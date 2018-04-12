#include "StdAfx.h"
#include "l2commlogic.h"
#include "Shlwapi.h"


IMPLEMENT_L3CLASS(CL2CommLogic,CL3Object,1)

BEGIN_L3PROPTABLE(CL2CommLogic,CL3Object)
L3PROP_STRING(nickname)
L3PROP_STRING_LEN(varL2CommNotify,4000)
L3PROP_LONG(varL2CommBeginTrans)
L3PROP_LONG(varL2CommCommitTrans)
L3PROP_LONG(varL2CommRollbackTrans)
L3PROP_LONG(varL2CommWorkshopID)
L3PROP_LONG(varL2CommStopWorkshop)
L3PROP_LONG(varL2CommStartWorkshop)
L3PROP_LONG(varL2CommModifyWorkshopID)
END_L3PROPTABLE(CL2CommLogic)

BEGIN_L3METHODMAP(CL2CommLogic,CL3Object)
L3_METHOD(CL2CommLogic,"ParseNewL2Data",0,ParseNewL2Data,L3VT_BOOL,L3VTS_LONG L3VTS_STRING L3VTS_STRING L3VTS_STRING L3VTS_STRING L3VTS_STRING)
L3_METHOD(CL2CommLogic,"ReqSendL3DataToL2",1,ReqSendL3DataToL2,L3VT_BOOL,L3VTS_LONG L3VTS_STRING L3VTS_RECORDSET)
L3_METHOD(CL2CommLogic,"GetLogicTelegram",2,GetLogicTelegram,L3VT_STRING,L3VTS_NONE)
L3_METHOD(CL2CommLogic,"L3BeginTrans",3,L3BeginTrans,L3VT_VOID,L3VTS_LONG)
L3_METHOD(CL2CommLogic,"L3CommitTrans",4,L3CommitTrans,L3VT_VOID,L3VTS_LONG)
L3_METHOD(CL2CommLogic,"L3RollbackTrans",5,L3RollbackTrans,L3VT_VOID,L3VTS_LONG)
L3_METHOD(CL2CommLogic,"L3ReqStopWorkshop",6,L3ReqStopWorkshop,L3VT_VOID,L3VTS_LONG)
L3_METHOD(CL2CommLogic,"L3ReqStartWorkshop",7,L3ReqStartWorkshop,L3VT_VOID,L3VTS_LONG)
L3_METHOD(CL2CommLogic,"L3OnCommStart",8,L3OnCommStart,L3VT_VOID,L3VTS_NONE)
END_L3METHODMAP()

CL2CommLogic::CL2CommLogic(void)
{
	SetPropValue(_T("nickname"),_T("L2CommLogic"));
	SetPropValue(_T("varL2CommNotify"),0);
	SetPropValue(_T("varL2CommWorkshopID"),-1);
	bAppError=FALSE;
	//m_bNotify=FALSE;
	m_bBeginTrans=FALSE;
	m_bCommitTrans=FALSE;
	m_bRollbackTrans=FALSE;
	m_bStopWorkshopNotify=FALSE;
	m_bStartWorkshopNotify=FALSE;
	//pReqQueue=NULL;
	strRecordJunc=_T(" & ");
	InitializeCriticalSection(&cs);
	InitializeCriticalSection(&fcs);
	LogAppError(_T("L2CommLogic Loaded"));
}

CL2CommLogic::~CL2CommLogic(void)
{
	//释放电文队列
	//PQueueNode pTemp;
	//if(pReqQueue!=NULL){
	//	while(pReqQueue->pNext!=NULL){
	//		pTemp=pReqQueue;
	//		pReqQueue=pTemp->pNext;
	//		delete pTemp;
	//	}
	//	delete pReqQueue;
	//}
	DeleteCriticalSection(&cs);
	DeleteCriticalSection(&fcs);
}

#define STR_LEN 256

CString CL2CommLogic::FormString(CString cstr)
{
	CString csTemp;
	csTemp=cstr;
	while((!(csTemp.Left(1).Compare(_T(" "))))&&(csTemp.GetLength()>0)){
		csTemp.Delete(0,1);
	}
	while((!(csTemp.Right(1).Compare(_T(" "))))&&(csTemp.GetLength()>0)){
		csTemp.Delete(csTemp.GetLength()-1,1);
	}
	return csTemp;
}

void CL2CommLogic::LogAppError(CString csError)
{
	char * sLog;
	int nlen,i;
	CFile cf;
	CString csLog;
	CString stErrorLogFile=_T("L2CommLogicError.log");
	CTime ct=CTime::GetCurrentTime();
	if(!bAppError){
        //added , LiuGe 2005-11-19
		CString csL2CommFolder = _T(".\\L2COMMLOGIC_LOGS");
		BOOL bPathFileExists;
		if (!PathFileExists(csL2CommFolder))
		{
			bPathFileExists = CreateDirectory(csL2CommFolder,NULL);
		}
		else
		{
			bPathFileExists = TRUE;
		}
		
		if (!bPathFileExists) 
		{
			return;
		}
		//////////////////////////////


		//csLogFile.Format(_T("c:\\%s_%04d%02d%02d_%02d%02d%02d.log"),stErrorLogFile,ct.GetYear(),ct.GetMonth(),ct.GetDay(),ct.GetHour(),ct.GetMinute(),ct.GetSecond());
		//modified, LiuGe 2005-11-19
		csLogFile.Format(_T("%s\\%s_%04d%02d%02d_%02d%02d%02d.log"),csL2CommFolder,stErrorLogFile,ct.GetYear(),ct.GetMonth(),ct.GetDay(),ct.GetHour(),ct.GetMinute(),ct.GetSecond());
		bAppError=TRUE;
	}
	EnterCriticalSection(&fcs);
	try{

		csLog.Format(_T("%04d-%02d-%02d %02d:%02d:%02d  %s\r\n"),ct.GetYear(),ct.GetMonth(),ct.GetDay(),ct.GetHour(),ct.GetMinute(),ct.GetSecond(),csError);
		nlen=csLog.GetLength();
		sLog=new char[nlen];
		for(i=0;i<nlen;i++) sLog[i]=(char)csLog.GetAt(i);
		cf.Open(csLogFile,CFile::modeCreate|CFile::modeNoTruncate|CFile::modeWrite);
		if(cf.GetLength()>100000){
			bAppError=FALSE;
			//cf.Close();
			//cf.Open(stErrorLogFile,CFile::modeCreate|CFile::modeWrite);
		}
		cf.SeekToEnd();
		cf.Write(sLog,nlen);
		cf.Close();
		delete sLog;
		LeaveCriticalSection(&fcs);
	}
	catch( ...){
		// Simply show an error message to the user.
		//e->ReportError();
		LeaveCriticalSection(&fcs);
	}
}

L3BOOL CL2CommLogic::ParseNewL2Data(L3LONG nCount,L3STRING FieldTypes,L3STRING FieldNames,L3STRING FieldData,L3STRING strURI,L3STRING strMethod)
{
	wchar_t stType[STR_LEN];
	wchar_t stName[STR_LEN];
	wchar_t stData[STR_LEN];
	CL3RecordSetWrap pRs;
	L3RECORDSET rs;
	CString csFieldTypes,csFieldNames,csFieldData,csURI,csMethod;
	CString csTemp;
	CStringArray FieldDatas;
	CStringArray rsFieldNames;
	CUIntArray rsFieldTypes;
	CL3Variant tvar,vrt;
	L3LONG lval;
	float fval;
	int i,k;
	int nr;//记录数
	int nDataPos,nDataLen;//单个数据长度
	csFieldTypes=FieldTypes;
	csFieldNames=FieldNames;
	csFieldData=FieldData;
	csFieldData=FormString(csFieldData);
	csFieldData+=_T(" ");
	csURI=strURI;
	csMethod=strMethod;
	csTemp.Format(_T("URI=%s::METHOD=%s::nFieldCount=%d::%s"),csURI,csMethod,nCount,csFieldData);
	LogAppError(csTemp);
	while(csFieldData.GetLength()>0){
		nDataPos=csFieldData.Find(strRecordJunc);
		if(nDataPos==-1) break;
		nDataLen=nDataPos;
		FieldDatas.Add(csFieldData.Left(nDataLen));
		csFieldData.Delete(0,nDataLen+strRecordJunc.GetLength());
	}
	nr=(int)FieldDatas.GetCount();
	while(csFieldTypes.GetLength()>0){
		swscanf(csFieldTypes.GetBuffer(),L"%s",stType);
		csFieldTypes.ReleaseBuffer();
		csTemp=stType;
		csFieldTypes.Delete(0,csTemp.GetLength()+1);
		if(!csTemp.Compare(_T("%s"))) rsFieldTypes.Add(L3VT_STRING);
		if(!csTemp.Compare(_T("%d"))) rsFieldTypes.Add(L3VT_LONG);
		if(!csTemp.Compare(_T("%f"))) rsFieldTypes.Add(L3VT_FLOAT);
		swscanf(csFieldNames,L"%s",stName);
		csFieldNames.ReleaseBuffer();
		csTemp=stName;
		csFieldNames.Delete(0,csTemp.GetLength()+1);
		rsFieldNames.Add(csTemp);
	}
	if(!CreateRecordSet(rsFieldNames,rsFieldTypes,pRs) || pRs.IsNull()){
		return FALSE;
	}
	pRs.DeleteAll();
	pRs.MoveFirst();
	if(nCount!=rsFieldTypes.GetCount()) return FALSE;
	for(k=0;k<nr;k++){
		if(!pRs.AppendRecord()) return FALSE;;
		for(i=0;i<nCount;i++){
			swscanf(FieldDatas[k].GetBuffer(),L"%s",stData);
			FieldDatas[k].ReleaseBuffer();
			csTemp=stData;
			FieldDatas[k].Delete(0,csTemp.GetLength()+1);
			csTemp.Replace(0x02,' ');
			csTemp.Remove(0x03);
			if(rsFieldTypes[i]==L3VT_STRING){
				tvar=csTemp;
			}
			if(rsFieldTypes[i]==L3VT_LONG){
				if(!csTemp.Compare(_T(""))) tvar=0;
				else{
					swscanf(csTemp.GetBuffer(),L"%d",&lval);
					tvar=lval;
				}
			}
			if(rsFieldTypes[i]==L3VT_FLOAT){
				if(!csTemp.Compare(_T(""))) tvar=0;
				else{
					swscanf(csTemp.GetBuffer(),L"%f",&fval);
					tvar=fval;
				}
			}
			csTemp.ReleaseBuffer();
			pRs.SetFieldByIndex(i,tvar);
		}
	}
	//rs=pRs.Detach();
	//rs->ToHead();
	nr=pRs.GetRowCount();
	pRs.MoveFirst();
	for(k=0;k<nr;k++){
	csTemp=_T("");
	for(i=0;i<nCount;i++){
		csTemp+=pRs.GetFieldName(i);
		csTemp+=_T(":");
		tvar=pRs.GetFieldByIndex(i);
		csTemp+=tvar.ToCString();
		csTemp+=_T("  ");
	}
	LogAppError(csTemp);
	pRs.MoveNext();
	}
	rs=pRs.Detach();
	vrt=InvokeObjectMethod(csURI,csMethod,rs);
	rs->Release();
	return vrt.ToBOOL();
}

L3BOOL CL2CommLogic::ReqSendL3DataToL2(L3LONG nWorkshopID,L3STRING strTelegramID,L3RECORDSET rsData)
{
	CString csTemp;
	CL3Variant cvar;
	CString csTelegram;
	CString csTelegramID;
	CString csNode;
	csTelegramID=strTelegramID;
	CL3RecordSetWrap pRs = rsData;
	CString csTrace;
	csTrace.Format(_T(":::::::::::::::::::ReqSendL3DataToL2::%d::%s::%s:::\n"),nWorkshopID,csTelegramID,csTelegram);
	TRACE(csTrace);
	//pRs.Attach(rsData);
	int nrCount;
	int nfCount;
	int r,i;
	nrCount=pRs.GetRowCount();
	nfCount=pRs.GetFieldCount();
	if(!pRs.MoveFirst()) return FALSE;
	EnterCriticalSection(&cs);
	try{
		for(r=0;r<nrCount;r++){
			csTelegram=_T("");
			if(pRs.IsEOF()) break;
			for(i=0;i<nfCount;i++){
				cvar=pRs.GetFieldByIndex(i);
				if(cvar.ToCString().IsEmpty()){
					csTemp=_T(" ");
					csTemp.Replace(' ',0x03);
				}
				else{
					csTemp=cvar.ToCString();
					csTemp.Replace(' ',0x02);
				}
				csTelegram+=csTemp;
				csTelegram+=_T(" ");
			}
			csTelegram+=strRecordJunc;
			csNode.Format(_T("<%d>[%s]%s"),nWorkshopID,csTelegramID,csTelegram);
			cvar=csNode;
			SetPropValue(_T("varL2CommNotify"),cvar);
			pRs.MoveNext();
		}
		LeaveCriticalSection(&cs);
	}
	catch(...){
		LeaveCriticalSection(&cs);
	}
	return TRUE;
}

L3STRING CL2CommLogic::GetLogicTelegram()
{
	//CL3Variant cvar;
	//EnterCriticalSection(&cs);
	//cvar=GetReqQueue().AllocSysString();
	//LeaveCriticalSection(&cs);
	//CString csTrace;
	//csTrace.Format(_T(":::::::::::::::::::GetLogicTelegram::%s:::\n"),cvar.ToString());
	//TRACE(csTrace);
	//return cvar.ToString();
	return _T("");
}

//void CL2CommLogic::PostReqQueue(CString csTelegramID,CString csTelegram)
//{
//	CString csTrace;
//	csTrace.Format(_T("::::::::::::::::::::PostReqQueue::pReqQueue=%d:::::::::::::::::\n"),(long)pReqQueue);
//	TRACE(csTrace);
//	//EnterCriticalSection(&cs);
//	PQueueNode pTempNode=new QueueNode;
//	PQueueNode pTemp=pReqQueue;
//	pTempNode->pNext=NULL;
//	pTempNode->csTelegramID=csTelegramID;
//	pTempNode->csTelegram=csTelegram;
//	if(pReqQueue==NULL){
//		pReqQueue=pTempNode;
//	}
//	else{
//		while((pTemp->pNext)!=NULL){
//			pTemp=pTemp->pNext;
//		}
//		pTemp->pNext=pTempNode;
//	}
//	//LeaveCriticalSection(&cs);
//}
//CString CL2CommLogic::GetReqQueue()
//{
//	CString csNode;
//	PQueueNode pTemp;
//	CString csTrace;
//	csTrace.Format(_T("::::::::::::::::::::GetReqQueue::pReqQueue=%d:::::::::::::::::\n"),(long)pReqQueue);
//	TRACE(csTrace);
//	if(pReqQueue==NULL) return NULL;
//	//EnterCriticalSection(&cs);
//	csNode="[";
//	csNode+=pReqQueue->csTelegramID;
//	csNode+="]";
//	csNode+=pReqQueue->csTelegram;
//	pTemp=pReqQueue;
//	pReqQueue=pReqQueue->pNext;
//	//LeaveCriticalSection(&cs);
//	delete pTemp;
//	return csNode;
//}

void CL2CommLogic::L3BeginTrans(L3LONG nWorkshopID)
{
	CL3Variant cvar;

	cvar=nWorkshopID;
	SetPropValue(_T("varL2CommWorkshopID"),cvar);
	m_bBeginTrans=!m_bBeginTrans;
	cvar=m_bBeginTrans;
	SetPropValue(_T("varL2CommBeginTrans"),cvar);
}

void CL2CommLogic::L3CommitTrans(L3LONG nWorkshopID)
{
	CL3Variant cvar;

	cvar=nWorkshopID;
	SetPropValue(_T("varL2CommWorkshopID"),cvar);
	m_bCommitTrans=!m_bCommitTrans;
	cvar=m_bCommitTrans;
	SetPropValue(_T("varL2CommCommitTrans"),cvar);
}

void CL2CommLogic::L3RollbackTrans(L3LONG nWorkshopID)
{
	CL3Variant cvar;

	cvar=nWorkshopID;
	SetPropValue(_T("varL2CommWorkshopID"),cvar);
	m_bRollbackTrans=!m_bRollbackTrans;
	cvar=m_bRollbackTrans;
	SetPropValue(_T("varL2CommRollbackTrans"),cvar);
}

void CL2CommLogic::L3ReqStartWorkshop(L3LONG nWorkshopID)
{
	CL3Variant cvar;

	cvar=nWorkshopID;
	SetPropValue(_T("varL2CommModifyWorkshopID"),cvar);
	m_bStartWorkshopNotify=!m_bStartWorkshopNotify;
	cvar=m_bStartWorkshopNotify;
	SetPropValue(_T("varL2CommStartWorkshop"),cvar);
}

void CL2CommLogic::L3ReqStopWorkshop(L3LONG nWorkshopID)
{
	CL3Variant cvar;

	cvar=nWorkshopID;
	SetPropValue(_T("varL2CommModifyWorkshopID"),cvar);
	m_bStopWorkshopNotify=!m_bStopWorkshopNotify;
	cvar=m_bStopWorkshopNotify;
	SetPropValue(_T("varL2CommStopWorkshop"),cvar);
}

void CL2CommLogic::L3OnCommStart(L3VOID)
{
	//PQueueNode pTemp;
	//EnterCriticalSection(&cs);
	//TRACE(_T(":::::::::::::::::::::Clear all req_send information:::::::::::::::::::::::\n"));
	//if(pReqQueue!=NULL){
	//	while(pReqQueue->pNext!=NULL){
	//		pTemp=pReqQueue;
	//		pReqQueue=pTemp->pNext;
	//		delete pTemp;
	//	}
	//	delete pReqQueue;
	//}
	//LeaveCriticalSection(&cs);
}

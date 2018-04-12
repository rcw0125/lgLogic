// �߼���CScrap_Store_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CScrap_Store_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CScrap_Store_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CScrap_Store_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CScrap_Store_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CScrap_Store_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ������⻺������URI
/// </summary>
CString CScrap_Store_Mag::GetInputCache()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return SCRAP_STORE_INCACHE_OBJ_URI;
}

/// <summary>
/// ���س��⻺������URI
/// </summary>
CString CScrap_Store_Mag::GetOutputCache()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return SCRAP_STORE_OUTCACHE_OBJ_URI;
}

/// <summary>
/// ��������¼��������
/// </summary>
CString CScrap_Store_Mag::GetInputLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return SCRAP_IN_CLASS_URI;
}

/// <summary>
/// ���س����¼��������
/// </summary>
CString CScrap_Store_Mag::GetOutputLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return SCRAP_OUT_CLASS_URI;
}

/// <summary>
/// ���ؿ�λ��������
/// </summary>
CString CScrap_Store_Mag::GetStoreAreaType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return _T("");
}

/// <summary>
///	��ʼ���ⷿ������
/// </summary>
BOOL CScrap_Store_Mag::InitializeStoreProperties()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::InitializeStoreProperties();
}

/// <summary>
/// ����λ�ĳ�ʼ������
/// </summary>
BOOL CScrap_Store_Mag::GetInitialAreaData(CL3RecordSetWrap& rs)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetInitialAreaData(rs);
}

/// <summary>
/// �ڿⷿ��ʼ��ɺ���á��̳������ش˺������ж���ĳ�ʼ��������
/// </summary>
void CScrap_Store_Mag::OnAfterStoreInitialized()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::OnAfterStoreInitialized();
}

/// <summary>
/// ���ǰԤ������������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsInputInfo : �����Ϣ��¼��
/// RET << TRUE ������⣻FALSE �ж����
/// </summary>
BOOL CScrap_Store_Mag::OnBeforeInputMaterials(L3RECORDSET rsInputInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeInputMaterials(rsInputInfo);
}

/// <summary>
/// �������������������ɹ�����á��̳�������ش˷������ж���Ĵ���
/// ARG >> rsInputInfo : �����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMaterialsInputted(L3RECORDSET rsInputInfo)
{
	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);
	return TRUE;
}

/// <summary>
/// ����ǰԤ�����ڳ������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsOutputInfo : ������Ϣ��¼��
/// RET << TRUE �������⣻FALSE �жϳ���
/// </summary>
BOOL CScrap_Store_Mag::OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeOutputMaterials(rsOutputInfo);
}

/// <summary>
/// ������������ڳ�������ɹ�����á��̳�������ش˷������ж���Ĵ���
/// ARG >> rsOutputInfo : ������Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo)
{
	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//2009-04-08 tangyi���ϸ������ӳ��⻺������ȥ,ɾ����������
	//2009-04-10 tangyi���ηϸ��г�������������ʲ���ɾ��
	//CString csOutObj = GetOutputCache();
	//InvokeObjectMethod(csOutObj,_T("RemoveMaterials"),rsOutputInfo);
	return TRUE;
}

/// <summary>
/// �˹����ӿ��ǰԤ�����ڽ����˹����ӿ��ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG	>> rsMaterialInfo : ����������Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CScrap_Store_Mag::OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeAddMaterials(rsMaterialInfo);
}

/// <summary>
/// �˹����ӿ����������ڽ����˹����ӿ�����á��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : �����Ĳ�����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsAdded(rsMaterialInfo);
}

/// <summary>
/// �˹�ɾ�����ǰԤ�����ڽ����˹�ɾ�����ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG	>> rsMaterialInfo : ɾ��������Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CScrap_Store_Mag::OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeDeleteMaterials(rsMaterialInfo);
}

/// <summary>
/// �˹�ɾ�������������ڽ����˹�ɾ��������á��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsDeleted(rsMaterialInfo);
}


//tangyi 2007-12-09
/// <summary>
/// �ƿ�ǰ������
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CScrap_Store_Mag::OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// �ƿ��������
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// ����¼Ԥ�����̳�������ش˷��������ǰ����������¼
/// </summary>
void CScrap_Store_Mag::PrepareInputLog(L3RECORDSET rsInputLog)
{
	CL3RecordSetWrap rs = rsInputLog;
	//��ȡ�������Ϣ
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//��𡢰��
		rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));		
		rs.MoveNext();
	}
}

/// <summary>
/// �����¼Ԥ�����̳�������ش˷����ڳ���ǰ����������¼
/// </summary>
void CScrap_Store_Mag::PrepareOutputLog(L3RECORDSET rsOutputLog)
{
	CL3RecordSetWrap rs = rsOutputLog;
	//��ȡ�������Ϣ
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rs.MoveFirst();
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	while(!rs.IsEOF())
	{
		//��𡢰��
		rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rs.SetFieldByName(_T("LogDate"),CL3Variant(curTime));
		//2009-03-08 tangyi �ϸֶ��ż���ʱ���׺
		CString csScrapSlotID = rs.GetFieldByName(_T("Scrap_Slot_ID")).ToCString();		
		CString strIronID;
		strIronID.Format(_T("%s_%04d%02d%02d%02d%02d%02d"),(LPCTSTR)csScrapSlotID,curTime.GetYear(),curTime.GetMonth(),curTime.GetDay(),curTime.GetHour(),curTime.GetMinute(),curTime.GetSecond());
		rs.SetFieldByName(_T("Scrap_Slot_ID"),CL3Variant(strIronID));
		rs.MoveNext();
	}
}

/// <summary>
/// ����ָ����ŵĿ�λ�����URI
/// </summary>
CString CScrap_Store_Mag::GetAreaURI(LPCTSTR lpcszAreaID)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������
	CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\");
	csAreaUri+=lpcszAreaID;

	return  csAreaUri;
}

/// <Method class="CScrap_Store_Mag" name="ScrapDataAccept" type="L3BOOL">
/// 
/// ����NC�ϸ�����,����input����,����ϱ�,���յ��ı�
/// ARG&gt;&gt; rsScrapData:�ϸ�������Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CScrap_Store_Mag::ScrapDataAccept(L3RECORDSET rsScrapData)
{
	CL3RecordSetWrap rsData =rsScrapData;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//�жϷϸ�������Ϣ
	//CString csTelType;
	//if(rsData.GetFieldIndex(_T("vbillcode")) < 0)//��ⵥ��
	//	csTelType = SCRAP_TRANS_TEL_CLASS_URI;
	//else
	//	csTelType = SCRAP_PUR_TEL_CLASS_URI;

	//CL3RecordSetWrap rsTelData;
	//if(!CreateClassPropSet(csTelType,rsTelData))
	//	return -1;

	//rsTelData.DelField(_T("GUID"));
	////rsTelData.AddField(_T("Rec_Time"),VT_DATE);
	//rsTelData.CopyFrom(rsData);
	//rsTelData.MoveFirst();
	//while(!rsTelData.IsEOF())
	//{
	//	rsTelData.SetFieldByName(_T("Rec_Time"),timeNow);
	//	rsTelData.MoveNext();
	//}
	////��¼�ϸֵ�����Ϣ
	//if(CreateNewObjects(csTelType,rsTelData) < rsTelData.GetRowCount())
	//	return -7;

	//���ϼ�����⻺��
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.DelField(_T("GUID"));
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rs.AppendRecord();
		rs.SetFieldByName(_T("MaterialID"),rsData.GetFieldByName(_T("Invcode")));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_SCRAP));
		if(rsData.GetFieldIndex(_T("vbillcode")) < 0)
			rs.SetFieldByName(_T("Amount"),rsData.GetFieldByName(_T("nnum")));
		else
			rs.SetFieldByName(_T("Amount"),rsData.GetFieldByName(_T("ninnum")));	
		rsData.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("AddMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	//����������ݱ�
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CL3Variant valTemp = rsData.GetFieldByName(_T("Invcode"));
		if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		CString csMaterialID = valTemp.ToCString();
		CString csUri = SCRAP_DATA_CLASS_URI + _T("\\") + csMaterialID;
		if(rsData.GetFieldIndex(_T("vbillcode")) < 0)
			valTemp = rsData.GetFieldByName(_T("nnum"));
		else
			valTemp = rsData.GetFieldByName(_T("ninnum"));

		if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		L3DOUBLE nAddAMount = valTemp.ToDouble();
		//2009-01-09 tangyi
		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();
		//if(!CreateNewObject(SCRAP_DATA_CLASS_URI,CL3Variant(csMaterialID)))
		if(!csObject.IsEmpty())
		{
			valTemp = GetObjectPropValue(csUri,_T("Amount"));
			if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			L3DOUBLE nAmount = valTemp.ToDouble();
			nAmount += nAddAMount;
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAmount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}

		}
		else
		{
			CreateNewObject(SCRAP_DATA_CLASS_URI,CL3Variant(csMaterialID));
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAddAMount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}
		
		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	// TODO : ���ڴ�����߼�����
	return 0;
}


/// <Method class="CScrap_Store_Mag" name="ScrapDataAccept" type="L3BOOL">
/// 
/// ����NC�ϸ�����,����input����,����ϱ�,���յ��ı�
/// ARG&gt;&gt; rsScrapData:�ϸ�������Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CScrap_Store_Mag::ScrapDataAcceptFromNC(L3RECORDSET rsScrapData)
{
	CL3RecordSetWrap rsData =rsScrapData;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return -1;

	//COleDateTime timeNow = COleDateTime::GetCurrentTime();

	////�жϷϸ�������Ϣ
	//CString csTelType;
	//if(rsData.GetFieldIndex(_T("vbillcode")) < 0)//��ⵥ��
	//	csTelType = SCRAP_TRANS_TEL_CLASS_URI;
	//else
	//	csTelType = SCRAP_PUR_TEL_CLASS_URI;

	//CL3RecordSetWrap rsTelData;
	//if(!CreateClassPropSet(csTelType,rsTelData))
	//	return -1;

	//rsTelData.DelField(_T("GUID"));
	////rsTelData.AddField(_T("Rec_Time"),VT_DATE);
	//rsTelData.CopyFrom(rsData);
	//rsTelData.MoveFirst();
	//while(!rsTelData.IsEOF())
	//{
	//	rsTelData.SetFieldByName(_T("Rec_Time"),timeNow);
	//	rsTelData.MoveNext();
	//}
	////��¼�ϸֵ�����Ϣ
	//if(CreateNewObjects(csTelType,rsTelData) < rsTelData.GetRowCount())
	//	return -7;

	//���ϼ�����⻺��
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.DelField(_T("GUID"));
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rs.AppendRecord();
		//Modify by liuzhiqiang 2009-03-13
		CString csInvcodeID = rsData.GetFieldByName(_T("cbaseid")).ToCString();
		CString csMaterialID;
		if(csInvcodeID == _T("0001NC10000000003MYN"))  
			csMaterialID =_T("PigIron"); 
		else 
		{
			if (csInvcodeID == _T("0001NC10000000003MYM"))  
				csMaterialID =_T("Scrap"); 
			else
			{
				rsData.MoveNext();
				continue;
			}
		}

		rs.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_SCRAP));
		rs.SetFieldByName(_T("Amount"),rsData.GetFieldByName(_T("ninnum")));	
		rsData.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("AddMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	//����������ݱ�
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CL3Variant valTemp = rs.GetFieldByName(_T("MaterialID"));
		CString csMaterialID=valTemp.ToCString(); 
		CString csUri = SCRAP_DATA_CLASS_URI + _T("\\") + csMaterialID;		
		valTemp = rs.GetFieldByName(_T("Amount"));
		L3DOUBLE nAddAMount = valTemp.ToDouble();
		//2009-01-09 tangyi
		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();
		//if(!CreateNewObject(SCRAP_DATA_CLASS_URI,CL3Variant(csMaterialID)))
		if(!csObject.IsEmpty())
		{
			valTemp = GetObjectPropValue(csUri,_T("Amount"));
			if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			L3DOUBLE nAmount = valTemp.ToDouble();
			nAmount += nAddAMount;
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAmount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}

		}
		else
		{
			CreateNewObject(SCRAP_DATA_CLASS_URI,CL3Variant(csMaterialID));
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAddAMount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}
		
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	// TODO : ���ڴ�����߼�����
	return 0;
}


/// <Method class="CScrap_Store_Mag" name="ScrapInStore" type="L3VOID">
/// 
/// �ϸ����
/// ARG&gt;&gt; rsInputInfo�ϸ�������Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CScrap_Store_Mag::ScrapInStore(L3RECORDSET rsInputInfo)
{
	return InputMaterials(rsInputInfo);
}

/// <Method class="CScrap_Store_Mag" name="ScrapOutStore" type="L3VOID">
/// 
/// �ϸֳ���
/// ARG&gt;&gt; rsOutputInfo�ϸ�������Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID,Scrap_Slot_ID,Car_ID,Car_Type,Net_Weight,Gross_Weight,Tare_Weight�⼸���ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsOutputInfo" type="L3RECORDSET">������Ϣ��¼������MaterialType,MaterialID,Amount,AreaID���ֶΡ�</Param>
/// </Method>
L3BOOL CScrap_Store_Mag::ScrapOutStore(L3RECORDSET rsOutputInfo)
{
	CL3RecordSetWrap rs =rsOutputInfo;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	if(rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("StoreAreaID")) < 0 ||
		rs.GetFieldIndex(_T("Scrap_Slot_ID")) < 0 ||
		rs.GetFieldIndex(_T("Car_ID")) < 0 ||
		rs.GetFieldIndex(_T("Car_Type")) < 0 ||
		rs.GetFieldIndex(_T("Net_Weight")) < 0 ||
		rs.GetFieldIndex(_T("Gross_Weight")) < 0 ||
		rs.GetFieldIndex(_T("Tare_Weight")) < 0)
			return false;

	return OutputMaterials(rsOutputInfo);
}

/// <Method class="CScrap_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// ��ȡ��⻺�����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CScrap_Store_Mag::GetMaterialOnInputCache()
{
	CString csInputCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
		return NULL;
	CString csPos = valRet.ToCString();
	CString csTemp = _T(" select a.*  from %s a  where  a.Position = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,csPos);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CAlloy_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// ��ȡ����������Ϣ
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CScrap_Store_Mag::GetMaterialOnStore(L3STRING strStoreID)
{
	CString csPos = strStoreID;
	CString csTemp;
	CString csSQL;
	if(csPos.IsEmpty())
	{
		csTemp= _T(" select a.*  from %s a  where  substr(a.Position,1,3) = '%s' and  substr(a.Position,4,1) <> 'P' and substr(a.Position,4,1) <> 'N'");
		csSQL.Format(csTemp,MES_MATERIAL_POSITION,STORE_ID_SCRAP);
	}
	else
	{
		csTemp = _T(" select a.*  from %s a  where  a.Position = '%s' ");
		csSQL.Format(csTemp,MES_MATERIAL_POSITION,csPos);

	}
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CAlloy_Store_Mag" name="AlloyModifyAmount" type="L3BOOL">
/// 
/// ��������������
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.�������MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag �⼸���ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CScrap_Store_Mag::ModifyMaterialAmount(L3RECORDSET rsData)
{
	CL3Variant valRet =InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("ModifyMaterialAmountFuction"),rsData);
	if(!valRet.IsValid()||valRet.IsError())
		return -1;

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return valRet.ToLong();

}


/// <Method class="CScrap_Store_Mag" name="ScrapInStore" type="L3VOID">
/// 
/// �ϸֳ�������2009-02-26
/// ARG&gt;&gt; rsOutputInfo�ϸ�������Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CScrap_Store_Mag::ScrapCancelOutStore(L3RECORDSET rsOutputInfo)
{

	CL3RecordSetWrap rsData =rsOutputInfo;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return  false;

	if(rsData.GetFieldIndex(_T("Scrap_Slot_ID")) < 0 )
		return false;

	//�齨���ݼ�
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsScrap; pRSRtn->QueryInterface(IID_IL3RecordSet,rsScrap); pRSRtn->Release();
	rsScrap.AddField(_T("MaterialType"),VT_BSTR);
	rsScrap.AddField(_T("MaterialID"),VT_BSTR);
	rsScrap.AddField(_T("SourceID"),VT_BSTR);
	rsScrap.AddField(_T("TargetID"),VT_BSTR);
	rsScrap.AddField(_T("Amount"),VT_R8);

	rsScrap.AppendRecord();


	//�齨���ݼ�
	CL3RecordSet *pRSRtnDel = new CL3RecordSet();
	CL3RecordSetWrap rsDel; pRSRtnDel->QueryInterface(IID_IL3RecordSet,rsDel); pRSRtnDel->Release();
	rsDel.AddField(_T("GUID"),VT_BSTR);



	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}


	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csCarID = rsData.GetFieldByName(_T("Scrap_Slot_ID")).ToCString();
		CString csTempSQL =_T(" select GUID,MaterialType,MaterialID,Amount,StoreAreaID as TargetID,'S82N01'as SourceID  from CScrap_Output_Log where Iron_flag =0 and Scrap_Slot_ID ='%s'");
		CString csSQL;
		csSQL.Format(csTempSQL,csCarID);
		CL3RecordSetWrap rsResultData;
		if(!Query(csSQL,rsResultData))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;
		}
		rsDel.CopyFrom(rsResultData);
		rsResultData.MoveFirst();
		while(!rsResultData.IsEOF())
		{
			rsScrap.CopyCurRowFrom(rsResultData);
			CString strSrc = rsScrap.GetFieldByName(_T("SourceID")).ToCString();
			CString strTgt = rsScrap.GetFieldByName(_T("TargetID")).ToCString();
			CString strSrcURI = XGINTERCACHE_URI + _T("\\") + strSrc;
			CL3Variant valRet = InvokeObjectMethod(strSrcURI,_T("RemoveMaterials"),(IL3RecordSet*)rsScrap);
			if(!valRet.ToBOOL())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return FALSE;
			}
			CString strTgtURI =XGSTOREAREA_URI + _T("\\") + strTgt;
			valRet = InvokeObjectMethod(strTgtURI,_T("AddMaterials"),(IL3RecordSet*)rsScrap);
			if(!valRet.ToBOOL())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return FALSE;
			}
			rsScrap.MoveFirst();
			rsResultData.MoveNext();
		}

		rsData.MoveNext();
	}

	if(DeleteOldObjects(SCRAP_OUT_CLASS_URI,rsDel) < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	if(bUseTrans) 
		Commit(nTrans);

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return true;
}


/// <Method class="CBOF_Unit_Mag" name="GetScrapesForDesignate" type="L3RECORDSET">
/// ��ȡ��ѡ�ϸ���Ϣ��¼�����ش��зϸֲۺźͷϸ����ļ�¼����
/// </Method>
L3RECORDSET CScrap_Store_Mag::GetScrapes()
{
	//2009-02-21*Liao
	CString cssss = _T("select Scrap_Slot_ID,sum(Amount) as Amount,sum(decode(StoreAreaID,'S82A01',Amount,0)) as ScrapWT,");
	cssss += _T(" sum(Amount)-sum(decode(StoreAreaID,'S82A01',Amount,0)) as PigIronWT ,to_char(LogDate,'yyyy-mm-dd') as LogTime from CScrap_Output_Log where Iron_Flag = 0 group by Scrap_Slot_ID,to_char(LogDate,'yyyy-mm-dd')");
	CString strSQL;
	//strSQL.Format(_T("select Scrap_Slot_ID,sum(Amount) as Amount sum(decode(StoreAearID))from %s where Iron_Flag = 0 group by Scrap_Slot_ID"),SCRAP_OUT_CLASS_URI);
	strSQL.Format(cssss,SCRAP_OUT_CLASS_URI);
	
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}


/// <Method class="CScrap_Store_Mag" name="SaveScrapOutDetail" type="L3LONG">
/// <Param name="rsScrap" type="L3RECORDSET"></Param>
/// ����ϸ֡���������������Ϣ
/// </Method>2011-03-19 �û���Ҫ��¼�ϸ�������Ϣ���
L3LONG CScrap_Store_Mag::SaveScrapOutDetail(L3RECORDSET rsScrap)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap pScrap =rsScrap;
	if( pScrap.IsNull() || pScrap.GetRowCount() < 1)
		return  -1;

	//��ȡ���һ���϶������¼���϶���
	CString csSql;
	csSql.Format(_T("select SCRAP_SLOT_ID from %s where LOGDATE>sysdate-0.007 and STOREAREAID='S82A01' order by LOGDATE desc "),SCRAP_OUT_CLASS_URI);

	CL3RecordSetWrap rsScrapData;
	if(!Query(csSql,rsScrapData)||rsScrapData.GetRowCount()<1)
		return -1;

	//ȡ���һ������
	rsScrapData.MoveFirst();
	CString csScrap_Slot_ID=rsScrapData.GetFieldByName(_T("Scrap_Slot_ID")).ToCString();

	pScrap.MoveFirst();
	while(!pScrap.IsEOF())
	{
		CString csMaterial_Code = pScrap.GetFieldByName(_T("MATERIAL_CODE")).ToCString();
		L3LONG dAmout = pScrap.GetFieldByName(_T("AMOUNT")).ToLong();
		CString csMaterial = pScrap.GetFieldByName(_T("MATERIAL")).ToCString();

		if(csMaterial_Code==_T("")||dAmout<0||csMaterial==_T(""))
			return -1;
		pScrap.SetFieldByName(_T("Scrap_Slot_ID"),(CL3Variant)csScrap_Slot_ID);

		pScrap.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	
	CreateNewObjects(SCRAP_OUT_STORE_DETAIL_CLASS_URI,pScrap);
	if(bUseTrans)
		Commit(nTrans);
	return 0;
}

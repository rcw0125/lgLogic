// �߼���CDEP_Unit_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CDEP_Unit_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CDEP_Unit_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CDEP_Unit_Mag.h"
#include "L3NameParser.h"

#define BLOWTIMER_PERIOD		5000
#define BLOWTIME		5
L3SHORT  count1=0 ;

//������װ�ص�ϵͳ��ʱ��������
void CDEP_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CDEP_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ���ػ���ļӹ�����
/// ARG << lstURIs : �������мӹ��������URI
/// </summary>
BOOL CDEP_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	CString strURI;
	strURI.Format(_T("XGMESLogic\\DePMag\\CDEP_Prod_Area\\%s"),GetIdentity().ToCString());
	lstURIs.AddHead(strURI);
	return TRUE;
}

/// <summary>
/// �õ�����ǰ����ϻ�������URI
/// </summary>
CString CDEP_Unit_Mag::GetInputCache()
{

	CString strURI;

	strURI=_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S91P01");
	return strURI;

	/*return MIXFProduceCache_URI;*/
	
}

/// <summary>
/// �õ������̲��ϻ�������URI
/// </summary>
CString CDEP_Unit_Mag::GetOutputCache()
{
	CString strURI;

	strURI=_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S25P01");
	return strURI;
}

/// <summary>
/// ��������ǰԤ�����ڻ�������ǰ���ã��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << ����TRUE�������ϣ�����FALSE�ж����ϡ�
/// </summary>
BOOL CDEP_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// �������Ϻ��������ڻ������Ϻ���ã��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CDEP_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// ���ػ������ϼ�¼������URI
/// </summary>
CString CDEP_Unit_Mag::GetFeedingLogType()
{
	return _T("");
}


/// <summary>
/// ׼�����ϼ�¼���ݡ��̳�������ش˺������ж�������ݴ���
/// ARG >> rsFeedingLogs : ���ϼ�¼��Ϣ��
/// RET << void
/// </summary>
void CDEP_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::PrepareFeedingLogs( rsFeedingLogs);
}


/// <summary>
/// �ӹ�����Ԥ�����ڵ��üӹ�����ļӹ�����ǰ���ã��̳�������ش˺����Լӹ����������޸ĺ����á�
/// ARG >> lpcszArea : �ӹ������URI
///		>> rsParameters : �ӹ�������¼����
/// RET << ����TRUE�����ӹ�������FALSE�жϼӹ���
/// </summary>
BOOL CDEP_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PrepareProcessParameters( lpcszArea, rsParameters);
}


/// <summary>
/// �ӹ���ɺ��������ڼӹ���ɺ���ã��̳�������ش˺������ж����߼�����
/// ARG >> lpcszArea : �ӹ������URI
///		>> nProcessType : �ӹ������͡�
///		>> rsProducts : �ӹ������Ĳ�Ʒ����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CDEP_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// ����ǰԤ������ִ�����߲���ǰ���ã��̳�������ش˺�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << ����TRUE�������ߣ�����FALSE�ж����ߡ�
/// </summary>
BOOL CDEP_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// ���ߺ���������ִ�����߲�������ã��̳�������ش˺������ж��⴦��
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CDEP_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsDelivered( rsMaterialInfo);
}


/// <summary>
/// ���ػ��������¼������URI
/// </summary>
CString CDEP_Unit_Mag::GetDeliveryLogType()
{
	return _T("");
}


/// <summary>
/// ׼�����ϼ�¼���ݡ�
/// ARG >> rsDeliveryLog : ���ϼ�¼���ݡ�
/// RET <<void
/// </summary>
void CDEP_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// ���ر������ͨѶ�������URI
/// </summary>
CString CDEP_Unit_Mag::GetCommunicator()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetCommunicator();
}


/// <summary>
/// ׼���ƻ����ݣ��Ա��������λϵͳ���͡�
/// ARG >> lpcszPlanType : �ƻ����͡�
///		>> rsPlan : �ƻ����ݡ�����PlanID�ֶΡ�
///		<< rsSend : ����׼���õļƻ��������ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CDEP_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// �ƻ��´��������������λϵͳ���ͼƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsSend : �·���λϵͳ�ļƻ����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CDEP_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterPlansSent( rsSend);
}


/// <summary>
/// ׼���ƻ����ݣ��Ա�֪ͨ������λϵͳȡ���ƻ���
/// ARG >> lpcszPlanType : �ƻ����͡�
///		>> rsPlan : �ƻ����ݡ�����PlanID�ֶΡ�
///		<< rsSend : ����׼���õļƻ�ȡ�����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CDEP_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// �ƻ�ȡ����������������λϵͳ����ȡ���ƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsCancel : �·���λϵͳ�ļƻ�ȡ�����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CDEP_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// ����������ߵ��¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CDEP_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// ������Ͻ���ӹ�������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CDEP_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// ��������뿪�ӹ������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CDEP_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// ���������������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CDEP_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// �������������ݱ���¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CDEP_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}


/// ������һ¯��
CString CDEP_Unit_Mag::CalculateNextHeatID (LPCTSTR lpcszHeatID)
{
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strHeatID(lpcszHeatID); strHeatID.Trim();
	CString strNextID; 	
	if(strHeatID.IsEmpty())
	{
		CString strID = GetIdentity().ToCString();
		strID = strID.Mid(2,1);
		LONG nYear = curTime.GetYear();
		nYear = nYear - (nYear / 100) * 100;
		strNextID.Format(_T("2%s%02d%05d"),(LPCTSTR)strID,nYear,(INT)1);
	}
	else
	{
		CString strIDHead = strHeatID.Left(2);
		CString strIDYear = strHeatID.Mid(2,2);
		CString strIDSeq = strHeatID.Mid(4,strHeatID.GetLength()-4);
		LONG nYear = 0, nSeq = 0;
		_stscanf_s(strIDYear,_T("%d"),&nYear);
		_stscanf_s(strIDSeq,_T("%d"),&nSeq);
		LONG nCurYear = curTime.GetYear();
		nCurYear = nCurYear - (nCurYear / 100) * 100;
		if(nYear != nCurYear)
		{
			nYear = nCurYear;
			nSeq = 1;
		}
		else
			nSeq ++;
		strNextID.Format(_T("%s%02d%05d"),strIDHead,nYear,nSeq);
	}
	return strNextID;
}




/// ͨ��DEP����״̬�޸ĺ���   1����״̬ 2.��¼״̬��־
BOOL CDEP_Unit_Mag::ChangeDEPStatus(LONG nStatus)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	//2016-1-13 �޸�
	if(nStatus!=13)
	{
			if(!SetPropValue(_T("Status"),CL3Variant(nStatus)))
		{
			if(nTrans > 0)
				Rollback(nTrans); 
			return FALSE;
		}

	
	}

	// ��¼�¼���־
	CL3RecordSetWrap rsStatus;
	if(!CreateClassPropSet( _T("XGMESLogic\\DePMag\\CDEP_Process_Status"),rsStatus))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsStatus.AppendRecord();
	rsStatus.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
	rsStatus.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsStatus.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	if(CreateNewObjects( _T("XGMESLogic\\DePMag\\CDEP_Process_Status"),rsStatus) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}


	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}



///2009-02-28
/// </Method>  ָ������������base process 
L3LONG CDEP_Unit_Mag::IronLadleToDEP(L3RECORDSET rsIrons)
{
	CL3RecordSetWrap rsIron = rsIrons;
	if(rsIron.GetRowCount() < 1)
		return -1;
	// �������
	if(rsIron.GetFieldIndex(_T("MaterialID")) < 0 )
		return -2;

	// ��鵱ǰDEP״̬,���ֽ�����ǰ������ָ����ԭ��
	if(Status != CDEP_Unit_Mag::DEPWaiting)
		return -6;


	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -7;
	}

	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -8;
	}

	//��ȡ¯��

	CString strHeatID = NextHeatID;
	// ¯�ű��
	HeatID = NextHeatID;
	//������һ¯��2009-03-26 tangyi����ʱ������һ¯�ţ����ڼ����������Ӽƻ��л�ȡ
	NextHeatID = CalculateNextHeatID(strHeatID);
	// ����DEP¯��ԭ������CDEP_Feed_Data
	// ׼����ˮ��¼��
	CL3RecordSet* pRS = new CL3RecordSet();
	CL3RecordSetWrap rsSet; pRS->QueryInterface(IID_IL3RecordSet,rsSet);
	rsSet.AddField(_T("MaterialID"),VT_BSTR);
	rsSet.AddField(_T("HeatID"),VT_BSTR);
	rsIron.MoveFirst();
	rsSet.CopyFrom(rsIron);
	rsSet.MoveFirst();
	while(!rsSet.IsEOF())
	{
		rsSet.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		rsSet.MoveNext();
	}

	// �޸���ˮ��Ϣ
	rsSet.MoveFirst();
	if(!SetObjsPropValues(MATERIAL_IRON_URI,rsSet))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -9;
	}

	// ��ȡ��ָ������ˮ
	CL3RecordSetWrap rsIronsDesignated;
	rsIronsDesignated.Attach(GetInputIrons());
	if(rsIronsDesignated.GetRowCount() < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -10;
	}
      rsIronsDesignated.MoveFirst();
		CString strLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,rsIronsDesignated.GetFieldByName(_T("IronLadleNo")).ToCString());
		SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT));	

	// ���DEP�������Ƿ��Ѵ�����ˮ
   //   CL3Variant val = InvokeObjectMethod(_T("S91"),_T("GetMaterialCount"),_T("CIron_Data"));
	//if(!val.IsValid())
	//{
	//	if(nTrans > 0) Rollback(nTrans);
	//	return -11;
	//}
	//if(val.ToLong() > 0)//2008-12-29 ȷ��ֻ��һ¯��ˮtangyi
	//{
	//	if(nTrans > 0) Rollback(nTrans);
	//	
	//	return -12;
	//}
	// ����ˮ���ߣ�����DEP������
	//FeedMaterials����������о�
	rsIronsDesignated.MoveFirst();
	if(!FeedMaterials(rsIronsDesignated))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -13;
	}
   


	rsIronsDesignated.MoveFirst();
	CL3RecordSetWrap rsFeedData;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Feed_Data"),rsFeedData))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -16;
	}
	rsIron.MoveFirst();
	IronLadle=rsIron.GetFieldByName(_T("MaterialID")).ToString();
	rsFeedData.CopyFrom(rsIronsDesignated);
	rsFeedData.MoveFirst();
	rsFeedData.SetFieldByName(_T("MaterialID"),CL3Variant(IronLadle));
    rsFeedData.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Feed_Data"),rsFeedData) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -17;
	}

	Load=rsIron.GetFieldByName(_T("Weight")).ToDouble();
	CurTemp=rsIron.GetFieldByName(_T("IronTemp")).ToDouble();
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	IronLadleNo=rsIron.GetFieldByName(_T("IronLadleNo")).ToString();



	//  ����base��process��
	// ��Ҫ����


	

	// ��ѯ��Ӧ���ּƻ�����
	CString strSQLPlan; strSQLPlan.Format(_T("select * from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,GetRealHeatID(strHeatID));
	CL3RecordSetWrap rsPlan;
	if(!Query(strSQLPlan,rsPlan) || rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
	{	// �ƻ�������
		Rollback(nTrans);
		/*SetL3LastError("0xF0011001");*/
		return -18;
	}
	rsPlan.MoveFirst();
	// �޸ĵ�ǰDEP����
	SteelGradeIndex = rsPlan.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	

	// ����DEP¯�λ�������CDEP_Base_Data
	CL3RecordSetWrap rsBaseData;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),rsBaseData))
	{
		Rollback(nTrans);
		return -19;
	}
	rsBaseData.AppendRecord();
	rsBaseData.CopyCurRowFrom(rsPlan);
	rsBaseData.SetFieldByName(_T("IronLadle"),CL3Variant(IronLadle));
	rsBaseData.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rsBaseData.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsBaseData.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
	CString csObj = GetName() + rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(UNIT_DUTY_CLASS_URI,csObj);
	rsBaseData.SetFieldByName(_T("HeadFurnace"),GetObjectPropValue(csUri,_T("HeadFurnace")));
	rsBaseData.SetFieldByName(_T("Assistant"),GetObjectPropValue(csUri,_T("Assistant")));
	rsBaseData.SetFieldByName(_T("SecondHand"),GetObjectPropValue(csUri,_T("SecondHand")));
	rsBaseData.SetFieldByName(_T("ProductionDate"),CL3Variant(curTime));
	rsBaseData.SetFieldByName(_T("StatisticsDate"),CL3Variant(curTime));
	rsBaseData.SetFieldByName(_T("Locked"),CL3Variant((LONG)0));
	rsBaseData.SetFieldByName(_T("SteelGrade"),GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + SteelGradeIndex,_T("SteelGrade")));//2009-01-11 tangyi
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),rsBaseData) < 1)
	{
		Rollback(nTrans);
		return -20;
	}

	// ������������
	CL3RecordSetWrap rsProc;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),rsProc))
	{
		Rollback(nTrans);
		return -21;
	}
	rsProc.AppendRecord();
	rsProc.SetFieldByName(_T("IronLadle"),CL3Variant(IronLadle));
	rsProc.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	//  Charging_Start_Time ��վʱ��
	rsProc.SetFieldByName(_T("Charging_Start_Time"),CL3Variant(curTime));
    //��Ӱ���
	CString  ironladleid=IronLadle.Left(3);
	CString strironladlebase = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\IronLadleMag\\CIronLadle_Base"),ironladleid);
	rsProc.SetFieldByName(_T("LadleAge"),GetObjectPropValue(strironladlebase,_T("IronLadle_Age")));
	//�������״��
	rsProc.SetFieldByName(_T("Ladle_Status"),_T("����"));

	if(!CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),rsProc))
	{
		Rollback(nTrans);
		return -22;
	}

	// �޸�DEP״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPFeeding))
	{
		Rollback(nTrans);
		return -23;
	}




	SendStatusToPLC(1);// �����´���ˮ����״̬

	if(nTrans > 0)
		Commit(nTrans);

	return 0;

}


/// <Method class="CDEP_Unit_Mag" name="Waiting" type="L3BOOL">
/// ������վ��DEP����ȴ�״̬��
/// </Method>
L3LONG CDEP_Unit_Mag::Waiting()
{
	// �޸�DEP����

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// ���DEP״̬
	if(Status == CDEP_Unit_Mag::DEPWaiting)
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return -2;
	}
   CString strAreaURI= _T("XGMESLogic\\DePMag\\CDEP_Prod_Area\\S91");
	CL3Variant val = InvokeObjectMethod(strAreaURI,_T("GetMaterialDetails"),_T("CIron_Data"),_T(""));
	CL3RecordSetWrap rsSteel;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsSteel)) || rsSteel.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return -3;
	}
	rsSteel.AddField(_T("Area"),VT_BSTR);
	rsSteel.MoveFirst();
	rsSteel.SetFieldByName(_T("Area"),CL3Variant(strAreaURI));

	CString strTargetCache = GetOutputCache();
	// ��ˮ����
	CBSTR bstrTarget = strTargetCache;
	if(!DeliverMaterialsTo(bstrTarget.GetBuffer(TRUE),rsSteel))
	{
		if(nTrans > 0) Rollback(nTrans);
		return -4;
	}
	


	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPWaiting))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -5;
	}
    COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);

	SetObjectPropValue(strProcData,_T("Furnace_Age"),CL3Variant(FurnaceAge));
	SetObjectPropValue(strProcData,_T("Furnace_Surface"),CL3Variant(Furnace_Surface));
	SetObjectPropValue(strProcData,_T("LanceNo"),CL3Variant(LanceNo));
	SetObjectPropValue(strProcData,_T("Lance_Age"),CL3Variant(LanceAge));
	SetObjectPropValue(strProcData,_T("Slag_Head"),CL3Variant(Slag_Head));
	//SetObjectPropValue(strProcData,_T("BlowO2_Time"),CL3Variant(L3LONG(Desi_Time)));
	//SetObjectPropValue(strProcData,_T("Tapping_Time"),CL3Variant((LONG)span.GetTotalSeconds()));
	//SetObjectPropValue(strProcData,_T("BlowO2_Time"),CL3Variant(Desi_Time));
	//SetObjectPropValue(strProcData,_T("ReBlow_Time"),CL3Variant(Dep_Time));
	//��վʱ��
	SetObjectPropValue(strProcData,_T("Tapping_End_Time"),CL3Variant(curTime));
	CString strFeedData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Feed_Data"),IronLadle);
	SetObjectPropValue(strFeedData,_T("IronTemp"),CL3Variant(CurTemp));


	Load=0;
	//������ױ�־ �����ѹ�ʱ��
	Dep_Flag=0;
	Dep_Time=0;
	Desi_Time=0;
	IronLadle=_T("");
	CurTemp=0;
	IronLadleNo=_T("");
	SteelGradeIndex=_T("");
	StartProcessTime=_T("");

	//��ǹǹ���1  ��ǹǹ���1
	FurnaceAge++;
	LanceAge++;
	Slag_Head++;



	if(nTrans > 0)
		Commit(nTrans);

	

	return 0;
}





/// <Method class="CDEP_Unit_Mag" name="FeedElement" type="L3BOOL">
/// ��DEP�м��ϡ�
/// <Param name="rsElement" type="L3RECORDSET">�������ݣ��������ͣ����ϴ��룬����</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::FeedElement(L3RECORDSET rsElement)
{
	CL3RecordSetWrap rs = rsElement;
	if(rs.GetRowCount() < 1)
		return FALSE;

	if(rs.GetFieldIndex(_T("Element")) < 0 ||
		rs.GetFieldIndex(_T("Type")) < 0 ||
		rs.GetFieldIndex(_T("Weight")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldIndex(_T("Discharge_Time")) < 0)
	{
		bUseTimeNow = TRUE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��ȡ¯��
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ��¼���ϼ�¼
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		if(bUseTimeNow)
			rsLog.SetFieldByName(_T("Discharge_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}

/// <Method class="CDEP_Unit_Mag" name="TopBlowing" type="L3BOOL">
/// ������¼DEP�����¼���
/// <Param name="rsBlow" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::TopBlowing(L3RECORDSET rsBlow)
{
	//CL3RecordSetWrap rs = rsBlow;
	//if(rs.GetRowCount() < 1)
	//	return FALSE;

	//// �������
	//if(rs.GetFieldByName(_T("Flow")) < 0 ||
	//	rs.GetFieldByName(_T("Pressure")) < 0)
	//{
	//	SetL3LastError(L3ERR_WRONG_PARAMETER);
	//	return FALSE;
	//}

	//BOOL bUseTimeNow = FALSE;
	//if(rs.GetFieldByName(_T("Catch_Time")) < 0)
	//{
	//	bUseTimeNow = TRUE;
	//}

	//LONG nTrans = 0;
	//if(!IsInTrans())
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return FALSE;
	//}

	//// ������DEP
	//if(!PutObjectIntoTrans(GetURI()))
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return FALSE;
	//}

	//// ��ȡ¯��
	//CString strHeatID = HeatID;
	//COleDateTime curTime = COleDateTime::GetCurrentTime();

	//// ��¼������¼
	//CL3RecordSetWrap rsLog;
	//if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Top_Blowing"),rsLog))
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return FALSE;
	//}
	//rs.MoveFirst();
	//rsLog.CopyFrom(rs);
	//rsLog.MoveFirst();
	//while(!rsLog.IsEOF())
	//{
	//	rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	//	if(bUseTimeNow)
	//		rsLog.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));
	//	rsLog.MoveNext();
	//}
	//rsLog.MoveFirst();
	//if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Top_Blowing"),rsLog) < 1)
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return FALSE;
	//}

	//// ���µ�ǰ��������
	//rsLog.MoveFirst();
	//L3DATETIME dtMax = 0;
	//while(!rsLog.IsEOF())
	//{
	//	L3DATETIME dt = rsLog.GetFieldByName(_T("Catch_Time")).ToDateTime();
	//	if(dt > dtMax)
	//	{
	//		SetPropValue(_T("TopFlow"),rsLog.GetFieldByName(_T("Flow")));
	//		SetPropValue(_T("TopPressure"),rsLog.GetFieldByName(_T("Pressure")));
	//		dtMax = dt;
	//	}
	//	rsLog.MoveNext();
	//}

	//if(nTrans > 0)
	//	Commit(nTrans);

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="BottomBlowing" type="L3BOOL">

/// </Method> ��ʼ����SI  
L3BOOL CDEP_Unit_Mag::StartSlag()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPBeginSlag )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSlag))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}

//  ��������SI
L3BOOL CDEP_Unit_Mag::EndSlag()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPEndSlag )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSlag))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}



//��ʼ����P
L3BOOL CDEP_Unit_Mag::StartSlagP()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPBeginSlagP )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSlagP))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}

//  ��������P
L3BOOL CDEP_Unit_Mag::EndSlagP()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPEndSlagP )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSlagP))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}

// ��ʼ�紵SI
L3BOOL CDEP_Unit_Mag::StartSpray()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPBeginSpray )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSpray))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
   COleDateTime curTime = COleDateTime::GetCurrentTime();
	//if(Dep_Flag<1)
	//{
	 Desi_Start_time=curTime;
	
	//}
	/*else
	{
	Dep_Start_time=curTime;
	}*/


	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}


// �����紵SI
L3BOOL CDEP_Unit_Mag::EndSpray()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPEndSpray )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSpray))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	//���ױ�־Ϊ0 ��ʱ����ѹ�  1ʱ �ѹ�
	//if(Dep_Flag<1)
	//{
	COleDateTimeSpan span = curTime - Desi_Start_time;
	L3LONG  time=(LONG)span.GetTotalSeconds();
	//SetObjectPropValue(strProcData,_T("Tapping_Time"),CL3Variant((LONG)span.GetTotalSeconds()));
	Desi_Time+=time;
	
	/////
   CString csURI = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);
   SetObjectPropValue(csURI,_T("BlowO2_Time"),CL3Variant(L3LONG(Desi_Time)));//�ѹ��紵ʱ��
	/////                                  
	//}
	//else
	//{
	//COleDateTimeSpan span = curTime - Dep_Start_time;
	//L3LONG  time=(LONG)span.GetTotalMinutes();
	//Dep_Time+=time;
	////Dep_Start_time=curTime;
	//}
	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}




// ��ʼ�紵P
L3BOOL CDEP_Unit_Mag::StartSprayP()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPBeginSprayP )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSprayP))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
   COleDateTime curTime = COleDateTime::GetCurrentTime();
	/*if(Dep_Flag<1)
	{
	 Desi_Start_time=curTime;
	
	}
	else
	{
	Dep_Start_time=curTime;
	}*/

 Dep_Start_time=curTime;
	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}


// �����紵P
L3BOOL CDEP_Unit_Mag::EndSprayP()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPEndSprayP )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSprayP))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	//���ױ�־Ϊ0 ��ʱ����ѹ�  1ʱ �ѹ�
	/*if(Dep_Flag<1)
	{
	COleDateTimeSpan span = curTime - Desi_Start_time;
	L3LONG  time=(LONG)span.GetTotalMinutes();
	Desi_Time+=time;
	
	
	}
	else
	{*/
	COleDateTimeSpan span = curTime - Dep_Start_time;
	L3LONG  time=(LONG)span.GetTotalSeconds();
	Dep_Time+=time;
 //Dep_Start_time=curTime;
	/*}*/
	////
   CString csURI = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);
   SetObjectPropValue(csURI,_T("ReBlow_Time"),CL3Variant(Dep_Time));///�����紵ʱ��
	////
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}



// ������ʼ
L3BOOL CDEP_Unit_Mag::ReblowBeginSpray()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPBeginReblow )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}
	
	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginReblow))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
  /* COleDateTime curTime = COleDateTime::GetCurrentTime();
	if(Dep_Flag<1)
	{
	 Desi_Start_time=curTime;
	
	}
	else
	{
	Dep_Start_time=curTime;
	}*/
 /*CL3RecordSetWrap rs;*/
	L3SHORT  count = 0;
	

	   count += count;
	   //count1=count1+count;
	  
	/////
//CString csURI = _T("XGMESLogic\\DePMag\\CDEP_Process_Data\\");

   
	//SetObjectPropValue(csURI+HeatID,_T("ReBlow_Count"),CL3Variant((L3SHORT)count));
   CString csURI = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);
   SetObjectPropValue(csURI,_T("ReBlow_Count"),CL3Variant((L3SHORT)count));
	


	/////



	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}


// ��������
L3BOOL CDEP_Unit_Mag::ReblowEndSpray()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
	if(( Status == CDEP_Unit_Mag::DEPEndReblow )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// �޸ĵ�ǰ״̬
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndReblow))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	//���ױ�־Ϊ0 ��ʱ����ѹ�  1ʱ �ѹ�
	/*if(Dep_Flag<1)
	{
	COleDateTimeSpan span = curTime - Desi_Start_time;
	L3LONG  time=(LONG)span.GetTotalMinutes();
	Desi_Time+=time;
	
	}
	else
	{
	COleDateTimeSpan span = curTime - Dep_Start_time;
	L3LONG  time=(LONG)span.GetTotalMinutes();
	Dep_Time+=time;
	
	}*/
	////
CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Status"),HeatID);
CString strProc = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);
CString csStatus =  GetObjectPropValue(strProcData,_T("Status")).ToCString();
if (Status==11)
 {
   COleDateTime dReblowBeginTime = GetObjectPropValue(strProcData,_T("Change_Time")).ToDateTime();
   COleDateTime curTime = COleDateTime::GetCurrentTime();
   
   COleDateTimeSpan span = curTime - dReblowBeginTime;
	L3LONG  time=(LONG)span.GetTotalSeconds();
	time += time;
	SetObjectPropValue(strProc,_T("Single_LaC"),CL3Variant(time));//����ʱ��
	
   }
	////
       
////

	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}



//L3BOOL CDEP_Unit_Mag::StartSi()
//{
//	LONG nTrans = 0;
//	if(!IsInTrans())
//	{
//		nTrans = BeginTrans();
//		if(nTrans < 1)
//			return FALSE;
//	}
//	// ������DEP
//	if(!PutObjectIntoTrans(GetURI()))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//
//	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
//	if(( Status == CDEP_Unit_Mag::DEPBeginSi )||(Status == CDEP_Unit_Mag::DEPWaiting))
//	{	// �Ѿ��������״̬
//		Rollback(nTrans);
//		//SetL3LastError(XGMES_ERR_BOFREFUSED);
//		return FALSE;
//	}
//
//	// �޸ĵ�ǰ״̬
//	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSi))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//	//if(Step<2)
//	//{
//	// COleDateTime curTime = COleDateTime::GetCurrentTime();
//	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
//	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
//	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
//	//
//	//}
//	   
//	if(nTrans > 0)
//		Commit(nTrans);
//	return TRUE;
//}
//
//L3BOOL CDEP_Unit_Mag::EndSi()
//{
//	LONG nTrans = 0;
//	if(!IsInTrans())
//	{
//		nTrans = BeginTrans();
//		if(nTrans < 1)
//			return FALSE;
//	}
//	// ������DEP
//	if(!PutObjectIntoTrans(GetURI()))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//
//	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
//	if(( Status == CDEP_Unit_Mag::DEPEndSi )||(Status == CDEP_Unit_Mag::DEPWaiting))
//	{	// �Ѿ��������״̬
//		Rollback(nTrans);
//		//SetL3LastError(XGMES_ERR_BOFREFUSED);
//		return FALSE;
//	}
//
//	// �޸ĵ�ǰ״̬
//	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSi))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//	//if(Step<2)
//	//{
//	// COleDateTime curTime = COleDateTime::GetCurrentTime();
//	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
//	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
//	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
//	//
//	//}
//	   
//	if(nTrans > 0)
//		Commit(nTrans);
//	return TRUE;
//}
//
//L3BOOL CDEP_Unit_Mag::StartP()
//{
//	LONG nTrans = 0;
//	if(!IsInTrans())
//	{
//		nTrans = BeginTrans();
//		if(nTrans < 1)
//			return FALSE;
//	}
//	// ������DEP
//	if(!PutObjectIntoTrans(GetURI()))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//
//	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
//	if(( Status == CDEP_Unit_Mag::DEPBeginP )||(Status == CDEP_Unit_Mag::DEPWaiting))
//	{	// �Ѿ��������״̬
//		Rollback(nTrans);
//		//SetL3LastError(XGMES_ERR_BOFREFUSED);
//		return FALSE;
//	}
//    //���ױ�־ ��1
//	Dep_Flag=1;
//
//	// �޸ĵ�ǰ״̬
//	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginP))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//	//if(Step<2)
//	//{
//	// COleDateTime curTime = COleDateTime::GetCurrentTime();
//	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
//	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
//	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
//	//
//	//}
//	   
//	if(nTrans > 0)
//		Commit(nTrans);
//	return TRUE;
//}
//
//
//L3BOOL CDEP_Unit_Mag::EndP()
//{
//	LONG nTrans = 0;
//	if(!IsInTrans())
//	{
//		nTrans = BeginTrans();
//		if(nTrans < 1)
//			return FALSE;
//	}
//	// ������DEP
//	if(!PutObjectIntoTrans(GetURI()))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//
//	// ���DEP״̬2009-01-02 tangyi  �Ѿ���ʼ���������ѳ�վ
//	if(( Status == CDEP_Unit_Mag::DEPEndP )||(Status == CDEP_Unit_Mag::DEPWaiting))
//	{	// �Ѿ��������״̬
//		Rollback(nTrans);
//		//SetL3LastError(XGMES_ERR_BOFREFUSED);
//		return FALSE;
//	}
//
//	// �޸ĵ�ǰ״̬
//	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndP))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//	//if(Step<2)
//	//{
//	// COleDateTime curTime = COleDateTime::GetCurrentTime();
//	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
//	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
//	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
//	//
//	//}
//	   
//	if(nTrans > 0)
//		Commit(nTrans);
//	return TRUE;
//}
//
//
//

/// <Method class="CDEP_Unit_Mag" name="SetOxygen" type="L3BOOL">
/// ������¼�����¼���
/// <Param name="rsOxygen" type="L3RECORDSET">��������</Param>
/// </Method>

/// <Method class="CDEP_Unit_Mag" name="SetTemperature" type="L3BOOL">
/// ������¼DEP�����¼���
/// <Param name="rsTemp" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::SetTemperature(L3RECORDSET rsTemp)
{
	CL3RecordSetWrap rs = rsTemp;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// �������
	if(rs.GetFieldIndex(_T("Temp")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldIndex(_T("Temp_Time")) < 0)
	{
		bUseTimeNow = TRUE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// ������DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��ȡ¯��
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ��¼���¼�¼
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Temp_Data"),rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	L3DOUBLE fTemp = 0;
	DATE dtTime = 0;
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		if(bUseTimeNow)
			rsLog.SetFieldByName(_T("Temp_Time"),CL3Variant(curTime));
		DATE dtTimeThis = rsLog.GetFieldByName(_T("Temp_Time")).ToDateTime();
		if(dtTimeThis > dtTime)
		{
			fTemp = rsLog.GetFieldByName(_T("Temp")).ToDouble();
			dtTime = dtTimeThis;
		}
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Temp_Data"),rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}




	CurTemp = fTemp;

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
/// �޸�DEP�豸״̬
/// <Param name="nStatus" type="L3LONG">���豸״̬</Param>
/// <Param name="reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::ChangeDeviceStatus(L3LONG nStatus,L3STRING reason)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// �޸��豸״̬
	//if(!SetPropValue(_T("Status"),CL3Variant(nStatus)))
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return FALSE;
	//}

	if(!SetPropValue(_T("Equip_Status"),CL3Variant(nStatus)))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��¼�豸״̬�����־
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Equipment_Status"),rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsLog.AppendRecord();
	CString cstrUnitID = (GetIdentity().ToCString()).Right(1);
	rsLog.SetFieldByName(_T("DEPID"),(L3LONG)_ttoi(cstrUnitID));
	rsLog.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsLog.SetFieldByName(_T("Log_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsLog.SetFieldByName(_T("Reason"),CL3Variant(reason));
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Equipment_Status"),rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}





/// <Method class="CDEP_Unit_Mag" name="GetIronsForDesignate" type="L3RECORDSET">
/// ���ؿ�����ָ��¯�ŵ���ˮ��Ϣ��
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetIronsForDesignate()
{
	CString strInput = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(strInput,_T("GetMaterialDetails"),_T("CIron_Data"),_T(""));
	CL3RecordSetWrap rsRet;
	if(FAILED(valRet.QueryInterface(IID_IL3RecordSet,rsRet)))
		return NULL;
	else
	{
		CL3RecordSetWrap rsIron;
		CreateClassPropSet(MATERIAL_IRON_URI,rsIron);
		rsRet.MoveFirst();
		rsIron.CopyFrom(rsRet);
		return rsIron.Detach();
	}
}

/// <Method class="CDEP_Unit_Mag" name="GetInputIrons" type="L3RECORDSET">
/// �����Ѿ�ָ���˵���ˮ��Ϣ
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetInputIrons()
{
	// ��ȡ��ָ������ˮ
	CL3RecordSetWrap rsIrons;
	CString strCond; 
	//strCond.Format(_T(" HeatID = '%s'"),(LPCTSTR)NextHeatID);
	//2009-02-28
	strCond.Format(_T(" HeatID = '%s'"),(LPCTSTR)HeatID);
	CString strIronType = MATERIAL_IRON_URI;
	CBSTR bstrIronType = strIronType;
	CBSTR bstrCond(strCond);
	CL3Variant valIrons = InvokeObjectMethod(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S91P01"),_T("GetMaterialDetails"),bstrIronType.GetBuffer(TRUE),bstrCond.GetBuffer(TRUE));
	if(FAILED(valIrons.QueryInterface(IID_IL3RecordSet,rsIrons)))
	{
		return NULL;
	}
	
	return rsIrons.Detach();
}

/// <Method class="CDEP_Unit_Mag" name="GetInputScrapes" type="L3RECORDSET">
/// �����Ѿ�ָ���˵������ϸ���Ϣ
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetInputScrapes()
{
	//CL3RecordSetWrap rsScrapes;
	//CString strSQL;
	////strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag,StoreAreaID,Amount from %s where Iron_Flag = 1 and HeatID = '%s'"),SCRAP_OUT_CLASS_URI,NextHeatID);
	//strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag,StoreAreaID,Amount from %s where Iron_Flag = 1 and HeatID = '%s'"),SCRAP_OUT_CLASS_URI,HeatID);
	//if(!Query(strSQL,rsScrapes))
	//{
		return NULL;
	//}
	/*return rsScrapes.Detach();*/
}

/// <Method class="CDEP_Unit_Mag" name="OnTimer" type="L3BOOL">
/// ��ʱ������
/// <Param name="uEventID" type="L3ULONG">�¼�ID</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::OnTimer(L3ULONG uEventID)
{
	//if(uEventID == m_nTimer)
	//{	// ������ʱ��
	//	BlowTotalTime += BLOWTIME;
	//	BlowThisTime += BLOWTIME;
	//}

	return TRUE;
}

/// <Method class="CDEP_Unit_Mag" name="GetAddedMaterialSum" type="L3RECORDSET">
/// ����ָ��¯�ŵļ�����ͳ�����ݡ�
/// <Param name="HeatID" type="L3STRING">¯��</Param>
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetAddedMaterialSum(L3STRING HeatID)
{
	CString strHeatID = String_BSTR2TChar(HeatID);
	CString strSQL;
	strSQL.Format(_T("select Element,Type,sum(Weight) as Weight from %s where HeatID = '%s' group by Element, Type"),
			_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),(LPCTSTR)strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog))
		return NULL;
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	return rsLog.Detach();
}


/// <Method class="CDEP_Unit_Mag" name="AcceptAlloyDischargeData" type="L3RECORDSET">
/// �ϲּ������ݲɼ�
/// <Param name="HeatID" type="L3STRING">¯��</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptMaterialDischargeData(L3RECORDSET rsMaterialData)
{
	//2009-03-28 tangyi�����߼����ϲֺϽ�ɢװ�ϰ����Ƚ��ȳ���ԭ���������ϣ�
	//��PLC�ϴ�һ���������ܻ���Ϊ���εĲ�ͬ��ֳɼ�������

	CL3RecordSetWrap rsData =rsMaterialData;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	if(rsData.GetFieldIndex(_T("PLC_Address")) < 0 ||
	   rsData.GetFieldIndex(_T("Amount")) < 0 )
			return FALSE;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog))
		return NULL;

	//�齨���ݼ��Ͻ�ԭ�Ͽ����
	CL3RecordSet *pRSAlloy = new CL3RecordSet();
	CL3RecordSetWrap rsAlloyOut; pRSAlloy->QueryInterface(IID_IL3RecordSet,rsAlloyOut); pRSAlloy->Release();
	rsAlloyOut.AddField(_T("MaterialID"),VT_BSTR);
	rsAlloyOut.AddField(_T("MaterialType"),VT_BSTR);
	rsAlloyOut.AddField(_T("Amount"),VT_R8);
	rsAlloyOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Target"),VT_BSTR);
	rsAlloyOut.AddField(_T("UnitID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Alloy_Code"),VT_BSTR);
	rsAlloyOut.AddField(_T("Batch_ID"),VT_BSTR);

	//�齨���ݼ�ɢ״��ԭ�Ͽ����
	//CL3RecordSet *pRSBulk = new CL3RecordSet();
	//CL3RecordSetWrap rsBulkOut; pRSBulk->QueryInterface(IID_IL3RecordSet,rsBulkOut); pRSBulk->Release();
	//rsBulkOut.AddField(_T("MaterialID"),VT_BSTR);
	//rsBulkOut.AddField(_T("MaterialType"),VT_BSTR);
	//rsBulkOut.AddField(_T("Amount"),VT_R8);
	//rsBulkOut.AddField(_T("StoreAreaID"),VT_BSTR);
	//rsBulkOut.AddField(_T("Target"),VT_BSTR);
	//rsBulkOut.AddField(_T("UnitID"),VT_BSTR);
	//rsBulkOut.AddField(_T("Bulk_Code"),VT_BSTR);
	//rsBulkOut.AddField(_T("Batch_ID"),VT_BSTR);

	//�齨���ݼ���������2009-03-28 tangyi
	CL3RecordSet *pRSMaterial = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRSMaterial->QueryInterface(IID_IL3RecordSet,rsMaterial); pRSMaterial->Release();
	rsMaterial.AddField(_T("Batch_ID"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("Element"),VT_BSTR);
	rsMaterial.AddField(_T("Weight"),VT_R8);

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rsMaterial.DeleteAll();
		//2009-03-06  DEP����ɢ״���ۼ������ռ�
		//ת��MES�Ͻ��ϲֺ�
		CString csPlcAddress = rsData.GetFieldByName(_T("PLC_Address")).ToCString();
		//L3SHORT iType = rsData.GetFieldByName(_T("Type")).ToShort(); //ɢ״���ۼ� iType = 9;
		////2009-05-11 begin ���ֿ�ʼ����¯���������������ϲ�������̼��������
		//if (((Status >= CDEP_Unit_Mag::DEPTapping) || (Status <= CDEP_Unit_Mag::DEPBlowing)) && (iType == 2))
		//{
		//	rsData.SetFieldByName(_T("Type"),CL3Variant((L3SHORT)1));
		//	iType = 1;
		//}
		//2009-05-11 end
	   /*	csPlcAddress.Replace(_T("."),_T("_"));*/
		csPlcAddress.Trim();
		if(csPlcAddress.IsEmpty())
		{
			rsData.MoveNext();
			continue;
		}
		CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\CBase_Address_Bulk_Relation\\") + csPlcAddress;
		CString csArea = GetObjectPropValue(csAreaUri,_T("Area")).ToCString();
		csArea.Trim();
		// S83Y04
		CString csMaterialType = csArea.Mid(0,3);
		rsLog.AppendRecord();
		//���ݺϽ��ϲֺŵõ��Ͻ�
		CString csSQL;
		CL3RecordSetWrap rs;
		CString cstrAreaUri;
		
		//if(csMaterialType == STORE_ID_ALLOY)//�Ͻ��ϲ�
		//{
			cstrAreaUri = _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Bulk_Relation\\") + csArea;//	2008-12-28 yao
			csSQL.Format(_T(" select b.Alloy_Code as Element,b.Batch_ID,a.MaterialID,a.MaterialType,a.Amount as PosWeight from MATERIALPOSITION a,CAlloy_Data b where a.Position = '%s' and a.MaterialID = b.MaterialID order by b.Batch_ID "),csArea);
		/*}*/
		//else
		//{
		//	cstrAreaUri = _T("XGMESLogic\\BulkStoreMag\\CBulk_Bulk_Relation\\") + csArea; //	2008-12-28 yao
		//	csSQL.Format(_T(" select b.Bulk_Code as Element,b.Batch_ID,a.MaterialID,a.MaterialType,a.Amount as PosWeight  from MATERIALPOSITION a,CBulk_Data b where a.Position = '%s' and a.MaterialID = b.MaterialID order by Idx "),csArea);
		//}

		if(!Query(csSQL,rs))
			return FALSE;

		rs.MoveFirst();
		L3LONG nCount = rs.GetRowCount();
		
		//�ϲ�����������
		L3DOUBLE nWeight = rsData.GetFieldByName(_T("Amount")).ToDouble();
		//������ʼ��Ϊ��������
		L3DOUBLE nRemainWeight = nWeight;

		//���Ƚ��ȳ������������������ݼ�
		for(int i=0;i< nCount;i++)
		{	
			rsMaterial.AppendRecord();
			//�������͡����ϱ��롢���κš����Ϻ�
			rsMaterial.CopyCurRowFrom(rs);
			//�õ��ϲֵ�ǰ����
			L3DOUBLE nPosWeight = rs.GetFieldByName(_T("PosWeight")).ToDouble();
			if(nWeight - nPosWeight < 0)
			{
				rsMaterial.SetFieldByName(_T("Weight"),CL3Variant(nWeight));
				nRemainWeight = 0;
				break;
			}
			rsMaterial.SetFieldByName(_T("Weight"),CL3Variant(nPosWeight));
			nWeight = nWeight - nPosWeight;
			nRemainWeight = nWeight;//�õ�����
			rs.MoveNext();
		}
		//�ϲ���û��ֵ�������ϲ�����ϲ��㹤������
		if(nRemainWeight > 0)
		{
			rsMaterial.AppendRecord();
			rsMaterial.SetFieldByName(_T("Batch_ID"),CL3Variant(_T("")));
			rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(_T("NoMaterialID")));
			//��MES�ϲ����ݲ���ȷ������£�rs���ݿ���Ϊ�գ��ʱ�����ϲ����ֶ�Ӧ��ϵ�л�ȡ2008-12-30 tangyi
	/*		if(csMaterialType == STORE_ID_ALLOY)
			{*/
				rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
				rsMaterial.SetFieldByName(_T("Element"),GetObjectPropValue(cstrAreaUri,_T("Alloy_Code")));	
			/*}
			else
			{
				rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BULK));
				rsMaterial.SetFieldByName(_T("Element"),GetObjectPropValue(cstrAreaUri,_T("Bulk_Code")));	
			}*/
			rsMaterial.SetFieldByName(_T("Weight"),CL3Variant(nRemainWeight));
		}

        L3LONG dep_type;
		if(Status==2)
		{
			dep_type=0;
		}else if (Status==5||Status==6)
		{
			dep_type=1;
		}

		rsMaterial.MoveFirst();
		while(!rsMaterial.IsEOF())
		{
			rsLog.AppendRecord();
			rsLog.CopyCurRowFrom(rsMaterial);//���κš�����,����
			rsLog.SetFieldByName(_T("Discharge_Time"),COleDateTime::GetCurrentTime());
			rsLog.SetFieldByName(_T("Area"),CL3Variant(csArea)); //2009-01-07 yao	
			//2008-12-28 begin yao
			CString csDishcargingHeatID;
			if (Status == CDEP_Unit_Mag::DEPWaiting) //2009-03-10 DEP�ȴ�״̬��������Ϊ��¯��
			{
				//��ǰ¯�γ��ֿ�ʼ�󣬴���λ��ϵͳ�ռ���ɢ״�����ݼ�Ϊ��¯������
				csDishcargingHeatID = NextHeatID;
			}
			else
			{
				csDishcargingHeatID = HeatID;
				//��ǰ¯�γ��ֿ�ʼǰ������λ��ϵͳ�ռ���ɢ״�����ݼ�Ϊ��ǰ¯������
			}

		
			CString csMaterialID = rsMaterial.GetFieldByName(_T("MaterialID")).ToCString();
			csMaterialID.Trim();
			

			//if(csMaterialType == STORE_ID_ALLOY)//�Ͻ��ϲ�
			//{
    			rsLog.SetFieldByName(_T("HeatID"),CL3Variant(csDishcargingHeatID));
				//rsLog.SetFieldByName(_T("Type"),CL3Variant(L3LONG(5)));
				rsLog.SetFieldByName(_T("Type"),CL3Variant(dep_type));
 			
				if(csMaterialID != _T("NoMaterialID"))
				{
					rsAlloyOut.AppendRecord();
					rsAlloyOut.CopyCurRowFrom(rsMaterial);
					rsAlloyOut.SetFieldByName(_T("Amount"),rsMaterial.GetFieldByName(_T("Weight")));
					rsAlloyOut.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));
					rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csDishcargingHeatID));
					rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));	
					rsAlloyOut.SetFieldByName(_T("Alloy_Code"),rsMaterial.GetFieldByName(_T("Element")));
				}
		
			rsMaterial.MoveNext();		
		}

		rsData.MoveNext();	
	}


	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog) < rsLog.GetRowCount())
		return FALSE;


	if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0)
		InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsAlloyOut));


	return TRUE;
}


/// <Method class="CDEP_Unit_Mag" name="MaterialGroundDischargeData" type="L3RECORDSET">
/// ��װ�Ͻ�ɢ״������
/// <Param name="HeatID" type="L3STRING">¯��</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::MaterialGroundDischargeData(L3RECORDSET rsMaterialData)
{
	CL3RecordSetWrap rsData =rsMaterialData;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	if(rsData.GetFieldIndex(_T("StoreAreaID")) < 0 ||
	   rsData.GetFieldIndex(_T("MaterialID")) < 0 ||
	   rsData.GetFieldIndex(_T("MaterialType")) < 0 ||
	   rsData.GetFieldIndex(_T("Batch_ID")) < 0 ||
	   rsData.GetFieldIndex(_T("Amount")) < 0 )
			return FALSE;

		CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog))
		return NULL;

	//�齨���ݼ��Ͻ�ԭ�Ͽ����
	CL3RecordSet *pRSAlloy = new CL3RecordSet();
	CL3RecordSetWrap rsAlloyOut; pRSAlloy->QueryInterface(IID_IL3RecordSet,rsAlloyOut); pRSAlloy->Release();
	rsAlloyOut.AddField(_T("MaterialID"),VT_BSTR);
	rsAlloyOut.AddField(_T("MaterialType"),VT_BSTR);
	rsAlloyOut.AddField(_T("Amount"),VT_R4);
	rsAlloyOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Target"),VT_BSTR);
	rsAlloyOut.AddField(_T("UnitID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Alloy_Code"),VT_BSTR);
	rsAlloyOut.AddField(_T("Batch_ID"),VT_BSTR);

	//�齨���ݼ�ɢ״��ԭ�Ͽ����
	CL3RecordSet *pRSBulk = new CL3RecordSet();
	CL3RecordSetWrap rsBulkOut; pRSBulk->QueryInterface(IID_IL3RecordSet,rsBulkOut); pRSBulk->Release();
	rsBulkOut.AddField(_T("MaterialID"),VT_BSTR);
	rsBulkOut.AddField(_T("MaterialType"),VT_BSTR);
	rsBulkOut.AddField(_T("Amount"),VT_R4);
	rsBulkOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsBulkOut.AddField(_T("Target"),VT_BSTR);
	rsBulkOut.AddField(_T("UnitID"),VT_BSTR);
	rsBulkOut.AddField(_T("Bulk_Code"),VT_BSTR);
	rsBulkOut.AddField(_T("Batch_ID"),VT_BSTR);

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csArea = rsData.GetFieldByName(_T("StoreAreaID")).ToCString();
		CString csMaterialID = rsData.GetFieldByName(_T("MaterialID")).ToCString();
		CString csMaterialType = csArea.Mid(0,3);
		rsLog.AppendRecord();
		rsLog.CopyCurRowFrom(rsData);
		rsLog.SetFieldByName(_T("Weight"),rsData.GetFieldByName(_T("Amount")));
		rsLog.SetFieldByName(_T("Discharge_Time"),COleDateTime::GetCurrentTime());
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsLog.SetFieldByName(_T("Area"),CL3Variant(csArea)); //2009-01-07 yao	
		if(csMaterialType == STORE_ID_ALLOY)//�Ͻ��ϲ�
		{
			rsLog.SetFieldByName(_T("Element"),rsData.GetFieldByName(_T("Alloy_Code")));	
			rsLog.SetFieldByName(_T("Type"),CL3Variant(L3LONG(5)));
			rsAlloyOut.AppendRecord();
			rsAlloyOut.CopyCurRowFrom(rsData);
			rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(HeatID));
			rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));		
		}
		else
		{
			rsLog.SetFieldByName(_T("Element"),rsData.GetFieldByName(_T("Bulk_Code")));	
			rsLog.SetFieldByName(_T("Type"),CL3Variant(L3LONG(1)));
			rsBulkOut.AppendRecord();
			rsBulkOut.CopyCurRowFrom(rsData);
			rsBulkOut.SetFieldByName(_T("Target"),CL3Variant(HeatID));
			rsBulkOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));
		}

		rsData.MoveNext();		
	}

	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog) < rsLog.GetRowCount())
		return FALSE;

	//if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0)
	//{
	//	CL3Variant vtRtn = InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsAlloyOut));
	//	if(vtRtn.IsError() || !vtRtn.ToBOOL())
	//		return FALSE;
	//}
	//if(!rsBulkOut.IsNull() && rsBulkOut.GetRowCount() > 0)
	//{
	//	CL3Variant vtRtn = InvokeObjectMethod(BULK_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsBulkOut));
	//	if(vtRtn.IsError() || !vtRtn.ToBOOL())
	//		return FALSE;
	//}

	return TRUE;
}





/// <Method class="CDEP_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
/// ����ĸ�
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_EXE_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),csHeatID);
	CString csPreHeatID = GetObjectPropValue(csUri,_T("PreHeatID")).ToCString();
	rsSteel.SetFieldByName(_T("PreHeatID"),CL3Variant(csPreHeatID));
	rsSteel.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rsSteel.SetFieldByName(_T("SteelGradeIndex"),GetObjectPropValue(csUri,_T("SteelGradeIndex")));//2008-12-30 tangyi
	rsSteel.SetFieldByName(_T("App_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsSteel.SetFieldByName(_T("App_Steel_Weight"),CL3Variant(fWeight));
	rsSteel.SetFieldByName(_T("App_Operator"),CL3Variant(GetCurrentUser()));
	rsSteel.SetFieldByName(_T("App_UnitID"),GetIdentity());
	rsSteel.SetFieldByName(_T("App_Reason"),CL3Variant(Reason));

	CString strDispMag =DISPATCH_OBJ_URI;
	CL3Variant val = InvokeObjectMethod(strDispMag,_T("SteelExchangeApp"),(L3RECORDSET)rsSteel);
	return val.ToBOOL();

}


/// <Method class="CDEP_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  ��ˮ��¯���� 2009-02-28 ����¯��
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_TURN_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	//CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csHeatID = strHeatID;
	CString csUri = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),csHeatID);
	CString csPreHeatID = GetObjectPropValue(csUri,_T("PreHeatID")).ToCString();
	rsSteel.SetFieldByName(_T("PreHeatID"),CL3Variant(csPreHeatID));
	rsSteel.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rsSteel.SetFieldByName(_T("SteelGradeIndex"),GetObjectPropValue(csUri,_T("SteelGradeIndex")));//2008-12-30 tangyi
	rsSteel.SetFieldByName(_T("App_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsSteel.SetFieldByName(_T("App_Steel_Weight"),CL3Variant(fWeight));
	rsSteel.SetFieldByName(_T("App_Operator"),CL3Variant(GetCurrentUser()));
	rsSteel.SetFieldByName(_T("App_UnitID"),GetIdentity());
	rsSteel.SetFieldByName(_T("App_Reason"),CL3Variant(Reason));

	CString strDispMag =DISPATCH_OBJ_URI;
	CL3Variant val = InvokeObjectMethod(strDispMag,_T("SteelTurnApp"),(L3RECORDSET)rsSteel);
	return val.ToBOOL();
}

/// <Method class="CDEP_Unit_Mag" name="GetExceptHeatID" type="L3RECORDSET">
/// ��ȡ�����쳣¯�����ݡ�
/// <Param name="UnitID" type="L3STRING">��λ</Param>
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetExceptHeatID(L3STRING UnitID)
{
	CString strUnitID = String_BSTR2TChar(UnitID);
	int nUnitTypeID = _ttoi(strUnitID.Mid(1,1));
	CString csUnitID = strUnitID.Mid(2,1);
	CString strSQL;
	switch(nUnitTypeID)
	{
	case 9:
		{	//DEP
			strSQL.Format(_T("select HeatID from (select HeatID from %s  order by ProductionDate desc) where rownum < 3"),
					_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),csUnitID);
		}
		break;
	case 4:
		{	//LF¯
			strSQL.Format(_T("select HeatID from (select HeatID from %s where substr(TreatNo,1,1) = '%s' order by ProductionDate desc) where rownum < 3"),
					LF_BASE_DATA_CLASS_URI,csUnitID);
		}
		break;
	case 5:
		{	// RH¯
			strSQL.Format(_T("select HeatID from (select HeatID from %s where substr(TreatNo,1,1) = '%s' order by ProductionDate desc) where rownum < 3"),
					RH_BASE_DATA_CLASS_URI,csUnitID);
		}
		break;
	case 6:
		{	//����
			strSQL.Format(_T("select HeatID from (select HeatID from %s where substr(TreatNo,1,1) = '%s' order by ProductionDate desc) where rownum < 3"),
					CCM_BASE_DATA_CLASS_URI,csUnitID);
		}
		break;
	default:
		{
			return NULL;
		}
	}

	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	return rs.Detach();
}

/// <Method class="CDEP_Unit_Mag" name="SetStackData" type="L3BOOL">
/// ��¼DEP¯��ά������
/// <Param name="rsData" type="L3RECORDSET">¯������</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::SetStackData(L3RECORDSET rsData)
{

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="LockData" type="L3SHORT">
/// ����ʵ������
/// <Param name="strUnitID" type="L3STRING">��λ</Param>
/// <Param name="strHeatID" type="L3STRING">¯��</Param>
/// <Param name="strTreatNo" type="L3STRING">�����</Param>
/// </Method>
L3SHORT CDEP_Unit_Mag::LockData(L3STRING strUnitID,L3STRING strHeatID,L3STRING strTreatNo)
{
	if ((strUnitID == NULL) || (strHeatID == NULL))
	{
		return -1;
	}

	CString csUnitID = strUnitID;
	CString csHeatID = strHeatID;
	CString csTreatNo = strTreatNo;

	CString csLockFlag;
	CString csURI;
	CString csPropName;

	//2009-04-14 �˹�ȷ����־ʱ���ֹ�¼����ϴӴ�װ�Ͻ𴦳���
	//�齨���ݼ��Ͻ�ԭ�Ͽ����
	CL3RecordSet *pRSAlloy = new CL3RecordSet();
	CL3RecordSetWrap rsAlloyOut; pRSAlloy->QueryInterface(IID_IL3RecordSet,rsAlloyOut); pRSAlloy->Release();
	rsAlloyOut.AddField(_T("MaterialID"),VT_BSTR);
	rsAlloyOut.AddField(_T("MaterialType"),VT_BSTR);
	rsAlloyOut.AddField(_T("Amount"),VT_R8);
	rsAlloyOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Target"),VT_BSTR);
	rsAlloyOut.AddField(_T("UnitID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Alloy_Code"),VT_BSTR);
	rsAlloyOut.AddField(_T("Batch_ID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Type"),VT_R4);

	


		//Modify end
		//csURI = _T("XGMESLogic\\DePMag\\CDEP_Base_Data\\");
	 //   csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("DEPFinishedFlag"))).ToCString();
      /*  csPropName = _T("BOFFinishedFlag");*/
		//DEP�ֹ�����Ͻ�
		CString csTempSQL = _T(" select * from CDEP_ADDITION_DATA where Name ='1'  and HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs))
			return -5;
		rs.MoveFirst();
		while(!rs.IsEOF())
		{	
			CString csAlloyCode = rs.GetFieldByName(_T("Element")).ToCString();
			CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString();
			CString csSQL;
			CString	csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='15' ");
			CL3RecordSetWrap rsResult;
			csSQL.Format(csTempSQL,csAlloyCode);
			if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
			{
				rs.MoveNext();
				continue;
				
			}
			rsResult.MoveFirst();
			rsAlloyOut.AppendRecord();
			rsAlloyOut.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
			rsAlloyOut.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
			rsAlloyOut.SetFieldByName(_T("Amount"),rs.GetFieldByName(_T("Weight")));
			rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csHeatID));
			rsAlloyOut.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
			rsAlloyOut.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
			rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(csUnitID));
			rsAlloyOut.SetFieldByName(_T("Type"),L3LONG(5));
			rsAlloyOut.SetFieldByName(_T("StoreAreaID"),rsResult.GetFieldByIndex(0));
			rs.MoveNext();
		}
		
	
	



	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}
	csURI = _T("XGMESLogic\\DePMag\\CDEP_Base_Data\\");

	if (!SetObjectPropValue(csURI+csTreatNo,_T("Locked"),(L3SHORT)1))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}

	//if (!SetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,csPropName,CL3Variant(_T("1"))))
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return -5;
	//}

	if(nTrans > 0)
		Commit(nTrans);

	//2009-04-14 �˹�ȷ����־ʱ���ֹ�¼����ϴӴ�װ�Ͻ𴦳���
	if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0) 
		InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsAlloyOut));

	//2009-05-22 ͬһ�����϶�����ϣ��ܹ�Ŀǰ��֧�������������ʸ�Ϊ��������
	//CL3RecordSetWrap rsFinalData = rsAlloyOut.CloneStruct();
	//rsFinalData.AppendRecord();	
	//rsFinalData.MoveFirst();
	//rsAlloyOut.MoveFirst();
	//while(!rsAlloyOut.IsEOF())
	//{
	//	rsFinalData.CopyCurRowFrom(rsAlloyOut);
	//	InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsFinalData));
	//	rsFinalData.MoveFirst();
	//	rsAlloyOut.MoveNext();
	//}
	return 0;	
}

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPStatus" type="L3BOOL">
/// ����DEP����״̬���� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">״̬����</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPStatus(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	// ��ȡ¯��
	rs.MoveFirst();
	L3LONG DEPStatus = -1;
	DEPStatus = (rs.GetFieldByName(_T("DEPStatus"))).ToLong();
	switch(DEPStatus)
	{
	case CDEP_Unit_Mag::DEPBeginSpray:
			StartSpray();
			break;
	
    case CDEP_Unit_Mag::DEPEndSpray:
			EndSpray();
			break;

	case CDEP_Unit_Mag::DEPBeginSlag:
		  StartSlag();
			
		break;
	case CDEP_Unit_Mag::DEPEndSlag:
		  EndSlag();
		break;
		
	case CDEP_Unit_Mag::DEPBeginSprayP: 
				StartSprayP();
		break;

    case CDEP_Unit_Mag::DEPEndSprayP: 
				EndSprayP();
		break;

    case CDEP_Unit_Mag::DEPBeginSlagP:
		  StartSlagP();
			
		break;
	case CDEP_Unit_Mag::DEPEndSlagP:
		  EndSlagP();
		break;

    case CDEP_Unit_Mag::DEPBeginReblow:
		  ReblowBeginSpray();
			
		break;
	case CDEP_Unit_Mag::DEPEndReblow:
		  ReblowEndSpray();
		break;

		default:
			break;
	}
	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPStatus" type="L3BOOL">
/// ����DEP  ����״̬ 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">step</Param>
///



/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPTopBlowData(L3RECORDSET rsData)
{
	//CL3RecordSetWrap rs = rsData;
	//if(rs.GetRowCount() < 1)
	//	return TRUE;

	//CL3RecordSetWrap rsBlow;
	//if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Top_Blowing"),rsBlow))
	//{
	//	return FALSE;
	//}

	//rsBlow.CopyFrom(rs);

	//rsBlow.MoveFirst();
	//while (!rsBlow.IsEOF())
	//{
	//	rsBlow.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
	//	rsBlow.SetFieldByName(_T("Catch_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	//	TopFlow = rsBlow.GetFieldByName(_T("Flow")).ToFloat();
	//	TopPressure = rsBlow.GetFieldByName(_T("Pressure")).ToFloat();
	//	rsBlow.MoveNext();
	//}

	//rsBlow.MoveFirst();
	//if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Top_Blowing"),rsBlow) < rsBlow.GetRowCount())
	//{
	//	return FALSE;
	//}

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPTappedData" type="L3BOOL">
/// ����DEP�������� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPTappedData(L3RECORDSET rsData)
{
	//CL3RecordSetWrap rs = rsData;
	//if(rs.GetRowCount() < 1)
	//	return TRUE;

	//rs.AddField(_T("HeatID"),L3VT_STRING);
	//rs.MoveFirst();
	//while (!rs.IsEOF())
	//{
	//	rs.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
	//	rs.MoveNext();
	//}

	//rs.MoveFirst();
	//SetObjsPropValues(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),rs);

	//CalculateLcTemp();

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPTempData" type="L3BOOL">
/// ����DEP�������� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPTempData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	if (Status >= CDEP_Unit_Mag::DEPWaiting) //���ֽ��������ռ��¶�����2009-01-09
	{
		return TRUE;
	}

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Temp_Data"),rsTemp))
	{
		return FALSE;
	}

			// д���ѹ������¶�
	CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);

	//		// д����ԭ���¶�
//	CString strFeedData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Feed_Data"),IronLadle);





	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("Temp_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		CurTemp = rsTemp.GetFieldByName(_T("Temp")).ToLong();

		///д���ѹ������¶�
		if(Status==4)
		{
			SetObjectPropValue(strProcData,_T("LaC_Temp"),CL3Variant(CurTemp));
		}
		else if(Status==8)
		{
			SetObjectPropValue(strProcData,_T("Tapping_Temp"),CL3Variant(CurTemp));
		}

		//SetObjectPropValue(strFeedData,_T("IronTemp"),CL3Variant(CurTemp));
		////
		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Temp_Data"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPOxygenData" type="L3BOOL">
/// ����DEP�������� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPOxygenData(L3RECORDSET rsData)
{
	//CL3RecordSetWrap rs = rsData;
	//if(rs.GetRowCount() < 1)
	//	return TRUE;

	//if (Status >= CDEP_Unit_Mag::DEPTapped) //���ֽ��������ռ��¶�����2009-01-09
	//{
	//	return TRUE;
	//}

	//CL3RecordSetWrap rsTemp;
	//if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Oxygen_Data"),rsTemp))
	//{
	//	return FALSE;
	//}

	//rsTemp.CopyFrom(rs);

	//rsTemp.MoveFirst();
	//while (!rsTemp.IsEOF())
	//{
	//	rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
	//	rsTemp.SetFieldByName(_T("Measure_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	//	rsTemp.MoveNext();
	//}

	//rsTemp.MoveFirst();
	//if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Oxygen_Data"),rsTemp) < rsTemp.GetRowCount())
	//{
	//	return FALSE;
	//}

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="CalculateLcTemp" type="L3BOOL">
/// ������̼ĩ���¶����ݣ���ԭ��ʼǰ���һ���¶�
/// </Method>
L3BOOL CDEP_Unit_Mag::CalculateLcTemp()
{
	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="CalculateTappingTemp" type="L3BOOL">


/// <Method class="CDEP_Unit_Mag" name="CalculateDefaultSmeltPeriod" type="L3BOOL">
/// ����ұ������ 2009-01-14   
/// </Method>
L3BOOL CDEP_Unit_Mag::CalculateDefaultSmeltPeriod()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString cspreviousHeatID = GetPreviousHeatID(curHeatID);
	if (cspreviousHeatID.GetLength() != 9)
	{
		return FALSE;
	}

    CString strUri = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),cspreviousHeatID);
	COleDateTime dTappingEndTime = GetObjectPropValue(strUri,_T("Tapping_End_Time")).ToDateTime();
	COleDateTime dCurTime = COleDateTime::GetCurrentTime();
	COleDateTimeSpan span = dCurTime - dTappingEndTime;
	
	LONG smeltperious = (LONG)span.GetTotalMinutes();

	CString strUri2 = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),curHeatID);
	if (smeltperious > 0)
	{
	   if (!SetObjectPropValue(strUri2,_T("Smelt_Period"),CL3Variant((L3LONG)smeltperious)))
	   {
			return FALSE; 
	   }
	}

	return TRUE;	
}

/// ��ȡ��һ¯��
CString CDEP_Unit_Mag::GetPreviousHeatID(LPCTSTR lpcszHeatID)
{
	CString cstrHeatID = lpcszHeatID;
	if (cstrHeatID.GetLength() != 9)
	{
		return _T("");
	}
	CString cspartHeatID = cstrHeatID.Right(5);
	CString csYear = cstrHeatID.Mid(2,2);
	int ipartHeatID = 0;
	int iYear = 0;
	try
	{
		ipartHeatID = _ttoi(cspartHeatID);
		iYear = _ttoi(csYear);
	}
	catch(...)
	{
	}

	CString csPreviousHeatID;
	if (ipartHeatID > 1)
	{
		csPreviousHeatID.Format(_T("%05d"),(INT)(ipartHeatID-1));
		csPreviousHeatID = cstrHeatID.Left(4) + csPreviousHeatID;
	}
	else
	{
		iYear = iYear - 1;
		CString cslastYear;
		cslastYear.Format(_T("%02d"),(INT)iYear);

		CString cssubHeatID;
		cssubHeatID = cstrHeatID.Left(2) + cslastYear;

		CString csSQL;
		csSQL.Format(_T("select max(HeatID) as HeatID from CDEP_Process_Data where substr(HeatID,1,4) ='%s'"),cssubHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
			return _T("");
		rs.MoveFirst();
		csPreviousHeatID = rs.GetFieldByName(_T("HeatID")).ToCString();
	}

	return csPreviousHeatID;
}

/// <Method class="CDEP_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  ��ȡ���¯�� 2009-02-28 ����¯��
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetPreThreeHeatID()
{
	CString csUnitID = GetIdentity().ToCString();
	CString csDEPID = csUnitID.Mid(2,1);
	CString csTempSQL =_T("select * from (select HeatID from CDEP_Base_Data where substr(HeatID,2,1) = '%s'  order by  HeatID desc) where rownum < 4");
	CString csSQL;
	csSQL.Format(csTempSQL,csDEPID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;
	return rs.Detach();	
}


/// <Method class="CDEP_Unit_Mag" name="SendStatusToPLC" type="L3BOOL">
/// ����ˮ����״̬�´�PLC 
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL  CDEP_Unit_Mag::SendStatusToPLC(L3LONG fStatus)
{
	//�齨���ݼ�
	CString csCCMID = GetIdentity().ToCString();
	
	//Modify begin by llj 2011-1-26 Add CCM7
	//if (csCCMID == _T("S65")) ���δ��޸�Ϊ�������
	//if (csCCMID == _T("S65")||csCCMID == _T("S67"))
	////Modify end
	//{
	//	return false;
	//}

	CL3RecordSet *pRSheet = new CL3RecordSet();
	CL3RecordSetWrap rsWeight; pRSheet->QueryInterface(IID_IL3RecordSet,rsWeight); rsWeight->Release();
	rsWeight.AddField(_T("DEPID"),VT_BSTR);
	rsWeight.AddField(_T("Status"),VT_I4);
	rsWeight.AddField(_T("Permit_Delete_Flag"),VT_INT);

	rsWeight.AppendRecord();
	rsWeight.SetFieldByName(_T("DEPID"),CL3Variant(csCCMID));
	rsWeight.SetFieldByName(_T("Status"),CL3Variant(L3LONG(fStatus)));
	rsWeight.SetFieldByName(_T("Permit_Delete_Flag"),L3LONG(1));

	L3LONG nPosID = 1;
	CString csTableName = _T("DEP_PLCStatus");
	L3STRING strTableName = csTableName.AllocSysString();
	InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
					    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
						strTableName,(L3RECORDSET)rsWeight);
	L3SysFreeString(strTableName);

	return true;
}

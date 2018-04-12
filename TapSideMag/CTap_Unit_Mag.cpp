// �߼���CTap_Unit_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CTap_Unit_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CTap_Unit_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CTap_Unit_Mag.h"
#include "L3NameParser.h"

#define PROCTIMER_PERIOD 5000

//������װ�ص�ϵͳ��ʱ��������
void CTap_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CTap_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ���ػ���ļӹ�����
/// ARG << lstURIs : �������мӹ��������URI
/// </summary>
BOOL CTap_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	CString strArea;
	strArea.Format(_T("XGMESLogic\\BaseDataMag\\XGProduceArea\\%s"),GetIdentity().ToCString());
	lstURIs.AddHead(strArea);
	return TRUE;
}

/// <summary>
/// �õ�����ǰ����ϻ�������URI
/// </summary>
CString CTap_Unit_Mag::GetInputCache()
{
	CString strID = GetIdentity().ToCString();
	CString strIdx = strID.Mid(strID.GetLength() - 1,1);
	CString strCache; strCache.Format(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S3%sP01"),strIdx);
	return strCache;
}

/// <summary>
/// �õ������̲��ϻ�������URI
/// </summary>
CString CTap_Unit_Mag::GetOutputCache()
{
	// ������Ҫ���ݹ���·��ת�˸�ˮ�������鲻�������ڻ��档
	return _T("");
}

/// <summary>
/// ��������ǰԤ�����ڻ�������ǰ���ã��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << ����TRUE�������ϣ�����FALSE�ж����ϡ�
/// </summary>
BOOL CTap_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// �������Ϻ��������ڻ������Ϻ���ã��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CTap_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// ���ػ������ϼ�¼������URI
/// </summary>
CString CTap_Unit_Mag::GetFeedingLogType()
{
	return _T("");
}


/// <summary>
/// ׼�����ϼ�¼���ݡ��̳�������ش˺������ж�������ݴ���
/// ARG >> rsFeedingLogs : ���ϼ�¼��Ϣ��
/// RET << void
/// </summary>
void CTap_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
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
BOOL CTap_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
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
BOOL CTap_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// ����ǰԤ������ִ�����߲���ǰ���ã��̳�������ش˺�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << ����TRUE�������ߣ�����FALSE�ж����ߡ�
/// </summary>
BOOL CTap_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// ���ߺ���������ִ�����߲�������ã��̳�������ش˺������ж��⴦��
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CTap_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsDelivered( rsMaterialInfo);
}


/// <summary>
/// ���ػ��������¼������URI
/// </summary>
CString CTap_Unit_Mag::GetDeliveryLogType()
{
	return _T("");
}


/// <summary>
/// ׼�����ϼ�¼���ݡ�
/// ARG >> rsDeliveryLog : ���ϼ�¼���ݡ�
/// RET <<void
/// </summary>
void CTap_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// ���ر������ͨѶ�������URI
/// </summary>
CString CTap_Unit_Mag::GetCommunicator()
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
BOOL CTap_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// �ƻ��´��������������λϵͳ���ͼƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsSend : �·���λϵͳ�ļƻ����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CTap_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
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
BOOL CTap_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// �ƻ�ȡ����������������λϵͳ����ȡ���ƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsCancel : �·���λϵͳ�ļƻ�ȡ�����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CTap_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// ����������ߵ��¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CTap_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// ������Ͻ���ӹ�������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CTap_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// ��������뿪�ӹ������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CTap_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// ���������������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CTap_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// �������������ݱ���¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CTap_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}

/// ͨ�üƻ�״̬�޸ĺ���
BOOL CTap_Unit_Mag::ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status)
{
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsPlanStatus; pRS->QueryInterface(IID_IL3RecordSet,rsPlanStatus); pRS->Release();
	rsPlanStatus.AddField(_T("HeatID"),VT_BSTR);
	rsPlanStatus.AddField(_T("UnitType"),VT_I4);
	rsPlanStatus.AddField(_T("TreatNo"),VT_BSTR);
	rsPlanStatus.AddField(_T("UnitStatus"),VT_BSTR);
	rsPlanStatus.AddField(_T("StatusChangeTime"),VT_DATE);
	rsPlanStatus.AppendRecord();
	rsPlanStatus.SetFieldByName(_T("HeatID"),CL3Variant(lpcszHeatID));
	rsPlanStatus.SetFieldByName(_T("UnitType"),CL3Variant(_T("3")));
	rsPlanStatus.SetFieldByName(_T("TreatNo"),CL3Variant(lpcszTreatNo));
	rsPlanStatus.SetFieldByName(_T("UnitStatus"),CL3Variant(Status));
	rsPlanStatus.SetFieldByName(_T("StatusChangeTime"),CL3Variant(COleDateTime::GetCurrentTime()));
	CL3Variant valRet = InvokeObjectMethod(PLAN_OBJ_URI,_T("ModifyPlanExecutionStatus"),(L3RECORDSET)rsPlanStatus);
	return valRet.ToBOOL();
}

/// <Method class="CTap_Unit_Mag" name="StartProcess" type="L3BOOL">
/// ��ʼ���и�ˮ¯����
/// <Param name="rsSteel" type="L3RECORDSET">Ҫ����ĸ�ˮ��¼</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::StartProcess(L3RECORDSET rsSteel)
{
	CL3RecordSetWrap rs = rsSteel;
	if(rs.GetRowCount() != 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// ����������
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ������״̬
	if(Status != CTap_Unit_Mag::TAPWaiting)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_TAPREFUSED);
		return FALSE;
	}
	CString csSteelGradeIndex = rs.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	// ����������
	rs.AddField(MESPROP_MATERIAL_TYPE,VT_BSTR);
	rs.AddField(MESPROP_AMOUNT,VT_R8);
	rs.SetFieldByName(MESPROP_MATERIAL_TYPE,CL3Variant(_T("CSteel_Data")));
	rs.SetFieldByName(MESPROP_AMOUNT,CL3Variant((L3DOUBLE)1));
	if(!FeedMaterials(rs))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// �����������ݼ�¼
	CL3RecordSetWrap rsBaseData;
	if(!CreateClassPropSet(TAP_BASE_DATA_CLASS_URI,rsBaseData))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsBaseData.CopyFrom(rsSteel);
	rsBaseData.MoveFirst();
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rsBaseData.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsBaseData.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
	rsBaseData.SetFieldByName(_T("ProductionDate"),CL3Variant(curTime));
	rsBaseData.SetFieldByName(_T("SteelGrade"),GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("SteelGrade")));//2009-01-11 tangyi
	if(CreateNewObjects(TAP_BASE_DATA_CLASS_URI,rsBaseData) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	AcceptPropSet(rs,TRUE);
	StartTime = curTime;



	// �޸�״̬
	if(!SetPropValue(_T("Status"),CL3Variant((LONG)CTap_Unit_Mag::TAPProcessing)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	StartProcessTime = curTime.Format(_T("%H:%M:%S"));

	// ������ʱ��
	//m_iTimer = SetTimer(GetURI(),PROCTIMER_PERIOD);

	if(nTrans > 0) Commit(nTrans);

		// �޸ļƻ�״̬
	ChangePlanStatus(HeatID,HeatID,TAPPING_PLAN_SIDE_STATUS_BEGIN);

	return TRUE;

}

/// <Method class="CTap_Unit_Mag" name="StopProcess" type="L3BOOL">
/// ������ˮ¯����
/// </Method>
L3BOOL CTap_Unit_Mag::StopProcess()
{
	//CL3RecordSetWrap rs = rsProcData;
	
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// ����������
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ���״̬
	if(Status != CTap_Unit_Mag::TAPProcessing)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_TAPREFUSED);
		return FALSE;
	}

	COleDateTime curTime = COleDateTime::GetCurrentTime();
	BOOL bUseCurTime = FALSE;
	//if(rs.GetFieldIndex(_T("End_Time")) < 0)
		bUseCurTime = TRUE;
	BOOL bUseLoggedStartTime = FALSE;
	//if(rs.GetFieldIndex(_T("Start_Time")) < 0)
		bUseLoggedStartTime = TRUE;
	BOOL bUseCalTime = FALSE;
	//if(rs.GetFieldIndex(_T("BlowAr_Time")) < 0)
		bUseCalTime = TRUE;

	// ���ɹ������ݼ�¼
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_PROCESS_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	//rs.MoveFirst();
	rsLog.AppendRecord();
	//rsLog.CopyCurRowFrom(rs);
	rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
	if(bUseLoggedStartTime)
		rsLog.SetFieldByName(_T("Start_Time"),GetPropValue(_T("StartTime")));
	if(bUseCurTime)
		rsLog.SetFieldByName(_T("End_Time"),CL3Variant(curTime));
	if(bUseCalTime)
		rsLog.SetFieldByName(_T("BlowAr_Time"),GetPropValue(_T("ProcTime")));
	if(CreateNewObjects(TAP_PROCESS_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	


	// �޸�״̬
	if(!SetPropValue(_T("Status"),CL3Variant((LONG)CTap_Unit_Mag::TAPProcessed)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(!bUseCurTime)
		SetPropValue(_T("StopTime"),rsLog.GetFieldByName(_T("End_Time")));

	StartProcessTime =_T("");//2008-12-26


    CalculateOxygenContent(); //2009-03-17
	CalculateTemperature();   //2009-03-17



	// �޸ļƻ�״̬
	ChangePlanStatus(HeatID,HeatID,TAPPING_PLAN_SIDE_STATUS_END);

	//if(m_iTimer != 0)
	//	KillTimer(GetURI(),m_iTimer);
	//m_iTimer = 0;

	if (!Complete()) //������������Զ������¹��� 2009-01-14 
	{
		if(nTrans > 0) 
			Rollback(nTrans);
		return FALSE;
	}

    if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="FeedElements" type="L3BOOL">
/// ���м���ι˿
/// <Param name="rsElem" type="L3RECORDSET">����ι˿����</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::FeedElements(L3RECORDSET rsElem)
{
	CL3RecordSetWrap rs = rsElem;
	if(rs.GetRowCount() < 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	BOOL bUseCurTime = FALSE;
	if(rs.GetFieldIndex(_T("Discharge_Time")) < 0)
		bUseCurTime = TRUE;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_ADDITION_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
		if(bUseCurTime)
			rsLog.SetFieldByName(_T("Discharge_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(TAP_ADDITION_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="SetTemperature" type="L3BOOL">
/// ��������¼�
/// <Param name="rsTemp" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::SetTemperature(L3RECORDSET rsTemp)
{
	CL3RecordSetWrap rs = rsTemp;
	if(rs.GetRowCount() < 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	BOOL bUseCurTime = FALSE;
	if(rs.GetFieldIndex(_T("MeasureTime")) < 0)
		bUseCurTime = TRUE;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_TEMP_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
		if(bUseCurTime)
			rsLog.SetFieldByName(_T("MeasureTime"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(TAP_TEMP_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="SetOxygen" type="BOOL">
/// �������¼�
/// <Param name="rsOxygen" type="L3RECORDSET">��������</Param>
/// </Method>
BOOL CTap_Unit_Mag::SetOxygen(L3RECORDSET rsOxygen)
{
	CL3RecordSetWrap rs = rsOxygen;
	if(rs.GetRowCount() < 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	BOOL bUseCurTime = FALSE;
	if(rs.GetFieldIndex(_T("MeasureTime")) < 0)
		bUseCurTime = TRUE;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_OXYGEN_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
		if(bUseCurTime)
			rsLog.SetFieldByName(_T("MeasureTime"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(TAP_OXYGEN_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="OnTimer" type="L3BOOL">
/// ����ʱ���¼�
/// <Param name="nEventID" type="L3ULONG">��ʱ���¼�ID</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::OnTimer(L3ULONG nEventID)
{
	if(nEventID == m_iTimer)
	{	// ������ʱ��
		ProcTime += PROCTIMER_PERIOD;
	}

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="SetWeight" type="L3BOOL">
/// �����ˮ�������ݡ�
/// <Param name="fWeight" type="L3DOUBLE">��ˮ����</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::SetWeight(L3DOUBLE fWeight)
{
	// ���ɳ��ؼ�¼
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_LADLE_WEIGHT_CLASS_URI,rsLog))
		return FALSE;

	COleDateTime curTime = COleDateTime::GetCurrentTime();

	rsLog.AppendRecord();
	rsLog.SetFieldByName(_T("TAPID"),GetIdentity());
	rsLog.SetFieldByName(_T("Weight"),CL3Variant(fWeight));
	rsLog.SetFieldByName(_T("Log_Time"),CL3Variant(curTime));

	if(HeatID != _T(""))
	{
		rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
		rsLog.SetFieldByName(_T("LadleID"),GetPropValue(_T("LadleID")));
	}
	CreateNewObjects(TAP_LADLE_WEIGHT_CLASS_URI,rsLog);


	CString cstrSteelGradeIndex = GetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("SteelGradeIndex")).ToCString();
    L3DOUBLE SteelWeight = GetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("Weight")).ToDouble();
	
	if ((cstrSteelGradeIndex.GetLength() > 1)&&(SteelWeight < 1) )
	{
		if (cstrSteelGradeIndex.Left(1) == _T("F")) //2009-03-14 �ոּ�ȥ����0.3��;Ʒ�ָּ�ȥ����1��
			fWeight = fWeight - 0.3;
		else
		{
			//2009-07-16��ˮ�����涨������ְ�300Kg/¯��������ϵͳƷ�ְָ�800Kg/¯����������Ʒ�ְָ�1200Kg/¯����(�ֿ�������Ϊ1450kg)��

			if (cstrSteelGradeIndex.Left(1) == _T("P"))
			{
				//Modify begin by llj 2011-04-18 �޸�ת¯ֱ�Ͳ���ֲ��߿�����Ϊ700kg������������Ϊ800kg
				CString csHeatID=GetPropValue(_T("HeatID")).ToCString();
				CString csSql;
				csSql.Format(_T("select CasterID from %s where HeatID='%s'"),PLAN_TAPPING_CLASS_URI,csHeatID);
				CL3RecordSetWrap rsTappingPlan;
				if(Query(csSql,rsTappingPlan)&&rsTappingPlan.GetRowCount()>0)
				{
					CString csCasterID=rsTappingPlan.GetFieldByName(_T("CasterID")).ToCString();
					if(csCasterID==_T("S66"))
						fWeight = fWeight - 0.7;
					else
						fWeight = fWeight - 0.8;
				}
				else
					fWeight = fWeight - 0.8;
				//Modify end
			}
			else
			{
				
				//Modify begin by llj 2011-05-13 ��Ʒ����5#�����Ŀ���1.45 ������������0.8
				//fWeight = fWeight - 1.2;
				CString csHeatID=GetPropValue(_T("HeatID")).ToCString();
				CString csSql;
				csSql.Format(_T("select CasterID from %s where HeatID='%s'"),PLAN_TAPPING_CLASS_URI,csHeatID);
				CL3RecordSetWrap rsTappingPlan;
				if(Query(csSql,rsTappingPlan)&&rsTappingPlan.GetRowCount()>0)
				{
					CString csCasterID=rsTappingPlan.GetFieldByName(_T("CasterID")).ToCString();
					if(csCasterID==_T("S65"))
						fWeight = fWeight - 1.45;
					else
						fWeight = fWeight - 0.8;
				}
				else
					fWeight = fWeight - 0.8;
				//Modify end
			}
		}
		  CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,HeatID);
	    if(!SetObjectPropValue(strProcData,_T("Tapping_Weight"),CL3Variant(fWeight)))
	    {
		  return FALSE;
	     }

	   // �޸ĵ�ǰ��ˮ����
	     if(!SetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("Weight"),CL3Variant(fWeight)))//2009-04-09
	     {
		   return FALSE;
	      }
	}

	//2009-06-09 tangyi 
	//if(fWeight > 50)
	//	fWeight = 48;

	//CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,HeatID);
	//if(!SetObjectPropValue(strProcData,_T("Tapping_Weight"),CL3Variant(fWeight)))
	//{
	//	return FALSE;
	//}

	//// �޸ĵ�ǰ��ˮ����
	//if(!SetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("Weight"),CL3Variant(fWeight)))//2009-04-09
	//{
	//	return FALSE;
	//}

	if (!StopProcess()) //��ˮ�������Ｔ¯������� 2009-01-14
	{
		return FALSE;
	}

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="Complete" type="L3BOOL">
/// ���¯��������ˮת�����¹���
/// </Method>
L3BOOL CTap_Unit_Mag::Complete()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// ����������
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ���״̬
	if(Status != CTap_Unit_Mag::TAPProcessed)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_TAPREFUSED);
		return FALSE;
	}

	// ��ȡ�ø�ˮ�ļƻ����ж���ȥ��
	CString strHeatID = HeatID;
	strHeatID.Trim();
	CString strPlan;
	strPlan.Format(_T("select * from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,(LPCTSTR)GetRealHeatID(strHeatID));
	CL3RecordSetWrap rsPlan;
	if(!Query(strPlan,rsPlan) || rsPlan.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_PLANNOTEXIST);
		return FALSE;
	}
	rsPlan.MoveFirst();
	CString strLFID = rsPlan.GetFieldByName(_T("LFID")).ToCString();
	CString strRHID = rsPlan.GetFieldByName(_T("RHID")).ToCString();
	CString strCCMID = rsPlan.GetFieldByName(_T("CasterID")).ToCString();
	CString strType = rsPlan.GetFieldByName(_T("Refine_Type")).ToCString();
	CString strTargetCache;
	TCHAR cHead = *((LPCTSTR)strType);
	switch(cHead)
	{
	case _T('0'):
		{	// ȥ����
			strTargetCache = strCCMID + _T("P01");
		}
		break;
	case _T('L'):
		{	// ȥLF¯
			strTargetCache = strLFID + _T("P01");
		}
		break;
	case _T('R'):
		{	// ȥRH¯
			strTargetCache = strRHID + _T("P01");
		}
		break;
	default:
		{
			if(nTrans > 0) Rollback(nTrans);
			SetL3LastError(XGMES_ERR_PLANWRONGREFINETYPE);
			return FALSE;
		}
	}
	strTargetCache = CL3NameParser::MergeClassDomainName(XGINTERCACHE_URI,strTargetCache);
	// ��ˮ����
	CString strArea = CL3NameParser::MergeClassDomainName(XGPRODUCEAREA_URI,GetIdentity().ToCString());
	CL3Variant valSteels = InvokeObjectMethod(strArea,_T("GetMaterials"));
	CL3RecordSetWrap rsSteels;
	if(FAILED(valSteels.QueryInterface(IID_IL3RecordSet,rsSteels)) || rsSteels.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	//tangyi20081202
	rsSteels.AddField(_T("Area"),VT_BSTR);
	rsSteels.MoveFirst();
	rsSteels.SetFieldByName(_T("Area"),CL3Variant(strArea));

	CBSTR bstrTarget = strTargetCache;
	rsSteels.MoveFirst();
    /*���ο�ʼ by hyh 2012-05-16  ���ڽ�6#��������MESͳһ����
	//Modify begin by llj 2011-03-27 ����ֱ�Ͳ���ָ�ˮ��¯�����ɾ������
	if(strCCMID==_T("S66"))
	{
		CL3RecordSet rsPosData;
		rsPosData.CopyFrom(rsSteels);
		CL3RecordSetWrap rsPos; rsPosData.QueryInterface(IID_IL3RecordSet,rsPos);
		CL3Variant valRet = InvokeObjectMethod(strArea,_T("RemoveMaterials"),(IL3RecordSet*)rsPos);
		if(!valRet.ToBOOL())
		{	// �Ӽӹ�λ��ת�Ʋ���ʧ��
			if(nTrans>0)
				Rollback(nTrans);
			return FALSE;
		}
	}
	else
	{
	//Modify end
		if(!DeliverMaterialsTo(bstrTarget.GetBuffer(TRUE),rsSteels))
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}
	}
	���ν���*/
	//add by hyh 2012-05-16
	if(!DeliverMaterialsTo(bstrTarget.GetBuffer(TRUE),rsSteels))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	//end

	// �޸�״̬
	if(!SetPropValue(_T("Status"),CL3Variant((LONG)CTap_Unit_Mag::TAPWaiting)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	//2009-04-30 Begin 1-3#ת¯����ˮ��Ϊ0�����ø�ˮ��48��
	CString cstrUnitID = GetIdentity().ToCString();
	if (cstrUnitID != _T("S34"))
	{
		CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,strHeatID);
		L3DOUBLE fSteelWeight = 0;
		fSteelWeight = GetObjectPropValue(strProcData,_T("Tapping_Weight")).ToDouble();
		if (fSteelWeight < 1)
		{
			if(!SetObjectPropValue(strProcData,_T("Tapping_Weight"),(L3DOUBLE)48))
			{
				if(nTrans > 0) Rollback(nTrans);
				return FALSE;
			}

			// �޸ĵ�ǰ��ˮ����
			if(!SetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("Weight"),(L3DOUBLE)48))
			{
				if(nTrans > 0) Rollback(nTrans);
				return FALSE;
			}
		}
	}
	//2009-04-30 End

	if(nTrans > 0) Commit(nTrans);

	//��վ�ɹ�������¯ԭʼ��¼���ô洢���̷�������֮��2009-04-01 tangyi
	//CL3RecordSet *pRSData = new CL3RecordSet();
	//CL3RecordSetWrap rsOrigData; pRSData->QueryInterface(IID_IL3RecordSet,rsOrigData); pRSData->Release();
	//rsOrigData.AddField(_T("UnitID"),VT_BSTR);
	//rsOrigData.AddField(_T("HeatID"),VT_BSTR);

	//rsOrigData.AppendRecord();
	//rsOrigData.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	//rsOrigData.SetFieldByName(_T("UnitID"),GetIdentity());

	//CreateNewObjects(_T("XGMESLogic\\BaseDataMag\\CBase_Unit_Original_Data"),rsOrigData);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="GetInputSteels" type="L3RECORDSET">
/// ����¯��������ˮ��Ϣ
/// </Method>
L3RECORDSET CTap_Unit_Mag::GetInputSteels()
{
	CString strCache = GetInputCache();
	CL3Variant valSteels = InvokeObjectMethod(strCache,_T("GetMaterialDetails"),_T("CSteel_Data"),_T(""));
	if(!valSteels.IsValid())
		return NULL;
	CL3RecordSetWrap rsSteels;
	if(FAILED(valSteels.QueryInterface(IID_IL3RecordSet,rsSteels)))
		return NULL;
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MATERIAL_STEEL_URI,rs))
		return NULL;
	rsSteels.MoveFirst();
	rs.CopyFrom(rsSteels);
	return rs.Detach();
}

/// <Method class="CBOF_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
/// ����ĸ�
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_EXE_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,csHeatID);
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


/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  ��ˮ��¯����
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_TURN_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	CString csHeatID = strHeatID;
	CString csUri = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,csHeatID);
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

/// <Method class="CBOF_Unit_Mag" name="AcceptTapSideWeightData" type="L3BOOL">
/// ����¯��������� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">¯����������</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::AcceptTapSideWeightData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveLast();
	L3DOUBLE fWeight = rs.GetFieldByName(_T("Weight")).ToDouble();
    if (!SetWeight(fWeight))
	{
		return FALSE;
	}
	return TRUE;	
}

/// <Method class="CTap_Unit_Mag" name="AutoStartProcess" type="L3BOOL">
/// ת¯���ֽ������Զ�¯��ʼ���� 2009-01-14
/// </Method>
L3BOOL CTap_Unit_Mag::AutoStartProcess()
{
	CL3RecordSetWrap rs = GetInputSteels();

	if (rs.GetRowCount() != 1)
	{
		return FALSE;
	}

	if (!(StartProcess(rs)))
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  ��ȡ���¯�� 2009-02-28 ����¯��
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3RECORDSET CTap_Unit_Mag::GetPreThreeHeatID()
{
	CString csUnitID = GetIdentity().ToCString();
	CString csBOFID = csUnitID.Mid(2,1);
	CString csTempSQL =_T("select * from (select HeatID from CTap_Base_Data where substr(HeatID,2,1) = '%s'  order by  HeatID desc) where rownum < 4");
	CString csSQL;
	csSQL.Format(csTempSQL,csBOFID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;
	return rs.Detach();	
}

/// <Method class="CTap_Unit_Mag" name="AcceptOxygenData" type="L3BOOL">
/// ����¯�������� 2009-03-16
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CTap_Unit_Mag::AcceptOxygenData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount = rs.GetRowCount();
	if(rsCount < 1)
		return TRUE;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_OXYGEN_DATA_CLASS_URI,rsLog))
	{
		return FALSE;
	}

	rs.MoveFirst();
	for(int i=0;i<rsCount;i++) //2009-03-05 ���Ӷ������ռ�
	{
		CString strBOFID = rs.GetFieldByName(_T("BOFID")).ToCString();  //��ȡ�����

		//��ȡ�����������
		CString strBOFMag = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag"),strBOFID);
		CString strHeatID = GetObjectPropValue(strBOFMag,_T("HeatID")).ToCString();

		COleDateTime curTime = COleDateTime::GetCurrentTime();
		rsLog.AppendRecord();
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		rsLog.SetFieldByName(_T("Oxygen_Content"),rs.GetFieldByName(_T("Oxygen_Content")));
		rsLog.SetFieldByName(_T("Temp"),rs.GetFieldByName(_T("Temp"))); //2009-03-23
		rsLog.SetFieldByName(_T("MeasureTime"),CL3Variant(curTime));

		rs.MoveNext();
	}
	
	if (rsLog.GetRowCount() > 0)
	{
		rsLog.MoveFirst();
		if(CreateNewObjects(TAP_OXYGEN_DATA_CLASS_URI,rsLog) < 1)
		{
			return FALSE;
		}
	}

	return TRUE;	
}

/// <Method class="CTap_Unit_Mag" name="AcceptTempData" type="L3BOOL">
/// ����¯��������� 2009-03-16
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CTap_Unit_Mag::AcceptTempData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount = rs.GetRowCount();
	if(rsCount < 1)
		return TRUE;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_TEMP_DATA_CLASS_URI,rsLog))
	{
		return FALSE;
	}

	rs.MoveFirst();
	for(int i=0;i<rsCount;i++) //2009-03-05 ���Ӷ������ռ�
	{
		CString strBOFID = rs.GetFieldByName(_T("BOFID")).ToCString();  //��ȡ�����

		//��ȡ�����������
		CString strBOFMag = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag"),strBOFID);
		CString strHeatID = GetObjectPropValue(strBOFMag,_T("HeatID")).ToCString();

		COleDateTime curTime = COleDateTime::GetCurrentTime();
		rsLog.AppendRecord();
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		rsLog.SetFieldByName(_T("Temperature"),rs.GetFieldByName(_T("Temperature")));
		rsLog.SetFieldByName(_T("MeasureTime"),CL3Variant(curTime));
		rsLog.SetFieldByName(_T("MeasureType"),rs.GetFieldByName(_T("MeasureType")));

		rs.MoveNext();
	}
	
	if (rsLog.GetRowCount() > 0)
	{
		rsLog.MoveFirst();
		if(CreateNewObjects(TAP_TEMP_DATA_CLASS_URI,rsLog) < 1)
		{
			return FALSE;
		}
	}

	return TRUE;	
}

/// <Method class="CTap_Unit_Mag" name="CalculateTemperature" type="L3BOOL">
/// �����ǰ���¶�
/// </Method>
L3BOOL CTap_Unit_Mag::CalculateTemperature()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString csSQL;
	csSQL.Format(_T("select * from %s where HeatID = '%s' order by MeasureTime asc"),
		TAP_TEMP_DATA_CLASS_URI,curHeatID);
	CL3RecordSetWrap rstemp;
	if (!Query(csSQL, rstemp) || rstemp.IsNull()|| rstemp.GetRowCount() < 1)	
	{
		return FALSE; 
	}

	rstemp.MoveFirst();
	//20090902 liao
	//20090902 liao


	CString strUri = CL3NameParser::MergeClassDomainName(TAP_PROCESS_DATA_CLASS_URI,curHeatID);
	SetObjectPropValue(strUri,_T("Temp_Before_BlowAr"),rstemp.GetFieldByName(_T("Temperature")));
	
	L3LONG rsCount = rstemp.GetRowCount();
	if (rsCount > 1)
	{
		rstemp.MoveLast();
		SetObjectPropValue(strUri,_T("Temp_BlownAr"),rstemp.GetFieldByName(_T("Temperature")));
	}
	else
	{
		SetObjectPropValue(strUri,_T("Temp_BlownAr"),CL3Variant((L3LONG)0));
	}
	
	
	return TRUE;	
}

/// <Method class="CTap_Unit_Mag" name="CalculateOxygenContent" type="L3BOOL">
/// �����ǰ��������
/// </Method>
L3BOOL CTap_Unit_Mag::CalculateOxygenContent()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString csSQL;
	csSQL.Format(_T("select * from %s where HeatID = '%s' order by MeasureTime asc"),
		TAP_OXYGEN_DATA_CLASS_URI,curHeatID);
	CL3RecordSetWrap rstemp;
	if (!Query(csSQL, rstemp) || rstemp.IsNull())	
	{
		return FALSE; 
	}
	L3LONG rsCount = rstemp.GetRowCount();
	if (rsCount < 1)
	{
		return TRUE;
	}

	rstemp.MoveFirst();
	//20090902 liao
	/*csSQL.Format(_T("select * from CTap_Process_Data where heatid = '%s' ",curHeatID));
	CL3RecordSetWrap rsProcessData;
	if (!Query(csSQL, rsProcessData) || rsProcessData.IsNull())	
	{
		return FALSE; 
	}
	if(rsProcessData.GetRowCount() > 0)
	{
		rsProcessData.MoveFirst();*/

		//CString csGUID = rsProcessData.GetFieldByName(_T("GUID")).ToCString();
	CString strUri = CL3NameParser::MergeClassDomainName(TAP_PROCESS_DATA_CLASS_URI,curHeatID);
	SetObjectPropValue(strUri,_T("O2_Before_BlowAr"),rstemp.GetFieldByName(_T("Oxygen_Content")));

	if (rsCount > 1)
	{
		rstemp.MoveLast();
		SetObjectPropValue(strUri,_T("O2_BlownAr"),rstemp.GetFieldByName(_T("Oxygen_Content")));
	}
	else
	{
		SetObjectPropValue(strUri,_T("O2_BlownAr"),CL3Variant((L3LONG)0));
	}
	
	return TRUE;	
	//}
}

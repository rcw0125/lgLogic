// �߼���CCCM_Unit_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CCCM_Unit_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CCCM_Unit_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CCCM_Unit_Mag.h"
#include "L3NameParser.h"

//������װ�ص�ϵͳ��ʱ��������
void CCCM_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CCCM_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

CString CCCM_Unit_Mag::GetPrepareArea()
{
	CString strID = GetIdentity().ToCString();
	CString strPrepare = strID + _T("A01");
	CString strAreaPrepare = CL3NameParser::MergeClassDomainName(CCM_AREA_CLASS_URI,strPrepare);
	return strAreaPrepare;
}

CString CCCM_Unit_Mag::GetCastingArea()
{
	CString strID = GetIdentity().ToCString();
	CString strCasting = strID + _T("A02");
	CString strAreaCasting = CL3NameParser::MergeClassDomainName(CCM_AREA_CLASS_URI,strCasting);
	return strAreaCasting;
}

CString CCCM_Unit_Mag::GetBloomingArea()
{
	CString strID = GetIdentity().ToCString();
	CString strBlooming = strID + _T("A03");
	CString strAreaBlooming = CL3NameParser::MergeClassDomainName(CCM_AREA_CLASS_URI,strBlooming);
	return strAreaBlooming;
}

/// <summary>
/// ���ػ���ļӹ�����
/// ARG << lstURIs : �������мӹ��������URI
/// </summary>
BOOL CCCM_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	lstURIs.AddTail(GetPrepareArea());
	lstURIs.AddTail(GetCastingArea());
	lstURIs.AddTail(GetBloomingArea());

	return TRUE;
}

/// <summary>
/// �õ�����ǰ����ϻ�������URI
/// </summary>
CString CCCM_Unit_Mag::GetInputCache()
{
	CString strID = GetIdentity();
	CString strKey = strID + _T("P01");
	CString strCache = CL3NameParser::MergeClassDomainName(XGINTERCACHE_URI,strKey);
	return strCache;
}

/// <summary>
/// �õ������̲��ϻ�������URI
/// </summary>
CString CCCM_Unit_Mag::GetOutputCache()
{
	return BLOOM_STORE_INCACHE_OBJ_URI;
}

/// <summary>
/// ��������ǰԤ�����ڻ�������ǰ���ã��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << ����TRUE�������ϣ�����FALSE�ж����ϡ�
/// </summary>
BOOL CCCM_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// �������Ϻ��������ڻ������Ϻ���ã��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CCCM_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// ���ػ������ϼ�¼������URI
/// </summary>
CString CCCM_Unit_Mag::GetFeedingLogType()
{
	return _T("");
}


/// <summary>
/// ׼�����ϼ�¼���ݡ��̳�������ش˺������ж�������ݴ���
/// ARG >> rsFeedingLogs : ���ϼ�¼��Ϣ��
/// RET << void
/// </summary>
void CCCM_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
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
BOOL CCCM_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
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
BOOL CCCM_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// ����ǰԤ������ִ�����߲���ǰ���ã��̳�������ش˺�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << ����TRUE�������ߣ�����FALSE�ж����ߡ�
/// </summary>
BOOL CCCM_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// ���ߺ���������ִ�����߲�������ã��̳�������ش˺������ж��⴦��
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CCCM_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	CL3RecordSetWrap rs = rsMaterialInfo;
	rs.MoveFirst();
	CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
	CString csUir = BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID;
	if(!SetObjectPropValue(csUir,_T("Status"),CL3Variant(BLOOM_STATUS_CUT)))
		return false;
	if(!SetObjectPropValue(csUir,_T("Position"),CL3Variant(UNIT_ID_BLOOM_PCACHE)))
		return false;
	return true;
}


/// <summary>
/// ���ػ��������¼������URI
/// </summary>
CString CCCM_Unit_Mag::GetDeliveryLogType()
{
	return _T("");
}


/// <summary>
/// ׼�����ϼ�¼���ݡ�
/// ARG >> rsDeliveryLog : ���ϼ�¼���ݡ�
/// RET <<void
/// </summary>
void CCCM_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// ���ر������ͨѶ�������URI
/// </summary>
CString CCCM_Unit_Mag::GetCommunicator()
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
BOOL CCCM_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// �ƻ��´��������������λϵͳ���ͼƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsSend : �·���λϵͳ�ļƻ����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CCCM_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
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
BOOL CCCM_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// �ƻ�ȡ����������������λϵͳ����ȡ���ƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsCancel : �·���λϵͳ�ļƻ�ȡ�����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CCCM_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// ����������ߵ��¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CCCM_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// ������Ͻ���ӹ�������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CCCM_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// ��������뿪�ӹ������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CCCM_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// ���������������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CCCM_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// �������������ݱ���¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CCCM_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}

/// ������һ�����
CString CCCM_Unit_Mag::CalculateNextTreatNo(LPCTSTR lpcszTreatNo)
{
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strTreatNo(lpcszTreatNo); strTreatNo.Trim();
	CString strNextID; 	
	CString strID = GetIdentity().ToCString();
	strID = strID.Mid(2,1);
	if(strTreatNo.IsEmpty())
	{
		LONG nYear = curTime.GetYear();
		nYear = nYear - (nYear / 100) * 100;
		strNextID.Format(_T("%s%02d%05d"),(LPCTSTR)strID,nYear,(INT)1);
	}
	else
	{
		CString strIDYear = strTreatNo.Mid(1,2);
		CString strIDSeq = strTreatNo.Mid(3,strTreatNo.GetLength()-3);
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
		strNextID.Format(_T("%s%02d%05d"),strID,nYear,nSeq);
	}
	return strNextID;
}

/// ������һ���κ�
CString CCCM_Unit_Mag::CalculateNextCastingNo(LPCTSTR lpcszCastingNo)
{
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strTreatNo(lpcszCastingNo); strTreatNo.Trim();
	CString strNextID; 	
	CString strID = GetIdentity().ToCString();
	strID = strID.Mid(2,1);
	if(strTreatNo.IsEmpty())
	{
		LONG nYear = curTime.GetYear();
		nYear = nYear - (nYear / 100) * 100;
		strNextID.Format(_T("J%s%02d%04d"),(LPCTSTR)strID,nYear,(INT)1);
	}
	else
	{
		CString strIDYear = strTreatNo.Mid(2,2);
		CString strIDSeq = strTreatNo.Mid(4,strTreatNo.GetLength()-4);
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
		strNextID.Format(_T("J%s%02d%04d"),strID,nYear,nSeq);
	}
	return strNextID;
}

/// ������һ���κ�
CString CCCM_Unit_Mag::CalculateNextTundishNo(LPCTSTR lpcszTundishNo)
{
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strTreatNo(lpcszTundishNo); strTreatNo.Trim();
	CString strNextID; 	
	CString strID = GetIdentity().ToCString();
	strID = strID.Mid(2,1);
	if(strTreatNo.IsEmpty())
	{
		LONG nYear = curTime.GetYear();
		nYear = nYear - (nYear / 100) * 100;
		strNextID.Format(_T("B%s%02d%04d"),(LPCTSTR)strID,nYear,(INT)1);
	}
	else
	{
		CString strIDYear = strTreatNo.Mid(2,2);
		CString strIDSeq = strTreatNo.Mid(4,strTreatNo.GetLength()-4);
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
		strNextID.Format(_T("B%s%02d%04d"),strID,nYear,nSeq);
	}
	return strNextID;
}

/// ͨ�ù���״̬�޸ĺ���
BOOL CCCM_Unit_Mag::ChangeStatus(LONG nStatus)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// �޸�ת¯״̬
	if(!SetPropValue(_T("Status"),CL3Variant(nStatus)))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��¼�¼���־
	CL3RecordSetWrap rsStatus;
	if(!CreateClassPropSet(CCM_PROCESS_STATUS_CLASS_URI,rsStatus))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsStatus.AppendRecord();
	rsStatus.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
	rsStatus.SetFieldByName(_T("TreatNo"),CL3Variant(TreatNo));
	rsStatus.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
	rsStatus.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsStatus.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	if(CreateNewObjects(CCM_PROCESS_STATUS_CLASS_URI,rsStatus) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}

/// ͨ�üƻ�״̬�޸ĺ���
BOOL CCCM_Unit_Mag::ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status)
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
	rsPlanStatus.SetFieldByName(_T("UnitType"),CL3Variant(_T("6")));//��������
	rsPlanStatus.SetFieldByName(_T("TreatNo"),CL3Variant(lpcszTreatNo));
	rsPlanStatus.SetFieldByName(_T("UnitStatus"),CL3Variant(Status));
	rsPlanStatus.SetFieldByName(_T("StatusChangeTime"),CL3Variant(COleDateTime::GetCurrentTime()));
	CL3Variant valRet = InvokeObjectMethod(PLAN_OBJ_URI,_T("ModifyPlanExecutionStatus"),(L3RECORDSET)rsPlanStatus);
	return valRet.ToBOOL();
}

/// <Method class="CCCM_Unit_Mag" name="GetInputSteels" type="L3RECORDSET">
/// ������ڸ�ˮ��Ϣ.
/// </Method>
L3RECORDSET CCCM_Unit_Mag::GetInputSteels()
{
	CString strCache = GetInputCache();
	CL3Variant val = InvokeObjectMethod(strCache,_T("GetMaterialDetails"),_T("CSteel_Data"),_T(""));
	CL3RecordSetWrap rs;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rs)))
		return NULL;
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(MATERIAL_STEEL_URI,rsSteel))
		return NULL;
	rs.MoveFirst();
	rsSteel.CopyFrom(rs);
	return rsSteel.Detach();
}

/// <Method class="CCCM_Unit_Mag" name="DesignateSteel" type="L3BOOL">
/// ָ���¸����ߵĸ�ˮ.
/// <Param name="rsSteel" type="L3RECORDSET">Ҫָ�����ߵĸ�ˮ��¼</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::DesignateSteel(L3RECORDSET rsSteel)
{
	CL3RecordSetWrap rs = rsSteel;
	if(rs.GetRowCount() < 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	if(rs.GetFieldIndex(_T("HeatID")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	rs.MoveFirst();
	CString strHeatID = rs.GetFieldByName(_T("HeatID")).ToCString();
	strHeatID.Trim();
	if(strHeatID.IsEmpty())
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	NextHeatID = strHeatID;
	//2008-12-28 tangyi����ְ���
	NextLadleID = rs.GetFieldByName(_T("LadleID")).ToCString();

	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="SteelArrived" type="L3BOOL">
/// ��������ˮ�����¼�����ָ���ĸ�ˮ���ߡ�
/// </Method>
L3BOOL CCCM_Unit_Mag::SteelArrived()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	//���ƶ�uri���뵱ǰ����
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ��ȡ��ˮ��
	CString strHeatID = NextHeatID;
	strHeatID.Trim();
	if(strHeatID.IsEmpty())
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_CCM_NEEDSTEEL);
		return FALSE;
	}
	
	CString strAreaURI = GetPrepareArea(); // ���ߵ���ת̨��λ
	// ����ת̨���Ƿ���ڴ��
	CL3Variant val = InvokeObjectMethod(strAreaURI,_T("GetMaterialCount"),_T("CSteel_Data"));
	if(!val.IsValid())
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	if(val.ToLong() > 0)//2008-12-29 ȷ��ֻ��һ¯��ˮtangyi
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_CCM_TOOMUCHSTEELS);
		return FALSE;
	}

	// �ְ�����
	CString strInputCache = GetInputCache();
	val = InvokeObjectMethod(strInputCache,_T("FindMaterial"),_T("CSteel_Data"),(LPCTSTR)strHeatID);
	CL3RecordSetWrap rsSteel;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsSteel)) || rsSteel.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_RH_NEEDSTEEL);
		return FALSE;
	}
	rsSteel.AddField(_T("TargetArea"),VT_BSTR); // ָ������Ŀ�깤λURI
	rsSteel.MoveFirst();
	rsSteel.SetFieldByName(_T("TargetArea"),CL3Variant(strAreaURI));
	L3FLOAT fSteelWeight = rsSteel.GetFieldByName(_T("Weight")).ToFloat();//2009-03-26 �����´�PLC��ˮ��
	if(!FeedMaterials(rsSteel))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}


	// �޸�����״̬2008-12-23
	if(!SetPropValue(_T("Status"),CL3Variant(L3LONG(CCCM_Unit_Mag::CCMArrivle))))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��¼�¼���־
	CL3RecordSetWrap rsStatus;
	if(!CreateClassPropSet(CCM_PROCESS_STATUS_CLASS_URI,rsStatus))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsStatus.AppendRecord();
	rsStatus.SetFieldByName(_T("TreatNo"),CL3Variant(_T("")));
	rsStatus.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	rsStatus.SetFieldByName(_T("Status"),CL3Variant(L3LONG(CCCM_Unit_Mag::CCMArrivle)));
	rsStatus.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsStatus.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));//2008-12-30 tangyi
	if(CreateNewObjects(CCM_PROCESS_STATUS_CLASS_URI,rsStatus) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	ArriveTime = (COleDateTime::GetCurrentTime()).Format(_T("%H:%M:%S"));

	//NextHeatID = _T("");2008-12-28��ʾ����¯������

	if(nTrans > 0) Commit(nTrans);

	// �޸ļƻ�״̬
	ChangePlanStatus(strHeatID,_T(""),TAPPING_PLAN_CCM_STATUS_ARR);

	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="StartCasting" type="L3BOOL">
/// ��ʼ�����ע
/// </Method>
L3BOOL CCCM_Unit_Mag::StartCasting()
{
	CastNum1ST=0;
	CastNum2ST=0;
	CastNum3ST=0;
	CastNum4ST=0;

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	// ��ȡ��ǰ���κͰ���
	CString strCastingData = CL3NameParser::MergeClassDomainName(CCM_CASTING_DATA_CLASS_URI,CastingNo);
	CString strTundishData = CL3NameParser::MergeClassDomainName(CCM_TUNDISH_DATA_CLASS_URI,TundishNo);
	PutObjectIntoTrans(strCastingData);
	PutObjectIntoTrans(strTundishData);

	// ��鴦���
	TreatNo.Trim();
	if(TreatNo.IsEmpty())
		TreatNo = CalculateNextTreatNo(NULL);

	// ��齽ע��λ���Ƿ��Ѿ����ڴ��
	CString strCastingArea = GetCastingArea();
	CL3Variant val = InvokeObjectMethod(strCastingArea,_T("GetMaterialCount"),_T("CSteel_Data"));
	if(!val.IsValid())
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	L3LONG nLadleNum = val.ToLong();
	if(nLadleNum > 0)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_CCM_TOOMUCHSTEELS);
		return FALSE;
	}

	// ����ת̨���Ƿ���ڴ��
	CString strPrepareArea = GetPrepareArea();
	val = InvokeObjectMethod(strPrepareArea,_T("GetMaterialDetails"),_T("CSteel_Data"),_T(""));
	CL3RecordSetWrap rsSteel;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsSteel)) || rsSteel.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_CCM_NEEDSTEEL);
		return FALSE;
	}
	while(rsSteel.GetRowCount() > 1)
	{	// Make sure there is only one steel
		rsSteel.MoveLast();
		rsSteel.DeleteRecord();
	}
	rsSteel.MoveFirst();

	LadleID = rsSteel.GetFieldByName(_T("LadleID")).ToCString();//2008-12-28 tangyi
	
	CString strHeatID = rsSteel.GetFieldByName(_T("HeatID")).ToCString();
	//L3FLOAT fSteelWeight = rsSteel.GetFieldByName(_T("Weight")).ToFloat();
	L3FLOAT fSteelWeight = GetObjectPropValue(BOF_PROCESS_DATA_CLASS_URI + _T("\\") + strHeatID,_T("Tapping_Weight")).ToFloat();//2009-04-24
    SteelWeight = fSteelWeight;

	// ������ӻ�ת̨�˵���ע��λ
	CBSTR bstrCastingArea(strCastingArea),bstrPrepareArea(strPrepareArea);
	if(!TransferMaterials(bstrPrepareArea.GetBuffer(TRUE),bstrCastingArea.GetBuffer(TRUE),rsSteel))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ��ѯ�ƻ�
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

	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ���ɻ������ݼ�¼
	CL3RecordSetWrap rsBaseData;
	if(!CreateClassPropSet(CCM_BASE_DATA_CLASS_URI,rsBaseData))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsBaseData.AppendRecord();
	rsBaseData.CopyCurRowFrom(rsSteel);
	rsBaseData.CopyCurRowFrom(rsPlan);
	//rsBaseData.SetFieldByName(_T("CastingNo"),GetPropValue(_T("CastingNo"))); 2009-02-13
	rsBaseData.SetFieldByName(_T("CCMID"),GetIdentity());
	rsBaseData.SetFieldByName(_T("TreatNo"),GetPropValue(_T("TreatNo")));
	rsBaseData.SetFieldByName(_T("HeatConfirm"),CL3Variant((LONG)0));
	rsBaseData.SetFieldByName(_T("ProductionDate"),CL3Variant(curTime));
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rsBaseData.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsBaseData.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
	//CString csObj = GetName() + rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();
	//CString csUri = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\CCMMag\\CCCM_Duty"),csObj);
	//rsBaseData.SetFieldByName(_T("HeadFurnace"),GetObjectPropValue(csUri,_T("HeadFurnace")));
	//rsBaseData.SetFieldByName(_T("Ladle_Operator"),GetObjectPropValue(csUri,_T("Ladle_Officer")));
	//rsBaseData.SetFieldByName(_T("Cut_Operator"),GetObjectPropValue(csUri,_T("Bloom_Officer")));
	//rsBaseData.SetFieldByName(_T("Control_Operator"),GetObjectPropValue(csUri,_T("Control_Operator")));// 2009-02-13
	//rsBaseData.SetFieldByName(_T("Tundish_1ST_Officer"),GetObjectPropValue(csUri,_T("Tundish_1ST_Officer")));
	//rsBaseData.SetFieldByName(_T("Tundish_2ST_Officer"),GetObjectPropValue(csUri,_T("Tundish_2ST_Officer")));
	//rsBaseData.SetFieldByName(_T("Tundish_3ST_Officer"),GetObjectPropValue(csUri,_T("Tundish_3ST_Officer")));
	//rsBaseData.SetFieldByName(_T("Tundish_4ST_Officer"),GetObjectPropValue(csUri,_T("Tundish_4ST_Officer")));
	rsBaseData.SetFieldByName(_T("Locked"),CL3Variant((LONG)0));
	rsBaseData.SetFieldByName(_T("LadleNo"),rsSteel.GetFieldByName(_T("LadleID")));
	CString csSteelGradeIndex = rsPlan.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	rsBaseData.SetFieldByName(_T("SteelGrade"),GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("SteelGrade")));//2009-01-11 tangyi
	CString csPreSteelGradeIndex = rsPlan.GetFieldByName(_T("Pre_SteelGradeIndex")).ToCString();
	rsBaseData.SetFieldByName(_T("Plan_SteelGrade"),GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + csPreSteelGradeIndex,_T("SteelGrade")));//2009-02-13 tangyi

	
	if(CreateNewObjects(CCM_BASE_DATA_CLASS_URI,rsBaseData) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ���½��κͰ��ζ�Ӧ��¯����Ϣ
	LONG nCastingHeatCnt = 1+GetObjectPropValue(strCastingData,_T("HeatCount")).ToLong();
	LONG nTundishHeatCnt = 1+GetObjectPropValue(strTundishData,_T("HeatCount")).ToLong();
	SetObjectPropValue(strCastingData,_T("HeatCount"),CL3Variant(nCastingHeatCnt));
	SetObjectPropValue(strTundishData,_T("HeatCount"),CL3Variant(nTundishHeatCnt));
	if(GetObjectPropValue(strCastingData,_T("First_HeatID")).ToCString() == _T(""))
		SetObjectPropValue(strCastingData,_T("First_HeatID"),CL3Variant(strHeatID));
	if(GetObjectPropValue(strTundishData,_T("First_HeatID")).ToCString() == _T(""))
		SetObjectPropValue(strTundishData,_T("First_HeatID"),CL3Variant(strHeatID));
	SetObjectPropValue(strCastingData,_T("Last_HeatID"),CL3Variant(strHeatID));
	SetObjectPropValue(strTundishData,_T("Last_HeatID"),CL3Variant(strHeatID));

	// ����¯��ʵ����¼
	CL3RecordSetWrap rsProcData;
	if(!CreateClassPropSet(CCM_PROCESS_DATA_CLASS_URI,rsProcData))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsProcData.AppendRecord();
	rsProcData.CopyCurRowFrom(rsSteel);
	rsProcData.CopyCurRowFrom(rsPlan);
	rsProcData.SetFieldByName(_T("CastingNo"),GetPropValue(_T("CastingNo")));
	rsProcData.SetFieldByName(_T("CCMID"),GetIdentity());
	rsProcData.SetFieldByName(_T("TreatNo"),GetPropValue(_T("TreatNo")));
	rsProcData.SetFieldByName(_T("TundishNo"),GetPropValue(_T("TundishNo")));
	rsProcData.SetFieldByName(_T("Casting_HeatNum"),CL3Variant(nCastingHeatCnt));
	rsProcData.SetFieldByName(_T("Tundish_HeatNum"),CL3Variant(nTundishHeatCnt));
	rsProcData.SetFieldByName(_T("CastingStartTime"),CL3Variant(curTime));
	rsProcData.SetFieldByName(_T("PlugBar_Control"),CL3Variant(_T("�Զ�")));
	//2009-03-25 begin
	CString cstrTundishNo = GetPropValue(_T("TundishNo")).ToCString();
	CString cstrTundishUri = CCM_TUNDISH_DATA_CLASS_URI + _T("\\") + cstrTundishNo;
	rsProcData.SetFieldByName(_T("TundishCar_Type"),GetObjectPropValue(cstrTundishUri,_T("Tundish_CarID")));
    //2009-03-25 end
	if(CreateNewObjects(CCM_PROCESS_DATA_CLASS_URI,rsProcData) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// �������¯������2006-12-26 tangyi
	CL3RecordSetWrap rsLadelData;
	if(!CreateClassPropSet(CCM_HEAT_LADLE_CLASS_URI,rsLadelData))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsLadelData.AppendRecord();
	rsLadelData.CopyCurRowFrom(rsSteel);
	rsLadelData.SetFieldByName(_T("TreatNo"),GetPropValue(_T("TreatNo")));
	//add by hyh 2012-08-01 ����տ���ʱ�̵��а��������ݵĲɼ�
	//COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime(); 
  //  COleDateTimeSpan span = COleDateTime::GetCurrentTime()-dtCurrentTime;
   // L3LONG fTotalTime = (LONG)span.GetTotalSeconds();
	//while (fTotalTime= 3)
   //{
	rsLadelData.SetFieldByName(_T("CastingTundishWeight"),GetPropValue(_T("TundishWeight")));
   //}
	
	//end
	rsLadelData.SetFieldByName(_T("CCMID"),GetIdentity());
	rsLadelData.SetFieldByName(_T("Casting_Start_Time"),CL3Variant(curTime));
	rsLadelData.SetFieldByName(_T("Protection"),L3LONG(1));//2009-03-02
	rsLadelData.SetFieldByName(_T("AutoFlow"),L3LONG(1));//2009-03-02
	
	CString csLadleID  = rsSteel.GetFieldByName(_T("LadleID")).ToCString();
	CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
	rsLadelData.SetFieldByName(_T("LadleType"),GetObjectPropValue(csLadleUri,_T("Ladle_Grade")));
	//��ȡ�ϻ��¶�2009-01-14
	CString csRefineType = rsPlan.GetFieldByName(_T("Refine_Type")).ToCString();
	CString strUnitType = _T("");
	L3LONG iTemperature = 0;
	if(csRefineType == _T("0"))
	{
		strUnitType = _T("S2");
		iTemperature = (GetObjectPropValue(TAP_PROCESS_DATA_CLASS_URI + _T("\\") + strHeatID,_T("Temp_BlownAr"))).ToLong();
	}
	else
	{
		CString csSQL;
		if (csRefineType == _T("L"))
		{	
			csSQL.Format(_T("select Departure_Temp from CLF_Process_Data where HeatID = '%s' order by Start_Time desc"),strHeatID);
		    strUnitType = _T("S4");
		}
		else
		{
			csSQL.Format(_T("select Departure_Temp from CRH_Process_Data where HeatID = '%s' order by Start_Time desc"),strHeatID);
		    strUnitType = _T("S5");
		}
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs))
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}
		int itemp = rs.GetRowCount();
		if (itemp > 0)
		{
			rs.MoveFirst();
			iTemperature = (rs.GetFieldByIndex(0)).ToLong();
		}
	}
	rsLadelData.SetFieldByName(_T("Temp"),CL3Variant((LONG)iTemperature));
	//�ж��ϻ��¶��Ƿ�ϸ� 2009-02-28
	if ((strUnitType.GetLength() > 1) && (iTemperature > 0))
	{
		CString csSteelGradeIndex = rsSteel.GetFieldByName(_T("SteelGradeIndex")).ToCString();//2009-04-13
		L3SHORT iTempUpTo = ArrivalTemperatureJudge(csSteelGradeIndex,strUnitType,iTemperature,nCastingHeatCnt);
    	rsLadelData.SetFieldByName(_T("TempUpTo"),CL3Variant((L3SHORT)iTempUpTo));
	}
	
	CString csSQL;
	csSQL.Format(_T("select Change_Time from CCCM_Process_Status where Status = 1 and HeatID ='%s'"),strHeatID);
	CL3RecordSetWrap rsArrivleTime;
	if(!Query(csSQL,rsArrivleTime))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsArrivleTime.MoveFirst();
	rsLadelData.SetFieldByName(_T("Arrival_Time"),rsArrivleTime.GetFieldByIndex(0));
	//�����ѹ��ʱ��2009-02-13 tangyi
	if (nTundishHeatCnt == 1) //2009-03-16 �а���һ¯��ѹ��ʱ��Ϊ0
	{
		//Modify begion by llj 2011-03-30 ���а���һ¯��ѹ��ʱ��Ϊ��¯����ʱ��-��¯�а�����ʱ��
		//����ԭ���
		//rsLadelData.SetFieldByName(_T("HoldTime"),(L3LONG)(0));
		L3DATETIME dArrival = rsArrivleTime.GetFieldByIndex(0).ToDateTime();
		//L3DATETIME curTime = COleDateTime::GetCurrentTime();
		COleDateTimeSpan span = (L3DATETIME)COleDateTime::GetCurrentTime() - dArrival;
		L3LONG nTotalTime = (LONG)span.GetTotalSeconds();
		rsLadelData.SetFieldByName(_T("HoldTime"),(L3LONG)nTotalTime);
		//Modify end
	}
	else
	{
		L3DATETIME dStopCasting = CalculateHoldTime(GetPropValue(_T("TreatNo")).ToCString());
		L3DATETIME dArrival = rsArrivleTime.GetFieldByIndex(0).ToDateTime();
		COleDateTimeSpan span = dStopCasting - dArrival;//2009-03-16 ��ѹ��ʱ���Ϊͣ��-����ʱ��
		L3LONG nTotalTime = (LONG)span.GetTotalSeconds();
		rsLadelData.SetFieldByName(_T("HoldTime"),(L3LONG)(nTotalTime));
	}

	if(CreateNewObjects(CCM_HEAT_LADLE_CLASS_URI,rsLadelData) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ��ѯ��Ӧ���ּƻ�����
	if(rsPlan.GetRowCount() > 0)
	{
		// ����¯��������ʼ�ȼ�
		rsPlan.MoveFirst();
		InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQuality_Mag\\Quality_Mag"),_T("CreateHeatGradeQAData"),(LPCTSTR)GetName(),(L3RECORDSET)rsPlan);
	}

	// ���µ�ǰ��������
	HeatID = strHeatID;
	SteelGradeIndex = rsSteel.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	RemainedWeight = rsSteel.GetFieldByName(_T("Weight")).ToDouble();

	//����Ĭ�ϵ���һ¯ֵ������ʵ����Ϣ2009-02-28tangyi
	GenProtectSlagInfor(TreatNo);

	//���Ӱ���2008-12-25
	CString csTundishNo = GetPropValue(_T("TundishNo"));
	CString csTundishUri= CCM_TUNDISH_DATA_CLASS_URI +_T("\\") + csTundishNo;
	CString csTundishID = GetObjectPropValue(csTundishUri,_T("TundishID")).ToCString();
	CString csTundishBaseUri = CTUNDISH_BASE_URI + _T("\\") + csTundishID;
	L3LONG  nAge = GetObjectPropValue(csTundishBaseUri,_T("Tundish_Age")).ToLong();
	nAge++;
	SetObjectPropValue(csTundishBaseUri,_T("Tundish_Age"),CL3Variant(L3LONG(nAge)));
	// �޸�����״̬2008-12-23
	if(!ChangeStatus(CCCM_Unit_Mag::CCMCasting))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	StartCastingTime = (COleDateTime::GetCurrentTime()).Format(_T("%H:%M:%S"));
	//2008-12-28 tangyi
	NextHeatID = _T("");
	NextLadleID = _T("");

	CastTo15Minute = 0; //2009-02-28

	if(nTrans > 0) Commit(nTrans);

	// �޸ļƻ�״̬
	ChangePlanStatus(strHeatID,TreatNo,TAPPING_PLAN_CCM_STATUS_BEGIN);
	//2009-05-27 �����ƻ�ʱ��
	InvokeObjectMethod(PLAN_OBJ_URI,_T("TappingPlanChangeTimeTable"),L3RECORDSET(rsPlan));

	SendSteelWeightToPLC(fSteelWeight);//2009-03-26 �����´�PLC��ˮ��
///
	/*CString csTreatNo =GetPropValue(_T("TreatNo")).ToCString();
	CString csHeatLadleUri = CCM_HEAT_LADLE_CLASS_URI + _T("\\") + csTreatNo;
	
    COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime(); 
    COleDateTimeSpan span = COleDateTime::GetCurrentTime()-dtCurrentTime;
    L3LONG fTotalTime = (LONG)span.GetTotalSeconds();
	while (fTotalTime= 3)
   {
	SetObjectPropValue(csHeatLadleUri,_T("CastingTundishWeight"),GetPropValue(_T("TundishWeight")));
   }*/
	/////
	return TRUE;
}


/// <Method class="CCCM_Unit_Mag" name="CompletCasting" type="L3BOOL">
/// ��ɴ����ע
/// </Method>
L3BOOL CCCM_Unit_Mag::CompletCasting()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ��齽ע��λ���Ƿ��Ѿ����ڴ��
	CString strCastingArea = GetCastingArea();
	CL3Variant val = InvokeObjectMethod(strCastingArea,_T("GetMaterialDetails"),_T("CSteel_Data"),_T(""));
	CL3RecordSetWrap rsSteel;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsSteel)) || rsSteel.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_CCM_NEEDSTEEL);
		return FALSE;
	}
	while(rsSteel.GetRowCount() > 1)
	{	// Make sure there is only one steel
		rsSteel.MoveLast();
		rsSteel.DeleteRecord();
	}
	rsSteel.MoveFirst();
	CString strHeatID = rsSteel.GetFieldByName(_T("HeatID")).ToCString();
	CString strLadleID = rsSteel.GetFieldByName(_T("LadleID")).ToCString();

	// ���ְ�״̬�趨Ϊ�ȱ�
	CString strLadleURI = CL3NameParser::MergeClassDomainName(CLADLE_BASE_URI,strLadleID);
	SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CLADLE_STATUS_HOT));

	// ������ӽ�עλ�ƶ�������λ��
	CString strBloomingArea = GetBloomingArea();
	CBSTR bstrCastingArea(strCastingArea),bstrBloomingArea(strBloomingArea);
	if(!TransferMaterials(bstrCastingArea.GetBuffer(TRUE),bstrBloomingArea.GetBuffer(TRUE),rsSteel))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	CString strCurTreatNo = TreatNo;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ����ʵ������
	CString strProcData = CL3NameParser::MergeClassDomainName(CCM_PROCESS_DATA_CLASS_URI,strCurTreatNo);
	SetObjectPropValue(strProcData,_T("CastingStopTime"),CL3Variant(curTime));
	
	//�������¯������
	CString strLadelData = CL3NameParser::MergeClassDomainName(CCM_HEAT_LADLE_CLASS_URI,strCurTreatNo);
	SetObjectPropValue(strLadelData,_T("Casting_Stop_Time"),CL3Variant(curTime));
    //COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime(); 
   // COleDateTimeSpan span = COleDateTime::GetCurrentTime()-dtCurrentTime;
   // L3LONG fTotalTime = (LONG)span.GetTotalSeconds();
	//while (fTotalTime= 3)
  // {
	SetObjectPropValue(strLadelData,_T("RemainWeight"),CL3Variant(RemainedWeight)); //2009-02-28
 //  }
	
	// �޸�����״̬2008-12-23
	if(!ChangeStatus(CCCM_Unit_Mag::CCMCasted))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// �޸�����״̬2008-12-23
	if(!ChangeStatus(CCCM_Unit_Mag::CCMWaiting))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
    //����¯��ͨ����2008-02-28
	CalculateStrandCaseWeight();
	CastTo15Minute = 0; //2009-03-05

	// �������鵱ǰ����
	cstrStopCastingHeatID = HeatID;//2009-04-18
	PrevHeatID = HeatID;//2009-04-30
	HeatID = _T("");
	SteelGrade = _T("");
	SteelGradeIndex = _T("");
	StartCastingTime =_T(""); //2008-12-26 
	ArriveTime = _T("");//2008-12-26 
	RemainedWeight = 0.0;
	
	// ������һ�����
	TreatNo = CalculateNextTreatNo(strCurTreatNo);


	if(nTrans > 0) Commit(nTrans);

	// �޸ļƻ�״̬
	ChangePlanStatus(strHeatID,strCurTreatNo,TAPPING_PLAN_CCM_STATUS_END);

	//�ı�����ֵ��֪ͨ����˦��
	CL3Variant varEvent = GetPropValue(_T("CastingEndEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("CastingEndEvent"),nEvent);

	//�ı�����ֵ��֪ͨͨѶ��NC�������ƻ�
	CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
	varEvent = GetObjectPropValue(csBaseUri,_T("NC_Plan_Event"));
	nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csBaseUri,_T("NC_Plan_Event"),nEvent);

   
	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="ChangeCastingNo" type="L3BOOL">
/// ��������
/// </Method>
L3BOOL CCCM_Unit_Mag::ChangeCastingNo()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ȡ�õ�ǰ����
	CString strCurNo = CastingNo; strCurNo.Trim();
	CString strCurCasting = strCurNo.IsEmpty() ? _T("") : CL3NameParser::MergeClassDomainName(CCM_CASTING_DATA_CLASS_URI,strCurNo);
	if(!strCurCasting.IsEmpty())
	{
		//if(!PutObjectIntoTrans(strCurCasting))
		//{
		//	if(nTrans > 0) Rollback(nTrans);
		//	return FALSE;
		//}

		// ������ǰ����
		SetObjectPropValue(strCurCasting,_T("Casting_Stop_Time"),CL3Variant(curTime));
		CastingNo = _T("");
	}

	// ��ʼ�½���
	CString strNewNo = CalculateNextCastingNo(strCurNo);
	CL3RecordSetWrap rsCasting;
	if(!CreateClassPropSet(CCM_CASTING_DATA_CLASS_URI,rsCasting))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsCasting.AppendRecord();
	rsCasting.SetFieldByName(_T("CastingNo"),CL3Variant(strNewNo));
	rsCasting.SetFieldByName(_T("CCMID"),GetIdentity());
	rsCasting.SetFieldByName(_T("Casting_Start_Time"),CL3Variant(curTime));
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rsCasting.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsCasting.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
	rsCasting.SetFieldByName(_T("First_HeatID"),CL3Variant(_T("")));
	rsCasting.SetFieldByName(_T("Last_HeatID"),CL3Variant(_T("")));
	rsCasting.SetFieldByName(_T("HeatCount"),CL3Variant((LONG)0));
	if(CreateNewObjects(CCM_CASTING_DATA_CLASS_URI,rsCasting) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ���»��鵱ǰ����
	if(!SetPropValue(_T("CastingNo"),CL3Variant(strNewNo)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
    //2009-03-16 ��������ͬʱ�������� Begin
	if (!ChangeTundishNo())
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	//2009-03-16 ��������ͬʱ�������� End

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="ChangeTundishNo" type="L3BOOL">
/// ��������
/// </Method>
L3BOOL CCCM_Unit_Mag::ChangeTundishNo()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ��ѯ��ǰ�ȱ����а�
	CString strTundish; strTundish.Format(_T("select * from %s where Cast_ID = '%s' and Status = '%s'"), (LPCTSTR)CTUNDISH_BASE_URI,(LPCTSTR)GetName(),(LPCTSTR)CTUNDISH_STATUS_HOT);
	CL3RecordSetWrap rs;
	if(!Query(strTundish,rs) || rs.GetRowCount() < 1)
	{
		SetL3LastError(XGMES_ERR_CCM_NEEDTUNDISH);
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	CString strNewTundishID = rs.GetFieldByName(_T("TundishID")).ToCString();
	CString strNewWorkID = rs.GetFieldByName(_T("WorkID")).ToCString();
	CString csCarID;
	if(!strNewTundishID.IsEmpty()) //2009-03-23
		csCarID = GetObjectPropValue(CTUNDISH_BASE_URI + _T("\\") + strNewTundishID,_T("VehicleID")).ToCString();//2009-03-23
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ȡ�õ�ǰ����
	CString strCurNo = TundishNo; strCurNo.Trim();
	CString strCurTundish = strCurNo.IsEmpty() ? _T("") : CL3NameParser::MergeClassDomainName(CCM_TUNDISH_DATA_CLASS_URI,strCurNo);
	if(!strCurTundish.IsEmpty())
	{
		//if(!PutObjectIntoTrans(strCurTundish))
		//{
		//	if(nTrans > 0) Rollback(nTrans);
		//	return FALSE;
		//}
		// �����а�����֪ͨ���ν�����������ʱ�������ð��ν���ʱ�䡾2009-03-30 Liao��
		CString strCurTundishID = GetObjectPropValue(strCurTundish,_T("TundishID")).ToCString();
		L3STRING l3strCurTundishID = strCurTundishID.AllocSysString();
		L3STRING l3strCurNo = strCurNo.AllocSysString();
		CL3Variant valTundish = InvokeObjectMethod(_T("XGMESLogic\\TundishMag\\CTundish_Mag\\Tundish_Mag"),_T("TundishOffLine"),l3strCurTundishID,l3strCurNo,COleDateTime::GetCurrentTime());
		L3SysFreeString(l3strCurTundishID);
		L3SysFreeString(l3strCurNo);
		if(valTundish.ToLong() == 0)
		{
			if(nTrans > 0) 
				Rollback(nTrans);
			return FALSE;
		}

	    // ������ǰ����2009-02-13 [2009-30-30 ����]
		//SetObjectPropValue(strCurTundish,_T("Casting_Stop_Time"),CL3Variant(curTime));

		TundishNo = _T("");
	}

	// ��ʼ�°���
	CString strNewNo = CalculateNextTundishNo(strCurNo);
	CL3RecordSetWrap rsTundish;
	if(!CreateClassPropSet(CCM_TUNDISH_DATA_CLASS_URI,rsTundish))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsTundish.AppendRecord();
	rsTundish.CopyCurRowFrom(rs);
	rsTundish.SetFieldByName(_T("TundishNo"),CL3Variant(strNewNo));
	rsTundish.SetFieldByName(_T("CastingNo"),GetPropValue(_T("CastingNo")));
	rsTundish.SetFieldByName(_T("CCMID"),GetIdentity());
	rsTundish.SetFieldByName(_T("Casting_Start_Time"),CL3Variant(curTime));//2009-02-13
	rsTundish.SetFieldByName(_T("First_HeatID"),CL3Variant(_T("")));
	rsTundish.SetFieldByName(_T("Last_HeatID"),CL3Variant(_T("")));
	rsTundish.SetFieldByName(_T("HeatCount"),CL3Variant((LONG)0));
	rsTundish.SetFieldByName(_T("TundishID"),CL3Variant(strNewTundishID));
	rsTundish.SetFieldByName(_T("WorkID"),CL3Variant(strNewWorkID));
	rsTundish.SetFieldByName(_T("Tundish_CarID"),CL3Variant(csCarID)); //2009-03-23
	if(CreateNewObjects(CCM_TUNDISH_DATA_CLASS_URI,rsTundish) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ֪ͨ�а���������а���ʼ��ע
	L3STRING l3strNewTundishID = strNewTundishID.AllocSysString();
	L3STRING l3strNewNo = strNewNo.AllocSysString();
	CL3Variant valTundish = InvokeObjectMethod(_T("XGMESLogic\\TundishMag\\CTundish_Mag\\Tundish_Mag"),_T("TundishOnLine"),l3strNewTundishID,l3strNewNo,COleDateTime::GetCurrentTime());
	
	L3SysFreeString(l3strNewTundishID);
	L3SysFreeString(l3strNewNo);

	if(valTundish.ToLong() == 0)
	{
		if(nTrans > 0) 
			Rollback(nTrans);
		return FALSE;
	}

	// ���»��鵱ǰ����
	if(!SetPropValue(_T("TundishNo"),CL3Variant(strNewNo)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="ChangeStatus" type="L3LONG">
/// <Method class="CCCM_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
/// �޸��豸״̬
/// <Param name="nStatus" type="L3LONG">���豸״̬</Param>
/// <Param name="reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::ChangeDeviceStatus(L3LONG nStatus, L3STRING reason)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// �޸��豸״̬
	if(!SetPropValue(_T("Equip_Status"),CL3Variant(nStatus)))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��¼�豸״̬�����־
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(CCM_EQUIPMENT_STATUS_CLASS_URI,rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsLog.AppendRecord();
	CString cstrUnitID = (GetIdentity().ToCString()).Right(1);
	rsLog.SetFieldByName(_T("CCMID"),(L3LONG)_ttoi(cstrUnitID));
	rsLog.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsLog.SetFieldByName(_T("Log_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsLog.SetFieldByName(_T("Reason"),CL3Variant(reason));
	if(CreateNewObjects(CCM_EQUIPMENT_STATUS_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="DivideHeatApp" type="L3BOOL">
/// ����¯�ηָ�
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::DivideHeatApp(L3STRING Reason)
{
	// ��ȡ��ǰ��עλ�ϴ��
	CString strCastingArea = GetCastingArea();
	CL3Variant val = InvokeObjectMethod(strCastingArea,_T("GetMaterialDetails"),_T("CSteel_Data"),_T(""));
	CL3RecordSetWrap rsSteel;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsSteel)) || rsSteel.GetRowCount() < 1)
	{
		SetL3LastError(XGMES_ERR_CCM_NEEDSTEEL);
		return FALSE;
	}
	while(rsSteel.GetRowCount() > 1)
	{
		rsSteel.MoveLast();
		rsSteel.DeleteRecord();
	}
	rsSteel.AddField(_T("App_Time"),VT_DATE);
	rsSteel.AddField(_T("App_Steel_Weight"),VT_R8);
	rsSteel.AddField(_T("App_Operator"),VT_BSTR);
	rsSteel.AddField(_T("App_UnitID"),VT_BSTR);
	rsSteel.AddField(_T("App_Reason"),VT_BSTR);
	rsSteel.MoveFirst();
	rsSteel.SetFieldByName(_T("App_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsSteel.SetFieldByName(_T("App_Steel_Weight"),GetPropValue(_T("RemainedWeight")));
	rsSteel.SetFieldByName(_T("App_Operator"),CL3Variant(GetCurrentUser()));
	rsSteel.SetFieldByName(_T("App_UnitID"),GetIdentity());
	rsSteel.SetFieldByName(_T("App_Reason"),CL3Variant(Reason));

	CString strDispMag = DISPATCH_OBJ_URI;
	val = InvokeObjectMethod(strDispMag,_T("SteelDivApp"),(L3RECORDSET)rsSteel);
	return val.ToBOOL();
}

/// <Method class="CCCM_Unit_Mag" name="SendBackSteelApp" type="L3BOOL">
/// �������������͡�
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::SteelBackApp(L3STRING Reason)
{
	// ��ȡ��ǰ��ת̨λ�ϴ��
	CString strPrepareArea = GetPrepareArea();
	CL3Variant val = InvokeObjectMethod(strPrepareArea,_T("GetMaterialDetails"),_T("CSteel_Data"),_T(""));
	CL3RecordSetWrap rsSteel;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsSteel)) || rsSteel.GetRowCount() < 1)
	{
		SetL3LastError(XGMES_ERR_CCM_NEEDSTEEL);
		return FALSE;
	}
	while(rsSteel.GetRowCount() > 1)
	{
		rsSteel.MoveLast();
		rsSteel.DeleteRecord();
	}
	rsSteel.AddField(_T("App_Time"),VT_DATE);
	rsSteel.AddField(_T("App_Steel_Weight"),VT_R8);
	rsSteel.AddField(_T("App_Operator"),VT_BSTR);
	rsSteel.AddField(_T("App_UnitID"),VT_BSTR);
	rsSteel.AddField(_T("App_Reason"),VT_BSTR);
	rsSteel.MoveFirst();
	rsSteel.SetFieldByName(_T("App_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsSteel.SetFieldByName(_T("App_Steel_Weight"),rsSteel.GetFieldByName(_T("Weight")));
	rsSteel.SetFieldByName(_T("App_Operator"),CL3Variant(GetCurrentUser()));
	rsSteel.SetFieldByName(_T("App_UnitID"),GetIdentity());
	rsSteel.SetFieldByName(_T("App_Reason"),CL3Variant(Reason));

	CString strDispMag = DISPATCH_OBJ_URI;
	val = InvokeObjectMethod(strDispMag,_T("SteelBackApp"),(L3RECORDSET)rsSteel);
	return val.ToBOOL();
}

/// <Method class="CCCM_Unit_Mag" name="SendTurnSteelApp" type="L3BOOL">
/// ��������ˮȫ��¯��
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::SteelReturnApp(L3STRING Reason)
{
	// ��ȡ��ǰ��ת̨λ�ϴ��
	CString strPrepareArea = GetPrepareArea();
	CL3Variant val = InvokeObjectMethod(strPrepareArea,_T("GetMaterialDetails"),_T("CSteel_Data"),_T(""));
	CL3RecordSetWrap rsSteel;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsSteel)) || rsSteel.GetRowCount() < 1)
	{
		SetL3LastError(XGMES_ERR_CCM_NEEDSTEEL);
		return FALSE;
	}
	while(rsSteel.GetRowCount() > 1)
	{
		rsSteel.MoveLast();
		rsSteel.DeleteRecord();
	}
	rsSteel.AddField(_T("App_Time"),VT_DATE);
	rsSteel.AddField(_T("App_Steel_Weight"),VT_R8);
	rsSteel.AddField(_T("App_Operator"),VT_BSTR);
	rsSteel.AddField(_T("App_UnitID"),VT_BSTR);
	rsSteel.AddField(_T("App_Reason"),VT_BSTR);
	rsSteel.MoveFirst();
	rsSteel.SetFieldByName(_T("App_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsSteel.SetFieldByName(_T("App_Steel_Weight"),rsSteel.GetFieldByName(_T("Weight")));
	rsSteel.SetFieldByName(_T("App_Operator"),CL3Variant(GetCurrentUser()));
	rsSteel.SetFieldByName(_T("App_UnitID"),GetIdentity());
	rsSteel.SetFieldByName(_T("App_Reason"),CL3Variant(Reason));

	CString strDispMag = DISPATCH_OBJ_URI;
	val = InvokeObjectMethod(strDispMag,_T("SteelTurnApp"),(L3RECORDSET)rsSteel);
	return val.ToBOOL();
}


/// <Method class="CCCM_Unit_Mag" name="GenerateBlooms" type="L3BOOL">
/// ¯���и�  ¯��˦��
/// <Param name="rsBloomData" type="L3RECORDSET">��������</Param>
/// <Param name="HeatID" type="L3STRING">����¯��</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::GenerateBlooms(L3RECORDSET rsBloomData)
{
	CL3RecordSetWrap rs = rsBloomData;
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

	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	CString strBloomingArea = GetBloomingArea();
	if(!PutObjectIntoTrans(strBloomingArea))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ����������ˮ�任Ϊ����
	//rsSteel.MoveFirst();
	rs.MoveFirst();
	CBSTR bstrBloomingArea(strBloomingArea);
	if(!ProcessMaterials(bstrBloomingArea.GetBuffer(TRUE),rs,rs))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// �������ĸ����Ƴ���������ǰ��
	rs.MoveFirst();
	CString csHeatID = rs.GetFieldByName(_T("MaterialID")).ToCString();
	CL3RecordSetWrap rsBloom;
	CString strCond; strCond.Format(_T("B.MaterialID = '%s'"),csHeatID);
	CBSTR bstrCond(strCond);
	CL3Variant val = InvokeObjectMethod(strBloomingArea,_T("GetMaterialDetails"),_T("CBloom_Data"),bstrCond.GetBuffer(TRUE));
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsBloom)) || rsBloom.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsBloom.AddField(_T("Area"),VT_BSTR);
	rsBloom.MoveFirst();
	rsBloom.SetFieldByName(_T("Area"),CL3Variant(strBloomingArea));
	if(!DeliverMaterials(rsBloom))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// ������ҵʵ��2009-04-30����
	//rsBloom.MoveFirst();
	//CString strTreatNo = rsBloom.GetFieldByName(_T("TreatNo")).ToCString();
	//CString strProcData = CL3NameParser::MergeClassDomainName(CCM_PROCESS_DATA_CLASS_URI,strTreatNo);
	//SetObjPropValues(strProcData,rsBloom);

	//��¼˦��ʵ��
	CL3RecordSetWrap rsBloomWaster;
	CString csClass = _T("XGMESLogic\\QualityMag\\CQA_Bloom_Waster_Data");
	if(!CreateClassPropSet(csClass,rsBloomWaster))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsBloomWaster.DelField(_T("GUID"));
	rsBloomWaster.DelField(_T("Name"));
	rsBloomWaster.AppendRecord();
	rs.MoveFirst();
	rsBloomWaster.CopyCurRowFrom(rs);
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	rsBloomWaster.SetFieldByName(_T("Waster_Operator"),CL3Variant(GetCurrentUser()));
	rsBloomWaster.SetFieldByName(_T("Waster_Date"),CL3Variant(timeNow));
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rsBloomWaster.SetFieldByName(_T("ShitID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsBloomWaster.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
	//rsBloom.SetFieldByName(_T("Waster_Reason"),CL3Variant(GetCurrentUser()));
	if(CreateNewObjects(csClass,L3RECORDSET(rsBloomWaster)) < rsBloomWaster.GetRowCount())
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	//2009-04-27 �жϸ����Ƿ񿪽���ȫ��¯ tangyi
	rsBloom.MoveFirst();
	L3LONG nBloom_Count = rsBloom.GetFieldByName(_T("Bloom_Count")).ToLong();
	if(nBloom_Count == 0)
	{
		CString csSteelUri = MATERIAL_STEEL_URI + _T("\\") + csHeatID;
		CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
		//ɾ����ˮ����
		if(!SetObjectPropValue(csSteelUri,_T("Status"),L3LONG(5)))
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}

		//������ˮȫ��¯����
		CL3RecordSetWrap rsSteelTurnAppData;
		if(!CreateClassPropSet(DISPATCH_STEEL_TURN_CLASS_URI,rsSteelTurnAppData))
			return FALSE;
		rsSteelTurnAppData.DelField(_T("GUID"));
		rsSteelTurnAppData.DelField(_T("Name"));
		rsSteelTurnAppData.AppendRecord();
		rsSteelTurnAppData.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
		rsSteelTurnAppData.SetFieldByName(_T("PreHeatID"),GetObjectPropValue(csSteelUri,_T("PreHeatID")));
		rsSteelTurnAppData.SetFieldByName(_T("SteelGradeIndex"),GetObjectPropValue(csSteelUri,_T("SteelGradeIndex")));
		rsSteelTurnAppData.SetFieldByName(_T("App_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsSteelTurnAppData.SetFieldByName(_T("App_Steel_Weight"),GetObjectPropValue(csSteelUri,_T("Weight")));
		rsSteelTurnAppData.SetFieldByName(_T("App_Operator"),CL3Variant(GetCurrentUser()));
		rsSteelTurnAppData.SetFieldByName(_T("App_UnitID"),GetIdentity());
		rsSteelTurnAppData.SetFieldByName(_T("App_Reason"),CL3Variant(_T("1")));
		rsSteelTurnAppData.SetFieldByName(_T("Turn_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsSteelTurnAppData.SetFieldByName(_T("Turn_Flag"),L3LONG(1));
		rsSteelTurnAppData.SetFieldByName(_T("Turn_Operator"),CL3Variant(GetCurrentUser()));
		rsSteelTurnAppData.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsSteelTurnAppData.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsSteelTurnAppData.SetFieldByName(_T("All_Turn_Flag"),L3LONG(1));

		if(CreateNewObjects(DISPATCH_STEEL_TURN_CLASS_URI,rsSteelTurnAppData) < rsSteelTurnAppData.GetRowCount())
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}

		//���ļƻ���Ϣ
		CString csPlanURi = PLAN_TAPPING_CLASS_URI + _T("\\") + GetObjectPropValue(csSteelUri,_T("PreHeatID")).ToCString();
		if(!SetObjectPropValue(csPlanURi,_T("Steel_Return_Flag"),L3LONG(1))) 
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}
		//���ĸ�����״̬Ϊɾ��
		if(!SetObjectPropValue(csBloomUri,_T("Status"),L3LONG(5)))
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}
		//�齨���ݼ�
		CL3RecordSet *pRS = new CL3RecordSet();
		CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
		rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
		rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
		rsMaterial.AddField(_T("Amount"),VT_INT);
		rsMaterial.AppendRecord();
		rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BLOOM));
		rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csHeatID));
		rsMaterial.SetFieldByName(_T("Amount"),CL3Variant(L3LONG(1)));
		//����ˮ�Ӹ������ǰ������ȥ
		CString csSteelCurCache = BLOOM_STORE_INCACHE_OBJ_URI;
		CL3Variant valResult = InvokeObjectMethod(csSteelCurCache,_T("RemoveMaterials"),(L3RECORDSET)rsMaterial);
		if(!valResult.IsValid()||!valResult.ToBOOL())
			return FALSE;//��ˮ�ӷ������빤���Ƴ�ʧ��

		//֪ͨͨѶ��NC����ȫ��¯����
		CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
		CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Steel_Back_Event"));
		L3LONG nEvent = varEvent.ToLong();
		nEvent = (nEvent+1) % 9999;
		SetObjectPropValue(csBaseUri,_T("NC_Steel_Back_Event"),nEvent);
	}


	if(nTrans > 0) Commit(nTrans);

	//�ı�����ֵ,֪ͨ���������ȼ�
	CString csUri = _T("XGMESLogic\\QualityMag\\CQA_HeatSufaceAssume_Mag\\QA_HeatSufaceAssume_Mag");
	CL3Variant varEvent = GetObjectPropValue(csUri,_T("BloomCuttingEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csUri,_T("BloomCuttingEvent"),nEvent);

	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="SetRemainedSteelWeight" type="L3BOOL">
/// ������ʣ�������źš�
/// <Param name="fWeight" type="L3DOUBLE">���ʣ������</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::SetRemainedSteelWeight(L3DOUBLE fWeight)
{
	RemainedWeight = fWeight;
	return TRUE;
}


/// <Method class="CCCM_Unit_Mag" name="GetHeatAllInformation" type="">
/// ��ȡ�Ѿ�������¯�ε���Ϣ
/// </Method>
L3RECORDSET CCCM_Unit_Mag::GetHeatAllInformation()
{
	CString csArea = GetIdentity().ToCString() + _T("A03");
	CString csTemp =_T(" select a.MaterialID,a.MaterialType,a.Amount,b.HeatID,b.CastingNo as Casting_No,b.CCMID as CasterID,b.Casting_HeatNum as Casting_Heat_Cnt,                       ");
			csTemp+=_T(" c.SteelGradeIndex,c.SteelGradeIndex as Cut_SteelGradeIndex,c.Pre_SteelGradeIndex,c.Destitation as Destination,                                                  ");
			csTemp+=_T(" c.Plan_Ord_ID,c.Thickness,c.Width,c.Length,c.Hot_Send_Flag,NULL as Bloom_Count,NULL as Cal_Weight,NULL as Right_Count,                                          ");
			csTemp+=_T(" NULL as Right_Weight,NULL as Waster_Count,NULL as Waster_Weight,NULL as Waster_Count1, NULL as Waster_Weight1,                                                  ");
			csTemp+=_T(" NULL as Waster_Reason1,NULL as Waster_Count2,NULL as Waster_Weight2,NULL as Waster_Reason2, NULL as Waster_Count3,                                              ");
			csTemp+=_T(" NULL as Waster_Weight3,NULL as Waster_Reason3,NULL as Produce_Date,                                                                                             ");
			//2009-08-06 
			csTemp+=_T(" NULL as Add_Bloom_Count,NULL as Div_Bloom_Count,NULL as Plan_Bloom_Count,NULL as Add_Div_HeatID                                                               ");
			csTemp+=_T(" from %s a,%s b,%s c  where a.Position ='%s' and a.MaterialType = '%s' and a.MaterialID = b.HeatID(+) and b.CCMID = '%s' and a.MaterialID = c.HeatID(+)          ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,CCM_PROCESS_DATA_CLASS_URI,PLAN_TAPPING_CLASS_URI,csArea,MATERIAL_TYPE_STEEL,GetIdentity().ToCString());
	CL3RecordSetWrap rsHeat;
	if(!Query(csSQL,rsHeat) || rsHeat.IsNull())
		return NULL;
	return rsHeat.Detach();
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCMTundishFireData" type="L3BOOL">
/// ���������а��濾���� 2009-01-03
/// <Param name="rsData" type="L3RECORDSET">�а��濾����</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCMTundishFireData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_Tundish_Fire_Data"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	CString csPosition,csTundishID;
	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		//��ȡ�а��š���������
		csPosition = rsTemp.GetFieldByName(_T("Position"));
		if (csPosition == _T("1")) //���а�
			csTundishID = EastTundishID;
		else  //���а�
			csTundishID = WestTundishID;

		rsTemp.SetFieldByName(_T("Cast_ID"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsTemp.SetFieldByName(_T("MeasureTime"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsTemp.SetFieldByName(_T("WorkID"),GetObjectPropValue(_T("XGMESLogic\\TundishMag\\CTundish_Base\\")+csTundishID,_T("WorkID")));

		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_Tundish_Fire_Data"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCMRuntimeData" type="L3BOOL">
/// ���������������ս������һ�ε�ʵʱ���� 2009-01-03
/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCMRuntimeData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

    CString cstrCCMUri;

	cstrCCMUri = _T("XGMESLogic\\CCMMag\\CCCM_Runtime_Data");

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(cstrCCMUri,rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("TreatNo"),CL3Variant(TreatNo));
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("LogTime"),CL3Variant(COleDateTime::GetCurrentTime()));

		CString cstrCCID = GetIdentity().ToCString();//2009-04-30
		//2009-02-28 begin
		L3SHORT CatchCount = (rsTemp.GetFieldByName(_T("Catch_Count"))).ToShort();
		if (CatchCount == 3)  //���а���ǰ��ˮ�����а�Һ�������� 
		{
			CastTo15Minute = 1;
			CString strTreatNo = TreatNo;
			if (strTreatNo.GetLength() < 1) //2009-04-30
			{
				rsTemp.MoveNext();
				break;
			}
			CString procData = CL3NameParser::MergeClassDomainName(CCM_PROCESS_DATA_CLASS_URI,strTreatNo);
			if ((cstrCCID != _T("S61")) && (cstrCCID != _T("S62")))//2009-04-30
			{
				SetObjectPropValue(procData,_T("Tundish_Level_Mold"),CL3Variant(TundishWeight));  //�а�Һ��
			}
    		L3SHORT iCooling_MeterNo = (rsTemp.GetFieldByName(_T("Cooling_MeterNo"))).ToShort();  //2009-03-03
			SetObjectPropValue(procData,_T("Second_Cooling_CurveNo"),CL3Variant((L3SHORT)iCooling_MeterNo));  //ˮ��� //2009-03-03
			SetObjectPropValue(procData,_T("Second_Cooling_Mode"),rsTemp.GetFieldByName(_T("Mode_Cooling_2ST"))); 
			//��ȡ�����������
			L3FLOAT fFlow_BlowAr_PlugBar_1ST = (rsTemp.GetFieldByName(_T("Flow_BlowAr_PlugBar_1ST"))).ToFloat();
			L3FLOAT fFlow_BlowAr_PlugBar_2ST = (rsTemp.GetFieldByName(_T("Flow_BlowAr_PlugBar_2ST"))).ToFloat();
			L3FLOAT fFlow_BlowAr_PlugBar_3ST = (rsTemp.GetFieldByName(_T("Flow_BlowAr_PlugBar_3ST"))).ToFloat();
			L3FLOAT fFlow_BlowAr_PlugBar_4ST = (rsTemp.GetFieldByName(_T("Flow_BlowAr_PlugBar_4ST"))).ToFloat();

			//������ʼ
			if(cstrCCID!=_T("S67"))
			{
				if ((fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_2ST > 5) ||
					(fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5) ||
					(fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_4ST > 5) ||
					(fFlow_BlowAr_PlugBar_2ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5) ||
					(fFlow_BlowAr_PlugBar_2ST > 5) && (fFlow_BlowAr_PlugBar_4ST > 5) ||
					(fFlow_BlowAr_PlugBar_3ST > 5) && (fFlow_BlowAr_PlugBar_4ST > 5))
				{
		    		SetObjectPropValue(procData,_T("InjectionBar_BlowAr"),CL3Variant((L3SHORT)1)); //�Ƿ��������
				}
			}
			if(cstrCCID==_T("S67"))
			{
				if ((fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_2ST > 5) ||
					(fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5) ||
					(fFlow_BlowAr_PlugBar_2ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5))
				{
		    		SetObjectPropValue(procData,_T("InjectionBar_BlowAr"),CL3Variant((L3SHORT)1)); //�Ƿ��������
				}
			}
			//��������
			//modify end

			//��ȡ���������ע�������
			L3FLOAT fFlow_BlowAr_ProtectCasting = (rsTemp.GetFieldByName(_T("Flow_BlowAr_ProtectCasting"))).ToFloat();
			if (fFlow_BlowAr_ProtectCasting > 30)
			{
				CString ladleData = CL3NameParser::MergeClassDomainName(CCM_HEAT_LADLE_CLASS_URI,strTreatNo);
		    	SetObjectPropValue(ladleData,_T("Protection"),CL3Variant((L3SHORT)1)); //�Ƿ���������ע
			}
            //��������ע״̬
			CString strHeatID = HeatID;
			CString strGUID;
			for (int i=1;i<5;i++)
			{
				strGUID = GetHeatStrandGUID(strHeatID,GetIdentity().ToCString(),i);
				if (strGUID.GetLength() > 1)
				{
        			CString strObjectID = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo"),strGUID);
   					switch (i)
					{
    					case CCCM_Unit_Mag::ST1: 
							SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((LONG)OnOff1st));
						break;
						case CCCM_Unit_Mag::ST2: 
							SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((LONG)OnOff2st));
						break;
						case CCCM_Unit_Mag::ST3: 
							SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((LONG)OnOff3st));
						break;
						case CCCM_Unit_Mag::ST4: 
							SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((LONG)OnOff4st));
						break;
						default:
							break;
					}
				}
			}
		}
		//2009-02-28 end

		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	CreateNewObjects(cstrCCMUri,rsTemp);

	return TRUE;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCM5Runtime1Data" type="L3BOOL">
/// ����5#�����������ս������һ�ε�ʵʱ����1 2009-02-25
/// ����6#CCM���ɹ��ô˷���hyh 2012-05-09
/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCM5Runtime1Data(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

    CString cstrCCMUri;

	CString cstrUnitID = GetIdentity().ToCString();
    cstrCCMUri = _T("XGMESLogic\\CCMMag\\CCCM5_Runtime1_Data");

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(cstrCCMUri,rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("TreatNo"),CL3Variant(TreatNo));
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("LogTime"),CL3Variant(COleDateTime::GetCurrentTime()));

		CString cstrCCID = GetIdentity().ToCString();//2009-04-30
		//2009-02-28 begin
		L3SHORT CatchCount = (rsTemp.GetFieldByName(_T("Catch_Count"))).ToShort();
		if (CatchCount == 3)  //���а���ǰ��ˮ�����а�Һ�������� 
		{
			CString strTreatNo = TreatNo;
			if (strTreatNo.GetLength() < 1) //2009-04-30
			{
				rsTemp.MoveNext();
				break;
			}

			CString procData = CL3NameParser::MergeClassDomainName(CCM_PROCESS_DATA_CLASS_URI,strTreatNo);
			SetObjectPropValue(procData,_T("Tundish_Level_Mold"),CL3Variant(TundishWeight));  //�а�Һ��
    		L3SHORT iCooling_MeterNo = (rsTemp.GetFieldByName(_T("Cooling_MeterNo"))).ToShort();  //2009-03-03
			SetObjectPropValue(procData,_T("Second_Cooling_CurveNo"),CL3Variant((L3SHORT)iCooling_MeterNo));  //ˮ��� //2009-03-03

			//��ȡ�����������
			L3FLOAT fFlow_BlowAr_PlugBar_1ST = (rsTemp.GetFieldByName(_T("Flow_BlowAr_PlugBar_1ST"))).ToFloat();
			L3FLOAT fFlow_BlowAr_PlugBar_2ST = (rsTemp.GetFieldByName(_T("Flow_BlowAr_PlugBar_2ST"))).ToFloat();
			L3FLOAT fFlow_BlowAr_PlugBar_3ST = (rsTemp.GetFieldByName(_T("Flow_BlowAr_PlugBar_3ST"))).ToFloat();
			L3FLOAT fFlow_BlowAr_PlugBar_4ST = (rsTemp.GetFieldByName(_T("Flow_BlowAr_PlugBar_4ST"))).ToFloat();

			//modify begin by llj 2011-1-26 Add CCM7 CC7ֻ��3��
			//ԭ�������
			//if ((fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_2ST > 5) ||
			//	(fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5) ||
			//	(fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_4ST > 5) ||
			//	(fFlow_BlowAr_PlugBar_2ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5) ||
			//	(fFlow_BlowAr_PlugBar_2ST > 5) && (fFlow_BlowAr_PlugBar_4ST > 5) ||
			//	(fFlow_BlowAr_PlugBar_3ST > 5) && (fFlow_BlowAr_PlugBar_4ST > 5))
			//{
			//   	SetObjectPropValue(procData,_T("InjectionBar_BlowAr"),CL3Variant((L3SHORT)1)); //�Ƿ��������
			//}
			//������ʼ
			if(cstrCCID!=_T("S67"))
			{
				if ((fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_2ST > 5) ||
					(fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5) ||
					(fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_4ST > 5) ||
					(fFlow_BlowAr_PlugBar_2ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5) ||
					(fFlow_BlowAr_PlugBar_2ST > 5) && (fFlow_BlowAr_PlugBar_4ST > 5) ||
					(fFlow_BlowAr_PlugBar_3ST > 5) && (fFlow_BlowAr_PlugBar_4ST > 5))
				{
		    		SetObjectPropValue(procData,_T("InjectionBar_BlowAr"),CL3Variant((L3SHORT)1)); //�Ƿ��������
				}
			}
			if(cstrCCID==_T("S67"))
			{
				if ((fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_2ST > 5) ||
					(fFlow_BlowAr_PlugBar_1ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5) ||
					(fFlow_BlowAr_PlugBar_2ST > 5) && (fFlow_BlowAr_PlugBar_3ST > 5))
				{
		    		SetObjectPropValue(procData,_T("InjectionBar_BlowAr"),CL3Variant((L3SHORT)1)); //�Ƿ��������
				}
			}
			//��������
			//modify end


			//��ȡ���������ע�������
			L3FLOAT fFlow_BlowAr_ProtectCasting = (rsTemp.GetFieldByName(_T("Flow_BlowAr_ProtectCasting"))).ToFloat();
			if (fFlow_BlowAr_ProtectCasting > 30)
			{
				CString ladleData = CL3NameParser::MergeClassDomainName(CCM_HEAT_LADLE_CLASS_URI,strTreatNo);
		    	SetObjectPropValue(ladleData,_T("Protection"),CL3Variant((L3SHORT)1)); //�Ƿ���������ע
			}
            //��������ע״̬
			CString strHeatID = HeatID;
			CString strGUID;
			for (int i=1;i<5;i++)
			{
				strGUID = GetHeatStrandGUID(strHeatID,GetIdentity().ToCString(),i);
				if (strGUID.GetLength() > 1)
				{
        			CString strObjectID = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo"),strGUID);
   					switch (i)
					{
    					case CCCM_Unit_Mag::ST1: 
							SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((LONG)OnOff1st));
						break;
						case CCCM_Unit_Mag::ST2: 
							SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((LONG)OnOff2st));
						break;
						case CCCM_Unit_Mag::ST3: 
							SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((LONG)OnOff3st));
						break;
						case CCCM_Unit_Mag::ST4: 
							SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((LONG)OnOff4st));
						break;
						default:
							break;
					}
				}
			}
		}
		//2009-02-28 end

		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	CreateNewObjects(cstrCCMUri,rsTemp);

	return TRUE;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCM5Runtime2Data" type="L3BOOL">
/// ����5#�����������ս������һ�ε�ʵʱ������ȴ������� 2009-02-25
/// ����6#CCM���ɹ��ô˷���hyh 2012-05-09
/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCM5Runtime2Data(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

    CString cstrCCMUri;

	CString cstrUnitID = GetIdentity().ToCString();
    cstrCCMUri = _T("XGMESLogic\\CCMMag\\CCCM5_Runtime2_Data");

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(cstrCCMUri,rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("TreatNo"),CL3Variant(TreatNo));
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("LogTime"),CL3Variant(COleDateTime::GetCurrentTime()));

		//2009-03-19 begin
		L3SHORT CatchCount = (rsTemp.GetFieldByName(_T("Catch_Count"))).ToShort();
		if (CatchCount == 3)  
		{
			CString strTreatNo = TreatNo;
			if (strTreatNo.GetLength() < 1) //2009-04-30
			{
				rsTemp.MoveNext();
				break;
			}
			CString procData = CL3NameParser::MergeClassDomainName(CCM_PROCESS_DATA_CLASS_URI,strTreatNo);
			SetObjectPropValue(procData,_T("Soft_Press_Flag_1"),rsTemp.GetFieldByName(_T("Flag_SoftPress_1ST"))); 
			SetObjectPropValue(procData,_T("Soft_Press_Flag_2"),rsTemp.GetFieldByName(_T("Flag_SoftPress_2ST"))); 
			SetObjectPropValue(procData,_T("Soft_Press_Flag_3"),rsTemp.GetFieldByName(_T("Flag_SoftPress_3ST"))); 
			SetObjectPropValue(procData,_T("Soft_Press_Flag_4"),rsTemp.GetFieldByName(_T("Flag_SoftPress_4ST"))); 
			L3LONG iMode = rsTemp.GetFieldByName(_T("Mode_Cooling_2ST")).ToLong();//2009-03-23(5# 0-һ��;1-����) ͳһ��1-4#��ͬ 1-����Ա;2-һ��;3-����
			if (iMode == 0)
				iMode = 2;
			else
				iMode = 3;
			SetObjectPropValue(procData,_T("Second_Cooling_Mode"),(L3LONG)iMode); 
		}		
		//2009-03-19 End

		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	CreateNewObjects(cstrCCMUri,rsTemp);

	return TRUE;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCMSpeedData" type="L3BOOL">
/// ���������������ս�����ʵʱ���� 2009-01-03
/// ����6#CCM���ɹ��ô˷���hyh 2012-05-09
/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCMSpeedData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	CL3RecordSetWrap rsSpeed;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_Heat_Speed"),rsSpeed))
	{
		return FALSE;
	}


	rs.MoveFirst();
	L3DOUBLE fSpeed1ST=0;
	L3DOUBLE fSpeed2ST=0;
	L3DOUBLE fSpeed3ST=0;
	L3DOUBLE fSpeed4ST=0;

	while (!rs.IsEOF())
	{
		fSpeed1ST = (rs.GetFieldByName(_T("Speed_1ST"))).ToFloat();
		if (fSpeed1ST > 0.001)
		{
			rsSpeed.AppendRecord();
			rsSpeed.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
			rsSpeed.SetFieldByName(_T("StrandID"),(L3SHORT)1);
			rsSpeed.SetFieldByName(_T("Speed"),(L3DOUBLE)fSpeed1ST);
			rsSpeed.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsSpeed.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		}

		fSpeed2ST = (rs.GetFieldByName(_T("Speed_2ST"))).ToFloat();
		if (fSpeed2ST > 0.001)
		{
			rsSpeed.AppendRecord();
			rsSpeed.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
			rsSpeed.SetFieldByName(_T("StrandID"),(L3SHORT)2);
			rsSpeed.SetFieldByName(_T("Speed"),(L3DOUBLE)fSpeed2ST);
			rsSpeed.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsSpeed.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		}

		fSpeed3ST = (rs.GetFieldByName(_T("Speed_3ST"))).ToFloat();
		if (fSpeed3ST > 0.001)
		{
			rsSpeed.AppendRecord();
			rsSpeed.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
			rsSpeed.SetFieldByName(_T("StrandID"),(L3SHORT)3);
			rsSpeed.SetFieldByName(_T("Speed"),(L3DOUBLE)fSpeed3ST);
			rsSpeed.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsSpeed.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		}

		fSpeed4ST = (rs.GetFieldByName(_T("Speed_4ST"))).ToFloat();
		if (fSpeed4ST > 0.001)
		{
			rsSpeed.AppendRecord();
			rsSpeed.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
			rsSpeed.SetFieldByName(_T("StrandID"),(L3SHORT)4);
			rsSpeed.SetFieldByName(_T("Speed"),(L3DOUBLE)fSpeed4ST);
			rsSpeed.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsSpeed.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		}

		rs.MoveNext();
	}

	rsSpeed.MoveFirst();
	CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_Heat_Speed"),rsSpeed);

	//2009-01-15 ���õ�ǰ���� Begin
	Speed1st = fSpeed1ST;
	Speed2st = fSpeed2ST;
	Speed3st = fSpeed3ST;
	Speed4st = fSpeed4ST;
    //2009-01-15 End

	return TRUE;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCMTundishTempData" type="L3BOOL">
/// ���������������ս��а��������� 2009-01-03
/// <Param name="rsData" type="L3RECORDSET">�а���������</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCMTundishTempData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_Heat_TundishTemp"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("Measure_Time"),CL3Variant(COleDateTime::GetCurrentTime()));

		L3LONG iTemp = rsTemp.GetFieldByName(_T("Temp")).ToLong();
		if ((iTemp < 1450) || (iTemp > 1650))
		{
			rsTemp.SetFieldByName(_T("InValidFlag"),CL3Variant((L3SHORT)1));
		}

		CString strHeatID = HeatID;
		CString strCCMID = GetIdentity().ToCString();
		SetTundishTempInValidFlag(strHeatID,strCCMID);//2009-03-25

		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_Heat_TundishTemp"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	//2009-01-15 ���õ�ǰ�а��¶� Begin
	rsTemp.MoveLast();
	TundishTemp = rsTemp.GetFieldByName(_T("Temp")).ToShort();
    //2009-01-15 End

	return TRUE;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCMStatus" type="L3BOOL">
/// ������������״̬���� 2009-01-03
/// ����6#CCM���ɹ��ô˷���hyh 2012-05-09
/// <Param name="rsData" type="L3RECORDSET">״̬����</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCMStatus(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	// ��ȡ¯��
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		L3LONG CCMStatus = -1;
		CCMStatus = (rs.GetFieldByName(_T("CCMStatus"))).ToLong();
		switch(CCMStatus)
		{
			//�����������
    		case CCCM_Unit_Mag::CCMArrivle: 
				SteelArrived();
			break;
			//��������
			case CCCM_Unit_Mag::CCMCasting: 
				StartCasting();
			break;
			//��������
			case CCCM_Unit_Mag::CCMCasted: 
				CompletCasting();
			break;
			//����°�
			case CCCM_Unit_Mag::CCMDeparture: 
				LadleDeparture();
			break;
			//�ȴ�
			default:
				break;
		}
		rs.MoveNext();
	}
	
	return TRUE;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCMLadleWeightData" type="L3BOOL">
/// �����������а��������� 2009-01-03
///����6#CCM���ɹ��ô˷���hyh 2012-05-09
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCMLadleWeightData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	// ��ȡ���а�����
	rs.MoveFirst();
	L3DOUBLE fTundishWeight = (rs.GetFieldByName(_T("TundishWeight"))).ToDouble();
	L3DOUBLE fLadleWeight = (rs.GetFieldByName(_T("LadleWeight"))).ToDouble();
	RemainedWeight = fLadleWeight;
	TundishWeight = fTundishWeight;
	CalculateRemainCastingTime(); //2009-03-20
	return TRUE;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCMSteelWeightData" type="L3BOOL">
/// ����������ˮ�������� 2009-01-03
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCMSteelWeightData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveFirst();
	L3DOUBLE fSteelWeight = (rs.GetFieldByName(_T("Weight"))).ToDouble();
	SteelWeight = fSteelWeight;
	return TRUE;	
}

//�����ѹ��ʱ��
L3DATETIME CCCM_Unit_Mag::CalculateHoldTime(LPCTSTR lpcszTreatNo)
{
	CString csLastTreatNo = GetPreviousTreatNo(lpcszTreatNo);

    CL3Variant valStopCasting = GetObjectPropValue(_T("XGMESLogic\\CCMMag\\CCCM_Heat_Ladle\\")+csLastTreatNo,_T("Casting_Stop_Time"));
	return valStopCasting.ToDateTime();
}



/// <Method class="CCCM_Unit_Mag" name="GetHeatAllInformation" type="">
/// ��ȡ���Խ���¯��ȷ������Ϣ2009-02-22
/// </Method>
L3RECORDSET CCCM_Unit_Mag::GetHeatConfirmInfor()
{
	CString csTemp =_T(" select a.* from %s a,%s b where a.HeatID =b.HeatID and b.HeatConfirm = 0 and a.CasterID ='%s'");
	CString csSQL;
	csSQL.Format(csTemp,BLOOM_DATA_CLASS_URI,CCM_BASE_DATA_CLASS_URI,GetIdentity().ToCString());
	CL3RecordSetWrap rsHeat;
	if(!Query(csSQL,rsHeat) || rsHeat.IsNull())
		return NULL;
	return rsHeat.Detach();
}

/// ��ȡǰ����� 2009-02-26
CString CCCM_Unit_Mag::GetPreviousTreatNo(LPCTSTR lpcszTreatNo)
{
	CString csUnit = GetIdentity().ToCString();
	CString strTreatNo = lpcszTreatNo;
	CString csTempSQL =_T(" select Max(TreatNo) as TreatNo from CCCM_Base_Data where CCMID = '%s' and TreatNo < '%s'");
	CString csSQL;
	csSQL.Format(csTempSQL,csUnit,lpcszTreatNo);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return lpcszTreatNo;
	rs.MoveFirst();
	CString csPreTreatNo = rs.GetFieldByIndex(0).ToCString();
	return csPreTreatNo;
}

/// <Method class="CCCM_Unit_Mag" name="LadleDeparture" type="L3BOOL">
/// ����°� 2009-02-26
/// </Method>
L3BOOL CCCM_Unit_Mag::LadleDeparture()
{
	CString strCurTreatNo = TreatNo;
	if (strCurTreatNo.GetLength() != 8)
	{
		return FALSE;
	}

    CString strPreTreatNo = GetPreviousTreatNo(strCurTreatNo);

	if (strPreTreatNo.GetLength() != 8)
	{
		return FALSE;
	}
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	//�������¯������
	CString strLadelData = CL3NameParser::MergeClassDomainName(CCM_HEAT_LADLE_CLASS_URI,strPreTreatNo);
	SetObjectPropValue(strLadelData,_T("Departure_Time"),CL3Variant(curTime));

	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="AcceptSteelWeight" type="L3BOOL">
/// ����������ˮ�������� 2009-02-26
/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptSteelWeight(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveFirst();
	CString strCCMID = rs.GetFieldByName(_T("CCMID")).ToCString();
	L3FLOAT fSteelWeight = rs.GetFieldByName(_T("SteelWeight")).ToFloat();

	CString strCCMMag = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag"),strCCMID);

	CString strHeatID = GetObjectPropValue(strCCMMag,_T("NextHeatID")).ToCString();

	if (strHeatID.GetLength() != 9)
	{
		return FALSE;
	}
	CString strHeatData = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,strHeatID);
	SetObjectPropValue(strHeatData,_T("Weight"),CL3Variant(fSteelWeight));
	SetObjectPropValue(strCCMMag,_T("SteelWeight"),CL3Variant(fSteelWeight));

	return TRUE;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptStrandStatusData" type="L3BOOL">
/// ����������״̬���� 2009-02-26
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptStrandStatusData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount = rs.GetRowCount();
	if(rsCount < 1)
		return TRUE;

	rs.MoveFirst();
	for(int i=0;i<rsCount;i++) //2009-03-05 ���Ӷ������ռ�
	{
		CString strCCMID = rs.GetFieldByName(_T("CCMID")).ToCString();  //��ȡ������
		L3LONG iStrandNo = rs.GetFieldByName(_T("StrandNo")).ToLong();  //��ȡ����
		L3LONG iStrandStatus = rs.GetFieldByName(_T("OnOff")).ToLong(); //��ȡ��״̬

		//��ȡ�����������
		CString strCCMMag = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag"),strCCMID);
		//����������������ȡ��ǰ���κ�,���κ�,¯��
		CString strCastingNo = GetObjectPropValue(strCCMMag,_T("CastingNo")).ToCString();
		CString strTundishNo = GetObjectPropValue(strCCMMag,_T("TundishNo")).ToCString();
		L3LONG iStatus = GetObjectPropValue(strCCMMag,_T("Status")).ToLong();
		CString strHeatID = GetObjectPropValue(strCCMMag,_T("HeatID")).ToCString();

		if (CastTo15Minute == 0) //2009-03-05 ���˿���15�������ս�ʱ��βż�¼������״̬����,���ڼ���ͨ����(Ҳ����״̬���ս�������15�����ڼ��ռ���PLC����Ϊ����)
		{
			switch (iStrandNo)
			{
    			case CCCM_Unit_Mag::ST1: 
					SetObjectPropValue(strCCMMag,_T("OnOff1st"),CL3Variant((LONG)iStrandStatus));
				break;
				case CCCM_Unit_Mag::ST2: 
					SetObjectPropValue(strCCMMag,_T("OnOff2st"),CL3Variant((LONG)iStrandStatus));
				break;
				case CCCM_Unit_Mag::ST3: 
					SetObjectPropValue(strCCMMag,_T("OnOff3st"),CL3Variant((LONG)iStrandStatus));
				break;
				case CCCM_Unit_Mag::ST4: 
					SetObjectPropValue(strCCMMag,_T("OnOff4st"),CL3Variant((LONG)iStrandStatus));
				break;
				default:
					break;
			}
		}

		CL3RecordSetWrap rsSTData;
		if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_StrandInfo"),rsSTData))
		{
			return FALSE;
		}

		COleDateTime curTime = COleDateTime::GetCurrentTime();
		rsSTData.AppendRecord();
		rsSTData.SetFieldByName(_T("CCMID"),CL3Variant(strCCMID));
		rsSTData.SetFieldByName(_T("StrandNo"),(L3LONG)iStrandNo);
		rsSTData.SetFieldByName(_T("OnOff"),(L3LONG)iStrandStatus);
		rsSTData.SetFieldByName(_T("ChangeTime"),CL3Variant(curTime));
		rsSTData.SetFieldByName(_T("CastingNo"),CL3Variant(strCastingNo));
		rsSTData.SetFieldByName(_T("TundishNo"),CL3Variant(strTundishNo));
		rsSTData.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));

		if (strHeatID.GetLength() > 0) 
		{
			CString strGUID = GetHeatStrandGUID(strHeatID,strCCMID,iStrandNo);
			if (strGUID.GetLength() > 1)
			{
        		CString strObjectID = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo"),strGUID);
				if (iStrandStatus == 0) //ͣ��:����ͣ��ʱ��
				{
					SetObjectPropValue(strObjectID,_T("Stop_Time"),CL3Variant(curTime));
				}
				else //����:���ÿ���ʱ��
				{
					SetObjectPropValue(strObjectID,_T("Start_Time"),CL3Variant(curTime));
					switch (iStrandNo)
					{
						case CCCM_Unit_Mag::ST1: 
							SetObjectPropValue(strObjectID,_T("Cast_Num"),CL3Variant((L3LONG)(++CastNum1ST)));
						break;
						case CCCM_Unit_Mag::ST2: 
							SetObjectPropValue(strObjectID,_T("Cast_Num"),CL3Variant((L3LONG)(++CastNum2ST)));
						break;
						case CCCM_Unit_Mag::ST3: 
							SetObjectPropValue(strObjectID,_T("Cast_Num"),CL3Variant((L3LONG)(++CastNum3ST)));
						break;
						case CCCM_Unit_Mag::ST4: 
							SetObjectPropValue(strObjectID,_T("Cast_Num"),CL3Variant((L3LONG)(++CastNum4ST)));
						break;
						default:
							break;
					}
				}

				//if (CastTo15Minute == 0)
				//{
				//	SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant(L3LONG)iStrandStatus);//2009-03-26 ��¼��ͣ��״̬(¯���ڿ���15����ǰ���һ��Ϊ׼)
				//}
				
			}
		}

		rsSTData.MoveFirst();
		CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_StrandInfo"),rsSTData);

		rs.MoveNext();
	}
	
	return TRUE;	
}

/// ��ȡ¯����GUID 2009-02-26
CString CCCM_Unit_Mag::GetHeatStrandGUID(LPCTSTR lpcszHeatID,LPCTSTR lpcszCCMID,L3LONG iStrandID)
{
	CString cssql,strHeatID,strCCMID; 
	strHeatID = lpcszHeatID; strCCMID = lpcszCCMID;

	cssql.Format(_T("select GUID from CCCM_Heat_StrandInfo where HeatID = '%s' and CCMID = '%s' and StrandID = '%d'"),
		             strHeatID,strCCMID,iStrandID);
	CL3RecordSetWrap rs;
	if(!Query(cssql,rs) || rs.GetRowCount() < 1)
	{
		return _T("");
	}
	rs.MoveFirst();
    return rs.GetFieldByName(_T("GUID")).ToCString();
}


/// <Method class="CCCM_Unit_Mag" name="ArrivalTemperatureJudge" type="L3SHORT">
/// �ж������¶Ⱥϸ� 2009-02-28
/// <Param name="lpcszSteelGradeIndex" type="LPCTSTR">���ּǺ�</Param>//2009-04-13 ��Ϊ�ж�ʱ��¯���ּǺ�δ����
/// <Param name="lpcszUnitType" type="LPCTSTR">��������</Param>
/// <Param name="iTempertaure" type="L3LONG">�ϻ��¶�</Param>
/// <Param name="iHeatNum" type="L3LONG">������¯��</Param>
/// </Method>
L3SHORT CCCM_Unit_Mag::ArrivalTemperatureJudge(LPCTSTR lpcszSteelGradeIndex,LPCTSTR lpcszUnitType,L3LONG iTempertaure,L3LONG iHeatNum)
{
	L3SHORT iresult = 0;
	CString csSQL;
	CString strSteelGradeIndex = lpcszSteelGradeIndex;
	CString strUnitID = lpcszUnitType;
	if ((strUnitID.GetLength() < 1) || (strSteelGradeIndex.GetLength() < 1))
	{
		return iresult;
	}
	if (strUnitID == _T("S2"))
	{	
		csSQL.Format(_T("select BeAr_SteelTemp_Fir_Min,BeAr_SteelTemp_Fir_Max,BeAr_SteelTemp_Min,BeAr_SteelTemp_Max from CQA_BOF_Std_Ar where SteelGradeIndex = '%s'"),strSteelGradeIndex);
	}
	else if (strUnitID == _T("S4"))
	{
		csSQL.Format(_T("select LeaFir_Temp_Min,LeaFir_Temp_Max,Lea_Temp_Min,Lea_Temp_Max from CQA_LF_Std_Proc where SteelGradeIndex = '%s'"),strSteelGradeIndex);
	}
	else if (strUnitID == _T("S5"))
	{
		csSQL.Format(_T("select LeaFir_Temp_Min,LeaFir_Temp_Max,Lea_Temp_Min,Lea_Temp_Max from CQA_RH_Std_Proc where SteelGradeIndex = '%s'"),strSteelGradeIndex);
	}

	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
	{
		return iresult;
	}
	int itemp = rs.GetRowCount();
	if (itemp < 1)
	{
		return iresult;
	}
	rs.MoveFirst();

	L3LONG iLeaFir_Temp_Min = rs.GetFieldByIndex(0).ToLong();
	L3LONG iLeaFir_Temp_Max = rs.GetFieldByIndex(1).ToLong();
	L3LONG iLea_Temp_Min = rs.GetFieldByIndex(2).ToLong();
	L3LONG iLea_Temp_Max = rs.GetFieldByIndex(3).ToLong();

	if (iHeatNum == 1)
	{
		if ((iTempertaure > iLeaFir_Temp_Max) || ((iTempertaure < iLeaFir_Temp_Min)))
		{
			iresult = 0;
		}
		else
		{
			iresult = 1;
		}
	}
	else
	{
		if ((iTempertaure > iLea_Temp_Max) || ((iTempertaure < iLea_Temp_Min)))
		{
			iresult = 0;
		}
		else
		{
			iresult = 1;
		}
	}
	return iresult;	
}


//2009-02-28 ����������ʵ��Ĭ��Ϊ��һ¯��ʵ��

L3BOOL CCCM_Unit_Mag::GenProtectSlagInfor(LPCTSTR lpcszTreatNo)
{
	//�õ���һ¯�ţ������
	CString csPreTreatNo = GetPreviousTreatNo(lpcszTreatNo);
	CString PreHeatID = GetObjectPropValue(CCM_BASE_DATA_CLASS_URI+_T("\\")+csPreTreatNo,_T("HeatID")).ToCString();
	//����������
	CL3RecordSetWrap rsProtectSlag;
	if(!CreateClassPropSet(CCM_HEAT_PROTECTSLAG_CLASS_URI,rsProtectSlag))
		return false;
	rsProtectSlag.DelField(_T("GUID"));
	CString csTempSQL =_T(" select * from CCCM_Heat_ProtectSlag where HeatID = '%s' ");
	CString csSQL;
	csSQL.Format(csTempSQL,PreHeatID);
	CL3RecordSetWrap rsData;
	if(!Query(csSQL,rsData))
		return false;
	rsData.MoveFirst();
	if(rsData.GetRowCount() > 0)
	{
		rsProtectSlag.CopyFrom(rsData);
		rsProtectSlag.MoveFirst();
		while(!rsProtectSlag.IsEOF())
		{
			rsProtectSlag.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsProtectSlag.MoveNext();
		}
		if(CreateNewObjects(CCM_HEAT_PROTECTSLAG_CLASS_URI,rsProtectSlag) < rsProtectSlag.GetRowCount())
			return false;
	}
	//��������
	/*CL3RecordSetWrap rsSmoothBlock;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_SmoothBlock"),rsSmoothBlock))
		return false;
	rsSmoothBlock.DelField(_T("GUID"));
	csTempSQL =_T(" select * from CCCM_SmoothBlock where HeatID = '%s'");
	csSQL.Format(csTempSQL,PreHeatID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return false;
	rs.MoveFirst();
	if(rs.GetRowCount() > 0)
	{
		rsSmoothBlock.CopyFrom(rs);
		rsSmoothBlock.MoveFirst();
		while(!rsSmoothBlock.IsEOF())
		{
			rsSmoothBlock.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsSmoothBlock.MoveNext();
		}
		if(CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_SmoothBlock"),rsSmoothBlock) < rsSmoothBlock.GetRowCount())
			return false;
	}*/

	//ˮ������
	/*CL3RecordSetWrap rsWaterGap;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_WaterGap"),rsWaterGap))
		return false;
	rsWaterGap.DelField(_T("GUID"));
	csTempSQL =_T(" select * from CCCM_WaterGap where HeatID = '%s'");
	csSQL.Format(csTempSQL,PreHeatID);
	CL3RecordSetWrap rsWater;
	if(!Query(csSQL,rsWater))
		return false;
	rsWater.MoveFirst();
	if(rsWater.GetRowCount() > 0)
	{
		rsWaterGap.CopyFrom(rsWater);
		rsWaterGap.MoveFirst();
		while(!rsWaterGap.IsEOF())
		{
			rsWaterGap.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsWaterGap.MoveNext();
		}
		if(CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_WaterGap"),rsWaterGap) < rsWaterGap.GetRowCount())
			return false;
	}*/


	//���Ǽ�
	CL3RecordSetWrap rsCover;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_Heat_Cover"),rsCover))
		return false;
	rsCover.DelField(_T("GUID"));
	csTempSQL =_T(" select * from CCCM_Heat_Cover where HeatID = '%s'");
	csSQL.Format(csTempSQL,PreHeatID);
	CL3RecordSetWrap rsHeatCover;
	if(!Query(csSQL,rsHeatCover))
		return false;
	rsHeatCover.MoveFirst();
	if(rsHeatCover.GetRowCount() > 0)
	{
		rsCover.CopyFrom(rsHeatCover);
		rsCover.MoveFirst();
		while(!rsCover.IsEOF())
		{
			rsCover.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsCover.MoveNext();
		}
		if(CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_Heat_Cover"),rsCover) < rsCover.GetRowCount())
			return false;
	}

	
	//���¼�
	CL3RecordSetWrap rsHoldTempMat;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_Heat_HoldTempMat"),rsHoldTempMat))
		return false;
	rsHoldTempMat.DelField(_T("GUID"));
	csTempSQL =_T(" select * from CCCM_Heat_HoldTempMat where HeatID = '%s'");
	csSQL.Format(csTempSQL,PreHeatID);
	CL3RecordSetWrap rsHeatTemp;
	if(!Query(csSQL,rsHeatTemp))
		return false;
	rsHeatTemp.MoveFirst();
	if(rsHeatTemp.GetRowCount() > 0)
	{
		rsHoldTempMat.CopyFrom(rsHeatTemp);
		rsHoldTempMat.MoveFirst();
		while(!rsHoldTempMat.IsEOF())
		{
			rsHoldTempMat.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsHoldTempMat.MoveNext();
		}
		if(CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_Heat_HoldTempMat"),rsHoldTempMat) < rsHoldTempMat.GetRowCount())
			return false;
	}


	//������
	CL3RecordSetWrap rsStrandInfo;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo"),rsStrandInfo))
		return false;
	rsStrandInfo.DelField(_T("GUID"));
	rsStrandInfo.DelField(_T("Start_Time"));
	rsStrandInfo.DelField(_T("Stop_Time"));
	rsStrandInfo.DelField(_T("Heat_Weight"));
	rsStrandInfo.DelField(_T("Total_Weight"));

	csTempSQL =_T(" select * from CCCM_Heat_StrandInfo where HeatID = '%s'");
	csSQL.Format(csTempSQL,PreHeatID);
	CL3RecordSetWrap rsHeatStrand;
	if(!Query(csSQL,rsHeatStrand))
		return false;
	rsHeatStrand.MoveFirst();
	if(rsHeatStrand.GetRowCount() > 0)
	{
		//��ȡ�������2009-03-03
		/////////////////////////////
		CString strTundishNo = TundishNo;
		CString strFirst_Fra_ID,strSecond_Fra_ID,strThird_Fra_ID,strFourth_Fra_ID;
 		csTempSQL =_T("select First_Fra_ID,Second_Fra_ID,Third_Fra_ID,Fourth_Fra_ID from CTUNDISH_TFF_HOT_FIRE where WorkID in (select WorkID from CTundish_Base where TundishID in (select TundishID from CCCM_Tundish_Data where TundishNO = '%s'))");
		csSQL.Format(csTempSQL,strTundishNo);
		CL3RecordSetWrap rsTundishData;
		if(!Query(csSQL,rsTundishData))
			return false;
		rsTundishData.MoveFirst();
		if(rsTundishData.GetRowCount() > 0)
		{
			strFirst_Fra_ID = rsTundishData.GetFieldByName(_T("First_Fra_ID")).ToCString();
			strSecond_Fra_ID = rsTundishData.GetFieldByName(_T("Second_Fra_ID")).ToCString();
			strThird_Fra_ID = rsTundishData.GetFieldByName(_T("Third_Fra_ID")).ToCString();
			strFourth_Fra_ID = rsTundishData.GetFieldByName(_T("Fourth_Fra_ID")).ToCString();
		}
		//////////////////////////////
		rsStrandInfo.CopyFrom(rsHeatStrand);
		rsStrandInfo.MoveFirst();
		while(!rsStrandInfo.IsEOF())
		{
			//��ȡ�ᾧ�����,ͭ�ܱ��,����2009-03-03
			///////////////////begin////////////////////
			CString crStrandid = rsStrandInfo.GetFieldByName(_T("StrandID")).ToCString();
			L3SHORT iStrandid = 0;
			try
			{
				iStrandid = _ttoi(crStrandid);
			}
			catch(...)
			{
			}

			CL3RecordSetWrap rsMold = GetMoldData(crStrandid);
			if (rsMold.GetRowCount() > 0)
			{
				rsMold.MoveFirst();
				CString strMoldID,strCopper_ID,strCopper_Fac;
				strMoldID = rsMold.GetFieldByName(_T("MoldID")).ToCString();
				strCopper_ID = rsMold.GetFieldByName(_T("Copper_ID")).ToCString();
				strCopper_Fac = rsMold.GetFieldByName(_T("Copper_Fac")).ToCString();
                rsStrandInfo.SetFieldByName(_T("MoldID"),CL3Variant(strMoldID));
                rsStrandInfo.SetFieldByName(_T("Copper_Fac"),CL3Variant(strCopper_Fac));
                rsStrandInfo.SetFieldByName(_T("Copper_ID"),CL3Variant(strCopper_ID));
			}
			switch(iStrandid)
			{
			case 1:
				{	
					rsStrandInfo.SetFieldByName(_T("Code"),CL3Variant(strFirst_Fra_ID));
				}
				break;
			case 2:
				{	
					rsStrandInfo.SetFieldByName(_T("Code"),CL3Variant(strSecond_Fra_ID));
				}
				break;
			case 3:
				{	
					rsStrandInfo.SetFieldByName(_T("Code"),CL3Variant(strThird_Fra_ID));
				}
				break;
			case 4:
				{	
					rsStrandInfo.SetFieldByName(_T("Code"),CL3Variant(strFourth_Fra_ID));
				}
				break;
			default:
				{
				}
			}
			/////////////////////////end//////////////////////////////////
			rsStrandInfo.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
			rsStrandInfo.MoveNext();
		}
		if(CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo"),rsStrandInfo) < rsStrandInfo.GetRowCount())
			return false;
	}

	return true;
}

/// <Method class="CCCM_Unit_Mag" name="GetMoldData" type="">
/// ��ȡ�ᾧ������
/// </Method>
L3RECORDSET CCCM_Unit_Mag::GetMoldData(LPCTSTR lcpstrStrandId)
{
	CString cstrStrandId = lcpstrStrandId;
	CString csUnitID = GetIdentity().ToCString();
    CString csTeamp =_T("select MoldID,Copper_ID,Copper_Fac from CMold_Base where Status = '04' and Cast_ID = '%s' and FlowID = '%s'");
    CString csSQL;
	csSQL.Format(csTeamp,csUnitID,cstrStrandId);
	CL3RecordSetWrap rsMold;
	if(!Query(csSQL,rsMold) || rsMold.IsNull())
		return NULL;
	return rsMold.Detach();
}

/// <Method class="CCCM_Unit_Mag" name="CalculateStrandCaseWeight" type="L3BOOL">
/// ����¯��ͨ���� 2009-02-28
/// </Method>
L3BOOL CCCM_Unit_Mag::CalculateStrandCaseWeight()
{
	CString strHeatID = HeatID;
	CString strGUID;
	L3SHORT iStrandCount = 0;
	for (int i=1;i<5;i++)
	{
		strGUID = GetHeatStrandGUID(strHeatID,GetIdentity().ToCString(),i);
		if (strGUID.GetLength() > 1)
		{
			CString strObjectID = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo"),strGUID);
			L3LONG iOnOff = (GetObjectPropValue(strObjectID,_T("CastingStatus"))).ToLong();
			if (iOnOff == 1)
			{
				++iStrandCount;
			}
		}
	}

	L3DOUBLE castWeight = 0;
	if (iStrandCount > 0)
	{
		castWeight = SteelWeight / iStrandCount;
	}

	for (int i=1;i<5;i++)
	{
		strGUID = GetHeatStrandGUID(strHeatID,GetIdentity().ToCString(),i);
		if (strGUID.GetLength() > 1)
		{
			CString strObjectID = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo"),strGUID);
			L3LONG iOnOff = (GetObjectPropValue(strObjectID,_T("CastingStatus"))).ToLong();
			if (iOnOff == 1)
			{
				L3DOUBLE sumCastWeight = 0;
				switch (i)
				{
					case CCCM_Unit_Mag::ST1: 
						SumCastWeight1st = SumCastWeight1st + castWeight;
						sumCastWeight = SumCastWeight1st;
					break;
					case CCCM_Unit_Mag::ST2: 
						SumCastWeight2st = SumCastWeight2st + castWeight;
						sumCastWeight = SumCastWeight2st;
					break;
					case CCCM_Unit_Mag::ST3: 
						SumCastWeight3st = SumCastWeight3st + castWeight;
						sumCastWeight = SumCastWeight3st;
					break;
					case CCCM_Unit_Mag::ST4: 
						SumCastWeight4st = SumCastWeight4st + castWeight;
						sumCastWeight = SumCastWeight4st;
					break;
					default:
						break;
				}

				SetObjectPropValue(strObjectID,_T("Heat_Weight"),CL3Variant(castWeight));
				SetObjectPropValue(strObjectID,_T("Total_Weight"),CL3Variant(sumCastWeight));
			}
			else //2009-03-26
			{
				L3DOUBLE sumCastWeight = 0;
				switch (i)
				{
					case CCCM_Unit_Mag::ST1: 
						sumCastWeight = SumCastWeight1st;
					break;
					case CCCM_Unit_Mag::ST2: 
						sumCastWeight = SumCastWeight2st;
					break;
					case CCCM_Unit_Mag::ST3: 
						sumCastWeight = SumCastWeight3st;
					break;
					case CCCM_Unit_Mag::ST4: 
						sumCastWeight = SumCastWeight4st;
					break;
					default:
						break;
				}
				SetObjectPropValue(strObjectID,_T("Heat_Weight"),CL3Variant(0));
				SetObjectPropValue(strObjectID,_T("Total_Weight"),CL3Variant(sumCastWeight));
			}
		}
	}

	return TRUE;	
}


/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  ��ȡ���¯�� 2009-02-28 ����¯��
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3RECORDSET CCCM_Unit_Mag::GetPreThreeHeatID()
{
	CString strPrepareArea = GetPrepareArea();
	CL3Variant val = InvokeObjectMethod(strPrepareArea,_T("GetMaterialDetails"),_T("CSteel_Data"),_T(""));
	CL3RecordSetWrap rsSteel;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsSteel)) || rsSteel.GetRowCount() < 1)
	{
		SetL3LastError(XGMES_ERR_CCM_NEEDSTEEL);
		return NULL;
	}
	//�齨�������ݼ�
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsHeat; pRSRtn->QueryInterface(IID_IL3RecordSet,rsHeat); pRSRtn->Release();
	rsHeat.AddField(_T("HeatID"),VT_BSTR);
	rsSteel.MoveFirst();
	rsHeat.CopyFrom(rsSteel);
	return rsHeat.Detach();
}

/// <Method class="CCCM_Unit_Mag" name="ChangeCCMEquipment" type="L3BOOL">
/// ��������/ˮ��/���ˮ�� 2009-03-07[2009-03-08:Liao]
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::ChangeCCMEquipment(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return FALSE;

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	rs.MoveFirst();
	CString cstrClassName,cstrLifeProp;
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	COleDateTime dtcurTime = (DATE)curTime;
	while (!rs.IsEOF())
	{
		L3SHORT iEquipType = rs.GetFieldByName(_T("EquipmentType")).ToShort();
		L3LONG iStrandNo = rs.GetFieldByName(_T("StrandNo")).ToLong();
		CString csCCMID = rs.GetFieldByName(_T("CCMID")).ToCString();
		CString csReason =  rs.GetFieldByName(_T("Reason")).ToCString();
		switch (iEquipType)
		{
			case CCCM_Unit_Mag::SmoothBlock:
				{
					cstrClassName = _T("CCCM_SmoothBlock");
					cstrLifeProp = _T("Block_Life");
					//dttemp = rs.GetFieldByName(_T("Start_Time")).ToDateTime();
					rs.SetFieldByName(_T("Start_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
				}
				break;
			case CCCM_Unit_Mag::WaterGap: 
				{
					cstrClassName = _T("CCCM_WaterGap");
					cstrLifeProp = _T("GapLife");
					//dttemp = rs.GetFieldByName(_T("Start_Time")).ToDateTime();
					rs.SetFieldByName(_T("Start_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
				}
				break;
			case CCCM_Unit_Mag::BigWaterGap: 
				{
					cstrClassName = _T("CCCM_BigWaterGap");
					cstrLifeProp = _T("GapLife");
					//dttemp = rs.GetFieldByName(_T("ChangeTime")).ToDateTime();
					rs.SetFieldByName(_T("ChangeTime"),CL3Variant(COleDateTime::GetCurrentTime()));
				}
				break;
			default:
				if(nTrans > 0) Rollback(nTrans);
				return FALSE;
				break;
		}

		if (cstrClassName.GetLength()<1)
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}

		if ((iStrandNo < 1) || (iStrandNo > 4))
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}

		/*L3STRING strCCMID = csCCMID.AllocSysString();
		L3STRING strReason = csReason.AllocSysString();
		CalculateEquipmentLife(iEquipType,strCCMID,iStrandNo,strReason);
		L3SysFreeString(strCCMID);
		L3SysFreeString(strReason);*/

		if(csCCMID == _T(""))
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}

		CString strSql,csSQL;
		CString cstrPropName;
		switch (iEquipType)
		{
			case CCCM_Unit_Mag::SmoothBlock:
				{
					cstrPropName = _T("Start_Time");
        			strSql =_T("select GUID,Start_Time from (select GUID,Start_Time from CCCM_SmoothBlock where CCMID = '%s' and StrandNo = '%d' and Start_Time is not null order by Start_Time desc) where rownum < 2");
				
					csSQL.Format(strSql,csCCMID,iStrandNo);
				}
				break;
			case CCCM_Unit_Mag::WaterGap: 
				{
					cstrPropName = _T("Start_Time");
        			strSql =_T("select GUID,Start_Time from (select GUID,Start_Time from CCCM_WaterGap where CCMID = '%s' and StrandNo = '%d' and Start_Time is not null order by Start_Time desc) where rownum < 2");
				
					csSQL.Format(strSql,csCCMID,iStrandNo);
				}
				break;
			case CCCM_Unit_Mag::BigWaterGap: 
				{
					cstrPropName = _T("ChangeTime");
        			strSql =_T("select GUID,ChangeTime from (select GUID,ChangeTime from CCCM_BigWaterGap where CCMID = '%s'  and ChangeTime is not null order by ChangeTime desc) where rownum < 2");
				
					csSQL.Format(strSql,csCCMID);
				}
				break;
			default:
				break;
		}
		if (strSql.GetLength() < 1)
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}

		CL3RecordSetWrap rstemp;
		if(!Query(csSQL,rstemp))
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}

		L3LONG life = 0;
		CString csGUID;
		if(rstemp.GetRowCount() > 0)
		{
			rstemp.MoveFirst();
			CString LifeName ;
			switch (iEquipType)
			{
				case CCCM_Unit_Mag::SmoothBlock:
					LifeName = _T("Block_Life");
					break;
				case CCCM_Unit_Mag::WaterGap: 
					LifeName = _T("GapLife");
					break;
				case CCCM_Unit_Mag::BigWaterGap: 
					LifeName = _T("GapLife");
					break;
				default:
					break;
			}

			if(LifeName == _T(""))
			{
				rs.MoveNext();
				continue;
			}

			long loldLife = rstemp.GetFieldByName(LifeName).ToLong();

			if(loldLife > 0)
			{
				rs.MoveNext();
				continue;
			}

			csGUID = rstemp.GetFieldByName(_T("GUID")).ToCString();
			COleDateTime dtlastChangeTime = (rstemp.GetFieldByName(cstrPropName)).ToDateTime();

			COleDateTimeSpan span = dtcurTime - dtlastChangeTime;
			life = (LONG)span.GetTotalMinutes();

			switch (iEquipType)
			{
				case CCCM_Unit_Mag::SmoothBlock:
						if(!SetObjectPropValue(CCM_SMOOTHBLOCK_CLASS_URI +_T("\\") + csGUID,_T("Block_Life"),CL3Variant(life))
							|| !SetObjectPropValue(CCM_SMOOTHBLOCK_CLASS_URI +_T("\\") + csGUID,_T("Reason"),CL3Variant(csReason)))
						{
							if(nTrans > 0) Rollback(nTrans);
							return FALSE;
						}

					break;

				case CCCM_Unit_Mag::WaterGap: 
					if(!SetObjectPropValue(CCM_WATERGAP_CLASS_URI +_T("\\") + csGUID,_T("GapLife"),CL3Variant(life))
						|| !SetObjectPropValue(CCM_WATERGAP_CLASS_URI +_T("\\") + csGUID,_T("Reason"),CL3Variant(csReason)))
							{
								if(nTrans > 0) Rollback(nTrans);
								return FALSE;
							}

					break;

				case CCCM_Unit_Mag::BigWaterGap: 
					if(!SetObjectPropValue(CCM_BIGWATERGAP_CLASS_URI +_T("\\") + csGUID,_T("GapLife"),CL3Variant(life))
						|| !SetObjectPropValue(CCM_BIGWATERGAP_CLASS_URI +_T("\\") + csGUID,_T("Reason"),CL3Variant(csReason)))
							{
								if(nTrans > 0) Rollback(nTrans);
								return FALSE;
							}

					break;
				default:
					break;
			}
		}

		rs.SetFieldByName(cstrLifeProp,(L3LONG)0);
		rs.SetFieldByName(_T("Reason"),CL3Variant(_T("")));//��ǰ̨���뻻��ԭ��ɾ��

		rs.MoveNext();
	}

	CL3RecordSetWrap rstemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\")+cstrClassName,rstemp))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rstemp.CopyFrom(rs);

	rstemp.DelField(_T("GUID"));
	rstemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\CCMMag\\")+cstrClassName,rstemp) < rstemp.GetRowCount())
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="CalculateEquipmentLife" type="L3LONG">
/// �����豸���� 2009-03-07[2009-03-08:Liao]
/// <Param name="iEquipType" type="L3LONG">����/ˮ��/���ˮ��</Param>
/// <Param name="iStrandNo" type="L3LONG">����</Param>
/// <Param name="dtChangeTime" type="L3DATETIME">���ʱ��</Param>
/// </Method>
L3LONG CCCM_Unit_Mag::CalculateEquipmentLife(L3LONG iEquipType,L3STRING strCCMID,L3LONG iStrandNo,L3STRING strReason)
{
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString csCCMID = strCCMID;
	CString csReason = strReason;
	COleDateTime dtcurTime = (DATE)curTime;
	if(csCCMID == _T(""))
		return 0;

	CString strSql,csSQL;
	CString cstrPropName;
	switch (iEquipType)
	{
		case CCCM_Unit_Mag::SmoothBlock:
			{
				cstrPropName = _T("Start_Time");
        		strSql =_T("select GUID,Start_Time from (select GUID,Start_Time from CCCM_SmoothBlock where CCMID = '%s' and StrandNo = '%d' and Start_Time is not null  order by Start_Time desc) where rownum < 2");
			
				csSQL.Format(strSql,csCCMID,iStrandNo);
			}
			break;
		case CCCM_Unit_Mag::WaterGap: 
			{
				cstrPropName = _T("Start_Time");
        		strSql =_T("select GUID,Start_Time from (select GUID,Start_Time from CCCM_WaterGap where CCMID = '%s' and StrandNo = '%d' and Start_Time is not null  order by Start_Time desc) where rownum < 2");
			
				csSQL.Format(strSql,csCCMID,iStrandNo);
			}
			break;
		case CCCM_Unit_Mag::BigWaterGap: 
			{
				cstrPropName = _T("ChangeTime");
        		strSql =_T("select GUID,ChangeTime from (select GUID,ChangeTime from CCCM_BigWaterGap where CCMID = '%s' and ChangeTime is not null  order by ChangeTime desc) where rownum < 2");
			
				csSQL.Format(strSql,csCCMID);
			}
			break;
		default:
			break;
	}
	if (strSql.GetLength() < 1)
		return -1;

	CL3RecordSetWrap rstemp;
	if(!Query(csSQL,rstemp))
		return -2;

	L3LONG life = 0;
	CString csGUID;
	if(rstemp.GetRowCount() > 0)
	{
		rstemp.MoveFirst();
		CString LifeName ;
		switch (iEquipType)
		{
			case CCCM_Unit_Mag::SmoothBlock:
				LifeName = _T("Block_Life");
				break;
			case CCCM_Unit_Mag::WaterGap: 
				LifeName = _T("GapLife");
				break;
			case CCCM_Unit_Mag::BigWaterGap: 
				LifeName = _T("GapLife");
				break;
			default:
				break;
		}
		long loldLife = rstemp.GetFieldByName(LifeName).ToLong();
		if(loldLife > 0)
			return 1;
		csGUID = rstemp.GetFieldByName(_T("GUID")).ToCString();
		COleDateTime dtlastChangeTime = (rstemp.GetFieldByName(cstrPropName)).ToDateTime();

		COleDateTimeSpan span = dtcurTime - dtlastChangeTime;
		life = (LONG)span.GetTotalMinutes();
	}
	if(csGUID.Trim() == _T(""))
		return 0;
		
	switch (iEquipType)
	{
		case CCCM_Unit_Mag::SmoothBlock:
				if(!SetObjectPropValue(CCM_SMOOTHBLOCK_CLASS_URI +_T("\\") + csGUID,_T("Block_Life"),CL3Variant(life))
					|| !SetObjectPropValue(CCM_SMOOTHBLOCK_CLASS_URI +_T("\\") + csGUID,_T("Reason"),CL3Variant(csReason)))
					return -3;
			break;

		case CCCM_Unit_Mag::WaterGap: 
			if(!SetObjectPropValue(CCM_WATERGAP_CLASS_URI +_T("\\") + csGUID,_T("GapLife"),CL3Variant(life))
				|| !SetObjectPropValue(CCM_WATERGAP_CLASS_URI +_T("\\") + csGUID,_T("Reason"),CL3Variant(csReason)))
					return -3;
			break;

		case CCCM_Unit_Mag::BigWaterGap: 
			if(!SetObjectPropValue(CCM_BIGWATERGAP_CLASS_URI +_T("\\") + csGUID,_T("GapLife"),CL3Variant(life))
				|| !SetObjectPropValue(CCM_BIGWATERGAP_CLASS_URI +_T("\\") + csGUID,_T("Reason"),CL3Variant(csReason)))
					return -3;
			break;
		default:
			break;
	}
	return life;
}

/// <Method class="CCCM_Unit_Mag" name="CalculateRemainCastingTime" type="L3BOOL">
/// ����ʣ�ཽעʱ�� 2009-03-20
/// </Method>
L3BOOL CCCM_Unit_Mag::CalculateRemainCastingTime()
{
	if (RemainedWeight < 0.1)
	{
		return FALSE;
	}
    //��ȡ����
	CString strSql,csSQL;
    strSql =_T("select Width,Thickness from CPlan_Tapping where HeatID = '%s'");
	csSQL.Format(strSql,HeatID);
	CL3RecordSetWrap rstemp;
	if(!Query(csSQL,rstemp))
		return FALSE;

	L3LONG width = 0;
	L3LONG thickness = 0;
	if(rstemp.GetRowCount() > 0)
	{
		rstemp.MoveFirst();
		width = rstemp.GetFieldByName(_T("Width")).ToLong();
		thickness = rstemp.GetFieldByName(_T("Thickness")).ToLong();
	}

	if ((width == 0) || (thickness == 0))
	{
		return FALSE;
	}

    L3DOUBLE ftemp = (width) * (thickness) * (Speed1st + Speed2st + Speed3st + Speed4st) * 7/(1000*1000);

	if (ftemp > 0)
	{
		RemainCastingTime =	int(RemainedWeight / ftemp);
	}
	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="SetTundishTempInValidFlag" type="L3BOOL">
/// �����а��¶���Ч��־ 2009-03-25
/// </Method>
L3BOOL CCCM_Unit_Mag::SetTundishTempInValidFlag(LPCTSTR strHeatID,LPCTSTR strCCMID)
{
	CString csHeatID = strHeatID;
	CString csCCMID = strCCMID;
    //��ȡ����
	CString strSql,csSQL;
    strSql =_T("select * from CCCM_Heat_TundishTemp where HeatID = '%s' and CCMID = '%s' order by Measure_Time desc");
	csSQL.Format(strSql,csHeatID,csCCMID);
	CL3RecordSetWrap rstemp;
	if(!Query(csSQL,rstemp))
		return FALSE;

	if(rstemp.GetRowCount() < 1)
	{
		return TRUE;
	}

	rstemp.MoveFirst();
	CString csGUID = rstemp.GetFieldByName(_T("GUID")).ToCString();
	COleDateTime dMeasureTime = (rstemp.GetFieldByName(_T("Measure_Time"))).ToDateTime();
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	COleDateTimeSpan span = curTime - dMeasureTime;
	LONG itimespan = (LONG)span.GetTotalMinutes();
	if (itimespan < 1)
	{
		SetObjectPropValue(_T("XGMESLogic\\CCMMag\\CCCM_Heat_TundishTemp\\") + csGUID,_T("InValidFlag"),CL3Variant((L3SHORT)1));
	}

	return TRUE;
}

/// <Method class="CCCM_Unit_Mag" name="SendSteelWeightToPLC" type="L3BOOL">
/// ����ˮ�����´�PLC 2009-03-26
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL  CCCM_Unit_Mag::SendSteelWeightToPLC(L3FLOAT fSteelWeight)
{
	//�齨���ݼ�
	CString csCCMID = GetIdentity().ToCString();
	
	//Modify begin by llj 2011-1-26 Add CCM7
	//if (csCCMID == _T("S65")) ���δ��޸�Ϊ�������
	if (csCCMID == _T("S65")||csCCMID == _T("S67"))
	//Modify end
	{
		return false;
	}

	CL3RecordSet *pRSheet = new CL3RecordSet();
	CL3RecordSetWrap rsWeight; pRSheet->QueryInterface(IID_IL3RecordSet,rsWeight); rsWeight->Release();
	rsWeight.AddField(_T("CCMID"),VT_BSTR);
	rsWeight.AddField(_T("Weight"),VT_R8);
	rsWeight.AddField(_T("Permit_Delete_Flag"),VT_INT);

	rsWeight.AppendRecord();
	rsWeight.SetFieldByName(_T("CCMID"),CL3Variant(csCCMID));
	rsWeight.SetFieldByName(_T("Weight"),CL3Variant(fSteelWeight));
	rsWeight.SetFieldByName(_T("Permit_Delete_Flag"),L3LONG(1));

	L3LONG nPosID = 1;
	CString csTableName = _T("CCM_PLCSteelWeight");
	L3STRING strTableName = csTableName.AllocSysString();
	InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
					    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
						strTableName,(L3RECORDSET)rsWeight);
	L3SysFreeString(strTableName);

	return true;
}


/// <Method class="CCCM_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
/// ����ĸ�2009-04-15
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::ChangeSteelGradeApp(L3STRING Reason)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_EXE_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	CString csTreatNo =GetPropValue(_T("TreatNo")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(CCM_BASE_DATA_CLASS_URI,csTreatNo);
	CString csHeatID = GetObjectPropValue(csUri,_T("HeatID")).ToCString();
	csHeatID.Trim();
	if(csHeatID.IsEmpty())
		return false;
	CString csSteelUri =  CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,csHeatID);
	rsSteel.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rsSteel.SetFieldByName(_T("PreHeatID"),GetObjectPropValue(csSteelUri,_T("PreHeatID")));
	rsSteel.SetFieldByName(_T("SteelGradeIndex"),GetObjectPropValue(csSteelUri,_T("SteelGradeIndex")));
	rsSteel.SetFieldByName(_T("App_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsSteel.SetFieldByName(_T("App_Steel_Weight"),GetObjectPropValue(csSteelUri,_T("Weight")));
	rsSteel.SetFieldByName(_T("App_Operator"),CL3Variant(GetCurrentUser()));
	rsSteel.SetFieldByName(_T("App_UnitID"),GetIdentity());
	rsSteel.SetFieldByName(_T("App_Reason"),CL3Variant(Reason));

	CString strDispMag =DISPATCH_OBJ_URI;
	CL3Variant val = InvokeObjectMethod(strDispMag,_T("SteelExchangeApp"),(L3RECORDSET)rsSteel);
	return val.ToBOOL();

}

/// <Method class="CCCM_Unit_Mag" name="ModifyStrandStatusData" type="L3LONG">
/// �޸�������״̬���� 2009-04-18
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CCCM_Unit_Mag::ModifyStrandStatusData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount = rs.GetRowCount();
	if(rsCount < 1)
		return -1;

	rs.MoveFirst();
	for(int i=0;i<rsCount;i++) 
	{
		CString strCCMID = GetIdentity().ToCString();
		L3LONG iStrandNo = rs.GetFieldByName(_T("StrandNo")).ToLong();  //��ȡ����
		L3LONG iStrandStatus = rs.GetFieldByName(_T("OnOff")).ToLong(); //��ȡ��״̬

		L3LONG iStatus = Status;
		CString strHeatID = HeatID;
		if(strHeatID.GetLength() < 9)
		{
			cstrStopCastingHeatID = PrevHeatID;//2009-04-30
			if (cstrStopCastingHeatID.GetLength() == 9)
			{
				strHeatID = cstrStopCastingHeatID;
			}
			else
			{
				return -2;
			}
		}

		switch (iStrandNo)
		{
			case CCCM_Unit_Mag::ST1: 
				OnOff1st=iStrandStatus;
			break;
			case CCCM_Unit_Mag::ST2: 
				OnOff2st=iStrandStatus;
			break;
			case CCCM_Unit_Mag::ST3: 
				OnOff3st=iStrandStatus;
			break;
			case CCCM_Unit_Mag::ST4: 
				OnOff4st=iStrandStatus;
			break;
			default:
				break;
		}

		if (strHeatID.GetLength() > 0) 
		{
			CString strGUID = GetHeatStrandGUID(strHeatID,strCCMID,iStrandNo);
			if (strGUID.GetLength() > 1)
			{
        		CString strObjectID = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo"),strGUID);
				if (iStrandStatus == 0) //ͣ��:����ͣ��ʱ��
				{
					SetObjectPropValue(strObjectID,_T("Stop_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
					SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((L3LONG)0));//2009-04-25
				}
				else //����:���ÿ���ʱ��
				{
					SetObjectPropValue(strObjectID,_T("Start_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
					SetObjectPropValue(strObjectID,_T("CastingStatus"),CL3Variant((L3LONG)1));//2009-04-25
					switch (iStrandNo)
					{
						case CCCM_Unit_Mag::ST1: 
							SetObjectPropValue(strObjectID,_T("Cast_Num"),CL3Variant((L3LONG)(++CastNum1ST)));
						break;
						case CCCM_Unit_Mag::ST2: 
							SetObjectPropValue(strObjectID,_T("Cast_Num"),CL3Variant((L3LONG)(++CastNum2ST)));
						break;
						case CCCM_Unit_Mag::ST3: 
							SetObjectPropValue(strObjectID,_T("Cast_Num"),CL3Variant((L3LONG)(++CastNum3ST)));
						break;
						case CCCM_Unit_Mag::ST4: 
							SetObjectPropValue(strObjectID,_T("Cast_Num"),CL3Variant((L3LONG)(++CastNum4ST)));
						break;
						default:
							break;
					}
				}
			}
		}
		rs.MoveNext();
	}
	
	return 1;	
}

/// <Method class="CCCM_Unit_Mag" name="AcceptCCMTundishTempData" type="L3BOOL">
/// ��������������2�����а��������� 2009-06-02
/// ����6#CCM���ɹ��ô˷���hyh 2012-05-09
/// <Param name="rsData" type="L3RECORDSET">�а���������</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptCCMTundishTempForRefine(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return FALSE;

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\CCMMag\\CCCM_TundishTemp_TwoMinute"),rsTemp))
		return FALSE;

	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("CCMID"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("CastingNo"),CL3Variant(CastingNo));
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("TreatNo"),CL3Variant(TreatNo));
		rsTemp.SetFieldByName(_T("Measure_Time"),CL3Variant(COleDateTime::GetCurrentTime()));	
		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\CCMMag\\CCCM_TundishTemp_TwoMinute"),rsTemp) < rsTemp.GetRowCount())
		return FALSE;

	return TRUE;	
}


/// <Method class="CCCM_Unit_Mag" name="AcceptTundishWeightData" type="L3BOOL">
/// ���������а���ˮ�������� 2009-01-03
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CCCM_Unit_Mag::AcceptTundishWeightData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveFirst();
    CString csTreatNo =GetPropValue(_T("TreatNo")).ToCString();
	CString csHeatLadleUri = CCM_HEAT_LADLE_CLASS_URI + _T("\\") + csTreatNo;
	L3DOUBLE fSteelWeight = (rs.GetFieldByName(_T("TundishWeight"))).ToDouble();
	SetObjectPropValue(csHeatLadleUri,_T("CastingTundishWeight"),CL3Variant(fSteelWeight));
	
	return TRUE;	
}

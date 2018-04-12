// �߼���CBOF_Unit_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CBOF_Unit_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CBOF_Unit_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CBOF_Unit_Mag.h"
#include "L3NameParser.h"

#define BLOWTIMER_PERIOD		5000
#define BLOWTIME		5

//������װ�ص�ϵͳ��ʱ��������
void CBOF_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CBOF_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ���ػ���ļӹ�����
/// ARG << lstURIs : �������мӹ��������URI
/// </summary>
BOOL CBOF_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	CString strURI;
	strURI.Format(_T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\%s"),GetIdentity().ToCString());
	lstURIs.AddHead(strURI);
	return TRUE;
}

/// <summary>
/// �õ�����ǰ����ϻ�������URI
/// </summary>
CString CBOF_Unit_Mag::GetInputCache()
{
	return MIXFProduceCache_URI;
}

/// <summary>
/// �õ������̲��ϻ�������URI
/// </summary>
CString CBOF_Unit_Mag::GetOutputCache()
{
	CString strURI;
	CString strID = GetIdentity().ToCString();
	CString strIdx = strID.Right(1);
	strURI.Format(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S3%sP01"),strIdx);
	return strURI;
}

/// <summary>
/// ��������ǰԤ�����ڻ�������ǰ���ã��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << ����TRUE�������ϣ�����FALSE�ж����ϡ�
/// </summary>
BOOL CBOF_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// �������Ϻ��������ڻ������Ϻ���ã��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBOF_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// ���ػ������ϼ�¼������URI
/// </summary>
CString CBOF_Unit_Mag::GetFeedingLogType()
{
	return _T("");
}


/// <summary>
/// ׼�����ϼ�¼���ݡ��̳�������ش˺������ж�������ݴ���
/// ARG >> rsFeedingLogs : ���ϼ�¼��Ϣ��
/// RET << void
/// </summary>
void CBOF_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
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
BOOL CBOF_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
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
BOOL CBOF_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// ����ǰԤ������ִ�����߲���ǰ���ã��̳�������ش˺�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << ����TRUE�������ߣ�����FALSE�ж����ߡ�
/// </summary>
BOOL CBOF_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// ���ߺ���������ִ�����߲�������ã��̳�������ش˺������ж��⴦��
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBOF_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsDelivered( rsMaterialInfo);
}


/// <summary>
/// ���ػ��������¼������URI
/// </summary>
CString CBOF_Unit_Mag::GetDeliveryLogType()
{
	return _T("");
}


/// <summary>
/// ׼�����ϼ�¼���ݡ�
/// ARG >> rsDeliveryLog : ���ϼ�¼���ݡ�
/// RET <<void
/// </summary>
void CBOF_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// ���ر������ͨѶ�������URI
/// </summary>
CString CBOF_Unit_Mag::GetCommunicator()
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
BOOL CBOF_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// �ƻ��´��������������λϵͳ���ͼƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsSend : �·���λϵͳ�ļƻ����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBOF_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
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
BOOL CBOF_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// �ƻ�ȡ����������������λϵͳ����ȡ���ƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsCancel : �·���λϵͳ�ļƻ�ȡ�����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBOF_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// ����������ߵ��¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CBOF_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// ������Ͻ���ӹ�������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CBOF_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// ��������뿪�ӹ������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CBOF_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// ���������������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CBOF_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// �������������ݱ���¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CBOF_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}

	



/// <Method class="CBOF_Unit_Mag" name="GetScrapesForDesignate" type="L3RECORDSET">
/// ��ȡ��ѡ�ϸ���Ϣ��¼�����ش��зϸֲۺźͷϸ����ļ�¼����
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetScrapesForDesignate()
{
	////2009-02-21*Liao
	//CString cssss = _T("select Scrap_Slot_ID,sum(Amount) as Amount,sum(decode(StoreAreaID,'S82A01',Amount,0)) as ScrapWT,");
	//cssss += _T(" sum(Amount)-sum(decode(StoreAreaID,'S82A01',Amount,0)) as PigIronWT,LogDate from CScrap_Output_Log where Iron_Flag = 0 group by Scrap_Slot_ID,LogDate Order by LOGDATE");
	//CString strSQL;
	////strSQL.Format(_T("select Scrap_Slot_ID,sum(Amount) as Amount sum(decode(StoreAearID))from %s where Iron_Flag = 0 group by Scrap_Slot_ID"),SCRAP_OUT_CLASS_URI);
	//strSQL.Format(cssss,SCRAP_OUT_CLASS_URI);
	//
	//CL3RecordSetWrap rs;
	//if(!Query(strSQL,rs))
	//	return NULL;
	//else
	//	return rs.Detach();

  //2016-01-27 ren

		CString cssss = _T("select Scrap_Slot_ID,sum(Amount) as Amount,sum(decode(StoreAreaID,'S82A01',Amount,0)) as ScrapWT,");
	cssss += _T(" sum(Amount)-sum(decode(StoreAreaID,'S82A01',Amount,0)) as PigIronWT,LogDate from CScrap_Output_Log where Iron_Flag = 0   group by Scrap_Slot_ID,LogDate Order by LOGDATE");
	//cssss += _T(" sum(Amount)-sum(decode(StoreAreaID,'S82A01',Amount,0)) as PigIronWT,LogDate from   CScrap_Output_Log  where Iron_Flag = 0 and  Scrap_Slot_ID   not like 'B%' group by Scrap_Slot_ID,LogDate Order by LOGDATE");
	/*CString strSQL;*/

	//strSQL.Format(_T("select Scrap_Slot_ID,sum(Amount) as Amount sum(decode(StoreAearID))from %s where Iron_Flag = 0 group by Scrap_Slot_ID"),SCRAP_OUT_CLASS_URI);
	//strSQL.Format(cssss,SCRAP_OUT_CLASS_URI);
	
	CL3RecordSetWrap rs;
	if(!Query(cssss,rs))
		return NULL;
	else
		return rs.Detach();

}

/// ������һ¯��
CString CBOF_Unit_Mag::CalculateNextHeatID (LPCTSTR lpcszHeatID)
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

/// �Ӽƻ����ȡ��һ¯��
CString CBOF_Unit_Mag::FindNextHeatIDFromPlan()
{
	//2008-12-26¯�Ÿ�Ϊ�Ӽƻ���ȡ��tangyi
	CString csUnitID = GetIdentity().ToCString();
	CString csSQL;
	csSQL.Format(_T("select min(HeatID) from CPlan_Tapping where Status ='%s' and BOFID ='%s' "),TAPPING_PLAN_STATUS_SEND,csUnitID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return _T("");
	rs.MoveFirst();
	return rs.GetFieldByIndex(0).ToCString();
}

/// ͨ��ת¯����״̬�޸ĺ���
BOOL CBOF_Unit_Mag::ChangeBOFStatus(LONG nStatus)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// �޸�ת¯״̬
	if ((nStatus < CBOF_Unit_Mag::BOFSplash) || (Status >= CBOF_Unit_Mag::BOFTapped)) //2009-01-09�����ֽ���״̬δ�����ҽ����������źŵ���ʱ,ֻ��¼״̬��Ϣ,�����ת¯״̬
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
	if(!CreateClassPropSet(BOF_PROC_STATUS_CLASS_URI,rsStatus))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsStatus.AppendRecord();

	if (nStatus == CBOF_Unit_Mag::BOFWaiting)
	  rsStatus.SetFieldByName(_T("HeatID"),GetPropValue(_T("NextHeatID")));
	else
      rsStatus.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));

	rsStatus.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsStatus.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	if(CreateNewObjects(BOF_PROC_STATUS_CLASS_URI,rsStatus) < 1)
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
BOOL CBOF_Unit_Mag::ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status)
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
	rsPlanStatus.SetFieldByName(_T("UnitType"),CL3Variant(_T("2")));
	rsPlanStatus.SetFieldByName(_T("TreatNo"),CL3Variant(lpcszTreatNo));
	rsPlanStatus.SetFieldByName(_T("UnitStatus"),CL3Variant(Status));
	rsPlanStatus.SetFieldByName(_T("StatusChangeTime"),CL3Variant(COleDateTime::GetCurrentTime()));
	CL3Variant valRet = InvokeObjectMethod(PLAN_OBJ_URI,_T("ModifyPlanExecutionStatus"),(L3RECORDSET)rsPlanStatus);
	return valRet.ToBOOL();
}


/// <Method class="CBOF_Unit_Mag" name="FeedIrons" type="L3BOOL">
/// ���ж�����ʹ������ָ������ˮ�ͷϸֶ����ж�����
/// </Method>
///2009-02-28 ���ϸ�ʵ�ʵ���Ҫ���Զ����߼�������޸ģ�ָ����ԭ�Ϸ��ڶ���֮��
L3BOOL CBOF_Unit_Mag::FeedIrons()
{
	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return FALSE;

	// ������ת¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		Rollback(nTrans);
		return FALSE;
	}

	//���ת¯�ƻ��������С��3��������ʾ
	CString csUnitID = GetIdentity().ToCString();
	CString csTempSQL =_T(" select count(*) as PlanCount from CPlan_Tapping where status = %s and BOFID ='%s' ");
	CString csSQL;
	csSQL.Format(csTempSQL,TAPPING_PLAN_STATUS_SEND,csUnitID);
	CL3RecordSetWrap rsPlanCount;
	if(!Query(csSQL,rsPlanCount))
	{
		Rollback(nTrans);
		return FALSE;
	}
	rsPlanCount.MoveFirst();
	L3LONG nPlanCount = rsPlanCount.GetFieldByIndex(0).ToLong();
	if(nPlanCount < 3)
	{
		//�ı�����ֵ֪ͨ���ȼ�ʱ�¼ƻ� 2009-03-03 tangyi
		CL3Variant varStoreEvent = GetPropValue(_T("Plan_Count"));
		L3SHORT nStoreEvent = varStoreEvent.ToShort();
		nStoreEvent = (nStoreEvent+1) % 9999;
		SetPropValue(_T("Plan_Count"),nStoreEvent);
	}

	// ���ת¯״̬,δ������׼�����������
	if(Status != CBOF_Unit_Mag::BOFWaiting)
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	CString strHeatID = NextHeatID;

	// ¯�ű��
	HeatID = NextHeatID;

	//������һ¯��2009-03-26 tangyi����ʱ������һ¯�ţ����ڼ����������Ӽƻ��л�ȡ
	NextHeatID = CalculateNextHeatID(strHeatID);

	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ��ѯ��Ӧ���ּƻ�����
	CString strSQLPlan; strSQLPlan.Format(_T("select * from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,GetRealHeatID(strHeatID));
	CL3RecordSetWrap rsPlan;
	if(!Query(strSQLPlan,rsPlan) || rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
	{	// �ƻ�������
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_PLANNOTEXIST);
		return FALSE;
	}

	rsPlan.MoveFirst();

	// �޸ĵ�ǰת¯����
	SteelGradeIndex = rsPlan.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	

	// ����ת¯¯�λ�������CBOF_Base_Data
	CL3RecordSetWrap rsBaseData;
	if(!CreateClassPropSet(BOF_BASE_DATA_CLASS_URI,rsBaseData))
	{
		Rollback(nTrans);
		return FALSE;
	}
	rsBaseData.AppendRecord();
	rsBaseData.CopyCurRowFrom(rsPlan);
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
	if(CreateNewObjects(BOF_BASE_DATA_CLASS_URI,rsBaseData) < 1)
	{
		Rollback(nTrans);
		return FALSE;
	}

	// ������������
	CL3RecordSetWrap rsProc;
	if(!CreateClassPropSet(BOF_PROCESS_DATA_CLASS_URI,rsProc))
	{
		Rollback(nTrans);
		return FALSE;
	}
	rsProc.AppendRecord();
	rsProc.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	rsProc.SetFieldByName(_T("Charging_Start_Time"),CL3Variant(curTime));
	if(!CreateNewObjects(BOF_PROCESS_DATA_CLASS_URI,rsProc))
	{
		Rollback(nTrans);
		return FALSE;
	}

	// �޸�ת¯״̬
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFFeeding))
	{
		Rollback(nTrans);
		return FALSE;
	}

	// ����¯��������ʼ�ȼ�
	rsPlan.MoveFirst();
	InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQuality_Mag\\Quality_Mag"),_T("CreateHeatGradeQAData"),(LPCTSTR)GetName(),(L3RECORDSET)rsPlan);


	// ���ô���ʱ��
	BlowTotalTime = 0;
	BlowThisTime = 0;

	Commit(nTrans);

	// �޸ļƻ�״̬
	ChangePlanStatus(strHeatID,strHeatID,TAPPING_PLAN_BOF_STATUS_IRON);

	/// ��컯�鷢�ͽ�����Ϣ2009-01-03 tangyi
	L3STRING strBOFHeatID = HeatID.AllocSysString();
	SendCastingDataToAnaL2(strBOFHeatID);
	L3SysFreeString(strBOFHeatID);

	return TRUE;
}


/// <Method class="CBOF_Unit_Mag" name="DesignateIrons" type="L3LONG">
/// ָ����ԭ��
/// <Param name="rsIrons" type="L3RECORDSET">��ˮ��Ϣ,Ӧ���ٰ���MaterialID</Param>
///2009-02-28
/// </Method>
L3LONG CBOF_Unit_Mag::DesignateMainMaterial(L3RECORDSET rsIrons,L3RECORDSET rsReturnSteel,L3RECORDSET rsScrapes)
{
	CL3RecordSetWrap rsIron = rsIrons;
	if(rsIron.GetRowCount() < 1)
		return -1;

	// �������
	if(rsIron.GetFieldIndex(_T("MaterialID")) < 0 || rsIron.GetFieldIndex(_T("HeatID")) < 0 )
		return -2;

	CL3RecordSetWrap rsRtnSteel = rsReturnSteel;
	if(rsRtnSteel.GetRowCount() != 1)
		return -3;

	// �������
	if(rsRtnSteel.GetFieldIndex(_T("HeatID")) < 0 || rsRtnSteel.GetFieldIndex(_T("Return_Steel_Weight")) < 0 )
		return -4;


	CL3RecordSetWrap rsScrap = rsScrapes;
	if(rsScrap.GetRowCount() > 0)
	{
		// �������
		if(rsScrap.GetFieldIndex(_T("Scrap_Slot_ID")) < 0)
			return -5;
	}


	// ��鵱ǰת¯״̬,���ֽ�����ǰ������ָ����ԭ��
	if(Status < CBOF_Unit_Mag::BOFFeeding || Status > CBOF_Unit_Mag::BOFTapping)
		return -6;


	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -7;
	}

	// ������ת¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -8;
	}

	//��ȡ¯��
	CString strHeatID =HeatID;

	// ����ϸֺ�������
	double ScrapeWeight = 0, PigIronWeight = 0;

	if(rsScrap.GetRowCount() > 0)
	{
		// ׼���ϸֶ�����
		CString strSlots;
		rsScrap.MoveFirst();
		while(!rsScrap.IsEOF())
		{
			if(!strSlots.IsEmpty())
				strSlots += _T(",");
			strSlots += CString(_T("'")) + rsScrap.GetFieldByName(_T("Scrap_Slot_ID")).ToCString() + CString(_T("'"));
			rsScrap.MoveNext();
		}

		// ��ѯ�ϸ����������¼
		CString strSQL;
		strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag from %s where Iron_Flag = 0 and Scrap_Slot_ID in (%s)"),SCRAP_OUT_CLASS_URI,strSlots);
		CL3RecordSetWrap rsLog;
		if(!Query(strSQL,rsLog))
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -12;
		}
		// �޸ķϸ����������¼
		rsLog.MoveFirst();
		while(!rsLog.IsEOF())
		{
			rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
			rsLog.SetFieldByName(_T("Iron_Flag"),CL3Variant((LONG)1));
			rsLog.MoveNext();
		}
		rsLog.MoveFirst();
		if(!SetObjsPropValues(SCRAP_OUT_CLASS_URI,rsLog))
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -13;
		}

		// ��ȡ��ָ���ķϸ���������Ϣ
		CL3RecordSetWrap rsScrapDesignated;
		rsScrapDesignated.Attach(GetInputScrapes());
		
		rsScrapDesignated.MoveFirst();
		while(!rsScrapDesignated.IsEOF())
		{
			// ���ݳ�����Դ��λ���ж��Ƿϸֻ�������
			CString strAreaID = rsScrapDesignated.GetFieldByName(_T("StoreAreaID")).ToCString();
			double fW = rsScrapDesignated.GetFieldByName(_T("Amount")).ToDouble();
			if(strAreaID == _T("S82A01"))
			{	// �ϸֿ���
				ScrapeWeight += fW;
			}
			else
			{	// ��������
				PigIronWeight += fW;
			}
			rsScrapDesignated.MoveNext();
		}
	}


	// ����ת¯¯��ԭ������CBOF_Feed_Data
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

	// ����ˮ���ߣ�����ת¯������
	rsIronsDesignated.MoveFirst();
	if(!FeedMaterials(rsIronsDesignated))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -11;
	}
   
	// ������������ɷ�
	double C=0,Si=0,Mn=0,P=0,S=0,Ti=0,Temp=0;
	double Sn=0,Sb=0,As=0,Pb=0;//add by hyh 2012-04-05

	double IronWeight = 0;//2009-02-16 tangyi
	double Return_Steel_Weight = 0; //2009-03-09
	rsIronsDesignated.MoveFirst();
	while(!rsIronsDesignated.IsEOF())
	{	
		double fW = rsIronsDesignated.GetFieldByName(_T("Weight")).ToDouble();
		double fC = rsIronsDesignated.GetFieldByName(_T("C")).ToDouble();
		double fSi = rsIronsDesignated.GetFieldByName(_T("Si")).ToDouble();
		double fMn = rsIronsDesignated.GetFieldByName(_T("Mn")).ToDouble();
		double fP = rsIronsDesignated.GetFieldByName(_T("P")).ToDouble();
		double fS = rsIronsDesignated.GetFieldByName(_T("S")).ToDouble();
		double fTi = rsIronsDesignated.GetFieldByName(_T("Ti")).ToDouble();

		//add by hyh 2012-04-05
		double fSn = rsIronsDesignated.GetFieldByName(_T("Sn")).ToDouble();
		double fSb = rsIronsDesignated.GetFieldByName(_T("Sb")).ToDouble();
		double fAs = rsIronsDesignated.GetFieldByName(_T("As")).ToDouble();
		double fPb = rsIronsDesignated.GetFieldByName(_T("Pb")).ToDouble();
		//end

		double fTmp = rsIronsDesignated.GetFieldByName(_T("IronTemp")).ToDouble();
		double fReHeatWeight = rsIronsDesignated.GetFieldByName(_T("Return_Steel_Weight")).ToDouble();//2009-03-09
		Return_Steel_Weight += fReHeatWeight; //2009-03-09
		Temp += fTmp;
		C += fW * fC;
		Si += fW * fSi;
		Mn += fW * fMn;
		P += fW * fP;
		S += fW * fS;
		Ti += fW * fTi;
		//add by hyh 2012-04-05
		Sn += fW * fSn;
		Sb += fW * fSb;
		As += fW * fAs;
		Pb += fW * fPb;
		//end
		IronWeight += fW;
		// �޸�����״̬Ϊ�ȱ�
		CString strLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,rsIronsDesignated.GetFieldByName(_T("IronLadleNo")).ToCString());
		SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT));	
		rsIronsDesignated.MoveNext();
	}

	//����������¯��¯��
	rsRtnSteel.MoveFirst();
	rsRtnSteel.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	L3DOUBLE nWeight = rsRtnSteel.GetFieldByName(_T("Return_Steel_Weight")).ToDouble();
	CString  csSteelGrade = rsRtnSteel.GetFieldByName(_T("Return_SteelGrade")).ToCString();
	Return_Steel_Weight += nWeight;

	//��ǰ�Ѿ�ָ������ԭ�ϵ������²������2009-03-26
	CString csTemp = _T(" select * from %s  where HeatID  ='%s' ");
	CString csSQL;
	csSQL.Format(csTemp,BOF_FEED_DATA_CLASS_URI,strHeatID);
	CL3RecordSetWrap rsFeedFirData;
	if(!Query(csSQL,rsFeedFirData))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -8;
	}

	rsFeedFirData.MoveFirst();
	while(!rsFeedFirData.IsEOF())
	{
		double fW = rsFeedFirData.GetFieldByName(_T("IronWeight")).ToDouble();
		double fC = rsFeedFirData.GetFieldByName(_T("C")).ToDouble();
		double fSi = rsFeedFirData.GetFieldByName(_T("Si")).ToDouble();
		double fMn = rsFeedFirData.GetFieldByName(_T("Mn")).ToDouble();
		double fP = rsFeedFirData.GetFieldByName(_T("P")).ToDouble();
		double fS = rsFeedFirData.GetFieldByName(_T("S")).ToDouble();
		double fTi = rsFeedFirData.GetFieldByName(_T("Ti")).ToDouble();

		//add by hyh 2012-04-05
		double fSn = rsFeedFirData.GetFieldByName(_T("Sn")).ToDouble();
		double fSb = rsFeedFirData.GetFieldByName(_T("Sb")).ToDouble();
		double fAs = rsFeedFirData.GetFieldByName(_T("As")).ToDouble();
		double fPb = rsFeedFirData.GetFieldByName(_T("Pb")).ToDouble();
		//end

		double fTmp = rsFeedFirData.GetFieldByName(_T("IronTemp")).ToDouble();
		double fReHeatWeight = rsFeedFirData.GetFieldByName(_T("Return_Steel_Weight")).ToDouble();
		double fPigIronWeight = rsFeedFirData.GetFieldByName(_T("PigIronWeight")).ToDouble();
		double fScrapWeight = rsFeedFirData.GetFieldByName(_T("ScrapWeight")).ToDouble();
		Temp += fTmp;
		C += fW * fC;
		Si += fW * fSi;
		Mn += fW * fMn;
		P += fW * fP;
		S += fW * fS;
		Ti += fW * fTi;

		//add by hyh 2012-04-05
		Sn += fW * fSn;
		Sb += fW * fSb;
		As += fW * fAs;
		Pb += fW * fPb;
		//end

		IronWeight += fW;	
		ScrapeWeight  += fScrapWeight;
		PigIronWeight += fPigIronWeight;
		Return_Steel_Weight += fReHeatWeight;
		rsFeedFirData.MoveNext();
	}

	Temp = Temp / (rsIronsDesignated.GetRowCount() + rsFeedFirData.GetRowCount());
	C = C / IronWeight;
	Si = Si / IronWeight;
	Mn = Mn / IronWeight;
	P = P / IronWeight;
	S = S / IronWeight;
	Ti = Ti / IronWeight;
	//add by hyh 2012-04-05
	Sn = Sn / IronWeight;
	Sb = Sb / IronWeight;
	As = As / IronWeight;
	Pb = Pb / IronWeight;
	//end

	CurTemp = Temp;


	CL3RecordSetWrap rsFeedData;
	if(!CreateClassPropSet(BOF_FEED_DATA_CLASS_URI,rsFeedData))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -16;
	}
	rsFeedData.AppendRecord();
	rsFeedData.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	rsFeedData.SetFieldByName(_T("IronWeight"),CL3Variant(IronWeight));//2009-02-16 tangyi
	rsFeedData.SetFieldByName(_T("ScrapWeight"),CL3Variant(ScrapeWeight));
	rsFeedData.SetFieldByName(_T("PigIronWeight"),CL3Variant(PigIronWeight));
	rsFeedData.SetFieldByName(_T("Return_Steel_Weight"),CL3Variant(Return_Steel_Weight));//2009-01-02 tangyi
	rsFeedData.SetFieldByName(_T("Return_SteelGrade"),CL3Variant(csSteelGrade));//2009-03-09 tangyi
	rsFeedData.SetFieldByName(_T("C"),CL3Variant(C));
	rsFeedData.SetFieldByName(_T("Si"),CL3Variant(Si));
	rsFeedData.SetFieldByName(_T("Mn"),CL3Variant(Mn));
	rsFeedData.SetFieldByName(_T("P"),CL3Variant(P));
	rsFeedData.SetFieldByName(_T("S"),CL3Variant(S));
	rsFeedData.SetFieldByName(_T("Ti"),CL3Variant(Ti));
	//add by hyh 2012-04-05
	rsFeedData.SetFieldByName(_T("Sn"),CL3Variant(Sn));
	rsFeedData.SetFieldByName(_T("Sb"),CL3Variant(Sb));
	rsFeedData.SetFieldByName(_T("As"),CL3Variant(As));
	rsFeedData.SetFieldByName(_T("Pb"),CL3Variant(Pb));
	//end
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	rsFeedData.SetFieldByName(_T("LogTime"),CL3Variant(curTime));
	rsFeedData.SetFieldByName(_T("IronTemp"),CL3Variant(Temp));

	Load = IronWeight + ScrapeWeight + PigIronWeight + Return_Steel_Weight;//װ����
	rsFeedFirData.MoveFirst();
	if(rsFeedFirData.GetRowCount() > 0)
	{
		if(DeleteOldObjects(BOF_FEED_DATA_CLASS_URI,rsFeedFirData) < 0)
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -17;
		}
	}
	if(CreateNewObjects(BOF_FEED_DATA_CLASS_URI,rsFeedData) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -17;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return 0;

}

/// <Method class="CCCM_Unit_Mag" name="CompletCasting" type="L3BOOL">
/// ��컯�鷢�ͽ�����Ϣ,��������д�Ա���Ϣ�ط���2009-01-03 tangyi
/// </Method>
L3BOOL CBOF_Unit_Mag::SendCastingDataToAnaL2(L3STRING strHeatID)
{

	//�齨���ݼ�
	CString csHeatID = strHeatID;
	CString csSQL;
	CL3RecordSetWrap rsCasting;
	csSQL.Format(_T("select a.HeatID,NULL as CastingNo,a.CasterID as CCMID,a.SteelGradeIndex,NULL as SteelGrade,to_Char(b.Act_Time_IronPrepared,'yyyy-mm-dd hh24:mi:ss') as ProductionDate, 1 as PERMIT_DELETE_FLAG from CPlan_Tapping a,CPlan_Tapping_Act b where a.PlanID = b.PreHeatID and a.HeatID ='%s'"),csHeatID);
	if(!Query(csSQL,rsCasting) || rsCasting.IsNull() || rsCasting.GetRowCount() <1)
		return false;
	rsCasting.MoveFirst();
	CString csSteelGradeIndex = rsCasting.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	rsCasting.SetFieldByName(_T("SteelGrade"),GetObjectPropValue(QA_STG_RELATION_CLASS_URI+_T("\\")+csSteelGradeIndex,_T("SteelGrade")));
	//L3LONG nPosID = 2;
	//CString csTableName = _T("TB_L3_CHANGECAST");
	//L3STRING strTableName = csTableName.AllocSysString();
	//InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
	//				    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
	//					strTableName,(L3RECORDSET)rsCasting);Waiting
	//L3SysFreeString(strTableName);

	//csTableName = _T("TB_L3_CHANGECASTHIS");
	//strTableName = csTableName.AllocSysString();
	//InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
	//				    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
	//					strTableName,(L3RECORDSET)rsCasting);
	//L3SysFreeString(strTableName);

	rsCasting.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\TB_L3_CHANGECAST"),rsCasting) < rsCasting.GetRowCount())
		return false;

	return true;

}


/// <Method class="CBOF_Unit_Mag" name="FeedElement" type="L3BOOL">
/// ��ת¯�м��ϡ�
/// <Param name="rsElement" type="L3RECORDSET">�������ݣ��������ͣ����ϴ��룬����</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::FeedElement(L3RECORDSET rsElement)
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

	// ������ת¯
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
	if(!CreateClassPropSet(BOF_ADDITION_DATA_CLASS_URI,rsLog))
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
	if(CreateNewObjects(BOF_ADDITION_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="TopBlowing" type="L3BOOL">
/// ������¼ת¯�����¼���
/// <Param name="rsBlow" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::TopBlowing(L3RECORDSET rsBlow)
{
	CL3RecordSetWrap rs = rsBlow;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// �������
	if(rs.GetFieldByName(_T("Flow")) < 0 ||
		rs.GetFieldByName(_T("Pressure")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldByName(_T("Catch_Time")) < 0)
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

	// ������ת¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��ȡ¯��
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ��¼������¼
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_TOP_BLOWING_CLASS_URI,rsLog))
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
			rsLog.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(BOF_TOP_BLOWING_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���µ�ǰ��������
	rsLog.MoveFirst();
	L3DATETIME dtMax = 0;
	while(!rsLog.IsEOF())
	{
		L3DATETIME dt = rsLog.GetFieldByName(_T("Catch_Time")).ToDateTime();
		if(dt > dtMax)
		{
			SetPropValue(_T("TopFlow"),rsLog.GetFieldByName(_T("Flow")));
			SetPropValue(_T("TopPressure"),rsLog.GetFieldByName(_T("Pressure")));
			dtMax = dt;
		}
		rsLog.MoveNext();
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="BottomBlowing" type="L3BOOL">
/// ������¼�״��¼���
/// <Param name="rsBlow" type="L3RECORDSET">�״�����</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::BottomBlowing(L3RECORDSET rsBlow)
{
	CL3RecordSetWrap rs = rsBlow;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// �������
	if(rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Gas_Type")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldByName(_T("Catch_Time")) < 0)
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

	// ������ת¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��ȡ¯��
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ��¼�״���¼
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_BOTTOM_BLOWING_CLASS_URI,rsLog))
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
			rsLog.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(BOF_BOTTOM_BLOWING_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���µ�ǰ�״�����
	rsLog.MoveFirst();
	L3DATETIME dtMax = 0;
	while(!rsLog.IsEOF())
	{
		L3DATETIME dt = rsLog.GetFieldByName(_T("Catch_Time")).ToDateTime();
		if(dt > dtMax)
		{
			SetPropValue(_T("BottomFlow1"),rsLog.GetFieldByName(_T("Flow1")));
			SetPropValue(_T("BottomPressure1"),rsLog.GetFieldByName(_T("Pressure1")));
			SetPropValue(_T("BottomFlow2"),rsLog.GetFieldByName(_T("Flow2")));
			SetPropValue(_T("BottomPressure2"),rsLog.GetFieldByName(_T("Pressure2")));
			SetPropValue(_T("BottomFlow3"),rsLog.GetFieldByName(_T("Flow3")));
			SetPropValue(_T("BottomPressure3"),rsLog.GetFieldByName(_T("Pressure3")));
			SetPropValue(_T("BottomFlow4"),rsLog.GetFieldByName(_T("Flow4")));
			SetPropValue(_T("BottomPressure4"),rsLog.GetFieldByName(_T("Pressure4")));
			SetPropValue(_T("BottomFlow5"),rsLog.GetFieldByName(_T("Flow5")));
			SetPropValue(_T("BottomPressure5"),rsLog.GetFieldByName(_T("Pressure5")));
			SetPropValue(_T("BottomFlow6"),rsLog.GetFieldByName(_T("Flow6")));
			SetPropValue(_T("BottomPressure6"),rsLog.GetFieldByName(_T("Pressure6")));
			dtMax = dt;
		}
		rsLog.MoveNext();
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="StartBlowing" type="L3BOOL">
/// ת¯���봵��
/// <Param name="bMainBlowing" type="L3BOOL">������ʶ</Param>
/// <Param name="Catch_Time" type="L3DATETIME">��ʼʱ��</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::StartBlowing(L3BOOL bMainBlowing, L3DATETIME Catch_Time)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	COleDateTime curTime = COleDateTime::GetCurrentTime();
	if(Catch_Time < 100)
		Catch_Time = (DATE)curTime;

	// ������ת¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ���ת¯״̬2009-01-02 tangyi
	if(Status > CBOF_Unit_Mag::BOFReBlowing || Status < CBOF_Unit_Mag::BOFFeeding)
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}


	// �޸ĵ�ǰ״̬
	if(!ChangeBOFStatus(bMainBlowing ? CBOF_Unit_Mag::BOFBlowing : CBOF_Unit_Mag::BOFReBlowing))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// �޸Ĺ�������
	CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,HeatID);
	if (bMainBlowing)
	{
		SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
		StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	}

	//StartProcessTime = curTime.Format(_T("%Y%m%d%H%M%S"));//2008-12-26
	//CString cs = curTime.Format(_T("%Y-%m-%d %H:%M:%S"));

	// ���������¼�
	BlowingEvent = bMainBlowing ? 1 : 2;

	
	if(nTrans > 0)
		Commit(nTrans);

	// �޸ļƻ�״̬
	if(bMainBlowing)
	{
		ChangePlanStatus(HeatID,HeatID,TAPPING_PLAN_BOF_STATUS_BLOW);

		// ��ʼ��ʱ��
		//2009-03-04 Begin
		if(m_nTimer != 0)
			KillTimer(GetURI(),m_nTimer);
		m_nTimer = 0;

		//2009-03-04 End
		BlowTotalTime = 0;
		BlowThisTime = 0;

		m_nTimer = SetTimer(GetURI(),BLOWTIMER_PERIOD); //2009-05-24 ����
	}


	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="StopBlowing" type="L3BOOL">
/// ת¯��������
/// <Param name="Catch_Time" type="L3DATETIME">����ʱ��</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::StopBlowing(L3DATETIME Catch_Time)
{
	if(Catch_Time < 100)
		Catch_Time = COleDateTime::GetCurrentTime();

	LONG nCurStatus = Status;
	if(nCurStatus == CBOF_Unit_Mag::BOFBlowing ||
		nCurStatus == CBOF_Unit_Mag::BOFReBlowing)
	{	// ��ǰ�Ǵ���״̬���������������¼�
		BlowingEvent = 0;
	}

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="SetOxygen" type="L3BOOL">
/// ������¼�����¼���
/// <Param name="rsOxygen" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::SetOxygen(L3RECORDSET rsOxygen)
{
	CL3RecordSetWrap rs = rsOxygen;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// �������
	if(rs.GetFieldIndex(_T("Oxygen_Content")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldIndex(_T("Measure_Time")) < 0)
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

	// ������ת¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��ȡ¯��
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ��¼������¼
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_OXYGEN_DATA_CLASS_URI,rsLog))
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
			rsLog.SetFieldByName(_T("Measure_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(BOF_OXYGEN_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="SetTemperature" type="L3BOOL">
/// ������¼ת¯�����¼���
/// <Param name="rsTemp" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::SetTemperature(L3RECORDSET rsTemp)
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

	// ������ת¯
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
	if(!CreateClassPropSet(BOF_TEMP_DATA_CLASS_URI,rsLog))
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
	if(CreateNewObjects(BOF_TEMP_DATA_CLASS_URI,rsLog) < 1)
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

/// <Method class="CBOF_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
/// �޸�ת¯�豸״̬
/// <Param name="nStatus" type="L3LONG">���豸״̬</Param>
/// <Param name="reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::ChangeDeviceStatus(L3LONG nStatus,L3STRING reason)
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
	if(!CreateClassPropSet(BOF_EQUIPMENT_STATUS_CLASS_URI,rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsLog.AppendRecord();
	CString cstrUnitID = (GetIdentity().ToCString()).Right(1);
	rsLog.SetFieldByName(_T("BOFID"),(L3LONG)_ttoi(cstrUnitID));
	rsLog.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsLog.SetFieldByName(_T("Log_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsLog.SetFieldByName(_T("Reason"),CL3Variant(reason));
	if(CreateNewObjects(BOF_EQUIPMENT_STATUS_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="StartTapping" type="L3BOOL">
/// ������ֿ�ʼ�¼�
/// </Method>
L3BOOL CBOF_Unit_Mag::StartTapping()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// ���ת¯״̬2009-01-02 tangyi
	if(Status > CBOF_Unit_Mag::BOFReBlowing || Status < CBOF_Unit_Mag::BOFFeeding)
	{	// �Ѿ�������
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	COleDateTime curTime = COleDateTime::GetCurrentTime();
	// �޸Ĺ�������
	CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,HeatID);
	SetObjectPropValue(strProcData,_T("Tapping_Strat_Time"),CL3Variant(curTime));

	// �޸�ת¯״̬
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFTapping))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	//2008-12-26tangyi���������Ϣ
	
	L3STRING strHeatID = HeatID.AllocSysString();
	if(!CaculateLadleGrade(COleDateTime::GetCurrentTime(),strHeatID))
	{
		L3SysFreeString(strHeatID);
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	L3SysFreeString(strHeatID);

	// ������һ¯��2009-02-10  tangyi 2009-03-26 �ڶ���ʱ����
	//CString strNextID = CalculateNextHeatID(HeatID);
	//NextHeatID = strNextID;

	if(nTrans > 0) Commit(nTrans);

	
	// �޸ļƻ�״̬
	ChangePlanStatus(HeatID,HeatID,TAPPING_PLAN_BOF_STATUS_TAPPING);


	CalculateTappingTemp();//2009-01-10 
	CalculateTappedOxygenContent();//2009-01-10 

	

	//2009-03-04 Begin
	if(m_nTimer != 0)
		KillTimer(GetURI(),m_nTimer);
	m_nTimer = 0;
	//2009-03-04 End

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="CaculateLadleGrade" type="L3BOOL">
/// ����ְ��ȼ�2008-12-28
/// </Method>
L3BOOL CBOF_Unit_Mag::CaculateLadleGrade(L3DATETIME dtTapTime,L3STRING strHeatID)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	CString csSQL;
	csSQL.Format(_T("select * from CLadle_Use where ComFlag = 0 order by Input_Time asc "));
	CL3RecordSetWrap rsLadle;
	if(!Query(csSQL,rsLadle))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsLadle.MoveFirst();
	CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,strHeatID);
	CString strSteelData = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,strHeatID);
	CString csUnitID =GetIdentity().ToCString();
	while(!rsLadle.IsEOF())
	{
		CString csBOFID = rsLadle.GetFieldByName(_T("BOFID")).ToCString();
		if(csBOFID!=csUnitID)
		{
			rsLadle.MoveNext();
			continue;
		}
		else
		{
			//�޸ĸְ���Ϣ
			CString csLadleID = rsLadle.GetFieldByName(_T("LadleID")).ToCString();
			CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
			L3LONG nLadleType = GetObjectPropValue(csLadleUri,_T("LadleType")).ToLong();
			L3LONG nAge = rsLadle.GetFieldByName(_T("Ladle_Age")).ToLong();//[2009-03-19 Liao] GetObjectPropValue(csLadleUri,_T("Ladle_Age")).ToLong();
			
			SetObjectPropValue(csLadleUri,_T("Ladle_Age"),CL3Variant(L3LONG(nAge)));
			SetObjectPropValue(csLadleUri, _T("Status"), CL3Variant(CLADLE_STATUS_USE));
			//�޸�ת¯ʵ������
			SetObjectPropValue(strProcData,_T("LadleNo"),CL3Variant(csLadleID));
			SetObjectPropValue(strSteelData,_T("LadleID"),CL3Variant(csLadleID));//��Ϊ�ְ��ϼ��󱸲�¼���ֿ�ʼ��
			//�޸ĸְ��ϼ�ʵ��
			CString csGuid = rsLadle.GetFieldByName(_T("GUID")).ToCString(); 
			//[���������ʵ�ʰ�����ͬʱ���¼���������������¼���]2009-03-03
			CString csLadleGrade_Cal =  rsLadle.GetFieldByName(_T("Ladle_Grade")).ToCString(); 
			CString csLadleGrade_Act =  rsLadle.GetFieldByName(_T("Act_Ladle_Grade")).ToCString(); 

			CString csLadleUseUri = CLADLE_USE_URI + _T("\\") + csGuid;
			SteelGradeIndex.Trim();
			if(!SteelGradeIndex.IsEmpty())
			{
				CString csSteelGradeIndexUri = QA_STG_RELATION_CLASS_URI + _T("\\") + SteelGradeIndex;
				SetObjectPropValue(csLadleUseUri,_T("Steel_Grade"),GetObjectPropValue(csSteelGradeIndexUri,_T("SteelGrade")));	
			}
			SetObjectPropValue(csLadleUseUri,_T("HeatID"),CL3Variant(strHeatID));
			SetObjectPropValue(csLadleUseUri,_T("ComFlag"),CL3Variant(L3LONG(1)));	
			//SetObjectPropValue(csLadleUseUri,_T("Tap_Time"),COleDateTime::GetCurrentTime());
			SetObjectPropValue(csLadleUseUri,_T("Tap_Time"),CL3Variant(dtTapTime));
			//��ȡ�ְ����ϼ�ʱ��2009-02-20
			L3DATETIME dtArrTime = rsLadle.GetFieldByName(_T("Arrive_Time")).ToDateTime();
			L3DATETIME dtIrrEndTime = rsLadle.GetFieldByName(_T("Irr_End_Time")).ToDateTime();

			//Modify begin by llj 2011-04-24 �޸ĸְ��ȼ��ļ���ʱ��Ϊ������ʱ��-�������ϴδ����������ʱ��
			//[2009-03-03Liao]
			//COleDateTimeSpan span = dtTapTime - dtArrTime;
			COleDateTimeSpan span = dtTapTime - dtIrrEndTime;
			//Modify end
			L3DOUBLE nTime =  (LONG)span.GetTotalMinutes();
			/*************************************************************************************************/
			//��¼�ְ�����ʱ�䡢��һ¯¯�ţ�����ʱ�䡢���һ¯¯��2009-08-19��
			//1�����ݸְ��Ż�ȡ�ְ���������
			CString csLadleWorkID =  GetObjectPropValue(csLadleUri,_T("WorkID")).ToCString();
			//2���ж�CLadle_Process���Ƿ������ת��¼
			CString csLadleProcessUri = CLADLE_PROCESS_URI + _T("\\") + csLadleWorkID;
			CString csProcessLadleID = GetObjectPropValue(csLadleProcessUri,_T("LadleID")).ToCString();//��ȡ��Ӧ��ת��¼�ĸְ���
			if(csProcessLadleID == _T(""))//��ȡ�ְ���Ϊ�գ���ʾ�����ڶ�Ӧ����ת��¼��������ת��¼
			{
				CString csInnerID = GetObjectPropValue(csLadleUri,_T("InnerID")).ToCString();
				CL3RecordSetWrap rsLadleProcess;
				if(!CreateClassPropSet(CLADLE_PROCESS_URI,rsLadleProcess))
				{
					if(nTrans > 0) Rollback(nTrans);
						return FALSE;
				}
				rsLadleProcess.AppendRecord();
				rsLadleProcess.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));//�ְ���
				rsLadleProcess.SetFieldByName(_T("WorkID"),CL3Variant(csLadleWorkID));//�������ţ��ؼ��֣�
				rsLadleProcess.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));//���ò���
				rsLadleProcess.SetFieldByName(_T("Online_Time"),CL3Variant(dtTapTime));//�ְ���һ¯ʱ�䣨ת¯���ֿ�ʼʱ�䣩
				rsLadleProcess.SetFieldByName(_T("Online_HeatID"),CL3Variant(strHeatID));//���ߵ�һ��¯��
				rsLadleProcess.SetFieldByName(_T("Ladle_Age"),CL3Variant(L3LONG(nAge)));
				
				rsLadleProcess.MoveFirst();
				CreateNewObjects(CLADLE_PROCESS_URI,rsLadleProcess);
			}
			else //������ת��¼���޸�����ʱ�䡢���һ¯¯��
			{
				SetObjectPropValue(csLadleProcessUri,_T("Offline_Time"),CL3Variant(dtTapTime));
				SetObjectPropValue(csLadleProcessUri,_T("Offline_HeatID"),CL3Variant(strHeatID));
				SetObjectPropValue(csLadleProcessUri,_T("Ladle_Age"),CL3Variant(L3LONG(nAge)));
			}
			/*************************************************************************************************/

			if(csLadleGrade_Cal == csLadleGrade_Act)
			{
				switch(nLadleType)
				{
					case 1: //50�ֳ���ְ�
						if(nTime <=1.5*60) 
							csLadleGrade_Act =_T("A");
						else
							if((1.5*60< nTime) && (nTime<=2.5*60))
								csLadleGrade_Act =_T("B");
							else
								if((2.5*60< nTime) && (nTime<=4.5*60))
									csLadleGrade_Act =_T("C");
								else
									csLadleGrade_Act =_T("D");
					break;
					case 2: //50�־����ְ�
						if(nTime<=2.5*60) 
							csLadleGrade_Act =_T("A");
						else
							if((2.5*60< nTime) && (nTime<=4.5*60))
								csLadleGrade_Act =_T("B");
							else
								if((4.5*60< nTime) && (nTime <=6.5*60))
									csLadleGrade_Act =_T("C");
								else
									csLadleGrade_Act =_T("D");
					break;
					case 3: //80�־����ְ�
						if(nTime <=4*60) 
							csLadleGrade_Act =_T("A");
						else
							if((4*60< nTime ) && (nTime <=8*60))
								csLadleGrade_Act =_T("B");
							else
								if((8*60< nTime) && (nTime <=12*60))
									csLadleGrade_Act =_T("C");
								else
									csLadleGrade_Act =_T("D");
					break;
					default:
						break;
				}
			}
			//�޸�ת¯ʵ������
			SetObjectPropValue(strProcData,_T("Ladle_Grade"),CL3Variant(csLadleGrade_Act));
			SetObjectPropValue(strProcData,_T("Ladle_Stop"),CL3Variant(nTime));
			//�޸ĸְ�����
			SetObjectPropValue(csLadleUri,_T("Ladle_Grade"),CL3Variant(csLadleGrade_Act));	
			//�޸ĸְ��ϼ�ʵ��
			SetObjectPropValue(csLadleUseUri,_T("Act_Ladle_Grade"),CL3Variant(csLadleGrade_Act));	
			SetObjectPropValue(csLadleUseUri,_T("Stop_Time_Len"),CL3Variant(nTime));	
			break;
		}			
	}

	if(nTrans > 0) Commit(nTrans);
	return TRUE;
}
/// <Method class="CBOF_Unit_Mag" name="StopTapping" type="L3BOOL">
/// ������ֽ����¼�
/// </Method>
L3BOOL CBOF_Unit_Mag::StopTapping()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// ������ת¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	
	// ���ת¯״̬2009-01-02 tangyi
	if(Status < CBOF_Unit_Mag::BOFFeeding || Status  > CBOF_Unit_Mag::BOFTapping)
	{	// �Ѿ�������
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	CString strHeatID = HeatID;

	COleDateTime curTime = COleDateTime::GetCurrentTime();
	// �޸Ĺ�������
	CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,strHeatID);
	SetObjectPropValue(strProcData,_T("Tapping_End_Time"),CL3Variant(curTime));
	//CL3Variant valStartTime = GetObjectPropValue(strProcData,_T("Tapping_Start_Time"));2009-01-04 tangyi
	CL3Variant valStartTime = GetObjectPropValue(strProcData,_T("Tapping_Strat_Time"));
	
	if(valStartTime.IsValid())
	{
		COleDateTime timeStart = valStartTime.ToDateTime();
		COleDateTimeSpan span = curTime - timeStart;
		SetObjectPropValue(strProcData,_T("Tapping_Time"),CL3Variant((LONG)span.GetTotalSeconds()));
	}
	SetObjectPropValue(strProcData,_T("Lance_Age"),GetPropValue(_T("LanceAge")));
	SetObjectPropValue(strProcData,_T("LanceNo"),GetPropValue(_T("LanceNo")));
	//SetObjectPropValue(strProcData,_T("FurnaceAge"),GetPropValue(_T("Furnace_Age")));2009-01-04 tangyi
	SetObjectPropValue(strProcData,_T("Furnace_Age"),GetPropValue(_T("FurnaceAge")));
	SetObjectPropValue(strProcData,_T("Taphole_Life"),GetPropValue(_T("Taphole_Life")));
	// �޸�ǹ�䣬¯��2009-04-10 ǹ��,¯��,���ֿ��������Ե�����ǰ¯����Ч
	LanceAge ++;
	FurnaceAge ++;
	Taphole_Life++;//2008-12-26

	// �޸�ת¯״̬
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFTapped))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}



	// �����������µĸ�ˮ����
	CStringList lstAreas;
	GetProduceAreas(lstAreas);
	CString strArea = lstAreas.GetHead();
	CBSTR bstrArea(strArea);
	CL3RecordSet *prsParam = new CL3RecordSet();
	CL3RecordSetWrap rsParam; prsParam->QueryInterface(IID_IL3RecordSet,rsParam); prsParam->Release();
	rsParam.AddField(_T("HeatID"),VT_BSTR);
	rsParam.AppendRecord();
	rsParam.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	if(!Process(bstrArea.GetBuffer(TRUE),rsParam))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��ˮ����
	CL3RecordSetWrap rsSteels;
	CL3Variant valSteel = InvokeObjectMethod(strArea,_T("GetMaterials"));
	if(FAILED(valSteel.QueryInterface(IID_IL3RecordSet,rsSteels)))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsSteels.AddField(_T("Area"),VT_BSTR);
	rsSteels.MoveFirst();
	while(!rsSteels.IsEOF())
	{
		rsSteels.SetFieldByName(_T("Area"),CL3Variant(strArea));
		rsSteels.MoveNext();
	}
	rsSteels.MoveFirst();
	if(!DeliverMaterials(rsSteels))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	//// ������һ¯��2009-02-10 ��Ϊ���ֿ�ʼʱ������һ¯��
	//CString strNextID = CalculateNextHeatID(HeatID);
	//NextHeatID = strNextID;

	// �޸ĵ�ǰת¯����
	SteelGradeIndex = _T("");
	StartProcessTime = _T("");//2008-12-26
	Load = 0;
	
	if(nTrans > 0)
		Commit(nTrans);

	// �޸ļƻ�״̬
	ChangePlanStatus(strHeatID,strHeatID,TAPPING_PLAN_BOF_STATUS_TAPPED);


	CalculateFirstLaC();//2009-01-10
	CalculateDefaultSmeltPeriod();////2009-01-14����ұ������

	//¯���Զ�����ʼ 2009-01-14 begin
	CString csUnitID = GetIdentity().ToCString();
	if (csUnitID.GetLength() == 3)
	{
		L3SHORT nUnitID = 0;
		try
		{
			nUnitID = _ttoi(csUnitID.Right(2));
		}
		catch(...)
		{
		}

		nUnitID = nUnitID + 10;

		CString csUnitID;
		csUnitID.Format(_T("%02d"),nUnitID);
		CString TapSideUnitID = _T("S")+csUnitID;
        CString strUri = CL3NameParser::MergeClassDomainName(BOF_SIDE_CLASS_URI,TapSideUnitID);
    	InvokeObjectMethod(strUri,_T("AutoStartProcess"));

	}
	//2009-01-14 End

	//2009-03-04 Begin
	if(m_nTimer != 0)
		KillTimer(GetURI(),m_nTimer);
	m_nTimer = 0;
	//2009-03-04 End

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="Splashing" type="L3BOOL">
/// ת¯��ʼ����
/// </Method>
L3BOOL CBOF_Unit_Mag::Splashing()
{
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFSplash))
		return FALSE;
	else
		return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="Dumping" type="L3BOOL">
/// ת¯��ʼ����
/// </Method>
L3BOOL CBOF_Unit_Mag::Dumping()
{
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFDumping))
		return FALSE;
	else
		return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="Waiting" type="L3BOOL">
/// ����׼����ת¯����ȴ�״̬��
/// </Method>
L3BOOL CBOF_Unit_Mag::Waiting()
{
	// �޸�ת¯����
	CurTemp = 0.0;

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// ���ת¯״̬
	if(Status > CBOF_Unit_Mag::BOFWaiting && Status < CBOF_Unit_Mag::BOFTapped)
	{	// �Ѿ��������״̬
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	//2009-01-10 û�мƻ����ܶ���׼��
	CString strHeatID;
	strHeatID = FindNextHeatIDFromPlan();
	
	if(strHeatID == _T(""))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		SetL3LastError(XGMES_ERR_PLANNOTEXIST);
		return FALSE;
	}
	NextHeatID = strHeatID;

	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFWaiting))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="GetIronsForDesignate" type="L3RECORDSET">
/// ���ؿ�����ָ��¯�ŵ���ˮ��Ϣ��
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetIronsForDesignate()
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

/// <Method class="CBOF_Unit_Mag" name="GetInputIrons" type="L3RECORDSET">
/// �����Ѿ�ָ���˵���ˮ��Ϣ
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetInputIrons()
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
	CL3Variant valIrons = InvokeObjectMethod(MIXFProduceCache_URI,_T("GetMaterialDetails"),bstrIronType.GetBuffer(TRUE),bstrCond.GetBuffer(TRUE));
	if(FAILED(valIrons.QueryInterface(IID_IL3RecordSet,rsIrons)))
	{
		return NULL;
	}
	
	return rsIrons.Detach();
}

/// <Method class="CBOF_Unit_Mag" name="GetInputScrapes" type="L3RECORDSET">
/// �����Ѿ�ָ���˵������ϸ���Ϣ
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetInputScrapes()
{
	CL3RecordSetWrap rsScrapes;
	CString strSQL;
	//strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag,StoreAreaID,Amount from %s where Iron_Flag = 1 and HeatID = '%s'"),SCRAP_OUT_CLASS_URI,NextHeatID);
	strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag,StoreAreaID,Amount from %s where Iron_Flag = 1 and HeatID = '%s'"),SCRAP_OUT_CLASS_URI,HeatID);
	if(!Query(strSQL,rsScrapes))
	{
		return NULL;
	}
	return rsScrapes.Detach();
}

/// <Method class="CBOF_Unit_Mag" name="OnTimer" type="L3BOOL">
/// ��ʱ������
/// <Param name="uEventID" type="L3ULONG">�¼�ID</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::OnTimer(L3ULONG uEventID)
{
	if(uEventID == m_nTimer)
	{	// ������ʱ��
		BlowTotalTime += BLOWTIME;
		BlowThisTime += BLOWTIME;
	}

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="GetAddedMaterialSum" type="L3RECORDSET">
/// ����ָ��¯�ŵļ�����ͳ�����ݡ�
/// <Param name="HeatID" type="L3STRING">¯��</Param>
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetAddedMaterialSum(L3STRING HeatID)
{
	CString strHeatID = String_BSTR2TChar(HeatID);
	CString strSQL;
	strSQL.Format(_T("select Element,Type,sum(Weight) as Weight from %s where HeatID = '%s' group by Element, Type"),
			BOF_ADDITION_DATA_CLASS_URI,(LPCTSTR)strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_ADDITION_DATA_CLASS_URI,rsLog))
		return NULL;
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	return rsLog.Detach();
}


/// <Method class="CBOF_Unit_Mag" name="AcceptAlloyDischargeData" type="L3RECORDSET">
/// �ϲּ������ݲɼ�
/// <Param name="HeatID" type="L3STRING">¯��</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptMaterialDischargeData(L3RECORDSET rsMaterialData)
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
	if(!CreateClassPropSet(BOF_ADDITION_DATA_CLASS_URI,rsLog))
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
	CL3RecordSet *pRSBulk = new CL3RecordSet();
	CL3RecordSetWrap rsBulkOut; pRSBulk->QueryInterface(IID_IL3RecordSet,rsBulkOut); pRSBulk->Release();
	rsBulkOut.AddField(_T("MaterialID"),VT_BSTR);
	rsBulkOut.AddField(_T("MaterialType"),VT_BSTR);
	rsBulkOut.AddField(_T("Amount"),VT_R8);
	rsBulkOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsBulkOut.AddField(_T("Target"),VT_BSTR);
	rsBulkOut.AddField(_T("UnitID"),VT_BSTR);
	rsBulkOut.AddField(_T("Bulk_Code"),VT_BSTR);
	rsBulkOut.AddField(_T("Batch_ID"),VT_BSTR);

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
		//2009-03-06  ת¯����ɢ״���ۼ������ռ�
		//ת��MES�Ͻ��ϲֺ�
		CString csPlcAddress = rsData.GetFieldByName(_T("PLC_Address")).ToCString();
		L3SHORT iType = rsData.GetFieldByName(_T("Type")).ToShort(); //ɢ״���ۼ� iType = 9;
		//2009-05-11 begin ���ֿ�ʼ����¯���������������ϲ�������̼��������
		if (((Status >= CBOF_Unit_Mag::BOFTapping) || (Status <= CBOF_Unit_Mag::BOFBlowing)) && (iType == 2))
		{
			rsData.SetFieldByName(_T("Type"),CL3Variant((L3SHORT)1));
			iType = 1;
		}
		//2009-05-11 end
		csPlcAddress.Replace(_T("."),_T("_"));
		csPlcAddress.Trim();
		if(csPlcAddress.IsEmpty())
		{
			rsData.MoveNext();
			continue;
		}
		CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\CBase_Address_Bulk_Relation\\") + csPlcAddress;
		CString csArea = GetObjectPropValue(csAreaUri,_T("Area")).ToCString();
		csArea.Trim();
		CString csMaterialType = csArea.Mid(0,3);
		rsLog.AppendRecord();
		//���ݺϽ��ϲֺŵõ��Ͻ�
		CString csSQL;
		CL3RecordSetWrap rs;
		CString cstrAreaUri;
		
		if(csMaterialType == STORE_ID_ALLOY)//�Ͻ��ϲ�
		{
			cstrAreaUri = _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Bulk_Relation\\") + csArea;//	2008-12-28 yao
			csSQL.Format(_T(" select b.Alloy_Code as Element,b.Batch_ID,a.MaterialID,a.MaterialType,a.Amount as PosWeight from MATERIALPOSITION a,CAlloy_Data b where a.Position = '%s' and a.MaterialID = b.MaterialID order by Idx "),csArea);
		}
		else
		{
			cstrAreaUri = _T("XGMESLogic\\BulkStoreMag\\CBulk_Bulk_Relation\\") + csArea; //	2008-12-28 yao
			csSQL.Format(_T(" select b.Bulk_Code as Element,b.Batch_ID,a.MaterialID,a.MaterialType,a.Amount as PosWeight  from MATERIALPOSITION a,CBulk_Data b where a.Position = '%s' and a.MaterialID = b.MaterialID order by Idx "),csArea);
		}

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
			if(csMaterialType == STORE_ID_ALLOY)
			{
				rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
				rsMaterial.SetFieldByName(_T("Element"),GetObjectPropValue(cstrAreaUri,_T("Alloy_Code")));	
			}
			else
			{
				rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BULK));
				rsMaterial.SetFieldByName(_T("Element"),GetObjectPropValue(cstrAreaUri,_T("Bulk_Code")));	
			}
			rsMaterial.SetFieldByName(_T("Weight"),CL3Variant(nRemainWeight));
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
			if (((Status >= CBOF_Unit_Mag::BOFTapping)||(Status == CBOF_Unit_Mag::BOFWaiting)) && (iType != 9)) //2009-03-10 ת¯�ȴ�״̬��������Ϊ��¯��
			{
				//��ǰ¯�γ��ֿ�ʼ�󣬴���λ��ϵͳ�ռ���ɢ״�����ݼ�Ϊ��¯������
				csDishcargingHeatID = NextHeatID;
			}
			else
			{
				csDishcargingHeatID = HeatID;
				//��ǰ¯�γ��ֿ�ʼǰ������λ��ϵͳ�ռ���ɢ״�����ݼ�Ϊ��ǰ¯������
			}
			//2008-12-28 end yao

			//2009-01-13 Begin
			CString csAlloyHeatID;
			if (((Status >= CBOF_Unit_Mag::BOFTapping)||(Status == CBOF_Unit_Mag::BOFWaiting)) && (csPlcAddress.Find(_T("BOF_001_BOF1Alloy")) == -1)) //2009-03-10 ת¯�ȴ�״̬��������Ϊ��¯��
			{
				//��ǰ¯�γ��ֿ�ʼ�󣬴���λ��ϵͳ�ռ��ĺϽ�濾¯�Ͻ������ݼ�Ϊ��¯������
				csAlloyHeatID = NextHeatID;
			}
			else if (((Status >= CBOF_Unit_Mag::BOFTapped)||(Status == CBOF_Unit_Mag::BOFWaiting)) && (csPlcAddress.Find(_T("BOF_001_BOF1Alloy")) != -1))//2009-04-27��ǰ¯�γ��ֽ����󣬴���λ��ϵͳ�ռ���1#�Ͻ�߲������ݼ�Ϊ��¯������
			{
				csAlloyHeatID = NextHeatID;
			}
			else
			{
				csAlloyHeatID = HeatID;
				//��ǰ¯�γ��ֿ�ʼǰ������λ��ϵͳ�ռ��ĺϽ������ݼ�Ϊ��ǰ¯������
			}
			//2009-01-13 End

		
			CString csMaterialID = rsMaterial.GetFieldByName(_T("MaterialID")).ToCString();
			csMaterialID.Trim();
			

			if(csMaterialType == STORE_ID_ALLOY)//�Ͻ��ϲ�
			{
    			rsLog.SetFieldByName(_T("HeatID"),CL3Variant(csAlloyHeatID));
				rsLog.SetFieldByName(_T("Type"),CL3Variant(L3LONG(5)));
 			
				if(csMaterialID != _T("NoMaterialID"))
				{
					rsAlloyOut.AppendRecord();
					rsAlloyOut.CopyCurRowFrom(rsMaterial);
					rsAlloyOut.SetFieldByName(_T("Amount"),rsMaterial.GetFieldByName(_T("Weight")));
					rsAlloyOut.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));
					rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csAlloyHeatID));
					rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));	
					rsAlloyOut.SetFieldByName(_T("Alloy_Code"),rsMaterial.GetFieldByName(_T("Element")));
				}
			}
			else
			{
    			rsLog.SetFieldByName(_T("HeatID"),CL3Variant(csDishcargingHeatID));
				rsLog.SetFieldByName(_T("Type"),rsData.GetFieldByName(_T("Type")));

				if(csMaterialID != _T("NoMaterialID"))		
				{
					rsBulkOut.AppendRecord();
					rsBulkOut.CopyCurRowFrom(rsMaterial);
					rsBulkOut.SetFieldByName(_T("Amount"),rsMaterial.GetFieldByName(_T("Weight")));
					rsBulkOut.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));
					rsBulkOut.SetFieldByName(_T("Target"),CL3Variant(csDishcargingHeatID));
					rsBulkOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));
					rsBulkOut.SetFieldByName(_T("Bulk_Code"),rsMaterial.GetFieldByName(_T("Element")));
				}
			}
			//	2008-12-28 begin yao
    		L3LONG nTopSlagFlag = GetObjectPropValue(cstrAreaUri,_T("TopSlagFlag")).ToLong();
			//����nTopSlagFlag(��Ϊ1��Ϊ����;��Ϊ2����ݹ���·������LF��RH��өʯ����С��50kg��һ�����ڶ���)
			if ((nTopSlagFlag == 1) && (iType != 9)) //2009-04-25 ��� (iType != 9)
			{
				rsLog.SetFieldByName(_T("Type"),(L3SHORT)3);
			}
			else if ((nTopSlagFlag == 2) && (iType != 9)) //2009-04-25 ��� (iType != 9)
			{
				// ��ѯ�ƻ�����
				CL3RecordSetWrap rsPlan;
				CString strPlan; strPlan.Format(_T("select LFID,RHID from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,HeatID);
				Query(strPlan,rsPlan);
				if(rsPlan.GetRowCount() > 0)
					rsPlan.MoveFirst();
				CString csLFID = (rsPlan.GetFieldByName(_T("LFID"))).ToCString();
				CString csRHID = (rsPlan.GetFieldByName(_T("RHID"))).ToCString();
				L3FLOAT fWeight = (rsLog.GetFieldByName(_T("Weight"))).ToFloat();
				if (((csLFID != _T("0")) || (csRHID != _T("0"))) && (fWeight < 50))
				{
					rsLog.SetFieldByName(_T("Type"),(L3SHORT)3);
				}

				//2009-04-30 begin ����Ϊ���ֽ��������Ϊ��¯��
				CString cstrDishcargingHeatID;
				if (((Status >= CBOF_Unit_Mag::BOFTapped)||(Status == CBOF_Unit_Mag::BOFWaiting)) && (iType != 9)) //2009-03-10 ת¯�ȴ�״̬��������Ϊ��¯��
				{
					cstrDishcargingHeatID = NextHeatID;
				}
				else
				{
					cstrDishcargingHeatID = HeatID;
				}
				rsLog.SetFieldByName(_T("HeatID"),CL3Variant(cstrDishcargingHeatID));
				//2009-04-30 end

			}
			rsMaterial.MoveNext();		
		}

		rsData.MoveNext();	
	}


	if(CreateNewObjects(BOF_ADDITION_DATA_CLASS_URI,rsLog) < rsLog.GetRowCount())
		return FALSE;


	if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0)
		InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsAlloyOut));
	if(!rsBulkOut.IsNull() && rsBulkOut.GetRowCount() > 0)
		InvokeObjectMethod(BULK_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsBulkOut));

	//2009-05-22 ͬһ�����϶�����ϣ��ܹ�Ŀǰ��֧�������������ʸ�Ϊ��������
	//if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0)
	//{
	//	CL3RecordSetWrap rsFinalData = rsAlloyOut.CloneStruct();
	//	rsFinalData.AppendRecord();	
	//	rsFinalData.MoveFirst();
	//	rsAlloyOut.MoveFirst();
	//	while(!rsAlloyOut.IsEOF())
	//	{
	//		rsFinalData.CopyCurRowFrom(rsAlloyOut);
	//		InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsFinalData));
	//		rsFinalData.MoveFirst();
	//		rsAlloyOut.MoveNext();
	//	}
	//}

	//if(!rsBulkOut.IsNull() && rsBulkOut.GetRowCount() > 0)
	//{
	//	CL3RecordSetWrap rsFinalData = rsBulkOut.CloneStruct();
	//	rsFinalData.AppendRecord();	
	//	rsFinalData.MoveFirst();
	//	rsBulkOut.MoveFirst();
	//	while(!rsBulkOut.IsEOF())
	//	{
	//		rsFinalData.CopyCurRowFrom(rsBulkOut);
	//		InvokeObjectMethod(BULK_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsFinalData));
	//		rsFinalData.MoveFirst();
	//		rsBulkOut.MoveNext();
	//	}
	//}

	return TRUE;
}


/// <Method class="CBOF_Unit_Mag" name="MaterialGroundDischargeData" type="L3RECORDSET">
/// ��װ�Ͻ�ɢ״������
/// <Param name="HeatID" type="L3STRING">¯��</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::MaterialGroundDischargeData(L3RECORDSET rsMaterialData)
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
	if(!CreateClassPropSet(BOF_ADDITION_DATA_CLASS_URI,rsLog))
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

	if(CreateNewObjects(BOF_ADDITION_DATA_CLASS_URI,rsLog) < rsLog.GetRowCount())
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





/// <Method class="CBOF_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
/// ����ĸ�
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_EXE_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(BOF_BASE_DATA_CLASS_URI,csHeatID);
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
///  ��ˮ��¯���� 2009-02-28 ����¯��
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_TURN_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	//CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csHeatID = strHeatID;
	CString csUri = CL3NameParser::MergeClassDomainName(BOF_BASE_DATA_CLASS_URI,csHeatID);
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

/// <Method class="CBOF_Unit_Mag" name="GetExceptHeatID" type="L3RECORDSET">
/// ��ȡ�����쳣¯�����ݡ�
/// <Param name="UnitID" type="L3STRING">��λ</Param>
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetExceptHeatID(L3STRING UnitID)
{
	CString strUnitID = String_BSTR2TChar(UnitID);
	int nUnitTypeID = _ttoi(strUnitID.Mid(1,1));
	CString csUnitID = strUnitID.Mid(2,1);
	CString strSQL;
	switch(nUnitTypeID)
	{
	case 2:
		{	//ת¯
			strSQL.Format(_T("select HeatID from (select HeatID from %s where substr(HeatID,2,1) = '%s' order by ProductionDate desc) where rownum < 3"),
					BOF_BASE_DATA_CLASS_URI,csUnitID);
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

/// <Method class="CBOF_Unit_Mag" name="SetStackData" type="L3BOOL">
/// ��¼ת¯¯��ά������
/// <Param name="rsData" type="L3RECORDSET">¯������</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::SetStackData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// �������
	if(rs.GetFieldIndex(_T("Team")) < 0)
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

	// ������ת¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// ��ȡ¯��
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// ��¼¯�ļ�¼
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Stack_Maintenance"),rsLog))
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
		rsLog.SetFieldByName(_T("ProductionDate"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Stack_Maintenance"),rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="LockData" type="L3SHORT">
/// ����ʵ������
/// <Param name="strUnitID" type="L3STRING">��λ</Param>
/// <Param name="strHeatID" type="L3STRING">¯��</Param>
/// <Param name="strTreatNo" type="L3STRING">�����</Param>
/// </Method>
L3SHORT CBOF_Unit_Mag::LockData(L3STRING strUnitID,L3STRING strHeatID,L3STRING strTreatNo)
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

	//2009-04-14 �˹�ȷ����־ʱ���չ�¼����ϴӴ�װ�Ͻ𴦳���
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

	

	if (csUnitID.Left(2) == _T("S2"))
	{
		//Modify begin by llj 2011-03-26 ��ת¯��ˮֱ�Ͳ���ֽ��������жϴ�����ΪNC��Ҫ�ϴ���ˮ����
		if(csUnitID==_T("S24"))
		{
			CString csSql;
			csSql.Format(_T("select CASTERID from %s where HEATID='%s'"),PLAN_TAPPING_CLASS_URI,strHeatID);
			CL3RecordSetWrap rsTapping;
			if(!Query(csSql,rsTapping)||rsTapping.IsNull()||rsTapping.GetFieldCount()<1)
				return -1;
			rsTapping.MoveFirst();
			CString csCasterID=rsTapping.GetFieldByName(_T("CasterID")).ToString();
			if(csCasterID==_T("S66"))
			{
				double dSteelWeight=(GetObjectPropValue(_T("XGMESLogic\\BOFMag\\CBOF_Process_Data\\")+csHeatID,_T("Tapping_Weight"))).ToLong();
				if(dSteelWeight<0.1)
					return -1;
			}
		}
		//Modify end
		csURI = _T("XGMESLogic\\BOFMag\\CBOF_Base_Data\\");
	    csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("BOFFinishedFlag"))).ToCString();
        csPropName = _T("BOFFinishedFlag");
		//ת¯�ֹ�����Ͻ�
		CString csTempSQL = _T(" select * from CBOF_ADDITION_DATA where Name ='1' and Type ='5' and HeatID ='%s' ");
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
			CString	csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='1' ");
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
		//¯���ֹ�����Ͻ�
		csTempSQL = _T(" select * from CTAP_ADDITION_DATA  where  Name ='1' and HeatID ='%s' ");
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsTap;
		if(!Query(csSQL,rsTap))
			return -5;
		rsTap.MoveFirst();
		while(!rsTap.IsEOF())
		{	
			CString csAlloyCode = rsTap.GetFieldByName(_T("Element")).ToCString();
			CString csBatchID = rsTap.GetFieldByName(_T("Batch_ID")).ToCString();
			CString csSQL;
			CString	csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='1' ");
			CL3RecordSetWrap rsResult;
			csSQL.Format(csTempSQL,csAlloyCode);
			if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
			{
				rsTap.MoveNext();
				continue;
				
			}
			rsResult.MoveFirst();
			rsAlloyOut.AppendRecord();
			rsAlloyOut.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
			rsAlloyOut.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
			rsAlloyOut.SetFieldByName(_T("Amount"),rsTap.GetFieldByName(_T("Weight")));
			rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csHeatID));
			rsAlloyOut.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
			rsAlloyOut.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
			rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(csUnitID));
			rsAlloyOut.SetFieldByName(_T("Type"),L3LONG(5));
			rsAlloyOut.SetFieldByName(_T("StoreAreaID"),rsResult.GetFieldByIndex(0));
			rsTap.MoveNext();
		}
	}
	else if (csUnitID.Left(2) == _T("S4"))
	{
		csURI = _T("XGMESLogic\\LFMag\\CLF_Base_Data\\");
	    csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("LFFinishedFlag"))).ToCString();
        csPropName = _T("LFFinishedFlag");
		//�Ͻ�
		CString csTempSQL = _T(" select * from CLF_ADDITION_DATA where Name ='1' and HeatID ='%s' ");
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
			CString	csTempSQL;
			if(csUnitID == UNIT_ID_1LF || csUnitID == UNIT_ID_2LF)
			csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='2' ");
			else
			csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='3' ");
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
	}
	else if (csUnitID.Left(2) == _T("S5"))
	{
		csURI = _T("XGMESLogic\\RHMag\\CRH_Base_Data\\");
	    csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("RHFinishedFlag"))).ToCString();
        csPropName = _T("RHFinishedFlag");
		////�Ͻ�
		CString csTempSQL = _T(" select * from CRH_ADDITION_DATA where Name ='1'  and HeatID ='%s' ");
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
			CString	csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='3' ");
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
	}
	else if (csUnitID.Left(2) == _T("S6"))
	{
		csURI = _T("XGMESLogic\\CCMMag\\CCCM_Base_Data\\");
	    csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("CCMFinishedFlag"))).ToCString();
        csPropName = _T("CCMFinishedFlag");
	}


	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	if (!SetObjectPropValue(csURI+csTreatNo,_T("Locked"),(L3SHORT)1))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}

	if (!SetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,csPropName,CL3Variant(_T("1"))))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}

	if(nTrans > 0)
		Commit(nTrans);

	//2009-04-14 �˹�ȷ����־ʱ���չ�¼����ϴӴ�װ�Ͻ𴦳���
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

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFStatus" type="L3BOOL">
/// ����ת¯����״̬���� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">״̬����</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFStatus(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	// ��ȡ¯��
	rs.MoveFirst();
	L3LONG BOFStatus = -1;
	BOFStatus = (rs.GetFieldByName(_T("BOFStatus"))).ToLong();
	switch(BOFStatus)
	{
    	case CBOF_Unit_Mag::BOFFeeding: 
			FeedIrons();
		break;
		case CBOF_Unit_Mag::BOFBlowing: 
			StartBlowing(true, rs.GetFieldByName(_T("MesauresTime")).ToDateTime());
		break;
		case CBOF_Unit_Mag::BOFReBlowing: 
		{
			StartBlowing(false, rs.GetFieldByName(_T("MesauresTime")).ToDateTime());
		}
		break;
		case CBOF_Unit_Mag::BOFTapping: 
		{
			StartTapping();
		}
		break;
		case CBOF_Unit_Mag::BOFTapped: 
			StopTapping();
		break;
		case CBOF_Unit_Mag::BOFSplash: 
			Splashing();
		break;
		case CBOF_Unit_Mag::BOFDumping:  
		{
			//2009-01-10 Begin
			CString curHeatID = HeatID;
			if (curHeatID.GetLength() == 9)
			{
				L3LONG iSplashingTime = rs.GetFieldByName(_T("SplashingTime")).ToLong();
				if (iSplashingTime > 0)
				{
					SetObjectPropValue(_T("XGMESLogic\\BOFMag\\CBOF_Process_Data\\")+curHeatID,_T("Splashing_Time"),CL3Variant(iSplashingTime));
				}
			}
			//2009-01-10 End
			Dumping();
		}
		break;
		default:
			break;
	}
	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFBottomBlowData" type="L3BOOL">
/// ����ת¯�״����� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">�״�����</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFBottomBlowData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	CL3RecordSetWrap rsBlow;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Bottom_Blowing"),rsBlow))
	{
		return FALSE;
	}

	rsBlow.CopyFrom(rs);

	rsBlow.MoveFirst();
	while (!rsBlow.IsEOF())
	{
		rsBlow.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsBlow.SetFieldByName(_T("Catch_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		BottomFlow1 = rsBlow.GetFieldByName(_T("Flow1")).ToFloat();
		BottomFlow2 = rsBlow.GetFieldByName(_T("Flow2")).ToFloat();
		BottomFlow3 = rsBlow.GetFieldByName(_T("Flow3")).ToFloat();
		BottomFlow4 = rsBlow.GetFieldByName(_T("Flow4")).ToFloat();
		BottomFlow5 = rsBlow.GetFieldByName(_T("Flow5")).ToFloat();
		BottomFlow6 = rsBlow.GetFieldByName(_T("Flow6")).ToFloat();
		BottomPressure1 = rsBlow.GetFieldByName(_T("Pressure1")).ToFloat();
		BottomPressure2 = rsBlow.GetFieldByName(_T("Pressure2")).ToFloat();
		BottomPressure3 = rsBlow.GetFieldByName(_T("Pressure3")).ToFloat();
		BottomPressure4 = rsBlow.GetFieldByName(_T("Pressure4")).ToFloat();
		BottomPressure5 = rsBlow.GetFieldByName(_T("Pressure5")).ToFloat();
		BottomPressure6 = rsBlow.GetFieldByName(_T("Pressure6")).ToFloat();

		if (rsBlow.GetFieldByName(_T("Gas_Type")).ToShort() == 1) //2009-01-08 
		{
			rsBlow.SetFieldByName(_T("Gas_Type"),CL3Variant(_T("N2")));
		}
		else
		{
			rsBlow.SetFieldByName(_T("Gas_Type"),CL3Variant(_T("Ar")));
		}
		rsBlow.MoveNext();
	}

	rsBlow.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Bottom_Blowing"),rsBlow) < rsBlow.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFTopBlowData" type="L3BOOL">
/// ����ת¯�������� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFTopBlowData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	CL3RecordSetWrap rsBlow;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Top_Blowing"),rsBlow))
	{
		return FALSE;
	}

	rsBlow.CopyFrom(rs);

	rsBlow.MoveFirst();
	while (!rsBlow.IsEOF())
	{
		rsBlow.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsBlow.SetFieldByName(_T("Catch_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		TopFlow = rsBlow.GetFieldByName(_T("Flow")).ToFloat();
		TopPressure = rsBlow.GetFieldByName(_T("Pressure")).ToFloat();
		rsBlow.MoveNext();
	}

	rsBlow.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Top_Blowing"),rsBlow) < rsBlow.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFTappedData" type="L3BOOL">
/// ����ת¯�������� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFTappedData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.AddField(_T("HeatID"),L3VT_STRING);
	rs.MoveFirst();
	while (!rs.IsEOF())
	{
		rs.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rs.MoveNext();
	}

	rs.MoveFirst();
	SetObjsPropValues(BOF_PROCESS_DATA_CLASS_URI,rs);

	CalculateLcTemp();

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFTempData" type="L3BOOL">
/// ����ת¯�������� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFTempData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	if (Status >= CBOF_Unit_Mag::BOFTapped) //���ֽ��������ռ��¶�����2009-01-09
	{
		return TRUE;
	}

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Temp_Data"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("Temp_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		CurTemp = rsTemp.GetFieldByName(_T("Temp")).ToLong();
		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Temp_Data"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFOxygenData" type="L3BOOL">
/// ����ת¯�������� 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFOxygenData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	if (Status >= CBOF_Unit_Mag::BOFTapped) //���ֽ��������ռ��¶�����2009-01-09
	{
		return TRUE;
	}

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Oxygen_Data"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("Measure_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Oxygen_Data"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateLcTemp" type="L3BOOL">
/// ������̼�¶�����(ȡ����ǰ���һ������,�޲���ȡ���һ������) 2009-01-10
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateLcTemp()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
	L3SHORT nReBlow_Count = GetObjectPropValue(strUri,_T("ReBlow_Count")).ToShort();
	CString csSQL;
	if (nReBlow_Count == 0) //�޲���ȡ���һ������
	{
		csSQL.Format(_T("select Temp from %s where HeatID = '%s' order by Temp_Time desc"),BOF_TEMP_DATA_CLASS_URI,curHeatID);
		CL3RecordSetWrap rstemp;
		if (!Query(csSQL, rstemp) || rstemp.IsNull())	
		{
			return FALSE; 
		}
		L3LONG rsCount = rstemp.GetRowCount();
		if (rsCount > 0)
		{
		   rstemp.MoveFirst();
		   L3LONG iLcTemp = rstemp.GetFieldByName(_T("Temp")).ToLong();
		   if (!SetObjectPropValue(strUri,_T("LaC_Temp"),CL3Variant(iLcTemp)))
		   {
				return FALSE; 
		   }
		}
	}
	else //ȡ����ǰ���һ������
	{
		csSQL.Format(_T("select Temp from CBOF_Temp_Data where HeatID = '%s' and Temp_Time < (select Change_Time from CBOF_Process_Status where HeatID = '%s' and Status = 3) order by Temp_Time desc"),curHeatID,curHeatID);
		CL3RecordSetWrap rstempreblow;
		if (!Query(csSQL, rstempreblow) || rstempreblow.IsNull())	
		{
			return FALSE; 
		}
		L3LONG rsCount = rstempreblow.GetRowCount();
		if (rsCount > 0)
		{
		   rstempreblow.MoveFirst();
		   L3LONG iLcTemp = rstempreblow.GetFieldByName(_T("Temp")).ToLong();
		   if (!SetObjectPropValue(strUri,_T("LaC_Temp"),CL3Variant(iLcTemp)))
		   {
				return FALSE; 
		   }
		}
	}
	
	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateTappingTemp" type="L3BOOL">
/// ��������¶�����(��Դ��Ϊ����:һΪ��¯���£���Ϊ����ʱ����;���ֿ�ʼ֮ǰ�����һ�β���;
/// �����ֲ�����������ʼ�����ֿ�ʼʱ���δ���£�������¶ȼ�Ϊδ��(-1)������δ���²ɼ�����ʱ�¶�����) 2009-01-10
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateTappingTemp()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

    //���ֿ�ʼ֮ǰ�����һ�β���
	CString csSQL;
	csSQL.Format(_T("select Temp from %s where HeatID = '%s' order by Temp_Time desc"),BOF_TEMP_DATA_CLASS_URI,curHeatID);
	CL3RecordSetWrap rstemp;
	if (!Query(csSQL, rstemp) || rstemp.IsNull())	
	{
		return FALSE; 
	}

	L3LONG iTappingTemp = 0;
	L3LONG rsCount = rstemp.GetRowCount();
	if (rsCount > 0)
	{
	   rstemp.MoveFirst();
	   iTappingTemp = rstemp.GetFieldByName(_T("Temp")).ToLong();
	}
	//�����ֲ�����������ʼ�����ֿ�ʼʱ���δ���£�������¶ȼ�Ϊδ��(-1)
	csSQL.Format(_T("select * from %s where HeatID = '%s' and Status = %d order by Change_Time desc"),
		BOF_PROC_STATUS_CLASS_URI,curHeatID,CBOF_Unit_Mag::BOFReBlowing);
	CL3RecordSetWrap rstime;
	if (!Query(csSQL, rstime) || rstime.IsNull())	
	{
		return FALSE; 
	}
	rsCount = rstime.GetRowCount();
	if (rsCount > 0)
	{
	   rstime.MoveFirst();
	   COleDateTime timeOld = rstime.GetFieldByName(_T("Change_Time")).ToDateTime();
	   csSQL.Format(_T("select Temp from %s where HeatID = '%s' and Temp_Time>? "),
		         BOF_TEMP_DATA_CLASS_URI,curHeatID);
		VARIANT params[1];
		params[0].vt = VT_DATE; params[0].date = (DATE)timeOld;
		CL3RecordSetWrap rs;
		if(QueryWithParam(csSQL,params,1,rs))
		{
			L3LONG irsCount = rs.GetRowCount();
			if (irsCount < 1)
			{
				iTappingTemp = -1;
			}
		}
	}

	CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
   if (!SetObjectPropValue(strUri,_T("Tapping_Temp"),CL3Variant(iTappingTemp)))
   {
		return FALSE; 
   }

   //Modify begin by llj 2011-0-09 ������̼�¶�Ϊ�紵��ʼ6���Ӻ�ĵ�һ���¶�
   csSQL.Format(_T("select Change_Time from CBOF_Process_Status where  HeatID='%s' and Status=2"),curHeatID);
   CL3RecordSetWrap rsBOFStatus;
   if(!Query(csSQL,rsBOFStatus)&&rsBOFStatus.GetRowCount()==1)
   {
	   rsBOFStatus.MoveFirst();
	   L3DATETIME dChangeTime=rsBOFStatus.GetFieldByName(_T("Change_Time")).ToDateTime();
	   csSQL.Format(_T("select Temp_Time,Temp from CBOF_Temp_Data where HeatID = '%s' and Temp_Time > %d order by Temp_Time asc "),curHeatID,dChangeTime);
	   CL3RecordSetWrap rs;
	   if(!Query(csSQL,rs)&&!rs.IsNull()&&rs.GetRowCount()>0)
	   {
		   rs.MoveFirst();
		   while(!rs.IsEOF())
		   {
			   L3DATETIME dTempTime=rs.GetFieldByName(_T("Temp_Time")).ToDateTime();
			   COleDateTimeSpan span = dTempTime - dChangeTime;
			   if(span.GetTotalSeconds()>8*60)
			   {
				   L3LONG iTemp=rs.GetFieldByName(_T("Temp")).ToLong();

					//������̼�¶�
					CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
					if (!SetObjectPropValue(strUri,_T("LaC_Temp"),CL3Variant(iTemp)))
					{
						return FALSE; 
					}
					break;
			   }
		   }

	   }
   }
   //Modify end

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateTappedOxygenContent" type="L3BOOL">
/// �����������������(ȡ���һ������������) 2009-01-10
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateTappedOxygenContent()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString csSQL;
	csSQL.Format(_T("select Oxygen_Content from %s where HeatID = '%s' order by Measure_Time desc"),BOF_OXYGEN_DATA_CLASS_URI,curHeatID);
	CL3RecordSetWrap rstemp;
	if (!Query(csSQL, rstemp) || rstemp.IsNull())	
	{
		return FALSE; 
	}
	L3LONG rsCount = rstemp.GetRowCount();
	if (rsCount > 0)
	{
	   rstemp.MoveFirst();
	   L3FLOAT fOxygenContent = rstemp.GetFieldByName(_T("Oxygen_Content")).ToFloat();
	   CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
       if (!SetObjectPropValue(strUri,_T("Tapping_Oxygen"),CL3Variant(fOxygenContent)))
	   {
			return FALSE; 
	   }
	}
	
	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateFirstLaC" type="L3BOOL">
/// ����һ����̼(��̼�¶ȵ��ڳ����¶����޲�������̼���ϣ����հ���ʯ��ʯ�ң��źŵģ���Ϊһ����̼) 2009-01-10
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateFirstLaC()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

    CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
	L3LONG iTappingTemp = GetObjectPropValue(strUri,_T("Tapping_Temp")).ToLong();
	L3LONG iLaCTemp = GetObjectPropValue(strUri,_T("LaC_Temp")).ToLong();
	if (iTappingTemp == iLaCTemp)
	{
		L3SHORT noReBlow = -1;
		CString csSQL;
		csSQL.Format(_T("select * from %s where HeatID = '%s' and Status = %d"),
			BOF_PROC_STATUS_CLASS_URI,curHeatID,CBOF_Unit_Mag::BOFReBlowing);
		CL3RecordSetWrap rstime;
		if (!Query(csSQL, rstime) || rstime.IsNull())	
		{
			return FALSE; 
		}
		L3LONG rsCount = rstime.GetRowCount();
		if (rsCount < 1)
		{
			noReBlow = 1;
		}

		L3LONG noLaCMat = -1;
		csSQL.Format(_T("select * from %s where HeatID = '%s' and Type = 2 and Element <> 'B006'"),
			BOF_ADDITION_DATA_CLASS_URI,curHeatID);
		CL3RecordSetWrap rstemp;
		if (!Query(csSQL, rstemp) || rstemp.IsNull())	
		{
			return FALSE; 
		}
		rsCount = rstemp.GetRowCount();
		if (rsCount < 1)
		{
			noLaCMat = 1;
		}

		if ((noReBlow == 1) && (noLaCMat == 1))
		{
		   if (!SetObjectPropValue(strUri,_T("Single_LaC"),CL3Variant((L3SHORT)1)))
		   {
				return FALSE; 
		   }

		}
	}
	
	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateDefaultSmeltPeriod" type="L3BOOL">
/// ����ȱʡұ������ 2009-01-14
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateDefaultSmeltPeriod()
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

    CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,cspreviousHeatID);
	COleDateTime dTappingEndTime = GetObjectPropValue(strUri,_T("Tapping_End_Time")).ToDateTime();
	COleDateTime dCurTime = COleDateTime::GetCurrentTime();
	COleDateTimeSpan span = dCurTime - dTappingEndTime;
	
	LONG smeltperious = (LONG)span.GetTotalMinutes();

	if (smeltperious > 0)
	{
	   if (!SetObjectPropValue(strUri,_T("Smelt_Period"),CL3Variant((L3LONG)smeltperious)))
	   {
			return FALSE; 
	   }
	}

	return TRUE;	
}

/// ��ȡ��һ¯��
CString CBOF_Unit_Mag::GetPreviousHeatID(LPCTSTR lpcszHeatID)
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
		csSQL.Format(_T("select max(HeatID) as HeatID from CBOF_Process_Data where substr(HeatID,1,4) ='%s'"),cssubHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
			return _T("");
		rs.MoveFirst();
		csPreviousHeatID = rs.GetFieldByName(_T("HeatID")).ToCString();
	}

	return csPreviousHeatID;
}

/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  ��ȡ���¯�� 2009-02-28 ����¯��
/// <Param name="Reason" type="L3STRING">ԭ��</Param>
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetPreThreeHeatID()
{
	CString csUnitID = GetIdentity().ToCString();
	CString csBOFID = csUnitID.Mid(2,1);
	CString csTempSQL =_T("select * from (select HeatID from CBOF_Base_Data where substr(HeatID,2,1) = '%s'  order by  HeatID desc) where rownum < 4");
	CString csSQL;
	csSQL.Format(csTempSQL,csBOFID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;
	return rs.Detach();	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFRemainSlag" type="L3BOOL">
/// ����ת¯�������� 2016-08-11
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFRemainSlag(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;
    
	rs.MoveFirst();
	CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csHeatIDUri = BOF_PROCESS_DATA_CLASS_URI + _T("\\") + csHeatID;
    int nRemainSlag =  rs.GetFieldByName(_T("RemainSlagStatus")).ToShort ();
	if(nRemainSlag > 0)
	{
		
	    SetObjectPropValue(csHeatIDUri,_T("RemainSlag"),CL3Variant(_T("��")));
	}
	else if(nRemainSlag < 0)
	{
        SetObjectPropValue(csHeatIDUri,_T("RemainSlag"),CL3Variant(_T("��")));
	  }
	return TRUE;		
}
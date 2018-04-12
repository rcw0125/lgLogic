// �߼���CMIF_Unit_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CMIF_Unit_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CMIF_Unit_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CMIF_Unit_Mag.h"
#include "_CMIF_Mag.h"
#include "L3NameParser.h"
#include "Material.h"
#include "_CIron_Data.h"

//������װ�ص�ϵͳ��ʱ��������
void CMIF_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CMIF_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ���ػ���ļӹ�����
/// ARG << lstURIs : �������мӹ��������URI
/// </summary>
BOOL CMIF_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetProduceAreas( lstURIs);
}

/// <summary>
/// �õ�����ǰ����ϻ�������URI
/// </summary>
CString CMIF_Unit_Mag::GetInputCache()
{
	return BFIronStoreOutCache_URI;
}

/// <summary>
/// �õ������̲��ϻ�������URI
/// </summary>
CString CMIF_Unit_Mag::GetOutputCache()
{
	return MIXFProduceCache_URI;
}

/// <summary>
/// ��������ǰԤ�����ڻ�������ǰ���ã��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << ����TRUE�������ϣ�����FALSE�ж����ϡ�
/// </summary>
BOOL CMIF_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// �������Ϻ��������ڻ������Ϻ���ã��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : ������Ϣ��¼����
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CMIF_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// ���ػ������ϼ�¼������URI
/// </summary>
CString CMIF_Unit_Mag::GetFeedingLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetFeedingLogType();
}


/// <summary>
/// ׼�����ϼ�¼���ݡ��̳�������ش˺������ж�������ݴ���
/// ARG >> rsFeedingLogs : ���ϼ�¼��Ϣ��
/// RET << void
/// </summary>
void CMIF_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
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
BOOL CMIF_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
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
BOOL CMIF_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// ����ǰԤ������ִ�����߲���ǰ���ã��̳�������ش˺�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << ����TRUE�������ߣ�����FALSE�ж����ߡ�
/// </summary>
BOOL CMIF_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// ���ߺ���������ִ�����߲�������ã��̳�������ش˺������ж��⴦��
/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CMIF_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsDelivered( rsMaterialInfo);
}


/// <summary>
/// ���ػ��������¼������URI
/// </summary>
CString CMIF_Unit_Mag::GetDeliveryLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetDeliveryLogType();
}


/// <summary>
/// ׼�����ϼ�¼���ݡ�
/// ARG >> rsDeliveryLog : ���ϼ�¼���ݡ�
/// RET <<void
/// </summary>
void CMIF_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// ���ر������ͨѶ�������URI
/// </summary>
CString CMIF_Unit_Mag::GetCommunicator()
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
BOOL CMIF_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// �ƻ��´��������������λϵͳ���ͼƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsSend : �·���λϵͳ�ļƻ����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CMIF_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
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
BOOL CMIF_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// �ƻ�ȡ����������������λϵͳ����ȡ���ƻ�����ã��̳�������ش˺������к�������
/// ARG >> rsCancel : �·���λϵͳ�ļƻ�ȡ�����ݡ�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CMIF_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// ����������ߵ��¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CMIF_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// ������Ͻ���ӹ�������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CMIF_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// ��������뿪�ӹ������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CMIF_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// ���������������¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CMIF_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// �������������ݱ���¼�
/// ARG >> pEvt : �¼�����
/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
/// </summary>
BOOL CMIF_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}

/// <Method class="CMIF_Unit_Mag" name="CalculateChemicalData" type="L3VOID">
/// <Param name="rsIron" type="L3RECORDSET">��ˮ������</Param>
/// </Method>
L3VOID CMIF_Unit_Mag::CalculateChemicalData(L3RECORDSET rsIron)
{
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CMIF_Unit_Mag" name="SampleChemcialData" type="L3LONG">
/// ����¯����������
/// <Param name="rsChemical" type="L3RECORDSET">�ɷ�����</Param>
/// </Method>
L3LONG CMIF_Unit_Mag::SampleChemcialData(L3RECORDSET rsChemical)
{
	// TODO : ���ڴ�����߼�����
	return 0;
}

/// <Method class="CMIF_Unit_Mag" name="MixIrons" type="L3LONG">
/// ��ĳЩ��ˮ�������¯
/// <Param name="rsIrons" type="L3RECORDSET">�������¯����ˮ��¼</Param>
/// </Method>
L3LONG CMIF_Unit_Mag::MixIrons(L3RECORDSET rsIrons)
{
	CL3RecordSetWrap rs = rsIrons;
	if(rs.GetRowCount() < 1)
		return 0;

	// ��鼰׼������
	if(rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Spare_Weight")) < 0 ||
		rs.GetFieldIndex(_T("Net_Weight")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
	}
	rs.AddField(_T("MaterialType"),VT_BSTR);
	rs.AddField(_T("Amount"),VT_R8);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CBFIron")));
		rs.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		rs.MoveNext();
	}
	
	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	// ��ס��ˮ�����Cache
	if(!PutObjectIntoTrans(BFIronStoreOutCache_URI))
	{
		Rollback(nTrans);
		return -1;
	}

	// ׼����ˮ����������¼��
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsUpdate; pRS->QueryInterface(IID_IL3RecordSet,rsUpdate); pRS->Release();
	rsUpdate.AddField(_T("MaterialType"),VT_BSTR);
	rsUpdate.AddField(_T("MaterialID"),VT_BSTR);
	rsUpdate.AddField(_T("Spare_Weight"),VT_R8);
	//Modify begin by llj 2011-04-11 ������ˮ������
	rsUpdate.AddField(_T("Gross_Weight"),VT_R8);
	//Modify end
	rsUpdate.AddField(_T("Feed_Time"),VT_DATE);

	//2009-05-17 tangyiy �޸�Ϊ����
	CL3RecordSet *pRSdel = new CL3RecordSet();
	CL3RecordSetWrap rsDel; pRSdel->QueryInterface(IID_IL3RecordSet,rsDel); pRSdel->Release();
	rsDel.AddField(_T("MaterialType"),VT_BSTR);
	rsDel.AddField(_T("MaterialID"),VT_BSTR);
	rsDel.AddField(_T("Amount"),VT_R8);
	rsDel.AddField(_T("Status"),VT_I4);
	rsDel.AddField(_T("Feed_Time"),VT_DATE);
	rsDel.AddField(_T("Spare_Weight"),VT_R8);

	// ׼��������־
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(MIXF_FeedLog_URI,rsLog))
	{
		Rollback(nTrans);
		return -1;
	}
	rsLog.DelField(_T("GUID"));
	
	COleDateTime curDate = COleDateTime::GetCurrentTime();
	CString strUser = GetCurrentUser();

	// ������ˮ��Ϣ
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString IronID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString IronURI = CL3NameParser::MergeClassDomainName(MATERIAL_BFIRON_URI,IronID);
		// ������ˮ������
		CL3Variant valOrgWeight = GetObjectPropValue(IronURI,_T("Spare_Weight"));
		L3DOUBLE fOrgWeight = valOrgWeight.ToDouble();
		L3DOUBLE fMixWeight = rs.GetFieldByName(_T("Net_Weight")).ToDouble();
		L3DOUBLE fOff = fOrgWeight - fMixWeight;
		//if(fOff < -0.00000001)
		if(fOff < -0.005) //2009-06-10 tangyi
		{	// ��ˮ��������
			Rollback(nTrans);
			SetL3LastError(MESERR_MATERIAL_NOTENOUGH);
			return NULL;
		}
		else if(fOff < 0.00000001)
		{	// ����ȫ����ˮ
			rsDel.AppendRecord();
			//rsDel.CopyCurRowFrom(rs);//2008-12-23
			rsDel.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
			rsDel.SetFieldByName(_T("MaterialID"),CL3Variant(IronID));
			rsDel.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
			rsDel.SetFieldByName(_T("Status"),CL3Variant((LONG)Material::Deleted));
		    rsDel.SetFieldByName(_T("Feed_Time"),COleDateTime::GetCurrentTime());
			rsDel.SetFieldByName(_T("Spare_Weight"),CL3Variant((LONG)0));
		}
		else
		{	// ���벿����ˮ
			rsUpdate.AppendRecord();
			rsUpdate.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
			rsUpdate.SetFieldByName(_T("MaterialID"),CL3Variant(IronID));
			rsUpdate.SetFieldByName(_T("Spare_Weight"),CL3Variant(fOff));
			//Modify begin by llj 2011-04-11 ��ˮδ����ʱ����ë�ؽ���Ϊԭë��-������
			CString IronURI = CL3NameParser::MergeClassDomainName(MATERIAL_BFIRON_URI,IronID);
			// ��ȡ��ˮԭë��
			CL3Variant valGrossWeight = GetObjectPropValue(IronURI,_T("Gross_Weight"));
			L3DOUBLE fGrossWeight = valGrossWeight.ToDouble();
			fGrossWeight=fGrossWeight-fMixWeight;
			rsDel.SetFieldByName(_T("Gross_Weight"),CL3Variant(fGrossWeight));
			//Modify end
		    rsUpdate.SetFieldByName(_T("Feed_Time"),COleDateTime::GetCurrentTime());
		}
		// д��־
		rsLog.AppendRecord();
		rsLog.CopyCurRowFrom(rs);
		rsLog.SetFieldByName(_T("LogDate"),CL3Variant(curDate));
		//rsLog.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_BFIRON_URI));2009-01-08 tangyi
		rsLog.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CBFIron")));
		rsLog.SetFieldByName(_T("MaterialID"),CL3Variant(IronID));
		rsLog.SetFieldByName(_T("Amount"),CL3Variant(fMixWeight));
		rsLog.SetFieldByName(_T("MIFID"),CL3Variant(GetIdentity().ToCString()));//2009-04-25 tangyi
		//2009-01-08 tangyi
		CString csInputCacheUri = GetInputCache();
		CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
		CString csPos = valRet.ToCString();
		rsLog.SetFieldByName(_T("SourceArea"),CL3Variant(csPos));
		rsLog.SetFieldByName(_T("Operator"),CL3Variant(strUser));
		//rsLog.SetFieldByName(_T("LogTime"),CL3Variant(COleDateTime::GetCurrentTime()));
		rs.MoveNext();
	}
	// ����ˮ�������¯
	CL3RecordSet* pRsMix = new CL3RecordSet();
	CL3RecordSetWrap rsMix; pRsMix->QueryInterface(IID_IL3RecordSet,rsMix); pRsMix->Release();
	rsMix.AddField(_T("Net_Weight"),VT_R8);
	rsMix.AddField(_T("Mn"),VT_R8);
	rsMix.AddField(_T("P"),VT_R8);
	rsMix.AddField(_T("S"),VT_R8);
	rsMix.AddField(_T("Ti"),VT_R8);
	rsMix.AddField(_T("Si"),VT_R8);
	rsMix.AddField(_T("C"),VT_R8);
	//add by hyh 2012-05-11
	rsMix.AddField(_T("Sn"),VT_R8);
	rsMix.AddField(_T("Sb"),VT_R8);
	rsMix.AddField(_T("As"),VT_R8);
	rsMix.AddField(_T("Pb"),VT_R8);
	//end

	//add by hyh 2012-08-09 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	rsMix.AddField(_T("Ni"),VT_R8);
	rsMix.AddField(_T("Mo"),VT_R8);
	rsMix.AddField(_T("Cu"),VT_R8);
	rsMix.AddField(_T("Cr"),VT_R8);
	rsMix.AddField(_T("B"),VT_R8);
	rsMix.AddField(_T("V"),VT_R8);
	rsMix.AddField(_T("Al"),VT_R8);
	rsMix.AddField(_T("Nb"),VT_R8);
	rsMix.AddField(_T("Zn"),VT_R8);
	rsMix.AddField(_T("W"),VT_R8);
	//end

	rsMix.AppendRecord();
	CL3RecordSetWrap rsMixData = rs.Clone();
	rsMixData.AppendRecord();
	rsMixData.SetFieldByName(_T("Net_Weight"),GetPropValue(_T("Weight")));
	rsMixData.SetFieldByName(_T("C"),CL3Variant(/*C == 0 ? C_Cal : */C));
	rsMixData.SetFieldByName(_T("Si"),CL3Variant(/*Si == 0 ? Si_Cal : */Si));
	rsMixData.SetFieldByName(_T("Mn"),CL3Variant(/*Mn == 0 ? Mn_Cal : */Mn));
	rsMixData.SetFieldByName(_T("P"),CL3Variant(/*P == 0 ? P_Cal : */P));
	rsMixData.SetFieldByName(_T("S"),CL3Variant(/*S == 0 ? S_Cal : */S));
	rsMixData.SetFieldByName(_T("Ti"),CL3Variant(/*Ti == 0 ? Ti_Cal : */Ti));
	//add by hyh 2012-05-11
	rsMixData.SetFieldByName(_T("Sn"),CL3Variant(/*Sn == 0 ? Sn_Cal : */Sn));
	rsMixData.SetFieldByName(_T("Sb"),CL3Variant(/*Sb == 0 ? Sb_Cal : */Sb));
	rsMixData.SetFieldByName(_T("As"),CL3Variant(/*As == 0 ? As_Cal : */As));
	rsMixData.SetFieldByName(_T("Pb"),CL3Variant(/*Pb == 0 ? Pb_Cal : */Pb));
	//end

	//add by hyh 2012-08-09 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	rsMixData.SetFieldByName(_T("Ni"),CL3Variant(/*Ni == 0 ? Ni_Cal : */Ni));
	rsMixData.SetFieldByName(_T("Mo"),CL3Variant(/*Mo == 0 ? Mo_Cal : */Mo));
	rsMixData.SetFieldByName(_T("Cu"),CL3Variant(/*Cu == 0 ? Cu_Cal : */Cu));
	rsMixData.SetFieldByName(_T("Cr"),CL3Variant(/*Cr == 0 ? Cr_Cal : */Cr));
	rsMixData.SetFieldByName(_T("B"),CL3Variant(/*B == 0 ? B_Cal : */B));
	rsMixData.SetFieldByName(_T("V"),CL3Variant(/*V == 0 ? V_Cal : */V));
	rsMixData.SetFieldByName(_T("Al"),CL3Variant(/*Al == 0 ? Al_Cal : */Al));
	rsMixData.SetFieldByName(_T("Nb"),CL3Variant(/*Nb == 0 ? Nb_Cal : */Nb));
	rsMixData.SetFieldByName(_T("Zn"),CL3Variant(/*Zn == 0 ? Zn_Cal : */Zn));
	rsMixData.SetFieldByName(_T("W"),CL3Variant(/*W == 0 ? W_Cal : */W));
	//end

	rsMixData.MoveFirst();
	if(!CMIF_Mag::MixIrons(rsMixData,rsMix))
	{
		Rollback(nTrans);
		return 0;
	}
	SetPropValue(_T("Weight"),rsMix.GetFieldByName(_T("Net_Weight")));
	SetPropValue(_T("C_Cal"),rsMix.GetFieldByName(_T("C")));
	SetPropValue(_T("Si_Cal"),rsMix.GetFieldByName(_T("Si")));
	SetPropValue(_T("Mn_Cal"),rsMix.GetFieldByName(_T("Mn")));
	SetPropValue(_T("P_Cal"),rsMix.GetFieldByName(_T("P")));
	SetPropValue(_T("S_Cal"),rsMix.GetFieldByName(_T("S")));
	SetPropValue(_T("Ti_Cal"),rsMix.GetFieldByName(_T("Ti")));
	//add by hyh 2012-05-11
	SetPropValue(_T("Sn_Cal"),rsMix.GetFieldByName(_T("Sn")));
	SetPropValue(_T("Sb_Cal"),rsMix.GetFieldByName(_T("Sb")));
	SetPropValue(_T("As_Cal"),rsMix.GetFieldByName(_T("As")));
	SetPropValue(_T("Pb_Cal"),rsMix.GetFieldByName(_T("Pb")));
	//end

	//add by hyh 2012-08-13 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	SetPropValue(_T("Ni_Cal"),rsMix.GetFieldByName(_T("Ni")));
	SetPropValue(_T("Mo_Cal"),rsMix.GetFieldByName(_T("Mo")));
	SetPropValue(_T("Cu_Cal"),rsMix.GetFieldByName(_T("Cu")));
	SetPropValue(_T("Cr_Cal"),rsMix.GetFieldByName(_T("Cr")));
	SetPropValue(_T("B_Cal"),rsMix.GetFieldByName(_T("B")));
	SetPropValue(_T("V_Cal"),rsMix.GetFieldByName(_T("V")));
	SetPropValue(_T("Al_Cal"),rsMix.GetFieldByName(_T("Al")));
	SetPropValue(_T("Nb_Cal"),rsMix.GetFieldByName(_T("Nb")));
	SetPropValue(_T("Zn_Cal"),rsMix.GetFieldByName(_T("Zn")));
	SetPropValue(_T("W_Cal"),rsMix.GetFieldByName(_T("W")));
	//end

	//Modify begin by llj 2011-04-14 ��ˮ�ɷ��ƶ���Ȩƽ��
	/*
	SetPropValue(_T("C"),rsMix.GetFieldByName(_T("C")));
	SetPropValue(_T("Si"),rsMix.GetFieldByName(_T("Si")));
	SetPropValue(_T("Mn"),rsMix.GetFieldByName(_T("Mn")));
	SetPropValue(_T("P"),rsMix.GetFieldByName(_T("P")));
	SetPropValue(_T("S"),rsMix.GetFieldByName(_T("S")));
	SetPropValue(_T("Ti"),rsMix.GetFieldByName(_T("Ti")));
	*/
	//Modify end

	// ��ȫ���������ˮ����������Ƴ�����ɾ����־��
	if (rsDel.GetRowCount() > 0)
	{
		rsDel.MoveFirst();
		CL3Variant valRet = InvokeObjectMethod(BFIronStoreOutCache_URI,_T("RemoveMaterials"),(L3RECORDSET)rsDel);
		if(valRet.ToBOOL() == FALSE)
		{
			Rollback(nTrans);
			return 0;
		}
		rsDel.MoveFirst();
		if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rsDel))
		{
			Rollback(nTrans);
			return 0;
		}
	}
	// ��δȫ���������ˮ���޸���ʣ����
	if (rsUpdate.GetRowCount() > 0)
	{
		rsUpdate.MoveFirst();
		if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rsUpdate))
		{
			Rollback(nTrans);
			return 0;
		}
	}

	// ��¼��־
	rsLog.MoveFirst();
	if(CreateNewObjects(MIXF_FeedLog_URI,rsLog) < 1)
	{
		Rollback(nTrans);
		return 0;
	}

	Commit(nTrans);
	return rs.GetRowCount();
}

/// <Method class="CMIF_Unit_Mag" name="OutputIron" type="L3BOOL">
/// ��Ŀ����������
/// <Param name="LadleID" type="L3STRING">Ŀ��������</Param>
/// <Param name="fWeight" type="L3DOUBLE">��������</Param>
/// <Param name="fReHeatWeight" type="L3DOUBLE">��¯������</Param>
/// </Method>
L3BOOL CMIF_Unit_Mag::OutputIron(L3STRING LadleID, L3DOUBLE fWeight,L3DOUBLE fReHeatWeight,L3STRING Destination)
{
	CString strLadle = ::String_BSTR2TChar(LadleID);
	CString dest=Destination;

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return FALSE;

	// ����������¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		Rollback(nTrans);
		return FALSE;
	}

	// �������
	if(Weight < fWeight)
	{
		Rollback(nTrans);
		SetL3LastError(MESERR_MATERIAL_NOTENOUGH);
		return FALSE;
	}

	// ������ˮ����
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strIronID; strIronID.Format(_T("%s_%04d%02d%02d%02d%02d%02d"),(LPCTSTR)strLadle,curTime.GetYear(),curTime.GetMonth(),curTime.GetDay(),curTime.GetHour(),curTime.GetMinute(),curTime.GetSecond());
	CL3RecordSetWrap rsIron;
	if(!CreateClassPropSet(MATERIAL_IRON_URI,rsIron))
	{
		Rollback(nTrans);
		return FALSE;
	}
	rsIron.AppendRecord();
	rsIron.SetFieldByName(_T("MaterialID"),CL3Variant(strIronID));
	rsIron.SetFieldByName(_T("IronLadleNo"),CL3Variant(strLadle));
	rsIron.SetFieldByName(_T("Weight"),CL3Variant(fWeight));
	rsIron.SetFieldByName(_T("Return_Steel_Weight"),CL3Variant(fReHeatWeight));
	rsIron.SetFieldByName(_T("Tap_Time"),CL3Variant(curTime));
	//add by hyh 2012-04-26
	if(GetIdentity().ToCString() == _T("S11"))
		rsIron.SetFieldByName(_T("Source"),CL3Variant((LONG)CIron_Data::FromMix1));
	else if(GetIdentity().ToCString() == _T("S12"))
		rsIron.SetFieldByName(_T("Source"),CL3Variant((LONG)CIron_Data::FromMix2));
	else
		rsIron.SetFieldByName(_T("Source"),CL3Variant((LONG)CIron_Data::FromMix3));
	//end
	rsIron.SetFieldByName(_T("IronTemp"),GetPropValue(_T("Temp")));
	//Modify begin by llj ����ʱʹ�ü���Ԫ��
	rsIron.SetFieldByName(_T("C"),GetPropValue(_T("C_Cal")));
	rsIron.SetFieldByName(_T("Si"),GetPropValue(_T("Si_Cal")));
	rsIron.SetFieldByName(_T("Mn"),GetPropValue(_T("Mn_Cal")));
	rsIron.SetFieldByName(_T("P"),GetPropValue(_T("P_Cal")));
	rsIron.SetFieldByName(_T("S"),GetPropValue(_T("S_Cal")));
	rsIron.SetFieldByName(_T("Ti"),GetPropValue(_T("Ti_Cal")));
	//add by hyh 2012-04-26
	rsIron.SetFieldByName(_T("Sn"),GetPropValue(_T("Sn_Cal")));
	rsIron.SetFieldByName(_T("Sb"),GetPropValue(_T("Sb_Cal")));
	rsIron.SetFieldByName(_T("As"),GetPropValue(_T("As_Cal")));
	rsIron.SetFieldByName(_T("Pb"),GetPropValue(_T("Pb_Cal")));
	//end

	//add by hyh 2012-08-13 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	rsIron.SetFieldByName(_T("Ni"),GetPropValue(_T("Ni_Cal")));
	rsIron.SetFieldByName(_T("Mo"),GetPropValue(_T("Mo_Cal")));
	rsIron.SetFieldByName(_T("Cu"),GetPropValue(_T("Cu_Cal")));
	rsIron.SetFieldByName(_T("Cr"),GetPropValue(_T("Cr_Cal")));
	rsIron.SetFieldByName(_T("B"),GetPropValue(_T("B_Cal")));
	rsIron.SetFieldByName(_T("V"),GetPropValue(_T("V_Cal")));
	rsIron.SetFieldByName(_T("Al"),GetPropValue(_T("Al_Cal")));
	rsIron.SetFieldByName(_T("Nb"),GetPropValue(_T("Nb_Cal")));
	rsIron.SetFieldByName(_T("Zn"),GetPropValue(_T("Zn_Cal")));
	rsIron.SetFieldByName(_T("W"),GetPropValue(_T("W_Cal")));
	//end
	//Modify end
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rsIron.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsIron.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
	rsIron.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	if(CreateNewObjects(MATERIAL_IRON_URI,rsIron) < 1)
	{
		Rollback(nTrans);
		return FALSE;
	}

	// �޸�ʣ������
	Weight -= fWeight;

	// ������ˮ�����������
	rsIron.AddField(_T("MaterialType"),VT_BSTR);
	rsIron.AddField(_T("Amount"),VT_R8);
	rsIron.MoveFirst();
	rsIron.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CIron_Data")));
	rsIron.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
	CL3Variant valRet;
	if(dest=="1")
	{
	 valRet = InvokeObjectMethod(MIXFProduceCache_URI,_T("AddMaterials"),(L3RECORDSET)rsIron);
	}
	else
	{
	valRet = InvokeObjectMethod(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S91P01"),_T("AddMaterials"),(L3RECORDSET)rsIron);
	}
	
	if(valRet.ToBOOL() == FALSE)
	{
		Rollback(nTrans);
		return FALSE;
	}

	// ������״̬��Ϊ����
	CString strLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,strLadle);
	SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_USE));
	
	//2009-05-26
	long iIronLadleAge = GetObjectPropValue(strLadleURI,_T("IronLadle_Age")).ToLong();
	iIronLadleAge += 1;

	SetObjectPropValue(strLadleURI,_T("IronLadle_Age"),CL3Variant(L3LONG(iIronLadleAge)));


	Commit(nTrans);

	return TRUE;
}

/// <Method class="CMIF_Unit_Mag" name="AcceptIronLadleWeightData" type="L3BOOL">
/// ���ջ���¯�������� 2009-01-04
/// <Param name="rsData" type="L3RECORDSET">����¯��������</Param>
/// </Method>
L3BOOL CMIF_Unit_Mag::AcceptIronLadleWeightData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveLast();
	L3DOUBLE fWeight = rs.GetFieldByName(_T("Weight")).ToDouble();
    Gross_Weight=fWeight;
	Gross_Weight_Time = COleDateTime::GetCurrentTime();

	//��¼��������
	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\MIXFMag\\CMIF_Weight"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	CString csShift = rpSysInfo.GetFieldByName(_T("ShiftID")).ToCString();
	CString csTeam = rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("Source"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("Shift"),CL3Variant(csShift));
		rsTemp.SetFieldByName(_T("Team"),CL3Variant(csTeam));
		rsTemp.SetFieldByName(_T("Weight_Time"),CL3Variant(COleDateTime::GetCurrentTime()));

		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\MIXFMag\\CMIF_Weight"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CMIF_Unit_Mag" name="AcceptTemperatureData" type="L3BOOL">
/// ���ջ���¯�������� 2009-01-04
/// <Param name="rsData" type="L3RECORDSET">����¯��������</Param>
/// </Method>
L3BOOL CMIF_Unit_Mag::AcceptTemperatureData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveLast();
	L3LONG iTemp = rs.GetFieldByName(_T("Temp")).ToLong();
    Temp = iTemp;
	Temp_Time = COleDateTime::GetCurrentTime();

	//��¼��������
	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\MIXFMag\\CMIF_Temp_Data"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	CString csShift = rpSysInfo.GetFieldByName(_T("ShiftID")).ToCString();
	CString csTeam = rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("MIFID"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("Shift"),CL3Variant(csShift));
		rsTemp.SetFieldByName(_T("Team"),CL3Variant(csTeam));
		rsTemp.SetFieldByName(_T("Temp_Time"),CL3Variant(COleDateTime::GetCurrentTime()));

		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\MIXFMag\\CMIF_Temp_Data"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CMIF_Unit_Mag" name="AcceptDirectIronWeightData" type="L3BOOL">
/// ���ջ���¯������������������ 2009-01-04
/// <Param name="rsData" type="L3RECORDSET">������������������</Param>
/// </Method>
L3BOOL CMIF_Unit_Mag::AcceptDirectIronWeightData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveLast();
	L3DOUBLE fWeight = rs.GetFieldByName(_T("Weight")).ToDouble();
    Tare_Weight = fWeight;
	Tare_Weight_Time = COleDateTime::GetCurrentTime();

	return TRUE;	
}



/// <Method class="CMIF_Unit_Mag" name="OutputIronCancel" type="L3BOOL">
/// ȡ������¯����2009-03-11
/// </Method>
L3LONG CMIF_Unit_Mag::OutputIronCancel(L3RECORDSET rsLadleID)
{
	CL3RecordSetWrap rs = rsLadleID;
	if(rs.GetRowCount() < 1 || rs.IsNull())
		return -1;

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	// ����������¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		Rollback(nTrans);
		return -2;
	}

	//�齨���ݼ�
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("Amount"),VT_INT);
	rsMaterial.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//�޸�ʣ������
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csIronUri = CL3NameParser::MergeClassDomainName(MATERIAL_IRON_URI,csMaterialID);
		CString csHeatID = GetObjectPropValue(csIronUri,_T("HeatID")).ToCString();
		csHeatID.Trim();
		//�Ѿ�ָ����ԭ�ϲ�����ȡ��
		if(!csHeatID.IsEmpty())
		{
			Rollback(nTrans);
			return -3;
		}
		L3LONG nSource = GetObjectPropValue(csIronUri,_T("Source")).ToLong();
		//ֱ����ˮ������ȡ��
		if(nSource < 1)
		{
			Rollback(nTrans);
			return -4;
		}
		L3DOUBLE fWeight = GetObjectPropValue(csIronUri,_T("Weight")).ToDouble();
		Weight += fWeight;

		//����������״̬Ϊ�ȱ�
		CString csIronLadle = GetObjectPropValue(csIronUri,_T("IronLadleNo")).ToCString();
		CString csLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,csIronLadle);
		if(!SetObjectPropValue(csLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT)))
		{
			Rollback(nTrans);
			return -7;
		}

		//ɾ����ˮ����
		if(!DeleteOldObject(csIronUri))
		{
			Rollback(nTrans);
			return -5;
		}
		// ������ˮ�Ƴ���������
		rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_IRON));
		rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rsMaterial.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		CL3Variant valRet = InvokeObjectMethod(MIXFProduceCache_URI,_T("RemoveMaterials"),(L3RECORDSET)rsMaterial);
		if(valRet.ToBOOL() == FALSE)
		{
			Rollback(nTrans);
			return -6;
		}

		rsMaterial.MoveFirst();
		rs.MoveNext();
	}

	Commit(nTrans);

	return 1;
}

//ȡ��ȥ����վ�ĳ���
L3LONG CMIF_Unit_Mag::OutputIronCancelToDEP(L3RECORDSET rsLadleID)
{
	CL3RecordSetWrap rs = rsLadleID;
	if(rs.GetRowCount() < 1 || rs.IsNull())
		return -1;

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	// ����������¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		Rollback(nTrans);
		return -2;
	}

	//�齨���ݼ�
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("Amount"),VT_INT);
	rsMaterial.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//�޸�ʣ������
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csIronUri = CL3NameParser::MergeClassDomainName(MATERIAL_IRON_URI,csMaterialID);
		CString csHeatID = GetObjectPropValue(csIronUri,_T("HeatID")).ToCString();
		csHeatID.Trim();
		//�Ѿ�ָ����ԭ�ϲ�����ȡ��
		if(!csHeatID.IsEmpty())
		{
			Rollback(nTrans);
			return -3;
		}
		L3LONG nSource = GetObjectPropValue(csIronUri,_T("Source")).ToLong();
		//ֱ����ˮ������ȡ��
		if(nSource < 1)
		{
			Rollback(nTrans);
			return -4;
		}
		L3DOUBLE fWeight = GetObjectPropValue(csIronUri,_T("Weight")).ToDouble();
		Weight += fWeight;

		//����������״̬Ϊ�ȱ�
		CString csIronLadle = GetObjectPropValue(csIronUri,_T("IronLadleNo")).ToCString();
		CString csLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,csIronLadle);
		if(!SetObjectPropValue(csLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT)))
		{
			Rollback(nTrans);
			return -7;
		}

		//ɾ����ˮ����
		if(!DeleteOldObject(csIronUri))
		{
			Rollback(nTrans);
			return -5;
		}
		// ������ˮ�Ƴ���������
		rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_IRON));
		rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rsMaterial.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S91P01"),_T("RemoveMaterials"),(L3RECORDSET)rsMaterial);
		if(valRet.ToBOOL() == FALSE)
		{
			Rollback(nTrans);
			return -6;
		}

		rsMaterial.MoveFirst();
		rs.MoveNext();
	}

	Commit(nTrans);

	return 1;
}

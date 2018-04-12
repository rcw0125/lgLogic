// �߼���CBOF_Prod_Area���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CBOF_Prod_Area.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CBOF_Prod_Area.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CBOF_Prod_Area.h"
#include "L3NameParser.h"

//������װ�ص�ϵͳ��ʱ��������
void CBOF_Prod_Area::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CBOF_Prod_Area::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ����λ�ñ�����麯�����̳���������ش˺��������Լ���λ�ñ��붨�塣
/// ARG >> void
/// RET << λ�ñ���
/// </summary>
CString CBOF_Prod_Area::GetPositionCode()
{
	return GetPropValue(_T("Code")).ToCString();
}

/// <summary>
/// �ӹ�ǰԤ�����ڽ��мӹ��߼�����ǰ���ã��̳�������ش˺�����������Ԥ����
/// ARG >> rsParameter : �ӹ�������¼����
/// RET << ����TRUE�����ӹ�������FALSE�жϼӹ���
/// </summary>
BOOL CBOF_Prod_Area::OnBeforeProcess(L3RECORDSET rsParameter)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeProcess( rsParameter);
}

/// <summary>
/// ���ϼӹ��߼������̳�����Ҫ���ش˺����������ض��Ĳ��ϼӹ�����
/// ע�⣺�ڴ˷����в�Ҫ�Լӹ���ص����ݽ���ֱ���޸ģ�����������������������
/// ARG >> rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
///		>> rsParameter : �ӹ�ʹ�õĲ�����¼����
///		<< pnProcessType : �ɹ��󷵻ؼӹ����͡�
///		<< prsProducts : �ɹ��󷵻ز�Ʒ���ݼ�¼��
///		<< prsMaterialMap : ����ӹ�������CreateNew���ɹ��󷵻�ԭ�ϳ�Ʒ���ձ��������á�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBOF_Prod_Area::ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap)
{
	CL3RecordSetWrap rsMat = rsMaterials;
	CL3RecordSetWrap rsParam = rsParameter;

	if(rsMat.GetRowCount() < 1 || rsParam.GetRowCount() < 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}
	
	rsParam.MoveFirst();
	CString strHeatID = rsParam.GetFieldByName(_T("HeatID")).ToCString(); strHeatID.Trim();
	if(strHeatID.IsEmpty())
	{	
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	// ��ѯ�ƻ�����
	CL3RecordSetWrap rsPlan;
	CString strPlan; strPlan.Format(_T("select * from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,(LPCTSTR)GetRealHeatID(strHeatID));
	Query(strPlan,rsPlan);
	if(rsPlan.GetRowCount() > 0)
		rsPlan.MoveFirst();
	CString strPreHeatID = rsPlan.GetFieldByName(_T("PreHeatID")).ToCString();
	//2008-12-25 tangyi �ְ���ת¯ʵ���в���
	CString strLadleID = GetObjectPropValue(CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,strHeatID),_T("LadleNo")).ToCString();

	// ���ְ�״̬�趨Ϊ����
	//CString strLadleURI = CL3NameParser::MergeClassDomainName(CLADLE_BASE_URI,strLadleID);
	//SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CLADLE_STATUS_USE));

	// �����¸�ˮ����
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(MATERIAL_STEEL_URI,rsSteel))
		return FALSE;
	rsSteel.AddField(MESPROP_MATERIAL_TYPE,VT_BSTR);
	rsSteel.AddField(MESPROP_AMOUNT,VT_R8);
	rsSteel.AppendRecord();
	if(rsPlan.GetRowCount() > 0)
		rsSteel.CopyCurRowFrom(rsPlan);
	rsSteel.SetFieldByName(MESPROP_MATERIAL_TYPE,CL3Variant(_T("CSteel_Data")));
	rsSteel.SetFieldByName(MESPROP_MATERIAL_ID,CL3Variant(strHeatID));
	rsSteel.SetFieldByName(MESPROP_AMOUNT,CL3Variant((L3DOUBLE)1));
	rsSteel.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	rsSteel.SetFieldByName(_T("LadleID"),CL3Variant(strLadleID));
	rsSteel.SetFieldByName(_T("Status"),CL3Variant((LONG)1));

	// �����������
	CL3RecordSetWrap rsMap;
	if(!CreateClassPropSet(MES_MATERIAL_MAP,rsMap))
		return FALSE;
	rsMat.MoveFirst();
	while(!rsMat.IsEOF())
	{
		rsMap.AppendRecord();
		rsMap.SetFieldByName(_T("FromType"),CL3Variant(_T("CIron_Data")));
		rsMap.SetFieldByName(_T("FromID"),rsMat.GetFieldByName(_T("MaterialID")));
		rsMap.SetFieldByName(_T("ToType"),CL3Variant(_T("CSteel_Data")));
		rsMap.SetFieldByName(_T("ToID"),CL3Variant(strHeatID));
		rsMap.SetFieldByName(_T("SrcAmount"),rsMat.GetFieldByName(_T("Net_Weight")));
		rsMap.SetFieldByName(_T("TgtAmount"),CL3Variant((LONG)1));
		rsMat.MoveNext();
	}

	*pnProcessType = ProduceArea::CreateNew;
	*prsProducts = rsSteel.Detach();
	*prsMaterialMap = rsMap.Detach();

	return TRUE;
}

/// <summary>
/// �ӹ����������ڼӹ��߼�������ɺ���ã��̳�������ش˺������ж��⴦��
/// ARG >> rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
///		>> rsParameter : �ӹ�ʹ�õĲ�����¼����
///		>> pnProcessType : �ӹ����͡�
///		>> rsProducts : ��Ʒ���ݼ�¼��
///		>> rsMaterialMap : ����ӹ�������CreateNew��Ϊԭ�ϳ�Ʒ���ձ��������á�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBOF_Prod_Area::OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessed( rsMaterials, rsParameter, nProcessType, rsProducts, rsMaterialMap);
}

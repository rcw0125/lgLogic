// �߼���CCCM_Prod_Area���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CCCM_Prod_Area.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CCCM_Prod_Area.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CCCM_Prod_Area.h"
#include "MaterialMap.h"

//������װ�ص�ϵͳ��ʱ��������
void CCCM_Prod_Area::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CCCM_Prod_Area::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ����λ�ñ�����麯�����̳���������ش˺��������Լ���λ�ñ��붨�塣
/// ARG >> void
/// RET << λ�ñ���
/// </summary>
CString CCCM_Prod_Area::GetPositionCode()
{
	return GetPropValue(_T("Code")).ToCString();
}

/// <summary>
/// �ӹ�ǰԤ�����ڽ��мӹ��߼�����ǰ���ã��̳�������ش˺�����������Ԥ����
/// ARG >> rsParameter : �ӹ�������¼����
/// RET << ����TRUE�����ӹ�������FALSE�жϼӹ���
/// </summary>
BOOL CCCM_Prod_Area::OnBeforeProcess(L3RECORDSET rsParameter)
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
BOOL CCCM_Prod_Area::ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap)
{
	CL3RecordSetWrap rsMat = rsMaterials;
	CL3RecordSetWrap rsParam = rsParameter;
	if(rsMat.GetRowCount() != 1 || rsParam.GetRowCount() != 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	// ���ɸ�������
	CL3RecordSetWrap rsBloom;
	if(!CreateClassPropSet(BLOOM_DATA_CLASS_URI,rsBloom))
		return FALSE;
	rsBloom.AddField(_T("MaterialType"),VT_BSTR);
	rsBloom.AddField(_T("Amount"),VT_DECIMAL);
	rsMat.MoveFirst();
	//rsParam.MoveFirst();
	rsBloom.AppendRecord();
	rsBloom.CopyCurRowFrom(rsMat);
	//rsBloom.CopyCurRowFrom(rsParam);
	rsBloom.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BLOOM));
	//2009-04-15 tangyi
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	rsBloom.SetFieldByName(_T("Produce_Date"),CL3Variant(timeNow));

	// ���ɲ��϶��ձ�
	CL3RecordSetWrap rsMap;
	if(!CreateClassPropSet(MES_MATERIAL_MAP,rsMap))
		return FALSE;
	rsMap.AppendRecord();
	rsMap.SetFieldByName(_T("FromType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMap.SetFieldByName(_T("ToType"),CL3Variant(MATERIAL_TYPE_BLOOM));
	rsMap.SetFieldByName(_T("FromID"),rsMat.GetFieldByName(_T("MaterialID")));
	rsMap.SetFieldByName(_T("ToID"),rsBloom.GetFieldByName(_T("HeatID")));
	rsMap.SetFieldByName(_T("SrcAmount"),CL3Variant((LONG)1));
	rsMap.SetFieldByName(_T("TgtAmount"),CL3Variant((LONG)1));
	rsMap.SetFieldByName(_T("Mode"),CL3Variant((LONG)MaterialMap::Produce));
	rsMap.SetFieldByName(_T("Mapper"),CL3Variant(GetPositionCode()));

	*pnProcessType = ProduceArea::CreateNew;
	*prsProducts = rsBloom.Detach();
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
BOOL CCCM_Prod_Area::OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessed( rsMaterials, rsParameter, nProcessType, rsProducts, rsMaterialMap);
}

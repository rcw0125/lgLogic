// �߼���XGProduceArea���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_XGProduceArea.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_XGProduceArea.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_XGProduceArea.h"

//������װ�ص�ϵͳ��ʱ��������
void XGProduceArea::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void XGProduceArea::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
///	���ظû�������ȫ��λ�ñ��롣�˱��������ȫ��Ψһ�ģ�
/// </summary>
CString XGProduceArea::GetPositionCode()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return GetPropValue(_T("Code")).ToCString();
}


/// <summary>
/// �ӹ�ǰԤ�����ڽ��мӹ��߼�����ǰ���ã��̳�������ش˺�����������Ԥ����
/// ARG >> rsParameter : �ӹ�������¼����
/// RET << ����TRUE�����ӹ�������FALSE�жϼӹ���
/// </summary>
BOOL XGProduceArea::OnBeforeProcess(L3RECORDSET rsParameter)
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
BOOL XGProduceArea::ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::ProcessMaterials( rsMaterials, rsParameter, pnProcessType, prsProducts, prsMaterialMap);
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
BOOL XGProduceArea::OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessed( rsMaterials, rsParameter, nProcessType, rsProducts, rsMaterialMap);
}




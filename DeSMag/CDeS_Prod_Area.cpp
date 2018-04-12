// �߼���CDeS_Prod_Area���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CDeS_Prod_Area.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CDeS_Prod_Area.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CDeS_Prod_Area.h"

#define PROCTIME_PERIOD		5000
#define BLOWTIME_PERIOD     5

//������װ�ص�ϵͳ��ʱ��������
void CDeS_Prod_Area::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CDeS_Prod_Area::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// �ӹ�ǰԤ�����ڽ��мӹ��߼�����ǰ���ã��̳�������ش˺�����������Ԥ����
/// ARG >> rsParameter : �ӹ�������¼����
/// RET << ����TRUE�����ӹ�������FALSE�жϼӹ���
/// </summary>
BOOL CDeS_Prod_Area::OnBeforeProcess(L3RECORDSET rsParameter)
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
BOOL CDeS_Prod_Area::ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap)
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
BOOL CDeS_Prod_Area::OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessed( rsMaterials, rsParameter, nProcessType, rsProducts, rsMaterialMap);
}

/// <Method class="CDeS_Prod_Area" name="OnTimer" type="L3BOOL">
/// ����ʱ���¼�
/// <Param name="nEventID" type="L3ULONG">��ʱ���¼�ID</Param>
/// </Method>
L3BOOL CDeS_Prod_Area::OnTimer(L3ULONG nEventID)
{
	if(nEventID == m_iTimer)
	{	
		BlowTime += BLOWTIME_PERIOD;
	}

	return TRUE;
}

/// <Method class="CDeS_Prod_Area" name="SetDeSAreaTimer" type="L3BOOL">
/// ������ʱ���¼�
/// </Method>
L3BOOL CDeS_Prod_Area::SetDeSAreaTimer()
{
	BlowTime = 0;
	m_iTimer = SetTimer(GetURI(),PROCTIME_PERIOD);

	return TRUE;
}

/// <Method class="CDeS_Prod_Area" name="KillDeSAreaTimer" type="L3BOOL">
/// ֹͣ��ʱ���¼�
/// </Method>
L3BOOL CDeS_Prod_Area::KillDeSAreaTimer()
{
	if(m_iTimer != 0)
		KillTimer(GetURI(),m_iTimer);
	m_iTimer = 0;

	return TRUE;
}

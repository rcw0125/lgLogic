// �߼���CCCM_ProdArea���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CCCM_ProdArea.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CCCM_ProdArea.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CCCM_ProdArea.h"

//������װ�ص�ϵͳ��ʱ��������
void CCCM_ProdArea::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CCCM_ProdArea::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


/// <Method class="CCCM_ProdArea" name="ProcessMaterials" type="L3BOOL">
/// 
/// ���ϼӹ��߼������̳�����Ҫ���ش˺����������ض��Ĳ��ϼӹ�����
/// ע�⣺�ڴ˷����в�Ҫ�Լӹ���ص����ݽ���ֱ���޸ģ�����������������������
/// ARG &gt;&gt; rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
/// &gt;&gt; rsParameter : �ӹ�ʹ�õĲ�����¼����
/// &lt;&lt; pnProcessType : �ɹ��󷵻ؼӹ����͡�
/// &lt;&lt; prsProducts : �ɹ��󷵻ز�Ʒ���ݼ�¼��
/// &lt;&lt; prsMaterialMap : ����ӹ�������CreateNew���ɹ��󷵻�ԭ�ϳ�Ʒ���ձ��������á�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsMaterials" type="L3RECORDSET"></Param>
/// <Param name="rsParameter" type="L3RECORDSET"></Param>
/// <Param name="pnProcessType" type="L3LONG*"></Param>
/// <Param name="prsMaterialMap" type="L3RECORDSET*"></Param>
/// <Param name="prsProducts" type="L3RECORDSET*"></Param>
/// </Method>
L3BOOL CCCM_ProdArea::ProcessMaterials(L3RECORDSET rsMaterials, L3RECORDSET rsParameter, L3LONG* pnProcessType, L3RECORDSET* prsMaterialMap, L3RECORDSET* prsProducts)
{
	return 0;
}

// �߼���CMIF_Communicator���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CMIF_Communicator.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CMIF_Communicator.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CMIF_Communicator.h"

//������װ�ص�ϵͳ��ʱ��������
void CMIF_Communicator::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CMIF_Communicator::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


/// <Method class="CMIF_Communicator" name="OnMIFTemperature" type="L3BOOL">
/// ����¯�¶����ݵ����¼���Ӧ����
/// <Param name="rsTemp" type="L3RECORDSET">�¶�����(¯����,�¶�ֵ,����ʱ��)</Param>
/// </Method>
L3BOOL CMIF_Communicator::OnMIFTemperature(L3RECORDSET rsTemp)
{
    return 0; 
}

/// <Method class="CMIF_Communicator" name="OnWeight" type="L3BOOL">
/// �����¼����ﴦ����
/// <Param name="rsWeight" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CMIF_Communicator::OnWeight(L3RECORDSET rsWeight)
{
    return 0; 
}

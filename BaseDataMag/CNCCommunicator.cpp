// �߼���CNCCommunicator���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CNCCommunicator.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CNCCommunicator.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CNCCommunicator.h"

//������װ�ص�ϵͳ��ʱ��������
void CNCCommunicator::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CNCCommunicator::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}



/// <Method class="CNCCommunicator" name="SendCastIronDataToNC" type="LONG">
/// ����ˮ��Ϣ���͵�NCϵͳ��
/// <Param name="rsIron" type="L3RECORDSET">������ˮ��Ϣ�ļ�¼��</Param>
/// </Method>
LONG CNCCommunicator::SendCastIronDataToNC(L3RECORDSET rsIron)
{
	// TODO : ���ڴ�����߼�����
	return 0;
}

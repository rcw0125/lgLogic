// �߼���CAlloy_Store_Communicator���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CAlloy_Store_Communicator.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CAlloy_Store_Communicator.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CAlloy_Store_Communicator.h"

//������װ�ص�ϵͳ��ʱ��������
void CAlloy_Store_Communicator::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CAlloy_Store_Communicator::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


/// <summary>
/// ����յ��ĵ��ĵ���Ч��
/// ARG >> lpcszSender : ���ķ����߱�ʶ��
///		>> lpcszTelType : ��������
///		>> lpcszTelID : ���ı��
///		>> rsTelData : ��������
/// RET << ����FALSEϵͳ�����Դ˵��ġ�����TRUEϵͳ��������˵��ġ�
/// </summary>
BOOL CAlloy_Store_Communicator::CheckRecvTelegram(LPCTSTR lpcszSender,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::CheckRecvTelegram( lpcszSender, lpcszTelType, lpcszTelID, rsTelData);
}

/// <summary>
/// ���յ����������ơ��̳������ش˺���ʵ���ܼ����ĵ��������ơ�
/// ARG >> lpcszSender : ���ķ����߱�ʶ��
///		>> lpcszTgt : ���ĵ�Ŀ�Ķ���URI
///		>> lpcszTelType : ��������
///		>> lpcszTelID : ���ı��
///		>> rsTelData : �������ݡ��������ƽ������޸Ĵ�
/// RET << �������ƽ�����μ�RecvPaceCtrlResult
/// </summary>
DWORD CAlloy_Store_Communicator::RecvPaceControl(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::RecvPaceControl( lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, rsTelData);
}

/// <summary>
/// ��ȡ����Ŀ�Ķ����URI
/// ARG >> lpcszSender : ���ķ����߱�ʶ��
///		>> lpcszTelType : ��������
///		>> lpcszTelID : ���ı��
///		>> rsTelData : ��������
/// RET << ���մ˵��ĵĶ����URI
CString CAlloy_Store_Communicator::GetTelegramTarget(LPCTSTR lpcszSender,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetTelegramTarget( lpcszSender, lpcszTelType, lpcszTelID, rsTelData);
}

/// <summary>
/// �����յ��������ݡ��̳�������ش˷�����������ĵ��Ļ�����ơ��磺�Զ̼�����ۼ������ģ������ò��룬���ǲ����ۼӵķ�ʽ�������ݡ�
/// ARG >> lpcszSender : ���ķ����߱�ʶ��
///		>> lpcszTgt : ���ĵ�Ŀ�Ķ���URI
///		>> lpcszTelType : ��������
///		>> lpcszTelID : ���ı��
///		>> rsTelData : ��������
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CAlloy_Store_Communicator::CacheRecvTelegramData(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::CacheRecvTelegramData( lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, rsTelData);
}

/// <summary>
/// ���ص������Ͷ�Ӧ��MESϵͳ�����������URI
/// ARG >> lpczTelType : ������������
/// RET << �����������URI��
/// </summary>
CString CAlloy_Store_Communicator::GetTelegramDataType(LPCTSTR lpcszType)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetTelegramDataType( lpcszType);
}

/// <summary>
/// ���յ��Ĵ����߼����̳������ش˺������е��ĵ�ʵ�ʽ��մ���������֪ͨ���������ض����ȡ�
/// ARG >> lpcszSender : ���ķ����߱�ʶ��
///		>> lpcszTgt : ���ĵ�Ŀ�Ķ���URI
///		>> lpcszTelType : ��������
///		>> lpcszTelID : ���ı��
///		>> lpcszDataType : �������ݻ�������
///		>> rsTelData : ��������
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CAlloy_Store_Communicator::DoAcceptTelegram(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,LPCTSTR lpcszDataType,L3RECORDSET rsTelData)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::DoAcceptTelegram( lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, lpcszDataType, rsTelData);
}

/// <summary>
/// ���ص��Ķ�Ӧ���߼��¼�������
/// ARG >> lpcszSender : ���ķ����߱�ʶ��
///		>> lpcszTgt : ���ĵ�Ŀ�Ķ���URI
///		>> lpcszTelType : ��������
///		>> lpcszTelID : ���ı��
///		>> rsTelData : ��������
/// RET << �߼��¼�����
/// </summary>
CString CAlloy_Store_Communicator::GetRecvTelEventType(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetRecvTelEventType( lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, rsTelData);
}

/// <summary>
/// ׼�����յ����¼����ݡ��̳������ش˺���������Ľ����¼��Ķ��������
/// ARG >> evt : �¼�����.
///		>> lpcszSender : ���ķ����߱�ʶ��
///		>> lpcszTgt : ���ĵ�Ŀ�Ķ���URI
///		>> lpcszTelType : ��������
///		>> lpcszTelID : ���ı��
///		>> lpcszDataType : �������ݻ�������
///		>> rsTelData : ��������
///	RET << void
/// </summary>
void CAlloy_Store_Communicator::PrepareRecvEvent(CL3EventWrap& evt,LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,LPCTSTR lpcszDataType,L3RECORDSET rsTelData)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::PrepareRecvEvent( evt, lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, lpcszDataType, rsTelData);
}

/// <summary>
/// ʵ�ʵķ��͵��ķ������̳������ش˷������е���ͨѶ
/// ARG >> Sender : ���͵��ĵĶ����URI.
///		>> Receiver : ���Ľ����߱�ʶ��
///		>> TelegramType : ��������
///		>> TelegramID : ���ı��
///		>> rsTelegram : ��������
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
L3BOOL CAlloy_Store_Communicator::DoSendTelegram(L3STRING Sender,L3STRING Receiver,L3STRING TelegramType,L3STRING TelegramID,L3RECORDSET rsTelegram)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::DoSendTelegram( Sender, Receiver, TelegramType, TelegramID, rsTelegram);
}


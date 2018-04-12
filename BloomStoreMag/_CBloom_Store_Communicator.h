// �߼���CBloom_Store_Communicatorͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MESCommunicator.h"

class CBloom_Store_Communicator :
	public MESCommunicator
{
public:
	CBloom_Store_Communicator(void);
	virtual ~CBloom_Store_Communicator(void);

	DECLARE_L3CLASS(CBloom_Store_Communicator,XGMESLogic\\BloomStoreMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Store_Communicator)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:
	/// <summary>
	/// ����յ��ĵ��ĵ���Ч��
	/// ARG >> lpcszSender : ���ķ����߱�ʶ��
	///		>> lpcszTelType : ��������
	///		>> lpcszTelID : ���ı��
	///		>> rsTelData : ��������
	/// RET << ����FALSEϵͳ�����Դ˵��ġ�����TRUEϵͳ��������˵��ġ�
	/// </summary>
	virtual BOOL CheckRecvTelegram(LPCTSTR lpcszSender,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
	/// <summary>
	/// ���յ����������ơ��̳������ش˺���ʵ���ܼ����ĵ��������ơ�
	/// ARG >> lpcszSender : ���ķ����߱�ʶ��
	///		>> lpcszTgt : ���ĵ�Ŀ�Ķ���URI
	///		>> lpcszTelType : ��������
	///		>> lpcszTelID : ���ı��
	///		>> rsTelData : �������ݡ��������ƽ������޸Ĵ�
	/// RET << �������ƽ�����μ�RecvPaceCtrlResult
	/// </summary>
	virtual DWORD RecvPaceControl(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
	/// <summary>
	/// ��ȡ����Ŀ�Ķ����URI
	/// ARG >> lpcszSender : ���ķ����߱�ʶ��
	///		>> lpcszTelType : ��������
	///		>> lpcszTelID : ���ı��
	///		>> rsTelData : ��������
	/// RET << ���մ˵��ĵĶ����URI
	virtual CString GetTelegramTarget(LPCTSTR lpcszSender,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
	/// <summary>
	/// �����յ��������ݡ��̳�������ش˷�����������ĵ��Ļ�����ơ��磺�Զ̼�����ۼ������ģ������ò��룬���ǲ����ۼӵķ�ʽ�������ݡ�
	/// ARG >> lpcszSender : ���ķ����߱�ʶ��
	///		>> lpcszTgt : ���ĵ�Ŀ�Ķ���URI
	///		>> lpcszTelType : ��������
	///		>> lpcszTelID : ���ı��
	///		>> rsTelData : ��������
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL CacheRecvTelegramData(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
	/// <summary>
	/// ���ص������Ͷ�Ӧ��MESϵͳ�����������URI
	/// ARG >> lpczTelType : ������������
	/// RET << �����������URI��
	/// </summary>
	virtual CString GetTelegramDataType(LPCTSTR lpcszType);
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
	virtual BOOL DoAcceptTelegram(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,LPCTSTR lpcszDataType,L3RECORDSET rsTelData);
	/// <summary>
	/// ���ص��Ķ�Ӧ���߼��¼�������
	/// ARG >> lpcszSender : ���ķ����߱�ʶ��
	///		>> lpcszTgt : ���ĵ�Ŀ�Ķ���URI
	///		>> lpcszTelType : ��������
	///		>> lpcszTelID : ���ı��
	///		>> rsTelData : ��������
	/// RET << �߼��¼�����
	/// </summary>
	virtual CString GetRecvTelEventType(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
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
	virtual void PrepareRecvEvent(CL3EventWrap& evt,LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,LPCTSTR lpcszDataType,L3RECORDSET rsTelData);

	/// <summary>
	/// ʵ�ʵķ��͵��ķ������̳������ش˷������е���ͨѶ
	/// ARG >> Sender : ���͵��ĵĶ����URI.
	///		>> Receiver : ���Ľ����߱�ʶ��
	///		>> TelegramType : ��������
	///		>> TelegramID : ���ı��
	///		>> rsTelegram : ��������
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual L3BOOL DoSendTelegram(L3STRING Sender,L3STRING Receiver,L3STRING TelegramType,L3STRING TelegramID,L3RECORDSET rsTelegram);

};

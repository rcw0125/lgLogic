// �߼���CTAP_Communicatorͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTAP_Communicator :
	public CL3Object
{
public:
	CTAP_Communicator(void);
	virtual ~CTAP_Communicator(void);

	DECLARE_L3CLASS(CTAP_Communicator,XGMESLogic\\TapSideMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTAP_Communicator)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

};

// �߼���CPlan_Communicatorͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CPlan_Communicator :
	public CL3Object
{
public:
	CPlan_Communicator(void);
	virtual ~CPlan_Communicator(void);

	DECLARE_L3CLASS(CPlan_Communicator,XGMESLogic\\PlanMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Communicator)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

};

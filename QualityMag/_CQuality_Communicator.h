// �߼���CQuality_Communicatorͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQuality_Communicator :
	public CL3Object
{
public:
	CQuality_Communicator(void);
	virtual ~CQuality_Communicator(void);

	DECLARE_L3CLASS(CQuality_Communicator,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQuality_Communicator)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

};

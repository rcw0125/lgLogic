// �߼���CCommunicationStatusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCommunicationStatus :
	public CL3Object
{
public:
	CCommunicationStatus(void);
	virtual ~CCommunicationStatus(void);

	DECLARE_L3CLASS(CCommunicationStatus,XGMESLogic\\BaseDataMag, WorkShop)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCommunicationStatus)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	DECLARE_L3PROP_STRING  (WorkShop)     //��λ        
	DECLARE_L3PROP_LONG    (WatchDog)     //����ֵ  
};

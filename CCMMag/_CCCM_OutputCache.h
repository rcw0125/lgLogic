// �߼���CCCM_OutputCacheͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_OutputCache :
	public CL3Object
{
public:
	CCCM_OutputCache(void);
	virtual ~CCCM_OutputCache(void);

	DECLARE_L3CLASS(CCCM_OutputCache,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_OutputCache)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

};

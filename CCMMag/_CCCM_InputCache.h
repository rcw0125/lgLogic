// �߼���CCCM_InputCacheͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_InputCache :
	public CL3Object
{
public:
	CCCM_InputCache(void);
	virtual ~CCCM_InputCache(void);

	DECLARE_L3CLASS(CCCM_InputCache,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_InputCache)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

};

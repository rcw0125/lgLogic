// �߼���CTap_OutputCacheͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTap_OutputCache :
	public CL3Object
{
public:
	CTap_OutputCache(void);
	virtual ~CTap_OutputCache(void);

	DECLARE_L3CLASS(CTap_OutputCache,XGMESLogic\\TapSideMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_OutputCache)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

};

// �߼���CScrap_Input_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialInputLog.h"

class CScrap_Input_Log :
	public MaterialInputLog
{
public:
	CScrap_Input_Log(void);
	virtual ~CScrap_Input_Log(void);

	DECLARE_L3CLASS(CScrap_Input_Log,XGMESLogic\\ScrapStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CScrap_Input_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

};

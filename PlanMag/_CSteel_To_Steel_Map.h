// �߼���CSteel_To_Steel_Mapͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialMap.h"
class CSteel_To_Steel_Map :
	public MaterialMap
{
public:
	CSteel_To_Steel_Map(void);
	virtual ~CSteel_To_Steel_Map(void);

	DECLARE_L3CLASS(CSteel_To_Steel_Map,XGMESLogic\\PlanMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CSteel_To_Steel_Map)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

};

// �߼���CScrap_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "Material.h"

class CScrap_Data :
	public Material
{
public:
	CScrap_Data(void);
	virtual ~CScrap_Data(void);

	DECLARE_L3CLASS(CScrap_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CScrap_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBulk_Code" name="Amount" type="L3DOUBLE">
	/// ��������
	/// </Property>
	/// <Property class="CScrap_Data" name="Amount" type="L3DOUBLE">
	/// �ϸ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

};

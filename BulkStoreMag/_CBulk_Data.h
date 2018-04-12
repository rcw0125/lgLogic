// �߼���CBulk_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "Material.h"

class CBulk_Data :
	public Material
{
public:
	CBulk_Data(void);
	virtual ~CBulk_Data(void);

	DECLARE_L3CLASS(CBulk_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBulk_Data" name="Bulk_Destination" type="L3STRING">
	/// ɢ״��ȥ��
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Destination)

	/// <Property class="CBulk_Data" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CBulk_Data" name="Bulk_Code" type="L3STRING">
	/// ɢ״�ϱ���
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Data" name="Amount" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

};

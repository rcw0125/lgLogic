// �߼���CEquip_Cleaning_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Cleaning_Data :
	public CL3Object
{
public:
	CEquip_Cleaning_Data(void);
	virtual ~CEquip_Cleaning_Data(void);

	DECLARE_L3CLASS(CEquip_Cleaning_Data,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Cleaning_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Cleaning_Data" name="TagName" type="L3STRING">
	/// ��ǩ��
	/// </Property>
	DECLARE_L3PROP_STRING(TagName)

	/// <Property class="CEquip_Cleaning_Data" name="TagType" type="L3LONG">
	/// ��ǩ����
	/// </Property>
	DECLARE_L3PROP_LONG(TagType)

	/// <Property class="CEquip_Cleaning_Data" name="TagValue" type="L3LONG">
	/// ��ǩֵ
	/// </Property>
	DECLARE_L3PROP_LONG(TagValue)

	/// <Property class="CEquip_Cleaning_Data" name="Catch_Time" type="L3DATETIME">
	/// �ɼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

};

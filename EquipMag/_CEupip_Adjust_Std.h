// �߼���CEupip_Adjust_Stdͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEupip_Adjust_Std :
	public CL3Object
{
public:
	CEupip_Adjust_Std(void);
	virtual ~CEupip_Adjust_Std(void);

	DECLARE_L3CLASS(CEupip_Adjust_Std,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEupip_Adjust_Std)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEupip_Adjust_Std" name="AdjustType" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(AdjustType)

	/// <Property class="CEupip_Adjust_Std" name="UnitID" type="L3STRING">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CEupip_Adjust_Std" name="AdjustObject" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(AdjustObject)

	/// <Property class="CEupip_Adjust_Std" name="Items" type="L3STRING">
	/// ��Ŀ
	/// </Property>
	DECLARE_L3PROP_STRING(Items)

	/// <Property class="CEupip_Adjust_Std" name="Standard" type="L3STRING">
	/// ��׼
	/// </Property>
	DECLARE_L3PROP_STRING(Standard)

	/// <Property class="CEupip_Adjust_Std" name="ValidFlag" type="L3LONG">
	/// ��׼
	/// </Property>
	DECLARE_L3PROP_LONG(ValidFlag)
};

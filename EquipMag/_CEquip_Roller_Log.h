// �߼���CEquip_Roller_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Roller_Log :
	public CL3Object
{
public:
	CEquip_Roller_Log(void);
	virtual ~CEquip_Roller_Log(void);

	DECLARE_L3CLASS(CEquip_Roller_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Roller_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Roller_Log" name="CCMID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Roller_Log" name="StrandNo" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Roller_Log" name="Roller_Std" type="L3STRING">
	/// �궨ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Roller_Std)

	/// <Property class="CEquip_Roller_Log" name="Roller1_Act" type="L3STRING">
	/// һ�Ź�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Roller1_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller2_Act" type="L3STRING">
	/// ���Ź�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Roller2_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller3_Act" type="L3STRING">
	/// ���Ź�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Roller3_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller4_Act" type="L3STRING">
	/// �ĺŹ�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Roller4_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller5_Act" type="L3STRING">
	/// ��Ź�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Roller5_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller6_Act" type="L3STRING">
	/// ���Ź�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Roller6_Act)

	/// <Property class="CEquip_Roller_Log" name="Roller7_Act" type="L3STRING">
	/// �ߺŹ�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Roller7_Act)

	/// <Property class="CEquip_Level_Log" name="Check_Date" type="L3DATETIME">
	/// У׼����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Level_Log" name="Create_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Level_Log" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Level_Log" name="Status" type="L3LONG">
	/// ״̬ 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};

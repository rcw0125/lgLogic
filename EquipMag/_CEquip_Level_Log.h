// �߼���CEquip_Level_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Level_Log :
	public CL3Object
{
public:
	CEquip_Level_Log(void);
	virtual ~CEquip_Level_Log(void);

	DECLARE_L3CLASS(CEquip_Level_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Level_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Level_Log" name="CCMID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Level_Log" name="StrandNo" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Level_Log" name="Zero_B_Act" type="L3STRING">
	/// ����ǰֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Zero_B_Act)

	/// <Property class="CEquip_Level_Log" name="Zero_A_Act" type="L3STRING">
	/// �����ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Zero_A_Act)

	/// <Property class="CEquip_Level_Log" name="Full_B_Act" type="L3STRING">
	/// ����ǰֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Full_B_Act)

	/// <Property class="CEquip_Level_Log" name="Full_A_Act" type="L3STRING">
	/// ������ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Full_A_Act)

	/// <Property class="CEquip_Level_Log" name="N0_Std" type="L3STRING">
	/// N0��׼ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(N0_Std)

	/// <Property class="CEquip_Level_Log" name="N0_Act" type="L3STRING">
	/// N0ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(N0_Act)

	/// <Property class="CEquip_Level_Log" name="N7_N8_Std" type="L3STRING">
	/// N7-N8��׼ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(N7_N8_Std)

	/// <Property class="CEquip_Level_Log" name="N7_N8_Act" type="L3STRING">
	/// N7-N8ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(N7_N8_Act)

	/// <Property class="CEquip_Level_Log" name="N10_Std" type="L3STRING">
	/// N10��׼ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(N10_Std)

	/// <Property class="CEquip_Level_Log" name="N10_Act" type="L3STRING">
	/// N10ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(N10_Act)

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

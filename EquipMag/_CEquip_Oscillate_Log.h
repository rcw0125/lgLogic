// �߼���CEquip_Oscillate_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Oscillate_Log :
	public CL3Object
{
public:
	CEquip_Oscillate_Log(void);
	virtual ~CEquip_Oscillate_Log(void);

	DECLARE_L3CLASS(CEquip_Oscillate_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Oscillate_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Oscillate_Log" name="CCMID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Oscillate_Log" name="StrandNo" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Oscillate_Log" name="Swing_Std" type="L3STRING">
	/// ����ƫ�ڱ�׼
	/// </Property>
	DECLARE_L3PROP_STRING(Swing_Std)

	/// <Property class="CEquip_Oscillate_Log" name="Swing_Act" type="L3STRING">
	/// ����ƫ��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Swing_Act)

	/// <Property class="CEquip_Oscillate_Log" name="Freq_Setup" type="L3STRING">
	/// �趨��Ƶ
	/// </Property>
	DECLARE_L3PROP_STRING(Freq_Setup)

	/// <Property class="CEquip_Oscillate_Log" name="Freq_Act" type="L3STRING">
	/// ��Ƶʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Freq_Act)

	/// <Property class="CEquip_Oscillate_Log" name="Ampl_Setup" type="L3STRING">
	/// �趨���
	/// </Property>
	DECLARE_L3PROP_STRING(Ampl_Setup)

	/// <Property class="CEquip_Oscillate_Log" name="Ampl_Act" type="L3STRING">
	/// ���ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Ampl_Act)

	/// <Property class="CEquip_Oscillate_Log" name="Check_Date" type="L3DATETIME">
	/// У׼����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Oscillate_Log" name="Create_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Oscillate_Log" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Oscillate_Log" name="Status" type="L3LONG">
	/// ״̬ 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};

// �߼���CEquip_Pole_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Pole_Log :
	public CL3Object
{
public:
	CEquip_Pole_Log(void);
	virtual ~CEquip_Pole_Log(void);

	DECLARE_L3CLASS(CEquip_Pole_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Pole_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Pole_Log" name="LFID" type="L3STRING">
	/// ����¯
	/// </Property>
	DECLARE_L3PROP_STRING(LFID)

	/// <Property class="CEquip_Pole_Log" name="PhaseNo" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(PhaseNo)

	/// <Property class="CEquip_Pole_Log" name="Pole_Std" type="L3STRING">
	/// �궨ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Pole_Std)

	/// <Property class="CEquip_Pole_Log" name="Pole_Act" type="L3STRING">
	/// ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Pole_Act)

	/// <Property class="CEquip_Pole_Log" name="Check_Date" type="L3DATETIME">
	/// У׼����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Pole_Log" name="Create_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Pole_Log" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Pole_Log" name="Status" type="L3LONG">
	/// ״̬ 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};

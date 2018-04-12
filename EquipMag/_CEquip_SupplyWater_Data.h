// �߼���CEquip_SupplyWater_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_SupplyWater_Data :
	public CL3Object
{
public:
	CEquip_SupplyWater_Data(void);
	virtual ~CEquip_SupplyWater_Data(void);

	DECLARE_L3CLASS(CEquip_SupplyWater_Data,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_SupplyWater_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_SupplyWater_Data" name="UnitID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CEquip_SupplyWater_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CEquip_SupplyWater_Data" name="Level_Boil" type="L3FLOAT">
	/// ����ˮλ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Level_Boil)

	/// <Property class="CEquip_SupplyWater_Data" name="P_Boil" type="L3FLOAT">
	/// ����ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Boil)

	/// <Property class="CEquip_SupplyWater_Data" name="P_Pump_SupplyWater" type="L3FLOAT">
	/// ��ˮ��ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Pump_SupplyWater)

	/// <Property class="CEquip_SupplyWater_Data" name="P_Pump_SoftWater" type="L3FLOAT">
	/// ��ˮ��ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Pump_SoftWater)

	/// <Property class="CEquip_SupplyWater_Data" name="Level_DeO2Box" type="L3FLOAT">
	/// ������ˮ��ˮλ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Level_DeO2Box)

	/// <Property class="CEquip_SupplyWater_Data" name="Level_SoftWaterBox" type="L3FLOAT">
	/// ��ˮ��ˮλ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Level_SoftWaterBox)

	/// <Property class="CEquip_SupplyWater_Data" name="P_MainPipe_Steam" type="L3FLOAT">
	/// ��������ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_MainPipe_Steam)

	/// <Property class="CEquip_SupplyWater_Data" name="Time_Start" type="L3DATETIME">
	/// ��ˮ��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Start)

	/// <Property class="CEquip_SupplyWater_Data" name="Time_Stop" type="L3DATETIME">
	/// ��ˮ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Stop)

	/// <Property class="CEquip_SupplyWater_Data" name="Time_Blow" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Blow)

	/// <Property class="CEquip_SupplyWater_Data" name="EndFla" type="L3SHORT">
	/// ������־
	/// </Property>
	DECLARE_L3PROP_SHORT(EndFlag)

	/// <Property class="CEquip_SupplyWater_Data" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CEquip_SupplyWater_Data" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CEquip_SupplyWater_Data" name="Operator" type="L3STRING">
	/// ����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

};

// �߼���CBOF_Process_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_Process_Data :
	public CL3Object
{
public:
	CBOF_Process_Data(void);
	virtual ~CBOF_Process_Data(void);

	DECLARE_L3CLASS(CBOF_Process_Data,XGMESLogic\\BOFMag, HeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_Process_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_Process_Data" name="Charging_Start_Time" type="L3DATETIME">
	/// 
	/// װ��ʱ��
	/// 
	/// </Property>
	DECLARE_L3PROP_DATETIME(Charging_Start_Time)

	/// <Property class="CBOF_Process_Data" name="Blow_Start_Time" type="DischargeTime">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Blow_Start_Time)

	/// <Property class="CBOF_Process_Data" name="Tapping_Strat_Time" type="DischargeTime">
	/// ���ֿ�ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tapping_Strat_Time)

	/// <Property class="CBOF_Process_Data" name="Tapping_End_Time" type="L3DATETIME">
	/// ���ֽ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tapping_End_Time)

	/// <Property class="CBOF_Process_Data" name="BlowO2_Time" type="L3LONG">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(BlowO2_Time)

	/// <Property class="CBOF_Process_Data" name="ReBlow_Time" type="L3LONG">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(ReBlow_Time)

	/// <Property class="CBOF_Process_Data" name="Tapping_Time" type="L3LONG">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(Tapping_Time)

	/// <Property class="CBOF_Process_Data" name="Splashing_Time" type="L3LONG">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(Splashing_Time)

	/// <Property class="CBOF_Process_Data" name="Smelt_Period" type="L3LONG">
	/// ұ������
	/// </Property>
	DECLARE_L3PROP_LONG(Smelt_Period)

	/// <Property class="CBOF_Process_Data" name="Waiting_Time" type="L3LONG">
	/// �Ƚ���ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(Waiting_Time)

	/// <Property class="CBOF_Process_Data" name="Lance_Age" type="L3LONG">
	/// ǹ��
	DECLARE_L3PROP_STRING(LanceNo)
	/// </Property>
	DECLARE_L3PROP_LONG(Lance_Age)

	/// <Property class="CBOF_Process_Data" name="Furnace_Age" type="L3LONG">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Furnace_Age)

	/// <Property class="CBOF_Process_Data" name="ReBlow_Count" type="L3SHORT">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_SHORT(ReBlow_Count)

	/// <Property class="CBOF_Process_Data" name="LaC_Temp" type="L3LONG">
	/// ��̼�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(LaC_Temp)

	/// <Property class="CBOF_Process_Data" name="Tapping_Temp" type="L3LONG">
	/// �����¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Tapping_Temp)

	/// <Property class="CBOF_Process_Data" name="Single_LaC" type="L3SHORT">
	/// һ����̼
	/// </Property>
	DECLARE_L3PROP_SHORT(Single_LaC)

	/// <Property class="CBOF_Process_Data" name="Tapping_Oxygen" type="L3FLOAT">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Tapping_Oxygen)

	/// <Property class="CBOF_Process_Data" name="LadleNo" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

	/// <Property class="CBOF_Process_Data" name="Ladle_Status" type="L3STRING">
	/// �ְ�״��
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Status)

	/// <Property class="CBOF_Process_Data" name="Taphole_Life" type="L3LONG">
	/// ���ֿ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Taphole_Life)

	/// <Property class="CBOF_Process_Data" name="Tapping_Weight" type="L3FLOAT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Tapping_Weight)

	/// <Property class="CBOF_Process_Data" name="Furnace_Line_Status" type="L3STRING">
	/// ¯�ļ�ש�����
	/// </Property>
	DECLARE_L3PROP_STRING(Furnace_Line_Status)

	/// <Property class="CBOF_Process_Data" name="Ladle_Grade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Grade)

	/// <Property class="CBOF_Process_Data" name="Ladle_Stop" type="L3DOUBLE">
	/// �ְ�ͣ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Stop)

	/// <Property class="CBOF_Process_Data" name="ScrapStatus" type="L3STRING">
	/// �ϸּ��
	/// </Property>
	DECLARE_L3PROP_STRING(ScrapStatus)
    
	//2010-01-07 sun
    /// <Property class="CBOF_Process_Data" name="Carpolite" type="L3FLOAT">
	/// ʯ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Carpolite)


	/// <Property class="CBOF_Process_Data" name="O2Total" type="L3FLOAT">
	/// ��¯��������
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2Total)

	/// <Property class="CBOF_Process_Data" name="RemainSlag" type="L3STRING">
	/// �Ƿ�����
	/// </Property>
	DECLARE_L3PROP_STRING(RemainSlag)
};

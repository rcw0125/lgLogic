// �߼���CAOD_Process_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAOD_Process_Data :
	public CL3Object
{
public:
	CAOD_Process_Data(void);
	virtual ~CAOD_Process_Data(void);

	DECLARE_L3CLASS(CAOD_Process_Data,XGMESLogic\\LFMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAOD_Process_Data" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CAOD_Process_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Process_Data" name="Arrival_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CAOD_Process_Data" name="Arrival_Temp" type="L3SHORT">
	/// ��վ�¶�
	/// </Property>
	DECLARE_L3PROP_SHORT(Arrival_Temp)

	/// <Property class="CAOD_Process_Data" name="Start_Time" type="L3DATETIME">
	/// ����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Start_Time)
    DECLARE_L3PROP_DATETIME(Blow_Start_Time)
	DECLARE_L3PROP_DATETIME(C_Start_Time)
	DECLARE_L3PROP_DATETIME(C_End_Time)
	DECLARE_L3PROP_DATETIME(Tapping_Start_Time)
	DECLARE_L3PROP_DATETIME(Tapping_End_Time)
	DECLARE_L3PROP_DATETIME(Side_Start_Time)
	DECLARE_L3PROP_DATETIME(Side_End_Time)
	DECLARE_L3PROP_LONG(C_Time)
	DECLARE_L3PROP_LONG(Tapping_Time)
	DECLARE_L3PROP_LONG(Smelt_Period)
	DECLARE_L3PROP_DOUBLE(O_Consume)
	DECLARE_L3PROP_DOUBLE(N_Consume)
	DECLARE_L3PROP_DOUBLE(Ar_Consume)
	DECLARE_L3PROP_LONG(Steel_Temp)
	DECLARE_L3PROP_LONG(Sheet_Temp)
	DECLARE_L3PROP_LONG(Return_Temp)
	DECLARE_L3PROP_LONG(Ladle_Temp)
	DECLARE_L3PROP_DOUBLE(Tapping_Weight)
	DECLARE_L3PROP_LONG(Lance_No)
	DECLARE_L3PROP_LONG(Furnace_No)
	DECLARE_L3PROP_LONG(Furnace_Age)
	DECLARE_L3PROP_STRING(LadleNo)
	DECLARE_L3PROP_STRING(Ladle_Status)
	DECLARE_L3PROP_STRING(Ladle_Grade)

};

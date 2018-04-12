// �߼���CRHL_Process_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CRHL_Process_Data :
	public CL3Object
{
public:
	CRHL_Process_Data(void);
	virtual ~CRHL_Process_Data(void);

	DECLARE_L3CLASS(CRHL_Process_Data,XGMESLogic\\RHLMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRHL_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CRHL_Process_Data" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CRHL_Process_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CRHL_Process_Data" name="Arrival_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CRHL_Process_Data" name="Arrival_Temp" type="L3SHORT">
	/// ��վ�¶�
	/// </Property>
	DECLARE_L3PROP_SHORT(Arrival_Temp)

	/// <Property class="CRHL_Process_Data" name="Start_Time" type="L3DATETIME">
	/// ����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CRHL_Process_Data" name="End_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	/// <Property class="CRHL_Process_Data" name="Process_Time" type="L3LONG">
	/// ����ʱ��(��)
	/// </Property>
	DECLARE_L3PROP_LONG(Process_Time)

	/// <Property class="CRHL_Process_Data" name="Heat_Time" type="L3LONG">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(Heat_Time)

	/// <Property class="CRHL_Process_Data" name="Heat_Count" type="L3SHORT">
	/// ���ȴ���
	/// </Property>
	DECLARE_L3PROP_SHORT(Heat_Count)



/// 
	DECLARE_L3PROP_DOUBLE(Current_Position)
	DECLARE_L3PROP_DOUBLE(E_V)
	DECLARE_L3PROP_DOUBLE(E_A)
	DECLARE_L3PROP_DOUBLE(O_Pressure)
	DECLARE_L3PROP_DOUBLE(O_Flow)
	DECLARE_L3PROP_DOUBLE(Gas_Pressure)
	DECLARE_L3PROP_DOUBLE(Gas_Flow)
	DECLARE_L3PROP_DOUBLE(Gas_F_Flow)
	DECLARE_L3PROP_DOUBLE(Spray_Pressure)
	DECLARE_L3PROP_DOUBLE(Spray_Flow)
	DECLARE_L3PROP_DOUBLE(Bodyin_Pressure)
	DECLARE_L3PROP_DOUBLE(Bodyin_Flow)
	DECLARE_L3PROP_DOUBLE(Bodyout_Pressure)
	DECLARE_L3PROP_DOUBLE(Bodyout_Flow)
	DECLARE_L3PROP_DOUBLE(Topin_Pressure)
	DECLARE_L3PROP_DOUBLE(Topin_Flow)
	DECLARE_L3PROP_DOUBLE(Wallin_Pressure)
	DECLARE_L3PROP_DOUBLE(Wallin_Flow)
	DECLARE_L3PROP_DOUBLE(Wallout_Pressure)
	DECLARE_L3PROP_DOUBLE(Wallout_Flow)
	DECLARE_L3PROP_DOUBLE(Coldin_Pressure)
	DECLARE_L3PROP_DOUBLE(Coldin_Flow)
	DECLARE_L3PROP_DOUBLE(Coldout_Pressure)
	DECLARE_L3PROP_DOUBLE(Coldout_Flow)
	DECLARE_L3PROP_DOUBLE(Angle)
	DECLARE_L3PROP_FLOAT(Steel_Weight)
	DECLARE_L3PROP_STRING(LadleNo)
	DECLARE_L3PROP_STRING(Ladle_Grade)
};

// �߼���CLF_Process_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_Process_Data :
	public CL3Object
{
public:
	CLF_Process_Data(void);
	virtual ~CLF_Process_Data(void);

	DECLARE_L3CLASS(CLF_Process_Data,XGMESLogic\\LFMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_Process_Data" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Process_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Process_Data" name="Arrival_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CLF_Process_Data" name="Arrival_Temp" type="L3SHORT">
	/// ��վ�¶�
	/// </Property>
	DECLARE_L3PROP_SHORT(Arrival_Temp)

	/// <Property class="CLF_Process_Data" name="Start_Time" type="L3DATETIME">
	/// ����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CLF_Process_Data" name="End_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	/// <Property class="CLF_Process_Data" name="Process_Time" type="L3LONG">
	/// ����ʱ��(��)
	/// </Property>
	DECLARE_L3PROP_LONG(Process_Time)

	/// <Property class="CLF_Process_Data" name="Heat_Time" type="L3LONG">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(Heat_Time)

	/// <Property class="CLF_Process_Data" name="Heat_Count" type="L3SHORT">
	/// ���ȴ���
	/// </Property>
	DECLARE_L3PROP_SHORT(Heat_Count)

	/// <Property class="CLF_Process_Data" name="Probe_Vonder" type="L3STRING">
	/// 
	/// ʹ�ö���̽ͷ����
	/// (�����ϡ�����������)
	/// </Property>
	DECLARE_L3PROP_STRING(Probe_Vonder)

	/// <Property class="CLF_Process_Data" name="FeedWire_Temp" type="L3SHORT">
	/// �ƴ�������¶�
	/// </Property>
	DECLARE_L3PROP_SHORT(FeedWire_Temp)

	/// <Property class="CLF_Process_Data" name="Departure_Temp" type="L3SHORT">
	/// ��վ�¶�
	/// </Property>
	DECLARE_L3PROP_SHORT(Departure_Temp)

	/// <Property class="CLF_Process_Data" name="SoftBlow_StartTime" type="L3DATETIME">
	/// ����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(SoftBlow_StartTime)

	/// <Property class="CLF_Process_Data" name="SoftBlow_EndTime" type="L3DATETIME">
	/// ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(SoftBlow_EndTime)

	/// <Property class="CLF_Process_Data" name="SoftBlow_Time" type="L3LONG">
	/// ��ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(SoftBlow_Time)

	/// <Property class="CLF_Process_Data" name="Lid_Life" type="L3SHORT">
	/// ¯������
	/// </Property>
	DECLARE_L3PROP_SHORT(Lid_Life)

	/// <Property class="CLF_Process_Data" name="HoldBack_Time" type="L3LONG">
	/// ��ѹ��ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(HoldBack_Time)

	/// <Property class="CLF_Process_Data" name="Steel_Weight" type="L3FLOAT">
	/// ��ˮ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Steel_Weight)

	/// <Property class="CLF_Process_Data" name="LadleNo" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

	/// <Property class="CLF_Process_Data" name="CCM_Ladle_Weight" type="L3DOUBLE">
	/// LF��վʱ�����������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CCM_Ladle_Weight)

	/// <Property class="CLF_Unit_Mag" name="PoleConsume" type="L3LONG">
	/// �缫����
	/// </Property>
	DECLARE_L3PROP_LONG(PoleConsume)

	/// <Property class="CLF_Process_Data" name="Pole_Vendor" type="L3STRING">
	/// 
	/// �缫����
	/// </Property>
	DECLARE_L3PROP_STRING(Pole_Vendor)

	/// <Property class="CLF_Process_Data" name="Flow_BlowAr_Heat" type="L3DOUBLE">
	/// ����ʱ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_Heat)

	/// <Property class="CLF_Process_Data" name="Flow_BlowAr_SoftBlow" type="L3DOUBLE">
	/// ��ʱ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_SoftBlow)
	
	//2009-03-30
	/// <Property class="CLF_Process_Data" name="Ladle_Grade" type="L3STRING">
	/// �ְ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Grade)

};

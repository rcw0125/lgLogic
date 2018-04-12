// �߼���CTundish_TFF_Hot_Fireͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_TFF_Hot_Fire :
	public CL3Object
{
public:
	CTundish_TFF_Hot_Fire(void);
	virtual ~CTundish_TFF_Hot_Fire(void);

	DECLARE_L3CLASS(CTundish_TFF_Hot_Fire,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_TFF_Hot_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTundish_TFF_Hot_Fire" name="TundishID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Cast_ID" type="L3STRING">
	/// ȥ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)
	
	/// <Property class="CTundish_TFF_Hot_Fire" name="VehicleID" type="L3STRING">
	/// �а�����
	/// </Property>
	DECLARE_L3PROP_STRING(VehicleID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Crane_TeamID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Crane_TeamID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="First_Fra_ID" type="L3STRING">
	/// 1���������
	/// </Property>
	DECLARE_L3PROP_STRING(First_Fra_ID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Second_Fra_ID" type="L3STRING">
	/// 
	/// 2���������
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(Second_Fra_ID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Third_Fra_ID" type="L3STRING">
	/// 3���������
	/// </Property>
	DECLARE_L3PROP_STRING(Third_Fra_ID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fourth_Fra_ID" type="L3STRING">
	/// 4���������
	/// </Property>
	DECLARE_L3PROP_STRING(Fourth_Fra_ID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Small_Start_Time" type="L3DATETIME">
	/// С��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Small_Start_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Small_End_Time" type="L3DATETIME">
	/// С�����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Small_End_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Mid_Start_Time" type="L3DATETIME">
	/// �л�ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Mid_Start_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Mid_End_Time" type="L3DATETIME">
	/// �л����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Mid_End_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Big_Start_Time" type="L3DATETIME">
	/// ���ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Big_Start_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Big_End_Time" type="L3DATETIME">
	/// ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Big_End_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_TFF_Hot_Fire" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fir_Gas_Flux" type="L3DOUBLE">
	/// (0��10)����ú������m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fir_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fir_Gas_Press" type="L3DOUBLE">
	/// (0��10)ú��ѹ��kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fir_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sec_Gas_Flux" type="L3DOUBLE">
	/// (10��20)����ú������m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sec_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sec_Gas_Press" type="L3DOUBLE">
	/// (10��20)ú��ѹ��kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sec_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Thi_Gas_Flux" type="L3DOUBLE">
	/// (20��60)����ú������m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Thi_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Thi_Gas_Press" type="L3DOUBLE">
	/// (20��60)ú��ѹ��kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Thi_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Thi_Wall_Temp" type="L3DOUBLE">
	/// (20��60)�м�����¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Thi_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Thi_Gap_Temp" type="L3DOUBLE">
	/// (20��60)ˮ���¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Thi_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fou_Gas_Flux" type="L3DOUBLE">
	/// (60��90)����ú������m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fou_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fou_Gas_Press" type="L3DOUBLE">
	/// (60��90)ú��ѹ��kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fou_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fou_Wall_Temp" type="L3DOUBLE">
	/// (60��90)�м�����¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fou_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fou_Gap_Temp" type="L3DOUBLE">
	/// (60��90)ˮ���¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fou_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fiv_Gas_Flux" type="L3DOUBLE">
	/// (90��120)����ú������m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fiv_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fiv_Gas_Press" type="L3DOUBLE">
	/// (90��120)ú��ѹ��kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fiv_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fiv_Wall_Temp" type="L3DOUBLE">
	/// (90��120)�м�����¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fiv_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fiv_Gap_Temp" type="L3DOUBLE">
	/// (90��120)ˮ���¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fiv_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Six_Gas_Flux" type="L3DOUBLE">
	/// (120��150)����ú������m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Six_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Six_Gas_Press" type="L3DOUBLE">
	/// (120��150)ú��ѹ��kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Six_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Six_Wall_Temp" type="L3DOUBLE">
	/// (120��150)�м�����¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Six_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Six_Gap_Temp" type="L3DOUBLE">
	/// (120��150)ˮ���¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Six_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sev_Gas_Flux" type="L3DOUBLE">
	/// (150������)����ú������m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sev_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sev_Gas_Press" type="L3DOUBLE">
	/// (150������)ú��ѹ��kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sev_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sev_Wall_Temp" type="L3DOUBLE">
	/// (150������)�м�����¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sev_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sev_Gap_Temp" type="L3DOUBLE">
	/// (150������)ˮ���¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sev_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};

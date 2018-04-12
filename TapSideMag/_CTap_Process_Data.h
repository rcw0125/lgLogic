// �߼���CTap_Process_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTap_Process_Data :
	public CL3Object
{
public:
	CTap_Process_Data(void);
	virtual ~CTap_Process_Data(void);

	DECLARE_L3CLASS(CTap_Process_Data,XGMESLogic\\TapSideMag, HeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTap_Process_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Process_Data" name="Temp_Before_BlowAr" type="L3LONG">
	/// �ǰ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Before_BlowAr)

	/// <Property class="CTap_Process_Data" name="O2_Before_BlowAr" type="L3FLOAT">
	/// �ǰ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_Before_BlowAr)

	/// <Property class="CTap_Process_Data" name="Temp_BlownAr" type="L3LONG">
	/// 벺��¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_BlownAr)

	/// <Property class="CTap_Process_Data" name="O2_BlownAr" type="L3FLOAT">
	/// 벺�������
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_BlownAr)

	/// <Property class="CTap_Process_Data" name="Blow_Mode" type="L3SHORT">
	/// ����/�״�
	/// </Property>
	DECLARE_L3PROP_SHORT(Blow_Mode)

	/// <Property class="CTap_Process_Data" name="Tune_Flag" type="L3SHORT">
	/// 
	/// �Ƿ����
	/// 0-��
	/// 1-��
	/// </Property>
	DECLARE_L3PROP_SHORT(Tune_Flag)

	/// <Property class="CTap_Process_Data" name="BlowAr_Time" type="L3LONG">
	/// ���ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(BlowAr_Time)

	/// <Property class="CTap_Process_Data" name="Start_Time" type="L3DATETIME">
	/// ����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CTap_Process_Data" name="End_Time" type="L3DATETIME">
	/// �������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	/// <Property class="CTap_Process_Data" name="Cold_Mat_Cunsume" type="L3FLOAT">
	/// ���¼�����[kg]
	/// </Property>
	DECLARE_L3PROP_FLOAT(Cold_Mat_Cunsume)

};

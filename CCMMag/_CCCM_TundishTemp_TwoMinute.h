// �߼���CCCM_TundishTemp_TwoMinuteͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_TundishTemp_TwoMinute :
	public CL3Object
{
public:
	CCCM_TundishTemp_TwoMinute(void);
	virtual ~CCCM_TundishTemp_TwoMinute(void);

	DECLARE_L3CLASS(CCCM_TundishTemp_TwoMinute,XGMESLogic\\CCMMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_TundishTemp_TwoMinute)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="CastingNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_TundishTemp_TwoMinute" name="Temp" type="L3FLOAT">
	/// �¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(Temp)


	/// <Property class="CCCM_TundishTemp_TwoMinute" name="Measure_Time" type="L3DATETIME">
	/// �ɼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Measure_Time)

	

};

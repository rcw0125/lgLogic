// �߼���CPlan_Tapping_Actͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CPlan_Tapping_Act :
	public CL3Object
{
public:
	CPlan_Tapping_Act(void);
	virtual ~CPlan_Tapping_Act(void);

	DECLARE_L3CLASS(CPlan_Tapping_Act,XGMESLogic\\PlanMag, PreHeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Tapping_Act)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_Tapping_Act" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CPlan_Tapping_Act" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CPlan_Tapping_Act" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CPlan_Tapping_Act" name="LF_TreatNo" type="L3STRING">
	/// LF�����
	/// </Property>
	DECLARE_L3PROP_STRING(LF_TreatNo)

	/// <Property class="CPlan_Tapping_Act" name="RH_TreatNo" type="L3STRING">
	/// RH�����
	/// </Property>
	DECLARE_L3PROP_STRING(RH_TreatNo)

	/// <Property class="CPlan_Tapping_Act" name="Caster_TreatNo" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(Caster_TreatNo)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_IronPrepared" type="L3DATETIME">
	/// ��ԭ��װ��ʱ�̣���ˮ׼���գ�
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_IronPrepared)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_BOFStart" type="L3DATETIME">
	/// ����ʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_BOFStart)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_BOFTapped" type="L3DATETIME">
	/// ������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_BOFTapped)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_TappedSideEnd" type="L3DATETIME">
	/// ¯�������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_TappedSideEnd)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_LFArrival" type="L3DATETIME">
	/// LF��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFArrival)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_LFStart" type="L3DATETIME">
	/// LFʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFStart)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_LFEnd" type="L3DATETIME">
	/// LF��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFEnd)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_LFLeave" type="L3DATETIME">
	/// LF��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFLeave)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_RHArrival" type="L3DATETIME">
	/// RH��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHArrival)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_RHStart" type="L3DATETIME">
	/// RHʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHStart)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_RHEnd" type="L3DATETIME">
	/// RH��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHEnd)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_RHLeave" type="L3DATETIME">
	/// RH��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHLeave)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_CasterArrival" type="L3DATETIME">
	/// ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CasterArrival)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_CastingStart" type="L3DATETIME">
	/// ע��ʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CastingStart)

	/// <Property class="CPlan_Tapping_Act" name="Act_Time_CastingEnd" type="L3DATETIME">
	/// ע����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CastingEnd)

	/// <Property class="CPlan_Tapping_Act" name="CreateDate" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateDate)


	/// <Property class="CPlan_Tapping_Act" name="BOFID" type="L3STRING">
	/// ת¯¯����
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CPlan_Tapping_Act" name="LFID" type="L3STRING">
	/// LF¯����
	/// </Property>
	DECLARE_L3PROP_STRING(LFID)

	/// <Property class="CPlan_Tapping_Act" name="RHID" type="L3STRING">
	/// RH¯����
	/// </Property>
	DECLARE_L3PROP_STRING(RHID)


};

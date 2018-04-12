// �߼���CLadle_Planͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Plan :
	public CL3Object
{
public:
	CLadle_Plan(void);
	virtual ~CLadle_Plan(void);

	DECLARE_L3CLASS(CLadle_Plan,XGMESLogic\\LadleMag, PlanID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Plan)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Plan" name="Heat_ID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PlanID)

	/// <Property class="CLadle_Plan" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)					

	/// <Property class="CLadle_Plan" name="Input_Date" type="L3DATETIME">
	/// �����ƻ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateDate)

	/// <Property class="CLadle_Plan" name="Heat_ID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLadle_Plan" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CLadle_Plan" name="UnitID" type="L3STRING">
	/// ��ǰ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)							   

	/// <Property class="CLadle_Plan" name="LadleID" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Plan" name="Ladle_Age" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Age)

	/// <Property class="CLadle_Plan" name="New_BOF_Flag" type="L3LONG">
	/// 80tת¯��־
	/// </Property>
	DECLARE_L3PROP_LONG(New_BOF_Flag)

	/// <Property class="CLadle_Plan" name="Status" type="L3STRING">
	/// �ƻ�״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CLadle_Plan" name="Act_Time_IronPrepared" type="L3DATETIME">
	/// ��ԭ��װ��ʱ�̣���ˮ׼���գ�
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_IronPrepared)

	/// <Property class="CLadle_Plan" name="Act_Time_BOFStart" type="L3DATETIME">
	/// ����ʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_BOFStart)

	/// <Property class="CLadle_Plan" name="Act_Time_BOFTapped" type="L3DATETIME">
	/// ������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_BOFTapped)

	/// <Property class="CLadle_Plan" name="Act_Time_TappedSideEnd" type="L3DATETIME">
	/// ¯�������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_TappedSideEnd)

	/// <Property class="CLadle_Plan" name="Act_Time_LFArrival" type="L3DATETIME">
	/// LF��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFArrival)

	/// <Property class="CLadle_Plan" name="Act_Time_LFStart" type="L3DATETIME">
	/// LFʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFStart)

	/// <Property class="CLadle_Plan" name="Act_Time_LFEnd" type="L3DATETIME">
	/// LF��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFEnd)

	/// <Property class="CLadle_Plan" name="Act_Time_LFLeave" type="L3DATETIME">
	/// LF��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_LFLeave)

	/// <Property class="CLadle_Plan" name="Act_Time_RHArrival" type="L3DATETIME">
	/// RH��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHArrival)

	/// <Property class="CLadle_Plan" name="Act_Time_RHStart" type="L3DATETIME">
	/// RHʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHStart)

	/// <Property class="CLadle_Plan" name="Act_Time_RHEnd" type="L3DATETIME">
	/// RH��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHEnd)

	/// <Property class="CLadle_Plan" name="Act_Time_RHLeave" type="L3DATETIME">
	/// RH��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_RHLeave)

	/// <Property class="CLadle_Plan" name="Act_Time_CasterArrival" type="L3DATETIME">
	/// ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CasterArrival)

	/// <Property class="CLadle_Plan" name="Act_Time_CastingStart" type="L3DATETIME">
	/// ע��ʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CastingStart)

	/// <Property class="CLadle_Plan" name="Act_Time_CastingEnd" type="L3DATETIME">
	/// ע����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Act_Time_CastingEnd)


	/// <Property class="CLadle_Plan" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Plan" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Plan" name="Operator" type="L3STRING">
	/// ����ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Plan" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

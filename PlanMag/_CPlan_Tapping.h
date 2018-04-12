// �߼���CPlan_Tappingͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProducePlan.h"

class CPlan_Tapping :
	public ProducePlan
{
public:
	CPlan_Tapping(void);
	virtual ~CPlan_Tapping(void);

	DECLARE_L3CLASS(CPlan_Tapping,XGMESLogic\\PlanMag, PlanID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Tapping)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_Tapping" name="Pre_LotNo" type="L3STRING">
	/// Ԥ�����κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_LotNo)

	/// <Property class="CPlan_Tapping" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CPlan_Tapping" name="Pre_SteelGradeIndex" type="L3STRING">
	/// Ԥ�����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CPlan_Tapping" name="Pre_SteelGrade" type="L3STRING">
	/// Ԥ������
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGrade)

	/// <Property class="CPlan_Tapping" name="Aim_Tapped_Weight" type="L3DOUBLE">
	/// Ŀ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Aim_Tapped_Weight)

	/// <Property class="CPlan_Tapping" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CPlan_Tapping" name="BOFID" type="L3STRING">
	/// ת¯¯����
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CPlan_Tapping" name="LFID" type="L3STRING">
	/// LF¯����
	/// </Property>
	DECLARE_L3PROP_STRING(LFID)

	/// <Property class="CPlan_Tapping" name="RHID" type="L3STRING">
	/// RH¯����
	/// </Property>
	DECLARE_L3PROP_STRING(RHID)


	DECLARE_L3PROP_STRING(DEPID)
	DECLARE_L3PROP_STRING(RHLID)
	DECLARE_L3PROP_STRING(AODID)
	DECLARE_L3PROP_STRING(DEP_Status)
	DECLARE_L3PROP_STRING(RHL_Status)
	DECLARE_L3PROP_STRING(AOD_Status)

	/// <Property class="CPlan_Tapping" name="BOF_Status" type="L3STRING">
	/// ת¯״̬
	/// </Property>
	DECLARE_L3PROP_STRING(BOF_Status)

	/// <Property class="CPlan_Tapping" name="LF_Status" type="L3STRING">
	/// LF¯״̬
	/// </Property>
	DECLARE_L3PROP_STRING(LF_Status)

	/// <Property class="CPlan_Tapping" name="RH_Status" type="L3STRING">
	/// RH¯״̬
	/// </Property>
	DECLARE_L3PROP_STRING(RH_Status)

	/// <Property class="CPlan_Tapping" name="Caster_Status" type="L3STRING">
	/// ����״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Caster_Status)

	/// <Property class="CPlan_Tapping" name="Side_Status" type="L3STRING">
	/// ¯��״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Side_Status)


	/// <Property class="CPlan_Tapping" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CPlan_Tapping" name="Casting_No" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Casting_No)

	/// <Property class="CPlan_Tapping" name="Casting_Heat_Cnt" type="L3LONG">
	/// ������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Casting_Heat_Cnt)

	/// <Property class="CPlan_Tapping" name="Aim_Time_IronPrepared" type="L3DATETIME">
	/// ��ԭ��װ��ʱ�̣���ˮ׼���գ�
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_IronPrepared)

	/// <Property class="CPlan_Tapping" name="Aim_Time_BOFStart" type="L3DATETIME">
	/// ����ʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_BOFStart)

	/// <Property class="CPlan_Tapping" name="Aim_Time_BOFTapped" type="L3DATETIME">
	/// ������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_BOFTapped)

	/// <Property class="CPlan_Tapping" name="Aim_Time_TappedSideEnd" type="L3DATETIME">
	/// ¯�������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_TappedSideEnd)

	/// <Property class="CPlan_Tapping" name="Aim_Time_LFArrival" type="L3DATETIME">
	/// LF��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_LFArrival)

	/// <Property class="CPlan_Tapping" name="Aim_Time_LFStart" type="L3DATETIME">
	/// LFʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_LFStart)

	/// <Property class="CPlan_Tapping" name="Aim_Time_LFEnd" type="L3DATETIME">
	/// LF��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_LFEnd)

	/// <Property class="CPlan_Tapping" name="Aim_Time_LFLeave" type="L3DATETIME">
	/// LF��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_LFLeave)

	/// <Property class="CPlan_Tapping" name="Aim_Time_RHArrival" type="L3DATETIME">
	/// RH��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_RHArrival)

	/// <Property class="CPlan_Tapping" name="Aim_Time_RHStart" type="L3DATETIME">
	/// RHʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_RHStart)

	/// <Property class="CPlan_Tapping" name="Aim_Time_RHEnd" type="L3DATETIME">
	/// RH��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_RHEnd)

	/// <Property class="CPlan_Tapping" name="Aim_Time_RHLeave" type="L3DATETIME">
	/// RH��վʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_RHLeave)

	/// <Property class="CPlan_Tapping" name="Aim_Time_CasterArrival" type="L3DATETIME">
	/// ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_CasterArrival)

	/// <Property class="CPlan_Tapping" name="Aim_Time_CastingStart" type="L3DATETIME">
	/// ע��ʼ
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_CastingStart)

	/// <Property class="CPlan_Tapping" name="Aim_Time_CastingEnd" type="L3DATETIME">
	/// ע����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_CastingEnd)

	/// <Property class="CPlan_Tapping" name="Fir_Heat_Flag" type="L3LONG">
	/// ���ε�һ¯��־
	/// </Property>
	DECLARE_L3PROP_LONG(Fir_Heat_Flag)


	/// <Property class="CPlan_Tapping" name="Div_HeatID" type="L3STRING">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_STRING(Div_HeatID)

	/// <Property class="CPlan_Tapping" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CPlan_Tapping" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CPlan_Tapping" name="SteelGradeIndex" type="L3STRING">
	/// ʵ�����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CPlan_Tapping" name="SteelGrade" type="L3STRING">
	/// ʵ�ʸ���
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CPlan_Tapping" name="Plan_Ord_ID" type="L3STRING">
	/// �ƻ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Plan_Ord_ID)

	/// <Property class="CPlan_Tapping" name="Hot_Send_Flag" type="L3LONG">
	/// ���ͱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Send_Flag)


	/// <Property class="CPlan_Tapping" name="Steel_Return_Flag" type="L3LONG">
	/// ��¯��־
	/// </Property>
	DECLARE_L3PROP_LONG(Steel_Return_Flag)


	/// <Property class="CPlan_Tapping" name="Steel_Back_Flag" type="L3LONG">
	/// ���ͱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Steel_Back_Flag)

	/// <Property class="CPlan_Tapping" name="Treat_Seq" type="L3STRING">
	/// ��������˳��ţ�08000001
	/// </Property>
	DECLARE_L3PROP_STRING(Treat_Seq)

	/// <Property class="CPlan_Tapping" name="Destitation" type="L3STRING">
	/// ȥ��
	/// </Property>
	DECLARE_L3PROP_STRING(Destitation)

	/// <Property class="CPlan_Tapping" name="New_BOF_Flag" type="L3SHORT">
	/// 80tת¯��־
	/// </Property>
	DECLARE_L3PROP_SHORT(New_BOF_Flag)

	/// <Property class="CPlan_Tapping" name="Refine_Type" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Refine_Type)

	/// <Property class="CPlan_Tapping" name="Length" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CPlan_Tapping" name="Width" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CPlan_Tapping" name="Thickness" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

};

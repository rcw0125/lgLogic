// �߼���CPlan_Castingͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProducePlan.h"

class CPlan_Casting :
	public ProducePlan
{
public:
	CPlan_Casting(void);
	virtual ~CPlan_Casting(void);

	DECLARE_L3CLASS(CPlan_Casting,XGMESLogic\\PlanMag, PlanID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Casting)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_Casting" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CPlan_Casting" name="Length" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CPlan_Casting" name="Width" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CPlan_Casting" name="Thickness" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CPlan_Casting" name="Pre_SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CPlan_Casting" name="Pre_SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGrade)

	/// <Property class="CPlan_Casting" name="Refine_Type" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Refine_Type)

	/// <Property class="CPlan_Casting" name="Pre_LotNo" type="L3STRING">
	/// Ԥ�����κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_LotNo)

	/// <Property class="CPlan_Casting" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CPlan_Casting" name="Aim_Tapped_Weight" type="L3DOUBLE">
	/// Ŀ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Aim_Tapped_Weight)

	/// <Property class="CPlan_Casting" name="Proc_Seq" type="L3LONG">
	/// �ƻ�����˳��
	/// </Property>
	DECLARE_L3PROP_LONG(Proc_Seq)

	/// <Property class="CPlan_Casting" name="Plan_Ord_ID" type="L3STRING">
	/// �ƻ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Plan_Ord_ID)

	/// <Property class="CPlan_Casting" name="Bloom_Count" type="L3LONG">
	/// �ƻ���������
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CPlan_Casting" name="Aim_Time_CastingStart" type="L3DATETIME">
	/// �ƻ�����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_CastingStart)

	/// <Property class="CPlan_Casting" name="New_BOF_Flag" type="L3SHORT">
	/// 80tת¯��־
	/// </Property>
	DECLARE_L3PROP_SHORT(New_BOF_Flag)


	/// <Property class="CPlan_Casting" name="BOFID" type="L3STRING">
	/// ת¯¯����
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CPlan_Casting" name="LFID" type="L3STRING">
	/// LF¯����
	/// </Property>
	DECLARE_L3PROP_STRING(LFID)

	/// <Property class="CPlan_Casting" name="RHID" type="L3STRING">
	/// RH¯����
	/// </Property>
	DECLARE_L3PROP_STRING(RHID)

	/// <Property class="CPlan_Casting" name="ActWeight" type="L3DOUBLE">
	/// ʵ��Ͷ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ActWeight)

};

// �߼���CSteel_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "Material.h"

class CSteel_Data :
	public Material
{
public:
	CSteel_Data(void);
	virtual ~CSteel_Data(void);

	DECLARE_L3CLASS(CSteel_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CSteel_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

public:

	enum _YesOrNoEnum
	{
		No = 0,	// ��
		Yes = 1,// ��
	};
	/// <Property class="CSteel_Data" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CSteel_Data" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CSteel_Data" name="Pre_SteelGradeIndex" type="L3STRING">
	/// Ԥ�����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CSteel_Data" name="Final_SteelGradeIndex" type="L3STRING">
	/// �������ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Final_SteelGradeIndex)

	/// <Property class="CSteel_Data" name="Decide_SteelGradeIndex" type="L3STRING">
	/// �������ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_SteelGradeIndex)

	/// <Property class="CSteel_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CSteel_Data" name="LadleID" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CSteel_Data" name="Weight" type="L3FLOAT">
	/// ��ˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CSteel_Data" name="Decide_Code" type="L3STRING">
	/// ���ô���
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CSteel_Data" name="HeatGrade" type="L3STRING">
	/// Ʒ�ʵȼ�
	/// </Property>
	DECLARE_L3PROP_STRING(HeatGrade)

	/// <Property class="CSteel_Data" name="Classify" type="L3STRING">
	/// �쳣�������
	/// </Property>
	DECLARE_L3PROP_STRING(Classify)

	/// <Property class="CSteel_Data" name="Exceptional_Code" type="L3STRING">
	/// �쳣����
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CSteel_Data" name="DecideSteelGradeIndexFlag" type="L3STRING">
	/// �������ּǺŲ�����־
	/// </Property>
	DECLARE_L3PROP_STRING(DecideSteelGradeIndexFlag)

	/// <Property class="CSteel_Data" name="DecideFinalFlag" type="L3STRING">
	/// ��Ҫ���б�־
	/// </Property>
	DECLARE_L3PROP_STRING(DecideFinalFlag)

	/// <Property class="CSteel_Data" name="BOFFinishedFlag" type="L3STRING">
	/// ת¯ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_STRING(BOFFinishedFlag)

	/// <Property class="CSteel_Data" name="LFFinishedFlag" type="L3STRING">
	/// LFʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_STRING(LFFinishedFlag)

	/// <Property class="CSteel_Data" name="RHFinishedFlag" type="L3STRING">
	/// RHʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_STRING(RHFinishedFlag)

	/// <Property class="CSteel_Data" name="CCMFinishedFlag" type="L3STRING">
	/// CCMʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_STRING(CCMFinishedFlag)

	/// <Property class="CSteel_Data" name="FinalChemiclaFlag" type="L3STRING">
	/// ¯��ȷ����־
	/// </Property>
	DECLARE_L3PROP_STRING(FinalChemiclaFlag)

	/// <Property class="CSteel_Data" name="DivFinalChemiclaFlag" type="L3STRING">
	/// ¯�ηָ����ճɷ����ޱ�־
	/// </Property>
	DECLARE_L3PROP_STRING(DivFinalChemiclaFlag)





};

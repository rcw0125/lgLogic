// �߼���CCCM_Base_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Base_Data :
	public CL3Object
{
public:
	CCCM_Base_Data(void);
	virtual ~CCCM_Base_Data(void);

	DECLARE_L3CLASS(CCCM_Base_Data,XGMESLogic\\CCMMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Base_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	///2009-02-13ɾ�����κš�Ԥ�����κ�,������ع�����ȡ���ȡ�����

	/// <Property class="CCCM_Base_Data" name="TreatNo" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Base_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Base_Data" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)


	/// <Property class="CCCM_Base_Data" name="HeatConfirm" type="L3SHORT">
	/// 
	/// ¯��ȷ�ϱ�־
	/// (0--δ¯��ȷ��
	///  1--����ȷ��
	///  2--����ȷ��)
	/// </Property>
	DECLARE_L3PROP_SHORT(HeatConfirm)

	/// <Property class="CCCM_Base_Data" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)


	/// <Property class="CCCM_Base_Data" name="Production_Date" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProductionDate)

	/// <Property class="CCCM_Base_Data" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)


	/// <Property class="CCCM_Base_Data" name="LadleNo" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)


	/// <Property class="CCCM_Base_Data" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CCCM_Base_Data" name="Pre_SteelGradeIndex" type="L3STRING">
	/// Ԥ�����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CCCM_Base_Data" name="Plan_SteelGrade" type="L3STRING">
	/// �ƻ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Plan_SteelGrade)

	/// <Property class="CCCM_Base_Data" name="HeadFurnace" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CCCM_Base_Data" name="Ladle_Operator" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Operator)

	/// <Property class="CCCM_Base_Data" name="Control_Operator" type="L3STRING">
	/// ���ع�
	/// </Property>
	DECLARE_L3PROP_STRING(Control_Operator)


	/// <Property class="CCCM_Base_Data" name="Cut_Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_Operator)

	/// <Property class="CCCM_Base_Data" name="Tundish_1ST_Officer" type="L3STRING">
	/// 1ST�а���
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_1ST_Officer)

	/// <Property class="CCCM_Base_Data" name="Tundish_2ST_Officer" type="L3STRING">
	/// 2ST�а���
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_2ST_Officer)

	/// <Property class="CCCM_Base_Data" name="Tundish_3ST_Officer" type="L3STRING">
	/// 3ST�а���
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_3ST_Officer)

	/// <Property class="CCCM_Base_Data" name="Tundish_4ST_Officer" type="L3STRING">
	/// 4ST�а���
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_4ST_Officer)

	/// <Property class="CCCM_Base_Data" name="Thickness" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CCCM_Base_Data" name="Width" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CCCM_Base_Data" name="Length" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Length)


	/// <Property class="CCCM_Base_Data" name="Locked" type="L3SHORT">
	/// 
	/// ����־(0:δ����
	///                  1:����[���������ݱ��])
	/// </Property>
	DECLARE_L3PROP_SHORT(Locked)


	/// <Property class="CCCM_Base_Data" name="Shift" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CCCM_Base_Data" name="Team" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)


	/// <Property class="CSteel_Data" name="NC_Confirm_Flag" type="L3LONG">
	/// NCȷ�ϱ�־
	/// </Property>
	///2009-02-22
	DECLARE_L3PROP_LONG(NC_Confirm_Flag)


};

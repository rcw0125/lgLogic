// �߼���CBOF_Base_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_Base_Data :
	public CL3Object
{
public:
	CBOF_Base_Data(void);
	virtual ~CBOF_Base_Data(void);

	DECLARE_L3CLASS(CBOF_Base_Data,XGMESLogic\\BOFMag, HeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Base_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_Base_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_Base_Data" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CBOF_Base_Data" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CBOF_Base_Data" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CBOF_Base_Data" name="Shift" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CBOF_Base_Data" name="Team" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CBOF_Base_Data" name="HeadFurnace" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CBOF_Base_Data" name="Assistant" type="L3STRING">
	/// һ����
	/// </Property>
	DECLARE_L3PROP_STRING(Assistant)

	/// <Property class="CBOF_Base_Data" name="SecondHand" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(SecondHand)

	/// <Property class="CBOF_Base_Data" name="ProductionDate" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProductionDate)

	/// <Property class="CBOF_Base_Data" name="StatisticsDate" type="L3DATETIME">
	/// ͳ������
	/// </Property>
	DECLARE_L3PROP_DATETIME(StatisticsDate)

	/// <Property class="CBOF_Base_Data" name="Locked" type="L3SHORT">
	/// 
	/// ����־(0:δ����
	///                  1:����[���������ݱ��])
	/// </Property>
	DECLARE_L3PROP_SHORT(Locked)
	
	/// <Property class="CBOF_Base_Data" name="NC_Confirm_Flag" type="L3LONG">
	/// NCȷ�ϱ�־
	/// </Property>
	///2009-02-25
	DECLARE_L3PROP_LONG(NC_Confirm_Flag)

};

// �߼���CLF_Base_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_Base_Data :
	public CL3Object
{
public:
	CLF_Base_Data(void);
	virtual ~CLF_Base_Data(void);

	DECLARE_L3CLASS(CLF_Base_Data,XGMESLogic\\LFMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Base_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_Base_Data" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Base_Data" name="HeatID" type="L3STRING">
	///¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)


	/// <Property class="CLF_Base_Data" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CLF_Base_Data" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CLF_Base_Data" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CLF_Base_Data" name="LadleNo" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

	/// <Property class="CLF_Base_Data" name="HeadFurnace" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CLF_Base_Data" name="Assistant" type="L3STRING">
	/// һ����
	/// </Property>
	DECLARE_L3PROP_STRING(Assistant)

	/// <Property class="CLF_Base_Data" name="SecondHand" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(SecondHand)

	/// <Property class="CLF_Base_Data" name="ProductionDate" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProductionDate)

	/// <Property class="CLF_Base_Data" name="Locked" type="L3SHORT">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_SHORT(Locked)

	/// <Property class="CLF_Base_Data" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CLF_Base_Data" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CLF_Base_Data" name="NC_Confirm_Flag" type="L3LONG">
	/// NCȷ�ϱ�־
	/// </Property>
	///2009-02-25
	DECLARE_L3PROP_LONG(NC_Confirm_Flag)



};

// �߼���CQA_Heat_Prod_Exceptͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Heat_Prod_Except :
	public CL3Object
{
public:
	CQA_Heat_Prod_Except(void);
	virtual ~CQA_Heat_Prod_Except(void);

	DECLARE_L3CLASS(CQA_Heat_Prod_Except,XGMESLogic\\QualityMag, ID_Object)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Prod_Except)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Prod_Except" name="ID_Object" type="L3STRING">
	/// ��ݱ�ʶ
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)

	/// <Property class="CQA_Heat_Prod_Except" name="HeatID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Heat_Prod_Except" name="Process_Count" type="L3LONG">
	/// �������
	/// </Property>
	DECLARE_L3PROP_LONG(Process_Count)

	/// <Property class="CQA_Heat_Prod_Except" name="UnitTypeID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(UnitTypeID)

	/// <Property class="CQA_Heat_Prod_Except" name="UnitID" type="L3STRING">
	/// ��λID
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CQA_Heat_Prod_Except" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CQA_Heat_Prod_Except" name="Pre_SteelGradeIndex" type="L3STRING">
	/// Ԥ�����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CQA_Heat_Prod_Except" name="SteelGradeIndex" type="L3STRING">
	/// ��ҵ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Heat_Prod_Except" name="Exceptional_Code" type="L3STRING">
	/// �쳣����
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CQA_Heat_Prod_Except" name="Decide_Code" type="L3STRING">
	/// ���ô���
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CQA_Heat_Prod_Except" name="Classify" type="L3LONG">
	/// ���ȼ�
	/// </Property>
	DECLARE_L3PROP_LONG(Classify)

	/// <Property class="CQA_Heat_Prod_Except" name="Exceptional_Time" type="L3DATETIME">
	/// �쳣����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Exceptional_Time)

};

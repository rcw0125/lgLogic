// �߼���CQA_HeatGradeDataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_HeatGradeData :
	public CL3Object
{
public:
	CQA_HeatGradeData(void);
	virtual ~CQA_HeatGradeData(void);

	DECLARE_L3CLASS(CQA_HeatGradeData,XGMESLogic\\QualityMag, ID_Object)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatGradeData)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_HeatGradeData" name="ID_Object" type="L3STRING">
	/// 
	/// ��ݱ�ʶ��
	/// ������+����λ�������+����
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)

	/// <Property class="CQA_HeatGradeData" name="HeatID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_HeatGradeData" name="ProcessCount" type="L3SHORT">
	/// ����λ�������
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessCount)

	/// <Property class="CQA_HeatGradeData" name="UnitTypeID" type="L3SHORT">
	/// 
	/// ����:
	/// 9�����վ���
	/// </Property>
	DECLARE_L3PROP_LONG(UnitTypeID)

	/// <Property class="CQA_HeatGradeData" name="UnitID" type="L3SHORT">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_LONG(UnitID)

	/// <Property class="CQA_HeatGradeData" name="Exceptional_Code" type="L3STRING">
	/// �쳣����
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CQA_HeatGradeData" name="Decide_Code" type="L3STRING">
	/// ���ô���
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CQA_HeatGradeData" name="HeatGrade" type="L3STRING">
	/// ¯�εȼ�
	/// </Property>
	DECLARE_L3PROP_STRING(HeatGrade)

	/// <Property class="CQA_HeatGradeData" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CQA_HeatGradeData" name="Pre_SteelGradeIndex" type="L3STRING">
	/// Ԥ�����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CQA_HeatGradeData" name="SteelGradeIndex" type="L3STRING">
	/// ��ҵ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_HeatGradeData" name="DataLogMode" type="L3SHORT">
	/// 
	/// ���ݲ�����ʽ:
	/// 0���Զ����㣻1���ֹ�¼��
	/// </Property>
	DECLARE_L3PROP_LONG(DataLogMode)

};

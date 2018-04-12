// �߼���CQA_Heat_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Heat_Data :
	public CL3Object
{
public:
	CQA_Heat_Data(void);
	virtual ~CQA_Heat_Data(void);

	DECLARE_L3CLASS(CQA_Heat_Data,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Data" name="HeatID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Heat_Data" name="Proc_Cnt" type="L3LONG">
	/// �������
	/// </Property>
	DECLARE_L3PROP_LONG(Proc_Cnt)

	/// <Property class="CQA_Heat_Data" name="Unit_Type" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Unit_Type)

	/// <Property class="CQA_Heat_Data" name="UnitID" type="L3STRING">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CQA_Heat_Data" name="Except_Code" type="L3STRING">
	/// ���롢
	/// </Property>
	DECLARE_L3PROP_STRING(Except_Code)

	/// <Property class="CQA_Heat_Data" name="Decide_Code" type="L3STRING">
	/// ���ô���
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CQA_Heat_Data" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CQA_Heat_Data" name="Heat_Lev" type="L3STRING">
	/// ¯�εȼ�
	/// </Property>
	DECLARE_L3PROP_STRING(Heat_Lev)

	/// <Property class="CQA_Heat_Data" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Heat_Data" name="Act_SteelGradeIndex" type="L3STRING">
	/// ʵ�����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Act_SteelGradeIndex)

	/// <Property class="CQA_Heat_Data" name="Data_Mod" type="L3LONG">
	/// ���ݲ���ģʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Data_Mod)

};

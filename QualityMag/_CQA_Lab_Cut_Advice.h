// �߼���CQA_Lab_Cut_Adviceͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Lab_Cut_Advice :
	public CL3Object
{
public:
	CQA_Lab_Cut_Advice(void);
	virtual ~CQA_Lab_Cut_Advice(void);

	DECLARE_L3CLASS(CQA_Lab_Cut_Advice,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_Cut_Advice)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Lab_Cut_Advice" name="HeatID" type="L3STRING">
	/// Sample_Code
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Lab_Cut_Advice" name="SteelGradeIndex" type="L3STRING">
	///���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)


	/// <Property class="CQA_Lab_Cut_Advice" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_Lab_Cut_Advice" name="Protocol" type="L3STRING">
	/// Э��
	/// </Property>
	DECLARE_L3PROP_STRING(Protocol)


	/// <Property class="CQA_Lab_Cut_Advice" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CQA_Lab_Cut_Advice" name="Cut_Count" type="L3LONG">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Count)

	/// <Property class="CQA_Lab_Cut_Advice" name="Cut_Position" type="L3STRING">
	/// ����λ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_Position)

	/// <Property class="CQA_Lab_Cut_Advice" name="Cut_Dimen" type="L3STRING">
	/// �����ߴ�
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_Dimen)

	/// <Property class="CQA_Lab_Cut_Advice" name="Cut_Mark" type="L3STRING">
	/// ������ʶ
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_Mark)

	/// <Property class="CQA_Lab_Cut_Advice" name="Log_Time" type="L3DATETIME">
	/// ֪ͨʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

};

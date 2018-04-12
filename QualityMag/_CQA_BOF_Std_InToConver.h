// �߼���CQA_BOF_Std_InToConverͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_InToConver :
	public CL3Object
{
public:
	CQA_BOF_Std_InToConver(void);
	virtual ~CQA_BOF_Std_InToConver(void);

	DECLARE_L3CLASS(CQA_BOF_Std_InToConver,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_InToConver)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_InToConver" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Temp_Min" type="L3LONG">
	/// ��ˮ�¶���С
	/// </Property>
	DECLARE_L3PROP_LONG(Iron_Temp_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Temp_Max" type="L3LONG">
	/// ��ˮ�¶����
	/// </Property>
	DECLARE_L3PROP_LONG(Iron_Temp_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Weight_Max" type="L3DOUBLE">
	/// ��ˮװ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Weight_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Weight_Min" type="L3DOUBLE">
	/// ��ˮװ������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Weight_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_S_Max" type="L3DOUBLE">
	/// ��ˮ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_S_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_S_Min" type="L3DOUBLE">
	/// ��ˮ������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_S_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_P_Max" type="L3DOUBLE">
	/// ��ˮP�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_P_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_P_Min" type="L3DOUBLE">
	/// ��ˮP������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_P_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Si_Max" type="L3DOUBLE">
	/// ��ˮSI�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Si_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Si_Min" type="L3DOUBLE">
	/// ��ˮSI������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Si_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Ti_Min" type="L3DOUBLE">
	/// ��ˮTi������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Ti_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Iron_Ti_Max" type="L3DOUBLE">
	/// ��ˮTi�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Iron_Ti_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Scrap_Type" type="L3STRING">
	/// �ϸ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Scrap_Type)

	/// <Property class="CQA_BOF_Std_InToConver" name="Scrap_Weight_Max" type="L3DOUBLE">
	/// �ϸ�װ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Scrap_Weight_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="Scrap_Weight_Min" type="L3DOUBLE">
	/// �ϸ�װ����С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Scrap_Weight_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="PigIron_Weight_Max" type="L3DOUBLE">
	/// ����װ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(PigIron_Weight_Max)

	/// <Property class="CQA_BOF_Std_InToConver" name="PigIron_Weight_Min" type="L3DOUBLE">
	/// ����װ����С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(PigIron_Weight_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Total_Weight_Min" type="L3DOUBLE">
	/// ��װ������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Total_Weight_Min)

	/// <Property class="CQA_BOF_Std_InToConver" name="Total_Weight_Max" type="L3DOUBLE">
	/// ��װ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Total_Weight_Max)

};

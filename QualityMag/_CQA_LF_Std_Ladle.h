// �߼���CQA_LF_Std_Ladleͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_LF_Std_Ladle :
	public CL3Object
{
public:
	CQA_LF_Std_Ladle(void);
	virtual ~CQA_LF_Std_Ladle(void);

	DECLARE_L3CLASS(CQA_LF_Std_Ladle,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Ladle)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Ladle" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Ladle" name="Ladle_Mat_Name" type="L3STRING">
	/// �ְ���������
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Mat_Name)

	/// <Property class="CQA_LF_Std_Ladle" name="Ladle_Mat_Min" type="L3DOUBLE">
	/// �ְ�����������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Mat_Min)

	/// <Property class="CQA_LF_Std_Ladle" name="Ladle_Mat_Max" type="L3DOUBLE">
	/// �ְ������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Mat_Max)

	/// <Property class="CQA_LF_Std_Ladle" name="Ladle_Mat_Aim" type="L3DOUBLE">
	/// �ְ���������Ŀ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Mat_Aim)

};

// �߼���CQA_BOF_Std_Baseͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_Base :
	public CL3Object
{
public:
	CQA_BOF_Std_Base(void);
	virtual ~CQA_BOF_Std_Base(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Base,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Base)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Base" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Base" name="Valid_Date" type="L3DATETIME">
	/// ��Ч����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Valid_Date)

	/// <Property class="CQA_BOF_Std_Base" name="New_Code" type="L3STRING">
	/// ���Ժ�
	/// </Property>
	DECLARE_L3PROP_STRING(New_Code)

	/// <Property class="CQA_BOF_Std_Base" name="Note" type="L3STRING">
	/// ˵��
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

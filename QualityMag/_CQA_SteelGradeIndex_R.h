// �߼���CQA_SteelGradeIndex_Rͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_SteelGradeIndex_R :
	public CL3Object
{
public:
	CQA_SteelGradeIndex_R(void);
	virtual ~CQA_SteelGradeIndex_R(void);

	DECLARE_L3CLASS(CQA_SteelGradeIndex_R,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_SteelGradeIndex_R)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_SteelGradeIndex_R" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_SteelGradeIndex_R" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_SteelGradeIndex_R" name="Grade_Group_Code" type="L3STRING">
	/// �쳣�������
	/// </Property>
	DECLARE_L3PROP_STRING(Grade_Group_Code)

	/// <Property class="CQA_SteelGradeIndex_R" name="First_Flag" type="L3SHORT">
	/// 
	/// �������ּǺű�־��
	/// 0������1��������
	/// </Property>
	DECLARE_L3PROP_LONG(First_Flag)


	/// <Property class="CQA_SteelGradeIndex_R" name="Protocol" type="L3STRING">
	/// Э��
	/// </Property>
	DECLARE_L3PROP_STRING(Protocol)
	
	/// <Property class="CQA_SteelGradeIndex_R" name="NC_Zyx1" type="L3STRING">
	/// ������1
	/// </Property>
	DECLARE_L3PROP_STRING(NC_Zyx1)

	/// <Property class="CQA_SteelGradeIndex_R" name="NC_Zyx2" type="L3STRING">
	/// ������2
	/// </Property>
	DECLARE_L3PROP_STRING(NC_Zyx2)

	
	/// <Property class="CQA_SteelGradeIndex_R" name="Protocol" type="L3STRING">
	/// ұ����ע
	/// </Property>
	DECLARE_L3PROP_STRING(BOF_Note)

	//Modify begin by llj 2011-03-11
	/// <Property class="CQA_SteelGradeIndex_R" name="Use_Flag" type="L3STRING">
	/// ʹ�ñ�־ 0:ʹ�� 1:����
	/// </Property>
	DECLARE_L3PROP_STRING(Use_Flag)
	//Modify end


};

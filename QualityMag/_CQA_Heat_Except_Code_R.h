// �߼���CQA_Heat_Except_Code_Rͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Heat_Except_Code_R :
	public CL3Object
{
public:
	CQA_Heat_Except_Code_R(void);
	virtual ~CQA_Heat_Except_Code_R(void);

	DECLARE_L3CLASS(CQA_Heat_Except_Code_R,XGMESLogic\\QualityMag, Exceptional_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Except_Code_R)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Except_Code_R" name="Exceptional_Code" type="L3STRING">
	/// �쳣����
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CQA_Heat_Except_Code_R" name="Exceptional_Group_Code" type="L3STRING">
	/// �쳣�������
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Group_Code)

	/// <Property class="CQA_Heat_Except_Code_R" name="Decide_Code" type="L3STRING">
	/// ���ô���
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

};

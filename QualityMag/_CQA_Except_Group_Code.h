// �߼���CQA_Except_Group_Codeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Except_Group_Code :
	public CL3Object
{
public:
	CQA_Except_Group_Code(void);
	virtual ~CQA_Except_Group_Code(void);

	DECLARE_L3CLASS(CQA_Except_Group_Code,XGMESLogic\\QualityMag, Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Except_Group_Code)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Except_Group_Code" name="Code" type="L3STRING">
	/// ���롢
	/// </Property>
	DECLARE_L3PROP_STRING(Code)

	/// <Property class="CQA_Except_Group_Code" name="Des" type="L3STRING">
	/// ���ݡ�
	/// </Property>
	DECLARE_L3PROP_STRING(Des)

};

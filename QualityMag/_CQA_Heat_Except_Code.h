// �߼���CQA_Heat_Except_Codeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Heat_Except_Code :
	public CL3Object
{
public:
	CQA_Heat_Except_Code(void);
	virtual ~CQA_Heat_Except_Code(void);

	DECLARE_L3CLASS(CQA_Heat_Except_Code,XGMESLogic\\QualityMag, Exceptional_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Except_Code)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Except_Code" name="Exceptional_Code" type="L3STRING">
	/// ���롢
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CQA_Heat_Except_Code" name="Exceptional_Des" type="L3STRING">
	/// ���ݡ�
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Des)

	/// <Property class="CQA_Heat_Except_Code" name="Unit" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Unit)

	/// <Property class="CQA_Heat_Except_Code" name="Auto_Judge_Flag" type="L3SHORT">
	/// �Զ��ж���־��
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Judge_Flag)

};

// �߼���CQA_Decide_Codeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Decide_Code :
	public CL3Object
{
public:
	CQA_Decide_Code(void);
	virtual ~CQA_Decide_Code(void);

	DECLARE_L3CLASS(CQA_Decide_Code,XGMESLogic\\QualityMag, Decide_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Decide_Code)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Decide_Code" name="Decide_Code" type="L3STRING">
	/// ���롢
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CQA_Decide_Code" name="Decide_Des" type="L3STRING">
	/// ���ݡ�
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Des)

	/// <Property class="CQA_Decide_Code" name="Classify" type="L3SHORT">
	/// ���ȼ�
	/// </Property>
	DECLARE_L3PROP_LONG(Classify)

};

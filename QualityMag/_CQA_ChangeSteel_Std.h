// �߼���CQA_ChangeSteel_Stdͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_ChangeSteel_Std :
	public CL3Object
{
public:
	CQA_ChangeSteel_Std(void);
	virtual ~CQA_ChangeSteel_Std(void);

	DECLARE_L3CLASS(CQA_ChangeSteel_Std,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_ChangeSteel_Std)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_ChangeSteel_Std" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_ChangeSteel_Std" name="Judged_SteelGrade" type="L3STRING">
	/// ���и���
	/// </Property>
	DECLARE_L3PROP_STRING(Judged_SteelGrade)

};

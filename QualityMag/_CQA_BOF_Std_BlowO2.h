// �߼���CQA_BOF_Std_BlowO2ͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_BlowO2 :
	public CL3Object
{
public:
	CQA_BOF_Std_BlowO2(void);
	virtual ~CQA_BOF_Std_BlowO2(void);

	DECLARE_L3CLASS(CQA_BOF_Std_BlowO2,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_BlowO2)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_BlowO2" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_BlowO2" name="Total_O2_Press_Ctr" type="L3STRING">
	/// �ܹ���ѹ���ƻ�׼
	/// </Property>
	DECLARE_L3PROP_STRING(Total_O2_Press_Ctr)

	/// <Property class="CQA_BOF_Std_BlowO2" name="Work_O2_Press_Ctr" type="L3STRING">
	/// ������ѹ���ƻ�׼
	/// </Property>
	DECLARE_L3PROP_STRING(Work_O2_Press_Ctr)

	/// <Property class="CQA_BOF_Std_BlowO2" name="O2_Blow_Ctr" type="L3STRING">
	/// �����������ƻ�׼
	/// </Property>
	DECLARE_L3PROP_STRING(O2_Blow_Ctr)

};

// �߼���CQA_RH_Std_Feedͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_RH_Std_Feed :
	public CL3Object
{
public:
	CQA_RH_Std_Feed(void);
	virtual ~CQA_RH_Std_Feed(void);

	DECLARE_L3CLASS(CQA_RH_Std_Feed,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_RH_Std_Feed)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_RH_Std_Feed" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_RH_Std_Feed" name="CaProc_Code" type="L3STRING">
	/// Ca����ι˿��
	/// </Property>
	DECLARE_L3PROP_STRING(CaProc_Code)

	/// <Property class="CQA_RH_Std_Feed" name="CaProc_Code_Weight_Max" type="L3DOUBLE">
	/// Ca����ι��ι�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProc_Code_Weight_Max)

	/// <Property class="CQA_RH_Std_Feed" name="CaProc_Code_Weight_Min" type="L3DOUBLE">
	/// Ca����ι��ι������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProc_Code_Weight_Min)

};

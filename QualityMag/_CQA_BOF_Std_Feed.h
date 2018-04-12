// �߼���CQA_BOF_Std_Feedͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_Feed :
	public CL3Object
{
public:
	CQA_BOF_Std_Feed(void);
	virtual ~CQA_BOF_Std_Feed(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Feed,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Feed)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Feed" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Feed" name="Feed_Code" type="L3STRING">
	/// ι˿������
	/// </Property>
	DECLARE_L3PROP_STRING(Feed_Code)

	/// <Property class="CQA_BOF_Std_Feed" name="Feed_Weight_Min" type="L3DOUBLE">
	/// ι˿��������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Feed_Weight_Min)

	/// <Property class="CQA_BOF_Std_Feed" name="Feed_Weight_Max" type="L3DOUBLE">
	/// ι˿�߼��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Feed_Weight_Max)

};

// �߼���CQA_LF_Std_Alloyͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_LF_Std_Alloy :
	public CL3Object
{
public:
	CQA_LF_Std_Alloy(void);
	virtual ~CQA_LF_Std_Alloy(void);

	DECLARE_L3CLASS(CQA_LF_Std_Alloy,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Alloy)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Alloy" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Alloy" name="Alloy_Flag" type="L3LONG">
	/// �Ͻ𻯷�
	/// </Property>
	DECLARE_L3PROP_LONG(Alloy_Flag)

	/// <Property class="CQA_LF_Std_Alloy" name="Alloy_Code" type="L3STRING">
	/// �Ͻ��ƺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CQA_LF_Std_Alloy" name="Alloy_Yield" type="L3DOUBLE">
	/// �Ͻ��յ���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Alloy_Yield)

};

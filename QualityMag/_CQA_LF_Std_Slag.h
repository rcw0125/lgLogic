// �߼���CQA_LF_Std_Slagͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_LF_Std_Slag :
	public CL3Object
{
public:
	CQA_LF_Std_Slag(void);
	virtual ~CQA_LF_Std_Slag(void);

	DECLARE_L3CLASS(CQA_LF_Std_Slag,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Slag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Slag" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Slag" name="Slag_Code" type="L3STRING">
	/// ����1�ƺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Slag_Code)

	/// <Property class="CQA_LF_Std_Slag" name="Slag_Weight" type="L3DOUBLE">
	/// ����1������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Slag_Weight)

};

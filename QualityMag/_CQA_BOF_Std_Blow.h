// �߼���CQA_BOF_Std_Blowͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_Blow :
	public CL3Object
{
public:
	CQA_BOF_Std_Blow(void);
	virtual ~CQA_BOF_Std_Blow(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Blow,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Blow)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Blow" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Blow" name="ReBlow_Cnt_Max" type="L3SHORT">
	/// �����������
	/// </Property>
	DECLARE_L3PROP_LONG(ReBlow_Cnt_Max)

	/// <Property class="CQA_BOF_Std_Blow" name="Catch_C_Temp_Min" type="L3LONG">
	/// ��̼�¶���С
	/// </Property>
	DECLARE_L3PROP_LONG(Catch_C_Temp_Min)

	/// <Property class="CQA_BOF_Std_Blow" name="ReBlow_Time_Max" type="L3SHORT">
	/// ����ʱ�����
	/// </Property>
	DECLARE_L3PROP_LONG(ReBlow_Time_Max)

	/// <Property class="CQA_BOF_Std_Blow" name="Bottom_Blow_Base" type="L3STRING">
	/// �״���׼
	/// </Property>
	DECLARE_L3PROP_STRING(Bottom_Blow_Base)

};

// �߼���CCalibration_Detailͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCalibration_Detail :
	public CL3Object
{
public:
	CCalibration_Detail(void);
	virtual ~CCalibration_Detail(void);

	DECLARE_L3CLASS(CCalibration_Detail,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCalibration_Detail)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCalibration_Detail" name="Location" type="L3STRING">
	/// �����ʶ=����+����
	/// </Property>
	DECLARE_L3PROP_STRING(LogID)

	/// <Property class="CCalibration_Detail" name="Load_B_Std" type="L3STRING">
	/// ����ǰ���ر�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Load_B_Std)

	/// <Property class="CCalibration_Detail" name="Load_B_Act" type="L3STRING">
	/// ����ǰ����ʾֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Load_B_Act)

	/// <Property class="CCalibration_Detail" name="Load_B_Dif" type="L3STRING">
	/// ����ǰ���ز�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Load_B_Dif)

	/// <Property class="CCalibration_Detail" name="UnLoad_B_Std" type="L3STRING">
	/// ����ǰж�ر�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_B_Std)

	/// <Property class="CCalibration_Detail" name="UnLoad_B_Act" type="L3STRING">
	/// ����ǰж��ʾֵ
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_B_Act)

	/// <Property class="CCalibration_Detail" name="UnLoad_B_Dif" type="L3STRING">
	/// ����ǰж�ز�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_B_Dif)

	/// <Property class="CCalibration_Detail" name="Load_A_Std" type="L3STRING">
	/// ��������ر�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Load_A_Std)

	/// <Property class="CCalibration_Detail" name="Load_A_Act" type="L3STRING">
	/// ���������ʾֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Load_A_Act)

	/// <Property class="CCalibration_Detail" name="Load_A_Dif" type="L3STRING">
	/// ��������ز�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Load_A_Dif)

	/// <Property class="CCalibration_Detail" name="UnLoad_A_Std" type="L3STRING">
	/// ������ж�ر�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_A_Std)

	/// <Property class="CCalibration_Detail" name="UnLoad_A_Act" type="L3STRING">
	/// ������ж��ʾֵ
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_A_Act)

	/// <Property class="CCalibration_Detail" name="UnLoad_A_Dif" type="L3STRING">
	/// ������ж�ز�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_A_Dif)

	/// <Property class="CCalibration_Detail" name="Create_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)
};

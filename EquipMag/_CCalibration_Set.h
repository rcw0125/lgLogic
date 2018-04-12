// �߼���CCalibration_Setͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCalibration_Set :
	public CL3Object
{
public:
	CCalibration_Set(void);
	virtual ~CCalibration_Set(void);

	DECLARE_L3CLASS(CCalibration_Set,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCalibration_Set)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCalibration_Set" name="Location" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Location)

	/// <Property class="CCalibration_Set" name="Location_Des" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Location_Des)

	/// <Property class="CCalibration_Set" name="Meter" type="L3STRING">
	/// �Ǳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Meter)

	/// <Property class="CCalibration_Set" name="Meter_Size" type="L3STRING">
	/// �Ǳ��ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Meter_Size)

	/// <Property class="CCalibration_Set" name="Range" type="L3STRING">
	/// ������Χ
	/// </Property>
	DECLARE_L3PROP_STRING(Range)

	/// <Property class="CCalibration_Set" name="Precision" type="L3STRING">
	/// ׼ȷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Precision)

	/// <Property class="CCalibration_Set" name="Factory" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCalibration_Set" name="Measure_ID" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Measure_ID)

	/// <Property class="CCalibration_Set" name="Standard_Equ" type="L3STRING">
	/// ��׼��
	/// </Property>
	DECLARE_L3PROP_STRING(Standard_Equ)

	/// <Property class="CCalibration_Set" name="Scale_Min" type="L3STRING">
	/// ��С�ֶ�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Scale_Min)

};

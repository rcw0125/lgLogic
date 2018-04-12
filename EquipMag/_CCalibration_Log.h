// �߼���CCalibration_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCalibration_Log :
	public CL3Object
{
public:
	CCalibration_Log(void);
	virtual ~CCalibration_Log(void);

	DECLARE_L3CLASS(CCalibration_Log,XGMESLogic\\EquipMag, LogID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCalibration_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCalibration_Log" name="Location" type="L3STRING">
	/// �����ʶ=����+����
	/// </Property>
	DECLARE_L3PROP_STRING(LogID)

	/// <Property class="CCalibration_Log" name="Location" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Location)

	/// <Property class="CCalibration_Log" name="Location_Des" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Location_Des)

	/// <Property class="CCalibration_Log" name="Meter" type="L3STRING">
	/// �Ǳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Meter)

	/// <Property class="CCalibration_Log" name="Meter_Size" type="L3STRING">
	/// �Ǳ��ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Meter_Size)

	/// <Property class="CCalibration_Log" name="Range" type="L3STRING">
	/// ������Χ
	/// </Property>
	DECLARE_L3PROP_STRING(Range)

	/// <Property class="CCalibration_Log" name="Precision" type="L3STRING">
	/// ׼ȷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Precision)

	/// <Property class="CCalibration_Log" name="Factory" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCalibration_Log" name="Measure_ID" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Measure_ID)

	/// <Property class="CCalibration_Log" name="Standard_Equ" type="L3STRING">
	/// ��׼��
	/// </Property>
	DECLARE_L3PROP_STRING(Standard_Equ)

	/// <Property class="CCalibration_Log" name="Scale_Min" type="L3STRING">
	/// ��С�ֶ�ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Scale_Min)

	/// <Property class="CCalibration_Log" name="Check_Date" type="L3DATETIME">
	/// У׼����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CCalibration_Log" name="Create_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CCalibration_Log" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CCalibration_Log" name="Auditing_Time" type="L3DATETIME">
	/// ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Auditing_Time)

	/// <Property class="CCalibration_Log" name="Assessor" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(Assessor)

	/// <Property class="CCalibration_Log" name="Result" type="L3STRING">
	/// У�����
	/// </Property>
	DECLARE_L3PROP_STRING(Result)

	/// <Property class="CCalibration_Log" name="Status" type="L3LONG">
	/// ״̬ 0-δ��ˡ�1-�����
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

};

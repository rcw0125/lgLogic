// �߼���CDeS_Addition_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDeS_Addition_Data :
	public CL3Object
{
public:
	CDeS_Addition_Data(void);
	virtual ~CDeS_Addition_Data(void);

	DECLARE_L3CLASS(CDeS_Addition_Data,XGMESLogic\\DeSMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Addition_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDeS_Addition_Data" name="UnitID" type="L3STRING">
	/// ����λ
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CDeS_Addition_Data" name="Mat_Code" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(Mat_Code)

	/// <Property class="CDeS_Addition_Data" name="Mat_Vendor" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(Mat_Vendor)

	/// <Property class="CDeS_Addition_Data" name="Weight" type="L3FLOAT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CDeS_Addition_Data" name="Time_Discharge" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Discharge)

	/// <Property class="CDeS_Addition_Data" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDeS_Addition_Data" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDeS_Addition_Data" name="Operator" type="L3STRING">
	/// ����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CDeS_Addition_Data" name="Time_Begin_Discharge" type="L3DATETIME">
	/// ���Ͽ�ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Begin_Discharge)

	/// <Property class="CDeS_Addition_Data" name="Time_Stop_Discharge" type="L3DATETIME">
	/// ���Ͻ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Stop_Discharge)
};

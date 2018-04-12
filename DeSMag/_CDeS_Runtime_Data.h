// �߼���CDeS_Runtime_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDeS_Runtime_Data :
	public CL3Object
{
public:
	CDeS_Runtime_Data(void);
	virtual ~CDeS_Runtime_Data(void);

	DECLARE_L3CLASS(CDeS_Runtime_Data,XGMESLogic\\DeSMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Runtime_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();
	/// <Property class="CDeS_Process_Data" name="ID_Object" type="L3STRING">
	/// �����ʶ
	/// (����+�޺�+�紵��)
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)

	/// <Property class="CDeS_Process_Data" name="TreatNo" type="L3STRING">
	/// �紵��
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CDeS_Process_Data" name="Pressure" type="L3DOUBLE">
	/// ����ѹ��(MPa)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure)

	/// <Property class="CDeS_Process_Data" name="Flow" type="L3DOUBLE">
	/// ��������(Nm3/h)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow)

	/// <Property class="CDeS_Process_Data" name="Rate" type="L3DOUBLE">
	/// ����(kg/min)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Rate)

	/// <Property class="CDeS_Process_Data" name="Catch_Count" type="L3LONG">
	/// �ɼ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Catch_Count)

	/// <Property class="CDeS_Process_Data" name="Catch_Time" type="L3LONG">
	/// �ɼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)
};

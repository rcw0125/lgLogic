// �߼���CAOD_Oxygen_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAOD_Oxygen_Data :
	public CL3Object
{
public:
	CAOD_Oxygen_Data(void);
	virtual ~CAOD_Oxygen_Data(void);

	DECLARE_L3CLASS(CAOD_Oxygen_Data,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Oxygen_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAOD_Oxygen_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Oxygen_Data" name="Oxygen_Content" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(Oxygen_Content)

	/// <Property class="CAOD_Oxygen_Data" name="Measure_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Measure_Time)

	/// <Property class="CAOD_Temp_Data" name="Temp" type="L3LONG">
	/// ����ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)
};

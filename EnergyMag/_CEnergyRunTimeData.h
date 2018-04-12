// �߼���CEnergyRunTimeDataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEnergyRunTimeData :
	public CL3Object
{
public:
	CEnergyRunTimeData(void);
	virtual ~CEnergyRunTimeData(void);

	DECLARE_L3CLASS(CEnergyRunTimeData,XGMESLogic\\EnergyMag, TagName)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergyRunTimeData)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEnergyRunTimeData" name="TagName" type="L3STRING">
	/// ��ǩ��
	/// </Property>
	DECLARE_L3PROP_STRING(TagName)

	/// <Property class="CEnergyRunTimeData" name="TagCode" type="L3STRING">
	/// ��ǩ����
	/// </Property>
	DECLARE_L3PROP_STRING(TagCode)

	/// <Property class="CEnergyRunTimeData" name="TagDesc" type="L3STRING">
	/// ��ǩ����
	/// </Property>
	DECLARE_L3PROP_STRING(TagDesc)

	/// <Property class="CEnergyRunTimeData" name="Pressure" type="L3DOUBLE">
	/// ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure)

	/// <Property class="CEnergyRunTimeData" name="Flow" type="L3DOUBLE">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow)

	/// <Property class="CEnergyRunTimeData" name="P_Max" type="L3DOUBLE">
	/// ѹ������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Max)

	/// <Property class="CEnergyRunTimeData" name="P_Min" type="L3DOUBLE">
	/// ѹ������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Min)

	/// <Property class="CEnergyRunTimeData" name="P_High" type="L3DOUBLE">
	/// ѹ������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_High)

	/// <Property class="CEnergyRunTimeData" name="P_Low" type="L3DOUBLE">
	/// ѹ������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Low)

	/// <Property class="CEnergyRunTimeData" name="F_Max" type="L3DOUBLE">
	/// ��������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(F_Max)

	/// <Property class="CEnergyRunTimeData" name="F_Min" type="L3DOUBLE">
	/// ��������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(F_Min)

	/// <Property class="CEnergyRunTimeData" name="F_High" type="L3DOUBLE">
	/// ��������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(F_High)

	/// <Property class="CEnergyRunTimeData" name="F_Low" type="L3DOUBLE">
	/// ��������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(F_Low)

	/// <Property class="CEnergyRunTimeData" name="Catch_Time" type="L3DATETIME">
	/// �ɼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

	/// <Property class="CEnergyRunTimeData" name="Multiple" type="L3DOUBLE">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Multiple)

	/// <Property class="CEnergyRunTimeData" name="MeasuringRange" type="L3DOUBLE">
	/// �ֳ�(����)�Ǳ��ֻ�ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MeasuringRange)
};

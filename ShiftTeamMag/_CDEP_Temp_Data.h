// �߼���CBOF_Temp_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDEP_Temp_Data :
	public CL3Object
{
public:
	CDEP_Temp_Data(void);
	virtual ~CDEP_Temp_Data(void);

	DECLARE_L3CLASS(CDEP_Temp_Data,XGMESLogic\\DePMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDEP_Temp_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();
	/// <Property class="CDEP_Temp_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	//DECLARE_L3PROP_STRING(IronLadle)

	/// <Property class="CDEP_Temp_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CDEP_Temp_Data" name="Temp" type="L3LONG">
	/// ����ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)

	/// <Property class="CDEP_Temp_Data" name="Temp_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Temp_Time)

	/// <Property class="CDEP_Temp_Data" name="Mode" type="L3SHORT">
	/// ����ģʽ(1-����ǹ����;2-�����ǲ���)
	/// </Property>
	DECLARE_L3PROP_SHORT(Mode)

};

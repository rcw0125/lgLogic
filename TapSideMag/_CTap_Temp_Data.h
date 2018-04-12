// �߼���CTap_Temp_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTap_Temp_Data :
	public CL3Object
{
public:
	CTap_Temp_Data(void);
	virtual ~CTap_Temp_Data(void);

	DECLARE_L3CLASS(CTap_Temp_Data,XGMESLogic\\TapSideMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Temp_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTap_Temp_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Temp_Data" name="Temperature" type="L3LONG">
	/// ����ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Temperature)

	/// <Property class="CTap_Temp_Data" name="MeasureTime" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(MeasureTime)

	/// <Property class="CTap_Temp_Data" name="MeasureType" type="L3SHORT">
	/// ��������(1-����ǹ����;2-�����ǲ���)
	/// </Property>
	DECLARE_L3PROP_SHORT(MeasureType)

};

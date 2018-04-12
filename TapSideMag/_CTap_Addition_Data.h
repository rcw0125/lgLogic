// �߼���CTap_Addition_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTap_Addition_Data :
	public CL3Object
{
public:
	CTap_Addition_Data(void);
	virtual ~CTap_Addition_Data(void);

	DECLARE_L3CLASS(CTap_Addition_Data,XGMESLogic\\TapSideMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Addition_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTap_Addition_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Addition_Data" name="Element" type="L3STRING">
	/// ���ϴ���
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CTap_Addition_Data" name="Weight" type="L3FLOAT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CTap_Addition_Data" name="Length" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Length)

	/// <Property class="CTap_Addition_Data" name="Discharge_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Discharge_Time)

	/// <Property class="CTap_Addition_Data" name="Type" type="L3SHORT">
	/// 
	/// ��������(1-������;
	///                  2-ι˿)
	/// </Property>
	DECLARE_L3PROP_SHORT(Type)

	/// <Property class="CTap_Addition_Data" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)
};

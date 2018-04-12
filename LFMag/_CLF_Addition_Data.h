// �߼���CLF_Addition_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_Addition_Data :
	public CL3Object
{
public:
	CLF_Addition_Data(void);
	virtual ~CLF_Addition_Data(void);

	DECLARE_L3CLASS(CLF_Addition_Data,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Addition_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_Addition_Data" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Addition_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Addition_Data" name="Element" type="L3STRING">
	/// ���ϴ���
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CLF_Addition_Data" name="Weight" type="L3FLOAT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CLF_Addition_Data" name="Discharge_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Discharge_Time)

	/// <Property class="CLF_Addition_Data" name="Type" type="L3SHORT">
	/// 
	/// ��������(1-����;
	///          2:�Ͻ�)
	/// </Property>
	DECLARE_L3PROP_SHORT(Type)

	/// <Property class="CLF_Addition_Data" name="Area" type="L3STRING">
	/// �ϲֺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Area)

	/// <Property class="CLF_Addition_Data" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CLF_Addition_Data" name="Vendor" type="L3STRING">
	/// ����
	/// </Property> 2009-03-19
	DECLARE_L3PROP_STRING(Vendor)
};

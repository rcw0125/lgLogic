// �߼���CLF_Wire_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_Wire_Data :
	public CL3Object
{
public:
	CLF_Wire_Data(void);
	virtual ~CLF_Wire_Data(void);

	DECLARE_L3CLASS(CLF_Wire_Data,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Wire_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_Wire_Data" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Wire_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Wire_Data" name="WireCode" type="L3STRING">
	/// ι�ߴ���
	/// </Property>
	DECLARE_L3PROP_STRING(WireCode)

	/// <Property class="CLF_Wire_Data" name="Weight" type="L3FLOAT">
	/// ι����[����]
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CLF_Wire_Data" name="Speed" type="L3FLOAT">
	/// ι���ٶ�
	/// </Property>
	DECLARE_L3PROP_FLOAT(Speed)

	/// <Property class="CLF_Wire_Data" name="WireTime" type="L3DATETIME">
	/// ι��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(WireTime)

	/// <Property class="CLF_Wire_Data" name="Batch_Code" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CLF_Wire_Data" name="Vendor" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Vendor)

	/// <Property class="CLF_Wire_Data" name="Amount" type="L3FLOAT">
	/// ι����[����]
	/// </Property>
	DECLARE_L3PROP_FLOAT(Amount)
};

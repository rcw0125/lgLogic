// �߼���CTundish_Baseͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_Base :
	public CL3Object
{
public:
	CTundish_Base(void);
	virtual ~CTundish_Base(void);

	DECLARE_L3CLASS(CTundish_Base,XGMESLogic\\TundishMag, TundishID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Base)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	
	/// <Property class="CTundish_Base" name="TundishID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	
	/// <Property class="CTundish_Base" name="Cast_ID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_Base" name="Refra_Pro" type="L3STRING">
	/// �ͲĲ���
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Pro)

	/// <Property class="CTundish_Base" name="Status" type="L3STRING">
	/// ״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CTundish_Base" name="Tundish_Age" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Age)

	/// <Property class="CTundish_Base" name="InnerID" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Base" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_Base" name="TundishNO" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNO)

	/// <Property class="CTundish_Base" name="Flag" type="L3LONG">
	/// ��ɱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Flag)

	/// <Property class="CTundish_Base" name="TundishType" type="L3SHORT">
	/// �а�����
	/// </Property>
	DECLARE_L3PROP_SHORT(TundishType)

	/// <Property class="CTundish_Base" name="VehicleID" type="L3STRING">
	/// �а�����
	/// </Property>
	DECLARE_L3PROP_STRING(VehicleID)

};

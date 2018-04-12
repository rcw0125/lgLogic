// �߼���CCCM_Tundish_Fire_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Tundish_Fire_Data :
	public CL3Object
{
public:
	CCCM_Tundish_Fire_Data(void);
	virtual ~CCCM_Tundish_Fire_Data(void);

	DECLARE_L3CLASS(CCCM_Tundish_Fire_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Tundish_Fire_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Tundish_Fire_Data" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CCCM_Tundish_Fire_Data" name="Cast_ID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CCCM_Tundish_Fire_Data" name="TundishID" type="L3STRING">
	/// �а���
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CCCM_Tundish_Fire_Data" name="Flow_Gas" type="L3FLOAT">
	/// ú������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_Gas)

	/// <Property class="CCCM_Tundish_Fire_Data" name="Position" type="L3STRING">
	/// �濾λ��
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CCCM_Tundish_Fire_Data" name="Fire_Type" type="L3STRING">
	/// �濾����
	/// </Property>
	DECLARE_L3PROP_STRING(Fire_Type)

	/// <Property class="CCCM_Tundish_Fire_Data" name="MeasureTime" type="L3DATETIME">
	/// ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(MeasureTime)

};

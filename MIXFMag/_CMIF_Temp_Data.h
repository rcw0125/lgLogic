// �߼���CMIF_Temp_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMIF_Temp_Data :
	public CL3Object
{
public:
	CMIF_Temp_Data(void);
	virtual ~CMIF_Temp_Data(void);

	DECLARE_L3CLASS(CMIF_Temp_Data,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Temp_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CMIF_Temp_Data" name="MIFID" type="L3STRING">
	/// ����¯¯��
	/// </Property>
	DECLARE_L3PROP_STRING(MIFID)

	/// <Property class="CMIF_Temp_Data" name="Temp" type="L3LONG">
	/// �¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)

	/// <Property class="CMIF_Temp_Data" name="Temp_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Temp_Time)

	/// <Property class="CMIF_Temp_Data" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CMIF_Temp_Data" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

};

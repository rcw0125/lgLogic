// �߼���CCCM_Casting_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Casting_Data :
	public CL3Object
{
public:
	CCCM_Casting_Data(void);
	virtual ~CCCM_Casting_Data(void);

	DECLARE_L3CLASS(CCCM_Casting_Data,XGMESLogic\\CCMMag, CastingNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Casting_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Casting_Data" name="CastingNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Casting_Data" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Casting_Data" name="Casting_Start_Time" type="L3DATETIME">
	/// ���ο�ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Start_Time)

	/// <Property class="CCCM_Casting_Data" name="Casting_Stop_Time" type="L3DATETIME">
	/// ���ν���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Stop_Time)

	/// <Property class="CCCM_Casting_Data" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CCCM_Casting_Data" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CCCM_Casting_Data" name="First_HeatID" type="L3STRING">
	/// ���ε�һ¯
	/// </Property>
	DECLARE_L3PROP_STRING(First_HeatID)

	/// <Property class="CCCM_Casting_Data" name="Last_HeatID" type="L3STRING">
	/// �������һ¯
	/// </Property>
	DECLARE_L3PROP_STRING(Last_HeatID)

	/// <Property class="CCCM_Casting_Data" name="HeatCount" type="L3LONG">
	/// ��ǰ������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(HeatCount)

};

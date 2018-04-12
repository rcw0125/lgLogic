// �߼���CLance_Useͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLance_Use :
	public CL3Object
{
public:
	CLance_Use(void);
	virtual ~CLance_Use(void);

	DECLARE_L3CLASS(CLance_Use,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Use)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLance_Use" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_Use" name="LanceID" type="L3STRING">
	/// ǹ��
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Use" name="MakeID" type="L3STRING">
	/// ��ǹ�������
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Use" name="Lance_Head_Type" type="L3STRING">
	/// ǹͷ�ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Use" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLance_Use" name="Shift_Date" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Shift_Date)

	/// <Property class="CLance_Use" name="Cool_Water_Flow" type="L3DOUBLE">
	/// ��ȴˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cool_Water_Flow)

	/// <Property class="CLance_Use" name="Cool_Water_Temp" type="L3DOUBLE">
	/// ��ȴˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cool_Water_Temp)

	/// <Property class="CLance_Use" name="Oxygen_Pressure" type="L3DOUBLE">
	/// ����(����)ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Oxygen_Pressure)

	/// <Property class="CLance_Use" name="Oxygen_Flow" type="L3DOUBLE">
	/// ����(����)����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Oxygen_Flow)

	/// <Property class="CLance_Use" name="Furnace_Count" type="L3LONG">
	/// ����ʹ��¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Furnace_Count)

	/// <Property class="CLance_Use" name="Change_Lance_Reason" type="L3STRING">
	/// ��ǹԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Change_Lance_Reason)

	/// <Property class="CLance_Use" name="Total_Lance_Age" type="L3LONG">
	/// �ۼ�ǹ��
	/// </Property>
	DECLARE_L3PROP_LONG(Total_Lance_Age)

	/// <Property class="CLance_Use" name="Amelt_Confirm_Pepole" type="L3STRING">
	/// ұ��ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Amelt_Confirm_Pepole)

	/// <Property class="CLance_Use" name="Maintain_Confirm_Pepole" type="L3STRING">
	/// ά��ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Maintain_Confirm_Pepole)

	/// <Property class="CLance_Use" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_Use" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_Use" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLance_Use" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

// �߼���CLance_Defendͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLance_Defend :
	public CL3Object
{
public:
	CLance_Defend(void);
	virtual ~CLance_Defend(void);

	DECLARE_L3CLASS(CLance_Defend,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Defend)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLance_Defend" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_Defend" name="LanceID" type="L3STRING">
	/// ǹ��
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Defend" name="Check_Date" type="L3DATETIME">
	/// �������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CLance_Defend" name="Lance_Head_Type" type="L3STRING">
	/// ǹͷ�ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Defend" name="MakeID" type="L3STRING">
	/// ��ǹ�������
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Defend" name="Test_Water_Pressure" type="L3DOUBLE">
	/// ��ˮѹ��[MPa]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Test_Water_Pressure)

	/// <Property class="CLance_Defend" name="Nasal_Erosion" type="L3DOUBLE">
	/// ������ʴ[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nasal_Erosion)

	/// <Property class="CLance_Defend" name="Exit_Shape" type="L3LONG">
	/// �����Ƿ����
	/// </Property>
	DECLARE_L3PROP_LONG(Exit_Shape)

	/// <Property class="CLance_Defend" name="Sundry" type="L3LONG">
	/// ������Ƿ�������
	/// </Property>
	DECLARE_L3PROP_LONG(Sundry)

	/// <Property class="CLance_Defend" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_Defend" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_Defend" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLance_Defend" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

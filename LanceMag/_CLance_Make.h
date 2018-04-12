// �߼���CLance_Makeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLance_Make :
	public CL3Object
{
public:
	CLance_Make(void);
	virtual ~CLance_Make(void);

	DECLARE_L3CLASS(CLance_Make,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Make)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLance_Make" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_Make" name="LanceID" type="L3STRING">
	/// ǹ��
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Make" name="Check_Date" type="L3DATETIME">
	/// �������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CLance_Make" name="Lance_Head_Type" type="L3STRING">
	/// ǹͷ�ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Make" name="MakeID" type="L3STRING">
	/// ��ǹ�������
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Make" name="Nozzle_Factury" type="L3STRING">
	/// ��ͷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Nozzle_Factury)

	/// <Property class="CLance_Make" name="Nozzle_Throat_Dia" type="L3DOUBLE">
	/// ��ͷ���ֱ��[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Throat_Dia)

	/// <Property class="CLance_Make" name="Nozzle_Angle" type="L3DOUBLE">
	/// ��ͷ�н�[��]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Angle)

	/// <Property class="CLance_Make" name="Weld_Operator" type="L3STRING">
	/// װ�亸����
	/// </Property>
	DECLARE_L3PROP_STRING(Weld_Operator)

	/// <Property class="CLance_Make" name="Suppress_Operator" type="L3STRING">
	/// װ���ѹ��
	/// </Property>
	DECLARE_L3PROP_STRING(Suppress_Operator)

	/// <Property class="CLance_Make" name="Test_Water_Pressure" type="L3DOUBLE">
	/// ��ˮѹ��[MPa]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Test_Water_Pressure)

	/// <Property class="CLance_Make" name="Assembly_Starte_Time" type="L3DATETIME">
	/// ������ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Assembly_Starte_Time)

	/// <Property class="CLance_Make" name="Assembly_End_Time" type="L3DATETIME">
	/// ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Assembly_End_Time)

	/// <Property class="CLance_Make" name="Nasal_Erosion" type="L3DOUBLE">
	/// ������ʴ[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nasal_Erosion)

	/// <Property class="CLance_Make" name="Exit_Shape" type="L3LONG">
	/// �����Ƿ����
	/// </Property>
	DECLARE_L3PROP_LONG(Exit_Shape)

	/// <Property class="CLance_Make" name="Sundry" type="L3LONG">
	/// ������Ƿ�������
	/// </Property>
	DECLARE_L3PROP_LONG(Sundry)

	/// <Property class="CLance_Make" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_Make" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_Make" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLance_Make" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

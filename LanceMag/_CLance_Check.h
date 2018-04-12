// �߼���CLance_Checkͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLance_Check :
	public CL3Object
{
public:
	CLance_Check(void);
	virtual ~CLance_Check(void);

	DECLARE_L3CLASS(CLance_Check,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Check)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLance_Check" name="Input_Time" type="L3DATETIME">
	/// ¼������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_Check" name="LanceID" type="L3STRING">
	/// ǹ��
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Check" name="MakeID" type="L3STRING">
	/// ��ǹ�������
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Check" name="Lance_Head_Type" type="L3STRING">
	/// ǹͷ�ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Check" name="Nozzle_Factury" type="L3STRING">
	/// ��ͷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Nozzle_Factury)

	/// <Property class="CLance_Check" name="Nozzle_Throat_Dia" type="L3DOUBLE">
	/// ��ͷ���ֱ��[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Throat_Dia)

	/// <Property class="CLance_Check" name="Nozzle_Angle" type="L3DOUBLE">
	/// ��ͷ�н�[��]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Angle)

	/// <Property class="CLance_Check" name="Off_Date" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Off_Date)

	/// <Property class="CLance_Check" name="Nasal_Erosion" type="L3LONG">
	/// �����Ƿ�ʴ
	/// </Property>
	DECLARE_L3PROP_LONG(Nasal_Erosion)

	/// <Property class="CLance_Check" name="Exit_Shape" type="L3LONG">
	/// �����Ƿ����
	/// </Property>
	DECLARE_L3PROP_LONG(Exit_Shape)

	/// <Property class="CLance_Check" name="Nozzle_Assembly_Date" type="L3DATETIME">
	/// ��ͷװ������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Nozzle_Assembly_Date)

	/// <Property class="CLance_Check" name="Lance_Body_Shap" type="L3LONG">
	/// ǹ���Ƿ����
	/// </Property>
	DECLARE_L3PROP_LONG(Lance_Body_Shap)

	/// <Property class="CLance_Check" name="In_Mid_Out_Replace" type="L3LONG">
	/// �ڡ��С�����Ƿ����
	/// </Property>
	DECLARE_L3PROP_LONG(In_Mid_Out_Replace)

	/// <Property class="CLance_Check" name="Weld_Check" type="L3LONG">
	/// ������
	/// </Property>
	DECLARE_L3PROP_LONG(Weld_Check)

	/// <Property class="CLance_Check" name="N2_And_Baffle_Check" type="L3LONG">
	/// ����׼�������
	/// </Property>
	DECLARE_L3PROP_LONG(N2_And_Baffle_Check)

	/// <Property class="CLance_Check" name="Ring_Check" type="L3LONG">
	/// ���Ҽ��
	/// </Property>
	DECLARE_L3PROP_LONG(Ring_Check)

	/// <Property class="CLance_Check" name="Flange_Check" type="L3LONG">
	/// ��ǹ�������
	/// </Property>
	DECLARE_L3PROP_LONG(Flange_Check)

	/// <Property class="CLance_Check" name="Test_Water_Pressure" type="L3DOUBLE">
	/// ��ˮѹ��[MPa]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Test_Water_Pressure)

	/// <Property class="CLance_Check" name="Keep_Pressure_Time" type="L3DOUBLE">
	/// ��ѹʱ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Keep_Pressure_Time)

	/// <Property class="CLance_Check" name="Test_Water_Result" type="L3LONG">
	/// ��ˮ��ҵ���
	/// </Property>
	DECLARE_L3PROP_LONG(Test_Water_Result)

	/// <Property class="CLance_Check" name="Test_Water_Operator" type="L3STRING">
	/// ��ˮ��ҵ��
	/// </Property>
	DECLARE_L3PROP_STRING(Test_Water_Operator)

	/// <Property class="CLance_Check" name="BOFID" type="L3STRING">
	/// ʹ��ת¯¯��
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CLance_Check" name="Rise_Lance_Date" type="L3DATETIME">
	/// ��ǹ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Rise_Lance_Date)

	/// <Property class="CLance_Check" name="On_Lance_Operator" type="L3STRING">
	/// ��ǹ��ҵ��Ա
	/// </Property>
	DECLARE_L3PROP_STRING(On_Lance_Operator)

	/// <Property class="CLance_Check" name="Off_Lance_Operator" type="L3STRING">
	/// ��ǹ��ҵ��Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Lance_Operator)

	/// <Property class="CLance_Check" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_Check" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_Check" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLance_Check" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)


};

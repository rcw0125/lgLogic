// �߼���CLance_In_Yardͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLance_In_Yard :
	public CL3Object
{
public:
	CLance_In_Yard(void);
	virtual ~CLance_In_Yard(void);

	DECLARE_L3CLASS(CLance_In_Yard,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_In_Yard)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLance_In_Yard" name="Input_Time" type="L3DATETIME">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_In_Yard" name="Lance_Head_Type" type="L3STRING">
	/// ǹͷ�ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_In_Yard" name="Nozzle_Factury" type="L3STRING">
	/// ��ͷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Nozzle_Factury)

	/// <Property class="CLance_In_Yard" name="Nozzle_Throat_Dia" type="L3DOUBLE">
	/// ��ͷ���ֱ��[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Throat_Dia)

	/// <Property class="CLance_In_Yard" name="Nozzle_Angle" type="L3DOUBLE">
	/// ��ͷ�н�[��]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Angle)

	/// <Property class="CLance_In_Yard" name="IN_Yard" type="L3LONG">
	/// �����
	/// </Property>
	DECLARE_L3PROP_LONG(IN_Yard)

	/// <Property class="CLance_In_Yard" name="IN_Total" type="L3LONG">
	/// �������
	/// </Property>
	DECLARE_L3PROP_LONG(IN_Total)

	/// <Property class="CLance_In_Yard" name="In_Confirm" type="L3STRING">
	/// ���ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(In_Confirm)

	/// <Property class="CLance_In_Yard" name="TeamID" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_In_Yard" name="ShiftID" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_In_Yard" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

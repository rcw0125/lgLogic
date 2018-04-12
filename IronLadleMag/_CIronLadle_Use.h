// �߼���CIronLadle_Useͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CIronLadle_Use :
	public CL3Object
{
public:
	CIronLadle_Use(void);
	virtual ~CIronLadle_Use(void);

	DECLARE_L3CLASS(CIronLadle_Use,XGMESLogic\\IronLadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Use)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CIronLadle_Use" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CIronLadle_Use" name="IronLadleID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadleID)

	/// <Property class="CIronLadle_Use" name="TieID" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TieID)

	/// <Property class="CIronLadle_Use" name="Check_Time" type="L3DATETIME">
	/// ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Time)

	/// <Property class="CIronLadle_Use" name="IronLadle_Age" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(IronLadle_Age)

	/// <Property class="CIronLadle_Use" name="Wall_TEMP" type="L3FLOAT">
	/// �����¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(Wall_TEMP)

	/// <Property class="CIronLadle_Use" name="Bottom_TEMP" type="L3FLOAT">
	/// �����¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(Bottom_TEMP)

	/// <Property class="CIronLadle_Use" name="Stop_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Stop_Reason)

	/// <Property class="CIronLadle_Use" name="Throw_Time" type="L3STRING">
	/// ˦��ʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(Throw_Time)

	
	/// <Property class="CIronLadle_Use" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	
	/// <Property class="CIronLadle_Use" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CIronLadle_Use" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CIronLadle_Use" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

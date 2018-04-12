// �߼���CIronLadle_Tieͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CIronLadle_Tie :
	public CL3Object
{
public:
	CIronLadle_Tie(void);
	virtual ~CIronLadle_Tie(void);

	DECLARE_L3CLASS(CIronLadle_Tie,XGMESLogic\\IronLadleMag, TieID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Tie)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	
	/// <Property class="CIronLadle_Tie" name="InPut_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(InPut_Time)

	/// <Property class="CIronLadle_Tie" name="IronLadleID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadleID)

	/// <Property class="CIronLadle_Tie" name="TieID" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TieID)

	/// <Property class="CIronLadle_Tie" name="Refra_Produce" type="L3STRING">
	/// �Ͳĳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Produce)

	/// <Property class="CIronLadle_Tie" name="Refra_ID" type="L3STRING">
	/// �Ͳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_ID)

	/// <Property class="CIronLadle_Tie" name="Consumption" type="L3FLOAT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Consumption)

	/// <Property class="CIronLadle_Tie" name="Tie_Start_Time" type="L3DATETIME">
	/// ��Ὺʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_Start_Time)

	/// <Property class="CIronLadle_Tie" name="Tie_End_Time" type="L3DATETIME">
	/// ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_End_Time)

	
	/// <Property class="CIronLadle_Tie" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	
	/// <Property class="CIronLadle_Tie" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	
	/// <Property class="CIronLadle_Tie" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CIronLadle_Tie" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CIronLadle_Tie" name="Doff_Mod_Time" type="L3DATETIME">
	/// ��ģʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Doff_Mod_Time)

};

// �߼���CIronLadle_Fireͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CIronLadle_Fire :
	public CL3Object
{
public:
	CIronLadle_Fire(void);
	virtual ~CIronLadle_Fire(void);

	DECLARE_L3CLASS(CIronLadle_Fire,XGMESLogic\\IronLadleMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CIronLadle_Fire" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CIronLadle_Fire" name="IronLadleID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadleID)

	/// <Property class="CIronLadle_Fire" name="TieID" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TieID)

	/// <Property class="CIronLadle_Fire" name="Fire_Type" type="L3STRING">
	/// �濾����
	/// </Property>
	DECLARE_L3PROP_STRING(Fire_Type)

	/// <Property class="CIronLadle_Fire" name="Fire_Start_Time" type="L3DATETIME">
	/// �濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CIronLadle_Fire" name="Fire_End_Time" type="L3DATETIME">
	/// �濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CIronLadle_Fire" name="Fire_Length" type="L3LONG">
	/// �濾ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(Fire_Length)

	/// <Property class="CIronLadle_Fire" name="Operator" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CIronLadle_Fire" name="NOTE" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(NOTE)

	/// <Property class="CIronLadle_Fire" name="TeamID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CIronLadle_Fire" name="ShiftID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	//2009-03-17
	/// <Property class="CIronLadle_Fire" name="FireID" type="L3LONG">
	/// �濾����
	/// </Property>
	DECLARE_L3PROP_LONG(FireID)

	/// <Property class="CIronLadle_Fire" name="Object_ID" type="L3STRING">
	/// �ؼ���[TieID + Fire_Type + FireID]
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};

// �߼���CLadle_Foldͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Fold :
	public CL3Object
{
public:
	CLadle_Fold(void);
	virtual ~CLadle_Fold(void);

	DECLARE_L3CLASS(CLadle_Fold,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Fold)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Fold" name="Input_Time" type="L3DATETIME">
	/// ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Fold" name="Steel_Grade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Steel_Grade)

	/// <Property class="CLadle_Fold" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLadle_Fold" name="Out_LadleID" type="L3STRING">
	/// �����ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(Out_LadleID)

	/// <Property class="CLadle_Fold" name="In_LadleID" type="L3STRING">
	/// ����ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(In_LadleID)

	/// <Property class="CLadle_Fold" name="Weight" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Weight)

	/// <Property class="CLadle_Fold" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Fold" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Fold" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Fold" name="Operator" type="L3STRING">
	/// �۹�ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Fold" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Fold" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

};

// �߼���CTundish_Inner_Fireͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_Inner_Fire :
	public CL3Object
{
public:
	CTundish_Inner_Fire(void);
	virtual ~CTundish_Inner_Fire(void);

	DECLARE_L3CLASS(CTundish_Inner_Fire,XGMESLogic\\TundishMag, InnerID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Inner_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTundish_Inner_Fire" name="TundishID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_Inner_Fire" name="InnerID" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Inner_Fire" name="Small_Fire_Time" type="L3DATETIME">
	/// С��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Small_Fire_Time)

	/// <Property class="CTundish_Inner_Fire" name="Small_Fire_Operator" type="L3STRING">
	/// С�������
	/// </Property>
	DECLARE_L3PROP_STRING(Small_Fire_Operator)

	/// <Property class="CTundish_Inner_Fire" name="Mid_Fire_Time" type="L3DATETIME">
	/// �л�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Mid_Fire_Time)

	/// <Property class="CTundish_Inner_Fire" name="Mid_Fire_Operator" type="L3STRING">
	/// �л������
	/// </Property>
	DECLARE_L3PROP_STRING(Mid_Fire_Operator)

	/// <Property class="CTundish_Inner_Fire" name="Big_Fire_Time" type="L3DATETIME">
	/// ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Big_Fire_Time)

	/// <Property class="CTundish_Inner_Fire" name="Big_Fire_Operator" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Big_Fire_Operator)

	/// <Property class="CTundish_Inner_Fire" name="Close_Fire_Time" type="L3DATETIME">
	/// ͣ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Close_Fire_Time)

	/// <Property class="CTundish_Inner_Fire" name="Close_Fire_Operator" type="L3STRING">
	/// ͣ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Close_Fire_Operator)

	/// <Property class="CTundish_Inner_Fire" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_Inner_Fire" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_Inner_Fire" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_Inner_Fire" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_Inner_Fire" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

};

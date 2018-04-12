// �߼���CTundish_OT_Refra_Useͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_OT_Refra_Use :
	public CL3Object
{
public:
	CTundish_OT_Refra_Use(void);
	virtual ~CTundish_OT_Refra_Use(void);

	DECLARE_L3CLASS(CTundish_OT_Refra_Use,XGMESLogic\\TundishMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_OT_Refra_Use)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTundish_OT_Refra_Use" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CTundish_OT_Refra_Use" name="TundishID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_OT_Refra_Use" name="Cast_ID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_OT_Refra_Use" name="Stop_Cast_Reason" type="L3STRING">
	/// ͣ��ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Stop_Cast_Reason)

	/// <Property class="CTundish_OT_Refra_Use" name="Cover_Use_Case" type="L3STRING">
	/// ���Ǽ�ʹ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Cover_Use_Case)

	/// <Property class="CTundish_OT_Refra_Use" name="Protect_Use_Case" type="L3STRING">
	/// ������ʹ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Protect_Use_Case)

	/// <Property class="CTundish_OT_Refra_Use" name="Daub_Use_Case" type="L3STRING">
	/// ͿĨ(����)��ʹ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Daub_Use_Case)

	/// <Property class="CTundish_OT_Refra_Use" name="Tranq_Case" type="L3STRING">
	/// ������ʹ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Tranq_Case)

	/// <Property class="CTundish_OT_Refra_Use" name="Note" type="L3STRING">
	/// �����쳣˵��
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_OT_Refra_Use" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_OT_Refra_Use" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_OT_Refra_Use" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_OT_Refra_Use" name="TundishNO" type="L3STRING">
	/// �а����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNO)

	/// <Property class="CTundish_OT_Refra_Use" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};

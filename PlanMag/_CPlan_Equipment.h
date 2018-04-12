// �߼���CPlan_Equipmentͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CPlan_Equipment :
	public CL3Object
{
public:
	CPlan_Equipment(void);
	virtual ~CPlan_Equipment(void);

	DECLARE_L3CLASS(CPlan_Equipment,XGMESLogic\\PlanMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Equipment)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_Equipment" name="UnitID" type="L3STRING">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CPlan_Equipment" name="Unit_TypeID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Unit_TypeID)

	/// <Property class="CPlan_Equipment" name="EndStopTime_Aim" type="L3DATETIME">
	/// �ƻ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(EndStopTime_Aim)

	/// <Property class="CPlan_Equipment" name="BeginStopTime_Aim" type="L3DATETIME">
	/// ���޿�ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(BeginStopTime_Aim)

	/// <Property class="CPlan_Equipment" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CPlan_Equipment" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CPlan_Equipment" name="Operator" type="L3STRING">
	/// ��¼Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

};

// �߼���CEquip_Cooling_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Cooling_Log :
	public CL3Object
{
public:
	CEquip_Cooling_Log(void);
	virtual ~CEquip_Cooling_Log(void);

	DECLARE_L3CLASS(CEquip_Cooling_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Cooling_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Coil_Log" name="BOFID" type="L3STRING">
	/// ת¯
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CEquip_Coil_Log" name="Time_Chong_called" type="L3LONG">
	/// ����ˮλ�Ƴ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Chong_called)

	/// <Property class="CEquip_Coil_Log" name="Time_Experiment" type="L3LONG">
	/// ��ȫ���ֶ�����ʱ�䡡
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Experiment)

	/// <Property class="CEquip_Coil_Log" name="Reason_UnCleaning" type="L3STRING">
	/// δ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason_UnCleaning)

	/// <Property class="CEquip_Coil_Log" name="Problem_Inspection" type="L3STRING">
	/// Ѳ���豸����
	/// </Property>
	DECLARE_L3PROP_STRING(Problem_Inspection)

	/// <Property class="CEquip_Coil_Log" name="Check_Date" type="L3DATETIME">
	/// У׼����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Coil_Log" name="Create_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Coil_Log" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Coil_Log" name="Status" type="L3LONG">
	/// ״̬ 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};

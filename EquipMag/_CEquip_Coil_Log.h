// �߼���CEquip_Coil_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Coil_Log :
	public CL3Object
{
public:
	CEquip_Coil_Log(void);
	virtual ~CEquip_Coil_Log(void);

	DECLARE_L3CLASS(CEquip_Coil_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Coil_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Coil_Log" name="CCMID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Coil_Log" name="StrandNo" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Coil_Log" name="CoilNo" type="L3STRING">
	/// ��Ȧ��š�
	/// </Property>
	DECLARE_L3PROP_STRING(CoilNo)

	/// <Property class="CEquip_Coil_Log" name="Insulating" type="L3STRING">
	/// ��Եǿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Insulating)

	/// <Property class="CEquip_Coil_Log" name="Elec_Intensity_Std" type="L3STRING">
	/// ��ų�ǿ�ȱ�׼ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Elec_Intensity_Std )

	/// <Property class="CEquip_Coil_Log" name="Elec_Intensity_Act" type="L3STRING">
	/// ��ų�ǿ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Elec_Intensity_Act )

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

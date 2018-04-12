// �߼���CEquip_Mold_Arc_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Mold_Arc_Log :
	public CL3Object
{
public:
	CEquip_Mold_Arc_Log(void);
	virtual ~CEquip_Mold_Arc_Log(void);

	DECLARE_L3CLASS(CEquip_Mold_Arc_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Mold_Arc_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Mold_Arc_Log" name="CCMID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Mold_Arc_Log" name="StrandNo" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Mold_Arc_Log" name="MoldNo" type="L3STRING">
	/// �ᾧ�����
	/// </Property>
	DECLARE_L3PROP_STRING(MoldNo)

	/// <Property class="CEquip_Mold_Arc_Log" name="Arc_Out_Std" type="L3STRING">
	/// �⻡�Ի���׼
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_Out_Std)

	/// <Property class="CEquip_Mold_Arc_Log" name="Arc_Out_Act" type="L3STRING">
	/// �⻡�Ի�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_Out_Act)

	/// <Property class="CEquip_Mold_Arc_Log" name="Arc_Out_Std" type="L3STRING">
	/// �ϻ��Ի���׼
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_South_Std)

	/// <Property class="CEquip_Mold_Arc_Log" name="Arc_Out_Act" type="L3STRING">
	/// �ϻ��Ի�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_South_Act)

	/// <Property class="CEquip_Mold_Arc_Log" name="Check_Date" type="L3DATETIME">
	/// У׼����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Mold_Arc_Log" name="Create_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Mold_Arc_Log" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Mold_Arc_Log" name="Status" type="L3LONG">
	/// ״̬ 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};

// �߼���CEquip_Sect_Arc_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Sect_Arc_Log :
	public CL3Object
{
public:
	CEquip_Sect_Arc_Log(void);
	virtual ~CEquip_Sect_Arc_Log(void);

	DECLARE_L3CLASS(CEquip_Sect_Arc_Log,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Sect_Arc_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Sect_Arc_Log" name="CCMID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CEquip_Sect_Arc_Log" name="StrandNo" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CEquip_Sect_Arc_Log" name="SectNo" type="L3STRING">
	/// ���ζα��
	/// </Property>
	DECLARE_L3PROP_STRING(SectNo)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_1stSect_Std" type="L3STRING">
	/// һ�ζԻ���׼
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_1stSect_Std)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_1stSect_Act" type="L3STRING">
	/// һ�ζԻ�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_1stSect_Act)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_2ndSect_Std" type="L3STRING">
	/// ���ζԻ���׼
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_2ndSect_Std)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_2ndSect_Act" type="L3STRING">
	/// ���ζԻ�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_2ndSect_Act)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_3rdSect_Std" type="L3STRING">
	/// ���ζԻ���׼
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_3rdSect_Std)

	/// <Property class="CEquip_Sect_Arc_Log" name="Arc_3rdSect_Act" type="L3STRING">
	/// ���ζԻ�ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Arc_3rdSect_Act)

	/// <Property class="CEquip_Sect_Arc_Log" name="Check_Date" type="L3DATETIME">
	/// У׼����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CEquip_Sect_Arc_Log" name="Create_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)

	/// <Property class="CEquip_Sect_Arc_Log" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEquip_Sect_Arc_Log" name="Status" type="L3LONG">
	/// ״̬ 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)
};

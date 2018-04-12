// �߼���CBOF_Stack_Maintenanceͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_Stack_Maintenance :
	public CL3Object
{
public:
	CBOF_Stack_Maintenance(void);
	virtual ~CBOF_Stack_Maintenance(void);

	DECLARE_L3CLASS(CBOF_Stack_Maintenance,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Stack_Maintenance)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_Stack_Maintenance" name="ProductionDate" type="L3DATETIME">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProductionDate)

	/// <Property class="CBOF_Stack_Maintenance" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CBOF_Stack_Maintenance" name="Content" type="L3STRING">
	/// 
	/// ά������
	/// (1:����ֿ�;
	///  2:�¹�;
	///  3:������
	///  4:�����
	///  5:������
	///  6:������
	///  7:������
	///  8:��¯��
	///  9:�粹¯��
	///  10:�粹����
	///  11:����ֿ�
	///  12:��¯��)
	/// </Property>
	DECLARE_L3PROP_STRING(Content)

	/// <Property class="CBOF_Stack_Maintenance" name="Materiel" type="L3STRING">
	/// 
	/// ʹ������
	/// (1:�粹��;
	///  2:¯����;
	///  3:��Ͷ��)
	/// </Property>
	DECLARE_L3PROP_STRING(Materiel)

	/// <Property class="CBOF_Stack_Maintenance" name="Taphole_Vendor" type="L3STRING">
	/// ���ֿڳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Taphole_Vendor)

	/// <Property class="CBOF_Stack_Maintenance" name="Materiel_Vendor" type="L3STRING">
	/// ���ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Materiel_Vendor)

	/// <Property class="CBOF_Stack_Maintenance" name="Wastage" type="L3FLOAT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Wastage)

	/// <Property class="CBOF_Stack_Maintenance" name="BOFID" type="L3STRING">
	/// ¯����
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

};

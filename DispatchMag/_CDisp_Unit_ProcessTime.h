// �߼���CDisp_Unit_ProcessTimeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDisp_Unit_ProcessTime :
	public CL3Object
{
public:
	CDisp_Unit_ProcessTime(void);
	virtual ~CDisp_Unit_ProcessTime(void);

	DECLARE_L3CLASS(CDisp_Unit_ProcessTime,XGMESLogic\\DispatchMag, ObjectID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Unit_ProcessTime)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDisp_Unit_ProcessTime" name="ObjectID" type="L3STRING">
	/// ����ID
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)//ObjectID=ProductDate+UnitID+Team+ProcessType

	/// <Property class="CDisp_Unit_ProcessTime" name="ProductDate" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(ProductDate)

	/// <Property class="CDisp_Unit_ProcessTime" name="UnitID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CDisp_Unit_ProcessTime" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDisp_Unit_ProcessTime" name="ProcessType" type="L3STRING">
	/// ��ҵ����
	/// </Property>
	DECLARE_L3PROP_STRING(ProcessType)

	/// <Property class="CDisp_Unit_ProcessTime" name="ProcessTime" type="L3LONG">
	/// ��ҵʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessTime)

	/// <Property class="CDisp_Unit_ProcessTime" name="CreateTime" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

};

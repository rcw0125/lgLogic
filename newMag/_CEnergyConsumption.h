// �߼���CEnergyConsumptionͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEnergyConsumption :
	public CL3Object
{
public:
	CEnergyConsumption(void);
	virtual ~CEnergyConsumption(void);

	DECLARE_L3CLASS(CEnergyConsumption,XGMESLogic\\EnergyMag, ObjectID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergyConsumption)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEnergyConsumption" name="ObjectID" type="L3STRING">
	/// �����ʶ
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CEnergyConsumption" name="ProductionDate" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(ProductionDate) //�� yyyyMMdd ��ʽ�洢

	/// <Property class="CEnergyConsumption" name="TagName" type="L3STRING">
	/// ��ǩ��
	/// </Property>
	DECLARE_L3PROP_STRING(TagName)

	/// <Property class="CEnergyConsumption" name="TagValue" type="L3DOUBLE">
	/// ������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TagValue)

	/// <Property class="CEnergyConsumption" name="DayValue" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(DayValue)

	/// <Property class="CEnergyConsumption" name="MonthValue" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MonthValue)

	/// <Property class="CEnergyConsumption" name="CreateTime" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

	/// <Property class="CEnergyConsumption" name="ModifyTime" type="L3DATETIME">
	/// ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(ModifyTime)

	/// <Property class="CEnergyConsumption" name="Operator" type="L3STRING">
	/// ����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)
};

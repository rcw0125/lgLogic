// �߼���CDutyDefinitionͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDuty_Definition :
	public CL3Object
{
public:
	CDuty_Definition(void);
	virtual ~CDuty_Definition(void);

	DECLARE_L3CLASS(CDuty_Definition,XGMESLogic\\BOFMag, ObjectID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDuty_Definition)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDuty_Definition" name="ObjectID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CDuty_Definition" name="UnitID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)


	/// <Property class="CDuty_Definition" name="Team" type="L3STRING">
	/// 
	/// ���
	/// (1:��
	/// 2:��
	/// 3:��
	/// 4:��)
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDuty_Definition" name="HeadFurnace" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CDuty_Definition" name="Assistant" type="L3STRING">
	/// һ����
	/// </Property>
	DECLARE_L3PROP_STRING(Assistant)

	/// <Property class="CDuty_Definition" name="SecondHand" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(SecondHand)

};

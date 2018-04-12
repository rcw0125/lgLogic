// �߼���CDutyDefinitionͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDEP_Duty :
	public CL3Object
{
public:
	CDEP_Duty(void);
	virtual ~CDEP_Duty(void);

	DECLARE_L3CLASS(CDEP_Duty,XGMESLogic\\DePMag, ObjectID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDEP_Duty)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDEP_Duty" name="ObjectID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CDEP_Duty" name="UnitID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)


	/// <Property class="CDEP_Duty" name="Team" type="L3STRING">
	/// 
	/// ���
	/// (1:��
	/// 2:��
	/// 3:��
	/// 4:��)
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDEP_Duty" name="HeadFurnace" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CDEP_Duty" name="Assistant" type="L3STRING">
	/// һ����
	/// </Property>
	DECLARE_L3PROP_STRING(Assistant)

	/// <Property class="CDEP_Duty" name="SecondHand" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(SecondHand)

};

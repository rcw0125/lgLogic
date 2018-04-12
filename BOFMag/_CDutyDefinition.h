// �߼���CDutyDefinitionͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDutyDefinition :
	public CL3Object
{
public:
	CDutyDefinition(void);
	virtual ~CDutyDefinition(void);

	DECLARE_L3CLASS(CDutyDefinition,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDutyDefinition)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDutyDefinition" name="UnitID" type="L3SHORT">
	/// 
	/// ����(1:����¯
	///      2:ת¯
	///      3:LF¯
	///      4:RH¯
	///      5:����)
	/// 
	/// </Property>
	DECLARE_L3PROP_SHORT(UnitID)

	/// <Property class="CDutyDefinition" name="PlantID" type="L3SHORT">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_SHORT(PlantID)

	/// <Property class="CDutyDefinition" name="TeamID" type="L3SHORT">
	/// 
	/// ���
	/// (1:��
	/// 2:��
	/// 3:��
	/// 4:��)
	/// </Property>
	DECLARE_L3PROP_SHORT(TeamID)

	/// <Property class="CDutyDefinition" name="HeadFurnace" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeadFurnace)

	/// <Property class="CDutyDefinition" name="Assistant" type="L3STRING">
	/// һ����
	/// </Property>
	DECLARE_L3PROP_STRING(Assistant)

	/// <Property class="CDutyDefinition" name="SecondHand" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(SecondHand)

};

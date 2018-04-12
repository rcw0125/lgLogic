// �߼���CBase_Unit_Consumeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Unit_Consume :
	public CL3Object
{
public:
	CBase_Unit_Consume(void);
	virtual ~CBase_Unit_Consume(void);

	DECLARE_L3CLASS(CBase_Unit_Consume,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Unit_Consume)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Unit_Consume" name="SteelType" type="L3STRING">
	/// ��Ʒ���
	/// </Property>
	DECLARE_L3PROP_STRING(SteelType)

	/// <Property class="CBase_Unit_Consume" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CBase_Unit_Price" name="Ele_Code" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ele_Code)

	/// <Property class="CBase_Unit_Price" name="Ele_Des" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Ele_Des)

	/// <Property class="CBase_Unit_Consume" name="Unit_Consume" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Unit_Consume)

};

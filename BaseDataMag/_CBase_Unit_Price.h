// �߼���CBase_Unit_Priceͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Unit_Price :
	public CL3Object
{
public:
	CBase_Unit_Price(void);
	virtual ~CBase_Unit_Price(void);

	DECLARE_L3CLASS(CBase_Unit_Price,XGMESLogic\\BaseDataMag, Ele_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Unit_Price)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Unit_Price" name="Ele_Code" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ele_Code)

	/// <Property class="CBase_Unit_Price" name="Ele_Des" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Ele_Des)

	/// <Property class="CBase_Unit_Price" name="Ele_Price" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Ele_Price)

};

// �߼���CCost_Standard_Rateͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCost_Standard_Rate :
	public CL3Object
{
public:
	CCost_Standard_Rate(void);
	virtual ~CCost_Standard_Rate(void);

	DECLARE_L3CLASS(CCost_Standard_Rate,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCost_Standard_Rate)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCost_Standard_Rate" name="Cost_Item" type="L3STRING">
	/// �ɱ���Ŀ
	/// </Property>
	DECLARE_L3PROP_STRING(Cost_Item)

	/// <Property class="CCost_Standard_Rate" name="Cost_Center" type="L3STRING">
	/// �ɱ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Cost_Center)

	/// <Property class="CCost_Standard_Rate" name="Pro_type" type="L3STRING">
	/// ��Ʒ��
	/// </Property>
	DECLARE_L3PROP_STRING(Pro_type)

	/// <Property class="CCost_Standard_Rate" name="Standard_Cost" type="L3FLOAT">
	/// ��׼����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Standard_Cost)

};

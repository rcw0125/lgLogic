// �߼���CCost_Medium_Consume_Standardͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCost_Medium_Consume_Std :
	public CL3Object
{
public:
	CCost_Medium_Consume_Std(void);
	virtual ~CCost_Medium_Consume_Std(void);

	DECLARE_L3CLASS(CCost_Medium_Consume_Std,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCost_Medium_Consume_Std)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCost_Medium_Consume_Std" name="Medium" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Medium)

	/// <Property class="CCost_Medium_Consume_Std" name="Cost_Center" type="L3STRING">
	/// �ɱ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Cost_Center)

	/// <Property class="CCost_Medium_Consume_Std" name="Stock_Type" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Stock_Type)

	/// <Property class="CCost_Medium_Consume_Std" name="Standard_Cost" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Standard_Cost)

};

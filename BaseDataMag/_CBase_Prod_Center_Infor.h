// �߼���Produce_Center_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Prod_Center_Infor :
	public CL3Object
{
public:
	CBase_Prod_Center_Infor(void);
	virtual ~CBase_Prod_Center_Infor(void);

	DECLARE_L3CLASS(CBase_Prod_Center_Infor,XGMESLogic\\BaseDataMag, Pk_Center)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Prod_Center_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	
	/// <Property class="Produce_Center_Infor" name="Pk_Center" type="L3STRING">
	/// ������������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Center)

	/// <Property class="Produce_Center_Infor" name="Center_Name" type="L3STRING">
	/// ������������
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Name)

	/// <Property class="Produce_Center_Infor" name="Center_Code" type="L3STRING">
	/// �������ı���
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Code)

	/// <Property class="Produce_Center_Infor" name="Pk_Department" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Department)

};

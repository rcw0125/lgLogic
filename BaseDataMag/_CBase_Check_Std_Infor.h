// �߼���CBase_Check_Std_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Check_Std_Infor :
	public CL3Object
{
public:
	CBase_Check_Std_Infor(void);
	virtual ~CBase_Check_Std_Infor(void);

	DECLARE_L3CLASS(CBase_Check_Std_Infor,XGMESLogic\\BaseDataMag, CheckStandard_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Check_Std_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

    /// <Property class="CBase_Check_Std_Infor" name="CheckStandard_ID" type="L3LONG">
	/// �����׼����
	/// </Property>
	DECLARE_L3PROP_STRING(CheckStandard_ID)

	/// <Property class="CBase_Check_Std_Infor" name="Pk_Check_Std" type="L3STRING">
	/// �����׼����
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Check_Std)

	
	/// <Property class="CBase_Check_Std_Infor" name="Check_Std_Code" type="L3STRING">
	/// �����׼����
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Std_Code)

	/// <Property class="CBase_Check_Std_Infor" name="Check_Std_Name" type="L3STRING">
	/// �����׼����
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Std_Name)

	/// <Property class="CBase_Check_Std_Infor" name="Check_Item_Id" type="L3STRING">
	/// ������Ŀ����
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Item_Id)

	/// <Property class="CBase_Check_Std_Infor" name="bcritical" type="L3STRING">
	/// �Ƿ�ؼ���Ŀ
	/// </Property>
	DECLARE_L3PROP_STRING(bcritical)

	/// <Property class="CBase_Check_Std_Infor" name="Std_Value" type="L3STRING">
	/// ��׼ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Std_Value)

	/// <Property class="CBase_Check_Std_Infor" name="Std_Value_Type" type="L3STRING">
	/// ��׼ֵ����
	/// </Property>
	DECLARE_L3PROP_STRING(Std_Value_Type)

};

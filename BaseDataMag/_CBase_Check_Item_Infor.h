// �߼���CBase_Check_Item_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Check_Item_Infor :
	public CL3Object
{
public:
	CBase_Check_Item_Infor(void);
	virtual ~CBase_Check_Item_Infor(void);

	DECLARE_L3CLASS(CBase_Check_Item_Infor,XGMESLogic\\BaseDataMag, Pk_Check_Item)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Check_Item_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Check_Item_Infor" name="Pk_Check_Item" type="L3STRING">
	/// ������Ŀ����
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Check_Item)

	/// <Property class="CBase_Check_Item_Infor" name="Check_Item_Code" type="L3STRING">
	/// ������Ŀ����
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Item_Code)

	/// <Property class="CBase_Check_Item_Infor" name="Check_Item_Name" type="L3STRING">
	/// ������Ŀ����
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Item_Name)

	/// <Property class="CBase_Check_Item_Infor" name="Check_Unit_Id" type="L3STRING">
	/// ��Ŀ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(Check_Unit_Id)

};

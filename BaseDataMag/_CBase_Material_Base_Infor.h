// �߼���CBase_Material_Base_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Material_Base_Infor :
	public CL3Object
{
public:
	CBase_Material_Base_Infor(void);
	virtual ~CBase_Material_Base_Infor(void);

	DECLARE_L3CLASS(CBase_Material_Base_Infor,XGMESLogic\\BaseDataMag, Pk_Material_Bas)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Material_Base_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Material_Base_Infor" name="Pk_Material_Bas" type="L3STRING">
	/// ���ϱ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Material_Bas)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Code" type="L3STRING">
	/// ���ϱ���
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Code)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Name" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Name)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Spec" type="L3STRING">
	/// ���Ϲ��
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Spec)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Type" type="L3STRING">
	/// �����ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Type)

	/// <Property class="CBase_Material_Base_Infor" name="Material_Type" type="L3STRING">
	/// ���Ϸ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Material_Class)

	/// <Property class="CBase_Material_Base_Infor" name="Pk_Unit" type="L3STRING">
	/// ������λ����
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Unit)

	/// <Property class="CBase_Material_Base_Infor" name="Route" type="L3STRING">
	/// ����·��
	/// </Property>2009-03-11
	DECLARE_L3PROP_STRING(Route)

};

// �߼���CBase_Material_Class_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Material_Class_Infor :
	public CL3Object
{
public:
	CBase_Material_Class_Infor(void);
	virtual ~CBase_Material_Class_Infor(void);

	DECLARE_L3CLASS(CBase_Material_Class_Infor,XGMESLogic\\BaseDataMag, Pk_Material_Class)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Material_Class_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Material_Class_Infor" name="Pk_Material_Class" type="L3STRING">
	/// ���Ϸ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Material_Class)

	/// <Property class="CBase_Material_Class_Infor" name="Material_Class_Code" type="L3STRING">
	/// ���Ϸ������
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Class_Code)

	/// <Property class="CBase_Material_Class_Infor" name="Material_Class_Name" type="L3STRING">
	/// ���Ϸ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Class_Name)

	/// <Property class="CBase_Material_Class_Infor" name="End_Flag" type="L3STRING">
	/// �Ƿ�ĩ������
	/// </Property>
	DECLARE_L3PROP_STRING(End_Flag)

};

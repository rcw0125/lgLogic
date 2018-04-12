// �߼���CXGMES_All_Codeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_All_Code :
	public CL3Object
{
public:
	CBase_All_Code(void);
	virtual ~CBase_All_Code(void);

	DECLARE_L3CLASS(CBase_All_Code,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_All_Code)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CXGMES_All_Code" name="Code" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Code)

	/// <Property class="CXGMES_All_Code" name="Code_Des" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Des)

	/// <Property class="CXGMES_All_Code" name="Code_Group" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Group)

	/// <Property class="CXGMES_All_Code" name="Code_Group_Des" type="L3STRING">
	/// �����������
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Group_Des)

	/// <Property class="CXGMES_All_Code" name="Code_Val_Str" type="L3STRING">
	/// ���봮ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Val_Str)

	/// <Property class="CXGMES_All_Code" name="Code_Val_Long" type="L3LONG">
	/// ��������ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Code_Val_Long)

	/// <Property class="CXGMES_All_Code" name="Code_Val_Double" type="L3DOUBLE">
	/// ���븡��ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Code_Val_Double)

	/// <Property class="CXGMES_All_Code" name="Code_Function_Group" type="L3STRING">
	/// ���빦�ܷ���
	/// </Property>
	DECLARE_L3PROP_STRING(Code_Function_Group)

	/// <Property class="CXGMES_All_Code" name="NC_Code" type="L3STRING">
	/// NC����
	/// </Property>
	DECLARE_L3PROP_STRING(NC_Code)

};

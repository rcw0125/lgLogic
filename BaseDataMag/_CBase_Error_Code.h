// �߼���CBase_Error_Codeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Error_Code :
	public CL3Object
{
public:
	CBase_Error_Code(void);
	virtual ~CBase_Error_Code(void);

	DECLARE_L3CLASS(CBase_Error_Code,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Error_Code)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Error_Code" name="Error_Code" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Error_Code)

	/// <Property class="CBase_Error_Code" name="Error_Des" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Error_Des)

	/// <Property class="CBase_Error_Code" name="Owner" type="L3STRING">
	/// ����Uri
	/// </Property>
	DECLARE_L3PROP_STRING(Owner)

	/// <Property class="CBase_Error_Code" name="Owner_Des" type="L3STRING">
	/// ����Uri����
	/// </Property>
	DECLARE_L3PROP_STRING(Owner_Des)

	/// <Property class="CBase_Error_Code" name="Error_Val_Long" type="L3STRING">
	/// ����ֵ
	/// </Property>
	DECLARE_L3PROP_STRING(Error_Val_Long)

};

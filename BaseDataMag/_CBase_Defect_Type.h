// �߼���CBase_Defect_Typeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Defect_Type :
	public CL3Object
{
public:
	CBase_Defect_Type(void);
	virtual ~CBase_Defect_Type(void);

	DECLARE_L3CLASS(CBase_Defect_Type,XGMESLogic\\BaseDataMag, Pk_Defec_Type)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Defect_Type)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Defect_Type" name="Pk_Defec_Type" type="L3STRING">
	/// ���ϸ���������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Defec_Type)

	/// <Property class="CBase_Defect_Type" name="Defect_Type_Code" type="L3STRING">
	/// ���ϸ����ͱ���
	/// </Property>
	DECLARE_L3PROP_STRING(Defect_Type_Code)

	/// <Property class="CBase_Defect_Type" name="Defect_Type_Name" type="L3STRING">
	/// ���ϸ���������
	/// </Property>
	DECLARE_L3PROP_STRING(Defect_Type_Name)

};

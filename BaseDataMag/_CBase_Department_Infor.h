// �߼���Department_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Department_Infor :
	public CL3Object
{
public:
	CBase_Department_Infor(void);
	virtual ~CBase_Department_Infor(void);

	DECLARE_L3CLASS(CBase_Department_Infor,XGMESLogic\\BaseDataMag, Pk_Department)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Department_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="Department_Infor" name="Pk_Department" type="L3STRING">
	/// ���ŵ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Department)

	/// <Property class="Department_Infor" name="Department_Name" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Department_Name)

	/// <Property class="Department_Infor" name="Department_Code" type="L3STRING">
	/// ���ű���
	/// </Property>
	DECLARE_L3PROP_STRING(Department_Code)

};

// �߼���CBase_Excep_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Excep_Infor :
	public CL3Object
{
public:
	CBase_Excep_Infor(void);
	virtual ~CBase_Excep_Infor(void);

	DECLARE_L3CLASS(CBase_Excep_Infor,XGMESLogic\\BaseDataMag, Pk_Exception)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Excep_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Excep_Infor" name="Pk_Exception" type="L3STRING">
	/// �쳣��ת��Ŀ����
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Exception)

	/// <Property class="CBase_Excep_Infor" name="Exception_Code" type="L3STRING">
	/// ��Ŀ����
	/// </Property>
	DECLARE_L3PROP_STRING(Exception_Code)

	/// <Property class="CBase_Excep_Infor" name="Exception_Name" type="L3STRING">
	/// ��Ŀ����
	/// </Property>
	DECLARE_L3PROP_STRING(Exception_Name)

};

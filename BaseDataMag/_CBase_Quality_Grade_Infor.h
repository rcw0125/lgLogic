// �߼���Quality_Grade_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Quality_Grade_Infor :
	public CL3Object
{
public:
	CBase_Quality_Grade_Infor(void);
	virtual ~CBase_Quality_Grade_Infor(void);

	DECLARE_L3CLASS(CBase_Quality_Grade_Infor,XGMESLogic\\BaseDataMag, Pk_Qua_Grade)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Quality_Grade_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="Quality_Grade_Infor" name="Pk_Qua_Grade" type="L3STRING">
	/// �����ȼ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Qua_Grade)

	/// <Property class="Quality_Grade_Infor" name="Qua_Grade_Name" type="L3STRING">
	/// �����ȼ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Qua_Grade_Name)

	/// <Property class="Quality_Grade_Infor" name="Qua_Grade_Code" type="L3STRING">
	/// �����ȼ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Qua_Grade_Code)

	/// <Property class="Quality_Grade_Infor" name="Qualified" type="L3STRING">
	/// �Ƿ�ϸ�
	/// </Property>
	DECLARE_L3PROP_STRING(Qualified)

	/// <Property class="Quality_Grade_Infor" name="Pk_Qua_Grade_Group" type="L3STRING">
	/// �����ȼ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Qua_Grade_Group)

};

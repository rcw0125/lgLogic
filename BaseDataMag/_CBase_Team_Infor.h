// �߼���Team_Base_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Team_Infor :
	public CL3Object
{
public:
	CBase_Team_Infor(void);
	virtual ~CBase_Team_Infor(void);

	DECLARE_L3CLASS(CBase_Team_Infor,XGMESLogic\\BaseDataMag, Pk_Team)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(Team_Base_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="Team_Base_Infor" name="Pk_Team" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Team)

	/// <Property class="Team_Base_Infor" name="Team_Code" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Team_Code)

	/// <Property class="Team_Base_Infor" name="Team_Name" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Team_Name)

	/// <Property class="Team_Base_Infor" name="Pk_Center" type="L3STRING">
	/// ������������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Center)

	/// <Property class="Team_Base_Infor" name="Pk_Department" type="L3STRING">
	/// ���ŵ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Department)

};

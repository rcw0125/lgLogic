//add by hyh 2012-04-12 
//�����û�Ҫ��ʱ�����빦��

// �߼���CBase_UserPwd_Lockͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_UserPwd_Lock :
	public CL3Object
{
public:
	CBase_UserPwd_Lock(void);
	virtual ~CBase_UserPwd_Lock(void);

	DECLARE_L3CLASS(CBase_UserPwd_Lock,XGMESLogic\\BaseDataMag,userId)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_UserPwd_Lock)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_UserPwd_Lock" name="userId" type="L3STRING">
	/// �û���
	/// </Property>
	DECLARE_L3PROP_STRING(userId)

	/// <Property class="CBase_UserPwd_Lock" name="passWord" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(passWord)

	/// <Property class="CBase_UserPwd_Lock" name="lastModTime" type="L3DATETIME">
	/// �ϴ��޸�����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(lastModTime)

	/// <Property class="CBase_UserPwd_Lock" name="temp" type="L3STRING">
	/// �����ֶ�
	/// </Property>
	DECLARE_L3PROP_STRING(temp)

};

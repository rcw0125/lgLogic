// �߼���CBase_UserPwd_Lock_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_UserPwd_Lock_Mag :
	public CL3Object
{
public:
	CBase_UserPwd_Lock_Mag(void);
	virtual ~CBase_UserPwd_Lock_Mag(void);

	DECLARE_L3CLASS(CBase_UserPwd_Lock_Mag,XGMESLogic\\BaseDataMag,Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_UserPwd_Lock_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CBase_UserPwd_Lock_Mag" name="GetUserLastUpdTime" type="L3STRING">
	/// ��ȡ�û��ϴ��޸�����ʱ��
	/// <Param name="userId" type="L3STRING">�û���</Param>
	/// <Param name="passWord" type="L3STRING">����</Param>
	/// </Method>
	L3STRING GetUserLastUpdTime(L3STRING userId, L3STRING passWord);
	/// <Method class="CBase_UserPwd_Lock_Mag" name="UpdPassWord" type="L3SHORT">
	/// ��¼�û��޸�������Ϣ
	/// <Param name="userId" type="L3STRING"></Param>
	/// <Param name="passWord" type="L3STRING"></Param>
	/// </Method>
	L3SHORT UpdPassWord(L3STRING userId, L3STRING passWord);
};

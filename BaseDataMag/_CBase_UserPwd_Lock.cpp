//add by hyh 2012-04-12 
//�����û�Ҫ��ʱ�����빦��

// �߼���CBase_UserPwd_LockԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_UserPwd_Lock.h"

IMPLEMENT_L3CLASS(CBase_UserPwd_Lock,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_UserPwd_Lock,CL3Object)
	L3PROP_STRING(userId)
	L3PROP_STRING(passWord)
	L3PROP_DATETIME(lastModTime)
	L3PROP_STRING(temp)
END_L3PROPTABLE(CBase_UserPwd_Lock)

BEGIN_L3METHODMAP(CBase_UserPwd_Lock,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_UserPwd_Lock,CL3Object)
END_L3EVENTSINK_MAP(CBase_UserPwd_Lock)

CBase_UserPwd_Lock::CBase_UserPwd_Lock(void)
{
}

CBase_UserPwd_Lock::~CBase_UserPwd_Lock(void)
{
}

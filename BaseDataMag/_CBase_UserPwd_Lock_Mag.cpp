//add by hyh 2012-04-12 
//�����û�Ҫ��ʱ�����빦��

// �߼���CBase_UserPwd_Lock_MagԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_UserPwd_Lock_Mag.h"

IMPLEMENT_L3CLASS(CBase_UserPwd_Lock_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_UserPwd_Lock_Mag,CL3Object)
END_L3PROPTABLE(CBase_UserPwd_Lock_Mag)

BEGIN_L3METHODMAP(CBase_UserPwd_Lock_Mag,CL3Object)
	L3_METHOD(CBase_UserPwd_Lock_Mag,"GetUserLastUpdTime",0,GetUserLastUpdTime,L3VT_STRING,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CBase_UserPwd_Lock_Mag,"UpdPassWord",0,UpdPassWord,L3VT_SHORT,L3VTS_STRING L3VTS_STRING)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_UserPwd_Lock_Mag,CL3Object)
END_L3EVENTSINK_MAP(CBase_UserPwd_Lock_Mag)

CBase_UserPwd_Lock_Mag::CBase_UserPwd_Lock_Mag(void)
{
}

CBase_UserPwd_Lock_Mag::~CBase_UserPwd_Lock_Mag(void)
{
}

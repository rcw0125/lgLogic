//add by hyh 2012-04-12 
//用于用户要求定时锁密码功能

// 逻辑类CBase_UserPwd_Lock源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

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

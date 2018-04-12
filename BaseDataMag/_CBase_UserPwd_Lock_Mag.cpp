//add by hyh 2012-04-12 
//用于用户要求定时锁密码功能

// 逻辑类CBase_UserPwd_Lock_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

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

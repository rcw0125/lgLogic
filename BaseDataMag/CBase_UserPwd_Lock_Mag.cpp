//add by hyh 2012-04-12 
//用于用户要求定时锁密码功能
// 逻辑类CBase_UserPwd_Lock_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CBase_UserPwd_Lock_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CBase_UserPwd_Lock_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CBase_UserPwd_Lock_Mag.h"

//当对象被装载到系统中时，被调用
void CBase_UserPwd_Lock_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CBase_UserPwd_Lock_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

//
//

/// <Method class="CBase_UserPwd_Lock_Mag" name="GetUserLastUpdTime" type="L3STRING">
/// 获取用户上次修改密码时间
/// <Param name="userId" type="L3STRING">用户名</Param>
/// <Param name="passWord" type="L3STRING">密码</Param>
/// </Method>
L3STRING CBase_UserPwd_Lock_Mag::GetUserLastUpdTime(L3STRING userId, L3STRING passWord)
{
	CString csId=String_BSTR2TChar(userId);//用户名
	CString csPwd=String_BSTR2TChar(passWord);//密码
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString csCurDate = curTime.Format(_T("%Y-%m-%d %H:%M:%S"));

	//CString csTemp = _T(" select to_char(LASTMODTIME,'yyyy-MM-dd HH-mm-ss') from %s where userID ='%s' ");
	CString csTemp = _T(" select  LASTMODTIME from %s where userID ='%s' ");
	CString csSQL;
	csSQL.Format(csTemp,UserPwd_Lock_URI,csId);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return csCurDate.AllocSysString();
	if(rs.GetRowCount()<1)
		UpdPassWord(csId.AllocSysString(),csPwd.AllocSysString());
	else
	{
		rs.MoveFirst();
		CL3Variant vatDate=rs.GetFieldByName(_T("LASTMODTIME"));
		COleDateTime dt=COleDateTime(vatDate.ToDateTime());

		CString csdd=dt.Format(_T("%Y-%m-%d %H:%M:%S"));
		return csdd.AllocSysString();
	}
	return csCurDate.AllocSysString();
}

/// <Method class="CBase_UserPwd_Lock_Mag" name="UpdPassWord" type="L3SHORT">
/// 记录用户修改密码信息
/// <Param name="userId" type="L3STRING"></Param>
/// <Param name="passWord" type="L3STRING"></Param>
/// </Method>
L3SHORT CBase_UserPwd_Lock_Mag::UpdPassWord(L3STRING userId, L3STRING passWord)
{
	//查询是否存在此用户，不存在则新增，否则修改
	CString csId=String_BSTR2TChar(userId);//用户名
	//CString csPwd=String_BSTR2TChar(passWord);//密码
	CString csPwd=_T("******");
	CString csTemp = _T(" select * from %s where userId ='%s' ");
	CString csSQL;
	csSQL.Format(csTemp,UserPwd_Lock_URI,csId);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return 1;
	//if(rs.IsNull)
	//	return 1;
	//建一个空的表
	CL3RecordSetWrap rsUserPwdLock;
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	if(!CreateClassPropSet(UserPwd_Lock_URI,rsUserPwdLock))
		return 1;
	rsUserPwdLock.AppendRecord();  
	rsUserPwdLock.SetFieldByName(_T("userID"),CL3Variant(csId));
	rsUserPwdLock.SetFieldByName(_T("passWord"),CL3Variant(csPwd));
	rsUserPwdLock.SetFieldByName(_T("lastModTime"),CL3Variant(curTime));

	if (rs.GetRowCount()> 0)//有，则修改密码和时间  
	{
		if(SetObjPropValues(UserPwd_Lock_URI + CString(_T("\\")) + userId,rsUserPwdLock)==1)
			return 0;
	}
	else//无，则新增
	{
		if(CreateNewObjects(UserPwd_Lock_URI,rsUserPwdLock) < rsUserPwdLock.GetRowCount())        //创建指定类的多个对象
			return 0;
	}
}

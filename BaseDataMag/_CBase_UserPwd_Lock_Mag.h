// 逻辑类CBase_UserPwd_Lock_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
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

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CBase_UserPwd_Lock_Mag" name="GetUserLastUpdTime" type="L3STRING">
	/// 获取用户上次修改密码时间
	/// <Param name="userId" type="L3STRING">用户名</Param>
	/// <Param name="passWord" type="L3STRING">密码</Param>
	/// </Method>
	L3STRING GetUserLastUpdTime(L3STRING userId, L3STRING passWord);
	/// <Method class="CBase_UserPwd_Lock_Mag" name="UpdPassWord" type="L3SHORT">
	/// 记录用户修改密码信息
	/// <Param name="userId" type="L3STRING"></Param>
	/// <Param name="passWord" type="L3STRING"></Param>
	/// </Method>
	L3SHORT UpdPassWord(L3STRING userId, L3STRING passWord);
};

//add by hyh 2012-04-12 
//用于用户要求定时锁密码功能

// 逻辑类CBase_UserPwd_Lock头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
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

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_UserPwd_Lock" name="userId" type="L3STRING">
	/// 用户名
	/// </Property>
	DECLARE_L3PROP_STRING(userId)

	/// <Property class="CBase_UserPwd_Lock" name="passWord" type="L3STRING">
	/// 密码
	/// </Property>
	DECLARE_L3PROP_STRING(passWord)

	/// <Property class="CBase_UserPwd_Lock" name="lastModTime" type="L3DATETIME">
	/// 上次修改密码时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(lastModTime)

	/// <Property class="CBase_UserPwd_Lock" name="temp" type="L3STRING">
	/// 备用字段
	/// </Property>
	DECLARE_L3PROP_STRING(temp)

};

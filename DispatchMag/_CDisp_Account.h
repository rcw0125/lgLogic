// 逻辑类CDisp_Account头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDisp_Account :
	public CL3Object
{
public:
	CDisp_Account(void);
	virtual ~CDisp_Account(void);

	DECLARE_L3CLASS(CDisp_Account,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Account)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDisp_Account" name="ProductDate" type="L3STRING">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_STRING(ProductDate)

	/// <Property class="CDisp_Account" name="UnitID" type="L3STRING">
	/// 机组
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CDisp_Account" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDisp_Account" name="AccountType" type="L3STRING">
	/// 台帐类型
	/// </Property>
	DECLARE_L3PROP_STRING(AccountType)

	/// <Property class="CDisp_Account" name="AccountCount" type="L3LONG">
	/// 台帐计数
	/// </Property>
	DECLARE_L3PROP_LONG(AccountCount)

	/// <Property class="CDisp_Account" name="AccountReason" type="L3STRING">
	/// 原因
	/// </Property>
	DECLARE_L3PROP_STRING(AccountReason)

	/// <Property class="CDisp_Account" name="Responsibility_Organ" type="L3STRING">
	/// 责任单位
	/// </Property>
	DECLARE_L3PROP_STRING(Responsibility_Organ)

	/// <Property class="CDisp_Account" name="CreateTime" type="L3DATETIME">
	/// 创建时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

	/// <Property class="CDisp_Account" name="AccountAmount" type="L3DOUBLE">
	/// 台帐数量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(AccountAmount)

};

// 逻辑类CDisp_Exceptional头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDisp_Exceptional :
	public CL3Object
{
public:
	CDisp_Exceptional(void);
	virtual ~CDisp_Exceptional(void);

	DECLARE_L3CLASS(CDisp_Exceptional,XGMESLogic\\DispatchMag, IDObject)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Exceptional)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDisp_Exceptional" name="IDObject" type="L3STRING">
	/// ID标识=日期+工位+班次
	/// </Property>
	DECLARE_L3PROP_STRING(IDObject)

	/// <Property class="CDisp_Exceptional" name="CreateDate" type="L3STRING">
	/// 日期[yyyyMMdd]
	/// </Property>
	DECLARE_L3PROP_STRING(CreateDate)

	/// <Property class="CDisp_Exceptional" name="UnitID" type="L3STRING">
	/// 工作中心
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CDisp_Exceptional" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDisp_Exceptional" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDisp_Exceptional" name="CreateTime" type="L3STRING">
	/// 日期
	/// </Property>
	DECLARE_L3PROP_STRING(CreateTime)

	/// <Property class="CDisp_Exceptional" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	//2009-04-09
	/// <Property class="CDisp_Exceptional" name="SendFlag" type="L3LONG">
	/// 上传标志 0:未上传;1:已上传
	/// </Property>
	DECLARE_L3PROP_LONG(SendFlag)

};

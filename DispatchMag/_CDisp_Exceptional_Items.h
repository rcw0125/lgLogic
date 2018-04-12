// 逻辑类CDisp_Exceptional_Items头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDisp_Exceptional_Items :
	public CL3Object
{
public:
	CDisp_Exceptional_Items(void);
	virtual ~CDisp_Exceptional_Items(void);

	DECLARE_L3CLASS(CDisp_Exceptional_Items,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Exceptional_Items)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDisp_Exceptional_Items" name="IDObject" type="L3STRING">
	/// ID标识=日期+工位+班次
	/// </Property>
	DECLARE_L3PROP_STRING(IDObject)

	/// <Property class="CDisp_Exceptional_Items" name="Items" type="L3STRING">
	/// 异常项目
	/// </Property>
	DECLARE_L3PROP_STRING(Items)

	/// <Property class="CDisp_Exceptional_Items" name="BeginTime" type="L3STRING">
	/// 开始时刻
	/// </Property>
	DECLARE_L3PROP_STRING(BeginTime)

	/// <Property class="CDisp_Exceptional_Items" name="EndTime" type="L3STRING">
	/// 结束时刻
	/// </Property>
	DECLARE_L3PROP_STRING(EndTime)

	/// <Property class="CDisp_Exceptional_Items" name="TimeSpan" type="L3LONG">
	/// 时间间隔[分钟]
	/// </Property>
	DECLARE_L3PROP_LONG(TimeSpan)

	/// <Property class="CDisp_Exceptional_Items" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CDisp_Exceptional_Items" name="CreateTime" type="L3STRING">
	/// 日期
	/// </Property>
	DECLARE_L3PROP_STRING(CreateTime)

	/// <Property class="CDisp_Exceptional_Items" name="UnitID" type="L3STRING">
	/// 工作中心 2009-04-10 liuzhiqiang
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)


};

// 逻辑类CTundish_OT_Install头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_OT_Install :
	public CL3Object
{
public:
	CTundish_OT_Install(void);
	virtual ~CTundish_OT_Install(void);

	DECLARE_L3CLASS(CTundish_OT_Install,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_OT_Install)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTundish_OT_Install" name="TundishID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_OT_Install" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_OT_Install" name="Daub_Fac" type="L3STRING">
	/// 涂料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Daub_Fac)

	/// <Property class="CTundish_OT_Install" name="Fra_Case" type="L3STRING">
	/// 机构情况
	/// </Property>
	DECLARE_L3PROP_STRING(Fra_Case)

	/// <Property class="CTundish_OT_Install" name="Slip_Blo_Fac" type="L3STRING">
	/// 滑块厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Slip_Blo_Fac)

	/// <Property class="CTundish_OT_Install" name="Gap_Fac" type="L3STRING">
	/// 上水口厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Gap_Fac)

	/// <Property class="CTundish_OT_Install" name="Install_Per" type="L3STRING">
	/// 安装人
	/// </Property>
	DECLARE_L3PROP_STRING(Install_Per)

	/// <Property class="CTundish_OT_Install" name="Install_Time" type="L3DATETIME">
	/// 安装日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Time)

	/// <Property class="CTundish_OT_Install" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)
	
	/// <Property class="CTundish_OT_Install" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};

// 逻辑类CMIF_Feed_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "UnitFeedingLog.h"

class CMIF_Feed_Log :
	public UnitFeedingLog
{
public:
	CMIF_Feed_Log(void);
	virtual ~CMIF_Feed_Log(void);

	DECLARE_L3CLASS(CMIF_Feed_Log,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Feed_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CMIF_Feed_Log" name="MIFID" type="L3STRING">
	/// 混铁炉号
	/// </Property>
	DECLARE_L3PROP_STRING(MIFID)

	/// <Property class="CMIF_Feed_Log" name="BFID" type="L3STRING">
	/// 高炉炉号
	/// </Property>
	DECLARE_L3PROP_STRING(BFID)

	/// <Property class="CMIF_Feed_Log" name="TAP_No" type="L3STRING">
	/// 铁次号
	/// </Property>
	DECLARE_L3PROP_STRING(TAP_No)

	/// <Property class="CMIF_Feed_Log" name="TPC_No" type="L3STRING">
	/// 罐号
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

};

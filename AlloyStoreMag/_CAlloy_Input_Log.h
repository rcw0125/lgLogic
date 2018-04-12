// 逻辑类CAlloy_Input_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialInputLog.h"

class CAlloy_Input_Log :
	public MaterialInputLog
{
public:
	CAlloy_Input_Log(void);
	virtual ~CAlloy_Input_Log(void);

	DECLARE_L3CLASS(CAlloy_Input_Log,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Input_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Input_Log" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CAlloy_Input_Log" name="Alloy_Code" type="L3STRING">
	/// 合金编码
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_Input_Log" name="Alloy_Confirm_Man" type="L3STRING">
	/// 炉前确认
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Confirm_Man)

	/// <Property class="CAlloy_Input_Log" name="Shop_Confirm_Man" type="L3STRING">
	/// 车间确认
	/// </Property>
	DECLARE_L3PROP_STRING(Shop_Confirm_Man)

};

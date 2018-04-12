// 逻辑类CAlloy_Output_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialOutputLog.h"

class CAlloy_Output_Log :
	public MaterialOutputLog
{
public:
	CAlloy_Output_Log(void);
	virtual ~CAlloy_Output_Log(void);

	DECLARE_L3CLASS(CAlloy_Output_Log,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Output_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Output_Log" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CAlloy_Output_Log" name="Alloy_Code" type="L3STRING">
	/// 合金代码
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_Output_Log" name="UnitID" type="L3STRING">
	/// 机组
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

};

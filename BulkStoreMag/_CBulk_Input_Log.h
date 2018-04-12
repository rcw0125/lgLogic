// 逻辑类CBulk_Input_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialInputLog.h"

class CBulk_Input_Log :
	public MaterialInputLog
{
public:
	CBulk_Input_Log(void);
	virtual ~CBulk_Input_Log(void);

	DECLARE_L3CLASS(CBulk_Input_Log,XGMESLogic\\BulkStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Input_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBulk_Input_Log" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CBulk_Input_Log" name="Bulk_Code" type="L3STRING">
	/// 散状料代码
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Input_Log" name="Bulk_Confirm_Man" type="L3STRING">
	/// 炉前确认
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Confirm_Man)

	/// <Property class="CBulk_Input_Log" name="Shop_Confirm_Man" type="L3STRING">
	/// 车间确认
	/// </Property>
	DECLARE_L3PROP_STRING(Shop_Confirm_Man)

};

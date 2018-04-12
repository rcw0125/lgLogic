// 逻辑类CBulk_Trans_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBulk_Trans_Log :
	public CL3Object
{
public:
	CBulk_Trans_Log(void);
	virtual ~CBulk_Trans_Log(void);

	DECLARE_L3CLASS(CBulk_Trans_Log,XGMESLogic\\BulkStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Trans_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBulk_Trans_Log" name="SourceID" type="L3STRING">
	/// 原料仓
	/// </Property>
	DECLARE_L3PROP_STRING(SourceID)

	/// <Property class="CBulk_Trans_Log" name="TargetID" type="L3STRING">
	/// 新料仓
	/// </Property>
	DECLARE_L3PROP_STRING(TargetID)

	/// <Property class="CBulk_Trans_Log" name="MaterialID" type="L3STRING">
	/// 材料号
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID)

	/// <Property class="CBulk_Trans_Log" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CBulk_Trans_Log" name="Bulk_Code" type="L3STRING">
	/// 编码
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Trans_Log" name="Amount" type="L3DOUBLE">
	/// 转移量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	/// <Property class="CBulk_Trans_Log" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CBulk_Trans_Log" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CBulk_Trans_Log" name="Trans_Date" type="L3DATETIME">
	/// 时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Trans_Date)

	/// <Property class="CBulk_Trans_Log" name="Operator" type="L3STRING">
	/// 操作人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)
};

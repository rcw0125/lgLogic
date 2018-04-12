// 逻辑类CAlloy_Pos_Change_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAlloy_Trans_Log :
	public CL3Object
{
public:
	CAlloy_Trans_Log(void);
	virtual ~CAlloy_Trans_Log(void);

	DECLARE_L3CLASS(CAlloy_Trans_Log,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Trans_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Trans_Log" name="SourceID" type="L3STRING">
	/// 原料仓
	/// </Property>
	DECLARE_L3PROP_STRING(SourceID)

	/// <Property class="CAlloy_Trans_Log" name="TargetID" type="L3STRING">
	/// 新料仓
	/// </Property>
	DECLARE_L3PROP_STRING(TargetID)

	/// <Property class="CAlloy_Trans_Log" name="MaterialID" type="L3STRING">
	/// 材料号
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID)

	/// <Property class="CAlloy_Trans_Log" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CAlloy_Trans_Log" name="Alloy_Code" type="L3STRING">
	/// 合金编码
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_Trans_Log" name="Amount" type="L3DOUBLE">
	/// 转移合金量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	/// <Property class="CAlloy_Trans_Log" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CAlloy_Trans_Log" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CAlloy_Trans_Log" name="Trans_Date" type="L3DATETIME">
	/// 时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Trans_Date)

	/// <Property class="CAlloy_Trans_Log" name="Operator" type="L3STRING">
	/// 操作人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)


};

// 逻辑类CCCM_SmoothBlock头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_SmoothBlock :
	public CL3Object
{
public:
	CCCM_SmoothBlock(void);
	virtual ~CCCM_SmoothBlock(void);

	DECLARE_L3CLASS(CCCM_SmoothBlock,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_SmoothBlock)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_SmoothBlock" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	
	/// <Property class="CCCM_SmoothBlock" name="StrandNo" type="L3LONG">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_LONG(StrandNo)

	/// <Property class="CCCM_SmoothBlock" name="BlockID" type="L3STRING">
	/// 滑块
	/// </Property>
	DECLARE_L3PROP_STRING(BlockID)

	/// <Property class="CCCM_SmoothBlock" name="Block_Life" type="L3LONG">
	/// 滑块寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Block_Life)

	/// <Property class="CCCM_SmoothBlock" name="Factory" type="L3STRING">
	/// 滑块厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCCM_SmoothBlock" name="Start_Time" type="L3DATETIME">
	/// 滑块更换开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CCCM_SmoothBlock" name="End_Time" type="L3DATETIME">
	/// 滑块更换结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	
	/// <Property class="CCCM_SmoothBlock" name="Block_Size" type="L3STRING">
	/// 规格
	/// </Property>
	DECLARE_L3PROP_STRING(Block_Size)

	
	/// <Property class="CCCM_SmoothBlock" name="Reason" type="L3STRING">
	/// 换下原因
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

	/// <Property class="CCCM_SmoothBlock" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

};

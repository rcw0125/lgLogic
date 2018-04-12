// 逻辑类CBloom_Input_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialInputLog.h"

class CBloom_Input_Log :
	public MaterialInputLog
{
public:
	CBloom_Input_Log(void);
	virtual ~CBloom_Input_Log(void);

	DECLARE_L3CLASS(CBloom_Input_Log,XGMESLogic\\BloomStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Input_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBloom_Input_Log" name="Bloom_Count" type="L3LONG">
	/// 钢坯枝数
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CBloom_Input_Log" name="Waster_Count" type="L3DOUBLE">
	/// 甩废钢坯长度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count)

	/// <Property class="CBloom_Input_Log" name="Wrong_Count" type="L3LONG">
	/// 不合格钢坯枝数
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count)

	/// <Property class="CBloom_Input_Log" name="Right_Count" type="L3LONG">
	/// 合格钢坯枝数
	/// </Property>
	DECLARE_L3PROP_LONG(Right_Count)

	/// <Property class="CBloom_Input_Log" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CBloom_Input_Log" name="Cur_Section_ID" type="L3STRING">
	/// 当前区
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Section_ID)

	/// <Property class="CBloom_Input_Log" name="Cur_Bay_ID" type="L3STRING">
	/// 当前跨
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Bay_ID)

	/// <Property class="CBloom_Input_Log" name="Cur_Pile_ID" type="L3STRING">
	/// 当前垛
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Pile_ID)

	/// <Property class="CBloom_Input_Log" name="Cur_Layer_ID" type="L3STRING">
	/// 当前层
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Layer_ID)

	/// <Property class="CBloom_Input_Log" name="Cur_Seq_ID" type="L3LONG">
	/// 当前顺序
	/// </Property>
	DECLARE_L3PROP_LONG(Cur_Seq_ID)

	///2009-02-23增加以下字段
	/// <Property class="CBloom_Input_Log" name="Length" type="L3LONG">
	/// 长度
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CBloom_Input_Log" name="Width" type="L3LONG">
	/// 宽度
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CBloom_Input_Log" name="Thickness" type="L3LONG">
	/// 厚度
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CBloom_Input_Log" name="Cal_Weight" type="L3DOUBLE">
	/// 理论重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cal_Weight)

	/// <Property class="CBloom_Input_Log" name="Right_Weight" type="L3DOUBLE">
	/// 合格重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Right_Weight)

	/// <Property class="CBloom_Input_Log" name="Waster_Weight" type="L3DOUBLE">
	/// 甩废总重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight)

	/// <Property class="CBloom_Input_Log" name="Wrong_Weight" type="L3DOUBLE">
	/// 不合格总重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight)

};

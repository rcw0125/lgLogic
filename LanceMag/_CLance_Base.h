// 逻辑类CLance_Base头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLance_Base :
	public CL3Object
{
public:
	CLance_Base(void);
	virtual ~CLance_Base(void);

	DECLARE_L3CLASS(CLance_Base,XGMESLogic\\LanceMag, LanceID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Base)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLance_Base" name="LanceID" type="L3STRING">
	/// 氧枪编号
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Base" name="Lance_Head_Type" type="L3STRING">
	/// 
	/// 枪头型号
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Base" name="BOFID" type="L3STRING">
	/// 炉座
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CLance_Base" name="Status" type="L3STRING">
	/// 状态
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CLance_Base" name="Nozzle_Factury" type="L3STRING">
	/// 喷头厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Nozzle_Factury)

	/// <Property class="CLance_Base" name="Lance_Age" type="L3LONG">
	/// 枪龄
	/// </Property>
	DECLARE_L3PROP_LONG(Lance_Age)

	/// <Property class="CLance_Base" name="MakeID" type="L3STRING">
	/// 氧枪制作编号
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Base" name="Make_Start_Time" type="L3DATETIME">
	/// 氧枪制作开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Make_Start_Time)

	/// <Property class="CLance_Base" name="Make_End_Time" type="L3DATETIME">
	/// 氧枪制作结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Make_End_Time)

};

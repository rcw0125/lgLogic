// 逻辑类CMIF_Chemical头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMIF_Chemical :
	public CL3Object
{
public:
	CMIF_Chemical(void);
	virtual ~CMIF_Chemical(void);

	DECLARE_L3CLASS(CMIF_Chemical,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Chemical)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CMIF_Chemical" name="Sample_Time" type="L3DATETIME">
	/// 来样时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Sample_Time)

	/// <Property class="CMIF_Chemical" name="C" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(C)

	/// <Property class="CMIF_Chemical" name="Si" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si)

	/// <Property class="CMIF_Chemical" name="Mn" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mn)

	/// <Property class="CMIF_Chemical" name="S" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CMIF_Chemical" name="P" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P)

	/// <Property class="CMIF_Chemical" name="Ti" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ti)

	/// <Property class="CMIF_Chemical" name="Mode" type="L3SHORT">
	/// 
	/// 样标识
	/// (0:铁包样
	///  1:1#混铁炉
	///  2:2#混铁炉)
	/// </Property>
	DECLARE_L3PROP_SHORT(Mode)

	/// <Property class="CMIF_Chemical" name="Used_Flag" type="L3SHORT">
	/// 
	/// 使用标志
	/// (0:未使用
	///  1:已使用)
	/// </Property>
	DECLARE_L3PROP_SHORT(Used_Flag)

	/// <Property class="CMIF_Chemical" name="Shift" type="L3SHORT">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_SHORT(Shift)

	/// <Property class="CMIF_Chemical" name="Team" type="L3SHORT">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_SHORT(Team)

};

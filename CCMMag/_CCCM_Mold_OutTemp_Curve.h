// 逻辑类CCCM_Mold_OutTemp_Curve头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Mold_OutTemp_Curve :
	public CL3Object
{
public:
	CCCM_Mold_OutTemp_Curve(void);
	virtual ~CCCM_Mold_OutTemp_Curve(void);

	DECLARE_L3CLASS(CCCM_Mold_OutTemp_Curve,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Mold_OutTemp_Curve)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Mold_OutTemp_Curve" name="ObjectID" type="L3STRING">
	/// 实时数据标识
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CCCM_Mold_OutTemp_Curve" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Mold_OutTemp_Curve" name="ValueID" type="L3LONG">
	/// 
	/// 实时数据代码
	/// (1-4 流结晶器出水温度检测点)
	/// </Property>
	DECLARE_L3PROP_LONG(ValueID)

	/// <Property class="CCCM_Mold_OutTemp_Curve" name="Clock" type="L3DATETIME">
	/// 实时数据记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Clock)

	/// <Property class="CCCM_Mold_OutTemp_Curve" name="Val" type="L3DOUBLE">
	/// 实时数据数值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Val)

};

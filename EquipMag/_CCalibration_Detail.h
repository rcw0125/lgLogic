// 逻辑类CCalibration_Detail头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCalibration_Detail :
	public CL3Object
{
public:
	CCalibration_Detail(void);
	virtual ~CCalibration_Detail(void);

	DECLARE_L3CLASS(CCalibration_Detail,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCalibration_Detail)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCalibration_Detail" name="Location" type="L3STRING">
	/// 对象标识=处所+日期
	/// </Property>
	DECLARE_L3PROP_STRING(LogID)

	/// <Property class="CCalibration_Detail" name="Load_B_Std" type="L3STRING">
	/// 调整前加载标值
	/// </Property>
	DECLARE_L3PROP_STRING(Load_B_Std)

	/// <Property class="CCalibration_Detail" name="Load_B_Act" type="L3STRING">
	/// 调整前加载示值
	/// </Property>
	DECLARE_L3PROP_STRING(Load_B_Act)

	/// <Property class="CCalibration_Detail" name="Load_B_Dif" type="L3STRING">
	/// 调整前加载差值
	/// </Property>
	DECLARE_L3PROP_STRING(Load_B_Dif)

	/// <Property class="CCalibration_Detail" name="UnLoad_B_Std" type="L3STRING">
	/// 调整前卸载标值
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_B_Std)

	/// <Property class="CCalibration_Detail" name="UnLoad_B_Act" type="L3STRING">
	/// 调整前卸载示值
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_B_Act)

	/// <Property class="CCalibration_Detail" name="UnLoad_B_Dif" type="L3STRING">
	/// 调整前卸载差值
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_B_Dif)

	/// <Property class="CCalibration_Detail" name="Load_A_Std" type="L3STRING">
	/// 调整后加载标值
	/// </Property>
	DECLARE_L3PROP_STRING(Load_A_Std)

	/// <Property class="CCalibration_Detail" name="Load_A_Act" type="L3STRING">
	/// 调整后加载示值
	/// </Property>
	DECLARE_L3PROP_STRING(Load_A_Act)

	/// <Property class="CCalibration_Detail" name="Load_A_Dif" type="L3STRING">
	/// 调整后加载差值
	/// </Property>
	DECLARE_L3PROP_STRING(Load_A_Dif)

	/// <Property class="CCalibration_Detail" name="UnLoad_A_Std" type="L3STRING">
	/// 调整后卸载标值
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_A_Std)

	/// <Property class="CCalibration_Detail" name="UnLoad_A_Act" type="L3STRING">
	/// 调整后卸载示值
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_A_Act)

	/// <Property class="CCalibration_Detail" name="UnLoad_A_Dif" type="L3STRING">
	/// 调整后卸载差值
	/// </Property>
	DECLARE_L3PROP_STRING(UnLoad_A_Dif)

	/// <Property class="CCalibration_Detail" name="Create_Time" type="L3DATETIME">
	/// 创建时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Create_Time)
};

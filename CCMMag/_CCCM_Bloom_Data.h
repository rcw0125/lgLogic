// 逻辑类CCCM_Bloom_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Bloom_Data :
	public CL3Object
{
public:
	CCCM_Bloom_Data(void);
	virtual ~CCCM_Bloom_Data(void);

	DECLARE_L3CLASS(CCCM_Bloom_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Bloom_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Bloom_Data" name="Caster_ID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(Caster_ID)

	/// <Property class="CCCM_Bloom_Data" name="Casting_No" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(Casting_No)

	/// <Property class="CCCM_Bloom_Data" name="Casting_Heat_Cnt" type="L3LONG">
	/// 浇次内炉数
	/// </Property>
	DECLARE_L3PROP_LONG(Casting_Heat_Cnt)

	/// <Property class="CCCM_Bloom_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CCCM_Bloom_Data" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CCCM_Bloom_Data" name="Width" type="L3LONG">
	/// 宽度
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CCCM_Bloom_Data" name="Length" type="L3LONG">
	/// 长度
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CCCM_Bloom_Data" name="Cal_Weight" type="L3DOUBLE">
	/// 理论重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cal_Weight)

	/// <Property class="CCCM_Bloom_Data" name="Weight" type="L3DOUBLE">
	/// 重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CCCM_Bloom_Data" name="Cut_Time" type="L3DATETIME">
	/// 切断时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Cut_Time)

	/// <Property class="CCCM_Bloom_Data" name="Thickness" type="L3LONG">
	/// 厚度
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

};

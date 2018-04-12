// 逻辑类CQA_Caster_Std_Proc头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Caster_Std_Proc :
	public CL3Object
{
public:
	CQA_Caster_Std_Proc(void);
	virtual ~CQA_Caster_Std_Proc(void);

	DECLARE_L3CLASS(CQA_Caster_Std_Proc,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Caster_Std_Proc)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Caster_Std_Proc" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Caster_Std_Proc" name="Mold_Cold_Base" type="L3STRING">
	/// 结晶器冷却基准、
	/// </Property>
	DECLARE_L3PROP_STRING(Mold_Cold_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Mold_Shake_Base" type="L3STRING">
	/// 结晶器振动基准、
	/// </Property>
	DECLARE_L3PROP_STRING(Mold_Shake_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Sec_Cold_Base" type="L3STRING">
	/// 二次冷却基准、
	/// </Property>
	DECLARE_L3PROP_STRING(Sec_Cold_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Elec_Mix_Current" type="L3DOUBLE">
	/// 电磁搅拌电流、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Elec_Mix_Current)

	/// <Property class="CQA_Caster_Std_Proc" name="Elec_Mix_Freq" type="L3DOUBLE">
	/// 电磁搅拌频率、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Elec_Mix_Freq)

	/// <Property class="CQA_Caster_Std_Proc" name="ASTC_Flag" type="L3LONG">
	/// 轻压下、
	/// </Property>
	DECLARE_L3PROP_LONG(ASTC_Flag)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Coefficient" type="L3LONG">
	/// 切割补正系数
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Coefficient)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Head_Max" type="L3LONG">
	/// 铸坯切头长度最大、
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Head_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Head_Min" type="L3LONG">
	/// 铸坯切头长度最小
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Head_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Trail_Max" type="L3LONG">
	/// 铸坯切尾长度最大、
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Trail_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Trail_Min" type="L3LONG">
	/// 铸坯切尾长度最小、
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Trail_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="DifSteel_Cut_Length_Max" type="L3LONG">
	/// 异钢连浇接痕前切割长度最大
	/// </Property>
	DECLARE_L3PROP_LONG(DifSteel_Cut_Length_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="DifSteel_Cut_Length_Min" type="L3LONG">
	/// 异钢连浇接痕前切割长度最小、
	/// </Property>
	DECLARE_L3PROP_LONG(DifSteel_Cut_Length_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Mark_Cut_Length_Max" type="L3LONG">
	/// 接痕后切割长度最大、
	/// </Property>
	DECLARE_L3PROP_LONG(Mark_Cut_Length_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Mark_Cut_Length_Min" type="L3LONG">
	/// 接痕后切割长度最小、
	/// </Property>
	DECLARE_L3PROP_LONG(Mark_Cut_Length_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Bloom_Finish_Base" type="L3STRING">
	/// 铸坯精理基准、
	/// </Property>
	DECLARE_L3PROP_STRING(Bloom_Finish_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Slab_Check_Base" type="L3STRING">
	/// 铸坯精整基准
	/// </Property>
	DECLARE_L3PROP_STRING(Slab_Check_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Tundish_Water_Type" type="L3STRING">
	/// 中包水口类型、
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_Water_Type)

	/// <Property class="CQA_Caster_Std_Proc" name="Tundish_Weight_Min" type="L3DOUBLE">
	/// 中包最小钢水量、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tundish_Weight_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Protect_Slag_Base" type="L3STRING">
	/// 保护渣基准、
	/// </Property>
	DECLARE_L3PROP_STRING(Protect_Slag_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Blow_Ar_Max" type="L3DOUBLE">
	/// 塞棒吹氩流量最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Blow_Ar_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Blow_Ar_Min" type="L3DOUBLE">
	/// 塞棒吹氩流量最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Blow_Ar_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Ladle_Blow_Ar_Max" type="L3DOUBLE">
	/// 大包吹氩流量最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Blow_Ar_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Ladle_Blow_Ar_Min" type="L3DOUBLE">
	/// 大包吹氩流量最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Blow_Ar_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Change_Time_Min" type="L3DOUBLE">
	/// 气氛置换时间最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Change_Time_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Hold_Steel_Time_Max" type="L3DOUBLE">
	/// 压钢时间最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hold_Steel_Time_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Stay_Steel_Time_Max" type="L3DOUBLE">
	/// 等钢时间最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Stay_Steel_Time_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Liquid_Temp" type="L3DOUBLE">
	/// 液相线温度、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Liquid_Temp)

	/// <Property class="CQA_Caster_Std_Proc" name="Slow_Cold_Base" type="L3STRING">
	/// 缓冷基准、
	/// </Property>
	DECLARE_L3PROP_STRING(Slow_Cold_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Tundish_Speed_Base" type="L3STRING">
	/// 中包目标温度时铸机拉速基准
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_Speed_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Bloom_Low_Base" type="L3STRING">
	/// 铸坯低倍基准
	/// </Property>
	DECLARE_L3PROP_STRING(Bloom_Low_Base)

};

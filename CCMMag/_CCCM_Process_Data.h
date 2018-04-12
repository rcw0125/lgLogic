// 逻辑类CCCM_Process_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Process_Data :
	public CL3Object
{
public:
	CCCM_Process_Data(void);
	virtual ~CCCM_Process_Data(void);

	DECLARE_L3CLASS(CCCM_Process_Data,XGMESLogic\\CCMMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	///2009-02-13 删除厚宽长、预定炉号、预定包次号、产品牌号、铸造宽、铸造厚、引流次数、保护浇注、铸坯支数、
	///保护浇注、铸坯支数、粗坯量、合格支数、合格重量、不合格支数、不合格重量、甩废支数、最终切断时刻、
	///炼钢记号、甩废重量、合格支数、钢水返送区分、漏钢次数
	///添加回炉原因、中包车别

	/// <Property class="CCCM_Process_Data" name="TreatNo" type="L3STRING">
	/// 连铸处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Process_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Process_Data" name="CastingNo" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Process_Data" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Process_Data" name="TundishNo" type="L3STRING">
	/// 中包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_Process_Data" name="TundishCar_Type" type="L3STRING">
	/// 中包车别
	/// </Property>
	DECLARE_L3PROP_STRING(TundishCar_Type)




	/// <Property class="CCCM_Process_Data" name="Casting_HeatNum" type="L3LONG">
	/// 浇次内炉数
	/// </Property>
	DECLARE_L3PROP_LONG(Casting_HeatNum)

	/// <Property class="CCCM_Process_Data" name="Tundish_HeatNum" type="L3LONG">
	/// 包次内炉数
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_HeatNum)

	/// <Property class="CCCM_Process_Data" name="CastingStartTime" type="L3DATETIME">
	/// 开浇时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(CastingStartTime)

	/// <Property class="CCCM_Process_Data" name="CastingStopTime" type="L3DATETIME">
	/// 停浇时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(CastingStopTime)

	
	/// <Property class="CCCM_Process_Data" name="InjectionBar_BlowAr" type="L3SHORT">
	/// 
	/// 是否塞棒吹氩
	/// (1-是
	///  0-不是)
	/// </Property>
	DECLARE_L3PROP_SHORT(InjectionBar_BlowAr)


	/// <Property class="CCCM_Process_Data" name="Weight_Return" type="L3DOUBLE">
	/// 回炉钢水量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Return)


	/// <Property class="CCCM_Process_Data" name="Weight_Return_Reason" type="L3STRING">
	/// 回炉原因
	/// </Property>
	DECLARE_L3PROP_STRING(Weight_Return_Reason)


	/// <Property class="CCCM_Process_Data" name="Second_Cooling_Mode" type="L3SHORT">
	/// 
	/// 二冷水模式
	/// (1-L1、2-L2、0-手动)
	/// </Property>
	DECLARE_L3PROP_SHORT(Second_Cooling_Mode)

	/// <Property class="CCCM_Process_Data" name="Second_Cooling_CurveNo" type="L3SHORT">
	/// 二冷水水表号
	/// </Property>
	DECLARE_L3PROP_SHORT(Second_Cooling_CurveNo)

	/// <Property class="CCCM_Process_Data" name="Weight_Cut_Head" type="L3DOUBLE">
	/// 切头量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Cut_Head)

	/// <Property class="CCCM_Process_Data" name="Weight_Cut_Trail" type="L3DOUBLE">
	/// 切尾量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Cut_Trail)

	/// <Property class="CCCM_Process_Data" name="Tundish_SlagThickness" type="L3LONG">
	/// 中包渣层厚度[mm]
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_SlagThickness)

	/// <Property class="CCCM_Process_Data" name="Tundish_Bottom_Temp" type="L3LONG">
	/// 中包底温度[℃]
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Bottom_Temp)

	/// <Property class="CCCM_Process_Data" name="Tundish_Wall_Temp" type="L3LONG">
	/// 中包壁温度[℃]
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Wall_Temp)

	/// <Property class="CCCM_Process_Data" name="Tundish_Level_Mold" type="L3LONG">
	/// 中包液面[mm]
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Level_Mold) 

	/// <Property class="CCCM_Process_Data" name="PlugBar_Control" type="L3STRING">
	/// 塞棒控制
	/// </Property>
	DECLARE_L3PROP_STRING(PlugBar_Control)

	/// <Property class="CCCM_Process_Data" name="Soft_Press_Flag_1" type="L3STRING">
	/// 1流轻压下是否投用
	/// </Property>
	DECLARE_L3PROP_STRING(Soft_Press_Flag_1)

	/// <Property class="CCCM_Process_Data" name="Soft_Press_Flag_2" type="L3STRING">
	/// 2流轻压下是否投用
	/// </Property>
	DECLARE_L3PROP_STRING(Soft_Press_Flag_2)

	/// <Property class="CCCM_Process_Data" name="Soft_Press_Flag_3" type="L3STRING">
	/// 3流轻压下是否投用
	/// </Property>
	DECLARE_L3PROP_STRING(Soft_Press_Flag_3)

	/// <Property class="CCCM_Process_Data" name="Soft_Press_Flag_4" type="L3STRING">
	/// 4流轻压下是否投用
	/// </Property>
	DECLARE_L3PROP_STRING(Soft_Press_Flag_4)

	/// <Property class="CCCM_Process_Data" name="SpeedChange" type="L3STRING">
	/// 拉速改变标志 
	/// </Property>
	DECLARE_L3PROP_STRING(SpeedChange)




};

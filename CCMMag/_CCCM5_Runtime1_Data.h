// 逻辑类CCCM5_Runtime1_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM5_Runtime1_Data :
	public CL3Object
{
public:
	CCCM5_Runtime1_Data(void);
	virtual ~CCCM5_Runtime1_Data(void);

	DECLARE_L3CLASS(CCCM5_Runtime1_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM5_Runtime1_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM5_Runtime_Data" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM5_Runtime_Data" name="TreatNo" type="L3STRING">
	/// 处理号
		/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM5_Runtime_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM5_Runtime_Data" name="Catch_Count" type="L3LONG">
	/// 采集次数
	/// </Property>
	DECLARE_L3PROP_LONG(Catch_Count)

	/// <Property class="CCCM5_Runtime_Data" name="Cooling_MeterNo" type="L3LONG">
	/// 二冷水表号
	/// </Property>
	DECLARE_L3PROP_LONG(Cooling_MeterNo)

	/// <Property class="CCCM5_Runtime_Data" name="Oscillate_MeterNo" type="L3LONG">
	/// 振动表号
	/// </Property>
	DECLARE_L3PROP_LONG(Oscillate_MeterNo)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_ProtectCasting" type="L3DOUBLE">
	/// 大包保护浇注吹氩流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_ProtectCasting)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_PlugBar_1ST" type="L3DOUBLE">
	/// 1流吹氩流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_PlugBar_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_PlugBar_2ST" type="L3DOUBLE">
	/// 2流吹氩流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_PlugBar_2ST)

		/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_PlugBar_3ST" type="L3DOUBLE">
	/// 3流吹氩流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_PlugBar_3ST)

		/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_PlugBar_4ST" type="L3DOUBLE">
	/// 4流吹氩流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_PlugBar_4ST)


	/// <Property class="CCCM5_Runtime_Data" name="Position_Act_PlugBar_1ST" type="L3DOUBLE">
	/// 1流实际棒位
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Act_PlugBar_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Act_PlugBar_2ST" type="L3DOUBLE">
	/// 2流实际棒位
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Act_PlugBar_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Act_PlugBar_3ST" type="L3DOUBLE">
	/// 3流实际棒位
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Act_PlugBar_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Act_PlugBar_4ST" type="L3DOUBLE">
	/// 4流实际棒位
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Act_PlugBar_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Init_PlugBar_1ST" type="L3DOUBLE">
	/// 1流初始棒位
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Init_PlugBar_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Init_PlugBar_2ST" type="L3DOUBLE">
	/// 2流初始棒位
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Init_PlugBar_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Init_PlugBar_3ST" type="L3DOUBLE">
	/// 3流初始棒位
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Init_PlugBar_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Init_PlugBar_4ST" type="L3DOUBLE">
	/// 4流初始棒位
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Init_PlugBar_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Level_Act_Mold_1ST" type="L3DOUBLE">
	/// 1流实际结晶器液面
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Level_Act_Mold_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Level_Act_Mold_2ST" type="L3DOUBLE">
	/// 2流实际结晶器液面
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Level_Act_Mold_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Level_Act_Mold_3ST" type="L3DOUBLE">
	/// 3流实际液面
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Level_Act_Mold_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Level_Act_Mold_4ST" type="L3DOUBLE">
	/// 4流实际结液面
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Level_Act_Mold_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_In_Cooling" type="L3LONG">
	/// 二冷水进水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_In_Cooling)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1stSect_1ST" type="L3DOUBLE">
	/// 1流1段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_1stSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ndSect_1ST" type="L3DOUBLE">
	/// 1流2段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_2ndSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3rdSect_1ST" type="L3DOUBLE">
	/// 1流3段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_3rdSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4thSect_1ST" type="L3DOUBLE">
	/// 1流4段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_4thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_5thSect_1ST" type="L3DOUBLE">
	/// 1流5段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_5thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1stSect_1ST" type="L3DOUBLE">
	/// 1流1段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_1stSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ndSect_1ST" type="L3DOUBLE">
	/// 1流2段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_2ndSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3rdSect_1ST" type="L3DOUBLE">
	/// 1流3段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_3rdSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4thSect_1ST" type="L3DOUBLE">
	/// 1流4段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_4thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_5thSect_1ST" type="L3DOUBLE">
	/// 1流5段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_5thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1stSect_2ST" type="L3DOUBLE">
	/// 2流1段宽面冷却水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_1stSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ndSect_2ST" type="L3DOUBLE">
	/// 2流2段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_2ndSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3rdSect_2ST" type="L3DOUBLE">
	/// 2流3段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_3rdSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4thSect_2ST" type="L3DOUBLE">
	/// 2流4段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_4thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_5thSect_2ST" type="L3DOUBLE">
	/// 2流5段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_5thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1stSect_2ST" type="L3DOUBLE">
	/// 2流1段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_1stSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ndSect_2ST" type="L3DOUBLE">
	/// 2流2段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_2ndSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3rdSect_2ST" type="L3DOUBLE">
	/// 2流3段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_3rdSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4thSect_2ST" type="L3DOUBLE">
	/// 2流4段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_4thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_5thSect_2ST" type="L3DOUBLE">
	/// 2流5段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_5thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1stSect_3ST" type="L3DOUBLE">
	/// 3流1段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_1stSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ndSect_3ST" type="L3DOUBLE">
	/// 3流2段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_2ndSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3rdSect_3ST" type="L3DOUBLE">
	/// 3流3段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_3rdSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4thSect_3ST" type="L3DOUBLE">
	/// 3流4段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_4thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_5thSect_3ST" type="L3DOUBLE">
	/// 3流5段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_5thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1stSect_3ST" type="L3DOUBLE">
	/// 3流1段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_1stSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ndSect_3ST" type="L3DOUBLE">
	/// 3流2段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_2ndSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3rdSect_3ST" type="L3DOUBLE">
	/// 3流3段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_3rdSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4thSect_3ST" type="L3DOUBLE">
	/// 3流4段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_4thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_5thSect_3ST" type="L3DOUBLE">
	/// 3流5段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_5thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1stSect_4ST" type="L3DOUBLE">
	/// 4流1段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_1stSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ndSect_4ST" type="L3DOUBLE">
	/// 4流2段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_2ndSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3rdSect_4ST" type="L3DOUBLE">
	/// 4流3段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_3rdSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4thSect_4ST" type="L3DOUBLE">
	/// 4流4段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_4thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_5thSect_4ST" type="L3DOUBLE">
	/// 4流5段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_5thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1stSect_4ST" type="L3DOUBLE">
	/// 4流1段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_1stSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ndSect_4ST" type="L3DOUBLE">
	/// 4流2段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_2ndSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3rdSect_4ST" type="L3DOUBLE">
	/// 4流3段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_3rdSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4thSect_4ST" type="L3DOUBLE">
	/// 4流4段宽面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_4thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_5thSect_4ST" type="L3DOUBLE">
	/// 4流5段窄面水流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_5thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cooling" type="L3DOUBLE">
	/// 二冷水总流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cooling)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_Mold_1ST" type="L3LONG">
	/// 1流出水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_Mold_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_Mold_2ST" type="L3LONG">
	/// 2流出水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_Mold_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_Mold_3ST" type="L3LONG">
	/// 3流出水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_Mold_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_Mold_4ST" type="L3LONG">
	/// 4流出水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_Mold_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_1ST" type="L3LONG">
	/// 1流出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_2ST" type="L3LONG">
	/// 2流出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_3ST" type="L3LONG">
	/// 3流出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_4ST" type="L3LONG">
	/// 4流出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1ST" type="L3LONG">
	/// 1流宽面水流量
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Wdh_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ST" type="L3LONG">
	/// 2流宽面水流量
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Wdh_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3ST" type="L3LONG">
	/// 3流宽面水流量
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Wdh_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4ST" type="L3LONG">
	/// 4流宽面水流量
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Wdh_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1ST" type="L3LONG">
	/// 1流窄面水流量
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Nrw_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ST" type="L3LONG">
	/// 2流窄面水流量
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Nrw_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3ST" type="L3LONG">
	/// 3流窄面水流量
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Nrw_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4ST" type="L3LONG">
	/// 4流窄面水流量
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Nrw_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_1ST" type="L3DOUBLE">
	/// 1流设定振频
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_2ST" type="L3DOUBLE">
	/// 2流设定振频
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_3ST" type="L3DOUBLE">
	/// 3流设定振频
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_4ST" type="L3DOUBLE">
	/// 4流设定振频
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_1ST" type="L3DOUBLE">
	/// 1流实际振频
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_2ST" type="L3DOUBLE">
	/// 2流实际振频
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_3ST" type="L3DOUBLE">
	/// 3流实际振频
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_4ST" type="L3DOUBLE">
	/// 4流实际振频
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Setup_1ST" type="L3DOUBLE">
	/// 1流设定振幅
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Setup_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Setup_2ST" type="L3DOUBLE">
	/// 2流设定振幅
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Setup_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Setup_3ST" type="L3DOUBLE">
	/// 3流设定振幅
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Setup_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Setup_4ST" type="L3DOUBLE">
	/// 4流设定振幅
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Setup_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Act_1ST" type="L3DOUBLE">
	/// 1流实际振幅
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Act_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Act_2ST" type="L3DOUBLE">
	/// 2流实际振幅
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Act_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Act_3ST" type="L3DOUBLE">
	/// 3流实际振幅
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Act_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Act_4ST" type="L3DOUBLE">
	/// 4流实际振幅
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Act_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_In_ElectMix" type="L3LONG">
	/// 进水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_In_ElectMix)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_ElectMix_1ST" type="L3LONG">
	/// 1流拌出水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_ElectMix_2ST" type="L3LONG">
	/// 2流出水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_ElectMix_3ST" type="L3LONG">
	/// 3流出水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_ElectMix_4ST" type="L3LONG">
	/// 4流出水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_1ST" type="L3LONG">
	/// 1流进出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Def_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_2ST" type="L3LONG">
	/// 2流进出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Def_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_3ST" type="L3LONG">
	/// 3流进出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Def_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_4ST" type="L3LONG">
	/// 4流进出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Def_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Setup_ElectMix_1ST" type="L3DOUBLE">
	/// 1流设定电流
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Setup_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Setup_ElectMix_2ST" type="L3DOUBLE">
	/// 2流设定电流
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Setup_ElectMix_2ST)

    /// <Property class="CCCM5_Runtime_Data" name="Current_Setup_ElectMix_3ST" type="L3DOUBLE">
	/// 3流设定电流
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Setup_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Setup_ElectMix_4ST" type="L3DOUBLE">
	/// 4流设定电流
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Setup_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Act_ElectMix_1ST" type="L3DOUBLE">
	/// 1流实际电流
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Act_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Act_ElectMix_2ST" type="L3DOUBLE">
	/// 2流实际电流
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Act_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Act_ElectMix_3ST" type="L3DOUBLE">
	/// 3流实际电流
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Act_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Act_ElectMix_4ST" type="L3DOUBLE">
	/// 4流实际电流
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Act_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_ElectMix_1ST" type="L3DOUBLE">
	/// 1流设定频率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_ElectMix_2ST" type="L3DOUBLE">
	/// 2流设定频率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_ElectMix_3ST" type="L3DOUBLE">
	/// 3流设定频率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_ElectMix_4ST" type="L3DOUBLE">
	/// 4流设定频率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_ElectMix_1ST" type="L3DOUBLE">
	/// 1流实际频率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_ElectMix_2ST" type="L3DOUBLE">
	/// 2流实际频率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_ElectMix_3ST" type="L3DOUBLE">
	/// 3流实际频率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_ElectMix_4ST" type="L3DOUBLE">
	/// 4流实际频率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Direction_ElectMix_1ST" type="L3LONG">
	/// 1流旋转方向
	/// </Property>
	DECLARE_L3PROP_LONG(Direction_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Direction_ElectMix_2ST" type="L3LONG">
	/// 2流旋转方向
	/// </Property>
	DECLARE_L3PROP_LONG(Direction_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Direction_ElectMix_3ST" type="L3LONG">
	/// 3流旋转方向
	/// </Property>
	DECLARE_L3PROP_LONG(Direction_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Direction_ElectMix_4ST" type="L3LONG">
	/// 4流旋转方向
	/// </Property>
	DECLARE_L3PROP_LONG(Direction_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pressure_Oxygen_Cut" type="L3DOUBLE">
	/// 切割氧压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure_Oxygen_Cut)

	/// <Property class="CCCM5_Runtime_Data" name="Pressure_Oxygen_PreHeat" type="L3DOUBLE">
	/// 预热氧压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure_Oxygen_PreHeat)

	/// <Property class="CCCM5_Runtime_Data" name="Pressure_CokeGas" type="L3DOUBLE">
	/// 焦炉煤气压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure_CokeGas)

	/// <Property class="CCCM5_Runtime_Data" name="LogTime" type="L3DATETIME">
	/// 数据记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CCCM_Runtime_Data" name="Temp_In_Mold_12ST" type="L3LONG">
	/// 结晶器1-2流进水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_In_Mold_12ST)

	/// <Property class="CCCM_Runtime_Data" name="Temp_In_Mold_34ST" type="L3LONG">
	/// 结晶器3-4流进水温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_In_Mold_34ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_N_1ST" type="L3DOUBLE">
	/// 1流窄面出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_N_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_N_2ST" type="L3DOUBLE">
	/// 2流窄面出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_N_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_N_3ST" type="L3DOUBLE">
	/// 3流窄面出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_N_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_N_4ST" type="L3DOUBLE">
	/// 4流窄面出水温差
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_N_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pressure_Cooling" type="L3DOUBLE">
	/// 二冷水总管氧压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure_Cooling)
};

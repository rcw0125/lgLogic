// 逻辑类CCCM5_Runtime2_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM5_Runtime2_Data :
	public CL3Object
{
public:
	CCCM5_Runtime2_Data(void);
	virtual ~CCCM5_Runtime2_Data(void);

	DECLARE_L3CLASS(CCCM5_Runtime2_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM5_Runtime2_Data)
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

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_12ST" type="L3DOUBLE">
	/// 1-2流冷却气压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_12ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_34ST" type="L3DOUBLE">
	/// 3-4流冷却气压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_34ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_2ndSect_1ST" type="L3DOUBLE">
	/// 1流2段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_2ndSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_3rdSect_1ST" type="L3DOUBLE">
	/// 1流3段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_3rdSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_4thSect_1ST" type="L3DOUBLE">
	/// 1流4段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_4thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_5thSect_1ST" type="L3DOUBLE">
	/// 1流5段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_5thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_2ndSect_1ST" type="L3DOUBLE">
	/// 1流2段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_2ndSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_3rdSect_1ST" type="L3DOUBLE">
	/// 1流3段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_3rdSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_4thSect_1ST" type="L3DOUBLE">
	/// 1流4段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_4thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_5thSect_1ST" type="L3DOUBLE">
	/// 1流5段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_5thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_2ndSect_2ST" type="L3DOUBLE">
	/// 2流2段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_2ndSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_3rdSect_2ST" type="L3DOUBLE">
	/// 2流3段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_3rdSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_4thSect_2ST" type="L3DOUBLE">
	/// 2流4段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_4thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_5thSect_2ST" type="L3DOUBLE">
	/// 2流5段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_5thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_2ndSect_2ST" type="L3DOUBLE">
	/// 2流2段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_2ndSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_3rdSect_2ST" type="L3DOUBLE">
	/// 2流3段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_3rdSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_4thSect_2ST" type="L3DOUBLE">
	/// 2流4段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_4thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_5thSect_2ST" type="L3DOUBLE">
	/// 2流5段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_5thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_2ndSect_3ST" type="L3DOUBLE">
	/// 3流2段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_2ndSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_3rdSect_3ST" type="L3DOUBLE">
	/// 3流3段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_3rdSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_4thSect_3ST" type="L3DOUBLE">
	/// 3流4段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_4thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_5thSect_3ST" type="L3DOUBLE">
	/// 3流5段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_5thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_2ndSect_3ST" type="L3DOUBLE">
	/// 3流2段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_2ndSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_3rdSect_3ST" type="L3DOUBLE">
	/// 3流3段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_3rdSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_4thSect_3ST" type="L3DOUBLE">
	/// 3流4段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_4thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_5thSect_3ST" type="L3DOUBLE">
	/// 3流5段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_5thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_2ndSect_4ST" type="L3DOUBLE">
	/// 4流2段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_2ndSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_3rdSect_4ST" type="L3DOUBLE">
	/// 4流3段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_3rdSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_4thSect_4ST" type="L3DOUBLE">
	/// 4流4段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_4thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_5thSect_4ST" type="L3DOUBLE">
	/// 4流5段宽面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_5thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_2ndSect_4ST" type="L3DOUBLE">
	/// 4流2段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_2ndSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_3rdSect_4ST" type="L3DOUBLE">
	/// 4流3段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_3rdSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_4thSect_4ST" type="L3DOUBLE">
	/// 4流4段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_4thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_5thSect_4ST" type="L3DOUBLE">
	/// 4流5段窄面气压
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_5thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller1_1ST" type="L3DOUBLE">
	/// 1流1#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller1_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller2_1ST" type="L3DOUBLE">
	/// 1流2#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller2_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller3_1ST" type="L3DOUBLE">
	/// 1流3#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller3_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller4_1ST" type="L3DOUBLE">
	/// 1流4#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller4_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller5_1ST" type="L3DOUBLE">
	/// 1流5#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller5_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller6_1ST" type="L3DOUBLE">
	/// 1流6#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller6_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller7_1ST" type="L3DOUBLE">
	/// 1流7#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller7_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller1_2ST" type="L3DOUBLE">
	/// 2流1#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller1_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller2_2ST" type="L3DOUBLE">
	/// 2流2#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller2_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller3_2ST" type="L3DOUBLE">
	/// 2流3#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller3_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller4_2ST" type="L3DOUBLE">
	/// 2流4#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller4_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller5_2ST" type="L3DOUBLE">
	/// 2流5#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller5_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller6_2ST" type="L3DOUBLE">
	/// 2流6#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller6_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller7_2ST" type="L3DOUBLE">
	/// 2流7#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller7_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller1_3ST" type="L3DOUBLE">
	/// 3流1#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller1_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller2_3ST" type="L3DOUBLE">
	/// 3流2#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller2_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller3_3ST" type="L3DOUBLE">
	/// 3流3#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller3_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller4_3ST" type="L3DOUBLE">
	/// 3流4#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller4_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller5_3ST" type="L3DOUBLE">
	/// 3流5#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller5_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller6_3ST" type="L3DOUBLE">
	/// 3流6#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller6_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller7_3ST" type="L3DOUBLE">
	/// 3流7#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller7_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller1_4ST" type="L3DOUBLE">
	/// 4流1#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller1_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller2_4ST" type="L3DOUBLE">
	/// 4流2#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller2_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller3_4ST" type="L3DOUBLE">
	/// 4流3#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller3_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller4_4ST" type="L3DOUBLE">
	/// 4流4#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller4_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller5_4ST" type="L3DOUBLE">
	/// 4流5#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller5_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller6_4ST" type="L3DOUBLE">
	/// 4流6#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller6_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller7_4ST" type="L3DOUBLE">
	/// 4流7#辊设定值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller7_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller1_1ST" type="L3DOUBLE">
	/// 1流1#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller1_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller2_1ST" type="L3DOUBLE">
	/// 1流2#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller2_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller3_1ST" type="L3DOUBLE">
	/// 1流3#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller3_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller4_1ST" type="L3DOUBLE">
	/// 1流4#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller4_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller5_1ST" type="L3DOUBLE">
	/// 1流5#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller5_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller6_1ST" type="L3DOUBLE">
	/// 1流6#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller6_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller7_1ST" type="L3DOUBLE">
	/// 1流7#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller7_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller1_2ST" type="L3DOUBLE">
	/// 2流1#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller1_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller2_2ST" type="L3DOUBLE">
	/// 2流2#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller2_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller3_2ST" type="L3DOUBLE">
	/// 2流3#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller3_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller4_2ST" type="L3DOUBLE">
	/// 2流4#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller4_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller5_2ST" type="L3DOUBLE">
	/// 2流5#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller5_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller6_2ST" type="L3DOUBLE">
	/// 2流6#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller6_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller7_2ST" type="L3DOUBLE">
	/// 2流7#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller7_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller1_3ST" type="L3DOUBLE">
	/// 3流1#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller1_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller2_3ST" type="L3DOUBLE">
	/// 3流2#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller2_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller3_3ST" type="L3DOUBLE">
	/// 3流3#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller3_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller4_3ST" type="L3DOUBLE">
	/// 3流4#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller4_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller5_3ST" type="L3DOUBLE">
	/// 3流5#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller5_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller6_3ST" type="L3DOUBLE">
	/// 3流6#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller6_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller7_3ST" type="L3DOUBLE">
	/// 3流7#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller7_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller1_4ST" type="L3DOUBLE">
	/// 4流1#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller1_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller2_4ST" type="L3DOUBLE">
	/// 4流2#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller2_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller3_4ST" type="L3DOUBLE">
	/// 4流3#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller3_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller4_4ST" type="L3DOUBLE">
	/// 4流4#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller4_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller5_4ST" type="L3DOUBLE">
	/// 4流5#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller5_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller6_4ST" type="L3DOUBLE">
	/// 4流6#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller6_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller7_4ST" type="L3DOUBLE">
	/// 4流7#辊实际值
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller7_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="LogTime" type="L3DATETIME">
	/// 数据记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CCCM5_Runtime_Data" name="Auto_Level_1ST" type="L3LONG">
	/// 1流液面控制模式
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Level_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Auto_Level_2ST" type="L3LONG">
	/// 2流液面控制模式
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Level_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Auto_Level_3ST" type="L3LONG">
	/// 3流液面控制模式
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Level_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Auto_Level_4ST" type="L3LONG">
	/// 4流液面控制模式
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Level_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Mode_Cooling_1ST" type="L3LONG">
	/// 1流二冷水模式
	/// </Property>
	DECLARE_L3PROP_LONG(Mode_Cooling_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Mode_Cooling_2ST" type="L3LONG">
	/// 2流二冷水模式
	/// </Property>
	DECLARE_L3PROP_LONG(Mode_Cooling_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Mode_Cooling_3ST" type="L3LONG">
	/// 3流二冷水模式
	/// </Property>
	DECLARE_L3PROP_LONG(Mode_Cooling_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Mode_Cooling_4ST" type="L3LONG">
	/// 4流二冷水模式
	/// </Property>
	DECLARE_L3PROP_LONG(Mode_Cooling_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flag_SoftPress_1ST" type="L3LONG">
	/// 1流投用轻压下
	/// </Property>
	DECLARE_L3PROP_LONG(Flag_SoftPress_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flag_SoftPress_2ST" type="L3LONG">
	/// 2流投用轻压下
	/// </Property>
	DECLARE_L3PROP_LONG(Flag_SoftPress_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flag_SoftPress_3ST" type="L3LONG">
	/// 3流投用轻压下
	/// </Property>
	DECLARE_L3PROP_LONG(Flag_SoftPress_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flag_SoftPress_4ST" type="L3LONG">
	/// 4流投用轻压下
	/// </Property>
	DECLARE_L3PROP_LONG(Flag_SoftPress_4ST)
};

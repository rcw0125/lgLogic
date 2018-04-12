// 逻辑类CEquip_Runtime_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEquip_Runtime_Data :
	public CL3Object
{
public:
	CEquip_Runtime_Data(void);
	virtual ~CEquip_Runtime_Data(void);

	DECLARE_L3CLASS(CEquip_Runtime_Data,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Runtime_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEquip_Runtime_Data" name="Catch_Time" type="L3DATETIME">
	/// 采集时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

	/// <Property class="CEquip_Runtime_Data" name="P_Before_CycPump_BOF4" type="L3FLOAT">
	/// 4#转炉烟罩循环泵后压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Before_CycPump_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="P_After_CycPump_BOF4" type="L3FLOAT">
	/// 4#转炉烟罩循环泵前压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_After_CycPump_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="P_Regenerator1" type="L3FLOAT">
	/// 1#蓄热器工作压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Regenerator1)

	/// <Property class="CEquip_Runtime_Data" name="T_Regenerator1" type="L3FLOAT">
	/// 1#蓄热器工作温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Regenerator1)

	/// <Property class="CEquip_Runtime_Data" name="P_Regenerator2" type="L3FLOAT">
	/// 2#蓄热器工作压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Regenerator2)

	/// <Property class="CEquip_Runtime_Data" name="T_Regenerator2" type="L3FLOAT">
	/// 2#蓄热器工作温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Regenerator2)

	/// <Property class="CEquip_Runtime_Data" name="P_Supply_Regenerator" type="L3FLOAT">
	/// 蓄热器供外网压力
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Supply_Regenerator)

	/// <Property class="CEquip_Runtime_Data" name="P_YiWen_BOF1" type="L3FLOAT">
	/// 1#一文前负压
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="P_YiWen_BOF2" type="L3FLOAT">
	/// 2#一文前负压
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="P_YiWen_BOF3" type="L3FLOAT">
	/// 3#一文前负压
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="P_YiWen_BOF4" type="L3FLOAT">
	/// 4#一文前负压
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Lose_YiWen_BOF1" type="L3FLOAT">
	/// 1#一文阻损
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="Lose_YiWen_BOF2" type="L3FLOAT">
	/// 2#一文阻损
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="Lose_YiWen_BOF3" type="L3FLOAT">
	/// 3#一文阻损
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="Lose_YiWen_BOF4" type="L3FLOAT">
	/// 4#一文阻损
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="P_Water_YiWen_BOF1" type="L3FLOAT">
	/// 1#一文冷却水水压
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Water_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="P_Water_YiWen_BOF2" type="L3FLOAT">
	/// 2#一文冷却水水压
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Water_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="P_Water_YiWen_BOF3" type="L3FLOAT">
	/// 3#一文冷却水水压
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Water_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="P_Water_YiWen_BOF4" type="L3FLOAT">
	/// 4#一文冷却水水压
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Water_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Jet_YiWen_BOF1" type="L3FLOAT">
	/// 1#一文喷头水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Jet_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Jet_YiWen_BOF2" type="L3FLOAT">
	/// 2#一文喷头水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Jet_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Jet_YiWen_BOF3" type="L3FLOAT">
	/// 3#一文喷头水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Jet_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Jet_YiWen_BOF4" type="L3FLOAT">
	/// 4#一文喷头水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Jet_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Spill_YiWen_BOF1" type="L3FLOAT">
	/// 1#一文溢流水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Spill_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Spill_YiWen_BOF2" type="L3FLOAT">
	/// 2#一文溢流水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Spill_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Spill_YiWen_BOF3" type="L3FLOAT">
	/// 3#一文溢流水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Spill_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Spill_YiWen_BOF4" type="L3FLOAT">
	/// 4#一文溢流水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Spill_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="T_Water_Cycle_BOF1" type="L3FLOAT">
	/// 1#转炉浊环水温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Water_Cycle_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="T_Water_Cycle_BOF2" type="L3FLOAT">
	/// 2#转炉浊环水温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Water_Cycle_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="T_Water_Cycle_BOF3" type="L3FLOAT">
	/// 3#转炉浊环水温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Water_Cycle_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="T_Water_Cycle_BOF4" type="L3FLOAT">
	/// 4#转炉浊环水温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Water_Cycle_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_YiWen_BOF1" type="L3FLOAT">
	/// 1#一文出口烟气温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_YiWen_BOF2" type="L3FLOAT">
	/// 2#一文出口烟气温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_YiWen_BOF3" type="L3FLOAT">
	/// 3#一文出口烟气温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_YiWen_BOF4" type="L3FLOAT">
	/// 4#一文出口烟气温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Lose_ErWen_BOF1" type="L3FLOAT">
	/// 1#二文阻损
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_ErWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="Lose_ErWen_BOF2" type="L3FLOAT">
	/// 2#二文阻损
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_ErWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="Lose_ErWen_BOF3" type="L3FLOAT">
	/// 3#二文阻损
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_ErWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="Lose_ErWen_BOF4" type="L3FLOAT">
	/// 4#二文阻损
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_ErWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_ErWen_BOF1" type="L3FLOAT">
	/// 1#二文冷却水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_ErWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_ErWen_BOF2" type="L3FLOAT">
	/// 2#二文冷却水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_ErWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_ErWen_BOF3" type="L3FLOAT">
	/// 3#二文冷却水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_ErWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_ErWen_BOF4" type="L3FLOAT">
	/// 4#二文冷却水流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_ErWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_ErWen_BOF1" type="L3FLOAT">
	/// 1#二文出口烟气温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_ErWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_ErWen_BOF2" type="L3FLOAT">
	/// 2#二文出口烟气温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_ErWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_ErWen_BOF3" type="L3FLOAT">
	/// 3#二文出口烟气温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_ErWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_ErWen_BOF4" type="L3FLOAT">
	/// 4#二文出口烟气温度
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_ErWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Span_Valve_ErWen_BOF1" type="L3FLOAT">
	/// 1#二文翻板开口度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Span_Valve_ErWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="Span_Valve_ErWen_BOF2" type="L3FLOAT">
	/// 2#二文翻板开口度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Span_Valve_ErWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="Span_Valve_ErWen_BOF3" type="L3FLOAT">
	/// 3#二文翻板开口度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Span_Valve_ErWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="Span_Valve_ErWen_BOF4" type="L3FLOAT">
	/// 4#二文翻板开口度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Span_Valve_ErWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Rev_Fan_BOF1" type="L3FLOAT">
	/// 1#风机转速
	/// </Property>
	DECLARE_L3PROP_FLOAT(Rev_Fan_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="Rev_Fan_BOF2" type="L3FLOAT">
	/// 2#风机转速
	/// </Property>
	DECLARE_L3PROP_FLOAT(Rev_Fan_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="Rev_Fan_BOF3" type="L3FLOAT">
	/// 3#风机转速
	/// </Property>
	DECLARE_L3PROP_FLOAT(Rev_Fan_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="Rev_Fan_BOF4" type="L3FLOAT">
	/// 4#风机转速
	/// </Property>
	DECLARE_L3PROP_FLOAT(Rev_Fan_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="C_CO_Gas_BOF1" type="L3FLOAT">
	/// 1#转炉煤气CO含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_CO_Gas_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="C_CO_Gas_BOF2" type="L3FLOAT">
	/// 2#转炉煤气CO含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_CO_Gas_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="C_CO_Gas_BOF3" type="L3FLOAT">
	/// 3#转炉煤气CO含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_CO_Gas_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="C_CO_Gas_BOF4" type="L3FLOAT">
	/// 4#转炉煤气CO含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_CO_Gas_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="C_O2_Gas_BOF1" type="L3FLOAT">
	/// 1#转炉煤气O2含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_O2_Gas_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="C_O2_Gas_BOF2" type="L3FLOAT">
	/// 2#转炉煤气O2含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_O2_Gas_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="C_O2_Gas_BOF3" type="L3FLOAT">
	/// 3#转炉煤气O2含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_O2_Gas_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="C_O2_Gas_BOF4" type="L3FLOAT">
	/// 4#转炉煤气O2含量
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_O2_Gas_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CEquip_Runtime_Data" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)
};

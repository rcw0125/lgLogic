// 逻辑类CBF_Iron_Back_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBF_Iron_Back_Log :
	public CL3Object
{
public:
	CBF_Iron_Back_Log(void);
	virtual ~CBF_Iron_Back_Log(void);

	DECLARE_L3CLASS(CBF_Iron_Back_Log,XGMESLogic\\BFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBF_Iron_Back_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBFIron" name="BFID" type="L3STRING">
	/// 高炉炉号
	/// </Property>
	DECLARE_L3PROP_STRING(BFID)

	/// <Property class="CBFIron" name="TAP_No" type="L3STRING">
	/// 铁次号
	/// </Property>
	DECLARE_L3PROP_STRING(TAP_No)

	/// <Property class="CBFIron" name="TPC_No" type="L3STRING">
	/// 罐号
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

	
	/// <Property class="CBFIron" name="Source" type="L3LONG">
	/// 铁水来源
	/// (0:高炉
	/// 1:脱硫站)
	/// </Property>
	DECLARE_L3PROP_LONG(Source)

	
	/// <Property class="CBFIron" name="Destination" type="L3LONG">
	/// 去向
	// 0:未指定去向
	// 1:炼钢
	// 2:铸铁
	/// </Property>
	DECLARE_L3PROP_LONG(Destination)

	/// <Property class="CBFIron" name="Production_Date" type="L3DATETIME">
	/// 生产日期(进机时刻)
	/// </Property>
	DECLARE_L3PROP_DATETIME(Production_Date)

	
	/// <Property class="CBFIron" name="Shift" type="L3LONG">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_LONG(Shift)

	/// <Property class="CBFIron" name="Operator" type="L3STRING">
	/// 操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CBFIron" name="NC_Confirm_Flag" type="L3LONG">
	/// 已发电文标志
	/// (1:已发电
	///  0:未发电)
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Confirm_Flag)

	
	/// <Property class="CBFIron" name="Team" type="L3LONG">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_LONG(Team)

	/// <Property class="CBFIron" name="Result" type="L3LONG">
	/// 成分判定结果
	/// (1:合格
	///  2:不合格
	/// 0: 未判定)
	/// </Property>
	DECLARE_L3PROP_LONG(Result)

	/// <Property class="CBFIron" name="Sample_Place" type="L3STRING">
	/// 采样地点
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Place)

	/// <Property class="CBFIron" name="C" type="L3STRING">
	/// C成份
	/// </Property>
	DECLARE_L3PROP_STRING(C)

	/// <Property class="CBFIron" name="Si" type="L3STRING">
	/// Si成份
	/// </Property>
	DECLARE_L3PROP_STRING(Si)

	/// <Property class="CBFIron" name="Mn" type="L3STRING">
	/// Mn成份
	/// </Property>
	DECLARE_L3PROP_STRING(Mn)

	/// <Property class="CBFIron" name="S" type="L3STRING">
	/// S成份
	/// </Property>
	DECLARE_L3PROP_STRING(S)

	/// <Property class="CBFIron" name="P" type="L3STRING">
	/// P成份
	/// </Property>
	DECLARE_L3PROP_STRING(P)

	/// <Property class="CBFIron" name="Ti" type="L3STRING">
	/// Ti成份
	/// </Property>
	DECLARE_L3PROP_STRING(Ti)

	/// <Property class="CBFIron" name="Gross_Weight" type="L3FLOAT">
	/// 毛重
	/// </Property>
	DECLARE_L3PROP_FLOAT(Gross_Weight)

	/// <Property class="CBFIron" name="Last_Tare" type="L3FLOAT">
	/// 上次皮重
	/// </Property>
	DECLARE_L3PROP_FLOAT(Last_Tare)

	/// <Property class="CBFIron" name="Curr_Tare" type="L3FLOAT">
	/// 本次皮重
	/// </Property>
	DECLARE_L3PROP_FLOAT(Curr_Tare)

	/// <Property class="CBFIron" name="Net_Weight" type="L3FLOAT">
	/// 净重
	/// </Property>
	DECLARE_L3PROP_FLOAT(Net_Weight)

	/// <Property class="CBFIron" name="Spare_Weight" type="L3DOUBLE">
	/// 剩余重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spare_Weight)

	
	/// <Property class="CBFIron" name="IronStatus" type="L3LONG">
	/// 状态
	/// (0:未处理;
	/// 1:去向确认
	/// 2:到达确认;
	/// 3:已使用;
	/// 4:回退)
	/// </Property>
	DECLARE_L3PROP_LONG(IronStatus)

	/// <Property class="CBFIron" name="Arrival_Time" type="L3DATETIME">
	/// 到达时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CBFIron" name="Feed_Time" type="L3DATETIME">
	/// 兑入时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Feed_Time)

	/// <Property class="CBFIron" name="Send_Time" type="L3DATETIME">
	/// 送NC时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Send_Time)

	/// <Property class="CBFIron" name="SampCode" type="L3DATETIME">
	/// 试样编码
	/// </Property>
	DECLARE_L3PROP_STRING(SampCode)

	/// <Property class="CBFIron" name="IronConfirm" type="L3LONG">
	/// 已发电文标志
	/// (1:已确认
	///  0:未确认)
	/// </Property>
	DECLARE_L3PROP_LONG(IronConfirm)

	/// <Property class="CBFIron" name="C_B" type="L3STRING">
	/// 前C成份
	/// </Property>
	DECLARE_L3PROP_STRING(C_B)

	/// <Property class="CBFIron" name="Si_B" type="L3STRING">
	/// 前Si成份
	/// </Property>
	DECLARE_L3PROP_STRING(Si_B)

	/// <Property class="CBFIron" name="Mn_B" type="L3STRING">
	/// 前Mn成份
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_B)

	/// <Property class="CBFIron" name="S_B" type="L3STRING">
	/// 前S成份
	/// </Property>
	DECLARE_L3PROP_STRING(S_B)

	/// <Property class="CBFIron" name="P_B" type="L3STRING">
	/// 前P成份
	/// </Property>
	DECLARE_L3PROP_STRING(P_B)

	/// <Property class="CBFIron" name="Ti_B" type="L3STRING">
	/// 前Ti成份
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_B)

	/// <Property class="CBFIron" name="GrossFlag" type="L3LONG">
	/// 毛重标志
	/// </Property>
	DECLARE_L3PROP_LONG(GrossFlag)

	/// <Property class="CBFIron" name="TareFlag" type="L3LONG">
	/// 皮重标志
	/// </Property>
	DECLARE_L3PROP_LONG(TareFlag)

	/// <Property class="CBFIron" name="AnalysisFlag" type="L3LONG">
	/// 分析标志
	/// </Property>
	DECLARE_L3PROP_LONG(AnalysisFlag)

	/// <Property class="CBFIron" name="Operator_B" type="L3STRING">
	/// 检验员
	/// </Property>2009-04-23
	DECLARE_L3PROP_STRING(Operator_B)

	/// <Property class="CBFIron" name="Back_Operator" type="L3STRING">
	/// 回退操作人员
	/// </Property>
	DECLARE_L3PROP_STRING(Back_Operator)

	/// <Property class="CBFIron" name="Back_Team" type="L3STRING">
	/// 回退班别
	/// </Property>
	DECLARE_L3PROP_STRING(Back_Team)

	/// <Property class="CBFIron" name="Back_Shift" type="L3STRING">
	/// 回退班次
	/// </Property>
	DECLARE_L3PROP_STRING(Back_Shift)

	/// <Property class="CBFIron" name="Back_Shift" type="L3STRING">
	/// 回退时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Back_Time)

};

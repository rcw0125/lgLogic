// 逻辑类CBFIron头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "Material.h"

class CBFIron :
	public Material
{
public:
	CBFIron(void);
	virtual ~CBFIron(void);

	DECLARE_L3CLASS(CBFIron, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBFIron)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:
	// 铁水状态枚举
	enum _IronStatusEnum
	{
		ironNotProcessed = 0,			// 铁水未处理
		ironDestDefined = 1,			// 铁水已指定去向
		ironArrived = 2,				// 铁水已到达目的地
		ironProcessingAtDeS = 5,		// 铁水正在脱硫处理 2009-10-21 yao
	};
	
	/// 铁水去向枚举
	enum _IronDestEnum
	{
		ironToNoWhere = 0,				// 未指定去向
		ironToBOF = 1,					// 去炼钢
		ironToCast = 2,					// 去铸铁
	};

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

	//针对高炉铁水表CBFIron，在后台BFMag工程中在实体类新增元素Sn、Sb、As、Pb；
	//Modify by hyh 2012-03-28
	/// <Property class="CBFIron" name="C" type="L3STRING">
	/// Sn成份
	/// </Property>
	DECLARE_L3PROP_STRING(Sn)

	/// <Property class="CBFIron" name="Si" type="L3STRING">
	/// Sb成份
	/// </Property>
	DECLARE_L3PROP_STRING(Sb)

	/// <Property class="CBFIron" name="Mn" type="L3STRING">
	/// As成份
	/// </Property>
	DECLARE_L3PROP_STRING(As)

	/// <Property class="CBFIron" name="S" type="L3STRING">
	/// Pb成份
	/// </Property>
	DECLARE_L3PROP_STRING(Pb)
	//End

	//add by hyh 2012-08-13 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	/// <Property class="CQA_Iron_Element" name="Ni" type="L3STRING">
	/// Ni
	/// </Property>
	DECLARE_L3PROP_STRING(Ni)

	/// <Property class="CQA_Iron_Element" name="Mo" type="L3STRING">
	/// Mo
	/// </Property>
	DECLARE_L3PROP_STRING(Mo)

	/// <Property class="CQA_Iron_Element" name="Cu" type="L3STRING">
	/// Cu
	/// </Property>
	DECLARE_L3PROP_STRING(Cu)

	/// <Property class="CQA_Iron_Element" name="Cr" type="L3STRING">
	/// Cr
	/// </Property>
	DECLARE_L3PROP_STRING(Cr)

	/// <Property class="CQA_Iron_Element" name="B" type="L3STRING">
	/// B
	/// </Property>
	DECLARE_L3PROP_STRING(B)

	/// <Property class="CQA_Iron_Element" name="V" type="L3STRING">
	/// V
	/// </Property>
	DECLARE_L3PROP_STRING(V)

	/// <Property class="CQA_Iron_Element" name="Al" type="L3STRING">
	/// Al
	/// </Property>
	DECLARE_L3PROP_STRING(Al)

	/// <Property class="CQA_Iron_Element" name="Nb" type="L3STRING">
	///Nb
	/// </Property>
	DECLARE_L3PROP_STRING(Nb)

	/// <Property class="CQA_Iron_Element" name="Zn" type="L3STRING">
	/// Zn
	/// </Property>
	DECLARE_L3PROP_STRING(Zn)

	/// <Property class="CQA_Iron_Element" name="W" type="L3STRING">
	/// W
	/// </Property>
	DECLARE_L3PROP_STRING(W)
	//end

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
	/// 4:回退;
	/// 5:脱硫处理 2009-10-21)
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

	//Modify by hyh 2012-03-28
	/// <Property class="CBFIron" name="Sn_B" type="L3STRING">
	/// 前Sn成份
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_B)

	/// <Property class="CBFIron" name="Sb_B" type="L3STRING">
	/// 前Sb成份
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_B)

	/// <Property class="CBFIron" name="As_B" type="L3STRING">
	/// 前As成份
	/// </Property>
	DECLARE_L3PROP_STRING(As_B)

	/// <Property class="CBFIron" name="Pb_B" type="L3STRING">
	/// 前Pb成份
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_B)
	//End

	//add by hyh 2012-08-13 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	/// <Property class="CQA_Iron_Element" name="Ni" type="L3STRING">
	/// Ni
	/// </Property>
	DECLARE_L3PROP_STRING(Ni_B)

	/// <Property class="CQA_Iron_Element" name="Mo" type="L3STRING">
	/// Mo
	/// </Property>
	DECLARE_L3PROP_STRING(Mo_B)

	/// <Property class="CQA_Iron_Element" name="Cu" type="L3STRING">
	/// Cu
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_B)

	/// <Property class="CQA_Iron_Element" name="Cr" type="L3STRING">
	/// Cr
	/// </Property>
	DECLARE_L3PROP_STRING(Cr_B)

	/// <Property class="CQA_Iron_Element" name="B" type="L3STRING">
	/// B
	/// </Property>
	DECLARE_L3PROP_STRING(B_B)

	/// <Property class="CQA_Iron_Element" name="V" type="L3STRING">
	/// V
	/// </Property>
	DECLARE_L3PROP_STRING(V_B)

	/// <Property class="CQA_Iron_Element" name="Al" type="L3STRING">
	/// Al
	/// </Property>
	DECLARE_L3PROP_STRING(Al_B)

	/// <Property class="CQA_Iron_Element" name="Nb" type="L3STRING">
	///Nb
	/// </Property>
	DECLARE_L3PROP_STRING(Nb_B)

	/// <Property class="CQA_Iron_Element" name="Zn" type="L3STRING">
	/// Zn
	/// </Property>
	DECLARE_L3PROP_STRING(Zn_B)

	/// <Property class="CQA_Iron_Element" name="W" type="L3STRING">
	/// W
	/// </Property>
	DECLARE_L3PROP_STRING(W_B)
	//end

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

	/// <Property class="CBFIron" name="DeSFlag" type="L3LONG">
	/// 脱硫标志
	/// </Property>
	DECLARE_L3PROP_LONG(DeSFlag)

	/// <Property class="CDeS_Base_Data" name="DeSType" type="L3LONG">
	/// 脱硫类型
	/// (1:浅脱硫
	///  2:标准脱硫
	///  3:深脱硫
	///  4:超深脱硫
	///  5:捞渣)
	/// </Property>
	DECLARE_L3PROP_LONG(DeSType)
};
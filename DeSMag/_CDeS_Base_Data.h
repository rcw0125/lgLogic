// 逻辑类CDeS_Base_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDeS_Base_Data :
	public CL3Object
{
public:
	CDeS_Base_Data(void);
	virtual ~CDeS_Base_Data(void);

	// 铁水状态枚举
	enum _IronStatusEnum
	{
		ironPrepare = 1,			// 准备脱硫
		ironArrived = 2,			// 铁罐进站
		ironBeginPreRemoveSlag = 3,	// 预捞渣开始
		ironEndPreRemoveSlag = 4,	// 预捞渣结束
		ironBeginSpray = 5,			// 喷吹开始
		ironEndSpray = 6,			// 喷吹结束
		ironBeginRemoveSlag = 7,	// 捞渣开始
		ironEndRemoveSlag = 8,	    // 捞渣结束
		ironDepart = 9,			    // 铁罐出站
		ironUsed = 10,			    // 铁水已使用
		ironUndo = 11,			    // 铁水回退
	};


	DECLARE_L3CLASS(CDeS_Base_Data,XGMESLogic\\DeSMag, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Base_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDeS_Base_Data" name="MaterialID" type="L3STRING">
	/// 物料标识
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID)

	/// <Property class="CDeS_Base_Data" name="TAP_No" type="L3STRING">
	/// 铁次号
	/// </Property>
	DECLARE_L3PROP_STRING(TAP_No)

	/// <Property class="CDeS_Base_Data" name="TPC_No" type="L3STRING">
	/// 罐号
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

	/// <Property class="CDeS_Base_Data" name="DeS_UnitID" type="L3STRING">
	/// 脱硫工位
	/// </Property>
	DECLARE_L3PROP_STRING(DeS_UnitID)

	/// <Property class="CDeS_Base_Data" name="RemoveSlag_UnitID" type="L3STRING">
	/// 捞渣工位
	/// </Property>
	DECLARE_L3PROP_STRING(RemoveSlag_UnitID)

	/// <Property class="CDeS_Base_Data" name="DeS_Operator" type="L3STRING">
	/// 脱硫工
	/// </Property>
	DECLARE_L3PROP_STRING(DeS_Operator)

	/// <Property class="CDeS_Base_Data" name="RemoveSlag_Operator" type="L3STRING">
	/// 捞渣工
	/// </Property>
	DECLARE_L3PROP_STRING(RemoveSlag_Operator)

	/// <Property class="CDeS_Base_Data" name="DeS_Flag" type="L3LONG">
	/// 脱硫标志
	/// </Property>
	DECLARE_L3PROP_LONG(DeS_Flag)

	/// <Property class="CDeS_Base_Data" name="ProductionDate" type="L3DATETIME">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProductionDate)

	/// <Property class="CDeS_Base_Data" name="PreRemoveSlagTime" type="L3LONG">
	/// 预捞渣用时
	/// </Property>
	DECLARE_L3PROP_LONG(PreRemoveSlagTime)

	/// <Property class="CDeS_Base_Data" name="RemoveSlagTime" type="L3LONG">
	/// 捞渣用时
	/// </Property>
	DECLARE_L3PROP_LONG(RemoveSlagTime)

	/// <Property class="CDeS_Process_Data" name="BlowTimeTotal" type="L3LONG">
	/// 喷吹用时
	/// </Property>
	DECLARE_L3PROP_LONG(BlowTimeTotal)

	/// <Property class="CDeS_Process_Data" name="ProcessTime" type="L3LONG">
	/// 作业时间
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessTime)

	/// <Property class="CDeS_Base_Data" name="RemoveSlagCount" type="L3LONG">
	/// 捞渣次数
	/// </Property>
	DECLARE_L3PROP_LONG(RemoveSlagCount)

	/// <Property class="CDeS_Process_Data" name="Gross_Weight" type="L3DOUBLE">
	/// 毛重
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gross_Weight)

	/// <Property class="CDeS_Process_Data" name="Estimate_Weight" type="L3DOUBLE">
	/// 铁水预测重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Estimate_Weight)

	/// <Property class="CDeS_Process_Data" name="Net_Weight" type="L3DOUBLE">
	/// 净重
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Net_Weight)

	/// <Property class="CDeS_Base_Data" name="DeSType" type="L3SHORT">
	/// 脱硫类型
	/// (1:浅脱硫
	///  2:标准脱硫
	///  3:深脱硫
	///  4:超深脱硫
	///  5:捞渣)
	/// </Property>
	DECLARE_L3PROP_SHORT(DeSType)

	/// <Property class="CDeS_Process_Data" name="Mat_Consume" type="L3DOUBLE">
	/// 颗粒镁消耗
	/// (多次喷吹之和)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mat_Consume)

	/// <Property class="CDeS_Process_Data" name="Weight_MatTank" type="L3DOUBLE">
	/// 储料罐重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_MatTank)

	/// <Property class="CDeS_Process_Data" name="Weight_SprayTank" type="L3DOUBLE">
	/// 喷吹罐重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_SprayTank)

	/// <Property class="CDeS_Base_Data" name="Status" type="L3SHORT">
	/// 状态
	/// (1:准备脱硫;
	///  2:铁罐进站;
	///  3:预捞渣开始;
	///  4:预捞渣结束;
	///  5:喷吹开始;
	///  6:喷吹结束;
	///  7:捞渣开始;
	///  8:捞渣结束;
	///  9:铁罐出站;
	///  10:铁水已使用
	///  11:铁水回退)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CDeS_Process_Data" name="Destination" type="L3LONG">
	/// 去向
	/// (0:未指定;
	///  1:混铁炉;
	///  2:炼铁)
	/// </Property>
	DECLARE_L3PROP_LONG(Destination)

	/// <Property class="CDeS_Base_Data" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDeS_Base_Data" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDeS_Base_Data" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CDeS_Base_Data" name="Locked" type="L3SHORT">
	/// 
	/// 封存标志(0:未锁定
	///                  1:锁定[不允许数据变更])
	/// </Property>
	DECLARE_L3PROP_SHORT(Locked)

	/// <Property class="CDeS_Base_Data" name="SampleApplyCout_B" type="L3SHORT">
	/// 脱硫前样申请次数
	/// </Property>
	DECLARE_L3PROP_SHORT(SampleApplyCount_B)

	/// <Property class="CDeS_Base_Data" name="SampleApplyCout_A" type="L3SHORT">
	/// 脱硫后样申请次数
	/// </Property>
	DECLARE_L3PROP_SHORT(SampleApplyCount_A)

	/// <Property class="CDeS_Base_Data" name="Mediator" type="L3STRING">
	/// 协调人
	/// </Property>
	DECLARE_L3PROP_STRING(Mediator)

	/// <Property class="CDeS_Process_Data" name="TotalTime" type="L3LONG">
	/// 全程用时
	/// </Property>
	DECLARE_L3PROP_LONG(TotalTime)
};

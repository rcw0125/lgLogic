// 逻辑类CMIF_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMIF_Mag :
	public CL3Object
{
public:
	CMIF_Mag(void);
	virtual ~CMIF_Mag(void);

	DECLARE_L3CLASS(CMIF_Mag,XGMESLogic\\MIXFMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Mag)
	DECLARE_L3EVENTSINK_MAP()
 
	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:
	// 兑铁算法工具函数。用于将多条铁水信息兑入一条新的铁水信息
	static BOOL MixIrons(L3RECORDSET rsIrons,L3RECORDSET rsTarget);

	/// <Method class="CMIF_Mag" name="DirectFeedIron" type="L3STRING">
	/// 将多个原铁包的铁水兑入目标铁包，产生新的铁水材料。返回新铁水材料的MaterialID。
	/// <Param name="TargetLadle" type="L3STRING">目标铁包号</Param>
	/// <Param name="rsIron" type="L3RECORDSET">将兑入铁包的原铁水信息</Param>
	/// </Method>
	L3STRING DirectFeedIron(L3STRING TargetLadle, L3RECORDSET rsIron);
	/// <Method class="CMIF_Mag" name="GetUnArrivedIrons" type="L3RECORDSET">
	/// 返回去向为炼钢但未到达的铁水信息
	/// </Method>
	L3RECORDSET GetUnArrivedIrons();
	/// <Method class="CMIF_Mag" name="GetIncomingIrons" type="L3RECORDSET">
	/// 返回到达混铁炉工序前的铁水信息
	/// </Method>
	L3RECORDSET GetIncomingIrons();
	/// <Method class="CMIF_Mag" name="GetOutgoingIrons" type="L3RECORDSET">
	/// 返回直兑和混铁炉出铁的铁水信息。
	/// </Method>
	L3RECORDSET GetOutgoingIrons();
	L3RECORDSET GetOutgoingIrons2();
	/// <Method class="CMIF_Unit_Mag" name="GetHotIronLadles" type="L3RECORDSET">
	/// 获取当前热备铁包
	/// </Method>
	L3RECORDSET GetHotIronLadles();
	/// <Method class="CMIF_Mag" name="BackBFIron" type="L3LONG">
	/// 回退高炉铁水
	/// <Param name="dsIron" type="L3RECORDSET">回退铁水信息</Param>
	/// </Method>
	L3LONG BackBFIron(L3RECORDSET dsIron);

	/// <Method class="CMIF_Mag" name="OutputIronCancel" type="L3LONG">
	/// 取消直兑铁水2009-04-19
	/// </Method>
	L3LONG OutputIronCancel(L3RECORDSET rsLadleID);

	/// <Method class="CMIF_Mag" name="OnDoFeedIron" type="L3BOOL">
	/// 回退直兑铁水2009-04-19
	/// </Method>
	L3BOOL OnDoFeedIron(CString strMaterialID);

	/// <Method class="CMIF_Mag" name="SetIsDes" type="L3BOOL">
	/// 人工设置是否脱硫
	/// </Method>
	L3LONG SetIsDes(L3RECORDSET rsIsDes);
};

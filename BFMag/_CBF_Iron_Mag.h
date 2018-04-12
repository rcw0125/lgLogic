// 逻辑类CBF_Iron_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialStore.h"

class CBF_Iron_Mag :
	public MaterialStore
{
public:
	CBF_Iron_Mag(void);
	virtual ~CBF_Iron_Mag(void);

	DECLARE_L3CLASS(CBF_Iron_Mag,XGMESLogic\\BFMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBF_Iron_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

protected:

	/// <summary>
	/// 返回入库缓冲区的URI
	/// </summary>
	virtual CString GetInputCache();
	/// <summary>
	/// 返回出库缓冲区的URI
	/// </summary>
	virtual CString GetOutputCache();
	/// <summary>
	/// 返回入库记录类型名称
	/// </summary>
	virtual CString GetInputLogType();
	/// <summary>
	/// 返回出库记录类型名称
	/// </summary>
	virtual CString GetOutputLogType();
	/// <summary>
	/// 返回库位类型名称
	/// </summary>
	virtual CString GetStoreAreaType();

	/// <summary>
	///	初始化库房的属性
	/// </summary>
	virtual BOOL InitializeStoreProperties();
	/// <summary>
	/// 填充库位的初始化数据
	/// </summary>
	virtual BOOL GetInitialAreaData(CL3RecordSetWrap& rs);
	/// <summary>
	/// 在库房初始完成后调用。继承类重载此函数进行额外的初始化工作。
	/// </summary>
	virtual void OnAfterStoreInitialized();

	/// <summary>
	/// 入库前预处理。在入库操作前调用。继承类可重载此方法进行预先的数据准备和处理
	/// ARG >> rsInputInfo : 入库信息记录。
	/// RET << TRUE 继续入库；FALSE 中断入库
	/// </summary>
	virtual BOOL OnBeforeInputMaterials(L3RECORDSET rsInputInfo);
	/// <summary>
	/// 入库后续处理。在入库操作成功后调用。继承类可重载此方法进行额外的处理。
	/// ARG >> rsInputInfo : 入库信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE；
	/// </summary>
	virtual BOOL OnAfterMaterialsInputted(L3RECORDSET rsInputInfo);
	/// <summary>
	/// 出库前预处理。在出库操作前调用。继承类可重载此方法进行预先的数据准备和处理
	/// ARG >> rsOutputInfo : 出库信息记录。
	/// RET << TRUE 继续出库；FALSE 中断出库
	/// </summary>
	virtual BOOL OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo);
	/// <summary>
	/// 出库后续处理。在出库操作成功后调用。继承类可重载此方法进行额外的处理。
	/// ARG >> rsOutputInfo : 出库信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE；
	/// </summary>
	virtual BOOL OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo);
	/// <summary>
	/// 人工增加库存前预处理。在进行人工增加库存前调用。继承类可重载此方发进行预先数据准备和处理
	/// ARG	>> rsMaterialInfo : 新增材料信息记录。
	/// RET << 返回TRUE继续处理；返回FALSE中断。
	/// </summary>
	virtual BOOL OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo);
	/// <summary>
	/// 人工增加库存后续处理。在进行人工增加库存后调用。继承类可重载此方法进行额外处理。
	/// ARG >> rsMaterialInfo : 新增的材料信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo);
	/// <summary>
	/// 人工删除库存前预处理。在进行人工删除库存前调用。继承类可重载此方发进行预先数据准备和处理
	/// ARG	>> rsMaterialInfo : 删除材料信息记录。
	/// RET << 返回TRUE继续处理；返回FALSE中断。
	/// </summary>
	virtual BOOL OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo);
	/// <summary>
	/// 人工删除库存后续处理。在进行人工删除库存后调用。继承类可重载此方法进行额外处理。
	/// ARG >> rsMaterialInfo : 删除的材料信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo);

	//tangyi 2007-12-09
	/// <summary>
	/// 移库前导处理。
	/// ARG >> rsMaterialInfo : 删除的材料信息记录。
	/// RET << 返回TRUE继续处理；返回FALSE中断。
	/// </summary>
	virtual BOOL OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 移库后续处理。
	/// ARG >> rsMaterialInfo : 删除的材料信息记录。
	/// RET << << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 入库记录预处理。继承类可重载此方法在入库前检查或处理入库记录
	/// </summary>
	virtual void PrepareInputLog(L3RECORDSET rsInputLog);
	/// <summary>
	/// 出库记录预处理。继承类可重载此方法在出库前检查或处理出库记录
	/// </summary>
	virtual void PrepareOutputLog(L3RECORDSET rsOutputLog);

	/// <summary>
	/// 返回指定编号的库位对象的URI
	/// </summary>
	virtual CString GetAreaURI(LPCTSTR lpcszAreaID);

	/// <Method class="CBF_Iron_Mag" name="NewIronData" type="L3LONG">
	/// 
	/// 新增铁水数据
	/// ARG&gt;&gt; rsIron : 铁水数据。必须包含BFID,TAP_No,TPC_No,Source字段。
	/// RET &lt;&lt; 成功返回1；失败返回出错代码。
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewIronData(L3RECORDSET rsIron);
	/// <Method class="CBF_Iron_Mag" name="ModifyIronData" type="L3LONG">
	/// 修改铁水数据
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyIronData(L3RECORDSET rsIron);
	/// <Method class="CBF_Iron_Mag" name="DeleteIronData" type="L3LONG">
	/// 删除铁水数据
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteIronData(L3RECORDSET rsIron);
	/// <Method class="CBF_Iron_Mag" name="DesignatePath" type="L3LONG">
	/// 铁水去向指定
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DesignatePath(L3RECORDSET rsIron);
	/// <Method class="CBF_Iron_Mag" name="SendIronDataToNC" type="L3LONG">
	/// 铁水上传NC
	/// <Param name="strTapNo" type="L3STRING"></Param>
	/// </Method>
    L3LONG SendIronDataToNC(L3STRING strTapNo);
	
	/// <Method class="CBF_Iron_Mag" name="GetUnprocessedIrons" type="L3RECORDSET">
	/// 返回未处理的铁水数据
	/// </Method>
	L3RECORDSET GetUnprocessedIrons();
	/// <Method class="CBF_Iron_Mag" name="GetIronsForDefineDest" type="L3RECORDSET">
	/// 返回未到达的铁水
	/// </Method>
	L3RECORDSET GetIronsForDefineDest();
	/// <Method class="CBF_Iron_Mag" name="SendIronInfoToNC" type="L3LONG">
	/// 发送铁水记录到NC
	/// <Param name="rsIrons" type="L3RECORDSET">要发送的铁水数据</Param>
	/// </Method>
	//L3LONG SendIronInfoToNC(L3RECORDSET rsIrons);

	/// <Method class="CBF_Iron_Mag" name="QueryIronInfo" type="L3RECORDSET">
	/// 根据时间段和去向查铁水信息
	/// <Param name="timeFrom" type="L3DATETIME">起始时间</Param>
	/// <Param name="timeTo" type="L3DATETIME">结束时间</Param>
	/// <Param name="Destination" type="L3LONG">去向</Param>
	/// </Method>
	L3RECORDSET QueryIronInfo(L3DATETIME timeFrom, L3DATETIME timeTo, L3LONG Destination);
	/// <Method class="CBF_Iron_Mag" name="GetMaxTAPNoByBFID" type="L3RECORDSET">
	/// 按高炉分组获取最大铁次号。返回记录集包含字段BFID和TAP_No。
	/// </Method>
	L3RECORDSET GetMaxTAPNoByBFID();
	/// <Method class="CBF_Iron_Mag" name="GetLastTareWeightByTPCNo" type="L3DOUBLE">
	/// 根据罐号查询最近一次的皮重。
	/// <Param name="nTPCNo" type="L3STRING">罐号</Param>
	/// </Method>
	L3DOUBLE GetLastTareWeightByTPCNo(L3STRING nTPCNo);
	/// <Method class="CBF_Iron_Mag" name="GetUnArrivedIrons" type="L3RECORDSET">
	/// 返回已指定去向，但未到达确认的铁水数据。
	/// <Param name="Destination" type="L3LONG">去向</Param>
	/// </Method>
	L3RECORDSET GetUnArrivedIrons(L3LONG Destination);
	/// <Method class="CBF_Iron_Mag" name="ConfirmIronArrive" type="L3BOOL">
	/// 确认铁水到达。根据去向进行不同的处理。
	/// <Param name="rsIron" type="L3RECORDSET">确认已经到达的铁水记录</Param>
	/// </Method>
	L3BOOL ConfirmIronArrive(L3RECORDSET rsIron);

	/// <Method class="CBF_Iron_Mag" name="SetIrongTare" type="L3LONG">
	/// 设置铁次罐号皮重
	/// <Param name="strTapNo" type="L3STRING"></Param>
	/// <Param name="strTpcNo" type="L3STRING"></Param>
	/// <Param name="fTare" type="L3FLOAT"></Param>
	/// </Method>
	L3LONG SetIronTare(L3STRING strTapNo,L3STRING strTpcNo,L3FLOAT fTare);

	/// <Method class="CBF_Iron_Mag" name="GetBFChemicalData" type="L3RECORDSET">
	/// 通过铁次罐号获取铁水成份数据。
	/// <Param name="strTapNo" type="L3STRING">铁次号</Param>
	/// <Param name="strTpcNo" type="L3STRING">罐号</Param>
	/// </Method>
	L3RECORDSET GetBFChemicalData(L3STRING strTapNo,L3STRING strTpcNo);


	/// <Property class="CBF_Iron_Mag" name="EventIronChanged" type="L3LONG">
	/// 铁水数据变更事件
	/// </Property>
	DECLARE_L3PROP_LONG(EventIronChanged)

	/// <Method class="CBF_Iron_Mag" name="NewIronInfo" type="L3LONG">
	/// 新增铁水信息
	/// ARG&gt;&gt; rsIron : 铁水信息。必须包含TAP_No,TPC_No字段。
	/// RET &lt;&lt; 成功返回1；失败返回出错代码。
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewIronInfo(L3RECORDSET rsData);

	//L3LONG RetoLab(L3RECORDSET rsData);

	/// <Method class="CBF_Iron_Mag" name="AcceptWeightData" type="L3BOOL">
	/// 接收铁水罐重量数据 2009-03-30
	/// <Param name="rsData" type="L3RECORDSET">重量数据</Param>
	/// </Method>
	L3BOOL AcceptWeightData(L3RECORDSET rsData);

/// <Method class="CBF_Iron_Mag" name="Complete" type="L3BOOL">
	/// 铁水完工 2009-03-30
	/// <Param name="rsData" type="L3RECORDSET">重量数据</Param>
	/// </Method>
	L3BOOL Complete(L3STRING strID);

	/// <Method class="CBF_Iron_Mag" name="SendIronDataToWeight" type="L3BOOL">
	/// 将高拉碳炉终样下传PLC 2009-03-21
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL  SendIronDataToWeight(LPCTSTR strTapNo,LPCTSTR strTpcNo);

	/// <Method class="CBF_Iron_Mag" name="SendBackIrons" type="L3LONG">
	/// 未到达铁水回退
	/// <Param name="rsIrons" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SendBackIrons(L3RECORDSET rsIrons);

	/// <Method class="CBF_Iron_Mag" name="SendBackArrivedIrons" type="L3LONG">
	/// 已到达铁水回退
	/// <Param name="rsIrons" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SendBackArrivedIrons(L3RECORDSET rsIrons);

	/// <Method class="CBF_Iron_Mag" name="SendIronToCast" type="L3BOOL">
	/// 设置铁水去铸铁
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL SendIronToCast(L3RECORDSET rsIron);

	/// <Method class="CBF_Iron_Mag" name="MarkIronSource" type="L3LONG">
	/// 标识铁水来源
	/// <Param name="rsIrons" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MarkIronSource(L3RECORDSET rsIrons);

	/// <Method class="CBF_Iron_Mag" name="GetUnprocessSampIrons" type="L3RECORDSET">
	/// add by hyh 2012-04-12
	/// 用于前台钢种成分报警显示铁水成分
	/// </Method>
	L3RECORDSET GetUnprocessSampIrons();
};

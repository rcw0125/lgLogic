// 逻辑类CLF_Unit_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProduceUnit.h"

class CRHL_Unit_Mag :
	public ProduceUnit
{
public:
	CRHL_Unit_Mag(void);
	virtual ~CRHL_Unit_Mag(void);

	DECLARE_L3CLASS(CRHL_Unit_Mag,XGMESLogic\\RHLMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRHL_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:
	enum _LFStatus
	{
		// 正常状态
		LFWaiting = 0,		// 等待
		LFProcBegin = 1,	// 处理开始
		LFHeatBegin = 2,	// 开始加热
		LFHeatEnd = 3,		// 加热结束
		LFProcEnd = 4,		// 处理结束
		LFBlowBegin = 5,	// 软吹开始
		LFBlowEnd = 6,		// 软吹结束
	};

	//2009-03-02 tangyi
	enum _LFEquipStatus
	{
		// 异常状态
		LFNormal = 0,       //正常
		LFRepair = -1,		// 检修
		LFBushing = -2,		// 套管
		LFMaintain = -3,	// 护炉
		LFFailure = -4,		// 故障
	};



protected:

	CString csDischargeUnit;

	/// <summary>
	/// 返回机组的加工区域
	/// ARG << lstURIs : 接收所有加工区对象的URI
	/// </summary>
	virtual BOOL GetProduceAreas(CStringList& lstURIs);

	/// <summary>
	/// 获取指定生产区域的后续区域的URI
	/// ARG >> lpcszCurArea : 当前生产区域的URI。
	///		>> rsMaterialInfo : 材料信息，用于辅助判断。包含MaterialType,MaterialID,Amount,等材料信息。
	///							注意：应该只用该记录集的当前行进行判断！！！
	/// RET << 返回后续生产区域的URI。返回空表示当前生产区域已经是机组的出口了。
	/// </summary>
	virtual CString GetNextProduceArea(LPCTSTR lpcszCurArea,L3RECORDSET rsMaterialInfo) { return _T(""); };

	/// <summary>
	/// 获取指定生产区域的前导区域的URI
	/// ARG >> lpcszCurArea : 当前生产区域的URI。
	///		>> rsMaterialInfo : 材料信息，用于辅助判断。包含MaterialType,MaterialID,Amount,等材料信息。
	///							注意：应该只用该记录集的当前行进行判断！！！
	/// RET << 返回前导生产区域的URI。返回空表示当前生产区域已经是机组的入口了。
	/// </summary>
	virtual CString GetPrevProduceArea(LPCTSTR lpcszCurArea,L3RECORDSET rsMaterialInfo) { return _T(""); };

	/// <summary>
	/// 得到机组前序材料缓冲区的URI
	/// </summary>
	virtual CString GetInputCache();

	/// <summary>
	/// 得到机组后继材料缓冲区的URI
	/// </summary>
	virtual CString GetOutputCache();

	/// <summary>
	/// 机组上料前预处理。在机组上料前调用，继承类可重载此方法进行预先数据准备和处理。
	/// ARG >> rsMaterialInfo : 材料信息记录集。
	/// RET << 返回TRUE继续上料；返回FALSE中断上料。
	/// </summary>
	virtual BOOL OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 机组上料后续处理。在机组上料后调用，继承类可重载此方法进行额外处理。
	/// ARG >> rsMaterialInfo : 材料信息记录集。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 返回机组上料记录的类型URI
	/// </summary>
	virtual CString GetFeedingLogType();

	/// <summary>
	/// 准备上料记录数据。继承类可重载此函数进行额外的数据处理。
	/// ARG >> rsFeedingLogs : 上料记录信息。
	/// RET << void
	/// </summary>
	virtual void PrepareFeedingLogs(L3RECORDSET rsFeedingLogs);

	/// <summary>
	/// 加工参数预处理。在调用加工区域的加工方法前调用，继承类可重载此函数对加工参数进行修改和配置。
	/// ARG >> lpcszArea : 加工区域的URI
	///		>> rsParameters : 加工参数记录集。
	/// RET << 返回TRUE继续加工；返回FALSE中断加工。
	/// </summary>
	virtual BOOL PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters);

	/// <summary>
	/// 加工完成后续处理。在加工完成后调用，继承类可重载此函数进行额外逻辑处理
	/// ARG >> lpcszArea : 加工区域的URI
	///		>> nProcessType : 加工的类型。
	///		>> rsProducts : 加工产生的产品的信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts);

	/// <summary>
	/// 下线前预处理。在执行下线操作前调用，继承类可重载此函数进行预先的数据准备和处理。
	/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
	/// RET << 返回TRUE继续下线；返回FALSE中断下线。
	/// </summary>
	virtual BOOL OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 下线后续处理。在执行下线操作后调用，继承类可重载此函数进行额外处理。
	/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 返回机组产出记录的类型URI
	/// </summary>
	virtual CString GetDeliveryLogType();

	/// <summary>
	/// 准备下料记录数据。
	/// ARG >> rsDeliveryLog : 下料记录数据。
	/// RET <<void
	/// </summary>
	virtual void PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog);

	/// <summary>
	/// 返回本机组的通讯器对象的URI
	/// </summary>
	virtual CString GetCommunicator();

	/// <summary>
	/// 准备计划数据，以便向机组下位系统发送。
	/// ARG >> lpcszPlanType : 计划类型。
	///		>> rsPlan : 计划数据。包括PlanID字段。
	///		<< rsSend : 接收准备好的计划发送数据。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend);

	/// <summary>
	/// 计划下达后续处理。在向下位系统发送计划后调用，继承类可重载此函数进行后续处理。
	/// ARG >> rsSend : 下发下位系统的计划数据。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterPlansSent(L3RECORDSET rsSend);

	/// <summary>
	/// 准备计划数据，以便通知机组下位系统取消计划。
	/// ARG >> lpcszPlanType : 计划类型。
	///		>> rsPlan : 计划数据。包括PlanID字段。
	///		<< rsSend : 接收准备好的计划取消数据。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel);

	/// <summary>
	/// 计划取消后续处理。在向下位系统发送取消计划后调用，继承类可重载此函数进行后续处理。
	/// ARG >> rsCancel : 下发下位系统的计划取消数据。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterPlansCanceled(L3RECORDSET rsCancel);

	/// <summary>
	/// 处理材料上线的事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleMaterialFeedingEvent(MatEnterArea *pEvt);
	/// <summary>
	/// 处理材料进入加工区域的事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleMaterialEnterAreaEvent(MatEnterArea *pEvt);
	/// <summary>
	/// 处理材料离开加工区域事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt);
	/// <summary>
	/// 处理材料生产完毕事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleMaterialProducedEvent(MatProduced *pEvt);
	/// <summary>
	/// 处理机组测量数据变更事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleUnitMeasureChangedEvent(UnitMeasure *pEvt);

	/// <Property class="CLF_Unit_Mag" name="TreatNo" type="L3STRING">
	/// 当前处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Unit_Mag" name="NextTreatNo" type="L3STRING">
	/// 下一处理号
	/// </Property>
	DECLARE_L3PROP_STRING(NextTreatNo)

	/// <Property class="CLF_Unit_Mag" name="Status" type="L3LONG">
	/// 机组状态
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CLF_Unit_Mag" name="NextSteel" type="L3STRING">
	/// 下一个上线的钢水
	/// </Property>
	DECLARE_L3PROP_STRING(NextSteel)

	/// <Property class="CLF_Unit_Mag" name="CurArea" type="L3STRING">
	/// 当前正在处理的工位
	/// </Property>
	DECLARE_L3PROP_STRING(CurArea)

	/// <Property class="CLF_Unit_Mag" name="ProcStartTime" type="L3DATETIME">
	/// 开始处理时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProcStartTime)

	/// <Property class="CLF_Unit_Mag" name="ProcStopTime" type="L3DATETIME">
	/// 结束处理时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProcStopTime)

	/// <Property class="CLF_Unit_Mag" name="HeatStartTime" type="L3DATETIME">
	/// 开始加热时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(HeatStartTime)

	/// <Property class="CLF_Unit_Mag" name="ProcTime" type="L3LONG">
	/// 已处理时间
	/// </Property>
	DECLARE_L3PROP_LONG(ProcTime)


	/// <Property class="CLF_Unit_Mag" name="StartProcessTime" type="L3STRING">
	/// 处理开始时间
	/// </Property>
	DECLARE_L3PROP_STRING(StartProcessTime)


	/// <Property class="CLF_Unit_Mag" name="WeightingSteel" type="L3STRING">
	/// 等待称重的钢水号
	/// </Property>
	DECLARE_L3PROP_STRING(WeightingSteel)

	/// <Property class="CLF_Unit_Mag" name="CurTemp" type="L3DOUBLE">
	/// 当前温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CurTemp)

	/// <Property class="CLF_Unit_Mag" name="ReSampleHeatID" type="L3STRING">
	/// 重取样通知炉号
	/// </Property>
	DECLARE_L3PROP_STRING(ReSampleHeatID)

	/// <Property class="CLF_Unit_Mag" name="Lid_Life" type="L3LONG">
	/// 炉盖寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Lid_Life)

	/// <Property class="CLF_Unit_Mag" name="PoleConsume" type="L3LONG">
	/// 电极消耗
	/// </Property>
	DECLARE_L3PROP_LONG(PoleConsume)

	/// <Property class="CLF_Unit_Mag" name="Equip_Status" type="L3LONG">
	/// 设备状态
	/// </Property> 2009-03-02设备状态 tangyi
	DECLARE_L3PROP_LONG(Equip_Status)

	/// <Property class="CLF_Unit_Mag" name="Pole_Vendor" type="L3STRING">
	/// 电极厂家
	/// </Property> 2009-03-19
	DECLARE_L3PROP_STRING(Pole_Vendor)
	
	/// <Property class="CLF_Unit_Mag" name="Probe_Vendor" type="L3STRING">
	/// 探头厂家
	/// </Property> 2009-03-19
	DECLARE_L3PROP_STRING(Probe_Vendor)

	/// <Property class="CLF_Unit_Mag" name="PrevArea" type="L3STRING">
	/// 处理结束后的工位
	/// </Property>
	DECLARE_L3PROP_STRING(PrevArea)

	/// 计算下一处理号
	CString CalculateNextTreatNo(LPCTSTR lpcszTreatNo);
	
	/// 通用过程状态修改函数
	BOOL ChangeStatus(LONG nStatus);

	/// 通用计划状态修改函数
	BOOL ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status);

	/// <Method class="CLF_Unit_Mag" name="GetInputSteels" type="L3RECORDSET">
	/// 返回入口区域的待处理钢水信息。
	/// </Method>
	L3RECORDSET GetInputSteels();
	/// <Method class="CLF_Unit_Mag" name="DesignateForWeighting" type="L3BOOL">
	/// 指定即将称重的钢水炉号。
	/// <Param name="MaterialID" type="L3STRING">即将称重的钢水号</Param>
	/// </Method>
	L3BOOL DesignateForWeighting(L3STRING MaterialID);
	/// <Method class="CLF_Unit_Mag" name="SetWeight" type="L3BOOL">
	/// 处理称重信号。
	/// <Param name="fWeight" type="L3DOUBLE">重量</Param>
	/// </Method>
	L3BOOL SetWeight(L3DOUBLE fWeight);
	/// <Method class="CLF_Unit_Mag" name="DesignateLadle" type="L3BOOL">
	/// 为A、B工位指定即将到达的钢水。
	/// <Param name="Area" type="L3STRING">工位码：A，B</Param>
	/// <Param name="MaterialID" type="L3STRING">钢水炉号</Param>
	/// </Method>
	L3BOOL DesignateLadle(L3STRING Area, L3STRING MaterialID);
	/// <Method class="CLF_Unit_Mag" name="SteelArrived" type="L3BOOL">
	/// 处理钢包到达事件。
	/// <Param name="AreaID" type="L3STRING">钢包到达的工位</Param>
	/// </Method>
	L3BOOL SteelArrived(L3STRING AreaID);
	/// <Method class="CLF_Unit_Mag" name="FeedElement" type="L3BOOL">
	/// 向LF炉加料
	/// <Param name="rsElem" type="L3RECORDSET">加料数据</Param>
	/// </Method>
	L3BOOL FeedElement(L3RECORDSET rsElem);
	/// <Method class="CLF_Unit_Mag" name="SetTemperature" type="L3BOOL">
	/// 处理并记录测温事件
	/// <Param name="rsTemp" type="L3RECORDSET">测温事件数据</Param>
	/// </Method>
	L3BOOL SetTemperature(L3RECORDSET rsTemp);
	/// <Method class="CLF_Prod_Area" name="SetOxygen" type="L3BOOL">
	/// 处理并记录LF炉定氧事件。
	/// <Param name="rsOxygen" type="L3RECORDSET">定氧数据</Param>
	/// </Method>
	L3BOOL SetOxygen(L3RECORDSET rsOxygen);
	/// <Method class="CLF_Unit_Mag" name="FeedWire" type="L3BOOL">
	/// 处理并记录喂丝事件
	/// <Param name="Area" type="L3STRING">进行喂丝的工位</Param>
	/// <Param name="rsWire" type="L3RECORDSET">喂丝数据记录</Param>
	/// </Method>
	L3BOOL FeedWire(L3STRING Area,L3RECORDSET rsWire);
	/// <Method class="CLF_Unit_Mag" name="StartProcess" type="L3BOOL">
	/// 开始处理A、B两个之一工位上的钢水。
	/// <Param name="Area" type="L3STRING">要开始处理的工位</Param>
	/// </Method>
	L3BOOL StartProcess(L3STRING Area);
	/// <Method class="CLF_Unit_Mag" name="StopProcess" type="BOOL">
	/// 结束处理
	/// </Method>
	BOOL StopProcess();
	/// <Method class="CLF_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
	/// 修改设备状态
	/// <Param name="nStatus" type="L3LONG">新设备状态</Param>
	/// <Param name="reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL ChangeDeviceStatus(L3LONG nStatus, L3STRING reason);
	/// <Method class="CLF_Unit_Mag" name="OnTimer" type="L3BOOL">
	/// 处理定时器事件
	/// <Param name="nEventID" type="L3ULONG">事件ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG nEventID);
	/// <Method class="CLF_Unit_Mag" name="StartHeating" type="L3BOOL">
	/// 处理加热开始事件
	/// </Method>
	L3BOOL StartHeating();
	/// <Method class="CLF_Unit_Mag" name="StopHeating" type="L3BOOL">
	/// 处理加热结束事件
	/// </Method>
	L3BOOL StopHeating();
	/// <Method class="CLF_Unit_Mag" name="StartBlowing" type="BOOL">
	/// 处理软吹开始事件
	/// <Param name="Area" type="L3STRING">开始软吹的工位</Param>
	/// </Method>
	BOOL StartBlowing(L3STRING Area);
	/// <Method class="CLF_Unit_Mag" name="StopBlowing" type="L3BOOL">
	/// 处理软吹结束事件
	/// <Param name="Area" type="L3STRING">结束软吹的工位</Param>
	/// </Method>
	L3BOOL StopBlowing(L3STRING Area);
	/// <Method class="CLF_Unit_Mag" name="SteelLeave" type="L3BOOL">
	/// 处理钢水离站事件
	/// <Param name="Area" type="L3STRING">离站钢水工位</Param>
	/// </Method>
	L3BOOL SteelLeave(L3STRING Area);


	/// <Method class="CLF_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
	/// 申请改钢
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL ChangeSteelGradeApp(L3STRING Reason);


	/// <Method class="CLF_Unit_Mag" name="SteelReturnApp" type="L3BOOL">
	///  钢水回炉申请
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL SteelReturnApp(L3STRING Reason,L3STRING strHeatID);


	/// <Method class="CLF_Unit_Mag" name="SteelBackApp" type="L3BOOL">
	///  钢水返送申请
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL SteelBackApp(L3STRING Reason,L3STRING strHeatID);


	/// <Method class="CLF_Unit_Mag" name="AcceptAlloyDischargeData" type="L3RECORDSET">
	/// 合金料仓加料数据采集
	/// <Param name="HeatID" type="L3STRING">炉号</Param>
	/// </Method>
	L3BOOL AcceptMaterialDischargeData(L3RECORDSET rsMaterialData);

	/// <Method class="CLF_Unit_Mag" name="MaterialGroundDischargeData" type="L3RECORDSET">
	/// 袋装合金散状料消耗
	/// <Param name="HeatID" type="L3STRING">炉号</Param>
	/// </Method>
	L3BOOL MaterialGroundDischargeData(L3RECORDSET rsMaterialData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFArrivalData" type="L3BOOL">
	/// 接收LF炉钢包到达数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">到达数据</Param>
	/// </Method>
	L3BOOL AcceptLFArrivalData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFStartProcessData" type="L3BOOL">
	/// 接收LF炉处理开始数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">处理开始数据</Param>
	/// </Method>
	L3BOOL AcceptLFStartProcessData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFHeatData" type="L3BOOL">
	/// 接收LF炉加热数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">加热开始数据</Param>
	/// </Method>
	L3BOOL AcceptLFHeatData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFEndProcessData" type="L3BOOL">
	/// 接收LF炉处理结束数据 2008-12-30
	/// <Param name="rsData" type="L3RECORDSET">到达数据</Param>
	/// </Method>
	L3BOOL AcceptLFEndProcessData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFStartSoftBlowData" type="L3BOOL">
	/// 接收LF炉软吹开始数据 2008-12-30
	/// <Param name="rsData" type="L3RECORDSET">到达数据</Param>
	/// </Method>
	L3BOOL AcceptLFStartSoftBlowData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFStopSoftBlowData" type="L3BOOL">
	/// 接收LF炉处理结束数据 2008-12-30
	/// <Param name="rsData" type="L3RECORDSET">到达数据</Param>
	/// </Method>
	L3BOOL AcceptLFStopSoftBlowData(L3RECORDSET rsData);

/// <Method class="CLF_Unit_Mag" name="AcceptLFTempData" type="L3BOOL">
	/// 接收LF炉测温数据 2008-12-30
	/// <Param name="rsData" type="L3RECORDSET">测温数据</Param>
	/// </Method>
	L3BOOL AcceptLFTempData(L3RECORDSET rsData);

	/// 到达、处理结束之后改变工位状态函数;用于温度数据采集2008-12-31
	BOOL ChangeAreaStatus(LPCTSTR csAreaID,LONG nStatus);

	/// <Method class="CLF_Unit_Mag" name="SetTreatNoForTempDataBeforeProcess" type="L3BOOL">
	/// 对处理开始前测温设置处理号数据项 2008-12-30
	/// <Param name="csHeatID" type="LPCTSTR">炉号</Param>
	/// <Param name="csTreatNo" type="LPCTSTR">处理号</Param>
	/// </Method>
	L3BOOL SetTreatNoForTempDataBeforeProcess(LPCTSTR csHeatID,LPCTSTR csTreatNo);

	/// <Method class="CLF_Unit_Mag" name="SetDepartureTemp" type="L3BOOL">
	/// 设置离站温度 2009-01-02
	/// <Param name="csTreatNo" type="LPCTSTR">处理号</Param>
	/// </Method>
	L3BOOL SetDepartureTemp(LPCTSTR csTreatNo);

	/// <Method class="CLF_Unit_Mag" name="SetWireTemp" type="L3BOOL">
	/// 设置钙处理结束温度 2009-01-02
	/// <Param name="csTreatNo" type="LPCTSTR">处理号</Param>
	/// </Method>
	L3BOOL SetWireTemp(LPCTSTR csTreatNo);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFWireData" type="L3BOOL">
	/// 接收LF炉喂线数据 2009-01-02
	/// <Param name="rsData" type="L3RECORDSET">喂线数据</Param>
	/// </Method>
	L3BOOL AcceptLFWireData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFOxygenData" type="L3BOOL">
	/// 接收LF炉定氧数据 2009-01-02
	/// <Param name="rsData" type="L3RECORDSET">定氧数据</Param>
	/// </Method>
	L3BOOL AcceptLFOxygenData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFWeightData" type="L3BOOL">
	/// 接收LF炉称重数据 2009-01-08
	/// <Param name="rsData" type="L3RECORDSET">称重数据</Param>
	/// </Method>
	L3BOOL AcceptLFWeightData(L3RECORDSET rsData);

	/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  获取最近炉号 2009-02-28 增加炉号
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3RECORDSET GetPreThreeHeatID();

	/// <Method class="CLF_Unit_Mag" name="DoBlowwing" type="L3BOOL">
	/// 判定是否软吹开始 2009-03-09
	/// <Param name="strAreaUri" type="LPCTSTR">工序对象Uri</Param>
	/// <Param name="strHeatID" type="LPCTSTR">炉号</Param>
	/// </Method>
	L3BOOL DoBlowwing(LPCTSTR strAreaUri,LPCTSTR strHeatID);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFHeatGears" type="L3BOOL">
	/// 接收LF加热挡位数据 2009-01-02
	/// <Param name="rsData" type="L3RECORDSET">挡位数据</Param>
	/// </Method>
	L3BOOL AcceptLFHeatGears(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFBlowArData" type="L3BOOL">
	/// 接收LF炉吹氩流量数据 2009-03-23
	/// <Param name="rsData" type="L3RECORDSET">吹氩流量数据</Param>
	/// </Method>
	L3BOOL AcceptLFBlowArData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="SetTreatNoForBlowArData" type="L3BOOL">
	/// 对处理开始前吹氩数据设置处理号数据项 2009-03-23
	/// <Param name="csHeatID" type="LPCTSTR">炉号</Param>
	/// <Param name="csTreatNo" type="LPCTSTR">处理号</Param>
	/// </Method>
	L3BOOL SetTreatNoForBlowArData(LPCTSTR csHeatID,LPCTSTR csTreatNo);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFBlowArFlow" type="L3BOOL">
	/// 接收LF实绩吹氩数据 2009-03-23
	/// <Param name="rsData" type="L3RECORDSET">挡位数据</Param>
	/// </Method>
	L3BOOL AcceptLFBlowArFlow(L3RECORDSET rsData);

	//计算等压钢时间2009-03-28
	L3LONG CalculateHoldTime(LPCTSTR lpcszTreatNo,L3DATETIME dArrival);

	/// 获取前处理号 2009-03-28
	CString GetPreviousTreatNo(LPCTSTR lpcszTreatNo);


	/// <Method class="CLF_Unit_Mag" name="ModifyLadleGrade" type="L3LONG">
	/// 修改包况//2009-03-30 Liao
	/// <Param name="strTreatNo" type="L3STRING">处理号</Param>
	/// <Param name="strLadleGrade" type="L3STRING">包况</Param>
	/// </Method>
	L3LONG ModifyLadleGrade(L3STRING strTreatNo, L3STRING strLadleGrade);


	/// <Method class="CLF_Unit_Mag" name="CalEleRateValue" type="L3LONG">
	/// 计算最进化验结果比值
	/// <Param name="strHeatID" type="L3STRING">炉次号</Param>
	/// <Param name="strEleName1" type="L3STRING">元素1</Param>
	/// <Param name="strEleName2" type="L3STRING">元素2</Param>
	/// </Method>
	L3FLOAT CalEleRateValue(L3STRING strHeatID, L3STRING strEleName1,L3STRING strEleName2);
};

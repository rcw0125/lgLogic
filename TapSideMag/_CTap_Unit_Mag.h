// 逻辑类CTap_Unit_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProduceUnit.h"

class CTap_Unit_Mag :
	public ProduceUnit
{
public:
	CTap_Unit_Mag(void);
	virtual ~CTap_Unit_Mag(void);

	DECLARE_L3CLASS(CTap_Unit_Mag,XGMESLogic\\TapSideMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:
	enum _TapStatus
	{
		TAPWaiting = 0,			// 等待
		TAPProcessing = 1,		// 正在处理
		TAPProcessed = 2,		// 处理完毕
	};

protected:
	UINT m_iTimer;

	/// <summary>
	/// 返回机组的加工区域
	/// ARG << lstURIs : 接收所有加工区对象的URI
	/// </summary>
	virtual BOOL GetProduceAreas(CStringList& lstURIs);

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

	/// <Property class="CTap_Unit_Mag" name="Status" type="L3LONG">
	/// 当前状态
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CTap_Unit_Mag" name="HeatID" type="L3STRING">
	/// 当前处理的炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Unit_Mag" name="LadleID" type="L3STRING">
	/// 当前钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CTap_Unit_Mag" name="SteelGradeIndex" type="L3STRING">
	/// 当前炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CTap_Unit_Mag" name="StartTime" type="L3DATETIME">
	/// 处理开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(StartTime)

	/// <Property class="CTap_Unit_Mag" name="StopTime" type="L3DATETIME">
	/// 处理结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(StopTime)

	/// <Property class="CTap_Unit_Mag" name="ProcTime" type="L3LONG">
	/// 当前处理时间
	/// </Property>
	DECLARE_L3PROP_LONG(ProcTime)

	/// <Property class="CTap_Unit_Mag" name="ReSampleHeatID" type="L3STRING">
	/// 重取样通知炉号
	/// </Property>
	DECLARE_L3PROP_STRING(ReSampleHeatID)

	
	/// <Property class="CTap_Unit_Mag" name="StartProcessTime" type="L3STRING">
	/// 处理开始时间
	/// </Property>
	DECLARE_L3PROP_STRING(StartProcessTime)


	/// 通用计划状态修改函数
	BOOL ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status);

	/// <Method class="CTap_Unit_Mag" name="StartProcess" type="L3BOOL">
	/// 开始进行钢水炉后处理
	/// <Param name="rsSteel" type="L3RECORDSET">要处理的钢水记录</Param>
	/// </Method>
	L3BOOL StartProcess(L3RECORDSET rsSteel);
	/// <Method class="CTap_Unit_Mag" name="StopProcess" type="L3BOOL">
	/// 结束钢水炉后处理
	/// </Method>
	//L3BOOL StopProcess(L3RECORDSET rsProcData);
	L3BOOL StopProcess();
	/// <Method class="CTap_Unit_Mag" name="FeedElements" type="L3BOOL">
	/// 进行加料喂丝
	/// <Param name="rsElem" type="L3RECORDSET">加料喂丝数据</Param>
	/// </Method>
	L3BOOL FeedElements(L3RECORDSET rsElem);
	/// <Method class="CTap_Unit_Mag" name="SetTemperature" type="L3BOOL">
	/// 处理测温事件
	/// <Param name="rsTemp" type="L3RECORDSET">测温数据</Param>
	/// </Method>
	L3BOOL SetTemperature(L3RECORDSET rsTemp);
	/// <Method class="CTap_Unit_Mag" name="SetOxygen" type="BOOL">
	/// 处理定氧事件
	/// <Param name="rsOxygen" type="L3RECORDSET">定氧数据</Param>
	/// </Method>
	BOOL SetOxygen(L3RECORDSET rsOxygen);
	/// <Method class="CTap_Unit_Mag" name="OnTimer" type="L3BOOL">
	/// 处理定时器事件
	/// <Param name="nEventID" type="L3ULONG">定时器事件ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG nEventID);
	/// <Method class="CTap_Unit_Mag" name="SetWeight" type="L3BOOL">
	/// 处理钢水称重数据。
	/// <Param name="fWeight" type="L3DOUBLE">钢水重量</Param>
	/// </Method>
	L3BOOL SetWeight(L3DOUBLE fWeight);
	/// <Method class="CTap_Unit_Mag" name="Complete" type="L3BOOL">
	/// 完成炉后处理，将钢水转运至下工序。
	/// </Method>
	L3BOOL Complete();
	/// <Method class="CTap_Unit_Mag" name="GetInputSteels" type="L3RECORDSET">
	/// 返回炉后待处理钢水信息
	/// </Method>
	L3RECORDSET GetInputSteels();


	/// <Method class="CTap_Unit_Mag" name="ChangeSteelGrade" type="L3BOOL">
	/// 申请改钢
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight);

	/// <Method class="CTap_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  钢水回炉申请
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID);

	/// <Method class="CBOF_Unit_Mag" name="AcceptTapSideWeightData" type="L3BOOL">
	/// 接收炉后称重数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">炉后重量数据</Param>
	/// </Method>
	L3BOOL AcceptTapSideWeightData(L3RECORDSET rsData);

	/// <Method class="CTap_Unit_Mag" name="AutoStartProcess" type="L3BOOL">
	/// 转炉出钢结束后自动炉后开始处理 2009-01-14
	/// </Method>
	L3BOOL AutoStartProcess();


	/// <Method class="CTap_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  获取最近炉号 2009-02-28 增加炉号
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3RECORDSET GetPreThreeHeatID();

	/// <Method class="CTap_Unit_Mag" name="AcceptOxygenData" type="L3BOOL">
	/// 接收炉后定氧数据 2009-03-16
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptOxygenData(L3RECORDSET rsData);

	/// <Method class="CTap_Unit_Mag" name="AcceptTempData" type="L3BOOL">
	/// 接收炉后测温数据 2009-03-16
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptTempData(L3RECORDSET rsData);

	/// <Method class="CTap_Unit_Mag" name="CalculateOxygenContent" type="L3BOOL">
	/// 计算氩前后氧含量 2009-03-17
	/// </Method>
	L3BOOL CalculateOxygenContent();

	/// <Method class="CTap_Unit_Mag" name="CalculateTemperature" type="L3BOOL">
	/// 计算氩前后温度 2009-03-17
	/// </Method>
	L3BOOL CalculateTemperature();
};

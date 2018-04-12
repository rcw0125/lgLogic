// 逻辑类CBOF_Unit_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProduceUnit.h"

const CString AlloyArea1BOF = _T("A");
const CString AlloyAreaComm  = _T("B");

//定义结构
struct AddtionMaterial
{
	CString  MaterialType;
	CString  MaterialID;
	CString  Batch_ID;
	CString  Code;
	L3DOUBLE nWeight;
};



class CBOF_Unit_Mag :
	public ProduceUnit
{
public:
	CBOF_Unit_Mag(void);
	virtual ~CBOF_Unit_Mag(void);

	DECLARE_L3CLASS(CBOF_Unit_Mag,XGMESLogic\\BOFMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

protected:
	UINT m_nTimer;

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:

	//2009-03-02设备状态与生产状态分开 tangyi
	enum _BOFStatus
	{
		// 正常状态
		BOFWaiting = 0,			// 等待
		BOFFeeding = 1,			// 兑铁
		BOFBlowing = 2,			// 主吹
		BOFReBlowing = 3,		// 补吹
		BOFTapping = 4,			// 出钢
		BOFTapped = 5,			// 出钢结束
		BOFSplash = 6,			// 溅渣
		BOFDumping = 7,			// 倒渣
	};

	enum _BOFEquipStatus
	{
		// 异常状态
		BOFNormal = 0,	
		BOFRepair = -1,			// 检修
		BOFBushing = -2,		// 套管
		BOFMaintain = -3,		// 护炉
		BOFFailure = -4,		// 故障
	};

protected:
	/// <Property class="CBOF_Unit_Mag" name="HeatID" type="L3STRING">
	/// 当前炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_Unit_Mag" name="HeatID" type="L3STRING">
	/// 下一炉号
	/// </Property>
	DECLARE_L3PROP_STRING(NextHeatID)

	/// <Property class="CBOF_Unit_Mag" name="Status" type="L3LONG">
	/// 当前状态
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CBOF_Unit_Mag" name="LanceAge" type="L3LONG">
	/// 枪龄
	/// </Property>
    DECLARE_L3PROP_STRING(LanceNo)

	DECLARE_L3PROP_LONG(LanceAge)

	/// <Property class="CBOF_Unit_Mag" name="FurnaceAge" type="L3LONG">
	/// 炉龄
	/// </Property>
	DECLARE_L3PROP_LONG(FurnaceAge)

	/// <Property class="CBOF_Unit_Mag" name="Campaign" type="L3LONG">
	/// 炉役
	/// </Property>
	DECLARE_L3PROP_LONG(Campaign)

	/// <Property class="CBOF_Unit_Mag" name="Addition_Type" type="L3LONG">
	/// 当前加料类型
	/// </Property>
	DECLARE_L3PROP_LONG(Addition_Type)

	/// <Property class="CBOF_Unit_Mag" name="TopFlow" type="L3DOUBLE">
	/// 顶吹流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TopFlow)

	/// <Property class="CBOF_Unit_Mag" name="TopPressure" type="L3DOUBLE">
	/// 顶吹压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TopPressure)

	/// <Property class="CBOF_Unit_Mag" name="BottomFlow1" type="L3DOUBLE">
	/// 底吹流量1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow1)

	/// <Property class="CBOF_Unit_Mag" name="BottomPressure1" type="L3DOUBLE">
	/// 底吹压力1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure1)

	/// <Property class="CBOF_Unit_Mag" name="BottomFlow2" type="L3DOUBLE">
	/// 底吹流量2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow2)

	/// <Property class="CBOF_Unit_Mag" name="BottomPressure2" type="L3DOUBLE">
	/// 底吹压力2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure2)

	/// <Property class="CBOF_Unit_Mag" name="BottomFlow3" type="L3DOUBLE">
	/// 底吹流量3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow3)

	/// <Property class="CBOF_Unit_Mag" name="BottomPressure3" type="L3DOUBLE">
	/// 底吹压力3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure3)

	/// <Property class="CBOF_Unit_Mag" name="BottomFlow4" type="L3DOUBLE">
	/// 底吹流量4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow4)

	/// <Property class="CBOF_Unit_Mag" name="BottomPressure4" type="L3DOUBLE">
	/// 底吹压力4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure4)

	/// <Property class="CBOF_Unit_Mag" name="BottomFlow5" type="L3DOUBLE">
	/// 底吹流量5
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow5)

	/// <Property class="CBOF_Unit_Mag" name="BottomPressure5" type="L3DOUBLE">
	/// 底吹压力5
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure5)

	/// <Property class="CBOF_Unit_Mag" name="BottomFlow6" type="L3DOUBLE">
	/// 底吹流量6
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow6)

	/// <Property class="CBOF_Unit_Mag" name="BottomPressure6" type="L3DOUBLE">
	/// 底吹压力6
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure6)

	/// <Property class="CBOF_Unit_Mag" name="BlowTotalTime" type="L3DOUBLE">
	/// 总吹炼时间
	/// </Property>
	DECLARE_L3PROP_LONG(BlowTotalTime)

	/// <Property class="CBOF_Unit_Mag" name="BlowThisTime" type="L3DOUBLE">
	/// 本次时间
	/// </Property>
	DECLARE_L3PROP_LONG(BlowThisTime)

	/// <Property class="CBOF_Unit_Mag" name="BlowingEvent" type="L3LONG">
	/// 吹炼起始事件。0：停止，1：主吹，2：辅吹
	/// </Property>
	DECLARE_L3PROP_LONG(BlowingEvent)

	/// <Property class="CPlan_Tapping" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CPlan_Tapping" name="Load" type="L3DOUBLE">
	/// 装入量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Load)

	/// <Property class="CPlan_Tapping" name="CurTemp" type="L3DOUBLE">
	/// 炉温
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CurTemp)
	
	/// <Property class="CBOF_Unit_Mag" name="ReSampleEvent" type="L3LONG">
	/// 重新取样事件
	/// </Property>
	DECLARE_L3PROP_LONG(ReSampleEvent)

	/// <Property class="CBOF_Unit_Mag" name="UndoApplyEvent" type="L3LONG">
	/// 委托单回退事件
	/// </Property>
	DECLARE_L3PROP_LONG(UndoApplyEvent)

	/// <Property class="CBOF_Unit_Mag" name="ReSampleHeatID" type="L3STRING">
	/// 重取样通知炉号
	/// </Property>
	DECLARE_L3PROP_STRING(ReSampleHeatID)

	/// <Property class="CBOF_Unit_Mag" name="StartProcessTime" type="L3STRING">
	/// 处理开始时间
	/// </Property>
	DECLARE_L3PROP_STRING(StartProcessTime)//2008-12-26


	/// <Property class="CBOF_Unit_Mag" name="Taphole_Life" type="L3LONG">
	/// 出钢口寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Taphole_Life)

	/// <Property class="CBOF_Unit_Mag" name="Equip_Status" type="L3LONG">
	/// 当前状态
	/// </Property> 2009-03-02设备状态 tangyi
	DECLARE_L3PROP_LONG(Equip_Status)

	/// <Property class="CBOF_Unit_Mag" name="Plan_Count" type="L3LONG">
	///计划数
	/// </Property> 2009-03-02设备状态 tangyi
	DECLARE_L3PROP_LONG(Plan_Count)


	///////////////////////////////////////////////////////////////////////////////////////
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

	
	/// <Method class="CBOF_Unit_Mag" name="GetScrapesForDesignate" type="L3RECORDSET">
	/// 获取可选废钢信息记录。返回带有废钢槽号和废钢量的记录集。
	/// </Method>
	L3RECORDSET GetScrapesForDesignate();

	/// 计算下一炉号
	CString FindNextHeatIDFromPlan();

	/// 通用转炉过程状态修改函数
	BOOL ChangeBOFStatus(LONG nStatus);

	/// 通用计划状态修改函数
	BOOL ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status);

	/// <Method class="CBOF_Unit_Mag" name="FeedIrons" type="L3BOOL">
	/// 进行兑铁。使用事先指定的铁水和废钢斗进行兑铁。
	/// </Method>
	L3BOOL FeedIrons();
	/// <Method class="CBOF_Unit_Mag" name="FeedElement" type="L3BOOL">
	/// 向转炉中加料。
	/// <Param name="rsElement" type="L3RECORDSET">加料数据，包含类型，辅料代码，料量</Param>
	/// </Method>
	L3BOOL FeedElement(L3RECORDSET rsElement);
	/// <Method class="CBOF_Unit_Mag" name="TopBlowing" type="L3BOOL">
	/// 处理并记录转炉顶吹事件。
	/// <Param name="rsBlow" type="L3RECORDSET">顶吹数据</Param>
	/// </Method>
	L3BOOL TopBlowing(L3RECORDSET rsBlow);
	/// <Method class="CBOF_Unit_Mag" name="BottomBlowing" type="L3BOOL">
	/// 处理并记录底吹事件。
	/// <Param name="rsBlow" type="L3RECORDSET">底吹数据</Param>
	/// </Method>
	L3BOOL BottomBlowing(L3RECORDSET rsBlow);
	/// <Method class="CBOF_Unit_Mag" name="StartBlowing" type="L3BOOL">
	/// 转炉进入吹炼
	/// <Param name="bMainBlowing" type="L3BOOL">主吹标识</Param>
	/// <Param name="Catch_Time" type="L3DATETIME">开始时刻</Param>
	/// </Method>
	L3BOOL StartBlowing(L3BOOL bMainBlowing, L3DATETIME Catch_Time);
	/// <Method class="CBOF_Unit_Mag" name="StopBlowing" type="L3BOOL">
	/// 转炉结束吹炼
	/// <Param name="Catch_Time" type="L3DATETIME">结束时刻</Param>
	/// </Method>
	L3BOOL StopBlowing(L3DATETIME Catch_Time);
	/// <Method class="CBOF_Unit_Mag" name="SetOxygen" type="L3BOOL">
	/// 处理并记录定氧事件。
	/// <Param name="rsOxygen" type="L3RECORDSET">定氧数据</Param>
	/// </Method>
	L3BOOL SetOxygen(L3RECORDSET rsOxygen);
	/// <Method class="CBOF_Unit_Mag" name="SetTemperature" type="L3BOOL">
	/// 处理并记录转炉测温事件。
	/// <Param name="rsTemp" type="L3RECORDSET">测温数据</Param>
	/// </Method>
	L3BOOL SetTemperature(L3RECORDSET rsTemp);
	/// <Method class="CBOF_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
	/// 修改转炉设备状态
	/// <Param name="nStatus" type="L3LONG">新设备状态</Param>
	/// <Param name="reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL ChangeDeviceStatus(L3LONG nStatus,L3STRING reason);
	/// <Method class="CBOF_Unit_Mag" name="StartTapping" type="L3BOOL">
	/// 处理出钢开始事件
	/// </Method>
	L3BOOL StartTapping();
	/// <Method class="CBOF_Unit_Mag" name="StopTapping" type="L3BOOL">
	/// 处理出钢结束事件
	/// </Method>
	L3BOOL StopTapping();
	/// <Method class="CBOF_Unit_Mag" name="Splashing" type="L3BOOL">
	/// 转炉开始溅渣
	/// </Method>
	L3BOOL Splashing();
	/// <Method class="CBOF_Unit_Mag" name="Dumping" type="L3BOOL">
	/// 转炉开始倒渣
	/// </Method>
	L3BOOL Dumping();
	/// <Method class="CBOF_Unit_Mag" name="Waiting" type="L3BOOL">
	/// 转炉进入等待状态。
	/// </Method>
	L3BOOL Waiting();
	/// <Method class="CBOF_Unit_Mag" name="GetIronsForDesignate" type="L3RECORDSET">
	/// 返回可用于指定炉号的铁水信息。
	/// </Method>
	L3RECORDSET GetIronsForDesignate();
	/// <Method class="CBOF_Unit_Mag" name="GetInputIrons" type="L3RECORDSET">
	/// 返回已经指定了的铁水信息
	/// </Method>
	L3RECORDSET GetInputIrons();
	/// <Method class="CBOF_Unit_Mag" name="GetInputScrapes" type="L3RECORDSET">
	/// 返回已经指定了的生铁废钢信息
	/// </Method>
	L3RECORDSET GetInputScrapes();
	/// <Method class="CBOF_Unit_Mag" name="OnTimer" type="L3BOOL">
	/// 定时器处理
	/// <Param name="uEventID" type="L3ULONG">事件ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG uEventID);
	/// <Method class="CBOF_Unit_Mag" name="GetAddedMaterialSum" type="L3RECORDSET">
	/// 返回指定炉号的加料量统计数据。
	/// <Param name="HeatID" type="L3STRING">炉号</Param>
	/// </Method>
	L3RECORDSET GetAddedMaterialSum(L3STRING HeatID);


	/// <Method class="CCCM_Unit_Mag" name="ChangeSteelGrade" type="L3BOOL">
	/// 申请改钢
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight);

	/// <Method class="CCCM_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  钢水回炉申请
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID);


	/// <Method class="CBOF_Unit_Mag" name="AcceptAlloyDischargeData" type="L3RECORDSET">
	/// 合金料仓加料数据采集
	/// <Param name="HeatID" type="L3STRING">炉号</Param>
	/// </Method>
	L3BOOL AcceptMaterialDischargeData(L3RECORDSET rsMaterialData);



	/// <Method class="CBOF_Unit_Mag" name="MaterialGroundDischargeData" type="L3RECORDSET">
	/// 袋装合金散状料消耗
	/// <Param name="HeatID" type="L3STRING">炉号</Param>
	/// </Method>
	L3BOOL MaterialGroundDischargeData(L3RECORDSET rsMaterialData);

	/// <Method class="CBOF_Unit_Mag" name="GetExceptHeatID" type="L3RECORDSET">
	/// 获取工艺异常炉号数据。
	/// <Param name="UnitID" type="L3STRING">工位</Param>
	/// </Method>
	L3RECORDSET GetExceptHeatID(L3STRING UnitID);

	/// <Method class="CBOF_Unit_Mag" name="SetTemperature" type="L3BOOL">
	/// 记录转炉炉衬维护数据
	/// <Param name="rsData" type="L3RECORDSET">炉衬数据</Param>
	/// </Method>
	L3BOOL SetStackData(L3RECORDSET rsData);

	/// <Method class="CBOF_Unit_Mag" name="LockData" type="L3SHORT">
	/// 封锁实绩数据
	/// <Param name="strUnitID" type="L3STRING">工位</Param>
	/// <Param name="strHeatID" type="L3STRING">炉号</Param>
	/// <Param name="strTreatNo" type="L3STRING">处理号</Param>
	/// </Method>
	L3SHORT LockData(L3STRING strUnitID,L3STRING strHeatID,L3STRING strTreatNo);

	/// <Method class="CBOF_Unit_Mag" name="AcceptBOFStatus" type="L3BOOL">
	/// 接收转炉过程状态数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">状态数据</Param>
	/// </Method>
	L3BOOL AcceptBOFStatus(L3RECORDSET rsData);

	/// <Method class="CBOF_Unit_Mag" name="AcceptBOFBottomBlowData" type="L3BOOL">
	/// 接收转炉底吹数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">底吹数据</Param>
	/// </Method>
	L3BOOL AcceptBOFBottomBlowData(L3RECORDSET rsData);

	/// <Method class="CBOF_Unit_Mag" name="AcceptBOFTopBlowData" type="L3BOOL">
	/// 接收转炉顶吹数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">顶吹数据</Param>
	/// </Method>
	L3BOOL AcceptBOFTopBlowData(L3RECORDSET rsData);

	/// <Method class="CBOF_Unit_Mag" name="AcceptBOFTappedData" type="L3BOOL">
	/// 接收转炉出钢数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">出钢数据</Param>
	/// </Method>
	L3BOOL AcceptBOFTappedData(L3RECORDSET rsData);

	/// <Method class="CBOF_Unit_Mag" name="AcceptBOFTempData" type="L3BOOL">
	/// 接收转炉测温数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">测温数据</Param>
	/// </Method>
	L3BOOL AcceptBOFTempData(L3RECORDSET rsData);

	/// <Method class="CBOF_Unit_Mag" name="AcceptBOFOxygenData" type="L3BOOL">
	/// 接收转炉定氧数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">定氧数据</Param>
	/// </Method>
	L3BOOL AcceptBOFOxygenData(L3RECORDSET rsData);


	/// <Method class="CBOF_Unit_Mag" name="CaculateLadleGrade" type="L3BOOL">
	/// 计算钢包等级2008-12-28
	/// </Method>
	L3BOOL CaculateLadleGrade(L3DATETIME dtTapTime,L3STRING strHeatID);




	/// <Method class="CBOF_Unit_Mag" name="CalculateLcTemp" type="L3BOOL">
	/// 计算拉碳温度数据 2009-01-10
	/// </Method>
	L3BOOL CalculateLcTemp();

	/// <Method class="CBOF_Unit_Mag" name="CalculateTappingTemp" type="L3BOOL">
	/// 计算出钢温度数据(来源分为两处:一为倒炉测温，二为定氧时测温;出钢开始之前的最后一次测温;
	/// 若出现补吹，补吹开始至出钢开始时间段未测温，则出钢温度记为未测(-1)；定氧未测温采集定氧时温度数据) 2009-01-10
	/// </Method>
	L3BOOL CalculateTappingTemp();

	/// <Method class="CBOF_Unit_Mag" name="CalculateTappedOxygenContent" type="L3BOOL">
	/// 计算出钢氧含量数据(取最后一次氧含量数据) 2009-01-10
	/// </Method>
	L3BOOL CalculateTappedOxygenContent();

	/// <Method class="CBOF_Unit_Mag" name="CalculateFirstLaC" type="L3BOOL">
	/// 计算一次拉碳(拉碳温度等于出钢温度且无补吹及拉碳调料（轻烧白云石、石灰）信号的，视为一次拉碳) 2009-01-10
	/// </Method>
	L3BOOL CalculateFirstLaC();


	/// <Method class="CCCM_Unit_Mag" name="CompletCasting" type="L3BOOL">
	/// 向检化验发送浇铸信息,方法单独写以备信息重发。2009-01-03 tangyi
	/// </Method>
	L3BOOL SendCastingDataToAnaL2(L3STRING strHeatID);

	/// <Method class="CBOF_Unit_Mag" name="CalculateDefaultSmeltPeriod" type="L3BOOL">
	/// 计算缺省冶炼周期 2009-01-14
	/// </Method>
	L3BOOL CalculateDefaultSmeltPeriod();

	/// 获取上一炉号 2009-01-14
	CString GetPreviousHeatID(LPCTSTR lpcszHeatID);

	/// <Method class="CBOF_Unit_Mag" name="DesignateIrons" type="L3LONG">
	/// 指定主原料
	/// <Param name="rsIrons" type="L3RECORDSET">铁水信息,应至少包含MaterialID</Param>
	///2009-02-28
	/// </Method>
	L3LONG DesignateMainMaterial(L3RECORDSET rsIrons,L3RECORDSET rsReturnSteel,L3RECORDSET rsScrapes);


	/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  获取最近炉号 2009-02-28 增加炉号
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3RECORDSET GetPreThreeHeatID();

	/// 计算下一炉号
	CString CalculateNextHeatID (LPCTSTR lpcszHeatID);

	/// <Method class="CBOF_Unit_Mag" name="AcceptBOFRemainSlag" type="L3BOOL">
	/// 接收转炉出钢数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">出钢数据</Param>
	///2016-08-11
	/// </Method>
	L3BOOL AcceptBOFRemainSlag(L3RECORDSET rsData);

};

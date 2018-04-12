// 逻辑类CDEP_Unit_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProduceUnit.h"

const CString AlloyArea1DEP = _T("A");
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



class CDEP_Unit_Mag :
	public ProduceUnit
{
public:
	CDEP_Unit_Mag(void);
	virtual ~CDEP_Unit_Mag(void);

	DECLARE_L3CLASS(CDEP_Unit_Mag,XGMESLogic\\DePMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDEP_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

protected:
	UINT m_nTimer;

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:

	//2009-03-02设备状态与生产状态分开 tangyi
	enum _DEPStatus
	{
		// 正常状态
		
		//DEPFeeding = 1,			// 铁包进站                 //铁包进站 1
		//DEPBeginSlag   =2	,		//开始捞渣          //脱SI喷吹 2 3
		//DEPEndSlag = 3,           // 结束捞渣                    //扒SI渣   4 5
		//DEPBeginSpray = 4,		// 开始喷吹                 //脱P喷吹  6 7
		//DEPEndSpray = 5,			// 结束喷吹             //扒P渣    8 9
		//DEPBeginSi = 6,			// 开始脱硅                 //补吹开始、结束 10 11
		//DEPEndSi = 7,			    // 出钢脱硅                 //离站     12
		//DEPBeginP = 8,			// 开始脱磷
		//DEPEndP = 9,			    // 结束脱磷
		//DEPWaiting = 10,			// 等待或出站


		DEPFeeding = 1,			 //铁包进站 1
		DEPBeginSpray   =2	,	//脱SI喷吹开始、结束 2 3
		DEPEndSpray = 3,        
		DEPBeginSlag = 4,		//扒SI渣开始、结束   4 5
		DEPEndSlag = 5,			
        DEPBeginSprayP   =6	,	//脱P喷吹开始、结束  6 7
		DEPEndSprayP = 7,      
        DEPBeginSlagP = 8,		//扒P渣开始、结束    8 9
		DEPEndSlagP = 9,		
		DEPBeginReblow = 10,    //补吹开始、结束 10 11
		DEPEndReblow = 11,		
		DEPWaiting = 12,			// 等待或出站
	
		
	};

	enum _DEPEquipStatus
	{
		// 异常状态
		DEPNormal = 0,	
		DEPRepair = -1,			// 检修
		DEPBushing = -2,		// 套管
		DEPMaintain = -3,		// 护炉
		DEPFailure = -4,		// 故障
	};

protected:
	/// <Property class="CDEP_Unit_Mag" name="HeatID" type="L3STRING">
	/// 当前炉号
	/// </Property  铁包号
	DECLARE_L3PROP_STRING(IronLadle)
	DECLARE_L3PROP_STRING(IronLadleNo)
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CDEP_Unit_Mag" name="HeatID" type="L3STRING">
	/// 下一炉号
	/// </Property>
	DECLARE_L3PROP_STRING(NextHeatID)

	/// <Property class="CDEP_Unit_Mag" name="Status" type="L3LONG">
	/// 当前状态
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CDEP_Unit_Mag" name="LanceAge" type="L3LONG">


	/// <Property class="CDEP_Unit_Mag" name="FurnaceAge" type="L3LONG">
	/// 氧枪龄
	/// </Property>
	DECLARE_L3PROP_LONG(FurnaceAge)
	/// 氧枪铁水液面
	/// </Property>
	DECLARE_L3PROP_LONG(Furnace_Surface)

	/// 喷枪枪龄
	/// </Property>
	DECLARE_L3PROP_LONG(LanceAge)
	/// 喷枪抢号
	/// </Property>
	DECLARE_L3PROP_LONG(LanceNo)
		/// 扒渣耙头
	DECLARE_L3PROP_LONG(Slag_Head)

	//步数
	
	DECLARE_L3PROP_LONG(Step)

	/// 脱硅开始时刻
	/// 
	/// </Property>
	DECLARE_L3PROP_DATETIME(Desi_Start_time)
		/// 脱lin开始时刻
	/// 
	/// </Property>
	DECLARE_L3PROP_DATETIME(Dep_Start_time)

	DECLARE_L3PROP_LONG(Desi_Time)
	DECLARE_L3PROP_LONG(Dep_Time)
	//脱磷脱硅标志  脱硅0 脱磷 1
	DECLARE_L3PROP_LONG(Dep_Flag)
	


	
	DECLARE_L3PROP_LONG(Return_Flag)

	/// <Property class="CDEP_Unit_Mag" name="Addition_Type" type="L3LONG">
	/// 当前加料类型
	/// </Property>
	DECLARE_L3PROP_LONG(Addition_Type)

	/// <Property class="CDEP_Unit_Mag" name="TopFlow" type="L3DOUBLE">
	/// 顶吹流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TopFlow)

	/// <Property class="CDEP_Unit_Mag" name="TopPressure" type="L3DOUBLE">
	/// 顶吹压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TopPressure)

	/// <Property class="CDEP_Unit_Mag" name="BottomFlow1" type="L3DOUBLE">
	/// 底吹流量1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow1)

	/// <Property class="CDEP_Unit_Mag" name="BottomPressure1" type="L3DOUBLE">
	/// 底吹压力1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure1)

	/// <Property class="CDEP_Unit_Mag" name="BottomFlow2" type="L3DOUBLE">
	/// 底吹流量2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow2)

	/// <Property class="CDEP_Unit_Mag" name="BottomPressure2" type="L3DOUBLE">
	/// 底吹压力2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure2)

	/// <Property class="CDEP_Unit_Mag" name="BottomFlow3" type="L3DOUBLE">
	/// 底吹流量3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow3)

	/// <Property class="CDEP_Unit_Mag" name="BottomPressure3" type="L3DOUBLE">
	/// 底吹压力3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure3)

	/// <Property class="CDEP_Unit_Mag" name="BottomFlow4" type="L3DOUBLE">
	/// 底吹流量4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow4)

	/// <Property class="CDEP_Unit_Mag" name="BottomPressure4" type="L3DOUBLE">
	/// 底吹压力4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure4)

	/// <Property class="CDEP_Unit_Mag" name="BottomFlow5" type="L3DOUBLE">
	/// 底吹流量5
	/// </Property>

	/// <Property class="CDEP_Unit_Mag" name="BlowTotalTime" type="L3DOUBLE">
	/// 总吹炼时间
	/// </Property>
	DECLARE_L3PROP_LONG(BlowTotalTime)

	/// <Property class="CDEP_Unit_Mag" name="BlowThisTime" type="L3DOUBLE">
	/// 本次时间
	/// </Property>
	DECLARE_L3PROP_LONG(BlowThisTime)

	/// <Property class="CDEP_Unit_Mag" name="BlowingEvent" type="L3LONG">
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
	
	/// <Property class="CDEP_Unit_Mag" name="ReSampleEvent" type="L3LONG">
	/// 重新取样事件
	/// </Property>
	DECLARE_L3PROP_LONG(ReSampleEvent)

	/// <Property class="CDEP_Unit_Mag" name="UndoApplyEvent" type="L3LONG">
	/// 委托单回退事件
	/// </Property>
	DECLARE_L3PROP_LONG(UndoApplyEvent)

	/// <Property class="CDEP_Unit_Mag" name="ReSampleHeatID" type="L3STRING">
	/// 重取样通知炉号
	/// </Property>
	DECLARE_L3PROP_STRING(ReSampleHeatID)

	/// <Property class="CDEP_Unit_Mag" name="StartProcessTime" type="L3STRING">
	/// 处理开始时间
	/// </Property>
	DECLARE_L3PROP_STRING(StartProcessTime)//2008-12-26


	/// <Property class="CDEP_Unit_Mag" name="Taphole_Life" type="L3LONG">
	/// 出钢口寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Taphole_Life)

	/// <Property class="CDEP_Unit_Mag" name="Equip_Status" type="L3LONG">
	/// 当前状态
	/// </Property> 2009-03-02设备状态 tangyi
	DECLARE_L3PROP_LONG(Equip_Status)

	/// <Property class="CDEP_Unit_Mag" name="Plan_Count" type="L3LONG">
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

	




	/// 通用转炉过程状态修改函数
	BOOL ChangeDEPStatus(LONG nStatus);

	/// <Method class="CDEP_Unit_Mag" name="FeedElement" type="L3BOOL">
	/// 向转炉中加料。
	/// <Param name="rsElement" type="L3RECORDSET">加料数据，包含类型，辅料代码，料量</Param>
	/// </Method>
	L3BOOL FeedElement(L3RECORDSET rsElement);
	/// <Method class="CDEP_Unit_Mag" name="TopBlowing" type="L3BOOL">
	/// 处理并记录转炉顶吹事件。
	/// <Param name="rsBlow" type="L3RECORDSET">顶吹数据</Param>
	/// </Method>
	L3BOOL TopBlowing(L3RECORDSET rsBlow);
	/// <Method class="CDEP_Unit_Mag" name="BottomBlowing" type="L3BOOL">
	/// 处理并记录底吹事件。

	/// <Param name="rsTemp" type="L3RECORDSET">测温数据</Param>
	/// </Method>
	L3BOOL SetTemperature(L3RECORDSET rsTemp);
	/// <Method class="CDEP_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
	/// 修改转炉设备状态
	/// <Param name="nStatus" type="L3LONG">新设备状态</Param>
	/// <Param name="reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL ChangeDeviceStatus(L3LONG nStatus,L3STRING reason);
	/// <Method class="CDEP_Unit_Mag" name="StartTapping" type="L3BOOL">
	/// 处理出钢开始事件

	/// <Method class="CDEP_Unit_Mag" name="Splashing" type="L3BOOL">

	/// 转炉进入等待状态。
	/// </Method>
	L3LONG Waiting();
	/// <Method class="CDEP_Unit_Mag" name="GetIronsForDesignate" type="L3RECORDSET">
	/// 返回可用于指定炉号的铁水信息。
	/// </Method>
	L3RECORDSET GetIronsForDesignate();
	/// <Method class="CDEP_Unit_Mag" name="GetInputIrons" type="L3RECORDSET">
	/// 返回已经指定了的铁水信息
	/// </Method>
	L3RECORDSET GetInputIrons();
	/// <Method class="CDEP_Unit_Mag" name="GetInputScrapes" type="L3RECORDSET">
	/// 返回已经指定了的生铁废钢信息
	/// </Method>
	L3RECORDSET GetInputScrapes();
	/// <Method class="CDEP_Unit_Mag" name="OnTimer" type="L3BOOL">
	/// 定时器处理
	/// <Param name="uEventID" type="L3ULONG">事件ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG uEventID);
	/// <Method class="CDEP_Unit_Mag" name="GetAddedMaterialSum" type="L3RECORDSET">
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


	/// <Method class="CDEP_Unit_Mag" name="AcceptAlloyDischargeData" type="L3RECORDSET">
	/// 合金料仓加料数据采集
	/// <Param name="HeatID" type="L3STRING">炉号</Param>
	/// </Method>
	L3BOOL AcceptMaterialDischargeData(L3RECORDSET rsMaterialData);



	/// <Method class="CDEP_Unit_Mag" name="MaterialGroundDischargeData" type="L3RECORDSET">
	/// 袋装合金散状料消耗
	/// <Param name="HeatID" type="L3STRING">炉号</Param>
	/// </Method>
	L3BOOL MaterialGroundDischargeData(L3RECORDSET rsMaterialData);

	/// <Method class="CDEP_Unit_Mag" name="GetExceptHeatID" type="L3RECORDSET">
	/// 获取工艺异常炉号数据。
	/// <Param name="UnitID" type="L3STRING">工位</Param>
	/// </Method>
	L3RECORDSET GetExceptHeatID(L3STRING UnitID);

	/// <Method class="CDEP_Unit_Mag" name="SetTemperature" type="L3BOOL">
	/// 记录转炉炉衬维护数据
	/// <Param name="rsData" type="L3RECORDSET">炉衬数据</Param>
	/// </Method>
	L3BOOL SetStackData(L3RECORDSET rsData);

	/// <Method class="CDEP_Unit_Mag" name="LockData" type="L3SHORT">
	/// 封锁实绩数据
	/// <Param name="strUnitID" type="L3STRING">工位</Param>
	/// <Param name="strHeatID" type="L3STRING">炉号</Param>
	/// <Param name="strTreatNo" type="L3STRING">处理号</Param>
	/// </Method>
	L3SHORT LockData(L3STRING strUnitID,L3STRING strHeatID,L3STRING strTreatNo);

	/// <Method class="CDEP_Unit_Mag" name="AcceptDEPStatus" type="L3BOOL">
	/// 接收转炉过程状态数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">状态数据</Param>
	/// </Method>
	L3BOOL AcceptDEPStatus(L3RECORDSET rsData);


	/// <Method class="CDEP_Unit_Mag" name="AcceptDEPTopBlowData" type="L3BOOL">
	/// 接收转炉顶吹数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">顶吹数据</Param>
	/// </Method>
	L3BOOL AcceptDEPTopBlowData(L3RECORDSET rsData);

	/// <Method class="CDEP_Unit_Mag" name="AcceptDEPTappedData" type="L3BOOL">
	/// 接收转炉出钢数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">出钢数据</Param>
	/// </Method>
	L3BOOL AcceptDEPTappedData(L3RECORDSET rsData);

	/// <Method class="CDEP_Unit_Mag" name="AcceptDEPTempData" type="L3BOOL">
	/// 接收转炉测温数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">测温数据</Param>
	/// </Method>
	L3BOOL AcceptDEPTempData(L3RECORDSET rsData);

	/// <Method class="CDEP_Unit_Mag" name="AcceptDEPOxygenData" type="L3BOOL">
	/// 接收转炉定氧数据 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">定氧数据</Param>
	/// </Method>
	L3BOOL AcceptDEPOxygenData(L3RECORDSET rsData);




	/// <Method class="CDEP_Unit_Mag" name="CalculateLcTemp" type="L3BOOL">
	/// 计算拉碳温度数据 2009-01-10
	/// </Method>
	L3BOOL CalculateLcTemp();

	/// <Method class="CDEP_Unit_Mag" name="CalculateTappingTemp" type="L3BOOL">
	/// 计算出钢温度数据(来源分为两处:一为倒炉测温，二为定氧时测温;出钢开始之前的最后一次测温;
	/// 若出现补吹，补吹开始至出钢开始时间段未测温，则出钢温度记为未测(-1)；定氧未测温采集定氧时温度数据) 2009-01-10
	/// </Method>
	L3BOOL CalculateTappingTemp();

	/// <Method class="CDEP_Unit_Mag" name="CalculateTappedOxygenContent" type="L3BOOL">
	/// 计算出钢氧含量数据(取最后一次氧含量数据) 2009-01-10
	/// </Method>
	L3BOOL CalculateTappedOxygenContent();

	/// <Method class="CDEP_Unit_Mag" name="CalculateFirstLaC" type="L3BOOL">
	/// 计算一次拉碳(拉碳温度等于出钢温度且无补吹及拉碳调料（轻烧白云石、石灰）信号的，视为一次拉碳) 2009-01-10
	/// </Method>
	L3BOOL CalculateFirstLaC();

    /// <Method class="CDEP_Unit_Mag" name="SendStatusToPLC" type="L3BOOL">
	/// 将钢水重量下传PLC 2009-03-26
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL  SendStatusToPLC(L3LONG fStatus);


	/// <Method class="CDEP_Unit_Mag" name="CalculateDefaultSmeltPeriod" type="L3BOOL">
	/// 计算缺省冶炼周期 2009-01-14
	/// </Method>
	L3BOOL CalculateDefaultSmeltPeriod();

	/// 获取上一炉号 2009-01-14
	CString GetPreviousHeatID(LPCTSTR lpcszHeatID);


	/// <Method class="CDEP_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  获取最近炉号 2009-02-28 增加炉号
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3RECORDSET GetPreThreeHeatID();

	/// 计算下一炉号
	CString CalculateNextHeatID (LPCTSTR lpcszHeatID);
	L3LONG IronLadleToDEP(L3RECORDSET rsIrons);
	L3BOOL StartSlag();
	L3BOOL EndSlag();
	L3BOOL StartSpray();
	L3BOOL EndSpray();
	//L3BOOL StartSi();
	//L3BOOL EndSi();
	//L3BOOL StartP();
	//L3BOOL EndP();
	L3BOOL ReblowBeginSpray();
	L3BOOL ReblowEndSpray();
	L3BOOL StartSprayP();
	L3BOOL EndSprayP();
	L3BOOL StartSlagP();
	L3BOOL EndSlagP();

};

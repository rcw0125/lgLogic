// 逻辑类CCCM_Unit_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProduceUnit.h"

class CCCM_Unit_Mag :
	public ProduceUnit
{
public:
	CCCM_Unit_Mag(void);
	virtual ~CCCM_Unit_Mag(void);

	DECLARE_L3CLASS(CCCM_Unit_Mag,XGMESLogic\\CCMMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:
	enum _CCMStatus
	{
		// 正常状态
		CCMWaiting = 0,			// 等待状态
		CCMArrivle = 1,			// 到达
		CCMCasting = 2,			// 浇注中
		CCMCasted = 3,			// 浇注结束
		CCMDeparture = 4,		// 大包下包
	};

	//2009-03-02 tangyi
	enum _CCMEquipStatus
	{
		// 异常状态
		CCMNormal = 0,			// 正常
		CCMRepair = -1,			// 检修中
		CCMFailure = -2,		// 故障
	};

	enum _CCMST
	{
		ST1 = 1,			//1流
		ST2 = 2,			//2流
		ST3 = 3,			//3流
		ST4 = 4,			//4流
	};

	enum _CCMEquipType
	{
		SmoothBlock = 1,			//滑块
		WaterGap = 2,			    //水口
		BigWaterGap = 3,			//大包水口
	};

protected:
	CString cstrStopCastingHeatID; //2009-04-18 用于浇次最后一炉停浇后流停浇状状态及时刻的设置

	int CastNum1ST,CastNum2ST,CastNum3ST,CastNum4ST;
	CString GetPrepareArea();
	CString GetCastingArea();
	CString GetBloomingArea();

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

	/// <Property class="CCCM_Unit_Mag" name="Status" type="L3LONG">
	/// 当前状态
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CCCM_Unit_Mag" name="TreatNo" type="L3STRING">
	/// 当前处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Unit_Mag" name="CastingNo" type="L3STRING">
	/// 当前浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Unit_Mag" name="TundishNo" type="L3STRING">
	/// 当前包次号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_Unit_Mag" name="HeatID" type="L3STRING">
	/// 当前浇注炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Unit_Mag" name="NextHeatID" type="L3STRING">
	/// 下一上线炉号
	/// </Property>
	DECLARE_L3PROP_STRING(NextHeatID)

	/// <Property class="CCCM_Unit_Mag" name="SteelGradeIndex" type="L3STRING">
	/// 当前炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CCCM_Unit_Mag" name="SteelGrade" type="L3STRING">
	/// 当前钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CCCM_Unit_Mag" name="RemainedWeight" type="L3DOUBLE">
	/// 当前浇注钢水剩余量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(RemainedWeight)

	/// <Property class="CCCM_Unit_Mag" name="CastingEndEvent" type="L3LONG">
	/// 铸机浇铸结束事件
	/// </Property>
	DECLARE_L3PROP_LONG(CastingEndEvent)  

	/// <Property class="CCCM_Unit_Mag" name="CutSampleHeatID" type="L3STRING">
	/// 割样通知炉号
	/// </Property>
	DECLARE_L3PROP_STRING(CutSampleHeatID)
	/// <Property class="CCCM_Unit_Mag" name="ReSampleHeatID" type="L3STRING">
	/// 重取样通知炉号
	/// </Property>
	DECLARE_L3PROP_STRING(ReSampleHeatID)

	/// <Property class="CCCM_Unit_Mag" name="ArriveTime" type="L3STRING">
	/// 大包到达时间
	/// </Property>
	DECLARE_L3PROP_STRING(ArriveTime)

	/// <Property class="CCCM_Unit_Mag" name="StartCastingTime" type="L3STRING">
	/// 大包开浇时间
	/// </Property>
	DECLARE_L3PROP_STRING(StartCastingTime)

	/// <Property class="CCCM_Unit_Mag" name="LadleID" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)//2008-12-28

	/// <Property class="CCCM_Unit_Mag" name="NextLadleID" type="L3STRING">
	/// 下一钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(NextLadleID)//2008-12-28

	/// <Property class="CCCM_Unit_Mag" name="TundishWeight" type="L3DOUBLE">
	/// 当前中包钢水剩余量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TundishWeight)////2009-01-03

	/// <Property class="CCCM_Unit_Mag" name="EastTundishID" type="L3STRING">
	/// 东烘烤中包号
	/// </Property>
	DECLARE_L3PROP_STRING(EastTundishID)//2009-01-03

	/// <Property class="CCCM_Unit_Mag" name="WestTundishID" type="L3STRING">
	/// 西烘烤中包号
	/// </Property>
	DECLARE_L3PROP_STRING(WestTundishID)//2009-01-03

	/// <Property class="CCCM_Unit_Mag" name="SteelWeight" type="L3DOUBLE">
	/// 连铸称重钢水量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SteelWeight)////2009-01-03


	/// <Property class="CCCM_Unit_Mag" name="TundishTemp" type="L3LONG">
	///中包温度
	/// </Property>
	DECLARE_L3PROP_LONG(TundishTemp)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="Speed1st" type="L3DOUBLE">
	///1st拉速
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed1st)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="Speed2st" type="L3DOUBLE">
	///2st拉速
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed2st)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="Speed3st" type="L3DOUBLE">
	///3st拉速
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed3st)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="Speed4st" type="L3DOUBLE">
	///4st拉速
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed4st)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="SumCastWeight1st" type="L3DOUBLE">
	///1st拉钢量累计
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SumCastWeight1st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="SumCastWeight2st" type="L3DOUBLE">
	///2st拉钢量累计
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SumCastWeight2st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="SumCastWeight3st" type="L3DOUBLE">
	///3st拉钢量累计
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SumCastWeight3st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="SumCastWeight4st" type="L3DOUBLE">
	///4st拉钢量累计
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SumCastWeight4st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="CastTo15Minute" type="L3LONG">
	///浇注到达15分钟
	/// </Property>
	DECLARE_L3PROP_LONG(CastTo15Minute)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="OnOff1st" type="L3LONG">
	///1st开停浇状态
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff1st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="OnOff2st" type="L3LONG">
	///2st开停浇状态
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff2st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="OnOff3st" type="L3LONG">
	///3st开停浇状态
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff3st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="OnOff4st" type="L3LONG">
	///4st开停浇状态
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff4st)////2009-02-28


	/// <Property class="CCCM_Unit_Mag" name="Eqiup_Status" type="L3LONG">
	/// 设备状态
	/// </Property>2009-03-02
	DECLARE_L3PROP_LONG(Equip_Status)


	/// <Property class="CCCM_Unit_Mag" name="Cut_Information" type="L3LONG">
	/// 割样通知
	/// </Property>2009-03-11
	DECLARE_L3PROP_LONG(Cut_Information)

	/// <Property class="CCCM_Unit_Mag" name="RemainCastingTime" type="L3LONG">
	/// 当前剩余浇注时间
	/// </Property>
	DECLARE_L3PROP_LONG(RemainCastingTime)

	/// <Property class="CCCM_Unit_Mag" name="PrevHeatID" type="L3STRING">
	/// 停浇前炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PrevHeatID)

	/// 计算下一处理号
	CString CalculateNextTreatNo(LPCTSTR lpcszTreatNo);
	/// 计算下一浇次号
	CString CalculateNextCastingNo(LPCTSTR lpcszCastingNo);
	/// 计算下一包次号
	CString CalculateNextTundishNo(LPCTSTR lpcszTundishNo);
	
	/// 通用过程状态修改函数
	BOOL ChangeStatus(LONG nStatus);

	/// 通用计划状态修改函数
	BOOL ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status);

	/// <Method class="CCCM_Unit_Mag" name="GetInputSteels" type="L3RECORDSET">
	/// 返回入口钢水信息.
	/// </Method>
	L3RECORDSET GetInputSteels();
	/// <Method class="CCCM_Unit_Mag" name="DesignateSteel" type="L3BOOL">
	/// 指定下个上线的钢水.
	/// <Param name="rsSteel" type="L3RECORDSET">要指定上线的钢水记录</Param>
	/// </Method>
	L3BOOL DesignateSteel(L3RECORDSET rsSteel);
	/// <Method class="CCCM_Unit_Mag" name="SteelArrived" type="L3BOOL">
	/// 处理大包钢水到达事件，将指定的钢水上线。
	/// </Method>
	L3BOOL SteelArrived();
	/// <Method class="CCCM_Unit_Mag" name="StartCasting" type="L3BOOL">
	/// 开始大包浇注
	/// </Method>
	L3BOOL StartCasting();
	/// <Method class="CCCM_Unit_Mag" name="CompletCasting" type="L3BOOL">
	/// 完成大包浇注
	/// </Method>
	L3BOOL CompletCasting();
	/// <Method class="CCCM_Unit_Mag" name="ChangeCastingNo" type="L3BOOL">
	/// 更换浇次
	/// </Method>
	L3BOOL ChangeCastingNo();
	/// <Method class="CCCM_Unit_Mag" name="ChangeTundishNo" type="L3BOOL">
	/// 更换包次
	/// </Method>
	L3BOOL ChangeTundishNo();
	/// <Method class="CRH_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
	/// 修改设备状态
	/// <Param name="nStatus" type="L3LONG">新设备状态</Param>
	/// <Param name="reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL ChangeDeviceStatus(L3LONG nStatus, L3STRING reason);
	/// <Method class="CCCM_Unit_Mag" name="DivideHeatApp" type="L3BOOL">
	/// 申请炉次分割
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL DivideHeatApp(L3STRING Reason);
	/// <Method class="CCCM_Unit_Mag" name="SendBackSteelApp" type="L3BOOL">
	/// 申请大包整包返送。
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL SteelBackApp(L3STRING Reason);
	/// <Method class="CCCM_Unit_Mag" name="GenerateBlooms" type="L3BOOL">
	/// 炉次出坯
	/// <Param name="rsBloomData" type="L3RECORDSET">铸坯数据</Param>
	/// <Param name="HeatID" type="L3STRING">出坯炉号</Param>
	/// </Method>
	L3BOOL GenerateBlooms(L3RECORDSET rsBloomData);
	/// <Method class="CCCM_Unit_Mag" name="SetRemainedSteelWeight" type="L3BOOL">
	/// 处理大包剩余重量信号。
	/// <Param name="fWeight" type="L3DOUBLE">大包剩余重量</Param>
	/// </Method>
	L3BOOL SetRemainedSteelWeight(L3DOUBLE fWeight);


	/// <Method class="CCCM_Unit_Mag" name="SendTurnSteelApp" type="L3BOOL">
	/// 申请大包钢水回炉。
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL SteelReturnApp(L3STRING Reason);


	/// <Method class="CCCM_Unit_Mag" name="GetHeatAllInformation" type="">
	/// 获取已经浇铸完炉次的信息
	/// </Method>
	L3RECORDSET GetHeatAllInformation();


	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMTundishFireData" type="L3BOOL">
	/// 接收铸机中包烘烤数据 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">中包烘烤数据</Param>
	/// </Method>
	L3BOOL AcceptCCMTundishFireData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMRuntimeData" type="L3BOOL">
	/// 接收铸机开浇至终浇五分钟一次的实时数据 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">实时数据</Param>
	/// </Method>
	L3BOOL AcceptCCMRuntimeData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMSpeedData" type="L3BOOL">
	/// 接收铸机开浇至终浇拉速实时数据 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">实时数据</Param>
	/// </Method>
	L3BOOL AcceptCCMSpeedData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMTundishTempData" type="L3BOOL">
	/// 接收铸机开浇至终浇中包测温数据 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">中包测温数据</Param>
	/// </Method>
	L3BOOL AcceptCCMTundishTempData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMStatus" type="L3BOOL">
	/// 接收铸机过程状态数据 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">状态数据</Param>
	/// </Method>
	L3BOOL AcceptCCMStatus(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMLadleWeightData" type="L3BOOL">
	/// 接收铸机大、中包重量数据 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">重量数据</Param>
	/// </Method>
	L3BOOL AcceptCCMLadleWeightData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMSteelWeightData" type="L3BOOL">
	/// 接收铸机钢水重量数据 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">重量数据</Param>
	/// </Method>
	L3BOOL AcceptCCMSteelWeightData(L3RECORDSET rsData);

	//计算等压钢时间
    L3DATETIME CalculateHoldTime(LPCTSTR lpcszTreatNo);

	/// <Method class="CCCM_Unit_Mag" name="GetHeatAllInformation" type="">
	/// 获取可以进行炉次确定的信息
	/// </Method>
	L3RECORDSET GetHeatConfirmInfor();


	/// <Method class="CCCM_Unit_Mag" name="AcceptCCM5Runtime1Data" type="L3BOOL">
	/// 接收5#铸机开浇至终浇五分钟一次的实时数据 2009-02-25
	/// <Param name="rsData" type="L3RECORDSET">实时数据</Param>
	/// </Method>
	L3BOOL AcceptCCM5Runtime1Data(L3RECORDSET rsData);

    /// <Method class="CCCM_Unit_Mag" name="AcceptCCM5Runtime2Data" type="L3BOOL">
	/// 接收5#铸机开浇至终浇五分钟一次的实时数据冷却气体辊缝 2009-02-25
	/// <Param name="rsData" type="L3RECORDSET">实时数据</Param>
	/// </Method>
	L3BOOL AcceptCCM5Runtime2Data(L3RECORDSET rsData);

	/// 获取前处理号 2009-02-26
	CString GetPreviousTreatNo(LPCTSTR lpcszTreatNo);

/// <Method class="CCCM_Unit_Mag" name="LadleDeparture" type="L3BOOL">
	/// 大包下包
	/// </Method>
	L3BOOL LadleDeparture();

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCM5Runtime2Data" type="L3BOOL">
	/// 接收铸机钢水称重数据 2009-02-26
	/// <Param name="rsData" type="L3RECORDSET">实时数据</Param>
	/// </Method>
	L3BOOL AcceptSteelWeight(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptStrandStatusData" type="L3BOOL">
	/// 接收铸机流状态数据 2009-02-26
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptStrandStatusData(L3RECORDSET rsData);

	/// 获取炉次流GUID 2009-02-26
    CString GetHeatStrandGUID(LPCTSTR lpcszHeatID,LPCTSTR lpcszCCMID,L3LONG iStrandID);

	/// <Method class="CCCM_Unit_Mag" name="ArrivalTemperatureJudge" type="L3SHORT">
	/// 判定进机温度合格 2009-02-28
	/// <Param name="lpcszSteelGradeIndex" type="LPCTSTR">炼钢记号</Param>
	/// <Param name="lpcszUnitType" type="LPCTSTR">工序类型</Param>
	/// <Param name="iTempertaure" type="L3LONG">上机温度</Param>
	/// <Param name="iHeatNum" type="L3LONG">浇次内炉数</Param>
	/// </Method>
	L3SHORT ArrivalTemperatureJudge(LPCTSTR lpcszSteelGradeIndex,LPCTSTR lpcszUnitType,L3LONG iTempertaure,L3LONG iHeatNum);


	//2009-02-28 产生保护渣实绩默认为上一炉的实绩
	L3BOOL GenProtectSlagInfor(LPCTSTR lpcszTreatNo);

	/// <Method class="CCCM_Unit_Mag" name="CalculateStrandCaseWeight" type="L3BOOL">
	/// 计算炉次通钢量 2009-02-28
	/// </Method>
	L3BOOL CalculateStrandCaseWeight();

	/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  获取最近炉号 2009-02-28 增加炉号
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3RECORDSET GetPreThreeHeatID();

	/// <Method class="CCCM_Unit_Mag" name="GetMoldData" type="">
	/// 获取结晶器数据
	/// </Method>
	L3RECORDSET GetMoldData(LPCTSTR lcpstrStrandId);

	/// <Method class="CCCM_Unit_Mag" name="ChangeCCMEquipment" type="L3BOOL">
	/// 更换滑块/水口/大包水口
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL ChangeCCMEquipment(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="CalculateEquipmentLife" type="L3LONG">
	/// 计算设备寿命 2009-03-07
	/// <Param name="iEquipType" type="L3LONG">滑块/水口/大包水口</Param>
	/// <Param name="strCCMID" type="L3STRING">铸机号</Param>
	/// <Param name="iStrandNo" type="L3LONG">流号</Param>
	/// <Param name="strReason" type="L3STRING">流号</Param>
	/// </Method>
	L3LONG CalculateEquipmentLife(L3LONG iEquipType,L3STRING strCCMID,L3LONG iStrandNo,L3STRING strReason);

	/// <Method class="CCCM_Unit_Mag" name="CalculateRemainCastingTime" type="L3BOOL">
	/// 计算剩余浇注时间
	/// </Method>
	L3BOOL CalculateRemainCastingTime();

	/// <Method class="CCCM_Unit_Mag" name="SetTundishTempInValidFlag" type="L3BOOL">
	/// 设置中包温度无效标志 2009-03-25
	/// </Method>
	L3BOOL SetTundishTempInValidFlag(LPCTSTR strHeatID,LPCTSTR strCCMID);

	/// <Method class="CCCM_Unit_Mag" name="SendSteelWeightToPLC" type="L3BOOL">
	/// 将钢水重量下传PLC 2009-03-26
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL  SendSteelWeightToPLC(L3FLOAT fSteelWeight);

	/// <Method class="CCCM_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
	/// 申请改钢2009-04-15
	/// <Param name="Reason" type="L3STRING">原因</Param>
	/// </Method>
	L3BOOL ChangeSteelGradeApp(L3STRING Reason);

	/// <Method class="CCCM_Unit_Mag" name="ModifyStrandStatusData" type="L3LONG">
	/// 修改铸机流状态数据 2009-04-18
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyStrandStatusData(L3RECORDSET rsData);


	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMTundishTempData" type="L3BOOL">
	/// 接收铸机开浇后2分钟中包测温数据 2009-06-02
	/// <Param name="rsData" type="L3RECORDSET">中包测温数据</Param>
	/// </Method>
	L3BOOL AcceptCCMTundishTempForRefine(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptTundishWeightData" type="L3BOOL">
	/// 接收铸机中包钢水称重数据 2009-02-26
	/// <Param name="rsData" type="L3RECORDSET">实时数据</Param>
	/// </Method>
	L3BOOL AcceptTundishWeightData(L3RECORDSET rsData);
};

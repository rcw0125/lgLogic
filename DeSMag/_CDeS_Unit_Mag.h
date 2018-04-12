// 逻辑类CDeS_Unit_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProduceUnit.h"

class CDeS_Unit_Mag :
	public ProduceUnit
{
public:
	CDeS_Unit_Mag(void);
	virtual ~CDeS_Unit_Mag(void);

	DECLARE_L3CLASS(CDeS_Unit_Mag,XGMESLogic\\DeSMag, Name)
	DECLARE_L3PROPTABLE()

	DECLARE_L3METHODMAP(CDeS_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

protected:
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

	/// <Property class="CDeS_Unit_Mag" name="MaterialID_UnDeS" type="L3STRING">
	/// 未脱硫物料号
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID_UnDeS)

	/// <Property class="CDeS_Unit_Mag" name="MaterialID_DeSing" type="L3STRING">
	/// 正脱硫物料号
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID_DeSing)

	/// <Property class="CDeS_Unit_Mag" name="MaterialID_DeSed" type="L3STRING">
	/// 已脱硫物料号
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID_DeSed)

	/// <Property class="CDeS_Unit_Mag" name="TreatNo" type="L3STRING">
	/// 当前喷吹号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CDeS_Unit_Mag" name="NextTreatNo" type="L3STRING">
	/// 下一喷吹号
	/// </Property>
	DECLARE_L3PROP_STRING(NextTreatNo)

	/// <Property class="CDeS_Unit_Mag" name="CurArea" type="L3STRING">
	/// 当前工位
	/// </Property>
	DECLARE_L3PROP_STRING(CurArea)

	/// <Property class="CDeS_Unit_Mag" name="Weight_MatTank" type="L3DOUBLE">
	/// 储料罐重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_MatTank)

	/// <Property class="CDeS_Unit_Mag" name="Weight_SprayTank" type="L3DOUBLE">
	/// 喷吹罐重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_SprayTank)

	/// <Property class="CDeS_Unit_Mag" name="Pressure" type="L3DOUBLE">
	/// 主吹压力
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure)

	/// <Property class="CDeS_Unit_Mag" name="Flow" type="L3DOUBLE">
	/// 主吹流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow)

	/// <Property class="CDeS_Unit_Mag" name="Rate" type="L3DOUBLE">
	/// 速率
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Rate)

	/// <Property class="CDeS_Unit_Mag" name="Mat_Code" type="L3STRING">
	/// 脱硫剂代码
	/// </Property> 
	DECLARE_L3PROP_STRING(Mat_Code)

	/// <Property class="CDeS_Unit_Mag" name="Mat_Vendor" type="L3STRING">
	/// 脱硫剂厂家
	/// </Property> 
	DECLARE_L3PROP_STRING(Mat_Vendor)

	/// <Property class="CDeS_Unit_Mag" name="EventIronChanged" type="L3LONG">
	/// 铁水数据变更事件
	/// </Property>
	DECLARE_L3PROP_LONG(EventIronChanged)

	/// <Property class="CDeS_Unit_Mag" name="S" type="L3DOUBLE">
	/// 前S
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CDeS_Unit_Mag" name="Equipment_Status" type="L3LONG">
	/// 设备状态
	/// (1:正常;
	///  2:检修;
	///  3:等待;
	///  4:清渣;
	///  5:喷浆;
	///  6:更换防溅罩;
	///  7:故障)
	/// </Property>
	DECLARE_L3PROP_SHORT(Equipment_Status)

	/// <Property class="CDeS_Unit_Mag" name="DeSType" type="L3SHORT">
	/// 脱硫类型
	/// (1:浅脱硫
	///  2:标准脱硫
	///  3:深脱硫
	///  4:超深脱硫
	///  5:捞渣)
	/// </Property>
	DECLARE_L3PROP_SHORT(DeSType)

	/// <Property class="CDeS_Unit_Mag" name="DeSStatus" type="L3LONG">
	/// 脱硫状态(1:准备脱硫 2:铁水进站 9:铁罐出站
	/// </Property>
	DECLARE_L3PROP_LONG(DeSStatus)

	/// <Property class="CDeS_Unit_Mag" name="DeSStatusChanged_Time" type="L3DATETIME">
	/// 脱硫状态变化时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(DeSStatusChanged_Time)

	/// 计算下一处理号
	CString CalculateNextTreatNo(LPCTSTR lpcszTreatNo);

	/// <Method class="CDeS_Unit_Mag" name="DesignateIronLadle" type="L3BOOL">
	/// 指定即将到达的铁水。
	/// <Param name="rsIrons" type="L3STRING">铁水(铁次+罐号)</Param>
	/// </Method>
	L3LONG DesignateIronLadle(L3RECORDSET rsIrons);

	/// <Method class="CDeS_Unit_Mag" name="UndoDesignateIronLadle" type="L3BOOL">
	/// 测消指定即将到达的铁水。
	/// <Param name="strIron" type="L3STRING">铁水(铁次+罐号)</Param>
	/// </Method>
	L3LONG UndoDesignateIronLadle(L3STRING strIron);

	/// <Method class="CDeS_Unit_Mag" name="UndoDesignateIronLadle" type="L3LONG">
	/// 脱硫区域铁水状态变化
	/// <Param name="strIron" type="L3STRING">铁水(铁次+罐号)</Param>
	/// <Param name="nStatus" type="L3SHORT">铁水状态)</Param>
	/// </Method>
	L3LONG ChangeStatus(L3STRING strIron,L3SHORT nStatus,L3STRING strAreaID);

	/// <Method class="CDeS_Unit_Mag" name="CalculateTime" type="L3BOOL">
	/// 计算时间
	/// <Param name="lpcszDeSIron" type="LPCTSTR">铁水(铁次+罐号)</Param>
	/// <Param name="nStatus" type="L3SHORT">状态)</Param>
	/// <Param name="ncurStatus" type="L3SHORT">当前状态)</Param>
	/// </Method>
	L3LONG CalculateTime(LPCTSTR lpcszDeSIron,L3SHORT nStatus,L3SHORT ncurStatus);

	/// <Method class="CDeS_Unit_Mag" name="CalculateRemoveSlagTime" type="L3BOOL">
	/// 计算捞渣时间
	/// <Param name="lpcszDeSIron" type="LPCTSTR">铁水(铁次+罐号)</Param>
		/// <Param name="dArrival" type="L3DATETIME">预捞渣结束时刻)</Param>
	/// </Method>
	L3LONG CalculateRemoveSlagTime(LPCTSTR lpcszDeSIron,L3DATETIME dRemoveSlagEndTime);

	/// <Method class="CDeS_Unit_Mag" name="DesignateDeSUnitID" type="L3LONG">
	/// 指定工位。
	/// <Param name="strIron" type="L3STRING">铁水(铁次+罐号)</Param>
	/// </Method>
	L3LONG DesignateDeSUnitID(L3STRING strIron);

	/// <Method class="CDeS_Unit_Mag" name="StartBlowing" type="L3LONG">
	/// 处理喷吹开始事件
	/// <Param name="Area" type="L3STRING">开始喷吹的工位</Param>
	/// </Method>
	L3LONG StartBlowing(L3STRING Area);

    /// <Method class="CDeS_Unit_Mag" name="StopBlowing" type="L3LONG">
	/// 处理喷吹结束事件
	/// </Method>
	L3LONG StopBlowing();

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSBlowBeginData" type="L3BOOL">
	/// 接收DES喷吹开始数据 
	/// <Param name="rsData" type="L3RECORDSET">喷吹数据</Param>
	/// </Method>
	L3BOOL AcceptDeSBlowBeginData(L3RECORDSET rsData);

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSBlowEndData" type="L3BOOL">
	/// 接收DES喷吹结束数据 
	/// <Param name="rsData" type="L3RECORDSET">喷吹数据</Param>
	/// </Method>
	L3BOOL AcceptDeSBlowEndData(L3RECORDSET rsData);

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSRuntimeData" type="L3BOOL">
	/// 接收DES喷吹实时数据 
	/// <Param name="rsData" type="L3RECORDSET">实时数据</Param>
	/// </Method>
	L3BOOL AcceptDeSRuntimeData(L3RECORDSET rsData);

	/// <Method class="CDeS_Unit_Mag" name="SetLanceNo" type="L3LONG">
	/// 换喷枪 
	/// <Param name="strLanceNo" type="L3STRING">枪号</Param>
	/// <Param name="strUnitID" type="L3STRING">工位</Param>
	/// </Method>
	L3LONG ChangeLanceNo(L3STRING strLanceNo,L3STRING strUnitID);

	/// <Method class="CDeS_Unit_Mag" name="ChangeMatCodeAndVendor" type="L3BOOL">
	/// 更换脱硫剂
	/// <Param name="MatCode" type="L3STRING">脱硫剂</Param>
	/// <Param name="MatVendor" type="L3STRING">脱硫剂产家</Param>
	/// </Method>
	L3BOOL ChangeMatCodeAndVendor(L3STRING MatCode,L3STRING MatVendor);

	/// <Method class="CDeS_Unit_Mag" name="IronsDeparture" type="L3BOOL">
	/// 脱硫铁水离站
	/// <Param name="rsIrons" type="L3RECORDSET">铁水(MaterialID,Destination)</Param>
	/// </Method>
	L3LONG IronsDeparture();

	/// <Method class="CDeS_Unit_Mag" name="ChangeTreatNo" type="L3BOOL">
	/// 调整喷吹号
	/// <Param name="strTreatNo" type="L3STRING">喷吹号</Param>
	/// </Method>
	L3BOOL ChangeTreatNo(L3STRING strTreatNo);

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSStatusData" type="L3BOOL">
	/// 接收DES状态数据 
	/// <Param name="rsData" type="L3RECORDSET">喷吹数据</Param>
	/// </Method>
	L3BOOL AcceptDeSStatusData(L3RECORDSET rsData);

	/// <Method class="CDeS_Unit_Mag" name="LockData" type="L3SHORT">
	/// 封锁实绩数据
	/// <Param name="MaterialID" type="L3STRING">物料号</Param>
	/// </Method>
	L3SHORT LockData(L3STRING MaterialID);

	/// <Method class="CDeS_Unit_Mag" name="NewDeSAdditionData" type="L3LONG">
	/// 记录脱硫剂上料数据
	/// <Param name="rsMats" type="L3RECORDSET">脱硫剂</Param>
	/// </Method>
	L3LONG NewDeSAdditionData(L3RECORDSET rsMats);

	/// <Method class="CDeS_Unit_Mag" name="SetDeSMode" type="L3BOOL">
	/// 设置脱硫类型
	/// <Param name="MaterialID" type="L3STRING">物料号</Param>
	/// </Method>
	L3BOOL SetDeSMode(L3STRING MaterialID,L3SHORT DeSMode);

	/// <Method class="CDeS_Unit_Mag" name="NewDeSEquipmentStatusData" type="L3LONG">
	/// 记录脱硫设备状态变化数据
	/// <Param name="nStatus" type="L3SHORT">设备状态</Param>
	/// <Param name="strReason" type="L3STRING">设备状态变化原因</Param>
	/// </Method>
	L3LONG NewDeSEquipmentStatusData(L3SHORT nStatus,L3STRING strReason);

	/// <Method class="CDeS_Unit_Mag" name="IsOverForPreStatus" type="L3BOOL">
	/// 判定前一状态是否结束 
	/// <Param name="MaterialID" type="LPCTSTR">铁水</Param>
	/// <Param name="nStatus" type="LPCTSTR">当前状态</Param>
	/// <Param name="nEndStatu" type="L3SHORT">前结束状态</Param>
	/// <Param name="AreaID" type="CString">前结束状态</Param>
	/// </Method>
	L3BOOL IsOverForPreStatus(LPCTSTR MaterialID,L3SHORT nStatus,L3SHORT & nEndStatu,CString & AreaID);

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSDepartData" type="L3BOOL">
	/// 接受现场离站信号 
	/// </Method>
	L3BOOL AcceptDeSDepartData();

	/// <Method class="CDeS_Unit_Mag" name="AddNewLanceData" type="L3LONG">
	/// 新增喷枪数据
	/// <Param name="rsIrons" type="L3RECORDSET">喷枪数据</Param>
	/// </Method>
	L3LONG AddNewLanceData(L3RECORDSET rsLance);

	/// <Method class="CDeS_Unit_Mag" name="ChangeLanceStatus" type="L3LONG">
	/// 改变喷枪状态
	/// <Param name="rsIrons" type="L3RECORDSET">喷枪数据[喷枪号/状态]</Param>
	/// </Method>
	L3LONG ChangeLanceStatus(L3RECORDSET rsLance);

	/// <Method class="CDeS_Unit_Mag" name="ChangeLanceAge" type="L3LONG">
	/// 改变喷枪状态
	/// <Param name="rsIrons" type="L3RECORDSET">喷枪数据[喷枪号/枪龄]</Param>
	/// </Method>
	L3LONG ChangeLanceAge(L3RECORDSET rsLance);

	/// <Method class="CDeS_Unit_Mag" name="AddNewLanceLogData" type="L3LONG">
	/// 新增喷枪日志
	/// <Param name="strLanceNo" type="LPCTSTR">喷枪号</Param>
	/// <Param name="strNote" type="LPCTSTR">日志</Param>
	/// </Method>
	L3LONG AddNewLanceLogData(LPCTSTR strLanceNo,LPCTSTR strNote);

	/// <Method class="CDeS_Unit_Mag" name="PrepareIronLadle" type="L3LONG">
	/// 铁水准备
	/// </Method>
	L3LONG PrepareIronLadle();

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSArrivalData" type="L3LONG">
	/// 铁水进站
	/// </Method>
	L3LONG AcceptDeSArrivalSignal();

	/// <Method class="CDeS_Unit_Mag" name="GenerateLanceNo" type="L3STRING">
	/// 产生喷吹号
	/// </Method>
	L3STRING GenerateLanceNo();

	/// <Method class="CDeS_Unit_Mag" name="GetUnArrivedIrons" type="L3RECORDSET">
	/// 返回已指定去向，但未到达确认的铁水数据。
	/// </Method>
	L3RECORDSET GetUnArrivedIrons();

	/// <Method class="CDeS_Unit_Mag" name="GetUnitForEndStatus" type="L3BOOL">
	/// 在状态结束时获取对应开始状态的工位 
	/// <Param name="MaterialID" type="LPCTSTR">铁水</Param>
	/// <Param name="nStatus" type="LPCTSTR">当前状态</Param>
	/// <Param name="AreaID" type="CString">工位</Param>
	/// </Method>
	L3BOOL GetUnitForEndStatus(LPCTSTR MaterialID,L3SHORT nStatus,CString & AreaID);

	/// <Method class="CDeS_Unit_Mag" name="SetDeSIronPath" type="L3BOOL">
	/// 设置目的地
	/// <Param name="MaterialID" type="L3STRING">物料号</Param>
	/// <Param name="nPath" type="L3SHORT">目的地</Param>
	/// </Method>
	L3BOOL SetDeSIronPath(L3STRING MaterialID,L3SHORT nPath);

	/// <Method class="CDeS_Unit_Mag" name="BeginRemoveSlagNoDeS" type="L3BOOL">
	/// 判定前一状态是否结束 
	/// <Param name="MaterialID" type="LPCTSTR">铁水</Param>
	/// <Param name="AreaID" type="LPCTSTR">当前工位</Param>
	/// <Param name="nStatus" type="L3SHORT">当前状态</Param>
	/// <Param name="nDeSType" type="L3SHORT">脱硫类型</Param>
	/// </Method>
	L3BOOL BeginRemoveSlagNoDeS(LPCTSTR MaterialID,LPCTSTR AreaID,L3SHORT nStatus,L3SHORT nDeSType);

};

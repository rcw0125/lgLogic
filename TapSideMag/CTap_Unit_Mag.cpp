// 逻辑类CTap_Unit_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CTap_Unit_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CTap_Unit_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CTap_Unit_Mag.h"
#include "L3NameParser.h"

#define PROCTIMER_PERIOD 5000

//当对象被装载到系统中时，被调用
void CTap_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CTap_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 返回机组的加工区域
/// ARG << lstURIs : 接收所有加工区对象的URI
/// </summary>
BOOL CTap_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	CString strArea;
	strArea.Format(_T("XGMESLogic\\BaseDataMag\\XGProduceArea\\%s"),GetIdentity().ToCString());
	lstURIs.AddHead(strArea);
	return TRUE;
}

/// <summary>
/// 得到机组前序材料缓冲区的URI
/// </summary>
CString CTap_Unit_Mag::GetInputCache()
{
	CString strID = GetIdentity().ToCString();
	CString strIdx = strID.Mid(strID.GetLength() - 1,1);
	CString strCache; strCache.Format(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S3%sP01"),strIdx);
	return strCache;
}

/// <summary>
/// 得到机组后继材料缓冲区的URI
/// </summary>
CString CTap_Unit_Mag::GetOutputCache()
{
	// 由于需要根据工艺路线转运钢水，本机组不设立出口缓存。
	return _T("");
}

/// <summary>
/// 机组上料前预处理。在机组上料前调用，继承类可重载此方法进行预先数据准备和处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 返回TRUE继续上料；返回FALSE中断上料。
/// </summary>
BOOL CTap_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// 机组上料后续处理。在机组上料后调用，继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CTap_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// 返回机组上料记录的类型URI
/// </summary>
CString CTap_Unit_Mag::GetFeedingLogType()
{
	return _T("");
}


/// <summary>
/// 准备上料记录数据。继承类可重载此函数进行额外的数据处理。
/// ARG >> rsFeedingLogs : 上料记录信息。
/// RET << void
/// </summary>
void CTap_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::PrepareFeedingLogs( rsFeedingLogs);
}


/// <summary>
/// 加工参数预处理。在调用加工区域的加工方法前调用，继承类可重载此函数对加工参数进行修改和配置。
/// ARG >> lpcszArea : 加工区域的URI
///		>> rsParameters : 加工参数记录集。
/// RET << 返回TRUE继续加工；返回FALSE中断加工。
/// </summary>
BOOL CTap_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PrepareProcessParameters( lpcszArea, rsParameters);
}


/// <summary>
/// 加工完成后续处理。在加工完成后调用，继承类可重载此函数进行额外逻辑处理
/// ARG >> lpcszArea : 加工区域的URI
///		>> nProcessType : 加工的类型。
///		>> rsProducts : 加工产生的产品的信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CTap_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// 下线前预处理。在执行下线操作前调用，继承类可重载此函数进行预先的数据准备和处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 返回TRUE继续下线；返回FALSE中断下线。
/// </summary>
BOOL CTap_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// 下线后续处理。在执行下线操作后调用，继承类可重载此函数进行额外处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CTap_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsDelivered( rsMaterialInfo);
}


/// <summary>
/// 返回机组产出记录的类型URI
/// </summary>
CString CTap_Unit_Mag::GetDeliveryLogType()
{
	return _T("");
}


/// <summary>
/// 准备下料记录数据。
/// ARG >> rsDeliveryLog : 下料记录数据。
/// RET <<void
/// </summary>
void CTap_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// 返回本机组的通讯器对象的URI
/// </summary>
CString CTap_Unit_Mag::GetCommunicator()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetCommunicator();
}


/// <summary>
/// 准备计划数据，以便向机组下位系统发送。
/// ARG >> lpcszPlanType : 计划类型。
///		>> rsPlan : 计划数据。包括PlanID字段。
///		<< rsSend : 接收准备好的计划发送数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CTap_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// 计划下达后续处理。在向下位系统发送计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsSend : 下发下位系统的计划数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CTap_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterPlansSent( rsSend);
}


/// <summary>
/// 准备计划数据，以便通知机组下位系统取消计划。
/// ARG >> lpcszPlanType : 计划类型。
///		>> rsPlan : 计划数据。包括PlanID字段。
///		<< rsSend : 接收准备好的计划取消数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CTap_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// 计划取消后续处理。在向下位系统发送取消计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsCancel : 下发下位系统的计划取消数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CTap_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// 处理材料上线的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CTap_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// 处理材料进入加工区域的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CTap_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// 处理材料离开加工区域事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CTap_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// 处理材料生产完毕事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CTap_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// 处理机组测量数据变更事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CTap_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}

/// 通用计划状态修改函数
BOOL CTap_Unit_Mag::ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status)
{
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsPlanStatus; pRS->QueryInterface(IID_IL3RecordSet,rsPlanStatus); pRS->Release();
	rsPlanStatus.AddField(_T("HeatID"),VT_BSTR);
	rsPlanStatus.AddField(_T("UnitType"),VT_I4);
	rsPlanStatus.AddField(_T("TreatNo"),VT_BSTR);
	rsPlanStatus.AddField(_T("UnitStatus"),VT_BSTR);
	rsPlanStatus.AddField(_T("StatusChangeTime"),VT_DATE);
	rsPlanStatus.AppendRecord();
	rsPlanStatus.SetFieldByName(_T("HeatID"),CL3Variant(lpcszHeatID));
	rsPlanStatus.SetFieldByName(_T("UnitType"),CL3Variant(_T("3")));
	rsPlanStatus.SetFieldByName(_T("TreatNo"),CL3Variant(lpcszTreatNo));
	rsPlanStatus.SetFieldByName(_T("UnitStatus"),CL3Variant(Status));
	rsPlanStatus.SetFieldByName(_T("StatusChangeTime"),CL3Variant(COleDateTime::GetCurrentTime()));
	CL3Variant valRet = InvokeObjectMethod(PLAN_OBJ_URI,_T("ModifyPlanExecutionStatus"),(L3RECORDSET)rsPlanStatus);
	return valRet.ToBOOL();
}

/// <Method class="CTap_Unit_Mag" name="StartProcess" type="L3BOOL">
/// 开始进行钢水炉后处理
/// <Param name="rsSteel" type="L3RECORDSET">要处理的钢水记录</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::StartProcess(L3RECORDSET rsSteel)
{
	CL3RecordSetWrap rs = rsSteel;
	if(rs.GetRowCount() != 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 锁定本机组
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// 检查机组状态
	if(Status != CTap_Unit_Mag::TAPWaiting)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_TAPREFUSED);
		return FALSE;
	}
	CString csSteelGradeIndex = rs.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	// 将材料上线
	rs.AddField(MESPROP_MATERIAL_TYPE,VT_BSTR);
	rs.AddField(MESPROP_AMOUNT,VT_R8);
	rs.SetFieldByName(MESPROP_MATERIAL_TYPE,CL3Variant(_T("CSteel_Data")));
	rs.SetFieldByName(MESPROP_AMOUNT,CL3Variant((L3DOUBLE)1));
	if(!FeedMaterials(rs))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// 产生基本数据记录
	CL3RecordSetWrap rsBaseData;
	if(!CreateClassPropSet(TAP_BASE_DATA_CLASS_URI,rsBaseData))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsBaseData.CopyFrom(rsSteel);
	rsBaseData.MoveFirst();
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rsBaseData.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsBaseData.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
	rsBaseData.SetFieldByName(_T("ProductionDate"),CL3Variant(curTime));
	rsBaseData.SetFieldByName(_T("SteelGrade"),GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("SteelGrade")));//2009-01-11 tangyi
	if(CreateNewObjects(TAP_BASE_DATA_CLASS_URI,rsBaseData) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	AcceptPropSet(rs,TRUE);
	StartTime = curTime;



	// 修改状态
	if(!SetPropValue(_T("Status"),CL3Variant((LONG)CTap_Unit_Mag::TAPProcessing)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	StartProcessTime = curTime.Format(_T("%H:%M:%S"));

	// 启动定时器
	//m_iTimer = SetTimer(GetURI(),PROCTIMER_PERIOD);

	if(nTrans > 0) Commit(nTrans);

		// 修改计划状态
	ChangePlanStatus(HeatID,HeatID,TAPPING_PLAN_SIDE_STATUS_BEGIN);

	return TRUE;

}

/// <Method class="CTap_Unit_Mag" name="StopProcess" type="L3BOOL">
/// 结束钢水炉后处理
/// </Method>
L3BOOL CTap_Unit_Mag::StopProcess()
{
	//CL3RecordSetWrap rs = rsProcData;
	
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 锁定本机组
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// 检查状态
	if(Status != CTap_Unit_Mag::TAPProcessing)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_TAPREFUSED);
		return FALSE;
	}

	COleDateTime curTime = COleDateTime::GetCurrentTime();
	BOOL bUseCurTime = FALSE;
	//if(rs.GetFieldIndex(_T("End_Time")) < 0)
		bUseCurTime = TRUE;
	BOOL bUseLoggedStartTime = FALSE;
	//if(rs.GetFieldIndex(_T("Start_Time")) < 0)
		bUseLoggedStartTime = TRUE;
	BOOL bUseCalTime = FALSE;
	//if(rs.GetFieldIndex(_T("BlowAr_Time")) < 0)
		bUseCalTime = TRUE;

	// 生成过程数据记录
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_PROCESS_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	//rs.MoveFirst();
	rsLog.AppendRecord();
	//rsLog.CopyCurRowFrom(rs);
	rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
	if(bUseLoggedStartTime)
		rsLog.SetFieldByName(_T("Start_Time"),GetPropValue(_T("StartTime")));
	if(bUseCurTime)
		rsLog.SetFieldByName(_T("End_Time"),CL3Variant(curTime));
	if(bUseCalTime)
		rsLog.SetFieldByName(_T("BlowAr_Time"),GetPropValue(_T("ProcTime")));
	if(CreateNewObjects(TAP_PROCESS_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	


	// 修改状态
	if(!SetPropValue(_T("Status"),CL3Variant((LONG)CTap_Unit_Mag::TAPProcessed)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(!bUseCurTime)
		SetPropValue(_T("StopTime"),rsLog.GetFieldByName(_T("End_Time")));

	StartProcessTime =_T("");//2008-12-26


    CalculateOxygenContent(); //2009-03-17
	CalculateTemperature();   //2009-03-17



	// 修改计划状态
	ChangePlanStatus(HeatID,HeatID,TAPPING_PLAN_SIDE_STATUS_END);

	//if(m_iTimer != 0)
	//	KillTimer(GetURI(),m_iTimer);
	//m_iTimer = 0;

	if (!Complete()) //处理结束物料自动进入下工序 2009-01-14 
	{
		if(nTrans > 0) 
			Rollback(nTrans);
		return FALSE;
	}

    if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="FeedElements" type="L3BOOL">
/// 进行加料喂丝
/// <Param name="rsElem" type="L3RECORDSET">加料喂丝数据</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::FeedElements(L3RECORDSET rsElem)
{
	CL3RecordSetWrap rs = rsElem;
	if(rs.GetRowCount() < 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	BOOL bUseCurTime = FALSE;
	if(rs.GetFieldIndex(_T("Discharge_Time")) < 0)
		bUseCurTime = TRUE;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_ADDITION_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
		if(bUseCurTime)
			rsLog.SetFieldByName(_T("Discharge_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(TAP_ADDITION_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="SetTemperature" type="L3BOOL">
/// 处理测温事件
/// <Param name="rsTemp" type="L3RECORDSET">测温数据</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::SetTemperature(L3RECORDSET rsTemp)
{
	CL3RecordSetWrap rs = rsTemp;
	if(rs.GetRowCount() < 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	BOOL bUseCurTime = FALSE;
	if(rs.GetFieldIndex(_T("MeasureTime")) < 0)
		bUseCurTime = TRUE;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_TEMP_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
		if(bUseCurTime)
			rsLog.SetFieldByName(_T("MeasureTime"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(TAP_TEMP_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="SetOxygen" type="BOOL">
/// 处理定氧事件
/// <Param name="rsOxygen" type="L3RECORDSET">定氧数据</Param>
/// </Method>
BOOL CTap_Unit_Mag::SetOxygen(L3RECORDSET rsOxygen)
{
	CL3RecordSetWrap rs = rsOxygen;
	if(rs.GetRowCount() < 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	BOOL bUseCurTime = FALSE;
	if(rs.GetFieldIndex(_T("MeasureTime")) < 0)
		bUseCurTime = TRUE;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_OXYGEN_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
		if(bUseCurTime)
			rsLog.SetFieldByName(_T("MeasureTime"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(TAP_OXYGEN_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="OnTimer" type="L3BOOL">
/// 处理定时器事件
/// <Param name="nEventID" type="L3ULONG">定时器事件ID</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::OnTimer(L3ULONG nEventID)
{
	if(nEventID == m_iTimer)
	{	// 吹炼定时器
		ProcTime += PROCTIMER_PERIOD;
	}

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="SetWeight" type="L3BOOL">
/// 处理钢水称重数据。
/// <Param name="fWeight" type="L3DOUBLE">钢水重量</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::SetWeight(L3DOUBLE fWeight)
{
	// 生成称重记录
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_LADLE_WEIGHT_CLASS_URI,rsLog))
		return FALSE;

	COleDateTime curTime = COleDateTime::GetCurrentTime();

	rsLog.AppendRecord();
	rsLog.SetFieldByName(_T("TAPID"),GetIdentity());
	rsLog.SetFieldByName(_T("Weight"),CL3Variant(fWeight));
	rsLog.SetFieldByName(_T("Log_Time"),CL3Variant(curTime));

	if(HeatID != _T(""))
	{
		rsLog.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
		rsLog.SetFieldByName(_T("LadleID"),GetPropValue(_T("LadleID")));
	}
	CreateNewObjects(TAP_LADLE_WEIGHT_CLASS_URI,rsLog);


	CString cstrSteelGradeIndex = GetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("SteelGradeIndex")).ToCString();
    L3DOUBLE SteelWeight = GetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("Weight")).ToDouble();
	
	if ((cstrSteelGradeIndex.GetLength() > 1)&&(SteelWeight < 1) )
	{
		if (cstrSteelGradeIndex.Left(1) == _T("F")) //2009-03-14 普钢减去渣重0.3吨;品种钢减去渣重1吨
			fWeight = fWeight - 0.3;
		else
		{
			//2009-07-16钢水扣渣规定：常规钢按300Kg/炉扣渣，老系统品种钢按800Kg/炉扣渣，大方坯品种钢按1200Kg/炉扣渣(现扣渣量改为1450kg)。

			if (cstrSteelGradeIndex.Left(1) == _T("P"))
			{
				//Modify begin by llj 2011-04-18 修改转炉直送不锈钢产线扣渣量为700kg，其他扣渣量为800kg
				CString csHeatID=GetPropValue(_T("HeatID")).ToCString();
				CString csSql;
				csSql.Format(_T("select CasterID from %s where HeatID='%s'"),PLAN_TAPPING_CLASS_URI,csHeatID);
				CL3RecordSetWrap rsTappingPlan;
				if(Query(csSql,rsTappingPlan)&&rsTappingPlan.GetRowCount()>0)
				{
					CString csCasterID=rsTappingPlan.GetFieldByName(_T("CasterID")).ToCString();
					if(csCasterID==_T("S66"))
						fWeight = fWeight - 0.7;
					else
						fWeight = fWeight - 0.8;
				}
				else
					fWeight = fWeight - 0.8;
				//Modify end
			}
			else
			{
				
				//Modify begin by llj 2011-05-13 精品钢送5#铸机的扣渣1.45 其他铸机扣渣0.8
				//fWeight = fWeight - 1.2;
				CString csHeatID=GetPropValue(_T("HeatID")).ToCString();
				CString csSql;
				csSql.Format(_T("select CasterID from %s where HeatID='%s'"),PLAN_TAPPING_CLASS_URI,csHeatID);
				CL3RecordSetWrap rsTappingPlan;
				if(Query(csSql,rsTappingPlan)&&rsTappingPlan.GetRowCount()>0)
				{
					CString csCasterID=rsTappingPlan.GetFieldByName(_T("CasterID")).ToCString();
					if(csCasterID==_T("S65"))
						fWeight = fWeight - 1.45;
					else
						fWeight = fWeight - 0.8;
				}
				else
					fWeight = fWeight - 0.8;
				//Modify end
			}
		}
		  CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,HeatID);
	    if(!SetObjectPropValue(strProcData,_T("Tapping_Weight"),CL3Variant(fWeight)))
	    {
		  return FALSE;
	     }

	   // 修改当前钢水重量
	     if(!SetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("Weight"),CL3Variant(fWeight)))//2009-04-09
	     {
		   return FALSE;
	      }
	}

	//2009-06-09 tangyi 
	//if(fWeight > 50)
	//	fWeight = 48;

	//CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,HeatID);
	//if(!SetObjectPropValue(strProcData,_T("Tapping_Weight"),CL3Variant(fWeight)))
	//{
	//	return FALSE;
	//}

	//// 修改当前钢水重量
	//if(!SetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("Weight"),CL3Variant(fWeight)))//2009-04-09
	//{
	//	return FALSE;
	//}

	if (!StopProcess()) //钢水重量到达即炉后处理结束 2009-01-14
	{
		return FALSE;
	}

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="Complete" type="L3BOOL">
/// 完成炉后处理，将钢水转运至下工序。
/// </Method>
L3BOOL CTap_Unit_Mag::Complete()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 锁定本机组
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	// 检查状态
	if(Status != CTap_Unit_Mag::TAPProcessed)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_TAPREFUSED);
		return FALSE;
	}

	// 读取该钢水的计划，判定其去向
	CString strHeatID = HeatID;
	strHeatID.Trim();
	CString strPlan;
	strPlan.Format(_T("select * from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,(LPCTSTR)GetRealHeatID(strHeatID));
	CL3RecordSetWrap rsPlan;
	if(!Query(strPlan,rsPlan) || rsPlan.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		SetL3LastError(XGMES_ERR_PLANNOTEXIST);
		return FALSE;
	}
	rsPlan.MoveFirst();
	CString strLFID = rsPlan.GetFieldByName(_T("LFID")).ToCString();
	CString strRHID = rsPlan.GetFieldByName(_T("RHID")).ToCString();
	CString strCCMID = rsPlan.GetFieldByName(_T("CasterID")).ToCString();
	CString strType = rsPlan.GetFieldByName(_T("Refine_Type")).ToCString();
	CString strTargetCache;
	TCHAR cHead = *((LPCTSTR)strType);
	switch(cHead)
	{
	case _T('0'):
		{	// 去铸机
			strTargetCache = strCCMID + _T("P01");
		}
		break;
	case _T('L'):
		{	// 去LF炉
			strTargetCache = strLFID + _T("P01");
		}
		break;
	case _T('R'):
		{	// 去RH炉
			strTargetCache = strRHID + _T("P01");
		}
		break;
	default:
		{
			if(nTrans > 0) Rollback(nTrans);
			SetL3LastError(XGMES_ERR_PLANWRONGREFINETYPE);
			return FALSE;
		}
	}
	strTargetCache = CL3NameParser::MergeClassDomainName(XGINTERCACHE_URI,strTargetCache);
	// 钢水下线
	CString strArea = CL3NameParser::MergeClassDomainName(XGPRODUCEAREA_URI,GetIdentity().ToCString());
	CL3Variant valSteels = InvokeObjectMethod(strArea,_T("GetMaterials"));
	CL3RecordSetWrap rsSteels;
	if(FAILED(valSteels.QueryInterface(IID_IL3RecordSet,rsSteels)) || rsSteels.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	//tangyi20081202
	rsSteels.AddField(_T("Area"),VT_BSTR);
	rsSteels.MoveFirst();
	rsSteels.SetFieldByName(_T("Area"),CL3Variant(strArea));

	CBSTR bstrTarget = strTargetCache;
	rsSteels.MoveFirst();
    /*屏蔽开始 by hyh 2012-05-16  由于将6#铸机纳入MES统一管理
	//Modify begin by llj 2011-03-27 对于直送不锈钢钢水在炉后处理后删除数据
	if(strCCMID==_T("S66"))
	{
		CL3RecordSet rsPosData;
		rsPosData.CopyFrom(rsSteels);
		CL3RecordSetWrap rsPos; rsPosData.QueryInterface(IID_IL3RecordSet,rsPos);
		CL3Variant valRet = InvokeObjectMethod(strArea,_T("RemoveMaterials"),(IL3RecordSet*)rsPos);
		if(!valRet.ToBOOL())
		{	// 从加工位中转移材料失败
			if(nTrans>0)
				Rollback(nTrans);
			return FALSE;
		}
	}
	else
	{
	//Modify end
		if(!DeliverMaterialsTo(bstrTarget.GetBuffer(TRUE),rsSteels))
		{
			if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}
	}
	屏蔽结束*/
	//add by hyh 2012-05-16
	if(!DeliverMaterialsTo(bstrTarget.GetBuffer(TRUE),rsSteels))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	//end

	// 修改状态
	if(!SetPropValue(_T("Status"),CL3Variant((LONG)CTap_Unit_Mag::TAPWaiting)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	//2009-04-30 Begin 1-3#转炉若钢水量为0则设置钢水量48吨
	CString cstrUnitID = GetIdentity().ToCString();
	if (cstrUnitID != _T("S34"))
	{
		CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,strHeatID);
		L3DOUBLE fSteelWeight = 0;
		fSteelWeight = GetObjectPropValue(strProcData,_T("Tapping_Weight")).ToDouble();
		if (fSteelWeight < 1)
		{
			if(!SetObjectPropValue(strProcData,_T("Tapping_Weight"),(L3DOUBLE)48))
			{
				if(nTrans > 0) Rollback(nTrans);
				return FALSE;
			}

			// 修改当前钢水重量
			if(!SetObjectPropValue(CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,HeatID),_T("Weight"),(L3DOUBLE)48))
			{
				if(nTrans > 0) Rollback(nTrans);
				return FALSE;
			}
		}
	}
	//2009-04-30 End

	if(nTrans > 0) Commit(nTrans);

	//离站成功产生该炉原始记录调用存储过程放在事务之外2009-04-01 tangyi
	//CL3RecordSet *pRSData = new CL3RecordSet();
	//CL3RecordSetWrap rsOrigData; pRSData->QueryInterface(IID_IL3RecordSet,rsOrigData); pRSData->Release();
	//rsOrigData.AddField(_T("UnitID"),VT_BSTR);
	//rsOrigData.AddField(_T("HeatID"),VT_BSTR);

	//rsOrigData.AppendRecord();
	//rsOrigData.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	//rsOrigData.SetFieldByName(_T("UnitID"),GetIdentity());

	//CreateNewObjects(_T("XGMESLogic\\BaseDataMag\\CBase_Unit_Original_Data"),rsOrigData);

	return TRUE;
}

/// <Method class="CTap_Unit_Mag" name="GetInputSteels" type="L3RECORDSET">
/// 返回炉后待处理钢水信息
/// </Method>
L3RECORDSET CTap_Unit_Mag::GetInputSteels()
{
	CString strCache = GetInputCache();
	CL3Variant valSteels = InvokeObjectMethod(strCache,_T("GetMaterialDetails"),_T("CSteel_Data"),_T(""));
	if(!valSteels.IsValid())
		return NULL;
	CL3RecordSetWrap rsSteels;
	if(FAILED(valSteels.QueryInterface(IID_IL3RecordSet,rsSteels)))
		return NULL;
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MATERIAL_STEEL_URI,rs))
		return NULL;
	rsSteels.MoveFirst();
	rs.CopyFrom(rsSteels);
	return rs.Detach();
}

/// <Method class="CBOF_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
/// 申请改钢
/// <Param name="Reason" type="L3STRING">原因</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_EXE_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,csHeatID);
	CString csPreHeatID = GetObjectPropValue(csUri,_T("PreHeatID")).ToCString();
	rsSteel.SetFieldByName(_T("PreHeatID"),CL3Variant(csPreHeatID));
	rsSteel.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rsSteel.SetFieldByName(_T("SteelGradeIndex"),GetObjectPropValue(csUri,_T("SteelGradeIndex")));//2008-12-30 tangyi
	rsSteel.SetFieldByName(_T("App_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsSteel.SetFieldByName(_T("App_Steel_Weight"),CL3Variant(fWeight));
	rsSteel.SetFieldByName(_T("App_Operator"),CL3Variant(GetCurrentUser()));
	rsSteel.SetFieldByName(_T("App_UnitID"),GetIdentity());
	rsSteel.SetFieldByName(_T("App_Reason"),CL3Variant(Reason));

	CString strDispMag =DISPATCH_OBJ_URI;
	CL3Variant val = InvokeObjectMethod(strDispMag,_T("SteelExchangeApp"),(L3RECORDSET)rsSteel);
	return val.ToBOOL();

}


/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  钢水回炉申请
/// <Param name="Reason" type="L3STRING">原因</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_TURN_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	CString csHeatID = strHeatID;
	CString csUri = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,csHeatID);
	CString csPreHeatID = GetObjectPropValue(csUri,_T("PreHeatID")).ToCString();
	rsSteel.SetFieldByName(_T("PreHeatID"),CL3Variant(csPreHeatID));
	rsSteel.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rsSteel.SetFieldByName(_T("SteelGradeIndex"),GetObjectPropValue(csUri,_T("SteelGradeIndex")));//2008-12-30 tangyi
	rsSteel.SetFieldByName(_T("App_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsSteel.SetFieldByName(_T("App_Steel_Weight"),CL3Variant(fWeight));
	rsSteel.SetFieldByName(_T("App_Operator"),CL3Variant(GetCurrentUser()));
	rsSteel.SetFieldByName(_T("App_UnitID"),GetIdentity());
	rsSteel.SetFieldByName(_T("App_Reason"),CL3Variant(Reason));

	CString strDispMag =DISPATCH_OBJ_URI;
	CL3Variant val = InvokeObjectMethod(strDispMag,_T("SteelTurnApp"),(L3RECORDSET)rsSteel);
	return val.ToBOOL();

}

/// <Method class="CBOF_Unit_Mag" name="AcceptTapSideWeightData" type="L3BOOL">
/// 接收炉后称重数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">炉后重量数据</Param>
/// </Method>
L3BOOL CTap_Unit_Mag::AcceptTapSideWeightData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveLast();
	L3DOUBLE fWeight = rs.GetFieldByName(_T("Weight")).ToDouble();
    if (!SetWeight(fWeight))
	{
		return FALSE;
	}
	return TRUE;	
}

/// <Method class="CTap_Unit_Mag" name="AutoStartProcess" type="L3BOOL">
/// 转炉出钢结束后自动炉后开始处理 2009-01-14
/// </Method>
L3BOOL CTap_Unit_Mag::AutoStartProcess()
{
	CL3RecordSetWrap rs = GetInputSteels();

	if (rs.GetRowCount() != 1)
	{
		return FALSE;
	}

	if (!(StartProcess(rs)))
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  获取最近炉号 2009-02-28 增加炉号
/// <Param name="Reason" type="L3STRING">原因</Param>
/// </Method>
L3RECORDSET CTap_Unit_Mag::GetPreThreeHeatID()
{
	CString csUnitID = GetIdentity().ToCString();
	CString csBOFID = csUnitID.Mid(2,1);
	CString csTempSQL =_T("select * from (select HeatID from CTap_Base_Data where substr(HeatID,2,1) = '%s'  order by  HeatID desc) where rownum < 4");
	CString csSQL;
	csSQL.Format(csTempSQL,csBOFID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;
	return rs.Detach();	
}

/// <Method class="CTap_Unit_Mag" name="AcceptOxygenData" type="L3BOOL">
/// 接收炉后定氧数据 2009-03-16
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CTap_Unit_Mag::AcceptOxygenData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount = rs.GetRowCount();
	if(rsCount < 1)
		return TRUE;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_OXYGEN_DATA_CLASS_URI,rsLog))
	{
		return FALSE;
	}

	rs.MoveFirst();
	for(int i=0;i<rsCount;i++) //2009-03-05 增加多数据收集
	{
		CString strBOFID = rs.GetFieldByName(_T("BOFID")).ToCString();  //获取机组号

		//获取铸机管理对象
		CString strBOFMag = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag"),strBOFID);
		CString strHeatID = GetObjectPropValue(strBOFMag,_T("HeatID")).ToCString();

		COleDateTime curTime = COleDateTime::GetCurrentTime();
		rsLog.AppendRecord();
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		rsLog.SetFieldByName(_T("Oxygen_Content"),rs.GetFieldByName(_T("Oxygen_Content")));
		rsLog.SetFieldByName(_T("Temp"),rs.GetFieldByName(_T("Temp"))); //2009-03-23
		rsLog.SetFieldByName(_T("MeasureTime"),CL3Variant(curTime));

		rs.MoveNext();
	}
	
	if (rsLog.GetRowCount() > 0)
	{
		rsLog.MoveFirst();
		if(CreateNewObjects(TAP_OXYGEN_DATA_CLASS_URI,rsLog) < 1)
		{
			return FALSE;
		}
	}

	return TRUE;	
}

/// <Method class="CTap_Unit_Mag" name="AcceptTempData" type="L3BOOL">
/// 接收炉后测温数据 2009-03-16
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CTap_Unit_Mag::AcceptTempData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount = rs.GetRowCount();
	if(rsCount < 1)
		return TRUE;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(TAP_TEMP_DATA_CLASS_URI,rsLog))
	{
		return FALSE;
	}

	rs.MoveFirst();
	for(int i=0;i<rsCount;i++) //2009-03-05 增加多数据收集
	{
		CString strBOFID = rs.GetFieldByName(_T("BOFID")).ToCString();  //获取机组号

		//获取铸机管理对象
		CString strBOFMag = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag"),strBOFID);
		CString strHeatID = GetObjectPropValue(strBOFMag,_T("HeatID")).ToCString();

		COleDateTime curTime = COleDateTime::GetCurrentTime();
		rsLog.AppendRecord();
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		rsLog.SetFieldByName(_T("Temperature"),rs.GetFieldByName(_T("Temperature")));
		rsLog.SetFieldByName(_T("MeasureTime"),CL3Variant(curTime));
		rsLog.SetFieldByName(_T("MeasureType"),rs.GetFieldByName(_T("MeasureType")));

		rs.MoveNext();
	}
	
	if (rsLog.GetRowCount() > 0)
	{
		rsLog.MoveFirst();
		if(CreateNewObjects(TAP_TEMP_DATA_CLASS_URI,rsLog) < 1)
		{
			return FALSE;
		}
	}

	return TRUE;	
}

/// <Method class="CTap_Unit_Mag" name="CalculateTemperature" type="L3BOOL">
/// 计算氩前后温度
/// </Method>
L3BOOL CTap_Unit_Mag::CalculateTemperature()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString csSQL;
	csSQL.Format(_T("select * from %s where HeatID = '%s' order by MeasureTime asc"),
		TAP_TEMP_DATA_CLASS_URI,curHeatID);
	CL3RecordSetWrap rstemp;
	if (!Query(csSQL, rstemp) || rstemp.IsNull()|| rstemp.GetRowCount() < 1)	
	{
		return FALSE; 
	}

	rstemp.MoveFirst();
	//20090902 liao
	//20090902 liao


	CString strUri = CL3NameParser::MergeClassDomainName(TAP_PROCESS_DATA_CLASS_URI,curHeatID);
	SetObjectPropValue(strUri,_T("Temp_Before_BlowAr"),rstemp.GetFieldByName(_T("Temperature")));
	
	L3LONG rsCount = rstemp.GetRowCount();
	if (rsCount > 1)
	{
		rstemp.MoveLast();
		SetObjectPropValue(strUri,_T("Temp_BlownAr"),rstemp.GetFieldByName(_T("Temperature")));
	}
	else
	{
		SetObjectPropValue(strUri,_T("Temp_BlownAr"),CL3Variant((L3LONG)0));
	}
	
	
	return TRUE;	
}

/// <Method class="CTap_Unit_Mag" name="CalculateOxygenContent" type="L3BOOL">
/// 计算氩前后氧含量
/// </Method>
L3BOOL CTap_Unit_Mag::CalculateOxygenContent()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString csSQL;
	csSQL.Format(_T("select * from %s where HeatID = '%s' order by MeasureTime asc"),
		TAP_OXYGEN_DATA_CLASS_URI,curHeatID);
	CL3RecordSetWrap rstemp;
	if (!Query(csSQL, rstemp) || rstemp.IsNull())	
	{
		return FALSE; 
	}
	L3LONG rsCount = rstemp.GetRowCount();
	if (rsCount < 1)
	{
		return TRUE;
	}

	rstemp.MoveFirst();
	//20090902 liao
	/*csSQL.Format(_T("select * from CTap_Process_Data where heatid = '%s' ",curHeatID));
	CL3RecordSetWrap rsProcessData;
	if (!Query(csSQL, rsProcessData) || rsProcessData.IsNull())	
	{
		return FALSE; 
	}
	if(rsProcessData.GetRowCount() > 0)
	{
		rsProcessData.MoveFirst();*/

		//CString csGUID = rsProcessData.GetFieldByName(_T("GUID")).ToCString();
	CString strUri = CL3NameParser::MergeClassDomainName(TAP_PROCESS_DATA_CLASS_URI,curHeatID);
	SetObjectPropValue(strUri,_T("O2_Before_BlowAr"),rstemp.GetFieldByName(_T("Oxygen_Content")));

	if (rsCount > 1)
	{
		rstemp.MoveLast();
		SetObjectPropValue(strUri,_T("O2_BlownAr"),rstemp.GetFieldByName(_T("Oxygen_Content")));
	}
	else
	{
		SetObjectPropValue(strUri,_T("O2_BlownAr"),CL3Variant((L3LONG)0));
	}
	
	return TRUE;	
	//}
}

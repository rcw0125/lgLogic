// 逻辑类CBOF_Unit_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CBOF_Unit_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CBOF_Unit_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CBOF_Unit_Mag.h"
#include "L3NameParser.h"

#define BLOWTIMER_PERIOD		5000
#define BLOWTIME		5

//当对象被装载到系统中时，被调用
void CBOF_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CBOF_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 返回机组的加工区域
/// ARG << lstURIs : 接收所有加工区对象的URI
/// </summary>
BOOL CBOF_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	CString strURI;
	strURI.Format(_T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\%s"),GetIdentity().ToCString());
	lstURIs.AddHead(strURI);
	return TRUE;
}

/// <summary>
/// 得到机组前序材料缓冲区的URI
/// </summary>
CString CBOF_Unit_Mag::GetInputCache()
{
	return MIXFProduceCache_URI;
}

/// <summary>
/// 得到机组后继材料缓冲区的URI
/// </summary>
CString CBOF_Unit_Mag::GetOutputCache()
{
	CString strURI;
	CString strID = GetIdentity().ToCString();
	CString strIdx = strID.Right(1);
	strURI.Format(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S3%sP01"),strIdx);
	return strURI;
}

/// <summary>
/// 机组上料前预处理。在机组上料前调用，继承类可重载此方法进行预先数据准备和处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 返回TRUE继续上料；返回FALSE中断上料。
/// </summary>
BOOL CBOF_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// 机组上料后续处理。在机组上料后调用，继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBOF_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// 返回机组上料记录的类型URI
/// </summary>
CString CBOF_Unit_Mag::GetFeedingLogType()
{
	return _T("");
}


/// <summary>
/// 准备上料记录数据。继承类可重载此函数进行额外的数据处理。
/// ARG >> rsFeedingLogs : 上料记录信息。
/// RET << void
/// </summary>
void CBOF_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
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
BOOL CBOF_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
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
BOOL CBOF_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// 下线前预处理。在执行下线操作前调用，继承类可重载此函数进行预先的数据准备和处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 返回TRUE继续下线；返回FALSE中断下线。
/// </summary>
BOOL CBOF_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// 下线后续处理。在执行下线操作后调用，继承类可重载此函数进行额外处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBOF_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsDelivered( rsMaterialInfo);
}


/// <summary>
/// 返回机组产出记录的类型URI
/// </summary>
CString CBOF_Unit_Mag::GetDeliveryLogType()
{
	return _T("");
}


/// <summary>
/// 准备下料记录数据。
/// ARG >> rsDeliveryLog : 下料记录数据。
/// RET <<void
/// </summary>
void CBOF_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// 返回本机组的通讯器对象的URI
/// </summary>
CString CBOF_Unit_Mag::GetCommunicator()
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
BOOL CBOF_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// 计划下达后续处理。在向下位系统发送计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsSend : 下发下位系统的计划数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBOF_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
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
BOOL CBOF_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// 计划取消后续处理。在向下位系统发送取消计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsCancel : 下发下位系统的计划取消数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBOF_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// 处理材料上线的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CBOF_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// 处理材料进入加工区域的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CBOF_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// 处理材料离开加工区域事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CBOF_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// 处理材料生产完毕事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CBOF_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// 处理机组测量数据变更事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CBOF_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}

	



/// <Method class="CBOF_Unit_Mag" name="GetScrapesForDesignate" type="L3RECORDSET">
/// 获取可选废钢信息记录。返回带有废钢槽号和废钢量的记录集。
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetScrapesForDesignate()
{
	////2009-02-21*Liao
	//CString cssss = _T("select Scrap_Slot_ID,sum(Amount) as Amount,sum(decode(StoreAreaID,'S82A01',Amount,0)) as ScrapWT,");
	//cssss += _T(" sum(Amount)-sum(decode(StoreAreaID,'S82A01',Amount,0)) as PigIronWT,LogDate from CScrap_Output_Log where Iron_Flag = 0 group by Scrap_Slot_ID,LogDate Order by LOGDATE");
	//CString strSQL;
	////strSQL.Format(_T("select Scrap_Slot_ID,sum(Amount) as Amount sum(decode(StoreAearID))from %s where Iron_Flag = 0 group by Scrap_Slot_ID"),SCRAP_OUT_CLASS_URI);
	//strSQL.Format(cssss,SCRAP_OUT_CLASS_URI);
	//
	//CL3RecordSetWrap rs;
	//if(!Query(strSQL,rs))
	//	return NULL;
	//else
	//	return rs.Detach();

  //2016-01-27 ren

		CString cssss = _T("select Scrap_Slot_ID,sum(Amount) as Amount,sum(decode(StoreAreaID,'S82A01',Amount,0)) as ScrapWT,");
	cssss += _T(" sum(Amount)-sum(decode(StoreAreaID,'S82A01',Amount,0)) as PigIronWT,LogDate from CScrap_Output_Log where Iron_Flag = 0   group by Scrap_Slot_ID,LogDate Order by LOGDATE");
	//cssss += _T(" sum(Amount)-sum(decode(StoreAreaID,'S82A01',Amount,0)) as PigIronWT,LogDate from   CScrap_Output_Log  where Iron_Flag = 0 and  Scrap_Slot_ID   not like 'B%' group by Scrap_Slot_ID,LogDate Order by LOGDATE");
	/*CString strSQL;*/

	//strSQL.Format(_T("select Scrap_Slot_ID,sum(Amount) as Amount sum(decode(StoreAearID))from %s where Iron_Flag = 0 group by Scrap_Slot_ID"),SCRAP_OUT_CLASS_URI);
	//strSQL.Format(cssss,SCRAP_OUT_CLASS_URI);
	
	CL3RecordSetWrap rs;
	if(!Query(cssss,rs))
		return NULL;
	else
		return rs.Detach();

}

/// 计算下一炉号
CString CBOF_Unit_Mag::CalculateNextHeatID (LPCTSTR lpcszHeatID)
{
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strHeatID(lpcszHeatID); strHeatID.Trim();
	CString strNextID; 	
	if(strHeatID.IsEmpty())
	{
		CString strID = GetIdentity().ToCString();
		strID = strID.Mid(2,1);
		LONG nYear = curTime.GetYear();
		nYear = nYear - (nYear / 100) * 100;
		strNextID.Format(_T("2%s%02d%05d"),(LPCTSTR)strID,nYear,(INT)1);
	}
	else
	{
		CString strIDHead = strHeatID.Left(2);
		CString strIDYear = strHeatID.Mid(2,2);
		CString strIDSeq = strHeatID.Mid(4,strHeatID.GetLength()-4);
		LONG nYear = 0, nSeq = 0;
		_stscanf_s(strIDYear,_T("%d"),&nYear);
		_stscanf_s(strIDSeq,_T("%d"),&nSeq);
		LONG nCurYear = curTime.GetYear();
		nCurYear = nCurYear - (nCurYear / 100) * 100;
		if(nYear != nCurYear)
		{
			nYear = nCurYear;
			nSeq = 1;
		}
		else
			nSeq ++;
		strNextID.Format(_T("%s%02d%05d"),strIDHead,nYear,nSeq);
	}
	return strNextID;
}

/// 从计划里获取下一炉号
CString CBOF_Unit_Mag::FindNextHeatIDFromPlan()
{
	//2008-12-26炉号改为从计划获取，tangyi
	CString csUnitID = GetIdentity().ToCString();
	CString csSQL;
	csSQL.Format(_T("select min(HeatID) from CPlan_Tapping where Status ='%s' and BOFID ='%s' "),TAPPING_PLAN_STATUS_SEND,csUnitID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return _T("");
	rs.MoveFirst();
	return rs.GetFieldByIndex(0).ToCString();
}

/// 通用转炉过程状态修改函数
BOOL CBOF_Unit_Mag::ChangeBOFStatus(LONG nStatus)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 修改转炉状态
	if ((nStatus < CBOF_Unit_Mag::BOFSplash) || (Status >= CBOF_Unit_Mag::BOFTapped)) //2009-01-09若出钢结束状态未到达且溅渣、倒渣信号到达时,只记录状态信息,不变更转炉状态
	{
		if(!SetPropValue(_T("Status"),CL3Variant(nStatus)))
		{
			if(nTrans > 0)
				Rollback(nTrans); 
			return FALSE;
		}
	}

	// 记录事件日志
	CL3RecordSetWrap rsStatus;
	if(!CreateClassPropSet(BOF_PROC_STATUS_CLASS_URI,rsStatus))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsStatus.AppendRecord();

	if (nStatus == CBOF_Unit_Mag::BOFWaiting)
	  rsStatus.SetFieldByName(_T("HeatID"),GetPropValue(_T("NextHeatID")));
	else
      rsStatus.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));

	rsStatus.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsStatus.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	if(CreateNewObjects(BOF_PROC_STATUS_CLASS_URI,rsStatus) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}

/// 通用计划状态修改函数
BOOL CBOF_Unit_Mag::ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status)
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
	rsPlanStatus.SetFieldByName(_T("UnitType"),CL3Variant(_T("2")));
	rsPlanStatus.SetFieldByName(_T("TreatNo"),CL3Variant(lpcszTreatNo));
	rsPlanStatus.SetFieldByName(_T("UnitStatus"),CL3Variant(Status));
	rsPlanStatus.SetFieldByName(_T("StatusChangeTime"),CL3Variant(COleDateTime::GetCurrentTime()));
	CL3Variant valRet = InvokeObjectMethod(PLAN_OBJ_URI,_T("ModifyPlanExecutionStatus"),(L3RECORDSET)rsPlanStatus);
	return valRet.ToBOOL();
}


/// <Method class="CBOF_Unit_Mag" name="FeedIrons" type="L3BOOL">
/// 进行兑铁。使用事先指定的铁水和废钢斗进行兑铁。
/// </Method>
///2009-02-28 因邢钢实际的需要，对兑铁逻辑做大的修改，指定主原料放在兑铁之后
L3BOOL CBOF_Unit_Mag::FeedIrons()
{
	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return FALSE;

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		Rollback(nTrans);
		return FALSE;
	}

	//检查转炉计划数，如果小于3给调度提示
	CString csUnitID = GetIdentity().ToCString();
	CString csTempSQL =_T(" select count(*) as PlanCount from CPlan_Tapping where status = %s and BOFID ='%s' ");
	CString csSQL;
	csSQL.Format(csTempSQL,TAPPING_PLAN_STATUS_SEND,csUnitID);
	CL3RecordSetWrap rsPlanCount;
	if(!Query(csSQL,rsPlanCount))
	{
		Rollback(nTrans);
		return FALSE;
	}
	rsPlanCount.MoveFirst();
	L3LONG nPlanCount = rsPlanCount.GetFieldByIndex(0).ToLong();
	if(nPlanCount < 3)
	{
		//改变属性值通知调度及时下计划 2009-03-03 tangyi
		CL3Variant varStoreEvent = GetPropValue(_T("Plan_Count"));
		L3SHORT nStoreEvent = varStoreEvent.ToShort();
		nStoreEvent = (nStoreEvent+1) % 9999;
		SetPropValue(_T("Plan_Count"),nStoreEvent);
	}

	// 检查转炉状态,未作兑铁准备不允许兑铁
	if(Status != CBOF_Unit_Mag::BOFWaiting)
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	CString strHeatID = NextHeatID;

	// 炉号变更
	HeatID = NextHeatID;

	//产生下一炉号2009-03-26 tangyi兑铁时计算下一炉号，用于计量，但不从计划中获取
	NextHeatID = CalculateNextHeatID(strHeatID);

	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// 查询对应出钢计划数据
	CString strSQLPlan; strSQLPlan.Format(_T("select * from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,GetRealHeatID(strHeatID));
	CL3RecordSetWrap rsPlan;
	if(!Query(strSQLPlan,rsPlan) || rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
	{	// 计划不存在
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_PLANNOTEXIST);
		return FALSE;
	}

	rsPlan.MoveFirst();

	// 修改当前转炉数据
	SteelGradeIndex = rsPlan.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	

	// 产生转炉炉次基本数据CBOF_Base_Data
	CL3RecordSetWrap rsBaseData;
	if(!CreateClassPropSet(BOF_BASE_DATA_CLASS_URI,rsBaseData))
	{
		Rollback(nTrans);
		return FALSE;
	}
	rsBaseData.AppendRecord();
	rsBaseData.CopyCurRowFrom(rsPlan);
	rsBaseData.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rsBaseData.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsBaseData.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
	CString csObj = GetName() + rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(UNIT_DUTY_CLASS_URI,csObj);
	rsBaseData.SetFieldByName(_T("HeadFurnace"),GetObjectPropValue(csUri,_T("HeadFurnace")));
	rsBaseData.SetFieldByName(_T("Assistant"),GetObjectPropValue(csUri,_T("Assistant")));
	rsBaseData.SetFieldByName(_T("SecondHand"),GetObjectPropValue(csUri,_T("SecondHand")));
	rsBaseData.SetFieldByName(_T("ProductionDate"),CL3Variant(curTime));
	rsBaseData.SetFieldByName(_T("StatisticsDate"),CL3Variant(curTime));
	rsBaseData.SetFieldByName(_T("Locked"),CL3Variant((LONG)0));
	rsBaseData.SetFieldByName(_T("SteelGrade"),GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + SteelGradeIndex,_T("SteelGrade")));//2009-01-11 tangyi
	if(CreateNewObjects(BOF_BASE_DATA_CLASS_URI,rsBaseData) < 1)
	{
		Rollback(nTrans);
		return FALSE;
	}

	// 产生过程数据
	CL3RecordSetWrap rsProc;
	if(!CreateClassPropSet(BOF_PROCESS_DATA_CLASS_URI,rsProc))
	{
		Rollback(nTrans);
		return FALSE;
	}
	rsProc.AppendRecord();
	rsProc.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	rsProc.SetFieldByName(_T("Charging_Start_Time"),CL3Variant(curTime));
	if(!CreateNewObjects(BOF_PROCESS_DATA_CLASS_URI,rsProc))
	{
		Rollback(nTrans);
		return FALSE;
	}

	// 修改转炉状态
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFFeeding))
	{
		Rollback(nTrans);
		return FALSE;
	}

	// 创建炉次质量初始等级
	rsPlan.MoveFirst();
	InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQuality_Mag\\Quality_Mag"),_T("CreateHeatGradeQAData"),(LPCTSTR)GetName(),(L3RECORDSET)rsPlan);


	// 重置吹炼时间
	BlowTotalTime = 0;
	BlowThisTime = 0;

	Commit(nTrans);

	// 修改计划状态
	ChangePlanStatus(strHeatID,strHeatID,TAPPING_PLAN_BOF_STATUS_IRON);

	/// 向检化验发送浇铸信息2009-01-03 tangyi
	L3STRING strBOFHeatID = HeatID.AllocSysString();
	SendCastingDataToAnaL2(strBOFHeatID);
	L3SysFreeString(strBOFHeatID);

	return TRUE;
}


/// <Method class="CBOF_Unit_Mag" name="DesignateIrons" type="L3LONG">
/// 指定主原料
/// <Param name="rsIrons" type="L3RECORDSET">铁水信息,应至少包含MaterialID</Param>
///2009-02-28
/// </Method>
L3LONG CBOF_Unit_Mag::DesignateMainMaterial(L3RECORDSET rsIrons,L3RECORDSET rsReturnSteel,L3RECORDSET rsScrapes)
{
	CL3RecordSetWrap rsIron = rsIrons;
	if(rsIron.GetRowCount() < 1)
		return -1;

	// 检查数据
	if(rsIron.GetFieldIndex(_T("MaterialID")) < 0 || rsIron.GetFieldIndex(_T("HeatID")) < 0 )
		return -2;

	CL3RecordSetWrap rsRtnSteel = rsReturnSteel;
	if(rsRtnSteel.GetRowCount() != 1)
		return -3;

	// 检查数据
	if(rsRtnSteel.GetFieldIndex(_T("HeatID")) < 0 || rsRtnSteel.GetFieldIndex(_T("Return_Steel_Weight")) < 0 )
		return -4;


	CL3RecordSetWrap rsScrap = rsScrapes;
	if(rsScrap.GetRowCount() > 0)
	{
		// 检查数据
		if(rsScrap.GetFieldIndex(_T("Scrap_Slot_ID")) < 0)
			return -5;
	}


	// 检查当前转炉状态,出钢结束以前都可以指定主原料
	if(Status < CBOF_Unit_Mag::BOFFeeding || Status > CBOF_Unit_Mag::BOFTapping)
		return -6;


	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -7;
	}

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -8;
	}

	//获取炉号
	CString strHeatID =HeatID;

	// 计算废钢和生铁量
	double ScrapeWeight = 0, PigIronWeight = 0;

	if(rsScrap.GetRowCount() > 0)
	{
		// 准备废钢斗条件
		CString strSlots;
		rsScrap.MoveFirst();
		while(!rsScrap.IsEOF())
		{
			if(!strSlots.IsEmpty())
				strSlots += _T(",");
			strSlots += CString(_T("'")) + rsScrap.GetFieldByName(_T("Scrap_Slot_ID")).ToCString() + CString(_T("'"));
			rsScrap.MoveNext();
		}

		// 查询废钢生铁出库记录
		CString strSQL;
		strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag from %s where Iron_Flag = 0 and Scrap_Slot_ID in (%s)"),SCRAP_OUT_CLASS_URI,strSlots);
		CL3RecordSetWrap rsLog;
		if(!Query(strSQL,rsLog))
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -12;
		}
		// 修改废钢生铁出库记录
		rsLog.MoveFirst();
		while(!rsLog.IsEOF())
		{
			rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
			rsLog.SetFieldByName(_T("Iron_Flag"),CL3Variant((LONG)1));
			rsLog.MoveNext();
		}
		rsLog.MoveFirst();
		if(!SetObjsPropValues(SCRAP_OUT_CLASS_URI,rsLog))
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -13;
		}

		// 获取已指定的废钢生铁斗信息
		CL3RecordSetWrap rsScrapDesignated;
		rsScrapDesignated.Attach(GetInputScrapes());
		
		rsScrapDesignated.MoveFirst();
		while(!rsScrapDesignated.IsEOF())
		{
			// 根据出库来源库位来判断是废钢还是生铁
			CString strAreaID = rsScrapDesignated.GetFieldByName(_T("StoreAreaID")).ToCString();
			double fW = rsScrapDesignated.GetFieldByName(_T("Amount")).ToDouble();
			if(strAreaID == _T("S82A01"))
			{	// 废钢库区
				ScrapeWeight += fW;
			}
			else
			{	// 生铁库区
				PigIronWeight += fW;
			}
			rsScrapDesignated.MoveNext();
		}
	}


	// 产生转炉炉次原料数据CBOF_Feed_Data
	// 准备铁水记录集
	CL3RecordSet* pRS = new CL3RecordSet();
	CL3RecordSetWrap rsSet; pRS->QueryInterface(IID_IL3RecordSet,rsSet);
	rsSet.AddField(_T("MaterialID"),VT_BSTR);
	rsSet.AddField(_T("HeatID"),VT_BSTR);
	rsIron.MoveFirst();
	rsSet.CopyFrom(rsIron);
	rsSet.MoveFirst();
	while(!rsSet.IsEOF())
	{
		rsSet.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		rsSet.MoveNext();
	}

	// 修改铁水信息
	rsSet.MoveFirst();
	if(!SetObjsPropValues(MATERIAL_IRON_URI,rsSet))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -9;
	}

	// 获取已指定的铁水
	CL3RecordSetWrap rsIronsDesignated;
	rsIronsDesignated.Attach(GetInputIrons());
	if(rsIronsDesignated.GetRowCount() < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -10;
	}

	// 将铁水上线，移入转炉生产区
	rsIronsDesignated.MoveFirst();
	if(!FeedMaterials(rsIronsDesignated))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -11;
	}
   
	// 计算兑铁量及成分
	double C=0,Si=0,Mn=0,P=0,S=0,Ti=0,Temp=0;
	double Sn=0,Sb=0,As=0,Pb=0;//add by hyh 2012-04-05

	double IronWeight = 0;//2009-02-16 tangyi
	double Return_Steel_Weight = 0; //2009-03-09
	rsIronsDesignated.MoveFirst();
	while(!rsIronsDesignated.IsEOF())
	{	
		double fW = rsIronsDesignated.GetFieldByName(_T("Weight")).ToDouble();
		double fC = rsIronsDesignated.GetFieldByName(_T("C")).ToDouble();
		double fSi = rsIronsDesignated.GetFieldByName(_T("Si")).ToDouble();
		double fMn = rsIronsDesignated.GetFieldByName(_T("Mn")).ToDouble();
		double fP = rsIronsDesignated.GetFieldByName(_T("P")).ToDouble();
		double fS = rsIronsDesignated.GetFieldByName(_T("S")).ToDouble();
		double fTi = rsIronsDesignated.GetFieldByName(_T("Ti")).ToDouble();

		//add by hyh 2012-04-05
		double fSn = rsIronsDesignated.GetFieldByName(_T("Sn")).ToDouble();
		double fSb = rsIronsDesignated.GetFieldByName(_T("Sb")).ToDouble();
		double fAs = rsIronsDesignated.GetFieldByName(_T("As")).ToDouble();
		double fPb = rsIronsDesignated.GetFieldByName(_T("Pb")).ToDouble();
		//end

		double fTmp = rsIronsDesignated.GetFieldByName(_T("IronTemp")).ToDouble();
		double fReHeatWeight = rsIronsDesignated.GetFieldByName(_T("Return_Steel_Weight")).ToDouble();//2009-03-09
		Return_Steel_Weight += fReHeatWeight; //2009-03-09
		Temp += fTmp;
		C += fW * fC;
		Si += fW * fSi;
		Mn += fW * fMn;
		P += fW * fP;
		S += fW * fS;
		Ti += fW * fTi;
		//add by hyh 2012-04-05
		Sn += fW * fSn;
		Sb += fW * fSb;
		As += fW * fAs;
		Pb += fW * fPb;
		//end
		IronWeight += fW;
		// 修改铁包状态为热备
		CString strLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,rsIronsDesignated.GetFieldByName(_T("IronLadleNo")).ToCString());
		SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT));	
		rsIronsDesignated.MoveNext();
	}

	//不经过混铁炉回炉钢
	rsRtnSteel.MoveFirst();
	rsRtnSteel.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	L3DOUBLE nWeight = rsRtnSteel.GetFieldByName(_T("Return_Steel_Weight")).ToDouble();
	CString  csSteelGrade = rsRtnSteel.GetFieldByName(_T("Return_SteelGrade")).ToCString();
	Return_Steel_Weight += nWeight;

	//以前已经指定过主原料的量重新参与计算2009-03-26
	CString csTemp = _T(" select * from %s  where HeatID  ='%s' ");
	CString csSQL;
	csSQL.Format(csTemp,BOF_FEED_DATA_CLASS_URI,strHeatID);
	CL3RecordSetWrap rsFeedFirData;
	if(!Query(csSQL,rsFeedFirData))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -8;
	}

	rsFeedFirData.MoveFirst();
	while(!rsFeedFirData.IsEOF())
	{
		double fW = rsFeedFirData.GetFieldByName(_T("IronWeight")).ToDouble();
		double fC = rsFeedFirData.GetFieldByName(_T("C")).ToDouble();
		double fSi = rsFeedFirData.GetFieldByName(_T("Si")).ToDouble();
		double fMn = rsFeedFirData.GetFieldByName(_T("Mn")).ToDouble();
		double fP = rsFeedFirData.GetFieldByName(_T("P")).ToDouble();
		double fS = rsFeedFirData.GetFieldByName(_T("S")).ToDouble();
		double fTi = rsFeedFirData.GetFieldByName(_T("Ti")).ToDouble();

		//add by hyh 2012-04-05
		double fSn = rsFeedFirData.GetFieldByName(_T("Sn")).ToDouble();
		double fSb = rsFeedFirData.GetFieldByName(_T("Sb")).ToDouble();
		double fAs = rsFeedFirData.GetFieldByName(_T("As")).ToDouble();
		double fPb = rsFeedFirData.GetFieldByName(_T("Pb")).ToDouble();
		//end

		double fTmp = rsFeedFirData.GetFieldByName(_T("IronTemp")).ToDouble();
		double fReHeatWeight = rsFeedFirData.GetFieldByName(_T("Return_Steel_Weight")).ToDouble();
		double fPigIronWeight = rsFeedFirData.GetFieldByName(_T("PigIronWeight")).ToDouble();
		double fScrapWeight = rsFeedFirData.GetFieldByName(_T("ScrapWeight")).ToDouble();
		Temp += fTmp;
		C += fW * fC;
		Si += fW * fSi;
		Mn += fW * fMn;
		P += fW * fP;
		S += fW * fS;
		Ti += fW * fTi;

		//add by hyh 2012-04-05
		Sn += fW * fSn;
		Sb += fW * fSb;
		As += fW * fAs;
		Pb += fW * fPb;
		//end

		IronWeight += fW;	
		ScrapeWeight  += fScrapWeight;
		PigIronWeight += fPigIronWeight;
		Return_Steel_Weight += fReHeatWeight;
		rsFeedFirData.MoveNext();
	}

	Temp = Temp / (rsIronsDesignated.GetRowCount() + rsFeedFirData.GetRowCount());
	C = C / IronWeight;
	Si = Si / IronWeight;
	Mn = Mn / IronWeight;
	P = P / IronWeight;
	S = S / IronWeight;
	Ti = Ti / IronWeight;
	//add by hyh 2012-04-05
	Sn = Sn / IronWeight;
	Sb = Sb / IronWeight;
	As = As / IronWeight;
	Pb = Pb / IronWeight;
	//end

	CurTemp = Temp;


	CL3RecordSetWrap rsFeedData;
	if(!CreateClassPropSet(BOF_FEED_DATA_CLASS_URI,rsFeedData))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -16;
	}
	rsFeedData.AppendRecord();
	rsFeedData.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	rsFeedData.SetFieldByName(_T("IronWeight"),CL3Variant(IronWeight));//2009-02-16 tangyi
	rsFeedData.SetFieldByName(_T("ScrapWeight"),CL3Variant(ScrapeWeight));
	rsFeedData.SetFieldByName(_T("PigIronWeight"),CL3Variant(PigIronWeight));
	rsFeedData.SetFieldByName(_T("Return_Steel_Weight"),CL3Variant(Return_Steel_Weight));//2009-01-02 tangyi
	rsFeedData.SetFieldByName(_T("Return_SteelGrade"),CL3Variant(csSteelGrade));//2009-03-09 tangyi
	rsFeedData.SetFieldByName(_T("C"),CL3Variant(C));
	rsFeedData.SetFieldByName(_T("Si"),CL3Variant(Si));
	rsFeedData.SetFieldByName(_T("Mn"),CL3Variant(Mn));
	rsFeedData.SetFieldByName(_T("P"),CL3Variant(P));
	rsFeedData.SetFieldByName(_T("S"),CL3Variant(S));
	rsFeedData.SetFieldByName(_T("Ti"),CL3Variant(Ti));
	//add by hyh 2012-04-05
	rsFeedData.SetFieldByName(_T("Sn"),CL3Variant(Sn));
	rsFeedData.SetFieldByName(_T("Sb"),CL3Variant(Sb));
	rsFeedData.SetFieldByName(_T("As"),CL3Variant(As));
	rsFeedData.SetFieldByName(_T("Pb"),CL3Variant(Pb));
	//end
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	rsFeedData.SetFieldByName(_T("LogTime"),CL3Variant(curTime));
	rsFeedData.SetFieldByName(_T("IronTemp"),CL3Variant(Temp));

	Load = IronWeight + ScrapeWeight + PigIronWeight + Return_Steel_Weight;//装入量
	rsFeedFirData.MoveFirst();
	if(rsFeedFirData.GetRowCount() > 0)
	{
		if(DeleteOldObjects(BOF_FEED_DATA_CLASS_URI,rsFeedFirData) < 0)
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -17;
		}
	}
	if(CreateNewObjects(BOF_FEED_DATA_CLASS_URI,rsFeedData) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -17;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return 0;

}

/// <Method class="CCCM_Unit_Mag" name="CompletCasting" type="L3BOOL">
/// 向检化验发送浇铸信息,方法单独写以备信息重发。2009-01-03 tangyi
/// </Method>
L3BOOL CBOF_Unit_Mag::SendCastingDataToAnaL2(L3STRING strHeatID)
{

	//组建数据集
	CString csHeatID = strHeatID;
	CString csSQL;
	CL3RecordSetWrap rsCasting;
	csSQL.Format(_T("select a.HeatID,NULL as CastingNo,a.CasterID as CCMID,a.SteelGradeIndex,NULL as SteelGrade,to_Char(b.Act_Time_IronPrepared,'yyyy-mm-dd hh24:mi:ss') as ProductionDate, 1 as PERMIT_DELETE_FLAG from CPlan_Tapping a,CPlan_Tapping_Act b where a.PlanID = b.PreHeatID and a.HeatID ='%s'"),csHeatID);
	if(!Query(csSQL,rsCasting) || rsCasting.IsNull() || rsCasting.GetRowCount() <1)
		return false;
	rsCasting.MoveFirst();
	CString csSteelGradeIndex = rsCasting.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	rsCasting.SetFieldByName(_T("SteelGrade"),GetObjectPropValue(QA_STG_RELATION_CLASS_URI+_T("\\")+csSteelGradeIndex,_T("SteelGrade")));
	//L3LONG nPosID = 2;
	//CString csTableName = _T("TB_L3_CHANGECAST");
	//L3STRING strTableName = csTableName.AllocSysString();
	//InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
	//				    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
	//					strTableName,(L3RECORDSET)rsCasting);Waiting
	//L3SysFreeString(strTableName);

	//csTableName = _T("TB_L3_CHANGECASTHIS");
	//strTableName = csTableName.AllocSysString();
	//InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
	//				    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
	//					strTableName,(L3RECORDSET)rsCasting);
	//L3SysFreeString(strTableName);

	rsCasting.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\TB_L3_CHANGECAST"),rsCasting) < rsCasting.GetRowCount())
		return false;

	return true;

}


/// <Method class="CBOF_Unit_Mag" name="FeedElement" type="L3BOOL">
/// 向转炉中加料。
/// <Param name="rsElement" type="L3RECORDSET">加料数据，包含类型，辅料代码，料量</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::FeedElement(L3RECORDSET rsElement)
{
	CL3RecordSetWrap rs = rsElement;
	if(rs.GetRowCount() < 1)
		return FALSE;

	if(rs.GetFieldIndex(_T("Element")) < 0 ||
		rs.GetFieldIndex(_T("Type")) < 0 ||
		rs.GetFieldIndex(_T("Weight")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldIndex(_T("Discharge_Time")) < 0)
	{
		bUseTimeNow = TRUE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 获取炉号
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// 记录加料记录
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_ADDITION_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		if(bUseTimeNow)
			rsLog.SetFieldByName(_T("Discharge_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(BOF_ADDITION_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="TopBlowing" type="L3BOOL">
/// 处理并记录转炉顶吹事件。
/// <Param name="rsBlow" type="L3RECORDSET">顶吹数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::TopBlowing(L3RECORDSET rsBlow)
{
	CL3RecordSetWrap rs = rsBlow;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// 检查数据
	if(rs.GetFieldByName(_T("Flow")) < 0 ||
		rs.GetFieldByName(_T("Pressure")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldByName(_T("Catch_Time")) < 0)
	{
		bUseTimeNow = TRUE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 获取炉号
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// 记录顶吹记录
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_TOP_BLOWING_CLASS_URI,rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		if(bUseTimeNow)
			rsLog.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(BOF_TOP_BLOWING_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 更新当前顶吹数据
	rsLog.MoveFirst();
	L3DATETIME dtMax = 0;
	while(!rsLog.IsEOF())
	{
		L3DATETIME dt = rsLog.GetFieldByName(_T("Catch_Time")).ToDateTime();
		if(dt > dtMax)
		{
			SetPropValue(_T("TopFlow"),rsLog.GetFieldByName(_T("Flow")));
			SetPropValue(_T("TopPressure"),rsLog.GetFieldByName(_T("Pressure")));
			dtMax = dt;
		}
		rsLog.MoveNext();
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="BottomBlowing" type="L3BOOL">
/// 处理并记录底吹事件。
/// <Param name="rsBlow" type="L3RECORDSET">底吹数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::BottomBlowing(L3RECORDSET rsBlow)
{
	CL3RecordSetWrap rs = rsBlow;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// 检查数据
	if(rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Flow1")) < 0 || rs.GetFieldByName(_T("Pressure1")) < 0 ||
		rs.GetFieldByName(_T("Gas_Type")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldByName(_T("Catch_Time")) < 0)
	{
		bUseTimeNow = TRUE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 获取炉号
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// 记录底吹记录
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_BOTTOM_BLOWING_CLASS_URI,rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		if(bUseTimeNow)
			rsLog.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(BOF_BOTTOM_BLOWING_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 更新当前底吹数据
	rsLog.MoveFirst();
	L3DATETIME dtMax = 0;
	while(!rsLog.IsEOF())
	{
		L3DATETIME dt = rsLog.GetFieldByName(_T("Catch_Time")).ToDateTime();
		if(dt > dtMax)
		{
			SetPropValue(_T("BottomFlow1"),rsLog.GetFieldByName(_T("Flow1")));
			SetPropValue(_T("BottomPressure1"),rsLog.GetFieldByName(_T("Pressure1")));
			SetPropValue(_T("BottomFlow2"),rsLog.GetFieldByName(_T("Flow2")));
			SetPropValue(_T("BottomPressure2"),rsLog.GetFieldByName(_T("Pressure2")));
			SetPropValue(_T("BottomFlow3"),rsLog.GetFieldByName(_T("Flow3")));
			SetPropValue(_T("BottomPressure3"),rsLog.GetFieldByName(_T("Pressure3")));
			SetPropValue(_T("BottomFlow4"),rsLog.GetFieldByName(_T("Flow4")));
			SetPropValue(_T("BottomPressure4"),rsLog.GetFieldByName(_T("Pressure4")));
			SetPropValue(_T("BottomFlow5"),rsLog.GetFieldByName(_T("Flow5")));
			SetPropValue(_T("BottomPressure5"),rsLog.GetFieldByName(_T("Pressure5")));
			SetPropValue(_T("BottomFlow6"),rsLog.GetFieldByName(_T("Flow6")));
			SetPropValue(_T("BottomPressure6"),rsLog.GetFieldByName(_T("Pressure6")));
			dtMax = dt;
		}
		rsLog.MoveNext();
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="StartBlowing" type="L3BOOL">
/// 转炉进入吹炼
/// <Param name="bMainBlowing" type="L3BOOL">主吹标识</Param>
/// <Param name="Catch_Time" type="L3DATETIME">开始时刻</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::StartBlowing(L3BOOL bMainBlowing, L3DATETIME Catch_Time)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	COleDateTime curTime = COleDateTime::GetCurrentTime();
	if(Catch_Time < 100)
		Catch_Time = (DATE)curTime;

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查转炉状态2009-01-02 tangyi
	if(Status > CBOF_Unit_Mag::BOFReBlowing || Status < CBOF_Unit_Mag::BOFFeeding)
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}


	// 修改当前状态
	if(!ChangeBOFStatus(bMainBlowing ? CBOF_Unit_Mag::BOFBlowing : CBOF_Unit_Mag::BOFReBlowing))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 修改过程数据
	CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,HeatID);
	if (bMainBlowing)
	{
		SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
		StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	}

	//StartProcessTime = curTime.Format(_T("%Y%m%d%H%M%S"));//2008-12-26
	//CString cs = curTime.Format(_T("%Y-%m-%d %H:%M:%S"));

	// 触发吹炼事件
	BlowingEvent = bMainBlowing ? 1 : 2;

	
	if(nTrans > 0)
		Commit(nTrans);

	// 修改计划状态
	if(bMainBlowing)
	{
		ChangePlanStatus(HeatID,HeatID,TAPPING_PLAN_BOF_STATUS_BLOW);

		// 开始定时器
		//2009-03-04 Begin
		if(m_nTimer != 0)
			KillTimer(GetURI(),m_nTimer);
		m_nTimer = 0;

		//2009-03-04 End
		BlowTotalTime = 0;
		BlowThisTime = 0;

		m_nTimer = SetTimer(GetURI(),BLOWTIMER_PERIOD); //2009-05-24 屏蔽
	}


	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="StopBlowing" type="L3BOOL">
/// 转炉结束吹炼
/// <Param name="Catch_Time" type="L3DATETIME">结束时刻</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::StopBlowing(L3DATETIME Catch_Time)
{
	if(Catch_Time < 100)
		Catch_Time = COleDateTime::GetCurrentTime();

	LONG nCurStatus = Status;
	if(nCurStatus == CBOF_Unit_Mag::BOFBlowing ||
		nCurStatus == CBOF_Unit_Mag::BOFReBlowing)
	{	// 当前是吹炼状态，触发吹炼结束事件
		BlowingEvent = 0;
	}

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="SetOxygen" type="L3BOOL">
/// 处理并记录定氧事件。
/// <Param name="rsOxygen" type="L3RECORDSET">定氧数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::SetOxygen(L3RECORDSET rsOxygen)
{
	CL3RecordSetWrap rs = rsOxygen;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// 检查数据
	if(rs.GetFieldIndex(_T("Oxygen_Content")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldIndex(_T("Measure_Time")) < 0)
	{
		bUseTimeNow = TRUE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 获取炉号
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// 记录定氧记录
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_OXYGEN_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		if(bUseTimeNow)
			rsLog.SetFieldByName(_T("Measure_Time"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(BOF_OXYGEN_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="SetTemperature" type="L3BOOL">
/// 处理并记录转炉测温事件。
/// <Param name="rsTemp" type="L3RECORDSET">测温数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::SetTemperature(L3RECORDSET rsTemp)
{
	CL3RecordSetWrap rs = rsTemp;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// 检查数据
	if(rs.GetFieldIndex(_T("Temp")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	BOOL bUseTimeNow = FALSE;
	if(rs.GetFieldIndex(_T("Temp_Time")) < 0)
	{
		bUseTimeNow = TRUE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 获取炉号
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// 记录测温记录
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_TEMP_DATA_CLASS_URI,rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	L3DOUBLE fTemp = 0;
	DATE dtTime = 0;
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
		if(bUseTimeNow)
			rsLog.SetFieldByName(_T("Temp_Time"),CL3Variant(curTime));
		DATE dtTimeThis = rsLog.GetFieldByName(_T("Temp_Time")).ToDateTime();
		if(dtTimeThis > dtTime)
		{
			fTemp = rsLog.GetFieldByName(_T("Temp")).ToDouble();
			dtTime = dtTimeThis;
		}
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(BOF_TEMP_DATA_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	CurTemp = fTemp;

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
/// 修改转炉设备状态
/// <Param name="nStatus" type="L3LONG">新设备状态</Param>
/// <Param name="reason" type="L3STRING">原因</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::ChangeDeviceStatus(L3LONG nStatus,L3STRING reason)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 修改设备状态
	//if(!SetPropValue(_T("Status"),CL3Variant(nStatus)))
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return FALSE;
	//}

	if(!SetPropValue(_T("Equip_Status"),CL3Variant(nStatus)))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 记录设备状态变更日志
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_EQUIPMENT_STATUS_CLASS_URI,rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsLog.AppendRecord();
	CString cstrUnitID = (GetIdentity().ToCString()).Right(1);
	rsLog.SetFieldByName(_T("BOFID"),(L3LONG)_ttoi(cstrUnitID));
	rsLog.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsLog.SetFieldByName(_T("Log_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsLog.SetFieldByName(_T("Reason"),CL3Variant(reason));
	if(CreateNewObjects(BOF_EQUIPMENT_STATUS_CLASS_URI,rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="StartTapping" type="L3BOOL">
/// 处理出钢开始事件
/// </Method>
L3BOOL CBOF_Unit_Mag::StartTapping()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 检查转炉状态2009-01-02 tangyi
	if(Status > CBOF_Unit_Mag::BOFReBlowing || Status < CBOF_Unit_Mag::BOFFeeding)
	{	// 已经出过钢
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	COleDateTime curTime = COleDateTime::GetCurrentTime();
	// 修改过程数据
	CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,HeatID);
	SetObjectPropValue(strProcData,_T("Tapping_Strat_Time"),CL3Variant(curTime));

	// 修改转炉状态
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFTapping))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	//2008-12-26tangyi添加以下信息
	
	L3STRING strHeatID = HeatID.AllocSysString();
	if(!CaculateLadleGrade(COleDateTime::GetCurrentTime(),strHeatID))
	{
		L3SysFreeString(strHeatID);
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	L3SysFreeString(strHeatID);

	// 计算下一炉号2009-02-10  tangyi 2009-03-26 在兑铁时产生
	//CString strNextID = CalculateNextHeatID(HeatID);
	//NextHeatID = strNextID;

	if(nTrans > 0) Commit(nTrans);

	
	// 修改计划状态
	ChangePlanStatus(HeatID,HeatID,TAPPING_PLAN_BOF_STATUS_TAPPING);


	CalculateTappingTemp();//2009-01-10 
	CalculateTappedOxygenContent();//2009-01-10 

	

	//2009-03-04 Begin
	if(m_nTimer != 0)
		KillTimer(GetURI(),m_nTimer);
	m_nTimer = 0;
	//2009-03-04 End

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="CaculateLadleGrade" type="L3BOOL">
/// 计算钢包等级2008-12-28
/// </Method>
L3BOOL CBOF_Unit_Mag::CaculateLadleGrade(L3DATETIME dtTapTime,L3STRING strHeatID)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	CString csSQL;
	csSQL.Format(_T("select * from CLadle_Use where ComFlag = 0 order by Input_Time asc "));
	CL3RecordSetWrap rsLadle;
	if(!Query(csSQL,rsLadle))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rsLadle.MoveFirst();
	CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,strHeatID);
	CString strSteelData = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,strHeatID);
	CString csUnitID =GetIdentity().ToCString();
	while(!rsLadle.IsEOF())
	{
		CString csBOFID = rsLadle.GetFieldByName(_T("BOFID")).ToCString();
		if(csBOFID!=csUnitID)
		{
			rsLadle.MoveNext();
			continue;
		}
		else
		{
			//修改钢包信息
			CString csLadleID = rsLadle.GetFieldByName(_T("LadleID")).ToCString();
			CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
			L3LONG nLadleType = GetObjectPropValue(csLadleUri,_T("LadleType")).ToLong();
			L3LONG nAge = rsLadle.GetFieldByName(_T("Ladle_Age")).ToLong();//[2009-03-19 Liao] GetObjectPropValue(csLadleUri,_T("Ladle_Age")).ToLong();
			
			SetObjectPropValue(csLadleUri,_T("Ladle_Age"),CL3Variant(L3LONG(nAge)));
			SetObjectPropValue(csLadleUri, _T("Status"), CL3Variant(CLADLE_STATUS_USE));
			//修改转炉实绩数据
			SetObjectPropValue(strProcData,_T("LadleNo"),CL3Variant(csLadleID));
			SetObjectPropValue(strSteelData,_T("LadleID"),CL3Variant(csLadleID));//作为钢包上件后备补录出钢开始用
			//修改钢包上件实绩
			CString csGuid = rsLadle.GetFieldByName(_T("GUID")).ToCString(); 
			//[计算包况和实际包况相同时重新计算包况；否则不重新计算]2009-03-03
			CString csLadleGrade_Cal =  rsLadle.GetFieldByName(_T("Ladle_Grade")).ToCString(); 
			CString csLadleGrade_Act =  rsLadle.GetFieldByName(_T("Act_Ladle_Grade")).ToCString(); 

			CString csLadleUseUri = CLADLE_USE_URI + _T("\\") + csGuid;
			SteelGradeIndex.Trim();
			if(!SteelGradeIndex.IsEmpty())
			{
				CString csSteelGradeIndexUri = QA_STG_RELATION_CLASS_URI + _T("\\") + SteelGradeIndex;
				SetObjectPropValue(csLadleUseUri,_T("Steel_Grade"),GetObjectPropValue(csSteelGradeIndexUri,_T("SteelGrade")));	
			}
			SetObjectPropValue(csLadleUseUri,_T("HeatID"),CL3Variant(strHeatID));
			SetObjectPropValue(csLadleUseUri,_T("ComFlag"),CL3Variant(L3LONG(1)));	
			//SetObjectPropValue(csLadleUseUri,_T("Tap_Time"),COleDateTime::GetCurrentTime());
			SetObjectPropValue(csLadleUseUri,_T("Tap_Time"),CL3Variant(dtTapTime));
			//获取钢包到上件时间2009-02-20
			L3DATETIME dtArrTime = rsLadle.GetFieldByName(_T("Arrive_Time")).ToDateTime();
			L3DATETIME dtIrrEndTime = rsLadle.GetFieldByName(_T("Irr_End_Time")).ToDateTime();

			//Modify begin by llj 2011-04-24 修改钢包等级的计算时间为：出钢时间-本包的上次大包浇铸结束时间
			//[2009-03-03Liao]
			//COleDateTimeSpan span = dtTapTime - dtArrTime;
			COleDateTimeSpan span = dtTapTime - dtIrrEndTime;
			//Modify end
			L3DOUBLE nTime =  (LONG)span.GetTotalMinutes();
			/*************************************************************************************************/
			//记录钢包上线时间、第一炉炉号，下线时间、最后一炉炉号2009-08-19廖
			//1、根据钢包号获取钢包工作层编号
			CString csLadleWorkID =  GetObjectPropValue(csLadleUri,_T("WorkID")).ToCString();
			//2、判断CLadle_Process表是否存在周转记录
			CString csLadleProcessUri = CLADLE_PROCESS_URI + _T("\\") + csLadleWorkID;
			CString csProcessLadleID = GetObjectPropValue(csLadleProcessUri,_T("LadleID")).ToCString();//获取对应周转记录的钢包号
			if(csProcessLadleID == _T(""))//获取钢包号为空，表示不存在对应的周转记录：新增周转记录
			{
				CString csInnerID = GetObjectPropValue(csLadleUri,_T("InnerID")).ToCString();
				CL3RecordSetWrap rsLadleProcess;
				if(!CreateClassPropSet(CLADLE_PROCESS_URI,rsLadleProcess))
				{
					if(nTrans > 0) Rollback(nTrans);
						return FALSE;
				}
				rsLadleProcess.AppendRecord();
				rsLadleProcess.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));//钢包号
				rsLadleProcess.SetFieldByName(_T("WorkID"),CL3Variant(csLadleWorkID));//工作层编号（关键字）
				rsLadleProcess.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));//永久层编号
				rsLadleProcess.SetFieldByName(_T("Online_Time"),CL3Variant(dtTapTime));//钢包第一炉时间（转炉出钢开始时间）
				rsLadleProcess.SetFieldByName(_T("Online_HeatID"),CL3Variant(strHeatID));//上线第一个炉号
				rsLadleProcess.SetFieldByName(_T("Ladle_Age"),CL3Variant(L3LONG(nAge)));
				
				rsLadleProcess.MoveFirst();
				CreateNewObjects(CLADLE_PROCESS_URI,rsLadleProcess);
			}
			else //存在周转记录：修改下线时间、最后一炉炉号
			{
				SetObjectPropValue(csLadleProcessUri,_T("Offline_Time"),CL3Variant(dtTapTime));
				SetObjectPropValue(csLadleProcessUri,_T("Offline_HeatID"),CL3Variant(strHeatID));
				SetObjectPropValue(csLadleProcessUri,_T("Ladle_Age"),CL3Variant(L3LONG(nAge)));
			}
			/*************************************************************************************************/

			if(csLadleGrade_Cal == csLadleGrade_Act)
			{
				switch(nLadleType)
				{
					case 1: //50吨常规钢包
						if(nTime <=1.5*60) 
							csLadleGrade_Act =_T("A");
						else
							if((1.5*60< nTime) && (nTime<=2.5*60))
								csLadleGrade_Act =_T("B");
							else
								if((2.5*60< nTime) && (nTime<=4.5*60))
									csLadleGrade_Act =_T("C");
								else
									csLadleGrade_Act =_T("D");
					break;
					case 2: //50吨精炼钢包
						if(nTime<=2.5*60) 
							csLadleGrade_Act =_T("A");
						else
							if((2.5*60< nTime) && (nTime<=4.5*60))
								csLadleGrade_Act =_T("B");
							else
								if((4.5*60< nTime) && (nTime <=6.5*60))
									csLadleGrade_Act =_T("C");
								else
									csLadleGrade_Act =_T("D");
					break;
					case 3: //80吨精炼钢包
						if(nTime <=4*60) 
							csLadleGrade_Act =_T("A");
						else
							if((4*60< nTime ) && (nTime <=8*60))
								csLadleGrade_Act =_T("B");
							else
								if((8*60< nTime) && (nTime <=12*60))
									csLadleGrade_Act =_T("C");
								else
									csLadleGrade_Act =_T("D");
					break;
					default:
						break;
				}
			}
			//修改转炉实绩数据
			SetObjectPropValue(strProcData,_T("Ladle_Grade"),CL3Variant(csLadleGrade_Act));
			SetObjectPropValue(strProcData,_T("Ladle_Stop"),CL3Variant(nTime));
			//修改钢包数据
			SetObjectPropValue(csLadleUri,_T("Ladle_Grade"),CL3Variant(csLadleGrade_Act));	
			//修改钢包上件实绩
			SetObjectPropValue(csLadleUseUri,_T("Act_Ladle_Grade"),CL3Variant(csLadleGrade_Act));	
			SetObjectPropValue(csLadleUseUri,_T("Stop_Time_Len"),CL3Variant(nTime));	
			break;
		}			
	}

	if(nTrans > 0) Commit(nTrans);
	return TRUE;
}
/// <Method class="CBOF_Unit_Mag" name="StopTapping" type="L3BOOL">
/// 处理出钢结束事件
/// </Method>
L3BOOL CBOF_Unit_Mag::StopTapping()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	
	// 检查转炉状态2009-01-02 tangyi
	if(Status < CBOF_Unit_Mag::BOFFeeding || Status  > CBOF_Unit_Mag::BOFTapping)
	{	// 已经出过钢
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	CString strHeatID = HeatID;

	COleDateTime curTime = COleDateTime::GetCurrentTime();
	// 修改过程数据
	CString strProcData = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,strHeatID);
	SetObjectPropValue(strProcData,_T("Tapping_End_Time"),CL3Variant(curTime));
	//CL3Variant valStartTime = GetObjectPropValue(strProcData,_T("Tapping_Start_Time"));2009-01-04 tangyi
	CL3Variant valStartTime = GetObjectPropValue(strProcData,_T("Tapping_Strat_Time"));
	
	if(valStartTime.IsValid())
	{
		COleDateTime timeStart = valStartTime.ToDateTime();
		COleDateTimeSpan span = curTime - timeStart;
		SetObjectPropValue(strProcData,_T("Tapping_Time"),CL3Variant((LONG)span.GetTotalSeconds()));
	}
	SetObjectPropValue(strProcData,_T("Lance_Age"),GetPropValue(_T("LanceAge")));
	SetObjectPropValue(strProcData,_T("LanceNo"),GetPropValue(_T("LanceNo")));
	//SetObjectPropValue(strProcData,_T("FurnaceAge"),GetPropValue(_T("Furnace_Age")));2009-01-04 tangyi
	SetObjectPropValue(strProcData,_T("Furnace_Age"),GetPropValue(_T("FurnaceAge")));
	SetObjectPropValue(strProcData,_T("Taphole_Life"),GetPropValue(_T("Taphole_Life")));
	// 修改枪龄，炉龄2009-04-10 枪龄,炉龄,出钢口寿命属性调整当前炉次生效
	LanceAge ++;
	FurnaceAge ++;
	Taphole_Life++;//2008-12-26

	// 修改转炉状态
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFTapped))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}



	// 生产，产生新的钢水对象
	CStringList lstAreas;
	GetProduceAreas(lstAreas);
	CString strArea = lstAreas.GetHead();
	CBSTR bstrArea(strArea);
	CL3RecordSet *prsParam = new CL3RecordSet();
	CL3RecordSetWrap rsParam; prsParam->QueryInterface(IID_IL3RecordSet,rsParam); prsParam->Release();
	rsParam.AddField(_T("HeatID"),VT_BSTR);
	rsParam.AppendRecord();
	rsParam.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	if(!Process(bstrArea.GetBuffer(TRUE),rsParam))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 钢水下线
	CL3RecordSetWrap rsSteels;
	CL3Variant valSteel = InvokeObjectMethod(strArea,_T("GetMaterials"));
	if(FAILED(valSteel.QueryInterface(IID_IL3RecordSet,rsSteels)))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsSteels.AddField(_T("Area"),VT_BSTR);
	rsSteels.MoveFirst();
	while(!rsSteels.IsEOF())
	{
		rsSteels.SetFieldByName(_T("Area"),CL3Variant(strArea));
		rsSteels.MoveNext();
	}
	rsSteels.MoveFirst();
	if(!DeliverMaterials(rsSteels))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	//// 计算下一炉号2009-02-10 改为出钢开始时计算下一炉号
	//CString strNextID = CalculateNextHeatID(HeatID);
	//NextHeatID = strNextID;

	// 修改当前转炉数据
	SteelGradeIndex = _T("");
	StartProcessTime = _T("");//2008-12-26
	Load = 0;
	
	if(nTrans > 0)
		Commit(nTrans);

	// 修改计划状态
	ChangePlanStatus(strHeatID,strHeatID,TAPPING_PLAN_BOF_STATUS_TAPPED);


	CalculateFirstLaC();//2009-01-10
	CalculateDefaultSmeltPeriod();////2009-01-14计算冶炼周期

	//炉后自动处理开始 2009-01-14 begin
	CString csUnitID = GetIdentity().ToCString();
	if (csUnitID.GetLength() == 3)
	{
		L3SHORT nUnitID = 0;
		try
		{
			nUnitID = _ttoi(csUnitID.Right(2));
		}
		catch(...)
		{
		}

		nUnitID = nUnitID + 10;

		CString csUnitID;
		csUnitID.Format(_T("%02d"),nUnitID);
		CString TapSideUnitID = _T("S")+csUnitID;
        CString strUri = CL3NameParser::MergeClassDomainName(BOF_SIDE_CLASS_URI,TapSideUnitID);
    	InvokeObjectMethod(strUri,_T("AutoStartProcess"));

	}
	//2009-01-14 End

	//2009-03-04 Begin
	if(m_nTimer != 0)
		KillTimer(GetURI(),m_nTimer);
	m_nTimer = 0;
	//2009-03-04 End

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="Splashing" type="L3BOOL">
/// 转炉开始溅渣
/// </Method>
L3BOOL CBOF_Unit_Mag::Splashing()
{
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFSplash))
		return FALSE;
	else
		return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="Dumping" type="L3BOOL">
/// 转炉开始倒渣
/// </Method>
L3BOOL CBOF_Unit_Mag::Dumping()
{
	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFDumping))
		return FALSE;
	else
		return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="Waiting" type="L3BOOL">
/// 兑铁准备，转炉进入等待状态。
/// </Method>
L3BOOL CBOF_Unit_Mag::Waiting()
{
	// 修改转炉属性
	CurTemp = 0.0;

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	// 检查转炉状态
	if(Status > CBOF_Unit_Mag::BOFWaiting && Status < CBOF_Unit_Mag::BOFTapped)
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	//2009-01-10 没有计划不能兑铁准备
	CString strHeatID;
	strHeatID = FindNextHeatIDFromPlan();
	
	if(strHeatID == _T(""))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		SetL3LastError(XGMES_ERR_PLANNOTEXIST);
		return FALSE;
	}
	NextHeatID = strHeatID;

	if(!ChangeBOFStatus(CBOF_Unit_Mag::BOFWaiting))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="GetIronsForDesignate" type="L3RECORDSET">
/// 返回可用于指定炉号的铁水信息。
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetIronsForDesignate()
{
	CString strInput = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(strInput,_T("GetMaterialDetails"),_T("CIron_Data"),_T(""));
	CL3RecordSetWrap rsRet;
	if(FAILED(valRet.QueryInterface(IID_IL3RecordSet,rsRet)))
		return NULL;
	else
	{
		CL3RecordSetWrap rsIron;
		CreateClassPropSet(MATERIAL_IRON_URI,rsIron);
		rsRet.MoveFirst();
		rsIron.CopyFrom(rsRet);
		return rsIron.Detach();
	}
}

/// <Method class="CBOF_Unit_Mag" name="GetInputIrons" type="L3RECORDSET">
/// 返回已经指定了的铁水信息
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetInputIrons()
{
	// 获取已指定的铁水
	CL3RecordSetWrap rsIrons;
	CString strCond; 
	//strCond.Format(_T(" HeatID = '%s'"),(LPCTSTR)NextHeatID);
	//2009-02-28
	strCond.Format(_T(" HeatID = '%s'"),(LPCTSTR)HeatID);
	CString strIronType = MATERIAL_IRON_URI;
	CBSTR bstrIronType = strIronType;
	CBSTR bstrCond(strCond);
	CL3Variant valIrons = InvokeObjectMethod(MIXFProduceCache_URI,_T("GetMaterialDetails"),bstrIronType.GetBuffer(TRUE),bstrCond.GetBuffer(TRUE));
	if(FAILED(valIrons.QueryInterface(IID_IL3RecordSet,rsIrons)))
	{
		return NULL;
	}
	
	return rsIrons.Detach();
}

/// <Method class="CBOF_Unit_Mag" name="GetInputScrapes" type="L3RECORDSET">
/// 返回已经指定了的生铁废钢信息
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetInputScrapes()
{
	CL3RecordSetWrap rsScrapes;
	CString strSQL;
	//strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag,StoreAreaID,Amount from %s where Iron_Flag = 1 and HeatID = '%s'"),SCRAP_OUT_CLASS_URI,NextHeatID);
	strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag,StoreAreaID,Amount from %s where Iron_Flag = 1 and HeatID = '%s'"),SCRAP_OUT_CLASS_URI,HeatID);
	if(!Query(strSQL,rsScrapes))
	{
		return NULL;
	}
	return rsScrapes.Detach();
}

/// <Method class="CBOF_Unit_Mag" name="OnTimer" type="L3BOOL">
/// 定时器处理
/// <Param name="uEventID" type="L3ULONG">事件ID</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::OnTimer(L3ULONG uEventID)
{
	if(uEventID == m_nTimer)
	{	// 吹炼定时器
		BlowTotalTime += BLOWTIME;
		BlowThisTime += BLOWTIME;
	}

	return TRUE;
}

/// <Method class="CBOF_Unit_Mag" name="GetAddedMaterialSum" type="L3RECORDSET">
/// 返回指定炉号的加料量统计数据。
/// <Param name="HeatID" type="L3STRING">炉号</Param>
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetAddedMaterialSum(L3STRING HeatID)
{
	CString strHeatID = String_BSTR2TChar(HeatID);
	CString strSQL;
	strSQL.Format(_T("select Element,Type,sum(Weight) as Weight from %s where HeatID = '%s' group by Element, Type"),
			BOF_ADDITION_DATA_CLASS_URI,(LPCTSTR)strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_ADDITION_DATA_CLASS_URI,rsLog))
		return NULL;
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	return rsLog.Detach();
}


/// <Method class="CBOF_Unit_Mag" name="AcceptAlloyDischargeData" type="L3RECORDSET">
/// 料仓加料数据采集
/// <Param name="HeatID" type="L3STRING">炉号</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptMaterialDischargeData(L3RECORDSET rsMaterialData)
{
	//2009-03-28 tangyi更改逻辑，料仓合金散装料按照先进先出的原则批次下料，
	//故PLC上传一个重量可能会因为批次的不同拆分成几个重量

	CL3RecordSetWrap rsData =rsMaterialData;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	if(rsData.GetFieldIndex(_T("PLC_Address")) < 0 ||
	   rsData.GetFieldIndex(_T("Amount")) < 0 )
			return FALSE;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_ADDITION_DATA_CLASS_URI,rsLog))
		return NULL;

	//组建数据集合金原料库出库
	CL3RecordSet *pRSAlloy = new CL3RecordSet();
	CL3RecordSetWrap rsAlloyOut; pRSAlloy->QueryInterface(IID_IL3RecordSet,rsAlloyOut); pRSAlloy->Release();
	rsAlloyOut.AddField(_T("MaterialID"),VT_BSTR);
	rsAlloyOut.AddField(_T("MaterialType"),VT_BSTR);
	rsAlloyOut.AddField(_T("Amount"),VT_R8);
	rsAlloyOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Target"),VT_BSTR);
	rsAlloyOut.AddField(_T("UnitID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Alloy_Code"),VT_BSTR);
	rsAlloyOut.AddField(_T("Batch_ID"),VT_BSTR);

	//组建数据集散状料原料库出库
	CL3RecordSet *pRSBulk = new CL3RecordSet();
	CL3RecordSetWrap rsBulkOut; pRSBulk->QueryInterface(IID_IL3RecordSet,rsBulkOut); pRSBulk->Release();
	rsBulkOut.AddField(_T("MaterialID"),VT_BSTR);
	rsBulkOut.AddField(_T("MaterialType"),VT_BSTR);
	rsBulkOut.AddField(_T("Amount"),VT_R8);
	rsBulkOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsBulkOut.AddField(_T("Target"),VT_BSTR);
	rsBulkOut.AddField(_T("UnitID"),VT_BSTR);
	rsBulkOut.AddField(_T("Bulk_Code"),VT_BSTR);
	rsBulkOut.AddField(_T("Batch_ID"),VT_BSTR);

	//组建数据集下料批次2009-03-28 tangyi
	CL3RecordSet *pRSMaterial = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRSMaterial->QueryInterface(IID_IL3RecordSet,rsMaterial); pRSMaterial->Release();
	rsMaterial.AddField(_T("Batch_ID"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("Element"),VT_BSTR);
	rsMaterial.AddField(_T("Weight"),VT_R8);

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rsMaterial.DeleteAll();
		//2009-03-06  转炉新增散状料累计数据收集
		//转换MES合金料仓号
		CString csPlcAddress = rsData.GetFieldByName(_T("PLC_Address")).ToCString();
		L3SHORT iType = rsData.GetFieldByName(_T("Type")).ToShort(); //散状料累计 iType = 9;
		//2009-05-11 begin 出钢开始至下炉主吹过程所加物料不能算拉碳调料数据
		if (((Status >= CBOF_Unit_Mag::BOFTapping) || (Status <= CBOF_Unit_Mag::BOFBlowing)) && (iType == 2))
		{
			rsData.SetFieldByName(_T("Type"),CL3Variant((L3SHORT)1));
			iType = 1;
		}
		//2009-05-11 end
		csPlcAddress.Replace(_T("."),_T("_"));
		csPlcAddress.Trim();
		if(csPlcAddress.IsEmpty())
		{
			rsData.MoveNext();
			continue;
		}
		CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\CBase_Address_Bulk_Relation\\") + csPlcAddress;
		CString csArea = GetObjectPropValue(csAreaUri,_T("Area")).ToCString();
		csArea.Trim();
		CString csMaterialType = csArea.Mid(0,3);
		rsLog.AppendRecord();
		//根据合金料仓号得到合金
		CString csSQL;
		CL3RecordSetWrap rs;
		CString cstrAreaUri;
		
		if(csMaterialType == STORE_ID_ALLOY)//合金料仓
		{
			cstrAreaUri = _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Bulk_Relation\\") + csArea;//	2008-12-28 yao
			csSQL.Format(_T(" select b.Alloy_Code as Element,b.Batch_ID,a.MaterialID,a.MaterialType,a.Amount as PosWeight from MATERIALPOSITION a,CAlloy_Data b where a.Position = '%s' and a.MaterialID = b.MaterialID order by Idx "),csArea);
		}
		else
		{
			cstrAreaUri = _T("XGMESLogic\\BulkStoreMag\\CBulk_Bulk_Relation\\") + csArea; //	2008-12-28 yao
			csSQL.Format(_T(" select b.Bulk_Code as Element,b.Batch_ID,a.MaterialID,a.MaterialType,a.Amount as PosWeight  from MATERIALPOSITION a,CBulk_Data b where a.Position = '%s' and a.MaterialID = b.MaterialID order by Idx "),csArea);
		}

		if(!Query(csSQL,rs))
			return FALSE;

		rs.MoveFirst();
		L3LONG nCount = rs.GetRowCount();
		
		//料仓下料总重量
		L3DOUBLE nWeight = rsData.GetFieldByName(_T("Amount")).ToDouble();
		//余量初始化为下料总量
		L3DOUBLE nRemainWeight = nWeight;

		//料先进先出，创建下料批次数据集
		for(int i=0;i< nCount;i++)
		{	
			rsMaterial.AppendRecord();
			//材料类型、物料编码、批次号、材料号
			rsMaterial.CopyCurRowFrom(rs);
			//得到料仓当前重量
			L3DOUBLE nPosWeight = rs.GetFieldByName(_T("PosWeight")).ToDouble();
			if(nWeight - nPosWeight < 0)
			{
				rsMaterial.SetFieldByName(_T("Weight"),CL3Variant(nWeight));
				nRemainWeight = 0;
				break;
			}
			rsMaterial.SetFieldByName(_T("Weight"),CL3Variant(nPosWeight));
			nWeight = nWeight - nPosWeight;
			nRemainWeight = nWeight;//得到余量
			rs.MoveNext();
		}
		//料仓里没有值，或者料仓里的料不足工序下料
		if(nRemainWeight > 0)
		{
			rsMaterial.AppendRecord();
			rsMaterial.SetFieldByName(_T("Batch_ID"),CL3Variant(_T("")));
			rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(_T("NoMaterialID")));
			//在MES料仓数据不正确的情况下，rs数据可能为空，故编码从料仓料种对应关系中获取2008-12-30 tangyi
			if(csMaterialType == STORE_ID_ALLOY)
			{
				rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
				rsMaterial.SetFieldByName(_T("Element"),GetObjectPropValue(cstrAreaUri,_T("Alloy_Code")));	
			}
			else
			{
				rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BULK));
				rsMaterial.SetFieldByName(_T("Element"),GetObjectPropValue(cstrAreaUri,_T("Bulk_Code")));	
			}
			rsMaterial.SetFieldByName(_T("Weight"),CL3Variant(nRemainWeight));
		}

		rsMaterial.MoveFirst();
		while(!rsMaterial.IsEOF())
		{
			rsLog.AppendRecord();
			rsLog.CopyCurRowFrom(rsMaterial);//批次号、重量,编码
			rsLog.SetFieldByName(_T("Discharge_Time"),COleDateTime::GetCurrentTime());
			rsLog.SetFieldByName(_T("Area"),CL3Variant(csArea)); //2009-01-07 yao	
			//2008-12-28 begin yao
			CString csDishcargingHeatID;
			if (((Status >= CBOF_Unit_Mag::BOFTapping)||(Status == CBOF_Unit_Mag::BOFWaiting)) && (iType != 9)) //2009-03-10 转炉等待状态所加物料为下炉次
			{
				//当前炉次出钢开始后，从下位机系统收集的散状料数据记为下炉次消耗
				csDishcargingHeatID = NextHeatID;
			}
			else
			{
				csDishcargingHeatID = HeatID;
				//当前炉次出钢开始前，从下位机系统收集的散状料数据记为当前炉次消耗
			}
			//2008-12-28 end yao

			//2009-01-13 Begin
			CString csAlloyHeatID;
			if (((Status >= CBOF_Unit_Mag::BOFTapping)||(Status == CBOF_Unit_Mag::BOFWaiting)) && (csPlcAddress.Find(_T("BOF_001_BOF1Alloy")) == -1)) //2009-03-10 转炉等待状态所加物料为下炉次
			{
				//当前炉次出钢开始后，从下位机系统收集的合金烘烤炉合金料数据记为下炉次消耗
				csAlloyHeatID = NextHeatID;
			}
			else if (((Status >= CBOF_Unit_Mag::BOFTapped)||(Status == CBOF_Unit_Mag::BOFWaiting)) && (csPlcAddress.Find(_T("BOF_001_BOF1Alloy")) != -1))//2009-04-27当前炉次出钢结束后，从下位机系统收集的1#合金高仓料数据记为下炉次消耗
			{
				csAlloyHeatID = NextHeatID;
			}
			else
			{
				csAlloyHeatID = HeatID;
				//当前炉次出钢开始前，从下位机系统收集的合金料数据记为当前炉次消耗
			}
			//2009-01-13 End

		
			CString csMaterialID = rsMaterial.GetFieldByName(_T("MaterialID")).ToCString();
			csMaterialID.Trim();
			

			if(csMaterialType == STORE_ID_ALLOY)//合金料仓
			{
    			rsLog.SetFieldByName(_T("HeatID"),CL3Variant(csAlloyHeatID));
				rsLog.SetFieldByName(_T("Type"),CL3Variant(L3LONG(5)));
 			
				if(csMaterialID != _T("NoMaterialID"))
				{
					rsAlloyOut.AppendRecord();
					rsAlloyOut.CopyCurRowFrom(rsMaterial);
					rsAlloyOut.SetFieldByName(_T("Amount"),rsMaterial.GetFieldByName(_T("Weight")));
					rsAlloyOut.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));
					rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csAlloyHeatID));
					rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));	
					rsAlloyOut.SetFieldByName(_T("Alloy_Code"),rsMaterial.GetFieldByName(_T("Element")));
				}
			}
			else
			{
    			rsLog.SetFieldByName(_T("HeatID"),CL3Variant(csDishcargingHeatID));
				rsLog.SetFieldByName(_T("Type"),rsData.GetFieldByName(_T("Type")));

				if(csMaterialID != _T("NoMaterialID"))		
				{
					rsBulkOut.AppendRecord();
					rsBulkOut.CopyCurRowFrom(rsMaterial);
					rsBulkOut.SetFieldByName(_T("Amount"),rsMaterial.GetFieldByName(_T("Weight")));
					rsBulkOut.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));
					rsBulkOut.SetFieldByName(_T("Target"),CL3Variant(csDishcargingHeatID));
					rsBulkOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));
					rsBulkOut.SetFieldByName(_T("Bulk_Code"),rsMaterial.GetFieldByName(_T("Element")));
				}
			}
			//	2008-12-28 begin yao
    		L3LONG nTopSlagFlag = GetObjectPropValue(cstrAreaUri,_T("TopSlagFlag")).ToLong();
			//根据nTopSlagFlag(若为1即为顶渣;若为2需根据工艺路径（过LF或RH）萤石振料小于50kg的一批属于顶渣)
			if ((nTopSlagFlag == 1) && (iType != 9)) //2009-04-25 添加 (iType != 9)
			{
				rsLog.SetFieldByName(_T("Type"),(L3SHORT)3);
			}
			else if ((nTopSlagFlag == 2) && (iType != 9)) //2009-04-25 添加 (iType != 9)
			{
				// 查询计划数据
				CL3RecordSetWrap rsPlan;
				CString strPlan; strPlan.Format(_T("select LFID,RHID from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,HeatID);
				Query(strPlan,rsPlan);
				if(rsPlan.GetRowCount() > 0)
					rsPlan.MoveFirst();
				CString csLFID = (rsPlan.GetFieldByName(_T("LFID"))).ToCString();
				CString csRHID = (rsPlan.GetFieldByName(_T("RHID"))).ToCString();
				L3FLOAT fWeight = (rsLog.GetFieldByName(_T("Weight"))).ToFloat();
				if (((csLFID != _T("0")) || (csRHID != _T("0"))) && (fWeight < 50))
				{
					rsLog.SetFieldByName(_T("Type"),(L3SHORT)3);
				}

				//2009-04-30 begin 顶渣为出钢结束后加料为下炉次
				CString cstrDishcargingHeatID;
				if (((Status >= CBOF_Unit_Mag::BOFTapped)||(Status == CBOF_Unit_Mag::BOFWaiting)) && (iType != 9)) //2009-03-10 转炉等待状态所加物料为下炉次
				{
					cstrDishcargingHeatID = NextHeatID;
				}
				else
				{
					cstrDishcargingHeatID = HeatID;
				}
				rsLog.SetFieldByName(_T("HeatID"),CL3Variant(cstrDishcargingHeatID));
				//2009-04-30 end

			}
			rsMaterial.MoveNext();		
		}

		rsData.MoveNext();	
	}


	if(CreateNewObjects(BOF_ADDITION_DATA_CLASS_URI,rsLog) < rsLog.GetRowCount())
		return FALSE;


	if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0)
		InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsAlloyOut));
	if(!rsBulkOut.IsNull() && rsBulkOut.GetRowCount() > 0)
		InvokeObjectMethod(BULK_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsBulkOut));

	//2009-05-22 同一种物料多次下料，架构目前不支持批量操作，故改为单步操作
	//if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0)
	//{
	//	CL3RecordSetWrap rsFinalData = rsAlloyOut.CloneStruct();
	//	rsFinalData.AppendRecord();	
	//	rsFinalData.MoveFirst();
	//	rsAlloyOut.MoveFirst();
	//	while(!rsAlloyOut.IsEOF())
	//	{
	//		rsFinalData.CopyCurRowFrom(rsAlloyOut);
	//		InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsFinalData));
	//		rsFinalData.MoveFirst();
	//		rsAlloyOut.MoveNext();
	//	}
	//}

	//if(!rsBulkOut.IsNull() && rsBulkOut.GetRowCount() > 0)
	//{
	//	CL3RecordSetWrap rsFinalData = rsBulkOut.CloneStruct();
	//	rsFinalData.AppendRecord();	
	//	rsFinalData.MoveFirst();
	//	rsBulkOut.MoveFirst();
	//	while(!rsBulkOut.IsEOF())
	//	{
	//		rsFinalData.CopyCurRowFrom(rsBulkOut);
	//		InvokeObjectMethod(BULK_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsFinalData));
	//		rsFinalData.MoveFirst();
	//		rsBulkOut.MoveNext();
	//	}
	//}

	return TRUE;
}


/// <Method class="CBOF_Unit_Mag" name="MaterialGroundDischargeData" type="L3RECORDSET">
/// 袋装合金散状料消耗
/// <Param name="HeatID" type="L3STRING">炉号</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::MaterialGroundDischargeData(L3RECORDSET rsMaterialData)
{
	CL3RecordSetWrap rsData =rsMaterialData;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	if(rsData.GetFieldIndex(_T("StoreAreaID")) < 0 ||
	   rsData.GetFieldIndex(_T("MaterialID")) < 0 ||
	   rsData.GetFieldIndex(_T("MaterialType")) < 0 ||
	   rsData.GetFieldIndex(_T("Batch_ID")) < 0 ||
	   rsData.GetFieldIndex(_T("Amount")) < 0 )
			return FALSE;

		CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(BOF_ADDITION_DATA_CLASS_URI,rsLog))
		return NULL;

	//组建数据集合金原料库出库
	CL3RecordSet *pRSAlloy = new CL3RecordSet();
	CL3RecordSetWrap rsAlloyOut; pRSAlloy->QueryInterface(IID_IL3RecordSet,rsAlloyOut); pRSAlloy->Release();
	rsAlloyOut.AddField(_T("MaterialID"),VT_BSTR);
	rsAlloyOut.AddField(_T("MaterialType"),VT_BSTR);
	rsAlloyOut.AddField(_T("Amount"),VT_R4);
	rsAlloyOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Target"),VT_BSTR);
	rsAlloyOut.AddField(_T("UnitID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Alloy_Code"),VT_BSTR);
	rsAlloyOut.AddField(_T("Batch_ID"),VT_BSTR);

	//组建数据集散状料原料库出库
	CL3RecordSet *pRSBulk = new CL3RecordSet();
	CL3RecordSetWrap rsBulkOut; pRSBulk->QueryInterface(IID_IL3RecordSet,rsBulkOut); pRSBulk->Release();
	rsBulkOut.AddField(_T("MaterialID"),VT_BSTR);
	rsBulkOut.AddField(_T("MaterialType"),VT_BSTR);
	rsBulkOut.AddField(_T("Amount"),VT_R4);
	rsBulkOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsBulkOut.AddField(_T("Target"),VT_BSTR);
	rsBulkOut.AddField(_T("UnitID"),VT_BSTR);
	rsBulkOut.AddField(_T("Bulk_Code"),VT_BSTR);
	rsBulkOut.AddField(_T("Batch_ID"),VT_BSTR);

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csArea = rsData.GetFieldByName(_T("StoreAreaID")).ToCString();
		CString csMaterialID = rsData.GetFieldByName(_T("MaterialID")).ToCString();
		CString csMaterialType = csArea.Mid(0,3);
		rsLog.AppendRecord();
		rsLog.CopyCurRowFrom(rsData);
		rsLog.SetFieldByName(_T("Weight"),rsData.GetFieldByName(_T("Amount")));
		rsLog.SetFieldByName(_T("Discharge_Time"),COleDateTime::GetCurrentTime());
		rsLog.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsLog.SetFieldByName(_T("Area"),CL3Variant(csArea)); //2009-01-07 yao	
		if(csMaterialType == STORE_ID_ALLOY)//合金料仓
		{
			rsLog.SetFieldByName(_T("Element"),rsData.GetFieldByName(_T("Alloy_Code")));	
			rsLog.SetFieldByName(_T("Type"),CL3Variant(L3LONG(5)));
			rsAlloyOut.AppendRecord();
			rsAlloyOut.CopyCurRowFrom(rsData);
			rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(HeatID));
			rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));		
		}
		else
		{
			rsLog.SetFieldByName(_T("Element"),rsData.GetFieldByName(_T("Bulk_Code")));	
			rsLog.SetFieldByName(_T("Type"),CL3Variant(L3LONG(1)));
			rsBulkOut.AppendRecord();
			rsBulkOut.CopyCurRowFrom(rsData);
			rsBulkOut.SetFieldByName(_T("Target"),CL3Variant(HeatID));
			rsBulkOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));
		}

		rsData.MoveNext();		
	}

	if(CreateNewObjects(BOF_ADDITION_DATA_CLASS_URI,rsLog) < rsLog.GetRowCount())
		return FALSE;

	//if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0)
	//{
	//	CL3Variant vtRtn = InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsAlloyOut));
	//	if(vtRtn.IsError() || !vtRtn.ToBOOL())
	//		return FALSE;
	//}
	//if(!rsBulkOut.IsNull() && rsBulkOut.GetRowCount() > 0)
	//{
	//	CL3Variant vtRtn = InvokeObjectMethod(BULK_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsBulkOut));
	//	if(vtRtn.IsError() || !vtRtn.ToBOOL())
	//		return FALSE;
	//}

	return TRUE;
}





/// <Method class="CBOF_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
/// 申请改钢
/// <Param name="Reason" type="L3STRING">原因</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_EXE_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(BOF_BASE_DATA_CLASS_URI,csHeatID);
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
///  钢水回炉申请 2009-02-28 增加炉号
/// <Param name="Reason" type="L3STRING">原因</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_TURN_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	//CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csHeatID = strHeatID;
	CString csUri = CL3NameParser::MergeClassDomainName(BOF_BASE_DATA_CLASS_URI,csHeatID);
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

/// <Method class="CBOF_Unit_Mag" name="GetExceptHeatID" type="L3RECORDSET">
/// 获取工艺异常炉号数据。
/// <Param name="UnitID" type="L3STRING">工位</Param>
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetExceptHeatID(L3STRING UnitID)
{
	CString strUnitID = String_BSTR2TChar(UnitID);
	int nUnitTypeID = _ttoi(strUnitID.Mid(1,1));
	CString csUnitID = strUnitID.Mid(2,1);
	CString strSQL;
	switch(nUnitTypeID)
	{
	case 2:
		{	//转炉
			strSQL.Format(_T("select HeatID from (select HeatID from %s where substr(HeatID,2,1) = '%s' order by ProductionDate desc) where rownum < 3"),
					BOF_BASE_DATA_CLASS_URI,csUnitID);
		}
		break;
	case 4:
		{	//LF炉
			strSQL.Format(_T("select HeatID from (select HeatID from %s where substr(TreatNo,1,1) = '%s' order by ProductionDate desc) where rownum < 3"),
					LF_BASE_DATA_CLASS_URI,csUnitID);
		}
		break;
	case 5:
		{	// RH炉
			strSQL.Format(_T("select HeatID from (select HeatID from %s where substr(TreatNo,1,1) = '%s' order by ProductionDate desc) where rownum < 3"),
					RH_BASE_DATA_CLASS_URI,csUnitID);
		}
		break;
	case 6:
		{	//连铸
			strSQL.Format(_T("select HeatID from (select HeatID from %s where substr(TreatNo,1,1) = '%s' order by ProductionDate desc) where rownum < 3"),
					CCM_BASE_DATA_CLASS_URI,csUnitID);
		}
		break;
	default:
		{
			return NULL;
		}
	}

	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	return rs.Detach();
}

/// <Method class="CBOF_Unit_Mag" name="SetStackData" type="L3BOOL">
/// 记录转炉炉衬维护数据
/// <Param name="rsData" type="L3RECORDSET">炉衬数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::SetStackData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// 检查数据
	if(rs.GetFieldIndex(_T("Team")) < 0)
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

	// 锁定本转炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 获取炉号
	CString strHeatID = HeatID;
	COleDateTime curTime = COleDateTime::GetCurrentTime();

	// 记录炉衬记录
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Stack_Maintenance"),rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("ProductionDate"),CL3Variant(curTime));
		rsLog.MoveNext();
	}
	rsLog.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Stack_Maintenance"),rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="LockData" type="L3SHORT">
/// 封锁实绩数据
/// <Param name="strUnitID" type="L3STRING">工位</Param>
/// <Param name="strHeatID" type="L3STRING">炉号</Param>
/// <Param name="strTreatNo" type="L3STRING">处理号</Param>
/// </Method>
L3SHORT CBOF_Unit_Mag::LockData(L3STRING strUnitID,L3STRING strHeatID,L3STRING strTreatNo)
{
	if ((strUnitID == NULL) || (strHeatID == NULL))
	{
		return -1;
	}

	CString csUnitID = strUnitID;
	CString csHeatID = strHeatID;
	CString csTreatNo = strTreatNo;

	CString csLockFlag;
	CString csURI;
	CString csPropName;

	//2009-04-14 人工确认日志时将收工录入的料从袋装合金处出库
	//组建数据集合金原料库出库
	CL3RecordSet *pRSAlloy = new CL3RecordSet();
	CL3RecordSetWrap rsAlloyOut; pRSAlloy->QueryInterface(IID_IL3RecordSet,rsAlloyOut); pRSAlloy->Release();
	rsAlloyOut.AddField(_T("MaterialID"),VT_BSTR);
	rsAlloyOut.AddField(_T("MaterialType"),VT_BSTR);
	rsAlloyOut.AddField(_T("Amount"),VT_R8);
	rsAlloyOut.AddField(_T("StoreAreaID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Target"),VT_BSTR);
	rsAlloyOut.AddField(_T("UnitID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Alloy_Code"),VT_BSTR);
	rsAlloyOut.AddField(_T("Batch_ID"),VT_BSTR);
	rsAlloyOut.AddField(_T("Type"),VT_R4);

	

	if (csUnitID.Left(2) == _T("S2"))
	{
		//Modify begin by llj 2011-03-26 对转炉钢水直送不锈钢进行重量判断处理，因为NC需要上传钢水重量
		if(csUnitID==_T("S24"))
		{
			CString csSql;
			csSql.Format(_T("select CASTERID from %s where HEATID='%s'"),PLAN_TAPPING_CLASS_URI,strHeatID);
			CL3RecordSetWrap rsTapping;
			if(!Query(csSql,rsTapping)||rsTapping.IsNull()||rsTapping.GetFieldCount()<1)
				return -1;
			rsTapping.MoveFirst();
			CString csCasterID=rsTapping.GetFieldByName(_T("CasterID")).ToString();
			if(csCasterID==_T("S66"))
			{
				double dSteelWeight=(GetObjectPropValue(_T("XGMESLogic\\BOFMag\\CBOF_Process_Data\\")+csHeatID,_T("Tapping_Weight"))).ToLong();
				if(dSteelWeight<0.1)
					return -1;
			}
		}
		//Modify end
		csURI = _T("XGMESLogic\\BOFMag\\CBOF_Base_Data\\");
	    csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("BOFFinishedFlag"))).ToCString();
        csPropName = _T("BOFFinishedFlag");
		//转炉手工输入合金
		CString csTempSQL = _T(" select * from CBOF_ADDITION_DATA where Name ='1' and Type ='5' and HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs))
			return -5;
		rs.MoveFirst();
		while(!rs.IsEOF())
		{	
			CString csAlloyCode = rs.GetFieldByName(_T("Element")).ToCString();
			CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString();
			CString csSQL;
			CString	csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='1' ");
			CL3RecordSetWrap rsResult;
			csSQL.Format(csTempSQL,csAlloyCode);
			if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
			{
				rs.MoveNext();
				continue;
				
			}
			rsResult.MoveFirst();
			rsAlloyOut.AppendRecord();
			rsAlloyOut.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
			rsAlloyOut.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
			rsAlloyOut.SetFieldByName(_T("Amount"),rs.GetFieldByName(_T("Weight")));
			rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csHeatID));
			rsAlloyOut.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
			rsAlloyOut.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
			rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(csUnitID));
			rsAlloyOut.SetFieldByName(_T("Type"),L3LONG(5));
			rsAlloyOut.SetFieldByName(_T("StoreAreaID"),rsResult.GetFieldByIndex(0));
			rs.MoveNext();
		}
		//炉后手工输入合金
		csTempSQL = _T(" select * from CTAP_ADDITION_DATA  where  Name ='1' and HeatID ='%s' ");
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsTap;
		if(!Query(csSQL,rsTap))
			return -5;
		rsTap.MoveFirst();
		while(!rsTap.IsEOF())
		{	
			CString csAlloyCode = rsTap.GetFieldByName(_T("Element")).ToCString();
			CString csBatchID = rsTap.GetFieldByName(_T("Batch_ID")).ToCString();
			CString csSQL;
			CString	csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='1' ");
			CL3RecordSetWrap rsResult;
			csSQL.Format(csTempSQL,csAlloyCode);
			if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
			{
				rsTap.MoveNext();
				continue;
				
			}
			rsResult.MoveFirst();
			rsAlloyOut.AppendRecord();
			rsAlloyOut.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
			rsAlloyOut.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
			rsAlloyOut.SetFieldByName(_T("Amount"),rsTap.GetFieldByName(_T("Weight")));
			rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csHeatID));
			rsAlloyOut.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
			rsAlloyOut.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
			rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(csUnitID));
			rsAlloyOut.SetFieldByName(_T("Type"),L3LONG(5));
			rsAlloyOut.SetFieldByName(_T("StoreAreaID"),rsResult.GetFieldByIndex(0));
			rsTap.MoveNext();
		}
	}
	else if (csUnitID.Left(2) == _T("S4"))
	{
		csURI = _T("XGMESLogic\\LFMag\\CLF_Base_Data\\");
	    csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("LFFinishedFlag"))).ToCString();
        csPropName = _T("LFFinishedFlag");
		//合金
		CString csTempSQL = _T(" select * from CLF_ADDITION_DATA where Name ='1' and HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs))
			return -5;
		rs.MoveFirst();
		while(!rs.IsEOF())
		{	
			CString csAlloyCode = rs.GetFieldByName(_T("Element")).ToCString();
			CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString();
			CString csSQL;
			CString	csTempSQL;
			if(csUnitID == UNIT_ID_1LF || csUnitID == UNIT_ID_2LF)
			csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='2' ");
			else
			csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='3' ");
			CL3RecordSetWrap rsResult;
			csSQL.Format(csTempSQL,csAlloyCode);
			if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
			{
				rs.MoveNext();
				continue;
			}
			rsResult.MoveFirst();
			rsAlloyOut.AppendRecord();
			rsAlloyOut.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
			rsAlloyOut.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
			rsAlloyOut.SetFieldByName(_T("Amount"),rs.GetFieldByName(_T("Weight")));
			rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csHeatID));
			rsAlloyOut.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
			rsAlloyOut.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
			rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(csUnitID));
			rsAlloyOut.SetFieldByName(_T("Type"),L3LONG(5));
			rsAlloyOut.SetFieldByName(_T("StoreAreaID"),rsResult.GetFieldByIndex(0));
			rs.MoveNext();
		}
	}
	else if (csUnitID.Left(2) == _T("S5"))
	{
		csURI = _T("XGMESLogic\\RHMag\\CRH_Base_Data\\");
	    csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("RHFinishedFlag"))).ToCString();
        csPropName = _T("RHFinishedFlag");
		////合金
		CString csTempSQL = _T(" select * from CRH_ADDITION_DATA where Name ='1'  and HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs))
			return -5;
		rs.MoveFirst();
		while(!rs.IsEOF())
		{	
			CString csAlloyCode = rs.GetFieldByName(_T("Element")).ToCString();
			CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString();
			CString csSQL;
			CString	csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='3' ");
			CL3RecordSetWrap rsResult;
			csSQL.Format(csTempSQL,csAlloyCode);
			if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
			{
				rs.MoveNext();
				continue;
			}
			rsResult.MoveFirst();
			rsAlloyOut.AppendRecord();
			rsAlloyOut.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
			rsAlloyOut.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
			rsAlloyOut.SetFieldByName(_T("Amount"),rs.GetFieldByName(_T("Weight")));
			rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csHeatID));
			rsAlloyOut.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
			rsAlloyOut.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
			rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(csUnitID));
			rsAlloyOut.SetFieldByName(_T("Type"),L3LONG(5));
			rsAlloyOut.SetFieldByName(_T("StoreAreaID"),rsResult.GetFieldByIndex(0));
			rs.MoveNext();
		}
	}
	else if (csUnitID.Left(2) == _T("S6"))
	{
		csURI = _T("XGMESLogic\\CCMMag\\CCCM_Base_Data\\");
	    csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("CCMFinishedFlag"))).ToCString();
        csPropName = _T("CCMFinishedFlag");
	}


	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	if (!SetObjectPropValue(csURI+csTreatNo,_T("Locked"),(L3SHORT)1))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}

	if (!SetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,csPropName,CL3Variant(_T("1"))))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}

	if(nTrans > 0)
		Commit(nTrans);

	//2009-04-14 人工确认日志时将收工录入的料从袋装合金处出库
	if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0) 
		InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsAlloyOut));

	//2009-05-22 同一种物料多次下料，架构目前不支持批量操作，故改为单步操作
	//CL3RecordSetWrap rsFinalData = rsAlloyOut.CloneStruct();
	//rsFinalData.AppendRecord();	
	//rsFinalData.MoveFirst();
	//rsAlloyOut.MoveFirst();
	//while(!rsAlloyOut.IsEOF())
	//{
	//	rsFinalData.CopyCurRowFrom(rsAlloyOut);
	//	InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsFinalData));
	//	rsFinalData.MoveFirst();
	//	rsAlloyOut.MoveNext();
	//}
	return 0;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFStatus" type="L3BOOL">
/// 接收转炉过程状态数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">状态数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFStatus(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	// 获取炉号
	rs.MoveFirst();
	L3LONG BOFStatus = -1;
	BOFStatus = (rs.GetFieldByName(_T("BOFStatus"))).ToLong();
	switch(BOFStatus)
	{
    	case CBOF_Unit_Mag::BOFFeeding: 
			FeedIrons();
		break;
		case CBOF_Unit_Mag::BOFBlowing: 
			StartBlowing(true, rs.GetFieldByName(_T("MesauresTime")).ToDateTime());
		break;
		case CBOF_Unit_Mag::BOFReBlowing: 
		{
			StartBlowing(false, rs.GetFieldByName(_T("MesauresTime")).ToDateTime());
		}
		break;
		case CBOF_Unit_Mag::BOFTapping: 
		{
			StartTapping();
		}
		break;
		case CBOF_Unit_Mag::BOFTapped: 
			StopTapping();
		break;
		case CBOF_Unit_Mag::BOFSplash: 
			Splashing();
		break;
		case CBOF_Unit_Mag::BOFDumping:  
		{
			//2009-01-10 Begin
			CString curHeatID = HeatID;
			if (curHeatID.GetLength() == 9)
			{
				L3LONG iSplashingTime = rs.GetFieldByName(_T("SplashingTime")).ToLong();
				if (iSplashingTime > 0)
				{
					SetObjectPropValue(_T("XGMESLogic\\BOFMag\\CBOF_Process_Data\\")+curHeatID,_T("Splashing_Time"),CL3Variant(iSplashingTime));
				}
			}
			//2009-01-10 End
			Dumping();
		}
		break;
		default:
			break;
	}
	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFBottomBlowData" type="L3BOOL">
/// 接收转炉底吹数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">底吹数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFBottomBlowData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	CL3RecordSetWrap rsBlow;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Bottom_Blowing"),rsBlow))
	{
		return FALSE;
	}

	rsBlow.CopyFrom(rs);

	rsBlow.MoveFirst();
	while (!rsBlow.IsEOF())
	{
		rsBlow.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsBlow.SetFieldByName(_T("Catch_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		BottomFlow1 = rsBlow.GetFieldByName(_T("Flow1")).ToFloat();
		BottomFlow2 = rsBlow.GetFieldByName(_T("Flow2")).ToFloat();
		BottomFlow3 = rsBlow.GetFieldByName(_T("Flow3")).ToFloat();
		BottomFlow4 = rsBlow.GetFieldByName(_T("Flow4")).ToFloat();
		BottomFlow5 = rsBlow.GetFieldByName(_T("Flow5")).ToFloat();
		BottomFlow6 = rsBlow.GetFieldByName(_T("Flow6")).ToFloat();
		BottomPressure1 = rsBlow.GetFieldByName(_T("Pressure1")).ToFloat();
		BottomPressure2 = rsBlow.GetFieldByName(_T("Pressure2")).ToFloat();
		BottomPressure3 = rsBlow.GetFieldByName(_T("Pressure3")).ToFloat();
		BottomPressure4 = rsBlow.GetFieldByName(_T("Pressure4")).ToFloat();
		BottomPressure5 = rsBlow.GetFieldByName(_T("Pressure5")).ToFloat();
		BottomPressure6 = rsBlow.GetFieldByName(_T("Pressure6")).ToFloat();

		if (rsBlow.GetFieldByName(_T("Gas_Type")).ToShort() == 1) //2009-01-08 
		{
			rsBlow.SetFieldByName(_T("Gas_Type"),CL3Variant(_T("N2")));
		}
		else
		{
			rsBlow.SetFieldByName(_T("Gas_Type"),CL3Variant(_T("Ar")));
		}
		rsBlow.MoveNext();
	}

	rsBlow.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Bottom_Blowing"),rsBlow) < rsBlow.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFTopBlowData" type="L3BOOL">
/// 接收转炉顶吹数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">顶吹数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFTopBlowData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	CL3RecordSetWrap rsBlow;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Top_Blowing"),rsBlow))
	{
		return FALSE;
	}

	rsBlow.CopyFrom(rs);

	rsBlow.MoveFirst();
	while (!rsBlow.IsEOF())
	{
		rsBlow.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsBlow.SetFieldByName(_T("Catch_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		TopFlow = rsBlow.GetFieldByName(_T("Flow")).ToFloat();
		TopPressure = rsBlow.GetFieldByName(_T("Pressure")).ToFloat();
		rsBlow.MoveNext();
	}

	rsBlow.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Top_Blowing"),rsBlow) < rsBlow.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFTappedData" type="L3BOOL">
/// 接收转炉出钢数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">出钢数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFTappedData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.AddField(_T("HeatID"),L3VT_STRING);
	rs.MoveFirst();
	while (!rs.IsEOF())
	{
		rs.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rs.MoveNext();
	}

	rs.MoveFirst();
	SetObjsPropValues(BOF_PROCESS_DATA_CLASS_URI,rs);

	CalculateLcTemp();

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFTempData" type="L3BOOL">
/// 接收转炉测温数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">测温数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFTempData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	if (Status >= CBOF_Unit_Mag::BOFTapped) //出钢结束后不再收集温度数据2009-01-09
	{
		return TRUE;
	}

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Temp_Data"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("Temp_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		CurTemp = rsTemp.GetFieldByName(_T("Temp")).ToLong();
		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Temp_Data"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFOxygenData" type="L3BOOL">
/// 接收转炉定氧数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">定氧数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFOxygenData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	if (Status >= CBOF_Unit_Mag::BOFTapped) //出钢结束后不再收集温度数据2009-01-09
	{
		return TRUE;
	}

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\BOFMag\\CBOF_Oxygen_Data"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("Measure_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\BOFMag\\CBOF_Oxygen_Data"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateLcTemp" type="L3BOOL">
/// 计算拉碳温度数据(取补吹前最后一次数据,无补吹取最后一次数据) 2009-01-10
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateLcTemp()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
	L3SHORT nReBlow_Count = GetObjectPropValue(strUri,_T("ReBlow_Count")).ToShort();
	CString csSQL;
	if (nReBlow_Count == 0) //无补吹取最后一次数据
	{
		csSQL.Format(_T("select Temp from %s where HeatID = '%s' order by Temp_Time desc"),BOF_TEMP_DATA_CLASS_URI,curHeatID);
		CL3RecordSetWrap rstemp;
		if (!Query(csSQL, rstemp) || rstemp.IsNull())	
		{
			return FALSE; 
		}
		L3LONG rsCount = rstemp.GetRowCount();
		if (rsCount > 0)
		{
		   rstemp.MoveFirst();
		   L3LONG iLcTemp = rstemp.GetFieldByName(_T("Temp")).ToLong();
		   if (!SetObjectPropValue(strUri,_T("LaC_Temp"),CL3Variant(iLcTemp)))
		   {
				return FALSE; 
		   }
		}
	}
	else //取补吹前最后一次数据
	{
		csSQL.Format(_T("select Temp from CBOF_Temp_Data where HeatID = '%s' and Temp_Time < (select Change_Time from CBOF_Process_Status where HeatID = '%s' and Status = 3) order by Temp_Time desc"),curHeatID,curHeatID);
		CL3RecordSetWrap rstempreblow;
		if (!Query(csSQL, rstempreblow) || rstempreblow.IsNull())	
		{
			return FALSE; 
		}
		L3LONG rsCount = rstempreblow.GetRowCount();
		if (rsCount > 0)
		{
		   rstempreblow.MoveFirst();
		   L3LONG iLcTemp = rstempreblow.GetFieldByName(_T("Temp")).ToLong();
		   if (!SetObjectPropValue(strUri,_T("LaC_Temp"),CL3Variant(iLcTemp)))
		   {
				return FALSE; 
		   }
		}
	}
	
	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateTappingTemp" type="L3BOOL">
/// 计算出钢温度数据(来源分为两处:一为倒炉测温，二为定氧时测温;出钢开始之前的最后一次测温;
/// 若出现补吹，补吹开始至出钢开始时间段未测温，则出钢温度记为未测(-1)；定氧未测温采集定氧时温度数据) 2009-01-10
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateTappingTemp()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

    //出钢开始之前的最后一次测温
	CString csSQL;
	csSQL.Format(_T("select Temp from %s where HeatID = '%s' order by Temp_Time desc"),BOF_TEMP_DATA_CLASS_URI,curHeatID);
	CL3RecordSetWrap rstemp;
	if (!Query(csSQL, rstemp) || rstemp.IsNull())	
	{
		return FALSE; 
	}

	L3LONG iTappingTemp = 0;
	L3LONG rsCount = rstemp.GetRowCount();
	if (rsCount > 0)
	{
	   rstemp.MoveFirst();
	   iTappingTemp = rstemp.GetFieldByName(_T("Temp")).ToLong();
	}
	//若出现补吹，补吹开始至出钢开始时间段未测温，则出钢温度记为未测(-1)
	csSQL.Format(_T("select * from %s where HeatID = '%s' and Status = %d order by Change_Time desc"),
		BOF_PROC_STATUS_CLASS_URI,curHeatID,CBOF_Unit_Mag::BOFReBlowing);
	CL3RecordSetWrap rstime;
	if (!Query(csSQL, rstime) || rstime.IsNull())	
	{
		return FALSE; 
	}
	rsCount = rstime.GetRowCount();
	if (rsCount > 0)
	{
	   rstime.MoveFirst();
	   COleDateTime timeOld = rstime.GetFieldByName(_T("Change_Time")).ToDateTime();
	   csSQL.Format(_T("select Temp from %s where HeatID = '%s' and Temp_Time>? "),
		         BOF_TEMP_DATA_CLASS_URI,curHeatID);
		VARIANT params[1];
		params[0].vt = VT_DATE; params[0].date = (DATE)timeOld;
		CL3RecordSetWrap rs;
		if(QueryWithParam(csSQL,params,1,rs))
		{
			L3LONG irsCount = rs.GetRowCount();
			if (irsCount < 1)
			{
				iTappingTemp = -1;
			}
		}
	}

	CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
   if (!SetObjectPropValue(strUri,_T("Tapping_Temp"),CL3Variant(iTappingTemp)))
   {
		return FALSE; 
   }

   //Modify begin by llj 2011-0-09 修正拉碳温度为喷吹开始6分钟后的第一个温度
   csSQL.Format(_T("select Change_Time from CBOF_Process_Status where  HeatID='%s' and Status=2"),curHeatID);
   CL3RecordSetWrap rsBOFStatus;
   if(!Query(csSQL,rsBOFStatus)&&rsBOFStatus.GetRowCount()==1)
   {
	   rsBOFStatus.MoveFirst();
	   L3DATETIME dChangeTime=rsBOFStatus.GetFieldByName(_T("Change_Time")).ToDateTime();
	   csSQL.Format(_T("select Temp_Time,Temp from CBOF_Temp_Data where HeatID = '%s' and Temp_Time > %d order by Temp_Time asc "),curHeatID,dChangeTime);
	   CL3RecordSetWrap rs;
	   if(!Query(csSQL,rs)&&!rs.IsNull()&&rs.GetRowCount()>0)
	   {
		   rs.MoveFirst();
		   while(!rs.IsEOF())
		   {
			   L3DATETIME dTempTime=rs.GetFieldByName(_T("Temp_Time")).ToDateTime();
			   COleDateTimeSpan span = dTempTime - dChangeTime;
			   if(span.GetTotalSeconds()>8*60)
			   {
				   L3LONG iTemp=rs.GetFieldByName(_T("Temp")).ToLong();

					//修正拉碳温度
					CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
					if (!SetObjectPropValue(strUri,_T("LaC_Temp"),CL3Variant(iTemp)))
					{
						return FALSE; 
					}
					break;
			   }
		   }

	   }
   }
   //Modify end

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateTappedOxygenContent" type="L3BOOL">
/// 计算出钢氧含量数据(取最后一次氧含量数据) 2009-01-10
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateTappedOxygenContent()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString csSQL;
	csSQL.Format(_T("select Oxygen_Content from %s where HeatID = '%s' order by Measure_Time desc"),BOF_OXYGEN_DATA_CLASS_URI,curHeatID);
	CL3RecordSetWrap rstemp;
	if (!Query(csSQL, rstemp) || rstemp.IsNull())	
	{
		return FALSE; 
	}
	L3LONG rsCount = rstemp.GetRowCount();
	if (rsCount > 0)
	{
	   rstemp.MoveFirst();
	   L3FLOAT fOxygenContent = rstemp.GetFieldByName(_T("Oxygen_Content")).ToFloat();
	   CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
       if (!SetObjectPropValue(strUri,_T("Tapping_Oxygen"),CL3Variant(fOxygenContent)))
	   {
			return FALSE; 
	   }
	}
	
	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateFirstLaC" type="L3BOOL">
/// 计算一次拉碳(拉碳温度等于出钢温度且无补吹及拉碳调料（轻烧白云石、石灰）信号的，视为一次拉碳) 2009-01-10
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateFirstLaC()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

    CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,curHeatID);
	L3LONG iTappingTemp = GetObjectPropValue(strUri,_T("Tapping_Temp")).ToLong();
	L3LONG iLaCTemp = GetObjectPropValue(strUri,_T("LaC_Temp")).ToLong();
	if (iTappingTemp == iLaCTemp)
	{
		L3SHORT noReBlow = -1;
		CString csSQL;
		csSQL.Format(_T("select * from %s where HeatID = '%s' and Status = %d"),
			BOF_PROC_STATUS_CLASS_URI,curHeatID,CBOF_Unit_Mag::BOFReBlowing);
		CL3RecordSetWrap rstime;
		if (!Query(csSQL, rstime) || rstime.IsNull())	
		{
			return FALSE; 
		}
		L3LONG rsCount = rstime.GetRowCount();
		if (rsCount < 1)
		{
			noReBlow = 1;
		}

		L3LONG noLaCMat = -1;
		csSQL.Format(_T("select * from %s where HeatID = '%s' and Type = 2 and Element <> 'B006'"),
			BOF_ADDITION_DATA_CLASS_URI,curHeatID);
		CL3RecordSetWrap rstemp;
		if (!Query(csSQL, rstemp) || rstemp.IsNull())	
		{
			return FALSE; 
		}
		rsCount = rstemp.GetRowCount();
		if (rsCount < 1)
		{
			noLaCMat = 1;
		}

		if ((noReBlow == 1) && (noLaCMat == 1))
		{
		   if (!SetObjectPropValue(strUri,_T("Single_LaC"),CL3Variant((L3SHORT)1)))
		   {
				return FALSE; 
		   }

		}
	}
	
	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="CalculateDefaultSmeltPeriod" type="L3BOOL">
/// 计算缺省冶炼周期 2009-01-14
/// </Method>
L3BOOL CBOF_Unit_Mag::CalculateDefaultSmeltPeriod()
{
	CString curHeatID = HeatID;
	if (curHeatID.GetLength() != 9)
	{
		return FALSE;
	}

	CString cspreviousHeatID = GetPreviousHeatID(curHeatID);
	if (cspreviousHeatID.GetLength() != 9)
	{
		return FALSE;
	}

    CString strUri = CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,cspreviousHeatID);
	COleDateTime dTappingEndTime = GetObjectPropValue(strUri,_T("Tapping_End_Time")).ToDateTime();
	COleDateTime dCurTime = COleDateTime::GetCurrentTime();
	COleDateTimeSpan span = dCurTime - dTappingEndTime;
	
	LONG smeltperious = (LONG)span.GetTotalMinutes();

	if (smeltperious > 0)
	{
	   if (!SetObjectPropValue(strUri,_T("Smelt_Period"),CL3Variant((L3LONG)smeltperious)))
	   {
			return FALSE; 
	   }
	}

	return TRUE;	
}

/// 获取上一炉号
CString CBOF_Unit_Mag::GetPreviousHeatID(LPCTSTR lpcszHeatID)
{
	CString cstrHeatID = lpcszHeatID;
	if (cstrHeatID.GetLength() != 9)
	{
		return _T("");
	}
	CString cspartHeatID = cstrHeatID.Right(5);
	CString csYear = cstrHeatID.Mid(2,2);
	int ipartHeatID = 0;
	int iYear = 0;
	try
	{
		ipartHeatID = _ttoi(cspartHeatID);
		iYear = _ttoi(csYear);
	}
	catch(...)
	{
	}

	CString csPreviousHeatID;
	if (ipartHeatID > 1)
	{
		csPreviousHeatID.Format(_T("%05d"),(INT)(ipartHeatID-1));
		csPreviousHeatID = cstrHeatID.Left(4) + csPreviousHeatID;
	}
	else
	{
		iYear = iYear - 1;
		CString cslastYear;
		cslastYear.Format(_T("%02d"),(INT)iYear);

		CString cssubHeatID;
		cssubHeatID = cstrHeatID.Left(2) + cslastYear;

		CString csSQL;
		csSQL.Format(_T("select max(HeatID) as HeatID from CBOF_Process_Data where substr(HeatID,1,4) ='%s'"),cssubHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
			return _T("");
		rs.MoveFirst();
		csPreviousHeatID = rs.GetFieldByName(_T("HeatID")).ToCString();
	}

	return csPreviousHeatID;
}

/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  获取最近炉号 2009-02-28 增加炉号
/// <Param name="Reason" type="L3STRING">原因</Param>
/// </Method>
L3RECORDSET CBOF_Unit_Mag::GetPreThreeHeatID()
{
	CString csUnitID = GetIdentity().ToCString();
	CString csBOFID = csUnitID.Mid(2,1);
	CString csTempSQL =_T("select * from (select HeatID from CBOF_Base_Data where substr(HeatID,2,1) = '%s'  order by  HeatID desc) where rownum < 4");
	CString csSQL;
	csSQL.Format(csTempSQL,csBOFID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;
	return rs.Detach();	
}

/// <Method class="CBOF_Unit_Mag" name="AcceptBOFRemainSlag" type="L3BOOL">
/// 接收转炉留渣数据 2016-08-11
/// <Param name="rsData" type="L3RECORDSET">留渣数据</Param>
/// </Method>
L3BOOL CBOF_Unit_Mag::AcceptBOFRemainSlag(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;
    
	rs.MoveFirst();
	CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csHeatIDUri = BOF_PROCESS_DATA_CLASS_URI + _T("\\") + csHeatID;
    int nRemainSlag =  rs.GetFieldByName(_T("RemainSlagStatus")).ToShort ();
	if(nRemainSlag > 0)
	{
		
	    SetObjectPropValue(csHeatIDUri,_T("RemainSlag"),CL3Variant(_T("否")));
	}
	else if(nRemainSlag < 0)
	{
        SetObjectPropValue(csHeatIDUri,_T("RemainSlag"),CL3Variant(_T("是")));
	  }
	return TRUE;		
}
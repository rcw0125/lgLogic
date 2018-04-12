// 逻辑类CDeS_Unit_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CDeS_Unit_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CDeS_Unit_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CDeS_Unit_Mag.h"
#include "_CDeS_Base_Data.h"
#include "L3NameParser.h"
#include "_CBFIron.h"
#include "_CDeS_Lance_Data.h"


//2010-01-04 将	EventIronChanged 修改改在事务之外

//当对象被装载到系统中时，被调用
void CDeS_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CDeS_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 返回机组的加工区域
/// ARG << lstURIs : 接收所有加工区对象的URI
/// </summary>
BOOL CDeS_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetProduceAreas( lstURIs);
}

/// <summary>
/// 得到机组前序材料缓冲区的URI
/// </summary>
CString CDeS_Unit_Mag::GetInputCache()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetInputCache();
}

/// <summary>
/// 得到机组后继材料缓冲区的URI
/// </summary>
CString CDeS_Unit_Mag::GetOutputCache()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetOutputCache();
}

/// <summary>
/// 机组上料前预处理。在机组上料前调用，继承类可重载此方法进行预先数据准备和处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 返回TRUE继续上料；返回FALSE中断上料。
/// </summary>
BOOL CDeS_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// 机组上料后续处理。在机组上料后调用，继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDeS_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// 返回机组上料记录的类型URI
/// </summary>
CString CDeS_Unit_Mag::GetFeedingLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetFeedingLogType();
}


/// <summary>
/// 准备上料记录数据。继承类可重载此函数进行额外的数据处理。
/// ARG >> rsFeedingLogs : 上料记录信息。
/// RET << void
/// </summary>
void CDeS_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
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
BOOL CDeS_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
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
BOOL CDeS_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// 下线前预处理。在执行下线操作前调用，继承类可重载此函数进行预先的数据准备和处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 返回TRUE继续下线；返回FALSE中断下线。
/// </summary>
BOOL CDeS_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// 下线后续处理。在执行下线操作后调用，继承类可重载此函数进行额外处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDeS_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsDelivered( rsMaterialInfo);
}


/// <summary>
/// 返回机组产出记录的类型URI
/// </summary>
CString CDeS_Unit_Mag::GetDeliveryLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetDeliveryLogType();
}


/// <summary>
/// 准备下料记录数据。
/// ARG >> rsDeliveryLog : 下料记录数据。
/// RET <<void
/// </summary>
void CDeS_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// 返回本机组的通讯器对象的URI
/// </summary>
CString CDeS_Unit_Mag::GetCommunicator()
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
BOOL CDeS_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// 计划下达后续处理。在向下位系统发送计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsSend : 下发下位系统的计划数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDeS_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
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
BOOL CDeS_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// 计划取消后续处理。在向下位系统发送取消计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsCancel : 下发下位系统的计划取消数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDeS_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// 处理材料上线的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDeS_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// 处理材料进入加工区域的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDeS_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// 处理材料离开加工区域事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDeS_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// 处理材料生产完毕事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDeS_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// 处理机组测量数据变更事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDeS_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}

/// 计算下一处理号
CString CDeS_Unit_Mag::CalculateNextTreatNo(LPCTSTR lpcszTreatNo)
{
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strTreatNo(lpcszTreatNo); strTreatNo.Trim();
	CString strNextID; 	
	CString strID = GetIdentity().ToCString();
	strID = strID.Mid(2,1);
	L3LONG nID = _ttoi(strID)-1;
	strID.Format(_T("%1d"),nID);
	if(strTreatNo.IsEmpty())
	{
		LONG nYear = curTime.GetYear();
		nYear = nYear - (nYear / 100) * 100;
		strNextID.Format(_T("%s%02d%05d"),(LPCTSTR)strID,nYear,(INT)1);
	}
	else
	{
		CString strIDYear = strTreatNo.Mid(1,2);
		CString strIDSeq = strTreatNo.Mid(3,strTreatNo.GetLength()-3);
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
		strNextID.Format(_T("%s%02d%05d"),strID,nYear,nSeq);
	}
	return strNextID;
}

/// <Method class="CDeS_Unit_Mag" name="DesignateIronLadle" type="L3BOOL">
/// 指定即将到达的铁水。
/// <Param name="rsIrons" type="L3RECORDSET">铁水(铁次+罐号)</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::DesignateIronLadle(L3RECORDSET rsIrons)
{
	CL3RecordSetWrap rs = rsIrons;
	if(rs.GetRowCount() < 1)
		return 0;
	
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("IronStatus")) < 0)
	{
		return -1;
	}

	CL3RecordSetWrap rsDeSIron;
	if(!CreateClassPropSet(CDES_BASE_URI,rsDeSIron))
		return -2;
	rsDeSIron.DelField(_T("GUID"));
	rsDeSIron.CopyFrom(rs);

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	COleDateTime dtCreateTime = COleDateTime::GetCurrentTime();

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	// 记录状态日志
	CL3RecordSetWrap rsStatus;
	if(!CreateClassPropSet(CDES_STATUS_URI,rsStatus))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}
	//rsStatus.DelField(_T("GUID"));

	rsDeSIron.MoveFirst();
	while(!rsDeSIron.IsEOF())
	{
		rsDeSIron.SetFieldByName(_T("DeS_Flag"),CL3Variant((LONG)0));
		rsDeSIron.SetFieldByName(_T("ProductionDate"),CL3Variant(dtCreateTime));
		rsDeSIron.SetFieldByName(_T("Status"),CL3Variant((L3SHORT)CDeS_Base_Data::ironArrived));
		rsDeSIron.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsDeSIron.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsDeSIron.SetFieldByName(_T("Estimate_Weight"),rsDeSIron.GetFieldByName(_T("Net_Weight")));
		rsDeSIron.SetFieldByName(_T("Destination"),(L3LONG)0);
		CString csObj = GetName() + rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();
		CString csUri = CL3NameParser::MergeClassDomainName(UNIT_DUTY_CLASS_URI,csObj);
		rsDeSIron.SetFieldByName(_T("DeS_Operator"),GetObjectPropValue(csUri,_T("HeadFurnace")));
		rsDeSIron.SetFieldByName(_T("RemoveSlag_Operator"),GetObjectPropValue(csUri,_T("Assistant")));
		rsDeSIron.SetFieldByName(_T("Mediator"),GetObjectPropValue(csUri,_T("SecondHand")));
		rsDeSIron.SetFieldByName(_T("RemoveSlagCount"),CL3Variant((LONG)6));

		rsStatus.AppendRecord();
		CString cstrIDObject = rsDeSIron.GetFieldByName(_T("MaterialID")).ToCString();
		rsStatus.SetFieldByName(_T("ID_Object"),CL3Variant(cstrIDObject));
		rsStatus.SetFieldByName(_T("Status"),CL3Variant((L3SHORT)CDeS_Base_Data::ironArrived));
		rsStatus.SetFieldByName(_T("Change_Time"),CL3Variant(DeSStatusChanged_Time));

		rsDeSIron.MoveNext();
	}

	rsDeSIron.MoveFirst();

	if(CreateNewObjects(CDES_BASE_URI,rsDeSIron) < rsDeSIron.GetRowCount())
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -5;
	}

	if(CreateNewObjects(CDES_STATUS_URI,rsStatus) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -6;
	}

	// 修改铁水状态
	rs.DelField(_T("TAP_No"));
	rs.DelField(_T("TPC_No"));
	rs.DelField(_T("Gross_Weight"));
	rs.DelField(_T("Net_Weight"));

	rs.AddField(_T("IronStatus"),VT_I4);
	rs.AddField(_T("Destination"),VT_I4);
	//rs.AddField(_T("Source"),VT_I4);
	rs.AddField(_T("DeSFlag"),VT_I4);
	
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("Destination"),CL3Variant((LONG)CBFIron::ironToNoWhere));
		rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironProcessingAtDeS));
		//rs.SetFieldByName(_T("Source"),CL3Variant((LONG)1));
		rs.SetFieldByName(_T("DeSFlag"),CL3Variant((LONG)1));
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rs))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return -7;
	}

	if(nTrans > 0)
		Commit(nTrans);

	L3LONG EventIronChanged = (GetObjectPropValue(BFIronStore_URI,_T("EventIronChanged"))).ToLong();
	EventIronChanged *= -1;
	SetObjectPropValue(BFIronStore_URI,_T("EventIronChanged"),CL3Variant((LONG)EventIronChanged));

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="UndoDesignateIronLadle" type="L3BOOL">
/// 测消指定即将到达的铁水。
/// <Param name="strIron" type="L3STRING">铁水(铁次+罐号)</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::UndoDesignateIronLadle(L3STRING strIron)
{
	if(strIron == NULL)
		return 0;
	
    CString cstrIron = strIron;

	CString csSQL;
	CString csTemp =_T(" SELECT * FROM %s WHERE MaterialID = '%s' ");
	csSQL.Format(csTemp,CDES_PROCESS_URI,cstrIron);
	
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		return -2;
	}

	csTemp =_T(" SELECT * FROM %s WHERE ID_Object = '%s' ");
	csSQL.Format(csTemp,CDES_STATUS_URI,cstrIron);
	
	CL3RecordSetWrap rsStatus;
	if(!Query(csSQL,rsStatus)||rsStatus.IsNull())
	{
		return -2;
	}

	CString csBFIronUri = CL3NameParser::MergeClassDomainName(MATERIAL_BFIRON_URI,cstrIron);

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	if (!PutObjectIntoTrans(csBFIronUri,FALSE))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -2;
	}

	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		CString cstrTreatNo = rsResult.GetFieldByName(_T("TreatNo")).ToCString();
		csTemp =_T(" SELECT * FROM %s WHERE TreatNo = '%s' ");
		csSQL.Format(csTemp,CDES_RUNTIME_URI,cstrTreatNo);
		
		CL3RecordSetWrap rsRuntime;
		if(!Query(csSQL,rsRuntime)||rsRuntime.IsNull())
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -2;
		}

		if(rsRuntime.GetRowCount() > 0)
		{
		    rsRuntime.MoveFirst();
			if(DeleteOldObjects(CDES_RUNTIME_URI,rsRuntime) < rsRuntime.GetRowCount())
			{
				if(nTrans > 0)
					Rollback(nTrans);
				return -3;
			}
		}

		if(DeleteOldObjects(CDES_PROCESS_URI,rsResult) < rsResult.GetRowCount())
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rsStatus.GetRowCount() > 0)
	{
	    rsStatus.MoveFirst();
		if(DeleteOldObjects(CDES_STATUS_URI,rsStatus) < rsStatus.GetRowCount())
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -3;
		}
	}


	CString csDeSIronUri = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,cstrIron);
	if(!DeleteOldObject(csDeSIronUri))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -3;
	}


	L3LONG nGrossWeightFlag = GetObjectPropValue(csBFIronUri,_T("GrossFlag")).ToLong();
	if (nGrossWeightFlag == 1)
	{
		if(!SetObjectPropValue(csBFIronUri,_T("Destination"),(LONG)CBFIron::ironToBOF))
		{
			if(nTrans > 0)
    			Rollback(nTrans);
			return -4;
		}

		if(!SetObjectPropValue(csBFIronUri,_T("IronStatus"),(LONG)CBFIron::ironDestDefined))
		{
			if(nTrans > 0)
    			Rollback(nTrans);
			return -5;
		}
	}
	else
	{
		if(!SetObjectPropValue(csBFIronUri,_T("IronStatus"),(LONG)CBFIron::ironNotProcessed))
		{
			if(nTrans > 0)
    			Rollback(nTrans);
			return -5;
		}
	}

	if(!SetObjectPropValue(csBFIronUri,_T("DeSFlag"),(LONG)0))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return -8;
	}


	if(nTrans > 0)
		Commit(nTrans);

	L3LONG EventIronChanged = (GetObjectPropValue(BFIronStore_URI,_T("EventIronChanged"))).ToLong();
	EventIronChanged *= -1;
	SetObjectPropValue(BFIronStore_URI,_T("EventIronChanged"),CL3Variant((LONG)EventIronChanged));


	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="UndoDesignateIronLadle" type="L3LONG">
/// 脱硫区域铁水状态变化
/// <Param name="strIron" type="L3STRING">铁水(铁次+罐号)</Param>
/// <Param name="nStatus" type="L3SHORT">铁水状态)</Param>
/// <Param name="strAreaID" type="L3STRING">铁水状态)</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::ChangeStatus(L3STRING strIron,L3SHORT nStatus,L3STRING strAreaID)
{
	if (strIron == NULL)
	{
		return 0;
	}
	CString cstrIron = strIron;
	CString csDeSIronUri = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,cstrIron);

    L3SHORT curStatus = -1;
	curStatus = GetObjectPropValue(csDeSIronUri,_T("Status")).ToShort();

 	CString strArea = String_BSTR2TChar(strAreaID);
	strArea.Trim();
	CString cscurAreaID = strArea;

	CString beginStatusUnitID=_T("");
	bool orderiserror = true;
	switch (nStatus)
	{
		case CDeS_Base_Data::ironEndPreRemoveSlag://预捞渣结束
			GetUnitForEndStatus(cstrIron,nStatus,beginStatusUnitID);
			strArea = beginStatusUnitID;
			if(curStatus != CDeS_Base_Data::ironBeginPreRemoveSlag)
			    orderiserror = false;
			break;
		case CDeS_Base_Data::ironEndRemoveSlag://捞渣结束
			GetUnitForEndStatus(cstrIron,nStatus,beginStatusUnitID);
			strArea = beginStatusUnitID;
			if(curStatus != CDeS_Base_Data::ironBeginRemoveSlag)
			    orderiserror = false;
			break;
		default:
			break;
	}

    if (!orderiserror)
	{
		return -2;
	}

	if((nStatus <= curStatus) && (nStatus != CDeS_Base_Data::ironBeginSpray))
	{
		return -3;
	}

	L3LONG iTime = 0;
    L3SHORT nEndStatus = -1;
	L3SHORT nDeSType = -1;
	CString csAreaID = _T("");
	L3LONG iPreRemoveSlagTime = 0;
	L3LONG iRemoveSlagTime = 0;
	L3LONG iBlowTimeTotal = 0;
	L3LONG iProcessTime = 0;
	L3LONG iTotalTime = 0;
	switch (nStatus)
	{
		case CDeS_Base_Data::ironEndPreRemoveSlag://预捞渣结束
			iTime = 0;
			iTime = CalculateTime(cstrIron,(L3SHORT)CDeS_Base_Data::ironBeginPreRemoveSlag,CDeS_Base_Data::ironEndPreRemoveSlag);
            iPreRemoveSlagTime = iTime;
			break;
		case CDeS_Base_Data::ironEndRemoveSlag://捞渣结束
			iTime = 0;
			iTime = CalculateTime(cstrIron,(L3SHORT)CDeS_Base_Data::ironBeginRemoveSlag,CDeS_Base_Data::ironEndRemoveSlag);
            iRemoveSlagTime = iTime;
			//break;
			iTime = 0;
			iTime = CalculateTime(cstrIron,(L3SHORT)CDeS_Base_Data::ironArrived,CDeS_Base_Data::ironEndRemoveSlag);
            iProcessTime = iTime;
			break;
		case CDeS_Base_Data::ironEndSpray://喷吹用时
			iTime = 0;
			iTime = CalculateTime(cstrIron,(L3SHORT)CDeS_Base_Data::ironBeginSpray,CDeS_Base_Data::ironEndSpray);
            iBlowTimeTotal = iTime;
			break;
		case CDeS_Base_Data::ironDepart://全程用时
			iTime = 0;
			iTime = CalculateTime(cstrIron,(L3SHORT)CDeS_Base_Data::ironArrived,CDeS_Base_Data::ironDepart);
            iTotalTime = iTime;
			if (!IsOverForPreStatus(cstrIron,nStatus,nEndStatus,csAreaID))
			{
				if (nEndStatus != -1)
				{
					L3STRING bstrMaterial = cstrIron.AllocSysString();
					L3STRING bstrAreaID = csAreaID.AllocSysString();
					if (ChangeStatus(bstrMaterial,nEndStatus,bstrAreaID) != 1)
					{
						L3SysFreeString(bstrMaterial);
						L3SysFreeString(bstrAreaID);
						return -8;
					}		
					L3SysFreeString(bstrMaterial);
					L3SysFreeString(bstrAreaID);
				}
			}
			break;
		case CDeS_Base_Data::ironBeginPreRemoveSlag://预捞渣开始
			if (!IsOverForPreStatus(cstrIron,nStatus,nEndStatus,csAreaID))
			{
				if (nEndStatus != -1)
				{
					L3STRING bstrMaterial = cstrIron.AllocSysString();
					L3STRING bstrAreaID = csAreaID.AllocSysString();
					if (ChangeStatus(bstrMaterial,nEndStatus,bstrAreaID) != 1)
					{
						L3SysFreeString(bstrMaterial);
						L3SysFreeString(bstrAreaID);
						return -8;
					}		
					L3SysFreeString(bstrMaterial);
					L3SysFreeString(bstrAreaID);
				}
			}
			break;
		case CDeS_Base_Data::ironBeginSpray://喷吹开始
			if (!IsOverForPreStatus(cstrIron,nStatus,nEndStatus,csAreaID))
			{
				if (nEndStatus != -1)
				{
					L3STRING bstrMaterial = cstrIron.AllocSysString();
					L3STRING bstrAreaID = csAreaID.AllocSysString();
					if (ChangeStatus(bstrMaterial,nEndStatus,bstrAreaID) != 1)
					{
						L3SysFreeString(bstrMaterial);
						L3SysFreeString(bstrAreaID);
						return -8;
					}		
					L3SysFreeString(bstrMaterial);
					L3SysFreeString(bstrAreaID);
				}
			}
			break;
		case CDeS_Base_Data::ironBeginRemoveSlag://捞渣开始

			nDeSType = (GetObjectPropValue(csDeSIronUri,_T("DeSType"))).ToShort();
			if (nDeSType < 1 )
			{
	    		return -12;
			}
			if (!IsOverForPreStatus(cstrIron,nStatus,nEndStatus,csAreaID))
			{
				if (nEndStatus != -1)
				{
					L3STRING bstrMaterial = cstrIron.AllocSysString();
					L3STRING bstrAreaID = csAreaID.AllocSysString();
					if (ChangeStatus(bstrMaterial,nEndStatus,bstrAreaID) != 1)
					{
						L3SysFreeString(bstrMaterial);
						L3SysFreeString(bstrAreaID);
						return -8;
					}		
					L3SysFreeString(bstrMaterial);
					L3SysFreeString(bstrAreaID);
				}
			}
			//BeginRemoveSlagNoDeS(cstrIron,cscurAreaID,CDeS_Base_Data::ironBeginRemoveSlag,nDeSType);
			break;
		default:
			break;
	}

	CString cstrStatus;
	cstrStatus.Format(_T("%2d"),nStatus);
	// 记录状态日志
	CL3RecordSetWrap rsStatus;
	if(!CreateClassPropSet(CDES_STATUS_URI,rsStatus))
	{
		return -9;
	}

	CString cstrAreaID = GetIdentity().ToCString() + strArea;

	if(nStatus==CDeS_Base_Data::ironBeginRemoveSlag)
	{
		SetObjectPropValue(csDeSIronUri,_T("RemoveSlag_UnitID"),(CL3Variant(cstrAreaID)));
	}

	rsStatus.DelField(_T("GUID"));
	rsStatus.AppendRecord();
	rsStatus.SetFieldByName(_T("ID_Object"),CL3Variant(cstrIron));
	rsStatus.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	if ((nStatus == CDeS_Base_Data::ironDepart) && (DeSStatus == CDeS_Base_Data::ironDepart))
		rsStatus.SetFieldByName(_T("Change_Time"),CL3Variant(DeSStatusChanged_Time));
	else
		rsStatus.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));

	if(nStatus!=CDeS_Base_Data::ironDepart)
		rsStatus.SetFieldByName(_T("AreaID"),CL3Variant(cstrAreaID));

	CString csDeSAreaUri = CL3NameParser::MergeClassDomainName(DES_AREA_CLASS_URI,cstrAreaID);

	//LONG nTrans = 0;
	//if(!IsInTrans())
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return -1;
	//}
	//PutObjectIntoTrans(csDeSIronUri,FALSE);
	//PutObjectIntoTrans(csDeSAreaUri,FALSE);

	if(CreateNewObjects(CDES_STATUS_URI,rsStatus) < 1)
	{
		//if(nTrans > 0)
		//	Rollback(nTrans);
		return -10;
	}

    CString cstrTreatNo,csDeSProcUri;
	switch (nStatus)
	{
		case CDeS_Base_Data::ironEndPreRemoveSlag://预捞渣结束
			if(!SetObjectPropValue(csDeSIronUri,_T("PreRemoveSlagTime"),CL3Variant(iPreRemoveSlagTime)))
			{
				//if(nTrans > 0)
				//	Rollback(nTrans);
				return -4;
			}
			break;
		case CDeS_Base_Data::ironEndRemoveSlag://捞渣结束
			if(!SetObjectPropValue(csDeSIronUri,_T("RemoveSlagTime"),CL3Variant(iRemoveSlagTime)))
			{
				//if(nTrans > 0)
				//	Rollback(nTrans);
				return -5;
			}
			if(!SetObjectPropValue(csDeSIronUri,_T("ProcessTime"),CL3Variant(iProcessTime)))
			{
				//if(nTrans > 0)
				//	Rollback(nTrans);
				return -5;
			}
			break;
		case CDeS_Base_Data::ironEndSpray://喷吹用时
			if(!SetObjectPropValue(csDeSIronUri,_T("BlowTimeTotal"),CL3Variant(iBlowTimeTotal)))
			{
				//if(nTrans > 0)
				//	Rollback(nTrans);
				return -6;
			}

			cstrTreatNo = TreatNo;
			csDeSProcUri = CL3NameParser::MergeClassDomainName(CDES_PROCESS_URI,cstrTreatNo);
			if(!SetObjectPropValue(csDeSProcUri,_T("BlowTime"),CL3Variant(iBlowTimeTotal)))
			{
				//if(nTrans > 0)
				//	Rollback(nTrans);
				return -6;
			}
			break;
		case CDeS_Base_Data::ironDepart://全程用时
			if(!SetObjectPropValue(csDeSIronUri,_T("TotalTime"),CL3Variant(iTotalTime)))
			{
				//if(nTrans > 0)
				//	Rollback(nTrans);
				return -7;
			}
			break;
		default:
			break;
	}

	if(!SetObjectPropValue(csDeSIronUri,_T("Status"),CL3Variant((L3LONG)nStatus)))
	{
		//if(nTrans > 0)
		//	Rollback(nTrans);
		return -11;
	}

	if (cstrAreaID.GetLength() == 4)
	{
		if(!SetObjectPropValue(csDeSAreaUri,_T("Status"),CL3Variant((L3LONG)nStatus)))
		{
			//if(nTrans > 0)
			//	Rollback(nTrans);
			return -12;
		}
	}

	//if(nTrans > 0)
	//	Commit(nTrans);

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="CalculateTime" type="L3BOOL">
/// 计算时间
/// <Param name="lpcszDeSIron" type="LPCTSTR">铁水(铁次+罐号)</Param>
/// <Param name="nStatus" type="L3SHORT">状态)</Param>
/// <Param name="ncurStatus" type="L3SHORT">当前状态)</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::CalculateTime(LPCTSTR lpcszDeSIron,L3SHORT nStatus,L3SHORT ncurStatus)
{
	CString cstrDeSIron = lpcszDeSIron;

	CString csSQL;
	CString csTemp =_T(" SELECT * FROM %s WHERE ID_Object = '%s' and Status = %d order by Change_Time");
	csSQL.Format(csTemp,CDES_STATUS_URI,cstrDeSIron,nStatus);
	
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		return -1;
	}

	L3LONG nTotalTime = -1;
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		L3DATETIME dpreRemoveSlagBeginTime = rsResult.GetFieldByName(_T("Change_Time")).ToDateTime();
		COleDateTimeSpan span;
		if ((ncurStatus == CDeS_Base_Data::ironDepart) && (DeSStatus == CDeS_Base_Data::ironDepart))
		 span = (L3DATETIME)DeSStatusChanged_Time - dpreRemoveSlagBeginTime;
		else
		 span = (L3DATETIME)(COleDateTime::GetCurrentTime()) - dpreRemoveSlagBeginTime;

		if(ncurStatus == CDeS_Base_Data::ironEndSpray)
			nTotalTime = (LONG)span.GetTotalSeconds();
		else
		{
			nTotalTime = (LONG)span.GetTotalSeconds();
			if(nTotalTime >= 1 && nTotalTime <=60)
				nTotalTime = 1;
			else
			nTotalTime = (LONG)span.GetTotalMinutes();
		}
	}
	return nTotalTime;
}

/// <Method class="CDeS_Unit_Mag" name="DesignateDeSUnitID" type="L3LONG">
/// 指定工位。
/// <Param name="strIron" type="L3STRING">铁水(铁次+罐号)</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::DesignateDeSUnitID(L3STRING strIron)
{
	//2010-01-04 取消事务管理

	if (strIron == NULL)
	{
		return 0;
	}

	CString cstrIron = strIron;
	CString cstrUnitID = GetIdentity().ToCString();

	CString csUnitUri = CL3NameParser::MergeClassDomainName(DES_CLASS_URI,cstrUnitID);
	CString csIronUri = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,cstrIron);

	L3SHORT nStatus = GetObjectPropValue(csIronUri,_T("Status")).ToShort();
	if((nStatus > CDeS_Base_Data::ironEndSpray) || (nStatus < CDeS_Base_Data::ironArrived))
	{
		return -2;
	}

	//LONG nTrans = 0;
	//if(!IsInTrans())
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return -1;
	//}
	//PutObjectIntoTrans(csUnitUri,FALSE);
	//PutObjectIntoTrans(csIronUri,FALSE);

	//if(!SetObjectPropValue(csUnitUri,_T("MaterialID_UnDeS"),CL3Variant(cstrIron)))
	//{
	//	if(nTrans > 0)
 //   		Rollback(nTrans);
	//	return -3;
	//}


	SetObjectPropValue(csUnitUri,_T("MaterialID_UnDeS"),CL3Variant(cstrIron));
	SetObjectPropValue(csIronUri,_T("DeS_UnitID"),CL3Variant(cstrUnitID));
	SetObjectPropValue(csIronUri,_T("RemoveSlag_UnitID"),CL3Variant(cstrUnitID));

	//if(!SetObjectPropValue(csIronUri,_T("DeS_UnitID"),CL3Variant(cstrUnitID)))
	//{
	//	if(nTrans > 0)
 //   		Rollback(nTrans);
	//	return -4;
	//}

	//if(!SetObjectPropValue(csIronUri,_T("RemoveSlag_UnitID"),CL3Variant(cstrUnitID)))
	//{
	//	if(nTrans > 0)
 //   		Rollback(nTrans);
	//	return -4;
	//}

	CString csTeamID = GetObjectPropValue(csIronUri,_T("Team")).ToCString();
	CString csObj = GetName() + csTeamID;
	CString csUri = CL3NameParser::MergeClassDomainName(UNIT_DUTY_CLASS_URI,csObj);

	SetObjectPropValue(csIronUri,_T("DeS_Operator"),GetObjectPropValue(csUri,_T("HeadFurnace")));
	SetObjectPropValue(csIronUri,_T("RemoveSlag_Operator"),GetObjectPropValue(csUri,_T("Assistant")));
	SetObjectPropValue(csIronUri,_T("Mediator"),GetObjectPropValue(csUri,_T("SecondHand")));


	//if(!(SetObjectPropValue(csIronUri,_T("DeS_Operator"),GetObjectPropValue(csUri,_T("HeadFurnace")))))
	//{
	//	if(nTrans > 0)
 //   		Rollback(nTrans);
	//	return -4;
	//}
	//if(!(SetObjectPropValue(csIronUri,_T("RemoveSlag_Operator"),GetObjectPropValue(csUri,_T("Assistant")))))
	//{
	//	if(nTrans > 0)
 //   		Rollback(nTrans);
	//	return -4;
	//}

	//if(!(SetObjectPropValue(csIronUri,_T("Mediator"),GetObjectPropValue(csUri,_T("SecondHand")))))
	//{
	//	if(nTrans > 0)
 //   		Rollback(nTrans);
	//	return -4;
	//}

	//if(nTrans > 0)
	//	Commit(nTrans);

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="StartBlowing" type="L3LONG">
/// 处理喷吹开始事件
/// <Param name="Area" type="L3STRING">开始喷吹的工位</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::StartBlowing(L3STRING Area)
{

	CString strArea = String_BSTR2TChar(Area);
	strArea.Trim();
	if(strArea.IsEmpty() || (strArea !=_T("A") && strArea !=_T("B")))
	{
		return 0;
	}

	CString strAreaID = GetIdentity().ToCString() + strArea;
	CString strAreaURI = CL3NameParser::MergeClassDomainName(DES_AREA_CLASS_URI,strAreaID);

    MaterialID_DeSing = MaterialID_UnDeS;
	CString strMaterialID = MaterialID_DeSing;

	CString strDeSIronURI = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,strMaterialID);
	L3SHORT nStatus = GetObjectPropValue(strDeSIronURI,_T("Status")).ToShort();
	if((nStatus < CDeS_Base_Data::ironArrived) || (nStatus > CDeS_Base_Data::ironEndSpray) || (nStatus == CDeS_Base_Data::ironBeginSpray))
	{
		return -2;
	}

	CString strBFIronURI = CL3NameParser::MergeClassDomainName(MATERIAL_BFIRON_URI,strMaterialID);

	L3FLOAT fS = (GetObjectPropValue(strBFIronURI,_T("S"))).ToFloat();
	L3FLOAT fP = (GetObjectPropValue(strBFIronURI,_T("P"))).ToFloat();
	L3FLOAT fWeight = (GetObjectPropValue(strBFIronURI,_T("Net_Weight"))).ToFloat();

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	PutObjectIntoTrans(strBFIronURI,FALSE);
	PutObjectIntoTrans(strDeSIronURI,FALSE);
	PutObjectIntoTrans(strAreaURI,FALSE);

	if(!(strAreaID.GetLength() < 4) || (strMaterialID.GetLength() < 3))
	{
		CString csTPC_No = strMaterialID.Right(2);
		CString csTAP_No = strMaterialID.Mid(0,strMaterialID.GetLength()-2);

		if(!SetObjectPropValue(strAreaURI,_T("TAP_No"),CL3Variant(csTAP_No)))
		{
			if(nTrans > 0) Rollback(nTrans);
			return -3;
		}
		if(!SetObjectPropValue(strAreaURI,_T("TPC_No"),CL3Variant(csTPC_No)))
		{
			if(nTrans > 0) Rollback(nTrans);
			return -3;
		}
		if(!SetObjectPropValue(strAreaURI,_T("S"),CL3Variant(fS)))
		{
			if(nTrans > 0) Rollback(nTrans);
			return -3;
		}
		if(!SetObjectPropValue(strAreaURI,_T("P"),CL3Variant(fP)))
		{
			if(nTrans > 0) Rollback(nTrans);
			return -3;
		}
		if(!SetObjectPropValue(strAreaURI,_T("Weight"),CL3Variant(fWeight)))
		{
			if(nTrans > 0) Rollback(nTrans);
			return -3;
		}
	}

	if(!SetObjectPropValue(strDeSIronURI,_T("DeS_Flag"),(L3LONG)1))
	{
		if(nTrans > 0) Rollback(nTrans);
		return -3;
	}
	if(!SetObjectPropValue(strDeSIronURI,_T("DeS_UnitID"),CL3Variant(strAreaID)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return -3;
	}

	//2009-11-09
	TreatNo = NextTreatNo;
	if(TreatNo == _T(""))
		TreatNo = CalculateNextTreatNo(NULL);
	NextTreatNo = CalculateNextTreatNo(TreatNo);

	CurArea = Area;
	CString csTreatNo = TreatNo;
	// 记录脱硫实绩
	CL3RecordSetWrap rsProcess;
	if(!CreateClassPropSet(CDES_PROCESS_URI,rsProcess))
	{
		if(nTrans > 0) Rollback(nTrans);
		return -4;
	}
	rsProcess.DelField(_T("GUID"));
	rsProcess.AppendRecord();
	rsProcess.SetFieldByName(_T("TreatNo"),CL3Variant(csTreatNo));
	rsProcess.SetFieldByName(_T("MaterialID"),CL3Variant(strMaterialID));
	rsProcess.SetFieldByName(_T("S_B"),CL3Variant(fS));
	rsProcess.SetFieldByName(_T("P_B"),CL3Variant(fP));
	rsProcess.SetFieldByName(_T("LanceNo"),GetObjectPropValue(strAreaURI,_T("LanceNo")));
	rsProcess.SetFieldByName(_T("LanceAge"),CL3Variant(GetObjectPropValue(strAreaURI,_T("LanceAge")).ToLong()+1));
	rsProcess.SetFieldByName(_T("BlowBeginTime"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsProcess.SetFieldByName(_T("AreaID"),CL3Variant(strAreaID));
	if(CreateNewObjects(CDES_PROCESS_URI,rsProcess) < 1)
	{
		if(nTrans > 0)	Rollback(nTrans);
		return -5;
	}

	if(!SetObjectPropValue(strAreaURI,_T("LanceAge"),CL3Variant(GetObjectPropValue(strAreaURI,_T("LanceAge")).ToLong()+1)))
	{
		if(nTrans > 0)	Rollback(nTrans);
		return -6;

	}

	if(nTrans > 0)
		Commit(nTrans);

	// 记录脱硫状态实绩
	L3STRING bstrMaterialID = strMaterialID.AllocSysString();
	L3STRING bstrArea = strArea.AllocSysString();
	if (ChangeStatus(bstrMaterialID,CDeS_Base_Data::ironBeginSpray,bstrArea) != 1)
	{
		L3SysFreeString(bstrMaterialID);
		L3SysFreeString(bstrArea);
		return -7;
	}
	L3SysFreeString(bstrMaterialID);
	L3SysFreeString(bstrArea);


	// 开始定时器
	if(!strAreaURI.IsEmpty())
	{
    	InvokeObjectMethod(strAreaURI,_T("SetDeSAreaTimer"));
	}
	
	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="StopBlowing" type="L3LONG">
/// 处理喷吹结束事件
/// </Method>
L3LONG CDeS_Unit_Mag::StopBlowing()
{
	CString strArea = CurArea;
	strArea.Trim();
	if(strArea.IsEmpty() || (strArea !=_T("A") && strArea !=_T("B")))
	{
		return 0;
	}
    MaterialID_DeSed = MaterialID_DeSing;
	CString strMaterialID = MaterialID_DeSed;
	CString strAreaID = GetIdentity().ToCString() + strArea;
	CString strAreaURI = CL3NameParser::MergeClassDomainName(DES_AREA_CLASS_URI,strAreaID);

	CString strDeSIronURI = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,strMaterialID);
	L3SHORT nStatus = GetObjectPropValue(strDeSIronURI,_T("Status")).ToShort();
	if(nStatus != CDeS_Base_Data::ironBeginSpray)
	{
		return -2;
	}

	// 记录脱硫状态实绩
	L3STRING bstrMaterialID = strMaterialID.AllocSysString();
	L3STRING bstrArea = strArea.AllocSysString();
	if (ChangeStatus(bstrMaterialID,CDeS_Base_Data::ironEndSpray,bstrArea) != 1)
	{
		L3SysFreeString(bstrMaterialID);
		L3SysFreeString(bstrArea);
		return -4;
	}		
	L3SysFreeString(bstrMaterialID);
	L3SysFreeString(bstrArea);

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	PutObjectIntoTrans(strDeSIronURI,FALSE);
	PutObjectIntoTrans(strAreaURI,FALSE);

	//设置脱硫喷吹结束时刻
	CString csTreatNo = TreatNo;
	CString strProcURI = CL3NameParser::MergeClassDomainName(CDES_PROCESS_URI,csTreatNo);
	if(!SetObjectPropValue(strProcURI,_T("BlowEndTime"),CL3Variant(COleDateTime::GetCurrentTime())))
	{
		if(nTrans > 0) Rollback(nTrans);
		return -3;
	}

	//设置脱硫喷吹结束时刻储料罐重量
	CString strIronURI = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,strMaterialID);
	if(!SetObjectPropValue(strIronURI,_T("Weight_MatTank"),CL3Variant(Weight_MatTank)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return -3;
	}
    //设置脱硫喷吹结束时刻喷吹罐重量
	if(!SetObjectPropValue(strIronURI,_T("Weight_SprayTank"),CL3Variant(Weight_MatTank)))
	{
		if(nTrans > 0) Rollback(nTrans);
		return -3;
	}

	CString csLanceNo = GetObjectPropValue(strAreaURI,_T("LanceNo")).ToCString();
	CString strLanceURI = CL3NameParser::MergeClassDomainName(CDES_LANCEDATA_URI,csLanceNo);
	if(!SetObjectPropValue(strLanceURI,_T("LanceAge"),CL3Variant(GetObjectPropValue(strLanceURI,_T("LanceAge")).ToLong()+1)))
	{
		if(nTrans > 0)	Rollback(nTrans);
		return -5;

	}

    L3LONG nBlowTime = GetObjectPropValue(strProcURI,_T("BlowTime")).ToLong();
	if(!SetObjectPropValue(strLanceURI,_T("ProcessTime"),CL3Variant(GetObjectPropValue(strLanceURI,_T("ProcessTime")).ToLong()+nBlowTime/60)))
	{
		if(nTrans > 0)	Rollback(nTrans);
		return -5;
	}

	L3FLOAT fWeight = GetObjectPropValue(strDeSIronURI,_T("Net_Weight")).ToFloat();
	if(!SetObjectPropValue(strLanceURI,_T("ProcessAmount"),CL3Variant(GetObjectPropValue(strLanceURI,_T("ProcessAmount")).ToFloat()+fWeight)))
	{
		if(nTrans > 0)	Rollback(nTrans);
		return -5;
	}
	//2009-11-06 sun begin
    if(!SetObjectPropValue(strLanceURI,_T("Status"),(L3LONG)2))
	{
		if(nTrans > 0)	Rollback(nTrans);
		return -6;

	}
    //2009-11-06 sun end

	if(nTrans > 0)
		Commit(nTrans);


	// 终止定时器
	if(!strAreaURI.IsEmpty())
	{
    	InvokeObjectMethod(strAreaURI,_T("KillDeSAreaTimer"));
	}
	
	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="AcceptDeSBlowBeginData" type="L3BOOL">
/// 接收DES喷吹开始数据 
/// <Param name="rsData" type="L3RECORDSET">喷吹数据</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::AcceptDeSBlowBeginData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveFirst();
	CString csAreaID = rs.GetFieldByName(_T("AreaID"));
	L3STRING bstrAreaID = csAreaID.AllocSysString();

	if (StartBlowing(bstrAreaID) != 1)
	{
		L3SysFreeString(bstrAreaID);
		return FALSE;
	}
	L3SysFreeString(bstrAreaID);

	return TRUE;	
}

/// <Method class="CDeS_Unit_Mag" name="AcceptDeSBlowEndData" type="L3BOOL">
/// 接收DES喷吹结束数据 
/// <Param name="rsData" type="L3RECORDSET">喷吹数据</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::AcceptDeSBlowEndData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveFirst();
	L3LONG nBlowTime = rs.GetFieldByName(_T("Blow_Time")).ToLong();
	L3FLOAT fWeight = rs.GetFieldByName(_T("Mat_Consume")).ToFloat();
	L3STRING sMaterialID = rs.GetFieldByName(_T("Mat_Consume")).ToString();
    if (StopBlowing() != 1)
	{
	   return FALSE;
	}

	//LONG nTrans = 0;
	//if(!IsInTrans())
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return FALSE;
	//}

	CString strTreatNo = TreatNo;
	//记录处理实绩
	CString strProcData = CL3NameParser::MergeClassDomainName(CDES_PROCESS_URI,strTreatNo);
	if (!SetObjectPropValue(strProcData,_T("Mat_Consume"),(L3LONG)fWeight))
	{
		//if(nTrans > 0) Rollback(nTrans);
			return FALSE;
	}
	if (!SetObjectPropValue(strProcData,_T("BlowTime"),(L3SHORT)nBlowTime))
	{
		//if(nTrans > 0) Rollback(nTrans);
			return FALSE;
	}

	CString strArea = CurArea;
	strArea.Trim();
	if(strArea.IsEmpty() || (strArea !=_T("A") && strArea !=_T("B")))
	{
		return 0;
	}
	CString strAreaID = GetIdentity().ToCString() + strArea;
	CString strAreaURI = CL3NameParser::MergeClassDomainName(DES_AREA_CLASS_URI,strAreaID);

	CString csLanceNo = GetObjectPropValue(strAreaURI,_T("LanceNo")).ToCString();
	CString strLanceURI = CL3NameParser::MergeClassDomainName(CDES_LANCEDATA_URI,csLanceNo);

	L3LONG iBlowTime = GetObjectPropValue(strProcData,_T("BlowTime")).ToLong();
	if(!SetObjectPropValue(strLanceURI,_T("ProcessTime"),CL3Variant(GetObjectPropValue(strLanceURI,_T("ProcessTime")).ToLong()+(nBlowTime-iBlowTime)/60)))
	{
		//if(nTrans > 0)	Rollback(nTrans);
		return -5;
	}

	CString csMaterialID = MaterialID_DeSing;
	CString strBaseData = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,csMaterialID);
	if (!SetObjectPropValue(strBaseData,_T("Weight_MatTank"),CL3Variant(Weight_MatTank)))
	{
		//if(nTrans > 0) Rollback(nTrans);
			return FALSE;
	}
	if (!SetObjectPropValue(strBaseData,_T("Weight_SprayTank"),CL3Variant(Weight_SprayTank)))
	{
		//if(nTrans > 0) Rollback(nTrans);
			return FALSE;
	}


	CString csSQL;
	CString csTemp =_T(" SELECT sum(Mat_Consume) as Mat_Consume FROM %s WHERE MaterialID = '%s' ");
	csSQL.Format(csTemp,CDES_PROCESS_URI,csMaterialID);
	
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		//if(nTrans > 0)
		//	Rollback(nTrans);
		return FALSE;
	}

	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		L3FLOAT fMatConsume = rsResult.GetFieldByName(_T("Mat_Consume")).ToFloat();
		if (!SetObjectPropValue(strBaseData,_T("Mat_Consume"),CL3Variant(fMatConsume)))
		{
			//if(nTrans > 0) Rollback(nTrans);
				return FALSE;
		}
	}

	//if(nTrans > 0)
	//	Commit(nTrans);

	return TRUE;	
}

/// <Method class="CDeS_Unit_Mag" name="AcceptDeSRuntimeData" type="L3BOOL">
/// 接收DES喷吹实时数据 
/// <Param name="rsData" type="L3RECORDSET">实时数据</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::AcceptDeSRuntimeData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	CString cstrUnitID = GetIdentity().ToCString();
	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(CDES_RUNTIME_URI,rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	CString strMaterialID = MaterialID_DeSing;
	CString strTreatNo = TreatNo;

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("TreatNo"),CL3Variant(strTreatNo));
		rsTemp.SetFieldByName(_T("ID_Object"),CL3Variant(strMaterialID+strTreatNo));
		rsTemp.SetFieldByName(_T("Catch_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	CreateNewObjects(CDES_RUNTIME_URI,rsTemp);

	rs.MoveFirst();
	L3FLOAT ftemp =  rs.GetFieldByName(_T("Weight_MatTank")).ToFloat();
	Weight_MatTank = ftemp;
	ftemp = rs.GetFieldByName(_T("Weight_SprayTank")).ToFloat();
	Weight_SprayTank = ftemp;
	ftemp = rs.GetFieldByName(_T("Pressure")).ToFloat();
	Pressure = ftemp;
	ftemp = rs.GetFieldByName(_T("Flow")).ToFloat(); 
	Flow = ftemp;
	ftemp = rs.GetFieldByName(_T("Rate")).ToFloat(); 
	Rate = ftemp;

	return TRUE;	
}

/// <Method class="CDeS_Unit_Mag" name="SetLanceNo" type="L3LONG">
/// 换喷枪 
/// <Param name="strLanceNo" type="L3STRING">枪号</Param>
/// <Param name="strUnitID" type="L3STRING">工位</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::ChangeLanceNo(L3STRING strLanceNo,L3STRING strUnitID)
{
    if ((strLanceNo == NULL) || (strUnitID == NULL))
	{
		return -1;
	}

	CString csLanceNo = strLanceNo;
	CString csUnitID = strUnitID;
	if ((csUnitID != _T("A")) && (csUnitID != _T("B")))
	{
		return -2;
	}

	CString cstrUnitID = GetIdentity().ToCString();
	cstrUnitID += csUnitID;

	CString csUnitArea = CL3NameParser::MergeClassDomainName(DES_AREA_CLASS_URI,cstrUnitID);
	CString csCurLanceNo = GetObjectPropValue(csUnitArea,_T("LanceNo")).ToCString();
	if (csLanceNo.Trim() == csCurLanceNo.Trim())
	{
		return -3;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -4;
	}

	if(!SetObjectPropValue(csUnitArea,_T("LanceNo"),CL3Variant(csLanceNo)))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return -5;

	}

    if (AddNewLanceLogData(csLanceNo,_T("换枪")) != 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -6;
	}

	//Modify begin by llj 2011-04-12 更换喷枪的同时更换工位上的枪龄
	// 获取新枪号的枪龄
	CString csDesLanceDataURI = CL3NameParser::MergeClassDomainName(CDES_LANCEDATA_URI,csLanceNo);
	L3LONG dLanceAge=GetObjectPropValue(csDesLanceDataURI,_T("LanceAge")).ToLong();
	if(!SetObjectPropValue(csUnitArea,_T("LanceAge"),CL3Variant(dLanceAge)))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return -7;

	}

	//处理换枪时间
	COleDateTime dtCreateTime = COleDateTime::GetCurrentTime();
	if(!SetObjectPropValue(csDesLanceDataURI,_T("OpTime"),CL3Variant(dtCreateTime)))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return -8;

	}
	//Modify end
	if(nTrans > 0)
		Commit(nTrans);

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="ChangeMatCodeAndVendor" type="L3BOOL">
/// 更换脱硫剂
/// <Param name="MatCode" type="L3STRING">脱硫剂</Param>
/// <Param name="MatVendor" type="L3STRING">脱硫剂产家</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::ChangeMatCodeAndVendor(L3STRING MatCode,L3STRING MatVendor)
{
    if ((MatCode == NULL) || (MatVendor == NULL))
	{
		return FALSE;
	}

	CString csCurMatCode = Mat_Code;
	CString csMatCode = MatCode;
	CString csMatVendor = MatVendor;

	if (csCurMatCode.Trim() == csMatCode.Trim())
	{
		return FALSE;
	}

	Mat_Code = csCurMatCode;
    Mat_Vendor = csMatVendor;

	return TRUE;
}

/// <Method class="CDeS_Unit_Mag" name="IronsDeparture" type="L3BOOL">
/// 脱硫铁水离站
/// </Method>
L3LONG CDeS_Unit_Mag::IronsDeparture()
{
	CString csSQL;
	CString csTemp =_T(" SELECT MaterialID,Destination FROM %s WHERE (Status = %d) or (Status = %d)");
	csSQL.Format(csTemp,CDES_BASE_URI,CDeS_Base_Data::ironBeginRemoveSlag,CDeS_Base_Data::ironEndRemoveSlag);
	
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		return -1;
	}

	if(rsResult.GetRowCount() < 1)
	{
		return -2;
	}

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsDepart; pRS->QueryInterface(IID_IL3RecordSet,rsDepart); pRS->Release();
	rsDepart.AddField(_T("MaterialID"),VT_BSTR);
	rsDepart.AddField(_T("Destination"),VT_I2);

	rsResult.MoveFirst();
	while(!rsResult.IsEOF())
	{
		CString csMaterialID = (rsResult.GetFieldByName(_T("MaterialID"))).ToCString();

		if (csMaterialID.GetLength() < 9)
		{
			rsDepart.MoveNext();
			continue;
		}

		CString strDeSURI = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,csMaterialID);
		L3SHORT nStatus = (GetObjectPropValue(strDeSURI,_T("Status"))).ToShort();
		if ((nStatus != CDeS_Base_Data::ironEndRemoveSlag) && (nStatus != CDeS_Base_Data::ironBeginRemoveSlag))
		{
		    rsDepart.MoveNext();
			continue;
		}

		rsDepart.AppendRecord();
		rsDepart.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		CString csIronUri = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,csMaterialID);
		//L3SHORT nDestination = GetObjectPropValue(csIronUri,_T("Destination")).ToShort();
		L3SHORT nDestination = (rsResult.GetFieldByName(_T("Destination"))).ToShort();
		if (nDestination == 0)//未设置目的地
		{
			rsDepart.SetFieldByName(_T("Destination"),(L3SHORT)1);
		}
		else
		{
			rsDepart.SetFieldByName(_T("Destination"),(L3SHORT)nDestination);
		}
		rsResult.MoveNext();
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	rsDepart.MoveFirst();
	if(!SetObjsPropValues(CDES_BASE_URI,rsDepart))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return -7;
	}

	rsDepart.MoveFirst();

	rsDepart.AddField(_T("IronStatus"),VT_I4);
	rsDepart.AddField(_T("Source"),VT_I4);
	rsDepart.MoveFirst();
	while(!rsDepart.IsEOF())
	{
		rsDepart.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironDestDefined));
		rsDepart.SetFieldByName(_T("Source"),CL3Variant((LONG)1));
		rsDepart.MoveNext();
	}

	rsDepart.MoveFirst();
	if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rsDepart))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return -8;
	}


	CString cstrUnitID = GetIdentity().ToCString();
	if((cstrUnitID != _T("S02")) && (cstrUnitID != _T("S03")))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return -10;
	}

	//CString csUnitUri = _T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag\\");
 //   if(cstrUnitID == _T("S02"))
	//{
	//	csUnitUri += _T("S03");
	//}
	//else
	//{
	//	csUnitUri += _T("S02");
	//}

	//DeSStatus = CDeS_Base_Data::ironPrepare;
	//DeSStatusChanged_Time = COleDateTime::GetCurrentTime();

	//if(!SetObjectPropValue(csUnitUri,_T("DeSStatus"),(L3LONG)CDeS_Base_Data::ironDepart))
	//{
	//	if(nTrans > 0)
 //   		Rollback(nTrans);
	//	return -11;
	//}

	//if(!SetObjectPropValue(csUnitUri,_T("DeSStatusChanged_Time"),CL3Variant(COleDateTime::GetCurrentTime())))
	//{
	//	if(nTrans > 0)
 //   		Rollback(nTrans);
	//	return -12;
	//}

	if(nTrans > 0)
		Commit(nTrans);

	rsDepart.MoveFirst();
	while(!rsDepart.IsEOF())
	{
		CString csMaterialID = (rsDepart.GetFieldByName(_T("MaterialID"))).ToCString();

	    L3STRING bstrMaterialID = csMaterialID.AllocSysString();
		if (ChangeStatus(bstrMaterialID,CDeS_Base_Data::ironDepart,NULL) != 1)
		{
			L3SysFreeString(bstrMaterialID);
			return -6;
		}
		L3SysFreeString(bstrMaterialID);

	   rsDepart.MoveNext();
	}

	L3LONG EventIronChanged = (GetObjectPropValue(BFIronStore_URI,_T("EventIronChanged"))).ToLong();
	EventIronChanged *= -1;
	SetObjectPropValue(BFIronStore_URI,_T("EventIronChanged"),CL3Variant((LONG)EventIronChanged));


	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="ChangeTreatNo" type="L3BOOL">
/// 调整喷吹号
/// <Param name="strTreatNo" type="L3STRING">喷吹号</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::ChangeTreatNo(L3STRING strTreatNo)
{
    if (strTreatNo == NULL)
	{
		return FALSE;
	}

	CString csCurTreatNo = NextTreatNo;
	CString csTreatNo = strTreatNo;

	if (csCurTreatNo.Trim() == csTreatNo.Trim())
	{
		return FALSE;
	}

	NextTreatNo = strTreatNo;

	return TRUE;
}

/// <Method class="CDeS_Unit_Mag" name="AcceptDeSStatusData" type="L3BOOL">
/// 接收DES状态数据 
/// <Param name="rsData" type="L3RECORDSET">喷吹数据</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::AcceptDeSStatusData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveFirst();
	L3LONG DeSStatus = -1;
	DeSStatus = (rs.GetFieldByName(_T("DeSStatus"))).ToLong();
	switch(DeSStatus)
	{
		case CDeS_Base_Data::ironBeginSpray: 
			AcceptDeSBlowBeginData(rs);
		break;
		case CDeS_Base_Data::ironEndSpray: 
			AcceptDeSBlowEndData(rs);
		break;
		case CDeS_Base_Data::ironDepart: 
			AcceptDeSDepartData();
		break;
		case CDeS_Base_Data::ironArrived:
			AcceptDeSArrivalSignal();
		break;
		default:
			break;
	}
	return TRUE;	
}

/// <Method class="CDeS_Unit_Mag" name="LockData" type="L3SHORT">
/// 封锁实绩数据
/// <Param name="MaterialID" type="L3STRING">物料号</Param>
/// </Method>
L3SHORT CDeS_Unit_Mag::LockData(L3STRING MaterialID)
{
	if (MaterialID == NULL)
	{
		return -1;
	}

	CString csMaterialID = MaterialID;

    CString strDeSURI = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,csMaterialID);
	L3SHORT nStatus = GetObjectPropValue(strDeSURI,_T("Status")).ToShort();
	if (nStatus < CDeS_Base_Data::ironDepart)
	{
		return -2;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	if (!SetObjectPropValue(strDeSURI,_T("Locked"),(L3SHORT)1))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return 0;	
}


/// <Method class="CDeS_Unit_Mag" name="NewDeSAdditionData" type="L3LONG">
/// 记录脱硫剂上料数据
/// <Param name="rsMats" type="L3RECORDSET">脱硫剂</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::NewDeSAdditionData(L3RECORDSET rsMats)
{
	CL3RecordSetWrap rs = rsMats;
	if(rs.GetRowCount() < 1)
		return 0;
	
	// 检查数据有效性
	//2009-11-04 孙
	/*if(rs.GetFieldIndex(_T("MaterialID")) < 0)
	{
		return -1;
	}*/

	CL3RecordSetWrap rsDeSMat;
	if(!CreateClassPropSet(CDES_ADDITION_URI,rsDeSMat))
		return -2;
	rsDeSMat.DelField(_T("GUID"));
	rsDeSMat.CopyFrom(rs);
    
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	COleDateTime dtCreateTime = COleDateTime::GetCurrentTime();
   
//
	CString ssss = rsDeSMat.GetFieldByName(_T("Time_Begin_Discharge")).ToString();
CString sss = rsDeSMat.GetFieldByName(_T("Time_Stop_Discharge")).ToString();
	//


	CString cstrUnitID = GetIdentity().ToCString();

	rsDeSMat.MoveFirst();
	while(!rsDeSMat.IsEOF())
	{
		rsDeSMat.SetFieldByName(_T("UnitID"),CL3Variant(cstrUnitID));
		rsDeSMat.SetFieldByName(_T("Time_Discharge"),CL3Variant(dtCreateTime));
		rsDeSMat.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsDeSMat.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		CString csObj = GetName() + rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();
		CString csUri = CL3NameParser::MergeClassDomainName(UNIT_DUTY_CLASS_URI,csObj);
		rsDeSMat.SetFieldByName(_T("Operator"),GetObjectPropValue(csUri,_T("HeadFurnace")));

		rsDeSMat.MoveNext();
	}

	rsDeSMat.MoveFirst();

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	if(CreateNewObjects(CDES_ADDITION_URI,rsDeSMat) < rsDeSMat.GetRowCount())
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="SetDeSMode" type="L3BOOL">
/// 设置脱硫类型
/// <Param name="MaterialID" type="L3STRING">物料号</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::SetDeSMode(L3STRING MaterialID,L3SHORT DeSMode)
{
	if (MaterialID == NULL)
	{
		return FALSE;
	}

	CString csMaterialID = MaterialID;

    CString strDeSURI = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,csMaterialID);
	L3SHORT nStatus = GetObjectPropValue(strDeSURI,_T("Status")).ToShort();
	if (nStatus > CDeS_Base_Data::ironDepart)
	{
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	if (!SetObjectPropValue(strDeSURI,_T("DeSType"),(L3SHORT)DeSMode))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	CString csCurMaterialID = MaterialID_DeSing;
	if(csMaterialID == csCurMaterialID)
	{
		DeSType = (L3SHORT)DeSMode;
	}

    CString csBFIronUri = CL3NameParser::MergeClassDomainName(MATERIAL_BFIRON_URI,csMaterialID);
	if(!SetObjectPropValue(csBFIronUri,_T("DeSType"),(LONG)DeSMode))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CDeS_Unit_Mag" name="NewDeSEquipmentStatusData" type="L3LONG">
/// 记录脱硫设备状态变化数据
/// <Param name="nStatus" type="L3SHORT">设备状态</Param>
/// <Param name="strReason" type="L3STRING">设备状态变化原因</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::NewDeSEquipmentStatusData(L3SHORT nStatus,L3STRING strReason)
{
	if ((strReason == NULL) || (nStatus < 1))
		return 0;
	
	CL3RecordSetWrap rsDeSEquipment;
	if(!CreateClassPropSet(CDES_EQUIPMENT_URI,rsDeSEquipment))
		return -1;
	rsDeSEquipment.DelField(_T("GUID"));

    COleDateTime dtCreateTime = COleDateTime::GetCurrentTime();

	CString cstrUnitID = GetIdentity().ToCString();
	//2009-11-03 sun begin
	L3SHORT nUnitID = 0;
	if(cstrUnitID == _T("S02"))
		nUnitID = 1;
	else if(cstrUnitID == _T("S03"))
		nUnitID = 2;
	else
	{
		nUnitID = 0;
		return -3;
	}
	//2009-11-03 sun end
	rsDeSEquipment.MoveFirst();
	rsDeSEquipment.AppendRecord();
    rsDeSEquipment.SetFieldByName(_T("DeSID"),(L3SHORT)nUnitID);//2009-11-03 sun
	rsDeSEquipment.SetFieldByName(_T("Log_Time"),CL3Variant(dtCreateTime));
	rsDeSEquipment.SetFieldByName(_T("Status"),(L3SHORT)nStatus);
	rsDeSEquipment.SetFieldByName(_T("Reason"),strReason);

	rsDeSEquipment.MoveFirst();

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	if(CreateNewObjects(CDES_EQUIPMENT_URI,rsDeSEquipment) < rsDeSEquipment.GetRowCount())
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}

	//Equipment_Status = (L3SHORT)nStatus;
	//2009-11-03 sun begin
	CString csUnitUri = CL3NameParser::MergeClassDomainName(DES_CLASS_URI,cstrUnitID);
	if (!SetObjectPropValue(csUnitUri,_T("Equipment_Status"),(L3SHORT)nStatus))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -5;
	}
	//2009-11-03 sun end
	if(nTrans > 0)
		Commit(nTrans);
	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="IsOverForPreStatus" type="L3BOOL">
/// 判定前一状态是否结束 
/// <Param name="MaterialID" type="LPCTSTR">铁水</Param>
/// <Param name="nStatus" type="LPCTSTR">当前状态</Param>
/// <Param name="AreaID" type="CString">前结束状态</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::IsOverForPreStatus(LPCTSTR MaterialID,L3SHORT nStatus,L3SHORT & nEndStatu,CString & AreaID)
{
    AreaID = _T("");
	CString csMaterialID = MaterialID;
	if(csMaterialID.GetLength() < 10)
		return TRUE;

	nEndStatu = -1;
	L3SHORT npreStatus = -1;
	switch (nStatus)
	{
	case CDeS_Base_Data::ironBeginPreRemoveSlag://预捞渣开始
			npreStatus = CDeS_Base_Data::ironArrived;
			break;
	case CDeS_Base_Data::ironBeginSpray://喷吹开始
				npreStatus = CDeS_Base_Data::ironBeginPreRemoveSlag;
			break;
	case CDeS_Base_Data::ironBeginRemoveSlag://捞渣开始
			npreStatus = CDeS_Base_Data::ironBeginSpray;
			break;
	case CDeS_Base_Data::ironDepart://离站
				npreStatus = CDeS_Base_Data::ironBeginRemoveSlag;
			break;
		default:
			break;
	}

	if(npreStatus == -1)
		return TRUE;

	CString csSQL;
	CString csTemp =_T(" SELECT ID_Object,AreaID FROM %s WHERE ID_Object = '%s' and Status = %d order by Change_Time desc");
	csSQL.Format(csTemp,CDES_STATUS_URI,csMaterialID,npreStatus);
	
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		return TRUE;
	}

	if(rsResult.GetRowCount() < 1)
	{
		//2009-11-25 begin
		if(nStatus == CDeS_Base_Data::ironBeginRemoveSlag)
		{
			CString csDeSIronUri = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,csMaterialID);
			//2009-12-02 sun begin
			////MaterialID_DeSing = csMaterialID;
			////MaterialID_DeSed = csMaterialID;
			CString csDeSUnitID = GetIdentity().ToCString();
			CString csDeSUnit = GetObjectPropValue(csDeSIronUri,_T("DeS_UnitID")).ToString();
			if(csDeSUnit.GetLength() < 1)
			{
				SetObjectPropValue(csDeSIronUri,_T("DeS_UnitID"),CL3Variant(csDeSUnitID));
			}
			//2009-12-02 sun end
			L3SHORT nDeSType = GetObjectPropValue(csDeSIronUri,_T("DeSType")).ToLong();
			DeSType = nDeSType;
		}
				   //2009-11-25 End
					return TRUE;
	}

	rsResult.MoveFirst();
	CString cstrAreaID = rsResult.GetFieldByName(_T("AreaID")).ToCString();

	L3SHORT naddStatus = -1;
	switch (nStatus)
	{
	case CDeS_Base_Data::ironBeginPreRemoveSlag://预捞渣开始
			naddStatus = CDeS_Base_Data::ironArrived;
			break;
	case CDeS_Base_Data::ironBeginSpray://喷吹开始
				naddStatus = CDeS_Base_Data::ironEndPreRemoveSlag;
			break;
	case CDeS_Base_Data::ironBeginRemoveSlag://捞渣开始
			naddStatus = CDeS_Base_Data::ironEndSpray;
			break;
	case CDeS_Base_Data::ironDepart://离站
				naddStatus = CDeS_Base_Data::ironEndRemoveSlag;
			break;
		default:
			break;
	}

	csTemp =_T(" SELECT ID_Object FROM %s WHERE ID_Object = '%s' and Status = '%d'");
	csSQL.Format(csTemp,CDES_STATUS_URI,csMaterialID,naddStatus);
	
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		return TRUE;
	}

	if(rsResult.GetRowCount() < 1)
	{
		nEndStatu = naddStatus;
		AreaID = cstrAreaID.Right(1);
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CDeS_Unit_Mag" name="AcceptDeSDepartData" type="L3BOOL">
/// 接受现场离站信号 
/// </Method>
L3BOOL CDeS_Unit_Mag::AcceptDeSDepartData()
{
	CString cstrUnitID = GetIdentity().ToCString();
	if((cstrUnitID != _T("S02")) && (cstrUnitID != _T("S03")))
	{
		return TRUE;
	}

	CString csUnitUri = _T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag\\");
    if(cstrUnitID == _T("S02"))
	{
		csUnitUri += _T("S03");
	}
	else
	{
		csUnitUri += _T("S02");
	}

	//LONG nTrans = 0;
	//if(!IsInTrans())
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return FALSE;
	//}

	DeSStatus = CDeS_Base_Data::ironDepart;
	DeSStatusChanged_Time = COleDateTime::GetCurrentTime();
	Weight_MatTank = 0;
	Weight_SprayTank = 0;
	Pressure = 0;
	Flow = 0;
	Rate = 0;

	CString cstrAreaA = GetIdentity().ToCString() + _T("A");
    CString cstrAreaB = GetIdentity().ToCString() + _T("B");
	CString csAreaAUri = CL3NameParser::MergeClassDomainName(DES_AREA_CLASS_URI,cstrAreaA);
	CString csAreaBUri = CL3NameParser::MergeClassDomainName(DES_AREA_CLASS_URI,cstrAreaB);

	SetObjectPropValue(csAreaAUri,_T("TAP_No"),CL3Variant(_T("")));
	SetObjectPropValue(csAreaBUri,_T("TAP_No"),CL3Variant(_T("")));
	SetObjectPropValue(csAreaAUri,_T("TPC_No"),CL3Variant(_T("")));
	SetObjectPropValue(csAreaBUri,_T("TPC_No"),CL3Variant(_T("")));
	SetObjectPropValue(csAreaAUri,_T("BlowTime"),CL3Variant(0));
	SetObjectPropValue(csAreaBUri,_T("BlowTime"),CL3Variant(0));
	SetObjectPropValue(csAreaAUri,_T("S"),CL3Variant(0));
	SetObjectPropValue(csAreaBUri,_T("S"),CL3Variant(0));
	SetObjectPropValue(csAreaAUri,_T("Weight"),CL3Variant(0));
	SetObjectPropValue(csAreaBUri,_T("Weight"),CL3Variant(0));


	if(!SetObjectPropValue(csUnitUri,_T("DeSStatusChanged_Time"),CL3Variant(COleDateTime::GetCurrentTime())))
	{
		//if(nTrans > 0)
  //  		Rollback(nTrans);
		return FALSE;
	}

	//if(nTrans > 0)
	//	Commit(nTrans);

	return TRUE;


}

/// <Method class="CDeS_Unit_Mag" name="AddNewLanceData" type="L3LONG">
/// 新增喷枪数据
/// <Param name="rsIrons" type="L3RECORDSET">喷枪数据</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::AddNewLanceData(L3RECORDSET rsLance)
{
	CL3RecordSetWrap rs = rsLance;
	if(rs.GetRowCount() < 1)
		return 0;
	
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("LanceNo")) < 0)
	{
		return -1;
	}

	CL3RecordSetWrap rsLanceData;
	if(!CreateClassPropSet(CDES_LANCEDATA_URI,rsLanceData))
		return -2;
	rsLanceData.DelField(_T("GUID"));
	rsLanceData.CopyFrom(rs);

	CL3RecordSetWrap rsLanceLog;
	if(!CreateClassPropSet(CDES_LANCELOG_URI,rsLanceLog))
		return -2;
	rsLanceLog.DelField(_T("GUID"));
	rsLanceLog.CopyFrom(rs);


	rsLanceData.MoveFirst();
	while(!rsLanceData.IsEOF())
	{
		CString csLanceNo = rsLanceData.GetFieldByName(_T("LanceNo")).ToCString();
		if(csLanceNo.GetLength() != 7&&csLanceNo.GetLength() != 6)
		{
			return -4;
		}

		rsLanceData.SetFieldByName(_T("Status"),(L3LONG)CDeS_Lance_Data::lancePrepare);
		rsLanceData.SetFieldByName(_T("LanceAge"),(L3LONG)0);
		rsLanceData.SetFieldByName(_T("ProcessTime"),(L3LONG)0);
		rsLanceData.SetFieldByName(_T("ProcessAmount"),(L3LONG)0);
		//Modify begin by llj 2011-03-30 调整枪编号增加枪的记录时间
		rsLanceData.SetFieldByName(_T("OpTime"),CL3Variant(COleDateTime::GetCurrentTime()));
		//Modify end
		rsLanceData.MoveNext();
	}

	rsLanceData.MoveFirst();

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	if(CreateNewObjects(CDES_LANCEDATA_URI,rsLanceData) < rsLanceData.GetRowCount())
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -5;
	}

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	rsLanceLog.MoveFirst();
	while(!rsLanceLog.IsEOF())
	{
		rsLanceLog.SetFieldByName(_T("Status"),(L3LONG)CDeS_Lance_Data::lanceOffline);
		rsLanceLog.SetFieldByName(_T("LanceAge"),(L3LONG)0);
		rsLanceLog.SetFieldByName(_T("ProcessTime"),(L3LONG)0);
		rsLanceLog.SetFieldByName(_T("ProcessAmount"),(L3LONG)0);
		rsLanceLog.SetFieldByName(_T("Action"),CL3Variant(_T("新增喷枪")));
		rsLanceLog.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsLanceLog.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		CString csObj = GetName() + rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();
		CString csUri = CL3NameParser::MergeClassDomainName(UNIT_DUTY_CLASS_URI,csObj);
		rsLanceLog.SetFieldByName(_T("Operator"),GetObjectPropValue(csUri,_T("HeadFurnace")));
		rsLanceLog.SetFieldByName(_T("Time_Change"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsLanceLog.MoveNext();
	}

	rsLanceLog.MoveFirst();
	if(CreateNewObjects(CDES_LANCELOG_URI,rsLanceLog) < rsLanceLog.GetRowCount())
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -6;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="ChangeLanceStatus" type="L3LONG">
/// 改变喷枪状态
/// <Param name="rsIrons" type="L3RECORDSET">喷枪数据[喷枪号/状态]</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::ChangeLanceStatus(L3RECORDSET rsLance)
{
	CL3RecordSetWrap rs = rsLance;
	if(rs.GetRowCount() < 1)
		return 0;
	
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("LanceNo")) < 0)
	{
		return -1;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csLanceNo = rs.GetFieldByName(_T("LanceNo")).ToCString();

		L3LONG ncurLanceStatus = rs.GetFieldByName(_T("Status")).ToLong();

		CString csLanceUri = CL3NameParser::MergeClassDomainName(CDES_LANCEDATA_URI,csLanceNo);
		L3LONG npreLanceStatus = GetObjectPropValue(csLanceUri,_T("Status")).ToLong();
		//2009-11-06 sun lanceMaintain 改为 lanceOffline
		if((npreLanceStatus < CDeS_Lance_Data::lancePrepare) || (npreLanceStatus > CDeS_Lance_Data::lanceDeleted))
		{
			if(nTrans > 0)
				Rollback(nTrans);
				return -4;
		}

		if(npreLanceStatus == ncurLanceStatus)
		{
			if(nTrans > 0)
				Rollback(nTrans);
				return -5;
		}

        if (AddNewLanceLogData(csLanceNo,_T("状态变化")) != 1)
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -6;
		}

		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!SetObjsPropValues(CDES_LANCEDATA_URI,rs))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -6;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="ChangeLanceAge" type="L3LONG">
/// 改变喷枪状态
/// <Param name="rsIrons" type="L3RECORDSET">喷枪数据[喷枪号/枪龄]</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::ChangeLanceAge(L3RECORDSET rsLance)
{
	CL3RecordSetWrap rs = rsLance;
	if(rs.GetRowCount() < 1)
		return 0;
	
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("LanceNo")) < 0)
	{
		return -1;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csLanceNo = rs.GetFieldByName(_T("LanceNo")).ToCString();
		CString csLanceUri = CL3NameParser::MergeClassDomainName(CDES_LANCEDATA_URI,csLanceNo);

        if (AddNewLanceLogData(csLanceNo,_T("枪龄变化")) != 1)
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -4;
		}
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!SetObjsPropValues(CDES_LANCEDATA_URI,rs))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -5;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return 1;
}


/// <Method class="CDeS_Unit_Mag" name="AddNewLanceLogData" type="L3LONG">
/// 新增喷枪日志
/// <Param name="strLanceNo" type="LPCTSTR">喷枪号</Param>
/// <Param name="strNote" type="LPCTSTR">日志</Param>
/// </Method>
L3LONG CDeS_Unit_Mag::AddNewLanceLogData(LPCTSTR strLanceNo,LPCTSTR strNote)
{
	CString csLanceNo = strLanceNo;
	CString csNote = strNote;

	CL3RecordSetWrap rsLanceLog;
	if(!CreateClassPropSet(CDES_LANCELOG_URI,rsLanceLog))
		return -1;
	rsLanceLog.DelField(_T("GUID"));

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	CString csLanceUri = CL3NameParser::MergeClassDomainName(CDES_LANCEDATA_URI,csLanceNo);

	rsLanceLog.AppendRecord();
	rsLanceLog.SetFieldByName(_T("LanceNo"),CL3Variant(csLanceNo));
	rsLanceLog.SetFieldByName(_T("Status"),GetObjectPropValue(csLanceUri,_T("Status")));
	rsLanceLog.SetFieldByName(_T("LanceAge"),GetObjectPropValue(csLanceUri,_T("LanceAge")));
	rsLanceLog.SetFieldByName(_T("LanceVendor"),GetObjectPropValue(csLanceUri,_T("LanceVendor")));
	rsLanceLog.SetFieldByName(_T("ProcessTime"),GetObjectPropValue(csLanceUri,_T("ProcessTime")));
	rsLanceLog.SetFieldByName(_T("ProcessAmount"),GetObjectPropValue(csLanceUri,_T("ProcessAmount")));
	rsLanceLog.SetFieldByName(_T("Note"),GetObjectPropValue(csLanceUri,_T("Note")));
	rsLanceLog.SetFieldByName(_T("Time_Change"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsLanceLog.SetFieldByName(_T("Action"),CL3Variant(csNote));
	rsLanceLog.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
	rsLanceLog.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	CString csObj = GetName() + rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(UNIT_DUTY_CLASS_URI,csObj);
	rsLanceLog.SetFieldByName(_T("Operator"),GetObjectPropValue(csUri,_T("HeadFurnace")));

	rsLanceLog.MoveFirst();
	if(CreateNewObjects(CDES_LANCELOG_URI,rsLanceLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -3;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="PrepareIronLadle" type="L3LONG">
/// 准备即将到达的铁水。
/// </Method>
L3LONG CDeS_Unit_Mag::PrepareIronLadle()
{
	CString cstrUnitID = GetIdentity().ToCString();
	if((cstrUnitID != _T("S02")) && (cstrUnitID != _T("S03")))
	{
		return -1;
	}

	CString csUnitUri = _T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag\\");
    if(cstrUnitID == _T("S02"))
	{
		csUnitUri += _T("S03");
	}
	else
	{
		csUnitUri += _T("S02");
	}

	DeSStatus = CDeS_Base_Data::ironPrepare;
	DeSStatusChanged_Time = COleDateTime::GetCurrentTime();

	//LONG nTrans = 0;
	//if(!IsInTrans())
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return -2;
	//}

	if(!SetObjectPropValue(csUnitUri,_T("DeSStatus"),(L3LONG)CDeS_Base_Data::ironArrived))
	{
		//if(nTrans > 0)
  //  		Rollback(nTrans);
		return -3;
	}

	if(!SetObjectPropValue(csUnitUri,_T("DeSStatusChanged_Time"),CL3Variant(COleDateTime::GetCurrentTime())))
	{
		//if(nTrans > 0)
  //  		Rollback(nTrans);
		return -4;
	}

	//if(nTrans > 0)
	//	Commit(nTrans);

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="AcceptDeSArrivalSignal" type="L3LONG">
/// 铁水进站
/// </Method>
L3LONG CDeS_Unit_Mag::AcceptDeSArrivalSignal()
{

	L3LONG nDeSStatus = DeSStatus;
	//if (nDeSStatus != CDeS_Base_Data::ironPrepare)
	//{
	//	return 0;
	//}

	CString cstrUnitID = GetIdentity().ToCString();
	if((cstrUnitID != _T("S02")) && (cstrUnitID != _T("S03")))
	{
		return -1;
	}

	CString csUnitUri = _T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag\\");
    if(cstrUnitID == _T("S02"))
	{
		csUnitUri += _T("S03");
	}
	else
	{
		csUnitUri += _T("S02");
	}
	//LONG nTrans = 0;
	//if(!IsInTrans())
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return -2;
	//}

	DeSStatus = CDeS_Base_Data::ironArrived;
	DeSStatusChanged_Time = COleDateTime::GetCurrentTime();

	if(!SetObjectPropValue(csUnitUri,_T("DeSStatus"),(L3LONG)CDeS_Base_Data::ironArrived))
	{
		//if(nTrans > 0)
  //  		Rollback(nTrans);
		return -3;
	}

	if(!SetObjectPropValue(csUnitUri,_T("DeSStatusChanged_Time"),CL3Variant(COleDateTime::GetCurrentTime())))
	{
		//if(nTrans > 0)
  //  		Rollback(nTrans);
		return -4;
	}

	//if(nTrans > 0)
	//	Commit(nTrans);

	return 1;
}

/// <Method class="CDeS_Unit_Mag" name="GenerateLanceNo" type="L3STRING">
/// 产生喷枪号
/// </Method>
L3STRING CDeS_Unit_Mag::GenerateLanceNo()
{

	COleDateTime curTime = COleDateTime::GetCurrentTime();
	LONG nYear = curTime.GetYear();
	nYear = nYear - (nYear / 100) * 100;
	//Modify begin by llj 2011-03-30 调整喷枪枪号（年号后两位-3位枪号）
	//屏蔽原语句
	/*LONG nMonth = curTime.GetMonth();

	CString csLanceNo;
	csLanceNo.Format(_T("%02d%02d"),nYear,nMonth);

	L3LONG maxLanceNo = 0;
	CString csSQL;
	CString csTemp =_T(" SELECT Max(substr(LanceNo,6,2)) as maxLanceNo FROM %s WHERE substr (LanceNo,1,4) = '%s' and Status <>'%d'");
	csSQL.Format(csTemp,CDES_LANCEDATA_URI,csLanceNo,CDeS_Lance_Data::lanceDeleted);*/
	
	CString csLanceNo;
	csLanceNo.Format(_T("%02d"),nYear);

	L3LONG maxLanceNo = 0;
	CString csSQL;
	CString csTemp =_T(" SELECT Max(substr(LanceNo,4,3)) as maxLanceNo FROM %s WHERE substr (LanceNo,1,3) = '%s-'");
	csSQL.Format(csTemp,CDES_LANCEDATA_URI,csLanceNo);
	//Modify end
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		return NULL;
	}

	if(rsResult.GetRowCount() < 1)
	{
		maxLanceNo = 1;
	}
	else
	{
		rsResult.MoveFirst();
		maxLanceNo = rsResult.GetFieldByName(_T("maxLanceNo")).ToLong();
		maxLanceNo ++;
	}
	//Modify begin by llj 2011-03-30 调整喷枪枪号（年号后两位-3位枪号）
	//屏蔽原语句
	//csLanceNo.Format(_T("%02d%02d-%02d"),nYear,nMonth,maxLanceNo);
	csLanceNo.Format(_T("%02d-%03d"),nYear,maxLanceNo);
	//Modify end
	return csLanceNo.AllocSysString();
}

/// <Method class="CDeS_Unit_Mag" name="GetUnArrivedIrons" type="L3RECORDSET">
/// 返回已指定去向，但未到达确认的铁水数据。
/// </Method>
L3RECORDSET CDeS_Unit_Mag::GetUnArrivedIrons()
{
	CString strSQL;
	strSQL.Format(_T("select * from %s where Status != %d and IronStatus <= %d and DeSFlag = 0")
		,MATERIAL_BFIRON_URI,(LONG)Material::Deleted,(INT)CBFIron::ironDestDefined);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	//{
	//	CL3RecordSetWrap rsRet;
	//	CreateClassPropSet(MATERIAL_BFIRON_URI,rsRet);
	//	rs.MoveFirst();
	//	rsRet.CopyFrom(rs);
	//	return rsRet.Detach();
	//}
	return rs.Detach();
}

/// <Method class="CDeS_Unit_Mag" name="GetUnitForEndStatus" type="L3BOOL">
/// 在状态结束时获取对应开始状态的工位 
/// <Param name="MaterialID" type="LPCTSTR">铁水</Param>
/// <Param name="nStatus" type="LPCTSTR">当前状态</Param>
/// <Param name="AreaID" type="CString">工位</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::GetUnitForEndStatus(LPCTSTR MaterialID,L3SHORT nStatus,CString & AreaID)
{
    AreaID = _T("");
	CString csMaterialID = MaterialID;
	if(csMaterialID.GetLength() < 10)
		return FALSE;

	L3SHORT npreStatus = -1;
	switch (nStatus)
	{
	case CDeS_Base_Data::ironEndPreRemoveSlag://预捞渣结束
		    npreStatus = CDeS_Base_Data::ironBeginPreRemoveSlag;
			break;
	case CDeS_Base_Data::ironEndSpray://喷吹开始
			npreStatus = CDeS_Base_Data::ironBeginSpray;
			break;
	case CDeS_Base_Data::ironEndRemoveSlag://捞渣开始
			npreStatus = CDeS_Base_Data::ironBeginRemoveSlag;
			break;
		default:
			break;
	}

	if(npreStatus == -1)
		return FALSE;

	CString csSQL;
	CString csTemp =_T(" SELECT ID_Object,AreaID FROM %s WHERE ID_Object = '%s' and Status = %d order by Change_Time desc");
	csSQL.Format(csTemp,CDES_STATUS_URI,csMaterialID,npreStatus);
	
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		return FALSE;
	}

	if(rsResult.GetRowCount() < 1)
	{
		return FALSE;
	}

	rsResult.MoveFirst();
	CString cstrAreaID = rsResult.GetFieldByName(_T("AreaID")).ToCString();
	AreaID = cstrAreaID.Right(1);

	return TRUE;	
}

/// <Method class="CDeS_Unit_Mag" name="SetDeSIronPath" type="L3BOOL">
/// 设置目的地
/// <Param name="MaterialID" type="L3STRING">物料号</Param>
/// <Param name="nPath" type="L3SHORT">目的地</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::SetDeSIronPath(L3STRING MaterialID,L3SHORT nPath)
{
	if (MaterialID == NULL)
	{
		return FALSE;
	}

	CString csMaterialID = MaterialID;

    CString strDeSURI = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,csMaterialID);
	L3SHORT nStatus = GetObjectPropValue(strDeSURI,_T("Status")).ToShort();
	if (nStatus > CDeS_Base_Data::ironDepart)
	{
		return FALSE;
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	if (!SetObjectPropValue(strDeSURI,_T("Destination"),(L3SHORT)nPath))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;	
}

/// <Method class="CDeS_Unit_Mag" name="BeginRemoveSlag" type="L3BOOL">
/// 捞渣开始更改物料标识
/// <Param name="strIron" type="CString">铁水(铁次+罐号)</Param>
/// </Method>
//L3BOOL CDeS_Unit_Mag::BeginRemoveSlag(CString strIron,L3SHORT nDeSType)
//{
//	if(strIron.GetLength() < 10) return FALSE;
//
//	MaterialID_DeSing = strIron;
//	MaterialID_DeSed = strIron;
//
//	DeSType = nDeSType;
//	//CString csDeSAreaUri = CL3NameParser::MergeClassDomainName(DES_AREA_CLASS_URI,strAreaID);
//	//SetObjectPropValue(csDeSAreaUri,_T("TAP_No"),CL3Variant(strIron.Left(9)));
//	//SetObjectPropValue(csDeSAreaUri,_T("TPC_No"),CL3Variant(strIron.Right(2)));
//	//L3LONG flagDes = GetObjectPropValue(csDeSIronUri,_T("DeS_Flag")).ToLong();
//	//if(flagDeS != 1)
//	//{
//	//	SetObjectPropValue(csDeSAreaUri,_T("BlowTime"),(L3LONG)0);
//	//}
//	//SetObjectPropValue(csDeSAreaUri,_T("BlowTime"),(L3LONG)0);
//
//	return TRUE;
//}

/// <Method class="CDeS_Unit_Mag" name="BeginRemoveSlagNoDeS" type="L3BOOL">
/// 判定前一状态是否结束 
/// <Param name="MaterialID" type="LPCTSTR">铁水</Param>
/// <Param name="AreaID" type="LPCTSTR">当前工位</Param>
/// <Param name="nStatus" type="L3SHORT">当前状态</Param>
/// <Param name="nDeSType" type="L3SHORT">脱硫类型</Param>
/// </Method>
L3BOOL CDeS_Unit_Mag::BeginRemoveSlagNoDeS(LPCTSTR MaterialID,LPCTSTR AreaID,L3SHORT nStatus,L3SHORT nDeSType)
{
    CString csAreaID = AreaID;
	CString csMaterialID = MaterialID;
	if(csMaterialID.GetLength() < 10)
		return FALSE;

	L3SHORT npreStatus = -1;
	switch (nStatus)
	{
	case CDeS_Base_Data::ironBeginRemoveSlag://捞渣开始
			npreStatus = CDeS_Base_Data::ironBeginSpray;
			break;
		default:
			break;
	}

	if(npreStatus == -1)
		return FALSE;

	CString csSQL;
	CString csTemp =_T(" SELECT ID_Object,AreaID FROM %s WHERE ID_Object = '%s' and Status = %d order by Change_Time desc");
	csSQL.Format(csTemp,CDES_STATUS_URI,csMaterialID,npreStatus);
	
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		return FALSE;
	}

	/*if(rsResult.GetRowCount() < 1)
	{*/
		//2009-11-25 begin
		if(nStatus == CDeS_Base_Data::ironBeginRemoveSlag)
		{
            CString csBFUri = CL3NameParser::MergeClassDomainName(MATERIAL_BFIRON_URI,csMaterialID);
			L3FLOAT fS = GetObjectPropValue(csBFUri,_T("S_B")).ToFloat();
			MaterialID_DeSing = csMaterialID;
			MaterialID_DeSed = csMaterialID;
			DeSType = nDeSType;
			CurArea = csAreaID;
			CString strAreaID = GetIdentity().ToCString() + csAreaID;
            CString csDeSAreaUri = CL3NameParser::MergeClassDomainName(DES_AREA_CLASS_URI,strAreaID);
			SetObjectPropValue(csDeSAreaUri,_T("S"),CL3Variant(fS));
			SetObjectPropValue(csDeSAreaUri,_T("BlowTime"),CL3Variant(0));
			SetObjectPropValue(csDeSAreaUri,_T("TAP_No"),CL3Variant(csMaterialID.Left(9)));
			SetObjectPropValue(csDeSAreaUri,_T("TPC_No"),CL3Variant(csMaterialID.Right(2)));
		}
	    //2009-11-25 End
	//}
	return TRUE;	
}


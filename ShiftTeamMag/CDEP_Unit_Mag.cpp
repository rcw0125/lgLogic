// 逻辑类CDEP_Unit_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CDEP_Unit_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CDEP_Unit_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CDEP_Unit_Mag.h"
#include "L3NameParser.h"

#define BLOWTIMER_PERIOD		5000
#define BLOWTIME		5
L3SHORT  count1=0 ;

//当对象被装载到系统中时，被调用
void CDEP_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CDEP_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 返回机组的加工区域
/// ARG << lstURIs : 接收所有加工区对象的URI
/// </summary>
BOOL CDEP_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	CString strURI;
	strURI.Format(_T("XGMESLogic\\DePMag\\CDEP_Prod_Area\\%s"),GetIdentity().ToCString());
	lstURIs.AddHead(strURI);
	return TRUE;
}

/// <summary>
/// 得到机组前序材料缓冲区的URI
/// </summary>
CString CDEP_Unit_Mag::GetInputCache()
{

	CString strURI;

	strURI=_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S91P01");
	return strURI;

	/*return MIXFProduceCache_URI;*/
	
}

/// <summary>
/// 得到机组后继材料缓冲区的URI
/// </summary>
CString CDEP_Unit_Mag::GetOutputCache()
{
	CString strURI;

	strURI=_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S25P01");
	return strURI;
}

/// <summary>
/// 机组上料前预处理。在机组上料前调用，继承类可重载此方法进行预先数据准备和处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 返回TRUE继续上料；返回FALSE中断上料。
/// </summary>
BOOL CDEP_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// 机组上料后续处理。在机组上料后调用，继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDEP_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// 返回机组上料记录的类型URI
/// </summary>
CString CDEP_Unit_Mag::GetFeedingLogType()
{
	return _T("");
}


/// <summary>
/// 准备上料记录数据。继承类可重载此函数进行额外的数据处理。
/// ARG >> rsFeedingLogs : 上料记录信息。
/// RET << void
/// </summary>
void CDEP_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
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
BOOL CDEP_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
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
BOOL CDEP_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// 下线前预处理。在执行下线操作前调用，继承类可重载此函数进行预先的数据准备和处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 返回TRUE继续下线；返回FALSE中断下线。
/// </summary>
BOOL CDEP_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// 下线后续处理。在执行下线操作后调用，继承类可重载此函数进行额外处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDEP_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsDelivered( rsMaterialInfo);
}


/// <summary>
/// 返回机组产出记录的类型URI
/// </summary>
CString CDEP_Unit_Mag::GetDeliveryLogType()
{
	return _T("");
}


/// <summary>
/// 准备下料记录数据。
/// ARG >> rsDeliveryLog : 下料记录数据。
/// RET <<void
/// </summary>
void CDEP_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// 返回本机组的通讯器对象的URI
/// </summary>
CString CDEP_Unit_Mag::GetCommunicator()
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
BOOL CDEP_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// 计划下达后续处理。在向下位系统发送计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsSend : 下发下位系统的计划数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDEP_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
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
BOOL CDEP_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// 计划取消后续处理。在向下位系统发送取消计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsCancel : 下发下位系统的计划取消数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDEP_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// 处理材料上线的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDEP_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// 处理材料进入加工区域的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDEP_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// 处理材料离开加工区域事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDEP_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// 处理材料生产完毕事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDEP_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// 处理机组测量数据变更事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CDEP_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}


/// 计算下一炉号
CString CDEP_Unit_Mag::CalculateNextHeatID (LPCTSTR lpcszHeatID)
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




/// 通用DEP过程状态修改函数   1更改状态 2.记录状态日志
BOOL CDEP_Unit_Mag::ChangeDEPStatus(LONG nStatus)
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	//2016-1-13 修改
	if(nStatus!=13)
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
	if(!CreateClassPropSet( _T("XGMESLogic\\DePMag\\CDEP_Process_Status"),rsStatus))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsStatus.AppendRecord();
	rsStatus.SetFieldByName(_T("HeatID"),GetPropValue(_T("HeatID")));
	rsStatus.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsStatus.SetFieldByName(_T("Change_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	if(CreateNewObjects( _T("XGMESLogic\\DePMag\\CDEP_Process_Status"),rsStatus) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}


	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}



///2009-02-28
/// </Method>  指定铁包，生成base process 
L3LONG CDEP_Unit_Mag::IronLadleToDEP(L3RECORDSET rsIrons)
{
	CL3RecordSetWrap rsIron = rsIrons;
	if(rsIron.GetRowCount() < 1)
		return -1;
	// 检查数据
	if(rsIron.GetFieldIndex(_T("MaterialID")) < 0 )
		return -2;

	// 检查当前DEP状态,出钢结束以前都可以指定主原料
	if(Status != CDEP_Unit_Mag::DEPWaiting)
		return -6;


	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -7;
	}

	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -8;
	}

	//获取炉号

	CString strHeatID = NextHeatID;
	// 炉号变更
	HeatID = NextHeatID;
	//产生下一炉号2009-03-26 tangyi兑铁时计算下一炉号，用于计量，但不从计划中获取
	NextHeatID = CalculateNextHeatID(strHeatID);
	// 产生DEP炉次原料数据CDEP_Feed_Data
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
      rsIronsDesignated.MoveFirst();
		CString strLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,rsIronsDesignated.GetFieldByName(_T("IronLadleNo")).ToCString());
		SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT));	

	// 检查DEP生产区是否已存在铁水
   //   CL3Variant val = InvokeObjectMethod(_T("S91"),_T("GetMaterialCount"),_T("CIron_Data"));
	//if(!val.IsValid())
	//{
	//	if(nTrans > 0) Rollback(nTrans);
	//	return -11;
	//}
	//if(val.ToLong() > 0)//2008-12-29 确保只有一炉钢水tangyi
	//{
	//	if(nTrans > 0) Rollback(nTrans);
	//	
	//	return -12;
	//}
	// 将铁水上线，移入DEP生产区
	//FeedMaterials方法需跟踪研究
	rsIronsDesignated.MoveFirst();
	if(!FeedMaterials(rsIronsDesignated))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -13;
	}
   


	rsIronsDesignated.MoveFirst();
	CL3RecordSetWrap rsFeedData;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Feed_Data"),rsFeedData))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -16;
	}
	rsIron.MoveFirst();
	IronLadle=rsIron.GetFieldByName(_T("MaterialID")).ToString();
	rsFeedData.CopyFrom(rsIronsDesignated);
	rsFeedData.MoveFirst();
	rsFeedData.SetFieldByName(_T("MaterialID"),CL3Variant(IronLadle));
    rsFeedData.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Feed_Data"),rsFeedData) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -17;
	}

	Load=rsIron.GetFieldByName(_T("Weight")).ToDouble();
	CurTemp=rsIron.GetFieldByName(_T("IronTemp")).ToDouble();
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	IronLadleNo=rsIron.GetFieldByName(_T("IronLadleNo")).ToString();



	//  生成base和process表
	// 重要操作


	

	// 查询对应出钢计划数据
	CString strSQLPlan; strSQLPlan.Format(_T("select * from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,GetRealHeatID(strHeatID));
	CL3RecordSetWrap rsPlan;
	if(!Query(strSQLPlan,rsPlan) || rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
	{	// 计划不存在
		Rollback(nTrans);
		/*SetL3LastError("0xF0011001");*/
		return -18;
	}
	rsPlan.MoveFirst();
	// 修改当前DEP数据
	SteelGradeIndex = rsPlan.GetFieldByName(_T("SteelGradeIndex")).ToCString();
	

	// 产生DEP炉次基本数据CDEP_Base_Data
	CL3RecordSetWrap rsBaseData;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),rsBaseData))
	{
		Rollback(nTrans);
		return -19;
	}
	rsBaseData.AppendRecord();
	rsBaseData.CopyCurRowFrom(rsPlan);
	rsBaseData.SetFieldByName(_T("IronLadle"),CL3Variant(IronLadle));
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
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),rsBaseData) < 1)
	{
		Rollback(nTrans);
		return -20;
	}

	// 产生过程数据
	CL3RecordSetWrap rsProc;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),rsProc))
	{
		Rollback(nTrans);
		return -21;
	}
	rsProc.AppendRecord();
	rsProc.SetFieldByName(_T("IronLadle"),CL3Variant(IronLadle));
	rsProc.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	//  Charging_Start_Time 进站时刻
	rsProc.SetFieldByName(_T("Charging_Start_Time"),CL3Variant(curTime));
    //添加包龄
	CString  ironladleid=IronLadle.Left(3);
	CString strironladlebase = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\IronLadleMag\\CIronLadle_Base"),ironladleid);
	rsProc.SetFieldByName(_T("LadleAge"),GetObjectPropValue(strironladlebase,_T("IronLadle_Age")));
	//添加铁包状况
	rsProc.SetFieldByName(_T("Ladle_Status"),_T("正常"));

	if(!CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),rsProc))
	{
		Rollback(nTrans);
		return -22;
	}

	// 修改DEP状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPFeeding))
	{
		Rollback(nTrans);
		return -23;
	}




	SendStatusToPLC(1);// 用于下传铁水到达状态

	if(nTrans > 0)
		Commit(nTrans);

	return 0;

}


/// <Method class="CDEP_Unit_Mag" name="Waiting" type="L3BOOL">
/// 铁包离站，DEP进入等待状态。
/// </Method>
L3LONG CDEP_Unit_Mag::Waiting()
{
	// 修改DEP属性

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// 检查DEP状态
	if(Status == CDEP_Unit_Mag::DEPWaiting)
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return -2;
	}
   CString strAreaURI= _T("XGMESLogic\\DePMag\\CDEP_Prod_Area\\S91");
	CL3Variant val = InvokeObjectMethod(strAreaURI,_T("GetMaterialDetails"),_T("CIron_Data"),_T(""));
	CL3RecordSetWrap rsSteel;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rsSteel)) || rsSteel.GetRowCount() < 1)
	{
		if(nTrans > 0) Rollback(nTrans);
		return -3;
	}
	rsSteel.AddField(_T("Area"),VT_BSTR);
	rsSteel.MoveFirst();
	rsSteel.SetFieldByName(_T("Area"),CL3Variant(strAreaURI));

	CString strTargetCache = GetOutputCache();
	// 铁水下线
	CBSTR bstrTarget = strTargetCache;
	if(!DeliverMaterialsTo(bstrTarget.GetBuffer(TRUE),rsSteel))
	{
		if(nTrans > 0) Rollback(nTrans);
		return -4;
	}
	


	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPWaiting))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -5;
	}
    COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);

	SetObjectPropValue(strProcData,_T("Furnace_Age"),CL3Variant(FurnaceAge));
	SetObjectPropValue(strProcData,_T("Furnace_Surface"),CL3Variant(Furnace_Surface));
	SetObjectPropValue(strProcData,_T("LanceNo"),CL3Variant(LanceNo));
	SetObjectPropValue(strProcData,_T("Lance_Age"),CL3Variant(LanceAge));
	SetObjectPropValue(strProcData,_T("Slag_Head"),CL3Variant(Slag_Head));
	//SetObjectPropValue(strProcData,_T("BlowO2_Time"),CL3Variant(L3LONG(Desi_Time)));
	//SetObjectPropValue(strProcData,_T("Tapping_Time"),CL3Variant((LONG)span.GetTotalSeconds()));
	//SetObjectPropValue(strProcData,_T("BlowO2_Time"),CL3Variant(Desi_Time));
	//SetObjectPropValue(strProcData,_T("ReBlow_Time"),CL3Variant(Dep_Time));
	//离站时间
	SetObjectPropValue(strProcData,_T("Tapping_End_Time"),CL3Variant(curTime));
	CString strFeedData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Feed_Data"),IronLadle);
	SetObjectPropValue(strFeedData,_T("IronTemp"),CL3Variant(CurTemp));


	Load=0;
	//添加脱磷标志 脱磷脱硅时间
	Dep_Flag=0;
	Dep_Time=0;
	Desi_Time=0;
	IronLadle=_T("");
	CurTemp=0;
	IronLadleNo=_T("");
	SteelGradeIndex=_T("");
	StartProcessTime=_T("");

	//氧枪枪龄加1  喷枪枪龄加1
	FurnaceAge++;
	LanceAge++;
	Slag_Head++;



	if(nTrans > 0)
		Commit(nTrans);

	

	return 0;
}





/// <Method class="CDEP_Unit_Mag" name="FeedElement" type="L3BOOL">
/// 向DEP中加料。
/// <Param name="rsElement" type="L3RECORDSET">加料数据，包含类型，辅料代码，料量</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::FeedElement(L3RECORDSET rsElement)
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

	// 锁定本DEP
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
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog))
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
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);

	return TRUE;
}

/// <Method class="CDEP_Unit_Mag" name="TopBlowing" type="L3BOOL">
/// 处理并记录DEP顶吹事件。
/// <Param name="rsBlow" type="L3RECORDSET">顶吹数据</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::TopBlowing(L3RECORDSET rsBlow)
{
	//CL3RecordSetWrap rs = rsBlow;
	//if(rs.GetRowCount() < 1)
	//	return FALSE;

	//// 检查数据
	//if(rs.GetFieldByName(_T("Flow")) < 0 ||
	//	rs.GetFieldByName(_T("Pressure")) < 0)
	//{
	//	SetL3LastError(L3ERR_WRONG_PARAMETER);
	//	return FALSE;
	//}

	//BOOL bUseTimeNow = FALSE;
	//if(rs.GetFieldByName(_T("Catch_Time")) < 0)
	//{
	//	bUseTimeNow = TRUE;
	//}

	//LONG nTrans = 0;
	//if(!IsInTrans())
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return FALSE;
	//}

	//// 锁定本DEP
	//if(!PutObjectIntoTrans(GetURI()))
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return FALSE;
	//}

	//// 获取炉号
	//CString strHeatID = HeatID;
	//COleDateTime curTime = COleDateTime::GetCurrentTime();

	//// 记录顶吹记录
	//CL3RecordSetWrap rsLog;
	//if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Top_Blowing"),rsLog))
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return FALSE;
	//}
	//rs.MoveFirst();
	//rsLog.CopyFrom(rs);
	//rsLog.MoveFirst();
	//while(!rsLog.IsEOF())
	//{
	//	rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	//	if(bUseTimeNow)
	//		rsLog.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));
	//	rsLog.MoveNext();
	//}
	//rsLog.MoveFirst();
	//if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Top_Blowing"),rsLog) < 1)
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return FALSE;
	//}

	//// 更新当前顶吹数据
	//rsLog.MoveFirst();
	//L3DATETIME dtMax = 0;
	//while(!rsLog.IsEOF())
	//{
	//	L3DATETIME dt = rsLog.GetFieldByName(_T("Catch_Time")).ToDateTime();
	//	if(dt > dtMax)
	//	{
	//		SetPropValue(_T("TopFlow"),rsLog.GetFieldByName(_T("Flow")));
	//		SetPropValue(_T("TopPressure"),rsLog.GetFieldByName(_T("Pressure")));
	//		dtMax = dt;
	//	}
	//	rsLog.MoveNext();
	//}

	//if(nTrans > 0)
	//	Commit(nTrans);

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="BottomBlowing" type="L3BOOL">

/// </Method> 开始捞渣SI  
L3BOOL CDEP_Unit_Mag::StartSlag()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPBeginSlag )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSlag))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}

//  结束捞渣SI
L3BOOL CDEP_Unit_Mag::EndSlag()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPEndSlag )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSlag))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}



//开始捞渣P
L3BOOL CDEP_Unit_Mag::StartSlagP()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPBeginSlagP )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSlagP))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}

//  结束捞渣P
L3BOOL CDEP_Unit_Mag::EndSlagP()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPEndSlagP )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSlagP))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}

// 开始喷吹SI
L3BOOL CDEP_Unit_Mag::StartSpray()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPBeginSpray )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSpray))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
   COleDateTime curTime = COleDateTime::GetCurrentTime();
	//if(Dep_Flag<1)
	//{
	 Desi_Start_time=curTime;
	
	//}
	/*else
	{
	Dep_Start_time=curTime;
	}*/


	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}


// 结束喷吹SI
L3BOOL CDEP_Unit_Mag::EndSpray()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPEndSpray )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSpray))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	//脱磷标志为0 将时间给脱硅  1时 脱硅
	//if(Dep_Flag<1)
	//{
	COleDateTimeSpan span = curTime - Desi_Start_time;
	L3LONG  time=(LONG)span.GetTotalSeconds();
	//SetObjectPropValue(strProcData,_T("Tapping_Time"),CL3Variant((LONG)span.GetTotalSeconds()));
	Desi_Time+=time;
	
	/////
   CString csURI = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);
   SetObjectPropValue(csURI,_T("BlowO2_Time"),CL3Variant(L3LONG(Desi_Time)));//脱硅喷吹时间
	/////                                  
	//}
	//else
	//{
	//COleDateTimeSpan span = curTime - Dep_Start_time;
	//L3LONG  time=(LONG)span.GetTotalMinutes();
	//Dep_Time+=time;
	////Dep_Start_time=curTime;
	//}
	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}




// 开始喷吹P
L3BOOL CDEP_Unit_Mag::StartSprayP()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPBeginSprayP )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSprayP))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
   COleDateTime curTime = COleDateTime::GetCurrentTime();
	/*if(Dep_Flag<1)
	{
	 Desi_Start_time=curTime;
	
	}
	else
	{
	Dep_Start_time=curTime;
	}*/

 Dep_Start_time=curTime;
	   
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}


// 结束喷吹P
L3BOOL CDEP_Unit_Mag::EndSprayP()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPEndSprayP )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSprayP))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	//脱磷标志为0 将时间给脱硅  1时 脱硅
	/*if(Dep_Flag<1)
	{
	COleDateTimeSpan span = curTime - Desi_Start_time;
	L3LONG  time=(LONG)span.GetTotalMinutes();
	Desi_Time+=time;
	
	
	}
	else
	{*/
	COleDateTimeSpan span = curTime - Dep_Start_time;
	L3LONG  time=(LONG)span.GetTotalSeconds();
	Dep_Time+=time;
 //Dep_Start_time=curTime;
	/*}*/
	////
   CString csURI = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);
   SetObjectPropValue(csURI,_T("ReBlow_Time"),CL3Variant(Dep_Time));///脱磷喷吹时间
	////
	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}



// 补吹开始
L3BOOL CDEP_Unit_Mag::ReblowBeginSpray()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPBeginReblow )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}
	
	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginReblow))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
  /* COleDateTime curTime = COleDateTime::GetCurrentTime();
	if(Dep_Flag<1)
	{
	 Desi_Start_time=curTime;
	
	}
	else
	{
	Dep_Start_time=curTime;
	}*/
 /*CL3RecordSetWrap rs;*/
	L3SHORT  count = 0;
	

	   count += count;
	   //count1=count1+count;
	  
	/////
//CString csURI = _T("XGMESLogic\\DePMag\\CDEP_Process_Data\\");

   
	//SetObjectPropValue(csURI+HeatID,_T("ReBlow_Count"),CL3Variant((L3SHORT)count));
   CString csURI = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);
   SetObjectPropValue(csURI,_T("ReBlow_Count"),CL3Variant((L3SHORT)count));
	


	/////



	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}


// 补吹结束
L3BOOL CDEP_Unit_Mag::ReblowEndSpray()
{
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定本DEP
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
	if(( Status == CDEP_Unit_Mag::DEPEndReblow )||(Status == CDEP_Unit_Mag::DEPWaiting))
	{	// 已经进入兑铁状态
		Rollback(nTrans);
		//SetL3LastError(XGMES_ERR_BOFREFUSED);
		return FALSE;
	}

	// 修改当前状态
	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndReblow))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	//if(Step<2)
	//{
	// COleDateTime curTime = COleDateTime::GetCurrentTime();
	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
	//
	//}
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	//脱磷标志为0 将时间给脱硅  1时 脱硅
	/*if(Dep_Flag<1)
	{
	COleDateTimeSpan span = curTime - Desi_Start_time;
	L3LONG  time=(LONG)span.GetTotalMinutes();
	Desi_Time+=time;
	
	}
	else
	{
	COleDateTimeSpan span = curTime - Dep_Start_time;
	L3LONG  time=(LONG)span.GetTotalMinutes();
	Dep_Time+=time;
	
	}*/
	////
CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Status"),HeatID);
CString strProc = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);
CString csStatus =  GetObjectPropValue(strProcData,_T("Status")).ToCString();
if (Status==11)
 {
   COleDateTime dReblowBeginTime = GetObjectPropValue(strProcData,_T("Change_Time")).ToDateTime();
   COleDateTime curTime = COleDateTime::GetCurrentTime();
   
   COleDateTimeSpan span = curTime - dReblowBeginTime;
	L3LONG  time=(LONG)span.GetTotalSeconds();
	time += time;
	SetObjectPropValue(strProc,_T("Single_LaC"),CL3Variant(time));//补吹时间
	
   }
	////
       
////

	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}



//L3BOOL CDEP_Unit_Mag::StartSi()
//{
//	LONG nTrans = 0;
//	if(!IsInTrans())
//	{
//		nTrans = BeginTrans();
//		if(nTrans < 1)
//			return FALSE;
//	}
//	// 锁定本DEP
//	if(!PutObjectIntoTrans(GetURI()))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//
//	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
//	if(( Status == CDEP_Unit_Mag::DEPBeginSi )||(Status == CDEP_Unit_Mag::DEPWaiting))
//	{	// 已经进入兑铁状态
//		Rollback(nTrans);
//		//SetL3LastError(XGMES_ERR_BOFREFUSED);
//		return FALSE;
//	}
//
//	// 修改当前状态
//	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginSi))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//	//if(Step<2)
//	//{
//	// COleDateTime curTime = COleDateTime::GetCurrentTime();
//	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
//	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
//	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
//	//
//	//}
//	   
//	if(nTrans > 0)
//		Commit(nTrans);
//	return TRUE;
//}
//
//L3BOOL CDEP_Unit_Mag::EndSi()
//{
//	LONG nTrans = 0;
//	if(!IsInTrans())
//	{
//		nTrans = BeginTrans();
//		if(nTrans < 1)
//			return FALSE;
//	}
//	// 锁定本DEP
//	if(!PutObjectIntoTrans(GetURI()))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//
//	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
//	if(( Status == CDEP_Unit_Mag::DEPEndSi )||(Status == CDEP_Unit_Mag::DEPWaiting))
//	{	// 已经进入兑铁状态
//		Rollback(nTrans);
//		//SetL3LastError(XGMES_ERR_BOFREFUSED);
//		return FALSE;
//	}
//
//	// 修改当前状态
//	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndSi))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//	//if(Step<2)
//	//{
//	// COleDateTime curTime = COleDateTime::GetCurrentTime();
//	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
//	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
//	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
//	//
//	//}
//	   
//	if(nTrans > 0)
//		Commit(nTrans);
//	return TRUE;
//}
//
//L3BOOL CDEP_Unit_Mag::StartP()
//{
//	LONG nTrans = 0;
//	if(!IsInTrans())
//	{
//		nTrans = BeginTrans();
//		if(nTrans < 1)
//			return FALSE;
//	}
//	// 锁定本DEP
//	if(!PutObjectIntoTrans(GetURI()))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//
//	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
//	if(( Status == CDEP_Unit_Mag::DEPBeginP )||(Status == CDEP_Unit_Mag::DEPWaiting))
//	{	// 已经进入兑铁状态
//		Rollback(nTrans);
//		//SetL3LastError(XGMES_ERR_BOFREFUSED);
//		return FALSE;
//	}
//    //脱磷标志 置1
//	Dep_Flag=1;
//
//	// 修改当前状态
//	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPBeginP))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//	//if(Step<2)
//	//{
//	// COleDateTime curTime = COleDateTime::GetCurrentTime();
//	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
//	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
//	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
//	//
//	//}
//	   
//	if(nTrans > 0)
//		Commit(nTrans);
//	return TRUE;
//}
//
//
//L3BOOL CDEP_Unit_Mag::EndP()
//{
//	LONG nTrans = 0;
//	if(!IsInTrans())
//	{
//		nTrans = BeginTrans();
//		if(nTrans < 1)
//			return FALSE;
//	}
//	// 锁定本DEP
//	if(!PutObjectIntoTrans(GetURI()))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//
//	// 检查DEP状态2009-01-02 tangyi  已经开始捞渣或者已出站
//	if(( Status == CDEP_Unit_Mag::DEPEndP )||(Status == CDEP_Unit_Mag::DEPWaiting))
//	{	// 已经进入兑铁状态
//		Rollback(nTrans);
//		//SetL3LastError(XGMES_ERR_BOFREFUSED);
//		return FALSE;
//	}
//
//	// 修改当前状态
//	if(!ChangeDEPStatus(CDEP_Unit_Mag::DEPEndP))
//	{
//		if(nTrans > 0)
//			Rollback(nTrans);
//		return FALSE;
//	}
//	//if(Step<2)
//	//{
//	// COleDateTime curTime = COleDateTime::GetCurrentTime();
//	// CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),HeatID);
//	// SetObjectPropValue(strProcData,_T("Blow_Start_Time"),CL3Variant(curTime));
//	// StartProcessTime = curTime.Format(_T("%H:%M:%S"));
//	//
//	//}
//	   
//	if(nTrans > 0)
//		Commit(nTrans);
//	return TRUE;
//}
//
//
//

/// <Method class="CDEP_Unit_Mag" name="SetOxygen" type="L3BOOL">
/// 处理并记录定氧事件。
/// <Param name="rsOxygen" type="L3RECORDSET">定氧数据</Param>
/// </Method>

/// <Method class="CDEP_Unit_Mag" name="SetTemperature" type="L3BOOL">
/// 处理并记录DEP测温事件。
/// <Param name="rsTemp" type="L3RECORDSET">测温数据</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::SetTemperature(L3RECORDSET rsTemp)
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

	// 锁定本DEP
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
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Temp_Data"),rsLog))
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
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Temp_Data"),rsLog) < 1)
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

/// <Method class="CDEP_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
/// 修改DEP设备状态
/// <Param name="nStatus" type="L3LONG">新设备状态</Param>
/// <Param name="reason" type="L3STRING">原因</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::ChangeDeviceStatus(L3LONG nStatus,L3STRING reason)
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
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Equipment_Status"),rsLog))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}
	rsLog.AppendRecord();
	CString cstrUnitID = (GetIdentity().ToCString()).Right(1);
	rsLog.SetFieldByName(_T("DEPID"),(L3LONG)_ttoi(cstrUnitID));
	rsLog.SetFieldByName(_T("Status"),CL3Variant(nStatus));
	rsLog.SetFieldByName(_T("Log_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	rsLog.SetFieldByName(_T("Reason"),CL3Variant(reason));
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Equipment_Status"),rsLog) < 1)
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0)
		Commit(nTrans);
	return TRUE;
}





/// <Method class="CDEP_Unit_Mag" name="GetIronsForDesignate" type="L3RECORDSET">
/// 返回可用于指定炉号的铁水信息。
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetIronsForDesignate()
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

/// <Method class="CDEP_Unit_Mag" name="GetInputIrons" type="L3RECORDSET">
/// 返回已经指定了的铁水信息
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetInputIrons()
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
	CL3Variant valIrons = InvokeObjectMethod(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S91P01"),_T("GetMaterialDetails"),bstrIronType.GetBuffer(TRUE),bstrCond.GetBuffer(TRUE));
	if(FAILED(valIrons.QueryInterface(IID_IL3RecordSet,rsIrons)))
	{
		return NULL;
	}
	
	return rsIrons.Detach();
}

/// <Method class="CDEP_Unit_Mag" name="GetInputScrapes" type="L3RECORDSET">
/// 返回已经指定了的生铁废钢信息
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetInputScrapes()
{
	//CL3RecordSetWrap rsScrapes;
	//CString strSQL;
	////strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag,StoreAreaID,Amount from %s where Iron_Flag = 1 and HeatID = '%s'"),SCRAP_OUT_CLASS_URI,NextHeatID);
	//strSQL.Format(_T("select GUID,Scrap_Slot_ID,HeatID,Iron_Flag,StoreAreaID,Amount from %s where Iron_Flag = 1 and HeatID = '%s'"),SCRAP_OUT_CLASS_URI,HeatID);
	//if(!Query(strSQL,rsScrapes))
	//{
		return NULL;
	//}
	/*return rsScrapes.Detach();*/
}

/// <Method class="CDEP_Unit_Mag" name="OnTimer" type="L3BOOL">
/// 定时器处理
/// <Param name="uEventID" type="L3ULONG">事件ID</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::OnTimer(L3ULONG uEventID)
{
	//if(uEventID == m_nTimer)
	//{	// 吹炼定时器
	//	BlowTotalTime += BLOWTIME;
	//	BlowThisTime += BLOWTIME;
	//}

	return TRUE;
}

/// <Method class="CDEP_Unit_Mag" name="GetAddedMaterialSum" type="L3RECORDSET">
/// 返回指定炉号的加料量统计数据。
/// <Param name="HeatID" type="L3STRING">炉号</Param>
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetAddedMaterialSum(L3STRING HeatID)
{
	CString strHeatID = String_BSTR2TChar(HeatID);
	CString strSQL;
	strSQL.Format(_T("select Element,Type,sum(Weight) as Weight from %s where HeatID = '%s' group by Element, Type"),
			_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),(LPCTSTR)strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog))
		return NULL;
	rs.MoveFirst();
	rsLog.CopyFrom(rs);
	return rsLog.Detach();
}


/// <Method class="CDEP_Unit_Mag" name="AcceptAlloyDischargeData" type="L3RECORDSET">
/// 料仓加料数据采集
/// <Param name="HeatID" type="L3STRING">炉号</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptMaterialDischargeData(L3RECORDSET rsMaterialData)
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
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog))
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
	//CL3RecordSet *pRSBulk = new CL3RecordSet();
	//CL3RecordSetWrap rsBulkOut; pRSBulk->QueryInterface(IID_IL3RecordSet,rsBulkOut); pRSBulk->Release();
	//rsBulkOut.AddField(_T("MaterialID"),VT_BSTR);
	//rsBulkOut.AddField(_T("MaterialType"),VT_BSTR);
	//rsBulkOut.AddField(_T("Amount"),VT_R8);
	//rsBulkOut.AddField(_T("StoreAreaID"),VT_BSTR);
	//rsBulkOut.AddField(_T("Target"),VT_BSTR);
	//rsBulkOut.AddField(_T("UnitID"),VT_BSTR);
	//rsBulkOut.AddField(_T("Bulk_Code"),VT_BSTR);
	//rsBulkOut.AddField(_T("Batch_ID"),VT_BSTR);

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
		//2009-03-06  DEP新增散状料累计数据收集
		//转换MES合金料仓号
		CString csPlcAddress = rsData.GetFieldByName(_T("PLC_Address")).ToCString();
		//L3SHORT iType = rsData.GetFieldByName(_T("Type")).ToShort(); //散状料累计 iType = 9;
		////2009-05-11 begin 出钢开始至下炉主吹过程所加物料不能算拉碳调料数据
		//if (((Status >= CDEP_Unit_Mag::DEPTapping) || (Status <= CDEP_Unit_Mag::DEPBlowing)) && (iType == 2))
		//{
		//	rsData.SetFieldByName(_T("Type"),CL3Variant((L3SHORT)1));
		//	iType = 1;
		//}
		//2009-05-11 end
	   /*	csPlcAddress.Replace(_T("."),_T("_"));*/
		csPlcAddress.Trim();
		if(csPlcAddress.IsEmpty())
		{
			rsData.MoveNext();
			continue;
		}
		CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\CBase_Address_Bulk_Relation\\") + csPlcAddress;
		CString csArea = GetObjectPropValue(csAreaUri,_T("Area")).ToCString();
		csArea.Trim();
		// S83Y04
		CString csMaterialType = csArea.Mid(0,3);
		rsLog.AppendRecord();
		//根据合金料仓号得到合金
		CString csSQL;
		CL3RecordSetWrap rs;
		CString cstrAreaUri;
		
		//if(csMaterialType == STORE_ID_ALLOY)//合金料仓
		//{
			cstrAreaUri = _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Bulk_Relation\\") + csArea;//	2008-12-28 yao
			csSQL.Format(_T(" select b.Alloy_Code as Element,b.Batch_ID,a.MaterialID,a.MaterialType,a.Amount as PosWeight from MATERIALPOSITION a,CAlloy_Data b where a.Position = '%s' and a.MaterialID = b.MaterialID order by b.Batch_ID "),csArea);
		/*}*/
		//else
		//{
		//	cstrAreaUri = _T("XGMESLogic\\BulkStoreMag\\CBulk_Bulk_Relation\\") + csArea; //	2008-12-28 yao
		//	csSQL.Format(_T(" select b.Bulk_Code as Element,b.Batch_ID,a.MaterialID,a.MaterialType,a.Amount as PosWeight  from MATERIALPOSITION a,CBulk_Data b where a.Position = '%s' and a.MaterialID = b.MaterialID order by Idx "),csArea);
		//}

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
	/*		if(csMaterialType == STORE_ID_ALLOY)
			{*/
				rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
				rsMaterial.SetFieldByName(_T("Element"),GetObjectPropValue(cstrAreaUri,_T("Alloy_Code")));	
			/*}
			else
			{
				rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BULK));
				rsMaterial.SetFieldByName(_T("Element"),GetObjectPropValue(cstrAreaUri,_T("Bulk_Code")));	
			}*/
			rsMaterial.SetFieldByName(_T("Weight"),CL3Variant(nRemainWeight));
		}

        L3LONG dep_type;
		if(Status==2)
		{
			dep_type=0;
		}else if (Status==5||Status==6)
		{
			dep_type=1;
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
			if (Status == CDEP_Unit_Mag::DEPWaiting) //2009-03-10 DEP等待状态所加物料为下炉次
			{
				//当前炉次出钢开始后，从下位机系统收集的散状料数据记为下炉次消耗
				csDishcargingHeatID = NextHeatID;
			}
			else
			{
				csDishcargingHeatID = HeatID;
				//当前炉次出钢开始前，从下位机系统收集的散状料数据记为当前炉次消耗
			}

		
			CString csMaterialID = rsMaterial.GetFieldByName(_T("MaterialID")).ToCString();
			csMaterialID.Trim();
			

			//if(csMaterialType == STORE_ID_ALLOY)//合金料仓
			//{
    			rsLog.SetFieldByName(_T("HeatID"),CL3Variant(csDishcargingHeatID));
				//rsLog.SetFieldByName(_T("Type"),CL3Variant(L3LONG(5)));
				rsLog.SetFieldByName(_T("Type"),CL3Variant(dep_type));
 			
				if(csMaterialID != _T("NoMaterialID"))
				{
					rsAlloyOut.AppendRecord();
					rsAlloyOut.CopyCurRowFrom(rsMaterial);
					rsAlloyOut.SetFieldByName(_T("Amount"),rsMaterial.GetFieldByName(_T("Weight")));
					rsAlloyOut.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));
					rsAlloyOut.SetFieldByName(_T("Target"),CL3Variant(csDishcargingHeatID));
					rsAlloyOut.SetFieldByName(_T("UnitID"),CL3Variant(GetIdentity().ToCString()));	
					rsAlloyOut.SetFieldByName(_T("Alloy_Code"),rsMaterial.GetFieldByName(_T("Element")));
				}
		
			rsMaterial.MoveNext();		
		}

		rsData.MoveNext();	
	}


	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog) < rsLog.GetRowCount())
		return FALSE;


	if(!rsAlloyOut.IsNull() && rsAlloyOut.GetRowCount() > 0)
		InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("OutputMaterials"),L3RECORDSET(rsAlloyOut));


	return TRUE;
}


/// <Method class="CDEP_Unit_Mag" name="MaterialGroundDischargeData" type="L3RECORDSET">
/// 袋装合金散状料消耗
/// <Param name="HeatID" type="L3STRING">炉号</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::MaterialGroundDischargeData(L3RECORDSET rsMaterialData)
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
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog))
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

	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Addition_Data"),rsLog) < rsLog.GetRowCount())
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





/// <Method class="CDEP_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
/// 申请改钢
/// <Param name="Reason" type="L3STRING">原因</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_EXE_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csUri = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),csHeatID);
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


/// <Method class="CDEP_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  钢水回炉申请 2009-02-28 增加炉号
/// <Param name="Reason" type="L3STRING">原因</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID)
{
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(DISPATCH_STEEL_TURN_CLASS_URI,rsSteel))
		return false;
	rsSteel.DelField(_T("GUID"));
	rsSteel.DelField(_T("Name"));
	rsSteel.AppendRecord();
	//CString csHeatID =GetPropValue(_T("HeatID")).ToCString();
	CString csHeatID = strHeatID;
	CString csUri = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),csHeatID);
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

/// <Method class="CDEP_Unit_Mag" name="GetExceptHeatID" type="L3RECORDSET">
/// 获取工艺异常炉号数据。
/// <Param name="UnitID" type="L3STRING">工位</Param>
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetExceptHeatID(L3STRING UnitID)
{
	CString strUnitID = String_BSTR2TChar(UnitID);
	int nUnitTypeID = _ttoi(strUnitID.Mid(1,1));
	CString csUnitID = strUnitID.Mid(2,1);
	CString strSQL;
	switch(nUnitTypeID)
	{
	case 9:
		{	//DEP
			strSQL.Format(_T("select HeatID from (select HeatID from %s  order by ProductionDate desc) where rownum < 3"),
					_T("XGMESLogic\\DePMag\\CDEP_Base_Data"),csUnitID);
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

/// <Method class="CDEP_Unit_Mag" name="SetStackData" type="L3BOOL">
/// 记录DEP炉衬维护数据
/// <Param name="rsData" type="L3RECORDSET">炉衬数据</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::SetStackData(L3RECORDSET rsData)
{

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="LockData" type="L3SHORT">
/// 封锁实绩数据
/// <Param name="strUnitID" type="L3STRING">工位</Param>
/// <Param name="strHeatID" type="L3STRING">炉号</Param>
/// <Param name="strTreatNo" type="L3STRING">处理号</Param>
/// </Method>
L3SHORT CDEP_Unit_Mag::LockData(L3STRING strUnitID,L3STRING strHeatID,L3STRING strTreatNo)
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

	//2009-04-14 人工确认日志时将手工录入的料从袋装合金处出库
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

	


		//Modify end
		//csURI = _T("XGMESLogic\\DePMag\\CDEP_Base_Data\\");
	 //   csLockFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,_T("DEPFinishedFlag"))).ToCString();
      /*  csPropName = _T("BOFFinishedFlag");*/
		//DEP手工输入合金
		CString csTempSQL = _T(" select * from CDEP_ADDITION_DATA where Name ='1'  and HeatID ='%s' ");
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
			CString	csTempSQL = _T(" select Alloy_Area from CAlloy_Bulk_Relation  where Alloy_Code = '%s' and Name ='15' ");
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
		
	
	



	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}
	csURI = _T("XGMESLogic\\DePMag\\CDEP_Base_Data\\");

	if (!SetObjectPropValue(csURI+csTreatNo,_T("Locked"),(L3SHORT)1))
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -4;
	}

	//if (!SetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+csHeatID,csPropName,CL3Variant(_T("1"))))
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return -5;
	//}

	if(nTrans > 0)
		Commit(nTrans);

	//2009-04-14 人工确认日志时将手工录入的料从袋装合金处出库
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

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPStatus" type="L3BOOL">
/// 接收DEP过程状态数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">状态数据</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPStatus(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	// 获取炉号
	rs.MoveFirst();
	L3LONG DEPStatus = -1;
	DEPStatus = (rs.GetFieldByName(_T("DEPStatus"))).ToLong();
	switch(DEPStatus)
	{
	case CDEP_Unit_Mag::DEPBeginSpray:
			StartSpray();
			break;
	
    case CDEP_Unit_Mag::DEPEndSpray:
			EndSpray();
			break;

	case CDEP_Unit_Mag::DEPBeginSlag:
		  StartSlag();
			
		break;
	case CDEP_Unit_Mag::DEPEndSlag:
		  EndSlag();
		break;
		
	case CDEP_Unit_Mag::DEPBeginSprayP: 
				StartSprayP();
		break;

    case CDEP_Unit_Mag::DEPEndSprayP: 
				EndSprayP();
		break;

    case CDEP_Unit_Mag::DEPBeginSlagP:
		  StartSlagP();
			
		break;
	case CDEP_Unit_Mag::DEPEndSlagP:
		  EndSlagP();
		break;

    case CDEP_Unit_Mag::DEPBeginReblow:
		  ReblowBeginSpray();
			
		break;
	case CDEP_Unit_Mag::DEPEndReblow:
		  ReblowEndSpray();
		break;

		default:
			break;
	}
	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPStatus" type="L3BOOL">
/// 接收DEP  步数状态 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">step</Param>
///



/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPTopBlowData(L3RECORDSET rsData)
{
	//CL3RecordSetWrap rs = rsData;
	//if(rs.GetRowCount() < 1)
	//	return TRUE;

	//CL3RecordSetWrap rsBlow;
	//if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Top_Blowing"),rsBlow))
	//{
	//	return FALSE;
	//}

	//rsBlow.CopyFrom(rs);

	//rsBlow.MoveFirst();
	//while (!rsBlow.IsEOF())
	//{
	//	rsBlow.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
	//	rsBlow.SetFieldByName(_T("Catch_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	//	TopFlow = rsBlow.GetFieldByName(_T("Flow")).ToFloat();
	//	TopPressure = rsBlow.GetFieldByName(_T("Pressure")).ToFloat();
	//	rsBlow.MoveNext();
	//}

	//rsBlow.MoveFirst();
	//if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Top_Blowing"),rsBlow) < rsBlow.GetRowCount())
	//{
	//	return FALSE;
	//}

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPTappedData" type="L3BOOL">
/// 接收DEP出钢数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">出钢数据</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPTappedData(L3RECORDSET rsData)
{
	//CL3RecordSetWrap rs = rsData;
	//if(rs.GetRowCount() < 1)
	//	return TRUE;

	//rs.AddField(_T("HeatID"),L3VT_STRING);
	//rs.MoveFirst();
	//while (!rs.IsEOF())
	//{
	//	rs.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
	//	rs.MoveNext();
	//}

	//rs.MoveFirst();
	//SetObjsPropValues(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),rs);

	//CalculateLcTemp();

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPTempData" type="L3BOOL">
/// 接收DEP测温数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">测温数据</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPTempData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	if (Status >= CDEP_Unit_Mag::DEPWaiting) //出钢结束后不再收集温度数据2009-01-09
	{
		return TRUE;
	}

	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Temp_Data"),rsTemp))
	{
		return FALSE;
	}

			// 写入脱硅脱磷温度
	CString strProcData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),IronLadle);

	//		// 写入主原料温度
//	CString strFeedData = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Feed_Data"),IronLadle);





	rsTemp.CopyFrom(rs);

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
		rsTemp.SetFieldByName(_T("Temp_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		CurTemp = rsTemp.GetFieldByName(_T("Temp")).ToLong();

		///写入脱硅脱磷温度
		if(Status==4)
		{
			SetObjectPropValue(strProcData,_T("LaC_Temp"),CL3Variant(CurTemp));
		}
		else if(Status==8)
		{
			SetObjectPropValue(strProcData,_T("Tapping_Temp"),CL3Variant(CurTemp));
		}

		//SetObjectPropValue(strFeedData,_T("IronTemp"),CL3Variant(CurTemp));
		////
		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Temp_Data"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="AcceptDEPOxygenData" type="L3BOOL">
/// 接收DEP定氧数据 2008-12-28
/// <Param name="rsData" type="L3RECORDSET">定氧数据</Param>
/// </Method>
L3BOOL CDEP_Unit_Mag::AcceptDEPOxygenData(L3RECORDSET rsData)
{
	//CL3RecordSetWrap rs = rsData;
	//if(rs.GetRowCount() < 1)
	//	return TRUE;

	//if (Status >= CDEP_Unit_Mag::DEPTapped) //出钢结束后不再收集温度数据2009-01-09
	//{
	//	return TRUE;
	//}

	//CL3RecordSetWrap rsTemp;
	//if(!CreateClassPropSet(_T("XGMESLogic\\DePMag\\CDEP_Oxygen_Data"),rsTemp))
	//{
	//	return FALSE;
	//}

	//rsTemp.CopyFrom(rs);

	//rsTemp.MoveFirst();
	//while (!rsTemp.IsEOF())
	//{
	//	rsTemp.SetFieldByName(_T("HeatID"),CL3Variant(HeatID));
	//	rsTemp.SetFieldByName(_T("Measure_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
	//	rsTemp.MoveNext();
	//}

	//rsTemp.MoveFirst();
	//if(CreateNewObjects(_T("XGMESLogic\\DePMag\\CDEP_Oxygen_Data"),rsTemp) < rsTemp.GetRowCount())
	//{
	//	return FALSE;
	//}

	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="CalculateLcTemp" type="L3BOOL">
/// 计算脱碳末期温度数据，还原开始前最后一次温度
/// </Method>
L3BOOL CDEP_Unit_Mag::CalculateLcTemp()
{
	return TRUE;	
}

/// <Method class="CDEP_Unit_Mag" name="CalculateTappingTemp" type="L3BOOL">


/// <Method class="CDEP_Unit_Mag" name="CalculateDefaultSmeltPeriod" type="L3BOOL">
/// 计算冶炼周期 2009-01-14   
/// </Method>
L3BOOL CDEP_Unit_Mag::CalculateDefaultSmeltPeriod()
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

    CString strUri = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),cspreviousHeatID);
	COleDateTime dTappingEndTime = GetObjectPropValue(strUri,_T("Tapping_End_Time")).ToDateTime();
	COleDateTime dCurTime = COleDateTime::GetCurrentTime();
	COleDateTimeSpan span = dCurTime - dTappingEndTime;
	
	LONG smeltperious = (LONG)span.GetTotalMinutes();

	CString strUri2 = CL3NameParser::MergeClassDomainName(_T("XGMESLogic\\DePMag\\CDEP_Process_Data"),curHeatID);
	if (smeltperious > 0)
	{
	   if (!SetObjectPropValue(strUri2,_T("Smelt_Period"),CL3Variant((L3LONG)smeltperious)))
	   {
			return FALSE; 
	   }
	}

	return TRUE;	
}

/// 获取上一炉号
CString CDEP_Unit_Mag::GetPreviousHeatID(LPCTSTR lpcszHeatID)
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
		csSQL.Format(_T("select max(HeatID) as HeatID from CDEP_Process_Data where substr(HeatID,1,4) ='%s'"),cssubHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
			return _T("");
		rs.MoveFirst();
		csPreviousHeatID = rs.GetFieldByName(_T("HeatID")).ToCString();
	}

	return csPreviousHeatID;
}

/// <Method class="CDEP_Unit_Mag" name="SteelReturn" type="L3BOOL">
///  获取最近炉号 2009-02-28 增加炉号
/// <Param name="Reason" type="L3STRING">原因</Param>
/// </Method>
L3RECORDSET CDEP_Unit_Mag::GetPreThreeHeatID()
{
	CString csUnitID = GetIdentity().ToCString();
	CString csDEPID = csUnitID.Mid(2,1);
	CString csTempSQL =_T("select * from (select HeatID from CDEP_Base_Data where substr(HeatID,2,1) = '%s'  order by  HeatID desc) where rownum < 4");
	CString csSQL;
	csSQL.Format(csTempSQL,csDEPID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;
	return rs.Detach();	
}


/// <Method class="CDEP_Unit_Mag" name="SendStatusToPLC" type="L3BOOL">
/// 将铁水到达状态下传PLC 
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL  CDEP_Unit_Mag::SendStatusToPLC(L3LONG fStatus)
{
	//组建数据集
	CString csCCMID = GetIdentity().ToCString();
	
	//Modify begin by llj 2011-1-26 Add CCM7
	//if (csCCMID == _T("S65")) 屏蔽此修改为下面语句
	//if (csCCMID == _T("S65")||csCCMID == _T("S67"))
	////Modify end
	//{
	//	return false;
	//}

	CL3RecordSet *pRSheet = new CL3RecordSet();
	CL3RecordSetWrap rsWeight; pRSheet->QueryInterface(IID_IL3RecordSet,rsWeight); rsWeight->Release();
	rsWeight.AddField(_T("DEPID"),VT_BSTR);
	rsWeight.AddField(_T("Status"),VT_I4);
	rsWeight.AddField(_T("Permit_Delete_Flag"),VT_INT);

	rsWeight.AppendRecord();
	rsWeight.SetFieldByName(_T("DEPID"),CL3Variant(csCCMID));
	rsWeight.SetFieldByName(_T("Status"),CL3Variant(L3LONG(fStatus)));
	rsWeight.SetFieldByName(_T("Permit_Delete_Flag"),L3LONG(1));

	L3LONG nPosID = 1;
	CString csTableName = _T("DEP_PLCStatus");
	L3STRING strTableName = csTableName.AllocSysString();
	InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
					    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
						strTableName,(L3RECORDSET)rsWeight);
	L3SysFreeString(strTableName);

	return true;
}

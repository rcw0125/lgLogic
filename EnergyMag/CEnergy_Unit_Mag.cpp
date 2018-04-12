// 逻辑类CEnergy_Unit_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CEnergy_Unit_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CEnergy_Unit_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CEnergy_Unit_Mag.h"

//当对象被装载到系统中时，被调用
void CEnergy_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CEnergy_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <Method class="CEnergy_Unit_Mag" name="AcceptEnergyFlowData" type="L3BOOL">
/// 接收一级能源流量检测数据。
/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
/// </Method>
L3BOOL CEnergy_Unit_Mag::AcceptEnergyFlowData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount=0;
	if((rsCount = rs.GetRowCount()) < 1)
		return TRUE;

	CString strRuntimeClass = _T("XGMESLogic\\EnergyMag\\CEnergyRunTimeData\\");
	rs.MoveFirst();
	for (int i=0;i<rsCount;i++)
	{
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		int ifieldCount = rs.GetFieldCount();
		for(int j=1;j<ifieldCount-2;j++)
		{
			//设置CEnergyRunTimeData流量数据
			int TagName = 2000+j; //2001--2025 标签名配置为能源流量
			CString cstrTagName;
			cstrTagName.Format(_T("%d"),TagName);
			double tagValue = rs.GetFieldByIndex(j).ToDouble();
			SetObjectPropValue(strRuntimeClass+cstrTagName,_T("Flow"),rs.GetFieldByIndex(j));
			SetObjectPropValue(strRuntimeClass+cstrTagName,_T("Catch_Time"),CL3Variant(curTime));
		}
	}

	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="AcceptEnergyPressureData" type="L3BOOL">
/// 接收一级能源压力检测数据。
/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
/// </Method>
L3BOOL CEnergy_Unit_Mag::AcceptEnergyPressureData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount=0;
	if((rsCount = rs.GetRowCount()) < 1)
		return TRUE;

	CString strRuntimeClass = _T("XGMESLogic\\EnergyMag\\CEnergyRunTimeData\\");
	rs.MoveFirst();
	for (int i=0;i<rsCount;i++)
	{
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		int ifieldCount = rs.GetFieldCount();
		for(int j=1;j<ifieldCount-2;j++)
		{
			//设置CEnergyRunTimeData压力数据
			int TagName = 2000+j; //2001--2025 标签名配置为能源压力
			CString cstrTagName;
			cstrTagName.Format(_T("%d"),TagName);
			double tagValue = rs.GetFieldByIndex(j).ToDouble();
			SetObjectPropValue(strRuntimeClass+cstrTagName,_T("Pressure"),rs.GetFieldByIndex(j));
			SetObjectPropValue(strRuntimeClass+cstrTagName,_T("Catch_Time"),CL3Variant(curTime));
		}
	}
	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="AcceptEnergyConsumeData" type="L3BOOL">
/// 接收一级能源消耗检测数据。
/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
/// </Method>
L3BOOL CEnergy_Unit_Mag::AcceptEnergyConsumeData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount=0;
	if((rsCount = rs.GetRowCount()) < 1)
		return TRUE;

	//创建CEnergyConsumption记录集
	CL3RecordSetWrap rsLog;
	CString strLogClass = _T("XGMESLogic\\EnergyMag\\CEnergyConsumption");
	CreateClassPropSet(strLogClass,rsLog);

	rs.MoveFirst();
	for (int i=0;i<rsCount;i++)
	{
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		CString csProductionDate = curTime.Format(_T("%Y%m%d"));
		int ifieldCount = rs.GetFieldCount();
		for(int j=1;j<ifieldCount-2;j++)
		{
			//设置CEnergyConsumption消耗数据
			int TagName = 3000+j;
			CString cstrTagName;
			cstrTagName.Format(_T("%d"),TagName);
			double tagValue = rs.GetFieldByIndex(j).ToDouble();

			//设置CEnergyConsumption消耗数据
			rsLog.AppendRecord();
			CString csObjectID = csProductionDate + cstrTagName;
			rsLog.SetFieldByName(_T("ObjectID"),CL3Variant(csObjectID));
			rsLog.SetFieldByName(_T("ProductionDate"),CL3Variant(csProductionDate));
			rsLog.SetFieldByName(_T("TagName"),CL3Variant(cstrTagName));
			rsLog.SetFieldByName(_T("TagValue"),CL3Variant(tagValue));
			rsLog.SetFieldByName(_T("CreateTime"),CL3Variant(curTime));
			L3FLOAT dayValue = 0;
			L3FLOAT monthValue = 0;
			
			CalculateValue(csProductionDate,cstrTagName,tagValue,dayValue,monthValue);

			rsLog.SetFieldByName(_T("DayValue"),CL3Variant(dayValue));
			rsLog.SetFieldByName(_T("MonthValue"),CL3Variant(monthValue));
		}
	}

	if (rsLog.GetRowCount() > 0)
	{
		CreateNewObjects(strLogClass,rsLog);
	}
	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="AcceptTrendGasFlowData" type="L3BOOL">
/// 接收一级烘烤趋势煤气流量检测数据。
/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
/// </Method>
L3BOOL CEnergy_Unit_Mag::AcceptTrendGasFlowData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount=0;
	if((rsCount = rs.GetRowCount()) < 1)
		return TRUE;

	//创建CEnergyHistoryData记录集
	CL3RecordSetWrap rsLog;
	CString strLogClass = _T("XGMESLogic\\EnergyMag\\CEnergyHistoryData");
	CreateClassPropSet(strLogClass,rsLog);

	CString strRuntimeClass = _T("XGMESLogic\\EnergyMag\\CEnergyRunTimeData\\");
	rs.MoveFirst();
	for (int i=0;i<rsCount;i++)
	{
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		int ifieldCount = rs.GetFieldCount();
		for(int j=1;j<ifieldCount-2;j++)
		{
			//设置CEnergyRunTimeData流量数据 
			int TagName = 1000+j; //1001--1022 标签名配置为烘烤趋势煤气
			CString cstrTagName;
			cstrTagName.Format(_T("%d"),TagName);
			double tagValue = rs.GetFieldByIndex(j).ToDouble();
			SetObjectPropValue(strRuntimeClass+cstrTagName,_T("Flow"),rs.GetFieldByIndex(j));
			SetObjectPropValue(strRuntimeClass+cstrTagName,_T("Catch_Time"),CL3Variant(curTime));

			//设置CEnergyHistoryData流量数据
			//if (tagValue > 10) //数据大于10存储
			//{
				rsLog.AppendRecord();
				rsLog.SetFieldByName(_T("TagName"),CL3Variant(cstrTagName)); //1001--1022 标签名配置为烘烤趋势煤气
				rsLog.SetFieldByName(_T("TagType"),CL3Variant((L3LONG)2));
				rsLog.SetFieldByName(_T("TagValue"),CL3Variant(tagValue));
				rsLog.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));
			//}
		}
	}

	if (rsLog.GetRowCount() > 0)
	{
		CreateNewObjects(strLogClass,rsLog);
	}
	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="AcceptTrendAirFlowData" type="L3BOOL">
/// 接收一级烘烤趋势空气流量检测数据。
/// <Param name="rsData" type="L3RECORDSET">能源检测点数据</Param>
/// </Method>
L3BOOL CEnergy_Unit_Mag::AcceptTrendAirFlowData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount=0;
	if((rsCount = rs.GetRowCount()) < 1)
		return TRUE;

	//创建CEnergyHistoryData记录集
	CL3RecordSetWrap rsLog;
	CString strLogClass = _T("XGMESLogic\\EnergyMag\\CEnergyHistoryData");
	CreateClassPropSet(strLogClass,rsLog);

	CString strRuntimeClass = _T("XGMESLogic\\EnergyMag\\CEnergyRunTimeData\\");
	rs.MoveFirst();
	for (int i=0;i<rsCount;i++)
	{
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		int ifieldCount = rs.GetFieldCount();
		for(int j=1;j<ifieldCount-2;j++)
		{
			//设置CEnergyRunTimeData流量数据 
			int TagName = 1000+j; //1001--1022 标签名配置为烘烤趋势空气
			CString cstrTagName;
			cstrTagName.Format(_T("%d"),TagName);
			double tagValue = rs.GetFieldByIndex(j).ToDouble();
			SetObjectPropValue(strRuntimeClass+cstrTagName,_T("Pressure"),rs.GetFieldByIndex(j));
			SetObjectPropValue(strRuntimeClass+cstrTagName,_T("Catch_Time"),CL3Variant(curTime));

			//设置CEnergyHistoryData流量数据
			//if (tagValue > 10) //数据大于10存储
			//{
				rsLog.AppendRecord();
				rsLog.SetFieldByName(_T("TagName"),CL3Variant(cstrTagName)); //1001--1022 标签名配置为烘烤趋势空气
				rsLog.SetFieldByName(_T("TagType"),CL3Variant((L3LONG)1)); //空气流量在此当着压力存储
				rsLog.SetFieldByName(_T("TagValue"),CL3Variant(tagValue));
				rsLog.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));
			//}
		}
	}

	if (rsLog.GetRowCount() > 0)
	{
		CreateNewObjects(strLogClass,rsLog);
	}
	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="GetDayValue" type="L3BOOL">
///  获取当日能耗
/// <Param name="curday" type="COleDateTime">当天</Param>
/// <Param name="csTagName" type="CString">标签点</Param>
/// <Param name="fieldValue" type="L3FLOAT">现场数据</Param>
/// <Param name="dayValue" type="L3FLOAT">当日数据</Param>
/// <Param name="monthValue" type="L3FLOAT">月累数据</Param>
/// </Method>
L3BOOL CEnergy_Unit_Mag::CalculateValue(CString cscurday,
										CString csTagName,
										L3FLOAT fieldValue,
										L3FLOAT & todayValue,
										L3FLOAT & curmonthValue)
{
	if ( (cscurday.GetLength() != 8) ||
		 (csTagName.GetLength() < 1) || 
		 (fieldValue < 0))
		return FALSE;

	CString csTemp;
	CString csSQL;
	CL3RecordSetWrap rsResult;
	csTemp  = _T("SELECT TagValue											");
	csTemp += _T("  FROM (SELECT   TagValue									");
	csTemp += _T("            FROM CEnergyConsumption						");
	csTemp += _T("           WHERE ProductionDate < '%s' AND TagName = '%s'	");
	csTemp += _T("        ORDER BY ProductionDate DESC)						");
	csTemp += _T(" WHERE ROWNUM < 2											");
	
	csSQL.Format(csTemp,cscurday,csTagName);

	if(!Query(csSQL,rsResult))
		return FALSE;

	long rsCount = rsResult.GetRowCount();
	L3FLOAT lastValue = 0;
	if (rsCount > 0)
	{
		rsResult.MoveFirst();
        lastValue = rsResult.GetFieldByName(_T("TagValue")).ToFloat();
	}

	//获取系数
	L3LONG lCoefficient = 1;//默认值

	csTemp  = _T("SELECT CASE												");
 	csTemp += _T("         WHEN code_val_long IS NULL OR code_val_long < 1	");
	csTemp += _T("            THEN 1										");
	csTemp += _T("         ELSE code_val_long								");
	csTemp += _T("      END AS Code_Val_Long								");
 	csTemp += _T(" FROM cbase_all_code										");
 	csTemp += _T("WHERE code_group = 'EnergyConsumption' AND code = '%s'	");

	csSQL.Format(csTemp,csTagName);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult))
		return FALSE;
	
	if(rsResult.GetRowCount() > 0)
		lCoefficient = rsResult.GetFieldByName(_T("Code_Val_Long")).ToLong();

    todayValue = (fieldValue - lastValue) * lCoefficient ;

	if (todayValue < 0) //若小于前一天的数据,表明仪表数据轮回
		todayValue = (99999999 - lastValue + fieldValue ) * lCoefficient;

	
	csTemp   =_T("SELECT CASE									");
	csTemp += _T("          WHEN SUM (dayvalue) IS NULL			");
	csTemp += _T("             THEN 0							");
	csTemp += _T("          ELSE SUM (dayvalue)					");
	csTemp += _T("       END AS monthvalue						");
	csTemp += _T("  FROM cenergyconsumption						");
	csTemp += _T(" WHERE SUBSTR (productiondate, 1, 6) = '%s'	");
	csTemp += _T("   AND productiondate < '%s'					");
	csTemp += _T("   AND tagname = '%s'							");
											
	csSQL.Format(csTemp,cscurday.Left(6),cscurday,csTagName);
	if(!Query(csSQL,rsResult))
		return FALSE;

	if (rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		L3FLOAT lastmonthValue = rsResult.GetFieldByName(_T("MonthValue")).ToFloat();
		curmonthValue = lastmonthValue + todayValue;
	}
	else
		curmonthValue = todayValue;
	
	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="NewConsumption" type="L3BOOL">
/// 手工新增消耗数据
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CEnergy_Unit_Mag::NewConsumption(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return FALSE;

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	rs.MoveFirst();
	while (!rs.IsEOF())
	{
		COleDateTime currentTime = COleDateTime::GetCurrentTime();

		CString csProductionDate = rs.GetFieldByName(_T("ProductionDate")).ToCString();
		CString csTagName = rs.GetFieldByName(_T("TagName")).ToCString();
		
		if (csProductionDate == _T("") || csTagName == _T(""))
		{
			if(nTrans > 0) Rollback(nTrans);
				return FALSE;
		}
		
		CString csObjectID = csProductionDate + csTagName;
		L3FLOAT dayValue = 0;
		L3FLOAT monthValue = 0;
		L3FLOAT tagValue = 0;
		tagValue = rs.GetFieldByName(_T("TagValue")).ToFloat();
		dayValue = rs.GetFieldByName(_T("DayValue")).ToFloat();
		monthValue = rs.GetFieldByName(_T("MonthValue")).ToFloat();

		rs.SetFieldByName(_T("CreateTime"),CL3Variant(currentTime));
		rs.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		rs.SetFieldByName(_T("ObjectID"),CL3Variant(csObjectID));

	/*	int iyear,imonth,iday;
		try
		{
			iyear = _ttoi(csProductionDate.Mid(0,4));
			imonth = _ttoi(csProductionDate.Mid(4,2));
			iday = _ttoi(csProductionDate.Mid(6,2));
		}
		catch(...)
		{
	    	if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}

		COleDateTime curTime(iyear,imonth,iday,0,0,0);*/
		L3FLOAT caldayValue = 0;
		L3FLOAT calmonthValue = 0;

		CalculateValue(csProductionDate,csTagName,tagValue,caldayValue,calmonthValue);
		//if (dayValue < 1)
		rs.SetFieldByName(_T("DayValue"),CL3Variant(caldayValue));
		//if (monthValue < 1)
		rs.SetFieldByName(_T("MonthValue"),CL3Variant(calmonthValue));

		rs.MoveNext();
	}

	CL3RecordSetWrap rstemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\EnergyMag\\CEnergyConsumption"),rstemp))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rstemp.CopyFrom(rs);

	rstemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\EnergyMag\\CEnergyConsumption"),rstemp) < rstemp.GetRowCount())
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="UpdateConsumption" type="L3BOOL">
/// 手工修改消耗数据
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CEnergy_Unit_Mag::UpdateConsumption(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return FALSE;

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	rs.MoveFirst();
	while (!rs.IsEOF())
	{
		COleDateTime currentTime = COleDateTime::GetCurrentTime();

		CString csProductionDate = rs.GetFieldByName(_T("ProductionDate")).ToCString();
		CString csTagName = rs.GetFieldByName(_T("TagName")).ToCString();
		CString csObjectID = csProductionDate + csTagName;

		L3FLOAT dayValue = 0;
		L3FLOAT monthValue = 0;
		L3FLOAT tagValue = 0;

		tagValue = rs.GetFieldByName(_T("TagValue")).ToFloat();
		dayValue = rs.GetFieldByName(_T("DayValue")).ToFloat();
		monthValue = rs.GetFieldByName(_T("MonthValue")).ToFloat();

		rs.SetFieldByName(_T("ModifyTime"),CL3Variant(currentTime));
		rs.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		/*int iyear,imonth,iday;
		try
		{
			iyear = _ttoi(csProductionDate.Mid(0,4));
			imonth = _ttoi(csProductionDate.Mid(4,2));
			iday = _ttoi(csProductionDate.Mid(6,2));
		}
		catch(...)
		{
	    	if(nTrans > 0) Rollback(nTrans);
			return FALSE;
		}*/

		//COleDateTime curTime(iyear,imonth,iday,0,0,0);
		L3FLOAT caldayValue = 0;
		L3FLOAT calmonthValue = 0;

		CalculateValue(csProductionDate,csTagName,tagValue,caldayValue,calmonthValue);
		//if (dayValue < 1)
		rs.SetFieldByName(_T("DayValue"),CL3Variant(caldayValue));
		//if (monthValue < 1)
		rs.SetFieldByName(_T("MonthValue"),CL3Variant(calmonthValue));

		rs.MoveNext();
	}

	CL3RecordSetWrap rstemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\EnergyMag\\CEnergyConsumption"),rstemp))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}
	rstemp.CopyFrom(rs);

	rstemp.MoveFirst();
	if(!SetObjsPropValues(_T("XGMESLogic\\EnergyMag\\CEnergyConsumption"),rstemp))
	{
		if(nTrans > 0) Rollback(nTrans);
		return FALSE;
	}

	if(nTrans > 0) Commit(nTrans);

	return TRUE;
}

/// <Method class="CBF_Iron_Mag" name="QueryConsumptionInfo" type="L3RECORDSET">
/// 根据时间段和去向查旬能源消耗信息
/// <Param name="timeFrom" type="L3DATETIME">起始时间</Param>
/// <Param name="timeTo" type="L3DATETIME">结束时间</Param>
/// </Method>
L3RECORDSET CEnergy_Unit_Mag::QueryConsumptionInfo(L3DATETIME timeFrom, L3DATETIME timeTo)
{
	CString strSQL;
	strSQL.Format(_T("select * from CEnergyConsumption where (CreateTime between ? and ?)"));
	VARIANT params[2];
	params[0].vt = VT_DATE; params[0].date = timeFrom;
	params[1].vt = VT_DATE; params[1].date = timeTo;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,2,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(_T("XGMESLogic\\EnergyMag\\CEnergyConsumption"),rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
L3BOOL CEnergy_Unit_Mag::UpdateAODHeatid()
{
	CString strSQL;
	strSQL.Format(_T("select a.heatid,a.* from cplan_tapping a where bofid='S25' and status='10'"));
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return false;
	CString heatid,temp;
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
	  heatid=rs.GetFieldByName(_T("HeatID")).ToCString();
	  temp=_T("61")+heatid.Mid(2,7);
	  rs.SetFieldByName(_T("HeatID"),CL3Variant(temp));
	  rs.MoveNext();
	}
	rs.MoveFirst();
	if(!SetObjsPropValues(_T("XGMESLogic\\PlanMag\\CPlan_Tapping"),rs))
	{
	return false;
	}


	strSQL.Format(_T("select * from cplan_tapping_act  where bofid='S25' "));
	CL3RecordSetWrap rsact;
	if(!Query(strSQL,rsact))
		return false;
	
	rsact.MoveFirst();
	while(!rsact.IsEOF())
	{
	  heatid=rsact.GetFieldByName(_T("HeatID")).ToCString();
	  temp=_T("61")+heatid.Mid(2,7);
	  rsact.SetFieldByName(_T("HeatID"),CL3Variant(temp));
	  rsact.MoveNext();
	}
	rsact.MoveFirst();
	if(!SetObjsPropValues(_T("XGMESLogic\\PlanMag\\CPlan_Tapping_Act"),rsact))
	{
	return false;
	}


return true;

	/*	rsLog.MoveFirst();
		while(!rsLog.IsEOF())
		{
			rsLog.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
			rsLog.SetFieldByName(_T("Iron_Flag"),CL3Variant((LONG)1));
			rsLog.MoveNext();
		}*/
	//rsLog.MoveFirst();
	//	if(!SetObjsPropValues(SCRAP_OUT_CLASS_URI,rsLog))
	//	{
	//		if(nTrans > 0)
	//			Rollback(nTrans);
	//		return -13;
	//	}

	
}


L3LONG CEnergy_Unit_Mag::TappingPlanGen(L3RECORDSET rsCastingPlan)
{
	CL3RecordSetWrap rsCastPlan =rsCastingPlan;
    if( rsCastPlan.IsNull() || rsCastPlan.GetRowCount() < 1)
		return -1;


	//创建出钢计划记录集
	CL3RecordSetWrap rsTappingPlan;
	if(!CreateClassPropSet(_T("XGMESLogic\\PlanMag\\CPlan_Tapping"),rsTappingPlan)) 
		return -1;
	rsTappingPlan.AppendRecord();
	rsTappingPlan.MoveFirst();

	//创建出钢计划实绩记录集
	CL3RecordSetWrap rsTappingPlanActual;
	if(!CreateClassPropSet(_T("XGMESLogic\\PlanMag\\CPlan_Tapping_Act"),rsTappingPlanActual)) 
		return -1;
	rsTappingPlanActual.AppendRecord();
	rsTappingPlanActual.MoveFirst();


	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	//创建出钢计划实绩记录集
	CL3RecordSetWrap rsUnSchedulCastingPlan;
	if(!CreateClassPropSet(_T("XGMESLogic\\PlanMag\\CPlan_Casting"),rsUnSchedulCastingPlan)) 
		return -1;
	rsUnSchedulCastingPlan.DelField(_T("Status"));

	rsCastPlan.MoveFirst();
	
	L3LONG nPlanNum = 0;

	while(!rsCastPlan.IsEOF())
	{
		//判断浇钢计划的状态,如果已排产则继续下一炉
		CL3Variant vsPlaID = rsCastPlan.GetFieldByName(_T("PlanID"));
		if(!vsPlaID.IsValid() || vsPlaID.IsError() || vsPlaID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}

		CL3Variant vsBOFID = rsCastPlan.GetFieldByName(_T("BOFID"));
		if(!vsBOFID.IsValid() || vsBOFID.IsError() || vsBOFID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		CString csbofid=vsBOFID.ToString();
		if(csbofid!="S25")
		{
		rsCastPlan.MoveNext();
			continue;
		}


		CString csPlanID = vsPlaID.ToCString();
		CString csObjUri = _T("XGMESLogic\\PlanMag\\CPlan_Casting\\") + csPlanID;
		CL3Variant vsStatus = GetObjectPropValue(csObjUri,_T("Status"));
		if(!vsStatus.IsValid() || vsStatus.IsError() || vsStatus.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		CString csStatus = vsStatus.ToCString();
		if(csStatus != "10")
		{
			rsCastPlan.MoveNext();
			continue;
		}
		//判断出钢计划中此计划是否存在，若存在则继续下一炉
		CString csObjTappingUri = _T("XGMESLogic\\PlanMag\\CPlan_Tapping\\")  + csPlanID;
		CL3Variant vsPlanID = GetObjectPropValue(csObjTappingUri,_T("PlanID"));
		CString csIsExit = vsPlanID.ToCString();
		if(!csIsExit.IsEmpty())
		{
			rsCastPlan.MoveNext();
			continue;
		}

		////铸机号
		CL3Variant vsCasterID = GetObjectPropValue(csObjUri,_T("CasterID"));
		if(!vsCasterID.IsValid() || vsCasterID.IsError() || vsCasterID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -6;
		}
		CString csCasterID = vsCasterID.ToCString();

		//生成出钢计划相应内容
		rsTappingPlan.SetFieldByName(_T("PlanID"),CL3Variant(csPlanID));
		rsTappingPlan.SetFieldByName(_T("PreHeatID"), CL3Variant(csPlanID));
		rsTappingPlan.SetFieldByName(_T("CasterID"),rsCastPlan.GetFieldByName(_T("CasterID")));
		rsTappingPlan.SetFieldByName(_T("SteelGradeIndex"),rsCastPlan.GetFieldByName(_T("Pre_SteelGradeIndex")));
		//rsTappingPlan.SetFieldByName(_T("SteelGrade"),rsCastPlan.GetFieldByName(_T("Pre_SteelGrade")));
		rsTappingPlan.SetFieldByName(_T("Aim_Tapped_Weight"),rsCastPlan.GetFieldByName(_T("Aim_Tapped_Weight")));
		rsTappingPlan.SetFieldByName(_T("BOF_Status"),CL3Variant(_T("01")));
		rsTappingPlan.SetFieldByName(_T("RH_Status"),CL3Variant(_T("01")));
		rsTappingPlan.SetFieldByName(_T("LF_Status"),CL3Variant(_T("01")));
		rsTappingPlan.SetFieldByName(_T("Caster_Status"),CL3Variant(_T("01")));
		rsTappingPlan.SetFieldByName(_T("Side_Status"),CL3Variant(_T("01")));
		rsTappingPlan.SetFieldByName(_T("Pre_SteelGradeIndex"),rsCastPlan.GetFieldByName(_T("Pre_SteelGradeIndex")));
		rsTappingPlan.SetFieldByName(_T("Pre_SteelGrade"),rsCastPlan.GetFieldByName(_T("Pre_SteelGrade")));
		rsTappingPlan.SetFieldByName(_T("Plan_Ord_ID"),rsCastPlan.GetFieldByName(_T("Plan_Ord_ID")));
		rsTappingPlan.SetFieldByName(_T("Refine_Type"),rsCastPlan.GetFieldByName(_T("Refine_Type")));
		rsTappingPlan.SetFieldByName(_T("New_BOF_Flag"),rsCastPlan.GetFieldByName(_T("New_BOF_Flag")));
		rsTappingPlan.SetFieldByName(_T("Length"),rsCastPlan.GetFieldByName(_T("Length")));
		rsTappingPlan.SetFieldByName(_T("Width"),rsCastPlan.GetFieldByName(_T("Width")));
		rsTappingPlan.SetFieldByName(_T("Thickness"),rsCastPlan.GetFieldByName(_T("Thickness")));
		rsTappingPlan.SetFieldByName(_T("CreateDate"), COleDateTime::GetCurrentTime());
		rsTappingPlan.SetFieldByName(_T("Status"),CL3Variant(_T("10")));
		rsTappingPlan.SetFieldByName(_T("Planner"),CL3Variant(GetCurrentUser()));
		//2008-12-09新增
		rsTappingPlan.SetFieldByName(_T("LFID"),rsCastPlan.GetFieldByName(_T("LFID")));
		rsTappingPlan.SetFieldByName(_T("RHID"),rsCastPlan.GetFieldByName(_T("RHID")));
		rsTappingPlan.SetFieldByName(_T("BOFID"),rsCastPlan.GetFieldByName(_T("BOFID")));

		
		//用精练区分和铸机号确定RH\LF炉座,不经过设置为-1
		CL3Variant vsRefineType = rsCastPlan.GetFieldByName(_T("Refine_Type"));
		if(!vsRefineType.IsValid() || vsRefineType.IsError() || vsRefineType.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -10;
		}
		CString csRefineType = vsRefineType.ToCString();
		//铸机开浇时间
		CL3Variant vsCastignStart = rsCastPlan.GetFieldByName(_T("Aim_Time_CastingStart"));
		if(!vsCastignStart.IsValid() || vsCastignStart.IsError() || vsCastignStart.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -11;
		}
		L3DATETIME dtCastingStart = vsCastignStart.ToDateTime();

		L3DATETIME dtAim_IronPrepareTime = 0; //兑铁时间
		L3DATETIME dtAim_BOFProcessTime = 0;  //转炉处理时间
		L3DATETIME dtAim_LFWaitTime = 0; //LF等待时间
		L3DATETIME dtAim_RHWaitTime = 0; //RH等待时间
		L3DATETIME dtAim_LFProcessTime = 0;//LF炉处理时间
		L3DATETIME dtAim_RHProcessTime = 0;//RH炉处理时间
		L3DATETIME dtAim_CastWaitedTime = 0;//铸机等待时间
		L3DATETIME dtAim_CastingTime = 0;//浇注时间
		L3DATETIME dtAim_BOFSideTime = 0;//炉后处理时间
		L3DATETIME dtAim_Time_CastingEnd = 0;//浇注结束时刻
		L3DATETIME dtAim_Time_CasterArrival = 0;//大包到达时刻
		L3DATETIME dtAim_Time_RHArrival = 0;//RH进站时刻
		L3DATETIME dtAim_Time_RHLeave = 0;//RH出站时刻
		L3DATETIME dtAim_Time_RHEnd = 0;//RH处理结束时刻
		L3DATETIME dtAim_Time_RHStart = 0;//RH处理开始时刻
		L3DATETIME dtAim_Time_LFArrival = 0;//LF进站时刻
		L3DATETIME dtAim_Time_LFLeave = 0;//LF出站时刻
		L3DATETIME dtAim_Time_LFEnd = 0;//LF处理结束时刻
		L3DATETIME dtAim_Time_LFStart = 0;;//LF处理开始时刻
		L3DATETIME dtAim_Time_BOFSided = 0;//炉后F处理结束时刻
		L3DATETIME dtAim_Time_BOFTapped = 0;//出钢结束时刻
		L3DATETIME dtAim_Time_BOFStart = 0;//开吹时刻
		L3DATETIME dtAim_Time_IronPrepared = 0;//兑铁时刻

		//计算各工位处理时刻
		CString csTemp = _T("Select * from %s where SteelGradeIndex = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,_T("XGMESLogic\\QualityMag\\CQA_Unit_Proc_Time"),rsCastPlan.GetFieldByName(_T("Pre_SteelGradeIndex")).ToCString());
		CL3RecordSetWrap rsTime;
		if(!Query(csSQL,rsTime) || rsTime.IsNull() || rsTime.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -12;
		}
		rsTime.MoveFirst();
		//转炉
		CL3Variant vsTempTime  = rsTime.GetFieldByName(_T("BOF_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -13;
		}
		dtAim_BOFProcessTime = (vsTempTime.ToDateTime())/1440;
		//LF
		vsTempTime  = rsTime.GetFieldByName(_T("LF_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -14;
		}
		dtAim_LFProcessTime = (vsTempTime.ToDateTime())/1440;
		//RH
		vsTempTime  = rsTime.GetFieldByName(_T("RH_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -15;
		}
		dtAim_RHProcessTime = (vsTempTime.ToDateTime())/1440;
		//铸机
		vsTempTime  = rsTime.GetFieldByName(_T("Caster_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -16;
		}
		dtAim_CastingTime = (vsTempTime.ToDateTime())/1440;
		//炉后
		vsTempTime  = rsTime.GetFieldByName(_T("Tapped_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -17;
		}
		dtAim_BOFSideTime = (vsTempTime.ToDateTime())/1440;

		dtAim_IronPrepareTime = 5/1440;
		dtAim_CastWaitedTime  = 5/1440;
		dtAim_LFWaitTime = 5/1440;
		dtAim_RHWaitTime = 5/1440;


		//计算标准工艺时间
		dtAim_Time_CastingEnd = dtCastingStart + dtAim_CastingTime;
		dtAim_Time_CasterArrival = dtCastingStart - dtAim_CastWaitedTime;
		if(csRefineType == _T("0"))
		{
			dtAim_Time_RHArrival = 0;
			dtAim_Time_RHEnd = 0;
			dtAim_Time_RHStart = 0;
			dtAim_Time_RHLeave = 0;
			dtAim_Time_LFArrival = 0;
			dtAim_Time_LFEnd = 0;
			dtAim_Time_LFStart = 0;
			dtAim_Time_LFLeave = 0;
			dtAim_Time_BOFSided = dtAim_Time_CasterArrival;
		}
		else
		{
			if(csRefineType == _T("L"))
			{
				dtAim_Time_RHArrival = 0;
				dtAim_Time_RHEnd = 0;
				dtAim_Time_RHStart = 0;
				dtAim_Time_RHLeave = 0;
				dtAim_Time_LFLeave = dtAim_Time_CasterArrival;
				dtAim_Time_LFEnd = dtAim_Time_LFLeave - dtAim_LFWaitTime;
				dtAim_Time_LFStart = dtAim_Time_LFEnd - dtAim_LFProcessTime;
				dtAim_Time_LFArrival = dtAim_Time_LFStart - dtAim_LFWaitTime;
				dtAim_Time_BOFSided = dtAim_Time_LFArrival;
			}
			else
			{
				if(csRefineType == _T("R"))
				{
					dtAim_Time_LFArrival = 0;
					dtAim_Time_LFEnd = 0;
					dtAim_Time_LFStart = 0;
					dtAim_Time_LFLeave = 0;
					dtAim_Time_RHLeave = dtAim_Time_CasterArrival;
					dtAim_Time_RHEnd = dtAim_Time_RHLeave - dtAim_RHWaitTime;
					dtAim_Time_RHStart = dtAim_Time_RHEnd - dtAim_RHProcessTime;
					dtAim_Time_RHArrival = dtAim_Time_RHStart - dtAim_RHWaitTime;
					dtAim_Time_BOFSided = dtAim_Time_RHArrival;

				}
				else
				{
					if(csRefineType == _T("LR"))
					{
						dtAim_Time_RHLeave = dtAim_Time_CasterArrival;
						dtAim_Time_RHEnd = dtAim_Time_RHLeave - dtAim_RHWaitTime;
						dtAim_Time_RHStart = dtAim_Time_RHEnd - dtAim_RHProcessTime;
						dtAim_Time_RHArrival = dtAim_Time_RHStart - dtAim_RHWaitTime;
						dtAim_Time_LFLeave = dtAim_Time_RHArrival;
						dtAim_Time_LFEnd = dtAim_Time_LFLeave - dtAim_LFWaitTime;
						dtAim_Time_LFStart = dtAim_Time_LFEnd - dtAim_LFProcessTime;
						dtAim_Time_LFArrival = dtAim_Time_LFStart - dtAim_LFWaitTime;
						dtAim_Time_BOFSided = dtAim_Time_LFArrival;

					}
					else
					{
						dtAim_Time_LFLeave = dtAim_Time_CasterArrival;
						dtAim_Time_LFEnd = dtAim_Time_LFLeave - dtAim_LFWaitTime;
						dtAim_Time_LFStart = dtAim_Time_LFEnd - dtAim_LFProcessTime;
						dtAim_Time_LFArrival = dtAim_Time_LFStart - dtAim_LFWaitTime;
						dtAim_Time_RHLeave = dtAim_Time_LFArrival;
						dtAim_Time_RHEnd = dtAim_Time_RHLeave - dtAim_RHWaitTime;
						dtAim_Time_RHStart = dtAim_Time_RHEnd - dtAim_RHProcessTime;
						dtAim_Time_RHArrival = dtAim_Time_RHStart - dtAim_RHWaitTime;
						dtAim_Time_BOFSided = dtAim_Time_RHArrival;
					}

				}
			}

		}
		//dtAim_Time_BOFSided = dtAim_Time_LFStart;
		dtAim_Time_BOFTapped = dtAim_Time_BOFSided - dtAim_BOFSideTime;
		dtAim_Time_BOFStart = dtAim_Time_BOFTapped - dtAim_BOFProcessTime;
		dtAim_Time_IronPrepared = dtAim_Time_BOFStart - dtAim_IronPrepareTime;
		//对出钢计划工序处理时刻赋值
		rsTappingPlan.SetFieldByName(_T("Aim_Time_CastingEnd"), dtAim_Time_CastingEnd);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_CastingStart"), dtCastingStart);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_CasterArrival"), dtAim_Time_CasterArrival);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_RHLeave"), dtAim_Time_RHLeave);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_RHEnd"), dtAim_Time_RHEnd);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_RHStart"), dtAim_Time_RHStart);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_RHArrival"), dtAim_Time_RHArrival);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_LFLeave"), dtAim_Time_LFLeave);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_LFEnd"), dtAim_Time_LFEnd);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_LFStart"), dtAim_Time_LFStart);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_LFArrival"), dtAim_Time_LFArrival);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_TappedSideEnd"), dtAim_Time_BOFSided);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_BOFTapped"), dtAim_Time_BOFTapped);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_BOFStart"), dtAim_Time_BOFStart);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_IronPrepared"), dtAim_Time_IronPrepared);


		//计算处理顺序号
		csTemp = _T( " select  max(Treat_Seq) from %s where CasterID = '%s' and to_char(CreateDate,'yyyy') = to_char(sysdate,'yyyy') " );
		csSQL.Format(csTemp,_T("XGMESLogic\\PlanMag\\CPlan_Tapping"),csCasterID);
		CL3RecordSetWrap rsTreatSeq;
		if ((!Query(csSQL,rsTreatSeq)))
		{
			rsCastPlan.MoveNext();
			continue;
		}
		rsTreatSeq.MoveFirst();
		CL3Variant valTemp = rsTreatSeq.GetFieldByIndex(0);
		CString csMaxTreatSeq = valTemp.ToCString();
		L3LONG nMaxTreatSeq;
		if (csMaxTreatSeq.IsEmpty())
			nMaxTreatSeq =0;
		else
		{
			CString csSeq = csMaxTreatSeq.Mid(2,5);
			//nMaxTreatSeq = csSeq.ToShort();
			nMaxTreatSeq = _ttol(csSeq);	
		}
		nMaxTreatSeq++;
		CString csTempTreatSeq;
		csTempTreatSeq.Format(_T("%05d"), nMaxTreatSeq);
		COleDateTime odtCurrentDate = COleDateTime::GetCurrentTime();
		CString cstrCurrentDate = odtCurrentDate.Format(_T("%Y"));
		CString csTreatSeq =cstrCurrentDate.Mid(2,2) + csTempTreatSeq;

		rsTappingPlan.SetFieldByName(_T("Treat_Seq"), CL3Variant(csTreatSeq));
		//班别班次
		CL3Variant valR = InvokeObjectMethod(_T("XGMESLogic\\ShiftTeamMag\\CShiftMag\\1"),_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
		rpSysInfo.MoveFirst();

		rsTappingPlan.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsTappingPlan.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));


		//2008-12-09新增以下代码
		//创建出钢计划实绩记录集
		//重新生成出钢计划实绩,并且计算熔炼号、工序处理号

		//得到预定炉号
		rsTappingPlanActual.SetFieldByName(_T("PreHeatID"), CL3Variant(csPlanID));
		rsTappingPlanActual.SetFieldByName(_T("CasterID"),rsCastPlan.GetFieldByName(_T("CasterID")));
		rsTappingPlanActual.SetFieldByName(_T("LFID"),rsCastPlan.GetFieldByName(_T("LFID")));
		rsTappingPlanActual.SetFieldByName(_T("RHID"),rsCastPlan.GetFieldByName(_T("RHID")));
		rsTappingPlanActual.SetFieldByName(_T("BOFID"),rsCastPlan.GetFieldByName(_T("BOFID")));

		//得到熔炼号
		CL3RecordSetWrap rsMaxProcessNo;
	CString csSQL2=_T("select max(heatid) from cplan_tapping_act  a where bofid='S25' and to_char(CreateDate,'yyyy') = to_char(sysdate,'yyyy')");
    if ((!Query(csSQL2,rsMaxProcessNo)))
		return 0;

	//L3LONG lMaxProcessNo = 0;
	rsMaxProcessNo.MoveFirst();
	CL3Variant valTemp2 = rsMaxProcessNo.GetFieldByIndex(0);
	CString cstrTemp = valTemp2.ToCString();
	CString csHeatID;
	long lTemp;
	CString csTempHeatID;
	if(cstrTemp.IsEmpty())
	{
	lTemp=1;
	csTempHeatID.Format(_T("%05d"),lTemp);
	csHeatID =_T("61")  + cstrCurrentDate.Mid(2,2) + csTempHeatID;
	rsTappingPlanActual.SetFieldByName(_T("HeatID"), CL3Variant(csHeatID));
	rsTappingPlan.SetFieldByName(_T("HeatID"), CL3Variant(csHeatID));
	}
	else
	{
	lTemp = rsMaxProcessNo.GetFieldByIndex(0).ToLong() + 1;
	rsTappingPlanActual.SetFieldByName(_T("HeatID"), CL3Variant(lTemp));
	rsTappingPlan.SetFieldByName(_T("HeatID"), CL3Variant(lTemp));
	
	}
		
	/*CL3Variant valTemp = rsMaxProcessNo.GetFieldByIndex(0);*/

		L3SHORT nUnitType = 2;
		CString csBOFID =  rsCastPlan.GetFieldByName(_T("BOFID")).ToCString();
		/*long lTemp = rsMaxProcessNo.GetFieldByIndex(0).ToLong() + 1;	*/	//循环次数为i + 1
		//CString csTempHeatID;
		//csTempHeatID.Format(_T("%05d"),lTemp);	//不足5位的前面补0
		//CString csHeatID;
		/*if(csBOFID=="S25")
		{
		csHeatID =_T("61")  + cstrCurrentDate.Mid(2,2) + lTemp.Mid(3,5);
		}
		else
		{
		 csHeatID =_T("2") + csBOFID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempHeatID;
		}*/
		/*CString csHeatID =_T("2") + csBOFID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempHeatID;*/
		/*rsTappingPlanActual.SetFieldByName(_T("HeatID"), CL3Variant(csHeatID));*/
		
		//初始化处理号为零2008-12-30 tangyi
		rsTappingPlanActual.SetFieldByName(_T("LF_TreatNo"), CL3Variant(_T("")));
		rsTappingPlanActual.SetFieldByName(_T("RH_TreatNo"),CL3Variant(_T("")));
		rsTappingPlanActual.SetFieldByName(_T("Caster_TreatNo"), CL3Variant(_T("")));
		rsTappingPlanActual.SetFieldByName(_T("CreateDate"), COleDateTime::GetCurrentTime());

		//创建出钢计划
		if(CreateNewObjects(_T("XGMESLogic\\PlanMag\\CPlan_Tapping"),L3RECORDSET(rsTappingPlan)) < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -18;
		}
		//创建对象CHeatTappingPlanActualData
		if (CreateNewObjects(_T("XGMESLogic\\PlanMag\\CPlan_Tapping_Act"),rsTappingPlanActual) < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -26;
		}	
		//更改浇钢计划状态
		if(!SetObjectPropValue(csObjUri,_T("Status"),CL3Variant(_T("11"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -19;
		}
		//更改计划订单状态
		CString csObjPlanOrdUri = _T("XGMESLogic\\PlanMag\\CPlan_Order\\")  + rsCastPlan.GetFieldByName(_T("Plan_Ord_ID")).ToCString();
		if(!SetObjectPropValue(csObjPlanOrdUri,_T("Status"),CL3Variant(_T("14"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -20;
		}

		//2009-05-27 计算工序间移动时间
		/*CalcUnitOneToOneTime(csPlanID);*/
  CL3Variant valResult = InvokeObjectMethod(_T("XGMESLogic\\PlanMag\\CPlan_Mag\\Plan_Mag"),_T("CalcUnitOneToOneTime"),csPlanID);
	/*if(!valResult.IsValid()||!valResult.ToBOOL())
		return -21;*/



		rsUnSchedulCastingPlan.AppendRecord();
		rsUnSchedulCastingPlan.CopyCurRowFrom(rsCastPlan);
		nPlanNum++;
		rsTappingPlan.MoveFirst();
		rsTappingPlanActual.MoveFirst();
		rsCastPlan.MoveNext();
	}

	//回执浇钢计划信息（转炉、精炼）2008-12-24
	if(nPlanNum > 0)
	{
		if(!SetObjsPropValues(_T("XGMESLogic\\PlanMag\\CPlan_Casting"),rsUnSchedulCastingPlan))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -27;
		}
	}


	if(bUseTrans)
		Commit(nTrans);

	CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\PlanMag\\CPlan_Mag\\Plan_Mag"),_T("ChangeRsTappingPlanValue"));
	//return -29;

	/*ChangeRsTappingPlanValue();*/
	if(nPlanNum ==0) return -28; else return 0;// TODO : 请在此添加逻辑代码
}




L3LONG CEnergy_Unit_Mag::NewCastingPlanGen(L3RECORDSET rsPlan,L3STRING strSteelGradeIndex)
{

	CL3RecordSetWrap rsPlanOrd =rsPlan;
    if( rsPlanOrd.IsNull() || rsPlanOrd.GetRowCount() < 1)
		return -1;

	if( rsPlanOrd.GetFieldIndex(_T("PlanID")) < 0 ||
		rsPlanOrd.GetFieldIndex(_T("CasterID")) < 0 ||
		rsPlanOrd.GetFieldIndex(_T("SpareWeight")) < 0)
		return -1;

	CString csSteelGradeIndex=strSteelGradeIndex;
	csSteelGradeIndex=csSteelGradeIndex.Trim();
	if (strSteelGradeIndex==_T(""))
		return -1;

    //2016-1-1 修改，此检查没有意思，选择炼钢记号时，已检查过。
	//检查炼钢记号是否存在并处于使用状态  
	//CString csTemp = _T(" SELECT *  FROM %s  where  STEELGRADEINDEX = '%s' and USE_FLAG='0' ");	
	//CString strSQL;
	//strSQL.Format(csTemp,QA_STG_RELATION_CLASS_URI,csSteelGradeIndex);
	//CL3RecordSetWrap rsSteelGradeIndex ;
	//BOOL bRet = Query(strSQL,rsSteelGradeIndex);		
	//if(!bRet || rsSteelGradeIndex.IsNull() || rsSteelGradeIndex.GetRowCount() < 1)
	//{
	//		return -1;
	//}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	rsPlanOrd.MoveFirst();
	while(!rsPlanOrd.IsEOF())
	{
		//判断余量是否满足要求
		CL3Variant vsSteelWeight = rsPlanOrd.GetFieldByName(_T("SpareWeight"));
		if(!vsSteelWeight.IsValid() || vsSteelWeight.IsError() || vsSteelWeight.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}	
		L3DOUBLE dSteelWeight = vsSteelWeight.ToDouble();
		if(dSteelWeight * 1000 <= 10000)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -18;
		}
		//获取代表炼钢记号
		CL3Variant vsSteelGrade = rsPlanOrd.GetFieldByName(_T("SteelGrade"));
		if(!vsSteelGrade.IsValid() || vsSteelGrade.IsError() || vsSteelGrade.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;
		}
		CString csSteelGradeOfOrd = vsSteelGrade.ToCString();
		//CL3Variant vsProtocol = rsPlanOrd.GetFieldByName(_T("Protocol"));
		//CString csProtocol = vsProtocol.ToCString();
		////2009-01-15 tangyi 添加物料编码
		//CL3Variant vsMaterialCode = rsPlanOrd.GetFieldByName(_T("MaterialCode"));
		//if(!vsMaterialCode.IsValid() || vsMaterialCode.IsError() || vsMaterialCode.IsNull())
		//{
		//	if(bUseTrans)
		//		Rollback(nTrans);
		//	return -19;
		//}
		//CString csMaterialCode = vsMaterialCode.ToCString();
		//CString csSteelGradeIndex = GetSteelGradeIndexBySteelGrade(csSteelGrade,csProtocol,csMaterialCode);
		//if(csSteelGradeIndex == EMPTY_ERR)
		//{	
		//	if(bUseTrans)
		//		Rollback(nTrans);
		//	return -3;
		//}



		//2016-1-1 修改 没有意思
		//判断订单钢种与选定的炼钢记号中的钢种是否一致
	/*	if(rsSteelGradeIndex.GetFieldByName(_T("SteelGrade")).ToCString()!=csSteelGradeOfOrd)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;
		}*/

		//判断分配的铸机号是否合法
		CL3Variant vsCasterID = rsPlanOrd.GetFieldByName(_T("CasterID"));
		if(!vsCasterID.IsValid() || vsCasterID.IsError() || vsCasterID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		
		CString csCasterID = vsCasterID.ToCString();
		CString csMaterialCode=rsPlanOrd.GetFieldByName(_T("MaterialCode")).ToString();
		/*屏蔽 by hyh 2012-06-07
		csMaterialCode=csMaterialCode.Mid(0,3);
		if(csMaterialCode==_T("609"))
		{
			if(csCasterID!=_T("S66"))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
		}
		if(csCasterID==_T("S66"))
		{
			if(csMaterialCode!=_T("609"))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
		}
		屏蔽结束*/

		CString csProdSheetUri = QA_PROD_SHEET_CLASS_URI + _T("\\") + csSteelGradeIndex;
		L3LONG	nCasterType = GetObjectPropValue(csProdSheetUri,_T("Caster_Type")).ToLong();	
		L3LONG  nCasterUnitID = _ttol(csCasterID.Mid(2,1));
		switch(nCasterType)
		{
			case NoLFCaster:
				//2009-01-17 tangyi
				if (nCasterUnitID > 7 || nCasterUnitID < 1) 		
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			case OldLFCaster:
				if (nCasterUnitID > 4 || nCasterUnitID < 3) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			case NewLFCaster:
				if (nCasterUnitID < 5||nCasterUnitID>5) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			//Modify begin 2011-02-15 llj
			case NewLFCaster6:
				if (nCasterUnitID < 6||nCasterUnitID>6) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			case NewLFCaster7:
				if (nCasterUnitID < 7) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			//Modify end
			default:
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -6;
				};
		}
		L3SHORT nBOFFlag = 0;
		L3LONG	nBOFType = GetObjectPropValue(csProdSheetUri,_T("BOF_Type")).ToLong();
		switch(nBOFType)
		{
			case BOF50t: nBOFFlag = nOldBOF;
				break;
			case BOF80t: nBOFFlag = nNewBOF;
				break;
			default:
				// 2016-1-1 增加 nBOFFlag = nOldBOF;一句
				 nBOFFlag = nOldBOF;
				break;
		}	
		//计算炉次
		
		L3LONG nSteelLadleCount = CalculateHeatCount(nBOFFlag,dSteelWeight);
		//生成浇钢计划
		L3LONG nBackValue = GenCastingPlanOfSpecifyCasterID(csCasterID,
			                                                L3RECORDSET(rsPlanOrd),
															nSteelLadleCount,
															csSteelGradeIndex,
															dSteelWeight,
															nBOFFlag);
		if(nBackValue < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return nBackValue;
		}
		//更改计划订单状态
		CL3Variant vsPlanID = rsPlanOrd.GetFieldByName(_T("PlanID"));
		if(!vsPlanID.IsValid() || vsPlanID.IsError() || vsPlanID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -16;
		}
		CString csPlanID = vsPlanID.ToCString();
		CString csStatus = GetObjectPropValue(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID,_T("Status")).ToCString();
		if(csStatus ==PLAN_ORDER_STATUS_UNINTEGRATE)
		{
			if(!SetObjectPropValue(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_CASTING)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -17;
			}	
		}
		rsPlanOrd.MoveNext();
	}


	if(bUseTrans)
		Commit(nTrans);

	return 0;// TODO : 请在此添加逻辑代码
}



L3LONG CEnergy_Unit_Mag::GenCastingPlanOfSpecifyCasterID(CString csCasterID,L3RECORDSET rsPlanOrder,L3LONG nHeatCount,CString csSteelGradeIndex,L3DOUBLE fWeight,L3SHORT nBOFFlag)
{
	CL3RecordSetWrap rsPlanOrd =rsPlanOrder;
	L3DOUBLE fTotalWeight = fWeight*1000;



	//2008-12-24 tangyi计划订单实际投用量增加、余量减少
	CString csPlanID = rsPlanOrd.GetFieldByName(_T("PlanID")).ToCString();
	CString csPlanOrderUri = PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID;
	CL3Variant vsPlanOrderCurSpareWeight = GetObjectPropValue(csPlanOrderUri,_T("SpareWeight"));
	if(!vsPlanOrderCurSpareWeight.IsValid() || vsPlanOrderCurSpareWeight.IsError() || vsPlanOrderCurSpareWeight.IsNull())
		return -1;

	L3DOUBLE fPlanOrderSpareWeight = vsPlanOrderCurSpareWeight.ToDouble();
	if((fPlanOrderSpareWeight - fWeight) < 0)
		return -81;//余量不足
	CL3Variant vsPlanOrderCurActWeight = GetObjectPropValue(csPlanOrderUri,_T("ActWeight"));
	if(!vsPlanOrderCurActWeight.IsValid() || vsPlanOrderCurActWeight.IsError() || vsPlanOrderCurActWeight.IsNull())
		return -1;

	L3DOUBLE fPlanOrderActWeight = vsPlanOrderCurActWeight.ToDouble();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	L3DOUBLE fCurSpareWeight = fPlanOrderSpareWeight - fWeight;
	if(!SetObjectPropValue(csPlanOrderUri,_T("SpareWeight"),CL3Variant(fCurSpareWeight)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -82;
	}
	L3DOUBLE fCurActWeight = fPlanOrderActWeight + fWeight;
	if(!SetObjectPropValue(csPlanOrderUri,_T("ActWeight"),CL3Variant(fCurActWeight)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -83;
	}
	//2009-01-10 手动添加协议
	if(!SetObjectPropValue(csPlanOrderUri,_T("Protocol"),rsPlanOrd.GetFieldByName(_T("Protocol"))))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -99;
	}

	CL3RecordSetWrap rsCastingPlan;
	if(!CreateClassPropSet(PLAN_CASTING_CLASS_URI,rsCastingPlan)) 
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -84;
	}
	rsCastingPlan.AppendRecord();
	//rsPlanOrd.MoveFirst();不能移动该记录集的指针

	for(int i=0;i<nHeatCount;i++)
	{
		//rsCastingPlan.CopyCurRowFrom(rsPlanOrd);
		//生成预定炉号
		CL3Variant vsYear = GetObjectPropValue(PLAN_CUR_PREHEATID_CLASS_URI + _T("\\") + csCasterID,_T("Year"));
		if(!vsYear.IsValid() || vsYear.IsError() || vsYear.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -85;
		}
		CString csYear = vsYear.ToCString();
		CL3Variant vsPreHeatID = GetObjectPropValue(PLAN_CUR_PREHEATID_CLASS_URI + _T("\\") + csCasterID,_T("Cur_PreHeatID"));
		if(!vsPreHeatID.IsValid() || vsPreHeatID.IsError() || vsPreHeatID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -86;
		}
		L3LONG nPreHeatID = vsPreHeatID.ToLong();
		nPreHeatID++;
		CString csTempPreHeaID;
		csTempPreHeaID.Format(_T("%06d"),nPreHeatID);
		CString csPreHeatID = csYear + csCasterID + csTempPreHeaID;
		if(!SetObjectPropValue(PLAN_CUR_PREHEATID_CLASS_URI + _T("\\") + csCasterID,_T("Cur_PreHeatID"),CL3Variant(nPreHeatID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -87;
		}
		//生成浇钢计划其它信息
		rsCastingPlan.SetFieldByName(_T("PlanID"),CL3Variant(csPreHeatID));
		rsCastingPlan.SetFieldByName(_T("PreHeatID"),CL3Variant(csPreHeatID));
		rsCastingPlan.SetFieldByName(_T("Pre_SteelGradeIndex"),CL3Variant(csSteelGradeIndex));
		rsCastingPlan.SetFieldByName(_T("CasterID"),CL3Variant(csCasterID));
		rsCastingPlan.SetFieldByName(_T("Length"),rsPlanOrd.GetFieldByName(_T("Length")));
		rsCastingPlan.SetFieldByName(_T("Width"),rsPlanOrd.GetFieldByName(_T("Width")));
		rsCastingPlan.SetFieldByName(_T("Thickness"),rsPlanOrd.GetFieldByName(_T("Thickness")));
		rsCastingPlan.SetFieldByName(_T("Pre_SteelGrade"),rsPlanOrd.GetFieldByName(_T("SteelGrade")));
		rsCastingPlan.SetFieldByName(_T("Plan_Ord_ID"),rsPlanOrd.GetFieldByName(_T("PlanID")));
		rsCastingPlan.SetFieldByName(_T("New_BOF_Flag"),CL3Variant(nBOFFlag));
		//计划状态为未排产
		rsCastingPlan.SetFieldByName(_T("Status"),CL3Variant(CASTING_PLAN_STATUS_UNSCHEDULING));

		//更据铸机号获取最优工艺路径
		CString csTemp = _T("Select * from %s where CasterID = '%s' and Lev_Type = 1 ");
		CString csSQL;
		csSQL.Format(csTemp,QA_UNIT_ROUTE_CLASS_URI,csCasterID);
		CL3RecordSetWrap rsRoute;
		if(!Query(csSQL,rsRoute) || rsRoute.IsNull() || rsRoute.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -89;
		}
		rsRoute.MoveFirst();
		//得到RH炉座
		CL3Variant vsRHID = rsRoute.GetFieldByName(_T("RHID"));
		if(!vsRHID.IsValid() || vsRHID.IsError() || vsRHID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -90;
		}
		CString csRHID = vsRHID.ToCString();
		
		//得到LF炉座
		CL3Variant vsLFID = rsRoute.GetFieldByName(_T("LFID"));
		if(!vsLFID.IsValid() || vsLFID.IsError() || vsLFID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -91;
		}
		CString csLFID = vsLFID.ToCString();
		

		//得到转炉炉座
		CL3Variant vsBOFID = rsRoute.GetFieldByName(_T("BOFID"));
		if(!vsBOFID.IsValid() || vsBOFID.IsError() || vsBOFID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -92;
		}
		CString csBOFID = vsBOFID.ToCString();
		

		//获取精炼区分
		CL3Variant vsLFType = GetObjectPropValue(QA_PROD_SHEET_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("LF_Type"));
		if(!vsLFType.IsValid() || vsLFType.IsError() || vsLFType.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -93;
		}
		CString csLFType = vsLFType.ToCString();
		CL3Variant vsRHType = GetObjectPropValue(QA_PROD_SHEET_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("RH_Type"));
		if(!vsRHType.IsValid() || vsRHType.IsError() || vsRHType.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -94;
		}
		CString csRHType = vsRHType.ToCString();
		//2009-04-20 tangyi 获取NC工艺路径
		CString csRoute = rsPlanOrd.GetFieldByName(_T("Product_Route")).ToCString();
		//根据精炼区分得到炉座号，防止最优工艺路径维护错误加保护2009-03-30，
		//工艺路径是由冶金规范确定的，最优工艺路径只是参考
		
		/*屏蔽开始 by hyh 2012-05-17
		//Modify begin by llj 2011-03-21 为管理到不锈钢厂的炉次信息,防止NC计划出现错误 
		if(csCasterID == _T("S66"))
		{//确保到不锈钢铸机的计划不经过LF和RH机组
			csLFType == _T("01");
			csRHType == _T("01");
		}
		//Modify end
		屏蔽结束*/

		if(csLFType == _T("01") && csRHType == _T("01"))//不经过LF及RH
		{
			rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(_T("0")));
			rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(_T("0")));
			rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("0")));
		}
		if(csLFType == _T("01") && csRHType != _T("01"))//不经过LF，经过RH
		{
			rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(_T("0")));
			csRHID =_T("S51");
			rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(csRHID));
			rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("R")));
		}
		if(csLFType != _T("01") && csRHType == _T("01"))//经过LF，但不经过RH
		{
			if(csCasterID == _T("S65")) csLFID = _T("S43");//铸机是5#铸机，必须经过3#LF
			if((csLFID == _T("0") || csLFID == _T("S43")) && csCasterID != _T("S65")) csLFID = _T("S41");//LF未确定或者3#LF，并且是5#铸机，必须经过1#LF
			rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(csLFID));
			rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(_T("0")));
			rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("L")));
		}
		if(csLFType != _T("01") && csRHType != _T("01"))//经过LF，经过RH
		{
			csRHID = _T("S51");
			csLFID = _T("S43");
			rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(csLFID));
			rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(csRHID));
			if(csRoute == _T("BRL"))
				rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("RL")));
			else
				rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("LR")));
		}
		//if(csLFType == _T("2") && csRHType == _T("2"))
		//{
		//	rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(csLFID));
		//	rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(csRHID));
		//	rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("RL")));
		//}
	   if(nBOFFlag == nNewBOF)
		   csBOFID =_T("S24");
	   else
		  if((csBOFID == _T("S24")) && csCasterID != _T("S65")) csBOFID = _T("S21");

		rsCastingPlan.SetFieldByName(_T("BOFID"),CL3Variant(csBOFID));

		//生成目标出钢量
		L3DOUBLE fLadleWeight = 0;
		if(nBOFFlag == 1) fLadleWeight = NEW_LADLE_WEIGHT;else fLadleWeight = OLD_LADLE_WEIGHT;
		rsCastingPlan.SetFieldByName(_T("Aim_Tapped_Weight"),CL3Variant(fLadleWeight/1000));
		//生成实际投放量 2008-12-24
		fTotalWeight = fTotalWeight - fLadleWeight;
		if(fTotalWeight <= 10000)
			rsCastingPlan.SetFieldByName(_T("ActWeight"),CL3Variant((fTotalWeight + fLadleWeight)/1000));
		else
			rsCastingPlan.SetFieldByName(_T("ActWeight"),CL3Variant(fLadleWeight/1000));
			

		//计算钢坯枝数
		CL3Variant vsLength = rsPlanOrd.GetFieldByName(_T("Length"));
		if(!vsLength.IsValid() || vsLength.IsError() || vsLength.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -95;
		}
		CString csLength = vsLength.ToCString();
		//大方坯按照钢种管理2009-03-12 tangyi
		CString csSteelGrade = rsPlanOrd.GetFieldByName(_T("SteelGrade")).ToCString();
		CString csObjectID; 
		//2016-1-1 修改，不锈钢也是按照此精品钢计算重量
		if((csSteelGradeIndex.Mid(0,1) ==_T("J"))||((csSteelGradeIndex.Mid(0,1) ==_T("B"))))
			csObjectID = csLength + csSteelGrade;
		else 
			csObjectID = csLength;
		CL3Variant vsCalWeight = GetObjectPropValue(QA_CAL_WEIGHT_CLASS_URI + _T("\\") + csObjectID,_T("Weight"));
		if(!vsCalWeight.IsValid() || vsCalWeight.IsError() || vsCalWeight.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -96;
		}
		L3DOUBLE dCalWeight = vsCalWeight.ToDouble();
		L3LONG nCalWeight =int(dCalWeight*1000);
		L3LONG nLadleWeight = 0;
		if(nBOFFlag == 1) nLadleWeight = NEW_LADLE_WEIGHT;else nLadleWeight = OLD_LADLE_WEIGHT;
		L3LONG nBloomCount = nLadleWeight/nCalWeight;
		if(nLadleWeight % nCalWeight > 0)
			nBloomCount++;
		rsCastingPlan.SetFieldByName(_T("Bloom_Count"),CL3Variant(nBloomCount));
		//计划创建时间
		COleDateTime timeNow = COleDateTime::GetCurrentTime();
		rsCastingPlan.SetFieldByName(_T("CreateDate"),CL3Variant(timeNow));
		rsCastingPlan.SetFieldByName(_T("Planner"),CL3Variant(GetCurrentUser()));
		//计算计划开浇时间
		L3DATETIME dtCastingTime;
		if(CalculateCastingTime(csCasterID,csSteelGradeIndex,dtCastingTime) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -97;
		}
		
		rsCastingPlan.SetFieldByName(_T("Aim_Time_CastingStart"),CL3Variant(dtCastingTime));
		//计算浇钢时间所以把创建记录放入循环内
		if(CreateNewObjects(PLAN_CASTING_CLASS_URI,L3RECORDSET(rsCastingPlan)) < rsCastingPlan.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -98;
		}
		rsCastingPlan.MoveFirst();
	}

	
	if(bUseTrans)
		Commit(nTrans);
	return 0;
}

L3LONG CEnergy_Unit_Mag::CalculateHeatCount(L3SHORT nBOFFlag,L3DOUBLE dWeight)
{
	L3LONG nWeight = int((dWeight*1000));
	L3LONG nSteelLadleCount = 0;
	L3LONG nBalanceWeight =0;
	L3LONG nLadleWeight =0;
	if(nBOFFlag == 0) nLadleWeight = OLD_LADLE_WEIGHT; else nLadleWeight = NEW_LADLE_WEIGHT;

	nSteelLadleCount = nWeight/ nLadleWeight;
	nBalanceWeight = nWeight % nLadleWeight;
	if(nBalanceWeight > 10000)
		nSteelLadleCount++;

	return nSteelLadleCount;

}

L3LONG CEnergy_Unit_Mag::CalculateCastingTime(CString csCasterID,CString csSteelGradeIndex,L3DATETIME &dtCastingTime)
{
	L3DATETIME dtPreCastingTime;
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csTemp = _T(" SELECT Max(Aim_Time_CastingStart)  FROM %s  where  CasterID = '%s' ");	
	CString strSQL;
	strSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,csCasterID);
	CL3RecordSetWrap rsResult;
	BOOL bRet = Query(strSQL,rsResult);
	if(!bRet || rsResult.IsNull()|| rsResult.GetRowCount() < 1)
		L3DATETIME dtPreCastingTime=timeNow;
	else
	{
		rsResult.MoveFirst();
		CL3Variant vsPreCastingStartTime = rsResult.GetFieldByIndex(0);
		dtPreCastingTime = vsPreCastingStartTime.ToDateTime();
		//L3DOUBLE nTime = difftime(timeNow,dtPreCastingTime)*24;//2009-02-12 tangyi
		//2009-04-6 
		L3DATETIME dtNow = timeNow;
		COleDateTimeSpan span = dtNow - dtPreCastingTime;
		L3DOUBLE nTime =  abs((LONG)span.GetTotalHours());
		if(dtPreCastingTime <= 0 || nTime > 30)
		dtPreCastingTime=timeNow;
	}
	//Modify begin by llj 2011-04-26 送不锈钢钢水计划的浇铸时间为当前时间
	dtPreCastingTime=timeNow;
	//Modify end
	//根据炼钢记号得到浇注时间
	CL3Variant vsStdCastingTime = GetObjectPropValue(QA_UNIT_PROC_TIME_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("Caster_Proc_Time"));
	if(!vsStdCastingTime.IsValid() || vsStdCastingTime.IsError() || vsStdCastingTime.IsNull())
		return -2;
	L3DATETIME dtProcessTime = vsStdCastingTime.ToDateTime();
	dtCastingTime = dtPreCastingTime + dtProcessTime/1440;
	return 0;

}

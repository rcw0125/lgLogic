// 逻辑类CEquip_Unit_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CEquip_Unit_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CEquip_Unit_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CEquip_Unit_Mag.h"

//当对象被装载到系统中时，被调用
void CEquip_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CEquip_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <Method class="CEquip_Unit_Mag" name="NewCalibration" type="L3LONG">
/// 新增校准基本信息 2009-04-06
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CEquip_Unit_Mag::NewCalibration(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	L3LONG rscount = rs.GetRowCount();
	if (rscount < 1)
	{
		return -1;
	}

	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\EquipMag\\CCalibration_Log"),rsLog))
	{
		return -2;
	}

	rsLog.CopyFrom(rs);

	//准备铁水数据
	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		CString csLocation = rsLog.GetFieldByName(_T("Location")).ToCString();
		COleDateTime dLogDate = rsLog.GetFieldByName(_T("Check_Date")).ToDateTime();
		CString csLogDate = dLogDate.Format(_T("%Y%m%d%H%M%S"));
		if (csLocation.GetLength() < 1)
		{
			return -3;
		}
		CString csID = csLocation + csLogDate;
		rsLog.SetFieldByName(_T("LogID"),CL3Variant(csID));
		rsLog.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		rsLog.SetFieldByName(_T("Create_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsLog.SetFieldByName(_T("Status"),CL3Variant((LONG)0));
        
		rsLog.MoveNext();
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -4;
	}

	rsLog.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\EquipMag\\CCalibration_Log"),rsLog);
	if(nRet < rsLog.GetRowCount())
	{
		if(nTrans > 0)
		   Rollback(nTrans);
		return -5;
	}
	
	if(nTrans > 0)
	   Commit(nTrans);

	return rsLog.GetRowCount();
}

/// <Method class="CEquip_Unit_Mag" name="ModifyCalibration" type="L3LONG">
/// 修改校准基本信息 2009-04-06
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CEquip_Unit_Mag::ModifyCalibration(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	L3LONG rscount = rs.GetRowCount();
	if (rscount < 1)
	{
		return -1;
	}

	// 检查数据有效性
	if(rs.GetFieldIndex(_T("LogID")) < 0)
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

	rs.MoveFirst();
	if(SetObjsPropValues(_T("XGMESLogic\\EquipMag\\CCalibration_Log"),rs))
	{
		if(nTrans > 0)
			Commit(nTrans);
		return rs.GetRowCount();
	}
	else
	{
		if(nTrans > 0)
		    Rollback(nTrans);
		return 0;
	}
}

/// <Method class="CEquip_Unit_Mag" name="DeleteCalibration" type="L3LONG">
/// 删除校准基本信息 2009-04-06
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CEquip_Unit_Mag::DeleteCalibration(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	L3LONG rscount = rs.GetRowCount();
	if (rscount < 1)
	{
		return -1;
	}

	if(rs.GetFieldIndex(_T("LogID")) < 0)
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

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csLogID = rs.GetFieldByName(_T("LogID")).ToCString();
		CString csTemp = _T(" select * from CCalibration_Log where LogID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,csLogID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(nTrans > 0)
				Rollback(nTrans);
			return -4;
		}


		rsResult.MoveFirst();
		if (rsResult.GetRowCount() > 0)
		{
			if(DeleteOldObjects(_T("XGMESLogic\\EquipMag\\CCalibration_Detail"),rsResult) < rsResult.GetRowCount())
			{
				if(nTrans > 0)
					Rollback(nTrans);
				return -5;
			}
		}
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(DeleteOldObjects(_T("XGMESLogic\\EquipMag\\CCalibration_Log"),rs) < rs.GetRowCount())
	{
		if(nTrans > 0)
			Rollback(nTrans);
		return -6;
	}

	if(nTrans > 0 )
		Commit(nTrans);

	return 1;
}

/// <Method class="CEquip_Unit_Mag" name="NewCalibrationDetail" type="L3LONG">
/// 新增校准详细信息 2009-04-06
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CEquip_Unit_Mag::NewCalibrationDetail(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	L3LONG rscount = rs.GetRowCount();
	if (rscount < 1)
	{
		return -1;
	}

	if(rs.GetFieldIndex(_T("LogID")) < 0)
	{
		return -2;
	}

	CL3RecordSetWrap rsDetail;
	if(!CreateClassPropSet(_T("XGMESLogic\\EquipMag\\CCalibration_Detail"),rsDetail))
	{
		return -3;
	}

	rsDetail.CopyFrom(rs);

	rsDetail.MoveFirst();
	while(!rsDetail.IsEOF())
	{
		CString csLogID = rsDetail.GetFieldByName(_T("LogID")).ToCString();
		CL3Variant valRet = GetObjectPropValue(_T("XGMESLogic\\EquipMag\\CCalibration_Log\\")+csLogID,_T("Location"));
		if ((valRet.IsError()) && (GetL3LastError() == L3ERR_OBJECT_NOTEXIST))
		{
			return -4;
		}
		rsDetail.SetFieldByName(_T("Create_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
        
		rsDetail.MoveNext();
	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -5;
	}

	rsDetail.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\EquipMag\\CCalibration_Detail"),rsDetail);
	if(nRet < rsDetail.GetRowCount())
	{
		if(nTrans > 0)
		   Rollback(nTrans);
		return -6;
	}
	
	if(nTrans > 0)
	   Commit(nTrans);

	return rsDetail.GetRowCount();
}

/// <Method class="CEquip_Unit_Mag" name="DeleteCalibrationDetail" type="L3LONG">
/// 删除校准详细信息 2009-04-06
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CEquip_Unit_Mag::DeleteCalibrationDetail(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	L3LONG rscount = rs.GetRowCount();
	if (rscount < 1)
	{
		return -1;
	}

	if(rs.GetFieldIndex(_T("GUID")) < 0)
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

	rs.MoveFirst();
	if(DeleteOldObjects(_T("XGMESLogic\\EquipMag\\CCalibration_Detail"),rs) < rs.GetRowCount())
	{
		if(nTrans > 0)
		    Rollback(nTrans);
		return -4;
	}

	if(nTrans > 0 )
		Commit(nTrans);

	return 1;
}

/// <Method class="CEquip_Unit_Mag" name="ModifyCalibrationDetail" type="L3LONG">
/// 修改校准详细信息 2009-04-06
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CEquip_Unit_Mag::ModifyCalibrationDetail(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	L3LONG rscount = rs.GetRowCount();
	if (rscount < 1)
	{
		return -1;
	}

	// 检查数据有效性
	if(rs.GetFieldIndex(_T("GUID")) < 0)
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

	rs.MoveFirst();
	if(SetObjsPropValues(_T("XGMESLogic\\EquipMag\\CCalibration_Detail"),rs))
	{
		if(nTrans > 0)
			Commit(nTrans);
		return rs.GetRowCount();
	}
	else
	{
		if(nTrans > 0)
		    Rollback(nTrans);
		return 0;
	}
}

/// <Method class="CBF_Iron_Mag" name="QueryCalibration" type="L3RECORDSET">
/// 根据时间段查校准信息
/// <Param name="timeFrom" type="L3DATETIME">起始时间</Param>
/// <Param name="timeTo" type="L3DATETIME">结束时间</Param>
/// </Method>
L3RECORDSET CEquip_Unit_Mag::QueryCalibration(L3DATETIME timeFrom, L3DATETIME timeTo)
{
	CString strSQL;
	strSQL.Format(_T("select * from CCalibration_Log where Check_Date between ? and ?"));
	VARIANT params[2];
	params[0].vt = VT_DATE; params[0].date = timeFrom;
	params[1].vt = VT_DATE; params[1].date = timeTo;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,2,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(_T("XGMESLogic\\EquipMag\\CCalibration_Log"),rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CBF_Iron_Mag" name="QueryCalibrationDetail" type="L3RECORDSET">
/// 根据LogID查校准详细信息
/// <Param name="strLogID" type="L3STRING">起始时间</Param>
/// </Method>
L3RECORDSET CEquip_Unit_Mag::QueryCalibrationDetail(L3STRING strLogID)
{
	CString cstrLogID = strLogID;
	CString csSQL;
	csSQL.Format(_T("select * from CCalibration_Detail where LogID = '%s'"),cstrLogID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(_T("XGMESLogic\\EquipMag\\CCalibration_Detail"),rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CEnergy_Unit_Mag" name="AcceptCleaningData" type="L3BOOL">
/// 接收一级汽化冷却排污数据。
/// <Param name="rsData" type="L3RECORDSET">排污数据</Param>
/// </Method>
L3BOOL CEquip_Unit_Mag::AcceptCleaningData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount=0;
	if((rsCount = rs.GetRowCount()) < 1)
		return TRUE;

	CL3RecordSetWrap rsCleaning;
	if(!CreateClassPropSet(_T("XGMESLogic\\EquipMag\\CEquip_Cleaning_Data"),rsCleaning))
	{
		return FALSE;
	}

	rsCleaning.CopyFrom(rs);

	rsCleaning.MoveFirst();
	while (!rsCleaning.IsEOF())
	{
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		rsCleaning.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));

		rsCleaning.MoveNext();
	}

	CreateNewObjects(_T("XGMESLogic\\EquipMag\\CEquip_Cleaning_Data"),rsCleaning);

	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="AcceptRuntimeData" type="L3BOOL">
/// 接收一级汽化回收周期数据。
/// <Param name="rsData" type="L3RECORDSET">周期数据</Param>
/// </Method>
L3BOOL CEquip_Unit_Mag::AcceptRuntimeData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount=0;
	if((rsCount = rs.GetRowCount()) < 1)
		return TRUE;

	CL3RecordSetWrap rsRuntime;
	if(!CreateClassPropSet(_T("XGMESLogic\\EquipMag\\CEquip_Runtime_Data"),rsRuntime))
	{
		return FALSE;
	}

	rsRuntime.CopyFrom(rs);
	//班次班别
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	rsRuntime.MoveFirst();
	while (!rsRuntime.IsEOF())
	{
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		rsRuntime.SetFieldByName(_T("Catch_Time"),CL3Variant(curTime));
		rsRuntime.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsRuntime.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	

		rsRuntime.MoveNext();
	}

	CreateNewObjects(_T("XGMESLogic\\EquipMag\\CEquip_Runtime_Data"),rsRuntime);

	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="AcceptSupplyWaterData" type="L3BOOL">
/// 接收一级汽化回收补水数据。
/// <Param name="rsData" type="L3RECORDSET">周期数据</Param>
/// </Method>
L3BOOL CEquip_Unit_Mag::AcceptSupplyWaterData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount=0;
	if((rsCount = rs.GetRowCount()) < 1)
		return TRUE;

	//班次班别
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	CL3RecordSetWrap rsWater;
	if(!CreateClassPropSet(_T("XGMESLogic\\EquipMag\\CEquip_SupplyWater_Data"),rsWater))
	{
		return FALSE;
	}

	rsWater.CopyFrom(rs);

	rsWater.MoveFirst();
	while (!rsWater.IsEOF())
	{
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		CString csBOFID = rsWater.GetFieldByName(_T("BOFID")).ToCString();
		if(csBOFID.IsEmpty())
		{
			rsWater.MoveNext();
			continue;
		}
		CString csHeatID = GetObjectPropValue(_T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\")+csBOFID,_T("HeatID")).ToString();
		rsWater.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
		rsWater.SetFieldByName(_T("Time_Start"),CL3Variant(curTime));
		rsWater.SetFieldByName(_T("EndFlag"),CL3Variant((L3SHORT)0));
		rsWater.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsWater.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	

		rsWater.MoveNext();
	}

	CreateNewObjects(_T("XGMESLogic\\EquipMag\\CEquip_SupplyWater_Data"),rsWater);

	return TRUE;
}

/// <Method class="CEnergy_Unit_Mag" name="AcceptSupplyWaterEndData" type="L3BOOL">
/// 接收一级汽化回收补水结束数据。
/// <Param name="rsData" type="L3RECORDSET">周期数据</Param>
/// </Method>
L3BOOL CEquip_Unit_Mag::AcceptSupplyWaterEndData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	int rsCount=0;
	if((rsCount = rs.GetRowCount()) < 1)
		return TRUE;

	CL3RecordSetWrap rsWater;
	if(!CreateClassPropSet(_T("XGMESLogic\\EquipMag\\CEquip_SupplyWater_Data"),rsWater))
	{
		return FALSE;
	}

	rsWater.CopyFrom(rs);

	rsWater.MoveFirst();
	while (!rsWater.IsEOF())
	{
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		CString csBOFID = rsWater.GetFieldByName(_T("BOFID")).ToCString();
		if(csBOFID.IsEmpty())
		{
			rsWater.MoveNext();
			continue;
		}

		CString csSQL;
		csSQL.Format(_T("select * from CEquip_SupplyWater_Data where EndFlag = 0 and BOFID = '%s' order by Time_Start desc"),csBOFID);
		CL3RecordSetWrap rsLog;
		if(!Query(csSQL,rsLog))
			return FALSE;

		if(rsLog.GetRowCount() < 1)
		{
			rsWater.MoveNext();
			continue;
		}
		rsLog.MoveFirst();
		CString csGUID = rsLog.GetFieldByName(_T("GUID")).ToCString();
		CString csHeatID = rsLog.GetFieldByName(_T("HeatID")).ToCString();

		CString csUri = _T("XGMESLogic\\EquipMag\\CEquip_SupplyWater_Data\\")+csGUID;
		SetObjectPropValue(csUri,_T("Time_Stop"),CL3Variant(curTime));
		SetObjectPropValue(csUri,_T("EndFlag"),CL3Variant((L3SHORT)1));

		CString cstrSQL;
		cstrSQL.Format(_T("select * from CBOF_Process_Status where Status = 2 and HeatID = '%s'"),csHeatID);
		CL3RecordSetWrap rsHeat;
		if(!Query(cstrSQL,rsHeat))
			return FALSE;

		if(rsHeat.GetRowCount()>0)
		{
    		rsHeat.MoveFirst();
			COleDateTime dtBlowTime = rsHeat.GetFieldByName(_T("Change_Time")).ToDateTime();
			SetObjectPropValue(csUri,_T("Time_Blow"),CL3Variant(dtBlowTime));
		}

		rsWater.MoveNext();
	}

	return TRUE;
}

L3RECORDSET CVacTube_Mag::GetVacTubeBuild(L3STRING strCondition)
/// <Method class="CVacTube_Mag" name="GetVacTubeBuild" type="L3RECORDSET">
/// 
/// 获取真空槽砌筑实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsVacTubes；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
#include "StdAfx.h"
#include "_CVacTube_Mag.h"

//当对象被装载到系统中时，被调用
void CVacTube_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CVacTube_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

L3BOOL CVacTube_Mag::UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = rsInfos;
	if(rs.IsNull() || rs.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	CString csUri = lpcsClass;
	rs.MoveFirst();
	if(!SetObjsPropValues(csUri,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

L3BOOL CVacTube_Mag::DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = rsInfos;
	if(rs.IsNull() || rs.GetRowCount() < 1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	CString csUri = lpcsClass;
	rs.MoveFirst();
	if(!DeleteOldObjects(csUri,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

L3RECORDSET CVacTube_Mag::GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition =lpcsCondition;
	if(csCondition == _T(""))//2009-04-30
		return NULL;
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	
	CString csUri = lpcsClass;
	CString csSQL;
	csSQL.Format(csTemp,csUri,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	
	return rsResult.Detach();
}

/// <Method class="CVacTube_Mag" name="VacTubeOnPosition" type="L3BOOL">
/// 
/// 真空管上位
/// ARG &gt;&gt; rsVacTubes: 要要上位的真空管的记录集。必须包含VacTube_ID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::VacTubeOnPosition(L3RECORDSET rsVacTubes)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsVacTubes;
	if (rsData.IsNull()||rsData.GetRowCount() <1)
	{
		return FALSE;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	rsData.MoveFirst();
	CString csPosition = rsData.GetFieldByName(_T("Position")).ToCString();
	if( csPosition  == CVACTUBE_POSITION_WORK_A || csPosition  == CVACTUBE_POSITION_WORK_B)
	{
		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;
		//真空槽编号
		csTemp = _T(" SELECT   VacTube_Code   FROM cvactube_base   WHERE POSITION =  '%s' ");
		csTemp += _T(" AND vactube_name < '3'     AND vactube_name > '0' AND VacTube_Code IS NOT NULL");
		csTemp += _T(" GROUP BY VacTube_Code");
		csSQL.Format(csTemp,csPosition);
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}	
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			CString csVactubecode = rsResult.GetFieldByName(_T("VacTube_Code")).ToCString();
			//CString csRHUnitMagURI = RH1_UNIT_URI + csPosition;
			SetObjectPropValue(RH1_UNIT_URI,_T("Slot_No"),CL3Variant(csVactubecode));
		}
	}
	if(!SetObjsPropValues(CVACTUBE_BASE_URI ,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;
	}

	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CVacTube_Mag" name="VacTubeBuildStart" type="L3BOOL">
/// 
/// 真空槽槽管砌筑开始
/// ARG &gt;&gt; rsVacTubes: 要要砌筑开始的真空管的记录集。必须包含VacTube_ID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::VacTubeBuildStart(L3RECORDSET rsVacTubes)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsVacTubes;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	
	int iYear = dtCurrentTime.GetYear();
	int iMonth = dtCurrentTime.GetMonth();

	CString csYear;
	csYear.Format(_T("%d"),iYear);
	csYear = csYear.Right(2);

	CString csMonth;
	csMonth.Format(_T("%02d"),iMonth);

	CString csYearMonth = csYear + csMonth;
	
	CL3RecordSetWrap rsBuild;
	if(!CreateClassPropSet(CVACTUBE_BUILD_URI,rsBuild))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;
	}
	
	CL3RecordSetWrap rsBuildHot;
	if(!CreateClassPropSet(CVACTUBE_HOT_SYP_BUI_URI,rsBuildHot))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;
	}

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csVacTubeID = rsData.GetFieldByName(_T("VacTube_ID")).ToCString();
		if(csVacTubeID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CString csBaseURI = CVACTUBE_BASE_URI + _T("\\") + csVacTubeID;
		CString csStatus = GetObjectPropValue(csBaseURI,_T("Status")).ToCString();
		if(csStatus != CVACTUBE_STATUS_OFFLINE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CString csOldBuildID = GetObjectPropValue(csBaseURI,_T("Build_ID")).ToCString();
		CString csVacTubeName = GetObjectPropValue(csBaseURI,_T("VacTube_Name")).ToCString();
		CString csBuildID;
		CString csOldYearMonth;
		CString csID;
		
		if(csOldBuildID == _T(""))
			csID = _T("01");
		else
		{
			csOldYearMonth = csOldBuildID.Left(4);
			if(csOldYearMonth != csYearMonth)
				csID = _T("01");
			else
			{
				csID = csOldBuildID.Right(2);

				int iID = _ttoi(csID) + 1;
				csID.Format(_T("%02d"),iID);
			}
		}

		csBuildID = csYearMonth + csVacTubeID + csID;

		SetObjectPropValue(csBaseURI,_T("Status"),CL3Variant(CVACTUBE_STATUS_REPAIR));
		SetObjectPropValue(csBaseURI,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));
		SetObjectPropValue(csBaseURI,_T("VacTube_Age"),CL3Variant(L3LONG(0)));
		SetObjectPropValue(csBaseURI,_T("Flag"),CL3Variant(L3LONG(0)));
		SetObjectPropValue(csBaseURI,_T("HeatID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseURI,_T("Install_ID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseURI,_T("VacTube_Code"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseURI,_T("Build_ID"),CL3Variant(csBuildID));
		
		if(csVacTubeName == _T("1") || csVacTubeName == _T("2"))
		{
			rsBuild.AppendRecord();
			rsBuild.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsBuild.SetFieldByName(_T("Build_ID"),CL3Variant(csBuildID));
			rsBuild.SetFieldByName(_T("VacTube_Name"),CL3Variant(csVacTubeName));
			rsBuild.SetFieldByName(_T("VacTube_Id"),CL3Variant(csVacTubeID));
			rsBuild.SetFieldByName(_T("Build_Start_Time"),CL3Variant(dtCurrentTime));
			rsBuild.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsBuild.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsBuild.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		else if(csVacTubeName == _T("3"))//热弯管
		{
			rsBuildHot.AppendRecord();
			rsBuildHot.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsBuildHot.SetFieldByName(_T("Build_ID"),CL3Variant(csBuildID));
			rsBuildHot.SetFieldByName(_T("Hot_Syp_ID"),CL3Variant(csVacTubeID));
			rsBuildHot.SetFieldByName(_T("Build_Start_Time"),CL3Variant(dtCurrentTime));
			rsBuildHot.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsBuildHot.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsBuildHot.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		rsData.MoveNext();
	}
	if(rsBuild.GetRowCount() > 0)
	{
		rsBuild.MoveFirst();
		if(CreateNewObjects(CVACTUBE_BUILD_URI,rsBuild) < rsBuild.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
	}
	if(rsBuildHot.GetRowCount() > 0)
	{
		rsBuildHot.MoveFirst();
		if(CreateNewObjects(CVACTUBE_HOT_SYP_BUI_URI,rsBuildHot) < rsBuildHot.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CVacTube_Mag" name="VacTubeBuildEnd" type="L3BOOL">
/// 
/// 真空槽槽管砌筑结束
/// ARG &gt;&gt; rsVacTubes: 要要砌筑结束的真空管的记录集。必须包含VacTube_ID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::VacTubeBuildEnd(L3RECORDSET rsVacTubes)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsVacTubes;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csVacTubeID = rsData.GetFieldByName(_T("VacTube_ID")).ToCString();
		if(csVacTubeID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CString csBaseURI = CVACTUBE_BASE_URI + _T("\\") + csVacTubeID;
		CString csStatus = GetObjectPropValue(csBaseURI,_T("Status")).ToCString();

		if(csStatus != CVACTUBE_STATUS_REPAIR)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CString csBuildID = GetObjectPropValue(csBaseURI,_T("Build_ID")).ToCString();
		CString csVacTubeName = GetObjectPropValue(csBaseURI,_T("VacTube_Name")).ToCString();
		
		if(csVacTubeName == _T("1") || csVacTubeName == _T("2"))
		{
			if( !SetObjectPropValue(csBaseURI,_T("Flag"),CL3Variant(L3LONG(1))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return FALSE;
			}
			
			if(csBuildID != _T(""))
			{
				CString csBuildURI =  CVACTUBE_BUILD_URI + _T("\\") + csBuildID;
				SetObjectPropValue(csBuildURI,_T("Build_End_Time"),CL3Variant(dtCurrentTime));
			}
		}
		else if(csVacTubeName == _T("3"))//热弯管
		{
			SetObjectPropValue(csBaseURI,_T("Flag"),CL3Variant(L3LONG(1)));
			SetObjectPropValue(csBaseURI,_T("Status"),CL3Variant(CVACTUBE_STATUS_COLD));
			
			if(csBuildID != _T(""))
			{
				CString csBuildURI =  CVACTUBE_HOT_SYP_BUI_URI + _T("\\") + csBuildID;
				SetObjectPropValue(csBuildURI,_T("Build_End_Time"),CL3Variant(dtCurrentTime));
			}
		}

		rsData.MoveNext();
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CVacTube_Mag" name="HotOn" type="L3LONG">
/// 换上热弯管 状态为冷备
/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::HotOn(L3RECORDSET rsVacTubes)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsVacTubes;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsUse;
	if(!CreateClassPropSet(CVACTUBE_HOT_SYP_USE_URI,rsUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csVacTubeName = rsData.GetFieldByName(_T("VacTube_Name")).ToCString();
		CString csVacTubeID = rsData.GetFieldByName(_T("VacTube_ID")).ToCString();
		
		if(csVacTubeID == _T("")|| csVacTubeName != _T("3"))//热弯管编号为空或不为热弯管
		{
			rsData.MoveNext();
			continue;
		}
		CString csBaseUri = CVACTUBE_BASE_URI + _T("\\") + csVacTubeID;
		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();
		if(csStatus != CVACTUBE_STATUS_COLD)
		{
			rsData.MoveNext();
			continue;
		}
		long lAge = GetObjectPropValue(csBaseUri,_T("VacTube_Age")).ToLong();
		CString csBuildID = GetObjectPropValue(csBaseUri,_T("Build_ID")).ToCString();
		CString csPosition = GetObjectPropValue(csBaseUri,_T("Position")).ToCString();
		
		CString csRefraFac;
		if(csBuildID != _T(""))
			csRefraFac = GetObjectPropValue(CVACTUBE_HOT_SYP_BUI_URI + _T("\\") + csBuildID,_T("Refra_Fac")).ToCString();

		SetObjectPropValue(csBaseUri ,_T("Status"),CL3Variant(CVACTUBE_STATUS_USE));//
		SetObjectPropValue(csBaseUri ,_T("Flag"),CL3Variant(L3LONG(1)));
		
		rsUse.AppendRecord();
		rsUse.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsUse.SetFieldByName(_T("Build_ID"),CL3Variant(csBuildID));
		rsUse.SetFieldByName(_T("Hot_Syp_ID"),CL3Variant(csVacTubeID));
		rsUse.SetFieldByName(_T("Refra_Fac"),CL3Variant(csRefraFac));
		rsUse.SetFieldByName(_T("On_Time"),CL3Variant(dtCurrentTime));
		rsUse.SetFieldByName(_T("Position"),CL3Variant(csPosition));
		rsUse.SetFieldByName(_T("On_Age"),CL3Variant(L3LONG(lAge)));
		rsUse.SetFieldByName(_T("Total_Age"),CL3Variant(L3LONG(lAge)));
		rsUse.SetFieldByName(_T("On_TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsUse.SetFieldByName(_T("On_ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsUse.SetFieldByName(_T("On_Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	if(rsUse.GetRowCount() > 0)
	{
		rsUse.MoveFirst();
		if(CreateNewObjects(CVACTUBE_HOT_SYP_USE_URI,rsUse) < rsUse.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="HotOff" type="L3LONG">
/// 换下热弯管
/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::HotOff(L3RECORDSET rsVacTubes)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsVacTubes;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsUse;
	if(!CreateClassPropSet(CVACTUBE_HOT_SYP_USE_URI,rsUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csVacTubeName = rsData.GetFieldByName(_T("VacTube_Name")).ToCString();
		CString csVacTubeID = rsData.GetFieldByName(_T("VacTube_ID")).ToCString();
		if(csVacTubeID == _T("") || csVacTubeName != _T("3"))
		{
			rsData.MoveNext();
			continue;
		}

		CString csBaseUri = CVACTUBE_BASE_URI + _T("\\") + csVacTubeID;
		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();
		if(csStatus != CVACTUBE_STATUS_USE)
		{
			rsData.MoveNext();
			continue;
		}
		CString csBuildID = GetObjectPropValue(csBaseUri,_T("Build_ID")).ToCString();
		if(csBuildID == _T(""))
		{
			rsData.MoveNext();
			continue;
		}
		SetObjectPropValue(csBaseUri ,_T("Status"),CL3Variant(CVACTUBE_STATUS_CHECK));//下线检查
		SetObjectPropValue(csBaseUri ,_T("Flag"),CL3Variant(L3LONG(0)));
		
		CString csTemp = _T("Select * from (Select * from CVacTube_Hot_Syp_Use where Build_ID = '%s' order by Input_Time desc) where rownum <  2 ");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,csBuildID);
		if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		{
			rsData.MoveNext();
			continue;
		}
		rsResult.MoveFirst();
		
		L3DATETIME dtOnTime = rsResult.GetFieldByName(_T("On_Time")).ToDateTime();
		L3DATETIME dtOffTime = dtCurrentTime;
		COleDateTimeSpan span = dtOffTime - dtOnTime;
		L3DOUBLE dTime = span.GetTotalDays();
		
		rsUse.AppendRecord();
		rsUse.CopyCurRowFrom(rsResult);
		rsUse.SetFieldByName(_T("OffLine_Time"),CL3Variant(dtCurrentTime));
		rsUse.SetFieldByName(_T("OnLine_Len"),CL3Variant(dTime));
		rsUse.SetFieldByName(_T("Off_TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsUse.SetFieldByName(_T("Off_ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsUse.SetFieldByName(_T("Off_Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	if(rsUse.GetRowCount() > 0)
	{
		rsUse.MoveFirst();
		SetObjsPropValues(CVACTUBE_HOT_SYP_USE_URI,rsUse);
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="InsertVacTubeBuild" type="L3LONG">
/// 
/// 添加真空槽砌筑实绩
/// ARG &gt;&gt; rsVacTubes: 要添加的真空槽砌筑的记录集。必须包含 VacTube_ID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::InsertVacTubeBuild(L3RECORDSET rsVacTubes)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsVacTubes;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csVacTubeId = rsData.GetFieldByName(_T("VacTube_Id")).ToCString();
		if(csVacTubeId == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有真空槽编号
		}
		CString csBaseUri = CVACTUBE_BASE_URI + _T("\\") + csVacTubeId;
		CString csBuildID = GetObjectPropValue(csBaseUri,_T("Build_ID")).ToCString();
		
		rsData.SetFieldByName(_T("Build_ID"),CL3Variant(csBuildID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CVACTUBE_BUILD_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="UpdateVacTubeBuild" type="L3BOOL">
/// 
/// 修改真空槽砌筑实绩
/// ARG &gt;&gt; rsVacTubes: 要修改的真空槽砌筑的记录集。必须包含 VacTube_ID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::UpdateVacTubeBuild(L3RECORDSET rsVacTubes)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsVacTubes,CVACTUBE_BUILD_URI);
}

/// <Method class="CVacTube_Mag" name="DeleteVacTubeBuild" type="L3LONG">
/// 
/// 删除真空槽砌筑实绩
/// ARG &gt;&gt; rsVacTubes: 要删除的真空槽砌筑的记录集。必须包含 VacTube_ID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::DeleteVacTubeBuild(L3RECORDSET rsVacTubes)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsVacTubes;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csBuildID = rsData.GetFieldByName(_T("Build_ID")).ToCString();
		if(csBuildID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有主键砌筑编号
		}
		CString csTemp = _T("select * from %s where Build_ID = '%s'");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,CVACTUBE_REPAIR_URI,csBuildID);
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	//查询失败
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(DeleteOldObjects(CVACTUBE_REPAIR_URI,rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//删除修补信息失败
			}
		}
		
		rsData.MoveNext();
	}
	rsData.MoveFirst();
	if(DeleteOldObjects(CVACTUBE_BUILD_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//删除主信息失败
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CVacTube_Mag" name="GetVacTubeBuild" type="L3RECORDSET">
/// 
/// 获取真空槽砌筑实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsVacTubes；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CVacTube_Mag::GetVacTubeBuild(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CVACTUBE_BUILD_URI,strCondition);
}

/// <Method class="CVacTube_Mag" name="InsertHotSypBuild" type="L3LONG">
/// 
/// 添加热弯管砌筑实绩
/// ARG &gt;&gt; rsHotSyps: 要添加的热弯管砌筑的记录集。必须包含 Hot_Syp_ID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsHotSyps" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::InsertHotSypBuild(L3RECORDSET rsHotSyps)
{
	// TODO : 请在此添加逻辑代码
 	CL3RecordSetWrap rsData = rsHotSyps;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csVacTubeId = rsData.GetFieldByName(_T("Hot_Syp_ID")).ToCString();
		if(csVacTubeId == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有真空槽编号
		}
		CString csBaseUri = CVACTUBE_BASE_URI + _T("\\") + csVacTubeId;
		CString csBuildID = GetObjectPropValue(csBaseUri,_T("Build_ID")).ToCString();
		
		rsData.SetFieldByName(_T("Build_ID"),CL3Variant(csBuildID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CVACTUBE_HOT_SYP_BUI_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return  rsData.GetRowCount();
}

/// <Method class="CVacTube_Mag" name="UpdateHotSypBuild" type="L3BOOL">
/// 
/// 修改热弯管砌筑实绩
/// ARG &gt;&gt; rsHotSyps: 要修改的热弯管砌筑的记录集。必须包含 Hot_Syp_ID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsHotSyps" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::UpdateHotSypBuild(L3RECORDSET rsHotSyps)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsHotSyps,CVACTUBE_HOT_SYP_BUI_URI);
}

/// <Method class="CVacTube_Mag" name="DeleteHotSypBuild" type="L3LONG">
/// 
/// 删除热弯管砌筑实绩
/// ARG &gt;&gt; rsHotSyps: 要删除的热弯管砌筑的记录集。必须包含 Hot_Syp_ID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsHotSyps" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::DeleteHotSypBuild(L3RECORDSET rsHotSyps)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsHotSyps;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csBuildID = rsData.GetFieldByName(_T("Build_ID")).ToCString();
		if(csBuildID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有主键砌筑编号
		}
		CString csTemp = _T("select * from CVacTube_Hot_Syp_Repair where Build_ID = '%s'");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,csBuildID);
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	//查询失败
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(DeleteOldObjects(CVACTUBE_HOT_SYP_REPAIR_URI,rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//删除修补信息失败
			}
		}
		
		rsData.MoveNext();
	}
	rsData.MoveFirst();
	if(DeleteOldObjects(CVACTUBE_HOT_SYP_BUI_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//删除主信息失败
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CVacTube_Mag" name="GetHotSypBuild" type="L3RECORDSET">
/// 
/// 获取热弯管砌筑实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsHotSyps；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CVacTube_Mag::GetHotSypBuild(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CVACTUBE_HOT_SYP_BUI_URI,strCondition);
}

/// <Method class="CVacTube_Mag" name="InsertVacTubeFire" type="L3LONG">
/// 
/// 添加真空槽烘烤实绩
/// ARG &gt;&gt; rsFires: 要添加的真空槽烘烤的记录集。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::InsertVacTubeFire(L3RECORDSET rsFires)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsFires;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csPosition = rsData.GetFieldByName(_T("Position")).ToCString();//Up_Slot_ID,Bel_Slot_ID
		if(csPosition == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有烘烤位置
		}
		
		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;
		//真空槽编号
		csTemp = _T(" SELECT   VacTube_Code,Install_ID ,Fire_Count   FROM cvactube_base   WHERE POSITION =  '%s' ");
		csTemp += _T(" AND vactube_name < '3'     AND vactube_name > '0' AND VacTube_Code IS NOT NULL and Install_ID is not null");
		csTemp += _T(" GROUP BY VacTube_Code,Install_ID,Fire_Count");
		csSQL.Format(csTemp,csPosition);
		if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//当前位置上没有真空槽
		}	
		rsResult.MoveFirst();
		CString csVactubecode = rsResult.GetFieldByName(_T("VacTube_Code")).ToCString();
		CString csInstallID = rsResult.GetFieldByName(_T("Install_ID")).ToCString();
		CString csFireCount = rsResult.GetFieldByName(_T("Fire_Count")).ToCString().Trim();
		if(csFireCount == _T(""))
			csFireCount = _T("1");
		
		CString csObject = csInstallID + csFireCount;

		//上部槽编号
		CString csUpID = _T("");
		csTemp = _T(" SELECT vactube_id  FROM cvactube_base WHERE POSITION =  '%s'    "); 
		csTemp += _T("AND vactube_code = '%s' AND vactube_name = '1' order by vactube_name");
		csSQL.Format(csTemp,csPosition,csVactubecode);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}	
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			csUpID =  rsResult.GetFieldByIndex(0).ToCString();
		}

		//下部槽编号
		CString csDownID = _T("");
		csTemp = _T(" SELECT vactube_id  FROM cvactube_base WHERE POSITION =  '%s'    "); 
		csTemp += _T("AND vactube_code = '%s' AND vactube_name = '2' order by vactube_name");
		csSQL.Format(csTemp,csPosition,csVactubecode);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}	
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			csDownID =  rsResult.GetFieldByIndex(0).ToCString();
		}
		
		rsData.SetFieldByName(_T("VacTube_Code"),CL3Variant(csVactubecode));
		rsData.SetFieldByName(_T("Install_ID"),CL3Variant(csInstallID));
		rsData.SetFieldByName(_T("Up_Slot_ID"),CL3Variant(csUpID));
		rsData.SetFieldByName(_T("Bel_Slot_ID"),CL3Variant(csDownID));
		rsData.SetFieldByName(_T("Object_ID"),CL3Variant(csObject));
		rsData.SetFieldByName(_T("Fire_Soruce"),CL3Variant(L3LONG(1)));
		
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CVACTUBE_FIRE_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;//添加信息失败
	}
	if(bUseTrans)
		Commit(nTrans);
	return  rsData.GetRowCount();
}

/// <Method class="CVacTube_Mag" name="UpdateVacTubeFire" type="L3BOOL">
/// 
/// 修改真空槽烘烤实绩
/// ARG &gt;&gt; rsFires: 要修改的真空槽烘烤的记录集。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsFires" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::UpdateVacTubeFire(L3RECORDSET rsFires)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsFires,CVACTUBE_FIRE_URI);
}

/// <Method class="CVacTube_Mag" name="DeleteVacTubeFire" type="L3LONG">
/// 
/// 删除真空槽烘烤实绩
/// ARG &gt;&gt; rsFires: 要删除的真空槽烘烤的记录集。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::DeleteVacTubeFire(L3RECORDSET rsFires)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsFires;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csObjectID = rsData.GetFieldByName(_T("Object_ID")).ToCString();
		if(csObjectID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有主键
		}
		CString csTemp = _T("select * from CVacTube_Fire_Info where Object_ID = '%s'");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,csObjectID);
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	//查询失败
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(DeleteOldObjects(CVACTUBE_FIRE_INFO_URI,rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//删除详细信息失败
			}
		}
		
		rsData.MoveNext();
	}
	rsData.MoveFirst();
	if(DeleteOldObjects(CVACTUBE_FIRE_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//删除主信息失败
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CVacTube_Mag" name="GetVacTubeFire" type="L3RECORDSET">
/// 
/// 获取真空槽烘烤实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsFires；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CVacTube_Mag::GetVacTubeFire(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CVACTUBE_FIRE_URI,strCondition);
}

/// <Method class="CVacTube_Mag" name="InsertVacTubeUse" type="L3LONG">
/// 
/// 添加真空槽使用实绩
/// ARG &gt;&gt; rsUses: 要添加的真空槽使用的记录集。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::InsertVacTubeUse(L3RECORDSET rsUses)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsUses;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csPosition = rsData.GetFieldByName(_T("Position")).ToCString();
		if(csPosition == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有处理位置
		}
		
		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;
		//真空槽编号
		csTemp = _T(" SELECT   VacTube_Code,Install_ID   FROM cvactube_base   WHERE POSITION =  '%s' ");
		csTemp += _T(" AND vactube_name < '3'     AND vactube_name > '0' AND VacTube_Code IS NOT NULL and Install_ID is not null");
		csTemp += _T(" GROUP BY VacTube_Code,Install_ID");
		csSQL.Format(csTemp,csPosition);
		if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//当前位置上没有真空槽
		}	
		rsResult.MoveFirst();
		CString csVactubecode = rsResult.GetFieldByName(_T("VacTube_Code")).ToCString();
		CString csInstallID = rsResult.GetFieldByName(_T("Install_ID")).ToCString();
	
		//上部槽编号
		CString csUpID = _T("");
		csTemp = _T(" SELECT vactube_id  FROM cvactube_base WHERE POSITION =  '%s'    "); 
		csTemp += _T("AND vactube_code = '%s' AND vactube_name = '1' order by vactube_name");
		csSQL.Format(csTemp,csPosition,csVactubecode);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}	
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			csUpID =  rsResult.GetFieldByIndex(0).ToCString();
		}

		//下部槽编号
		CString csDownID = _T("");
		csTemp = _T(" SELECT vactube_id  FROM cvactube_base WHERE POSITION =  '%s'    "); 
		csTemp += _T("AND vactube_code = '%s' AND vactube_name = '2' order by vactube_name");
		csSQL.Format(csTemp,csPosition,csVactubecode);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}	
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			csDownID =  rsResult.GetFieldByIndex(0).ToCString();
		}
		
		rsData.SetFieldByName(_T("VacTube_Code"),CL3Variant(csVactubecode));
		rsData.SetFieldByName(_T("Install_ID"),CL3Variant(csInstallID));
		rsData.SetFieldByName(_T("Up_Slot_ID"),CL3Variant(csUpID));
		rsData.SetFieldByName(_T("Bel_Slot_ID"),CL3Variant(csDownID));
		rsData.SetFieldByName(_T("Fire_Soruce"),CL3Variant(L3LONG(1)));
		
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CVACTUBE_USE_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;//添加信息失败
	}
	if(bUseTrans)
		Commit(nTrans);
	return  rsData.GetRowCount();
}

/// <Method class="CVacTube_Mag" name="UpdateVacTubeUse" type="L3BOOL">
/// 
/// 修改真空槽使用实绩
/// ARG &gt;&gt; rsUses: 要修改的真空槽使用的记录集。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsUses" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::UpdateVacTubeUse(L3RECORDSET rsUses)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsUses,CVACTUBE_USE_URI);
}

/// <Method class="CVacTube_Mag" name="DeleteVacTubeUse" type="L3LONG">
/// 
/// 删除真空槽使用实绩
/// ARG &gt;&gt; rsUses: 要删除的真空槽使用的记录集。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::DeleteVacTubeUse(L3RECORDSET rsUses)
{
	// TODO : 请在此添加逻辑代码
		CL3RecordSetWrap rsData = rsUses;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csInstallID = rsData.GetFieldByName(_T("Install_ID")).ToCString();
		if(csInstallID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有主键
		}
		CString csTemp = _T("select * from CVacTube_Use_Info where Install_ID = '%s'");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,csInstallID);
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	//查询失败
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(DeleteOldObjects(CVACTUBE_USE_INFO_URI,rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//删除详细信息失败
			}
		}
		
		rsData.MoveNext();
	}
	rsData.MoveFirst();
	if(DeleteOldObjects(CVACTUBE_USE_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//删除主信息失败
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CVacTube_Mag" name="GetVacTubeUse" type="L3RECORDSET">
/// 
/// 获取真空槽使用实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsUses；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CVacTube_Mag::GetVacTubeUse(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CVACTUBE_USE_URI,strCondition);
}

/// <Method class="CVacTube_Mag" name="VactubeOnLine" type="L3LONG">
/// RH处理开始,真空槽上线使用
/// <Param name="strPosition" type="L3STRING">处理工位</Param>
/// </Method>
L3LONG CVacTube_Mag::VactubeOnLine(L3STRING strPosition)
{
	// TODO : 请在此添加逻辑代码
	CString csPosition = strPosition;
	if(csPosition == _T("") || ((csPosition != CVACTUBE_POSITION_WORK_A) && (csPosition != CVACTUBE_POSITION_WORK_B)))
		return -1;
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	//RH工位上信息
	CString csRHAreaName = _T("XGMESLogic\\RHMag\\CRH_Prod_Area\\S51") + csPosition ;
	CString csHeatID = GetObjectPropValue(csRHAreaName,_T("HeatID")).ToCString();
	CString csSteelGrade;
	CString csSteelGradeIndex = GetObjectPropValue(csRHAreaName,_T("SteelGradeIndex")).ToCString();
	if(csSteelGradeIndex != _T(""))
		csSteelGrade = GetObjectPropValue(_T("XGMESLogic\\QualityMag\\CQA_SteelGradeIndex_R\\") + csSteelGradeIndex,_T("SteelGrade")).ToCString();
	
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

	CString csTemp;
	CString csSQL;
	CL3RecordSetWrap rsResult;
	//真空槽编号
	csTemp = _T(" SELECT   VacTube_Code,Install_ID   FROM cvactube_base   WHERE POSITION =  '%s'  and Status = '%s'");
	csTemp += _T(" AND vactube_name < '3'     AND vactube_name > '0' AND VacTube_Code IS NOT NULL");
	csTemp += _T(" GROUP BY VacTube_Code,Install_ID");
	csSQL.Format(csTemp,csPosition,CVACTUBE_STATUS_HOT);
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	rsResult.MoveFirst();
	CString csVactubecode = rsResult.GetFieldByName(_T("VacTube_Code")).ToCString();
	CString csInstallID = rsResult.GetFieldByName(_T("Install_ID")).ToCString();

	if(csVactubecode == _T("") || csInstallID == _T(""))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//没用真空槽编号或组装编号
	}	

	//上部槽编号
	CString csUpID = _T("");
	long lUpAge ;
	csTemp = _T(" SELECT VacTube_ID ,VacTube_Age FROM cvactube_base WHERE POSITION =  '%s'   and Status = '%s'");
	csTemp += _T("AND vactube_code = '%s' AND vactube_name = '1' order by VacTube_ID");
	csSQL.Format(csTemp,csPosition,CVACTUBE_STATUS_HOT,csVactubecode);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csUpID =  rsResult.GetFieldByName(_T("VacTube_ID")).ToCString();
		CString csUpAge = rsResult.GetFieldByName(_T("VacTube_Age")).ToCString().Trim();
		if(csUpAge == _T(""))
			lUpAge = 1;
		else
			lUpAge = _ttol(csUpAge) + 1;
		if(csUpID != _T(""))
		{
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_USE));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("VacTube_Age"),CL3Variant(lUpAge));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(0)));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("HeatID"),CL3Variant(csHeatID));
		}
	}
	else
		lUpAge = 1;

	//下部槽编号
	CString csDownID = _T("");
	long lDownAge ;
	csTemp = _T(" SELECT VacTube_ID ,VacTube_Age FROM cvactube_base WHERE POSITION =  '%s'   and Status = '%s'");
	csTemp += _T("AND vactube_code = '%s' AND vactube_name = '2' order by VacTube_ID");
	csSQL.Format(csTemp,csPosition,CVACTUBE_STATUS_HOT,csVactubecode);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csDownID = rsResult.GetFieldByName(_T("VacTube_ID")).ToCString();
		CString csDownAge = rsResult.GetFieldByName(_T("VacTube_Age")).ToCString().Trim();

		if(csDownAge == _T(""))
			lDownAge = 1;
		else
			lDownAge = _ttol(csDownAge) + 1;
		if(csUpID != _T(""))
		{
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_USE));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("VacTube_Age"),CL3Variant(lDownAge));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(0)));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("HeatID"),CL3Variant(csHeatID));
		}
	}
	else
		lDownAge = 1;
		
	//真空槽使用主信息
	CL3RecordSetWrap rsUse;
	if(!CreateClassPropSet(CVACTUBE_USE_URI,rsUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	long lCir_Total_Age;//环流管累计寿命

	long lAes_Soa_Total_Len;//上升管累计时长[min]
	long lAes_Soa_Total_Age;//上升管累计寿命

	long lDes_Soa_Total_Len;//下降管累计时长[min]
	long lDes_Soa_Total_Age;//下降管累计寿命
	//获取上次使用信息
	csTemp =  _T(" SELECT *							");
	csTemp += _T("  FROM (SELECT   *				");
	csTemp += _T("            FROM cvactube_use		");
    csTemp += _T("WHERE Install_ID = '%s'			");
    csTemp += _T("ORDER BY input_time DESC)			");
	csTemp += _T("WHERE ROWNUM < 2					");
	csSQL.Format(csTemp,csInstallID);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		lCir_Total_Age = rsResult.GetFieldByName(_T("Cir_Total_Age")).ToLong() + 1;
		lAes_Soa_Total_Len = rsResult.GetFieldByName(_T("Aes_Soa_Total_Len")).ToLong();
		lAes_Soa_Total_Age = rsResult.GetFieldByName(_T("Aes_Soa_Total_Age")).ToLong() + 1;

		lDes_Soa_Total_Len = rsResult.GetFieldByName(_T("Des_Soa_Total_Len")).ToLong();
		lDes_Soa_Total_Age = rsResult.GetFieldByName(_T("Des_Soa_Total_Age")).ToLong() + 1;
		
		rsResult.MoveFirst();
		rsResult.SetFieldByName(_T("Up_Total_Age"),CL3Variant(lUpAge));
		rsResult.SetFieldByName(_T("Bel_Total_Age"),CL3Variant(lDownAge));
		rsResult.SetFieldByName(_T("Cir_Total_Age"),CL3Variant(lCir_Total_Age));
		rsResult.SetFieldByName(_T("Aes_Soa_Total_Len"),CL3Variant(lAes_Soa_Total_Len));
		rsResult.SetFieldByName(_T("Aes_Soa_Total_Age"),CL3Variant(lAes_Soa_Total_Age));
		rsResult.SetFieldByName(_T("Des_Soa_Total_Len"),CL3Variant(lDes_Soa_Total_Len));
		rsResult.SetFieldByName(_T("Des_Soa_Total_Age"),CL3Variant(lDes_Soa_Total_Age));
		
		rsUse.AppendRecord();
		rsUse.CopyCurRowFrom(rsResult);
		
		rsUse.MoveFirst();
		if(!SetObjsPropValues(CVACTUBE_USE_URI,rsUse))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
	}
	else//组装信息丢失或则没有产生，产生组装信息（使用主信息）
	{
		lCir_Total_Age = 1;
		lAes_Soa_Total_Len = 0;
		lAes_Soa_Total_Age =  1;

		lDes_Soa_Total_Len = 0;
		lDes_Soa_Total_Age = 1;

		rsUse.AppendRecord();
		rsUse.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsUse.SetFieldByName(_T("Install_ID"),CL3Variant(csInstallID));
		rsUse.SetFieldByName(_T("Position"),CL3Variant(csPosition));
		rsUse.SetFieldByName(_T("VacTube_Code"),CL3Variant(csVactubecode));
		rsUse.SetFieldByName(_T("Up_Slot_ID"),CL3Variant(csUpID));
		rsUse.SetFieldByName(_T("Bel_Slot_ID"),CL3Variant(csDownID));
		rsUse.SetFieldByName(_T("Up_Total_Age"),CL3Variant(lUpAge));
		rsUse.SetFieldByName(_T("Bel_Total_Age"),CL3Variant(lDownAge));
		rsUse.SetFieldByName(_T("Cir_Total_Age"),CL3Variant(lCir_Total_Age));
		rsUse.SetFieldByName(_T("Aes_Soa_Total_Len"),CL3Variant(lAes_Soa_Total_Len));
		rsUse.SetFieldByName(_T("Aes_Soa_Total_Age"),CL3Variant(lAes_Soa_Total_Age));
		rsUse.SetFieldByName(_T("Des_Soa_Total_Len"),CL3Variant(lDes_Soa_Total_Len));
		rsUse.SetFieldByName(_T("Des_Soa_Total_Age"),CL3Variant(lDes_Soa_Total_Age));
		rsUse.SetFieldByName(_T("On_Line_Time"),CL3Variant(dtCurrentTime));
		rsUse.SetFieldByName(_T("Crane_TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		rsUse.MoveFirst();
		if(rsUse.GetRowCount() > 0)
			CreateNewObjects(CVACTUBE_USE_URI,rsUse);
	}
	
	//使用详细信息
	CL3RecordSetWrap rsUseInfo;
	if(!CreateClassPropSet(CVACTUBE_USE_INFO_URI,rsUseInfo))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsUseInfo.AppendRecord();
	rsUseInfo.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
	rsUseInfo.SetFieldByName(_T("Install_ID"),CL3Variant(csInstallID));
	rsUseInfo.SetFieldByName(_T("Position"),CL3Variant(csPosition));
	rsUseInfo.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rsUseInfo.SetFieldByName(_T("SteelGrade"),CL3Variant(csSteelGrade));
	rsUseInfo.SetFieldByName(_T("VacTube_Code"),CL3Variant(csVactubecode));
	rsUseInfo.SetFieldByName(_T("Up_Slot_ID"),CL3Variant(csUpID));
	rsUseInfo.SetFieldByName(_T("Bel_Slot_ID"),CL3Variant(csDownID));
	rsUseInfo.SetFieldByName(_T("Up_Total_Age"),CL3Variant(lUpAge));
	rsUseInfo.SetFieldByName(_T("Bel_Total_Age"),CL3Variant(lDownAge));
	rsUseInfo.SetFieldByName(_T("Cir_Total_Age"),CL3Variant(lCir_Total_Age));
	rsUseInfo.SetFieldByName(_T("Aes_Soa_Total_Len"),CL3Variant(lAes_Soa_Total_Len));
	rsUseInfo.SetFieldByName(_T("Aes_Soa_Total_Age"),CL3Variant(lAes_Soa_Total_Age));
	rsUseInfo.SetFieldByName(_T("Des_Soa_Total_Len"),CL3Variant(lDes_Soa_Total_Len));
	rsUseInfo.SetFieldByName(_T("Des_Soa_Total_Age"),CL3Variant(lDes_Soa_Total_Age));
	rsUseInfo.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
	rsUseInfo.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsUseInfo.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	
	rsUseInfo.MoveFirst();
	if(rsUseInfo.GetRowCount() > 0)
			CreateNewObjects(CVACTUBE_USE_INFO_URI,rsUseInfo);
	
	//热弯管
	CString csHotID = _T("");
	long lHotAge ;
	csTemp = _T(" SELECT VacTube_ID ,VacTube_Age,Build_ID FROM cvactube_base WHERE POSITION =  '%s' ");
	csTemp += _T("AND vactube_name = '3' order by VacTube_ID");
	csSQL.Format(csTemp,csPosition);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csHotID = rsResult.GetFieldByName(_T("VacTube_ID")).ToCString();
		CString csBuildID = rsResult.GetFieldByName(_T("Build_ID")).ToCString();
		CString csHotAge = rsResult.GetFieldByName(_T("VacTube_Age")).ToCString().Trim();

		if(csHotAge == _T(""))
			lHotAge = 1;
		else
			lHotAge = _ttol(csHotAge) + 1;
		if(csUpID != _T(""))
		{
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csHotID ,_T("VacTube_Age"),CL3Variant(L3LONG(lHotAge)));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csHotID ,_T("Flag"),CL3Variant(L3LONG(0)));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csHotID ,_T("HeatID"),CL3Variant(csHeatID));
		}
		if(csBuildID != _T(""))
		{
			csTemp = _T("Select * from (Select * from CVacTube_Hot_Syp_Use where Build_ID = '%s' order by Input_Time desc) where rownum <  2 ");
			csSQL.Format(csTemp,csBuildID);
			rsResult.DeleteAll();
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}	
			if(rsResult.GetRowCount() > 0)
			{
				rsResult.MoveFirst();

				long lOnAge = rsResult.GetFieldByName(_T("On_Age")).ToLong();
				long lCueAge = lHotAge - lOnAge;
				L3DATETIME dtOnTime = rsResult.GetFieldByName(_T("On_Time")).ToDateTime();
				L3DATETIME dtOffTime = dtCurrentTime;
				COleDateTimeSpan span = dtOffTime - dtOnTime;
				L3DOUBLE dTime = span.GetTotalDays();

				CL3RecordSetWrap rsUse;
				if(!CreateClassPropSet(CVACTUBE_HOT_SYP_USE_URI,rsUse))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}	
				rsUse.AppendRecord();
				rsUse.CopyCurRowFrom(rsResult);
				rsUse.SetFieldByName(_T("Cur_Age"),CL3Variant(L3LONG(lCueAge)));
				rsUse.SetFieldByName(_T("Total_Age"),CL3Variant(L3LONG(lHotAge)));
				rsUse.SetFieldByName(_T("OnLine_Len"),CL3Variant(dTime));
				if(rsUse.GetRowCount() > 0)
				{
					rsUse.MoveFirst();
					SetObjsPropValues(CVACTUBE_HOT_SYP_USE_URI,rsUse);
				}
			}
		}
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="VactubeOffLine" type="L3LONG">
/// RH处理结束,真空槽热备
/// <Param name="strPosition" type="L3STRING">处理工位</Param>
/// </Method>
L3LONG CVacTube_Mag::VactubeOffLine(L3STRING strPosition)
{
	// TODO : 请在此添加逻辑代码
	CString csPosition = strPosition;
	if(csPosition == _T("") || ((csPosition != CVACTUBE_POSITION_WORK_A) && (csPosition != CVACTUBE_POSITION_WORK_B)))
		return -1;
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	//RH工位上信息：真空处理时长
	long lProcessTime;
	CString csRHAreaName = _T("XGMESLogic\\RHMag\\CRH_Prod_Area\\S51") + csPosition ;
	CString csTreatNo = GetObjectPropValue(csRHAreaName,_T("TreatNo")).ToCString().Trim();
	if(csTreatNo != _T(""))
		lProcessTime = GetObjectPropValue(RH_PROCESS_DATA_CLASS_URI + _T("\\") + csTreatNo,_T("Process_Time")).ToLong();
	else
		lProcessTime = 0;
	lProcessTime = lProcessTime / 60 ;

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

	CString csTemp;
	CString csSQL;
	CL3RecordSetWrap rsResult;
	//真空槽编号
	csTemp = _T(" SELECT   VacTube_Code,Install_ID   FROM cvactube_base   WHERE POSITION =  '%s'  and Status = '%s'");
	csTemp += _T(" AND vactube_name < '3'     AND vactube_name > '0' AND VacTube_Code IS NOT NULL");
	csTemp += _T(" GROUP BY VacTube_Code,Install_ID");
	csSQL.Format(csTemp,csPosition,CVACTUBE_STATUS_USE);
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	rsResult.MoveFirst();
	CString csVactubecode = rsResult.GetFieldByName(_T("VacTube_Code")).ToCString();
	CString csInstallID = rsResult.GetFieldByName(_T("Install_ID")).ToCString();

	if(csVactubecode == _T("") || csInstallID == _T(""))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//没用真空槽编号或组装编号
	}	

	//上部槽编号
	CString csUpID = _T("");
	long lUpAge ;
	csTemp = _T(" SELECT VacTube_ID,VacTube_Age  FROM cvactube_base WHERE POSITION =  '%s'   and Status = '%s'");
	csTemp += _T("AND vactube_code = '%s' AND vactube_name = '1' order by vactube_name");
	csSQL.Format(csTemp,csPosition,CVACTUBE_STATUS_USE,csVactubecode);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csUpID =  rsResult.GetFieldByName(_T("VacTube_ID")).ToCString();
		
		lUpAge = rsResult.GetFieldByName(_T("VacTube_Age")).ToLong() ;
		
		if(csUpID != _T(""))
		{
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_HOT));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(1)));
		}
	}

	//下部槽编号
	CString csDownID = _T("");
	long lDownAge ;
	csTemp = _T(" SELECT VacTube_ID ,VacTube_Age FROM cvactube_base WHERE POSITION =  '%s'   and Status = '%s'");
	csTemp += _T("AND vactube_code = '%s' AND vactube_name = '2' order by vactube_name");
	csSQL.Format(csTemp,csPosition,CVACTUBE_STATUS_USE,csVactubecode);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csDownID = rsResult.GetFieldByName(_T("VacTube_ID")).ToCString();
		lDownAge = rsResult.GetFieldByName(_T("VacTube_Age")).ToLong();
		if(csUpID != _T(""))
		{
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_HOT));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(1)));
		}
	}
	
	long lAes_Soa_Total_Len;//上升管累计时长[min]

	long lDes_Soa_Total_Len;//下降管累计时长[min]

	//真空槽使用主信息（组装信息）
	csTemp = _T(" select * from CVACTUBE_USE where Install_ID = '%s' ");
	csSQL.Format(csTemp,csInstallID);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		lAes_Soa_Total_Len = rsResult.GetFieldByName(_T("Aes_Soa_Total_Len")).ToLong();
		lDes_Soa_Total_Len = rsResult.GetFieldByName(_T("Des_Soa_Total_Len")).ToLong();
		
		lAes_Soa_Total_Len += lProcessTime;
		lDes_Soa_Total_Len += lProcessTime;
		
		//修改主信息累计使用时长
		SetObjectPropValue(CVACTUBE_USE_URI + _T("\\") + csInstallID,_T("Aes_Soa_Total_Len"),CL3Variant(L3LONG(lAes_Soa_Total_Len)));
		SetObjectPropValue(CVACTUBE_USE_URI + _T("\\") + csInstallID,_T("Des_Soa_Total_Len"),CL3Variant(L3LONG(lDes_Soa_Total_Len)));
	}
	else 
	{
		lAes_Soa_Total_Len = 0;
		lDes_Soa_Total_Len = 0;
		
		//真空槽使用主信息
		CL3RecordSetWrap rsUse;
		if(!CreateClassPropSet(CVACTUBE_USE_URI,rsUse))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		rsUse.AppendRecord();
		rsUse.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsUse.SetFieldByName(_T("Install_ID"),CL3Variant(csInstallID));
		rsUse.SetFieldByName(_T("Position"),CL3Variant(csPosition));
		rsUse.SetFieldByName(_T("VacTube_Code"),CL3Variant(csVactubecode));
		rsUse.SetFieldByName(_T("Up_Slot_ID"),CL3Variant(csUpID));
		rsUse.SetFieldByName(_T("Bel_Slot_ID"),CL3Variant(csDownID));
		rsUse.SetFieldByName(_T("Up_Total_Age"),CL3Variant(lUpAge));
		rsUse.SetFieldByName(_T("Bel_Total_Age"),CL3Variant(lDownAge));
		//rsUse.SetFieldByName(_T("Cir_Total_Age"),CL3Variant(L3LONG(1)));
		rsUse.SetFieldByName(_T("Aes_Soa_Total_Len"),CL3Variant(lAes_Soa_Total_Len));
		//rsUse.SetFieldByName(_T("Aes_Soa_Total_Age"),CL3Variant(lAes_Soa_Total_Age));
		rsUse.SetFieldByName(_T("Des_Soa_Total_Len"),CL3Variant(lDes_Soa_Total_Len));
		//rsUse.SetFieldByName(_T("Des_Soa_Total_Age"),CL3Variant(lDes_Soa_Total_Age));
		//rsUse.SetFieldByName(_T("On_Line_Time"),CL3Variant(dtCurrentTime));
		//rsUse.SetFieldByName(_T("Crane_TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		/*rsUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));*/
		rsUse.MoveFirst();
		if(rsUse.GetRowCount() > 0)
			CreateNewObjects(CVACTUBE_USE_URI,rsUse);
	}

	//真空槽使用详细信息
	csTemp	= _T(" SELECT *							");
  	csTemp += _T(" FROM (SELECT *					");
    csTemp += _T("        FROM cvactube_use_info	");
    csTemp += _T("WHERE install_id = '%s'			");
    csTemp += _T("ORDER BY input_time DESC)			");
	csTemp += _T("WHERE ROWNUM < 2					");
	csSQL.Format(csTemp,csInstallID);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
		CString csInfoURI = CVACTUBE_USE_INFO_URI + _T("\\") + csGUID;
		SetObjectPropValue(csInfoURI,_T("Aes_Soa_On_Len"),CL3Variant(L3LONG(lProcessTime)));
		SetObjectPropValue(csInfoURI,_T("Aes_Soa_Total_Len"),CL3Variant(L3LONG(lAes_Soa_Total_Len)));
		SetObjectPropValue(csInfoURI,_T("Des_Soa_On_Len"),CL3Variant(L3LONG(lProcessTime)));
		SetObjectPropValue(csInfoURI,_T("Des_Soa_Total_Len"),CL3Variant(L3LONG(lDes_Soa_Total_Len)));
	}
	//热弯管
	CString csHotID = _T("");
	csTemp = _T(" SELECT VacTube_ID ,Build_ID FROM cvactube_base WHERE POSITION =  '%s' ");
	csTemp += _T("AND vactube_name = '3' order by VacTube_ID");
	csSQL.Format(csTemp,csPosition);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csHotID = rsResult.GetFieldByName(_T("VacTube_ID")).ToCString();
		CString csBuildID = rsResult.GetFieldByName(_T("Build_ID")).ToCString();
	
		if(csUpID != _T(""))
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csHotID ,_T("Flag"),CL3Variant(L3LONG(1)));
		
		if(csBuildID != _T(""))
		{
			csTemp = _T("Select * from (Select * from CVacTube_Hot_Syp_Use where Build_ID = '%s' order by Input_Time desc) where rownum <  2 ");
			csSQL.Format(csTemp,csBuildID);
			rsResult.DeleteAll();
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}	
			if(rsResult.GetRowCount() > 0)
			{
				rsResult.MoveFirst();

				CString csHotGUID =  rsResult.GetFieldByName(_T("GUID")).ToCString();

				L3DATETIME dtOnTime = rsResult.GetFieldByName(_T("On_Time")).ToDateTime();
				L3DATETIME dtOffTime = dtCurrentTime;
				COleDateTimeSpan span = dtOffTime - dtOnTime;
				L3DOUBLE dTime = span.GetTotalDays();

				SetObjectPropValue(CVACTUBE_HOT_SYP_USE_URI + _T("\\") + csHotGUID,_T("OnLine_Len"),CL3Variant(dTime));
			}
		}
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="AccepteFireData" type="L3BOOL">
/// 接收烘烤数据
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::AccepteFireData(L3RECORDSET rsData)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = rsData;
	if(rs.IsNull() || rs.GetRowCount() < 1)
		return TRUE;
	
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CVACTUBE_FIRE_URI,rsFire))
		return TRUE;

	CL3RecordSetWrap rsFireInfo;
	if(!CreateClassPropSet(CVACTUBE_FIRE_INFO_URI,rsFireInfo))
		return TRUE;
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csLanceID = rs.GetFieldByName(_T("LanceID")).ToCString().Trim();
		L3FLOAT fO2Flow = rs.GetFieldByName(_T("O2_Flow")).ToFloat();
		L3FLOAT fCOFlow = rs.GetFieldByName(_T("CO_Flow")).ToFloat();
		L3FLOAT fTemp = rs.GetFieldByName(_T("Temp")).ToFloat();
		L3FLOAT fHeight = rs.GetFieldByName(_T("Height")).ToFloat();
		L3LONG lTime_ID = rs.GetFieldByName(_T("Catch_Count")).ToLong();
		L3LONG lMode = rs.GetFieldByName(_T("Mode")).ToLong();
	
		if(csLanceID == _T(""))
		{
			rs.MoveNext();
			continue ;
		}
		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;
		//真空槽编号
		csTemp = _T(" SELECT   VacTube_Code,Install_ID ,Fire_Count   FROM cvactube_base   WHERE POSITION =  '%s' ");
		csTemp += _T(" AND vactube_name < '3'     AND vactube_name > '0' AND VacTube_Code IS NOT NULL");
		csTemp += _T(" GROUP BY VacTube_Code,Install_ID,Fire_Count");
		csSQL.Format(csTemp,csLanceID);
		if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		{
			rs.MoveNext();
			continue ;
		}
		rsResult.MoveFirst();
		CString csVactubecode = rsResult.GetFieldByName(_T("VacTube_Code")).ToCString();
		CString csInstallID = rsResult.GetFieldByName(_T("Install_ID")).ToCString();
		CString csFireCount = rsResult.GetFieldByName(_T("Fire_Count")).ToCString().Trim();;
		if(csFireCount == _T(""))
			csFireCount == _T("0");
		CString csObject = csInstallID + csFireCount;

		//上部槽编号
		CString csUpID;
		csTemp = _T(" SELECT vactube_id  FROM cvactube_base WHERE POSITION =  '%s'    "); 
		csTemp += _T("AND vactube_code = '%s' AND vactube_name = '1' order by vactube_name");
		csSQL.Format(csTemp,csLanceID,csVactubecode);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			rs.MoveNext();
			continue ;
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			csUpID =  rsResult.GetFieldByIndex(0).ToCString();
		}

		//下部槽编号
		CString csDownID;
		csTemp = _T(" SELECT vactube_id  FROM cvactube_base WHERE POSITION =  '%s'    "); 
		csTemp += _T("AND vactube_code = '%s' AND vactube_name = '2' order by vactube_name");
		csSQL.Format(csTemp,csLanceID,csVactubecode);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			rs.MoveNext();
			continue ;
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			csDownID =  rsResult.GetFieldByIndex(0).ToCString();
		}
		
		

		if(lMode==1)//1开始：首先添加主信息，然后录入过程数据
		{
			int iFireCount = _ttoi(csFireCount) + 1;
			csFireCount.Format(_T("%d"),iFireCount);
			csObject = csInstallID + csFireCount;

			rsFire.AppendRecord();
			rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsFire.SetFieldByName(_T("VacTube_Code"),CL3Variant(csVactubecode));
			rsFire.SetFieldByName(_T("Install_ID"),CL3Variant(csInstallID));
			rsFire.SetFieldByName(_T("Position"),CL3Variant(csLanceID));
			rsFire.SetFieldByName(_T("Up_Slot_ID"),CL3Variant(csUpID));
			rsFire.SetFieldByName(_T("Bel_Slot_ID"),CL3Variant(csDownID));
			rsFire.SetFieldByName(_T("Fire_Start_Time"),CL3Variant(dtCurrentTime));
			rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsFire.SetFieldByName(_T("Log_Per"),CL3Variant(GetCurrentUser()));
			rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csObject));//主键
			rsFire.SetFieldByName(_T("Fire_Soruce"),CL3Variant(L3LONG(0)));

			if(csLanceID == CVACTUBE_POSITION_FIRE_A ||csLanceID == CVACTUBE_POSITION_FIRE_B )
			{
				if(csUpID != _T(""))
				{
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_PRE_FIRE));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(0)));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Fire_Count"),CL3Variant(L3LONG(iFireCount)));
				}
				if(csDownID != _T(""))
				{
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_PRE_FIRE));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(0)));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Fire_Count"),CL3Variant(L3LONG(iFireCount)));
				}
			}
			else if(csLanceID == CVACTUBE_POSITION_WORK_A ||csLanceID == CVACTUBE_POSITION_WORK_B )
			{
				if(csUpID != _T(""))
				{
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_BIG_FIRE));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(0)));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Fire_Count"),CL3Variant(L3LONG(iFireCount)));
				}
				if(csDownID != _T(""))
				{
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_BIG_FIRE));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(0)));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Fire_Count"),CL3Variant(L3LONG(iFireCount)));
				}
			}
		}
		else if(lMode==0)//0结束：修改主信息，然后录入过程数据
		{
			if(csLanceID == CVACTUBE_POSITION_FIRE_A ||csLanceID == CVACTUBE_POSITION_FIRE_B )
			{
				if(csUpID != _T(""))
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(1)));
				if(csDownID != _T(""))
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(1)));
			}
			else if(csLanceID == CVACTUBE_POSITION_WORK_A ||csLanceID == CVACTUBE_POSITION_WORK_B )
			{
				if(csUpID != _T(""))
				{
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_HOT));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(1)));
				}
				if(csDownID != _T(""))
				{
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_HOT));
					SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(1)));
				}
			}
			/*csTemp = _T("	SELECT *																		");
			csTemp += _T("	  FROM (SELECT   *																");
			csTemp += _T("	            FROM cvactube_fire													");
			csTemp += _T("	           WHERE VacTube_Code = '%s' AND install_id = '%s' AND Position = '%s'  ");
			csTemp += _T("	        ORDER BY input_time DESC)												");
			csTemp += _T("	 WHERE ROWNUM < 2																");
			
			csSQL.Format(csTemp,csVactubecode,csInstallID,csLanceID);
			rsResult.DeleteAll();
			if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
			{
				rs.MoveNext();
				continue ;
			}
			rsResult.MoveFirst();
			CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToString();
			SetObjectPropValue(CVACTUBE_FIRE_URI + _T("\\") + csGUID,_T("Fire_End_Time"),CL3Variant(dtCurrentTime));*/
			csObject = csInstallID + csFireCount;

			csTemp = _T("	SELECT *																		");
			csTemp += _T("	  FROM (SELECT   *																");
			csTemp += _T("	            FROM cvactube_fire													");
			csTemp += _T("	           WHERE Object_ID  = '%s'  ");
			csTemp += _T("	        ORDER BY input_time DESC)												");
			csTemp += _T("	 WHERE ROWNUM < 2																");
			
			csSQL.Format(csTemp,csObject);
			rsResult.DeleteAll();
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
			{
				rs.MoveNext();
				continue ;
			}	
			if( rsResult.GetRowCount() > 0)
				SetObjectPropValue(CVACTUBE_FIRE_URI + _T("\\") + csObject,_T("Fire_End_Time"),CL3Variant(dtCurrentTime));
		}
		else if( lMode != 2)	
		{
			rs.MoveNext();
			continue ;
		}
		//2过程：只录入过程数据
		rsFireInfo.AppendRecord();
		rsFireInfo.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsFireInfo.SetFieldByName(_T("VacTube_Code"),CL3Variant(csVactubecode));
		rsFireInfo.SetFieldByName(_T("Install_ID"),CL3Variant(csInstallID));
		rsFireInfo.SetFieldByName(_T("Position"),CL3Variant(csLanceID));
		rsFireInfo.SetFieldByName(_T("Time_ID"),CL3Variant(lTime_ID));
		rsFireInfo.SetFieldByName(_T("Fact_Temp"),CL3Variant(fTemp));
		rsFireInfo.SetFieldByName(_T("Gun_Height"),CL3Variant(fHeight));
		rsFireInfo.SetFieldByName(_T("Gas_Flow"),CL3Variant(fCOFlow));
		rsFireInfo.SetFieldByName(_T("O2_Flow"),CL3Variant(fO2Flow));
		rsFireInfo.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFireInfo.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFireInfo.SetFieldByName(_T("Log_Per"),CL3Variant(GetCurrentUser()));
		rsFireInfo.SetFieldByName(_T("Object_ID"),CL3Variant(csObject));

		rs.MoveNext();
	}
	if(rsFire.GetRowCount() > 0)
		CreateNewObjects(CVACTUBE_FIRE_URI,rsFire);
	
	if(rsFireInfo.GetRowCount() > 0)
		CreateNewObjects(CVACTUBE_FIRE_INFO_URI,rsFireInfo);
	
	return TRUE;
}

/// <Method class="CVacTube_Mag" name="Vactube_Install" type="L3LONG">
/// 真空槽组装　2009-05-13 
/// <Param name="strUpID" type="L3STRING">上部槽号</Param>
/// <Param name="strDownID" type="L3STRING">下部槽号</Param>
/// </Method>
L3LONG CVacTube_Mag::Vactube_Install(L3STRING strUpID, L3STRING strDownID)
{
	// TODO : 请在此添加逻辑代码
	CString csUpID = strUpID;
	CString csDownID = strDownID;
	if(csUpID == _T("") || csDownID == _T(""))
		return -1;//没有真空槽上部槽或下部槽槽号
	
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	
	int iYear = dtCurrentTime.GetYear();
	int iMonth = dtCurrentTime.GetMonth();

	CString csYear;
	csYear.Format(_T("%d"),iYear);
	csYear = csYear.Right(2);

	CString csMonth;
	csMonth.Format(_T("%02d"),iMonth);

	CString csYearMonth = csYear + csMonth;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

	CString csBaseUpURI = CVACTUBE_BASE_URI + _T("\\") + csUpID;
	CString csBaseDownURI = CVACTUBE_BASE_URI + _T("\\") + strDownID;
	
	CString csUpStatus = GetObjectPropValue(csBaseUpURI,_T("Status")).ToCString();
	CString csDownStatus = GetObjectPropValue(csBaseDownURI,_T("Status")).ToCString();

	if(csUpStatus != CVACTUBE_STATUS_REPAIR || csDownStatus != CVACTUBE_STATUS_REPAIR)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//真空槽状态不为维修
	}	
	
	CString csVacTubeCode = csUpID.Right(1) + csDownID.Right(1);
	CString csOldInstallID;
	CString csInstallID;
	CString csOldYearMonth;
	CString csID;
	
	//上部槽编号
	long lUpAge ;
	CString csUpAge =  GetObjectPropValue(csBaseUpURI,_T("VacTube_Age")).ToCString().Trim();
	if(csUpAge == _T(""))
		lUpAge = 0;
	else
		lUpAge = _ttol(csUpAge);

	//下部槽编号
	long lDownAge ;
	CString csDownAge =  GetObjectPropValue(csBaseDownURI,_T("VacTube_Age")).ToCString().Trim();
	if(csDownAge == _T(""))
		lDownAge = 0;
	else
		lDownAge = _ttol(csDownAge);

	//从真空槽组装信息（使用信息）中获取当前最大组装编号
	CString csTemp = _T(" select Max(Install_ID) as Install_ID from CVacTube_Use where VacTube_Code = '%s' and Install_ID is not null");
	CString csSQL;
	csSQL.Format(csTemp,csVacTubeCode);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;//查询失败
	}	
	if(rsResult.GetRowCount() < 1 )
		csInstallID = csYearMonth + csVacTubeCode + _T("01");
	rsResult.MoveFirst();
	csOldInstallID = rsResult.GetFieldByName(_T("Install_ID")).ToCString().Trim();
	if(csOldInstallID == _T(""))
		csID = _T("01");
	else
	{
		csOldYearMonth = csOldInstallID.Left(4);
	
		if(csOldYearMonth != csYearMonth)
			csID = _T("01");
		else
		{
			csID = csOldInstallID.Right(2);
			int iID = _ttoi(csID) + 1;
			csID.Format(_T("%02d"),iID);
		}
	}
	csInstallID = csYearMonth + csVacTubeCode + csID;
	
	SetObjectPropValue(csBaseUpURI,_T("Status"),CL3Variant(CVACTUBE_STATUS_COLD));
	SetObjectPropValue(csBaseUpURI,_T("Install_ID"),CL3Variant(csInstallID));
	SetObjectPropValue(csBaseUpURI,_T("VacTube_Code"),CL3Variant(csVacTubeCode));
	SetObjectPropValue(csBaseUpURI,_T("Flag"),CL3Variant(L3LONG(1)));

	SetObjectPropValue(csBaseDownURI,_T("Status"),CL3Variant(CVACTUBE_STATUS_COLD));
	SetObjectPropValue(csBaseDownURI,_T("Install_ID"),CL3Variant(csInstallID));
	SetObjectPropValue(csBaseDownURI,_T("VacTube_Code"),CL3Variant(csVacTubeCode));
	SetObjectPropValue(csBaseDownURI,_T("Flag"),CL3Variant(L3LONG(1)));
		
	//真空槽使用主信息
	CL3RecordSetWrap rsUse;
	if(!CreateClassPropSet(CVACTUBE_USE_URI,rsUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsUse.AppendRecord();
	rsUse.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
	rsUse.SetFieldByName(_T("Install_ID"),CL3Variant(csInstallID));
	rsUse.SetFieldByName(_T("VacTube_Code"),CL3Variant(csVacTubeCode));
	rsUse.SetFieldByName(_T("Up_Slot_ID"),CL3Variant(csUpID));
	rsUse.SetFieldByName(_T("Bel_Slot_ID"),CL3Variant(csDownID));
	rsUse.SetFieldByName(_T("Up_Total_Age"),CL3Variant(lUpAge));
	rsUse.SetFieldByName(_T("Bel_Total_Age"),CL3Variant(lDownAge));
	/*rsUse.SetFieldByName(_T("Cir_Total_Age"),CL3Variant(L3LONG(0)));
	rsUse.SetFieldByName(_T("Aes_Soa_Total_Len"),CL3Variant(L3LONG(0)));
	rsUse.SetFieldByName(_T("Aes_Soa_Total_Age"),CL3Variant(L3LONG(0)));
	rsUse.SetFieldByName(_T("Des_Soa_Total_Len"),CL3Variant(L3LONG(0)));
	rsUse.SetFieldByName(_T("Des_Soa_Total_Age"),CL3Variant(L3LONG(0)));*/
	rsUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
	rsUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rsUse.MoveFirst();
	if(rsUse.GetRowCount() > 0)
		CreateNewObjects(CVACTUBE_USE_URI,rsUse);

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="VacTubeFire" type="L3LONG">
/// 烘烤位置：2(A预热位)，3(B预热位)，A(A处理位)，B(B处理位)
/// 烘烤类别：1(烘烤开始)，0(烘烤结束)
/// <Param name="strPositon" type="L3STRING">烘烤位置</Param>
/// <Param name="strType" type="L3STRING">烘烤类别</Param>
/// </Method>
L3LONG CVacTube_Mag::VacTubeFire(L3STRING strPositon, L3STRING strType)
{
	// TODO : 请在此添加逻辑代码
	CString csPosition = strPositon;
	CString csType = strType;
	if(csPosition == _T("") || csType == _T(""))
		return -1;//没有烘烤位置或烘烤类型

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CVACTUBE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

	CString csTemp;
	CString csSQL;
	CL3RecordSetWrap rsResult;
	//真空槽编号
	csTemp = _T(" SELECT   VacTube_Code,Install_ID ,Fire_Count   FROM cvactube_base   WHERE POSITION =  '%s' ");
	csTemp += _T(" AND vactube_name < '3'     AND vactube_name > '0' AND VacTube_Code IS NOT NULL");
	csTemp += _T(" GROUP BY VacTube_Code,Install_ID,Fire_Count");
	csSQL.Format(csTemp,csPosition);
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	rsResult.MoveFirst();
	CString csVactubecode = rsResult.GetFieldByName(_T("VacTube_Code")).ToCString();
	CString csInstallID = rsResult.GetFieldByName(_T("Install_ID")).ToCString();
	CString csFireCount = rsResult.GetFieldByName(_T("Fire_Count")).ToCString().Trim();
	if(csFireCount == _T(""))
		csFireCount = _T("0");
	CString csObject;

	//上部槽编号
	CString csUpID = _T("");
	csTemp = _T(" SELECT vactube_id  FROM cvactube_base WHERE POSITION =  '%s'    "); 
	csTemp += _T("AND vactube_code = '%s' AND vactube_name = '1' order by vactube_name");
	csSQL.Format(csTemp,csPosition,csVactubecode);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csUpID =  rsResult.GetFieldByIndex(0).ToCString();
	}

	//下部槽编号
	CString csDownID = _T("");
	csTemp = _T(" SELECT vactube_id  FROM cvactube_base WHERE POSITION =  '%s'    "); 
	csTemp += _T("AND vactube_code = '%s' AND vactube_name = '2' order by vactube_name");
	csSQL.Format(csTemp,csPosition,csVactubecode);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csDownID =  rsResult.GetFieldByIndex(0).ToCString();
	}
	if(csType == _T("1"))//1开始：首先添加主信息
	{
		int iFireCount = _ttoi(csFireCount) + 1;
		csFireCount.Format(_T("%d"),iFireCount);
		csObject = csInstallID + csFireCount;

		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("VacTube_Code"),CL3Variant(csVactubecode));
		rsFire.SetFieldByName(_T("Install_ID"),CL3Variant(csInstallID));
		rsFire.SetFieldByName(_T("Position"),CL3Variant(csPosition));
		rsFire.SetFieldByName(_T("Up_Slot_ID"),CL3Variant(csUpID));
		rsFire.SetFieldByName(_T("Bel_Slot_ID"),CL3Variant(csDownID));
		rsFire.SetFieldByName(_T("Fire_Start_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Log_Per"),CL3Variant(GetCurrentUser()));
		rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csObject));//主键
		rsFire.SetFieldByName(_T("Fire_Soruce"),CL3Variant(L3LONG(1)));
		
		if(csPosition == CVACTUBE_POSITION_FIRE_A ||csPosition == CVACTUBE_POSITION_FIRE_B )
		{
			if(csUpID != _T(""))
			{
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_PRE_FIRE));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(0)));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Fire_Count"),CL3Variant(L3LONG(iFireCount)));
			}
			if(csDownID != _T(""))
			{
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_PRE_FIRE));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(0)));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Fire_Count"),CL3Variant(L3LONG(iFireCount)));
			}
		}
		else if(csPosition == CVACTUBE_POSITION_WORK_A ||csPosition == CVACTUBE_POSITION_WORK_B )
		{
			if(csUpID != _T(""))
			{
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_BIG_FIRE));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(0)));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Fire_Count"),CL3Variant(L3LONG(iFireCount)));
			}
			if(csDownID != _T(""))
			{
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_BIG_FIRE));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(0)));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Fire_Count"),CL3Variant(L3LONG(iFireCount)));
			}
		}
	}
	else if(csType == _T("0"))//0结束：修改主信息
	{
		csObject = csInstallID + csFireCount;

		csTemp = _T("	SELECT *																		");
		csTemp += _T("	  FROM (SELECT   *																");
		csTemp += _T("	            FROM cvactube_fire													");
		csTemp += _T("	           WHERE Object_ID  = '%s'  ");
		csTemp += _T("	        ORDER BY input_time DESC)												");
		csTemp += _T("	 WHERE ROWNUM < 2																");
		
		csSQL.Format(csTemp,csObject);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}	
		if( rsResult.GetRowCount() > 0)
		{
			SetObjectPropValue(CVACTUBE_FIRE_URI + _T("\\") + csObject,_T("Fire_End_Time"),CL3Variant(dtCurrentTime));
		}
		
		if(csPosition == CVACTUBE_POSITION_FIRE_A ||csPosition == CVACTUBE_POSITION_FIRE_B )
		{
			if(csUpID != _T(""))
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(1)));
			if(csDownID != _T(""))
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(1)));
		}
		else if(csPosition == CVACTUBE_POSITION_WORK_A ||csPosition == CVACTUBE_POSITION_WORK_B )
		{
			if(csUpID != _T(""))
			{
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_HOT));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(1)));
			}
			if(csDownID != _T(""))
			{
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_HOT));
				SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(1)));
			}
		}
	}
	else 
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
		
	if(rsFire.GetRowCount() > 0)
		CreateNewObjects(CVACTUBE_FIRE_URI,rsFire);

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="VacTubeCheck" type="L3LONG">
/// 真空槽下线检查
/// <Param name="strPosition" type="L3STRING"></Param>
/// </Method>
L3LONG CVacTube_Mag::VacTubeCheck(L3STRING strPosition)
{
	// TODO : 请在此添加逻辑代码
	CString csPosition = strPosition;
	if(csPosition == _T("") || ((csPosition != CVACTUBE_POSITION_WORK_A) && (csPosition != CVACTUBE_POSITION_WORK_B)))
		return -1;
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	
	CString csTemp;
	CString csSQL;
	CL3RecordSetWrap rsResult;
	//真空槽编号
	csTemp = _T(" SELECT   VacTube_Code   FROM cvactube_base   WHERE POSITION =  '%s'  and Status = '%s'");
	csTemp += _T(" AND vactube_name < '3'     AND vactube_name > '0' AND VacTube_Code IS NOT NULL");
	csTemp += _T(" GROUP BY VacTube_Code");
	csSQL.Format(csTemp,csPosition,CVACTUBE_STATUS_HOT);
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	rsResult.MoveFirst();
	CString csVactubecode = rsResult.GetFieldByName(_T("VacTube_Code")).ToCString();

	if(csVactubecode == _T(""))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//没用真空槽编号
	}	

	//上部槽编号
	CString csUpID = _T("");
	csTemp = _T(" SELECT VacTube_ID  FROM cvactube_base WHERE POSITION =  '%s'   and Status = '%s'");
	csTemp += _T("AND vactube_code = '%s' AND vactube_name = '1' order by vactube_name");
	csSQL.Format(csTemp,csPosition,CVACTUBE_STATUS_HOT,csVactubecode);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csUpID =  rsResult.GetFieldByName(_T("VacTube_ID")).ToCString();
		if(csUpID != _T(""))
		{
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_CHECK));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csUpID ,_T("Flag"),CL3Variant(L3LONG(1)));
		}
	}

	//下部槽编号
	CString csDownID = _T("");
	csTemp = _T(" SELECT VacTube_ID  FROM cvactube_base WHERE POSITION =  '%s'   and Status = '%s'");
	csTemp += _T("AND vactube_code = '%s' AND vactube_name = '2' order by vactube_name");
	csSQL.Format(csTemp,csPosition,CVACTUBE_STATUS_HOT,csVactubecode);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}	
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csDownID = rsResult.GetFieldByName(_T("VacTube_ID")).ToCString();
		if(csUpID != _T(""))
		{
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Status"),CL3Variant(CVACTUBE_STATUS_CHECK));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));
			SetObjectPropValue(CVACTUBE_BASE_URI + _T("\\") + csDownID ,_T("Flag"),CL3Variant(L3LONG(1)));
		}
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="VacTubeCheckOver" type="L3LONG">
/// 真空槽下线检查完毕
/// 1:备用
/// 2:小修
/// 3:重新砌筑
/// <Param name="strVacTubeCode" type="L3STRING">真空槽编号</Param>
/// <Param name="strType" type="L3STRING">操作类型</Param>
/// </Method>
L3LONG CVacTube_Mag::VacTubeCheckOver(L3STRING strVacTubeCode, L3STRING strType)
{
	// TODO : 请在此添加逻辑代码
	CString csVactubeCode = strVacTubeCode;
	CString csType = strType;
	if(csVactubeCode == _T("") || csType == _T(""))
		return -1;//没有真空槽号和类型
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	//2009-05-31
	CString csBaseURI = CVACTUBE_BASE_URI + _T("\\") + csVactubeCode;
	CString csStatus;
	//热弯管
	if(csVactubeCode.Left(1) == _T("R"))
	{
		if(csType == _T("1"))
			csStatus = CVACTUBE_STATUS_COLD;
		else if(csType == _T("2"))
			csStatus = CVACTUBE_STATUS_COLD;
		else if(csType == _T("3"))
		{
			csStatus = CVACTUBE_STATUS_OFFLINE;
			SetObjectPropValue(csBaseURI,_T("VacTube_Age"),CL3Variant(L3LONG(0)));
		}

		SetObjectPropValue(csBaseURI,_T("Status"),CL3Variant(csStatus));
		SetObjectPropValue(csBaseURI,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));
		SetObjectPropValue(csBaseURI,_T("HeatID"),CL3Variant(_T("")));
	}
	else
	{
		if(csType == _T("1"))
		{
			CString csUpID = _T("ZS0") + csVactubeCode.Left(1) ;
			CString csDownID = _T("ZX0") + csVactubeCode.Right(1);
			CString csUpURI = CVACTUBE_BASE_URI + _T("\\") + csUpID;
			CString csDownURI = CVACTUBE_BASE_URI + _T("\\") + csDownID;

			csStatus = CVACTUBE_STATUS_COLD;
			SetObjectPropValue(csUpURI,_T("Flag"),CL3Variant(L3LONG(1)));
			SetObjectPropValue(csDownURI,_T("Flag"),CL3Variant(L3LONG(1)));

			SetObjectPropValue(csUpURI,_T("HeatID"),CL3Variant(_T("")));
			SetObjectPropValue(csUpURI,_T("Status"),CL3Variant(csStatus));
			SetObjectPropValue(csUpURI,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));

			SetObjectPropValue(csDownURI,_T("Status"),CL3Variant(csStatus));
			SetObjectPropValue(csDownURI,_T("HeatID"),CL3Variant(_T("")));
			SetObjectPropValue(csDownURI,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));
		}
		else if(csType == _T("2"))
		{
			csStatus = CVACTUBE_STATUS_REPAIR;
			SetObjectPropValue(csBaseURI,_T("VacTube_Code"),CL3Variant(_T("")));
			SetObjectPropValue(csBaseURI,_T("Install_ID"),CL3Variant(_T("")));
			SetObjectPropValue(csBaseURI,_T("Flag"),CL3Variant(L3LONG(1)));
			SetObjectPropValue(csBaseURI,_T("Fire_Count"),CL3Variant(L3LONG(0)));

			//SetObjectPropValue(csDownURI,_T("VacTube_Code"),CL3Variant(_T("")));
			//SetObjectPropValue(csDownURI,_T("Install_ID"),CL3Variant(_T("")));
			//SetObjectPropValue(csDownURI,_T("Flag"),CL3Variant(L3LONG(1)));
			//SetObjectPropValue(csDownURI,_T("Fire_Count"),CL3Variant(L3LONG(0)));
			SetObjectPropValue(csBaseURI,_T("HeatID"),CL3Variant(_T("")));
			SetObjectPropValue(csBaseURI,_T("Status"),CL3Variant(csStatus));
			SetObjectPropValue(csBaseURI,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));

		}
		else if(csType == _T("3"))
		{
			csStatus = CVACTUBE_STATUS_OFFLINE;
			SetObjectPropValue(csBaseURI,_T("Flag"),CL3Variant(L3LONG(0)));
			SetObjectPropValue(csBaseURI,_T("VacTube_Code"),CL3Variant(_T("")));
			SetObjectPropValue(csBaseURI,_T("Install_ID"),CL3Variant(_T("")));
			SetObjectPropValue(csBaseURI,_T("VacTube_Age"),CL3Variant(L3LONG(0)));
			SetObjectPropValue(csBaseURI,_T("Fire_Count"),CL3Variant(L3LONG(0)));

			SetObjectPropValue(csBaseURI,_T("HeatID"),CL3Variant(_T("")));
			SetObjectPropValue(csBaseURI,_T("Status"),CL3Variant(csStatus));
			SetObjectPropValue(csBaseURI,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));
			//SetObjectPropValue(csDownURI,_T("Flag"),CL3Variant(L3LONG(0)));
			//SetObjectPropValue(csDownURI,_T("VacTube_Code"),CL3Variant(_T("")));
			//SetObjectPropValue(csDownURI,_T("Install_ID"),CL3Variant(_T("")));
			//SetObjectPropValue(csDownURI,_T("VacTube_Age"),CL3Variant(L3LONG(0)));
			//SetObjectPropValue(csDownURI,_T("Fire_Count"),CL3Variant(L3LONG(0)));
		}

	/*	SetObjectPropValue(csUpURI,_T("HeatID"),CL3Variant(_T("")));
		SetObjectPropValue(csUpURI,_T("Status"),CL3Variant(csStatus));
		SetObjectPropValue(csUpURI,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));

		SetObjectPropValue(csDownURI,_T("Status"),CL3Variant(csStatus));
		SetObjectPropValue(csDownURI,_T("HeatID"),CL3Variant(_T("")));
		SetObjectPropValue(csDownURI,_T("Position"),CL3Variant(CVACTUBE_POSITION_BUILD));*/
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="InsertVacTubeRepair" type="L3LONG">
/// 添加真空槽修补信息
/// <Param name="rsRepair" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::InsertVacTubeRepair(L3RECORDSET rsRepair)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsRepair;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CVACTUBE_REPAIR_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CVacTube_Mag" name="UpdateVacTubeRepair" type="L3BOOL">
/// 修改真空槽修补信息
/// <Param name="rsRepair" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::UpdateVacTubeRepair(L3RECORDSET rsRepair)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsRepair,CVACTUBE_REPAIR_URI);
}

/// <Method class="CVacTube_Mag" name="DeleteVacTubeRepair" type="L3BOOL">
/// 删除真空槽修补信息
/// <Param name="rsRepair" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::DeleteVacTubeRepair(L3RECORDSET rsRepair)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsRepair,CVACTUBE_REPAIR_URI);
}

/// <Method class="CVacTube_Mag" name="GetVacTubeRepair" type="L3RECORDSET">
/// 获取真空槽修补信息
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CVacTube_Mag::GetVacTubeRepair(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CVACTUBE_REPAIR_URI,strCondition);
}


/// <Method class="CVacTube_Mag" name="InsertHotSypRepair" type="L3LONG">
/// 添加热弯管修补信息
/// <Param name="rsRepair" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::InsertHotSypRepair(L3RECORDSET rsRepair)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsRepair;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CVACTUBE_HOT_SYP_REPAIR_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CVacTube_Mag" name="UpdateHotSypRepair" type="L3BOOL">
/// 修改热弯管修补信息
/// <Param name="rsRepair" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::UpdateHotSypRepair(L3RECORDSET rsRepair)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsRepair,CVACTUBE_HOT_SYP_REPAIR_URI);
}
/// <Method class="CVacTube_Mag" name="DeleteHotSypRepair" type="L3BOOL">
/// 删除热弯管修补信息
/// <Param name="rsRepair" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::DeleteHotSypRepair(L3RECORDSET rsRepair)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsRepair,CVACTUBE_HOT_SYP_REPAIR_URI);
}
/// <Method class="CVacTube_Mag" name="GetHotSypRepair" type="L3RECORDSET">
/// 获取热弯管修补信息
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CVacTube_Mag::GetHotSypRepair(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CVACTUBE_HOT_SYP_REPAIR_URI,strCondition);
}

/// <Method class="CVacTube_Mag" name="InsertVacTubeFireInfo" type="L3LONG">
/// 添加烘烤详细信息
/// <Param name="rsFireInfo" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::InsertVacTubeFireInfo(L3RECORDSET rsFireInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsFireInfo;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CVACTUBE_FIRE_INFO_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CVacTube_Mag" name="UpdateVacTubeFireInfo" type="L3BOOL">
/// 修改烘烤详细信息
/// <Param name="rsFireInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::UpdateVacTubeFireInfo(L3RECORDSET rsFireInfo)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsFireInfo,CVACTUBE_FIRE_INFO_URI);
}
/// <Method class="CVacTube_Mag" name="DeleteVacTubeFireInfo" type="L3BOOL">
/// 删除烘烤详细信息
/// <Param name="rsFireInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::DeleteVacTubeFireInfo(L3RECORDSET rsFireInfo)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsFireInfo,CVACTUBE_FIRE_INFO_URI);
}
/// <Method class="CVacTube_Mag" name="GetVacTubeFireInfo" type="L3RECORDSET">
/// 获取烘烤详细信息
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CVacTube_Mag::GetVacTubeFireInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CVACTUBE_FIRE_INFO_URI,strCondition);
}

/// <Method class="CVacTube_Mag" name="InsertVacTubeUseInfo" type="L3LONG">
/// 添加真空槽使用详细信息
/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::InsertVacTubeUseInfo(L3RECORDSET rsUseInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsUseInfo;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CVACTUBE_USE_INFO_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CVacTube_Mag" name="UpdateVacTubeUseInfo" type="L3BOOL">
/// 修改真空槽使用详细信息
/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::UpdateVacTubeUseInfo(L3RECORDSET rsUseInfo)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsUseInfo,CVACTUBE_USE_INFO_URI);
}
/// <Method class="CVacTube_Mag" name="DeleteVacTubeUseInfo" type="L3BOOL">
/// 删除真空槽使用详细信息
/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::DeleteVacTubeUseInfo(L3RECORDSET rsUseInfo)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsUseInfo,CVACTUBE_USE_INFO_URI);
}
/// <Method class="CVacTube_Mag" name="GetVacTubeUseInfo" type="L3RECORDSET">
/// 获取真空槽使用详细信息
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CVacTube_Mag::GetVacTubeUseInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CVACTUBE_USE_INFO_URI,strCondition);
}

/// <Method class="CVacTube_Mag" name="InsertHotSypUseInfo" type="L3LONG">
/// 添加热弯管使用信息
/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CVacTube_Mag::InsertHotSypUseInfo(L3RECORDSET rsUseInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsUseInfo;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csVacTubeID = rsData.GetFieldByName(_T("Hot_Syp_ID")).ToCString();
		
		if(csVacTubeID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//热弯管编号为空		
		}
		CString csBaseUri = CVACTUBE_BASE_URI + _T("\\") + csVacTubeID;
		CString csBuildID = GetObjectPropValue(csBaseUri,_T("Build_ID")).ToCString();
		
		CString csRefraFac;
		if(csBuildID != _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//砌筑编号为空
		}
		csRefraFac = GetObjectPropValue(CVACTUBE_HOT_SYP_BUI_URI + _T("\\") + csBuildID,_T("Refra_Fac")).ToCString();
	
		rsData.SetFieldByName(_T("Build_ID"),CL3Variant(csBuildID));
		rsData.SetFieldByName(_T("Refra_Fac"),CL3Variant(csRefraFac));

		rsData.MoveNext();
	}
	rsData.MoveFirst();
	if(CreateNewObjects(CVACTUBE_HOT_SYP_USE_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CVacTube_Mag" name="UpdateHotSypUseInfo" type="L3BOOL">
/// 修改热弯管使用信息
/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::UpdateHotSypUseInfo(L3RECORDSET rsUseInfo)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsUseInfo,CVACTUBE_HOT_SYP_USE_URI);
}
/// <Method class="CVacTube_Mag" name="DeleteHotSypUseInfo" type="L3BOOL">
/// 删除热弯管使用信息
/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CVacTube_Mag::DeleteHotSypUseInfo(L3RECORDSET rsUseInfo)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsUseInfo,CVACTUBE_HOT_SYP_USE_URI);
}
/// <Method class="CVacTube_Mag" name="GetHotSypUseInfo" type="L3RECORDSET">
/// 获取热弯管使用信息
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CVacTube_Mag::GetHotSypUseInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CVACTUBE_HOT_SYP_USE_URI,strCondition);
}

//Modfy begin by llj 2011-04-10 增加上升管的累计时长
/// <Method class="CVacTube_Mag" name="LastVacTubeAesSoaTotalLenOfHeatID" type="L3RECORDSET">
/// 获取该炉次的最后上升管累计时长
/// <Param name="strHeatID" type="L3STRING"></Param>
/// </Method>
L3LONG CVacTube_Mag::LastVacTubeAesSoaTotalLenOfHeatID(L3STRING strHeatID)
{
	CString csHeatID=strHeatID;
	CString csSql;
	csSql.Format(_T("select Aes_Soa_Total_Len from CVacTube_Use_Info where HeatID='%s' order by Input_Time desc "),csHeatID);
	CL3RecordSetWrap rs;
	if(!Query(csSql,rs)||rs.IsNull()||rs.GetRowCount()<1)
		return -1;
	rs.MoveFirst();

	return rs.GetFieldByName(_T("Aes_Soa_Total_Len")).ToLong();
}
//Modify end
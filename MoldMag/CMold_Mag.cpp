// 逻辑类CMold_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CMold_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CMold_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CMold_Mag.h"

//当对象被装载到系统中时，被调用
void CMold_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CMold_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


L3LONG CMold_Mag::UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = rsInfos;
	if(rs.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	CString csUri = lpcsClass;
	rs.MoveFirst();
	if(!SetObjsPropValues(csUri,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

L3LONG CMold_Mag::DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = rsInfos;
	if(rs.GetRowCount() < 1)
		return 0;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	CString csUri = lpcsClass;
	rs.MoveFirst();
	if(DeleteOldObjects(csUri,rs) < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


L3RECORDSET CMold_Mag::GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition =lpcsCondition;
	if(csCondition == _T(""))
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


/// <Method class="CMold_Mag" name="MoldInstallStart" type="L3LONG">
/// 
/// 结晶器装配开始
/// ARG &gt;&gt; rsMolds: 要装配开始的结晶器的记录集。必须包含MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldInstallStart(L3RECORDSET rsMolds)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
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

	//用于修改结晶器基本信息的记录集[20081230]
	CStringArray BaseNames;BaseNames.SetSize(3);
	CUIntArray BaseTypes;BaseTypes.SetSize(3);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("InStallID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	
	CL3RecordSetWrap rsPipeInstall;
	if(!CreateClassPropSet(CMOLD_PIPE_INSTALL_URI,rsPipeInstall))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;//组建铜管装配记录失败
	}
	
	CL3RecordSetWrap rsBoardInstall;
	if(!CreateClassPropSet(CMOLD_BOARD_INSTALL_URI,rsBoardInstall))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;//组建铜管装配记录失败
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		//断面尺寸
		long lFaceMea = rsData.GetFieldByName(_T("Break_Face_Mea")).ToLong();
		//原装配编号
		CString csOldInStallID = rsData.GetFieldByName(_T("InStallID")).ToCString();
		CString csInStallID;
		if(csMoldID == _T("")|| lFaceMea <= 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//不存在结晶器号或没有断面尺寸
		}

		//产生装配编号
		if(csOldInStallID == _T(""))
		{
			csInStallID = csYearMonth + csMoldID + _T("01");
		}
		else
		{
			CString csOldYearMonth = csOldInStallID.Left(4);
			//属于同年同月
			if(csOldYearMonth == csYearMonth)
			{
				CString csOldNO = csOldInStallID.Right(2);
				CString csNO;
				int iNO = _ttoi(csOldNO) + 1;
				csNO.Format(_T("%02d"),iNO);
				csInStallID = csYearMonth + csMoldID + csNO;
			}
			else
			{
				csInStallID = csYearMonth + csMoldID + _T("01");
			}
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CMOLD_STATUS_REPAIR));
		rsBase.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));

		//产生装配记录
		if (lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
		{
			CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
			CL3RecordSetWrap rpSysInfo;
			SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

			rsPipeInstall.AppendRecord();
			rsPipeInstall.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
			rsPipeInstall.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsPipeInstall.SetFieldByName(_T("Install_Date"),CL3Variant(dtCurrentTime));
			rsPipeInstall.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
			rsPipeInstall.SetFieldByName(_T("Repair_Start_Time"),CL3Variant(dtCurrentTime));
			rsPipeInstall.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsPipeInstall.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsPipeInstall.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		else if (lFaceMea == 12)
		{
			CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
			CL3RecordSetWrap rpSysInfo;
			SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

			rsBoardInstall.AppendRecord();
			rsBoardInstall.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
			rsBoardInstall.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsBoardInstall.SetFieldByName(_T("Install_Date"),CL3Variant(dtCurrentTime));
			rsBoardInstall.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
			rsBoardInstall.SetFieldByName(_T("Repair_Start_Time"),CL3Variant(dtCurrentTime));
			rsBoardInstall.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsBoardInstall.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsBoardInstall.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}
	//新增铜管装配记录
	if (rsPipeInstall.GetRowCount() > 0)
	{
		rsPipeInstall.MoveFirst();
		CreateNewObjects(CMOLD_PIPE_INSTALL_URI,rsPipeInstall);
		/*if(CreateNewObjects(CMOLD_PIPE_INSTALL_URI,rsPipeInstall) <  1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}*/
	}
	//新增铜板装配记录
	if (rsBoardInstall.GetRowCount() > 0)
	{
		rsBoardInstall.MoveFirst();
		CreateNewObjects(CMOLD_BOARD_INSTALL_URI,rsBoardInstall);
		/*if(CreateNewObjects(CMOLD_BOARD_INSTALL_URI,rsBoardInstall) <  1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}*/
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="MoldInstallEnd" type="L3LONG">
/// 
/// 结晶器装配结束
/// ARG &gt;&gt; rsMolds: 要装配结束的结晶器的记录集。必须包含MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldInstallEnd(L3RECORDSET rsMolds)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	////用于修改结晶器基本信息的记录集
	//CStringArray BaseNames;BaseNames.SetSize(3);
	//CUIntArray BaseTypes;BaseTypes.SetSize(3);
	//BaseNames[0] = _T("MoldID");
	//BaseNames[1] = _T("Status");
	//BaseNames[2] = _T("InStallID");

	//BaseTypes[0] = L3VT_STRING;
	//BaseTypes[1] = L3VT_STRING;
	//BaseTypes[2] = L3VT_STRING;

	//CL3RecordSetWrap rsBase;
	//if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	//{
	//	if(bUseTrans)
	//		Rollback(nTrans);
	//	return 0;
	//}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		//断面尺寸
		long lFaceMea = rsData.GetFieldByName(_T("Break_Face_Mea")).ToLong();
		//装配编号
		CString csInStallID = rsData.GetFieldByName(_T("InStallID")).ToCString();

		if(csMoldID == _T("") || lFaceMea <= 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//不存在结晶器号或没有断面尺寸
		}
		
		SetObjectPropValue(CMOLD_BASE_URI + _T("\\") + csMoldID,_T("Status"),CL3Variant(CMOLD_STATUS_FREE));
		/*rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CMOLD_STATUS_FREE));
		rsBase.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));*/
		//修改装配结束时间
		if (lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
		{
			CString csUri = CMOLD_PIPE_INSTALL_URI + _T("\\") + csInStallID ;
			SetObjectPropValue(csUri,_T("Repair_End_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
			//if(!SetObjectPropValue(csUri,_T("Repair_End_Time"),CL3Variant(COleDateTime::GetCurrentTime())))
			//{
			//	if(bUseTrans)
			//		Rollback(nTrans);
			//	return -2;//修改不成功
			//}
		}
		else if (lFaceMea == 12)
		{
			CString csUri = CMOLD_BOARD_INSTALL_URI + _T("\\") + csInStallID ;
			SetObjectPropValue(csUri,_T("Repair_End_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
			//if(!SetObjectPropValue(csUri,_T("Repair_End_Time"),CL3Variant(COleDateTime::GetCurrentTime())))
			//{
			//	if(bUseTrans)
			//		Rollback(nTrans);
			//	return -2;//修改不成功
			//}
		}
		rsData.MoveNext();
	}
	/*rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}*/
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="MoldOnLine" type="L3LONG">
/// 
/// 结晶器换上操作
/// ARG &gt;&gt; rsMolds: 要换上的结晶器的记录集。必须包含MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldOnLine(L3RECORDSET rsMolds)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	//用于修改结晶器基本信息的记录集
	CStringArray BaseNames;BaseNames.SetSize(6);
	CUIntArray BaseTypes;BaseTypes.SetSize(6);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("Cast_ID");
	BaseNames[3] = _T("FlowID");
	BaseNames[4] = _T("Copper_Fac");
	BaseNames[5] = _T("Copper_ID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;
	BaseTypes[3] = L3VT_STRING;
	BaseTypes[4] = L3VT_STRING;
	BaseTypes[5] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	
	CL3RecordSetWrap rsPipeUse;
	if(!CreateClassPropSet(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;//组建铜管使用记录失败
	}
	
	CL3RecordSetWrap rsBoardUse;
	if(!CreateClassPropSet(CMOLD_BOARD_PAR_USE_URI,rsBoardUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;//组建铜管使用记录失败
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csCastID = rsData.GetFieldByName(_T("Cast_ID")).ToCString();
		CString csFlowID = rsData.GetFieldByName(_T("FlowID")).ToCString();
		
		CString csBaseUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		
		long lFaceMea = GetObjectPropValue(csBaseUri,_T("Break_Face_Mea")).ToLong();//断面尺寸
		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();//结晶器状态
		CString csInStallID = GetObjectPropValue(csBaseUri,_T("InStallID")).ToCString();
		CString csCopperFac;// = rsData.GetFieldByName(_T("Copper_Fac")).ToCString();
		CString csCopperID;// = rsData.GetFieldByName(_T("Copper_ID")).ToCString();
	
		if(csMoldID == _T("") || csCastID == _T("") || csFlowID == _T("")|| csInStallID == _T("")||lFaceMea <= 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//结晶器、铸机号、流号、装配编号至少有一个为空//断面尺寸不正确
		}

		if(csStatus != CMOLD_STATUS_FREE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//结晶器状态不为冷备
		}

		CString csTemp = _T("Select * From %s where Cast_ID = '%s' and FlowID = '%s' and Status = '%s' ");
		CString csSQL;	
		csSQL.Format(csTemp,CMOLD_BASE_URI,csCastID,csFlowID,CMOLD_STATUS_USE);
		
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if(rsResult.GetRowCount() > 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//当前铸机当前流上已经有结晶器
		}
		//新增装配使用记录
		if (lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
		{
			CString csTempExist =  _T("Select * From %s where InStallID = '%s' ");
			CString csSQLExist;	
			csSQLExist.Format(csTempExist,CMOLD_PIPE_PAR_USEI_URI,csInStallID);
			CL3RecordSetWrap rsResultExist;
			if(!Query(csSQLExist,rsResultExist) || rsResultExist.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}

			if (rsResultExist.GetRowCount() < 1)//判断当前是否存在使用记录，不存在就新增，否则修改
			{
				#pragma region "新增装配记录"
				CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
				CL3RecordSetWrap rpSysInfo;
				SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
				
				CString csTempPipe = _T("Select * From %s where InStallID = '%s' ");
				CString csSQLPipe;	
				csSQLPipe.Format(csTempPipe,CMOLD_PIPE_INSTALL_URI,csInStallID);
				CL3RecordSetWrap rsResultPipe;
				if(!Query(csSQLPipe,rsResultPipe) || rsResultPipe.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				if (rsResultPipe.GetRowCount()>0)
				{
					rsResultPipe.MoveFirst();
				
					csCopperFac = rsResultPipe.GetFieldByName(_T("Copper_Fac")).ToCString();
					csCopperID = rsResultPipe.GetFieldByName(_T("Copper_ID")).ToCString();

					rsPipeUse.AppendRecord();
					rsPipeUse.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));//装配编号
					rsPipeUse.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//录入日期
					rsPipeUse.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));//铸机号
					rsPipeUse.SetFieldByName(_T("FlowID"),CL3Variant(csFlowID));//流号
					rsPipeUse.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));//结晶器号
					rsPipeUse.SetFieldByName(_T("Copper_Fac"),CL3Variant(csCopperFac));//铜管厂家
					rsPipeUse.SetFieldByName(_T("Copper_ID"),CL3Variant(csCopperID));//铜管编号
					rsPipeUse.SetFieldByName(_T("OnLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//上线时间
					rsPipeUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));//班别
					rsPipeUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));//班次
					rsPipeUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//操作人员
				}
				#pragma endregion
			}
			else
			{
				#pragma region "修改装配记录"
				CString csTempPipe = _T("Select * From %s where InStallID = '%s' ");
				CString csSQLPipe;	
				csSQLPipe.Format(csTempPipe,CMOLD_PIPE_INSTALL_URI,csInStallID);
				CL3RecordSetWrap rsResultPipe;
				if(!Query(csSQLPipe,rsResultPipe) || rsResultPipe.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				if (rsResultPipe.GetRowCount()>0)
				{
					rsResultPipe.MoveFirst();
				
					csCopperFac = rsResultPipe.GetFieldByName(_T("Copper_Fac")).ToCString();
					csCopperID = rsResultPipe.GetFieldByName(_T("Copper_ID")).ToCString();
					
					CString csPipeUri = CMOLD_PIPE_PAR_USEI_URI + _T("\\") + csInStallID;
					SetObjectPropValue(csPipeUri,_T("Cast_ID"),CL3Variant(csCastID));//铸机号
					SetObjectPropValue(csPipeUri,_T("FlowID"),CL3Variant(csFlowID));//流号
					SetObjectPropValue(csPipeUri,_T("MoldID"),CL3Variant(csMoldID));//结晶器号
					SetObjectPropValue(csPipeUri,_T("Copper_Fac"),CL3Variant(csCopperFac));//铜管厂家
					SetObjectPropValue(csPipeUri,_T("Copper_ID"),CL3Variant(csCopperID));//铜管编号
				}
			}
			#pragma endregion

		}
		else if (lFaceMea == 12)//五号机
		{
			CString csTempExist =  _T("Select * From %s where InStallID = '%s' ");
			CString csSQLExist;	
			csSQLExist.Format(csTempExist,CMOLD_BOARD_PAR_USE_URI,csInStallID);
			CL3RecordSetWrap rsResultExist;
			if(!Query(csSQLExist,rsResultExist) || rsResultExist.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			if (rsResultExist.GetRowCount() < 1)//判断当前是否存在使用记录，不存在就新增，否则修改
			{
				#pragma region
				CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
				CL3RecordSetWrap rpSysInfo;
				SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

				CString csTempBoard = _T("Select * From %s where InStallID = '%s' ");
				CString csSQLBoard;	
				csSQLBoard.Format(csTempBoard,CMOLD_BOARD_INSTALL_URI,csInStallID);
				CL3RecordSetWrap rsResultBoard;
				if(!Query(csSQLBoard,rsResultBoard) || rsResultBoard.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				if (rsResultBoard.GetRowCount()>0)
				{
					rsResultBoard.MoveFirst();
					
					csCopperFac = rsResultBoard.GetFieldByName(_T("Copper_Fac")).ToCString();
					csCopperID = rsResultBoard.GetFieldByName(_T("Inner_ID")).ToCString() + _T("*") + rsResultBoard.GetFieldByName(_T("Outer_ID")).ToCString() + _T("*")
						+ rsResultBoard.GetFieldByName(_T("South_ID")).ToCString() + _T("*") + rsResultBoard.GetFieldByName(_T("North_ID")).ToCString() ;

					rsBoardUse.AppendRecord();
					rsBoardUse.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));//装配编号
					rsBoardUse.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//录入日期
					rsBoardUse.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));//铸机号
					rsBoardUse.SetFieldByName(_T("FlowID"),CL3Variant(csFlowID));//流号
					rsBoardUse.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));//结晶器号
					
					rsBoardUse.SetFieldByName(_T("Inner_ID"),rsResultBoard.GetFieldByName(_T("Inner_ID")));//铜板内弧编号
					rsBoardUse.SetFieldByName(_T("Outer_ID"),rsResultBoard.GetFieldByName(_T("Outer_ID")));//铜板外弧编号
					rsBoardUse.SetFieldByName(_T("South_ID"),rsResultBoard.GetFieldByName(_T("South_ID")));//铜板南侧编号
					rsBoardUse.SetFieldByName(_T("North_ID"),rsResultBoard.GetFieldByName(_T("North_ID")));//铜板北侧编号
					rsBoardUse.SetFieldByName(_T("Copper_Fac"),rsResultBoard.GetFieldByName(_T("Copper_Fac")));//铜管厂家
					rsBoardUse.SetFieldByName(_T("Lug_Steel_Mea"),rsResultBoard.GetFieldByName(_T("Lug_Steel_Mea")));//通钢量
					rsBoardUse.SetFieldByName(_T("Total_Pull_Mea"),rsResultBoard.GetFieldByName(_T("Lug_Steel_Mea")));//通钢量

					rsBoardUse.SetFieldByName(_T("OnLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//上线时间
					rsBoardUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));//班别
					rsBoardUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));//班次
					rsBoardUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//操作人员

					
				}

				#pragma endregion
			}
			else
			{
				CString csTempBoard = _T("Select * From %s where InStallID = '%s' ");
				CString csSQLBoard;	
				csSQLBoard.Format(csTempBoard,CMOLD_BOARD_INSTALL_URI,csInStallID);
				CL3RecordSetWrap rsResultBoard;
				if(!Query(csSQLBoard,rsResultBoard) || rsResultBoard.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				if (rsResultBoard.GetRowCount()>0)
				{
					rsResultBoard.MoveFirst();
					
					csCopperFac = rsResultBoard.GetFieldByName(_T("Copper_Fac")).ToCString();
					csCopperID = rsResultBoard.GetFieldByName(_T("Inner_ID")).ToCString() + _T("*") + rsResultBoard.GetFieldByName(_T("Outer_ID")).ToCString() + _T("*")
						+ rsResultBoard.GetFieldByName(_T("South_ID")).ToCString() + _T("*") + rsResultBoard.GetFieldByName(_T("North_ID")).ToCString() ;

					CString csBoardUri = CMOLD_BOARD_PAR_USE_URI + _T("\\") + csInStallID;

					SetObjectPropValue(csBoardUri,_T("Cast_ID"),CL3Variant(csCastID));//铸机号
					SetObjectPropValue(csBoardUri,_T("FlowID"),CL3Variant(csFlowID));//流号
					//SetObjectPropValue(csBoardUri,_T("MoldID"),CL3Variant(csMoldID));//结晶器号
					//SetObjectPropValue(csBoardUri,_T("Inner_ID"),rsResultBoard.GetFieldByName(_T("Inner_ID")));//铜板内弧编号
					//SetObjectPropValue(csBoardUri,_T("Outer_ID"),rsResultBoard.GetFieldByName(_T("Outer_ID")));//铜板外弧编号
					//SetObjectPropValue(csBoardUri,_T("South_ID"),rsResultBoard.GetFieldByName(_T("South_ID")));//铜板南侧编号
					//SetObjectPropValue(csBoardUri,_T("North_ID"),rsResultBoard.GetFieldByName(_T("North_ID")));//铜板北侧编号
					//SetObjectPropValue(csBoardUri,_T("Copper_Fac"),rsResultBoard.GetFieldByName(_T("Copper_Fac")));//铜管厂家
					//SetObjectPropValue(csBoardUri,_T("Lug_Steel_Mea"),rsResultBoard.GetFieldByName(_T("Lug_Steel_Mea")));//铜管拉钢量
				}
			}

			//Modify begin by llj 2011-04-114 修改结晶器铜板的通钢量
			CString csSql;
			csSql.Format(_T("select Total_Weight from %s where Copper_ID='%s' ordery by Stop_Time desc " ),CCM_HEAT_STRANDINFO_CLASS_URI,csCopperID);
			CL3RecordSetWrap rsHeatStandInfo;
			if(Query(csSql,rsHeatStandInfo)&&!rsHeatStandInfo.IsNull()&&rsHeatStandInfo.GetRowCount()>0)
			{
				rsHeatStandInfo.MoveFirst();
				CString csCCMMagUri =  CCM_CLASS_URI+_T("\\")+csCastID;
				CString csSunCastWeightNo=_T("SumCastWeight")+csFlowID+_T("st");
				SetObjectPropValue(csCCMMagUri,csSunCastWeightNo,rsHeatStandInfo.GetFieldByName(_T("Total_Weight")));
			}
			//Modify end


		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CMOLD_STATUS_USE));
		rsBase.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));
		rsBase.SetFieldByName(_T("FlowID"),CL3Variant(csFlowID));
		rsBase.SetFieldByName(_T("Copper_Fac"),CL3Variant(csCopperFac));
		rsBase.SetFieldByName(_T("Copper_ID"),CL3Variant(csCopperID));

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}
	//新增铜管使用记录
	if (rsPipeUse.GetRowCount() > 0)
	{
		rsPipeUse.MoveFirst();
		CreateNewObjects(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse);

		/*if(CreateNewObjects(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse) <  1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}*/
	}
	//新增铜板使用记录
	if (rsBoardUse.GetRowCount() > 0)
	{
		rsBoardUse.MoveFirst();
		CreateNewObjects(CMOLD_BOARD_PAR_USE_URI,rsBoardUse);
		/*if(CreateNewObjects(CMOLD_BOARD_PAR_USE_URI,rsBoardUse) <  1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}*/
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="MoldOffLine" type="L3LONG">
/// 
/// 结晶器换下操作检测
/// ARG &gt;&gt; rsMolds: 要换下的结晶器的记录集。必须包含MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldOffLine(L3RECORDSET rsMolds)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
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
		//2009-06-04
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		
		CString csBaseUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		
		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();//结晶器状态
		CString csInStallID = GetObjectPropValue(csBaseUri,_T("InStallID")).ToCString();
		
		CString csCastID = GetObjectPropValue(csBaseUri,_T("Cast_ID")).ToCString();
		CString csFlowID = GetObjectPropValue(csBaseUri,_T("FlowID")).ToCString();

		if(csMoldID == _T("") || csCastID == _T("") || csFlowID == _T("")|| csInStallID == _T("") )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//结晶器、铸机号、流号、装配编号至少有一个为空//断面尺寸不正确
		}
		if(csStatus != CMOLD_STATUS_USE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//状态不为使用
		}
		//修改结晶器基本信息
		CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID ;

		if(!SetObjectPropValue(csUri,_T("Status"),CL3Variant(CMOLD_STATUS_OFFLINE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//修改状态失败
		}

		//铸机工序管理Uri
		CString csCCMUnitUri = CCM_CLASS_URI + _T("\\") + csCastID ;
		double dHeatWeight = 0;
		int iFlowID = _ttoi(csFlowID);
		switch (iFlowID)
		{
			case 1:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight1st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight1st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -4;//修改铸机累计通钢量失败
				}
				break;
			case 2:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight2st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight2st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				}
				break;
			case 3:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight3st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight3st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				}
				break;
			case 4:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight4st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight4st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				}
				break;
		}
		
		try
		{
			if(dHeatWeight > 0.0)
			{
				CString csBoardUri = CMOLD_BOARD_PAR_USE_URI + _T("\\") + csInStallID ;

				double dLug_Steel_Mea = GetObjectPropValue(csBoardUri,_T("Total_Pull_Mea")).ToDouble();
				dHeatWeight = dHeatWeight + dLug_Steel_Mea;
				
				SetObjectPropValue(csBoardUri,_T("Total_Pull_Mea"),CL3Variant(dHeatWeight));
			}
		}
		catch(...)
		{}
		
		/************************************************************************************************/
		//产生结晶器检测记录 2009-08-20 liao
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csSQL;
		csSQL.Format(_T("select * from %s where InstallID = '%s'"),CMOLD_BOARD_INSTALL_URI,csInStallID);
		
		CL3RecordSetWrap rsMoldInstall;
		Query(csSQL,rsMoldInstall);

		CL3RecordSetWrap rsMoldCheck;
		if(!CreateClassPropSet(_T("XGMESLogic\\MoldMag\\CMold_Board_Check"),rsMoldCheck))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
	
		if(rsMoldInstall.GetRowCount() > 0)
		{
			rsMoldCheck.CopyFrom(rsMoldInstall);
		}
		else
		{
			rsMoldCheck.AppendRecord();
			rsMoldCheck.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
			rsMoldCheck.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
		}
		rsMoldCheck.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsMoldCheck.SetFieldByName(_T("Check_Date"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsMoldCheck.SetFieldByName(_T("Lug_Steel_Mea"),CL3Variant(dHeatWeight));
		rsMoldCheck.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsMoldCheck.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsMoldCheck.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		rsMoldCheck.SetFieldByName(_T("Note"),CL3Variant(_T("")));

		rsMoldCheck.MoveFirst();
		CreateNewObjects(_T("XGMESLogic\\MoldMag\\CMold_Board_Check"),rsMoldCheck);
		/************************************************************************************************/
	
		rsData.MoveNext();
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CMold_Mag" name="MoldCheckCold" type="L3LONG">
/// 结晶器检测完毕判为备用
/// <Param name="dsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldCheckCold(L3RECORDSET dsMolds)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	//用于修改结晶器基本信息的记录集
	CStringArray BaseNames;BaseNames.SetSize(2);
	CUIntArray BaseTypes;BaseTypes.SetSize(2);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	/*BaseNames[2] = _T("Cast_ID");
	BaseNames[3] = _T("FlowID");
	BaseNames[4] = _T("Copper_Fac");
	BaseNames[5] = _T("Copper_ID");*/

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	/*BaseTypes[2] = L3VT_STRING;
	BaseTypes[3] = L3VT_STRING;
	BaseTypes[4] = L3VT_STRING;
	BaseTypes[5] = L3VT_STRING;*/

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID"));
		if(csMoldID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CMOLD_STATUS_FREE));
		rsBase.SetFieldByName(_T("Cast_ID"),CL3Variant(CMOLD_STATUS_FREE));
		rsBase.SetFieldByName(_T("FlowID"),CL3Variant(CMOLD_STATUS_FREE));

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;

}

/// <Method class="CMold_Mag" name="MoldCheckBuild" type="L3LONG">
/// 结晶器检测完毕判为待装
/// <Param name="dsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldCheckBuild(L3RECORDSET dsMolds)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	//用于修改结晶器基本信息的记录集
	CStringArray BaseNames;BaseNames.SetSize(6);
	CUIntArray BaseTypes;BaseTypes.SetSize(6);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("Cast_ID");
	BaseNames[3] = _T("FlowID");
	BaseNames[4] = _T("Copper_Fac");
	BaseNames[5] = _T("Copper_ID"); 

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;
	BaseTypes[3] = L3VT_STRING;
	BaseTypes[4] = L3VT_STRING;
	BaseTypes[5] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		
		CString csBaseUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		
		long lFaceMea = GetObjectPropValue(csBaseUri,_T("Break_Face_Mea")).ToLong();//断面尺寸
		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();//结晶器状态
		CString csInStallID = GetObjectPropValue(csBaseUri,_T("InStallID")).ToCString();
		
		CString csCastID = GetObjectPropValue(csBaseUri,_T("Cast_ID")).ToCString();
		CString csFlowID = GetObjectPropValue(csBaseUri,_T("FlowID")).ToCString();
		CString csCopperFac = GetObjectPropValue(csBaseUri,_T("Copper_Fac")).ToCString();
		CString csCopperID = GetObjectPropValue(csBaseUri,_T("Copper_ID")).ToCString();

		if(csMoldID == _T("") || csCastID == _T("") || csFlowID == _T("")|| csInStallID == _T("")|| lFaceMea <= 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//结晶器、铸机号、流号、装配编号至少有一个为空//断面尺寸不正确
		}
		if(csStatus != CMOLD_STATUS_USE && csStatus != CMOLD_STATUS_OFFLINE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//状态不为使用
		}
		//修改结晶器基本信息
		CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID ;
		SetObjectPropValue(csUri,_T("Status"),CL3Variant(CMOLD_STATUS_WAIT));
		SetObjectPropValue(csUri,_T("Cast_ID"),CL3Variant(_T("")));
		SetObjectPropValue(csUri,_T("FlowID"),CL3Variant(_T("")));
		SetObjectPropValue(csUri,_T("Copper_Fac"),CL3Variant(_T("")));
		SetObjectPropValue(csUri,_T("Copper_ID"),CL3Variant(_T("")));

		//铸机工序管理Uri
		CString csCCMUnitUri = CCM_CLASS_URI + _T("\\") + csCastID ;
		double dHeatWeight = 0;
		int iFlowID = _ttoi(csFlowID);
		switch (iFlowID)
		{
			case 1:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight1st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight1st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				break;
			case 2:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight2st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight2st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				break;
			case 3:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight3st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight3st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				break;
			case 4:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight4st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight4st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				break;
		}
		
		//完善使用信息
		if (lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
		{
			CString csPipeUri = CMOLD_PIPE_PAR_USEI_URI + _T("\\") + csInStallID ;
		
			//2009-04-13
			SetObjectPropValue(csPipeUri,_T("Total_Pull_Mea"),CL3Variant(dHeatWeight));
			SetObjectPropValue(csPipeUri,_T("OffLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		
		}
		else if (lFaceMea == 12)//五号机
		{
			//只修改下线时间，通钢量在下线检查的时候计算 2009-06-04
			CString csBoardUri = CMOLD_BOARD_PAR_USE_URI + _T("\\") + csInStallID ;
			
			//double dLug_Steel_Mea = GetObjectPropValue(csBoardUri,_T("Lug_Steel_Mea")).ToDouble();

			//dHeatWeight = dHeatWeight + dLug_Steel_Mea;//=
			////2009-04-13
			//SetObjectPropValue(csBoardUri,_T("Total_Pull_Mea"),CL3Variant(dHeatWeight));
			SetObjectPropValue(csBoardUri,_T("OffLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		}
		
		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CMold_Mag" name="InsertPipeInstallInfo" type="L3LONG">
/// 
/// 添加铜管装配实绩
/// ARG &gt;&gt; rsPipeInstalls: 要添加的铜管装配的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::InsertPipeInstallInfo(L3RECORDSET rsPipeInstalls)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsPipeInstalls;
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

	//用于修改结晶器基本信息的记录集[20081230]
	CStringArray BaseNames;BaseNames.SetSize(3);
	CUIntArray BaseTypes;BaseTypes.SetSize(3);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Copper_Fac");
	BaseNames[2] = _T("Copper_ID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csCopperFac = rsData.GetFieldByName(_T("Copper_Fac")).ToCString();
		CString csCopperID = rsData.GetFieldByName(_T("Copper_ID")).ToCString();
		CString csInStallID = GetObjectPropValue(CMOLD_BASE_URI + _T("\\") + csMoldID,_T("InStallID")).ToCString();
		
		if(csMoldID == _T("")||csInStallID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//结晶器号或装配编号为空
		}

		CString csTemp = _T(" select * from %s where InStallID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CMOLD_PIPE_INSTALL_URI,csInStallID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//查询装配记录失败
		}
		if(rsResult.GetRowCount() > 0 )//当前存在装配记录
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//当前存在装配记录，不允许新增
		}
		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Copper_Fac"),CL3Variant(csCopperFac));
		rsBase.SetFieldByName(_T("Copper_ID"),CL3Variant(csCopperID));

		rsData.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CMOLD_PIPE_INSTALL_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}

	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="UpdatePipeInstallInfo" type="L3LONG">
/// 
/// 修改铜管装配实绩
/// ARG &gt;&gt; rsPipeInstalls: 要修改的铜管装配的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::UpdatePipeInstallInfo(L3RECORDSET rsPipeInstalls)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsPipeInstalls,CMOLD_PIPE_INSTALL_URI);
}

/// <Method class="CMold_Mag" name="DeletePipeInstallInfo" type="L3LONG">
/// 
/// 删除铜管装配实绩
/// ARG &gt;&gt; rsPipeInstalls: 要删除的铜管装配的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::DeletePipeInstallInfo(L3RECORDSET rsPipeInstalls)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsPipeInstalls,CMOLD_PIPE_INSTALL_URI);
}

/// <Method class="CMold_Mag" name="GetPipeInstallInfo" type="L3RECORDSET">
/// 
/// 获取铜管装配实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsPipeInstalls；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CMold_Mag::GetPipeInstallInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CMOLD_PIPE_INSTALL_URI,strCondition);
}

/// <Method class="CMold_Mag" name="InsertBoardInstallInfo" type="L3LONG">
/// 
/// 添加铜板装配实绩
/// ARG &gt;&gt; rsBoardInstalls: 要添加的铜管装配的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::InsertBoardInstallInfo(L3RECORDSET rsBoardInstalls)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsBoardInstalls;
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

	//用于修改结晶器基本信息的记录集
	CStringArray BaseNames;BaseNames.SetSize(3);
	CUIntArray BaseTypes;BaseTypes.SetSize(3);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Copper_Fac");
	BaseNames[2] = _T("Copper_ID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csCopperFac = rsData.GetFieldByName(_T("Copper_Fac")).ToCString();
		
		CString csInnerID = rsData.GetFieldByName(_T("Inner_ID")).ToCString();
		CString csOuterID = rsData.GetFieldByName(_T("Outer_ID")).ToCString();
		CString csSouthID = rsData.GetFieldByName(_T("South_ID")).ToCString();
		CString csNorthID = rsData.GetFieldByName(_T("North_ID")).ToCString();
		
		CString csInStallID = GetObjectPropValue(CMOLD_BASE_URI + _T("\\") + csMoldID,_T("InStallID")).ToCString();

		CString csCopperID = csInnerID + _T("*") + csOuterID + _T("*") + csSouthID  + _T("*") + csNorthID;

		if(csMoldID == _T("") || csInStallID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//结晶器号或装配编号为空
		}
		
		CString csTemp = _T(" select * from %s where InStallID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CMOLD_BOARD_INSTALL_URI,csInStallID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//查询装配记录失败
		}
		if(rsResult.GetRowCount() > 0 )//当前存在装配记录
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//当前存在装配记录，不允许新增
		}
		rsData.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Copper_Fac"),CL3Variant(csCopperFac));
		rsBase.SetFieldByName(_T("Copper_ID"),CL3Variant(csCopperID));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CMOLD_BOARD_INSTALL_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}

	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="UpdateBoardInstallInfo" type="L3LONG">
/// 
/// 修改铜板装配实绩
/// ARG &gt;&gt; rsBoardInstalls: 要修改的铜管装配的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::UpdateBoardInstallInfo(L3RECORDSET rsBoardInstalls)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsBoardInstalls,CMOLD_BOARD_INSTALL_URI);
}

/// <Method class="CMold_Mag" name="DeleteBoardInstallInfo" type="L3LONG">
/// 
/// 删除铜板装配实绩
/// ARG &gt;&gt; rsBoardInstalls: 要删除的铜管装配的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::DeleteBoardInstallInfo(L3RECORDSET rsBoardInstalls)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsBoardInstalls,CMOLD_BOARD_INSTALL_URI);
}

/// <Method class="CMold_Mag" name="GetBoardInstallInfo" type="L3RECORDSET">
/// 
/// 获取铜板装配实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsBoardInstalls:；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CMold_Mag::GetBoardInstallInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CMOLD_BOARD_INSTALL_URI,strCondition);
}

/// <Method class="CMold_Mag" name="InsertPipeUseInfo" type="L3LONG">
/// 
/// 添加铜管使用实绩
/// ARG &gt;&gt; rsPipeUses: 要添加的铜管使用的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::InsertPipeUseInfo(L3RECORDSET rsPipeUses)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsPipeUses;
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
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		
		CString csFac = GetObjectPropValue(csUri ,_T("Copper_Fac")).ToCString();
		CString csID = GetObjectPropValue(csUri ,_T("Copper_ID")).ToCString();
		CString csInStallID = GetObjectPropValue(csUri,_T("InStallID")).ToCString();

		if(csMoldID == _T("")||csInStallID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//结晶器号或装配编号为空
		}

		CString csTemp = _T(" select * from %s where InStallID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CMOLD_PIPE_PAR_USEI_URI,csInStallID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//查询装配记录失败
		}
		if(rsResult.GetRowCount() > 0 )//当前存在装配记录
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//当前存在装配记录，不允许新增
		}

		rsData.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
		rsData.SetFieldByName(_T("Copper_Fac"),CL3Variant(csFac));
		rsData.SetFieldByName(_T("Copper_ID"),CL3Variant(csID));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CMOLD_PIPE_PAR_USEI_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="UpdatePipeUseInfo" type="L3LONG">
/// 
/// 修改铜管使用实绩
/// ARG &gt;&gt; rsPipeUses: 要修改的铜管使用的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::UpdatePipeUseInfo(L3RECORDSET rsPipeUses)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsPipeUses,CMOLD_PIPE_PAR_USEI_URI);
}

/// <Method class="CMold_Mag" name="DeletePipeUseInfo" type="L3LONG">
/// 
/// 删除铜管使用实绩
/// ARG &gt;&gt; rsPipeUses: 要删除的铜管使用的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::DeletePipeUseInfo(L3RECORDSET rsPipeUses)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsPipeUses,CMOLD_PIPE_PAR_USEI_URI);
}

/// <Method class="CMold_Mag" name="GetPipeUseInfo" type="L3RECORDSET">
/// 
/// 获取铜管装配实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsPipeUses；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CMold_Mag::GetPipeUseInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CMOLD_PIPE_PAR_USEI_URI,strCondition);
}

/// <Method class="CMold_Mag" name="InsertBoardUseInfo" type="L3LONG">
/// 
/// 添加铜板使用实绩
/// ARG &gt;&gt; rsBoardUses: 要添加的铜板使用的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回0。
/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::InsertBoardUseInfo(L3RECORDSET rsBoardUses)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsBoardUses;
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
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		CString csFac = GetObjectPropValue(csUri ,_T("Copper_Fac")).ToCString();
		CString csID = GetObjectPropValue(csUri ,_T("Copper_ID")).ToCString();//0000*11111*2222*33333
		
		CString csInStallID = GetObjectPropValue(csUri,_T("InStallID")).ToCString();

		if(csMoldID == _T("")||csInStallID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//结晶器号或装配编号为空
		}

		CString csTemp = _T(" select * from %s where InStallID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CMOLD_BOARD_PAR_USE_URI,csInStallID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//查询装配记录失败
		}
		if(rsResult.GetRowCount() > 0 )//当前存在装配记录
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//当前存在装配记录，不允许新增
		}

		int iPosition = csID.FindOneOf(_T("*"));
		CString csInnerID = csID.Left(iPosition);
		csID = csID.Right(csID.GetLength() - iPosition - 1);
		
		iPosition = csID.FindOneOf(_T("*"));
		CString csOuterID = csID.Left(iPosition);
		csID = csID.Right(csID.GetLength() - iPosition - 1);

		iPosition = csID.FindOneOf(_T("*"));
		CString csSouthID = csID.Left(iPosition);
		csID = csID.Right(csID.GetLength() - iPosition - 1);

		CString csNorthID = csID;

		rsData.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
		rsData.SetFieldByName(_T("Copper_Fac"),CL3Variant(csFac));
		rsData.SetFieldByName(_T("Inner_ID"),CL3Variant(csInnerID));
		rsData.SetFieldByName(_T("Outer_ID"),CL3Variant(csOuterID));
		rsData.SetFieldByName(_T("South_ID"),CL3Variant(csSouthID));
		rsData.SetFieldByName(_T("North_ID"),CL3Variant(csNorthID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CMOLD_BOARD_PAR_USE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="UpdateBoardUseInfo" type="L3LONG">
/// 
/// 修改铜板使用实绩
/// ARG &gt;&gt; rsBoardUses: 要修改的铜板使用的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::UpdateBoardUseInfo(L3RECORDSET rsBoardUses)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsBoardUses,CMOLD_BOARD_PAR_USE_URI);
}

/// <Method class="CMold_Mag" name="DeleteBoardUseInfo" type="L3LONG">
/// 
/// 删除铜管使用实绩
/// ARG &gt;&gt; rsBoardUses: 要删除的铜板使用的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::DeleteBoardUseInfo(L3RECORDSET rsBoardUses)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsBoardUses,CMOLD_BOARD_PAR_USE_URI);
}

/// <Method class="CMold_Mag" name="GetBoardUseInfo" type="L3RECORDSET">
/// 
/// 获取铜管装配实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsBoardUses；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CMold_Mag::GetBoardUseInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CMOLD_BOARD_PAR_USE_URI,strCondition);
}


/// <Method class="CMold_Mag" name="MoldChangeFlowID" type="L3LONG">
/// 
/// 换流别
/// ARG &gt;&gt; dsMolds: 要修改的铜板使用的记录集。必须包含 MoldID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="strMoldID" type="L3STRING"></Param>
/// <Param name="strNewFlowID" type="L3STRING"></Param>
/// </Method>
L3LONG CMold_Mag::MoldChangeFlowID(L3STRING strMoldID,L3STRING strNewFlowID)
{
	// TODO : 请在此添加逻辑代码
	CString csMoldID = strMoldID;
	CString csNewFlowID  = strNewFlowID;
	if(csMoldID == _T("")|| csNewFlowID == _T(""))
		return 0;//不存在结晶器号，或则没有选择新流号
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	//CL3RecordSetWrap rsBase;
	//if(!CreateClassPropSet(CMOLD_BASE_URI,rsBase))
	//{
	//	if(bUseTrans)
	//		Rollback(nTrans);
	//	return 0;//组建铜管装配记录失败
	//}

	//用于修改结晶器基本信息的记录集
	CStringArray BaseNames;BaseNames.SetSize(6);
	CUIntArray BaseTypes;BaseTypes.SetSize(6);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("Cast_ID");
	BaseNames[3] = _T("FlowID");
	BaseNames[4] = _T("Copper_Fac");
	BaseNames[5] = _T("Copper_ID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;
	BaseTypes[3] = L3VT_STRING;
	BaseTypes[4] = L3VT_STRING;
	BaseTypes[5] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
	//断面尺寸
	long lFaceMea = GetObjectPropValue(csUri,_T("Break_Face_Mea")).ToLong();
	//装配编号
	CString csInStallID = GetObjectPropValue(csUri,_T("InStallID")).ToCString();
	//结晶器状态
	CString csStatus = GetObjectPropValue(csUri,_T("Status")).ToCString();
	CString csCastID =GetObjectPropValue(csUri,_T("Cast_ID")).ToCString(); 
	CString csOldFlowID =GetObjectPropValue(csUri,_T("FlowID")).ToCString(); 
	
	if( lFaceMea <= 0 || csInStallID == _T("") || csOldFlowID == csNewFlowID)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;//没有断面尺寸或没有装配编号或则新流别和原流别相同
	}
	//判断当前更换是否有效
	CString csTemp = _T("Select Count(*) as Mold_Count from %s where Cast_ID = '%s' and FlowID = '%s' and Status = '%s'");
	CString csSQL;	
	csSQL.Format(csTemp,CMOLD_BASE_URI,csCastID,csNewFlowID,CMOLD_STATUS_USE);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	rsResult.MoveFirst();
	long lCount = rsResult.GetFieldByName(_T("Mold_Count")).ToLong();
	if (lCount > 0 )
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//当前不允许换流别，原因是所选流别上存在结晶器
	}
	//修改基本信息中流别
	SetObjectPropValue(csUri,_T("FlowID"),CL3Variant(csNewFlowID));
	//修改使用记录中流别和备注
	if(lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
	{
		CString csTempExist =  _T("Select * From %s where InStallID = '%s' ");
		CString csSQLExist;	
		csSQLExist.Format(csTempExist,CMOLD_PIPE_PAR_USEI_URI,csInStallID);
		CL3RecordSetWrap rsResultExist;
		if(!Query(csSQLExist,rsResultExist) || rsResultExist.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if (rsResultExist.GetRowCount() < 1 )//不存在使用记录,可能是没有产生或被人工删除
		{
			CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
			CL3RecordSetWrap rpSysInfo;
			SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
			
			CString csTempPipe = _T("Select * From %s where InStallID = '%s' ");
			CString csSQLPipe;	
			csSQLPipe.Format(csTempPipe,CMOLD_PIPE_INSTALL_URI,csInStallID);
			CL3RecordSetWrap rsResultPipe;
			if(!Query(csSQLPipe,rsResultPipe) || rsResultPipe.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			if (rsResultPipe.GetRowCount()>0)
			{
				rsResultPipe.MoveFirst();
			
				CL3RecordSetWrap rsPipeUse;
				if(!CreateClassPropSet(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;//组建铜管使用记录失败
				}

				rsPipeUse.AppendRecord();
				rsPipeUse.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));//装配编号
				rsPipeUse.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//录入日期
				rsPipeUse.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));//铸机号
				rsPipeUse.SetFieldByName(_T("FlowID"),CL3Variant(csNewFlowID));//流号
				rsPipeUse.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));//结晶器号
				rsPipeUse.SetFieldByName(_T("Copper_Fac"),rsResultPipe.GetFieldByName(_T("Copper_Fac")));//铜管厂家
				rsPipeUse.SetFieldByName(_T("Copper_ID"),rsResultPipe.GetFieldByName(_T("Copper_ID")));//铜管编号
				rsPipeUse.SetFieldByName(_T("OnLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//上线时间
				rsPipeUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));//班别
				rsPipeUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));//班次
				rsPipeUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//操作人员
				//rsPipeUse.SetFieldByName(_T("Note"),CL3Variant(_T("换流别")));//操作人员
				rsPipeUse.MoveFirst();
				CreateNewObjects(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse);
			}
		}
		else
		{
			CString csPipeUri = CMOLD_PIPE_PAR_USEI_URI + _T("\\") + csInStallID;
			SetObjectPropValue(csPipeUri,_T("FlowID"),CL3Variant(csNewFlowID));//流号
		}
	}
	//Modify begin by llj 2011-1-27 Add CMM7
	//else 屏蔽，增加断面为12的判断
	else if(lFaceMea == 12)
	//Modify end
	{
		CString csTempExist =  _T("Select * From %s where InStallID = '%s' ");
		CString csSQLExist;	
		csSQLExist.Format(csTempExist,CMOLD_BOARD_PAR_USE_URI,csInStallID);
		CL3RecordSetWrap rsResultExist;
		if(!Query(csSQLExist,rsResultExist) || rsResultExist.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if (rsResultExist.GetRowCount() < 1 )//不存在使用记录,可能是没有产生或被人工删除
		{
			CL3RecordSetWrap rsBoardUse;
			if(!CreateClassPropSet(CMOLD_BOARD_PAR_USE_URI,rsBoardUse))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;//组建铜管使用记录失败
			}

			CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
			CL3RecordSetWrap rpSysInfo;
			SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

			CString csTempBoard = _T("Select * From %s where InStallID = '%s' ");
			CString csSQLBoard;	
			csSQLBoard.Format(csTempBoard,CMOLD_BOARD_INSTALL_URI,csInStallID);
			CL3RecordSetWrap rsResultBoard;
			if(!Query(csSQLBoard,rsResultBoard) || rsResultBoard.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			if (rsResultBoard.GetRowCount()>0)
			{
				rsResultBoard.MoveFirst();
			
				rsBoardUse.AppendRecord();
				rsBoardUse.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));//装配编号
				rsBoardUse.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//录入日期
				rsBoardUse.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));//铸机号
				rsBoardUse.SetFieldByName(_T("FlowID"),CL3Variant(csNewFlowID));//流号
				rsBoardUse.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));//结晶器号
				
				rsBoardUse.SetFieldByName(_T("Inner_ID"),rsResultBoard.GetFieldByName(_T("Inner_ID")));//铜板内弧编号
				rsBoardUse.SetFieldByName(_T("Outer_ID"),rsResultBoard.GetFieldByName(_T("Outer_ID")));//铜板外弧编号
				rsBoardUse.SetFieldByName(_T("South_ID"),rsResultBoard.GetFieldByName(_T("South_ID")));//铜板南侧编号
				rsBoardUse.SetFieldByName(_T("North_ID"),rsResultBoard.GetFieldByName(_T("North_ID")));//铜板北侧编号
				rsBoardUse.SetFieldByName(_T("Copper_Fac"),rsResultBoard.GetFieldByName(_T("Copper_Fac")));//铜管厂家
				rsBoardUse.SetFieldByName(_T("Lug_Steel_Mea"),rsResultBoard.GetFieldByName(_T("Lug_Steel_Mea")));//铜管厂家

				rsBoardUse.SetFieldByName(_T("OnLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//上线时间
				rsBoardUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));//班别
				rsBoardUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));//班次
				rsBoardUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//操作人员
				rsBoardUse.MoveFirst();
				CreateNewObjects(CMOLD_BOARD_PAR_USE_URI,rsBoardUse);
			}
		}
		else
		{
			CString csBoardUri = CMOLD_BOARD_PAR_USE_URI + _T("\\") + csInStallID;
			SetObjectPropValue(csBoardUri,_T("FlowID"),CL3Variant(csNewFlowID));//流号
		}
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
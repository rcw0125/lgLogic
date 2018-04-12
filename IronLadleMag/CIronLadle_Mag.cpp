// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CIronLadle_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CIronLadle_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CIronLadle_Mag.h"

//当对象被装载到系统中时，被调用
void CIronLadle_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CIronLadle_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <Method class="CIronLadle_Mag" name="GetInfos" type="L3BOOL">
/// 
/// 获取实绩信息
/// ARG &gt;&gt;strClassName:类名
///     &gt;&gt;strCondition: 查询条件
/// RET &lt;&lt; 成功返回reInfos；失败返回Null
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// <Param name="strClassName" type="L3STRING">类名</Param>
/// </Method>
L3RECORDSET CIronLadle_Mag::GetInfos(L3STRING strCondition, L3STRING strClassName)
{
	CString  csClassUri = _T("XGMESLogic\\IronLadleMag\\");
	csClassUri += strClassName;
	CString csCondition =strCondition;
	if(csCondition == _T(""))
		return NULL;

	// TODO : 请在此添加逻辑代码
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	
	CString csSQL;
	csSQL.Format(csTemp,csClassUri,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CIronLadle_Mag" name="InsertInfos" type="L3LONG">
/// 
/// 添加实绩信息
/// ARG &gt;&gt;strClassName:类名
///     &gt;&gt;rsInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// <Param name="strClassName" type="L3STRING">类名</Param>
/// </Method>
L3LONG CIronLadle_Mag::InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName)
{
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;
	
	CString  csClassUri = _T("XGMESLogic\\IronLadleMag\\");
	csClassUri += strClassName;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	if(CreateNewObjects(csClassUri,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}

	if(bUseTrans)
		Commit(nTrans);

	// TODO : 请在此添加逻辑代码
	return 1;
}

/// <Method class="CIronLadle_Mag" name="UpdateInfos" type="L3LONG">
/// 
/// 修改实绩信息
/// ARG &gt;&gt;strClassName:类名
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// <Param name="strClassName" type="L3STRING">类名</Param>
/// </Method>
L3LONG CIronLadle_Mag::UpdateInfos(L3RECORDSET rsInfos, L3STRING strClassName)
{
	// TODO : 请在此添加逻辑代码

	return 0;
}

/// <Method class="CIronLadle_Mag" name="DeleteInfos" type="L3LONG">
/// 
/// 删除实绩信息
/// ARG &gt;&gt;strClassName:类名
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// <Param name="strClassName" type="L3STRING">类名</Param>
/// </Method>
L3LONG CIronLadle_Mag::DeleteInfos(L3RECORDSET rsInfos, L3STRING strClassName)
{
	// TODO : 请在此添加逻辑代码
	return 0;
}


/// <Method class="CIronLadle_Mag" name="IronLadleTieStart" type="L3LONG">
/// 
/// 铁包打结开始
/// ARG &gt;&gt;rsIronLadles: 要打结开始的铁包的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleTieStart(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
	int iYear = dtCurrentTime.GetYear();
	int iMonth = dtCurrentTime.GetMonth();

	CString csYear;
	csYear.Format(_T("%d"),iYear);
	csYear = csYear.Right(2);

	CString csMonth;
	csMonth.Format(_T("%02d"),iMonth);

	CString csYearMonth = csYear + csMonth;

	//创建用于修改CIronLadle_Base数据[2009-03-17]
	/*CL3RecordSetWrap rsBase;
	if(!CreateClassPropSet(CIRONLADLE_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}*/
	
	//创建用于新增CIRONLADLE_TIE_URI部分数据
	CL3RecordSetWrap rsTie;
	if(!CreateClassPropSet(CIRONLADLE_TIE_URI,rsTie))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csOldTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csTieID;

		if(csOldTieID == _T(""))
		{
			csTieID = csYearMonth + csIronLadleID + _T("01");
		}
		else
		{
			CString csOldYearMonth = csOldTieID.Left(4);
			//属于同年同月
			if(csOldYearMonth == csYearMonth)
			{
				CString csOldNO = csOldTieID.Right(2);
				CString csNO;
				int iNO = _ttoi(csOldNO) + 1;
				csNO.Format(_T("%02d"),iNO);
				csTieID = csYearMonth + csIronLadleID + csNO;
			}
			else
			{
				csTieID = csYearMonth + csIronLadleID + _T("01");
			}
		}
		SetObjectPropValue(csBaseUri,_T("TieID"),CL3Variant(csTieID));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_TIE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("IronLadle_Age"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Refra_Produce"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Refra_ID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Small_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Middle_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Big_FireID"),CL3Variant((L3LONG)0));
	/*	rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsBase.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CIRONLADLE_STATUS_TIE));
		rsBase.SetFieldByName(_T("ComFlag"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("IronLadle_Age"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("Refra_Produce"),CL3Variant(_T("")));
		rsBase.SetFieldByName(_T("Refra_ID"),CL3Variant(_T("")));

		rsBase.SetFieldByName(_T("Small_FireID"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("Middle_FireID"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("Big_FireID"),CL3Variant((L3LONG)0));*/

		//添加打结实绩
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		rsTie.AppendRecord();
		rsTie.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsTie.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsTie.SetFieldByName(_T("TieID"),CL3Variant(csTieID));

		rsTie.SetFieldByName(_T("Tie_Start_Time"),CL3Variant(dtCurrentTime));
		rsTie.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsTie.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsTie.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		rsTie.SetFieldByName(_T("Doff_Mod_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}
	/*if(!SetObjsPropValues(CIRONLADLE_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}*/
	if(CreateNewObjects(CIRONLADLE_TIE_URI,rsTie) < rsTie.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//可能违反唯一约束条件
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleTieEnd" type="L3LONG">
/// 
/// 铁包打结结束
/// ARG &gt;&gt;rsIronLadles: 要打结结束的铁包的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleTieEnd(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();

		if(csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有打结编号
		}

		CString csTieUri = CIRONLADLE_TIE_URI + _T("\\") + csTieID;//
		SetObjectPropValue(csTieUri,_T("Tie_End_Time"),CL3Variant(COleDateTime::GetCurrentTime()));

		CString csFac = GetObjectPropValue(csTieUri,_T("Refra_Produce")).ToCString();
		CString csName = GetObjectPropValue(csTieUri,_T("Refra_ID")).ToCString();
	
		SetObjectPropValue(csBaseUri,_T("Refra_Produce"),CL3Variant(csFac));
		SetObjectPropValue(csBaseUri,_T("Refra_ID"),CL3Variant(csName));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_COLD));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleSmallFireStart" type="L3LONG">
/// 
/// 铁包小火开始
/// ARG &gt;&gt;rsIronLadles: 要小火开始的铁包的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleSmallFireStart(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	//创建用于新增CIRONLADLE_FIRE_URI部分数据
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有打结编号
		}
		long iSmallID =  GetObjectPropValue(csBaseUri,_T("Small_FireID")).ToLong();

		iSmallID = iSmallID + 1;
		SetObjectPropValue(csBaseUri,_T("Small_FireID"),CL3Variant(iSmallID));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_SMALL_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));

		//添加小火烘烤实绩
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csObjectID ;
		csObjectID.Format(_T("%d"),iSmallID);
		csObjectID = csTieID + _T("1") + csObjectID;
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsFire.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("1")));
		rsFire.SetFieldByName(_T("Fire_Start_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(iSmallID));
		rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csObjectID));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//可能违反唯一约束条件
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CIronLadle_Mag" name="IronLadleSmallFireEnd" type="L3LONG">
/// 
/// 铁包小火结束
/// ARG &gt;&gt;rsIronLadles: 要小火结束的铁包的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleSmallFireEnd(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csSmallID =  GetObjectPropValue(csBaseUri,_T("Small_FireID")).ToCString();

		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_SMALL_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		if(csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有打结编号
		}

		CString csObjectID = csTieID + _T("1") + csSmallID;
		CString csFireUri = CIRONLADLE_FIRE_URI + _T("\\") + csObjectID;
		COleDateTime dtStartTime = GetObjectPropValue(csFireUri,_T("Fire_Start_Time")).ToDateTime();
		//烘烤时长
		COleDateTimeSpan span = dtCurrentTime - dtStartTime;
		L3LONG nTime =(LONG)span.GetTotalMinutes();;

		SetObjectPropValue(csFireUri,_T("Fire_End_Time"),CL3Variant(dtCurrentTime));
		SetObjectPropValue(csFireUri,_T("Fire_Length"),CL3Variant(nTime));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleMiddleFireStart" type="L3LONG">
/// 
/// 铁包中火开始
/// ARG &gt;&gt;rsIronLadles: 要中火开始的铁包的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleMiddleFireStart(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	//创建用于新增CIRONLADLE_FIRE_URI部分数据
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有打结编号
		}
		long iMidID =  GetObjectPropValue(csBaseUri,_T("Middle_FireID")).ToLong();

		iMidID = iMidID + 1;
		SetObjectPropValue(csBaseUri,_T("Middle_FireID"),CL3Variant(iMidID));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_MIDDLE_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));

		//添加中火烘烤实绩
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csObjectID ;
		csObjectID.Format(_T("%d"),iMidID);
		csObjectID = csTieID + _T("2") + csObjectID;
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsFire.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("2")));
		rsFire.SetFieldByName(_T("Fire_Start_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(iMidID));
		rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csObjectID));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//可能违反唯一约束条件
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleMiddleFireEnd" type="L3LONG">
/// 
/// 铁包中火结束
/// ARG &gt;&gt;rsIronLadles: 要中火结束的铁包的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleMiddleFireEnd(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csMidID =  GetObjectPropValue(csBaseUri,_T("Middle_FireID")).ToCString();

		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_MIDDLE_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		if(csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有打结编号
		}

		CString csObjectID = csTieID + _T("2") + csMidID;
		CString csFireUri = CIRONLADLE_FIRE_URI + _T("\\") + csObjectID;
		COleDateTime dtStartTime = GetObjectPropValue(csFireUri,_T("Fire_Start_Time")).ToDateTime();
		//烘烤时长
		COleDateTimeSpan span = dtCurrentTime - dtStartTime;
		L3LONG nTime =(LONG)span.GetTotalMinutes();;

		SetObjectPropValue(csFireUri,_T("Fire_End_Time"),CL3Variant(dtCurrentTime));
		SetObjectPropValue(csFireUri,_T("Fire_Length"),CL3Variant(nTime));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleBigFireStart" type="L3LONG">
/// 
/// 铁包大火开始
/// ARG &gt;&gt;rsIronLadles: 要大火开始的铁包的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleBigFireStart(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	//创建用于新增CIRONLADLE_FIRE_URI部分数据
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有打结编号
		}
		long iBigID =  GetObjectPropValue(csBaseUri,_T("Big_FireID")).ToLong();

		iBigID = iBigID + 1;
		SetObjectPropValue(csBaseUri,_T("Big_FireID"),CL3Variant(iBigID));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_BIG_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));

		//添加大火烘烤实绩
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csObjectID ;
		csObjectID.Format(_T("%d"),iBigID);
		csObjectID = csTieID + _T("3") + csObjectID;
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsFire.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("3")));
		rsFire.SetFieldByName(_T("Fire_Start_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(iBigID));
		rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csObjectID));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//可能违反唯一约束条件
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleBigFireEnd" type="L3LONG">
/// 
/// 铁包大火结束
/// ARG &gt;&gt;rsIronLadles: 要大火结束的铁包的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleBigFireEnd(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csBigID =  GetObjectPropValue(csBaseUri,_T("Big_FireID")).ToCString();

		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		if(csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有打结编号
		}

		CString csObjectID = csTieID + _T("3") + csBigID;
		CString csFireUri = CIRONLADLE_FIRE_URI + _T("\\") + csObjectID;
		COleDateTime dtStartTime = GetObjectPropValue(csFireUri,_T("Fire_Start_Time")).ToDateTime();
		//烘烤时长
		COleDateTimeSpan span = dtCurrentTime - dtStartTime;
		L3LONG nTime =(LONG)span.GetTotalMinutes();;	

		SetObjectPropValue(csFireUri,_T("Fire_End_Time"),CL3Variant(dtCurrentTime));
		SetObjectPropValue(csFireUri,_T("Fire_Length"),CL3Variant(nTime));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLaldeStopUse" type="L3LONG">
/// 铁包停用(转为冷备)
/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLaldeStopUse(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_COLD));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleWaitRepair" type="L3LONG">
/// 铁包下线待修
/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleWaitRepair(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_OFFLINE));
		SetObjectPropValue(csBaseUri,_T("Refra_Produce"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Refra_ID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Small_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Middle_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Big_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="InsertTieInfos" type="L3LONG">
/// 
/// 添加打结实绩信息
/// ARG  &gt;&gt;rsTieInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTieInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CIronLadle_Mag::InsertTieInfos(L3RECORDSET rsTieInfos)
{
	// TODO : 请在此添加逻辑代码
    CL3RecordSetWrap rsData = rsTieInfos;
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
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//获取铁包号
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();

		CString csTemp = _T(" select * from %s where TieID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CIRONLADLE_TIE_URI,csTieID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//查询打结记录失败
		}
		if(rsResult.GetRowCount() > 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//当前存在打结记录，不允许新增
		}

		rsData.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		
		//耐材厂家
		CString csRefraPro = rsData.GetFieldByName(_T("Refra_Produce")).ToCString();
		//耐材名称
		CString csRefraID = rsData.GetFieldByName(_T("Refra_ID")).ToCString();
 
		SetObjectPropValue(csBaseUri,_T("Refra_Produce"),CL3Variant(csRefraPro));
		SetObjectPropValue(csBaseUri,_T("Refra_ID"),CL3Variant(csRefraID));
		
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CIRONLADLE_TIE_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="UpdateTieInfos" type="L3LONG">
/// 
/// 修改打结实绩信息
/// ARG &gt;&gt;rsTieInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTieInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CIronLadle_Mag::UpdateTieInfos(L3RECORDSET rsTieInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = rsTieInfos;
	if(rs.IsNull() || rs.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//获取铁包号
		CString csTieID = rs.GetFieldByName(_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有打结编号
		}
		rs.MoveNext();
	}
	rs.MoveFirst();
	if(!SetObjsPropValues(CIRONLADLE_TIE_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="DeleteTieInfos" type="L3LONG">
/// 
/// 删除打结实绩信息
/// ARG &gt;&gt;rsTieInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTieInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CIronLadle_Mag::DeleteTieInfos(L3RECORDSET rsTieInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = rsTieInfos;
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
	
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//获取打结编号
		CString csTieID = rs.GetFieldByName(_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有打结编号
		}
		rs.MoveNext();
	}
	rs.MoveFirst();
	if(DeleteOldObjects(CIRONLADLE_TIE_URI,rs) < rs.GetRowCount ())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


L3RECORDSET CIronLadle_Mag::GetTieInfos(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition =strCondition;
	if(csCondition == _T(""))
		return NULL;
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	
	CString csSQL;
	csSQL.Format(csTemp,CIRONLADLE_TIE_URI,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CIronLadle_Mag" name="InsertFireInfos" type="L3LONG">
/// 添加烘烤信息
/// <Param name="FireInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::InsertFireInfos(L3RECORDSET FireInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = FireInfos;
	if(rsData.GetRowCount() < 1||rsData.IsNull())
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
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		long lFireType = rsData.GetFieldByName(_T("Fire_Type")).ToLong();
		CString csFireID =  rsData.GetFieldByName(_T("FireID")).ToString();//修改记录当中烘烤编号
		int iFireID = _ttoi(csFireID);
		if (csIronLadleID == _T("") ||lFireType == 0 ||iFireID < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有铁包号或烘烤类型或烘烤次数
		}
		
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csObjectID;
		CString csBaseFireID;
		int iBaseFireID = -1;
		switch(lFireType)
		{
			case 1:
				csBaseFireID =  GetObjectPropValue(csBaseUri,_T("Small_FireID")).ToCString();
				iBaseFireID = _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -2;//烘烤次数比基本信息中烘烤次数高，操作不允许
				}
				csObjectID = csTieID + _T("1") + csFireID;
				break;
				
			case 2:
				csBaseFireID =  GetObjectPropValue(csBaseUri,_T("Middle_FireID")).ToCString();
				iBaseFireID = _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -2;//烘烤次数比基本信息中烘烤次数高，操作不允许
				}
				csObjectID = csTieID + _T("2") +csFireID;
				break;
				
			case 3:
				csBaseFireID =  GetObjectPropValue(csBaseUri,_T("Big_FireID")).ToCString();
				iBaseFireID = _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -2;//烘烤次数比基本信息中烘烤次数高，操作不允许
				}
				csObjectID = csTieID + _T("3") + csFireID;
				break;
		}
		CString csTemp = _T(" select * from %s where Object_ID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CIRONLADLE_FIRE_URI,csObjectID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;//查询烘烤记录失败
		}
		if(rsResult.GetRowCount() > 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//当前存在烘烤记录，不允许新增
		}

		rsData.SetFieldByName(_T("Object_ID"),CL3Variant(csObjectID));
		rsData.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsData.SetFieldByName(_T("FireID"),CL3Variant(csFireID));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="UpdateFireInfos" type="L3LONG">
/// 修改烘烤信息
/// <Param name="dsFireInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CIronLadle_Mag::UpdateFireInfos(L3RECORDSET dsFireInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = dsFireInfos;
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

	//创建用于新增CIRONLADLE_FIRE_URI部分数据
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csObjectID = rs.GetFieldByName(_T("Object_ID")).ToString();
		if (csObjectID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//当前修改记录没有关键字(可能没有刷新)
		}
		
		CString csIronLadleID = rs.GetFieldByName(_T("IronLadleID")).ToString();//修改记录当中铁包号
		CString csFireID =  rs.GetFieldByName(_T("FireID")).ToString();//修改记录当中烘烤编号
		int iFireID = _ttoi(csFireID);
		long lFireType = rs.GetFieldByName(_T("Fire_Type")).ToLong();//修改记录当中烘烤类型
		if (csIronLadleID == _T("")||csFireID ==_T("") ||lFireType ==0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//当前修改记录没有铁包号或烘烤编号或烘烤类型
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToString();
		CString csBaseFireID;
		int iBaseFireID = -1;
		CString csBaseObjectID;
		switch(lFireType)
		{
			case 1:
				csBaseFireID = GetObjectPropValue(csBaseUri,_T("Small_FireID")).ToString();
				iBaseFireID =  _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -3;//烘烤次数比基本信息中烘烤次数高，操作不允许
				}
				csBaseObjectID = csTieID + _T("1") + csFireID;
				break;
				
			case 2:
				csBaseFireID = GetObjectPropValue(csBaseUri,_T("Middle_FireID")).ToString();
				iBaseFireID =  _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -3;//烘烤次数比基本信息中烘烤次数高，操作不允许
				}
				csBaseObjectID = csTieID + _T("2") +csFireID;
				break;
				
			case 3:
				csBaseFireID = GetObjectPropValue(csBaseUri,_T("Big_FireID")).ToString();
				iBaseFireID =  _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -3;//烘烤次数比基本信息中烘烤次数高，操作不允许
				}
				csBaseObjectID = csTieID + _T("3") + csFireID;
				break;
		}
		if(csObjectID != csBaseObjectID)//修改主键，先查看可否新新增，
		{

			CString csTemp = _T(" select * from %s where Object_ID = '%s' ");
			CString csSQL;
			csSQL.Format(csTemp,CIRONLADLE_FIRE_URI,csBaseObjectID);
			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;//查询烘烤记录失败
			}
			if(rsResult.GetRowCount() > 0 )
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;//当前存在烘烤记录，不允许新增（不允许修改）
			}

			//删除当前记录
			CL3RecordSetWrap rsDelete;
			if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsDelete))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			rsDelete.AppendRecord();
			rsDelete.CopyCurRowFrom(rs);
			rsDelete.MoveFirst();
			if(DeleteOldObjects(CIRONLADLE_FIRE_URI,rsDelete) < rsDelete.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;//删除原有记录失败		
			}
			//新增修改后的记录
			rsFire.AppendRecord();
			rsFire.CopyCurRowFrom(rs);
			rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csBaseObjectID));
			rs.DeleteRecord(-1);
		}
		rs.MoveNext();
	}

	rs.MoveFirst();
	if (rs.GetRowCount()>0)
	{
		if(!SetObjsPropValues(CIRONLADLE_FIRE_URI,rs))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}
	}
	if (rsFire.GetRowCount()>0)
	{
		if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
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
/// <Method class="CIronLadle_Mag" name="DeleteFireInfos" type="L3LONG">
/// 删除烘烤信息
/// <Param name="dsFireInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CIronLadle_Mag::DeleteFireInfos(L3RECORDSET dsFireInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = dsFireInfos;
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
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csObjectID = rs.GetFieldByName(_T("Object_ID")).ToString();
		if (csObjectID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//当前修改记录没有关键字(可能没有刷新)
		}
		rs.MoveNext();
	}
	rs.MoveFirst();
	if(DeleteOldObjects(CIRONLADLE_FIRE_URI,rs) < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="GetFireInfos" type="L3RECORDSET">
/// 获取烘烤信息
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CIronLadle_Mag::GetFireInfos(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition =strCondition;
	if(csCondition == _T(""))
		return NULL;
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	
	CString csSQL;
	csSQL.Format(csTemp,CIRONLADLE_FIRE_URI,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}



/// <Method class="CIronLadle_Mag" name="InsertUseInfos" type="L3LONG">
/// 添加使用信息
/// <Param name="UseInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::InsertUseInfos(L3RECORDSET UseInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = UseInfos;
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

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csIronLadleID = rs.GetFieldByName(_T("IronLadleID")).ToCString();
		if(csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	
		}
		
		CString csTieID = GetObjectPropValue(CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID,_T("TieID")).ToCString();
		rs.SetFieldByName(_T("TieID"),CL3Variant(csTieID));

	
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!CreateNewObjects(CIRONLADLE_USE_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="UpdateUseInfos" type="L3LONG">
/// 修改使用信息
/// <Param name="dsUseInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CIronLadle_Mag::UpdateUseInfos(L3RECORDSET dsUseInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = dsUseInfos;
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

	if(!SetObjsPropValues(CIRONLADLE_USE_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="DeleteUseInfos" type="L3LONG">
/// 删除使用信息
/// <Param name="dsUseInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CIronLadle_Mag::DeleteUseInfos(L3RECORDSET dsUseInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = dsUseInfos;
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

	if(DeleteOldObjects(CIRONLADLE_USE_URI,rs)< rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="GetUseInfos" type="L3RECORDSET">
/// 获取使用信息
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CIronLadle_Mag::GetUseInfos(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition =strCondition;
	if(csCondition == _T(""))
		return NULL;
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	
	CString csSQL;
	csSQL.Format(csTemp,CIRONLADLE_USE_URI,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CIronLadle_Mag" name="GetIronLadle_Age" type="L3LONG">
/// 包龄
/// <Param name="strIronladleId" type="L3STRING">查询条件</Param>
/// </Method>
L3LONG CIronLadle_Mag::GetIronLadle_Age(L3STRING strIronladleId)
{
	// TODO : 请在此添加逻辑代码
	CString csIronladleId =strIronladleId;
	CString csTemp = _T(" SELECT IRONLADLE_AGE FROM %s where INPUT_TIME = (select max(INPUT_TIME) from %s where IronLadleID = '%s')");
	CString csSQL;
	csSQL.Format(csTemp,CIRONLADLE_USE_URI,CIRONLADLE_USE_URI,csIronladleId);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return 0;

	if (rsResult.GetRowCount() < 1)
	{
		return 0;
	}

	rsResult.MoveFirst();
	L3LONG RelAge= rsResult.GetFieldByName(_T("IRONLADLE_AGE")).ToLong();
	return RelAge;

}

/// <Method class="CIronLadle_Mag" name="IronLadleUse" type="L3LONG">
/// 铁包转为使用
/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleUse(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if(csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	
		}
		
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		long lIronLadleAge =GetObjectPropValue(csBaseUri,_T("IronLadle_Age")).ToLong();
		lIronLadleAge += 1;
	
		SetObjectPropValue(csBaseUri,_T("IronLadle_Age"),CL3Variant(lIronLadleAge));
		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleHot" type="L3LONG">
/// 转炉指定住原料置铁包为热备
/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleHot(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if(csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	
		}
		
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT));
	
		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleOffLineException" type="L3LONG">
/// 铁包异常下线
/// <Param name="rsIronLadles" type="L3RECORDSET">下线的记录</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleOffLineException(L3RECORDSET rsIronLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;
	if(rsData.GetFieldIndex(_T("IronLadleID")) < 0 || rsData.GetFieldIndex(_T("Status")) < 0 )
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans <1)
			return 0;
	}
	
	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		CString csStatus = rsData.GetFieldByName(_T("Status")).ToCString();
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;

		if(csIronLadleID == _T("") || csStatus == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//没有铁包号或状态
		}
	
		if(csStatus == CIRONLADLE_STATUS_USE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//在用铁包不能异常下线
		}
		if(!SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_OFFLINE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//修改铁包状态失败
		}

		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

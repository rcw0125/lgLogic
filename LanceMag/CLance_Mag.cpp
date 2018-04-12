// 逻辑类CLance_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CLance_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CLance_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CLance_Mag.h"

//当对象被装载到系统中时，被调用
void CLance_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CLance_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


L3BOOL CLance_Mag::UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = rsInfos;
	if(rs.GetRowCount() < 1)
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

L3BOOL CLance_Mag::DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs = rsInfos;
	if(rs.GetRowCount() < 1)
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


L3RECORDSET CLance_Mag::GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition =lpcsCondition;

	if(csCondition == _T(""))//2009-04-06
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





/// <Method class="CLance_Mag" name="SetLanceStatus" type="L3BOOL">
/// 
/// 设置氧枪包状态
/// ARG &gt;&gt; rsLances: 要设置状态的氧枪的记录集
///     &gt;&gt; strStatus: 设置成为的状态。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsLances" type="L3RECORDSET"></Param>
/// <Param name="strStatus" type="L3STRING"></Param>
/// </Method>
L3BOOL CLance_Mag::SetLanceStatus(L3RECORDSET rsLances, L3STRING strStatus)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLances;
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
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rsData.SetFieldByName(_T("Status"),CL3Variant(strStatus));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!SetObjsPropValues(CLANCE_BASE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;	
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceDefendStrat" type="L3BOOL">
/// 
/// 氧枪维修开始
/// ARG &gt;&gt; rsLances: 要开始维修的氧枪的记录集。必须包含LanceID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsLance" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceDefendStrat(L3RECORDSET rsLance)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLance;
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
	
	CStringArray FieldNames;FieldNames.SetSize(7);
	CUIntArray FieldTypes;FieldTypes.SetSize(7);

	FieldNames[0]=_T("LanceID");
	FieldNames[1]=_T("BOFID");
	FieldNames[2]=_T("Status");
	FieldNames[3]=_T("Lance_Age");
	FieldNames[4]=_T("MakeID");
	FieldNames[5]=_T("Make_Start_Time");
	FieldNames[6]=_T("Make_End_Time");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_STRING;
	FieldTypes[3]=L3VT_LONG;
	FieldTypes[4]=L3VT_STRING;
	FieldTypes[5]=L3VT_DATETIME;
	FieldTypes[6]=L3VT_DATETIME;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		CString csMakeID;

		CString csTemp = _T(" SELECT MakeID FROM %s WHERE LanceID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CLANCE_BASE_URI,csLanceID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull()||rsResult.GetRowCount() != 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;
		}
		rsResult.MoveFirst();
		CString csOldMakeID = rsResult.GetFieldByName(_T("MakeID")).ToCString();
		
		if(csOldMakeID == _T(""))
		{
			csMakeID = csYearMonth + csLanceID + _T("01");
		}
		else
		{
			CString csOldYearMonth = csOldMakeID.Left(4);
			//属于同年同月
			if(csOldYearMonth == csYearMonth)
			{
				CString csOldNO = csOldMakeID.Right(2);
				CString csNO;
				int iNO = _ttoi(csOldNO) + 1;
				csNO.Format(_T("%02d"),iNO);
				csMakeID = csYearMonth + csLanceID + csNO;
			}
			else
			{
				csMakeID = csYearMonth + csLanceID + _T("01");
			}
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("LanceID"),CL3Variant(csLanceID));
		rsBase.SetFieldByName(_T("BOFID"),CL3Variant(_T("")));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CLANCE_STATUS_REPAIR));
		rsBase.SetFieldByName(_T("Lance_Age"),CL3Variant(L3LONG(0)));
		rsBase.SetFieldByName(_T("MakeID"),CL3Variant(csMakeID));
		rsBase.SetFieldByName(_T("Make_Start_Time"),CL3Variant(dtCurrentTime));
		rsBase.SetFieldByName(_T("Make_End_Time"),CL3Variant(_T("")));

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CLANCE_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;			
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceDefendEnd" type="L3BOOL">
/// 
/// 氧枪维修结束
/// ARG &gt;&gt; rsLances: 要结束维修的氧枪的记录集。必须包含LanceID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsLance" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceDefendEnd(L3RECORDSET rsLance)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLance;
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

	CStringArray FieldNames;FieldNames.SetSize(3);
	CUIntArray FieldTypes;FieldTypes.SetSize(3);

	FieldNames[0]=_T("LanceID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Make_End_Time");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_DATETIME;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
	
		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("LanceID"),CL3Variant(csLanceID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CLANCE_STATUS_FREE));
		rsBase.SetFieldByName(_T("Make_End_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CLANCE_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;			
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceChangeOn" type="L3BOOL">
/// 
/// 人工换上氧枪
/// ARG &gt;&gt; rsLances: 要换上的氧枪的记录集。必须包含LanceID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsLance" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceChangeOn(L3RECORDSET rsLance)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLance;
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if(!SetObjectPropValue(CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Status"),CL3Variant(CLANCE_STATUS_USE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;				
		}
		rsData.MoveNext();
		
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceOffLineCheck" type="L3BOOL">
/// 氧枪下线检查
/// <Param name="rsLances" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceOffLineCheck(L3RECORDSET rsLances)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLances;
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if(!SetObjectPropValue(CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Status"),CL3Variant(CLANCE_STATUS_CHECK)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;				
		}
		rsData.MoveNext();
		
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceFree" type="L3BOOL">
/// 氧枪下线检查完毕
/// 判为可再次上线使用
/// <Param name="rsLances" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceFree(L3RECORDSET rsLances)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLances;
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if(!SetObjectPropValue(CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Status"),CL3Variant(CLANCE_STATUS_FREE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;				
		}
		rsData.MoveNext();
		
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceChangeOff" type="L3BOOL">
/// 氧枪离线待修
/// ARG &gt;&gt; rsLances: 要换下的氧枪的记录集。必须包含LanceID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsLance" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceChangeOff(L3RECORDSET rsLance)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLance;
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if(!SetObjectPropValue(CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Status"),CL3Variant(CLANCE_STATUS_OFFLINE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;				
		}
		rsData.MoveNext();
		
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="InsertLanceDefendInfo" type="L3BOOL">
/// 
/// 添加氧枪维护信息
/// ARG &gt;&gt; rsLanceDefends: 要添加的氧枪的维护的记录集。必须包含LanceID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsLanceDefend" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceDefendInfo(L3RECORDSET rsLanceDefend)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLanceDefend;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		CString csMakeID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if (csLanceID == _T("") || csMakeID== _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_DEFEND_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceDefendInfo" type="L3BOOL">
/// 
/// 修改氧枪维护实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceDefendInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_DEFEND_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceDefendInfo" type="L3BOOL">
/// 
/// 删除氧枪维护实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceDefendInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_DEFEND_URI);
}

/// <Method class="CLance_Mag" name="GetLanceDefendInfo" type="L3RECORDSET">
/// 
/// 获取氧枪维护信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回记录集；失败返回Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceDefendInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CLANCE_DEFEND_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceUseInfo" type="L3BOOL">
/// 
/// 添加氧枪使用信息
/// ARG &gt;&gt; rsLanceUse: 要添加的氧枪的使用的记录集。必须包含LanceID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsLanceUse" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceUseInfo(L3RECORDSET rsLanceUse)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLanceUse;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	//COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		if (csLanceID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CL3Variant clMakeID = GetObjectPropValue (CLANCE_BASE_URI + _T("\\") + csLanceID,_T("MakeID"));
		if( clMakeID.ToCString() == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CL3Variant clHeadType= GetObjectPropValue (CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Lance_Head_Type"));
		rsData.SetFieldByName(_T("Lance_Head_Type"),CL3Variant(clHeadType));
		rsData.SetFieldByName(_T("MakeID"),CL3Variant(clMakeID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_USE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceUseInfo" type="L3BOOL">
/// 
/// 修改氧枪使用实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceUseInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_USE_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceUseInfo" type="L3BOOL">
/// 
/// 删除氧枪使用实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceUseInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_USE_URI);
}

/// <Method class="CLance_Mag" name="GetLanceDefendInfo" type="L3RECORDSET">
/// <Method class="CLance_Mag" name="GetLanceUseInfo" type="L3RECORDSET">
/// 
/// 获取氧枪使用信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回记录集；失败返回Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceUseInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CLANCE_USE_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceCheckInfo" type="L3BOOL">
/// 
/// 添加氧枪检查信息
/// ARG &gt;&gt; rsLanceCheck: 要添加的氧枪的检查的记录集。必须包含LanceID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsLanceCheck" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceCheckInfo(L3RECORDSET rsLanceCheck)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLanceCheck;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
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
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		if (csLanceID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CL3Variant clMakeID = GetObjectPropValue (CLANCE_BASE_URI + _T("\\") + csLanceID,_T("MakeID"));
		if( clMakeID.ToCString() == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		rsData.SetFieldByName(_T("MakeID"),CL3Variant(clMakeID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_CHECK_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceCheckInfo" type="L3BOOL">
/// 
/// 修改氧枪检查实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceCheckInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_CHECK_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceCheckInfo" type="L3BOOL">
/// 
/// 删除氧枪检查实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceCheckInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_CHECK_URI);
}
/// <Method class="CLance_Mag" name="GetLanceCheckInfo" type="L3RECORDSET">
/// 
/// 获取氧枪检查信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回记录集；失败返回Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceCheckInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CLANCE_CHECK_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceHeadInInfo" type="L3BOOL">
/// 
/// 添加氧枪枪头入库信息
/// ARG &gt;&gt; rsLanceHeadIn: 要添加的氧枪的枪头入库的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceHeadInInfo(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_IN_YARD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}
/// <Method class="CLance_Mag" name="UpdateLanceHeadInInfo" type="L3BOOL">
/// 
/// 修改枪头入库实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceHeadInInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_IN_YARD_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceHeadInInfo" type="L3BOOL">
/// 
/// 删除枪头入库实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceHeadInInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_IN_YARD_URI);
}
/// <Method class="CLance_Mag" name="GetLanceLanceHeadInInfo" type="L3RECORDSET">
/// 
/// 获取氧枪枪头入库信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回记录集；失败返回Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceLanceHeadInInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CLANCE_IN_YARD_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceHeadOutInfo" type="L3BOOL">
/// 
/// 添加氧枪枪头出库信息
/// ARG &gt;&gt; rsInfos: 要添加的氧枪的枪头出库的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceHeadOutInfo(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_OUT_YARD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceHeadOutInfo" type="L3BOOL">
/// 
/// 修改枪头出库实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceHeadOutInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_OUT_YARD_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceHeadOutInfo" type="L3BOOL">
/// 
/// 删除枪头出库实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceHeadOutInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_OUT_YARD_URI);
}

/// <Method class="CLance_Mag" name="GetLanceLanceHeadOutInfo" type="L3RECORDSET">
/// 
/// 获取氧枪枪头出库信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回记录集；失败返回Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceLanceHeadOutInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CLANCE_OUT_YARD_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceMakeInfo" type="L3BOOL">
/// 插入氧枪制作信息
/// <Param name="rsInfos" type="L3RECORDSET">氧枪制作信息</Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceMakeInfo(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		if (csLanceID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CL3Variant clMakeID = GetObjectPropValue (CLANCE_BASE_URI + _T("\\") + csLanceID,_T("MakeID"));
		if( clMakeID.ToCString() == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		rsData.SetFieldByName(_T("MakeID"),CL3Variant(clMakeID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_MAKE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceMakeInfo" type="L3BOOL">
/// 修改氧枪制作信息
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::UpdateLanceMakeInfo(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsInfos,CLANCE_MAKE_URI);
}

/// <Method class="CLance_Mag" name="DeleteLanceMakeInfo" type="L3BOOL">
/// 删除氧枪制作信息
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::DeleteLanceMakeInfo(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMakeID = rsData.GetFieldByName(_T("MakeID")).ToCString();
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		CString csTemp;
		CString csSQL;
		if (csMakeID == _T(""))
		{
			csTemp = _T("SELECT * FROM %s WHERE LanceID = '%s' and MakeID is null");
			csSQL.Format (csTemp,CLANCE_DEFEND_URI,csLanceID);
		}
		else
		{
			csTemp = _T("SELECT * FROM %s WHERE LanceID = '%s' and MakeID = '%s'");
			csSQL.Format (csTemp,CLANCE_DEFEND_URI,csLanceID,csMakeID);
		}
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(!DeleteOldObjects(CLANCE_DEFEND_URI,rsResult))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return FALSE;	
			}
		}

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!DeleteOldObjects(CLANCE_MAKE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="GetLanceMakeInfo" type="L3RECORDSET">
/// 获取氧枪制作信息
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceMakeInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CLANCE_MAKE_URI,strCondition);
}




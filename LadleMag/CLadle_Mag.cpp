ULONG CLadle_Mag::MeasureDesignate(L3STRING strLadleID)// 逻辑类CLadle_Mag的用户逻辑程序源文件
/// <Method class="CLadle_Mag" name="MeasureDesignate" type="ULONG">
/// 钢包称重指定
/// <Param name="strLadleID" type="L3STRING">钢包号</Param>
/// </Method>
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CLadle_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CLadle_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CLadle_Mag.h"

//当对象被装载到系统中时，被调用
void CLadle_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CLadle_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <Method class="CLadle_Mag" name="SetLadleStatus" type="L3LONG">
/// 
/// 设置钢包状态
/// ARG &gt;&gt; rsLadles: 要设置状态的钢包的记录集
///     &gt;&gt; strStatus: 设置成为的状态。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// <Param name="strStatus" type="L3STRING"></Param>
/// </Method>
L3LONG CLadle_Mag::SetLadleStatus(L3RECORDSET rsLadles, L3STRING strStatus)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		rsData.SetFieldByName(_T("Status"),CL3Variant(strStatus));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!SetObjsPropValues(CLADLE_BASE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="InsertInfos" type="L3LONG">
/// 
/// 添加实绩信息
/// ARG &gt;&gt;strClassName:类名
///     &gt;&gt;rsInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// <Param name="strClassName" type="L3STRING">类名</Param>
/// </Method>
L3LONG CLadle_Mag::InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName)
{
	// TODO : 请在此添加逻辑代码
	return 0;
}

/// <Method class="CLadle_Mag" name="UpdateInfos" type="L3LONG">
/// 
/// 修改实绩信息
/// ARG &gt;&gt;lpcsClass:类名
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// <Param name="lpcsClass" type="LPCTSTR">类名</Param>
/// </Method>
L3LONG CLadle_Mag::UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
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
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="DeleteInfos" type="L3LONG">
/// 
/// 删除实绩信息
/// ARG &gt;&gt;lpcsClass:类名
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// <Param name="lpcsClass" type="LPCTSTR">类名</Param>
/// </Method>
L3LONG CLadle_Mag::DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
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

/// <Method class="CLadle_Mag" name="GetInfos" type="L3RECORDSET">
/// 
/// 获取实绩信息
/// ARG &gt;&gt;strClassName:类名
///     &gt;&gt;strCondition: 查询条件
/// RET &lt;&lt; 成功返回reInfos；失败返回Null
/// <Param name="lpcsClass" type="LPCTSTR">查询条件</Param>
/// <Param name="lpcsCondition" type="LPCTSTR">类名</Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition =lpcsCondition;
	if(csCondition==_T(""))
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

/// <Method class="CLadle_Mag" name="SpecifyLadle" type="L3LONG">
/// 
/// 指定钢包
/// ARG &gt;&gt; rsLadlePlans: 要指定钢包的钢包计划的记录集。
/// RET &lt;&lt; 成功返回true；失败返回false。
/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::SpecifyLadle(L3RECORDSET rsLadlePlans)
{
	CL3RecordSetWrap rs =rsLadlePlans;
    if( rs.IsNull() || rs.GetRowCount() < 1 )
		return 0;
	rs.MoveFirst();

	LONG lExcuteResult = 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	while(!rs.IsEOF())
	{
		CString csPlanID = rs.GetFieldByName(_T("PlanID")).ToCString();
		CString csUri = CLADLE_PLAN_URI + _T("\\") + csPlanID;
		CString csStatus = GetObjectPropValue(csUri,_T("Status")).ToCString();
		CString csLadleID =  rs.GetFieldByName(_T("LadleID")).ToCString();
		if(csStatus!=CLADLE_PLAN_STATUS_UNDESIGN || csLadleID.IsEmpty())
		{
			rs.MoveNext();
			continue;
		}
		CString csUriLadle = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString ssss =  GetObjectPropValue(csUriLadle,_T("Ladle_Age"));
		if (!SetObjectPropValue(csUri, _T("Ladle_Age"),GetObjectPropValue(csUriLadle,_T("Ladle_Age"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("New_BOF_Flag"),GetObjectPropValue(csUriLadle,_T("New_BOF_Flag"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("LadleID"),CL3Variant(csLadleID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("Status"),CL3Variant(CLADLE_PLAN_STATUS_DESIGN)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUriLadle, _T("Status"),CL3Variant(CLADLE_STATUS_DESIGN)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		lExcuteResult += 1;
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//改变属性值
	CL3Variant varEvent = GetPropValue(_T("LadlePlanEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("LadlePlanEvent"),nEvent);

	return lExcuteResult;
}

/// <Method class="CLadle_Mag" name="LadlePour" type="L3LONG">
/// 
/// 钢包倒包
/// ARG &gt;&gt; rsLadles: 要倒包的钢包的记录集。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadlePour(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsInfos;
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
		//获取钢包号
		CString csOutLadleID = rsData.GetFieldByName(_T("Out_LadleID")).ToCString();
		CString csInLadleID = rsData.GetFieldByName(_T("In_LadleID")).ToCString();
		//获取倒出钢包工作层编号
		CL3Variant clWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("WorkID"));

		CString csOutStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("Status")).ToCString();
		CString csInStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csInLadleID,_T("Status")).ToCString();

		if( csOutLadleID == _T("") || csInLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有选择钢包号
		}
		
		//如果倒出钢包状态为使用并且导入钢包为热备，此时修改钢包状态
		if (csOutStatus == CLADLE_STATUS_USE && csInStatus == CLADLE_STATUS_HOT)
		{
			if(!SetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("Status"),CL3Variant(CLADLE_STATUS_HOT)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//设置状态不成功
			}
			if(!SetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csInLadleID,_T("Status"),CL3Variant(CLADLE_STATUS_USE)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//设置状态不成功
			}
		}
		rsData.SetFieldByName(_T("WorkID"),CL3Variant(clWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_POUR_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CLadle_Mag" name="UpdateLadlePourInfos" type="L3LONG">
/// 修改钢包倒包实绩
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::UpdateLadlePourInfos(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsInfos,CLADLE_POUR_URI);
}

/// <Method class="CLadle_Mag" name="DeleteLadlePourInfos" type="L3LONG">
/// 删除钢包倒包实绩
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::DeleteLadlePourInfos(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsInfos,CLADLE_POUR_URI);
}

/// <Method class="CLadle_Mag" name="GetLadlePourInfos" type="L3RECORDSET">
/// 获取钢包倒包实绩
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetLadlePourInfos(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CLADLE_POUR_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="LadleFold" type="L3LONG">
/// 
/// 钢包折罐
/// ARG &gt;&gt; rsLadles: 要折罐的钢包的记录集。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleFold(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsInfos;
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
		//获取钢包号
		CString csOutLadleID = rsData.GetFieldByName(_T("Out_LadleID")).ToCString();
		CString csInLadleID = rsData.GetFieldByName(_T("In_LadleID")).ToCString();
		//获取倒出钢包工作层编号
		CL3Variant clWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("WorkID"));

		CString csOutStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("Status")).ToCString();
		CString csInStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csInLadleID,_T("Status")).ToCString();

		if( csOutLadleID == _T("") || csInLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有选择钢包号
		}
		
		//如果倒出钢包状态为使用并且导入钢包为热备，此时修改钢包状态
		if (csOutStatus == CLADLE_STATUS_USE && csInStatus == CLADLE_STATUS_HOT)
		{
			if(!SetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("Status"),CL3Variant(CLADLE_STATUS_HOT)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//设置状态不成功
			}
			if(!SetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csInLadleID,_T("Status"),CL3Variant(CLADLE_STATUS_USE)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//设置状态不成功
			}
		}
		rsData.SetFieldByName(_T("WorkID"),CL3Variant(clWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_FOLD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="UpdateLadleFoldInfos" type="L3LONG">
/// 修改钢包折罐实绩
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::UpdateLadleFoldInfos(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsInfos,CLADLE_FOLD_URI);
}

/// <Method class="CLadle_Mag" name="DeleteLadleFoldInfos" type="L3LONG">
/// 删除钢包折罐实绩
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::DeleteLadleFoldInfos(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsInfos,CLADLE_FOLD_URI);
}

/// <Method class="CLadle_Mag" name="GetLadleFoldInfos" type="L3RECORDSET">
/// 获取钢包折罐实绩
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetLadleFoldInfos(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CLADLE_FOLD_URI,strCondition);
}
/// <Method class="CLadle_Mag" name="CancelSpecifyLadle" type="L3LONG">
/// 
/// 取消指定
/// ARG &gt;&gt; rsLadlePlans: 要取消指定的钢包计划的记录集。
/// RET &lt;&lt; 成功返回true；失败返回false。
/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::CancelSpecifyLadle(L3RECORDSET rsLadlePlans)
{
	CL3RecordSetWrap rs =rsLadlePlans;
    if( rs.IsNull() || rs.GetRowCount() < 1 )
		return 0;
	rs.MoveFirst();

	LONG lExcuteResult = 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	while(!rs.IsEOF())
	{
		CString csPlanID = rs.GetFieldByName(_T("PlanID")).ToCString();
		CString csUri = CLADLE_PLAN_URI + _T("\\") + csPlanID;
		CString csStatus = GetObjectPropValue(csUri,_T("Status")).ToCString();
		CString csLadleID =  rs.GetFieldByName(_T("LadleID")).ToCString();
		if(csStatus!=CLADLE_PLAN_STATUS_DESIGN || csLadleID.IsEmpty())
		{
			rs.MoveNext();
			continue;
		}
		CString csUriLadle = CLADLE_BASE_URI + _T("\\") + csLadleID;
		if (!SetObjectPropValue(csUri, _T("Ladle_Age"),L3LONG(0)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}

		if (!SetObjectPropValue(csUri, _T("New_BOF_Flag"),L3LONG(0)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("LadleID"),CL3Variant(_T(""))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("Status"),CL3Variant(CLADLE_PLAN_STATUS_UNDESIGN)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUriLadle, _T("Status"),CL3Variant(CLADLE_STATUS_HOT)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		lExcuteResult += 1;
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//改变属性值
	CL3Variant varEvent = GetPropValue(_T("LadlePlanEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("LadlePlanEvent"),nEvent);

	return lExcuteResult;
}

/// <Method class="CLadle_Mag" name="ReSpecifyLadle" type="L3LONG">
/// 
/// 重新指定钢包
/// ARG &gt;&gt; strReLadleID:指定钢包号；
///          &gt;&gt; rsLadlePlans: 要指定钢包的钢包计划的记录集。
/// RET &lt;&lt; 成功返回true；失败返回false。
/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
/// <Param name="strReLadleID" type="L3STRING"></Param>
/// </Method>
L3LONG CLadle_Mag::ReSpecifyLadle(L3RECORDSET rsLadlePlans, L3STRING strReLadleID)
{
	// TODO : 请在此添加逻辑代码
	return 0;
}

/// <Method class="CLadle_Mag" name="QueryUnProcessLadlePlan" type="L3RECORDSET">
/// 
/// 获取当班计划信息以及上班未执行完成计划
/// ARG &gt;&gt; strBofID: 转炉号。
///         &gt;&gt;strCasterID:铸机号
/// RET &gt;&gt; 找到的计划记录集。
/// <Param name="strBofID" type="L3STRING"></Param>
/// <Param name="strCasterID" type="L3STRING"></Param>
/// </Method>

L3RECORDSET CLadle_Mag::QueryUnProcessLadlePlan(L3STRING strBOFID, L3STRING strCasterID)
{

	CString csCasterID = strCasterID;
	CString csTempBOFID = strBOFID;
	CString csBOFID =csTempBOFID.Mid(2,1); 

	CL3RecordSetWrap rsReturnVal;

	CString cstrSQL = _T("  Select *  from %s                                                 ");
			cstrSQL+= _T("  where (CreateDate >= (select TRUNC(SYSDATE) from dual) -0.3333        ");
			cstrSQL+= _T("  or ( CreateDate < (select TRUNC(SYSDATE) from dual) -0.3333          ");
			cstrSQL+= _T(" and Status < '%s' ))                                                 ");


	if ((csBOFID == _T("")) && (csCasterID ==_T("")))
	{
		cstrSQL += _T("order by CasterID,CreateDate ");
		CString csSQL;
		csSQL.Format(cstrSQL,CLADLE_PLAN_URI,CLADLE_STATUS_WORK_EXCUTED);
		if (!Query(csSQL, rsReturnVal) || rsReturnVal.IsNull())
			return NULL;
		else
			return rsReturnVal.Detach();
	}
	else
	{
			if(csBOFID == _T("") && csCasterID !=_T(""))
			{
				cstrSQL += _T("and  CasterID = '%s' order by  CreateDate ");
				CString csSQL;
				csSQL.Format(cstrSQL,CLADLE_PLAN_URI,CLADLE_STATUS_WORK_EXCUTED,csCasterID);
				if (!Query(csSQL,rsReturnVal) || rsReturnVal.IsNull())
					return NULL;
				else
					return rsReturnVal.Detach();
			}
			else
			{
				if(csBOFID != _T("") && csCasterID ==_T(""))
				{
					cstrSQL += _T("and SubStr(HeatID,2,1) = '%s' order by HeatID ");	
					CString csSQL;
					csSQL.Format(cstrSQL,CLADLE_PLAN_URI,CLADLE_STATUS_WORK_EXCUTED,csBOFID);
					if (!Query(csSQL,rsReturnVal) || rsReturnVal.IsNull())
						return NULL;
					else
						return rsReturnVal.Detach();

				}
				else
				{
					cstrSQL += _T("and   SubStr(HeatID,2,1) = '%s' and  CasterID = '%s' order by HeatID ");	
					CString csSQL;
					csSQL.Format(cstrSQL,CLADLE_PLAN_URI,CLADLE_STATUS_WORK_EXCUTED,csBOFID,csCasterID);
					if (!Query(csSQL,rsReturnVal) || rsReturnVal.IsNull())
						return NULL;
					else
						return rsReturnVal.Detach();

				}
			}

	}

	return NULL;

}

//查询可用钢包
/// <Method class="CLadle_Mag" name="GetAvailableLadle" type="L3RECORDSET">
/// </Method>
L3RECORDSET CLadle_Mag::GetAvailableLadle(void)
{
	CL3RecordSetWrap rsReturn;
	CString cstrSQL;
	cstrSQL.Format(_T("Select a.Code,a.Code_Des from %s a,%s b where a.code = b.LadleID and Status = '%s' order by LadleID "),_T("XGMESLogic\\BaseDataMag\\CBase_All_Code"),CLADLE_BASE_URI,CLADLE_STATUS_HOT);
	if (!Query(cstrSQL,rsReturn) || rsReturn.IsNull())
		return NULL;
	else
		return rsReturn.Detach();
}

//查询钢包永久层编号
/// <Method class="CLadle_Mag" name="GetLadleInnerID" type="L3RECORDSET">
/// <Param name="strDateLadleID" type="L3STRING">钢包号</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetLadleInnerID(L3STRING strDateLadleID)
{
	CL3RecordSetWrap rs;
	CString cstrSQL;
	CString csDateLadleID = strDateLadleID;
	csDateLadleID += _T("%");
	CString csTemp = _T("Select max(InnerID) InnerID from %s where InnerID like ? ");
	cstrSQL.Format(csTemp,CLADLE_IN_BUILD_URI);
	VARIANT valParams[1];
	valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csDateLadleID.AllocSysString();

	if (!QueryWithParam(cstrSQL,valParams,1,rs) || rs.IsNull())	  
	{
		::VariantClear(&valParams[0]);
		return NULL;
	}
	else
	{
		::VariantClear(&valParams[0]);
		return rs.Detach();
	}
}


/// <Method class="CLadle_Mag" name="InsertInnerBuildInfos" type="L3LONG">
/// 
/// 添加永久层打结实绩信息
///     &gt;&gt;rsInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertInnerBuildInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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
		//获取钢包号
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有钢包号
		}
		
		CString csInnerID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("InnerID"));
		
		CString csTemp = _T(" SELECT * FROM %s where InnerID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CLADLE_IN_BUILD_URI,csInnerID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount()>0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//已经存在永久层砌筑信息
		}
		rsData.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_IN_BUILD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateInnerBuildInfos" type="L3LONG">
/// 
/// 修改永久层打结实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateInnerBuildInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_IN_BUILD_URI);
}
/// <Method class="CLadle_Mag" name="DeleteInnerBuildInfos" type="L3LONG">
/// 
/// 删除永久层打结实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteInnerBuildInfos(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLADLE_IN_BUILD_URI);
}

/// <Method class="CLadle_Mag" name="GetInnerBuildInfos" type="L3RECORDSET">
/// 
/// 获取永久层打结实绩信息
///     &gt;&gt;strCondition: 查询条件
/// RET &lt;&lt; 成功返回reInfos；失败返回Null
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetInnerBuildInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_IN_BUILD_URI,strCondition);
}


/// <Method class="CLadle_Mag" name="InsertComTieInfos" type="L3LONG">
/// 
/// 添加工作层打结实绩信息
///     &gt;&gt;rsInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertComTieInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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
		//获取钢包号
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有钢包号
		}
		
		CString csWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkID"));
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有工作层编号
		}
		
		CString csTemp = _T(" SELECT * FROM %s where WorkID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CLADLE_COM_TIE_URI,csWorkID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount()>0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//已经存在普通钢包打结信息
		}

		rsData.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_COM_TIE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateComTieInfos" type="L3LONG">
/// 
/// 修改工作层打结实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateComTieInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_COM_TIE_URI);
}
/// <Method class="CLadle_Mag" name="DeleteComTieInfos" type="L3LONG">
/// 
/// 删除工作层打结实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteComTieInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
	if (rsData.IsNull()||rsData.GetRowCount()<1)
	return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if (bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
		{
			return 0;
		}
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//获取主信息中的WorkID
		CString csWorkID = rsData.GetFieldByName(_T("WorkID")).ToCString();
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();

		//根据主GUID查询从信息
		CString csTemp;
		CString csSQL;

		if (csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//没有工作层编号
		}
		csTemp =_T(" SELECT * FROM %s WHERE WorkID = '%s' ");
		csSQL.Format(csTemp,CLADLE_COM_LAD_REP_URI,csWorkID);
		
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
			{
				Rollback(nTrans);
				return 0;
			}
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(DeleteOldObjects(CLADLE_COM_LAD_REP_URI,rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
				{
					Rollback(nTrans);
					return -2;//删除修补实绩失败
				}
			}
		}
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(DeleteOldObjects(CLADLE_COM_TIE_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
		{
			Rollback(nTrans);
			return 0;
		}
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CLadle_Mag" name="GetComTieInfos" type="L3RECORDSET">
/// 
/// 获取工作层打结实绩信息
///     &gt;&gt;strCondition: 查询条件
/// RET &lt;&lt; 成功返回reInfos；失败返回Null
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetComTieInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_COM_TIE_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="InsertComRepInfos" type="L3LONG">
/// 
/// 添加工作层修补实绩信息
///     &gt;&gt;rsInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertComRepInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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
	if(CreateNewObjects(CLADLE_COM_LAD_REP_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateComRepInfos" type="L3LONG">
/// 
/// 修改工作层修补实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateComRepInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_COM_LAD_REP_URI);
}
/// <Method class="CLadle_Mag" name="DeleteComRepInfos" type="L3LONG">
/// 
/// 删除工作层修补实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteComRepInfos(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLADLE_COM_LAD_REP_URI);
}

/// <Method class="CLadle_Mag" name="GetComRepInfos" type="L3RECORDSET">
/// 
/// 获取工作层修补实绩信息
///     &gt;&gt;strCondition: 查询条件
/// RET &lt;&lt; 成功返回reInfos；失败返回Null
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetComRepInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_COM_LAD_REP_URI,strCondition);
}


/// <Method class="CLadle_Mag" name="InsertFinBuildInfos" type="L3LONG">
/// 
/// 添加工作层砌筑实绩信息
///     &gt;&gt;rsInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertFinBuildInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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
		//获取钢包号
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有钢包号
		}
		
		CString csWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkID"));
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有工作层编号
		}
		CString csTemp = _T(" SELECT * FROM %s where WorkID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CLADLE_FIN_BUILD_URI,csWorkID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount()>0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//已经存在普通钢包打结信息
		}
		
		rsData.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_FIN_BUILD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateFinBuildInfos" type="L3LONG">
/// 
/// 修改工作层砌筑实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateFinBuildInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_FIN_BUILD_URI);
}
/// <Method class="CLadle_Mag" name="DeleteFinBuildInfos" type="L3LONG">
/// 
/// 删除工作层砌筑实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteFinBuildInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
	if (rsData.IsNull()||rsData.GetRowCount()<1)
	{
		return 0;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if (nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csWorkID = rsData.GetFieldByName (_T("WorkID")).ToCString();
		CString csLadleID = rsData.GetFieldByName (_T("LadleID")).ToCString();
		CString csTemp;
		CString csSQL;
		
		if (csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//没有工作层编号
		}
		csTemp =_T(" SELECT * FROM %s WHERE WorkID = '%s' ");
		csSQL.Format(csTemp,CLADLE_CHA_DRE_LIN_URI,csWorkID);
		
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
			{
				Rollback(nTrans);
				return 0;
			}
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(DeleteOldObjects(CLADLE_CHA_DRE_LIN_URI,rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
				{
					Rollback(nTrans);
					return -2;//删除渣线实绩失败
				}
			}
		}
		rsData.MoveNext();
	}

	if(DeleteOldObjects(CLADLE_FIN_BUILD_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CLadle_Mag" name="GetFinBuildInfos" type="L3RECORDSET">
/// 
/// 获取工作层砌筑实绩信息
///     &gt;&gt;strCondition: 查询条件
/// RET &lt;&lt; 成功返回reInfos；失败返回Null
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetFinBuildInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_FIN_BUILD_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="InsertChaDreLinInfos" type="L3LONG">
/// 
/// 添加工作层换渣线实绩信息
///     &gt;&gt;rsInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertChaDreLinInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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
	if(CreateNewObjects(CLADLE_CHA_DRE_LIN_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateChaDreLinInfos" type="L3LONG">
/// 
/// 修改工作层换渣线实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateChaDreLinInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_CHA_DRE_LIN_URI);
}
/// <Method class="CLadle_Mag" name="DeleteChaDreLinInfos" type="L3LONG">
/// 
/// 删除工作层换渣线实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteChaDreLinInfos(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLADLE_CHA_DRE_LIN_URI);
}

/// <Method class="CLadle_Mag" name="GetChaDreLinInfos" type="L3RECORDSET">
/// 
/// 获取工作层换渣线实绩信息
///     &gt;&gt;strCondition: 查询条件
/// RET &lt;&lt; 成功返回reInfos；失败返回Null
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetChaDreLinInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_CHA_DRE_LIN_URI,strCondition);
}


/// <Method class="CLadle_Mag" name="InsertFireInfos" type="L3LONG">
/// 
/// 添加烘烤实绩信息
///     &gt;&gt;rsInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertFireInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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
		//获取钢包号
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有钢包号
		}
		CString csFireType = rsData.GetFieldByName(_T("Fire_Type")).ToCString();
		if( csFireType == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有烘烤类型
		}
		CString csWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkID"));
		if( csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;	//没有工作层编号
		}

		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;
		CString csFireID;

		#pragma region "工作层烘烤"
		//工作层烘烤
		if(csFireType == _T("1"))
		{
			bool bExist = true;
			CString csWorkFireID;
			long lWorkFireID = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkFireID")).ToLong();
			while(lWorkFireID > 0 && bExist)
			{
				csWorkFireID.Format(_T("%d"),lWorkFireID);
				csFireID = csWorkID + _T("1") + csWorkFireID;
				csTemp = _T(" SELECT * FROM %s where FireID = '%s' ");
				csSQL.Format(csTemp,CLADLE_FIRE_URI,csFireID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult) || rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;	
				}
				if(rsResult.GetRowCount()>0)
				{
					bExist = true;
					lWorkFireID--;
				}
				else
				{
					bExist = false;
					rsData.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
					rsData.SetFieldByName(_T("FireID"),CL3Variant(csFireID));
				}
				//没有可以新增的记录
				if(bExist)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -5;//已经存在钢包在线烘烤信息
				}
			}

		}
		#pragma endregion
		#pragma region "在线烘烤"
		//在线烘烤
		else if (csFireType == _T("2"))
		{
			bool bExist = true;
			CString csHotFireID;
			long lHotFireID = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("OnFireID")).ToLong();
			while(lHotFireID > 0 && bExist)
			{
				csHotFireID.Format(_T("%d"),lHotFireID);
				csFireID = csWorkID + _T("2") + csHotFireID;
				csTemp = _T(" SELECT * FROM %s where FireID = '%s' ");
				csSQL.Format(csTemp,CLADLE_FIRE_URI,csFireID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult) || rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;	
				}
				if(rsResult.GetRowCount()>0)
				{
					bExist = true;
					lHotFireID--;
				}
				else
				{
					bExist = false;
					rsData.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
					rsData.SetFieldByName(_T("FireID"),CL3Variant(csFireID));
				}
				//没有可以新增的记录
				if(bExist)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -5;//已经存在钢包在线烘烤信息
				}
			}
		}
		#pragma endregion
		//Modify begin by llj 2011-04-10 增加永久层烘烤
		#pragma region "永久层烘烤"
		//永久层烘烤
		else if(csFireType == _T("3"))
		{
			bool bExist = true;
			CString csInnerFireID;
			long lInnerFireID = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("InnerFireID")).ToLong();
			CString csInnerID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("InnerID"));
			if( csInnerID == _T(""))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;	//没有永久层编号
			}
			while(lInnerFireID > 0 && bExist)
			{
				csInnerFireID.Format(_T("%d"),lInnerFireID);
				csFireID = csInnerID + _T("3") + csInnerFireID;
				csTemp = _T(" SELECT * FROM %s where FireID = '%s' ");
				csSQL.Format(csTemp,CLADLE_FIRE_URI,csFireID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult) || rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;	
				}
				if(rsResult.GetRowCount()>0)
				{
					bExist = true;
					lInnerFireID--;
				}
				else
				{
					bExist = false;
					rsData.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
					rsData.SetFieldByName(_T("FireID"),CL3Variant(csFireID));
				}
				//没有可以新增的记录
				if(bExist)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -7;//已经存在钢包在线烘烤信息
				}
			}

		}
		#pragma endregion
		//Modify end
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_FIRE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateFireInfos" type="L3LONG">
/// 
/// 修改烘烤实绩信息
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateFireInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_FIRE_URI);
}
/// <Method class="CLadle_Mag" name="DeleteFireInfos" type="L3LONG">
/// 
/// 删除烘烤实绩信息
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteFireInfos(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLADLE_FIRE_URI);
}

/// <Method class="CLadle_Mag" name="GetFireInfos" type="L3RECORDSET">
/// 
/// 获取烘烤实绩信息
///     &gt;&gt;strCondition: 查询条件
/// RET &lt;&lt; 成功返回reInfos；失败返回Null
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetFireInfos(L3STRING strCondition)
{
	return GetInfos(CLADLE_FIRE_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="InsertLadleUseInfos" type="L3LONG">
/// 添加使用信息
/// <Param name="rsInfos" type="L3RECORDSET">添加的记录集</Param>
/// </Method>
L3LONG CLadle_Mag::InsertLadleUseInfos(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;//行数小于0

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
		//获取钢包号
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csBOFID = rsData.GetFieldByName(_T("BOFID")).ToCString();//[2009-03-03]

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有获取到钢包号
		}
		
		CL3Variant clWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkID"));
		CString csStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("Status")).ToCString();

		if(csStatus != CLADLE_STATUS_HOT)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//此钢包不是热备钢包
		}

		//如果转炉不为空，判断当前转炉是否存在没有使用的钢包[ComFlag=0]
		if (csBOFID != _T(""))
		{	
			CString csTemp = _T("select * from %s where LadleID = '%s' and BOFID = '%s' and ComFlag = '0' ");
			CString csSQL;
			csSQL.Format(csTemp,CLADLE_USE_URI,csLadleID,csBOFID);

			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	//查询失败
			}
			if(rsResult.GetRowCount() > 0)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -3;	//检查到当前转炉上存在指定钢包，请取消指定
			}
			
		}
		rsData.SetFieldByName(_T("WorkID"),CL3Variant(clWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_USE_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;//rsData.GetRowCount();
}

/// <Method class="CLadle_Mag" name="UpdateLadleUseInfos" type="L3LONG">
/// 修改使用信息
/// <Param name="rsInfos" type="L3RECORDSET">修改的记录集</Param>
/// </Method>
L3LONG CLadle_Mag::UpdateLadleUseInfos(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	//return UpdateInfos(rsInfos,CLADLE_USE_URI);

	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;//行数小于0

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
		//获取钢包号
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csBOFID = rsData.GetFieldByName(_T("BOFID")).ToCString();//[2009-03-03]

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有获取到钢包号
		}
		
		//如果转炉不为空，判断当前转炉是否存在没有使用的钢包[ComFlag=0]
		if (csBOFID != _T(""))
		{	
			CString csTemp = _T("select * from %s where LadleID = '%s' and BOFID = '%s' and ComFlag = '0' ");
			CString csSQL;
			csSQL.Format(csTemp,CLADLE_USE_URI,csLadleID,csBOFID);

			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	//查询失败
			}
			if(rsResult.GetRowCount() > 0)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -3;	//检查到当前转炉上存在指定钢包，请取消指定
			}
			
		}
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!SetObjsPropValues(CLADLE_USE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="DeleteLadleUseInfos" type="L3LONG">
/// 删除使用信息
/// <Param name="rsInfos" type="L3RECORDSET">删除的记录集</Param>
/// </Method>
L3LONG CLadle_Mag::DeleteLadleUseInfos(L3RECORDSET rsInfos)
{
	// TODO : 请在此添加逻辑代码
	return DeleteInfos(rsInfos,CLADLE_USE_URI);
}

/// <Method class="CLadle_Mag" name="GetLadleUseInfos" type="L3RECORDSET">
/// 查询使用信息
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetLadleUseInfos(L3STRING strCondition)
{
	return GetInfos(CLADLE_USE_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="GetUseByLadleID" type="L3RECORDSET">
/// 根据钢包号获取钢包上次周转使用信息
/// <Param name="strLadleID" type="L3STRING">钢包号</Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetUseByLadleID(L3STRING strLadleID)
{
	// TODO : 请在此添加逻辑代码
	CString csLadleID = strLadleID;
	if (csLadleID == _T("")||csLadleID.GetLength()<1)
	{
		return NULL ;
	}

	CStringArray FieldNames;FieldNames.SetSize(7);
	CUIntArray FieldTypes;FieldTypes.SetSize(7);

	FieldNames[0]=_T("LadleID");
	FieldNames[1]=_T("Ladle_Age");
	FieldNames[2]=_T("Steel_Grade");
	FieldNames[3]=_T("Tap_Time");
	FieldNames[4]=_T("Irr_Time");
	FieldNames[5]=_T("Off_Ladle_Time");//
	FieldNames[6]=_T("HeatID");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_LONG;
	FieldTypes[2]=L3VT_STRING;
	FieldTypes[3]=L3VT_DATETIME;
	FieldTypes[4]=L3VT_DATETIME;
	FieldTypes[5]=L3VT_DATETIME;
	FieldTypes[6]=L3VT_STRING;

	CL3RecordSetWrap rsInfo;
	if(!CreateRecordSet(FieldNames,FieldTypes,rsInfo)||rsInfo.IsNull())
		return NULL;

	rsInfo.AppendRecord();
	
	//连铸实绩
	CString csTemp = _T("select * from (SELECT * FROM %s WHERE LadleID = '%s' order by Casting_Start_Time desc) where rownum < 2");
	CString csSQL;
	csSQL.Format(csTemp,_T("XGMESLogic\\CCMMag\\CCCM_Heat_Ladle"),csLadleID);
	CL3RecordSetWrap rsResult;
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;
	
	rsResult.MoveFirst();
	CString csIrrTime = rsResult.GetFieldByName(_T("Casting_Start_Time")).ToCString();
	CString csOffLadleTime = rsResult.GetFieldByName(_T("Departure_Time")).ToCString();
	CString csHeatID = rsResult.GetFieldByName(_T("HeatID")).ToCString();

	rsInfo.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
	rsInfo.SetFieldByName(_T("Irr_Time"),CL3Variant(csIrrTime));
	rsInfo.SetFieldByName(_T("Off_Ladle_Time"),CL3Variant(csOffLadleTime));
	rsInfo.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));

	//出钢时刻
	csTemp = _T("select Tapping_Strat_Time  from %s where HeatID = '%s'");//SteelGrade
	csSQL.Format(csTemp,_T("XGMESLogic\\BOFMag\\CBOF_Process_Data"),csHeatID);
	rsResult.DeleteAll();
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;

	rsResult.MoveFirst();
	CString csTapTime = rsResult.GetFieldByName(_T("Tapping_Strat_Time")).ToCString();
	rsInfo.SetFieldByName(_T("Tap_Time"),CL3Variant(csTapTime));

	//钢种
	csTemp = _T("select SteelGrade  from %s where HeatID = '%s'");
	csSQL.Format(csTemp,_T("XGMESLogic\\BOFMag\\CBOF_Base_Data"),csHeatID);
	rsResult.DeleteAll();
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;

	rsResult.MoveFirst();
	CString csSteelGrade = rsResult.GetFieldByName(_T("SteelGrade")).ToCString();
	rsInfo.SetFieldByName(_T("Steel_Grade"),CL3Variant(csSteelGrade));

	//包龄
	csTemp = _T("select * from (select *  from %s where LadleID = '%s' order by Input_Time desc) where rownum < 2");
	csSQL.Format(csTemp,CLADLE_USE_URI,csLadleID);
	rsResult.DeleteAll();
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;

	rsResult.MoveFirst();
	CString csLadleAge = rsResult.GetFieldByName(_T("Ladle_Age")).ToCString();
	int  iAge=_ttoi(csLadleAge) + 1;
	rsInfo.SetFieldByName(_T("Steel_Grade"),CL3Variant(iAge));

	return rsInfo.Detach();
}

/// <Method class="CLadle_Mag" name="SetLadleInfoTaping" type="L3LONG">
/// 转炉出钢时设置钢包上件信息以及钢包基本信息
/// <Param name="dsInfo" type="L3RECORDSET">钢包号</Param>
/// </Method>
L3LONG CLadle_Mag::SetLadleInfoTaping(L3RECORDSET dsInfo)
{
	return 0;
}

/// <Method class="CLadle_Mag" name="GetIrrEndTime" type="L3RECORDSET">
/// 通过钢包号查询此钢包上次停浇时间
/// <Param name="strLadleID" type="L3STRING">钢包号</Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetIrrEndTime(L3STRING strLadleID)
{
	// TODO : 请在此添加逻辑代码
	CString csLadleID = strLadleID;
	if (csLadleID == _T("")||csLadleID.GetLength()<1)
	{
		return NULL ;
	}

	CString csTemp = _T("select * from (select * from %s where LadleID = '%s' order by Input_time desc) where rownum <2 ");
	CString csSQL;
	csSQL.Format(csTemp,CLADLE_USE_URI,csLadleID);
	CL3RecordSetWrap rsResult;
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;
	
	rsResult.MoveFirst();
	CString csHeatID = rsResult.GetFieldByName(_T("HeatID")).ToCString();

	csTemp = _T("select * from (SELECT * FROM %s WHERE LadleID = '%s' and HeatID = '%s' order by Casting_Start_Time desc) where rownum < 2");
	csSQL.Format(csTemp,_T("XGMESLogic\\CCMMag\\CCCM_Heat_Ladle"),csLadleID,csHeatID);
	rsResult.DeleteAll();
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;

	return rsResult.Detach();
}

/// <Method class="CLadle_Mag" name="LadleInnerBuildStart" type="L3LONG">
/// 钢包永久层砌筑开始
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleInnerBuildStart(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
	int iYear = dtCurrentTime.GetYear();
	int iMonth = dtCurrentTime.GetMonth();

	CString csYear;
	csYear.Format(_T("%d"),iYear);
	csYear = csYear.Right(2);

	CString csMonth;
	csMonth.Format(_T("%02d"),iMonth);

	CString csYearMonth = csYear + csMonth;
	
	//创建用于新增钢包永久层实绩
	CL3RecordSetWrap rsInner;
	if(!CreateClassPropSet(CLADLE_IN_BUILD_URI,rsInner))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csInnerID ;
		if(csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//没有钢包号
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		//查询原永久层编号
		CString csOldInnerID = GetObjectPropValue(csBaseUri,_T("InnerID")).ToCString();
		
		if(csOldInnerID == _T(""))
			csInnerID = csYearMonth + csLadleID + _T("01");
		else
		{
			CString csOldYearMonth = csOldInnerID.Left(4);
			//属于同年同月
			if(csOldYearMonth == csYearMonth)
			{
				CString csOldNO = csOldInnerID.Right(2);
				CString csNO;
				int iNO = _ttoi(csOldNO) + 1;
				csNO.Format(_T("%02d"),iNO);
				csInnerID = csYearMonth + csLadleID + csNO;
			}
			else
				csInnerID = csYearMonth + csLadleID + _T("01");
		}

		SetObjectPropValue(csBaseUri,_T("HeatID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_INNER_BUILD));
		SetObjectPropValue(csBaseUri,_T("Ladle_Age"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("InnerID"),CL3Variant(csInnerID));
		SetObjectPropValue(csBaseUri,_T("WorkID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("WorkFireID"),CL3Variant((L3LONG)0));//2009-04-17
		//Modify begin by llj 2011-04-10 增加永久层烘烤实绩
		SetObjectPropValue(csBaseUri,_T("InnerFireID"),CL3Variant((L3LONG)0));//2009-04-17
		//Modify end
		SetObjectPropValue(csBaseUri,_T("OnFireID"),CL3Variant((L3LONG)0));

		//添加永久层砌筑实绩
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		rsInner.AppendRecord();//
		rsInner.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsInner.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
		rsInner.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
		rsInner.SetFieldByName(_T("Build_Start_Time"),CL3Variant(dtCurrentTime));
		rsInner.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsInner.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsInner.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	rsInner.MoveFirst();
	if(CreateNewObjects(CLADLE_IN_BUILD_URI,rsInner) <  rsInner.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//添加永久层砌筑信息失败		
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleInnerBuildEnd" type="L3LONG">
/// 钢包永久层砌筑结束
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleInnerBuildEnd(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csInnerID =	rsData.GetFieldByName(_T("InnerID")).ToCString();
		if(csLadleID == _T("") || csInnerID ==_T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//钢包号或永久层编号为空
		}
		//修改完成标志
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));
		//修改砌筑结束时间
		CString csInnerUri = CLADLE_IN_BUILD_URI +_T("\\") + csInnerID;
		
		CL3RecordSetWrap rsResult;
		CString csTemp = _T(" SELECT * FROM %s WHERE InnerID = '%s'");
		CString csSQL;
		csSQL.Format(csTemp,CLADLE_IN_BUILD_URI,csInnerID);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if (rsResult.GetRowCount()> 0 )
			SetObjectPropValue(csInnerUri,_T("Build_End_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleWorkBuildStart" type="L3LONG">
/// 钢包工作层打结/砌筑开始
/// <Param name="rsLadles" type="L3LONG"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleWorkBuildStart(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
	//创建用于新增普通钢包工作层实绩
	CL3RecordSetWrap rsComTie;
	if(!CreateClassPropSet(CLADLE_COM_TIE_URI,rsComTie))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	//创建用于新增精炼钢包工作层实绩
	CL3RecordSetWrap rsFinBuild;
	if(!CreateClassPropSet(CLADLE_FIN_BUILD_URI,rsFinBuild))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//钢包号为空
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;

		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();
		CString csInnerID = GetObjectPropValue(csBaseUri,_T("InnerID")).ToCString(); 
		CString csOldWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		long lLadleType = GetObjectPropValue(csBaseUri,_T("LadleType")).ToLong();
		if (csInnerID == _T("")|| lLadleType == 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//没有永久层编号或钢包类型
		}

		int iID;
		CString csOldID;
		CString csID;
		CString csWorkID;
		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;
	
		if(csStatus == CLADLE_STATUS_INNER_FIRE)//永久层烘烤
		{
			iID = 1;
			csID.Format(_T("%02d"),iID);
			csWorkID = csInnerID + csID;
		}
		else 
		{
			if(csStatus == CLADLE_STATUS_OFFLINE)
			{
		
				if(csOldWorkID == _T(""))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				csOldID = csOldWorkID.Right(2);
				iID = _ttoi(csOldID) + 1;
				csID.Format(_T("%02d"),iID);
				csWorkID = csInnerID + csID;
			}
			else
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
		}
		
		//修改基础数据集
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_WORK_DAUB));
		SetObjectPropValue(csBaseUri,_T("WorkID"),CL3Variant(csWorkID));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("WorkFireID"),CL3Variant((L3LONG)0));//2009-04-17
		SetObjectPropValue(csBaseUri,_T("OnFireID"),CL3Variant((L3LONG)0));

		//修改永久层使用次数
		CString csInnerUri = CLADLE_IN_BUILD_URI + _T("\\") + csInnerID;
		csTemp = _T(" SELECT * FROM %s WHERE InnerID = '%s'");
		csSQL.Format(csTemp,CLADLE_IN_BUILD_URI,csInnerID);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		long lLadle_Inner_Use_Count = 0;
		if(rsResult.GetRowCount()>0)
		{
			long lLadle_Inner_Use_Count = GetObjectPropValue(csInnerUri,_T("Ladle_Inner_Use_Count")).ToLong();
			lLadle_Inner_Use_Count++;
			SetObjectPropValue(csInnerUri,_T("Ladle_Inner_Use_Count"),CL3Variant(lLadle_Inner_Use_Count));
		}
		if(lLadle_Inner_Use_Count==0)
			lLadle_Inner_Use_Count++;
		//班别班次数据集
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
		if(lLadleType == 1)
		{
			rsComTie.AppendRecord();
			rsComTie.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsComTie.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsComTie.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
			rsComTie.SetFieldByName(_T("Tie_Start_Time"),CL3Variant(dtCurrentTime));
			rsComTie.SetFieldByName(_T("Ladle_Inner_Use_Count"),CL3Variant(lLadle_Inner_Use_Count));
			rsComTie.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsComTie.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsComTie.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		
		else if(lLadleType == 2|| lLadleType == 3)//为下线钢包，未曾重新打结永久层
		{
			rsFinBuild.AppendRecord();
			rsFinBuild.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsFinBuild.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsFinBuild.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
			rsFinBuild.SetFieldByName(_T("Build_Start_Time"),CL3Variant(dtCurrentTime));
			rsFinBuild.SetFieldByName(_T("Ladle_Inner_Use_Count"),CL3Variant(lLadle_Inner_Use_Count));
			rsFinBuild.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsFinBuild.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsFinBuild.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		rsData.MoveNext();
	}
	if(rsComTie.GetRowCount() > 0)
	{
		rsComTie.MoveFirst();
		if(CreateNewObjects(CLADLE_COM_TIE_URI,rsComTie) < rsComTie.GetRowCount())
		{
			if(bUseTrans)
					Rollback(nTrans);
			return -3;//添加常规钢包打结实绩失败
		}
	}
	if(rsFinBuild.GetRowCount() > 0)
	{
		rsFinBuild.MoveFirst();
		if(CreateNewObjects(CLADLE_FIN_BUILD_URI,rsFinBuild) < rsFinBuild.GetRowCount())
		{
			if(bUseTrans)
					Rollback(nTrans);
			return -4;//添加精炼钢包砌筑信息失败
		}
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleWorkBuildEnd" type="L3LONG">
/// 钢包工作层打结/砌筑结束
/// <Param name="rsLadles" type="L3LONG"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleWorkBuildEnd(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//钢包号为空
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		long lLadleType = GetObjectPropValue(csBaseUri,_T("LadleType")).ToLong();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;
		}
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));
		if(lLadleType == 1)
			SetObjectPropValue(CLADLE_COM_TIE_URI + _T("\\") + csWorkID,_T("Tie_End_Time"),CL3Variant(dtCurrentTime));
		
		else if(lLadleType == 2 || lLadleType == 3)
			SetObjectPropValue(CLADLE_FIN_BUILD_URI + _T("\\") + csWorkID,_T("Build_End_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CLadle_Mag" name="LadleWorkFireStart" type="L3LONG">
/// 钢包工作层烘烤开始
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleWorkFireStart(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
	//创建用于新增钢包工作层烘烤实绩
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//钢包号为空
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		long lWorkFireID = GetObjectPropValue(csBaseUri,_T("WorkFireID")).ToLong();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//没有工作层编号
		}
		lWorkFireID++;
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_WORK_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("WorkFireID"),CL3Variant(lWorkFireID));
		
		CString csFireID;
		csFireID.Format(_T("%d"),lWorkFireID);
		csFireID = csWorkID + _T("1") + csFireID;

		//班别班次数据集
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
		
		//CString csFireID = csWorkID + _T("11");//烘烤编号 = WorkID + 1 +1
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(csFireID));//
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
		rsFire.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
		rsFire.SetFieldByName(_T("Start_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("1")));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}

	rsFire.MoveFirst();
	if(CreateNewObjects(CLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
				Rollback(nTrans);
		return -3;//添加钢包工作层烘烤信息失败
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleWorkFireEnd" type="L3LONG">
/// 钢包工作层烘烤结束
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleWorkFireEnd(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//钢包号为空
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		CString csWorkFireID = GetObjectPropValue(csBaseUri,_T("WorkFireID")).ToCString();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//没有工作层编号
		}
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_COLD));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		//修改钢包工作层烘烤结束时间
		if(csWorkFireID != _T("") && csWorkFireID != _T("0") )
		{
			CString csFireUri = CLADLE_FIRE_URI + _T("\\") + csWorkID + _T("1") + csWorkFireID;
			SetObjectPropValue(csFireUri,_T("End_Time"),CL3Variant(dtCurrentTime));
		}

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleHotFireStart" type="L3LONG">
/// 钢包热备烘烤开始
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleHotFireStart(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
	
	//创建用于新增钢包工作层烘烤实绩
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//钢包号为空
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		long lHotFireID = GetObjectPropValue(csBaseUri,_T("OnFireID")).ToLong();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//没有工作层编号
		}
		lHotFireID++;
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_HOT_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("OnFireID"),CL3Variant(lHotFireID));
		
		//班别班次数据集
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csFireID;
		csFireID.Format(_T("%d"),lHotFireID);
		csFireID = csWorkID + _T("2") + csFireID;
		//添加烘烤记录
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(csFireID));//
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
		rsFire.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
		rsFire.SetFieldByName(_T("Start_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("2")));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	rsFire.MoveFirst();
	if(CreateNewObjects(CLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
				Rollback(nTrans);
		return -3;//添加钢包工作层烘烤信息失败
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleHotFireEnd" type="L3LONG">
/// 钢包热备烘烤结束
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleHotFireEnd(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//钢包号为空
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		CString csOnFireID = GetObjectPropValue(csBaseUri,_T("OnFireID")).ToCString();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//没有工作层编号
		}
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_HOT));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));
		
		//修改钢包工作层烘烤结束时间
		if(csOnFireID != _T("") && csOnFireID != _T("0") )
		{
			CString csFireUri = CLADLE_FIRE_URI + _T("\\") + csWorkID + _T("2") + csOnFireID;
			SetObjectPropValue(csFireUri,_T("End_Time"),CL3Variant(dtCurrentTime));
		}
		
		rsData.MoveNext();
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="BOFTapingStart" type="L3BOOL">
/// 补录转炉出钢开始//20081229Liao
/// <Param name="strUnitID" type="L3STRING">炉座</Param>
/// <Param name="dtTapTime" type="L3DATETIME">出钢开始时间</Param>
/// <Param name="strHeatID" type="L3STRING">炉号</Param>
/// </Method>
L3BOOL CLadle_Mag::BOFTapingStart(L3STRING strUnitID, L3DATETIME dtTapTime, L3STRING strHeatID)
{
	// TODO : 请在此添加逻辑代码
	CString csUnitID = strUnitID;
	CString csUnitUri = BOF_CLASS_URI + _T("\\") + csUnitID;
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	CL3Variant valRet =  InvokeObjectMethod(csUnitUri,_T("CaculateLadleGrade"),dtTapTime,strHeatID);
	//L3SysFreeString(strHeatID);

	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLadle_Mag" name="LadleThrow" type="L3LONG">
/// 钢包甩包
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleThrow(L3RECORDSET rsLadles)
{
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//钢包号为空
		}
		CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csLadleUri,_T("WorkID")).ToCString();

		SetObjectPropValue(csLadleUri,_T("Status"),CL3Variant(CLADLE_STATUS_OFFLINE));
		
		//2009-08-22 liao
		if(csWorkID != _T(""))
		{
			CString csLadleProcessUri = CLADLE_PROCESS_URI + _T("\\") + csWorkID;
			SetObjectPropValue(csLadleProcessUri,_T("Throw_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
			SetObjectPropValue(csLadleProcessUri,_T("Comfirm_Flag"),CL3Variant(L3LONG(1)));
		}

		rsData.MoveNext();
	}
	/*rsData.MoveFirst();
	if(!SetObjsPropValues(CLADLE_BASE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}*/
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CLadle_Mag" name="MeasureDesignate" type="L3LONG">
/// 钢包称重指定 2009-04-13 liao
/// <Param name="strLadleID" type="L3STRING">钢包号</Param>
/// </Method>
L3LONG CLadle_Mag::MeasureDesignate(L3STRING strLadleID)
{
	// TODO : 请在此添加逻辑代码
	CString csLadleID = strLadleID;
	if(csLadleID == _T(""))
		return 0;//没有钢包号
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
		
	CString csTemp = _T("SELECT LadleID,Measure_Flag from %s order by LadleID");
	CString csSQL;
	csSQL.Format(csTemp,CLADLE_BASE_URI);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	
	rsResult.MoveFirst();
	while(!rsResult.IsEOF())
	{
		CString csCurLadleID = rsResult.GetFieldByName(_T("LadleID")).ToCString();
		long lMeasureFlag = rsResult.GetFieldByName(_T("Measure_Flag")).ToLong();
		if(lMeasureFlag == 1)
		{
			CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csCurLadleID;
			if(!SetObjectPropValue(csBaseUri,_T("Measure_Flag"),L3LONG(0)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}

		rsResult.MoveNext();
	}
	CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
	if(!SetObjectPropValue(csBaseUri,_T("Measure_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleOffLineException" type="L3LONG">
/// 钢包异常下线
/// <Param name="rsLadles" type="L3RECORDSET">下线记录</Param>
/// </Method>
L3LONG CLadle_Mag::LadleOffLineException(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;
	if(rsData.GetFieldIndex(_T("LadleID")) < 0 || rsData.GetFieldIndex(_T("Status")) < 0)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csStatus = rsData.GetFieldByName(_T("Status")).ToCString();
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;

		if(csLadleID == _T("") || csStatus == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//没有钢包号或状态
		}
	
		if(csStatus == CLADLE_STATUS_USE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//在用钢包不能异常下线
		}
		
		if(!SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_OFFLINE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//修改中包状态失败
		}

		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}


//Modify begin by llj 2011-04-09 增加永久层烘烤(包含永久层烘烤开始，永久层烘烤结束)
/// <Method class="CLadle_Mag" name="LadleInnerFireStart" type="L3LONG">
/// 钢包永久层烘烤开始
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleInnerFireStart(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
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
	//创建用于新增钢包永久层烘烤实绩
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//钢包号为空
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csInnerID = GetObjectPropValue(csBaseUri,_T("InnerID")).ToCString();
		long lInnerFireID = GetObjectPropValue(csBaseUri,_T("InnerFireID")).ToLong();
		if(csInnerID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//没有永久层编号
		}
		lInnerFireID++;
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_INNER_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("InnerFireID"),CL3Variant(lInnerFireID));
		
		CString csFireID;
		csFireID.Format(_T("%d"),lInnerFireID);
		csFireID = csInnerID + _T("3") + csFireID;

		//班别班次数据集
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
		
		//CString csFireID = csInnerID + _T("11");//烘烤编号 = InnerID + 烘烤类型 +1
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(csFireID));//
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
		rsFire.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
		rsFire.SetFieldByName(_T("Start_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("3")));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}

	rsFire.MoveFirst();
	if(CreateNewObjects(CLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
				Rollback(nTrans);
		return -1;//添加钢包工作层烘烤信息失败
	}
	if(bUseTrans)
		Commit(nTrans);
	return 0;
}

/// <Method class="CLadle_Mag" name="LadleInnerFireEnd" type="L3LONG">
/// 钢包永久层烘烤结束
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleInnerFireEnd(L3RECORDSET rsLadles)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsLadles;
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//钢包号为空
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csInnerID = GetObjectPropValue(csBaseUri,_T("InnerID")).ToCString();
		CString csInnerFireID = GetObjectPropValue(csBaseUri,_T("InnerFireID")).ToCString();
		if(csInnerID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//没有永久层编号
		}
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_INNER_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		//修改钢包永久层烘烤结束时间
		if(csInnerFireID != _T("") && csInnerFireID != _T("0") )
		{
			CString csFireUri = CLADLE_FIRE_URI + _T("\\") + csInnerID + _T("3") + csInnerFireID;
			SetObjectPropValue(csFireUri,_T("End_Time"),CL3Variant(dtCurrentTime));
		}

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 0;
}


//Modify end
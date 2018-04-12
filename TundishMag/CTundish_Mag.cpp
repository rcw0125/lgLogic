// 逻辑类CTundish_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CTundish_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CTundish_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CTundish_Mag.h"
#include "L3NameParser.h"

//当对象被装载到系统中时，被调用
void CTundish_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CTundish_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <Method class="CTundish_Mag" name="InsertInfos" type="L3LONG">
/// 
/// 添加实绩信息
/// ARG &gt;&gt;strClassName:类名
///     &gt;&gt;rsInfos: 要添加的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// <Param name="strClassName" type="L3STRING">类名</Param>
/// </Method>
L3LONG CTundish_Mag::InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName)
{
	// TODO : 请在此添加逻辑代码
	return 0;
}

/// <Method class="CTundish_Mag" name="UpdateInfos" type="L3LONG">
/// 
/// 修改实绩信息
/// ARG &gt;&gt;lpcsClass:类名
///     &gt;&gt;rsInfos: 要修改的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// <Param name="lpcsClass" type="LPCTSTR">类名</Param>
/// </Method>
L3LONG CTundish_Mag::UpdateInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass)
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

/// <Method class="CTundish_Mag" name="DeleteInfos" type="L3LONG">
/// 
/// 删除实绩信息
/// ARG &gt;&gt;lpcsClass:类名
///     &gt;&gt;rsInfos: 要删除的实绩的记录集
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
/// <Param name="lpcsClass" type="LPCTSTR">类名</Param>
/// </Method>
L3LONG CTundish_Mag::DeleteInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass)
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
	if(!DeleteOldObjects(csUri,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="GetInfos" type="L3RECORDSET">
/// 
/// 获取实绩信息
/// ARG &gt;&gt;lpcsClass:类名
///     &gt;&gt;lpcsCondition: 查询条件
/// RET &lt;&lt; 成功返回reInfos；失败返回Null
/// <Param name="lpcsClass" type="LPCTSTR">查询条件</Param>
/// <Param name="lpcsCondition" type="LPCTSTR">类名</Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition =lpcsCondition;
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	CString csUri = lpcsClass;
	
	CString csSQL;
	csSQL.Format(csTemp,csUri,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	
	return rsResult.Detach();
}
/// <Method class="CTundish_Mag" name="TundishInnerBuildStart" type="L3LONG">
/// 
/// 中包永久层打结开始
/// ARG &gt;&gt; rsTundishs: 要打结开始的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishInnerBuildStart(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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
	//创建用于修改CTundish_Base部分数据（铁包号、状态、包龄、永久层编号,工作层编号，完成标志）记录集
	CStringArray FieldNames;FieldNames.SetSize(6);
	CUIntArray FieldTypes;FieldTypes.SetSize(6);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Tundish_Age");
	FieldNames[3]=_T("InnerID");
	FieldNames[4]=_T("WorkID");
	FieldNames[5]=_T("Flag");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_LONG;
	FieldTypes[3]=L3VT_STRING;
	FieldTypes[4]=L3VT_STRING;
	FieldTypes[5]=L3VT_LONG;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于新增中包履历表的记录集，包括(创建时间，中包号，永久层编号， 永久层打结开始时间)
	CStringArray UseNames;UseNames.SetSize(4);
	CUIntArray UseTypes;UseTypes.SetSize(4);

	UseNames[0] = _T("Creat_Time");
	UseNames[1] = _T("TundishID");
	UseNames[2] = _T("InnerID");
	UseNames[3] = _T("Inner_Tie_Start_Time");

	UseTypes[0] = L3VT_DATETIME;
	UseTypes[1] = L3VT_STRING;
	UseTypes[2] = L3VT_STRING;
	UseTypes[3] = L3VT_DATETIME;

	CL3RecordSetWrap rsUse;
	if(!CreateRecordSet(UseNames,UseTypes,rsUse)||rsUse.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于新增中包永久层打结的记录集，包括(中包号，永久层编号， 永久层打结开始时间)
	CStringArray InnerBuildNames;InnerBuildNames.SetSize(4);
	CUIntArray InnerBuildTypes;InnerBuildTypes.SetSize(4);

	InnerBuildNames[0] = _T("TundishID");
	InnerBuildNames[1] = _T("InnerID");
	InnerBuildNames[2] = _T("Tie_Start_Time");
	InnerBuildNames[3] = _T("Inner_Use_Count");

	InnerBuildTypes[0] = L3VT_STRING;
	InnerBuildTypes[1] = L3VT_STRING;
	InnerBuildTypes[2] = L3VT_DATETIME;
	InnerBuildTypes[3] = L3VT_SHORT;

	CL3RecordSetWrap rsInnerBuild;
	if(!CreateRecordSet(InnerBuildNames,InnerBuildTypes,rsInnerBuild)||rsInnerBuild.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csInnerID ;
		if(csTundishID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		//查询原永久层编号
		CString csTemp = _T(" SELECT InnerID FROM %s WHERE TundishID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CTUNDISH_BASE_URI,csTundishID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull()||rsResult.GetRowCount() != 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		rsResult.MoveFirst();
		CString csOldInnerID = rsResult.GetFieldByName(_T("InnerID")).ToString();
		if(csOldInnerID == _T(""))
		{
			csInnerID = csYearMonth + csTundishID + _T("01");
		}
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
				csInnerID = csYearMonth + csTundishID + csNO;
			}
			else
			{
				csInnerID = csYearMonth + csTundishID + _T("01");
			}
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_INNER_BUILD));
		rsBase.SetFieldByName(_T("Tundish_Age"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
		rsBase.SetFieldByName(_T("WorkID"),CL3Variant(_T("")));
		rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)0));

		rsUse.AppendRecord();
		rsUse.SetFieldByName(_T("Creat_Time"),CL3Variant(dtCurrentTime));
		rsUse.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsUse.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
		rsUse.SetFieldByName(_T("Inner_Tie_Start_Time"),CL3Variant(dtCurrentTime));

		rsInnerBuild.AppendRecord();
		rsInnerBuild.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsInnerBuild.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
		rsInnerBuild.SetFieldByName(_T("Tie_Start_Time"),CL3Variant(dtCurrentTime));
		rsInnerBuild.SetFieldByName(_T("Inner_Use_Count"),CL3Variant((L3LONG)0));

		rsData.MoveNext();
	}
	
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	rsUse.MoveFirst();
	if(CreateNewObjects(CTUNDISH_USE_INFO_URI,rsUse) <  rsUse.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	rsInnerBuild.MoveFirst();
	if(CreateNewObjects(CTUNDISH_INNER_BUILD_URI,rsInnerBuild) <  rsInnerBuild.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="TundishInnerBuildEnd" type="L3LONG">
/// 
/// 中包永久层打结结束
/// ARG &gt;&gt; rsTundishs: 要打结结束的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishInnerBuildEnd(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csInnerID = rsData.GetFieldByName(_T("InnerID")).ToCString();
		if(csInnerID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if(!SetObjectPropValue(CTUNDISH_BASE_URI + _T("\\") + csTundishID,_T("Flag"),CL3Variant((L3LONG)1)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}

		if(!SetObjectPropValue(CTUNDISH_INNER_BUILD_URI + _T("\\") + csInnerID,_T("Tie_End_Time"),CL3Variant(dtCurrentTime)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}

		CString csTemp = _T(" select * from %s where InnerID = '%s' order by InnerID desc");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csInnerID);
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
			if(!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Inner_Tie_End_Time"),CL3Variant(dtCurrentTime)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}
	
		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="TundishInnerFireStart" type="L3LONG">
/// 
/// 中包永久层烘烤开始
/// ARG &gt;&gt; rsTundishs: 要烘烤开始的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishInnerFireStart(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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

	//创建用于修改CTundish_Base部分数据（铁包号、状态、完成标志）记录集
	CStringArray FieldNames;FieldNames.SetSize(3);
	CUIntArray FieldTypes;FieldTypes.SetSize(3);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Flag");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_LONG;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于新增中包履历表的记录集，包括(GUID,永久层烘烤开始时间)
	CStringArray UseNames;UseNames.SetSize(2);
	CUIntArray UseTypes;UseTypes.SetSize(2);

	UseNames[0] = _T("GUID");
	UseNames[1] = _T("Inner_Small_Fire_Time");

	UseTypes[0] = L3VT_STRING;
	UseTypes[1] = L3VT_DATETIME;

	CL3RecordSetWrap rsUse;
	if(!CreateRecordSet(UseNames,UseTypes,rsUse)||rsUse.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于新增中包永久层烘烤实绩的记录集，包括(中包号，永久层编号，永久层小伙烘烤开始时间)
	CStringArray InnerFireNames;InnerFireNames.SetSize(3);
	CUIntArray InnerFireTypes;InnerFireTypes.SetSize(3);

	InnerFireNames[0] = _T("TundishID");
	InnerFireNames[1] = _T("InnerID");
	InnerFireNames[2] = _T("Small_Fire_Time");

	InnerFireTypes[0] = L3VT_STRING;
	InnerFireTypes[1] = L3VT_STRING;
	InnerFireTypes[2] = L3VT_DATETIME;

	CL3RecordSetWrap rsInnerFire;
	if(!CreateRecordSet(InnerFireNames,InnerFireTypes,rsInnerFire)||rsInnerFire.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csInnerID = rsData.GetFieldByName(_T("InnerID")).ToCString();
		if(csInnerID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_INNER_FIRE));
		rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)0));

		CString csTemp = _T(" select * from %s where InnerID = '%s'  order by InnerID desc");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csInnerID);
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			
			CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
			rsUse.AppendRecord();
			rsUse.SetFieldByName(_T("GUID"),CL3Variant(csGUID));
			rsUse.SetFieldByName(_T("Inner_Small_Fire_Time"),CL3Variant(dtCurrentTime));
		}

		rsInnerFire.AppendRecord();
		rsInnerFire.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsInnerFire.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
		rsInnerFire.SetFieldByName(_T("Small_Fire_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}

	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	rsUse.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_USE_INFO_URI,rsUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	rsInnerFire.MoveFirst();
	if(CreateNewObjects(CTUNDISH_INNER_FIRE_URI,rsInnerFire) <  rsInnerFire.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="TundishInnerFireEnd" type="L3LONG">
/// 
/// 中包永久层烘烤结束
/// ARG &gt;&gt; rsTundishs: 要烘烤结束的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishInnerFireEnd(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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

	//创建用于修改CTundish_Base部分数据（铁包号、完成标志）记录集
	CStringArray FieldNames;FieldNames.SetSize(2);
	CUIntArray FieldTypes;FieldTypes.SetSize(2);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Flag");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_LONG;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于修改中包履历表的记录集，包括(GUID,永久层烘烤结束时间)
	CStringArray UseNames;UseNames.SetSize(2);
	CUIntArray UseTypes;UseTypes.SetSize(2);

	UseNames[0] = _T("GUID");
	UseNames[1] = _T("Inner_Close_Fire_Time");

	UseTypes[0] = L3VT_STRING;
	UseTypes[1] = L3VT_DATETIME;

	CL3RecordSetWrap rsUse;
	if(!CreateRecordSet(UseNames,UseTypes,rsUse)||rsUse.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于修改中包永久层烘烤实绩的记录集，包括(永久层编号，永久层烘烤结束时间 )
	CStringArray InnerBuildNames;InnerBuildNames.SetSize(2);
	CUIntArray InnerBuildTypes;InnerBuildTypes.SetSize(2);

	InnerBuildNames[0] = _T("InnerID");
	InnerBuildNames[1] = _T("Close_Fire_Time");

	InnerBuildTypes[0] = L3VT_STRING;
	InnerBuildTypes[1] = L3VT_DATETIME;

	CL3RecordSetWrap rsInnerBuild;
	if(!CreateRecordSet(InnerBuildNames,InnerBuildTypes,rsInnerBuild)||rsInnerBuild.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csInnerID = rsData.GetFieldByName(_T("InnerID")).ToCString();
		if(csInnerID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)1));

		CString csTemp = _T(" select * from %s where InnerID = '%s'  order by InnerID desc");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csInnerID);
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();

			rsUse.AppendRecord();
			rsUse.SetFieldByName(_T("GUID"),CL3Variant(csGUID));
			rsUse.SetFieldByName(_T("Inner_Close_Fire_Time"),CL3Variant(dtCurrentTime));
		}

		rsInnerBuild.AppendRecord();
		rsInnerBuild.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
		rsInnerBuild.SetFieldByName(_T("Close_Fire_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	rsUse.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_USE_INFO_URI,rsUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	rsInnerBuild.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_INNER_FIRE_URI,rsInnerBuild))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="TundishWorkBuildStart" type="L3LONG">
/// 
/// 中包工作层涂抹/干振开始
/// ARG &gt;&gt; rsTundishs: 要涂抹/干振开始的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishWorkBuildStart(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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

	//创建用于设置CTundish_Base部分数据（铁包号、状态、工作层编号）记录集
	CStringArray FieldNames;FieldNames.SetSize(5);
	CUIntArray FieldTypes;FieldTypes.SetSize(5);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("WorkID");
	FieldNames[3]=_T("Flag");
	FieldNames[4]=_T("Tundish_Age");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_STRING;
	FieldTypes[3]=L3VT_LONG;
	FieldTypes[4]=L3VT_LONG;

	CL3RecordSetWrap rsBase;
	if((!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于新增中包履历表的记录集，包括(创建时间，中包号，工作层编号，工作层修砌开始时间 )
	CStringArray UseNames;UseNames.SetSize(9);
	CUIntArray UseTypes;UseTypes.SetSize(9);

	UseNames[0] = _T("Creat_Time");
	UseNames[1] = _T("TundishID");
	UseNames[2] = _T("InnerID");
	UseNames[3] = _T("Inner_Tie_Start_Time");
	UseNames[4] = _T("Inner_Tie_End_Time");
	UseNames[5] = _T("Inner_Small_Fire_Time");
	UseNames[6] = _T("Inner_Close_Fire_Time");
	UseNames[7] = _T("Daub_Start_Time");
	UseNames[8] = _T("WorkID");

	UseTypes[0] = L3VT_DATETIME;
	UseTypes[1] = L3VT_STRING;
	UseTypes[2] = L3VT_STRING;
	UseTypes[3] = L3VT_DATETIME;
	UseTypes[4] = L3VT_DATETIME;
	UseTypes[5] = L3VT_DATETIME;
	UseTypes[6] = L3VT_DATETIME;
	UseTypes[7] = L3VT_DATETIME;
	UseTypes[8] = L3VT_STRING;

	CL3RecordSetWrap rsUse;
	if(!CreateRecordSet(UseNames,UseTypes,rsUse)||rsUse.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于修改中包履历表的记录集，包括(GUID，工作层编号，工作层修砌开始时间 )
	CStringArray UseModNames;UseModNames.SetSize(3);
	CUIntArray UseModTypes;UseModTypes.SetSize(3);

	UseModNames[0] = _T("GUID");
	UseModNames[1] = _T("WorkID");
	UseModNames[2] = _T("Daub_Start_Time");

	UseModTypes[0] = L3VT_STRING;
	UseModTypes[1] = L3VT_STRING;
	UseModTypes[2] = L3VT_DATETIME;

	CL3RecordSetWrap rsUseMod;
	if(!CreateRecordSet(UseModNames,UseModTypes,rsUseMod)||rsUseMod.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于修改中包永久层打结实绩的记录集，包括(永久层编号，永久层使用次数 )
	CStringArray InnerBuildNames;InnerBuildNames.SetSize(2);
	CUIntArray InnerBuildTypes;InnerBuildTypes.SetSize(2);

	InnerBuildNames[0] = _T("InnerID");
	InnerBuildNames[1] = _T("Inner_Use_Count");

	InnerBuildTypes[0] = L3VT_STRING;
	InnerBuildTypes[1] = L3VT_SHORT;

	CL3RecordSetWrap rsInnerBuild;
	if(!CreateRecordSet(InnerBuildNames,InnerBuildTypes,rsInnerBuild)||rsInnerBuild.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于新增中包工作层涂抹\干振实绩的记录集，包括(中包号，工作层编号，永久层编号，永久层使用次数，工作层涂抹\干振开始时间)
	CStringArray DaubNames;DaubNames.SetSize(5);
	CUIntArray DaubTypes;DaubTypes.SetSize(5);

	DaubNames[0] = _T("TundishID");
	DaubNames[1] = _T("WorkID");
	DaubNames[2] = _T("InnerID");
	DaubNames[3] = _T("Inner_Use_Count");
	DaubNames[4] = _T("Daub_Start_Time");

	DaubTypes[0] = L3VT_STRING;
	DaubTypes[1] = L3VT_STRING;
	DaubTypes[2] = L3VT_STRING;
	DaubTypes[3] = L3VT_SHORT;
	DaubTypes[4] = L3VT_DATETIME;

	CL3RecordSetWrap rsDaub;
	if(!CreateRecordSet(DaubNames,DaubTypes,rsDaub)||rsDaub.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csStatus = rsData.GetFieldByName(_T("Status")).ToCString();
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csInnerID = rsData.GetFieldByName(_T("InnerID")).ToCString();
		CString csOldWorkID = rsData.GetFieldByName (_T("WorkID")).ToCString();
		CString csTundishType =   rsData.GetFieldByName(_T("TundishType")).ToCString(); 

		int iID;
		CString csOldID;
		CString csID;
		CString csWorkID;
		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;

		if(csStatus ==  _T("")||csTundishID == _T("")||csInnerID == _T("")|| csTundishType == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}

		if(csTundishType == _T("1"))//1、2#机中包
		{
			if(csStatus != CTUNDISH_STATUS_ISTALL)//如果状态不为中包上件
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}

			csTemp = _T(" SELECT * FROM %s WHERE WorkID = '%s' ");
			csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csOldWorkID);
			rsResult.DeleteAll();
			if(!Query(csSQL,rsResult)||rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}

			if(rsResult.GetRowCount () > 0)
			{
				rsResult.MoveFirst();
				CString csGuid = rsResult.GetFieldByName(_T("GUID")).ToCString();
				
				rsUseMod.AppendRecord();
				rsUseMod.SetFieldByName(_T("GUID"),CL3Variant(csGuid));
				rsUseMod.SetFieldByName(_T("WorkID"),CL3Variant(csOldWorkID));
				rsUseMod.SetFieldByName(_T("Daub_Start_Time"),CL3Variant(dtCurrentTime));
			}

			
			//给基础数据集赋值
			rsBase.AppendRecord();
			rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_WORK_DAUB));
			rsBase.SetFieldByName(_T("WorkID"),CL3Variant(csOldWorkID));
			rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)0));
			rsBase.SetFieldByName(_T("Tundish_Age"),CL3Variant((L3LONG)0));

			csOldID = csOldWorkID.Right(2);
			iID = _ttoi(csOldID);

			//给永久层打结数据集赋值
			rsInnerBuild.AppendRecord();
			rsInnerBuild.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
			rsInnerBuild.SetFieldByName(_T("Inner_Use_Count"),CL3Variant((L3SHORT(iID))));
		
			//给工作层涂抹\干振数据集赋值
			rsDaub.AppendRecord();
			rsDaub.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsDaub.SetFieldByName(_T("WorkID"),CL3Variant(csOldWorkID));
			rsDaub.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
			rsDaub.SetFieldByName(_T("Inner_Use_Count"),CL3Variant((L3SHORT)iID));
			rsDaub.SetFieldByName(_T("Daub_Start_Time"),CL3Variant(dtCurrentTime));

		}
		//modify begin by llj 2011-03-12 增加7#铸机的中包 屏蔽原语句
		//else if (csTundishType == _T("2") || csTundishType == _T("3"))//3、4、5#机中包
		else if (csTundishType == _T("2") || csTundishType == _T("3")||csTundishType == _T("4")||csTundishType == _T("5"))//3、4、5#、7#机中包   //modify by hyh 2012-06-08 新增6#CCM
		//modify end
		{
			if(csStatus == CTUNDISH_STATUS_INNER_FIRE)//新永久层打结,永久层已烘烤完毕
			{
				iID = 1;
				csID.Format(_T("%02d"),iID);
				csWorkID = csInnerID + csID;

				csTemp = _T(" SELECT * FROM %s WHERE InnerID = '%s' AND WorkID is null");
				csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csInnerID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult)||rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}

				if(rsResult.GetRowCount () > 0)
				{
					rsResult.MoveFirst();
					CString csGuid = rsResult.GetFieldByName(_T("GUID")).ToCString();
					
					rsUseMod.AppendRecord();
					rsUseMod.SetFieldByName(_T("GUID"),CL3Variant(csGuid));
					rsUseMod.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
					rsUseMod.SetFieldByName(_T("Daub_Start_Time"),CL3Variant(dtCurrentTime));
				}
			}
			else if(csStatus == CTUNDISH_STATUS_OFFLINE)//为下线中包，未曾重新打结永久层
			{
				csOldID = csOldWorkID.Right(2);
				iID = _ttoi(csOldID) + 1;
				csID.Format(_T("%02d"),iID);
				csWorkID = csInnerID + csID;

				//查询中包上一个工作层编号对应永久层最新履历
				csTemp = _T(" SELECT * FROM %s WHERE WorkID = '%s'" );
				csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csOldWorkID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult)||rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				if(rsResult.GetRowCount () > 0)
				{
					rsResult.MoveFirst();
					CString csInnerTieStartTime = rsResult.GetFieldByName(_T("Inner_Tie_Start_Time")).ToCString();
					CString csInnerTieEndTime = rsResult.GetFieldByName(_T("Inner_Tie_End_Time")).ToCString();
					CString csInnerSmallFireTime = rsResult.GetFieldByName(_T("Inner_Small_Fire_Time")).ToCString();
					CString csInnerCloseFireTime = rsResult.GetFieldByName(_T("Inner_Close_Fire_Time")).ToCString();

					rsUse.AppendRecord();
					rsUse.SetFieldByName(_T("Creat_Time"),CL3Variant(dtCurrentTime));
					rsUse.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
					rsUse.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
					rsUse.SetFieldByName(_T("Inner_Tie_Start_Time"),CL3Variant(csInnerTieStartTime));
					rsUse.SetFieldByName(_T("Inner_Tie_End_Time"),CL3Variant(csInnerTieEndTime));
					rsUse.SetFieldByName(_T("Inner_Small_Fire_Time"),CL3Variant(csInnerSmallFireTime));
					rsUse.SetFieldByName(_T("Inner_Close_Fire_Time"),CL3Variant(csInnerCloseFireTime));
					rsUse.SetFieldByName(_T("Daub_Start_Time"),CL3Variant(dtCurrentTime));
					rsUse.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
				}
			}
	
			//给基础数据集赋值
			rsBase.AppendRecord();
			rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_WORK_DAUB));
			rsBase.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)0));
			rsBase.SetFieldByName(_T("Tundish_Age"),CL3Variant((L3LONG)0));

			//给永久层打结数据集赋值
			rsInnerBuild.AppendRecord();
			rsInnerBuild.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
			rsInnerBuild.SetFieldByName(_T("Inner_Use_Count"),CL3Variant((L3SHORT(iID))));
		
			//给工作层涂抹\干振数据集赋值
			rsDaub.AppendRecord();
			rsDaub.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsDaub.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsDaub.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
			rsDaub.SetFieldByName(_T("Inner_Use_Count"),CL3Variant((L3SHORT)iID));
			rsDaub.SetFieldByName(_T("Daub_Start_Time"),CL3Variant(dtCurrentTime));

		}
		rsData.MoveNext();
	}
	
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
		return 0;
	}
	rsInnerBuild.MoveFirst();
	//Modify begin 2011-05-16 by llj 修改钢包不能干膜的处理
	//屏蔽下面语句
	/*if(!SetObjsPropValues(CTUNDISH_INNER_BUILD_URI,rsInnerBuild))
	{
		if(bUseTrans)
				Rollback(nTrans);
		return 0;
	}*/
	CString csSql=_T("select * from CTundish_Inner_Build where InnerID='")+rsInnerBuild.GetFieldByName(_T("InnerID")).ToCString()+_T("'");
	CL3RecordSetWrap rsResult;
	if(Query(csSql,rsResult)&&rsResult.GetRowCount()>0)
	{
		if(!SetObjsPropValues(CTUNDISH_INNER_BUILD_URI,rsInnerBuild))
		{
			if(bUseTrans)
					Rollback(nTrans);
			return 0;
		}	
	}
	else
	{
		if(!CreateNewObjects(CTUNDISH_INNER_BUILD_URI,rsInnerBuild))
		{
			if(bUseTrans)
					Rollback(nTrans);
			return 0;
		}
	}
	//Modify end
	rsDaub.MoveFirst();
	if(CreateNewObjects(CTUNDISH_DAUB_URI,rsDaub) < rsDaub.GetRowCount())
	{
		if(bUseTrans)
				Rollback(nTrans);
		return 0;
	}
	if(rsUse.GetRowCount() > 0)
	{
		rsUse.MoveFirst();
		if(!CreateNewObjects(CTUNDISH_USE_INFO_URI,rsUse))
		{
			if(bUseTrans)
					Rollback(nTrans);
			return 0;
		}
	}
	if(rsUseMod.GetRowCount() > 0)
	{
		rsUseMod.MoveFirst();
		if(!SetObjsPropValues(CTUNDISH_USE_INFO_URI,rsUseMod))
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

/// <Method class="CTundish_Mag" name="TundishWorkBuildEnd" type="L3LONG">
/// 
/// 中包工作层涂抹/干振结束
/// ARG &gt;&gt; rsTundishs: 要中包工作层涂抹/干振的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishWorkBuildEnd(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csWorkID = rsData.GetFieldByName(_T("WorkID")).ToCString();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if(!SetObjectPropValue(CTUNDISH_BASE_URI + _T("\\") + csTundishID,_T("Flag"),CL3Variant((L3LONG)1)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}
		if(!SetObjectPropValue(CTUNDISH_DAUB_URI + _T("\\") + csWorkID,_T("Daub_End_Time"),CL3Variant(dtCurrentTime)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}

		CString csTemp = _T(" select * from %s where WorkID = '%s' order by WorkID desc");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csWorkID);
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			CString csGUID = rsResult.GetFieldByName(_T("GUID"));
			if(!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Daub_End_Time"),CL3Variant(dtCurrentTime)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="TundishWorkFireStart" type="L3LONG">
/// 
/// 中包工作层烘烤开始
/// ARG &gt;&gt; rsTundishs: 要工作层烘烤开始的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishWorkFireStart(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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

	//创建用于设置CTundish_Base部分数据（铁包号、状态、）记录集
	CStringArray FieldNames;FieldNames.SetSize(3);
	CUIntArray FieldTypes;FieldTypes.SetSize(3);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Flag");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_LONG;

	CL3RecordSetWrap rsBase;
	if((!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csWorkID = rsData.GetFieldByName(_T("WorkID")).ToCString();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		//修改涂抹\干振实绩烘烤开始时间
		if(!SetObjectPropValue(CTUNDISH_DAUB_URI + _T("\\") + csWorkID,_T("Fire_Start_Time"),CL3Variant(dtCurrentTime)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_WORK_FIRE));
		rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)0));
		
		CString csTemp = _T(" select * from %s where TundishID = '%s' and WorkID = '%s' ");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csTundishID,csWorkID);
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount() > 0 )
		{
			rsResult.MoveFirst();
			CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
			if(!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Fire_Start_Time"),CL3Variant(dtCurrentTime)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
		return 0;
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="TundishWorkFireEnd" type="L3LONG">
/// 
/// 中包工作层烘烤结束
/// ARG &gt;&gt; rsTundishs: 要工作层烘烤结束的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishWorkFireEnd(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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

	//创建用于设置CTundish_Base部分数据（铁包号、状态、）记录集
	CStringArray FieldNames;FieldNames.SetSize(3);
	CUIntArray FieldTypes;FieldTypes.SetSize(3);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Flag");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_LONG;

	CL3RecordSetWrap rsBase;
	if((!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csWorkID = rsData.GetFieldByName(_T("WorkID")).ToCString();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_WORK_FIRE));
		rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)1));

		if(!SetObjectPropValue(CTUNDISH_DAUB_URI + _T("\\") + csWorkID,_T("Fire_End_Time"),CL3Variant(dtCurrentTime)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}

		CString csTemp = _T(" select * from %s where TundishID = '%s' and WorkID = '%s' ");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csTundishID,csWorkID);
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
			if(!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Fire_End_Time"),CL3Variant(dtCurrentTime)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}

		rsData.MoveNext();
	}

	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CTundish_Mag" name="TundishConfirmCold" type="L3LONG">
/// 确认中包冷备
/// <Param name="dsTundish" type="L3RECORDSET">中包记录集</Param>
/// </Method>
L3LONG CTundish_Mag::TundishConfirmCold(L3RECORDSET dsTundish)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsTundish;
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

	//创建用于设置CTundish_Base部分数据（铁包号、状态、）记录集
	CStringArray FieldNames;FieldNames.SetSize(3);
	CUIntArray FieldTypes;FieldTypes.SetSize(3);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Flag");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_LONG;

	CL3RecordSetWrap rsBase;
	if((!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_COLD));
		rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)1));

		rsData.MoveNext();
	}

	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

///2009-02-28Liao
/// <Method class="CTundish_Mag" name="TundishInstallStart" type="L3LONG">
/// 中包开始上件
/// <Param name="dsTundish" type="L3RECORDSET">中包记录集</Param>
/// </Method>
L3LONG CTundish_Mag::TundishInstallStart(L3RECORDSET dsTundish)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsTundish;
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

	/*对于中包直接从离线到连铸上件的情况：其中先生成工作层编号，以作为中包上件数据管理修改时使用
	编号的产生方式：获取当前对应中包履历的最大工作层编号，然后加1*/
	//创建用于新增或则修改中包履历表的记录集，包括(创建时间，中包号，工作层编号，上件开始时间 )
	CStringArray UseNames;UseNames.SetSize(9);
	CUIntArray UseTypes;UseTypes.SetSize(9);

	UseNames[0] = _T("Creat_Time");
	UseNames[1] = _T("TundishID");
	UseNames[2] = _T("InnerID");
	UseNames[3] = _T("Inner_Tie_Start_Time");
	UseNames[4] = _T("Inner_Tie_End_Time");
	UseNames[5] = _T("Inner_Small_Fire_Time");
	UseNames[6] = _T("Inner_Close_Fire_Time");
	UseNames[7] = _T("Install_Start_Time");
	UseNames[8] = _T("WorkID");

	UseTypes[0] = L3VT_DATETIME;
	UseTypes[1] = L3VT_STRING;
	UseTypes[2] = L3VT_STRING;
	UseTypes[3] = L3VT_DATETIME;
	UseTypes[4] = L3VT_DATETIME;
	UseTypes[5] = L3VT_DATETIME;
	UseTypes[6] = L3VT_DATETIME;
	UseTypes[7] = L3VT_DATETIME;
	UseTypes[8] = L3VT_STRING;

	CL3RecordSetWrap rsUse;
	if(!CreateRecordSet(UseNames,UseTypes,rsUse)||rsUse.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于修改中包履历表的记录集，包括(GUID，工作层编号，工作层修砌开始时间 )
	CStringArray UseModNames;UseModNames.SetSize(3);
	CUIntArray UseModTypes;UseModTypes.SetSize(3);

	UseModNames[0] = _T("GUID");
	UseModNames[1] = _T("WorkID");
	UseModNames[2] = _T("Install_Start_Time");

	UseModTypes[0] = L3VT_STRING;
	UseModTypes[1] = L3VT_STRING;
	UseModTypes[2] = L3VT_DATETIME;

	CL3RecordSetWrap rsUseMod;
	if(!CreateRecordSet(UseModNames,UseModTypes,rsUseMod)||rsUseMod.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//// 锁定本对象
	//if(!PutObjectIntoTrans(_T("XGMESLogic\\TundishMag\\CTundish_Mag\\Tundish_Mag")))
	//{
	//	if(nTrans > 0)
	//		Rollback(nTrans);
	//	return FALSE;
	//}

	//创建用于设置CTundish_Base部分数据（铁包号、状态、）记录集
	CStringArray FieldNames;FieldNames.SetSize(4);
	CUIntArray FieldTypes;FieldTypes.SetSize(4);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Flag");
	FieldNames[3]=_T("WorkID");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_LONG;
	FieldTypes[3]=L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if((!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于新增CTundish_OT_Install部分数据（）记录集
	CStringArray OTInstallNames;OTInstallNames.SetSize(3);
	CUIntArray OTInstallTypes;OTInstallTypes.SetSize(3);

	OTInstallNames[0]=_T("TundishID");
	OTInstallNames[1]=_T("WorkID");
	OTInstallNames[2]=_T("Install_Time");

	OTInstallTypes[0]=L3VT_STRING;
	OTInstallTypes[1]=L3VT_STRING;
	OTInstallTypes[2]=L3VT_DATETIME;

	CL3RecordSetWrap rsOTInstall;
	if((!CreateRecordSet(OTInstallNames,OTInstallTypes,rsOTInstall)||rsOTInstall.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于新增CTundish_TFF_Install部分数据（）记录集
	CStringArray TFFInstallNames;TFFInstallNames.SetSize(3);
	CUIntArray TFFInstallTypes;TFFInstallTypes.SetSize(3);

	TFFInstallNames[0]=_T("TundishID");
	TFFInstallNames[1]=_T("WorkID");
	TFFInstallNames[2]=_T("Install_Time");

	TFFInstallTypes[0]=L3VT_STRING;
	TFFInstallTypes[1]=L3VT_STRING;
	TFFInstallTypes[2]=L3VT_DATETIME;

	CL3RecordSetWrap rsTFFInstall;
	if((!CreateRecordSet(TFFInstallNames,TFFInstallTypes,rsTFFInstall)||rsTFFInstall.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csWorkID = rsData.GetFieldByName(_T("WorkID")).ToCString();
		CString csInnerID = rsData.GetFieldByName(_T("InnerID")).ToCString();
		CString csTundishType = rsData.GetFieldByName(_T("TundishType")).ToCString(); 

		//没有中包号或永久层编号则退出操作
		if(csTundishID == _T("") || csInnerID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		//获取对应中包状态
		CL3Variant cvCurStatus = GetObjectPropValue(CTUNDISH_BASE_URI + _T("\\") + csTundishID,_T("Status"));
		CString csStatus = cvCurStatus.ToCString();

		int iID;
		CString csOldID;
		CString csID;
		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;
		
		if(csTundishType == _T("1"))//1、2机中包
		{
			if(csStatus == CTUNDISH_STATUS_INNER_FIRE)//新永久层打结,永久层已烘烤完毕
			{
				iID = 1;
				csID.Format(_T("%02d"),iID);
				csWorkID = csInnerID + csID;

				csTemp = _T(" SELECT * FROM %s WHERE InnerID = '%s' AND WorkID is null");
				csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csInnerID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult)||rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}

				if(rsResult.GetRowCount() > 0)
				{
					rsResult.MoveFirst();
					CString csGuid = rsResult.GetFieldByName(_T("GUID")).ToCString();
					
					rsUseMod.AppendRecord();
					rsUseMod.SetFieldByName(_T("GUID"),CL3Variant(csGuid));
					rsUseMod.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
					rsUseMod.SetFieldByName(_T("Install_Start_Time"),CL3Variant(dtCurrentTime));
				}
			}
			//如果是1、2#机中包，并且是直接从离线待修到连铸中包上件
			else if(csStatus == CTUNDISH_STATUS_OFFLINE)//上1、2#铸机
			{
				//根据中包永久层编号查询中包最大工作层编号对应永久层(最新)履历
				csTemp = _T(" select * from %s where WorkID in (select max(workID) from %s where InnerID = '%s' )" );
				csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,CTUNDISH_USE_INFO_URI,csInnerID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult)||rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				
				rsResult.MoveFirst();


				CString csOldWorkID = rsResult.GetFieldByName(_T("WorkID")).ToCString();
				csOldID = csOldWorkID.Right(2);
				iID = _ttoi(csOldID) + 1;
				csID.Format(_T("%02d"),iID);
				csWorkID = csInnerID + csID;

				CString csInnerTieStartTime = rsResult.GetFieldByName(_T("Inner_Tie_Start_Time")).ToCString();
				CString csInnerTieEndTime = rsResult.GetFieldByName(_T("Inner_Tie_End_Time")).ToCString();
				CString csInnerSmallFireTime = rsResult.GetFieldByName(_T("Inner_Small_Fire_Time")).ToCString();
				CString csInnerCloseFireTime = rsResult.GetFieldByName(_T("Inner_Close_Fire_Time")).ToCString();

				////创建中包时间履历记录
				rsUse.AppendRecord();
				rsUse.SetFieldByName(_T("Creat_Time"),CL3Variant(dtCurrentTime));
				rsUse.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
				rsUse.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
				rsUse.SetFieldByName(_T("Inner_Tie_Start_Time"),CL3Variant(csInnerTieStartTime));
				rsUse.SetFieldByName(_T("Inner_Tie_End_Time"),CL3Variant(csInnerTieEndTime));
				rsUse.SetFieldByName(_T("Inner_Small_Fire_Time"),CL3Variant(csInnerSmallFireTime));
				rsUse.SetFieldByName(_T("Inner_Close_Fire_Time"),CL3Variant(csInnerCloseFireTime));
				rsUse.SetFieldByName(_T("Install_Start_Time"),CL3Variant(dtCurrentTime));
				rsUse.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			}
			//新增上件记录
			rsOTInstall.AppendRecord();
			rsOTInstall.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsOTInstall.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsOTInstall.SetFieldByName(_T("Install_Time"),CL3Variant(dtCurrentTime));
			
			//修改基本信息
			rsBase.AppendRecord();
			rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsBase.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_ISTALL));
			rsBase.SetFieldByName(_T("Flag"),L3LONG(0));

		}
		////3、4、5#机中包
		//Modify begin by llj 2011-03-15 因增加7#铸机中包（4#铸机中包单独一个类型定义为4），屏蔽原语句
		//else if(csTundishType == _T("2")||csTundishType == _T("3"))//上3、4或5#铸机
		else if(csTundishType == _T("2")||csTundishType == _T("3")||csTundishType == _T("4")||csTundishType == _T("5"))//上3、4或5#铸机或7#铸机  //modify by hyh 2012-06-08 新增6#CCM
		//Modify end
		{
			CString csTemp = _T(" select * from %s where TundishID = '%s' and WorkID = '%s' ");
	
			csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csTundishID,csWorkID);
			rsResult.DeleteAll();
			if(!Query(csSQL,rsResult)||rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
			rsResult.MoveFirst();
			if(rsResult.GetRowCount() > 0)
			{
				rsResult.MoveFirst();
				CString csGuid = rsResult.GetFieldByName(_T("GUID")).ToCString();
				
				rsUseMod.AppendRecord();
				rsUseMod.SetFieldByName(_T("GUID"),CL3Variant(csGuid));
				rsUseMod.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
				rsUseMod.SetFieldByName(_T("Install_Start_Time"),CL3Variant(dtCurrentTime));
			}

			//新增上件记录
			rsTFFInstall.AppendRecord();
			rsTFFInstall.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsTFFInstall.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsTFFInstall.SetFieldByName(_T("Install_Time"),CL3Variant(dtCurrentTime));

			//修改基本信息
			rsBase.AppendRecord();
			rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsBase.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_ISTALL));
			rsBase.SetFieldByName(_T("Flag"),L3LONG(0));
		}
		
		rsData.MoveNext();
	}

	if(rsBase.GetRowCount() > 0)
	{
		rsBase.MoveFirst();
		if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
		{
			if(bUseTrans)
					Rollback(nTrans);
			return 0;
		}
	}

	if(rsOTInstall.GetRowCount() > 0)
	{
		rsOTInstall.MoveFirst();
		if(CreateNewObjects(CTUNDISH_OT_INSTALL_URI,rsOTInstall) < rsOTInstall.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
	}
	if(rsTFFInstall.GetRowCount() > 0)
	{
		rsTFFInstall.MoveFirst();
		if(CreateNewObjects(CTUNDISH_TFF_INSTALL_URI,rsTFFInstall) < rsTFFInstall.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
	}
	if(rsUse.GetRowCount() > 0)
	{
		rsUse.MoveFirst();
		if(CreateNewObjects(CTUNDISH_USE_INFO_URI,rsUse) < rsUse.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
	}
	
	if(rsUseMod.GetRowCount() > 0)
	{
		rsUseMod.MoveFirst();
		if(!SetObjsPropValues(CTUNDISH_USE_INFO_URI,rsUseMod))
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

/// <Method class="CTundish_Mag" name="TundishInstallEnd" type="L3LONG">
/// 中包上件结束
/// <Param name="dsTundish" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishInstallEnd(L3RECORDSET dsTundish)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsTundish;
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

	//创建用于设置CTundish_Base部分数据（铁包号、状态、）记录集
	CStringArray FieldNames;FieldNames.SetSize(3);
	CUIntArray FieldTypes;FieldTypes.SetSize(3);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Flag");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_LONG;

	CL3RecordSetWrap rsBase;
	if((!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csWorkID = rsData.GetFieldByName(_T("WorkID")).ToCString();

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_ISTALL));
		rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)1));

		CString csTemp = _T(" select * from %s where TundishID = '%s' and WorkID = '%s' ");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csTundishID,csWorkID);
		if(!Query(csSQL,rsResult))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
		
			if(!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Install_End_Time"),CL3Variant(dtCurrentTime)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}
		rsData.MoveNext();
	}

	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="TundishOnFireStart" type="L3LONG">
/// 
/// 中包在线烘烤开始
/// ARG &gt;&gt; rsTundishs: 要在线烘烤开始的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishOnFireStart(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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

	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	//创建用于设置CTundish_Base部分数据（）记录集[2009-03-09]
	CStringArray FieldNames;FieldNames.SetSize(5);
	CUIntArray FieldTypes;FieldTypes.SetSize(5);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Flag");
	FieldNames[3]=_T("Cast_ID");
	FieldNames[4]=_T("VehicleID");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_LONG;
	FieldTypes[3]=L3VT_STRING;
	FieldTypes[4]=L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if((!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	
	//创建用于新增CTundish_TFF_Hot_Fire部分数据（）记录集
	CStringArray TFFHotNames;TFFHotNames.SetSize(5);
	CUIntArray TFFHotTypes;TFFHotTypes.SetSize(5);

	TFFHotNames[0]=_T("TundishID");
	TFFHotNames[1]=_T("WorkID");
	TFFHotNames[2]=_T("Small_Start_Time");
	TFFHotNames[3]=_T("Cast_ID");
	TFFHotNames[4]=_T("VehicleID");

	TFFHotTypes[0]=L3VT_STRING;
	TFFHotTypes[1]=L3VT_STRING;
	TFFHotTypes[2]=L3VT_DATETIME;
	TFFHotTypes[3]=L3VT_STRING;
	TFFHotTypes[4]=L3VT_STRING;

	CL3RecordSetWrap rsTFFHot;
	if((!CreateRecordSet(TFFHotNames,TFFHotTypes,rsTFFHot)||rsTFFHot.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于新增CTundish_OT_Hot_Fire部分数据（）记录集
	CStringArray OTHotNames;OTHotNames.SetSize(5);
	CUIntArray OTHotTypes;OTHotTypes.SetSize(5);

	OTHotNames[0]=_T("TundishID");
	OTHotNames[1]=_T("WorkID");
	OTHotNames[2]=_T("Fire_Start_Time");
	OTHotNames[3]=_T("Cast_ID");
	OTHotNames[4]=_T("VehicleID");

	OTHotTypes[0]=L3VT_STRING;
	OTHotTypes[1]=L3VT_STRING;
	OTHotTypes[2]=L3VT_DATETIME;
	OTHotTypes[3]=L3VT_STRING;
	OTHotTypes[4]=L3VT_STRING;

	CL3RecordSetWrap rsOTHot;
	if((!CreateRecordSet(OTHotNames,OTHotTypes,rsOTHot)||rsOTHot.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csWorkID = rsData.GetFieldByName(_T("WorkID")).ToCString();
		CString csTundishType = rsData.GetFieldByName(_T("TundishType")).ToCString(); 
		
		//[2009-03-09]
		CString csCCMID = rsData.GetFieldByName(_T("Cast_ID")).ToCString(); 
		CString csVehicleID = rsData.GetFieldByName(_T("VehicleID")).ToCString(); 

	
		if(csWorkID == _T("")||csCCMID == _T("") || (csVehicleID !=_T("1")&& csVehicleID !=_T("2")))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//工作层编号为空，或铸机为空，或车号为空
		}
		
		//判断当前铸机当前车号上是否存在中包
		//Modify begin by llj 2011-3-15 解决中包车上只能存在一个中包号，屏蔽原语句
		/*CString csTemp = _T(" select * from %s where Cast_ID = '%s'  and VehicleID = '%s' ");
		csTemp += _T(" and Status >= '%s' and Status <= '%s'");*/
		CString csTemp = _T(" select * from %s where Cast_ID = '%s'  and VehicleID = '%s' ");
		csTemp += _T(" and (Status = '%s' or Status = '%s' or  Status = '%s')");
		//Modify end
		CString csSQL;
		CL3RecordSetWrap rsResult;

		//csSQL.Format(csTemp,CTUNDISH_BASE_URI,csCCMID,csVehicleID,CTUNDISH_STATUS_HOT_FIRE,CTUNDISH_STATUS_HOT);
		csSQL.Format(csTemp,CTUNDISH_BASE_URI,csCCMID,csVehicleID,CTUNDISH_STATUS_HOT_FIRE,CTUNDISH_STATUS_HOT,CTUNDISH_STATUS_USE);
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if (rsResult.GetRowCount() > 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//当前铸机当前车号上存在中包
		}

		//修改连铸中包号//
		CString csCCMUri = CCM_CLASS_URI + _T("\\") + csCCMID;
		CString csPositionTundishID = _T("");
		if (csVehicleID == _T("1"))//西车
			csPositionTundishID = _T("WestTundishID");
		else //东车(csVehicleID == _T("2"))
			csPositionTundishID = _T("EastTundishID");

		if(!SetObjectPropValue(csCCMUri,csPositionTundishID,CL3Variant(csTundishID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;	//设置东西中包号失败
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_HOT_FIRE));
		rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("Cast_ID"),CL3Variant(csCCMID));
		rsBase.SetFieldByName(_T("VehicleID"),CL3Variant(csVehicleID));
		
		//中包履历
		csTemp = _T(" select * from %s where WorkID = '%s' order by WorkID desc");
		csSQL = _T("");
		rsResult.DeleteAll();
		csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csWorkID);
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;	//获取中包履历信息失败
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
			if(!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Hot_Small_Start_Time"),CL3Variant(dtCurrentTime))
				||!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Cast_ID"),CL3Variant(csCCMID))
				||!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Vehicle_ID"),CL3Variant(csVehicleID)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;	//修改中包履历信息失败
			}
		}

		if(csTundishType == _T("1"))//上1、2#铸机
		{
			rsOTHot.AppendRecord();
			rsOTHot.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsOTHot.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsOTHot.SetFieldByName(_T("Fire_Start_Time"),CL3Variant(dtCurrentTime));
			rsOTHot.SetFieldByName(_T("Cast_ID"),CL3Variant(csCCMID));
			rsOTHot.SetFieldByName(_T("VehicleID"),CL3Variant(csVehicleID));
		}
		//Modify begin llj 2011-03-15 因增加7#铸机，单独产生中包类型，为4，屏蔽原语句
		//else if(csTundishType == _T("2")||csTundishType == _T("3"))//上3、4或5#铸机
		else if(csTundishType == _T("2")||csTundishType == _T("3")||csTundishType == _T("4")||csTundishType == _T("5"))//上3、4或5#铸机或7#铸机 //modify by hyh 2012-06-08 新增6#CCM
		//Modify end
		{
			rsTFFHot.AppendRecord();
			rsTFFHot.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsTFFHot.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsTFFHot.SetFieldByName(_T("Small_Start_Time"),CL3Variant(dtCurrentTime));
			rsTFFHot.SetFieldByName(_T("Cast_ID"),CL3Variant(csCCMID));
			rsTFFHot.SetFieldByName(_T("VehicleID"),CL3Variant(csVehicleID));
		}

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	if(rsOTHot.GetRowCount() > 0)
	{
		rsOTHot.MoveFirst();
		if(CreateNewObjects(CTUNDISH_OT_HOT_FIRE_URI,rsOTHot) < rsOTHot.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
	}
	if(rsTFFHot.GetRowCount() > 0)
	{
		rsTFFHot.MoveFirst();
		if(CreateNewObjects(CTUNDISH_TFF_HOT_FIRE_URI,rsTFFHot) < rsTFFHot.GetRowCount())
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

/// <Method class="CTundish_Mag" name="TundishOnFireEnd" type="L3LONG">
/// 
/// 中包在线烘烤结束
/// ARG &gt;&gt; rsTundishs: 要在线烘烤结束的中包的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishOnFireEnd(L3RECORDSET rsTundishs)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishs;
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

	//创建用于设置CTundish_Base部分数据（）记录集
	CStringArray FieldNames;FieldNames.SetSize(3);
	CUIntArray FieldTypes;FieldTypes.SetSize(3);

	FieldNames[0]=_T("TundishID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Flag");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_LONG;

	CL3RecordSetWrap rsBase;
	if((!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csWorkID = rsData.GetFieldByName(_T("WorkID")).ToCString();
		CString csTundishType = rsData.GetFieldByName(_T("TundishType")).ToCString(); 
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_HOT));
		rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)1));
		
		CString csTemp = _T(" select * from %s where TundishID = '%s' and WorkID = '%s' ");
		CString csSQL;
		CL3RecordSetWrap rsResult;
		csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csTundishID,csWorkID);
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount() > 0 )
		{
			rsResult.MoveFirst();
			CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
			if(!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Hot_Big_End_Time"),CL3Variant(dtCurrentTime)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}

		if(csTundishType == _T("1"))//上1、2#铸机
		{
			if(!SetObjectPropValue(CTUNDISH_OT_HOT_FIRE_URI + _T("\\") + csWorkID,_T("Fire_End_Time"),CL3Variant(dtCurrentTime)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}
		//Modify begin llj 2011-03-15 因增加7#铸机使用新类别的中包，类型为4，屏蔽原语句
		//else if(csTundishType == _T("2")||csTundishType == _T("3"))//上3、4、5#铸机
		else if(csTundishType == _T("2")||csTundishType == _T("3")||csTundishType == _T("4")||csTundishType == _T("5"))//上3、4、5、7#铸机    //modify by hyh 2012-06-08 新增6#CCM
		//Modify end
		{
			if(!SetObjectPropValue(CTUNDISH_TFF_HOT_FIRE_URI + _T("\\") + csWorkID,_T("Big_End_Time"),CL3Variant(dtCurrentTime)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="InsertTundishInnerBuildInfo" type="L3LONG">
/// 
/// 添加中包永久层砌筑信息
/// ARG &gt;&gt; rsTundishInnerBuilds: 要添加的中包永久层打结的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInnerBuilds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::InsertTundishInnerBuildInfo(L3RECORDSET rsTundishInnerBuilds)
{
	// TODO : 请在此添加逻辑代码
	 CL3RecordSetWrap rsData = rsTundishInnerBuilds;
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
	//创建用于设置CTundish_Base部分数据（主键、耐材）记录集
	CStringArray FieldNames; FieldNames.SetSize(2);
	CUIntArray FieldTypes; FieldTypes.SetSize(2);
	FieldNames[0] = _T("TundishID");
	FieldNames[1] = _T("Refra_Pro");

	FieldTypes[0] = L3VT_STRING;
	FieldTypes[1] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if (!CreateRecordSet(FieldNames,FieldTypes,rsBase)|| rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));

		//获取中包号
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		//耐材厂家
		CString RefraPro =  rsData.GetFieldByName(_T("Refra_Fac")).ToCString();

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
		rsBase.SetFieldByName(_T("Refra_Pro"),CL3Variant(RefraPro));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CTUNDISH_INNER_BUILD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="UpdateTundishInnerBuildInfo" type="L3LONG">
/// 
/// 修改中包永久层砌筑信息
/// ARG &gt;&gt; rsTundishInnerBuilds: 要修改的中包永久层打结的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInnerBuilds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::UpdateTundishInnerBuildInfo(L3RECORDSET rsTundishInnerBuilds)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsTundishInnerBuilds, CTUNDISH_INNER_BUILD_URI);
}

/// <Method class="CTundish_Mag" name="DeleteTundishInnerBuildInfo" type="L3LONG">
/// 
/// 删除中包永久层砌筑信息
/// ARG &gt;&gt; rsTundishInnerBuilds: 要删除的中包永久层打结的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInnerBuilds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::DeleteTundishInnerBuildInfo(L3RECORDSET rsTundishInnerBuilds)
{
	// TODO : 请在此添加逻辑代码
	return  DeleteInfos(rsTundishInnerBuilds, CTUNDISH_INNER_BUILD_URI);
}

/// <Method class="CTundish_Mag" name="GetTundishInnerBuildInfo" type="L3RECORDSET">
/// 
/// 获取中包永久层砌筑信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回reTundishInnerBuildInfos；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetTundishInnerBuildInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CTUNDISH_INNER_BUILD_URI, strCondition);
}

/// <Method class="CTundish_Mag" name="InsertTundishInnerFireInfo" type="L3LONG">
/// 
/// 添加中包永久层烘烤信息
/// ARG &gt;&gt; rsTundishInnerFires: 要添加的中包永久层烘烤的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInnerFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::InsertTundishInnerFireInfo(L3RECORDSET rsTundishInnerFires)
{
	// TODO : 请在此添加逻辑代码
	 CL3RecordSetWrap rsData = rsTundishInnerFires;
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CTUNDISH_INNER_FIRE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="UpdateTundishInnerFireInfo" type="L3LONG">
/// 
/// 修改中包永久层烘烤信息
/// ARG &gt;&gt; rsTundishInnerFires: 要修改的中包永久层烘烤的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInnerFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::UpdateTundishInnerFireInfo(L3RECORDSET rsTundishInnerFires)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsTundishInnerFires, CTUNDISH_INNER_FIRE_URI);
}

/// <Method class="CTundish_Mag" name="DeleteTundishInnerFireInfo" type="L3LONG">
/// 
/// 删除中包永久层烘烤信息
/// ARG &gt;&gt; rsTundishInnerFires: 要删除的中包永久层烘烤的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInnerFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::DeleteTundishInnerFireInfo(L3RECORDSET rsTundishInnerFires)
{
	// TODO : 请在此添加逻辑代码
	return  DeleteInfos(rsTundishInnerFires, CTUNDISH_INNER_FIRE_URI);
}

/// <Method class="CTundish_Mag" name="GetTundishInnerFireInfo" type="L3RECORDSET">
/// 
/// 获取中包永久层烘烤信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回reTundishInnerFireInfos；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetTundishInnerFireInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CTUNDISH_INNER_FIRE_URI, strCondition);
}

/// <Method class="CTundish_Mag" name="InsertTundishWorkBuildInfo" type="L3LONG">
/// 
/// 添加中包工作层砌筑信息
/// ARG &gt;&gt; rsTundishWorkBuilds: 要添加的中包工作层打结的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishWorkBuilds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::InsertTundishWorkBuildInfo(L3RECORDSET rsTundishWorkBuilds)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishWorkBuilds;
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CTUNDISH_DAUB_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="UpdateTundishWorkBuildInfo" type="L3LONG">
/// 
/// 修改中包工作层砌筑信息
/// ARG &gt;&gt; rsTundishWorkBuilds: 要修改的中包工作层打结的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishWorkBuilds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::UpdateTundishWorkBuildInfo(L3RECORDSET rsTundishWorkBuilds)
{
	// TODO : 请在此添加逻辑代码
	return UpdateInfos(rsTundishWorkBuilds, CTUNDISH_DAUB_URI);
}

/// <Method class="CTundish_Mag" name="DeleteTundishWorkBuildInfo" type="L3LONG">
/// 
/// 删除中包工作层砌筑信息
/// ARG &gt;&gt; rsTundishWorkBuilds: 要删除的中包工作层打结的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishWorkBuilds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::DeleteTundishWorkBuildInfo(L3RECORDSET rsTundishWorkBuilds)
{
	// TODO : 请在此添加逻辑代码
	return  DeleteInfos(rsTundishWorkBuilds, CTUNDISH_DAUB_URI);
}

/// <Method class="CTundish_Mag" name="GetTundishWorkBuildInfo" type="L3RECORDSET">
/// 
/// 获取中包工作层砌筑信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsTundishWorkBuilds；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetTundishWorkBuildInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CTUNDISH_DAUB_URI, strCondition);
}

/// <Method class="CTundish_Mag" name="InsertTundishOTHotFireInfo" type="L3LONG">
/// 
/// 添加1、2#铸机中包调整及热备烘烤信息
/// ARG &gt;&gt; rsTundishHotFires: 要添加的中包烘烤的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::InsertTundishOTHotFireInfo(L3RECORDSET rsTundishHotFires)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishHotFires;
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CTUNDISH_OT_HOT_FIRE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="UpdateTundishOTHotFireInfo" type="L3LONG">
/// 
/// 修改1、2#铸机中包调整及热备烘烤信息
/// ARG &gt;&gt; rsTundishHotFires: 要修改的中包烘烤的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::UpdateTundishOTHotFireInfo(L3RECORDSET rsTundishHotFires)
{
	// TODO : 请在此添加逻辑代码
	return  UpdateInfos(rsTundishHotFires, CTUNDISH_OT_HOT_FIRE_URI);
}

/// <Method class="CTundish_Mag" name="DeleteTundishOTHotFireInfo" type="L3LONG">
/// 
/// 删除1、2#铸机中包调整及热备烘烤信息
/// ARG &gt;&gt; rsTundishHotFires: 要删除的中包烘烤的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::DeleteTundishOTHotFireInfo(L3RECORDSET rsTundishHotFires)
{
	// TODO : 请在此添加逻辑代码
	return  DeleteInfos(rsTundishHotFires, CTUNDISH_OT_HOT_FIRE_URI);
}

/// <Method class="CTundish_Mag" name="GetTundishOTHotFireInfo" type="L3RECORDSET">
/// 
/// 获取1、2#铸机中包调整及热备烘烤信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsTundishOTHotFires；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetTundishOTHotFireInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CTUNDISH_OT_HOT_FIRE_URI, strCondition);
}

/// <Method class="CTundish_Mag" name="InsertTundishTFFHotFireInfo" type="L3LONG">
/// 
/// 添加3、4、5#铸机中包热备烘烤信息
/// ARG &gt;&gt; rsTundishHotFires: 要添加的中包烘烤的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::InsertTundishTFFHotFireInfo(L3RECORDSET rsTundishHotFires)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishHotFires;
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CTUNDISH_TFF_HOT_FIRE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="UpdateTundishTFFHotFireInfo" type="L3LONG">
/// 
/// 修改3、4、5#铸机中包热备烘烤信息
/// ARG &gt;&gt; rsTundishHotFires: 要修改的中包烘烤的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::UpdateTundishTFFHotFireInfo(L3RECORDSET rsTundishHotFires)
{
	// TODO : 请在此添加逻辑代码
	return  UpdateInfos(rsTundishHotFires, CTUNDISH_TFF_HOT_FIRE_URI);
}

/// <Method class="CTundish_Mag" name="DeleteTundishTFFHotFireInfo" type="L3LONG">
/// 
/// 删除3、4、5#铸机中包热备烘烤信息
/// ARG &gt;&gt; rsTundishHotFires: 要删除的中包烘烤的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::DeleteTundishTFFHotFireInfo(L3RECORDSET rsTundishHotFires)
{
	// TODO : 请在此添加逻辑代码
	return  DeleteInfos(rsTundishHotFires, CTUNDISH_TFF_HOT_FIRE_URI);
}

/// <Method class="CTundish_Mag" name="GetTundishTFFHotFireInfo" type="L3RECORDSET">
/// 
/// 获取3、4、5#铸机中包烘烤信息
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsTundishTFFHotFires；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetTundishTFFHotFireInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CTUNDISH_TFF_HOT_FIRE_URI, strCondition);
}

/// <Method class="CTundish_Mag" name="InsertTundishOTInstallInfo" type="L3LONG">
/// 
/// 添加1、2#铸机中包上件实绩
/// ARG &gt;&gt; rsTundishInstalls: 要添加的中包上件的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::InsertTundishOTInstallInfo(L3RECORDSET rsTundishInstalls)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishInstalls;
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CTUNDISH_OT_INSTALL_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="UpdateTundishOTInstallInfo" type="L3LONG">
/// 
/// 修改1、2#铸机中包上件实绩
/// ARG &gt;&gt; rsTundishInstalls: 要修改的中包上件的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::UpdateTundishOTInstallInfo(L3RECORDSET rsTundishInstalls)
{
	// TODO : 请在此添加逻辑代码
	return  UpdateInfos(rsTundishInstalls, CTUNDISH_OT_INSTALL_URI);
}

/// <Method class="CTundish_Mag" name="DeleteTundishOTInstallInfo" type="L3LONG">
/// 
/// 删除1、2#铸机中包上件实绩
/// ARG &gt;&gt; rsTundishInstalls: 要删除的中包上件的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::DeleteTundishOTInstallInfo(L3RECORDSET rsTundishInstalls)
{
	// TODO : 请在此添加逻辑代码
	return  DeleteInfos(rsTundishInstalls, CTUNDISH_OT_INSTALL_URI);
}

/// <Method class="CTundish_Mag" name="GetTundishOTInstallInfo" type="L3RECORDSET">
/// 
/// 获取1、2#铸机中包上件实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsTundishOTInstalls；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetTundishOTInstallInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CTUNDISH_OT_INSTALL_URI, strCondition);
}

/// <Method class="CTundish_Mag" name="InsertTundishTFFInstallInfo" type="L3LONG">
/// 
/// 添加3、4、5#铸机中包上件实绩
/// ARG &gt;&gt; rsTundishInstalls: 要添加的中包上件的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::InsertTundishTFFInstallInfo(L3RECORDSET rsTundishInstalls)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishInstalls;
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CTUNDISH_TFF_INSTALL_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="UpdateTundishTFFInstallInfo" type="L3LONG">
/// 
/// 修改3、4、5#铸机中包上件实绩
/// ARG &gt;&gt; rsTundishInstalls: 要修改的中包上件的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::UpdateTundishTFFInstallInfo(L3RECORDSET rsTundishInstalls)
{
	// TODO : 请在此添加逻辑代码
	return  UpdateInfos(rsTundishInstalls, CTUNDISH_TFF_INSTALL_URI);
}

/// <Method class="CTundish_Mag" name="DeleteTundishTFFInstallInfo" type="L3LONG">
/// 
/// 删除3、4、5#铸机中包上件实绩
/// ARG &gt;&gt; rsTundishInstalls: 要删除的中包上件的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::DeleteTundishTFFInstallInfo(L3RECORDSET rsTundishInstalls)
{
	// TODO : 请在此添加逻辑代码
	return  DeleteInfos(rsTundishInstalls, CTUNDISH_TFF_INSTALL_URI);
}

/// <Method class="CTundish_Mag" name="GetTundishTFFInstallInfo" type="L3RECORDSET">
/// 
/// 获取3、4、5#铸机中包上件实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsTundishOTInstalls；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetTundishTFFInstallInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CTUNDISH_TFF_INSTALL_URI, strCondition);
}

/// <Method class="CTundish_Mag" name="InsertTundishOTRefraUseInfo" type="L3LONG">
/// 
/// 添加1、2#铸机中包耐材使用实绩
/// ARG &gt;&gt; rsTundishRefraUses: 要添加的中包耐材使用的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::InsertTundishOTRefraUseInfo(L3RECORDSET rsTundishRefraUses)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishRefraUses;
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!CreateNewObjects(CTUNDISH_OT_REFRA_USE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="UpdateTundishOTRefraUseInfo" type="L3LONG">
/// 
/// 修改1、2#铸机中包耐材使用实绩
/// ARG &gt;&gt; rsTundishRefraUses: 要修改的中包耐材使用的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::UpdateTundishOTRefraUseInfo(L3RECORDSET rsTundishRefraUses)
{
	// TODO : 请在此添加逻辑代码
	return  UpdateInfos(rsTundishRefraUses, CTUNDISH_OT_REFRA_USE_URI);
}

/// <Method class="CTundish_Mag" name="DeleteTundishOTRefraUseInfo" type="L3LONG">
/// 
/// 删除1、2#铸机中包耐材使用实绩
/// ARG &gt;&gt; rsTundishRefraUses: 要删除的中包耐材使用的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::DeleteTundishOTRefraUseInfo(L3RECORDSET rsTundishRefraUses)
{
	// TODO : 请在此添加逻辑代码
	return  DeleteInfos(rsTundishRefraUses, CTUNDISH_OT_REFRA_USE_URI);
}

/// <Method class="CTundish_Mag" name="GetTundishOTRefraUseInfo" type="L3RECORDSET">
/// 
/// 获取1、2#铸机中包耐材使用实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsTundishRefraUses；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetTundishOTRefraUseInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CTUNDISH_OT_REFRA_USE_URI, strCondition);
}

/// <Method class="CTundish_Mag" name="InsertTundishTTFRefraUseInfo" type="L3LONG">
/// 
/// 添加3、4、5#铸机中包耐材使用实绩
/// ARG &gt;&gt; rsTundishRefraUses: 要添加的中包耐材使用的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::InsertTundishTTFRefraUseInfo(L3RECORDSET rsTundishRefraUses)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundishRefraUses;
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
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!CreateNewObjects(CTUNDISH_TFF_REFRA_USE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="UpdateTundishTTFRefraUseInfo" type="L3LONG">
/// 
/// 修改3、4、5#铸机中包耐材使用实绩
/// ARG &gt;&gt; rsTundishRefraUses: 要修改的中包耐材使用的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::UpdateTundishTTFRefraUseInfo(L3RECORDSET rsTundishRefraUses)
{
	// TODO : 请在此添加逻辑代码
	return  UpdateInfos(rsTundishRefraUses, CTUNDISH_TFF_REFRA_USE_URI);
}

/// <Method class="CTundish_Mag" name="DeleteTundishTTFRefraUseInfo" type="L3LONG">
/// 
/// 删除3、4、5#铸机中包耐材使用实绩
/// ARG &gt;&gt; rsTundishRefraUses: 要删除的中包耐材使用的记录集。必须包含TundishID字段。
/// RET &lt;&lt; 成功返回1；失败返回0。
/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::DeleteTundishTTFRefraUseInfo(L3RECORDSET rsTundishRefraUses)
{
	// TODO : 请在此添加逻辑代码
	return  DeleteInfos(rsTundishRefraUses, CTUNDISH_TFF_REFRA_USE_URI);
}

/// <Method class="CTundish_Mag" name="GetTundishTTFRefraUseInfo" type="L3RECORDSET">
/// 
/// 获取3、4、5#铸机中包耐材使用实绩
/// ARG &gt;&gt; strCondition: 查询条件
/// RET &lt;&lt; 成功返回rsTundishRefraUses；失败返回null。
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetTundishTTFRefraUseInfo(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	return GetInfos(CTUNDISH_TFF_REFRA_USE_URI, strCondition);
}


/// <Method class="CTundish_Mag" name="GetAllHotTundish" type="L3RECORDSET">
/// 获取中包状态为热备中包(可用中包)
/// </Method>
L3RECORDSET CTundish_Mag::GetAllHotTundish()
{
	// TODO : 请在此添加逻辑代码
	CString csTemp = _T(" select TundishID from %s where Status = '%s' order by TundishID ");
	CString csSQL;
	csSQL.Format(csTemp,CTUNDISH_BASE_URI,CTUNDISH_STATUS_HOT);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;
	
	return rsResult.Detach();
}

/// <Method class="CTundish_Mag" name="SetTundishNO" type="L3LONG">
/// 设置中包包次号
/// <Param name="TundishID" type="L3STRING">中包号</Param>
/// <Param name="TundishNO" type="L3STRING">包次号</Param>
/// </Method>
L3LONG CTundish_Mag::SetTundishNO(L3STRING TundishID, L3STRING TundishNO)
{
	// TODO : 请在此添加逻辑代码
	return 0;
}

/// <Method class="CTundish_Mag" name="TundishOnLine" type="L3LONG">
/// 中包上线
/// <Param name="TundishID" type="L3STRING">中包号</Param>
/// <Param name="TundishNO" type="L3STRING">包次号</Param>
/// <Param name="dtOnLine" type="L3DATETIME">中包换上时间</Param>
/// </Method>
L3LONG CTundish_Mag::TundishOnLine(L3STRING TundishID, L3STRING TundishNO,L3DATETIME dtOnLine)
{
	//在中包履历中加入中包包次号
	CString csTundishID = TundishID;
	CString csTundishNO = TundishNO;
	if(csTundishID == _T("")||csTundishNO == _T(""))
	{
		return 0;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
		{
			return 0;
		}
	}
	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	//COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	//创建用于修改中包状态的记录集，包括()
	CStringArray BaseNames;BaseNames.SetSize(4);
	CUIntArray BaseTypes;BaseTypes.SetSize(4);

	BaseNames[0] = _T("TundishID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("Flag");
	BaseNames[3] = _T("TundishNO");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_LONG;
	BaseTypes[3] = L3VT_STRING;//20081229Liao

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于修改中包履历表的记录集，包括(GUID,永久层烘烤开始时间)
	CStringArray UseNames;UseNames.SetSize(3);
	CUIntArray UseTypes;UseTypes.SetSize(3);

	UseNames[0] = _T("GUID");
	UseNames[1] = _T("Cast_Start_Time");
	UseNames[2] = _T("TundishNO");

	UseTypes[0] = L3VT_STRING;
	UseTypes[1] = L3VT_DATETIME;
	UseTypes[2] = L3VT_STRING;

	CL3RecordSetWrap rsUse;
	if(!CreateRecordSet(UseNames,UseTypes,rsUse)||rsUse.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsBase.AppendRecord();
	rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
	rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_USE));
	rsBase.SetFieldByName(_T("TundishNO"),CL3Variant(csTundishNO));
	rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)0));

	CString csTemp = _T(" select * from %s where TundishID ='%s' and TundishNO is null order by WorkID desc");
	CString csSQL;
	csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csTundishID);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;

	}
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
		rsUse.AppendRecord();
		rsUse.SetFieldByName(_T("GUID"),CL3Variant(csGUID));
		rsUse.SetFieldByName(_T("Cast_Start_Time"),CL3Variant(dtOnLine));
		rsUse.SetFieldByName(_T("TundishNO"),CL3Variant(csTundishNO));
	}
	
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	rsUse.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_USE_INFO_URI,rsUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CTundish_Mag" name="TundishOffLine" type="L3LONG">
/// 中包下线()
/// <Param name="TundishID" type="L3STRING">中包号</Param>
/// <Param name="TundishNO" type="L3STRING">包次号</Param>
/// <Param name="dtOffLine" type="L3DATETIME">中包换下时间</Param>
/// </Method>
L3LONG CTundish_Mag::TundishOffLine(L3STRING TundishID, L3STRING TundishNO,L3DATETIME dtOffLine)
{
	// TODO : 请在此添加逻辑代码
	CString csTundishID = TundishID;
	CString csTundishNO = TundishNO;

	if(csTundishID == _T("")|| csTundishNO == _T(""))
		return -1;

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
	//COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	//创建用于修改中包状态的记录集[20081229Liao]
	CStringArray BaseNames;BaseNames.SetSize(5);
	CUIntArray BaseTypes;BaseTypes.SetSize(5);

	BaseNames[0] = _T("TundishID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("Flag");
	BaseNames[3] = _T("TundishNO");
	BaseNames[4] = _T("Cast_ID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_LONG;
	BaseTypes[3] = L3VT_STRING;
	BaseTypes[4] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsBase.AppendRecord();
	rsBase.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
	rsBase.SetFieldByName(_T("Status"),CL3Variant(CTUNDISH_STATUS_OFFLINE));
	rsBase.SetFieldByName(_T("Flag"),CL3Variant((L3LONG)1));
	rsBase.SetFieldByName(_T("TundishNO"),CL3Variant(_T("")));
	rsBase.SetFieldByName(_T("Cast_ID"),CL3Variant(_T("")));

	rsBase.MoveFirst();
	if(!SetObjsPropValues(CTUNDISH_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//创建用于修改中包履历表的记录集
	CStringArray UseNames;UseNames.SetSize(2);
	CUIntArray UseTypes;UseTypes.SetSize(2);

	UseNames[0] = _T("GUID");
	UseNames[1] = _T("Cast_End_Time");

	UseTypes[0] = L3VT_STRING;
	UseTypes[1] = L3VT_DATETIME;

	CL3RecordSetWrap rsUse;
	if(!CreateRecordSet(UseNames,UseTypes,rsUse)||rsUse.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	CString csTemp = _T(" select * from %s where TundishNO = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csTundishNO);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;

	}
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
		rsUse.AppendRecord();
		rsUse.SetFieldByName(_T("GUID"),CL3Variant(csGUID));
		rsUse.SetFieldByName(_T("Cast_End_Time"),CL3Variant(dtOffLine));

		rsUse.MoveFirst();
		if(!SetObjsPropValues(CTUNDISH_USE_INFO_URI,rsUse))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
	}
	
	csTemp = _T(" select treatNo from (select treatNo from %s where TundishNo = '%s' order by treatNo desc) where rownum < 2");
	csSQL.Format(csTemp,CCM_PROCESS_DATA_CLASS_URI,csTundishNO);
	rsResult.DeleteAll();
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;

	}
	CString csTreatNo;
	CString csHeadFurnace;
	if(rsResult.GetRowCount() > 0)
	{
		rsResult.MoveFirst();
		csTreatNo = rsResult.GetFieldByName(_T("TreatNo")).ToCString();
		if(!csTreatNo.IsEmpty())
			csHeadFurnace = GetObjectPropValue(CCM_BASE_DATA_CLASS_URI + _T("\\") + csTreatNo,_T("HeadFurnace")).ToCString();
	}

	//获取中包类型
	CString csTundishType = GetObjectPropValue(CTUNDISH_BASE_URI + _T("\\") + csTundishID,_T("TundishType")).ToCString();
	
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	
	//1、2铸机中包
	if(csTundishType == _T("1"))
	{
		csTemp = _T(" select * from %s where TundishNO = '%s' ");
		csSQL.Format(csTemp,CTUNDISH_OT_REFRA_USE_URI,csTundishNO);
		rsResult.DeleteAll ();
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if(rsResult.GetRowCount() < 1)//如果对应包次不存在耐材使用实绩
		{
			//创建用于新增中包耐材使用情况的记录集
			CL3RecordSetWrap rsOTRefraUse;
			if(!CreateClassPropSet(CTUNDISH_OT_REFRA_USE_URI,rsOTRefraUse))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			
			rsOTRefraUse.AppendRecord();

			rsOTRefraUse.SetFieldByName(_T("Input_Time"),CL3Variant(dtOffLine));
			rsOTRefraUse.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsOTRefraUse.SetFieldByName(_T("Cover_Use_Case"),CL3Variant(_T("0")));
			rsOTRefraUse.SetFieldByName(_T("Protect_Use_Case"),CL3Variant(_T("0")));
			rsOTRefraUse.SetFieldByName(_T("Daub_Use_Case"),CL3Variant(_T("0")));
			rsOTRefraUse.SetFieldByName(_T("Tranq_Case"),CL3Variant(_T("0")));
			rsOTRefraUse.SetFieldByName(_T("TundishNO"),CL3Variant(csTundishNO));
			rsOTRefraUse.SetFieldByName(_T("Stop_Cast_Reason"),CL3Variant(_T("0")));

			rsOTRefraUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsOTRefraUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsOTRefraUse.SetFieldByName(_T("Operator"),CL3Variant(csHeadFurnace));

			rsOTRefraUse.MoveFirst();
			if(CreateNewObjects(CTUNDISH_OT_REFRA_USE_URI,rsOTRefraUse) < rsOTRefraUse.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
		}
	}
	//3、4、5#铸机中包
	//Modify begin by llj 2011-03-15 因增加7#铸机使用新的中包类型，型号为4 屏蔽原语句
	//else if (csTundishType == _T("2") || csTundishType == _T("3"))
	else if (csTundishType == _T("2") || csTundishType == _T("3")|| csTundishType == _T("4")|| csTundishType == _T("5"))               //modify by hyh 2012-06-08 新增6#CCM
	//Modify end
	{
		csTemp = _T(" select * from %s where TundishNO = '%s' ");
		csSQL.Format(csTemp,CTUNDISH_TFF_REFRA_USE_URI,csTundishNO);
		rsResult.DeleteAll ();
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}

		if(rsResult.GetRowCount() < 1)
		{	
			CL3RecordSetWrap rsTFFRefraUse;
			if(!CreateClassPropSet(CTUNDISH_TFF_REFRA_USE_URI,rsTFFRefraUse))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}

			rsTFFRefraUse.AppendRecord();
			rsTFFRefraUse.SetFieldByName(_T("Input_Time"),CL3Variant(dtOffLine));
			rsTFFRefraUse.SetFieldByName(_T("TundishID"),CL3Variant(csTundishID));
			rsTFFRefraUse.SetFieldByName(_T("TundishNO"),CL3Variant(csTundishNO));
			rsTFFRefraUse.SetFieldByName(_T("Daub_Use_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Tranq_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Frist_Tuck_Stick_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Sec_Tuck_Stick_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Thr_Tuck_Stick_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("For_Tuck_Stick_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Frist_Water_Gap_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Sec_Water_Gap_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Thr_Water_Gap_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("For_Water_Gap_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Ward_Dregs_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Cover_Use_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Protect_Use_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Pro_Temp_Use_Case"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("Stop_Cast_Reason"),CL3Variant(_T("0")));
			rsTFFRefraUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsTFFRefraUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsTFFRefraUse.SetFieldByName(_T("Operator"),CL3Variant(csHeadFurnace));

			rsTFFRefraUse.MoveFirst();
			if(CreateNewObjects(CTUNDISH_TFF_REFRA_USE_URI,rsTFFRefraUse) < rsTFFRefraUse.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
		}
	}

	//2009-03-30 Liao 
	//修改包次数据包次结束时间
	CString csCCMTundishDataUri = CCM_TUNDISH_DATA_CLASS_URI + _T("\\") + csTundishNO;
	COleDateTime dtCastingStopTime = GetObjectPropValue(csCCMTundishDataUri,_T("Casting_Stop_Time")).ToDateTime();
	CString csCastingStopTime  = dtCastingStopTime.Format(_T("%Y"));
	if(csCastingStopTime == _T("1899"))
		SetObjectPropValue(csCCMTundishDataUri,_T("Casting_Stop_Time"),CL3Variant(dtOffLine));

	CString csCCMID = _T("S6") + (csTundishNO.Left(2)).Right(1);//铸机号
	CString csCCMUnitUri = CCM_CLASS_URI + _T("\\") + csCCMID;//
	//CString csLastHeatID =  GetObjectPropValue(csCCMTundishDataUri,_T("Last_HeatID")).ToCString();
	
	/******************************计算铸机耐材寿命**************************************/
	L3STRING strCCMID = csCCMID.AllocSysString();
	CString csReasonSmooth = _T("6");//固定为"停浇"
	L3STRING strReasonSmooth = csReasonSmooth.AllocSysString();
	//计算滑块寿命
	for(int i = 1; i < 5 ; i++)
	{
		CL3Variant valRet =  InvokeObjectMethod(csCCMUnitUri,_T("CalculateEquipmentLife"),L3LONG(1),strCCMID,L3LONG(i),strReasonSmooth);

		if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
		{
			L3SysFreeString(strCCMID);
			L3SysFreeString(strReasonSmooth);

			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
	}
	//计算中包水口寿命	L3SysFreeString(strHeatID);
	CString csReasonMidGap = _T("5");//固定为"停浇"
	L3STRING strReasonMidGap = csReasonMidGap.AllocSysString();
	for(int i = 1; i < 5 ; i++)
	{
		CL3Variant valRet =  InvokeObjectMethod(csCCMUnitUri,_T("CalculateEquipmentLife"),L3LONG(2),strCCMID,L3LONG(i),strReasonMidGap);
		if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
		{
			L3SysFreeString(strCCMID);
			L3SysFreeString(strReasonSmooth);
			L3SysFreeString(strReasonMidGap);
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
	}
	//计算大包水口寿命
	CString csReasonBigGap = _T("5");//固定为"停浇"
	L3STRING strReasonBigGap = csReasonBigGap.AllocSysString();
	
	CL3Variant valRet =  InvokeObjectMethod(csCCMUnitUri,_T("CalculateEquipmentLife"),L3LONG(3),strCCMID,L3LONG(0),strReasonBigGap);
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
	{
		L3SysFreeString(strCCMID);
		L3SysFreeString(strReasonSmooth);
		L3SysFreeString(strReasonMidGap);
		L3SysFreeString(strReasonBigGap);
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	L3SysFreeString(strCCMID);
	L3SysFreeString(strReasonSmooth);
	L3SysFreeString(strReasonMidGap);
	L3SysFreeString(strReasonBigGap);

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="GetEnableInnerIDorWorkID" type="L3RECORDSET">
/// 根据中包号和获取类型获取有中包履历但没有实绩的永久层编号或则工作层编号
/// <Param name="strTundishID" type="L3STRING">中包号</Param>
/// <Param name="strType" type="L3STRING">获取类型</Param>
/// </Method>
L3RECORDSET CTundish_Mag::GetEnableInnerIDorWorkID(L3STRING strTundishID, L3STRING strType)
{
	// TODO : 请在此添加逻辑代码
	CString csTundishID = strTundishID;
	CString csType = strType;
	if(csType == _T("")||csTundishID == _T(""))
		return NULL;

	CString csCode;//查询代码
	CString csUseUri = CTUNDISH_USE_INFO_URI;//履历URI
	CString csInfoUri;//实绩URI
	
	if(csType == CTUNDISH_GET_TYPE_INNER_TIE)
	{
		csCode = _T("InnerID");
		csInfoUri = CTUNDISH_INNER_BUILD_URI;
	}
	else if(csType == CTUNDISH_GET_TYPE_INNER_FIRE)
	{
		csCode = _T("InnerID");
		csInfoUri = CTUNDISH_INNER_FIRE_URI;
	}
	else if(csType == CTUNDISH_GET_TYPE_WORK_TIE)
	{
		csCode = _T("WorkID");
		csInfoUri = CTUNDISH_DAUB_URI;
	}
	else if(csType == CTUNDISH_GET_TYPE_OT_HOT_FIRE)
	{
		csCode = _T("WorkID");
		csInfoUri = CTUNDISH_OT_HOT_FIRE_URI;
	}
	else if(csType == CTUNDISH_GET_TYPE_TFF_HOT_FIRE)
	{
		csCode = _T("WorkID");
		csInfoUri =	CTUNDISH_TFF_HOT_FIRE_URI;
	}
	else
		return NULL;

	CString csTemp;
	CString csSQL;
	CL3RecordSetWrap rsResult;
	csTemp = _T(" select distinct %s from %s where Tundish_Id = '%s' ");
	csTemp += _T("and %s not in (select %s from %s) order by %s");
	csSQL.Format(csTemp,csCode,csUseUri,csTundishID,csCode,csCode,csInfoUri,csCode);
	if(!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;

	return rsResult.Detach();
}

/// <Method class="CTundish_Mag" name="TundishDirectCold" type="L3LONG">
/// 中包直接冷备
/// <Param name="dsTundishs" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishDirectCold(L3RECORDSET dsTundishs)
{
	// TODO : 请在此添加逻辑代码

	CL3RecordSetWrap rsData = dsTundishs;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans <1)
			return 0;
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		if(!SetObjectPropValue(CTUNDISH_BASE_URI + _T("\\") + csTundishID,_T("Status"),CL3Variant(CTUNDISH_STATUS_COLD)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="TundishDireCCMID" type="L3LONG">
/// 给状态为热备烘烤和热备的中包指定去向
/// <Param name="strTundishID" type="L3STRING">中包号</Param>
/// <Param name="strCCMID" type="L3STRING"></Param>
/// </Method>
L3LONG CTundish_Mag::TundishDireCCMID(L3STRING strTundishID, L3STRING strCCMID)
{
	// TODO : 请在此添加逻辑代码
	CString csTundishID = strTundishID;
	CString csCCMID = strCCMID;
	if( csTundishID == _T("") || csCCMID == _T(""))
		return 0;	
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans <1)
			return 0;
	}

	CString csURI = CTUNDISH_BASE_URI + _T("\\") + csTundishID;
	CString csStatus = GetObjectPropValue(csURI,_T("Status")).ToCString();
	CString csWorkID = GetObjectPropValue(csURI,_T("WorkID")).ToCString();
	if(csStatus == CTUNDISH_STATUS_HOT_FIRE || csStatus == CTUNDISH_STATUS_HOT)
	{
		if(csCCMID != _T("0"))
		{
			CString csTemp=_T(" select * from %s where Cast_ID = '%s' and Status = '%s'");
			CString csSQL;
			csSQL.Format(csTemp,CTUNDISH_BASE_URI,csCCMID,CTUNDISH_STATUS_HOT);
			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult)||rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			if(rsResult.GetRowCount() > 0)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -1;
			}
		}
		else
			csCCMID = _T("");

		if (!SetObjectPropValue(csURI,_T("Cast_ID"),CL3Variant(csCCMID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}

		if(csWorkID != _T(""))
		{
			CString csTemp=_T(" select * from %s where WorkID = '%s' ");
			CString csSQL;
			csSQL.Format(csTemp,CTUNDISH_USE_INFO_URI,csWorkID);
			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult)||rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			if(rsResult.GetRowCount() > 0)
			{
				rsResult.MoveFirst();
				CString csGUID = rsResult.GetFieldByName(_T("GUID")).ToCString();
				if (!SetObjectPropValue(CTUNDISH_USE_INFO_URI + _T("\\") + csGUID,_T("Cast_ID"),CL3Variant(csCCMID)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
			}
		}

	}
	else
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CTundish_Mag" name="TundishOffLineException" type="L3LONG">
/// 中包异常下线[只对状态为"使用"以前的中包]
/// <Param name="rsTundish" type="L3RECORDSET">异常下线的记录</Param>
/// </Method>
L3LONG CTundish_Mag::TundishOffLineException(L3RECORDSET rsTundish)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = rsTundish;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;
	if(rsData.GetFieldIndex(_T("TundishID")) < 0 || rsData.GetFieldIndex(_T("Status")) < 0 
		|| rsData.GetFieldIndex(_T("VehicleID")) < 0 ||  rsData.GetFieldIndex(_T("Cast_ID")) < 0  )
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
		CString csTundishID = rsData.GetFieldByName(_T("TundishID")).ToCString();
		CString csStatus = rsData.GetFieldByName(_T("Status")).ToCString();
		CString csBaseUri = CTUNDISH_BASE_URI + _T("\\") + csTundishID;

		if(csTundishID == _T("") || csStatus == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//没有中包号或状态
		}
	
		if(csStatus == CTUNDISH_STATUS_USE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//在用中包不能异常下线
		}
		//热备烘烤或热备中包下线
		if( csStatus == CTUNDISH_STATUS_HOT_FIRE || csStatus == CTUNDISH_STATUS_HOT)
		{	
			//车号，铸机号
			CString csVehicleID = rsData.GetFieldByName(_T("VehicleID")).ToCString();
			CString csCCMID = rsData.GetFieldByName(_T("Cast_ID")).ToCString();
			if(csVehicleID != _T("") && csCCMID != _T(""))
			{
				//修改连铸中包号//
				CString csCCMUri = CCM_CLASS_URI + _T("\\") + csCCMID;
				CString csPositionTundishID = _T("");
				if (csVehicleID == _T("1"))//西车
					csPositionTundishID = _T("WestTundishID");
				else //东车(csVehicleID == _T("2"))
					csPositionTundishID = _T("EastTundishID");

				SetObjectPropValue(csCCMUri,csPositionTundishID,CL3Variant(_T("")));
			}
		}
		SetObjectPropValue(csBaseUri,_T("VehicleID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Cast_ID"),CL3Variant(_T("")));
		if(!SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CTUNDISH_STATUS_OFFLINE)))
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


// 逻辑类ShiftMag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_ShiftMag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_ShiftMag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CShiftMag.h"

//当对象被装载到系统中时，被调用
void CShiftMag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CShiftMag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

//////自动换班
L3BOOL CShiftMag::AutoModifyProcessShift()
{
	/////获取换班的类型
	L3STRING str=GetPropValue(_T("L3Name")).ToString();

	CL3Variant valTemp;
	CL3RecordSetWrap rsTemp;
	Query(_T("Select * from XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo"),rsTemp);
	if (rsTemp.GetRowCount()==0)
	{
		////初始化当前班次表
		CL3RecordSetWrap rsInit;
		Query(_T("Select distinct UnitIndex from XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo "),rsInit);

		if(rsInit.GetRowCount()>0)
		{
			VARIANT val;
			rsInit.MoveFirst();
			for(int i=0;i<rsInit.GetRowCount();i++)
			{
				val.vt = VT_BSTR;val.bstrVal = rsInit.GetFieldByName(_T("UnitIndex")).ToBSTR();
				CL3RecordSetWrap rs;
				QueryWithParam(_T("Select * from XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo where UnitIndex=? order by L3Index "),&val,1,rs);
				if(rs.GetRowCount()>0)
				{
					rs.MoveFirst();
					CL3Variant newobject;
					newobject = rs.GetFieldByName(_T("UnitIndex"));
					CString URITemp;
					CreateNewObject(_T("XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo"),newobject);
					URITemp = _T("XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo\\")+newobject.ToCString();

					SetObjectPropValue(URITemp,_T("ShiftType"),rs.GetFieldByName(_T("ShiftType")));
					SetObjectPropValue(URITemp,_T("ShiftID"),rs.GetFieldByName(_T("ShiftID")));
					SetObjectPropValue(URITemp,_T("UnitTypeID"),rs.GetFieldByName(_T("UnitTypeID")));
					SetObjectPropValue(URITemp,_T("UnitID"),rs.GetFieldByName(_T("UnitID")));
					SetObjectPropValue(URITemp,_T("BeginProcessTime"),rs.GetFieldByName(_T("BeginProcessTime")));
					SetObjectPropValue(URITemp,_T("EndProcessTime"),rs.GetFieldByName(_T("EndProcessTime")));
					SetObjectPropValue(URITemp,_T("TeamID"),CL3Variant(L3SHORT(1)));
				}
				else return false;
				rs.Clear();
				rsInit.MoveNext();
			}
		}
		else return false;
		rsInit.Clear();

	}
	else
	{

		CL3RecordSetWrap rs;
		VARIANT val;
		val.vt = VT_BSTR;val.bstrVal = str;
		QueryWithParam(_T("Select * from XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo where ShiftType=? "),&val,1,rs);
		if(rs.GetRowCount()>0)
		{
			rs.MoveFirst();
			for(int i=0;i<rs.GetRowCount();i++)
			{	
				valTemp = rs.GetFieldByName(_T("L3Index"));
				L3SHORT shortTemp = rs.GetFieldByName(_T("CurrentID")).ToShort();
				CL3RecordSetWrap rsShift;
				QueryWithParam(_T("Select * from XGMESLogic\\ShiftTeamMag\\CShiftTeamOrder where ShiftType = ?  order by OrderIndex "),&val,1,rsShift);
				shortTemp = (shortTemp % rsShift.GetRowCount()) +1;
				SetObjectPropValue(_T("XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo\\")+valTemp.ToCString(),_T("CurrentID"),CL3Variant(shortTemp));
	
				rsShift.MoveFirst();
				for(int j=1;j<shortTemp;j++)	rsShift.MoveNext();
				SetObjectPropValue(_T("XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo\\")+valTemp.ToCString(),_T("ShiftID"),rsShift.GetFieldByName(_T("ShiftID")));
				SetObjectPropValue(_T("XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo\\")+valTemp.ToCString(),_T("TeamID"),rsShift.GetFieldByName(_T("TeamID")));

				VARIANT valParams[2];
				valParams[0].vt = VT_BSTR;		valParams[0].bstrVal = valTemp.ToBSTR();
				valParams[1].vt = VT_I2;		valParams[1].iVal = rsShift.GetFieldByName(_T("ShiftID")).ToShort();
				CL3RecordSetWrap rsTime;
				QueryWithParam(_T("Select * from XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo where UnitIndex = ? and ShiftID = ? "),valParams,2,rsTime);
				rsTime.MoveFirst();

				SetObjectPropValue(_T("XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo\\")+valTemp.ToCString(),_T("BeginProcessTime"),rsTime.GetFieldByName(_T("BeginProcessTime")));
				SetObjectPropValue(_T("XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo\\")+valTemp.ToCString(),_T("EndProcessTime"),rsTime.GetFieldByName(_T("EndProcessTime")));

				rs.MoveNext();

			}

		}
		else return false;

	}
	return true;
}


L3RECORDSET CShiftMag::GetShiftTeamOrder()
{
	CL3RecordSetWrap rs;
	CL3Variant valTemp;
	Query(_T("Select * from XGMESLogic\\ShiftTeamMag\\CShiftTeamOrder order by L3Index "),rs);
	if(rs.GetRowCount() == 0)
	{
		valTemp = CL3Variant(L3SHORT(1));
		CreateNewObject(_T("XGMESLogic\\ShiftTeamMag\\CShiftTeamOrder"),valTemp);
		CString cstrTemp = valTemp.ToCString();
		cstrTemp = _T("XGMESLogic\\ShiftTeamMag\\CShiftTeamOrder\\")+cstrTemp;

		SetObjectPropValue(cstrTemp,_T("ShiftType"),CL3Variant(_T("1")));
		SetObjectPropValue(cstrTemp,_T("OrderIndex"),CL3Variant(L3SHORT(1)));
		SetObjectPropValue(cstrTemp,_T("ShiftID"),CL3Variant(L3SHORT(1)));
		SetObjectPropValue(cstrTemp,_T("TeamID"),CL3Variant(L3SHORT(1)));
		
		rs.Clear();
		Query(_T("Select * from XGMESLogic\\ShiftTeamMag\\CShiftTeamOrder order by L3Index  "),rs);
	}
	
	return	rs.Detach();

}


L3BOOL CShiftMag::CommitShiftTeamOrder(L3RECORDSET rs)
{
	int i = rs->GetRecordCount();
	for(int j=0;j<i;j++)
	{
		rs->GoTo(rs->ToHead(),j);
		CL3Variant valTemp;
		rs->GetFieldByName(_T("L3Index"),valTemp);
		DeleteOldObject(_T("\\XGMESLogic\\ShiftTeamMag\\CShiftTeamOrder\\")+valTemp.ToCString());
	}

	CreateNewObjects(_T("\\XGMESLogic\\ShiftTeamMag\\CShiftTeamOrder"),rs);
	return true;

}

L3BOOL CShiftMag::DeleteShiftTeamOrder()
{
	CL3RecordSetWrap rs;
	L3LONG lTemp;
	if (!Query(_T("Select \"L3Index\"  from XGMESLogic\\ShiftTeamMag\\CShiftTeamOrder order by L3Index desc "),rs))
		return false;
	if(rs.GetRowCount()>0)
	{
		rs.MoveFirst();
		lTemp = rs.GetFieldByName(_T("L3Index")).ToLong();
		DeleteOldObject(_T("\\XGMESLogic\\ShiftTeamMag\\CShiftTeamOrder\\")+(CL3Variant(lTemp)).ToCString());
		return true;
	}
	else return false;
	
}


L3RECORDSET CShiftMag::GetUnitTime()
{
	CL3RecordSetWrap rs;
	CL3Variant valTemp;
	Query(_T("Select * from XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo order by L3Index "),rs);
	if(rs.GetRowCount() == 0)
	{
		valTemp = CL3Variant(L3SHORT(1));
		CreateNewObject(_T("XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo"),valTemp);
		CString cstrTemp = valTemp.ToCString();
		cstrTemp = _T("XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo\\")+cstrTemp;

		SetObjectPropValue(cstrTemp,_T("UnitIndex"),CL3Variant(_T("0101")));
		SetObjectPropValue(cstrTemp,_T("ShiftType"),CL3Variant(_T("1")));
		SetObjectPropValue(cstrTemp,_T("ShiftID"),CL3Variant(L3SHORT(1)));
		SetObjectPropValue(cstrTemp,_T("UnitTypeID"),CL3Variant(_T("01")));
		SetObjectPropValue(cstrTemp,_T("UnitTypeIDDesc"),CL3Variant(_T("工序描述")));
		SetObjectPropValue(cstrTemp,_T("UnitID"),CL3Variant(_T("01")));
		SetObjectPropValue(cstrTemp,_T("UnitIDDesc"),CL3Variant(_T("工位描述")));
		SetObjectPropValue(cstrTemp,_T("BeginProcessTime"),CL3Variant( L3DOUBLE(0.0) ));
		SetObjectPropValue(cstrTemp,_T("EndProcessTime"),CL3Variant( L3DOUBLE(0.0) ));
		
		rs.Clear();
		Query(_T("Select * from XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo order by L3Index "),rs);
	}
	
	return	rs.Detach();

}

L3BOOL CShiftMag::CommitUnitTime(L3RECORDSET rs)
{
	int i = rs->GetRecordCount();
	for(int j=0;j<i;j++)
	{
		rs->GoTo(rs->ToHead(),j);
		CL3Variant valTemp;
		rs->GetFieldByName(_T("L3Index"),valTemp);
		DeleteOldObject(_T("\\XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo\\")+valTemp.ToCString());
	}

	CreateNewObjects(_T("\\XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo"),rs);
	return true;

}

L3BOOL CShiftMag::DeleteUnitTime()
{
	CL3RecordSetWrap rs;
	L3LONG lTemp;
	if (!Query(_T("Select L3Index  from XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo order by L3Index desc "),rs))
		return false;
	if(rs.GetRowCount()>0)
	{
		rs.MoveFirst();
		lTemp = rs.GetFieldByName(_T("L3Index")).ToLong();
		DeleteOldObject(_T("\\XGMESLogic\\ShiftTeamMag\\CUnitTimeInfo\\")+(CL3Variant(lTemp)).ToCString());
		return true;
	}
	else return false;

}


L3RECORDSET CShiftMag::GetUnitOperator()
{
	CL3RecordSetWrap rs;
	CL3Variant valTemp;
	Query(_T("Select * from XGMESLogic\\ShiftTeamMag\\CUnitOperator order by L3Index "),rs);
	if(rs.GetRowCount() == 0)
	{
		valTemp = CL3Variant(L3SHORT(1));
		CreateNewObject(_T("XGMESLogic\\ShiftTeamMag\\CUnitOperator"),valTemp);
		CString cstrTemp = valTemp.ToCString();
		cstrTemp = _T("XGMESLogic\\ShiftTeamMag\\CUnitOperator\\")+cstrTemp;

		SetObjectPropValue(cstrTemp,_T("UnitIndex"),CL3Variant(_T("9999")));
		SetObjectPropValue(cstrTemp,_T("Operator"),CL3Variant(_T("操作工1,操作工2")));
		
		rs.Clear();
		Query(_T("Select * from XGMESLogic\\ShiftTeamMag\\CUnitOperator order by L3Index "),rs);
	}

	return	rs.Detach();
}


L3BOOL CShiftMag::CommitUnitOperator(L3RECORDSET rs)
{
	int i = rs->GetRecordCount();
	for(int j=0;j<i;j++)
	{
		rs->GoTo(rs->ToHead(),j);
		CL3Variant valTemp;
		rs->GetFieldByName(_T("L3Index"),valTemp);
		DeleteOldObject(_T("\\XGMESLogic\\ShiftTeamMag\\CUnitOperator\\")+valTemp.ToCString());
	}

	CreateNewObjects(_T("\\XGMESLogic\\ShiftTeamMag\\CUnitOperator"),rs);
	return true;
}


L3BOOL CShiftMag::DeleteUnitOperator()
{
	CL3RecordSetWrap rs;
	L3LONG lTemp;
	if (!Query(_T("Select L3Index  from XGMESLogic\\ShiftTeamMag\\CUnitOperator order by L3Index desc "),rs))
		return false;
	if(rs.GetRowCount()>0)
	{
		rs.MoveFirst();
		lTemp = rs.GetFieldByName(_T("L3Index")).ToLong();
		DeleteOldObject(_T("\\XGMESLogic\\ShiftTeamMag\\CUnitOperator\\")+(CL3Variant(lTemp)).ToCString());
		return true;
	}
	else return false;
}


L3RECORDSET CShiftMag::GetShiftTeamID(L3STRING str)
{
	CL3RecordSetWrap rs;
	CString cstrTemp;
	CL3Variant valTemp;
	valTemp = CL3Variant(str);
	cstrTemp = valTemp.ToCString();
	L3STRING bstrTemp = SysAllocString(_T(""));
	
	VARIANT val;
	
	Query(_T("Select UnitIndex, Operator  from XGMESLogic\\ShiftTeamMag\\CUnitOperator "),rs);
	if (rs.GetRowCount()>0)
	{
		int iix;
		CString cstrAllOperators;
		rs.MoveFirst();
		for(int i =0 ;i < rs.GetRowCount();i++)
		{
			cstrAllOperators = rs.GetFieldByName(_T("Operator")).ToCString();
			iix = cstrAllOperators.Find(cstrTemp);
			if (iix == -1) 
			{
				rs.MoveNext();
				continue;
			}

			valTemp = rs.GetFieldByName(_T("UnitIndex"));
			rs.Clear();
			L3SysFreeString(bstrTemp);
			bstrTemp = valTemp.ToBSTR();
			val.vt = VT_BSTR;val.bstrVal = bstrTemp;
			QueryWithParam(_T("Select ShiftID,TeamID,UnitID,ShiftWarning from XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo where L3Index= ? "),&val,1,rs);
			if (rs.GetRowCount()>0)
			{
				CString NewUri = _T("XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo\\");
				CString NewObj = bstrTemp;
				if(!rs.SetFieldByName(_T("UnitID"),CL3Variant(NewUri+NewObj)))
				{
					L3SysFreeString(bstrTemp);
					return NULL;
				}

				L3SysFreeString(bstrTemp);
				return rs.Detach();
			}
			break;
		}
	}

	L3SysFreeString(bstrTemp);
}


L3RECORDSET CShiftMag::GetCurrentShiftTeamID(L3SHORT shortTemp)
{
	CL3RecordSetWrap rs;

	VARIANT val;
	val.vt = VT_I2;		val.iVal = shortTemp;

	QueryWithParam(_T("Select CurrentID,ShiftID,TeamID from XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo where ShiftType = ?"),&val,1,rs);
	if(rs.GetRowCount()>0)
	{
		return rs.Detach();
	}
	else return NULL;

}


L3RECORDSET CShiftMag::GetSessionShiftTeam()
{
	//CString username = GetCurrentUser();
	//L3STRING strun = username.AllocSysString();
	//L3RECORDSET rs = GetShiftTeamID(strun);
	//L3SysFreeString(strun);

	//2009-01-10 tangyi
	CL3RecordSetWrap rs;
	CString csSQL = _T(" select TeamID,ShiftID from CCurrentShiftInfo where L3Index = '0101'");
	if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return NULL;
	else
		return rs.Detach();
}


L3BOOL CShiftMag::AutoWarning()
{
	CString str=GetPropValue(_T("L3Name")).ToCString();
	CL3RecordSetWrap rs;
	Query(_T("Select L3Index from XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo where ShiftType='")+str+_T("'"),rs);
	if(rs.GetRowCount()<=0)
	{
		return VARIANT_FALSE;
	}
	rs.MoveFirst();
	str = rs.GetFieldByName(_T("L3Index")).ToCString();
	CString NewUri = _T("\\XGMESLogic\\ShiftTeamMag\\CCurrentShiftInfo\\")+str;
	L3STRING xixi = NewUri.AllocSysString();
	L3LONG OldValue = GetObjectPropValue(xixi,_T("ShiftWarning")).ToLong();
	if(OldValue==0) 
	{
		OldValue++;
	}
	else
	{
		OldValue = 0;
	}
	if(!SetObjectPropValue(xixi,_T("ShiftWarning"),CL3Variant(OldValue)))
	{
		L3SysFreeString(xixi);
		return VARIANT_FALSE;
	}
	L3SysFreeString(xixi);

	return VARIANT_TRUE;

}

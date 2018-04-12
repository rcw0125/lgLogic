// 逻辑类CDispatch_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CDispatch_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CDispatch_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CDispatch_Mag.h"
#include "Material.h"
#include "MaterialMap.h"


//当对象被装载到系统中时，被调用
void CDispatch_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CDispatch_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <Method class="CDispatch_Mag" name="SteelTurnApp" type="L3BOOL">
/// 
/// 钢水回炉申请
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID字段
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
/// </Method>
L3BOOL CDispatch_Mag::SteelTurnApp(L3RECORDSET rsSteelTurnAppData)
{
	//数据检查
	CL3RecordSetWrap rsSteelData =rsSteelTurnAppData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return false;
	if(rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("SteelGradeIndex")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Time")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Steel_Weight")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Operator")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_UnitID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Reason")) < 0)
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	if(CreateNewObjects(DISPATCH_STEEL_TURN_CLASS_URI,rsSteelTurnAppData) < rsSteelData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	
	if(bUseTrans)
		Commit(nTrans);

	//改变属性值
	CL3Variant varEvent = GetPropValue(_T("SteelReturnAppEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("SteelReturnAppEvent"),nEvent);

	return true;

}
/// <Method class="CDispatch_Mag" name="SteelTurn" type="L3BOOL">
/// 
/// 钢水回炉
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括GUID\PreHeatID\All_Turn_Flag三个字段
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
/// </Method>
L3LONG CDispatch_Mag::SteelTurn(L3RECORDSET rsSteelTurnData)
{
	//数据检查
	CL3RecordSetWrap rsSteelData =rsSteelTurnData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return -1;
	if(rsSteelData.GetFieldIndex(_T("GUID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("All_Turn_Flag")) < 0)
		return -1;
	//数据解析
	rsSteelData.MoveFirst();
	CL3Variant valTemp = rsSteelData.GetFieldByName(_T("GUID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csObjectID = valTemp.ToCString();

	CString csURi= DISPATCH_STEEL_TURN_CLASS_URI + _T("\\") + csObjectID;
	L3LONG nTurnFlag =  GetObjectPropValue(csURi,_T("Turn_Flag")).ToLong();
	if(nTurnFlag) return -4;

	valTemp = rsSteelData.GetFieldByName(_T("PreHeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csPreHeatID = valTemp.ToCString();

	valTemp = rsSteelData.GetFieldByName(_T("All_Turn_Flag"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3LONG nAllTurnFlag = valTemp.ToLong();

	valTemp = rsSteelData.GetFieldByName(_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csHeatID = valTemp.ToCString();
	
	valTemp =  rsSteelData.GetFieldByName(_T("App_UnitID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString  csAppUnit = valTemp.ToCString();

	valTemp =  rsSteelData.GetFieldByName(_T("App_Steel_Weight"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3DOUBLE  fWeight = valTemp.ToDouble();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-27
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	//更改申请单相应信息
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	
	if(!SetObjectPropValue(csURi,_T("Turn_Time"),CL3Variant(timeNow)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}
	if(!SetObjectPropValue(csURi,_T("Turn_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}
	if(!SetObjectPropValue(csURi,_T("Turn_Operator"),CL3Variant(csUser)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}
	//班次班别
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	if(!SetObjectPropValue(csURi,_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID"))))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}
	if(!SetObjectPropValue(csURi,_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID"))))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	//更改计划信息
	CString csPlanURi = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	if(!SetObjectPropValue(csPlanURi,_T("Steel_Return_Flag"),L3LONG(1))) 
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	//判断是否全回炉
	//if(nAllTurnFlag)
	//{
	if(!SetObjectPropValue(csPlanURi,_T("Status"),CL3Variant(TAPPING_PLAN_STATUS_EXCUTED)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	if(!SetObjectPropValue(csURi,_T("All_Turn_Flag"),CL3Variant(nAllTurnFlag)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	L3LONG nRet = SteelAllReturn(csPlanURi,csAppUnit,csHeatID,fWeight);
	if(nRet < 0)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return nRet;
	}
	//}

	if(bUseTrans)
		Commit(nTrans);

	//修改钢包状态2009-03-03 tangyi
	CString csSteelUri = MATERIAL_STEEL_URI + _T("\\") + csHeatID;
	CString csLadleID = GetObjectPropValue(csSteelUri,_T("LadleID")).ToCString();
	CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
	SetObjectPropValue(csLadleUri,_T("Status"),CL3Variant(CLADLE_STATUS_HOT));

	//通知通讯向NC发送全回炉电文2009-03-22
	CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
	CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Steel_Back_Event"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csBaseUri,_T("NC_Steel_Back_Event"),nEvent);

	InvokeObjectMethod(PLAN_OBJ_URI,_T("ChangeRsTappingPlanValue"));

	return 0;// TODO : 请在此添加逻辑代码
}

/// <Method class="CDispatch_Mag" name="SteelBackApp" type="L3BOOL">
/// 
/// 钢水返送申请
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID字段
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
/// </Method>
L3BOOL CDispatch_Mag::SteelBackApp(L3RECORDSET rsSteelBackAppData)
{
	//数据检查
	CL3RecordSetWrap rsSteelData =rsSteelBackAppData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return false;
	if(rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("SteelGradeIndex")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Time")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Steel_Weight")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Operator")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_UnitID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Reason")) < 0)
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	if(CreateNewObjects(DISPATCH_STEEL_BACK_CLASS_URI,rsSteelBackAppData) < rsSteelData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	
	if(bUseTrans)
		Commit(nTrans);

	//改变属性值
	CL3Variant varEvent = GetPropValue(_T("SteelBackAppEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("SteelBackAppEvent"),nEvent);

	return true;

}

/// <Method class="CDispatch_Mag" name="SteelBack" type="L3BOOL">
/// 
/// 钢水返送
/// ARG&gt;&gt; rsSteelBackData :钢水返送信息,必须包括GUID\PreHeatID\BackUnitIDType\HeatID 三个字段
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsSteelBackData" type="L3RECORDSET">钢水返送信息</Param>
/// </Method>
L3LONG CDispatch_Mag::SteelBack(L3RECORDSET rsSteelBackData)
{
	//数据检查
	CL3RecordSetWrap rsSteelData =rsSteelBackData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return -1;
	if(rsSteelData.GetFieldIndex(_T("GUID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("Back_UnitID_Type")) < 0)
		return -1;
	//数据解析
	rsSteelData.MoveFirst();
	CL3Variant valTemp = rsSteelData.GetFieldByName(_T("GUID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csObjectID = valTemp.ToCString();

	CString csObjURi= DISPATCH_STEEL_BACK_CLASS_URI + _T("\\") + csObjectID;
	L3LONG nBackFlag =  GetObjectPropValue(csObjURi,_T("Back_Flag")).ToLong();
	if(nBackFlag) return -10;

	valTemp = rsSteelData.GetFieldByName(_T("PreHeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csPreHeatID = valTemp.ToCString();

	valTemp = rsSteelData.GetFieldByName(_T("Back_UnitID_Type"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3LONG nBackUnit = valTemp.ToLong();

	valTemp = rsSteelData.GetFieldByName(_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csHeatID = valTemp.ToCString();
	
	valTemp =  rsSteelData.GetFieldByName(_T("App_UnitID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString  csAppUnit = valTemp.ToCString();

	//根据返送工序判断申请工序是否处理
	L3LONG nAppUnit = _ttol(csAppUnit.Mid(1,1));
	CString csTappingPlanURi = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	L3SHORT nStatus =0;
	switch (nAppUnit)
	{
		case UNIT_AREA_CASTER://铸机只有到达允许返送
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("Caster_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus != 2)
                    return -2;
			break;
		case UNIT_AREA_RH://RH处理未出站不允许返送
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("RH_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				//if(nStatus < 3)
				if(nStatus < 5) //2009-02-16 tangyi
					return -3;
			break;
		case UNIT_AREA_LF://LF处理未出站不允许返送
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("LF_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 5) //2009-02-16 tangyi
					return -4;
			break;
		default:
			 return -5;//返送申请工序不合法
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -6;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-27
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -6;
	}

	//L3LONG nBackUnit = _ttol(csBackUnit.Mid(1,1));
	L3LONG nRet =0;
	CString csUnitID;
	switch(nBackUnit)
	{
		case UNIT_AREA_RH:
				nRet = SteelMoveInCache(csTappingPlanURi,UNIT_AREA_RH,csHeatID,csUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_LF:
				nRet = SteelMoveInCache(csTappingPlanURi,UNIT_AREA_LF,csHeatID,csUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_TAPSIDE:
				nRet = SteelMoveInCache(csTappingPlanURi,UNIT_AREA_TAPSIDE,csHeatID,csUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		default:
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -7;//返送目标工序不合法
				}
	}
	//更改申请单相应信息
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	
	if(!SetObjectPropValue(csObjURi,_T("Back_Time"),CL3Variant(timeNow)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	if(!SetObjectPropValue(csObjURi,_T("Back_UnitID"),CL3Variant(csUnitID)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	if(!SetObjectPropValue(csObjURi,_T("Back_Operator"),CL3Variant(csUser)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	if(!SetObjectPropValue(csObjURi,_T("Back_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	//更改计划信息
	if(!SetObjectPropValue(csTappingPlanURi,_T("Steel_Back_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -9;
	}

	if(bUseTrans)
		Commit(nTrans);

	InvokeObjectMethod(PLAN_OBJ_URI,_T("ChangeRsTappingPlanValue"));

	return 0;// TODO : 请在此添加逻辑代码
}

/// <Method class="CDispatch_Mag" name="SteelDivApp" type="L3BOOL">
/// 
/// 钢水炉次分割申请
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID字段
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
/// </Method>
L3BOOL CDispatch_Mag::SteelDivApp(L3RECORDSET rsSteelDivAppData)
{
	//数据检查
	CL3RecordSetWrap rsSteelData =rsSteelDivAppData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return false;
	if(rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("SteelGradeIndex")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Time")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Steel_Weight")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Operator")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_UnitID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Reason")) < 0)
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	if(CreateNewObjects(DISPATCH_STEEL_DIV_CLASS_URI,rsSteelDivAppData) < rsSteelData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	
	if(bUseTrans)
		Commit(nTrans);

	//改变属性值
	CL3Variant varEvent = GetPropValue(_T("SteelDivAppEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("SteelDivAppEvent"),nEvent);

	return true;

}

/// <Method class="CDispatch_Mag" name="SteelDiv" type="L3BOOL">
/// 
/// 钢水分割
/// ARG&gt;&gt; strPreHeatID :预定炉号
///        &gt;&gt; strBackUnit:   返送工位
///        &gt;&gt;strObjName:对象名
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="strPreHeatID" type="L3STRING">预定炉号</Param>
/// <Param name="strBackUnit" type="L3STRING">返送工位</Param>
/// <Param name="strObjName" type="L3STRING">预定炉号</Param>
/// </Method>
L3LONG CDispatch_Mag::SteelDiv(L3RECORDSET rsSteelDiv)
{
	//数据检查
	CL3RecordSetWrap rsSteelData =rsSteelDiv;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return -1;
	if(rsSteelData.GetFieldIndex(_T("GUID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("Back_UnitID_Type")) < 0)
		return -1;
	//数据解析
	rsSteelData.MoveFirst();
	CL3Variant valTemp = rsSteelData.GetFieldByName(_T("GUID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csObjectID = valTemp.ToCString();

	CString csObjURi= DISPATCH_STEEL_DIV_CLASS_URI + _T("\\") + csObjectID;
	L3LONG nDivFlag =  GetObjectPropValue(csObjURi,_T("Div_Flag")).ToLong();
	if(nDivFlag) return -14;

	valTemp = rsSteelData.GetFieldByName(_T("PreHeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csPreHeatID = valTemp.ToCString();

	valTemp = rsSteelData.GetFieldByName(_T("Back_UnitID_Type"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3LONG nBackUnit = valTemp.ToLong();

	valTemp = rsSteelData.GetFieldByName(_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csHeatID = valTemp.ToCString();
	
	valTemp =  rsSteelData.GetFieldByName(_T("App_UnitID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString  csAppUnit = valTemp.ToCString();

	valTemp =  rsSteelData.GetFieldByName(_T("App_Steel_Weight"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3DOUBLE  fWeight = valTemp.ToDouble();

	//根据返送工序判断申请工序是否合法
	L3LONG nAppUnit = _ttol(csAppUnit.Mid(1,1));
	CString csTappingPlanURi = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	L3SHORT nStatus =0;
	switch (nAppUnit)
	{
		case UNIT_AREA_CASTER://铸机只有开浇允许分割
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("Caster_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 3)
                    return -2;
			break;
		default:
			 return -3;//分割申请工序不合法
	}
	
	//下半炉熔炼号
	CString csHeatTreat = csHeatID.Mid(4,5);
	CString csYear = csHeatID.Mid(0,4);
	L3LONG nHeatTreat = _ttol(csHeatTreat);
	nHeatTreat = nHeatTreat + 90000;
	CString csDivHeatID;
	csDivHeatID.Format(_T("%05d"),nHeatTreat);
	csDivHeatID = csYear + csDivHeatID;
	//产生材料下半炉信息
	CL3RecordSetWrap rsDivSteelData;
	if(!CreateClassPropSet(MATERIAL_STEEL_URI,rsDivSteelData))
		return -4;
	//删除无用字段
	rsDivSteelData.DelField(_T("GUID"));
	rsDivSteelData.DelField(_T("Name"));
	//获取母炉信息
	CL3RecordSetWrap rsData;
	CString csSQL;
	csSQL.Format(_T("select * from %s where MaterialID ='%s'"),MATERIAL_STEEL_URI,csHeatID);
	if(!Query(csSQL,rsData)||rsData.IsNull()||rsData.GetRowCount() <1)
		return -5;
	rsData.MoveFirst();
	rsDivSteelData.AppendRecord();
	rsDivSteelData.CopyCurRowFrom(rsData);
	//修改重量，炉号
	rsDivSteelData.SetFieldByName(_T("Weight"),CL3Variant(fWeight));
	rsDivSteelData.SetFieldByName(_T("MaterialID"),CL3Variant(csDivHeatID));
	rsDivSteelData.SetFieldByName(_T("HeatID"),CL3Variant(csDivHeatID));
	//计算上半炉重量
	L3DOUBLE fOldWeight = rsData.GetFieldByName(_T("Weight")).ToDouble();
	fOldWeight -= fWeight;
	//产生材料对照表
	CL3RecordSetWrap rsMaterialMap;
	if(!CreateClassPropSet(_T("MES\\MaterialData\\MaterialMap"),rsMaterialMap))
		return -6;
	rsMaterialMap.AppendRecord();//上半炉
	rsMaterialMap.SetFieldByName(_T("FromType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("FromID"),CL3Variant(csHeatID));
	rsMaterialMap.SetFieldByName(_T("ToType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("ToID"),CL3Variant(csHeatID));
	rsMaterialMap.SetFieldByName(_T("Mode"),CL3Variant(L3LONG(MaterialMap::Split)));
	rsMaterialMap.SetFieldByName(_T("Mapper"),CL3Variant(csAppUnit));
	rsMaterialMap.SetFieldByName(_T("SrcAmount"),rsData.GetFieldByName(_T("Weight")));
	rsMaterialMap.SetFieldByName(_T("TgtAmount"),CL3Variant(fOldWeight));
	rsMaterialMap.AppendRecord();//下半炉
	rsMaterialMap.SetFieldByName(_T("FromType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("FromID"),CL3Variant(csHeatID));
	rsMaterialMap.SetFieldByName(_T("ToType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("ToID"),CL3Variant(csDivHeatID));
	rsMaterialMap.SetFieldByName(_T("Mode"),CL3Variant(L3LONG(MaterialMap::Split)));
	rsMaterialMap.SetFieldByName(_T("Mapper"),CL3Variant(csAppUnit));
	rsMaterialMap.SetFieldByName(_T("SrcAmount"),rsData.GetFieldByName(_T("Weight")));
	rsMaterialMap.SetFieldByName(_T("TgtAmount"),CL3Variant(fWeight));

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -7;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-27
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -7;
	}

	rsMaterialMap.MoveFirst();

	if(CreateNewObjects(_T("MES\\MaterialData\\MaterialMap"),(L3RECORDSET)rsMaterialMap) < 2)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	if(CreateNewObjects(MATERIAL_STEEL_URI,(L3RECORDSET)rsDivSteelData) < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -9;
	}
	CString csSteelUri = MATERIAL_STEEL_URI + _T("\\") + csHeatID;
	if(!SetObjectPropValue(csSteelUri,_T("Weight"),CL3Variant(fOldWeight)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -10;
	}
	//添加下半炉的信息到相应的缓存
	L3LONG nRet =0;
	CString csDivUnitID;
	switch(nBackUnit)
	{
		case UNIT_AREA_CASTER:
				nRet = AddSteelToSpeciCache(csTappingPlanURi,UNIT_AREA_CASTER,csDivHeatID,csDivUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_RH:
				nRet = AddSteelToSpeciCache(csTappingPlanURi,UNIT_AREA_RH,csDivHeatID,csDivUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_LF:
				nRet = AddSteelToSpeciCache(csTappingPlanURi,UNIT_AREA_LF,csDivHeatID,csDivUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_TAPSIDE:
				nRet = AddSteelToSpeciCache(csTappingPlanURi,UNIT_AREA_TAPSIDE,csDivHeatID,csDivUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		default:
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -13;//返送目标工序不合法
				}
	}
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	if(!SetObjectPropValue(csObjURi,_T("Div_Time"),CL3Variant(timeNow)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -11;
	}
	if(!SetObjectPropValue(csObjURi,_T("Div_UnitID"),CL3Variant(csDivUnitID)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -11;
	}
	if(!SetObjectPropValue(csObjURi,_T("Div_Operator"),CL3Variant(csUser)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -11;
	}
	if(!SetObjectPropValue(csObjURi,_T("Div_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -11;
	}
	//更改计划信息
	if(!SetObjectPropValue(csTappingPlanURi,_T("Div_HeatID"),CL3Variant(csDivHeatID)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -12;
	}

	if(bUseTrans)
		Commit(nTrans);

	InvokeObjectMethod(PLAN_OBJ_URI,_T("ChangeRsTappingPlanValue"));

	return 0;// TODO : 请在此添加逻辑代码
}

/// <Method class="CDispatch_Mag" name="SteelExchangeApp" type="L3BOOL">
/// 
/// 钢水改钢申请
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID字段
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
/// </Method>
L3BOOL CDispatch_Mag::SteelExchangeApp(L3RECORDSET rsSteelExchangeAppData)
{
	//数据检查
	CL3RecordSetWrap rsSteelData =rsSteelExchangeAppData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return false;
	if(rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("SteelGradeIndex")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Time")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Steel_Weight")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Operator")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_UnitID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Reason")) < 0)
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	if(CreateNewObjects(DISPATCH_STEEL_EXE_CLASS_URI,rsSteelExchangeAppData) < rsSteelData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	
	if(bUseTrans)
		Commit(nTrans);

	//改变属性值
	CL3Variant varEvent = GetPropValue(_T("SteelExchangeAppEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("SteelExchangeAppEvent"),nEvent);

	return true;

}

/// <Method class="CDispatch_Mag" name="SteelExchange" type="L3BOOL">
/// 
/// 钢水改钢
/// ARG &gt;&gt; 
///     &gt;&gt;rsExchangeData：改钢数据集必须包括GUID\PreHeatID\Ex_SteelGradeIndex三个字段
/// RET &lt;&lt; 成功返回0；失败返回code。
/// <Param name="rsExchangeData" type="L3RECORDSET">数据集</Param>
/// </Method>
L3LONG CDispatch_Mag::SteelExchange(L3RECORDSET rsExchangeData)
{
	//数据检查
	CL3RecordSetWrap rsSteelData =rsExchangeData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return -1;
	if(rsSteelData.GetFieldIndex(_T("GUID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("Ex_SteelGradeIndex")) < 0)
		return -1;
	//数据解析
	rsSteelData.MoveFirst();
	CL3Variant valTemp = rsSteelData.GetFieldByName(_T("GUID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csObjectID = valTemp.ToCString();

	
	CString csObjURi= DISPATCH_STEEL_EXE_CLASS_URI + _T("\\") + csObjectID;
	L3LONG nExFlag =  GetObjectPropValue(csObjURi,_T("Ex_Flag")).ToLong();
	if(nExFlag) return -5;

	valTemp = rsSteelData.GetFieldByName(_T("PreHeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csPreHeatID = valTemp.ToCString();

	valTemp = rsSteelData.GetFieldByName(_T("Ex_SteelGradeIndex"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csSteelGrade = valTemp.ToCString();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-27
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	//更改申请单相应信息
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	
	if(!SetObjectPropValue(csObjURi,_T("Ex_Time"),CL3Variant(timeNow)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	if(!SetObjectPropValue(csObjURi,_T("Ex_SteelGradeIndex"),CL3Variant(csSteelGrade)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	if(!SetObjectPropValue(csObjURi,_T("Ex_Operator"),CL3Variant(csUser)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	if(!SetObjectPropValue(csObjURi,_T("Ex_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	//更改计划信息
	CString csUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	if(!SetObjectPropValue(csUri,_T("SteelGradeIndex"),CL3Variant(csSteelGrade)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}
	//获取炉号
	valTemp = GetObjectPropValue(csUri,_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}
	CString csHeatID = valTemp.ToCString();
	L3STRING strHeatID = csHeatID.AllocSysString();
	//更改钢水信息与机组信息
	valTemp = InvokeObjectMethod(PLAN_OBJ_URI,_T("ModifyUnitSteelGradeIndex"),strHeatID);
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull() || valTemp.ToLong() < 0)
	{
		L3SysFreeString(strHeatID);
		if(bUseTrans)
			Rollback(nTrans);
		return valTemp.ToLong();
	}
	L3SysFreeString(strHeatID);

	if(bUseTrans)
		Commit(nTrans);

	InvokeObjectMethod(PLAN_OBJ_URI,_T("ChangeRsTappingPlanValue"));

	return 0;// TODO : 请在此添加逻辑代码
}

/// <Method class="CDispatch_Mag" name="DispatchLog" type="L3BOOL">
/// 
/// 调度记事
/// ARG&gt;&gt; rsData:数据集
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET">数据</Param>
/// </Method>
L3BOOL CDispatch_Mag::DispatchLog(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsLogData =rsData;
	if( rsLogData.IsNull() || rsLogData.GetRowCount() < 1)
		return false;
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rsLogData.MoveFirst();
	while(!rsLogData.IsEOF())
	{
		rsLogData.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsLogData.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsLogData.SetFieldByName(_T("CreateDate"),COleDateTime::GetCurrentTime());
		rsLogData.MoveNext();
	}

	if(CreateNewObjects(DISPATCH_LOG_CLASS_URI,rsData) <  rsLogData.GetRowCount())
		return false;

	return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CDispatch_Mag" name="GetBOFRealData" type="L3RECORDSET">
/// 
/// 获取转炉实时数据
/// ARG&gt;&gt;strBOFID:转炉工序
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CDispatch_Mag::GetBOFRealData(L3STRING strBOFID)
{
	//获取转炉当前炉号
	//CString csBOFID = strBOFID;
	//CString csObjUri = BOF_CLASS_URI + _T("\\") + csBOFID;
	//CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("HeatID"));
	//if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
	//	return NULL;
	//CString csHeatID = valTemp.ToCString();
	//CString csTemp = _T(" select a.HeatID,a.SteelGradeIndex,a.PreHeatID,a.ProductionDate   ");
	//		csTemp+= _T(" b.IronWeight,b.ScrapWeight,b.PigIronWeight,b.ReHeatAmount        ");
	//		csTemp+= _T(" c.Status,c.LanceAge,c.FurnaceAge,c.Campaign                      ");
	//		csTemp+= _T(" from %s a,%s b,% c where a.HeatID ='%s' and a.HeatID =b.HeatID   ");
	//		csTemp+= _T(" and a.HeatID = c.HeatID ");
	//CString csSQL;
	//csSQL.Format(csTemp,BOF_BASE_DATA_CLASS_URI,BOF_FEED_CLASS_URI,BOF_CLASS_URI,csHeatID);
	//CL3RecordSetWrap rsSteelData;
	//if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	//else
	//	return rsSteelData.Detach();
}


/// <Method class="CDispatch_Mag" name="GetBOFSideRealData" type="L3RECORDSET">
/// 
/// 获取炉后实时数据
/// ARG&gt;&gt;strBOFID:转炉工序
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CDispatch_Mag::GetBOFSideRealData(L3STRING strBOFID)
{
	//获取转炉当前炉号
	CString csBOFID = strBOFID;
	CString csObjUri = BOF_SIDE_CLASS_URI + _T("\\") + csBOFID;
	CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return NULL;
	CString csHeatID = valTemp.ToCString();

	CString csTemp = _T(" select a.HeatID,a.SteelGradeIndex,a.PreHeatID,a.LadleNo,a.ProductionDate ");
			csTemp+= _T(" b.Status,                                                        ");
			csTemp+= _T(" from %s a,%s b where a.HeatID ='%s' and a.HeatID =b.HeatID   ");

	CString csSQL;
	csSQL.Format(csTemp,TAP_BASE_DATA_CLASS_URI,BOF_SIDE_CLASS_URI,csHeatID);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	else
		return rsSteelData.Detach();
}


/// <Method class="CDispatch_Mag" name="GetFactoryEnergyData" type="">
/// </Method>
L3RECORDSET CDispatch_Mag::GetFactoryEnergyData()
{
	return NULL;// TODO : 请在此添加逻辑代码
}


/// <Method class="CDispatch_Mag" name="Get1LFRealData" type="">
/// 
/// 获取1#LF炉实时数据
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CDispatch_Mag::GetLFRealData(L3STRING strLFID)
{
	//获取转炉当前炉号
	CString csLFID = strLFID;
	CString csObjUri = LF_CLASS_URI + _T("\\") + csLFID;
	CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("TreatNo"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return NULL;
	CString csTreatNo = valTemp.ToCString();

	CString csTemp = _T(" select a.TreatNo, a.HeatID,a.PreHeatID,a.SteelGradeIndex,a.LadleNo,a.ProductionDate ");
			csTemp+= _T(" b.Status,                                                          ");
			csTemp+= _T(" from %s a,% b where a.TreatNo ='%s' and a.TreatNo =b.TreatNo       ");

	CString csSQL;
	csSQL.Format(csTemp,LF_BASE_DATA_CLASS_URI,LF_CLASS_URI,csTreatNo);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	else
		return rsSteelData.Detach();
}


/// <Method class="CDispatch_Mag" name="Get1RHRealData" type="">
/// 
/// 获取1#RH炉实时数据
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CDispatch_Mag::GetRHRealData(L3STRING strRHID)
{
	//获取转炉当前炉号
	CString csRHID = strRHID;
	CString csObjUri = RH_CLASS_URI + _T("\\") + csRHID;
	CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("TreatNo"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return NULL;
	CString csTreatNo = valTemp.ToCString();

	CString csTemp = _T(" select a.TreatNo, a.HeatID,a.PreHeatID,a.SteelGradeIndex,a.LadleNo,a.ProductionDate ");
			csTemp+= _T(" b.Status,                                                          ");
			csTemp+= _T(" from %s a,% b where a.TreatNo ='%s' and a.TreatNo =b.TreatNo       ");

	CString csSQL;
	csSQL.Format(csTemp,RH_BASE_DATA_CLASS_URI,RH_CLASS_URI,csTreatNo);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	else
		return rsSteelData.Detach();
}

/// <Method class="CDispatch_Mag" name="Get1CasterRealData" type="">
/// 
/// 获取铸机实时数据
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CDispatch_Mag::GetCasterRealData(L3STRING strCasterID)
{
	//获取转炉当前炉号
	CString csCasterID = strCasterID;
	CString csObjUri = CCM_CLASS_URI + _T("\\") + csCasterID;
	CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return NULL;
	CString csHeatID = valTemp.ToCString();

	CString csTemp = _T(" select a.TreatNo, a.HeatID,a.PreHeatID,a.SteelGradeIndex,a.LadleNo,a.ProductionDate         ");
			csTemp+= _T(" b.Status,b.Ladle_Weight,b.Tundish_Weight,b.Tundish_SeqNo,b.Casting_HeatNum,b.Tundish_HeatNum ");
			csTemp+= _T(" from %s a,% b where a.HeatID ='%s' and a.HeatID =b.HeatID                                    ");

	CString csSQL;
	csSQL.Format(csTemp,CCM_BASE_DATA_CLASS_URI,CCM_CLASS_URI,csHeatID);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	else
		return rsSteelData.Detach();
}



/// <Method class="CDispatch_Mag" name="GetAlloyStoreData" type="">
/// 
/// 获取合金原料库数据
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CDispatch_Mag::GetAlloyStoreData()
{
	return NULL;// TODO : 请在此添加逻辑代码
}

/// <Method class="CDispatch_Mag" name="GetScrapStoreData" type="">
/// 
/// 获取2#炉实时数据
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CDispatch_Mag::GetScrapStoreData()
{
	return NULL;// TODO : 请在此添加逻辑代码
}

/// <Method class="CDispatch_Mag" name="GetBloomStoreData" type="">
/// 
/// 获取2#炉实时数据
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CDispatch_Mag::GetBloomStoreData()
{
	return NULL;// TODO : 请在此添加逻辑代码
}

/// <Method class="CDispatch_Mag" name="GetBulkStoreData" type="">
/// 
/// 获取2#炉实时数据
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CDispatch_Mag::GetBulkStoreData()
{
	return NULL;// TODO : 请在此添加逻辑代码
}

/// <Method class="CDispatch_Mag" name="GetCurSteelBackInfor" type="DATASET">
/// 
/// 获取未处理钢包返送申请信息
/// ARG 
/// RET &gt;&gt; 找到的钢包返送申请信息记录集。
/// </Method>
L3RECORDSET CDispatch_Mag::GetCurSteelBackInfor()
{
	//CString csTemp = _T(" select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) or (App_Time < (select TRUNC(SYSDATE) from dual) and Back_Flag = 0)  ");

	CString csTemp = _T(" select * from (select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
			csTemp +=_T(" union                                                                               ");
			csTemp +=_T(" select * from                                                                       ");
			csTemp +=_T(" (select * from %s where App_Time <  (select TRUNC(SYSDATE) from dual)               ");
			csTemp +=_T("  and Back_Flag = 0 order by App_Time desc)  where rownum < 5 )                       ");
			csTemp +=_T(" order by Back_Flag asc ,App_Time desc                                                ");

	CString csSQL;
	csSQL.Format(csTemp,DISPATCH_STEEL_BACK_CLASS_URI,DISPATCH_STEEL_BACK_CLASS_URI);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull())
		return NULL;
	else
		return rsSteelData.Detach();

}

/// <Method class="CDispatch_Mag" name="GetCurSteelTurnInfor" type="DATASET">
/// 
/// 获取未处理钢包回炉申请信息
/// ARG 
/// RET &gt;&gt; 找到的钢包回炉申请信息记录集。
/// </Method>
L3RECORDSET CDispatch_Mag::GetCurSteelTurnInfor()
{
	//CString csTemp = _T(" select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
	//		csTemp +=_T(" or (App_Time < (select TRUNC(SYSDATE) from dual) and Turn_Flag = 0)  ");
	//		csTemp +=_T(" order by Turn_Flag asc ,App_Time desc                                ");

	CString csTemp = _T(" select * from (select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
			csTemp +=_T(" union                                                                               ");
			csTemp +=_T(" select * from                                                                       ");
			csTemp +=_T(" (select * from %s where App_Time <  (select TRUNC(SYSDATE) from dual)               ");
			csTemp +=_T("  and Turn_Flag = 0 order by App_Time desc)  where rownum < 5 )                      ");
			csTemp +=_T(" order by Turn_Flag asc ,App_Time desc                                               ");

	CString csSQL;
	csSQL.Format(csTemp,DISPATCH_STEEL_TURN_CLASS_URI,DISPATCH_STEEL_TURN_CLASS_URI);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull())
		return NULL;
	else
		return rsSteelData.Detach();

}

/// <Method class="CDispatch_Mag" name="GetCurSteelDivInfor" type="DATASET">
/// 
/// 获取未处理钢包炉次分割申请信息
/// ARG 
/// RET &gt;&gt; 找到的钢包回炉炉次分割信息记录集。
/// </Method>
L3RECORDSET CDispatch_Mag::GetCurSteelDivInfor()
{
	//CString csTemp = _T(" select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) or (App_Time < (select TRUNC(SYSDATE) from dual) and Div_Flag = 0)  ");

	CString csTemp = _T(" select * from (select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
			csTemp +=_T(" union                                                                               ");
			csTemp +=_T(" select * from                                                                       ");
			csTemp +=_T(" (select * from %s where App_Time <  (select TRUNC(SYSDATE) from dual)               ");
			csTemp +=_T("  and Div_Flag = 0 order by App_Time desc)  where rownum < 5 )                       ");
			csTemp +=_T(" order by Div_Flag asc ,App_Time desc                                                ");

	CString csSQL;
	csSQL.Format(csTemp,DISPATCH_STEEL_DIV_CLASS_URI,DISPATCH_STEEL_DIV_CLASS_URI);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull())
		return NULL;
	else
		return rsSteelData.Detach();
}

/// <Method class="CDispatch_Mag" name="GetCurSteelExInfor" type="DATASET">
/// 
/// 获取未处理改钢申请信息
/// ARG 
/// RET &gt;&gt; 找到的改钢申请记录集。
/// </Method>
L3RECORDSET CDispatch_Mag::GetCurSteelExInfor()
{
	//CString csTemp = _T(" select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) or (App_Time < (select TRUNC(SYSDATE) from dual) and Ex_Flag = 0)  ");
	CString csTemp = _T(" select * from (select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
			csTemp +=_T(" union                                                                               ");
			csTemp +=_T(" select * from                                                                       ");
			csTemp +=_T(" (select * from %s where App_Time <  (select TRUNC(SYSDATE) from dual)               ");
			csTemp +=_T("  and Ex_Flag = 0 order by App_Time desc)  where rownum < 5 )                       ");
			csTemp +=_T(" order by Ex_Flag asc ,App_Time desc                                                ");
	CString csSQL;
	csSQL.Format(csTemp,DISPATCH_STEEL_EXE_CLASS_URI,DISPATCH_STEEL_EXE_CLASS_URI);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull())
		return NULL;
	else
		return rsSteelData.Detach();
}

/// <Method class="CDispatch_Mag" name="GetCurSteelCache" type="DATASET">
/// 
/// 获取钢水当前所在缓存URi
/// ARG csHeatID：炉号
/// RET &gt;&gt; 找到的URi
/// </Method>
CString CDispatch_Mag::GetCurSteelCache(CString csHeatID)
{
	//获取材料当前钢水cache
	CString csTemp;
	csTemp.Format(_T("select Position from %s where MaterialID = '%s' and MaterialType = '%s'"),MES_MATERIAL_POSITION,csHeatID,MATERIAL_TYPE_STEEL);
	CL3RecordSetWrap rsPosition;
	if(!Query(csTemp,rsPosition) || rsPosition.IsNull())
		return _T("");
	rsPosition.MoveFirst();
	CString csCache = rsPosition.GetFieldByName(_T("Position")).ToCString();
	CString csIsOk = csCache.Mid(3,1);
	CString csIsCaster = csCache.Mid(3,3);
	if(csIsOk != _T("P") && csIsCaster != _T("A01"))
		return _T("");
	CString csCacheUri;
	if(csIsOk == _T("P"))
		csCacheUri = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\") + csCache;
	else
		csCacheUri = _T("XGMESLogic\\CCMMag\\CCCM_Prod_Area\\") + csCache;
	return csCacheUri;

}


/// <Method class="CDispatch_Mag" name="SteelMoveInCache" type="L3LONG">
/// 
/// 在工序缓存中移动钢水
/// ARG&gt;&gt; csTappingPlanURi：出钢计划URI
///  &gt;&gt; nUnitType：目标工序
///  &gt;&gt; csHeatID：炉号
///  &gt;&gt; &csUnitID：目标机组
/// RET &lt;&lt;返回0
/// </Method>
L3LONG CDispatch_Mag::SteelMoveInCache(CString csTappingPlanURi,L3LONG nUnitType,CString csHeatID,CString &csUnitID)
{

	L3LONG nRet = MoveSteelFromCurCache(csHeatID);
	if(nRet < 0)
		return nRet;

	nRet = AddSteelToSpeciCache(csTappingPlanURi,nUnitType,csHeatID,csUnitID);
	if(nRet < 0)
		return nRet;
	


	return 0;
}

/// <Method class="CDispatch_Mag" name="MoveSteelFromCurCache" type="L3LONG">
/// 
/// 将钢水从当前缓存中移去
/// ARG&gt;&gt; 
///  &gt;&gt; csHeatID：炉号
/// RET &lt;&lt;返回0
/// </Method>

L3LONG CDispatch_Mag::MoveSteelFromCurCache(CString csHeatID)
{
	//组建数据集
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("Amount"),VT_INT);
	rsMaterial.AppendRecord();
	rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csHeatID));
	rsMaterial.SetFieldByName(_T("Amount"),CL3Variant(L3LONG(1)));
	
	CString csSteelCurCache = GetCurSteelCache(csHeatID);
	if(csSteelCurCache.IsEmpty())
		return -90;//钢水当前没有在相应的缓存中

	CL3Variant valResult = InvokeObjectMethod(csSteelCurCache,_T("RemoveMaterials"),(L3RECORDSET)rsMaterial);
	if(!valResult.IsValid()||!valResult.ToBOOL())
		return -91;//钢水从返送申请工序移除失败

	return 0;

}

/// <Method class="CDispatch_Mag" name="SteelMoveInCache" type="L3LONG">
/// 
/// 将钢水移动到指定的缓存同时更改计划信息
/// ARG&gt;&gt; csTappingPlanURi：出钢计划URI
///  &gt;&gt; nUnitType：目标工序
///  &gt;&gt; &csUnitID：目标机组
/// RET &lt;&lt;返回0
/// </Method>

L3LONG CDispatch_Mag::AddSteelToSpeciCache(CString csTappingPlanURi,L3LONG nUnitType,CString csHeatID,CString &csUnitID)
{
	CString csUnitIDType;

	switch(nUnitType)
	{
		case UNIT_AREA_CASTER:
			csUnitIDType = _T("Caster_ID");
		case UNIT_AREA_RH:
			csUnitIDType = _T("RHID");
			if(!SetObjectPropValue(csTappingPlanURi,_T("Caster_Status"),CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING)))
				return -92; 
			if(!SetObjectPropValue(csTappingPlanURi,_T("RH_Status"),CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING)))
				return -93;
			break;
		case UNIT_AREA_LF:
			csUnitIDType = _T("LFID");
			if(!SetObjectPropValue(csTappingPlanURi,_T("Caster_Status"),CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING)))
				return -92; 
			if(!SetObjectPropValue(csTappingPlanURi,_T("RH_Status"),CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING)))
				return -93;
			if(!SetObjectPropValue(csTappingPlanURi,_T("LF_Status"),CL3Variant(TAPPING_PLAN_LF_STATUS_UNEXCUTING)))
				return -94;
			break;
		//case UNIT_AREA_TAPSIDE:
		//	csUnitIDType = _T("BOFID");
		//	if(!SetObjectPropValue(csTappingPlanURi,_T("Caster_Status"),CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING)))
		//		return -92; 
		//	if(!SetObjectPropValue(csTappingPlanURi,_T("RH_Status"),CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING)))
		//		return -93;
		//	if(!SetObjectPropValue(csTappingPlanURi,_T("LF_Status"),CL3Variant(TAPPING_PLAN_LF_STATUS_UNEXCUTING)))
		//		return -94;
		//	if(!SetObjectPropValue(csTappingPlanURi,_T("Side_Status"),CL3Variant(TAPPING_PLAN_SIDE_STATUS_UNEXCUTING)))
		//		return -95;
		//	break;
		default:
			return -96;
	}
	//组建数据集
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("Amount"),VT_INT);
	rsMaterial.AppendRecord();
	rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csHeatID));
	rsMaterial.SetFieldByName(_T("Amount"),CL3Variant(L3LONG(1)));
	
	csUnitID = GetObjectPropValue(csTappingPlanURi,csUnitIDType).ToCString();
	if(csUnitID == _T("0")) return -97;//返送目标工序，工艺路径不允许
	//if(csUnitID ==UNIT_ID_1BOF) csUnitID = UNIT_ID_1TAPSIDE;
	//if(csUnitID ==UNIT_ID_2BOF) csUnitID = UNIT_ID_2TAPSIDE;
	//if(csUnitID ==UNIT_ID_3BOF) csUnitID = UNIT_ID_3TAPSIDE;
	//if(csUnitID ==UNIT_ID_4BOF) csUnitID = UNIT_ID_4TAPSIDE;

	CString csSteelNextCache = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\") + csUnitID +_T("P01");

	CL3Variant valResult = InvokeObjectMethod(csSteelNextCache,_T("AddMaterials"),(L3RECORDSET)rsMaterial);					
	if(!valResult.IsValid()||!valResult.ToBOOL())
		return -98;//钢水移到返送目标工序失败

	return 0;

}

/// <Method class="CDispatch_Mag" name="SteelAllReturn" type="L3LONG">
/// 
/// 钢水全回炉
/// ARG&gt;&gt; csTappingPlanURi：出钢计划URI
///  &gt;&gt; csUnitID：全回炉申请机组
///  &gt;&gt; csHeatID：炉号
/// RET &lt;&lt;返回0错误代码
/// </Method>
L3LONG CDispatch_Mag::SteelAllReturn(CString csTappingPlanURi,CString csUnitID,CString csHeatID,L3DOUBLE fWeight)
{
	//判断状态
	L3LONG nAppUnit = _ttol(csUnitID.Mid(1,1));
	L3SHORT nStatus =0;
	CL3Variant valTemp;
	switch (nAppUnit)
	{
		case UNIT_AREA_CASTER://铸机只有到达允许全回炉
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("Caster_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus != 2)
                    return -21;
			break;
		case UNIT_AREA_RH://RH处理未出站不允许全回炉
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("RH_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 5)//2009-02-16 tangyi
					return -22;
			break;
		case UNIT_AREA_LF://LF处理未出站不允许全回炉
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("LF_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 5)//2009-02-16 tangyi
					return -23;
			break;
		case UNIT_AREA_TAPSIDE://炉后处理未结束不允许全回炉
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("Side_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 3)
					return -24;
		case UNIT_AREA_BOF://转炉处理未结束不允许全回炉
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("BOF_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 5)
					return -25;
			break;
		default:
			 return -26;//回炉申请工序不合法
	}
	//删除钢水材料表信息
	CString csSteelUri = MATERIAL_STEEL_URI + _T("\\") + csHeatID;
	if(!SetObjectPropValue(csSteelUri,_T("Status"),CL3Variant(L3LONG(Material::Deleted))))
		return -27;

	//将钢水从缓存移去
	L3LONG nRet = MoveSteelFromCurCache(csHeatID);	
	if(nRet < 0)
		return nRet;

	COleDateTime curTime= COleDateTime::GetCurrentTime();
	CString csIronMaterialID = csHeatID + _T("_") + curTime.Format(_T("%Y%m%d%H%M%S"));

	//生成材料对照表
	CL3RecordSetWrap rsMaterialMap;
	if(!CreateClassPropSet(_T("MES\\MaterialData\\MaterialMap"),rsMaterialMap))
		return -28;
	rsMaterialMap.AppendRecord();
	rsMaterialMap.SetFieldByName(_T("FromType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("FromID"),CL3Variant(csHeatID));
	rsMaterialMap.SetFieldByName(_T("ToType"),CL3Variant(MATERIAL_TYPE_IRON));
	rsMaterialMap.SetFieldByName(_T("ToID"),CL3Variant(csIronMaterialID));
	rsMaterialMap.SetFieldByName(_T("Mode"),CL3Variant(L3LONG(MaterialMap::Produce)));
	rsMaterialMap.SetFieldByName(_T("Mapper"),CL3Variant(csUnitID));
	rsMaterialMap.SetFieldByName(_T("SrcAmount"),CL3Variant(fWeight));
	rsMaterialMap.SetFieldByName(_T("TgtAmount"),CL3Variant(fWeight));

	if(CreateNewObjects(_T("MES\\MaterialData\\MaterialMap"),L3RECORDSET(rsMaterialMap)) < rsMaterialMap.GetRowCount())
		return -29;

	//2009-01-02 tangyi 屏蔽以下信息，回炉钢在转炉兑铁时人工录入
	//生成回炉钢水信息（铁水）
	//CL3RecordSetWrap rsIronData;
	//if(!CreateClassPropSet(MATERIAL_BFIRON_URI,rsIronData))
	//	return -30;
	//rsIronData.AppendRecord();
	//rsIronData.SetFieldByName(_T("MaterialID"),CL3Variant(csIronMaterialID));
	//rsIronData.SetFieldByName(_T("Tare"),CL3Variant(fWeight));
	//rsIronData.SetFieldByName(_T("Source"),CL3Variant(L3LONG(3)));

	//if(CreateNewObjects(MATERIAL_IRON_URI,L3RECORDSET(rsIronData)) < rsIronData.GetRowCount())
	//	return -31;

	//
	////组建返送钢水数据集
	//CL3RecordSet *pRSIron = new CL3RecordSet();
	//CL3RecordSetWrap rsIronMaterial; pRSIron->QueryInterface(IID_IL3RecordSet,rsIronMaterial); pRSIron->Release();
	//rsIronMaterial.AddField(_T("MaterialType"),VT_BSTR);
	//rsIronMaterial.AddField(_T("MaterialID"),VT_BSTR);
	//rsIronMaterial.AddField(_T("Amount"),VT_INT);
	//rsIronMaterial.AppendRecord();
	//rsIronMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_IRON));
	//rsIronMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csIronMaterialID));
	//rsIronMaterial.SetFieldByName(_T("Amount"),CL3Variant(L3LONG(1)));
	//CL3Variant valResult = InvokeObjectMethod(MIXFProduceCache_URI,_T("AddMaterials"),(L3RECORDSET)rsIronMaterial);					
	//if(!valResult.IsValid()||!valResult.ToBOOL())
	//	return -32;//回炉钢水移到返送目标工序失败

	return 0;
}




/// <Method class="CDispatch_Mag" name="GetDestination" type="L3RECORDSET">
/// 
/// 获取工序工艺去向
/// ARG&gt;&gt;strBOFID:转炉工序
/// RET &lt;&lt;返回数据集
/// </Method>
L3STRING CDispatch_Mag::GetDestination(L3STRING strUnitID,L3STRING strHeatID)
{
	CString csRtn =_T("");
	CString csUnitID =strUnitID;
	csUnitID.Trim();
	if(csUnitID.IsEmpty()) return csRtn.AllocSysString();
	
	CString csSQL;
	CL3RecordSetWrap rsResult;
	csSQL.Format(_T("select * from CPlan_Tapping where HeatID = '%s'"),strHeatID);
	if (!Query(csSQL,rsResult))
		return NULL;
	rsResult.MoveFirst();
	CString csRefineType = rsResult.GetFieldByName(_T("Refine_Type")).ToCString();

	L3LONG nUnitID = _ttol(csUnitID.Mid(1,1));
	switch(nUnitID)
	{
		case UNIT_AREA_BOF:
			if(csRefineType == _T("0"))
				return rsResult.GetFieldByName(_T("CasterID")).ToBSTR();
			else
				if(csRefineType == _T("L") || csRefineType == _T("LR"))
					return rsResult.GetFieldByName(_T("LFID")).ToBSTR();
				else
					if(csRefineType == _T("R") || csRefineType == _T("RL"))
						return rsResult.GetFieldByName(_T("RHID")).ToBSTR();
			break;
		case UNIT_AREA_LF:
				if(csRefineType == _T("L") || csRefineType == _T("RL"))
					return rsResult.GetFieldByName(_T("CasterID")).ToBSTR();
				else
					if(csRefineType == _T("LR"))
						return rsResult.GetFieldByName(_T("RHID")).ToBSTR();
			break;
		case UNIT_AREA_RH:
				if(csRefineType == _T("R") || csRefineType == _T("LR"))
					return rsResult.GetFieldByName(_T("CasterID")).ToBSTR();
				else
					if(csRefineType == _T("RL"))
						return rsResult.GetFieldByName(_T("LFID")).ToBSTR();
			break;
		default:
			return csRtn.AllocSysString();
	}	

	return csRtn.AllocSysString(); 
	
}

/// <Method class="CDispatch_Mag" name="AddDisExceptional" type="L3LONG">
/// 新增设备异常主信息
/// <Param name="dsInfo" type="L3RECORDSET">新增主信息</Param>
/// </Method>
L3LONG CDispatch_Mag::AddDisExceptional(L3RECORDSET dsInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csDate = rsData.GetFieldByName(_T("CreateDate")).ToCString();//日期yyyyMmdd
		CString csUnitID = rsData.GetFieldByName(_T("UnitID")).ToCString();//工作中心
		CString csShift = rsData.GetFieldByName(_T("Shift")).ToCString();//班次

		if(csDate == _T("") || csUnitID == _T("") || csShift == _T(""))
			return 0;
		CString csObjectID = csDate + csUnitID + csShift;
		rsData.SetFieldByName(_T("IDObject"),CL3Variant(csObjectID));
		
		rsData.MoveNext();
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
	if(CreateNewObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional"),rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="ModifyDisExceptional" type="L3LONG">
/// 修改设备异常主信息
/// <Param name="dsInfo" type="L3RECORDSET">修改的主信息</Param>
/// </Method>
L3LONG CDispatch_Mag::ModifyDisExceptional(L3RECORDSET dsInfo)
{
	// TODO : 请在此添加逻辑代码
	return 0;
}

/// <Method class="CDispatch_Mag" name="DeleteDisExceptional" type="L3LONG">
/// 删除设备异常主信息
/// <Param name="dsInfo" type="L3RECORDSET">删除的主信息</Param>
/// </Method>
L3LONG CDispatch_Mag::DeleteDisExceptional(L3RECORDSET dsInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;
	
	if(rsData.GetFieldIndex(_T("IDObject")) < 0)
		return -1;//没有关键字

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
		CString csObjectID = rsData.GetFieldByName(_T("IDObject")).ToCString();
		if(csObjectID == _T(""))
		{
			if(bUseTrans)		
				Rollback(nTrans);
			return -1;//没有关键字
		}
		CString csTemp;
		CString csSQL;

		csTemp =_T(" SELECT * FROM %s WHERE IDObject = '%s'");
		csSQL.Format(csTemp,_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),csObjectID);
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
			if(DeleteOldObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;//删除详细信息失败
			}
		}
		
		rsData.MoveNext();
	}
	
	rsData.MoveFirst();
	if(DeleteOldObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional"),rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;//删除主信息失败
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="AddDisExceptionalItems" type="L3LONG">
/// 新增设备异常详细信息
/// <Param name="dsInfo" type="L3RECORDSET">新增的详细信息</Param>
/// </Method>
L3LONG CDispatch_Mag::AddDisExceptionalItems(L3RECORDSET dsInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csObjectID = rsData.GetFieldByName(_T("IDObject")).ToCString();
		CString csItems = rsData.GetFieldByName(_T("Items")).ToCString();

		if(csObjectID == _T("") || csItems == _T(""))
			return -1;//没有主信息关键字或没有选择异常项目

		COleDateTime dtBeginTime = rsData.GetFieldByName(_T("BeginTime")).ToDateTime();//COleDateTime::GetCurrentTime();
		COleDateTime dtEndTime = rsData.GetFieldByName(_T("EndTime")).ToDateTime();

		long lTimeSpan = 0;
		COleDateTimeSpan span = dtEndTime - dtBeginTime;
		lTimeSpan = (LONG)span.GetTotalMinutes();
		//设置异常时间长度
		rsData.SetFieldByName(_T("TimeSpan"),CL3Variant(lTimeSpan));
		
		rsData.MoveNext();
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
	if(CreateNewObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
				Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="ModifyDisExceptionalItems" type="L3LONG">
/// 修改设备异常详细信息
/// <Param name="dsInfo" type="L3RECORDSET">修改的详细信息</Param>
/// </Method>
L3LONG CDispatch_Mag::ModifyDisExceptionalItems(L3RECORDSET dsInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;

	if(rsData.GetFieldIndex(_T("GUID")) < 0)
		return -1;//没有关键字
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	if(!SetObjsPropValues(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//修改详细信息失败
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="DelDisExceptionalItems" type="L3LONG">
/// 删除设备异常详细信息
/// <Param name="dsInfo" type="L3RECORDSET">删除的详细信息</Param>
/// </Method>
L3LONG CDispatch_Mag::DelDisExceptionalItems(L3RECORDSET dsInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;

	if(rsData.GetFieldIndex(_T("GUID")) < 0)
		return -1;//没有关键字
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	if(DeleteOldObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;//删除详细信息失败
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="GetDispExceData" type="L3RECORDSET">
/// 设备异常通用查询方法
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CDispatch_Mag::GetDispExceData(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition = strCondition;
	if(csCondition == _T(""))
		return NULL;
	
	CString csSQL;
	CString csTemp = _T("Select * from XGMESLogic\\DispatchMag\\CDisp_Exceptional where %s");
	csSQL.Format(csTemp,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	
	return rsResult.Detach();
}

/// <Method class="CDispatch_Mag" name="GetDispExceItemData" type="L3RECORDSET">
/// 通用获取设备异常详细
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CDispatch_Mag::GetDispExceItemData(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition = strCondition;
	if(csCondition == _T(""))
		return NULL;

	CString csSQL;
	CString csTemp = _T("Select * from XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items where %s");
	csSQL.Format(csTemp,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	
	return rsResult.Detach();
}

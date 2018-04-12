// 逻辑类CBF_Iron_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CBF_Iron_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CBF_Iron_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CBF_Iron_Mag.h"
#include "Material.h"
#include "_CBFIron.h"
#include "_CDeS_Base_Data.h"

//2010-01-04 将	EventIronChanged 修改改在事务之外


//当对象被装载到系统中时，被调用
void CBF_Iron_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CBF_Iron_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 返回入库缓冲区的URI
/// </summary>
CString CBF_Iron_Mag::GetInputCache()
{
	//return __super::GetInputCache();
	// 入厂铁水库无输入缓冲区
	return _T("");
}

/// <summary>
/// 返回出库缓冲区的URI
/// </summary>
CString CBF_Iron_Mag::GetOutputCache()
{
	return BFIronStoreOutCache_URI;
}

/// <summary>
/// 返回入库记录类型名称
/// </summary>
CString CBF_Iron_Mag::GetInputLogType()
{
	return BFIronInLog_URI;
}

/// <summary>
/// 返回出库记录类型名称
/// </summary>
CString CBF_Iron_Mag::GetOutputLogType()
{
	return BFIronOutLog_URI;
}

/// <summary>
/// 返回库位类型名称
/// </summary>
CString CBF_Iron_Mag::GetStoreAreaType()
{
	return XGSTOREAREA_URI;
}

/// <summary>
///	初始化库房的属性
/// </summary>
BOOL CBF_Iron_Mag::InitializeStoreProperties()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::InitializeStoreProperties();
}

/// <summary>
/// 填充库位的初始化数据
/// </summary>
BOOL CBF_Iron_Mag::GetInitialAreaData(CL3RecordSetWrap& rs)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetInitialAreaData(rs);
}

/// <summary>
/// 在库房初始完成后调用。继承类重载此函数进行额外的初始化工作。
/// </summary>
void CBF_Iron_Mag::OnAfterStoreInitialized()
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::OnAfterStoreInitialized();
}

/// <summary>
/// 入库前预处理。在入库操作前调用。继承类可重载此方法进行预先的数据准备和处理
/// ARG >> rsInputInfo : 入库信息记录。
/// RET << TRUE 继续入库；FALSE 中断入库
/// </summary>
BOOL CBF_Iron_Mag::OnBeforeInputMaterials(L3RECORDSET rsInputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeInputMaterials(rsInputInfo);
}

/// <summary>
/// 入库后续处理。在入库操作成功后调用。继承类可重载此方法进行额外的处理。
/// ARG >> rsInputInfo : 入库信息记录。
/// RET << 成功返回TRUE；失败返回FALSE；
/// </summary>
BOOL CBF_Iron_Mag::OnAfterMaterialsInputted(L3RECORDSET rsInputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsInputted(rsInputInfo);
}

/// <summary>
/// 出库前预处理。在出库操作前调用。继承类可重载此方法进行预先的数据准备和处理
/// ARG >> rsOutputInfo : 出库信息记录。
/// RET << TRUE 继续出库；FALSE 中断出库
/// </summary>
BOOL CBF_Iron_Mag::OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeOutputMaterials(rsOutputInfo);
}

/// <summary>
/// 出库后续处理。在出库操作成功后调用。继承类可重载此方法进行额外的处理。
/// ARG >> rsOutputInfo : 出库信息记录。
/// RET << 成功返回TRUE；失败返回FALSE；
/// </summary>
BOOL CBF_Iron_Mag::OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsOutputted(rsOutputInfo);
}

/// <summary>
/// 人工增加库存前预处理。在进行人工增加库存前调用。继承类可重载此方发进行预先数据准备和处理
/// ARG	>> rsMaterialInfo : 新增材料信息记录。
/// RET << 返回TRUE继续处理；返回FALSE中断。
/// </summary>
BOOL CBF_Iron_Mag::OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeAddMaterials(rsMaterialInfo);
}

/// <summary>
/// 人工增加库存后续处理。在进行人工增加库存后调用。继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 新增的材料信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBF_Iron_Mag::OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsAdded(rsMaterialInfo);
}

/// <summary>
/// 人工删除库存前预处理。在进行人工删除库存前调用。继承类可重载此方发进行预先数据准备和处理
/// ARG	>> rsMaterialInfo : 删除材料信息记录。
/// RET << 返回TRUE继续处理；返回FALSE中断。
/// </summary>
BOOL CBF_Iron_Mag::OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeDeleteMaterials(rsMaterialInfo);
}

/// <summary>
/// 人工删除库存后续处理。在进行人工删除库存后调用。继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 删除的材料信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBF_Iron_Mag::OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsDeleted(rsMaterialInfo);
}

//tangyi 2007-12-09
/// <summary>
/// 移库前导处理。
/// ARG >> rsMaterialInfo : 删除的材料信息记录。
/// RET << 返回TRUE继续处理；返回FALSE中断。
/// </summary>
BOOL CBF_Iron_Mag::OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// 移库后续处理。
/// ARG >> rsMaterialInfo : 删除的材料信息记录。
/// RET << << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBF_Iron_Mag::OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// 入库记录预处理。继承类可重载此方法在入库前检查或处理入库记录
/// </summary>
void CBF_Iron_Mag::PrepareInputLog(L3RECORDSET rsInputLog)
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::PrepareInputLog(rsInputLog);
}

/// <summary>
/// 出库记录预处理。继承类可重载此方法在出库前检查或处理出库记录
/// </summary>
void CBF_Iron_Mag::PrepareOutputLog(L3RECORDSET rsOutputLog)
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::PrepareOutputLog(rsOutputLog);
}

/// <summary>
/// 返回指定编号的库位对象的URI
/// </summary>
CString CBF_Iron_Mag::GetAreaURI(LPCTSTR lpcszAreaID)
{
	return XGSTOREAREA_URI + CString(_T("\\")) + lpcszAreaID;
}

/// <Method class="CBF_Iron_Mag" name="NewIronData" type="L3LONG">
/// 
/// 新增铁水数据
/// ARG&gt;&gt; rsIron : 铁水数据。必须包含BFID,TAP_No,TPC_No,Source字段。
/// RET &lt;&lt; 成功返回1；失败返回出错代码。
/// <Param name="rsIron" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::NewIronData(L3RECORDSET rsIron)
{
	CL3RecordSetWrap rs = rsIron;

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	// 入厂铁水入库, 补齐入库数据所需字段
	rs.AddField(MESPROP_MATERIAL_TYPE,L3VT_STRING);
	rs.AddField(MESPROP_AMOUNT,L3VT_DOUBLE);
	rs.AddField(_T("StoreAreaID"),L3VT_STRING);
	rs.AddField(_T("DeSFlag"),L3VT_LONG);
	
	// 补齐字段信息
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CBFIron")));
		// 计算材料号
		CString strTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString strTpcNo = rs.GetFieldByName(_T("TPC_No")).ToCString();
		CString strID = strTapNo + strTpcNo;
		rs.SetFieldByName(_T("MaterialID"),CL3Variant(strID));
		// 初始状态
		rs.SetFieldByName(_T("Status"),CL3Variant((LONG)Material::Normal));
		rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironNotProcessed));
		// 入库库位
		rs.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON));
		// 入库量
		rs.SetFieldByName(MESPROP_AMOUNT,CL3Variant((DOUBLE)1));
		// 剩余量
		rs.SetFieldByName(_T("Spare_Weight"),rs.GetFieldByName(_T("Net_Weight")));
		// TODO: 其他需要补齐的数据

		rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rs.SetFieldByName(_T("Production_Date"),CL3Variant(COleDateTime::GetCurrentTime()));
		//2008-12-25 Added Begin
		L3LONG nDest = rs.GetFieldByName(_T("Destination")).ToLong();
		if(nDest == CBFIron::ironToNoWhere)
		{	// 无去向
			rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironNotProcessed));
		}
		else
		{	// 有去向
			rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironDestDefined));
		}
		//2008-12-25 Added end

		rs.SetFieldByName(_T("DeSFlag"),(L3LONG)0);//2009-11-05

		rs.MoveNext();
	}

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	// 创建铁水材料
	rs.MoveFirst();
	LONG nRet = CreateNewObjects(MATERIAL_BFIRON_URI,rs);
	if(nRet < rs.GetRowCount())
	{
		Rollback(nTrans);
		return -1;
	}
	
	// 将新建的铁水入库
	rs.MoveFirst();
	if(!InputMaterials(rs))
	{
		Rollback(nTrans);
		return -1;
	}



	Commit(nTrans);

	// 触发预约事件
	EventIronChanged *= -1;

	return rs.GetRowCount();
}

/// <Method class="CBF_Iron_Mag" name="ModifyIronData" type="L3LONG">
/// 修改铁水数据
/// <Param name="rsIron" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::ModifyIronData(L3RECORDSET rsIron)
{
	CL3RecordSetWrap rs = rsIron;
	if(rs.GetRowCount() < 1)
		return 0;

	// 检查铁水状态，已经使用的（IronStatus不为0）不能修改
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		// 剩余量
		rs.SetFieldByName(_T("Spare_Weight"),rs.GetFieldByName(_T("Net_Weight")));
		L3LONG nStatus = rs.GetFieldByName(_T("IronStatus")).ToLong();
		if(nStatus != CBFIron::ironNotProcessed)
		{	// 铁水已经处理
			SetL3LastError(XGMES_ERR_IRONINUSE);
			return -1;
		}
		rs.MoveNext();
	}

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	rs.MoveFirst();
	if(SetObjsPropValues(MATERIAL_BFIRON_URI,rs))
	{
		Commit(nTrans);
		// 触发预约事件
		EventIronChanged *= -1;
		return rs.GetRowCount();
	}
	else
	{
		Rollback(nTrans);
		return 0;
	}
}

/// <Method class="CBF_Iron_Mag" name="DeleteIronData" type="L3LONG">
/// 删除铁水数据
/// <Param name="rsIron" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::DeleteIronData(L3RECORDSET rsIron)
{
	CL3RecordSetWrap rs = rsIron;
	if(rs.GetRowCount() < 1)
		return 0;
	// 检查铁水状态，已经使用的（IronStatus不为0）不能删除
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		L3LONG nStatus = rs.GetFieldByName(_T("IronStatus")).ToLong();
		if(nStatus != CBFIron::ironNotProcessed)
		{
			SetL3LastError(XGMES_ERR_IRONINUSE);
			return -1;
		}
		rs.MoveNext();
	}

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	rs.AddField(MESPROP_MATERIAL_TYPE,L3VT_STRING);
	rs.AddField(MESPROP_AMOUNT,L3VT_DOUBLE);
	rs.AddField(_T("StoreAreaID"),L3VT_STRING);
	// 补齐字段信息
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(MESPROP_MATERIAL_TYPE,CL3Variant(_T("CBFIron")));
		// 库位
		rs.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON));
		// 库量
		rs.SetFieldByName(MESPROP_AMOUNT,CL3Variant((DOUBLE)1));
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!DeleteMaterials(rs))
	{
		Rollback(nTrans);
		return -1;
	}

	rs.MoveFirst();
	if(this->DeleteOldObjects(MATERIAL_BFIRON_URI,rs))
	{
		Commit(nTrans);
		// 触发预约事件
		EventIronChanged *= -1;
		return rs.GetRowCount();
	}
	else
	{
		Rollback(nTrans);
		return 0;
	}
	return 0;
}

/// <Method class="CBF_Iron_Mag" name="DesignatePath" type="L3LONG">
/// 铁水去向指定
/// <Param name="rsIron" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::DesignatePath(L3RECORDSET rsIron)
{
	CL3RecordSetWrap rs = rsIron;
	if(rs.GetRowCount() < 1)
		return 0;
	
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("Destination")) < 0 ||
		rs.GetFieldIndex(_T("IronStatus")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
	}

	//2009-06-30 tangyi 
	rs.DelField(_T("NC_Confirm_Flag"));
	rs.DelField(_T("Gross_Weight"));
	rs.DelField(_T("Last_Tare"));
	rs.DelField(_T("Curr_Tare"));
	rs.DelField(_T("Net_Weight"));
	rs.DelField(_T("Spare_Weight"));
	rs.DelField(_T("IronConfirm"));
	rs.DelField(_T("GrossFlag"));
	rs.DelField(_T("TareFlag"));
	rs.DelField(_T("AnalysisFlag"));

	//CL3RecordSetWrap rsToNC = rs.CloneStruct();

	// 检查和修改铁水状态
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		L3LONG nStatus = rs.GetFieldByName(_T("IronStatus")).ToLong();
		if(nStatus == CBFIron::ironArrived)
		{	// 铁水已经到达，不能修改去向
			SetL3LastError(XGMES_ERR_IRONINUSE);
			return -1;
		}
		L3LONG nDest = rs.GetFieldByName(_T("Destination")).ToLong();
		if(nDest == CBFIron::ironToNoWhere)
		{	// 无去向
			rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironNotProcessed));
		}
		else
		{	// 有去向
			rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironDestDefined));
		}
		//if(nDest == CBFIron::ironToCast)
		//{
		//	rsToNC.AppendRecord();
		//	rsToNC.CopyCurRowFrom(rs);
		//}
		rs.MoveNext();
	}

	// 修改
	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	//if(rsToNC.GetRowCount() > 0)
	//{
	//	rsToNC.MoveFirst();
	//	SendCastIronToNC(rsToNC);
	//}

	rs.MoveFirst();
	if(SetObjsPropValues(MATERIAL_BFIRON_URI,rs))
	{
		Commit(nTrans);
		// 触发预约事件
		EventIronChanged *= -1;
		return rs.GetRowCount();
	}
	else
	{
		Rollback(nTrans);
		return 0;
	}
}

/// <Method class="CBF_Iron_Mag" name="SendIronDataToNC" type="L3LONG">
/// 铁水上传NC
/// <Param name="strTapNo" type="L3STRING"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::SendIronDataToNC(L3STRING strTapNo)
{
	//2009-04-07 begin
	CString csTapNo = strTapNo;

	CString strSQL;
	strSQL.Format(_T("select * from CBFIron where TAP_No = '%s'"),csTapNo);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return -1;


	bool bSend = true;
	rs.MoveFirst();
	while (!rs.IsEOF())
	{
		L3LONG grossFlag = rs.GetFieldByName(_T("GrossFlag")).ToLong();
		L3LONG tareFlag = rs.GetFieldByName(_T("TareFlag")).ToLong();
		L3LONG analysisFlag = rs.GetFieldByName(_T("AnalysisFlag")).ToLong();
		L3LONG NCFlag = rs.GetFieldByName(_T("NC_Confirm_Flag")).ToLong();

		if ((grossFlag == 0) || (tareFlag == 0) || (analysisFlag == 0) || (NCFlag == 1))
		{
			bSend = false;
		}
		rs.MoveNext();
	}

	if (bSend)
	{
		//设置IronConfirm标志
		rs.MoveFirst();
		while (!rs.IsEOF())
		{
			CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
			if (!SetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csMaterialID,_T("IronConfirm"),(L3LONG)1))
				return -2;

			rs.MoveNext();
		}
		//设置NC_Iron_Event标志
		CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
		CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Iron_Event"));
		L3LONG nEvent = varEvent.ToLong();
		nEvent = (nEvent+1) % 9999;
		if (!SetObjectPropValue(csBaseUri,_T("NC_Iron_Event"),nEvent))
			return -3;
	}
	else
	{
		return -4;//整个铁次不满上传要求[毛重,皮重,成份不完整]

	}

	return 1;
}

/// <Method class="CBF_Iron_Mag" name="GetUnprocessedIrons" type="L3RECORDSET">
/// 返回未处理的铁水数据
/// </Method>
L3RECORDSET CBF_Iron_Mag::GetUnprocessedIrons()
{

	CString strSQL;
	//strSQL.Format(_T("select * from %s where Status != %d and NC_Confirm_Flag = '0' order by Production_Date desc"),MATERIAL_BFIRON_URI,(LONG)Material::Deleted);
	//2009-04-07
	strSQL.Format(_T("select * from %s where NC_Confirm_Flag = '0' or (IronStatus = 0  and Destination = 0) order by Production_Date desc"),MATERIAL_BFIRON_URI);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(MATERIAL_BFIRON_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CBF_Iron_Mag" name="GetIronsForDefineDest" type="L3RECORDSET">
/// 返回未到达的铁水
/// </Method>
L3RECORDSET CBF_Iron_Mag::GetIronsForDefineDest()
{
	CString strSQL;
	strSQL.Format(_T("select * from %s where Status != %d and (IronStatus = 1 or IronStatus = 0)"),MATERIAL_BFIRON_URI,(LONG)Material::Deleted);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(MATERIAL_BFIRON_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}


/// <Method class="CBF_Iron_Mag" name="QueryIronInfo" type="L3RECORDSET">
/// 根据时间段和去向查铁水信息
/// <Param name="timeFrom" type="L3DATETIME">起始时间</Param>
/// <Param name="timeTo" type="L3DATETIME">结束时间</Param>
/// <Param name="Destination" type="L3LONG">去向</Param>
/// </Method>
L3RECORDSET CBF_Iron_Mag::QueryIronInfo(L3DATETIME timeFrom, L3DATETIME timeTo, L3LONG Destination)
{
	CString strSQL;
	strSQL.Format(_T("select * from %s where Status != %d and (Production_Date between ? and ? and Destination = ?)"),MATERIAL_BFIRON_URI,(LONG)Material::Deleted);
	VARIANT params[3];
	params[0].vt = VT_DATE; params[0].date = timeFrom;
	params[1].vt = VT_DATE; params[1].date = timeTo;
	params[2].vt = VT_I4; params[2].lVal = Destination;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,3,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(MATERIAL_BFIRON_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CBF_Iron_Mag" name="GetMaxTAPNoByBFID" type="L3RECORDSET">
/// 按高炉分组获取最大铁次号。返回记录集包含字段BFID和TAP_No。
/// </Method>
L3RECORDSET CBF_Iron_Mag::GetMaxTAPNoByBFID()
{
	CString strSQL;
	//strSQL.Format(_T("select BFID,max(TAP_No) as TAPNo from %s where Status != %d and (Production_Date > ?) group by BFID"),
		//MATERIAL_BFIRON_URI,(LONG)Material::Deleted);2009-04-09
	strSQL.Format(_T("select BFID,max(TAP_No) as TAPNo from %s where (Production_Date > ?) group by BFID"),
		MATERIAL_BFIRON_URI);
	COleDateTime timeCur = COleDateTime::GetCurrentTime();
	COleDateTime timeOld = timeCur - COleDateTimeSpan(30,0,0,0);
	VARIANT params[1];
	params[0].vt = VT_DATE; params[0].date = (DATE)timeOld;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,1,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CBF_Iron_Mag" name="GetLastTareWeightByTPCNo" type="L3DOUBLE">
/// 根据罐号查询最近一次的皮重。
/// <Param name="nTPCNo" type="L3STRING">罐号</Param>
/// </Method>
L3DOUBLE CBF_Iron_Mag::GetLastTareWeightByTPCNo(L3STRING nTPCNo)
{
	CString strTPCNo = String_BSTR2TChar(nTPCNo);
	CString strSQL;
	strSQL.Format(_T("select * from (select Curr_Tare from %s where TPC_No = '%s' order by Production_Date desc) where rownum < 2"),
		MATERIAL_BFIRON_URI,(LPCTSTR)strTPCNo);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs) || rs.GetRowCount() < 1)
		return 0;
	else
	{
		rs.MoveFirst();
		CL3Variant val = rs.GetFieldByIndex(0);
		return val.ToDouble();
	}
}

/// <Method class="CBF_Iron_Mag" name="GetUnArrivedIrons" type="L3RECORDSET">
/// 返回已指定去向，但未到达确认的铁水数据。
/// <Param name="Destination" type="L3LONG">去向</Param>
/// </Method>
L3RECORDSET CBF_Iron_Mag::GetUnArrivedIrons(L3LONG Destination)
{
	CString strSQL;
	strSQL.Format(_T("select * from %s where Status != %d and IronStatus = %d and Destination = %d")
		,MATERIAL_BFIRON_URI,(LONG)Material::Deleted,(INT)CBFIron::ironDestDefined,Destination);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(MATERIAL_BFIRON_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CBF_Iron_Mag" name="ConfirmIronArrive" type="L3BOOL">
/// 确认铁水到达。根据去向进行不同的处理。
/// <Param name="rsIron" type="L3RECORDSET">确认已经到达的铁水记录</Param>
/// </Method>
L3BOOL CBF_Iron_Mag::ConfirmIronArrive(L3RECORDSET rsIron)
{
	CL3RecordSetWrap rs = rsIron;
	if(rs.GetRowCount() < 1)
		return FALSE;
	if(rs.GetFieldIndex(_T("IronStatus")) < 0)
		return FALSE;

	//2009-06-30 tangyi 
	rs.DelField(_T("NC_Confirm_Flag"));
	rs.DelField(_T("Gross_Weight"));
	rs.DelField(_T("Last_Tare"));
	rs.DelField(_T("Curr_Tare"));
	rs.DelField(_T("Net_Weight"));
	rs.DelField(_T("Spare_Weight"));
	rs.DelField(_T("IronConfirm"));
	rs.DelField(_T("GrossFlag"));
	rs.DelField(_T("TareFlag"));
	rs.DelField(_T("AnalysisFlag"));

	// 准备出库记录
	rs.AddField(_T("MaterialType"),VT_BSTR);
	rs.AddField(_T("Amount"),VT_R8);
	rs.AddField(_T("StoreAreaID"),VT_BSTR);
	rs.AddField(_T("Arrival_Time"),VT_DATE);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
		rs.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		rs.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON));
		rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironArrived));
		rs.SetFieldByName(_T("Arrival_Time"),COleDateTime::GetCurrentTime());
		rs.MoveNext();
	}

	// 将记录集按照去向分为两组，铸铁和炼钢
	CL3RecordSetWrap rsToCast,rsToBOF;
	rsToCast = rs.CloneStruct();
	rsToBOF = rs.CloneStruct();
	rsToCast.DelField(_T("GUID")); //2009-11-09
	rsToBOF.DelField(_T("GUID"));  //2009-11-09
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		LONG nDest = rs.GetFieldByName(_T("Destination")).ToLong();
		if(nDest == CBFIron::ironToBOF)
		{
			rsToBOF.AppendRecord();
			rsToBOF.CopyCurRowFrom(rs);
		}
		else
		{
			rsToCast.AppendRecord();
			rsToCast.CopyCurRowFrom(rs);
			// 对于去铸铁的铁水，标记其为删除
			rs.SetFieldByName(_T("Status"),CL3Variant((LONG)Material::Deleted));
		}
		rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironArrived));
		rs.MoveNext();
	}

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return FALSE;

	// 向炼钢出库
	if(rsToBOF.GetRowCount() > 0)
	{
		rsToBOF.MoveFirst();
		if(!OutputMaterials(rsToBOF))
		{
			Rollback(nTrans);
			return FALSE;
		}
	}
	// 向铸铁出库
	if(rsToCast.GetRowCount() > 0)
	{
		rsToCast.MoveFirst();
		CBSTR bstrCastCache = ::String_TChar2CBSTR(BFIronCastCache_URI);
		if(!OutputMaterialsTo(bstrCastCache.GetBuffer(TRUE),rsToCast))
		{
			Rollback(nTrans);
			return FALSE;
		}
	}

	// 修改铁水状态
	rs.MoveFirst();
	if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rs))
	{
		Rollback(nTrans);
		return FALSE;
	}

    /**设置脱硫铁水状态数据为离站 2009-10-23 Begin yao*********/
	CL3RecordSet *pDeSIrons = new CL3RecordSet();
	CL3RecordSetWrap rsDeSIrons; pDeSIrons->QueryInterface(IID_IL3RecordSet,rsDeSIrons); pDeSIrons->Release();
	rsDeSIrons.AddField(_T("MaterialID"),VT_BSTR);
	rsDeSIrons.AddField(_T("Status"),VT_I2);
	rsDeSIrons.AddField(_T("Source"),VT_I4);

	rsDeSIrons.CopyFrom(rs);
	rsDeSIrons.MoveFirst();
	while(!rsDeSIrons.IsEOF())
	{
		L3LONG nSource = rsDeSIrons.GetFieldByName(_T("Source")).ToLong();
		if(nSource == 1)
		{
			CString cstrMaterial = rsDeSIrons.GetFieldByName(_T("MaterialID")).ToCString();
			if(cstrMaterial.GetLength() > 9)
			{
				CString csDeSUri = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,cstrMaterial);
				if(!SetObjectPropValue(csDeSUri,_T("Status"),CL3Variant((LONG)CDeS_Base_Data::ironUsed)))
				{
					if(nTrans > 0)
    					Rollback(nTrans);
					return FALSE;
				}
			}
		}
		rsDeSIrons.MoveNext();
	}
	/***********2009-10-23 End ********/



	Commit(nTrans);

	// 触发预约事件
	EventIronChanged *= -1;

	return TRUE;
}

/// <Method class="CBF_Iron_Mag" name="SetIronTare" type="L3LONG">
/// 设置铁次罐号皮重
/// <Param name="strTapNo" type="L3STRING"></Param>
/// <Param name="strTpcNo" type="L3STRING"></Param>
/// <Param name="fTare" type="L3FLOAT"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::SetIronTare(L3STRING strTapNo,L3STRING strTpcNo,L3FLOAT fTare)
{
    if ((strTapNo == NULL) || (strTpcNo == NULL) || (fTare < 1))
	{
		return -1;
	}

	CString csTapNo = strTapNo;
	CString csTpcNo = strTpcNo;

	L3FLOAT fGrossWeight = 0;
	fGrossWeight = (GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csTapNo+csTpcNo,_T("Gross_Weight"))).ToFloat();
    if (fGrossWeight < 1)
	{
		return -2;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	if (!SetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csTapNo+csTpcNo,_T("Curr_Tare"),(L3FLOAT)fTare))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}
	if (!SetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csTapNo+csTpcNo,_T("Net_Weight"),(L3FLOAT)(fGrossWeight-fTare)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	if(bUseTrans)
		Commit(nTrans);
	
	return 0;
}

/// <Method class="CBF_Iron_Mag" name="GetBFChemicalData" type="L3RECORDSET">
/// 通过铁次罐号获取铁水成份数据。
/// <Param name="strTapNo" type="L3STRING">铁次号</Param>
/// <Param name="strTpcNo" type="L3STRING">罐号</Param>
/// </Method>
L3RECORDSET CBF_Iron_Mag::GetBFChemicalData(L3STRING strTapNo,L3STRING strTpcNo)
{
	CString csTapNo = strTapNo;
	CString csTpcNo = strTpcNo;
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Iron_Element where TAP_No = '%s' and TPC_No = '%s' and Sample_Type = 'TS'")
		          ,csTapNo,csTpcNo);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;

	int rsCount = rs.GetRowCount();
	if (rsCount > 0)
	{
		return rs.Detach();
	}

	strSQL.Format(_T("select * from CQA_Iron_Element where TAP_No = '%s'and Sample_Type <> 'TS'")
		          ,csTapNo);
	CL3RecordSetWrap rstemp;
	if(!Query(strSQL,rstemp))
		return NULL;

	//rsCount = rstemp.GetRowCount();
	//if (rsCount > 0)
	//{
		return rstemp.Detach();
	//}
	//else
	//	return NULL;
}

/// <Method class="CBF_Iron_Mag" name="NewIronInfo" type="L3LONG">
/// 新增铁水信息
/// ARG&gt;&gt; rsIron : 铁水信息。必须包含TAP_No,TPC_No字段。
/// RET &lt;&lt; 成功返回1；失败返回出错代码。
/// <Param name="rsIron" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::NewIronInfo(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	L3LONG rscount = rs.GetRowCount();
	if (rscount < 1)
	{
		return -1;
	}

	CL3RecordSetWrap rsIron;
	if(!CreateClassPropSet(MATERIAL_BFIRON_URI,rsIron))
	{
		return -2;
	}

	rsIron.AddField(_T("MaterialType"),VT_BSTR);
	rsIron.AddField(_T("Amount"),VT_R8);
	rsIron.AddField(_T("StoreAreaID"),VT_BSTR);
	rsIron.AddField(_T("DeSFlag"),VT_I4);//2009-11-05
	
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	COleDateTime dtCreateTime = COleDateTime::GetCurrentTime();//2009-04-23 新增

	//准备铁水数据
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString cstrTPCNo = rs.GetFieldByName(_T("TPC_No")).ToCString();
		CString csName = rs.GetFieldByName(_T("Name")).ToCString();
		if (cstrTPCNo.GetLength() < 1)
		{
			return -3;
		}
		CString strID;
		while (cstrTPCNo.FindOneOf(_T(",")) != -1)
		{
			rsIron.AppendRecord();
			rsIron.MoveLast();
			rsIron.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CBFIron")));
			rsIron.SetFieldByName(_T("Amount"),CL3Variant(_T("1")));
			rsIron.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON));
			rsIron.SetFieldByName(_T("DeSFlag"),CL3Variant((LONG)0));//2009-11-05
			// 计算材料号
			CString cstrTPC_No = cstrTPCNo.Left(cstrTPCNo.FindOneOf(_T(",")));

			L3LONG itpcno=0;
			try
			{
				itpcno = _ttoi(cstrTPC_No);
			}
			catch(...)
			{
			}
			cstrTPC_No.Format(_T("%02d"),itpcno);
			strID = cstrTapNo + cstrTPC_No;
			rsIron.SetFieldByName(_T("Name"),CL3Variant(csName));
			rsIron.SetFieldByName(_T("MaterialID"),CL3Variant(strID));
			rsIron.SetFieldByName(_T("BFID"),CL3Variant(cstrTapNo.Mid(1,1)));
			rsIron.SetFieldByName(_T("TAP_No"),CL3Variant(cstrTapNo));
			rsIron.SetFieldByName(_T("TPC_No"),CL3Variant(cstrTPC_No));
			// 初始状态
			rsIron.SetFieldByName(_T("Status"),CL3Variant((LONG)Material::Normal));
			rsIron.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironNotProcessed));
			// 入库库位
			rsIron.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON));
			// 入库量
			rsIron.SetFieldByName(MESPROP_AMOUNT,CL3Variant((DOUBLE)1));

			rsIron.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsIron.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsIron.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//2009-04-09
			//rsIron.SetFieldByName(_T("Production_Date"),CL3Variant(COleDateTime::GetCurrentTime()));//2009-04-23 屏蔽
			rsIron.SetFieldByName(_T("Production_Date"),CL3Variant(dtCreateTime));
			rsIron.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironNotProcessed));

			//2009-04-10 begin
			L3STRING bstrTpcNo = cstrTPC_No.AllocSysString();
			L3DOUBLE flastTareWeight = GetLastTareWeightByTPCNo(bstrTpcNo);
		    L3SysFreeString(bstrTpcNo);
			if (flastTareWeight < 1) 
				flastTareWeight = 47;
			rsIron.SetFieldByName(_T("Last_Tare"),(L3FLOAT)flastTareWeight);
			//2009-04-10 end

			cstrTPCNo = cstrTPCNo.Mid(cstrTPCNo.FindOneOf(_T(","))+1,cstrTPCNo.GetLength() - cstrTPCNo.FindOneOf(_T(",")) - 1);
		}

		rsIron.AppendRecord();
		rsIron.MoveLast();
		rsIron.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CBFIron")));
		rsIron.SetFieldByName(_T("Amount"),CL3Variant(_T("1")));
		rsIron.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON));

		L3LONG ltpcno=0;
		try
		{
			ltpcno = _ttoi(cstrTPCNo);
		}
		catch(...)
		{
		}
		cstrTPCNo.Format(_T("%02d"),ltpcno);
		strID = cstrTapNo + cstrTPCNo;
		rsIron.SetFieldByName(_T("Name"),CL3Variant(csName));
		rsIron.SetFieldByName(_T("MaterialID"),CL3Variant(strID));
		rsIron.SetFieldByName(_T("BFID"),CL3Variant(cstrTapNo.Mid(1,1)));
		rsIron.SetFieldByName(_T("TAP_No"),CL3Variant(cstrTapNo));
		rsIron.SetFieldByName(_T("TPC_No"),CL3Variant(cstrTPCNo));
		rsIron.SetFieldByName(_T("Status"),CL3Variant((LONG)Material::Normal));
		rsIron.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironNotProcessed));
		// 入库库位
		rsIron.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON));
		rsIron.SetFieldByName(_T("DeSFlag"),CL3Variant((LONG)0)); //2009-11-05
		// 入库量
		rsIron.SetFieldByName(MESPROP_AMOUNT,CL3Variant((DOUBLE)1));

		rsIron.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsIron.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsIron.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//2009-04-09
		//rsIron.SetFieldByName(_T("Production_Date"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsIron.SetFieldByName(_T("Production_Date"),CL3Variant(dtCreateTime));
		rsIron.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironNotProcessed));
		//2009-04-10 begin
		L3STRING brTpcNo = cstrTPCNo.AllocSysString();
		L3FLOAT flastTareWeight = GetLastTareWeightByTPCNo(brTpcNo);
	    L3SysFreeString(brTpcNo);
		if (flastTareWeight < 1) 
			flastTareWeight = 47;
		rsIron.SetFieldByName(_T("Last_Tare"),(L3FLOAT)flastTareWeight);//2009-04-10
		//2009-04-10 end
        
		rs.MoveNext();

	}

	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -4;
	}

	// 创建铁水材料
	rsIron.MoveFirst();
	LONG nRet = CreateNewObjects(MATERIAL_BFIRON_URI,rsIron);
	if(nRet < rsIron.GetRowCount())
	{
		if(nTrans > 0)
		   Rollback(nTrans);
		return -5;
	}
	
	// 将新建的铁水入库
	rsIron.MoveFirst();
	if(!InputMaterials(rsIron))
	{
		if(nTrans > 0)
		   Rollback(nTrans);
		return -6;
	}


	if(nTrans > 0)
	   Commit(nTrans);

	// 触发预约事件
	EventIronChanged *= -1;

	//制定铁沟样委托单并下传检化验
	CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatChemicalData_Mag\\QA_HeatChemicalData_Mag"),_T("NewBFIronSheet"),(L3RECORDSET)rs);
	if(valRet.IsError() || valRet.IsNull() || (valRet.ToLong() < 1))
	{
		return -7;
	}

	//制定渣样委托单并下传检化验
	CL3Variant valSlagRet = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatChemicalData_Mag\\QA_HeatChemicalData_Mag"),_T("NewBFSlagSheet"),(L3RECORDSET)rs);
	if(valSlagRet.IsError() || valSlagRet.IsNull() || (valSlagRet.ToLong() < 1))
	{
		return -8;
	}
	//2009-04-08
	//rsIron.MoveFirst();
	//while(!rsIron.IsEOF())
	//{
	//	CString cstrTapNo = rsIron.GetFieldByName(_T("TAP_No")).ToCString();
	//	CString cstrTPCNo = rsIron.GetFieldByName(_T("TPC_No")).ToCString();

	//	SendIronDataToWeight(cstrTapNo,cstrTPCNo);

	//	rsIron.MoveNext();
	//}
	return rs.GetRowCount();
}


//L3LONG CBF_Iron_Mag::RetoLab(L3RECORDSET rsData)
//{
//	CL3RecordSetWrap rs = rsData;
//	L3LONG rscount = rs.GetRowCount();
//	if (rscount < 1)
//	{
//		return -1;
//	}
//
//	//制定铁沟样委托单并下传检化验
//	CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatChemicalData_Mag\\QA_HeatChemicalData_Mag"),_T("NewBFIronSheet"),(L3RECORDSET)rs);
//	if(valRet.IsError() || valRet.IsNull() || (valRet.ToLong() < 1))
//	{
//		return -7;
//	}
//
//	//制定渣样委托单并下传检化验
//	CL3Variant valSlagRet = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatChemicalData_Mag\\QA_HeatChemicalData_Mag"),_T("NewBFSlagSheet"),(L3RECORDSET)rs);
//	if(valSlagRet.IsError() || valSlagRet.IsNull() || (valSlagRet.ToLong() < 1))
//	{
//		return -8;
//	}
//	//2009-04-08
//	//rsIron.MoveFirst();
//	//while(!rsIron.IsEOF())
//	//{
//	//	CString cstrTapNo = rsIron.GetFieldByName(_T("TAP_No")).ToCString();
//	//	CString cstrTPCNo = rsIron.GetFieldByName(_T("TPC_No")).ToCString();
//
//	//	SendIronDataToWeight(cstrTapNo,cstrTPCNo);
//
//	//	rsIron.MoveNext();
//	//}
//	return rs.GetRowCount();
//}

/// <Method class="CBOF_Unit_Mag" name="AcceptWeightData" type="L3BOOL">
/// 接收铁水罐重量数据 2009-03-30
/// <Param name="rsData" type="L3RECORDSET">重量数据</Param>
/// </Method>
L3BOOL CBF_Iron_Mag::AcceptWeightData(L3RECORDSET rsData)
{
	//2010-01-04 取消事务管理

	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	//LONG nTrans = 0;
	//if(!IsInTrans())
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return FALSE;
	//}

	rs.MoveFirst();
	while (!rs.IsEOF())
	{
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		if (cstrTapNo.GetLength() < 1)
		{
			rs.MoveNext();
			continue;
		}

		CString cstrTpcNo = rs.GetFieldByName(_T("TPC_No")).ToCString();
		if (cstrTpcNo.GetLength() < 1)
		{
			rs.MoveNext();
			continue;
		}
		L3LONG ltpcno=0;
		try
		{
			ltpcno = _ttoi(cstrTpcNo);
		}
		catch(...)
		{
		}
		cstrTpcNo.Format(_T("%02d"),ltpcno);
		L3FLOAT fWeight = rs.GetFieldByName(_T("Weight")).ToFloat();
		L3LONG iMode = rs.GetFieldByName(_T("WeightMode")).ToLong();
		CString cstrID = cstrTapNo + cstrTpcNo;
		if (iMode == 1) //毛重
		{
			L3LONG iGrossFlag = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+cstrID,_T("GrossFlag")).ToLong();
			if (iGrossFlag < 1)
			{
				CL3RecordSet *pRS = new CL3RecordSet();
				CL3RecordSetWrap rsGross; pRS->QueryInterface(IID_IL3RecordSet,rsGross); pRS->Release();
				rsGross.AddField(_T("Gross_Weight"),VT_R4);
				rsGross.AddField(_T("Spare_Weight"),VT_R4);
				rsGross.AddField(_T("Destination"),VT_I4);
				rsGross.AddField(_T("IronStatus"),VT_I4);
				rsGross.AddField(_T("GrossFlag"),VT_I4);
				rsGross.AddField(_T("Net_Weight"),VT_R4);

				rsGross.AppendRecord();
				L3FLOAT fLastTareWeight = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+cstrID,_T("Last_Tare")).ToFloat();
				rsGross.SetFieldByName(_T("Gross_Weight"),(L3FLOAT)(fWeight));
				rsGross.SetFieldByName(_T("Spare_Weight"),(L3FLOAT)(fWeight-fLastTareWeight));
				rsGross.SetFieldByName(_T("Destination"),(L3LONG)1);
				rsGross.SetFieldByName(_T("IronStatus"),(L3LONG)1);
				rsGross.SetFieldByName(_T("GrossFlag"),(L3LONG)1);
				rsGross.SetFieldByName(_T("Net_Weight"),(L3FLOAT)(fWeight-fLastTareWeight));

				SetObjPropValues(_T("MES\\MaterialData\\CBFIron\\")+cstrID,rsGross);

				//if (SetObjPropValues(_T("MES\\MaterialData\\CBFIron\\")+cstrID,rsGross) < 6)
				//{
				//	////if(nTrans > 0)
				//	////	Rollback(nTrans);
				//	return FALSE;
				//}

				L3STRING bstrID = cstrID.AllocSysString();	
				Complete(bstrID);

				//if (!Complete(bstrID))
				//{
				//	//if(nTrans > 0)
				//	//	Rollback(nTrans);
				//	L3SysFreeString(bstrID);
				//	return FALSE;
				//}
				L3SysFreeString(bstrID);

				//2009-11-08 begin
				L3LONG nDeSFlag = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+cstrID,_T("DeSFlag")).ToLong();
				if(nDeSFlag == 1)
				{
					//若正在脱硫,则设置脱硫铁水重量信息
					CL3RecordSet *pDeS = new CL3RecordSet();
					CL3RecordSetWrap rsDeS; pDeS->QueryInterface(IID_IL3RecordSet,rsDeS); pDeS->Release();
					rsDeS.AddField(_T("Gross_Weight"),VT_R4);
					rsDeS.AddField(_T("Estimate_Weight"),VT_R4);
					rsDeS.AddField(_T("Net_Weight"),VT_R4);

					rsDeS.AppendRecord();
					rsDeS.SetFieldByName(_T("Gross_Weight"),(L3FLOAT)(fWeight));
					rsDeS.SetFieldByName(_T("Estimate_Weight"),(L3FLOAT)(fWeight-fLastTareWeight));
					rsDeS.SetFieldByName(_T("Net_Weight"),(L3FLOAT)(fWeight-fLastTareWeight));

					SetObjPropValues(_T("XGMESLogic\\DeSMag\\CDeS_Base_Data\\")+cstrID,rsDeS);

					//if (SetObjPropValues(_T("XGMESLogic\\DeSMag\\CDeS_Base_Data\\")+cstrID,rsDeS) < 3)
					//{
					//	//if(nTrans > 0)
					//	//	Rollback(nTrans);
					//	return FALSE;
					//}
				}
				//2009-11-08 End
			}
		}
		else
		{
			L3LONG iTareFlag = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+cstrID,_T("TareFlag")).ToLong();
			if (iTareFlag < 1)
			{
			    L3FLOAT fGrossWeight = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+cstrID,_T("Gross_Weight")).ToFloat();
			    L3FLOAT flastTare = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+cstrID,_T("Last_Tare")).ToFloat();//2009-04-15 获取上次皮重
			    L3FLOAT fspareWeight = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+cstrID,_T("Spare_Weight")).ToFloat();//2009-04-15 获取剩余重量
					
				CL3RecordSet *pRS = new CL3RecordSet();
				CL3RecordSetWrap rsTare; pRS->QueryInterface(IID_IL3RecordSet,rsTare); pRS->Release();
				rsTare.AddField(_T("Net_Weight"),VT_R4);
				rsTare.AddField(_T("Curr_Tare"),VT_R4);
				rsTare.AddField(_T("TareFlag"),VT_I4);
				rsTare.AddField(_T("Spare_Weight"),VT_R4);//2009-04-15

				rsTare.AppendRecord();
				rsTare.SetFieldByName(_T("Curr_Tare"),(L3FLOAT)(fGrossWeight-fWeight));
				rsTare.SetFieldByName(_T("Net_Weight"),(L3FLOAT)(fWeight));
				rsTare.SetFieldByName(_T("TareFlag"),(L3LONG)1);
				rsTare.SetFieldByName(_T("Spare_Weight"),(L3FLOAT)(fspareWeight+flastTare-(fGrossWeight-fWeight)));//2009-04-15 真实剩余重量

				SetObjPropValues(_T("MES\\MaterialData\\CBFIron\\")+cstrID,rsTare);

				//if (SetObjPropValues(_T("MES\\MaterialData\\CBFIron\\")+cstrID,rsTare) < 4)
				//{
				//	//if(nTrans > 0)
				//	//	Rollback(nTrans);
				//	return FALSE;
				//}

				L3STRING bstrID = cstrID.AllocSysString();
				Complete(bstrID);
				//if (!Complete(bstrID))
				//{
				//	//if(nTrans > 0)
				//	//	Rollback(nTrans);
				//	L3SysFreeString(bstrID);
				//	return FALSE;
				//}
				L3SysFreeString(bstrID);

				/******2009-10-25 Begin 设置脱硫铁水重量 yao*******/
				CString csDeSUri = _T("XGMESLogic\\DeSMag\\CDeS_Base_Data\\")+cstrID;
				L3LONG nDeSFlag = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+cstrID,_T("DeSFlag")).ToLong();
				if(nDeSFlag == 1)
				{
					SetObjectPropValue(csDeSUri,_T("Net_Weight"),(L3FLOAT)(fWeight));
					//if (!SetObjectPropValue(csDeSUri,_T("Net_Weight"),(L3FLOAT)(fWeight)))
					//{
					//	//if(nTrans > 0)
					//	//	Rollback(nTrans);
					//	return FALSE;
					//}
				}
				/******2009-10-25 End*******/
			}
		}

		rs.MoveNext();
	}

	//if(nTrans > 0)
	//  Commit(nTrans);

	return TRUE;	
}

/// <Method class="CBOF_Unit_Mag" name="Complete" type="L3BOOL">
/// 铁水完工 2009-03-30
/// <Param name="rsData" type="L3RECORDSET">重量数据</Param>
/// </Method>
L3BOOL CBF_Iron_Mag::Complete(L3STRING strID)
{
	//2009-06-22 修改如下 
	CString cstrID = strID;
	CString csTapNo =cstrID.Left(9);

	CString strSQL;
	strSQL.Format(_T("select * from CBFIron where TAP_No = '%s'"),csTapNo);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return FALSE;

	bool bSend = true;
	rs.MoveFirst();
	while (!rs.IsEOF())
	{
		L3LONG grossFlag = rs.GetFieldByName(_T("GrossFlag")).ToLong();
		L3LONG tareFlag = rs.GetFieldByName(_T("TareFlag")).ToLong();
		L3LONG analysisFlag = rs.GetFieldByName(_T("AnalysisFlag")).ToLong();
		L3LONG NCFlag = rs.GetFieldByName(_T("NC_Confirm_Flag")).ToLong();

		if ((grossFlag == 0) || (tareFlag == 0) || (analysisFlag == 0) || (NCFlag == 1))
		{
			bSend = false;
		}
		rs.MoveNext();
	}

	if (bSend)
	{
		//设置IronConfirm标志
		rs.MoveFirst();
		while (!rs.IsEOF())
		{
			CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
			if (!SetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csMaterialID,_T("IronConfirm"),(L3LONG)1))
				return FALSE;

			rs.MoveNext();
		}
		//设置NC_Iron_Event标志
		CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
		CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Iron_Event"));
		L3LONG nEvent = varEvent.ToLong();
		nEvent = (nEvent+1) % 9999;
		if (!SetObjectPropValue(csBaseUri,_T("NC_Iron_Event"),nEvent))
			return FALSE;
	}


	EventIronChanged *= -1;

	return TRUE;	
}

/// <Method class="CBF_Iron_Mag" name="SendIronDataToWeight" type="L3BOOL">
/// 将铁水信息下传PLC 2009-03-31
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL  CBF_Iron_Mag::SendIronDataToWeight(LPCTSTR strTapNo,LPCTSTR strTpcNo)
{
	//组建数据集
	CL3RecordSet *pRSheet = new CL3RecordSet();
	CL3RecordSetWrap rsData; pRSheet->QueryInterface(IID_IL3RecordSet,rsData); rsData->Release();
	rsData.AddField(_T("TAP_NO"),VT_BSTR);
	rsData.AddField(_T("TPC_NO"),VT_BSTR);
	rsData.AddField(_T("USEDFLAG"),VT_INT);
	rsData.AddField(_T("CREATETIME"),VT_BSTR);
	rsData.AddField(_T("PERMIT_DELETE_FLAG"),VT_INT);

	rsData.AppendRecord();
	rsData.SetFieldByName(_T("TAP_NO"),CL3Variant(strTapNo));
	L3LONG ltpcno=0;
	try
	{
		ltpcno = _ttoi(strTpcNo);
	}
	catch(...)
	{
	}
	CString cstrtpcno;
	cstrtpcno.Format(_T("%2d"),ltpcno);
	rsData.SetFieldByName(_T("TPC_NO"),CL3Variant(cstrtpcno));
	rsData.SetFieldByName(_T("USEDFLAG"),L3LONG(0));
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	rsData.SetFieldByName(_T("CREATETIME"),CL3Variant(curTime.Format(_T("%Y-%m-%d %H:%M:%S"))));
	rsData.SetFieldByName(_T("PERMIT_DELETE_FLAG"),L3LONG(1));

	L3LONG nPosID = 3;
	CString csTableName = _T("TB_IRONINFO");
	L3STRING strTableName = csTableName.AllocSysString();
	InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
					    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
						strTableName,(L3RECORDSET)rsData);
	L3SysFreeString(strTableName);

	return true;
}

/// <Method class="CBF_Iron_Mag" name="SendBackIrons" type="L3LONG">
/// 铁水回退
/// <Param name="rsIrons" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::SendBackIrons(L3RECORDSET rsIrons)
{
	CL3RecordSetWrap rs = rsIrons;
	if(rs.GetRowCount() < 1)
		return 0;
	
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("IronStatus")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
	}
	
	//2009-05-14 tangyi 添加铁水回退日志
	CL3RecordSetWrap rsBackIronData;
	if(!CreateClassPropSet(_T("XGMESLogic\\BFMag\\CBF_Iron_Back_Log"),rsBackIronData))
		return -1;
	rsBackIronData.DelField(_T("GUID"));
	rsBackIronData.CopyFrom(rs);

	//2009-06-30 tangyi 
	rs.DelField(_T("NC_Confirm_Flag"));
	rs.DelField(_T("Gross_Weight"));
	rs.DelField(_T("Last_Tare"));
	rs.DelField(_T("Curr_Tare"));
	rs.DelField(_T("Net_Weight"));
	rs.DelField(_T("Spare_Weight"));
	rs.DelField(_T("IronConfirm"));
	rs.DelField(_T("GrossFlag"));
	rs.DelField(_T("TareFlag"));
	rs.DelField(_T("AnalysisFlag"));


	// 检查和修改水状态
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		L3LONG nStatus = rs.GetFieldByName(_T("IronStatus")).ToLong();
		if(nStatus != 1)
		{	// 铁水未到达，不能回退
			SetL3LastError(XGMES_ERR_IRONINUSE);
			return -1;
		}

    	rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)0));
		rs.SetFieldByName(_T("Destination"),CL3Variant((LONG)0));
		rs.MoveNext();
	}

	// 修改
	LONG nTrans = 0;
	if(!IsInTrans())
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rs.MoveFirst();
	if(!SetObjsPropValues(MATERIAL_BFIRON_URI,(L3RECORDSET)rs))
	{
		if(nTrans > 0)
		Rollback(nTrans);
		return 0;
	
	}

    /**设置脱硫铁水状态数据为离站 2009-10-23 Begin yao*********/
	CL3RecordSet *pDeSIrons = new CL3RecordSet();
	CL3RecordSetWrap rsDeSIrons; pDeSIrons->QueryInterface(IID_IL3RecordSet,rsDeSIrons); pDeSIrons->Release();
	rsDeSIrons.AddField(_T("MaterialID"),VT_BSTR);
	rsDeSIrons.AddField(_T("Status"),VT_BSTR);
	rsDeSIrons.AddField(_T("Source"),VT_I4);

	rsDeSIrons.CopyFrom(rs);
	rsDeSIrons.MoveFirst();
	while(!rsDeSIrons.IsEOF())
	{
		L3LONG nSource = rsDeSIrons.GetFieldByName(_T("Source")).ToLong();
		if(nSource == 1)
		{
			CString cstrMaterial = rsDeSIrons.GetFieldByName(_T("MaterialID")).ToCString();
			if(cstrMaterial.GetLength() > 9)
			{
				CString csDeSUri = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,cstrMaterial);
				if(!SetObjectPropValue(csDeSUri,_T("Status"),CL3Variant((LONG)CDeS_Base_Data::ironEndRemoveSlag)))
				{
					if(nTrans > 0)
    					Rollback(nTrans);
					return FALSE;
				}
			}
		}

		rsDeSIrons.MoveNext();
	}
	
	rsDeSIrons.MoveFirst();
	if(!SetObjsPropValues(CDES_BASE_URI,rsDeSIrons))
	{
		if(nTrans > 0)
    		Rollback(nTrans);
		return 0;
	}
	/***********2009-10-23 End ********/

	//2009-05-14 tangyi 添加铁水回退日志
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	COleDateTime dtCreateTime = COleDateTime::GetCurrentTime();

	rsBackIronData.MoveFirst();
	while(!rsBackIronData.IsEOF())
	{
		rsBackIronData.SetFieldByName(_T("Back_Operator"),CL3Variant(GetCurrentUser()));
		rsBackIronData.SetFieldByName(_T("Back_Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsBackIronData.SetFieldByName(_T("Back_Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsBackIronData.SetFieldByName(_T("Back_Time"),CL3Variant(dtCreateTime));
		rsBackIronData.MoveNext();
	}

	rsBackIronData.MoveFirst();

	if(CreateNewObjects(_T("XGMESLogic\\BFMag\\CBF_Iron_Back_Log"),rsBackIronData) < rsBackIronData.GetRowCount())
	{
		if(nTrans > 0)
		Rollback(nTrans);
		return 0;
	
	}


	if(nTrans > 0)
		Commit(nTrans);

	EventIronChanged *= -1;

	rs.MoveFirst();
	L3LONG n =rs.GetRowCount();
	return n;
}

/// <Method class="CBF_Iron_Mag" name="SendBackArrivedIrons" type="L3LONG">
/// 铁水回退
/// <Param name="rsIrons" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::SendBackArrivedIrons(L3RECORDSET rsIrons)
{
	CL3RecordSetWrap rs = rsIrons;
	if(rs.GetRowCount() < 1)
		return 0;
	
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("IronStatus")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
	}

	rs.AddField(_T("MaterialType"),VT_BSTR);
	rs.AddField(_T("Amount"),VT_R8);
	rs.AddField(_T("StoreAreaID"),VT_BSTR);

	//2009-06-30 tangyi 
	rs.DelField(_T("NC_Confirm_Flag"));
	rs.DelField(_T("Gross_Weight"));
	rs.DelField(_T("Last_Tare"));
	rs.DelField(_T("Curr_Tare"));
	rs.DelField(_T("Net_Weight"));
	rs.DelField(_T("Spare_Weight"));
	rs.DelField(_T("IronConfirm"));
	rs.DelField(_T("GrossFlag"));
	rs.DelField(_T("TareFlag"));
	rs.DelField(_T("AnalysisFlag"));

	// 检查和修改铁水状态
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		L3LONG nStatus = rs.GetFieldByName(_T("IronStatus")).ToLong();
		if(nStatus != 2)
		{	// 铁水未到达，不能回退
			SetL3LastError(XGMES_ERR_IRONINUSE);
			return -1;
		}
		rs.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
		rs.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		rs.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON_CACHE));
		rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)0));
		rs.SetFieldByName(_T("Destination"),CL3Variant((LONG)0));

		rs.MoveNext();
	}

	// 修改
	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	rs.MoveFirst();
	CL3Variant valRet = InvokeObjectMethod(GetOutputCache(),_T("RemoveMaterials"),L3RECORDSET(rs));
	if(!valRet.ToBOOL())
	{	
    	if(nTrans > 0)
		   Rollback(nTrans);
		return 0;
	}
	CBSTR bstrCastCache = ::String_TChar2CBSTR(BFIronStoreArea_URI);
	valRet = InvokeObjectMethod(bstrCastCache,_T("AddMaterials"),L3RECORDSET(rs));
	if(!valRet.ToBOOL())
	{	
    	if(nTrans > 0)
	    	Rollback(nTrans);
		return 0;
	}


	rs.MoveFirst();
	if(SetObjsPropValues(MATERIAL_BFIRON_URI,rs))
	{
        /**设置脱硫铁水状态数据为离站 2009-10-23 Begin yao*********/
		CL3RecordSet *pDeSIrons = new CL3RecordSet();
		CL3RecordSetWrap rsDeSIrons; pDeSIrons->QueryInterface(IID_IL3RecordSet,rsDeSIrons); pDeSIrons->Release();
		rsDeSIrons.AddField(_T("MaterialID"),VT_BSTR);
		rsDeSIrons.AddField(_T("Status"),VT_BSTR);
		rsDeSIrons.AddField(_T("Source"),VT_I4);

		rsDeSIrons.CopyFrom(rs);
		rsDeSIrons.MoveFirst();
		while(!rsDeSIrons.IsEOF())
		{
			L3LONG nSource = rsDeSIrons.GetFieldByName(_T("Source")).ToLong();
			if(nSource == 1)
			{
				CString cstrMaterial = rsDeSIrons.GetFieldByName(_T("MaterialID")).ToCString();
				if(cstrMaterial.GetLength() > 9)
				{
					CString csDeSUri = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,cstrMaterial);
					if(!SetObjectPropValue(csDeSUri,_T("Status"),CL3Variant((LONG)CDeS_Base_Data::ironEndRemoveSlag)))
					{
						if(nTrans > 0)
    						Rollback(nTrans);
						return FALSE;
					}
				}
			}

			rsDeSIrons.MoveNext();
		}
		
		/***********2009-10-23 End ********/

		// 触发预约事件
     	if(nTrans > 0)
	    	Commit(nTrans);

		EventIronChanged *= -1;
		return rs.GetRowCount();
	}
	else
	{
    	if(nTrans > 0)
	    	Rollback(nTrans);
		return 0;
	}
}

/// <Method class="CBF_Iron_Mag" name="SendIronToCast" type="L3BOOL">
/// 设置铁水去铸铁
/// <Param name="rsIron" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBF_Iron_Mag::SendIronToCast(L3RECORDSET rsIron)
{
	CL3RecordSetWrap rs = rsIron;
	if(rs.GetRowCount() < 1)
		return FALSE;

	// 准备出库记录
	rs.AddField(_T("MaterialType"),VT_BSTR);
	rs.AddField(_T("Amount"),VT_R8);
	rs.AddField(_T("StoreAreaID"),VT_BSTR);

	//2009-06-30 tangyi 
	rs.DelField(_T("NC_Confirm_Flag"));
	rs.DelField(_T("Gross_Weight"));
	rs.DelField(_T("Last_Tare"));
	rs.DelField(_T("Curr_Tare"));
	//rs.DelField(_T("Net_Weight"));
	rs.DelField(_T("Spare_Weight"));
	rs.DelField(_T("IronConfirm"));
	rs.DelField(_T("AnalysisFlag"));

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
		rs.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		rs.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON));
		rs.SetFieldByName(_T("IronStatus"),CL3Variant((LONG)CBFIron::ironArrived));
		rs.SetFieldByName(_T("Destination"),CL3Variant((LONG)CBFIron::ironToCast));
		rs.SetFieldByName(_T("GrossFlag"),CL3Variant((LONG)1));
		rs.SetFieldByName(_T("TareFlag"),CL3Variant((LONG)1));
		rs.SetFieldByName(_T("Status"),CL3Variant((LONG)Material::Deleted));
		rs.MoveNext();
	}

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return FALSE;

	rs.MoveFirst();
	CL3Variant valRet = InvokeObjectMethod(BFIronStoreArea_URI,_T("RemoveMaterials"),L3RECORDSET(rs));
	if(!valRet.ToBOOL())
	{	
    	if(nTrans > 0)
		   Rollback(nTrans);
		return 0;
	}
	//CBSTR bstrCastCache = ::String_TChar2CBSTR(BFIronCastCache_URI);
	//valRet = InvokeObjectMethod(bstrCastCache,_T("AddMaterials"),L3RECORDSET(rs));
	//if(!valRet.ToBOOL())
	//{	
 //   	if(nTrans > 0)
	//    	Rollback(nTrans);
	//	return 0;
	//}

   // 修改铁水状态
	rs.MoveFirst();
	if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rs))
	{
     	if(nTrans > 0)
	    	Rollback(nTrans);
		return FALSE;
	}

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();

		L3STRING bstrMaterialID = csMaterialID.AllocSysString();
		if (!Complete(bstrMaterialID))
		{
			L3SysFreeString(bstrMaterialID);
        	if(nTrans > 0)
	    		Rollback(nTrans);
			return FALSE;
		}
		L3SysFreeString(bstrMaterialID);
    	rs.MoveNext();

	}


    if(nTrans > 0)
    	Commit(nTrans);

	// 触发预约事件
	EventIronChanged *= -1;

	return TRUE;
}

/// <Method class="CBF_Iron_Mag" name="MarkIronSource" type="L3LONG">
/// 标识铁水来源
/// <Param name="rsIrons" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBF_Iron_Mag::MarkIronSource(L3RECORDSET rsIrons)
{
	CL3RecordSetWrap rs = rsIrons;
	if(rs.GetRowCount() < 1)
		return 0;
	
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("IronStatus")) < 0 ||
		rs.GetFieldIndex(_T("Source")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
	}

	//2009-06-30 tangyi 
	rs.DelField(_T("NC_Confirm_Flag"));
	rs.DelField(_T("Gross_Weight"));
	rs.DelField(_T("Last_Tare"));
	rs.DelField(_T("Curr_Tare"));
	rs.DelField(_T("Net_Weight"));
	rs.DelField(_T("Spare_Weight"));
	rs.DelField(_T("IronConfirm"));
	rs.DelField(_T("GrossFlag"));
	rs.DelField(_T("TareFlag"));
	rs.DelField(_T("AnalysisFlag"));

	// 检查和修改铁水状态
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		L3LONG nStatus = rs.GetFieldByName(_T("IronStatus")).ToLong();
		if(nStatus == 2)
		{	// 铁水已到达，不能标识铁水来源
			SetL3LastError(XGMES_ERR_IRONINUSE);
			return -1;
		}
		rs.MoveNext();
	}

	// 修改
	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	rs.MoveFirst();
	if(SetObjsPropValues(MATERIAL_BFIRON_URI,rs))
	{
		// 触发预约事件
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


/// <Method class="CBF_Iron_Mag" name="GetUnprocessSampIrons" type="L3RECORDSET">
/// add by hyh 2012-04-12
/// 用于前台钢种成分报警显示铁水成分
/// </Method>
L3RECORDSET CBF_Iron_Mag::GetUnprocessSampIrons()
{
	CString strSQL;
	strSQL.Format(_T("select * from %s where NC_Confirm_Flag = '0' or (IronStatus = 0  and Destination = 0 and AnalysisFlag=1) order by Production_Date desc"),MATERIAL_BFIRON_URI);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

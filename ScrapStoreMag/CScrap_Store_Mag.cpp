// 逻辑类CScrap_Store_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CScrap_Store_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CScrap_Store_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CScrap_Store_Mag.h"

//当对象被装载到系统中时，被调用
void CScrap_Store_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CScrap_Store_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 返回入库缓冲区的URI
/// </summary>
CString CScrap_Store_Mag::GetInputCache()
{
	// TODO: 在此处编辑相关功能的处理代码

	return SCRAP_STORE_INCACHE_OBJ_URI;
}

/// <summary>
/// 返回出库缓冲区的URI
/// </summary>
CString CScrap_Store_Mag::GetOutputCache()
{
	// TODO: 在此处编辑相关功能的处理代码

	return SCRAP_STORE_OUTCACHE_OBJ_URI;
}

/// <summary>
/// 返回入库记录类型名称
/// </summary>
CString CScrap_Store_Mag::GetInputLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return SCRAP_IN_CLASS_URI;
}

/// <summary>
/// 返回出库记录类型名称
/// </summary>
CString CScrap_Store_Mag::GetOutputLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return SCRAP_OUT_CLASS_URI;
}

/// <summary>
/// 返回库位类型名称
/// </summary>
CString CScrap_Store_Mag::GetStoreAreaType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return _T("");
}

/// <summary>
///	初始化库房的属性
/// </summary>
BOOL CScrap_Store_Mag::InitializeStoreProperties()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::InitializeStoreProperties();
}

/// <summary>
/// 填充库位的初始化数据
/// </summary>
BOOL CScrap_Store_Mag::GetInitialAreaData(CL3RecordSetWrap& rs)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetInitialAreaData(rs);
}

/// <summary>
/// 在库房初始完成后调用。继承类重载此函数进行额外的初始化工作。
/// </summary>
void CScrap_Store_Mag::OnAfterStoreInitialized()
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::OnAfterStoreInitialized();
}

/// <summary>
/// 入库前预处理。在入库操作前调用。继承类可重载此方法进行预先的数据准备和处理
/// ARG >> rsInputInfo : 入库信息记录。
/// RET << TRUE 继续入库；FALSE 中断入库
/// </summary>
BOOL CScrap_Store_Mag::OnBeforeInputMaterials(L3RECORDSET rsInputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeInputMaterials(rsInputInfo);
}

/// <summary>
/// 入库后续处理。在入库操作成功后调用。继承类可重载此方法进行额外的处理。
/// ARG >> rsInputInfo : 入库信息记录。
/// RET << 成功返回TRUE；失败返回FALSE；
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMaterialsInputted(L3RECORDSET rsInputInfo)
{
	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);
	return TRUE;
}

/// <summary>
/// 出库前预处理。在出库操作前调用。继承类可重载此方法进行预先的数据准备和处理
/// ARG >> rsOutputInfo : 出库信息记录。
/// RET << TRUE 继续出库；FALSE 中断出库
/// </summary>
BOOL CScrap_Store_Mag::OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeOutputMaterials(rsOutputInfo);
}

/// <summary>
/// 出库后续处理。在出库操作成功后调用。继承类可重载此方法进行额外的处理。
/// ARG >> rsOutputInfo : 出库信息记录。
/// RET << 成功返回TRUE；失败返回FALSE；
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo)
{
	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//2009-04-08 tangyi将废钢生铁从出库缓存中移去,删除垃圾数据
	//2009-04-10 tangyi屏蔽废钢有撤销出库操作，故不能删除
	//CString csOutObj = GetOutputCache();
	//InvokeObjectMethod(csOutObj,_T("RemoveMaterials"),rsOutputInfo);
	return TRUE;
}

/// <summary>
/// 人工增加库存前预处理。在进行人工增加库存前调用。继承类可重载此方发进行预先数据准备和处理
/// ARG	>> rsMaterialInfo : 新增材料信息记录。
/// RET << 返回TRUE继续处理；返回FALSE中断。
/// </summary>
BOOL CScrap_Store_Mag::OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeAddMaterials(rsMaterialInfo);
}

/// <summary>
/// 人工增加库存后续处理。在进行人工增加库存后调用。继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 新增的材料信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsAdded(rsMaterialInfo);
}

/// <summary>
/// 人工删除库存前预处理。在进行人工删除库存前调用。继承类可重载此方发进行预先数据准备和处理
/// ARG	>> rsMaterialInfo : 删除材料信息记录。
/// RET << 返回TRUE继续处理；返回FALSE中断。
/// </summary>
BOOL CScrap_Store_Mag::OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeDeleteMaterials(rsMaterialInfo);
}

/// <summary>
/// 人工删除库存后续处理。在进行人工删除库存后调用。继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 删除的材料信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo)
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
BOOL CScrap_Store_Mag::OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// 移库后续处理。
/// ARG >> rsMaterialInfo : 删除的材料信息记录。
/// RET << << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CScrap_Store_Mag::OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// 入库记录预处理。继承类可重载此方法在入库前检查或处理入库记录
/// </summary>
void CScrap_Store_Mag::PrepareInputLog(L3RECORDSET rsInputLog)
{
	CL3RecordSetWrap rs = rsInputLog;
	//获取班别班次信息
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//班别、班次
		rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));		
		rs.MoveNext();
	}
}

/// <summary>
/// 出库记录预处理。继承类可重载此方法在出库前检查或处理出库记录
/// </summary>
void CScrap_Store_Mag::PrepareOutputLog(L3RECORDSET rsOutputLog)
{
	CL3RecordSetWrap rs = rsOutputLog;
	//获取班别班次信息
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rs.MoveFirst();
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	while(!rs.IsEOF())
	{
		//班别、班次
		rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rs.SetFieldByName(_T("LogDate"),CL3Variant(curTime));
		//2009-03-08 tangyi 废钢斗号加上时间后缀
		CString csScrapSlotID = rs.GetFieldByName(_T("Scrap_Slot_ID")).ToCString();		
		CString strIronID;
		strIronID.Format(_T("%s_%04d%02d%02d%02d%02d%02d"),(LPCTSTR)csScrapSlotID,curTime.GetYear(),curTime.GetMonth(),curTime.GetDay(),curTime.GetHour(),curTime.GetMinute(),curTime.GetSecond());
		rs.SetFieldByName(_T("Scrap_Slot_ID"),CL3Variant(strIronID));
		rs.MoveNext();
	}
}

/// <summary>
/// 返回指定编号的库位对象的URI
/// </summary>
CString CScrap_Store_Mag::GetAreaURI(LPCTSTR lpcszAreaID)
{
	// TODO: 在此处编辑相关功能的处理代码
	CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\");
	csAreaUri+=lpcszAreaID;

	return  csAreaUri;
}

/// <Method class="CScrap_Store_Mag" name="ScrapDataAccept" type="L3BOOL">
/// 
/// 接收NC废钢数据,加入input缓存,与材料表,接收电文表
/// ARG&gt;&gt; rsScrapData:废钢生铁信息.
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CScrap_Store_Mag::ScrapDataAccept(L3RECORDSET rsScrapData)
{
	CL3RecordSetWrap rsData =rsScrapData;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//判断废钢来料信息
	//CString csTelType;
	//if(rsData.GetFieldIndex(_T("vbillcode")) < 0)//入库单号
	//	csTelType = SCRAP_TRANS_TEL_CLASS_URI;
	//else
	//	csTelType = SCRAP_PUR_TEL_CLASS_URI;

	//CL3RecordSetWrap rsTelData;
	//if(!CreateClassPropSet(csTelType,rsTelData))
	//	return -1;

	//rsTelData.DelField(_T("GUID"));
	////rsTelData.AddField(_T("Rec_Time"),VT_DATE);
	//rsTelData.CopyFrom(rsData);
	//rsTelData.MoveFirst();
	//while(!rsTelData.IsEOF())
	//{
	//	rsTelData.SetFieldByName(_T("Rec_Time"),timeNow);
	//	rsTelData.MoveNext();
	//}
	////记录废钢电文信息
	//if(CreateNewObjects(csTelType,rsTelData) < rsTelData.GetRowCount())
	//	return -7;

	//材料加入入库缓存
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.DelField(_T("GUID"));
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rs.AppendRecord();
		rs.SetFieldByName(_T("MaterialID"),rsData.GetFieldByName(_T("Invcode")));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_SCRAP));
		if(rsData.GetFieldIndex(_T("vbillcode")) < 0)
			rs.SetFieldByName(_T("Amount"),rsData.GetFieldByName(_T("nnum")));
		else
			rs.SetFieldByName(_T("Amount"),rsData.GetFieldByName(_T("ninnum")));	
		rsData.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("AddMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	//加入基本数据表
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CL3Variant valTemp = rsData.GetFieldByName(_T("Invcode"));
		if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		CString csMaterialID = valTemp.ToCString();
		CString csUri = SCRAP_DATA_CLASS_URI + _T("\\") + csMaterialID;
		if(rsData.GetFieldIndex(_T("vbillcode")) < 0)
			valTemp = rsData.GetFieldByName(_T("nnum"));
		else
			valTemp = rsData.GetFieldByName(_T("ninnum"));

		if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		L3DOUBLE nAddAMount = valTemp.ToDouble();
		//2009-01-09 tangyi
		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();
		//if(!CreateNewObject(SCRAP_DATA_CLASS_URI,CL3Variant(csMaterialID)))
		if(!csObject.IsEmpty())
		{
			valTemp = GetObjectPropValue(csUri,_T("Amount"));
			if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			L3DOUBLE nAmount = valTemp.ToDouble();
			nAmount += nAddAMount;
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAmount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}

		}
		else
		{
			CreateNewObject(SCRAP_DATA_CLASS_URI,CL3Variant(csMaterialID));
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAddAMount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}
		
		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	// TODO : 请在此添加逻辑代码
	return 0;
}


/// <Method class="CScrap_Store_Mag" name="ScrapDataAccept" type="L3BOOL">
/// 
/// 接收NC废钢数据,加入input缓存,与材料表,接收电文表
/// ARG&gt;&gt; rsScrapData:废钢生铁信息.
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CScrap_Store_Mag::ScrapDataAcceptFromNC(L3RECORDSET rsScrapData)
{
	CL3RecordSetWrap rsData =rsScrapData;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return -1;

	//COleDateTime timeNow = COleDateTime::GetCurrentTime();

	////判断废钢来料信息
	//CString csTelType;
	//if(rsData.GetFieldIndex(_T("vbillcode")) < 0)//入库单号
	//	csTelType = SCRAP_TRANS_TEL_CLASS_URI;
	//else
	//	csTelType = SCRAP_PUR_TEL_CLASS_URI;

	//CL3RecordSetWrap rsTelData;
	//if(!CreateClassPropSet(csTelType,rsTelData))
	//	return -1;

	//rsTelData.DelField(_T("GUID"));
	////rsTelData.AddField(_T("Rec_Time"),VT_DATE);
	//rsTelData.CopyFrom(rsData);
	//rsTelData.MoveFirst();
	//while(!rsTelData.IsEOF())
	//{
	//	rsTelData.SetFieldByName(_T("Rec_Time"),timeNow);
	//	rsTelData.MoveNext();
	//}
	////记录废钢电文信息
	//if(CreateNewObjects(csTelType,rsTelData) < rsTelData.GetRowCount())
	//	return -7;

	//材料加入入库缓存
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.DelField(_T("GUID"));
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rs.AppendRecord();
		//Modify by liuzhiqiang 2009-03-13
		CString csInvcodeID = rsData.GetFieldByName(_T("cbaseid")).ToCString();
		CString csMaterialID;
		if(csInvcodeID == _T("0001NC10000000003MYN"))  
			csMaterialID =_T("PigIron"); 
		else 
		{
			if (csInvcodeID == _T("0001NC10000000003MYM"))  
				csMaterialID =_T("Scrap"); 
			else
			{
				rsData.MoveNext();
				continue;
			}
		}

		rs.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_SCRAP));
		rs.SetFieldByName(_T("Amount"),rsData.GetFieldByName(_T("ninnum")));	
		rsData.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("AddMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	//加入基本数据表
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CL3Variant valTemp = rs.GetFieldByName(_T("MaterialID"));
		CString csMaterialID=valTemp.ToCString(); 
		CString csUri = SCRAP_DATA_CLASS_URI + _T("\\") + csMaterialID;		
		valTemp = rs.GetFieldByName(_T("Amount"));
		L3DOUBLE nAddAMount = valTemp.ToDouble();
		//2009-01-09 tangyi
		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();
		//if(!CreateNewObject(SCRAP_DATA_CLASS_URI,CL3Variant(csMaterialID)))
		if(!csObject.IsEmpty())
		{
			valTemp = GetObjectPropValue(csUri,_T("Amount"));
			if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			L3DOUBLE nAmount = valTemp.ToDouble();
			nAmount += nAddAMount;
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAmount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}

		}
		else
		{
			CreateNewObject(SCRAP_DATA_CLASS_URI,CL3Variant(csMaterialID));
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAddAMount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}
		
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	// TODO : 请在此添加逻辑代码
	return 0;
}


/// <Method class="CScrap_Store_Mag" name="ScrapInStore" type="L3VOID">
/// 
/// 废钢入库
/// ARG&gt;&gt; rsInputInfo废钢生铁信息.必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CScrap_Store_Mag::ScrapInStore(L3RECORDSET rsInputInfo)
{
	return InputMaterials(rsInputInfo);
}

/// <Method class="CScrap_Store_Mag" name="ScrapOutStore" type="L3VOID">
/// 
/// 废钢出库
/// ARG&gt;&gt; rsOutputInfo废钢生铁信息.必须包含MaterialType, MaterialID, Amount, StoreAreaID,Scrap_Slot_ID,Car_ID,Car_Type,Net_Weight,Gross_Weight,Tare_Weight这几个字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsOutputInfo" type="L3RECORDSET">出库信息记录。包含MaterialType,MaterialID,Amount,AreaID等字段。</Param>
/// </Method>
L3BOOL CScrap_Store_Mag::ScrapOutStore(L3RECORDSET rsOutputInfo)
{
	CL3RecordSetWrap rs =rsOutputInfo;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	if(rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("StoreAreaID")) < 0 ||
		rs.GetFieldIndex(_T("Scrap_Slot_ID")) < 0 ||
		rs.GetFieldIndex(_T("Car_ID")) < 0 ||
		rs.GetFieldIndex(_T("Car_Type")) < 0 ||
		rs.GetFieldIndex(_T("Net_Weight")) < 0 ||
		rs.GetFieldIndex(_T("Gross_Weight")) < 0 ||
		rs.GetFieldIndex(_T("Tare_Weight")) < 0)
			return false;

	return OutputMaterials(rsOutputInfo);
}

/// <Method class="CScrap_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// 获取入库缓存材料
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CScrap_Store_Mag::GetMaterialOnInputCache()
{
	CString csInputCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
		return NULL;
	CString csPos = valRet.ToCString();
	CString csTemp = _T(" select a.*  from %s a  where  a.Position = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,csPos);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CAlloy_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// 获取库区材料信息
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CScrap_Store_Mag::GetMaterialOnStore(L3STRING strStoreID)
{
	CString csPos = strStoreID;
	CString csTemp;
	CString csSQL;
	if(csPos.IsEmpty())
	{
		csTemp= _T(" select a.*  from %s a  where  substr(a.Position,1,3) = '%s' and  substr(a.Position,4,1) <> 'P' and substr(a.Position,4,1) <> 'N'");
		csSQL.Format(csTemp,MES_MATERIAL_POSITION,STORE_ID_SCRAP);
	}
	else
	{
		csTemp = _T(" select a.*  from %s a  where  a.Position = '%s' ");
		csSQL.Format(csTemp,MES_MATERIAL_POSITION,csPos);

	}
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CAlloy_Store_Mag" name="AlloyModifyAmount" type="L3BOOL">
/// 
/// 库区材料量调整
/// ARG&gt;&gt; rsData:合金信息.必须包含MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag 这几个字段
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CScrap_Store_Mag::ModifyMaterialAmount(L3RECORDSET rsData)
{
	CL3Variant valRet =InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("ModifyMaterialAmountFuction"),rsData);
	if(!valRet.IsValid()||valRet.IsError())
		return -1;

	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return valRet.ToLong();

}


/// <Method class="CScrap_Store_Mag" name="ScrapInStore" type="L3VOID">
/// 
/// 废钢撤销出库2009-02-26
/// ARG&gt;&gt; rsOutputInfo废钢生铁信息.必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CScrap_Store_Mag::ScrapCancelOutStore(L3RECORDSET rsOutputInfo)
{

	CL3RecordSetWrap rsData =rsOutputInfo;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return  false;

	if(rsData.GetFieldIndex(_T("Scrap_Slot_ID")) < 0 )
		return false;

	//组建数据集
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsScrap; pRSRtn->QueryInterface(IID_IL3RecordSet,rsScrap); pRSRtn->Release();
	rsScrap.AddField(_T("MaterialType"),VT_BSTR);
	rsScrap.AddField(_T("MaterialID"),VT_BSTR);
	rsScrap.AddField(_T("SourceID"),VT_BSTR);
	rsScrap.AddField(_T("TargetID"),VT_BSTR);
	rsScrap.AddField(_T("Amount"),VT_R8);

	rsScrap.AppendRecord();


	//组建数据集
	CL3RecordSet *pRSRtnDel = new CL3RecordSet();
	CL3RecordSetWrap rsDel; pRSRtnDel->QueryInterface(IID_IL3RecordSet,rsDel); pRSRtnDel->Release();
	rsDel.AddField(_T("GUID"),VT_BSTR);



	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}


	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csCarID = rsData.GetFieldByName(_T("Scrap_Slot_ID")).ToCString();
		CString csTempSQL =_T(" select GUID,MaterialType,MaterialID,Amount,StoreAreaID as TargetID,'S82N01'as SourceID  from CScrap_Output_Log where Iron_flag =0 and Scrap_Slot_ID ='%s'");
		CString csSQL;
		csSQL.Format(csTempSQL,csCarID);
		CL3RecordSetWrap rsResultData;
		if(!Query(csSQL,rsResultData))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;
		}
		rsDel.CopyFrom(rsResultData);
		rsResultData.MoveFirst();
		while(!rsResultData.IsEOF())
		{
			rsScrap.CopyCurRowFrom(rsResultData);
			CString strSrc = rsScrap.GetFieldByName(_T("SourceID")).ToCString();
			CString strTgt = rsScrap.GetFieldByName(_T("TargetID")).ToCString();
			CString strSrcURI = XGINTERCACHE_URI + _T("\\") + strSrc;
			CL3Variant valRet = InvokeObjectMethod(strSrcURI,_T("RemoveMaterials"),(IL3RecordSet*)rsScrap);
			if(!valRet.ToBOOL())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return FALSE;
			}
			CString strTgtURI =XGSTOREAREA_URI + _T("\\") + strTgt;
			valRet = InvokeObjectMethod(strTgtURI,_T("AddMaterials"),(IL3RecordSet*)rsScrap);
			if(!valRet.ToBOOL())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return FALSE;
			}
			rsScrap.MoveFirst();
			rsResultData.MoveNext();
		}

		rsData.MoveNext();
	}

	if(DeleteOldObjects(SCRAP_OUT_CLASS_URI,rsDel) < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	if(bUseTrans) 
		Commit(nTrans);

	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return true;
}


/// <Method class="CBOF_Unit_Mag" name="GetScrapesForDesignate" type="L3RECORDSET">
/// 获取可选废钢信息记录。返回带有废钢槽号和废钢量的记录集。
/// </Method>
L3RECORDSET CScrap_Store_Mag::GetScrapes()
{
	//2009-02-21*Liao
	CString cssss = _T("select Scrap_Slot_ID,sum(Amount) as Amount,sum(decode(StoreAreaID,'S82A01',Amount,0)) as ScrapWT,");
	cssss += _T(" sum(Amount)-sum(decode(StoreAreaID,'S82A01',Amount,0)) as PigIronWT ,to_char(LogDate,'yyyy-mm-dd') as LogTime from CScrap_Output_Log where Iron_Flag = 0 group by Scrap_Slot_ID,to_char(LogDate,'yyyy-mm-dd')");
	CString strSQL;
	//strSQL.Format(_T("select Scrap_Slot_ID,sum(Amount) as Amount sum(decode(StoreAearID))from %s where Iron_Flag = 0 group by Scrap_Slot_ID"),SCRAP_OUT_CLASS_URI);
	strSQL.Format(cssss,SCRAP_OUT_CLASS_URI);
	
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}


/// <Method class="CScrap_Store_Mag" name="SaveScrapOutDetail" type="L3LONG">
/// <Param name="rsScrap" type="L3RECORDSET"></Param>
/// 保存废钢、生铁分类重量信息
/// </Method>2011-03-19 用户需要记录废钢种类信息添加
L3LONG CScrap_Store_Mag::SaveScrapOutDetail(L3RECORDSET rsScrap)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap pScrap =rsScrap;
	if( pScrap.IsNull() || pScrap.GetRowCount() < 1)
		return  -1;

	//获取最后一次料斗出库记录的料斗号
	CString csSql;
	csSql.Format(_T("select SCRAP_SLOT_ID from %s where LOGDATE>sysdate-0.007 and STOREAREAID='S82A01' order by LOGDATE desc "),SCRAP_OUT_CLASS_URI);

	CL3RecordSetWrap rsScrapData;
	if(!Query(csSql,rsScrapData)||rsScrapData.GetRowCount()<1)
		return -1;

	//取最后一条数据
	rsScrapData.MoveFirst();
	CString csScrap_Slot_ID=rsScrapData.GetFieldByName(_T("Scrap_Slot_ID")).ToCString();

	pScrap.MoveFirst();
	while(!pScrap.IsEOF())
	{
		CString csMaterial_Code = pScrap.GetFieldByName(_T("MATERIAL_CODE")).ToCString();
		L3LONG dAmout = pScrap.GetFieldByName(_T("AMOUNT")).ToLong();
		CString csMaterial = pScrap.GetFieldByName(_T("MATERIAL")).ToCString();

		if(csMaterial_Code==_T("")||dAmout<0||csMaterial==_T(""))
			return -1;
		pScrap.SetFieldByName(_T("Scrap_Slot_ID"),(CL3Variant)csScrap_Slot_ID);

		pScrap.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	
	CreateNewObjects(SCRAP_OUT_STORE_DETAIL_CLASS_URI,pScrap);
	if(bUseTrans)
		Commit(nTrans);
	return 0;
}

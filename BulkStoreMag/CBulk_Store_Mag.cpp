// 逻辑类CBulk_Store_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CBulk_Store_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CBulk_Store_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CBulk_Store_Mag.h"

//当对象被装载到系统中时，被调用
void CBulk_Store_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CBulk_Store_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 返回入库缓冲区的URI
/// </summary>
CString CBulk_Store_Mag::GetInputCache()
{
	// TODO: 在此处编辑相关功能的处理代码

	return BULK_STORE_INCACHE_OBJ_URI;
}

/// <summary>
/// 返回出库缓冲区的URI
/// </summary>
CString CBulk_Store_Mag::GetOutputCache()
{
	// TODO: 在此处编辑相关功能的处理代码

	return BULK_STORE_OUTCACHE_OBJ_URI;
}

/// <summary>
/// 返回入库记录类型名称
/// </summary>
CString CBulk_Store_Mag::GetInputLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return BULK_IN_CLASS_URI;
}

/// <summary>
/// 返回出库记录类型名称
/// </summary>
CString CBulk_Store_Mag::GetOutputLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return BULK_OUT_CLASS_URI;
}

/// <summary>
/// 返回库位类型名称
/// </summary>
CString CBulk_Store_Mag::GetStoreAreaType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return _T("");
}

/// <summary>
///	初始化库房的属性
/// </summary>
BOOL CBulk_Store_Mag::InitializeStoreProperties()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::InitializeStoreProperties();
}

/// <summary>
/// 填充库位的初始化数据
/// </summary>
BOOL CBulk_Store_Mag::GetInitialAreaData(CL3RecordSetWrap& rs)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetInitialAreaData(rs);
}

/// <summary>
/// 在库房初始完成后调用。继承类重载此函数进行额外的初始化工作。
/// </summary>
void CBulk_Store_Mag::OnAfterStoreInitialized()
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::OnAfterStoreInitialized();
}

/// <summary>
/// 入库前预处理。在入库操作前调用。继承类可重载此方法进行预先的数据准备和处理
/// ARG >> rsInputInfo : 入库信息记录。
/// RET << TRUE 继续入库；FALSE 中断入库
/// </summary>
BOOL CBulk_Store_Mag::OnBeforeInputMaterials(L3RECORDSET rsInputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeInputMaterials(rsInputInfo);
}

/// <summary>
/// 入库后续处理。在入库操作成功后调用。继承类可重载此方法进行额外的处理。
/// ARG >> rsInputInfo : 入库信息记录。
/// RET << 成功返回TRUE；失败返回FALSE；
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMaterialsInputted(L3RECORDSET rsInputInfo)
{
	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3LONG nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),L3LONG(nStoreEvent));
	
	//改变属性值2009-01-05 tangyi
	varStoreEvent = GetPropValue(_T("Bulk_Add_Material"));
	nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Bulk_Add_Material"),nStoreEvent);

	return TRUE;
}

/// <summary>
/// 出库前预处理。在出库操作前调用。继承类可重载此方法进行预先的数据准备和处理
/// ARG >> rsOutputInfo : 出库信息记录。
/// RET << TRUE 继续出库；FALSE 中断出库
/// </summary>
BOOL CBulk_Store_Mag::OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeOutputMaterials(rsOutputInfo);
}

/// <summary>
/// 出库后续处理。在出库操作成功后调用。继承类可重载此方法进行额外的处理。
/// ARG >> rsOutputInfo : 出库信息记录。
/// RET << 成功返回TRUE；失败返回FALSE；
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo)
{
	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//2009-04-08 tangyi将散装料从出库缓存中移去,删除垃圾数据
	//CString csOutObj = GetOutputCache();
	//InvokeObjectMethod(csOutObj,_T("RemoveMaterials"),rsOutputInfo);

	return TRUE;
}

/// <summary>
/// 人工增加库存前预处理。在进行人工增加库存前调用。继承类可重载此方发进行预先数据准备和处理
/// ARG	>> rsMaterialInfo : 新增材料信息记录。
/// RET << 返回TRUE继续处理；返回FALSE中断。
/// </summary>
BOOL CBulk_Store_Mag::OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeAddMaterials(rsMaterialInfo);
}

/// <summary>
/// 人工增加库存后续处理。在进行人工增加库存后调用。继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 新增的材料信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsAdded(rsMaterialInfo);
}

/// <summary>
/// 人工删除库存前预处理。在进行人工删除库存前调用。继承类可重载此方发进行预先数据准备和处理
/// ARG	>> rsMaterialInfo : 删除材料信息记录。
/// RET << 返回TRUE继续处理；返回FALSE中断。
/// </summary>
BOOL CBulk_Store_Mag::OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeDeleteMaterials(rsMaterialInfo);
}

/// <summary>
/// 人工删除库存后续处理。在进行人工删除库存后调用。继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 删除的材料信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo)
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
BOOL CBulk_Store_Mag::OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// 移库后续处理。
/// ARG >> rsMaterialInfo : 删除的材料信息记录。
/// RET << << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	CL3RecordSetWrap rs = rsMaterialInfo;
	CL3RecordSetWrap rsTrans;
	if(!CreateClassPropSet(BULK_TRANS_CLASS_URI,rsTrans))
		return false;
	rsTrans.DelField(_T("GUID"));
	rsTrans.DelField(_T("Name"));
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsTrans.AppendRecord();
		rsTrans.CopyCurRowFrom(rs);
		rsTrans.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsTrans.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));	
		rsTrans.SetFieldByName(_T("Trans_Date"),COleDateTime::GetCurrentTime());	
		rsTrans.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));	
		rs.MoveNext();
	}
	if(CreateNewObjects(BULK_TRANS_CLASS_URI,L3RECORDSET(rsTrans)) < rsTrans.GetRowCount())
		return false;

	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return true;

}

/// <summary>
/// 入库记录预处理。继承类可重载此方法在入库前检查或处理入库记录
/// </summary>
void CBulk_Store_Mag::PrepareInputLog(L3RECORDSET rsInputLog)
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
void CBulk_Store_Mag::PrepareOutputLog(L3RECORDSET rsOutputLog)
{
	CL3RecordSetWrap rs = rsOutputLog;
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
/// 返回指定编号的库位对象的URI
/// </summary>
CString CBulk_Store_Mag::GetAreaURI(LPCTSTR lpcszAreaID)
{
	// TODO: 在此处编辑相关功能的处理代码
	CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\");
	csAreaUri+=lpcszAreaID;

	return  csAreaUri;
}

/// <Method class="CBulk_Store_Mag" name="BulkDataAccept" type="L3BOOL">
/// 
/// 接收NC散状料入库数据,加入input缓存,与材料表,接收电文表
/// ARG&gt;&gt; rsData:散状料信息.
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBulk_Store_Mag::BulkDataAccept(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsBulkData =rsData;
	if( rsBulkData.IsNull() || rsBulkData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//材料加入入库缓存
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.AddField(_T("Batch_ID"),VT_BSTR);
	rs.AddField(_T("Bulk_Code"),VT_BSTR);
	rsBulkData.MoveFirst();
	while(!rsBulkData.IsEOF())
	{
	
		//2009-06-19 加上物料编码判断为空不接收
		CString csBulkCode = rsBulkData.GetFieldByName(_T("Invcode")).ToCString();
		csBulkCode.Trim();
		if(csBulkCode.IsEmpty())
		{
			rsBulkData.MoveNext();
			continue;
		}
		rs.AppendRecord();
		CString csBatchID = rsBulkData.GetFieldByName(_T("vproductbatchcode")).ToCString();
		CString csMaterialID = csBulkCode + csBatchID;
		rs.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BULK));
		L3DOUBLE nWeight =0;
		if(rsBulkData.GetFieldIndex(_T("vbillcode")) < 0)
			nWeight = rsBulkData.GetFieldByName(_T("nnum")).ToDouble();
		else
			nWeight = rsBulkData.GetFieldByName(_T("ninnum")).ToDouble();
		rs.SetFieldByName(_T("Amount"),CL3Variant(nWeight*1000));
		rs.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
		rs.SetFieldByName(_T("Bulk_Code"),CL3Variant(csBulkCode));
		rsBulkData.MoveNext();
	}

	//2009-06-19 加上物料编码判断为空不接收
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;


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
	CL3RecordSetWrap rsBulkBaseData;
	//modify by hyh 2012-04-11
	if(!CreateClassPropSet(BULK_DATA_CLASS_URI,rsBulkBaseData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	//end


	rsBulkBaseData.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CL3Variant valTemp = rs.GetFieldByName(_T("MaterialID"));
		if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		CString csMaterialID = valTemp.ToCString();	

		valTemp = rs.GetFieldByName(_T("Amount"));

		if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		L3DOUBLE nAddAMount = valTemp.ToDouble();
		CString csBulkCode = rs.GetFieldByName(_T("Bulk_Code")).ToCString();
		CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString();
		rsBulkBaseData.SetFieldByName(_T("MaterialID"),  CL3Variant(csMaterialID));
		rsBulkBaseData.SetFieldByName(_T("Bulk_Code"),  CL3Variant(csBulkCode));
		rsBulkBaseData.SetFieldByName(_T("Amount"),  CL3Variant(nAddAMount));
		rsBulkBaseData.SetFieldByName(_T("Batch_ID"),  CL3Variant(csBatchID));

		CString csUri = BULK_DATA_CLASS_URI + _T("\\") + csMaterialID;

		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();

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
			CreateNewObject(BULK_DATA_CLASS_URI,CL3Variant(csMaterialID));
			if(!SetObjPropValues(csUri,rsBulkBaseData))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}
		rsBulkBaseData.MoveFirst();
		rs.MoveNext();
	}


	if(bUseTrans)
		Commit(nTrans);

	// TODO : 请在此添加逻辑代码
	return 0;
}


/// <Method class="CBulk_Store_Mag" name="BulkDataAcceptFromNC" type="L3BOOL">
/// 
/// 接收NC数据,加入input缓存,与材料表,接收电文表
/// ARG&gt;&gt; rsScrapData:废钢生铁信息.
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBulk_Store_Mag::BulkDataAcceptFromNC(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsBulkData =rsData;
	if( rsBulkData.IsNull() || rsBulkData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//材料加入入库缓存
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.DelField(_T("GUID"));
	rs.AddField(_T("Batch_ID"),VT_BSTR);
	rs.AddField(_T("Bulk_Code"),VT_BSTR);

	rsBulkData.MoveFirst();
	while(!rsBulkData.IsEOF())
	{
		//2009-04-07物料编码直接从电文里获取	
		//2009-06-19 加上物料编码判断为空不接收
		CString csBulkCode = rsBulkData.GetFieldByName(_T("Invcode")).ToCString();
		csBulkCode.Trim();
		if(csBulkCode.IsEmpty())
		{
			rsBulkData.MoveNext();
			continue;
		}
		rs.AppendRecord();	
		CString csBatchID = rsBulkData.GetFieldByName(_T("vbatchcode")).ToCString();
		L3DOUBLE nAmount = rsBulkData.GetFieldByName(_T("ninnum")).ToDouble();
		rs.SetFieldByName(_T("MaterialID"),CL3Variant(csBulkCode + csBatchID));
		rs.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BULK));
		rs.SetFieldByName(_T("Amount"),CL3Variant(nAmount*1000));
		rs.SetFieldByName(_T("Bulk_Code"),CL3Variant(csBulkCode));
		rsBulkData.MoveNext();
	}

	//2009-06-19 加上物料编码判断为空不接收
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;

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
		CString csMaterialID =rs.GetFieldByName(_T("MaterialID")).ToCString(); 
		CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString(); 
		CString csBulkCode = rs.GetFieldByName(_T("Bulk_Code")).ToCString(); 
		CString csUri = BULK_DATA_CLASS_URI + _T("\\") + csMaterialID;	
		CL3Variant valTemp = rs.GetFieldByName(_T("Amount"));
		L3DOUBLE nAddAMount = valTemp.ToDouble();
		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();
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
			CreateNewObject(BULK_DATA_CLASS_URI,CL3Variant(csMaterialID));
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAddAMount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
			if(!SetObjectPropValue(csUri,_T("Bulk_Code"),CL3Variant(csBulkCode)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}	
			//2009-03-20 liuzhiqiang
			if(!SetObjectPropValue(csUri,_T("Batch_ID"),CL3Variant(csBatchID)))
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

	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("Bulk_Add_Material"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Bulk_Add_Material"),nStoreEvent);

	// TODO : 请在此添加逻辑代码
	return 0;
}


/// <Method class="CBulk_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// 获取入库缓存材料
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CBulk_Store_Mag::GetMaterialOnInputCache()
{
	CString csInputCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
		return NULL;
	CString csPos = valRet.ToCString();
	CString csTemp = _T(" select a.*,b.Batch_ID,b.Bulk_Code ");
			csTemp+= _T(" from %s a,%s b where a.MaterialID = b.MaterialID and a.Position = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,BULK_DATA_CLASS_URI,csPos);
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
L3RECORDSET CBulk_Store_Mag::GetMaterialOnStore(L3STRING strStoreID)
{
	CString csPos = strStoreID;
	CString csTemp = _T(" select a.*,b.Batch_ID,b.Bulk_Code ");
			csTemp+= _T(" from %s a,%b b where a.MaterialID = b.MaterialID and a.Position = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,BULK_DATA_CLASS_URI,csPos);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CBulk_Store_Mag" name="GetBulkArea" type="L3RECORDSET">
/// 
/// 根据散状料编码获取料仓
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CBulk_Store_Mag::GetBulkArea(L3STRING strBulkCode)
{
	CString csTemp = _T(" select a.Bulk_Area,b.Code_Des from (select  Bulk_Area  from %s  where Bulk_Code ='%s') a, CBase_All_Code b where a.Bulk_Area = b.Code  order by b.Code_Des");
	CString csSQL;
	csSQL.Format(csTemp,BULK_REL_CLASS_URI,strBulkCode);
	CL3RecordSetWrap rsAlloyData;
	if(!Query(csSQL,rsAlloyData))
		return NULL;
	else
		return rsAlloyData.Detach();
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CAlloy_Store_Mag" name="GetAllMaterialOnStore" type="L3RECORDSET">
/// 
/// 获取所有库区材料信息
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CBulk_Store_Mag::GetAllMaterialOnStore(void)
{

	CString csTemp = _T(" select c.MaterialID,c.MaterialType,d.Code as Position,                         ");
			csTemp+= _T(" substr(d.Code,4,1) as PosDiff,c.Amount, c.Batch_ID,c.Bulk_Code  from           ");
			csTemp+= _T(" (select a.MaterialID,a.MaterialType,a.Amount,a.Position as Pos,                ");
			csTemp+= _T(" b.Batch_ID,b.Bulk_Code                                                         ");
			csTemp+= _T(" from %s a,%s b                                                                  ");
			csTemp+= _T(" where  a.MaterialID = b.MaterialID  and substr(a.Position,1,3) = '%s'           ");
			csTemp+= _T(" and  substr(a.Position,4,1) <> 'P' and  substr(a.Position,4,1) <> 'N' ) c ,     ");
			csTemp+= _T(" (select * from XGSTOREAREA where substr(Code,1,3) = '%s') d                     ");		
			csTemp+= _T(" where   c.Pos(+)  = d.Code        order by Position                             ");
			
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,BULK_DATA_CLASS_URI,STORE_ID_BULK,STORE_ID_BULK);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CBulk_Store_Mag" name="GetAreaIDByUnitID" type="L3STRING">
/// 
/// 通过工位获取料仓编码
/// ARG&gt;&gt; strUnitID：工位
/// RET &lt;&lt;返回料仓编码
/// <Param name="strUnitID" type="L3STRING"></Param>
/// </Method>
L3STRING CBulk_Store_Mag::GetAreaIDByUnitID(L3STRING strUnitID)
{
	// TODO : 请在此添加逻辑代码
	return NULL;
}

/// <Method class="CBulk_Store_Mag" name="BulkApp" type="L3BOOL">
/// 
/// 散状料要料申请
/// ARG&gt;&gt; rsData:散状料信息.
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBulk_Store_Mag::BulkApp(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	if(rs.GetFieldIndex(_T("Bulk_Code")) < 0 ||
		rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("App_Time")) < 0 ||
		rs.GetFieldIndex(_T("App_Operator")) < 0 ||
		rs.GetFieldIndex(_T("App_UnitID")) < 0)
			return FALSE;

	rs.MoveFirst();
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	//补齐数据
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("App_Operator"),CL3Variant(csUser));
		rs.SetFieldByName(_T("App_Time"),timeNow);
		rs.MoveNext();
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(CreateNewObjects(BULK_APP_CLASS_URI,L3RECORDSET(rs)) < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	if(bUseTrans)
		Commit(nTrans);
	return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBulk_Store_Mag" name="BulkAppConfirm" type="L3BOOL">
/// 
/// 散状料要料申请确认
/// ARG&gt;&gt; rsData:散状料信息.
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBulk_Store_Mag::BulkAppConfirm(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	rs.MoveFirst();
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	//补齐数据
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("Confirm_Flag"),LONG(1));
		rs.SetFieldByName(_T("Confirm_Operator"),CL3Variant(csUser));
		rs.SetFieldByName(_T("Confirm_Time"),timeNow);
		rs.MoveNext();
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(!SetObjsPropValues(BULK_APP_CLASS_URI,L3RECORDSET(rs)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	if(bUseTrans)
		Commit(nTrans);
	return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBulk_Store_Mag" name="BulkInStore" type="L3BOOL">
/// 
/// 散状料入库
/// ARG&gt;&gt; rsInputInfo散状料信息.必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBulk_Store_Mag::BulkInStore(L3RECORDSET rsInputInfo)
{
	//2009-03-26 改,一个料仓可以对同一种料进行混装,出的时候,采取先进先出的原则tangyi

	CL3RecordSetWrap rs =rsInputInfo;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if(rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("StoreAreaID")) < 0 ||
		rs.GetFieldIndex(_T("Batch_ID")) < 0 ||
		rs.GetFieldIndex(_T("Bulk_Code")) < 0)
			return -1;
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csArea = rs.GetFieldByName(_T("StoreAreaID")).ToCString();
		csArea.Trim();
		CString csMaterialType = rs.GetFieldByName(_T("MaterialType")).ToCString();
		//2009-03-26 tangyi得到编码
		CString csBulkCode = rs.GetFieldByName(_T("Bulk_Code")).ToCString();
		CString strSQL;
		strSQL.Format(_T("SELECT * FROM %s WHERE Position = '%s'"),MES_MATERIAL_POSITION,csArea);
		CL3RecordSetWrap rsResult;
		if(!Query(strSQL,rsResult))
            return -2;
		rsResult.MoveFirst();
		while(!rsResult.IsEOF())
		{
			CString csCurMaterialID = rsResult.GetFieldByName(_T("MaterialID")).ToCString();
			//2009-03-26 tangyi得到编码
			CString cBulkUri = BULK_DATA_CLASS_URI + _T("\\") + csCurMaterialID;
			CString csCurBulkCode = GetObjectPropValue(cBulkUri,_T("Bulk_Code")).ToCString();
			CString csCurMaterialType = rsResult.GetFieldByName(_T("MaterialType")).ToCString();
			if(csBulkCode != csCurBulkCode || csCurMaterialType!= csMaterialType)
				return -3;
			rsResult.MoveNext();
		}
		rs.MoveNext();
	}
	if(!InputMaterials(rsInputInfo))
		return -4;
	return 0;
}

//// <Method class="CAlloy_Store_Mag" name="AlloyInStore" type="L3LONG">
//// 
//// 转库
//// ARG&gt;&gt; rsInputInfo信息.必须包含 MaterialType,MaterialID,Amount,Position,TargetID这几个字段。
//// &gt;&gt;strUnitID:工序
//// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
//// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
//// <Param name="strUnitID" type="L3STRING"></Param>
/////</Method>
L3LONG CBulk_Store_Mag::BulkChangeStore(L3RECORDSET rsInputInfo)
{
	//同一个料仓只能加入同一批次的同种合金
	CL3RecordSetWrap rs =rsInputInfo;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if (rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Position")) < 0 ||
		rs.GetFieldIndex(_T("Bulk_Code")) < 0 ||
		rs.GetFieldIndex(_T("Batch_ID")) < 0 ||
		rs.GetFieldIndex(_T("TargetID")) < 0 )
			return -1;
	rs.MoveFirst();
	//数据检查
	while(!rs.IsEOF())
	{
		CString csTargetArea = rs.GetFieldByName(_T("TargetID")).ToCString();
		csTargetArea.Trim();
		CString csMaterialType=rs.GetFieldByName(_T("MaterialType")).ToCString();
		CString csBulkCode = rs.GetFieldByName(_T("Bulk_Code")).ToCString();
		CString strSQL;
		strSQL.Format(_T("SELECT * FROM %s WHERE Position = '%s'"),MES_MATERIAL_POSITION,csTargetArea);
		CL3RecordSetWrap rsResult;
		if(!Query(strSQL,rsResult))
            return -2;
		rsResult.MoveFirst();
		while(!rsResult.IsEOF())
		{
			CString csTargetMaterialID = rsResult.GetFieldByName(_T("MaterialID")).ToCString();
			//2009-03-26 tangyi得到编码
			CString cBulkUri = BULK_DATA_CLASS_URI + _T("\\") + csTargetMaterialID;
			CString csTargetBulkCode = GetObjectPropValue(cBulkUri,_T("Bulk_Code")).ToCString();
			CString csCurMaterialType = rsResult.GetFieldByName(_T("MaterialType")).ToCString();
			if(csBulkCode != csTargetBulkCode || csCurMaterialType!= csMaterialType)
				return -3;
			rsResult.MoveNext();
		}
		rs.MoveNext();
	}
	//数据准备
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBulk; pRS->QueryInterface(IID_IL3RecordSet,rsBulk); pRS->Release();
	rsBulk.AddField(_T("MaterialType"),VT_BSTR);
	rsBulk.AddField(_T("MaterialID"),VT_BSTR);
	rsBulk.AddField(_T("Amount"),VT_R8);
	rsBulk.AddField(_T("TargetID"),VT_BSTR);
	rsBulk.AddField(_T("SourceID"),VT_BSTR);
	rsBulk.AddField(_T("Bulk_Code"),VT_BSTR);
	rsBulk.AddField(_T("Batch_ID"),VT_BSTR);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBulk.AppendRecord();
		rsBulk.SetFieldByName(_T("MaterialType"),rs.GetFieldByName(_T("MaterialType")));
		rsBulk.SetFieldByName(_T("MaterialID"),rs.GetFieldByName(_T("MaterialID")));
		rsBulk.SetFieldByName(_T("Amount"),rs.GetFieldByName(_T("Amount")));
		rsBulk.SetFieldByName(_T("TargetID"),rs.GetFieldByName(_T("TargetID")));
		rsBulk.SetFieldByName(_T("SourceID"),rs.GetFieldByName(_T("Position")));
		rsBulk.SetFieldByName(_T("Bulk_Code"),rs.GetFieldByName(_T("Bulk_Code")));
		rsBulk.SetFieldByName(_T("Batch_ID"),rs.GetFieldByName(_T("Batch_ID")));
		rs.MoveNext();
	}	
	//rsAlloy.MoveFirst();
	if(!MoveMaterials(L3RECORDSET(rsBulk)))
		return -4;
	return 0;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBulk_Store_Mag" name="GetBulkAppInfor" type="L3RECORDSET">
/// 
/// 获取未确认散状料申请信息
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CBulk_Store_Mag::GetBulkAppInfor(L3STRING strDate)
{
	CString csTemp = _T(" select * from %s where Confirm_Flag = 0 and to_char(App_Time,'yyyy-mm-dd') = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,BULK_APP_CLASS_URI,strDate);
	CL3RecordSetWrap rsAlloyData;
	if(!Query(csSQL,rsAlloyData)||rsAlloyData.IsNull())
		return NULL;
	else
		return rsAlloyData.Detach();
	// TODO : 请在此添加逻辑代码
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBulk_Store_Mag" name="BulkAndAreaMap" type="L3BOOL">
/// 
/// 料仓料种维护
/// ARG&gt;&gt; rsData:料仓料种信息.
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBulk_Store_Mag::BulkAndAreaMap(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(!SetObjsPropValues(BULK_REL_CLASS_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	if(bUseTrans)
		Commit(nTrans);
	return true;
	// TODO : 请在此添加逻辑代码
}


/// <Method class="CAlloy_Store_Mag" name="AlloyModifyAmount" type="L3LONG">
/// 
/// 库区材料量调整
/// ARG&gt;&gt; rsData:合金信息.必须包含MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag 这几个字段
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBulk_Store_Mag::ModifyMaterialAmount(L3RECORDSET rsData)
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


// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
/// 
/// 散装料上料取消2009-04-05
/// ARG&gt;&gt; rsData:合金信息.
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CBulk_Store_Mag::BulkInStoreCancel (L3RECORDSET rsData)
{
	CL3RecordSetWrap rsBulkData =rsData;
	if( rsBulkData.IsNull() || rsBulkData.GetRowCount() < 1)
		return -1;

	if (rsBulkData.GetFieldIndex(_T("Amount")) < 0 ||
		rsBulkData.GetFieldIndex(_T("MaterialType")) < 0 ||
		rsBulkData.GetFieldIndex(_T("MaterialID")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Position")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Bulk_Code")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Batch_ID")) < 0 )
			return -1;

	rsBulkData.MoveFirst();

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//班次班别
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	//散装料出库日志
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(BULK_OUT_CLASS_URI,rs))
		return -1;

	//得到退料合金类型、数量

	//2009-03-24 tangyi 修改
	rs.AppendRecord();
	rs.CopyCurRowFrom(rsBulkData);
	rs.SetFieldByName(_T("Type"),L3LONG(1));
	rs.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rs.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
	rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
	CString csArea = rsBulkData.GetFieldByName(_T("Position")).ToCString();
	rs.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));	

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CString csAreaObj = GetAreaURI(csArea);
	CL3Variant valRet = InvokeObjectMethod(csAreaObj,_T("RemoveMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	CString csCacheUri = GetInputCache();
	valRet = InvokeObjectMethod(csCacheUri,_T("AddMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}
	
	rs.MoveFirst();
	if(CreateNewObjects(BULK_OUT_CLASS_URI,rs) < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	if(bUseTrans)
		Commit(nTrans);


	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//改变属性值2009-01-05 tangyi
	varStoreEvent = GetPropValue(_T("Bulk_Add_Material"));
	nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Bulk_Add_Material"),nStoreEvent);

	// TODO : 请在此添加逻辑代码
	return 0;
}


// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
/// 
/// 散装料转合金2009-04-08
/// ARG&gt;&gt; rsData:合金信息.
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CBulk_Store_Mag::BulkTransToAlloy (L3RECORDSET rsData)
{
	CL3RecordSetWrap rsBulkData =rsData;
	if( rsBulkData.IsNull() || rsBulkData.GetRowCount() < 1)
		return -1;

	if (rsBulkData.GetFieldIndex(_T("Amount")) < 0 ||
		rsBulkData.GetFieldIndex(_T("MaterialType")) < 0 ||
		rsBulkData.GetFieldIndex(_T("MaterialID")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Position")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Bulk_Code")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Batch_ID")) < 0 )
			return -1;

	rsBulkData.MoveFirst();

	CString csAlloyCode = rsBulkData.GetFieldByName(_T("Bulk_Code")).ToCString();
	CString csBatchID	= rsBulkData.GetFieldByName(_T("Batch_ID")).ToCString();


	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//班次班别
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	//散装料出库日志
	CL3RecordSetWrap rsOut;
	if(!CreateClassPropSet(BULK_OUT_CLASS_URI,rsOut))
		return -1;

	//合金入库日志
	CL3RecordSetWrap rsIn;
	if(!CreateClassPropSet(ALLOY_IN_CLASS_URI,rsIn))
		return -2;

	//判断是否能转合金
	CString csTemp = _T("select Code from CBase_All_Code where code ='%s' and Code_Group='ALLOY_CODE' ");
	CString csSQL;
	csSQL.Format(csTemp,csAlloyCode);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		return -3;

	//散装料出库
	rsOut.AppendRecord();
	rsOut.CopyCurRowFrom(rsBulkData);
	rsOut.SetFieldByName(_T("Type"),L3LONG(3));
	rsOut.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rsOut.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
	rsOut.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsOut.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
	CString csArea = rsBulkData.GetFieldByName(_T("Position")).ToCString();
	rsOut.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));	

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CString csCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csCacheUri,_T("RemoveMaterials"),L3RECORDSET(rsOut));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rsOut.MoveFirst();
	if(CreateNewObjects(BULK_OUT_CLASS_URI,rsOut) < rsOut.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}


	//合金入入库缓存库
	rsIn.AppendRecord();
	rsIn.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
	rsIn.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
	rsIn.SetFieldByName(_T("Amount"),rsBulkData.GetFieldByName(_T("Amount")));
	rsIn.SetFieldByName(_T("Type"),L3LONG(3));
	rsIn.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rsIn.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
	rsIn.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsIn.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
	rsIn.SetFieldByName(_T("StoreAreaID"),CL3Variant(_T("S81P01")));	
	rsIn.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
	rsIn.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
	csCacheUri = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S81P01");

	valRet = InvokeObjectMethod(csCacheUri,_T("AddMaterials"),L3RECORDSET(rsIn));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}
	
	rsIn.MoveFirst();
	if(CreateNewObjects(ALLOY_IN_CLASS_URI,rsIn) < rsIn.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	//生成合金基本数据
	CL3RecordSetWrap rsAlloy;
	if(!CreateClassPropSet(ALLOY_DATA_CLASS_URI,rsAlloy))
		return -1;

	rsAlloy.AppendRecord();
	rsAlloy.SetFieldByName(_T("Status"),L3LONG(0));
	rsAlloy.SetFieldByName(_T("Amount"),rsBulkData.GetFieldByName(_T("Amount")));
	rsAlloy.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
	rsAlloy.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
	rsAlloy.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
	
	CreateNewObjects(ALLOY_DATA_CLASS_URI,rsAlloy);

	if(bUseTrans)
		Commit(nTrans);

	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("Bulk_Add_Material"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Bulk_Add_Material"),nStoreEvent);

	// TODO : 请在此添加逻辑代码
	return 0;
}


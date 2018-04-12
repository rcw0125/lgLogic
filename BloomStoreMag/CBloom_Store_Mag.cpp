// 逻辑类CBloom_Store_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CBloom_Store_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CBloom_Store_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CBloom_Store_Mag.h"
#include "L3NameParser.h"

//当对象被装载到系统中时，被调用
void CBloom_Store_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CBloom_Store_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 返回入库缓冲区的URI
/// </summary>
CString CBloom_Store_Mag::GetInputCache()
{
	// TODO: 在此处编辑相关功能的处理代码

	return _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S71P01");	
}

/// <summary>
/// 返回出库缓冲区的URI
/// </summary>
CString CBloom_Store_Mag::GetOutputCache()
{
	// TODO: 在此处编辑相关功能的处理代码

	return  BLOOM_STORE_OUTCACHE_OBJ_URI;	
}

/// <summary>
/// 返回入库记录类型名称
/// </summary>
CString CBloom_Store_Mag::GetInputLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return BLOOM_IN_CLASS_URI;
}

/// <summary>
/// 返回出库记录类型名称
/// </summary>
CString CBloom_Store_Mag::GetOutputLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return BLOOM_OUT_CLASS_URI;
}

/// <summary>
/// 返回库位类型名称
/// </summary>
CString CBloom_Store_Mag::GetStoreAreaType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return _T("");
}

/// <summary>
///	初始化库房的属性
/// </summary>
BOOL CBloom_Store_Mag::InitializeStoreProperties()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::InitializeStoreProperties();
}

/// <summary>
/// 填充库位的初始化数据
/// </summary>
BOOL CBloom_Store_Mag::GetInitialAreaData(CL3RecordSetWrap& rs)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetInitialAreaData(rs);
}

/// <summary>
/// 在库房初始完成后调用。继承类重载此函数进行额外的初始化工作。
/// </summary>
void CBloom_Store_Mag::OnAfterStoreInitialized()
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::OnAfterStoreInitialized();
}

/// <summary>
/// 入库前预处理。在入库操作前调用。继承类可重载此方法进行预先的数据准备和处理
/// ARG >> rsInputInfo : 入库信息记录。
/// RET << TRUE 继续入库；FALSE 中断入库
/// </summary>
BOOL CBloom_Store_Mag::OnBeforeInputMaterials(L3RECORDSET rsInputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeInputMaterials(rsInputInfo);
}

/// <summary>
/// 入库后续处理。在入库操作成功后调用。继承类可重载此方法进行额外的处理。
/// ARG >> rsInputInfo : 入库信息记录。
/// RET << 成功返回TRUE；失败返回FALSE；
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMaterialsInputted(L3RECORDSET rsInputInfo)
{
	//设置钢坯材料状态为入库,记下钢坯所在位置
	CL3RecordSetWrap rs = rsInputInfo;
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csPos = rs.GetFieldByName(_T("StoreAreaID")).ToCString();
		CString csPile = rs.GetFieldByName(_T("Cur_Pile_ID")).ToCString();
		CString csLayer = rs.GetFieldByName(_T("Cur_Layer_ID")).ToCString();
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csUir = BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID;
		if(!SetObjectPropValue(csUir,_T("Status"),CL3Variant(BLOOM_STATUS_INSTORE)))
			return false;
		if(!SetObjectPropValue(csUir,_T("Position"),CL3Variant(csPos)))
			return false;
		if(!SetObjectPropValue(csUir,_T("Cur_Pile_ID"),CL3Variant(csPile)))
			return false;
		if(!SetObjectPropValue(csUir,_T("Cur_Layer_ID"),CL3Variant(csLayer)))
			return false;
		rs.MoveNext();
	}
	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//改变属性值2009-02-17 tangyi
	//varStoreEvent = GetPropValue(_T("BloomInStore"));
	//nStoreEvent = varStoreEvent.ToShort();
	//nStoreEvent = (nStoreEvent+1) % 9999;
	//SetPropValue(_T("BloomInStore"),nStoreEvent);
	
	return TRUE;
}

/// <summary>
/// 出库前预处理。在出库操作前调用。继承类可重载此方法进行预先的数据准备和处理
/// ARG >> rsOutputInfo : 出库信息记录。
/// RET << TRUE 继续出库；FALSE 中断出库
/// </summary>
BOOL CBloom_Store_Mag::OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeOutputMaterials(rsOutputInfo);
}

/// <summary>
/// 出库后续处理。在出库操作成功后调用。继承类可重载此方法进行额外的处理。
/// ARG >> rsOutputInfo : 出库信息记录。
/// RET << 成功返回TRUE；失败返回FALSE；
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo)
{
	//设置钢坯材料状态为出库
	CL3RecordSetWrap rs = rsOutputInfo;
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csUir = BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID;
		if(!SetObjectPropValue(csUir,_T("Status"),CL3Variant(BLOOM_STATUS_OUTSTORE)))
			return false;
		if(!SetObjectPropValue(csUir,_T("Position"),CL3Variant(STORE_ID_BLOOM_CACHE)))
			return false;
		rs.MoveNext();
	}
	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);
	//2009-03-06 tangyi将钢坯从出库缓存中移去,删除垃圾数据
	CString csOutObj = GetOutputCache();
	rs.MoveFirst();
	InvokeObjectMethod(csOutObj,_T("RemoveMaterials"),(L3RECORDSET)rs);

	return TRUE;
}

/// <summary>
/// 人工增加库存前预处理。在进行人工增加库存前调用。继承类可重载此方发进行预先数据准备和处理
/// ARG	>> rsMaterialInfo : 新增材料信息记录。
/// RET << 返回TRUE继续处理；返回FALSE中断。
/// </summary>
BOOL CBloom_Store_Mag::OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeAddMaterials(rsMaterialInfo);
}

/// <summary>
/// 人工增加库存后续处理。在进行人工增加库存后调用。继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 新增的材料信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsAdded(rsMaterialInfo);
}

/// <summary>
/// 人工删除库存前预处理。在进行人工删除库存前调用。继承类可重载此方发进行预先数据准备和处理
/// ARG	>> rsMaterialInfo : 删除材料信息记录。
/// RET << 返回TRUE继续处理；返回FALSE中断。
/// </summary>
BOOL CBloom_Store_Mag::OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeDeleteMaterials(rsMaterialInfo);
}

/// <summary>
/// 人工删除库存后续处理。在进行人工删除库存后调用。继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 删除的材料信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo)
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
BOOL CBloom_Store_Mag::OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// 移库后续处理。
/// ARG >> rsMaterialInfo : 删除的材料信息记录。
/// RET << << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	CL3RecordSetWrap rs = rsMaterialInfo;
	CL3RecordSetWrap rsTrans;
	if(!CreateClassPropSet(_T("XGMESLogic\\BloomStoreMag\\CBloom_Trans_Log"),rsTrans))
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
	if(CreateNewObjects(_T("XGMESLogic\\BloomStoreMag\\CBloom_Trans_Log"),L3RECORDSET(rsTrans)) < rsTrans.GetRowCount())
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
void CBloom_Store_Mag::PrepareInputLog(L3RECORDSET rsInputLog)
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
void CBloom_Store_Mag::PrepareOutputLog(L3RECORDSET rsOutputLog)
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
CString CBloom_Store_Mag::GetAreaURI(LPCTSTR lpcszAreaID)
{
	// TODO: 在此处编辑相关功能的处理代码
	CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\");
	csAreaUri+=lpcszAreaID;

	return  csAreaUri;
}

/// <Method class="CBloom_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// 获取入库缓存材料
/// ARG&gt;&gt; 
/// RET &lt;&lt;返回数据集
/// </Method>
L3RECORDSET CBloom_Store_Mag::GetMaterialOnInputCache()
{
	CString csInputCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
		return NULL;
	CString csPos = valRet.ToCString();
	CString csTemp = _T(" select a.MaterialType,a.Amount,b.MaterialID,b.Cur_Pile_ID,b.Cur_Layer_ID,b.CasterID,NULL as StoreAreaID,                ");
			csTemp+= _T(" b.Thickness || '*' || b.Width || '*' || b.Length as Std,b.SteelGradeIndex,b.Waster_Count,b.Wrong_Count,                 ");
			csTemp+= _T(" b.Right_Count,b.Pre_SteelGradeIndex,b.Casting_No,b.Casting_Heat_Cnt,b.Process_Type,b.Plan_Ord_ID,b.Bloom_Count,         ");
			csTemp+= _T(" b.Cal_Weight,b.Right_Weight,b.Waster_Weight,b.Waster_Count1,b.Waster_Weight1,b.Waster_Reason1,b.Waster_Count2,b.Waster_Weight2,b.Waster_Reason2,");
			csTemp+= _T(" b.Waster_Count3,b.Waster_Weight3,b.Waster_Reason3,b.Wrong_Weight,b.Wrong_Count1,b.Wrong_Weight1,b.Wrong_Reason1,");
			csTemp+= _T(" b.Wrong_Count2,b.Wrong_Weight2,b.Wrong_Reason2,b.Wrong_Count3,b.Wrong_Weight3,b.Wrong_Reason3,b.SufaceDefactDes, ");
			csTemp+= _T(" b.Reason from %s a,%s b where a.MaterialID = b.MaterialID and a.Position = '%s' and Status =%s	              ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,BLOOM_DATA_CLASS_URI,csPos,BLOOM_STATUS_DOWN);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CBloom_Store_Mag" name="ChangeBloomPosition" type="L3BOOL">
/// 
/// 垛位变更
/// ARG&gt;&gt; rsBloom：钢坯数据，包括新的垛位信息
/// RET &lt;&lt;成功返回True，失败返回False
/// <Param name="rsBloom" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBloom_Store_Mag::ChangeBloomPosition(L3RECORDSET rsBloom)
{
	CL3RecordSetWrap rs =rsBloom;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if (rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Position")) < 0 ||
		rs.GetFieldIndex(_T("Cur_Pile_ID")) < 0 ||
		rs.GetFieldIndex(_T("Cur_Layer_ID")) < 0 ||
		rs.GetFieldIndex(_T("TargetID")) < 0 ||
		rs.GetFieldIndex(_T("Target_Pile_ID")) < 0 ||
		rs.GetFieldIndex(_T("Target_Layer_ID")) < 0 
		)
		return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloomChange; pRS->QueryInterface(IID_IL3RecordSet,rsBloomChange); pRS->Release();
	rsBloomChange.AddField(_T("MaterialType"),VT_BSTR);
	rsBloomChange.AddField(_T("MaterialID"),VT_BSTR);
	rsBloomChange.AddField(_T("Amount"),VT_INT);
	rsBloomChange.AddField(_T("TargetID"),VT_BSTR);
	rsBloomChange.AddField(_T("Target_Pile_ID"),VT_BSTR);
	rsBloomChange.AddField(_T("Target_Layer_ID"),VT_BSTR);
	rsBloomChange.AddField(_T("SourceID"),VT_BSTR);
	rsBloomChange.AddField(_T("Cur_Pile_ID"),VT_BSTR);
	rsBloomChange.AddField(_T("Cur_Layer_ID"),VT_BSTR);
	rsBloomChange.AppendRecord();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}
	rs.MoveFirst();
	//判断是否库区变更
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csOldPos = rs.GetFieldByName(_T("Position")).ToCString();
		CString csNewPos = rs.GetFieldByName(_T("TargetID")).ToCString();
		CString csUri = BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID;

		if(csOldPos!=csNewPos)//转库区
		{
			rsBloomChange.CopyCurRowFrom(rs);
			rsBloomChange.SetFieldByName(_T("SourceID"),rs.GetFieldByName(_T("Position")));
			if(!MoveMaterials(L3RECORDSET(rsBloomChange)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -3;
			}
			if(!SetObjectPropValue(csUri,_T("Position"),rs.GetFieldByName(_T("TargetID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
			if(!SetObjectPropValue(csUri,_T("Cur_Pile_ID"),rs.GetFieldByName(_T("Target_Pile_ID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
			if(!SetObjectPropValue(csUri,_T("Cur_Layer_ID"),rs.GetFieldByName(_T("Target_Layer_ID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
		}
		else//垛位变更
		{
			if(!SetObjectPropValue(csUri,_T("Cur_Pile_ID"),rs.GetFieldByName(_T("Target_Pile_ID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
			if(!SetObjectPropValue(csUri,_T("Cur_Layer_ID"),rs.GetFieldByName(_T("Target_Layer_ID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}

		}
		rsBloomChange.MoveFirst();
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return 0;
	// TODO : 请在此添加逻辑代码
}



/// <Method class="CBloom_Store_Mag" name="BloomColdSendInStore" type="L3BOOL">
/// 
/// 将一批材料入库。
/// ARG &gt;&gt; rsInputInfo : 材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID,Cur_Pile_ID,Cur_Layer_ID这几个字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE；
/// <Param name="rsInputInfo" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
/// </Method>
L3LONG CBloom_Store_Mag::BloomColdSendInStore(L3RECORDSET rsInputInfo)
{
	CL3RecordSetWrap rsData =rsInputInfo;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return -1;
	if(rsData.GetFieldIndex(_T("MaterialType")) < 0 ||
		rsData.GetFieldIndex(_T("MaterialID")) < 0 ||
		rsData.GetFieldIndex(_T("Amount")) < 0 ||
		rsData.GetFieldIndex(_T("StoreAreaID")) < 0 ||
		rsData.GetFieldIndex(_T("Cur_Layer_ID")) < 0 ||
		rsData.GetFieldIndex(_T("Cur_Pile_ID")) < 0)
			return -1;

	///2009-02-23增加以下字段
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialType"),VT_BSTR);
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rsBloom.AddField(_T("Amount"),VT_INT);
	rsBloom.AddField(_T("StoreAreaID"),VT_BSTR);
	rsBloom.AddField(_T("SteelGradeIndex"),VT_BSTR);
	rsBloom.AddField(_T("Cur_Pile_ID"),VT_BSTR);
	rsBloom.AddField(_T("Cur_Layer_ID"),VT_BSTR);
	rsBloom.AddField(_T("Bloom_Count"),VT_INT);
	rsBloom.AddField(_T("Waster_Count"),VT_R8);
	rsBloom.AddField(_T("Wrong_Count"),VT_INT);
	rsBloom.AddField(_T("Right_Count"),VT_INT);
	rsBloom.AddField(_T("Length"),VT_INT);
	rsBloom.AddField(_T("Width"),VT_INT);
	rsBloom.AddField(_T("Thickness"),VT_INT);
	rsBloom.AddField(_T("Cal_Weight"),VT_R8);
	rsBloom.AddField(_T("Right_Weight"),VT_R8);
	rsBloom.AddField(_T("Waster_Weight"),VT_R8);
	rsBloom.AddField(_T("Wrong_Weight"),VT_R8);
	rsBloom.AddField(_T("CasterID"),VT_BSTR);

	//判断是否满足入库条件,入库钢坯必需实绩数据完整确认，经过终判，如果满足设置炉次确定标志2009-03-16
	L3LONG nRtn = CCMConfirmHeat(rsInputInfo);
	if( nRtn < 0)
		return nRtn;

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rsBloom.AppendRecord();
		rsBloom.CopyCurRowFrom(rsData);
		CString csMaterialID = rsData.GetFieldByName(_T("MaterialID")).ToCString();				
		CString csTemp = _T("select * from CBloom_Data where MaterialID = '%s'");
		CString csSQL;
		csSQL.Format(csTemp,csMaterialID);
		CL3RecordSetWrap rsBloomInfor;
		if(!Query(csSQL,rsBloomInfor)||rsBloomInfor.IsNull() ||rsBloomInfor.GetRowCount() < 1)
			return -3;

		rsBloomInfor.MoveFirst();
		rsBloomInfor.DelField(_T("Cur_Pile_ID"));
		rsBloomInfor.DelField(_T("Cur_Layer_ID"));
		rsBloom.CopyCurRowFrom(rsBloomInfor);
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

	if (!InputMaterials(rsBloom))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}

	//修改炉次确定标志2009-04-30 从炉次确定方法里移出tangyi
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMaterialID = rsData.GetFieldByName(_T("MaterialID")).ToCString();
		CString csTempSQL =_T("select TreatNo from CCCM_Base_Data where HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csMaterialID);
		CL3RecordSetWrap rsCCMHeat;
		if(!Query(csSQL,rsCCMHeat) || rsCCMHeat.IsNull() || rsCCMHeat.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -86;
		}
		rsCCMHeat.MoveFirst();

		while(!rsCCMHeat.IsEOF())
		{
			CString csTreatNo = rsCCMHeat.GetFieldByName(_T("TreatNo")).ToCString();
			CString csSteelUri = CL3NameParser::MergeClassDomainName(CCM_BASE_DATA_CLASS_URI,csTreatNo);
			if(!SetObjectPropValue(csSteelUri,_T("HeatConfirm"),L3SHORT(1)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -88;
			}
			rsCCMHeat.MoveNext();
		}
		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//改变属性值，通知通讯向NC发送生产投料、生产完工、质量、入库信息2009-03-16
	CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
	CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"),nEvent);

	return 0;
}

//2009-03-16 tangyi
L3LONG CBloom_Store_Mag::CCMConfirmHeat(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csHeatID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		csHeatID.Trim();
		//查看转炉实绩是否已经确认
		if(csHeatID.Left(1)=="2")
		{
		CString csBOFUri = CL3NameParser::MergeClassDomainName(BOF_BASE_DATA_CLASS_URI,csHeatID);
		CL3Variant vaBOFLocked = GetObjectPropValue(csBOFUri,_T("Locked"));
		if(!vaBOFLocked.ToShort()) 
			return -81;
		}
		else
		{
		
		}
		//CString csBOFUri = CL3NameParser::MergeClassDomainName(BOF_BASE_DATA_CLASS_URI,csHeatID);
		//CL3Variant vaBOFLocked = GetObjectPropValue(csBOFUri,_T("Locked"));
		//if(!vaBOFLocked.ToShort()) 
		//	return -81;
		//得到工艺路径
		CString csSteelUri = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,csHeatID);
		CString csPreHeatID = GetObjectPropValue(csSteelUri,_T("PreHeatID")).ToCString();
		csPreHeatID.Trim();
		CString csPlanUri = CL3NameParser::MergeClassDomainName(PLAN_TAPPING_CLASS_URI,csPreHeatID);
		CString csLFID = GetObjectPropValue(csPlanUri,_T("LFID")).ToCString();
		CString csRHID = GetObjectPropValue(csPlanUri,_T("RHID")).ToCString();
		//查看LF炉实绩是否已经确认
		if(csLFID != _T("0"))
		{
			CString csTempSQL =_T("select TreatNo,Locked from CLF_Base_Data where HeatID ='%s' ");
			CString csSQL;
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsLFHeat;
			if(!Query(csSQL,rsLFHeat) || rsLFHeat.IsNull() || rsLFHeat.GetRowCount() < 1)
				return  -82;
			rsLFHeat.MoveFirst();
			while(!rsLFHeat.IsEOF())
			{
				CL3Variant vaLFLocked = rsLFHeat.GetFieldByName(_T("Locked"));
				if(!vaLFLocked.ToShort()) 
					return -83;
				rsLFHeat.MoveNext();
			}
		}
		//查看RH炉实绩是否已经确认
		if(csRHID != _T("0"))
		{
			CString csTempSQL =_T("select TreatNo,Locked from CRH_Base_Data where HeatID ='%s' ");
			CString csSQL;
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsRHHeat;
			if(!Query(csSQL,rsRHHeat) || rsRHHeat.IsNull() || rsRHHeat.GetRowCount() < 1)
				return -84;

			rsRHHeat.MoveFirst();
			while(!rsRHHeat.IsEOF())
			{
				CL3Variant vaRHLocked = rsRHHeat.GetFieldByName(_T("Locked"));
				if(!vaRHLocked.ToShort()) 
					return -85;
				rsRHHeat.MoveNext();
			}
		}	
		//查看连铸实绩是否已经确认

		CString csTempSQL =_T("select TreatNo,Locked from CCCM_Base_Data where HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsCCMHeat;
		if(!Query(csSQL,rsCCMHeat) || rsCCMHeat.IsNull() || rsCCMHeat.GetRowCount() < 1)
			return -86;
		rsCCMHeat.MoveFirst();

		while(!rsCCMHeat.IsEOF())
		{
			CL3Variant vaCCMLocked = rsCCMHeat.GetFieldByName(_T("Locked"));
			if(!vaCCMLocked.ToShort()) 
				return -87;
			rsCCMHeat.MoveNext();
		}
		//判断钢坯是否终判
		CString csBloomUri = CL3NameParser::MergeClassDomainName(BLOOM_DATA_CLASS_URI,csHeatID);
		CString csFinSteelGradeIndex = GetObjectPropValue(csBloomUri,_T("Final_SteelGradeIndex")).ToCString();
		csFinSteelGradeIndex.Trim();
		L3LONG nProcessType = GetObjectPropValue(csBloomUri,_T("Process_Type")).ToLong();
		csFinSteelGradeIndex.Trim();
		if(csFinSteelGradeIndex.IsEmpty())
			return -89;
		rs.MoveNext();
	}
	return 0;
}
/// <Method class="CBloom_Store_Mag" name="BloomHotSend" type="L3LONG">
/// 
/// 方坯热送
/// ARG&gt;&gt; rsInputInfo : 材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID,Target,SteelGradeIndex这几个字段。
/// RET &lt;&lt;成功返回1，失败返回出错代码
/// <Param name="rsInputInfo" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
/// </Method>
L3LONG CBloom_Store_Mag::BloomHotSend(L3RECORDSET rsInputInfo)
{
	CL3RecordSetWrap rsData =rsInputInfo;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return -1;

	//判断是否满足热送条件,热送钢坯必需实绩数据完整确认，经过终判，如果满足设置炉次确定标志,移出事务2009-04-30
	L3LONG nRtn = CCMConfirmHeat(rsInputInfo);
	if( nRtn < 0)
		return nRtn;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	if(!InputMaterials(rsInputInfo))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -21;
	}
	if(!OutputMaterials(rsInputInfo))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -22;
	}

	//修改炉次确定标志2009-04-30 从炉次确定方法里移出tangyi
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMaterialID = rsData.GetFieldByName(_T("MaterialID")).ToCString();
		CString csTempSQL =_T("select TreatNo from CCCM_Base_Data where HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csMaterialID);
		CL3RecordSetWrap rsCCMHeat;
		if(!Query(csSQL,rsCCMHeat) || rsCCMHeat.IsNull() || rsCCMHeat.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -86;
		}
		rsCCMHeat.MoveFirst();

		while(!rsCCMHeat.IsEOF())
		{
			CString csTreatNo = rsCCMHeat.GetFieldByName(_T("TreatNo")).ToCString();
			CString csSteelUri = CL3NameParser::MergeClassDomainName(CCM_BASE_DATA_CLASS_URI,csTreatNo);
			if(!SetObjectPropValue(csSteelUri,_T("HeatConfirm"),L3SHORT(1)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -88;
			}
			rsCCMHeat.MoveNext();
		}
		rsData.MoveNext();
	}


	if(bUseTrans)
		Commit(nTrans);
	// TODO : 请在此添加逻辑代码

	//改变属性值，通知通讯向NC发送生产投料、生产完工、质量、入库信息2009-03-16
	CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
	CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"),nEvent);

	return 0;
}


/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
/// 
/// 接收钢坯冷送出库信息2009-03-08
/// ARG&gt;&gt; rsData : 材料出库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID,Target这几个字段。
/// RET &lt;&lt;成功返回1，失败返回出错代码
/// <Param name="rsData" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
/// </Method>
L3LONG CBloom_Store_Mag::AcceptBloomOutStoreInforFromNC (L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rsBloom.AddField(_T("Target"),VT_BSTR);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBloom.AppendRecord();
		//2009-03-20 liuzhiqiang
		CString csMaterialID = rs.GetFieldByName(_T("vbatchcode")).ToString();
		if(csMaterialID.GetLength() > 9)
			csMaterialID = csMaterialID.Mid(0,9);
		rsBloom.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		//转换出库去向编码
		CString csTarget;
		//CString csInvcodeID = rs.GetFieldByName(_T("cotherwhid")).ToCString();
		CString csInvcodeID = rs.GetFieldByName(_T("cwarehouseid")).ToCString();
		CString csTempSql = _T("select code from CBase_All_Code where Code_Group ='DESTINATION' and NC_Code ='%s'");
		CString csSQL;
		csSQL.Format(csTempSql,csInvcodeID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
			csTarget = csInvcodeID;
		else
		{
			rsResult.MoveFirst();
			csTarget = rsResult.GetFieldByIndex(0).ToCString();
		}	
		rsBloom.SetFieldByName(_T("Target"),CL3Variant(csTarget));
		rs.MoveNext();
	}

	return AcceptBloomOutStoreInfor((L3RECORDSET)rsBloom);
}
/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
/// 
/// 接收钢坯冷送出库信息
/// ARG&gt;&gt; rsData : 材料出库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID,Target这几个字段。
/// RET &lt;&lt;成功返回1，失败返回出错代码
/// <Param name="rsData" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
/// </Method>
L3LONG CBloom_Store_Mag::AcceptBloomOutStoreInfor(L3RECORDSET rsData)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if( rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Target")) < 0)
			return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialType"),VT_BSTR);
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rsBloom.AddField(_T("Amount"),VT_INT);
	rsBloom.AddField(_T("Target"),VT_BSTR);
	rsBloom.AddField(_T("SteelGradeIndex"),VT_BSTR);
	rsBloom.AddField(_T("StoreAreaID"),VT_BSTR);
	///2009-02-23增加以下字段
	rsBloom.AddField(_T("Bloom_Count"),VT_INT);
	rsBloom.AddField(_T("Waster_Count"),VT_R8);
	rsBloom.AddField(_T("Wrong_Count"),VT_INT);
	rsBloom.AddField(_T("Right_Count"),VT_INT);
	rsBloom.AddField(_T("Length"),VT_INT);
	rsBloom.AddField(_T("Width"),VT_INT);
	rsBloom.AddField(_T("Thickness"),VT_INT);
	rsBloom.AddField(_T("Cal_Weight"),VT_R8);
	rsBloom.AddField(_T("Right_Weight"),VT_R8);
	rsBloom.AddField(_T("Waster_Weight"),VT_R8);
	rsBloom.AddField(_T("Wrong_Weight"),VT_R8);

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBloom.AppendRecord();
		rsBloom.CopyCurRowFrom(rs);
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();		
		//20081213tangyi 钢坯没有终判或者待判不允许出库
		CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID;
		CString csFinSteelGradeIndex = GetObjectPropValue(csBloomUri,_T("Final_SteelGradeIndex")).ToCString();
		L3LONG  nBloomCount = GetObjectPropValue(csBloomUri,_T("Right_Count")).ToLong();//判断是否全炉不合格
		L3LONG	nProcessType = GetObjectPropValue(csBloomUri,_T("Process_Type")).ToLong();//判断是否试轧
		csFinSteelGradeIndex.Trim();
		if(csFinSteelGradeIndex.IsEmpty())
			return -3;
		if(csFinSteelGradeIndex == WAITING_FIN_JUDGE && nProcessType != 1)
			return -4;
		if( nBloomCount == 0)
			return -5;
		//2009-02-23
		CString csTemp = _T("select * from CBloom_Data where MaterialID = '%s'");
		CString csSQL;
		csSQL.Format(csTemp,csMaterialID);
		CL3RecordSetWrap rsBloomInfor;
		if(!Query(csSQL,rsBloomInfor)||rsBloomInfor.IsNull() ||rsBloomInfor.GetRowCount() < 1)
			return -6;
		rsBloomInfor.MoveFirst();
		rsBloom.CopyCurRowFrom(rsBloomInfor);

		rsBloom.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BLOOM));
		rsBloom.SetFieldByName(_T("StoreAreaID"),GetObjectPropValue(csBloomUri,_T("Position")));
		rsBloom.SetFieldByName(_T("Amount"),CL3Variant(L3LONG(1)));
	
		rs.MoveNext();
	}

	if(!OutputMaterials(L3RECORDSET(rsBloom)))
		return -3;
	return 0;
}

/// <Method class="CBloom_Store_Mag" name="GetBloomOnStoreArea" type="L3RECORDSET">
/// 
/// 获取库区钢坯
/// ARG&gt;&gt; strArea:库区。
/// RET &lt;&lt;返回数据集
/// <Param name="strArea" type="L3STRING">库区代码</Param>
/// </Method>
L3RECORDSET CBloom_Store_Mag::GetBloomOnStoreArea(L3STRING strArea,L3STRING strHeatID)
{
	CString csPos = strArea;
	CString csHeatID = strHeatID;
	CString csTemp;
	CString csSQL;
	if(csPos.IsEmpty() && csHeatID.IsEmpty())
	{
		csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.Status > %s and  a.Status < %s and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID ");
		csSQL.Format(csTemp,BLOOM_STATUS_DOWN,BLOOM_STATUS_OUTSTORE);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
			return NULL;
		else
			return rsResult.Detach();
	}
	else
	{
		if(!csPos.IsEmpty() && csHeatID.IsEmpty())
		{
			csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.Position = '%s' and (a.Status > %s and  a.Status < %s )  and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
			csSQL.Format(csTemp,csPos,BLOOM_STATUS_DOWN,BLOOM_STATUS_OUTSTORE);
			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
				return NULL;
			else
				return rsResult.Detach();
		}
		else
		{
			if(csPos.IsEmpty() && !csHeatID.IsEmpty())
			{
				csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.MaterialID like ? and (a.Status > %s and  a.Status < %s ) and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
				csSQL.Format(csTemp,BLOOM_STATUS_DOWN,BLOOM_STATUS_OUTSTORE);
				CString csLikeMaterialID = _T("%") + csHeatID + _T("%");

				VARIANT valParams[1];
				valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csLikeMaterialID.AllocSysString();
				CL3RecordSetWrap rsResult;

				if (!QueryWithParam(csSQL,valParams,1,rsResult) || rsResult.IsNull())	  
				{
					::VariantClear(&valParams[0]);
					return NULL;
				}
				else
				{
					::VariantClear(&valParams[0]);
					return rsResult.Detach();
				}
			}
			else
			{
				if(!csPos.IsEmpty() && !csHeatID.IsEmpty())
				{
					csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.Position = '%s' and a.MaterialID like ? and (a.Status > %s and  a.Status < %s )  and a.SteelGradeIndex = b.SteelGradeIndex(+)  order by a.MaterialID");
					csSQL.Format(csTemp,csPos,BLOOM_STATUS_DOWN,BLOOM_STATUS_OUTSTORE);
					CString csLikeMaterialID = _T("%") + csHeatID + _T("%");
					VARIANT valParams[1];
					valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csLikeMaterialID.AllocSysString();
					CL3RecordSetWrap rsResult;

					if (!QueryWithParam(csSQL,valParams,1,rsResult) || rsResult.IsNull())	  
					{
						::VariantClear(&valParams[0]);
						return NULL;
					}
					else
					{
						::VariantClear(&valParams[0]);
						return rsResult.Detach();
					}
				}

			}
		}
	}

	return NULL;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBloom_Store_Mag" name="BloomFinish" type="L3BOOL">
/// 
/// 钢坯精整质量抽检
/// ARG &gt;&gt; rsHeatID: 钢坯炉号。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE；
/// <Param name="rsHeat" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBloom_Store_Mag::BloomFinish(L3RECORDSET rsHeat)
{
	CL3RecordSetWrap rs = rsHeat;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;

	rs.MoveFirst();
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	while(!rs.IsEOF())
	{
		CString csHeatID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csUri = BLOOM_DATA_CLASS_URI  + _T("\\") + csHeatID;
		if(!SetObjectPropValue(csUri,_T("Status"),CL3Variant(BLOOM_STATUS_CHECK)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if(!SetObjectPropValue(csUri,_T("FinishedTime"),CL3Variant(COleDateTime::GetCurrentTime())))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//改变属性值，通知钢坯终判2009-01-02
	CString csUri = _T("XGMESLogic\\QualityMag\\CQA_HeatSufaceAssume_Mag\\QA_HeatSufaceAssume_Mag");
	CL3Variant varEvent = GetObjectPropValue(csUri,_T("HotJudgeEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csUri,_T("HotJudgeEvent"),nEvent);
	// TODO : 请在此添加逻辑代码

	//改变属性值2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return true;
}

/// <Method class="CBloom_Store_Mag" name="GetWillFinishBloom" type="L3VOID">
/// 
/// 获取可以质量抽检钢坯
/// ARG&gt;&gt; strArea:库区。
/// RET &lt;&lt;返回数据集
/// <Param name="strArea" type="L3STRING">库区代码</Param>
/// </Method>
L3RECORDSET CBloom_Store_Mag::GetWillFinishBloom(L3STRING strArea,L3STRING strHeatID)
{
	//2009-01-07 tangyi增加上垛标志
	CString csPos = strArea;
	CString csHeatID = strHeatID;
	CString csTemp;
	CString csSQL;
	if(csPos.IsEmpty() && csHeatID.IsEmpty())
	{
		csTemp = _T(" select a.*,b.SpileFlagDes  from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where (a.Status = %s or a.Status = %s) and  (a.SteelGradeIndex <> '%s' or (a.SteelGradeIndex  = '%s' and Process_Type = 1))  and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID ");
		csSQL.Format(csTemp,BLOOM_STATUS_INSTORE,BLOOM_STATUS_COOL_JUDGE,WAITING_FIN_JUDGE,WAITING_FIN_JUDGE);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
			return NULL;
		else
			return rsResult.Detach();
	}
	else
	{
		if(!csPos.IsEmpty() && csHeatID.IsEmpty())
		{
			csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.Position = '%s' and (a.Status = %s or a.Status = %s) and  (a.SteelGradeIndex <> '%s' or (a.SteelGradeIndex  = '%s' and a.Process_Type = 1)) and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
			csSQL.Format(csTemp,csPos,BLOOM_STATUS_INSTORE,BLOOM_STATUS_COOL_JUDGE,WAITING_FIN_JUDGE,WAITING_FIN_JUDGE);
			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
				return NULL;
			else
				return rsResult.Detach();
		}
		else
		{
			if(csPos.IsEmpty() && !csHeatID.IsEmpty())
			{
				csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.MaterialID like ? and (a.Status = %s or a.Status = %s) and (a.SteelGradeIndex <> '%s' or (a.SteelGradeIndex  = '%s' and a.Process_Type = 1)) and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
				csSQL.Format(csTemp,BLOOM_STATUS_INSTORE,BLOOM_STATUS_COOL_JUDGE,WAITING_FIN_JUDGE,WAITING_FIN_JUDGE);
				CString csLikeMaterialID = _T("%") + csHeatID + _T("%");

				VARIANT valParams[1];
				valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csLikeMaterialID.AllocSysString();
				CL3RecordSetWrap rsResult;

				if (!QueryWithParam(csSQL,valParams,1,rsResult) || rsResult.IsNull())	  
				{
					::VariantClear(&valParams[0]);
					return NULL;
				}
				else
				{
					::VariantClear(&valParams[0]);
					return rsResult.Detach();
				}
			}
			else
			{
				if(!csPos.IsEmpty() && !csHeatID.IsEmpty())
				{
					csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b  where a.Position = '%s' and a.MaterialID like ? and (a.Status = %s or a.Status = %s) and (a.SteelGradeIndex <> '%s' or (a.SteelGradeIndex  = '%s' and a.Process_Type = 1))  and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
					csSQL.Format(csTemp,csPos,BLOOM_STATUS_INSTORE,BLOOM_STATUS_COOL_JUDGE,WAITING_FIN_JUDGE,WAITING_FIN_JUDGE);
					CString csLikeMaterialID = _T("%") + csHeatID + _T("%");
					VARIANT valParams[1];
					valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csLikeMaterialID.AllocSysString();
					CL3RecordSetWrap rsResult;

					if (!QueryWithParam(csSQL,valParams,1,rsResult) || rsResult.IsNull())	  
					{
						::VariantClear(&valParams[0]);
						return NULL;
					}
					else
					{
						::VariantClear(&valParams[0]);
						return rsResult.Detach();
					}
				}

			}
		}
	}

	return NULL;

	// TODO : 请在此添加逻辑代码
}



/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
/// 
/// 接收钢线材钢坯逆送信息2009-04-02
/// <Param name="rsData" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
/// </Method>
L3LONG CBloom_Store_Mag::AcceptBloomBackInforFromNC (L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBloom.AppendRecord();
		//2009-03-20 liuzhiqiang
		CString csMaterialID = rs.GetFieldByName(_T("vbatchcode")).ToString();
		if(csMaterialID.GetLength() > 9)
			csMaterialID = csMaterialID.Mid(0,9);
		rsBloom.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rs.MoveNext();
	}

	return BloomBack((L3RECORDSET)rsBloom);
}


/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
/// 
/// 钢坯逆送2009-04-02
/// <Param name="rsData" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
/// </Method>
L3LONG CBloom_Store_Mag::BloomBack (L3RECORDSET rsData)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if( rs.GetFieldIndex(_T("MaterialID")) < 0 )
			return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialType"),VT_BSTR);
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rsBloom.AddField(_T("Amount"),VT_INT);


	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBloom.AppendRecord();
		rsBloom.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BLOOM));
		rsBloom.SetFieldByName(_T("MaterialID"),rs.GetFieldByName(_T("MaterialID")));
		rsBloom.SetFieldByName(_T("Amount"),L3LONG(1));
		rs.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	//加入缓存
	CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S71A01"),_T("AddMaterials"),L3RECORDSET(rsBloom));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	//更改钢坯状态
	rsBloom.MoveFirst();
	while(!rsBloom.IsEOF())
	{
		CString csMaterialID = rsBloom.GetFieldByName(_T("MaterialID")).ToCString();
		CString csBloomUri = BLOOM_DATA_CLASS_URI +_T("\\") + csMaterialID;
		if(!SetObjectPropValue(csBloomUri,_T("Position"),CL3Variant(_T("S71A01"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		if(!SetObjectPropValue(csBloomUri,_T("Status"),CL3Variant(BLOOM_STATUS_INSTORE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		if(!SetObjectPropValue(csBloomUri,_T("Back_Flag"),L3LONG(1)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		if(!SetObjectPropValue(csBloomUri,_T("Back_Date"),CL3Variant(timeNow)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}		
		rsBloom.MoveNext();
	}
	if(bUseTrans)
			Commit(nTrans);
	return 0;
}
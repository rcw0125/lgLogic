LONG CBaseData_Mag::Add_Mat_Price(L3RECORDSET dsInfo)// 逻辑类BaseData_Mag的用户逻辑程序源文件

/// <Method class="CBaseData_Mag" name="Add_Mat_Price" type="LONG">
/// 添加物料价格库信息
/// <Param name="dsInfo" type="L3RECORDSET">添加信息</Param>
/// </Method>
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_BaseData_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_BaseData_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CBaseData_Mag.h"
#include "L3NameParser.h"

//当对象被装载到系统中时，被调用
void CBaseData_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}


//当对象被卸载时，被调用
void CBaseData_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <Method class="BaseData_Mag" name="ReceiveBaseData" type="">
/// 
/// 接收NC基本数据信息
/// ARG&gt;&gt; rsData : 基本数据，必须包含DataType字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// </Method>
L3BOOL CBaseData_Mag::ReceiveBaseData()
{
	return 0;// TODO : 请在此添加逻辑代码
}



L3RECORDSET CBaseData_Mag::GetCodeAndDes(L3STRING csCodeGroup)
{
	CString csTemp = _T(" select * from %s where Code_Group = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,_T("XGMESLogic\\BaseDataMag\\CBase_All_Code"),csCodeGroup);
	CL3RecordSetWrap rsResult;
	BOOL bRet = Query(csSQL,rsResult);
	if(!bRet)
		return NULL;
	else
		return rsResult.Detach();

}

L3STRING CBaseData_Mag::GetSysCurDate()
{
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString csCurDate = curTime.Format(_T("%Y-%m-%d %H:%M:%S"));
	return csCurDate.AllocSysString();
}

//获取批次号2009-03-28
L3RECORDSET CBaseData_Mag::GetMaterialBatchID(L3STRING strMaterialCode)
{
	CString csMaterialCode = strMaterialCode;
	CString csTemp;

	//判断是合金还是散装料
	csTemp = _T("select Code_Group from CBase_All_Code where code ='%s' ");
	CString csSQL;
	CL3RecordSetWrap rsType;
	csSQL.Format(csTemp,csMaterialCode);
	if(!Query(csSQL,rsType) || rsType.IsNull() || rsType.GetRowCount() < 1)
		return NULL;

	rsType.MoveFirst();
	CString csMaterialType = rsType.GetFieldByIndex(0).ToCString();

	if(csMaterialType == _T("ALLOY_CODE"))
	{
		csTemp =  _T(" select Batch_ID from (                                                                     ");
		csTemp += _T(" select b.Batch_ID,sum(a.Amount) as Amount from MaterialPosition a,CAlloy_Data  b           ");
		csTemp += _T(" where a.MaterialID = b.MaterialID                                                          ");
		csTemp += _T(" and substr(a.Position,4,1) <> 'P' and  substr(a.Position,4,1) <> 'N'                       ");
		csTemp += _T(" and b.Alloy_Code = '%s' Group by  b.Batch_ID order by Amount ) where  Batch_ID is not null ");
	}
	else
	{
		csTemp =  _T(" select Batch_ID from (                                                                    ");
		csTemp += _T(" select b.Batch_ID,sum(a.Amount) as Amount from MaterialPosition a,CBulk_Data  b           ");
		csTemp += _T(" where a.MaterialID = b.MaterialID                                                         ");
		csTemp += _T(" and substr(a.Position,4,1) <> 'P' and  substr(a.Position,4,1) <> 'N'                      ");
		csTemp += _T(" and b.Bulk_Code = '%s' Group by  b.Batch_ID order by Amount )  where Batch_ID is not null ");
	}

	CL3RecordSetWrap rsResult;
	csSQL.Format(csTemp,csMaterialCode);
	if(!Query(csSQL,rsResult))
		return NULL;
	return rsResult.Detach();
}


/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
/// 
/// 代码数据导入
/// RET &lt;&lt;成功返回1，失败返回0
/// </Method>
L3BOOL CBaseData_Mag::BaseAllCodeInput()
{
	CString csSQL =_T(" select * from CBASE_ALL_CODE_BACK ");
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs)|| rs.IsNull() || rs.GetRowCount() < 0)
		return false;
	rs.DelField(_T("GUID"));
	rs.MoveFirst();
	CreateNewObjects(_T("XGMESLogic\\BaseDataMag\\CBase_All_Code"),rs);
	return true;
}

/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
/// 
/// 改判数据推算
/// RET &lt;&lt;成功返回1，失败返回0
/// </Method>
L3RECORDSET CBaseData_Mag::ModifySteelGrade(CString HeatID,CString CurSteelGradeIndex)
{
	//组建改判后记录集
	CL3RecordSet *pRSRtnMain = new CL3RecordSet();
	CL3RecordSetWrap rsMain; pRSRtnMain->QueryInterface(IID_IL3RecordSet,rsMain); pRSRtnMain->Release();
	rsMain.AddField(_T("MaterialID"),VT_BSTR);//改判后的物料编码主键
	rsMain.AddField(_T("free1"),VT_BSTR);//自由项1
	rsMain.AddField(_T("free2"),VT_BSTR);//自由项2

	CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + HeatID;
	//找物料编码
	CString csWidth  = GetObjectPropValue(csBloomUri,_T("Width")).ToCString();
	CString csThickness  = GetObjectPropValue(csBloomUri,_T("Thickness")).ToCString();
	L3LONG nLength = GetObjectPropValue(csBloomUri,_T("Length")).ToLong()/1000;
	CString csLength;
	csLength.Format(_T("%d"),nLength);
	L3LONG nNexLength = GetObjectPropValue(csBloomUri,_T("Length")).ToLong()%1000;
	CString csNextLength;
	CString csFinalLength;
	if(nNexLength == 0)
	{
		csFinalLength = csLength;
	}
	else if(nNexLength%100 == 0)
	{
		csNextLength.Format(_T("%d"),nNexLength);
		csNextLength = csNextLength.Mid(0,1);
		csFinalLength = csLength + _T(".") + csNextLength;
	}
	else if(nNexLength%10 == 0)
	{
		csNextLength.Format(_T("%d"),nNexLength);
		csNextLength = csNextLength.Mid(0,2);
		csFinalLength = csLength + _T(".") + csNextLength;
	}else
	{
		csNextLength.Format(_T("%d"),nNexLength);
		csFinalLength = csLength + _T(".") + csNextLength;
	}
	//规格+钢种+工艺路径找到唯一的物料编码ID
	CString csChar = _T("×");
	CString csSpec = csThickness + _T("mm") + csChar + csWidth + _T("mm") + csChar + csFinalLength + _T("m");
	CString csPlanOrderID  = GetObjectPropValue(csBloomUri,_T("Plan_Ord_ID")).ToCString();

	//得到改判后钢种、自由项2009-04-21 加上待判
	CString ActSteelGradeIndex;
	if(CurSteelGradeIndex !=WAITING_FIN_JUDGE)
		ActSteelGradeIndex = CurSteelGradeIndex;
	else
		ActSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("Pre_SteelGradeIndex")).ToCString();

	CString csCurSteelIndexUri = QA_STG_RELATION_CLASS_URI + _T("\\") + ActSteelGradeIndex;
	CString csCurSteelGrade= GetObjectPropValue(csCurSteelIndexUri,_T("SteelGrade")).ToCString();
	CString csCurZyx1 =  GetObjectPropValue(csCurSteelIndexUri,_T("NC_Zyx1")).ToCString();
	CString csCurZyx2 =  GetObjectPropValue(csCurSteelIndexUri,_T("NC_Zyx2")).ToCString();
	//得到原来的工艺路径
	CString csPlanOrderUri = PLAN_ORDER_CLASS_URI + _T("\\") + csPlanOrderID;
	CString csRoute = GetObjectPropValue(csPlanOrderUri,_T("Product_Route")).ToCString();
	CString csMatIDSQL = _T("select PK_Material_Bas from CBASE_MATERIAL_BASE_INFOR where Material_Spec ='%s' and Material_Type ='%s' and Route = '%s'");
	CString csSQL;
	CL3RecordSetWrap rsResult;
	csSQL.Format(csMatIDSQL,csSpec,csCurSteelGrade,csRoute);
	if(!Query(csSQL,rsResult))
		return NULL;
	rsResult.MoveFirst();

	CString csCurMaterialID = rsResult.GetFieldByIndex(0).ToCString();

	rsMain.AppendRecord();
	rsMain.SetFieldByName(_T("MaterialID"),CL3Variant(csCurMaterialID));
	rsMain.SetFieldByName(_T("free1"),CL3Variant(csCurZyx1));
	rsMain.SetFieldByName(_T("free2"),CL3Variant(csCurZyx2));

	return rsMain.Detach();
}


/// <Method class="CBaseData_Mag" name="ConfirmIronBloomInStoreInfor" type="L3LONG">
///从NC接收钢铁料信息
/// RET &lt;&lt;成功返回1，失败返回0 2009-03-18
/// </Method>
L3BOOL CBaseData_Mag::ReceiveSteelmaterialInforFromNC(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//判断来料信息
	CL3RecordSetWrap rsTelData;
	if(!CreateClassPropSet(_T("XGMESLogic\\BaseDataMag\\CBase_Steel_Mat_Tel_Data"),rsTelData))
		return false;

	rsTelData.DelField(_T("GUID"));
	rsTelData.CopyFrom(rs);
	rsTelData.MoveFirst();
	while(!rsTelData.IsEOF())
	{
		rsTelData.SetFieldByName(_T("Rec_Time"),timeNow);
		rsTelData.MoveNext();
	}

	//记录废钢电文信息
	if(CreateNewObjects(_T("XGMESLogic\\BaseDataMag\\CBase_Steel_Mat_Tel_Data"),rsTelData) < rsTelData.GetRowCount())
		return false;

	//2009-05-22 同一种物料多次下料，架构目前不支持批量操作，故改为单步操作
	CL3RecordSetWrap rsRecData;
	if(!CreateClassPropSet(_T("XGMESLogic\\BaseDataMag\\CBase_Steel_Mat_Tel_Data"),rsRecData))
		return false;

	rsRecData.AppendRecord();
	rsRecData.MoveFirst();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csStore = rs.GetFieldByName(_T("cwarehouseid")).ToCString();
		//2009-03-19 liuzhiqiang
		if(csStore.IsEmpty())
			return false;

		rsRecData.CopyCurRowFrom(rs);

		//合金:炼钢厂合金库、炼钢厂耐材库
		if(csStore == _T("1006AA100000000E8U7E") || csStore == _T("CKDA0000000000000010") || csStore == _T("1001NC100000001J1L5B") ||csStore == _T("1001NC100000001J1L5C")) //modify by hyh 2012-06-21
		{
			CL3Variant vsRtn = InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("AlloyDataAcceptFromNC"),(L3RECORDSET)rsRecData);
			if(vsRtn.IsError() || vsRtn.ToLong() < 0)
				return false;
		}
		else
		{
			//散装料
			/*if(csStore == _T("CKDA0000000000000007")||csStore == _T("1001NC100000001J1L5C"))*/ //modify by hyh 2012-06-19
			if(csStore == _T("CKDA0000000000000007"))
			{
				CL3Variant vsRtn = InvokeObjectMethod(BULK_STORE_OBJ_URI,_T("BulkDataAcceptFromNC"),(L3RECORDSET)rsRecData);
				if(vsRtn.IsError() || vsRtn.ToLong() < 0)
					return false;
			}
			else
			{
				//废钢生铁
				if(csStore == _T("CKDA0000000000000009"))
				{
					CL3Variant vsRtn = InvokeObjectMethod(SCRAP_STORE_OBJ_URI,_T("ScrapDataAcceptFromNC"),(L3RECORDSET)rsRecData);
					if(vsRtn.IsError() || vsRtn.ToLong() < 0)
						return false;
				}
				else
				{
					//合金退库
					if(csStore == _T("CKDA0000000000000008"))
					{
						CL3Variant vsRtn = InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("AlloyBackAcceptFromNC"),(L3RECORDSET)rsRecData);
						if(vsRtn.IsError() || vsRtn.ToLong() < 0)
							return false;
					}
					else
					{
						//线材钢坯退库
						if(csStore == _T("1006AA100000000EBWCE"))
						{
							CL3Variant vsRtn = InvokeObjectMethod(BLOOM_STORE_OBJ_URI,_T("AcceptBloomBackInforFromNC"),(L3RECORDSET)rsRecData);
							if(vsRtn.IsError() || vsRtn.ToLong() < 0)
								return false;
						}
						else
						{
							//钢坯转库出库
							CL3Variant vsRtn = InvokeObjectMethod(BLOOM_STORE_OBJ_URI,_T("AcceptBloomOutStoreInforFromNC"),(L3RECORDSET)rsRecData);
							if(vsRtn.IsError() || vsRtn.ToLong() < 0)
								return false;
						}
					}
				}
			}
		}
		rsRecData.MoveFirst();
		rs.MoveNext();
	}
	return true;
}




/// <Method class="CBloom_Store_Mag" name="WriteLogFromNC" type="L3LONG">
/// 
/// 根据发送的电文记录日志
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3BOOL CBaseData_Mag::WriteLogFromNC(L3RECORDSET rsData)
{
	// TODO : 请在此添加逻辑代码
	COleDateTime NowTime = COleDateTime::GetCurrentTime();
	CL3RecordSetWrap rs = rsData;
	if (rs.IsNull() || rs.GetRowCount()<1)
		return false;	
	rs.MoveFirst();

	//创建数据集结构
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(_T("XGMESLogic\\BaseDataMag\\CRetrunData_NC"),rsLog)) return false;
	rsLog.CopyFrom(L3RECORDSET(rs));

	rsLog.MoveFirst();
	while(!rsLog.IsEOF())
	{
		rsLog.SetFieldByName(_T("CreateTime"),CL3Variant(NowTime));
		//正常
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("MillPlanToNC.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("订单")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("BOFAddMaterialsInforToNC.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("投料")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("BloomInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("完工")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("QualityJudgeInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("质检")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("BloomInStoreInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("入库")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("IronBloomInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("完工")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("IronQualityJudgeInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("质检")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("IronBloomInStoreInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("入库")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("InStoreQualityInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("入库改判")));


		//补发
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("updateMillPlanToNC.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("订单")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("updateMaterialsInforToNC.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("投料")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("updateBloomInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("完工")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("updateQualityJudgeInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("质检")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("updateBloomInStoreInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("入库")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("updateIronBloomInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("完工")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("updateIronQualityJudgeInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("质检")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("updateIronBloomInStoreInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("入库")));
		if(rsLog.GetFieldByName(_T("BillType")).ToCString() == _T("updateInStoreQualityInfor.xslt"))
			rsLog.SetFieldByName(_T("BillType"),CL3Variant(_T("入库改判")));

		rsLog.MoveNext();
	}
	//写数据
	if(!CreateNewObjects(_T("XGMESLogic\\BaseDataMag\\CRetrunData_NC"),L3RECORDSET(rsLog)))
		return false;
	return true;
}





/// <Method class="CBaseData_Mag" name="SendPlanInfor" type="L3LONG">
/// 2009-03-26 liuzhiqiang
/// 向NC补发生产计划电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::SendPlanInfor(L3STRING strHeatID)
{
	CString csTemp = _T(" select PlanID from CPlan_Tapping where  HeatID = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return NULL;

#pragma region "组建返回数据集"
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsPlan; pRSRtn->QueryInterface(IID_IL3RecordSet,rsPlan); pRSRtn->Release();
	rsPlan.AddField(_T("HeatID"),VT_BSTR);
	rsPlan.AddField(_T("Flag"),VT_BSTR);//1表示:钢 2表示:铁
	rsPlan.AddField(_T("scddh"),VT_BSTR);//生产订单号
	rsPlan.AddField(_T("pk_poid"),VT_BSTR);//计划订单号主键(*)(从NC下发的生产订单获取)
	rsPlan.AddField(_T("jhddh"),VT_BSTR);//计划订单号
	rsPlan.AddField(_T("wlbmid"),VT_BSTR);//产品(*)(从基础数据存货基本档案中获取)
	rsPlan.AddField(_T("pk_produce"),VT_BSTR);//产品生产档案
	rsPlan.AddField(_T("invcode"),VT_BSTR);//物料编码
	rsPlan.AddField(_T("nvname"),VT_BSTR);//物料名称
	rsPlan.AddField(_T("pch"),VT_BSTR);//批次号(*)
	rsPlan.AddField(_T("scbmid"),VT_BSTR);//生产部门(*)(从基础数据部门档案中获取)
	rsPlan.AddField(_T("gzzxid"),VT_BSTR);//工作中心(*)(从基础数据工作中心档案中获取)
	rsPlan.AddField(_T("gzzxbm"),VT_BSTR);//工作中心编码
	rsPlan.AddField(_T("ksid"),VT_BSTR);//客户
	rsPlan.AddField(_T("memo"),VT_BSTR);//备注
	rsPlan.AddField(_T("sfjj"),VT_BSTR);//是否加急
	rsPlan.AddField(_T("yxj"),VT_BSTR);//优先级
	rsPlan.AddField(_T("bcid"),VT_BSTR);//班次(*)(从基本数据班次档案中获取)
	rsPlan.AddField(_T("bzid"),VT_BSTR);//班组(*)(从基本数据班组档案中获取)
	rsPlan.AddField(_T("jhkgrq"),VT_BSTR);//计划开工日期(*)
	rsPlan.AddField(_T("jhwgrq"),VT_BSTR);//计划完工日期(*)
	rsPlan.AddField(_T("jhkssj"),VT_BSTR);//计划开始时间(*)
	rsPlan.AddField(_T("jhjssj"),VT_BSTR);//计划结束时间(*)
	rsPlan.AddField(_T("sjkgrq"),VT_BSTR);//实际开工日期(*)
	rsPlan.AddField(_T("sjwgrq"),VT_BSTR);//实际完工日期(*)
	rsPlan.AddField(_T("sjkssj"),VT_BSTR);//实际开始时间(*)
	rsPlan.AddField(_T("sjjssj"),VT_BSTR);//实际结束时间(*)
	rsPlan.AddField(_T("jhwgsl"),VT_R8);//计划生产数量(*)
	rsPlan.AddField(_T("fjhsl"),VT_R8);//辅计划数量(*)(有就填写,没有就不填)

	/**************************************************************/
	//2009-03-03 Modify by liuzhiqiang
	rsPlan.AddField(_T("jldwid"),VT_BSTR);//计量单位ID(*)(从基本数据计量档案中获取)
	rsPlan.AddField(_T("fjlid"),VT_BSTR);//辅计量单位ID(*)(从基本数据计量档案中获取)(有就填写,没有就不填)
	/**************************************************************/

	rsPlan.AddField(_T("sjwgsl"),VT_R8);//实际生产数量(*)
	rsPlan.AddField(_T("fwcsl"),VT_R8);//辅完工数量(*)
	rsPlan.AddField(_T("zdy1"),VT_BSTR);//自定义1
	rsPlan.AddField(_T("zdy2"),VT_BSTR);//自定义2
	rsPlan.AddField(_T("zdy3"),VT_BSTR);//自定义3
	rsPlan.AddField(_T("zdy4"),VT_BSTR);//自定义4
	rsPlan.AddField(_T("zdy5"),VT_BSTR);//自定义5
	rsPlan.AddField(_T("zyx1"),VT_BSTR);//自由项1(产品标准)(*)
	rsPlan.AddField(_T("zyx2"),VT_BSTR);//自由项2(技术要求)(*)
	rsPlan.AddField(_T("zyx3"),VT_BSTR);//自由项3
	rsPlan.AddField(_T("zyx4"),VT_BSTR);//自由项4
	rsPlan.AddField(_T("zyx5"),VT_BSTR);//自由项5
	rsPlan.AddField(_T("pk_corp"),VT_BSTR);//公司
	rsPlan.AddField(_T("gcbm"),VT_BSTR);//工厂
	rsPlan.AddField(_T("zdrid"),VT_BSTR);//操作员工号(*)
	rsPlan.AddField(_T("pk_moid"),VT_BSTR);//生产订单主键
	rsPlan.AddField(_T("PlanID"),VT_BSTR);//计划号
	rsPlan.AddField(_T("NC_Confirm_Flag"),VT_BSTR);//NC确认标志
#pragma endregion

	CString csHeatID=strHeatID;

	//判断是否为全回炉
	CString csTempSQL = _T(" select * from CSteel_Data where HeatID = '%s' ");
	CString csSQLAll;
	csSQLAll.Format(csTempSQL,strHeatID);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQLAll,rsSteelData) || rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return NULL;
	rsSteelData.MoveFirst();
	CString csType = rsSteelData.GetFieldByName(_T("Status")).ToCString();
	//全回炉
	if(csType == _T("5"))
	{
#pragma region "全回炉"
		rs.MoveFirst();
		while(!rs.IsEOF())
		{
			CString csPlanID = rs.GetFieldByName(_T("PlanID")).ToCString();
			CString csTempSQL4  = _T(" select a.HeatID,'1' as Flag,a.PlanID,b.pk_poid,a.Plan_Ord_ID as jhddh,b.MATERIALCODE_ID as wlbmid,b.MaterialCode as invcode,a.HeatID as pch,case when substr(a.heatid,1,1)='2'  then  '1001NC1000000000037T' else '1001NC100000003C8ORS' end as scbmid,case when a.CASTERID ='S61'  then '1001NC100000000015R4' when a.CASTERID ='S62' then 			");
			csTempSQL4 += _T(" '1001NC100000000015R6' when a.CASTERID ='S63'then '1001NC100000000015R7' when a.CASTERID ='S64' then '1001NC100000000015R8' when a.CASTERID ='S65' then '1001NC100000000015R9' when a.CASTERID ='S67' then '1001NC100000002DPNDB' when a.CASTERID ='S66' and substr(a.HeatID,1,1)='2' then '1001NC100000001JTY8G' when a.CASTERID ='S66' and substr(a.HeatID,1,1)='6' then '1001NC100000002DDER1' else a.CASTERID end as gzzxid,f.Bloom_Count as fjhsl,'jlda0000000000000012'as jldwid, 		");
			csTempSQL4 += _T(" '0001AA100000000BR5AE' as fjlid,a.Planner as zdrid,a.HeatID as Pch,case when c.Shift ='1'then '1001NC1000000000103W' when c.shift ='2' then '1001NC1000000000103X' when c.shift='3' then '1001NC1000000000103Y' else c.shift end as bcid,case								");
			csTempSQL4 += _T(" when c.Team ='1' and a.CASTERID ='S61' then '1001NC10000000004BRY' when c.Team ='2' and a.CASTERID ='S61' then '1001NC10000000004BS1' when c.Team ='3' and a.CASTERID ='S61' then '1001NC10000000004BS4' when c.Team ='4' and a.CASTERID ='S61' then '1001NC10000000004BSD'	");      											
			csTempSQL4 += _T(" when c.Team ='1' and a.CASTERID ='S62' then '1001NC10000000004BSF' when c.Team ='2' and a.CASTERID ='S62' then '1001NC10000000004BSH' when c.Team ='3' and a.CASTERID ='S62' then '1001NC10000000004BSJ' when c.Team ='4' and a.CASTERID ='S62' then '1001NC10000000004BSL'	"); 
			csTempSQL4 += _T(" when c.Team ='1' and a.CASTERID ='S63' then '1001NC10000000004BSN' when c.Team ='2' and a.CASTERID ='S63' then '1001NC10000000004BSP' when c.Team ='3' and a.CASTERID ='S63' then '1001NC10000000004BSR' when c.Team ='4' and a.CASTERID ='S63' then '1001NC10000000004BST'	"); 
			csTempSQL4 += _T(" when c.Team ='1' and a.CASTERID ='S64' then '1001NC10000000004W8Z' when c.Team ='2' and a.CASTERID ='S64' then '1001NC10000000004W91' when c.Team ='3' and a.CASTERID ='S64' then '1001NC10000000004WBS' when c.Team ='4' and a.CASTERID ='S64' then '1001NC10000000004WBU'	"); 
			csTempSQL4 += _T(" when c.Team ='1' and a.CASTERID ='S65' then '1001NC10000000004BSV' when c.Team ='2' and a.CASTERID ='S65' then '1001NC10000000004BSX' when c.Team ='3' and a.CASTERID ='S65' then '1001NC10000000004BSZ' when c.Team ='4' and a.CASTERID ='S65' then '1001NC10000000004BT1'  "); 
			csTempSQL4 += _T(" when c.Team ='1' and a.CASTERID ='S67' then '1001NC100000002E7W12' when c.Team ='2' and a.CASTERID ='S67' then '1001NC100000002E7W1K' when c.Team ='3' and a.CASTERID ='S67' then '1001NC100000002E7W1Z' when c.Team ='4' and a.CASTERID ='S67' then '1001NC100000002E7W23'  ");
			//add by hyh 2012-06-08
			csTempSQL4 += _T(" when c.Team ='1' and a.CASTERID ='S66' then '1001NC100000001NYRC0' when c.Team ='2' and a.CASTERID ='S66' then '1001NC100000001NYRC2' when c.Team ='3' and a.CASTERID ='S66' then '1001NC100000001NYRCO' when c.Team ='4' and a.CASTERID ='S66' then '1001NC100000001NYRCU'  ");
			//end
			csTempSQL4 += _T(" else c.Team end as bzid,to_char(a.Aim_Time_CastingStart,'yyyy-mm-dd') as jhkgrq,to_char(a.Aim_Time_CastingEnd,'yyyy-mm-dd') as jhwgrq,                                                                              															");
			csTempSQL4 += _T(" to_char(a.Aim_Time_CastingStart,'hh24:mi:ss') as jhkssj,to_char(a.Aim_Time_CastingEnd,'hh24:mi:ss') as jhjssj,                                                                                        																		");
			csTempSQL4 += _T(" to_char(c.App_Time,'yyyy-mm-dd') as sjkgrq,to_char(c.App_Time,'yyyy-mm-dd') as sjwgrq,                                                                                        																								");
			csTempSQL4 += _T(" to_char(c.App_Time,'hh24:mi:ss') as sjkssj,to_char(c.App_Time,'hh24:mi:ss') as sjjssj,                                                                                        																								");
			csTempSQL4 += _T(" a.Aim_Tapped_Weight as jhwgsl,round(c.App_Steel_Weight,3) as sjwgsl,NULL as zdy1, NULL as zdy2,NULL as zdy3,NULL as zdy4,NULL as zdy5,                                                                																		");
			csTempSQL4 += _T(" b.ProduceStd as zyx1,b.Tech_Request as zyx2,NULL as zyx3, NULL as zyx4,NULL as zyx5,b.Corp as pk_corp,                                                                                                																		");
			csTempSQL4 += _T(" b.Factory as gcbm,NULL as Zdrbm,NULL as pk_moid  from CPlan_Tapping a,CPlan_Order b,CDisp_SteelTurn_App c,CPlan_Tapping_Act d,                                                                        																		");
			csTempSQL4 += _T(" CPlan_Casting f  where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.PlanID =d.PreHeatID and a.PlanID =f.PlanID and a.PlanID ='%s' and c.ALL_TURN_FLAG = 1                                                         												    ");
			//Modify end
			CString csSQL4;
			csSQL4.Format(csTempSQL4,csPlanID);
			CL3RecordSetWrap rsResult4;
			if(!Query(csSQL4,rsResult4))
				return NULL;
			rsPlan.CopyFrom(rsResult4);
			rs.MoveNext();
		}
#pragma endregion
	}
	else
	{
#pragma region "非全回炉"
		rs.MoveFirst();

		while(!rs.IsEOF())
		{
			CString csPlanID = rs.GetFieldByName(_T("PlanID")).ToCString();
			CString csTempSQL4  = _T(" select a.HeatID,'1' as Flag,a.PlanID,c.TreatNo as scddh,b.pk_poid,a.Plan_Ord_ID as jhddh,b.MATERIALCODE_ID as wlbmid,b.MaterialCode as invcode,														 ");
			csTempSQL4 += _T(" a.HeatID as pch,a.HeatID as pch,case when substr(a.heatid,1,1)='2'  then '1001NC1000000000037T' else '1001NC100000003C8ORS' end as scbmid,case when a.CASTERID ='S61' then '1001NC100000000015R4' when a.CASTERID ='S62' then '1001NC100000000015R6' when a.CASTERID ='S63'                    ");
			csTempSQL4 += _T(" then '1001NC100000000015R7' when a.CASTERID ='S64' then '1001NC100000000015R8' when a.CASTERID ='S65' then '1001NC100000000015R9' when a.CASTERID ='S67' then '1001NC100000002DPNDB'  when a.CASTERID ='S66' and substr(a.HeatID,1,1)='2' then '1001NC100000001JTY8G' when a.CASTERID ='S66' and substr(a.HeatID,1,1)='6' then '1001NC100000002DDER1' else a.CASTERID end as gzzxid,										 ");
			csTempSQL4 += _T(" f.Bloom_Count as fjhsl,'jlda0000000000000012'as jldwid, '0001AA100000000BR5AE' as fjlid,a.Planner as zdrid,a.HeatID as Pch,									                                         ");
			csTempSQL4 += _T(" case when c.Shift ='1'then '1001NC1000000000103W' when c.shift ='2' then '1001NC1000000000103X' when c.shift='3' then '1001NC1000000000103Y' else c.shift end as bcid,                                ");
			csTempSQL4 += _T(" case when c.Team ='1' and a.CASTERID ='S61' then '1001NC10000000004BRY' when c.Team ='2' and a.CASTERID ='S61' then '1001NC10000000004BS1'							                                 ");
			csTempSQL4 += _T(" when c.Team ='3' and a.CASTERID ='S61' then '1001NC10000000004BS4' when c.Team ='4' and a.CASTERID ='S61' then '1001NC10000000004BSD' when c.Team ='1' and a.CASTERID ='S62'                          ");
			csTempSQL4 += _T("  then '1001NC10000000004BSF' when c.Team ='2' and a.CASTERID ='S62' then '1001NC10000000004BSH' when c.Team ='3' and a.CASTERID ='S62' then '1001NC10000000004BSJ'                                    ");
			csTempSQL4 += _T(" when c.Team ='4' and a.CASTERID ='S62' then '1001NC10000000004BSL' when c.Team ='1' and a.CASTERID ='S63' then '1001NC10000000004BSN' when c.Team ='2' and a.CASTERID ='S63'                          ");
			csTempSQL4 += _T(" then '1001NC10000000004BSP' when c.Team ='3' and a.CASTERID ='S63' then '1001NC10000000004BSR' when c.Team ='4' and a.CASTERID ='S63' then '1001NC10000000004BST' when c.Team ='1' and                ");
			csTempSQL4 += _T(" a.CASTERID ='S64' then '1001NC10000000004W8Z' when c.Team ='2' and a.CASTERID ='S64' then '1001NC10000000004W91' when c.Team ='3' and a.CASTERID ='S64' then '1001NC10000000004WBS' when c.Team ='4'  ");
			csTempSQL4 += _T(" and a.CASTERID ='S64' then '1001NC10000000004WBU' when c.Team ='1' and a.CASTERID ='S65' then '1001NC10000000004BSV' when c.Team ='2' and a.CASTERID ='S65' then '1001NC10000000004BSX' when          ");
			csTempSQL4 += _T(" c.Team ='3' and a.CASTERID ='S65' then '1001NC10000000004BSZ' when c.Team ='4' and a.CASTERID ='S65' then '1001NC10000000004BT1'  											 ");
			csTempSQL4 += _T(" when c.Team ='1' and a.CASTERID ='S66' then '1001NC100000001NYRC0' when c.Team ='2' and a.CASTERID ='S66' then '1001NC100000001NYRC2' when c.Team ='3' and a.CASTERID ='S66' then '1001NC100000001NYRCO' when c.Team ='4' and a.CASTERID ='S66' then '1001NC100000001NYRCU'  ");//add by hyh 2012-06-08
			csTempSQL4 += _T(" when c.Team ='1' and a.CASTERID ='S67' then '1001NC100000002E7W12' when c.Team ='2' and a.CASTERID ='S67' then '1001NC100000002E7W1K' when c.Team ='3' and a.CASTERID ='S67' then '1001NC100000002E7W1Z' when c.Team ='4' and a.CASTERID ='S67' then '1001NC100000002E7W23' else c.Team end as bzid,  ");
			csTempSQL4 += _T(" to_char(a.Aim_Time_CastingStart,'yyyy-mm-dd') as jhkgrq,to_char(a.Aim_Time_CastingEnd,'yyyy-mm-dd') as jhwgrq,                                                                                        ");
			csTempSQL4 += _T(" to_char(a.Aim_Time_CastingStart,'hh24:mi:ss') as jhkssj,to_char(a.Aim_Time_CastingEnd,'hh24:mi:ss') as jhjssj,                                                                                        ");
			csTempSQL4 += _T(" to_char(d.Act_Time_CastingStart,'yyyy-mm-dd') as sjkgrq,to_char(d.Act_Time_CastingEnd,'yyyy-mm-dd') as sjwgrq,                                                                                        ");
			csTempSQL4 += _T(" to_char(d.Act_Time_CastingStart,'hh24:mi:ss') as sjkssj,to_char(d.Act_Time_CastingEnd,'hh24:mi:ss') as sjjssj,                                                                                        ");
			csTempSQL4 += _T(" a.Aim_Tapped_Weight as jhwgsl,round(e.Weight,3) as sjwgsl,NULL as zdy1, NULL as zdy2,NULL as zdy3,NULL as zdy4,NULL as zdy5,                                                                          ");
			csTempSQL4 += _T(" b.ProduceStd as zyx1,b.Tech_Request as zyx2,NULL as zyx3, NULL as zyx4,NULL as zyx5,b.Corp as pk_corp,                                                                                                ");
			csTempSQL4 += _T(" b.Factory as gcbm,NULL as Zdrbm,NULL as pk_moid  from CPlan_Tapping a,CPlan_Order b,CCCM_Base_Data c,CPlan_Tapping_Act d,                                                                             ");
			csTempSQL4 += _T(" CCCM_HEAT_LADLE e,CPlan_Casting f  where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.PlanID =d.PreHeatID and a.HeatID =e.HeatID                                                             ");
			csTempSQL4 += _T("  and  a.PlanID =f.PlanID and a.PlanID ='%s'																																							 ");
			//Modify end
			CString csSQL4;
			csSQL4.Format(csTempSQL4,csPlanID);
			CL3RecordSetWrap rsResult4;
			if(!Query(csSQL4,rsResult4))
				return NULL;
			rsPlan.CopyFrom(rsResult4);

			rs.MoveNext();
		}
#pragma endregion
	}

	return rsPlan.Detach();
}





/// <Method class="CBaseData_Mag" name="SendAddMaterialsInfor" type="L3LONG">
/// 2009-03-26 liuzhiqiang
/// 向NC补发生产发投料电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::SendAddMaterialsInfor(L3STRING strHeatID,L3RECORDSET *rsMainData)
{
	CString csHeatID = strHeatID;

#pragma region  "组建记录集"
	//组建返回数据集
	CL3RecordSet *pRSRtnMain = new CL3RecordSet();
	CL3RecordSetWrap rsMain; pRSRtnMain->QueryInterface(IID_IL3RecordSet,rsMain); pRSRtnMain->Release();
	rsMain.AddField(_T("HeatID"),VT_BSTR);
	rsMain.AddField(_T("Flag"),VT_BSTR);//1表示:钢 2表示:铁
	rsMain.AddField(_T("scddh"),VT_BSTR);//生产订单号
	rsMain.AddField(_T("zdrid"),VT_BSTR);//操作员编号(*)(调度排产的工号)
	rsMain.AddField(_T("pch"),VT_BSTR);//生产批次号(*)
	rsMain.AddField(_T("wlbmid"),VT_BSTR);//物料编码id(*)
	rsMain.AddField(_T("jldwid"),VT_BSTR);//计量单位id(*)
	rsMain.AddField(_T("ylbmid"),VT_BSTR);//用料部门id(*)
	rsMain.AddField(_T("bljhdh"),VT_BSTR);//备料计划单号
	rsMain.AddField(_T("zdrq"),VT_BSTR);//制单日期(*)(算铸机开浇时间)
	rsMain.AddField(_T("freeitemvalue1"),VT_BSTR);//自由项1(*)(产品标准)
	rsMain.AddField(_T("freeitemvalue2"),VT_BSTR);//自由项2(*)(技术要求)
	rsMain.AddField(_T("freeitemvalue3"),VT_BSTR);//自由项3
	rsMain.AddField(_T("freeitemvalue4"),VT_BSTR);//自由项4
	rsMain.AddField(_T("freeitemvalue5"),VT_BSTR);//自由项5	
	rsMain.AddField(_T("ObjectID"),VT_BSTR);
	rsMain.AddField(_T("NC_Confirm_Flag"),VT_BSTR);//确认标志
	rsMain.AddField(_T("TreatNo"),VT_BSTR);//处理号


	CL3RecordSet *pRSRtn = new CL3RecordSet();

	CL3RecordSetWrap rsMaterials; pRSRtn->QueryInterface(IID_IL3RecordSet,rsMaterials); rsMaterials->Release();
	//从表信息
	rsMaterials.AddField(_T("kgyid"),VT_BSTR);//投料操作员编码(*)
	rsMaterials.AddField(_T("ckckid"),VT_BSTR);//发料仓库(*)(从基础数据仓库档案获取)
	rsMaterials.AddField(_T("ckckbm"),VT_BSTR);//发料仓库编码
	rsMaterials.AddField(_T("wlbmid"),VT_BSTR);//物料编码id(*)(从基础物料档案获取)
	rsMaterials.AddField(_T("jldwid"),VT_BSTR);//计量单位id(*)(从基础计量档案获取)
	rsMaterials.AddField(_T("fjldwid"),VT_BSTR);//辅计量单位id(*)从基础计量档案获取)(有就填写,没有就不填)
	rsMaterials.AddField(_T("ljcksl"),VT_R8);//投料数量(*)
	rsMaterials.AddField(_T("fljcksl"),VT_R8);//投料辅数量(*)(有就填写,没有就不填)
	rsMaterials.AddField(_T("pch"),VT_BSTR);//投料物料批次号(*)(出库时的批次号)
	rsMaterials.AddField(_T("gzzxid"),VT_BSTR);//投料工作中心(*)(从基础工作中心档案获取)
	rsMaterials.AddField(_T("gxh"),VT_BSTR);//工序号
	rsMaterials.AddField(_T("zdy1"),VT_BSTR);//自定义1
	rsMaterials.AddField(_T("zdy2"),VT_BSTR);//自定义2
	rsMaterials.AddField(_T("zdy3"),VT_BSTR);//自定义3
	rsMaterials.AddField(_T("zdy4"),VT_BSTR);//自定义4
	rsMaterials.AddField(_T("zdy5"),VT_BSTR);//自定义5
	rsMaterials.AddField(_T("zyx1"),VT_BSTR);//自由项1(产品标准)(*)(有就填写,没有就不填)
	rsMaterials.AddField(_T("zyx2"),VT_BSTR);//自由项2(技术要求)(*)(有就填写,没有就不填)
	rsMaterials.AddField(_T("zyx3"),VT_BSTR);//自由项3
	rsMaterials.AddField(_T("zyx4"),VT_BSTR);//自由项4
	rsMaterials.AddField(_T("zyx5"),VT_BSTR);//自由项5
	rsMaterials.AddField(_T("pk_corp"),VT_BSTR);//公司
	rsMaterials.AddField(_T("gcbm"),VT_BSTR);//工厂
	rsMaterials.AddField(_T("ccostobject"),VT_BSTR);//成本对象主键(存货管理档案,取生产订单的产品存货档案得到,生成材料出库单时要用到)
	rsMaterials.AddField(_T("flrq"),VT_BSTR);//发料日期(*)(算铸机开浇时间)
	rsMaterials.AddField(_T("pk_moid"),VT_BSTR);//备料计划单主键
	rsMaterials.AddField(_T("ObjectID"),VT_BSTR);
#pragma endregion

	//add by hyh 2012-06-19  对不锈钢合金库和低位料仓库 和炼钢厂的进行区分
	CL3RecordSetWrap rsPlanTapping;
	CString csSql;CString csCasterID;CString csLFID ;CString csBofID;
	csSql.Format(_T("select BOFID,CASTERID,LFID from %s where HEATID='%s'"),PLAN_TAPPING_CLASS_URI,csHeatID);
	if(Query(csSql,rsPlanTapping)&&rsPlanTapping.GetRowCount()>0)
	{
		CString csTempSQL;
		CString csSQL;
		rsPlanTapping.MoveFirst();
		csBofID = rsPlanTapping.GetFieldByName (_T("BOFID")).ToString ();//转炉号
		csCasterID=rsPlanTapping.GetFieldByName(_T("CASTERID")).ToString();	//铸机号
		csLFID=rsPlanTapping.GetFieldByName(_T("LFID")).ToString(); //精炼号
	}
	//end

	if(csBofID=="S25")
	{
	

	
	//判断是否为全回炉
	CString csTempSQL = _T(" select * from CSteel_Data where HeatID = '%s' ");
	CString csSQL;
	csSQL.Format(csTempSQL,strHeatID);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData) || rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return NULL;
	rsSteelData.MoveFirst();
	CString csType = rsSteelData.GetFieldByName(_T("Status")).ToCString();
	//全回炉 
	if(csType == _T("5"))
	{
#pragma region "全回炉处理"
		//转炉投料信息	
		CString csTempSQL  = _T(" select a.HeatID,'1' as Flag,a.HeatID as pch,a.HeatID as ObjectID,b.MATERIALCODE_ID as wlbmid,									");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as zdrid,to_char(a.CreateDate, 'yyyy-mm-dd')  as zdrq,								");
		csTempSQL += _T(" b.ProduceStd as freeitemvalue1,b.Tech_Request as freeitemvalue2 from CPlan_Tapping a,CPlan_Order b,Caod_Addition_Data c		"); 
		csTempSQL += _T(" where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and c.HeatID = '%s'														");  
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultMain;
		if(!Query(csSQL,rsResultMain))
			return NULL;
		if(rsResultMain.GetRowCount()<1)
			return NULL;
		rsResultMain.MoveFirst();
		rsMain.AppendRecord();
		rsMain.CopyCurRowFrom(rsResultMain);

		//modify by hyh 2012-06-25
		//转炉合金
		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																									");
		csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,  		");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,																		 		");
		csTempSQL += _T(" '1001NC100000002DDER1' as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,'1006AA100000000E8U7E' as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_Addition_Data c, 									 		");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type=5  and c.Element <> '67103' and d.ALL_TURN_FLAG = 1  "); 
		csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid	                                               																                "); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultBOF1;
		if(!Query(csSQL,rsResultBOF1))
			return NULL;
		rsResultBOF1.MoveFirst();
		rsMaterials.CopyFrom(rsResultBOF1);

		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,																			");
		csTempSQL += _T(" a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,									");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,																				");
		csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  'CKDA0000000000000007'   as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_Addition_Data c, 											");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103' and d.ALL_TURN_FLAG = 1 )	"); 	
		csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																																"); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultBOF2;
		if(!Query(csSQL,rsResultBOF2))
			return NULL;
		rsResultBOF2.MoveFirst();
		rsMaterials.CopyFrom(rsResultBOF2);

			// 脱磷站物料消耗
		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,																			");
		csTempSQL += _T(" a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,									");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,																				");
		csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  'CKDA0000000000000007'   as ckckid from CPlan_Tapping a,CPlan_Order b,Cdep_Addition_Data c, 											");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	 and c.Element <> '67103' and d.ALL_TURN_FLAG = 1 )	"); 	
		csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																																"); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultDEP;
		if(!Query(csSQL,rsResultDEP))
			return NULL;
		rsResultDEP.MoveFirst();
		rsMaterials.CopyFrom(rsResultDEP);

		//转炉铁水
		//铁水
		csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'CHDA0000000000009282' as wlbmid,c.IRONWEIGHT as ljcksl,																");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,													");
		//csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end	");
		csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,'CKDA0000000000000026' as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_FEED_DATA c, 					");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s' and d.ALL_TURN_FLAG = 1				"); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultBOF3;
		if(!Query(csSQL,rsResultBOF3))
			return NULL;
		rsResultBOF3.MoveFirst();
		rsMaterials.CopyFrom(rsResultBOF3);

		///////////////////20160319 屏蔽生铁废钢
		//生铁
		//csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYN' as wlbmid,c.PIGIRONWEIGHT as ljcksl,																");
		//csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,													");
		////csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
		//csTempSQL += _T(" '1001NC100000002DDER1' as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_FEED_DATA c, 						");
		//csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s' and d.ALL_TURN_FLAG = 1 					"); 
		//csSQL.Format(csTempSQL,csHeatID);
		//CL3RecordSetWrap rsResultBOF4;
		//if(!Query(csSQL,rsResultBOF4))
		//	return NULL;
		//rsResultBOF4.MoveFirst();
		//rsMaterials.CopyFrom(rsResultBOF4);


		//废钢
		//csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYM' as wlbmid,c.SCRAPWEIGHT as ljcksl,																	");
		//csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,														");
		////csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
		//csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_FEED_DATA c, 						");
		//csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'  and d.ALL_TURN_FLAG = 1 					"); 
		//csSQL.Format(csTempSQL,csHeatID);
		//CL3RecordSetWrap rsResultBOF5;
		//if(!Query(csSQL,rsResultBOF5))
		//	return NULL;
		//rsResultBOF5.MoveFirst();
		//rsMaterials.CopyFrom(rsResultBOF5);


	
		//modify by hyh 2012-06-19
		if(csLFID==_T("S44"))
		{
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
			csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
			csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000002DDER1' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	");//modify by hyh 2012-06-08
			csTempSQL += _T("  To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                		");
			csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'  and d.ALL_TURN_FLAG = 1 	");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																			            "); 
		}
		else
		{
			//csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
			//csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
			//csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
			//csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	");//modify by hyh 2012-06-08
			//csTempSQL += _T("  To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                		");
			//csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'  and d.ALL_TURN_FLAG = 1 	");
			//csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																			            "); 
		}
		//Modify end
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResult1;
		if(!Query(csSQL,rsResult1))
			return NULL;
		rsResult1.MoveFirst();
		rsMaterials.CopyFrom(rsResult1);
		//LF喂线
		//modify by hyh 2012-06-19
		if(csLFID==_T("S44"))
		{
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																      ");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		      ");
			csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when  ");
			csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000002DDER1' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,				  ");//modify by hyh 2012-06-08
			csTempSQL += _T(" To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 						      ");
			csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'  and d.ALL_TURN_FLAG = 1 		      ");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid															          ");
			//Modify end
		}
		else
		{
			//csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																      ");
			//csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		      ");
			//csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when  ");
			//csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,				  ");//modify by hyh 2012-06-08
			//csTempSQL += _T(" To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 						      ");
			//csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'  and d.ALL_TURN_FLAG = 1 		      ");
			//csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid															          ");

		}
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResult2;
		if(!Query(csSQL,rsResult2))
			return NULL;
		rsResult2.MoveFirst();
		rsMaterials.CopyFrom(rsResult2);

		
#pragma endregion
	}
	else
	{
#pragma region "非全回炉"
		//2009-08-21 添加因为拨坯产生的投料平衡 唐毅
		CString csTempBloomSQL =_T(" select * from CBloom_Data where MaterialID = '%s'");
		CString csBloomSQL;
		csBloomSQL.Format(csTempBloomSQL,csHeatID);
		CL3RecordSetWrap rsBloom;
		if(!Query(csBloomSQL,rsBloom))
			return NULL;
		if(rsBloom.GetRowCount() < 1)
			return NULL;
		//计划钢坯支数
		L3DOUBLE nPlanBloomCount = rsBloom.GetFieldByName(_T("Plan_Bloom_Count")).ToDouble();
		//实际钢坯支数
		L3DOUBLE nBloomCount = rsBloom.GetFieldByName(_T("Bloom_Count")).ToDouble();		
		//拨出钢坯支数
		L3DOUBLE nDivBloomCount = rsBloom.GetFieldByName(_T("Div_Bloom_Count")).ToDouble();		
		//拨入钢坯支数1
		L3DOUBLE nAddBloomCount1 = rsBloom.GetFieldByName(_T("Add_Bloom_Count")).ToDouble();
		//拨入钢坯支数2
		L3DOUBLE nAddBloomCount2 = rsBloom.GetFieldByName(_T("Add_Bloom_Count2")).ToDouble();
		//拨入炉号1
		CString strAddHeatID1 = rsBloom.GetFieldByName(_T("Add_HeatID1")).ToCString();
		//拨入炉号2
		CString strAddHeatID2 = rsBloom.GetFieldByName(_T("Add_HeatID2")).ToCString();

		//计划钢坯支数+拨入钢坯支数1+拨入钢坯支数2-拨出钢坯支数=实际钢坯支数
		//判断该炉是拨入钢坯还是拨出钢坯
		L3BOOL bIsDivBloom = false;
		if(nDivBloomCount > 0 || (nDivBloomCount ==0 && nAddBloomCount1 == 0 && nAddBloomCount2 == 0)) bIsDivBloom =true; else bIsDivBloom =false;

		//转炉投料主表信息	
		CString csTempSQL  = _T(" select a.HeatID,'1' as Flag,a.HeatID as pch,a.HeatID as ObjectID,b.MATERIALCODE_ID as wlbmid,															");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as zdrid,to_char(d.CastingStartTime, 'yyyy-mm-dd')  as zdrq,											    ");
		//csTempSQL += _T(" b.ProduceStd as freeitemvalue1,b.Tech_Request as freeitemvalue2,d.TreatNo from CPlan_Tapping a,CPlan_Order b,Caod_Addition_Data c,CCCM_Process_Data d "); 
		//csTempSQL += _T(" where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'														");  
		csTempSQL += _T(" b.ProduceStd as freeitemvalue1,b.Tech_Request as freeitemvalue2,d.TreatNo from CPlan_Tapping a,CPlan_Order b,CCCM_Process_Data d "); 
		csTempSQL += _T(" where a.Plan_Ord_ID = b.PlanID and  a.HeatID =d.HeatID and a.HeatID = '%s'														");  
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultMain;
		if(!Query(csSQL,rsResultMain))
			return NULL;
		if(rsResultMain.GetRowCount()<1)
			return NULL;
		rsResultMain.MoveFirst();
		rsMain.AppendRecord();
		rsMain.CopyCurRowFrom(rsResultMain);

		if(bIsDivBloom)//拨出或者不拨坯
		{
#pragma region "拨出或者不拨坯处理"
			//拨出钢坯投料调整系数，总的投料*系数=总的投料 - （总的投料/计划钢坯支数）*拨出钢坯支数
			L3DOUBLE fBanlance;
			if(nPlanBloomCount > 0)
				fBanlance = nBloomCount / nPlanBloomCount;
			else
				fBanlance =1;

			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,																			");
			//csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end							");
			csTempSQL += _T(" '1001NC100000002DDER1' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_Addition_Data c, 								");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'		and c.Element <> '67103'						");
			csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 

			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResultBOF1;
			if(!Query(csSQL,rsResultBOF1))
				return NULL;
			rsResultBOF1.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF1);

			////转炉辅料2009-08-06

			//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,											");
			//csTempSQL += _T(" a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,			");
			//csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,													");
			////csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			//csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5C' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 			");
			//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103')	"); 	
			//csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																										"); 
			//csSQL.Format(csTempSQL,fBanlance,csHeatID);

			//CL3RecordSetWrap rsResultBOF2;
			//if(!Query(csSQL,rsResultBOF2))
			//	return NULL;
			//rsResultBOF2.MoveFirst();
			//rsMaterials.CopyFrom(rsResultBOF2);

			//  脱磷站物料消耗
			//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
			//csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
			//csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,																			");
			////csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end							");
			//csTempSQL += _T(" '1001NC100000002DDER1' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,Cdep_Addition_Data c, 								");
			//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'		and c.Element <> '67103'						");
			//csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 

			//csSQL.Format(csTempSQL,fBanlance,csHeatID);

			//CL3RecordSetWrap rsResultDEP;
			//if(!Query(csSQL,rsResultDEP))
			//	return NULL;
			//rsResultDEP.MoveFirst();
			//rsMaterials.CopyFrom(rsResultDEP);



			//转炉铁水2009-08-06
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'CHDA0000000000009282' as wlbmid,round(c.IRONWEIGHT * '%f',6) as ljcksl,																	");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,													");
			//csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1001NC100000001J1L6O' as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResultBOF3;
			if(!Query(csSQL,rsResultBOF3))
				return NULL;
			rsResultBOF3.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF3);

			//生铁2009-08-06
			//csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYN' as wlbmid,round(c.PIGIRONWEIGHT * '%f',6) as ljcksl,													    ");
			//csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,													");
			////csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			//csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1001NC100000001J1L5D' as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_FEED_DATA c, 				");
			//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			//csSQL.Format(csTempSQL,fBanlance,csHeatID);

			//CL3RecordSetWrap rsResultBOF4;
			//if(!Query(csSQL,rsResultBOF4))
			//	return NULL;
			//rsResultBOF4.MoveFirst();
			//rsMaterials.CopyFrom(rsResultBOF4);

			//废钢2009-08-06
			//csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYM' as wlbmid,round(c.SCRAPWEIGHT * '%f',6) as ljcksl,															");
			//csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,													");
			////csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			//csTempSQL += _T(" '1001NC100000002DDER1'  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1001NC100000001J1L5D' as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_FEED_DATA c, 				");
			//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			//csSQL.Format(csTempSQL,fBanlance,csHeatID);


			//CL3RecordSetWrap rsResultBOF5;
			//if(!Query(csSQL,rsResultBOF5))
			//	return NULL;
			//rsResultBOF5.MoveFirst();
			//rsMaterials.CopyFrom(rsResultBOF5);


			//回炉钢水2009-08-06
		/*	csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001AA1000000002IQ4W' as wlbmid,round(c.Return_Steel_Weight *'%f',6) as ljcksl,													");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1006AA100000000E8UQ1' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,fBanlance,csHeatID);


			CL3RecordSetWrap rsResultSteel;
			if(!Query(csSQL,rsResultSteel))
				return NULL;
			rsResultSteel.MoveFirst();
			rsMaterials.CopyFrom(rsResultSteel);*/

			//炉后喂丝2009-08-06

			//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
			//csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000		");
			//csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			//csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end					");
			//csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1006AA100000000E8U7E' as ckckid from CPlan_Tapping a,CPlan_Order b,CTAP_ADDITION_DATA c, 						");
			//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'								"); 
			//csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													"); 

			//csSQL.Format(csTempSQL,fBanlance,csHeatID);

			//CL3RecordSetWrap rsResultBOF6;
			//if(!Query(csSQL,rsResultBOF6))
			//	return NULL;
			//rsResultBOF6.MoveFirst();
			//rsMaterials.CopyFrom(rsResultBOF6);

			//LF合金2009-08-06
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000002DDER1' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,							    ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
				//Modify end
			}
			else
			{
				//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
				//csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				//csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				//csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,							    ");//modify by hyh 2012-06-08 新增4#LF
				//csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1006AA100000000E8U7E' as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				//csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
				//Modify end
			}
			csSQL.Format(csTempSQL,fBanlance,csHeatID);


			CL3RecordSetWrap rsResult1;
			if(!Query(csSQL,rsResult1))
				return NULL;
			rsResult1.MoveFirst();
			rsMaterials.CopyFrom(rsResult1);

			//LF喂线2009-08-06
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(														 ");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000002DDER1' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			else
			{
				//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(														 ");
				//csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				//csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				//csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				//csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				//csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			//Modify end
			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResult2;
			if(!Query(csSQL,rsResult2))
				return NULL;
			rsResult2.MoveFirst();
			rsMaterials.CopyFrom(rsResult2);


#pragma endregion
		}
		else//拨入钢坯
		{
#pragma region "拨入钢坯"
			//根据拨入炉号获取拨入炉号的计划钢坯支数
			L3DOUBLE nAddPlanBloomCount1 = 0;
			L3DOUBLE nAddPlanBloomCount2 = 0;
			CString csTempSQL =_T(" select * from CBloom_Data where MaterialID = '%s'");
			CString csSQL;
			csSQL.Format(csTempSQL,strAddHeatID1);
			CL3RecordSetWrap rsBloom1;
			if(!Query(csBloomSQL,rsBloom1))
				return NULL;
			if(rsBloom.GetRowCount() < 1)
				nAddPlanBloomCount1 = 0;
			else
			{
				rsBloom1.MoveFirst();
				nAddPlanBloomCount1 = rsBloom1.GetFieldByName(_T("Plan_Bloom_Count")).ToDouble();
			}

			csTempSQL =_T(" select * from CBloom_Data where MaterialID = '%s'");
			csSQL.Format(csTempSQL,strAddHeatID2);
			CL3RecordSetWrap rsBloom2;
			if(!Query(csBloomSQL,rsBloom2))
				return NULL;
			if(rsBloom2.GetRowCount() < 1)
				nAddPlanBloomCount2 = 0;
			else
			{
				rsBloom2.MoveFirst();
				nAddPlanBloomCount2 = rsBloom2.GetFieldByName(_T("Plan_Bloom_Count")).ToDouble();
			}

			//拨入钢坯投料调整系数，总的投料=总的投料 + （拨入炉号1总的投料/拨入炉号1计划钢坯支数）*拨入钢坯支数1 + （拨入炉号2总的投料/拨入炉号2计划钢坯支数）*拨入钢坯支数2
			L3DOUBLE fBanlance1 = 0;
			if(nAddPlanBloomCount1 > 0) fBanlance1 = nAddBloomCount1 / nAddPlanBloomCount1; else fBanlance1 = 0;

			L3DOUBLE fBanlance2 = 0;
			if(nAddPlanBloomCount2 > 0) fBanlance2 = nAddBloomCount2 / nAddPlanBloomCount2; else fBanlance2 = 0;

#pragma region "当前炉号应属于的转炉工作中心,后面做替换"
			CString csBOFID = csHeatID.Mid(1,1);
			CString csNCCenter;


			//if(csBOFID == _T("1"))
			//	csNCCenter = _T("1001NC100000000015QG");
			//else
			//	if(csBOFID == _T("2"))
			//		csNCCenter = _T("1001NC100000000015QN");
			//	else
			//		if(csBOFID == _T("3"))
			//			csNCCenter = _T("1001NC100000000015QS");
			//		else
			//			if(csBOFID == _T("4"))
			//				csNCCenter = _T("1001NC100000000015QU");
			//			else
							csNCCenter = _T("1001NC100000002DDER1");
#pragma endregion

#pragma region "转炉合金本炉总的投料"
			//2009-08-21转炉合金本炉总的投料
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			            ");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,																		");
			//csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end							");
			csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_Addition_Data c, 								");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'		and c.Element <> '67103'						");
			csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 

			csSQL.Format(csTempSQL,csHeatID);

			CL3RecordSetWrap rsResultBOF1;
			if(!Query(csSQL,rsResultBOF1))
				return NULL;
			rsResultBOF1.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF1);	

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			if(csCasterID==_T("S66"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\'  as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		                    ");
				csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
				csTempSQL += csNCCenter;
				csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_Addition_Data c, 								");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type=5	and c.Element <> '67103'						");
				csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 
			}
			else
			{
/*				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\'  as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		                    ");
				csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
				csTempSQL += csNCCenter;
				csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 								");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type=5	and c.Element <> '67103'						");
				csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																														"); */
			}
			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF2;
				if(!Query(csSQL,rsResultBOF2))
					return NULL;
				rsResultBOF2.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF2);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF3;
				if(!Query(csSQL,rsResultBOF3))
					return NULL;
				rsResultBOF3.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF3);	
			}
#pragma endregion

#pragma region "本炉转炉辅料"


			//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,											");
			//csTempSQL += _T(" a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,			");
			//csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,														");
			////csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			//csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5C'     as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_Addition_Data c, 			");
			//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103')	"); 	
			//csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																										"); 
			//csSQL.Format(csTempSQL,csHeatID);

			//CL3RecordSetWrap rsResultBOF4;
			//if(!Query(csSQL,rsResultBOF4))
			//	return NULL;
			//rsResultBOF4.MoveFirst();
			//rsMaterials.CopyFrom(rsResultBOF4);

			////按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			//if(csCasterID==_T("S66"))
			//{
			//	csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,\'");
			//	csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
			//	csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
			//	csTempSQL += csNCCenter;
			//	csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5C'    as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_Addition_Data c, 			");
			//	csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103')	"); 	
			//	csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																										"); 
			//}
			//else
			//{
			//	/*csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,\'");
			//	csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
			//	csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
			//	csTempSQL += csNCCenter;
			//	csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  'CKDA0000000000000007'    as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 			");
			//	csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103')	"); 	
			//	csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																									"); */	
			//}
			////拨入炉号1
			//if(fBanlance1 > 0)
			//{
			//	csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
			//	CL3RecordSetWrap rsResultBOF5;
			//	if(!Query(csSQL,rsResultBOF5))
			//		return NULL;
			//	rsResultBOF5.MoveFirst();
			//	rsMaterials.CopyFrom(rsResultBOF5);	
			//}

			////拨入炉号2
			//if(fBanlance2 > 0)
			//{
			//	csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
			//	CL3RecordSetWrap rsResultBOF6;
			//	if(!Query(csSQL,rsResultBOF6))
			//		return NULL;
			//	rsResultBOF6.MoveFirst();
			//	rsMaterials.CopyFrom(rsResultBOF6);	
			//}
#pragma endregion

#pragma region "DEP脱磷 合金本炉总的投料"
//			//2009-08-21转炉合金本炉总的投料
//			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			            ");
//			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
//			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,																		");
//			//csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end							");
//			csTempSQL += _T("  '1001NC100000002DDER1' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,CDEP_Addition_Data c, 								");
//			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'		and c.Element <> '67103'						");
//			csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 
//
//			csSQL.Format(csTempSQL,csHeatID);
//
//			CL3RecordSetWrap rsResultDEP;
//			if(!Query(csSQL,rsResultDEP))
//				return NULL;
//			rsResultDEP.MoveFirst();
//			rsMaterials.CopyFrom(rsResultDEP);	
//
//			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
//			if(csCasterID==_T("S66"))
//			{
//				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
//				csTempSQL += _T(" select c.Batch_ID as pch,\'");
//				csTempSQL += csHeatID + _T("\'  as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		                    ");
//				csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
//				csTempSQL += csNCCenter;
//				csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CDEP_Addition_Data c, 								");
//				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'		and c.Element <> '67103'						");
//				csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 
//			}
//			else
//			{
///*				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
//				csTempSQL += _T(" select c.Batch_ID as pch,\'");
//				csTempSQL += csHeatID + _T("\'  as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		                    ");
//				csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
//				csTempSQL += csNCCenter;
//				csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 								");
//				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type=5	and c.Element <> '67103'						");
//				csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																														"); */
//			}
//			//拨入炉号1
//			if(fBanlance1 > 0)
//			{
//				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
//				CL3RecordSetWrap rsResultDEP2;
//				if(!Query(csSQL,rsResultDEP2))
//					return NULL;
//				rsResultDEP2.MoveFirst();
//				rsMaterials.CopyFrom(rsResultDEP2);	
//			}
//
//			//拨入炉号2
//			if(fBanlance2 > 0)
//			{
//				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
//				CL3RecordSetWrap rsResultDEP3;
//				if(!Query(csSQL,rsResultDEP3))
//					return NULL;
//				rsResultDEP3.MoveFirst();
//				rsMaterials.CopyFrom(rsResultDEP3);	
//			}
#pragma endregion

#pragma region "转炉本炉铁水"

			//转炉本炉铁水
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'CHDA0000000000009282' as wlbmid,round(c.IRONWEIGHT,6) as ljcksl,															");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,														");
			//csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T(" '1001NC100000002DDER1' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1001NC100000001J1L6O' as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,csHeatID);

			CL3RecordSetWrap rsResultBOF7;
			if(!Query(csSQL,rsResultBOF7))
				return NULL;
			rsResultBOF7.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF7);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			csTempSQL  = _T(" select NULL as pch,\'");
			csTempSQL += csHeatID + _T("\' as ObjectID,'CHDA0000000000009282' as wlbmid,round(c.IRONWEIGHT *'%f',6) as ljcksl,															");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
			csTempSQL += csNCCenter;
			csTempSQL += _T("\'  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1001NC100000001J1L6O' as ckckid from CPlan_Tapping a,CPlan_Order b,Caod_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												");

			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF8;
				if(!Query(csSQL,rsResultBOF8))
					return NULL;
				rsResultBOF8.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF8);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF9;
				if(!Query(csSQL,rsResultBOF9))
					return NULL;
				rsResultBOF9.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF9);	
			}
#pragma endregion





#pragma region "LF本炉合金"
			//LF本炉合金2009-08-06
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) ,6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000002DDER1' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	 ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
			}
			else
			{
				//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) ,6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				//csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				//csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				//csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	 ");//modify by hyh 2012-06-08 新增4#LF
				//csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				//csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
			}
			//Modify end

			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF22;
			if(!Query(csSQL,rsResultBOF22))
				return NULL;
			rsResultBOF22.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF22);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉,LF投料中心不用换
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f' ,6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																	    ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000002DDER1' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	  ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
			}
			else
			{
				//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f' ,6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																	    ");
				//csTempSQL += _T(" select c.Batch_ID as pch,\'");
				//csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				//csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				//csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	  ");//modify by hyh 2012-06-08 新增4#LF
				//csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				//csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
			}
			//Modify end

			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF23;
				if(!Query(csSQL,rsResultBOF23))
					return NULL;
				rsResultBOF23.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF23);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF24;
				if(!Query(csSQL,rsResultBOF24))
					return NULL;
				rsResultBOF24.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF24);	

			}

#pragma endregion

#pragma region "LF本炉喂线"
			//LF本炉喂线2009-08-21
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																     ");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000002DDER1' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			else
			{
				//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																     ");
				//csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				//csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				//csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				//csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,   '1006AA100000000E8U7E' as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				//csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			//Modify end
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF25;
			if(!Query(csSQL,rsResultBOF25))
				return NULL;
			rsResultBOF25.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF25);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉,LF投料中心不用换
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																     ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000002DDER1' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			else
			{
				//csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																     ");
				//csTempSQL += _T(" select c.Batch_ID as pch,\'");
				//csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				//csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				//csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				//csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				//csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				//csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			//Modify end

			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF26;
				if(!Query(csSQL,rsResultBOF26))
					return NULL;
				rsResultBOF26.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF26);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF27;
				if(!Query(csSQL,rsResultBOF27))
					return NULL;
				rsResultBOF27.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF27);	

			}
#pragma endregion




#pragma endregion

		}

#pragma endregion
	}	

#pragma region "删除垃圾数据"
	//2009-04-21 Modify by liuzhiqang
	//01#合成渣,冶金灰入130库
	//其余的合成渣入133库
	rsMaterials.MoveFirst();
	while(!rsMaterials.IsEOF())
	{
		//物料代码为空，或重量为0
		if(rsMaterials.GetFieldByName(_T("ljcksl")).ToCString() == _T("0") || rsMaterials.GetFieldByName(_T("wlbmid")).ToCString().IsEmpty())
		{
			rsMaterials.DeleteRecord();
		}
		else
		{
			//modify by hyh 2012-06-21
			CString csMaterialCode = rsMaterials.GetFieldByName(_T("wlbmid")).ToCString();
			CString csCenter= rsMaterials.GetFieldByName(_T("gzzxid")).ToCString();
			CString ckck= rsMaterials.GetFieldByName(_T("ckckid")).ToCString();
			// 0001AA1000000009UZTT 精炼合成渣XGYRZ-01 0001AA1000000003U1WJ 新冶金灰                               0001NC100000000FR9LG脱磷用氧化铁皮
			 if(csMaterialCode == _T("0001AA1000000009UZTT") || csMaterialCode == _T("0001AA1000000003U1WJ")|| csMaterialCode == _T("0001NC100000000FR9LG")|| csMaterialCode == _T("0001NC100000000FR9LG")) 
			 {
			  rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5C")));//炼钢厂低位料二仓
			 }
			 // 0001NC1000000010US04武安二级AOD用石灰             济南一级AOD用石灰0001NC1000000010US01            淄博一级AOD用石灰0001NC100000000L6A28         炼钢用轻烧白云石0001AA1000000006WAIQ   
			  else if(csMaterialCode == _T("0001NC1000000010US04") || csMaterialCode == _T("0001NC1000000010US01")|| csMaterialCode == _T("0001NC100000000L6A28")|| csMaterialCode == _T("0001AA1000000006WAIQ")) 
			 {
			  rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5C")));//炼钢厂低位料二仓
			 }
			 //CHDA0000000000009283 生铁  0001NC100000000JJH0Z 镍系不锈钢切废 0001NC100000000J2LA7钼系不锈钢切废 0001NC100000000J2LA9铜系不锈钢切废 0001NC100000000JJH1V铬系不锈钢切废     
			 else if(csMaterialCode == _T("CHDA0000000000009283")|| csMaterialCode == _T("0001NC100000000JJH0Z")|| csMaterialCode == _T("0001NC100000000J2LA7") ||csMaterialCode == _T("0001NC100000000J2LA9")||csMaterialCode == _T("0001NC100000000JJH1V"))
			 {
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5D")));//不锈钢钢铁料仓库 
			 }
			 //0001NC100000000O4YLQ200系切废                                       镍铁10-150001NC100000000C1B1N              镍铁8-100001NC100000000ITWHY                     镍铁6-80001NC100000000CEDPT             自产Gr-Ni-Cu系不锈废钢0001NC100000000I21D7
			  else if(csMaterialCode == _T("0001NC100000000O4YLQ")|| csMaterialCode == _T("0001NC100000000C1B1N")|| csMaterialCode == _T("0001NC100000000ITWHY") ||csMaterialCode == _T("0001NC100000000J2LA9")||csMaterialCode == _T("0001NC100000000I21D7"))
			 {
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5D")));//不锈钢钢铁料仓库 
			 }
			 // 自产Gr-Ni-2Mo不锈废钢0001NC100000000I21D5             自产Gr-Ni不锈废钢0001NC10000000082R06       自产Gr不锈废钢0001NC100000000I21D8         200系不锈钢废钢0001NC100000000O4YLP                              5公分冷料0001AA100000000AZXIR 
			 else if(csMaterialCode == _T("0001NC100000000I21D5")|| csMaterialCode == _T("0001NC10000000082R06")|| csMaterialCode == _T("0001NC100000000I21D8") ||csMaterialCode == _T("0001NC100000000O4YLP")||csMaterialCode == _T("0001AA100000000AZXIR"))
			 {
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5D")));//不锈钢钢铁料仓库 
			 }

		 /*   if(csMaterialCode == _T("0001AA1000000009UZTV") || csMaterialCode == _T("0001AA100000000BGKGY") || csMaterialCode == _T("0001AA100000000AXQ2B") || csMaterialCode == _T("0001AA1000000005L7EA") || csMaterialCode == _T("0001AA10000000004GYT")) 
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5B")));*/

			rsMaterials.MoveNext();
			//end
		}
	}

	//modify by hyh 2012-07-12
	//rsMaterials.MoveFirst();
	//while(!rsMaterials.IsEOF())
	//{
	//	if(rsMaterials.GetFieldByName(_T("ljcksl")).ToCString() == _T("0") || rsMaterials.GetFieldByName(_T("wlbmid")).ToCString().IsEmpty())
	//	{
	//		rsMaterials.DeleteRecord();
	//	}
	//	else
	//	{
	//		CString csMaterialCode = rsMaterials.GetFieldByName(_T("wlbmid")).ToCString();
	//		CString csCenter= rsMaterials.GetFieldByName(_T("gzzxid")).ToCString();
	//		CString ckck= rsMaterials.GetFieldByName(_T("ckckid")).ToCString();
	//		//1001NC100000001KDV0W 4#LF机组   1001NC100000001JTY8G 6#机机组  1006AA100000000E8U7E 合金一库  CKDA0000000000000007低仓一库
	//		if((csCenter==_T("1001NC100000001KDV0W")||csCenter==_T("1001NC100000001JTY8G"))&&ckck==_T("1006AA100000000E8U7E"))
	//			rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5B")));
	//		if((csCenter==_T("1001NC100000001KDV0W")||csCenter==_T("1001NC100000001JTY8G"))&&ckck==_T("CKDA0000000000000007"))
	//			rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5C")));

	//		rsMaterials.MoveNext();

	//	}
	//}
	//end
#pragma endregion


	if (*rsMainData != NULL)
		(*rsMainData)->Release();
	(*rsMainData) = rsMain.Detach(); 
	return rsMaterials.Detach();





	}



	///******************************碳钢系统***********************************
	else
	{
	
	
	//判断是否为全回炉
	CString csTempSQL = _T(" select * from CSteel_Data where HeatID = '%s' ");
	CString csSQL;
	csSQL.Format(csTempSQL,strHeatID);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData) || rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return NULL;
	rsSteelData.MoveFirst();
	CString csType = rsSteelData.GetFieldByName(_T("Status")).ToCString();
	//全回炉 
	if(csType == _T("5"))
	{
#pragma region "全回炉处理"
		//转炉投料信息	
		CString csTempSQL  = _T(" select a.HeatID,'1' as Flag,a.HeatID as pch,a.HeatID as ObjectID,b.MATERIALCODE_ID as wlbmid,									");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as zdrid,to_char(a.CreateDate, 'yyyy-mm-dd')  as zdrq,								");
		csTempSQL += _T(" b.ProduceStd as freeitemvalue1,b.Tech_Request as freeitemvalue2 from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c		"); 
		csTempSQL += _T(" where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and c.HeatID = '%s'														");  
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultMain;
		if(!Query(csSQL,rsResultMain))
			return NULL;
		if(rsResultMain.GetRowCount()<1)
			return NULL;
		rsResultMain.MoveFirst();
		rsMain.AppendRecord();
		rsMain.CopyCurRowFrom(rsResultMain);

		//modify by hyh 2012-06-25
		//转炉合金
		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																									");
		csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,  		");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when																		 		");
		csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end						 		");
		csTempSQL += _T("  as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,'1006AA100000000E8U7E' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 									 		");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type=5  and c.Element <> '67103' and d.ALL_TURN_FLAG = 1  "); 
		csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid	                                               																                "); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultBOF1;
		if(!Query(csSQL,rsResultBOF1))
			return NULL;
		rsResultBOF1.MoveFirst();
		rsMaterials.CopyFrom(rsResultBOF1);

		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,																			");
		csTempSQL += _T(" a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,									");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when																				");
		csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end								");
		csTempSQL += _T("  as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  'CKDA0000000000000007'   as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 											");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103' and d.ALL_TURN_FLAG = 1 )	"); 	
		csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																																"); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultBOF2;
		if(!Query(csSQL,rsResultBOF2))
			return NULL;
		rsResultBOF2.MoveFirst();
		rsMaterials.CopyFrom(rsResultBOF2);

		//转炉铁水,生铁,费钢,回炉钢水
		//铁水
		csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'CHDA0000000000009282' as wlbmid,c.IRONWEIGHT as ljcksl,																");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when													");
		csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end	");
		csTempSQL += _T("  as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,'CKDA0000000000000026' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 					");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s' and d.ALL_TURN_FLAG = 1				"); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultBOF3;
		if(!Query(csSQL,rsResultBOF3))
			return NULL;
		rsResultBOF3.MoveFirst();
		rsMaterials.CopyFrom(rsResultBOF3);

		//生铁
		csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYN' as wlbmid,c.PIGIRONWEIGHT as ljcksl,																");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
		csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
		csTempSQL += _T("  as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 						");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s' and d.ALL_TURN_FLAG = 1 					"); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultBOF4;
		if(!Query(csSQL,rsResultBOF4))
			return NULL;
		rsResultBOF4.MoveFirst();
		rsMaterials.CopyFrom(rsResultBOF4);
		//废钢
		csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYM' as wlbmid,c.SCRAPWEIGHT as ljcksl,																	");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
		csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
		csTempSQL += _T("  as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 						");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'  and d.ALL_TURN_FLAG = 1 					"); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultBOF5;
		if(!Query(csSQL,rsResultBOF5))
			return NULL;
		rsResultBOF5.MoveFirst();
		rsMaterials.CopyFrom(rsResultBOF5);

		//回炉钢水
		csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001AA1000000002IQ4W' as wlbmid,c.Return_Steel_Weight as ljcksl,															");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
		csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
		csTempSQL += _T("  as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,'1006AA100000000E8UQ1' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 						");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	 and d.ALL_TURN_FLAG = 1 				"); 
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultSteel;
		if(!Query(csSQL,rsResultSteel))
			return NULL;
		rsResultSteel.MoveFirst();
		rsMaterials.CopyFrom(rsResultSteel);

		//炉后喂丝
		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
		csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000		");
		csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
		csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end					");
		csTempSQL += _T("  as gzzxid,To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CTAP_ADDITION_DATA c, 								");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'  and d.ALL_TURN_FLAG = 1 	"); 
		csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													"); 

		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultBOF6;
		if(!Query(csSQL,rsResultBOF6))
			return NULL;
		rsResultBOF6.MoveFirst();
		rsMaterials.CopyFrom(rsResultBOF6);
		//LF投料信息
		//modify by hyh 2012-06-19
		if(csLFID==_T("S44"))
		{
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
			csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
			csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	");//modify by hyh 2012-06-08
			csTempSQL += _T("  To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                		");
			csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'  and d.ALL_TURN_FLAG = 1 	");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																			            "); 
		}
		else
		{
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
			csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
			csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	");//modify by hyh 2012-06-08
			csTempSQL += _T("  To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                		");
			csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'  and d.ALL_TURN_FLAG = 1 	");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																			            "); 
		}
		//Modify end
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResult1;
		if(!Query(csSQL,rsResult1))
			return NULL;
		rsResult1.MoveFirst();
		rsMaterials.CopyFrom(rsResult1);
		//LF喂线
		//modify by hyh 2012-06-19
		if(csLFID==_T("S44"))
		{
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																      ");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		      ");
			csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when  ");
			csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,				  ");//modify by hyh 2012-06-08
			csTempSQL += _T(" To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 						      ");
			csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'  and d.ALL_TURN_FLAG = 1 		      ");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid															          ");
			//Modify end
		}
		else
		{
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																      ");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		      ");
			csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when  ");
			csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,				  ");//modify by hyh 2012-06-08
			csTempSQL += _T(" To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 						      ");
			csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'  and d.ALL_TURN_FLAG = 1 		      ");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid															          ");

		}
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResult2;
		if(!Query(csSQL,rsResult2))
			return NULL;
		rsResult2.MoveFirst();
		rsMaterials.CopyFrom(rsResult2);

		//RH投料
		//modify by hyh 2012-06-19
		/*if(csCasterID==_T("S66"))
		{
		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																								 ");
		csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) as wlbmid, ");
		csTempSQL += _T(" c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,			     ");
		csTempSQL += _T(" To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_Addition_Data c, 													 ");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'  and d.ALL_TURN_FLAG = 1 			 "); 
		csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																							     ");
		}
		else
		{*/
		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																								 ");
		csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) as wlbmid, ");
		csTempSQL += _T(" c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,			     ");
		csTempSQL += _T(" To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'  as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_Addition_Data c, 													 ");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'  and d.ALL_TURN_FLAG = 1 			 "); 
		csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																							     ");
		//}
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResult3;
		if(!Query(csSQL,rsResult3))
			return NULL;
		rsResult3.MoveFirst();
		rsMaterials.CopyFrom(rsResult3);
		//RH喂线
		/*if(csCasterID==_T("S66"))
		{
		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																					");
		csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE') as wlbmid,c.Amount/1000	");
		csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,					");
		csTempSQL += _T(" To_Char(d.App_Time,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_WIRE_DATA c, 											");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'  and d.ALL_TURN_FLAG = 1 							");
		csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																					");
		}
		else
		{*/
		csTempSQL  = _T(" select pch,ObjectID,wlbmid,sum(ljcksl) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																					");
		csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE') as wlbmid,c.Amount/1000	");
		csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,					");
		csTempSQL += _T(" To_Char(d.App_Time,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_WIRE_DATA c, 											");
		csTempSQL += _T(" CDisp_SteelTurn_App d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'  and d.ALL_TURN_FLAG = 1 							");
		csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																					");
		//}
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResult4;
		if(!Query(csSQL,rsResult4))
			return NULL;
		rsResult4.MoveFirst();
		rsMaterials.CopyFrom(rsResult4);
#pragma endregion
	}
	else
	{
#pragma region "非全回炉"
		//2009-08-21 添加因为拨坯产生的投料平衡 唐毅
		CString csTempBloomSQL =_T(" select * from CBloom_Data where MaterialID = '%s'");
		CString csBloomSQL;
		csBloomSQL.Format(csTempBloomSQL,csHeatID);
		CL3RecordSetWrap rsBloom;
		if(!Query(csBloomSQL,rsBloom))
			return NULL;
		if(rsBloom.GetRowCount() < 1)
			return NULL;
		//计划钢坯支数
		L3DOUBLE nPlanBloomCount = rsBloom.GetFieldByName(_T("Plan_Bloom_Count")).ToDouble();
		//实际钢坯支数
		L3DOUBLE nBloomCount = rsBloom.GetFieldByName(_T("Bloom_Count")).ToDouble();		
		//拨出钢坯支数
		L3DOUBLE nDivBloomCount = rsBloom.GetFieldByName(_T("Div_Bloom_Count")).ToDouble();		
		//拨入钢坯支数1
		L3DOUBLE nAddBloomCount1 = rsBloom.GetFieldByName(_T("Add_Bloom_Count")).ToDouble();
		//拨入钢坯支数2
		L3DOUBLE nAddBloomCount2 = rsBloom.GetFieldByName(_T("Add_Bloom_Count2")).ToDouble();
		//拨入炉号1
		CString strAddHeatID1 = rsBloom.GetFieldByName(_T("Add_HeatID1")).ToCString();
		//拨入炉号2
		CString strAddHeatID2 = rsBloom.GetFieldByName(_T("Add_HeatID2")).ToCString();

		//计划钢坯支数+拨入钢坯支数1+拨入钢坯支数2-拨出钢坯支数=实际钢坯支数
		//判断该炉是拨入钢坯还是拨出钢坯
		L3BOOL bIsDivBloom = false;
		if(nDivBloomCount > 0 || (nDivBloomCount ==0 && nAddBloomCount1 == 0 && nAddBloomCount2 == 0)) bIsDivBloom =true; else bIsDivBloom =false;

		//转炉投料主表信息	
		CString csTempSQL  = _T(" select a.HeatID,'1' as Flag,a.HeatID as pch,a.HeatID as ObjectID,b.MATERIALCODE_ID as wlbmid,															");
		csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as zdrid,to_char(d.CastingStartTime, 'yyyy-mm-dd')  as zdrq,											    ");
		csTempSQL += _T(" b.ProduceStd as freeitemvalue1,b.Tech_Request as freeitemvalue2,d.TreatNo from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c,CCCM_Process_Data d "); 
		csTempSQL += _T(" where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'														");  
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResultMain;
		if(!Query(csSQL,rsResultMain))
			return NULL;
		if(rsResultMain.GetRowCount()<1)
			return NULL;
		rsResultMain.MoveFirst();
		rsMain.AppendRecord();
		rsMain.CopyCurRowFrom(rsResultMain);

		if(bIsDivBloom)//拨出或者不拨坯
		{
#pragma region "拨出或者不拨坯处理"
			//拨出钢坯投料调整系数，总的投料*系数=总的投料 - （总的投料/计划钢坯支数）*拨出钢坯支数
			L3DOUBLE fBanlance;
			if(nPlanBloomCount > 0)
				fBanlance = nBloomCount / nPlanBloomCount;
			else
				fBanlance =1;

			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when																			");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end							");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 								");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type=5	and c.Element <> '67103'						");
			csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 

			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResultBOF1;
			if(!Query(csSQL,rsResultBOF1))
				return NULL;
			rsResultBOF1.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF1);

			////转炉辅料2009-08-06

			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,											");
			csTempSQL += _T(" a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,			");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,   'CKDA0000000000000007'  as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 			");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103')	"); 	
			csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																										"); 
			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResultBOF2;
			if(!Query(csSQL,rsResultBOF2))
				return NULL;
			rsResultBOF2.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF2);

			//转炉铁水2009-08-06
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'CHDA0000000000009282' as wlbmid,round(c.IRONWEIGHT * '%f',6) as ljcksl,																	");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'CKDA0000000000000026' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResultBOF3;
			if(!Query(csSQL,rsResultBOF3))
				return NULL;
			rsResultBOF3.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF3);

			//生铁2009-08-06
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYN' as wlbmid,round(c.PIGIRONWEIGHT * '%f',6) as ljcksl,													    ");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResultBOF4;
			if(!Query(csSQL,rsResultBOF4))
				return NULL;
			rsResultBOF4.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF4);

			//废钢2009-08-06
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYM' as wlbmid,round(c.SCRAPWEIGHT * '%f',6) as ljcksl,															");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,fBanlance,csHeatID);


			CL3RecordSetWrap rsResultBOF5;
			if(!Query(csSQL,rsResultBOF5))
				return NULL;
			rsResultBOF5.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF5);


			//回炉钢水2009-08-06
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001AA1000000002IQ4W' as wlbmid,round(c.Return_Steel_Weight *'%f',6) as ljcksl,													");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1006AA100000000E8UQ1' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,fBanlance,csHeatID);


			CL3RecordSetWrap rsResultSteel;
			if(!Query(csSQL,rsResultSteel))
				return NULL;
			rsResultSteel.MoveFirst();
			rsMaterials.CopyFrom(rsResultSteel);

			//炉后喂丝2009-08-06

			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000		");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end					");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1006AA100000000E8U7E' as ckckid from CPlan_Tapping a,CPlan_Order b,CTAP_ADDITION_DATA c, 						");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'								"); 
			csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													"); 

			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResultBOF6;
			if(!Query(csSQL,rsResultBOF6))
				return NULL;
			rsResultBOF6.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF6);

			//LF合金2009-08-06
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,							    ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
				//Modify end
			}
			else
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																						");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,							    ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1006AA100000000E8U7E' as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
				//Modify end
			}
			csSQL.Format(csTempSQL,fBanlance,csHeatID);


			CL3RecordSetWrap rsResult1;
			if(!Query(csSQL,rsResult1))
				return NULL;
			rsResult1.MoveFirst();
			rsMaterials.CopyFrom(rsResult1);

			//LF喂线2009-08-06
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(														 ");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			else
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) *'%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(														 ");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			//Modify end
			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResult2;
			if(!Query(csSQL,rsResult2))
				return NULL;
			rsResult2.MoveFirst();
			rsMaterials.CopyFrom(rsResult2);

			//RH投料2009-08-06
			/*if(csCasterID==_T("S66"))
			{
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																													");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) as wlbmid,c.WEIGHT/1000		");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,													");
			csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_Addition_Data c, 																");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'															");   
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													");
			}
			else
			{*/
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																													");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) as wlbmid,c.WEIGHT/1000		");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,													");
			csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_Addition_Data c, 																");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'															");   
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													");
			//}
			csSQL.Format(csTempSQL,fBanlance,csHeatID);

			CL3RecordSetWrap rsResult3;
			if(!Query(csSQL,rsResult3))
				return NULL;
			rsResult3.MoveFirst();
			rsMaterials.CopyFrom(rsResult3);

			//RH喂线2009-08-06
			/*if(csCasterID==_T("S66"))
			{
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																					");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE') as wlbmid,c.Amount/1000	");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,			        ");
			csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_WIRE_DATA c, 									");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'														");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																					");
			}
			else
			{*/
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																					");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE') as wlbmid,c.Amount/1000	");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,			        ");
			csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,   '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_WIRE_DATA c, 									");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'														");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																					");
			//}
			csSQL.Format(csTempSQL,fBanlance,csHeatID);


			CL3RecordSetWrap rsResult4;
			if(!Query(csSQL,rsResult4))
				return NULL;
			rsResult4.MoveFirst();
			rsMaterials.CopyFrom(rsResult4);

#pragma endregion
		}
		else//拨入钢坯
		{
#pragma region "拨入钢坯"
			//根据拨入炉号获取拨入炉号的计划钢坯支数
			L3DOUBLE nAddPlanBloomCount1 = 0;
			L3DOUBLE nAddPlanBloomCount2 = 0;
			CString csTempSQL =_T(" select * from CBloom_Data where MaterialID = '%s'");
			CString csSQL;
			csSQL.Format(csTempSQL,strAddHeatID1);
			CL3RecordSetWrap rsBloom1;
			if(!Query(csBloomSQL,rsBloom1))
				return NULL;
			if(rsBloom.GetRowCount() < 1)
				nAddPlanBloomCount1 = 0;
			else
			{
				rsBloom1.MoveFirst();
				nAddPlanBloomCount1 = rsBloom1.GetFieldByName(_T("Plan_Bloom_Count")).ToDouble();
			}

			csTempSQL =_T(" select * from CBloom_Data where MaterialID = '%s'");
			csSQL.Format(csTempSQL,strAddHeatID2);
			CL3RecordSetWrap rsBloom2;
			if(!Query(csBloomSQL,rsBloom2))
				return NULL;
			if(rsBloom2.GetRowCount() < 1)
				nAddPlanBloomCount2 = 0;
			else
			{
				rsBloom2.MoveFirst();
				nAddPlanBloomCount2 = rsBloom2.GetFieldByName(_T("Plan_Bloom_Count")).ToDouble();
			}

			//拨入钢坯投料调整系数，总的投料=总的投料 + （拨入炉号1总的投料/拨入炉号1计划钢坯支数）*拨入钢坯支数1 + （拨入炉号2总的投料/拨入炉号2计划钢坯支数）*拨入钢坯支数2
			L3DOUBLE fBanlance1 = 0;
			if(nAddPlanBloomCount1 > 0) fBanlance1 = nAddBloomCount1 / nAddPlanBloomCount1; else fBanlance1 = 0;

			L3DOUBLE fBanlance2 = 0;
			if(nAddPlanBloomCount2 > 0) fBanlance2 = nAddBloomCount2 / nAddPlanBloomCount2; else fBanlance2 = 0;

#pragma region "当前炉号应属于的转炉工作中心,后面做替换"
			CString csBOFID = csHeatID.Mid(1,1);
			CString csNCCenter;
			if(csBOFID == _T("1"))
				csNCCenter = _T("1001NC100000000015QG");
			else
				if(csBOFID == _T("2"))
					csNCCenter = _T("1001NC100000000015QN");
				else
					if(csBOFID == _T("3"))
						csNCCenter = _T("1001NC100000000015QS");
					else
						if(csBOFID == _T("4"))
							csNCCenter = _T("1001NC100000000015QU");
						else
							csNCCenter = _T("");
#pragma endregion

#pragma region "转炉合金本炉总的投料"
			//2009-08-21转炉合金本炉总的投料
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			            ");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when																			");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end							");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 								");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type=5	and c.Element <> '67103'						");
			csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 

			csSQL.Format(csTempSQL,csHeatID);

			CL3RecordSetWrap rsResultBOF1;
			if(!Query(csSQL,rsResultBOF1))
				return NULL;
			rsResultBOF1.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF1);	

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			if(csCasterID==_T("S66"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\'  as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		                    ");
				csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
				csTempSQL += csNCCenter;
				csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 								");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type=5	and c.Element <> '67103'						");
				csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 
			}
			else
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6)  as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\'  as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		                    ");
				csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
				csTempSQL += csNCCenter;
				csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 								");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type=5	and c.Element <> '67103'						");
				csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																															"); 
			}
			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF2;
				if(!Query(csSQL,rsResultBOF2))
					return NULL;
				rsResultBOF2.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF2);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF3;
				if(!Query(csSQL,rsResultBOF3))
					return NULL;
				rsResultBOF3.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF3);	
			}
#pragma endregion

#pragma region "本炉转炉辅料"


			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,											");
			csTempSQL += _T(" a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,			");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  'CKDA0000000000000007'     as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 			");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103')	"); 	
			csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																										"); 
			csSQL.Format(csTempSQL,csHeatID);

			CL3RecordSetWrap rsResultBOF4;
			if(!Query(csSQL,rsResultBOF4))
				return NULL;
			rsResultBOF4.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF4);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			if(csCasterID==_T("S66"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
				csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
				csTempSQL += csNCCenter;
				csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5C'    as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 			");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103')	"); 	
				csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																										"); 
			}
			else
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='BULK_CODE') as wlbmid,c.WEIGHT/1000 as ljcksl,		");
				csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
				csTempSQL += csNCCenter;
				csTempSQL += _T("\' as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  'CKDA0000000000000007'    as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_Addition_Data c, 			");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Type < 5 and c.Element <> '67103')	"); 	
				csTempSQL += _T(" group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																										"); 
			}
			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF5;
				if(!Query(csSQL,rsResultBOF5))
					return NULL;
				rsResultBOF5.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF5);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF6;
				if(!Query(csSQL,rsResultBOF6))
					return NULL;
				rsResultBOF6.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF6);	
			}
#pragma endregion

#pragma region "转炉本炉铁水"

			//转炉本炉铁水
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'CHDA0000000000009282' as wlbmid,round(c.IRONWEIGHT,6) as ljcksl,															");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'CKDA0000000000000026' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,csHeatID);

			CL3RecordSetWrap rsResultBOF7;
			if(!Query(csSQL,rsResultBOF7))
				return NULL;
			rsResultBOF7.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF7);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			csTempSQL  = _T(" select NULL as pch,\'");
			csTempSQL += csHeatID + _T("\' as ObjectID,'CHDA0000000000009282' as wlbmid,round(c.IRONWEIGHT *'%f',6) as ljcksl,															");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
			csTempSQL += csNCCenter;
			csTempSQL += _T("\'  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'CKDA0000000000000026' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												");

			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF8;
				if(!Query(csSQL,rsResultBOF8))
					return NULL;
				rsResultBOF8.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF8);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF9;
				if(!Query(csSQL,rsResultBOF9))
					return NULL;
				rsResultBOF9.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF9);	
			}
#pragma endregion

#pragma region "本炉生铁"

			//本炉生铁2009-08-21
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYN' as wlbmid,round(c.PIGIRONWEIGHT,6) as ljcksl,													    ");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF10;
			if(!Query(csSQL,rsResultBOF10))
				return NULL;
			rsResultBOF10.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF10);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			csTempSQL  = _T(" select NULL as pch,\'");
			csTempSQL += csHeatID + _T("\' as ObjectID,'0001NC10000000003MYN' as wlbmid,round(c.PIGIRONWEIGHT * '%f',6) as ljcksl,													    ");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
			csTempSQL += csNCCenter;
			csTempSQL += _T("\'  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 

			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF11;
				if(!Query(csSQL,rsResultBOF11))
					return NULL;
				rsResultBOF11.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF11);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF12;
				if(!Query(csSQL,rsResultBOF12))
					return NULL;
				rsResultBOF12.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF12);	
			}
#pragma endregion

#pragma region "本炉废钢"

			//本炉废钢2009-08-21
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001NC10000000003MYM' as wlbmid,round(c.SCRAPWEIGHT,6) as ljcksl,													    ");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF13;
			if(!Query(csSQL,rsResultBOF13))
				return NULL;
			rsResultBOF13.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF13);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			csTempSQL  = _T(" select NULL as pch,\'");
			csTempSQL += csHeatID + _T("\' as ObjectID,'0001NC10000000003MYM' as wlbmid,round(c.SCRAPWEIGHT * '%f',6) as ljcksl,													    ");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
			csTempSQL += csNCCenter;
			csTempSQL += _T("\'  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'CKDA0000000000000009' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 

			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF14;
				if(!Query(csSQL,rsResultBOF14))
					return NULL;
				rsResultBOF14.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF14);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF15;
				if(!Query(csSQL,rsResultBOF15))
					return NULL;
				rsResultBOF15.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF15);	
			}

#pragma endregion

#pragma region "本炉回炉钢水"

			//本炉回炉钢水2009-08-21
			csTempSQL  = _T(" select NULL as pch,a.HeatID as ObjectID,'0001AA1000000002IQ4W' as wlbmid,round(c.Return_Steel_Weight,6) as ljcksl,											    ");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end		");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1006AA100000000E8UQ1' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'												"); 
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF16;
			if(!Query(csSQL,rsResultBOF16))
				return NULL;
			rsResultBOF16.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF16);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			csTempSQL  = _T(" select NULL as pch,\'");
			csTempSQL += csHeatID + _T("\' as ObjectID,'0001AA1000000002IQ4W' as wlbmid,round(c.Return_Steel_Weight * '%f',6) as ljcksl,											    ");
			csTempSQL += _T(" 'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
			csTempSQL += csNCCenter;
			csTempSQL += _T("\'  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,'1006AA100000000E8UQ1' as ckckid from CPlan_Tapping a,CPlan_Order b,CBOF_FEED_DATA c, 				");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'");										

			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF17;
				if(!Query(csSQL,rsResultBOF17))
					return NULL;
				rsResultBOF17.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF17);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF18;
				if(!Query(csSQL,rsResultBOF18))
					return NULL;
				rsResultBOF18.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF18);	
			}

#pragma endregion

#pragma region "本炉炉后喂丝"
			//本炉炉后喂丝2009-08-21
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000		");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when a.BOFID ='S21' then '1001NC100000000015QG' when														");
			csTempSQL += _T("  a.BOFID ='S22' then '1001NC100000000015QN' when a.BOFID ='S23' then '1001NC100000000015QS' when a.BOFID ='S24' then '1001NC100000000015QU' else a.BOFID end					");
			csTempSQL += _T("  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E' as ckckid from CPlan_Tapping a,CPlan_Order b,CTAP_ADDITION_DATA c, 						");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'								"); 
			csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													"); 
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF19;
			if(!Query(csSQL,rsResultBOF19))
				return NULL;
			rsResultBOF19.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF19);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉
			if(csCasterID==_T("S66"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000		");
				csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
				csTempSQL += csNCCenter;
				csTempSQL += _T("\'  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CTAP_ADDITION_DATA c, 						");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'								"); 
				csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													"); 
			}
			else
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and Code_Group ='ALLOY_CODE') as wlbmid,c.WEIGHT/1000		");
				csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,\'");
				csTempSQL += csNCCenter;
				csTempSQL += _T("\'  as gzzxid,To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CTAP_ADDITION_DATA c, 						");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'								"); 
				csTempSQL += _T(" )group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													"); 
			}
			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF20;
				if(!Query(csSQL,rsResultBOF20))
					return NULL;
				rsResultBOF20.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF20);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF21;
				if(!Query(csSQL,rsResultBOF21))
					return NULL;
				rsResultBOF21.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF21);	
			}
#pragma endregion

#pragma region "LF本炉合金"
			//LF本炉合金2009-08-06
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) ,6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	 ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
			}
			else
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) ,6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																			    ");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	 ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
			}
			//Modify end

			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF22;
			if(!Query(csSQL,rsResultBOF22))
				return NULL;
			rsResultBOF22.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF22);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉,LF投料中心不用换
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f' ,6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																	    ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	  ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
			}
			else
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f' ,6)as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																	    ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) 	");
				csTempSQL += _T(" as wlbmid,c.WEIGHT/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when		            ");
				csTempSQL += _T("  substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2' when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,	  ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T("  To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_Addition_Data c, 	                                ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'						        ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																		                ");
			}
			//Modify end

			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF23;
				if(!Query(csSQL,rsResultBOF23))
					return NULL;
				rsResultBOF23.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF23);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF24;
				if(!Query(csSQL,rsResultBOF24))
					return NULL;
				rsResultBOF24.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF24);	

			}

#pragma endregion

#pragma region "LF本炉喂线"
			//LF本炉喂线2009-08-21
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																     ");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			else
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																     ");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,   '1006AA100000000E8U7E' as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			//Modify end
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF25;
			if(!Query(csSQL,rsResultBOF25))
				return NULL;
			rsResultBOF25.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF25);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉,LF投料中心不用换
			if(csLFID==_T("S44"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																     ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			else
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																     ");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE')		     ");
				csTempSQL += _T(" as wlbmid,c.Amount/1000 as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015QW' when ");
				csTempSQL += _T(" substr(c.TreatNo,1,1) ='2' then '1001NC100000000015R0' when substr(c.TreatNo,1,1) ='3' then '1001NC100000000015R2'  when substr(c.TreatNo,1,1) ='4' then '1001NC100000001KDV0W' when substr(c.TreatNo,1,1) ='5' then '1001NC100000002DPNCG' else a.LFID end as gzzxid,		         ");//modify by hyh 2012-06-08 新增4#LF
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CLF_WIRE_DATA c, 				     ");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'									     ");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																	 ");
			}
			//Modify end

			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF26;
				if(!Query(csSQL,rsResultBOF26))
					return NULL;
				rsResultBOF26.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF26);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF27;
				if(!Query(csSQL,rsResultBOF27))
					return NULL;
				rsResultBOF27.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF27);	

			}
#pragma endregion

#pragma region "RH本炉投料"
			//RH本炉投料2009-08-21
			/*if(csCasterID==_T("S66"))
			{
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																									");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) as wlbmid,c.WEIGHT/1000		");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,													");
			csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_Addition_Data c, 																");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'															");   
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													");
			}
			else
			{*/
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																									");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) as wlbmid,c.WEIGHT/1000		");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,													");
			csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_Addition_Data c, 																");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'															");   
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																													");
			//}
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF28;
			if(!Query(csSQL,rsResultBOF28))
				return NULL;
			rsResultBOF28.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF28);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉,RH投料中心不用换
			/*if(csCasterID==_T("S66"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																									");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) as wlbmid,c.WEIGHT/1000		");
				csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,													");
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_Addition_Data c, 																");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'															");   
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid	");
			}
			else
			{*/
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																									");
			csTempSQL += _T(" select c.Batch_ID as pch,\'");
			csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.ELEMENT and (Code_Group ='ALLOY_CODE' or Code_Group ='BULK_CODE')) as wlbmid,c.WEIGHT/1000		");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,													");
			csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'  as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_Addition_Data c, 																");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'	and c.Element <> '67103'															");   
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid	");
			//}
			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF29;
				if(!Query(csSQL,rsResultBOF29))
					return NULL;
				rsResultBOF29.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF29);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF30;
				if(!Query(csSQL,rsResultBOF30))
					return NULL;
				rsResultBOF30.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF30);	

			}
#pragma endregion

#pragma region "RH本炉喂线"
			//RH本炉喂线2009-08-21
			/*if(csCasterID==_T("S66"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																					");
				csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE') as wlbmid,c.Amount/1000	");
				csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,			        ");
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_WIRE_DATA c, 									");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'														");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																					");
			}
			else
			{*/
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl),6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																					");
			csTempSQL += _T(" select c.Batch_ID as pch,a.HeatID as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE') as wlbmid,c.Amount/1000	");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,			        ");
			csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_WIRE_DATA c, 									");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'														");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																					");
			//}
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsResultBOF31;
			if(!Query(csSQL,rsResultBOF31))
				return NULL;
			rsResultBOF31.MoveFirst();
			rsMaterials.CopyFrom(rsResultBOF31);

			//按照拨入炉号查询但是将拨入炉号，投料中心全部换为当前炉,RH投料中心不用换
			/*if(csCasterID==_T("S66"))
			{
				csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																					");
				csTempSQL += _T(" select c.Batch_ID as pch,\'");
				csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE') as wlbmid,c.Amount/1000	");
				csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,			        ");
				csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq,  '1001NC100000001J1L5B'  as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_WIRE_DATA c, 									");
				csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'														");
				csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																					");
			}
			else
			{*/
			csTempSQL  = _T(" select pch,ObjectID,wlbmid,round(sum(ljcksl) * '%f',6) as ljcksl,jldwid,kgyid,gzzxid,flrq,ckckid from(																					");
			csTempSQL += _T(" select c.Batch_ID as pch,\'");
			csTempSQL += csHeatID + _T("\' as ObjectID,(select distinct NC_CODE from CBASE_ALL_CODE where CODE =c.WIRECODE and Code_Group ='ALLOY_CODE') as wlbmid,c.Amount/1000	");
			csTempSQL += _T(" as ljcksl,'jlda0000000000000012'as jldwid,a.Planner as kgyid,case when substr(c.TreatNo,1,1) ='1' then '1001NC100000000015R3' else a.RHID end as gzzxid,			        ");
			csTempSQL += _T(" To_Char(d.CastingStartTime,'yyyy-mm-dd') as flrq, '1006AA100000000E8U7E'   as ckckid from CPlan_Tapping a,CPlan_Order b,CRH_WIRE_DATA c, 									");
			csTempSQL += _T(" CCCM_Process_Data d where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and a.HeatID =d.HeatID and c.HeatID = '%s'														");
			csTempSQL += _T(" and c.TreatNo is not null)group by pch,ObjectID,wlbmid,jldwid,kgyid,gzzxid,flrq,ckckid																					");
			//}
			//拨入炉号1
			if(fBanlance1 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance1,strAddHeatID1);
				CL3RecordSetWrap rsResultBOF29;
				if(!Query(csSQL,rsResultBOF29))
					return NULL;
				rsResultBOF29.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF29);	
			}

			//拨入炉号2
			if(fBanlance2 > 0)
			{
				csSQL.Format(csTempSQL,fBanlance2,strAddHeatID2);
				CL3RecordSetWrap rsResultBOF30;
				if(!Query(csSQL,rsResultBOF30))
					return NULL;
				rsResultBOF30.MoveFirst();
				rsMaterials.CopyFrom(rsResultBOF30);	

			}
#pragma endregion

#pragma endregion

		}

#pragma endregion
	}	

#pragma region "删除垃圾数据"
	//2009-04-21 Modify by liuzhiqang
	//01#合成渣,冶金灰入130库
	//其余的合成渣入133库
	rsMaterials.MoveFirst();
	while(!rsMaterials.IsEOF())
	{
		if(rsMaterials.GetFieldByName(_T("ljcksl")).ToCString() == _T("0") || rsMaterials.GetFieldByName(_T("wlbmid")).ToCString().IsEmpty())
		{
			rsMaterials.DeleteRecord();
		}
		else
		{
			//modify by hyh 2012-06-21
			CString csMaterialCode = rsMaterials.GetFieldByName(_T("wlbmid")).ToCString();
			CString csCenter= rsMaterials.GetFieldByName(_T("gzzxid")).ToCString();
			CString ckck= rsMaterials.GetFieldByName(_T("ckckid")).ToCString();
			if((csMaterialCode == _T("0001AA1000000009UZTT") || csMaterialCode == _T("0001AA1000000003U1WJ")) && csCasterID!=_T("S66"))
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("CKDA0000000000000007")));//炼钢厂低位料仓
			//0001NC1000000010US04武安二级AOD用石灰             济南一级AOD用石灰0001NC1000000010US01 ---2016-09-06
			else if((csMaterialCode == _T("0001AA1000000009UZTT") || csMaterialCode == _T("0001AA1000000003U1WJ")||csMaterialCode == _T("0001NC1000000010US04") || csMaterialCode == _T("0001NC1000000010US01")) && csCasterID==_T("S66") && csCenter==_T("1001NC100000001KDV0W"))
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5C")));//炼钢厂低位料二仓

			if((csMaterialCode == _T("0001AA1000000009UZTV") || csMaterialCode == _T("0001AA100000000BGKGY") || csMaterialCode == _T("0001AA100000000AXQ2B") || csMaterialCode == _T("0001AA1000000005L7EA") || csMaterialCode == _T("0001AA10000000004GYT")) && csCasterID!=_T("S66"))
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1006AA100000000E8U7E")));
			else if((csMaterialCode == _T("0001AA1000000009UZTV") || csMaterialCode == _T("0001AA100000000BGKGY") || csMaterialCode == _T("0001AA100000000AXQ2B") || csMaterialCode == _T("0001AA1000000005L7EA") || csMaterialCode == _T("0001AA10000000004GYT")) && csCasterID==_T("S66") && csCenter==_T("1001NC100000001KDV0W"))
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5B")));

			rsMaterials.MoveNext();
			//end
		}
	}

	//modify by hyh 2012-07-12
	rsMaterials.MoveFirst();
	while(!rsMaterials.IsEOF())
	{
		if(rsMaterials.GetFieldByName(_T("ljcksl")).ToCString() == _T("0") || rsMaterials.GetFieldByName(_T("wlbmid")).ToCString().IsEmpty())
		{
			rsMaterials.DeleteRecord();
		}
		else
		{
			CString csMaterialCode = rsMaterials.GetFieldByName(_T("wlbmid")).ToCString();
			CString csCenter= rsMaterials.GetFieldByName(_T("gzzxid")).ToCString();
			CString ckck= rsMaterials.GetFieldByName(_T("ckckid")).ToCString();

			if((csCenter==_T("1001NC100000001KDV0W")||csCenter==_T("1001NC100000001JTY8G"))&&ckck==_T("1006AA100000000E8U7E"))
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5B")));
			if((csCenter==_T("1001NC100000001KDV0W")||csCenter==_T("1001NC100000001JTY8G"))&&ckck==_T("CKDA0000000000000007"))
				rsMaterials.SetFieldByName(_T("ckckid"),CL3Variant(_T("1001NC100000001J1L5C")));

			rsMaterials.MoveNext();

		}
	}
	//end
#pragma endregion


	if (*rsMainData != NULL)
		(*rsMainData)->Release();
	(*rsMainData) = rsMain.Detach(); 
	return rsMaterials.Detach();
	
	}


}






/// <Method class="CBaseData_Mag" name="GetBloomInfor" type="L3LONG">
/// 2009-03-26 liuzhiqiang
/// 向NC补发生产完成电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::SendBloomInfor(L3STRING strHeatID,L3RECORDSET *rsMainData)
{
#pragma region "创建记录集"
	//组建返回数据集
	CL3RecordSet *pRSRtnMain = new CL3RecordSet();
	CL3RecordSetWrap rsMain; pRSRtnMain->QueryInterface(IID_IL3RecordSet,rsMain); pRSRtnMain->Release();
	rsMain.AddField(_T("HeatID"),VT_BSTR);
	rsMain.AddField(_T("Flag"),VT_BSTR);//1表示:钢 2表示:铁
	rsMain.AddField(_T("pch"),VT_BSTR);//批次号(*)
	rsMain.AddField(_T("zdrid"),VT_BSTR);//操作员编码(*)(最终的操作人员)
	rsMain.AddField(_T("rq"),VT_BSTR);//报告日期(*)
	rsMain.AddField(_T("sj"),VT_BSTR);//报告时间(*)
	rsMain.AddField(_T("gzzxbmid"),VT_BSTR);//工作中心编码id(*)(从基础数据中获取)
	rsMain.AddField(_T("scbmid"),VT_BSTR);//生产部门id(*)(从基础数据中获取)	   
	rsMain.AddField(_T("NC_Confirm_Flag"),VT_BSTR);//确认标志
	rsMain.AddField(_T("TreatNo"),VT_BSTR);//处理号
	rsMain.AddField(_T("ObjectID"),VT_BSTR);

	//组建返回数据集
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsMaterials; pRSRtn->QueryInterface(IID_IL3RecordSet,rsMaterials); rsMaterials->Release();
	rsMaterials.AddField(_T("pch"),VT_BSTR);//批次号(*)
	rsMaterials.AddField(_T("scddh"),VT_BSTR);//生产订单号
	rsMaterials.AddField(_T("wlbmid"),VT_BSTR);//物料编码id(*)
	rsMaterials.AddField(_T("jldwid"),VT_BSTR);//计量单位id(*)
	rsMaterials.AddField(_T("gzzxid"),VT_BSTR);//工作中心id(*)
	rsMaterials.AddField(_T("ccxh"),VT_BSTR);//产出序号(*) (没有产出序号:给处理号)
	rsMaterials.AddField(_T("gxh"),VT_BSTR);//工序号
	rsMaterials.AddField(_T("pk_produce"),VT_BSTR);//完工产品
	rsMaterials.AddField(_T("ksrq"),VT_BSTR);//开始日期(*)
	rsMaterials.AddField(_T("kssj"),VT_BSTR);//开始时间(*)
	rsMaterials.AddField(_T("jsrq"),VT_BSTR);//结束日期(*)
	rsMaterials.AddField(_T("jssj"),VT_BSTR);//结束时间(*)
	rsMaterials.AddField(_T("hgsl"),VT_R8);//实际完工数量(*)
	rsMaterials.AddField(_T("fhgsl"),VT_I4);//实际完工辅数量(*)
	rsMaterials.AddField(_T("sflfcp"),VT_BSTR);//是否联副产品(*)(是:Y,不是:N)
	rsMaterials.AddField(_T("sffsgp"),VT_BSTR);//是否改判(*)(是:Y,不是:N)
	rsMaterials.AddField(_T("zdy1"),VT_BSTR);//自定义1
	rsMaterials.AddField(_T("zdy2"),VT_BSTR);//自定义2
	rsMaterials.AddField(_T("zdy3"),VT_BSTR);//自定义3
	rsMaterials.AddField(_T("zdy4"),VT_BSTR);//自定义4
	rsMaterials.AddField(_T("zdy5"),VT_BSTR);//自定义5
	rsMaterials.AddField(_T("zyx1"),VT_BSTR);//自由项1(产品标准)(*)(有就填写,没有不填)
	rsMaterials.AddField(_T("zyx2"),VT_BSTR);//自由项2(技术要求)(*)(有就填写,没有不填)
	rsMaterials.AddField(_T("zyx3"),VT_BSTR);//自由项3
	rsMaterials.AddField(_T("zyx4"),VT_BSTR);//自由项4
	rsMaterials.AddField(_T("zyx5"),VT_BSTR);//自由项5
	rsMaterials.AddField(_T("pk_corp"),VT_BSTR);//公司
	rsMaterials.AddField(_T("gcbm"),VT_BSTR);//工厂
	rsMaterials.AddField(_T("ObjectID"),VT_BSTR);
#pragma endregion 

	CString csHeatID=strHeatID;
	
	//判断是否为全回炉
	CString csTempSQL = _T(" select * from CSteel_Data where HeatID = '%s' ");
	CString csSQL;
	csSQL.Format(csTempSQL,strHeatID);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData) || rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return NULL;
	rsSteelData.MoveFirst();
	CString csType = rsSteelData.GetFieldByName(_T("Status")).ToCString();

	if(csType != _T("5"))
	{
#pragma region "非全回炉"
		CString csTempSQL = _T(" select TreatNo,PreHeatID,HeatID from CCCM_Base_Data where HeatID = '%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,strHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
			return NULL;		

		CString csChar = _T("×");
		rs.MoveFirst();
		L3LONG nccxh = rs.GetFieldByName(_T("TreatNo")).ToLong();
		while(!rs.IsEOF())
		{		
			//钢坯信息
			CString csTreatNo = rs.GetFieldByName(_T("TreatNo")).ToCString();
			CString csHeatID  = rs.GetFieldByName(_T("HeatID")).ToCString();	
			CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
			CString csProcessUri = CCM_PROCESS_DATA_CLASS_URI + _T("\\") + csTreatNo; 
			//甩废量
			L3DOUBLE nWasterWeight = GetObjectPropValue(csBloomUri,_T("Waster_Weight")).ToDouble();
			//回炉钢水量
			L3DOUBLE nReturnWeight = GetObjectPropValue(csProcessUri,_T("Weight_Return")).ToDouble();

			CString csPreSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("Pre_SteelGradeIndex")).ToCString();
			CString csCurSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("SteelGradeIndex")).ToCString();

			CString csCurMaterialID;
			CString csCurZyx1;
			CString csCurZyx2;
			if(csPreSteelGradeIndex !=csCurSteelGradeIndex && csCurSteelGradeIndex != WAITING_FIN_JUDGE)
			{
				CL3RecordSetWrap rs = ModifySteelGrade(csHeatID,csCurSteelGradeIndex);
				rs.MoveFirst();
				csCurMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
				csCurZyx1 = rs.GetFieldByName(_T("free1")).ToCString();
				csCurZyx1 = rs.GetFieldByName(_T("free2")).ToCString();
			}

			CString csTempSQL;
			if(nWasterWeight > 0)
			{
				//甩废产品为联副产品，非改判,物料编码为废钢
				//2009-09-20屏蔽
				//csTempSQL  = _T(" select a.TreatNo,NULL as pch,c.Planner as zdrid,to_Char(sysdate,'hh24:mi:ss') as sj,to_Char(sysdate,'yyyy-mm-dd') as rq,													");   
				//csTempSQL += _T(" case when a.CCMID ='S61' then '1001NC100000000015R4' when a.CCMID ='S62' then '1001NC100000000015R6' when a.CCMID ='S63' then                                             ");
				//csTempSQL += _T(" '1001NC100000000015R7' when a.CCMID ='S64' then '1001NC100000000015R8' when a.CCMID ='S65' then '1001NC100000000015R9'  end as gzzxid,a.TreatNo as ccxh,  				");
				//csTempSQL += _T(" case when a.CCMID ='S61' then '110301' when a.CCMID ='S62' then '110302' when a.CCMID ='S63' then																			");
				//csTempSQL += _T(" '110303' when a.CCMID ='S64' then '110304' when a.CCMID ='S65' then '110305'  end as gzzxbmid,																			");
				//csTempSQL += _T(" 'CHDA0000000000009346' as wlbmid,'jlda0000000000000012'as jldwid,																											");  
				//csTempSQL += _T(" d.ProduceStd as zyx1,d.Tech_Request as zyx2,to_Char(a.CASTINGSTARTTIME,'yyyy-mm-dd') as Ksrq,to_Char(a.CASTINGSTARTTIME,'hh24:mi:ss') as Kssj,				            ");   
				//csTempSQL += _T(" to_Char(a.CASTINGSTOPTIME,'yyyy-mm-dd') as Jsrq,to_Char(a.CASTINGSTOPTIME,'hh24:mi:ss') as Jssj,b.Waster_Weight as hgsl,'Y' as sflfcp,									");   
				//csTempSQL += _T(" a.TreatNo||a.HeatID as ObjectID,'N' as sffsgp                                                                                                                             ");   
				//csTempSQL += _T(" from CCCM_Process_Data a,CBloom_Data b,CPLAN_TAPPING c,CPlan_Order d where a.HeatID = b.HeatID and a.HeatID = c.HeatID and c.Plan_Ord_ID = d.PlanID and a.TreatNo = '%s'	");			
				//CString csSQL;
				//csSQL.Format(csTempSQL,csTreatNo);
				//CL3RecordSetWrap rsResult;
				//if(!Query(csSQL,rsResult))
				//	return NULL;
				//rsResult.MoveFirst();
				//rsMaterials.CopyFrom(rsResult);

			}
			if(nReturnWeight > 0)
			{
				//回炉钢水为联副产品，非改判,物料编码为回炉钢水
				//Modify begin llj 2011-03-14 增加lF5工序，LF5NC编码为1001NC100000002DPNCG，屏蔽原语句
				/*csTempSQL  = _T(" select a.TreatNo,NULL as pch,c.Planner as zdrid,to_Char(sysdate,'hh24:mi:ss') as sj,to_Char(sysdate,'yyyy-mm-dd') as rq,													");   
				csTempSQL += _T(" case when a.CCMID ='S61' then '1001NC100000000015R4' when a.CCMID ='S62' then '1001NC100000000015R6' when a.CCMID ='S63' then                                             ");
				csTempSQL += _T(" '1001NC100000000015R7' when a.CCMID ='S64' then '1001NC100000000015R8' when a.CCMID ='S65' then '1001NC100000000015R9'  end as gzzxid,a.TreatNo as ccxh,  				");
				csTempSQL += _T(" case when a.CCMID ='S61' then '110301' when a.CCMID ='S62' then '110302' when a.CCMID ='S63' then																			");
				csTempSQL += _T(" '110303' when a.CCMID ='S64' then '110304' when a.CCMID ='S65' then '110305'  end as gzzxbmid,																			");
				csTempSQL += _T(" '0001AA1000000002IQ4W' as wlbmid,'jlda0000000000000012'as jldwid,																											");  
				csTempSQL += _T(" d.ProduceStd as zyx1,d.Tech_Request as zyx2,to_Char(a.CASTINGSTARTTIME,'yyyy-mm-dd') as Ksrq,to_Char(a.CASTINGSTARTTIME,'hh24:mi:ss') as Kssj,				            ");   
				csTempSQL += _T(" to_Char(a.CASTINGSTOPTIME,'yyyy-mm-dd') as Jsrq,to_Char(a.CASTINGSTOPTIME,'hh24:mi:ss') as Jssj,a.Weight_Return as hgsl,'Y' as sflfcp,									");   
				csTempSQL += _T(" a.TreatNo||a.HeatID as ObjectID,'N' as sffsgp                                                                                                                             ");   
				csTempSQL += _T(" from CCCM_Process_Data a,CBloom_Data b,CPLAN_TAPPING c,CPlan_Order d where a.HeatID = b.HeatID and a.HeatID = c.HeatID and c.Plan_Ord_ID = d.PlanID and a.TreatNo = '%s'	");		*/

				csTempSQL  = _T(" select a.TreatNo,NULL as pch,c.Planner as zdrid,to_Char(sysdate,'hh24:mi:ss') as sj,to_Char(sysdate,'yyyy-mm-dd') as rq,													");   
				csTempSQL += _T(" case when a.CCMID ='S61' then '1001NC100000000015R4' when a.CCMID ='S62' then '1001NC100000000015R6' when a.CCMID ='S63' then                                             ");
				csTempSQL += _T(" '1001NC100000000015R7' when a.CCMID ='S64' then '1001NC100000000015R8' when a.CCMID ='S65' then '1001NC100000000015R9'  when a.CCMID ='S66' and substr(a.HeatID,1,1)='2' then '1001NC100000001JTY8G'  when a.CCMID ='S66' and substr(a.HeatID,1,1)='6' then '1001NC100000002DDER1' when a.CCMID ='S67' then '1001NC100000002DPNDB' end as gzzxid,a.TreatNo as ccxh,  				");//modify by hyh 2012-06-08 新增CCM7
				csTempSQL += _T(" case when a.CCMID ='S61' then '110301' when a.CCMID ='S62' then '110302' when a.CCMID ='S63' then																			");
				csTempSQL += _T(" '110303' when a.CCMID ='S64' then '110304' when a.CCMID ='S65' then '110305' when a.CCMID ='S67' then '110306'  when a.CCMID ='S66' and substr(a.HeatID,1,1)='2' then '140301' when a.CCMID ='S66'and substr(a.HeatID,1,1)='6' then '140311' end as gzzxbmid,																			");//modify by hyh 2012-06-08 新增CCM7
				csTempSQL += _T(" '0001AA1000000002IQ4W' as wlbmid,'jlda0000000000000012'as jldwid,																											");  
				csTempSQL += _T(" d.ProduceStd as zyx1,d.Tech_Request as zyx2,to_Char(a.CASTINGSTARTTIME,'yyyy-mm-dd') as Ksrq,to_Char(a.CASTINGSTARTTIME,'hh24:mi:ss') as Kssj,				            ");   
				csTempSQL += _T(" to_Char(a.CASTINGSTOPTIME,'yyyy-mm-dd') as Jsrq,to_Char(a.CASTINGSTOPTIME,'hh24:mi:ss') as Jssj,a.Weight_Return as hgsl,'Y' as sflfcp,									");   
				csTempSQL += _T(" a.TreatNo||a.HeatID as ObjectID,'N' as sffsgp                                                                                                                             ");   
				csTempSQL += _T(" from CCCM_Process_Data a,CBloom_Data b,CPLAN_TAPPING c,CPlan_Order d where a.HeatID = b.HeatID and a.HeatID = c.HeatID and c.Plan_Ord_ID = d.PlanID and a.TreatNo = '%s'	");
				//Modify end
				CString csSQL;
				csSQL.Format(csTempSQL,csTreatNo);
				CL3RecordSetWrap rsResult;
				if(!Query(csSQL,rsResult))
					return NULL;
				rsResult.MoveFirst();
				rsMaterials.CopyFrom(rsResult);
			}

			////产品根据是否改钢判断是否改判，如改钢同时也是联副产品
			//csTempSQL  = _T(" select a.TreatNo,a.HeatID,'1' as Flag,a.HeatID as pch,c.Planner as zdrid,to_Char(sysdate,'hh24:mi:ss') as sj,to_Char(sysdate,'yyyy-mm-dd') as rq,							");   
			//csTempSQL += _T(" case when a.CCMID ='S61' then '1001NC100000000015R4' when a.CCMID ='S62' then '1001NC100000000015R6' when a.CCMID ='S63' then                                             ");
			//csTempSQL += _T(" '1001NC100000000015R7' when a.CCMID ='S64' then '1001NC100000000015R8' when a.CCMID ='S65' then '1001NC100000000015R9'  end as gzzxid,a.TreatNo as ccxh,  				");
			//csTempSQL += _T(" case when a.CCMID ='S61' then '110301' when a.CCMID ='S62' then '110302' when a.CCMID ='S63' then																			");
			//csTempSQL += _T(" '110303' when a.CCMID ='S64' then '110304' when a.CCMID ='S65' then '110305'  end as gzzxbmid,																			");
			//csTempSQL += _T(" case when b.Pre_SteelGradeIndex = b.SteelGradeIndex or b.SteelGradeIndex ='YY000000'then d.MaterialCode_ID   else                                                         ");
			//csTempSQL += _T(" \'") + csCurMaterialID + _T("\' end																																		");
			//csTempSQL += _T("  as wlbmid,'jlda0000000000000012'as jldwid,																																");  
			//csTempSQL += _T(" d.ProduceStd as zyx1,d.Tech_Request as zyx2,to_Char(a.CASTINGSTARTTIME,'yyyy-mm-dd') as Ksrq,to_Char(a.CASTINGSTARTTIME,'hh24:mi:ss') as Kssj,				            ");   
			//csTempSQL += _T(" to_Char(a.CASTINGSTOPTIME,'yyyy-mm-dd') as Jsrq,to_Char(a.CASTINGSTOPTIME,'hh24:mi:ss') as Jssj,b.CAL_WEIGHT as hgsl,b.BLOOM_COUNT as fhgsl,                              "); 
			//csTempSQL += _T(" case when b.Pre_SteelGradeIndex = b.SteelGradeIndex or b.SteelGradeIndex ='YY000000' then 'N' else 'Y' end as sflfcp,                                                     ");             
			//csTempSQL += _T(" a.TreatNo||a.HeatID as ObjectID,case when b.Pre_SteelGradeIndex = b.SteelGradeIndex or b.SteelGradeIndex ='YY000000' then 'N' else 'Y' end as sffsgp,                     ");   
			//csTempSQL += _T(" case when b.Pre_SteelGradeIndex = b.SteelGradeIndex or b.SteelGradeIndex ='YY000000' then	d.ProduceStd																	");
			//csTempSQL += _T(" else \'") + csCurZyx1 + _T("\' end  as zyx1, ");        
			//csTempSQL += _T(" case when b.Pre_SteelGradeIndex = b.SteelGradeIndex or b.SteelGradeIndex ='YY000000' then	d.Tech_Request																    ");
			//csTempSQL += _T(" else \'") + csCurZyx2 + _T("\' end  as zyx2  ");
			//csTempSQL += _T(" from CCCM_Process_Data a,CBloom_Data b,CPLAN_TAPPING c,CPlan_Order d where a.HeatID = b.HeatID and a.HeatID = c.HeatID and c.Plan_Ord_ID = d.PlanID and a.TreatNo = '%s'	");			
			//csSQL.Format(csTempSQL,csTreatNo);
			//CL3RecordSetWrap rsResult1;
			//if(!Query(csSQL,rsResult1))
			//	return NULL;
			//rsResult1.MoveFirst();
			//rsMain.AppendRecord();
			//rsMain.CopyCurRowFrom(rsResult1);
			//rsMaterials.CopyFrom(rsResult1);
			//rs.MoveNext();

			//Modify by liuzhiqiang 2009-04-18
			//产品根据是否改钢判断是否改判，钢坯是非联副产品2009-04-23
			//Modify begin llj 2011-03-14 增加lF5工序，LF5NC编码为1001NC100000002DPNCG，屏蔽原语句
			/*csTempSQL  = _T(" select a.TreatNo,a.HeatID,'1' as Flag,a.HeatID as pch,c.Planner as zdrid,to_Char(sysdate,'hh24:mi:ss') as sj,to_Char(sysdate,'yyyy-mm-dd') as rq,							");   
			csTempSQL += _T(" case when a.CCMID ='S61' then '1001NC100000000015R4' when a.CCMID ='S62' then '1001NC100000000015R6' when a.CCMID ='S63' then                                             ");
			csTempSQL += _T(" '1001NC100000000015R7' when a.CCMID ='S64' then '1001NC100000000015R8' when a.CCMID ='S65' then '1001NC100000000015R9'  end as gzzxid,a.TreatNo as ccxh,  				");
			csTempSQL += _T(" case when a.CCMID ='S61' then '110301' when a.CCMID ='S62' then '110302' when a.CCMID ='S63' then																			");
			csTempSQL += _T(" '110303' when a.CCMID ='S64' then '110304' when a.CCMID ='S65' then '110305'  end as gzzxbmid,																			");
			csTempSQL += _T(" d.MaterialCode_ID as wlbmid,'jlda0000000000000012'as jldwid,																												");  
			csTempSQL += _T(" d.ProduceStd as zyx1,d.Tech_Request as zyx2,to_Char(a.CASTINGSTARTTIME,'yyyy-mm-dd') as Ksrq,to_Char(a.CASTINGSTARTTIME,'hh24:mi:ss') as Kssj,				            ");   
			csTempSQL += _T(" to_Char(a.CASTINGSTOPTIME,'yyyy-mm-dd') as Jsrq,to_Char(a.CASTINGSTOPTIME,'hh24:mi:ss') as Jssj,b.CAL_WEIGHT as hgsl,b.BLOOM_COUNT as fhgsl,                              "); 
			csTempSQL += _T(" 'N' as sflfcp,                                                                                                                                                            ");             
			csTempSQL += _T(" a.TreatNo||a.HeatID as ObjectID,case when b.Pre_SteelGradeIndex = b.SteelGradeIndex or b.SteelGradeIndex ='YY000000' then 'N' else 'Y' end as sffsgp,                     ");   
			csTempSQL += _T(" d.ProduceStd	as zyx1,d.Tech_Request	as zyx2																																");
			csTempSQL += _T(" from CCCM_Process_Data a,CBloom_Data b,CPLAN_TAPPING c,CPlan_Order d where a.HeatID = b.HeatID and a.HeatID = c.HeatID and c.Plan_Ord_ID = d.PlanID and a.TreatNo = '%s'	");	*/

			csTempSQL  = _T(" select a.TreatNo,a.HeatID,'1' as Flag,a.HeatID as pch,c.Planner as zdrid,to_Char(sysdate,'hh24:mi:ss') as sj,to_Char(sysdate,'yyyy-mm-dd') as rq,							");   
			csTempSQL += _T(" case when a.CCMID ='S61' then '1001NC100000000015R4' when a.CCMID ='S62' then '1001NC100000000015R6' when a.CCMID ='S63' then                                             ");
			csTempSQL += _T(" '1001NC100000000015R7' when a.CCMID ='S64' then '1001NC100000000015R8' when a.CCMID ='S65' then '1001NC100000000015R9' when a.CCMID ='S67' then '1001NC100000002DPNDB'  when a.CCMID ='S66' and substr(a.HeatID,1,1)='2' then '1001NC100000001JTY8G' when a.CCMID ='S66' and substr(a.HeatID,1,1)='6' then '1001NC100000002DDER1' end as gzzxid,a.TreatNo as ccxh,  				");//Modify by hyh 2012-06-08 新增CCM7
			csTempSQL += _T(" case when a.CCMID ='S61' then '110301' when a.CCMID ='S62' then '110302' when a.CCMID ='S63' then																			");
			csTempSQL += _T(" '110303' when a.CCMID ='S64' then '110304' when a.CCMID ='S65' then '110305' when a.CCMID ='S67' then '110306' when a.CCMID ='S66' and substr(a.HeatID,1,1)='2' then '140301' when a.CCMID ='S66'and substr(a.HeatID,1,1)='6' then '140311' end as gzzxbmid,																			");//Modify by hyh 2012-06-08 新增CCM7
			csTempSQL += _T(" d.MaterialCode_ID as wlbmid,'jlda0000000000000012'as jldwid,																												");  
			csTempSQL += _T(" d.ProduceStd as zyx1,d.Tech_Request as zyx2,to_Char(a.CASTINGSTARTTIME,'yyyy-mm-dd') as Ksrq,to_Char(a.CASTINGSTARTTIME,'hh24:mi:ss') as Kssj,				            ");   
			csTempSQL += _T(" to_Char(a.CASTINGSTOPTIME,'yyyy-mm-dd') as Jsrq,to_Char(a.CASTINGSTOPTIME,'hh24:mi:ss') as Jssj,b.CAL_WEIGHT as hgsl,b.BLOOM_COUNT as fhgsl,                              "); 
			csTempSQL += _T(" 'N' as sflfcp,                                                                                                                                                            ");             
			csTempSQL += _T(" a.TreatNo||a.HeatID as ObjectID,case when b.Pre_SteelGradeIndex = b.SteelGradeIndex or b.SteelGradeIndex ='YY000000' then 'N' else 'Y' end as sffsgp,                     ");   
			csTempSQL += _T(" d.ProduceStd	as zyx1,d.Tech_Request	as zyx2																																");
			csTempSQL += _T(" from CCCM_Process_Data a,CBloom_Data b,CPLAN_TAPPING c,CPlan_Order d where a.HeatID = b.HeatID and a.HeatID = c.HeatID and c.Plan_Ord_ID = d.PlanID and a.TreatNo = '%s'	");	
			//Modify end
			csSQL.Format(csTempSQL,csTreatNo);
			CL3RecordSetWrap rsResult1;
			if(!Query(csSQL,rsResult1))
				return NULL;
			rsResult1.MoveFirst();
			rsMain.AppendRecord();
			rsMain.CopyCurRowFrom(rsResult1);
			rsMaterials.CopyFrom(rsResult1);
			rs.MoveNext();
		}
		if(rsMaterials.GetRowCount() > 0)
		{
			rsMaterials.MoveFirst();
			while(!rsMaterials.IsEOF())
			{
				rsMaterials.SetFieldByName(_T("ccxh"),CL3Variant(nccxh));
				nccxh ++;
				rsMaterials.MoveNext();
			}
		}
		if (*rsMainData != NULL)
			(*rsMainData)->Release();
		(*rsMainData) = rsMain.Detach(); 
		return rsMaterials.Detach();
#pragma endregion
	}
	else
	{	
#pragma region "全回炉"
		//回炉钢水为联副产品，非改判,物料编码为回炉钢水2009-04-23
		CString csTempSQL  = _T(" select a.HeatID,'1' as Flag,NULL as pch,c.Planner as zdrid,to_Char(sysdate,'hh24:mi:ss') as sj,to_Char(sysdate,'yyyy-mm-dd') as rq,case when				");   
		csTempSQL += _T(" c.CASTERID ='S61' then '1001NC100000000015R4' when c.CASTERID ='S62'																						");
		csTempSQL += _T(" then '1001NC100000000015R6' when c.CASTERID ='S63'then '1001NC100000000015R7' when c.CASTERID ='S64' then '1001NC100000000015R8' when c.CASTERID ='S65'	");
		csTempSQL += _T(" then '1001NC100000000015R9'  when c.CASTERID ='S67' then '1001NC100000002DPNDB'  when c.CASTERID ='S66' then '1001NC100000001JTY8G'  else c.CASTERID end as gzzxid,a.HeatID*10 as ccxh,case when	c.CASTERID ='S61' then '110301' when c.CASTERID ='S62' then		");//Modify by hyh 2012-06-08 新增CCM7
		csTempSQL += _T(" '110302' when c.CASTERID ='S63' then '110303' when c.CASTERID ='S64'  then '110304' when c.CASTERID ='S65' then '110305'  when c.CASTERID ='S67' then '110306'  when c.CASTERID ='S66' and substr(a.HeatID,1,1)='2' then '140301'  when c.CASTERID ='S66'and substr(a.HeatID,1,1)='6' then '140311' end as gzzxbmid,					");//Modify by hyh 2012-06-08 新增CCM7
		csTempSQL += _T(" '0001AA1000000002IQ4W' as wlbmid,'jlda0000000000000012'as jldwid,d.ProduceStd as zyx1,d.Tech_Request as zyx2,												");  
		csTempSQL += _T(" to_Char(a.App_Time,'yyyy-mm-dd') as Ksrq,to_Char(a.App_Time,'hh24:mi:ss') as Kssj,round(a.App_Steel_Weight,3) as hgsl,									");   
		csTempSQL += _T(" to_Char(a.App_Time,'yyyy-mm-dd') as Jsrq,to_Char(a.App_Time,'hh24:mi:ss') as Jssj,'Y' as sflfcp,a.HeatID as ObjectID,'N' as sffsgp from					");   
		csTempSQL += _T(" CDisp_SteelTurn_App a,CPLAN_TAPPING c,CPlan_Order d where a.HeatID = c.HeatID and c.Plan_Ord_ID = d.PlanID and a.HeatID = '%s'  and a.ALL_TURN_FLAG = 1	"); 

		CString csSQL;
		csSQL.Format(csTempSQL,strHeatID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult))
			return NULL;
		rsResult.MoveFirst();
		rsMain.AppendRecord();
		rsMain.CopyCurRowFrom(rsResult);
		CString csHeatID = strHeatID;
		rsMain.MoveFirst();
		while(!rsMain.IsEOF())
		{
			rsMain.SetFieldByName(_T("pch"),CL3Variant(csHeatID));
			rsMain.MoveNext();
		}
		rsMaterials.CopyFrom(rsResult);

		if (*rsMainData != NULL)
			(*rsMainData)->Release();
		(*rsMainData) = rsMain.Detach(); 
		return rsMaterials.Detach();
#pragma endregion
	}

}

/// <Method class="CBaseData_Mag" name="SendQualityJudgeInfor" type="L3LONG">
/// 2009-03-26 liuzhiqiang
/// 向NC补发终判质量电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::SendQualityJudgeInfor(L3STRING strHeatID,L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2,L3STRING strType)
{
	CL3RecordSetWrap rs;
	CString csSQL;
	CString csType = strType;

#pragma region "创建主从表记录集"
	//组建主表数据集
	CL3RecordSet *pRSRtnMain = new CL3RecordSet();
	CL3RecordSetWrap rsMain; pRSRtnMain->QueryInterface(IID_IL3RecordSet,rsMain); pRSRtnMain->Release();
	rsMain.AddField(_T("HeatID"),VT_BSTR);
	rsMain.AddField(_T("Flag"),VT_BSTR);//1表示:钢 2表示:铁
	rsMain.AddField(_T("scddh"),VT_BSTR);//生产订单号
	rsMain.AddField(_T("vproductbatchcode"),VT_BSTR);//产品批次	
	rsMain.AddField(_T("vcheckbillcode"),VT_BSTR);//检验单号
	rsMain.AddField(_T("bcompcheck"),VT_BSTR);//是否成分检验
	rsMain.AddField(_T("vbatchcode"),VT_BSTR);//检验批次
	rsMain.AddField(_T("cpraydeptid"),VT_BSTR);//报检部门(*)
	rsMain.AddField(_T("cprayerid"),VT_BSTR);//报检人(编码)(*)
	rsMain.AddField(_T("creporterid"),VT_BSTR);//检验人(编码)(*)
	rsMain.AddField(_T("dpraydate"),VT_BSTR);//报检日期(*)
	rsMain.AddField(_T("nchecknum"),VT_R8);//报检数量(*)
	rsMain.AddField(_T("nassistchecknum"),VT_R8);//报检辅数量(*)
	rsMain.AddField(_T("cassistunitid"),VT_BSTR);//辅计量单位id(*)
	rsMain.AddField(_T("cstoreorganization"),VT_BSTR);//库存组织
	rsMain.AddField(_T("cpraycorp"),VT_BSTR);//报检公司
	rsMain.AddField(_T("ccheckbillid"),VT_BSTR);// 质量检验单主键
	rsMain.AddField(_T("NC_Confirm_Flag"),VT_BSTR);//确认标志
	rsMain.AddField(_T("ObjectID"),VT_BSTR);//MaterialID

	//组建从表1数据集
	CL3RecordSet *pRSRtn1 = new CL3RecordSet();
	CL3RecordSetWrap rsMaterials1; pRSRtn1->QueryInterface(IID_IL3RecordSet,rsMaterials1); rsMaterials1->Release();
	rsMaterials1.AddField(_T("pk_stordoc"),VT_BSTR);//仓库(*)
	rsMaterials1.AddField(_T("vinvbatchcode"),VT_BSTR);//批次号(*)
	rsMaterials1.AddField(_T("ccheckbill_b1id"),VT_BSTR);//质检单表体主键
	rsMaterials1.AddField(_T("dproducedate"),VT_BSTR);//生产日期(*)
	rsMaterials1.AddField(_T("cbaseid"),VT_BSTR);//检验产品(*)(从基本数据中的物料档案主键)
	rsMaterials1.AddField(_T("cchgbasid"),VT_BSTR);//改判后产品(*)(如果有改判,就要填写)
	rsMaterials1.AddField(_T("cchgassistunitid"),VT_BSTR);//改判辅计量单位id(*)
	rsMaterials1.AddField(_T("vdef1"),VT_BSTR);//自定义1
	rsMaterials1.AddField(_T("vdef2"),VT_BSTR);//自定义2
	rsMaterials1.AddField(_T("vdef3"),VT_BSTR);//自定义3
	rsMaterials1.AddField(_T("vdef4"),VT_BSTR);//自定义4
	rsMaterials1.AddField(_T("vdef5"),VT_BSTR);//自定义5
	rsMaterials1.AddField(_T("vfree1"),VT_BSTR);//自由项1(产品标准)(*)
	rsMaterials1.AddField(_T("vfree2"),VT_BSTR);//自由项2(技术要求)(*)
	rsMaterials1.AddField(_T("vfree3"),VT_BSTR);//自由项3
	rsMaterials1.AddField(_T("vfree4"),VT_BSTR);//自由项4
	rsMaterials1.AddField(_T("vfree5"),VT_BSTR);//自由项5
	rsMaterials1.AddField(_T("nnum"),VT_BSTR);//判定数量(*)
	rsMaterials1.AddField(_T("nassistnum"),VT_BSTR);//判定辅数量(*)
	rsMaterials1.AddField(_T("bcheckin"),VT_BSTR);//可否入库
	rsMaterials1.AddField(_T("bqualified"),VT_BSTR);//是否合格品
	rsMaterials1.AddField(_T("bchange"),VT_BSTR);//是否改判(*)(Y/N)
	rsMaterials1.AddField(_T("ccheckstatecode"),VT_BSTR);//质量等级编码
	rsMaterials1.AddField(_T("ccheckstatename"),VT_BSTR);//质量等级名称
	rsMaterials1.AddField(_T("vmemo"),VT_BSTR);//不合格说明
	rsMaterials1.AddField(_T("ccheckstate_bid"),VT_BSTR);//质量等级主键(*)(质量等级档案中ccheckstatecode第一位为4开头的)
	rsMaterials1.AddField(_T("ObjectID"),VT_BSTR);

	//组建从表2数据集
	CL3RecordSet *pRSRtn2 = new CL3RecordSet();
	CL3RecordSetWrap rsMaterials2; pRSRtn2->QueryInterface(IID_IL3RecordSet,rsMaterials2); rsMaterials2->Release();
	rsMaterials2.AddField(_T("cbaseid"),VT_BSTR);//检验产品
	rsMaterials2.AddField(_T("dcheckdate"),VT_BSTR);//检验日期(*)
	rsMaterials2.AddField(_T("vsamplecode"),VT_BSTR);//样本号(*)
	rsMaterials2.AddField(_T("nnum"),VT_R8);//检验数量
	rsMaterials2.AddField(_T("ccheckitemid"),VT_BSTR);//检验项目(*)
	rsMaterials2.AddField(_T("ccheckstandardid"),VT_BSTR);//检验标准主键(*)(在基础数据中检验标准中通过ccheckstandardname和ccheckitemid获取)
	rsMaterials2.AddField(_T("icheckstandard"),VT_BSTR);//检验标准类型
	rsMaterials2.AddField(_T("cresult"),VT_BSTR);//检验值(*)
	rsMaterials2.AddField(_T("ccheckerid"),VT_BSTR);//检验员(*)
	rsMaterials2.AddField(_T("ObjectID"),VT_BSTR);
#pragma endregion

	CString csHeatID=strHeatID;
	
#pragma region "非不锈钢"

#pragma region "按炉号查找最后一条质量信息"
	//过程终判
	if(csType == _T("0"))
	{
		//按照炉号和时间找出每炉最后一条信息
		CString csTempSQL  = _T(" select d.HeatID,d.GUID,d.SteelGradeIndex,d.Final_SteelGradeIndex,d.Wrong_Count1,d.Wrong_Count2,d.Wrong_Count3 from CCCM_Base_Data c,		");
		csTempSQL += _T(" (select a.HeatID,a.Guid,a.NC_Confirm_Flag ,a.SteelGradeIndex,a.Final_SteelGradeIndex,a.Wrong_Count1,a.Wrong_Count2,a.Wrong_Count3 from	");
		csTempSQL += _T(" CQA_Bloom_FinJudge_Data a, (select HeatID,max(FinalJudge_Time) as FinalJudge_Time from  CQA_Bloom_FinJudge_Data group by HeatID) b where 	");
		csTempSQL += _T(" a.HeatID =b.HeatID and a.FinalJudge_Time=b. FinalJudge_Time) d	where c.HeatID = d.HeatID and c.HeatID = '%s'							"); 		
		csSQL.Format(csTempSQL,strHeatID);		
		if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
			return NULL;
	}
	//库内改判
	else
	{
		//按照炉号和时间找出每炉最后一条信息
		CString csTempSQL  = _T(" select d.HeatID,d.GUID,d.SteelGradeIndex,d.Final_SteelGradeIndex,d.Wrong_Count1,d.Wrong_Count2,d.Wrong_Count3 from CCCM_Base_Data c,					");
		csTempSQL += _T(" (select a.HeatID,a.Guid,a.Store_ChangeJudge_Flag,a.SteelGradeIndex,a.Final_SteelGradeIndex,a.Wrong_Count1,a.Wrong_Count2,a.Wrong_Count3				");
		csTempSQL += _T(" from CQA_Bloom_FinJudge_Data a, (select HeatID,max(FinalJudge_Time) as FinalJudge_Time from  CQA_Bloom_FinJudge_Data group by HeatID) b 				"); 
		csTempSQL += _T(" where a.HeatID =b.HeatID and a.FinalJudge_Time= b. FinalJudge_Time) d	where c.HeatID = d.HeatID and c.HeatID = '%s' and d.Store_ChangeJudge_Flag = 1	");
		csSQL.Format(csTempSQL,strHeatID);		
		if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
			return NULL;
	}

#pragma endregion

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//钢坯信息
		CString csHeatID  = rs.GetFieldByName(_T("HeatID")).ToCString();
		CString csGUID = rs.GetFieldByName(_T("GUID")).ToCString();
		CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
		L3DOUBLE dWrong_Count1 = rs.GetFieldByName(_T("Wrong_Count1")).ToDouble();
		L3DOUBLE dWrong_Count2 = rs.GetFieldByName(_T("Wrong_Count2")).ToDouble();
		L3DOUBLE dWrong_Count3 = rs.GetFieldByName(_T("Wrong_Count3")).ToDouble();

		//入库前后改判判定条件从终判记录找，避免库内改判回原钢种找不到条件
		CString csPreSteelGradeIndex  = rs.GetFieldByName(_T("SteelGradeIndex")).ToCString();//判前钢种
		CString csCurSteelGradeIndex  = rs.GetFieldByName(_T("Final_SteelGradeIndex")).ToCString();//判后钢种

		CString csCurMaterialID;
		CString csCurZyx1;
		CString csCurZyx2;

		CString csPreMaterialID;
#pragma region "主表"
		//主表信息
		CString csTempSQL1  = _T(" select a.HeatID,'1' as Flag,a.HeatID as scddh,'MES' as cpraydeptid,b.PLANNER as cprayerid,a.Operator as creporterid,To_Char(a.FinalJudge_Time,'yyyy-mm-dd hh24:mi:ss') as dpraydate,a.Cal_Weight ");
		csTempSQL1 += _T(" as nchecknum,a.Bloom_Count as nassistchecknum,'jlda0000000000000019' as cassistunitid,a.GUID as ObjectID from VIEW_BLOOM_FIANLJUDGE_DATA a,CPLAN_TAPPING b	   ");
		csTempSQL1 += _T(" where a.heatid = b.heatid and a.GUID = '%s'");
		CString csSQL1;
		csSQL1.Format(csTempSQL1,csGUID);
		CL3RecordSetWrap rsResult1;
		if(!Query(csSQL1,rsResult1))
			return NULL;
		rsMain.CopyFrom(rsResult1);
#pragma endregion
#pragma region "从表1信息"
		//从表1信息
		//改判
		if(csPreSteelGradeIndex !=csCurSteelGradeIndex && csCurSteelGradeIndex != WAITING_FIN_JUDGE)
		{
			//获取改判前后的物料编码2009-04-04
			CL3RecordSetWrap rsNext = ModifySteelGrade(csHeatID,csCurSteelGradeIndex);
			rsNext.MoveFirst();
			csCurMaterialID = rsNext.GetFieldByName(_T("MaterialID")).ToCString();
			csCurZyx1 = rsNext.GetFieldByName(_T("free1")).ToCString();
			csCurZyx2 = rsNext.GetFieldByName(_T("free2")).ToCString();

			CL3RecordSetWrap rsPre = ModifySteelGrade(csHeatID,csPreSteelGradeIndex);
			csPreMaterialID = rsPre.GetFieldByName(_T("MaterialID")).ToCString();

#pragma region "不合格重量1、2、3"
			//不合格重量 > 0
			if(dWrong_Count1 > 0)
			{
				CString csTempSQL2  =_T(" select '1006AA100000000EBWCF' as pk_stordoc,a.GUID as ObjectID,a.HeatID as vinvbatchcode,To_Char(b.ProductionDate,'yyyy-mm-dd') as dproducedate,a.Cal_Weight ");
				csTempSQL2 +=_T(" as nchecknum,a.Bloom_Count as nassistchecknum,");
				csTempSQL2 +=_T(" \'") + csPreMaterialID + _T(" \' as cbaseid,"); 																  
				csTempSQL2 +=_T(" \'") + csCurMaterialID + _T("\' as cchgbasid,																													");
				csTempSQL2 += _T(" \'") + csCurZyx1 + _T(" \' as vfree1,") + _T(" \'") + csCurZyx2 + _T(" \' as vfree2,'jlda0000000000000019' as cchgassistunitid,'N' as bchang,				");
				csTempSQL2 +=_T(" a.Wrong_Count1 as nassistnum,a.Wrong_Weight1 as nnum,(select Code_Des from CBASE_ALL_CODE where Code = a.Wrong_Reason1 and Code_Group ='WRONG_REASON_CODE') as");
				csTempSQL2 +=_T("  vmemo,'Y' as bchange,'1001NC100000000052Z6' as ccheckstate_bid	from CQA_Bloom_FinJudge_Data a,CCCM_Base_Data b,CBLOOM_DATA d								");
				csTempSQL2 +=_T(" where a.HeatID = b.HeatID and a.HeatID = d.HeatID  and a.GUID = '%s'																							");
				CString csSQL2;
				csSQL2.Format(csTempSQL2,csGUID);
				CL3RecordSetWrap rsResultP2;
				if(!Query(csSQL2,rsResultP2))
					return NULL;
				rsMaterials1.CopyFrom(rsResultP2);
			}
			if(dWrong_Count2 > 0)
			{
				CString csTempSQL2  =_T(" select '1006AA100000000EBWCF' as pk_stordoc,a.GUID as ObjectID,a.HeatID as vinvbatchcode,To_Char(b.ProductionDate,'yyyy-mm-dd') as dproducedate,a.Cal_Weight ");
				csTempSQL2 +=_T(" as nchecknum,a.Bloom_Count as nassistchecknum,");
				csTempSQL2 +=_T(" \'") + csPreMaterialID + _T(" \' as cbaseid,"); 																  
				csTempSQL2 +=_T(" \'") + csCurMaterialID + _T("\' as cchgbasid,																													");
				csTempSQL2 +=_T(" \'") + csCurZyx1 + _T(" \' as vfree1,") + _T(" \'") + csCurZyx2 + _T(" \' as vfree2,'jlda0000000000000019' as cchgassistunitid,'N' as bchang,					");
				csTempSQL2 +=_T(" a.Wrong_Count2 as nassistnum,a.Wrong_Weight2 as nnum,(select Code_Des from CBASE_ALL_CODE where Code = a.Wrong_Reason2 and Code_Group ='WRONG_REASON_CODE') as");
				csTempSQL2 +=_T(" vmemo,'Y' as bchange,'1001NC100000000052Z6' as ccheckstate_bid from CQA_Bloom_FinJudge_Data a,CCCM_Base_Data b,CBLOOM_DATA d									");
				csTempSQL2 +=_T(" where a.HeatID = b.HeatID and a.HeatID = d.HeatID  and a.GUID = '%s'																							");
				CString csSQL2;
				csSQL2.Format(csTempSQL2,csGUID);
				CL3RecordSetWrap rsResultP2;
				if(!Query(csSQL2,rsResultP2))
					return NULL;
				rsMaterials1.CopyFrom(rsResultP2);
			}
			if(dWrong_Count3 > 0)
			{
				CString csTempSQL2  =_T(" select '1006AA100000000EBWCF' as pk_stordoc,a.GUID as ObjectID,a.HeatID as vinvbatchcode,To_Char(b.ProductionDate,'yyyy-mm-dd') as dproducedate,a.Cal_Weight ");
				csTempSQL2 +=_T(" as nchecknum,a.Bloom_Count as nassistchecknum,");
				csTempSQL2 +=_T(" \'") + csPreMaterialID + _T(" \' as cbaseid,"); 																  
				csTempSQL2 +=_T(" \'") + csCurMaterialID + _T("\' as cchgbasid,																													");
				csTempSQL2 +=_T(" \'") + csCurZyx1 + _T(" \' as vfree1,") + _T(" \'") + csCurZyx2 + _T(" \' as vfree2,'jlda0000000000000019' as cchgassistunitid,'N' as bchang,					");
				csTempSQL2 +=_T(" a.Wrong_Count3 as nassistnum,a.Wrong_Weight3 as nnum,(select Code_Des from CBASE_ALL_CODE where Code = a.Wrong_Reason3 and Code_Group ='WRONG_REASON_CODE') as");
				csTempSQL2 +=_T(" vmemo,'Y' as bchange,'1001NC100000000052Z6' as ccheckstate_bid	from CQA_Bloom_FinJudge_Data a,CCCM_Base_Data b,CBLOOM_DATA d								");
				csTempSQL2 +=_T(" where a.HeatID = b.HeatID and a.HeatID = d.HeatID  and a.GUID = '%s'																							");
				CString csSQL2;
				csSQL2.Format(csTempSQL2,csGUID);
				CL3RecordSetWrap rsResultP2;
				if(!Query(csSQL2,rsResultP2))
					return NULL;
				rsMaterials1.CopyFrom(rsResultP2);
			}
#pragma endregion

#pragma region "合格重量"
			//合格重量 > 0			
			CString csTempSQL2  =_T(" select '1006AA100000000EBWCE' as pk_stordoc,a.GUID as ObjectID,a.HeatID as vinvbatchcode,To_Char(b.ProductionDate,'yyyy-mm-dd') as dproducedate,a.Cal_Weight	");
			csTempSQL2 +=_T(" as nchecknum,a.Bloom_Count as nassistchecknum,");
			csTempSQL2 +=_T(" \'") + csPreMaterialID + _T(" \' as cbaseid,"); 
			csTempSQL2 +=_T(" \'") + csCurMaterialID + _T("\' as cchgbasid,																								  ");
			csTempSQL2 +=_T(" \'") + csCurZyx1 + _T(" \' as vfree1,") + _T(" \'") + csCurZyx2 + _T(" \' as vfree2,'jlda0000000000000019' as cchgassistunitid,'N' as bchang,  ");
			csTempSQL2 +=_T(" (a.Right_Weight-a.WASTER_WEIGHT) as nnum,a.Right_Count as nassistnum,'Y' as bchange,'1001NC100000000052Z3' as ccheckstate_bid								  ");
			csTempSQL2 +=_T(" from CQA_Bloom_FinJudge_Data a,CCCM_Base_Data b,CBLOOM_DATA d																  ");
			csTempSQL2 +=_T(" where a.HeatID = b.HeatID and a.HeatID = d.HeatID  and a.Right_Weight > 0 and a.GUID = '%s'					  ");							
			CString csSQL2;
			csSQL2.Format(csTempSQL2,csGUID);
			CL3RecordSetWrap rsResultP3;
			if(!Query(csSQL2,rsResultP3))
				return NULL;
			rsMaterials1.CopyFrom(rsResultP3);
#pragma endregion 

		}
		//没有改判
		else
		{
#pragma region "待判"
			//待判
			CString csTempSQL2  =_T(" select a.GUID as ObjectID,a.HeatID as vinvbatchcode,To_Char(b.ProductionDate,'yyyy-mm-dd') as dproducedate,a.Cal_Weight		");
			csTempSQL2 +=_T(" as nchecknum,a.Bloom_Count as nassistchecknum,c.MATERIALCODE_ID as cbaseid,c.ProduceStd as vfree1,c.Tech_Request as vfree2,	");
			csTempSQL2 +=_T(" a.Cal_Weight as nnum,a.Bloom_Count as nassistnum,'1001NC100000000052Z5' as ccheckstate_bid,'N' as bchange						");
			csTempSQL2 +=_T(" from CQA_Bloom_FinJudge_Data a,CCCM_Base_Data b,CPlan_Order c,CBLOOM_DATA d where a.HeatID = b.HeatID and a.HeatID = d.HeatID ");
			csTempSQL2 +=_T("  and c.PlanID = d.PLAN_ORD_ID and a.Final_SteelGradeIndex = 'YY000000' and a.GUID = '%s'										");				
			CString csSQL2;
			csSQL2.Format(csTempSQL2,csGUID);
			CL3RecordSetWrap rsResultP4;
			if(!Query(csSQL2,rsResultP4))
				return NULL;
			rsMaterials1.CopyFrom(rsResultP4);
#pragma endregion 

#pragma region "不合格1、2、3"
			//不合格
			if(dWrong_Count1 > 0)
			{
				csTempSQL2  =_T(" select '1006AA100000000EBWCF' as pk_stordoc,a.GUID as ObjectID,a.HeatID as vinvbatchcode,To_Char(b.ProductionDate,'yyyy-mm-dd') as dproducedate,a.Cal_Weight		");
				csTempSQL2 +=_T(" as nchecknum,a.Bloom_Count as nassistchecknum,c.MATERIALCODE_ID as cbaseid,c.ProduceStd as vfree1,c.Tech_Request as vfree2,										");
				csTempSQL2 +=_T(" a.Wrong_Weight1 as nnum,a.Wrong_Count1 as nassistnum,(select Code_Des from CBASE_ALL_CODE where Code = a.Wrong_Reason1 and Code_Group ='WRONG_REASON_CODE') as	");
				csTempSQL2 +=_T(" vmemo,'1001NC100000000052Z6' as ccheckstate_bid,'N' as bchange from CQA_Bloom_FinJudge_Data a,CCCM_Base_Data b,CPlan_Order c,CBLOOM_DATA d where a.HeatID = 		");
				csTempSQL2 +=_T(" b.HeatID and a.HeatID = d.HeatID and c.PlanID = d.PLAN_ORD_ID and a.Final_SteelGradeIndex <> 'YY000000' and a.GUID = '%s'											");				
				csSQL2.Format(csTempSQL2,csGUID);
				CL3RecordSetWrap rsResultP5;
				if(!Query(csSQL2,rsResultP5))
					return NULL;
				rsMaterials1.CopyFrom(rsResultP5);
			}
			if(dWrong_Count2 > 0)
			{
				csTempSQL2  =_T(" select '1006AA100000000EBWCF' as pk_stordoc,a.GUID as ObjectID,a.HeatID as vinvbatchcode,To_Char(b.ProductionDate,'yyyy-mm-dd') as dproducedate,a.Cal_Weight		");
				csTempSQL2 +=_T(" as nchecknum,a.Bloom_Count as nassistchecknum,c.MATERIALCODE_ID as cbaseid,c.ProduceStd as vfree1,c.Tech_Request as vfree2,										");
				csTempSQL2 +=_T(" a.Wrong_Weight2 as nnum,a.Wrong_Count2 as nassistnum,(select Code_Des from CBASE_ALL_CODE where Code = a.Wrong_Reason2 and Code_Group ='WRONG_REASON_CODE') as	");
				csTempSQL2 +=_T(" vmemo,'1001NC100000000052Z6' as ccheckstate_bid,'N' as bchange from CQA_Bloom_FinJudge_Data a,CCCM_Base_Data b,CPlan_Order c,CBLOOM_DATA d where a.HeatID = 		");
				csTempSQL2 +=_T(" b.HeatID and a.HeatID = d.HeatID and c.PlanID = d.PLAN_ORD_ID and a.Final_SteelGradeIndex <> 'YY000000' and a.GUID = '%s'											");						
				csSQL2.Format(csTempSQL2,csGUID);
				CL3RecordSetWrap rsResultP5;
				if(!Query(csSQL2,rsResultP5))
					return NULL;
				rsMaterials1.CopyFrom(rsResultP5);
			}
			if(dWrong_Count3 > 0)
			{
				csTempSQL2  =_T(" select '1006AA100000000EBWCF' as pk_stordoc,a.GUID as ObjectID,a.HeatID as vinvbatchcode,To_Char(b.ProductionDate,'yyyy-mm-dd') as dproducedate,a.Cal_Weight		");
				csTempSQL2 +=_T(" as nchecknum,a.Bloom_Count as nassistchecknum,c.MATERIALCODE_ID as cbaseid,c.ProduceStd as vfree1,c.Tech_Request as vfree2,										");
				csTempSQL2 +=_T(" a.Wrong_Weight3 as nnum,a.Wrong_Count3 as nassistnum,(select Code_Des from CBASE_ALL_CODE where Code = a.Wrong_Reason3 and Code_Group ='WRONG_REASON_CODE') as	");
				csTempSQL2 +=_T(" vmemo,'1001NC100000000052Z6' as ccheckstate_bid,'N' as bchange from CQA_Bloom_FinJudge_Data a,CCCM_Base_Data b,CPlan_Order c,CBLOOM_DATA d where a.HeatID = 		");
				csTempSQL2 +=_T(" b.HeatID and a.HeatID = d.HeatID and c.PlanID = d.PLAN_ORD_ID and a.Final_SteelGradeIndex <> 'YY000000' and a.GUID = '%s'											");			
				csSQL2.Format(csTempSQL2,csGUID);
				CL3RecordSetWrap rsResultP5;
				if(!Query(csSQL2,rsResultP5))
					return NULL;
				rsMaterials1.CopyFrom(rsResultP5);
			}
#pragma endregion

#pragma region "合格"
			//合格
			csTempSQL2  =_T(" select '1006AA100000000EBWCE' as pk_stordoc,a.GUID as ObjectID,a.HeatID as vinvbatchcode,To_Char(b.ProductionDate,'yyyy-mm-dd') as dproducedate,a.Cal_Weight		");
			csTempSQL2 +=_T(" as nchecknum,a.Bloom_Count as nassistchecknum,c.MATERIALCODE_ID as cbaseid,c.ProduceStd as vfree1,c.Tech_Request as vfree2,		");
			csTempSQL2 +=_T(" (a.Right_Weight-a.WASTER_WEIGHT) as nnum,a.Right_Count as nassistnum,'1001NC100000000052Z3' as ccheckstate_bid,'N' as bchange						");
			csTempSQL2 +=_T(" from CQA_Bloom_FinJudge_Data a,CCCM_Base_Data b,CPlan_Order c,CBLOOM_DATA d where a.HeatID = b.HeatID and a.HeatID = d.HeatID ");
			csTempSQL2 +=_T("  and c.PlanID = d.PLAN_ORD_ID and a.Final_SteelGradeIndex <> 'YY000000' and a.Right_Weight > 0 and a.GUID = '%s'				");				
			csSQL2.Format(csTempSQL2,csGUID);
			CL3RecordSetWrap rsResultP6;
			if(!Query(csSQL2,rsResultP6))
				return NULL;
			rsMaterials1.CopyFrom(rsResultP6);
#pragma endregion 

		}
#pragma endregion

		if(csType != _T("0"))
		{
			rsMaterials1.MoveFirst();
			while(!rsMaterials1.IsEOF())
			{
				rsMaterials1.SetFieldByName(_T("pk_stordoc"),CL3Variant(_T("1006AA100000000EBWCE")));
				rsMaterials1.MoveNext();
			}
		}

#pragma region "从表2信息"
		//从表2信息
		CString csTempSQL3 = _T("select to_char(a.finaljudge_time,'yyyy-mm-dd hh24:mi:ss') as finaljudgetime,a.* from VIEW_BLOOM_FIANLJUDGE_DATA a where a.GUID = '%s'");
		CString csSQL3;
		csSQL3.Format(csTempSQL3,csGUID);
		CL3RecordSetWrap rsResult3;
		if(!Query(csSQL3,rsResult3))
			return NULL;
		if(rsResult3.GetRowCount()<1)
			return NULL;
		//按照终盘视图里的元素位置定义与之相对应的NC检验编码静态数组
		CString CheckItemID[30] = {_T("1001NC10000000004KXY")/*C*/,_T("1001NC10000000004KXU")/*Si*/,_T("1001NC10000000004KXW")/*Mn*/,_T("1001NC10000000004KX3")/*P*/,_T("1001NC10000000004KX2")/*S*/,
			_T("1001NC10000000004KYZ")/*Cu*/,_T("1001NC10000000004L1A")/*Ni*/,_T("1001NC10000000004KYE")/*Cr*/,_T("1001NC10000000004KY9")/*Mo*/,_T("1001NC10000000004KYB")/*V*/,
			_T("1001NC10000000004L2Z")/*Nb*/,_T("1001NC10000000004L18")/*Al*/,_T("1001NC10000000004L30")/*ALS*/,_T("1001NC10000000004KYF")/*Ti*/,_T("1001NC10000000004KYH")/*B*/,
			_T("1001NC10000000004L2W")/*Sb*/,_T("1001NC10000000004L29")/*AS*/,_T("1001NC10000000004L2A")/*Sn*/,_T("1001NC10000000004KYX")/*Zn*/,_T("1001NC10000000004KY2")/*Ca*/,
			_T("1001NC10000000004L2B")/*W*/,_T("1001NC10000000004KYV")/*Pb*/,_T("1001NC10000000004KXF")/*Re*(R)*/,_T("1001NC10000000004L14")/*Ceq*/,_T("1001NC10000000004L25")/*N*/,
			_T( "1001NC10000000004L26")/*H*/,_T("1001NC10000000004L24")/*O*/,_T("1001NC10000000005EQY")/*CrNi*/,_T("")/*CrCu*(无)*/,_T("1001NC10000000005L7I")/*CrNiCu*/}; 
		rsMaterials2.MoveFirst();
		rsResult3.MoveFirst();
		//只有30个元素
		for(int i=0;i<30;i++)
		{
			rsMaterials2.AppendRecord();
			rsMaterials2.SetFieldByName(_T("dcheckdate"),rsResult3.GetFieldByName(_T("finaljudgetime")));
			rsMaterials2.SetFieldByName(_T("vsamplecode"),rsResult3.GetFieldByName(_T("sample_code")));			
			rsMaterials2.SetFieldByName(_T("ccheckerid"),rsResult3.GetFieldByName(_T("Operator")));
			rsMaterials2.SetFieldByName(_T("ObjectID"),CL3Variant(csGUID));
			rsMaterials2.SetFieldByName(_T("ccheckitemid"),CL3Variant(CheckItemID[i]));
			rsMaterials2.SetFieldByName(_T("cresult"),rsResult3.GetFieldByIndex(56+i));
		}
		rsMaterials2.MoveFirst();
		while(!rsMaterials2.IsEOF())
		{
			if(rsMaterials2.GetFieldByName(_T("cresult")).ToCString() == _T(""))
				rsMaterials2.DeleteRecord();
			else
				rsMaterials2.MoveNext();
		}
#pragma endregion
		rs.MoveNext();
	}
#pragma endregion

	if (*rsMaterialsData1 != NULL)
		(*rsMaterialsData1)->Release();
	(*rsMaterialsData1) = rsMaterials1.Detach(); 
	if (*rsMaterialsData2 != NULL)
		(*rsMaterialsData2)->Release();
	(*rsMaterialsData2) = rsMaterials2.Detach(); 
	return rsMain.Detach();
}



/// <Method class="CBloom_Store_Mag" name="SendBloomInStoreInfor" type="L3LONG">
/// 2009-03-26 liuzhiqiang
/// 向NC补发钢坯入库电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::SendBloomInStoreInfor(L3STRING strHeatID,L3RECORDSET *rsMainData)
{
#pragma region "创建记录集"
	//组建主表数据集
	CL3RecordSet *pRSRtnMain = new CL3RecordSet();
	CL3RecordSetWrap rsMain; pRSRtnMain->QueryInterface(IID_IL3RecordSet,rsMain); pRSRtnMain->Release();
	rsMain.AddField(_T("HeatID"),VT_BSTR);
	rsMain.AddField(_T("Flag"),VT_BSTR);//1表示:钢 2表示:铁
	rsMain.AddField(_T("vbatchcode"),VT_BSTR);//批次号
	rsMain.AddField(_T("cwarehouseid"),VT_BSTR);//入库仓库
	rsMain.AddField(_T("NC_Confirm_Flag"),VT_BSTR);//确认标志
	rsMain.AddField(_T("GUID"),VT_BSTR);//主键
	rsMain.AddField(_T("TreatNo"),VT_BSTR);//MaterialID
	rsMain.AddField(_T("ObjectID"),VT_BSTR);//MaterialID

	//组建从表数据集
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsMaterials; pRSRtn->QueryInterface(IID_IL3RecordSet,rsMaterials); rsMaterials->Release();
	rsMaterials.AddField(_T("cwarehouseid"),VT_BSTR);//入库仓库(*)
	rsMaterials.AddField(_T("taccounttime"),VT_BSTR);//库房签字时间(*)
	rsMaterials.AddField(_T("coperatorid"),VT_BSTR);//操作员编码(*)
	rsMaterials.AddField(_T("ccheckstate_bid"),VT_BSTR);//质量等级主键(*)(和质检相同)
	rsMaterials.AddField(_T("cworkcenterid"),VT_BSTR);//工作中心主键(*)(基础数据中工作中心档案获取)
	rsMaterials.AddField(_T("dbizdate"),VT_BSTR);//业务日期(*)
	rsMaterials.AddField(_T("vbatchcode"),VT_BSTR);//批次号(*)(废钢没有批次号)
	rsMaterials.AddField(_T("cinvbasid"),VT_BSTR);//入库存货(*)(从基本数据中的物料档案中获取)
	rsMaterials.AddField(_T("pk_produce"),VT_BSTR);//入库产品
	rsMaterials.AddField(_T("ninnum"),VT_R8);//入库数量(*)
	rsMaterials.AddField(_T("ninassistnum"),VT_R8);//入库辅数量(*)
	/****************************************************************/
	//2009-03-03 Modify by liuzhiqiang
	rsMaterials.AddField(_T("castunitid"),VT_BSTR);//辅计量单位id(*)(有就填写,没有不填写)
	/****************************************************************/
	rsMaterials.AddField(_T("vuserdef1"),VT_BSTR);//自定义1
	rsMaterials.AddField(_T("vuserdef2"),VT_BSTR);//自定义2
	rsMaterials.AddField(_T("vuserdef3"),VT_BSTR);//自定义3
	rsMaterials.AddField(_T("vuserdef4"),VT_BSTR);//自定义4
	rsMaterials.AddField(_T("vuserdef5"),VT_BSTR);//自定义5
	rsMaterials.AddField(_T("vuserdef6"),VT_BSTR);//自定义6
	rsMaterials.AddField(_T("vuserdef7"),VT_BSTR);//自定义7
	rsMaterials.AddField(_T("vuserdef8"),VT_BSTR);//自定义8
	rsMaterials.AddField(_T("vuserdef9"),VT_BSTR);//自定义9
	rsMaterials.AddField(_T("vuserdef10"),VT_BSTR);//自定义10
	rsMaterials.AddField(_T("vfree1"),VT_BSTR);//自由项1(产品标准)(*)
	rsMaterials.AddField(_T("vfree2"),VT_BSTR);//自由项2(技术要求)(*)
	rsMaterials.AddField(_T("vfree3"),VT_BSTR);//自由项3
	rsMaterials.AddField(_T("vfree4"),VT_BSTR);//自由项4
	rsMaterials.AddField(_T("vfree5"),VT_BSTR);//自由项5
	rsMaterials.AddField(_T("pk_corp"),VT_BSTR);//公司
	rsMaterials.AddField(_T("gcbm"),VT_BSTR);//工厂
	rsMaterials.AddField(_T("ObjectID"),VT_BSTR);//MaterialID

#pragma endregion

	//判断是否为全回炉
	CString csTempSQL = _T(" select Status from CSteel_Data where HeatID = '%s' ");
	CString csSQL;
	csSQL.Format(csTempSQL,strHeatID);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData) || rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return NULL;
	rsSteelData.MoveFirst();
	CString csType = rsSteelData.GetFieldByName(_T("Status")).ToCString();

	if(csType != _T("5"))
	{
#pragma region "非全回炉"
		CString csTempSQL = _T(" select HeatID,TreatNo from  CCCM_Base_Data  where HeatID='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,strHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
			return NULL;
		rs.MoveFirst();
		while(!rs.IsEOF())
		{
			CString csHeatID = rs.GetFieldByName(_T("HeatID")).ToCString();
			CString csTreatNo = rs.GetFieldByName(_T("TreatNo")).ToCString();


			//热送
			//CString csTempSQL1  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,(select NC_Code from CBase_All_Code where Code = e.Target ) as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,"); 
			//csTempSQL1 += _T(" '1001NC100000000052Z3' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 					                                          ");
			//csTempSQL1 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' then '1001NC100000001JTY8G' end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 		    ");//add by hyh 2012-06-08 新增CCM7
			//csTempSQL1 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,(a.Right_Weight-a.WASTER_WEIGHT) as ninnum,a.RIGHT_COUNT as ninassistnum,'jlda0000000000000019'								                                  ");
			//csTempSQL1 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CBloom_Output_Log e,CCCM_Process_Data f where a.MaterialID = e.MaterialID and 			                      ");
			//csTempSQL1 += _T(" a.Type = '9' and a.Right_Count > 0  and a.MaterialID = b.MaterialID and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc													  ");
//热送  2016-01-05
			CString csTempSQL1  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,(select NC_Code from CBase_All_Code where Code = e.Target ) as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,"); 
			csTempSQL1 += _T(" '1001NC100000000052Z3' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 					                                          ");
			csTempSQL1 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' and substr(c.HeatID,1,1)='2' then '1001NC100000001JTY8G'  when b.CASTERID ='S66' and substr(c.HeatID,1,1)='6' then '1001NC100000002DDER1' end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 		    ");//add by hyh 2012-06-08 新增CCM7
			csTempSQL1 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,(a.Right_Weight-a.WASTER_WEIGHT) as ninnum,a.RIGHT_COUNT as ninassistnum,'jlda0000000000000019'								                                  ");
			csTempSQL1 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CBloom_Output_Log e,CCCM_Process_Data f where a.MaterialID = e.MaterialID and 			                      ");
			csTempSQL1 += _T(" a.Type = '9' and a.Right_Count > 0  and a.MaterialID = b.MaterialID and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc													  ");

			//Modify end
			CString csSQL1;
			csSQL1.Format(csTempSQL1,csHeatID);
			CL3RecordSetWrap rsResult1;
			if(!Query(csSQL1,rsResult1))
				return NULL;
			if(rsResult1.GetRowCount()>0)
			{
#pragma region "热送"
				rsResult1.MoveFirst();
				//钢坯信息
				CString csHeatID  = rsResult1.GetFieldByName(_T("ObjectID")).ToCString();
				CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
				CString csPreSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("Pre_SteelGradeIndex")).ToCString();
				CString csCurSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("SteelGradeIndex")).ToCString();
				rsResult1.SetFieldByName(_T("TreatNo"),CL3Variant(csTreatNo));
				//改判
				if(csPreSteelGradeIndex !=csCurSteelGradeIndex && csCurSteelGradeIndex != WAITING_FIN_JUDGE)
				{
					CL3RecordSetWrap rs = ModifySteelGrade(csHeatID,csCurSteelGradeIndex);
					rs.MoveFirst();
					rsResult1.SetFieldByName(_T("cinvbasid"),rs.GetFieldByName(_T("MaterialID")));
					rsResult1.SetFieldByName(_T("vfree1"),rs.GetFieldByName(_T("free1")));
					rsResult1.SetFieldByName(_T("vfree2"),rs.GetFieldByName(_T("free2")));
				}				
				rsMain.AppendRecord();
				rsMain.CopyCurRowFrom(rsResult1);
				rsMaterials.AppendRecord();
				rsMaterials.CopyCurRowFrom(rsResult1);
#pragma endregion 
			}
			else
			{
#pragma region "冷送合格"
				//冷送合格
				//CString csTempSQL2  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,'1006AA100000000EBWCE' as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,								"); 
				//csTempSQL2 += _T(" '1001NC100000000052Z3' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 				");
				//csTempSQL2 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' then '1001NC100000001JTY8G' end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 				");//add by hyh 2012-06-08 新增CCM7
				//csTempSQL2 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,(a.Right_Weight-a.WASTER_WEIGHT) as ninnum,a.Right_Count as ninassistnum,case when b.RIGHT_COUNT>0 then 'jlda0000000000000019' else '' end  ");
				//csTempSQL2 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CCCM_Process_Data f where a.MaterialID = b.MaterialID and 							");
				//csTempSQL2 += _T(" a.Type = '0' and a.Right_Count > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc																						");

				////Modify end   2015-01-05
				CString csTempSQL2  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,case when substr(c.heatid,1,1)='6' then '1001NC100000001J1L6N' else '1006AA100000000EBWCE' end as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,								"); 
				csTempSQL2 += _T(" '1001NC100000000052Z3' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 				");
				csTempSQL2 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' and  substr(c.heatid,1,1)='2' then '1001NC100000001JTY8G' when b.CASTERID ='S66' and substr(c.heatid,1,1)='6' then '1001NC100000002DDER1' end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 				");//add by hyh 2012-06-08 新增CCM7
				csTempSQL2 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,(a.Right_Weight-a.WASTER_WEIGHT) as ninnum,a.Right_Count as ninassistnum,case when b.RIGHT_COUNT>0 then 'jlda0000000000000019' else '' end  ");
				csTempSQL2 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CCCM_Process_Data f where a.MaterialID = b.MaterialID and 							");
				csTempSQL2 += _T(" a.Type = '0' and a.Right_Count > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc																						");



				CString csSQL2;
				csSQL2.Format(csTempSQL2,csHeatID);
				CL3RecordSetWrap rsResult2;
				if(!Query(csSQL2,rsResult2))
					return NULL;
				if(rsResult2.GetRowCount()>0)
				{
					rsResult2.MoveFirst();
					//钢坯信息
					CString csHeatID  = rsResult2.GetFieldByName(_T("ObjectID")).ToCString();
					CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
					CString csPreSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("Pre_SteelGradeIndex")).ToCString();
					CString csCurSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("SteelGradeIndex")).ToCString();
					rsResult2.SetFieldByName(_T("TreatNo"),CL3Variant(csTreatNo));
					//改判
					if(csPreSteelGradeIndex !=csCurSteelGradeIndex && csCurSteelGradeIndex != WAITING_FIN_JUDGE)
					{
						CL3RecordSetWrap rs = ModifySteelGrade(csHeatID,csCurSteelGradeIndex);
						rs.MoveFirst();
						rsResult2.SetFieldByName(_T("cinvbasid"),rs.GetFieldByName(_T("MaterialID")));
						rsResult2.SetFieldByName(_T("vfree1"),rs.GetFieldByName(_T("free1")));
						rsResult2.SetFieldByName(_T("vfree2"),rs.GetFieldByName(_T("free2")));
					}					
					rsMain.AppendRecord();
					rsMain.CopyCurRowFrom(rsResult2);
					rsMaterials.AppendRecord();
					rsMaterials.CopyCurRowFrom(rsResult2);
				}
#pragma endregion
			}

#pragma region "不合格原因1"
			//不合格原因1
			//CString csTempSQL3  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,'1006AA100000000EBWCF' as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,	"); 
			//csTempSQL3 += _T(" '1001NC100000000052Z6' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 					");
			//csTempSQL3 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' then '1001NC100000001JTY8G' end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 					");//add by hyh 2012-06-08 新增CCM7
			//csTempSQL3 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,b.Wrong_Weight1 as ninnum,b.Wrong_Count1 as ninassistnum,case when b.Wrong_Count1>0 then 'jlda0000000000000019' else '' end	");
			//csTempSQL3 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CCCM_Process_Data f  where a.MaterialID = b.MaterialID and 				");
			//csTempSQL3 += _T(" b.Wrong_Count1 > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc																	");
			//
			//不合格原因1  2016-01-05
			CString csTempSQL3  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,case when substr(b.heatid,1,1)='2' then '1006AA100000000EBWCF' else '1001NC100000001J1L6Q' end as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,	"); 
			csTempSQL3 += _T(" '1001NC100000000052Z6' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 					");
			csTempSQL3 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' and substr(b.heatid,1,1)='2' then '1001NC100000001JTY8G' when b.CASTERID ='S66' and substr(b.heatid,1,1)='6' then '1001NC100000002DDER1' end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 					");//add by hyh 2012-06-08 新增CCM7
			csTempSQL3 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,b.Wrong_Weight1 as ninnum,b.Wrong_Count1 as ninassistnum,case when b.Wrong_Count1>0 then 'jlda0000000000000019' else '' end	");
			csTempSQL3 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CCCM_Process_Data f  where a.MaterialID = b.MaterialID and 				");
			csTempSQL3 += _T(" b.Wrong_Count1 > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc		");
			
			//Modify end
			CString csSQL3;
			csSQL3.Format(csTempSQL3,csHeatID);
			CL3RecordSetWrap rsResult3;
			if(!Query(csSQL3,rsResult3))
				return NULL;
			if(rsResult3.GetRowCount()>0)
			{
				rsResult3.MoveFirst();
				//钢坯信息
				CString csHeatID  = rsResult3.GetFieldByName(_T("ObjectID")).ToCString();
				CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
				CString csPreSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("Pre_SteelGradeIndex")).ToCString();
				CString csCurSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("SteelGradeIndex")).ToCString();
				rsResult3.SetFieldByName(_T("TreatNo"),CL3Variant(csTreatNo));
				//改判
				if(csPreSteelGradeIndex !=csCurSteelGradeIndex && csCurSteelGradeIndex != WAITING_FIN_JUDGE)
				{
					CL3RecordSetWrap rs = ModifySteelGrade(csHeatID,csCurSteelGradeIndex);
					rs.MoveFirst();
					rsResult3.SetFieldByName(_T("cinvbasid"),rs.GetFieldByName(_T("MaterialID")));
					rsResult3.SetFieldByName(_T("vfree1"),rs.GetFieldByName(_T("free1")));
					rsResult3.SetFieldByName(_T("vfree2"),rs.GetFieldByName(_T("free2")));
				}					
			
				if(rsMain.GetRowCount() < 1)
				{
					rsMain.AppendRecord();
					rsMain.CopyCurRowFrom(rsResult3);
				}
				rsMaterials.AppendRecord();
				rsMaterials.CopyCurRowFrom(rsResult3);
			}
#pragma endregion

#pragma region "不合格原因2"
			//不合格原因2
			//CString csTempSQL31  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,'1006AA100000000EBWCF' as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,	"); 
			//csTempSQL31 += _T(" '1001NC100000000052Z6' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 					");
			//csTempSQL31 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9'  when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' then '1001NC100000001JTY8G'  end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 					");//add by hyh 2012-06-08
			//csTempSQL31 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,b.Wrong_Weight2 as ninnum,b.Wrong_Count2 as ninassistnum,case when b.Wrong_Count2>0 then 'jlda0000000000000019' else '' end	");
			//csTempSQL31 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CCCM_Process_Data f  where a.MaterialID = b.MaterialID and 		");
			//csTempSQL31 += _T(" b.Wrong_Count2 > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc															");

			//不合格原因2 2016-01-05
			CString csTempSQL31  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,case when substr(c.heatid,1,1)='2' then '1006AA100000000EBWCF' else '1001NC100000001J1L6Q' end as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,	"); 
			csTempSQL31 += _T(" '1001NC100000000052Z6' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 					");
			csTempSQL31 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9'  when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' and  substr(c.heatid,1,1)='2' then '1001NC100000001JTY8G' when b.CASTERID ='S66' and substr(c.heatid,1,1)='6' then '1001NC100000002DDER1'  end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 					");//add by hyh 2012-06-08
			csTempSQL31 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,b.Wrong_Weight2 as ninnum,b.Wrong_Count2 as ninassistnum,case when b.Wrong_Count2>0 then 'jlda0000000000000019' else '' end	");
			csTempSQL31 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CCCM_Process_Data f  where a.MaterialID = b.MaterialID and 		");
			csTempSQL31 += _T(" b.Wrong_Count2 > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc		");
			//Modify end
			CString csSQL31;
			csSQL31.Format(csTempSQL31,csHeatID);
			CL3RecordSetWrap rsResult31;
			if(!Query(csSQL31,rsResult31))
				return NULL;
			if(rsResult31.GetRowCount()>0)
			{
				rsResult31.MoveFirst();
				//钢坯信息
				CString csHeatID  = rsResult31.GetFieldByName(_T("ObjectID")).ToCString();
				CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
				CString csPreSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("Pre_SteelGradeIndex")).ToCString();
				CString csCurSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("SteelGradeIndex")).ToCString();
				rsResult31.SetFieldByName(_T("TreatNo"),CL3Variant(csTreatNo));
				//改判
				if(csPreSteelGradeIndex !=csCurSteelGradeIndex && csCurSteelGradeIndex != WAITING_FIN_JUDGE)
				{
					CL3RecordSetWrap rs = ModifySteelGrade(csHeatID,csCurSteelGradeIndex);
					rs.MoveFirst();
					rsResult31.SetFieldByName(_T("cinvbasid"),rs.GetFieldByName(_T("MaterialID")));
					rsResult31.SetFieldByName(_T("vfree1"),rs.GetFieldByName(_T("free1")));
					rsResult31.SetFieldByName(_T("vfree2"),rs.GetFieldByName(_T("free2")));
				}					
				
				if(rsMain.GetRowCount() < 1)
				{
					rsMain.AppendRecord();
					rsMain.CopyCurRowFrom(rsResult31);
				}
				rsMaterials.AppendRecord();
				rsMaterials.CopyCurRowFrom(rsResult31);
			}
#pragma endregion

#pragma region "不合格原因3"
			//不合格原因3
			
			//CString csTempSQL32  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,'1006AA100000000EBWCF' as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,	"); 
			//csTempSQL32 += _T(" '1001NC100000000052Z6' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 					");
			//csTempSQL32 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' then '1001NC100000001JTY8G' end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 					");//add by hyh 2012-06-08
			//csTempSQL32 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,b.Wrong_Weight3 as ninnum,b.Wrong_Count3 as ninassistnum,case when b.Wrong_Count3>0 then 'jlda0000000000000019' else '' end	");
			//csTempSQL32 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CCCM_Process_Data f  where a.MaterialID = b.MaterialID and 		");
			//csTempSQL32 += _T(" b.Wrong_Count3 > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc															");
			//
				//不合格原因3 2016-01-05
			//
			CString csTempSQL32  = _T(" select c.HeatID,'1' as Flag,a.MaterialID as ObjectID,case when substr(c.heatid,1,1)='2' then '1006AA100000000EBWCF' else '1001NC100000001J1L6Q' end as cwarehouseid,To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,	"); 
			csTempSQL32 += _T(" '1001NC100000000052Z6' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 					");
			csTempSQL32 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' and substr(c.heatid,1,1)='2' then '1001NC100000001JTY8G' when b.CASTERID ='S66' and substr(c.heatid,1,1)='6' then '1001NC100000002DDER1' end as cworkcenterid,d.MATERIALCODE_ID as cinvbasid, 					");//add by hyh 2012-06-08
			csTempSQL32 += _T(" To_Char(f.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,a.MaterialID as vbatchcode,b.Wrong_Weight3 as ninnum,b.Wrong_Count3 as ninassistnum,case when b.Wrong_Count3>0 then 'jlda0000000000000019' else '' end	");
			csTempSQL32 += _T(" as castunitid,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,CPlan_Order d,CCCM_Process_Data f  where a.MaterialID = b.MaterialID and 		");
			csTempSQL32 += _T(" b.Wrong_Count3 > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and f.HeatID =b.HeatID and b.HeatID = '%s'	order by a.Logdate desc	");
			
			////Modify end
			CString csSQL32;
			csSQL32.Format(csTempSQL32,csHeatID);
			CL3RecordSetWrap rsResult32;
			if(!Query(csSQL32,rsResult32))
				return NULL;
			if(rsResult32.GetRowCount()>0)
			{
				rsResult32.MoveFirst();
				//while(!rsResult32.IsEOF())
				//{
				//钢坯信息
				CString csHeatID  = rsResult32.GetFieldByName(_T("ObjectID")).ToCString();
				CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
				CString csPreSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("Pre_SteelGradeIndex")).ToCString();
				CString csCurSteelGradeIndex  = GetObjectPropValue(csBloomUri,_T("SteelGradeIndex")).ToCString();
				rsResult32.SetFieldByName(_T("TreatNo"),CL3Variant(csTreatNo));
				//改判
				if(csPreSteelGradeIndex !=csCurSteelGradeIndex && csCurSteelGradeIndex != WAITING_FIN_JUDGE)
				{
					CL3RecordSetWrap rs = ModifySteelGrade(csHeatID,csCurSteelGradeIndex);
					rs.MoveFirst();
					rsResult32.SetFieldByName(_T("cinvbasid"),rs.GetFieldByName(_T("MaterialID")));
					rsResult32.SetFieldByName(_T("vfree1"),rs.GetFieldByName(_T("free1")));
					rsResult32.SetFieldByName(_T("vfree2"),rs.GetFieldByName(_T("free2")));
				}					
				//	rsResult32.MoveNext();
				//}
				if(rsMain.GetRowCount() < 1)
				{
					rsMain.AppendRecord();
					rsMain.CopyCurRowFrom(rsResult32);
				}
				rsMaterials.AppendRecord();
				rsMaterials.CopyCurRowFrom(rsResult32);
			}
#pragma endregion 

#pragma region "回炉钢"
			//废钢2009-09-20屏蔽
			//CString csTempSQL5  = _T(" select a.MaterialID as ObjectID,'1006AA100000000E8UQ1' as cwarehouseid,To_Char(e.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,						"); 
			//csTempSQL5 += _T(" '1001NC100000000052Z3' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 				");
			//csTempSQL5 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' then '1001NC100000001JTY8G' end as cworkcenterid,'0001AA1000000002IQ4W' as cinvbasid, 			");//add by hyh 2012-06-08
			//csTempSQL5 += _T(" To_Char(e.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,NULL as vbatchcode,e.Weight_Return as ninnum,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,  ");
			//csTempSQL5 += _T(" CPlan_Order d,CCCM_Process_Data e where a.MaterialID = b.MaterialID and e.Weight_Return > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and b.HeatID =e.HeatID and b.HeatID = '%s' order by a.Logdate desc		");
			////2016-01-05
			CString csTempSQL5  = _T(" select a.MaterialID as ObjectID,case when substr(b.heatid,1,1)='2' then '1006AA100000000E8UQ1' else '1001NC100000001J1L6P' end as cwarehouseid,To_Char(e.CASTINGSTARTTIME,'yyyy-mm-dd hh24:mi:ss') as taccounttime,a.Operator as coperatorid,NULL as TreatNo,						"); 
			csTempSQL5 += _T(" '1001NC100000000052Z3' as ccheckstate_bid,case when b.CASTERID ='S61' then '1001NC100000000015R4' when b.CASTERID ='S62' then '1001NC100000000015R6' when b.CASTERID ='S63' then 				");
			csTempSQL5 += _T(" '1001NC100000000015R7' when b.CASTERID ='S64' then '1001NC100000000015R8' when b.CASTERID ='S65' then '1001NC100000000015R9' when b.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' and substr(c.heatid,1,1)='2' then '1001NC100000001JTY8G' when b.CASTERID ='S66' and substr(c.heatid,1,1)='6' then '1001NC100000002DDER1' end as cworkcenterid,'0001AA1000000002IQ4W' as cinvbasid, 			");//add by hyh 2012-06-08
			csTempSQL5 += _T(" To_Char(e.CASTINGSTARTTIME,'yyyy-mm-dd') as dbizdate,NULL as vbatchcode,e.Weight_Return as ninnum,d.ProduceStd as vfree1,d.Tech_Request as vfree2 from CBloom_Input_Log a,CBLOOM_DATA b,CPlan_Tapping c,  ");
			csTempSQL5 += _T(" CPlan_Order d,CCCM_Process_Data e where a.MaterialID = b.MaterialID and e.Weight_Return > 0 and c.Plan_Ord_ID = d.PlanID and c.HeatID =b.HeatID and b.HeatID =e.HeatID and b.HeatID = '%s' order by a.Logdate desc		");
			
			
			////Modify end
			CString csSQL5;
			csSQL5.Format(csTempSQL5,csHeatID);
			CL3RecordSetWrap rsResult5;
			if(!Query(csSQL5,rsResult5))
				return NULL;
			if(rsResult5.GetRowCount()>0)
			{
				rsResult5.MoveFirst();
				rsMaterials.AppendRecord();
				rsMaterials.CopyCurRowFrom(rsResult5);
			}
#pragma endregion 
			rs.MoveNext();
		}

		if (*rsMainData != NULL)
			(*rsMainData)->Release();
		(*rsMainData) = rsMain.Detach(); 
		return rsMaterials.Detach();
#pragma endregion
	}
	else
	{
#pragma region "全回炉"
		//Modify begin llj 2011-03-14 增加lF5和CCM7工序，LF5NC编码为1001NC100000002DPNCG，屏蔽原语句
		//CString csTempSQL  = _T(" select a.HeatID,'1' as Flag,a.HeatID as ObjectID,'1006AA100000000E8UQ1' as cwarehouseid,To_Char(c.App_Time,'yyyy-mm-dd hh24:mi:ss') as taccounttime,c.App_Operator as coperatorid,		"); 
		//csTempSQL += _T(" case when a.CASTERID ='S61' then '1001NC100000000015R4' when a.CASTERID ='S62' then '1001NC100000000015R6' when a.CASTERID ='S63' then 													");
		//csTempSQL += _T(" '1001NC100000000015R7' when a.CASTERID ='S64' then '1001NC100000000015R8' when a.CASTERID ='S65' then '1001NC100000000015R9' when a.CASTERID ='S67' then '1001NC100000002DPNDB'  when a.CASTERID ='S66' then '1001NC100000001JTY8G'  end as cworkcenterid,'0001AA1000000002IQ4W' as cinvbasid, 	");//add by hyh 2012-06-08
		//csTempSQL += _T(" To_Char(c.App_Time,'yyyy-mm-dd') as dbizdate,NULL as vbatchcode,round(c.App_Steel_Weight,3) as ninnum from CPlan_Tapping a,																	");
		//csTempSQL += _T(" CPlan_Order b,CDisp_SteelTurn_App c where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and c.HeatID = '%s'	 and c.ALL_TURN_FLAG = 1 													");
		//
		
		//2016-01-05
		CString csTempSQL  = _T(" select a.HeatID,'1' as Flag,a.HeatID as ObjectID,case when substr(a.heatid,1,1)='2' then '1006AA100000000E8UQ1' else '1001NC100000001J1L6P' end as cwarehouseid,To_Char(c.App_Time,'yyyy-mm-dd hh24:mi:ss') as taccounttime,c.App_Operator as coperatorid,		"); 
		csTempSQL += _T(" case when a.CASTERID ='S61' then '1001NC100000000015R4' when a.CASTERID ='S62' then '1001NC100000000015R6' when a.CASTERID ='S63' then 													");
		csTempSQL += _T(" '1001NC100000000015R7' when a.CASTERID ='S64' then '1001NC100000000015R8' when a.CASTERID ='S65' then '1001NC100000000015R9' when a.CASTERID ='S67' then '1001NC100000002DPNDB'  when b.CASTERID ='S66' and substr(c.heatid,1,1)='2' then '1001NC100000001JTY8G' when b.CASTERID ='S66' and substr(c.heatid,1,1)='6' then '1001NC100000002DDER1'  end as cworkcenterid,'0001AA1000000002IQ4W' as cinvbasid, 	");//add by hyh 2012-06-08
		csTempSQL += _T(" To_Char(c.App_Time,'yyyy-mm-dd') as dbizdate,NULL as vbatchcode,round(c.App_Steel_Weight,3) as ninnum from CPlan_Tapping a,																	");
		csTempSQL += _T(" CPlan_Order b,CDisp_SteelTurn_App c where a.Plan_Ord_ID = b.PlanID and a.HeatID =c.HeatID and c.HeatID = '%s'	 and c.ALL_TURN_FLAG = 1 													");
	
		
		
		////Modify end
		CString csSQL;
		csSQL.Format(csTempSQL,strHeatID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult))
			return NULL;
		rsResult.MoveFirst();
		rsMain.AppendRecord();
		rsMain.CopyCurRowFrom(rsResult);
		CString csHeatID = strHeatID;
		rsMain.MoveFirst();
		while(!rsMain.IsEOF())
		{
			rsMain.SetFieldByName(_T("vbatchcode"),CL3Variant(csHeatID));
			rsMain.MoveNext();
		}
		rsMaterials.CopyFrom(rsResult);

		if (*rsMainData != NULL)
			(*rsMainData)->Release();
		(*rsMainData) = rsMain.Detach(); 
		return rsMaterials.Detach();
#pragma endregion
	}
}

/// <Method class="CBaseData_Mag" name="SendIronBloomInfor" type="L3LONG">
/// 2009-03-26 liuzhiqiang
/// 向NC补发铁水生产完成电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::SendIronBloomInfor(L3STRING strHeatID,L3RECORDSET *rsMainData)
{
	//组建返回数据集
	CL3RecordSet *pRSRtnMain = new CL3RecordSet();
	CL3RecordSetWrap rsMain; pRSRtnMain->QueryInterface(IID_IL3RecordSet,rsMain); pRSRtnMain->Release();
	rsMain.AddField(_T("HeatID"),VT_BSTR);
	rsMain.AddField(_T("Flag"),VT_BSTR);//1表示:钢 2表示:铁
	rsMain.AddField(_T("pch"),VT_BSTR);//批次号(*)
	rsMain.AddField(_T("zdrid"),VT_BSTR);//操作员编码(*)(最终的操作人员)
	rsMain.AddField(_T("rq"),VT_BSTR);//报告日期(*)
	rsMain.AddField(_T("sj"),VT_BSTR);//报告时间(*)   
	rsMain.AddField(_T("NC_Confirm_Flag"),VT_BSTR);//确认标志
	rsMain.AddField(_T("ObjectID"),VT_BSTR);

	//组建返回数据集
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsMaterials; pRSRtn->QueryInterface(IID_IL3RecordSet,rsMaterials); rsMaterials->Release();
	rsMaterials.AddField(_T("wlbmid"),VT_BSTR);//物料编码id(*)
	rsMaterials.AddField(_T("jldwid"),VT_BSTR);//计量单位id(*)
	rsMaterials.AddField(_T("gzzxid"),VT_BSTR);//工作中心id(*)
	rsMaterials.AddField(_T("ccxh"),VT_BSTR);//产出序号(*) (没有产出序号:给处理号)
	rsMaterials.AddField(_T("gxh"),VT_BSTR);//工序号
	rsMaterials.AddField(_T("pk_produce"),VT_BSTR);//完工产品
	rsMaterials.AddField(_T("ksrq"),VT_BSTR);//开始日期(*)
	rsMaterials.AddField(_T("kssj"),VT_BSTR);//开始时间(*)
	rsMaterials.AddField(_T("jsrq"),VT_BSTR);//结束日期(*)
	rsMaterials.AddField(_T("jssj"),VT_BSTR);//结束时间(*)
	rsMaterials.AddField(_T("hgsl"),VT_R8);//实际完工数量(*)
	rsMaterials.AddField(_T("fhgsl"),VT_I4);//实际完工辅数量(*)
	rsMaterials.AddField(_T("sflfcp"),VT_BSTR);//是否联副产品(*)(是:Y,不是:N)
	rsMaterials.AddField(_T("sffsgp"),VT_BSTR);//是否改判(*)(是:Y,不是:N)
	rsMaterials.AddField(_T("zdy1"),VT_BSTR);//自定义1(导出状态:夜班,白班,中班)
	rsMaterials.AddField(_T("zdy2"),VT_BSTR);//自定义2
	rsMaterials.AddField(_T("zdy3"),VT_BSTR);//自定义3
	rsMaterials.AddField(_T("zdy4"),VT_BSTR);//自定义4
	rsMaterials.AddField(_T("zdy5"),VT_BSTR);//自定义5
	rsMaterials.AddField(_T("freeitemvalue1"),VT_BSTR);//自由项1(产品标准)(*)(有就填写,没有不填)
	rsMaterials.AddField(_T("freeitemvalue2"),VT_BSTR);//自由项2(技术要求)(*)(有就填写,没有不填)
	rsMaterials.AddField(_T("freeitemvalue3"),VT_BSTR);//自由项3
	rsMaterials.AddField(_T("freeitemvalue4"),VT_BSTR);//自由项4
	rsMaterials.AddField(_T("freeitemvalue5"),VT_BSTR);//自由项5
	rsMaterials.AddField(_T("pk_corp"),VT_BSTR);//公司
	rsMaterials.AddField(_T("gcbm"),VT_BSTR);//工厂
	rsMaterials.AddField(_T("ObjectID"),VT_BSTR);

	//Modidy begin 2011-11-30 by llj 增加6号高炉处理其工作中心为1001NC100000002VLN77
	CString csTempSQL  = _T(" select HeatID,Flag,pch,objectid,zdrid,rq,sj,gzzxid,jldwid,wlbmid,ccxh,sum(hgsl) as hgsl,zdy1 from																						");
	csTempSQL += _T(" (select TAP_No as HeatID,'2' as Flag,TAP_No as pch,TAP_No as ObjectID,Operator as zdrid,to_char(Production_Date,'yyyy-mm-dd') as rq,to_char(Production_Date,'hh24:mi:ss') as sj,		");
	csTempSQL += _T(" case when BFID ='1' then '1001NC100000000036ZH' when BFID ='2' then '1001NC100000000036ZI' when BFID ='3' then '1001NC100000000036ZJ' when BFID ='4' then								");				 
	csTempSQL += _T(" '1001NC100000000036ZK' when BFID ='5' then '1001NC100000000036ZL' when BFID ='6' then '1001NC100000002VLN77' else BFID end as gzzxid,'jlda0000000000000012' as jldwid,'CHDA0000000000009282' as	");				 
	csTempSQL += _T(" wlbmid,TAP_No as ccxh,Net_Weight as hgsl,case when Shift ='1' then '夜班' when Shift='2' then '白班' else '中班' end as zdy1 from CBFIron where TAP_No ='%s'							");
	csTempSQL += _T(" ) group by 	HeatID,Flag,pch,objectid,zdrid,rq,sj,gzzxid,jldwid,wlbmid,ccxh,zdy1																										");
	//Modify end by llj

	CString csSQL;
	csSQL.Format(csTempSQL,strHeatID);
	CL3RecordSetWrap rsResult1;
	if(!Query(csSQL,rsResult1))
		return NULL;
	rsResult1.MoveFirst();
	rsMain.CopyFrom(rsResult1);
	rsMaterials.CopyFrom(rsResult1);

	if (*rsMainData != NULL)
		(*rsMainData)->Release();
	(*rsMainData) = rsMain.Detach(); 
	return rsMaterials.Detach();
}

/// <Method class="CBaseData_Mag" name="SendIronQualityJudgeInfor" type="L3LONG">
/// 2009-03-26 liuzhiqiang
/// 向NC补发铁水终判质量电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::SendIronQualityJudgeInfor(L3STRING strHeatID,L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2)
{	
	//组建主表数据集
	CL3RecordSet *pRSRtnMain = new CL3RecordSet();
	CL3RecordSetWrap rsMain; pRSRtnMain->QueryInterface(IID_IL3RecordSet,rsMain); pRSRtnMain->Release();
	rsMain.AddField(_T("HeatID"),VT_BSTR);
	rsMain.AddField(_T("Flag"),VT_BSTR);//1表示:钢 2表示:铁
	rsMain.AddField(_T("scddh"),VT_BSTR);//生产订单号
	rsMain.AddField(_T("vproductbatchcode"),VT_BSTR);//产品批次	
	rsMain.AddField(_T("vprodserialnum"),VT_BSTR);//铁次号	
	rsMain.AddField(_T("vcheckbillcode"),VT_BSTR);//检验单号
	rsMain.AddField(_T("bcompcheck"),VT_BSTR);//是否成分检验
	rsMain.AddField(_T("vbatchcode"),VT_BSTR);//检验批次
	rsMain.AddField(_T("cpraydeptid"),VT_BSTR);//报检部门(*)
	rsMain.AddField(_T("cprayerid"),VT_BSTR);//报检人(编码)(*)
	rsMain.AddField(_T("creporterid"),VT_BSTR);//检验人(编码)(*)
	rsMain.AddField(_T("dpraydate"),VT_BSTR);//报检日期(*)
	rsMain.AddField(_T("nchecknum"),VT_R8);//报检数量(*)
	rsMain.AddField(_T("nassistchecknum"),VT_R8);//报检辅数量(*)
	rsMain.AddField(_T("cassistunitid"),VT_BSTR);//辅计量单位id(*)
	rsMain.AddField(_T("cstoreorganization"),VT_BSTR);//库存组织
	rsMain.AddField(_T("cpraycorp"),VT_BSTR);//报检公司
	rsMain.AddField(_T("ccheckbillid"),VT_BSTR);// 质量检验单主键
	rsMain.AddField(_T("NC_Confirm_Flag"),VT_BSTR);//确认标志
	rsMain.AddField(_T("ObjectID"),VT_BSTR);//MaterialID

	//组建从表1数据集
	CL3RecordSet *pRSRtn1 = new CL3RecordSet();
	CL3RecordSetWrap rsMaterials1; pRSRtn1->QueryInterface(IID_IL3RecordSet,rsMaterials1); rsMaterials1->Release();
	rsMaterials1.AddField(_T("vinvbatchcode"),VT_BSTR);//批次号(*)
	rsMaterials1.AddField(_T("ccheckbill_b1id"),VT_BSTR);//质检单表体主键
	rsMaterials1.AddField(_T("dproducedate"),VT_BSTR);//生产日期(*)
	rsMaterials1.AddField(_T("cbaseid"),VT_BSTR);//检验产品(*)(从基本数据中的物料档案主键)
	rsMaterials1.AddField(_T("cchgbasid"),VT_BSTR);//改判后产品(*)(如果有改判,就要填写)
	rsMaterials1.AddField(_T("cchgassistunitid"),VT_BSTR);//改判辅计量单位id(*)
	rsMaterials1.AddField(_T("vdef1"),VT_BSTR);//自定义1
	rsMaterials1.AddField(_T("vdef2"),VT_BSTR);//自定义2
	rsMaterials1.AddField(_T("vdef3"),VT_BSTR);//自定义3
	rsMaterials1.AddField(_T("vdef4"),VT_BSTR);//自定义4
	rsMaterials1.AddField(_T("vdef5"),VT_BSTR);//自定义5
	rsMaterials1.AddField(_T("vfree1"),VT_BSTR);//自由项1(产品标准)(*)
	rsMaterials1.AddField(_T("vfree2"),VT_BSTR);//自由项2(技术要求)(*)
	rsMaterials1.AddField(_T("vfree3"),VT_BSTR);//自由项3
	rsMaterials1.AddField(_T("vfree4"),VT_BSTR);//自由项4
	rsMaterials1.AddField(_T("vfree5"),VT_BSTR);//自由项5
	rsMaterials1.AddField(_T("nnum"),VT_BSTR);//判定数量(*)
	rsMaterials1.AddField(_T("nassistnum"),VT_BSTR);//判定辅数量(*)
	rsMaterials1.AddField(_T("bcheckin"),VT_BSTR);//可否入库
	rsMaterials1.AddField(_T("bqualified"),VT_BSTR);//是否合格品
	rsMaterials1.AddField(_T("bchange"),VT_BSTR);//是否改判(*)(Y/N)
	rsMaterials1.AddField(_T("ccheckstatecode"),VT_BSTR);//质量等级编码
	rsMaterials1.AddField(_T("ccheckstatename"),VT_BSTR);//质量等级名称
	rsMaterials1.AddField(_T("vmemo"),VT_BSTR);//不合格说明
	rsMaterials1.AddField(_T("ccheckstate_bid"),VT_BSTR);//质量等级主键(*)(质量等级档案中ccheckstatecode第一位为4开头的)
	rsMaterials1.AddField(_T("ObjectID"),VT_BSTR);

	//组建从表2数据集
	CL3RecordSet *pRSRtn2 = new CL3RecordSet();
	CL3RecordSetWrap rsMaterials2; pRSRtn2->QueryInterface(IID_IL3RecordSet,rsMaterials2); rsMaterials2->Release();
	rsMaterials2.AddField(_T("cbaseid"),VT_BSTR);//检验产品
	rsMaterials2.AddField(_T("dcheckdate"),VT_BSTR);//检验日期(*)
	rsMaterials2.AddField(_T("vsamplecode"),VT_BSTR);//样本号(*)
	rsMaterials2.AddField(_T("nnum"),VT_R8);//检验数量
	rsMaterials2.AddField(_T("ccheckitemid"),VT_BSTR);//检验项目(*)
	rsMaterials2.AddField(_T("ccheckstandardid"),VT_BSTR);//检验标准主键(*)(在基础数据中检验标准中通过ccheckstandardname和ccheckitemid获取)
	rsMaterials2.AddField(_T("icheckstandard"),VT_BSTR);//检验标准类型
	rsMaterials2.AddField(_T("cresult"),VT_BSTR);//检验值(*)
	rsMaterials2.AddField(_T("ccheckerid"),VT_BSTR);//检验员(*)
	rsMaterials2.AddField(_T("ObjectID"),VT_BSTR);	

	//主表信息		
	CString csTempSQL1  = _T(" select heatid,flag,scddh,vprodserialnum,cpraydeptid,cprayerid,creporterid,dpraydate,sum(nchecknum) as nchecknum,ObjectID from ");
	csTempSQL1 += _T(" (select TAP_No as HeatID,'2' as Flag,TAP_No as scddh,TAP_No as vprodserialnum,'MES' as cpraydeptid,					");
	csTempSQL1 += _T(" Operator as cprayerid,Operator_B as creporterid,To_Char(Production_Date,'yyyy-mm-dd hh24:mi:ss')						");
	csTempSQL1 += _T(" as dpraydate,round(Net_Weight,3) as nchecknum,TAP_No as ObjectID from CBFIron	 where TAP_No = '%s'				");
	csTempSQL1 += _T(" ) group by heatid,flag,scddh,vprodserialnum,cpraydeptid,cprayerid,creporterid,dpraydate,ObjectID						");

	CString csSQL1;
	csSQL1.Format(csTempSQL1,strHeatID);
	CL3RecordSetWrap rsResult1;
	if(!Query(csSQL1,rsResult1))
		return NULL;
	rsMain.CopyFrom(rsResult1);

	//从表1信息		
	CString csTempSQL2  =_T(" select vinvbatchcode,objectid,dproducedate,cbaseid,sum(nnum) as nnum,bchange,ccheckstate_bid from									");
	csTempSQL2 +=_T(" (select TAP_No as vinvbatchcode,TAP_No as ObjectID,To_Char(Production_Date,'yyyy-mm-dd') as dproducedate,'CHDA0000000000009282'	"); 
	csTempSQL2 +=_T(" as cbaseid,round(Net_Weight,3) as nnum,'N' as bchange,'1001NC100000000052Z0' as ccheckstate_bid from CBFIron where TAP_No = '%s'	");
	csTempSQL2 +=_T(" ) group by vinvbatchcode,objectid,dproducedate,cbaseid,bchange,ccheckstate_bid");

	CString csSQL2;
	csSQL2.Format(csTempSQL2,strHeatID);
	CL3RecordSetWrap rsResult2;
	if(!Query(csSQL2,rsResult2))
		return NULL;
	rsMaterials1.CopyFrom(rsResult2);

	//从表2信息
	CString csTempSQL3  =_T("select to_char(a.Production_Date,'yyyy-mm-dd hh24:mi:ss') as finaljudgetime,a.* from CBFIron a where a.TAP_No = '%s'");
	CString csSQL3;
	csSQL3.Format(csTempSQL3,strHeatID);
	CL3RecordSetWrap rsResult3;
	if(!Query(csSQL3,rsResult3))
		return NULL;
	if(rsResult3.GetRowCount()<1)
		return NULL;
	//按照终盘视图里的元素位置定义与之相对应的NC检验编码静态数组
	/**********************************2012-04-26xiaocg  2012-08-13 hyh 新增十个元素应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)**********/
	//CString CheckItemID[6] = {_T("1001NC10000000004KXY")/*C*/,_T("1001NC10000000004KXU")/*Si*/,_T("1001NC10000000004KXW")/*Mn*/,_T("1001NC10000000004KX2")/*S*/,_T("1001NC10000000004KX3")/*P*/, _T("1001NC10000000004KYF")/*Ti*/}; 
	//CString CheckItemID[10] = {_T("1001NC10000000004KXY")/*C*/,_T("1001NC10000000004KXU")/*Si*/,_T("1001NC10000000004KXW")/*Mn*/,_T("1001NC10000000004KX2")/*S*/,_T("1001NC10000000004KX3")/*P*/, _T("1001NC10000000004KYF")/*Ti*/,
	//	_T("1001NC10000000004L2A")/*Sn*/,_T("1001NC10000000004L2W")/*Sb*/,_T("1001NC10000000004L29")/*As*/,_T("1001NC10000000004KYV")/*Pb*/}; 

	CString CheckItemID[20] = {_T("1001NC10000000004KXY")/*C*/,_T("1001NC10000000004KXU")/*Si*/,_T("1001NC10000000004KXW")/*Mn*/,_T("1001NC10000000004KX2")/*S*/,_T("1001NC10000000004KX3")/*P*/, 
		_T("1001NC10000000004KYF")/*Ti*/,_T("1001NC10000000004L2A")/*Sn*/,_T("1001NC10000000004L2W")/*Sb*/,_T("1001NC10000000004L29")/*As*/,_T("1001NC10000000004KYV")/*Pb*/,

		_T("1001NC10000000004L1A")/*Ni*/,_T("1001NC10000000004KY9")/*Mo*/,_T("1001NC10000000004KYZ")/*Cu*/,_T("1001NC10000000004KYE")/*Cr*/,_T("1001NC10000000004KYH")/*B*/,
		_T("1001NC10000000004KYB")/*V*/,_T("1001NC10000000004KY0")/*Al*/,_T("1001NC10000000004L2Z")/*Nb*/,_T("1001NC10000000004KYX")/*Zn*/,_T("1001NC10000000004L2B")/*W*/
	};
	/**********************************2012-04-26xiaocg********************************************************************************/
	rsMaterials2.MoveFirst();
	rsResult3.MoveFirst();
	/**********************************2012-04-26xiaocg********************************************************************************/
	//只有6个元素
	/*for(int i=0;i<6;i++)
	{
	rsMaterials2.AppendRecord();
	rsMaterials2.SetFieldByName(_T("dcheckdate"),rsResult3.GetFieldByName(_T("finaljudgetime")));
	rsMaterials2.SetFieldByName(_T("vsamplecode"),rsResult3.GetFieldByName(_T("SampCode")));			
	rsMaterials2.SetFieldByName(_T("ccheckerid"),rsResult3.GetFieldByName(_T("Operator_B")));
	rsMaterials2.SetFieldByName(_T("ObjectID"),CL3Variant(strHeatID));
	rsMaterials2.SetFieldByName(_T("ccheckitemid"),CL3Variant(CheckItemID[i]));
	rsMaterials2.SetFieldByName(_T("cresult"),rsResult3.GetFieldByIndex(40+i));
	}*/

	for(int i=0;i<20;i++)
	{
		rsMaterials2.AppendRecord();
		rsMaterials2.SetFieldByName(_T("dcheckdate"),rsResult3.GetFieldByName(_T("finaljudgetime")));
		rsMaterials2.SetFieldByName(_T("vsamplecode"),rsResult3.GetFieldByName(_T("SampCode")));			
		rsMaterials2.SetFieldByName(_T("ccheckerid"),rsResult3.GetFieldByName(_T("Operator_B")));
		rsMaterials2.SetFieldByName(_T("ObjectID"),CL3Variant(strHeatID));
		rsMaterials2.SetFieldByName(_T("ccheckitemid"),CL3Variant(CheckItemID[i]));
		if(i<6)
		{
			rsMaterials2.SetFieldByName(_T("cresult"),rsResult3.GetFieldByIndex(40+i));
			CString cs=rsResult3.GetFieldByIndex(40+i).ToCString();
		}
		else if(i<10)
		{
			rsMaterials2.SetFieldByName(_T("cresult"),rsResult3.GetFieldByIndex(50+i));
			CString cs=rsResult3.GetFieldByIndex(50+i).ToCString();
		}
		else
		{
			rsMaterials2.SetFieldByName(_T("cresult"),rsResult3.GetFieldByIndex(60+i));
			CString cs=rsResult3.GetFieldByIndex(60+i).ToCString();
		}
	}
	/**********************************2012-04-26xiaocg********************************************************************************/
	rsMaterials2.MoveFirst();
	while(!rsMaterials2.IsEOF())
	{
		if(rsMaterials2.GetFieldByName(_T("cresult")).ToCString() == _T(""))
			rsMaterials2.DeleteRecord();
		else
			rsMaterials2.MoveNext();
	}

	if (*rsMaterialsData1 != NULL)
		(*rsMaterialsData1)->Release();
	(*rsMaterialsData1) = rsMaterials1.Detach(); 
	if (*rsMaterialsData2 != NULL)
		(*rsMaterialsData2)->Release();
	(*rsMaterialsData2) = rsMaterials2.Detach(); 
	return rsMain.Detach();
}

/// <Method class="CBloom_Store_Mag" name="SendIronBloomInStoreInfor" type="L3LONG">
/// 2009-03-26 liuzhiqiang
/// 向NC补发铁水入库电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::SendIronBloomInStoreInfor(L3STRING strHeatID,L3RECORDSET *rsMainData)
{
	//组建主表数据集
	CL3RecordSet *pRSRtnMain = new CL3RecordSet();
	CL3RecordSetWrap rsMain; pRSRtnMain->QueryInterface(IID_IL3RecordSet,rsMain); pRSRtnMain->Release();
	rsMain.AddField(_T("HeatID"),VT_BSTR);
	rsMain.AddField(_T("Flag"),VT_BSTR);//1表示:钢 2表示:铁
	rsMain.AddField(_T("pch"),VT_BSTR);//铁次号
	rsMain.AddField(_T("cwarehouseid"),VT_BSTR);//入库仓库
	rsMain.AddField(_T("NC_Confirm_Flag"),VT_BSTR);//确认标志
	rsMain.AddField(_T("MaterialID"),VT_BSTR);//MaterialID
	rsMain.AddField(_T("ObjectID"),VT_BSTR);//MaterialID

	//组建从表数据集
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsMaterials; pRSRtn->QueryInterface(IID_IL3RecordSet,rsMaterials); rsMaterials->Release();
	rsMaterials.AddField(_T("cwarehouseid"),VT_BSTR);//入库仓库(*)
	rsMaterials.AddField(_T("taccounttime"),VT_BSTR);//库房签字时间(*)
	rsMaterials.AddField(_T("coperatorid"),VT_BSTR);//操作员编码(*)
	rsMaterials.AddField(_T("ccheckstate_bid"),VT_BSTR);//质量等级主键(*)(和质检相同)
	rsMaterials.AddField(_T("cworkcenterid"),VT_BSTR);//工作中心主键(*)(基础数据中工作中心档案获取)
	rsMaterials.AddField(_T("dbizdate"),VT_BSTR);//业务日期(*)
	rsMaterials.AddField(_T("vbatchcode"),VT_BSTR);//批次号(*)(废钢没有批次号)
	rsMaterials.AddField(_T("cinvbasid"),VT_BSTR);//入库存货(*)(从基本数据中的物料档案中获取)
	rsMaterials.AddField(_T("pk_produce"),VT_BSTR);//入库产品
	rsMaterials.AddField(_T("ninnum"),VT_R8);//入库数量(*)
	rsMaterials.AddField(_T("ninassistnum"),VT_R8);//入库辅数量(*)
	/****************************************************************/
	//2009-03-03 Modify by liuzhiqiang
	rsMaterials.AddField(_T("castunitid"),VT_BSTR);//辅计量单位id(*)(有就填写,没有不填写)
	/****************************************************************/
	rsMaterials.AddField(_T("vuserdef1"),VT_BSTR);//自定义1
	rsMaterials.AddField(_T("vuserdef2"),VT_BSTR);//自定义2
	rsMaterials.AddField(_T("vuserdef3"),VT_BSTR);//自定义3
	rsMaterials.AddField(_T("vuserdef4"),VT_BSTR);//自定义4
	rsMaterials.AddField(_T("vuserdef5"),VT_BSTR);//自定义5
	rsMaterials.AddField(_T("vuserdef6"),VT_BSTR);//自定义6
	rsMaterials.AddField(_T("vuserdef7"),VT_BSTR);//自定义7
	rsMaterials.AddField(_T("vuserdef8"),VT_BSTR);//自定义8
	rsMaterials.AddField(_T("vuserdef9"),VT_BSTR);//自定义9
	rsMaterials.AddField(_T("vuserdef10"),VT_BSTR);//自定义10
	rsMaterials.AddField(_T("vfree1"),VT_BSTR);//自由项1(产品标准)(*)
	rsMaterials.AddField(_T("vfree2"),VT_BSTR);//自由项2(技术要求)(*)
	rsMaterials.AddField(_T("vfree3"),VT_BSTR);//自由项3
	rsMaterials.AddField(_T("vfree4"),VT_BSTR);//自由项4
	rsMaterials.AddField(_T("vfree5"),VT_BSTR);//自由项5
	rsMaterials.AddField(_T("pk_corp"),VT_BSTR);//公司
	rsMaterials.AddField(_T("gcbm"),VT_BSTR);//工厂
	rsMaterials.AddField(_T("ObjectID"),VT_BSTR);//MaterialID

	CString csTempSQL = _T("select distinct DESTINATION from CBFIRON where TAP_No = '%s'");
	CString csSQL;
	csSQL.Format(csTempSQL,strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;
	if(rs.GetRowCount() > 1)
	{
		//Modify begin 2011-11-30 by llj 增加6号高炉处理其工作中心为1001NC100000002VLN77
		csTempSQL  = _T(" select TAP_No as HeatID,'2' as Flag,TAP_No as pch,TAP_No as vbatchcode,Operator as coperatorid,case when DESTINATION =1 then 'CKDA0000000000000026' else							");
		csTempSQL += _T(" '1006AA1000000007LBSO' end as cwarehouseid,to_char(Production_Date,'yyyy-mm-dd hh24:mi:ss') as																					");													
		csTempSQL += _T(" taccounttime, case when BFID ='1' then '1001NC100000000036ZH' when BFID ='2' then '1001NC100000000036ZI' when BFID ='3' then '1001NC100000000036ZJ' when							");											
		csTempSQL += _T(" BFID ='4' then '1001NC100000000036ZK' when BFID ='5' then '1001NC100000000036ZL' when BFID ='6' then '1001NC100000002VLN77' else BFID end as cworkcenterid,to_char(Production_Date,'yyyy-mm-dd') as dbizdate,				");										
		csTempSQL += _T(" round(Net_Weight,3) as ninnum,'1001NC100000000052Z0' as ccheckstate_bid,'CHDA0000000000009282' as cinvbasid from CBFIron where TAP_No = '%s'										");
		//Modify end by llj

		csSQL.Format(csTempSQL,strHeatID);
		CL3RecordSetWrap rsResult1;
		if(!Query(csSQL,rsResult1))
			return NULL;
		rsResult1.MoveFirst();
		rsMain.AppendRecord();
		rsMain.CopyCurRowFrom(rsResult1);
		rsMaterials.CopyFrom(rsResult1);
	}
	else
	{
		//Modify begin 2011-11-30 by llj 增加6号高炉铁水处理其工作中心为1001NC100000002VLN77
		csTempSQL  = _T(" select HeatID,Flag,pch,vbatchcode,coperatorid,cwarehouseid,taccounttime,cworkcenterid,taccounttime, cworkcenterid,dbizdate,sum(ninnum) as ninnum,ccheckstate_bid,cinvbasid from	");
		csTempSQL += _T(" (select TAP_No as HeatID,'2' as Flag,TAP_No as pch,TAP_No as vbatchcode,Operator as coperatorid,case when DESTINATION =1 then 'CKDA0000000000000026' else							");
		csTempSQL += _T(" '1006AA1000000007LBSO' end as cwarehouseid,to_char(Production_Date,'yyyy-mm-dd hh24:mi:ss') as																					");													
		csTempSQL += _T(" taccounttime, case when BFID ='1' then '1001NC100000000036ZH' when BFID ='2' then '1001NC100000000036ZI' when BFID ='3' then '1001NC100000000036ZJ' when							");											
		csTempSQL += _T(" BFID ='4' then '1001NC100000000036ZK' when BFID ='5' then '1001NC100000000036ZL' when BFID ='6' then '1001NC100000002VLN77' else BFID end as cworkcenterid,to_char(Production_Date,'yyyy-mm-dd') as dbizdate,				");										
		csTempSQL += _T(" round(Net_Weight,3) as ninnum,'1001NC100000000052Z0' as ccheckstate_bid,'CHDA0000000000009282' as cinvbasid from CBFIron where TAP_No = '%s'										");
		csTempSQL += _T(" ) group by HeatID,Flag,pch,vbatchcode,coperatorid,cwarehouseid,taccounttime,cworkcenterid,taccounttime, cworkcenterid,dbizdate,ccheckstate_bid,cinvbasid							");	

		//Modify end by llj
		csSQL.Format(csTempSQL,strHeatID);
		CL3RecordSetWrap rsResult1;
		if(!Query(csSQL,rsResult1))
			return NULL;
		rsResult1.MoveFirst();
		rsMain.AppendRecord();
		rsMain.CopyCurRowFrom(rsResult1);
		rsMaterials.CopyFrom(rsResult1);
	}

	if (*rsMainData != NULL)
		(*rsMainData)->Release();
	(*rsMainData) = rsMain.Detach(); 
	return rsMaterials.Detach();
}

/// <Method class="CBaseData_Mag" name="GetPlanOrder" type="L3LONG">
/// 2009-02-21
/// 向NC发送生产计划电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::GetPlanOrder()
{
	CString csTemp = _T(" select PlanID,HeatID,NC_Confirm_Flag from CPlan_Tapping where  NC_Confirm_Flag = 0   and  Caster_Status ='%s' ");
	CString csSQL;
	csSQL.Format(csTemp,TAPPING_PLAN_CCM_STATUS_END);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return NULL;
	return rs.Detach();
}

/// <Method class="CBaseData_Mag" name="ConfirmPlanOrder" type="L3LONG">
/// 
/// NC确认生产订单
/// RET &lt;&lt;成功返回1，失败返回0
/// </Method>
L3BOOL CBaseData_Mag::ConfirmPlanOrder(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	if(!SetObjsPropValues(PLAN_TAPPING_CLASS_URI,rs))
		return false;
	return true;
}

/// <Method class="CBloom_Store_Mag" name="GetInStore" type="L3LONG">
/// 
/// 向NC发送钢坯入库电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::GetInStore()
{
	CString csSQL = _T(" select HeatID,NC_Confirm_Flag,TreatNo from  CCCM_Base_Data  where NC_Confirm_Flag = 0 and  HeatConfirm = 1 ");
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return NULL;
	return rs.Detach();
}

/// <Method class="CBaseData_Mag" name="ConfirmInStore" type="L3LONG">
/// 
/// NC确认钢坯入库
/// RET &lt;&lt;成功返回1，失败返回0
/// </Method>
L3BOOL CBaseData_Mag::ConfirmInStore(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	rs.MoveFirst();
	if(!SetObjsPropValues(CCM_BASE_DATA_CLASS_URI,rs))
		return false;
	return true;
}

/// <Method class="CBaseData_Mag" name="GetIron" type="L3LONG">
/// 2009-02-22
/// 向NC发送铁水终判质量电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::GetIron()
{
	//按照炉号和时间找出每炉最后一条信息
	CString csSQL  = _T(" select distinct TAP_No as HeatID from CBFIron where NC_Confirm_Flag = '0' and IronConfirm ='1' ");

	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return NULL;
	return rs.Detach();
}

/// <Method class="CBaseData_Mag" name="ConfirmIron" type="L3LONG">
/// 
/// NC确认铁水入库
/// RET &lt;&lt;成功返回1，失败返回0
/// </Method>
L3BOOL CBaseData_Mag::ConfirmIron(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csHeatID = rs.GetFieldByName(_T("HeatID")).ToCString();
		CString csTempSQL  = _T(" select * from CBFIron where TAP_No = '%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult))
			return NULL;
		rsResult.MoveFirst();
		while(!rsResult.IsEOF())
		{
			rsResult.SetFieldByName(_T("NC_Confirm_Flag"),CL3Variant(LONG(1)));
			rsResult.MoveNext();
		}
		rsResult.MoveFirst();
		SetObjsPropValues(MATERIAL_BFIRON_URI,rsResult);
		rs.MoveNext();
	}
	return true;
}

/// <Method class="CBaseData_Mag" name="GetIron" type="L3LONG">
/// 2009-02-22
/// 向NC发送库内终判质量电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::GetInStoreQuality()
{
	//按照炉号和时间找出每炉最后一条信息
	CString csSQL  = _T(" select GUID,HeatID,NC_Confirm_Flag from CQA_Bloom_FinJudge_Data where NC_Confirm_Flag = '0' and Store_ChangeJudge_Flag ='1' ");

	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return NULL;
	return rs.Detach();
}

/// <Method class="CBaseData_Mag" name="ConfirmIron" type="L3LONG">
/// 
/// NC确认库内改判
/// RET &lt;&lt;成功返回1，失败返回0
/// </Method>
L3BOOL CBaseData_Mag::ConfirmInStoreQuality(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	rs.MoveFirst();
	if(!SetObjsPropValues(QA_FIN_JUDGE_CLASS_URI,rs))
		return false;
	return true;
}


/// <Method class="CBaseData_Mag" name="ConfirmIron" type="L3LONG">
/// 
/// 测试存储过程
/// RET &lt;&lt;成功返回1，失败返回0
/// </Method>
L3BOOL CBaseData_Mag::TestOracleProcess(L3STRING strHeatID)
{
	CString csHeatID = strHeatID;
	CString csTemp = _T(" call PROC_TR_LF_CURHEAT_ORIGINDATA('%s')");
	CString csSQL;
	csSQL.Format(csTemp,csHeatID);
	CL3RecordSetWrap rs;
	Query(csSQL,rs);
	return true;
}

/// <Method class="CBloom_Store_Mag" name="GetInStore" type="L3LONG">
/// 2009-04-04 liuzhiqiang
/// 向NC发送全回炉电文
/// RET &lt;&lt;成功返回1，失败返回NULL
/// </Method>
L3RECORDSET CBaseData_Mag::GetAllReturn()
{
	CString csSQL  = _T(" select GUID,HeatID,NC_Confirm_Flag from CDISP_STEELTURN_APP where NC_Confirm_Flag = '0' and ALL_TURN_FLAG ='1' ");

	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs) || rs.IsNull() || rs.GetRowCount() < 1)
		return NULL;
	return rs.Detach();
}

/// <Method class="CBaseData_Mag" name="ConfirmInStore" type="L3LONG">
/// 2009-04-04 liuzhiqiang
/// NC确认全回炉
/// RET &lt;&lt;成功返回1，失败返回0
/// </Method>
L3BOOL CBaseData_Mag::ConfirmAllReturn(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	rs.MoveFirst();
	if(!SetObjsPropValues(DISPATCH_STEEL_TURN_CLASS_URI,rs))
		return false;
	return true;
}
//2009-04-17 Liao
/// <Method class="CBaseData_Mag" name="Add_Mat_Price" type="L3LONG">
/// 添加物料价格库信息
/// <Param name="dsInfo" type="L3RECORDSET">物料信息</Param>
/// </Method>
L3LONG CBaseData_Mag::Add_Mat_Price(L3RECORDSET dsInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsInfo;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1 ;

	if(rsData.GetFieldIndex(_T("Work_Year")) < 0 || rsData.GetFieldIndex(_T("Material_Code")) < 0)
		return -2;//没有年份或物料编码

	//如果没有传入关键字
	if(rsData.GetFieldIndex(_T("Object_ID")) < 0)
		rsData.AddField(_T("Object_ID"),VT_BSTR);

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csWorkYear = rsData.GetFieldByName(_T("Work_Year")).ToCString();
		CString csMatCode = rsData.GetFieldByName(_T("Material_Code")).ToCString();
		if(csWorkYear == _T("") || csMatCode == _T(""))
			return -3;//新增记录没有输入年份或物料编码
		CString csObjectID = csWorkYear + csMatCode;
		rsData.SetFieldByName(_T("Object_ID"),CL3Variant(csObjectID));

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
	if(CreateNewObjects(CMATERIAL_PRICE_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CBaseData_Mag" name="Modify_Mat_Price" type="L3LONG">
/// 修改物料价格库信息
/// <Param name="dsInfo" type="L3RECORDSET">修改信息</Param>
/// </Method>
L3LONG CBaseData_Mag::Modify_Mat_Price(L3RECORDSET dsInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsInfo;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1 ;
	if(rsData.GetFieldIndex(_T("Object_ID")) < 0)
		return -2;//没有关键字

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	rsData.MoveFirst();
	if(!SetObjsPropValues(CMATERIAL_PRICE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CBaseData_Mag" name="Delete_Mat_Price" type="L3LONG">
/// 删除物料价格库信息
/// <Param name="dsInfo" type="L3RECORDSET">删除信息</Param>
/// </Method>
L3LONG CBaseData_Mag::Delete_Mat_Price(L3RECORDSET dsInfo)
{
	// TODO : 请在此添加逻辑代码
	CL3RecordSetWrap rsData = dsInfo;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1 ;
	if(rsData.GetFieldIndex(_T("Object_ID")) < 0)
		return -2;//没有关键字

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	rsData.MoveFirst();
	if(!DeleteOldObjects(CMATERIAL_PRICE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CBaseData_Mag" name="Get_Materia_Price" type="L3RECORDSET">
/// 获取物料价格信息
/// <Param name="strCondition" type="L3STRING">查询条件</Param>
/// </Method>
L3RECORDSET CBaseData_Mag::Get_Materia_Price(L3STRING strCondition)
{
	// TODO : 请在此添加逻辑代码
	CString csCondition = strCondition;
	if(csCondition == _T(""))
		return NULL;

	CString csTemp = _T(" Select * from %s where %s");
	CString csSQL;
	csSQL.Format(csTemp,CMATERIAL_PRICE_URI,csCondition);
	CL3RecordSetWrap rsReasult;
	if(!Query(csSQL,rsReasult) || rsReasult.IsNull())
		return NULL;

	return rsReasult.Detach();
}

/// <Method class="CBaseData_Mag" name="InsertBaseParameter" type="L3LONG">
/// 插入数据到指定的基类中
/// ARG >> strClassNameURI: 基类名
///		   rsParam： 数据集
/// RET << 成功返回1；否则返回非1
/// <Param name="strClassNam" type="L3STRING"></Param>
/// <Param name="rsParam" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBaseData_Mag::InsertBaseParameter(L3STRING strClassNameURI, L3RECORDSET rsParam)
{
	// TODO : 请在此添加逻辑代码
	CString csClassNameURI = strClassNameURI;
	csClassNameURI = csClassNameURI.Trim();
	if(csClassNameURI == _T(""))
		return -1;

	CL3RecordSetWrap pRs = rsParam;
	if(pRs.IsNull() || pRs.GetRowCount()<1)
		return -1;

	if(CreateNewObjects(csClassNameURI,pRs)<1)
		return -1;

	return 0;
}


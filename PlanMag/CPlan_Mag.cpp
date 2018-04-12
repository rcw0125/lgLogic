// 逻辑类CPlan_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CPlan_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CPlan_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CPlan_Mag.h"

//当对象被装载到系统中时，被调用
void CPlan_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}


//当对象被卸载时，被调用
void CPlan_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <Method class="CPlan_Mag" name="PlanOrdRec" type="L3BOOL">
/// 
/// 接收EXCEL导入计划订单，判断计划订单的状态如果大于2则退出。新增计划订单状态为0未确认
/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsPlan" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CPlan_Mag::PlanOrdRec(L3RECORDSET rsPlan)
{
	CL3RecordSetWrap rsData =rsPlan;
    if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return false;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsPlanOrder;
	if(!CreateClassPropSet(PLAN_ORDER_CLASS_URI,rsPlanOrder))
		return false;


	CString csChar = _T("×");


	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{	
		//计划重量不能为空
		CL3Variant vsPlanWeight = rsData.GetFieldByName(_T("Jhwgsl"));
		if(!vsPlanWeight.IsValid() || vsPlanWeight.IsError() || vsPlanWeight.IsNull())
		{
			rsData.MoveNext();
			continue;
		}
		//物料编码不能为空
		CL3Variant vsMaterialCode = rsData.GetFieldByName(_T("Invcode"));
		if(!vsMaterialCode.IsValid() || vsMaterialCode.IsError() || vsMaterialCode.IsNull())
		{
			rsData.MoveNext();
			continue;
		}
		//钢种不能为空
		CL3Variant vsSteelGrade = rsData.GetFieldByName(_T("Invtype"));
		if(!vsSteelGrade.IsValid() || vsSteelGrade.IsError() || vsSteelGrade.IsNull())
		{
			rsData.MoveNext();
			continue;
		}
		//工艺路径不能为空
		CL3Variant vsRoute = rsData.GetFieldByName(_T("zdy3"));
		//if(!vsRoute.IsValid() || vsRoute.IsError() || vsRoute.IsNull())
		//{
		//	rsData.MoveNext();
		//	continue;
		//}
		rsPlanOrder.AppendRecord();
		rsPlanOrder.SetFieldByName(_T("PlanID"),rsData.GetFieldByName(_T("Jhddh")));
		rsPlanOrder.SetFieldByName(_T("ContractID"),rsData.GetFieldByName(_T("Xsddh")));
		rsPlanOrder.SetFieldByName(_T("Unit"),CL3Variant(_T("吨")));
		rsPlanOrder.SetFieldByName(_T("Assist_Unit"),rsData.GetFieldByName(_T("Fjlid")));
		rsPlanOrder.SetFieldByName(_T("Weight"),vsPlanWeight);
		rsPlanOrder.SetFieldByName(_T("SpareWeight"),vsPlanWeight);
		rsPlanOrder.SetFieldByName(_T("ActWeight"),CL3Variant(0));
		rsPlanOrder.SetFieldByName(_T("Assisi_Weight"),rsData.GetFieldByName(_T("Fjhsl")));
		rsPlanOrder.SetFieldByName(_T("PlanRec_Date"),timeNow);
		rsPlanOrder.SetFieldByName(_T("Request_Date"),rsData.GetFieldByName(_T("Xqrq")));
		rsPlanOrder.SetFieldByName(_T("CreateDate"),rsData.GetFieldByName(_T("Jhksrq")));
		rsPlanOrder.SetFieldByName(_T("Corp"),rsData.GetFieldByName(_T("pk_corp")));
		rsPlanOrder.SetFieldByName(_T("Factory"),rsData.GetFieldByName(_T("Gcbm")));
		rsPlanOrder.SetFieldByName(_T("Work_Center"),rsData.GetFieldByName(_T("Gzzxbm")));
		rsPlanOrder.SetFieldByName(_T("ExecuteDept"),rsData.GetFieldByName(_T("Scbmbm")));
		rsPlanOrder.SetFieldByName(_T("Client"),rsData.GetFieldByName(_T("Ksid")));

		//2009-01-15tangyi钢种都去掉规格标示增加物料编码
		rsPlanOrder.SetFieldByName(_T("MaterialCode"),vsMaterialCode);
		rsPlanOrder.SetFieldByName(_T("MaterialCode_ID"),rsData.GetFieldByName(_T("pk_invbasdoc")));//2009-03-11
		rsPlanOrder.SetFieldByName(_T("Product_Route"),vsRoute);//2009-03-11 工艺路径
		rsPlanOrder.SetFieldByName(_T("Other_Tech_Request"),rsData.GetFieldByName(_T("zdy2")));//2009-03-27 其他技术要求
		
		rsPlanOrder.SetFieldByName(_T("SteelGrade"),vsSteelGrade);
		
		rsPlanOrder.SetFieldByName(_T("ProduceStd"),rsData.GetFieldByName(_T("zyx1")));//制造标准
		rsPlanOrder.SetFieldByName(_T("Tech_Request"),rsData.GetFieldByName(_T("zyx2")));//技术要求
		CString csTechRequest = rsData.GetFieldByName(_T("zyx2")).ToCString();
		CString csProduceStd = rsData.GetFieldByName(_T("zyx1")).ToCString();
		csTechRequest.Trim();
		csProduceStd.Trim();
		L3LONG nPos =0;
		if(!csTechRequest.IsEmpty())
		{
			nPos = csTechRequest.Find(_T("~")) + 1;
			CString csTech = csTechRequest.Mid(nPos,(csTechRequest.GetLength() - nPos));
			if(csTech !=_T("普通要求"))
				rsPlanOrder.SetFieldByName(_T("Protocol"),CL3Variant(csTech));//MES系统排产协议
			else
			{
				nPos = csProduceStd.Find(_T("~")) + 1;
				CString csProdstd = csProduceStd.Mid(nPos,(csProduceStd.GetLength() - nPos));
				rsPlanOrder.SetFieldByName(_T("Protocol"),CL3Variant(csProdstd));//MES系统排产协议
			}
		}
		else
		{
				nPos = csProduceStd.Find(_T("~")) + 1;
				CString csProdstd = csProduceStd.Mid(nPos,(csProduceStd.GetLength() - nPos));
				rsPlanOrder.SetFieldByName(_T("Protocol"),CL3Variant(csProdstd));//MES系统排产协议
		}
		
		rsPlanOrder.SetFieldByName(_T("Inside_Note"),rsData.GetFieldByName(_T("zdy4")));//内部指示
		rsPlanOrder.SetFieldByName(_T("Imm_Flag"),rsData.GetFieldByName(_T("Sfjj")));		
		rsPlanOrder.SetFieldByName(_T("pk_poid"),rsData.GetFieldByName(_T("pk_poid")));
		
		
		CString csSpeci  = rsData.GetFieldByName(_T("Invspec")).ToCString();
		csSpeci.Trim();
		if(!csSpeci.IsEmpty())
		{
			CString csThickness = csSpeci.Mid(0,3);
			L3LONG nThickness = _ttol(csThickness);
			rsPlanOrder.SetFieldByName(_T("Thickness"),CL3Variant(nThickness));

			//CString csWidth = csSpeci.Mid(4,3);
			CString csWidth = csSpeci.Mid(6,3);
			L3LONG nWidth = _ttol(csWidth);
			rsPlanOrder.SetFieldByName(_T("Width"),CL3Variant(nWidth));

			//CString csLength = csSpeci.Mid(8,(csSpeci.GetLength()-8));
			CString csLength = csSpeci.Mid(12,(csSpeci.GetLength()-13));
			L3LONG nLength = _tstof(csLength) * 1000;
			rsPlanOrder.SetFieldByName(_T("Length"),CL3Variant(nLength));
		}	
		rsPlanOrder.SetFieldByName(_T("Status"),CL3Variant(PLAN_ORDER_STATUS_UNINTEGRATE));
		rsData.MoveNext();
	}

	rsPlanOrder.MoveFirst();
	CreateNewObjects(PLAN_ORDER_CLASS_URI,rsPlanOrder);

	return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="PlanOrdRec" type="L3BOOL">
/// 
/// 接收计划订单，判断计划订单的状态如果大于2则退出。新增计划订单状态为0未确认
/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsPlan" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CPlan_Mag::PlanOrdRecFormNC(L3RECORDSET rsPlan)
{
	CL3RecordSetWrap rsData =rsPlan;
    if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return false;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	CL3RecordSetWrap rsPlanOrderTel;
	if(!CreateClassPropSet(_T("XGMESLogic\\PlanMag\\CPlan_Order_Tel_Data"),rsPlanOrderTel))
		return false;
	rsPlanOrderTel.DelField(_T("GUID"));
	rsPlanOrderTel.AddField(_T("PlanRec_Date"),VT_DATE);
	rsPlanOrderTel.CopyFrom(rsData);
	rsPlanOrderTel.MoveFirst();
	while(!rsPlanOrderTel.IsEOF())
	{
		rsPlanOrderTel.SetFieldByName(_T("PlanRec_Date"),timeNow);
		rsPlanOrderTel.MoveNext();
	}

	if(CreateNewObjects(_T("XGMESLogic\\PlanMag\\CPlan_Order_Tel_Data"),rsPlanOrderTel) < rsPlanOrderTel.GetRowCount())
		return false;

	CL3RecordSetWrap rsPlanOrder;
	if(!CreateClassPropSet(PLAN_ORDER_CLASS_URI,rsPlanOrder))
		return false;


	CString csChar = _T("×");


	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{	
		//计划重量不能为空
		CL3Variant vsPlanWeight = rsData.GetFieldByName(_T("xqsl"));
		if(!vsPlanWeight.IsValid() || vsPlanWeight.IsError() || vsPlanWeight.IsNull())
		{
			rsData.MoveNext();
			continue;
		}
		//物料编码不能为空
		CL3Variant vsMaterialCode = rsData.GetFieldByName(_T("wlbm"));
		if(!vsMaterialCode.IsValid() || vsMaterialCode.IsError() || vsMaterialCode.IsNull())
		{
			rsData.MoveNext();
			continue;
		}
		//钢种不能为空
		CL3Variant vsSteelGrade = rsData.GetFieldByName(_T("Invtype"));
		if(!vsSteelGrade.IsValid() || vsSteelGrade.IsError() || vsSteelGrade.IsNull())
		{
			rsData.MoveNext();
			continue;
		}	
		//工艺路径不能为空
		CL3Variant vsRoute = rsData.GetFieldByName(_T("zdy3"));
		if(!vsRoute.IsValid() || vsRoute.IsError() || vsRoute.IsNull())
		{
			rsData.MoveNext();
			continue;
		}

		rsPlanOrder.AppendRecord();
		rsPlanOrder.SetFieldByName(_T("PlanID"),rsData.GetFieldByName(_T("Jhddh")));
		rsPlanOrder.SetFieldByName(_T("ContractID"),rsData.GetFieldByName(_T("Xsddh")));
		//rsPlanOrder.SetFieldByName(_T("Unit"),rsData.GetFieldByName(_T("Jldwmc")));
		rsPlanOrder.SetFieldByName(_T("Unit"),CL3Variant(_T("吨")));
		rsPlanOrder.SetFieldByName(_T("Assist_Unit"),rsData.GetFieldByName(_T("fjldwid")));
		rsPlanOrder.SetFieldByName(_T("Weight"),vsPlanWeight);
		rsPlanOrder.SetFieldByName(_T("SpareWeight"),vsPlanWeight);
		rsPlanOrder.SetFieldByName(_T("ActWeight"),CL3Variant(0));
		rsPlanOrder.SetFieldByName(_T("Assisi_Weight"),rsData.GetFieldByName(_T("xqfsl")));
		rsPlanOrder.SetFieldByName(_T("PlanRec_Date"),timeNow);
		rsPlanOrder.SetFieldByName(_T("Request_Date"),rsData.GetFieldByName(_T("Xqrq")));
		rsPlanOrder.SetFieldByName(_T("CreateDate"),rsData.GetFieldByName(_T("jhrq")));
		rsPlanOrder.SetFieldByName(_T("Corp"),rsData.GetFieldByName(_T("pk_corp")));
		rsPlanOrder.SetFieldByName(_T("Factory"),rsData.GetFieldByName(_T("Gcbm")));
		rsPlanOrder.SetFieldByName(_T("Work_Center"),rsData.GetFieldByName(_T("Gzzxbm")));
		rsPlanOrder.SetFieldByName(_T("ExecuteDept"),rsData.GetFieldByName(_T("Scbmbm")));
		rsPlanOrder.SetFieldByName(_T("Client"),rsData.GetFieldByName(_T("Ksid")));

		//2009-01-15tangyi钢种都去掉规格标示增加物料编码
		rsPlanOrder.SetFieldByName(_T("MaterialCode"),vsMaterialCode);
		rsPlanOrder.SetFieldByName(_T("MaterialCode_ID"),rsData.GetFieldByName(_T("wlbmID")));//2009-03-11 物料编码ID主键
		rsPlanOrder.SetFieldByName(_T("Product_Route"),vsRoute);//2009-03-11 工艺路径
		rsPlanOrder.SetFieldByName(_T("Other_Tech_Request"),rsData.GetFieldByName(_T("zdy2")));//2009-03-27 其他技术要求
		rsPlanOrder.SetFieldByName(_T("Inside_Note"),rsData.GetFieldByName(_T("zdy4")));//内部指示
		
		rsPlanOrder.SetFieldByName(_T("SteelGrade"),vsSteelGrade);
		
		rsPlanOrder.SetFieldByName(_T("ProduceStd"),rsData.GetFieldByName(_T("zyx1")));//制造标准
		rsPlanOrder.SetFieldByName(_T("Tech_Request"),rsData.GetFieldByName(_T("zyx2")));//技术要求
		CString csTechRequest = rsData.GetFieldByName(_T("zyx2")).ToCString();
		CString csProduceStd = rsData.GetFieldByName(_T("zyx1")).ToCString();
		csTechRequest.Trim();
		csProduceStd.Trim();
		L3LONG nPos =0;
		if(!csTechRequest.IsEmpty())
		{
			nPos = csTechRequest.Find(_T("~")) + 1;
			CString csTech = csTechRequest.Mid(nPos,(csTechRequest.GetLength() - nPos));
			if(csTech !=_T("普通要求"))
				rsPlanOrder.SetFieldByName(_T("Protocol"),CL3Variant(csTech));//MES系统排产协议
			else
			{
				nPos = csProduceStd.Find(_T("~")) + 1;
				CString csProdstd = csProduceStd.Mid(nPos,(csProduceStd.GetLength() - nPos));
				rsPlanOrder.SetFieldByName(_T("Protocol"),CL3Variant(csProdstd));//MES系统排产协议
			}
		}
		else
		{
				nPos = csProduceStd.Find(_T("~")) + 1;
				CString csProdstd = csProduceStd.Mid(nPos,(csProduceStd.GetLength() - nPos));
				rsPlanOrder.SetFieldByName(_T("Protocol"),CL3Variant(csProdstd));//MES系统排产协议
		}
		
		rsPlanOrder.SetFieldByName(_T("Imm_Flag"),rsData.GetFieldByName(_T("Sfjj")));		
		rsPlanOrder.SetFieldByName(_T("pk_poid"),rsData.GetFieldByName(_T("pk_poid")));
		
		
		CString csSpeci  = rsData.GetFieldByName(_T("Invspec")).ToCString();
		csSpeci.Trim();
		if(!csSpeci.IsEmpty())
		{
			CString csThickness = csSpeci.Mid(0,3);
			L3LONG nThickness = _ttol(csThickness);
			rsPlanOrder.SetFieldByName(_T("Thickness"),CL3Variant(nThickness));

			//CString csWidth = csSpeci.Mid(4,3);
			CString csWidth = csSpeci.Mid(6,3);
			L3LONG nWidth = _ttol(csWidth);
			rsPlanOrder.SetFieldByName(_T("Width"),CL3Variant(nWidth));

			//CString csLength = csSpeci.Mid(8,(csSpeci.GetLength()-8));
			CString csLength = csSpeci.Mid(12,(csSpeci.GetLength()-13));
			L3LONG nLength = _tstof(csLength) * 1000;
			rsPlanOrder.SetFieldByName(_T("Length"),CL3Variant(nLength));
		}	

		
		rsPlanOrder.SetFieldByName(_T("Status"),CL3Variant(PLAN_ORDER_STATUS_UNINTEGRATE));
		
		rsData.MoveNext();
	}


	rsPlanOrder.MoveFirst();
	CreateNewObjects(PLAN_ORDER_CLASS_URI,rsPlanOrder);

	return true;// TODO : 请在此添加逻辑代码
}



/// <Method class="CPlan_Mag" name="PlanOrdCfm" type="L3BOOL">
/// 
/// 删除计划订单2009-01-10 tangyi
/// <Param name="rsPlan" type="L3RECORDSET">计划订单信息</Param>
/// </Method>
L3BOOL CPlan_Mag::DelPlanOrder(L3RECORDSET rsPlan)
{
	CL3RecordSetWrap rsPlanOrd =rsPlan;
    if( rsPlanOrd.IsNull() || rsPlanOrd.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	rsPlanOrd.MoveFirst();
	L3LONG nCount =0;
	while(!rsPlanOrd.IsEOF())
	{
		CL3Variant vaTemp = rsPlanOrd.GetFieldByName(_T("ActWeight"));
		L3DOUBLE nActWeight = vaTemp.ToDouble();
		vaTemp = rsPlanOrd.GetFieldByName(_T("PlanID"));
		CString csPlanID = vaTemp.ToCString();
		if(nActWeight > 0)
		{
			rsPlanOrd.MoveNext();
			continue;
		}
		if(!DeleteOldObject(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;				
		}
		nCount++;
		rsPlanOrd.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);

	if(nCount == 0)
		return false;
	else
		return true;	// TODO : 请在此添加逻辑代码
}


/// <Method class="CPlan_Mag" name="PlanOrdCfm" type="L3BOOL">
/// 
/// 关闭计划订单2009-04-19 tangyi
/// <Param name="rsPlan" type="L3RECORDSET">计划订单信息</Param>
/// </Method>
L3BOOL CPlan_Mag::EndPlanOrder(L3RECORDSET rsPlan)
{
	CL3RecordSetWrap rsPlanOrd =rsPlan;
    if( rsPlanOrd.IsNull() || rsPlanOrd.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	rsPlanOrd.MoveFirst();
	L3LONG nCount =0;
	while(!rsPlanOrd.IsEOF())
	{
		CL3Variant vaTemp = rsPlanOrd.GetFieldByName(_T("PlanID"));
		CString csPlanID = vaTemp.ToCString();
		CString csPlanUri = PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID;
		if(!SetObjectPropValue(csPlanUri,_T("SpareWeight"),L3DOUBLE(0)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;				
		}
		if(!SetObjectPropValue(csPlanUri,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_EXCUTED)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;				
		}
		nCount++;
		rsPlanOrd.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);

	if(nCount == 0)
		return false;
	else
		return true;	// TODO : 请在此添加逻辑代码
}


/// <Method class="CPlan_Mag" name="PlanOrdCfm" type="L3BOOL">
/// 
/// 计划订单确认，更改订单的状态为1未收池
/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsPlan" type="L3RECORDSET">计划订单信息</Param>
/// </Method>
L3BOOL CPlan_Mag::PlanOrdCfm(L3RECORDSET rsPlan)
{
	CL3RecordSetWrap rsPlanOrd =rsPlan;
    if( rsPlanOrd.IsNull() || rsPlanOrd.GetRowCount() < 1)
		return true;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	rsPlanOrd.MoveFirst();
	while(!rsPlanOrd.IsEOF())
	{
		CL3Variant vaTemp = rsPlanOrd.GetFieldByName(_T("PlanID"));
		CString csPlanID = vaTemp.ToCString();
		if(!SetObjectPropValue(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_UNINTEGRATE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;				
		}
		rsPlanOrd.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);

	return true;	// TODO : 请在此添加逻辑代码
}
/// <Method class="CPlan_Mag" name="GetUnConfirmPlanOrder" type="L3RECORDSET">
/// 
/// 获取未确认计划订单
/// ARG &gt;&gt; 
/// RET &gt;&gt; 找到的计划记录集。
/// <Param name="Condition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CPlan_Mag::GetUnConfirmPlanOrder()
{
	//2008-12-23 tangyi 屏蔽
	//CString csTemp = _T(" SELECT *  FROM %s  where Status = %s  order by PlanRec_Date desc,PlanID asc");	
	//CString strSQL;
	//strSQL.Format(csTemp,PLAN_ORDER_CLASS_URI,PLAN_ORDER_STATUS_UNCONFIRM);
	//CL3RecordSetWrap rsResult;
	//BOOL bRet = Query(strSQL,rsResult);
	//if(!bRet)
		return NULL;
	//else
	//	return rsResult.Detach();
}
/// <Method class="CPlan_Mag" name="GetUnIntegratePlanOrd" type="L3RECORDSET">
/// 
/// 按照日期获取未收池计划订单
/// ARG &gt;&gt; Condition : 收池条件。
/// RET &gt;&gt; 找到的计划记录集。
/// <Param name="Condition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CPlan_Mag::GetUnIntegratePlanOrd(L3STRING strDate)
{
	CString csTemp = _T(" SELECT a.*,a.Thickness || '*' || Width || '*' || Length as Std                          ");
			csTemp+= _T(" FROM %s a where to_Char(a.CreateDate,'yyyy-mm-dd') = '%s' and a.Status = %s             ");
			csTemp+= _T(" order by a.SteelGrade,a.Thickness,a.Width,a.Length                                      ");	
	CString csDate = strDate;
	CString strSQL;
	strSQL.Format(csTemp,PLAN_ORDER_CLASS_URI,csDate,PLAN_ORDER_STATUS_UNINTEGRATE);
	CL3RecordSetWrap rsResult;
	BOOL bRet = Query(strSQL,rsResult);
	if(!bRet)
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CPlan_Mag" name="GetCastingPlan" type="L3RECORDSET">
/// 
/// 按照日期、铸机获取铸机浇钢计划
/// ARG &gt;&gt; Condition : 收池条件。
/// RET &gt;&gt; 找到的计划记录集。
/// <Param name="Condition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CPlan_Mag::GetCastingPlan(L3STRING strDate,L3STRING strCasterID)
{
	CString csCasterID = strCasterID;
	CString csDate = strDate;
	CString csTemp = _T(" SELECT a.*,a.Thickness || '*' || a.Width || '*' || a.Length as Std ,b.protocol,b.ProduceStd,b.TECH_REQUEST                      ");
			csTemp+= _T(" FROM %s a,%s b where to_Char(a.CreateDate,'yyyy-mm-dd') = '%s'   and a.plan_ord_id = b.planid   ");
	CString strSQL;
	if(csCasterID.IsEmpty())
	{
		csTemp += _T(" order by a.CasterID,a.Status,a.PlanID,a.Pre_SteelGradeIndex,a.Thickness,a.Width,a.Length   ");
		strSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,PLAN_ORDER_CLASS_URI,csDate);
	}
	else
	{
		csTemp+= _T("  and a.CasterID ='%s'  order by a.Status, a.PlanID,a.Pre_SteelGradeIndex,a.Thickness,a.Width,a.Length ");	
	    strSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,PLAN_ORDER_CLASS_URI,csDate,csCasterID);
	}
	CL3RecordSetWrap rsResult;
	BOOL bRet = Query(strSQL,rsResult);
	if(!bRet)
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CPlan_Mag" name="GetIntegratedPlanOrd" type="L3RECORDSET">
/// 
/// 按照起始日期获取计划订单
/// ARG &gt;&gt; Condition : 收池条件。
/// RET &gt;&gt; 找到的计划记录集。
/// <Param name="Condition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CPlan_Mag::GetIntegratedPlanOrd(L3STRING strBeginDate,L3STRING strEndDate,L3STRING strSteelGrade)
{
	CString csEndDate = strEndDate;
	CString csBeginDate = strBeginDate;
	CString csSteelGrade = strSteelGrade;
	csSteelGrade.Trim();
	CString csTemp;
	CString strSQL;
	if(csSteelGrade.IsEmpty())
	{
			csTemp  = _T(" SELECT a.*,a.Thickness || '*' || Width || '*' || Length as Std                       ");
			csTemp += _T(" FROM %s a where to_Char(a.CreateDate,'yyyy-mm-dd') between  '%s'  and '%s'           ");
	        csTemp += _T(" order by  a.SpareWeight desc ,a.Status,a.SteelGrade,a.Thickness,a.Width,a.Length asc ");
			strSQL.Format(csTemp,PLAN_ORDER_CLASS_URI,strBeginDate,csEndDate);
	}
	else
	{ 
			csTemp  = _T(" SELECT a.*,a.Thickness || '*' || Width || '*' || Length as Std                                      ");
			csTemp += _T(" FROM %s a where (to_Char(a.CreateDate,'yyyy-mm-dd') between  '%s'  and '%s')  and SteelGrade ='%s'  ");
	        csTemp += _T(" order by  a.SpareWeight desc ,a.Status,a.Thickness,a.Width,a.Length asc                             ");
			strSQL.Format(csTemp,PLAN_ORDER_CLASS_URI,strBeginDate,csEndDate,csSteelGrade);
	}

	CL3RecordSetWrap rsResult;
	BOOL bRet = Query(strSQL,rsResult);
	if(!bRet)
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CPlan_Mag" name="PlanOrdIntegrateCfm" type="L3BOOL">
/// 
/// 计划订单收池确认，同时确定铸机号，更改订单的状态为2收池
/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID\CasrterID\New_BOF_Flag字段。
///         &gt;&gt;strCasterID ：铸机号
///         &gt;&gt;nNewBOFFlag ：新旧转炉标志
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsPlan" type="L3RECORDSET"></Param>
/// <Param name="strCasterID" type="L3STRING"></Param>
/// </Method>
L3LONG CPlan_Mag::PlanOrdIntegrateCfm(L3RECORDSET rsPlan)
{
	//CL3RecordSetWrap rsPlanOrd =rsPlan;
 //   if( rsPlanOrd.IsNull() || rsPlanOrd.GetRowCount() < 1)
	//	return -1;
	//if( rsPlanOrd.GetFieldIndex(_T("PlanID")) < 0 ||
	//	rsPlanOrd.GetFieldIndex(_T("CasterID")) < 0 ||
	//	rsPlanOrd.GetFieldIndex(_T("New_BOF_Flag")) < 0 )
	//	return -1;

	//BOOL bUseTrans = !IsInTrans();
	//LONG nTrans = 0;
	//if(bUseTrans)
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return -1;
	//}
	//rsPlanOrd.MoveFirst();
	//while(!rsPlanOrd.IsEOF())
	//{
	//	CL3Variant vaTemp = rsPlanOrd.GetFieldByName(_T("PlanID"));
	//	CString csPlanID = vaTemp.ToCString();
	//	CString csUri = PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID;

	//	//根据工艺卡标准判断指定铸机是否合法20081212 tangyi
	//	CString csSteelGrade = GetObjectPropValue(csUri,_T("SteelGrade")).ToCString();	
	//	CString csProtocol = GetObjectPropValue(csUri,_T("Protocol")).ToCString();
	//	CString csSteelGradeIndex = GetSteelGradeIndexBySteelGrade(csSteelGrade,csProtocol);
	//	if(csSteelGradeIndex == EMPTY_ERR)
	//	{	
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return -3;
	//	}
	//	CString csProdSheetUri = QA_PROD_SHEET_CLASS_URI + _T("\\") + csSteelGradeIndex;
	//	L3LONG	nCasterType = GetObjectPropValue(csProdSheetUri,_T("Caster_Type")).ToLong();	
	//	CString csCasterID = rsPlanOrd.GetFieldByName(_T("CasterID")).ToCString();
	//	L3LONG  nCasterUnitID = _ttol(csCasterID.Mid(2,1));
	//	switch(nCasterType)
	//	{
	//		case NoLFCaster:
	//			if (nCasterUnitID > 2) 		
	//			{	
	//				if(bUseTrans)
	//					Rollback(nTrans);
	//				return -4;
	//			};
	//			break;
	//		case OldLFCaster:
	//			if (nCasterUnitID > 4 || nCasterUnitID < 3) 
	//			{	
	//				if(bUseTrans)
	//					Rollback(nTrans);
	//				return -4;
	//			};
	//			break;
	//		case NewLFCaster:
	//			if (nCasterUnitID < 5) 
	//			{	
	//				if(bUseTrans)
	//					Rollback(nTrans);
	//				return -4;
	//			};
	//			break;
	//		default:
	//			{	
	//				if(bUseTrans)
	//					Rollback(nTrans);
	//				return -5;
	//			};
	//	}
	//	L3SHORT nBOFFlag = 0;
	//	L3LONG	nBOFType = GetObjectPropValue(csProdSheetUri,_T("BOF_Type")).ToLong();
	//	switch(nBOFType)
	//	{
	//		case BOF50t: nBOFFlag = nOldBOF;
	//			break;
	//		case BOF80t: nBOFFlag = nNewBOF;
	//			break;
	//		default:
	//			break;
	//	}		
	//	if(!SetObjectPropValue(csUri,_T("CasterID"),CL3Variant(csCasterID)))
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return -6;				
	//	}
	//	if(!SetObjectPropValue(csUri,_T("New_BOF_Flag"),CL3Variant(nBOFFlag)))
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return false;				
	//	}
	//	if(!SetObjectPropValue(csUri,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_INTEGRATED)))
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return -7;				
	//	}
	//	rsPlanOrd.MoveNext();
	//}
	//if(bUseTrans)
	//	Commit(nTrans);

	return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="PlanOrdIntegrateCancel" type="L3BOOL">
/// 
/// 计划订单收池取消，同时取消铸机号，更改订单的状态为1未收池
/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsPlan" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CPlan_Mag::PlanOrdIntegrateCancel(L3RECORDSET rsPlan)
{
	//2008-12-24 tangyi 屏蔽
	//CL3RecordSetWrap rsPlanOrd =rsPlan;
 //   if( rsPlanOrd.IsNull() || rsPlanOrd.GetRowCount() < 1)
	//	return true;
	//BOOL bUseTrans = !IsInTrans();
	//LONG nTrans = 0;
	//if(bUseTrans)
	//{
	//	nTrans = BeginTrans();
	//	if(nTrans < 1)
	//		return false;
	//}
	//rsPlanOrd.MoveFirst();
	//while(!rsPlanOrd.IsEOF())
	//{
	//	CL3Variant vaTemp = rsPlanOrd.GetFieldByName(_T("PlanID"));
	//	CString csPlanID = vaTemp.ToCString();
	//	CString csUri = PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID;
	//	CString csStatus = GetObjectPropValue(csUri,_T("Status")).ToCString();
	//	if(csStatus != PLAN_ORDER_STATUS_INTEGRATED) 
	//	{
	//		rsPlanOrd.MoveNext();
	//		continue;
	//	}
	//	if(!SetObjectPropValue(csUri,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_UNINTEGRATE)))
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return false;				
	//	}
	//	if(!SetObjectPropValue(csUri,_T("CasterID"),CL3Variant(_T(""))))
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return false;				
	//	}
	//	if(!SetObjectPropValue(csUri,_T("New_BOF_Flag"),CL3Variant(0)))
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return false;				
	//	}
	//	rsPlanOrd.MoveNext();
	//}
	//if(bUseTrans)
	//	Commit(nTrans);

	return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="GetSteelGradeIndexBySteelGrade" type="L3LONG">
/// 
/// 获取钢种代表炼钢记号
/// ARG&gt;&gt; csSteelGrade : 钢种。
/// RET &lt;&lt; 成功返回炼钢记号。
/// <Param name="csSteelGrade" type="L3STRING">钢种</Param>
/// </Method>
CString  CPlan_Mag::GetSteelGradeIndexBySteelGrade(CString csSteelGrade,CString csProtocol,CString csMaterialCode)
{
	CString csTemp;
	csProtocol.Trim();
	csMaterialCode.Trim();
	CString csBigBloomFlag = csMaterialCode.Mid(0,3);

	CString strSQL;
	if(csProtocol.IsEmpty())
	{
		if(csBigBloomFlag == _T("613"))
		{
			csTemp = _T(" SELECT SteelGradeIndex  FROM %s  where   SteelGrade = '%s' and substr(SteelGradeIndex,1,1) ='J' ");	
			strSQL.Format(csTemp,QA_STG_RELATION_CLASS_URI,csSteelGrade);
		}
		else
		{
			if(csBigBloomFlag == _T("615"))
			{
				csTemp = _T(" SELECT SteelGradeIndex  FROM %s  where   SteelGrade = '%s' and substr(SteelGradeIndex,1,1) ='M' ");	
				strSQL.Format(csTemp,QA_STG_RELATION_CLASS_URI,csSteelGrade);
			}
			else
			{
				csTemp = _T(" SELECT SteelGradeIndex  FROM %s  where   SteelGrade = '%s'   and (substr(SteelGradeIndex,1,1) <>'J' and substr(SteelGradeIndex,1,1) <>'M') ");	
				strSQL.Format(csTemp,QA_STG_RELATION_CLASS_URI,csSteelGrade);

			}
		}

	}
	else
	{
		if(csBigBloomFlag == _T("613"))
		{
			csTemp = _T("SELECT SteelGradeIndex  FROM %s  where   SteelGrade = '%s'  and Protocol = '%s' and (substr(SteelGradeIndex,1,1) ='J' or substr(SteelGradeIndex,1,1) ='M') ");	
			strSQL.Format(csTemp,QA_STG_RELATION_CLASS_URI,csSteelGrade,csProtocol);
		}
		else
		{
			if(csBigBloomFlag == _T("615"))
			{
				csTemp = _T(" SELECT SteelGradeIndex  FROM %s  where   SteelGrade = '%s' and Protocol = '%s' and substr(SteelGradeIndex,1,1) ='M' ");	
				strSQL.Format(csTemp,QA_STG_RELATION_CLASS_URI,csSteelGrade,csProtocol);
			}
			else
			{
				csTemp = _T("SELECT SteelGradeIndex  FROM %s  where   SteelGrade = '%s'  and Protocol = '%s' and (substr(SteelGradeIndex,1,1) <>'J' and substr(SteelGradeIndex,1,1) <>'M') ");	
				strSQL.Format(csTemp,QA_STG_RELATION_CLASS_URI,csSteelGrade,csProtocol);

			}
		}

	}
	CL3RecordSetWrap rsResult;
	BOOL bRet = Query(strSQL,rsResult);
	if(!bRet || rsResult.IsNull()|| rsResult.GetRowCount() < 1)
		return EMPTY_ERR;
	rsResult.MoveFirst();
	CL3Variant vsSteelGradeIndex = rsResult.GetFieldByIndex(0);
	CString csSteelGradeIndex = vsSteelGradeIndex.ToCString();
	return csSteelGradeIndex;

}

/// <Method class="CPlan_Mag" name="CalculateHeatCount" type="L3LONG">
/// 
/// 计算炉数
/// ARG&gt;&gt; nBOFFlag : 转炉标志。
/// dWeight:计划订单重量
/// RET &lt;&lt; 成功返回炼钢记号。
/// <Param name="nBOFFlag" type="L3SHORT">转炉标志</Param>
/// <Param name="dWeight" type="L3DOUBLE">计划订单重量</Param>
/// </Method>
L3LONG CPlan_Mag::CalculateHeatCount(L3SHORT nBOFFlag,L3DOUBLE dWeight)
{
	L3LONG nWeight = int((dWeight*1000));
	L3LONG nSteelLadleCount = 0;
	L3LONG nBalanceWeight =0;
	L3LONG nLadleWeight =0;
	if(nBOFFlag == 0) nLadleWeight = OLD_LADLE_WEIGHT; else nLadleWeight = NEW_LADLE_WEIGHT;

	nSteelLadleCount = nWeight/ nLadleWeight;
	nBalanceWeight = nWeight % nLadleWeight;
	if(nBalanceWeight > BALANCE_WEIGHT)
		nSteelLadleCount++;

	return nSteelLadleCount;

}


/// <Method class="CPlan_Mag" name="GenCastingPlanOfSpecifyCasterID" type="L3LONG">
/// 生成指定铸机铸机浇钢计划
/// ARG&gt;&gt; csCasterID : 铸机。
/// rsPlanOrder:计划订单信息
/// nHeatCount:炉数
/// csSteelGradeIndex:炼钢记号
/// RET &lt;&lt; 返回出错代码。
/// <Param name="csCasterID" type="CSTRING">铸机</Param>
/// <Param name="rsPlanOrder" type="L3RECOEDSET">计划订单信息</Param>
/// <Param name="nHeatCount" type="L3LONG">炉数</Param>
/// <Param name="csSteelGradeIndex" type="CSTRING">炼钢记号</Param>
/// </Method>
L3LONG CPlan_Mag::GenCastingPlanOfSpecifyCasterID(CString csCasterID,L3RECORDSET rsPlanOrder,
												  L3LONG nHeatCount,CString csSteelGradeIndex,
												  L3DOUBLE fWeight,L3SHORT nBOFFlag)
{
	CL3RecordSetWrap rsPlanOrd =rsPlanOrder;
	L3DOUBLE fTotalWeight = fWeight*1000;



	//2008-12-24 tangyi计划订单实际投用量增加、余量减少
	CString csPlanID = rsPlanOrd.GetFieldByName(_T("PlanID")).ToCString();
	CString csPlanOrderUri = PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID;
	CL3Variant vsPlanOrderCurSpareWeight = GetObjectPropValue(csPlanOrderUri,_T("SpareWeight"));
	if(!vsPlanOrderCurSpareWeight.IsValid() || vsPlanOrderCurSpareWeight.IsError() || vsPlanOrderCurSpareWeight.IsNull())
		return -1;

	L3DOUBLE fPlanOrderSpareWeight = vsPlanOrderCurSpareWeight.ToDouble();
	if((fPlanOrderSpareWeight - fWeight) < 0)
		return -81;//余量不足
	CL3Variant vsPlanOrderCurActWeight = GetObjectPropValue(csPlanOrderUri,_T("ActWeight"));
	if(!vsPlanOrderCurActWeight.IsValid() || vsPlanOrderCurActWeight.IsError() || vsPlanOrderCurActWeight.IsNull())
		return -1;

	L3DOUBLE fPlanOrderActWeight = vsPlanOrderCurActWeight.ToDouble();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	L3DOUBLE fCurSpareWeight = fPlanOrderSpareWeight - fWeight;
	if(!SetObjectPropValue(csPlanOrderUri,_T("SpareWeight"),CL3Variant(fCurSpareWeight)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -82;
	}
	L3DOUBLE fCurActWeight = fPlanOrderActWeight + fWeight;
	if(!SetObjectPropValue(csPlanOrderUri,_T("ActWeight"),CL3Variant(fCurActWeight)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -83;
	}
	//2009-01-10 手动添加协议
	if(!SetObjectPropValue(csPlanOrderUri,_T("Protocol"),rsPlanOrd.GetFieldByName(_T("Protocol"))))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -99;
	}

	CL3RecordSetWrap rsCastingPlan;
	if(!CreateClassPropSet(PLAN_CASTING_CLASS_URI,rsCastingPlan)) 
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -84;
	}
	rsCastingPlan.AppendRecord();
	//rsPlanOrd.MoveFirst();不能移动该记录集的指针

	for(int i=0;i<nHeatCount;i++)
	{
		//rsCastingPlan.CopyCurRowFrom(rsPlanOrd);
		//生成预定炉号
		CL3Variant vsYear = GetObjectPropValue(PLAN_CUR_PREHEATID_CLASS_URI + _T("\\") + csCasterID,_T("Year"));
		if(!vsYear.IsValid() || vsYear.IsError() || vsYear.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -85;
		}
		CString csYear = vsYear.ToCString();
		CL3Variant vsPreHeatID = GetObjectPropValue(PLAN_CUR_PREHEATID_CLASS_URI + _T("\\") + csCasterID,_T("Cur_PreHeatID"));
		if(!vsPreHeatID.IsValid() || vsPreHeatID.IsError() || vsPreHeatID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -86;
		}
		L3LONG nPreHeatID = vsPreHeatID.ToLong();
		nPreHeatID++;
		CString csTempPreHeaID;
		csTempPreHeaID.Format(_T("%06d"),nPreHeatID);
		CString csPreHeatID = csYear + csCasterID + csTempPreHeaID;
		if(!SetObjectPropValue(PLAN_CUR_PREHEATID_CLASS_URI + _T("\\") + csCasterID,_T("Cur_PreHeatID"),CL3Variant(nPreHeatID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -87;
		}
		//生成浇钢计划其它信息
		rsCastingPlan.SetFieldByName(_T("PlanID"),CL3Variant(csPreHeatID));
		rsCastingPlan.SetFieldByName(_T("PreHeatID"),CL3Variant(csPreHeatID));
		rsCastingPlan.SetFieldByName(_T("Pre_SteelGradeIndex"),CL3Variant(csSteelGradeIndex));
		rsCastingPlan.SetFieldByName(_T("CasterID"),CL3Variant(csCasterID));
		rsCastingPlan.SetFieldByName(_T("Length"),rsPlanOrd.GetFieldByName(_T("Length")));
		rsCastingPlan.SetFieldByName(_T("Width"),rsPlanOrd.GetFieldByName(_T("Width")));
		rsCastingPlan.SetFieldByName(_T("Thickness"),rsPlanOrd.GetFieldByName(_T("Thickness")));
		rsCastingPlan.SetFieldByName(_T("Pre_SteelGrade"),rsPlanOrd.GetFieldByName(_T("SteelGrade")));
		rsCastingPlan.SetFieldByName(_T("Plan_Ord_ID"),rsPlanOrd.GetFieldByName(_T("PlanID")));
		rsCastingPlan.SetFieldByName(_T("New_BOF_Flag"),CL3Variant(nBOFFlag));
		//计划状态为未排产
		rsCastingPlan.SetFieldByName(_T("Status"),CL3Variant(CASTING_PLAN_STATUS_UNSCHEDULING));

		//更据铸机号获取最优工艺路径
		CString csTemp = _T("Select * from %s where CasterID = '%s' and Lev_Type = 1 ");
		CString csSQL;
		csSQL.Format(csTemp,QA_UNIT_ROUTE_CLASS_URI,csCasterID);
		CL3RecordSetWrap rsRoute;
		if(!Query(csSQL,rsRoute) || rsRoute.IsNull() || rsRoute.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -89;
		}
		rsRoute.MoveFirst();
		//得到RH炉座
		CL3Variant vsRHID = rsRoute.GetFieldByName(_T("RHID"));
		if(!vsRHID.IsValid() || vsRHID.IsError() || vsRHID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -90;
		}
		CString csRHID = vsRHID.ToCString();
		
		//得到LF炉座
		CL3Variant vsLFID = rsRoute.GetFieldByName(_T("LFID"));
		if(!vsLFID.IsValid() || vsLFID.IsError() || vsLFID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -91;
		}
		CString csLFID = vsLFID.ToCString();
		

		//得到转炉炉座
		CL3Variant vsBOFID = rsRoute.GetFieldByName(_T("BOFID"));
		if(!vsBOFID.IsValid() || vsBOFID.IsError() || vsBOFID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -92;
		}
		CString csBOFID = vsBOFID.ToCString();
		

		//获取精炼区分
		CL3Variant vsLFType = GetObjectPropValue(QA_PROD_SHEET_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("LF_Type"));
		if(!vsLFType.IsValid() || vsLFType.IsError() || vsLFType.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -93;
		}
		CString csLFType = vsLFType.ToCString();
		CL3Variant vsRHType = GetObjectPropValue(QA_PROD_SHEET_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("RH_Type"));
		if(!vsRHType.IsValid() || vsRHType.IsError() || vsRHType.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -94;
		}
		CString csRHType = vsRHType.ToCString();
		//2009-04-20 tangyi 获取NC工艺路径
		CString csRoute = rsPlanOrd.GetFieldByName(_T("Product_Route")).ToCString();
		//根据精炼区分得到炉座号，防止最优工艺路径维护错误加保护2009-03-30，
		//工艺路径是由冶金规范确定的，最优工艺路径只是参考
		
		/*屏蔽开始 by hyh 2012-05-17
		//Modify begin by llj 2011-03-21 为管理到不锈钢厂的炉次信息,防止NC计划出现错误 
		if(csCasterID == _T("S66"))
		{//确保到不锈钢铸机的计划不经过LF和RH机组
			csLFType == _T("01");
			csRHType == _T("01");
		}
		//Modify end
		屏蔽结束*/

		if(csLFType == _T("01") && csRHType == _T("01"))//不经过LF及RH
		{
			rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(_T("0")));
			rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(_T("0")));
			rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("0")));
		}
		if(csLFType == _T("01") && csRHType != _T("01"))//不经过LF，经过RH
		{
			rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(_T("0")));
			csRHID =_T("S51");
			rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(csRHID));
			rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("R")));
		}
		if(csLFType != _T("01") && csRHType == _T("01"))//经过LF，但不经过RH
		{
			if(csCasterID == _T("S65")) csLFID = _T("S43");//铸机是5#铸机，必须经过3#LF
			if((csLFID == _T("0") || csLFID == _T("S43")) && csCasterID != _T("S65")) csLFID = _T("S41");//LF未确定或者3#LF，并且是5#铸机，必须经过1#LF
			rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(csLFID));
			rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(_T("0")));
			rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("L")));
		}
		if(csLFType != _T("01") && csRHType != _T("01"))//经过LF，经过RH
		{
			csRHID = _T("S51");
			csLFID = _T("S43");
			rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(csLFID));
			rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(csRHID));
			if(csRoute == _T("BRL"))
				rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("RL")));
			else
				rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("LR")));
		}
		//if(csLFType == _T("2") && csRHType == _T("2"))
		//{
		//	rsCastingPlan.SetFieldByName(_T("LFID"),CL3Variant(csLFID));
		//	rsCastingPlan.SetFieldByName(_T("RHID"),CL3Variant(csRHID));
		//	rsCastingPlan.SetFieldByName(_T("Refine_Type"),CL3Variant(_T("RL")));
		//}
	   if(nBOFFlag == nNewBOF)
		   csBOFID =_T("S24");
	   else
		  if((csBOFID == _T("S24")) && csCasterID != _T("S65")) csBOFID = _T("S21");

		rsCastingPlan.SetFieldByName(_T("BOFID"),CL3Variant(csBOFID));

		//生成目标出钢量
		L3DOUBLE fLadleWeight = 0;
		if(nBOFFlag == 1) fLadleWeight = NEW_LADLE_WEIGHT;else fLadleWeight = OLD_LADLE_WEIGHT;
		rsCastingPlan.SetFieldByName(_T("Aim_Tapped_Weight"),CL3Variant(fLadleWeight/1000));
		//生成实际投放量 2008-12-24
		fTotalWeight = fTotalWeight - fLadleWeight;
		if(fTotalWeight <= BALANCE_WEIGHT)
			rsCastingPlan.SetFieldByName(_T("ActWeight"),CL3Variant((fTotalWeight + fLadleWeight)/1000));
		else
			rsCastingPlan.SetFieldByName(_T("ActWeight"),CL3Variant(fLadleWeight/1000));
			

		//计算钢坯枝数
		CL3Variant vsLength = rsPlanOrd.GetFieldByName(_T("Length"));
		if(!vsLength.IsValid() || vsLength.IsError() || vsLength.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -95;
		}
		CString csLength = vsLength.ToCString();
		//大方坯按照钢种管理2009-03-12 tangyi
		CString csSteelGrade = rsPlanOrd.GetFieldByName(_T("SteelGrade")).ToCString();
		CString csObjectID; 
		//2016-1-1 修改，不锈钢也是按照此精品钢计算重量
		if((csSteelGradeIndex.Mid(0,1) ==_T("J"))||(csSteelGradeIndex.Mid(0,1) ==_T("B")))
			csObjectID = csLength + csSteelGrade;
		else 
			csObjectID = csLength;
		CL3Variant vsCalWeight = GetObjectPropValue(QA_CAL_WEIGHT_CLASS_URI + _T("\\") + csObjectID,_T("Weight"));
		if(!vsCalWeight.IsValid() || vsCalWeight.IsError() || vsCalWeight.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -96;
		}
		L3DOUBLE dCalWeight = vsCalWeight.ToDouble();
		L3LONG nCalWeight =int(dCalWeight*1000);
		L3LONG nLadleWeight = 0;
		if(nBOFFlag == 1) nLadleWeight = NEW_LADLE_WEIGHT;else nLadleWeight = OLD_LADLE_WEIGHT;
		L3LONG nBloomCount = nLadleWeight/nCalWeight;
		if(nLadleWeight % nCalWeight > 0)
			nBloomCount++;
		rsCastingPlan.SetFieldByName(_T("Bloom_Count"),CL3Variant(nBloomCount));
		//计划创建时间
		COleDateTime timeNow = COleDateTime::GetCurrentTime();
		rsCastingPlan.SetFieldByName(_T("CreateDate"),CL3Variant(timeNow));
		rsCastingPlan.SetFieldByName(_T("Planner"),CL3Variant(GetCurrentUser()));
		//计算计划开浇时间
		L3DATETIME dtCastingTime;
		if(CalculateCastingTime(csCasterID,csSteelGradeIndex,dtCastingTime) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -97;
		}
		
		rsCastingPlan.SetFieldByName(_T("Aim_Time_CastingStart"),CL3Variant(dtCastingTime));
		//计算浇钢时间所以把创建记录放入循环内
		if(CreateNewObjects(PLAN_CASTING_CLASS_URI,L3RECORDSET(rsCastingPlan)) < rsCastingPlan.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -98;
		}
		rsCastingPlan.MoveFirst();
	}

	
	if(bUseTrans)
		Commit(nTrans);
	return 0;
}

/// <Method class="CPlan_Mag" name="CalculateCastingTime" type="L3LONG">
/// 计算浇钢计划铸机开浇时间
/// ARG&gt;&gt; csCasterID : 铸机。
/// ARG&gt;&gt; csSteelGradeIndex : 炼钢记号。
/// ARG&gt;&gt; &dtCastingTime : 开浇时间。
/// RET &lt;&lt; 错误返回错误代码。
/// <Param name="csCasterID" type="CSTRING">铸机</Param>
/// <Param name="csSteelGradeIndex" type="CSTRING">炼钢记号</Param>
/// </Method>
L3LONG CPlan_Mag::CalculateCastingTime(CString csCasterID,CString csSteelGradeIndex,L3DATETIME &dtCastingTime)
{
	L3DATETIME dtPreCastingTime;
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csTemp = _T(" SELECT Max(Aim_Time_CastingStart)  FROM %s  where  CasterID = '%s' ");	
	CString strSQL;
	strSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,csCasterID);
	CL3RecordSetWrap rsResult;
	BOOL bRet = Query(strSQL,rsResult);
	if(!bRet || rsResult.IsNull()|| rsResult.GetRowCount() < 1)
		L3DATETIME dtPreCastingTime=timeNow;
	else
	{
		rsResult.MoveFirst();
		CL3Variant vsPreCastingStartTime = rsResult.GetFieldByIndex(0);
		dtPreCastingTime = vsPreCastingStartTime.ToDateTime();
		//L3DOUBLE nTime = difftime(timeNow,dtPreCastingTime)*24;//2009-02-12 tangyi
		//2009-04-6 
		L3DATETIME dtNow = timeNow;
		COleDateTimeSpan span = dtNow - dtPreCastingTime;
		L3DOUBLE nTime =  abs((LONG)span.GetTotalHours());
		if(dtPreCastingTime <= 0 || nTime > 30)
		dtPreCastingTime=timeNow;
	}
	//Modify begin by llj 2011-04-26 送不锈钢钢水计划的浇铸时间为当前时间
	dtPreCastingTime=timeNow;
	//Modify end
	//根据炼钢记号得到浇注时间
	CL3Variant vsStdCastingTime = GetObjectPropValue(QA_UNIT_PROC_TIME_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("Caster_Proc_Time"));
	if(!vsStdCastingTime.IsValid() || vsStdCastingTime.IsError() || vsStdCastingTime.IsNull())
		return -2;
	L3DATETIME dtProcessTime = vsStdCastingTime.ToDateTime();
	dtCastingTime = dtPreCastingTime + dtProcessTime/1440;
	return 0;

}

#pragma region 原浇钢计划编制CastingPlanGen(L3RECORDSET rsPlan)

/// <Method class="CPlan_Mag" name="CastingPlanGen" type="L3BOOL">
/// 
/// 编制铸机浇钢计划，更改订单的状态为3生成浇钢计划，浇钢计划的状态为1未排产
/// ARG&gt;&gt; rsPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsPlan" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CPlan_Mag::CastingPlanGen(L3RECORDSET rsPlan)
{
	CL3RecordSetWrap rsPlanOrd =rsPlan;
    if( rsPlanOrd.IsNull() || rsPlanOrd.GetRowCount() < 1)
		return -1;

	if( rsPlanOrd.GetFieldIndex(_T("PlanID")) < 0 ||
		rsPlanOrd.GetFieldIndex(_T("CasterID")) < 0 ||
		rsPlanOrd.GetFieldIndex(_T("SpareWeight")) < 0)
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	rsPlanOrd.MoveFirst();
	while(!rsPlanOrd.IsEOF())
	{
		//判断余量是否满足要求
		CL3Variant vsSteelWeight = rsPlanOrd.GetFieldByName(_T("SpareWeight"));
		if(!vsSteelWeight.IsValid() || vsSteelWeight.IsError() || vsSteelWeight.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}	
		L3DOUBLE dSteelWeight = vsSteelWeight.ToDouble();
		if(dSteelWeight * 1000 <= BALANCE_WEIGHT)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -18;
		}
		//获取代表炼钢记号
		CL3Variant vsSteelGrade = rsPlanOrd.GetFieldByName(_T("SteelGrade"));
		if(!vsSteelGrade.IsValid() || vsSteelGrade.IsError() || vsSteelGrade.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;
		}
		CString csSteelGrade = vsSteelGrade.ToCString();
		CL3Variant vsProtocol = rsPlanOrd.GetFieldByName(_T("Protocol"));
		CString csProtocol = vsProtocol.ToCString();
		//2009-01-15 tangyi 添加物料编码
		CL3Variant vsMaterialCode = rsPlanOrd.GetFieldByName(_T("MaterialCode"));
		if(!vsMaterialCode.IsValid() || vsMaterialCode.IsError() || vsMaterialCode.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -19;
		}
		CString csMaterialCode = vsMaterialCode.ToCString();
		CString csSteelGradeIndex = GetSteelGradeIndexBySteelGrade(csSteelGrade,csProtocol,csMaterialCode);
		if(csSteelGradeIndex == EMPTY_ERR)
		{	
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
		//判断分配的铸机号是否合法
		CL3Variant vsCasterID = rsPlanOrd.GetFieldByName(_T("CasterID"));
		if(!vsCasterID.IsValid() || vsCasterID.IsError() || vsCasterID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		CString csCasterID = vsCasterID.ToCString();
		CString csProdSheetUri = QA_PROD_SHEET_CLASS_URI + _T("\\") + csSteelGradeIndex;
		L3LONG	nCasterType = GetObjectPropValue(csProdSheetUri,_T("Caster_Type")).ToLong();	
		L3LONG  nCasterUnitID = _ttol(csCasterID.Mid(2,1));
		switch(nCasterType)
		{
			case NoLFCaster:
				//2009-01-17 tangyi
				if (nCasterUnitID > 7 || nCasterUnitID < 1) 		
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			case OldLFCaster:
				if (nCasterUnitID > 4 || nCasterUnitID < 3) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			case NewLFCaster:
				if (nCasterUnitID < 5) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			//Modify begin 2011-02-15 llj
			case NewLFCaster7:
				if (nCasterUnitID < 7) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			//Modify end

			//add by hyh 2012-06-07
			case NewLFCaster6:
				if (nCasterUnitID < 6) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
				//end
			default:
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -6;
				};
		}
		L3SHORT nBOFFlag = 0;
		L3LONG	nBOFType = GetObjectPropValue(csProdSheetUri,_T("BOF_Type")).ToLong();
		switch(nBOFType)
		{
			case BOF50t: nBOFFlag = nOldBOF;
				break;
			case BOF80t: nBOFFlag = nNewBOF;
				break;
			default:
				break;
		}	
		//计算炉次
		
		L3LONG nSteelLadleCount = CalculateHeatCount(nBOFFlag,dSteelWeight);
		//生成浇钢计划
		L3LONG nBackValue = GenCastingPlanOfSpecifyCasterID(csCasterID,
			                                                L3RECORDSET(rsPlanOrd),
															nSteelLadleCount,
															csSteelGradeIndex,
															dSteelWeight,
															nBOFFlag);
		if(nBackValue < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return nBackValue;
		}
		//更改计划订单状态
		CL3Variant vsPlanID = rsPlanOrd.GetFieldByName(_T("PlanID"));
		if(!vsPlanID.IsValid() || vsPlanID.IsError() || vsPlanID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -16;
		}
		CString csPlanID = vsPlanID.ToCString();
		CString csStatus = GetObjectPropValue(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID,_T("Status")).ToCString();
		if(csStatus ==PLAN_ORDER_STATUS_UNINTEGRATE)
		{
			if(!SetObjectPropValue(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_CASTING)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -17;
			}	
		}
		rsPlanOrd.MoveNext();
	}


	if(bUseTrans)
		Commit(nTrans);

	return 0;// TODO : 请在此添加逻辑代码
}

#pragma endregion

/// <Method class="CPlan_Mag" name="NewCastingPlanGen" type="L3BOOL">
/// 
/// 新编制铸机浇钢计划，更改订单的状态为3生成浇钢计划，浇钢计划的状态为1未排产
/// ARG&gt;&gt; csPlanOrd : 订单号，csSteelGradeIndex：炼钢记号。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsPlan" type="L3RECORDSET"></Param>
/// <Param name="csSteelGradeIndex" type="string"></Param>
/// </Method>
L3LONG CPlan_Mag::NewCastingPlanGen(L3RECORDSET rsPlan,L3STRING strSteelGradeIndex)
{

	CL3RecordSetWrap rsPlanOrd =rsPlan;
    if( rsPlanOrd.IsNull() || rsPlanOrd.GetRowCount() < 1)
		return -1;

	if( rsPlanOrd.GetFieldIndex(_T("PlanID")) < 0 ||
		rsPlanOrd.GetFieldIndex(_T("CasterID")) < 0 ||
		rsPlanOrd.GetFieldIndex(_T("SpareWeight")) < 0)
		return -1;

	CString csSteelGradeIndex=strSteelGradeIndex;
	csSteelGradeIndex=csSteelGradeIndex.Trim();
	if (strSteelGradeIndex==_T(""))
		return -1;

    //2016-1-1 修改，此检查没有意思，选择炼钢记号时，已检查过。
	//检查炼钢记号是否存在并处于使用状态  
	//CString csTemp = _T(" SELECT *  FROM %s  where  STEELGRADEINDEX = '%s' and USE_FLAG='0' ");	
	//CString strSQL;
	//strSQL.Format(csTemp,QA_STG_RELATION_CLASS_URI,csSteelGradeIndex);
	//CL3RecordSetWrap rsSteelGradeIndex ;
	//BOOL bRet = Query(strSQL,rsSteelGradeIndex);		
	//if(!bRet || rsSteelGradeIndex.IsNull() || rsSteelGradeIndex.GetRowCount() < 1)
	//{
	//		return -1;
	//}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	rsPlanOrd.MoveFirst();
	while(!rsPlanOrd.IsEOF())
	{
		//判断余量是否满足要求
		CL3Variant vsSteelWeight = rsPlanOrd.GetFieldByName(_T("SpareWeight"));
		if(!vsSteelWeight.IsValid() || vsSteelWeight.IsError() || vsSteelWeight.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}	
		L3DOUBLE dSteelWeight = vsSteelWeight.ToDouble();
		if(dSteelWeight * 1000 <= BALANCE_WEIGHT)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -18;
		}
		//获取代表炼钢记号
		CL3Variant vsSteelGrade = rsPlanOrd.GetFieldByName(_T("SteelGrade"));
		if(!vsSteelGrade.IsValid() || vsSteelGrade.IsError() || vsSteelGrade.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;
		}
		CString csSteelGradeOfOrd = vsSteelGrade.ToCString();
		//CL3Variant vsProtocol = rsPlanOrd.GetFieldByName(_T("Protocol"));
		//CString csProtocol = vsProtocol.ToCString();
		////2009-01-15 tangyi 添加物料编码
		//CL3Variant vsMaterialCode = rsPlanOrd.GetFieldByName(_T("MaterialCode"));
		//if(!vsMaterialCode.IsValid() || vsMaterialCode.IsError() || vsMaterialCode.IsNull())
		//{
		//	if(bUseTrans)
		//		Rollback(nTrans);
		//	return -19;
		//}
		//CString csMaterialCode = vsMaterialCode.ToCString();
		//CString csSteelGradeIndex = GetSteelGradeIndexBySteelGrade(csSteelGrade,csProtocol,csMaterialCode);
		//if(csSteelGradeIndex == EMPTY_ERR)
		//{	
		//	if(bUseTrans)
		//		Rollback(nTrans);
		//	return -3;
		//}



		//2016-1-1 修改 没有意思
		//判断订单钢种与选定的炼钢记号中的钢种是否一致
	/*	if(rsSteelGradeIndex.GetFieldByName(_T("SteelGrade")).ToCString()!=csSteelGradeOfOrd)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;
		}*/

		//判断分配的铸机号是否合法
		CL3Variant vsCasterID = rsPlanOrd.GetFieldByName(_T("CasterID"));
		if(!vsCasterID.IsValid() || vsCasterID.IsError() || vsCasterID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		
		CString csCasterID = vsCasterID.ToCString();
		CString csMaterialCode=rsPlanOrd.GetFieldByName(_T("MaterialCode")).ToString();
		/*屏蔽 by hyh 2012-06-07
		csMaterialCode=csMaterialCode.Mid(0,3);
		if(csMaterialCode==_T("609"))
		{
			if(csCasterID!=_T("S66"))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
		}
		if(csCasterID==_T("S66"))
		{
			if(csMaterialCode!=_T("609"))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
		}
		屏蔽结束*/

		CString csProdSheetUri = QA_PROD_SHEET_CLASS_URI + _T("\\") + csSteelGradeIndex;
		L3LONG	nCasterType = GetObjectPropValue(csProdSheetUri,_T("Caster_Type")).ToLong();	
		L3LONG  nCasterUnitID = _ttol(csCasterID.Mid(2,1));
		switch(nCasterType)
		{
			case NoLFCaster:
				//2009-01-17 tangyi
				if (nCasterUnitID > 7 || nCasterUnitID < 1) 		
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			case OldLFCaster:
				if (nCasterUnitID > 4 || nCasterUnitID < 3) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			case NewLFCaster:
				if (nCasterUnitID < 5||nCasterUnitID>5) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			//Modify begin 2011-02-15 llj
			case NewLFCaster6:
				if (nCasterUnitID < 6||nCasterUnitID>6) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			case NewLFCaster7:
				if (nCasterUnitID < 7) 
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				};
				break;
			//Modify end
			default:
				{	
					if(bUseTrans)
						Rollback(nTrans);
					return -6;
				};
		}
		L3SHORT nBOFFlag = 0;
		L3LONG	nBOFType = GetObjectPropValue(csProdSheetUri,_T("BOF_Type")).ToLong();
		switch(nBOFType)
		{
			case BOF50t: nBOFFlag = nOldBOF;
				break;
			case BOF80t: nBOFFlag = nNewBOF;
				break;
			default:
				// 2016-1-1 增加 nBOFFlag = nOldBOF;一句
				 nBOFFlag = nOldBOF;
				break;
		}	
		//计算炉次
		
		L3LONG nSteelLadleCount = CalculateHeatCount(nBOFFlag,dSteelWeight);
		//生成浇钢计划
		L3LONG nBackValue = GenCastingPlanOfSpecifyCasterID(csCasterID,
			                                                L3RECORDSET(rsPlanOrd),
															nSteelLadleCount,
															csSteelGradeIndex,
															dSteelWeight,
															nBOFFlag);
		if(nBackValue < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return nBackValue;
		}
		//更改计划订单状态
		CL3Variant vsPlanID = rsPlanOrd.GetFieldByName(_T("PlanID"));
		if(!vsPlanID.IsValid() || vsPlanID.IsError() || vsPlanID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -16;
		}
		CString csPlanID = vsPlanID.ToCString();
		CString csStatus = GetObjectPropValue(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID,_T("Status")).ToCString();
		if(csStatus ==PLAN_ORDER_STATUS_UNINTEGRATE)
		{
			if(!SetObjectPropValue(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanID,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_CASTING)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -17;
			}	
		}
		rsPlanOrd.MoveNext();
	}


	if(bUseTrans)
		Commit(nTrans);

	return 0;// TODO : 请在此添加逻辑代码
}

#pragma endregion



/// <Method class="CPlan_Mag" name="CastingPlanCancel" type="L3BOOL">
/// 
/// 取消铸机浇钢计划，更改订单的状态为2
/// ARG&gt;&gt; rsCastingPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsCastingPlan" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CPlan_Mag::CastingPlanCancel(L3RECORDSET rsCastingPlan)
{
	CL3RecordSetWrap rsPlan =rsCastingPlan;
    if( rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}


	rsPlan.MoveFirst();
	while(!rsPlan.IsEOF())
	{
		////获取计划订单号
		//CL3Variant vsPlanOrder = rsPlan.GetFieldByName(_T("Plan_Ord_ID"));
		//if(!vsPlanOrder.IsValid() || vsPlanOrder.IsError() || vsPlanOrder.IsNull())
		//{
		//	rsPlan.MoveNext();
		//	continue;
		//}
		//CString csPlanOrderID = vsPlanOrder.ToCString();
		////判断计划订单状态
		//CL3Variant vsStatus = GetObjectPropValue(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanOrderID,_T("Status"));
		//if(!vsStatus.IsValid() || vsStatus.IsError() || vsStatus.IsNull())
		//{
		//	rsPlan.MoveNext();
		//	continue;
		//}
		//CString csStatus = vsStatus.ToCString();
		//if(csStatus != PLAN_ORDER_STATUS_CASTING)
		//{
		//	rsPlan.MoveNext();
		//	continue;
		//}
		////删除铸机浇钢计划
		//CString csTemp = _T(" SELECT PlanID  FROM %s  where  Plan_Ord_ID = '%s' ");	
		//CString strSQL;
		//strSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,csPlanOrderID);
		//CL3RecordSetWrap rsResult;
		//BOOL bRet = Query(strSQL,rsResult);		
		//if(!bRet || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		//{
		//	rsPlan.MoveNext();
		//	continue;
		//}
		//rsResult.MoveFirst();
		//if(DeleteOldObjects(PLAN_CASTING_CLASS_URI,L3RECORDSET(rsResult)) < rsResult.GetRowCount())
		//{
		//	if(bUseTrans)
		//		Rollback(nTrans);
		//	return false;
		//}
		////设置计划订单状态为收池
		//if(!SetObjectPropValue(PLAN_ORDER_CLASS_URI + _T("\\") + csPlanOrderID,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_INTEGRATED)))
		//{
		//	if(bUseTrans)
		//		Rollback(nTrans);
		//	return false;
		//}
		//rsPlan.MoveNext();
		//2008-12-24
		CL3Variant vsPlanID = rsPlan.GetFieldByName(_T("PlanID"));
		if(!vsPlanID.IsValid() || vsPlanID.IsError() || vsPlanID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString csPlanID = vsPlanID.ToCString();
		CString csCastingPlanUri = PLAN_CASTING_CLASS_URI + _T("\\") + csPlanID;
		CL3Variant vsStatus = GetObjectPropValue(csCastingPlanUri,_T("Status"));
		if(!vsStatus.IsValid() || vsStatus.IsError() || vsStatus.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString csStatus = vsStatus.ToCString();
		if(csStatus != CASTING_PLAN_STATUS_UNSCHEDULING)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		//获取浇钢计划实际投放量
		CL3Variant vsPlanOrderID = GetObjectPropValue(csCastingPlanUri,_T("Plan_Ord_ID"));
		if(!vsPlanOrderID.IsValid() || vsPlanOrderID.IsError() || vsPlanOrderID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString csPlanOrderID = vsPlanOrderID.ToCString();
		CL3Variant vsCastingPlanActWeight = GetObjectPropValue(csCastingPlanUri,_T("ActWeight"));
		if(!vsCastingPlanActWeight.IsValid() || vsCastingPlanActWeight.IsError() || vsCastingPlanActWeight.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		L3DOUBLE fCastingPlanWeight = vsCastingPlanActWeight.ToDouble();
		//获取计划订单当前实际用量与余量
		CString csPlanOrderUri = PLAN_ORDER_CLASS_URI + _T("\\") + csPlanOrderID;
		CL3Variant vsPlanOrderCurSpareWeight = GetObjectPropValue(csPlanOrderUri,_T("SpareWeight"));
		if(!vsPlanOrderCurSpareWeight.IsValid() || vsPlanOrderCurSpareWeight.IsError() || vsPlanOrderCurSpareWeight.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		L3DOUBLE fPlanOrderSpareWeight = vsPlanOrderCurSpareWeight.ToDouble();
		CL3Variant vsPlanOrderCurActWeight = GetObjectPropValue(csPlanOrderUri,_T("ActWeight"));
		if(!vsPlanOrderCurActWeight.IsValid() || vsPlanOrderCurActWeight.IsError() || vsPlanOrderCurActWeight.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		L3DOUBLE fPlanOrderActWeight = vsPlanOrderCurActWeight.ToDouble();
		if(!SetObjectPropValue(csPlanOrderUri,_T("SpareWeight"),CL3Variant(fPlanOrderSpareWeight + fCastingPlanWeight)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if(!SetObjectPropValue(csPlanOrderUri,_T("ActWeight"),CL3Variant(fPlanOrderActWeight - fCastingPlanWeight)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if(fPlanOrderActWeight - fCastingPlanWeight == 0)
		{
			if(!SetObjectPropValue(csPlanOrderUri,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_UNINTEGRATE)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return false;
			}

		}
		rsPlan.MoveNext();
	}
	//删除浇钢计划
	rsPlan.MoveFirst();
	if(DeleteOldObjects(PLAN_CASTING_CLASS_URI,rsPlan) < rsPlan.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	if(bUseTrans)
		Commit(nTrans);
	return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanGen" type="L3LONG">
/// 
/// 编制出钢计划，更改订单，浇钢计划的状态为4已排产，新生成的出钢计划状态为1未下达
/// ARG&gt;&gt; rsCastingPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
/// <Param name="rsCastingPlan" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CPlan_Mag::TappingPlanGen(L3RECORDSET rsCastingPlan)
{
	CL3RecordSetWrap rsCastPlan =rsCastingPlan;
    if( rsCastPlan.IsNull() || rsCastPlan.GetRowCount() < 1)
		return -1;


	//创建出钢计划记录集
	CL3RecordSetWrap rsTappingPlan;
	if(!CreateClassPropSet(PLAN_TAPPING_CLASS_URI,rsTappingPlan)) 
		return -1;
	rsTappingPlan.AppendRecord();
	rsTappingPlan.MoveFirst();

	//创建出钢计划实绩记录集
	CL3RecordSetWrap rsTappingPlanActual;
	if(!CreateClassPropSet(PLAN_TAPPING_ACT_CLASS_URI,rsTappingPlanActual)) 
		return -1;
	rsTappingPlanActual.AppendRecord();
	rsTappingPlanActual.MoveFirst();


	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -3;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	//创建出钢计划实绩记录集
	CL3RecordSetWrap rsUnSchedulCastingPlan;
	if(!CreateClassPropSet(PLAN_CASTING_CLASS_URI,rsUnSchedulCastingPlan)) 
		return -1;
	rsUnSchedulCastingPlan.DelField(_T("Status"));

	rsCastPlan.MoveFirst();
	
	L3LONG nPlanNum = 0;

	while(!rsCastPlan.IsEOF())
	{
		//判断浇钢计划的状态,如果已排产则继续下一炉
		CL3Variant vsPlaID = rsCastPlan.GetFieldByName(_T("PlanID"));
		if(!vsPlaID.IsValid() || vsPlaID.IsError() || vsPlaID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		CString csPlanID = vsPlaID.ToCString();
		CString csObjUri = PLAN_CASTING_CLASS_URI + _T("\\") + csPlanID;
		CL3Variant vsStatus = GetObjectPropValue(csObjUri,_T("Status"));
		if(!vsStatus.IsValid() || vsStatus.IsError() || vsStatus.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		CString csStatus = vsStatus.ToCString();
		if(csStatus != CASTING_PLAN_STATUS_UNSCHEDULING)
		{
			rsCastPlan.MoveNext();
			continue;
		}
		//判断出钢计划中此计划是否存在，若存在则继续下一炉
		CString csObjTappingUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID;
		CL3Variant vsPlanID = GetObjectPropValue(csObjTappingUri,_T("PlanID"));
		CString csIsExit = vsPlanID.ToCString();
		if(!csIsExit.IsEmpty())
		{
			rsCastPlan.MoveNext();
			continue;
		}

		////铸机号
		CL3Variant vsCasterID = GetObjectPropValue(csObjUri,_T("CasterID"));
		if(!vsCasterID.IsValid() || vsCasterID.IsError() || vsCasterID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -6;
		}
		CString csCasterID = vsCasterID.ToCString();

		//生成出钢计划相应内容
		rsTappingPlan.SetFieldByName(_T("PlanID"),CL3Variant(csPlanID));
		rsTappingPlan.SetFieldByName(_T("PreHeatID"), CL3Variant(csPlanID));
		rsTappingPlan.SetFieldByName(_T("CasterID"),rsCastPlan.GetFieldByName(_T("CasterID")));
		rsTappingPlan.SetFieldByName(_T("SteelGradeIndex"),rsCastPlan.GetFieldByName(_T("Pre_SteelGradeIndex")));
		//rsTappingPlan.SetFieldByName(_T("SteelGrade"),rsCastPlan.GetFieldByName(_T("Pre_SteelGrade")));
		rsTappingPlan.SetFieldByName(_T("Aim_Tapped_Weight"),rsCastPlan.GetFieldByName(_T("Aim_Tapped_Weight")));
		rsTappingPlan.SetFieldByName(_T("BOF_Status"),CL3Variant(TAPPING_PLAN_BOF_STATUS_UNEXCUTING));
		rsTappingPlan.SetFieldByName(_T("RH_Status"),CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING));
		rsTappingPlan.SetFieldByName(_T("LF_Status"),CL3Variant(TAPPING_PLAN_LF_STATUS_UNEXCUTING));
		rsTappingPlan.SetFieldByName(_T("Caster_Status"),CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING));
		rsTappingPlan.SetFieldByName(_T("Side_Status"),CL3Variant(TAPPING_PLAN_SIDE_STATUS_UNEXCUTING));
		rsTappingPlan.SetFieldByName(_T("Pre_SteelGradeIndex"),rsCastPlan.GetFieldByName(_T("Pre_SteelGradeIndex")));
		rsTappingPlan.SetFieldByName(_T("Pre_SteelGrade"),rsCastPlan.GetFieldByName(_T("Pre_SteelGrade")));
		rsTappingPlan.SetFieldByName(_T("Plan_Ord_ID"),rsCastPlan.GetFieldByName(_T("Plan_Ord_ID")));
		rsTappingPlan.SetFieldByName(_T("Refine_Type"),rsCastPlan.GetFieldByName(_T("Refine_Type")));
		rsTappingPlan.SetFieldByName(_T("New_BOF_Flag"),rsCastPlan.GetFieldByName(_T("New_BOF_Flag")));
		rsTappingPlan.SetFieldByName(_T("Length"),rsCastPlan.GetFieldByName(_T("Length")));
		rsTappingPlan.SetFieldByName(_T("Width"),rsCastPlan.GetFieldByName(_T("Width")));
		rsTappingPlan.SetFieldByName(_T("Thickness"),rsCastPlan.GetFieldByName(_T("Thickness")));
		rsTappingPlan.SetFieldByName(_T("CreateDate"), COleDateTime::GetCurrentTime());
		rsTappingPlan.SetFieldByName(_T("Status"),CL3Variant(TAPPING_PLAN_STATUS_UNSEND));
		rsTappingPlan.SetFieldByName(_T("Planner"),CL3Variant(GetCurrentUser()));
		//2008-12-09新增
		rsTappingPlan.SetFieldByName(_T("LFID"),rsCastPlan.GetFieldByName(_T("LFID")));
		rsTappingPlan.SetFieldByName(_T("RHID"),rsCastPlan.GetFieldByName(_T("RHID")));
		rsTappingPlan.SetFieldByName(_T("BOFID"),rsCastPlan.GetFieldByName(_T("BOFID")));

		
		//用精练区分和铸机号确定RH\LF炉座,不经过设置为-1
		CL3Variant vsRefineType = rsCastPlan.GetFieldByName(_T("Refine_Type"));
		if(!vsRefineType.IsValid() || vsRefineType.IsError() || vsRefineType.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -10;
		}
		CString csRefineType = vsRefineType.ToCString();
		//铸机开浇时间
		CL3Variant vsCastignStart = rsCastPlan.GetFieldByName(_T("Aim_Time_CastingStart"));
		if(!vsCastignStart.IsValid() || vsCastignStart.IsError() || vsCastignStart.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -11;
		}
		L3DATETIME dtCastingStart = vsCastignStart.ToDateTime();

		L3DATETIME dtAim_IronPrepareTime = 0; //兑铁时间
		L3DATETIME dtAim_BOFProcessTime = 0;  //转炉处理时间
		L3DATETIME dtAim_LFWaitTime = 0; //LF等待时间
		L3DATETIME dtAim_RHWaitTime = 0; //RH等待时间
		L3DATETIME dtAim_LFProcessTime = 0;//LF炉处理时间
		L3DATETIME dtAim_RHProcessTime = 0;//RH炉处理时间
		L3DATETIME dtAim_CastWaitedTime = 0;//铸机等待时间
		L3DATETIME dtAim_CastingTime = 0;//浇注时间
		L3DATETIME dtAim_BOFSideTime = 0;//炉后处理时间
		L3DATETIME dtAim_Time_CastingEnd = 0;//浇注结束时刻
		L3DATETIME dtAim_Time_CasterArrival = 0;//大包到达时刻
		L3DATETIME dtAim_Time_RHArrival = 0;//RH进站时刻
		L3DATETIME dtAim_Time_RHLeave = 0;//RH出站时刻
		L3DATETIME dtAim_Time_RHEnd = 0;//RH处理结束时刻
		L3DATETIME dtAim_Time_RHStart = 0;//RH处理开始时刻
		L3DATETIME dtAim_Time_LFArrival = 0;//LF进站时刻
		L3DATETIME dtAim_Time_LFLeave = 0;//LF出站时刻
		L3DATETIME dtAim_Time_LFEnd = 0;//LF处理结束时刻
		L3DATETIME dtAim_Time_LFStart = 0;;//LF处理开始时刻
		L3DATETIME dtAim_Time_BOFSided = 0;//炉后F处理结束时刻
		L3DATETIME dtAim_Time_BOFTapped = 0;//出钢结束时刻
		L3DATETIME dtAim_Time_BOFStart = 0;//开吹时刻
		L3DATETIME dtAim_Time_IronPrepared = 0;//兑铁时刻

		//计算各工位处理时刻
		CString csTemp = _T("Select * from %s where SteelGradeIndex = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,QA_UNIT_PROC_TIME_CLASS_URI,rsCastPlan.GetFieldByName(_T("Pre_SteelGradeIndex")).ToCString());
		CL3RecordSetWrap rsTime;
		if(!Query(csSQL,rsTime) || rsTime.IsNull() || rsTime.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -12;
		}
		rsTime.MoveFirst();
		//转炉
		CL3Variant vsTempTime  = rsTime.GetFieldByName(_T("BOF_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -13;
		}
		dtAim_BOFProcessTime = (vsTempTime.ToDateTime())/1440;
		//LF
		vsTempTime  = rsTime.GetFieldByName(_T("LF_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -14;
		}
		dtAim_LFProcessTime = (vsTempTime.ToDateTime())/1440;
		//RH
		vsTempTime  = rsTime.GetFieldByName(_T("RH_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -15;
		}
		dtAim_RHProcessTime = (vsTempTime.ToDateTime())/1440;
		//铸机
		vsTempTime  = rsTime.GetFieldByName(_T("Caster_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -16;
		}
		dtAim_CastingTime = (vsTempTime.ToDateTime())/1440;
		//炉后
		vsTempTime  = rsTime.GetFieldByName(_T("Tapped_Proc_Time"));
		if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -17;
		}
		dtAim_BOFSideTime = (vsTempTime.ToDateTime())/1440;

		dtAim_IronPrepareTime = BOF_PREPARED_TIME/1440;
		dtAim_CastWaitedTime  = CASTING_WAITED_TIME/1440;
		dtAim_LFWaitTime = 5/1440;
		dtAim_RHWaitTime = 5/1440;


		//计算标准工艺时间
		dtAim_Time_CastingEnd = dtCastingStart + dtAim_CastingTime;
		dtAim_Time_CasterArrival = dtCastingStart - dtAim_CastWaitedTime;
		if(csRefineType == _T("0"))
		{
			dtAim_Time_RHArrival = 0;
			dtAim_Time_RHEnd = 0;
			dtAim_Time_RHStart = 0;
			dtAim_Time_RHLeave = 0;
			dtAim_Time_LFArrival = 0;
			dtAim_Time_LFEnd = 0;
			dtAim_Time_LFStart = 0;
			dtAim_Time_LFLeave = 0;
			dtAim_Time_BOFSided = dtAim_Time_CasterArrival;
		}
		else
		{
			if(csRefineType == _T("L"))
			{
				dtAim_Time_RHArrival = 0;
				dtAim_Time_RHEnd = 0;
				dtAim_Time_RHStart = 0;
				dtAim_Time_RHLeave = 0;
				dtAim_Time_LFLeave = dtAim_Time_CasterArrival;
				dtAim_Time_LFEnd = dtAim_Time_LFLeave - dtAim_LFWaitTime;
				dtAim_Time_LFStart = dtAim_Time_LFEnd - dtAim_LFProcessTime;
				dtAim_Time_LFArrival = dtAim_Time_LFStart - dtAim_LFWaitTime;
				dtAim_Time_BOFSided = dtAim_Time_LFArrival;
			}
			else
			{
				if(csRefineType == _T("R"))
				{
					dtAim_Time_LFArrival = 0;
					dtAim_Time_LFEnd = 0;
					dtAim_Time_LFStart = 0;
					dtAim_Time_LFLeave = 0;
					dtAim_Time_RHLeave = dtAim_Time_CasterArrival;
					dtAim_Time_RHEnd = dtAim_Time_RHLeave - dtAim_RHWaitTime;
					dtAim_Time_RHStart = dtAim_Time_RHEnd - dtAim_RHProcessTime;
					dtAim_Time_RHArrival = dtAim_Time_RHStart - dtAim_RHWaitTime;
					dtAim_Time_BOFSided = dtAim_Time_RHArrival;

				}
				else
				{
					if(csRefineType == _T("LR"))
					{
						dtAim_Time_RHLeave = dtAim_Time_CasterArrival;
						dtAim_Time_RHEnd = dtAim_Time_RHLeave - dtAim_RHWaitTime;
						dtAim_Time_RHStart = dtAim_Time_RHEnd - dtAim_RHProcessTime;
						dtAim_Time_RHArrival = dtAim_Time_RHStart - dtAim_RHWaitTime;
						dtAim_Time_LFLeave = dtAim_Time_RHArrival;
						dtAim_Time_LFEnd = dtAim_Time_LFLeave - dtAim_LFWaitTime;
						dtAim_Time_LFStart = dtAim_Time_LFEnd - dtAim_LFProcessTime;
						dtAim_Time_LFArrival = dtAim_Time_LFStart - dtAim_LFWaitTime;
						dtAim_Time_BOFSided = dtAim_Time_LFArrival;

					}
					else
					{
						dtAim_Time_LFLeave = dtAim_Time_CasterArrival;
						dtAim_Time_LFEnd = dtAim_Time_LFLeave - dtAim_LFWaitTime;
						dtAim_Time_LFStart = dtAim_Time_LFEnd - dtAim_LFProcessTime;
						dtAim_Time_LFArrival = dtAim_Time_LFStart - dtAim_LFWaitTime;
						dtAim_Time_RHLeave = dtAim_Time_LFArrival;
						dtAim_Time_RHEnd = dtAim_Time_RHLeave - dtAim_RHWaitTime;
						dtAim_Time_RHStart = dtAim_Time_RHEnd - dtAim_RHProcessTime;
						dtAim_Time_RHArrival = dtAim_Time_RHStart - dtAim_RHWaitTime;
						dtAim_Time_BOFSided = dtAim_Time_RHArrival;
					}

				}
			}

		}
		//dtAim_Time_BOFSided = dtAim_Time_LFStart;
		dtAim_Time_BOFTapped = dtAim_Time_BOFSided - dtAim_BOFSideTime;
		dtAim_Time_BOFStart = dtAim_Time_BOFTapped - dtAim_BOFProcessTime;
		dtAim_Time_IronPrepared = dtAim_Time_BOFStart - dtAim_IronPrepareTime;
		//对出钢计划工序处理时刻赋值
		rsTappingPlan.SetFieldByName(_T("Aim_Time_CastingEnd"), dtAim_Time_CastingEnd);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_CastingStart"), dtCastingStart);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_CasterArrival"), dtAim_Time_CasterArrival);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_RHLeave"), dtAim_Time_RHLeave);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_RHEnd"), dtAim_Time_RHEnd);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_RHStart"), dtAim_Time_RHStart);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_RHArrival"), dtAim_Time_RHArrival);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_LFLeave"), dtAim_Time_LFLeave);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_LFEnd"), dtAim_Time_LFEnd);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_LFStart"), dtAim_Time_LFStart);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_LFArrival"), dtAim_Time_LFArrival);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_TappedSideEnd"), dtAim_Time_BOFSided);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_BOFTapped"), dtAim_Time_BOFTapped);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_BOFStart"), dtAim_Time_BOFStart);
		rsTappingPlan.SetFieldByName(_T("Aim_Time_IronPrepared"), dtAim_Time_IronPrepared);


		//计算处理顺序号
		csTemp = _T( " select  max(Treat_Seq) from %s where CasterID = '%s' and to_char(CreateDate,'yyyy') = to_char(sysdate,'yyyy') " );
		csSQL.Format(csTemp,PLAN_TAPPING_CLASS_URI,csCasterID);
		CL3RecordSetWrap rsTreatSeq;
		if ((!Query(csSQL,rsTreatSeq)))
		{
			rsCastPlan.MoveNext();
			continue;
		}
		rsTreatSeq.MoveFirst();
		CL3Variant valTemp = rsTreatSeq.GetFieldByIndex(0);
		CString csMaxTreatSeq = valTemp.ToCString();
		L3LONG nMaxTreatSeq;
		if (csMaxTreatSeq.IsEmpty())
			nMaxTreatSeq =0;
		else
		{
			CString csSeq = csMaxTreatSeq.Mid(2,5);
			//nMaxTreatSeq = csSeq.ToShort();
			nMaxTreatSeq = _ttol(csSeq);	
		}
		nMaxTreatSeq++;
		CString csTempTreatSeq;
		csTempTreatSeq.Format(_T("%05d"), nMaxTreatSeq);
		COleDateTime odtCurrentDate = COleDateTime::GetCurrentTime();
		CString cstrCurrentDate = odtCurrentDate.Format(_T("%Y"));
		CString csTreatSeq =cstrCurrentDate.Mid(2,2) + csTempTreatSeq;

		rsTappingPlan.SetFieldByName(_T("Treat_Seq"), CL3Variant(csTreatSeq));
		//班别班次
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
		rpSysInfo.MoveFirst();

		rsTappingPlan.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsTappingPlan.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));


		//2008-12-09新增以下代码
		//创建出钢计划实绩记录集
		//重新生成出钢计划实绩,并且计算熔炼号、工序处理号

		//得到预定炉号
		rsTappingPlanActual.SetFieldByName(_T("PreHeatID"), CL3Variant(csPlanID));
		rsTappingPlanActual.SetFieldByName(_T("CasterID"),rsCastPlan.GetFieldByName(_T("CasterID")));
		rsTappingPlanActual.SetFieldByName(_T("LFID"),rsCastPlan.GetFieldByName(_T("LFID")));
		rsTappingPlanActual.SetFieldByName(_T("RHID"),rsCastPlan.GetFieldByName(_T("RHID")));
		rsTappingPlanActual.SetFieldByName(_T("BOFID"),rsCastPlan.GetFieldByName(_T("BOFID")));

		//得到熔炼号
		L3SHORT nUnitType = UNIT_AREA_BOF;
		CString csBOFID =  rsCastPlan.GetFieldByName(_T("BOFID")).ToCString();
		long lTemp = GetHeatMaxProcessNo(nUnitType,csBOFID) + 1;		//循环次数为i + 1
		CString csTempHeatID;
		csTempHeatID.Format(_T("%05d"),lTemp);	//不足5位的前面补0
		CString csHeatID =_T("2") + csBOFID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempHeatID;
		rsTappingPlanActual.SetFieldByName(_T("HeatID"), CL3Variant(csHeatID));
		rsTappingPlan.SetFieldByName(_T("HeatID"), CL3Variant(csHeatID));
		//初始化处理号为零2008-12-30 tangyi
		rsTappingPlanActual.SetFieldByName(_T("LF_TreatNo"), CL3Variant(_T("")));
		rsTappingPlanActual.SetFieldByName(_T("RH_TreatNo"),CL3Variant(_T("")));
		rsTappingPlanActual.SetFieldByName(_T("Caster_TreatNo"), CL3Variant(_T("")));

		//2008-12-30 tangyi 因各工序都独立的计算处理号，故排产时处理号不计算，最后实绩采用工序实际处理号。屏蔽以下代码
		//LF处理号
		//CString csLFTreatNo =_T("0");
		//valTemp = rsCastPlan.GetFieldByName(_T("LFID")).ToCString();
		//if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		//{
		//	if(bUseTrans)
		//		Rollback(nTrans);
		//	return -23;
		//}
		//CString csLFID = valTemp.ToCString();
		//if(csLFID!=_T("0"))
		//{
		//	nUnitType = UNIT_AREA_LF;
		//	lTemp = GetHeatMaxProcessNo(nUnitType, csLFID) + 1;		//循环次数为i + 1
		//	CString csTempTreatNo;
		//	csTempTreatNo.Format(_T("%05d"), lTemp);
		//	csLFTreatNo = csLFID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempTreatNo;
		//}
		//rsTappingPlanActual.SetFieldByName(_T("LF_TreatNo"), CL3Variant(csLFTreatNo));

		////RH处理号
		//CString csRHTreatNo =_T("0");
		//valTemp = rsCastPlan.GetFieldByName(_T("RHID")).ToCString();
		//if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		//{
		//	if(bUseTrans)
		//		Rollback(nTrans);
		//	return -24;
		//}
		//CString csRHID = valTemp.ToCString();
		//if(csRHID!=_T("0"))
		//{
		//	nUnitType = UNIT_AREA_RH;
		//	lTemp = GetHeatMaxProcessNo(nUnitType, csRHID) + 1;		//循环次数为i + 1
		//	CString csTempTreatNo;
		//	csTempTreatNo.Format(_T("%05d"), lTemp);
		//	csRHTreatNo = csRHID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempTreatNo;
		//}
		//rsTappingPlanActual.SetFieldByName(_T("RH_TreatNo"),CL3Variant(csRHTreatNo));

		////得到铸机处理号
		//nUnitType = UNIT_AREA_CASTER;
		//lTemp = GetHeatMaxProcessNo(nUnitType, csCasterID) + 1;		//循环次数为i + 1
		//CString csTempTreatNo;
		//csTempTreatNo.Format(_T("%05d"), lTemp);
		//CString csCasterTreatNo = csCasterID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempTreatNo;
		//rsTappingPlanActual.SetFieldByName(_T("Caster_TreatNo"), CL3Variant(csCasterTreatNo));

		rsTappingPlanActual.SetFieldByName(_T("CreateDate"), COleDateTime::GetCurrentTime());

		//创建出钢计划
		if(CreateNewObjects(PLAN_TAPPING_CLASS_URI,L3RECORDSET(rsTappingPlan)) < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -18;
		}
		//创建对象CHeatTappingPlanActualData
		if (CreateNewObjects(PLAN_TAPPING_ACT_CLASS_URI,rsTappingPlanActual) < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -26;
		}	
		//更改浇钢计划状态
		if(!SetObjectPropValue(csObjUri,_T("Status"),CL3Variant(CASTING_PLAN_STATUS_SCHEDULED)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -19;
		}
		//更改计划订单状态
		CString csObjPlanOrdUri = PLAN_ORDER_CLASS_URI + _T("\\") + rsCastPlan.GetFieldByName(_T("Plan_Ord_ID")).ToCString();
		if(!SetObjectPropValue(csObjPlanOrdUri,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_TAPPING)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -20;
		}

		//2009-05-27 计算工序间移动时间
		CalcUnitOneToOneTime(csPlanID);


		rsUnSchedulCastingPlan.AppendRecord();
		rsUnSchedulCastingPlan.CopyCurRowFrom(rsCastPlan);
		nPlanNum++;
		rsTappingPlan.MoveFirst();
		rsTappingPlanActual.MoveFirst();
		rsCastPlan.MoveNext();
	}

	//回执浇钢计划信息（转炉、精炼）2008-12-24
	if(nPlanNum > 0)
	{
		if(!SetObjsPropValues(PLAN_CASTING_CLASS_URI,rsUnSchedulCastingPlan))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -27;
		}
	}

	//2008-12-09屏蔽以下代码
	//老转炉
	//if(nPlanNum > 0)
	//{
	//	L3LONG nBackVal = CalBOFIDAndReGenTappingAct(nOldBOF);
	//	if(nBackVal < 0)
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return nBackVal;
	//	}
	//	//新转炉
	//	nBackVal = CalBOFIDAndReGenTappingAct(nNewBOF);
	//	if(nBackVal < 0)
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return nBackVal;
	//	}

	//}


	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();
	if(nPlanNum ==0) return -28; else return 0;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanCancel" type="L3BOOL">
/// 
/// 取消出钢计划，更改浇钢计划的状态为1未排产，如果订单下的浇钢计划状态全为1则更改订单的状态为3
/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CPlan_Mag::TappingPlanCancel(L3RECORDSET rsTappingPlan)
{
	CL3RecordSetWrap rsPlan =rsTappingPlan;
    if( rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	//rsPlan.MoveFirst();
	rsPlan.MoveLast();
	//while(!rsPlan.IsEOF())
	L3LONG nCount =0;
	for(int i=0;i < rsPlan.GetRowCount();i++)
	{
		CL3Variant vsPlanID = rsPlan.GetFieldByName(_T("PlanID"));
		if(!vsPlanID.IsValid() || vsPlanID.IsError() || vsPlanID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString csPlanID = vsPlanID.ToCString();
		CString csObjPlanUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID;
		CString csObjPlanActUri = PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPlanID;
		CL3Variant vsStatus = GetObjectPropValue(csObjPlanUri,_T("Status"));
		if(!vsStatus.IsValid() || vsStatus.IsError() || vsStatus.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString csStatus = vsStatus.ToCString();
		if(csStatus != TAPPING_PLAN_STATUS_UNSEND)
		{
			//rsPlan.MoveNext();
			rsPlan.MovePrev();
			continue;
		}

		//下一炉还存在,不允许当前炉取消20081222 tangyi
		CString csHeatID = GetObjectPropValue(csObjPlanUri,_T("HeatID")).ToCString();
		csHeatID.Trim();
		CString csBofProcessSeq=csHeatID.Mid(4,5);
		CString csYearID=csHeatID.Mid(0,4);
		L3LONG nNextBOFTreateNo = _ttol(csBofProcessSeq) + 1;
		CString csFinalHeatID;
		csFinalHeatID.Format(_T("%05d"),nNextBOFTreateNo);
		csFinalHeatID=csYearID + csFinalHeatID;
		CString csSQL;
		csSQL.Format(_T(" select PlanID from CPlan_Tapping where HeatID ='%s' "),csFinalHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSQL,rs))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if(rs.GetRowCount() > 0)
		{
			//rsPlan.MoveNext();
			rsPlan.MovePrev();
			continue;
		}

		if(!DeleteOldObject(csObjPlanUri))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if(!DeleteOldObject(csObjPlanActUri))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString csObjCastUri = PLAN_CASTING_CLASS_URI + _T("\\") + csPlanID;  
		if(!SetObjectPropValue(csObjCastUri,_T("Status"),CL3Variant(CASTING_PLAN_STATUS_UNSCHEDULING)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		//判断计划订单下的浇钢计划状态是否都为未排产
		CL3Variant vsPlanOrdID = GetObjectPropValue(csObjCastUri,_T("Plan_Ord_ID"));
		if(!vsPlanOrdID.IsValid() || vsPlanOrdID.IsError() || vsPlanOrdID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString csPlanOrdID = vsPlanOrdID.ToCString();
		CString csTemp = _T(" select * from %s where Plan_Ord_ID = '%s' ");
		csSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,csPlanOrdID);
		CL3RecordSetWrap rsPlanCout1;
		if(!Query(csSQL,rsPlanCout1))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		csTemp = _T(" select * from %s where Plan_Ord_ID = '%s' and Status = %s ");
		csSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,csPlanOrdID,CASTING_PLAN_STATUS_UNSCHEDULING);
		CL3RecordSetWrap rsPlanCout2;
		if(!Query(csSQL,rsPlanCout2))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if(rsPlanCout1.GetRowCount() == rsPlanCout2.GetRowCount())
		{
			CString csObjPlanOrdUri = PLAN_ORDER_CLASS_URI + _T("\\") + csPlanOrdID;  
			if(!SetObjectPropValue(csObjPlanOrdUri,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_CASTING)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return false;
			}

		}
		//rsPlan.MoveNext();
		rsPlan.MovePrev();
		nCount++;
	}

	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

   if(nCount ==0) return false;   else 	return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanSend" type="L3BOOL">
/// 
/// 出钢计划下达，更改出钢计划的状态为2
/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CPlan_Mag::TappingPlanSend(L3RECORDSET rsTappingPlan)
{
	CL3RecordSetWrap rsPlan =rsTappingPlan;
    if( rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	rsPlan.MoveFirst();
	L3LONG ncount =0;
	while(!rsPlan.IsEOF())
	{
		CL3Variant vsPlaID = rsPlan.GetFieldByName(_T("PlanID"));
		CString csPlanID = vsPlaID.ToCString();
		CString csPlanUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID;
		CL3Variant vsStatus = GetObjectPropValue(csPlanUri,_T("Status"));
		CString csStatus = vsStatus.ToCString();
		if(csStatus != TAPPING_PLAN_STATUS_UNSEND)
		{
			rsPlan.MoveNext();
			continue;
		}
		//判断转炉上一炉的状态
		CString csHeatID = GetObjectPropValue(csPlanUri,_T("HeatID")).ToCString();
		CString csLastStatus = GetSomeHeatStatus(csHeatID,LastHeat);
		if(csLastStatus == TAPPING_PLAN_STATUS_UNSEND)
		{
			rsPlan.MoveNext();
			continue;
		}
		if(!SetObjectPropValue(csPlanUri,_T("Status"),CL3Variant(TAPPING_PLAN_STATUS_SEND)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		//产生钢包计划 2008-12-26 tangyi 屏蔽
		/*CString csLadleUri = CLADLE_PLAN_URI + _T("\\") + csPlanID;
		if(CreateNewObject(CLADLE_PLAN_URI,CL3Variant(csPlanID)))
		{
			CString csTemp;
			csTemp.Format(_T("select * from %s where PlanID ='%s'"),PLAN_TAPPING_CLASS_URI,csPlanID);
			CL3RecordSetWrap rsLadlePlan;
			if(!Query(csTemp,rsLadlePlan) || rsLadlePlan.IsNull() ||rsLadlePlan.GetRowCount() !=1 )
			{
				if(bUseTrans)
					Rollback(nTrans);
				return false;
			}
			rsLadlePlan.MoveFirst();
			if(SetObjPropValues(csLadleUri,L3RECORDSET(rsLadlePlan)) < 1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return false;
			}
			
			if(!SetObjectPropValue(csLadleUri,_T("Status"),CL3Variant(CLADLE_PLAN_STATUS_UNDESIGN)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return false;
			}
			if(!SetObjectPropValue(csLadleUri,_T("CreateDate"),CL3Variant(COleDateTime::GetCurrentTime())))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return false;
			}
		}*/
		rsPlan.MoveNext();
		ncount++;
	}

	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

	//CL3Variant varEvent = GetObjectPropValue(CLADLE_MAG_OBJ_URI,_T("LadlePlanEvent"));
	//L3LONG nEvent = varEvent.ToLong();
	//nEvent = (nEvent+1) % 9999;
	//SetObjectPropValue(CLADLE_MAG_OBJ_URI,_T("LadlePlanEvent"),nEvent);

	if (ncount ==0) return false; else return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanSndCancel" type="L3BOOL">
/// 
/// 出钢计划下达取消，更改出钢计划的状态为1
/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CPlan_Mag::TappingPlanSndCancel(L3RECORDSET rsTappingPlan)
{
	CL3RecordSetWrap rsPlan =rsTappingPlan;
    if( rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	rsPlan.MoveLast();
	L3LONG nCount =0;
	for(int i=0;i< rsPlan.GetRowCount();i++)
	{
		CL3Variant vsPlaID = rsPlan.GetFieldByName(_T("PlanID"));
		CString csPlanID = vsPlaID.ToCString();
		CString csPlanUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID;
		CL3Variant vsStatus = GetObjectPropValue(csPlanUri,_T("Status"));
		CString csStatus = vsStatus.ToCString();
		if(csStatus != TAPPING_PLAN_STATUS_SEND)
		{
			rsPlan.MovePrev();
			continue;
		}
		//查看当前转炉下一炉的状态
		CString csHeatID = GetObjectPropValue(csPlanUri,_T("HeatID")).ToCString();
		CString csLastStatus = GetSomeHeatStatus(csHeatID,NextHeat);
		if(csLastStatus != TAPPING_PLAN_STATUS_UNSEND)
		{
			rsPlan.MovePrev();
			continue;
		}
		if(!SetObjectPropValue(csPlanUri,_T("Status"),CL3Variant(TAPPING_PLAN_STATUS_UNSEND)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		////回收钢包计划 2008-12-26 tangyi 屏蔽
		//CString csLadelPlanUri = CLADLE_PLAN_URI + _T("\\") + csPlanID;
		//CString csIsExist = GetObjectPropValue(csLadelPlanUri,_T("PlanID")).ToCString();
		//if(!csIsExist.IsEmpty())
		//{
		//	CString csLadleID =  GetObjectPropValue(csLadelPlanUri,_T("LadleID")).ToCString();
		//	if(!csLadleID.IsEmpty())
		//	{
		//		CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		//		if (!SetObjectPropValue(csLadleUri,_T("Status"),CL3Variant(CLADLE_STATUS_HOT)))
		//		{
		//			if(bUseTrans)
		//				Rollback(nTrans);
		//			return false;
		//		}
		//	}
		//	if (!DeleteOldObject(csLadelPlanUri))
		//	{
		//		if(bUseTrans)
		//			Rollback(nTrans);
		//		return false;
		//	}

		//}
		rsPlan.MovePrev();
		nCount++;
	}

	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

	//CL3Variant varEvent = GetObjectPropValue(CLADLE_MAG_OBJ_URI,_T("LadlePlanEvent"));
	//L3LONG nEvent = varEvent.ToLong();
	//nEvent = (nEvent+1) % 9999;
	//SetObjectPropValue(CLADLE_MAG_OBJ_URI,_T("LadlePlanEvent"),nEvent);

	if(nCount == 0) return false;else return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanDestCfm" type="L3BOOL">
/// 
/// 出钢计划去向确认
/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
/// &gt;&gt;strDestination：去向
/// &gt;&gt;nHotFlag：热送标志
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
/// <Param name="strDestination" type="L3STRING"></Param>
/// <Param name="nHotFlag" type="L3LONG"></Param>
/// </Method>
L3BOOL CPlan_Mag::TappingPlanDestCfm(L3RECORDSET rsTappingPlan)
{
	CL3RecordSetWrap rsPlan =rsTappingPlan;
    if( rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	rsPlan.MoveFirst();
	while(!rsPlan.IsEOF())
	{
		CL3Variant vsPlaID = rsPlan.GetFieldByName(_T("PlanID"));
		if(!vsPlaID.IsValid() || vsPlaID.IsError() || vsPlaID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString csPlanID = vsPlaID.ToCString();
		CString csObjectUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID;
		if(!SetObjectPropValue(csObjectUri,_T("Destitation"),rsPlan.GetFieldByName(_T("Destitation"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if(!SetObjectPropValue(csObjectUri,_T("Hot_Send_Flag"),rsPlan.GetFieldByName(_T("Hot_Send_Flag"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		rsPlan.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanEnd" type="L3BOOL">
/// 
/// 出钢计划强制结束
/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
/// <Param name="strDestination" type="L3STRING"></Param>
/// <Param name="nHotFlag" type="L3LONG"></Param>
/// </Method>
L3BOOL CPlan_Mag::TappingPlanEnd(L3RECORDSET rsTappingPlan)
{
	CL3RecordSetWrap rsPlan =rsTappingPlan;
    if( rsPlan.IsNull() || rsPlan.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	rsPlan.MoveFirst();
	while(!rsPlan.IsEOF())
	{
		CL3Variant vsPlaID = rsPlan.GetFieldByName(_T("PlanID"));
		if(!vsPlaID.IsValid() || vsPlaID.IsError() || vsPlaID.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString csPlanID = vsPlaID.ToCString();
		CString csObjectUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID;
		if(!SetObjectPropValue(csObjectUri,_T("Status"),CL3Variant(TAPPING_PLAN_STATUS_EXCUTED)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}

		rsPlan.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

	return true;// TODO : 请在此添加逻辑代码
}


/// <Method class="CPlan_Mag" name="TappingPlanExchange" type="L3LONG">
/// 
/// 炉座交换
/// ARG&gt;&gt; PreHeatID1 : 预定炉号1。
///  &gt;&gt;PreHeatID2 : 预定炉号2。
/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
/// <Param name="PreHeatID1" type="L3STRING">预定炉号</Param>
/// <Param name="PreHeatID2" type="L3STRING">预定炉号</Param>
/// </Method>
L3LONG CPlan_Mag::TappingPlanExchange(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
    if( rs.IsNull() || rs.GetRowCount() !=2 )
		return -1;
	if(rs.GetFieldIndex(_T("PlanID")) < 0 )
		return -1;

	rs.MoveFirst();
	CString csPreHeatID1 = rs.GetFieldByName(_T("PlanID")).ToCString();
	rs.MoveNext();
	CString csPreHeatID2 = rs.GetFieldByName(_T("PlanID")).ToCString();

	//交换计划类
	CString cstrURI1 = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID1 ;
	CString cstrURI2 = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID2 ;

	//获取新转炉标志
	CL3Variant valTemp = GetObjectPropValue(cstrURI1, _T("New_BOF_Flag"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT nNewBOFFlag1 = valTemp.ToShort();

	valTemp = GetObjectPropValue(cstrURI2, _T("New_BOF_Flag"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT nNewBOFFlag2 = valTemp.ToShort();
	//新旧转炉之间不允许交换
	if(nNewBOFFlag1 != nNewBOFFlag2) return -3;

	//铸机开浇不允许交换
	valTemp = GetObjectPropValue(cstrURI1, _T("Caster_Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull() || valTemp.ToLong() > 2)
		return -4;
	L3SHORT nCasterExecuteStatus1 = valTemp.ToShort();
	valTemp = GetObjectPropValue(cstrURI2, _T("Caster_Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull() || valTemp.ToLong() > 2)
		return -4;	
	L3SHORT nCasterExecuteStatus2 = valTemp.ToShort();

	//炉次分割不允许交换
	valTemp = GetObjectPropValue(cstrURI1, _T("Div_HeatID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull() || !valTemp.ToCString().IsEmpty())
		return -10;
	valTemp = GetObjectPropValue(cstrURI2, _T("Div_HeatID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull() || !valTemp.ToCString().IsEmpty())
		return -10;

	//获取计划1工序状态
	valTemp = GetObjectPropValue(cstrURI1, _T("RH_Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT nRHExecuteStatus1 = valTemp.ToShort();

	valTemp = GetObjectPropValue(cstrURI1, _T("LF_Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT nLFExecuteStatus1 = valTemp.ToShort();

	valTemp = GetObjectPropValue(cstrURI1, _T("Side_Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT nSideExecuteStatus1 = valTemp.ToShort();
	//获取计划2工序状态
	valTemp = GetObjectPropValue(cstrURI2, _T("RH_Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT nRHExecuteStatus2 = valTemp.ToShort();
	
	valTemp = GetObjectPropValue(cstrURI2, _T("LF_Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT nLFExecuteStatus2 = valTemp.ToShort();

	valTemp = GetObjectPropValue(cstrURI2, _T("Side_Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT nSideExecuteStatus2 = valTemp.ToShort();

	//得到计划执行状态
	valTemp = GetObjectPropValue(cstrURI1, _T("Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT ExecutionStatus1 = valTemp.ToShort();

	valTemp = GetObjectPropValue(cstrURI2, _T("Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	L3SHORT ExecutionStatus2 = valTemp.ToShort();

	//获取精炼区分标志
	valTemp = GetObjectPropValue(cstrURI1, _T("Refine_Type"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	CString csRefineTypeFlag1 = valTemp.ToCString();

	valTemp = GetObjectPropValue(cstrURI2, _T("Refine_Type"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -2;
	CString csRefineTypeFlag2 = valTemp.ToCString();


	//铸机相同交换处理顺序、不同不交换处理顺序2009-06-01
	valTemp = GetObjectPropValue(cstrURI1, _T("CasterID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull() || valTemp.ToLong() > 2)
		return -1;
	CString csCasterID1 = valTemp.ToCString();

	valTemp = GetObjectPropValue(cstrURI2, _T("CasterID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull() || valTemp.ToLong() > 2)
		return -1;
	CString csCasterID2 = valTemp.ToCString();	

	CString csTreatSeqCondition;
	if(csCasterID1 == csCasterID2)
		csTreatSeqCondition = _T(" Treat_Seq, ");
	else
		csTreatSeqCondition = _T(" ");

	//按计划执行状态确定交换内容

	//查询出钢计划内容
	CString cstrSQL;

	//开浇之前可以交换炉座
	if (max(nCasterExecuteStatus1, nCasterExecuteStatus2) > 1)
	{
		//钢包上回转台,经过精炼与不经过精炼的炉次不允许交换（工艺路径不允许）
		//if((csRefineTypeFlag1 ==_T("0") && csRefineTypeFlag2!=_T("0")) || (csRefineTypeFlag2 ==_T("0") && csRefineTypeFlag1!=_T("0"))) 
		//	return -11;

		//钢包上回转台,精炼区分不相同不允许交换（工艺路径不允许）2009-03-13 修改
		if(csRefineTypeFlag1 != csRefineTypeFlag2)
			return -11;

		cstrSQL = _T(" Select BOFID,LFID,RHID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,");
	    cstrSQL+= _T(" Aim_Time_LFArrival,Aim_Time_LFStart,Aim_Time_LFEnd,Aim_Time_LFLeave,Aim_Time_RHArrival,Aim_Time_RHStart, ");
		cstrSQL+= _T(" Aim_Time_RHEnd,Aim_Time_RHLeave,Aim_Time_CasterArrival,HeatID,BOF_Status,Side_Status,                    ");
		cstrSQL+= _T(" Status,LF_Status,RH_Status,Caster_Status ,Steel_Return_Flag,Div_HeatID,                                  ");
		cstrSQL+= csTreatSeqCondition;
		cstrSQL+= _T(" Steel_Back_Flag   from %s where PlanID = '%s'                                                            ");
	}//2009-03-12 LF与RH进行拆分	
	else if (max(nRHExecuteStatus1, nRHExecuteStatus2) > 1)//精品钢线
	{	
		if(nRHExecuteStatus1 >= nRHExecuteStatus2)
		{
			if(csRefineTypeFlag1 == _T("LR"))
			{	
				//RH开始处理时，精炼区分为LR，另一个炉次不为LR不允许交换（工艺路径不允许）
				if(csRefineTypeFlag2 != _T("LR"))
					return -12;
				cstrSQL = _T(" Select BOFID,LFID,RHID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,");
				cstrSQL+= _T(" Aim_Time_LFArrival,Aim_Time_LFStart,Aim_Time_LFEnd,Aim_Time_LFLeave,Aim_Time_RHArrival,Aim_Time_RHStart, ");
				cstrSQL+= _T(" Aim_Time_RHEnd,Aim_Time_RHLeave,HeatID,BOF_Status,Side_Status,Status,LF_Status,                          ");
				cstrSQL+= csTreatSeqCondition;
				cstrSQL+= _T(" RH_Status,Steel_Return_Flag,Div_HeatID,Steel_Back_Flag from %s where PlanID = '%s'                       ");
			}
			else
			{
				if(csRefineTypeFlag1 == _T("R") || csRefineTypeFlag1 == _T("RL"))
				{
					//RH开始处理时，精炼区分为R,RL，另一个炉次精炼区分为“0”或者“LR”不允许交换（工艺路径不允许）
					if(csRefineTypeFlag2 != _T("R") && csRefineTypeFlag2 != _T("RL"))
						return -13;
					cstrSQL = _T(" Select BOFID,RHID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,     ");
					cstrSQL+= _T(" Aim_Time_RHArrival,Aim_Time_RHStart,Aim_Time_RHEnd,Aim_Time_RHLeave,HeatID,BOF_Status,Side_Status,Status,");
					cstrSQL+= csTreatSeqCondition;
					cstrSQL+= _T(" RH_Status,Steel_Return_Flag,Div_HeatID,Steel_Back_Flag            from %s where PlanID = '%s'            ");
				}
			}
		}
		else
		{
			if(csRefineTypeFlag2 == _T("LR"))
			{	
				//RH开始处理时，精炼区分为LR，另一个炉次不为LR不允许交换（工艺路径不允许）
				if(csRefineTypeFlag1 != _T("LR"))
					return -12;
				cstrSQL = _T(" Select BOFID,LFID,RHID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,");
				cstrSQL+= _T(" Aim_Time_LFArrival,Aim_Time_LFStart,Aim_Time_LFEnd,Aim_Time_LFLeave,Aim_Time_RHArrival,Aim_Time_RHStart, ");
				cstrSQL+= _T(" Aim_Time_RHEnd,Aim_Time_RHLeave,HeatID,BOF_Status,Side_Status,Status,LF_Status,                          ");
				cstrSQL+= csTreatSeqCondition;
				cstrSQL+= _T(" RH_Status,Steel_Return_Flag,Div_HeatID,Steel_Back_Flag  from %s where PlanID = '%s'                      ");
			}
			else
			{
				if(csRefineTypeFlag2 == _T("R") || csRefineTypeFlag2 == _T("RL"))
				{
					//RH开始处理时，精炼区分为R,RL，另一个炉次精炼区分为“0”或者“LR”不允许交换（工艺路径不允许）
					if(csRefineTypeFlag1 != _T("R") && csRefineTypeFlag1 != _T("RL"))
						return -13;
					cstrSQL = _T(" Select BOFID,RHID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,     ");
					cstrSQL+= _T(" Aim_Time_RHArrival,Aim_Time_RHStart,Aim_Time_RHEnd,Aim_Time_RHLeave,HeatID,BOF_Status,Side_Status,Status,");
					cstrSQL+= csTreatSeqCondition;
					cstrSQL+= _T(" RH_Status,Steel_Return_Flag,Div_HeatID,Steel_Back_Flag   from %s where PlanID = '%s'                     ");
				}
			}
		}


	}		
	else if (max(nLFExecuteStatus1, nLFExecuteStatus2) > 1)
	{
		if(nLFExecuteStatus1 >= nLFExecuteStatus2)
		{
			//LF开始处理时，精炼区分为RL，另一个炉次不为RL不允许交换（工艺路径不允许）
			if(csRefineTypeFlag1 == _T("RL"))
			{
				if(csRefineTypeFlag2 != _T("RL"))
					return -14;
				cstrSQL = _T(" Select BOFID,LFID,RHID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,");
				cstrSQL+= _T(" Aim_Time_LFArrival,Aim_Time_LFStart,Aim_Time_LFEnd,Aim_Time_LFLeave,Aim_Time_RHArrival,Aim_Time_RHStart, ");
				cstrSQL+= _T(" Aim_Time_RHEnd,Aim_Time_RHLeave,HeatID,BOF_Status,Side_Status,Status,LF_Status,                          ");
				cstrSQL+= csTreatSeqCondition;
				cstrSQL+= _T(" RH_Status,Steel_Return_Flag,Div_HeatID,Steel_Back_Flag  from %s where PlanID = '%s'                      ");
			}
			else
			{
				if(csRefineTypeFlag1 == _T("L") || csRefineTypeFlag1 == _T("LR"))
				{
					//LF开始处理时，精炼区分为LR,L，另一个炉次精炼区分为“0”或者“RL”不允许交换（工艺路径不允许）
					if(csRefineTypeFlag2 != _T("L") && csRefineTypeFlag2 != _T("LR"))
						return -15;
				cstrSQL = _T(" Select BOFID,LFID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,     ");
				cstrSQL+= _T(" Aim_Time_LFArrival,Aim_Time_LFStart,Aim_Time_LFEnd,Aim_Time_LFLeave,HeatID,BOF_Status,Side_Status,       ");
				cstrSQL+= csTreatSeqCondition;
				cstrSQL+= _T(" Status,LF_Status,Steel_Return_Flag,Div_HeatID,Steel_Back_Flag            from %s where PlanID = '%s'     ");
				}
			}
		}
		else
		{
			//LF开始处理时，精炼区分为RL，另一个炉次不为RL不允许交换（工艺路径不允许）
			if(csRefineTypeFlag2 == _T("RL"))
			{
				if(csRefineTypeFlag1 != _T("RL"))
					return -14;
				cstrSQL = _T(" Select BOFID,LFID,RHID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,");
				cstrSQL+= _T(" Aim_Time_LFArrival,Aim_Time_LFStart,Aim_Time_LFEnd,Aim_Time_LFLeave,Aim_Time_RHArrival,Aim_Time_RHStart, ");
				cstrSQL+= _T(" Aim_Time_RHEnd,Aim_Time_RHLeave,HeatID,BOF_Status,Side_Status,Status,LF_Status,                          ");
				cstrSQL+= csTreatSeqCondition;
				cstrSQL+= _T(" RH_Status,Steel_Return_Flag,Div_HeatID,Steel_Back_Flag  from %s where PlanID = '%s'                      ");
			}
			else
			{
				if(csRefineTypeFlag2 == _T("L") || csRefineTypeFlag2 == _T("LR"))
				{
					//LF开始处理时，精炼区分为LR,L，另一个炉次精炼区分为“0”或者“RL”不允许交换（工艺路径不允许）
					if(csRefineTypeFlag1 != _T("L") && csRefineTypeFlag1 != _T("LR"))
						return -15;
				cstrSQL = _T(" Select BOFID,LFID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,     ");
				cstrSQL+= _T(" Aim_Time_LFArrival,Aim_Time_LFStart,Aim_Time_LFEnd,Aim_Time_LFLeave,HeatID,BOF_Status,Side_Status,       ");
				cstrSQL+= csTreatSeqCondition;
				cstrSQL+= _T(" Status,LF_Status,Steel_Return_Flag,Div_HeatID,Steel_Back_Flag            from %s where PlanID = '%s'     ");
				}
			}
		}

	}
	else if (max(nSideExecuteStatus1, nSideExecuteStatus2) > 1)
	{
		cstrSQL = _T(" Select BOFID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,Aim_Time_TappedSideEnd,     ");
	    cstrSQL+= _T(" HeatID,BOF_Status,Side_Status,Status,Steel_Return_Flag,Div_HeatID,                                  ");
		cstrSQL+= csTreatSeqCondition;
		cstrSQL+= _T(" Steel_Back_Flag  from %s where PlanID = '%s'                                                        ");
	}
	else
	{
		cstrSQL = _T(" Select BOFID,Aim_Time_IronPrepared,Aim_Time_BOFStart,Aim_Time_BOFTapped,     ");
	    cstrSQL+= _T(" HeatID,BOF_Status,Status,Steel_Return_Flag,Div_HeatID,                       ");
		cstrSQL+= csTreatSeqCondition;
		cstrSQL+= _T(" Steel_Back_Flag  from %s where PlanID = '%s'                                 ");
	}

	CString csSQL1;
	csSQL1.Format(cstrSQL,PLAN_TAPPING_CLASS_URI,csPreHeatID1);
	CL3RecordSetWrap rsTappingPlan1;
	if (!Query(csSQL1,rsTappingPlan1) || rsTappingPlan1.IsNull() || (rsTappingPlan1.GetRowCount() < 1))
		return -4;

	CString csSQL2;
	csSQL2.Format(cstrSQL,PLAN_TAPPING_CLASS_URI,csPreHeatID2);	
	CL3RecordSetWrap rsTappingPlan2;
	if (!Query(csSQL2,rsTappingPlan2) || rsTappingPlan2.IsNull() || (rsTappingPlan2.GetRowCount() < 1))
		return -4;

	//记录熔炼号
	rsTappingPlan1.MoveFirst();
	valTemp = rsTappingPlan1.GetFieldByName(_T("HeatID"));
	CString cstrHeatID1 = valTemp.ToCString();

	rsTappingPlan2.MoveFirst();
	valTemp = rsTappingPlan2.GetFieldByName(_T("HeatID"));
	CString cstrHeatID2 = valTemp.ToCString();


	//事务开始
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	//随着计划的调整移动钢水到相应的缓存
	if (max(nCasterExecuteStatus1, nCasterExecuteStatus2) > 1)
	{
		L3LONG nRet = MoveSteelWhenCasterExPlan(cstrURI1,cstrURI2);
		if(nRet < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return nRet;
		}
		
	}
	else if (max(nRHExecuteStatus1, nRHExecuteStatus2) > 1)//精品钢线
	{
		L3LONG nRet = MoveSteelWhenRHExPlan(cstrURI1,cstrURI2);
		if(nRet < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return nRet;
		}

	}
	else if(max(nLFExecuteStatus1, nLFExecuteStatus2) > 1)
	{
		L3LONG nRet = MoveSteelWhenLFExPlan(cstrURI1,cstrURI2);
		if(nRet < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return nRet;
		}
	}

	else if (max(nSideExecuteStatus1, nSideExecuteStatus2) > 1)
	{
		L3LONG nRet = MoveSteelWhenSideExchangePlan(cstrURI1,cstrURI2);
		if(nRet < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return nRet;
		}

	}
	else
	{
		L3LONG nRet = MoveSteelWhenBOFExPlan(cstrURI1,cstrURI2);
		if(nRet < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return nRet;
		}

	}

	//设置对象属性
	rsTappingPlan2.MoveFirst();
	if (SetObjPropValues(cstrURI1, rsTappingPlan2) < 10)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	rsTappingPlan1.MoveFirst();
	if (SetObjPropValues(cstrURI2, rsTappingPlan1) < 10)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	//交换实绩类
	//得到URI
	CString cstrActURI1 = PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPreHeatID1 ;
	CString cstrActURI2 = PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPreHeatID2 ;


	//开浇之前可以交换炉座
	if (max(nCasterExecuteStatus1, nCasterExecuteStatus2) > 1)
		//上回转台,但是铸机不能参与交换
	{
		cstrSQL = _T("Select BOFID,HeatID,LFID,RHID,LF_TreatNo,RH_TreatNo,Act_Time_IronPrepared,Act_Time_BOFStart,Act_Time_BOFTapped,     ");
		cstrSQL+= _T("Act_Time_TappedSideEnd,Act_Time_LFArrival,Act_Time_LFStart,Act_Time_LFEnd,Act_Time_LFLeave,Act_Time_RHArrival,      ");
		cstrSQL+= _T("Act_Time_RHStart,Act_Time_RHEnd,Act_Time_RHLeave,Act_Time_CasterArrival,CreateDate  from %s where PreHeatID = '%s'  ");
	}
	else if (max(nRHExecuteStatus1, nRHExecuteStatus2) > 1)
	{
		if(csRefineTypeFlag1 == _T("LR") || csRefineTypeFlag2 == _T("LR"))
		{
			cstrSQL = _T("Select BOFID,HeatID,LFID,RHID,LF_TreatNo,RH_TreatNo,Act_Time_IronPrepared,Act_Time_BOFStart,Act_Time_BOFTapped,     ");
			cstrSQL+= _T("Act_Time_TappedSideEnd,Act_Time_LFArrival,Act_Time_LFStart,Act_Time_LFEnd,Act_Time_LFLeave,Act_Time_RHArrival,      ");
			cstrSQL+= _T("Act_Time_RHStart,Act_Time_RHEnd,Act_Time_RHLeave,CreateDate  from %s where PreHeatID = '%s'                         ");
		}
		else
		{    
			cstrSQL = _T("Select BOFID,HeatID,RHID,RH_TreatNo,Act_Time_IronPrepared,Act_Time_BOFStart,Act_Time_BOFTapped,                     ");
			cstrSQL+= _T("Act_Time_TappedSideEnd,Act_Time_RHArrival,                                                                          ");
			cstrSQL+= _T("Act_Time_RHStart,Act_Time_RHEnd,Act_Time_RHLeave,CreateDate  from %s where PreHeatID = '%s'                         ");
		}


	}
	else if (max(nLFExecuteStatus1, nLFExecuteStatus2) > 1)
	{
		if(csRefineTypeFlag1 == _T("RL") || csRefineTypeFlag2 == _T("RL"))
		{
			cstrSQL = _T("Select BOFID,HeatID,LFID,RHID,LF_TreatNo,RH_TreatNo,Act_Time_IronPrepared,Act_Time_BOFStart,Act_Time_BOFTapped,     ");
			cstrSQL+= _T("Act_Time_TappedSideEnd,Act_Time_LFArrival,Act_Time_LFStart,Act_Time_LFEnd,Act_Time_LFLeave,Act_Time_RHArrival,      ");
			cstrSQL+= _T("Act_Time_RHStart,Act_Time_RHEnd,Act_Time_RHLeave,CreateDate  from %s where PreHeatID = '%s'                         ");
		}
		else
		{    
			cstrSQL = _T("Select BOFID,HeatID,LFID,LF_TreatNo,Act_Time_IronPrepared,Act_Time_BOFStart,Act_Time_BOFTapped,                ");
			cstrSQL+= _T("Act_Time_TappedSideEnd,Act_Time_LFArrival,Act_Time_LFStart,Act_Time_LFEnd,Act_Time_LFLeave,                    ");
			cstrSQL+= _T("CreateDate  from %s where PreHeatID = '%s'                                                                     ");
		}
	}
	else if (max(nSideExecuteStatus1, nSideExecuteStatus2) > 1)
	{
		cstrSQL = _T("Select BOFID,HeatID,Act_Time_IronPrepared,Act_Time_BOFStart,Act_Time_BOFTapped,  ");
		cstrSQL+= _T("Act_Time_TappedSideEnd, CreateDate  from %s where PreHeatID = '%s'              ");
	}
	else
	{
		cstrSQL = _T("Select BOFID,HeatID,Act_Time_IronPrepared,Act_Time_BOFStart,Act_Time_BOFTapped,  ");
		cstrSQL+= _T("CreateDate  from %s where PreHeatID = '%s'              ");
	}


	//查询出钢计划实绩内容
	CString csActSQL1;
	csActSQL1.Format(cstrSQL,PLAN_TAPPING_ACT_CLASS_URI,csPreHeatID1);
	CL3RecordSetWrap rsTappingPlanActual1;
	if (!Query(csActSQL1,rsTappingPlanActual1) || rsTappingPlanActual1.IsNull() || (rsTappingPlanActual1.GetRowCount() < 1))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -6;
	}
	CString csActSQL2;
	csActSQL2.Format(cstrSQL,PLAN_TAPPING_ACT_CLASS_URI,csPreHeatID2);
	CL3RecordSetWrap rsTappingPlanActual2;
	if (!Query(csActSQL2,rsTappingPlanActual2) || rsTappingPlanActual2.IsNull() || (rsTappingPlanActual2.GetRowCount() < 1))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -6;
	}


	//设置对象属性
	rsTappingPlanActual2.MoveFirst();
	if (SetObjPropValues(cstrActURI1, rsTappingPlanActual2) < 6)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -7;
	}

	rsTappingPlanActual1.MoveFirst();
	if (SetObjPropValues(cstrActURI2, rsTappingPlanActual1) < 6)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -7;
	}

	if(bUseTrans)
		Commit(nTrans);

	//修改工序炼钢记号放在事务之外
	L3STRING strHeatID1 = cstrHeatID1.AllocSysString();
	L3STRING strHeatID2 = cstrHeatID2.AllocSysString();
	ModifyUnitSteelGradeIndex(strHeatID1);
	ModifyUnitSteelGradeIndex(strHeatID2);
	L3SysFreeString(strHeatID1);
	L3SysFreeString(strHeatID2);
	ChangeRsTappingPlanValue();

	return 0;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanFirHeatDesign" type="L3BOOL">
/// 
/// 指定浇次第一炉，产生新的浇次与浇次内炉数
/// ARG&gt;&gt; PreHeatID : 预定炉号。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="strPreHeatID" type="L3STRING">预定炉号</Param>
/// </Method>
L3BOOL CPlan_Mag::TappingPlanFirHeatDesign(L3RECORDSET rsFirData)
{
	CL3RecordSetWrap rs =rsFirData;
    if( rs.IsNull() || rs.GetRowCount() !=1 )
		return false;
	if(rs.GetFieldIndex(_T("PlanID")) < 0 )
		return false;

	rs.MoveFirst();
	CL3Variant tempVariant = rs.GetFieldByName(_T("PlanID"));
	if(!tempVariant.IsValid() || tempVariant.IsError() || tempVariant.IsNull())
		return false;
	//得到URI
	CString csPlanID = tempVariant.ToCString();
	CString cstrURI = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

    if(!SetObjectPropValue(cstrURI,_T("Fir_Heat_Flag"),(L3LONG)1))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	//计算浇次浇次内炉数
	if (CaculateNewCastingNoAndHeats(csPlanID) < 0)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

	return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanFirHeatDesign" type="L3BOOL">
/// 
/// 计算新的浇次与浇次内炉数
/// ARG&gt;&gt; PreHeatID : 预定炉号。
/// RET &lt;&lt; 成功返回0，失败返回错误代码
/// <Param name="strPreHeatID" type="L3STRING">预定炉号</Param>
/// </Method>

L3LONG	CPlan_Mag::CaculateNewCastingNoAndHeats(CString csPresetHeatID)
{
	
	CL3Variant tempVariant;
	CString cstrUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPresetHeatID;

	//得到铸机号
	tempVariant = GetObjectPropValue(cstrUri,_T("CasterID"));
	if(!tempVariant.IsValid() || tempVariant.IsError() || tempVariant.IsNull())
		return -1;

	CString csCasterID=tempVariant.ToCString();

	//得到铸机处理顺序号
	tempVariant = GetObjectPropValue(cstrUri, _T("Treat_Seq"));
	if (tempVariant.IsEmpty() || tempVariant.IsError() || tempVariant.IsNull())
		return -1;
	CString  csTreatSeq = tempVariant.ToCString();


	//得到铸机浇次第一炉后面的所有炉数,按铸机处理顺序号排序0800001
	CString csTemp  = _T(" Select PlanID from %s                                 ");
			csTemp += _T(" where  CasterID = '%s'    and   Treat_Seq >= '%s'     ");
			csTemp += _T(" order by Treat_Seq                                    ");

	CString csSQL;
	csSQL.Format(csTemp,PLAN_TAPPING_CLASS_URI,csCasterID,csTreatSeq);
	CL3RecordSetWrap rsPlanHeats;
	if (!Query(csSQL,rsPlanHeats) || rsPlanHeats.IsNull() || (rsPlanHeats.GetRowCount() < 1))
		return -1;
	rsPlanHeats.MoveFirst();

	//得到新的浇次号J1080001
	csTemp = _T(" Select Max(Casting_No)    from %s                          ");
	csTemp+= _T(" Where  CasterID  = '%s'                                    ");
	csTemp+= _T(" and substr(Casting_No,2,1) = '%s'                          ");
	csTemp+= _T(" and to_char(CreateDate,'yyyy') = to_char(sysdate,'yyyy')   ");	//解决跨年问题

	csSQL.Format(csTemp,PLAN_TAPPING_CLASS_URI,csCasterID,csCasterID.Mid(2,1));

	CL3RecordSetWrap rsMaxCastingNo;
	if (!Query(csSQL,rsMaxCastingNo))
		return -2;

	rsMaxCastingNo.MoveFirst();

	tempVariant = rsMaxCastingNo.GetFieldByIndex(0);

	L3LONG nCastingNo =0;
	CString csCastingNo = tempVariant.ToCString();
	if(csCastingNo.IsEmpty())
		nCastingNo = 0;
	else
	{
		CString csTemp = csCastingNo.Mid(4,4);
		nCastingNo = _ttol(csTemp);
	}

	nCastingNo++;
	CString csTempCastingNo;
	csTempCastingNo.Format(_T("%04d"),nCastingNo);

	COleDateTime odtCurrentDate = COleDateTime::GetCurrentTime();
	CString cstrCurrentDate = odtCurrentDate.Format(_T("%Y"));
	CString csCastNo =_T("J") + csCasterID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempCastingNo;	

	CString cstrPreHeatID;

	L3SHORT i = 1;

	while(!rsPlanHeats.IsEOF())
	{
		tempVariant = rsPlanHeats.GetFieldByIndex(0);
		if(!tempVariant.IsValid() || tempVariant.IsError() || tempVariant.IsNull())
			return -2;
		cstrPreHeatID = tempVariant.ToCString();
		CString csUri=PLAN_TAPPING_CLASS_URI + _T("\\") + cstrPreHeatID;

		//清掉该炉次后面的浇次第一炉标志
		if ( i > 1)
		{
			if (!SetObjectPropValue(csUri,_T("Fir_Heat_Flag"),(L3SHORT) 0 ))
				return -3;

		}

		if (!SetObjectPropValue(csUri,_T("Casting_No"),CL3Variant(csCastNo)))
			return -3;

		if (!SetObjectPropValue(csUri,_T("Casting_Heat_Cnt"),i))
			return -3;
		i++;
		rsPlanHeats.MoveNext();
	}

	return 0;

}



/// <Method class="CPlan_Mag" name="TappingPlanFirHeatCancel" type="L3BOOL">
/// 
/// 取消浇次第一炉，清掉浇次号、浇次内炉数
/// ARG&gt;&gt; strCasterID:铸机号
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// </Method>
L3BOOL CPlan_Mag::TappingPlanFirHeatCancel(L3STRING strCasterID)
{

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	CL3RecordSetWrap rsPky_HeatTappingPlan;
	CString csCasterID = strCasterID;
	CString csTemp = _T(" select PlanID from %s where Status <> %s and CasterID = '%s' ");
	CString csSQl;
	csSQl.Format(csTemp,PLAN_TAPPING_CLASS_URI,TAPPING_PLAN_STATUS_EXCUTED,csCasterID);

	if (!Query(csSQl,rsPky_HeatTappingPlan) || rsPky_HeatTappingPlan.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	L3LONG lCount = rsPky_HeatTappingPlan.GetRowCount();
	rsPky_HeatTappingPlan.MoveFirst();

	for(long i = 0; i < lCount; i ++)
	{
		CL3Variant varURI = rsPky_HeatTappingPlan.GetFieldByName(_T("PlanID"));
		if(!varURI.IsValid() || varURI.IsError() || varURI.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		CString cstrURI = PLAN_TAPPING_CLASS_URI + _T("\\") + varURI.ToCString();
		if (!SetObjectPropValue(cstrURI,_T("Fir_Heat_Flag"),(L3LONG)0))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if (!SetObjectPropValue(cstrURI,_T("Casting_No"),CL3Variant(_T(""))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if (!SetObjectPropValue(cstrURI,_T("Casting_Heat_Cnt"),(L3LONG) 0))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		rsPky_HeatTappingPlan.MoveNext();
	}	//End for

	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

	return true;

}


/// <Method class="CPlan_Mag" name="AddHeatsToCasting" type="L3BOOL">
/// 
/// 添加炉次到最近浇次中
/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// </Method>
L3BOOL CPlan_Mag::AddHeatsToCasting(L3STRING strCasterID)
{
	CString csCasterID = strCasterID;

	CL3RecordSetWrap rs_PresetHeatID; //查询返回的复合主键

	//得到最近的浇次中第一炉的预定熔炼号
	CString csTemp =_T(" select PlanID,Treat_Seq,Casting_No from %s  where Casting_No=        ");
	        csTemp+=_T(" (Select Max(Casting_No) From %s where  CasterID = '%s')              ");
			csTemp+=_T(" and Fir_Heat_Flag = 1                                                ");
	CString csSQL;
	csSQL.Format(csTemp,PLAN_TAPPING_CLASS_URI,PLAN_TAPPING_CLASS_URI,csCasterID);
	if (!Query(csSQL,rs_PresetHeatID) || rs_PresetHeatID.IsNull())
	    return false;

	rs_PresetHeatID.MoveFirst();

	CL3Variant tempVariant = rs_PresetHeatID.GetFieldByIndex(2);
	if(!tempVariant.IsValid() || tempVariant.IsError() || tempVariant.IsNull())
		return false;

	CString csCastingNo=tempVariant.ToCString();
	
	//得到处理顺序号
	tempVariant = rs_PresetHeatID.GetFieldByIndex(1);
	if(!tempVariant.IsValid() || tempVariant.IsError() || tempVariant.IsNull())
		return false;
	CString  csTreatSeq = tempVariant.ToCString();

	//得到铸机浇次第一炉后面的所有炉数,按包次处理顺序
	csTemp  = _T(" Select PlanID from %s                              ");
	csTemp += _T(" where CasterID = '%s'    and    Treat_Seq >= '%s'  ");
	csTemp += _T(" order by        Treat_Seq                          ");
	
	csSQL.Format(csTemp,PLAN_TAPPING_CLASS_URI,csCasterID,csTreatSeq);

	CL3RecordSetWrap rsPlanHeats;
	if (!Query(csSQL,rsPlanHeats) || rsPlanHeats.IsNull() || (rsPlanHeats.GetRowCount() < 1))
		return false;

	rsPlanHeats.MoveFirst();

	CString cstrPreHeatID;

	L3SHORT i = 1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	//重新计算浇次中炉次顺序
	while(!rsPlanHeats.IsEOF())
	{
		tempVariant = rsPlanHeats.GetFieldByIndex(0);
		cstrPreHeatID = tempVariant.ToCString();
		CString csUri=PLAN_TAPPING_CLASS_URI +_T("\\") + cstrPreHeatID;

		//清掉该炉次后面的浇次第一炉标志
		if ( i > 1)
		{
			if (!SetObjectPropValue(csUri,_T("Fir_Heat_Flag"),(L3SHORT) 0 ))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return false;
			}

		}

		if (!SetObjectPropValue(csUri,_T("Casting_No"),CL3Variant(csCastingNo)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}

		if (!SetObjectPropValue(csUri,_T("Casting_Heat_Cnt"),i))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		i++;
		rsPlanHeats.MoveNext();
	}
    
	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

	return true;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="CalBOFIDAndReGenTappingAct" type="L3LONG">
/// 
/// 重新分配转炉炉座产生出钢计划实际
/// ARG&gt;&gt; csNewBOFFlag:新转炉标志
/// RET &lt;&lt; 成功返回1；失败返回出错代码。
/// </Method>
L3LONG CPlan_Mag::CalBOFIDAndReGenTappingAct(L3SHORT nNewBOFFlag)
{
	//创建出钢计划实绩记录集
	CL3RecordSetWrap rsTappingPlanActual;
	if(!CreateClassPropSet(PLAN_TAPPING_ACT_CLASS_URI,rsTappingPlanActual)) 
		return -2;
	rsTappingPlanActual.AppendRecord();
	rsTappingPlanActual.MoveFirst();

	CString cstrTemp = _T("Select * from %s where Status = %s and New_BOF_Flag = %d order by Aim_Time_IronPrepared asc " );
	CL3RecordSetWrap rsUnExecTappingPlan;
	CString csSQL;
	csSQL.Format(cstrTemp,PLAN_TAPPING_CLASS_URI,TAPPING_PLAN_STATUS_UNSEND,nNewBOFFlag);
	if (!Query(csSQL, rsUnExecTappingPlan) || rsUnExecTappingPlan.IsNull())
		return -21;
	//如果没有没有执行的计划,就不执行下面的逻辑,但不报错 
	if (rsUnExecTappingPlan.GetRowCount() < 1)
		return 0;

	rsUnExecTappingPlan.MoveFirst();

	while (!rsUnExecTappingPlan.IsEOF())
	{
		//删除出钢计划实绩
		CL3Variant valTemp = rsUnExecTappingPlan.GetFieldByName(_T("PlanID"));
		if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
			return -22;
		CString csPlanID = valTemp.ToCString();
		CString	csPlanActObjUri = PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPlanID ;
		if (!DeleteOldObject(csPlanActObjUri))
			return -23;
		//对已经计算了HEATID的对其HEATID赋空值
		CString	csPlanObjUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID ;
		if (!SetObjectPropValue(csPlanObjUri, _T("HeatID"), CL3Variant(_T(""))))
			return -24;
		rsUnExecTappingPlan.MoveNext();
	}

	//判断几座转炉参与计算
	cstrTemp = _T("Select BOFID from %s where Status = '0' and New_BOF_Flag = %d order by BOFID ");
	CL3RecordSetWrap rsBOFID;
	csSQL.Format(cstrTemp,PLAN_BOF_CLASS_URI,nNewBOFFlag);
	if (!Query(csSQL, rsBOFID) || rsBOFID.IsNull())
		return -25;

	long nBOFCount = rsBOFID.GetRowCount();
	if (nBOFCount < 1)
		return 0;

	BOFStatus *arrayBOF = new BOFStatus[nBOFCount];


	rsUnExecTappingPlan.MoveFirst();

	while(!rsUnExecTappingPlan.IsEOF())
	{
		//得到预定炉号(URI)
		CL3Variant valTemp = rsUnExecTappingPlan.GetFieldByName(_T("PlanID"));
		if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
			return -26;
		CString csPlanID = valTemp.ToCString();
		CString	csPlanObjUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID ;

		//得到铁水准备时刻
		valTemp = rsUnExecTappingPlan.GetFieldByName(_T("Aim_Time_IronPrepared"));
		L3DATETIME dtCurrIronPrepared = valTemp.ToDateTime();

		//重新计算转炉炉座

		//计算转炉计划处理结束时刻
		L3DATETIME dtBOF01ProcessEndTime = 0;

		rsBOFID.MoveFirst();

		for (int i=0 ;i < nBOFCount;i++)
		{
			valTemp = rsBOFID.GetFieldByName(_T("BOFID"));
			CString csBOFID = valTemp.ToCString();
			if (CalcBOFProcessEndTime(csBOFID, dtBOF01ProcessEndTime, dtCurrIronPrepared) < 0)
			{
				delete arrayBOF;
				return -27;
			}
			arrayBOF[i].dtBOF0ProcessEndTime = dtBOF01ProcessEndTime;
			_tcsncpy_s(arrayBOF[i].BOFID,4,csBOFID,3); arrayBOF[i].BOFID[3] = 0;
			rsBOFID.MoveNext();
		}

		//先出钢先作业 
		dtBOF01ProcessEndTime = arrayBOF[0].dtBOF0ProcessEndTime;
		CString csBOFID = arrayBOF[0].BOFID;

		for (int i=0 ;i < nBOFCount-1;i++)
		{
			if ((dtBOF01ProcessEndTime - arrayBOF[i+1].dtBOF0ProcessEndTime) > 0 )
			{
				dtBOF01ProcessEndTime = arrayBOF[i+1].dtBOF0ProcessEndTime;
				csBOFID = arrayBOF[i+1].BOFID;
			}

		}

		//得到最小的出钢时间
		if (!SetObjectPropValue(csPlanObjUri, _T("BOFID"), CL3Variant(csBOFID))) 
		{
			delete arrayBOF;
			return -28;
		}

		//加上工序移动时间
		if (CalcUnitOneToOneTime(csPlanID) < 0)
		{
			delete arrayBOF;
			return -29;
		}

		//重新生成出钢计划实绩,并且计算熔炼号、工序处理号

		//得到预定炉号
		rsTappingPlanActual.SetFieldByName(_T("PreHeatID"), CL3Variant(csPlanID));
		rsTappingPlanActual.SetFieldByName(_T("CasterID"),rsUnExecTappingPlan.GetFieldByName(_T("CasterID")));
		rsTappingPlanActual.SetFieldByName(_T("BOFID"),CL3Variant(csBOFID));
		rsTappingPlanActual.SetFieldByName(_T("LFID"),rsUnExecTappingPlan.GetFieldByName(_T("LFID")));
		rsTappingPlanActual.SetFieldByName(_T("RHID"),rsUnExecTappingPlan.GetFieldByName(_T("RHID")));

		//得到熔炼号
		L3SHORT nUnitType = UNIT_AREA_BOF;
		long lTemp = GetHeatMaxProcessNo(nUnitType, csBOFID) + 1;		//循环次数为i + 1
		CString csTempHeatID;
		csTempHeatID.Format(_T("%05d"),lTemp);	//不足5位的前面补0
		COleDateTime odtCurrentDate = COleDateTime::GetCurrentTime();
		CString cstrCurrentDate = odtCurrentDate.Format(_T("%Y"));
		CString csHeatID =_T("2") + csBOFID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempHeatID;
		rsTappingPlanActual.SetFieldByName(_T("HeatID"), CL3Variant(csHeatID));
		//对出钢计划设置其熔炼号
		if (!SetObjectPropValue(csPlanObjUri, _T("HeatID"), CL3Variant(csHeatID)))
		{
			delete arrayBOF;
			return -30;
		}

		//LF处理号
		CString csLFTreatNo =_T("0");
		valTemp = GetObjectPropValue(csPlanObjUri,_T("LFID"));
		if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		{
			delete arrayBOF;
			return -31;
		}
		CString csLFID = valTemp.ToCString();
		if(csLFID!=_T("0"))
		{
			nUnitType = UNIT_AREA_LF;
			lTemp = GetHeatMaxProcessNo(nUnitType, csLFID) + 1;		//循环次数为i + 1
			CString csTempTreatNo;
			csTempTreatNo.Format(_T("%05d"), lTemp);
			csLFTreatNo = csLFID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempTreatNo;
		}
		rsTappingPlanActual.SetFieldByName(_T("LF_TreatNo"), CL3Variant(csLFTreatNo));

		//RH处理号
		CString csRHTreatNo =_T("0");
		valTemp = GetObjectPropValue(csPlanObjUri,_T("RHID"));
		if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		{
			delete arrayBOF;
			return -32;
		}
		CString csRHID = valTemp.ToCString();
		if(csRHID!=_T("0"))
		{
			nUnitType = UNIT_AREA_RH;
			lTemp = GetHeatMaxProcessNo(nUnitType, csRHID) + 1;		//循环次数为i + 1
			CString csTempTreatNo;
			csTempTreatNo.Format(_T("%05d"), lTemp);
			csRHTreatNo = csRHID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempTreatNo;
		}
		rsTappingPlanActual.SetFieldByName(_T("RH_TreatNo"),CL3Variant(csRHTreatNo));

		//得到铸机处理号
		valTemp = GetObjectPropValue(csPlanObjUri,_T("CasterID"));
		if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		{
			delete arrayBOF;
			return -33;
		}
		CString csCasterID = valTemp.ToCString();
		nUnitType = UNIT_AREA_CASTER;
		lTemp = GetHeatMaxProcessNo(nUnitType, csCasterID) + 1;		//循环次数为i + 1
		CString csTempTreatNo;
		csTempTreatNo.Format(_T("%05d"), lTemp);
		CString csCasterTreatNo = csCasterID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempTreatNo;
		rsTappingPlanActual.SetFieldByName(_T("Caster_TreatNo"), CL3Variant(csCasterTreatNo));

		rsTappingPlanActual.SetFieldByName(_T("CreateDate"), COleDateTime::GetCurrentTime());


		//创建对象CHeatTappingPlanActualData
		if (CreateNewObjects(PLAN_TAPPING_ACT_CLASS_URI,rsTappingPlanActual) < 1)
		{
			delete arrayBOF;
			return -34;
		}

		//***************************重新生成出钢计划实绩,并且计算熔炼号******************

		rsTappingPlanActual.MoveFirst();
		rsUnExecTappingPlan.MoveNext();
	}

	delete arrayBOF;

	return 0;// TODO : 请在此添加逻辑代码
}


/// <Method class="CPlan_Mag" name="GetCurDayTappingPlan" type="L3RECORDSET">
/// 
/// 获取当天出钢计划信息以及上一天未执行完成计划
/// ARG &gt;&gt; strBofID: 转炉号。
///         &gt;&gt;strCasterID:铸机号
/// RET &gt;&gt; 找到的计划记录集。
/// <Param name="strBofID" type="String"></Param>
/// <Param name="strCasterID" type="String"></Param>
/// </Method>
L3RECORDSET CPlan_Mag::GetCurDayTappingPlan(L3STRING strBofID, L3STRING strCasterID)
{
	CString csBOFID = strBofID;
	CString csCasterID = strCasterID;

	COleDateTime curTime= COleDateTime::GetCurrentTime();
	CString cstrCurTime=curTime.Format(_T("%Y%m%d%H%M%S"));

	CL3RecordSetWrap rsReturnVal;

	//CString cstrQuerySql  = _T("  Select a.*,b.Act_Time_IronPrepared,b.Act_Time_BOFStart,b.Act_Time_BOFTapped,                          ");
	//		cstrQuerySql += _T("  b.Act_Time_TappedSideEnd,b.Act_Time_LFArrival,b.Act_Time_LFStart,b.Act_Time_LFEnd,b.Act_Time_LFLeave, ");
	//		cstrQuerySql += _T("  b.Act_Time_RHArrival,b.Act_Time_RHStart,b.Act_Time_RHEnd,b.Act_Time_RHLeave,                          ");
	//		cstrQuerySql += _T("  b.Act_Time_CasterArrival,b.Act_Time_CastingStart,b.Act_Time_CastingEnd,b.LF_TreatNo,b.RH_TreatNo,     ");
	//		cstrQuerySql += _T("  b.Caster_TreatNo   from %s a,  %s b    where a.PlanID =b.PreHeatID                                    ");
	//		cstrQuerySql += _T("  and (a.CreateDate >= (select TRUNC(SYSDATE) - 1/3 from dual)                                          ");
	//		cstrQuerySql += _T("  or ( a.CreateDate  < (select TRUNC(SYSDATE) - 1/3 from dual)                                          ");
	//		cstrQuerySql += _T("  and a.Status < %s))                                                                                   ");

	//Modify begin by llj 2011-03-09 后台报错进行修改

	/*CString cstrQuerySql  = _T("  Select a.*,b.Act_Time_IronPrepared,b.Act_Time_BOFStart,b.Act_Time_BOFTapped,                          ");
			cstrQuerySql += _T("  b.Act_Time_TappedSideEnd,b.Act_Time_LFArrival,b.Act_Time_LFStart,b.Act_Time_LFEnd,b.Act_Time_LFLeave, ");
			cstrQuerySql += _T("  b.Act_Time_RHArrival,b.Act_Time_RHStart,b.Act_Time_RHEnd,b.Act_Time_RHLeave,                          ");
			cstrQuerySql += _T("  b.Act_Time_CasterArrival,b.Act_Time_CastingStart,b.Act_Time_CastingEnd,b.LF_TreatNo,b.RH_TreatNo,     ");
			cstrQuerySql += _T("  b.Caster_TreatNo   from %s a,  %s b    where a.PlanID =b.PreHeatID                                    ");
			cstrQuerySql += _T("  and (a.CreateDate >= (select SYSDATE  from dual) - 1/3                                                ");
			cstrQuerySql += _T("  or  (a.CreateDate <  (select SYSDATE  from dual) - 1/3                                                ");
			cstrQuerySql += _T("  and a.Status < %s))                                                                                   ");
	*///Modify bend
	CString cstrQuerySql  = _T("  Select a.*,b.Act_Time_IronPrepared,b.Act_Time_BOFStart,b.Act_Time_BOFTapped,                          ");
			cstrQuerySql += _T("  b.Act_Time_TappedSideEnd,b.Act_Time_LFArrival,b.Act_Time_LFStart,b.Act_Time_LFEnd,b.Act_Time_LFLeave, ");
			cstrQuerySql += _T("  b.Act_Time_RHArrival,b.Act_Time_RHStart,b.Act_Time_RHEnd,b.Act_Time_RHLeave,                          ");
			cstrQuerySql += _T("  b.Act_Time_CasterArrival,b.Act_Time_CastingStart,b.Act_Time_CastingEnd,b.LF_TreatNo,b.RH_TreatNo,     ");
			cstrQuerySql += _T("  b.Caster_TreatNo ,c.TECH_REQUEST,c.PROTOCOL,c.PRODUCESTD  from %s a,  %s b ,%s c    where a.PlanID =b.PreHeatID  and a.plan_ord_id = c.planid  ");
			//cstrQuerySql += _T("  and (a.CreateDate >= (select SYSDATE  from dual) - 0.3333                                             ");
			//cstrQuerySql += _T("  or  (a.CreateDate <  (select SYSDATE  from dual) - 0.3333                                             ");
			cstrQuerySql += _T("  and a.Status < %s                                                                                   ");

	if ((csBOFID == _T("")) && (csCasterID ==_T("")))
	{
		cstrQuerySql += _T("order by a.CasterID,a.Treat_Seq ");
		CString csSQL;
		csSQL.Format(cstrQuerySql,PLAN_TAPPING_CLASS_URI,PLAN_TAPPING_ACT_CLASS_URI,PLAN_ORDER_CLASS_URI,TAPPING_PLAN_STATUS_EXCUTED);
		if (!Query(csSQL, rsReturnVal) || rsReturnVal.IsNull())
			return NULL;
		else
			return rsReturnVal.Detach();
	}
	else
	{
			if(csBOFID == _T("") && csCasterID !=_T(""))
			{
				cstrQuerySql += _T("and  a.CasterID = '%s' order by a.Treat_Seq ");
				CString csSQL;
				csSQL.Format(cstrQuerySql,PLAN_TAPPING_CLASS_URI,PLAN_TAPPING_ACT_CLASS_URI,TAPPING_PLAN_STATUS_EXCUTED,csCasterID);
				if (!Query(csSQL,rsReturnVal) || rsReturnVal.IsNull())
					return NULL;
				else
					return rsReturnVal.Detach();
			}
			else
			{
				if(csBOFID != _T("") && csCasterID ==_T(""))
				{
					cstrQuerySql += _T("and   a.BOFID = '%s' order by a.HeatID ");	
					CString csSQL;
					csSQL.Format(cstrQuerySql,PLAN_TAPPING_CLASS_URI,PLAN_TAPPING_ACT_CLASS_URI,TAPPING_PLAN_STATUS_EXCUTED,csBOFID);
					if (!Query(csSQL,rsReturnVal) || rsReturnVal.IsNull())
						return NULL;
					else
						return rsReturnVal.Detach();

				}
				else
				{
					cstrQuerySql += _T("and   a.BOFID = '%s' and a.CasterID = '%s' order by a.HeatID ");	
					CString csSQL;
					csSQL.Format(cstrQuerySql,PLAN_TAPPING_CLASS_URI,PLAN_TAPPING_ACT_CLASS_URI,TAPPING_PLAN_STATUS_EXCUTED,csBOFID,csCasterID);
					if (!Query(csSQL,rsReturnVal) || rsReturnVal.IsNull())
						return NULL;
					else
						return rsReturnVal.Detach();

				}
			}

	}


	return NULL;
}

/// <Method class="CPlan_Mag" name="TappingPlanChangeTimeTable" type="L3LONG">
/// 
/// 更改火车时刻表
/// ARG&gt;&gt; PreHeatID1 : 预定炉号。
/// RET &lt;&lt; 成功返回0；失败返回出错代码。
/// <Param name="PreHeatID" type="L3STRING">预定炉号</Param>
/// </Method>
L3LONG CPlan_Mag::TappingPlanChangeTimeTable(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
    if( rs.IsNull() || rs.GetRowCount() !=1 )
		return -1;
	if(rs.GetFieldIndex(_T("PlanID")) < 0 )
		return -1;

	rs.MoveFirst();
	CL3Variant tempVariant = rs.GetFieldByName(_T("PlanID"));
	if(!tempVariant.IsValid() || tempVariant.IsError() || tempVariant.IsNull())
		return -1;

	CString csPreHeatID = tempVariant.ToCString();

	//取得该炉的开浇时刻和铸机号
	CString cstrURI = PLAN_TAPPING_CLASS_URI +_T("\\");
	cstrURI += csPreHeatID;

	CString csPlanActUri = PLAN_TAPPING_ACT_CLASS_URI +_T("\\") + csPreHeatID;

	CL3Variant valTemp = GetObjectPropValue(cstrURI, _T("Caster_Status"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;

	CString csCasterStatus=valTemp.ToCString();

	if ((csCasterStatus == TAPPING_PLAN_CCM_STATUS_BEGIN) || (csCasterStatus == TAPPING_PLAN_CCM_STATUS_END))
	{
		//查询实绩开浇时刻
		valTemp = GetObjectPropValue(csPlanActUri, _T("Act_Time_CastingStart"));
		if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
			return -1;
	}
	else
	{
		valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_CastingStart"));
		if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
			return -1;
	}

	L3DATETIME dtFristCastingStart = valTemp.ToDateTime();

	//得到铸机号
	valTemp = GetObjectPropValue(cstrURI, _T("CasterID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csCasterID = valTemp.ToCString();

	
	//得到理顺序号
	valTemp = GetObjectPropValue(cstrURI, _T("Treat_Seq"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString  csSeqNo = valTemp.ToCString();

	//得到炼钢记号
	valTemp = GetObjectPropValue(cstrURI, _T("SteelGradeIndex"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString  csSteelGradeIndex = valTemp.ToCString();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	//计算第一炉浇铸结束时间
	CL3Variant vsStdCastingTime = GetObjectPropValue(QA_UNIT_PROC_TIME_CLASS_URI + _T("\\") + csSteelGradeIndex,_T("Caster_Proc_Time"));
	if(!vsStdCastingTime.IsValid() || vsStdCastingTime.IsError() || vsStdCastingTime.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	L3DATETIME dtProcessTime = (vsStdCastingTime.ToDateTime())/1440;
	L3DATETIME dtFirstCastingEnd = dtFristCastingStart + dtProcessTime;

	//if (csCasterStatus != TAPPING_PLAN_CCM_STATUS_END)
	//{	

		if (!SetObjectPropValue(cstrURI, _T("Aim_Time_CastingStart"), (L3DATETIME)dtFristCastingStart))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}

		if (!SetObjectPropValue(cstrURI, _T("Aim_Time_CastingEnd"), (L3DATETIME)dtFirstCastingEnd))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
	//}

	L3DATETIME dtCurrCastingTime = dtFristCastingStart;
	L3DATETIME dtNextCastingTime;
	L3DATETIME dtLastCastingEndTime;


	CL3RecordSetWrap rsL3PlanData;
	CString cstrQueryL3Plan  = _T(" Select * from %s  where CasterID ='%s'      ");
			cstrQueryL3Plan += _T(" and    Treat_Seq > '%s'                     ");
			cstrQueryL3Plan += _T(" order by Treat_Seq                          ");

	CString csSQL;
	csSQL.Format(cstrQueryL3Plan,PLAN_TAPPING_CLASS_URI,csCasterID,csSeqNo);
	if ((!Query(csSQL , rsL3PlanData)) || rsL3PlanData.IsNull() ||  rsL3PlanData.GetRowCount() < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	//循环读取rsL3PlanData中的炼钢记号生成L3计划
	rsL3PlanData.MoveFirst();
	L3LONG nL3PlanCount = rsL3PlanData.GetRowCount();

	dtLastCastingEndTime = dtFirstCastingEnd;

	L3DOUBLE  CASTINGIDLETIME = 3;//回转台操作时间
	L3DATETIME dtCastIdleTime = CASTINGIDLETIME/1440;

	//从第二炉开始计算
	for (L3LONG i = 0; i < nL3PlanCount; i ++)
	{
		//根据上一炉浇铸结束时间设定本炉开浇时刻 

		dtNextCastingTime = dtLastCastingEndTime + dtCastIdleTime;

		valTemp = rsL3PlanData.GetFieldByName(_T("PlanID"));
		if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -6;
		}
		CString csPlanID = valTemp.ToCString();
		cstrURI = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID;

		if (!SetObjectPropValue(cstrURI, _T("Aim_Time_CastingStart"), (L3DATETIME)dtNextCastingTime))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -7;
		}

		if (CalcUnitStdProcessTime(csPlanID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -8;
		}

		//计算工序间移动时间
		if (CalcUnitOneToOneTime(csPlanID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -9;
		}
		valTemp = GetObjectPropValue(cstrURI,_T("Aim_Time_CastingEnd"));
		dtLastCastingEndTime = valTemp.ToDateTime();

		rsL3PlanData.MoveNext();
		
	}

	//2008-12-09  屏蔽以下代码
	//L3LONG nBackVal = CalBOFIDAndReGenTappingAct(0);

	//if ( nBackVal < 0)
	//{
	//	if(bUseTrans)
	//		Rollback(nTrans);
	//	return nBackVal;
	//}

	//nBackVal = CalBOFIDAndReGenTappingAct(1);

	//if ( nBackVal < 0)
	//{
	//	if(bUseTrans)
	//		Rollback(nTrans);
	//	return nBackVal;
	//}

	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

	return 0;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="CalcUnitStdProcessTime" type="L3LONG">
/// 
/// 计算一炉各工位标准处理时刻
/// ARG&gt;&gt; PreHeatID1 : 预定炉号。
/// RET &lt;&lt; 成功返回0；失败返回出错代码。
/// <Param name="PreHeatID" type="L3STRING">预定炉号</Param>
/// </Method>
L3LONG CPlan_Mag::CalcUnitStdProcessTime(CString csPreHeatID)
{

	//按预定炉号查询计划数据
	CString csPlanUri = PLAN_TAPPING_CLASS_URI +_T("\\") + csPreHeatID;

	CL3Variant valTemp = GetObjectPropValue(csPlanUri,_T("SteelGradeIndex"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;

	CString csSteelGradeIndex = valTemp.ToCString();

	valTemp = GetObjectPropValue(csPlanUri,_T("Aim_Time_CastingStart"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3DATETIME dtCastingStart = valTemp.ToDateTime();

    CString cstrCurTime1=(COleDateTime(dtCastingStart)).Format(_T("%Y%m%d%H%M%S"));

	valTemp = GetObjectPropValue(csPlanUri,_T("Refine_Type"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csRefine_Type = valTemp.ToCString();

	L3DATETIME dtAim_IronPrepareTime = 0; //兑铁时间
	L3DATETIME dtAim_BOFProcessTime = 0;  //转炉处理时间
	L3DATETIME dtAim_LFWaitTime = 0; //LF等待时间
	L3DATETIME dtAim_RHWaitTime = 0; //RH等待时间
	L3DATETIME dtAim_LFProcessTime = 0;//LF炉处理时间
	L3DATETIME dtAim_RHProcessTime = 0;//RH炉处理时间
	L3DATETIME dtAim_CastWaitedTime = 0;//铸机等待时间
	L3DATETIME dtAim_CastingTime = 0;//浇注时间
	L3DATETIME dtAim_BOFSideTime = 0;//炉后处理时间
	L3DATETIME dtAim_Time_CastingEnd = 0;//浇注结束时刻
	L3DATETIME dtAim_Time_CasterArrival = 0;//大包到达时刻
	L3DATETIME dtAim_Time_RHArrival = 0;//RH进站时刻
	L3DATETIME dtAim_Time_RHLeave = 0;//RH出站时刻
	L3DATETIME dtAim_Time_RHEnd = 0;//RH处理结束时刻
	L3DATETIME dtAim_Time_RHStart = 0;//RH处理开始时刻
	L3DATETIME dtAim_Time_LFArrival = 0;//LF进站时刻
	L3DATETIME dtAim_Time_LFLeave = 0;//LF出站时刻
	L3DATETIME dtAim_Time_LFEnd = 0;//LF处理结束时刻
	L3DATETIME dtAim_Time_LFStart = 0;;//LF处理开始时刻
	L3DATETIME dtAim_Time_BOFSided = 0;//炉后F处理结束时刻
	L3DATETIME dtAim_Time_BOFTapped = 0;//出钢结束时刻
	L3DATETIME dtAim_Time_BOFStart = 0;//开吹时刻
	L3DATETIME dtAim_Time_IronPrepared = 0;//兑铁时刻

	//计算各工位处理时刻
	CString csTemp = _T("Select * from %s where SteelGradeIndex = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,QA_UNIT_PROC_TIME_CLASS_URI,csSteelGradeIndex);
	CL3RecordSetWrap rsTime;
	if(!Query(csSQL,rsTime) || rsTime.IsNull() || rsTime.GetRowCount() < 1)
		return -2;

	rsTime.MoveFirst();
	//转炉
	CL3Variant vsTempTime  = rsTime.GetFieldByName(_T("BOF_Proc_Time"));
	if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		return -2;
	dtAim_BOFProcessTime = (vsTempTime.ToDateTime())/1440;
	//LF
	vsTempTime  = rsTime.GetFieldByName(_T("LF_Proc_Time"));
	if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		return -2;
	dtAim_LFProcessTime = (vsTempTime.ToDateTime())/1440;
	//RH
	vsTempTime  = rsTime.GetFieldByName(_T("RH_Proc_Time"));
	if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		return -2;
	dtAim_RHProcessTime = (vsTempTime.ToDateTime())/1440;
	//铸机
	vsTempTime  = rsTime.GetFieldByName(_T("Caster_Proc_Time"));
	if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		return -2;
	dtAim_CastingTime = (vsTempTime.ToDateTime())/1440;
	//炉后
	vsTempTime  = rsTime.GetFieldByName(_T("Tapped_Proc_Time"));
	if(!vsTempTime.IsValid() || vsTempTime.IsError() || vsTempTime.IsNull())
		return -2;
	dtAim_BOFSideTime = (vsTempTime.ToDateTime())/1440;

	dtAim_IronPrepareTime = BOF_PREPARED_TIME/1440;
	dtAim_CastWaitedTime  = CASTING_WAITED_TIME/1440;
	dtAim_LFWaitTime = 5/1440;
	dtAim_RHWaitTime = 5/1440;


	//获取精炼区分

	//计算标准工艺时间
	dtAim_Time_CastingEnd = dtCastingStart + dtAim_CastingTime;
	dtAim_Time_CasterArrival = dtCastingStart - dtAim_CastWaitedTime;

	if(csRefine_Type == _T("0"))
	{
		dtAim_Time_RHArrival = 0;
		dtAim_Time_RHEnd = 0;
		dtAim_Time_RHStart = 0;
		dtAim_Time_RHLeave = 0;
		dtAim_Time_LFArrival = 0;
		dtAim_Time_LFEnd = 0;
		dtAim_Time_LFStart = 0;
		dtAim_Time_LFLeave = 0;
		dtAim_Time_BOFSided = dtAim_Time_CasterArrival;
	}
	else
	{
		if(csRefine_Type == _T("L"))
		{
			dtAim_Time_RHArrival = 0;
			dtAim_Time_RHEnd = 0;
			dtAim_Time_RHStart = 0;
			dtAim_Time_RHLeave = 0;
			dtAim_Time_LFLeave = dtAim_Time_CasterArrival;
			dtAim_Time_LFEnd = dtAim_Time_LFLeave - dtAim_LFWaitTime;
			dtAim_Time_LFStart = dtAim_Time_LFEnd - dtAim_LFProcessTime;
			dtAim_Time_LFArrival = dtAim_Time_LFStart - dtAim_LFWaitTime;
			dtAim_Time_BOFSided = dtAim_Time_LFArrival;
		}
		else
		{
			if(csRefine_Type == _T("R"))
			{
				dtAim_Time_LFArrival = 0;
				dtAim_Time_LFEnd = 0;
				dtAim_Time_LFStart = 0;
				dtAim_Time_LFLeave = 0;
				dtAim_Time_RHLeave = dtAim_Time_CasterArrival;
				dtAim_Time_RHEnd = dtAim_Time_RHLeave - dtAim_RHWaitTime;
				dtAim_Time_RHStart = dtAim_Time_RHEnd - dtAim_RHProcessTime;
				dtAim_Time_RHArrival = dtAim_Time_RHStart - dtAim_RHWaitTime;
				dtAim_Time_BOFSided = dtAim_Time_RHArrival;

			}
			else
			{
				if(csRefine_Type == _T("LR"))
				{
					dtAim_Time_RHLeave = dtAim_Time_CasterArrival;
					dtAim_Time_RHEnd = dtAim_Time_RHLeave - dtAim_RHWaitTime;
					dtAim_Time_RHStart = dtAim_Time_RHEnd - dtAim_RHProcessTime;
					dtAim_Time_RHArrival = dtAim_Time_RHStart - dtAim_RHWaitTime;
					dtAim_Time_LFLeave = dtAim_Time_RHArrival;
					dtAim_Time_LFEnd = dtAim_Time_LFLeave - dtAim_LFWaitTime;
					dtAim_Time_LFStart = dtAim_Time_LFEnd - dtAim_LFProcessTime;
					dtAim_Time_LFArrival = dtAim_Time_LFStart - dtAim_LFWaitTime;
					dtAim_Time_BOFSided = dtAim_Time_LFArrival;

				}
				else
				{
					dtAim_Time_LFLeave = dtAim_Time_CasterArrival;
					dtAim_Time_LFEnd = dtAim_Time_LFLeave - dtAim_LFWaitTime;
					dtAim_Time_LFStart = dtAim_Time_LFEnd - dtAim_LFProcessTime;
					dtAim_Time_LFArrival = dtAim_Time_LFStart - dtAim_LFWaitTime;
					dtAim_Time_RHLeave = dtAim_Time_LFArrival;
					dtAim_Time_RHEnd = dtAim_Time_RHLeave - dtAim_RHWaitTime;
					dtAim_Time_RHStart = dtAim_Time_RHEnd - dtAim_RHProcessTime;
					dtAim_Time_RHArrival = dtAim_Time_RHStart - dtAim_RHWaitTime;
					dtAim_Time_BOFSided = dtAim_Time_RHArrival;
				}

			}
		}

	}
	//dtAim_Time_BOFSided = dtAim_Time_LFStart;
	dtAim_Time_BOFTapped = dtAim_Time_BOFSided - dtAim_BOFSideTime;
	dtAim_Time_BOFStart = dtAim_Time_BOFTapped - dtAim_BOFProcessTime;
	dtAim_Time_IronPrepared = dtAim_Time_BOFStart - dtAim_IronPrepareTime;

	//设置对象属性
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_IronPrepared"), dtAim_Time_IronPrepared))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_BOFStart"), dtAim_Time_BOFStart))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_BOFTapped"), dtAim_Time_BOFTapped))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_TappedSideEnd"), dtAim_Time_BOFSided))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_LFArrival"), dtAim_Time_LFArrival))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_LFStart"), dtAim_Time_LFStart))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_LFEnd"), dtAim_Time_LFEnd))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_LFLeave"), dtAim_Time_LFLeave))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_RHArrival"), dtAim_Time_RHArrival))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_RHStart"), dtAim_Time_RHStart))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_RHEnd"), dtAim_Time_RHEnd))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_RHLeave"), dtAim_Time_RHLeave))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_CasterArrival"), dtAim_Time_CasterArrival))
		return -5;
	if (!SetObjectPropValue(csPlanUri, _T("Aim_Time_CastingEnd"), dtAim_Time_CastingEnd))
		return -5;

	return 0;
}

/// <Method class="CPlan_Mag" name="GetCurHeatPlanInfor" type="L3RECORDSET">
/// 
/// 获取当前炉次计划信息
/// ARG &gt;&gt; strPreHetaID: 预定炉号。
/// RET &gt;&gt; 找到的计划记录集。
/// <Param name="strPreHeatID" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CPlan_Mag::GetCurHeatPlanInfor(L3STRING strPreHeatID)
{
	CString csPlanID = strPreHeatID;
	CString csTemp = _T("select * from %s where PlanID ='%s'");
	CString csSQL;
	csSQL.Format(PLAN_TAPPING_CLASS_URI,csPlanID);
	CL3RecordSetWrap rsL3PlanData;
	if(!Query(csSQL,rsL3PlanData) || rsL3PlanData.IsNull() || rsL3PlanData.GetRowCount() < 1)
		return NULL;
	return rsL3PlanData.Detach();// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanChangeRoute" type="L3LONG">
/// 
/// 更改工艺路径
/// ARG&gt;&gt; rsData: 更新数据集。
/// RET &lt;&lt; 成功返回0；失败返回出错代码。
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CPlan_Mag::TappingPlanChangeRoute(L3RECORDSET rsData)
{
	CL3RecordSetWrap rspPlaData =rsData;
	if( rspPlaData.IsNull() || rspPlaData.GetRowCount() < 1)
		return -1;
	if(rspPlaData.GetFieldIndex(_T("LFID")) < 0 ||
	rspPlaData.GetFieldIndex(_T("RHID")) < 0 ||
	rspPlaData.GetFieldIndex(_T("PreHeatID")) < 0)
		return -1;

	rspPlaData.MoveFirst();

	CL3Variant vsTemp = rspPlaData.GetFieldByName(_T("PreHeatID"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csPreHeatID = vsTemp.ToCString();

	vsTemp = rspPlaData.GetFieldByName(_T("LFID"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csLFID = vsTemp.ToCString();

	vsTemp = rspPlaData.GetFieldByName(_T("RHID"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csRHID = vsTemp.ToCString();

	CString csPlanObjUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	CString csPlanActObjUri = PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPreHeatID;

	vsTemp = GetObjectPropValue(csPlanObjUri,_T("LFID"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csOldLFID = vsTemp.ToCString();

	vsTemp = GetObjectPropValue(csPlanObjUri,_T("RHID"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csOldRHID = vsTemp.ToCString();

	if(csLFID ==csOldLFID && csRHID ==csOldRHID)
		return 0;//未作修改

	vsTemp = GetObjectPropValue(csPlanObjUri,_T("CasterID"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csCasterID = vsTemp.ToCString();

	//得到钢包类型
	vsTemp = GetObjectPropValue(csPlanObjUri,_T("New_BOF_Flag"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	L3SHORT nNewBOF = vsTemp.ToShort();

	//得到精炼工序状态
	vsTemp = GetObjectPropValue(csPlanObjUri,_T("LF_Status"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csLFStatus = vsTemp.ToCString();

	vsTemp = GetObjectPropValue(csPlanObjUri,_T("RH_Status"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csRHStatus = vsTemp.ToCString();

	//得到铸机状态
	vsTemp = GetObjectPropValue(csPlanObjUri,_T("Caster_Status"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csCasterStatus = vsTemp.ToCString();
	//大包上铸机不允许更改工艺路径
	if(csCasterStatus!=TAPPING_PLAN_CCM_STATUS_UNEXCUTING)
		return -99;

	//判断更改是否合法
	if(nNewBOF)
	{
		if(csLFID == UNIT_ID_1LF || csLFID == UNIT_ID_2LF)
			return -11;//80t钢包工艺路径不允许经过1#2#LF
		if(csLFStatus != TAPPING_PLAN_LF_STATUS_UNEXCUTING && csRHStatus != TAPPING_PLAN_RH_STATUS_UNEXCUTING)
			return -31;//精品线LFRH都开始执行了不允许更改工艺路径
		if(csLFStatus != TAPPING_PLAN_LF_STATUS_UNEXCUTING && csRHStatus == TAPPING_PLAN_RH_STATUS_UNEXCUTING)
		{
			if(csLFID !=csOldLFID)
			return -35;//LF都开始执行了不允许更改LF工艺路径	
		}
		if(csLFStatus == TAPPING_PLAN_LF_STATUS_UNEXCUTING && csRHStatus != TAPPING_PLAN_RH_STATUS_UNEXCUTING)
		{
			if(csRHID !=csOldRHID)
			return -36;//RH都开始执行了不允许更改RH工艺路径	
		}
				
	}
	else
	{
		if(csLFID == UNIT_ID_3LF || csRHID == UNIT_ID_1RH)
			return -12;//50t钢包工艺路径不允许经过精品线
		if(csLFStatus != TAPPING_PLAN_LF_STATUS_UNEXCUTING)
			return -32;//老线LF都开始执行了不允许更改工艺路径
	}

	//得到精炼区分
	vsTemp = GetObjectPropValue(csPlanObjUri,_T("Refine_Type"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csOldRefineFlag = vsTemp.ToCString();

	//创建当前计划新的精炼区分
	CString csNewRefineFlag;
	if(csLFID!=_T("0") && csRHID !=_T("0"))
		csNewRefineFlag =_T("LR");
	else
		if(csLFID ==_T("0") && csRHID !=_T("0"))
			csNewRefineFlag =_T("R");
		else
			if(csLFID !=_T("0") && csRHID ==_T("0"))
				csNewRefineFlag = _T("L");
			else
				csNewRefineFlag =_T("0");

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	//移动缓存里的钢水到相应位置
	vsTemp = GetObjectPropValue(csPlanObjUri,_T("HeatID"));
	if(!vsTemp.IsValid() || vsTemp.IsError() || vsTemp.IsNull())
		return -1;
	CString csHeatID = vsTemp.ToCString();
	CString csCache = GetCurSteelCache(csHeatID);
	CString csUnitType = csCache.Mid(1,1);

	//原先不经过精炼的
	if(csOldRefineFlag ==_T("0") && csUnitType ==UNIT_TYPE_CASTER && csNewRefineFlag !=_T("0"))
	{
		//移走钢水
		if(MoveSteelFromCache(csCache,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -33;
		}	
		CString csCacheUri;
		if(csNewRefineFlag ==_T("L") || csNewRefineFlag ==_T("LR"))
			csCacheUri = csLFID + _T("P01");
		if(csNewRefineFlag ==_T("R") || csNewRefineFlag ==_T("RL"))
			csCacheUri = csRHID + _T("P01");
		if(AddSteelToCache(csCacheUri,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -34;
		}

	}
	//LF未处理
	if((csOldRefineFlag ==_T("L") || csOldRefineFlag ==_T("LR")) && csUnitType ==UNIT_TYPE_LF)
	{
		//移走钢水
		if(MoveSteelFromCache(csCache,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -33;
		}
		CString csCacheUri;
		if(csNewRefineFlag ==_T("L") || csNewRefineFlag ==_T("LR"))
			csCacheUri = csLFID + _T("P01");
		if(csNewRefineFlag ==_T("R") || csNewRefineFlag ==_T("RL"))
			csCacheUri = csRHID + _T("P01");
		if(csNewRefineFlag ==_T("0"))
			csCacheUri = csCasterID + _T("P01");	
		if(AddSteelToCache(csCacheUri,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -34;
		}
	}
	//LF处理完毕,钢水到铸机，这时新的精炼区分只能是LR
	if(csOldRefineFlag ==_T("L") && csUnitType ==UNIT_TYPE_CASTER)
	{
		//移走钢水
		if(MoveSteelFromCache(csCache,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -33;
		}
		CString csCacheUri;
		if(csNewRefineFlag ==_T("LR"))
			csCacheUri = csRHID + _T("P01");
	
		if(AddSteelToCache(csCacheUri,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -34;
		}
	}

	
	//LF处理完毕,钢水到RH，这时新的精炼区分只能是L
	if(csOldRefineFlag ==_T("LR")&& csUnitType ==UNIT_TYPE_RH)
	{
		//移走钢水
		if(MoveSteelFromCache(csCache,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -33;
		}
		CString csCacheUri;

		if(csNewRefineFlag ==_T("L"))
			csCacheUri = csCasterID + _T("P01");

		if(AddSteelToCache(csCacheUri,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -34;
		}
	}

	//RH未处理
	if((csOldRefineFlag ==_T("R")|| csOldRefineFlag ==_T("RL"))&& csUnitType ==UNIT_TYPE_RH)
	{
		//移走钢水
		if(MoveSteelFromCache(csCache,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -33;
		}
		CString csCacheUri;
		if(csNewRefineFlag ==_T("L") || csNewRefineFlag ==_T("LR"))
			csCacheUri = csLFID + _T("P01");
		if(csNewRefineFlag ==_T("R") || csNewRefineFlag ==_T("RL"))
			csCacheUri = csRHID + _T("P01");
		if(csNewRefineFlag ==_T("0"))
			csCacheUri = csCasterID + _T("P01");	
		if(AddSteelToCache(csCacheUri,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -34;
		}
	}

	//RH处理完毕,钢水到铸机，这时新的精炼区分只能是RL
	if(csOldRefineFlag ==_T("R") && csUnitType ==UNIT_TYPE_CASTER)
	{
		//移走钢水
		if(MoveSteelFromCache(csCache,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -33;
		}
		CString csCacheUri;
		if(csNewRefineFlag ==_T("RL"))
			csCacheUri = csLFID + _T("P01");
	
		if(AddSteelToCache(csCacheUri,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -34;
		}
	}

	
	//RH处理完毕,钢水到LF，这时新的精炼区分只能是R
	if(csOldRefineFlag ==_T("RL")&& csUnitType ==UNIT_TYPE_LF)
	{
		//移走钢水
		if(MoveSteelFromCache(csCache,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -33;
		}
		CString csCacheUri;

		if(csNewRefineFlag ==_T("R"))
			csCacheUri = csCasterID + _T("P01");

		if(AddSteelToCache(csCacheUri,csHeatID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -34;
		}
	}

	if(!SetObjectPropValue(csPlanObjUri,_T("Refine_Type"),CL3Variant(csNewRefineFlag)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	//只有状态为未执行的才能修改
	if(csLFStatus == TAPPING_PLAN_LF_STATUS_UNEXCUTING)
	{
		if(!SetObjectPropValue(csPlanObjUri,_T("LFID"),CL3Variant(csLFID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
		if(!SetObjectPropValue(csPlanActObjUri,_T("LFID"),CL3Variant(csLFID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}

	}

    if(csRHStatus == TAPPING_PLAN_RH_STATUS_UNEXCUTING)
	{
		if(!SetObjectPropValue(csPlanObjUri,_T("RHID"),CL3Variant(csRHID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		if(!SetObjectPropValue(csPlanActObjUri,_T("RHID"),CL3Variant(csRHID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}

	}

	COleDateTime odtCurrentDate = COleDateTime::GetCurrentTime();
	CString cstrCurrentDate = odtCurrentDate.Format(_T("%Y"));

	//2008-12-30 tangyi屏蔽一下代码
	//重新计算LF处理号
	/*CString csSQL;
	CString	cstrTemp;
	if(nNewBOF)
	{
				cstrTemp  = _T(" Select * from %s                                                     ");
				cstrTemp += _T(" where LF_Status ='01' and Caster_Status = '01' and New_BOF_Flag = 1  ");
				cstrTemp += _T(" order by Aim_Time_IronPrepared                                       ");	
	}
	else
	{
				cstrTemp  = _T(" Select * from %s                                                     ");
				cstrTemp += _T(" where LF_Status ='01' and Caster_Status = '01' and New_BOF_Flag = 0  ");
				cstrTemp += _T(" order by Aim_Time_IronPrepared                                       ");		
	}
	CL3RecordSetWrap rsLFPlaData;
	csSQL.Format(cstrTemp,PLAN_TAPPING_CLASS_URI);
	if(!Query(csSQL,rsLFPlaData) || rsLFPlaData.IsNull() || rsLFPlaData.GetRowCount() < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}*/

	//rsLFPlaData.MoveFirst();
	//while(!rsLFPlaData.IsEOF())
	//{
	//	//清空处理号
	//	vsTemp=rsLFPlaData.GetFieldByName(_T("PlanID"));
	//	CString csPlanID=vsTemp.ToCString();
	//	CString csObjectUri=PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPlanID;
	//	if(!SetObjectPropValue(csObjectUri,_T("LF_TreatNo"),CL3Variant(_T("0"))))
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return -6;
	//	}
	//	rsLFPlaData.MoveNext();
	//}

	//rsLFPlaData.MoveFirst();
	//while(!rsLFPlaData.IsEOF())
	//{
	//	//计算处理号
	//	vsTemp=rsLFPlaData.GetFieldByName(_T("PlanID"));
	//	CString csPlanID=vsTemp.ToCString();
	//	CString csObjectUri=PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPlanID;

	//	vsTemp=rsLFPlaData.GetFieldByName(_T("LFID"));
	//	CString csLFID=vsTemp.ToCString();

	//	if(csLFID!=_T("0"))
	//	{
	//		L3LONG lTemp = GetHeatMaxProcessNo(UNIT_AREA_LF, csLFID) + 1;		//循环次数为i + 1
	//		CString csTempTreatNo;
	//		csTempTreatNo.Format(_T("%05d"), lTemp);
	//		CString csLFTreatNo = csLFID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempTreatNo;
	//		if(!SetObjectPropValue(csObjectUri,_T("LF_TreatNo"),CL3Variant(csLFTreatNo)))
	//		{
	//			if(bUseTrans)
	//				Rollback(nTrans);
	//			return -7;
	//		}
	//	}

		/*rsLFPlaData.MoveNext();
	}*/

	//if(nNewBOF)
	//{
	//	//重新计算RH处理号
	//	cstrTemp  = _T(" Select * from %s                                                      ");
	//	cstrTemp += _T(" where RH_Status ='01' and Caster_Status = '01'  and New_BOF_Flag = 1  ");
	//	cstrTemp += _T(" order by Aim_Time_IronPrepared                                        ");
	//	CL3RecordSetWrap rsRHPlaData;
	//	csSQL.Format(cstrTemp,PLAN_TAPPING_CLASS_URI);
	//	if(!Query(csSQL,rsRHPlaData) || rsRHPlaData.IsNull() || rsRHPlaData.GetRowCount() < 1)
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return -8;
	//	}

	//	rsRHPlaData.MoveFirst();
	//	while(!rsRHPlaData.IsEOF())
	//	{
	//		//清空处理号
	//		vsTemp=rsRHPlaData.GetFieldByName(_T("PlanID"));
	//		CString csPlanID=vsTemp.ToCString();
	//		CString csObjectUri=PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPlanID;
	//		if(!SetObjectPropValue(csObjectUri,_T("RH_TreatNo"),CL3Variant(_T("0"))))
	//		{
	//			if(bUseTrans)
	//				Rollback(nTrans);
	//			return -9;
	//		}
	//		rsRHPlaData.MoveNext();
	//	}

		//rsRHPlaData.MoveFirst();
		//while(!rsRHPlaData.IsEOF())
		//{
		//	//计算处理号
		//	vsTemp=rsRHPlaData.GetFieldByName(_T("PlanID"));
		//	CString csPlanID=vsTemp.ToCString();
		//	CString csObjectUri=PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPlanID;

		//	vsTemp=rsRHPlaData.GetFieldByName(_T("RHID"));
		//	CString csRHID=vsTemp.ToCString();

		//	//if(csRHID!=_T("0"))
		//	//{
		//	//	L3LONG lTemp = GetHeatMaxProcessNo(UNIT_AREA_RH, csRHID) + 1;		//循环次数为i + 1
		//	//	CString csTempTreatNo;
		//	//	csTempTreatNo.Format(_T("%05d"), lTemp);
		//	//	CString csRHTreatNo = csRHID.Mid(2,1) + cstrCurrentDate.Mid(2,2) + csTempTreatNo;
		//	//	if(!SetObjectPropValue(csObjectUri,_T("RH_TreatNo"),CL3Variant(csRHTreatNo)))
		//	//	{
		//	//		if(bUseTrans)
		//	//			Rollback(nTrans);
		//	//		return -10;
		//	//	}
		//	//}

		//	rsRHPlaData.MoveNext();
		//}
	//}

	//
	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

	return 0;// TODO : 请在此添加逻辑代码
}

/// <Method class="CPlan_Mag" name="TappingPlanExchangeTreatSeq" type="L3LONG">
/// 
/// 交换铸机处理顺序号
/// ARG&gt;&gt; PreHeatID1 : 预定炉号1。
///  &gt;&gt;PreHeatID2 : 预定炉号2。
/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
/// <Param name="PreHeatID1" type="L3STRING">预定炉号</Param>
/// <Param name="PreHeatID2" type="L3STRING">预定炉号</Param>
/// </Method>
L3LONG CPlan_Mag::TappingPlanExchangeTreatSeq(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
    if( rs.IsNull() || rs.GetRowCount() !=2 )
		return -1;
	if(rs.GetFieldIndex(_T("PlanID")) < 0 )
		return -1;

	rs.MoveFirst();
	CString csPreHeatID1 = rs.GetFieldByName(_T("PlanID")).ToCString();
	rs.MoveNext();
	CString csPreHeatID2 = rs.GetFieldByName(_T("PlanID")).ToCString();

	//计划对象URI
	CString csObjectUri1 = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID1;
	CString csObjectUri2 = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID2;

	CL3Variant vsCasterID1 = GetObjectPropValue(csObjectUri1,_T("CasterID"));
	if(!vsCasterID1.IsValid() || vsCasterID1.IsError() || vsCasterID1.IsNull())
		return -1;
	CL3Variant vsCasterID2 = GetObjectPropValue(csObjectUri2,_T("CasterID"));
	if(!vsCasterID2.IsValid() || vsCasterID2.IsError() || vsCasterID2.IsNull())
		return -2;
	CString csCasterID1=vsCasterID1.ToCString();
	CString csCasterID2=vsCasterID2.ToCString();
	//不是同一铸机退出
	if(csCasterID1!=csCasterID2)
		return -3;
	//CL3Variant vsStatus1 = GetObjectPropValue(csObjectUri1,_T("Status"));
	//if(!vsCasterID1.IsValid() || vsCasterID1.IsError() || vsCasterID1.IsNull())
	//	return -4;
	//CL3Variant vsStatus2 = GetObjectPropValue(csObjectUri2,_T("Status"));
	//if(!vsCasterID2.IsValid() || vsCasterID2.IsError() || vsCasterID2.IsNull())
	//	return -5;
	//CString csStatus1=vsStatus1.ToCString();
	//CString csStatus2=vsStatus2.ToCString();
	////状态为执行完成退出
	//if(csStatus1 == TAPPING_PLAN_STATUS_EXCUTED || csStatus2 == TAPPING_PLAN_STATUS_EXCUTED)
	//	return -6;

	//交换处理顺序号
	CL3Variant vsSeq1 = GetObjectPropValue(csObjectUri1,_T("Treat_Seq"));
	if(!vsSeq1.IsValid() || vsSeq1.IsError() || vsSeq1.IsNull())
		return -7;
	CL3Variant vsSeq2 = GetObjectPropValue(csObjectUri2,_T("Treat_Seq"));
	if(!vsSeq2.IsValid() || vsSeq2.IsError() || vsSeq2.IsNull())
		return -8;
	CString csSeq1=vsSeq1.ToCString();
	CString csSeq2=vsSeq2.ToCString();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	if(!SetObjectPropValue(csObjectUri1,_T("Treat_Seq"),CL3Variant(csSeq2)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -9;
	}

	if(!SetObjectPropValue(csObjectUri2,_T("Treat_Seq"),CL3Variant(csSeq1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -10;
	}

	//2008-12-30 tangyi屏蔽以下代码计划中浇次号、处理号不用计算
	//交换浇次号
	/*CL3Variant vsCastingNo1 = GetObjectPropValue(csObjectUri1,_T("Casting_No"));
	if(!vsCastingNo1.IsValid() || vsCastingNo1.IsError() || vsCastingNo1.IsNull())
		return -11;
	CL3Variant vsCastingNo2 = GetObjectPropValue(csObjectUri2,_T("Casting_No"));
	if(!vsCastingNo2.IsValid() || vsCastingNo2.IsError() || vsCastingNo2.IsNull())
		return -12;
	CString csCastingNo1=vsCastingNo1.ToCString();
	CString csCastingNo2=vsCastingNo2.ToCString();

	if(!SetObjectPropValue(csObjectUri1,_T("Casting_No"),CL3Variant(vsCastingNo2)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -13;
	}

	if(!SetObjectPropValue(csObjectUri2,_T("Casting_No"),CL3Variant(vsCastingNo1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -14;
	}*/

	//交换浇次内处理顺序号
	/*CL3Variant vsCastingHeatNo1 = GetObjectPropValue(csObjectUri1,_T("Casting_Heat_Cnt"));
	if(!vsCastingHeatNo1.IsValid() || vsCastingHeatNo1.IsError() || vsCastingHeatNo1.IsNull())
		return -15;
	CL3Variant vsCastingHeatNo2 = GetObjectPropValue(csObjectUri2,_T("Casting_Heat_Cnt"));
	if(!vsCastingHeatNo2.IsValid() || vsCastingHeatNo2.IsError() || vsCastingHeatNo2.IsNull())
		return -16;
	CString csCastingHeatNo1=vsCastingHeatNo1.ToCString();
	CString csCastingHeatNo2=vsCastingHeatNo2.ToCString();

	if(!SetObjectPropValue(csObjectUri1,_T("Casting_Heat_Cnt"),CL3Variant(vsCastingHeatNo2)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -17;
	}

	if(!SetObjectPropValue(csObjectUri2,_T("Casting_Heat_Cnt"),CL3Variant(vsCastingHeatNo1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -18;
	}*/

	//交换处理号
	/*csObjectUri1 = PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPreHeatID1;
	csObjectUri2 = PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPreHeatID2;
	CL3Variant vsCastingTreatNo1 = GetObjectPropValue(csObjectUri1,_T("Caster_TreatNo"));
	if(!vsCastingTreatNo1.IsValid() || vsCastingTreatNo1.IsError() || vsCastingTreatNo1.IsNull())
		return -19;
	CL3Variant vsCastingTreatNo2 = GetObjectPropValue(csObjectUri2,_T("Caster_TreatNo"));
	if(!vsCastingTreatNo2.IsValid() || vsCastingTreatNo2.IsError() || vsCastingTreatNo2.IsNull())
		return -20;
	CString csTreatNo1=vsCastingTreatNo1.ToCString();
	CString csTreatNo2=vsCastingTreatNo2.ToCString();

	if(!SetObjectPropValue(csObjectUri1,_T("Caster_TreatNo"),CL3Variant(csTreatNo2)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -21;
	}

	if(!SetObjectPropValue(csObjectUri2,_T("Caster_TreatNo"),CL3Variant(csTreatNo1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -22;
	}*/

	if(bUseTrans)
		Commit(nTrans);

	ChangeRsTappingPlanValue();

	return 0;// TODO : 请在此添加逻辑代码
}



/// <Method class="CPlan_Mag" name="CalcBOFProcessEndTime" type="L3LONG">
/// 
/// 计算转炉出钢时间
/// ARG&gt;&gt; nBOFID : 炉座号。
/// &gt;&gt;dtBOFProcessEndTime : 出钢时间。
/// &gt;&gt;dtCurrIronPreparedTime：兑铁时间
/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
/// <Param name="nBOFID" type="L3STRING">炉座号</Param>
/// <Param name="dtBOFProcessEndTime" type="L3DATETIME">出钢时间</Param>
/// <Param name="dtCurrIronPreparedTime" type="L3DATETIME">兑铁时间</Param>
/// </Method>

L3LONG CPlan_Mag::CalcBOFProcessEndTime(CString csBOFID, 
									   L3DATETIME &dtBOFProcessEndTime, 
									   L3DATETIME dtCurrIronPreparedTime)
{
	COleDateTime curTime= COleDateTime::GetCurrentTime();
	CString cstrCurTime=curTime.Format(_T("%Y%m%d%H%M%S"));

	CString csTemp = _T(" Select Aim_Time_BOFTapped,HeatID,SteelGradeIndex,             ");
	        csTemp+= _T(" BOF_Status from %s where BOFID= '%s' and                  ");
			csTemp+= _T(" Aim_Time_IronPrepared < ? order by Aim_Time_BOFTapped desc    ");
	CString csSQL;
	csSQL.Format(csTemp,PLAN_TAPPING_CLASS_URI,csBOFID);
	VARIANT valParams[1];
	valParams[0].vt = VT_DATE; valParams[0].date = dtCurrIronPreparedTime;
	CL3RecordSetWrap rsAim_Time_BOFTapped;
	L3BOOL bRet = QueryWithParam(csSQL,valParams,1,rsAim_Time_BOFTapped);
	if(!bRet || rsAim_Time_BOFTapped.IsNull())
		return -1;

	CL3Variant valTemp;
	//不存在计划
	if (rsAim_Time_BOFTapped.GetRowCount() == 0)
	{
		dtBOFProcessEndTime = 0;
		return 0;
	}
	rsAim_Time_BOFTapped.MoveFirst();

	valTemp = rsAim_Time_BOFTapped.GetFieldByName(_T("HeatID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
	{
		//熔炼号不存在，则按照计划时间给值
		valTemp = rsAim_Time_BOFTapped.GetFieldByName(_T("Aim_Time_BOFTapped"));
		if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
			return -1;
		dtBOFProcessEndTime = valTemp.ToDateTime();
		return 0;
	}
	CString csHeatID = valTemp.ToCString();

	valTemp = rsAim_Time_BOFTapped.GetFieldByName(_T("BOF_Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
	{
		//不存在，则按照计划时间给值
		valTemp = rsAim_Time_BOFTapped.GetFieldByName(_T("Aim_Time_BOFTapped"));
		if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
			return -1;
		dtBOFProcessEndTime = valTemp.ToDateTime();
	}
	else
	{
		CString csBOFStatus = valTemp.ToCString();
		//按状态对出钢结束时间赋值
		if(csBOFStatus== TAPPING_PLAN_BOF_STATUS_TAPPED)
		{
			//查询实绩作业时间
			CString cstrSQLAct = _T("Select Act_Time_BOFTapped from %s where HeatID = '%s' ");
			csSQL.Format(cstrSQLAct,PLAN_TAPPING_ACT_CLASS_URI,csHeatID);
			CL3RecordSetWrap rsTappingPlanActual;
			if (!Query(csSQL,rsTappingPlanActual) || rsTappingPlanActual.IsNull() || (rsTappingPlanActual.GetRowCount() != 1))
				return -1;
			rsTappingPlanActual.MoveFirst();
			valTemp = rsTappingPlanActual.GetFieldByName(_T("Act_Time_BOFTapped"));
			dtBOFProcessEndTime = valTemp.ToDateTime();
			if (dtBOFProcessEndTime < 30000)			//错误的实绩时间不加入计算
			{
				valTemp = rsAim_Time_BOFTapped.GetFieldByName(_T("Aim_Time_BOFTapped"));
				dtBOFProcessEndTime = valTemp.ToDateTime();
			}
		}
		else
		{
			valTemp = rsAim_Time_BOFTapped.GetFieldByName(_T("Aim_Time_BOFTapped"));
			dtBOFProcessEndTime = valTemp.ToDateTime();

		}

	}	
	//按熔炼号查询非转炉作业时间
	CString cstrSQL = _T("Select * from %s where HeatID = '%s' ");
	csSQL.Format(cstrSQL,PLAN_BOF_NON_PROC_CLASS_URI,csHeatID);
	CL3RecordSetWrap rspBOFNoProcessTime;
	
	if (!Query(csSQL,rspBOFNoProcessTime))
		return -2;

	if (rspBOFNoProcessTime.GetRowCount() == 1)
	{
		rspBOFNoProcessTime.MoveFirst();
		valTemp = rspBOFNoProcessTime.GetFieldByName(_T("Aim_Time_BOFRepared"));
		dtBOFProcessEndTime += (valTemp.ToDouble())/1440;

		valTemp = rspBOFNoProcessTime.GetFieldByName(_T("Aim_Time_BlowN2"));
		dtBOFProcessEndTime += (valTemp.ToDouble())/1440;
	}

	//查询检修计划
	cstrSQL = _T("Select * from %s where UnitID='%s' and Unit_TypeID='%s' and EndStopTime_Aim > ? order by EndStopTime_Aim ");
	csSQL.Format(cstrSQL,PLAN_EQUIMENT_CLASS_URI,csBOFID,UNIT_TYPE_BOF);
	VARIANT valParams1[1];
	valParams1[0].vt = VT_DATE; valParams1[0].date = dtBOFProcessEndTime;
	CL3RecordSetWrap rsEquipmentStoppingPlan;
	if (!QueryWithParam(csSQL,valParams1,1,rsEquipmentStoppingPlan))
		return -3;

	if (rsEquipmentStoppingPlan.GetRowCount() < 1)
		return 0;

	rsEquipmentStoppingPlan.MoveFirst();
	valTemp = rsEquipmentStoppingPlan.GetFieldByName(_T("BeginStopTime_Aim"));
	L3DATETIME dtBeginStopTime_Aim = valTemp.ToDateTime();

	//本炉作业完毕时刻在检修开始时刻之前，炉次作业时间推后至检修结束
	//计算距离开始检修时刻最近的炉次的下一炉的作业开始时间（最近的炉次的出钢时间）
	if (dtBOFProcessEndTime > dtBeginStopTime_Aim)
	{
		valTemp = rsEquipmentStoppingPlan.GetFieldByName(_T("EndStopTime_Aim"));		
		dtBOFProcessEndTime = valTemp.ToDateTime();
	}
	return 0;
 }


/// <Method class="CPlan_Mag" name="CalcUnitOneToOneTime" type="L3LONG">
/// 
/// 计算一炉的工位间移动时间
/// ARG&gt;&gt; csPreHeatID : 预定炉号。
/// RET &lt;&lt; 成功返回TRUE；失败返回出错代码。
/// <Param name="csPreHeatID" type="L3STRING">预定炉号</Param>
/// </Method>
 L3LONG CPlan_Mag::CalcUnitOneToOneTime(CString csPreHeatID)
{
	//已经过路程计算则退出
	CString cstrURI = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	
	CL3Variant valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd")); 
	L3DATETIME dtAim_Time_TappedSideEnd = valTemp.ToDateTime();
	valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFArrival")); 
	L3DATETIME dtAim_Time_LFArrival = valTemp.ToDateTime();
	valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_CasterArrival")); 
	L3DATETIME dtAim_Time_CasterArrival = valTemp.ToDateTime();
	valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHArrival")); 
	L3DATETIME Aim_Time_RHArrival = valTemp.ToDateTime();
	if (dtAim_Time_TappedSideEnd != dtAim_Time_LFArrival && dtAim_Time_TappedSideEnd != dtAim_Time_CasterArrival && dtAim_Time_TappedSideEnd != Aim_Time_RHArrival)
		return 0;

	//得到工艺路径
	valTemp = GetObjectPropValue(cstrURI, _T("BOFID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csBOFUnit = valTemp.ToCString();

	valTemp = GetObjectPropValue(cstrURI, _T("LFID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csLFUnit = valTemp.ToCString();

	valTemp = GetObjectPropValue(cstrURI, _T("RHID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csRHUnit = valTemp.ToCString();

	valTemp = GetObjectPropValue(cstrURI, _T("CasterID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csCastUnit = valTemp.ToCString();

	valTemp = GetObjectPropValue(cstrURI, _T("Refine_Type"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csRefineType = valTemp.ToCString();

	//得到工艺路径

	//查询标准工序移动时间

	L3DATETIME dtBOFToLF = 0;
	L3DATETIME dtBOFToRH = 0;
	L3DATETIME dtBOFToCaster = 0;
	L3DATETIME dtLFToRH = 0;
	L3DATETIME dtLFToCaster = 0;
	L3DATETIME dtRHToCaster = 0;
	L3DATETIME dtRHToLF = 0;
	

	if(csRefineType == _T("0"))//不经过LF/RH
	{
		//得到转炉到铸机时间
		dtBOFToCaster = GetUnitOneToOneTime(csBOFUnit,csCastUnit);

		//设置转炉处理时刻
		valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"));
		L3DATETIME dtBOFProcess = valTemp.ToDateTime();
		dtBOFProcess -= dtBOFToCaster;
		if (!SetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"), dtBOFProcess))
			return -2;

		valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"));
		dtBOFProcess = valTemp.ToDateTime();
		dtBOFProcess -= dtBOFToCaster;
		if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"), dtBOFProcess))
			return -2;

		valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"));
		dtBOFProcess = valTemp.ToDateTime();
		dtBOFProcess -= dtBOFToCaster;
		if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"), dtBOFProcess))
			return -2;

		valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"));
		dtBOFProcess = valTemp.ToDateTime();
		dtBOFProcess -= dtBOFToCaster;
		if (!SetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"), dtBOFProcess))
			return -2;		
	}
	else
	{
		if(csRefineType == _T("L"))//经过LF不经过RH
		{
			//得到转炉到LF的时间
			dtBOFToLF = GetUnitOneToOneTime(csBOFUnit,csLFUnit);
			//LF到铸机的时间
			dtLFToCaster = GetUnitOneToOneTime(csLFUnit,csCastUnit);

			//设置LF处理时刻
			valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFLeave"));
			L3DATETIME dtAim_Time_LFLeave = valTemp.ToDateTime();
			dtAim_Time_LFLeave -= dtLFToCaster;
			if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFLeave"), dtAim_Time_LFLeave))
				return -2;

			valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFEnd"));
			L3DATETIME dtAim_Time_LFEnd = valTemp.ToDateTime();
			dtAim_Time_LFEnd -= dtLFToCaster;
			if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFEnd"), dtAim_Time_LFEnd))
				return -2;

			valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFStart"));
			L3DATETIME dtAim_Time_LFStart = valTemp.ToDateTime();
			dtAim_Time_LFStart -= dtLFToCaster;
			if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFStart"), dtAim_Time_LFStart))
				return -2;

			valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFArrival"));
			L3DATETIME dtAim_Time_LFArrival = valTemp.ToDateTime();
			dtAim_Time_LFArrival -= dtLFToCaster;
			if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFArrival"), dtAim_Time_LFArrival))
				return -2;

			//设置转炉处理时刻
			L3DATETIME dtBOFAheadTime = dtLFToCaster + dtBOFToLF;
			valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"));
			L3DATETIME dtBOFProcess = valTemp.ToDateTime();
			dtBOFProcess -= dtBOFAheadTime;
			if (!SetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"), dtBOFProcess))
				return -2;

			valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"));
			dtBOFProcess = valTemp.ToDateTime();
			dtBOFProcess -= dtBOFAheadTime;
			if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"), dtBOFProcess))
				return -2;

			valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"));
			dtBOFProcess = valTemp.ToDateTime();
			dtBOFProcess -= dtBOFAheadTime;
			if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"), dtBOFProcess))
				return -2;

			valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"));
			dtBOFProcess = valTemp.ToDateTime();
			dtBOFProcess -= dtBOFAheadTime;
			if (!SetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"), dtBOFProcess))
				return -2;
		}
		else
		{
			if(csRefineType == _T("R"))//经过RH不经过LF
			{
				//得到转炉到RH的时间
				dtBOFToRH = GetUnitOneToOneTime(csBOFUnit,csRHUnit);
				//RH到铸机的时间
				dtRHToCaster = GetUnitOneToOneTime(csRHUnit,csCastUnit);

				//设置RH处理时刻
				valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHLeave"));
				L3DATETIME dtAim_Time_RHLeave = valTemp.ToDateTime();
				dtAim_Time_RHLeave -= dtRHToCaster;
				if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHLeave"), dtAim_Time_RHLeave))
					return -2;

				valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHEnd"));
				L3DATETIME dtAim_Time_RHEnd = valTemp.ToDateTime();
				dtAim_Time_RHEnd -= dtRHToCaster;
				if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHEnd"), dtAim_Time_RHEnd))
					return -2;

				valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHStart"));
				L3DATETIME dtAim_Time_RHStart = valTemp.ToDateTime();
				dtAim_Time_RHStart -= dtRHToCaster;
				if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHStart"), dtAim_Time_RHStart))
					return -2;

				valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHArrival"));
				L3DATETIME dtAim_Time_RHArrival = valTemp.ToDateTime();
				dtAim_Time_RHArrival -= dtRHToCaster;
				if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHArrival"), dtAim_Time_RHArrival))
					return -2;

				//设置转炉处理时刻
				L3DATETIME dtBOFAheadTime = dtRHToCaster + dtBOFToRH;
				valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"));
				L3DATETIME dtBOFProcess = valTemp.ToDateTime();
				dtBOFProcess -= dtBOFAheadTime;
				if (!SetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"), dtBOFProcess))
					return -2;

				valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"));
				dtBOFProcess = valTemp.ToDateTime();
				dtBOFProcess -= dtBOFAheadTime;
				if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"), dtBOFProcess))
					return -2;

				valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"));
				dtBOFProcess = valTemp.ToDateTime();
				dtBOFProcess -= dtBOFAheadTime;
				if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"), dtBOFProcess))
					return -2;

				valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"));
				dtBOFProcess = valTemp.ToDateTime();
				dtBOFProcess -= dtBOFAheadTime;
				if (!SetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"), dtBOFProcess))
					return -2;
			}
			else
			{
				if(csRefineType == _T("LR"))
				{
					//得到转炉到LF的时间
					dtBOFToLF = GetUnitOneToOneTime(csBOFUnit,csLFUnit);
					//LF到RH的时间
					dtLFToRH = GetUnitOneToOneTime(csLFUnit,csRHUnit);
					//RH到铸机的时间
					dtRHToCaster = GetUnitOneToOneTime(csRHUnit,csCastUnit);

					//设置RH处理时刻
					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHLeave"));
					L3DATETIME dtAim_Time_RHLeave = valTemp.ToDateTime();
					dtAim_Time_RHLeave -= dtRHToCaster;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHLeave"), dtAim_Time_RHLeave))
						return -2;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHEnd"));
					L3DATETIME dtAim_Time_RHEnd = valTemp.ToDateTime();
					dtAim_Time_RHEnd -= dtRHToCaster;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHEnd"), dtAim_Time_RHEnd))
						return -2;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHStart"));
					L3DATETIME dtAim_Time_RHStart = valTemp.ToDateTime();
					dtAim_Time_RHStart -= dtRHToCaster;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHStart"), dtAim_Time_RHStart))
						return -2;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHArrival"));
					L3DATETIME dtAim_Time_RHArrival = valTemp.ToDateTime();
					dtAim_Time_RHArrival -= dtRHToCaster;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHArrival"), dtAim_Time_RHArrival))
						return -2;

					//设置LF处理时刻
					L3DATETIME dtLFAheadTime = dtRHToCaster + dtLFToRH;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFLeave"));
					L3DATETIME dtAim_Time_LFLeave = valTemp.ToDateTime();
					dtAim_Time_LFLeave -= dtLFAheadTime;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFLeave"), dtAim_Time_LFLeave))
						return -2;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFEnd"));
					L3DATETIME dtAim_Time_LFEnd = valTemp.ToDateTime();
					dtAim_Time_LFEnd -= dtLFAheadTime;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFEnd"), dtAim_Time_LFEnd))
						return -2;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFStart"));
					L3DATETIME dtAim_Time_LFStart = valTemp.ToDateTime();
					dtAim_Time_LFStart -= dtLFAheadTime;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFStart"), dtAim_Time_LFStart))
						return -2;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFArrival"));
					L3DATETIME dtAim_Time_LFArrival = valTemp.ToDateTime();
					dtAim_Time_LFArrival -= dtLFAheadTime;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFArrival"), dtAim_Time_LFArrival))
						return -2;


					//设置转炉处理时刻
					L3DATETIME dtBOFAheadTime = dtRHToCaster + dtLFToRH + dtBOFToLF;
					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"));
					L3DATETIME dtBOFProcess = valTemp.ToDateTime();
					dtBOFProcess -= dtBOFAheadTime;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"), dtBOFProcess))
						return -2;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"));
					dtBOFProcess = valTemp.ToDateTime();
					dtBOFProcess -= dtBOFAheadTime;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"), dtBOFProcess))
						return -2;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"));
					dtBOFProcess = valTemp.ToDateTime();
					dtBOFProcess -= dtBOFAheadTime;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"), dtBOFProcess))
						return -2;

					valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"));
					dtBOFProcess = valTemp.ToDateTime();
					dtBOFProcess -= dtBOFAheadTime;
					if (!SetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"), dtBOFProcess))
						return -2;

				}
				else
				{
					if(csRefineType == _T("RL"))
					{
						//得到转炉到RH的时间
						dtBOFToRH = GetUnitOneToOneTime(csBOFUnit,csRHUnit);
						//RH到LF的时间
						dtRHToLF = GetUnitOneToOneTime(csRHUnit,csLFUnit);
						//LF到铸机的时间
						dtLFToCaster = GetUnitOneToOneTime(csLFUnit,csCastUnit);

						//设置LF处理时刻
						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFLeave"));
						L3DATETIME dtAim_Time_LFLeave = valTemp.ToDateTime();
						dtAim_Time_LFLeave -= dtLFToCaster;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFLeave"), dtAim_Time_LFLeave))
							return -2;

						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFEnd"));
						L3DATETIME dtAim_Time_LFEnd = valTemp.ToDateTime();
						dtAim_Time_LFEnd -= dtLFToCaster;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFEnd"), dtAim_Time_LFEnd))
							return -2;

						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFStart"));
						L3DATETIME dtAim_Time_LFStart = valTemp.ToDateTime();
						dtAim_Time_LFStart -= dtLFToCaster;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFStart"), dtAim_Time_LFStart))
							return -2;

						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_LFArrival"));
						L3DATETIME dtAim_Time_LFArrivel = valTemp.ToDateTime();
						dtAim_Time_LFArrivel -= dtLFToCaster;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_LFArrival"), dtAim_Time_LFArrivel))
							return -2;

						//设置RH处理时刻
						L3DATETIME dtRHAheadTime = dtLFToCaster + dtRHToLF;
						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHLeave"));
						L3DATETIME dtAim_Time_RHLeave = valTemp.ToDateTime();
						dtAim_Time_RHLeave -= dtRHAheadTime;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHLeave"), dtAim_Time_RHLeave))
							return -2;

						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHEnd"));
						L3DATETIME dtAim_Time_RHEnd = valTemp.ToDateTime();
						dtAim_Time_RHEnd -= dtRHAheadTime;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHEnd"), dtAim_Time_RHEnd))
							return -2;

						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHStart"));
						L3DATETIME dtAim_Time_RHStart = valTemp.ToDateTime();
						dtAim_Time_RHStart -= dtRHAheadTime;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHStart"), dtAim_Time_RHStart))
							return -2;

						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_RHArrival"));
						L3DATETIME dtAim_Time_RHArrival = valTemp.ToDateTime();
						dtAim_Time_RHArrival -= dtRHAheadTime;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_RHArrival"), dtAim_Time_RHArrival))
							return -2;

						//设置转炉处理时刻
						L3DATETIME dtBOFAheadTime = dtLFToCaster + dtRHToLF + dtBOFToRH;
						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"));
						L3DATETIME dtBOFProcess = valTemp.ToDateTime();
						dtBOFProcess -= dtBOFAheadTime;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_TappedSideEnd"), dtBOFProcess))
							return -2;

						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"));
						dtBOFProcess = valTemp.ToDateTime();
						dtBOFProcess -= dtBOFAheadTime;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFTapped"), dtBOFProcess))
							return -2;

						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"));
						dtBOFProcess = valTemp.ToDateTime();
						dtBOFProcess -= dtBOFAheadTime;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_BOFStart"), dtBOFProcess))
							return -2;

						valTemp = GetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"));
						dtBOFProcess = valTemp.ToDateTime();
						dtBOFProcess -= dtBOFAheadTime;
						if (!SetObjectPropValue(cstrURI, _T("Aim_Time_IronPrepared"), dtBOFProcess))
							return -2;

					}
				}


			}
		}

	}
	return 0;
}

/// <Method class="CPlan_Mag" name="GetUnitOneToOneTime" type="L3LONG">
/// 
/// 获取一炉的工位间移动时间
/// ARG&gt;&gt; StartUnit : 起始工序。
/// ARG&gt;&gt; EndUnit : 结束工序。
/// RET &lt;&lt; 成功返回移动时间。
/// <Param name="StartUnit" type="L3STRING">起始工序</Param>
/// <Param name="EndUnit" type="L3STRING">结束工序</Param>
/// </Method>
 L3DATETIME CPlan_Mag::GetUnitOneToOneTime(CString StartUnit,CString EndUnit)
 {
	CL3RecordSetWrap rsTransportReturn;
	L3DATETIME dtResult;
	CString csTemp = _T("Select Transport_Time from %s  Where Start_Unit = '%s' and End_Unit = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,QA_UNIT_TRANS_TIME_CLASS_URI,StartUnit,EndUnit);
	if (!Query(csSQL,rsTransportReturn))
		return 0;
	if (rsTransportReturn.GetRowCount() == 1)
	{
		rsTransportReturn.MoveFirst();
		CL3Variant valTemp = rsTransportReturn.GetFieldByName(_T("Transport_Time"));
		dtResult = (valTemp.ToDateTime())/1440;
	}
	else
		dtResult = 0;
	return dtResult;
 }

/// <Method class="CPlan_Mag" name="GetHeatMaxProcessNo" type="L3LONG">
/// 
/// 得到工序位最大处理号
/// ARG&gt;&gt; nUnitType : 工序。
/// ARG&gt;&gt; csUnitID : 工位。
/// RET &lt;&lt; 返回最大处理号。
/// <Param name="nUnitType" type="L3SHORT">工序</Param>
/// <Param name="csUnitID" type="L3STRING">工位</Param>
/// </Method>
 L3LONG CPlan_Mag::GetHeatMaxProcessNo(L3SHORT nUnitType, CString csUnitID)
{
	CString cstrProcessUnit,
			cstrProcessNo;
	bool bQueryBOF = false;
	switch(nUnitType)			//根据不同工序查询
	{
		case UNIT_AREA_BOF:
			{
				cstrProcessUnit = _T("BOFID");
				cstrProcessNo = _T("HeatID");
				bQueryBOF = true;
				break;
			}	
		case UNIT_AREA_LF:
			{
				cstrProcessUnit = _T("LFID");
				cstrProcessNo = _T("LF_TreatNo");
				break;
			}
		case UNIT_AREA_RH:
			{
				cstrProcessUnit = _T("RHID");
				cstrProcessNo = _T("RH_TreatNo");
				break;
			}
		case UNIT_AREA_CASTER:
			{
				cstrProcessUnit = _T("CasterID");
				cstrProcessNo = _T("Caster_TreatNo");
				break;
			}
		default:
			return 0;
	}

	CString csUnit = csUnitID.Mid(2,1);
	CString cstrQuery;

	if (bQueryBOF)
	{
		//组成查询语句
		cstrQuery = _T("Select Max(");
		cstrQuery += cstrProcessNo;
		cstrQuery += _T(") as MaxProcessNo from %s where ");
		cstrQuery += cstrProcessUnit;
		cstrQuery += _T("  = '%s' ");
		cstrQuery += _T(" and substr(");
		cstrQuery += cstrProcessNo;
		cstrQuery += _T(",2,1) = '%s' ");
		//加上年号解决跨年清零问题
		cstrQuery += _T("and to_char(CreateDate,'yyyy') = to_char(sysdate,'yyyy')");
	}
	else
	{
		//组成查询语句
		cstrQuery = _T("Select Max(");
		cstrQuery += cstrProcessNo;
		cstrQuery += _T(") as MaxProcessNo from %s where ");
		cstrQuery += cstrProcessUnit;
		cstrQuery += _T("  = '%s' ");
		cstrQuery += _T(" and substr(");
		cstrQuery += cstrProcessNo;
		cstrQuery += _T(",1,1) = '%s' ");
		//加上年号解决跨年清零问题
		cstrQuery += _T("and to_char(CreateDate,'yyyy') = to_char(sysdate,'yyyy')");

	}


	//设置参数
	CL3RecordSetWrap rsMaxProcessNo;
	CString csSQL;
	csSQL.Format(cstrQuery,PLAN_TAPPING_ACT_CLASS_URI,csUnitID,csUnit);
	if ((!Query(csSQL,rsMaxProcessNo)))
		return 0;

	L3LONG lMaxProcessNo = 0;

	//如果跨年处理号清零

	rsMaxProcessNo.MoveFirst();
	CL3Variant valTemp = rsMaxProcessNo.GetFieldByIndex(0);
	CString cstrTemp = valTemp.ToCString();
	if(cstrTemp.IsEmpty())
		return lMaxProcessNo;
	
	if (bQueryBOF)
	{
		CString cstrTemp2;
		TCHAR chTemp[100];

		for (L3SHORT i = 0; i < cstrTemp.GetLength() - 4; i ++)			//去掉熔炼号前4位
			cstrTemp2 += cstrTemp.GetAt(i + 4);

		_tcscpy(chTemp, cstrTemp2);
		lMaxProcessNo = _ttol(chTemp);
	}
	else
	{
		CString cstrTemp2;
		TCHAR chTemp[100];

		for (L3SHORT i = 0; i < cstrTemp.GetLength() - 3; i ++)			//去掉处理号前3位
			cstrTemp2 += cstrTemp.GetAt(i + 4);

		_tcscpy(chTemp, cstrTemp2);
		lMaxProcessNo = _ttol(chTemp);

	}

	return lMaxProcessNo;
}


/// <Method class="CPlan_Mag" name="ModifyPlanExecutionStatus" type="L3BOOL">
/// 
/// 更改出钢计划状态
/// ARG&gt;&gt; rsPlanExecutionData : 包括炉号\工序\处理号\工序状态\状态改变时间。
/// RET &lt;&lt; 返回true。
/// <Param name="rsTappingPlan" type="L3RECORDSET">计划执行数据</Param>
/// </Method>

L3BOOL CPlan_Mag::ModifyPlanExecutionStatus(L3RECORDSET rsTappingPlan)
{

	CL3RecordSetWrap rspPlanExecutionData =rsTappingPlan;
	if( rspPlanExecutionData.IsNull() || rspPlanExecutionData.GetRowCount() < 1)
		return false;
	if(rspPlanExecutionData.GetFieldIndex(_T("HeatID")) < 0 ||
	rspPlanExecutionData.GetFieldIndex(_T("TreatNo")) < 0 ||
	rspPlanExecutionData.GetFieldIndex(_T("UnitStatus")) < 0 ||
	rspPlanExecutionData.GetFieldIndex(_T("StatusChangeTime")) < 0 ||
	rspPlanExecutionData.GetFieldIndex(_T("UnitType")) < 0)
		return false;

	rspPlanExecutionData.MoveFirst();

	CL3Variant valTemp =rspPlanExecutionData.GetFieldByName(_T("HeatID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return false;
	CString csHeatID = valTemp.ToCString();

	valTemp =rspPlanExecutionData.GetFieldByName(_T("TreatNo"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return false;
	CString csTreatNo = valTemp.ToCString();

	valTemp =rspPlanExecutionData.GetFieldByName(_T("UnitType"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return false;
	L3LONG nUnitTypeID = valTemp.ToLong();

	valTemp =rspPlanExecutionData.GetFieldByName(_T("UnitStatus"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return false;
	CString csUnitStatus = valTemp.ToCString();

	L3DATETIME dtStatusChangeTime;
	valTemp = rspPlanExecutionData.GetFieldByName(_T("StatusChangeTime"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		dtStatusChangeTime=COleDateTime::GetCurrentTime();
	else
		dtStatusChangeTime= valTemp.ToDateTime();

	L3SHORT nIsPlanDev = 0; 
	//判断是否炉次分割
	CString csHeatSeq = csHeatID.Mid(4,1);
	L3LONG nHeatSeq =  _ttol(csHeatSeq);

	if (nHeatSeq >= 9)
	{
		//还原熔炼号
		CString csHeatTreat = csHeatID.Mid(4,5);
		CString csYear = csHeatID.Mid(0,4);
		L3LONG nHeatTreat = _ttol(csHeatTreat);
		nHeatTreat = nHeatTreat - 90000;
		csHeatID.Format(_T("%05d"),nHeatTreat);
		csHeatID = csYear + csHeatID;
		nIsPlanDev = 1;
	}

	CString csLastHeatStatus =GetSomeHeatStatus(csHeatID,LastHeat);
	//察看当前炉次上一炉次的状态
	if(csLastHeatStatus==TAPPING_PLAN_STATUS_UNSEND)
		return true;
	
	//判断该计划是否已经执行完成，防止干扰的信号
	CString csTemp = _T("Select Status,PlanID from %s Where HeatID = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,PLAN_TAPPING_CLASS_URI,csHeatID);
	CL3RecordSetWrap rsCurPlanStatus;
	if (!Query(csSQL,rsCurPlanStatus) || rsCurPlanStatus.IsNull() || (rsCurPlanStatus.GetRowCount() < 1))
		return false;

	rsCurPlanStatus.MoveFirst();
	CL3Variant varTemp = rsCurPlanStatus.GetFieldByName(_T("Status"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return false;
	CString csStatus= varTemp.ToCString();

	if (csStatus == TAPPING_PLAN_STATUS_EXCUTED && nIsPlanDev == 0)
		return true;

	valTemp =rsCurPlanStatus.GetFieldByName(_T("PlanID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return false;
	CString csPreHeatID = valTemp.ToCString();


	//得到HeatTappingPlan主键
	CString cstrURI = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	CString csPlanOrderID = GetObjectPropValue(cstrURI,_T("Plan_Ord_ID")).ToCString();
	//得到计划订单主键
	CString csPlanOrdUri = PLAN_ORDER_CLASS_URI + _T("\\") + csPlanOrderID;
	
	//得到HeatTappingPlanActual主键
	CString cstrActualURI = PLAN_TAPPING_ACT_CLASS_URI + _T("\\") + csPreHeatID;

	//得到浇钢计划主键
	CString csCastigPlanUri = PLAN_CASTING_CLASS_URI + _T("\\") + csPreHeatID;

	//得到钢包计划主键
	CString csLadlePlanOrdUri = CLADLE_PLAN_URI + _T("\\") + csPreHeatID;

	CString csUnitID;

	//设置对出钢计划类设置属性及状态时间名称

	CString cstrProcessNo,cstrStatusTimeName;
	switch (nUnitTypeID)
	{
	case UNIT_AREA_BOF:
		//设置对象属性值
		SetObjectPropValue(cstrURI, _T("BOF_Status"),  CL3Variant(csUnitStatus));
		SetObjectPropValue(cstrURI, _T("Side_Status"),  CL3Variant(TAPPING_PLAN_SIDE_STATUS_UNEXCUTING));
		SetObjectPropValue(cstrURI, _T("LF_Status"),  CL3Variant(TAPPING_PLAN_LF_STATUS_UNEXCUTING));
		SetObjectPropValue(cstrURI, _T("RH_Status"), CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING));
		SetObjectPropValue(cstrURI, _T("Caster_Status"), CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING));
		csUnitID = _T("S2") + csHeatID.Mid(1,1);
		cstrProcessNo = _T("HeatID");
		//兑铁
		if(csUnitStatus == TAPPING_PLAN_BOF_STATUS_IRON)
		{
			SetObjectPropValue(cstrURI,_T("Status"), CL3Variant(TAPPING_PLAN_STATUS_EXCUTING));	
			SetObjectPropValue(csCastigPlanUri,_T("Status"), CL3Variant(CASTING_PLAN_STATUS_EXCUTING));
			SetObjectPropValue(csPlanOrdUri,_T("Status"), CL3Variant(PLAN_ORDER_STATUS_EXCUTING));
			cstrStatusTimeName = _T("Act_Time_IronPrepared");
		}
		else
		{ 
			if(csUnitStatus == TAPPING_PLAN_BOF_STATUS_BLOW) //开吹
			{
				SetObjectPropValue(cstrURI,_T("Status"), CL3Variant(TAPPING_PLAN_STATUS_EXCUTING));	
				SetObjectPropValue(csCastigPlanUri,_T("Status"), CL3Variant(CASTING_PLAN_STATUS_EXCUTING));
				SetObjectPropValue(csPlanOrdUri,_T("Status"), CL3Variant(PLAN_ORDER_STATUS_EXCUTING));
				cstrStatusTimeName = _T("Act_Time_BOFStart");
			}
		   else
		   {
				if(csUnitStatus == TAPPING_PLAN_BOF_STATUS_TAPPING) //出钢开始
				 {
					 SetObjectPropValue(cstrURI,_T("Status"), CL3Variant(TAPPING_PLAN_STATUS_EXCUTING));	
					 SetObjectPropValue(csCastigPlanUri,_T("Status"), CL3Variant(CASTING_PLAN_STATUS_EXCUTING));
			         SetObjectPropValue(csPlanOrdUri,_T("Status"), CL3Variant(PLAN_ORDER_STATUS_EXCUTING));
				 }
					else 
						if (csUnitStatus == TAPPING_PLAN_BOF_STATUS_TAPPED) //出刚结束
						{
							SetObjectPropValue(cstrURI,_T("Status"), CL3Variant(TAPPING_PLAN_STATUS_EXCUTING));	
							SetObjectPropValue(csCastigPlanUri,_T("Status"), CL3Variant(CASTING_PLAN_STATUS_EXCUTING));
							SetObjectPropValue(csPlanOrdUri,_T("Status"), CL3Variant(PLAN_ORDER_STATUS_EXCUTING));
							cstrStatusTimeName = _T("Act_Time_BOFTapped");
						}
			}
		}
		break;
	case UNIT_AREA_TAPSIDE:
		//设置对象属性值
		SetObjectPropValue(cstrURI, _T("Side_Status"),  CL3Variant(csUnitStatus));
		SetObjectPropValue(cstrURI, _T("LF_Status"),  CL3Variant(TAPPING_PLAN_LF_STATUS_UNEXCUTING));
		SetObjectPropValue(cstrURI, _T("RH_Status"), CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING));
		SetObjectPropValue(cstrURI, _T("Caster_Status"), CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING));

		cstrProcessNo = _T("HeatID");

		csUnitID = _T("S3") + csHeatID.Mid(1,1);

		if(csUnitStatus == TAPPING_PLAN_SIDE_STATUS_END) //炉后处理结束
		{
			cstrStatusTimeName = _T("Act_Time_TappedSideEnd");

			/*屏蔽开始 by hyh 2012-05-17  将不锈钢LF4 CCM6拿如MES系统管理
		//Modify begin by llj 2011-03-21 增加转炉到不锈钢工艺路径，转炉炉后处理结束时
		//处理订单和出钢，浇钢计划的状态
		
			CString csCasterID=GetObjectPropValue(cstrURI,_T("CasterID")).ToCString();
			if(csCasterID==_T("S66"))
			{
				SetObjectPropValue(cstrURI, _T("Status"), CL3Variant(TAPPING_PLAN_STATUS_EXCUTED));
				SetObjectPropValue(csCastigPlanUri, _T("Status"), CL3Variant(CASTING_PLAN_STATUS_EXCUTED));
				//判断计划订单下的浇钢计划状态是否都为生产结束 
				//计划订单是否全部投放
				CString csISAlloyUse = GetObjectPropValue(csPlanOrdUri,_T("SpareWeight")).ToCString();
				if(csISAlloyUse == _T("0"))
				{
					CString csTemp = _T(" select * from %s where Plan_Ord_ID = '%s' ");
					CString csSQL;
					csSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,csPlanOrderID);
					CL3RecordSetWrap rsPlanCout1;
					if(!Query(csSQL,rsPlanCout1))
						return false;
					csTemp = _T(" select * from %s where Plan_Ord_ID = '%s' and Status = %s ");
					csSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,csPlanOrderID,CASTING_PLAN_STATUS_EXCUTED);
					CL3RecordSetWrap rsPlanCout2;
					if(!Query(csSQL,rsPlanCout2))
						return false;

					if(rsPlanCout1.GetRowCount() == rsPlanCout2.GetRowCount())
					{
						SetObjectPropValue(csPlanOrdUri,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_EXCUTED));
					}
				}

			}
			屏蔽结束*/
		}
		//Modify end

		break;
	case UNIT_AREA_LF:
		//设置对象属性值
		SetObjectPropValue(cstrURI, _T("LF_Status"), CL3Variant(csUnitStatus));
		SetObjectPropValue(cstrURI, _T("RH_Status"), CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING));
		SetObjectPropValue(cstrURI, _T("Caster_Status"), CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING));

		cstrProcessNo = _T("LF_TreatNo");

		csUnitID = _T("S4") + csTreatNo.Mid(0,1);

		if(csUnitStatus == TAPPING_PLAN_LF_STATUS_BEGIN)
			cstrStatusTimeName = _T("Act_Time_LFStart");
		else
		   if(csUnitStatus == TAPPING_PLAN_LF_STATUS_END)
				cstrStatusTimeName = _T("Act_Time_LFEnd");
		else
		   if(csUnitStatus == TAPPING_PLAN_LF_STATUS_ARR)
				cstrStatusTimeName = _T("Act_Time_LFArrival");
				else
		   if(csUnitStatus == TAPPING_PLAN_LF_STATUS_LEAVE)
				cstrStatusTimeName = _T("Act_Time_LFLeave");
		break;
	case UNIT_AREA_RH:
		//设置对象属性值
		SetObjectPropValue(cstrURI, _T("RH_Status"), CL3Variant(csUnitStatus));
		SetObjectPropValue(cstrURI, _T("Caster_Status"), CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING));

		cstrProcessNo = _T("RH_TreatNo");

		csUnitID = _T("S5") + csTreatNo.Mid(0,1);

		if(csUnitStatus == TAPPING_PLAN_RH_STATUS_BEGIN)
			cstrStatusTimeName = _T("Act_Time_RHStart");
		else
		   if(csUnitStatus == TAPPING_PLAN_RH_STATUS_END)
				cstrStatusTimeName = _T("Act_Time_RHEnd");
			else
		   if(csUnitStatus == TAPPING_PLAN_RH_STATUS_ARR)
				cstrStatusTimeName = _T("Act_Time_RHArrival");
			else
		   if(csUnitStatus == TAPPING_PLAN_RH_STATUS_LEAVE)
				cstrStatusTimeName = _T("Act_Time_RHLeave");
		break;

	case UNIT_AREA_CASTER:

		SetObjectPropValue(cstrURI, _T("Caster_Status"), CL3Variant(csUnitStatus));

		cstrProcessNo = _T("Caster_TreatNo");

		csUnitID = _T("S6") + csTreatNo.Mid(0,1);

		if(csUnitStatus == TAPPING_PLAN_CCM_STATUS_ARR)
			cstrStatusTimeName = _T("Act_Time_CasterArrival");
		else
		   if(csUnitStatus == TAPPING_PLAN_CCM_STATUS_BEGIN)
				cstrStatusTimeName = _T("Act_Time_CastingStart");
		   else
			if(csUnitStatus == TAPPING_PLAN_CCM_STATUS_END)
			{
				cstrStatusTimeName = _T("Act_Time_CastingEnd");
				SetObjectPropValue(cstrURI, _T("Status"), CL3Variant(TAPPING_PLAN_STATUS_EXCUTED));
				SetObjectPropValue(csCastigPlanUri, _T("Status"), CL3Variant(CASTING_PLAN_STATUS_EXCUTED));
				//判断计划订单下的浇钢计划状态是否都为生产结束
				//2008-12-24 tangyi 
				//计划订单是否全部投放
				CString csISAlloyUse = GetObjectPropValue(csPlanOrdUri,_T("SpareWeight")).ToCString();
				if(csISAlloyUse == _T("0"))
				{
					CString csTemp = _T(" select * from %s where Plan_Ord_ID = '%s' ");
					CString csSQL;
					csSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,csPlanOrderID);
					CL3RecordSetWrap rsPlanCout1;
					if(!Query(csSQL,rsPlanCout1))
						return false;
					csTemp = _T(" select * from %s where Plan_Ord_ID = '%s' and Status = %s ");
					csSQL.Format(csTemp,PLAN_CASTING_CLASS_URI,csPlanOrderID,CASTING_PLAN_STATUS_EXCUTED);
					CL3RecordSetWrap rsPlanCout2;
					if(!Query(csSQL,rsPlanCout2))
						return false;

					if(rsPlanCout1.GetRowCount() == rsPlanCout2.GetRowCount())
					{
						SetObjectPropValue(csPlanOrdUri,_T("Status"),CL3Variant(PLAN_ORDER_STATUS_EXCUTED));
					}
				}
				//钢包计划执行完成
				//SetObjectPropValue(csLadlePlanOrdUri,_T("Status"),CL3Variant(CLADLE_STATUS_WORK_EXCUTED));
				//CString csLadleID = GetObjectPropValue(csLadlePlanOrdUri,_T("LadleID")).ToCString();
				//CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
				//SetObjectPropValue(csLadleUri,_T("Status"),CL3Variant(CLADLE_STATUS_HOT));				
			}
		break;

	default:
		return false;
	}

	//得到状态改变时间

	//修改处理号
	if (nUnitTypeID == UNIT_AREA_RH && csUnitStatus != TAPPING_PLAN_RH_STATUS_ARR)
		SetObjectPropValue(cstrActualURI, cstrProcessNo, CL3Variant(csTreatNo));
	if (nUnitTypeID == UNIT_AREA_LF && csUnitStatus != TAPPING_PLAN_LF_STATUS_ARR)
		SetObjectPropValue(cstrActualURI, cstrProcessNo, CL3Variant(csTreatNo));
	if(nUnitTypeID == UNIT_AREA_CASTER && csUnitStatus != TAPPING_PLAN_CCM_STATUS_ARR)
		SetObjectPropValue(cstrActualURI, cstrProcessNo, CL3Variant(csTreatNo));

	SetObjectPropValue(cstrActualURI, cstrStatusTimeName, dtStatusChangeTime);
	//SetObjectPropValue(csLadlePlanOrdUri, cstrStatusTimeName, dtStatusChangeTime); 2006-12-26
	//SetObjectPropValue(csLadlePlanOrdUri, _T("UnitID"), CL3Variant(csUnitID));

	//2009-05-27加判断
	if((nUnitTypeID == UNIT_AREA_CASTER && csUnitStatus != TAPPING_PLAN_CCM_STATUS_BEGIN) || nUnitTypeID != UNIT_AREA_CASTER)
		ChangeRsTappingPlanValue();

		return true;

}

// <Method class="CPlan_Mag" name="ModifyLadleAllInfor" type="L3BOOL">
/// 修改钢包相应信息
/// </Method>

L3BOOL CPlan_Mag::ModifyLadleAllInfor(CString csUnitID,CString csHeatID,CString csPreHeatID)
{
	CString csSQL;
	csSQL.Format(_T("select * from CLadle_Use where ComFlag = 0"));
	CL3RecordSetWrap rsLadle;
	if(!Query(csSQL,rsLadle)||rsLadle.IsNull()||rsLadle.GetRowCount() < 1)
		return false;
	rsLadle.MoveFirst();
	while(!rsLadle.IsEOF())
	{
		CString csBOFID = rsLadle.GetFieldByName(_T("BOFID")).ToCString();
		if(csBOFID!=csUnitID)
		{
			rsLadle.MoveNext();
			continue;
		}
		//修改钢包信息
		CString csLadleID = rsLadle.GetFieldByName(_T("LadleID")).ToCString();
		/*CString csLadlePlanUri = CLADLE_PLAN_URI + _T("\\") + csPreHeatID;*/
		CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		/*SetObjectPropValue(csLadlePlanUri,_T("LadleID"),CL3Variant(csLadleID));*/
		/*SetObjectPropValue(csLadlePlanUri, _T("Status"), CL3Variant(CLADLE_PLAN_STATUS_EXCUTING));*/
		SetObjectPropValue(csLadleUri, _T("Status"), CL3Variant(CLADLE_STATUS_USE));
		L3LONG nAge = GetObjectPropValue(csLadleUri,_T("Ladle_Age")).ToLong();
		nAge++;
		SetObjectPropValue(csLadleUri,_T("Ladle_Age"),CL3Variant(L3LONG(nAge)));
		//修改转炉实绩数据
		CString csBOFProcessUri = BOF_PROCESS_DATA_CLASS_URI + _T("\\") + csHeatID;
		SetObjectPropValue(csBOFProcessUri,_T("LadleNo"),CL3Variant(csLadleID));
		//修改钢包上件实绩
		CString csPlanUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
		CString csSteelGradeIndex = GetObjectPropValue(csPlanUri,_T("SteelGradeIndex")).ToCString();
		CString csSteelGradeIndexUri = QA_STG_RELATION_CLASS_URI + _T("\\") + csSteelGradeIndex;
		CString csGuid = rsLadle.GetFieldByName(_T("GUID")).ToCString(); 
		CString csLadleUseUri = CLADLE_USE_URI + _T("\\") + csGuid;
		SetObjectPropValue(csLadleUseUri,_T("HeatID"),CL3Variant(csHeatID));
		SetObjectPropValue(csLadleUseUri,_T("ComFlag"),CL3Variant(L3LONG(1)));
		SetObjectPropValue(csLadleUseUri,_T("Steel_Grade"),GetObjectPropValue(csSteelGradeIndexUri,_T("SteelGrade")));	
		SetObjectPropValue(csLadleUseUri,_T("Tap_Time"),COleDateTime::GetCurrentTime());
		
		
		rsLadle.MoveNext();
	}

	return true;

}
/// <Method class="CPlan_Mag" name="GetUnitProcessPlan" type="L3RECORDSET">
/// 
/// 获取计划
/// ARG&gt;&gt; nUnitType : 工序。
/// ARG&gt;&gt; strUnitID : 工位。
/// RET &lt;&lt; 返回记录集。
/// <Param name="nUnitType" type="L3SHORT">工序</Param>
/// <Param name="strUnitID" type="L3SHORT">工位</Param>
/// </Method>

L3RECORDSET CPlan_Mag::GetUnitProcessPlan(L3SHORT nUnitType, L3STRING strUnitID)
{
	CL3RecordSetWrap rsCurShiftInfo;                                 //定义当班工序信息数据集
	CString csUnitID = strUnitID;												//工序位

	CString cstrUnitName;
	CL3RecordSetWrap rsCurShiftTappingPlan;

	//组成查询语句
	CString cstrURI = _T(" Select * from %s a, %s b where a.HeatID=b.HeatID and a.");

	switch(nUnitType)
	{
		case UNIT_AREA_BOF:
			cstrUnitName = _T("BOFID");
			break;
		case UNIT_AREA_LF:
			cstrUnitName = _T("LFID");
			break;
		case UNIT_AREA_RH:
			cstrUnitName = _T("RHID");
			break;
		case UNIT_AREA_CASTER:
			cstrUnitName = _T("CasterID");
			break;
		default:
			return NULL;
	}

	cstrURI += cstrUnitName;
	cstrURI += _T("='%s' ");
	cstrURI += _T("  and a.Status > 10                                            ");
	cstrURI += _T("  and  (a.CreateDate >=                                        ");
	cstrURI += _T(" (select TRUNC(SYSDATE) from dual)                             ");
	cstrURI += _T(" or ( a.CreateDate  < (select TRUNC(SYSDATE) from dual)        ");
	cstrURI += _T(" and a.Status < 13))                                           ");
	cstrURI += _T("	order by a.Aim_Time_CastingStart                              ");

	//参数定义
	CString csSQL;
	csSQL.Format(cstrURI,PLAN_TAPPING_CLASS_URI,PLAN_TAPPING_ACT_CLASS_URI,csUnitID);

	if (!Query(csSQL,rsCurShiftTappingPlan) || rsCurShiftTappingPlan.IsNull())
	{
	    return NULL;
	}
	else
	{
		return rsCurShiftTappingPlan.Detach();
	}
}


void CPlan_Mag::ChangeRsTappingPlanValue(void)
{
	//改变属性值
	CL3Variant varTappingPlanEvent = GetPropValue(_T("TappingPlanEvent"));
	L3SHORT nTappingPlanEvent = varTappingPlanEvent.ToShort();
	nTappingPlanEvent = (nTappingPlanEvent+1) % 9999;
	SetPropValue(_T("TappingPlanEvent"),nTappingPlanEvent);
}

/// <Method class="CPlan_Mag" name="ModifyUnitSteelGradeIndex" type="L3LONG">
/// 
/// 更改工序预定炼钢记号预定炉号
/// ARG&gt;&gt; strHeatID : 炉号1。
/// RET &lt;&lt; 成功0错误代码。
/// <Param name="strHeatID1" type="L3STRING">炉号1</Param>
/// </Method>

L3LONG CPlan_Mag::ModifyUnitSteelGradeIndex(L3STRING strHeatID)
{
	if (strHeatID == NULL)
		return -91;

	CStringArray UnitMagURI; UnitMagURI.SetSize(27);

	//转炉
	UnitMagURI[0] = BOF1_UNIT_URI;
	UnitMagURI[1] = BOF2_UNIT_URI;
	UnitMagURI[2] = BOF3_UNIT_URI;
	UnitMagURI[3] = BOF4_UNIT_URI;

	//炉后
	UnitMagURI[4] = TAPSIDE1_UNIT_URI;
	UnitMagURI[5] = TAPSIDE2_UNIT_URI;
	UnitMagURI[6] = TAPSIDE3_UNIT_URI;
	UnitMagURI[7] = TAPSIDE4_UNIT_URI;

	//LF
	UnitMagURI[8] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S41A");
	UnitMagURI[9] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S41B");
	UnitMagURI[10] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S42A");
	UnitMagURI[11] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S42B");
	UnitMagURI[12] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S43A");
	UnitMagURI[13] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S43B");
	//Modify begin 2011-02-14 llj 增加5#LF工序修改
	UnitMagURI[14] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S45A");
	UnitMagURI[15] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S45B");
	//Modify end

	//Modify by hyh 2012-05-09 增加4#LF工序修改
	UnitMagURI[16] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S44A");
	UnitMagURI[17] = _T("XGMESLogic\\LFMag\\CLF_Prod_Area\\S44B");
	//Modify end

	/*屏蔽开始1 llj 2011-02-14
	//RH
	UnitMagURI[14] = _T("XGMESLogic\\RHMag\\CRH_Prod_Area\\S51A");
	UnitMagURI[15] = _T("XGMESLogic\\RHMag\\CRH_Prod_Area\\S51B");
	屏蔽结束1*/

	/*屏蔽开始 by hyh 2012-05-09
	UnitMagURI[16] = _T("XGMESLogic\\RHMag\\CRH_Prod_Area\\S51A");
	UnitMagURI[17] = _T("XGMESLogic\\RHMag\\CRH_Prod_Area\\S51B");
	屏蔽结束*/

	//RH
	//modify by hyh 2012-05-09
	UnitMagURI[18] = _T("XGMESLogic\\RHMag\\CRH_Prod_Area\\S51A");
	UnitMagURI[19] = _T("XGMESLogic\\RHMag\\CRH_Prod_Area\\S51B");
	//end

	/*屏蔽开始2 llj 2011-02-14
	//2009-04-15 tangyi增加铸机改钢信息
	UnitMagURI[16] = CCM1_UNIT_URI;
	UnitMagURI[17] = CCM2_UNIT_URI;
	UnitMagURI[18] = CCM3_UNIT_URI;
	UnitMagURI[19] = CCM4_UNIT_URI;
	UnitMagURI[20] = CCM5_UNIT_URI;
	屏蔽结束2*/
	
	/*屏蔽开始 by hyh 2012-05-09
	//Modify begin 2011-02-14 by llj 增加7#铸机
	UnitMagURI[18] = CCM1_UNIT_URI;
	UnitMagURI[19] = CCM2_UNIT_URI;
	UnitMagURI[20] = CCM3_UNIT_URI;
	UnitMagURI[21] = CCM4_UNIT_URI;
	UnitMagURI[22] = CCM5_UNIT_URI;
	UnitMagURI[23] = CCM7_UNIT_URI;
	//Modify end
	屏蔽结束*/

	//CCM
	UnitMagURI[20] = CCM1_UNIT_URI;
	UnitMagURI[21] = CCM2_UNIT_URI;
	UnitMagURI[22] = CCM3_UNIT_URI;
	UnitMagURI[23] = CCM4_UNIT_URI;
	UnitMagURI[24] = CCM5_UNIT_URI;
	UnitMagURI[25] = CCM7_UNIT_URI;
	//add by hyh 05-09
	UnitMagURI[26] = CCM6_UNIT_URI;

	CString csHeatID = strHeatID;

	L3LONG nUnit = 0;
	L3LONG nUnitType = 0;

	CL3Variant valTemp;

	//得到炉号1炼钢记号
	CString cstrSQL = _T("Select Pre_SteelGradeIndex,PlanID,SteelGradeIndex,LFID,RHID,CasterID from %s where HeatID = '%s'");
	CString csSQL;
	csSQL.Format(cstrSQL,PLAN_TAPPING_CLASS_URI,csHeatID);
	CL3RecordSetWrap rsSteelGradeIndex;
	if (!Query(csSQL,rsSteelGradeIndex) || rsSteelGradeIndex.IsNull() || (rsSteelGradeIndex.GetRowCount() < 1))
		return -92;

	rsSteelGradeIndex.MoveFirst();
	valTemp = rsSteelGradeIndex.GetFieldByName(_T("SteelGradeIndex"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -93;
	CString csActSteelGradeIndex = valTemp.ToCString();

	valTemp = rsSteelGradeIndex.GetFieldByName(_T("Pre_SteelGradeIndex"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -93;
	CString csPreSteelGradeIndex = valTemp.ToCString();

	valTemp = rsSteelGradeIndex.GetFieldByName(_T("PlanID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -93;
	CString csPresetHeatID = valTemp.ToCString();

	valTemp = rsSteelGradeIndex.GetFieldByName(_T("LFID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -93;
	CString csLFID = valTemp.ToCString();

	valTemp = rsSteelGradeIndex.GetFieldByName(_T("RHID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -93;
	CString csRHID = valTemp.ToCString();

	valTemp = rsSteelGradeIndex.GetFieldByName(_T("CasterID"));
	if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -93;
	CString csCasterID = valTemp.ToCString();

	

	//设置CSteel_Data类属性
	//2009-03-18 tangyi 转炉出钢以前交换炉座应该可以修改工序钢种，故以下的判断返回去掉
	CString cstrURI = MATERIAL_STEEL_URI + _T("\\") + csHeatID;
	SetObjectPropValue(cstrURI, _T("PreHeatID"), CL3Variant(csPresetHeatID));
	SetObjectPropValue(cstrURI, _T("SteelGradeIndex"), CL3Variant(csActSteelGradeIndex));
	SetObjectPropValue(cstrURI, _T("Pre_SteelGradeIndex"), CL3Variant(csPreSteelGradeIndex));

	/*屏蔽 by hyh 2012-05-09
	//Modify begin 2011-02-14 by llj 增加5#LF、7#LF工序屏蔽下面并修改语句
	//for (long i = 0; i < 16; i ++)
	for (long i = 0; i < 18; i ++)
	//Modify end
	屏蔽*/
	for (long i = 0; i < 27; i ++)   //增加4#LF工序屏蔽下面并修改语句  是否应该包含铸机部分？？？？？ hyh 2012-05-09
	{

		CL3Variant valTemp = GetObjectPropValue(UnitMagURI[i], _T("Status"));
		if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull() || valTemp.ToShort()==0)
			continue;

		valTemp = GetObjectPropValue(UnitMagURI[i], _T("HeatID"));
		if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
			continue;


		if (valTemp.ToCString() == csHeatID)
		{
			SetObjectPropValue(UnitMagURI[i], _T("SteelGradeIndex"),CL3Variant(csActSteelGradeIndex));

			//设置基本数据类属性
			if (i < 4)					//BOF
			{
				cstrURI = BOF_BASE_DATA_CLASS_URI + _T("\\")  + csHeatID;
				if (!SetObjectPropValue(cstrURI, _T("SteelGradeIndex"), CL3Variant(csActSteelGradeIndex)))
					return -95;
				if (!SetObjectPropValue(cstrURI, _T("SteelGrade"), GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + csActSteelGradeIndex,_T("SteelGrade"))))
					return -95;//2009-01-11 tangyi
				if(!SetObjectPropValue(cstrURI, _T("PreHeatID"), CL3Variant(csPresetHeatID)))
					return -95;
			}
			else
			{
				if(i < 8)              //炉后
				{
					cstrURI = TAP_BASE_DATA_CLASS_URI + _T("\\")  + csHeatID;
					if (!SetObjectPropValue(cstrURI, _T("SteelGradeIndex"), CL3Variant(csActSteelGradeIndex)))
						return -96;
					if (!SetObjectPropValue(cstrURI, _T("SteelGrade"), GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + csActSteelGradeIndex,_T("SteelGrade"))))
						return -96;//2009-01-11 tangyi
					if(!SetObjectPropValue(cstrURI, _T("PreHeatID"), CL3Variant(csPresetHeatID)))
						return -96;

				}
				else
				{
					                  //LF
					//if(i < 14 && csLFID.GetLength() == 3) //LF 因调整上面定义的数组而调整
					//if(i < 16 && csLFID.GetLength() == 3) 
					if(i < 18 && csLFID.GetLength() == 3) //LF modify by hyh 2012-05-09
					{
						cstrSQL = _T("Select TreatNo from %s where HeatID='%s' and substr(TreatNo,1,1) ='%s' order by TreatNo desc");
						CString csSQL;
						csSQL.Format(cstrSQL,LF_BASE_DATA_CLASS_URI,csHeatID,csLFID.Mid(2,1));
						CL3RecordSetWrap rsID_Object;
						if (!Query(csSQL,rsID_Object) || rsID_Object.IsNull() || (rsID_Object.GetRowCount() < 1))
							return -97;
						rsID_Object.MoveFirst();
						valTemp = rsID_Object.GetFieldByName(_T("TreatNo"));
						if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
							return -97;

						cstrURI = LF_BASE_DATA_CLASS_URI + _T("\\") + valTemp.ToCString();

						//设置对象属性
						if (!SetObjectPropValue(cstrURI, _T("SteelGradeIndex"), CL3Variant(csActSteelGradeIndex)))
							return -97;
						if (!SetObjectPropValue(cstrURI, _T("SteelGrade"), GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + csActSteelGradeIndex,_T("SteelGrade"))))
							return -97;//2009-01-11 tangyi
						if(!SetObjectPropValue(cstrURI, _T("PreHeatID"), CL3Variant(csPresetHeatID)))
							return -97;

					}
					else
					{
						//if( i < 16 && csRHID.GetLength() == 3) //RH 因调整上面定义的数组而调整
						//if( i < 18 && csRHID.GetLength() == 3) //RH 因调整上面定义的数组而调整
						if( i < 20 && csRHID.GetLength() == 3)
						{
							//RH
							cstrSQL = _T("Select TreatNo from %s where HeatID='%s' and substr(TreatNo,1,1) ='%s' order by TreatNo desc");
							CString csSQL;
							csSQL.Format(cstrSQL,RH_BASE_DATA_CLASS_URI,csHeatID,csRHID.Mid(2,1));
							CL3RecordSetWrap rsID_Object;
							if (!Query(csSQL,rsID_Object) || rsID_Object.IsNull() || (rsID_Object.GetRowCount() < 1))
								return -98;
							rsID_Object.MoveFirst();
							valTemp = rsID_Object.GetFieldByName(_T("TreatNo"));
							if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
								return -98;

							cstrURI = RH_BASE_DATA_CLASS_URI + _T("\\") + valTemp.ToCString();

							//设置对象属性
							if (!SetObjectPropValue(cstrURI, _T("SteelGradeIndex"), CL3Variant(csActSteelGradeIndex)))
								return -98;
							if (!SetObjectPropValue(cstrURI, _T("SteelGrade"), GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + csActSteelGradeIndex,_T("SteelGrade"))))
								return -98;//2009-01-11 tangyi
							if(!SetObjectPropValue(cstrURI, _T("PreHeatID"), CL3Variant(csPresetHeatID)))
								return -98;
						}
						else//2009-04-15 tangyi增加铸机改钢信息
						{
							cstrSQL = _T("Select TreatNo from %s where HeatID='%s' and substr(TreatNo,1,1) ='%s' order by TreatNo desc");
							CString csSQL;
							csSQL.Format(cstrSQL,CCM_BASE_DATA_CLASS_URI,csHeatID,csCasterID.Mid(2,1));
							CL3RecordSetWrap rsID_Object;
							if (!Query(csSQL,rsID_Object) || rsID_Object.IsNull() || (rsID_Object.GetRowCount() < 1))
								return -99;
							rsID_Object.MoveFirst();
							valTemp = rsID_Object.GetFieldByName(_T("TreatNo"));
							if (!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
								return -99;

							cstrURI = CCM_BASE_DATA_CLASS_URI + _T("\\") + valTemp.ToCString();

							//设置对象属性
							if (!SetObjectPropValue(cstrURI, _T("SteelGradeIndex"), CL3Variant(csActSteelGradeIndex)))
								return -99;
							if (!SetObjectPropValue(cstrURI, _T("SteelGrade"), GetObjectPropValue(QA_STG_RELATION_CLASS_URI + _T("\\") + csActSteelGradeIndex,_T("SteelGrade"))))
								return -99;//2009-01-11 tangyi
							if(!SetObjectPropValue(cstrURI, _T("PreHeatID"), CL3Variant(csPresetHeatID)))
								return -99;
						}


					}
				}
			}		

				//调用质量算法重新计算等级
				//L3STRING strHeatID = csHeatID.AllocSysString();
				//valTemp = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatChemicalData_Mag\\QA_HeatChemicalData_Mag"), _T("GetReHeatCount"), strHeatID,nUnitType,nUnit);
				//if (valTemp.IsError() || valTemp.IsNull() || (valTemp.ToShort() < 0))
				//{
				//	L3SysFreeString(strHeatID);
				//	continue;
				//}
				//L3LONG nReProcessCount = valTemp.ToShort();
				//
				//InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssumeAlg_Mag\\QA_HeatGradeAssumeAlg_Mag"), _T("EstimateHeatGrade"), nUnitType, nUnit, strHeatID, nReProcessCount);

				//L3SysFreeString(strHeatID);
			}//if
	}//for
	return 0;
}







/// <Method class="CPlan_Mag" name="StoreLadlePlanBeforeExBOF" type="L3RECORDSET">
/// 
/// 记录钢包计划
/// ARG&gt;&gt; strHeatID : 炉号1。
/// RET &lt;&lt; 成功0错误代码。
/// <Param name="strHeatID1" type="L3STRING">炉号1</Param>
/// </Method>
L3RECORDSET CPlan_Mag::StoreLadlePlanBeforeExBOF (CString strPresetHeatID)
{
	CL3RecordSetWrap rsLadlePlanInfo;
	CString cstrSQL;
	cstrSQL.Format(_T(" select * from %s  where PlanID = '%s' "),CLADLE_PLAN_URI,strPresetHeatID);
	if (!Query(cstrSQL,rsLadlePlanInfo) || rsLadlePlanInfo.IsNull() || rsLadlePlanInfo.GetRowCount() < 1)
		return NULL;
	return rsLadlePlanInfo.Detach();

}

/// <Method class="CPlan_Mag" name="StoreLadlePlanBeforeExBOF" type="L3RECORDSET">
/// 
/// 炉座交换后，根据计划状态确定钢包计划是否重新下达
/// ARG&gt;&gt; strHeatID : 炉号1。
/// RET &lt;&lt; 成功0错误代码。
/// <Param name="strHeatID1" type="L3STRING">炉号1</Param>
/// </Method>
L3LONG CPlan_Mag::ReDownLoadLadlePlan(CString csPreHeatID,L3RECORDSET rsLadlePlan)
{
	CString csUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	CL3RecordSetWrap rsLadlePlanData=rsLadlePlan;
	rsLadlePlanData.MoveFirst();
	rsLadlePlanData.SetFieldByName(_T("PlanID"), CL3Variant(csPreHeatID));
	rsLadlePlanData.SetFieldByName(_T("SteelGradeIndex"),GetObjectPropValue(csUri,_T("SteelGradeIndex")));
	rsLadlePlanData.SetFieldByName(_T("CasterID"),GetObjectPropValue(csUri,_T("CasterID")));

	if(CreateNewObjects(CLADLE_PLAN_URI,L3RECORDSET(rsLadlePlanData)) < rsLadlePlanData.GetRowCount())
		return -1;
	return 0;
}

//根据炉号察看某一炉次的状态，0当前炉，1：上一炉；2：下一炉
CString CPlan_Mag::GetSomeHeatStatus(CString csHeatID,L3SHORT nLastFlag)
{
	CString csFinalHeatID;
	if(nLastFlag == LastHeat)
	{
		//察看当前炉次上一炉次的状态
		CString csBofProcessSeq=csHeatID.Mid(4,5);
		CString csYearID=csHeatID.Mid(0,4);
		L3LONG nLastBOFTreateNo = _ttol(csBofProcessSeq) - 1;
		csFinalHeatID.Format(_T("%05d"),nLastBOFTreateNo);
		csFinalHeatID=csYearID + csFinalHeatID;
	}
	else
	{
		if(nLastFlag == NextHeat)
		{
			//察看当前炉次下一炉次的状态
			CString csBofProcessSeq=csHeatID.Mid(4,5);
			CString csYearID=csHeatID.Mid(0,4);
			L3LONG nNextBOFTreateNo = _ttol(csBofProcessSeq) + 1;
			csFinalHeatID.Format(_T("%05d"),nNextBOFTreateNo);
			csFinalHeatID=csYearID + csFinalHeatID;
		}
		else
			csFinalHeatID = csHeatID;
	}


	CString csTemp = _T("Select Status from %s Where HeatID = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,PLAN_TAPPING_CLASS_URI,csFinalHeatID);
	CL3RecordSetWrap rsStatus; 
	if (!Query(csSQL,rsStatus) || rsStatus.IsNull())
		return _T("");

	if(rsStatus.GetRowCount() < 1 && nLastFlag == LastHeat)//第一炉
		return TAPPING_PLAN_STATUS_SEND;
	else
		if(rsStatus.GetRowCount() < 1 && nLastFlag == NextHeat)//最后一炉
			return TAPPING_PLAN_STATUS_UNSEND;
		else
			if(rsStatus.GetRowCount() < 1 && nLastFlag == CurrentHeat)//当前炉
			return _T("");

	rsStatus.MoveFirst();
	CL3Variant varTemp = rsStatus.GetFieldByName(_T("Status"));
	if (!varTemp.IsValid() || varTemp.IsError() || varTemp.IsNull())
		return _T("");
	CString  csStatus = varTemp.ToCString();
	return csStatus;
}




/// <Method class="CPlan_Mag" name="TappingPlanSndCancel" type="L3BOOL">
/// 
/// 记录转炉非作业时间
/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CPlan_Mag::LogBOFNunProcessTime(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
    if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	if(rs.GetFieldIndex(_T("Aim_Time_BOFRepared")) < 0 ||
		rs.GetFieldIndex(_T("Aim_Time_BlowN2")) < 0 ||
		rs.GetFieldIndex(_T("HeatID")) < 0 )
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(CreateNewObjects(_T("XGMESLogic\\PlanMag\\CPlan_BOFNon_Proc_Time"),rsData) < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	if(bUseTrans)
		Commit(nTrans);

	return true;// TODO : 请在此添加逻辑代码
}


/// <Method class="CPlan_Mag" name="TappingPlanSndCancel" type="L3BOOL">
/// 
/// 修改出钢计划计划时间信息
/// ARG&gt;&gt; rsTappingPlan : 计划数据。必须包含PlanID字段。
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CPlan_Mag::ModifyTappingPlanTimeInfor(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
    if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	if(rs.GetFieldIndex(_T("PlanID")) < 0 || rs.GetFieldIndex(_T("Aim_Time_CastingStart")) < 0 )
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	// 锁定逻辑对象，只允许单机操作 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csPlanID  = rs.GetFieldByName(_T("PlanID")).ToCString();
		CString csPlanUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPlanID;
		if(!SetObjectPropValue(csPlanUri,_T("Aim_Time_CastingStart"),rs.GetFieldByName(_T("Aim_Time_CastingStart"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if (CalcUnitStdProcessTime(csPlanID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if (CalcUnitOneToOneTime(csPlanID) < 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	return true;// TODO : 请在此添加逻辑代码
}



/// <Method class="CDispatch_Mag" name="GetCurSteelCache" type="DATASET">
/// 
/// 获取钢水当前所在缓存URi
/// ARG csHeatID：炉号
/// RET &gt;&gt; 找到的URi
/// </Method>
CString CPlan_Mag::GetCurSteelCache(CString csHeatID)
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
	return csCache;

}

/// <Method class="CDispatch_Mag" name="MoveSteelFromCache" type="L3LONG">
/// 
/// 将钢水从缓存中移去
/// ARG&gt;&gt; 
///  &gt;&gt; csHeatID：炉号
/// RET &lt;&lt;返回0
/// </Method>

L3LONG CPlan_Mag::MoveSteelFromCache(CString csCacheID,CString csHeatID)
{
	CString csIsCaster = csCacheID.Mid(3,1);
	CString csCacheUri;
	if(csIsCaster != _T("A"))
		csCacheUri = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\") + csCacheID;
	else
		csCacheUri = _T("XGMESLogic\\CCMMag\\CCCM_Prod_Area\\") + csCacheID;
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

	CL3Variant valResult = InvokeObjectMethod(csCacheUri,_T("RemoveMaterials"),(L3RECORDSET)rsMaterial);
	if(!valResult.IsValid()||!valResult.ToBOOL())
		return -91;

	return 0;

}


/// <Method class="CDispatch_Mag" name="AddSteelToCache" type="L3LONG">
/// 
/// 将钢水添加到缓存
/// ARG&gt;&gt; 
///  &gt;&gt; csHeatID：炉号
/// RET &lt;&lt;返回0
/// </Method>

L3LONG CPlan_Mag::AddSteelToCache(CString csCacheID,CString csHeatID)
{
	CString csIsCaster = csCacheID.Mid(3,1);
	CString csCacheUri;
	if(csIsCaster != _T("A"))
		csCacheUri = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\") + csCacheID;
	else
		csCacheUri = _T("XGMESLogic\\CCMMag\\CCCM_Prod_Area\\") + csCacheID;
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

	CL3Variant valResult = InvokeObjectMethod(csCacheUri,_T("AddMaterials"),(L3RECORDSET)rsMaterial);
	if(!valResult.IsValid()||!valResult.ToBOOL())
		return -91;

	return 0;

}


/// <Method class="CDispatch_Mag" name="MoveSteelWhenSideExchangePlan" type="L3LONG">
/// 
/// 当炉后工序交换计划时钢水移动
/// ARG&gt;&gt; 
///  &gt;&gt; csHeatID：炉号
/// RET &lt;&lt;返回0
/// </Method>

L3LONG CPlan_Mag::MoveSteelWhenSideExchangePlan(CString cstrURI1,CString cstrURI2)
{
	CString csCasterID1 = GetObjectPropValue(cstrURI1, _T("CasterID")).ToCString();
	CString csRHID1 = GetObjectPropValue(cstrURI1, _T("RHID")).ToCString();
	CString csLFID1 = GetObjectPropValue(cstrURI1, _T("LFID")).ToCString();
	CString csHeatID1= GetObjectPropValue(cstrURI1, _T("HeatID")).ToCString();
	CString csCache1 = GetCurSteelCache(csHeatID1);
	CString csUnitType1 = csCache1.Mid(1,1);
	CString csRefineTypeFlag1 = GetObjectPropValue(cstrURI1, _T("Refine_Type")).ToCString();

	CString csCasterID2 = GetObjectPropValue(cstrURI2, _T("CasterID")).ToCString();
	CString csRHID2 = GetObjectPropValue(cstrURI2, _T("RHID")).ToCString();
	CString csLFID2 = GetObjectPropValue(cstrURI2, _T("LFID")).ToCString();
	CString csHeatID2= GetObjectPropValue(cstrURI2, _T("HeatID")).ToCString();
	CString csCache2 = GetCurSteelCache(csHeatID2);
	CString csUnitType2 = csCache2.Mid(1,1);
	CString csRefineTypeFlag2 = GetObjectPropValue(cstrURI2, _T("Refine_Type")).ToCString();


	CString csCache1Next;
	if(csRefineTypeFlag2==_T("0"))
		csCache1Next=  csCasterID2 + _T("P01");
	else
		if(csRefineTypeFlag2==_T("L") || csRefineTypeFlag2==_T("LR"))
			csCache1Next=  csLFID2 + _T("P01");
		else
			csCache1Next=  csRHID2 + _T("P01");

	CString csCache2Next;
	if(csRefineTypeFlag1==_T("0"))
		csCache2Next=  csCasterID1 + _T("P01");
	else
		if(csRefineTypeFlag1==_T("L") || csRefineTypeFlag2==_T("LR"))
			csCache2Next=  csLFID1 + _T("P01");
		else
			csCache2Next=  csRHID1 + _T("P01");


	if(csCache1!=_T(""))
	{
		if(MoveSteelFromCache(csCache1,csHeatID1) < 0)
			return -31;
		if(AddSteelToCache(csCache1Next,csHeatID1) < 0)
			return -32;

	}

	if(csCache2!=_T(""))
	{
		if(MoveSteelFromCache(csCache2,csHeatID2) < 0)
			return -31;
		if(AddSteelToCache(csCache2Next,csHeatID2) < 0)
			return -32;
	}

	return 0;
}


/// <Method class="CDispatch_Mag" name="MoveSteelWhenCasterExPlan" type="L3LONG">
/// 
/// 当大包到达时交换计划时钢水移动
/// ARG&gt;&gt; 
///  &gt;&gt; csHeatID：炉号
/// RET &lt;&lt;返回0
/// </Method>

L3LONG CPlan_Mag::MoveSteelWhenCasterExPlan(CString cstrURI1,CString cstrURI2)
{
	CString csCasterID1 = GetObjectPropValue(cstrURI1, _T("CasterID")).ToCString();
	CString csCasterID2 = GetObjectPropValue(cstrURI2, _T("CasterID")).ToCString();

	if(csCasterID1 != csCasterID2)
	{
		CString csHeatID1= GetObjectPropValue(cstrURI1, _T("HeatID")).ToCString();
		CString csHeatID2= GetObjectPropValue(cstrURI2, _T("HeatID")).ToCString();
		CString csCache1 = GetCurSteelCache(csHeatID1);
		CString csCache2 = GetCurSteelCache(csHeatID2);
		CString csUnitType1 = csCache1.Mid(1,1);
		CString csUnitType2 = csCache2.Mid(1,1);

		if(csUnitType1 == UNIT_TYPE_CASTER)
		{
			if(MoveSteelFromCache(csCache1,csHeatID1) < 0)
				return -31;
			CString csCacheUri = csCasterID2 + _T("A01");
			if(AddSteelToCache(csCacheUri,csHeatID1) < 0)
				return -32;
		}
		if(csUnitType2 == UNIT_TYPE_CASTER)
		{
			if(MoveSteelFromCache(csCache2,csHeatID2) < 0)
				return -31;
			CString csCacheUri = csCasterID1 + _T("A01");
			if(AddSteelToCache(csCacheUri,csHeatID2) < 0)
				return -32;
		}
	}
	return 0;
}



/// <Method class="CDispatch_Mag" name="MoveSteelWhenRefineExchangePlan" type="L3LONG">
/// 
/// 当RH工序交换计划时钢水移动
/// ARG&gt;&gt; 
///  &gt;&gt; csHeatID：炉号
/// RET &lt;&lt;返回0
/// </Method>

L3LONG CPlan_Mag::MoveSteelWhenRHExPlan(CString cstrURI1,CString cstrURI2)
{
	CString csCasterID1 = GetObjectPropValue(cstrURI1, _T("CasterID")).ToCString();
	CString csLFID1 = GetObjectPropValue(cstrURI1, _T("LFID")).ToCString();
	CString csHeatID1= GetObjectPropValue(cstrURI1, _T("HeatID")).ToCString();
	CString csCache1 = GetCurSteelCache(csHeatID1);
	CString csUnitType1 = csCache1.Mid(1,1);
	CString csRefineTypeFlag1 = GetObjectPropValue(cstrURI1, _T("Refine_Type")).ToCString();

	CString csCasterID2 = GetObjectPropValue(cstrURI2, _T("CasterID")).ToCString();
	CString csLFID2 = GetObjectPropValue(cstrURI2, _T("LFID")).ToCString();
	CString csHeatID2= GetObjectPropValue(cstrURI2, _T("HeatID")).ToCString();
	CString csCache2 = GetCurSteelCache(csHeatID2);
	CString csUnitType2 = csCache2.Mid(1,1);
	CString csRefineTypeFlag2 = GetObjectPropValue(cstrURI2, _T("Refine_Type")).ToCString();


	CString csCache1Next;
	if(csRefineTypeFlag2==_T("LR") || csRefineTypeFlag2==_T("R"))
		csCache1Next=  csCasterID2 + _T("P01");
	else
		if(csRefineTypeFlag2==_T("RL"))
			csCache1Next=  csLFID2 + _T("P01");


	CString csCache2Next;
	if(csRefineTypeFlag1==_T("LR") || csRefineTypeFlag1==_T("R") )
		csCache2Next=  csCasterID1 + _T("P01");
	else
		if(csRefineTypeFlag1==_T("RL"))
			csCache2Next=  csLFID1 + _T("P01");

	if(csCache1!=_T(""))
	{
		if(MoveSteelFromCache(csCache1,csHeatID1) < 0)
			return -31;
		if(AddSteelToCache(csCache1Next,csHeatID1) < 0)
			return -32;

	}

	if(csCache2!=_T(""))
	{
		if(MoveSteelFromCache(csCache2,csHeatID2) < 0)
			return -31;
		if(AddSteelToCache(csCache2Next,csHeatID2) < 0)
			return -32;
	}



	return 0;
}


/// <Method class="CDispatch_Mag" name="MoveSteelWhenRefineExchangePlan" type="L3LONG">
/// 
/// 当LF工序交换计划时钢水移动
/// ARG&gt;&gt; 
///  &gt;&gt; csHeatID：炉号
/// RET &lt;&lt;返回0
/// </Method>

L3LONG CPlan_Mag::MoveSteelWhenLFExPlan(CString cstrURI1,CString cstrURI2)
{
	CString csCasterID1 = GetObjectPropValue(cstrURI1, _T("CasterID")).ToCString();
	CString csRHID1 = GetObjectPropValue(cstrURI1, _T("RHID")).ToCString();
	CString csHeatID1= GetObjectPropValue(cstrURI1, _T("HeatID")).ToCString();
	CString csCache1 = GetCurSteelCache(csHeatID1);
	CString csUnitType1 = csCache1.Mid(1,1);
	CString csRefineTypeFlag1 = GetObjectPropValue(cstrURI1, _T("Refine_Type")).ToCString();

	CString csCasterID2 = GetObjectPropValue(cstrURI2, _T("CasterID")).ToCString();
	CString csRHID2 = GetObjectPropValue(cstrURI2, _T("RHID")).ToCString();
	CString csHeatID2= GetObjectPropValue(cstrURI2, _T("HeatID")).ToCString();
	CString csCache2 = GetCurSteelCache(csHeatID2);
	CString csUnitType2 = csCache2.Mid(1,1);
	CString csRefineTypeFlag2 = GetObjectPropValue(cstrURI2, _T("Refine_Type")).ToCString();


	CString csCache1Next;
	if(csRefineTypeFlag2==_T("L") || csRefineTypeFlag2==_T("RL") )
		csCache1Next=  csCasterID2 + _T("P01");
	else
		if(csRefineTypeFlag2==_T("LR"))
			csCache1Next=  csRHID2 + _T("P01");


	CString csCache2Next;
	if(csRefineTypeFlag1==_T("L") || csRefineTypeFlag1==_T("RL") )
		csCache2Next=  csCasterID1 + _T("P01");
	else
		if(csRefineTypeFlag1==_T("LR"))
			csCache2Next=  csRHID1 + _T("P01");


	if(csCache1!=_T(""))
	{
		if(MoveSteelFromCache(csCache1,csHeatID1) < 0)
			return -31;
		if(AddSteelToCache(csCache1Next,csHeatID1) < 0)
			return -32;

	}

	if(csCache2!=_T(""))
	{
		if(MoveSteelFromCache(csCache2,csHeatID2) < 0)
			return -31;
		if(AddSteelToCache(csCache2Next,csHeatID2) < 0)
			return -32;

	}

	return 0;
}



/// <Method class="CDispatch_Mag" name="MoveSteelWhenBOFExPlan" type="L3LONG">
/// 
/// 当转炉工序交换计划时钢水移动
/// ARG&gt;&gt; 
///  &gt;&gt; csHeatID：炉号
/// RET &lt;&lt;返回0
/// </Method>

L3LONG CPlan_Mag::MoveSteelWhenBOFExPlan(CString cstrURI1,CString cstrURI2)
{
	CString csBOFID1 = GetObjectPropValue(cstrURI1, _T("BOFID")).ToCString();
	CString csBOFID2 = GetObjectPropValue(cstrURI2, _T("BOFID")).ToCString();
	if(csBOFID1 ==UNIT_ID_1BOF) csBOFID1 = UNIT_ID_1TAPSIDE;
	if(csBOFID1 ==UNIT_ID_2BOF) csBOFID1 = UNIT_ID_2TAPSIDE;
	if(csBOFID1 ==UNIT_ID_3BOF) csBOFID1 = UNIT_ID_3TAPSIDE;
	if(csBOFID1 ==UNIT_ID_4BOF) csBOFID1 = UNIT_ID_4TAPSIDE;

	if(csBOFID2 ==UNIT_ID_1BOF) csBOFID2 = UNIT_ID_1TAPSIDE;
	if(csBOFID2 ==UNIT_ID_2BOF) csBOFID2 = UNIT_ID_2TAPSIDE;
	if(csBOFID2 ==UNIT_ID_3BOF) csBOFID2 = UNIT_ID_3TAPSIDE;
	if(csBOFID2 ==UNIT_ID_4BOF) csBOFID2 = UNIT_ID_4TAPSIDE;

	if(csBOFID1 != csBOFID2)
	{
		CString csHeatID1= GetObjectPropValue(cstrURI1, _T("HeatID")).ToCString();
		CString csHeatID2= GetObjectPropValue(cstrURI2, _T("HeatID")).ToCString();
		CString csCache1 = GetCurSteelCache(csHeatID1);
		CString csCache2 = GetCurSteelCache(csHeatID2);
		CString csUnitType1 = csCache1.Mid(1,1);
		CString csUnitType2 = csCache2.Mid(1,1);

		if(csUnitType1 == UNIT_TYPE_TAPSIDE)
		{
			if(MoveSteelFromCache(csCache1,csHeatID1) < 0)
				return -31;
			CString csCacheUri = csBOFID2 + _T("P01");
			if(AddSteelToCache(csCacheUri,csHeatID1) < 0)
				return -32;
		}
		if(csUnitType2 == UNIT_TYPE_TAPSIDE)
		{
			if(MoveSteelFromCache(csCache2,csHeatID2) < 0)
				return -31;
			CString csCacheUri = csBOFID1 + _T("P01");
			if(AddSteelToCache(csCacheUri,csHeatID2) < 0)
				return -32;
		}
	}
	return 0;
}



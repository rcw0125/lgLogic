// 逻辑类CMIF_Unit_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CMIF_Unit_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CMIF_Unit_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CMIF_Unit_Mag.h"
#include "_CMIF_Mag.h"
#include "L3NameParser.h"
#include "Material.h"
#include "_CIron_Data.h"

//当对象被装载到系统中时，被调用
void CMIF_Unit_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CMIF_Unit_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 返回机组的加工区域
/// ARG << lstURIs : 接收所有加工区对象的URI
/// </summary>
BOOL CMIF_Unit_Mag::GetProduceAreas(CStringList& lstURIs)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetProduceAreas( lstURIs);
}

/// <summary>
/// 得到机组前序材料缓冲区的URI
/// </summary>
CString CMIF_Unit_Mag::GetInputCache()
{
	return BFIronStoreOutCache_URI;
}

/// <summary>
/// 得到机组后继材料缓冲区的URI
/// </summary>
CString CMIF_Unit_Mag::GetOutputCache()
{
	return MIXFProduceCache_URI;
}

/// <summary>
/// 机组上料前预处理。在机组上料前调用，继承类可重载此方法进行预先数据准备和处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 返回TRUE继续上料；返回FALSE中断上料。
/// </summary>
BOOL CMIF_Unit_Mag::OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeFeedMaterials( rsMaterialInfo);
}


/// <summary>
/// 机组上料后续处理。在机组上料后调用，继承类可重载此方法进行额外处理。
/// ARG >> rsMaterialInfo : 材料信息记录集。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CMIF_Unit_Mag::OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsFeeded( rsMaterialInfo);
}


/// <summary>
/// 返回机组上料记录的类型URI
/// </summary>
CString CMIF_Unit_Mag::GetFeedingLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetFeedingLogType();
}


/// <summary>
/// 准备上料记录数据。继承类可重载此函数进行额外的数据处理。
/// ARG >> rsFeedingLogs : 上料记录信息。
/// RET << void
/// </summary>
void CMIF_Unit_Mag::PrepareFeedingLogs(L3RECORDSET rsFeedingLogs)
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::PrepareFeedingLogs( rsFeedingLogs);
}


/// <summary>
/// 加工参数预处理。在调用加工区域的加工方法前调用，继承类可重载此函数对加工参数进行修改和配置。
/// ARG >> lpcszArea : 加工区域的URI
///		>> rsParameters : 加工参数记录集。
/// RET << 返回TRUE继续加工；返回FALSE中断加工。
/// </summary>
BOOL CMIF_Unit_Mag::PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PrepareProcessParameters( lpcszArea, rsParameters);
}


/// <summary>
/// 加工完成后续处理。在加工完成后调用，继承类可重载此函数进行额外逻辑处理
/// ARG >> lpcszArea : 加工区域的URI
///		>> nProcessType : 加工的类型。
///		>> rsProducts : 加工产生的产品的信息记录。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CMIF_Unit_Mag::OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterProcessCompleted( lpcszArea, nProcessType, rsProducts);
}


/// <summary>
/// 下线前预处理。在执行下线操作前调用，继承类可重载此函数进行预先的数据准备和处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 返回TRUE继续下线；返回FALSE中断下线。
/// </summary>
BOOL CMIF_Unit_Mag::OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeDeliverMaterials( rsMaterialInfo);
}

/// <summary>
/// 下线后续处理。在执行下线操作后调用，继承类可重载此函数进行额外处理。
/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CMIF_Unit_Mag::OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterMaterialsDelivered( rsMaterialInfo);
}


/// <summary>
/// 返回机组产出记录的类型URI
/// </summary>
CString CMIF_Unit_Mag::GetDeliveryLogType()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetDeliveryLogType();
}


/// <summary>
/// 准备下料记录数据。
/// ARG >> rsDeliveryLog : 下料记录数据。
/// RET <<void
/// </summary>
void CMIF_Unit_Mag::PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog)
{
	// TODO: 在此处编辑相关功能的处理代码

	__super::PrepareDeliveryLogs( rsDeliveryLog);
}


/// <summary>
/// 返回本机组的通讯器对象的URI
/// </summary>
CString CMIF_Unit_Mag::GetCommunicator()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetCommunicator();
}


/// <summary>
/// 准备计划数据，以便向机组下位系统发送。
/// ARG >> lpcszPlanType : 计划类型。
///		>> rsPlan : 计划数据。包括PlanID字段。
///		<< rsSend : 接收准备好的计划发送数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CMIF_Unit_Mag::PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForSending( lpcszPlanType, rsPlan, pprsSend);
}


/// <summary>
/// 计划下达后续处理。在向下位系统发送计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsSend : 下发下位系统的计划数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CMIF_Unit_Mag::OnAfterPlansSent(L3RECORDSET rsSend)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterPlansSent( rsSend);
}


/// <summary>
/// 准备计划数据，以便通知机组下位系统取消计划。
/// ARG >> lpcszPlanType : 计划类型。
///		>> rsPlan : 计划数据。包括PlanID字段。
///		<< rsSend : 接收准备好的计划取消数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CMIF_Unit_Mag::PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PreparePlanForCancel( lpcszPlanType, rsPlan, pprsCancel);
}


/// <summary>
/// 计划取消后续处理。在向下位系统发送取消计划后调用，继承类可重载此函数进行后续处理。
/// ARG >> rsCancel : 下发下位系统的计划取消数据。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CMIF_Unit_Mag::OnAfterPlansCanceled(L3RECORDSET rsCancel)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterPlansCanceled( rsCancel);
}


/// <summary>
/// 处理材料上线的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CMIF_Unit_Mag::HandleMaterialFeedingEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialFeedingEvent(pEvt);
}

/// <summary>
/// 处理材料进入加工区域的事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CMIF_Unit_Mag::HandleMaterialEnterAreaEvent(MatEnterArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialEnterAreaEvent(pEvt);
}

/// <summary>
/// 处理材料离开加工区域事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CMIF_Unit_Mag::HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialLeaveAreaEvent(pEvt);
}

/// <summary>
/// 处理材料生产完毕事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CMIF_Unit_Mag::HandleMaterialProducedEvent(MatProduced *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleMaterialProducedEvent(pEvt);
}

/// <summary>
/// 处理机组测量数据变更事件
/// ARG >> pEvt : 事件对象
/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
/// </summary>
BOOL CMIF_Unit_Mag::HandleUnitMeasureChangedEvent(UnitMeasure *pEvt)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::HandleUnitMeasureChangedEvent(pEvt);
}

/// <Method class="CMIF_Unit_Mag" name="CalculateChemicalData" type="L3VOID">
/// <Param name="rsIron" type="L3RECORDSET">铁水罐数据</Param>
/// </Method>
L3VOID CMIF_Unit_Mag::CalculateChemicalData(L3RECORDSET rsIron)
{
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CMIF_Unit_Mag" name="SampleChemcialData" type="L3LONG">
/// 混铁炉来样处理函数
/// <Param name="rsChemical" type="L3RECORDSET">成份数据</Param>
/// </Method>
L3LONG CMIF_Unit_Mag::SampleChemcialData(L3RECORDSET rsChemical)
{
	// TODO : 请在此添加逻辑代码
	return 0;
}

/// <Method class="CMIF_Unit_Mag" name="MixIrons" type="L3LONG">
/// 将某些铁水混入混铁炉
/// <Param name="rsIrons" type="L3RECORDSET">混入混铁炉的铁水记录</Param>
/// </Method>
L3LONG CMIF_Unit_Mag::MixIrons(L3RECORDSET rsIrons)
{
	CL3RecordSetWrap rs = rsIrons;
	if(rs.GetRowCount() < 1)
		return 0;

	// 检查及准备数据
	if(rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Spare_Weight")) < 0 ||
		rs.GetFieldIndex(_T("Net_Weight")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
	}
	rs.AddField(_T("MaterialType"),VT_BSTR);
	rs.AddField(_T("Amount"),VT_R8);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CBFIron")));
		rs.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		rs.MoveNext();
	}
	
	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	// 锁住铁水库出口Cache
	if(!PutObjectIntoTrans(BFIronStoreOutCache_URI))
	{
		Rollback(nTrans);
		return -1;
	}

	// 准备铁水重量修正记录集
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsUpdate; pRS->QueryInterface(IID_IL3RecordSet,rsUpdate); pRS->Release();
	rsUpdate.AddField(_T("MaterialType"),VT_BSTR);
	rsUpdate.AddField(_T("MaterialID"),VT_BSTR);
	rsUpdate.AddField(_T("Spare_Weight"),VT_R8);
	//Modify begin by llj 2011-04-11 修正铁水总重量
	rsUpdate.AddField(_T("Gross_Weight"),VT_R8);
	//Modify end
	rsUpdate.AddField(_T("Feed_Time"),VT_DATE);

	//2009-05-17 tangyiy 修改为以下
	CL3RecordSet *pRSdel = new CL3RecordSet();
	CL3RecordSetWrap rsDel; pRSdel->QueryInterface(IID_IL3RecordSet,rsDel); pRSdel->Release();
	rsDel.AddField(_T("MaterialType"),VT_BSTR);
	rsDel.AddField(_T("MaterialID"),VT_BSTR);
	rsDel.AddField(_T("Amount"),VT_R8);
	rsDel.AddField(_T("Status"),VT_I4);
	rsDel.AddField(_T("Feed_Time"),VT_DATE);
	rsDel.AddField(_T("Spare_Weight"),VT_R8);

	// 准备混铁日志
	CL3RecordSetWrap rsLog;
	if(!CreateClassPropSet(MIXF_FeedLog_URI,rsLog))
	{
		Rollback(nTrans);
		return -1;
	}
	rsLog.DelField(_T("GUID"));
	
	COleDateTime curDate = COleDateTime::GetCurrentTime();
	CString strUser = GetCurrentUser();

	// 处理铁水信息
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString IronID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString IronURI = CL3NameParser::MergeClassDomainName(MATERIAL_BFIRON_URI,IronID);
		// 检查该铁水的重量
		CL3Variant valOrgWeight = GetObjectPropValue(IronURI,_T("Spare_Weight"));
		L3DOUBLE fOrgWeight = valOrgWeight.ToDouble();
		L3DOUBLE fMixWeight = rs.GetFieldByName(_T("Net_Weight")).ToDouble();
		L3DOUBLE fOff = fOrgWeight - fMixWeight;
		//if(fOff < -0.00000001)
		if(fOff < -0.005) //2009-06-10 tangyi
		{	// 铁水重量不够
			Rollback(nTrans);
			SetL3LastError(MESERR_MATERIAL_NOTENOUGH);
			return NULL;
		}
		else if(fOff < 0.00000001)
		{	// 兑入全部铁水
			rsDel.AppendRecord();
			//rsDel.CopyCurRowFrom(rs);//2008-12-23
			rsDel.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
			rsDel.SetFieldByName(_T("MaterialID"),CL3Variant(IronID));
			rsDel.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
			rsDel.SetFieldByName(_T("Status"),CL3Variant((LONG)Material::Deleted));
		    rsDel.SetFieldByName(_T("Feed_Time"),COleDateTime::GetCurrentTime());
			rsDel.SetFieldByName(_T("Spare_Weight"),CL3Variant((LONG)0));
		}
		else
		{	// 兑入部分铁水
			rsUpdate.AppendRecord();
			rsUpdate.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
			rsUpdate.SetFieldByName(_T("MaterialID"),CL3Variant(IronID));
			rsUpdate.SetFieldByName(_T("Spare_Weight"),CL3Variant(fOff));
			//Modify begin by llj 2011-04-11 铁水未兑完时，其毛重将变为原毛重-兑入量
			CString IronURI = CL3NameParser::MergeClassDomainName(MATERIAL_BFIRON_URI,IronID);
			// 获取铁水原毛重
			CL3Variant valGrossWeight = GetObjectPropValue(IronURI,_T("Gross_Weight"));
			L3DOUBLE fGrossWeight = valGrossWeight.ToDouble();
			fGrossWeight=fGrossWeight-fMixWeight;
			rsDel.SetFieldByName(_T("Gross_Weight"),CL3Variant(fGrossWeight));
			//Modify end
		    rsUpdate.SetFieldByName(_T("Feed_Time"),COleDateTime::GetCurrentTime());
		}
		// 写日志
		rsLog.AppendRecord();
		rsLog.CopyCurRowFrom(rs);
		rsLog.SetFieldByName(_T("LogDate"),CL3Variant(curDate));
		//rsLog.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_BFIRON_URI));2009-01-08 tangyi
		rsLog.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CBFIron")));
		rsLog.SetFieldByName(_T("MaterialID"),CL3Variant(IronID));
		rsLog.SetFieldByName(_T("Amount"),CL3Variant(fMixWeight));
		rsLog.SetFieldByName(_T("MIFID"),CL3Variant(GetIdentity().ToCString()));//2009-04-25 tangyi
		//2009-01-08 tangyi
		CString csInputCacheUri = GetInputCache();
		CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
		CString csPos = valRet.ToCString();
		rsLog.SetFieldByName(_T("SourceArea"),CL3Variant(csPos));
		rsLog.SetFieldByName(_T("Operator"),CL3Variant(strUser));
		//rsLog.SetFieldByName(_T("LogTime"),CL3Variant(COleDateTime::GetCurrentTime()));
		rs.MoveNext();
	}
	// 将铁水混入混铁炉
	CL3RecordSet* pRsMix = new CL3RecordSet();
	CL3RecordSetWrap rsMix; pRsMix->QueryInterface(IID_IL3RecordSet,rsMix); pRsMix->Release();
	rsMix.AddField(_T("Net_Weight"),VT_R8);
	rsMix.AddField(_T("Mn"),VT_R8);
	rsMix.AddField(_T("P"),VT_R8);
	rsMix.AddField(_T("S"),VT_R8);
	rsMix.AddField(_T("Ti"),VT_R8);
	rsMix.AddField(_T("Si"),VT_R8);
	rsMix.AddField(_T("C"),VT_R8);
	//add by hyh 2012-05-11
	rsMix.AddField(_T("Sn"),VT_R8);
	rsMix.AddField(_T("Sb"),VT_R8);
	rsMix.AddField(_T("As"),VT_R8);
	rsMix.AddField(_T("Pb"),VT_R8);
	//end

	//add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	rsMix.AddField(_T("Ni"),VT_R8);
	rsMix.AddField(_T("Mo"),VT_R8);
	rsMix.AddField(_T("Cu"),VT_R8);
	rsMix.AddField(_T("Cr"),VT_R8);
	rsMix.AddField(_T("B"),VT_R8);
	rsMix.AddField(_T("V"),VT_R8);
	rsMix.AddField(_T("Al"),VT_R8);
	rsMix.AddField(_T("Nb"),VT_R8);
	rsMix.AddField(_T("Zn"),VT_R8);
	rsMix.AddField(_T("W"),VT_R8);
	//end

	rsMix.AppendRecord();
	CL3RecordSetWrap rsMixData = rs.Clone();
	rsMixData.AppendRecord();
	rsMixData.SetFieldByName(_T("Net_Weight"),GetPropValue(_T("Weight")));
	rsMixData.SetFieldByName(_T("C"),CL3Variant(/*C == 0 ? C_Cal : */C));
	rsMixData.SetFieldByName(_T("Si"),CL3Variant(/*Si == 0 ? Si_Cal : */Si));
	rsMixData.SetFieldByName(_T("Mn"),CL3Variant(/*Mn == 0 ? Mn_Cal : */Mn));
	rsMixData.SetFieldByName(_T("P"),CL3Variant(/*P == 0 ? P_Cal : */P));
	rsMixData.SetFieldByName(_T("S"),CL3Variant(/*S == 0 ? S_Cal : */S));
	rsMixData.SetFieldByName(_T("Ti"),CL3Variant(/*Ti == 0 ? Ti_Cal : */Ti));
	//add by hyh 2012-05-11
	rsMixData.SetFieldByName(_T("Sn"),CL3Variant(/*Sn == 0 ? Sn_Cal : */Sn));
	rsMixData.SetFieldByName(_T("Sb"),CL3Variant(/*Sb == 0 ? Sb_Cal : */Sb));
	rsMixData.SetFieldByName(_T("As"),CL3Variant(/*As == 0 ? As_Cal : */As));
	rsMixData.SetFieldByName(_T("Pb"),CL3Variant(/*Pb == 0 ? Pb_Cal : */Pb));
	//end

	//add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	rsMixData.SetFieldByName(_T("Ni"),CL3Variant(/*Ni == 0 ? Ni_Cal : */Ni));
	rsMixData.SetFieldByName(_T("Mo"),CL3Variant(/*Mo == 0 ? Mo_Cal : */Mo));
	rsMixData.SetFieldByName(_T("Cu"),CL3Variant(/*Cu == 0 ? Cu_Cal : */Cu));
	rsMixData.SetFieldByName(_T("Cr"),CL3Variant(/*Cr == 0 ? Cr_Cal : */Cr));
	rsMixData.SetFieldByName(_T("B"),CL3Variant(/*B == 0 ? B_Cal : */B));
	rsMixData.SetFieldByName(_T("V"),CL3Variant(/*V == 0 ? V_Cal : */V));
	rsMixData.SetFieldByName(_T("Al"),CL3Variant(/*Al == 0 ? Al_Cal : */Al));
	rsMixData.SetFieldByName(_T("Nb"),CL3Variant(/*Nb == 0 ? Nb_Cal : */Nb));
	rsMixData.SetFieldByName(_T("Zn"),CL3Variant(/*Zn == 0 ? Zn_Cal : */Zn));
	rsMixData.SetFieldByName(_T("W"),CL3Variant(/*W == 0 ? W_Cal : */W));
	//end

	rsMixData.MoveFirst();
	if(!CMIF_Mag::MixIrons(rsMixData,rsMix))
	{
		Rollback(nTrans);
		return 0;
	}
	SetPropValue(_T("Weight"),rsMix.GetFieldByName(_T("Net_Weight")));
	SetPropValue(_T("C_Cal"),rsMix.GetFieldByName(_T("C")));
	SetPropValue(_T("Si_Cal"),rsMix.GetFieldByName(_T("Si")));
	SetPropValue(_T("Mn_Cal"),rsMix.GetFieldByName(_T("Mn")));
	SetPropValue(_T("P_Cal"),rsMix.GetFieldByName(_T("P")));
	SetPropValue(_T("S_Cal"),rsMix.GetFieldByName(_T("S")));
	SetPropValue(_T("Ti_Cal"),rsMix.GetFieldByName(_T("Ti")));
	//add by hyh 2012-05-11
	SetPropValue(_T("Sn_Cal"),rsMix.GetFieldByName(_T("Sn")));
	SetPropValue(_T("Sb_Cal"),rsMix.GetFieldByName(_T("Sb")));
	SetPropValue(_T("As_Cal"),rsMix.GetFieldByName(_T("As")));
	SetPropValue(_T("Pb_Cal"),rsMix.GetFieldByName(_T("Pb")));
	//end

	//add by hyh 2012-08-13 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	SetPropValue(_T("Ni_Cal"),rsMix.GetFieldByName(_T("Ni")));
	SetPropValue(_T("Mo_Cal"),rsMix.GetFieldByName(_T("Mo")));
	SetPropValue(_T("Cu_Cal"),rsMix.GetFieldByName(_T("Cu")));
	SetPropValue(_T("Cr_Cal"),rsMix.GetFieldByName(_T("Cr")));
	SetPropValue(_T("B_Cal"),rsMix.GetFieldByName(_T("B")));
	SetPropValue(_T("V_Cal"),rsMix.GetFieldByName(_T("V")));
	SetPropValue(_T("Al_Cal"),rsMix.GetFieldByName(_T("Al")));
	SetPropValue(_T("Nb_Cal"),rsMix.GetFieldByName(_T("Nb")));
	SetPropValue(_T("Zn_Cal"),rsMix.GetFieldByName(_T("Zn")));
	SetPropValue(_T("W_Cal"),rsMix.GetFieldByName(_T("W")));
	//end

	//Modify begin by llj 2011-04-14 铁水成分移动加权平均
	/*
	SetPropValue(_T("C"),rsMix.GetFieldByName(_T("C")));
	SetPropValue(_T("Si"),rsMix.GetFieldByName(_T("Si")));
	SetPropValue(_T("Mn"),rsMix.GetFieldByName(_T("Mn")));
	SetPropValue(_T("P"),rsMix.GetFieldByName(_T("P")));
	SetPropValue(_T("S"),rsMix.GetFieldByName(_T("S")));
	SetPropValue(_T("Ti"),rsMix.GetFieldByName(_T("Ti")));
	*/
	//Modify end

	// 将全部兑入的铁水从入口区域移出并置删除标志。
	if (rsDel.GetRowCount() > 0)
	{
		rsDel.MoveFirst();
		CL3Variant valRet = InvokeObjectMethod(BFIronStoreOutCache_URI,_T("RemoveMaterials"),(L3RECORDSET)rsDel);
		if(valRet.ToBOOL() == FALSE)
		{
			Rollback(nTrans);
			return 0;
		}
		rsDel.MoveFirst();
		if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rsDel))
		{
			Rollback(nTrans);
			return 0;
		}
	}
	// 对未全部兑入的铁水，修改其剩余量
	if (rsUpdate.GetRowCount() > 0)
	{
		rsUpdate.MoveFirst();
		if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rsUpdate))
		{
			Rollback(nTrans);
			return 0;
		}
	}

	// 记录日志
	rsLog.MoveFirst();
	if(CreateNewObjects(MIXF_FeedLog_URI,rsLog) < 1)
	{
		Rollback(nTrans);
		return 0;
	}

	Commit(nTrans);
	return rs.GetRowCount();
}

/// <Method class="CMIF_Unit_Mag" name="OutputIron" type="L3BOOL">
/// 向目标铁包出铁
/// <Param name="LadleID" type="L3STRING">目标铁包号</Param>
/// <Param name="fWeight" type="L3DOUBLE">出铁重量</Param>
/// <Param name="fReHeatWeight" type="L3DOUBLE">回炉钢重量</Param>
/// </Method>
L3BOOL CMIF_Unit_Mag::OutputIron(L3STRING LadleID, L3DOUBLE fWeight,L3DOUBLE fReHeatWeight,L3STRING Destination)
{
	CString strLadle = ::String_BSTR2TChar(LadleID);
	CString dest=Destination;

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return FALSE;

	// 锁定本混铁炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		Rollback(nTrans);
		return FALSE;
	}

	// 检查铁量
	if(Weight < fWeight)
	{
		Rollback(nTrans);
		SetL3LastError(MESERR_MATERIAL_NOTENOUGH);
		return FALSE;
	}

	// 创建铁水对象
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	CString strIronID; strIronID.Format(_T("%s_%04d%02d%02d%02d%02d%02d"),(LPCTSTR)strLadle,curTime.GetYear(),curTime.GetMonth(),curTime.GetDay(),curTime.GetHour(),curTime.GetMinute(),curTime.GetSecond());
	CL3RecordSetWrap rsIron;
	if(!CreateClassPropSet(MATERIAL_IRON_URI,rsIron))
	{
		Rollback(nTrans);
		return FALSE;
	}
	rsIron.AppendRecord();
	rsIron.SetFieldByName(_T("MaterialID"),CL3Variant(strIronID));
	rsIron.SetFieldByName(_T("IronLadleNo"),CL3Variant(strLadle));
	rsIron.SetFieldByName(_T("Weight"),CL3Variant(fWeight));
	rsIron.SetFieldByName(_T("Return_Steel_Weight"),CL3Variant(fReHeatWeight));
	rsIron.SetFieldByName(_T("Tap_Time"),CL3Variant(curTime));
	//add by hyh 2012-04-26
	if(GetIdentity().ToCString() == _T("S11"))
		rsIron.SetFieldByName(_T("Source"),CL3Variant((LONG)CIron_Data::FromMix1));
	else if(GetIdentity().ToCString() == _T("S12"))
		rsIron.SetFieldByName(_T("Source"),CL3Variant((LONG)CIron_Data::FromMix2));
	else
		rsIron.SetFieldByName(_T("Source"),CL3Variant((LONG)CIron_Data::FromMix3));
	//end
	rsIron.SetFieldByName(_T("IronTemp"),GetPropValue(_T("Temp")));
	//Modify begin by llj 出铁时使用计算元素
	rsIron.SetFieldByName(_T("C"),GetPropValue(_T("C_Cal")));
	rsIron.SetFieldByName(_T("Si"),GetPropValue(_T("Si_Cal")));
	rsIron.SetFieldByName(_T("Mn"),GetPropValue(_T("Mn_Cal")));
	rsIron.SetFieldByName(_T("P"),GetPropValue(_T("P_Cal")));
	rsIron.SetFieldByName(_T("S"),GetPropValue(_T("S_Cal")));
	rsIron.SetFieldByName(_T("Ti"),GetPropValue(_T("Ti_Cal")));
	//add by hyh 2012-04-26
	rsIron.SetFieldByName(_T("Sn"),GetPropValue(_T("Sn_Cal")));
	rsIron.SetFieldByName(_T("Sb"),GetPropValue(_T("Sb_Cal")));
	rsIron.SetFieldByName(_T("As"),GetPropValue(_T("As_Cal")));
	rsIron.SetFieldByName(_T("Pb"),GetPropValue(_T("Pb_Cal")));
	//end

	//add by hyh 2012-08-13 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	rsIron.SetFieldByName(_T("Ni"),GetPropValue(_T("Ni_Cal")));
	rsIron.SetFieldByName(_T("Mo"),GetPropValue(_T("Mo_Cal")));
	rsIron.SetFieldByName(_T("Cu"),GetPropValue(_T("Cu_Cal")));
	rsIron.SetFieldByName(_T("Cr"),GetPropValue(_T("Cr_Cal")));
	rsIron.SetFieldByName(_T("B"),GetPropValue(_T("B_Cal")));
	rsIron.SetFieldByName(_T("V"),GetPropValue(_T("V_Cal")));
	rsIron.SetFieldByName(_T("Al"),GetPropValue(_T("Al_Cal")));
	rsIron.SetFieldByName(_T("Nb"),GetPropValue(_T("Nb_Cal")));
	rsIron.SetFieldByName(_T("Zn"),GetPropValue(_T("Zn_Cal")));
	rsIron.SetFieldByName(_T("W"),GetPropValue(_T("W_Cal")));
	//end
	//Modify end
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rsIron.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsIron.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));
	rsIron.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	if(CreateNewObjects(MATERIAL_IRON_URI,rsIron) < 1)
	{
		Rollback(nTrans);
		return FALSE;
	}

	// 修改剩余重量
	Weight -= fWeight;

	// 将新铁水移入出口区域
	rsIron.AddField(_T("MaterialType"),VT_BSTR);
	rsIron.AddField(_T("Amount"),VT_R8);
	rsIron.MoveFirst();
	rsIron.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CIron_Data")));
	rsIron.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
	CL3Variant valRet;
	if(dest=="1")
	{
	 valRet = InvokeObjectMethod(MIXFProduceCache_URI,_T("AddMaterials"),(L3RECORDSET)rsIron);
	}
	else
	{
	valRet = InvokeObjectMethod(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S91P01"),_T("AddMaterials"),(L3RECORDSET)rsIron);
	}
	
	if(valRet.ToBOOL() == FALSE)
	{
		Rollback(nTrans);
		return FALSE;
	}

	// 将铁包状态设为在用
	CString strLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,strLadle);
	SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_USE));
	
	//2009-05-26
	long iIronLadleAge = GetObjectPropValue(strLadleURI,_T("IronLadle_Age")).ToLong();
	iIronLadleAge += 1;

	SetObjectPropValue(strLadleURI,_T("IronLadle_Age"),CL3Variant(L3LONG(iIronLadleAge)));


	Commit(nTrans);

	return TRUE;
}

/// <Method class="CMIF_Unit_Mag" name="AcceptIronLadleWeightData" type="L3BOOL">
/// 接收混铁炉称重数据 2009-01-04
/// <Param name="rsData" type="L3RECORDSET">混铁炉重量数据</Param>
/// </Method>
L3BOOL CMIF_Unit_Mag::AcceptIronLadleWeightData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveLast();
	L3DOUBLE fWeight = rs.GetFieldByName(_T("Weight")).ToDouble();
    Gross_Weight=fWeight;
	Gross_Weight_Time = COleDateTime::GetCurrentTime();

	//记录称重数据
	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\MIXFMag\\CMIF_Weight"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	CString csShift = rpSysInfo.GetFieldByName(_T("ShiftID")).ToCString();
	CString csTeam = rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("Source"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("Shift"),CL3Variant(csShift));
		rsTemp.SetFieldByName(_T("Team"),CL3Variant(csTeam));
		rsTemp.SetFieldByName(_T("Weight_Time"),CL3Variant(COleDateTime::GetCurrentTime()));

		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\MIXFMag\\CMIF_Weight"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CMIF_Unit_Mag" name="AcceptTemperatureData" type="L3BOOL">
/// 接收混铁炉测温数据 2009-01-04
/// <Param name="rsData" type="L3RECORDSET">混铁炉测温数据</Param>
/// </Method>
L3BOOL CMIF_Unit_Mag::AcceptTemperatureData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveLast();
	L3LONG iTemp = rs.GetFieldByName(_T("Temp")).ToLong();
    Temp = iTemp;
	Temp_Time = COleDateTime::GetCurrentTime();

	//记录测温数据
	CL3RecordSetWrap rsTemp;
	if(!CreateClassPropSet(_T("XGMESLogic\\MIXFMag\\CMIF_Temp_Data"),rsTemp))
	{
		return FALSE;
	}

	rsTemp.CopyFrom(rs);

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	CString csShift = rpSysInfo.GetFieldByName(_T("ShiftID")).ToCString();
	CString csTeam = rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();

	rsTemp.MoveFirst();
	while (!rsTemp.IsEOF())
	{
		rsTemp.SetFieldByName(_T("MIFID"),CL3Variant(GetIdentity().ToCString()));
		rsTemp.SetFieldByName(_T("Shift"),CL3Variant(csShift));
		rsTemp.SetFieldByName(_T("Team"),CL3Variant(csTeam));
		rsTemp.SetFieldByName(_T("Temp_Time"),CL3Variant(COleDateTime::GetCurrentTime()));

		rsTemp.MoveNext();
	}

	rsTemp.MoveFirst();
	if(CreateNewObjects(_T("XGMESLogic\\MIXFMag\\CMIF_Temp_Data"),rsTemp) < rsTemp.GetRowCount())
	{
		return FALSE;
	}

	return TRUE;	
}

/// <Method class="CMIF_Unit_Mag" name="AcceptDirectIronWeightData" type="L3BOOL">
/// 接收混铁炉过跨线铁包称重数据 2009-01-04
/// <Param name="rsData" type="L3RECORDSET">过跨线铁包重量数据</Param>
/// </Method>
L3BOOL CMIF_Unit_Mag::AcceptDirectIronWeightData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return TRUE;

	rs.MoveLast();
	L3DOUBLE fWeight = rs.GetFieldByName(_T("Weight")).ToDouble();
    Tare_Weight = fWeight;
	Tare_Weight_Time = COleDateTime::GetCurrentTime();

	return TRUE;	
}



/// <Method class="CMIF_Unit_Mag" name="OutputIronCancel" type="L3BOOL">
/// 取消混铁炉出铁2009-03-11
/// </Method>
L3LONG CMIF_Unit_Mag::OutputIronCancel(L3RECORDSET rsLadleID)
{
	CL3RecordSetWrap rs = rsLadleID;
	if(rs.GetRowCount() < 1 || rs.IsNull())
		return -1;

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	// 锁定本混铁炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		Rollback(nTrans);
		return -2;
	}

	//组建数据集
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("Amount"),VT_INT);
	rsMaterial.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//修改剩余重量
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csIronUri = CL3NameParser::MergeClassDomainName(MATERIAL_IRON_URI,csMaterialID);
		CString csHeatID = GetObjectPropValue(csIronUri,_T("HeatID")).ToCString();
		csHeatID.Trim();
		//已经指定主原料不允许取消
		if(!csHeatID.IsEmpty())
		{
			Rollback(nTrans);
			return -3;
		}
		L3LONG nSource = GetObjectPropValue(csIronUri,_T("Source")).ToLong();
		//直兑铁水不允许取消
		if(nSource < 1)
		{
			Rollback(nTrans);
			return -4;
		}
		L3DOUBLE fWeight = GetObjectPropValue(csIronUri,_T("Weight")).ToDouble();
		Weight += fWeight;

		//更改铁包的状态为热备
		CString csIronLadle = GetObjectPropValue(csIronUri,_T("IronLadleNo")).ToCString();
		CString csLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,csIronLadle);
		if(!SetObjectPropValue(csLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT)))
		{
			Rollback(nTrans);
			return -7;
		}

		//删除铁水对象
		if(!DeleteOldObject(csIronUri))
		{
			Rollback(nTrans);
			return -5;
		}
		// 将新铁水移出出口区域
		rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_IRON));
		rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rsMaterial.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		CL3Variant valRet = InvokeObjectMethod(MIXFProduceCache_URI,_T("RemoveMaterials"),(L3RECORDSET)rsMaterial);
		if(valRet.ToBOOL() == FALSE)
		{
			Rollback(nTrans);
			return -6;
		}

		rsMaterial.MoveFirst();
		rs.MoveNext();
	}

	Commit(nTrans);

	return 1;
}

//取消去脱磷站的出铁
L3LONG CMIF_Unit_Mag::OutputIronCancelToDEP(L3RECORDSET rsLadleID)
{
	CL3RecordSetWrap rs = rsLadleID;
	if(rs.GetRowCount() < 1 || rs.IsNull())
		return -1;

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	// 锁定本混铁炉
	if(!PutObjectIntoTrans(GetURI()))
	{
		Rollback(nTrans);
		return -2;
	}

	//组建数据集
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("Amount"),VT_INT);
	rsMaterial.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//修改剩余重量
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csIronUri = CL3NameParser::MergeClassDomainName(MATERIAL_IRON_URI,csMaterialID);
		CString csHeatID = GetObjectPropValue(csIronUri,_T("HeatID")).ToCString();
		csHeatID.Trim();
		//已经指定主原料不允许取消
		if(!csHeatID.IsEmpty())
		{
			Rollback(nTrans);
			return -3;
		}
		L3LONG nSource = GetObjectPropValue(csIronUri,_T("Source")).ToLong();
		//直兑铁水不允许取消
		if(nSource < 1)
		{
			Rollback(nTrans);
			return -4;
		}
		L3DOUBLE fWeight = GetObjectPropValue(csIronUri,_T("Weight")).ToDouble();
		Weight += fWeight;

		//更改铁包的状态为热备
		CString csIronLadle = GetObjectPropValue(csIronUri,_T("IronLadleNo")).ToCString();
		CString csLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,csIronLadle);
		if(!SetObjectPropValue(csLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT)))
		{
			Rollback(nTrans);
			return -7;
		}

		//删除铁水对象
		if(!DeleteOldObject(csIronUri))
		{
			Rollback(nTrans);
			return -5;
		}
		// 将新铁水移出出口区域
		rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_IRON));
		rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rsMaterial.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S91P01"),_T("RemoveMaterials"),(L3RECORDSET)rsMaterial);
		if(valRet.ToBOOL() == FALSE)
		{
			Rollback(nTrans);
			return -6;
		}

		rsMaterial.MoveFirst();
		rs.MoveNext();
	}

	Commit(nTrans);

	return 1;
}

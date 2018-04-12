// 逻辑类CBOF_Prod_Area的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CBOF_Prod_Area.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CBOF_Prod_Area.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CBOF_Prod_Area.h"
#include "L3NameParser.h"

//当对象被装载到系统中时，被调用
void CBOF_Prod_Area::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CBOF_Prod_Area::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 生成位置编码的虚函数。继承类可以重载此函数进行自己的位置编码定义。
/// ARG >> void
/// RET << 位置编码
/// </summary>
CString CBOF_Prod_Area::GetPositionCode()
{
	return GetPropValue(_T("Code")).ToCString();
}

/// <summary>
/// 加工前预处理。在进行加工逻辑处理前调用，继承类可重载此函数进行数据预处理。
/// ARG >> rsParameter : 加工参数记录集。
/// RET << 返回TRUE继续加工；返回FALSE中断加工。
/// </summary>
BOOL CBOF_Prod_Area::OnBeforeProcess(L3RECORDSET rsParameter)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeProcess( rsParameter);
}

/// <summary>
/// 材料加工逻辑处理。继承类需要重载此函数进行其特定的材料加工处理。
/// 注意：在此方法中不要对加工相关的数据进行直接修改！调用它的主函数会做处理！
/// ARG >> rsMaterials : 加工使用的原料信息。包括MaterialType,MaterialID,Amount字段。
///		>> rsParameter : 加工使用的参数记录集。
///		<< pnProcessType : 成功后返回加工类型。
///		<< prsProducts : 成功后返回产品数据记录。
///		<< prsMaterialMap : 如果加工类型是CreateNew，成功后返回原料成品对照表。否则无用。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBOF_Prod_Area::ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap)
{
	CL3RecordSetWrap rsMat = rsMaterials;
	CL3RecordSetWrap rsParam = rsParameter;

	if(rsMat.GetRowCount() < 1 || rsParam.GetRowCount() < 1)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}
	
	rsParam.MoveFirst();
	CString strHeatID = rsParam.GetFieldByName(_T("HeatID")).ToCString(); strHeatID.Trim();
	if(strHeatID.IsEmpty())
	{	
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return FALSE;
	}

	// 查询计划数据
	CL3RecordSetWrap rsPlan;
	CString strPlan; strPlan.Format(_T("select * from %s where HeatID = '%s'"),PLAN_TAPPING_CLASS_URI,(LPCTSTR)GetRealHeatID(strHeatID));
	Query(strPlan,rsPlan);
	if(rsPlan.GetRowCount() > 0)
		rsPlan.MoveFirst();
	CString strPreHeatID = rsPlan.GetFieldByName(_T("PreHeatID")).ToCString();
	//2008-12-25 tangyi 钢包从转炉实绩中查找
	CString strLadleID = GetObjectPropValue(CL3NameParser::MergeClassDomainName(BOF_PROCESS_DATA_CLASS_URI,strHeatID),_T("LadleNo")).ToCString();

	// 将钢包状态设定为在用
	//CString strLadleURI = CL3NameParser::MergeClassDomainName(CLADLE_BASE_URI,strLadleID);
	//SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CLADLE_STATUS_USE));

	// 构造新钢水数据
	CL3RecordSetWrap rsSteel;
	if(!CreateClassPropSet(MATERIAL_STEEL_URI,rsSteel))
		return FALSE;
	rsSteel.AddField(MESPROP_MATERIAL_TYPE,VT_BSTR);
	rsSteel.AddField(MESPROP_AMOUNT,VT_R8);
	rsSteel.AppendRecord();
	if(rsPlan.GetRowCount() > 0)
		rsSteel.CopyCurRowFrom(rsPlan);
	rsSteel.SetFieldByName(MESPROP_MATERIAL_TYPE,CL3Variant(_T("CSteel_Data")));
	rsSteel.SetFieldByName(MESPROP_MATERIAL_ID,CL3Variant(strHeatID));
	rsSteel.SetFieldByName(MESPROP_AMOUNT,CL3Variant((L3DOUBLE)1));
	rsSteel.SetFieldByName(_T("HeatID"),CL3Variant(strHeatID));
	rsSteel.SetFieldByName(_T("LadleID"),CL3Variant(strLadleID));
	rsSteel.SetFieldByName(_T("Status"),CL3Variant((LONG)1));

	// 构造对照数据
	CL3RecordSetWrap rsMap;
	if(!CreateClassPropSet(MES_MATERIAL_MAP,rsMap))
		return FALSE;
	rsMat.MoveFirst();
	while(!rsMat.IsEOF())
	{
		rsMap.AppendRecord();
		rsMap.SetFieldByName(_T("FromType"),CL3Variant(_T("CIron_Data")));
		rsMap.SetFieldByName(_T("FromID"),rsMat.GetFieldByName(_T("MaterialID")));
		rsMap.SetFieldByName(_T("ToType"),CL3Variant(_T("CSteel_Data")));
		rsMap.SetFieldByName(_T("ToID"),CL3Variant(strHeatID));
		rsMap.SetFieldByName(_T("SrcAmount"),rsMat.GetFieldByName(_T("Net_Weight")));
		rsMap.SetFieldByName(_T("TgtAmount"),CL3Variant((LONG)1));
		rsMat.MoveNext();
	}

	*pnProcessType = ProduceArea::CreateNew;
	*prsProducts = rsSteel.Detach();
	*prsMaterialMap = rsMap.Detach();

	return TRUE;
}

/// <summary>
/// 加工后续处理。在加工逻辑处理完成后调用，继承类可重载此函数进行额外处理。
/// ARG >> rsMaterials : 加工使用的原料信息。包括MaterialType,MaterialID,Amount字段。
///		>> rsParameter : 加工使用的参数记录集。
///		>> pnProcessType : 加工类型。
///		>> rsProducts : 产品数据记录。
///		>> rsMaterialMap : 如果加工类型是CreateNew，为原料成品对照表。否则无用。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CBOF_Prod_Area::OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterProcessed( rsMaterials, rsParameter, nProcessType, rsProducts, rsMaterialMap);
}

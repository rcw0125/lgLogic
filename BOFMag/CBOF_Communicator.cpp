// 逻辑类CBOF_Communicator的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CBOF_Communicator.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CBOF_Communicator.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CBOF_Communicator.h"

//当对象被装载到系统中时，被调用
void CBOF_Communicator::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CBOF_Communicator::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <Method class="CBOF_Communicator" name="OnFeedIron" type="L3BOOL">
/// 响应兑铁加废钢事件函数
/// <Param name="rsData" type="L3RECORDSET">兑铁数据</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnFeedIron(L3RECORDSET rsData)
{
    return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBOF_Communicator" name="OnChangeStatus" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// 状态数据
/// (BOFID,Status,Change_Time)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnChangeStatus(L3RECORDSET rsData)
{
    return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBOF_Communicator" name="OnDischarge" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// 加料记录集
/// (Element,Weight,Discharge_Time,Type)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnDischarge(L3RECORDSET rsData)
{
    return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBOF_Communicator" name="OnMeasureTemp" type="L3BOOL">
/// 测温事件响应函数
/// <Param name="rsData" type="L3RECORDSET">
/// 测温数据
/// (Temp,Temp_Time,Mode)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnMeasureTemp(L3RECORDSET rsData)
{
    return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBOF_Communicator" name="OnMeasureO2" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// 定氧数据
/// (O2,Measure_Time)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnMeasureO2(L3RECORDSET rsData)
{
    return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBOF_Communicator" name="OnTapped" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBOF_Communicator::OnTapped(L3RECORDSET rsData)
{
    return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBOF_Communicator" name="OnBottomBlow" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// 底吹数据
/// (BOFID,Flow1...Flow6,Pressure1...Pressure6,Gas_Type)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnBottomBlow(L3RECORDSET rsData)
{
	CString strID = GetIdentity().ToCString();
	CString strBOFURI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\") + strID;

	CL3Variant valRet = InvokeObjectMethod(strBOFURI,_T("BottomBlowing"),(L3RECORDSET)rsData);
	if(valRet.IsError())
		return false;
	else
		return valRet.ToBOOL();

// TODO : 请在此添加逻辑代码
}

/// <Method class="CBOF_Communicator" name="OnTopBlow" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// 顶吹数据
/// (BFID,Flow,Pressure,Catch_Time)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnTopBlow(L3RECORDSET rsData)
{
    return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBOF_Communicator" name="OnSauceEvent" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBOF_Communicator::OnSauceEvent(L3RECORDSET rsData)
{
    return true;
	// TODO : 请在此添加逻辑代码
}

/// <Method class="CBOF_Communicator" name="OnTapStart" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBOF_Communicator::OnTapStart(L3RECORDSET rsData)
{
    return true;
	// TODO : 请在此添加逻辑代码
}

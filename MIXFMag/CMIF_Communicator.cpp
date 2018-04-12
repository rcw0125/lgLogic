// 逻辑类CMIF_Communicator的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CMIF_Communicator.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CMIF_Communicator.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CMIF_Communicator.h"

//当对象被装载到系统中时，被调用
void CMIF_Communicator::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CMIF_Communicator::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <Method class="CMIF_Communicator" name="OnMIFTemperature" type="L3BOOL">
/// 混铁炉温度数据到达事件相应函数
/// <Param name="rsTemp" type="L3RECORDSET">温度数据(炉座号,温度值,测温时刻)</Param>
/// </Method>
L3BOOL CMIF_Communicator::OnMIFTemperature(L3RECORDSET rsTemp)
{
    return 0; 
}

/// <Method class="CMIF_Communicator" name="OnWeight" type="L3BOOL">
/// 称重事件到达处理函数
/// <Param name="rsWeight" type="L3RECORDSET">称重数据</Param>
/// </Method>
L3BOOL CMIF_Communicator::OnWeight(L3RECORDSET rsWeight)
{
    return 0; 
}

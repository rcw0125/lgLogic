// 逻辑类CNCCommunicator的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CNCCommunicator.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CNCCommunicator.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CNCCommunicator.h"

//当对象被装载到系统中时，被调用
void CNCCommunicator::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CNCCommunicator::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}



/// <Method class="CNCCommunicator" name="SendCastIronDataToNC" type="LONG">
/// 将铁水信息发送到NC系统。
/// <Param name="rsIron" type="L3RECORDSET">包含铁水信息的记录集</Param>
/// </Method>
LONG CNCCommunicator::SendCastIronDataToNC(L3RECORDSET rsIron)
{
	// TODO : 请在此添加逻辑代码
	return 0;
}

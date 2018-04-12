// 逻辑类XGStoreArea的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_XGStoreArea.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_XGStoreArea.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_XGStoreArea.h"

//当对象被装载到系统中时，被调用
void XGStoreArea::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void XGStoreArea::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
///	返回该缓冲区的全局位置编码。此编码必须是全局唯一的！
/// </summary>
CString XGStoreArea::GetPositionCode()
{
	// TODO: 在此处编辑相关功能的处理代码

	return GetPropValue(_T("Code")).ToCString();
}

double XGStoreArea::GetAmountTolerance()
{
	CString csStoreArea = GetIdentity().ToCString();
	CString csStoreType = csStoreArea.Mid(0,3);
	if(csStoreType == STORE_ID_SCRAP)
		return 0.01;
	else
		return 10;
}

// 逻辑类XGInterCache的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_XGInterCache.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_XGInterCache.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_XGInterCache.h"

//当对象被装载到系统中时，被调用
void XGInterCache::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void XGInterCache::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
///	返回该缓冲区的全局位置编码。此编码必须是全局唯一的！
/// </summary>
CString XGInterCache::GetPositionCode()
{
	// TODO: 在此处编辑相关功能的处理代码

	return GetPropValue(_T("Code")).ToCString();
}

/// <summary>
/// 得到该缓冲区的特性标识。不同的特性决定了不同的缓冲区工作方式。
/// 标识内容参见枚举 MaterialCacheFlags 的定义。
/// </summary>
DWORD XGInterCache::GetCacheFlags()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetCacheFlags();
};

/// <summary>
/// 得到该缓冲区的供应缓冲区的URI。供应缓冲区可在该缓冲区缺货时，允许此缓冲区主动从其中调货。
/// </summary>
CString XGInterCache::GetSupplier()
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetSupplier();
};

/// <summary>
/// 得到该缓冲区的消费缓冲区的URI。消费缓冲区可在该缓冲区收到新的材料时，允许此缓冲区主动将材料发往其中。
/// </summary>
CString XGInterCache::GetConsumer() 
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetConsumer();
};


double XGInterCache::GetAmountTolerance()
{
	CString csStoreArea = GetIdentity().ToCString();
	CString csStoreType = csStoreArea.Mid(0,3);
	if(csStoreType == STORE_ID_SCRAP)
		return 0.01;
	else
		return 10;
}
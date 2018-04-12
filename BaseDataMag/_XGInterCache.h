// 逻辑类XGInterCache头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialCache.h"

class XGInterCache :
	public MaterialCache
{
public:
	XGInterCache(void);
	virtual ~XGInterCache(void);

	DECLARE_L3CLASS(XGInterCache,XGMESLogic\\BaseDataMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(XGInterCache)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

protected:
	/// <summary>
	/// 得到该缓冲区的特性标识。不同的特性决定了不同的缓冲区工作方式。
	/// 标识内容参见枚举 MaterialCacheFlags 的定义。
	/// </summary>
	virtual DWORD GetCacheFlags();

	/// <summary>
	/// 得到该缓冲区的供应缓冲区的URI。供应缓冲区可在该缓冲区缺货时，允许此缓冲区主动从其中调货。
	/// </summary>
	virtual CString GetSupplier();

	/// <summary>
	/// 得到该缓冲区的消费缓冲区的URI。消费缓冲区可在该缓冲区收到新的材料时，允许此缓冲区主动将材料发往其中。
	/// </summary>
	virtual CString GetConsumer();

	/// <summary>
	/// 生成位置编码的虚函数。继承类可以重载此函数进行自己的位置编码定义。
	/// ARG >> void
	/// RET << 位置编码
	/// </summary>
	virtual CString GetPositionCode();

	virtual double GetAmountTolerance();//2009-03-27
};

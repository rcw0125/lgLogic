// 逻辑类XGStoreArea头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialStoreArea.h"

class XGStoreArea :
	public MaterialStoreArea
{
public:
	XGStoreArea(void);
	virtual ~XGStoreArea(void);

	DECLARE_L3CLASS(XGStoreArea,XGMESLogic\\BaseDataMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(XGStoreArea)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

protected:
	 ////<summary>
	 ////生成位置编码的虚函数。继承类可以重载此函数进行自己的位置编码定义。
	 ////ARG >> void
	 ////RET << 位置编码
	 ////</summary>
	virtual CString GetPositionCode();

	virtual double GetAmountTolerance();//2009-03-27
};

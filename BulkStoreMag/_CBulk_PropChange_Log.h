// 逻辑类CBulk_PropChange_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialPropLog.h"

class CBulk_PropChange_Log :
	public MaterialPropLog
{
public:
	CBulk_PropChange_Log(void);
	virtual ~CBulk_PropChange_Log(void);

	DECLARE_L3CLASS(CBulk_PropChange_Log,XGMESLogic\\BulkStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_PropChange_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBulk_PropChange_Log" name="Amount" type="L3DOUBLE">
	/// 材料量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	/// <Property class="CBulk_PropChange_Log" name="Operator" type="L3STRING">
	/// 修改人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

};

// 逻辑类CSteel_To_Steel_Map头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialMap.h"
class CSteel_To_Steel_Map :
	public MaterialMap
{
public:
	CSteel_To_Steel_Map(void);
	virtual ~CSteel_To_Steel_Map(void);

	DECLARE_L3CLASS(CSteel_To_Steel_Map,XGMESLogic\\PlanMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CSteel_To_Steel_Map)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

};

// 逻辑类CLF_ProdArea头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLF_ProdArea :
	public CL3Object
{
public:
	CLF_ProdArea(void);
	virtual ~CLF_ProdArea(void);

	DECLARE_L3CLASS(CLF_ProdArea,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_ProdArea)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

};

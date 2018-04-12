// 逻辑类CCommunicationStatus头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCommunicationStatus :
	public CL3Object
{
public:
	CCommunicationStatus(void);
	virtual ~CCommunicationStatus(void);

	DECLARE_L3CLASS(CCommunicationStatus,XGMESLogic\\BaseDataMag, WorkShop)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCommunicationStatus)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	DECLARE_L3PROP_STRING  (WorkShop)     //工位        
	DECLARE_L3PROP_LONG    (WatchDog)     //计数值  
};

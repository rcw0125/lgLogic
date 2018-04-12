// 逻辑类CBOF_FenderSlagConsume头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_FenderSlagConsume :
	public CL3Object
{
public:
	CBOF_FenderSlagConsume(void);
	virtual ~CBOF_FenderSlagConsume(void);

	DECLARE_L3CLASS(CBOF_FenderSlagConsume,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_FenderSlagConsume)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_FenderSlagConsume" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_FenderSlagConsume" name="FenderSlag" type="L3SHORT">
	/// 
	/// 挡渣物料
	/// (1:挡渣球
	///  2:挡渣锥
	///  3:挡渣塞)
	/// </Property>
	DECLARE_L3PROP_SHORT(FenderSlag)

	/// <Property class="CBOF_FenderSlagConsume" name="Consume" type="L3FLOAT">
	/// 消耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(Consume)

};

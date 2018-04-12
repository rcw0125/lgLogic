// 逻辑类CLF_BlowAr_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLF_BlowAr_Data :
	public CL3Object
{
public:
	CLF_BlowAr_Data(void);
	virtual ~CLF_BlowAr_Data(void);

	DECLARE_L3CLASS(CLF_BlowAr_Data,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_BlowAr_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLF_BlowAr_Data" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_BlowAr_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_BlowAr_Data" name="Flow_BlowAr" type="L3DOUBLE">
	/// 吹氩流量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr)

	/// <Property class="CLF_BlowAr_Data" name="LogTime" type="L3DATETIME">
	/// 记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)
};

// 逻辑类CBOF_Proc_Stat_Def头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_Proc_Stat_Def :
	public CL3Object
{
public:
	CBOF_Proc_Stat_Def(void);
	virtual ~CBOF_Proc_Stat_Def(void);

	DECLARE_L3CLASS(CBOF_Proc_Stat_Def,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Proc_Stat_Def)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_Proc_Stat_Def" name="Status" type="L3SHORT">
	/// 状态
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CBOF_Proc_Stat_Def" name="Descr" type="L3STRING">
	/// 
	/// 状态(1:加废钢兑铁;
	///          2:主吹;
	///          3:补吹;
	///          4:出钢开始;
	///          5:出钢结束;
	///          6:溅渣开始;
	///          7:溅渣结束;
	///          8:倒渣开始;
	///          9:倒渣结束[等待])
	/// </Property>
	DECLARE_L3PROP_STRING(Descr)

};

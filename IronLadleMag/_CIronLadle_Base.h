// 逻辑类CIronLadle_Base头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CIronLadle_Base :
	public CL3Object
{
public:
	CIronLadle_Base(void);
	virtual ~CIronLadle_Base(void);

	DECLARE_L3CLASS(CIronLadle_Base,XGMESLogic\\IronLadleMag, IronLadleID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Base)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CIronLadle_Base" name="IronLadleID" type="L3STRING">
	/// 铁包号
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadleID)

	/// <Property class="CIronLadle_Base" name="TieID" type="L3STRING">
	/// 铁包打结编号
	/// </Property>
	DECLARE_L3PROP_STRING(TieID)

	/// <Property class="CIronLadle_Base" name="Status" type="L3STRING">
	/// 状态
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CIronLadle_Base" name="ComFlag" type="L3LONG">
	/// 完成标志
	/// </Property>
	DECLARE_L3PROP_LONG(ComFlag)
    
	/// <Property class="CIronLadle_Base" name="IronLadle_Age" type="L3LONG">
	/// 包龄
	/// </Property>
	DECLARE_L3PROP_LONG(IronLadle_Age)

	/// <Property class="CIronLadle_Base" name="Tare_Weight" type="L3FLOAT">
	/// 皮重
	/// </Property>
	DECLARE_L3PROP_FLOAT(Tare_Weight)

	/// <Property class="CIronLadle_Base" name="Gross_Weight" type="L3FLOAT">
	/// 毛重
	/// </Property>
	DECLARE_L3PROP_FLOAT(Gross_Weight)

	/// <Property class="CIronLadle_Base" name="Net_Weight" type="L3FLOAT">
	/// 净重
	/// </Property>
	DECLARE_L3PROP_FLOAT(Net_Weight)

	/// <Property class="CIronLadle_Base" name="Refra_Produce" type="L3STRING">
	/// 耐材厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Produce)

	/// <Property class="CIronLadle_Base" name="Refra_ID" type="L3STRING">
	/// 耐材名称
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_ID)
	
	//2009-03-17
	/// <Property class="CIronLadle_Base" name="Small_FireID" type="L3LONG">
	/// 小火烘烤次数
	/// </Property>
	DECLARE_L3PROP_LONG(Small_FireID)

	/// <Property class="CIronLadle_Base" name="Middle_FireID" type="L3LONG">
	/// 中火烘烤次数
	/// </Property>
	DECLARE_L3PROP_LONG(Middle_FireID)

	/// <Property class="CIronLadle_Base" name="Big_FireID" type="L3LONG">
	/// 大火烘烤次数
	/// </Property>
	DECLARE_L3PROP_LONG(Big_FireID)

};

// 逻辑类CQA_Unit_Route头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Unit_Route :
	public CL3Object
{
public:
	CQA_Unit_Route(void);
	virtual ~CQA_Unit_Route(void);

	DECLARE_L3CLASS(CQA_Unit_Route,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Unit_Route)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Unit_Route" name="Lev_Type" type="L3LONG">
	/// 优先级、
	/// </Property>
	DECLARE_L3PROP_LONG(Lev_Type)

	/// <Property class="CQA_Unit_Route" name="BOFID" type="L3STRING">
	/// 转炉工位、
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CQA_Unit_Route" name="LFID" type="L3STRING">
	/// LF工位、
	/// </Property>
	DECLARE_L3PROP_STRING(LFID)

	/// <Property class="CQA_Unit_Route" name="RHID" type="L3STRING">
	/// RH工位、
	/// </Property>
	DECLARE_L3PROP_STRING(RHID)

	/// <Property class="CQA_Unit_Route" name="CasterID" type="L3STRING">
	/// 连铸工位
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

};

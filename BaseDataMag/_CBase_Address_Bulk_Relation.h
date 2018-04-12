// 逻辑类CBase_Address_Bulk_Relation头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Address_Bulk_Relation :
	public CL3Object
{
public:
	CBase_Address_Bulk_Relation(void);
	virtual ~CBase_Address_Bulk_Relation(void);

	DECLARE_L3CLASS(CBase_Address_Bulk_Relation,XGMESLogic\\BaseDataMag, PLC_Address)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Address_Bulk_Relation)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Address_Bulk_Relation" name="PLC_Address" type="L3STRING">
	/// PLC地址
	/// </Property>
	DECLARE_L3PROP_STRING(PLC_Address)

	/// <Property class="CBase_Address_Bulk_Relation" name="AreaID" type="L3STRING">
	/// 料仓编码 若为1即为顶渣;若为2需根据工艺路径(过LF或RH)萤石振料小于50kg的一批属于顶渣)
	/// </Property>
	DECLARE_L3PROP_STRING(Area)

};

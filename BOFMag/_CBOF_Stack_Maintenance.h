// 逻辑类CBOF_Stack_Maintenance头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_Stack_Maintenance :
	public CL3Object
{
public:
	CBOF_Stack_Maintenance(void);
	virtual ~CBOF_Stack_Maintenance(void);

	DECLARE_L3CLASS(CBOF_Stack_Maintenance,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Stack_Maintenance)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_Stack_Maintenance" name="ProductionDate" type="L3DATETIME">
	/// 日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProductionDate)

	/// <Property class="CBOF_Stack_Maintenance" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CBOF_Stack_Maintenance" name="Content" type="L3STRING">
	/// 
	/// 维护内容
	/// (1:钻出钢口;
	///  2:下管;
	///  3:护钢面
	///  4:打钢面
	///  5:护渣面
	///  6:打渣面
	///  7:护渣线
	///  8:打炉底
	///  9:喷补炉衬
	///  10:喷补耳轴
	///  11:喷出钢口
	///  12:喷炉口)
	/// </Property>
	DECLARE_L3PROP_STRING(Content)

	/// <Property class="CBOF_Stack_Maintenance" name="Materiel" type="L3STRING">
	/// 
	/// 使用物料
	/// (1:喷补料;
	///  2:炉底料;
	///  3:手投料)
	/// </Property>
	DECLARE_L3PROP_STRING(Materiel)

	/// <Property class="CBOF_Stack_Maintenance" name="Taphole_Vendor" type="L3STRING">
	/// 出钢口厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Taphole_Vendor)

	/// <Property class="CBOF_Stack_Maintenance" name="Materiel_Vendor" type="L3STRING">
	/// 物料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Materiel_Vendor)

	/// <Property class="CBOF_Stack_Maintenance" name="Wastage" type="L3FLOAT">
	/// 用料量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Wastage)

	/// <Property class="CBOF_Stack_Maintenance" name="BOFID" type="L3STRING">
	/// 炉座号
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

};

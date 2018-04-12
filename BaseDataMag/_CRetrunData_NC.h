// 逻辑类CRetrunData_NC头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CRetrunData_NC :
	public CL3Object
{
public:
	CRetrunData_NC(void);
	virtual ~CRetrunData_NC(void);

	DECLARE_L3CLASS(CRetrunData_NC,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRetrunData_NC)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CRetrunData_NC" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CRetrunData_NC" name="BillType" type="L3STRING">
	/// 单据类型
	/// </Property>
	DECLARE_L3PROP_STRING(BillType)

	/// <Property class="CRetrunData_NC" name="Flag" type="L3STRING">
	/// 成功标志
	/// </Property>
	DECLARE_L3PROP_STRING(Flag)

	/// <Property class="CRetrunData_NC" name="Remark" type="L3STRING">
	/// 失败原因
	/// </Property>
	DECLARE_L3PROP_STRING(Remark)

	/// <Property class="CRetrunData_NC" name="CreateTime" type="L3DATETIME">
	/// 创建时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

	/// <Property class="CRetrunData_NC" name="Other1" type="L3STRING">
	/// 其他1
	/// </Property>
	DECLARE_L3PROP_STRING(Other1)

	/// <Property class="CRetrunData_NC" name="Other2" type="L3STRING">
	/// 其他2
	/// </Property>
	DECLARE_L3PROP_STRING(Other2)

	/// <Property class="CRetrunData_NC" name="Other3" type="L3STRING">
	/// 其他3
	/// </Property>
	DECLARE_L3PROP_STRING(Other3)

};

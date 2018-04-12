// 逻辑类CPlan_BOF_Status头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CPlan_BOF_Status :
	public CL3Object
{
public:
	CPlan_BOF_Status(void);
	virtual ~CPlan_BOF_Status(void);

	DECLARE_L3CLASS(CPlan_BOF_Status,XGMESLogic\\PlanMag, BOFID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_BOF_Status)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CPlan_BOF_Status" name="BOFID" type="L3STRING">
	/// 转炉炉座
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CPlan_BOF_Status" name="Status" type="L3STRING">
	/// 状态
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CPlan_BOF_Status" name="New_BOF_Flag" type="L3SHORT">
	/// 新转炉标志
	/// </Property>
	DECLARE_L3PROP_SHORT(New_BOF_Flag)

};

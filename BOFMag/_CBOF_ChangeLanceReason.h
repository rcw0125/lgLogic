// 逻辑类CBOF_ChangeLanceReason头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_ChangeLanceReason :
	public CL3Object
{
public:
	CBOF_ChangeLanceReason(void);
	virtual ~CBOF_ChangeLanceReason(void);

	DECLARE_L3CLASS(CBOF_ChangeLanceReason,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_ChangeLanceReason)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_ChangeLanceReason" name="BOFID" type="L3SHORT">
	/// 转炉炉座号
	/// </Property>
	DECLARE_L3PROP_SHORT(BOFID)

	/// <Property class="CBOF_ChangeLanceReason" name="ChangeLance_Time" type="L3DATETIME">
	/// 换枪时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(ChangeLance_Time)

	/// <Property class="CBOF_ChangeLanceReason" name="Reason" type="L3STRING">
	/// 原因
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

};

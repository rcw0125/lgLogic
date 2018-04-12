// 逻辑类Team_Base_Infor头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Team_Infor :
	public CL3Object
{
public:
	CBase_Team_Infor(void);
	virtual ~CBase_Team_Infor(void);

	DECLARE_L3CLASS(CBase_Team_Infor,XGMESLogic\\BaseDataMag, Pk_Team)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(Team_Base_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="Team_Base_Infor" name="Pk_Team" type="L3STRING">
	/// 班组主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Team)

	/// <Property class="Team_Base_Infor" name="Team_Code" type="L3STRING">
	/// 班组编码
	/// </Property>
	DECLARE_L3PROP_STRING(Team_Code)

	/// <Property class="Team_Base_Infor" name="Team_Name" type="L3STRING">
	/// 班组名称
	/// </Property>
	DECLARE_L3PROP_STRING(Team_Name)

	/// <Property class="Team_Base_Infor" name="Pk_Center" type="L3STRING">
	/// 工作中心主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Center)

	/// <Property class="Team_Base_Infor" name="Pk_Department" type="L3STRING">
	/// 部门档案主键
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Department)

};

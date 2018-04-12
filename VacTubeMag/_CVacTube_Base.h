// 逻辑类CVacTube_Base头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CVacTube_Base :
	public CL3Object
{
public:
	CVacTube_Base(void);
	virtual ~CVacTube_Base(void);

	DECLARE_L3CLASS(CVacTube_Base,XGMESLogic\\VacTubeMag, VacTube_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Base)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Base" name="VacTube_Name" type="L3STRING">
	/// 槽管名称
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Name)

	/// <Property class="CVacTube_Base" name="VacTube_ID" type="L3STRING">
	/// 槽管编号
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_ID)

	/// <Property class="CVacTube_Base" name="Status" type="L3STRING">
	/// 状态
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CVacTube_Base" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CVacTube_Base" name="Position" type="L3STRING">
	/// 位置
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CVacTube_Base" name="Build_ID" type="L3STRING">
	/// 砌筑编号
	/// yymm+VacTube_ID+两位次数
	/// </Property>
	DECLARE_L3PROP_STRING(Build_ID)

	/// <Property class="CVacTube_Base" name="VacTube_Code" type="L3STRING">
	/// 真空槽编号
	/// 上部槽号+下部槽号(11)
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Code)

	/// <Property class="CVacTube_Base" name="VacTube_Age" type="L3LONG">
	/// 寿命
	/// </Property>
	DECLARE_L3PROP_LONG(VacTube_Age)

	/// <Property class="CVacTube_Base" name="Install_ID" type="L3STRING">
	/// 组装编号
	/// yymm+VacTube_Code+两位次数
	/// </Property>
	DECLARE_L3PROP_STRING(Install_ID)

	/// <Property class="CVacTube_Base" name="Flag" type="L3LONG">
	/// 完成标志
	/// </Property>
	DECLARE_L3PROP_LONG(Flag)

	/// <Property class="CVacTube_Base" name="Fire_Count" type="L3LONG">
	/// 烘烤次数
	/// </Property>
	DECLARE_L3PROP_LONG(Fire_Count)

};

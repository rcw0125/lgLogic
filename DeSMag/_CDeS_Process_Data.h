// 逻辑类CDeS_Process_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDeS_Process_Data :
	public CL3Object
{
public:
	CDeS_Process_Data(void);
	virtual ~CDeS_Process_Data(void);

	DECLARE_L3CLASS(CDeS_Process_Data,XGMESLogic\\DeSMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDeS_Process_Data" name="TreatNo" type="L3STRING">
	/// 喷吹号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CDeS_Process_Data" name="MaterialID" type="L3STRING">
	/// 铁水ID
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID)

	/// <Property class="CDeS_Process_Data" name="S_B" type="L3DOUBLE">
	/// 脱前硫(%)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_B)

	/// <Property class="CDeS_Process_Data" name="S_A" type="L3DOUBLE">
	/// 脱后硫(%)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_A)

	/// <Property class="CDeS_Process_Data" name="P_B" type="L3DOUBLE">
	/// 脱前磷(%)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_B)

	/// <Property class="CDeS_Process_Data" name="P_A" type="L3DOUBLE">
	/// 脱后磷(%)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_A)

	/// <Property class="CDeS_Process_Data" name="Mat_Consume" type="L3DOUBLE">
	/// 颗粒镁消耗
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mat_Consume)

	/// <Property class="CDeS_Process_Data" name="LanceNo" type="L3STRING">
	/// 喷枪号
	/// </Property>
	DECLARE_L3PROP_STRING(LanceNo)

	/// <Property class="CDeS_Process_Data" name="LanceAge" type="L3LONG">
	/// 枪龄
	/// </Property>
	DECLARE_L3PROP_LONG(LanceAge)

	/// <Property class="CDeS_Process_Data" name="BlowTime" type="L3LONG">
	/// 喷吹用时
	/// </Property>
	DECLARE_L3PROP_LONG(BlowTime)

	/// <Property class="CDeS_Process_Data" name="BlowBeginTime" type="L3DATETIME">
	/// 喷吹开始时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(BlowBeginTime)

	/// <Property class="CDeS_Process_Data" name="BlowEndTime" type="L3DATETIME">
	/// 喷吹结束时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(BlowEndTime)

	/// <Property class="CDeS_Process_Data" name="AreaID" type="L3STRING">
	/// 工位
	/// </Property>
	DECLARE_L3PROP_STRING(AreaID)
};

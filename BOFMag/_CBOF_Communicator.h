// 逻辑类CBOF_Communicator头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_Communicator :
	public CL3Object
{
public:
	CBOF_Communicator(void);
	virtual ~CBOF_Communicator(void);

	DECLARE_L3CLASS(CBOF_Communicator,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Communicator)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CBOF_Communicator" name="OnFeedIron" type="L3BOOL">
	/// 响应兑铁加废钢事件函数
	/// <Param name="rsData" type="L3RECORDSET">兑铁数据</Param>
	/// </Method>
	L3BOOL OnFeedIron(L3RECORDSET rsData);
	/// <Method class="CBOF_Communicator" name="OnChangeStatus" type="L3BOOL">
	/// <Param name="rsData" type="L3RECORDSET">
	/// 状态数据
	/// (BOFID,Status,Change_Time)</Param>
	/// </Method>
	L3BOOL OnChangeStatus(L3RECORDSET rsData);
	/// <Method class="CBOF_Communicator" name="OnDischarge" type="L3BOOL">
	/// <Param name="rsData" type="L3RECORDSET">
	/// 加料记录集
	/// (Element,Weight,Discharge_Time,Type)</Param>
	/// </Method>
	L3BOOL OnDischarge(L3RECORDSET rsData);
	/// <Method class="CBOF_Communicator" name="OnMeasureTemp" type="L3BOOL">
	/// 测温事件响应函数
	/// <Param name="rsData" type="L3RECORDSET">
	/// 测温数据
	/// (Temp,Temp_Time,Mode)</Param>
	/// </Method>
	L3BOOL OnMeasureTemp(L3RECORDSET rsData);
	/// <Method class="CBOF_Communicator" name="OnMeasureO2" type="L3BOOL">
	/// <Param name="rsData" type="L3RECORDSET">
	/// 定氧数据
	/// (O2,Measure_Time)</Param>
	/// </Method>
	L3BOOL OnMeasureO2(L3RECORDSET rsData);
	/// <Method class="CBOF_Communicator" name="OnTapped" type="L3BOOL">
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL OnTapped(L3RECORDSET rsData);
	/// <Method class="CBOF_Communicator" name="OnBottomBlow" type="L3BOOL">
	/// <Param name="rsData" type="L3RECORDSET">
	/// 底吹数据
	/// (BOFID,Flow1...Flow6,Pressure1...Pressure6,Gas_Type)</Param>
	/// </Method>
	L3BOOL OnBottomBlow(L3RECORDSET rsData);
	/// <Method class="CBOF_Communicator" name="OnTopBlow" type="L3BOOL">
	/// <Param name="rsData" type="L3RECORDSET">
	/// 顶吹数据
	/// (BFID,Flow,Pressure,Catch_Time)</Param>
	/// </Method>
	L3BOOL OnTopBlow(L3RECORDSET rsData);
	/// <Method class="CBOF_Communicator" name="OnSauceEvent" type="L3BOOL">
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL OnSauceEvent(L3RECORDSET rsData);
	/// <Method class="CBOF_Communicator" name="OnTapStart" type="L3BOOL">
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL OnTapStart(L3RECORDSET rsData);
};

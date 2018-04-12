// 逻辑类CDispatch_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once




class CDispatch_Mag :
	public CL3Object
{
public:
	CDispatch_Mag(void);
	virtual ~CDispatch_Mag(void);

	DECLARE_L3CLASS(CDispatch_Mag,XGMESLogic\\DispatchMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDispatch_Mag)
	DECLARE_L3EVENTSINK_MAP()

	DECLARE_L3PROP_LONG(SteelBackAppEvent)      //钢水返送申请事件
	DECLARE_L3PROP_LONG(SteelReturnAppEvent)     //钢水回炉申请事件
	DECLARE_L3PROP_LONG(SteelDivAppEvent)		//钢水炉次分割申请事件
	DECLARE_L3PROP_LONG(SteelExchangeAppEvent)	//钢水改钢申请事件

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CDispatch_Mag" name="SteelTurnApp" type="L3BOOL">
	/// 
	/// 钢水回炉申请
	/// ARG&gt;&gt; 
	/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID字段
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
	/// </Method>
	L3BOOL SteelTurnApp(L3RECORDSET rsSteelTurnAppData);

	/// <Method class="CDispatch_Mag" name="SteelTurn" type="L3BOOL">
	/// 
	/// 钢水回炉
	/// ARG&gt;&gt; strPreHeatID :预定炉号
	/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括GUID\PreHeatID\All_Turn_Flag三个字段
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
	/// </Method>
	L3LONG SteelTurn(L3RECORDSET rsSteelTurnData);

	/// <Method class="CDispatch_Mag" name="SteelBackApp" type="L3BOOL">
	/// 
	/// 钢水返送申请
	/// ARG&gt;&gt; 
	/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID字段
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
	/// </Method>
	L3BOOL SteelBackApp(L3RECORDSET rsSteelBackAppData);

	/// <Method class="CDispatch_Mag" name="SteelBack" type="L3BOOL">
	/// 
	/// 钢水返送
	/// ARG&gt;&gt; rsSteelBackData :钢水返送信息,必须包括GUID\PreHeatID\Back_UnitID三个字段
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsSteelBackData" type="L3RECORDSET">钢水返送信息</Param>
	/// </Method>
	L3LONG SteelBack(L3RECORDSET rsSteelBackData);

	/// <Method class="CDispatch_Mag" name="SteelDivApp" type="L3BOOL">
	/// 
	/// 钢水炉次分割申请
	/// ARG&gt;&gt; 
	/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID字段
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
	/// </Method>
	L3BOOL SteelDivApp(L3RECORDSET rsSteelDivAppData);

	/// <Method class="CDispatch_Mag" name="SteelDiv" type="L3BOOL">
	/// 
	/// 钢水分割
	/// ARG&gt;&gt; strPreHeatID :预定炉号
	///        &gt;&gt; strBackUnit:   返送工位
	///        &gt;&gt;strObjName:对象名
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="strPreHeatID" type="L3STRING">预定炉号</Param>
	/// <Param name="strBackUnit" type="L3STRING">返送工位</Param>
	/// <Param name="strObjName" type="L3STRING">预定炉号</Param>
	/// </Method>
	L3LONG SteelDiv(L3RECORDSET rsSteelDiv);

	/// <Method class="CDispatch_Mag" name="SteelExchangeApp" type="L3BOOL">
	/// 
	/// 钢水改钢申请
	/// ARG&gt;&gt; 
	/// &gt;&gt;rsSteelTurnData:钢水回炉信息,必须包括PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID字段
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">钢水回炉信息</Param>
	/// </Method>
	L3BOOL SteelExchangeApp(L3RECORDSET rsSteelExchangeAppData);

	/// <Method class="CDispatch_Mag" name="SteelExchange" type="L3BOOL">
	/// 
	/// 钢水改钢
	/// ARG &gt;&gt; 
	///     &gt;&gt;rsExchangeData：改钢数据集必须包括GUID\PreHeatID\Ex_SteelGradeIndex三个字段
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsExchangeData" type="L3RECORDSET">数据集</Param>
	/// </Method>
	L3LONG SteelExchange(L3RECORDSET rsExchangeData);
	/// <Method class="CDispatch_Mag" name="DispatchLog" type="L3BOOL">
	/// 
	/// 调度记事
	/// ARG&gt;&gt; rsData:数据集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsData" type="L3RECORDSET">数据</Param>
	/// </Method>
	L3BOOL DispatchLog(L3RECORDSET rsData);
	/// <Method class="CDispatch_Mag" name="GetBOFRealData" type="L3RECORDSET">
	/// 
	/// 获取转炉实时数据
	/// ARG&gt;&gt;strBOFID:转炉工序
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetBOFRealData(L3STRING strBOFID);

	/// <Method class="CDispatch_Mag" name="GetBOFSideRealData" type="L3RECORDSET">
	/// 
	/// 获取炉后实时数据
	/// ARG&gt;&gt;strBOFID:转炉工序
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetBOFSideRealData(L3STRING strBOFID);


	/// <Method class="CDispatch_Mag" name="GetFactoryEnergyData" type="">
	/// </Method>
	L3RECORDSET GetFactoryEnergyData();
	
	/// <Method class="CDispatch_Mag" name="Get1LFRealData" type="">
	/// 
	/// 获取LF炉实时数据
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetLFRealData(L3STRING strLFID);
	
	/// <Method class="CDispatch_Mag" name="Get1RHRealData" type="">
	/// 
	/// 获取1#RH炉实时数据
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetRHRealData(L3STRING strRHID);
	/// <Method class="CDispatch_Mag" name="Get1CasterRealData" type="">
	/// 
	/// 获取1#铸机实时数据
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetCasterRealData(L3STRING strCasterID);

	/// <Method class="CDispatch_Mag" name="GetAlloyStoreData" type="">
	/// 
	/// 获取合金原料库数据
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetAlloyStoreData();
	/// <Method class="CDispatch_Mag" name="GetScrapStoreData" type="">
	/// 
	/// 获取2#炉实时数据
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetScrapStoreData();
	/// <Method class="CDispatch_Mag" name="GetBloomStoreData" type="">
	/// 
	/// 获取2#炉实时数据
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetBloomStoreData();
	/// <Method class="CDispatch_Mag" name="GetBulkStoreData" type="">
	/// 
	/// 获取2#炉实时数据
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetBulkStoreData();
	/// <Method class="CDispatch_Mag" name="GetCurSteelBackInfor" type="DATASET">
	/// 
	/// 获取未处理钢包返送申请信息
	/// ARG 
	/// RET &gt;&gt; 找到的钢包返送申请信息记录集。
	/// </Method>
	L3RECORDSET GetCurSteelBackInfor();
	/// <Method class="CDispatch_Mag" name="GetCurSteelTurnInfor" type="DATASET">
	/// 
	/// 获取未处理钢包回炉申请信息
	/// ARG 
	/// RET &gt;&gt; 找到的钢包回炉申请信息记录集。
	/// </Method>
	L3RECORDSET GetCurSteelTurnInfor();
	/// <Method class="CDispatch_Mag" name="GetCurSteelDivInfor" type="DATASET">
	/// 
	/// 获取未处理钢包炉次分割申请信息
	/// ARG 
	/// RET &gt;&gt; 找到的钢包回炉炉次分割信息记录集。
	/// </Method>
	L3RECORDSET GetCurSteelDivInfor();
	/// <Method class="CDispatch_Mag" name="GetCurSteelExInfor" type="DATASET">
	/// 
	/// 获取未处理改钢申请信息
	/// ARG 
	/// RET &gt;&gt; 找到的改钢申请记录集。
	/// </Method>
	L3RECORDSET GetCurSteelExInfor();

	/// <Method class="CDispatch_Mag" name="GetCurSteelCache" type="DATASET">
	/// 
	/// 获取钢水当前所在缓存URi
	/// ARG csHeatID：炉号
	/// RET &gt;&gt; 找到的URi
	/// </Method>
	CString GetCurSteelCache(CString csHeatID);

	/// <Method class="CDispatch_Mag" name="SteelMoveInCache" type="L3LONG">
	/// 
	/// 在工序缓存中移动钢水
	/// ARG&gt;&gt; csTappingPlanURi：出钢计划URI
	///  &gt;&gt; nUnitType：目标工序
	///  &gt;&gt; csHeatID：炉号
	///  &gt;&gt; &csUnitID：目标机组
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3LONG  SteelMoveInCache(CString csTappingPlanURi,L3LONG nUnitType,CString csHeatID,CString &csUnitID);


	/// <Method class="CDispatch_Mag" name="SteelAllReturn" type="L3LONG">
	/// 
	/// 钢水全回炉
	/// ARG&gt;&gt; csTappingPlanURi：出钢计划URI
	///  &gt;&gt; csUnitID：全回炉申请机组
	///  &gt;&gt; csHeatID：炉号
	/// RET &lt;&lt;返回0错误代码
	/// </Method>
	L3LONG SteelAllReturn(CString csTappingPlanURi,CString csUnitID,CString csHeatID,L3DOUBLE fWeight);


	/// <Method class="CDispatch_Mag" name="MoveSteelFromCurCache" type="L3LONG">
	/// 
	/// 将钢水从当前缓存中移去
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID：炉号
	/// RET &lt;&lt;返回0
	/// </Method>

	L3LONG MoveSteelFromCurCache(CString csHeatID);


	/// <Method class="CDispatch_Mag" name="SteelMoveInCache" type="L3LONG">
	/// 
	/// 将钢水移动到指定的缓存同时更改计划信息
	/// ARG&gt;&gt; csTappingPlanURi：出钢计划URI
	///  &gt;&gt; nUnitType：目标工序
	///  &gt;&gt; &csUnitID：目标机组
	/// RET &lt;&lt;返回0
	/// </Method>

	L3LONG AddSteelToSpeciCache(CString csTappingPlanURi,L3LONG nUnitType,CString csHeatID,CString &csUnitID);


	/// <Method class="CDispatch_Mag" name="GetDestination" type="L3RECORDSET">
	/// 
	/// 获取工序工艺去向
	/// ARG&gt;&gt;strBOFID:转炉工序
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3STRING GetDestination(L3STRING strUnitID,L3STRING strHeatID);

	//2009-04-09 Liao
	/// <Method class="CDispatch_Mag" name="AddDisExceptional" type="L3LONG">
	/// 新增设备异常主信息
	/// <Param name="dsInfo" type="L3RECORDSET">新增主信息</Param>
	/// </Method>
	L3LONG AddDisExceptional(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="ModifyDisExceptional" type="L3LONG">
	/// 修改设备异常主信息
	/// <Param name="dsInfo" type="L3RECORDSET">修改的主信息</Param>
	/// </Method>
	L3LONG ModifyDisExceptional(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="DeleteDisExceptional" type="L3LONG">
	/// 删除设备异常主信息
	/// <Param name="dsInfo" type="L3RECORDSET">删除的主信息</Param>
	/// </Method>
	L3LONG DeleteDisExceptional(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="AddDisExceptionalItems" type="L3LONG">
	/// 新增设备异常详细信息
	/// <Param name="dsInfo" type="L3RECORDSET">新增的详细信息</Param>
	/// </Method>
	L3LONG AddDisExceptionalItems(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="ModifyDisExceptionalItems" type="L3LONG">
	/// 修改设备异常详细信息
	/// <Param name="dsInfo" type="L3RECORDSET">修改的详细信息</Param>
	/// </Method>
	L3LONG ModifyDisExceptionalItems(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="DelDisExceptionalItems" type="L3LONG">
	/// 删除设备异常详细信息
	/// <Param name="dsInfo" type="L3RECORDSET">删除的详细信息</Param>
	/// </Method>
	L3LONG DelDisExceptionalItems(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="GetDispExceData" type="L3RECORDSET">
	/// 通用获取设备异常主信息
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET GetDispExceData(L3STRING strCondition);
	/// <Method class="CDispatch_Mag" name="GetDispExceItemData" type="L3RECORDSET">
	/// 通用获取设备异常详细信息
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET GetDispExceItemData(L3STRING strCondition);
};

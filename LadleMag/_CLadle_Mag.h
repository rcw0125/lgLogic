// 逻辑类CLadle_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_Mag :
	public CL3Object
{
public:
	CLadle_Mag(void);
	virtual ~CLadle_Mag(void);

	DECLARE_L3CLASS(CLadle_Mag,XGMESLogic\\LadleMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Mag)
	DECLARE_L3EVENTSINK_MAP()

	DECLARE_L3PROP_LONG(LadlePlanEvent)               //钢包计划状态变化事件

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CLadle_Mag" name="SetLadleStatus" type="L3LONG">
	/// 
	/// 设置钢包状态
	/// ARG &gt;&gt; rsLadles: 要设置状态的钢包的记录集
	///     &gt;&gt; strStatus: 设置成为的状态。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// <Param name="strStatus" type="L3STRING"></Param>
	/// </Method>
	L3LONG SetLadleStatus(L3RECORDSET rsLadles, L3STRING strStatus);
	/// <Method class="CLadle_Mag" name="InsertInfos" type="L3LONG">
	/// 
	/// 添加实绩信息
	/// ARG &gt;&gt;strClassName:类名
	///     &gt;&gt;rsInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// <Param name="strClassName" type="L3STRING">类名</Param>
	/// </Method>
	L3LONG InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	/// <Method class="CLadle_Mag" name="UpdateInfos" type="L3LONG">
	/// 
	/// 修改实绩信息
	/// ARG &gt;&gt;lpcsClass:类名
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// <Param name="lpcsClass" type="LPCTSTR">类名</Param>
	/// </Method>
	L3LONG UpdateInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass);//LPCTSTR lpcsClass
	/// <Method class="CLadle_Mag" name="DeleteInfos" type="L3LONG">
	/// 
	/// 删除实绩信息
	/// ARG &gt;&gt;lpcsClass:类名
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// <Param name="lpcsClass" type="LPCTSTR">类名</Param>
	/// </Method>
	L3LONG DeleteInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass);
	/// <Method class="CLadle_Mag" name="GetInfos" type="L3RECORDSET">
	/// 
	/// 获取实绩信息
	/// ARG &gt;&gt;strClassName:类名
	///     &gt;&gt;strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reInfos；失败返回Null
	/// <Param name="lpcsClass" type="LPCTSTR">查询条件</Param>
	/// <Param name="lpcsCondition" type="LPCTSTR">类名</Param>
	/// </Method>
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);
	/// <Method class="CLadle_Mag" name="SpecifyLadle" type="L3LONG">
	/// 
	/// 指定钢包
	/// ARG &gt;&gt; rsLadlePlans: 要指定钢包的钢包计划的记录集。
	/// RET &lt;&lt; 成功返回true；失败返回false。
	/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SpecifyLadle(L3RECORDSET rsLadlePlans);
	/// <Method class="CLadle_Mag" name="LadlePour" type="L3LONG">
	/// 
	/// 钢包倒包
	/// ARG &gt;&gt; rsLadles: 要倒包的钢包的记录集。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadlePour(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleFold" type="L3LONG">
	/// 
	/// 钢包折罐
	/// ARG &gt;&gt; rsLadles: 要折罐的钢包的记录集。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleFold(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="CancelSpecifyLadle" type="L3LONG">
	/// 
	/// 取消指定
	/// ARG &gt;&gt; rsLadlePlans: 要取消指定的钢包计划的记录集。
	/// RET &lt;&lt; 成功返回true；失败返回false。
	/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG CancelSpecifyLadle(L3RECORDSET rsLadlePlans);
	/// <Method class="CLadle_Mag" name="ReSpecifyLadle" type="L3LONG">
	/// 
	/// 重新指定钢包
	/// ARG &gt;&gt; strReLadleID:指定钢包号；
	///          &gt;&gt; rsLadlePlans: 要指定钢包的钢包计划的记录集。
	/// RET &lt;&lt; 成功返回true；失败返回false。
	/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
	/// <Param name="strReLadleID" type="L3STRING"></Param>
	/// </Method>
	L3LONG ReSpecifyLadle(L3RECORDSET rsLadlePlans, L3STRING strReLadleID);



	/// <Method class="CLadle_Mag" name="QueryUnProcessLadlePlan" type="L3RECORDSET">
	/// 
	/// 获取当班计划信息以及上班未执行完成计划
	/// ARG &gt;&gt; strBofID: 转炉号。
	///         &gt;&gt;strCasterID:铸机号
	/// RET &gt;&gt; 找到的计划记录集。
	/// <Param name="strBofID" type="L3STRING"></Param>
	/// <Param name="strCasterID" type="L3STRING"></Param>
	/// </Method>

	L3RECORDSET QueryUnProcessLadlePlan(L3STRING strBOFID, L3STRING strCasterID);


	//查询可用钢包
	/// <Method class="CLadle_Mag" name="GetAvailableLadle" type="L3RECORDSET">
	/// </Method>
	L3RECORDSET GetAvailableLadle(void);

	//查询钢包永久层编号
	/// <Method class="CLadle_Mag" name="GetLadleInnerID" type="L3RECORDSET">
	/// <Param name="strDateLadleID" type="L3STRING">钢包号</Param>
	/// </Method>
	L3RECORDSET GetLadleInnerID(L3STRING strDateLadleID);

	/// <Method class="CLadle_Mag" name="InsertInnerBuildInfos" type="L3LONG">
	/// 
	/// 添加永久层打结实绩信息
	///     &gt;&gt;rsInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG InsertInnerBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateInnerBuildInfos" type="L3LONG">
	/// 
	/// 修改永久层打结实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG UpdateInnerBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteInnerBuildInfos" type="L3LONG">
	/// 
	/// 删除永久层打结实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG DeleteInnerBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetInnerBuildInfos" type="L3RECORDSET">
	/// 
	/// 获取永久层打结实绩信息
	///     &gt;&gt;strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reInfos；失败返回Null
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET GetInnerBuildInfos(L3STRING strCondition);
		
	/// <Method class="CLadle_Mag" name="InsertComTieInfos" type="L3LONG">
	/// 
	/// 添加工作层打结实绩信息
	///     &gt;&gt;rsInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  InsertComTieInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateComTieInfos" type="L3LONG">
	/// 
	/// 修改工作层打结实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  UpdateComTieInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteComTieInfos" type="L3LONG">
	/// 
	/// 删除工作层打结实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG DeleteComTieInfos(L3RECORDSET rsInfos);

	/// <Method class="CLadle_Mag" name="GetComTieInfos" type="L3RECORDSET">
	/// 
	/// 获取工作层打结实绩信息
	///     &gt;&gt;strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reInfos；失败返回Null
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET  GetComTieInfos(L3STRING strCondition);

	/// <Method class="CLadle_Mag" name="InsertComRepInfos" type="L3LONG">
	/// 
	/// 添加工作层修补实绩信息
	///     &gt;&gt;rsInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  InsertComRepInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateComRepInfos" type="L3LONG">
	/// 
	/// 修改工作层修补实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  UpdateComRepInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteComRepInfos" type="L3LONG">
	/// 
	/// 删除工作层修补实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  DeleteComRepInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetComRepInfos" type="L3RECORDSET">
	/// 
	/// 获取工作层修补实绩信息
	///     &gt;&gt;strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reInfos；失败返回Null
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET  GetComRepInfos(L3STRING strCondition);

	/// <Method class="CLadle_Mag" name="InsertFinBuildInfos" type="L3LONG">
	/// 
	/// 添加工作层砌筑实绩信息
	///     &gt;&gt;rsInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  InsertFinBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateFinBuildInfos" type="L3LONG">
	/// 
	/// 修改工作层砌筑实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  UpdateFinBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteFinBuildInfos" type="L3LONG">
	/// 
	/// 删除工作层砌筑实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  DeleteFinBuildInfos(L3RECORDSET rsInfos);

	/// <Method class="CLadle_Mag" name="GetFinBuildInfos" type="L3RECORDSET">
	/// 
	/// 获取工作层砌筑实绩信息
	///     &gt;&gt;strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reInfos；失败返回Null
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET  GetFinBuildInfos(L3STRING strCondition);


	/// <Method class="CLadle_Mag" name="InsertChaDreLinInfos" type="L3LONG">
	/// 
	/// 添加工作层换渣线实绩信息
	///     &gt;&gt;rsInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  InsertChaDreLinInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateChaDreLinInfos" type="L3LONG">
	/// 
	/// 修改工作层换渣线实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  UpdateChaDreLinInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteChaDreLinInfos" type="L3LONG">
	/// 
	/// 删除工作层换渣线实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  DeleteChaDreLinInfos(L3RECORDSET rsInfos);

	/// <Method class="CLadle_Mag" name="GetChaDreLinInfos" type="L3RECORDSET">
	/// 
	/// 获取工作层换渣线实绩信息
	///     &gt;&gt;strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reInfos；失败返回Null
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET  GetChaDreLinInfos(L3STRING strCondition);


	/// <Method class="CLadle_Mag" name="InsertFireInfos" type="L3LONG">
	/// 
	/// 添加烘烤实绩信息
	///     &gt;&gt;rsInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  InsertFireInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateFireInfos" type="L3LONG">
	/// 
	/// 修改烘烤实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  UpdateFireInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteFireInfos" type="L3LONG">
	/// 
	/// 删除烘烤实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG  DeleteFireInfos(L3RECORDSET rsInfos);

	/// <Method class="CLadle_Mag" name="GetFireInfos" type="L3RECORDSET">
	/// 
	/// 获取烘烤实绩信息
	///     &gt;&gt;strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reInfos；失败返回Null
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET  GetFireInfos(L3STRING strCondition);


	/// <Method class="CLadle_Mag" name="InsertLadleUseInfos" type="L3LONG">
	/// 添加使用信息
	/// <Param name="rsInfos" type="L3RECORDSET">添加的记录集</Param>
	/// </Method>
	L3LONG InsertLadleUseInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateLadleUseInfos" type="L3LONG">
	/// 修改使用信息
	/// <Param name="rsInfos" type="L3RECORDSET">修改的记录集</Param>
	/// </Method>
	L3LONG UpdateLadleUseInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteLadleUseInfos" type="L3LONG">
	/// 删除使用信息
	/// <Param name="rsInfos" type="L3RECORDSET">删除的记录集</Param>
	/// </Method>
	L3LONG DeleteLadleUseInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetLadleUseInfos" type="L3RECORDSET">
	/// 查询使用信息
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET GetLadleUseInfos(L3STRING strCondition);
	/// <Method class="CLadle_Mag" name="GetUseByLadleID" type="L3RECORDSET">
	/// 根据钢包号获取钢包上次周转使用信息
	/// <Param name="strLadleID" type="L3STRING">钢包号</Param>
	/// </Method>
	L3RECORDSET GetUseByLadleID(L3STRING strLadleID);
	/// <Method class="CLadle_Mag" name="SetLadleInfoTaping" type="L3LONG">
	/// 转炉出钢时设置钢包上件信息以及钢包基本信息
	/// <Param name="dsInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SetLadleInfoTaping(L3RECORDSET dsInfo);

	/// <Method class="CLadle_Mag" name="GetIrrEndTime" type="L3RECORDSET">
	/// 通过钢包号查询此钢包上次停浇时间
	/// <Param name="strLadleID" type="L3STRING">钢包号</Param>
	/// </Method>
	L3RECORDSET GetIrrEndTime(L3STRING strLadleID);
	/// <Method class="CLadle_Mag" name="LadleInnerBuildStart" type="L3LONG">
	/// 钢包永久层砌筑开始
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleInnerBuildStart(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleInnerBuildEnd" type="L3LONG">
	/// 钢包永久层砌筑结束
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleInnerBuildEnd(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleWorkBuildStart" type="L3LONG">
	/// 钢包工作层打结/砌筑开始
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleWorkBuildStart(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleWorkBuildEnd" type="L3LONG">
	/// 钢包工作层打结/砌筑结束
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleWorkBuildEnd(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Fin_Build" name="LadleWorkFireStart" type="L3LONG">
	/// 钢包工作层烘烤开始
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleWorkFireStart(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleWorkFireEnd" type="L3LONG">
	/// 钢包工作层烘烤结束
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleWorkFireEnd(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleHotFireStart" type="L3LONG">
	/// 钢包热备烘烤开始
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleHotFireStart(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleHotFireEnd" type="L3LONG">
	/// 钢包热备烘烤结束
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleHotFireEnd(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="BOFTapingStart" type="L3BOOL">
	/// 补录转炉出钢开始//20081229Liao
	/// <Param name="strUnitID" type="L3STRING">炉座</Param>
	/// <Param name="dtTapTime" type="L3DATETIME">出钢开始时间</Param>
	/// <Param name="strHeatID" type="L3STRING">炉号</Param>
	/// </Method>
	L3BOOL BOFTapingStart(L3STRING strUnitID, L3DATETIME dtTapTime, L3STRING strHeatID);
	/// <Method class="CLadle_Mag" name="UpdateLadlePourInfos" type="L3LONG">
	/// 修改钢包倒包实绩
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateLadlePourInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteLadlePourInfos" type="L3LONG">
	/// 删除钢包倒包实绩
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteLadlePourInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetLadlePourInfos" type="L3RECORDSET">
	/// 获取钢包倒包实绩
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLadlePourInfos(L3STRING strCondition);
	/// <Method class="CLadle_Mag" name="UpdateLadleFoldInfos" type="L3LONG">
	/// 修改钢包折罐实绩
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateLadleFoldInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteLadleFoldInfos" type="L3LONG">
	/// 删除钢包折罐实绩
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteLadleFoldInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetLadleFoldInfos" type="L3RECORDSET">
	/// 获取钢包折罐实绩
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLadleFoldInfos(L3STRING strCondition);
	/// <Method class="CLadle_Mag" name="LadleThrow" type="L3LONG">
	/// 钢包甩包
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleThrow(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="MeasureDesignate" type="L3LONG">
	/// 钢包称重指定
	/// <Param name="strLadleID" type="L3STRING">钢包号</Param>
	/// </Method>
	L3LONG MeasureDesignate(L3STRING strLadleID);
	/// <Method class="CLadle_Mag" name="LadleOffLineException" type="L3LONG">
	/// 钢包异常下线
	/// <Param name="rsLadles" type="L3RECORDSET">下线记录</Param>
	/// </Method>
	L3LONG LadleOffLineException(L3RECORDSET rsLadles);

	/// <Method class="CLadle_Mag" name="LadleInnerFireStart" type="L3LONG">
	/// 钢包永久层烘烤开始
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG	LadleInnerFireStart(L3RECORDSET rsLadles);

	/// <Method class="CLadle_Mag" name="LadleInnerFireEnd" type="L3LONG">
	/// 钢包永久层烘烤结束
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleInnerFireEnd(L3RECORDSET rsLadles);
	};

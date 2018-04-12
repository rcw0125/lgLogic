// 逻辑类CTundish_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_Mag :
	public CL3Object
{
public:
	CTundish_Mag(void);
	virtual ~CTundish_Mag(void);

	DECLARE_L3CLASS(CTundish_Mag,XGMESLogic\\TundishMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CTundish_Mag" name="InsertInfos" type="L3LONG">
	/// 
	/// 添加实绩信息
	/// ARG &gt;&gt;strClassName:类名
	///     &gt;&gt;rsInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// <Param name="strClassName" type="L3STRING">类名</Param>
	/// </Method>
	L3LONG InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	/// <Method class="CTundish_Mag" name="UpdateInfos" type="L3LONG">
	/// 
	/// 修改实绩信息
	/// ARG &gt;&gt;lpcsClass:类名
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// <Param name="lpcsClass" type="LPCTSTR">类名</Param>
	/// </Method>
	L3LONG UpdateInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass); 
	/// <Method class="CTundish_Mag" name="DeleteInfos" type="L3LONG">
	/// 
	/// 删除实绩信息
	/// ARG &gt;&gt;lpcsClass:类名
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// <Param name="lpcsClass" type="LPCTSTR">类名</Param>
	/// </Method>
	L3LONG DeleteInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass);
	/// <Method class="CTundish_Mag" name="GetInfos" type="L3RECORDSET">
	/// 
	/// 获取实绩信息
	/// ARG &gt;&gt;lpcsClass:类名
	///     &gt;&gt;lpcsCondition: 查询条件
	/// RET &lt;&lt; 成功返回reInfos；失败返回Null
	/// <Param name="lpcsClass" type="LPCTSTR">查询条件</Param>
	/// <Param name="lpcsCondition" type="LPCTSTR">类名</Param>
	/// </Method>
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);
	/// <Method class="CTundish_Mag" name="TundishInnerBuildStart" type="L3LONG">
	/// 
	/// 中包永久层打结开始
	/// ARG &gt;&gt; rsTundishs: 要打结开始的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInnerBuildStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishInnerBuildEnd" type="L3LONG">
	/// 
	/// 中包永久层打结结束
	/// ARG &gt;&gt; rsTundishs: 要打结结束的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInnerBuildEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishInnerFireStart" type="L3LONG">
	/// 
	/// 中包永久层烘烤开始
	/// ARG &gt;&gt; rsTundishs: 要烘烤开始的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInnerFireStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishInnerFireEnd" type="L3LONG">
	/// 
	/// 中包永久层烘烤结束
	/// ARG &gt;&gt; rsTundishs: 要烘烤结束的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInnerFireEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishWorkBuildStart" type="L3LONG">
	/// 
	/// 中包工作层涂抹/干振开始
	/// ARG &gt;&gt; rsTundishs: 要涂抹/干振开始的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishWorkBuildStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishWorkBuildEnd" type="L3LONG">
	/// 
	/// 中包工作层涂抹/干振结束
	/// ARG &gt;&gt; rsTundishs: 要中包工作层涂抹/干振的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishWorkBuildEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishWorkFireStart" type="L3LONG">
	/// 
	/// 中包工作层烘烤开始
	/// ARG &gt;&gt; rsTundishs: 要工作层烘烤开始的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishWorkFireStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishWorkFireEnd" type="L3LONG">
	/// 
	/// 中包工作层烘烤结束
	/// ARG &gt;&gt; rsTundishs: 要工作层烘烤结束的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishWorkFireEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishConfirmCold" type="L3LONG">
	/// 确认中包冷备
	/// <Param name="dsTundish" type="L3RECORDSET">中包记录集</Param>
	/// </Method>
	L3LONG TundishConfirmCold(L3RECORDSET dsTundish);
	/// <Method class="CTundish_Mag" name="TundishInstallStart" type="L3LONG">
	/// 中包开始上件
	/// <Param name="dsTundish" type="L3RECORDSET">中包记录集</Param>
	/// </Method>
	L3LONG TundishInstallStart(L3RECORDSET dsTundish);
	/// <Method class="CTundish_Mag" name="TundishInstallEnd" type="L3LONG">
	/// 中包上件结束
	/// <Param name="dsTundish" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInstallEnd(L3RECORDSET dsTundish);
	/// <Method class="CTundish_Mag" name="TundishOnFireStart" type="L3LONG">
	/// 
	/// 中包在线烘烤开始
	/// ARG &gt;&gt; rsTundishs: 要在线烘烤开始的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishOnFireStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishOnFireEnd" type="L3LONG">
	/// 
	/// 中包在线烘烤结束
	/// ARG &gt;&gt; rsTundishs: 要在线烘烤结束的中包的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishOnFireEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="InsertTundishInnerBuildInfo" type="L3LONG">
	/// 
	/// 添加中包永久层砌筑信息
	/// ARG &gt;&gt; rsTundishInnerBuilds: 要添加的中包永久层打结的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInnerBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishInnerBuildInfo(L3RECORDSET rsTundishInnerBuilds);
	/// <Method class="CTundish_Mag" name="UpdateTundishInnerBuildInfo" type="L3LONG">
	/// 
	/// 修改中包永久层砌筑信息
	/// ARG &gt;&gt; rsTundishInnerBuilds: 要修改的中包永久层打结的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInnerBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishInnerBuildInfo(L3RECORDSET rsTundishInnerBuilds);
	/// <Method class="CTundish_Mag" name="DeleteTundishInnerBuildInfo" type="L3LONG">
	/// 
	/// 删除中包永久层砌筑信息
	/// ARG &gt;&gt; rsTundishInnerBuilds: 要删除的中包永久层打结的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInnerBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishInnerBuildInfo(L3RECORDSET rsTundishInnerBuilds);
	/// <Method class="CTundish_Mag" name="GetTundishInnerBuildInfo" type="L3RECORDSET">
	/// 
	/// 获取中包永久层砌筑信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reTundishInnerBuildInfos；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishInnerBuildInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishInnerFireInfo" type="L3LONG">
	/// 
	/// 添加中包永久层烘烤信息
	/// ARG &gt;&gt; rsTundishInnerFires: 要添加的中包永久层烘烤的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInnerFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishInnerFireInfo(L3RECORDSET rsTundishInnerFires);
	/// <Method class="CTundish_Mag" name="UpdateTundishInnerFireInfo" type="L3LONG">
	/// 
	/// 修改中包永久层烘烤信息
	/// ARG &gt;&gt; rsTundishInnerFires: 要修改的中包永久层烘烤的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInnerFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishInnerFireInfo(L3RECORDSET rsTundishInnerFires);
	/// <Method class="CTundish_Mag" name="DeleteTundishInnerFireInfo" type="L3LONG">
	/// 
	/// 删除中包永久层烘烤信息
	/// ARG &gt;&gt; rsTundishInnerFires: 要删除的中包永久层烘烤的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInnerFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishInnerFireInfo(L3RECORDSET rsTundishInnerFires);
	/// <Method class="CTundish_Mag" name="GetTundishInnerFireInfo" type="L3RECORDSET">
	/// 
	/// 获取中包永久层烘烤信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reTundishInnerFireInfos；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishInnerFireInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishWorkBuildInfo" type="L3LONG">
	/// 
	/// 添加中包工作层砌筑信息
	/// ARG &gt;&gt; rsTundishWorkBuilds: 要添加的中包工作层打结的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishWorkBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishWorkBuildInfo(L3RECORDSET rsTundishWorkBuilds);
	/// <Method class="CTundish_Mag" name="UpdateTundishWorkBuildInfo" type="L3LONG">
	/// 
	/// 修改中包工作层砌筑信息
	/// ARG &gt;&gt; rsTundishWorkBuilds: 要修改的中包工作层打结的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishWorkBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishWorkBuildInfo(L3RECORDSET rsTundishWorkBuilds);
	/// <Method class="CTundish_Mag" name="DeleteTundishWorkBuildInfo" type="L3LONG">
	/// 
	/// 删除中包工作层砌筑信息
	/// ARG &gt;&gt; rsTundishWorkBuilds: 要删除的中包工作层打结的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishWorkBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishWorkBuildInfo(L3RECORDSET rsTundishWorkBuilds);
	/// <Method class="CTundish_Mag" name="GetTundishWorkBuildInfo" type="L3RECORDSET">
	/// 
	/// 获取中包工作层砌筑信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsTundishWorkBuilds；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishWorkBuildInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishOTHotFireInfo" type="L3LONG">
	/// 
	/// 添加1、2#铸机中包调整及热备烘烤信息
	/// ARG &gt;&gt; rsTundishHotFires: 要添加的中包烘烤的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishOTHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="UpdateTundishOTHotFireInfo" type="L3LONG">
	/// 
	/// 修改1、2#铸机中包调整及热备烘烤信息
	/// ARG &gt;&gt; rsTundishHotFires: 要修改的中包烘烤的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishOTHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="DeleteTundishOTHotFireInfo" type="L3LONG">
	/// 
	/// 删除1、2#铸机中包调整及热备烘烤信息
	/// ARG &gt;&gt; rsTundishHotFires: 要删除的中包烘烤的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishOTHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="GetTundishOTHotFireInfo" type="L3RECORDSET">
	/// 
	/// 获取1、2#铸机中包调整及热备烘烤信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsTundishOTHotFires；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishOTHotFireInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishTFFHotFireInfo" type="L3LONG">
	/// 
	/// 添加3、4、5#铸机中包热备烘烤信息
	/// ARG &gt;&gt; rsTundishHotFires: 要添加的中包烘烤的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishTFFHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="UpdateTundishTFFHotFireInfo" type="L3LONG">
	/// 
	/// 修改3、4、5#铸机中包热备烘烤信息
	/// ARG &gt;&gt; rsTundishHotFires: 要修改的中包烘烤的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishTFFHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="DeleteTundishTFFHotFireInfo" type="L3LONG">
	/// 
	/// 删除3、4、5#铸机中包热备烘烤信息
	/// ARG &gt;&gt; rsTundishHotFires: 要删除的中包烘烤的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishTFFHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="GetTundishTFFHotFireInfo" type="L3RECORDSET">
	/// 
	/// 获取3、4、5#铸机中包烘烤信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsTundishTFFHotFires；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishTFFHotFireInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishOTInstallInfo" type="L3LONG">
	/// 
	/// 添加1、2#铸机中包上件实绩
	/// ARG &gt;&gt; rsTundishInstalls: 要添加的中包上件的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishOTInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="UpdateTundishOTInstallInfo" type="L3LONG">
	/// 
	/// 修改1、2#铸机中包上件实绩
	/// ARG &gt;&gt; rsTundishInstalls: 要修改的中包上件的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishOTInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="DeleteTundishOTInstallInfo" type="L3LONG">
	/// 
	/// 删除1、2#铸机中包上件实绩
	/// ARG &gt;&gt; rsTundishInstalls: 要删除的中包上件的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishOTInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="GetTundishOTInstallInfo" type="L3RECORDSET">
	/// 
	/// 获取1、2#铸机中包上件实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsTundishOTInstalls；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishOTInstallInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishTFFInstallInfo" type="L3LONG">
	/// 
	/// 添加3、4、5#铸机中包上件实绩
	/// ARG &gt;&gt; rsTundishInstalls: 要添加的中包上件的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishTFFInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="UpdateTundishTFFInstallInfo" type="L3LONG">
	/// 
	/// 修改3、4、5#铸机中包上件实绩
	/// ARG &gt;&gt; rsTundishInstalls: 要修改的中包上件的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishTFFInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="DeleteTundishTFFInstallInfo" type="L3LONG">
	/// 
	/// 删除3、4、5#铸机中包上件实绩
	/// ARG &gt;&gt; rsTundishInstalls: 要删除的中包上件的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishTFFInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="GetTundishTFFInstallInfo" type="L3RECORDSET">
	/// 
	/// 获取3、4、5#铸机中包上件实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsTundishOTInstalls；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishTFFInstallInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishOTRefraUseInfo" type="L3LONG">
	/// 
	/// 添加1、2#铸机中包耐材使用实绩
	/// ARG &gt;&gt; rsTundishRefraUses: 要添加的中包耐材使用的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishOTRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="UpdateTundishOTRefraUseInfo" type="L3LONG">
	/// 
	/// 修改1、2#铸机中包耐材使用实绩
	/// ARG &gt;&gt; rsTundishRefraUses: 要修改的中包耐材使用的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishOTRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="DeleteTundishOTRefraUseInfo" type="L3LONG">
	/// 
	/// 删除1、2#铸机中包耐材使用实绩
	/// ARG &gt;&gt; rsTundishRefraUses: 要删除的中包耐材使用的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishOTRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="GetTundishOTRefraUseInfo" type="L3RECORDSET">
	/// 
	/// 获取1、2#铸机中包耐材使用实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsTundishRefraUses；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishOTRefraUseInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishTTFRefraUseInfo" type="L3LONG">
	/// 
	/// 添加3、4、5#铸机中包耐材使用实绩
	/// ARG &gt;&gt; rsTundishRefraUses: 要添加的中包耐材使用的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishTTFRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="UpdateTundishTTFRefraUseInfo" type="L3LONG">
	/// 
	/// 修改3、4、5#铸机中包耐材使用实绩
	/// ARG &gt;&gt; rsTundishRefraUses: 要修改的中包耐材使用的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishTTFRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="DeleteTundishTTFRefraUseInfo" type="L3LONG">
	/// 
	/// 删除3、4、5#铸机中包耐材使用实绩
	/// ARG &gt;&gt; rsTundishRefraUses: 要删除的中包耐材使用的记录集。必须包含TundishID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishTTFRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="GetTundishTTFRefraUseInfo" type="L3RECORDSET">
	/// 
	/// 获取3、4、5#铸机中包耐材使用实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsTundishRefraUses；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishTTFRefraUseInfo(L3STRING strCondition);
	/// <Property class="CTundish_Mag" name="Tundish_SeqNo" type="L3STRING">
	/// 中包序号
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_SeqNo)

	/// <Method class="CTundish_Mag" name="GetAllHotTundish" type="L3RECORDSET">
	/// 获取中包状态为热备中包(可用中包)
	/// </Method>
	L3RECORDSET GetAllHotTundish();
	/// <Method class="CTundish_Mag" name="SetTundishNO" type="L3LONG">
	/// 设置中包包次号
	/// <Param name="TundishID" type="L3STRING">中包号</Param>
	/// <Param name="TundishNO" type="L3STRING">包次号</Param>
	/// </Method>
	L3LONG SetTundishNO(L3STRING TundishID, L3STRING TundishNO);
	/// <Method class="CTundish_Mag" name="TundishOnLine" type="L3LONG">
	/// 中包上线
	/// <Param name="TundishID" type="L3STRING">中包号</Param>
	/// <Param name="TundishNO" type="L3STRING">包次号</Param>
	/// <Param name="dtOnLine" type="L3DATETIME">中包换上时间</Param>
	/// </Method>
	L3LONG TundishOnLine(L3STRING TundishID, L3STRING TundishNO,L3DATETIME dtOnLine);
	
	/// <Method class="CTundish_Mag" name="TundishOffLine" type="L3LONG">
	/// 中包下线
	/// <Param name="TundishID" type="L3STRING">中包号</Param>
	/// <Param name="TundishNO" type="L3STRING">包次号</Param>
	/// <Param name="dtOffLine" type="L3DATETIME">中包换下时间</Param>
	/// </Method>
	L3LONG TundishOffLine(L3STRING TundishID, L3STRING TundishNO,L3DATETIME dtOffLine);
	/// <Method class="CTundish_Mag" name="GetEnableInnerIDorWorkID" type="L3RECORDSET">
	/// 根据中包号和获取类型获取有中包履历但没有实绩的永久层编号或则工作层编号
	/// <Param name="strTundishID" type="L3STRING">中包号</Param>
	/// <Param name="strType" type="L3STRING">获取类型</Param>
	/// </Method>
	L3RECORDSET GetEnableInnerIDorWorkID(L3STRING strTundishID, L3STRING strType);
	/// <Method class="CTundish_Mag" name="TundishDirectCold" type="L3LONG">
	/// 中包直接冷备
	/// <Param name="dsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishDirectCold(L3RECORDSET dsTundishs);
	/// <Method class="CTundish_Mag" name="TundishDireCCMID" type="L3LONG">
	/// 给状态为热备烘烤和热备的中包指定去向
	/// <Param name="strTundishID" type="L3STRING">中包号</Param>
	/// <Param name="strCCMID" type="L3STRING"></Param>
	/// </Method>
	L3LONG TundishDireCCMID(L3STRING strTundishID, L3STRING strCCMID);
	/// <Method class="CTundish_Mag" name="TundishOffLineException" type="L3LONG">
	/// 中包异常下线[只对状态为"使用"以前的中包]
	/// <Param name="rsTundish" type="L3RECORDSET">异常下线的记录</Param>
	/// </Method>
	L3LONG TundishOffLineException(L3RECORDSET rsTundish);
};

// 逻辑类CMold_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMold_Mag :
	public CL3Object
{
public:
	CMold_Mag(void);
	virtual ~CMold_Mag(void);

	DECLARE_L3CLASS(CMold_Mag,XGMESLogic\\MoldMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	L3LONG UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3LONG DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);


	/// <Method class="CMold_Mag" name="MoldInstallStart" type="L3LONG">
	/// 
	/// 结晶器装配开始
	/// ARG &gt;&gt; rsMolds: 要装配开始的结晶器的记录集。必须包含MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldInstallStart(L3RECORDSET rsMolds);
	/// <Method class="CMold_Mag" name="MoldInstallEnd" type="L3LONG">
	/// 
	/// 结晶器装配结束
	/// ARG &gt;&gt; rsMolds: 要装配结束的结晶器的记录集。必须包含MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldInstallEnd(L3RECORDSET rsMolds);
	/// <Method class="CMold_Mag" name="MoldOnLine" type="L3LONG">
	/// 
	/// 结晶器换上操作
	/// ARG &gt;&gt; rsMolds: 要换上的结晶器的记录集。必须包含MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldOnLine(L3RECORDSET rsMolds);
	/// <Method class="CMold_Mag" name="MoldOffLine" type="L3LONG">
	/// 
	/// 结晶器换下操作
	/// ARG &gt;&gt; rsMolds: 要换下的结晶器的记录集。必须包含MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldOffLine(L3RECORDSET rsMolds);
	/// <Method class="CMold_Mag" name="InsertPipeInstallInfo" type="L3LONG">
	/// 
	/// 添加铜管装配实绩
	/// ARG &gt;&gt; rsPipeInstalls: 要添加的铜管装配的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertPipeInstallInfo(L3RECORDSET rsPipeInstalls);
	/// <Method class="CMold_Mag" name="UpdatePipeInstallInfo" type="L3LONG">
	/// 
	/// 修改铜管装配实绩
	/// ARG &gt;&gt; rsPipeInstalls: 要修改的铜管装配的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdatePipeInstallInfo(L3RECORDSET rsPipeInstalls);
	/// <Method class="CMold_Mag" name="DeletePipeInstallInfo" type="L3LONG">
	/// 
	/// 删除铜管装配实绩
	/// ARG &gt;&gt; rsPipeInstalls: 要删除的铜管装配的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeletePipeInstallInfo(L3RECORDSET rsPipeInstalls);
	/// <Method class="CMold_Mag" name="GetPipeInstallInfo" type="L3RECORDSET">
	/// 
	/// 获取铜管装配实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsPipeInstalls；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetPipeInstallInfo(L3STRING strCondition);
	/// <Method class="CMold_Mag" name="InsertBoardInstallInfo" type="L3LONG">
	/// 
	/// 添加铜板装配实绩
	/// ARG &gt;&gt; rsBoardInstalls: 要添加的铜管装配的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertBoardInstallInfo(L3RECORDSET rsBoardInstalls);
	/// <Method class="CMold_Mag" name="UpdateBoardInstallInfo" type="L3LONG">
	/// 
	/// 修改铜板装配实绩
	/// ARG &gt;&gt; rsBoardInstalls: 要修改的铜管装配的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateBoardInstallInfo(L3RECORDSET rsBoardInstalls);
	/// <Method class="CMold_Mag" name="DeleteBoardInstallInfo" type="L3LONG">
	/// 
	/// 删除铜板装配实绩
	/// ARG &gt;&gt; rsBoardInstalls: 要删除的铜管装配的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteBoardInstallInfo(L3RECORDSET rsBoardInstalls);
	/// <Method class="CMold_Mag" name="GetBoardInstallInfo" type="L3RECORDSET">
	/// 
	/// 获取铜板装配实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsBoardInstalls:；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetBoardInstallInfo(L3STRING strCondition);
	/// <Method class="CMold_Mag" name="InsertPipeUseInfo" type="L3LONG">
	/// 
	/// 添加铜管使用实绩
	/// ARG &gt;&gt; rsPipeUses: 要添加的铜管使用的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertPipeUseInfo(L3RECORDSET rsPipeUses);
	/// <Method class="CMold_Mag" name="UpdatePipeUseInfo" type="L3LONG">
	/// 
	/// 修改铜管使用实绩
	/// ARG &gt;&gt; rsPipeUses: 要修改的铜管使用的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdatePipeUseInfo(L3RECORDSET rsPipeUses);
	/// <Method class="CMold_Mag" name="DeletePipeUseInfo" type="L3LONG">
	/// 
	/// 删除铜管使用实绩
	/// ARG &gt;&gt; rsPipeUses: 要删除的铜管使用的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeletePipeUseInfo(L3RECORDSET rsPipeUses);
	/// <Method class="CMold_Mag" name="GetPipeUseInfo" type="L3RECORDSET">
	/// 
	/// 获取铜管装配实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsPipeUses；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetPipeUseInfo(L3STRING strCondition);
	/// <Method class="CMold_Mag" name="InsertBoardUseInfo" type="L3LONG">
	/// 
	/// 添加铜板使用实绩
	/// ARG &gt;&gt; rsBoardUses: 要添加的铜板使用的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertBoardUseInfo(L3RECORDSET rsBoardUses);
	/// <Method class="CMold_Mag" name="UpdateBoardUseInfo" type="L3LONG">
	/// 
	/// 修改铜板使用实绩
	/// ARG &gt;&gt; rsBoardUses: 要修改的铜板使用的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateBoardUseInfo(L3RECORDSET rsBoardUses);
	/// <Method class="CMold_Mag" name="DeleteBoardUseInfo" type="L3LONG">
	/// 
	/// 删除铜管使用实绩
	/// ARG &gt;&gt; rsBoardUses: 要删除的铜板使用的记录集。必须包含 MoldID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteBoardUseInfo(L3RECORDSET rsBoardUses);
	/// <Method class="CMold_Mag" name="GetBoardUseInfo" type="L3RECORDSET">
	/// 
	/// 获取铜管装配实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsBoardUses；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetBoardUseInfo(L3STRING strCondition);
	/// <Method class="CMold_Mag" name="MoldCheckCold" type="L3LONG">
	/// 结晶器检测完毕判为备用
	/// <Param name="dsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldCheckCold(L3RECORDSET dsMolds);
	/// <Method class="CMold_Mag" name="MoldCheckBuild" type="L3LONG">
	/// 结晶器检测完毕判为待装
	/// <Param name="dsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldCheckBuild(L3RECORDSET dsMolds);//
	/// <Method class="CMold_Mag" name="MoldChangeFlowID" type="L3LONG">
	/// 结晶器检测完毕判为待装
	/// <Param name="strMoldID" type="L3STRING"></Param>
	/// <Param name="strNewFlowID" type="L3STRING"></Param>
	/// </Method>
	L3LONG MoldChangeFlowID(L3STRING strMoldID,L3STRING strNewFlowID);
};

// 逻辑类CIronLadle_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CIronLadle_Mag :
	public CL3Object
{
public:
	CIronLadle_Mag(void);
	virtual ~CIronLadle_Mag(void);

	DECLARE_L3CLASS(CIronLadle_Mag,XGMESLogic\\IronLadleMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CIronLadle_Mag" name="GetInfos" type="L3RECORDSET">
	/// 
	/// 获取实绩信息
	/// ARG &gt;&gt;strClassName:类名
	///     &gt;&gt;strCondition: 查询条件
	/// RET &lt;&lt; 成功返回reInfos；失败返回Null
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// <Param name="strClassName" type="L3STRING">类名</Param>
	/// </Method>
	L3RECORDSET GetInfos(L3STRING strCondition, L3STRING strClassName);
	/// <Method class="CIronLadle_Mag" name="InsertInfos" type="L3LONG">
	/// 
	/// 添加实绩信息
	/// ARG &gt;&gt;strClassName:类名
	///     &gt;&gt;rsInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// <Param name="strClassName" type="L3STRING">类名</Param>
	/// </Method>
	L3LONG InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	/// <Method class="CIronLadle_Mag" name="UpdateInfos" type="L3LONG">
	/// 
	/// 修改实绩信息
	/// ARG &gt;&gt;strClassName:类名
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// <Param name="strClassName" type="L3STRING">类名</Param>
	/// </Method>
	L3LONG UpdateInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	/// <Method class="CIronLadle_Mag" name="DeleteInfos" type="L3LONG">
	/// 
	/// 删除实绩信息
	/// ARG &gt;&gt;strClassName:类名
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// <Param name="strClassName" type="L3STRING">类名</Param>
	/// </Method>
	L3LONG DeleteInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	
	
	/// <Method class="CIronLadle_Mag" name="IronLadleTieStart" type="L3LONG">
	/// 
	/// 铁包打结开始
	/// ARG &gt;&gt;rsIronLadles: 要打结开始的铁包的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
	/// </Method>
	L3LONG IronLadleTieStart(L3RECORDSET rsIronLadles);
	
	/// <Method class="CIronLadle_Mag" name="IronLadleTieEnd" type="L3LONG">
	/// 
	/// 铁包打结结束
	/// ARG &gt;&gt;rsIronLadles: 要打结结束的铁包的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
	/// </Method>
	L3LONG IronLadleTieEnd(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleSmallFireStart" type="L3LONG">
	/// 
	/// 铁包小火开始
	/// ARG &gt;&gt;rsIronLadles: 要小火开始的铁包的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
	/// </Method>
	L3LONG IronLadleSmallFireStart(L3RECORDSET rsIronLadles);
	
	/// <Method class="CIronLadle_Mag" name="IronLadleSmallFireEnd" type="L3LONG">
	/// 
	/// 铁包小火结束
	/// ARG &gt;&gt;rsIronLadles: 要小火结束的铁包的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
	/// </Method>
	L3LONG IronLadleSmallFireEnd(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleMiddleFireStart" type="L3LONG">
	/// 
	/// 铁包中火开始
	/// ARG &gt;&gt;rsIronLadles: 要中火开始的铁包的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
	/// </Method>
	L3LONG IronLadleMiddleFireStart(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleMiddleFireEnd" type="L3LONG">
	/// 
	/// 铁包中火结束
	/// ARG &gt;&gt;rsIronLadles: 要中火结束的铁包的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
	/// </Method>
	L3LONG IronLadleMiddleFireEnd(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleBigFireStart" type="L3LONG">
	/// 
	/// 铁包大火开始
	/// ARG &gt;&gt;rsIronLadles: 要大火开始的铁包的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
	/// </Method>
	L3LONG IronLadleBigFireStart(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleBigFireEnd" type="L3LONG">
	/// 
	/// 铁包大火结束
	/// ARG &gt;&gt;rsIronLadles: 要大火结束的铁包的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">铁包的记录集</Param>
	/// </Method>
	L3LONG IronLadleBigFireEnd(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLaldeStopUse" type="L3LONG">
	/// 铁包下线停用(转为冷备)
	/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG IronLaldeStopUse(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleWaitRepair" type="L3LONG">
	/// 铁包下线待修
	/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG IronLadleWaitRepair(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="InsertTieInfos" type="L3LONG">
	/// 
	/// 添加打结实绩信息
	/// ARG  &gt;&gt;rsTieInfos: 要添加的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTieInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG InsertTieInfos(L3RECORDSET rsTieInfos);
	/// <Method class="CIronLadle_Mag" name="UpdateTieInfos" type="L3LONG">
	/// 
	/// 修改打结实绩信息
	/// ARG &gt;&gt;rsTieInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTieInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG UpdateTieInfos(L3RECORDSET rsTieInfos);
	/// <Method class="CIronLadle_Mag" name="DeleteTieInfos" type="L3LONG">
	/// 
	/// 删除打结实绩信息
	/// ARG &gt;&gt;rsTieInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsTieInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG DeleteTieInfos(L3RECORDSET rsTieInfos);
	/// <Method class="CIronLadle_Mag" name="GetTieInfos" type="L3RECORDSET">
	/// 获取打结实绩信息
	/// ARG &gt;&gt;strCondition
	/// RET &lt;&lt;成功返回记录集rsTieInfos,失败返回NULL
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET GetTieInfos(L3STRING strCondition);
	
	/// <Method class="CIronLadle_Mag" name="InsertFireInfos" type="L3LONG">
	/// 添加烘烤信息
	/// <Param name="dsFireInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertFireInfos(L3RECORDSET dsFireInfos);
	/// <Method class="CIronLadle_Mag" name="UpdateFireInfos" type="L3LONG">
	/// 修改烘烤信息
	/// <Param name="dsFireInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG UpdateFireInfos(L3RECORDSET dsFireInfos);
	/// <Method class="CIronLadle_Mag" name="DeleteFireInfos" type="L3LONG">
	/// 删除烘烤信息
	/// <Param name="dsFireInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG DeleteFireInfos(L3RECORDSET dsFireInfos);
	/// <Method class="CIronLadle_Mag" name="GetFireInfos" type="L3RECORDSET">
	/// 获取烘烤信息
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET GetFireInfos(L3STRING strCondition);

	/// <Method class="CIronLadle_Mag" name="InsertUseInfos" type="L3LONG">
	/// 添加使用信息
	/// <Param name="dsUseInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertUseInfos(L3RECORDSET dsUseInfos);
	/// <Method class="CIronLadle_Mag" name="UpdateUseInfos" type="L3LONG">
	/// 修改使用信息
	/// <Param name="dsUseInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG UpdateUseInfos(L3RECORDSET dsUseInfos);
	/// <Method class="CIronLadle_Mag" name="DeleteUseInfos" type="L3LONG">
	/// 删除使用信息
	/// <Param name="dsUseInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3LONG DeleteUseInfos(L3RECORDSET dsUseInfos);
	/// <Method class="CIronLadle_Mag" name="GetUseInfos" type="L3RECORDSET">
	/// 获取使用信息
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET GetUseInfos(L3STRING strCondition);

	/// <Method class="CIronLadle_Mag" name="GetIronLadle_Age" type="L3LONG">
	/// 获取铁包包龄
	/// <Param name="strIronladleId" type="L3STRING">铁包号</Param>
	/// </Method>
	L3LONG GetIronLadle_Age(L3STRING strIronladleId);
	/// <Method class="CIronLadle_Mag" name="IronLadleUse" type="L3LONG">
	/// 铁包转为使用
	/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG IronLadleUse(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleHot" type="L3LONG">
	/// 转炉兑铁置铁包为热备
	/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG IronLadleHot(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleOffLineException" type="L3LONG">
	/// 铁包异常下线
	/// <Param name="rsIronLadles" type="L3RECORDSET">下线的记录</Param>
	/// </Method>
	L3LONG IronLadleOffLineException(L3RECORDSET rsIronLadles);
};

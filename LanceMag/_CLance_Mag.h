// 逻辑类CLance_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLance_Mag :
	public CL3Object
{
public:
	CLance_Mag(void);
	virtual ~CLance_Mag(void);

	DECLARE_L3CLASS(CLance_Mag,XGMESLogic\\LanceMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();


	L3BOOL UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3BOOL DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);

	/// <Method class="CLance_Mag" name="SetLanceStatus" type="L3BOOL">
	/// 
	/// 设置氧枪包状态
	/// ARG &gt;&gt; rsLances: 要设置状态的氧枪的记录集
	///     &gt;&gt; strStatus: 设置成为的状态。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLances" type="L3RECORDSET"></Param>
	/// <Param name="strStatus" type="L3STRING"></Param>
	/// </Method>
	L3BOOL SetLanceStatus(L3RECORDSET rsLances, L3STRING strStatus);

	/// <Method class="CLance_Mag" name="LanceDefendStrat" type="L3BOOL">
	/// 
	/// 氧枪制作开始
	/// ARG &gt;&gt; rsLances: 要开始维修的氧枪的记录集。必须包含LanceID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLance" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceDefendStrat(L3RECORDSET rsLance);
	/// <Method class="CLance_Mag" name="LanceDefendEnd" type="L3BOOL">
	/// 
	/// 氧枪制作结束
	/// ARG &gt;&gt; rsLances: 要结束维修的氧枪的记录集。必须包含LanceID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLance" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceDefendEnd(L3RECORDSET rsLance);
	/// <Method class="CLance_Mag" name="LanceChangeOn" type="L3BOOL">
	/// 
	/// 人工换上氧枪
	/// ARG &gt;&gt; rsLances: 要换上的氧枪的记录集。必须包含LanceID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLance" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceChangeOn(L3RECORDSET rsLance);
	/// <Method class="CLance_Mag" name="LanceOffLineCheck" type="L3BOOL">
	/// 氧枪下线检查
	/// <Param name="rsLances" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceOffLineCheck(L3RECORDSET rsLances);
	/// <Method class="CLance_Mag" name="LanceFree" type="L3BOOL">
	/// 氧枪下线检查完毕
	/// 判为可再次上线使用
	/// <Param name="rsLances" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceFree(L3RECORDSET rsLances);
	/// <Method class="CLance_Mag" name="LanceChangeOff" type="L3BOOL">
	/// 氧枪离线待修
	/// ARG &gt;&gt; rsLances: 要换下的氧枪的记录集。必须包含LanceID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLance" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceChangeOff(L3RECORDSET rsLance);
	/// <Method class="CLance_Mag" name="InsertLanceDefendInfo" type="L3BOOL">
	/// 
	/// 添加氧枪维护信息
	/// ARG &gt;&gt; rsLanceDefends: 要添加的氧枪的维护的记录集。必须包含LanceID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLanceDefend" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceDefendInfo(L3RECORDSET rsLanceDefend);
	/// <Method class="CLance_Mag" name="UpdateLanceDefendInfo" type="L3BOOL">
	/// 
	/// 修改氧枪维护实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL  UpdateLanceDefendInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceDefendInfo" type="L3BOOL">
	/// 
	/// 删除氧枪维护实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL DeleteLanceDefendInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceDefendInfo" type="L3RECORDSET">
	/// 
	/// 获取氧枪维护信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回记录集；失败返回Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceDefendInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceUseInfo" type="L3BOOL">
	/// 
	/// 添加氧枪使用信息
	/// ARG &gt;&gt; rsLanceUse: 要添加的氧枪的使用的记录集。必须包含LanceID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLanceUse" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceUseInfo(L3RECORDSET rsLanceUse);
	/// <Method class="CLance_Mag" name="UpdateLanceUseInfo" type="L3BOOL">
	/// 
	/// 修改氧枪使用实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL UpdateLanceUseInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceUseInfo" type="L3BOOL">
	/// 
	/// 删除氧枪使用实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL DeleteLanceUseInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceUseInfo" type="L3RECORDSET">
	/// 
	/// 获取氧枪使用信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回记录集；失败返回Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceUseInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceCheckInfo" type="L3BOOL">
	/// 
	/// 添加氧枪检查信息
	/// ARG &gt;&gt; rsLanceCheck: 要添加的氧枪的检查的记录集。必须包含LanceID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsLanceCheck" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceCheckInfo(L3RECORDSET rsLanceCheck);
	/// <Method class="CLance_Mag" name="UpdateLanceCheckInfo" type="L3BOOL">
	/// 
	/// 修改氧枪检查实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL UpdateLanceCheckInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceCheckInfo" type="L3BOOL">
	/// 
	/// 删除氧枪检查实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL  DeleteLanceCheckInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceCheckInfo" type="L3RECORDSET">
	/// 
	/// 获取氧枪检查信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回记录集；失败返回Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceCheckInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceHeadInInfo" type="L3BOOL">
	/// 
	/// 添加氧枪枪头入库信息
	/// ARG &gt;&gt; rsInfos: 要添加的氧枪的枪头入库的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceHeadInInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="UpdateLanceHeadInInfo" type="L3BOOL">
	/// 
	/// 修改枪头入库实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL UpdateLanceHeadInInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceHeadInInfo" type="L3BOOL">
	/// 
	/// 删除枪头入库实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL DeleteLanceHeadInInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceLanceHeadInInfo" type="L3RECORDSET">
	/// 
	/// 获取氧枪枪头入库信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回记录集；失败返回Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceLanceHeadInInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceHeadOutInfo" type="L3BOOL">
	/// 
	/// 添加氧枪枪头出库信息
	/// ARG &gt;&gt; rsLanceHeadOut: 要添加的氧枪的枪头出库的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceHeadOutInfo(L3RECORDSET rsInfos);

	/// <Method class="CLance_Mag" name="UpdateLanceHeadOutInfo" type="L3BOOL">
	/// 
	/// 修改枪头出库实绩信息
	///     &gt;&gt;rsInfos: 要修改的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL UpdateLanceHeadOutInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceHeadOutInfo" type="L3BOOL">
	/// 
	/// 删除枪头出库实绩信息
	///     &gt;&gt;rsInfos: 要删除的实绩的记录集
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInfos" type="L3RECORDSET">实绩数据集</Param>
	/// </Method>
	L3BOOL DeleteLanceHeadOutInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceLanceHeadOutInfo" type="L3RECORDSET">
	/// 
	/// 获取氧枪枪头出库信息
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回记录集；失败返回Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceLanceHeadOutInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceMakeInfo" type="L3BOOL">
	/// 插入氧枪制作信息
	/// <Param name="rsInfos" type="L3RECORDSET">氧枪制作信息</Param>
	/// </Method>
	L3BOOL InsertLanceMakeInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="UpdateLanceMakeInfo" type="L3BOOL">
	/// 修改氧枪制作信息
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateLanceMakeInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceMakeInfo" type="L3BOOL">
	/// 删除氧枪制作信息
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteLanceMakeInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceMakeInfo" type="L3RECORDSET">
	/// 获取氧枪制作信息
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceMakeInfo(L3STRING strCondition);

};

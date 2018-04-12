// 逻辑类CVacTube_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CVacTube_Mag :
	public CL3Object
{
public:
	CVacTube_Mag(void);
	virtual ~CVacTube_Mag(void);

	DECLARE_L3CLASS(CVacTube_Mag,XGMESLogic\\VacTubeMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	L3BOOL UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3BOOL DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);

	/// <Method class="CVacTube_Mag" name="VacTubeOnPosition" type="L3BOOL">
	/// 
	/// 真空管上位
	/// ARG &gt;&gt; rsVacTubes: 要要上位的真空管的记录集。必须包含VacTube_ID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL VacTubeOnPosition(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="VacTubeBuildStart" type="L3BOOL">
	/// 
	/// 真空槽槽管砌筑开始
	/// ARG &gt;&gt; rsVacTubes: 要要砌筑开始的真空管的记录集。必须包含VacTube_ID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL VacTubeBuildStart(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="VacTubeBuildEnd" type="L3BOOL">
	/// 
	/// 真空槽槽管砌筑结束
	/// ARG &gt;&gt; rsVacTubes: 要要砌筑结束的真空管的记录集。必须包含VacTube_ID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL VacTubeBuildEnd(L3RECORDSET rsVacTubes);
	
	/// <Method class="CVacTube_Mag" name="InsertVacTubeBuild" type="L3LONG">
	/// 
	/// 添加真空槽砌筑实绩
	/// ARG &gt;&gt; rsVacTubes: 要添加的真空槽砌筑的记录集。必须包含 VacTube_ID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeBuild(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeBuild" type="L3BOOL">
	/// 
	/// 修改真空槽砌筑实绩
	/// ARG &gt;&gt; rsVacTubes: 要修改的真空槽砌筑的记录集。必须包含 VacTube_ID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeBuild(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeBuild" type="L3LONG">
	/// 
	/// 删除真空槽砌筑实绩
	/// ARG &gt;&gt; rsVacTubes: 要删除的真空槽砌筑的记录集。必须包含 VacTube_ID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteVacTubeBuild(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="GetVacTubeBuild" type="L3RECORDSET">
	/// 
	/// 获取真空槽砌筑实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsVacTubes；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeBuild(L3STRING strCondition);
	
	/// <Method class="CVacTube_Mag" name="InsertHotSypBuild" type="L3LONG">
	/// 
	/// 添加热弯管砌筑实绩
	/// ARG &gt;&gt; rsHotSyps: 要添加的热弯管砌筑的记录集。必须包含 Hot_Syp_ID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsHotSyps" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertHotSypBuild(L3RECORDSET rsHotSyps);
	/// <Method class="CVacTube_Mag" name="UpdateHotSypBuild" type="L3BOOL">
	/// 
	/// 修改热弯管砌筑实绩
	/// ARG &gt;&gt; rsHotSyps: 要修改的热弯管砌筑的记录集。必须包含 Hot_Syp_ID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsHotSyps" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateHotSypBuild(L3RECORDSET rsHotSyps);
	/// <Method class="CVacTube_Mag" name="DeleteHotSypBuild" type="L3LONG">
	/// 
	/// 删除热弯管砌筑实绩
	/// ARG &gt;&gt; rsHotSyps: 要删除的热弯管砌筑的记录集。必须包含 Hot_Syp_ID字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsHotSyps" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteHotSypBuild(L3RECORDSET rsHotSyps);
	/// <Method class="CVacTube_Mag" name="GetHotSypBuild" type="L3RECORDSET">
	/// 
	/// 获取真空槽砌筑实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsHotSyps；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetHotSypBuild(L3STRING strCondition);
	/// <Method class="CVacTube_Mag" name="InsertVacTubeFire" type="L3LONG">
	/// 
	/// 添加真空槽烘烤实绩
	/// ARG &gt;&gt; rsFires: 要添加的真空槽烘烤的记录集。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeFire(L3RECORDSET rsFires);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeFire" type="L3BOOL">
	/// 
	/// 修改真空槽烘烤实绩
	/// ARG &gt;&gt; rsFires: 要修改的真空槽烘烤的记录集。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeFire(L3RECORDSET rsFires);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeFire" type="L3LONG">
	/// 
	/// 删除真空槽烘烤实绩
	/// ARG &gt;&gt; rsFires: 要删除的真空槽烘烤的记录集。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteVacTubeFire(L3RECORDSET rsFires);
	/// <Method class="CVacTube_Mag" name="GetVacTubeFire" type="L3RECORDSET">
	/// 
	/// 获取真空槽烘烤实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsFires；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeFire(L3STRING strCondition);
	/// <Method class="CVacTube_Mag" name="InsertVacTubeUse" type="L3LONG">
	/// 
	/// 添加真空槽使用实绩
	/// ARG &gt;&gt; rsUses: 要添加的真空槽使用的记录集。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeUse(L3RECORDSET rsUses);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeUse" type="L3BOOL">
	/// 
	/// 修改真空槽使用实绩
	/// ARG &gt;&gt; rsUses: 要修改的真空槽使用的记录集。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeUse(L3RECORDSET rsUses);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeUse" type="L3LONG">
	/// 
	/// 删除真空槽使用实绩
	/// ARG &gt;&gt; rsUses: 要删除的真空槽使用的记录集。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteVacTubeUse(L3RECORDSET rsUses);
	/// <Method class="CVacTube_Mag" name="GetVacTubeUse" type="L3RECORDSET">
	/// 
	/// 获取真空槽使用实绩
	/// ARG &gt;&gt; strCondition: 查询条件
	/// RET &lt;&lt; 成功返回rsUses；失败返回null。
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeUse(L3STRING strCondition);
	
	/// <Method class="CVacTube_Mag" name="HotOn" type="L3LONG">
	/// 换上热弯管
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG HotOn(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="HotOff" type="L3LONG">
	/// 换下热弯管
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG HotOff(L3RECORDSET rsVacTubes);
	
	/// <Method class="CVacTube_Mag" name="VactubeOnLine" type="L3LONG">
	/// RH处理开始,真空槽上线使用
	/// <Param name="strPosition" type="L3STRING">处理工位</Param>
	/// </Method>
	L3LONG VactubeOnLine(L3STRING strPosition);
	/// <Method class="CVacTube_Mag" name="VactubeOffLine" type="L3LONG">
	/// RH处理结束,真空槽热备
	/// <Param name="strPosition" type="L3STRING">处理工位</Param>
	/// </Method>
	L3LONG VactubeOffLine(L3STRING strPosition);
	
	/// <Method class="CVacTube_Mag" name="AccepteFireData" type="L3BOOL">
	/// 接收烘烤数据
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AccepteFireData(L3RECORDSET rsData);
	/// <Method class="CVacTube_Mag" name="Vactube_Install" type="L3LONG">
	/// 真空槽组装
	/// <Param name="strUpID" type="L3STRING">上部槽号</Param>
	/// <Param name="strDownID" type="L3STRING">下部槽号</Param>
	/// </Method>
	L3LONG Vactube_Install(L3STRING strUpID, L3STRING strDownID);
	/// <Method class="CVacTube_Mag" name="VacTubeFire" type="L3LONG">
	/// 烘烤位置：2(A预热位)，3(B预热位)，A(A处理位)，B(B处理位)
	/// 烘烤类别：1(烘烤开始)，0(烘烤结束)
	/// <Param name="strPositon" type="L3STRING">烘烤位置</Param>
	/// <Param name="strType" type="L3STRING">烘烤类别</Param>
	/// </Method>
	L3LONG VacTubeFire(L3STRING strPositon, L3STRING strType);
	/// <Method class="CVacTube_Mag" name="VacTubeCheck" type="L3LONG">
	/// 真空槽下线检查
	/// <Param name="strPosition" type="L3STRING"></Param>
	/// </Method>
	L3LONG VacTubeCheck(L3STRING strPosition);
	/// <Method class="CVacTube_Mag" name="VacTubeCheckOver" type="L3LONG">
	/// 真空槽下线检查完毕
	/// 1:备用
	/// 2:小修
	/// 3:重新砌筑
	/// <Param name="strVacTubeCode" type="L3STRING">真空槽编号</Param>
	/// <Param name="strType" type="L3STRING">操作类型</Param>
	/// </Method>
	L3LONG VacTubeCheckOver(L3STRING strVacTubeCode, L3STRING strType);
	/// <Method class="CVacTube_Mag" name="InsertVacTubeRepair" type="L3LONG">
	/// 添加真空槽修补信息
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeRepair" type="L3BOOL">
	/// 修改真空槽修补信息
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeRepair" type="L3BOOL">
	/// 删除真空槽修补信息
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteVacTubeRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="GetVacTubeRepair" type="L3RECORDSET">
	/// 获取真空槽修补信息
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeRepair(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="InsertHotSypRepair" type="L3LONG">
	/// 添加热弯管修补信息
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertHotSypRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="UpdateHotSypRepair" type="L3BOOL">
	/// 修改热弯管修补信息
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateHotSypRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="DeleteHotSypRepair" type="L3BOOL">
	/// 删除热弯管修补信息
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteHotSypRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="GetHotSypRepair" type="L3RECORDSET">
	/// 获取热弯管修补信息
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetHotSypRepair(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="InsertVacTubeFireInfo" type="L3LONG">
	/// 添加烘烤详细信息
	/// <Param name="rsFireInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeFireInfo(L3RECORDSET rsFireInfo);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeFireInfo" type="L3BOOL">
	/// 修改烘烤详细信息
	/// <Param name="rsFireInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeFireInfo(L3RECORDSET rsFireInfo);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeFireInfo" type="L3BOOL">
	/// 删除烘烤详细信息
	/// <Param name="rsFireInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteVacTubeFireInfo(L3RECORDSET rsFireInfo);
	/// <Method class="CVacTube_Mag" name="GetVacTubeFireInfo" type="L3RECORDSET">
	/// 获取烘烤详细信息
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeFireInfo(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="InsertVacTubeUseInfo" type="L3LONG">
	/// 添加真空槽使用详细信息
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeUseInfo" type="L3BOOL">
	/// 修改真空槽使用详细信息
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeUseInfo" type="L3BOOL">
	/// 删除真空槽使用详细信息
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteVacTubeUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="GetVacTubeUseInfo" type="L3RECORDSET">
	/// 获取真空槽使用详细信息
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeUseInfo(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="InsertHotSypUseInfo" type="L3LONG">
	/// 添加热弯管使用信息
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertHotSypUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="UpdateHotSypUseInfo" type="L3BOOL">
	/// 修改热弯管使用信息
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateHotSypUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="DeleteHotSypUseInfo" type="L3BOOL">
	/// 删除热弯管使用信息
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteHotSypUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="GetHotSypUseInfo" type="L3RECORDSET">
	/// 获取热弯管使用信息
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetHotSypUseInfo(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="LastVacTubeAesSoaTotalLenOfHeatID" type="L3LONG">
	/// 获取该炉次的最后上升管累计时长
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// </Method>
	L3LONG LastVacTubeAesSoaTotalLenOfHeatID(L3STRING strHeatID);
};

// 逻辑类CScrap_Store_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialStore.h"

class CScrap_Store_Mag :
	public MaterialStore
{
public:
	CScrap_Store_Mag(void);
	virtual ~CScrap_Store_Mag(void);

	DECLARE_L3CLASS(CScrap_Store_Mag,XGMESLogic\\ScrapStoreMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CScrap_Store_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

protected:

	virtual double GetAmountTolerance() { return 0.02; };//2009-03-27

	/// <summary>
	/// 返回入库缓冲区的URI
	/// </summary>
	virtual CString GetInputCache();
	/// <summary>
	/// 返回出库缓冲区的URI
	/// </summary>
	virtual CString GetOutputCache();
	/// <summary>
	/// 返回入库记录类型名称
	/// </summary>
	virtual CString GetInputLogType();
	/// <summary>
	/// 返回出库记录类型名称
	/// </summary>
	virtual CString GetOutputLogType();
	/// <summary>
	/// 返回库位类型名称
	/// </summary>
	virtual CString GetStoreAreaType();

	/// <summary>
	///	初始化库房的属性
	/// </summary>
	virtual BOOL InitializeStoreProperties();
	/// <summary>
	/// 填充库位的初始化数据
	/// </summary>
	virtual BOOL GetInitialAreaData(CL3RecordSetWrap& rs);
	/// <summary>
	/// 在库房初始完成后调用。继承类重载此函数进行额外的初始化工作。
	/// </summary>
	virtual void OnAfterStoreInitialized();

	/// <summary>
	/// 入库前预处理。在入库操作前调用。继承类可重载此方法进行预先的数据准备和处理
	/// ARG >> rsInputInfo : 入库信息记录。
	/// RET << TRUE 继续入库；FALSE 中断入库
	/// </summary>
	virtual BOOL OnBeforeInputMaterials(L3RECORDSET rsInputInfo);
	/// <summary>
	/// 入库后续处理。在入库操作成功后调用。继承类可重载此方法进行额外的处理。
	/// ARG >> rsInputInfo : 入库信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE；
	/// </summary>
	virtual BOOL OnAfterMaterialsInputted(L3RECORDSET rsInputInfo);
	/// <summary>
	/// 出库前预处理。在出库操作前调用。继承类可重载此方法进行预先的数据准备和处理
	/// ARG >> rsOutputInfo : 出库信息记录。
	/// RET << TRUE 继续出库；FALSE 中断出库
	/// </summary>
	virtual BOOL OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo);
	/// <summary>
	/// 出库后续处理。在出库操作成功后调用。继承类可重载此方法进行额外的处理。
	/// ARG >> rsOutputInfo : 出库信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE；
	/// </summary>
	virtual BOOL OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo);
	/// <summary>
	/// 人工增加库存前预处理。在进行人工增加库存前调用。继承类可重载此方发进行预先数据准备和处理
	/// ARG	>> rsMaterialInfo : 新增材料信息记录。
	/// RET << 返回TRUE继续处理；返回FALSE中断。
	/// </summary>
	virtual BOOL OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo);
	/// <summary>
	/// 人工增加库存后续处理。在进行人工增加库存后调用。继承类可重载此方法进行额外处理。
	/// ARG >> rsMaterialInfo : 新增的材料信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo);
	/// <summary>
	/// 人工删除库存前预处理。在进行人工删除库存前调用。继承类可重载此方发进行预先数据准备和处理
	/// ARG	>> rsMaterialInfo : 删除材料信息记录。
	/// RET << 返回TRUE继续处理；返回FALSE中断。
	/// </summary>
	virtual BOOL OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo);
	/// <summary>
	/// 人工删除库存后续处理。在进行人工删除库存后调用。继承类可重载此方法进行额外处理。
	/// ARG >> rsMaterialInfo : 删除的材料信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo);


	//tangyi 2007-12-09
	/// <summary>
	/// 移库前导处理。
	/// ARG >> rsMaterialInfo : 删除的材料信息记录。
	/// RET << 返回TRUE继续处理；返回FALSE中断。
	/// </summary>
	virtual BOOL OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 移库后续处理。
	/// ARG >> rsMaterialInfo : 删除的材料信息记录。
	/// RET << << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 入库记录预处理。继承类可重载此方法在入库前检查或处理入库记录
	/// </summary>
	virtual void PrepareInputLog(L3RECORDSET rsInputLog);
	/// <summary>
	/// 出库记录预处理。继承类可重载此方法在出库前检查或处理出库记录
	/// </summary>
	virtual void PrepareOutputLog(L3RECORDSET rsOutputLog);

	/// <summary>
	/// 返回指定编号的库位对象的URI
	/// </summary>
	virtual CString GetAreaURI(LPCTSTR lpcszAreaID);

	/// <Method class="CScrap_Store_Mag" name="ScrapDataAccept" type="L3BOOL">
	/// 
	/// 接收NC废钢数据,加入input缓存,与材料表,接收电文表
	/// ARG&gt;&gt; rsScrapData:废钢生铁信息.
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ScrapDataAccept(L3RECORDSET rsScrapData);
	/// <Method class="CScrap_Store_Mag" name="ScrapInStore" type="L3VOID">
	/// 
	/// 废钢入库
	/// ARG&gt;&gt; rsInputInfo废钢生铁信息.必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL ScrapInStore(L3RECORDSET rsInputInfo);
	/// <Method class="CScrap_Store_Mag" name="ScrapOutStore" type="L3VOID">
	/// 
	/// 废钢出库
	/// ARG&gt;&gt; rsOutputInfo废钢生铁信息.必须包含MaterialType, MaterialID, Amount, StoreAreaID,Scrap_Slot_ID,Car_ID,Car_Type,Net_Weight,Gross_Weight,Tare_Weight这几个字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsOutputInfo" type="L3RECORDSET">出库信息记录。包含MaterialType,MaterialID,Amount,AreaID等字段。</Param>
	/// </Method>
	L3BOOL ScrapOutStore(L3RECORDSET rsOutputInfo);
	/// <Method class="CScrap_Store_Mag" name="GetMaterialOnInputCache" type="L3CORDSET">
	/// 
	/// 获取入库缓存材料
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetMaterialOnInputCache();

	/// <Method class="CAlloy_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
	/// 
	/// 获取库区材料信息
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetMaterialOnStore(L3STRING strStoreID);


	/// <Method class="CAlloy_Store_Mag" name="AlloyModifyAmount" type="L3BOOL">
	/// 
	/// 库区材料量调整
	/// ARG&gt;&gt; rsData:合金信息.必须包含MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag 这几个字段
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyMaterialAmount(L3RECORDSET rsData);

	/// <Method class="CScrap_Store_Mag" name="ScrapCancelOutStore" type="L3VOID">
	/// 
	/// 废钢撤销出库2009-02-26
	/// ARG&gt;&gt; rsOutputInfo废钢生铁信息.必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL ScrapCancelOutStore(L3RECORDSET rsOutputInfo);

	/// <Method class="CBOF_Unit_Mag" name="GetScrapesForDesignate" type="L3RECORDSET">
	/// 获取可选废钢信息记录。返回带有废钢槽号和废钢量的记录集。
	/// </Method>
	L3RECORDSET GetScrapes();

	/// <Method class="CScrap_Store_Mag" name="ScrapDataAccept" type="L3BOOL">
	/// 
	/// 接收NC废钢数据,加入input缓存,与材料表,接收电文表
	/// ARG&gt;&gt; rsScrapData:废钢生铁信息.
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ScrapDataAcceptFromNC(L3RECORDSET rsScrapData);

	/// <Method class="CScrap_Store_Mag" name="SaveScrapOutDetail" type="L3LONG">
	/// <Param name="rsScrap" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SaveScrapOutDetail(L3RECORDSET rsScrap);
};

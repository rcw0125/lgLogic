// 逻辑类CBloom_Store_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MaterialStore.h"


class CBloom_Store_Mag :
	public MaterialStore
{
public:
	CBloom_Store_Mag(void);
	virtual ~CBloom_Store_Mag(void);

	DECLARE_L3CLASS(CBloom_Store_Mag,XGMESLogic\\BloomStoreMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Store_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();


	/// <Property class="CBloom_Store_Mag" name="BloomOffLineEvent" type="L3LONG">
	/// 钢坯下线
	/// </Property>
	DECLARE_L3PROP_LONG(BloomOffLineEvent);

	/// <Property class="CBloom_Store_Mag" name="BloomInStore" type="L3LONG">
	/// 钢坯入库NC接口预约属性
	/// </Property>
	DECLARE_L3PROP_LONG(BloomInStore);

protected:

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

	/// <Method class="CBloom_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
	/// 
	/// 获取入库缓存材料
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;返回数据集
	/// </Method>
	L3RECORDSET GetMaterialOnInputCache();
	/// <Method class="CBloom_Store_Mag" name="ChangeBloomPosition" type="L3BOOL">
	/// 
	/// 垛位变更
	/// ARG&gt;&gt; rsBloom：钢坯数据，包括新的垛位信息
	/// RET &lt;&lt;成功返回True，失败返回False
	/// <Param name="rsBloom" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ChangeBloomPosition(L3RECORDSET rsBloom);
	/// <Method class="CBloom_Store_Mag" name="BloomColdSendInStore" type="L3BOOL">
	/// 
	/// 将一批材料入库。
	/// ARG &gt;&gt; rsInputInfo : 材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE；
	/// <Param name="rsInputInfo" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
	/// </Method>
	L3LONG BloomColdSendInStore(L3RECORDSET rsInputInfo);
	/// <Method class="CBloom_Store_Mag" name="BloomHotSend" type="L3LONG">
	/// 
	/// 方坯热送
	/// ARG&gt;&gt; rsInputInfo : 材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。
	/// RET &lt;&lt;成功返回1，失败返回出错代码
	/// <Param name="rsInputInfo" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
	/// </Method>
	L3LONG BloomHotSend(L3RECORDSET rsInputInfo);
	/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
	/// 
	/// 接收钢坯冷送出库信息
	/// ARG&gt;&gt; rsData : 材料出库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。
	/// RET &lt;&lt;成功返回1，失败返回出错代码
	/// <Param name="rsData" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
	/// </Method>
	L3LONG AcceptBloomOutStoreInfor(L3RECORDSET rsData);
	/// <Method class="CBloom_Store_Mag" name="GetBloomOnStoreArea" type="L3RECORDSET">
	/// 
	/// 获取库区钢坯
	/// ARG&gt;&gt; strArea:库区。
	/// RET &lt;&lt;返回数据集
	/// <Param name="strArea" type="L3STRING">库区代码</Param>
	/// </Method>
	L3RECORDSET GetBloomOnStoreArea(L3STRING strArea,L3STRING strHeatID);
	/// <Method class="CBloom_Store_Mag" name="BloomFinish" type="L3BOOL">
	/// 
	/// 钢坯精整质量抽检
	/// ARG &gt;&gt; rsHeatID: 钢坯炉号。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE；
	/// <Param name="rsHeat" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL BloomFinish(L3RECORDSET rsHeat);
	/// <Method class="CBloom_Store_Mag" name="GetWillFinishBloom" type="L3VOID">
	/// 
	/// 获取可以质量抽检钢坯
	/// ARG&gt;&gt; strArea:库区。
	/// RET &lt;&lt;返回数据集
	/// <Param name="strArea" type="L3STRING">库区代码</Param>
	/// </Method>
	L3RECORDSET GetWillFinishBloom(L3STRING strArea,L3STRING strHeatID);


	/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
	/// 
	/// 接收钢坯冷送出库信息2009-03-08
	/// ARG&gt;&gt; rsData : 材料出库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID,Target这几个字段。
	/// RET &lt;&lt;成功返回1，失败返回出错代码
	/// <Param name="rsData" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
	/// </Method>
	L3LONG AcceptBloomOutStoreInforFromNC (L3RECORDSET rsData);

	
	L3LONG CCMConfirmHeat(L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
	/// 
	/// 钢坯逆送2009-04-02
	/// <Param name="rsData" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
	/// </Method>
	L3LONG BloomBack (L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
	/// 
	/// 接收钢线材钢坯逆送信息2009-04-02
	/// <Param name="rsData" type="L3RECORDSET">材料入库信息记录集。必须包含MaterialType, MaterialID, Amount, StoreAreaID这几个字段。</Param>
	/// </Method>
	L3LONG AcceptBloomBackInforFromNC (L3RECORDSET rsData);

};

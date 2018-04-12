// 逻辑类CStoreOperateLog头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CStoreOperateLog :
	public CL3Object
{
public:
	CStoreOperateLog(void);
	virtual ~CStoreOperateLog(void);

	DECLARE_L3CLASS(CStoreOperateLog,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CStoreOperateLog)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CStoreOperateLog" name="StoreID" type="L3STRING">
	///料仓ID
	/// </Property>
	DECLARE_L3PROP_STRING(StoreID)

	/// <Property class="CStoreOperateLog" name="BeforeMaterialID" type="L3STRING">
	///操作前物料编码
	/// </Property>
	DECLARE_L3PROP_STRING(BeforeMaterialID)

	/// <Property class="CStoreOperateLog" name="BeforMaterialName" type="L3STRING">
	///操作前物料名称
	/// </Property>
	DECLARE_L3PROP_STRING(BeforMaterialName)

	/// <Property class="CStoreOperateLog" name="OperateMode" type="L3STRING">
	///操作模式 0：入库 1：出库 2：盘库 3：料仓清零 4：料种维护
	/// </Property>
	DECLARE_L3PROP_STRING(OperateMode)

	/// <Property class="CStoreOperateLog" name="Operater" type="L3STRING">
	///操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Operater)

	/// <Property class="CStoreOperateLog" name="OperatorTime" type="L3STRING">
	///操作时间
	/// </Property>
	DECLARE_L3PROP_STRING(OperatorTime)

	/// <Property class="CStoreOperateLog" name="AfterMaterialID" type="L3STRING">
	///操作后物料编码
	/// </Property>
	DECLARE_L3PROP_STRING(AfterMaterialID)

	/// <Property class="CStoreOperateLog" name="AfterMaterialName" type="L3STRING">
	///操作后物料名称
	/// </Property>
	DECLARE_L3PROP_STRING(AfterMaterialName)

	/// <Property class="CStoreOperateLog" name="BeforeWeight" type="L3STRING">
	///操作前重量
	/// </Property>
	DECLARE_L3PROP_STRING(BeforeWeight)

	/// <Property class="CStoreOperateLog" name="AfterWeight" type="L3STRING">
	///操作后重量
	/// </Property>
	DECLARE_L3PROP_STRING(AfterWeight)

};

// 逻辑类CCCM_ProdArea头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_ProdArea :
	public CL3Object
{
public:
	CCCM_ProdArea(void);
	virtual ~CCCM_ProdArea(void);

	DECLARE_L3CLASS(CCCM_ProdArea,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_ProdArea)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Method class="CCCM_ProdArea" name="ProcessMaterials" type="L3BOOL">
	/// 
	/// 材料加工逻辑处理。继承类需要重载此函数进行其特定的材料加工处理。
	/// 注意：在此方法中不要对加工相关的数据进行直接修改！调用它的主函数会做处理！
	/// ARG &gt;&gt; rsMaterials : 加工使用的原料信息。包括MaterialType,MaterialID,Amount字段。
	/// &gt;&gt; rsParameter : 加工使用的参数记录集。
	/// &lt;&lt; pnProcessType : 成功后返回加工类型。
	/// &lt;&lt; prsProducts : 成功后返回产品数据记录。
	/// &lt;&lt; prsMaterialMap : 如果加工类型是CreateNew，成功后返回原料成品对照表。否则无用。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// <Param name="rsMaterials" type="L3RECORDSET"></Param>
	/// <Param name="rsParameter" type="L3RECORDSET"></Param>
	/// <Param name="pnProcessType" type="L3LONG*"></Param>
	/// <Param name="prsMaterialMap" type="L3RECORDSET*"></Param>
	/// <Param name="prsProducts" type="L3RECORDSET*"></Param>
	/// </Method>
	L3BOOL ProcessMaterials(L3RECORDSET rsMaterials, L3RECORDSET rsParameter, L3LONG* pnProcessType, L3RECORDSET* prsMaterialMap, L3RECORDSET* prsProducts);
};

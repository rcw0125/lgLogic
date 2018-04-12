// 逻辑类CCCM_ProdArea的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CCCM_ProdArea.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CCCM_ProdArea.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CCCM_ProdArea.h"

//当对象被装载到系统中时，被调用
void CCCM_ProdArea::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CCCM_ProdArea::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


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
L3BOOL CCCM_ProdArea::ProcessMaterials(L3RECORDSET rsMaterials, L3RECORDSET rsParameter, L3LONG* pnProcessType, L3RECORDSET* prsMaterialMap, L3RECORDSET* prsProducts)
{
	return 0;
}

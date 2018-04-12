// 逻辑类CDeS_Prod_Area的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CDeS_Prod_Area.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CDeS_Prod_Area.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CDeS_Prod_Area.h"

#define PROCTIME_PERIOD		5000
#define BLOWTIME_PERIOD     5

//当对象被装载到系统中时，被调用
void CDeS_Prod_Area::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CDeS_Prod_Area::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <summary>
/// 加工前预处理。在进行加工逻辑处理前调用，继承类可重载此函数进行数据预处理。
/// ARG >> rsParameter : 加工参数记录集。
/// RET << 返回TRUE继续加工；返回FALSE中断加工。
/// </summary>
BOOL CDeS_Prod_Area::OnBeforeProcess(L3RECORDSET rsParameter)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnBeforeProcess( rsParameter);
}

/// <summary>
/// 材料加工逻辑处理。继承类需要重载此函数进行其特定的材料加工处理。
/// 注意：在此方法中不要对加工相关的数据进行直接修改！调用它的主函数会做处理！
/// ARG >> rsMaterials : 加工使用的原料信息。包括MaterialType,MaterialID,Amount字段。
///		>> rsParameter : 加工使用的参数记录集。
///		<< pnProcessType : 成功后返回加工类型。
///		<< prsProducts : 成功后返回产品数据记录。
///		<< prsMaterialMap : 如果加工类型是CreateNew，成功后返回原料成品对照表。否则无用。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDeS_Prod_Area::ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::ProcessMaterials( rsMaterials, rsParameter, pnProcessType, prsProducts, prsMaterialMap);
}

/// <summary>
/// 加工后续处理。在加工逻辑处理完成后调用，继承类可重载此函数进行额外处理。
/// ARG >> rsMaterials : 加工使用的原料信息。包括MaterialType,MaterialID,Amount字段。
///		>> rsParameter : 加工使用的参数记录集。
///		>> pnProcessType : 加工类型。
///		>> rsProducts : 产品数据记录。
///		>> rsMaterialMap : 如果加工类型是CreateNew，为原料成品对照表。否则无用。
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CDeS_Prod_Area::OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::OnAfterProcessed( rsMaterials, rsParameter, nProcessType, rsProducts, rsMaterialMap);
}

/// <Method class="CDeS_Prod_Area" name="OnTimer" type="L3BOOL">
/// 处理定时器事件
/// <Param name="nEventID" type="L3ULONG">定时器事件ID</Param>
/// </Method>
L3BOOL CDeS_Prod_Area::OnTimer(L3ULONG nEventID)
{
	if(nEventID == m_iTimer)
	{	
		BlowTime += BLOWTIME_PERIOD;
	}

	return TRUE;
}

/// <Method class="CDeS_Prod_Area" name="SetDeSAreaTimer" type="L3BOOL">
/// 启动定时器事件
/// </Method>
L3BOOL CDeS_Prod_Area::SetDeSAreaTimer()
{
	BlowTime = 0;
	m_iTimer = SetTimer(GetURI(),PROCTIME_PERIOD);

	return TRUE;
}

/// <Method class="CDeS_Prod_Area" name="KillDeSAreaTimer" type="L3BOOL">
/// 停止定时器事件
/// </Method>
L3BOOL CDeS_Prod_Area::KillDeSAreaTimer()
{
	if(m_iTimer != 0)
		KillTimer(GetURI(),m_iTimer);
	m_iTimer = 0;

	return TRUE;
}

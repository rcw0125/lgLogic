// 逻辑类CAOD_Prod_Area头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProduceArea.h"

class CAOD_Prod_Area :
	public ProduceArea
{
public:
	CAOD_Prod_Area(void);
	virtual ~CAOD_Prod_Area(void);

	DECLARE_L3CLASS(CAOD_Prod_Area,XGMESLogic\\AODMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Prod_Area)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

protected:
	UINT m_iTimer;

	/// <summary>
	/// 生成位置编码的虚函数。继承类可以重载此函数进行自己的位置编码定义。
	/// ARG >> void
	/// RET << 位置编码
	/// </summary>
	virtual CString GetPositionCode();

	/// <summary>
	/// 加工前预处理。在进行加工逻辑处理前调用，继承类可重载此函数进行数据预处理。
	/// ARG >> rsParameter : 加工参数记录集。
	/// RET << 返回TRUE继续加工；返回FALSE中断加工。
	/// </summary>
	virtual BOOL OnBeforeProcess(L3RECORDSET rsParameter);

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
	virtual BOOL ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap);

	/// <summary>
	/// 加工后续处理。在加工逻辑处理完成后调用，继承类可重载此函数进行额外处理。
	/// ARG >> rsMaterials : 加工使用的原料信息。包括MaterialType,MaterialID,Amount字段。
	///		>> rsParameter : 加工使用的参数记录集。
	///		>> pnProcessType : 加工类型。
	///		>> rsProducts : 产品数据记录。
	///		>> rsMaterialMap : 如果加工类型是CreateNew，为原料成品对照表。否则无用。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap);

	/// <summary>
	/// 材料添加前导处理
	/// </summary>
	virtual BOOL OnBeforeAddMaterials(L3RECORDSET rsMaterials);
	/// <summary>
	/// 材料添加后续处理
	/// </summary>
	virtual BOOL OnAfterMaterialsAdded(L3RECORDSET rsMaterials);
	/// <summary>
	/// 材料移出后续处理
	/// </summary>
	virtual BOOL OnAfterMaterialsRemoved(L3RECORDSET rsMaterials);

	/// <Property class="CAOD_Unit_Mag" name="Status" type="L3LONG">
	/// 工位状态
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CAOD_Prod_Area" name="NextSteel" type="L3STRING">
	/// 下一个要到达的钢水号
	/// </Property>
	DECLARE_L3PROP_STRING(NextSteel)

	/// <Property class="CAOD_Prod_Area" name="TreatNo" type="L3STRING">
	/// 当前处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CAOD_Prod_Area" name="HeatID" type="L3STRING">
	/// 当前炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Prod_Area" name="LadleID" type="L3STRING">
	/// 当前钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CAOD_Prod_Area" name="SteelGradeIndex" type="L3STRING">
	/// 当前炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CAOD_Prod_Area" name="Weight" type="L3DOUBLE">
	/// 当前重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CAOD_Prod_Area" name="Arrive_Time" type="L3DATETIME">
	/// 到达时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Time)

	/// <Property class="CAOD_Prod_Area" name="SoftBlowTime" type="L3LONG">
	///// 软吹计时
	///// </Property>
	//DECLARE_L3PROP_LONG(SoftBlowTime)

	///// <Property class="CAOD_Prod_Area" name="WiredFlag" type="L3LONG">
	///// 钙处理标志
	///// </Property>
	//DECLARE_L3PROP_LONG(WiredFlag)

	/// <Method class="CAOD_Prod_Area" name="OnTimer" type="L3BOOL">
	/// 处理定时器事件
	/// <Param name="nEventID" type="L3ULONG">定时器事件ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG nEventID);

	/// <Method class="CAOD_Prod_Area" name="SetLFAreaTimer" type="L3BOOL">
	/// 启动定时器事件
	/// </Method>
	L3BOOL SetLFAreaTimer();

	/// <Method class="CAOD_Prod_Area" name="KillLFAreaTimer" type="L3BOOL">
	/// 停止定时器事件
	/// </Method>
	L3BOOL KillLFAreaTimer();
};

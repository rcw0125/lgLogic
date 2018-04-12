// 逻辑类CPlan_Order头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProducePlan.h"

class CPlan_Order :
	public ProducePlan
{
public:
	CPlan_Order(void);
	virtual ~CPlan_Order(void);

	DECLARE_L3CLASS(CPlan_Order,XGMESLogic\\PlanMag, PlanID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Order)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CPlan_Order" name="Length" type="L3LONG">
	/// 长度
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CPlan_Order" name="Width" type="L3LONG">
	/// 宽度
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CPlan_Order" name="Thickness" type="L3LONG">
	/// 厚度
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CPlan_Order" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CPlan_Order" name="MaterialCode" type="L3STRING">
	/// 物料编码
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialCode)

	/// <Property class="CPlan_Order" name="Unit" type="L3STRING">
	/// 计量单位
	/// </Property>
	DECLARE_L3PROP_STRING(Unit)

	/// <Property class="CPlan_Order" name="Assist_Unit" type="L3STRING">
	/// 辅计量单位
	/// </Property>
	DECLARE_L3PROP_STRING(Assist_Unit)

	/// <Property class="CPlan_Order" name="Weight" type="L3DOUBLE">
	/// 计划数量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CPlan_Order" name="ActWeight" type="L3DOUBLE">
	/// 实际投放量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ActWeight)

	/// <Property class="CPlan_Order" name="SpareWeight" type="L3DOUBLE">
	/// 剩余量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SpareWeight)

	/// <Property class="CPlan_Order" name="Assisi_Weight" type="L3DOUBLE">
	/// 计划辅数量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Assisi_Weight)

	/// <Property class="CPlan_Order" name="PlanRec_Date" type="L3DATETIME">
	/// 计划下单日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(PlanRec_Date)

	/// <Property class="CPlan_Order" name="Request_Date" type="L3DATETIME">
	/// 需求日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Request_Date)

	/// <Property class="CPlan_Order" name="Corp" type="L3STRING">
	/// 公司
	/// </Property>
	DECLARE_L3PROP_STRING(Corp)

	/// <Property class="CPlan_Order" name="Factory" type="L3STRING">
	/// 工厂
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CPlan_Order" name="Work_Center" type="L3STRING">
	/// 工作中心
	/// </Property>
	DECLARE_L3PROP_STRING(Work_Center)

	/// <Property class="CPlan_Order" name="Client" type="L3STRING">
	/// 客户
	/// </Property>
	DECLARE_L3PROP_STRING(Client)

	/// <Property class="CPlan_Order" name="Tech_Request" type="L3STRING">
	/// 技术要求zyx2
	/// </Property>
	DECLARE_L3PROP_STRING(Tech_Request)

	/// <Property class="CPlan_Order" name="Inside_Note" type="L3STRING">
	/// 生产部说明zdy4
	/// </Property>
	DECLARE_L3PROP_STRING(Inside_Note)

	/// <Property class="CPlan_Order" name="Imm_Flag" type="L3STRING">
	/// 是否加急
	/// </Property>
	DECLARE_L3PROP_STRING(Imm_Flag)

	/// <Property class="CPlan_Order" name="CasterID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CPlan_Order" name="New_BOF_Flag" type="L3SHORT">
	/// 80t转炉标志
	/// </Property>
	DECLARE_L3PROP_SHORT(New_BOF_Flag)

	/// <Property class="CPlan_Order" name="Protocol" type="L3STRING">
	/// 协议
	/// </Property>
	DECLARE_L3PROP_STRING(Protocol)

	/// <Property class="CPlan_Order" name="ProduceStd" type="L3STRING">
	/// 产品标准zyx1
	/// </Property>
	DECLARE_L3PROP_STRING(ProduceStd)


	/// <Property class="CPlan_Order" name="pk_poid" type="L3STRING">
	/// 计划订单主键
	/// </Property>
	DECLARE_L3PROP_STRING(pk_poid)


	/// <Property class="CPlan_Order" name="MaterialCode_ID" type="L3STRING">
	/// 物料编码ID
	/// </Property>2009-03-11
	DECLARE_L3PROP_STRING(MaterialCode_ID)

	/// <Property class="CPlan_Order" name="MaterialCode_ID" type="L3STRING">
	/// 工艺路径zdy3
	/// </Property>2009-03-11
	DECLARE_L3PROP_STRING(Product_Route)

	/// <Property class="CPlan_Order" name="Other_Tech_Request" type="L3STRING">
	/// 其他技术要求zdy2
	/// </Property>
	DECLARE_L3PROP_STRING(Other_Tech_Request)

};

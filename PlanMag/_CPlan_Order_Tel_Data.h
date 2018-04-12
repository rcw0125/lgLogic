// 逻辑类CPlan_Order_Tel_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CPlan_Order_Tel_Data :
	public CL3Object
{
public:
	CPlan_Order_Tel_Data(void);
	virtual ~CPlan_Order_Tel_Data(void);

	DECLARE_L3CLASS(CPlan_Order_Tel_Data,XGMESLogic\\PlanMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Order_Tel_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CPlan_Order_Tel_Data" name="Jhddh" type="L3STRING">
	/// 计划订单号
	/// </Property>
	DECLARE_L3PROP_STRING(jhddh)

	/// <Property class="CPlan_Order_Tel_Data" name="Xsddh" type="L3STRING">
	/// 销售订单号
	/// </Property>
	DECLARE_L3PROP_STRING(xsddh)

	/// <Property class="CPlan_Order_Tel_Data" name="pk_invbasdoc" type="L3STRING">
	/// 产品
	/// </Property>
	DECLARE_L3PROP_STRING(wlbmid)

	/// <Property class="CPlan_Order_Tel_Data" name="pk_produce" type="L3STRING">
	/// 产品生产档案主键
	/// </Property>
	DECLARE_L3PROP_STRING(pk_produce)

	/// <Property class="CPlan_Order_Tel_Data" name="Invcode" type="L3STRING">
	/// 物料编码
	/// </Property>
	DECLARE_L3PROP_STRING(wlbm)

	/// <Property class="CPlan_Order_Tel_Data" name="Invname" type="L3STRING">
	/// 物料名称
	/// </Property>
	DECLARE_L3PROP_STRING(wlmc)

	/// <Property class="CPlan_Order_Tel_Data" name="Invspec" type="L3STRING">
	/// 物料规格
	/// </Property>
	DECLARE_L3PROP_STRING(invspec)

	/// <Property class="CPlan_Order_Tel_Data" name="Invtype" type="L3STRING">
	/// 物料型号
	/// </Property>
	DECLARE_L3PROP_STRING(invtype)

	/// <Property class="CPlan_Order_Tel_Data" name="Scbmid" type="L3STRING">
	/// 生产部门
	/// </Property>
	DECLARE_L3PROP_STRING(scbmid)

	/// <Property class="CPlan_Order_Tel_Data" name="Scbmbm" type="L3STRING">
	/// 生产部门编码
	/// </Property>
	DECLARE_L3PROP_STRING(scbmbm)

	/// <Property class="CPlan_Order_Tel_Data" name="Gzzxid" type="L3STRING">
	/// 工作中心
	/// </Property>
	DECLARE_L3PROP_STRING(gzzxid)

	/// <Property class="CPlan_Order_Tel_Data" name="Gzzxbm" type="L3STRING">
	/// 工作中心编码
	/// </Property>
	DECLARE_L3PROP_STRING(gzzxbm)

	/// <Property class="CPlan_Order_Tel_Data" name="Ztshow" type="L3STRING">
	/// 订单状态
	/// </Property>
	DECLARE_L3PROP_STRING(ztshow)

	/// <Property class="CPlan_Order_Tel_Data" name="Ddlx" type="L3STRING">
	/// 订单类型
	/// </Property>
	DECLARE_L3PROP_STRING(ddlx)

	/// <Property class="CPlan_Order_Tel_Data" name="Ksid" type="L3STRING">
	/// 客户
	/// </Property>
	DECLARE_L3PROP_STRING(ksid)

	/// <Property class="CPlan_Order_Tel_Data" name="Sfjj" type="L3STRING">
	/// 是否加急
	/// </Property>
	DECLARE_L3PROP_STRING(Sfjj)

	/// <Property class="CPlan_Order_Tel_Data" name="Jldwid" type="L3STRING">
	/// 计量单位
	/// </Property>
	DECLARE_L3PROP_STRING(jldwid)

	/// <Property class="CPlan_Order_Tel_Data" name="Jldwmc" type="L3STRING">
	/// 计量单位名称
	/// </Property>
	DECLARE_L3PROP_STRING(jldwmc)

	/// <Property class="CPlan_Order_Tel_Data" name="Fjlid" type="L3STRING">
	/// 辅计量单位
	/// </Property>
	DECLARE_L3PROP_STRING(fjldwid)

	/// <Property class="CPlan_Order_Tel_Data" name="Jhwgsl" type="L3DOUBLE">
	/// 计划数量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(xqsl)

	/// <Property class="CPlan_Order_Tel_Data" name="Jhxxsl" type="L3DOUBLE">
	/// 计划下限数量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(jhxxsl)

	/// <Property class="CPlan_Order_Tel_Data" name="Fjhsl" type="L3LONG">
	/// 需求辅数量
	/// </Property>
	DECLARE_L3PROP_LONG(xqfsl)

	/// <Property class="CPlan_Order_Tel_Data" name="Jhksrq" type="L3DATETIME">
	/// 计划开始日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(jhrq)

	/// <Property class="CPlan_Order_Tel_Data" name="Xdrq" type="L3DATETIME">
	/// 下单日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(xdrq)

	/// <Property class="CPlan_Order_Tel_Data" name="Xqrq" type="L3DATETIME">
	/// 需求日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(xqrq)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy1" type="L3STRING">
	/// 自定义1
	/// </Property>
	DECLARE_L3PROP_STRING(zdy1)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy2" type="L3STRING">
	/// 自定义2
	/// </Property>
	DECLARE_L3PROP_STRING(zdy2)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy3" type="L3STRING">
	/// 自定义3
	/// </Property>
	DECLARE_L3PROP_STRING(zdy3)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy4" type="L3STRING">
	/// 自定义4
	/// </Property>
	DECLARE_L3PROP_STRING(zdy4)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy5" type="L3STRING">
	/// 自定义5
	/// </Property>
	DECLARE_L3PROP_STRING(zdy5)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx1" type="L3STRING">
	/// 自由项1
	/// </Property>
	DECLARE_L3PROP_STRING(zyx1)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx2" type="L3STRING">
	/// 自由项2
	/// </Property>
	DECLARE_L3PROP_STRING(zyx2)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx3" type="L3STRING">
	/// 自由项3
	/// </Property>
	DECLARE_L3PROP_STRING(zyx3)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx4" type="L3STRING">
	/// 自由项4
	/// </Property>
	DECLARE_L3PROP_STRING(zyx4)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx5" type="L3STRING">
	/// 自由项5
	/// </Property>
	DECLARE_L3PROP_STRING(zyx5)

	/// <Property class="CPlan_Order_Tel_Data" name="pk_corp" type="L3STRING">
	/// 公司
	/// </Property>
	DECLARE_L3PROP_STRING(pk_corp)

	/// <Property class="CPlan_Order_Tel_Data" name="Gcbm" type="L3STRING">
	/// 工厂
	/// </Property>
	DECLARE_L3PROP_STRING(gcbm)

	/// <Property class="CPlan_Order_Tel_Data" name="pk_poid" type="L3STRING">
	/// 计划订单主键
	/// </Property>
	DECLARE_L3PROP_STRING(pk_poid)

	/// <Property class="CPlan_Order_Tel_Data" name="PlanRec_Date" type="L3DATETIME">
	/// 计划订单接收日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(PlanRec_Date)

};

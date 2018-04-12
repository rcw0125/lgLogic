// 逻辑类CBase_NC_Steel_Material头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBase_Steel_Mat_Tel_Data :
	public CL3Object
{
public:
	CBase_Steel_Mat_Tel_Data(void);
	virtual ~CBase_Steel_Mat_Tel_Data(void);

	DECLARE_L3CLASS(CBase_Steel_Mat_Tel_Data,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Steel_Mat_Tel_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="Rec_Time" type="L3DATETIME">
	/// 接收日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Rec_Time)
	
	/// <Property class="CBase_Steel_Mat_Tel_Data" name="vbillcode" type="L3STRING">
	/// 入库单号
	/// </Property>
	DECLARE_L3PROP_STRING(vbillcode)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="cinventoryid" type="L3STRING">
	/// 物料ID
	/// </Property>
	DECLARE_L3PROP_STRING(cinventoryid)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="cbaseid" type="L3STRING">
	/// 物料编码主键
	/// </Property>
	DECLARE_L3PROP_STRING(cbaseid)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="Invcode" type="L3STRING">
	/// 物料编码
	/// </Property>
	DECLARE_L3PROP_STRING(Invcode)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="Invname" type="L3STRING">
	/// 物料名称
	/// </Property>
	DECLARE_L3PROP_STRING(Invname)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="Invspec" type="L3STRING">
	/// 物料规格
	/// </Property>
	DECLARE_L3PROP_STRING(Invspec)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="Invtype" type="L3STRING">
	/// 物料型号
	/// </Property>
	DECLARE_L3PROP_STRING(Invtype)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="Dbilldate" type="L3DATETIME">
	/// 单据日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(dbizdate)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="coutwarehouseid" type="L3STRING">
	/// 出库仓库
	/// </Property>
	DECLARE_L3PROP_STRING(cotherwhid)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="cinwarehouseid" type="L3STRING">
	/// 入库仓库
	/// </Property>
	DECLARE_L3PROP_STRING(cwarehouseid)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="nnum" type="L3DOUBLE">
	/// 转库数量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ninnum)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="nassistnum" type="L3LONG">
	/// 转库辅数量
	/// </Property>
	DECLARE_L3PROP_LONG(ninassistnum)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="vbatchcode" type="L3STRING">
	/// 合金批次
	/// </Property>
	DECLARE_L3PROP_STRING(vbatchcode)


	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zdy1" type="L3STRING">
	/// 自定义1
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef1)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zdy2" type="L3STRING">
	/// 自定义2
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef2)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zdy3" type="L3STRING">
	/// 自定义3
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef3)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zdy4" type="L3STRING">
	/// 自定义4
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef4)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zdy5" type="L3STRING">
	/// 自定义5
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef5)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zyx1" type="L3STRING">
	/// 自由项1
	/// </Property>
	DECLARE_L3PROP_STRING(vfree1)

	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zyx2" type="L3STRING">
	/// 自由项2
	/// </Property>
	DECLARE_L3PROP_STRING(vfree2)


	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zyx3" type="L3STRING">
	/// 自由项3
	/// </Property>
	DECLARE_L3PROP_STRING(vfree3)


	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zyx4" type="L3STRING">
	/// 自由项4
	/// </Property>
	DECLARE_L3PROP_STRING(vfree4)


	/// <Property class="CBase_Steel_Mat_Tel_Data" name="zyx5" type="L3STRING">
	/// 自由项5
	/// </Property>
	DECLARE_L3PROP_STRING(vfree5)


	/// <Property class="CBase_Steel_Mat_Tel_Data" name="pk_corp" type="L3STRING">
	/// 公司
	/// </Property>
	DECLARE_L3PROP_STRING(pk_corp)


};

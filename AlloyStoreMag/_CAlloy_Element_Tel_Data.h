// 逻辑类CAlloy_Element_Tel_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAlloy_Element_Tel_Data :
	public CL3Object
{
public:
	CAlloy_Element_Tel_Data(void);
	virtual ~CAlloy_Element_Tel_Data(void);

	DECLARE_L3CLASS(CAlloy_Element_Tel_Data,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Element_Tel_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Element_Tel_Data" name="Rec_Time" type="L3STRING">
	/// 接收时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Rec_Time)

	/// <Property class="CAlloy_Element_Tel_Data" name="vproductbatchcode" type="L3STRING">
	/// 合金批次
	/// </Property>
	DECLARE_L3PROP_STRING(vstobatchcode)

	/// <Property class="CAlloy_Element_Tel_Data" name="vcheckbillcode" type="L3STRING">
	/// 检验单号
	/// </Property>
	DECLARE_L3PROP_STRING(vcheckbillcode)

	/// <Property class="CAlloy_Element_Tel_Data" name="bcompcheck" type="L3STRING">
	/// 是否成分检验
	/// </Property>
	DECLARE_L3PROP_STRING(bcompcheck)

	/// <Property class="CAlloy_Element_Tel_Data" name="nassistchecknum" type="L3LONG">
	/// 报检辅数量
	/// </Property>
	DECLARE_L3PROP_LONG(ninassistnum)

	/// <Property class="CAlloy_Element_Tel_Data" name="cstoreorganization" type="L3STRING">
	/// 库存组织
	/// </Property>
	DECLARE_L3PROP_STRING(cstoreorganization)

	/// <Property class="CAlloy_Element_Tel_Data" name="cpraycorp" type="L3STRING">
	/// 报检公司
	/// </Property>
	DECLARE_L3PROP_STRING(cpraycorp)

	/// <Property class="CAlloy_Element_Tel_Data" name="ccheckbillid" type="L3STRING">
	/// 质量检验单主键
	/// </Property>
	DECLARE_L3PROP_STRING(ccheckbillid)

	/// <Property class="CAlloy_Element_Tel_Data" name="cbaseid" type="L3STRING">
	/// 检验产品
	/// </Property>
	DECLARE_L3PROP_STRING(cbaseid)

	/// <Property class="CAlloy_Element_Tel_Data" name="vsamplecode" type="L3STRING">
	/// 样本号
	/// </Property>
	DECLARE_L3PROP_STRING(vsamplecode)

	/// <Property class="CAlloy_Element_Tel_Data" name="nnum" type="L3STRING">
	/// 检验数量
	/// </Property>
	DECLARE_L3PROP_STRING(ninnum)

	/// <Property class="CAlloy_Element_Tel_Data" name="ccheckitemid" type="L3STRING">
	/// 检验成分
	/// </Property>
	DECLARE_L3PROP_STRING(ccheckitemid)

	/// <Property class="CAlloy_Element_Tel_Data" name="cresult" type="L3DOUBLE">
	/// 检验数值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(cresult)
	
};

// 逻辑类CIron_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "Material.h"

class CIron_Data :
	public Material
{
public:
	CIron_Data(void);
	virtual ~CIron_Data(void);

	DECLARE_L3CLASS(CIron_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIron_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:

	enum _IronSource
	{
		DirectMixed = 0,	// 直兑
		FromMix1 = 1,		// 1号混铁炉出铁
		FromMix2 = 2,		// 2号混铁炉出铁
		FromMix3 = 3		// 3号混铁炉出铁
	};

	/// <Property class="CIron_Data" name="Weight" type="L3DOUBLE">
	/// 铁水重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CIron_Data" name="C" type="L3FLOAT">
	/// 碳成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(C)

	/// <Property class="CIron_Data" name="Si" type="L3FLOAT">
	/// 硅成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Si)

	/// <Property class="CIron_Data" name="Mn" type="L3FLOAT">
	/// 锰成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Mn)

	/// <Property class="CIron_Data" name="P" type="L3FLOAT">
	/// 磷成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(P)

	/// <Property class="CIron_Data" name="S" type="L3FLOAT">
	/// 硫成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(S)

	//modify by hyh 2012-04-10
	/// <Property class="CIron_Data" name="Ti" type="L3FLOAT">
	/// 钛成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Ti)

	/// <Property class="CIron_Data" name="Sn" type="L3FLOAT">
	/// add by hyh 20120331
	/// </Property>
	DECLARE_L3PROP_FLOAT(Sn)

	/// <Property class="CIron_Data" name="Sb" type="L3FLOAT">
	/// add by hyh 20120331
	/// </Property>
	DECLARE_L3PROP_FLOAT(Sb)

	/// <Property class="CIron_Data" name="As" type="L3FLOAT">
	/// add by hyh 20120331
	/// </Property>
	DECLARE_L3PROP_FLOAT(As)

	/// <Property class="CIron_Data" name="Pb" type="L3FLOAT">
	/// add by hyh 20120331
	/// </Property>
	DECLARE_L3PROP_FLOAT(Pb)
	//end

	//add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	/// <Property class="CIron_Data" name="Ni" type="L3FLOAT">
	/// 镍成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Ni)

	/// <Property class="CIron_Data" name="Mo" type="L3FLOAT">
	/// 钼成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Mo)

	/// <Property class="CIron_Data" name="Cu" type="L3FLOAT">
	/// 铜成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Cu)

	/// <Property class="CIron_Data" name="Cr" type="L3FLOAT">
	/// 铬成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Cr)

	/// <Property class="CIron_Data" name="B" type="L3FLOAT">
	/// 硼成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(B)

	/// <Property class="CIron_Data" name="V" type="L3FLOAT">
	/// 钒成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(V)

	/// <Property class="CIron_Data" name="Al" type="L3FLOAT">
	/// 铝成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Al)

	/// <Property class="CIron_Data" name="Nb" type="L3FLOAT">
	/// 铌成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Nb)

	/// <Property class="CIron_Data" name="Zn" type="L3FLOAT">
	/// 锌成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Zn)

	/// <Property class="CIron_Data" name="W type="L3FLOAT">
	/// 钨成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(W)
	//end

	/// <Property class="CIron_Data" name="IronTemp" type="L3LONG">
	/// 铁水温度
	/// </Property>
	DECLARE_L3PROP_LONG(IronTemp)

	/// <Property class="CIron_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CIron_Data" name="Source" type="L3SHORT">
	/// 
	/// 出铁方式(0:直兑;
	///          1:1#混铁炉出铁;
	///          2:2#混铁炉出铁)
	/// </Property>
	DECLARE_L3PROP_SHORT(Source)

	/// <Property class="CIron_Data" name="Shift" type="L3SHORT">
	///班次
	/// </Property>
	DECLARE_L3PROP_SHORT(Shift)

	/// <Property class="CIron_Data" name="Team" type="L3SHORT">
	///班别
	/// </Property>
	DECLARE_L3PROP_SHORT(Team)

	/// <Property class="CIron_Data" name="Operator" type="L3STRING">
	///操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CIron_Data" name="Tare" type="L3DOUBLE">
	/// 皮重
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tare)

	/// <Property class="CIron_Data" name="Gross_Weight" type="L3DOUBLE">
	/// 毛重
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gross_Weight)

	/// <Property class="CIron_Data" name="Tap_Time" type="L3DATETIME">
	/// 出铁时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tap_Time)

	/// <Property class="CIron_Data" name="IronLadleNo" type="L3STRING">
	/// 铁包号
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadleNo)

	/// <Property class="CIron_Data" name="Object1" type="L3STRING">
	/// 组罐主键1
	/// </Property>
	DECLARE_L3PROP_STRING(Object1)

	/// <Property class="CIron_Data" name="Weight1" type="L3DOUBLE">
	///组罐重量1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight1)

	/// <Property class="CIron_Data" name="Object2" type="L3STRING">
	/// 组罐主键2
	/// </Property>
	DECLARE_L3PROP_STRING(Object2)

	/// <Property class="CIron_Data" name="Weight2" type="L3DOUBLE">
	///组罐重量2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight2)

	/// <Property class="CIron_Data" name="Object3" type="L3STRING">
	/// 组罐主键3
	/// </Property>
	DECLARE_L3PROP_STRING(Object3)

	/// <Property class="CIron_Data" name="Weight3" type="L3DOUBLE">
	///组罐重量3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight3)

	/// <Property class="CIron_Data" name="Return_Steel_Weight" type="L3FLOAT">
	/// 
	/// 回炉钢量
	/// 
	/// </Property>
	DECLARE_L3PROP_FLOAT(Return_Steel_Weight)

	//Modify begin by llj 2011-04-06 增加是否脱硫分类
	
	
	/// <Property class="CIron_Data" name="IsDes" type="L3FLOAT">
	/// 
	/// 是否脱硫 0:脱硫 -1：非脱硫
	/// 
	/// </Property>
	DECLARE_L3PROP_FLOAT(IsDes)
	//modify end
};

// 逻辑类CBOF_Feed_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_Feed_Data :
	public CL3Object
{
public:
	CBOF_Feed_Data(void);
	virtual ~CBOF_Feed_Data(void);

	DECLARE_L3CLASS(CBOF_Feed_Data,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Feed_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_Feed_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_Feed_Data" name="IronWeight" type="L3FLOAT">
	/// 铁水量
	/// </Property>
	DECLARE_L3PROP_FLOAT(IronWeight)

	/// <Property class="CBOF_Feed_Data" name="ScrapWeight" type="L3FLOAT">
	/// 废钢量
	/// </Property>
	DECLARE_L3PROP_FLOAT(ScrapWeight)

	/// <Property class="CBOF_Feed_Data" name="PigIronWeight" type="L3FLOAT">
	/// 
	/// 生铁块量
	/// 
	/// </Property>
	DECLARE_L3PROP_FLOAT(PigIronWeight)

	/// <Property class="CBOF_Feed_Data" name="Return_Steel_Weight" type="L3FLOAT">
	/// 
	/// 回炉钢量
	/// 
	/// </Property>
	DECLARE_L3PROP_FLOAT(Return_Steel_Weight)

	/// <Property class="CBOF_Feed_Data" name="C" type="L3FLOAT">
	/// 碳成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(C)

	/// <Property class="CBOF_Feed_Data" name="Si" type="L3FLOAT">
	/// 硅成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Si)

	/// <Property class="CBOF_Feed_Data" name="Mn" type="L3FLOAT">
	/// 锰成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Mn)

	/// <Property class="CBOF_Feed_Data" name="P" type="L3FLOAT">
	/// 磷成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(P)

	/// <Property class="CBOF_Feed_Data" name="S" type="L3FLOAT">
	/// 硫成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(S)

	/// <Property class="CBOF_Feed_Data" name="Ti" type="L3FLOAT">
	/// 钛成分值
	/// </Property>
	DECLARE_L3PROP_FLOAT(Ti)

	//add by hyh 2012-04-05
	/// <Property class="CBOF_Feed_Data" name="Sn" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(Sn)

	/// <Property class="CBOF_Feed_Data" name="Sb" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(Sb)

	/// <Property class="CBOF_Feed_Data" name="As" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(As)

	/// <Property class="CBOF_Feed_Data" name="Pb" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(Pb)

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

	/// <Property class="CBOF_Feed_Data" name="IronTemp" type="L3LONG">
	/// 铁水温度
	/// </Property>
	DECLARE_L3PROP_LONG(IronTemp)

	/// <Property class="CBOF_Feed_Data" name="LogTime" type="L3DATETIME">
	/// 指定主原料时间2009-03-03
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CBOF_Feed_Data" name="Return_SteelGrade" type="L3STRING">
	/// 回炉钢钢种2009-03-03
	/// </Property>
	DECLARE_L3PROP_STRING(Return_SteelGrade)


};

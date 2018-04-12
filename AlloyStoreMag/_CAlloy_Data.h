// 逻辑类CAlloy_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "Material.h"

class CAlloy_Data :
	public Material
{
public:
	CAlloy_Data(void);
	virtual ~CAlloy_Data(void);

	DECLARE_L3CLASS(CAlloy_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Data" name="C" type="L3DOUBLE">
	/// C
	/// </Property>
	DECLARE_L3PROP_DOUBLE(C)

	/// <Property class="CAlloy_Data" name="Si" type="L3DOUBLE">
	/// Si
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si)

	/// <Property class="CAlloy_Data" name="Mn" type="L3DOUBLE">
	/// Mn
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mn)

	/// <Property class="CAlloy_Data" name="P" type="L3DOUBLE">
	/// P
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P)

	/// <Property class="CAlloy_Data" name="S" type="L3DOUBLE">
	/// S
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CAlloy_Data" name="Cu" type="L3DOUBLE">
	/// Cu
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cu)

	/// <Property class="CAlloy_Data" name="Ni" type="L3DOUBLE">
	/// Ni
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ni)

	/// <Property class="CAlloy_Data" name="Cr" type="L3DOUBLE">
	/// Cr
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cr)

	/// <Property class="CAlloy_Data" name="Mo" type="L3DOUBLE">
	/// Mo
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mo)

	/// <Property class="CAlloy_Data" name="V" type="L3DOUBLE">
	/// V
	/// </Property>
	DECLARE_L3PROP_DOUBLE(V)

	/// <Property class="CAlloy_Data" name="Nb" type="L3DOUBLE">
	/// Nb
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nb)

	/// <Property class="CAlloy_Data" name="Al" type="L3DOUBLE">
	/// Al
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al)

	/// <Property class="CAlloy_Data" name="AlS" type="L3DOUBLE">
	/// AlS
	/// </Property>
	DECLARE_L3PROP_STRING(AlS)

	/// <Property class="CAlloy_Data" name="Ti" type="L3DOUBLE">
	/// Ti
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ti)

	/// <Property class="CAlloy_Data" name="B" type="L3DOUBLE">
	/// B
	/// </Property>
	DECLARE_L3PROP_DOUBLE(B)

	/// <Property class="CAlloy_Data" name="Sb" type="L3DOUBLE">
	/// Sb
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sb)

	/// <Property class="CAlloy_Data" name="As" type="L3DOUBLE">
	/// As
	/// </Property>
	DECLARE_L3PROP_DOUBLE(As)

	/// <Property class="CAlloy_Data" name="Sn" type="L3DOUBLE">
	/// Sn
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sn)

	/// <Property class="CAlloy_Data" name="Zn" type="L3DOUBLE">
	/// Zn
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Zn)

	/// <Property class="CAlloy_Data" name="Ca" type="L3DOUBLE">
	/// Ca
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ca)

	/// <Property class="CAlloy_Data" name="W" type="L3DOUBLE">
	/// W
	/// </Property>
	DECLARE_L3PROP_DOUBLE(W)

	/// <Property class="CAlloy_Data" name="Pb" type="L3DOUBLE">
	/// Pb
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pb)

	/// <Property class="CAlloy_Data" name="Re" type="L3DOUBLE">
	/// Re
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Re)

	/// <Property class="CAlloy_Data" name="Ceq" type="L3DOUBLE">
	/// Ceq
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ceq)

	/// <Property class="CAlloy_Data" name="N" type="L3DOUBLE">
	/// N
	/// </Property>
	DECLARE_L3PROP_DOUBLE(N)

	/// <Property class="CAlloy_Data" name="H" type="L3DOUBLE">
	/// H
	/// </Property>
	DECLARE_L3PROP_DOUBLE(H)

	/// <Property class="CAlloy_Data" name="O" type="L3DOUBLE">
	/// O
	/// </Property>
	DECLARE_L3PROP_DOUBLE(O)

	/// <Property class="CAlloy_Data" name="Other1" type="L3DOUBLE">
	/// 其他1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Other1)

	/// <Property class="CAlloy_Data" name="Other2" type="L3DOUBLE">
	/// 其他2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Other2)

	/// <Property class="CAlloy_Data" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CAlloy_Data" name="Alloy_Code" type="L3STRING">
	/// 合金编码
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_Data" name="UnitID" type="L3STRING">
	/// 工序
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CAlloy_Data" name="Amount" type="L3DOUBLE">
	/// 材料量。
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	//2009-03-17 
	DECLARE_L3PROP_DOUBLE(CrNi)
	DECLARE_L3PROP_DOUBLE(CrCu)
	DECLARE_L3PROP_DOUBLE(CrNiCu)

	///2009-05-27 添加渣样成分
	/// <Property class="CAlloy_Data" name="TFe" type="L3STRING">
	/// TFe
	/// </Property>
	DECLARE_L3PROP_STRING(TFe)

	/// <Property class="CAlloy_Data" name="FeO" type="L3STRING">
	/// FeO
	/// </Property>
	DECLARE_L3PROP_STRING(FeO)

	/// <Property class="CAlloy_Data" name="SiO2" type="L3STRING">
	/// SiO2
	/// </Property>
	DECLARE_L3PROP_STRING(SiO2)

	/// <Property class="CAlloy_Data" name="TCa" type="L3STRING">
	/// TCa
	/// </Property>
	DECLARE_L3PROP_STRING(TCa)

	/// <Property class="CAlloy_Data" name="CaO" type="L3STRING">
	/// CaO
	/// </Property>
	DECLARE_L3PROP_STRING(CaO)

	/// <Property class="CAlloy_Data" name="MgO" type="L3STRING">
	/// MgO
	/// </Property>
	DECLARE_L3PROP_STRING(MgO)

	/// <Property class="CAlloy_Data" name="Al2O3" type="L3STRING">
	/// Al203
	/// </Property>
	DECLARE_L3PROP_STRING(Al2O3)

	/// <Property class="CQA_Lab_SlagEle" name="MnO" type="L3STRING">
	/// MnO
	/// </Property>
	DECLARE_L3PROP_STRING(MnO)

	/// <Property class="CAlloy_Data" name="TiO2" type="L3STRING">
	/// TiO2
	/// </Property>
	DECLARE_L3PROP_STRING(TiO2)

	/// <Property class="CAlloy_Data" name="P2O5" type="L3STRING">
	/// P2O5
	/// </Property>
	DECLARE_L3PROP_STRING(P2O5)

	/// <Property class="CAlloy_Data" name="R" type="L3STRING">
	/// R
	/// </Property>
	DECLARE_L3PROP_STRING(R)

	///2009-06-02 添加渣样成分

	/// <Property class="CAlloy_Data" name="AD" type="L3STRING">
	/// AD
	/// </Property>
	DECLARE_L3PROP_STRING(AD)


	/// <Property class="CAlloy_Data" name="Ni_Co" type="L3STRING">
	/// Ni+Co
	/// </Property>
	DECLARE_L3PROP_STRING(Ni_Co)

	/// <Property class="CAlloy_Data" name="H2O" type="L3STRING">
	/// H2O水分
	/// </Property>
	DECLARE_L3PROP_STRING(H2O)

	/// <Property class="CAlloy_Data" name="SSL" type="L3STRING">
	/// SSL烧失量
	/// </Property>
	DECLARE_L3PROP_STRING(SSL)

	/// <Property class="CAlloy_Data" name="FE2O3" type="L3STRING">
	/// FE2O3
	/// </Property>
	DECLARE_L3PROP_STRING(FE2O3)

	/// <Property class="CAlloy_Data" name="G_C" type="L3STRING">
	/// G_C固定碳
	/// </Property>
	DECLARE_L3PROP_STRING(G_C)

	/// <Property class="CAlloy_Data" name="RD" type="L3STRING">
	/// RD
	/// </Property>
	DECLARE_L3PROP_STRING(RD)

	/// <Property class="CAlloy_Data" name="Ba" type="L3STRING">
	/// Ba
	/// </Property>
	DECLARE_L3PROP_STRING(Ba)


	/// <Property class="CAlloy_Data" name="HFF" type="L3STRING">
	/// HFF挥发分
	/// </Property>
	DECLARE_L3PROP_STRING(HFF)

	/// <Property class="CAlloy_Data" name="Sic" type="L3STRING">
	/// Sic
	/// </Property>
	DECLARE_L3PROP_STRING(Sic)

	/// <Property class="CAlloy_Data" name="Si_SiO2" type="L3STRING">
	/// Si+SiO2
	/// </Property>
	DECLARE_L3PROP_STRING(Si_SiO2)

	/// <Property class="CAlloy_Data" name="Y_C" type="L3STRING">
	/// Y_C游离碳
	/// </Property>
	DECLARE_L3PROP_STRING(Y_C)

	/// <Property class="CAlloy_Data" name="Ca_MgO" type="L3STRING">
	/// Ca+MgO
	/// </Property>
	DECLARE_L3PROP_STRING(Ca_MgO)

	/// <Property class="CAlloy_Data" name="K2O_Na2O" type="L3STRING">
	/// K2O+Na2O
	/// </Property>
	DECLARE_L3PROP_STRING(K2O_Na2O)
		///2016-02-26 添加仓库分类，区分合金一库和合金二库
	DECLARE_L3PROP_STRING(cwarehouseid)

};

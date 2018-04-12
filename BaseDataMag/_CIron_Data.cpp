// 逻辑类CIron_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CIron_Data.h"

IMPLEMENT_L3CLASS(CIron_Data,Material,1)

BEGIN_L3PROPTABLE(CIron_Data,Material)
	L3PROP_DOUBLE(Weight)
	L3PROP_FLOAT(C)
	L3PROP_FLOAT(Si)
	L3PROP_FLOAT(Mn)
	L3PROP_FLOAT(P)
	L3PROP_FLOAT(S)
	L3PROP_FLOAT(Ti)
	//add by hyh 2012-04-10
	L3PROP_FLOAT(Sn)
	L3PROP_FLOAT(Sb)
	L3PROP_FLOAT(As)
	L3PROP_FLOAT(Pb)
	//end

	//add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	L3PROP_FLOAT(Ni)
	L3PROP_FLOAT(Mo)
	L3PROP_FLOAT(Cu)
	L3PROP_FLOAT(Cr)
	L3PROP_FLOAT(B)
	L3PROP_FLOAT(V)
	L3PROP_FLOAT(Al)
	L3PROP_FLOAT(Nb)
	L3PROP_FLOAT(Zn)
	L3PROP_FLOAT(W)
	//end

	L3PROP_LONG(IronTemp)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Source)
	L3PROP_SHORT(Shift)
	L3PROP_SHORT(Team)
	L3PROP_STRING(Operator)
	L3PROP_DOUBLE(Tare)
	L3PROP_DOUBLE(Gross_Weight)
	L3PROP_DATETIME(Tap_Time)
	L3PROP_STRING(IronLadleNo)
	L3PROP_STRING(Object1)
	L3PROP_DOUBLE(Weight1)
	L3PROP_STRING(Object2)
	L3PROP_DOUBLE(Weight2)
	L3PROP_STRING(Object3)
	L3PROP_DOUBLE(Weight3)
	L3PROP_FLOAT(Return_Steel_Weight)
	L3PROP_FLOAT(IsDes)
END_L3PROPTABLE(CIron_Data)

BEGIN_L3METHODMAP(CIron_Data,Material)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CIron_Data,Material)
END_L3EVENTSINK_MAP(CIron_Data)

CIron_Data::CIron_Data(void)
{
}

CIron_Data::~CIron_Data(void)
{
}

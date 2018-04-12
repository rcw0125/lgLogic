// 逻辑类CMIF_Unit_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CMIF_Unit_Mag.h"

IMPLEMENT_L3CLASS(CMIF_Unit_Mag,ProduceUnit,1)

BEGIN_L3PROPTABLE(CMIF_Unit_Mag,ProduceUnit)
	L3PROP_STRING(MIFID)
	L3PROP_LONG(Temp)
	L3PROP_DOUBLE(C)
	L3PROP_DOUBLE(Si)
	L3PROP_DOUBLE(Mn)
	L3PROP_DOUBLE(P)
	L3PROP_DOUBLE(S)
	L3PROP_DOUBLE(Ti)
	//add by hyh 2012-04-10
	L3PROP_DOUBLE(Sn)
	L3PROP_DOUBLE(Sb)
	L3PROP_DOUBLE(As)
	L3PROP_DOUBLE(Pb)
	//end

	//add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	L3PROP_DOUBLE(Ni)
	L3PROP_DOUBLE(Mo)
	L3PROP_DOUBLE(Cu)
	L3PROP_DOUBLE(Cr)
	L3PROP_DOUBLE(B)
	L3PROP_DOUBLE(V)
	L3PROP_DOUBLE(Al)
	L3PROP_DOUBLE(Nb)
	L3PROP_DOUBLE(Zn)
	L3PROP_DOUBLE(W)
	//end

	L3PROP_DOUBLE(C_Cal)
	L3PROP_DOUBLE(Si_Cal)
	L3PROP_DOUBLE(Mn_Cal)
	L3PROP_DOUBLE(P_Cal)
	L3PROP_DOUBLE(S_Cal)
	L3PROP_DOUBLE(Ti_Cal)
	//add by hyh 2012-04-10
	L3PROP_DOUBLE(Sn_Cal)
	L3PROP_DOUBLE(Sb_Cal)
	L3PROP_DOUBLE(As_Cal)
	L3PROP_DOUBLE(Pb_Cal)
	//end

	//add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	L3PROP_DOUBLE(Ni_Cal)
	L3PROP_DOUBLE(Mo_Cal)
	L3PROP_DOUBLE(Cu_Cal)
	L3PROP_DOUBLE(Cr_Cal)
	L3PROP_DOUBLE(B_Cal)
	L3PROP_DOUBLE(V_Cal)
	L3PROP_DOUBLE(Al_Cal)
	L3PROP_DOUBLE(Nb_Cal)
	L3PROP_DOUBLE(Zn_Cal)
	L3PROP_DOUBLE(W_Cal)
	//end

	L3PROP_DOUBLE(Weight)
	L3PROP_LONG(subCount)
	L3PROP_DATETIME(Temp_Time)
	L3PROP_DOUBLE(Tare_Weight)
	L3PROP_DATETIME(Tare_Weight_Time)
	L3PROP_DOUBLE(Gross_Weight)
	L3PROP_DATETIME(Gross_Weight_Time)
END_L3PROPTABLE(CMIF_Unit_Mag)

BEGIN_L3METHODMAP(CMIF_Unit_Mag,ProduceUnit)
	L3_METHOD(CMIF_Unit_Mag,"CalculateChemicalData",0,CalculateChemicalData,L3VT_VOID,L3VTS_RECORDSET)
	L3_METHOD(CMIF_Unit_Mag,"SampleChemcialData",0,SampleChemcialData,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMIF_Unit_Mag,"MixIrons",0,MixIrons,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMIF_Unit_Mag,"OutputIron",0,OutputIron,L3VT_BOOL,L3VTS_STRING L3VTS_DOUBLE L3VTS_DOUBLE L3VTS_STRING)
	L3_METHOD(CMIF_Unit_Mag,"AcceptIronLadleWeightData",0,AcceptIronLadleWeightData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CMIF_Unit_Mag,"AcceptTemperatureData",0,AcceptTemperatureData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CMIF_Unit_Mag,"AcceptDirectIronWeightData",0,AcceptDirectIronWeightData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CMIF_Unit_Mag,"OutputIronCancel",0,OutputIronCancel,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMIF_Unit_Mag,"OutputIronCancelToDEP",0,OutputIronCancelToDEP,L3VT_LONG,L3VTS_RECORDSET)
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMIF_Unit_Mag,ProduceUnit)
END_L3EVENTSINK_MAP(CMIF_Unit_Mag)

CMIF_Unit_Mag::CMIF_Unit_Mag(void)
{
}

CMIF_Unit_Mag::~CMIF_Unit_Mag(void)
{
}

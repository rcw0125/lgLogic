// 逻辑类CDeS_Unit_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDeS_Unit_Mag.h"

IMPLEMENT_L3CLASS(CDeS_Unit_Mag,ProduceUnit,1)

BEGIN_L3PROPTABLE(CDeS_Unit_Mag,ProduceUnit)
	L3PROP_STRING(MaterialID_UnDeS)
	L3PROP_STRING(MaterialID_DeSing)
	L3PROP_STRING(MaterialID_DeSed)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(NextTreatNo)
	L3PROP_STRING(CurArea)
	L3PROP_DOUBLE(Weight_MatTank)
	L3PROP_DOUBLE(Weight_SprayTank)
	L3PROP_DOUBLE(Pressure)
	L3PROP_DOUBLE(Flow)
	L3PROP_DOUBLE(Rate)
	L3PROP_STRING(Mat_Code)
	L3PROP_STRING(Mat_Vendor)
	L3PROP_LONG(EventIronChanged)
	L3PROP_DOUBLE(S)
	L3PROP_SHORT(Equipment_Status)
	L3PROP_SHORT(DeSType)
    L3PROP_LONG(DeSStatus)
	L3PROP_DATETIME(DeSStatusChanged_Time)
END_L3PROPTABLE(CDeS_Unit_Mag)

BEGIN_L3METHODMAP(CDeS_Unit_Mag,ProduceUnit)
	L3_METHOD(CDeS_Unit_Mag,"DesignateIronLadle",0,DesignateIronLadle,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDeS_Unit_Mag,"UndoDesignateIronLadle",0,UndoDesignateIronLadle,L3VT_LONG,L3VTS_STRING)
	L3_METHOD(CDeS_Unit_Mag,"ChangeStatus",0,ChangeStatus,L3VT_LONG,L3VTS_STRING L3VTS_SHORT L3VTS_STRING)
	L3_METHOD(CDeS_Unit_Mag,"DesignateDeSUnitID",0,DesignateDeSUnitID,L3VT_LONG,L3VTS_STRING)
	L3_METHOD(CDeS_Unit_Mag,"StartBlowing",0,StartBlowing,L3VT_LONG,L3VTS_STRING)
	L3_METHOD(CDeS_Unit_Mag,"StopBlowing",0,StopBlowing,L3VT_LONG,L3VTS_NONE)
	L3_METHOD(CDeS_Unit_Mag,"AcceptDeSBlowBeginData",0,AcceptDeSBlowBeginData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDeS_Unit_Mag,"AcceptDeSBlowEndData",0,AcceptDeSBlowEndData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDeS_Unit_Mag,"AcceptDeSRuntimeData",0,AcceptDeSRuntimeData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDeS_Unit_Mag,"ChangeLanceNo",0,ChangeLanceNo,L3VT_LONG,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CDeS_Unit_Mag,"IronsDeparture",0,IronsDeparture,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CDeS_Unit_Mag,"ChangeTreatNo",0,ChangeTreatNo,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CDeS_Unit_Mag,"AcceptDeSStatusData",0,AcceptDeSStatusData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDeS_Unit_Mag,"LockData",0,LockData,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CDeS_Unit_Mag,"NewDeSAdditionData",0,NewDeSAdditionData,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDeS_Unit_Mag,"SetDeSMode",0,SetDeSMode,L3VT_BOOL,L3VTS_STRING L3VTS_SHORT)
	L3_METHOD(CDeS_Unit_Mag,"NewDeSEquipmentStatusData",0,NewDeSEquipmentStatusData,L3VT_LONG,L3VTS_SHORT L3VTS_STRING)
	L3_METHOD(CDeS_Unit_Mag,"AddNewLanceData",0,AddNewLanceData,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDeS_Unit_Mag,"ChangeLanceStatus",0,ChangeLanceStatus,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDeS_Unit_Mag,"ChangeLanceAge",0,ChangeLanceAge,L3VT_LONG,L3VTS_RECORDSET)
    L3_METHOD(CDeS_Unit_Mag,"PrepareIronLadle",0,PrepareIronLadle,L3VT_LONG,L3VTS_NONE)
    L3_METHOD(CDeS_Unit_Mag,"AcceptDeSArrivalSignal",0,AcceptDeSArrivalSignal,L3VT_LONG,L3VTS_NONE)
    L3_METHOD(CDeS_Unit_Mag,"GenerateLanceNo",0,GenerateLanceNo,L3VT_STRING,L3VTS_NONE)
    L3_METHOD(CDeS_Unit_Mag,"GetUnArrivedIrons",0,GetUnArrivedIrons,L3VT_RECORDSET,L3VTS_NONE)
    L3_METHOD(CDeS_Unit_Mag,"SetDeSIronPath",0,SetDeSIronPath,L3VT_BOOL,L3VTS_STRING L3VTS_SHORT)

END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Unit_Mag,ProduceUnit)
END_L3EVENTSINK_MAP(CDeS_Unit_Mag)

CDeS_Unit_Mag::CDeS_Unit_Mag(void)
{
}

CDeS_Unit_Mag::~CDeS_Unit_Mag(void)
{
}

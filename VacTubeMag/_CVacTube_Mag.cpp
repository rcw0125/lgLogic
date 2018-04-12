// 逻辑类CVacTube_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CVacTube_Mag.h"

IMPLEMENT_L3CLASS(CVacTube_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Mag,CL3Object)
END_L3PROPTABLE(CVacTube_Mag)

BEGIN_L3METHODMAP(CVacTube_Mag,CL3Object)
	L3_METHOD(CVacTube_Mag,"VacTubeOnPosition",0,VacTubeOnPosition,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"VacTubeBuildStart",0,VacTubeBuildStart,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"VacTubeBuildEnd",0,VacTubeBuildEnd,L3VT_BOOL,L3VTS_RECORDSET)

	L3_METHOD(CVacTube_Mag,"Vactube_Install",0,Vactube_Install,L3VT_LONG,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CVacTube_Mag,"AccepteFireData",0,AccepteFireData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"VacTubeFire",0,VacTubeFire,L3VT_LONG,L3VTS_STRING L3VTS_STRING)

	L3_METHOD(CVacTube_Mag,"VactubeOnLine",0,VactubeOnLine,L3VT_LONG,L3VTS_STRING)
	L3_METHOD(CVacTube_Mag,"VactubeOffLine",0,VactubeOffLine,L3VT_LONG,L3VTS_STRING)

	L3_METHOD(CVacTube_Mag,"HotOn",0,HotOn,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"HotOff",0,HotOff,L3VT_LONG,L3VTS_RECORDSET)

	L3_METHOD(CVacTube_Mag,"VacTubeCheck",0,VacTubeCheck,L3VT_LONG,L3VTS_STRING)
	L3_METHOD(CVacTube_Mag,"VacTubeCheckOver",0,VacTubeCheckOver,L3VT_LONG,L3VTS_STRING L3VTS_STRING)

	L3_METHOD(CVacTube_Mag,"InsertVacTubeBuild",0,InsertVacTubeBuild,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"UpdateVacTubeBuild",0,UpdateVacTubeBuild,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"DeleteVacTubeBuild",0,DeleteVacTubeBuild,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"GetVacTubeBuild",0,GetVacTubeBuild,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CVacTube_Mag,"InsertHotSypBuild",0,InsertHotSypBuild,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"UpdateHotSypBuild",0,UpdateHotSypBuild,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"DeleteHotSypBuild",0,DeleteHotSypBuild,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"GetHotSypBuild",0,GetHotSypBuild,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CVacTube_Mag,"InsertVacTubeFire",0,InsertVacTubeFire,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"UpdateVacTubeFire",0,UpdateVacTubeFire,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"DeleteVacTubeFire",0,DeleteVacTubeFire,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"GetVacTubeFire",0,GetVacTubeFire,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CVacTube_Mag,"InsertVacTubeUse",0,InsertVacTubeUse,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"UpdateVacTubeUse",0,UpdateVacTubeUse,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"DeleteVacTubeUse",0,DeleteVacTubeUse,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"GetVacTubeUse",0,GetVacTubeUse,L3VT_RECORDSET,L3VTS_STRING)
	

	L3_METHOD(CVacTube_Mag,"InsertVacTubeRepair",0,InsertVacTubeRepair,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"UpdateVacTubeRepair",0,UpdateVacTubeRepair,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"DeleteVacTubeRepair",0,DeleteVacTubeRepair,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"GetVacTubeRepair",0,GetVacTubeRepair,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CVacTube_Mag,"InsertHotSypRepair",0,InsertHotSypRepair,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"UpdateHotSypRepair",0,UpdateHotSypRepair,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"DeleteHotSypRepair",0,DeleteHotSypRepair,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"GetHotSypRepair",0,GetHotSypRepair,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CVacTube_Mag,"InsertVacTubeFireInfo",0,InsertVacTubeFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"UpdateVacTubeFireInfo",0,UpdateVacTubeFireInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"DeleteVacTubeFireInfo",0,DeleteVacTubeFireInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"GetVacTubeFireInfo",0,GetVacTubeFireInfo,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CVacTube_Mag,"InsertVacTubeUseInfo",0,InsertVacTubeUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"UpdateVacTubeUseInfo",0,UpdateVacTubeUseInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"DeleteVacTubeUseInfo",0,DeleteVacTubeUseInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"GetVacTubeUseInfo",0,GetVacTubeUseInfo,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CVacTube_Mag,"InsertHotSypUseInfo",0,InsertHotSypUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"UpdateHotSypUseInfo",0,UpdateHotSypUseInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"DeleteHotSypUseInfo",0,DeleteHotSypUseInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CVacTube_Mag,"GetHotSypUseInfo",0,GetHotSypUseInfo,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CVacTube_Mag,"LastVacTubeAesSoaTotalLenOfHeatID",0,LastVacTubeAesSoaTotalLenOfHeatID,L3VT_LONG,L3VTS_STRING)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Mag,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Mag)

CVacTube_Mag::CVacTube_Mag(void)
{
}

CVacTube_Mag::~CVacTube_Mag(void)
{
}

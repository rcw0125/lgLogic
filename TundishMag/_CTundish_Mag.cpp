// 逻辑类CTundish_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CTundish_Mag.h"

IMPLEMENT_L3CLASS(CTundish_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_Mag,CL3Object)
	L3PROP_STRING(Tundish_SeqNo)
END_L3PROPTABLE(CTundish_Mag)

BEGIN_L3METHODMAP(CTundish_Mag,CL3Object)
	/*L3_METHOD(CTundish_Mag,"InsertInfos",0,InsertInfos,L3VT_LONG,L3VTS_RECORDSET CSTRING)
	L3_METHOD(CTundish_Mag,"UpdateInfos",0,UpdateInfos,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CTundish_Mag,"DeleteInfos",0,DeleteInfos,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CTundish_Mag,"GetInfos",0,GetInfos,L3VT_LONG,L3VTS_STRING L3VTS_STRING)*/

	L3_METHOD(CTundish_Mag,"TundishInnerBuildStart",0,TundishInnerBuildStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishInnerBuildEnd",0,TundishInnerBuildEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishInnerFireStart",0,TundishInnerFireStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishInnerFireEnd",0,TundishInnerFireEnd,L3VT_LONG,L3VTS_RECORDSET)

	L3_METHOD(CTundish_Mag,"TundishWorkBuildStart",0,TundishWorkBuildStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishWorkBuildEnd",0,TundishWorkBuildEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishWorkFireStart",0,TundishWorkFireStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishWorkFireEnd",0,TundishWorkFireEnd,L3VT_LONG,L3VTS_RECORDSET)

	L3_METHOD(CTundish_Mag,"TundishConfirmCold",0,TundishConfirmCold,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishInstallStart",0,TundishInstallStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishInstallEnd",0,TundishInstallEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishOnFireStart",0,TundishOnFireStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"TundishOnFireEnd",0,TundishOnFireEnd,L3VT_LONG,L3VTS_RECORDSET)

	L3_METHOD(CTundish_Mag,"InsertTundishInnerBuildInfo",0,InsertTundishInnerBuildInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"UpdateTundishInnerBuildInfo",0,UpdateTundishInnerBuildInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"DeleteTundishInnerBuildInfo",0,DeleteTundishInnerBuildInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"GetTundishInnerBuildInfo",0,GetTundishInnerBuildInfo,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CTundish_Mag,"InsertTundishInnerFireInfo",0,InsertTundishInnerFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"UpdateTundishInnerFireInfo",0,UpdateTundishInnerFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"DeleteTundishInnerFireInfo",0,DeleteTundishInnerFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"GetTundishInnerFireInfo",0,GetTundishInnerFireInfo,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CTundish_Mag,"InsertTundishWorkBuildInfo",0,InsertTundishWorkBuildInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"UpdateTundishWorkBuildInfo",0,UpdateTundishWorkBuildInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"DeleteTundishWorkBuildInfo",0,DeleteTundishWorkBuildInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"GetTundishWorkBuildInfo",0,GetTundishWorkBuildInfo,L3VT_RECORDSET,L3VTS_STRING)


	L3_METHOD(CTundish_Mag,"InsertTundishOTHotFireInfo",0,InsertTundishOTHotFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"UpdateTundishOTHotFireInfo",0,UpdateTundishOTHotFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"DeleteTundishOTHotFireInfo",0,DeleteTundishOTHotFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"GetTundishOTHotFireInfo",0,GetTundishOTHotFireInfo,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CTundish_Mag,"InsertTundishTFFHotFireInfo",0,InsertTundishTFFHotFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"UpdateTundishTFFHotFireInfo",0,UpdateTundishTFFHotFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"DeleteTundishTFFHotFireInfo",0,DeleteTundishTFFHotFireInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"GetTundishTFFHotFireInfo",0,GetTundishTFFHotFireInfo,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CTundish_Mag,"InsertTundishOTInstallInfo",0,InsertTundishOTInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"UpdateTundishOTInstallInfo",0,UpdateTundishOTInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"DeleteTundishOTInstallInfo",0,DeleteTundishOTInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"GetTundishOTInstallInfo",0,GetTundishOTInstallInfo,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CTundish_Mag,"InsertTundishTFFInstallInfo",0,InsertTundishTFFInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"UpdateTundishTFFInstallInfo",0,UpdateTundishTFFInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"DeleteTundishTFFInstallInfo",0,DeleteTundishTFFInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"GetTundishTFFInstallInfo",0,GetTundishTFFInstallInfo,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CTundish_Mag,"InsertTundishOTRefraUseInfo",0,InsertTundishOTRefraUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"UpdateTundishOTRefraUseInfo",0,UpdateTundishOTRefraUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"DeleteTundishOTRefraUseInfo",0,DeleteTundishOTRefraUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"GetTundishOTRefraUseInfo",0,GetTundishOTRefraUseInfo,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CTundish_Mag,"InsertTundishTTFRefraUseInfo",0,InsertTundishTTFRefraUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"UpdateTundishTTFRefraUseInfo",0,UpdateTundishTTFRefraUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"DeleteTundishTTFRefraUseInfo",0,DeleteTundishTTFRefraUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CTundish_Mag,"GetTundishTTFRefraUseInfo",0,GetTundishTTFRefraUseInfo,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CTundish_Mag,"GetAllHotTundish",0,GetAllHotTundish,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CTundish_Mag,"SetTundishNO",0,SetTundishNO,L3VT_LONG,L3VTS_STRING L3VTS_STRING)

	L3_METHOD(CTundish_Mag,"TundishOnLine",0,TundishOnLine,L3VT_LONG,L3VTS_STRING L3VTS_STRING L3VTS_DATETIME)
	L3_METHOD(CTundish_Mag,"TundishOffLine",0,TundishOffLine,L3VT_LONG,L3VTS_STRING L3VTS_STRING L3VTS_DATETIME)

	L3_METHOD(CTundish_Mag,"GetEnableInnerIDorWorkID",0,GetEnableInnerIDorWorkID,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CTundish_Mag,"TundishDirectCold",0,TundishDirectCold,L3VT_LONG,L3VTS_RECORDSET)
	
	L3_METHOD(CTundish_Mag,"TundishDireCCMID",0,TundishDireCCMID,L3VT_LONG,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CTundish_Mag,"TundishOffLineException",0,TundishOffLineException,L3VT_LONG,L3VTS_RECORDSET)
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_Mag,CL3Object)
END_L3EVENTSINK_MAP(CTundish_Mag)

CTundish_Mag::CTundish_Mag(void)
{
}

CTundish_Mag::~CTundish_Mag(void)
{
}

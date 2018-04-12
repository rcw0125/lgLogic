// 逻辑类CLadle_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLadle_Mag.h"

IMPLEMENT_L3CLASS(CLadle_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Mag,CL3Object)
	L3PROP_LONG(LadlePlanEvent)               //钢包计划状态变化事件
END_L3PROPTABLE(CLadle_Mag)

BEGIN_L3METHODMAP(CLadle_Mag,CL3Object)
	L3_METHOD(CLadle_Mag,"SetLadleStatus",0,SetLadleStatus,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)
	/*L3_METHOD(CLadle_Mag,"InsertInfos",0,InsertInfos,L3VT_BOOL,L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CLadle_Mag,"UpdateInfos",0,UpdateInfos,L3VT_BOOL,L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CLadle_Mag,"DeleteInfos",0,DeleteInfos,L3VT_BOOL,L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CLadle_Mag,"GetInfos",0,GetInfos,L3VTS_RECORDSET,L3VTS_STRING L3VTS_STRING)*/
	L3_METHOD(CLadle_Mag,"SpecifyLadle",1,SpecifyLadle,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"QueryUnProcessLadlePlan",2,QueryUnProcessLadlePlan,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CLadle_Mag,"GetAvailableLadle",37,GetAvailableLadle,L3VT_RECORDSET,L3VTS_NONE)
	
	L3_METHOD(CLadle_Mag,"LadlePour",3,LadlePour,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"UpdateLadlePourInfos",0,UpdateLadlePourInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"DeleteLadlePourInfos",0,DeleteLadlePourInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"GetLadlePourInfos",0,GetLadlePourInfos,L3VT_RECORDSET,L3VTS_STRING)
	
	L3_METHOD(CLadle_Mag,"LadleFold",4,LadleFold,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"UpdateLadleFoldInfos",0,UpdateLadleFoldInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"DeleteLadleFoldInfos",0,DeleteLadleFoldInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"GetLadleFoldInfos",0,GetLadleFoldInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"CancelSpecifyLadle",5,CancelSpecifyLadle,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"ReSpecifyLadle",6,ReSpecifyLadle,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"GetLadleInnerID",8,GetLadleInnerID,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CLadle_Mag,"InsertInnerBuildInfos",9,InsertInnerBuildInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"UpdateInnerBuildInfos",10,UpdateInnerBuildInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"DeleteInnerBuildInfos",11,DeleteInnerBuildInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"GetInnerBuildInfos",12,GetInnerBuildInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"InsertComTieInfos",13,InsertComTieInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"UpdateComTieInfos",14,UpdateComTieInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"DeleteComTieInfos",15,DeleteComTieInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"GetComTieInfos",16,GetComTieInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"InsertComRepInfos",17,InsertComRepInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"UpdateComRepInfos",18,UpdateComRepInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"DeleteComRepInfos",19,DeleteComRepInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"GetComRepInfos",20,GetComRepInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"InsertFinBuildInfos",21,InsertFinBuildInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"UpdateFinBuildInfos",22,UpdateFinBuildInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"DeleteFinBuildInfos",23,DeleteFinBuildInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"GetFinBuildInfos",24,GetFinBuildInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"InsertChaDreLinInfos",25,InsertChaDreLinInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"UpdateChaDreLinInfos",26,UpdateChaDreLinInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"DeleteChaDreLinInfos",27,DeleteChaDreLinInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"GetChaDreLinInfos",28,GetChaDreLinInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"InsertFireInfos",29,InsertFireInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"UpdateFireInfos",30,UpdateFireInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"DeleteFireInfos",31,DeleteFireInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"GetFireInfos",32,GetFireInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"InsertLadleUseInfos",33,InsertLadleUseInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"UpdateLadleUseInfos",34,UpdateLadleUseInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"DeleteLadleUseInfos",35,DeleteLadleUseInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"GetLadleUseInfos",36,GetLadleUseInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"GetUseByLadleID",37,GetUseByLadleID,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"SetLadleInfoTaping",38,SetLadleInfoTaping,L3VT_LONG,L3VTS_RECORDSET)

	L3_METHOD(CLadle_Mag,"GetIrrEndTime",0,GetIrrEndTime,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLadle_Mag,"LadleInnerBuildStart",0,LadleInnerBuildStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"LadleInnerBuildEnd",0,LadleInnerBuildEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"LadleWorkBuildStart",0,LadleWorkBuildStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"LadleWorkBuildEnd",0,LadleWorkBuildEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"LadleWorkFireStart",0,LadleWorkFireStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"LadleWorkFireEnd",0,LadleWorkFireEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"LadleHotFireStart",0,LadleHotFireStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"LadleHotFireEnd",0,LadleHotFireEnd,L3VT_LONG,L3VTS_RECORDSET)

	L3_METHOD(CLadle_Mag,"LadleThrow",0,LadleThrow,L3VT_LONG,L3VTS_RECORDSET)
	
	L3_METHOD(CLadle_Mag,"BOFTapingStart",0,BOFTapingStart,L3VT_BOOL,L3VTS_STRING L3VTS_DATETIME L3VTS_STRING)
	
	
	
	L3_METHOD(CLadle_Mag,"MeasureDesignate",0,MeasureDesignate,L3VT_ULONG,L3VTS_STRING)
	L3_METHOD(CLadle_Mag,"LadleOffLineException",0,LadleOffLineException,L3VT_LONG,L3VTS_RECORDSET)

	L3_METHOD(CLadle_Mag,"LadleInnerFireStart",0,LadleInnerFireStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CLadle_Mag,"LadleInnerFireEnd",0,LadleInnerFireEnd,L3VT_LONG,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Mag,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Mag)

CLadle_Mag::CLadle_Mag(void)
{
}

CLadle_Mag::~CLadle_Mag(void)
{
}

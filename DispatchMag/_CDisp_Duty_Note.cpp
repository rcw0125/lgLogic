// 逻辑类CDisp_Duty_Note源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDisp_Duty_Note.h"

IMPLEMENT_L3CLASS(CDisp_Duty_Note,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_Duty_Note,CL3Object)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_DATETIME(CreateDate)
	L3PROP_STRING_LEN(Note,500)
END_L3PROPTABLE(CDisp_Duty_Note)

BEGIN_L3METHODMAP(CDisp_Duty_Note,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_Duty_Note,CL3Object)
END_L3EVENTSINK_MAP(CDisp_Duty_Note)

CDisp_Duty_Note::CDisp_Duty_Note(void)
{
}

CDisp_Duty_Note::~CDisp_Duty_Note(void)
{
}

// 逻辑类CVacTube_Base源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CVacTube_Base.h"

IMPLEMENT_L3CLASS(CVacTube_Base,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Base,CL3Object)
	L3PROP_STRING(VacTube_Name)
	L3PROP_STRING(VacTube_ID)
	L3PROP_STRING(Status)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Position)
	L3PROP_STRING(Build_ID)
	L3PROP_STRING(VacTube_Code)
	L3PROP_LONG(VacTube_Age)
	L3PROP_STRING(Install_ID)
	L3PROP_LONG(Flag)
	L3PROP_LONG(Fire_Count)
END_L3PROPTABLE(CVacTube_Base)

BEGIN_L3METHODMAP(CVacTube_Base,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Base,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Base)

CVacTube_Base::CVacTube_Base(void)
{
}

CVacTube_Base::~CVacTube_Base(void)
{
}

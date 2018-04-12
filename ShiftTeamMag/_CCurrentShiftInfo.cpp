// �߼���CurrentShiftInfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCurrentShiftInfo.h"

IMPLEMENT_L3CLASS(CCurrentShiftInfo,CL3Object,1)

BEGIN_L3PROPTABLE(CCurrentShiftInfo,CL3Object)
	L3PROP_STRING(L3Index)
	L3PROP_STRING(ShiftType)
	L3PROP_SHORT(ShiftID)
	L3PROP_SHORT(TeamID)
	L3PROP_STRING(UnitTypeID)
	L3PROP_STRING(UnitID)
	L3PROP_SHORT(CurrentID)
	L3PROP_DATETIME(BeginProcessTime)
	L3PROP_DATETIME(EndProcessTime)
	L3PROP_STRING(ShiftWarning)
END_L3PROPTABLE(CCurrentShiftInfo)

BEGIN_L3METHODMAP(CCurrentShiftInfo,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCurrentShiftInfo,CL3Object)
END_L3EVENTSINK_MAP(CCurrentShiftInfo)

CCurrentShiftInfo::CCurrentShiftInfo(void)
{
}

CCurrentShiftInfo::~CCurrentShiftInfo(void)
{
}

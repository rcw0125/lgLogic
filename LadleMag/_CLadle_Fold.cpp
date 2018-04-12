// �߼���CLadle_FoldԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Fold.h"

IMPLEMENT_L3CLASS(CLadle_Fold,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Fold,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Steel_Grade)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Out_LadleID)
	L3PROP_STRING(In_LadleID)
	L3PROP_STRING(Weight)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
	L3PROP_LONG(Confirm_Flag)

END_L3PROPTABLE(CLadle_Fold)

BEGIN_L3METHODMAP(CLadle_Fold,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Fold,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Fold)

CLadle_Fold::CLadle_Fold(void)
{
}

CLadle_Fold::~CLadle_Fold(void)
{
}

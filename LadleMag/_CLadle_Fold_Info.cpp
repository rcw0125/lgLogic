// �߼���CLadle_Fold_InfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Fold_Info.h"

IMPLEMENT_L3CLASS(CLadle_Fold_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Fold_Info,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Steel_Grade)
	L3PROP_STRING(Out_Ladle_ID)
	L3PROP_STRING(In_Ladle_ID)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLadle_Fold_Info)

BEGIN_L3METHODMAP(CLadle_Fold_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Fold_Info,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Fold_Info)

CLadle_Fold_Info::CLadle_Fold_Info(void)
{
}

CLadle_Fold_Info::~CLadle_Fold_Info(void)
{
}

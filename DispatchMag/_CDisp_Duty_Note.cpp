// �߼���CDisp_Duty_NoteԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

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

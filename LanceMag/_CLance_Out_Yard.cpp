// �߼���CLance_Out_YardԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLance_Out_Yard.h"

IMPLEMENT_L3CLASS(CLance_Out_Yard,CL3Object,1)

BEGIN_L3PROPTABLE(CLance_Out_Yard,CL3Object)
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Lance_Head_Type)
	L3PROP_STRING(Nozzle_Factury)
	L3PROP_DOUBLE(Nozzle_Throat_Dia)
	L3PROP_DOUBLE(Nozzle_Angle)
	L3PROP_LONG(Out_Yard)
	L3PROP_LONG(Out_Total)
	L3PROP_STRING(Out_Confirm)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Take_Material_Man)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CLance_Out_Yard)

BEGIN_L3METHODMAP(CLance_Out_Yard,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLance_Out_Yard,CL3Object)
END_L3EVENTSINK_MAP(CLance_Out_Yard)

CLance_Out_Yard::CLance_Out_Yard(void)
{
}

CLance_Out_Yard::~CLance_Out_Yard(void)
{
}

// �߼���CLadle_ProcessԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Process.h"

IMPLEMENT_L3CLASS(CLadle_Process,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Process,CL3Object)
	
	L3PROP_STRING(LadleID)
	L3PROP_STRING(InnerID)
	L3PROP_STRING(WorkID)
	L3PROP_DATETIME(Online_Time)
	L3PROP_STRING(Online_HeatID)
	L3PROP_DATETIME(Offline_Time)
	L3PROP_STRING(Offline_HeatID)
	L3PROP_LONG(Comfirm_Flag)
	L3PROP_DATETIME(Throw_Time)
	L3PROP_LONG(Ladle_Age)
END_L3PROPTABLE(CLadle_Process)

BEGIN_L3METHODMAP(CLadle_Process,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Process,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Process)

CLadle_Process::CLadle_Process(void)
{
}

CLadle_Process::~CLadle_Process(void)
{
}

// �߼���CLadle_BaseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLadle_Base.h"

IMPLEMENT_L3CLASS(CLadle_Base,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Base,CL3Object)
	L3PROP_STRING(LadleID)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Refra_Facturer)
	L3PROP_STRING(Status)
	L3PROP_STRING(Ladle_Grade)
	L3PROP_LONG(Ladle_Age)
	L3PROP_LONG(New_BOF_Flag)
	L3PROP_DOUBLE(Tare_WT)
	L3PROP_LONG(LadleType)
	L3PROP_STRING(InnerID)
	L3PROP_STRING(WorkID)
	L3PROP_LONG(ComFlag)
	L3PROP_LONG(OnFireID)
	L3PROP_LONG(WorkFireID)
	L3PROP_LONG(Measure_Flag)//2009-04-13
	//Modify begin by llj 2011-04-09 �������ò�濾
	L3PROP_LONG(InnerFireID)
	//Modify end
END_L3PROPTABLE(CLadle_Base)

BEGIN_L3METHODMAP(CLadle_Base,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Base,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Base)

CLadle_Base::CLadle_Base(void)
{
}

CLadle_Base::~CLadle_Base(void)
{
}

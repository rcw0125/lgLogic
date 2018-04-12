// �߼���CIronLadle_BaseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CIronLadle_Base.h"

IMPLEMENT_L3CLASS(CIronLadle_Base,CL3Object,1)

BEGIN_L3PROPTABLE(CIronLadle_Base,CL3Object)
	L3PROP_STRING(IronLadleID)
	L3PROP_STRING(TieID)
	L3PROP_STRING(Status)
	L3PROP_LONG(ComFlag)
	L3PROP_LONG(IronLadle_Age)
	L3PROP_FLOAT(Tare_Weight)
	L3PROP_FLOAT(Gross_Weight)
	L3PROP_FLOAT(Net_Weight)
	L3PROP_STRING(Refra_Produce)
	L3PROP_STRING(Refra_ID)
	//2009-03-17
	L3PROP_LONG(Small_FireID)
	L3PROP_LONG(Middle_FireID)
	L3PROP_LONG(Big_FireID)
END_L3PROPTABLE(CIronLadle_Base)

BEGIN_L3METHODMAP(CIronLadle_Base,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CIronLadle_Base,CL3Object)
END_L3EVENTSINK_MAP(CIronLadle_Base)

CIronLadle_Base::CIronLadle_Base(void)
{
}

CIronLadle_Base::~CIronLadle_Base(void)
{
}

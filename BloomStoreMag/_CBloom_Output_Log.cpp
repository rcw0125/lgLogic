// �߼���CBloom_Output_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBloom_Output_Log.h"

IMPLEMENT_L3CLASS(CBloom_Output_Log,MaterialOutputLog,1)

BEGIN_L3PROPTABLE(CBloom_Output_Log,MaterialOutputLog)
	L3PROP_STRING(SteelGradeIndex)
	///2009-02-23���������ֶ�
	L3PROP_LONG(Length)
	L3PROP_LONG(Width)
	L3PROP_LONG(Thickness)
	L3PROP_DOUBLE(Cal_Weight)
	L3PROP_DOUBLE(Right_Weight)
	L3PROP_DOUBLE(Waster_Weight)
	L3PROP_DOUBLE(Wrong_Weight)
	L3PROP_LONG(Bloom_Count)
	L3PROP_DOUBLE(Waster_Count)
	L3PROP_LONG(Wrong_Count)
	L3PROP_LONG(Right_Count)
END_L3PROPTABLE(CBloom_Output_Log)

BEGIN_L3METHODMAP(CBloom_Output_Log,MaterialOutputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBloom_Output_Log,MaterialOutputLog)
END_L3EVENTSINK_MAP(CBloom_Output_Log)

CBloom_Output_Log::CBloom_Output_Log(void)
{
}

CBloom_Output_Log::~CBloom_Output_Log(void)
{
}

// �߼���CQA_HeatSufaceAssume_MagԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_HeatSufaceAssume_Mag.h"

IMPLEMENT_L3CLASS(CQA_HeatSufaceAssume_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_HeatSufaceAssume_Mag,CL3Object)
	L3PROP_STRING(HeatSufaceAAssumeMag)
	L3PROP_LONG(HotJudgeEvent)
	L3PROP_LONG(CoolJudgeEvent)
	L3PROP_LONG (BloomCuttingEvent)
END_L3PROPTABLE(CQA_HeatSufaceAssume_Mag)

BEGIN_L3METHODMAP(CQA_HeatSufaceAssume_Mag,CL3Object)
	L3_METHOD(CQA_HeatSufaceAssume_Mag,"BloomHotJudge", 0,BloomHotJudge,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatSufaceAssume_Mag,"BloomColdJudge", 0,BloomColdJudge,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatSufaceAssume_Mag,"GetBloomWaitingSendInfor", 0,GetBloomWaitingSendInfor,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CQA_HeatSufaceAssume_Mag,"BloomHotSend", 0,BloomHotSend,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatSufaceAssume_Mag,"BloomOffLine", 0,BloomOffLine,L3VT_LONG,L3VTS_RECORDSET)
	
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_HeatSufaceAssume_Mag,CL3Object)
END_L3EVENTSINK_MAP(CQA_HeatSufaceAssume_Mag)

CQA_HeatSufaceAssume_Mag::CQA_HeatSufaceAssume_Mag(void)
{
}

CQA_HeatSufaceAssume_Mag::~CQA_HeatSufaceAssume_Mag(void)
{
}

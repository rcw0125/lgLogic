// �߼���CEnergyHistoryDataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CEnergyHistoryData.h"

IMPLEMENT_L3CLASS(CEnergyHistoryData,CL3Object,1)

BEGIN_L3PROPTABLE(CEnergyHistoryData,CL3Object)
	L3PROP_STRING(TagName)
	L3PROP_LONG(TagType)
	L3PROP_DOUBLE(TagValue)
	L3PROP_DATETIME(Catch_Time)
END_L3PROPTABLE(CEnergyHistoryData)

BEGIN_L3METHODMAP(CEnergyHistoryData,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEnergyHistoryData,CL3Object)
END_L3EVENTSINK_MAP(CEnergyHistoryData)

CEnergyHistoryData::CEnergyHistoryData(void)
{
}

CEnergyHistoryData::~CEnergyHistoryData(void)
{
}

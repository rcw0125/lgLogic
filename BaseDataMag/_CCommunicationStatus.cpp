// �߼���CCommunicationStatusԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCommunicationStatus.h"

IMPLEMENT_L3CLASS(CCommunicationStatus,CL3Object,1)

BEGIN_L3PROPTABLE(CCommunicationStatus,CL3Object)
	L3PROP_STRING  (WorkShop)     //��λ        
	L3PROP_LONG    (WatchDog)     //����ֵ  
END_L3PROPTABLE(CCommunicationStatus)

BEGIN_L3METHODMAP(CCommunicationStatus,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCommunicationStatus,CL3Object)
END_L3EVENTSINK_MAP(CCommunicationStatus)

CCommunicationStatus::CCommunicationStatus(void)
{
}

CCommunicationStatus::~CCommunicationStatus(void)
{
}

// �߼���CLF_BlowAr_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_BlowAr_Data.h"

IMPLEMENT_L3CLASS(CLF_BlowAr_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_BlowAr_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_DOUBLE(Flow_BlowAr)
	L3PROP_DATETIME(LogTime)
END_L3PROPTABLE(CLF_BlowAr_Data)

BEGIN_L3METHODMAP(CLF_BlowAr_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_BlowAr_Data,CL3Object)
END_L3EVENTSINK_MAP(CLF_BlowAr_Data)

CLF_BlowAr_Data::CLF_BlowAr_Data(void)
{
}

CLF_BlowAr_Data::~CLF_BlowAr_Data(void)
{
}

// �߼���UnitTimeInfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CUnitTimeInfo.h"

IMPLEMENT_L3CLASS(CUnitTimeInfo,CL3Object,1)

BEGIN_L3PROPTABLE(CUnitTimeInfo,CL3Object)
	L3PROP_SHORT(L3Index)				//����
	L3PROP_STRING(UnitIndex)			//����+��λ
	L3PROP_STRING(ShiftType)			//��������
	L3PROP_SHORT(ShiftID)				//���
	L3PROP_STRING(UnitTypeID)			//����
	L3PROP_STRING(UnitTypeIDDesc)		//��������
	L3PROP_STRING(UnitID)				//��λ
	L3PROP_STRING(UnitIDDesc)			//��λ����
	L3PROP_DATETIME(BeginProcessTime)	//��ʼʱ��
	L3PROP_DATETIME(EndProcessTime)		//����ʱ��
END_L3PROPTABLE(CUnitTimeInfo)

BEGIN_L3METHODMAP(CUnitTimeInfo,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CUnitTimeInfo,CL3Object)
END_L3EVENTSINK_MAP(CUnitTimeInfo)

CUnitTimeInfo::CUnitTimeInfo(void)
{
}

CUnitTimeInfo::~CUnitTimeInfo(void)
{
}

// �߼���CPlan_Cur_PreLotNoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CPlan_Cur_PreLotNo.h"

IMPLEMENT_L3CLASS(CPlan_Cur_PreLotNo,CL3Object,1)

BEGIN_L3PROPTABLE(CPlan_Cur_PreLotNo,CL3Object)
	L3PROP_STRING(Cur_PreLotNo)
	L3PROP_STRING(CasterID)
END_L3PROPTABLE(CPlan_Cur_PreLotNo)

BEGIN_L3METHODMAP(CPlan_Cur_PreLotNo,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Cur_PreLotNo,CL3Object)
END_L3EVENTSINK_MAP(CPlan_Cur_PreLotNo)

CPlan_Cur_PreLotNo::CPlan_Cur_PreLotNo(void)
{
}

CPlan_Cur_PreLotNo::~CPlan_Cur_PreLotNo(void)
{
}

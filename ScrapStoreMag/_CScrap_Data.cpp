// �߼���CScrap_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CScrap_Data.h"

IMPLEMENT_L3CLASS(CScrap_Data,Material,1)

BEGIN_L3PROPTABLE(CScrap_Data,Material)
 L3PROP_DOUBLE(Amount)
END_L3PROPTABLE(CScrap_Data)

BEGIN_L3METHODMAP(CScrap_Data,Material)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CScrap_Data,Material)
END_L3EVENTSINK_MAP(CScrap_Data)

CScrap_Data::CScrap_Data(void)
{
}

CScrap_Data::~CScrap_Data(void)
{
}

// �߼���CSrap_Tel_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CScrap_Trans_Tel_Data.h"

IMPLEMENT_L3CLASS(CScrap_Trans_Tel_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CScrap_Trans_Tel_Data,CL3Object)
	
	L3PROP_DATETIME(Rec_Time)
	L3PROP_STRING(cinventoryid)
	L3PROP_STRING(Invcode)
	L3PROP_STRING(Invname)
	L3PROP_STRING(Invspec)
	L3PROP_STRING(Invtype)
	L3PROP_DATETIME(dbizdate)
	L3PROP_STRING(cotherwhid)
	L3PROP_STRING(cwarehouseid)
	L3PROP_DOUBLE(ninnum)
	L3PROP_LONG(ninassistnum)
	L3PROP_STRING(vbatchcode)
	L3PROP_STRING(vuserdef1)
	L3PROP_STRING(vuserdef2)
	L3PROP_STRING(vuserdef3)
	L3PROP_STRING(vuserdef4)
	L3PROP_STRING(vuserdef5)
	L3PROP_STRING(vfree1)
	L3PROP_STRING(vfree2)
	L3PROP_STRING(vfree3)
	L3PROP_STRING(vfree4)
	L3PROP_STRING(vfree5)
	L3PROP_STRING(pk_corp)
END_L3PROPTABLE(CScrap_Trans_Tel_Data)

BEGIN_L3METHODMAP(CScrap_Trans_Tel_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CScrap_Trans_Tel_Data,CL3Object)
END_L3EVENTSINK_MAP(CScrap_Trans_Tel_Data)

CScrap_Trans_Tel_Data::CScrap_Trans_Tel_Data(void)
{
}

CScrap_Trans_Tel_Data::~CScrap_Trans_Tel_Data(void)
{
}

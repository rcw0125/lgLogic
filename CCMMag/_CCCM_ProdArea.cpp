// �߼���CCCM_ProdAreaԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_ProdArea.h"

IMPLEMENT_L3CLASS(CCCM_ProdArea,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_ProdArea,CL3Object)
END_L3PROPTABLE(CCCM_ProdArea)

BEGIN_L3METHODMAP(CCCM_ProdArea,CL3Object)
	L3_METHOD(CCCM_ProdArea,"ProcessMaterials",0,ProcessMaterials,L3VT_BOOL,L3VTS_RECORDSET L3VTS_RECORDSET L3VTS_LONG L3VTS_RECORDSET L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_ProdArea,CL3Object)
END_L3EVENTSINK_MAP(CCCM_ProdArea)

CCCM_ProdArea::CCCM_ProdArea(void)
{
}

CCCM_ProdArea::~CCCM_ProdArea(void)
{
}

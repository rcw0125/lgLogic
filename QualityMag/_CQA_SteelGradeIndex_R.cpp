// �߼���CQA_SteelGradeIndex_RԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_SteelGradeIndex_R.h"

IMPLEMENT_L3CLASS(CQA_SteelGradeIndex_R,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_SteelGradeIndex_R,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(Grade_Group_Code)
	L3PROP_LONG(First_Flag)
	L3PROP_STRING(Protocol)
	L3PROP_STRING(NC_Zyx1)//2009-03-11 tangyi
	L3PROP_STRING(NC_Zyx2)//2009-03-11 tangyi
	L3PROP_STRING_LEN(BOF_Note,500)//2009-03-18 tangyi
	//Modify begin by llj 2011-03-11
	L3PROP_STRING_LEN(Use_Flag,1) //ʹ�ñ�־ 0��ʹ�� 1������
	//Modify end
END_L3PROPTABLE(CQA_SteelGradeIndex_R)

BEGIN_L3METHODMAP(CQA_SteelGradeIndex_R,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_SteelGradeIndex_R,CL3Object)
END_L3EVENTSINK_MAP(CQA_SteelGradeIndex_R)

CQA_SteelGradeIndex_R::CQA_SteelGradeIndex_R(void)
{
}

CQA_SteelGradeIndex_R::~CQA_SteelGradeIndex_R(void)
{
}

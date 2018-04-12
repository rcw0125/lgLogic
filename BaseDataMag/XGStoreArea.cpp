// �߼���XGStoreArea���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_XGStoreArea.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_XGStoreArea.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_XGStoreArea.h"

//������װ�ص�ϵͳ��ʱ��������
void XGStoreArea::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void XGStoreArea::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
///	���ظû�������ȫ��λ�ñ��롣�˱��������ȫ��Ψһ�ģ�
/// </summary>
CString XGStoreArea::GetPositionCode()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return GetPropValue(_T("Code")).ToCString();
}

double XGStoreArea::GetAmountTolerance()
{
	CString csStoreArea = GetIdentity().ToCString();
	CString csStoreType = csStoreArea.Mid(0,3);
	if(csStoreType == STORE_ID_SCRAP)
		return 0.01;
	else
		return 10;
}

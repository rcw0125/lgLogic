// �߼���XGInterCache���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_XGInterCache.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_XGInterCache.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_XGInterCache.h"

//������װ�ص�ϵͳ��ʱ��������
void XGInterCache::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void XGInterCache::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
///	���ظû�������ȫ��λ�ñ��롣�˱��������ȫ��Ψһ�ģ�
/// </summary>
CString XGInterCache::GetPositionCode()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return GetPropValue(_T("Code")).ToCString();
}

/// <summary>
/// �õ��û����������Ա�ʶ����ͬ�����Ծ����˲�ͬ�Ļ�����������ʽ��
/// ��ʶ���ݲμ�ö�� MaterialCacheFlags �Ķ��塣
/// </summary>
DWORD XGInterCache::GetCacheFlags()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetCacheFlags();
};

/// <summary>
/// �õ��û������Ĺ�Ӧ��������URI����Ӧ���������ڸû�����ȱ��ʱ������˻��������������е�����
/// </summary>
CString XGInterCache::GetSupplier()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetSupplier();
};

/// <summary>
/// �õ��û����������ѻ�������URI�����ѻ��������ڸû������յ��µĲ���ʱ������˻��������������Ϸ������С�
/// </summary>
CString XGInterCache::GetConsumer() 
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetConsumer();
};


double XGInterCache::GetAmountTolerance()
{
	CString csStoreArea = GetIdentity().ToCString();
	CString csStoreType = csStoreArea.Mid(0,3);
	if(csStoreType == STORE_ID_SCRAP)
		return 0.01;
	else
		return 10;
}
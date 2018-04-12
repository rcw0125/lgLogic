// �߼���XGInterCacheͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialCache.h"

class XGInterCache :
	public MaterialCache
{
public:
	XGInterCache(void);
	virtual ~XGInterCache(void);

	DECLARE_L3CLASS(XGInterCache,XGMESLogic\\BaseDataMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(XGInterCache)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:
	/// <summary>
	/// �õ��û����������Ա�ʶ����ͬ�����Ծ����˲�ͬ�Ļ�����������ʽ��
	/// ��ʶ���ݲμ�ö�� MaterialCacheFlags �Ķ��塣
	/// </summary>
	virtual DWORD GetCacheFlags();

	/// <summary>
	/// �õ��û������Ĺ�Ӧ��������URI����Ӧ���������ڸû�����ȱ��ʱ������˻��������������е�����
	/// </summary>
	virtual CString GetSupplier();

	/// <summary>
	/// �õ��û����������ѻ�������URI�����ѻ��������ڸû������յ��µĲ���ʱ������˻��������������Ϸ������С�
	/// </summary>
	virtual CString GetConsumer();

	/// <summary>
	/// ����λ�ñ�����麯�����̳���������ش˺��������Լ���λ�ñ��붨�塣
	/// ARG >> void
	/// RET << λ�ñ���
	/// </summary>
	virtual CString GetPositionCode();

	virtual double GetAmountTolerance();//2009-03-27
};

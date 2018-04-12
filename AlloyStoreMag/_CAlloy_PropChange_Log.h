// �߼���CAlloy_PropChange_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialPropLog.h"

class CAlloy_PropChange_Log :
	public MaterialPropLog
{
public:
	CAlloy_PropChange_Log(void);
	virtual ~CAlloy_PropChange_Log(void);

	DECLARE_L3CLASS(CAlloy_PropChange_Log,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_PropChange_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAlloy_PropChange_Log" name="Amount" type="L3DOUBLE">
	/// ������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	/// <Property class="CAlloy_PropChange_Log" name="Operator" type="L3STRING">
	/// �޸���
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

};

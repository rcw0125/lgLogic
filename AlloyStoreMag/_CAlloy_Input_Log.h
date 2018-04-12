// �߼���CAlloy_Input_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialInputLog.h"

class CAlloy_Input_Log :
	public MaterialInputLog
{
public:
	CAlloy_Input_Log(void);
	virtual ~CAlloy_Input_Log(void);

	DECLARE_L3CLASS(CAlloy_Input_Log,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Input_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Input_Log" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CAlloy_Input_Log" name="Alloy_Code" type="L3STRING">
	/// �Ͻ����
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_Input_Log" name="Alloy_Confirm_Man" type="L3STRING">
	/// ¯ǰȷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Confirm_Man)

	/// <Property class="CAlloy_Input_Log" name="Shop_Confirm_Man" type="L3STRING">
	/// ����ȷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Shop_Confirm_Man)

};

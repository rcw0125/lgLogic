// �߼���CBulk_Input_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialInputLog.h"

class CBulk_Input_Log :
	public MaterialInputLog
{
public:
	CBulk_Input_Log(void);
	virtual ~CBulk_Input_Log(void);

	DECLARE_L3CLASS(CBulk_Input_Log,XGMESLogic\\BulkStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Input_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBulk_Input_Log" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CBulk_Input_Log" name="Bulk_Code" type="L3STRING">
	/// ɢ״�ϴ���
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Input_Log" name="Bulk_Confirm_Man" type="L3STRING">
	/// ¯ǰȷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Confirm_Man)

	/// <Property class="CBulk_Input_Log" name="Shop_Confirm_Man" type="L3STRING">
	/// ����ȷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Shop_Confirm_Man)

};

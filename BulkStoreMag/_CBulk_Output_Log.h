// �߼���CBulk_Output_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialOutputLog.h"

class CBulk_Output_Log :
	public MaterialOutputLog
{
public:
	CBulk_Output_Log(void);
	virtual ~CBulk_Output_Log(void);

	DECLARE_L3CLASS(CBulk_Output_Log,XGMESLogic\\BulkStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Output_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBulk_Output_Log" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CBulk_Output_Log" name="Bulk_Code" type="L3STRING">
	/// ɢ״�ϴ���
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Output_Log" name="UnitID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

};

// �߼���CMIF_Feed_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "UnitFeedingLog.h"

class CMIF_Feed_Log :
	public UnitFeedingLog
{
public:
	CMIF_Feed_Log(void);
	virtual ~CMIF_Feed_Log(void);

	DECLARE_L3CLASS(CMIF_Feed_Log,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Feed_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CMIF_Feed_Log" name="MIFID" type="L3STRING">
	/// ����¯��
	/// </Property>
	DECLARE_L3PROP_STRING(MIFID)

	/// <Property class="CMIF_Feed_Log" name="BFID" type="L3STRING">
	/// ��¯¯��
	/// </Property>
	DECLARE_L3PROP_STRING(BFID)

	/// <Property class="CMIF_Feed_Log" name="TAP_No" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TAP_No)

	/// <Property class="CMIF_Feed_Log" name="TPC_No" type="L3STRING">
	/// �޺�
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

};

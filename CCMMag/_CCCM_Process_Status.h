// �߼���CCCM_Process_Statusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Process_Status :
	public CL3Object
{
public:
	CCCM_Process_Status(void);
	virtual ~CCCM_Process_Status(void);

	DECLARE_L3CLASS(CCCM_Process_Status,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Process_Status)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Process_Status" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Process_Status" name="TreatNo" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Process_Status" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Process_Status" name="Status" type="L3SHORT">
	/// 
	/// ״̬(1:¯�ο�ʼ;
	///          2:¯�ν���)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CCCM_Process_Status" name="Change_Time" type="L3DATETIME">
	/// ״̬�仯ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Time)

};

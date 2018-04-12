// �߼���CCCM_Heat_ProtectCastingͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_ProtectCasting :
	public CL3Object
{
public:
	CCCM_Heat_ProtectCasting(void);
	virtual ~CCCM_Heat_ProtectCasting(void);

	DECLARE_L3CLASS(CCCM_Heat_ProtectCasting,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_ProtectCasting)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_ProtectCasting" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_ProtectCasting" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_ProtectCasting" name="Start_Time" type="L3DATETIME">
	/// ������ע��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CCCM_Heat_ProtectCasting" name="Stop_Time" type="L3DATETIME">
	/// ������ע����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Stop_Time)

	/// <Property class="CCCM_Heat_ProtectCasting" name="Ar_Flow" type="L3FLOAT">
	/// ������ע�������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Ar_Flow)

};

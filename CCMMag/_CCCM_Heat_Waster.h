// �߼���CCCM_Heat_Wasterͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_Waster :
	public CL3Object
{
public:
	CCCM_Heat_Waster(void);
	virtual ~CCCM_Heat_Waster(void);

	DECLARE_L3CLASS(CCCM_Heat_Waster,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Waster)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_Waster" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Waster" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Waster" name="TreatNo" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Heat_Waster" name="BloomID" type="L3STRING">
	/// 
	/// ˦��֧��
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(BloomID)

	/// <Property class="CCCM_Heat_Waster" name="Weight" type="L3FLOAT">
	/// 
	/// ˦������
	/// 
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CCCM_Heat_Waster" name="Reason" type="L3STRING">
	/// 
	/// ˦��ԭ��
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

	/// <Property class="CCCM_Heat_Waster" name="Log_Time" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

};

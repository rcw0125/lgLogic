// �߼���CCCM_Heat_Coolingͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_Cooling :
	public CL3Object
{
public:
	CCCM_Heat_Cooling(void);
	virtual ~CCCM_Heat_Cooling(void);

	DECLARE_L3CLASS(CCCM_Heat_Cooling,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Cooling)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_Cooling" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Cooling" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Cooling" name="StrandID" type="L3SHORT">
	/// �ᾧ������(������Ϊ0��ʾ�ܹ�����)
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandID)

	/// <Property class="CCCM_Heat_Cooling" name="Flow" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow)

	/// <Property class="CCCM_Heat_Cooling" name="Pressure" type="L3FLOAT">
	/// ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Pressure)

	/// <Property class="CCCM_Heat_Cooling" name="Temp" type="L3FLOAT">
	/// �¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(Temp)

};

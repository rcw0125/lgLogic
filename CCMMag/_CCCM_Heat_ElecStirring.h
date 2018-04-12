// �߼���CCCM_Heat_ElecStirringͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_ElecStirring :
	public CL3Object
{
public:
	CCCM_Heat_ElecStirring(void);
	virtual ~CCCM_Heat_ElecStirring(void);

	DECLARE_L3CLASS(CCCM_Heat_ElecStirring,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_ElecStirring)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_ElecStirring" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_ElecStirring" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_ElecStirring" name="StrandID" type="L3SHORT">
	/// �ᾧ������
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandID)

	/// <Property class="CCCM_Heat_ElecStirring" name="Stirring" type="L3SHORT">
	/// ��Ž���(0���ޡ�1����)
	/// </Property>
	DECLARE_L3PROP_SHORT(Stirring)

	/// <Property class="CCCM_Heat_ElecStirring" name="Current" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Current)

	/// <Property class="CCCM_Heat_ElecStirring" name="Frequency" type="L3FLOAT">
	/// Ƶ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Frequency)

	/// <Property class="CCCM_Heat_ElecStirring" name="Mode" type="L3SHORT">
	/// ���跽ʽ
	/// </Property>
	DECLARE_L3PROP_SHORT(Mode)

};

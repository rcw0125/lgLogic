// �߼���CCCM_Heat_Speedͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_Speed :
	public CL3Object
{
public:
	CCCM_Heat_Speed(void);
	virtual ~CCCM_Heat_Speed(void);

	DECLARE_L3CLASS(CCCM_Heat_Speed,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Speed)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_Speed" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Speed" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Speed" name="StrandID" type="L3SHORT">
	/// �ᾧ������
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandID)

	/// <Property class="CCCM_Heat_Speed" name="Speed" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Speed)

	/// <Property class="CCCM_Heat_Speed" name="Change_Time" type="L3DATETIME">
	/// �仯ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Time)

};

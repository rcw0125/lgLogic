// �߼���CCCM_Dutyͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Duty :
	public CL3Object
{
public:
	CCCM_Duty(void);
	virtual ~CCCM_Duty(void);

	DECLARE_L3CLASS(CCCM_Duty,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Duty)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Duty" name="CCMID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Duty" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CCCM_Duty" name="Ladle_Officer" type="L3STRING">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(Station)

	/// <Property class="CCCM_Duty" name="Tundish_1ST_Officer" type="L3STRING">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator_name)

};

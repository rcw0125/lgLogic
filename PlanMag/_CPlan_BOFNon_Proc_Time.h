// �߼���CPlan_BOFNon_Proc_Timeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CPlan_BOFNon_Proc_Time :
	public CL3Object
{
public:
	CPlan_BOFNon_Proc_Time(void);
	virtual ~CPlan_BOFNon_Proc_Time(void);

	DECLARE_L3CLASS(CPlan_BOFNon_Proc_Time,XGMESLogic\\PlanMag, HeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_BOFNon_Proc_Time)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_BOFNon_Proc_Time" name="Aim_Time_BOFRepared" type="L3DOUBLE">
	/// �ƻ���¯ʱ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Aim_Time_BOFRepared)

	/// <Property class="CPlan_BOFNon_Proc_Time" name="Aim_Time_BlowN2" type="L3DOUBLE">
	/// ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Aim_Time_BlowN2)

	/// <Property class="CPlan_BOFNon_Proc_Time" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

};

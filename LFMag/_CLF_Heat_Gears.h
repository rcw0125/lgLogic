// �߼���CLF_Heat_Gearsͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_Heat_Gears :
	public CL3Object
{
public:
	CLF_Heat_Gears(void);
	virtual ~CLF_Heat_Gears(void);

	DECLARE_L3CLASS(CLF_Heat_Gears,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Heat_Gears)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_Heat_Gears" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Heat_Gears" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Heat_Gears" name="Gears" type="L3LONG">
	/// ���ȵ�λ
	/// </Property>
	DECLARE_L3PROP_LONG(Gears)

	/// <Property class="CLF_Heat_Gears" name="LogTime" type="L3DATETIME">
	/// ��λ�仯��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)
};

// �߼���CTundish_OT_Installͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_OT_Install :
	public CL3Object
{
public:
	CTundish_OT_Install(void);
	virtual ~CTundish_OT_Install(void);

	DECLARE_L3CLASS(CTundish_OT_Install,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_OT_Install)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTundish_OT_Install" name="TundishID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_OT_Install" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_OT_Install" name="Daub_Fac" type="L3STRING">
	/// Ϳ�ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Daub_Fac)

	/// <Property class="CTundish_OT_Install" name="Fra_Case" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Fra_Case)

	/// <Property class="CTundish_OT_Install" name="Slip_Blo_Fac" type="L3STRING">
	/// ���鳧��
	/// </Property>
	DECLARE_L3PROP_STRING(Slip_Blo_Fac)

	/// <Property class="CTundish_OT_Install" name="Gap_Fac" type="L3STRING">
	/// ��ˮ�ڳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Gap_Fac)

	/// <Property class="CTundish_OT_Install" name="Install_Per" type="L3STRING">
	/// ��װ��
	/// </Property>
	DECLARE_L3PROP_STRING(Install_Per)

	/// <Property class="CTundish_OT_Install" name="Install_Time" type="L3DATETIME">
	/// ��װ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Time)

	/// <Property class="CTundish_OT_Install" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)
	
	/// <Property class="CTundish_OT_Install" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};

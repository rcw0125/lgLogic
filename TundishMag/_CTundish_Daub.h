// �߼���CTundish_Daubͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_Daub :
	public CL3Object
{
public:
	CTundish_Daub(void);
	virtual ~CTundish_Daub(void);

	DECLARE_L3CLASS(CTundish_Daub,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Daub)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTundish_Daub" name="TundishID" type="L3STRING">
	/// �а���
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_Daub" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_Daub" name="InnerID" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Daub" name="Inner_Use_Count" type="L3SHORT">
	/// ���ò�ʹ�ô���
	/// </Property>
	DECLARE_L3PROP_SHORT(Inner_Use_Count)

	/// <Property class="CTundish_Daub" name="Cast_ID" type="L3STRING">
	/// ȥ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_Daub" name="Project" type="L3STRING">
	/// ��Ŀ
	/// </Property>
	DECLARE_L3PROP_STRING(Project)

	/// <Property class="CTundish_Daub" name="Gap_Bri_Fac" type="L3STRING">
	/// ��ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Gap_Bri_Fac)

	/// <Property class="CTundish_Daub" name="Gap_Bri_Consume" type="L3DOUBLE">
	/// ��ש������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gap_Bri_Consume)

	/// <Property class="CTundish_Daub" name="Ward_Dregs_Fac" type="L3STRING">
	/// ����ǽ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ward_Dregs_Fac)

	/// <Property class="CTundish_Daub" name="Ward_Dregs_Consume" type="L3DOUBLE">
	/// ����ǽ������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ward_Dregs_Consume)

	/// <Property class="CTundish_Daub" name="Tranq_Fac" type="L3STRING">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_STRING(Tranq_Fac)

	/// <Property class="CTundish_Daub" name="Tranq_Consume" type="L3DOUBLE">
	/// ������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tranq_Consume)

	/// <Property class="CTundish_Daub" name="Daub_Fac" type="L3STRING">
	/// ͿĨ�ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Daub_Fac)

	/// <Property class="CTundish_Daub" name="Daub_Consume" type="L3DOUBLE">
	/// ͿĨ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Daub_Consume)

	/// <Property class="CTundish_Daub" name="Dry_Flap_Fac" type="L3STRING">
	/// �����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Dry_Flap_Fac)

	/// <Property class="CTundish_Daub" name="Dry_Flap_Consume" type="L3DOUBLE">
	/// ������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Dry_Flap_Consume)

	/// <Property class="CTundish_Daub" name="Gluemud_Fac" type="L3STRING">
	/// ���೧��
	/// </Property>
	DECLARE_L3PROP_STRING(Gluemud_Fac)

	/// <Property class="CTundish_Daub" name="Gluemud_Consume" type="L3DOUBLE">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gluemud_Consume)

	/// <Property class="CTundish_Daub" name="Daub_Start_Time" type="L3DATETIME">
	/// ͿĨ(����)��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Daub_Start_Time)

	/// <Property class="CTundish_Daub" name="Daub_End_Time" type="L3DATETIME">
	/// ͿĨ(����)����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Daub_End_Time)

	/// <Property class="CTundish_Daub" name="Fire_Start_Time" type="L3DATETIME">
	/// �濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CTundish_Daub" name="Fire_End_Time" type="L3DATETIME">
	/// �濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CTundish_Daub" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_Daub" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_Daub" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_Daub" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_Daub" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};

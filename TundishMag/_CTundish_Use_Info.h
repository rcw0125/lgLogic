// �߼���CTundish_Use_Infoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_Use_Info :
	public CL3Object
{
public:
	CTundish_Use_Info(void);
	virtual ~CTundish_Use_Info(void);

	DECLARE_L3CLASS(CTundish_Use_Info,XGMESLogic\\TundishMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Use_Info)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTundish_Use_Info" name="Creat_Time" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Creat_Time)

	/// <Property class="CTundish_Use_Info" name="TundishID" type="L3STRING">
	/// �а�����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_Use_Info" name="TundishNO" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNO)

	/// <Property class="CTundish_Use_Info" name="InnerID" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Use_Info" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_Use_Info" name="Vehicle_ID" type="L3STRING">
	/// �а�����
	/// </Property>
	DECLARE_L3PROP_STRING(Vehicle_ID)

	/// <Property class="CTundish_Use_Info" name="Cast_ID" type="L3STRING">
	/// ȥ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_Use_Info" name="Inner_Tie_Start_Time" type="L3DATETIME">
	/// ���ò��Ὺʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Inner_Tie_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Inner_Tie_End_Time" type="L3DATETIME">
	/// ���ò������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Inner_Tie_End_Time)

	/// <Property class="CTundish_Use_Info" name="Inner_Small_Fire_Time" type="L3DATETIME">
	/// ���ò㿪ʼ�濾ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Inner_Small_Fire_Time)

	/// <Property class="CTundish_Use_Info" name="Inner_Close_Fire_Time" type="L3DATETIME">
	/// ���ò�����濾ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Inner_Close_Fire_Time)

	/// <Property class="CTundish_Use_Info" name="Daub_Start_Time" type="L3DATETIME">
	/// ͿĨ(����)��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Daub_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Daub_End_Time" type="L3DATETIME">
	/// ͿĨ(����)����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Daub_End_Time)

	/// <Property class="CTundish_Use_Info" name="Fire_Start_Time" type="L3DATETIME">
	/// ������濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Fire_End_Time" type="L3DATETIME">
	/// ������濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CTundish_Use_Info" name="Install_Start_Time" type="L3DATETIME">
	/// �ϼ���ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Install_End_Time" type="L3DATETIME">
	/// �ϼ�����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_End_Time)

	/// <Property class="CTundish_Use_Info" name="Hot_Small_Start_Time" type="L3DATETIME">
	/// �ȱ��濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Hot_Small_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Hot_Big_End_Time" type="L3DATETIME">
	/// �ȱ��濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Hot_Big_End_Time)

	/// <Property class="CTundish_Use_Info" name="Cast_Start_Time" type="L3DATETIME">
	/// �а�����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Cast_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Cast_End_Time" type="L3DATETIME">
	/// �а�����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Cast_End_Time)

	/// <Property class="CTundish_Use_Info" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};

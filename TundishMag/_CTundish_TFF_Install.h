// �߼���CTundish_TFF_Installͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_TFF_Install :
	public CL3Object
{
public:
	CTundish_TFF_Install(void);
	virtual ~CTundish_TFF_Install(void);

	DECLARE_L3CLASS(CTundish_TFF_Install,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_TFF_Install)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTundish_TFF_Install" name="TundishID" type="L3STRING">
	/// �а���
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_TFF_Install" name="WorkID" type="L3STRING">
	/// �а���������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_TFF_Install" name="Daub_Fac" type="L3STRING">
	/// Ϳ�ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Daub_Fac)

	/// <Property class="CTundish_TFF_Install" name="Refra_Fac" type="L3STRING">
	/// �Ͳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CTundish_TFF_Install" name="Fra_Switch_Case" type="L3STRING">
	/// ����բ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Fra_Switch_Case)

	/// <Property class="CTundish_TFF_Install" name="Con_Per" type="L3STRING">
	/// ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Con_Per)

	/// <Property class="CTundish_TFF_Install" name="Gap_Fac" type="L3STRING">
	/// ��ˮ�ڳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Gap_Fac)

	/// <Property class="CTundish_TFF_Install" name="Gap_Pro_Date" type="L3DATETIME">
	/// ˮ����������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Gap_Pro_Date)

	/// <Property class="CTundish_TFF_Install" name="First_Gap_ID" type="L3STRING">
	/// 1��ˮ�ڱ��
	/// </Property>
	DECLARE_L3PROP_STRING(First_Gap_ID)

	/// <Property class="CTundish_TFF_Install" name="Second_Gap_ID" type="L3STRING">
	/// 2��ˮ�ڱ��
	/// </Property>
	DECLARE_L3PROP_STRING(Second_Gap_ID)

	/// <Property class="CTundish_TFF_Install" name="Third_Gap_ID" type="L3STRING">
	/// 3��ˮ�ڱ��
	/// </Property>
	DECLARE_L3PROP_STRING(Third_Gap_ID)

	/// <Property class="CTundish_TFF_Install" name="Fourth_Gap_ID" type="L3STRING">
	/// 4��ˮ�ڱ��
	/// </Property>
	DECLARE_L3PROP_STRING(Fourth_Gap_ID)

	/// <Property class="CTundish_TFF_Install" name="Stu_Sti_Fac" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Stu_Sti_Fac)

	/// <Property class="CTundish_TFF_Install" name="Stu_Sti_Pro_Date" type="L3DATETIME">
	/// ������������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Stu_Sti_Pro_Date)

	/// <Property class="CTundish_TFF_Install" name="First_Stu_Sti_ID" type="L3STRING">
	/// 1���������
	/// </Property>
	DECLARE_L3PROP_STRING(First_Stu_Sti_ID)

	/// <Property class="CTundish_TFF_Install" name="Second_Stu_Sti_ID" type="L3STRING">
	/// 2���������
	/// </Property>
	DECLARE_L3PROP_STRING(Second_Stu_Sti_ID)

	/// <Property class="CTundish_TFF_Install" name="Third_Stu_Sti_ID" type="L3STRING">
	/// 3���������
	/// </Property>
	DECLARE_L3PROP_STRING(Third_Stu_Sti_ID)

	/// <Property class="CTundish_TFF_Install" name="Fourth_Stu_Sti_ID" type="L3STRING">
	/// 4���������
	/// </Property>
	DECLARE_L3PROP_STRING(Fourth_Stu_Sti_ID)

	/// <Property class="CTundish_TFF_Install" name="Install_Per" type="L3STRING">
	/// ��װ��
	/// </Property>
	DECLARE_L3PROP_STRING(Install_Per)

	/// <Property class="CTundish_TFF_Install" name="Install_Time" type="L3DATETIME">
	/// ��װ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Time)

	/// <Property class="CTundish_TFF_Install" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)
	
	/// <Property class="CTundish_TFF_Install" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};

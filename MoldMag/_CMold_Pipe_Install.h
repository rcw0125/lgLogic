// �߼���CMold_Pipe_Installͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMold_Pipe_Install :
	public CL3Object
{
public:
	CMold_Pipe_Install(void);
	virtual ~CMold_Pipe_Install(void);

	DECLARE_L3CLASS(CMold_Pipe_Install,XGMESLogic\\MoldMag, InStallID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Pipe_Install)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CMold_Pipe_Install" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CMold_Pipe_Install" name="Install_Date" type="L3DATETIME">
	/// ��װ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Date)

	/// <Property class="CMold_Pipe_Install" name="MoldID" type="L3STRING">
	/// �ᾧ�����
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CMold_Pipe_Install" name="Hit_Press_Flag" type="L3LONG">
	/// ��ѹ�Ƿ�ϸ�
	/// </Property>
	DECLARE_L3PROP_LONG(Hit_Press_Flag)

	/// <Property class="CMold_Pipe_Install" name="Copper_ID" type="L3STRING">
	/// ͭ�ܱ��
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_ID)

	/// <Property class="CMold_Pipe_Install" name="Copper_Fac" type="L3STRING">
	/// ͭ�ܳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CMold_Pipe_Install" name="Install_Per" type="L3STRING">
	/// װ����
	/// </Property>
	DECLARE_L3PROP_STRING(Install_Per)

	/// <Property class="CMold_Pipe_Install" name="Repair_Start_Time" type="L3DATETIME">
	/// ά�޿�ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Repair_Start_Time)

	/// <Property class="CMold_Pipe_Install" name="Repair_End_Time" type="L3DATETIME">
	/// ά�޽���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Repair_End_Time)

	/// <Property class="CMold_Pipe_Install" name="Repair_Content" type="L3STRING">
	/// ά������
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Content)

	/// <Property class="CMold_Pipe_Install" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CMold_Pipe_Install" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CMold_Pipe_Install" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CMold_Pipe_Install" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CMold_Pipe_Install" name="InStallID" type="L3STRING">
	/// װ����
	/// </Property>
	DECLARE_L3PROP_STRING(InStallID)
	
	/// <Property class="CMold_Pipe_Install" name="ConfirmFlag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(ConfirmFlag)

};

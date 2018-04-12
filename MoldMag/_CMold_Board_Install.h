// �߼���CMold_Board_Installͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMold_Board_Install :
	public CL3Object
{
public:
	CMold_Board_Install(void);
	virtual ~CMold_Board_Install(void);

	DECLARE_L3CLASS(CMold_Board_Install,XGMESLogic\\MoldMag, InStallID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Board_Install)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CMold_Board_Install" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CMold_Board_Install" name="Install_Date" type="L3DATETIME">
	/// ��װ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Date)

	/// <Property class="CMold_Board_Install" name="MoldID" type="L3STRING">
	/// �ᾧ�����
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CMold_Board_Install" name="Hit_Press_Flag" type="L3LONG">
	/// ��ѹ�Ƿ�ϸ�
	/// </Property>
	DECLARE_L3PROP_LONG(Hit_Press_Flag)

	/// <Property class="CMold_Board_Install" name="Copper_Fac" type="L3STRING">
	/// ͭ�峧��
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CMold_Board_Install" name="Repair_Fac" type="L3STRING">
	/// ͭ���޸�����
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Fac)

	/// <Property class="CMold_Board_Install" name="Rep_Count" type="L3LONG">
	/// ͭ���޸�����
	/// </Property>
	DECLARE_L3PROP_LONG(Rep_Count)

	/// <Property class="CMold_Board_Install" name="Inner_ID" type="L3STRING">
	/// ͭ���ڻ����
	/// </Property>
	DECLARE_L3PROP_STRING(Inner_ID)

	/// <Property class="CMold_Board_Install" name="Outer_ID" type="L3STRING">
	/// ͭ���⻡���
	/// </Property>
	DECLARE_L3PROP_STRING(Outer_ID)

	/// <Property class="CMold_Board_Install" name="South_ID" type="L3STRING">
	/// ͭ���ϲ���
	/// </Property>
	DECLARE_L3PROP_STRING(South_ID)

	/// <Property class="CMold_Board_Install" name="North_ID" type="L3STRING">
	/// ͭ�山����
	/// </Property>
	DECLARE_L3PROP_STRING(North_ID)

	/// <Property class="CMold_Board_Install" name="Lug_Steel_Mea" type="L3DOUBLE">
	/// ͭ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Lug_Steel_Mea)

	/// <Property class="CMold_Board_Install" name="Repair_Start_Time" type="L3DATETIME">
	/// ά�޿�ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Repair_Start_Time)

	/// <Property class="CMold_Board_Install" name="Repair_End_Time" type="L3DATETIME">
	/// ά�޽���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Repair_End_Time)

	/// <Property class="CMold_Board_Install" name="Install_Per" type="L3STRING">
	/// װ����
	/// </Property>
	DECLARE_L3PROP_STRING(Install_Per)

	/// <Property class="CMold_Board_Install" name="Wide_Up_Two_Fir" type="L3DOUBLE">
	/// ������Ͽ�200mm��1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Two_Fir)

	/// <Property class="CMold_Board_Install" name="Wide_Up_Two_Sec" type="L3DOUBLE">
	/// ������Ͽ�200mm��2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Two_Sec)

	/// <Property class="CMold_Board_Install" name="Wide_Up_Two_Thi" type="L3DOUBLE">
	/// ������Ͽ�200mm��3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Two_Thi)

	/// <Property class="CMold_Board_Install" name="Wide_Up_Three_Fir" type="L3DOUBLE">
	/// ������Ͽ�300mm��1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Three_Fir)

	/// <Property class="CMold_Board_Install" name="Wide_Up_Three_Sec" type="L3DOUBLE">
	/// ������Ͽ�300mm��2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Three_Sec)

	/// <Property class="CMold_Board_Install" name="Wide_Up_Three_Thi" type="L3DOUBLE">
	/// ������Ͽ�300mm��3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Up_Three_Thi)

	/// <Property class="CMold_Board_Install" name="Wide_Down_Eight_Fir" type="L3DOUBLE">
	/// ������¿�80mm��1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Down_Eight_Fir)

	/// <Property class="CMold_Board_Install" name="Wide_Down_Eight_Sec" type="L3DOUBLE">
	/// ������¿�80mm��2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Down_Eight_Sec)

	/// <Property class="CMold_Board_Install" name="Wide_Down_Eight_Thi" type="L3DOUBLE">
	/// ������¿�80mm��3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wide_Down_Eight_Thi)

	/// <Property class="CMold_Board_Install" name="Nar_Up_Two_Fir" type="L3DOUBLE">
	/// խ����Ͽ�200mm��1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Two_Fir)

	/// <Property class="CMold_Board_Install" name="Nar_Up_Two_Sec" type="L3DOUBLE">
	/// խ����Ͽ�200mm��2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Two_Sec)

	/// <Property class="CMold_Board_Install" name="Nar_Up_Two_Thi" type="L3DOUBLE">
	/// խ����Ͽ�200mm��3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Two_Thi)

	/// <Property class="CMold_Board_Install" name="Nar_Up_Three_Fir" type="L3DOUBLE">
	/// խ����Ͽ�300mm��1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Three_Fir)

	/// <Property class="CMold_Board_Install" name="Nar_Up_Three_Sec" type="L3DOUBLE">
	/// խ����Ͽ�300mm��2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Three_Sec)

	/// <Property class="CMold_Board_Install" name="Nar_Up_Three_Thi" type="L3DOUBLE">
	/// խ����Ͽ�300mm��3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Up_Three_Thi)

	/// <Property class="CMold_Board_Install" name="Nar_Down_Eight_Fir" type="L3DOUBLE">
	/// խ����¿�80mm��1[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Down_Eight_Fir)

	/// <Property class="CMold_Board_Install" name="Nar_Down_Eight_Sec" type="L3DOUBLE">
	/// խ����¿�80mm��2[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Down_Eight_Sec)

	/// <Property class="CMold_Board_Install" name="Nar_Down_Eight_Thi" type="L3DOUBLE">
	/// խ����¿�80mm��3[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nar_Down_Eight_Thi)

	/// <Property class="CMold_Board_Install" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CMold_Board_Install" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CMold_Board_Install" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CMold_Board_Install" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CMold_Board_Install" name="InStallID" type="L3STRING">
	/// װ����
	/// </Property>
	DECLARE_L3PROP_STRING(InStallID)
	
	/// <Property class="CMold_Board_Install" name="ConfirmFlag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(ConfirmFlag)


};

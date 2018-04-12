// �߼���CMold_Pipe_Par_Useͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMold_Pipe_Par_Use :
	public CL3Object
{
public:
	CMold_Pipe_Par_Use(void);
	virtual ~CMold_Pipe_Par_Use(void);

	DECLARE_L3CLASS(CMold_Pipe_Par_Use,XGMESLogic\\MoldMag, InStallID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Pipe_Par_Use)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CMold_Pipe_Par_Use" name="Input_Time" type="L3DATETIME">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CMold_Pipe_Par_Use" name="MoldID" type="L3STRING">
	/// �ᾧ�����
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CMold_Pipe_Par_Use" name="Copper_ID" type="L3STRING">
	/// ͭ�ܱ��
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_ID)

	/// <Property class="CMold_Pipe_Par_Use" name="Copper_Fac" type="L3STRING">
	/// ͭ�ܳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CMold_Pipe_Par_Use" name="Cur_Use_Count" type="L3LONG">
	/// ����ʹ�ô���
	/// </Property>
	DECLARE_L3PROP_LONG(Cur_Use_Count)

	/// <Property class="CMold_Pipe_Par_Use" name="Total_Use_Count" type="L3LONG">
	/// ʹ�ô����ۼ�
	/// </Property>
	DECLARE_L3PROP_LONG(Total_Use_Count)

	/// <Property class="CMold_Pipe_Par_Use" name="Cur_Pull_Mea" type="L3DOUBLE">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cur_Pull_Mea)

	/// <Property class="CMold_Pipe_Par_Use" name="Total_Pull_Mea" type="L3DOUBLE">
	/// �������ۼ�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Total_Pull_Mea)

	/// <Property class="CMold_Pipe_Par_Use" name="Cast_ID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CMold_Pipe_Par_Use" name="FlowID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(FlowID)

	/// <Property class="CMold_Pipe_Par_Use" name="OnLine_Flag" type="L3LONG">
	/// ���߱�־
	/// </Property>
	DECLARE_L3PROP_LONG(OnLine_Flag)

	/// <Property class="CMold_Pipe_Par_Use" name="OnLine_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(OnLine_Time)

	/// <Property class="CMold_Pipe_Par_Use" name="Stop_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Stop_Reason)

	/// <Property class="CMold_Pipe_Par_Use" name="OffLine_Flag" type="L3LONG">
	/// ���߱�־
	/// </Property>
	DECLARE_L3PROP_LONG(OffLine_Flag)

	/// <Property class="CMold_Pipe_Par_Use" name="OffLine_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(OffLine_Time)

	/// <Property class="CMold_Pipe_Par_Use" name="Ruler" type="L3DOUBLE">
	/// ����[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ruler)

	/// <Property class="CMold_Pipe_Par_Use" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CMold_Pipe_Par_Use" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CMold_Pipe_Par_Use" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CMold_Pipe_Par_Use" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CMold_Pipe_Par_Use" name="InStallID" type="L3STRING">
	/// װ����
	/// </Property>
	DECLARE_L3PROP_STRING(InStallID)
	
	/// <Property class="CMold_Pipe_Par_Use" name="ConfirmFlag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(ConfirmFlag)

};

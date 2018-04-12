// �߼���CLF_Ladle_Infoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_Ladle_Info :
	public CL3Object
{
public:
	CLF_Ladle_Info(void);
	virtual ~CLF_Ladle_Info(void);

	DECLARE_L3CLASS(CLF_Ladle_Info,XGMESLogic\\LFMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Ladle_Info)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_Ladle_Info" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Ladle_Info" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Ladle_Info" name="LadleID" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLF_Ladle_Info" name="Last_Ladle_Grade" type="L3STRING">
	/// �ϴΰ���
	/// </Property>
	DECLARE_L3PROP_STRING(Last_Ladle_Grade)

	
	/// <Property class="CLF_Ladle_Info" name="Temp" type="L3LONG">
	/// �ϴ�20'�½�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)

	/// <Property class="CLF_Ladle_Info" name="Last_SteelGrade" type="L3STRING">
	/// �ϴ�ʹ�ø���
	/// </Property>
	DECLARE_L3PROP_STRING(Last_SteelGrade)

	/// <Property class="CLF_Ladle_Info" name="Act_Ladle_Grade" type="L3STRING">
	/// ��ǰ����
	/// </Property>
	DECLARE_L3PROP_STRING(Act_Ladle_Grade)

	/// <Property class="CLF_Ladle_Info" name="Cur_SteelGrade" type="L3STRING">
	/// ��ǰʹ�ø���
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_SteelGrade)

	/// <Property class="CLF_Ladle_Info" name="In_Ladle_Grade" type="L3STRING">
	/// ��վ����
	/// </Property>
	DECLARE_L3PROP_STRING(In_Ladle_Grade)

	/// <Property class="CLF_Ladle_Info" name="Stop_Time_Len" type="L3LONG">
	/// ͣ��ʱ��[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Stop_Time_Len)

	/// <Property class="CLF_Ladle_Info" name="Ladle_Age" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Age)

	/// <Property class="CLF_Ladle_Info" name="Small_Fire" type="L3LONG">
	/// С��ʱ��[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Small_Fire)

	/// <Property class="CLF_Ladle_Info" name="Middle_Fire" type="L3LONG">
	/// �л�ʱ��[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Middle_Fire)

	/// <Property class="CLF_Ladle_Info" name="Big_Fire" type="L3LONG">
	/// ���ʱ��[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Big_Fire)

	/// <Property class="CLF_Ladle_Info" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLF_Ladle_Info" name="Other1" type="L3STRING">
	/// Ԥ��1
	/// </Property>
	DECLARE_L3PROP_STRING(Other1)

	
	/// <Property class="CLF_Ladle_Info" name="Other2" type="L3STRING">
	/// Ԥ��2
	/// </Property>
	DECLARE_L3PROP_STRING(Other2)

	
	/// <Property class="CLF_Ladle_Info" name="Other3" type="L3STRING">
	/// Ԥ��3
	/// </Property>
	DECLARE_L3PROP_STRING(Other3)

	/// <Property class="CLF_Ladle_Info" name="MaxTemp" type="L3LONG">
	/// �ϴ�ת���½�
	/// </Property>
	DECLARE_L3PROP_LONG(MaxTemp)

};

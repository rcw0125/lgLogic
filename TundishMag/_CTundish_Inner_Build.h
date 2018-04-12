// �߼���CTundish_Inner_Buildͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_Inner_Build :
	public CL3Object
{
public:
	CTundish_Inner_Build(void);
	virtual ~CTundish_Inner_Build(void);

	DECLARE_L3CLASS(CTundish_Inner_Build,XGMESLogic\\TundishMag, InnerID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Inner_Build)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTundish_Inner_Build" name="TundishID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_Inner_Build" name="InnerID" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Inner_Build" name="Inner_Use_Count" type="L3SHORT">
	/// ���ò�ʹ�ô���
	/// </Property>
	DECLARE_L3PROP_SHORT(Inner_Use_Count)

	/// <Property class="CTundish_Inner_Build" name="Tie_Start_Time" type="L3DATETIME">
	/// ��ʼ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_Start_Time)

	/// <Property class="CTundish_Inner_Build" name="Tie_End_Time" type="L3DATETIME">
	/// �������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_End_Time)

	/// <Property class="CTundish_Inner_Build" name="Refra_Fac" type="L3STRING">
	/// �ͲĲ���
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CTundish_Inner_Build" name="Refra_ID" type="L3STRING">
	/// �Ͳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_ID)

	/// <Property class="CTundish_Inner_Build" name="Waste" type="L3DOUBLE">
	/// ������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waste)

	/// <Property class="CTundish_Inner_Build" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_Inner_Build" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_Inner_Build" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_Inner_Build" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_Inner_Build" name="Check_Date" type="L3DATETIME">
	/// �������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	
	/// <Property class="CTundish_Inner_Build" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	

};

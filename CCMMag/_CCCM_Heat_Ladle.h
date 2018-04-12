// �߼���CCCM_Heat_Ladleͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_Ladle :
	public CL3Object
{
public:
	CCCM_Heat_Ladle(void);
	virtual ~CCCM_Heat_Ladle(void);

	DECLARE_L3CLASS(CCCM_Heat_Ladle,XGMESLogic\\CCMMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Ladle)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	///2009-02-13 ����Ƿ��Զ������� ���Զ�����ԭ��

	/// <Property class="CCCM_Heat_Ladle" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Ladle" name="TreatNo" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Heat_Ladle" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Ladle" name="LadleID" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CCCM_Heat_Ladle" name="Weight" type="L3FLOAT">
	/// �������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CCCM_Heat_Ladle" name="RemainWeight" type="L3FLOAT">
	/// ���ʣ���ˮ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(RemainWeight)

	/// <Property class="CCCM_Heat_Ladle" name="Arrival_Time" type="L3DATETIME">
	/// �������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CCCM_Heat_Ladle" name="LadleType" type="L3STRING">
	/// �ְ����
	/// </Property>
	DECLARE_L3PROP_STRING(LadleType)

	/// <Property class="CCCM_Heat_Ladle" name="Departure_Time" type="L3DATETIME">
	/// ����뿪ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Departure_Time)

	/// <Property class="CCCM_Heat_Ladle" name="Casting_Start_Time" type="L3DATETIME">
	/// �������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Start_Time)

	/// <Property class="CCCM_Heat_Ladle" name="Casting_Stop_Time" type="L3DATETIME">
	/// ���ͣ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Stop_Time)

	/// <Property class="CCCM_Heat_Ladle" name="HoldTime" type="L3LONG">
	/// ��ѹ��ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(HoldTime)

	/// <Property class="CCCM_Heat_Ladle" name="Temp" type="L3LONG">
	/// �ϻ��¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)

	/// <Property class="CCCM_Heat_Ladle" name="TempUpTo" type="L3SHORT">
	/// 
	/// �¶��Ƿ�ϸ�
	/// (1-�ϸ�
	///  0-���ϸ�)
	/// </Property>
	DECLARE_L3PROP_SHORT(TempUpTo)

	/// <Property class="CCCM_Heat_Ladle" name="HoldTime_Reason" type="L3STRING">
	/// ��ѹ�ֳ�ʱԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(HoldTime_Reason)

	/// <Property class="CCCM_Heat_Ladle" name="Protection" type="L3SHORT">
	/// 
	/// �Ƿ���������ע
	/// (0-��
	///  1-��)
	/// </Property>
	DECLARE_L3PROP_SHORT(Protection)

	/// <Property class="CCCM_Heat_Ladle" name="UnProtection_Reason" type="L3STRING">
	/// 
	/// δ���д��������עԭ��
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(UnProtection_Reason)

	/// <Property class="CCCM_Heat_Ladle" name="UnProtection_Reason" type="L3LONG">
	/// 
	/// �Ƿ��Զ�����
	/// 
	/// </Property>
	DECLARE_L3PROP_LONG(AutoFlow)

	/// <Property class="CCCM_Heat_Ladle" name="UnAutoFlow_Reason" type="L3STRING">
	/// 
	/// ���Զ�����ԭ��
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(UnAutoFlow_Reason)


	/// <Property class="CCCM_Heat_Ladle" name="CastingTundishWeight" type="L3FLOAT">
	/// �������ʱ�а�����
	/// </Property>
	DECLARE_L3PROP_FLOAT(CastingTundishWeight)

};

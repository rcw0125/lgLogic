// �߼���CCCM_Tundish_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Tundish_Data :
	public CL3Object
{
public:
	CCCM_Tundish_Data(void);
	virtual ~CCCM_Tundish_Data(void);

	DECLARE_L3CLASS(CCCM_Tundish_Data,XGMESLogic\\CCMMag, TundishNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Tundish_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	///2009-02-13 ɾ���а���������ʡ��а���������ء��а�����ǽ���а�����ǽ���ҡ�
	///�а�����ǽ���ʡ�Ԥ��С��ʼʱ�̡�Ԥ���л�ʼʱ�̡�Ԥ�ȴ��ʼʱ�̡�Ԥ�Ƚ���ʱ�̡�
	///Ԥ�Ƚ����а��������¶ȡ�Ԥ�Ƚ�������ʽˮ���¶ȡ�����ʽˮ���ͺš�����ʽˮ�ڲ��ء�
	///�����ͺš��������ء��а��Ǳ�š��а��Ǳ�š��а�����Ʒ���а����ڷϡ��а����Ǽ����ơ��а����Ǽ�����
	///���ӣ����ο�ʼʱ�̡����ν���ʱ��

	/// <Property class="CCCM_Tundish_Data" name="TundishNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_Tundish_Data" name="CastingNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Tundish_Data" name="TundishID" type="L3STRING">
	/// �а���
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CCCM_Tundish_Data" name="Tundish_CarID" type="L3STRING">
	/// �а�����
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_CarID)

	/// <Property class="CCCM_Casting_Data" name="First_HeatID" type="L3STRING">
	/// ���ε�һ¯
	/// </Property>
	DECLARE_L3PROP_STRING(First_HeatID)

	/// <Property class="CCCM_Casting_Data" name="Last_HeatID" type="L3STRING">
	/// �������һ¯
	/// </Property>
	DECLARE_L3PROP_STRING(Last_HeatID)

	/// <Property class="CCCM_Casting_Data" name="HeatCount" type="L3LONG">
	/// ��ǰ������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(HeatCount)


	/// <Property class="CCCM_Tundish_Data" name="Fender_Slag_Usage Case" type="L3STRING">
	/// �а�����ǽʹ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Fender_Slag_Usage_Case)

	/// <Property class="CCCM_Tundish_Data" name="Cover_Factory" type="L3STRING">
	/// �а��ǲ���
	/// </Property>
	DECLARE_L3PROP_STRING(Cover_Factory)


	/// <Property class="CCCM_Tundish_Data" name="Reason_Holt_Casting" type="L3STRING">
	/// ͣ��ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason_Holt_Casting)

	
	/// <Property class="CCCM_Tundish_Data" name="Remain_Steel_Weight" type="L3DOUBLE">
	/// �а������ˮ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Remain_Steel_Weight)

	/// <Property class="CCCM_Tundish_Data" name="Casting_Start_Time" type="L3DATETIME">
	/// ���ο�ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Start_Time)

	/// <Property class="CCCM_Tundish_Data" name="Casting_Stop_Time" type="L3DATETIME">
	/// ���ν���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Stop_Time)	

	/// <Property class="CCCM_Tundish_Data" name="WorkID" type="L3STRING">
	/// �а���������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

};

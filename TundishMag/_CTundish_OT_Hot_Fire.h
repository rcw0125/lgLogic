// �߼���CTundish_OT_Hot_Fireͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_OT_Hot_Fire :
	public CL3Object
{
public:
	CTundish_OT_Hot_Fire(void);
	virtual ~CTundish_OT_Hot_Fire(void);

	DECLARE_L3CLASS(CTundish_OT_Hot_Fire,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_OT_Hot_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();


	/// <Property class="CTundish_OT_Hot_Fire" name="TundishID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_OT_Hot_Fire" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Cast_ID" type="L3STRING">
	/// ȥ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_OT_Hot_Fire" name="VehicleID" type="L3STRING">
	/// �а�����
	/// </Property>
	DECLARE_L3PROP_STRING(VehicleID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Adjust_Per" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Adjust_Per)

	/// <Property class="CTundish_OT_Hot_Fire" name="Adjust_TeamID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Adjust_TeamID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Crane_TeamID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Crane_TeamID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Move_Case" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Move_Case)

	/// <Property class="CTundish_OT_Hot_Fire" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_OT_Hot_Fire" name="First_Hyd_Pre" type="L3DOUBLE">
	/// һ��Һѹ���г�[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(First_Hyd_Pre)

	/// <Property class="CTundish_OT_Hot_Fire" name="Second_Hyd_Pre" type="L3DOUBLE">
	/// ����Һѹ���г�[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Second_Hyd_Pre)

	/// <Property class="CTundish_OT_Hot_Fire" name="Third_Hyd_Pre" type="L3DOUBLE">
	/// ����Һѹ���г�[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Third_Hyd_Pre)

	/// <Property class="CTundish_OT_Hot_Fire" name="Fourth_Hyd_Pre" type="L3DOUBLE">
	/// ����Һѹ���г�[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fourth_Hyd_Pre)

	/// <Property class="CTundish_OT_Hot_Fire" name="Fire_Start_Time" type="L3DATETIME">
	/// �濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CTundish_OT_Hot_Fire" name="Fire_End_Time" type="L3DATETIME">
	/// �濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CTundish_OT_Hot_Fire" name="Fire_Temp" type="L3DOUBLE">
	/// �濾�¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fire_Temp)

	/// <Property class="CTundish_OT_Hot_Fire" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_OT_Hot_Fire" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_OT_Hot_Fire" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_OT_Hot_Fire" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

};

// �߼���CVacTube_Fireͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CVacTube_Fire :
	public CL3Object
{
public:
	CVacTube_Fire(void);
	virtual ~CVacTube_Fire(void);

	DECLARE_L3CLASS(CVacTube_Fire,XGMESLogic\\VacTubeMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Fire" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)
	
	/// <Property class="CVacTube_Fire" name="VacTube_Code" type="L3STRING">
	/// ��ղ۱��
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Code)

	/// <Property class="CVacTube_Fire" name="Install_ID" type="L3STRING">
	/// ��װ���
	/// </Property>
	DECLARE_L3PROP_STRING(Install_ID)

	/// <Property class="CVacTube_Fire" name="Position" type="L3STRING">
	/// λ��
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CVacTube_Fire" name="Up_Slot_ID" type="L3STRING">
	/// �ϲ��۱��
	/// </Property>
	DECLARE_L3PROP_STRING(Up_Slot_ID)

	/// <Property class="CVacTube_Fire" name="Bel_Slot_ID" type="L3STRING">
	/// �²��۱��
	/// </Property>
	DECLARE_L3PROP_STRING(Bel_Slot_ID)

	/// <Property class="CVacTube_Fire" name="Fire_Start_Time" type="L3DATETIME">
	/// ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CVacTube_Fire" name="Fire_End_Time" type="L3DATETIME">
	/// ͣ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CVacTube_Fire" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Fire" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Fire" name="Log_Per" type="L3STRING">
	/// ��¼��
	/// </Property>
	DECLARE_L3PROP_STRING(Log_Per)

	/// <Property class="CVacTube_Fire" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CVacTube_Fire" name="Object_ID" type="L3STRING">
	/// ���� ��װ��� + �濾����
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

	/// <Property class="CVacTube_Fire" name="Fire_Soruce" type="L3LONG">
	/// �濾�ź���Դ(0�Զ��ɼ���1�˹���Ԥ)
	/// </Property>
	DECLARE_L3PROP_LONG(Fire_Soruce)


};

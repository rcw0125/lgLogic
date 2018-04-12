// �߼���CVacTube_Fire_Info_Infoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CVacTube_Fire_Info :
	public CL3Object
{
public:
	CVacTube_Fire_Info(void);
	virtual ~CVacTube_Fire_Info(void);

	DECLARE_L3CLASS(CVacTube_Fire_Info,XGMESLogic\\VacTubeMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Fire_Info)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Fire_Info" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Fire_Info" name="VacTube_Code" type="L3STRING">
	/// ��ղ۱��
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Code)

	/// <Property class="CVacTube_Fire_Info" name="Install_ID" type="L3STRING">
	/// ��װ���
	/// </Property>
	DECLARE_L3PROP_STRING(Install_ID)

	/// <Property class="CVacTube_Fire_Info" name="Time_ID" type="L3LONG">
	/// ʱ��[H]
	/// </Property>
	DECLARE_L3PROP_LONG(Time_ID)

	/// <Property class="CVacTube_Fire_Info" name="Position" type="L3STRING">
	/// λ��
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CVacTube_Fire_Info" name="Fact_Temp" type="L3DOUBLE">
	/// ʵ���¶�[��]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fact_Temp)

	/// <Property class="CVacTube_Fire_Info" name="Gun_Height" type="L3DOUBLE">
	/// ǹλ�߶�[m]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gun_Height)

	/// <Property class="CVacTube_Fire_Info" name="Gas_Flow" type="L3DOUBLE">
	/// ú������[Nm3/h]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gas_Flow)

	/// <Property class="CVacTube_Fire_Info" name="O2_Flow" type="L3DOUBLE">
	/// ��������[Nm3/h]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(O2_Flow)

	/// <Property class="CVacTube_Fire_Info" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Fire_Info" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Fire_Info" name="Log_Per" type="L3STRING">
	/// ��¼��
	/// </Property>
	DECLARE_L3PROP_STRING(Log_Per)

	/// <Property class="CVacTube_Fire_Info" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CVacTube_Fire_Info" name="Object_ID" type="L3STRING">
	/// ����Ϣ���� ��װ��� + �濾����
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

	/// <Property class="CVacTube_Fire_Info" name="Fire_Soruce" type="L3LONG">
	/// �濾�ź���Դ(0�Զ��ɼ���1�˹���Ԥ)
	/// </Property>
	DECLARE_L3PROP_LONG(Fire_Soruce)

};

// �߼���CVacTube_Repairͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CVacTube_Repair :
	public CL3Object
{
public:
	CVacTube_Repair(void);
	virtual ~CVacTube_Repair(void);

	DECLARE_L3CLASS(CVacTube_Repair,XGMESLogic\\VacTubeMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Repair)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Repair" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Repair" name="Build_ID" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Build_ID)

	/// <Property class="CVacTube_Repair" name="VacTube_Name" type="L3STRING">
	/// �۹�����
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Name)

	/// <Property class="CVacTube_Repair" name="VacTube_Id" type="L3STRING">
	/// �۹ܱ��
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Id)

	/// <Property class="CVacTube_Repair" name="Refra_Fac" type="L3STRING">
	/// �Ͳĳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CVacTube_Repair" name="RH_Age" type="L3LONG">
	/// ������
	/// </Property>
	DECLARE_L3PROP_LONG(RH_Age)

	/// <Property class="CVacTube_Repair" name="Cir_Age" type="L3LONG">
	/// ����������(¯)
	/// </Property>
	DECLARE_L3PROP_LONG(Cir_Age)

	/// <Property class="CVacTube_Repair" name="Up_Age" type="L3LONG">
	/// ����������(min)
	/// </Property>
	DECLARE_L3PROP_LONG(Up_Age)

	/// <Property class="CVacTube_Repair" name="Down_Age" type="L3LONG">
	/// �½�������(min)
	/// </Property>
	DECLARE_L3PROP_LONG(Down_Age)

	/// <Property class="CVacTube_Repair" name="InWall_Bri_Thick" type="L3DOUBLE">
	/// �۱ڲ�ש���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(InWall_Bri_Thick)

	/// <Property class="CVacTube_Repair" name="InBot_Bri_Thick" type="L3DOUBLE">
	/// �۵ײ�ש���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(InBot_Bri_Thick)

	/// <Property class="CVacTube_Repair" name="Mg_Cr_Bri_Ele_Waste" type="L3DOUBLE">
	/// �����ٽ��Mg-Crש[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Ele_Waste)

	/// <Property class="CVacTube_Repair" name="Mg_Cr_Bri_Dir_Waste" type="L3DOUBLE">
	/// ֱ�ӽ��Mg-Crש[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Dir_Waste)

	/// <Property class="CVacTube_Repair" name="Mg_Cr_Bri_Half_Waste" type="L3DOUBLE">
	/// ���ٽ��Mg-Crש[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Half_Waste)

	/// <Property class="CVacTube_Repair" name="Mg_Cr_Fir_Waste" type="L3DOUBLE">
	/// Mg-Cr����[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Fir_Waste)

	/// <Property class="CVacTube_Repair" name="Bear_Fir_Waste" type="L3DOUBLE">
	/// �ͻ���[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bear_Fir_Waste)

	/// <Property class="CVacTube_Repair" name="Si_Ca_Boa_Waste" type="L3DOUBLE">
	/// ��ư�[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si_Ca_Boa_Waste)

	/// <Property class="CVacTube_Repair" name="Light_Mat_Bri_Waste" type="L3DOUBLE">
	/// ����ש[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Light_Mat_Bri_Waste)

	/// <Property class="CVacTube_Repair" name="Pug_Hit_Mat_Waste" type="L3DOUBLE">
	/// ������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pug_Hit_Mat_Waste)

	/// <Property class="CVacTube_Repair" name="Cast_Wast" type="L3DOUBLE">
	/// ��ע��[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cast_Wast)

	/// <Property class="CVacTube_Repair" name="Repair_Position" type="L3STRING">
	/// �޲���λ
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Position)

	/// <Property class="CVacTube_Repair" name="Repair_Case" type="L3STRING">
	/// �޲����
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Case)

	/// <Property class="CVacTube_Repair" name="Repair_Per" type="L3STRING">
	/// �޲���
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Per)

	/// <Property class="CVacTube_Repair" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Repair" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Repair" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

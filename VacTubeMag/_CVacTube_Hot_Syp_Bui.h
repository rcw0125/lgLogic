// �߼���CVacTube_Hot_Syp_Buiͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CVacTube_Hot_Syp_Bui :
	public CL3Object
{
public:
	CVacTube_Hot_Syp_Bui(void);
	virtual ~CVacTube_Hot_Syp_Bui(void);

	DECLARE_L3CLASS(CVacTube_Hot_Syp_Bui,XGMESLogic\\VacTubeMag, Build_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Hot_Syp_Bui)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Build_ID" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Build_ID)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Hot_Syp_ID" type="L3STRING">
	/// ����ܱ��
	/// </Property>
	DECLARE_L3PROP_STRING(Hot_Syp_ID)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Build_Start_Time" type="L3DATETIME">
	/// ������ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_Start_Time)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Build_End_Time" type="L3DATETIME">
	/// ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_End_Time)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Refra_Fac" type="L3STRING">
	/// �Ͳĳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Hot_Syp_Age" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Syp_Age)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Mg_Cr_Bri_Dir_Waste" type="L3DOUBLE">
	/// ֱ�ӽ��Mg-Crש[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Dir_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Mg_Cr_Bri_Half_Waste" type="L3DOUBLE">
	/// ���ٽ��Mg-Crש[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Half_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Bear_Fir_Waste" type="L3DOUBLE">
	/// �ͻ���[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bear_Fir_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Si_Ca_Boa_Waste" type="L3DOUBLE">
	/// ��ư�[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si_Ca_Boa_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Light_Mat_Bri_Waste" type="L3DOUBLE">
	/// ����ש[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Light_Mat_Bri_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Cast_Wast" type="L3DOUBLE">
	/// ��ע��[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cast_Wast)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)
	
};

// �߼���CVacTube_Hot_Syp_Useͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CVacTube_Hot_Syp_Use :
	public CL3Object
{
public:
	CVacTube_Hot_Syp_Use(void);
	virtual ~CVacTube_Hot_Syp_Use(void);

	DECLARE_L3CLASS(CVacTube_Hot_Syp_Use,XGMESLogic\\VacTubeMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Hot_Syp_Use)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Hot_Syp_Use" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Build_ID" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Build_ID)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Hot_Syp_ID" type="L3STRING">
	/// ����ܱ��
	/// </Property>
	DECLARE_L3PROP_STRING(Hot_Syp_ID)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Refra_Fac" type="L3STRING">
	/// �Ͳĳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CVacTube_Hot_Syp_Use" name="On_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(On_Time)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Position" type="L3STRING">
	/// ���߹�λ
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CVacTube_Hot_Syp_Use" name="On_TeamID" type="L3STRING">
	/// ���߰���
	/// </Property>
	DECLARE_L3PROP_STRING(On_TeamID)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="On_Age" type="L3LONG">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_LONG(On_Age)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Cur_Age" type="L3LONG">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_LONG(Cur_Age)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Total_Age" type="L3LONG">
	/// �ۼ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Total_Age)

	/// <Property class="CVacTube_Hot_Syp_Use" name="OffLine_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(OffLine_Time)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Off_TeamID" type="L3STRING">
	/// ���߰���
	/// </Property>
	DECLARE_L3PROP_STRING(Off_TeamID)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="Off_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Reason)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="OnLine_Len" type="L3DOUBLE">
	/// ����ʱ��[��]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(OnLine_Len)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CVacTube_Hot_Syp_Use" name="On_Operator" type="L3STRING">
	/// ���߲���Ա
	/// </Property>
	DECLARE_L3PROP_STRING(On_Operator)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="On_ShiftID" type="L3STRING">
	/// ���߰��
	/// </Property>
	DECLARE_L3PROP_STRING(On_ShiftID)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="Off_Operator" type="L3STRING">
	/// ���߲���Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Operator)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="Off_ShiftID" type="L3STRING">
	/// ���߰��
	/// </Property>
	DECLARE_L3PROP_STRING(Off_ShiftID)
	
	
};

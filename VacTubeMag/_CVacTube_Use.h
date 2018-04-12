// �߼���CVacTube_Useͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CVacTube_Use :
	public CL3Object
{
public:
	CVacTube_Use(void);
	virtual ~CVacTube_Use(void);

	DECLARE_L3CLASS(CVacTube_Use,XGMESLogic\\VacTubeMag, Install_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Use)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Use" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)
	
	/// <Property class="CVacTube_Use" name="Install_ID" type="L3STRING">
	/// ��ղ���װ���
	/// </Property>
	DECLARE_L3PROP_STRING(Install_ID)
	
	/// <Property class="CVacTube_Use" name="VacTube_Code" type="L3STRING">
	/// ��ղ۱��
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Code)
	
	/// <Property class="CVacTube_Use" name="Position" type="L3STRING">
	/// ����λ
	/// </Property>
	DECLARE_L3PROP_STRING(Position)
	
	/// <Property class="CVacTube_Use" name="Up_Slot_ID" type="L3STRING">
	/// �ϲ��ۺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Up_Slot_ID)

	/// <Property class="CVacTube_Use" name="Bel_Slot_ID" type="L3STRING">
	/// �²��ۺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Bel_Slot_ID)

	/// <Property class="CVacTube_Use" name="Up_Total_Age" type="L3LONG">
	/// �ϲ����ۼ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Up_Total_Age)

	/// <Property class="CVacTube_Use" name="Bel_Total_Age" type="L3LONG">
	/// �²����ۼ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Bel_Total_Age)

	/// <Property class="CVacTube_Use" name="Cir_Total_Age" type="L3LONG">
	/// �������ۼ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Cir_Total_Age)

	/// <Property class="CVacTube_Use" name="Aes_Soa_Total_Len" type="L3LONG">
	/// �������ۼ�ʱ��[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Aes_Soa_Total_Len)

	/// <Property class="CVacTube_Use" name="Aes_Soa_Total_Age" type="L3LONG">
	/// �������ۼ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Aes_Soa_Total_Age)

	/// <Property class="CVacTube_Use" name="Des_Soa_Total_Len" type="L3LONG">
	/// �½����ۼ�ʱ��[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Des_Soa_Total_Len)

	/// <Property class="CVacTube_Use" name="Des_Soa_Total_Age" type="L3LONG">
	/// �½����ۼ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Des_Soa_Total_Age)

	/// <Property class="CVacTube_Use" name="On_Line_Time" type="L3DATETIME">
	/// �Ϲ�λʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(On_Line_Time)

	/// <Property class="CVacTube_Use" name="Crane_TeamID" type="L3STRING">
	/// ���۰���
	/// </Property>
	DECLARE_L3PROP_STRING(Crane_TeamID)

	/// <Property class="CVacTube_Use" name="Off_Line_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Off_Line_Time)

	/// <Property class="CVacTube_Use" name="Off_Line_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Line_Reason)

	/// <Property class="CVacTube_Use" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Use" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Use" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CVacTube_Use" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

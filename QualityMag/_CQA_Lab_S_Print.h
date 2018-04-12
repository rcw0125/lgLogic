// �߼���CQA_Lab_S_Printͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Lab_S_Print :
	public CL3Object
{
public:
	CQA_Lab_S_Print(void);
	virtual ~CQA_Lab_S_Print(void);

	DECLARE_L3CLASS(CQA_Lab_S_Print,XGMESLogic\\QualityMag, AppID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_S_Print)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Lab_S_Print" name="AppID" type="L3STRING">
	/// ί�е����
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Lab_S_Print" name="Arrive_Date" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Date)

	/// <Property class="CQA_Lab_S_Print" name="Report_Date" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Report_Date)

	/// <Property class="CQA_Lab_S_Print" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Lab_S_Print" name="Sample_Address" type="L3STRING">
	/// ȡ���ص�
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)

	/// <Property class="CQA_Lab_S_Print" name="Sample_Type" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Type)

	/// <Property class="CQA_Lab_S_Print" name="Sample_Count" type="L3STRING">
	/// ȡ������
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Count)

	/// <Property class="CQA_Lab_S_Print" name="Sample_Code" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Code)

	/// <Property class="CQA_Lab_S_Print" name="Shrinkage_Hole" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Shrinkage_Hole)

	/// <Property class="CQA_Lab_S_Print" name="Center_Loose" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Loose)

	/// <Property class="CQA_Lab_S_Print" name="Common_Loose" type="L3STRING">
	/// һ������
	/// </Property>
	DECLARE_L3PROP_STRING(Common_Loose)

	/// <Property class="CQA_Lab_S_Print" name="Center_Crack_Lev" type="L3STRING">
	/// �������Ƽ���
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Crack_Lev)

	/// <Property class="CQA_Lab_S_Print" name="Center_Crack_Len" type="L3STRING">
	/// �������Ƴ���
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Crack_Len)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Bubble" type="L3STRING">
	/// Ƥ������
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Bubble)

	/// <Property class="CQA_Lab_S_Print" name="Center_Crack" type="L3STRING">
	/// �м�����
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Crack)

	/// <Property class="CQA_Lab_S_Print" name="Equiaxed_Grain" type="L3STRING">
	/// ���ᾧ
	/// </Property>
	DECLARE_L3PROP_STRING(Equiaxed_Grain)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Crack_D" type="L3STRING">
	/// Ƥ������d
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Crack_D)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Crack_L" type="L3STRING">
	/// Ƥ������l
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Crack_L)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Crack_Q" type="L3STRING">
	/// Ƥ������q
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Crack_Q)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Crack_Lev" type="L3STRING">
	/// Ƥ�����Ƽ���
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Crack_Lev)

	/// <Property class="CQA_Lab_S_Print" name="Surface_Eyelet" type="L3STRING">
	/// �ݱ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Surface_Eyelet)

	/// <Property class="CQA_Lab_S_Print" name="Surface_Crack" type="L3STRING">
	/// �ݱ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Surface_Crack)

	/// <Property class="CQA_Lab_S_Print" name="Surface_Slag" type="L3STRING">
	/// �ݱ������
	/// </Property>
	DECLARE_L3PROP_STRING(Surface_Slag)

	/// <Property class="CQA_Lab_S_Print" name="Nonmetal_Slag" type="L3STRING">
	/// �ǽ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Nonmetal_Slag)

	/// <Property class="CQA_Lab_S_Print" name="Spot" type="L3STRING">
	/// �ߵ�
	/// </Property>
	DECLARE_L3PROP_STRING(Spot)

	/// <Property class="CQA_Lab_S_Print" name="AcidTime" type="L3STRING">
	/// ��ʴʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(AcidTime)

	/// <Property class="CQA_Lab_S_Print" name="S_Print" type="L3STRING">
	/// ��ӡ���"0:���ϸ�1���ϸ񣬿գ�û����"
	/// </Property>
	DECLARE_L3PROP_STRING(S_Print)

	/// <Property class="CQA_Lab_S_Print" name="LogTime" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CQA_Lab_S_Print" name="DataLogMode" type="L3DATETIME">
	/// ���ݲ�����ʽ��0���Զ��ɼ������ң�1���˹����뻯����;
	/// </Property>
	DECLARE_L3PROP_LONG(DataLogMode)

	/// <Property class="CQA_Lab_S_Print" name="StrandID" type="L3STRING">
	///����
	/// </Property>
	DECLARE_L3PROP_STRING(StrandID)

	/// <Property class="CQA_Lab_S_Print" name="Size" type="L3STRING">
	///�ߴ�
	/// </Property>
	DECLARE_L3PROP_STRING(Size)

	/// <Property class="CQA_Lab_S_Print" name="Operator" type="L3STRING">
	/// ������
	/// </Property>2009-04-23
	DECLARE_L3PROP_STRING(Operator)

};

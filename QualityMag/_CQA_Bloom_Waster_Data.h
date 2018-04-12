// �߼���CQA_Bloom_Waster_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Bloom_Waster_Data :
	public CL3Object
{
public:
	CQA_Bloom_Waster_Data(void);
	virtual ~CQA_Bloom_Waster_Data(void);

	DECLARE_L3CLASS(CQA_Bloom_Waster_Data,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Bloom_Waster_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Bloom_Waster_Data" name="Produce_Date" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Produce_Date)

	/// <Property class="CQA_Bloom_Waster_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Bloom_Waster_Data" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Bloom_Waster_Data" name="Cut_SteelGradeIndex" type="L3STRING">
	/// �ж����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_SteelGradeIndex)

	/// <Property class="CQA_Bloom_Waster_Data" name="Thickness" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CQA_Bloom_Waster_Data" name="Width" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CQA_Bloom_Waster_Data" name="Length" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CQA_Bloom_Waster_Data" name="Bloom_Count" type="L3LONG">
	/// ����֦��
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CQA_Bloom_Waster_Data" name="Cal_Weight" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cal_Weight)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Count" type="L3DOUBLE">
	/// ˦���ܳ���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Weight" type="L3DOUBLE">
	/// ˦��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Count1" type="L3DOUBLE">
	/// ˦�ϳ���1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Weight1" type="L3DOUBLE">
	/// ˦������1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Reason1" type="L3STRING">
	/// ˦��ԭ��1
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Count2" type="L3DOUBLE">
	/// ˦�ϳ���2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Weight2" type="L3DOUBLE">
	/// ˦������2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Reason2" type="L3STRING">
	/// ˦��ԭ��2
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Count3" type="L3DOUBLE">
	/// ˦�ϳ���3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Weight3" type="L3DOUBLE">
	/// ˦������3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Reason3" type="L3STRING">
	/// ˦��ԭ��3
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Shop1" type="L3STRING">
	/// ���γ���1
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Shop1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Shop2" type="L3STRING">
	/// ���γ���2
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Shop2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Shop3" type="L3STRING">
	/// ���γ���3
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Shop3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Unit1" type="L3STRING">
	/// ���λ���1
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Unit1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Unit2" type="L3STRING">
	/// ���λ���2
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Unit2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Unit3" type="L3STRING">
	/// ���λ���3
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Unit3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Duty_Per1" type="L3STRING">
	/// ������1
	/// </Property>
	DECLARE_L3PROP_STRING(Duty_Per1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Duty_Per2" type="L3STRING">
	/// ������2
	/// </Property>
	DECLARE_L3PROP_STRING(Duty_Per2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Duty_Per3" type="L3STRING">
	/// ������3
	/// </Property>
	DECLARE_L3PROP_STRING(Duty_Per3)

	/// <Property class="CQA_Bloom_Waster_Data" name="TeamID1" type="L3STRING">
	/// ����1
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID1)

	/// <Property class="CQA_Bloom_Waster_Data" name="TeamID2" type="L3STRING">
	/// ����2
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID2)

	/// <Property class="CQA_Bloom_Waster_Data" name="TeamID3" type="L3STRING">
	/// ����3
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Confirm_Per" type="L3STRING">
	/// ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Confirm_Per)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Operator" type="L3STRING">
	/// ˦����
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Operator)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Date" type="L3DATETIME">
	/// ˦������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Waster_Date)

	/// <Property class="CQA_Bloom_Waster_Data" name="ShitID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShitID)

	/// <Property class="CQA_Bloom_Waster_Data" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CQA_Bloom_Waster_Data" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CQA_Bloom_Waster_Data" name="Duty_Flag" type="L3SHORT">
	/// ָ�����α�־
	/// </Property>
	DECLARE_L3PROP_LONG(Duty_Flag)

	/// <Property class="CQA_Bloom_Waster_Data" name="Object_ID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};

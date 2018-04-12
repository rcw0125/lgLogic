// �߼���CBloom_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "Material.h"

class CBloom_Data :
	public Material
{
public:
	CBloom_Data(void);
	virtual ~CBloom_Data(void);

	DECLARE_L3CLASS(CBloom_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBloom_Data" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CBloom_Data" name="Casting_No" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Casting_No)

	/// <Property class="CBloom_Data" name="Casting_Heat_Cnt" type="L3LONG">
	/// ������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Casting_Heat_Cnt)

	/// <Property class="CBloom_Data" name="Pre_SteelGradeIndex" type="L3STRING">
	/// Ԥ�����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CBloom_Data" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CBloom_Data" name="Cut_SteelGradeIndex" type="L3STRING">
	/// �ж����ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_SteelGradeIndex)

	/// <Property class="CBloom_Data" name="Final_SteelGradeIndex" type="L3STRING">
	/// �������ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Final_SteelGradeIndex)

	/// <Property class="CBloom_Data" name="Length" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CBloom_Data" name="Width" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CBloom_Data" name="Thickness" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CBloom_Data" name="Cur_Section_ID" type="L3STRING">
	/// ��ǰ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Section_ID)

	/// <Property class="CBloom_Data" name="Cur_Pile_ID" type="L3STRING">
	/// ��ǰ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Pile_ID)

	/// <Property class="CBloom_Data" name="Cur_Layer_ID" type="L3LONG">
	/// ��ǰ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Layer_ID)//2009-03-09 �����͸�Ϊ����һ¯�������Էż�����

	/// <Property class="CBloom_Data" name="Cur_Seq_ID" type="L3LONG">
	/// ��ǰ˳��
	/// </Property>
	DECLARE_L3PROP_LONG(Cur_Seq_ID)

	/// <Property class="CBloom_Data" name="Cur_Bay_ID" type="L3STRING">
	/// ��ǰ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Bay_ID)

	/// <Property class="CBloom_Data" name="Destination" type="L3STRING">
	/// ȥ��
	/// </Property>
	DECLARE_L3PROP_STRING(Destination)

	/// <Property class="CBloom_Data" name="Hot_Send_Flag" type="L3LONG">
	/// ���ͱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Send_Flag)

	/// <Property class="CBloom_Data" name="Process_Type" type="L3LONG">
	/// ���÷�ʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Process_Type)

	/// <Property class="CBloom_Data" name="Plan_Ord_ID" type="L3STRING">
	/// �ƻ�������
	/// </Property>
	DECLARE_L3PROP_STRING(Plan_Ord_ID)

	/// <Property class="CBloom_Data" name="Produce_Date" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Produce_Date)

	/// <Property class="CBloom_Data" name="Finish_Flag" type="L3LONG">
	/// ��������־��0��������1����죬2��������ж�
	/// </Property>
	DECLARE_L3PROP_LONG(Finish_Flag)

	/// <Property class="CBloom_Data" name="FinishedTime" type="L3DATETIME">
	/// �������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(FinishedTime)

	/// <Property class="CBloom_Data" name="Bloom_Count" type="L3LONG">
	/// ʵ�ʸ���֧��
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CBloom_Data" name="Cal_Weight" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cal_Weight)

	/// <Property class="CBloom_Data" name="Right_Count" type="L3LONG">
	/// �ϸ����֧��
	/// </Property>
	DECLARE_L3PROP_LONG(Right_Count)

	/// <Property class="CBloom_Data" name="Right_Weight" type="L3DOUBLE">
	/// �ϸ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Right_Weight)

	/// <Property class="CBloom_Data" name="Waster_Count" type="L3DOUBLE">
	/// ˦�ϸ����ܳ���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count)

	/// <Property class="CBloom_Data" name="Waster_Weight" type="L3DOUBLE">
	/// ˦������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight)

	/// <Property class="CBloom_Data" name="Waster_Count1" type="L3LONG">
	/// ˦�ϸ�������1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count1)

	/// <Property class="CBloom_Data" name="Waster_Weight1" type="L3DOUBLE">
	/// ˦������1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight1)

	/// <Property class="CBloom_Data" name="Waster_Reason1" type="L3STRING">
	/// ˦��ԭ��1
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason1)

	/// <Property class="CBloom_Data" name="Waster_Count2" type="L3DOUBLE">
	/// ˦�ϸ�������2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count2)

	/// <Property class="CBloom_Data" name="Waster_Weight2" type="L3DOUBLE">
	/// ˦������2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight2)

	/// <Property class="CBloom_Data" name="Waster_Reason2" type="L3STRING">
	/// ˦��ԭ��2
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason2)

	/// <Property class="CBloom_Data" name="Waster_Count3" type="L3DOUBLE">
	/// ˦�ϸ�������3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count3)

	/// <Property class="CBloom_Data" name="Waster_Weight3" type="L3DOUBLE">
	/// ˦������3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight3)

	/// <Property class="CBloom_Data" name="Waster_Reason3" type="L3STRING">
	/// ˦��ԭ��3
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason3)

	/// <Property class="CBloom_Data" name="Wrong_Count" type="L3LONG">
	/// ���ϸ������֧��
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count)

	/// <Property class="CBloom_Data" name="Wrong_Weight" type="L3DOUBLE">
	/// ���ϸ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight)

	/// <Property class="CBloom_Data" name="Wrong_Count1" type="L3LONG">
	/// ���ϸ����֧��1
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count1)

	/// <Property class="CBloom_Data" name="Wrong_Weight1" type="L3DOUBLE">
	/// ���ϸ�����1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight1)

	/// <Property class="CBloom_Data" name="Wrong_Reason1" type="L3STRING">
	/// ���ϸ�ԭ��1
	/// </Property>
	DECLARE_L3PROP_STRING(Wrong_Reason1)

	/// <Property class="CBloom_Data" name="Wrong_Count2" type="L3LONG">
	/// ���ϸ����֧��2
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count2)

	/// <Property class="CBloom_Data" name="Wrong_Weight2" type="L3DOUBLE">
	/// ���ϸ�����2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight2)

	/// <Property class="CBloom_Data" name="Wrong_Reason2" type="L3STRING">
	/// ���ϸ�ԭ��2
	/// </Property>
	DECLARE_L3PROP_STRING(Wrong_Reason2)

	/// <Property class="CBloom_Data" name="Wrong_Count3" type="L3LONG">
	/// ���ϸ����֧��3
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count3)

	/// <Property class="CBloom_Data" name="Wrong_Weight3" type="L3DOUBLE">
	/// ���ϸ�����3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight3)

	/// <Property class="CBloom_Data" name="Wrong_Reason3" type="L3STRING">
	/// ���ϸ�ԭ��3
	/// </Property>
	DECLARE_L3PROP_STRING(Wrong_Reason3)

	/// <Property class="CBloom_Data" name="SufaceDefactDes" type="L3STING">
	/// ����ȱ������
	/// </Property>
	DECLARE_L3PROP_STRING(SufaceDefactDes)

	/// <Property class="CBloom_Data" name="Reason" type="L3STING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

	/// <Property class="CBloom_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBloom_Data" name="Test_Roll_Count" type="L3LONG">
	/// ��������֧��
	/// </Property>
	DECLARE_L3PROP_LONG(Test_Roll_Count)

	/// <Property class="CBloom_Data" name="Test_Roll_Weight" type="L3DOUBLE">
	/// ������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Test_Roll_Weight)

	/// <Property class="CBloom_Data" name="Back_Flag" type="L3LONG">
	/// �������ͱ�־2009-04-02
	/// </Property>
	DECLARE_L3PROP_LONG(Back_Flag)

	/// <Property class="CBloom_Data" name="Back_Date" type="L3LONG">
	/// ��������ʱ��2009-04-02
	/// </Property>
	DECLARE_L3PROP_DATETIME(Back_Date)

	
	/// <Property class="CBloom_Data" name="Add_Bloom_Count" type="L3LONG">
	/// �������֧��1 2009-08-06
	/// </Property>
	DECLARE_L3PROP_LONG(Add_Bloom_Count)

	/// <Property class="CBloom_Data" name="Div_Bloom_Count" type="L3LONG">
	/// ��������֧��2009-08-06
	/// </Property>
	DECLARE_L3PROP_LONG(Div_Bloom_Count)

	/// <Property class="CBloom_Data" name="Plan_Bloom_Count" type="L3LONG">
	/// �ƻ�����֧��2009-08-06
	/// </Property>
	DECLARE_L3PROP_LONG(Plan_Bloom_Count)


	/// <Property class="CBloom_Data" name="Add_Div_HeatID" type="L3STRING">
	/// ����¯��
	/// </Property>
	DECLARE_L3PROP_STRING(Add_Div_HeatID)


	/// <Property class="CBloom_Data" name="Add_HeatID1" type="L3STRING">
	/// ����¯��1 2009-08-21
	/// </Property>
	DECLARE_L3PROP_STRING(Add_HeatID1)

	/// <Property class="CBloom_Data" name="Add_HeatID2" type="L3STRING">
	/// ����¯��2 2009-08-21
	/// </Property>
	DECLARE_L3PROP_STRING(Add_HeatID2)

	/// <Property class="CBloom_Data" name="Add_Bloom_Count2" type="L3LONG">
	/// �������֧��2 2009-08-21
	/// </Property>
	DECLARE_L3PROP_LONG(Add_Bloom_Count2)

};

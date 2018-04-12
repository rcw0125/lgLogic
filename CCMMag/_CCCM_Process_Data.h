// �߼���CCCM_Process_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Process_Data :
	public CL3Object
{
public:
	CCCM_Process_Data(void);
	virtual ~CCCM_Process_Data(void);

	DECLARE_L3CLASS(CCCM_Process_Data,XGMESLogic\\CCMMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	///2009-02-13 ɾ�������Ԥ��¯�š�Ԥ�����κš���Ʒ�ƺš���������������������������ע������֧����
	///������ע������֧�������������ϸ�֧�����ϸ����������ϸ�֧�������ϸ�������˦��֧���������ж�ʱ�̡�
	///���ּǺš�˦���������ϸ�֧������ˮ�������֡�©�ִ���
	///��ӻ�¯ԭ���а�����

	/// <Property class="CCCM_Process_Data" name="TreatNo" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Process_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Process_Data" name="CastingNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Process_Data" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Process_Data" name="TundishNo" type="L3STRING">
	/// �а���
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_Process_Data" name="TundishCar_Type" type="L3STRING">
	/// �а�����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishCar_Type)




	/// <Property class="CCCM_Process_Data" name="Casting_HeatNum" type="L3LONG">
	/// ������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Casting_HeatNum)

	/// <Property class="CCCM_Process_Data" name="Tundish_HeatNum" type="L3LONG">
	/// ������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_HeatNum)

	/// <Property class="CCCM_Process_Data" name="CastingStartTime" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(CastingStartTime)

	/// <Property class="CCCM_Process_Data" name="CastingStopTime" type="L3DATETIME">
	/// ͣ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(CastingStopTime)

	
	/// <Property class="CCCM_Process_Data" name="InjectionBar_BlowAr" type="L3SHORT">
	/// 
	/// �Ƿ��������
	/// (1-��
	///  0-����)
	/// </Property>
	DECLARE_L3PROP_SHORT(InjectionBar_BlowAr)


	/// <Property class="CCCM_Process_Data" name="Weight_Return" type="L3DOUBLE">
	/// ��¯��ˮ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Return)


	/// <Property class="CCCM_Process_Data" name="Weight_Return_Reason" type="L3STRING">
	/// ��¯ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Weight_Return_Reason)


	/// <Property class="CCCM_Process_Data" name="Second_Cooling_Mode" type="L3SHORT">
	/// 
	/// ����ˮģʽ
	/// (1-L1��2-L2��0-�ֶ�)
	/// </Property>
	DECLARE_L3PROP_SHORT(Second_Cooling_Mode)

	/// <Property class="CCCM_Process_Data" name="Second_Cooling_CurveNo" type="L3SHORT">
	/// ����ˮˮ���
	/// </Property>
	DECLARE_L3PROP_SHORT(Second_Cooling_CurveNo)

	/// <Property class="CCCM_Process_Data" name="Weight_Cut_Head" type="L3DOUBLE">
	/// ��ͷ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Cut_Head)

	/// <Property class="CCCM_Process_Data" name="Weight_Cut_Trail" type="L3DOUBLE">
	/// ��β��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Cut_Trail)

	/// <Property class="CCCM_Process_Data" name="Tundish_SlagThickness" type="L3LONG">
	/// �а�������[mm]
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_SlagThickness)

	/// <Property class="CCCM_Process_Data" name="Tundish_Bottom_Temp" type="L3LONG">
	/// �а����¶�[��]
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Bottom_Temp)

	/// <Property class="CCCM_Process_Data" name="Tundish_Wall_Temp" type="L3LONG">
	/// �а����¶�[��]
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Wall_Temp)

	/// <Property class="CCCM_Process_Data" name="Tundish_Level_Mold" type="L3LONG">
	/// �а�Һ��[mm]
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Level_Mold) 

	/// <Property class="CCCM_Process_Data" name="PlugBar_Control" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(PlugBar_Control)

	/// <Property class="CCCM_Process_Data" name="Soft_Press_Flag_1" type="L3STRING">
	/// 1����ѹ���Ƿ�Ͷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Soft_Press_Flag_1)

	/// <Property class="CCCM_Process_Data" name="Soft_Press_Flag_2" type="L3STRING">
	/// 2����ѹ���Ƿ�Ͷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Soft_Press_Flag_2)

	/// <Property class="CCCM_Process_Data" name="Soft_Press_Flag_3" type="L3STRING">
	/// 3����ѹ���Ƿ�Ͷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Soft_Press_Flag_3)

	/// <Property class="CCCM_Process_Data" name="Soft_Press_Flag_4" type="L3STRING">
	/// 4����ѹ���Ƿ�Ͷ��
	/// </Property>
	DECLARE_L3PROP_STRING(Soft_Press_Flag_4)

	/// <Property class="CCCM_Process_Data" name="SpeedChange" type="L3STRING">
	/// ���ٸı��־ 
	/// </Property>
	DECLARE_L3PROP_STRING(SpeedChange)




};

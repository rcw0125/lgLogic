// �߼���CCCM5_Runtime1_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM5_Runtime1_Data :
	public CL3Object
{
public:
	CCCM5_Runtime1_Data(void);
	virtual ~CCCM5_Runtime1_Data(void);

	DECLARE_L3CLASS(CCCM5_Runtime1_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM5_Runtime1_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM5_Runtime_Data" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM5_Runtime_Data" name="TreatNo" type="L3STRING">
	/// �����
		/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM5_Runtime_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM5_Runtime_Data" name="Catch_Count" type="L3LONG">
	/// �ɼ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Catch_Count)

	/// <Property class="CCCM5_Runtime_Data" name="Cooling_MeterNo" type="L3LONG">
	/// ����ˮ���
	/// </Property>
	DECLARE_L3PROP_LONG(Cooling_MeterNo)

	/// <Property class="CCCM5_Runtime_Data" name="Oscillate_MeterNo" type="L3LONG">
	/// �񶯱��
	/// </Property>
	DECLARE_L3PROP_LONG(Oscillate_MeterNo)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_ProtectCasting" type="L3DOUBLE">
	/// ���������ע�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_ProtectCasting)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_PlugBar_1ST" type="L3DOUBLE">
	/// 1���������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_PlugBar_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_PlugBar_2ST" type="L3DOUBLE">
	/// 2���������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_PlugBar_2ST)

		/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_PlugBar_3ST" type="L3DOUBLE">
	/// 3���������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_PlugBar_3ST)

		/// <Property class="CCCM5_Runtime_Data" name="Flow_BlowAr_PlugBar_4ST" type="L3DOUBLE">
	/// 4���������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr_PlugBar_4ST)


	/// <Property class="CCCM5_Runtime_Data" name="Position_Act_PlugBar_1ST" type="L3DOUBLE">
	/// 1��ʵ�ʰ�λ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Act_PlugBar_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Act_PlugBar_2ST" type="L3DOUBLE">
	/// 2��ʵ�ʰ�λ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Act_PlugBar_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Act_PlugBar_3ST" type="L3DOUBLE">
	/// 3��ʵ�ʰ�λ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Act_PlugBar_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Act_PlugBar_4ST" type="L3DOUBLE">
	/// 4��ʵ�ʰ�λ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Act_PlugBar_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Init_PlugBar_1ST" type="L3DOUBLE">
	/// 1����ʼ��λ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Init_PlugBar_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Init_PlugBar_2ST" type="L3DOUBLE">
	/// 2����ʼ��λ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Init_PlugBar_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Init_PlugBar_3ST" type="L3DOUBLE">
	/// 3����ʼ��λ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Init_PlugBar_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Position_Init_PlugBar_4ST" type="L3DOUBLE">
	/// 4����ʼ��λ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Position_Init_PlugBar_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Level_Act_Mold_1ST" type="L3DOUBLE">
	/// 1��ʵ�ʽᾧ��Һ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Level_Act_Mold_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Level_Act_Mold_2ST" type="L3DOUBLE">
	/// 2��ʵ�ʽᾧ��Һ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Level_Act_Mold_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Level_Act_Mold_3ST" type="L3DOUBLE">
	/// 3��ʵ��Һ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Level_Act_Mold_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Level_Act_Mold_4ST" type="L3DOUBLE">
	/// 4��ʵ�ʽ�Һ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Level_Act_Mold_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_In_Cooling" type="L3LONG">
	/// ����ˮ��ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_In_Cooling)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1stSect_1ST" type="L3DOUBLE">
	/// 1��1�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_1stSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ndSect_1ST" type="L3DOUBLE">
	/// 1��2�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_2ndSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3rdSect_1ST" type="L3DOUBLE">
	/// 1��3�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_3rdSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4thSect_1ST" type="L3DOUBLE">
	/// 1��4�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_4thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_5thSect_1ST" type="L3DOUBLE">
	/// 1��5�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_5thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1stSect_1ST" type="L3DOUBLE">
	/// 1��1��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_1stSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ndSect_1ST" type="L3DOUBLE">
	/// 1��2��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_2ndSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3rdSect_1ST" type="L3DOUBLE">
	/// 1��3��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_3rdSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4thSect_1ST" type="L3DOUBLE">
	/// 1��4�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_4thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_5thSect_1ST" type="L3DOUBLE">
	/// 1��5��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_5thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1stSect_2ST" type="L3DOUBLE">
	/// 2��1�ο�����ȴˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_1stSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ndSect_2ST" type="L3DOUBLE">
	/// 2��2�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_2ndSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3rdSect_2ST" type="L3DOUBLE">
	/// 2��3�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_3rdSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4thSect_2ST" type="L3DOUBLE">
	/// 2��4�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_4thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_5thSect_2ST" type="L3DOUBLE">
	/// 2��5�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_5thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1stSect_2ST" type="L3DOUBLE">
	/// 2��1��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_1stSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ndSect_2ST" type="L3DOUBLE">
	/// 2��2��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_2ndSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3rdSect_2ST" type="L3DOUBLE">
	/// 2��3��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_3rdSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4thSect_2ST" type="L3DOUBLE">
	/// 2��4�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_4thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_5thSect_2ST" type="L3DOUBLE">
	/// 2��5��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_5thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1stSect_3ST" type="L3DOUBLE">
	/// 3��1�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_1stSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ndSect_3ST" type="L3DOUBLE">
	/// 3��2�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_2ndSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3rdSect_3ST" type="L3DOUBLE">
	/// 3��3�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_3rdSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4thSect_3ST" type="L3DOUBLE">
	/// 3��4�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_4thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_5thSect_3ST" type="L3DOUBLE">
	/// 3��5�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_5thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1stSect_3ST" type="L3DOUBLE">
	/// 3��1��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_1stSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ndSect_3ST" type="L3DOUBLE">
	/// 3��2��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_2ndSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3rdSect_3ST" type="L3DOUBLE">
	/// 3��3��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_3rdSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4thSect_3ST" type="L3DOUBLE">
	/// 3��4�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_4thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_5thSect_3ST" type="L3DOUBLE">
	/// 3��5��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_5thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1stSect_4ST" type="L3DOUBLE">
	/// 4��1�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_1stSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ndSect_4ST" type="L3DOUBLE">
	/// 4��2�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_2ndSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3rdSect_4ST" type="L3DOUBLE">
	/// 4��3�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_3rdSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4thSect_4ST" type="L3DOUBLE">
	/// 4��4�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_4thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_5thSect_4ST" type="L3DOUBLE">
	/// 4��5�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Wdh_5thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1stSect_4ST" type="L3DOUBLE">
	/// 4��1��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_1stSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ndSect_4ST" type="L3DOUBLE">
	/// 4��2��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_2ndSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3rdSect_4ST" type="L3DOUBLE">
	/// 4��3��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_3rdSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4thSect_4ST" type="L3DOUBLE">
	/// 4��4�ο���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_4thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_5thSect_4ST" type="L3DOUBLE">
	/// 4��5��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cool_Nrw_5thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cooling" type="L3DOUBLE">
	/// ����ˮ������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_Cooling)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_Mold_1ST" type="L3LONG">
	/// 1����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_Mold_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_Mold_2ST" type="L3LONG">
	/// 2����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_Mold_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_Mold_3ST" type="L3LONG">
	/// 3����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_Mold_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_Mold_4ST" type="L3LONG">
	/// 4����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_Mold_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_1ST" type="L3LONG">
	/// 1����ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_2ST" type="L3LONG">
	/// 2����ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_3ST" type="L3LONG">
	/// 3����ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_4ST" type="L3LONG">
	/// 4����ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_1ST" type="L3LONG">
	/// 1������ˮ����
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Wdh_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_2ST" type="L3LONG">
	/// 2������ˮ����
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Wdh_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_3ST" type="L3LONG">
	/// 3������ˮ����
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Wdh_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Wdh_4ST" type="L3LONG">
	/// 4������ˮ����
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Wdh_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_1ST" type="L3LONG">
	/// 1��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Nrw_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_2ST" type="L3LONG">
	/// 2��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Nrw_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_3ST" type="L3LONG">
	/// 3��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Nrw_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flow_Cool_Nrw_4ST" type="L3LONG">
	/// 4��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_LONG(Flow_Cool_Nrw_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_1ST" type="L3DOUBLE">
	/// 1���趨��Ƶ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_2ST" type="L3DOUBLE">
	/// 2���趨��Ƶ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_3ST" type="L3DOUBLE">
	/// 3���趨��Ƶ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_4ST" type="L3DOUBLE">
	/// 4���趨��Ƶ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_1ST" type="L3DOUBLE">
	/// 1��ʵ����Ƶ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_2ST" type="L3DOUBLE">
	/// 2��ʵ����Ƶ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_3ST" type="L3DOUBLE">
	/// 3��ʵ����Ƶ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_4ST" type="L3DOUBLE">
	/// 4��ʵ����Ƶ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Setup_1ST" type="L3DOUBLE">
	/// 1���趨���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Setup_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Setup_2ST" type="L3DOUBLE">
	/// 2���趨���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Setup_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Setup_3ST" type="L3DOUBLE">
	/// 3���趨���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Setup_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Setup_4ST" type="L3DOUBLE">
	/// 4���趨���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Setup_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Act_1ST" type="L3DOUBLE">
	/// 1��ʵ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Act_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Act_2ST" type="L3DOUBLE">
	/// 2��ʵ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Act_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Act_3ST" type="L3DOUBLE">
	/// 3��ʵ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Act_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Ampl_Act_4ST" type="L3DOUBLE">
	/// 4��ʵ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ampl_Act_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_In_ElectMix" type="L3LONG">
	/// ��ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_In_ElectMix)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_ElectMix_1ST" type="L3LONG">
	/// 1�����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_ElectMix_2ST" type="L3LONG">
	/// 2����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_ElectMix_3ST" type="L3LONG">
	/// 3����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Out_ElectMix_4ST" type="L3LONG">
	/// 4����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Out_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_1ST" type="L3LONG">
	/// 1������ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Def_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_2ST" type="L3LONG">
	/// 2������ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Def_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_3ST" type="L3LONG">
	/// 3������ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Def_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_4ST" type="L3LONG">
	/// 4������ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Def_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Setup_ElectMix_1ST" type="L3DOUBLE">
	/// 1���趨����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Setup_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Setup_ElectMix_2ST" type="L3DOUBLE">
	/// 2���趨����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Setup_ElectMix_2ST)

    /// <Property class="CCCM5_Runtime_Data" name="Current_Setup_ElectMix_3ST" type="L3DOUBLE">
	/// 3���趨����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Setup_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Setup_ElectMix_4ST" type="L3DOUBLE">
	/// 4���趨����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Setup_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Act_ElectMix_1ST" type="L3DOUBLE">
	/// 1��ʵ�ʵ���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Act_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Act_ElectMix_2ST" type="L3DOUBLE">
	/// 2��ʵ�ʵ���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Act_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Act_ElectMix_3ST" type="L3DOUBLE">
	/// 3��ʵ�ʵ���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Act_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Current_Act_ElectMix_4ST" type="L3DOUBLE">
	/// 4��ʵ�ʵ���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Current_Act_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_ElectMix_1ST" type="L3DOUBLE">
	/// 1���趨Ƶ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_ElectMix_2ST" type="L3DOUBLE">
	/// 2���趨Ƶ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_ElectMix_3ST" type="L3DOUBLE">
	/// 3���趨Ƶ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Setup_ElectMix_4ST" type="L3DOUBLE">
	/// 4���趨Ƶ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Setup_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_ElectMix_1ST" type="L3DOUBLE">
	/// 1��ʵ��Ƶ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_ElectMix_2ST" type="L3DOUBLE">
	/// 2��ʵ��Ƶ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_ElectMix_3ST" type="L3DOUBLE">
	/// 3��ʵ��Ƶ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Freq_Act_ElectMix_4ST" type="L3DOUBLE">
	/// 4��ʵ��Ƶ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Freq_Act_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Direction_ElectMix_1ST" type="L3LONG">
	/// 1����ת����
	/// </Property>
	DECLARE_L3PROP_LONG(Direction_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Direction_ElectMix_2ST" type="L3LONG">
	/// 2����ת����
	/// </Property>
	DECLARE_L3PROP_LONG(Direction_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Direction_ElectMix_3ST" type="L3LONG">
	/// 3����ת����
	/// </Property>
	DECLARE_L3PROP_LONG(Direction_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Direction_ElectMix_4ST" type="L3LONG">
	/// 4����ת����
	/// </Property>
	DECLARE_L3PROP_LONG(Direction_ElectMix_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pressure_Oxygen_Cut" type="L3DOUBLE">
	/// �и���ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure_Oxygen_Cut)

	/// <Property class="CCCM5_Runtime_Data" name="Pressure_Oxygen_PreHeat" type="L3DOUBLE">
	/// Ԥ����ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure_Oxygen_PreHeat)

	/// <Property class="CCCM5_Runtime_Data" name="Pressure_CokeGas" type="L3DOUBLE">
	/// ��¯ú��ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure_CokeGas)

	/// <Property class="CCCM5_Runtime_Data" name="LogTime" type="L3DATETIME">
	/// ���ݼ�¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CCCM_Runtime_Data" name="Temp_In_Mold_12ST" type="L3LONG">
	/// �ᾧ��1-2����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_In_Mold_12ST)

	/// <Property class="CCCM_Runtime_Data" name="Temp_In_Mold_34ST" type="L3LONG">
	/// �ᾧ��3-4����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_In_Mold_34ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_N_1ST" type="L3DOUBLE">
	/// 1��խ���ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_N_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_N_2ST" type="L3DOUBLE">
	/// 2��խ���ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_N_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_N_3ST" type="L3DOUBLE">
	/// 3��խ���ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_N_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Dif_Mold_N_4ST" type="L3DOUBLE">
	/// 4��խ���ˮ�²�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Temp_Dif_Mold_N_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pressure_Cooling" type="L3DOUBLE">
	/// ����ˮ�ܹ���ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure_Cooling)
};

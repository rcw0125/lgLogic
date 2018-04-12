// �߼���CCCM5_Runtime_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM5_Runtime_Data :
	public CL3Object
{
public:
	CCCM5_Runtime_Data(void);
	virtual ~CCCM5_Runtime_Data(void);

	DECLARE_L3CLASS(CCCM5_Runtime_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM5_Runtime_Data)
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

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_12ST" type="L3DOUBLE">
	/// 1-2����ȴ��ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_12ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_34ST" type="L3DOUBLE">
	/// 3-4����ȴ��ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_34ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_2ndSect_1ST" type="L3DOUBLE">
	/// 1��2�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_2ndSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_3rdSect_1ST" type="L3DOUBLE">
	/// 1��3�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_3rdSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_4thSect_1ST" type="L3DOUBLE">
	/// 1��4�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_4thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_5thSect_1ST" type="L3DOUBLE">
	/// 1��5�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_5thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_2ndSect_1ST" type="L3DOUBLE">
	/// 1��2��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_2ndSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_3rdSect_1ST" type="L3DOUBLE">
	/// 1��3��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_3rdSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_4thSect_1ST" type="L3DOUBLE">
	/// 1��4��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_4thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_5thSect_1ST" type="L3DOUBLE">
	/// 1��5��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_5thSect_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_2ndSect_2ST" type="L3DOUBLE">
	/// 2��2�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_2ndSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_3rdSect_2ST" type="L3DOUBLE">
	/// 2��3�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_3rdSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_4thSect_2ST" type="L3DOUBLE">
	/// 2��4�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_4thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_5thSect_2ST" type="L3DOUBLE">
	/// 2��5�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_5thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_2ndSect_2ST" type="L3DOUBLE">
	/// 2��2��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_2ndSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_3rdSect_2ST" type="L3DOUBLE">
	/// 2��3��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_3rdSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_4thSect_2ST" type="L3DOUBLE">
	/// 2��4��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_4thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_5thSect_2ST" type="L3DOUBLE">
	/// 2��5��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_5thSect_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_2ndSect_3ST" type="L3DOUBLE">
	/// 3��2�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_2ndSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_3rdSect_3ST" type="L3DOUBLE">
	/// 3��3�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_3rdSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_4thSect_3ST" type="L3DOUBLE">
	/// 3��4�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_4thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_5thSect_3ST" type="L3DOUBLE">
	/// 3��5�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_5thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_2ndSect_3ST" type="L3DOUBLE">
	/// 3��2��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_2ndSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_3rdSect_3ST" type="L3DOUBLE">
	/// 3��3��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_3rdSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_4thSect_3ST" type="L3DOUBLE">
	/// 3��4��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_4thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_5thSect_3ST" type="L3DOUBLE">
	/// 3��5��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_5thSect_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_2ndSect_4ST" type="L3DOUBLE">
	/// 4��2�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_2ndSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_3rdSect_4ST" type="L3DOUBLE">
	/// 4��3�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_3rdSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_4thSect_4ST" type="L3DOUBLE">
	/// 4��4�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_4thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Wdh_5thSect_4ST" type="L3DOUBLE">
	/// 4��5�ο�����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Wdh_5thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_2ndSect_4ST" type="L3DOUBLE">
	/// 4��2��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_2ndSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_3rdSect_4ST" type="L3DOUBLE">
	/// 4��3��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_3rdSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_4thSect_4ST" type="L3DOUBLE">
	/// 4��4��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_4thSect_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Pres_CoolGas_Nrw_5thSect_4ST" type="L3DOUBLE">
	/// 4��5��խ����ѹ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pres_CoolGas_Nrw_5thSect_4ST)

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
	DECLARE_L3PROP_LONG(Temp_Def_ElectMix_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_2ST" type="L3LONG">
	/// 2������ˮ�²�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Def_ElectMix_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_3ST" type="L3LONG">
	/// 3������ˮ�²�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Def_ElectMix_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Temp_Def_ElectMix_4ST" type="L3LONG">
	/// 4������ˮ�²�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp_Def_ElectMix_4ST)

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

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller1_1ST" type="L3DOUBLE">
	/// 1��1#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller1_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller2_1ST" type="L3DOUBLE">
	/// 1��2#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller2_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller3_1ST" type="L3DOUBLE">
	/// 1��3#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller3_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller4_1ST" type="L3DOUBLE">
	/// 1��4#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller4_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller5_1ST" type="L3DOUBLE">
	/// 1��5#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller5_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller6_1ST" type="L3DOUBLE">
	/// 1��6#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller6_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller7_1ST" type="L3DOUBLE">
	/// 1��7#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller7_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller1_2ST" type="L3DOUBLE">
	/// 2��1#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller1_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller2_2ST" type="L3DOUBLE">
	/// 2��2#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller2_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller3_2ST" type="L3DOUBLE">
	/// 2��3#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller3_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller4_2ST" type="L3DOUBLE">
	/// 2��4#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller4_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller5_2ST" type="L3DOUBLE">
	/// 2��5#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller5_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller6_2ST" type="L3DOUBLE">
	/// 2��6#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller6_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller7_2ST" type="L3DOUBLE">
	/// 2��7#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller7_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller1_3ST" type="L3DOUBLE">
	/// 3��1#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller1_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller2_3ST" type="L3DOUBLE">
	/// 3��2#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller2_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller3_3ST" type="L3DOUBLE">
	/// 3��3#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller3_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller4_3ST" type="L3DOUBLE">
	/// 3��4#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller4_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller5_3ST" type="L3DOUBLE">
	/// 3��5#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller5_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller6_3ST" type="L3DOUBLE">
	/// 3��6#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller6_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller7_3ST" type="L3DOUBLE">
	/// 3��7#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller7_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller1_4ST" type="L3DOUBLE">
	/// 4��1#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller1_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller2_4ST" type="L3DOUBLE">
	/// 4��2#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller2_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller3_4ST" type="L3DOUBLE">
	/// 4��3#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller3_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller4_4ST" type="L3DOUBLE">
	/// 4��4#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller4_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller5_4ST" type="L3DOUBLE">
	/// 4��5#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller5_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller6_4ST" type="L3DOUBLE">
	/// 4��6#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller6_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Setup_Roller7_4ST" type="L3DOUBLE">
	/// 4��7#���趨ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Setup_Roller7_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller1_1ST" type="L3DOUBLE">
	/// 1��1#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller1_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller2_1ST" type="L3DOUBLE">
	/// 1��2#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller2_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller3_1ST" type="L3DOUBLE">
	/// 1��3#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller3_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller4_1ST" type="L3DOUBLE">
	/// 1��4#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller4_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller5_1ST" type="L3DOUBLE">
	/// 1��5#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller5_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller6_1ST" type="L3DOUBLE">
	/// 1��6#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller6_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller7_1ST" type="L3DOUBLE">
	/// 1��7#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller7_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller1_2ST" type="L3DOUBLE">
	/// 2��1#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller1_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller2_2ST" type="L3DOUBLE">
	/// 2��2#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller2_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller3_2ST" type="L3DOUBLE">
	/// 2��3#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller3_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller4_2ST" type="L3DOUBLE">
	/// 2��4#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller4_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller5_2ST" type="L3DOUBLE">
	/// 2��5#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller5_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller6_2ST" type="L3DOUBLE">
	/// 2��6#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller6_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller7_2ST" type="L3DOUBLE">
	/// 2��7#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller7_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller1_3ST" type="L3DOUBLE">
	/// 3��1#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller1_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller2_3ST" type="L3DOUBLE">
	/// 3��2#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller2_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller3_3ST" type="L3DOUBLE">
	/// 3��3#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller3_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller4_3ST" type="L3DOUBLE">
	/// 3��4#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller4_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller5_3ST" type="L3DOUBLE">
	/// 3��5#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller5_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller6_3ST" type="L3DOUBLE">
	/// 3��6#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller6_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller7_3ST" type="L3DOUBLE">
	/// 3��7#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller7_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller1_4ST" type="L3DOUBLE">
	/// 4��1#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller1_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller2_4ST" type="L3DOUBLE">
	/// 4��2#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller2_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller3_4ST" type="L3DOUBLE">
	/// 4��3#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller3_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller4_4ST" type="L3DOUBLE">
	/// 4��4#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller4_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller5_4ST" type="L3DOUBLE">
	/// 4��5#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller5_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller6_4ST" type="L3DOUBLE">
	/// 4��6#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller6_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Gap_Act_Roller7_4ST" type="L3DOUBLE">
	/// 4��7#��ʵ��ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Gap_Act_Roller7_4ST)

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

	/// <Property class="CCCM5_Runtime_Data" name="Catch_Count" type="L3LONG">
	/// �ɼ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Catch_Count)

	/// <Property class="CCCM5_Runtime_Data" name="LogTime" type="L3DATETIME">
	/// ���ݼ�¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

};

// �߼���CCCM5_Runtime2_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM5_Runtime2_Data :
	public CL3Object
{
public:
	CCCM5_Runtime2_Data(void);
	virtual ~CCCM5_Runtime2_Data(void);

	DECLARE_L3CLASS(CCCM5_Runtime2_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM5_Runtime2_Data)
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

	/// <Property class="CCCM5_Runtime_Data" name="LogTime" type="L3DATETIME">
	/// ���ݼ�¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CCCM5_Runtime_Data" name="Auto_Level_1ST" type="L3LONG">
	/// 1��Һ�����ģʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Level_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Auto_Level_2ST" type="L3LONG">
	/// 2��Һ�����ģʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Level_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Auto_Level_3ST" type="L3LONG">
	/// 3��Һ�����ģʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Level_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Auto_Level_4ST" type="L3LONG">
	/// 4��Һ�����ģʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Level_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Mode_Cooling_1ST" type="L3LONG">
	/// 1������ˮģʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Mode_Cooling_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Mode_Cooling_2ST" type="L3LONG">
	/// 2������ˮģʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Mode_Cooling_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Mode_Cooling_3ST" type="L3LONG">
	/// 3������ˮģʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Mode_Cooling_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Mode_Cooling_4ST" type="L3LONG">
	/// 4������ˮģʽ
	/// </Property>
	DECLARE_L3PROP_LONG(Mode_Cooling_4ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flag_SoftPress_1ST" type="L3LONG">
	/// 1��Ͷ����ѹ��
	/// </Property>
	DECLARE_L3PROP_LONG(Flag_SoftPress_1ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flag_SoftPress_2ST" type="L3LONG">
	/// 2��Ͷ����ѹ��
	/// </Property>
	DECLARE_L3PROP_LONG(Flag_SoftPress_2ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flag_SoftPress_3ST" type="L3LONG">
	/// 3��Ͷ����ѹ��
	/// </Property>
	DECLARE_L3PROP_LONG(Flag_SoftPress_3ST)

	/// <Property class="CCCM5_Runtime_Data" name="Flag_SoftPress_4ST" type="L3LONG">
	/// 4��Ͷ����ѹ��
	/// </Property>
	DECLARE_L3PROP_LONG(Flag_SoftPress_4ST)
};

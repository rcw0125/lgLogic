// �߼���CEquip_Runtime_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Runtime_Data :
	public CL3Object
{
public:
	CEquip_Runtime_Data(void);
	virtual ~CEquip_Runtime_Data(void);

	DECLARE_L3CLASS(CEquip_Runtime_Data,XGMESLogic\\EquipMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Runtime_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEquip_Runtime_Data" name="Catch_Time" type="L3DATETIME">
	/// �ɼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

	/// <Property class="CEquip_Runtime_Data" name="P_Before_CycPump_BOF4" type="L3FLOAT">
	/// 4#ת¯����ѭ���ú�ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Before_CycPump_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="P_After_CycPump_BOF4" type="L3FLOAT">
	/// 4#ת¯����ѭ����ǰѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_After_CycPump_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="P_Regenerator1" type="L3FLOAT">
	/// 1#����������ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Regenerator1)

	/// <Property class="CEquip_Runtime_Data" name="T_Regenerator1" type="L3FLOAT">
	/// 1#�����������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Regenerator1)

	/// <Property class="CEquip_Runtime_Data" name="P_Regenerator2" type="L3FLOAT">
	/// 2#����������ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Regenerator2)

	/// <Property class="CEquip_Runtime_Data" name="T_Regenerator2" type="L3FLOAT">
	/// 2#�����������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Regenerator2)

	/// <Property class="CEquip_Runtime_Data" name="P_Supply_Regenerator" type="L3FLOAT">
	/// ������������ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Supply_Regenerator)

	/// <Property class="CEquip_Runtime_Data" name="P_YiWen_BOF1" type="L3FLOAT">
	/// 1#һ��ǰ��ѹ
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="P_YiWen_BOF2" type="L3FLOAT">
	/// 2#һ��ǰ��ѹ
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="P_YiWen_BOF3" type="L3FLOAT">
	/// 3#һ��ǰ��ѹ
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="P_YiWen_BOF4" type="L3FLOAT">
	/// 4#һ��ǰ��ѹ
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Lose_YiWen_BOF1" type="L3FLOAT">
	/// 1#һ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="Lose_YiWen_BOF2" type="L3FLOAT">
	/// 2#һ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="Lose_YiWen_BOF3" type="L3FLOAT">
	/// 3#һ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="Lose_YiWen_BOF4" type="L3FLOAT">
	/// 4#һ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="P_Water_YiWen_BOF1" type="L3FLOAT">
	/// 1#һ����ȴˮˮѹ
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Water_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="P_Water_YiWen_BOF2" type="L3FLOAT">
	/// 2#һ����ȴˮˮѹ
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Water_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="P_Water_YiWen_BOF3" type="L3FLOAT">
	/// 3#һ����ȴˮˮѹ
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Water_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="P_Water_YiWen_BOF4" type="L3FLOAT">
	/// 4#һ����ȴˮˮѹ
	/// </Property>
	DECLARE_L3PROP_FLOAT(P_Water_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Jet_YiWen_BOF1" type="L3FLOAT">
	/// 1#һ����ͷˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Jet_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Jet_YiWen_BOF2" type="L3FLOAT">
	/// 2#һ����ͷˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Jet_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Jet_YiWen_BOF3" type="L3FLOAT">
	/// 3#һ����ͷˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Jet_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Jet_YiWen_BOF4" type="L3FLOAT">
	/// 4#һ����ͷˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Jet_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Spill_YiWen_BOF1" type="L3FLOAT">
	/// 1#һ������ˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Spill_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Spill_YiWen_BOF2" type="L3FLOAT">
	/// 2#һ������ˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Spill_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Spill_YiWen_BOF3" type="L3FLOAT">
	/// 3#һ������ˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Spill_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_Spill_YiWen_BOF4" type="L3FLOAT">
	/// 4#һ������ˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_Spill_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="T_Water_Cycle_BOF1" type="L3FLOAT">
	/// 1#ת¯�ǻ�ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Water_Cycle_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="T_Water_Cycle_BOF2" type="L3FLOAT">
	/// 2#ת¯�ǻ�ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Water_Cycle_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="T_Water_Cycle_BOF3" type="L3FLOAT">
	/// 3#ת¯�ǻ�ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Water_Cycle_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="T_Water_Cycle_BOF4" type="L3FLOAT">
	/// 4#ת¯�ǻ�ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Water_Cycle_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_YiWen_BOF1" type="L3FLOAT">
	/// 1#һ�ĳ��������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_YiWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_YiWen_BOF2" type="L3FLOAT">
	/// 2#һ�ĳ��������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_YiWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_YiWen_BOF3" type="L3FLOAT">
	/// 3#һ�ĳ��������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_YiWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_YiWen_BOF4" type="L3FLOAT">
	/// 4#һ�ĳ��������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_YiWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Lose_ErWen_BOF1" type="L3FLOAT">
	/// 1#��������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_ErWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="Lose_ErWen_BOF2" type="L3FLOAT">
	/// 2#��������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_ErWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="Lose_ErWen_BOF3" type="L3FLOAT">
	/// 3#��������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_ErWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="Lose_ErWen_BOF4" type="L3FLOAT">
	/// 4#��������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Lose_ErWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_ErWen_BOF1" type="L3FLOAT">
	/// 1#������ȴˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_ErWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_ErWen_BOF2" type="L3FLOAT">
	/// 2#������ȴˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_ErWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_ErWen_BOF3" type="L3FLOAT">
	/// 3#������ȴˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_ErWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="F_Water_ErWen_BOF4" type="L3FLOAT">
	/// 4#������ȴˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(F_Water_ErWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_ErWen_BOF1" type="L3FLOAT">
	/// 1#���ĳ��������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_ErWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_ErWen_BOF2" type="L3FLOAT">
	/// 2#���ĳ��������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_ErWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_ErWen_BOF3" type="L3FLOAT">
	/// 3#���ĳ��������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_ErWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="T_Out_ErWen_BOF4" type="L3FLOAT">
	/// 4#���ĳ��������¶�
	/// </Property>
	DECLARE_L3PROP_FLOAT(T_Out_ErWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Span_Valve_ErWen_BOF1" type="L3FLOAT">
	/// 1#���ķ��忪�ڶ�
	/// </Property>
	DECLARE_L3PROP_FLOAT(Span_Valve_ErWen_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="Span_Valve_ErWen_BOF2" type="L3FLOAT">
	/// 2#���ķ��忪�ڶ�
	/// </Property>
	DECLARE_L3PROP_FLOAT(Span_Valve_ErWen_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="Span_Valve_ErWen_BOF3" type="L3FLOAT">
	/// 3#���ķ��忪�ڶ�
	/// </Property>
	DECLARE_L3PROP_FLOAT(Span_Valve_ErWen_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="Span_Valve_ErWen_BOF4" type="L3FLOAT">
	/// 4#���ķ��忪�ڶ�
	/// </Property>
	DECLARE_L3PROP_FLOAT(Span_Valve_ErWen_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Rev_Fan_BOF1" type="L3FLOAT">
	/// 1#���ת��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Rev_Fan_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="Rev_Fan_BOF2" type="L3FLOAT">
	/// 2#���ת��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Rev_Fan_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="Rev_Fan_BOF3" type="L3FLOAT">
	/// 3#���ת��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Rev_Fan_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="Rev_Fan_BOF4" type="L3FLOAT">
	/// 4#���ת��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Rev_Fan_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="C_CO_Gas_BOF1" type="L3FLOAT">
	/// 1#ת¯ú��CO����
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_CO_Gas_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="C_CO_Gas_BOF2" type="L3FLOAT">
	/// 2#ת¯ú��CO����
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_CO_Gas_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="C_CO_Gas_BOF3" type="L3FLOAT">
	/// 3#ת¯ú��CO����
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_CO_Gas_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="C_CO_Gas_BOF4" type="L3FLOAT">
	/// 4#ת¯ú��CO����
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_CO_Gas_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="C_O2_Gas_BOF1" type="L3FLOAT">
	/// 1#ת¯ú��O2����
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_O2_Gas_BOF1)

	/// <Property class="CEquip_Runtime_Data" name="C_O2_Gas_BOF2" type="L3FLOAT">
	/// 2#ת¯ú��O2����
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_O2_Gas_BOF2)

	/// <Property class="CEquip_Runtime_Data" name="C_O2_Gas_BOF3" type="L3FLOAT">
	/// 3#ת¯ú��O2����
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_O2_Gas_BOF3)

	/// <Property class="CEquip_Runtime_Data" name="C_O2_Gas_BOF4" type="L3FLOAT">
	/// 4#ת¯ú��O2����
	/// </Property>
	DECLARE_L3PROP_FLOAT(C_O2_Gas_BOF4)

	/// <Property class="CEquip_Runtime_Data" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CEquip_Runtime_Data" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)
};

// �߼���CCCM_Tundish_StrandInfoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Tundish_StrandInfo :
	public CL3Object
{
public:
	CCCM_Tundish_StrandInfo(void);
	virtual ~CCCM_Tundish_StrandInfo(void);

	DECLARE_L3CLASS(CCCM_Tundish_StrandInfo,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Tundish_StrandInfo)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Tundish_StrandInfo" name="CastingNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Tundish_StrandInfo" name="TundishNo" type="L3STRING">
	/// �а����
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_Tundish_StrandInfo" name="TundishID" type="L3STRING">
	/// �а���
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CCCM_Tundish_StrandInfo" name="StrandNo" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Start_Time" type="L3DATETIME">
	/// �а�����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Stop_Time" type="L3DATETIME">
	/// �а�ͣ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Stop_Time)

	/// <Property class="CCCM_Tundish_StrandInfo" name="InjectionBarNo" type="L3STRING">
	/// �����ṹ���
	/// </Property>
	DECLARE_L3PROP_STRING(InjectionBarNo)

	/// <Property class="CCCM_Tundish_StrandInfo" name="WaterGap_Usage Case" type="L3SHORT">
	/// 
	/// ����ʽˮ��ʹ�����
	/// (1������ 2�����ߴ��� 3�������������ơ�4��������ԭ��)
	/// </Property>
	DECLARE_L3PROP_SHORT(WaterGap_Usage_Case)

	/// <Property class="CCCM_Tundish_StrandInfo" name="InjectionBar__Usage Case" type="L3STRING">
	/// ����ʹ�����
	/// </Property>
	DECLARE_L3PROP_STRING(InjectionBar_Usage_Case)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Reason_Holt_Casting" type="L3STRING">
	/// ͣ��ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason_Holt_Casting)

	/// <Property class="CCCM_Tundish_StrandInfo" name="RemainWeight" type="L3FLOAT">
	/// �а������ˮ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(RemainWeight)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Fir_HeatID" type="">
	/// ���ε�һ¯
	/// </Property>
	DECLARE_L3PROP_STRING(Fir_HeatID)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Last_HeatID" type="">
	/// �������һ¯
	/// </Property>
	DECLARE_L3PROP_STRING(Last_HeatID)

};

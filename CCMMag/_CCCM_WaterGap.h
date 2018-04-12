// �߼���CCCM_WaterGapͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_WaterGap :
	public CL3Object
{
public:
	CCCM_WaterGap(void);
	virtual ~CCCM_WaterGap(void);

	DECLARE_L3CLASS(CCCM_WaterGap,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_WaterGap)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_WaterGap" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	
	/// <Property class="CCCM_WaterGap" name="StrandNo" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(StrandNo)

	/// <Property class="CCCM_WaterGap" name="GapID" type="L3STRING">
	/// ˮ��
	/// </Property>
	DECLARE_L3PROP_STRING(GapID)

	/// <Property class="CCCM_WaterGap" name="GapLife" type="L3LONG">
	/// ˮ������
	/// </Property>
	DECLARE_L3PROP_LONG(GapLife)

	/// <Property class="CCCM_WaterGap" name="Factory" type="L3STRING">
	/// ˮ�ڳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCCM_WaterGap" name="Start_Time" type="L3DATETIME">
	/// ˮ�ڸ�����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CCCM_WaterGap" name="End_Time" type="L3DATETIME">
	/// ˮ�ڸ�������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	
	/// <Property class="CCCM_WaterGap" name="Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

	/// <Property class="CCCM_WaterGap" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_WaterGap" name="MatType" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(MatType)

};

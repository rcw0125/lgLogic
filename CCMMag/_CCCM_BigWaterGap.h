// �߼���CCCM_BigWaterGapͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_BigWaterGap :
	public CL3Object
{
public:
	CCCM_BigWaterGap(void);
	virtual ~CCCM_BigWaterGap(void);

	DECLARE_L3CLASS(CCCM_BigWaterGap,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_BigWaterGap)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_BigWaterGap" name="CCMID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_BigWaterGap" name="StrandNo" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(StrandNo)

	/// <Property class="CCCM_BigWaterGap" name="GapID" type="L3STRING">
	/// ˮ��
	/// </Property>
	DECLARE_L3PROP_STRING(GapID)

	/// <Property class="CCCM_BigWaterGap" name="Factory" type="L3STRING">
	/// ˮ�ڳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCCM_BigWaterGap" name="MatType" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(MatType)

	/// <Property class="CCCM_BigWaterGap" name="ChangeTime" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(ChangeTime)

	/// <Property class="CCCM_BigWaterGap" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_BigWaterGap" name="GapLife" type="L3LONG">
	/// ʹ������
	/// </Property>
	DECLARE_L3PROP_LONG(GapLife)

	/// <Property class="CCCM_BigWaterGap" name="Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)


};

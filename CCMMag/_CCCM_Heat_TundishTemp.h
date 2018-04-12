// �߼���CCCM_Heat_TundishTempͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_TundishTemp :
	public CL3Object
{
public:
	CCCM_Heat_TundishTemp(void);
	virtual ~CCCM_Heat_TundishTemp(void);

	DECLARE_L3CLASS(CCCM_Heat_TundishTemp,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_TundishTemp)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_TundishTemp" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_TundishTemp" name="CCMID" type="L3SHORT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_TundishTemp" name="TempID" type="L3SHORT">
	/// �а����µ�
	/// </Property>
	DECLARE_L3PROP_SHORT(TempID)

	/// <Property class="CCCM_Heat_TundishTemp" name="Temp" type="L3SHORT">
	/// ����ֵ
	/// </Property>
	DECLARE_L3PROP_SHORT(Temp)

	/// <Property class="CCCM_Heat_TundishTemp" name="Measure_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Measure_Time)

	/// <Property class="CCCM_Heat_TundishTemp" name="InValidFlag" type="L3SHORT">
	/// ��Ч(������ͳ��)��־
	/// </Property>
	DECLARE_L3PROP_SHORT(InValidFlag)
};

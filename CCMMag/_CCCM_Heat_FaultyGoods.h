// �߼���CCCM_Heat_FaultyGoodsͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_FaultyGoods :
	public CL3Object
{
public:
	CCCM_Heat_FaultyGoods(void);
	virtual ~CCCM_Heat_FaultyGoods(void);

	DECLARE_L3CLASS(CCCM_Heat_FaultyGoods,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_FaultyGoods)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_FaultyGoods" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_FaultyGoods" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_FaultyGoods" name="TreatNo" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Heat_FaultyGoods" name="BloomID" type="L3STRING">
	/// 
	/// ���ϸ�֧��
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(BloomID)

	/// <Property class="CCCM_Heat_FaultyGoods" name="Weight" type="L3FLOAT">
	/// 
	/// ���ϸ�����
	/// 
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CCCM_Heat_FaultyGoods" name="Reason" type="L3STRING">
	/// 
	/// ���ϸ�ԭ��
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

	/// <Property class="CCCM_Heat_FaultyGoods" name="Log_Time" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

};

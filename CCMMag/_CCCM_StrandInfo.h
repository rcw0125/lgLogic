// �߼���CCCM_StrandInfoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_StrandInfo :
	public CL3Object
{
public:
	CCCM_StrandInfo(void);
	virtual ~CCCM_StrandInfo(void);

	DECLARE_L3CLASS(CCCM_StrandInfo,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_StrandInfo)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_StrandInfo" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_StrandInfo" name="StrandNo" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(StrandNo)

	/// <Property class="CCCM_StrandInfo" name="OnOff" type="L3LONG">
	/// ��ͣ��״̬
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff)

	/// <Property class="CCCM_StrandInfo" name="ChangeTime" type="L3DATETIME">
	/// ��ͣ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(ChangeTime)

	/// <Property class="CCCM_StrandInfo" name="CastingNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_StrandInfo" name="TundishNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_StrandInfo" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

};

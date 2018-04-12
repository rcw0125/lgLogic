// �߼���CCCM_Heat_ProtectSlagͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_ProtectSlag :
	public CL3Object
{
public:
	CCCM_Heat_ProtectSlag(void);
	virtual ~CCCM_Heat_ProtectSlag(void);

	DECLARE_L3CLASS(CCCM_Heat_ProtectSlag,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_ProtectSlag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	///2009-02-13 ʹ�������������

	/// <Property class="CCCM_Heat_ProtectSlag" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_ProtectSlag" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_ProtectSlag" name="StrandID" type="L3SHORT">
	/// �ᾧ������
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandID)

	/// <Property class="CCCM_Heat_ProtectSlag" name="Element" type="L3STRING">
	/// �������ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CCCM_Heat_ProtectSlag" name="Factory" type="L3STRING">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCCM_Heat_ProtectSlag" name="BatchNo" type="L3STRING">
	/// ��������������
	/// </Property>
	DECLARE_L3PROP_STRING(BatchNo)

	/// <Property class="CCCM_Heat_ProtectSlag" name="UseInformation" type="L3STRING">
	/// ʹ�����
	/// </Property>
	DECLARE_L3PROP_STRING(UseInformation)

	/// <Property class="CCCM_Heat_ProtectSlag" name="Amount" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)


};

// �߼���CCCM_Heat_ProtectMatͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_ProtectMat :
	public CL3Object
{
public:
	CCCM_Heat_ProtectMat(void);
	virtual ~CCCM_Heat_ProtectMat(void);

	DECLARE_L3CLASS(CCCM_Heat_ProtectMat,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_ProtectMat)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_ProtectMat" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_ProtectMat" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_ProtectMat" name="Element" type="L3STRING">
	/// �����׹ܲ���
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CCCM_Heat_ProtectMat" name="Factory" type="L3STRING">
	/// �����׹ܲ���
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

};

// �߼���CCCM_Heat_Coverͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_Cover :
	public CL3Object
{
public:
	CCCM_Heat_Cover(void);
	virtual ~CCCM_Heat_Cover(void);

	DECLARE_L3CLASS(CCCM_Heat_Cover,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Cover)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	///2009-02-13 ������κš�ʹ�����

	/// <Property class="CCCM_Heat_Cover" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Cover" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Cover" name="Element" type="L3STRING">
	/// 
	/// �а����Ǽ�����
	/// (1-þ�ʡ�2-���ʡ�3-��̼��4-��ͨ)
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CCCM_Heat_Cover" name="Amount" type="L3FLOAT">
	/// �а����Ǽ�����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Amount)

	/// <Property class="CCCM_Heat_Cover" name="Origin" type="L3STRING">
	/// 
	/// �а����Ǽ�����
	/// (1-ͨ�2-������3-���顢4-����)
	/// </Property>
	DECLARE_L3PROP_STRING(Origin)


	/// <Property class="CCCM_Heat_Cover" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)


	/// <Property class="CCCM_Heat_Cover" name="UseInformation" type="L3STRING">
	/// ʹ�����
	/// </Property>
	DECLARE_L3PROP_STRING(UseInformation)


};

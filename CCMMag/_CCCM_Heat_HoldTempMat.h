// �߼���CCCM_Heat_HoldTempMatͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_HoldTempMat :
	public CL3Object
{
public:
	CCCM_Heat_HoldTempMat(void);
	virtual ~CCCM_Heat_HoldTempMat(void);

	DECLARE_L3CLASS(CCCM_Heat_HoldTempMat,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_HoldTempMat)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	///2009-02-13 ������κš�ʹ�����


	/// <Property class="CCCM_Heat_HoldTempMat" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_HoldTempMat" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_HoldTempMat" name="Element" type="L3STRING">
	/// 
	/// �а����¼�����
	/// (1-���ʡ�2-̼������)
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CCCM_Heat_HoldTempMat" name="Weight" type="L3FLOAT">
	/// �а����¼�����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CCCM_Heat_HoldTempMat" name="Origin" type="L3STRING">
	/// �а����¼�����
	/// </Property>
	DECLARE_L3PROP_STRING(Origin)


	/// <Property class="CCCM_Heat_HoldTempMat" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)


	/// <Property class="CCCM_Heat_HoldTempMat" name="UseInformation" type="L3STRING">
	/// ʹ�����
	/// </Property>
	DECLARE_L3PROP_STRING(UseInformation)

};

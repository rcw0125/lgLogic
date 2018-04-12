// �߼���CIronLadle_Baseͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CIronLadle_Base :
	public CL3Object
{
public:
	CIronLadle_Base(void);
	virtual ~CIronLadle_Base(void);

	DECLARE_L3CLASS(CIronLadle_Base,XGMESLogic\\IronLadleMag, IronLadleID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Base)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CIronLadle_Base" name="IronLadleID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadleID)

	/// <Property class="CIronLadle_Base" name="TieID" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TieID)

	/// <Property class="CIronLadle_Base" name="Status" type="L3STRING">
	/// ״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CIronLadle_Base" name="ComFlag" type="L3LONG">
	/// ��ɱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(ComFlag)
    
	/// <Property class="CIronLadle_Base" name="IronLadle_Age" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(IronLadle_Age)

	/// <Property class="CIronLadle_Base" name="Tare_Weight" type="L3FLOAT">
	/// Ƥ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Tare_Weight)

	/// <Property class="CIronLadle_Base" name="Gross_Weight" type="L3FLOAT">
	/// ë��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Gross_Weight)

	/// <Property class="CIronLadle_Base" name="Net_Weight" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Net_Weight)

	/// <Property class="CIronLadle_Base" name="Refra_Produce" type="L3STRING">
	/// �Ͳĳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Produce)

	/// <Property class="CIronLadle_Base" name="Refra_ID" type="L3STRING">
	/// �Ͳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_ID)
	
	//2009-03-17
	/// <Property class="CIronLadle_Base" name="Small_FireID" type="L3LONG">
	/// С��濾����
	/// </Property>
	DECLARE_L3PROP_LONG(Small_FireID)

	/// <Property class="CIronLadle_Base" name="Middle_FireID" type="L3LONG">
	/// �л�濾����
	/// </Property>
	DECLARE_L3PROP_LONG(Middle_FireID)

	/// <Property class="CIronLadle_Base" name="Big_FireID" type="L3LONG">
	/// ���濾����
	/// </Property>
	DECLARE_L3PROP_LONG(Big_FireID)

};

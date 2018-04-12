// �߼���TB_L3_ANACOMMISSIONͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class TB_L3_ANACOMMISSION :
	public CL3Object
{
public:
	TB_L3_ANACOMMISSION(void);
	virtual ~TB_L3_ANACOMMISSION(void);

	DECLARE_L3CLASS(TB_L3_ANACOMMISSION,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(TB_L3_ANACOMMISSION)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="TB_L3_ANACOMMISSION" name="CommissionID" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(CommissionID)

	/// <Property class="TB_L3_ANACOMMISSION" name="SampID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(SampID)

	/// <Property class="TB_L3_ANACOMMISSION" name="SampSort" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(SampSort)

	/// <Property class="TB_L3_ANACOMMISSION" name="SampPlace" type="L3STRING">
	/// �����ص�
	/// </Property>
	DECLARE_L3PROP_STRING(SampPlace)

	/// <Property class="TB_L3_ANACOMMISSION" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="TB_L3_ANACOMMISSION" name="Contract" type="L3STRING">
	/// Э���
	/// </Property>
	DECLARE_L3PROP_STRING(Contract)

	/// <Property class="TB_L3_ANACOMMISSION" name="SendDate" type="L3STRING">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(SendDate)

	/// <Property class="TB_L3_ANACOMMISSION" name="Permit_Delete_Flag" type="L3LONG">
	/// ����ɾ����־
	/// </Property>
	DECLARE_L3PROP_LONG(Permit_Delete_Flag)

};

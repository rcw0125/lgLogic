// �߼���CBase_Operator_IDͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Operator_ID :
	public CL3Object
{
public:
	CBase_Operator_ID(void);
	virtual ~CBase_Operator_ID(void);

	DECLARE_L3CLASS(CBase_Operator_ID,XGMESLogic\\BaseDataMag, Operator)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Operator_ID)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Operator_ID" name="Operator" type="L3STRING">
	/// Ա����
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CBase_Operator_ID" name="Operator_Name" type="L3STRING">
	/// Ա������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator_Name)

};

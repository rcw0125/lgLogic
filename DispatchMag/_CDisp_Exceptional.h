// �߼���CDisp_Exceptionalͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDisp_Exceptional :
	public CL3Object
{
public:
	CDisp_Exceptional(void);
	virtual ~CDisp_Exceptional(void);

	DECLARE_L3CLASS(CDisp_Exceptional,XGMESLogic\\DispatchMag, IDObject)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Exceptional)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDisp_Exceptional" name="IDObject" type="L3STRING">
	/// ID��ʶ=����+��λ+���
	/// </Property>
	DECLARE_L3PROP_STRING(IDObject)

	/// <Property class="CDisp_Exceptional" name="CreateDate" type="L3STRING">
	/// ����[yyyyMMdd]
	/// </Property>
	DECLARE_L3PROP_STRING(CreateDate)

	/// <Property class="CDisp_Exceptional" name="UnitID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CDisp_Exceptional" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDisp_Exceptional" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDisp_Exceptional" name="CreateTime" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CreateTime)

	/// <Property class="CDisp_Exceptional" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	//2009-04-09
	/// <Property class="CDisp_Exceptional" name="SendFlag" type="L3LONG">
	/// �ϴ���־ 0:δ�ϴ�;1:���ϴ�
	/// </Property>
	DECLARE_L3PROP_LONG(SendFlag)

};

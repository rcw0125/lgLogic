// �߼���CRetrunData_NCͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CRetrunData_NC :
	public CL3Object
{
public:
	CRetrunData_NC(void);
	virtual ~CRetrunData_NC(void);

	DECLARE_L3CLASS(CRetrunData_NC,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRetrunData_NC)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CRetrunData_NC" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CRetrunData_NC" name="BillType" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(BillType)

	/// <Property class="CRetrunData_NC" name="Flag" type="L3STRING">
	/// �ɹ���־
	/// </Property>
	DECLARE_L3PROP_STRING(Flag)

	/// <Property class="CRetrunData_NC" name="Remark" type="L3STRING">
	/// ʧ��ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Remark)

	/// <Property class="CRetrunData_NC" name="CreateTime" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

	/// <Property class="CRetrunData_NC" name="Other1" type="L3STRING">
	/// ����1
	/// </Property>
	DECLARE_L3PROP_STRING(Other1)

	/// <Property class="CRetrunData_NC" name="Other2" type="L3STRING">
	/// ����2
	/// </Property>
	DECLARE_L3PROP_STRING(Other2)

	/// <Property class="CRetrunData_NC" name="Other3" type="L3STRING">
	/// ����3
	/// </Property>
	DECLARE_L3PROP_STRING(Other3)

};

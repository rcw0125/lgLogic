// �߼���CDisp_Exceptional_Itemsͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDisp_Exceptional_Items :
	public CL3Object
{
public:
	CDisp_Exceptional_Items(void);
	virtual ~CDisp_Exceptional_Items(void);

	DECLARE_L3CLASS(CDisp_Exceptional_Items,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Exceptional_Items)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDisp_Exceptional_Items" name="IDObject" type="L3STRING">
	/// ID��ʶ=����+��λ+���
	/// </Property>
	DECLARE_L3PROP_STRING(IDObject)

	/// <Property class="CDisp_Exceptional_Items" name="Items" type="L3STRING">
	/// �쳣��Ŀ
	/// </Property>
	DECLARE_L3PROP_STRING(Items)

	/// <Property class="CDisp_Exceptional_Items" name="BeginTime" type="L3STRING">
	/// ��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(BeginTime)

	/// <Property class="CDisp_Exceptional_Items" name="EndTime" type="L3STRING">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(EndTime)

	/// <Property class="CDisp_Exceptional_Items" name="TimeSpan" type="L3LONG">
	/// ʱ����[����]
	/// </Property>
	DECLARE_L3PROP_LONG(TimeSpan)

	/// <Property class="CDisp_Exceptional_Items" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CDisp_Exceptional_Items" name="CreateTime" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(CreateTime)

	/// <Property class="CDisp_Exceptional_Items" name="UnitID" type="L3STRING">
	/// �������� 2009-04-10 liuzhiqiang
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)


};

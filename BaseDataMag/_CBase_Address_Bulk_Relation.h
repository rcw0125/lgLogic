// �߼���CBase_Address_Bulk_Relationͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Address_Bulk_Relation :
	public CL3Object
{
public:
	CBase_Address_Bulk_Relation(void);
	virtual ~CBase_Address_Bulk_Relation(void);

	DECLARE_L3CLASS(CBase_Address_Bulk_Relation,XGMESLogic\\BaseDataMag, PLC_Address)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Address_Bulk_Relation)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Address_Bulk_Relation" name="PLC_Address" type="L3STRING">
	/// PLC��ַ
	/// </Property>
	DECLARE_L3PROP_STRING(PLC_Address)

	/// <Property class="CBase_Address_Bulk_Relation" name="AreaID" type="L3STRING">
	/// �ϲֱ��� ��Ϊ1��Ϊ����;��Ϊ2����ݹ���·��(��LF��RH)өʯ����С��50kg��һ�����ڶ���)
	/// </Property>
	DECLARE_L3PROP_STRING(Area)

};

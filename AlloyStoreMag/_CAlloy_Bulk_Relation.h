// �߼���CAlloy_Bulk_Relationͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAlloy_Bulk_Relation :
	public CL3Object
{
public:
	CAlloy_Bulk_Relation(void);
	virtual ~CAlloy_Bulk_Relation(void);

	DECLARE_L3CLASS(CAlloy_Bulk_Relation,XGMESLogic\\AlloyStoreMag, Alloy_Area)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Bulk_Relation)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Bulk_Relation" name="Alloy_Area" type="L3STRING">
	/// �Ͻ��ϲֱ���
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Area)

	/// <Property class="CAlloy_Bulk_Relation" name="Alloy_Code" type="L3STRING">
	/// �Ͻ����
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_Bulk_Relation" name="TopSlagFlag" type="L3LONG">
	/// ������־
	/// </Property>
	DECLARE_L3PROP_LONG(TopSlagFlag)

	/// <Property class="CAlloy_Bulk_Relation" name="Alloy_Vendor" type="L3STRING">
	/// ����
	/// </Property> 2009-03-19
	DECLARE_L3PROP_STRING(Alloy_Vendor)
};

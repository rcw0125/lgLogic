// �߼���CBulk_Bulk_Relationͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBulk_Bulk_Relation :
	public CL3Object
{
public:
	CBulk_Bulk_Relation(void);
	virtual ~CBulk_Bulk_Relation(void);

	DECLARE_L3CLASS(CBulk_Bulk_Relation,XGMESLogic\\BulkStoreMag, Bulk_Area)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Bulk_Relation)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBulk_Bulk_Relation" name="Bulk_Area" type="L3STRING">
	/// ɢ״���ϲ�
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Area)

	/// <Property class="CBulk_Bulk_Relation" name="Bulk_Code" type="L3STRING">
	/// ɢ״�ϱ���
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Bulk_Relation" name="TopSlagFlag" type="L3LONG">
	/// ������־ ��Ϊ1��Ϊ����;��Ϊ2����ݹ���·������LF��RH��өʯ����С��50kg��һ�����ڶ���)
	/// </Property>
	DECLARE_L3PROP_LONG(TopSlagFlag)
};

// �߼���CBulk_Codeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBulk_Code :
	public CL3Object
{
public:
	CBulk_Code(void);
	virtual ~CBulk_Code(void);

	DECLARE_L3CLASS(CBulk_Code,XGMESLogic\\BulkStoreMag, Bulk_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Code)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBulk_Code" name="Bulk_Code" type="L3STRING">
	/// ɢ״�ϴ���
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Code" name="Bulk_Des" type="L3STRING">
	/// ɢ״������
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Des)

	/// <Property class="CBulk_Code" name="Amount" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)


};

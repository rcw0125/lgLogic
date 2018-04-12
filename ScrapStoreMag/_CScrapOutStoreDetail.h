// �߼���CScrapOutStoreDetailͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CScrapOutStoreDetail :
	public CL3Object
{
public:
	CScrapOutStoreDetail(void);
	virtual ~CScrapOutStoreDetail(void);

	DECLARE_L3CLASS(CScrapOutStoreDetail,XGMESLogic\\ScrapStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CScrapOutStoreDetail)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CScrapOutStoreDetail" name="SCRAP_SLOT_ID" type="L3STRING">
	/// �ϸֶ�ID
	/// </Property>
	DECLARE_L3PROP_STRING(SCRAP_SLOT_ID)

	/// <Property class="CScrapOutStoreDetail" name="MATERIAL" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(MATERIAL)

	/// <Property class="CScrapOutStoreDetail" name="MATERIAL_CODE" type="L3STRING">
	/// ���ϴ���
	/// </Property>
	DECLARE_L3PROP_STRING(MATERIAL_CODE)

	/// <Property class="CScrapOutStoreDetail" name="AMOUNT" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(AMOUNT)

};

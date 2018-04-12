// �߼���CAlloy_Element_Tel_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAlloy_Element_Tel_Data :
	public CL3Object
{
public:
	CAlloy_Element_Tel_Data(void);
	virtual ~CAlloy_Element_Tel_Data(void);

	DECLARE_L3CLASS(CAlloy_Element_Tel_Data,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Element_Tel_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Element_Tel_Data" name="Rec_Time" type="L3STRING">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Rec_Time)

	/// <Property class="CAlloy_Element_Tel_Data" name="vproductbatchcode" type="L3STRING">
	/// �Ͻ�����
	/// </Property>
	DECLARE_L3PROP_STRING(vstobatchcode)

	/// <Property class="CAlloy_Element_Tel_Data" name="vcheckbillcode" type="L3STRING">
	/// ���鵥��
	/// </Property>
	DECLARE_L3PROP_STRING(vcheckbillcode)

	/// <Property class="CAlloy_Element_Tel_Data" name="bcompcheck" type="L3STRING">
	/// �Ƿ�ɷּ���
	/// </Property>
	DECLARE_L3PROP_STRING(bcompcheck)

	/// <Property class="CAlloy_Element_Tel_Data" name="nassistchecknum" type="L3LONG">
	/// ���츨����
	/// </Property>
	DECLARE_L3PROP_LONG(ninassistnum)

	/// <Property class="CAlloy_Element_Tel_Data" name="cstoreorganization" type="L3STRING">
	/// �����֯
	/// </Property>
	DECLARE_L3PROP_STRING(cstoreorganization)

	/// <Property class="CAlloy_Element_Tel_Data" name="cpraycorp" type="L3STRING">
	/// ���칫˾
	/// </Property>
	DECLARE_L3PROP_STRING(cpraycorp)

	/// <Property class="CAlloy_Element_Tel_Data" name="ccheckbillid" type="L3STRING">
	/// �������鵥����
	/// </Property>
	DECLARE_L3PROP_STRING(ccheckbillid)

	/// <Property class="CAlloy_Element_Tel_Data" name="cbaseid" type="L3STRING">
	/// �����Ʒ
	/// </Property>
	DECLARE_L3PROP_STRING(cbaseid)

	/// <Property class="CAlloy_Element_Tel_Data" name="vsamplecode" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(vsamplecode)

	/// <Property class="CAlloy_Element_Tel_Data" name="nnum" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(ninnum)

	/// <Property class="CAlloy_Element_Tel_Data" name="ccheckitemid" type="L3STRING">
	/// ����ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(ccheckitemid)

	/// <Property class="CAlloy_Element_Tel_Data" name="cresult" type="L3DOUBLE">
	/// ������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(cresult)
	
};

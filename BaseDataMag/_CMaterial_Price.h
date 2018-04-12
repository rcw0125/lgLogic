// �߼���CMaterial_Priceͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMaterial_Price :
	public CL3Object
{
public:
	CMaterial_Price(void);
	virtual ~CMaterial_Price(void);

	DECLARE_L3CLASS(CMaterial_Price,XGMESLogic\\BaseDataMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMaterial_Price)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CMaterial_Price" name="Material_Code" type="L3STRING">
	/// ���ϱ���
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Code)

	/// <Property class="CMaterial_Price" name="Material_Name" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Material_Name)

	/// <Property class="CMaterial_Price" name="Standard_Price" type="L3DOUBLE">
	/// ��׼��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Standard_Price)

	/// <Property class="CMaterial_Price" name="Budget_Price_Jan" type="L3DOUBLE">
	/// һ��Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Jan)

	/// <Property class="CMaterial_Price" name="Budget_Price_Feb" type="L3DOUBLE">
	/// ����Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Feb)

	/// <Property class="CMaterial_Price" name="Budget_Price_Mar" type="L3DOUBLE">
	/// ����Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Mar)

	/// <Property class="CMaterial_Price" name="Budget_Price_Apr" type="L3DOUBLE">
	/// ����Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Apr)

	/// <Property class="CMaterial_Price" name="Budget_Price_May" type="L3DOUBLE">
	/// ����Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_May)

	/// <Property class="CMaterial_Price" name="Budget_Price_Jun" type="L3DOUBLE">
	/// ����Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Jun)

	/// <Property class="CMaterial_Price" name="Budget_Price_Jul" type="L3DOUBLE">
	/// ����Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Jul)

	/// <Property class="CMaterial_Price" name="Budget_Price_Aug" type="L3DOUBLE">
	/// ����Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Aug)

	/// <Property class="CMaterial_Price" name="Budget_Price_Sep" type="L3DOUBLE">
	/// ����Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Sep)

	/// <Property class="CMaterial_Price" name="Budget_Price_Oct" type="L3DOUBLE">
	/// ʮ��Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Oct)

	/// <Property class="CMaterial_Price" name="Budget_Price_Nov" type="L3DOUBLE">
	/// ʮһ��Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Nov)

	/// <Property class="CMaterial_Price" name="Budget_Price_Dec" type="L3DOUBLE">
	/// ʮ����Ԥ��۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Budget_Price_Dec)

	/// <Property class="CMaterial_Price" name="Work_Year" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Work_Year)

	/// <Property class="CMaterial_Price" name="Latest_Price" type="L3DOUBLE">
	/// ���¼۸�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Latest_Price)

	/// <Property class="CMaterial_Price" name="Object_ID" type="L3STRING">
	/// �ؼ���
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};

// �߼���CAlloy_Tel_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAlloy_Trans_Tel_Data :
	public CL3Object
{
public:
	CAlloy_Trans_Tel_Data(void);
	virtual ~CAlloy_Trans_Tel_Data(void);

	DECLARE_L3CLASS(CAlloy_Trans_Tel_Data,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Trans_Tel_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Trans_Tel_Data" name="Rec_Time" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Rec_Time)

	/// <Property class="CAlloy_Trans_Tel_Data" name="cinventoryid" type="L3STRING">
	/// ����ID
	/// </Property>
	DECLARE_L3PROP_STRING(cinventoryid)

	/// <Property class="CAlloy_Trans_Tel_Data" name="Invcode" type="L3STRING">
	/// ���ϱ���
	/// </Property>
	DECLARE_L3PROP_STRING(Invcode)

	/// <Property class="CAlloy_Trans_Tel_Data" name="Invname" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Invname)

	/// <Property class="CAlloy_Trans_Tel_Data" name="Invspec" type="L3STRING">
	/// ���Ϲ��
	/// </Property>
	DECLARE_L3PROP_STRING(Invspec)

	/// <Property class="CAlloy_Trans_Tel_Data" name="Invtype" type="L3STRING">
	/// �����ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Invtype)

	/// <Property class="CAlloy_Trans_Tel_Data" name="Dbilldate" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(dbizdate)

	/// <Property class="CAlloy_Trans_Tel_Data" name="coutwarehouseid" type="L3STRING">
	/// ����ֿ�
	/// </Property>
	DECLARE_L3PROP_STRING(cotherwhid)

	/// <Property class="CAlloy_Trans_Tel_Data" name="cinwarehouseid" type="L3STRING">
	/// ���ֿ�
	/// </Property>
	DECLARE_L3PROP_STRING(cwarehouseid)

	/// <Property class="CAlloy_Trans_Tel_Data" name="nnum" type="L3DOUBLE">
	/// ת������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ninnum)

	/// <Property class="CAlloy_Trans_Tel_Data" name="nassistnum" type="L3LONG">
	/// ת�⸨����
	/// </Property>
	DECLARE_L3PROP_LONG(ninassistnum)

	/// <Property class="CAlloy_Trans_Tel_Data" name="vbatchcode" type="L3STRING">
	/// �Ͻ�����
	/// </Property>
	DECLARE_L3PROP_STRING(vbatchcode)


	/// <Property class="CAlloy_Trans_Tel_Data" name="zdy1" type="L3STRING">
	/// �Զ���1
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef1)

	/// <Property class="CAlloy_Trans_Tel_Data" name="zdy2" type="L3STRING">
	/// �Զ���2
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef2)

	/// <Property class="CAlloy_Trans_Tel_Data" name="zdy3" type="L3STRING">
	/// �Զ���3
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef3)

	/// <Property class="CAlloy_Trans_Tel_Data" name="zdy4" type="L3STRING">
	/// �Զ���4
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef4)

	/// <Property class="CAlloy_Trans_Tel_Data" name="zdy5" type="L3STRING">
	/// �Զ���5
	/// </Property>
	DECLARE_L3PROP_STRING(vuserdef5)

	/// <Property class="CAlloy_Trans_Tel_Data" name="zyx1" type="L3STRING">
	/// ������1
	/// </Property>
	DECLARE_L3PROP_STRING(vfree1)

	/// <Property class="CAlloy_Trans_Tel_Data" name="zyx2" type="L3STRING">
	/// ������2
	/// </Property>
	DECLARE_L3PROP_STRING(vfree2)


	/// <Property class="CAlloy_Trans_Tel_Data" name="zyx3" type="L3STRING">
	/// ������3
	/// </Property>
	DECLARE_L3PROP_STRING(vfree3)


	/// <Property class="CAlloy_Trans_Tel_Data" name="zyx4" type="L3STRING">
	/// ������4
	/// </Property>
	DECLARE_L3PROP_STRING(vfree4)


	/// <Property class="CAlloy_Trans_Tel_Data" name="zyx5" type="L3STRING">
	/// ������5
	/// </Property>
	DECLARE_L3PROP_STRING(vfree5)


	/// <Property class="CAlloy_Trans_Tel_Data" name="pk_corp" type="L3STRING">
	/// ��˾
	/// </Property>
	DECLARE_L3PROP_STRING(pk_corp)


};

// �߼���CPlan_Order_Tel_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CPlan_Order_Tel_Data :
	public CL3Object
{
public:
	CPlan_Order_Tel_Data(void);
	virtual ~CPlan_Order_Tel_Data(void);

	DECLARE_L3CLASS(CPlan_Order_Tel_Data,XGMESLogic\\PlanMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Order_Tel_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_Order_Tel_Data" name="Jhddh" type="L3STRING">
	/// �ƻ�������
	/// </Property>
	DECLARE_L3PROP_STRING(jhddh)

	/// <Property class="CPlan_Order_Tel_Data" name="Xsddh" type="L3STRING">
	/// ���۶�����
	/// </Property>
	DECLARE_L3PROP_STRING(xsddh)

	/// <Property class="CPlan_Order_Tel_Data" name="pk_invbasdoc" type="L3STRING">
	/// ��Ʒ
	/// </Property>
	DECLARE_L3PROP_STRING(wlbmid)

	/// <Property class="CPlan_Order_Tel_Data" name="pk_produce" type="L3STRING">
	/// ��Ʒ������������
	/// </Property>
	DECLARE_L3PROP_STRING(pk_produce)

	/// <Property class="CPlan_Order_Tel_Data" name="Invcode" type="L3STRING">
	/// ���ϱ���
	/// </Property>
	DECLARE_L3PROP_STRING(wlbm)

	/// <Property class="CPlan_Order_Tel_Data" name="Invname" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(wlmc)

	/// <Property class="CPlan_Order_Tel_Data" name="Invspec" type="L3STRING">
	/// ���Ϲ��
	/// </Property>
	DECLARE_L3PROP_STRING(invspec)

	/// <Property class="CPlan_Order_Tel_Data" name="Invtype" type="L3STRING">
	/// �����ͺ�
	/// </Property>
	DECLARE_L3PROP_STRING(invtype)

	/// <Property class="CPlan_Order_Tel_Data" name="Scbmid" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(scbmid)

	/// <Property class="CPlan_Order_Tel_Data" name="Scbmbm" type="L3STRING">
	/// �������ű���
	/// </Property>
	DECLARE_L3PROP_STRING(scbmbm)

	/// <Property class="CPlan_Order_Tel_Data" name="Gzzxid" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(gzzxid)

	/// <Property class="CPlan_Order_Tel_Data" name="Gzzxbm" type="L3STRING">
	/// �������ı���
	/// </Property>
	DECLARE_L3PROP_STRING(gzzxbm)

	/// <Property class="CPlan_Order_Tel_Data" name="Ztshow" type="L3STRING">
	/// ����״̬
	/// </Property>
	DECLARE_L3PROP_STRING(ztshow)

	/// <Property class="CPlan_Order_Tel_Data" name="Ddlx" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(ddlx)

	/// <Property class="CPlan_Order_Tel_Data" name="Ksid" type="L3STRING">
	/// �ͻ�
	/// </Property>
	DECLARE_L3PROP_STRING(ksid)

	/// <Property class="CPlan_Order_Tel_Data" name="Sfjj" type="L3STRING">
	/// �Ƿ�Ӽ�
	/// </Property>
	DECLARE_L3PROP_STRING(Sfjj)

	/// <Property class="CPlan_Order_Tel_Data" name="Jldwid" type="L3STRING">
	/// ������λ
	/// </Property>
	DECLARE_L3PROP_STRING(jldwid)

	/// <Property class="CPlan_Order_Tel_Data" name="Jldwmc" type="L3STRING">
	/// ������λ����
	/// </Property>
	DECLARE_L3PROP_STRING(jldwmc)

	/// <Property class="CPlan_Order_Tel_Data" name="Fjlid" type="L3STRING">
	/// ��������λ
	/// </Property>
	DECLARE_L3PROP_STRING(fjldwid)

	/// <Property class="CPlan_Order_Tel_Data" name="Jhwgsl" type="L3DOUBLE">
	/// �ƻ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(xqsl)

	/// <Property class="CPlan_Order_Tel_Data" name="Jhxxsl" type="L3DOUBLE">
	/// �ƻ���������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(jhxxsl)

	/// <Property class="CPlan_Order_Tel_Data" name="Fjhsl" type="L3LONG">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_LONG(xqfsl)

	/// <Property class="CPlan_Order_Tel_Data" name="Jhksrq" type="L3DATETIME">
	/// �ƻ���ʼ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(jhrq)

	/// <Property class="CPlan_Order_Tel_Data" name="Xdrq" type="L3DATETIME">
	/// �µ�����
	/// </Property>
	DECLARE_L3PROP_DATETIME(xdrq)

	/// <Property class="CPlan_Order_Tel_Data" name="Xqrq" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(xqrq)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy1" type="L3STRING">
	/// �Զ���1
	/// </Property>
	DECLARE_L3PROP_STRING(zdy1)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy2" type="L3STRING">
	/// �Զ���2
	/// </Property>
	DECLARE_L3PROP_STRING(zdy2)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy3" type="L3STRING">
	/// �Զ���3
	/// </Property>
	DECLARE_L3PROP_STRING(zdy3)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy4" type="L3STRING">
	/// �Զ���4
	/// </Property>
	DECLARE_L3PROP_STRING(zdy4)

	/// <Property class="CPlan_Order_Tel_Data" name="zdy5" type="L3STRING">
	/// �Զ���5
	/// </Property>
	DECLARE_L3PROP_STRING(zdy5)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx1" type="L3STRING">
	/// ������1
	/// </Property>
	DECLARE_L3PROP_STRING(zyx1)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx2" type="L3STRING">
	/// ������2
	/// </Property>
	DECLARE_L3PROP_STRING(zyx2)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx3" type="L3STRING">
	/// ������3
	/// </Property>
	DECLARE_L3PROP_STRING(zyx3)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx4" type="L3STRING">
	/// ������4
	/// </Property>
	DECLARE_L3PROP_STRING(zyx4)

	/// <Property class="CPlan_Order_Tel_Data" name="zyx5" type="L3STRING">
	/// ������5
	/// </Property>
	DECLARE_L3PROP_STRING(zyx5)

	/// <Property class="CPlan_Order_Tel_Data" name="pk_corp" type="L3STRING">
	/// ��˾
	/// </Property>
	DECLARE_L3PROP_STRING(pk_corp)

	/// <Property class="CPlan_Order_Tel_Data" name="Gcbm" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(gcbm)

	/// <Property class="CPlan_Order_Tel_Data" name="pk_poid" type="L3STRING">
	/// �ƻ���������
	/// </Property>
	DECLARE_L3PROP_STRING(pk_poid)

	/// <Property class="CPlan_Order_Tel_Data" name="PlanRec_Date" type="L3DATETIME">
	/// �ƻ�������������
	/// </Property>
	DECLARE_L3PROP_DATETIME(PlanRec_Date)

};

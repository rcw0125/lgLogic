// �߼���CPlan_Orderͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProducePlan.h"

class CPlan_Order :
	public ProducePlan
{
public:
	CPlan_Order(void);
	virtual ~CPlan_Order(void);

	DECLARE_L3CLASS(CPlan_Order,XGMESLogic\\PlanMag, PlanID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Order)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_Order" name="Length" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CPlan_Order" name="Width" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CPlan_Order" name="Thickness" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CPlan_Order" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CPlan_Order" name="MaterialCode" type="L3STRING">
	/// ���ϱ���
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialCode)

	/// <Property class="CPlan_Order" name="Unit" type="L3STRING">
	/// ������λ
	/// </Property>
	DECLARE_L3PROP_STRING(Unit)

	/// <Property class="CPlan_Order" name="Assist_Unit" type="L3STRING">
	/// ��������λ
	/// </Property>
	DECLARE_L3PROP_STRING(Assist_Unit)

	/// <Property class="CPlan_Order" name="Weight" type="L3DOUBLE">
	/// �ƻ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CPlan_Order" name="ActWeight" type="L3DOUBLE">
	/// ʵ��Ͷ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ActWeight)

	/// <Property class="CPlan_Order" name="SpareWeight" type="L3DOUBLE">
	/// ʣ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SpareWeight)

	/// <Property class="CPlan_Order" name="Assisi_Weight" type="L3DOUBLE">
	/// �ƻ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Assisi_Weight)

	/// <Property class="CPlan_Order" name="PlanRec_Date" type="L3DATETIME">
	/// �ƻ��µ�����
	/// </Property>
	DECLARE_L3PROP_DATETIME(PlanRec_Date)

	/// <Property class="CPlan_Order" name="Request_Date" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Request_Date)

	/// <Property class="CPlan_Order" name="Corp" type="L3STRING">
	/// ��˾
	/// </Property>
	DECLARE_L3PROP_STRING(Corp)

	/// <Property class="CPlan_Order" name="Factory" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CPlan_Order" name="Work_Center" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Work_Center)

	/// <Property class="CPlan_Order" name="Client" type="L3STRING">
	/// �ͻ�
	/// </Property>
	DECLARE_L3PROP_STRING(Client)

	/// <Property class="CPlan_Order" name="Tech_Request" type="L3STRING">
	/// ����Ҫ��zyx2
	/// </Property>
	DECLARE_L3PROP_STRING(Tech_Request)

	/// <Property class="CPlan_Order" name="Inside_Note" type="L3STRING">
	/// ������˵��zdy4
	/// </Property>
	DECLARE_L3PROP_STRING(Inside_Note)

	/// <Property class="CPlan_Order" name="Imm_Flag" type="L3STRING">
	/// �Ƿ�Ӽ�
	/// </Property>
	DECLARE_L3PROP_STRING(Imm_Flag)

	/// <Property class="CPlan_Order" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CPlan_Order" name="New_BOF_Flag" type="L3SHORT">
	/// 80tת¯��־
	/// </Property>
	DECLARE_L3PROP_SHORT(New_BOF_Flag)

	/// <Property class="CPlan_Order" name="Protocol" type="L3STRING">
	/// Э��
	/// </Property>
	DECLARE_L3PROP_STRING(Protocol)

	/// <Property class="CPlan_Order" name="ProduceStd" type="L3STRING">
	/// ��Ʒ��׼zyx1
	/// </Property>
	DECLARE_L3PROP_STRING(ProduceStd)


	/// <Property class="CPlan_Order" name="pk_poid" type="L3STRING">
	/// �ƻ���������
	/// </Property>
	DECLARE_L3PROP_STRING(pk_poid)


	/// <Property class="CPlan_Order" name="MaterialCode_ID" type="L3STRING">
	/// ���ϱ���ID
	/// </Property>2009-03-11
	DECLARE_L3PROP_STRING(MaterialCode_ID)

	/// <Property class="CPlan_Order" name="MaterialCode_ID" type="L3STRING">
	/// ����·��zdy3
	/// </Property>2009-03-11
	DECLARE_L3PROP_STRING(Product_Route)

	/// <Property class="CPlan_Order" name="Other_Tech_Request" type="L3STRING">
	/// ��������Ҫ��zdy2
	/// </Property>
	DECLARE_L3PROP_STRING(Other_Tech_Request)

};

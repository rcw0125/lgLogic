// �߼���CDeS_Prod_Areaͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProduceArea.h"

class CDeS_Prod_Area :
	public ProduceArea
{
public:
	CDeS_Prod_Area(void);
	virtual ~CDeS_Prod_Area(void);

	DECLARE_L3CLASS(CDeS_Prod_Area,XGMESLogic\\DeSMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Prod_Area)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:

	UINT m_iTimer;

	/// <summary>
	/// �ӹ�ǰԤ�����ڽ��мӹ��߼�����ǰ���ã��̳�������ش˺�����������Ԥ����
	/// ARG >> rsParameter : �ӹ�������¼����
	/// RET << ����TRUE�����ӹ�������FALSE�жϼӹ���
	/// </summary>
	virtual BOOL OnBeforeProcess(L3RECORDSET rsParameter);

	/// <summary>
	/// ���ϼӹ��߼������̳�����Ҫ���ش˺����������ض��Ĳ��ϼӹ�����
	/// ע�⣺�ڴ˷����в�Ҫ�Լӹ���ص����ݽ���ֱ���޸ģ�����������������������
	/// ARG >> rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
	///		>> rsParameter : �ӹ�ʹ�õĲ�����¼����
	///		<< pnProcessType : �ɹ��󷵻ؼӹ����͡�
	///		<< prsProducts : �ɹ��󷵻ز�Ʒ���ݼ�¼��
	///		<< prsMaterialMap : ����ӹ�������CreateNew���ɹ��󷵻�ԭ�ϳ�Ʒ���ձ��������á�
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap);

	/// <summary>
	/// �ӹ����������ڼӹ��߼�������ɺ���ã��̳�������ش˺������ж��⴦��
	/// ARG >> rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
	///		>> rsParameter : �ӹ�ʹ�õĲ�����¼����
	///		>> pnProcessType : �ӹ����͡�
	///		>> rsProducts : ��Ʒ���ݼ�¼��
	///		>> rsMaterialMap : ����ӹ�������CreateNew��Ϊԭ�ϳ�Ʒ���ձ��������á�
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap);

	/// <Property class="CDeS_Prod_Area" name="TAP_No" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TAP_No)

	/// <Property class="CDeS_Prod_Area" name="TPC_No" type="L3STRING">
	/// �޺�
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

	/// <Property class="CDeS_Prod_Area" name="BlowTime" type="L3LONG">
	/// �紵ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(BlowTime)

	/// <Property class="CDeS_Prod_Area" name="S" type="L3DOUBLE">
	/// ǰ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CDeS_Prod_Area" name="Weight" type="L3DOUBLE">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CDeS_Prod_Area" name="LanceNo" type="L3STRING">
	/// ��ǹ��
	/// </Property>
	DECLARE_L3PROP_STRING(LanceNo)

	/// <Property class="CDeS_Prod_Area" name="LanceAge" type="L3LONG">
	/// ǹ��
	/// </Property>
	DECLARE_L3PROP_LONG(LanceAge)

	/// <Property class="CDeS_Prod_Area" name="P" type="L3DOUBLE">
	/// ǰ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P)

	/// <Property class="CDeS_Prod_Area+" name="Status" type="L3SHORT">
	/// ��ҵ״̬
	/// (1:׼������;
	///  2:���޽�վ;
	///  3:Ԥ������ʼ;
	///  4:Ԥ��������;
	///  5:�紵��ʼ;
	///  6:�紵����;
	///  7:������ʼ;
	///  8:��������;
	///  9:���޳�վ)
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Method class="CDeS_Prod_Area" name="OnTimer" type="L3BOOL">
	/// ����ʱ���¼�
	/// <Param name="nEventID" type="L3ULONG">��ʱ���¼�ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG nEventID);

	/// <Method class="CDeS_Prod_Area" name="SetDeSAreaTimer" type="L3BOOL">
	/// ������ʱ���¼�
	/// </Method>
	L3BOOL SetDeSAreaTimer();

	/// <Method class="CDeS_Prod_Area" name="KillDeSAreaTimer" type="L3BOOL">
	/// ֹͣ��ʱ���¼�
	/// </Method>
	L3BOOL KillDeSAreaTimer();

};

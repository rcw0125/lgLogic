// �߼���CAOD_Prod_Areaͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProduceArea.h"

class CAOD_Prod_Area :
	public ProduceArea
{
public:
	CAOD_Prod_Area(void);
	virtual ~CAOD_Prod_Area(void);

	DECLARE_L3CLASS(CAOD_Prod_Area,XGMESLogic\\AODMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Prod_Area)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:
	UINT m_iTimer;

	/// <summary>
	/// ����λ�ñ�����麯�����̳���������ش˺��������Լ���λ�ñ��붨�塣
	/// ARG >> void
	/// RET << λ�ñ���
	/// </summary>
	virtual CString GetPositionCode();

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

	/// <summary>
	/// �������ǰ������
	/// </summary>
	virtual BOOL OnBeforeAddMaterials(L3RECORDSET rsMaterials);
	/// <summary>
	/// ������Ӻ�������
	/// </summary>
	virtual BOOL OnAfterMaterialsAdded(L3RECORDSET rsMaterials);
	/// <summary>
	/// �����Ƴ���������
	/// </summary>
	virtual BOOL OnAfterMaterialsRemoved(L3RECORDSET rsMaterials);

	/// <Property class="CAOD_Unit_Mag" name="Status" type="L3LONG">
	/// ��λ״̬
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CAOD_Prod_Area" name="NextSteel" type="L3STRING">
	/// ��һ��Ҫ����ĸ�ˮ��
	/// </Property>
	DECLARE_L3PROP_STRING(NextSteel)

	/// <Property class="CAOD_Prod_Area" name="TreatNo" type="L3STRING">
	/// ��ǰ�����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CAOD_Prod_Area" name="HeatID" type="L3STRING">
	/// ��ǰ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Prod_Area" name="LadleID" type="L3STRING">
	/// ��ǰ�ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CAOD_Prod_Area" name="SteelGradeIndex" type="L3STRING">
	/// ��ǰ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CAOD_Prod_Area" name="Weight" type="L3DOUBLE">
	/// ��ǰ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CAOD_Prod_Area" name="Arrive_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Time)

	/// <Property class="CAOD_Prod_Area" name="SoftBlowTime" type="L3LONG">
	///// ����ʱ
	///// </Property>
	//DECLARE_L3PROP_LONG(SoftBlowTime)

	///// <Property class="CAOD_Prod_Area" name="WiredFlag" type="L3LONG">
	///// �ƴ����־
	///// </Property>
	//DECLARE_L3PROP_LONG(WiredFlag)

	/// <Method class="CAOD_Prod_Area" name="OnTimer" type="L3BOOL">
	/// ����ʱ���¼�
	/// <Param name="nEventID" type="L3ULONG">��ʱ���¼�ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG nEventID);

	/// <Method class="CAOD_Prod_Area" name="SetLFAreaTimer" type="L3BOOL">
	/// ������ʱ���¼�
	/// </Method>
	L3BOOL SetLFAreaTimer();

	/// <Method class="CAOD_Prod_Area" name="KillLFAreaTimer" type="L3BOOL">
	/// ֹͣ��ʱ���¼�
	/// </Method>
	L3BOOL KillLFAreaTimer();
};

// �߼���CMIF_Unit_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProduceUnit.h"

class CMIF_Unit_Mag :
	public ProduceUnit
{
public:
	CMIF_Unit_Mag(void);
	virtual ~CMIF_Unit_Mag(void);

	DECLARE_L3CLASS(CMIF_Unit_Mag,XGMESLogic\\MIXFMag, MIFID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:
	/// <summary>
	/// ���ػ���ļӹ�����
	/// ARG << lstURIs : �������мӹ��������URI
	/// </summary>
	virtual BOOL GetProduceAreas(CStringList& lstURIs);

	/// <summary>
	/// �õ�����ǰ����ϻ�������URI
	/// </summary>
	virtual CString GetInputCache();

	/// <summary>
	/// �õ������̲��ϻ�������URI
	/// </summary>
	virtual CString GetOutputCache();

	/// <summary>
	/// ��������ǰԤ�����ڻ�������ǰ���ã��̳�������ش˷�������Ԥ������׼���ʹ���
	/// ARG >> rsMaterialInfo : ������Ϣ��¼����
	/// RET << ����TRUE�������ϣ�����FALSE�ж����ϡ�
	/// </summary>
	virtual BOOL OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// �������Ϻ��������ڻ������Ϻ���ã��̳�������ش˷������ж��⴦��
	/// ARG >> rsMaterialInfo : ������Ϣ��¼����
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// ���ػ������ϼ�¼������URI
	/// </summary>
	virtual CString GetFeedingLogType();

	/// <summary>
	/// ׼�����ϼ�¼���ݡ��̳�������ش˺������ж�������ݴ���
	/// ARG >> rsFeedingLogs : ���ϼ�¼��Ϣ��
	/// RET << void
	/// </summary>
	virtual void PrepareFeedingLogs(L3RECORDSET rsFeedingLogs);

	/// <summary>
	/// �ӹ�����Ԥ�����ڵ��üӹ�����ļӹ�����ǰ���ã��̳�������ش˺����Լӹ����������޸ĺ����á�
	/// ARG >> lpcszArea : �ӹ������URI
	///		>> rsParameters : �ӹ�������¼����
	/// RET << ����TRUE�����ӹ�������FALSE�жϼӹ���
	/// </summary>
	virtual BOOL PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters);

	/// <summary>
	/// �ӹ���ɺ��������ڼӹ���ɺ���ã��̳�������ش˺������ж����߼�����
	/// ARG >> lpcszArea : �ӹ������URI
	///		>> nProcessType : �ӹ������͡�
	///		>> rsProducts : �ӹ������Ĳ�Ʒ����Ϣ��¼��
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts);

	/// <summary>
	/// ����ǰԤ������ִ�����߲���ǰ���ã��̳�������ش˺�������Ԥ�ȵ�����׼���ʹ���
	/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
	/// RET << ����TRUE�������ߣ�����FALSE�ж����ߡ�
	/// </summary>
	virtual BOOL OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// ���ߺ���������ִ�����߲�������ã��̳�������ش˺������ж��⴦��
	/// ARG >> rsMaterialInfo : ���߲�����Ϣ������MaterialType,MaterialID,Amount,Area�ֶΡ�
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// ���ػ��������¼������URI
	/// </summary>
	virtual CString GetDeliveryLogType();

	/// <summary>
	/// ׼�����ϼ�¼���ݡ�
	/// ARG >> rsDeliveryLog : ���ϼ�¼���ݡ�
	/// RET <<void
	/// </summary>
	virtual void PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog);

	/// <summary>
	/// ���ر������ͨѶ�������URI
	/// </summary>
	virtual CString GetCommunicator();

	/// <summary>
	/// ׼���ƻ����ݣ��Ա��������λϵͳ���͡�
	/// ARG >> lpcszPlanType : �ƻ����͡�
	///		>> rsPlan : �ƻ����ݡ�����PlanID�ֶΡ�
	///		<< rsSend : ����׼���õļƻ��������ݡ�
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend);

	/// <summary>
	/// �ƻ��´��������������λϵͳ���ͼƻ�����ã��̳�������ش˺������к�������
	/// ARG >> rsSend : �·���λϵͳ�ļƻ����ݡ�
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterPlansSent(L3RECORDSET rsSend);

	/// <summary>
	/// ׼���ƻ����ݣ��Ա�֪ͨ������λϵͳȡ���ƻ���
	/// ARG >> lpcszPlanType : �ƻ����͡�
	///		>> rsPlan : �ƻ����ݡ�����PlanID�ֶΡ�
	///		<< rsSend : ����׼���õļƻ�ȡ�����ݡ�
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel);

	/// <summary>
	/// �ƻ�ȡ����������������λϵͳ����ȡ���ƻ�����ã��̳�������ش˺������к�������
	/// ARG >> rsCancel : �·���λϵͳ�ļƻ�ȡ�����ݡ�
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterPlansCanceled(L3RECORDSET rsCancel);

	/// <summary>
	/// ����������ߵ��¼�
	/// ARG >> pEvt : �¼�����
	/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
	/// </summary>
	virtual BOOL HandleMaterialFeedingEvent(MatEnterArea *pEvt);
	/// <summary>
	/// ������Ͻ���ӹ�������¼�
	/// ARG >> pEvt : �¼�����
	/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
	/// </summary>
	virtual BOOL HandleMaterialEnterAreaEvent(MatEnterArea *pEvt);
	/// <summary>
	/// ��������뿪�ӹ������¼�
	/// ARG >> pEvt : �¼�����
	/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
	/// </summary>
	virtual BOOL HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt);
	/// <summary>
	/// ���������������¼�
	/// ARG >> pEvt : �¼�����
	/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
	/// </summary>
	virtual BOOL HandleMaterialProducedEvent(MatProduced *pEvt);
	/// <summary>
	/// �������������ݱ���¼�
	/// ARG >> pEvt : �¼�����
	/// RET << ����TRUE��ʾ�Ѿ��ɹ���������FALSE��ʾʹ��ϵͳȱʡ����ʽ��
	/// </summary>
	virtual BOOL HandleUnitMeasureChangedEvent(UnitMeasure *pEvt);

	/// <Property class="CMIF_Unit_Mag" name="MIFID" type="L3STRING">
	/// ����¯¯����
	/// </Property>
	DECLARE_L3PROP_STRING(MIFID)

	/// <Property class="CMIF_Unit_Mag" name="Temp" type="L3LONG">
	/// ��ǰ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)

	/// <Property class="CMIF_Unit_Mag" name="C" type="L3DOUBLE">
	/// C�ɷݻ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(C)

	/// <Property class="CMIF_Unit_Mag" name="Si" type="L3DOUBLE">
	/// Si�ɷݻ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si)

	/// <Property class="CMIF_Unit_Mag" name="Mn" type="L3DOUBLE">
	/// Mn�ɷݻ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mn)

	/// <Property class="CMIF_Unit_Mag" name="P" type="L3DOUBLE">
	/// P�ɷݻ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P)

	/// <Property class="CMIF_Unit_Mag" name="S" type="L3DOUBLE">
	/// S�ɷݻ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CMIF_Unit_Mag" name="Ti" type="L3DOUBLE">
	/// Ti�ɷݻ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ti)

	//add by hyh 2012-04-10
	/// <Property class="CMIF_Unit_Mag" name="Sn" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sn)

	/// <Property class="CMIF_Unit_Mag" name="Sb" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sb)

	/// <Property class="CMIF_Unit_Mag" name="As" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(As)

	/// <Property class="CMIF_Unit_Mag" name="Pb" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pb)
	//end

	//////add by hyh 2012-08-09 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	/// <Property class="CMIF_Unit_Mag" name="Ni" type="L3DOUBLE">
	/// Ni
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ni)

	/// <Property class="CMIF_Unit_Mag" name="Mo" type="L3DOUBLE">
	/// Mo
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mo)

	/// <Property class="CMIF_Unit_Mag" name="Cu" type="L3DOUBLE">
	/// Cu
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cu)

	/// <Property class="CMIF_Unit_Mag" name="Cr" type="L3DOUBLE">
	/// Cr
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cr)

	/// <Property class="CMIF_Unit_Mag" name="B" type="L3DOUBLE">
	/// B
	/// </Property>
	DECLARE_L3PROP_DOUBLE(B)

	/// <Property class="CMIF_Unit_Mag" name="V" type="L3DOUBLE">
	/// V
	/// </Property>
	DECLARE_L3PROP_DOUBLE(V)

	/// <Property class="CMIF_Unit_Mag" name="Al" type="L3DOUBLE">
	/// Al
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al)

	/// <Property class="CMIF_Unit_Mag" name="Nb" type="L3DOUBLE">
	///Nb
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nb)

	/// <Property class="CMIF_Unit_Mag" name="Zn" type="L3DOUBLE">
	/// Zn
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Zn)

	/// <Property class="CMIF_Unit_Mag" name="W" type="L3DOUBLE">
	/// W
	/// </Property>
	DECLARE_L3PROP_DOUBLE(W)
	//////////////////end///////////////////

	
	/// <Property class="CMIF_Unit_Mag" name="C_Cal" type="L3DOUBLE">
	/// C�ɷݼ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(C_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Si_Cal" type="L3DOUBLE">
	/// Si�ɷݼ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Mn_Cal" type="L3DOUBLE">
	/// Mn�ɷݼ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mn_Cal)

	/// <Property class="CMIF_Unit_Mag" name="P_Cal" type="L3DOUBLE">
	/// P�ɷݼ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Cal)

	/// <Property class="CMIF_Unit_Mag" name="S_Cal" type="L3DOUBLE">
	/// S�ɷݼ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Ti_Cal" type="L3DOUBLE">
	/// Ti�ɷݼ���ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ti_Cal)

	//add by hyh 2012-04-10
	/// <Property class="CMIF_Unit_Mag" name="Sn_Cal" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sn_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Sb_Cal" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sb_Cal)

	/// <Property class="CMIF_Unit_Mag" name="As_Cal" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(As_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Pb_Cal" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pb_Cal)

	//end


	//////add by hyh 2012-08-09 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	/// <Property class="CMIF_Unit_Mag" name="Ni_Cal" type="L3DOUBLE">
	/// Ni_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ni_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Mo_Cal" type="L3DOUBLE">
	/// Mo_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mo_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Cu_Cal" type="L3DOUBLE">
	/// Cu_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cu_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Cr_Cal" type="L3DOUBLE">
	/// Cr_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cr_Cal)

	/// <Property class="CMIF_Unit_Mag" name="B_Cal" type="L3DOUBLE">
	/// B_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(B_Cal)

	/// <Property class="CMIF_Unit_Mag" name="V_Cal" type="L3DOUBLE">
	/// V_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(V_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Al_Cal" type="L3DOUBLE">
	/// Al_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Nb_Cal" type="L3DOUBLE">
	///Nb_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nb_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Zn_Cal" type="L3DOUBLE">
	/// Zn_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Zn_Cal)

	/// <Property class="CMIF_Unit_Mag" name="W_Cal" type="L3DOUBLE">
	/// W_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(W_Cal)
	//////////////////end///////////////////

	/// <Property class="CMIF_Unit_Mag" name="Weight" type="L3DOUBLE">
	/// ����¯������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CMIF_Unit_Mag" name="subCount" type="L3LONG">
	/// ԤԼ����
	/// </Property>
	DECLARE_L3PROP_LONG(subCount)

	/// <Property class="CMIF_Unit_Mag" name="Temp_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Temp_Time)

	/// <Property class="CMIF_Unit_Mag" name="Tare_Weight" type="L3DOUBLE">
	/// �ذ������߳�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tare_Weight)

	/// <Property class="CMIF_Unit_Mag" name="Tare_Weight_Time" type="L3DATETIME">
	///�ذ������߳���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tare_Weight_Time)

	/// <Property class="CMIF_Unit_Mag" name="Gross_Weight" type="L3DOUBLE">
	/// �ذ���ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gross_Weight)

	/// <Property class="CMIF_Unit_Mag" name="Gross_Weight_Time" type="L3DATETIME">
	/// �ذ���ˮ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Gross_Weight_Time)

	/// <Method class="CMIF_Unit_Mag" name="CalculateChemicalData" type="L3VOID">
	/// <Param name="rsIron" type="L3RECORDSET">��ˮ������</Param>
	/// </Method>
	L3VOID CalculateChemicalData(L3RECORDSET rsIron);
	/// <Method class="CMIF_Unit_Mag" name="SampleChemcialData" type="L3LONG">
	/// ����¯����������
	/// <Param name="rsChemical" type="L3RECORDSET">�ɷ�����</Param>
	/// </Method>
	L3LONG SampleChemcialData(L3RECORDSET rsChemical);
	/// <Method class="CMIF_Unit_Mag" name="MixIrons" type="L3LONG">
	/// ��ĳЩ��ˮ�������¯
	/// <Param name="rsIrons" type="L3RECORDSET">�������¯����ˮ��¼</Param>
	/// </Method>
	L3LONG MixIrons(L3RECORDSET rsIrons);
	/// <Method class="CMIF_Unit_Mag" name="OutputIron" type="L3BOOL">
	/// ��Ŀ����������
	/// <Param name="LadleID" type="L3STRING">Ŀ��������</Param>
	/// <Param name="fWeight" type="L3DOUBLE">��������</Param>
	/// <Param name="fReHeatWeight" type="L3DOUBLE">��¯������</Param>
	/// </Method>
	L3BOOL OutputIron(L3STRING LadleID, L3DOUBLE fWeight,L3DOUBLE fReHeatWeight,L3STRING Destination);

	/// <Method class="CMIF_Unit_Mag" name="AcceptIronLadleWeightData" type="L3BOOL">
	/// ���ջ���¯�������� 2009-01-04
	/// <Param name="rsData" type="L3RECORDSET">����¯��������</Param>
	/// </Method>
	L3BOOL AcceptIronLadleWeightData(L3RECORDSET rsData);

	/// <Method class="CMIF_Unit_Mag" name="AcceptTemperatureData" type="L3BOOL">
	/// ���ջ���¯�������� 2009-01-04
	/// <Param name="rsData" type="L3RECORDSET">����¯��������</Param>
	/// </Method>
	L3BOOL AcceptTemperatureData(L3RECORDSET rsData);

	/// <Method class="CMIF_Unit_Mag" name="AcceptDirectIronWeightData" type="L3BOOL">
	/// ���ջ���¯������������������ 2009-01-04
	/// <Param name="rsData" type="L3RECORDSET">������������������</Param>
	/// </Method>
	L3BOOL AcceptDirectIronWeightData(L3RECORDSET rsData);



	/// <Method class="CMIF_Unit_Mag" name="OutputIronCancel" type="L3BOOL">
	/// ȡ������¯����2009-03-11
	/// </Method>
	L3LONG OutputIronCancel(L3RECORDSET rsLadleID);

	L3LONG OutputIronCancelToDEP(L3RECORDSET rsLadleID);



};

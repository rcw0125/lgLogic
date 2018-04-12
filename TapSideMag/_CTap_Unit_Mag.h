// �߼���CTap_Unit_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProduceUnit.h"

class CTap_Unit_Mag :
	public ProduceUnit
{
public:
	CTap_Unit_Mag(void);
	virtual ~CTap_Unit_Mag(void);

	DECLARE_L3CLASS(CTap_Unit_Mag,XGMESLogic\\TapSideMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

public:
	enum _TapStatus
	{
		TAPWaiting = 0,			// �ȴ�
		TAPProcessing = 1,		// ���ڴ���
		TAPProcessed = 2,		// �������
	};

protected:
	UINT m_iTimer;

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

	/// <Property class="CTap_Unit_Mag" name="Status" type="L3LONG">
	/// ��ǰ״̬
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CTap_Unit_Mag" name="HeatID" type="L3STRING">
	/// ��ǰ�����¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Unit_Mag" name="LadleID" type="L3STRING">
	/// ��ǰ�ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CTap_Unit_Mag" name="SteelGradeIndex" type="L3STRING">
	/// ��ǰ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CTap_Unit_Mag" name="StartTime" type="L3DATETIME">
	/// ����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(StartTime)

	/// <Property class="CTap_Unit_Mag" name="StopTime" type="L3DATETIME">
	/// �������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(StopTime)

	/// <Property class="CTap_Unit_Mag" name="ProcTime" type="L3LONG">
	/// ��ǰ����ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(ProcTime)

	/// <Property class="CTap_Unit_Mag" name="ReSampleHeatID" type="L3STRING">
	/// ��ȡ��֪ͨ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(ReSampleHeatID)

	
	/// <Property class="CTap_Unit_Mag" name="StartProcessTime" type="L3STRING">
	/// ����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(StartProcessTime)


	/// ͨ�üƻ�״̬�޸ĺ���
	BOOL ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status);

	/// <Method class="CTap_Unit_Mag" name="StartProcess" type="L3BOOL">
	/// ��ʼ���и�ˮ¯����
	/// <Param name="rsSteel" type="L3RECORDSET">Ҫ����ĸ�ˮ��¼</Param>
	/// </Method>
	L3BOOL StartProcess(L3RECORDSET rsSteel);
	/// <Method class="CTap_Unit_Mag" name="StopProcess" type="L3BOOL">
	/// ������ˮ¯����
	/// </Method>
	//L3BOOL StopProcess(L3RECORDSET rsProcData);
	L3BOOL StopProcess();
	/// <Method class="CTap_Unit_Mag" name="FeedElements" type="L3BOOL">
	/// ���м���ι˿
	/// <Param name="rsElem" type="L3RECORDSET">����ι˿����</Param>
	/// </Method>
	L3BOOL FeedElements(L3RECORDSET rsElem);
	/// <Method class="CTap_Unit_Mag" name="SetTemperature" type="L3BOOL">
	/// ��������¼�
	/// <Param name="rsTemp" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL SetTemperature(L3RECORDSET rsTemp);
	/// <Method class="CTap_Unit_Mag" name="SetOxygen" type="BOOL">
	/// �������¼�
	/// <Param name="rsOxygen" type="L3RECORDSET">��������</Param>
	/// </Method>
	BOOL SetOxygen(L3RECORDSET rsOxygen);
	/// <Method class="CTap_Unit_Mag" name="OnTimer" type="L3BOOL">
	/// ����ʱ���¼�
	/// <Param name="nEventID" type="L3ULONG">��ʱ���¼�ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG nEventID);
	/// <Method class="CTap_Unit_Mag" name="SetWeight" type="L3BOOL">
	/// �����ˮ�������ݡ�
	/// <Param name="fWeight" type="L3DOUBLE">��ˮ����</Param>
	/// </Method>
	L3BOOL SetWeight(L3DOUBLE fWeight);
	/// <Method class="CTap_Unit_Mag" name="Complete" type="L3BOOL">
	/// ���¯��������ˮת�����¹���
	/// </Method>
	L3BOOL Complete();
	/// <Method class="CTap_Unit_Mag" name="GetInputSteels" type="L3RECORDSET">
	/// ����¯��������ˮ��Ϣ
	/// </Method>
	L3RECORDSET GetInputSteels();


	/// <Method class="CTap_Unit_Mag" name="ChangeSteelGrade" type="L3BOOL">
	/// ����ĸ�
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight);

	/// <Method class="CTap_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  ��ˮ��¯����
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID);

	/// <Method class="CBOF_Unit_Mag" name="AcceptTapSideWeightData" type="L3BOOL">
	/// ����¯��������� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">¯����������</Param>
	/// </Method>
	L3BOOL AcceptTapSideWeightData(L3RECORDSET rsData);

	/// <Method class="CTap_Unit_Mag" name="AutoStartProcess" type="L3BOOL">
	/// ת¯���ֽ������Զ�¯��ʼ���� 2009-01-14
	/// </Method>
	L3BOOL AutoStartProcess();


	/// <Method class="CTap_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  ��ȡ���¯�� 2009-02-28 ����¯��
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3RECORDSET GetPreThreeHeatID();

	/// <Method class="CTap_Unit_Mag" name="AcceptOxygenData" type="L3BOOL">
	/// ����¯�������� 2009-03-16
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptOxygenData(L3RECORDSET rsData);

	/// <Method class="CTap_Unit_Mag" name="AcceptTempData" type="L3BOOL">
	/// ����¯��������� 2009-03-16
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptTempData(L3RECORDSET rsData);

	/// <Method class="CTap_Unit_Mag" name="CalculateOxygenContent" type="L3BOOL">
	/// �����ǰ�������� 2009-03-17
	/// </Method>
	L3BOOL CalculateOxygenContent();

	/// <Method class="CTap_Unit_Mag" name="CalculateTemperature" type="L3BOOL">
	/// �����ǰ���¶� 2009-03-17
	/// </Method>
	L3BOOL CalculateTemperature();
};

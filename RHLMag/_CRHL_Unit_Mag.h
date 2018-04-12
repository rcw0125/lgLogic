// �߼���CLF_Unit_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProduceUnit.h"

class CRHL_Unit_Mag :
	public ProduceUnit
{
public:
	CRHL_Unit_Mag(void);
	virtual ~CRHL_Unit_Mag(void);

	DECLARE_L3CLASS(CRHL_Unit_Mag,XGMESLogic\\RHLMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRHL_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

public:
	enum _LFStatus
	{
		// ����״̬
		LFWaiting = 0,		// �ȴ�
		LFProcBegin = 1,	// ����ʼ
		LFHeatBegin = 2,	// ��ʼ����
		LFHeatEnd = 3,		// ���Ƚ���
		LFProcEnd = 4,		// �������
		LFBlowBegin = 5,	// ����ʼ
		LFBlowEnd = 6,		// ������
	};

	//2009-03-02 tangyi
	enum _LFEquipStatus
	{
		// �쳣״̬
		LFNormal = 0,       //����
		LFRepair = -1,		// ����
		LFBushing = -2,		// �׹�
		LFMaintain = -3,	// ��¯
		LFFailure = -4,		// ����
	};



protected:

	CString csDischargeUnit;

	/// <summary>
	/// ���ػ���ļӹ�����
	/// ARG << lstURIs : �������мӹ��������URI
	/// </summary>
	virtual BOOL GetProduceAreas(CStringList& lstURIs);

	/// <summary>
	/// ��ȡָ����������ĺ��������URI
	/// ARG >> lpcszCurArea : ��ǰ���������URI��
	///		>> rsMaterialInfo : ������Ϣ�����ڸ����жϡ�����MaterialType,MaterialID,Amount,�Ȳ�����Ϣ��
	///							ע�⣺Ӧ��ֻ�øü�¼���ĵ�ǰ�н����жϣ�����
	/// RET << ���غ������������URI�����ؿձ�ʾ��ǰ���������Ѿ��ǻ���ĳ����ˡ�
	/// </summary>
	virtual CString GetNextProduceArea(LPCTSTR lpcszCurArea,L3RECORDSET rsMaterialInfo) { return _T(""); };

	/// <summary>
	/// ��ȡָ�����������ǰ�������URI
	/// ARG >> lpcszCurArea : ��ǰ���������URI��
	///		>> rsMaterialInfo : ������Ϣ�����ڸ����жϡ�����MaterialType,MaterialID,Amount,�Ȳ�����Ϣ��
	///							ע�⣺Ӧ��ֻ�øü�¼���ĵ�ǰ�н����жϣ�����
	/// RET << ����ǰ�����������URI�����ؿձ�ʾ��ǰ���������Ѿ��ǻ��������ˡ�
	/// </summary>
	virtual CString GetPrevProduceArea(LPCTSTR lpcszCurArea,L3RECORDSET rsMaterialInfo) { return _T(""); };

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

	/// <Property class="CLF_Unit_Mag" name="TreatNo" type="L3STRING">
	/// ��ǰ�����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Unit_Mag" name="NextTreatNo" type="L3STRING">
	/// ��һ�����
	/// </Property>
	DECLARE_L3PROP_STRING(NextTreatNo)

	/// <Property class="CLF_Unit_Mag" name="Status" type="L3LONG">
	/// ����״̬
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CLF_Unit_Mag" name="NextSteel" type="L3STRING">
	/// ��һ�����ߵĸ�ˮ
	/// </Property>
	DECLARE_L3PROP_STRING(NextSteel)

	/// <Property class="CLF_Unit_Mag" name="CurArea" type="L3STRING">
	/// ��ǰ���ڴ���Ĺ�λ
	/// </Property>
	DECLARE_L3PROP_STRING(CurArea)

	/// <Property class="CLF_Unit_Mag" name="ProcStartTime" type="L3DATETIME">
	/// ��ʼ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProcStartTime)

	/// <Property class="CLF_Unit_Mag" name="ProcStopTime" type="L3DATETIME">
	/// ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProcStopTime)

	/// <Property class="CLF_Unit_Mag" name="HeatStartTime" type="L3DATETIME">
	/// ��ʼ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(HeatStartTime)

	/// <Property class="CLF_Unit_Mag" name="ProcTime" type="L3LONG">
	/// �Ѵ���ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(ProcTime)


	/// <Property class="CLF_Unit_Mag" name="StartProcessTime" type="L3STRING">
	/// ����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(StartProcessTime)


	/// <Property class="CLF_Unit_Mag" name="WeightingSteel" type="L3STRING">
	/// �ȴ����صĸ�ˮ��
	/// </Property>
	DECLARE_L3PROP_STRING(WeightingSteel)

	/// <Property class="CLF_Unit_Mag" name="CurTemp" type="L3DOUBLE">
	/// ��ǰ�¶�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CurTemp)

	/// <Property class="CLF_Unit_Mag" name="ReSampleHeatID" type="L3STRING">
	/// ��ȡ��֪ͨ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(ReSampleHeatID)

	/// <Property class="CLF_Unit_Mag" name="Lid_Life" type="L3LONG">
	/// ¯������
	/// </Property>
	DECLARE_L3PROP_LONG(Lid_Life)

	/// <Property class="CLF_Unit_Mag" name="PoleConsume" type="L3LONG">
	/// �缫����
	/// </Property>
	DECLARE_L3PROP_LONG(PoleConsume)

	/// <Property class="CLF_Unit_Mag" name="Equip_Status" type="L3LONG">
	/// �豸״̬
	/// </Property> 2009-03-02�豸״̬ tangyi
	DECLARE_L3PROP_LONG(Equip_Status)

	/// <Property class="CLF_Unit_Mag" name="Pole_Vendor" type="L3STRING">
	/// �缫����
	/// </Property> 2009-03-19
	DECLARE_L3PROP_STRING(Pole_Vendor)
	
	/// <Property class="CLF_Unit_Mag" name="Probe_Vendor" type="L3STRING">
	/// ̽ͷ����
	/// </Property> 2009-03-19
	DECLARE_L3PROP_STRING(Probe_Vendor)

	/// <Property class="CLF_Unit_Mag" name="PrevArea" type="L3STRING">
	/// ���������Ĺ�λ
	/// </Property>
	DECLARE_L3PROP_STRING(PrevArea)

	/// ������һ�����
	CString CalculateNextTreatNo(LPCTSTR lpcszTreatNo);
	
	/// ͨ�ù���״̬�޸ĺ���
	BOOL ChangeStatus(LONG nStatus);

	/// ͨ�üƻ�״̬�޸ĺ���
	BOOL ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status);

	/// <Method class="CLF_Unit_Mag" name="GetInputSteels" type="L3RECORDSET">
	/// �����������Ĵ������ˮ��Ϣ��
	/// </Method>
	L3RECORDSET GetInputSteels();
	/// <Method class="CLF_Unit_Mag" name="DesignateForWeighting" type="L3BOOL">
	/// ָ���������صĸ�ˮ¯�š�
	/// <Param name="MaterialID" type="L3STRING">�������صĸ�ˮ��</Param>
	/// </Method>
	L3BOOL DesignateForWeighting(L3STRING MaterialID);
	/// <Method class="CLF_Unit_Mag" name="SetWeight" type="L3BOOL">
	/// ��������źš�
	/// <Param name="fWeight" type="L3DOUBLE">����</Param>
	/// </Method>
	L3BOOL SetWeight(L3DOUBLE fWeight);
	/// <Method class="CLF_Unit_Mag" name="DesignateLadle" type="L3BOOL">
	/// ΪA��B��λָ����������ĸ�ˮ��
	/// <Param name="Area" type="L3STRING">��λ�룺A��B</Param>
	/// <Param name="MaterialID" type="L3STRING">��ˮ¯��</Param>
	/// </Method>
	L3BOOL DesignateLadle(L3STRING Area, L3STRING MaterialID);
	/// <Method class="CLF_Unit_Mag" name="SteelArrived" type="L3BOOL">
	/// ����ְ������¼���
	/// <Param name="AreaID" type="L3STRING">�ְ�����Ĺ�λ</Param>
	/// </Method>
	L3BOOL SteelArrived(L3STRING AreaID);
	/// <Method class="CLF_Unit_Mag" name="FeedElement" type="L3BOOL">
	/// ��LF¯����
	/// <Param name="rsElem" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL FeedElement(L3RECORDSET rsElem);
	/// <Method class="CLF_Unit_Mag" name="SetTemperature" type="L3BOOL">
	/// ������¼�����¼�
	/// <Param name="rsTemp" type="L3RECORDSET">�����¼�����</Param>
	/// </Method>
	L3BOOL SetTemperature(L3RECORDSET rsTemp);
	/// <Method class="CLF_Prod_Area" name="SetOxygen" type="L3BOOL">
	/// ������¼LF¯�����¼���
	/// <Param name="rsOxygen" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL SetOxygen(L3RECORDSET rsOxygen);
	/// <Method class="CLF_Unit_Mag" name="FeedWire" type="L3BOOL">
	/// ������¼ι˿�¼�
	/// <Param name="Area" type="L3STRING">����ι˿�Ĺ�λ</Param>
	/// <Param name="rsWire" type="L3RECORDSET">ι˿���ݼ�¼</Param>
	/// </Method>
	L3BOOL FeedWire(L3STRING Area,L3RECORDSET rsWire);
	/// <Method class="CLF_Unit_Mag" name="StartProcess" type="L3BOOL">
	/// ��ʼ����A��B����֮һ��λ�ϵĸ�ˮ��
	/// <Param name="Area" type="L3STRING">Ҫ��ʼ����Ĺ�λ</Param>
	/// </Method>
	L3BOOL StartProcess(L3STRING Area);
	/// <Method class="CLF_Unit_Mag" name="StopProcess" type="BOOL">
	/// ��������
	/// </Method>
	BOOL StopProcess();
	/// <Method class="CLF_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
	/// �޸��豸״̬
	/// <Param name="nStatus" type="L3LONG">���豸״̬</Param>
	/// <Param name="reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL ChangeDeviceStatus(L3LONG nStatus, L3STRING reason);
	/// <Method class="CLF_Unit_Mag" name="OnTimer" type="L3BOOL">
	/// ����ʱ���¼�
	/// <Param name="nEventID" type="L3ULONG">�¼�ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG nEventID);
	/// <Method class="CLF_Unit_Mag" name="StartHeating" type="L3BOOL">
	/// ������ȿ�ʼ�¼�
	/// </Method>
	L3BOOL StartHeating();
	/// <Method class="CLF_Unit_Mag" name="StopHeating" type="L3BOOL">
	/// ������Ƚ����¼�
	/// </Method>
	L3BOOL StopHeating();
	/// <Method class="CLF_Unit_Mag" name="StartBlowing" type="BOOL">
	/// ��������ʼ�¼�
	/// <Param name="Area" type="L3STRING">��ʼ���Ĺ�λ</Param>
	/// </Method>
	BOOL StartBlowing(L3STRING Area);
	/// <Method class="CLF_Unit_Mag" name="StopBlowing" type="L3BOOL">
	/// �����������¼�
	/// <Param name="Area" type="L3STRING">�������Ĺ�λ</Param>
	/// </Method>
	L3BOOL StopBlowing(L3STRING Area);
	/// <Method class="CLF_Unit_Mag" name="SteelLeave" type="L3BOOL">
	/// �����ˮ��վ�¼�
	/// <Param name="Area" type="L3STRING">��վ��ˮ��λ</Param>
	/// </Method>
	L3BOOL SteelLeave(L3STRING Area);


	/// <Method class="CLF_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
	/// ����ĸ�
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL ChangeSteelGradeApp(L3STRING Reason);


	/// <Method class="CLF_Unit_Mag" name="SteelReturnApp" type="L3BOOL">
	///  ��ˮ��¯����
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL SteelReturnApp(L3STRING Reason,L3STRING strHeatID);


	/// <Method class="CLF_Unit_Mag" name="SteelBackApp" type="L3BOOL">
	///  ��ˮ��������
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL SteelBackApp(L3STRING Reason,L3STRING strHeatID);


	/// <Method class="CLF_Unit_Mag" name="AcceptAlloyDischargeData" type="L3RECORDSET">
	/// �Ͻ��ϲּ������ݲɼ�
	/// <Param name="HeatID" type="L3STRING">¯��</Param>
	/// </Method>
	L3BOOL AcceptMaterialDischargeData(L3RECORDSET rsMaterialData);

	/// <Method class="CLF_Unit_Mag" name="MaterialGroundDischargeData" type="L3RECORDSET">
	/// ��װ�Ͻ�ɢ״������
	/// <Param name="HeatID" type="L3STRING">¯��</Param>
	/// </Method>
	L3BOOL MaterialGroundDischargeData(L3RECORDSET rsMaterialData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFArrivalData" type="L3BOOL">
	/// ����LF¯�ְ��������� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptLFArrivalData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFStartProcessData" type="L3BOOL">
	/// ����LF¯����ʼ���� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">����ʼ����</Param>
	/// </Method>
	L3BOOL AcceptLFStartProcessData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFHeatData" type="L3BOOL">
	/// ����LF¯�������� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">���ȿ�ʼ����</Param>
	/// </Method>
	L3BOOL AcceptLFHeatData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFEndProcessData" type="L3BOOL">
	/// ����LF¯����������� 2008-12-30
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptLFEndProcessData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFStartSoftBlowData" type="L3BOOL">
	/// ����LF¯����ʼ���� 2008-12-30
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptLFStartSoftBlowData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFStopSoftBlowData" type="L3BOOL">
	/// ����LF¯����������� 2008-12-30
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptLFStopSoftBlowData(L3RECORDSET rsData);

/// <Method class="CLF_Unit_Mag" name="AcceptLFTempData" type="L3BOOL">
	/// ����LF¯�������� 2008-12-30
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptLFTempData(L3RECORDSET rsData);

	/// ����������֮��ı乤λ״̬����;�����¶����ݲɼ�2008-12-31
	BOOL ChangeAreaStatus(LPCTSTR csAreaID,LONG nStatus);

	/// <Method class="CLF_Unit_Mag" name="SetTreatNoForTempDataBeforeProcess" type="L3BOOL">
	/// �Դ���ʼǰ�������ô���������� 2008-12-30
	/// <Param name="csHeatID" type="LPCTSTR">¯��</Param>
	/// <Param name="csTreatNo" type="LPCTSTR">�����</Param>
	/// </Method>
	L3BOOL SetTreatNoForTempDataBeforeProcess(LPCTSTR csHeatID,LPCTSTR csTreatNo);

	/// <Method class="CLF_Unit_Mag" name="SetDepartureTemp" type="L3BOOL">
	/// ������վ�¶� 2009-01-02
	/// <Param name="csTreatNo" type="LPCTSTR">�����</Param>
	/// </Method>
	L3BOOL SetDepartureTemp(LPCTSTR csTreatNo);

	/// <Method class="CLF_Unit_Mag" name="SetWireTemp" type="L3BOOL">
	/// ���øƴ�������¶� 2009-01-02
	/// <Param name="csTreatNo" type="LPCTSTR">�����</Param>
	/// </Method>
	L3BOOL SetWireTemp(LPCTSTR csTreatNo);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFWireData" type="L3BOOL">
	/// ����LF¯ι������ 2009-01-02
	/// <Param name="rsData" type="L3RECORDSET">ι������</Param>
	/// </Method>
	L3BOOL AcceptLFWireData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFOxygenData" type="L3BOOL">
	/// ����LF¯�������� 2009-01-02
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptLFOxygenData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFWeightData" type="L3BOOL">
	/// ����LF¯�������� 2009-01-08
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptLFWeightData(L3RECORDSET rsData);

	/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  ��ȡ���¯�� 2009-02-28 ����¯��
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3RECORDSET GetPreThreeHeatID();

	/// <Method class="CLF_Unit_Mag" name="DoBlowwing" type="L3BOOL">
	/// �ж��Ƿ�����ʼ 2009-03-09
	/// <Param name="strAreaUri" type="LPCTSTR">�������Uri</Param>
	/// <Param name="strHeatID" type="LPCTSTR">¯��</Param>
	/// </Method>
	L3BOOL DoBlowwing(LPCTSTR strAreaUri,LPCTSTR strHeatID);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFHeatGears" type="L3BOOL">
	/// ����LF���ȵ�λ���� 2009-01-02
	/// <Param name="rsData" type="L3RECORDSET">��λ����</Param>
	/// </Method>
	L3BOOL AcceptLFHeatGears(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFBlowArData" type="L3BOOL">
	/// ����LF¯����������� 2009-03-23
	/// <Param name="rsData" type="L3RECORDSET">�����������</Param>
	/// </Method>
	L3BOOL AcceptLFBlowArData(L3RECORDSET rsData);

	/// <Method class="CLF_Unit_Mag" name="SetTreatNoForBlowArData" type="L3BOOL">
	/// �Դ���ʼǰ����������ô���������� 2009-03-23
	/// <Param name="csHeatID" type="LPCTSTR">¯��</Param>
	/// <Param name="csTreatNo" type="LPCTSTR">�����</Param>
	/// </Method>
	L3BOOL SetTreatNoForBlowArData(LPCTSTR csHeatID,LPCTSTR csTreatNo);

	/// <Method class="CLF_Unit_Mag" name="AcceptLFBlowArFlow" type="L3BOOL">
	/// ����LFʵ��������� 2009-03-23
	/// <Param name="rsData" type="L3RECORDSET">��λ����</Param>
	/// </Method>
	L3BOOL AcceptLFBlowArFlow(L3RECORDSET rsData);

	//�����ѹ��ʱ��2009-03-28
	L3LONG CalculateHoldTime(LPCTSTR lpcszTreatNo,L3DATETIME dArrival);

	/// ��ȡǰ����� 2009-03-28
	CString GetPreviousTreatNo(LPCTSTR lpcszTreatNo);


	/// <Method class="CLF_Unit_Mag" name="ModifyLadleGrade" type="L3LONG">
	/// �޸İ���//2009-03-30 Liao
	/// <Param name="strTreatNo" type="L3STRING">�����</Param>
	/// <Param name="strLadleGrade" type="L3STRING">����</Param>
	/// </Method>
	L3LONG ModifyLadleGrade(L3STRING strTreatNo, L3STRING strLadleGrade);


	/// <Method class="CLF_Unit_Mag" name="CalEleRateValue" type="L3LONG">
	/// ���������������ֵ
	/// <Param name="strHeatID" type="L3STRING">¯�κ�</Param>
	/// <Param name="strEleName1" type="L3STRING">Ԫ��1</Param>
	/// <Param name="strEleName2" type="L3STRING">Ԫ��2</Param>
	/// </Method>
	L3FLOAT CalEleRateValue(L3STRING strHeatID, L3STRING strEleName1,L3STRING strEleName2);
};

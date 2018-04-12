// �߼���CAOD_Unit_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProduceUnit.h"

const CString AlloyArea1AOD = _T("A");
const CString AlloyAreaComm  = _T("B");

//����ṹ
struct AddtionMaterial
{
	CString  MaterialType;
	CString  MaterialID;
	CString  Batch_ID;
	CString  Code;
	L3DOUBLE nWeight;
};



class CAOD_Unit_Mag :
	public ProduceUnit
{
public:
	CAOD_Unit_Mag(void);
	virtual ~CAOD_Unit_Mag(void);

	DECLARE_L3CLASS(CAOD_Unit_Mag,XGMESLogic\\AODMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

protected:
	UINT m_nTimer;

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

public:

	//2009-03-02�豸״̬������״̬�ֿ� tangyi
	enum _AODStatus
	{
		// ����״̬
		AODWaiting = 0,			// �ȴ�
		AODFeeding = 1,			// ����
		AODDec   =2	,			//��̼
		AODBlowing = 3,      // ������ʼ
		AODBlowStop = 4,		// ��������
		AODReturn = 5,			// ��ԭ
		AODTapping = 6,			// ����
		AODTapped = 7,			// ���ֽ���
	
		
	};

	enum _AODEquipStatus
	{
		// �쳣״̬
		AODNormal = 0,	
		AODRepair = -1,			// ����
		AODBushing = -2,		// �׹�
		AODMaintain = -3,		// ��¯
		AODFailure = -4,		// ����
	};

protected:
	/// <Property class="CAOD_Unit_Mag" name="HeatID" type="L3STRING">
	/// ��ǰ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Unit_Mag" name="HeatID" type="L3STRING">
	/// ��һ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(NextHeatID)

	/// <Property class="CAOD_Unit_Mag" name="Status" type="L3LONG">
	/// ��ǰ״̬
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CAOD_Unit_Mag" name="LanceAge" type="L3LONG">
	/// ǹ��
	/// </Property>
	DECLARE_L3PROP_LONG(LanceAge)

	/// <Property class="CAOD_Unit_Mag" name="FurnaceAge" type="L3LONG">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(FurnaceAge)


	/// ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(LanceNo)

	//����
	
	DECLARE_L3PROP_LONG(Step)

	//��ԭ��־
	DECLARE_L3PROP_LONG(Return_Flag)

	/// <Property class="CAOD_Unit_Mag" name="Addition_Type" type="L3LONG">
	/// ��ǰ��������
	/// </Property>
	DECLARE_L3PROP_LONG(Addition_Type)

	/// <Property class="CAOD_Unit_Mag" name="TopFlow" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TopFlow)

	/// <Property class="CAOD_Unit_Mag" name="TopPressure" type="L3DOUBLE">
	/// ����ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TopPressure)

	/// <Property class="CAOD_Unit_Mag" name="BottomFlow1" type="L3DOUBLE">
	/// �״�����1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow1)

	/// <Property class="CAOD_Unit_Mag" name="BottomPressure1" type="L3DOUBLE">
	/// �״�ѹ��1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure1)

	/// <Property class="CAOD_Unit_Mag" name="BottomFlow2" type="L3DOUBLE">
	/// �״�����2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow2)

	/// <Property class="CAOD_Unit_Mag" name="BottomPressure2" type="L3DOUBLE">
	/// �״�ѹ��2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure2)

	/// <Property class="CAOD_Unit_Mag" name="BottomFlow3" type="L3DOUBLE">
	/// �״�����3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow3)

	/// <Property class="CAOD_Unit_Mag" name="BottomPressure3" type="L3DOUBLE">
	/// �״�ѹ��3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure3)

	/// <Property class="CAOD_Unit_Mag" name="BottomFlow4" type="L3DOUBLE">
	/// �״�����4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomFlow4)

	/// <Property class="CAOD_Unit_Mag" name="BottomPressure4" type="L3DOUBLE">
	/// �״�ѹ��4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BottomPressure4)

	/// <Property class="CAOD_Unit_Mag" name="BottomFlow5" type="L3DOUBLE">
	/// �״�����5
	/// </Property>

	/// <Property class="CAOD_Unit_Mag" name="BlowTotalTime" type="L3DOUBLE">
	/// �ܴ���ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(BlowTotalTime)

	/// <Property class="CAOD_Unit_Mag" name="BlowThisTime" type="L3DOUBLE">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(BlowThisTime)

	/// <Property class="CAOD_Unit_Mag" name="BlowingEvent" type="L3LONG">
	/// ������ʼ�¼���0��ֹͣ��1��������2������
	/// </Property>
	DECLARE_L3PROP_LONG(BlowingEvent)

	/// <Property class="CPlan_Tapping" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CPlan_Tapping" name="Load" type="L3DOUBLE">
	/// װ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Load)

	/// <Property class="CPlan_Tapping" name="CurTemp" type="L3DOUBLE">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CurTemp)
	
	/// <Property class="CAOD_Unit_Mag" name="ReSampleEvent" type="L3LONG">
	/// ����ȡ���¼�
	/// </Property>
	DECLARE_L3PROP_LONG(ReSampleEvent)

	/// <Property class="CAOD_Unit_Mag" name="UndoApplyEvent" type="L3LONG">
	/// ί�е������¼�
	/// </Property>
	DECLARE_L3PROP_LONG(UndoApplyEvent)

	/// <Property class="CAOD_Unit_Mag" name="ReSampleHeatID" type="L3STRING">
	/// ��ȡ��֪ͨ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(ReSampleHeatID)

	/// <Property class="CAOD_Unit_Mag" name="StartProcessTime" type="L3STRING">
	/// ����ʼʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(StartProcessTime)//2008-12-26


	/// <Property class="CAOD_Unit_Mag" name="Taphole_Life" type="L3LONG">
	/// ���ֿ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Taphole_Life)

	/// <Property class="CAOD_Unit_Mag" name="Equip_Status" type="L3LONG">
	/// ��ǰ״̬
	/// </Property> 2009-03-02�豸״̬ tangyi
	DECLARE_L3PROP_LONG(Equip_Status)

	/// <Property class="CAOD_Unit_Mag" name="Plan_Count" type="L3LONG">
	///�ƻ���
	/// </Property> 2009-03-02�豸״̬ tangyi
	DECLARE_L3PROP_LONG(Plan_Count)
	DECLARE_L3PROP_LONG(FurnaceNo)

	


	///////////////////////////////////////////////////////////////////////////////////////
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

	
	/// <Method class="CAOD_Unit_Mag" name="GetScrapesForDesignate" type="L3RECORDSET">
	/// ��ȡ��ѡ�ϸ���Ϣ��¼�����ش��зϸֲۺźͷϸ����ļ�¼����
	/// </Method>
	L3RECORDSET GetScrapesForDesignate();

	/// ������һ¯��
	CString FindNextHeatIDFromPlan();

	/// ͨ��ת¯����״̬�޸ĺ���
	BOOL ChangeAODStatus(LONG nStatus);

	/// ͨ�üƻ�״̬�޸ĺ���
	BOOL ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status);

	/// <Method class="CAOD_Unit_Mag" name="FeedIrons" type="L3BOOL">
	/// ���ж�����ʹ������ָ������ˮ�ͷϸֶ����ж�����
	/// </Method>
	L3BOOL FeedIrons();
	/// <Method class="CAOD_Unit_Mag" name="FeedElement" type="L3BOOL">
	/// ��ת¯�м��ϡ�
	/// <Param name="rsElement" type="L3RECORDSET">�������ݣ��������ͣ����ϴ��룬����</Param>
	/// </Method>
	L3BOOL FeedElement(L3RECORDSET rsElement);
	/// <Method class="CAOD_Unit_Mag" name="TopBlowing" type="L3BOOL">
	/// ������¼ת¯�����¼���
	/// <Param name="rsBlow" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL TopBlowing(L3RECORDSET rsBlow);
	/// <Method class="CAOD_Unit_Mag" name="BottomBlowing" type="L3BOOL">
	/// ������¼�״��¼���
	/// <Param name="rsBlow" type="L3RECORDSET">�״�����</Param>
	/// </Method>
	L3BOOL BottomBlowing(L3RECORDSET rsBlow);
	/// <Method class="CAOD_Unit_Mag" name="StartBlowing" type="L3BOOL">
	/// ת¯���봵��
	/// <Param name="bMainBlowing" type="L3BOOL">������ʶ</Param>
	/// <Param name="Catch_Time" type="L3DATETIME">��ʼʱ��</Param>
	/// </Method>

	L3BOOL StartDec();

	L3BOOL StartBlowing();


	/// <Method class="CAOD_Unit_Mag" name="StopBlowing" type="L3BOOL">
	/// ת¯��������
	/// <Param name="Catch_Time" type="L3DATETIME">����ʱ��</Param>
	/// </Method>
	L3BOOL StopBlowing();

	L3BOOL StartReturn();
	/// <Method class="CAOD_Unit_Mag" name="SetOxygen" type="L3BOOL">
	/// ������¼�����¼���
	/// <Param name="rsOxygen" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL SetOxygen(L3RECORDSET rsOxygen);
	/// <Method class="CAOD_Unit_Mag" name="SetTemperature" type="L3BOOL">
	/// ������¼ת¯�����¼���
	/// <Param name="rsTemp" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL SetTemperature(L3RECORDSET rsTemp);
	/// <Method class="CAOD_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
	/// �޸�ת¯�豸״̬
	/// <Param name="nStatus" type="L3LONG">���豸״̬</Param>
	/// <Param name="reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL ChangeDeviceStatus(L3LONG nStatus,L3STRING reason);
	/// <Method class="CAOD_Unit_Mag" name="StartTapping" type="L3BOOL">
	/// ������ֿ�ʼ�¼�
	/// </Method>
	L3BOOL StartTapping();
	/// <Method class="CAOD_Unit_Mag" name="StopTapping" type="L3BOOL">
	/// ������ֽ����¼�
	/// </Method>
	L3BOOL StopTapping();
	/// <Method class="CAOD_Unit_Mag" name="Splashing" type="L3BOOL">
	/// ת¯��ʼ����
	/// </Method>
	L3BOOL Splashing();
	/// <Method class="CAOD_Unit_Mag" name="Dumping" type="L3BOOL">
	/// ת¯��ʼ����
	/// </Method>
	L3BOOL Dumping();
	/// <Method class="CAOD_Unit_Mag" name="Waiting" type="L3BOOL">
	/// ת¯����ȴ�״̬��
	/// </Method>
	L3BOOL Waiting();
	/// <Method class="CAOD_Unit_Mag" name="GetIronsForDesignate" type="L3RECORDSET">
	/// ���ؿ�����ָ��¯�ŵ���ˮ��Ϣ��
	/// </Method>
	L3RECORDSET GetIronsForDesignate();
	/// <Method class="CAOD_Unit_Mag" name="GetInputIrons" type="L3RECORDSET">
	/// �����Ѿ�ָ���˵���ˮ��Ϣ
	/// </Method>
	L3RECORDSET GetInputIrons();
	/// <Method class="CAOD_Unit_Mag" name="GetInputScrapes" type="L3RECORDSET">
	/// �����Ѿ�ָ���˵������ϸ���Ϣ
	/// </Method>
	L3RECORDSET GetInputScrapes();
	/// <Method class="CAOD_Unit_Mag" name="OnTimer" type="L3BOOL">
	/// ��ʱ������
	/// <Param name="uEventID" type="L3ULONG">�¼�ID</Param>
	/// </Method>
	L3BOOL OnTimer(L3ULONG uEventID);
	/// <Method class="CAOD_Unit_Mag" name="GetAddedMaterialSum" type="L3RECORDSET">
	/// ����ָ��¯�ŵļ�����ͳ�����ݡ�
	/// <Param name="HeatID" type="L3STRING">¯��</Param>
	/// </Method>
	L3RECORDSET GetAddedMaterialSum(L3STRING HeatID);


	/// <Method class="CCCM_Unit_Mag" name="ChangeSteelGrade" type="L3BOOL">
	/// ����ĸ�
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL ChangeSteelGradeApp(L3STRING Reason,L3DOUBLE fWeight);

	/// <Method class="CCCM_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  ��ˮ��¯����
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL SteelReturnApp(L3STRING Reason,L3DOUBLE fWeight,L3STRING strHeatID);


	/// <Method class="CAOD_Unit_Mag" name="AcceptAlloyDischargeData" type="L3RECORDSET">
	/// �Ͻ��ϲּ������ݲɼ�
	/// <Param name="HeatID" type="L3STRING">¯��</Param>
	/// </Method>
	L3BOOL AcceptMaterialDischargeData(L3RECORDSET rsMaterialData);



	/// <Method class="CAOD_Unit_Mag" name="MaterialGroundDischargeData" type="L3RECORDSET">
	/// ��װ�Ͻ�ɢ״������
	/// <Param name="HeatID" type="L3STRING">¯��</Param>
	/// </Method>
	L3BOOL MaterialGroundDischargeData(L3RECORDSET rsMaterialData);

	/// <Method class="CAOD_Unit_Mag" name="GetExceptHeatID" type="L3RECORDSET">
	/// ��ȡ�����쳣¯�����ݡ�
	/// <Param name="UnitID" type="L3STRING">��λ</Param>
	/// </Method>
	L3RECORDSET GetExceptHeatID(L3STRING UnitID);

	/// <Method class="CAOD_Unit_Mag" name="SetTemperature" type="L3BOOL">
	/// ��¼ת¯¯��ά������
	/// <Param name="rsData" type="L3RECORDSET">¯������</Param>
	/// </Method>
	L3BOOL SetStackData(L3RECORDSET rsData);

	/// <Method class="CAOD_Unit_Mag" name="LockData" type="L3SHORT">
	/// ����ʵ������
	/// <Param name="strUnitID" type="L3STRING">��λ</Param>
	/// <Param name="strHeatID" type="L3STRING">¯��</Param>
	/// <Param name="strTreatNo" type="L3STRING">�����</Param>
	/// </Method>
	L3SHORT LockData(L3STRING strUnitID,L3STRING strHeatID,L3STRING strTreatNo);

	/// <Method class="CAOD_Unit_Mag" name="AcceptAODStatus" type="L3BOOL">
	/// ����ת¯����״̬���� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">״̬����</Param>
	/// </Method>
	L3BOOL AcceptAODStatus(L3RECORDSET rsData);

	//���ղ�����Ϣ
	L3BOOL AcceptAODStep(L3RECORDSET rsData);

	/// <Method class="CAOD_Unit_Mag" name="AcceptAODBottomBlowData" type="L3BOOL">
	/// ����ת¯�״����� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">�״�����</Param>
	/// </Method>
	L3BOOL AcceptAODBottomBlowData(L3RECORDSET rsData);

	/// <Method class="CAOD_Unit_Mag" name="AcceptAODTopBlowData" type="L3BOOL">
	/// ����ת¯�������� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptAODTopBlowData(L3RECORDSET rsData);

	/// <Method class="CAOD_Unit_Mag" name="AcceptAODTappedData" type="L3BOOL">
	/// ����ת¯�������� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptAODTappedData(L3RECORDSET rsData);

	/// <Method class="CAOD_Unit_Mag" name="AcceptAODTempData" type="L3BOOL">
	/// ����ת¯�������� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptAODTempData(L3RECORDSET rsData);

	/// <Method class="CAOD_Unit_Mag" name="AcceptAODOxygenData" type="L3BOOL">
	/// ����ת¯�������� 2008-12-28
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptAODOxygenData(L3RECORDSET rsData);


	/// <Method class="CAOD_Unit_Mag" name="CaculateLadleGrade" type="L3BOOL">
	/// ����ְ��ȼ�2008-12-28
	/// </Method>
	L3BOOL CaculateLadleGrade(L3DATETIME dtTapTime,L3STRING strHeatID);




	/// <Method class="CAOD_Unit_Mag" name="CalculateLcTemp" type="L3BOOL">
	/// ������̼�¶����� 2009-01-10
	/// </Method>
	L3BOOL CalculateLcTemp();

	/// <Method class="CAOD_Unit_Mag" name="CalculateTappingTemp" type="L3BOOL">
	/// ��������¶�����(��Դ��Ϊ����:һΪ��¯���£���Ϊ����ʱ����;���ֿ�ʼ֮ǰ�����һ�β���;
	/// �����ֲ�����������ʼ�����ֿ�ʼʱ���δ���£�������¶ȼ�Ϊδ��(-1)������δ���²ɼ�����ʱ�¶�����) 2009-01-10
	/// </Method>
	L3BOOL CalculateTappingTemp();

	/// <Method class="CAOD_Unit_Mag" name="CalculateTappedOxygenContent" type="L3BOOL">
	/// �����������������(ȡ���һ������������) 2009-01-10
	/// </Method>
	L3BOOL CalculateTappedOxygenContent();

	/// <Method class="CAOD_Unit_Mag" name="CalculateFirstLaC" type="L3BOOL">
	/// ����һ����̼(��̼�¶ȵ��ڳ����¶����޲�������̼���ϣ����հ���ʯ��ʯ�ң��źŵģ���Ϊһ����̼) 2009-01-10
	/// </Method>
	L3BOOL CalculateFirstLaC();


	/// <Method class="CCCM_Unit_Mag" name="CompletCasting" type="L3BOOL">
	/// ��컯�鷢�ͽ�����Ϣ,��������д�Ա���Ϣ�ط���2009-01-03 tangyi
	/// </Method>
	L3BOOL SendCastingDataToAnaL2(L3STRING strHeatID);

	/// <Method class="CAOD_Unit_Mag" name="CalculateDefaultSmeltPeriod" type="L3BOOL">
	/// ����ȱʡұ������ 2009-01-14
	/// </Method>
	L3BOOL CalculateDefaultSmeltPeriod();

	/// ��ȡ��һ¯�� 2009-01-14
	CString GetPreviousHeatID(LPCTSTR lpcszHeatID);

	/// <Method class="CAOD_Unit_Mag" name="DesignateIrons" type="L3LONG">
	/// ָ����ԭ��
	/// <Param name="rsIrons" type="L3RECORDSET">��ˮ��Ϣ,Ӧ���ٰ���MaterialID</Param>
	///2009-02-28
	/// </Method>
	L3LONG DesignateMainMaterial(L3RECORDSET rsIrons,L3RECORDSET rsReturnSteel,L3RECORDSET rsScrapes);

	L3LONG AutoDesignateMainMaterial();


	/// <Method class="CAOD_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  ��ȡ���¯�� 2009-02-28 ����¯��
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3RECORDSET GetPreThreeHeatID();

	/// ������һ¯��
	CString CalculateNextHeatID (LPCTSTR lpcszHeatID);

};

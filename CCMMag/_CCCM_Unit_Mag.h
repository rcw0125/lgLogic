// �߼���CCCM_Unit_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProduceUnit.h"

class CCCM_Unit_Mag :
	public ProduceUnit
{
public:
	CCCM_Unit_Mag(void);
	virtual ~CCCM_Unit_Mag(void);

	DECLARE_L3CLASS(CCCM_Unit_Mag,XGMESLogic\\CCMMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

public:
	enum _CCMStatus
	{
		// ����״̬
		CCMWaiting = 0,			// �ȴ�״̬
		CCMArrivle = 1,			// ����
		CCMCasting = 2,			// ��ע��
		CCMCasted = 3,			// ��ע����
		CCMDeparture = 4,		// ����°�
	};

	//2009-03-02 tangyi
	enum _CCMEquipStatus
	{
		// �쳣״̬
		CCMNormal = 0,			// ����
		CCMRepair = -1,			// ������
		CCMFailure = -2,		// ����
	};

	enum _CCMST
	{
		ST1 = 1,			//1��
		ST2 = 2,			//2��
		ST3 = 3,			//3��
		ST4 = 4,			//4��
	};

	enum _CCMEquipType
	{
		SmoothBlock = 1,			//����
		WaterGap = 2,			    //ˮ��
		BigWaterGap = 3,			//���ˮ��
	};

protected:
	CString cstrStopCastingHeatID; //2009-04-18 ���ڽ������һ¯ͣ������ͣ��״״̬��ʱ�̵�����

	int CastNum1ST,CastNum2ST,CastNum3ST,CastNum4ST;
	CString GetPrepareArea();
	CString GetCastingArea();
	CString GetBloomingArea();

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

	/// <Property class="CCCM_Unit_Mag" name="Status" type="L3LONG">
	/// ��ǰ״̬
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CCCM_Unit_Mag" name="TreatNo" type="L3STRING">
	/// ��ǰ�����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Unit_Mag" name="CastingNo" type="L3STRING">
	/// ��ǰ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Unit_Mag" name="TundishNo" type="L3STRING">
	/// ��ǰ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_Unit_Mag" name="HeatID" type="L3STRING">
	/// ��ǰ��ע¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Unit_Mag" name="NextHeatID" type="L3STRING">
	/// ��һ����¯��
	/// </Property>
	DECLARE_L3PROP_STRING(NextHeatID)

	/// <Property class="CCCM_Unit_Mag" name="SteelGradeIndex" type="L3STRING">
	/// ��ǰ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CCCM_Unit_Mag" name="SteelGrade" type="L3STRING">
	/// ��ǰ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CCCM_Unit_Mag" name="RemainedWeight" type="L3DOUBLE">
	/// ��ǰ��ע��ˮʣ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(RemainedWeight)

	/// <Property class="CCCM_Unit_Mag" name="CastingEndEvent" type="L3LONG">
	/// �������������¼�
	/// </Property>
	DECLARE_L3PROP_LONG(CastingEndEvent)  

	/// <Property class="CCCM_Unit_Mag" name="CutSampleHeatID" type="L3STRING">
	/// ����֪ͨ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(CutSampleHeatID)
	/// <Property class="CCCM_Unit_Mag" name="ReSampleHeatID" type="L3STRING">
	/// ��ȡ��֪ͨ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(ReSampleHeatID)

	/// <Property class="CCCM_Unit_Mag" name="ArriveTime" type="L3STRING">
	/// �������ʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(ArriveTime)

	/// <Property class="CCCM_Unit_Mag" name="StartCastingTime" type="L3STRING">
	/// �������ʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(StartCastingTime)

	/// <Property class="CCCM_Unit_Mag" name="LadleID" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)//2008-12-28

	/// <Property class="CCCM_Unit_Mag" name="NextLadleID" type="L3STRING">
	/// ��һ�ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(NextLadleID)//2008-12-28

	/// <Property class="CCCM_Unit_Mag" name="TundishWeight" type="L3DOUBLE">
	/// ��ǰ�а���ˮʣ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TundishWeight)////2009-01-03

	/// <Property class="CCCM_Unit_Mag" name="EastTundishID" type="L3STRING">
	/// ���濾�а���
	/// </Property>
	DECLARE_L3PROP_STRING(EastTundishID)//2009-01-03

	/// <Property class="CCCM_Unit_Mag" name="WestTundishID" type="L3STRING">
	/// ���濾�а���
	/// </Property>
	DECLARE_L3PROP_STRING(WestTundishID)//2009-01-03

	/// <Property class="CCCM_Unit_Mag" name="SteelWeight" type="L3DOUBLE">
	/// �������ظ�ˮ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SteelWeight)////2009-01-03


	/// <Property class="CCCM_Unit_Mag" name="TundishTemp" type="L3LONG">
	///�а��¶�
	/// </Property>
	DECLARE_L3PROP_LONG(TundishTemp)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="Speed1st" type="L3DOUBLE">
	///1st����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed1st)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="Speed2st" type="L3DOUBLE">
	///2st����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed2st)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="Speed3st" type="L3DOUBLE">
	///3st����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed3st)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="Speed4st" type="L3DOUBLE">
	///4st����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed4st)////2009-01-14

	/// <Property class="CCCM_Unit_Mag" name="SumCastWeight1st" type="L3DOUBLE">
	///1st�������ۼ�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SumCastWeight1st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="SumCastWeight2st" type="L3DOUBLE">
	///2st�������ۼ�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SumCastWeight2st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="SumCastWeight3st" type="L3DOUBLE">
	///3st�������ۼ�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SumCastWeight3st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="SumCastWeight4st" type="L3DOUBLE">
	///4st�������ۼ�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SumCastWeight4st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="CastTo15Minute" type="L3LONG">
	///��ע����15����
	/// </Property>
	DECLARE_L3PROP_LONG(CastTo15Minute)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="OnOff1st" type="L3LONG">
	///1st��ͣ��״̬
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff1st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="OnOff2st" type="L3LONG">
	///2st��ͣ��״̬
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff2st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="OnOff3st" type="L3LONG">
	///3st��ͣ��״̬
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff3st)////2009-02-28

	/// <Property class="CCCM_Unit_Mag" name="OnOff4st" type="L3LONG">
	///4st��ͣ��״̬
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff4st)////2009-02-28


	/// <Property class="CCCM_Unit_Mag" name="Eqiup_Status" type="L3LONG">
	/// �豸״̬
	/// </Property>2009-03-02
	DECLARE_L3PROP_LONG(Equip_Status)


	/// <Property class="CCCM_Unit_Mag" name="Cut_Information" type="L3LONG">
	/// ����֪ͨ
	/// </Property>2009-03-11
	DECLARE_L3PROP_LONG(Cut_Information)

	/// <Property class="CCCM_Unit_Mag" name="RemainCastingTime" type="L3LONG">
	/// ��ǰʣ�ཽעʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(RemainCastingTime)

	/// <Property class="CCCM_Unit_Mag" name="PrevHeatID" type="L3STRING">
	/// ͣ��ǰ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PrevHeatID)

	/// ������һ�����
	CString CalculateNextTreatNo(LPCTSTR lpcszTreatNo);
	/// ������һ���κ�
	CString CalculateNextCastingNo(LPCTSTR lpcszCastingNo);
	/// ������һ���κ�
	CString CalculateNextTundishNo(LPCTSTR lpcszTundishNo);
	
	/// ͨ�ù���״̬�޸ĺ���
	BOOL ChangeStatus(LONG nStatus);

	/// ͨ�üƻ�״̬�޸ĺ���
	BOOL ChangePlanStatus(LPCTSTR lpcszHeatID,LPCTSTR lpcszTreatNo,LPCTSTR Status);

	/// <Method class="CCCM_Unit_Mag" name="GetInputSteels" type="L3RECORDSET">
	/// ������ڸ�ˮ��Ϣ.
	/// </Method>
	L3RECORDSET GetInputSteels();
	/// <Method class="CCCM_Unit_Mag" name="DesignateSteel" type="L3BOOL">
	/// ָ���¸����ߵĸ�ˮ.
	/// <Param name="rsSteel" type="L3RECORDSET">Ҫָ�����ߵĸ�ˮ��¼</Param>
	/// </Method>
	L3BOOL DesignateSteel(L3RECORDSET rsSteel);
	/// <Method class="CCCM_Unit_Mag" name="SteelArrived" type="L3BOOL">
	/// ��������ˮ�����¼�����ָ���ĸ�ˮ���ߡ�
	/// </Method>
	L3BOOL SteelArrived();
	/// <Method class="CCCM_Unit_Mag" name="StartCasting" type="L3BOOL">
	/// ��ʼ�����ע
	/// </Method>
	L3BOOL StartCasting();
	/// <Method class="CCCM_Unit_Mag" name="CompletCasting" type="L3BOOL">
	/// ��ɴ����ע
	/// </Method>
	L3BOOL CompletCasting();
	/// <Method class="CCCM_Unit_Mag" name="ChangeCastingNo" type="L3BOOL">
	/// ��������
	/// </Method>
	L3BOOL ChangeCastingNo();
	/// <Method class="CCCM_Unit_Mag" name="ChangeTundishNo" type="L3BOOL">
	/// ��������
	/// </Method>
	L3BOOL ChangeTundishNo();
	/// <Method class="CRH_Unit_Mag" name="ChangeDeviceStatus" type="L3BOOL">
	/// �޸��豸״̬
	/// <Param name="nStatus" type="L3LONG">���豸״̬</Param>
	/// <Param name="reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL ChangeDeviceStatus(L3LONG nStatus, L3STRING reason);
	/// <Method class="CCCM_Unit_Mag" name="DivideHeatApp" type="L3BOOL">
	/// ����¯�ηָ�
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL DivideHeatApp(L3STRING Reason);
	/// <Method class="CCCM_Unit_Mag" name="SendBackSteelApp" type="L3BOOL">
	/// �������������͡�
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL SteelBackApp(L3STRING Reason);
	/// <Method class="CCCM_Unit_Mag" name="GenerateBlooms" type="L3BOOL">
	/// ¯�γ���
	/// <Param name="rsBloomData" type="L3RECORDSET">��������</Param>
	/// <Param name="HeatID" type="L3STRING">����¯��</Param>
	/// </Method>
	L3BOOL GenerateBlooms(L3RECORDSET rsBloomData);
	/// <Method class="CCCM_Unit_Mag" name="SetRemainedSteelWeight" type="L3BOOL">
	/// ������ʣ�������źš�
	/// <Param name="fWeight" type="L3DOUBLE">���ʣ������</Param>
	/// </Method>
	L3BOOL SetRemainedSteelWeight(L3DOUBLE fWeight);


	/// <Method class="CCCM_Unit_Mag" name="SendTurnSteelApp" type="L3BOOL">
	/// ��������ˮ��¯��
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL SteelReturnApp(L3STRING Reason);


	/// <Method class="CCCM_Unit_Mag" name="GetHeatAllInformation" type="">
	/// ��ȡ�Ѿ�������¯�ε���Ϣ
	/// </Method>
	L3RECORDSET GetHeatAllInformation();


	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMTundishFireData" type="L3BOOL">
	/// ���������а��濾���� 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">�а��濾����</Param>
	/// </Method>
	L3BOOL AcceptCCMTundishFireData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMRuntimeData" type="L3BOOL">
	/// ���������������ս������һ�ε�ʵʱ���� 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
	/// </Method>
	L3BOOL AcceptCCMRuntimeData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMSpeedData" type="L3BOOL">
	/// ���������������ս�����ʵʱ���� 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
	/// </Method>
	L3BOOL AcceptCCMSpeedData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMTundishTempData" type="L3BOOL">
	/// ���������������ս��а��������� 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">�а���������</Param>
	/// </Method>
	L3BOOL AcceptCCMTundishTempData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMStatus" type="L3BOOL">
	/// ������������״̬���� 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">״̬����</Param>
	/// </Method>
	L3BOOL AcceptCCMStatus(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMLadleWeightData" type="L3BOOL">
	/// �����������а��������� 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptCCMLadleWeightData(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMSteelWeightData" type="L3BOOL">
	/// ����������ˮ�������� 2009-01-03
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptCCMSteelWeightData(L3RECORDSET rsData);

	//�����ѹ��ʱ��
    L3DATETIME CalculateHoldTime(LPCTSTR lpcszTreatNo);

	/// <Method class="CCCM_Unit_Mag" name="GetHeatAllInformation" type="">
	/// ��ȡ���Խ���¯��ȷ������Ϣ
	/// </Method>
	L3RECORDSET GetHeatConfirmInfor();


	/// <Method class="CCCM_Unit_Mag" name="AcceptCCM5Runtime1Data" type="L3BOOL">
	/// ����5#�����������ս������һ�ε�ʵʱ���� 2009-02-25
	/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
	/// </Method>
	L3BOOL AcceptCCM5Runtime1Data(L3RECORDSET rsData);

    /// <Method class="CCCM_Unit_Mag" name="AcceptCCM5Runtime2Data" type="L3BOOL">
	/// ����5#�����������ս������һ�ε�ʵʱ������ȴ������� 2009-02-25
	/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
	/// </Method>
	L3BOOL AcceptCCM5Runtime2Data(L3RECORDSET rsData);

	/// ��ȡǰ����� 2009-02-26
	CString GetPreviousTreatNo(LPCTSTR lpcszTreatNo);

/// <Method class="CCCM_Unit_Mag" name="LadleDeparture" type="L3BOOL">
	/// ����°�
	/// </Method>
	L3BOOL LadleDeparture();

	/// <Method class="CCCM_Unit_Mag" name="AcceptCCM5Runtime2Data" type="L3BOOL">
	/// ����������ˮ�������� 2009-02-26
	/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
	/// </Method>
	L3BOOL AcceptSteelWeight(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptStrandStatusData" type="L3BOOL">
	/// ����������״̬���� 2009-02-26
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptStrandStatusData(L3RECORDSET rsData);

	/// ��ȡ¯����GUID 2009-02-26
    CString GetHeatStrandGUID(LPCTSTR lpcszHeatID,LPCTSTR lpcszCCMID,L3LONG iStrandID);

	/// <Method class="CCCM_Unit_Mag" name="ArrivalTemperatureJudge" type="L3SHORT">
	/// �ж������¶Ⱥϸ� 2009-02-28
	/// <Param name="lpcszSteelGradeIndex" type="LPCTSTR">���ּǺ�</Param>
	/// <Param name="lpcszUnitType" type="LPCTSTR">��������</Param>
	/// <Param name="iTempertaure" type="L3LONG">�ϻ��¶�</Param>
	/// <Param name="iHeatNum" type="L3LONG">������¯��</Param>
	/// </Method>
	L3SHORT ArrivalTemperatureJudge(LPCTSTR lpcszSteelGradeIndex,LPCTSTR lpcszUnitType,L3LONG iTempertaure,L3LONG iHeatNum);


	//2009-02-28 ����������ʵ��Ĭ��Ϊ��һ¯��ʵ��
	L3BOOL GenProtectSlagInfor(LPCTSTR lpcszTreatNo);

	/// <Method class="CCCM_Unit_Mag" name="CalculateStrandCaseWeight" type="L3BOOL">
	/// ����¯��ͨ���� 2009-02-28
	/// </Method>
	L3BOOL CalculateStrandCaseWeight();

	/// <Method class="CBOF_Unit_Mag" name="SteelReturn" type="L3BOOL">
	///  ��ȡ���¯�� 2009-02-28 ����¯��
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3RECORDSET GetPreThreeHeatID();

	/// <Method class="CCCM_Unit_Mag" name="GetMoldData" type="">
	/// ��ȡ�ᾧ������
	/// </Method>
	L3RECORDSET GetMoldData(LPCTSTR lcpstrStrandId);

	/// <Method class="CCCM_Unit_Mag" name="ChangeCCMEquipment" type="L3BOOL">
	/// ��������/ˮ��/���ˮ��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL ChangeCCMEquipment(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="CalculateEquipmentLife" type="L3LONG">
	/// �����豸���� 2009-03-07
	/// <Param name="iEquipType" type="L3LONG">����/ˮ��/���ˮ��</Param>
	/// <Param name="strCCMID" type="L3STRING">������</Param>
	/// <Param name="iStrandNo" type="L3LONG">����</Param>
	/// <Param name="strReason" type="L3STRING">����</Param>
	/// </Method>
	L3LONG CalculateEquipmentLife(L3LONG iEquipType,L3STRING strCCMID,L3LONG iStrandNo,L3STRING strReason);

	/// <Method class="CCCM_Unit_Mag" name="CalculateRemainCastingTime" type="L3BOOL">
	/// ����ʣ�ཽעʱ��
	/// </Method>
	L3BOOL CalculateRemainCastingTime();

	/// <Method class="CCCM_Unit_Mag" name="SetTundishTempInValidFlag" type="L3BOOL">
	/// �����а��¶���Ч��־ 2009-03-25
	/// </Method>
	L3BOOL SetTundishTempInValidFlag(LPCTSTR strHeatID,LPCTSTR strCCMID);

	/// <Method class="CCCM_Unit_Mag" name="SendSteelWeightToPLC" type="L3BOOL">
	/// ����ˮ�����´�PLC 2009-03-26
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL  SendSteelWeightToPLC(L3FLOAT fSteelWeight);

	/// <Method class="CCCM_Unit_Mag" name="ChangeSteelGradeApp" type="L3BOOL">
	/// ����ĸ�2009-04-15
	/// <Param name="Reason" type="L3STRING">ԭ��</Param>
	/// </Method>
	L3BOOL ChangeSteelGradeApp(L3STRING Reason);

	/// <Method class="CCCM_Unit_Mag" name="ModifyStrandStatusData" type="L3LONG">
	/// �޸�������״̬���� 2009-04-18
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyStrandStatusData(L3RECORDSET rsData);


	/// <Method class="CCCM_Unit_Mag" name="AcceptCCMTundishTempData" type="L3BOOL">
	/// ��������������2�����а��������� 2009-06-02
	/// <Param name="rsData" type="L3RECORDSET">�а���������</Param>
	/// </Method>
	L3BOOL AcceptCCMTundishTempForRefine(L3RECORDSET rsData);

	/// <Method class="CCCM_Unit_Mag" name="AcceptTundishWeightData" type="L3BOOL">
	/// ���������а���ˮ�������� 2009-02-26
	/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
	/// </Method>
	L3BOOL AcceptTundishWeightData(L3RECORDSET rsData);
};

// �߼���CDeS_Unit_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "ProduceUnit.h"

class CDeS_Unit_Mag :
	public ProduceUnit
{
public:
	CDeS_Unit_Mag(void);
	virtual ~CDeS_Unit_Mag(void);

	DECLARE_L3CLASS(CDeS_Unit_Mag,XGMESLogic\\DeSMag, Name)
	DECLARE_L3PROPTABLE()

	DECLARE_L3METHODMAP(CDeS_Unit_Mag)
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

	/// <Property class="CDeS_Unit_Mag" name="MaterialID_UnDeS" type="L3STRING">
	/// δ�������Ϻ�
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID_UnDeS)

	/// <Property class="CDeS_Unit_Mag" name="MaterialID_DeSing" type="L3STRING">
	/// ���������Ϻ�
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID_DeSing)

	/// <Property class="CDeS_Unit_Mag" name="MaterialID_DeSed" type="L3STRING">
	/// ���������Ϻ�
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID_DeSed)

	/// <Property class="CDeS_Unit_Mag" name="TreatNo" type="L3STRING">
	/// ��ǰ�紵��
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CDeS_Unit_Mag" name="NextTreatNo" type="L3STRING">
	/// ��һ�紵��
	/// </Property>
	DECLARE_L3PROP_STRING(NextTreatNo)

	/// <Property class="CDeS_Unit_Mag" name="CurArea" type="L3STRING">
	/// ��ǰ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(CurArea)

	/// <Property class="CDeS_Unit_Mag" name="Weight_MatTank" type="L3DOUBLE">
	/// ���Ϲ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_MatTank)

	/// <Property class="CDeS_Unit_Mag" name="Weight_SprayTank" type="L3DOUBLE">
	/// �紵������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_SprayTank)

	/// <Property class="CDeS_Unit_Mag" name="Pressure" type="L3DOUBLE">
	/// ����ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure)

	/// <Property class="CDeS_Unit_Mag" name="Flow" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow)

	/// <Property class="CDeS_Unit_Mag" name="Rate" type="L3DOUBLE">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Rate)

	/// <Property class="CDeS_Unit_Mag" name="Mat_Code" type="L3STRING">
	/// ���������
	/// </Property> 
	DECLARE_L3PROP_STRING(Mat_Code)

	/// <Property class="CDeS_Unit_Mag" name="Mat_Vendor" type="L3STRING">
	/// ���������
	/// </Property> 
	DECLARE_L3PROP_STRING(Mat_Vendor)

	/// <Property class="CDeS_Unit_Mag" name="EventIronChanged" type="L3LONG">
	/// ��ˮ���ݱ���¼�
	/// </Property>
	DECLARE_L3PROP_LONG(EventIronChanged)

	/// <Property class="CDeS_Unit_Mag" name="S" type="L3DOUBLE">
	/// ǰS
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CDeS_Unit_Mag" name="Equipment_Status" type="L3LONG">
	/// �豸״̬
	/// (1:����;
	///  2:����;
	///  3:�ȴ�;
	///  4:����;
	///  5:�罬;
	///  6:����������;
	///  7:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(Equipment_Status)

	/// <Property class="CDeS_Unit_Mag" name="DeSType" type="L3SHORT">
	/// ��������
	/// (1:ǳ����
	///  2:��׼����
	///  3:������
	///  4:��������
	///  5:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(DeSType)

	/// <Property class="CDeS_Unit_Mag" name="DeSStatus" type="L3LONG">
	/// ����״̬(1:׼������ 2:��ˮ��վ 9:���޳�վ
	/// </Property>
	DECLARE_L3PROP_LONG(DeSStatus)

	/// <Property class="CDeS_Unit_Mag" name="DeSStatusChanged_Time" type="L3DATETIME">
	/// ����״̬�仯ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(DeSStatusChanged_Time)

	/// ������һ�����
	CString CalculateNextTreatNo(LPCTSTR lpcszTreatNo);

	/// <Method class="CDeS_Unit_Mag" name="DesignateIronLadle" type="L3BOOL">
	/// ָ�������������ˮ��
	/// <Param name="rsIrons" type="L3STRING">��ˮ(����+�޺�)</Param>
	/// </Method>
	L3LONG DesignateIronLadle(L3RECORDSET rsIrons);

	/// <Method class="CDeS_Unit_Mag" name="UndoDesignateIronLadle" type="L3BOOL">
	/// ����ָ�������������ˮ��
	/// <Param name="strIron" type="L3STRING">��ˮ(����+�޺�)</Param>
	/// </Method>
	L3LONG UndoDesignateIronLadle(L3STRING strIron);

	/// <Method class="CDeS_Unit_Mag" name="UndoDesignateIronLadle" type="L3LONG">
	/// ����������ˮ״̬�仯
	/// <Param name="strIron" type="L3STRING">��ˮ(����+�޺�)</Param>
	/// <Param name="nStatus" type="L3SHORT">��ˮ״̬)</Param>
	/// </Method>
	L3LONG ChangeStatus(L3STRING strIron,L3SHORT nStatus,L3STRING strAreaID);

	/// <Method class="CDeS_Unit_Mag" name="CalculateTime" type="L3BOOL">
	/// ����ʱ��
	/// <Param name="lpcszDeSIron" type="LPCTSTR">��ˮ(����+�޺�)</Param>
	/// <Param name="nStatus" type="L3SHORT">״̬)</Param>
	/// <Param name="ncurStatus" type="L3SHORT">��ǰ״̬)</Param>
	/// </Method>
	L3LONG CalculateTime(LPCTSTR lpcszDeSIron,L3SHORT nStatus,L3SHORT ncurStatus);

	/// <Method class="CDeS_Unit_Mag" name="CalculateRemoveSlagTime" type="L3BOOL">
	/// ��������ʱ��
	/// <Param name="lpcszDeSIron" type="LPCTSTR">��ˮ(����+�޺�)</Param>
		/// <Param name="dArrival" type="L3DATETIME">Ԥ��������ʱ��)</Param>
	/// </Method>
	L3LONG CalculateRemoveSlagTime(LPCTSTR lpcszDeSIron,L3DATETIME dRemoveSlagEndTime);

	/// <Method class="CDeS_Unit_Mag" name="DesignateDeSUnitID" type="L3LONG">
	/// ָ����λ��
	/// <Param name="strIron" type="L3STRING">��ˮ(����+�޺�)</Param>
	/// </Method>
	L3LONG DesignateDeSUnitID(L3STRING strIron);

	/// <Method class="CDeS_Unit_Mag" name="StartBlowing" type="L3LONG">
	/// �����紵��ʼ�¼�
	/// <Param name="Area" type="L3STRING">��ʼ�紵�Ĺ�λ</Param>
	/// </Method>
	L3LONG StartBlowing(L3STRING Area);

    /// <Method class="CDeS_Unit_Mag" name="StopBlowing" type="L3LONG">
	/// �����紵�����¼�
	/// </Method>
	L3LONG StopBlowing();

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSBlowBeginData" type="L3BOOL">
	/// ����DES�紵��ʼ���� 
	/// <Param name="rsData" type="L3RECORDSET">�紵����</Param>
	/// </Method>
	L3BOOL AcceptDeSBlowBeginData(L3RECORDSET rsData);

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSBlowEndData" type="L3BOOL">
	/// ����DES�紵�������� 
	/// <Param name="rsData" type="L3RECORDSET">�紵����</Param>
	/// </Method>
	L3BOOL AcceptDeSBlowEndData(L3RECORDSET rsData);

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSRuntimeData" type="L3BOOL">
	/// ����DES�紵ʵʱ���� 
	/// <Param name="rsData" type="L3RECORDSET">ʵʱ����</Param>
	/// </Method>
	L3BOOL AcceptDeSRuntimeData(L3RECORDSET rsData);

	/// <Method class="CDeS_Unit_Mag" name="SetLanceNo" type="L3LONG">
	/// ����ǹ 
	/// <Param name="strLanceNo" type="L3STRING">ǹ��</Param>
	/// <Param name="strUnitID" type="L3STRING">��λ</Param>
	/// </Method>
	L3LONG ChangeLanceNo(L3STRING strLanceNo,L3STRING strUnitID);

	/// <Method class="CDeS_Unit_Mag" name="ChangeMatCodeAndVendor" type="L3BOOL">
	/// ���������
	/// <Param name="MatCode" type="L3STRING">�����</Param>
	/// <Param name="MatVendor" type="L3STRING">���������</Param>
	/// </Method>
	L3BOOL ChangeMatCodeAndVendor(L3STRING MatCode,L3STRING MatVendor);

	/// <Method class="CDeS_Unit_Mag" name="IronsDeparture" type="L3BOOL">
	/// ������ˮ��վ
	/// <Param name="rsIrons" type="L3RECORDSET">��ˮ(MaterialID,Destination)</Param>
	/// </Method>
	L3LONG IronsDeparture();

	/// <Method class="CDeS_Unit_Mag" name="ChangeTreatNo" type="L3BOOL">
	/// �����紵��
	/// <Param name="strTreatNo" type="L3STRING">�紵��</Param>
	/// </Method>
	L3BOOL ChangeTreatNo(L3STRING strTreatNo);

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSStatusData" type="L3BOOL">
	/// ����DES״̬���� 
	/// <Param name="rsData" type="L3RECORDSET">�紵����</Param>
	/// </Method>
	L3BOOL AcceptDeSStatusData(L3RECORDSET rsData);

	/// <Method class="CDeS_Unit_Mag" name="LockData" type="L3SHORT">
	/// ����ʵ������
	/// <Param name="MaterialID" type="L3STRING">���Ϻ�</Param>
	/// </Method>
	L3SHORT LockData(L3STRING MaterialID);

	/// <Method class="CDeS_Unit_Mag" name="NewDeSAdditionData" type="L3LONG">
	/// ��¼�������������
	/// <Param name="rsMats" type="L3RECORDSET">�����</Param>
	/// </Method>
	L3LONG NewDeSAdditionData(L3RECORDSET rsMats);

	/// <Method class="CDeS_Unit_Mag" name="SetDeSMode" type="L3BOOL">
	/// ������������
	/// <Param name="MaterialID" type="L3STRING">���Ϻ�</Param>
	/// </Method>
	L3BOOL SetDeSMode(L3STRING MaterialID,L3SHORT DeSMode);

	/// <Method class="CDeS_Unit_Mag" name="NewDeSEquipmentStatusData" type="L3LONG">
	/// ��¼�����豸״̬�仯����
	/// <Param name="nStatus" type="L3SHORT">�豸״̬</Param>
	/// <Param name="strReason" type="L3STRING">�豸״̬�仯ԭ��</Param>
	/// </Method>
	L3LONG NewDeSEquipmentStatusData(L3SHORT nStatus,L3STRING strReason);

	/// <Method class="CDeS_Unit_Mag" name="IsOverForPreStatus" type="L3BOOL">
	/// �ж�ǰһ״̬�Ƿ���� 
	/// <Param name="MaterialID" type="LPCTSTR">��ˮ</Param>
	/// <Param name="nStatus" type="LPCTSTR">��ǰ״̬</Param>
	/// <Param name="nEndStatu" type="L3SHORT">ǰ����״̬</Param>
	/// <Param name="AreaID" type="CString">ǰ����״̬</Param>
	/// </Method>
	L3BOOL IsOverForPreStatus(LPCTSTR MaterialID,L3SHORT nStatus,L3SHORT & nEndStatu,CString & AreaID);

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSDepartData" type="L3BOOL">
	/// �����ֳ���վ�ź� 
	/// </Method>
	L3BOOL AcceptDeSDepartData();

	/// <Method class="CDeS_Unit_Mag" name="AddNewLanceData" type="L3LONG">
	/// ������ǹ����
	/// <Param name="rsIrons" type="L3RECORDSET">��ǹ����</Param>
	/// </Method>
	L3LONG AddNewLanceData(L3RECORDSET rsLance);

	/// <Method class="CDeS_Unit_Mag" name="ChangeLanceStatus" type="L3LONG">
	/// �ı���ǹ״̬
	/// <Param name="rsIrons" type="L3RECORDSET">��ǹ����[��ǹ��/״̬]</Param>
	/// </Method>
	L3LONG ChangeLanceStatus(L3RECORDSET rsLance);

	/// <Method class="CDeS_Unit_Mag" name="ChangeLanceAge" type="L3LONG">
	/// �ı���ǹ״̬
	/// <Param name="rsIrons" type="L3RECORDSET">��ǹ����[��ǹ��/ǹ��]</Param>
	/// </Method>
	L3LONG ChangeLanceAge(L3RECORDSET rsLance);

	/// <Method class="CDeS_Unit_Mag" name="AddNewLanceLogData" type="L3LONG">
	/// ������ǹ��־
	/// <Param name="strLanceNo" type="LPCTSTR">��ǹ��</Param>
	/// <Param name="strNote" type="LPCTSTR">��־</Param>
	/// </Method>
	L3LONG AddNewLanceLogData(LPCTSTR strLanceNo,LPCTSTR strNote);

	/// <Method class="CDeS_Unit_Mag" name="PrepareIronLadle" type="L3LONG">
	/// ��ˮ׼��
	/// </Method>
	L3LONG PrepareIronLadle();

	/// <Method class="CDeS_Unit_Mag" name="AcceptDeSArrivalData" type="L3LONG">
	/// ��ˮ��վ
	/// </Method>
	L3LONG AcceptDeSArrivalSignal();

	/// <Method class="CDeS_Unit_Mag" name="GenerateLanceNo" type="L3STRING">
	/// �����紵��
	/// </Method>
	L3STRING GenerateLanceNo();

	/// <Method class="CDeS_Unit_Mag" name="GetUnArrivedIrons" type="L3RECORDSET">
	/// ������ָ��ȥ�򣬵�δ����ȷ�ϵ���ˮ���ݡ�
	/// </Method>
	L3RECORDSET GetUnArrivedIrons();

	/// <Method class="CDeS_Unit_Mag" name="GetUnitForEndStatus" type="L3BOOL">
	/// ��״̬����ʱ��ȡ��Ӧ��ʼ״̬�Ĺ�λ 
	/// <Param name="MaterialID" type="LPCTSTR">��ˮ</Param>
	/// <Param name="nStatus" type="LPCTSTR">��ǰ״̬</Param>
	/// <Param name="AreaID" type="CString">��λ</Param>
	/// </Method>
	L3BOOL GetUnitForEndStatus(LPCTSTR MaterialID,L3SHORT nStatus,CString & AreaID);

	/// <Method class="CDeS_Unit_Mag" name="SetDeSIronPath" type="L3BOOL">
	/// ����Ŀ�ĵ�
	/// <Param name="MaterialID" type="L3STRING">���Ϻ�</Param>
	/// <Param name="nPath" type="L3SHORT">Ŀ�ĵ�</Param>
	/// </Method>
	L3BOOL SetDeSIronPath(L3STRING MaterialID,L3SHORT nPath);

	/// <Method class="CDeS_Unit_Mag" name="BeginRemoveSlagNoDeS" type="L3BOOL">
	/// �ж�ǰһ״̬�Ƿ���� 
	/// <Param name="MaterialID" type="LPCTSTR">��ˮ</Param>
	/// <Param name="AreaID" type="LPCTSTR">��ǰ��λ</Param>
	/// <Param name="nStatus" type="L3SHORT">��ǰ״̬</Param>
	/// <Param name="nDeSType" type="L3SHORT">��������</Param>
	/// </Method>
	L3BOOL BeginRemoveSlagNoDeS(LPCTSTR MaterialID,LPCTSTR AreaID,L3SHORT nStatus,L3SHORT nDeSType);

};

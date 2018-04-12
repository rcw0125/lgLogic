// �߼���CPlan_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "PlanDept.h"


//����ṹ
struct BOFStatus
{
	TCHAR BOFID[4];
	L3DATETIME dtBOF0ProcessEndTime;
};


const L3LONG nNewBOF =1;
const L3LONG nOldBOF =0;


/// <summary>
/// RH����
/// </summary>
enum BOFType
{
	BOF50t = 1,		// ������RH
	BOF80t = 2,			 // 1#RH
};


/// <summary>
/// ��������
/// </summary>
enum CasterType
{
	NoLFCaster = 1,		// 1#2#����
	OldLFCaster = 2,    // 3#4#����
	NewLFCaster = 3,	// 5#����
	//Modify by llj 2011-1-18 ������޸�
	NewLFCaster6 = 4,	// 6#����(������ֻ�����Ų�����¯�������ʱ���Զ�����������Բ���)
	NewLFCaster7 = 5,	// 7#���� 

};

/// <summary>
/// LF����
/// </summary>
enum LFType
{
	NoPassLF = 1,		// ������LF
	OldLF = 2,			 // 1#2#LF
	NewLF = 3,			// 3#LF
};

/// <summary>
/// RH����
/// </summary>
enum RHType
{
	NoPassRH = 1,		// ������RH
	PassRH = 2,			 // 1#RH
};


//����
const CString csCasterType1 =_T("01");//1#2#����
const CString csCasterType2 =_T("02");//3#4#����
const CString csCasterType3 =_T("03");//5#����
//Modify by llj 2011-1-18 ������޸�
const CString csCasterType7 =_T("07");//7#����

//LF
const CString csLFType1 =_T("01");//������LF
const CString csLFType2 =_T("02");//1#2#LF
const CString csLFType3 =_T("03");//3#LF
//Modify by llj 2011-02-11 ����5#LF�޸�
const CString csLFType5 =_T("05");//5#LF
//Add by hyh 2012-05-14  ������޸�
const CString csLFType4 =_T("04");//4#LF

//RH
const CString csRHType1 =_T("01");//������RH
const CString csRHType2 =_T("02");//1#RH


/// <summary>
/// ת¯
/// </summary>
enum HeatType
{
	CurrentHeat = 0,		// ��ǰ¯
	LastHeat = 1,		    // ��һ¯��
	NextHeat = 2,			// ��һ¯��
};

class CPlan_Mag :
	public PlanDept
{
public:
	CPlan_Mag(void);
	virtual ~CPlan_Mag(void);

	DECLARE_L3CLASS(CPlan_Mag,XGMESLogic\\PlanMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	DECLARE_L3PROP_LONG(PlanOrderEvent)               //�ƻ�����״̬�仯�¼�
	DECLARE_L3PROP_LONG(TappingPlanEvent)      //���ּƻ�״̬�仯�¼�
	DECLARE_L3PROP_LONG(TappingPlanGenerateEvent)      //���ּƻ������¼�
	DECLARE_L3PROP_LONG(EquipmentStatusChange)					//�豸״̬�ı�
	DECLARE_L3PROP_LONG(WriteFlag)	
	DECLARE_L3PROP_LONG(BOFChangeFlag)		        //����¯����ʼ��־ 
	DECLARE_L3PROP_LONG(TappingModelFlag)			//����ģ�ͽ�����־
	DECLARE_L3PROP_LONG(PlanExeFlag)			//�ƻ��´��־ 0,1 1:��ʼִ�У�0��ִ�����
	DECLARE_L3PROP_LONG(PlanCancelFlag)			//�ƻ�ȡ����־ 0,1 1:��ʼִ�У�0��ִ�����
	DECLARE_L3PROP_LONG(IronPlanExeFlag)			//��ˮ�ƻ��´��־ 0,1 1:��ʼִ�У�0��ִ�����
	DECLARE_L3PROP_LONG(TappingPlanFlag)			//���ּƻ���־ 0,1 1:��ʼִ�У�0��ִ�����
	DECLARE_L3PROP_LONG(BOFYieldFlag)		    //����ת¯���� 0,1 1:��ʼִ�У�0��ִ�����
	DECLARE_L3PROP_LONG(AddNewBOFFlag)			    //������¯�� 0,1 1:��ʼִ�У�0��ִ�����
	DECLARE_L3PROP_LONG(FirstCastingHeatFlag)			    //ָ�����ε�һ¯ 0,1 1:��ʼִ�У�0��ִ�����
	DECLARE_L3PROP_LONG(ReFirstCastingHeatFlag)			    //����ָ�����ε�һ¯ 0,1 1:��ʼִ�У�0��ִ�����
	DECLARE_L3PROP_LONG(ModifyPlanFlag)			    //�޸� 0,1 1:��ʼִ�У�0��ִ�����
	DECLARE_L3PROP_LONG(PlanDelFlag)			//�ƻ�ȡ����־ 0,1 1:��ʼִ�У�0��ִ�����

	/// <Method class="CPlan_Mag" name="PlanOrdRec" type="L3BOOL">
	/// 
	/// ���ռƻ��������жϼƻ�������״̬�������2���˳��������ƻ�����״̬Ϊ0δȷ��
	/// ARG&gt;&gt; rsPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL PlanOrdRec(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="PlanOrdCfm" type="L3BOOL">
	/// 
	/// �ƻ�����ȷ�ϣ����Ķ�����״̬Ϊ1δ�ճ�
	/// ARG&gt;&gt; rsPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPlan" type="L3RECORDSET">�ƻ�������Ϣ</Param>
	/// </Method>
	L3BOOL PlanOrdCfm(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="GetUnIntegratePlanOrd" type="L3RECORDSET">
	/// 
	/// �������ڻ�ȡδ�ճؼƻ�����
	/// ARG &gt;&gt; Condition : �ճ�������
	/// RET &gt;&gt; �ҵ��ļƻ���¼����
	/// <Param name="Condition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetUnIntegratePlanOrd(L3STRING strDate);

	/// <Method class="CPlan_Mag" name="GetIntegratedPlanOrd" type="L3RECORDSET">
	/// 
	/// �������ڡ�������ȡ�Ѿ��ؼƻ�����
	/// ARG &gt;&gt; Condition : �ճ�������
	/// RET &gt;&gt; �ҵ��ļƻ���¼����
	/// <Param name="Condition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetIntegratedPlanOrd(L3STRING strBeginDate,L3STRING strEndDate,L3STRING strSteelGrade);

	/// <Method class="CPlan_Mag" name="GetIntegratedPlanOrd" type="L3RECORDSET">
	/// 
	/// �������ڡ�������ȡ�������ּƻ�
	/// ARG &gt;&gt;
	/// RET &gt;&gt; �ҵ��ļƻ���¼����
	/// <Param name="Condition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetCastingPlan(L3STRING strDate,L3STRING strCasterID);

	/// <Method class="CPlan_Mag" name="PlanOrdIntegrateCfm" type="L3BOOL">
	/// 
	/// �ƻ������ճ�ȷ�ϣ�ͬʱȷ�������ţ����Ķ�����״̬Ϊ2�ճ�
	/// ARG&gt;&gt; rsPlan : �ƻ����ݡ��������PlanID\CasrterID\New_BOF_Flag�ֶΡ�
	///         &gt;&gt;strCasterID ��������
	///         &gt;&gt;nNewBOFFlag ���¾�ת¯��־
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// <Param name="strCasterID" type="L3STRING"></Param>
	/// </Method>
	L3LONG PlanOrdIntegrateCfm(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="PlanOrdIntegrateCancel" type="L3BOOL">
	/// 
	/// �ƻ������ճ�ȡ����ͬʱȡ�������ţ����Ķ�����״̬Ϊ1δ�ճ�
	/// ARG&gt;&gt; rsPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL PlanOrdIntegrateCancel(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="CastingPlanGen" type="L3BOOL">
	/// 
	/// �����������ּƻ������Ķ�����״̬Ϊ3���ɽ��ּƻ������ּƻ���״̬Ϊ1δ�Ų�
	/// ARG&gt;&gt; rsPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG CastingPlanGen(L3RECORDSET rsPlan);
	/// <Method class="CPlan_Mag" name="NewCastingPlanGen" type="L3LONG">
	/// 
	/// �±����������ּƻ������Ķ�����״̬Ϊ3���ɽ��ּƻ������ּƻ���״̬Ϊ1δ�Ų�
	/// ARG&gt;&gt; rsPlan :������¼��csSteelGradeIndex�����ּǺš�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// <Param name="strSteelGradeIndex" type="String"></Param>
	L3LONG NewCastingPlanGen(L3RECORDSET rsPlan,L3STRING strSteelGradeIndex);

	/// <Method class="CPlan_Mag" name="CastingPlanCancel" type="L3BOOL">
	/// 
	/// ȡ���������ּƻ������Ķ�����״̬Ϊ2
	/// ARG&gt;&gt; rsCastingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsCastingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL CastingPlanCancel(L3RECORDSET rsCastingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanGen" type="L3LONG">
	/// 
	/// ���Ƴ��ּƻ������Ķ��������ּƻ���״̬Ϊ4���Ų��������ɵĳ��ּƻ�״̬Ϊ1δ�´�
	/// ARG&gt;&gt; rsCastingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ��س�����롣
	/// <Param name="rsCastingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TappingPlanGen(L3RECORDSET rsCastingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanCancel" type="L3BOOL">
	/// 
	/// ȡ�����ּƻ������Ľ��ּƻ���״̬Ϊ1δ�Ų�����������µĽ��ּƻ�״̬ȫΪ1����Ķ�����״̬Ϊ3
	/// ARG&gt;&gt; rsTappingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL TappingPlanCancel(L3RECORDSET rsTappingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanSend" type="L3BOOL">
	/// 
	/// ���ּƻ��´���ĳ��ּƻ���״̬Ϊ2
	/// ARG&gt;&gt; rsTappingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL TappingPlanSend(L3RECORDSET rsTappingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanSndCancel" type="L3BOOL">
	/// 
	/// ���ּƻ��´�ȡ�������ĳ��ּƻ���״̬Ϊ1
	/// ARG&gt;&gt; rsTappingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL TappingPlanSndCancel(L3RECORDSET rsTappingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanDestCfm" type="L3BOOL">
	/// 
	/// ���ּƻ�ȥ��ȷ��
	/// ARG&gt;&gt; rsTappingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// &gt;&gt;strDestination��ȥ��
	/// &gt;&gt;nHotFlag�����ͱ�־
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// <Param name="strDestination" type="L3STRING"></Param>
	/// <Param name="nHotFlag" type="L3LONG"></Param>
	/// </Method>
	L3BOOL TappingPlanDestCfm(L3RECORDSET rsTappingPlan);
	/// <Method class="CPlan_Mag" name="TappingPlanExchange" type="L3LONG">
	/// 
	/// ¯������
	/// ARG&gt;&gt; PreHeatID1 : Ԥ��¯��1��
	///  &gt;&gt;PreHeatID2 : Ԥ��¯��2��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ��س�����롣
	/// <Param name="PreHeatID1" type="L3STRING">Ԥ��¯��</Param>
	/// <Param name="PreHeatID2" type="L3STRING">Ԥ��¯��</Param>
	/// </Method>
	L3LONG TappingPlanExchange(L3RECORDSET rsData);
	/// <Method class="CPlan_Mag" name="TappingPlanFirHeatDesign" type="L3BOOL">
	/// 
	/// ָ�����ε�һ¯�������µĽ����뽽����¯��
	/// ARG&gt;&gt; PreHeatID : Ԥ��¯�š�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="strPreHeatID" type="L3STRING">Ԥ��¯��</Param>
	/// </Method>
	L3BOOL TappingPlanFirHeatDesign(L3RECORDSET strPreHeatID);
	/// <Method class="CPlan_Mag" name="TappingPlanFirHeatCancel" type="L3BOOL">
	/// 
	/// ȡ�����ε�һ¯��������κš�������¯��
	/// ARG&gt;&gt; 
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </Method>
	L3BOOL TappingPlanFirHeatCancel(L3STRING strCasterID);
	/// <Method class="CPlan_Mag" name="AddHeatsToCasting" type="L3BOOL">
	/// 
	/// ���¯�ε����������
	/// ARG&gt;&gt; rsTappingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </Method>
	L3BOOL AddHeatsToCasting(L3STRING strCasterID);
	/// <Method class="CPlan_Mag" name="CalBOFIDAndReGenTappingAct" type="L3LONG">
	/// 
	/// ���·���ת¯¯���������ּƻ�ʵ��
	/// ARG&gt;&gt; 
	/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ��س�����롣
	/// </Method>
	L3LONG CalBOFIDAndReGenTappingAct();

	/// <Method class="CPlan_Mag" name="CalBOFIDAndReGenTappingAct" type="L3LONG">
	/// 
	/// ���·���ת¯¯���������ּƻ�ʵ��
	/// ARG&gt;&gt; csNewBOFFlag:��ת¯��־
	/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ��س�����롣
	/// </Method>
	L3LONG CalBOFIDAndReGenTappingAct(L3SHORT nNewBOFFlag);

	/// <Method class="CPlan_Mag" name="GetCurDayTappingPlan" type="L3RECORDSET">
	/// 
	/// ��ȡ������ּƻ���Ϣ�Լ���һ��δִ����ɼƻ�
	/// ARG &gt;&gt; strBofID: ת¯�š�
	///         &gt;&gt;strCasterID:������
	/// RET &gt;&gt; �ҵ��ļƻ���¼����
	/// <Param name="strBofID" type="String"></Param>
	/// <Param name="strCasterID" type="String"></Param>
	/// </Method>
	L3RECORDSET GetCurDayTappingPlan(L3STRING strBofID, L3STRING strCasterID);
	/// <Method class="CPlan_Mag" name="TappingPlanChangeTimeTable" type="L3LONG">
	/// 
	/// ���Ļ�ʱ�̱�
	/// ARG&gt;&gt; PreHeatID1 : Ԥ��¯�š�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ��س�����롣
	/// <Param name="PreHeatID" type="L3STRING">Ԥ��¯��</Param>
	/// </Method>
	L3LONG TappingPlanChangeTimeTable(L3RECORDSET rsData);
	/// <Method class="CPlan_Mag" name="GetCurHeatPlanInfor" type="L3RECORDSET">
	/// 
	/// ��ȡ��ǰ¯�μƻ���Ϣ
	/// ARG &gt;&gt; strPreHetaID: Ԥ��¯�š�
	/// RET &gt;&gt; �ҵ��ļƻ���¼����
	/// <Param name="strPreHeatID" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetCurHeatPlanInfor(L3STRING strPreHeatID);
	/// <Method class="CPlan_Mag" name="TappingPlanChangeRoute" type="L3LONG">
	/// 
	/// ���Ĺ���·��
	/// ARG&gt;&gt; rsData: �������ݼ���
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ��س�����롣
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TappingPlanChangeRoute(L3RECORDSET rsData);
	/// <Method class="CPlan_Mag" name="TappingPlanExchangeTreatSeq" type="L3LONG">
	/// 
	/// ������������˳���
	/// ARG&gt;&gt; PreHeatID1 : Ԥ��¯��1��
	///  &gt;&gt;PreHeatID2 : Ԥ��¯��2��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ��س�����롣
	/// <Param name="PreHeatID1" type="L3STRING">Ԥ��¯��</Param>
	/// <Param name="PreHeatID2" type="L3STRING">Ԥ��¯��</Param>
	/// </Method>
	L3LONG TappingPlanExchangeTreatSeq(L3RECORDSET rsData);

	
	/// <Method class="CPlan_Mag" name="ModifyPlanExecutionStatus" type="L3BOOL">
	/// 
	/// ���ĳ��ּƻ�״̬
	/// ARG&gt;&gt; rsPlanExecutionData : ����¯��\Ԥ��¯��\����\�����\����״̬\״̬�ı�ʱ�䡣
	/// RET &lt;&lt; ����true��
	/// <Param name="rsPlanExecutionData" type="L3RECORDSET">�ƻ�ִ������</Param>
	/// </Method>

	L3BOOL ModifyPlanExecutionStatus(L3RECORDSET rsTappingPlan);

	/// <Method class="CPlan_Mag" name="GetUnitProcessPlan" type="L3RECORDSET">
	/// 
	/// ���ĳ��ּƻ�״̬
	/// ARG&gt;&gt; nUnitType : ����
	/// ARG&gt;&gt; strUnitID : ��λ��
	/// RET &lt;&lt; ���ؼ�¼����
	/// <Param name="nUnitType" type="L3SHORT">����</Param>
	/// <Param name="strUnitID" type="L3SHORT">��λ</Param>
	/// </Method>

	L3RECORDSET GetUnitProcessPlan(L3SHORT nUnitType, L3STRING strUnitID);


	/// <Method class="CPlan_Mag" name="ModifyUnitSteelGradeIndex" type="L3LONG">
	/// 
	/// ���Ĺ���Ԥ�����ּǺ�Ԥ��¯��
	/// ARG&gt;&gt; strHeatID : ¯��1��
	/// RET &lt;&lt; �ɹ�0������롣
	/// <Param name="strHeatID1" type="L3STRING">¯��1</Param>
	/// </Method>

	L3LONG ModifyUnitSteelGradeIndex(L3STRING strHeatID);

	/// <Method class="CPlan_Mag" name="GetUnConfirmPlanOrder" type="L3RECORDSET">
	/// 
	/// ��ȡδȷ�ϼƻ�����
	/// ARG &gt;&gt; 
	/// RET &gt;&gt; �ҵ��ļƻ���¼����
	/// <Param name="Condition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetUnConfirmPlanOrder();


	private:

	/// <Method class="CPlan_Mag" name="GetSteelGradeIndexBySteelGrade" type="L3LONG">
	/// 
	/// ��ȡ���ִ������ּǺ�
	/// ARG&gt;&gt; csSteelGrade : ���֡�
	/// RET &lt;&lt; �ɹ��������ּǺš�
	/// <Param name="csSteelGrade" type="L3STRING">����</Param>
	/// </Method>
	CString  GetSteelGradeIndexBySteelGrade(CString csSteelGrade,CString csProtocol,CString csMaterialCode);

	/// <Method class="CPlan_Mag" name="CalculateHeatCount" type="L3LONG">
	/// 
	/// ����¯��
	/// ARG&gt;&gt; nBOFFlag : ת¯��־��
	/// dWeight:�ƻ���������
	/// RET &lt;&lt; �ɹ��������ּǺš�
	/// <Param name="nBOFFlag" type="L3SHORT">ת¯��־</Param>
	/// <Param name="dWeight" type="L3DOUBLE">�ƻ���������</Param>
	/// </Method>
	L3LONG  CalculateHeatCount(L3SHORT nBOFFlag,L3DOUBLE dWeight);

	/// <Method class="CPlan_Mag" name="GenCastingPlanOfSpecifyCasterID" type="L3LONG">
	/// 
	/// ����ָ�������������ּƻ�
	/// ARG&gt;&gt; csCasterID : ������
	/// rsPlanOrder:�ƻ�������Ϣ
	/// nHeatCount:¯��
	/// csSteelGradeIndex:���ּǺ�
	/// RET &lt;&lt; ���س�����롣
	/// <Param name="csCasterID" type="CSTRING">����</Param>
	/// <Param name="rsPlanOrder" type="L3RECOEDSET">�ƻ�������Ϣ</Param>
	/// <Param name="nHeatCount" type="L3LONG">¯��</Param>
	/// <Param name="csSteelGradeIndex" type="CSTRING">���ּǺ�</Param>
	/// </Method>
	L3LONG GenCastingPlanOfSpecifyCasterID(CString csCasterID,L3RECORDSET rsPlanOrder,L3LONG nHeatCount,CString csSteelGradeIndex,L3DOUBLE fWeight,L3SHORT nBOFFlag);

	/// <Method class="CPlan_Mag" name="CalculateCastingTime" type="L3LONG">
	/// ���㽽�ּƻ���������ʱ��
	/// ARG&gt;&gt; csCasterID : ������
	/// ARG&gt;&gt; csSteelGradeIndex : ���ּǺš�
	/// ARG&gt;&gt; &dtCastingTime : ����ʱ�䡣
	/// RET &lt;&lt; ���󷵻ش�����롣
	/// <Param name="csCasterID" type="CSTRING">����</Param>
	/// <Param name="csSteelGradeIndex" type="CSTRING">���ּǺ�</Param>
	/// </Method>
	L3LONG CalculateCastingTime(CString csCasterID,CString csSteelGradeIndex,L3DATETIME &dtCastingTime);

	/// <Method class="CPlan_Mag" name="CalcBOFProcessEndTime" type="L3LONG">
	/// 
	/// ����ת¯����ʱ��
	/// ARG&gt;&gt; nBOFID : ¯���š�
	/// &gt;&gt;dtBOFProcessEndTime : ����ʱ�䡣
	/// &gt;&gt;dtCurrIronPreparedTime������ʱ��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ��س�����롣
	/// <Param name="nBOFID" type="L3STRING">¯����</Param>
	/// <Param name="dtBOFProcessEndTime" type="L3DATETIME">����ʱ��</Param>
	/// <Param name="dtCurrIronPreparedTime" type="L3DATETIME">����ʱ��</Param>
	/// </Method>

	L3LONG CalcBOFProcessEndTime(CString nBOFID, L3DATETIME &dtBOFProcessEndTime,L3DATETIME dtCurrIronPreparedTime);


	/// <Method class="CPlan_Mag" name="CalcUnitOneToOneTime" type="L3LONG">
	/// 
	/// ����һ¯�Ĺ�λ���ƶ�ʱ��
	/// ARG&gt;&gt; csPreHeatID : Ԥ��¯�š�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ��س�����롣
	/// <Param name="csPreHeatID" type="L3STRING">Ԥ��¯��</Param>
	/// </Method>
	 L3LONG CPlan_Mag::CalcUnitOneToOneTime(CString csPreHeatID);


	 /// <Method class="CPlan_Mag" name="GetUnitOneToOneTime" type="L3LONG">
	 /// 
	 /// ��ȡһ¯�Ĺ�λ���ƶ�ʱ��
	 /// ARG&gt;&gt; StartUnit : ��ʼ����
	 /// ARG&gt;&gt; EndUnit : ��������
	 /// RET &lt;&lt; �ɹ������ƶ�ʱ�䡣
	 /// <Param name="StartUnit" type="L3STRING">��ʼ����</Param>
	 /// <Param name="EndUnit" type="L3STRING">��������</Param>
	 /// </Method>
	 L3DATETIME GetUnitOneToOneTime(CString StartUnit,CString EndUnit);


	 /// <Method class="CPlan_Mag" name="GetHeatMaxProcessNo" type="L3LONG">
	 /// 
	 /// �õ�����λ������
	 /// ARG&gt;&gt; nUnitType : ����
	 /// ARG&gt;&gt; csUnitID : ��λ��
	 /// RET &lt;&lt; ���������š�
	 /// <Param name="nUnitType" type="L3SHORT">����</Param>
	 /// <Param name="csUnitID" type="L3STRING">��λ</Param>
	 /// </Method>
	 L3LONG GetHeatMaxProcessNo(L3SHORT nUnitType, CString csUnitID);


	 /// <Method class="CPlan_Mag" name="TappingPlanFirHeatDesign" type="L3BOOL">
	/// 
	/// �����µĽ����뽽����¯��
	/// ARG&gt;&gt; PreHeatID : Ԥ��¯�š�
	/// RET &lt;&lt; �ɹ�����0��ʧ�ܷ��ش������
	/// <Param name="strPreHeatID" type="L3STRING">Ԥ��¯��</Param>
	/// </Method>

	L3LONG	CaculateNewCastingNoAndHeats(CString csPresetHeatID);


	/// <Method class="CPlan_Mag" name="CalcUnitStdProcessTime" type="L3LONG">
	/// 
	/// ����һ¯����λ��׼����ʱ��
	/// ARG&gt;&gt; PreHeatID1 : Ԥ��¯�š�
	/// RET &lt;&lt; �ɹ�����0��ʧ�ܷ��س�����롣
	/// <Param name="PreHeatID" type="L3STRING">Ԥ��¯��</Param>
	/// </Method>
	L3LONG CalcUnitStdProcessTime(CString csPreHeatID);



	/// <Method class="CPlan_Mag" name="StoreLadlePlanBeforeExBOF" type="L3RECORDSET">
	/// 
	/// ��¼�ְ��ƻ�
	/// ARG&gt;&gt; strHeatID : ¯��1��
	/// RET &lt;&lt; �ɹ�0������롣
	/// <Param name="strHeatID1" type="L3STRING">¯��1</Param>
	/// </Method>
	L3RECORDSET StoreLadlePlanBeforeExBOF (CString strPresetHeatID);

	
	/// <Method class="CPlan_Mag" name="StoreLadlePlanBeforeExBOF" type="L3RECORDSET">
	/// 
	/// ¯�������󣬸��ݼƻ�״̬ȷ���ְ��ƻ��Ƿ������´�
	/// ARG&gt;&gt; strHeatID : ¯��1��
	/// RET &lt;&lt; �ɹ�0������롣
	/// <Param name="strHeatID1" type="L3STRING">¯��1</Param>
	/// </Method>
	L3LONG ReDownLoadLadlePlan(CString csPreHeatID,L3RECORDSET rsLadlePlan);


	//�쿴��ǰ¯����һ¯�ε�״̬
	CString GetSomeHeatStatus(CString csHeatID,L3SHORT nLastFlag);


	/// <Method class="CPlan_Mag" name="TappingPlanSndCancel" type="L3BOOL">
	/// 
	/// ��¼ת¯����ҵʱ��
	/// ARG&gt;&gt; rsTappingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LogBOFNunProcessTime(L3RECORDSET rsData);


	/// <Method class="CPlan_Mag" name="TappingPlanSndCancel" type="L3BOOL">
	/// 
	/// �޸ĳ��ּƻ��ƻ�ʱ����Ϣ
	/// ARG&gt;&gt; rsTappingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL ModifyTappingPlanTimeInfor(L3RECORDSET rsData);

	void ChangeRsTappingPlanValue(void);


	/// <Method class="CDispatch_Mag" name="AddSteelToCache" type="L3LONG">
	/// 
	/// ����ˮ�ӻ�������ȥ
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID��¯��
	/// RET &lt;&lt;����0
	/// </Method>

	L3LONG MoveSteelFromCache(CString csCacheID,CString csHeatID);

	/// <Method class="CDispatch_Mag" name="AddSteelToCache" type="L3LONG">
	/// 
	/// ����ˮ��ӵ�����
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID��¯��
	/// RET &lt;&lt;����0
	/// </Method>
	L3LONG AddSteelToCache(CString csCacheID,CString csHeatID);


	/// <Method class="CDispatch_Mag" name="GetCurSteelCache" type="DATASET">
	/// 
	/// ��ȡ��ˮ��ǰ���ڻ���URi
	/// ARG csHeatID��¯��
	/// RET &gt;&gt; �ҵ���URi
	/// </Method>
	CString GetCurSteelCache(CString csHeatID);


	/// <Method class="CDispatch_Mag" name="MoveSteelWhenSideExchangePlan" type="L3LONG">
	/// 
	/// ��¯���򽻻��ƻ�ʱ��ˮ�ƶ�
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID��¯��
	/// RET &lt;&lt;����0
	/// </Method>

	L3LONG MoveSteelWhenSideExchangePlan(CString cstrURI1,CString cstrURI2);


	/// <Method class="CDispatch_Mag" name="MoveSteelWhenRefineExchangePlan" type="L3LONG">
	/// 
	/// ��RH���򽻻��ƻ�ʱ��ˮ�ƶ�
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID��¯��
	/// RET &lt;&lt;����0
	/// </Method>

	L3LONG MoveSteelWhenRHExPlan(CString cstrURI1,CString cstrURI2);

	/// <Method class="CDispatch_Mag" name="MoveSteelWhenRefineExchangePlan" type="L3LONG">
	/// 
	/// ��LF���򽻻��ƻ�ʱ��ˮ�ƶ�
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID��¯��
	/// RET &lt;&lt;����0
	/// </Method>

	L3LONG MoveSteelWhenLFExPlan(CString cstrURI1,CString cstrURI2);


	/// <Method class="CDispatch_Mag" name="MoveSteelWhenBOFExPlan" type="L3LONG">
	/// 
	/// ��ת¯���򽻻��ƻ�ʱ��ˮ�ƶ�
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID��¯��
	/// RET &lt;&lt;����0
	/// </Method>

	L3LONG MoveSteelWhenBOFExPlan(CString cstrURI1,CString cstrURI2);


	/// <Method class="CDispatch_Mag" name="MoveSteelWhenRefineExchangePlan" type="L3LONG">
	/// 
	/// ���������ʱ�����ƻ�ʱ��ˮ�ƶ�
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID��¯��
	/// RET &lt;&lt;����0
	/// </Method>

	L3LONG MoveSteelWhenCasterExPlan(CString cstrURI1,CString cstrURI2);


	/// <Method class="CPlan_Mag" name="TappingPlanEnd" type="L3BOOL">
	/// 
	/// ���ּƻ�ǿ�ƽ���
	/// ARG&gt;&gt; rsTappingPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTappingPlan" type="L3RECORDSET"></Param>
	/// <Param name="strDestination" type="L3STRING"></Param>
	/// <Param name="nHotFlag" type="L3LONG"></Param>
	/// </Method>
	L3BOOL TappingPlanEnd(L3RECORDSET rsTappingPlan);


	// <Method class="CPlan_Mag" name="ModifyLadleAllInfor" type="L3BOOL">
	/// �޸ĸְ���Ӧ��Ϣ
	/// </Method>

	L3BOOL ModifyLadleAllInfor(CString csUnitID,CString csHeatID,CString csPreHeatID);


	/// <Method class="CPlan_Mag" name="PlanOrdCfm" type="L3BOOL">
	/// 
	/// ɾ���ƻ�����
	/// <Param name="rsPlan" type="L3RECORDSET">�ƻ�������Ϣ</Param>
	/// </Method>
	L3BOOL DelPlanOrder(L3RECORDSET rsPlan);


	/// <Method class="CPlan_Mag" name="PlanOrdRec" type="L3BOOL">
	/// 
	/// ���ռƻ��������жϼƻ�������״̬�������2���˳��������ƻ�����״̬Ϊ0δȷ��
	/// ARG&gt;&gt; rsPlan : �ƻ����ݡ��������PlanID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPlan" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL PlanOrdRecFormNC(L3RECORDSET rsPlan);


	/// <Method class="CPlan_Mag" name="PlanOrdCfm" type="L3BOOL">
	/// 
	/// �رռƻ�����2009-04-19 tangyi
	/// <Param name="rsPlan" type="L3RECORDSET">�ƻ�������Ϣ</Param>
	/// </Method>
	L3BOOL EndPlanOrder(L3RECORDSET rsPlan);
};

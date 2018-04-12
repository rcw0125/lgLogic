// �߼���CPlan_MagԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CPlan_Mag.h"

IMPLEMENT_L3CLASS(CPlan_Mag,PlanDept,1)

BEGIN_L3PROPTABLE(CPlan_Mag,PlanDept)
	L3PROP_LONG(PlanOrderEvent)               //�ƻ�����״̬�仯�¼�
	L3PROP_LONG(TappingPlanEvent)               //���ּƻ�״̬�仯�¼�
	L3PROP_LONG(TappingPlanGenerateEvent)      //���ּƻ������¼�
	L3PROP_LONG(EquipmentStatusChange)			//�豸״̬�ı�
	L3PROP_LONG(WriteFlag)	
	L3PROP_LONG(BOFChangeFlag)		        //����¯����ʼ��־ 
	L3PROP_LONG(TappingModelFlag)			//����ģ�ͽ�����־
	L3PROP_LONG(PlanExeFlag)				//�ƻ��´��־ 0,1 1:��ʼִ�У�0��ִ�����
	L3PROP_LONG(PlanCancelFlag)			//�ƻ�ȡ����־ 0,1 1:��ʼִ�У�0��ִ�����
	L3PROP_LONG(IronPlanExeFlag)			//��ˮ�ƻ��´��־ 0,1 1:��ʼִ�У�0��ִ�����
	L3PROP_LONG(TappingPlanFlag)			//���ּƻ���־ 0,1 1:��ʼִ�У�0��ִ�����
	L3PROP_LONG(BOFYieldFlag)			    //����ת¯���� 0,1 1:��ʼִ�У�0��ִ�����
	L3PROP_LONG(AddNewBOFFlag)			    //������¯�� 0,1 1:��ʼִ�У�0��ִ�����
	L3PROP_LONG(FirstCastingHeatFlag)		//ָ�����ε�һ¯ 0,1 1:��ʼִ�У�0��ִ�����
	L3PROP_LONG(ReFirstCastingHeatFlag)	//����ָ�����ε�һ¯ 0,1 1:��ʼִ�У�0��ִ�����
	L3PROP_LONG(ModifyPlanFlag)			//�޸� 0,1 1:��ʼִ�У�0��ִ�����
	L3PROP_LONG(PlanDelFlag)				//�ƻ�ȡ����־ 0,1 1:��ʼִ�У�0��ִ�����
END_L3PROPTABLE(CPlan_Mag)

BEGIN_L3METHODMAP(CPlan_Mag,PlanDept)
	L3_METHOD(CPlan_Mag,"PlanOrdRec",0,PlanOrdRec,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"PlanOrdRecFormNC",0,PlanOrdRecFormNC,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"PlanOrdCfm",0,PlanOrdCfm,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"GetUnIntegratePlanOrd",0,GetUnIntegratePlanOrd,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"GetCastingPlan",0,GetCastingPlan,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"GetIntegratedPlanOrd",0,GetIntegratedPlanOrd,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"PlanOrdIntegrateCfm",0,PlanOrdIntegrateCfm,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"PlanOrdIntegrateCancel",0,PlanOrdIntegrateCancel,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"CastingPlanGen",0,CastingPlanGen,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"NewCastingPlanGen",0,NewCastingPlanGen,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"CastingPlanCancel",0,CastingPlanCancel,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanGen",0,TappingPlanGen,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanCancel",0,TappingPlanCancel,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanSend",0,TappingPlanSend,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanSndCancel",0,TappingPlanSndCancel,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanDestCfm",0,TappingPlanDestCfm,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanExchange",0,TappingPlanExchange,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanFirHeatDesign",0,TappingPlanFirHeatDesign,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanFirHeatCancel",0,TappingPlanFirHeatCancel,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"AddHeatsToCasting",0,AddHeatsToCasting,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"GetCurDayTappingPlan",0,GetCurDayTappingPlan,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"TappingPlanChangeTimeTable",0,TappingPlanChangeTimeTable,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"GetCurHeatPlanInfor",0,GetCurHeatPlanInfor,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"TappingPlanChangeRoute",0,TappingPlanChangeRoute,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"TappingPlanExchangeTreatSeq",0,TappingPlanExchangeTreatSeq,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"ModifyPlanExecutionStatus",0,ModifyPlanExecutionStatus,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"GetUnitProcessPlan",0,GetUnitProcessPlan,L3VT_RECORDSET,L3VTS_SHORT L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"GetUnConfirmPlanOrder",0,GetUnConfirmPlanOrder,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CPlan_Mag,"LogBOFNunProcessTime",0,LogBOFNunProcessTime,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"ModifyTappingPlanTimeInfor",0,ModifyTappingPlanTimeInfor,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"ChangeRsTappingPlanValue",0,ChangeRsTappingPlanValue,L3VT_VOID,L3VTS_NONE)
	L3_METHOD(CPlan_Mag,"TappingPlanEnd",0,TappingPlanEnd,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"ModifyUnitSteelGradeIndex",0,ModifyUnitSteelGradeIndex,L3VT_LONG,L3VTS_STRING)
	L3_METHOD(CPlan_Mag,"DelPlanOrder",0,DelPlanOrder,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CPlan_Mag,"EndPlanOrder",0,EndPlanOrder,L3VT_BOOL,L3VTS_RECORDSET)

	
	
	
	
	
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Mag,PlanDept)
END_L3EVENTSINK_MAP(CPlan_Mag)

CPlan_Mag::CPlan_Mag(void)
{
}

CPlan_Mag::~CPlan_Mag(void)
{
}

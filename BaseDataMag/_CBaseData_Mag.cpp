// �߼���BaseData_MagԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBaseData_Mag.h"

IMPLEMENT_L3CLASS(CBaseData_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CBaseData_Mag,CL3Object)
	L3PROP_LONG(NC_Plan_Event)////2009-02-21
	L3PROP_LONG(NC_Heat_Confirm_Event)////2009-02-22 tangyi
	L3PROP_LONG(NC_Iron_Event)////2009-03-15 liuzhiqng
	L3PROP_LONG(NC_Steel_Back_Event)////2009-03-22 tangyi
	L3PROP_LONG(NC_Store_Change_Event)////2009-03-31 tangyi
END_L3PROPTABLE(CBaseData_Mag)

BEGIN_L3METHODMAP(CBaseData_Mag,CL3Object)
	L3_METHOD(CBaseData_Mag,"ReceiveBaseData",0,ReceiveBaseData,L3VT_BOOL,L3VTS_NONE)
	L3_METHOD(CBaseData_Mag,"GetCodeAndDes",0,GetCodeAndDes,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CBaseData_Mag,"GetSysCurDate",0,GetSysCurDate,L3VT_STRING,L3VTS_NONE)
	L3_METHOD(CBaseData_Mag,"WriteLogFromNC",0,WriteLogFromNC,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBaseData_Mag,"ReceiveSteelmaterialInforFromNC",0,ReceiveSteelmaterialInforFromNC,L3VT_BOOL,L3VTS_RECORDSET)

	//2009-03-26 liuzhiqiang
	L3_METHOD(CBaseData_Mag,"SendPlanInfor",0,SendPlanInfor,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CBaseData_Mag,"SendAddMaterialsInfor",0,SendAddMaterialsInfor,L3VT_RECORDSET,L3VTS_STRING L3VTS_PRECORDSET)
	L3_METHOD(CBaseData_Mag,"SendBloomInfor",0,SendBloomInfor,L3VT_RECORDSET,L3VTS_STRING L3VTS_PRECORDSET)
	L3_METHOD(CBaseData_Mag,"SendQualityJudgeInfor",0,SendQualityJudgeInfor,L3VT_RECORDSET,L3VTS_STRING L3VTS_PRECORDSET L3VTS_PRECORDSET L3VTS_STRING)
	L3_METHOD(CBaseData_Mag,"SendBloomInStoreInfor",0,SendBloomInStoreInfor,L3VT_RECORDSET,L3VTS_STRING L3VTS_PRECORDSET)
	L3_METHOD(CBaseData_Mag,"SendIronBloomInfor",0,SendIronBloomInfor,L3VT_RECORDSET,L3VTS_STRING L3VTS_PRECORDSET)
	L3_METHOD(CBaseData_Mag,"SendIronQualityJudgeInfor",0,SendIronQualityJudgeInfor,L3VT_RECORDSET,L3VTS_STRING L3VTS_PRECORDSET L3VTS_PRECORDSET)
	L3_METHOD(CBaseData_Mag,"SendIronBloomInStoreInfor",0,SendIronBloomInStoreInfor,L3VT_RECORDSET,L3VTS_STRING L3VTS_PRECORDSET)
	L3_METHOD(CBaseData_Mag,"GetMaterialBatchID",0,GetMaterialBatchID,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CBaseData_Mag,"GetPlanOrder",0,GetPlanOrder,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBaseData_Mag,"ConfirmPlanOrder",0,ConfirmPlanOrder,L3VT_BOOL,L3VTS_RECORDSET)

	L3_METHOD(CBaseData_Mag,"GetInStore",0,GetInStore,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBaseData_Mag,"ConfirmInStore",0,ConfirmInStore,L3VT_BOOL,L3VTS_RECORDSET)

	L3_METHOD(CBaseData_Mag,"GetIron",0,GetIron,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBaseData_Mag,"ConfirmIron",0,ConfirmIron,L3VT_BOOL,L3VTS_RECORDSET)

	L3_METHOD(CBaseData_Mag,"GetAllReturn",0,GetAllReturn,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBaseData_Mag,"ConfirmAllReturn",0,ConfirmAllReturn,L3VT_BOOL,L3VTS_RECORDSET)


	L3_METHOD(CBaseData_Mag,"GetInStoreQuality",0,GetInStoreQuality,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBaseData_Mag,"ConfirmInStoreQuality",0,ConfirmInStoreQuality,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBaseData_Mag,"TestOracleProcess",0,TestOracleProcess,L3VT_BOOL,L3VTS_STRING)

	L3_METHOD(CBaseData_Mag,"Add_Mat_Price",0,Add_Mat_Price,L3VT_LONG,L3VTS_RECORDSET)	//2009-04-17 Liao
	L3_METHOD(CBaseData_Mag,"Modify_Mat_Price",0,Modify_Mat_Price,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBaseData_Mag,"Delete_Mat_Price",0,Delete_Mat_Price,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBaseData_Mag,"Get_Materia_Price",0,Get_Materia_Price,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CBaseData_Mag,"InsertBaseParameter",0,InsertBaseParameter,L3VT_LONG,L3VTS_STRING L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBaseData_Mag,CL3Object)
END_L3EVENTSINK_MAP(CBaseData_Mag)

//Ȩ�޹���
BEGIN_L3ACCESSCONTROL_MAP(CBaseData_Mag,CL3Object)
	

	L3RIGHT(ProcessDataMag,"���̼��")//2009-03-25

	//��������ά��
	L3RIGHT(TeamShiftMaint,"��ΰ��ά��")
	L3RIGHT(MaterialFacMaint,"�����߲��ϳ���ά��")
	L3RIGHT(MESCodeQuery,"MESϵͳ�����ѯ")
	L3RIGHT(FeedWireRelationMaint,"ι˿PLC��ַ��ι˿�����ϵά��")

	L3RIGHT(BtnMaterialFacMaint,"�����߲��ϳ���ά����ť")//2009-03-26
	L3RIGHT(IronLadleDataManageFrm,"���޵�������")//2009-04-15

	L3RIGHT(MaterialPriceMagFrm,"���ϼ۸�����")//2009-04-17

	L3RIGHT(ENMediumMagFrm,"��Դ�������Թ���")//2009-03-27
	L3RIGHT(ENMediumMagBtnMod,"��Դ���������޸�")//2009-03-27

	L3RIGHT(WireCoefficientFrm,"ι�����ع���")//2009-04-30
	L3RIGHT(btnWireCoefficient,"ι�����ذ�ť")//2009-04-30

	L3RIGHT(CostMediumMagFrm,"�������Ķ������")//2009-08-10
	L3RIGHT(CostStandardRateMagFrm,"��׼���ʹ���")//2009-08-10

	L3RIGHT(UnitPriceMagFrm,"�Ͻ�ƻ����۹���")//2009-08-25
	L3RIGHT(UnitConsumeMagFrm,"�Ͻ�ƻ����Ĺ���")//2009-08-25
	L3RIGHT(CSteelBulkConsumeRateMagFrm,"������ɢװ��ָ�굥�Ĺ���")//2009-09-07

	//����ʵ���޸�����Ȩ��
	L3RIGHT(CheckBoxBOFInfo,"ת¯ʵ�������߼�Ȩ��")//2009-04-02
	L3RIGHT(CheckBoxLFInfo,"LR¯ʵ�������߼�Ȩ��")//2009-04-02
	L3RIGHT(CheckBoxRHInfo,"RH¯ʵ�������߼�Ȩ��")//2009-04-02
	L3RIGHT(CheckBoxCCMInfo,"����ʵ�������߼�Ȩ��")//2009-04-02

	//[2009-03-03]
	L3RIGHT(btnBaseAllCode,"MESϵͳ����ά��")
	//[2009-03-16]
	L3RIGHT(OperatorMaint,"Ա������ά��")

	//�ƻ�
	L3RIGHT(PlanOrderWriteIn,"�ƻ�����¼��")
	L3RIGHT(CastingPlan,"�������ּƻ��Ų�")
	L3RIGHT(TappingPlan,"���ּƻ��Ų�")
	L3RIGHT(TappingPlanMain,"���ּƻ�����")
	L3RIGHT(TappingPlanQuery,"���ּƻ���ѯ")
	L3RIGHT(BloomPlanQueryFrm,"�����ƻ�����ִ�������ѯ")//[2009-04-07]
	

	//��ťȨ��
	L3RIGHT(BtnCancelTappingPlan,"ȡ�����ּƻ�")
	L3RIGHT(BtnTappingPlanSend,"���ּƻ��´�")
	L3RIGHT(BtnTappingPlanSendCancel,"���ּƻ��´�ȡ��")
	L3RIGHT(BtnTappingPlanExchange,"¯������")
	L3RIGHT(BtnExchangeProcessSeq,"������������˳��")
	L3RIGHT(BtnModTappingPlan,"���ּƻ��޸�")
	L3RIGHT(BtnChengeRoute,"���Ĺ���·��")
	L3RIGHT(BtnDispathAccountMag,"����̨�ʹ���")//2009-03-16
	L3RIGHT(BtnCastingPlanGen,"�������ּƻ��Ų���ť")//2009-03-26


	//����
	L3RIGHT(ExceptionProcess,"�����쳣����")
	L3RIGHT(ProcessTrack,"���̼���")
	L3RIGHT(DispathLog,"���ȼ��²�ѯ")
	L3RIGHT(SteelBackQuery,"��ˮ���������ѯ")
	L3RIGHT(SteelTurnQuery,"��ˮȫ��¯��ѯ")
	L3RIGHT(SteelExchangeQuery,"�ĸ������ѯ")

	L3RIGHT(BtnDispathLog,"���ȼ��¹���ť")//2009-03-26
	L3RIGHT(DispatchMap,"����������ʱ״̬")//2009-04-07
	L3RIGHT(DispExceptionalFrm,"�豸�쳣�������")//2009-04-15
	L3RIGHT(btnDispExceptional,"�豸�쳣����ť")//2009-04-15

	//��Դ����
	L3RIGHT(EnergyMain,"��Դ���ӻ���")

	//���򵯳��˵�[2009-03-13]
	L3RIGHT(menuBOF,"�����˵�ת¯")
	L3RIGHT(menuLF,"�����˵�LF")
	L3RIGHT(menuRH,"�����˵�RH")
	L3RIGHT(menuSide,"�����˵�¯��")
	L3RIGHT(menuCCM,"�����˵�����")
	//������ˮ
	L3RIGHT(IronIntegrateMag,"��ˮ�ռ�����")
	L3RIGHT(IronDestinationMag,"��ˮȥ�����")
	L3RIGHT(IronInforQueryMag,"��ˮ��Ϣ��ѯ")
	
	//2009-03-31 
	L3RIGHT(btnBFSample,"������ί�е�")
	L3RIGHT(btnDisSSample,"����ί�е�")
	//200904-08
	L3RIGHT(btnDelBFIron,"��ˮ--ɾ����ˮ��Ϣ")
	L3RIGHT(menuSouresHF,"��ˮ--ָ��Ϊ��¯��ˮ")
	L3RIGHT(menuSoureS,"��ˮ--ָ��Ϊ����վ��ˮ")
	L3RIGHT(menuGross,"��ˮ--�趨ë��")
	L3RIGHT(menuTare,"��ˮ--�趨Ƥ��")
	L3RIGHT(menuToIron,"��--ˮȥ����")
	L3RIGHT(menuToNC,"��ˮ--�ϴ�NC")
	

	//�������¯
	L3RIGHT(MixFurnaceMag,"����¯����")
	L3RIGHT(btnMixFurnaceMag,"����¯����ť")
	L3RIGHT(MixFurnaceDataQuery,"����¯�������ݲ�ѯ")
	L3RIGHT(MixTappedBtn,"����¯���������ť")//2009-08-10
	//�������� 2009-10-29 sun
	L3RIGHT(DeSIMag,"I�����������")
	L3RIGHT(DeSIIMag,"II�����������")
	L3RIGHT(DeSPorcessDataQuery,"����ʵ����ѯ")
	L3RIGHT(DeSAdditionMag,"�������ά��")
	L3RIGHT(DeSSideDuty,"����������ά��")
	L3RIGHT(DeSStatusQuery,"�����豸״̬��ѯ")
	L3RIGHT(DeSLanceMagFrm,"������ǹ����")

	//��ťȨ��
	L3RIGHT(btnPrepare,"����׼������")
	L3RIGHT(btnConfirm1,"��������ȷ��")
	L3RIGHT(btnUndoDes1,"������ȷ��")
	L3RIGHT(btnironArrived1,"�������޽�վ")
	L3RIGHT(btnDesignateDeSUnitID1,"����ָ����λ")
	L3RIGHT(btnBeginPreRemoveSlag1,"����Ԥ������ʼ")
	L3RIGHT(btnEndPreRemoveSlag1,"����Ԥ��������")
	L3RIGHT(btnStartBlowing1,"�����紵��ʼ")
	L3RIGHT(btnStopBlowing1,"�����紵����")
	L3RIGHT(btnBeginRemoveSlag1,"����������ʼ")
	L3RIGHT(btnEndRemoveSlag1,"������������")
	L3RIGHT(btnIronsDeparture1,"����ָ��ȥ��")
	L3RIGHT(btnDeSType1,"������������")
	L3RIGHT(btnDeSIronSheet1,"�����ƶ�ί�е�")
	L3RIGHT(btnChangeLance1,"����ǹ")
	L3RIGHT(btnChangeTreatNo1,"�����紵���޸�")
	L3RIGHT(btnEquipmentStatus1,"�����豸״̬ά��")
	L3RIGHT(btnMatSet1,"������������볧���趨")
	L3RIGHT(btnRemoveSlagCount,"������������")
	L3RIGHT(btnLanceQuery,"������ǹ��ѯ")
	L3RIGHT(btnOut,"�������޳�վ")

L3RIGHT(btnDeSProcessConfirm,"����ʵ��ȷ��")
L3RIGHT(cxDeSCheckFlag,"��������ά��")
L3RIGHT(btnDeSPorcessDataQuery,"����ʵ����ѯ��ť")

L3RIGHT(btnDeSAdditionAdd,"�������ά��������ť")
L3RIGHT(btnDeSAdditionConfirm,"�������ά��ȷ�ϰ�ť")
L3RIGHT(btnDeSAdditionCancel,"�������ά��ȡ����ť")

L3RIGHT(btnDeSDutyConfirm,"����������ά��ȷ����ť")

L3RIGHT(btnDeSLanceAdd,"������ǹ������ť")
L3RIGHT(btnDeSLanceChangeStatus,"������ǹ�޸�״̬��ť")
L3RIGHT(btnDeSLanceChangeAge,"������ǹ�޸�ǹ�䰴ť")
L3RIGHT(btnDeSLanceConfirm,"������ǹȷ����ť")
L3RIGHT(btnDeSLanceCancel,"������ǹȡ����ť")

	//����ת¯
	L3RIGHT(BOF1Mag,"1#ת¯����")
	L3RIGHT(BOF2Mag,"2#ת¯����")	
	L3RIGHT(BOF3Mag,"3#ת¯����")	
	L3RIGHT(BOF4Mag,"4#ת¯����")	
	L3RIGHT(BOFProcessDataQuery,"ת¯ʵ����ѯ")
	L3RIGHT(BOFDuty,"ת¯������ά��")	
	//����¯��
	L3RIGHT(BOFSide1Mag,"1#ת¯¯����")
	L3RIGHT(BOFSide2Mag,"2#ת¯¯����")	
	L3RIGHT(BOFSide3Mag,"3#ת¯¯����")	
	L3RIGHT(BOFSide4Mag,"4#ת¯¯����")	
	L3RIGHT(BOFSideProcessDataQuery,"ת¯¯��ʵ����ѯ")	
	L3RIGHT(BOFSideDuty,"ת¯¯��������ά��")	
	//����LF
	L3RIGHT(LF1Mag,"1#LF¯����")
	L3RIGHT(LF2Mag,"2#LF¯����")	
	L3RIGHT(LF3Mag,"3#LF¯����")	
	L3RIGHT(LFProcessDataQuery,"LF¯ʵ����ѯ")	
	L3RIGHT(LFDuty,"LF������ά��")	
	//����RH
	L3RIGHT(RH1Mag,"1#RH¯����")
	L3RIGHT(RHProcessDataQuery,"RH¯ʵ����ѯ")	
	L3RIGHT(RHDuty,"RH������ά��")
	//��������
	L3RIGHT(CCM1Mag,"1#��������")
	L3RIGHT(CCM2Mag,"2#��������")
	L3RIGHT(CCM3Mag,"3#��������")
	L3RIGHT(CCM4Mag,"4#��������")
	L3RIGHT(CCM5Mag,"5#��������")
	L3RIGHT(CCMMarkScrap,"��������˦��")
	L3RIGHT(CCMScrapDuty,"����˦������ȷ��")
	L3RIGHT(CCMMakeProduct,"��������")
	L3RIGHT(CCMSideMag,"����̨��")
	L3RIGHT(CCMProcessDataQuery,"����ʵ����ѯ")	
	L3RIGHT(CCMDuty,"����������ά��")
	L3RIGHT(CCMSamplebtnComfirm,"ȷ��ȡ��")
	//2009-04-07
	L3RIGHT(CCMScrapDutyFrm,"¯��˦������ָ��")
	L3RIGHT(CCMRefraQueryFrm,"�����Ͳ�ʹ��ʵ����ѯ")
	L3RIGHT(EquipmentStatusQueryFrm,"�豸״̬�仯��ѯ")

	//����ʵ������������ť
	L3RIGHT(BOFbtnConfirm,"ת¯ʵ��ȷ��")
	L3RIGHT(BOFCheck,"ת¯ʵ����������")
	L3RIGHT(SidebtnConfirm,"ת¯¯��ʵ��ȷ��")
	L3RIGHT(SideCheck,"ת¯¯��ʵ����������")
	L3RIGHT(LFbtnConfirm,"LF¯ʵ��ȷ��")
	L3RIGHT(LFCheck,"LF¯ʵ����������")
	L3RIGHT(RHbtnConfirm,"RH¯ʵ��ȷ��")
	L3RIGHT(RHCheck,"RH¯ʵ����������")
	L3RIGHT(CCMbtnConfirm,"����ʵ��ȷ��")
	L3RIGHT(CCMCheck,"����ʵ����������")


	//�����
	L3RIGHT(ScrapStoreMag,"�ϸ�����ԭ�Ͽ����")
	L3RIGHT(ScrapStoreInStoreQuery,"�ϸ���������ѯ")
	L3RIGHT(ScrapStoreOutStoreQuery,"�ϸ����������ѯ")
	L3RIGHT(ScrapStoreModQuery,"�ϸ������̿��ѯ")

	//2009-03-16
	L3RIGHT(BtnScrapInStore,"�ϸ����")
	L3RIGHT(BtnScrapOutStore,"�ϸֳ���")
	L3RIGHT(BtnScrapOutStoreCanel,"�ϸֳ�������")
	L3RIGHT(BtnScrapBanlance,"�ϸ��̿�")
	L3RIGHT(BtnScrapExl,"�ϸ�Exl����")


	L3RIGHT(AlloyStoreMag,"ת¯�Ͻ�ԭ�Ͽ����")//2009-04-04
	L3RIGHT(AlloyStoreInStoreQuery,"�Ͻ�ԭ����ѯ")
	L3RIGHT(AlloyStoreOutStoreQuery,"�Ͻ�ԭ�����ѯ")
	L3RIGHT(AlloyStoreTransQuery,"�Ͻ�ת���ѯ")
	L3RIGHT(AlloyStoreModQuery,"�Ͻ��̿��ѯ")
	L3RIGHT(AlloyStoreBulkRelation,"ת¯�Ͻ��ϲ�����ά��")//2009-04-04

	L3RIGHT(AlloyStoreQueryFrm,"�Ͻ����ѯ")//2009-04-08

	//2009-03-16
	L3RIGHT(BtnAlloyInstore,"�Ͻ�����")
	L3RIGHT(BtnAlloyExl,"�Ͻ�Exl����")

	//2009-04-04
	L3RIGHT(AlloyStoreLFMag,"1��2#LF�Ͻ�ԭ�Ͽ����")
	L3RIGHT(AlloyStoreRHMag,"3#LF��RH�Ͻ�ԭ�Ͽ����")
	L3RIGHT(AlloyAndAreaLFMapFrm,"1��2#LF�Ͻ��ϲ�����ά��")
	L3RIGHT(AlloyAndAreaRHMapFrm,"3#LF��RH�Ͻ��ϲ�����ά��")

	L3RIGHT(BulkStoreMag,"ɢ״��ԭ�Ͽ����")
	L3RIGHT(BulkStoreInStoreQuery,"ɢ״������ѯ")
	L3RIGHT(BulkStoreOutStoreQuery,"ɢ״�ϳ����ѯ")
	L3RIGHT(BulkStoreTransQuery,"ɢ״��ת���ѯ")
	L3RIGHT(BulkStoreModQuery,"ɢ״���̿��ѯ")
	L3RIGHT(BulkStoreBulkRelation,"ɢ״���ϲ�����ά��")

	//2009-03-16
	L3RIGHT(BtnBulkInstore,"ɢ״������")
	L3RIGHT(BtnBulkExl,"ɢ״��Exl����")

	L3RIGHT(BloomStoreMag,"���������")
	L3RIGHT(BloomStoreInStoreQuery,"����������ѯ")
	L3RIGHT(BloomStoreOutStoreQuery,"����������ѯ")
	L3RIGHT(BloomStoreTransQuery,"������ת���ѯ")
	L3RIGHT(BloomStoreOnStoreQuery,"���������ѯ")
	//�ڿ��������ť
	L3RIGHT(BloomStorebtnInStore,"���")
	L3RIGHT(BloomStorebtnQualityCheck,"���")
	L3RIGHT(BloomStorebtnSpileChange,"��λ���")
	L3RIGHT(BloomStorebtnOutStore,"����")

	//�����������
	L3RIGHT(HotJudge,"�ȼ������ж�")
	L3RIGHT(FinalJudge,"����")
	L3RIGHT(FinalJudgeQuery,"���в�ѯ")
	L3RIGHT(HotJudgeQuery,"�ȼ������ж���ѯ")
	L3RIGHT(DesStd,"���������׼����")
	L3RIGHT(BOFStd,"ת¯�����׼ά��")
	L3RIGHT(LFStd,"LF�����׼ά��")
	L3RIGHT(RHStd,"RH�����׼ά��")	
	L3RIGHT(CCMStd,"���������׼ά��")
	L3RIGHT(BOFInControlEle,"ת¯�ڿظֳɷֹ���")
	L3RIGHT(LFInControlEle,"LF¯�ڿظֳɷֹ���")
	L3RIGHT(RHInControlEle,"RH�ڿظֳɷֹ���")
	L3RIGHT(CCMProcessStd,"�����Ƴ̱�׼ά��")
	L3RIGHT(ProdSheet,"���տ�����")
	L3RIGHT(UnitPoecessTimeStd,"��������ҵʱ���׼ά��")
	L3RIGHT(TransTimeStd,"���������ʱ���׼ά��")
	L3RIGHT(RoutMaint,"����·��ά��")
	L3RIGHT(SteeGradeIndexMap,"���ּǺŸ��ֶ��չ�ϵά��")
	L3RIGHT(SteeGradeChangeMap,"���ָĸֶ��չ�ϵά��")
	L3RIGHT(BloomSpileStd,"�����϶��־ά��")
	//��ťȨ��
	L3RIGHT(BtnAddSteeGradeIndexMap,"�������ּǺŸ��ֶ��չ�ϵά��")
	L3RIGHT(BtnDelSteeGradeIndexMap,"ɾ�����ּǺŸ��ֶ��չ�ϵά��")
	L3RIGHT(BtnConfirmSteeGradeIndexMap,"ȷ�����ּǺŸ��ֶ��չ�ϵά��")

	L3RIGHT(DecideCode,"���ô���ά��")
	L3RIGHT(ExceptionGroup,"�쳣�������ά��")
	L3RIGHT(ExceptionCode,"�쳣����ά��")
	L3RIGHT(WeightStd,"�����������ȹ�ϵά��")
	L3RIGHT(ElemWriteIn,"�ɷ��ֹ��ռ�")
	L3RIGHT(CutElemInform,"����֪ͨ")

	/*������ťȨ��2009-04-28*/
	L3RIGHT(btnDesStd,"������ť--���������׼����")
	L3RIGHT(btnBOFStd,"������ť--ת¯�����׼ά��")
	L3RIGHT(btnLFStd,"������ť--LF�����׼ά��")
	L3RIGHT(btnRHStd,"������ť--RH�����׼ά��")	
	L3RIGHT(btnCCMStd,"������ť--���������׼ά��")
	L3RIGHT(btnBOFInControlEle,"������ť--ת¯�ڿظֳɷֹ���")
	L3RIGHT(btnLFInControlEle,"������ť--LF¯�ڿظֳɷֹ���")
	L3RIGHT(btnRHInControlEle,"������ť--RH�ڿظֳɷֹ���")
	L3RIGHT(btnCCMProcessStd,"������ť--�����Ƴ̱�׼ά��")
	L3RIGHT(btnProdSheet,"������ť--���տ�����")
	L3RIGHT(btnUnitPoecessTimeStd,"������ť--��������ҵʱ���׼ά��")
	L3RIGHT(btnTransTimeStd,"������ť--���������ʱ���׼ά��")
	L3RIGHT(btnRoutMaint,"������ť--����·��ά��")
	L3RIGHT(btnSteeGradeIndexMap,"������ť--���ּǺŸ��ֶ��չ�ϵά��")
	L3RIGHT(btnSteeGradeChangeMap,"������ť--���ָĸֶ��չ�ϵά��")
	L3RIGHT(btnBloomSpileStd,"������ť--�����϶��־ά��")

	L3RIGHT(btnExceptionCode,"������ť--�쳣����ά��")
	L3RIGHT(btnWeightStd,"������ť--�����������ȹ�ϵά��")
	/*������ťȨ��2009-04-28*/

	L3RIGHT(ProcessElementQuery,"��������ѯ")
	L3RIGHT(SlagElementQuery,"������ѯ")
	L3RIGHT(IronElementQuery,"��ˮ����ѯ")
	L3RIGHT(BFIronElementQuery,"��������ѯ")//2009-04-16
	L3RIGHT(SPrintElemInform,"�ͱ�������ѯ")
	L3RIGHT(SampleApplyQueryFrm,"����ί�е���ѯ")

	/***********************�����߹���****************************/
	//�����˵�
	L3RIGHT(IronLadeBase,"����������Ϣ����")
	L3RIGHT(IronLadeTie,"�������ʵ������")
	L3RIGHT(IronLadeHot,"�����濾ʵ������")
	L3RIGHT(IronLadeUse,"����ʹ��ʵ������")
	//2009-04-15
	L3RIGHT(btnAddIronLadle,"����������ť")
	L3RIGHT(btnDeleteIronLadle,"����ɾ����ť")
	//����IronLadeUse��ť
	L3RIGHT(IronLadebtnTieStart,"������Ὺʼ")
	L3RIGHT(IronLadebtnTieEnd,"����������")
	L3RIGHT(IronLadebtnSmallFireStart,"С��ʼ")
	L3RIGHT(IronLadebtnSmallFireEnd,"С�����") 
	L3RIGHT(IronLadebtnMidFireStart,"�л�ʼ")
	L3RIGHT(IronLadebtnMidFireEnd,"�л����")
	L3RIGHT(IronLadebtnBigFireStart,"���ʼ")
	L3RIGHT(IronLadebtnBigFireEnd,"������")
	L3RIGHT(IronLadebtnHot,"תΪ�ȱ�")//2009-03-27
	L3RIGHT(IronLadebtnUse,"תΪʹ��")//2009-03-27
	L3RIGHT(IronLadebtnStopUse,"����ά��")
	L3RIGHT(IronLadebtnWaitRepair,"���ߴ���")
	//�������ʵ������IronLadleTieMagFrm
	L3RIGHT(IronLadleTiebtnAdd,"�������ʵ������")
	L3RIGHT(IronLadleTiebtnDel,"�������ʵ��ɾ��")
	L3RIGHT(IronLadleTiebtnConfirm,"�������ʵ��ȷ��")
	L3RIGHT(IronLadleTiebtnQuery,"�������ʵ����ѯ")
	//�����濾ʵ������IronLadleFireMagFrm
	L3RIGHT(IronLadleFirebtnAdd,"�����濾ʵ������")
	L3RIGHT(IronLadleFirebtnDel,"�����濾ʵ��ɾ��")
	L3RIGHT(IronLadleFirebtnConfirm,"�����濾ʵ��ȷ��")
	L3RIGHT(IronLadleFirebtnQuery,"�����濾ʵ����ѯ")
	//����ʹ��ʵ������IronLadleUseMagFrm
	L3RIGHT(IronLadleUsebtnAdd,"����ʹ��ʵ������")
	L3RIGHT(IronLadleUsebtnDel,"����ʹ��ʵ��ɾ��")
	L3RIGHT(IronLadleUsebtnConfirm,"����ʹ��ʵ��ȷ��")
	L3RIGHT(IronLadleUsebtnQuery,"����ʹ��ʵ����ѯ")

	//�ְ��˵�
	L3RIGHT(LadeBase,"�ְ�������Ϣ����")
	L3RIGHT(LadleTie,"�ְ����ò���ʵ������")
	L3RIGHT(LadleWorkLayerTie,"��ͨ�ְ���������ʵ������")
	L3RIGHT(RefineLadle,"�����ְ�����������ʵ������")
	L3RIGHT(LadleHot,"�ְ��濾ʵ������")
	L3RIGHT(LadleCompelete,"�ְ��ϼ�ʵ������")
	L3RIGHT(LadleFold,"�ְ��۹�ʵ������")
	L3RIGHT(LadlePour,"�ְ�����ʵ������")
	//2009-04-15
	L3RIGHT(btnAddLadle,"�ְ�������ť")
	L3RIGHT(btnDeleteLadle,"�ְ�ɾ����ť")
	L3RIGHT(btnLaldeMeasure,"�ְ�ָ������")
	//�ְ�LadeBase��ť
	L3RIGHT(LadlebtnInnerBuildStart,"���ò�������ʼ")
	L3RIGHT(LadlebtnInnerBuildEnd,"���ò���������")
	L3RIGHT(LadlebtnWorkBuildStart,"������������ʼ")
	L3RIGHT(LadlebtnWorkBuildEnd,"��������������")
	L3RIGHT(LadlebtnWorkFireStart,"������濾��ʼ")
	L3RIGHT(LadlebtnWorkFireEnd,"������濾����")
	L3RIGHT(LadlebtnOnFireStart,"���ߺ濾��ʼ")
	L3RIGHT(LadlebtnOnFireEnd,"���ߺ濾����")
	L3RIGHT(LadlebtnBOFTaping,"ת¯���ֿ�ʼ")
	L3RIGHT(LadlebtnCastingEnd,"������ע����")
	L3RIGHT(LadlebtnOffLineToCold,"����ά��")
	L3RIGHT(LadlebtnOffLineThrow,"˦��")
	//�ְ����ò�����ʵ������LadleInnerBuildMagFrm
	L3RIGHT(LadleInnerBuildbtnAdd,"�ְ����ò�����ʵ������")
	L3RIGHT(LadleInnerBuildbtnDel,"�ְ����ò�����ʵ��ɾ��")
	L3RIGHT(LadleInnerBuildbtnConfirm,"�ְ����ò�����ʵ��ȷ��")
	L3RIGHT(LadleInnerBuildbtnQuery,"�ְ����ò�����ʵ����ѯ")
	//�����ְ�����ʵ������FinLadleBuildMagFrm
	L3RIGHT(FinLadleBuildbtnQuery,"�����ְ�����ʵ����ѯ")
	L3RIGHT(FinLadleBuildbtnAddMain,"�����ְ�����ʵ������")
	L3RIGHT(FinLadleBuildbtnDelMain,"�����ְ�����ʵ��ɾ��")
	L3RIGHT(FinLadleBuildbtnConfirmMain,"�����ְ�����ʵ��ȷ��")
	L3RIGHT(FinLadleBuildbtnAddDetail,"������ʵ������")
	L3RIGHT(FinLadleBuildbtnDelDetail,"������ʵ��ɾ��")
	L3RIGHT(FinLadleBuildbtnConfirmDetail,"������ʵ��ȷ��")
	//��ͨ�ְ����ʵ������ComLadleTieMagFrm
	L3RIGHT(ComLadleTiebtnQuery,"��ͨ�ְ����ʵ����ѯ")
	L3RIGHT(ComLadleTiebtnAddMain,"��ͨ�ְ����ʵ������")
	L3RIGHT(ComLadleTiebtnDelMain,"��ͨ�ְ����ʵ��ɾ��")
	L3RIGHT(ComLadleTiebtnConfirmMain,"��ͨ�ְ����ʵ��ȷ��")
	L3RIGHT(ComLadleTiebtnAddDetail,"��ͨ�ְ��޲�ʵ������")
	L3RIGHT(ComLadleTiebtnDelDetail,"��ͨ�ְ��޲�ʵ��ɾ��")
	L3RIGHT(ComLadleTiebtnConfirmDetail,"��ͨ�ְ��޲�ʵ��ȷ��")
	//�ְ��濾ʵ������LadleFireMagFrm
	L3RIGHT(LadleFirebtnAdd,"�ְ��濾ʵ������")
	L3RIGHT(LadleFirebtnDel,"�ְ��濾ʵ��ɾ��")
	L3RIGHT(LadleFirebtnConfirm,"�ְ��濾ʵ��ȷ��")
	L3RIGHT(LadleFirebtnQuery,"�ְ��濾ʵ����ѯ")
	//�ְ�ʹ��ʵ������LadleUseMagFrm
	L3RIGHT(LadleUsebtnAdd,"�ְ�ʹ��ʵ������")
	L3RIGHT(LadleUsebtnDel,"�ְ�ʹ��ʵ��ɾ��")
	L3RIGHT(LadleUsebtnConfirm,"�ְ�ʹ��ʵ��ȷ��")
	L3RIGHT(LadleUsebtnQuery,"�ְ�ʹ��ʵ����ѯ")
	//�ְ�����ʵ������LadlePourQueryFrm
	L3RIGHT(LadlePourbtnAdd,"�ְ�����ʵ������")
	L3RIGHT(LadlePourbtnDel,"�ְ�����ʵ��ɾ��")
	L3RIGHT(LadlePourbtnConfirm,"�ְ�����ʵ��ȷ��")
	L3RIGHT(LadlePourbtnQuery,"�ְ�����ʵ����ѯ")
	//�ְ��۹�ʵ������LadleFoldQueryFrm
	L3RIGHT(LadleFoldbtnAdd,"�ְ��۹�ʵ������")
	L3RIGHT(LadleFoldbtnDel,"�ְ��۹�ʵ��ɾ��")
	L3RIGHT(LadleFoldbtnConfirm,"�ְ��۹�ʵ��ȷ��")
	L3RIGHT(LadleFoldbtnQuery,"�ְ��۹�ʵ����ѯ")
	
	//�а��˵�
	L3RIGHT(TundishBase,"�а�������Ϣ����")
	L3RIGHT(TundishMag,"�а�����")
	L3RIGHT(TundishFireDataFrm,"�а����ߺ濾ʵ��")//[2009-03-16]
	//2009-04-15
	L3RIGHT(btnAddTundish,"�а�������ť")
	L3RIGHT(btnDeleteTundish,"�а�ɾ����ť")
	//�а�ʵ����ѯ [2009-03-30]
	L3RIGHT(TundishInnerBuildMagFrm,"�а����ò�����ʵ����ѯ")
	L3RIGHT(TundishInnerFireMagFrm,"�а����ò�濾ʵ����ѯ")
	L3RIGHT(TundishWorkBuildMagFrm,"�а���������ʵ����ѯ")
	L3RIGHT(TundishOTHotFireMagFrm,"1��2#�����а��ȱ��濾ʵ����ѯ")
	L3RIGHT(TundishTFFHotFireMagFrm,"3��4��5��7#�����а��ȱ��濾ʵ����ѯ")
	L3RIGHT(TundishOTInstallMagFrm,"1��2#�����а��ϼ�ʵ����ѯ")
	L3RIGHT(TundishTFFInstallMagFrm,"3��4��5��7#�����а��ϼ�ʵ����ѯ")
	L3RIGHT(TundishOTRefraUseMagFrm,"1��2#�����а��Ͳ�ʵ����ѯ")
	L3RIGHT(TundishTFFRefraUseMagFrm,"3��4��5��7#�����а��Ͳ�ʵ����ѯ")		

	//�а�TundishBase��ť
	L3RIGHT(TundishbtnInnerTieStart,"���ò��Ὺʼ")
	L3RIGHT(TundishbtnInnerTieEnd,"���ò������")
	L3RIGHT(TundishbtnInnerFireStart,"���ò�濾��ʼ")
	L3RIGHT(TundishbtnInnerFireEnd,"���ò�濾����")
	L3RIGHT(TundishbtnWorkBuildStart,"������ͿĨ/����ʼ")
	L3RIGHT(TundishbtnWorkBuildEnd,"������ͿĨ/�������")
	L3RIGHT(TundishbtnWorkFireStart,"������濾��ʼ")
	L3RIGHT(TundishbtnWorkFireEnd,"������濾����")
	L3RIGHT(TundishbtnConfirmCold,"ȷ���䱸")
	L3RIGHT(TundishbtnInstallStart,"�а��ϼ���ʼ")
	L3RIGHT(TundishbtnInstallEnd,"�а��ϼ�����")
	L3RIGHT(TundishbtnOnFireStart,"���ߺ濾��ʼ")
	L3RIGHT(TundishbtnOnFireEnd,"���ߺ濾����")
	L3RIGHT(TundishbtnONLine,"�а�����")
	L3RIGHT(TundishbtnOFFLine,"�а�����")//
	L3RIGHT(TundishcmsTundishDire,"ָ���а�ȥ��")
	//�а�����TabPage
	L3RIGHT(tabInnerBuild,"���ò�����")
	L3RIGHT(tabInnerFire,"���ò�濾")
	L3RIGHT(tabDaub,"������ͿĨ/����")
	L3RIGHT(tabOTInstall,"1��2#�����а��ϼ�")
	L3RIGHT(tabTFFInstall,"3��4��5��7#�����а��ϼ�")
	L3RIGHT(tabOTFire,"1��2#�����а��ȱ��濾")
	L3RIGHT(tabTFFFire,"3��4��5��7#�����а��ȱ��濾")
	L3RIGHT(tabRefraOT,"1��2#�����а��Ͳ�ʹ��")
	L3RIGHT(tabRefraTFF,"3��4��5��7#�����а��Ͳ�ʹ��")

	//�ᾧ���˵�
	L3RIGHT(MoldBase,"�ᾧ��������Ϣ����")
	L3RIGHT(MoldCuPipe,"�ᾧ��ͭ��װ��ʵ������")
	L3RIGHT(MoldCuPlate,"�ᾧ��ͭ��װ��ʵ������")
	L3RIGHT(MoldCuPipeUse,"�ᾧ��ͭ��ʹ��ʵ������")
	L3RIGHT(MoldCuPlateUse,"�ᾧ��ͭ��ʹ��ʵ������")
	L3RIGHT(MoldBoardCheckMagFrm,"�ᾧ��ͭ����ʵ������")//2009-08-25
	//2009-04-15
	L3RIGHT(btnAddMold,"�ᾧ��������ť")
	L3RIGHT(btnDeleteMold,"�ᾧ��ɾ����ť")
	//�ᾧ��MoldBase��ť
	L3RIGHT(MoldbtnInstallStrat,"�ᾧ��װ�俪ʼ")
	L3RIGHT(MoldbtnInstallEnd,"�ᾧ��װ�����")
	L3RIGHT(MoldbtnOn,"���Ͻᾧ��")
	L3RIGHT(MoldbtnChangeFlowID,"������")
	L3RIGHT(MoldbtnOffToBuild,"���ߴ�װ")
	L3RIGHT(MoldbtnOff,"�ᾧ�����߼��")
	L3RIGHT(MoldbtnCheckCom,"�ᾧ��������")
	//�ᾧ��ͭ��װ��ʵ������MoldBoardInstallMagFrm
	L3RIGHT(MoldBoardInstallbtnAdd,"�ᾧ��ͭ��װ��ʵ������")
	L3RIGHT(MoldBoardInstallbtnDel,"�ᾧ��ͭ��װ��ʵ��ɾ��")
	L3RIGHT(MoldBoardInstallbtnConfirm,"�ᾧ��ͭ��װ��ʵ��ȷ��")
	L3RIGHT(MoldBoardInstallbtnQuery,"�ᾧ��ͭ��װ��ʵ����ѯ")
	//�ᾧ��ͭ��װ��ʵ������MoldPipeInstallMagFrm
	L3RIGHT(MoldPipeInstallbtnAdd,"�ᾧ��ͭ��װ��ʵ������")
	L3RIGHT(MoldPipeInstallbtnDel,"�ᾧ��ͭ��װ��ʵ��ɾ��")
	L3RIGHT(MoldPipeInstallbtnConfirm,"�ᾧ��ͭ��װ��ʵ��ȷ��")
	L3RIGHT(MoldPipeInstallbtnQuery,"�ᾧ��ͭ��װ��ʵ����ѯ")
	//�ᾧ��ͭ��ʹ��ʵ������MoldBoardParUseMagFrm
	L3RIGHT(MoldBoardParUsebtnAdd,"�ᾧ��ͭ��ʹ��ʵ������")
	L3RIGHT(MoldBoardParUsebtnDel,"�ᾧ��ͭ��ʹ��ʵ��ɾ��")
	L3RIGHT(MoldBoardParUsebtnConfirm,"�ᾧ��ͭ��ʹ��ʵ��ȷ��")
	L3RIGHT(MoldBoardParUsebtnQuery,"�ᾧ��ͭ��ʹ��ʵ����ѯ")
	//�ᾧ��ͭ��ʹ��ʵ������MoldPipeParUseMagFrm
	L3RIGHT(MoldPipeParUsebtnAdd,"�ᾧ��ͭ��ʹ��ʵ������")
	L3RIGHT(MoldPipeParUsebtnDel,"�ᾧ��ͭ��ʹ��ʵ��ɾ��")
	L3RIGHT(MoldPipeParUsebtnConfirm,"�ᾧ��ͭ��ʹ��ʵ��ȷ��")
	L3RIGHT(MoldPipeParUsebtnQuery,"�ᾧ��ͭ��ʹ��ʵ����ѯ")
	//�ᾧ��ͭ��ʹ��ʵ������MoldBoardCheckMagFrm
	L3RIGHT(MoldBoardCheckMagbtnAdd,"�ᾧ��ͭ����ʵ������")//2009-08-25
	L3RIGHT(MoldBoardCheckMagbtnDel,"�ᾧ��ͭ����ʵ��ɾ��")//2009-08-25
	L3RIGHT(MoldBoardCheckMagbtnQuery,"�ᾧ��ͭ����ʵ����ѯ")//2009-08-25
	
	//��ղ۽��չܲ˵�
	L3RIGHT(VactubeBase,"��ղ۽��չܻ�����Ϣ����")
	L3RIGHT(VactubeRepair,"��ղ�����ʵ������")
	L3RIGHT(VactubeUse,"��ղ�ʹ��ʵ������")
	L3RIGHT(HotSypRepair,"���������ʵ������")
	L3RIGHT(HotSypUse,"�����ʹ��ʵ������")
	L3RIGHT(VactubeFire,"��ղۺ濾ʵ������")
	
	//��ղ۽��չ�VactubeBase
	L3RIGHT(VactubeBasebtnBuildStart,"��ղ۹�������ʼ")
	L3RIGHT(VactubeBasebtnBuildEnd,"��ղ�����������")
	L3RIGHT(VactubeBasebtnInstall,"��ղ���װ")
	L3RIGHT(VactubeBasebtnFire,"��ղۺ濾")
	L3RIGHT(VactubeBasebtnHotOn,"���������")
	L3RIGHT(VactubeBasebtnHotOff,"���������")
	L3RIGHT(VactubeBasebtnOnPosition,"��ղ۹���λ")
	L3RIGHT(VactubeBasebtnProcessStart,"����ʼ")
	L3RIGHT(VactubeBasebtnProcessEnd,"�������")
	L3RIGHT(VactubeBasebtnCheck,"���߼��")
	L3RIGHT(VactubeBasebtnCheckOver,"������")

	L3RIGHT(VactubeBasebtnAdd,"��ղ�������ť")
	L3RIGHT(VactubeBasebtnDelete,"��ղ�ɾ����ť")
	//RH¯��ղ�����ʵ������
	L3RIGHT(VacTubeBuildbtn,"��ղ�����ʵ��-��ť�������޸ġ�ɾ��")
	//��ղۺ濾ʵ������
	L3RIGHT(VacTubeFirebtn,"��ղۺ濾ʵ��-��ť�������޸ġ�ɾ��")
	//��ղ�ʹ��ʵ������
	L3RIGHT(VacTubeUsebtn,"��ղ�ʹ��ʵ��-��ť�������޸ġ�ɾ��")
	//���������ʵ������
	L3RIGHT(HotSypBuildbtn,"���������ʵ��-��ť�������޸ġ�ɾ��")
	//���������ʵ������
	L3RIGHT(HotSypUsebtn,"�����ʹ��ʵ��-��ť�������޸ġ�ɾ��")
	
	//��ǹ�˵�
	L3RIGHT(LanseBase,"��ǹ������Ϣ����")
	L3RIGHT(LanseMaint,"��ǹά��ʵ������")
	L3RIGHT(LanseCheck,"��ǹ���ʵ������")
	L3RIGHT(LanseUse,"��ǹʹ��ʵ������")
	//2009-04-15
	L3RIGHT(btnAddLance,"��ǹ������ť")
	L3RIGHT(btnDeleteLance,"��ǹɾ����ť")
	//��ǹLanseBase
	L3RIGHT(LansebtnDefendStrat,"��ǹ������ʼ")
	L3RIGHT(LansebtnDefendEnd,"��ǹ��������")
	L3RIGHT(LansebtnOn,"�˹�������ǹ")
	L3RIGHT(LansebtnOff,"�˹�������ǹ���")
	L3RIGHT(LansebtnCheckCom,"���߼�����")
	//��ǹά��ʵ������LanceDefendMagFrm
	L3RIGHT(LanceDefendbtnQuery,"����ʵ��ʵ����ѯ")
	L3RIGHT(LanceDefendbtnAddMain,"����ʵ��ʵ������")
	L3RIGHT(LanceDefendbtnDelMain,"����ʵ��ʵ��ɾ��")
	L3RIGHT(LanceDefendbtnConfirmMain,"����ʵ��ʵ��ȷ��")
	L3RIGHT(LanceDefendbtnAddDetail,"�ٴ�����ǹͷά������")
	L3RIGHT(LanceDefendbtnDelDetail,"�ٴ�����ǹͷά��ɾ��")
	L3RIGHT(LanceDefendbtnConfirmDetail,"�ٴ�����ǹͷά��ȷ��")
	//��ǹ���ʵ������LanceCheckMagFrm
	L3RIGHT(LanceCheckbtnAdd,"��ǹ���ʵ������")
	L3RIGHT(LanceCheckbtnDel,"��ǹ���ʵ��ɾ��")
	L3RIGHT(LanceCheckbtnConfirm,"��ǹ���ʵ��ȷ��")
	L3RIGHT(LanceCheckbtnQuery,"��ǹ���ʵ����ѯ")
	//��ǹʹ��ʵ���������LanceUseMagFrm
	L3RIGHT(LanceUsebtnAdd,"��ǹʹ��ʵ������")
	L3RIGHT(LanceUsebtnDel,"��ǹʹ��ʵ��ɾ��")
	L3RIGHT(LanceUsebtnConfirm,"��ǹʹ��ʵ��ȷ��")
	L3RIGHT(LanceUsebtnQuery,"��ǹʹ��ʵ����ѯ")
	
	/**********************************������******************************/

	//2009-03-27 liuzhiqiang
	L3RIGHT(NCTelQuery,"NC���Ĳ�ѯ")
	L3RIGHT(NCSteelTel,"NC�������Ĳ���")
	L3RIGHT(NCIronTel,"NC���ε��Ĳ���")

	//�豸У׼���� [2009-04-15]
	L3RIGHT(EquipAdjustMagFrm,"�豸У׼����")

	L3RIGHT(EquipCoilCheckFrm,"��Ž�����Ȧ���")
	L3RIGHT(EquipColletCheckFrm,"�缫��ͷ���")
	L3RIGHT(EquipLanceCheckFrm,"��ǹ�ڼ��")
	L3RIGHT(EquipLevelCheckFrm,"����Һ����")
	L3RIGHT(EquipMoldArcCheckFrm,"�ᾧ���Ի����")
	L3RIGHT(EquipOscillateCheckFrm,"��װ�ü��")
	L3RIGHT(EquipPoleCheckFrm,"�缫�׼��")
	L3RIGHT(EquipRollerCheckFrm,"���û����м��")
	L3RIGHT(EquipSectArcCheckFrm,"���ζζԻ�")
	L3RIGHT(EquipAdjustParaStdFrm,"�豸У׼������׼")
	L3RIGHT(EquipAdjustMagFrm,"�����豸У׼����")
	L3RIGHT(EquipAdjustSetFrm,"�����豸У׼����")

	L3RIGHT(btnEquipCoilCheck,"��Ž�����Ȧ���--��ť")
	L3RIGHT(btnEquipColletCheck,"�缫��ͷ���--��ť")
	L3RIGHT(btnEquipLanceCheck,"��ǹ�ڼ��--��ť")
	L3RIGHT(btnEquipLevelCheck,"����Һ����--��ť")
	L3RIGHT(btnEquipMoldArcCheck,"�ᾧ���Ի����--��ť")
	L3RIGHT(btnEquipOscillateCheck,"��װ�ü��--��ť")
	L3RIGHT(btnEquipPoleCheck,"�缫�׼��--��ť")
	L3RIGHT(btnEquipRollerCheck,"���û����м��--��ť")
	L3RIGHT(btnEquipSectArcCheck,"���ζζԻ�--��ť")
	L3RIGHT(btnEquipAdjustParaStd,"�豸У׼������׼--��ť")
	L3RIGHT(btnEquipAdjustMag,"�����豸У׼����--��ť")
	L3RIGHT(btnEquipAdjustSet,"�����豸У׼����--��ť")

	//2009-04-23
	L3RIGHT(EquipCleaningDataFrm,"������ȴ���۹���")
	L3RIGHT(EquipRuntimeFrm,"������ȴ��������")
	L3RIGHT(EquipSupplyWaterFrm,"������ȴ��ˮ����")

	//L3RIGHT(btnEquipCleaningDataFrm,"������ȴ���۹���--��ť")
	//L3RIGHT(btnEquipRuntimeFrm,"������ȴ��������--��ť")
	L3RIGHT(btnEquipSupplyWaterFrm,"������ȴ��ˮ����--��ť")

	//Modify begin 2011-02-15 by llj
	L3RIGHT(LF5Mag,"5#LF¯����")
	L3RIGHT(CCM7Mag,"7#��������")
	L3RIGHT(ProductGradeQueryFrm,"����ʵ����ѯ")
	L3RIGHT(AlloyStoreMagQuery,"�Ͻ��ϲ�����ά����Ϣ��ѯ")
	L3RIGHT(DESbtnDelete,"DES¯ʵ����ѯ--��������ɾ����ť")
	L3RIGHT(BOFbtnDelete,"BOF¯ʵ����ѯ--��������ɾ����ť")
	L3RIGHT(LFbtnDelete,"LF¯ʵ����ѯ--��������ɾ����ť")
	L3RIGHT(RHbtnDelete,"RH¯ʵ����ѯ--��������ɾ����ť")
	L3RIGHT(CCMbtnDelete,"CCM¯ʵ����ѯ--��������ɾ����ť")
	L3RIGHT(CCMbtnLadleCancel,"����¯�δ������ȡ����ť")
	L3RIGHT(CCMbtnLadleOk,"����¯�δ������ȷ����ť")
	L3RIGHT(AlloyYLStoreMaintain,"5#LF�Ͻ��ϲ�����ά��")
	L3RIGHT(AlloyYLStoreMag,"5#LF�Ͻ�ԭ�Ͽ����")
	L3RIGHT(SteelGradeGlobalMainten,"��������--�����׼����") 
	L3RIGHT(BofSteelWaterToBXGJudge,"ת¯��ˮֱ�Ͳ���������ж�")
	L3RIGHT(BofSteelWaterToBXGJudgeQuery,"ת¯��ˮֱ�Ͳ���������ж���ѯ")
	//Modify end

	//Add by hyh 2012-03-29
	L3RIGHT(SteelGradeStdMaintainMag,"���ֱ�׼ά��")
	L3RIGHT(IronWarn,"��ˮ��վ��������ʾ")
	L3RIGHT(PassWordLock,"�����������")
	//End

	//Add by hyh 2012-05-10
	L3RIGHT(LF4Mag,"4#LF¯����")
	L3RIGHT(CCM6Mag,"6#��������")
	//End

	//add by hyh 2012-06-06
	L3RIGHT(LF4AlloyYLStoreMag,"4#LF�Ͻ�ԭ�Ͽ����")
	L3RIGHT(LF4AlloyYLStoreMaintain,"4#LF�Ͻ��ϲ�����ά��")
	//end

		//Add by hyh 2012-05-10
	L3RIGHT(AODMag,"AOD¯����")
	L3RIGHT(MenuAODMag,"AOD¯�����˵�")
	L3RIGHT(AODbtnConfirm,"AOD¯ʵ������ȷ��")
	L3RIGHT(AODCheck,"AOD¯������������")
	//End

	//Add by hyh 2012-05-10
	L3RIGHT(DePMag,"����վ����")
	L3RIGHT(menuDEP,"����վ�����˵�")
	L3RIGHT(DePbtnConfirm,"����վʵ������ȷ��")
	L3RIGHT(ChangeSteel,"�ĸ�")
	//End


END_L3ACCESSCONTROL_MAP(CBaseData_Mag)

CBaseData_Mag::CBaseData_Mag(void)
{
}

CBaseData_Mag::~CBaseData_Mag(void)
{
}

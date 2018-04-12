// 逻辑类BaseData_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

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

//权限管理
BEGIN_L3ACCESSCONTROL_MAP(CBaseData_Mag,CL3Object)
	

	L3RIGHT(ProcessDataMag,"过程监控")//2009-03-25

	//基础数据维护
	L3RIGHT(TeamShiftMaint,"班次班别维护")
	L3RIGHT(MaterialFacMaint,"工器具材料厂家维护")
	L3RIGHT(MESCodeQuery,"MES系统编码查询")
	L3RIGHT(FeedWireRelationMaint,"喂丝PLC地址与喂丝代码关系维护")

	L3RIGHT(BtnMaterialFacMaint,"工器具材料厂家维护按钮")//2009-03-26
	L3RIGHT(IronLadleDataManageFrm,"铁罐档案管理")//2009-04-15

	L3RIGHT(MaterialPriceMagFrm,"物料价格库管理")//2009-04-17

	L3RIGHT(ENMediumMagFrm,"能源介质属性管理")//2009-03-27
	L3RIGHT(ENMediumMagBtnMod,"能源介质属性修改")//2009-03-27

	L3RIGHT(WireCoefficientFrm,"喂线米重管理")//2009-04-30
	L3RIGHT(btnWireCoefficient,"喂线米重按钮")//2009-04-30

	L3RIGHT(CostMediumMagFrm,"介质消耗定额管理")//2009-08-10
	L3RIGHT(CostStandardRateMagFrm,"标准费率管理")//2009-08-10

	L3RIGHT(UnitPriceMagFrm,"合金计划单价管理")//2009-08-25
	L3RIGHT(UnitConsumeMagFrm,"合金计划单耗管理")//2009-08-25
	L3RIGHT(CSteelBulkConsumeRateMagFrm,"钢铁料散装料指标单耗管理")//2009-09-07

	//工序实绩修改特殊权限
	L3RIGHT(CheckBoxBOFInfo,"转炉实绩修正高级权限")//2009-04-02
	L3RIGHT(CheckBoxLFInfo,"LR炉实绩修正高级权限")//2009-04-02
	L3RIGHT(CheckBoxRHInfo,"RH炉实绩修正高级权限")//2009-04-02
	L3RIGHT(CheckBoxCCMInfo,"连铸实绩修正高级权限")//2009-04-02

	//[2009-03-03]
	L3RIGHT(btnBaseAllCode,"MES系统编码维护")
	//[2009-03-16]
	L3RIGHT(OperatorMaint,"员工编码维护")

	//计划
	L3RIGHT(PlanOrderWriteIn,"计划订单录入")
	L3RIGHT(CastingPlan,"铸机浇钢计划排产")
	L3RIGHT(TappingPlan,"出钢计划排产")
	L3RIGHT(TappingPlanMain,"出钢计划管理")
	L3RIGHT(TappingPlanQuery,"出钢计划查询")
	L3RIGHT(BloomPlanQueryFrm,"钢坯计划订单执行情况查询")//[2009-04-07]
	

	//按钮权限
	L3RIGHT(BtnCancelTappingPlan,"取消出钢计划")
	L3RIGHT(BtnTappingPlanSend,"出钢计划下达")
	L3RIGHT(BtnTappingPlanSendCancel,"出钢计划下达取消")
	L3RIGHT(BtnTappingPlanExchange,"炉座交换")
	L3RIGHT(BtnExchangeProcessSeq,"调整铸机处理顺序")
	L3RIGHT(BtnModTappingPlan,"出钢计划修改")
	L3RIGHT(BtnChengeRoute,"更改工艺路径")
	L3RIGHT(BtnDispathAccountMag,"调度台帐管理")//2009-03-16
	L3RIGHT(BtnCastingPlanGen,"铸机浇钢计划排产按钮")//2009-03-26


	//调度
	L3RIGHT(ExceptionProcess,"工艺异常处理")
	L3RIGHT(ProcessTrack,"流程监视")
	L3RIGHT(DispathLog,"调度记事查询")
	L3RIGHT(SteelBackQuery,"钢水返送申请查询")
	L3RIGHT(SteelTurnQuery,"钢水全回炉查询")
	L3RIGHT(SteelExchangeQuery,"改钢申请查询")

	L3RIGHT(BtnDispathLog,"调度记事管理按钮")//2009-03-26
	L3RIGHT(DispatchMap,"调度生产即时状态")//2009-04-07
	L3RIGHT(DispExceptionalFrm,"设备异常管理界面")//2009-04-15
	L3RIGHT(btnDispExceptional,"设备异常管理按钮")//2009-04-15

	//能源介质
	L3RIGHT(EnergyMain,"能源监视画面")

	//工序弹出菜单[2009-03-13]
	L3RIGHT(menuBOF,"弹出菜单转炉")
	L3RIGHT(menuLF,"弹出菜单LF")
	L3RIGHT(menuRH,"弹出菜单RH")
	L3RIGHT(menuSide,"弹出菜单炉后")
	L3RIGHT(menuCCM,"弹出菜单铸机")
	//工序铁水
	L3RIGHT(IronIntegrateMag,"铁水收集管理")
	L3RIGHT(IronDestinationMag,"铁水去向管理")
	L3RIGHT(IronInforQueryMag,"铁水信息查询")
	
	//2009-03-31 
	L3RIGHT(btnBFSample,"铁钩样委托单")
	L3RIGHT(btnDisSSample,"脱硫委托单")
	//200904-08
	L3RIGHT(btnDelBFIron,"铁水--删除铁水信息")
	L3RIGHT(menuSouresHF,"铁水--指定为高炉铁水")
	L3RIGHT(menuSoureS,"铁水--指定为脱硫站铁水")
	L3RIGHT(menuGross,"铁水--设定毛重")
	L3RIGHT(menuTare,"铁水--设定皮重")
	L3RIGHT(menuToIron,"铁--水去铸铁")
	L3RIGHT(menuToNC,"铁水--上传NC")
	

	//工序混铁炉
	L3RIGHT(MixFurnaceMag,"混铁炉管理")
	L3RIGHT(btnMixFurnaceMag,"混铁炉管理按钮")
	L3RIGHT(MixFurnaceDataQuery,"混铁炉区域数据查询")
	L3RIGHT(MixTappedBtn,"混铁炉区域出铁按钮")//2009-08-10
	//工序脱硫 2009-10-29 sun
	L3RIGHT(DeSIMag,"I部脱硫工序管理")
	L3RIGHT(DeSIIMag,"II部脱硫工序管理")
	L3RIGHT(DeSPorcessDataQuery,"脱硫实绩查询")
	L3RIGHT(DeSAdditionMag,"脱硫加料维护")
	L3RIGHT(DeSSideDuty,"脱硫责任人维护")
	L3RIGHT(DeSStatusQuery,"脱硫设备状态查询")
	L3RIGHT(DeSLanceMagFrm,"脱硫喷枪管理")

	//按钮权限
	L3RIGHT(btnPrepare,"脱硫准备脱硫")
	L3RIGHT(btnConfirm1,"脱硫来料确认")
	L3RIGHT(btnUndoDes1,"脱硫撤销确认")
	L3RIGHT(btnironArrived1,"脱硫铁罐进站")
	L3RIGHT(btnDesignateDeSUnitID1,"脱硫指定工位")
	L3RIGHT(btnBeginPreRemoveSlag1,"脱硫预捞渣开始")
	L3RIGHT(btnEndPreRemoveSlag1,"脱硫预捞渣结束")
	L3RIGHT(btnStartBlowing1,"脱硫喷吹开始")
	L3RIGHT(btnStopBlowing1,"脱硫喷吹结束")
	L3RIGHT(btnBeginRemoveSlag1,"脱硫捞渣开始")
	L3RIGHT(btnEndRemoveSlag1,"脱硫捞渣结束")
	L3RIGHT(btnIronsDeparture1,"脱硫指定去向")
	L3RIGHT(btnDeSType1,"脱硫脱硫类型")
	L3RIGHT(btnDeSIronSheet1,"脱硫制定委托单")
	L3RIGHT(btnChangeLance1,"脱硫换枪")
	L3RIGHT(btnChangeTreatNo1,"脱硫喷吹号修改")
	L3RIGHT(btnEquipmentStatus1,"脱硫设备状态维护")
	L3RIGHT(btnMatSet1,"脱硫脱硫剂代码厂家设定")
	L3RIGHT(btnRemoveSlagCount,"脱硫捞渣次数")
	L3RIGHT(btnLanceQuery,"脱硫喷枪查询")
	L3RIGHT(btnOut,"脱硫铁罐出站")

L3RIGHT(btnDeSProcessConfirm,"脱硫实绩确认")
L3RIGHT(cxDeSCheckFlag,"脱硫数据维护")
L3RIGHT(btnDeSPorcessDataQuery,"脱硫实绩查询按钮")

L3RIGHT(btnDeSAdditionAdd,"脱硫加料维护新增按钮")
L3RIGHT(btnDeSAdditionConfirm,"脱硫加料维护确认按钮")
L3RIGHT(btnDeSAdditionCancel,"脱硫加料维护取消按钮")

L3RIGHT(btnDeSDutyConfirm,"脱硫责任者维护确定按钮")

L3RIGHT(btnDeSLanceAdd,"脱硫喷枪新增按钮")
L3RIGHT(btnDeSLanceChangeStatus,"脱硫喷枪修改状态按钮")
L3RIGHT(btnDeSLanceChangeAge,"脱硫喷枪修改枪龄按钮")
L3RIGHT(btnDeSLanceConfirm,"脱硫喷枪确定按钮")
L3RIGHT(btnDeSLanceCancel,"脱硫喷枪取消按钮")

	//工序转炉
	L3RIGHT(BOF1Mag,"1#转炉工序")
	L3RIGHT(BOF2Mag,"2#转炉工序")	
	L3RIGHT(BOF3Mag,"3#转炉工序")	
	L3RIGHT(BOF4Mag,"4#转炉工序")	
	L3RIGHT(BOFProcessDataQuery,"转炉实绩查询")
	L3RIGHT(BOFDuty,"转炉责任人维护")	
	//工序炉后
	L3RIGHT(BOFSide1Mag,"1#转炉炉后工序")
	L3RIGHT(BOFSide2Mag,"2#转炉炉后工序")	
	L3RIGHT(BOFSide3Mag,"3#转炉炉后工序")	
	L3RIGHT(BOFSide4Mag,"4#转炉炉后工序")	
	L3RIGHT(BOFSideProcessDataQuery,"转炉炉后实绩查询")	
	L3RIGHT(BOFSideDuty,"转炉炉后责任人维护")	
	//工序LF
	L3RIGHT(LF1Mag,"1#LF炉工序")
	L3RIGHT(LF2Mag,"2#LF炉工序")	
	L3RIGHT(LF3Mag,"3#LF炉工序")	
	L3RIGHT(LFProcessDataQuery,"LF炉实绩查询")	
	L3RIGHT(LFDuty,"LF责任人维护")	
	//工序RH
	L3RIGHT(RH1Mag,"1#RH炉工序")
	L3RIGHT(RHProcessDataQuery,"RH炉实绩查询")	
	L3RIGHT(RHDuty,"RH责任人维护")
	//工序铸机
	L3RIGHT(CCM1Mag,"1#连铸工序")
	L3RIGHT(CCM2Mag,"2#连铸工序")
	L3RIGHT(CCM3Mag,"3#连铸工序")
	L3RIGHT(CCM4Mag,"4#连铸工序")
	L3RIGHT(CCM5Mag,"5#连铸工序")
	L3RIGHT(CCMMarkScrap,"连铸钢坯甩废")
	L3RIGHT(CCMScrapDuty,"连铸甩废责任确认")
	L3RIGHT(CCMMakeProduct,"出坯管理")
	L3RIGHT(CCMSideMag,"连铸台下")
	L3RIGHT(CCMProcessDataQuery,"连铸实绩查询")	
	L3RIGHT(CCMDuty,"连铸责任人维护")
	L3RIGHT(CCMSamplebtnComfirm,"确认取样")
	//2009-04-07
	L3RIGHT(CCMScrapDutyFrm,"炉次甩废责任指定")
	L3RIGHT(CCMRefraQueryFrm,"连铸耐材使用实绩查询")
	L3RIGHT(EquipmentStatusQueryFrm,"设备状态变化查询")

	//工序实绩数据修正按钮
	L3RIGHT(BOFbtnConfirm,"转炉实绩确认")
	L3RIGHT(BOFCheck,"转炉实绩数据修正")
	L3RIGHT(SidebtnConfirm,"转炉炉后实绩确认")
	L3RIGHT(SideCheck,"转炉炉后实绩数据修正")
	L3RIGHT(LFbtnConfirm,"LF炉实绩确认")
	L3RIGHT(LFCheck,"LF炉实绩数据修正")
	L3RIGHT(RHbtnConfirm,"RH炉实绩确认")
	L3RIGHT(RHCheck,"RH炉实绩数据修正")
	L3RIGHT(CCMbtnConfirm,"连铸实绩确认")
	L3RIGHT(CCMCheck,"连铸实绩数据修正")


	//库管理
	L3RIGHT(ScrapStoreMag,"废钢生铁原料库管理")
	L3RIGHT(ScrapStoreInStoreQuery,"废钢生铁入库查询")
	L3RIGHT(ScrapStoreOutStoreQuery,"废钢生铁出库查询")
	L3RIGHT(ScrapStoreModQuery,"废钢生铁盘库查询")

	//2009-03-16
	L3RIGHT(BtnScrapInStore,"废钢入库")
	L3RIGHT(BtnScrapOutStore,"废钢出库")
	L3RIGHT(BtnScrapOutStoreCanel,"废钢撤销出库")
	L3RIGHT(BtnScrapBanlance,"废钢盘库")
	L3RIGHT(BtnScrapExl,"废钢Exl导入")


	L3RIGHT(AlloyStoreMag,"转炉合金原料库管理")//2009-04-04
	L3RIGHT(AlloyStoreInStoreQuery,"合金原入库查询")
	L3RIGHT(AlloyStoreOutStoreQuery,"合金原出库查询")
	L3RIGHT(AlloyStoreTransQuery,"合金转库查询")
	L3RIGHT(AlloyStoreModQuery,"合金盘库查询")
	L3RIGHT(AlloyStoreBulkRelation,"转炉合金料仓料种维护")//2009-04-04

	L3RIGHT(AlloyStoreQueryFrm,"合金库存查询")//2009-04-08

	//2009-03-16
	L3RIGHT(BtnAlloyInstore,"合金上料")
	L3RIGHT(BtnAlloyExl,"合金Exl导入")

	//2009-04-04
	L3RIGHT(AlloyStoreLFMag,"1、2#LF合金原料库管理")
	L3RIGHT(AlloyStoreRHMag,"3#LF、RH合金原料库管理")
	L3RIGHT(AlloyAndAreaLFMapFrm,"1、2#LF合金料仓料种维护")
	L3RIGHT(AlloyAndAreaRHMapFrm,"3#LF、RH合金料仓料种维护")

	L3RIGHT(BulkStoreMag,"散状料原料库管理")
	L3RIGHT(BulkStoreInStoreQuery,"散状料入库查询")
	L3RIGHT(BulkStoreOutStoreQuery,"散状料出库查询")
	L3RIGHT(BulkStoreTransQuery,"散状料转库查询")
	L3RIGHT(BulkStoreModQuery,"散状料盘库查询")
	L3RIGHT(BulkStoreBulkRelation,"散状料料仓料种维护")

	//2009-03-16
	L3RIGHT(BtnBulkInstore,"散状料上料")
	L3RIGHT(BtnBulkExl,"散状料Exl导入")

	L3RIGHT(BloomStoreMag,"钢坯库管理")
	L3RIGHT(BloomStoreInStoreQuery,"钢坯库入库查询")
	L3RIGHT(BloomStoreOutStoreQuery,"钢坯库出库查询")
	L3RIGHT(BloomStoreTransQuery,"钢坯库转库查询")
	L3RIGHT(BloomStoreOnStoreQuery,"钢坯库库存查询")
	//在库钢坯管理按钮
	L3RIGHT(BloomStorebtnInStore,"入库")
	L3RIGHT(BloomStorebtnQualityCheck,"抽检")
	L3RIGHT(BloomStorebtnSpileChange,"垛位变更")
	L3RIGHT(BloomStorebtnOutStore,"出库")

	//质量管理管理
	L3RIGHT(HotJudge,"热检质量判定")
	L3RIGHT(FinalJudge,"终判")
	L3RIGHT(FinalJudgeQuery,"终判查询")
	L3RIGHT(HotJudgeQuery,"热检质量判定查询")
	L3RIGHT(DesStd,"脱硫制造标准管理")
	L3RIGHT(BOFStd,"转炉制造标准维护")
	L3RIGHT(LFStd,"LF制造标准维护")
	L3RIGHT(RHStd,"RH制造标准维护")	
	L3RIGHT(CCMStd,"铸机制造标准维护")
	L3RIGHT(BOFInControlEle,"转炉内控钢成分管理")
	L3RIGHT(LFInControlEle,"LF炉内控钢成分管理")
	L3RIGHT(RHInControlEle,"RH内控钢成分管理")
	L3RIGHT(CCMProcessStd,"铸机制程标准维护")
	L3RIGHT(ProdSheet,"工艺卡管理")
	L3RIGHT(UnitPoecessTimeStd,"工序内作业时间标准维护")
	L3RIGHT(TransTimeStd,"工序间运输时间标准维护")
	L3RIGHT(RoutMaint,"工艺路径维护")
	L3RIGHT(SteeGradeIndexMap,"炼钢记号钢种对照关系维护")
	L3RIGHT(SteeGradeChangeMap,"钢种改钢对照关系维护")
	L3RIGHT(BloomSpileStd,"钢坯上垛标志维护")
	//按钮权限
	L3RIGHT(BtnAddSteeGradeIndexMap,"新增炼钢记号钢种对照关系维护")
	L3RIGHT(BtnDelSteeGradeIndexMap,"删除炼钢记号钢种对照关系维护")
	L3RIGHT(BtnConfirmSteeGradeIndexMap,"确认炼钢记号钢种对照关系维护")

	L3RIGHT(DecideCode,"处置代码维护")
	L3RIGHT(ExceptionGroup,"异常处理组号维护")
	L3RIGHT(ExceptionCode,"异常代码维护")
	L3RIGHT(WeightStd,"铸坯重量长度关系维护")
	L3RIGHT(ElemWriteIn,"成分手工收集")
	L3RIGHT(CutElemInform,"割样通知")

	/*质量按钮权限2009-04-28*/
	L3RIGHT(btnDesStd,"质量按钮--脱硫制造标准管理")
	L3RIGHT(btnBOFStd,"质量按钮--转炉制造标准维护")
	L3RIGHT(btnLFStd,"质量按钮--LF制造标准维护")
	L3RIGHT(btnRHStd,"质量按钮--RH制造标准维护")	
	L3RIGHT(btnCCMStd,"质量按钮--铸机制造标准维护")
	L3RIGHT(btnBOFInControlEle,"质量按钮--转炉内控钢成分管理")
	L3RIGHT(btnLFInControlEle,"质量按钮--LF炉内控钢成分管理")
	L3RIGHT(btnRHInControlEle,"质量按钮--RH内控钢成分管理")
	L3RIGHT(btnCCMProcessStd,"质量按钮--铸机制程标准维护")
	L3RIGHT(btnProdSheet,"质量按钮--工艺卡管理")
	L3RIGHT(btnUnitPoecessTimeStd,"质量按钮--工序内作业时间标准维护")
	L3RIGHT(btnTransTimeStd,"质量按钮--工序间运输时间标准维护")
	L3RIGHT(btnRoutMaint,"质量按钮--工艺路径维护")
	L3RIGHT(btnSteeGradeIndexMap,"质量按钮--炼钢记号钢种对照关系维护")
	L3RIGHT(btnSteeGradeChangeMap,"质量按钮--钢种改钢对照关系维护")
	L3RIGHT(btnBloomSpileStd,"质量按钮--钢坯上垛标志维护")

	L3RIGHT(btnExceptionCode,"质量按钮--异常代码维护")
	L3RIGHT(btnWeightStd,"质量按钮--铸坯重量长度关系维护")
	/*质量按钮权限2009-04-28*/

	L3RIGHT(ProcessElementQuery,"过程样查询")
	L3RIGHT(SlagElementQuery,"渣样查询")
	L3RIGHT(IronElementQuery,"铁水样查询")
	L3RIGHT(BFIronElementQuery,"高铁样查询")//2009-04-16
	L3RIGHT(SPrintElemInform,"低倍硫样查询")
	L3RIGHT(SampleApplyQueryFrm,"化验委托单查询")

	/***********************工器具管理****************************/
	//铁包菜单
	L3RIGHT(IronLadeBase,"铁包基本信息管理")
	L3RIGHT(IronLadeTie,"铁包打结实绩管理")
	L3RIGHT(IronLadeHot,"铁包烘烤实绩管理")
	L3RIGHT(IronLadeUse,"铁包使用实绩管理")
	//2009-04-15
	L3RIGHT(btnAddIronLadle,"铁包新增按钮")
	L3RIGHT(btnDeleteIronLadle,"铁包删除按钮")
	//铁包IronLadeUse按钮
	L3RIGHT(IronLadebtnTieStart,"铁包打结开始")
	L3RIGHT(IronLadebtnTieEnd,"铁包打结结束")
	L3RIGHT(IronLadebtnSmallFireStart,"小火开始")
	L3RIGHT(IronLadebtnSmallFireEnd,"小火结束") 
	L3RIGHT(IronLadebtnMidFireStart,"中火开始")
	L3RIGHT(IronLadebtnMidFireEnd,"中火结束")
	L3RIGHT(IronLadebtnBigFireStart,"大火开始")
	L3RIGHT(IronLadebtnBigFireEnd,"大火结束")
	L3RIGHT(IronLadebtnHot,"转为热备")//2009-03-27
	L3RIGHT(IronLadebtnUse,"转为使用")//2009-03-27
	L3RIGHT(IronLadebtnStopUse,"下线维护")
	L3RIGHT(IronLadebtnWaitRepair,"离线待修")
	//铁包打结实绩管理IronLadleTieMagFrm
	L3RIGHT(IronLadleTiebtnAdd,"铁包打结实绩新增")
	L3RIGHT(IronLadleTiebtnDel,"铁包打结实绩删除")
	L3RIGHT(IronLadleTiebtnConfirm,"铁包打结实绩确认")
	L3RIGHT(IronLadleTiebtnQuery,"铁包打结实绩查询")
	//铁包烘烤实绩管理IronLadleFireMagFrm
	L3RIGHT(IronLadleFirebtnAdd,"铁包烘烤实绩新增")
	L3RIGHT(IronLadleFirebtnDel,"铁包烘烤实绩删除")
	L3RIGHT(IronLadleFirebtnConfirm,"铁包烘烤实绩确认")
	L3RIGHT(IronLadleFirebtnQuery,"铁包烘烤实绩查询")
	//铁包使用实绩管理IronLadleUseMagFrm
	L3RIGHT(IronLadleUsebtnAdd,"铁包使用实绩新增")
	L3RIGHT(IronLadleUsebtnDel,"铁包使用实绩删除")
	L3RIGHT(IronLadleUsebtnConfirm,"铁包使用实绩确认")
	L3RIGHT(IronLadleUsebtnQuery,"铁包使用实绩查询")

	//钢包菜单
	L3RIGHT(LadeBase,"钢包基本信息管理")
	L3RIGHT(LadleTie,"钢包永久层打结实绩管理")
	L3RIGHT(LadleWorkLayerTie,"普通钢包工作层打结实绩管理")
	L3RIGHT(RefineLadle,"精炼钢包工作层砌筑实绩管理")
	L3RIGHT(LadleHot,"钢包烘烤实绩管理")
	L3RIGHT(LadleCompelete,"钢包上件实绩管理")
	L3RIGHT(LadleFold,"钢包折罐实绩管理")
	L3RIGHT(LadlePour,"钢包倒包实绩管理")
	//2009-04-15
	L3RIGHT(btnAddLadle,"钢包新增按钮")
	L3RIGHT(btnDeleteLadle,"钢包删除按钮")
	L3RIGHT(btnLaldeMeasure,"钢包指定称重")
	//钢包LadeBase按钮
	L3RIGHT(LadlebtnInnerBuildStart,"永久层砌筑开始")
	L3RIGHT(LadlebtnInnerBuildEnd,"永久层砌筑结束")
	L3RIGHT(LadlebtnWorkBuildStart,"工作层修砌开始")
	L3RIGHT(LadlebtnWorkBuildEnd,"工作层修砌结束")
	L3RIGHT(LadlebtnWorkFireStart,"工作层烘烤开始")
	L3RIGHT(LadlebtnWorkFireEnd,"工作层烘烤结束")
	L3RIGHT(LadlebtnOnFireStart,"在线烘烤开始")
	L3RIGHT(LadlebtnOnFireEnd,"在线烘烤结束")
	L3RIGHT(LadlebtnBOFTaping,"转炉出钢开始")
	L3RIGHT(LadlebtnCastingEnd,"连铸浇注结束")
	L3RIGHT(LadlebtnOffLineToCold,"下线维护")
	L3RIGHT(LadlebtnOffLineThrow,"甩包")
	//钢包永久层砌筑实绩管理LadleInnerBuildMagFrm
	L3RIGHT(LadleInnerBuildbtnAdd,"钢包永久层砌筑实绩新增")
	L3RIGHT(LadleInnerBuildbtnDel,"钢包永久层砌筑实绩删除")
	L3RIGHT(LadleInnerBuildbtnConfirm,"钢包永久层砌筑实绩确认")
	L3RIGHT(LadleInnerBuildbtnQuery,"钢包永久层砌筑实绩查询")
	//精炼钢包砌筑实绩管理FinLadleBuildMagFrm
	L3RIGHT(FinLadleBuildbtnQuery,"精炼钢包砌筑实绩查询")
	L3RIGHT(FinLadleBuildbtnAddMain,"精炼钢包砌筑实绩新增")
	L3RIGHT(FinLadleBuildbtnDelMain,"精炼钢包砌筑实绩删除")
	L3RIGHT(FinLadleBuildbtnConfirmMain,"精炼钢包砌筑实绩确认")
	L3RIGHT(FinLadleBuildbtnAddDetail,"换渣线实绩新增")
	L3RIGHT(FinLadleBuildbtnDelDetail,"换渣线实绩删除")
	L3RIGHT(FinLadleBuildbtnConfirmDetail,"换渣线实绩确认")
	//普通钢包打结实绩管理ComLadleTieMagFrm
	L3RIGHT(ComLadleTiebtnQuery,"普通钢包打结实绩查询")
	L3RIGHT(ComLadleTiebtnAddMain,"普通钢包打结实绩新增")
	L3RIGHT(ComLadleTiebtnDelMain,"普通钢包打结实绩删除")
	L3RIGHT(ComLadleTiebtnConfirmMain,"普通钢包打结实绩确认")
	L3RIGHT(ComLadleTiebtnAddDetail,"普通钢包修补实绩新增")
	L3RIGHT(ComLadleTiebtnDelDetail,"普通钢包修补实绩删除")
	L3RIGHT(ComLadleTiebtnConfirmDetail,"普通钢包修补实绩确认")
	//钢包烘烤实绩管理LadleFireMagFrm
	L3RIGHT(LadleFirebtnAdd,"钢包烘烤实绩新增")
	L3RIGHT(LadleFirebtnDel,"钢包烘烤实绩删除")
	L3RIGHT(LadleFirebtnConfirm,"钢包烘烤实绩确认")
	L3RIGHT(LadleFirebtnQuery,"钢包烘烤实绩查询")
	//钢包使用实绩管理LadleUseMagFrm
	L3RIGHT(LadleUsebtnAdd,"钢包使用实绩新增")
	L3RIGHT(LadleUsebtnDel,"钢包使用实绩删除")
	L3RIGHT(LadleUsebtnConfirm,"钢包使用实绩确认")
	L3RIGHT(LadleUsebtnQuery,"钢包使用实绩查询")
	//钢包倒包实绩管理LadlePourQueryFrm
	L3RIGHT(LadlePourbtnAdd,"钢包倒包实绩新增")
	L3RIGHT(LadlePourbtnDel,"钢包倒包实绩删除")
	L3RIGHT(LadlePourbtnConfirm,"钢包倒包实绩确认")
	L3RIGHT(LadlePourbtnQuery,"钢包倒包实绩查询")
	//钢包折灌实绩管理LadleFoldQueryFrm
	L3RIGHT(LadleFoldbtnAdd,"钢包折灌实绩新增")
	L3RIGHT(LadleFoldbtnDel,"钢包折灌实绩删除")
	L3RIGHT(LadleFoldbtnConfirm,"钢包折灌实绩确认")
	L3RIGHT(LadleFoldbtnQuery,"钢包折灌实绩查询")
	
	//中包菜单
	L3RIGHT(TundishBase,"中包基本信息管理")
	L3RIGHT(TundishMag,"中包管理")
	L3RIGHT(TundishFireDataFrm,"中包在线烘烤实绩")//[2009-03-16]
	//2009-04-15
	L3RIGHT(btnAddTundish,"中包新增按钮")
	L3RIGHT(btnDeleteTundish,"中包删除按钮")
	//中包实绩查询 [2009-03-30]
	L3RIGHT(TundishInnerBuildMagFrm,"中包永久层砌筑实绩查询")
	L3RIGHT(TundishInnerFireMagFrm,"中包永久层烘烤实绩查询")
	L3RIGHT(TundishWorkBuildMagFrm,"中包工作层打结实绩查询")
	L3RIGHT(TundishOTHotFireMagFrm,"1、2#铸机中包热备烘烤实绩查询")
	L3RIGHT(TundishTFFHotFireMagFrm,"3、4、5、7#铸机中包热备烘烤实绩查询")
	L3RIGHT(TundishOTInstallMagFrm,"1、2#铸机中包上件实绩查询")
	L3RIGHT(TundishTFFInstallMagFrm,"3、4、5、7#铸机中包上件实绩查询")
	L3RIGHT(TundishOTRefraUseMagFrm,"1、2#铸机中包耐材实绩查询")
	L3RIGHT(TundishTFFRefraUseMagFrm,"3、4、5、7#铸机中包耐材实绩查询")		

	//中包TundishBase按钮
	L3RIGHT(TundishbtnInnerTieStart,"永久层打结开始")
	L3RIGHT(TundishbtnInnerTieEnd,"永久层打结结束")
	L3RIGHT(TundishbtnInnerFireStart,"永久层烘烤开始")
	L3RIGHT(TundishbtnInnerFireEnd,"永久层烘烤结束")
	L3RIGHT(TundishbtnWorkBuildStart,"工作层涂抹/干振开始")
	L3RIGHT(TundishbtnWorkBuildEnd,"工作层涂抹/干振结束")
	L3RIGHT(TundishbtnWorkFireStart,"工作层烘烤开始")
	L3RIGHT(TundishbtnWorkFireEnd,"工作层烘烤结束")
	L3RIGHT(TundishbtnConfirmCold,"确认冷备")
	L3RIGHT(TundishbtnInstallStart,"中包上件开始")
	L3RIGHT(TundishbtnInstallEnd,"中包上件结束")
	L3RIGHT(TundishbtnOnFireStart,"在线烘烤开始")
	L3RIGHT(TundishbtnOnFireEnd,"在线烘烤结束")
	L3RIGHT(TundishbtnONLine,"中包上线")
	L3RIGHT(TundishbtnOFFLine,"中包下线")//
	L3RIGHT(TundishcmsTundishDire,"指定中包去向")
	//中包管理TabPage
	L3RIGHT(tabInnerBuild,"永久层砌筑")
	L3RIGHT(tabInnerFire,"永久层烘烤")
	L3RIGHT(tabDaub,"工作层涂抹/干振")
	L3RIGHT(tabOTInstall,"1、2#铸机中包上件")
	L3RIGHT(tabTFFInstall,"3、4、5、7#铸机中包上件")
	L3RIGHT(tabOTFire,"1、2#铸机中包热备烘烤")
	L3RIGHT(tabTFFFire,"3、4、5、7#铸机中包热备烘烤")
	L3RIGHT(tabRefraOT,"1、2#铸机中包耐材使用")
	L3RIGHT(tabRefraTFF,"3、4、5、7#铸机中包耐材使用")

	//结晶器菜单
	L3RIGHT(MoldBase,"结晶器基本信息管理")
	L3RIGHT(MoldCuPipe,"结晶器铜管装配实绩管理")
	L3RIGHT(MoldCuPlate,"结晶器铜板装配实绩管理")
	L3RIGHT(MoldCuPipeUse,"结晶器铜管使用实绩管理")
	L3RIGHT(MoldCuPlateUse,"结晶器铜板使用实绩管理")
	L3RIGHT(MoldBoardCheckMagFrm,"结晶器铜板检查实绩管理")//2009-08-25
	//2009-04-15
	L3RIGHT(btnAddMold,"结晶器新增按钮")
	L3RIGHT(btnDeleteMold,"结晶器删除按钮")
	//结晶器MoldBase按钮
	L3RIGHT(MoldbtnInstallStrat,"结晶器装配开始")
	L3RIGHT(MoldbtnInstallEnd,"结晶器装配结束")
	L3RIGHT(MoldbtnOn,"换上结晶器")
	L3RIGHT(MoldbtnChangeFlowID,"换流别")
	L3RIGHT(MoldbtnOffToBuild,"下线待装")
	L3RIGHT(MoldbtnOff,"结晶器下线检测")
	L3RIGHT(MoldbtnCheckCom,"结晶器检测完毕")
	//结晶器铜板装配实绩管理MoldBoardInstallMagFrm
	L3RIGHT(MoldBoardInstallbtnAdd,"结晶器铜板装配实绩新增")
	L3RIGHT(MoldBoardInstallbtnDel,"结晶器铜板装配实绩删除")
	L3RIGHT(MoldBoardInstallbtnConfirm,"结晶器铜板装配实绩确认")
	L3RIGHT(MoldBoardInstallbtnQuery,"结晶器铜板装配实绩查询")
	//结晶器铜管装配实绩管理MoldPipeInstallMagFrm
	L3RIGHT(MoldPipeInstallbtnAdd,"结晶器铜管装配实绩新增")
	L3RIGHT(MoldPipeInstallbtnDel,"结晶器铜管装配实绩删除")
	L3RIGHT(MoldPipeInstallbtnConfirm,"结晶器铜管装配实绩确认")
	L3RIGHT(MoldPipeInstallbtnQuery,"结晶器铜管装配实绩查询")
	//结晶器铜板使用实绩管理MoldBoardParUseMagFrm
	L3RIGHT(MoldBoardParUsebtnAdd,"结晶器铜板使用实绩新增")
	L3RIGHT(MoldBoardParUsebtnDel,"结晶器铜板使用实绩删除")
	L3RIGHT(MoldBoardParUsebtnConfirm,"结晶器铜板使用实绩确认")
	L3RIGHT(MoldBoardParUsebtnQuery,"结晶器铜板使用实绩查询")
	//结晶器铜管使用实绩管理MoldPipeParUseMagFrm
	L3RIGHT(MoldPipeParUsebtnAdd,"结晶器铜管使用实绩新增")
	L3RIGHT(MoldPipeParUsebtnDel,"结晶器铜管使用实绩删除")
	L3RIGHT(MoldPipeParUsebtnConfirm,"结晶器铜管使用实绩确认")
	L3RIGHT(MoldPipeParUsebtnQuery,"结晶器铜管使用实绩查询")
	//结晶器铜管使用实绩管理MoldBoardCheckMagFrm
	L3RIGHT(MoldBoardCheckMagbtnAdd,"结晶器铜板检查实绩新增")//2009-08-25
	L3RIGHT(MoldBoardCheckMagbtnDel,"结晶器铜板检查实绩删除")//2009-08-25
	L3RIGHT(MoldBoardCheckMagbtnQuery,"结晶器铜板检查实绩查询")//2009-08-25
	
	//真空槽浸渍管菜单
	L3RIGHT(VactubeBase,"真空槽浸渍管基本信息管理")
	L3RIGHT(VactubeRepair,"真空槽砌筑实绩管理")
	L3RIGHT(VactubeUse,"真空槽使用实绩管理")
	L3RIGHT(HotSypRepair,"热弯管砌筑实绩管理")
	L3RIGHT(HotSypUse,"热弯管使用实绩管理")
	L3RIGHT(VactubeFire,"真空槽烘烤实绩管理")
	
	//真空槽浸渍管VactubeBase
	L3RIGHT(VactubeBasebtnBuildStart,"真空槽管砌筑开始")
	L3RIGHT(VactubeBasebtnBuildEnd,"真空槽砌管筑结束")
	L3RIGHT(VactubeBasebtnInstall,"真空槽组装")
	L3RIGHT(VactubeBasebtnFire,"真空槽烘烤")
	L3RIGHT(VactubeBasebtnHotOn,"换上热弯管")
	L3RIGHT(VactubeBasebtnHotOff,"换下热弯管")
	L3RIGHT(VactubeBasebtnOnPosition,"真空槽管上位")
	L3RIGHT(VactubeBasebtnProcessStart,"处理开始")
	L3RIGHT(VactubeBasebtnProcessEnd,"处理结束")
	L3RIGHT(VactubeBasebtnCheck,"下线检查")
	L3RIGHT(VactubeBasebtnCheckOver,"检查完毕")

	L3RIGHT(VactubeBasebtnAdd,"真空槽新增按钮")
	L3RIGHT(VactubeBasebtnDelete,"真空槽删除按钮")
	//RH炉真空槽砌筑实绩管理
	L3RIGHT(VacTubeBuildbtn,"真空槽砌筑实绩-按钮新增、修改、删除")
	//真空槽烘烤实绩管理
	L3RIGHT(VacTubeFirebtn,"真空槽烘烤实绩-按钮新增、修改、删除")
	//真空槽使用实绩管理
	L3RIGHT(VacTubeUsebtn,"真空槽使用实绩-按钮新增、修改、删除")
	//热弯管砌筑实绩管理
	L3RIGHT(HotSypBuildbtn,"热弯管砌筑实绩-按钮新增、修改、删除")
	//热弯管砌筑实绩管理
	L3RIGHT(HotSypUsebtn,"热弯管使用实绩-按钮新增、修改、删除")
	
	//氧枪菜单
	L3RIGHT(LanseBase,"氧枪基本信息管理")
	L3RIGHT(LanseMaint,"氧枪维护实绩管理")
	L3RIGHT(LanseCheck,"氧枪检查实绩管理")
	L3RIGHT(LanseUse,"氧枪使用实绩管理")
	//2009-04-15
	L3RIGHT(btnAddLance,"氧枪新增按钮")
	L3RIGHT(btnDeleteLance,"氧枪删除按钮")
	//氧枪LanseBase
	L3RIGHT(LansebtnDefendStrat,"氧枪制作开始")
	L3RIGHT(LansebtnDefendEnd,"氧枪制作结束")
	L3RIGHT(LansebtnOn,"人工换上氧枪")
	L3RIGHT(LansebtnOff,"人工换下氧枪检查")
	L3RIGHT(LansebtnCheckCom,"下线检查完毕")
	//氧枪维护实绩管理LanceDefendMagFrm
	L3RIGHT(LanceDefendbtnQuery,"制作实绩实绩查询")
	L3RIGHT(LanceDefendbtnAddMain,"制作实绩实绩新增")
	L3RIGHT(LanceDefendbtnDelMain,"制作实绩实绩删除")
	L3RIGHT(LanceDefendbtnConfirmMain,"制作实绩实绩确认")
	L3RIGHT(LanceDefendbtnAddDetail,"再次上线枪头维护新增")
	L3RIGHT(LanceDefendbtnDelDetail,"再次上线枪头维护删除")
	L3RIGHT(LanceDefendbtnConfirmDetail,"再次上线枪头维护确认")
	//氧枪检查实绩管理LanceCheckMagFrm
	L3RIGHT(LanceCheckbtnAdd,"氧枪检查实绩新增")
	L3RIGHT(LanceCheckbtnDel,"氧枪检查实绩删除")
	L3RIGHT(LanceCheckbtnConfirm,"氧枪检查实绩确认")
	L3RIGHT(LanceCheckbtnQuery,"氧枪检查实绩查询")
	//氧枪使用实绩管理界面LanceUseMagFrm
	L3RIGHT(LanceUsebtnAdd,"氧枪使用实绩新增")
	L3RIGHT(LanceUsebtnDel,"氧枪使用实绩删除")
	L3RIGHT(LanceUsebtnConfirm,"氧枪使用实绩确认")
	L3RIGHT(LanceUsebtnQuery,"氧枪使用实绩查询")
	
	/**********************************工器具******************************/

	//2009-03-27 liuzhiqiang
	L3RIGHT(NCTelQuery,"NC电文查询")
	L3RIGHT(NCSteelTel,"NC钢坯电文补发")
	L3RIGHT(NCIronTel,"NC铁次电文补发")

	//设备校准管理 [2009-04-15]
	L3RIGHT(EquipAdjustMagFrm,"设备校准管理")

	L3RIGHT(EquipCoilCheckFrm,"电磁搅拌线圈检查")
	L3RIGHT(EquipColletCheckFrm,"电极夹头检查")
	L3RIGHT(EquipLanceCheckFrm,"氧枪口检查")
	L3RIGHT(EquipLevelCheckFrm,"铸机液面检查")
	L3RIGHT(EquipMoldArcCheckFrm,"结晶器对弧检查")
	L3RIGHT(EquipOscillateCheckFrm,"振动装置检查")
	L3RIGHT(EquipPoleCheckFrm,"电极孔检查")
	L3RIGHT(EquipRollerCheckFrm,"拉矫机运行检查")
	L3RIGHT(EquipSectArcCheckFrm,"扇形段对弧")
	L3RIGHT(EquipAdjustParaStdFrm,"设备校准参数标准")
	L3RIGHT(EquipAdjustMagFrm,"称重设备校准管理")
	L3RIGHT(EquipAdjustSetFrm,"称重设备校准设置")

	L3RIGHT(btnEquipCoilCheck,"电磁搅拌线圈检查--按钮")
	L3RIGHT(btnEquipColletCheck,"电极夹头检查--按钮")
	L3RIGHT(btnEquipLanceCheck,"氧枪口检查--按钮")
	L3RIGHT(btnEquipLevelCheck,"铸机液面检查--按钮")
	L3RIGHT(btnEquipMoldArcCheck,"结晶器对弧检查--按钮")
	L3RIGHT(btnEquipOscillateCheck,"振动装置检查--按钮")
	L3RIGHT(btnEquipPoleCheck,"电极孔检查--按钮")
	L3RIGHT(btnEquipRollerCheck,"拉矫机运行检查--按钮")
	L3RIGHT(btnEquipSectArcCheck,"扇形段对弧--按钮")
	L3RIGHT(btnEquipAdjustParaStd,"设备校准参数标准--按钮")
	L3RIGHT(btnEquipAdjustMag,"称重设备校准管理--按钮")
	L3RIGHT(btnEquipAdjustSet,"称重设备校准设置--按钮")

	//2009-04-23
	L3RIGHT(EquipCleaningDataFrm,"汽化冷却排污管理")
	L3RIGHT(EquipRuntimeFrm,"汽化冷却除尘管理")
	L3RIGHT(EquipSupplyWaterFrm,"汽化冷却补水管理")

	//L3RIGHT(btnEquipCleaningDataFrm,"汽化冷却排污管理--按钮")
	//L3RIGHT(btnEquipRuntimeFrm,"汽化冷却除尘管理--按钮")
	L3RIGHT(btnEquipSupplyWaterFrm,"汽化冷却补水管理--按钮")

	//Modify begin 2011-02-15 by llj
	L3RIGHT(LF5Mag,"5#LF炉工序")
	L3RIGHT(CCM7Mag,"7#连铸工序")
	L3RIGHT(ProductGradeQueryFrm,"生产实绩查询")
	L3RIGHT(AlloyStoreMagQuery,"合金料仓料种维护信息查询")
	L3RIGHT(DESbtnDelete,"DES炉实绩查询--加料数据删除按钮")
	L3RIGHT(BOFbtnDelete,"BOF炉实绩查询--加料数据删除按钮")
	L3RIGHT(LFbtnDelete,"LF炉实绩查询--加料数据删除按钮")
	L3RIGHT(RHbtnDelete,"RH炉实绩查询--加料数据删除按钮")
	L3RIGHT(CCMbtnDelete,"CCM炉实绩查询--加料数据删除按钮")
	L3RIGHT(CCMbtnLadleCancel,"连铸炉次大包数据取消按钮")
	L3RIGHT(CCMbtnLadleOk,"连铸炉次大包数据确定按钮")
	L3RIGHT(AlloyYLStoreMaintain,"5#LF合金料仓料种维护")
	L3RIGHT(AlloyYLStoreMag,"5#LF合金原料库管理")
	L3RIGHT(SteelGradeGlobalMainten,"质量管理--制造标准复制") 
	L3RIGHT(BofSteelWaterToBXGJudge,"转炉钢水直送不锈钢质量判定")
	L3RIGHT(BofSteelWaterToBXGJudgeQuery,"转炉钢水直送不锈钢质量判定查询")
	//Modify end

	//Add by hyh 2012-03-29
	L3RIGHT(SteelGradeStdMaintainMag,"钢种标准维护")
	L3RIGHT(IronWarn,"铁水进站样报警显示")
	L3RIGHT(PassWordLock,"过期密码解锁")
	//End

	//Add by hyh 2012-05-10
	L3RIGHT(LF4Mag,"4#LF炉工序")
	L3RIGHT(CCM6Mag,"6#连铸工序")
	//End

	//add by hyh 2012-06-06
	L3RIGHT(LF4AlloyYLStoreMag,"4#LF合金原料库管理")
	L3RIGHT(LF4AlloyYLStoreMaintain,"4#LF合金料仓料种维护")
	//end

		//Add by hyh 2012-05-10
	L3RIGHT(AODMag,"AOD炉工序")
	L3RIGHT(MenuAODMag,"AOD炉操作菜单")
	L3RIGHT(AODbtnConfirm,"AOD炉实绩数据确认")
	L3RIGHT(AODCheck,"AOD炉加料数据修正")
	//End

	//Add by hyh 2012-05-10
	L3RIGHT(DePMag,"脱磷站工序")
	L3RIGHT(menuDEP,"脱磷站操作菜单")
	L3RIGHT(DePbtnConfirm,"脱磷站实绩数据确认")
	L3RIGHT(ChangeSteel,"改钢")
	//End


END_L3ACCESSCONTROL_MAP(CBaseData_Mag)

CBaseData_Mag::CBaseData_Mag(void)
{
}

CBaseData_Mag::~CBaseData_Mag(void)
{
}

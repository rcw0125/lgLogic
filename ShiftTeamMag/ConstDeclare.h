
/********************************************************************************************
*  文件名：ConstDeclare.h																	*
*  项  目：邢钢MES系统：公共模块												*
*  版权所有 (C) 2008-2009 攀信软件分公司													*
*  创建人：	唐毅																				*
*  日  期：	2008-11-11																	*
*  修改人：																					*
*  日  期：																					*
*  描  述：该文件为“常量定义”类，保存常量数据												*
*  版  本：V1.0																				*
*********************************************************************************************/ 


const CString MATERIAL_TYPE_STEEL = _T("CSteel_Data");
const CString MATERIAL_TYPE_IRON  = _T("CIron_Data");
const CString MATERIAL_TYPE_ALLOY = _T("CAlloy_Data");
const CString MATERIAL_TYPE_SCRAP = _T("CScrap_Data");
const CString MATERIAL_TYPE_BLOOM = _T("CBloom_Data");
const CString MATERIAL_TYPE_BULK  = _T("CBulk_Data");

//工序：0：铁水，1：混铁炉，2：转炉，3：炉后，4：LF，5：RH，6：铸机,7：钢坯库,8:原料库

const CString UNIT_TYPE_IRON	= _T("0");//铁水区域
const CString UNIT_TYPE_MIXF	= _T("1");//混铁炉区域
const CString UNIT_TYPE_BOF		= _T("2");//转炉区域
const CString UNIT_TYPE_TAPSIDE	= _T("3");//炉后区域
const CString UNIT_TYPE_LF		= _T("4");//LF区域
const CString UNIT_TYPE_RH		= _T("5");//RH区域
const CString UNIT_TYPE_CASTER  = _T("6");//铸机区域
const CString STROE_TYPE_BLOOM   = _T("7");//钢坯库区
const CString STROE_TYPE_MATERIAL  = _T("8");//原料库区


const L3SHORT UNIT_AREA_IRON	= 0;//铁水区域
const L3SHORT UNIT_AREA_MIXF	= 1;//混铁炉区域
const L3SHORT UNIT_AREA_BOF		= 2;//转炉区域
const L3SHORT UNIT_AREA_TAPSIDE	= 3;//炉后区域
const L3SHORT UNIT_AREA_LF		= 4;//LF区域
const L3SHORT UNIT_AREA_RH		= 5;//RH区域
const L3SHORT UNIT_AREA_CASTER  = 6;//铸机区域
const L3SHORT UNIT_AREA_BLOOM   = 7;//钢坯库区
const L3SHORT UNIT_AREA_MATERIAL  = 8;//原料库区

//机组、缓存编码，当机组只有一个加工区时，其加工区编码与机组编码一致，有多个加工位时在机组编码后加两位流水号
//缓存按照机组材料下线时根据工艺路径直接将材料放入下工序进入缓存中的方式编码

const CString UNIT_ID_IRON				= _T("S01");    //进厂铁水，入厂铁水库区

const CString UNIT_ID_1DES				= _T("S02");    //1#脱硫工序 2009-10-20
const CString UNIT_ID_2DES				= _T("S03");    //2#脱硫工序 2009-10-20

const CString UNIT_ID_IRON_CACHE		= _T("S00N01"); //进厂铁水出库缓存
const CString UNIT_ID_1MIX				= _T("S11");    //1#混铁炉机组，1#混铁炉加工位
const CString UNIT_ID_2MIX				= _T("S12");	//2#混铁炉机组，2#混铁炉加工位
//add by hyh 2012-04-03 因新增3#混铁炉
const CString UNIT_ID_3MIX				= _T("S13");	//3#混铁炉机组，3#混铁炉加工位
//end
const CString UNIT_ID_MIX_CACHE			= _T("S10N01");	//混铁炉出铁或者直兑铁水缓存

const CString UNIT_ID_1BOF				= _T("S21");    //1#转炉机组，1#转炉加工位
const CString UNIT_ID_2BOF				= _T("S22");    //2#转炉机组，2#转炉加工位
const CString UNIT_ID_3BOF				= _T("S23");    //3#转炉机组，3#转炉加工位
const CString UNIT_ID_4BOF				= _T("S24");    //4#转炉机组，4#转炉加工位

const CString UNIT_ID_1TAPSIDE_CACHE	= _T("S31P01"); //1#转炉炉后上线前缓存
const CString UNIT_ID_2TAPSIDE_CACHE	= _T("S32P01"); //2#转炉炉后上线前缓存
const CString UNIT_ID_3TAPSIDE_CACHE	= _T("S33P01"); //3#转炉炉后上线前缓存
const CString UNIT_ID_4TAPSIDE_CACHE	= _T("S34P01"); //4#转炉炉后上线前缓存
const CString UNIT_ID_1TAPSIDE			= _T("S31");	//1#转炉炉后机组，1#转炉炉后加工位
const CString UNIT_ID_2TAPSIDE			= _T("S32");	//2#转炉炉后机组，2#转炉炉后加工位
const CString UNIT_ID_3TAPSIDE			= _T("S33");	//3#转炉炉后机组，3#转炉炉后加工位
const CString UNIT_ID_4TAPSIDE			= _T("S34");	//4#转炉炉后机组，4#转炉炉后加工位

const CString UNIT_ID_1LF_CACHE			= _T("S41P01");	//1#LF炉上线前缓存
const CString UNIT_ID_2LF_CACHE			= _T("S42P01");	//2#LF炉上线前缓存
const CString UNIT_ID_3LF_CACHE			= _T("S43P01");	//3#LF炉上线前缓存
//Modify by llj 2011-1-18 因改造修改
const CString UNIT_ID_5LF_CACHE			= _T("S45P01");	//5#LF炉上线前缓存
//add by hyh 2012-05-09 新增4#LF
const CString UNIT_ID_4LF_CACHE			= _T("S44P01");	//4#LF炉上线前缓存

const CString UNIT_ID_1LF				= _T("S41");    //1#LF炉机组，1#LF炉加工位
const CString UNIT_ID_2LF				= _T("S42");	//2#LF炉机组，2#LF炉加工位
const CString UNIT_ID_3LF				= _T("S43");	//3#LF炉机组，3#LF炉加工位
//Modify by llj 2011-1-18 因改造修改
const CString UNIT_ID_5LF				= _T("S45");	//5#LF炉机组，5#LF炉加工位
//add by hyh 2012-05-09 新增4#LF
const CString UNIT_ID_4LF				= _T("S44");	//4#LF炉机组，4#LF炉加工位

const CString UNIT_ID_1RH_CACHE			= _T("S51P01");	//1#RH炉上线前缓存
const CString UNIT_ID_1RH				= _T("S51");	//1#RH炉机组，1#RH炉加工位

const CString UNIT_ID_1CASTER_CACHE		= _T("S61P01");	//1#铸机上线前缓存
const CString UNIT_ID_2CASTER_CACHE		= _T("S62P01");	//2#铸机上线前缓存
const CString UNIT_ID_3CASTER_CACHE		= _T("S63P01");	//3#铸机上线前缓存
const CString UNIT_ID_4CASTER_CACHE		= _T("S64P01");	//4#铸机上线前缓存
const CString UNIT_ID_5CASTER_CACHE		= _T("S65P01");	//5#铸机上线前缓存
//Modify by llj 2011-1-18 因改造修改
const CString UNIT_ID_7CASTER_CACHE		= _T("S67P01");	//7#铸机上线前缓存
//Modify by hyh 2012-05-09 因改造修改
const CString UNIT_ID_6CASTER_CACHE		= _T("S66P01");	//6#铸机上线前缓存


const CString UNIT_ID_1CASTER			= _T("S61");	//1#铸机机组，1#铸机加工位
const CString UNIT_ID_2CASTER			= _T("S62");	//2#铸机机组，2#铸机加工位
const CString UNIT_ID_3CASTER			= _T("S63");	//3#铸机机组，3#铸机加工位
const CString UNIT_ID_4CASTER			= _T("S64");	//4#铸机机组，4#铸机加工位
const CString UNIT_ID_5CASTER			= _T("S65");	//5#铸机机组，5#铸机加工位
//Modify by llj 2011-1-18 因改造修改
const CString UNIT_ID_7CASTER			= _T("S67");	//7#铸机机组，7#铸机加工位
//Modify by hyh 2012-05-09 因改造修改
const CString UNIT_ID_6CASTER			= _T("S66");	//6#铸机机组，6#铸机加工位

const CString UNIT_ID_BLOOM_PCACHE		= _T("S71P01");	//铸机钢坯入库缓存
const CString STORE_ID_BLOOM			= _T("S71");	//钢坯库
const CString STORE_ID_BLOOM_STOCK		= _T("S71A01");	//钢坯库库区
const CString STORE_ID_BLOOM_COOL		= _T("S71B01");	//钢坯库缓冷区
const CString STORE_ID_BLOOM_CACHE		= _T("S71N01");	//钢坯库出库缓存

const CString STORE_ID_ALLOY_PCACHE	= _T("S81P01");	//合金原料库入库缓存
const CString STORE_ID_ALLOY		= _T("S81");	//合金原料库

//A:1#转炉高仓;B:烘烤炉;C:1#LF合金高仓;D:2#LF合金高仓;E:LF公用高仓
//1#转炉高仓
const CString STORE_ID_ALLOY_HIGH_1		= _T("S81A01");	//合金原料库1#转炉高仓1#料仓
const CString STORE_ID_ALLOY_HIGH_2		= _T("S81A02");	//合金原料库1#转炉高仓2#料仓
const CString STORE_ID_ALLOY_HIGH_3		= _T("S81A03");	//合金原料库1#转炉高仓3#料仓
const CString STORE_ID_ALLOY_HIGH_4		= _T("S81A04");	//合金原料库1#转炉高仓4#料仓
const CString STORE_ID_ALLOY_HIGH_5		= _T("S81A05");	//合金原料库1#转炉高仓5#料仓
const CString STORE_ID_ALLOY_HIGH_6		= _T("S81A06");	//合金原料库1#转炉高仓6#料仓
const CString STORE_ID_ALLOY_HIGH_7		= _T("S81A07");	//合金原料库1#转炉高仓7#料仓
const CString STORE_ID_ALLOY_HIGH_8		= _T("S81A08");	//合金原料库1#转炉高仓8#料仓

//烘烤炉
const CString STORE_ID_ALLOY_HOT_1		= _T("S81B01");	//合金原料库烘烤炉1#料仓
const CString STORE_ID_ALLOY_HOT_2		= _T("S81B02");	//合金原料库烘烤炉2#料仓
const CString STORE_ID_ALLOY_HOT_3		= _T("S81B03");	//合金原料库烘烤炉3#料仓
const CString STORE_ID_ALLOY_HOT_4		= _T("S81B04");	//合金原料库烘烤炉4#料仓
const CString STORE_ID_ALLOY_HOT_5		= _T("S81B05");	//合金原料库烘烤炉5#料仓
const CString STORE_ID_ALLOY_HOT_6		= _T("S81B06");	//合金原料库烘烤炉6#料仓
const CString STORE_ID_ALLOY_HOT_7		= _T("S81B07");	//合金原料库烘烤炉7#料仓
const CString STORE_ID_ALLOY_HOT_8		= _T("S81B08");	//合金原料库烘烤炉8#料仓
const CString STORE_ID_ALLOY_HOT_9		= _T("S81B09");	//合金原料库烘烤炉9#料仓
const CString STORE_ID_ALLOY_HOT_10		= _T("S81B10");	//合金原料库烘烤炉10#料仓
const CString STORE_ID_ALLOY_HOT_11		= _T("S81B11");	//合金原料库烘烤炉11#料仓
const CString STORE_ID_ALLOY_HOT_12		= _T("S81B12");	//合金原料库烘烤炉12#料仓
const CString STORE_ID_ALLOY_HOT_13		= _T("S81B13");	//合金原料库烘烤炉13#料仓
const CString STORE_ID_ALLOY_HOT_14		= _T("S81B14");	//合金原料库烘烤炉14#料仓
const CString STORE_ID_ALLOY_HOT_15		= _T("S81B15");	//合金原料库烘烤炉15#料仓
const CString STORE_ID_ALLOY_HOT_16		= _T("S81B16");	//合金原料库烘烤炉16#料仓
const CString STORE_ID_ALLOY_HOT_17		= _T("S81B17");	//合金原料库烘烤炉17#料仓
const CString STORE_ID_ALLOY_HOT_18		= _T("S81B18");	//合金原料库烘烤炉18#料仓

//1#LF炉高仓
const CString STORE_ID_ALLOY_1LF_1		= _T("S81C01");	//合金原料库1#LF炉高仓1#料仓
const CString STORE_ID_ALLOY_1LF_2		= _T("S81C02");	//合金原料库1#LF炉高仓2#料仓
const CString STORE_ID_ALLOY_1LF_3		= _T("S81C03");	//合金原料库1#LF炉高仓3#料仓
const CString STORE_ID_ALLOY_1LF_4		= _T("S81C04");	//合金原料库1#LF炉高仓4#料仓
const CString STORE_ID_ALLOY_1LF_5		= _T("S81C05");	//合金原料库1#LF炉高仓5#料仓
const CString STORE_ID_ALLOY_1LF_6		= _T("S81C06");	//合金原料库1#LF炉高仓6#料仓
const CString STORE_ID_ALLOY_1LF_7		= _T("S81C07");	//合金原料库1#LF炉高仓7#料仓
const CString STORE_ID_ALLOY_1LF_8		= _T("S81C08");	//合金原料库1#LF炉高仓8#料仓
const CString STORE_ID_ALLOY_1LF_9		= _T("S81C09");	//合金原料库1#LF炉高仓9#料仓
const CString STORE_ID_ALLOY_1LF_10		= _T("S81C10");	//合金原料库1#LF炉高仓10#料仓

//2#LF炉高仓
const CString STORE_ID_ALLOY_2LF_1		= _T("S81D01");	//合金原料库1#LF炉高仓1#料仓
const CString STORE_ID_ALLOY_2LF_2		= _T("S81D02");	//合金原料库1#LF炉高仓2#料仓
const CString STORE_ID_ALLOY_2LF_3		= _T("S81D03");	//合金原料库1#LF炉高仓3#料仓
const CString STORE_ID_ALLOY_2LF_4		= _T("S81D04");	//合金原料库1#LF炉高仓4#料仓
const CString STORE_ID_ALLOY_2LF_7		= _T("S81D05");	//合金原料库1#LF炉高仓5#料仓
const CString STORE_ID_ALLOY_2LF_6		= _T("S81D06");	//合金原料库1#LF炉高仓6#料仓

//1#2#LF炉公用高仓
const CString STORE_ID_ALLOY_12LF_1		= _T("S81E01");	//合金原料库公用高仓1#料仓
const CString STORE_ID_ALLOY_12LF_2		= _T("S81E02");	//合金原料库公用高仓2#料仓
const CString STORE_ID_ALLOY_12LF_3		= _T("S81E03");	//合金原料库公用高仓3#料仓
const CString STORE_ID_ALLOY_12LF_4		= _T("S81E04");	//合金原料库公用高仓4#料仓
const CString STORE_ID_ALLOY_12LF_5		= _T("S81E05");	//合金原料库公用高仓5#料仓
const CString STORE_ID_ALLOY_12LF_6		= _T("S81E06");	//合金原料库公用高仓6#料仓
const CString STORE_ID_ALLOY_12LF_7		= _T("S81E07");	//合金原料库公用高仓7#料仓


const CString STORE_ID_ALLOY_CACHE	= _T("S81N01");	//合金原料库出库缓存

const CString STORE_ID_SCRAP_PCACHE	= _T("S82P01");	//废钢生铁原料库入库缓存
const CString STORE_ID_SCRAP		= _T("S82");	//废钢生铁原料库
const CString STORE_ID_SCRAP_CACHE	= _T("S82N01");	//废钢生铁原料库出库缓存


const CString STORE_ID_BULK_PCACHE	= _T("S83P01");	//散状料原料库入库缓存
const CString STORE_ID_BULK			= _T("S83");	//散状料原料库
const CString STORE_ID_BULK_CACHE	= _T("S83N01");	//散状料原料库出库缓存

const CString STORE_ID_BULK_HIGH_1	= _T("S83A01");	//散状料原料库1#转炉高仓1#料仓
const CString STORE_ID_BULK_HIGH_2	= _T("S83A02");	//散状料原料库1#转炉高仓2#料仓
const CString STORE_ID_BULK_HIGH_3	= _T("S83A03");	//散状料原料库1#转炉高仓3#料仓
const CString STORE_ID_BULK_HIGH_4	= _T("S83A04");	//散状料原料库1#转炉高仓4#料仓
const CString STORE_ID_BULK_HIGH_5	= _T("S83A05");	//散状料原料库1#转炉高仓5#料仓
const CString STORE_ID_BULK_HIGH_6	= _T("S83A06");	//散状料原料库1#转炉高仓6#料仓
const CString STORE_ID_BULK_HIGH_7	= _T("S83A07");	//散状料原料库1#转炉高仓7#料仓
const CString STORE_ID_BULK_HIGH_8	= _T("S83A08");	//散状料原料库1#转炉高仓8#料仓


//NC通讯对象URI
const CString NC_COMMUNICATOR_URI	= _T("XGMESLogic\\BaseDataMag\\CNCCommunicator\\NCComm");
//班别管理逻辑对象
const CString SHIFT_MAG_URI			= _T("XGMESLogic\\ShiftTeamMag\\CShiftMag\\1");

//物料价格库
const CString CMATERIAL_PRICE_URI	= _T("XGMESLogic\\BaseDataMag\\CMaterial_Price");



//材料实体类URI
const CString MATERIAL_BFIRON_URI	= _T("MES\\MaterialData\\CBFIron");
const CString MATERIAL_IRON_URI		= _T("MES\\MaterialData\\CIron_Data");
const CString MATERIAL_STEEL_URI	= _T("MES\\MaterialData\\CSteel_Data");
const CString ALLOY_DATA_CLASS_URI	= _T("MES\\MaterialData\\CAlloy_Data");//合金数据实体类
const CString SCRAP_DATA_CLASS_URI	= _T("MES\\MaterialData\\CScrap_Data");//废钢数据实体类
const CString BULK_DATA_CLASS_URI	= _T("MES\\MaterialData\\CBulk_Data");//散状料数据实体类
const CString BLOOM_DATA_CLASS_URI	= _T("MES\\MaterialData\\CBloom_Data");//方坯数据实体类

//材料缓存类URI
const CString XGINTERCACHE_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache");		// 通用机组间材料缓存类
const CString XGSTOREAREA_URI = _T("XGMESLogic\\BaseDataMag\\XGStoreArea");			// 通用库区类
const CString XGPRODUCEAREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea");		// 通用生产机组工位类

//调度模块实体类URI
const CString DISPATCH_STEEL_BACK_CLASS_URI	= _T("XGMESLogic\\DispatchMag\\CDisp_SteelBack_App");
const CString DISPATCH_STEEL_DIV_CLASS_URI	= _T("XGMESLogic\\DispatchMag\\CDisp_SteelDiv_App");
const CString DISPATCH_STEEL_EXE_CLASS_URI		= _T("XGMESLogic\\DispatchMag\\CDisp_SteelExchange_App");
const CString DISPATCH_STEEL_TURN_CLASS_URI		= _T("XGMESLogic\\DispatchMag\\CDisp_SteelTurn_App");
const CString DISPATCH_LOG_CLASS_URI		= _T("XGMESLogic\\DispatchMag\\CDisp_Duty_Note");
const CString DISPATCH_OBJ_URI					= _T("XGMESLogic\\DispatchMag\\CDispatch_Mag\\Dispatch_Mag");

//计划模块实体类URI
const CString PLAN_ORDER_CLASS_URI			= _T("XGMESLogic\\PlanMag\\CPlan_Order");
const CString PLAN_CUR_PREHEATID_CLASS_URI	= _T("XGMESLogic\\PlanMag\\CPlan_Cur_PreHeatID");
const CString PLAN_CASTING_CLASS_URI		= _T("XGMESLogic\\PlanMag\\CPlan_Casting");
const CString PLAN_TAPPING_CLASS_URI		= _T("XGMESLogic\\PlanMag\\CPlan_Tapping");
const CString PLAN_TAPPING_ACT_CLASS_URI	= _T("XGMESLogic\\PlanMag\\CPlan_Tapping_Act");
const CString PLAN_BOF_CLASS_URI			= _T("XGMESLogic\\PlanMag\\CPlan_BOF_Status");
const CString PLAN_BOF_NON_PROC_CLASS_URI	= _T("XGMESLogic\\PlanMag\\CPlan_BOFNon_Proc_Time");
const CString PLAN_EQUIMENT_CLASS_URI		= _T("XGMESLogic\\PlanMag\\CPlan_Equipment");
//计划管理逻辑对象名
const CString PLAN_OBJ_URI					= _T("XGMESLogic\\PlanMag\\CPlan_Mag\\Plan_Mag");

//用于存储用户密码信息，实现定期锁定未修改密码的账户
//add by hyh 2012-03-31
const CString UserPwd_Lock_URI = _T("XGMESLogic\\BaseDataMag\\CBase_UserPwd_Lock");
//end



//质量模块实体类URI
const CString QA_STG_RELATION_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_SteelGradeIndex_R");
const CString QA_PROD_SHEET_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_Product_Sheet");
const CString QA_CAL_WEIGHT_CLASS_URI	= _T("XGMESLogic\\QualityMag\\CQA_Cal_Weight_Std");
const CString QA_UNIT_PROC_TIME_CLASS_URI	= _T("XGMESLogic\\QualityMag\\CQA_Unit_Proc_Time");
const CString QA_UNIT_ROUTE_CLASS_URI	= _T("XGMESLogic\\QualityMag\\CQA_Unit_Route");
const CString QA_UNIT_TRANS_TIME_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_Unit_Trans_Time");
const CString QA_HOT_JUDGE_CLASS_URI		=_T("XGMESLogic\\QualityMag\\CQA_Bloom_HotJudge_Data");
const CString QA_FIN_JUDGE_CLASS_URI		=_T("XGMESLogic\\QualityMag\\CQA_Bloom_FinJudge_Data");
//质量模块制造标准实体类URI
const CString QA_BOF_STD_AR_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ar");
const CString QA_BOF_STD_BASE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Base");
const CString QA_BOF_STD_BLOW_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Blow");
const CString QA_BOF_STD_BLOWO2_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_BlowO2");
const CString QA_BOF_STD_BULK_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Bulk");
const CString QA_BOF_STD_FEED_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Feed");
const CString QA_BOF_STD_INCTR_ELE_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_InCtr_Ele");
const CString QA_BOF_STD_INTOCONVER_CLASS_URI		= _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_InToConver");
const CString QA_BOF_STD_LADLE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ladle");
const CString QA_BOF_STD_SLAG_ELE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Slag_Ele");
const CString QA_BOF_STD_TAPPING_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Tapping");
 
const CString QA_LF_STD_ALLOY_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Alloy");
const CString QA_LF_STD_BASE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Base");
const CString QA_LF_STD_FEED_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Feed");
const CString QA_LF_STD_INCTR_ELE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_InCtr_Ele");
const CString QA_LF_STD_LADLE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Ladle");
const CString QA_LF_STD_PROC_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Proc");
const CString QA_LF_STD_SLAG_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Slag");
const CString QA_LF_STD_SLAG_ELE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_LF_Std_Slag_Ele");

const CString QA_RH_STD_ALLOY_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_Alloy");
const CString QA_RH_STD_BASE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_Base");
const CString QA_RH_STD_FEED_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_Feed");
const CString QA_RH_STD_INCTR_ELE_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_InCtr_Ele");
const CString QA_RH_STD_PROC_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_RH_Std_Proc");

const CString QA_CCM_STD_FLUX_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Flux");
const CString QA_CCM_STD_PROC_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Proc");
const CString QA_CCM_STD_PRODPROC_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_ProdProc");
const CString QA_CCM_STD_SPEC_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Spec");
const CString QA_CCM_STD_SPEED_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Speed");
const CString QA_CCM_STD_TUNDISH_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Tundish");
const CString QA_CCM_STD_BASE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Caster_Std_Base");

const CString QA_LAB_SHEET_APPID_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Lab_Sheet_AppID");
const CString QA_LAB_SHEET_APP_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Lab_Sheet_App");
const CString QA_LAB_ELEMENT_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Lab_Element");
const CString QA_LAB_ELEMENT_TEXT_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CQA_Lab_Element_Text");
const CString QA_LAB_S_PRINT_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Lab_S_Print");
const CString QA_LAB_SLAGELE_CLASS_URI		        = _T("XGMESLogic\\QualityMag\\CQA_Lab_SlagEle");
const CString QA_LAB_SLAGELE_TEXT_CLASS_URI			= _T("XGMESLogic\\QualityMag\\CQA_Lab_SlagEle_Text");
const CString BASE_ADDRESS_BULK_CLASS_URI		    = _T("XGMESLogic\\QualityMag\\CBase_Address_Bulk_Relation");


const CString CHEMICAL_EXCEPTIONAL_CODE = _T("501");
//钢包重量
const L3LONG OLD_LADLE_WEIGHT = 46000;
const L3LONG NEW_LADLE_WEIGHT = 76000;
const L3LONG BALANCE_WEIGHT = 10000;

const CString EMPTY_ERR = _T("Empty");


//工序类URI
const CString BFIronInLog_URI = _T("XGMESLogic\\BFMag\\CBFIronInLog");	// 入厂铁水入库记录
const CString BFIronOutLog_URI = _T("XGMESLogic\\BFMag\\CBFIronOutLog"); // 入厂铁水出库记录
const CString MIXFMag_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Mag");	// 混铁炉工序管理类
const CString MIXFUnit_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag"); // 混铁炉机组
const CString MIXFArea_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Area"); // 混铁炉机组加工位
const CString MIXF_FeedLog_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Feed_Log"); // 混铁日志

//工序对象URI
const CString BFIronStore_URI = _T("XGMESLogic\\BFMag\\CBF_Iron_Mag\\BFIronMag");	// 入厂铁水库房
const CString BFIronStoreArea_URI = _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S01");	// 入厂铁水库区
const CString BFIronStoreOutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S00N01"); // 入厂铁水库后缓存
const CString BFIronCastCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\Cast"); // 到铸铁去的铁水缓存

const CString MIXFMagObj_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Mag\\MIFMag"); // 混铁区域管理对象
const CString MIXFProduceUnit1_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag\\S11");	// 1号混铁炉机组
const CString MIXFProduceUnit2_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag\\S12");	// 2号混铁炉机组
const CString MIXFProduceArea1_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Area\\S11"); // 1号混铁炉加工位
const CString MIXFProduceArea2_URI = _T("XGMESLogic\\MIXFMag\\CMIF_Area\\S12"); // 1号混铁炉加工位

const CString MIXFProduceCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S10N01"); // 混铁炉后铁包缓存区


//转炉工序管理类
const CString BOF_CLASS_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag");
//转炉工序实绩类
const CString BOF_BASE_DATA_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Base_Data"); // 转炉炉次基本数据
const CString BOF_FEED_DATA_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Feed_Data");	// 转炉炉次原料数据
const CString BOF_PROC_STATUS_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Process_Status"); // 转炉工序事件数据
const CString BOF_ADDITION_DATA_CLASS_URI	= _T("XGMESLogic\\BOFMag\\CBOF_Addition_Data"); // 转炉加料数据
const CString BOF_TOP_BLOWING_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Top_Blowing"); // 顶吹记录
const CString BOF_BOTTOM_BLOWING_CLASS_URI	= _T("XGMESLogic\\BOFMag\\CBOF_Bottom_Blowing"); // 顶吹记录
const CString BOF_OXYGEN_DATA_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Oxygen_Data"); // 定氧事件记录
const CString BOF_TEMP_DATA_CLASS_URI		= _T("XGMESLogic\\BOFMag\\CBOF_Temp_Data"); // 测温事件记录
const CString BOF_EQUIPMENT_STATUS_CLASS_URI = _T("XGMESLogic\\BOFMag\\CBOF_Equipment_Status"); // 设备状态日志
const CString BOF_PROCESS_DATA_CLASS_URI	= _T("XGMESLogic\\BOFMag\\CBOF_Process_Data"); // 炼钢过程数据
const CString UNIT_DUTY_CLASS_URI	= _T("XGMESLogic\\BOFMag\\CDuty_Definition"); // 机组人员


//转炉工序对象URI
//转炉机组
const CString BOF1_UNIT_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\S21");
const CString BOF2_UNIT_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\S22");
const CString BOF3_UNIT_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\S23");
const CString BOF4_UNIT_URI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\S24");

// 转炉加工工位
const CString BOF1_AREA_URI = _T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\S21");
const CString BOF2_AREA_URI = _T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\S22");
const CString BOF3_AREA_URI = _T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\S23");
const CString BOF4_AREA_URI = _T("XGMESLogic\\BOFMag\\CBOF_Prod_Area\\S24");

//转炉出口缓存
const CString BOF1_OutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S31P01");
const CString BOF2_OutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S32P01");
const CString BOF3_OutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S33P01");
const CString BOF4_OutCache_URI = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S34P01");

//炉后工序管理类
const CString BOF_SIDE_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag");
//炉后机组
const CString TAPSIDE1_UNIT_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag\\S31");
const CString TAPSIDE2_UNIT_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag\\S32");
const CString TAPSIDE3_UNIT_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag\\S33");
const CString TAPSIDE4_UNIT_URI = _T("XGMESLogic\\TapSideMag\\CTap_Unit_Mag\\S34");
//炉后机组处理工位
const CString TAPSIDE1_AREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea\\S31");
const CString TAPSIDE2_AREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea\\S32");
const CString TAPSIDE3_AREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea\\S33");
const CString TAPSIDE4_AREA_URI = _T("XGMESLogic\\BaseDataMag\\XGProduceArea\\S34");

//炉后实绩类
const CString TAP_BASE_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Base_Data");
const CString TAP_PROCESS_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Process_Data");
const CString TAP_ADDITION_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Addition_Data");
const CString TAP_LADLE_WEIGHT_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Ladle_Weight");
const CString TAP_OXYGEN_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Oxygen_Data");
const CString TAP_TEMP_DATA_CLASS_URI = _T("XGMESLogic\\TapSideMag\\CTap_Temp_Data");

//LF工序管理类
const CString LF_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag");
const CString LF_AREA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Prod_Area");

//LF机组
const CString LF1_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S41");
const CString LF2_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S42");
const CString LF3_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S43");
//Modify by llj 2011-1-18 因改造修改
const CString LF5_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S45");//5#LF
//Modify by hyh 2012-05-09 因改造修改
const CString LF4_UNIT_URI = _T("XGMESLogic\\LFMag\\CLF_Unit_Mag\\S44");//4#LF

//LF工序实绩类
const CString LF_BASE_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Base_Data");
const CString LF_ADDITION_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Addition_Data");
const CString LF_EQUIPMENT_STATUS_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Equipment_Status");
const CString LF_FEED_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Feed_Data");
const CString LF_HEATREMARK_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_HeatRemark");
const CString LF_LADLE_WEIGHT_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Ladle_Weight");
const CString LF_OXYGEN_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Oxygen_Data");
const CString LF_PROCESS_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Process_Data");
const CString LF_PROCESS_STATUS_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Process_Satus");
const CString LF_TEMP_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Temp_Data");
const CString LF_WIRE_DATA_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Wire_Data");
const CString LF_LADLE_INFO_CLASS_URI = _T("XGMESLogic\\LFMag\\CLF_Ladle_Info");

//RH工序管理类
const CString RH_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Unit_Mag");
const CString RH_AREA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Prod_Area");

//RH机组
const CString RH1_UNIT_URI =  _T("XGMESLogic\\RHMag\\CRH_Unit_Mag\\S51");

//RH工序实绩类
const CString RH_BASE_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Base_Data");
const CString RH_ADDITION_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Addition_Data");
const CString RH_EQUIPMENT_STATUS_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Equipment_Status");
const CString RH_FEED_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Feed_Data");
const CString RH_HEATREMARK_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_HeatRemark");
const CString RH_LADLE_WEIGHT_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Ladle_Weight");
const CString RH_OXYGEN_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Oxygen_Data");
const CString RH_PROCESS_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Process_Data");
const CString RH_PROCESS_STATUS_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Process_Satus");
const CString RH_TEMP_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Temp_Data");
const CString RH_WIRE_DATA_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Wire_Data");
const CString RH_LADLE_INFO_CLASS_URI = _T("XGMESLogic\\RHMag\\CRH_Ladle_Info");

//铸机工序管理类
const CString CCM_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag");
const CString CCM_AREA_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Prod_Area");

//铸机机组
const CString CCM1_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S61");
const CString CCM2_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S62");
const CString CCM3_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S63");
const CString CCM4_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S64");
const CString CCM5_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S65");
//Modify by llj 2011-1-18 因改造修改
const CString CCM7_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S67");//7#铸机
//Modify by hyh 2012-05-09 因改造修改
const CString CCM6_UNIT_URI = _T("XGMESLogic\\CCMMag\\CCCM_Unit_Mag\\S66");//6#铸机

//铸机实绩类
const CString CCM_BASE_DATA_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Base_Data");	
const CString CCM_BLOOM_DATA_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Bloom_Data");
const CString CCM_CASTING_DATA_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Casting_Data");
const CString CCM_CASTING_STRANDINFO_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Casting_StrandInfo");
const CString CCM_EQUIPMENT_STATUS_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Equipment_Status");
const CString CCM_HEAT_COOLING_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Cooling");
const CString CCM_HEAT_COVER_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Cover");
const CString CCM_HEAT_ELECSTIRRING_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_ElecStirring");
const CString CCM_HEAT_FAULTYGOODS_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_FaultyGoods");
const CString CCM_HEAT_HOLDTEMPMAT_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_HoldTempMat");
const CString CCM_HEAT_LADLE_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Ladle");
const CString CCM_HEAT_MOLD_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Mold");
const CString CCM_HEAT_PROTECTCASTING_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_ProtectCasting");
const CString CCM_HEAT_PROTECTMAT_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_ProtectMat");
const CString CCM_HEAT_PROTECTSLAG_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_ProtectSlag");
const CString CCM_HEAT_REMARK_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Remark");
const CString CCM_HEAT_SPEED_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Speed");
const CString CCM_HEAT_STRANDINFO_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo");
const CString CCM_HEAT_TUNDISHTEMP_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Heat_TundishTemp");
const CString CCM_HEAT_WASTER_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Heat_Waster");
const CString CCM_MOLD_HEIGHT_CURVE_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Mold_Height_Curve");
const CString CCM_MOLD_INTEMP_CURVE_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Mold_InTemp_Curve");
const CString CCM_MOLD_OUTTEMP_CURVE_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Mold_OutTemp_Curve");
const CString CCM_PLUGBAR_CURVE_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_PlugBar_Curve");
const CString CCM_PROCESS_DATA_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Process_Data");
const CString CCM_PROCESS_STATUS_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Process_Status");
const CString CCM_RUNTIME_DATA_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Runtime_Data");
const CString CCM_SMOOTHBLOCK_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_SmoothBlock");
const CString CCM_SPEED_CURVE_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Speed_Curve");
const CString CCM_TEMP_CURVE_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_Temp_Curve");
const CString CCM_TUNDISH_DATA_CLASS_URI	= _T("XGMESLogic\\CCMMag\\CCCM_Tundish_Data");
const CString CCM_TUNDISH_STRANDINFO_CLASS_URI = _T("XGMESLogic\\CCMMag\\CCCM_Tundish_StrandInfo");
const CString CCM_WATERGAP_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_WaterGap");
const CString CCM_BIGWATERGAP_CLASS_URI		= _T("XGMESLogic\\CCMMag\\CCCM_BigWaterGap");



//钢坯库

const CString BLOOM_STORE_CLASS_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Store_Mag");//方坯库管理逻辑类

const CString BLOOM_IN_CLASS_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Input_Log");//方坯入库实绩实体类
const CString BLOOM_OUT_CLASS_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Output_Log");//方坯出库实绩实体类
const CString BLOOM_TEL_CLASS_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Tel_Data");//方坯电文实体类

const CString BLOOM_STORE_OBJ_URI		= _T("XGMESLogic\\BloomStoreMag\\CBloom_Store_Mag\\S71");//方坯原料库管理逻辑对象
const CString BLOOM_STORE_INCACHE_OBJ_URI   =   _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S71P01");//方坯原料库入库缓存
const CString BLOOM_STORE_OUTCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S71N01");//方坯原料库管理出库缓存

//钢坯状态														   
const CString BLOOM_STATUS_CUT					=_T("6");//01:切断	
const CString BLOOM_STATUS_HOT_JUDGE			=_T("7");//02:热检非待判
const CString BLOOM_STATUS_HOT_WAIT				=_T("8");//02:热检不良待判
const CString BLOOM_STATUS_FIN_JUDGE			=_T("9");//03:第一次终判
const CString BLOOM_STATUS_DOWN					=_T("10");//03:下线
const CString BLOOM_STATUS_INSTORE            	=_T("11");//04:入库
const CString BLOOM_STATUS_CHECK				=_T("12");//05:质量抽检
const CString BLOOM_STATUS_COOL_JUDGE           =_T("13");//06:冷检判定（再次终判）
const CString BLOOM_STATUS_OUTSTORE				=_T("14");//07:出库


const CString WAITING_FIN_JUDGE = _T("YY000000");


const CString BLOOM_STOCK_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S71A01");	//钢坯库库区
const CString BLOOM_COOL_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S71B01");	//钢坯库缓冷区

//废钢生铁原料库

const CString SCRAP_STORE_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Store_Mag");//废钢原料库管理逻辑类
const CString SCRAP_CODE_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Code");//废钢编码实体类

const CString SCRAP_IN_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Input_Log");//废钢入库实绩实体类
const CString SCRAP_OUT_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Output_Log");//废钢出库实绩实体类
const CString SCRAP_TRANS_TEL_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Trans_Tel_Data");//废钢料转库电文实体类
const CString SCRAP_PUR_TEL_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Purchase_Tel_Data");//废钢料外购电文实体类

//Modify begin by llj 2011-03-22 增加废钢和生铁种类
const CString SCRAP_OUT_STORE_DETAIL_CLASS_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrapOutStoreDetail");//废钢生铁种类出库明细实体类
//Modify end


const CString SCRAP_STORE_OBJ_URI		= _T("XGMESLogic\\ScrapStoreMag\\CScrap_Store_Mag\\S82");//废钢原料库管理逻辑对象

const CString SCRAP_STORE_INCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S82P01");//废钢原料库管理入库缓存

const CString SCRAP_STORE_OUTCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S82N01");//废钢原料库管理出库缓存

const CString SCRAP_SCRAP_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S82A01");	//废钢库区
const CString SCRAP_IRON_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S82A02");	//生铁区

//散状料原料库

const CString BULK_STORE_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Store_Mag");//散状料原料库管理逻辑类
const CString BULK_REL_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Bulk_Relation");//散状料料仓料种对应关系实体类
const CString BULK_CODE_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Code");//散状料编码实体类
const CString BULK_TRANS_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Trans_Log");///散状料转库实体类

const CString BULK_IN_CLASS_URI			= _T("XGMESLogic\\BulkStoreMag\\CBulk_Input_Log");//散状料入库实绩实体类
const CString BULK_OUT_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Output_Log");//散状料出库实绩实体类
const CString BULK_APP_CLASS_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_App");//散状料料申请实体类
const CString BULK_PUR_TEL_CLASS_URI	= _T("XGMESLogic\\BulkStoreMag\\CBulk_Purchase_Tel_Data");//散状料采购电文实体类
const CString BULK_TRANS_TEL_CLASS_URI	= _T("XGMESLogic\\BulkStoreMag\\CBulk_Trans_Tel_Data");//散状料转库电文实体类


const CString BULK_STORE_OBJ_URI		= _T("XGMESLogic\\BulkStoreMag\\CBulk_Store_Mag\\S83");//散状料原料库管理逻辑对象

const CString BULK_STORE_INCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S83P01");//散状料原料库管理入库缓存

const CString BULK_STORE_OUTCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S83N01");//散状料原料库管理出库缓存
//散状料原料库库区逻辑对象
const CString BULK_HIGH_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A01");	//散状料原料库1#转炉高仓1#料仓
const CString BULK_HIGH_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A02");	//散状料原料库1#转炉高仓2#料仓
const CString BULK_HIGH_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A03");	//散状料原料库1#转炉高仓3#料仓
const CString BULK_HIGH_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A04");	//散状料原料库1#转炉高仓4#料仓
const CString BULK_HIGH_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A05");	//散状料原料库1#转炉高仓5#料仓
const CString BULK_HIGH_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A06");	//散状料原料库1#转炉高仓6#料仓
const CString BULK_HIGH_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A07");	//散状料原料库1#转炉高仓7#料仓
const CString BULK_HIGH_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S83A08");	//散状料原料库1#转炉高仓8#料仓




//合金原料库

const CString ALLOY_STORE_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Store_Mag");//合金原料库管理逻辑类
const CString ALLOY_REL_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Bulk_Relation");//合金料仓料种对应关系实体类
const CString ALLOY_CODE_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Code");//合金编码实体类
const CString ALLOY_TRANS_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Trans_Log");//合金转库实体类

const CString ALLOY_IN_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Input_Log");//合金入库实绩实体类
const CString ALLOY_OUT_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Output_Log");//合金出库实绩实体类
const CString ALLOY_APP_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_App");//合金料申请实体类
const CString ALLOY_TRANS_TEL_CLASS_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Trans_Tel_Data");//合金料电文实体类
const CString ALLOY_ELEMENT_TEL_CLASS_URI  = _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Element_Tel_Data");//合金料电文实体类


const CString ALLOY_STORE_OBJ_URI		= _T("XGMESLogic\\AlloyStoreMag\\CAlloy_Store_Mag\\S81");//合金原料库管理逻辑对象

const CString ALLOY_STORE_INCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S81P01");//合金原料库管理入库缓存

const CString ALLOY_STORE_OUTCACHE_OBJ_URI	=	_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S81N01");//合金原料库管理出库缓存
//合金原料库库区逻辑对象
const CString ALLOY_HIGH_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A01");	//合金原料库1#转炉高仓1#料仓
const CString ALLOY_HIGH_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A02");	//合金原料库1#转炉高仓2#料仓
const CString ALLOY_HIGH_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A03");	//合金原料库1#转炉高仓3#料仓
const CString ALLOY_HIGH_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A04");	//合金原料库1#转炉高仓4#料仓
const CString ALLOY_HIGH_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A05");	//合金原料库1#转炉高仓5#料仓
const CString ALLOY_HIGH_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A06");	//合金原料库1#转炉高仓6#料仓
const CString ALLOY_HIGH_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A07");	//合金原料库1#转炉高仓7#料仓
const CString ALLOY_HIGH_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81A08");	//合金原料库1#转炉高仓8#料仓

//烘烤炉
const CString ALLOY_HOT_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B01");	//合金原料库烘烤炉1#料仓
const CString ALLOY_HOT_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B02");	//合金原料库烘烤炉2#料仓
const CString ALLOY_HOT_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B03");	//合金原料库烘烤炉3#料仓
const CString ALLOY_HOT_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B04");	//合金原料库烘烤炉4#料仓
const CString ALLOY_HOT_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B05");	//合金原料库烘烤炉5#料仓
const CString ALLOY_HOT_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B06");	//合金原料库烘烤炉6#料仓
const CString ALLOY_HOT_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B07");	//合金原料库烘烤炉7#料仓
const CString ALLOY_HOT_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B08");	//合金原料库烘烤炉8#料仓
const CString ALLOY_HOT_9_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B09");	//合金原料库烘烤炉9#料仓
const CString ALLOY_HOT_10_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B10");	//合金原料库烘烤炉10#料仓
const CString ALLOY_HOT_11_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B11");	//合金原料库烘烤炉11#料仓
const CString ALLOY_HOT_12_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B12");	//合金原料库烘烤炉12#料仓
const CString ALLOY_HOT_13_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B13");	//合金原料库烘烤炉13#料仓
const CString ALLOY_HOT_14_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B14");	//合金原料库烘烤炉14#料仓
const CString ALLOY_HOT_15_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B15");	//合金原料库烘烤炉15#料仓
const CString ALLOY_HOT_16_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B16");	//合金原料库烘烤炉16#料仓
const CString ALLOY_HOT_17_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B17");	//合金原料库烘烤炉17#料仓
const CString ALLOY_HOT_18_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81B18");	//合金原料库烘烤炉18#料仓

//1#LF炉高仓
const CString ALLOY_1LF_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C01");	//合金原料库1#LF炉高仓1#料仓
const CString ALLOY_1LF_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C02");	//合金原料库1#LF炉高仓2#料仓
const CString ALLOY_1LF_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C03");	//合金原料库1#LF炉高仓3#料仓
const CString ALLOY_1LF_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C04");	//合金原料库1#LF炉高仓4#料仓
const CString ALLOY_1LF_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C05");	//合金原料库1#LF炉高仓5#料仓
const CString ALLOY_1LF_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C06");	//合金原料库1#LF炉高仓6#料仓
const CString ALLOY_1LF_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C07");	//合金原料库1#LF炉高仓7#料仓
const CString ALLOY_1LF_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C08");	//合金原料库1#LF炉高仓8#料仓
const CString ALLOY_1LF_9_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C09");	//合金原料库1#LF炉高仓9#料仓
const CString ALLOY_1LF_10_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81C10");	//合金原料库1#LF炉高仓10#料仓

//2#LF炉高仓
const CString ALLOY_2LF_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D01");	//合金原料库1#LF炉高仓1#料仓
const CString ALLOY_2LF_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D02");	//合金原料库1#LF炉高仓2#料仓
const CString ALLOY_2LF_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D03");	//合金原料库1#LF炉高仓3#料仓
const CString ALLOY_2LF_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D04");	//合金原料库1#LF炉高仓4#料仓
const CString ALLOY_2LF_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D05");	//合金原料库1#LF炉高仓5#料仓
const CString ALLOY_2LF_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81D06");	//合金原料库1#LF炉高仓6#料仓

//3#LF1#RH炉公用高仓
const CString ALLOY_12LF_1_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E01");	//合金原料库公用高仓1#料仓
const CString ALLOY_12LF_2_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E02");	//合金原料库公用高仓2#料仓
const CString ALLOY_12LF_3_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E03");	//合金原料库公用高仓3#料仓
const CString ALLOY_12LF_4_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E04");	//合金原料库公用高仓4#料仓
const CString ALLOY_12LF_5_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E05");	//合金原料库公用高仓5#料仓
const CString ALLOY_12LF_6_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E06");	//合金原料库公用高仓6#料仓
const CString ALLOY_12LF_7_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E08");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_8_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E09");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_9_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E010");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_10_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E011");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_11_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E012");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_12_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E013");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_13_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E014");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_14_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E015");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_15_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E016");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_16_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E017");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_17_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E018");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_18_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E019");	//合金原料库公用高仓7#料仓
const CString ALLOY_12LF_19_OBJ_URI		= _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S81E020");	//合金原料库公用高仓7#料仓

//工器具

//铁包实体类URI
const CString CIRONLADLE_BASE_URI	= _T("XGMESLogic\\IronLadleMag\\CIronLadle_Base");
const CString CIRONLADLE_FIRE_URI	= _T("XGMESLogic\\IronLadleMag\\CIronLadle_Fire");
const CString CIRONLADLE_TIE_URI	= _T("XGMESLogic\\IronLadleMag\\CIronLadle_Tie");
const CString CIRONLADLE_USE_URI	= _T("XGMESLogic\\IronLadleMag\\CIronLadle_Use");

//铁包状态
const CString CIRONLADLE_STATUS_TIE				= _T("01");//打结
const CString CIRONLADLE_STATUS_COLD			= _T("02");//冷备
const CString CIRONLADLE_STATUS_SMALL_FIRE		= _T("03");//小火
const CString CIRONLADLE_STATUS_MIDDLE_FIRE		= _T("04");//中火
const CString CIRONLADLE_STATUS_BIG_FIRE		= _T("05");//大火
const CString CIRONLADLE_STATUS_HOT				= _T("06");//热备
const CString CIRONLADLE_STATUS_DISTRIBUTE		= _T("07");//已分配
const CString CIRONLADLE_STATUS_USE				= _T("08");//使用
const CString CIRONLADLE_STATUS_SUSPEND			= _T("09");//停用
const CString CIRONLADLE_STATUS_OFFLINE			= _T("10");//离线待修

//铁包下线原因
const CString CIRONLADLE_STOPREASON_DREG		= _T("01");//01:包壁粘渣严重,处理粘渣
const CString CIRONLADLE_STOPREASON_TEMP		= _T("02");//02:包壁或包底温度过高

//中包实体类URI
const CString CTUNDISH_BASE_URI				= _T("XGMESLogic\\TundishMag\\CTundish_Base");
const CString CTUNDISH_DAUB_URI				= _T("XGMESLogic\\TundishMag\\CTundish_Daub");
const CString CTUNDISH_INNER_BUILD_URI		= _T("XGMESLogic\\TundishMag\\CTundish_Inner_Build");
const CString CTUNDISH_INNER_FIRE_URI		= _T("XGMESLogic\\TundishMag\\CTundish_Inner_Fire");
const CString CTUNDISH_OT_HOT_FIRE_URI		= _T("XGMESLogic\\TundishMag\\CTundish_OT_Hot_Fire");
const CString CTUNDISH_OT_INSTALL_URI		= _T("XGMESLogic\\TundishMag\\CTundish_OT_Install");
const CString CTUNDISH_OT_REFRA_USE_URI		= _T("XGMESLogic\\TundishMag\\CTundish_OT_Refra_Use");
const CString CTUNDISH_TFF_INSTALL_URI		= _T("XGMESLogic\\TundishMag\\CTundish_TFF_Install");
const CString CTUNDISH_TFF_HOT_FIRE_URI		= _T("XGMESLogic\\TundishMag\\CTundish_TFF_Hot_Fire");
const CString CTUNDISH_TFF_REFRA_USE_URI	= _T("XGMESLogic\\TundishMag\\CTundish_TFF_Refra_Use");
const CString CTUNDISH_USE_INFO_URI			= _T("XGMESLogic\\TundishMag\\CTundish_Use_Info");

//中包状态
const CString CTUNDISH_STATUS_INNER_BUILD	= _T("01");//永久层砌筑
const CString CTUNDISH_STATUS_INNER_FIRE	= _T("02");//永久层烘烤
const CString CTUNDISH_STATUS_WORK_DAUB 	= _T("03");//工作层砌筑(打结)
const CString CTUNDISH_STATUS_WORK_FIRE		= _T("04");//工作层烘烤
const CString CTUNDISH_STATUS_COLD			= _T("05");//冷备
const CString CTUNDISH_STATUS_ISTALL		= _T("06");//中包上件
const CString CTUNDISH_STATUS_HOT_FIRE		= _T("07");//热备烘烤
const CString CTUNDISH_STATUS_HOT			= _T("08");//热备
const CString CTUNDISH_STATUS_USE			= _T("09");//使用(周转)
const CString CTUNDISH_STATUS_OFFLINE		= _T("10");//离线待修

//有中包履历但没有实绩的永久层编号或则工作层编号的获取类型
const CString CTUNDISH_GET_TYPE_INNER_TIE		= _T("01");//永久层砌筑:永久层编号
const CString CTUNDISH_GET_TYPE_INNER_FIRE		= _T("02");//永久层烘烤:永久层编号
const CString CTUNDISH_GET_TYPE_WORK_TIE 		= _T("03");//工作层砌筑(打结):工作层编号
const CString CTUNDISH_GET_TYPE_OT_HOT_FIRE		= _T("14");//1、2#铸机热备烘烤:工作层编号
const CString CTUNDISH_GET_TYPE_TFF_HOT_FIRE	= _T("24");//3、4、5#铸机热备烘烤:工作层编号



//钢包实体类URI
const CString CLADLE_BASE_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Base");
const CString CLADLE_PLAN_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Plan");
const CString CLADLE_MAG_OBJ_URI			= _T("XGMESLogic\\LadleMag\\CLadle_Mag");
const CString CLADLE_IN_BUILD_URI			= _T("XGMESLogic\\LadleMag\\CLadle_In_Build");
const CString CLADLE_COM_TIE_URI			= _T("XGMESLogic\\LadleMag\\CLadle_Com_Tie");
const CString CLADLE_COM_LAD_REP_URI		= _T("XGMESLogic\\LadleMag\\CLadle_Com_Lad_Rep");
const CString CLADLE_FIN_BUILD_URI			= _T("XGMESLogic\\LadleMag\\CLadle_Fin_Build");
const CString CLADLE_CHA_DRE_LIN_URI		= _T("XGMESLogic\\LadleMag\\CLadle_Cha_Dre_Lin");
const CString CLADLE_USE_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Use");
const CString CLADLE_FIRE_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Fire");
const CString CLADLE_POUR_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Pour");
const CString CLADLE_FOLD_URI				= _T("XGMESLogic\\LadleMag\\CLadle_Fold");//
const CString CLADLE_PROCESS_URI			= _T("XGMESLogic\\LadleMag\\CLadle_Process");

//钢包状态
const CString CLADLE_STATUS_INNER_BUILD		= _T("01");//永久层砌筑（打结）
const CString CLADLE_STATUS_INNER_FIRE		= _T("02");//永久层烘烤
const CString CLADLE_STATUS_WORK_DAUB 		= _T("03");//工作层砌筑（打结）
const CString CLADLE_STATUS_WORK_FIRE		= _T("04");//工作层烘烤
const CString CLADLE_STATUS_COLD			= _T("05");//冷备
const CString CLADLE_STATUS_HOT_FIRE		= _T("06");//热备烘烤
const CString CLADLE_STATUS_HOT				= _T("07");//热备
const CString CLADLE_STATUS_DESIGN			= _T("08");//分配
const CString CLADLE_STATUS_USE				= _T("09");//使用(周转)
const CString CLADLE_STATUS_OFFLINE			= _T("10");//离线待修


//钢包计划状态
const CString CLADLE_PLAN_STATUS_UNDESIGN	= _T("01");//未分配
const CString CLADLE_PLAN_STATUS_DESIGN		= _T("02");//分配
const CString CLADLE_PLAN_STATUS_EXCUTING 	= _T("03");//执行
const CString CLADLE_STATUS_WORK_EXCUTED	= _T("04");//执行结束

//氧枪实体类
const CString CLANCE_BASE_URI				= _T("XGMESLogic\\LanceMag\\CLance_Base");// 
const CString CLANCE_MAKE_URI				= _T("XGMESLogic\\LanceMag\\CLance_Make");//
const CString CLANCE_DEFEND_URI				= _T("XGMESLogic\\LanceMag\\CLance_Defend");//
const CString CLANCE_CHECK_URI				= _T("XGMESLogic\\LanceMag\\CLance_Check");//
const CString CLANCE_IN_YARD_URI			= _T("XGMESLogic\\LanceMag\\CLance_In_Yard");//
const CString CLANCE_OUT_YARD_URI			= _T("XGMESLogic\\LanceMag\\CLance_Out_Yard");//
const CString CLANCE_USE_URI				= _T("XGMESLogic\\LanceMag\\CLance_Use");// 
const CString CLANCE_MAG_URI				= _T("XGMESLogic\\LanceMag\\CLance_Mag");//

//氧枪状态
const CString CLANCE_STATUS_REPAIR			= _T("01");//制作 
const CString CLANCE_STATUS_FREE			= _T("02");//空闲
const CString CLANCE_STATUS_USE				= _T("03");//使用
const CString CLANCE_STATUS_CHECK			= _T("04");//检查
const CString CLANCE_STATUS_OFFLINE			= _T("05");//离线待修

//氧枪换枪原因
const CString CLANCE_CHANGE_WIDE			= _T("01");//因粘渣严重造成的枪粗(无法通过在线打渣清理) 
const CString CLANCE_CHANGE_LEAK			= _T("02");//焊缝及枪头漏
const CString CLANCE_CHANGE_ERODE			= _T("03");//枪头侵蚀严重(鼻区下陷大于5mm)、出口变形
const CString CLANCE_CHANGE_EFFICIENCY		= _T("04");//吹炼效果差

//真空管实体类
const CString CVACTUBE_BASE_URI				= _T("XGMESLogic\\VacTubeMag\\CVacTube_Base");
const CString CVACTUBE_BUILD_URI			= _T("XGMESLogic\\VacTubeMag\\CVacTube_Build");
const CString CVACTUBE_REPAIR_URI			= _T("XGMESLogic\\VacTubeMag\\CVacTube_Repair");
const CString CVACTUBE_USE_URI				= _T("XGMESLogic\\VacTubeMag\\CVacTube_Use");
const CString CVACTUBE_USE_INFO_URI			= _T("XGMESLogic\\VacTubeMag\\CVacTube_Use_Info");
//const CString CVACTUBE_CIR_INSTALL_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Cir_Install");
const CString CVACTUBE_HOT_SYP_BUI_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Bui");
const CString CVACTUBE_HOT_SYP_REPAIR_URI	= _T("XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Repair");
const CString CVACTUBE_HOT_SYP_USE_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Use");
//const CString CVACTUBE_SOA_CIR_USE_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Soa_Cir_Use");
const CString CVACTUBE_FIRE_URI				= _T("XGMESLogic\\VacTubeMag\\CVacTube_Fire");
const CString CVACTUBE_FIRE_INFO_URI		= _T("XGMESLogic\\VacTubeMag\\CVacTube_Fire_Info");
const CString CVACTUBE_MAG_URI				= _T("XGMESLogic\\VacTubeMag\\CVacTube_Mag");


//真空槽状态
const CString CVACTUBE_STATUS_REPAIR		= _T("01");//维修
const CString CVACTUBE_STATUS_COLD			= _T("02");//冷备
const CString CVACTUBE_STATUS_PRE_FIRE		= _T("03");//预热
const CString CVACTUBE_STATUS_BIG_FIRE		= _T("04");//大火
const CString CVACTUBE_STATUS_HOT			= _T("05");//热备
const CString CVACTUBE_STATUS_USE			= _T("06");//使用
const CString CVACTUBE_STATUS_CHECK			= _T("07");//下线检查
const CString CVACTUBE_STATUS_OFFLINE		= _T("08");//离线待修

//真空槽下线原因
const CString CVACTUBE_OFF_SOA_ERODE		= _T("01");//浸渍管侵蚀严重
const CString CVACTUBE_OFF_SOA_BRICK		= _T("02");//浸渍管掉砖
const CString CVACTUBE_OFF_SOA_WIDE 		= _T("03");//浸渍管粘粗
const CString CVACTUBE_OFF_CIR_ERODE		= _T("04");//环流管侵蚀严重
const CString CVACTUBE_OFF_DOWN_BRICK		= _T("05");//下部槽掉砖
const CString CVACTUBE_OFF_DOWN_RED			= _T("06");//下部槽发红
const CString CVACTUBE_OFF_DOWN_LEAK		= _T("07");//下部槽穿钢
const CString CVACTUBE_OFF_DEMAND			= _T("08");//不能满足排产需求
const CString CVACTUBE_OFF_OTHER			= _T("09");//其它

//真空槽位置
const CString CVACTUBE_POSITION_BUILD		= _T("1");//砌筑位
const CString CVACTUBE_POSITION_FIRE_A		= _T("2");//A烘烤位
const CString CVACTUBE_POSITION_FIRE_B 		= _T("3");//B烘烤位
const CString CVACTUBE_POSITION_WORK_A		= _T("A");//A工位
const CString CVACTUBE_POSITION_WORK_B		= _T("B");//B工位


//结晶器实体类
const CString CMOLD_BASE_URI				= _T("XGMESLogic\\MoldMag\\CMold_Base");
const CString CMOLD_PIPE_INSTALL_URI		= _T("XGMESLogic\\MoldMag\\CMold_Pipe_Install");
const CString CMOLD_BOARD_INSTALL_URI		= _T("XGMESLogic\\MoldMag\\CMold_Board_Install");
const CString CMOLD_PIPE_PAR_USEI_URI		= _T("XGMESLogic\\MoldMag\\CMold_Pipe_Par_Use");
const CString CMOLD_BOARD_PAR_USE_URI		= _T("XGMESLogic\\MoldMag\\CMold_Board_Par_Use");
const CString CMOLD_MOLD_URI				= _T("XGMESLogic\\MoldMag\\CMold_Mag");

//结晶器状态
const CString CMOLD_STATUS_WAIT				= _T("01");//待装  
const CString CMOLD_STATUS_REPAIR			= _T("02");//装配 
const CString CMOLD_STATUS_FREE				= _T("03");//备用
const CString CMOLD_STATUS_USE				= _T("04");//在线
const CString CMOLD_STATUS_OFFLINE			= _T("05");//下线检测

//结晶器下线原因
const CString CCMOLD_OFF_PLAN				= _T("01");//计划
const CString CCMOLD_OFF_WEAL				= _T("02");//磨损
const CString CCMOLD_OFF_LEAK_STEEL 		= _T("03");//漏钢
const CString CCMOLD_OFF_TRIPE				= _T("04");//脱方鼓肚
const CString CCMOLD_OFF_SCRATCH			= _T("05");//划伤
const CString CCMOLD_OFF_TUBE				= _T("06");//铜管凹凸
const CString CCMOLD_OFF_LEAK_WATER			= _T("07");//漏水
const CString CCMOLD_OFF_SIZE				= _T("08");//上下口尺寸不合
const CString CCMOLD_OFF_OTHER				= _T("09");//其他


//脱硫实体类
const CString CDES_BASE_URI				    = _T("XGMESLogic\\DeSMag\\CDeS_Base_Data");
const CString CDES_PROCESS_URI				= _T("XGMESLogic\\DeSMag\\CDeS_Process_Data");
const CString CDES_ADDITION_URI				= _T("XGMESLogic\\DeSMag\\CDeS_Addition_Data");
const CString CDES_EQUIPMENT_URI			= _T("XGMESLogic\\DeSMag\\CDeS_Equipment_Status");
const CString CDES_STATUS_URI				= _T("XGMESLogic\\DeSMag\\CDeS_Process_Status");
const CString CDES_RUNTIME_URI				= _T("XGMESLogic\\DeSMag\\CDeS_Runtime_Data");
const CString CDES_LANCEDATA_URI			= _T("XGMESLogic\\DeSMag\\CDeS_Lance_Data");
const CString CDES_LANCELOG_URI			= _T("XGMESLogic\\DeSMag\\CDeS_Lance_Log");
//DES工序管理类
const CString DES_CLASS_URI                 = _T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag");
const CString DES_AREA_CLASS_URI            = _T("XGMESLogic\\DeSMag\\CDeS_Prod_Area");

//脱磷实体类
const CString CDEP_BASE_URI				    = _T("XGMESLogic\\DePMag\\CDEP_Base_Data");
const CString CDEP_PROCESS_URI				= _T("XGMESLogic\\DePMag\\CDEP_Process_Data");
const CString CDEP_ADDITION_URI				= _T("XGMESLogic\\DePMag\\CDEP_Addition_Data");
const CString CDEP_EQUIPMENT_URI			= _T("XGMESLogic\\DePMag\\CDEP_Equipment_Status");
const CString CDEP_STATUS_URI				= _T("XGMESLogic\\DePMag\\CDEP_Process_Status");
const CString CDEP_RUNTIME_URI				= _T("XGMESLogic\\DePMag\\CDEP_Runtime_Data");

//DEP工序管理类
const CString DEP_CLASS_URI                 = _T("XGMESLogic\\DePMag\\CDEP_Unit_Mag");
const CString DEP_AREA_CLASS_URI            = _T("XGMESLogic\\DePMag\\CDEP_Prod_Area");




//基类定义的计划状态，不能与其发生冲突
//enum ProducePlanStatus
//{
//	Unknown = 0,			// 计划状态未知。不能进行任何合法的操作
//	Editing = 1,			// 计划正在编辑，不能下达或执行。
//	Created = 2,			// 计划已经生成，可以进行后续工作。
//	Confirmed = 3,			// 计划已经确认，属于合法有效的计划了。
//	Canceled = 4,			// 计划已经取消。
//	Assigned = 5,			// 计划已经下达给执行部门。
//	Executing = 6,			// 计划已经开始执行。
//	Paused = 7,				// 计划已经暂停执行。
//	Executed = 8,			// 计划已经执行完毕。
//	Completed = 9,			// 计划已经结束，不再有效。
//};


//计划订单状态
//const CString PLAN_ORDER_STATUS_UNCONFIRM           =_T("10");//00:未确认
const CString PLAN_ORDER_STATUS_UNINTEGRATE         =_T("11");//01:未排产
//const CString PLAN_ORDER_STATUS_INTEGRATED          =_T("12");//02:已收池
const CString PLAN_ORDER_STATUS_CASTING            	=_T("13");//03:产生浇钢计划
const CString PLAN_ORDER_STATUS_TAPPING             =_T("14");//04:产生出钢计划
const CString PLAN_ORDER_STATUS_EXCUTING            =_T("15");//05:执行
const CString PLAN_ORDER_STATUS_EXCUTED             =_T("16");//06:执行完成

//浇钢计划状态
const CString CASTING_PLAN_STATUS_UNSCHEDULING      =_T("10");//01:未排产
const CString CASTING_PLAN_STATUS_SCHEDULED			=_T("11");//02:已排产
const CString CASTING_PLAN_STATUS_EXCUTING			=_T("12");//03:执行
const CString CASTING_PLAN_STATUS_EXCUTED           =_T("13");//04:执行完成


//出钢计划状态
const CString TAPPING_PLAN_STATUS_UNSEND			=_T("10");//01:未下达
const CString TAPPING_PLAN_STATUS_SEND				=_T("11");//02:已下达
const CString TAPPING_PLAN_STATUS_EXCUTING			=_T("12");//03:执行
const CString TAPPING_PLAN_STATUS_EXCUTED           =_T("13");//04:执行完成


//出钢计划转炉状态
const CString TAPPING_PLAN_BOF_STATUS_UNEXCUTING	=_T("01");//01:未执行
const CString TAPPING_PLAN_BOF_STATUS_IRON			=_T("02");//02:兑铁
const CString TAPPING_PLAN_BOF_STATUS_BLOW			=_T("03");//03:吹炼开始
const CString TAPPING_PLAN_BOF_STATUS_TAPPING		=_T("04");//03:出钢开始
const CString TAPPING_PLAN_BOF_STATUS_TAPPED        =_T("05");//04:出钢结束


//出钢计划炉后状态
const CString TAPPING_PLAN_SIDE_STATUS_UNEXCUTING		=_T("01");//01:未执行
const CString TAPPING_PLAN_SIDE_STATUS_BEGIN			=_T("02");//02:处理开始
const CString TAPPING_PLAN_SIDE_STATUS_END				=_T("03");//03:处理结束


//出钢计划LF炉状态
const CString TAPPING_PLAN_LF_STATUS_UNEXCUTING		=_T("01");//01:未执行
const CString TAPPING_PLAN_LF_STATUS_ARR			=_T("02");//02:进站
const CString TAPPING_PLAN_LF_STATUS_BEGIN			=_T("03");//03:处理开始
const CString TAPPING_PLAN_LF_STATUS_END			=_T("04");//04:处理结束
const CString TAPPING_PLAN_LF_STATUS_LEAVE			=_T("05");//05:出站


//出钢计划RH炉状态
const CString TAPPING_PLAN_RH_STATUS_UNEXCUTING		=_T("01");//01:未执行
const CString TAPPING_PLAN_RH_STATUS_ARR			=_T("02");//02:进站
const CString TAPPING_PLAN_RH_STATUS_BEGIN			=_T("03");//03:处理开始
const CString TAPPING_PLAN_RH_STATUS_END			=_T("04");//04:处理结束
const CString TAPPING_PLAN_RH_STATUS_LEAVE			=_T("05");//05:出站

//出钢计划铸机状态
const CString TAPPING_PLAN_CCM_STATUS_UNEXCUTING	=_T("01");//01:未执行
const CString TAPPING_PLAN_CCM_STATUS_ARR			=_T("02");//02:大包到达
const CString TAPPING_PLAN_CCM_STATUS_BEGIN			=_T("03");//03:大包开浇
const CString TAPPING_PLAN_CCM_STATUS_END			=_T("04");//03:浇注结束


//工器具材料组别
const CString IRONLADLE_FAC					=_T("IronLadleF");//铁包
const CString LANCE_FAC						=_T("Lance");//氧枪
const CString LADLE_FAC						=_T("Ladle");//钢包
const CString VACTUBE_FAC					=_T("VacTube");//真空管
const CString TUNDISH_FAC					=_T("Tundish");//中包
const CString MOLD_FAC						=_T("Mold");//结晶器

//简化验取样地点类型
const CString MIF_SAMPLE_TYPE = _T("H");//混铁炉取样
const CString BOF_SAMPLE_TYPE = _T("Z");//转炉取样
const CString LF_SAMPLE_TYPE  = _T("F");//LF炉取样
const CString RH_SAMPLE_TYPE  = _T("R");//RH炉取样
const CString CCM_SAMPLE_TYPE = _T("C");//连铸取样
								
//质量试样类别QA_Sample_Type
const CString QA_Sample_Type_ZF = _T("ZF");//LF精渣样
const CString QA_Sample_Type_ZR = _T("ZR");//RH精渣样
const CString QA_Sample_Type_ZL = _T("ZL");//连铸中包渣样
const CString QA_Sample_Type_ZZ = _T("ZZ");//转炉渣样
const CString QA_Sample_Type_GL = _T("GL");//连铸中包样
const CString QA_Sample_Type_TS = _T("TS");//铁包样[现在没有用]
const CString QA_Sample_Type_TC = _T("TC");//抽查铁水样
const CString QA_Sample_Type_TH = _T("TH");//混铁炉样
const CString QA_Sample_Type_GZ = _T("GZ");//炉终样
const CString QA_Sample_Type_GN = _T("GN");//氮后样
const CString QA_Sample_Type_GG = _T("GG");//过程样
const CString QA_Sample_Type_GP = _T("GP");//成品样
const CString QA_Sample_Type_GE = _T("GE");//割样
const CString QA_Sample_Type_GQ = _T("GQ");//气体样
const CString QA_Sample_Type_GD = _T("GD");//钢坯低倍样
const CString QA_Sample_Type_TA = _T("TA");//铁罐混铁炉全分析2009-04-11
const CString QA_Sample_Type_ZG = _T("ZG");//铁渣样2009-04-11
								  
//质量试样地点QA_Sample_Addr			  
const CString QA_Sample_Addr_H1 = _T("H1");	//1#混铁炉	
const CString QA_Sample_Addr_H2 = _T("H2");	//2#混铁炉

const CString QA_Sample_Addr_TB = _T("TB");	//铁包
const CString QA_Sample_Addr_TC = _T("TC");	//铁罐
const CString QA_Sample_Addr_Z1 = _T("Z1");	//1#转炉	
const CString QA_Sample_Addr_Z2 = _T("Z2");	//2#转炉	
const CString QA_Sample_Addr_Z3 = _T("Z3");	//3#转炉	
const CString QA_Sample_Addr_Z4 = _T("Z4");	//4#转炉	
const CString QA_Sample_Addr_F1 = _T("F1");	//1#LF炉	
const CString QA_Sample_Addr_F2 = _T("F2");	//2#LF炉	
const CString QA_Sample_Addr_F3 = _T("F3");	//3#LF炉
//Modify by llj 2011-1-18 因改造修改
const CString QA_Sample_Addr_F5 = _T("F5");	//5#LF炉
//Modify by hyh 2012-05-09 因改造修改
const CString QA_Sample_Addr_F4 = _T("F4");	//4#LF炉

const CString QA_Sample_Addr_R1 = _T("R1");	//1RH炉
const CString QA_Sample_Addr_C1 = _T("C1");	//1#铸机	
const CString QA_Sample_Addr_C2 = _T("C2");	//2#铸机	
const CString QA_Sample_Addr_C3 = _T("C3");	//3#铸机	
const CString QA_Sample_Addr_C4 = _T("C4");	//4#铸机	
const CString QA_Sample_Addr_C5 = _T("C5");	//5#铸机
//Modify by llj 2011-1-18 因改造修改
const CString QA_Sample_Addr_C7 = _T("C7");	//7#铸机	
//Modify by hyh 2012-05-09 因改造修改
const CString QA_Sample_Addr_C6 = _T("C6");	//6#铸机
										
//基类定义的材料状态，不能与其发生冲突	
//enum MaterialStatus
//{
//	Unknown=0,	//未知材料状态
//	Normal=1,	//正常。
//	Blocked=2,	//材料被封闭。
//	Lost=3,		//材料丢失。
//	Outputted=4,//材料已经输出。如已经售出，或作为废品卖出。
//	Deleted=5,	//材料被删除。系统对材料的删除仅仅是作状态标记，这是为了数据安全。
//};

//材料状态
const CString COIL_STATUS_UNSEND            		=_T("6");//0:计划未下达
const CString COIL_STATUS_L1            			=_T("7");//1:计划下达
const CString COIL_STATUS_FEED            			=_T("8");//2:装炉
const CString COIL_STATUS_PROD            			=_T("9");//3:生产
const CString COIL_STATUS_HOTBEGIN              	=_T("10");//4:加热开始
const CString COIL_STATUS_HOTEND              		=_T("11");//5:加热结束
const CString COIL_STATUS_COLDBEGIN              	=_T("12");//6:冷却开始
const CString COIL_STATUS_COLDEND	             	=_T("13");//7:冷却结束
const CString COIL_STATUS_END						=_T("14");//8:生产结束
const CString COIL_STATUS_DEVLIVERY					=_T("15");//8:出炉

//下面定义了转炉铁水准备至吹炼开始常量
const double BOF_PREPARED_TIME = 5;						//分

const double BOF_TAPPING_TIME = 11;						//分

//下面定义了铸机准备时间常量
const double CASTING_WAITED_TIME = 5;
//分
//Modify begin by llj 2011-1-18 因改造修改，由14改为16
//在SAMPLE_ADDR添加_T("F5")
//在UNIT_MAG_OBJECT添加CCM5_UNIT_URI
//const L3LONG SAMPLE_ADDR_COUNT = 14;
//const CString SAMPLE_ADDR[SAMPLE_ADDR_COUNT] = {_T("H1"),_T("H2"),
//                                                _T("Z1"), _T("Z2"), _T("Z3"), _T("Z4"),
//                                                _T("F1"),_T("F2"),_T("F3"),
//                                                _T("L1"),_T("L2"),_T("L3"),_T("L4"),_T("L5")};
//
//const CString UNIT_MAG_OBJECT[SAMPLE_ADDR_COUNT] = {MIXFProduceUnit1_URI,MIXFProduceUnit1_URI,
//                                                    BOF1_UNIT_URI,BOF2_UNIT_URI,BOF3_UNIT_URI,BOF4_UNIT_URI,
//                                                    LF1_UNIT_URI,LF2_UNIT_URI,LF3_UNIT_URI,
//                                                    CCM1_UNIT_URI,CCM2_UNIT_URI,CCM3_UNIT_URI,CCM4_UNIT_URI,CCM4_UNIT_URI};

const L3LONG SAMPLE_ADDR_COUNT = 19;
//modify by hyh 2012-05-09
const CString SAMPLE_ADDR[SAMPLE_ADDR_COUNT] = {_T("H1"),_T("H2"),_T("H3"),
                                                _T("Z1"), _T("Z2"), _T("Z3"), _T("Z4"),
                                                _T("F1"),_T("F2"),_T("F3"),_T("F5"),_T("F4"),
                                                _T("L1"),_T("L2"),_T("L3"),_T("L4"),_T("L5"),_T("L7"),_T("L6")};

const CString UNIT_MAG_OBJECT[SAMPLE_ADDR_COUNT] = {MIXFProduceUnit1_URI,MIXFProduceUnit1_URI,
                                                    BOF1_UNIT_URI,BOF2_UNIT_URI,BOF3_UNIT_URI,BOF4_UNIT_URI,
                                                    LF1_UNIT_URI,LF2_UNIT_URI,LF3_UNIT_URI,LF5_UNIT_URI,LF4_UNIT_URI,
                                                    CCM1_UNIT_URI,CCM2_UNIT_URI,CCM3_UNIT_URI,CCM4_UNIT_URI,CCM5_UNIT_URI,CCM7_UNIT_URI,CCM6_UNIT_URI};
//end by hyh
//Modify end  

inline CString GetRealHeatID(LPCTSTR lpcszVirtualID)
{
	CString strRealID = lpcszVirtualID; strRealID.Trim();
	//if(strRealID.Mid(4,1) == _T("9"))
	//	strRealID.SetAt(4,_T('0'));
	return strRealID;
}
// 逻辑类BaseData_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBaseData_Mag :
	public CL3Object
{
public:
	CBaseData_Mag(void);
	virtual ~CBaseData_Mag(void);

	DECLARE_L3CLASS(CBaseData_Mag,XGMESLogic\\BaseDataMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBaseData_Mag)
	DECLARE_L3EVENTSINK_MAP()
	DECLARE_L3ACCESSCONTROL_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="BaseData_Mag" name="NC_Plan_Event" type="L3LONG">
	///NC计划预约属性
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Plan_Event)////2009-02-21 tangyi


	/// <Property class="BaseData_Mag" name="NC_Plan_Event" type="L3LONG">
	///NC炉次确定预约属性
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Heat_Confirm_Event)////2009-02-22 tangyi

	/// <Property class="BaseData_Mag" name="NC_Plan_Event" type="L3LONG">
	///NC铁水电文预约属性
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Iron_Event)////2009-03-15 liuzhiqiang


	/// <Property class="BaseData_Mag" name="Steel_Back_Event" type="L3LONG">
	///钢水回炉预约属性
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Steel_Back_Event)////2009-03-22 tangyi


	/// <Property class="BaseData_Mag" name="NC_Store_ChangeJudge_Event" type="L3LONG">
	///库内改判预约属性
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Store_Change_Event)////2009-03-22 tangyi


	/// <Method class="BaseData_Mag" name="ReceiveBaseData" type="">
	/// 
	/// 接收NC基本数据信息
	/// ARG&gt;&gt; rsData : 基本数据，必须包含DataType字段。
	/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
	/// </Method>
	L3BOOL ReceiveBaseData();


	L3RECORDSET GetCodeAndDes(L3STRING csCodeGroup);

	L3STRING GetSysCurDate();


	
	/*/// <Method class="CBaseData_Mag" name="GetPlanInfor" type="L3LONG">
	/// 2009-02-21
	/// 向NC发送生产计划电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetPlanInfor();
	/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
	/// 2009-02-21
	/// NC确认生产订单
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmPlan(L3RECORDSET rsData);


	/// <Method class="CBaseData_Mag" name="GetQualityJudgeInfor" type="L3LONG">
	/// 2009-02-22
	/// 向NC发送终判质量电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetQualityJudgeInfor(L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2);


	/// <Method class="CBaseData_Mag" name="ConfirmQuality" type="L3LONG">
	/// 
	/// NC确认质量终判
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmQuality(L3RECORDSET rsData);

	
	/// <Method class="CBaseData_Mag" name="GetBloomInfor" type="L3LONG">
	/// 2009-02-22
	/// 向NC发送生产完成电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetBloomInfor(L3RECORDSET *rsMainData);


	/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
	/// 
	/// NC确认生产完成
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmBloomInfor(L3RECORDSET rsData);


	/// <Method class="CBaseData_Mag" name="GetBOFAddMaterialsInfor" type="L3LONG">
	/// 2009-02-22
	/// 向NC发送生产发料电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetAddMaterialsInfor(L3RECORDSET *rsMainData);


	/// <Method class="CBloom_Store_Mag" name="BloomHotSend" type="L3LONG">
	/// 
	/// 向NC发送钢坯入库电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetBloomInStoreInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="ConfirmRHAddMaterials" type="L3LONG">
	/// 
	/// NC确认钢坯入库
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmBloomInStoreInfor(L3RECORDSET rsData);*/	

	/*/// NC确认发料成功完成
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmAddMaterialInfor(L3RECORDSET rsData);*/	

	/*/// <Method class="CBaseData_Mag" name="GetIronQualityJudgeInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng
	/// 向NC发送铁水终判质量电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetIronQualityJudgeInfor(L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2);

	/// <Method class="CBaseData_Mag" name="ConfirmIronQuality" type="L3LONG">
	/// 
	/// NC确认铁水质量终判
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmIronQuality(L3RECORDSET rsData);

	/// <Method class="CBaseData_Mag" name="GetIronBloomInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng
	/// 向NC发送铁水生产完成电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetIronBloomInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="ConfirmIronBloomInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng
	/// NC确认铁水生产完成
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmIronBloomInfor(L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="GetIronBloomInStoreInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng
	/// 向NC发送铁水入库电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetIronBloomInStoreInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="ConfirmIronBloomInStoreInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng 
	/// NC确认铁水入库
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmIronBloomInStoreInfor(L3RECORDSET rsData);*/


	/*/// <Method class="CBaseData_Mag" name="GetAllReturnMaterialsInfor" type="L3LONG">
	/// 2009-03-23 liuzhiqiang
	/// 向NC发送全回炉生产发料电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetAllReturnMaterialsInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="GetAllReturnBloomInfor" type="L3LONG">
	/// 2009-03-23
	/// 向NC发送全回炉生产完成电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetAllReturnBloomInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBloom_Store_Mag" name="GetAllBloomInStoreInfor" type="L3LONG">
	/// 
	/// 向NC发送全回炉入库电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetAllBloomInStoreInfor(L3RECORDSET *rsMainData);*/

	/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
	/// 
	/// 代码数据导入
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL BaseAllCodeInput();

	/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
	/// 
	/// 改判数据推算
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3RECORDSET ModifySteelGrade(CString HeatID,CString CurSteelGradeIndex);
	
	/// <Method class="CBaseData_Mag" name="ConfirmIronBloomInStoreInfor" type="L3LONG">
	/// 
	///从NC接收钢铁料信息
	/// RET &lt;&lt;成功返回1，失败返回0 2009-03-18
	/// </Method>
	L3BOOL ReceiveSteelmaterialInforFromNC(L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="WriteLogFromNC" type="L3LONG">
	/// 
	/// 根据发送的电文记录日志
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3BOOL WriteLogFromNC(L3RECORDSET rsData);


	/// <Method class="CBaseData_Mag" name="SendPlanInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// 向NC补发生产计划电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET SendPlanInfor(L3STRING strHeatID);

	/// <Method class="CBaseData_Mag" name="SendAddMaterialsInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// 向NC补发生产发料电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET SendAddMaterialsInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="GetBloomInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// 向NC补发生产完成电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET SendBloomInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="SendQualityJudgeInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// 向NC补发终判质量电文(strType:0过程终判;1:库内改判)
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET SendQualityJudgeInfor(L3STRING strHeatID,L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2,L3STRING strType);

	/// <Method class="CBloom_Store_Mag" name="SendBloomInStoreInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// 向NC补发钢坯入库电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET SendBloomInStoreInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="SendIronBloomInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// 向NC补发铁水生产完成电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET SendIronBloomInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="SendIronQualityJudgeInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// 向NC补发铁水终判质量电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET SendIronQualityJudgeInfor(L3STRING strHeatID,L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2);

	/// <Method class="CBloom_Store_Mag" name="SendIronBloomInStoreInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// 向NC补发铁水入库电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET SendIronBloomInStoreInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);


	//获取批次号2009-03-28
	L3RECORDSET GetMaterialBatchID(L3STRING strMaterialCode);

	/// <Method class="CBaseData_Mag" name="GetPlanOrder" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// 向NC发送生产计划电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetPlanOrder();

	/// <Method class="CBaseData_Mag" name="ConfirmPlanOrder" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// NC确认生产订单
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmPlanOrder(L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="GetInStore" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// 向NC发送钢坯入库电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetInStore();

	/// <Method class="CBaseData_Mag" name="ConfirmInStore" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// NC确认钢坯入库
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmInStore(L3RECORDSET rsData);

	/// <Method class="CBaseData_Mag" name="GetIron" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// 向NC发送铁水终判质量电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetIron();

	/// <Method class="CBaseData_Mag" name="ConfirmIron" type="L3LONG">
	/// 
	/// NC确认铁水入库
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmIron(L3RECORDSET rsData);

	/// <Method class="CBaseData_Mag" name="GetIron" type="L3LONG">
	/// 2009-02-22
	/// 向NC发送库内终判质量电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetInStoreQuality();


	/// <Method class="CBaseData_Mag" name="ConfirmIron" type="L3LONG">
	/// 
	/// NC确认库内改判
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmInStoreQuality(L3RECORDSET rsData);

	/// <Method class="CBaseData_Mag" name="ConfirmIron" type="L3LONG">
	/// 
	/// 测试存储过程
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL TestOracleProcess(L3STRING strHeatID);

	/// <Method class="CBloom_Store_Mag" name="GetInStore" type="L3LONG">
	/// 2009-04-04 liuzhiqiang
	/// 向NC发送全回炉电文
	/// RET &lt;&lt;成功返回1，失败返回NULL
	/// </Method>
	L3RECORDSET GetAllReturn();

	/// <Method class="CBaseData_Mag" name="ConfirmInStore" type="L3LONG">
	/// 2009-04-04 liuzhiqiang
	/// NC确认全回炉
	/// RET &lt;&lt;成功返回1，失败返回0
	/// </Method>
	L3BOOL ConfirmAllReturn(L3RECORDSET rsData);

	//2009-04-17 Liao
	/// <Method class="CBaseData_Mag" name="Add_Mat_Price" type="L3LONG">
	/// 添加物料价格库信息
	/// <Param name="dsInfo" type="L3RECORDSET">物料信息</Param>
	/// </Method>
	L3LONG Add_Mat_Price(L3RECORDSET dsInfo);
	/// <Method class="CBaseData_Mag" name="Modify_Mat_Price" type="L3LONG">
	/// 修改物料价格库信息
	/// <Param name="dsInfo" type="L3RECORDSET">修改信息</Param>
	/// </Method>
	L3LONG Modify_Mat_Price(L3RECORDSET dsInfo);
	/// <Method class="CBaseData_Mag" name="Delete_Mat_Price" type="L3LONG">
	/// 删除物料价格库信息
	/// <Param name="dsInfo" type="L3RECORDSET">删除信息</Param>
	/// </Method>
	L3LONG Delete_Mat_Price(L3RECORDSET dsInfo);
	/// <Method class="CBaseData_Mag" name="Get_Materia_Price" type="L3RECORDSET">
	/// 获取物料价格信息
	/// <Param name="strCondition" type="L3STRING">查询条件</Param>
	/// </Method>
	L3RECORDSET Get_Materia_Price(L3STRING strCondition);
	/// <Method class="CBaseData_Mag" name="InsertBaseParameter" type="L3LONG">
	/// 插入数据到指定的基类中
	/// ARG >> strClassNameURI: 基类名
	///		   rsParam： 数据集
	/// RET << 成功返回1；否则返回非1
	/// <Param name="strClassNam" type="L3STRING"></Param>
	/// <Param name="rsParam" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertBaseParameter(L3STRING strClassNameURI, L3RECORDSET rsParam);
};

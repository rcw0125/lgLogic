// 逻辑类CQA_HeatChemicalData_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_HeatChemicalData_Mag :
	public CL3Object
{
public:
	CQA_HeatChemicalData_Mag(void);
	virtual ~CQA_HeatChemicalData_Mag(void);

	DECLARE_L3CLASS(CQA_HeatChemicalData_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatChemicalData_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:
	// 工序枚举
	enum _UnitEnum
	{
		BF = 0,	// 铁水
		MIF = 1,// 混铁炉
		BOF = 2,// 转炉
		TAP = 3,// 炉后
		LF = 4, // LF炉
		RH = 5, // RH炉
		CCM = 6,// 铸机
	};
	/// <Method class="CQA_HeatChemicalData_Mag" name="GetUnitMagURIBySampleAddr" type="CString">
	/// 通过取样地点获取工序静态对象（用于设置工序对象相关属性）
	/// <Param name=strSampleAddr//取样地点</Param>
	/// </Method>
	CString GetUnitMagURIBySampleAddr(LPCTSTR strSampleAddr);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetSysYear" type="CString">
	/// 计算委托单申请号
	/// <Param name=无</Param>
	/// </Method>
    CString GetSysCurYear();

    /// <Method class="CQA_HeatChemicalData_Mag" name="CalLabSheetAppID" type="CString">
	/// 计算委托单申请号
	/// <Param name="cstrSampleAddr" type="LPCTSTR">采样地点</Param>
	/// </Method>
	CString CalLabSheetAppID(LPCTSTR csSampleAddr,LPCTSTR csSampleType);

	/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronSampleCode" type="CString">
	/// 计算铁水试样编码
	/// <Param name="csSampleAddr" type="LPCTSTR"> 取样地点
	/// <Param name="csSampleType" type="LPCTSTR"> 试样类别
	/// <Param name="csTAPNo" type="LPCTSTR"> 铁次号
	/// 必需包括BFID，TAP_No，Sample_Type，Sample_Address</Param>
	/// </Method>
    CString  CalIronSampleCode(LPCTSTR csSampleAddr,
													 LPCTSTR csSampleType,
													 LPCTSTR csTAPNo);

													 /// <Method class="CQA_HeatChemicalData_Mag" name="CalMixFurnaceSampleCode" type="CString">
	/// 计算混铁炉试样编码
	/// <Param name="csSampleAddr" type="LPCTSTR">取样地点(混铁炉)</Param>
	/// <Param name="csSampleType" type="LPCTSTR">试样类别(混铁炉)</Param>
	/// </Method>
	CString  CalMixFurnaceSampleCode(LPCTSTR csSampleAddr,LPCTSTR csSampleType);

	/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronLadleSampleCode" type="CString">
	/// 计算混铁炉铁包样编码
	/// <Param name="csSampleAddr" type="LPCTSTR">取样地点(混铁炉)</Param>
	/// <Param name="csSampleType" type="LPCTSTR">试样类别</Param>
	/// <Param name="csIronLadleNo" type="LPCTSTR">铁包</Param>
	/// </Method>
	CString  CalIronLadleSampleCode(LPCTSTR csSampleAddr,LPCTSTR csSampleType,LPCTSTR csIronLadleNo);

/// <Method class="CQA_HeatChemicalData_Mag" name="CalBOFSampleCode" type="CString">
	/// 计算炼钢试样编码
	/// <Param name="csSampleType" type="LPCTSTR">试样类别</Param>
	/// <Param name="csSampleAddr" type="LPCTSTR">取样地点</Param>
	/// <Param name="csHeatID" type="LPCTSTR">炉号</Param>
	/// </Method>
    CString CalBOFSampleCode(LPCTSTR csSampleType,
		                     LPCTSTR csSampleAddr,
							 LPCTSTR csHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="LogLabSheet" type="L3LONG">
	/// 生成化验委托单据
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///试样数据集必需包括：Sample_Type，Sample_Address，HeatID字段
	/// </Method>
	L3LONG NewLabSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="ModifyLabSheet" type="L3LONG">
	/// 修改委托单数据
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyLabSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="DeleteLabSheet" type="L3LONG">
	/// 删除委托单数据
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteLabSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="SendSheetDataToLab" type="L3LONG">
	/// 委托单数据下传化验室
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SendSheetDataToLab(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSheetBack" type="L3LONG">
	/// 接收检化验委托单回退
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabSheetBack(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSteelElement" type="L3LONG">
	/// 接收钢样检化验结果
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabSteelElement(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSPrintData" type="L3LONG">
	/// 接收低倍样实绩
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
	/// </Method>
	L3LONG  AcceptSPrintData(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSPrintData" type="L3LONG">
	/// 接收渣样检化验结果
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
	/// </Method>
	L3LONG  AcceptSlagElement(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptReSampleAdvice" type="L3LONG">
	/// 接收检化验重新取样通知 
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///试样数据集必需包括：ApplyID，ReSample_Reason字段
	/// </Method>
	L3LONG AcceptReSampleAdvice(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="LabCutAdvice" type="L3LONG">
	/// 填写割样通知单
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  LabCutAdvice(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetHeatLabElement" type="L3RECORDSET">
	/// 获取炉次过程钢样
	/// <Param name="rsData" type="L3RECORDSET">去向</Param>
	/// </Method>
	L3RECORDSET GetHeatLabElement(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetHeatSlagElement" type="L3RECORDSET">
	/// 获取炉次渣样信息
	/// <Param name="rsData" type="L3RECORDSET">去向</Param>
	/// </Method>
	L3RECORDSET GetHeatSlagElement(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetActualHeatChemicalData" type="L3RECORDSET">
	/// 获取炉次化学成分实绩数据
	/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
	/// </Method>
	L3RECORDSET GetActualHeatChemicalData(L3STRING strHeatID,
										  L3LONG nUnitTypeID,
										  L3LONG nUnitID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetTechRequestByHeatID" type="CString">
	/// 通过炉号获取委托单中的协议数据
	/// <Param name=strHeatID//炉号</Param>
	/// </Method>
	CString GetTechRequestByHeatID(LPCTSTR strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetSteelGradeByHeatID" type="CString">
	/// 通过炉号获取委托单中的钢种
	/// <Param name=strHeatID//炉号</Param>
	/// </Method>
	L3RECORDSET GetSteelGradeByHeatID(LPCTSTR strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetLatelyNewHeatChemicalData" type="L3RECORDSET">
	/// 获取最进人工新增的炉次成分数据
	/// <Param name=//</Param>
	/// </Method>
	L3RECORDSET GetLatelyNewHeatChemicalData();

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetApplyDataByApplyID" type="L3RECORDSET">
	/// 获取最进人工新增的炉次成分数据
	/// <Param name=strApplyID//</Param>
	/// </Method>
	L3RECORDSET GetApplyDataByApplyID(L3STRING strApplyID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetApplyDataByApplyID" type="L3RECORDSET">
	/// 根据委托单号获取委托单数据
	/// <Param name=strApplyID//</Param>
	/// </Method>
	L3RECORDSET GetApplyIDByHeatIDAndAddr(L3STRING strHeatID,L3STRING strAddr);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetCutAdviceData" type="L3RECORDSET">
	/// 获取最进割样通知数据
	/// <Param name=//</Param>
	/// </Method>
	L3RECORDSET GetCutAdviceData();

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetSteelGradeByHeatID" type="L3RECORDSET">
	/// 根据炉号获取钢种
	/// <Param name=//</Param>
	/// </Method>
	L3RECORDSET GetGradeByHeatID(L3STRING strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="DeleteCutAdvice" type="L3LONG">
	/// 删除割样通知
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteCutAdvice(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetFinalActualHeatChemicalByHeatID" type="L3LONG">
	/// 根据炉号获取最终实际成份数据
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetFinalActualHeatChemicalByHeatID(L3STRING strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetFinalStandardHeatChemicalByHeatID" type="L3LONG">
	/// 根据炉号获取最终标准成份数据
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetFinalStandardHeatChemicalByHeatID(L3STRING strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetReHeatCount" type="L3LONG">
	/// 获取重处理次数
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// <Param name="nUnitType" type="L3LONG"></Param>
	/// <Param name="nUnitID" type="L3LONG"></Param>
	/// </Method>
	L3LONG GetReHeatCount(L3STRING strHeatID,L3LONG nUnitType,L3LONG nUnitID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="NewHeatExceptionData" type="L3LONG">
	/// 生产新的炉次工艺异常数据
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// <Param name="nUnitType" type="L3LONG"></Param>
	/// <Param name="nUnitID" type="L3LONG"></Param>
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewHeatExceptionData(L3STRING strHeatID,L3LONG nUnitType,L3LONG nUnitID,L3RECORDSET rsData);
    L3LONG LogHeatExceptionData(L3SHORT nUnitTypeID,
													 L3SHORT nUnitID, 
													 L3STRING strHeatID, 
													 L3SHORT nProcessCount, 
													 L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptBFIronElementData" type="L3LONG">
	/// 接收高炉铁水样实绩
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  AcceptBFIronElementData(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GenLabSheet" type="L3LONG">
	/// 生成化验委托单据
	/// <Param name="strSampleType" type="L3STRING">试样类别</Param>
	/// <Param name="strAddr" type="L3STRING">取样地点</Param>
	/// <Param name="strHeatID" type="L3STRING">炉号</Param>
	/// <Param name="nFinalFlag" type="L3STRING">成品样标志</Param>
	/// </Method>
	L3RECORDSET  GenLabSheet(L3STRING strSampleType,L3STRING strAddr,L3STRING strHeatID,L3LONG nFinalFlag);

	    ////一键发送委托单
	L3LONG  GenLabSheetNew(L3STRING strSampleType,L3STRING strAddr,L3STRING strHeatID,L3STRING strSteelGradeIndex,L3LONG nFinalFlag);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSteelElementText" type="L3LONG">
	/// 接收钢样检化验结果(文本)
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabSteelElementText(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSlagElementText" type="L3LONG">
	/// 接收渣样检化验结果(文本)
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
	/// </Method>
	L3LONG  AcceptSlagElementText(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabIronElement" type="L3LONG">
	/// 接收铁样检化验结果
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabIronElement(L3RECORDSET rsData);


	/// <Method class="CQA_HeatChemicalData_Mag" name="SendSheetDataToAnaL2" type="L3BOOL">
	/// 将委托单下传检化验 2009-01-03 
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL  SendSheetDataToAnaL2(L3RECORDSET rsData);


	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabIronElement" type="L3LONG">
	/// 接收铁样检化验结果
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabIronElementText(L3RECORDSET rsData);


	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptErrorInfo" type="L3LONG">
	/// 接收化验单回退信息2009-01-03 tangyi
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
	/// </Method>
	L3LONG  AcceptErrorInfo (L3RECORDSET rsData);


	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptReSampleInfor" type="L3LONG">
	/// 接收重新取样指示2009-01-03 tangyi
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
	/// </Method>
	L3LONG  AcceptReSampleInfor (L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="SendAnalysisDataToPLC" type="L3BOOL">
	/// 将高拉碳炉终样下传PLC 2009-03-21
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL  SendAnalysisDataToPLC(L3FLOAT C_Ana,L3FLOAT S_Ana,L3FLOAT P_Ana);

	/// <Method class="CQA_HeatChemicalData_Mag" name="NewBFIronSheet" type="L3LONG">
	/// 生成铁沟样化验委托单据
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  NewBFIronSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronSampleCode" type="CString">
	/// 计算脱硫铁水试样编码
	/// <Param name="csTAPNo" type="LPCTSTR"> 铁次号
	/// <Param name="iMode" type="LPCTSTR"> 脱硫前后标识
	/// </Method>
	CString  CalDesIronSampleCode(LPCTSTR csTAPNo,LPCTSTR csTPCNo,L3SHORT iMode);

	/// <Method class="CQA_HeatChemicalData_Mag" name="NewDeSIronSheet" type="L3LONG">
	/// 生成脱硫预处理样化验委托单据
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  NewDeSIronSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="NewBFSlagSheet" type="L3LONG">
	/// 生成铁样化验委托单据
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  NewBFSlagSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="SetDeSAnalysisData" type="L3BOOL">
	/// 设置脱硫分析数据 2009-10-25 yao
	/// <Param name="SampleCode" type="LPCTSTR"> 试样编码号
	/// <Param name="S" type="L3FLOAT"> 硫
	/// <Param name="P" type="L3FLOAT"> 磷
	/// </Method>
	L3BOOL  SetDeSAnalysisData(LPCTSTR SampleCode,L3FLOAT S,L3FLOAT P);

};

// 逻辑类CQA_Lab_Sheet_App头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Lab_Sheet_App :
	public CL3Object
{
public:
	CQA_Lab_Sheet_App(void);
	virtual ~CQA_Lab_Sheet_App(void);

	DECLARE_L3CLASS(CQA_Lab_Sheet_App,XGMESLogic\\QualityMag, AppID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_Sheet_App)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

public:
	///下传检化验枚举
	enum _SendEnum
	{
		NotSendLab = 0,				// 未下传检化验
		SendLab = 1,				// 已下传检化验
	};
	enum _BackEnum
	{
		NotBack = 0,				// 未回退
		IsBack = 1,				    // 已回退
	};

	/// <Property class="CQA_Lab_Sheet_App" name="AppID" type="L3STRING">
	/// 委托单编号
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Lab_Sheet_App" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Code" type="L3STRING">
	/// 试样编码
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Code)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Address" type="L3STRING">
	/// 取样地点
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Type" type="L3STRING">
	/// 试样类别
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Type)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Count" type="L3STRING">
	/// 取样次数
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Count)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Date" type="L3DATETIME">
	/// 取样时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Sample_Date)

	/// <Property class="CQA_Lab_Sheet_App" name="Fin_Prod_Flag" type="L3SHORT">
	/// 成品样标志
	/// </Property>
	DECLARE_L3PROP_LONG(Fin_Prod_Flag)

	/// <Property class="CQA_Lab_Sheet_App" name="Asis_Flag" type="L3SHORT">
	/// 正副样标志
	/// </Property>
	DECLARE_L3PROP_LONG(Asis_Flag)

	/// <Property class="CQA_Lab_Sheet_App" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_Lab_Sheet_App" name="Treaty" type="L3STRING">
	/// 协议
	/// </Property>
	DECLARE_L3PROP_STRING(Treaty)

	/// <Property class="CQA_Lab_Sheet_App" name="Back_Flag" type="L3SHORT">
	/// 回退标志，0：未回退，1：回退
	/// </Property>
	DECLARE_L3PROP_LONG(Back_Flag)

	/// <Property class="CQA_Lab_Sheet_App" name="Back_Date" type="L3DATETIME">
	/// 回退时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Back_Date)

	/// <Property class="CQA_Lab_Sheet_App" name="ReSample_Flag" type="L3SHORT">
	/// 重新取样标志，0：正常，1：要求重新取样
	/// </Property>
	DECLARE_L3PROP_LONG(ReSample_Flag)

	/// <Property class="CQA_Lab_Sheet_App" name="ReSample_Reason" type="L3STRING">
	/// 重新取样原因
	/// </Property>
	DECLARE_L3PROP_STRING(ReSample_Reason)

	/// <Property class="CQA_Lab_Sheet_App" name="ReSample_Date" type="L3DATETIME">
	/// 重取样申请时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(ReSample_Date)

	/// <Property class="CQA_Lab_Sheet_App" name="SendFlag" type="L3LONG">
	/// 发送标识
	/// </Property>
	DECLARE_L3PROP_LONG(SendFlag)

	/// <Property class="CQA_Lab_Sheet_App" name="ReSampled" type="L3LONG">
	/// 已重取样
	/// </Property>
	DECLARE_L3PROP_LONG(ReSampled)

};

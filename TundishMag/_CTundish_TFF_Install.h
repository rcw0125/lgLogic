// 逻辑类CTundish_TFF_Install头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_TFF_Install :
	public CL3Object
{
public:
	CTundish_TFF_Install(void);
	virtual ~CTundish_TFF_Install(void);

	DECLARE_L3CLASS(CTundish_TFF_Install,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_TFF_Install)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTundish_TFF_Install" name="TundishID" type="L3STRING">
	/// 中包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_TFF_Install" name="WorkID" type="L3STRING">
	/// 中包工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_TFF_Install" name="Daub_Fac" type="L3STRING">
	/// 涂料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Daub_Fac)

	/// <Property class="CTundish_TFF_Install" name="Refra_Fac" type="L3STRING">
	/// 耐材性质
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CTundish_TFF_Install" name="Fra_Switch_Case" type="L3STRING">
	/// 机构闸刀情况
	/// </Property>
	DECLARE_L3PROP_STRING(Fra_Switch_Case)

	/// <Property class="CTundish_TFF_Install" name="Con_Per" type="L3STRING">
	/// 确认人
	/// </Property>
	DECLARE_L3PROP_STRING(Con_Per)

	/// <Property class="CTundish_TFF_Install" name="Gap_Fac" type="L3STRING">
	/// 上水口厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Gap_Fac)

	/// <Property class="CTundish_TFF_Install" name="Gap_Pro_Date" type="L3DATETIME">
	/// 水口生产日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Gap_Pro_Date)

	/// <Property class="CTundish_TFF_Install" name="First_Gap_ID" type="L3STRING">
	/// 1流水口编号
	/// </Property>
	DECLARE_L3PROP_STRING(First_Gap_ID)

	/// <Property class="CTundish_TFF_Install" name="Second_Gap_ID" type="L3STRING">
	/// 2流水口编号
	/// </Property>
	DECLARE_L3PROP_STRING(Second_Gap_ID)

	/// <Property class="CTundish_TFF_Install" name="Third_Gap_ID" type="L3STRING">
	/// 3流水口编号
	/// </Property>
	DECLARE_L3PROP_STRING(Third_Gap_ID)

	/// <Property class="CTundish_TFF_Install" name="Fourth_Gap_ID" type="L3STRING">
	/// 4流水口编号
	/// </Property>
	DECLARE_L3PROP_STRING(Fourth_Gap_ID)

	/// <Property class="CTundish_TFF_Install" name="Stu_Sti_Fac" type="L3STRING">
	/// 塞棒厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Stu_Sti_Fac)

	/// <Property class="CTundish_TFF_Install" name="Stu_Sti_Pro_Date" type="L3DATETIME">
	/// 塞棒生产日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Stu_Sti_Pro_Date)

	/// <Property class="CTundish_TFF_Install" name="First_Stu_Sti_ID" type="L3STRING">
	/// 1流塞棒编号
	/// </Property>
	DECLARE_L3PROP_STRING(First_Stu_Sti_ID)

	/// <Property class="CTundish_TFF_Install" name="Second_Stu_Sti_ID" type="L3STRING">
	/// 2流塞棒编号
	/// </Property>
	DECLARE_L3PROP_STRING(Second_Stu_Sti_ID)

	/// <Property class="CTundish_TFF_Install" name="Third_Stu_Sti_ID" type="L3STRING">
	/// 3流塞棒编号
	/// </Property>
	DECLARE_L3PROP_STRING(Third_Stu_Sti_ID)

	/// <Property class="CTundish_TFF_Install" name="Fourth_Stu_Sti_ID" type="L3STRING">
	/// 4流塞棒编号
	/// </Property>
	DECLARE_L3PROP_STRING(Fourth_Stu_Sti_ID)

	/// <Property class="CTundish_TFF_Install" name="Install_Per" type="L3STRING">
	/// 安装人
	/// </Property>
	DECLARE_L3PROP_STRING(Install_Per)

	/// <Property class="CTundish_TFF_Install" name="Install_Time" type="L3DATETIME">
	/// 安装日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Time)

	/// <Property class="CTundish_TFF_Install" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)
	
	/// <Property class="CTundish_TFF_Install" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};

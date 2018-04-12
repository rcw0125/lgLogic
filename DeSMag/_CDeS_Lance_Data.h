// 逻辑类CDeS_Lance_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDeS_Lance_Data :
	public CL3Object
{
public:
	CDeS_Lance_Data(void);
	virtual ~CDeS_Lance_Data(void);

		// 喷枪状态枚举
	enum _LanceStatusEnum
	{
		lancePrepare = 1,			// 准备
		lanceOnline = 2,			// 在用
		lanceMaintain = 3,	        // 维修
		lanceOffline = 4,	        // 下线
		lanceDeleted = 5,			// 废弃
	};

	DECLARE_L3CLASS(CDeS_Lance_Data,XGMESLogic\\DeSMag, LanceNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Lance_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CDeS_Lance_Data" name="LanceNo" type="L3STRING">
	/// 喷枪号
	/// </Property>
	DECLARE_L3PROP_STRING(LanceNo)

	/// <Property class="CDeS_Lance_Data" name="Status" type="L3LONG">
	/// 喷枪状态
	/// 备用
	/// 在线
	/// 待修
	/// 下线
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CDeS_Lance_Data" name="LanceAge" type="L3LONG">
	/// 喷枪枪龄
	/// </Property>
	DECLARE_L3PROP_LONG(LanceAge)

	/// <Property class="CDeS_Lance_Data" name="LanceVendor" type="L3STRING">
	/// 喷枪厂家
	/// </Property>
	DECLARE_L3PROP_STRING(LanceVendor)

	/// <Property class="CDeS_Lance_Data" name="ProcessTime" type="L3LONG">
	/// 作业时间
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessTime)

	/// <Property class="CDeS_Lance_Data" name="ProcessAmount" type="L3DOUBLE">
	/// 脱硫量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ProcessAmount)

	/// <Property class="CDeS_Lance_Data" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CDeS_Lance_Data" name="OpTime" type="L3DATETIME">
	/// 操作时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(OpTime)

};

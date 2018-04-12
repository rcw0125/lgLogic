// 逻辑类CDeS_Process_Satus头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CDeS_Process_Satus :
	public CL3Object
{
public:
	CDeS_Process_Satus(void);
	virtual ~CDeS_Process_Satus(void);

	DECLARE_L3CLASS(CDeS_Process_Satus,XGMESLogic\\DeSMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Process_Satus)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();
	/// <Property class="CDeS_Process_Satus" name="ID_Object" type="L3STRING">
	/// 对象标识
	/// (铁次+罐号)
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)

	/// <Property class="CDeS_Process_Satus" name="Status" type="L3SHORT">
	/// 作业状态
	/// (1:准备脱硫;
	///  2:铁罐进站;
	///  3:预捞渣开始;
	///  4:预捞渣结束;
	///  5:喷吹开始;
	///  6:喷吹结束;
	///  7:捞渣开始;
	///  8:捞渣结束;
	///  9:铁罐出站)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CDeS_Process_Satus" name="Change_Time" type="L3DATETIME">
	/// 作业状态变化时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Time)

};

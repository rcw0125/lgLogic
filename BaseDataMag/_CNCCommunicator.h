// 逻辑类CNCCommunicator头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CNCCommunicator :
	public CL3Object
{
public:
	CNCCommunicator(void);
	virtual ~CNCCommunicator(void);

	DECLARE_L3CLASS(CNCCommunicator,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CNCCommunicator)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	
	/// <Method class="CNCCommunicator" name="SendCastIronDataToNC" type="LONG">
	/// 将铁水信息发送到NC系统。
	/// <Param name="rsIron" type="L3RECORDSET">包含铁水信息的记录集</Param>
	/// </Method>
	LONG SendCastIronDataToNC(L3RECORDSET rsIron);
};

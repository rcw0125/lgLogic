// 逻辑类CBloom_Store_Communicator头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "MESCommunicator.h"

class CBloom_Store_Communicator :
	public MESCommunicator
{
public:
	CBloom_Store_Communicator(void);
	virtual ~CBloom_Store_Communicator(void);

	DECLARE_L3CLASS(CBloom_Store_Communicator,XGMESLogic\\BloomStoreMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Store_Communicator)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

protected:
	/// <summary>
	/// 检查收到的电文的有效性
	/// ARG >> lpcszSender : 电文发送者标识名
	///		>> lpcszTelType : 电文类型
	///		>> lpcszTelID : 电文编号
	///		>> rsTelData : 电文数据
	/// RET << 返回FALSE系统将忽略此电文。返回TRUE系统继续处理此电文。
	/// </summary>
	virtual BOOL CheckRecvTelegram(LPCTSTR lpcszSender,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
	/// <summary>
	/// 接收电文流量控制。继承类重载此函数实行密集电文的流量控制。
	/// ARG >> lpcszSender : 电文发送者标识名
	///		>> lpcszTgt : 电文的目的对象URI
	///		>> lpcszTelType : 电文类型
	///		>> lpcszTelID : 电文编号
	///		>> rsTelData : 电文数据。流量控制将可能修改此
	/// RET << 流量控制结果。参见RecvPaceCtrlResult
	/// </summary>
	virtual DWORD RecvPaceControl(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
	/// <summary>
	/// 获取电文目的对象的URI
	/// ARG >> lpcszSender : 电文发送者标识名
	///		>> lpcszTelType : 电文类型
	///		>> lpcszTelID : 电文编号
	///		>> rsTelData : 电文数据
	/// RET << 接收此电文的对象的URI
	virtual CString GetTelegramTarget(LPCTSTR lpcszSender,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
	/// <summary>
	/// 缓存收到电文数据。继承类可重载此方法进行特殊的电文缓存机制。如：对短间隔的累计量电文，不采用插入，而是采用累加的方式保存数据。
	/// ARG >> lpcszSender : 电文发送者标识名
	///		>> lpcszTgt : 电文的目的对象URI
	///		>> lpcszTelType : 电文类型
	///		>> lpcszTelID : 电文编号
	///		>> rsTelData : 电文数据
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL CacheRecvTelegramData(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
	/// <summary>
	/// 返回电文类型对应的MES系统电文数据类的URI
	/// ARG >> lpczTelType : 电文类型名。
	/// RET << 电文数据类的URI。
	/// </summary>
	virtual CString GetTelegramDataType(LPCTSTR lpcszType);
	/// <summary>
	/// 接收电文处理逻辑。继承类重载此函数进行电文的实际接收处理工作。如通知机组进行相关动作等。
	/// ARG >> lpcszSender : 电文发送者标识名
	///		>> lpcszTgt : 电文的目的对象URI
	///		>> lpcszTelType : 电文类型
	///		>> lpcszTelID : 电文编号
	///		>> lpcszDataType : 电文数据缓存类型
	///		>> rsTelData : 电文数据
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL DoAcceptTelegram(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,LPCTSTR lpcszDataType,L3RECORDSET rsTelData);
	/// <summary>
	/// 返回电文对应的逻辑事件的类型
	/// ARG >> lpcszSender : 电文发送者标识名
	///		>> lpcszTgt : 电文的目的对象URI
	///		>> lpcszTelType : 电文类型
	///		>> lpcszTelID : 电文编号
	///		>> rsTelData : 电文数据
	/// RET << 逻辑事件类型
	/// </summary>
	virtual CString GetRecvTelEventType(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData);
	/// <summary>
	/// 准备接收电文事件数据。继承类重载此函数补齐电文接收事件的额外参数。
	/// ARG >> evt : 事件对象.
	///		>> lpcszSender : 电文发送者标识名
	///		>> lpcszTgt : 电文的目的对象URI
	///		>> lpcszTelType : 电文类型
	///		>> lpcszTelID : 电文编号
	///		>> lpcszDataType : 电文数据缓存类型
	///		>> rsTelData : 电文数据
	///	RET << void
	/// </summary>
	virtual void PrepareRecvEvent(CL3EventWrap& evt,LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,LPCTSTR lpcszDataType,L3RECORDSET rsTelData);

	/// <summary>
	/// 实际的发送电文方法。继承类重载此方法进行电文通讯
	/// ARG >> Sender : 发送电文的对象的URI.
	///		>> Receiver : 电文接收者标识名
	///		>> TelegramType : 电文类型
	///		>> TelegramID : 电文编号
	///		>> rsTelegram : 电文数据
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual L3BOOL DoSendTelegram(L3STRING Sender,L3STRING Receiver,L3STRING TelegramType,L3STRING TelegramID,L3RECORDSET rsTelegram);

};

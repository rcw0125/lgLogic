// 逻辑类CAlloy_Store_Communicator的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CAlloy_Store_Communicator.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CAlloy_Store_Communicator.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CAlloy_Store_Communicator.h"

//当对象被装载到系统中时，被调用
void CAlloy_Store_Communicator::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CAlloy_Store_Communicator::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <summary>
/// 检查收到的电文的有效性
/// ARG >> lpcszSender : 电文发送者标识名
///		>> lpcszTelType : 电文类型
///		>> lpcszTelID : 电文编号
///		>> rsTelData : 电文数据
/// RET << 返回FALSE系统将忽略此电文。返回TRUE系统继续处理此电文。
/// </summary>
BOOL CAlloy_Store_Communicator::CheckRecvTelegram(LPCTSTR lpcszSender,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::CheckRecvTelegram( lpcszSender, lpcszTelType, lpcszTelID, rsTelData);
}

/// <summary>
/// 接收电文流量控制。继承类重载此函数实行密集电文的流量控制。
/// ARG >> lpcszSender : 电文发送者标识名
///		>> lpcszTgt : 电文的目的对象URI
///		>> lpcszTelType : 电文类型
///		>> lpcszTelID : 电文编号
///		>> rsTelData : 电文数据。流量控制将可能修改此
/// RET << 流量控制结果。参见RecvPaceCtrlResult
/// </summary>
DWORD CAlloy_Store_Communicator::RecvPaceControl(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::RecvPaceControl( lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, rsTelData);
}

/// <summary>
/// 获取电文目的对象的URI
/// ARG >> lpcszSender : 电文发送者标识名
///		>> lpcszTelType : 电文类型
///		>> lpcszTelID : 电文编号
///		>> rsTelData : 电文数据
/// RET << 接收此电文的对象的URI
CString CAlloy_Store_Communicator::GetTelegramTarget(LPCTSTR lpcszSender,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetTelegramTarget( lpcszSender, lpcszTelType, lpcszTelID, rsTelData);
}

/// <summary>
/// 缓存收到电文数据。继承类可重载此方法进行特殊的电文缓存机制。如：对短间隔的累计量电文，不采用插入，而是采用累加的方式保存数据。
/// ARG >> lpcszSender : 电文发送者标识名
///		>> lpcszTgt : 电文的目的对象URI
///		>> lpcszTelType : 电文类型
///		>> lpcszTelID : 电文编号
///		>> rsTelData : 电文数据
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
BOOL CAlloy_Store_Communicator::CacheRecvTelegramData(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::CacheRecvTelegramData( lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, rsTelData);
}

/// <summary>
/// 返回电文类型对应的MES系统电文数据类的URI
/// ARG >> lpczTelType : 电文类型名。
/// RET << 电文数据类的URI。
/// </summary>
CString CAlloy_Store_Communicator::GetTelegramDataType(LPCTSTR lpcszType)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetTelegramDataType( lpcszType);
}

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
BOOL CAlloy_Store_Communicator::DoAcceptTelegram(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,LPCTSTR lpcszDataType,L3RECORDSET rsTelData)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::DoAcceptTelegram( lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, lpcszDataType, rsTelData);
}

/// <summary>
/// 返回电文对应的逻辑事件的类型
/// ARG >> lpcszSender : 电文发送者标识名
///		>> lpcszTgt : 电文的目的对象URI
///		>> lpcszTelType : 电文类型
///		>> lpcszTelID : 电文编号
///		>> rsTelData : 电文数据
/// RET << 逻辑事件类型
/// </summary>
CString CAlloy_Store_Communicator::GetRecvTelEventType(LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,L3RECORDSET rsTelData)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::GetRecvTelEventType( lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, rsTelData);
}

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
void CAlloy_Store_Communicator::PrepareRecvEvent(CL3EventWrap& evt,LPCTSTR lpcszSender,LPCTSTR lpcszTgt,LPCTSTR lpcszTelType,LPCTSTR lpcszTelID,LPCTSTR lpcszDataType,L3RECORDSET rsTelData)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::PrepareRecvEvent( evt, lpcszSender, lpcszTgt, lpcszTelType, lpcszTelID, lpcszDataType, rsTelData);
}

/// <summary>
/// 实际的发送电文方法。继承类重载此方法进行电文通讯
/// ARG >> Sender : 发送电文的对象的URI.
///		>> Receiver : 电文接收者标识名
///		>> TelegramType : 电文类型
///		>> TelegramID : 电文编号
///		>> rsTelegram : 电文数据
/// RET << 成功返回TRUE；失败返回FALSE。
/// </summary>
L3BOOL CAlloy_Store_Communicator::DoSendTelegram(L3STRING Sender,L3STRING Receiver,L3STRING TelegramType,L3STRING TelegramID,L3RECORDSET rsTelegram)
{
	// TODO: 在此处编辑相关功能的处理代码

	return __super::DoSendTelegram( Sender, Receiver, TelegramType, TelegramID, rsTelegram);
}


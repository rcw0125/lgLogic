//#import "..\\..\\bin\\unicode debug\\l3clientif.dll" no_namespace

#pragma once

#define MSG_LOGICREQ 202

typedef struct _QueueNode
{
	struct _QueueNode * pNext;
	CString csTelegramID;
	CString csTelegram;
}QueueNode,* PQueueNode;

class CL2CommLogic:public CL3Object
{
public:
	CL2CommLogic(void);
	~CL2CommLogic(void);

	DECLARE_L3CLASS(CL2CommLogic,L3\\AppLogic,nickname)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CL2CommLogic)



	DECLARE_L3PROP_STRING(varL2CommNotify)//用于通知通讯进程向L2发送数据
	DECLARE_L3PROP_LONG(varL2CommWorkshopID)//用于通知通讯进程WorkshopID
	DECLARE_L3PROP_LONG(varL2CommBeginTrans)//用于通知通讯进程事务开始
	DECLARE_L3PROP_LONG(varL2CommCommitTrans)//用于通知通讯进程事务提交
	DECLARE_L3PROP_LONG(varL2CommRollbackTrans)//用于通知通讯进程事务回退
	
	DECLARE_L3PROP_LONG(varL2CommStopWorkshop)//用于通知通讯进程停止某一工位
	DECLARE_L3PROP_LONG(varL2CommStartWorkshop)//用于通知通讯启动某一工位
	DECLARE_L3PROP_LONG(varL2CommModifyWorkshopID)//用于通知通讯进程要更改的工位号

	CString strRecordJunc;
	CRITICAL_SECTION cs,fcs;

	BOOL bAppError;
	CString csLogFile;

	L3BOOL ParseNewL2Data(L3LONG nCount,L3STRING FieldTypes,L3STRING FieldNames,L3STRING FieldData,L3STRING strURI,L3STRING strMethod);
	L3BOOL ReqSendL3DataToL2(L3LONG nWorkshopID,L3STRING strTelegramID,L3RECORDSET rsData);
	L3STRING GetLogicTelegram();

	void L3BeginTrans(L3LONG nWorkshopID);
	void L3CommitTrans(L3LONG nWorkshopID);
	void L3RollbackTrans(L3LONG nWorkshopID);

	void L3ReqStopWorkshop(L3LONG nWorkshopID);
	void L3ReqStartWorkshop(L3LONG nWorkshopID);

	void L3OnCommStart(L3VOID);

	void LogAppError(CString csError);
	CString FormString(CString cstr);

protected:
	//PQueueNode pReqQueue;//电文队列指针
	//void PostReqQueue(CString csTelegramID,CString csTelegram);//将L3要求向L4发送的电文排入队列
	//CString GetReqQueue();//从电文队列中取出最前端的电文
	//BOOL m_bNotify;
	BOOL m_bBeginTrans;
	BOOL m_bCommitTrans;
	BOOL m_bRollbackTrans;

	BOOL m_bStopWorkshopNotify,m_bStartWorkshopNotify;
};

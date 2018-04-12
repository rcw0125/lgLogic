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



	DECLARE_L3PROP_STRING(varL2CommNotify)//����֪ͨͨѶ������L2��������
	DECLARE_L3PROP_LONG(varL2CommWorkshopID)//����֪ͨͨѶ����WorkshopID
	DECLARE_L3PROP_LONG(varL2CommBeginTrans)//����֪ͨͨѶ��������ʼ
	DECLARE_L3PROP_LONG(varL2CommCommitTrans)//����֪ͨͨѶ���������ύ
	DECLARE_L3PROP_LONG(varL2CommRollbackTrans)//����֪ͨͨѶ�����������
	
	DECLARE_L3PROP_LONG(varL2CommStopWorkshop)//����֪ͨͨѶ����ֹͣĳһ��λ
	DECLARE_L3PROP_LONG(varL2CommStartWorkshop)//����֪ͨͨѶ����ĳһ��λ
	DECLARE_L3PROP_LONG(varL2CommModifyWorkshopID)//����֪ͨͨѶ����Ҫ���ĵĹ�λ��

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
	//PQueueNode pReqQueue;//���Ķ���ָ��
	//void PostReqQueue(CString csTelegramID,CString csTelegram);//��L3Ҫ����L4���͵ĵ����������
	//CString GetReqQueue();//�ӵ��Ķ�����ȡ����ǰ�˵ĵ���
	//BOOL m_bNotify;
	BOOL m_bBeginTrans;
	BOOL m_bCommitTrans;
	BOOL m_bRollbackTrans;

	BOOL m_bStopWorkshopNotify,m_bStartWorkshopNotify;
};

// �߼���CBFIronInLogͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialInputLog.h"

class CBFIronInLog :
	public MaterialInputLog
{
public:
	CBFIronInLog(void);
	virtual ~CBFIronInLog(void);

	DECLARE_L3CLASS(CBFIronInLog,XGMESLogic\\BFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBFIronInLog)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

};

// �߼���XGStoreAreaͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialStoreArea.h"

class XGStoreArea :
	public MaterialStoreArea
{
public:
	XGStoreArea(void);
	virtual ~XGStoreArea(void);

	DECLARE_L3CLASS(XGStoreArea,XGMESLogic\\BaseDataMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(XGStoreArea)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:
	 ////<summary>
	 ////����λ�ñ�����麯�����̳���������ش˺��������Լ���λ�ñ��붨�塣
	 ////ARG >> void
	 ////RET << λ�ñ���
	 ////</summary>
	virtual CString GetPositionCode();

	virtual double GetAmountTolerance();//2009-03-27
};

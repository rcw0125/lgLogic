// �߼���UnitOperatorͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CUnitOperator :
	public CL3Object
{
public:
	CUnitOperator(void);
	virtual ~CUnitOperator(void);

	DECLARE_L3CLASS(CUnitOperator,XGMESLogic\\ShiftTeamMag, L3Index)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CUnitOperator)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();


	DECLARE_L3PROP_SHORT(L3Index)				//����
	DECLARE_L3PROP_STRING(UnitIndex)			//����+��λ
	DECLARE_L3PROP_STRING(Operator)			//������

};

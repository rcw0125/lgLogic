// �߼���UnitTimeInfoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CUnitTimeInfo :
	public CL3Object
{
public:
	CUnitTimeInfo(void);
	virtual ~CUnitTimeInfo(void);

	DECLARE_L3CLASS(CUnitTimeInfo,XGMESLogic\\ShiftTeamMag, L3Index)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CUnitTimeInfo)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	DECLARE_L3PROP_SHORT(L3Index)				//����
	DECLARE_L3PROP_STRING(UnitIndex)			//����+��λ
	DECLARE_L3PROP_STRING(ShiftType)			//��������
	DECLARE_L3PROP_SHORT(ShiftID)				//���
	DECLARE_L3PROP_STRING(UnitTypeID)			//����
	DECLARE_L3PROP_STRING(UnitTypeIDDesc)		//��������
	DECLARE_L3PROP_STRING(UnitID)				//��λ
	DECLARE_L3PROP_STRING(UnitIDDesc)			//��λ����
	DECLARE_L3PROP_DATETIME(BeginProcessTime)	//��ʼʱ��
	DECLARE_L3PROP_DATETIME(EndProcessTime)		//����ʱ��
};

// �߼���ShiftMagͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CShiftMag :
	public CL3Object
{
public:
	CShiftMag(void);
	virtual ~CShiftMag(void);

	DECLARE_L3CLASS(CShiftMag,XGMESLogic\\ShiftTeamMag, L3Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(ShiftMag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	DECLARE_L3PROP_STRING(L3Name)				//����
	////�Զ�����
	//L3BOOL AutoModifyProcessShift(L3STRING str);
	L3BOOL AutoModifyProcessShift();
	////�õ���ΰ���˳��
	L3RECORDSET GetShiftTeamOrder();
	//�ύ��ΰ���˳��
	L3BOOL CommitShiftTeamOrder(L3RECORDSET rs);
	//ɾ����ΰ���˳��
	L3BOOL DeleteShiftTeamOrder();
	////�õ�����ʱ��
	L3RECORDSET GetUnitTime();
	//�ύ����ʱ��
	L3BOOL CommitUnitTime(L3RECORDSET rs);
	//ɾ�����һ������ʱ��
	L3BOOL DeleteUnitTime();
	////�õ����������
	L3RECORDSET GetUnitOperator();
	//�ύ���������
	L3BOOL CommitUnitOperator(L3RECORDSET rs);
	//ɾ�����һ�����������
	L3BOOL DeleteUnitOperator();
	//�õ���ΰ��
	L3RECORDSET GetShiftTeamID(L3STRING str);
	//�õ���ǰ��ΰ���Լ�ά��ǰ̨����
	L3RECORDSET GetCurrentShiftTeamID(L3SHORT shortTemp);
	//��̨�õ���ǰ��ΰ��
	L3RECORDSET GetSessionShiftTeam();
	//���þ���ֵ
	L3BOOL AutoWarning();


};

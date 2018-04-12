// �߼���CurrentShiftInfoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCurrentShiftInfo :
	public CL3Object
{
public:
	CCurrentShiftInfo(void);
	virtual ~CCurrentShiftInfo(void);

	DECLARE_L3CLASS(CCurrentShiftInfo,XGMESLogic\\ShiftTeamMag, L3Index)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCurrentShiftInfo)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCurrentShiftInfo" name="L3Index" type="L3STRING">
	/// ����+��λ
	/// </Property>
	DECLARE_L3PROP_STRING(L3Index)

	/// <Property class="CCurrentShiftInfo" name="ShiftType" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftType)

	/// <Property class="CCurrentShiftInfo" name="ShiftID" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_SHORT(ShiftID)

	/// <Property class="CCurrentShiftInfo" name="TeamID" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_SHORT(TeamID)

	/// <Property class="CCurrentShiftInfo" name="UnitTypeID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(UnitTypeID)

	/// <Property class="CCurrentShiftInfo" name="UnitID" type="L3STRING">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CCurrentShiftInfo" name="CurrentID" type="L3SHORT">
	/// ��ǰ������
	/// </Property>
	DECLARE_L3PROP_SHORT(CurrentID)

	/// <Property class="CCurrentShiftInfo" name="BeginProcessTime" type="L3DATETIME">
	/// ��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(BeginProcessTime)

	/// <Property class="CCurrentShiftInfo" name="EndProcessTime" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(EndProcessTime)

	/// <Property class="CCurrentShiftInfo" name="ShiftWarning" type="L3STRING">
	/// �����־
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftWarning)

};

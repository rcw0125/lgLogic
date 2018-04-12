// �߼���ShiftTeamOrderͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CShiftTeamOrder :
	public CL3Object
{
public:
	CShiftTeamOrder(void);
	virtual ~CShiftTeamOrder(void);

	DECLARE_L3CLASS(CShiftTeamOrder,XGMESLogic\\ShiftTeamMag, L3Index)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CShiftTeamOrder)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CShiftTeamOrder" name="L3Index" type="L3SHORT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_SHORT(L3Index)

	/// <Property class="CShiftTeamOrder" name="ShiftType" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftType)

	/// <Property class="CShiftTeamOrder" name="OrderIndex" type="L3SHORT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_SHORT(OrderIndex)

	/// <Property class="CShiftTeamOrder" name="ShiftID" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_SHORT(ShiftID)

	/// <Property class="CShiftTeamOrder" name="TeamID" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_SHORT(TeamID)

};

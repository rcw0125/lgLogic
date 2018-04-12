// �߼���CBOF_ChangeLanceReasonͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_ChangeLanceReason :
	public CL3Object
{
public:
	CBOF_ChangeLanceReason(void);
	virtual ~CBOF_ChangeLanceReason(void);

	DECLARE_L3CLASS(CBOF_ChangeLanceReason,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_ChangeLanceReason)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_ChangeLanceReason" name="BOFID" type="L3SHORT">
	/// ת¯¯����
	/// </Property>
	DECLARE_L3PROP_SHORT(BOFID)

	/// <Property class="CBOF_ChangeLanceReason" name="ChangeLance_Time" type="L3DATETIME">
	/// ��ǹʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(ChangeLance_Time)

	/// <Property class="CBOF_ChangeLanceReason" name="Reason" type="L3STRING">
	/// ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

};

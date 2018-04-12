// �߼���CRHL_Equipment_Statusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CRHL_Equipment_Status :
	public CL3Object
{
public:
	CRHL_Equipment_Status(void);
	virtual ~CRHL_Equipment_Status(void);

	DECLARE_L3CLASS(CRHL_Equipment_Status,XGMESLogic\\RHLMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRHL_Equipment_Status)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CRHL_Equipment_Status" name="LFID" type="L3SHORT">
	/// 
	/// LF¯¯����(1:LF1
	///            2:LF2
	///            3:LF3)
	/// </Property>
	DECLARE_L3PROP_SHORT(RHLID)

	/// <Property class="CRHL_Equipment_Status" name="Status" type="L3SHORT">
	/// 
	/// �豸״̬
	/// (1:����
	///  2:����
	///  3:�׹�
	///  4:��¯
	///  5:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CRHL_Equipment_Status" name="Log_Time" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

	/// <Property class="CRHL_Equipment_Status" name="Reason" type="L3STRING">
	/// ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

};

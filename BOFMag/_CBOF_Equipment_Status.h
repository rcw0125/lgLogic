// �߼���CBOF_Equipment_Statusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_Equipment_Status :
	public CL3Object
{
public:
	CBOF_Equipment_Status(void);
	virtual ~CBOF_Equipment_Status(void);

	DECLARE_L3CLASS(CBOF_Equipment_Status,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Equipment_Status)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_Equipment_Status" name="BOFID" type="L3SHORT">
	/// 
	/// ת¯¯����(1:BOF1
	///            2:BOF2
	///            3:BOF3
	///            4:BOF4)
	/// </Property>
	DECLARE_L3PROP_SHORT(BOFID)

	/// <Property class="CBOF_Equipment_Status" name="Status" type="L3SHORT">
	/// 
	/// �豸״̬
	/// (1:����
	///  2:����
	///  3:�׹�
	///  4:��¯
	///  5:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CBOF_Equipment_Status" name="Log_Time" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

	/// <Property class="CBOF_Equipment_Status" name="Reason" type="L3STRING">
	/// ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)
};

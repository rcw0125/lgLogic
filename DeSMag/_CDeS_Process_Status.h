// �߼���CDeS_Process_Statusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDeS_Process_Status :
	public CL3Object
{
public:
	CDeS_Process_Status(void);
	virtual ~CDeS_Process_Status(void);

	DECLARE_L3CLASS(CDeS_Process_Status,XGMESLogic\\DeSMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Process_Status)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();
	/// <Property class="CDeS_Process_Status" name="ID_Object" type="L3STRING">
	/// �����ʶ
	/// (����+�޺�)
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)

	/// <Property class="CDeS_Process_Status" name="Status" type="L3SHORT">
	/// ��ҵ״̬
	/// (1:׼������;
	///  2:���޽�վ;
	///  3:Ԥ������ʼ;
	///  4:Ԥ��������;
	///  5:�紵��ʼ;
	///  6:�紵����;
	///  7:������ʼ;
	///  8:��������;
	///  9:���޳�վ)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CDeS_Process_Status" name="Change_Time" type="L3DATETIME">
	/// ��ҵ״̬�仯ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Time)

	/// <Property class="CDeS_Process_Status" name="AreaID" type="L3STRING">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(AreaID)
};

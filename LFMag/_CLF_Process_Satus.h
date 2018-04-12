// �߼���CLF_Process_Satusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_Process_Satus :
	public CL3Object
{
public:
	CLF_Process_Satus(void);
	virtual ~CLF_Process_Satus(void);

	DECLARE_L3CLASS(CLF_Process_Satus,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Process_Satus)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_Process_Satus" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Process_Satus" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Process_Satus" name="Status" type="L3SHORT">
	/// 
	/// ״̬(1:��վ;
	///          2:����ʼ;
	///          3:����;
	///          4:��;
	///          5:�������)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CLF_Process_Satus" name="Change_Time" type="L3DATETIME">
	/// ״̬�仯ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Time)

};

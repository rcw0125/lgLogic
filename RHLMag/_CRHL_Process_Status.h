// �߼���CRHL_Process_Satusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CRHL_Process_Status :
	public CL3Object
{
public:
	CRHL_Process_Status(void);
	virtual ~CRHL_Process_Status(void);

	DECLARE_L3CLASS(CRHL_Process_Status,XGMESLogic\\RHLMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRHL_Process_Status)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CRHL_Process_Satus" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CRHL_Process_Satus" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CRHL_Process_Satus" name="Status" type="L3SHORT">
	/// 
	/// ״̬(1:��վ;
	///          2:����ʼ;
	///          3:����;
	///          4:��;
	///          5:�������)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CRHL_Process_Satus" name="Change_Time" type="L3DATETIME">
	/// ״̬�仯ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Time)

};

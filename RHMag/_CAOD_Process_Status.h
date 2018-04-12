// �߼���CAOD_Process_Statusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAOD_Process_Status :
	public CL3Object
{
public:
	CAOD_Process_Status(void);
	virtual ~CAOD_Process_Status(void);

	DECLARE_L3CLASS(CAOD_Process_Status,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Process_Status)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAOD_Process_Status" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Process_Status" name="Status" type="L3SHORT">
	/// 
	/// ״̬(1:�ӷϸֶ���;
	///          2:����;
	///          3:����;
	///          4:���ֿ�ʼ;
	///          5:���ֽ���;
	///          6:������ʼ;
	///          7:��������;
	///          8:������ʼ;
	///          0:��������[�ȴ�])
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)
	DECLARE_L3PROP_SHORT(Step)

	/// <Property class="CAOD_Process_Status" name="Change_Time" type="L3DATETIME">
	/// ״̬�仯ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Change_Time)

};

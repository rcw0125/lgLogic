// �߼���CBOF_MainPipe_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_MainPipe_Data :
	public CL3Object
{
public:
	CBOF_MainPipe_Data(void);
	virtual ~CBOF_MainPipe_Data(void);

	DECLARE_L3CLASS(CBOF_MainPipe_Data,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_MainPipe_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_MainPipe_Data" name="Flow" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow)

	/// <Property class="CBOF_MainPipe_Data" name="Pressure" type="L3FLOAT">
	/// ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Pressure)

	/// <Property class="CBOF_MainPipe_Data" name="Catch_Time" type="L3DATETIME">
	/// �ɼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

};

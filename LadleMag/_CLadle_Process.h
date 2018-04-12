// �߼���CLadle_Processͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Process :
	public CL3Object
{
public:
	CLadle_Process(void);
	virtual ~CLadle_Process(void);

	DECLARE_L3CLASS(CLadle_Process,XGMESLogic\\LadleMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Process)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Process" name="LadleID" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)
	
	/// <Property class="CLadle_Process" name="InnerID" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CLadle_Process" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Process" name="Online_Time" type="L3DATETIME">
	/// �ְ�����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Online_Time)

	/// <Property class="CLadle_Process" name="Online_HeatID" type="L3STRING">
	/// ����¯��
	/// </Property>
	DECLARE_L3PROP_STRING(Online_HeatID)

	/// <Property class="CLadle_Process" name="Offline_Time" type="L3DATETIME">
	/// �ְ�����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Offline_Time)

	/// <Property class="CLadle_Process" name="Offline_HeatID" type="L3STRING">
	/// ����¯��
	/// </Property>
	DECLARE_L3PROP_STRING(Offline_HeatID)

	/// <Property class="CLadle_Process" name="Comfirm_Flag" type="L3LONG">
	/// ˦��״̬ 0Ϊδ˦����1Ϊ��˦��
	/// </Property>
	DECLARE_L3PROP_LONG(Comfirm_Flag)

	/// <Property class="CLadle_Process" name="Throw_Time" type="L3DATETIME">
	/// ˦��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Throw_Time)

	/// <Property class="CLadle_Process" name="Ladle_Age" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Age)

};

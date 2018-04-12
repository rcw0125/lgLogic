// �߼���CDeS_Process_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDeS_Process_Data :
	public CL3Object
{
public:
	CDeS_Process_Data(void);
	virtual ~CDeS_Process_Data(void);

	DECLARE_L3CLASS(CDeS_Process_Data,XGMESLogic\\DeSMag, TreatNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Process_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDeS_Process_Data" name="TreatNo" type="L3STRING">
	/// �紵��
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CDeS_Process_Data" name="MaterialID" type="L3STRING">
	/// ��ˮID
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID)

	/// <Property class="CDeS_Process_Data" name="S_B" type="L3DOUBLE">
	/// ��ǰ��(%)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_B)

	/// <Property class="CDeS_Process_Data" name="S_A" type="L3DOUBLE">
	/// �Ѻ���(%)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_A)

	/// <Property class="CDeS_Process_Data" name="P_B" type="L3DOUBLE">
	/// ��ǰ��(%)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_B)

	/// <Property class="CDeS_Process_Data" name="P_A" type="L3DOUBLE">
	/// �Ѻ���(%)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_A)

	/// <Property class="CDeS_Process_Data" name="Mat_Consume" type="L3DOUBLE">
	/// ����þ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mat_Consume)

	/// <Property class="CDeS_Process_Data" name="LanceNo" type="L3STRING">
	/// ��ǹ��
	/// </Property>
	DECLARE_L3PROP_STRING(LanceNo)

	/// <Property class="CDeS_Process_Data" name="LanceAge" type="L3LONG">
	/// ǹ��
	/// </Property>
	DECLARE_L3PROP_LONG(LanceAge)

	/// <Property class="CDeS_Process_Data" name="BlowTime" type="L3LONG">
	/// �紵��ʱ
	/// </Property>
	DECLARE_L3PROP_LONG(BlowTime)

	/// <Property class="CDeS_Process_Data" name="BlowBeginTime" type="L3DATETIME">
	/// �紵��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(BlowBeginTime)

	/// <Property class="CDeS_Process_Data" name="BlowEndTime" type="L3DATETIME">
	/// �紵����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(BlowEndTime)

	/// <Property class="CDeS_Process_Data" name="AreaID" type="L3STRING">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(AreaID)
};

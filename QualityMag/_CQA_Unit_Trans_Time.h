// �߼���CQA_Unit_Trans_Timeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Unit_Trans_Time :
	public CL3Object
{
public:
	CQA_Unit_Trans_Time(void);
	virtual ~CQA_Unit_Trans_Time(void);

	DECLARE_L3CLASS(CQA_Unit_Trans_Time,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Unit_Trans_Time)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Unit_Trans_Time" name="Start_Unit" type="L3STRING">
	/// ��ʼ��λ��
	/// </Property>
	DECLARE_L3PROP_STRING(Start_Unit)

	/// <Property class="CQA_Unit_Trans_Time" name="End_Unit" type="L3STRING">
	/// ������λ
	/// </Property>
	DECLARE_L3PROP_STRING(End_Unit)

	/// <Property class="CQA_Unit_Trans_Time" name="Transport_Time" type="L3LONG">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(Transport_Time)

};

// �߼���CLadle_Baseͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

/////2009-02-28�������ʹ��ʵ����ʵ��ȷ�ϱ�־

#pragma once

class CLadle_Base :
	public CL3Object
{
public:
	CLadle_Base(void);
	virtual ~CLadle_Base(void);

	DECLARE_L3CLASS(CLadle_Base,XGMESLogic\\LadleMag, LadleID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Base)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Base" name="LadleID" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Base" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLadle_Base" name="Refra_Facturer" type="L3STRING">
	/// �ͲĲ���
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Facturer)

	/// <Property class="CLadle_Base" name="Status" type="L3STRING">
	/// ״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CLadle_Base" name="Ladle_Grade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Grade)

	/// <Property class="CLadle_Base" name="Ladle_Age" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Age)

	/// <Property class="CLadle_Base" name="New_BOF_Flag" type="L3LONG">
	/// 80tת¯��־
	/// </Property>
	DECLARE_L3PROP_LONG(New_BOF_Flag)

	/// <Property class="CLadle_Base" name="Tare_WT" type="L3DOUBLE">
	/// �ְ�Ƥ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tare_WT)

	/// <Property class="CLadle_Base" name="LadleType" type="L3LONG">
	/// �ְ�����
	/// </Property>
	DECLARE_L3PROP_LONG(LadleType)

	/// <Property class="CLadle_Base" name="InnerID" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CLadle_Base" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Base" name="ComFlag" type="L3LONG">
	/// ��ɱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(ComFlag)

	/// <Property class="CLadle_Base" name="OnFireID" type="L3LONG">
	/// ���ߺ濾����
	/// </Property>
	DECLARE_L3PROP_LONG(OnFireID)

	/// <Property class="CLadle_Base" name="WorkFireID" type="L3LONG">
	/// ������濾����
	/// </Property>
	DECLARE_L3PROP_LONG(WorkFireID)
	
	//2009-04-13
	/// <Property class="CLadle_Base" name="Measure_Flag" type="L3LONG">
	/// �ְ�����׼����־
	/// </Property>
	DECLARE_L3PROP_LONG(Measure_Flag)

	/// <Property class="CLadle_Base" name="InnerFireID" type="L3LONG">
	/// ���ò�濾����
	/// </Property>
	DECLARE_L3PROP_LONG(InnerFireID)

};

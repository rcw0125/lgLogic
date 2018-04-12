// �߼���CBOF_Top_Blowingͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_Top_Blowing :
	public CL3Object
{
public:
	CBOF_Top_Blowing(void);
	virtual ~CBOF_Top_Blowing(void);

	DECLARE_L3CLASS(CBOF_Top_Blowing,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Top_Blowing)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_Top_Blowing" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_Top_Blowing" name="Flow" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow)

	/// <Property class="CBOF_Top_Blowing" name="Pressure" type="L3FLOAT">
	/// ѹ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Pressure)

	/// <Property class="CBOF_Top_Blowing" name="Catch_Time" type="L3DATETIME">
	/// �ɼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

	/// <Property class="CBOF_Top_Blowing" name="Flow" type="L3FLOAT">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_MainPipe)

	/// <Property class="CBOF_Top_Blowing" name="Pressure" type="L3FLOAT">
	/// ����ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Press_MainPipe)
};

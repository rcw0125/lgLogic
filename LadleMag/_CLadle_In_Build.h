// �߼���CLadle_In_Buildͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_In_Build :
	public CL3Object
{
public:
	CLadle_In_Build(void);
	virtual ~CLadle_In_Build(void);

	DECLARE_L3CLASS(CLadle_In_Build,XGMESLogic\\LadleMag, InnerID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_In_Build)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_In_Build" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_In_Build" name="InnerID" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CLadle_In_Build" name="LadleID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_In_Build" name="Build_Start_Time" type="L3DATETIME">
	/// ��ʼ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_Start_Time)

	/// <Property class="CLadle_In_Build" name="Build_End_Time" type="L3DATETIME">
	/// ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_End_Time)

	/// <Property class="CLadle_In_Build" name="Ato_Lig_Cast_Fac" type="L3STRING">
	/// ΢�����ʽ����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Ato_Lig_Cast_Fac)

	/// <Property class="CLadle_In_Build" name="Ato_Lig_Cast_Wast" type="L3DOUBLE">
	/// ΢�����ʽ�����������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ato_Lig_Cast_Wast)

	/// <Property class="CLadle_In_Build" name="Hard_Fi_Adi_Boa_Fac" type="L3STRING">
	/// Ӳ����ά���Ȱ峧��
	/// </Property>
	DECLARE_L3PROP_STRING(Hard_Fi_Adi_Boa_Fac)

	/// <Property class="CLadle_In_Build" name="Hard_Fi_Adi_Boa_Wast" type="L3DOUBLE">
	/// Ӳ����ά���Ȱ�������[m2]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hard_Fi_Adi_Boa_Wast)

	/// <Property class="CLadle_In_Build" name="Spinel_Cast_Fac" type="L3STRING">
	/// �⾧ʯ�����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Spinel_Cast_Fac)

	/// <Property class="CLadle_In_Build" name="Spinel_Cast_Wast" type="L3DOUBLE">
	/// �⾧ʯ������������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spinel_Cast_Wast)

	/// <Property class="CLadle_In_Build" name="Al_Mg_Brick_Fac" type="L3STRING">
	/// ��þש����
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Mg_Brick_Fac)

	/// <Property class="CLadle_In_Build" name="Al_Mg_Brick_Wast" type="L3DOUBLE">
	/// ��þש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al_Mg_Brick_Wast)

	/// <Property class="CLadle_In_Build" name="Mg_Firecaly_Fact" type="L3STRING">
	/// þ���೧��
	/// </Property>
	DECLARE_L3PROP_STRING(Mg_Firecaly_Fact)

	/// <Property class="CLadle_In_Build" name="Mg_Firecaly_Wast" type="L3DOUBLE">
	/// þ����������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Firecaly_Wast)

	/// <Property class="CLadle_In_Build" name="Ladle_Inner_Use_Count" type="L3LONG">
	/// ���ò�ʹ�ô���
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Inner_Use_Count)

	/// <Property class="CLadle_In_Build" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_In_Build" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_In_Build" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_In_Build" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_In_Build" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

};

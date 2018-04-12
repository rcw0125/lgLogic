// �߼���CLadle_In_Build_Infoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_In_Build_Info :
	public CL3Object
{
public:
	CLadle_In_Build_Info(void);
	virtual ~CLadle_In_Build_Info(void);

	DECLARE_L3CLASS(CLadle_In_Build_Info,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_In_Build_Info)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_In_Build_Info" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_In_Build_Info" name="Number" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_SHORT(Number)

	/// <Property class="CLadle_In_Build_Info" name="Ladle_ID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_ID)

	/// <Property class="CLadle_In_Build_Info" name="Build_Start_Time" type="L3DATETIME">
	/// ��ʼ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_Start_Time)

	/// <Property class="CLadle_In_Build_Info" name="Build_End_Time" type="L3DATETIME">
	/// ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_End_Time)

	/// <Property class="CLadle_In_Build_Info" name="Ato_Lig_Cast_Fac" type="L3STRING">
	/// ΢�����ʽ����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Ato_Lig_Cast_Fac)

	/// <Property class="CLadle_In_Build_Info" name="Ato_Lig_Cast_Wast" type="L3DOUBLE">
	/// ΢�����ʽ�����������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ato_Lig_Cast_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Hard_Fi_Adi_Boa_Fac" type="L3STRING">
	/// Ӳ����ά���Ȱ峧��
	/// </Property>
	DECLARE_L3PROP_STRING(Hard_Fi_Adi_Boa_Fac)

	/// <Property class="CLadle_In_Build_Info" name="Hard_Fi_Adi_Boa_Wast" type="L3DOUBLE">
	/// Ӳ����ά���Ȱ�������[m2]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hard_Fi_Adi_Boa_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Spinel_Cast_Fac" type="L3STRING">
	/// �⾧ʯ�����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Spinel_Cast_Fac)

	/// <Property class="CLadle_In_Build_Info" name="Spinel_Cast_Wast" type="L3DOUBLE">
	/// �⾧ʯ������������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spinel_Cast_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Al_Mg_Brick_Fac" type="L3STRING">
	/// ��þש����
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Mg_Brick_Fac)

	/// <Property class="CLadle_In_Build_Info" name="Al_Mg_Brick_Wast" type="L3DOUBLE">
	/// ��þש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al_Mg_Brick_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Mg_Firecaly_Fact" type="L3STRING">
	/// þ���೧��
	/// </Property>
	DECLARE_L3PROP_STRING(Mg_Firecaly_Fact)

	/// <Property class="CLadle_In_Build_Info" name="Mg_Firecaly_Wast" type="L3DOUBLE">
	/// þ����������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Firecaly_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Ladle_Inner_Use_Count" type="L3SHORT">
	/// ���ò�ʹ�ô���
	/// </Property>
	DECLARE_L3PROP_SHORT(Ladle_Inner_Use_Count)

	/// <Property class="CLadle_In_Build_Info" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_In_Build_Info" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_In_Build_Info" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_In_Build_Info" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};

// �߼���CAOD_Bottom_Blowingͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAOD_Bottom_Blowing :
	public CL3Object
{
public:
	CAOD_Bottom_Blowing(void);
	virtual ~CAOD_Bottom_Blowing(void);

	DECLARE_L3CLASS(CAOD_Bottom_Blowing,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Bottom_Blowing)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAOD_Bottom_Blowing" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow1" type="L3DOUBLE">
	/// ����1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow1)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure1" type="L3DOUBLE">
	/// ѹ��1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure1)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow2" type="L3DOUBLE">
	/// ����2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow2)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure2" type="L3DOUBLE">
	/// ѹ��2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure2)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow3" type="L3DOUBLE">
	/// ����3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow3)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure3" type="L3DOUBLE">
	/// ѹ��3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure3)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow4" type="L3DOUBLE">
	/// ����4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow4)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure4" type="L3DOUBLE">
	/// ѹ��4
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure4)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow5" type="L3DOUBLE">
	/// ����5
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow5)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure5" type="L3DOUBLE">
	/// ѹ��5
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure5)

	/// <Property class="CAOD_Bottom_Blowing" name="Flow6" type="L3DOUBLE">
	/// ����6
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow6)

	/// <Property class="CAOD_Bottom_Blowing" name="Pressure6" type="L3DOUBLE">
	/// ѹ��6
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pressure6)

	/// <Property class="CAOD_Bottom_Blowing" name="Gas_Type" type="L3STRING">
	/// 
	/// ����(N2;Ar)
	/// </Property>
	DECLARE_L3PROP_STRING(Gas_Type)

	/// <Property class="CAOD_Bottom_Blowing" name="Catch_Time" type="L3DATETIME">
	/// �ɼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

	/// <Property class="CAOD_Bottom_Blowing" name="ObjectID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

};

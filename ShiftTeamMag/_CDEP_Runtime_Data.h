// �߼���CDeS_Runtime_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDEP_Runtime_Data :
	public CL3Object
{
public:
	CDEP_Runtime_Data(void);
	virtual ~CDEP_Runtime_Data(void);

	DECLARE_L3CLASS(CDEP_Runtime_Data,XGMESLogic\\DePMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDEP_Runtime_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDeS_Runtime_Data" name="UnitID" type="L3STRING">
	/// ����λ
	/// </Property>
	DECLARE_L3PROP_STRING(ID_Object)
	DECLARE_L3PROP_STRING(TreatNo)
	DECLARE_L3PROP_STRING(Materialid)
	DECLARE_L3PROP_DOUBLE(N_Pressure)
	DECLARE_L3PROP_DOUBLE(Spray_Pressure)
	DECLARE_L3PROP_DOUBLE(Spray_Flow)
	DECLARE_L3PROP_DOUBLE(Lime_Rate)
	DECLARE_L3PROP_DOUBLE(O_Pressure)
	DECLARE_L3PROP_DOUBLE(O_Flow)
	DECLARE_L3PROP_DOUBLE(D_Value)
	DECLARE_L3PROP_LONG(Zhan_Temp)
	DECLARE_L3PROP_LONG(Ji_Temp)
	DECLARE_L3PROP_DATETIME(Catch_Time)
	
};

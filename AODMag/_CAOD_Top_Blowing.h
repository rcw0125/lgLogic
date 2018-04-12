// �߼���CAOD_Top_Blowingͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAOD_Top_Blowing :
	public CL3Object
{
public:
	CAOD_Top_Blowing(void);
	virtual ~CAOD_Top_Blowing(void);

	DECLARE_L3CLASS(CAOD_Top_Blowing,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Top_Blowing)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAOD_Top_Blowing" name="HeatID" type="L3STRING">
	/// ¯��
	DECLARE_L3PROP_STRING(TreatNo)
	DECLARE_L3PROP_STRING(HeatID)

	
	DECLARE_L3PROP_FLOAT(Position)
	DECLARE_L3PROP_SHORT(Air_Type)
	DECLARE_L3PROP_FLOAT(Air_Flow)
	DECLARE_L3PROP_FLOAT(Air_Pressure)
	DECLARE_L3PROP_SHORT(Inwater_Temp)
	DECLARE_L3PROP_FLOAT(Inwater_Flow)
	DECLARE_L3PROP_SHORT(Outwater_Temp)
	DECLARE_L3PROP_FLOAT(Outwater_Flow)
	DECLARE_L3PROP_DATETIME(Catch_Time)
};

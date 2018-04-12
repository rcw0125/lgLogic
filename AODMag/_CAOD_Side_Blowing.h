// �߼���CAOD_Side_Blowingͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAOD_Side_Blowing :
	public CL3Object
{
public:
	CAOD_Side_Blowing(void);
	virtual ~CAOD_Side_Blowing(void);

	DECLARE_L3CLASS(CAOD_Side_Blowing,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Side_Blowing)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	DECLARE_L3PROP_STRING(Treatno)
	DECLARE_L3PROP_STRING(HeatID)
	DECLARE_L3PROP_SHORT(Type)
	DECLARE_L3PROP_FLOAT(Flow)
	DECLARE_L3PROP_FLOAT(Pressure)
	DECLARE_L3PROP_SHORT(Type2)
	DECLARE_L3PROP_FLOAT(Flow2)
	DECLARE_L3PROP_FLOAT(Pressure2)

	/// <Property class="CAOD_Side_Blowing" name="Pressure" type="L3FLOAT">
	/// ����ѹ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Press_MainPipe)
};

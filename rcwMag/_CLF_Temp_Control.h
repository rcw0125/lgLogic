// �߼���CLF_Temp_Controlͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_Temp_Control :
	public CL3Object
{
public:
	CLF_Temp_Control(void);
	virtual ~CLF_Temp_Control(void);

	DECLARE_L3CLASS(CLF_Temp_Control,XGMESLogic\\EnergyMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Temp_Control)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_Temp_Control" name="ObjectID" type="L3STRING">
	/// �����ʶ
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)
	DECLARE_L3PROP_STRING(Reasion) 
	DECLARE_L3PROP_STRING(FlagValue)
	DECLARE_L3PROP_DATETIME(CreateTime)
	DECLARE_L3PROP_STRING(Operator)
};

// �߼���CLF_BlowAr_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_BlowAr_Data :
	public CL3Object
{
public:
	CLF_BlowAr_Data(void);
	virtual ~CLF_BlowAr_Data(void);

	DECLARE_L3CLASS(CLF_BlowAr_Data,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_BlowAr_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_BlowAr_Data" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_BlowAr_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_BlowAr_Data" name="Flow_BlowAr" type="L3DOUBLE">
	/// �������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Flow_BlowAr)

	/// <Property class="CLF_BlowAr_Data" name="LogTime" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)
};

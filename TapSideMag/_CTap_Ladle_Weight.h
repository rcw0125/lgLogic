// �߼���CTap_Ladle_Weightͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTap_Ladle_Weight :
	public CL3Object
{
public:
	CTap_Ladle_Weight(void);
	virtual ~CTap_Ladle_Weight(void);

	DECLARE_L3CLASS(CTap_Ladle_Weight,XGMESLogic\\TapSideMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Ladle_Weight)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTap_Ladle_Weight" name="TAPID" type="L3SHORT">
	/// ¯������
	/// </Property>
	DECLARE_L3PROP_SHORT(TAPID)

	/// <Property class="CTap_Ladle_Weight" name="Weight" type="L3DOUBLE">
	/// ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CTap_Ladle_Weight" name="Status" type="L3SHORT">
	/// 
	/// ״̬
	/// (0:δʹ��
	///  1:��ʹ��)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CTap_Ladle_Weight" name="LadleNo" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

	/// <Property class="CTap_Ladle_Weight" name="HeatID" type="L3STRING">
	/// ��ǰ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Ladle_Weight" name="Log_Time" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

};

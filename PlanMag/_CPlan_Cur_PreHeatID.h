// �߼���CPlan_Cur_PreHeatIDͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CPlan_Cur_PreHeatID :
	public CL3Object
{
public:
	CPlan_Cur_PreHeatID(void);
	virtual ~CPlan_Cur_PreHeatID(void);

	DECLARE_L3CLASS(CPlan_Cur_PreHeatID,XGMESLogic\\PlanMag, CasterID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Cur_PreHeatID)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_Cur_PreHeatID" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CPlan_Cur_PreHeatID" name="Cur_PreHeatID" type="L3STRING">
	/// ��ǰԤ��¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Cur_PreHeatID)

	/// <Property class="CPlan_Cur_PreHeatID" name="Year" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Year)

};

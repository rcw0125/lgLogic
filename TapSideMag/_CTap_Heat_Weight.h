// �߼���CTap_Heat_Weightͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTap_Heat_Weight :
	public CL3Object
{
public:
	CTap_Heat_Weight(void);
	virtual ~CTap_Heat_Weight(void);

	DECLARE_L3CLASS(CTap_Heat_Weight,XGMESLogic\\TapSideMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Heat_Weight)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CTap_Heat_Weight" name="HeatID" type="L3STRING">
	/// ��ǰ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Heat_Weight" name="Status" type="L3SHORT">
	/// 
	/// ״̬
	/// (0:��ָ��
	///  1:�ѳ���)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CTap_Heat_Weight" name="Weight" type="L3DOUBLE">
	/// ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CTap_Heat_Weight" name="LadleNo" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

};

// �߼���CBOF_ReturnSteelͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_ReturnSteel :
	public CL3Object
{
public:
	CBOF_ReturnSteel(void);
	virtual ~CBOF_ReturnSteel(void);

	DECLARE_L3CLASS(CBOF_ReturnSteel,XGMESLogic\\BOFMag, HeatID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_ReturnSteel)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_ReturnSteel" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_ReturnSteel" name="Return_Steel_Weight" type="L3DOUBLE">
	/// ��¯��ˮ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Return_Steel_Weight)

};

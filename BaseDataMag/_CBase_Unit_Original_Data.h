// �߼���CBase_Unit_Original_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Unit_Original_Data :
	public CL3Object
{
public:
	CBase_Unit_Original_Data(void);
	virtual ~CBase_Unit_Original_Data(void);

	DECLARE_L3CLASS(CBase_Unit_Original_Data,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Unit_Original_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Unit_Original_Data" name="UnitID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CBase_Unit_Original_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

};

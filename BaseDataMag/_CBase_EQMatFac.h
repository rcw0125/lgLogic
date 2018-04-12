// �߼���CBase_EQMatFacͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_EQMatFac :
	public CL3Object
{
public:
	CBase_EQMatFac(void);
	virtual ~CBase_EQMatFac(void);

	DECLARE_L3CLASS(CBase_EQMatFac,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_EQMatFac)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_EQMatFac" name="MatFactory" type="L3STRING">
	/// ���ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(MatFactory)

	/// <Property class="CBase_EQMatFac" name="MatName" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(MatName)

	/// <Property class="CBase_EQMatFac" name="MatGroup_Code" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(MatGroup_Code)

	/// <Property class="CBase_EQMatFac" name="MatGroup_Des" type="L3STRING">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_STRING(MatGroup_Des)

};

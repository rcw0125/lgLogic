// �߼���CBase_Wire_Coefficientͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Wire_Coefficient :
	public CL3Object
{
public:
	CBase_Wire_Coefficient(void);
	virtual ~CBase_Wire_Coefficient(void);

	DECLARE_L3CLASS(CBase_Wire_Coefficient,XGMESLogic\\BaseDataMag, WireCode)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Wire_Coefficient)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Wire_Coefficient" name="WireCode" type="L3STRING">
	/// ι�ߴ���
	/// </Property>
	DECLARE_L3PROP_STRING(WireCode)

	/// <Property class="CBase_Wire_Coefficient" name="Coefficient" type="L3FLOAT">
	/// ι��ϵ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Coefficient)

};

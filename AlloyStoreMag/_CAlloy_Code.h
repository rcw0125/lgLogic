// �߼���CAlloy_Codeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAlloy_Code :
	public CL3Object
{
public:
	CAlloy_Code(void);
	virtual ~CAlloy_Code(void);

	DECLARE_L3CLASS(CAlloy_Code,XGMESLogic\\AlloyStoreMag, Alloy_Code)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Code)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAlloy_Code" name="Alloy_Code" type="L3STRING">
	/// �Ͻ����
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_Code" name="Alloy_Des" type="L3STRING">
	/// �Ͻ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Des)


};

// �߼���CSrap_Codeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CSrap_Code :
	public CL3Object
{
public:
	CSrap_Code(void);
	virtual ~CSrap_Code(void);

	DECLARE_L3CLASS(CSrap_Code,XGMESLogic\\ScrapStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CSrap_Code)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CSrap_Code" name="Scrap_Code" type="L3STRING">
	/// �ϸ���������
	/// </Property>
	DECLARE_L3PROP_STRING(Scrap_Code)

	/// <Property class="CSrap_Code" name="Scrap_Des" type="L3STRING">
	/// �ϸ���������
	/// </Property>
	DECLARE_L3PROP_STRING(Scrap_Des)

};

// �߼���CQA_Lab_Sheet_AppIDͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Lab_Sheet_AppID :
	public CL3Object
{
public:
	CQA_Lab_Sheet_AppID(void);
	virtual ~CQA_Lab_Sheet_AppID(void);

	DECLARE_L3CLASS(CQA_Lab_Sheet_AppID,XGMESLogic\\QualityMag, Sample_Address)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_Sheet_AppID)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Lab_Sheet_AppID" name="AppID" type="L3STRING">
	/// ί�е����
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Lab_Sheet_AppID" name="Sample_Address" type="L3STRING">
	/// ȡ���ص�
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)
};

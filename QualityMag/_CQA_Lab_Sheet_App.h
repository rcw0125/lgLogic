// �߼���CQA_Lab_Sheet_Appͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Lab_Sheet_App :
	public CL3Object
{
public:
	CQA_Lab_Sheet_App(void);
	virtual ~CQA_Lab_Sheet_App(void);

	DECLARE_L3CLASS(CQA_Lab_Sheet_App,XGMESLogic\\QualityMag, AppID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_Sheet_App)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

public:
	///�´��컯��ö��
	enum _SendEnum
	{
		NotSendLab = 0,				// δ�´��컯��
		SendLab = 1,				// ���´��컯��
	};
	enum _BackEnum
	{
		NotBack = 0,				// δ����
		IsBack = 1,				    // �ѻ���
	};

	/// <Property class="CQA_Lab_Sheet_App" name="AppID" type="L3STRING">
	/// ί�е����
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Lab_Sheet_App" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Code" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Code)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Address" type="L3STRING">
	/// ȡ���ص�
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Type" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Type)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Count" type="L3STRING">
	/// ȡ������
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Count)

	/// <Property class="CQA_Lab_Sheet_App" name="Sample_Date" type="L3DATETIME">
	/// ȡ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Sample_Date)

	/// <Property class="CQA_Lab_Sheet_App" name="Fin_Prod_Flag" type="L3SHORT">
	/// ��Ʒ����־
	/// </Property>
	DECLARE_L3PROP_LONG(Fin_Prod_Flag)

	/// <Property class="CQA_Lab_Sheet_App" name="Asis_Flag" type="L3SHORT">
	/// ��������־
	/// </Property>
	DECLARE_L3PROP_LONG(Asis_Flag)

	/// <Property class="CQA_Lab_Sheet_App" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_Lab_Sheet_App" name="Treaty" type="L3STRING">
	/// Э��
	/// </Property>
	DECLARE_L3PROP_STRING(Treaty)

	/// <Property class="CQA_Lab_Sheet_App" name="Back_Flag" type="L3SHORT">
	/// ���˱�־��0��δ���ˣ�1������
	/// </Property>
	DECLARE_L3PROP_LONG(Back_Flag)

	/// <Property class="CQA_Lab_Sheet_App" name="Back_Date" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Back_Date)

	/// <Property class="CQA_Lab_Sheet_App" name="ReSample_Flag" type="L3SHORT">
	/// ����ȡ����־��0��������1��Ҫ������ȡ��
	/// </Property>
	DECLARE_L3PROP_LONG(ReSample_Flag)

	/// <Property class="CQA_Lab_Sheet_App" name="ReSample_Reason" type="L3STRING">
	/// ����ȡ��ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(ReSample_Reason)

	/// <Property class="CQA_Lab_Sheet_App" name="ReSample_Date" type="L3DATETIME">
	/// ��ȡ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(ReSample_Date)

	/// <Property class="CQA_Lab_Sheet_App" name="SendFlag" type="L3LONG">
	/// ���ͱ�ʶ
	/// </Property>
	DECLARE_L3PROP_LONG(SendFlag)

	/// <Property class="CQA_Lab_Sheet_App" name="ReSampled" type="L3LONG">
	/// ����ȡ��
	/// </Property>
	DECLARE_L3PROP_LONG(ReSampled)

};

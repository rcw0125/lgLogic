// �߼���CQA_BOF_Std_Bulkͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_Bulk :
	public CL3Object
{
public:
	CQA_BOF_Std_Bulk(void);
	virtual ~CQA_BOF_Std_Bulk(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Bulk,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Bulk)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Bulk" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Bulk" name="Bulk_Code" type="L3STRING">
	/// ɢ״������
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CQA_BOF_Std_Bulk" name="Bulk_Weight_Min" type="L3DOUBLE">
	/// ɢ״��1��������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bulk_Weight_Min)

	/// <Property class="CQA_BOF_Std_Bulk" name="Bulk_Weight_Max" type="L3DOUBLE">
	/// ɢ״��1���������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bulk_Weight_Max)

};

// �߼���CQA_Cal_Weight_Stdͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Cal_Weight_Std :
	public CL3Object
{
public:
	CQA_Cal_Weight_Std(void);
	virtual ~CQA_Cal_Weight_Std(void);

	DECLARE_L3CLASS(CQA_Cal_Weight_Std,XGMESLogic\\QualityMag, ObjectID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Cal_Weight_Std)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	///2009-03-12 ���Ӹ��֣��޸�����Ϊ���ּӶ���

	/// <Property class="CQA_Cal_Weight_Std" name="ObjectID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CQA_Cal_Weight_Std" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_Cal_Weight_Std" name="Length" type="L3LONG">
	/// ���ߣ�m��
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CQA_Cal_Weight_Std" name="Weight" type="L3DOUBLE">
	/// ����������t��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)


	/// <Property class="CQA_Cal_Weight_Std" name="Spec" type="L3STRING">
	/// ���m��
	/// </Property>
	DECLARE_L3PROP_STRING(Spec)

};

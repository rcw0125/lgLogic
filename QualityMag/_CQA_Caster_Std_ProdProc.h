// �߼���CQA_Caster_Std_ProdProcͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Caster_Std_ProdProc :
	public CL3Object
{
public:
	CQA_Caster_Std_ProdProc(void);
	virtual ~CQA_Caster_Std_ProdProc(void);

	DECLARE_L3CLASS(CQA_Caster_Std_ProdProc,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Caster_Std_ProdProc)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Caster_Std_ProdProc" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Caster_Std_ProdProc" name="CasterID" type="L3STRING">
	/// ��������(PK1)��
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CQA_Caster_Std_ProdProc" name="Spec_Seq" type="L3LONG">
	/// ������(PK2)��
	/// </Property>
	DECLARE_L3PROP_LONG(Spec_Seq)

	/// <Property class="CQA_Caster_Std_ProdProc" name="Width_Min" type="L3LONG">
	/// �����Сֵ��
	/// </Property>
	DECLARE_L3PROP_LONG(Width_Min)

	/// <Property class="CQA_Caster_Std_ProdProc" name="Width_Max" type="L3LONG">
	/// ������ֵ��
	/// </Property>
	DECLARE_L3PROP_LONG(Width_Max)

	/// <Property class="CQA_Caster_Std_ProdProc" name="Thickness_Min" type="L3LONG">
	/// �����Сֵ��
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness_Min)

	/// <Property class="CQA_Caster_Std_ProdProc" name="Thickness_Max" type="L3LONG">
	/// ������ֵ��
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness_Max)

	/// <Property class="CQA_Caster_Std_ProdProc" name="Length_Min" type="L3LONG">
	/// ������Сֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Length_Min)

	/// <Property class="CQA_Caster_Std_ProdProc" name="Length_Max" type="L3LONG">
	/// �������ֵ
	/// </Property>
	DECLARE_L3PROP_LONG(Length_Max)

};

// �߼���CQA_Unit_Proc_Timeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Unit_Proc_Time :
	public CL3Object
{
public:
	CQA_Unit_Proc_Time(void);
	virtual ~CQA_Unit_Proc_Time(void);

	DECLARE_L3CLASS(CQA_Unit_Proc_Time,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Unit_Proc_Time)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Unit_Proc_Time" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Unit_Proc_Time" name="BOF_Proc_Time" type="L3LONG">
	/// ת¯��ҵʱ�䡢
	/// </Property>
	DECLARE_L3PROP_LONG(BOF_Proc_Time)

	/// <Property class="CQA_Unit_Proc_Time" name="LF_Proc_Time" type="L3LONG">
	/// LF¯��ҵʱ�䡢
	/// </Property>
	DECLARE_L3PROP_LONG(LF_Proc_Time)

	/// <Property class="CQA_Unit_Proc_Time" name="RH_Proc_Time" type="L3LONG">
	/// RH¯��ҵʱ�䡢
	/// </Property>
	DECLARE_L3PROP_LONG(RH_Proc_Time)

	/// <Property class="CQA_Unit_Proc_Time" name="Caster_Proc_Time" type="L3LONG">
	/// ������ҵʱ�䡢
	/// </Property>
	DECLARE_L3PROP_LONG(Caster_Proc_Time)

	/// <Property class="CQA_Unit_Proc_Time" name="Tapped_Proc_Time" type="L3LONG">
	/// ¯����ҵʱ�䡢
	/// </Property>
	DECLARE_L3PROP_LONG(Tapped_Proc_Time)

};

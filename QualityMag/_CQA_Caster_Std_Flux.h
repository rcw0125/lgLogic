// �߼���CQA_Caster_Std_Fluxͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Caster_Std_Flux :
	public CL3Object
{
public:
	CQA_Caster_Std_Flux(void);
	virtual ~CQA_Caster_Std_Flux(void);

	DECLARE_L3CLASS(CQA_Caster_Std_Flux,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Caster_Std_Flux)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Caster_Std_Flux" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Caster_Std_Flux" name="Tundish_Flux_Name" type="L3STRING">
	/// �а����Ǽ����ơ�
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_Flux_Name)

	/// <Property class="CQA_Caster_Std_Flux" name="Tundish_Flux_Weight" type="L3DOUBLE">
	/// �а����Ǽ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tundish_Flux_Weight)

};

// �߼���CQA_Bloom_Std_Spileͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Bloom_Std_Spile :
	public CL3Object
{
public:
	CQA_Bloom_Std_Spile(void);
	virtual ~CQA_Bloom_Std_Spile(void);

	DECLARE_L3CLASS(CQA_Bloom_Std_Spile,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Bloom_Std_Spile)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Bloom_Std_Spile" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Bloom_Std_Spile" name="SpileFlagDes" type="L3STRING">
	/// �϶��־����
	/// </Property>
	DECLARE_L3PROP_STRING(SpileFlagDes)

};

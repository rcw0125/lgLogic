// �߼���CQA_Heat_Judge_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Heat_Judge_Log :
	public CL3Object
{
public:
	CQA_Heat_Judge_Log(void);
	virtual ~CQA_Heat_Judge_Log(void);

	DECLARE_L3CLASS(CQA_Heat_Judge_Log,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Heat_Judge_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Heat_Judge_Log" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Heat_Judge_Log" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Heat_Judge_Log" name="Decide_SteelGradeIndex" type="L3STRING">
	/// �������ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_SteelGradeIndex)

	/// <Property class="CQA_Heat_Judge_Log" name="Judge_Date" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Judge_Date)

	/// <Property class="CQA_Heat_Judge_Log" name="Operator" type="L3STRING">
	/// ������Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CQA_Heat_Judge_Log" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CQA_Heat_Judge_Log" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

};

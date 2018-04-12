// �߼���CQA_HeatGradeAssumeAlg_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_HeatGradeAssumeAlg_Mag :
	public CL3Object
{
public:
	CQA_HeatGradeAssumeAlg_Mag(void);
	virtual ~CQA_HeatGradeAssumeAlg_Mag(void);

	DECLARE_L3CLASS(CQA_HeatGradeAssumeAlg_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatGradeAssumeAlg_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="EstimateHeatGrade" type="">
	/// ¯��Ʒ���ж�
	/// <Param name="nUnitTypeID" type="L3SHORT">�����ʶ</Param>
	/// <Param name="nUnitID" type="L3SHORT">��λ</Param>
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// <Param name="nProcessCount" type="L3SHORT">����λ�������</Param>
	/// </Method>
	L3LONG EstimateHeatGrade(L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strHeatID, L3SHORT nProcessCount);

	/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="EstimateHeatChemical" type="L3SHORT">
	/// �ȶ�¯�γɷ�
	/// <Param name="nUnitTypeID" type="L3SHORT">����</Param>
	/// <Param name="nUnitID" type="L3SHORT">��λ</Param>
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// <Param name="nProcessCount" type="L3SHORT">�ش������</Param>
	/// <Param name="rsChemicalData" type="L3RECORDSET">�ɷ�����</Param>
	/// </Method>
	L3LONG EstimateHeatChemical(L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strHeatID, L3SHORT nProcessCount, L3RECORDSET rsChemicalData);

	/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="EstimateDecideHeatGrade" type="L3SHORT">
	/// �ۺϸ�����¯�εȼ������ɾ����ȼ�
	/// <Param name="nUnitTypeID" type="L3SHORT">����</Param>
	/// <Param name="nUnitID" type="L3SHORT">��λ</Param>
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// <Param name="nProcessCount" type="L3SHORT">�ش������</Param>
	/// </Method>
	L3LONG EstimateDecideHeatGrade(L3SHORT nUnitTypeID,L3SHORT nUnitID,L3STRING strHeatID,L3SHORT nProcessCount);

	/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="RecommendSteelGradeIndex" type="L3SHORT">
	/// �Ƽ����ּǺ�
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// <Param name="*rsSteelGradeIndexData" type="L3RECORDSET">�ش������</Param>
	/// </Method>
	L3LONG RecommendSteelGradeIndex(L3STRING strHeatID,L3RECORDSET *rsSteelGradeIndexData);
};

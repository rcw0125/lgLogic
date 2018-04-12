// �߼���CQA_HeatSufaceAssume_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_HeatSufaceAssume_Mag :
	public CL3Object
{
public:
	CQA_HeatSufaceAssume_Mag(void);
	virtual ~CQA_HeatSufaceAssume_Mag(void);

	DECLARE_L3CLASS(CQA_HeatSufaceAssume_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatSufaceAssume_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();


	/// <Property class="CQA_HeatSufaceAssume_Mag" name="HeatSufaceAAssumeMag" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(HeatSufaceAAssumeMag)

	/// <Property class="CQA_HeatSufaceAssume_Mag" name="HotJudgeEvent" type="L3LONG">
	/// �ȼ������ж��¼�
	/// </Property>
	DECLARE_L3PROP_LONG(HotJudgeEvent)

	/// <Property class="CQA_HeatSufaceAssume_Mag" name="CoolJudgeEvent" type="L3LONG">
	/// ��������ж��¼�
	/// </Property>
	DECLARE_L3PROP_LONG(CoolJudgeEvent)

	/// <Property class="CQA_HeatSufaceAssume_Mag" name="BloomCuttingEvent" type="L3LONG">
	/// �����ж��¼�
	/// </Property>
	DECLARE_L3PROP_LONG (BloomCuttingEvent); //�����ж��¼�

	/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomHotJudge" type="L3LONG">
	/// �����ȼ������ж�
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// ������HeatID��Bloom_Count��Cal_Weight��Wrong_Total_Count��Wrong_Total_Weight��
	/// Wrong_Reason��Cut_SteelGradeIndex ��SteelGradeIndex��Produce_Date��Length��Width��
	/// Thickness�ֶ�
	/// </Method>
	L3LONG BloomHotJudge(L3RECORDSET rsData);

	/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomCoolJudge" type="L3LONG">
	/// ������������ж�
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG BloomColdJudge(L3RECORDSET rsData);

	/// <Method class="CQuality_Mag" name="GetHeatCoolJudgeData" type="L3RECORDSET">
	/// ��ȡ��������ж���Ϣ
	/// <Param name="strCasterID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetHeatCoolJudgeData(L3STRING strCasterID);

	/// <Method class="CQuality_Mag" name="GetHeatCoolJudgeData" type="L3RECORDSET">
	/// ��ȡ�ȼ������ж���Ϣ
	/// <Param name="strCasterID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetHeatHotJudgeData(L3STRING strCasterID);


	/// <Method class="CQuality_Mag" name="GetBloomWaitingSendInfor" type="">
	/// ��ȡ������������Ϣ
	/// </Method>
	L3RECORDSET GetBloomWaitingSendInfor();


	/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomHotSend" type="L3BOOL">
	/// ��������
	/// </Method>
	L3LONG BloomHotSend(L3RECORDSET rsData);


	/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomOffLine" type="L3BOOL">
	/// ��������
	/// </Method>
	L3LONG BloomOffLine(L3RECORDSET rsData);

};

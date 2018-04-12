// �߼���CQuality_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

const CString BOF_INIT_HEATGRADE	= _T("1100");//ת¯��ʼ¯��Ʒ��
const CString LF_INIT_HEATGRADE	    = _T("1200");//LF¯��ʼ¯��Ʒ��
const CString RH_INIT_HEATGRADE		= _T("1300");//RH¯��ʼ¯��Ʒ��
const CString CCM_INIT_HEATGRADE	= _T("1400");//������ʼ¯��Ʒ��

class CQuality_Mag :
	public CL3Object
{
public:
	CQuality_Mag(void);
	virtual ~CQuality_Mag(void);

	DECLARE_L3CLASS(CQuality_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQuality_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();



	/// <Method class="CQuality_Mag" name="BloomWaster" type="L3BOOL">
	/// 
	/// ����˦��
	/// ARG&gt;&gt; rsData:˦�����ݣ�������HeatID��Bloom_Count��Cal_Weight��Waster_Total_Count��Waster_Total_Weight��Waster_Reason��Cut_SteelGradeIndex ��SteelGradeIndex��Produce_Date��Length��Width��Thickness�ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET">����ί�е���Ϣ</Param>
	/// </Method>
	L3BOOL BloomWaster(L3RECORDSET rsData);
	/// <Method class="CQuality_Mag" name="GetUnspecifyDutyWasterData" type="L3RECORDSET">
	/// 
	/// ��ȡδָ�����ε�λ��˦��ʵ������
	/// ARG&gt;&gt;strCasterID��������
	/// RET &lt;&lt; �ɹ����ز�ѯ���ݼ���ʧ�ܷ���NULL��
	/// <Param name="strCasterID" type=""></Param>
	/// </Method>
	L3RECORDSET GetUnspecifyDutyWasterData(L3STRING strCasterID);
	/// <Method class="CQuality_Mag" name="AddQAStdData" type="L3BOOL">
	/// 
	/// ������ҵ��׼����
	/// ARG&gt;&gt; rsData:��׼����
	///        &gt;&gt; strDataType:��������URI
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// <Param name="strDataType" type="L3STRING"></Param>
	/// </Method>
	L3LONG AddBOFQAStdData(L3RECORDSET rsBase,
									  L3RECORDSET rsAr,
									  L3RECORDSET rsBlow,
									  L3RECORDSET rsBlowO2,
									  L3RECORDSET rsBulk,
									  L3RECORDSET rsFeed,
									  L3RECORDSET rsInFurnace,
									  L3RECORDSET rsLadle,
									  L3RECORDSET rsSlag,
									  L3RECORDSET rsTap);
	/// <Method class="CQuality_Mag" name="DelQAStdData" type="L3BOOL">
	/// 
	/// ɾ����ҵ��׼����
	/// ARG&gt;&gt; rsData:��׼����
	///        &gt;&gt; DataType:��������URI
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// <Param name="strDataType" type="L3STRING"></Param>
	/// </Method>
    L3LONG CQuality_Mag::DelBOFQAStdData(L3RECORDSET rsBase,
										  L3RECORDSET rsAr,
										  L3RECORDSET rsBlow,
										  L3RECORDSET rsBlowO2,
										  L3RECORDSET rsBulk,
										  L3RECORDSET rsFeed,
										  L3RECORDSET rsInFurnace,
										  L3RECORDSET rsLadle,
										  L3RECORDSET rsSlag,
										  L3RECORDSET rsTap);
	/// <Method class="CQuality_Mag" name="ModQAStdData" type="L3BOOL">
	/// 
	/// �޸���ҵ��׼����
	/// ARG&gt;&gt; rsData:��׼����
	///        &gt;&gt; DataType:��������URI
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// <Param name="strDataType" type="L3STRING"></Param>
	/// </Method>
	L3LONG CQuality_Mag::ModBOFQAStdData(L3RECORDSET rsBase,
										  L3RECORDSET rsAr,
										  L3RECORDSET rsBlow,
										  L3RECORDSET rsBlowO2,
										  L3RECORDSET rsBulk,
										  L3RECORDSET rsFeed,
										  L3RECORDSET rsInFurnace,
										  L3RECORDSET rsLadle,
										  L3RECORDSET rsSlag,
										  L3RECORDSET rsTap);
	/// <Method class="CQuality_Mag" name="GetQAStdData" type="L3RECORDSET">
	/// 
	/// ��ȡ������׼���ݼ�
	/// ARG&gt;&gt; rsCondition ������StdDataType
	/// RET &lt;&lt; �ɹ��������ݼ���ʧ�ܷ���NULL��
	/// <Param name="rsCondition" type="L3RECORDSET"></Param>
	/// </Method>
	L3RECORDSET GetQAStdData(L3RECORDSET rsCondition);
    // ����LF�����׼
	L3LONG AddLFQAStdData(L3RECORDSET rsBase,
		                  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsLadle,
						  L3RECORDSET rsProc,
						  L3RECORDSET rsSlag,
						  L3RECORDSET rsSlagEle);
	// �޸�LF�����׼
	L3LONG ModLFQAStdData(L3RECORDSET rsBase,
		                  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsLadle,
						  L3RECORDSET rsProc,
						  L3RECORDSET rsSlag,
						  L3RECORDSET rsSlagEle);

	// ɾ��LF�����׼
	L3LONG DelLFQAStdData(L3RECORDSET rsBase,
		                  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsLadle,
						  L3RECORDSET rsProc,
						  L3RECORDSET rsSlag,
						  L3RECORDSET rsSlagEle);

    // ����RH�����׼
	L3LONG AddRHQAStdData(L3RECORDSET rsBase,
						  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsProc);
    // �޸�RH�����׼
	L3LONG ModRHQAStdData(L3RECORDSET rsBase,
						  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsProc);
    // ɾ��RH�����׼
	L3LONG DelRHQAStdData(L3RECORDSET rsBase,
						  L3RECORDSET rsAlloy,
						  L3RECORDSET rsFeed,
						  L3RECORDSET rsProc);

    //����CCM�����׼
	L3LONG AddCCMQAStdData(L3RECORDSET rsBase,
						   L3RECORDSET rsFlux,
						   L3RECORDSET rsProc,
						   L3RECORDSET rsProdProc,
						   L3RECORDSET rsSpec,
						   L3RECORDSET rsSpeed,
						   L3RECORDSET rsTundish);
    //�޸�CCM�����׼
	L3LONG ModCCMQAStdData(L3RECORDSET rsBase,
						   L3RECORDSET rsFlux,
						   L3RECORDSET rsProc,
						   L3RECORDSET rsProdProc,
						   L3RECORDSET rsSpec,
						   L3RECORDSET rsSpeed,
						   L3RECORDSET rsTundish);
    // ɾ��CCM�����׼
	L3LONG DelCCMQAStdData(L3RECORDSET rsBase,
						   L3RECORDSET rsFlux,
						   L3RECORDSET rsProc,
						   L3RECORDSET rsProdProc,
						   L3RECORDSET rsSpec,
						   L3RECORDSET rsSpeed,
						   L3RECORDSET rsTundish);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFBase" type="L3RECORDSET">
	/// ��ȡBOF�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFBase(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFAr" type="L3RECORDSET">
	/// ��ȡBOF�����׼(�������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFAr(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFBlow" type="L3RECORDSET">
	/// ��ȡBOF�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFBlow(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFBlowOxygen" type="L3RECORDSET">
	/// ��ȡBOF�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFBlowOxygen(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFBulk" type="L3RECORDSET">
	/// ��ȡBOF�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFBulk(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFFeed" type="L3RECORDSET">
	/// ��ȡBOF�����׼(ι˿����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFFeed(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFInCtrlElement" type="L3RECORDSET">
	/// ��ȡBOF�����׼(�ڿسɷ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFInCtrlElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFMaterial" type="L3RECORDSET">
	/// ��ȡBOF�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFMaterial(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFLadle" type="L3RECORDSET">
	/// ��ȡBOF�����׼(�ְ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFLadle(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFSlagElement" type="L3RECORDSET">
	/// ��ȡBOF�����׼(���ɷ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFSlagElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForBOFTapping" type="L3RECORDSET">
	/// ��ȡBOF�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForBOFTapping(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFBase" type="L3RECORDSET">
	/// ��ȡLF�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFBase(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFAlloy" type="L3RECORDSET">
	/// ��ȡLF�����׼(�Ͻ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFAlloy(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFFeed" type="L3RECORDSET">
	/// ��ȡLF�����׼(ι˿����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFFeed(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFInCtrlElement" type="L3RECORDSET">
	/// ��ȡLF�����׼(�ڿسɷ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFInCtrlElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFLadle" type="L3RECORDSET">
	/// ��ȡLF�����׼(�ְ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFLadle(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFProc" type="L3RECORDSET">
	/// ��ȡLF�����׼(��ҵ����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFProc(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFSlag" type="L3RECORDSET">
	/// ��ȡLF�����׼(������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFSlag(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForLFSlagElement" type="L3RECORDSET">
	/// ��ȡLF�����׼(���ɷ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForLFSlagElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHBase" type="L3RECORDSET">
	/// ��ȡRH�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHBase(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHAlloy" type="L3RECORDSET">
	/// ��ȡRH�����׼(�Ͻ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHAlloy(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHFeed" type="L3RECORDSET">
	/// ��ȡRH�����׼(ι˿����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHFeed(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHInCtrlElement" type="L3RECORDSET">
	/// ��ȡRH�����׼(�ڿ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHInCtrlElement(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForRHProc" type="L3RECORDSET">
	/// ��ȡRH�����׼(��ҵ����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForRHProc(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMFlux" type="L3RECORDSET">
	/// ��ȡCCM�����׼(�а����Ǽ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMFlux(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMProc" type="L3RECORDSET">
	/// ��ȡCCM�����׼(��ҵ����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMProc(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMProd" type="L3RECORDSET">
	/// ��ȡCCM�����׼(�Ƴ�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMProd(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMSpec" type="L3RECORDSET">
	/// ��ȡCCM�����׼(�������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMSpec(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMSpeed" type="L3RECORDSET">
	/// ��ȡCCM�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMSpeed(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMTundish" type="L3RECORDSET">
	/// ��ȡCCM�����׼(�а�����)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMTundish(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="GetQAStdForCCMBase" type="L3RECORDSET">
	/// ��ȡCCM�����׼(��������)��
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// </Method>
	L3RECORDSET GetQAStdForCCMBase(L3STRING strSteelGradeIndex);

	/// <Method class="CQuality_Mag" name="BloomWasterDutySpecify" type="L3RECORDSET">
	/// ��ȡCCM�����׼(��������)��
	/// <Param name="rsData" type="L3RECORDSET">CQA_Bloom_Waster_Data���������ε�λ�����α�־=1</Param>
	/// </Method>
	L3LONG BloomWasterDutySpecify(L3RECORDSET rsData);

	/// <Method class="CQuality_Mag" name="GetSampleApplyData" type="L3RECORDSET">
	/// ��ȡ���ص�(��λ)��ȡ����ί�е�����
	/// <Param name="strSampleAddr" type="L3STRING">ȡ���ص�(��λ)</Param>
	/// </Method>
	L3RECORDSET GetSampleApplyData(L3STRING strSampleAddr);

	/// <Method class="CQuality_Mag" name="GetHeatIDByAddr" type="L3RECORDSET">
	/// ͨ��ȡ���ص��ȡ��λ�����¯¯��
	/// <Param name="strSampleAddr" type="L3STRING">ȡ���ص�(��λ)</Param>
	/// </Method>
	L3RECORDSET GetHeatIDByAddr(L3STRING strSampleAddr);

	/// <Method class="CQuality_Mag" name="CreateHeatGradeQAData" type="L3RECORDSET">
	/// �����ʼ¯�εȼ�����
	/// <Param name="strUnitID" type="L3STRING">����</Param>
	/// <Param name="rsData" type="L3RECORDSET">���ٰ���¯�š�Ԥ��¯�š����ּǺš�Ԥ�����ּǺŵļ�¼��</Param>
	/// </Method>
	L3SHORT CreateHeatGradeQAData(L3STRING strUnitID ,L3RECORDSET rsData);

	/// <Method class="CQuality_Mag" name="GetCurrentHeatGradeQAData" type="L3RECORDSET">
	/// ��ȡ����ǰ¯��¯�εȼ�
	/// <Param name="strUnitID" type="L3STRING">��λ</Param>
	/// <Param name="strHeatID" type="L3STRING">¯��</Param>
	/// </Method>
	L3RECORDSET GetCurrentHeatGradeQAData(L3STRING strUnitID ,L3STRING strHeatID);

	/// <Method class="CQuality_Mag" name="UpdateCurrentHeatGradeData" type="L3LONG">
	/// 
	/// �޸ĵ�ǰ¯�εȼ���Ϣ
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateCurrentHeatGradeData(L3RECORDSET rsData);

	/// <Method class="CQuality_Mag" name="GetQACalWeightData" type="L3RECORDSET">
	/// ͨ�����߳��Ȼ�ȡ���߱�׼���ݡ�
	/// <Param name="Length" type="LONG">����</Param>
	/// </Method>
	L3RECORDSET GetQACalWeightData(LONG Length);

	///2008-12-29 tangyiͨ�����ֻ�ȡ�ø��ֿ��Ը��е����ּǺ�
	/// <Method class="CQuality_Mag" name="GetQACalWeightData" type="L3RECORDSET">
	/// ͨ�����߳��Ȼ�ȡ���߱�׼���ݡ�
	/// <Param name="Length" type="LONG">����</Param>
	/// </Method>
	L3RECORDSET GetJudgedSteelGrade(L3STRING strSteelGrade,L3STRING strSteelGradeIndex);

	///// <Method class="CQuality_Mag" name="GetDeSSampleApplyData" type="L3RECORDSET">
	///// ��ȡ����ί�е�(����)����
	///// </Method>
	//L3RECORDSET GetDeSSampleApplyData();

	///2011-03-19 llj �������ּǺŽ���׼���Ƶ��µ����ּǺ���
	/// <Method class="CQuality_Mag" name="SteelGradeIndexCopy" type="L3LONG">
	/// <Param name="strNewSteelGradeIndex" type="L3STRING">�µ����ּǺ�</Param>
	/// <Param name="strOldSteelGradeIndex" type="L3STRING">�ɵ����ּǺ�</Param>
	/// </Method>
	L3LONG SteelGradeIndexCopy(L3STRING strNewSteelGradeIndex, L3STRING strOldSteelGradeIndex);
};

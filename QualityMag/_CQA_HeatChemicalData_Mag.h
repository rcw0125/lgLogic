// �߼���CQA_HeatChemicalData_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_HeatChemicalData_Mag :
	public CL3Object
{
public:
	CQA_HeatChemicalData_Mag(void);
	virtual ~CQA_HeatChemicalData_Mag(void);

	DECLARE_L3CLASS(CQA_HeatChemicalData_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatChemicalData_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

public:
	// ����ö��
	enum _UnitEnum
	{
		BF = 0,	// ��ˮ
		MIF = 1,// ����¯
		BOF = 2,// ת¯
		TAP = 3,// ¯��
		LF = 4, // LF¯
		RH = 5, // RH¯
		CCM = 6,// ����
	};
	/// <Method class="CQA_HeatChemicalData_Mag" name="GetUnitMagURIBySampleAddr" type="CString">
	/// ͨ��ȡ���ص��ȡ����̬�����������ù������������ԣ�
	/// <Param name=strSampleAddr//ȡ���ص�</Param>
	/// </Method>
	CString GetUnitMagURIBySampleAddr(LPCTSTR strSampleAddr);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetSysYear" type="CString">
	/// ����ί�е������
	/// <Param name=��</Param>
	/// </Method>
    CString GetSysCurYear();

    /// <Method class="CQA_HeatChemicalData_Mag" name="CalLabSheetAppID" type="CString">
	/// ����ί�е������
	/// <Param name="cstrSampleAddr" type="LPCTSTR">�����ص�</Param>
	/// </Method>
	CString CalLabSheetAppID(LPCTSTR csSampleAddr,LPCTSTR csSampleType);

	/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronSampleCode" type="CString">
	/// ������ˮ��������
	/// <Param name="csSampleAddr" type="LPCTSTR"> ȡ���ص�
	/// <Param name="csSampleType" type="LPCTSTR"> �������
	/// <Param name="csTAPNo" type="LPCTSTR"> ���κ�
	/// �������BFID��TAP_No��Sample_Type��Sample_Address</Param>
	/// </Method>
    CString  CalIronSampleCode(LPCTSTR csSampleAddr,
													 LPCTSTR csSampleType,
													 LPCTSTR csTAPNo);

													 /// <Method class="CQA_HeatChemicalData_Mag" name="CalMixFurnaceSampleCode" type="CString">
	/// �������¯��������
	/// <Param name="csSampleAddr" type="LPCTSTR">ȡ���ص�(����¯)</Param>
	/// <Param name="csSampleType" type="LPCTSTR">�������(����¯)</Param>
	/// </Method>
	CString  CalMixFurnaceSampleCode(LPCTSTR csSampleAddr,LPCTSTR csSampleType);

	/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronLadleSampleCode" type="CString">
	/// �������¯����������
	/// <Param name="csSampleAddr" type="LPCTSTR">ȡ���ص�(����¯)</Param>
	/// <Param name="csSampleType" type="LPCTSTR">�������</Param>
	/// <Param name="csIronLadleNo" type="LPCTSTR">����</Param>
	/// </Method>
	CString  CalIronLadleSampleCode(LPCTSTR csSampleAddr,LPCTSTR csSampleType,LPCTSTR csIronLadleNo);

/// <Method class="CQA_HeatChemicalData_Mag" name="CalBOFSampleCode" type="CString">
	/// ����������������
	/// <Param name="csSampleType" type="LPCTSTR">�������</Param>
	/// <Param name="csSampleAddr" type="LPCTSTR">ȡ���ص�</Param>
	/// <Param name="csHeatID" type="LPCTSTR">¯��</Param>
	/// </Method>
    CString CalBOFSampleCode(LPCTSTR csSampleType,
		                     LPCTSTR csSampleAddr,
							 LPCTSTR csHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="LogLabSheet" type="L3LONG">
	/// ���ɻ���ί�е���
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///�������ݼ����������Sample_Type��Sample_Address��HeatID�ֶ�
	/// </Method>
	L3LONG NewLabSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="ModifyLabSheet" type="L3LONG">
	/// �޸�ί�е�����
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyLabSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="DeleteLabSheet" type="L3LONG">
	/// ɾ��ί�е�����
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteLabSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="SendSheetDataToLab" type="L3LONG">
	/// ί�е������´�������
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SendSheetDataToLab(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSheetBack" type="L3LONG">
	/// ���ռ컯��ί�е�����
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabSheetBack(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSteelElement" type="L3LONG">
	/// ���ո����컯����
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabSteelElement(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSPrintData" type="L3LONG">
	/// ���յͱ���ʵ��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
	/// </Method>
	L3LONG  AcceptSPrintData(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSPrintData" type="L3LONG">
	/// ���������컯����
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
	/// </Method>
	L3LONG  AcceptSlagElement(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptReSampleAdvice" type="L3LONG">
	/// ���ռ컯������ȡ��֪ͨ 
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///�������ݼ����������ApplyID��ReSample_Reason�ֶ�
	/// </Method>
	L3LONG AcceptReSampleAdvice(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="LabCutAdvice" type="L3LONG">
	/// ��д����֪ͨ��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  LabCutAdvice(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetHeatLabElement" type="L3RECORDSET">
	/// ��ȡ¯�ι��̸���
	/// <Param name="rsData" type="L3RECORDSET">ȥ��</Param>
	/// </Method>
	L3RECORDSET GetHeatLabElement(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetHeatSlagElement" type="L3RECORDSET">
	/// ��ȡ¯��������Ϣ
	/// <Param name="rsData" type="L3RECORDSET">ȥ��</Param>
	/// </Method>
	L3RECORDSET GetHeatSlagElement(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetActualHeatChemicalData" type="L3RECORDSET">
	/// ��ȡ¯�λ�ѧ�ɷ�ʵ������
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetActualHeatChemicalData(L3STRING strHeatID,
										  L3LONG nUnitTypeID,
										  L3LONG nUnitID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetTechRequestByHeatID" type="CString">
	/// ͨ��¯�Ż�ȡί�е��е�Э������
	/// <Param name=strHeatID//¯��</Param>
	/// </Method>
	CString GetTechRequestByHeatID(LPCTSTR strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetSteelGradeByHeatID" type="CString">
	/// ͨ��¯�Ż�ȡί�е��еĸ���
	/// <Param name=strHeatID//¯��</Param>
	/// </Method>
	L3RECORDSET GetSteelGradeByHeatID(LPCTSTR strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetLatelyNewHeatChemicalData" type="L3RECORDSET">
	/// ��ȡ����˹�������¯�γɷ�����
	/// <Param name=//</Param>
	/// </Method>
	L3RECORDSET GetLatelyNewHeatChemicalData();

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetApplyDataByApplyID" type="L3RECORDSET">
	/// ��ȡ����˹�������¯�γɷ�����
	/// <Param name=strApplyID//</Param>
	/// </Method>
	L3RECORDSET GetApplyDataByApplyID(L3STRING strApplyID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetApplyDataByApplyID" type="L3RECORDSET">
	/// ����ί�е��Ż�ȡί�е�����
	/// <Param name=strApplyID//</Param>
	/// </Method>
	L3RECORDSET GetApplyIDByHeatIDAndAddr(L3STRING strHeatID,L3STRING strAddr);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetCutAdviceData" type="L3RECORDSET">
	/// ��ȡ�������֪ͨ����
	/// <Param name=//</Param>
	/// </Method>
	L3RECORDSET GetCutAdviceData();

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetSteelGradeByHeatID" type="L3RECORDSET">
	/// ����¯�Ż�ȡ����
	/// <Param name=//</Param>
	/// </Method>
	L3RECORDSET GetGradeByHeatID(L3STRING strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="DeleteCutAdvice" type="L3LONG">
	/// ɾ������֪ͨ
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteCutAdvice(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetFinalActualHeatChemicalByHeatID" type="L3LONG">
	/// ����¯�Ż�ȡ����ʵ�ʳɷ�����
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetFinalActualHeatChemicalByHeatID(L3STRING strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetFinalStandardHeatChemicalByHeatID" type="L3LONG">
	/// ����¯�Ż�ȡ���ձ�׼�ɷ�����
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetFinalStandardHeatChemicalByHeatID(L3STRING strHeatID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GetReHeatCount" type="L3LONG">
	/// ��ȡ�ش������
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// <Param name="nUnitType" type="L3LONG"></Param>
	/// <Param name="nUnitID" type="L3LONG"></Param>
	/// </Method>
	L3LONG GetReHeatCount(L3STRING strHeatID,L3LONG nUnitType,L3LONG nUnitID);

	/// <Method class="CQA_HeatChemicalData_Mag" name="NewHeatExceptionData" type="L3LONG">
	/// �����µ�¯�ι����쳣����
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// <Param name="nUnitType" type="L3LONG"></Param>
	/// <Param name="nUnitID" type="L3LONG"></Param>
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewHeatExceptionData(L3STRING strHeatID,L3LONG nUnitType,L3LONG nUnitID,L3RECORDSET rsData);
    L3LONG LogHeatExceptionData(L3SHORT nUnitTypeID,
													 L3SHORT nUnitID, 
													 L3STRING strHeatID, 
													 L3SHORT nProcessCount, 
													 L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptBFIronElementData" type="L3LONG">
	/// ���ո�¯��ˮ��ʵ��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  AcceptBFIronElementData(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="GenLabSheet" type="L3LONG">
	/// ���ɻ���ί�е���
	/// <Param name="strSampleType" type="L3STRING">�������</Param>
	/// <Param name="strAddr" type="L3STRING">ȡ���ص�</Param>
	/// <Param name="strHeatID" type="L3STRING">¯��</Param>
	/// <Param name="nFinalFlag" type="L3STRING">��Ʒ����־</Param>
	/// </Method>
	L3RECORDSET  GenLabSheet(L3STRING strSampleType,L3STRING strAddr,L3STRING strHeatID,L3LONG nFinalFlag);

	    ////һ������ί�е�
	L3LONG  GenLabSheetNew(L3STRING strSampleType,L3STRING strAddr,L3STRING strHeatID,L3STRING strSteelGradeIndex,L3LONG nFinalFlag);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSteelElementText" type="L3LONG">
	/// ���ո����컯����(�ı�)
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabSteelElementText(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSlagElementText" type="L3LONG">
	/// ���������컯����(�ı�)
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
	/// </Method>
	L3LONG  AcceptSlagElementText(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabIronElement" type="L3LONG">
	/// ���������컯����
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabIronElement(L3RECORDSET rsData);


	/// <Method class="CQA_HeatChemicalData_Mag" name="SendSheetDataToAnaL2" type="L3BOOL">
	/// ��ί�е��´��컯�� 2009-01-03 
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL  SendSheetDataToAnaL2(L3RECORDSET rsData);


	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabIronElement" type="L3LONG">
	/// ���������컯����
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AcceptLabIronElementText(L3RECORDSET rsData);


	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptErrorInfo" type="L3LONG">
	/// ���ջ��鵥������Ϣ2009-01-03 tangyi
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
	/// </Method>
	L3LONG  AcceptErrorInfo (L3RECORDSET rsData);


	/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptReSampleInfor" type="L3LONG">
	/// ��������ȡ��ָʾ2009-01-03 tangyi
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
	/// </Method>
	L3LONG  AcceptReSampleInfor (L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="SendAnalysisDataToPLC" type="L3BOOL">
	/// ������̼¯�����´�PLC 2009-03-21
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL  SendAnalysisDataToPLC(L3FLOAT C_Ana,L3FLOAT S_Ana,L3FLOAT P_Ana);

	/// <Method class="CQA_HeatChemicalData_Mag" name="NewBFIronSheet" type="L3LONG">
	/// ��������������ί�е���
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  NewBFIronSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronSampleCode" type="CString">
	/// ����������ˮ��������
	/// <Param name="csTAPNo" type="LPCTSTR"> ���κ�
	/// <Param name="iMode" type="LPCTSTR"> ����ǰ���ʶ
	/// </Method>
	CString  CalDesIronSampleCode(LPCTSTR csTAPNo,LPCTSTR csTPCNo,L3SHORT iMode);

	/// <Method class="CQA_HeatChemicalData_Mag" name="NewDeSIronSheet" type="L3LONG">
	/// ��������Ԥ����������ί�е���
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  NewDeSIronSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="NewBFSlagSheet" type="L3LONG">
	/// ������������ί�е���
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG  NewBFSlagSheet(L3RECORDSET rsData);

	/// <Method class="CQA_HeatChemicalData_Mag" name="SetDeSAnalysisData" type="L3BOOL">
	/// ��������������� 2009-10-25 yao
	/// <Param name="SampleCode" type="LPCTSTR"> ���������
	/// <Param name="S" type="L3FLOAT"> ��
	/// <Param name="P" type="L3FLOAT"> ��
	/// </Method>
	L3BOOL  SetDeSAnalysisData(LPCTSTR SampleCode,L3FLOAT S,L3FLOAT P);

};

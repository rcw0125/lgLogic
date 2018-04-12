// �߼���CQA_HeatGradeAssume_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CQA_HeatGradeAssume_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CQA_HeatGradeAssume_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CQA_HeatGradeAssume_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CQA_HeatGradeAssume_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CQA_HeatGradeAssume_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


/// <Method class="CQA_HeatGradeAssume_Mag" name="LogHeatExceptionData" type="L3LONG">
/// ��¼¯�ι����쳣
/// <Param name="nUnitTypeID" type="L3SHORT">����</Param>
/// <Param name="nUnitID" type="L3SHORT">��λID</Param>
/// <Param name="strHeatID" type="L3STRING">������</Param>
/// <Param name="nProcessCount" type="L3SHORT">����λ�������</Param>
/// <Param name="rsData" type="L3RECORDSET">
/// �쳣���ݣ����������
/// nUnitTypeID(�����ʶ)��nUnitID(��λID)��strHeatID�������ţ���nProcessCount������λ�����������ExceptCode���쳣���룩</Param>
/// </Method>
L3LONG CQA_HeatGradeAssume_Mag::LogHeatExceptionData(L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strHeatID, L3SHORT nProcessCount, L3RECORDSET rsData)
{
	if (strHeatID == NULL) 
		return -1;

	//***********************//			
	CL3RecordSetWrap rs=rsData;
	if(rs.GetRowCount()<1)
	{
		return -1;
	}

	CString cstrHeatID = strHeatID;

	rs.MoveFirst();
	CString strExceptionalCode = (rs.GetFieldByName(_T("Exceptional_Code"))).ToCString();

	//��ѯ¯�ε�ǰԤ��¯�š����ּǺ�
	CString strPresetHeatID = (GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID,_T("PreHeatID"))).ToCString();
	CString strSteelGradeIndex = (GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID,_T("SteelGradeIndex"))).ToCString();
	CString strPreSteelGradeIndex = (GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID,_T("Pre_SteelGradeIndex"))).ToCString();

    CString cstrUnitTypeID,cstrUnitID,strProcessCount; 
    strProcessCount.Format(_T("%d"),nProcessCount);
	cstrUnitTypeID.Format(_T("%d"),nUnitTypeID);
	cstrUnitID.Format(_T("%d"),nUnitID);
	cstrUnitTypeID = _T("S")+cstrUnitTypeID;

	CString strPky = cstrHeatID + cstrUnitTypeID + cstrUnitID + strProcessCount + strExceptionalCode;

	CString strURI = _T("XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except");//��ȡ��URI
 	CL3RecordSetWrap RS;
	if(this ->CreateClassPropSet(strURI,RS))
	{
		RS.DeleteRecord();
		RS->CopyFrom(rsData);
		RS.MoveFirst();
		RS.SetFieldByName(_T("ID_Object"),CL3Variant(strPky));
		RS.SetFieldByName(_T("UnitTypeID"),(L3SHORT)nUnitTypeID);
		RS.SetFieldByName(_T("UnitID"),(L3SHORT)nUnitID);
		RS.SetFieldByName(_T("HeatID"),strHeatID);
		RS.SetFieldByName(_T("PreHeatID"),CL3Variant(strPresetHeatID));
		RS.SetFieldByName(_T("SteelGradeIndex"),CL3Variant(strSteelGradeIndex));
		RS.SetFieldByName(_T("Pre_SteelGradeIndex"),CL3Variant(strPreSteelGradeIndex));
        RS.SetFieldByName(_T("ProcessCount"),(L3SHORT)nProcessCount);
	}
	if (CreateNewObjects(strURI, RS) < 1)
		return -2;//���������쳣ʧ��

	//�޸Ķ���CHeatGradeAssumeMag����NewHeatAbnormalEvent=NewHeatAbnormalEvent +1
	CString strURIHeatGradeAssumeMag = _T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssume_Mag\\QA_HeatGradeAssume_Mag");//��ȡ����URI
	CL3Variant val = GetObjectPropValue(strURIHeatGradeAssumeMag, _T("NewHeatAbnormalEvent"));		
	int NewHeatAbnormalEvent = val.ToLong();
	int NewHeatAbnormalEvent1 = (NewHeatAbnormalEvent % 9999) + 1;

	if (!SetObjectPropValue(strURIHeatGradeAssumeMag,
		                    _T("NewHeatAbnormalEvent"),
							(L3LONG)NewHeatAbnormalEvent1)) 
		return -3;//�޸�ָ�����������ֵ		

	//����¯�εȼ��ж��㷨�෽��
	CL3Variant valReturn = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssumeAlg_Mag\\QA_HeatGradeAssumeAlg_Mag"),
		                                      _T("EstimateHeatGrade"),
											  (L3SHORT)nUnitTypeID,
											  (L3SHORT)nUnitID,
											  strHeatID,
											  (L3SHORT)nProcessCount);	
	if (valReturn.IsError())  
		return -3;
	return 1;	
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="HeatJudge" type="L3SHORT">
/// �ж��������ּǺ�
/// <Param name="strHeatID" type="L3STRING">������</Param>
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// <Param name="rsData" type="L3RECORDSET">
/// �����иּ�¼��,������
/// HeatID��DecideSteelGradeIndex�ֶ�
/// </Param>
/// </Method>
L3LONG CQA_HeatGradeAssume_Mag::HeatJudge(L3STRING strHeatID, L3STRING strSteelGradeIndex, L3RECORDSET rsData)
{
	//����У��
	CL3RecordSetWrap rs = rsData;
	if ((rs.GetRowCount()<1) || (strHeatID == NULL) || (strSteelGradeIndex == NULL))
		return 0;

	CString cstrHeatID = strHeatID;
	CString cstrSteelGradeIndex = strSteelGradeIndex;

	//��CSteel_Data�л�ȡ�������ּǺű�־����DecideSteelGradeIndexFlag=0��ʾδ�и�
	L3LONG nDecideFlag = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+cstrHeatID,_T("DecideSteelGradeIndexFlag"))).ToLong();
	if (nDecideFlag != 0)//�иֺ��ٽ����и�
		return -1;

    CString strPresetHeatID = (GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+cstrHeatID,_T("PreHeatID"))).ToCString();

  /*******�������ּǺŲ�Ϊ���У����¯���иֻ�ѧ�ɷ��Ƿ����************************/
  if ((cstrSteelGradeIndex != _T("YY000000")))
	{
		CString csSQL;
		csSQL.Format(_T("select HeatID from %s where HeatID = '%s' and UnitTypeID = 6"),
			         _T("XGMESLogic\\QualityMag\\CQA_Lab_Element"),cstrHeatID);
		CL3RecordSetWrap rsElement;
		if (!Query(csSQL, rsElement) || rsElement.IsNull() || (rsElement.GetRowCount() < 1))	
			return -2; 
	}
	/************************************************************************/

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	//���CQA_HeatGradeData(¯��Ʒ����Ϣʵ���ࣩ�ж�����ڷ�
	CString strUnitTypeID;
	strUnitTypeID.Format(_T("%d"),nUnitTypeID);
    CString strProcessCount; 
	strProcessCount.Format(_T("%d"),nProcessCount);
	CString strID_Object1 = cstrHeatID+strProcessCount+strUnitTypeID;//���ɶ����ʶ
	CString URIHeatGradeQAData = _T("XGMESLogic\\QualityMag\\CQA_HeatGradeData\\") + strID_Object1;//��ȡCHeatGradeQAData����URI
	CL3Variant valRet = GetObjectPropValue(URIHeatGradeQAData,_T("Exceptional_Code"));
	if ((valRet.IsError()) && (GetL3LastError() == L3ERR_OBJECT_NOTEXIST))
	{
		if (!CreateNewObject(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeData"),(CL3Variant)strID_Object1)) 
		{
			if (bUseTrans)
				Rollback(nTrans);
			return -3; //��������ʧ��
		}
	}
	//���ö���CQA_HeatGradeData������ԣ�DataLogMode=1��
	SetObjectPropValue(URIHeatGradeQAData,_T("HeatID"),CL3Variant(strHeatID));
	SetObjectPropValue(URIHeatGradeQAData,_T("PresetHeatID"),CL3Variant(strPresetHeatID));
	SetObjectPropValue(URIHeatGradeQAData,_T("UnitTypeID"),(L3SHORT)nUnitTypeID);
	SetObjectPropValue(URIHeatGradeQAData,_T("ProcessCount"),(L3SHORT)nProcessCount);
	SetObjectPropValue(URIHeatGradeQAData,_T("DataLogMode"),(L3SHORT)nDataLogMode);
	SetObjPropValues(URIHeatGradeQAData,rs);
  
  //���ö���CHeatID������ԣ�DecideSteelGradeIndex..	    
  CString URIHeatID = _T("MES\\MaterialData\\CSteel_Data\\") + cstrHeatID;//��ȡCHeatID����URI

	CL3Variant valRet1 = GetObjectPropValue(URIHeatID,_T("HeatID"));
	if ((valRet1.IsError()) && (GetL3LastError() == L3ERR_OBJECT_NOTEXIST))
	{
		if (!CreateNewObject(_T("MES\\MaterialData\\CSteel_Data"),(CL3Variant)cstrHeatID))
		{
			if (bUseTrans)
				Rollback(nTrans);
			return -3; 
		}
	}
	/***********************************/

  SetObjPropValues(URIHeatID,rs);
  SetObjectPropValue(URIHeatID,_T("DecideSteelGradeIndexFlag"),(L3SHORT)nDecideSteelGradeIndexFlag1);//��������:DecideSteelGradeIndexFlag=1��
  L3SHORT nDecideFinalFlag;
  if ((cstrSteelGradeIndex == _T("YY000000")) || (cstrSteelGradeIndex == _T("YB000000")))
		nDecideFinalFlag = 1;
	else
		nDecideFinalFlag = 0;
  SetObjectPropValue(URIHeatID,_T("DecideFinalFlag"),(L3SHORT)nDecideFinalFlag);//��������:DecideFinalFlag��

  //��¼����������Ϣ
	CStringArray FieldNames; FieldNames.SetSize(2);
	CUIntArray FieldTypes; FieldTypes.SetSize(2);
	FieldNames[0] = _T("HeatID");
	FieldNames[1] = _T("ActionCode");

	FieldTypes[0] = L3VT_STRING;
	FieldTypes[1] = L3VT_STRING;

	CL3RecordSetWrap rsQA;
	if (!CreateRecordSet(FieldNames,FieldTypes,rsQA)|| rsQA.IsNull())
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -1; //��������ʧ��
	}

	rsQA.AppendRecord();
	rsQA.SetFieldByName(_T("HeatID"),CL3Variant(cstrHeatID));
	rsQA.SetFieldByName(_T("ActionCode"),1);//¯���ж�

	rsQA.MoveFirst();
	//if (LogQAOperateInfo(rsQA) < 1)  //���ΰ��������⣬��ʱ���Σ�081126
	//{
	//	if (bUseTrans)
	//		Rollback(nTrans);
	//	return -1; //��������ʧ��
	//}
	if (bUseTrans)
		Commit(nTrans);
	return 1;// TODO : ���ڴ�����߼�����
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="LogQAOperateInfo" type="L3SHORT">
/// 
/// ��¼����������Ϣ
/// 
/// 
/// <Param name="rsData" type="L3RECORDSET">����¯�š���������ļ�¼��</Param>
/// </Method>
L3LONG CQA_HeatGradeAssume_Mag::LogQAOperateInfo(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	rs.AddField(_T("Shift"),L3VT_STRING);
	rs.AddField(_T("Team"),L3VT_STRING);
	rs.AddField(_T("Operator"),L3VT_STRING);
	rs.AddField(_T("OpeateTime"),L3VT_DATETIME);
	// �����ֶ���Ϣ

	CL3Variant valRtemp = InvokeObjectMethod(_T(""),_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rstemp;
	if(!SUCCEEDED(valRtemp.QueryInterface(IID_IL3RecordSet,rstemp)))
	{
		return -1; //��ѯ�����Ϣʧ��
	}

	if (rstemp.GetRowCount() < 1)
	{
		return -1;//��¼��Ϊ��
	}
	rstemp.MoveFirst();
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("Shift"),rstemp.GetFieldByName(_T("ShiftID")));
		rs.SetFieldByName(_T("Team"),rstemp.GetFieldByName(_T("TeamID")));
		rs.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		rs.SetFieldByName(_T("OpeateTime"),CL3Variant((L3DATETIME)(COleDateTime::GetCurrentTime())));

		rs.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rs.MoveFirst();
	LONG nRet = CreateNewObjects(_T("MES\\MaterialData\\CQA_Operate_Log"),rs);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	if(bUseTrans)
		Commit(nTrans);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="HeatFinalJudge" type="L3SHORT">
/// 
/// ¯������
/// 
/// 
/// <Param name="strHeatID" type="L3STRING">������</Param>
/// <Param name="rsData" type="L3RECORDSET">¯�����м�¼��</Param>
/// </Method>
L3LONG CQA_HeatGradeAssume_Mag::HeatFinalJudge(L3STRING strHeatID, L3RECORDSET rsData,L3STRING strAppID)
{
	//20081213tangyi �޸�
	if ((strHeatID == NULL) || (rsData == NULL) || (strAppID == NULL) || rsData->GetRecordCount() < 1)
		return -1;

	CString csAppID = strAppID;

	CL3RecordSetWrap rs = rsData;
	rs.MoveFirst();

	CString csHeatID = strHeatID;
	//���к�����ּǺ�
	CString csFinalSteelGradeIndex = rs.GetFieldByName(_T("Final_SteelGradeIndex")).ToCString();
	//����ǰ�����ּǺ�
	CString csSteelGradeIndex = rs.GetFieldByName(_T("SteelGradeIndex")).ToCString();//2009-03-31
	CString csSteelGradeUri = QA_STG_RELATION_CLASS_URI + _T("\\") + csFinalSteelGradeIndex;
	CString csIsExit = GetObjectPropValue(csSteelGradeUri,_T("SteelGradeIndex")).ToCString();
	csIsExit.Trim();
	if(csIsExit.IsEmpty()) return -2;

	CString csSQL;
	csSQL.Format(_T("select HeatID from %s where HeatID = '%s' and (Sample_Type = 'GP' or Sample_Type = 'GE' or Sample_Type = 'GL')"),//[20081230Liao]
		         QA_LAB_ELEMENT_CLASS_URI,csHeatID);
	CL3RecordSetWrap rsElement;
	if (!Query(csSQL, rsElement) || rsElement.IsNull() || (rsElement.GetRowCount() < 1))	
		return -3; 

	
	//�齨���ݼ�
	CL3RecordSet *pRSIron = new CL3RecordSet();
	CL3RecordSetWrap rsBloomMaterial; pRSIron->QueryInterface(IID_IL3RecordSet,rsBloomMaterial); pRSIron->Release();
	rsBloomMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsBloomMaterial.AddField(_T("Status"),VT_BSTR);
	rsBloomMaterial.AddField(_T("Right_Count"),VT_INT);
	rsBloomMaterial.AddField(_T("Right_Weight"),VT_R8);
	rsBloomMaterial.AddField(_T("Wrong_Count"),VT_INT);
	rsBloomMaterial.AddField(_T("Wrong_Weight"),VT_R8);
	rsBloomMaterial.AddField(_T("Wrong_Count1"),VT_INT);
	rsBloomMaterial.AddField(_T("Wrong_Weight1"),VT_R8);
	rsBloomMaterial.AddField(_T("Wrong_Reason1"),VT_BSTR);
	rsBloomMaterial.AddField(_T("Wrong_Count2"),VT_INT);
	rsBloomMaterial.AddField(_T("Wrong_Weight2"),VT_R8);
	rsBloomMaterial.AddField(_T("Wrong_Reason2"),VT_BSTR);
	rsBloomMaterial.AddField(_T("Wrong_Count3"),VT_INT);
	rsBloomMaterial.AddField(_T("Wrong_Weight3"),VT_R8);
	rsBloomMaterial.AddField(_T("Wrong_Reason3"),VT_BSTR);
	rsBloomMaterial.AddField(_T("SufaceDefactDes"),VT_BSTR);
	rsBloomMaterial.AddField(_T("SteelGradeIndex"),VT_BSTR);
	rsBloomMaterial.AddField(_T("Final_SteelGradeIndex"),VT_BSTR);
	rsBloomMaterial.AddField(_T("Process_Type"),VT_INT);
	rsBloomMaterial.AddField(_T("Test_Roll_Count"),VT_INT);//2008-12-31 tangyi
	rsBloomMaterial.AddField(_T("Test_Roll_Weight"),VT_R8);
	rsBloomMaterial.AddField(_T("Store_ChangeJudge_Flag"),VT_R4);//2009-04-04 tangyi

	rsBloomMaterial.AppendRecord();
	rs.MoveFirst();
	rsBloomMaterial.CopyCurRowFrom(rs);
	rsBloomMaterial.SetFieldByName(_T("SteelGradeIndex"),CL3Variant(csFinalSteelGradeIndex));
	rsBloomMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csHeatID));

	//�õ�����ǰ�ĸ���״̬���ϸ����֧��2009-04-08
	CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
	CL3Variant vsStatus = GetObjectPropValue(csBloomUri,_T("Status"));
	L3LONG nStatus = vsStatus.ToLong();
	CL3Variant vsBloomCount = GetObjectPropValue(csBloomUri,_T("Right_Count"));
	L3LONG nPreRightBloomCount = vsBloomCount.ToLong();
	//���к�ĺϸ����֧��2009-04-08
	L3LONG nCurRightBloomCount = rs.GetFieldByName(_T("Right_Count")).ToLong();

	if((nStatus ==7) || (nStatus ==8))
		rsBloomMaterial.SetFieldByName(_T("Status"),CL3Variant(BLOOM_STATUS_FIN_JUDGE));
	else
	{
		if(nStatus ==12)
		{
			rsBloomMaterial.SetFieldByName(_T("Status"),CL3Variant(BLOOM_STATUS_COOL_JUDGE));
			//�ı�����ֵ2009-01-05 tangyi
			CString csUri = BLOOM_STORE_OBJ_URI;
			CL3Variant varStoreEvent = GetObjectPropValue(csUri,_T("MaterialInputted"));
			L3SHORT nStoreEvent = varStoreEvent.ToShort();
			nStoreEvent = (nStoreEvent+1) % 9999;
			SetObjectPropValue(csUri,_T("MaterialInputted"),nStoreEvent);
		}
		else
			rsBloomMaterial.SetFieldByName(_T("Status"),vsStatus);
	}

	//��ʼ����
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if (bUseTrans)
	{
		nTrans = BeginTrans();
		if (nTrans < 1)
		{
			return -1;
		}
	}

	if(!SetObjsPropValues(BLOOM_DATA_CLASS_URI,rsBloomMaterial))
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -5;
	}

    //2009-01-09 Begin
	csSQL.Format(_T("select * from %s where HeatID = '%s' and FinalJudgeFlag = 1"),
		         QA_LAB_ELEMENT_CLASS_URI,csHeatID);
	CL3RecordSetWrap rsFinalElement;
	if (!Query(csSQL, rsFinalElement) || rsFinalElement.IsNull())	
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -9; 
	}
	L3LONG rsCount = rsFinalElement.GetRowCount();
	if (rsCount > 0)
	{
		rsFinalElement.MoveFirst();
		while(!rsFinalElement.IsEOF())
		{
			CString cstrAppID = (rsFinalElement.GetFieldByName(_T("AppID"))).ToCString();
	       if (!SetObjectPropValue(QA_LAB_ELEMENT_CLASS_URI+_T("\\")+cstrAppID,_T("FinalJudgeFlag"),CL3Variant((L3LONG)0)))
		   {
				if (bUseTrans)
					Rollback(nTrans);
				return -10; 
		   }
			rsFinalElement.MoveNext();
		}
	}
	
	if (!SetObjectPropValue(QA_LAB_ELEMENT_CLASS_URI+_T("\\")+csAppID,_T("FinalJudgeFlag"),CL3Variant((L3LONG)1)))
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -11; 
	}
	//2009-01-09 End

	//�齨��־���ݼ�
	CL3RecordSetWrap rsFinJudgeData;
	if(!CreateClassPropSet(QA_FIN_JUDGE_CLASS_URI,rsFinJudgeData))
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -6;
	}
	rsFinJudgeData.DelField(_T("GUID"));
	rsFinJudgeData.AppendRecord();
	rs.MoveFirst();
	rsFinJudgeData.CopyCurRowFrom(rs);

	//��ȡ�������Ϣ
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	CString csShiftID = rpSysInfo.GetFieldByName(_T("ShiftID")).ToCString();
	CString csTeamID = rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();

	rsFinJudgeData.SetFieldByName(_T("Team"),CL3Variant(csTeamID));
	rsFinJudgeData.SetFieldByName(_T("Shift"),CL3Variant(csShiftID));
	rsFinJudgeData.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rsFinJudgeData.SetFieldByName(_T("HeatID"),rs.GetFieldByName(_T("MaterialID")));
	rsFinJudgeData.SetFieldByName(_T("FinalJudge_Time"),COleDateTime::GetCurrentTime());

	//�ж��Ƿ���ڸ���
	if(nStatus ==12 && (csFinalSteelGradeIndex != csSteelGradeIndex || nPreRightBloomCount != nCurRightBloomCount))
		//�޸Ŀ��ڸ���Store_ChangeJudge_Flag��־
		rsFinJudgeData.SetFieldByName(_T("Store_ChangeJudge_Flag"),L3LONG(1));


	if(CreateNewObjects(QA_FIN_JUDGE_CLASS_URI,rsFinJudgeData) < 1)
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -7;
	}


	if (bUseTrans)
		Commit(nTrans);

	//�ж��Ƿ���ڸ��У�
	//���ڸ���һ���Ǹ������ȼ�2009-04-08
	if(nStatus ==12 && (csFinalSteelGradeIndex != csSteelGradeIndex || nPreRightBloomCount != nCurRightBloomCount))
	{
		//֪ͨͨѶ��NC���Ϳ��ڸ��е���2009-03-22
		CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
		CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Store_Change_Event"));
		L3LONG nEvent = varEvent.ToLong();
		nEvent = (nEvent+1) % 9999;
		SetObjectPropValue(csBaseUri,_T("NC_Store_Change_Event"),nEvent);

	}


	//�޸������¼�֪ͨ������λ��������2009-01-02tangyi
	CL3Variant varEvent = GetPropValue(_T("FinalJudgeEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("FinalJudgeEvent"),nEvent);


	return 0;
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="GetHeatGradeData" type="L3RECORDSET">
/// ��ȡ¯��Ʒ���ж�����
/// <Param name="strHeatID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetHeatGradeData(L3STRING strHeatID)
{
	CString cstrHeatID = strHeatID;
	CString strSQL;
	strSQL.Format(_T("select * from CQA_HeatGradeData where HeatID = '%s'"),cstrHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeData"),rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="GetHeatProcessExceptData" type="L3RECORDSET">
/// ��ȡ¯�ι����쳣����
/// <Param name="strHeatID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetHeatProcessExceptData(L3STRING strHeatID)
{
	CString cstrHeatID = strHeatID;
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Heat_Prod_Except where HeatID = '%s'"),cstrHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except"),rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="GetHeatJudgeUnitInfo" type="">
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetHeatJudgeUnitInfo()
{
	CString strSQL;
	strSQL.Format(_T("select HeatID  from CSteel_Data where DecideFinalFlag =1"));
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CSteel_Data"),rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="GetUnJudgeHeatID" type="L3RECORDSET">
/// 
/// ��ȡ��Ҫ�иֵ�¯��
/// ARG&gt;&gt; CCMID��������
/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
/// <Param name="CCMID" type="L3LONG">������</Param>
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetUnJudgeHeatID(L3LONG CCMID)
{
	CString csCasterID;
	csCasterID.Format(_T("S6%1d"),CCMID);
    CString strSQL;
	strSQL.Format(_T("select a.HeatID,a.CCMID from CCCM_Base_Data a,CBloom_Data b where a.HeatID = b.HeatID and b.Status = '%s' and a.CCMID = '%s'"),BLOOM_STATUS_CUT,csCasterID);
	CL3RecordSetWrap rs;
	if (! Query(strSQL,rs))
	{
		return NULL;// TODO : ���ڴ�����߼�����
	}
	//if (rs.GetRowCount()>0)
		return rs.Detach();
	//else
	//	return NULL;
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="GetFinJudgeHeat" type="L3RECORDSET">
/// 
/// ��ȡ��Ҫ����¯��
/// ARG&gt;&gt; strCasterID��������
/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
/// <Param name="strCasterID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetFinJudgeHeat(L3STRING strCasterID,L3STRING strCondition)
{
	CString csCaster = strCasterID;
	CString csCon = strCondition;
	CString csCondition;
	if(csCon == _T("0"))
		csCondition.Format(_T(" (a.Status = %s or a.Status = %s) and a.SteelGradeIndex = b.SteelGradeIndex "),BLOOM_STATUS_HOT_JUDGE,BLOOM_STATUS_HOT_WAIT);	
	else
		if(csCon == _T("2"))
			csCondition.Format(_T(" a.Final_SteelGradeIndex ='%s'  and a.Process_Type = 0 and a.SteelGradeIndex = b.SteelGradeIndex "),WAITING_FIN_JUDGE);	
		else
			if(csCon == _T("3"))
				csCondition.Format(_T(" a.Status = %s  and a.SteelGradeIndex = b.SteelGradeIndex  "),BLOOM_STATUS_CHECK);
				else
					return NULL;

	
	//switch(nCondition)
	//{
	//	case HotChecked:
	//		csCondition.Format(_T(" (a.Status = %s or a.Status = %s) and a.SteelGradeIndex = b.SteelGradeIndex "),BLOOM_STATUS_HOT_JUDGE,BLOOM_STATUS_HOT_WAIT);	
	//		break;
	//	case WaitJudge:
	//		csCondition.Format(_T(" a.Final_SteelGradeIndex ='%s'  and a.SteelGradeIndex = b.SteelGradeIndex "),WAITING_FIN_JUDGE);	
	//		break;
	//	case ColdCheck:
	//		csCondition.Format(_T(" a.Status = %s  and a.SteelGradeIndex = b.SteelGradeIndex  "),BLOOM_STATUS_CHECK);	
	//		break;
	//}
	csCaster.Trim();
	CString strSQL;
	if(csCaster.IsEmpty())
	{
		strSQL.Format(_T("select a.CasterID,a.HeatID,a.Status,a.Pre_SteelGradeIndex,a.SteelGradeIndex,a.Cut_SteelGradeIndex,a.Final_SteelGradeIndex,b.SteelGrade,b.Protocol from %s a,%s b  where  %s   order by a.CasterID ,a.HeatID "),
			          MATERIAL_TYPE_BLOOM,QA_STG_RELATION_CLASS_URI,csCondition);
	}
	else

		strSQL.Format(_T("select a.CasterID,a.HeatID,a.Status,a.Pre_SteelGradeIndex,a.SteelGradeIndex,a.Cut_SteelGradeIndex,a.Final_SteelGradeIndex,b.SteelGrade,b.Protocol from %s a,%s b where a.CasterID ='%s'  and  %s order by a.HeatID "),
		                MATERIAL_TYPE_BLOOM,QA_STG_RELATION_CLASS_URI,csCaster,csCondition);
	
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}


/// <Method class="CQA_HeatGradeAssume_Mag" name="GetSurfaceJudgeInfor" type="L3RECORDSET">
/// 
/// ����¯�Ż�ȡ�����ȼ���Ϣ
/// ARG&gt;&gt; strHeatID��������
/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
/// <Param name="strCasterID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetSurfaceJudgeInfor(L3STRING strHeatID)
{
	CString csHeatID = strHeatID;
	csHeatID.Trim();
	if(csHeatID.IsEmpty()) return NULL;
	CString strSQL;
	strSQL.Format(_T("select * from (select * from %s where HeatID ='%s' order by HotJudge_Time desc) where rownum = 1 "),QA_HOT_JUDGE_CLASS_URI,csHeatID);
	
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}


/// <Method class="CQA_HeatGradeAssume_Mag" name="GetFinJudgeInfor" type="L3RECORDSET">
/// 
/// ����¯�Ż�ȡ����������Ϣ
/// ARG&gt;&gt; strHeatID��������
/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
/// <Param name="strCasterID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetFinJudgeInfor(L3STRING strHeatID)
{
	CString csHeatID = strHeatID;
	csHeatID.Trim();
	if(csHeatID.IsEmpty()) return NULL;
	CString strSQL;
	strSQL.Format(_T("select * from (select * from %s where HeatID ='%s' order by FinalJudge_Time desc) where rownum = 1 "),QA_FIN_JUDGE_CLASS_URI,csHeatID);
	
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}


/// <Method class="CQA_HeatGradeAssume_Mag" name="GetBloomStdEle" type="L3RECORDSET">
/// 
/// ����¯�Ż�ȡ�����ɷֱ�׼
/// ARG&gt;&gt; strHeatID��������
/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
/// <Param name="strCasterID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetBloomStdEle(L3STRING strHeatID)
{
	CString csHeatID = strHeatID;
	csHeatID.Trim();
	if(csHeatID.IsEmpty()) return NULL;
	////Modify begin by llj 2011-03-28 Ϊ������ת¯��ˮֱ�Ͳ������������
	//CString csSql;
	//csSql.Format(_T("select CasterID from %s where HeatID='%s'"),PLAN_TAPPING_CLASS_URI,csHeatID);
	//CL3RecordSetWrap rsTapping;
	//if(!Query(csSql,rsTapping)||rsTapping.IsNull()||rsTapping.GetRowCount()<1)
	//	return NULL;
	//rsTapping.MoveFirst();
	//CString csCasterID=rsTapping.GetFieldByName(_T("CasterID")).ToString();
	CString csSteelGradeIndex;
	//if(csCasterID==_T("S66"))
	//{
	//	CString csBofBaseDataUri= BOF_BASE_DATA_CLASS_URI + _T("\\") + csHeatID;
	//	csSteelGradeIndex= GetObjectPropValue(csBofBaseDataUri,_T("SteelGradeIndex")).ToCString();
	//}
	//else
	//{
	////Modify end
		CString csBloomUri= BLOOM_DATA_CLASS_URI + _T("\\") + csHeatID;
		csSteelGradeIndex= GetObjectPropValue(csBloomUri,_T("SteelGradeIndex")).ToCString();
	//}
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s' "),QA_PROD_SHEET_CLASS_URI,csSteelGradeIndex);	
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs)||rs.IsNull()||rs.GetRowCount()<1)
		return NULL;
	else
		return rs.Detach();
}


/// <Method class="CQA_HeatGradeAssume_Mag" name="GetBloomTerminalEle" type="L3RECORDSET">
/// 
/// ����¯�Ż�ȡ�����յ���
/// ARG&gt;&gt; strHeatID��������
/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
/// <Param name="strCasterID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetBloomTerminalEle(L3STRING strHeatID)
{

	CString csHeatID = strHeatID;
	csHeatID.Trim();
	if(csHeatID.IsEmpty()) return NULL;
	//CString csSteelUri = MATERIAL_STEEL_URI + _T("\\") + csHeatID;
	//CString csSteelGradeIndex = GetObjectPropValue(csSteelUri,_T("FinalChemiclaFlag")).ToCString();
	//if(csSteelGradeIndex != _T("1")) return NULL;

	CString strSQL;
	/*���� by hyh 2012-06-13
	////Modify begin by llj 2011-03-28 Ϊ��ת¯��ˮֱ�Ͳ��������
	//CString csSql;
	//csSql.Format(_T("select CasterID from %s where HeatID='%s'"),PLAN_TAPPING_CLASS_URI,csHeatID);
	//CL3RecordSetWrap rsTapping;
	//if(!Query(csSql,rsTapping)||rsTapping.IsNull()||rsTapping.GetRowCount()<1)
	//	return NULL;
	//rsTapping.MoveFirst();
	//CString csCasterID=rsTapping.GetFieldByName(_T("CasterID")).ToString();
	//if(csCasterID==_T("S66"))
	//{
	//	strSQL.Format(_T("select * from %s where (SAMPLE_ADDRESS='Z1'or SAMPLE_ADDRESS='Z2' or SAMPLE_ADDRESS='Z3' or SAMPLE_ADDRESS='Z4') and HeatID = '%s'  order by LogTime desc"),QA_LAB_ELEMENT_CLASS_URI,csHeatID);
	//}
	//else
	//{
	////Modify end
	*/
		strSQL.Format(_T("select * from %s where (Sample_Type = 'GP' or Sample_Type = 'GE' or Sample_Type = 'GL') and HeatID = '%s'  order by LogTime desc"),QA_LAB_ELEMENT_CLASS_URI,csHeatID);
	//}
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs)||rs.IsNull()||rs.GetRowCount()<1)
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="ModHeatGrade" type="L3LONG">
/// ������ǰ¯�εȼ�
/// <Param name="strHeatID" type="L3STRING">������</Param>
/// <Param name="nProcessCount" type="L3SHORT">�ش������</Param>
/// <Param name="nUnitTypeID" type="L3SHORT">����</Param>
/// <Param name="rsData" type="L3RECORDSET">����¯�εȼ����쳣���롢���ô��롢���ȼ�</Param>
/// </Method>
L3LONG CQA_HeatGradeAssume_Mag::ModHeatGrade(L3STRING strHeatID, L3SHORT nProcessCount, L3SHORT nUnitTypeID, L3RECORDSET rsData)
{
	return 0;// TODO : ���ڴ�����߼�����
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="CreateQAHeatGradeData" type="L3LONG">
/// ������ʼ¯�εȼ�
/// <Param name="strHeatID" type="L3STRING">������</Param>
/// <Param name="strPresetHeatID" type="L3STRING">Ԥ��¯��</Param>
/// <Param name="nUnitTypeID" type="L3SHORT">����</Param>
/// <Param name="nUnitID" type="L3SHORT">��λ</Param>
/// <Param name="strSteelGradeIndex" type="L3STRING">��ǰ��ҵ���ּǺ�</Param>
/// </Method>
L3LONG CQA_HeatGradeAssume_Mag::CreateQAHeatGradeData(L3STRING strHeatID, L3STRING strPresetHeatID, L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strSteelGradeIndex)
{
	return 0;// TODO : ���ڴ�����߼�����
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="GetRefineThirdEle" type="L3RECORDSET">
/// 
/// ����¯�Ż�ȡ���������γɷ�����
/// ARG&gt;&gt; strHeatID��������
/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
/// <Param name="strCasterID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetRefineThirdEle(L3STRING strHeatID)
{
	CString csHeatID = strHeatID;
	csHeatID.Trim();
	if(csHeatID.IsEmpty()) return NULL;

	CString strSQL;
	strSQL.Format(_T("select * from (select * from %s where HeatID='%s' and (UnitTypeID = 4 or  UnitTypeID = 5) and Sample_Count >= '03' and  Sample_Type = 'GG' order by UnitTypeID desc) where rownum < 2 "),QA_LAB_ELEMENT_CLASS_URI,csHeatID);	
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="BofSteelQualityJudge" type="L3LONG">
///	ת¯��ˮֱ�Ͳ�����ж�
/// <Param name="rsBofSteelInfo" type="L3RECORDSET">��ˮ��Ϣ</Param>
/// </Method>
L3LONG CQA_HeatGradeAssume_Mag::BofSteelQualityJudge(L3RECORDSET rsBofSteelInfo)
{
	//ת¯��ˮֱ�Ͳ����������ڸ�ˮ���������ж���ͬʱ��
	//�Ѹ�ˮ������Ϣд��cqa_bloom_finjudge_data��
	// TODO : ���ڴ�����߼�����

	//modify by hyh 2012-06-13  ���� �˷���
	return 0;
	CL3RecordSetWrap pBofSteelInfo=rsBofSteelInfo;

	if(pBofSteelInfo.IsNull()||(pBofSteelInfo.GetRowCount()<1&&pBofSteelInfo.GetRowCount()>1))
		return -1;

	CString csHeatID=pBofSteelInfo.GetFieldByName(_T("HeatID")).ToCString();
	L3LONG nJudgeFlag=pBofSteelInfo.GetFieldByName(_T("JudgeFlag")).ToLong();//�ж������0;�ϸ� -1�����ϸ�
	CString csAppID =pBofSteelInfo.GetFieldByName(_T("AppID")).ToCString();

	if(nJudgeFlag!=0&&nJudgeFlag!=-1)
		return -1;

	csHeatID=csHeatID.Trim();
	csAppID=csAppID.Trim();
	if(csHeatID==_T(""))
		return -1;

	//���ת¯ʵ���Ƿ�ȷ��
	CString csLocked=GetObjectPropValue(_T("XGMESLogic\\BOFMag\\CBOF_Base_Data\\")+csHeatID,_T("Locked")).ToCString();
	if(csLocked!="1")
		return -2;//ת¯ʵ��δȷ��

	

	//����ˮ���м�¼�Ƿ����
	CString csSQL;
	csSQL.Format(_T("select HeatID from %s where HeatID = '%s'"),
		         QA_FIN_JUDGE_CLASS_URI,csHeatID);
	CL3RecordSetWrap rs;
	if (!Query(csSQL, rs) || rs.GetRowCount()>0)	
	{
		return -3; 
	}

	csSQL.Format(_T("select HeatID from %s where HeatID = '%s'"),
		         CCM_BASE_DATA_CLASS_URI,csHeatID);
	if (!Query(csSQL, rs) || rs.GetRowCount()>0)	
	{
		return -3; 
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	//������������������¼��
	CL3RecordSetWrap rsQaBloomFinjudgeData;
	CreateClassPropSet(QA_FIN_JUDGE_CLASS_URI,rsQaBloomFinjudgeData);
	rsQaBloomFinjudgeData.AppendRecord();

	//��ȡת¯�������ݵĳ�����
	L3FLOAT fBofSteelWeight=GetObjectPropValue(_T("XGMESLogic\\BOFMag\\CBOF_Process_Data\\")+csHeatID,_T("Tapping_Weight")).ToFloat();
	
	rsQaBloomFinjudgeData.SetFieldByName(_T("HeatID"),(CL3Variant)csHeatID);
	rsQaBloomFinjudgeData.SetFieldByName(_T("Cal_Weight"),(CL3Variant)fBofSteelWeight);
	rsQaBloomFinjudgeData.SetFieldByName(_T("Cal_Weight"),(CL3Variant)fBofSteelWeight);
	rsQaBloomFinjudgeData.SetFieldByName(_T("FinalJudge_Time"),(CL3Variant)COleDateTime::GetCurrentTime());
	if(nJudgeFlag==0)
	{
		rsQaBloomFinjudgeData.SetFieldByName(_T("Right_Weight"),(CL3Variant)fBofSteelWeight);
		rsQaBloomFinjudgeData.SetFieldByName(_T("Wrong_Weight"),(CL3Variant)0);
	}
	else
	{
		rsQaBloomFinjudgeData.SetFieldByName(_T("Right_Weight"),(CL3Variant)0);
		rsQaBloomFinjudgeData.SetFieldByName(_T("Wrong_Weight"),(CL3Variant)fBofSteelWeight);
	}

	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	rsQaBloomFinjudgeData.SetFieldByName(_T("Team"),(CL3Variant)rpSysInfo.GetFieldByName(_T("TeamID")));
	rsQaBloomFinjudgeData.SetFieldByName(_T("Shift"),(CL3Variant)rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsQaBloomFinjudgeData.SetFieldByName(_T("Operator"),(CL3Variant)CL3Variant(GetCurrentUser()));
	rsQaBloomFinjudgeData.SetFieldByName(_T("CasterID"),(CL3Variant)_T("S66"));
	
	//����ˮ������Ϣ�����������������ж�����
	if(CreateNewObjects(QA_FIN_JUDGE_CLASS_URI,rsQaBloomFinjudgeData)<1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	//�޸�

	csSQL.Format(_T("select * from %s where HeatID = '%s' and FinalJudgeFlag = 1"),
		         QA_LAB_ELEMENT_CLASS_URI,csHeatID);
	CL3RecordSetWrap rsFinalElement;
	if (!Query(csSQL, rsFinalElement) || rsFinalElement.IsNull())	
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -1; 
	}
	L3LONG rsCount = rsFinalElement.GetRowCount();
	if (rsCount > 0)
	{
		rsFinalElement.MoveFirst();
		while(!rsFinalElement.IsEOF())
		{
			CString cstrAppID = (rsFinalElement.GetFieldByName(_T("AppID"))).ToCString();
	       if (!SetObjectPropValue(QA_LAB_ELEMENT_CLASS_URI+_T("\\")+cstrAppID,_T("FinalJudgeFlag"),CL3Variant((L3LONG)0)))
		   {
				if (bUseTrans)
					Rollback(nTrans);
				return -1; 
		   }
			rsFinalElement.MoveNext();
		}
	}
	
	if (!SetObjectPropValue(QA_LAB_ELEMENT_CLASS_URI+_T("\\")+csAppID,_T("FinalJudgeFlag"),CL3Variant((L3LONG)1)))
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -1; 
	}

	//������������Ϣ����д��¯����Ϣ����Ҫ��Ϊ�˱�֤�ϴ�NC�ӿڲ���
	CL3RecordSetWrap rsCCMBaseData;
	CreateClassPropSet(CCM_BASE_DATA_CLASS_URI,rsCCMBaseData);
	rsCCMBaseData.AppendRecord();

	rsCCMBaseData.SetFieldByName(_T("HeatID"),(CL3Variant)csHeatID);
	rsCCMBaseData.SetFieldByName(_T("TreatNo"),(CL3Variant)csHeatID);
	rsCCMBaseData.SetFieldByName(_T("CCMID"),(CL3Variant)_T("S66"));
	rsCCMBaseData.SetFieldByName(_T("HeatConfirm"),CL3Variant((LONG)1));
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	rsCCMBaseData.SetFieldByName(_T("NC_Confirm_Flag"),(CL3Variant)((LONG)0));
	rsCCMBaseData.SetFieldByName(_T("Production_Date"),(CL3Variant)((L3DATETIME)curTime));

	
	//����ˮ��������д��������������
	if(CreateNewObjects(CCM_BASE_DATA_CLASS_URI,rsCCMBaseData)<1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	if (bUseTrans)
		Commit(nTrans);

	//Modify begin by llj 2011-03-23 ��Ը�ˮֱ�Ͳ���ֵķ���NC�¼�
	//�ı�����ֵ��֪ͨͨѶ��NC��������Ͷ�ϡ������깤��������Ϣ
	CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
	CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"),nEvent);
	//Modify end

	return 0;
}

/// <Method class="CQA_HeatGradeAssume_Mag" name="GetBofSteelJudgeHeat" type="L3RECORDSET">
///	��ȡת¯��ˮֱ�Ͳ����δ�жϵ�¯����Ϣ
/// </Method>
L3RECORDSET CQA_HeatGradeAssume_Mag::GetBofSteelJudgeHeat()
{
	// TODO : ���ڴ�����߼�����
	//��ȡ��ת¯��ˮֱ�Ͳ����,����ת¯ʵ���Ѿ�ȷ�ϣ���������δ���е�¯��
	CString csSql;
	csSql.Format(_T("select a.HeatID from %s a,%s b where a.HeatID=b.HeatID and b.CasterID='S66' and a.Locked=1 and not exists (select 1 from %s c where  a.HeatID=c.heatid and FINALJUDGEFLAG=1)"),
		BOF_BASE_DATA_CLASS_URI,PLAN_TAPPING_CLASS_URI,QA_LAB_ELEMENT_CLASS_URI);
	CL3RecordSetWrap rsHeatID;
	if(!Query(csSql,rsHeatID)||rsHeatID.IsNull()||rsHeatID.GetRowCount()<1)
		return NULL;

	//modif by hyh 2012-04-11

	////�������ؼ�¼��Ϣ
	//CStringArray FieldNames; FieldNames.SetSize(1);
	//CUIntArray FieldTypes; FieldTypes.SetSize(1);
	//FieldNames[0] = _T("HeatID");
	//FieldTypes[0] = L3VT_STRING;
	//CL3RecordSetWrap rs;
	//if (!CreateRecordSet(FieldNames,FieldTypes,rs)|| rs.IsNull())
	//{
	//	return NULL; //��������ʧ��
	//}

	//�齨�������ݼ�
	CL3RecordSet *pRSRtnMain = new CL3RecordSet();
	CL3RecordSetWrap rs; pRSRtnMain->QueryInterface(IID_IL3RecordSet,rs); pRSRtnMain->Release();
	rs.AddField(_T("HeatID"),VT_BSTR);

	//end

	rsHeatID.MoveFirst();
	while(!rsHeatID.IsEOF())
	{
		rs.AppendRecord();
		rs.SetFieldByName(_T("HeatID"),(CL3Variant)rsHeatID.GetFieldByName(_T("HeatID")));

		rsHeatID.MoveNext();
	}
	int ro=rs.GetRowCount();
	return rs.Detach();
}

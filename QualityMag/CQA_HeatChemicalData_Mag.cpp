// �߼���CQA_HeatChemicalData_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CQA_HeatChemicalData_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CQA_HeatChemicalData_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CQA_HeatChemicalData_Mag.h"
#include "_CQA_Lab_Sheet_App.h"
#include "_CSteel_Data.h"

//������װ�ص�ϵͳ��ʱ��������
void CQA_HeatChemicalData_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CQA_HeatChemicalData_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetUnitMagURIBySampleAddr" type="CString">
/// ͨ��ȡ���ص��ȡ����̬�����������ù������������ԣ�
/// <Param name=strSampleAddr//ȡ���ص�</Param>
/// </Method>
CString CQA_HeatChemicalData_Mag::GetUnitMagURIBySampleAddr(LPCTSTR strSampleAddr)
{
	L3LONG nIndex=-1;
	for (int i=0;i<SAMPLE_ADDR_COUNT;i++)
	{
		if (strSampleAddr == SAMPLE_ADDR[i])
		{
			nIndex = i;
			break;
		}
	}

	if (nIndex != -1)
	{
		return UNIT_MAG_OBJECT[nIndex];
	}
	else
	{
		return _T("");
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetSysYear" type="CString">
/// ����ί�е������
/// <Param name=��</Param>
/// </Method>
CString CQA_HeatChemicalData_Mag::GetSysCurYear()
{
	COleDateTime dtCurrentTime;
	dtCurrentTime = COleDateTime::GetCurrentTime();
	CString cstrCurTime = dtCurrentTime.Format(_T("%Y"));
    CString cstrYear = cstrCurTime.Mid(2,2);
    return cstrYear;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalLabSheetAppID" type="CString">
/// ����ί�е������
/// <Param name="crSampleAddr" type="LPCTSTR">�����ص�</Param>
/// <Param name="csSampleType" type="LPCTSTR">�������</Param>
/// </Method>
CString CQA_HeatChemicalData_Mag::CalLabSheetAppID(LPCTSTR csSampleAddr,LPCTSTR csSampleType)
{
    CString cstrSampleAddr=csSampleAddr;
	CL3RecordSetWrap rs;
    //�������ص��ȡί�е�����������˳���
	CString csSQL;
	csSQL.Format(_T("select Max(AppID) AS AppID from %s where Sample_Address = '%s'"),QA_LAB_SHEET_APPID_CLASS_URI,cstrSampleAddr);
	if(!Query(csSQL,rs) ||  rs.GetRowCount() < 1)
		return _T("");
	rs.MoveFirst();
	CString cstempAppid;
	cstempAppid = rs.GetFieldByIndex(0).ToCString();
    //����ί�е�����������˳���
	CString csNextAppid;
	if (cstempAppid.GetLength() < 1)
		cstempAppid = _T("0");
	csNextAppid.Format(_T("%06d"),_ttoi(cstempAppid)+1);
    //����ί�е�����������˳���
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return _T("");
	}

	CL3Variant valRet = GetObjectPropValue(QA_LAB_SHEET_APPID_CLASS_URI+_T("\\")+cstrSampleAddr,_T("AppID"));
	if ((valRet.IsError()) && (GetL3LastError() == L3ERR_OBJECT_NOTEXIST))
	{
		if (!CreateNewObject(QA_LAB_SHEET_APPID_CLASS_URI,CL3Variant(cstrSampleAddr)))
		{
			if (bUseTrans)
				Rollback(nTrans);
			return _T(""); 
		}
	}
    if (!SetObjectPropValue(QA_LAB_SHEET_APPID_CLASS_URI+_T("\\")+cstrSampleAddr,
		                    _T("AppID"),CL3Variant(csNextAppid)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return _T("");
	}

	if(bUseTrans)
		Commit(nTrans);

	return cstrSampleAddr+GetSysCurYear()+csNextAppid;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronSampleCode" type="CString">
/// ������ˮ��������
/// <Param name="csSampleAddr" type="LPCTSTR"> ȡ���ص�
/// <Param name="csSampleType" type="LPCTSTR"> �������
/// <Param name="csTAPNo" type="LPCTSTR"> ���κ�
/// �������BFID��TAP_No��Sample_Type��Sample_Address</Param>
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalIronSampleCode(LPCTSTR csSampleAddr,
													 LPCTSTR csSampleType,
													 LPCTSTR csTAPNo)
{
    CString cstrSampleAddr = csSampleAddr;
    CString cstrSampleType = csSampleType;
    CString cstrTAPNo = csTAPNo;
	CString cstrBFID = cstrTAPNo.Left(1);

	CString cstrSampleNo= cstrTAPNo + cstrSampleAddr + cstrSampleType;
   /* if (cstrSampleNo.GetLength()!=13)
	{
       return _T("");
	}*/

	CL3RecordSetWrap rs;
    //��CQA_Lab_Sheet_App��ȡ��¯����������(ȥ��ȡ������)���ȡ�����������Ϊ��ȡ������Ϊ0
	CString csSQL;
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where substr(Sample_Code,1,13) = '%s'"),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleNo);
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = 0;
		if ((rs.GetFieldByIndex(0)).ToCString().GetLength() > 0)
			nSampleCount = rs.GetFieldByIndex(0).ToLong();
		cstrSampleCount.Format(_T("%02d"),++nSampleCount);
	}
	else
	{
		cstrSampleCount = _T("01");
	}

	return cstrSampleNo + cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalMixFurnaceSampleCode" type="CString">
/// �������¯��������
/// <Param name="csSampleAddr" type="LPCTSTR">ȡ���ص�(����¯)</Param>
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalMixFurnaceSampleCode(LPCTSTR csSampleAddr,LPCTSTR csSampleType)
{
    CString cstrSampleAddr = csSampleAddr;
    if (cstrSampleAddr.GetLength()!=2)
	{
       return _T("");
	}
    //��ȡϵͳ���(��λ)
    CString cstrYear = GetSysCurYear();

	//����
	COleDateTime dtcurDay =  COleDateTime::GetCurrentTime();
	CString cstrcurDay = dtcurDay.Format(_T("%Y%m%d"));

	CL3RecordSetWrap rs;
    //��CQA_Lab_Sheet_App��ȡ����¯�������ȡ�����������Ϊ�յ���ȡ������Ϊ0
	CString csSQL;
	//csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where Sample_Address = '%s' and Sample_Type= '%s' and to_char(Sample_Date,'yyyyMMdd')='%s' "),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleAddr,csSampleType,cstrcurDay);
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where Sample_Address = '%s' and to_char(Sample_Date,'yyyyMMdd')='%s' "),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleAddr,cstrcurDay);
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = rs.GetFieldByIndex(0).ToLong();
		cstrSampleCount.Format(_T("%02d"),++nSampleCount);
	}
	else
	{
		cstrSampleCount = _T("00");
	}

	return _T("H") + cstrcurDay.Right(6) + cstrSampleAddr.Mid(1,1)+cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronLadleSampleCode" type="CString">
/// �������¯����������
/// <Param name="csSampleAddr" type="LPCTSTR">ȡ���ص�(����¯)</Param>
/// <Param name="csSampleType" type="LPCTSTR">�������</Param>
/// <Param name="csIronLadleNo" type="LPCTSTR">����</Param>
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalIronLadleSampleCode(LPCTSTR csSampleAddr,LPCTSTR csSampleType,LPCTSTR csIronLadleNo)
{
	//[20090106Liao]
    CString cstrSampleAddr = csSampleAddr;
	CString cstrIronLadleID = csIronLadleNo;
	cstrIronLadleID = cstrIronLadleID.Right(2);

    if (cstrSampleAddr.GetLength()!=2)
	{
       return _T("");
	}
    //��ȡϵͳ���(��λ)
    CString cstrYear = GetSysCurYear();

	//����
	COleDateTime dtcurDay =  COleDateTime::GetCurrentTime();
	CString cstrcurDay = dtcurDay.Format(_T("%m%d%H%M"));
	cstrcurDay = cstrYear + cstrcurDay;

	CString cstrSampleNo=_T("B") + cstrcurDay + cstrIronLadleID ;

	CL3RecordSetWrap rs;
    //��CQA_Lab_Sheet_App��ȡ����¯�������ȡ�����������Ϊ�յ���ȡ������Ϊ0
	CString csSQL;
	
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where substr(Sample_Code,1,13) = '%s'"),
		QA_LAB_SHEET_APP_CLASS_URI,cstrSampleNo);
	
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = rs.GetFieldByIndex(0).ToLong();
		cstrSampleCount.Format(_T("%02d"),++nSampleCount);
	}
	else
	{
		cstrSampleCount = _T("01");
	}

    return _T("B")+ cstrcurDay + cstrIronLadleID +cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalBOFSampleCode" type="CString">
/// ����������������
/// <Param name="csSampleType" type="LPCTSTR">�������</Param>
/// <Param name="csSampleAddr" type="LPCTSTR">ȡ���ص�</Param>
/// <Param name="csHeatID" type="LPCTSTR">¯��</Param>
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalBOFSampleCode(LPCTSTR csSampleType,
                                                    LPCTSTR csSampleAddr,
													LPCTSTR csHeatID)
{
    CString cstrSample_Type = csSampleType;
    CString cstrSample_Address = csSampleAddr;
    CString cstrHeatID = csHeatID;
    if ((cstrSample_Type.GetLength()!=2)||(cstrSample_Address.GetLength()<1)||(cstrHeatID.GetLength()!=9))
	{
       return _T("");
	}
    //��ȡϵͳ���(��λ)
    CString cstrYear = GetSysCurYear();
	//��ȡ¯��--����¯�ŵ�2λ��ȡת¯¯��
    CString cstrBOFID = cstrHeatID.Mid(1,1);
	//����¯�ź�5λ��ȡ������
	CString cstrPartHeatID = cstrHeatID.Mid(4,5);
	
	//�����������ڶ�λ�ж��ǳ�Ʒ�����ǹ�����
    bool IsFinalSample = false;
	if ((cstrSample_Type.Right(1) == _T("P")) || (cstrSample_Type.Right(1) == _T("L"))) //����(cstrSample_Type.Right(1) == _T("L")�����а������Ʒ�� 2009-01-17
	{
		IsFinalSample = true;
	}

    CString cstrSampleCode;
    //������������=2+¯����+���+������+ȡ���ص�+�������+ȡ������
	//cstrSampleCode = _T("2")+cstrBOFID+GetSysCurYear()+cstrHeatID.Mid(4,5)+cstrSample_Address+cstrSample_Type;
	cstrSampleCode = csHeatID+cstrSample_Address+cstrSample_Type;//2009-01-07 yao

	CL3RecordSetWrap rs;
    //�������ص��ȡί�е�����������˳���
	CString csSQL;
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where substr(Sample_Code,1,13) = '%s' "),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleCode);
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = rs.GetFieldByIndex(0).ToLong();
		if (IsFinalSample)
		{
			if (nSampleCount == 99) //2009-03-21 �������������������
			{
				cstrSampleCount = _T("00");
			}
			else
			{
				cstrSampleCount = _T("99");
			}
		}
		else
		{
			cstrSampleCount.Format(_T("%02d"),++nSampleCount);
		}
	}
	else
	{
		cstrSampleCount = _T("00");
	}

    return cstrSampleCode + cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="LogLabSheet" type="L3LONG">
/// ���ɻ���ί�е���
/// <Param name="rsData" type="L3RECORDSET"></Param>
///�������ݼ����������Sample_Type��Sample_Address��HeatID�ֶ�
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::NewLabSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// ����ί�е�, ���뻯��ί�е����������ֶ�
	//rs.AddField(_T("AppID"),L3VT_STRING);
	//rs.AddField(_T("Sample_Code"),L3VT_STRING);
	//rs.AddField(_T("Sample_Count"),L3VT_STRING);
	//rs.AddField(_T("Sample_Date"),L3VT_DATETIME);
	// �����ֶ���Ϣ
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//ȡ������
		CString cstrSample_Type = rs.GetFieldByName(_T("Sample_Type")).ToCString();
		//ȡ���ص�
		CString cstrSample_Address = rs.GetFieldByName(_T("Sample_Address")).ToCString();
		//¯��
		CString cstrHeatID = rs.GetFieldByName(_T("HeatID")).ToCString();
        //ί�е����
        CString cstrAppID = CalLabSheetAppID(cstrSample_Address,cstrSample_Type);
		//��������
		CString cstrSampleCode;
	
		//[20090106Liao]
		if ((cstrSample_Type == QA_Sample_Type_TH) || (cstrSample_Type == QA_Sample_Type_TA)) // ����¯�� (������޻���¯ȫ����2009-04-11)
		{
			cstrSampleCode = CalMixFurnaceSampleCode(cstrSample_Address,cstrSample_Type);
		}
		else if ((cstrSample_Type == QA_Sample_Type_TC) && (cstrSample_Address == QA_Sample_Addr_TC)) //��ˮ�����
		{
			cstrSampleCode = CalIronSampleCode(cstrSample_Address,cstrSample_Type,cstrHeatID);//cstrHeatIDΪ���κ�
		}
			else if ((cstrSample_Type == _T("TP")) || (cstrSample_Type == _T("TI"))) //������ˮ����� 20160316
		{
			cstrSampleCode = CalIronSampleCode(cstrSample_Address,cstrSample_Type,cstrHeatID);//cstrHeatIDΪ���κ�
		}
		else if((cstrSample_Type == QA_Sample_Type_TC) && (cstrSample_Address == QA_Sample_Addr_TB))
		{
			cstrSampleCode = CalIronLadleSampleCode(cstrSample_Address,cstrSample_Type,cstrHeatID);//cstrHeatIDΪ����
		}
		else if(cstrSample_Type == QA_Sample_Type_ZG) //������ 2009-04-11
		{
			cstrSampleCode = CalIronSampleCode(cstrSample_Address,cstrSample_Type,cstrHeatID);//cstrHeatIDΪ����
		}
		else 
		{
			cstrSampleCode = CalBOFSampleCode(cstrSample_Type,cstrSample_Address,cstrHeatID);
			//����2009-01-09tangyi GetSteelGradeByHeatID��Ϊ�������ݼ�
			CL3RecordSetWrap rsSteelGrade;
			rsSteelGrade = GetSteelGradeByHeatID(cstrHeatID);
			rsSteelGrade.MoveFirst();
			rs.SetFieldByName(_T("SteelGrade"),rsSteelGrade.GetFieldByName(_T("SteelGrade")));  
			//Э��
			rs.SetFieldByName(_T("Treaty"),rsSteelGrade.GetFieldByName(_T("Protocol")));       
		}

		 //�����
		rs.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
		//��������
		rs.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
		//��������
		rs.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
		//��������
		rs.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));

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
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rs);
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

/// <Method class="CQA_HeatChemicalData_Mag" name="ModifyLabSheet" type="L3LONG">
/// �޸�ί�е�����
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::ModifyLabSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// ����´��컯��״̬���Ѿ��´��ģ�SendFlag��Ϊ1�������޸�
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		// �´��컯���ʶ
		L3LONG nStatus = rs.GetFieldByName(_T("SendFlag")).ToLong();
		if(nStatus != CQA_Lab_Sheet_App::NotSendLab)
		{	//ί�е��Ѵ���
			SetL3LastError(XGMES_ERR_SHEETSEND);
			return -1;
		}
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
	if(SetObjsPropValues(QA_LAB_SHEET_APP_CLASS_URI,rs))
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
	else
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="DeleteLabSheet" type="L3LONG">
/// ɾ��ί�е�����
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::DeleteLabSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// ����´��컯��״̬���Ѿ��´��ģ�SendFlag��Ϊ1�������޸�
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		// �´��컯���ʶ
		L3LONG nStatus = rs.GetFieldByName(_T("SendFlag")).ToLong();
		if(nStatus == CQA_Lab_Sheet_App::SendLab)
		{	//ί�е��Ѵ���
			SetL3LastError(XGMES_ERR_SHEETSEND);
			return -1;
		}
		L3LONG nBackFlag = rs.GetFieldByName(_T("Back_Flag")).ToLong();
		if ((nBackFlag != CQA_Lab_Sheet_App::IsBack) && (nStatus == CQA_Lab_Sheet_App::SendLab))
		{	//ί�е�δ����
			SetL3LastError(XGMES_ERR_SHEETUNBACK);
			return -1;
		}
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
	if (DeleteOldObjects(QA_LAB_SHEET_APP_CLASS_URI,rs)<rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	else
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
}



/// <Method class="CQA_HeatChemicalData_Mag" name="SendSheetDataToLab" type="L3LONG">
/// ί�е������´�������
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::SendSheetDataToLab(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// ���������Ч��
	if(rs.GetFieldIndex(_T("SendFlag")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
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
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("SendFlag"),CL3Variant((LONG)CQA_Lab_Sheet_App::SendLab));
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!SetObjsPropValues(QA_LAB_SHEET_APP_CLASS_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//2009-04-07 Begin
	rs.MoveFirst();
	if (!SendSheetDataToAnaL2(rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	//2009-04-07 Begin

	if(bUseTrans)
		Commit(nTrans);

	// ��컯�鷢������,�������������2009-01-03 tangyi
	//rs.MoveFirst();
	//SendSheetDataToAnaL2(rs);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSheetBack" type="L3LONG">
/// ���ռ컯��ί�е�����
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabSheetBack(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// ���������Ч��
	if(rs.GetFieldIndex(_T("AppID")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
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
	while(!rs.IsEOF())
	{
		//�������������ȡ���ص����ù���������UndoApplyIDֵ
		CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Code"))).ToCString();
		CString cstrUnitMagURI = GetUnitMagURIBySampleAddr(cstrSampleAddr.Mid(9,2));
		if (cstrUnitMagURI.GetLength() > 0)
		{
			if (!(SetObjectPropValue(cstrUnitMagURI,
				                     _T("UndoApplyID"),rs.GetFieldByName(_T("AppID")))))
			{
				if(bUseTrans)
			       Rollback(nTrans);
			}
		}

		rs.SetFieldByName(_T("Back_Flag"),CL3Variant((LONG)1));
		COleDateTime dtCurrentTime;
	    dtCurrentTime = COleDateTime::GetCurrentTime();
		rs.SetFieldByName(_T("Back_Date"),CL3Variant((L3DATETIME)dtCurrentTime));
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!SetObjsPropValues(QA_LAB_SHEET_APP_CLASS_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	else
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSteelElement" type="L3LONG">
/// ���ո����컯����(��������)
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabSteelElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// ׼����Ч�ɷ�����
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_ELEMENT_CLASS_URI,rsElement))
	{
		return -1;
	}

	rsElement.DelField(_T("FinalJudgeFlag")); //2009-04-28 tangyi��ֹ���ش�ʱ�ı�FinalJudgeFlag��־

	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		//ͨ�������ص��ȡ����λ����
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrSampleType = rsElement.GetFieldByName(_T("Sample_Type")).ToCString();//2009-03-21 ��ȡ����������ڸ���̼¯��������PLC
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		L3LONG nUnitID=0;
		try
		{
			nUnitID = _ttoi(cstrUnitID);
		}
		catch(...)
		{
		}

		if (cstrUnitType == _T("Z"))
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BOF));
			if ((cstrSampleType == _T("GT")) && (nUnitID == 4)) //2009-03-21 4#¯����̼¯��������PLC
			{
				L3FLOAT fC = rsElement.GetFieldByName(_T("C")).ToFloat();
				L3FLOAT fS = rsElement.GetFieldByName(_T("S")).ToFloat();
				L3FLOAT fP = rsElement.GetFieldByName(_T("P")).ToFloat();
				SendAnalysisDataToPLC(fC,fS,fP);
			}
		}
		else if (cstrUnitType == _T("F")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)LF));
		}
		else if (cstrUnitType == _T("R")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)RH));
		}
		else if (cstrUnitType == _T("C")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)CCM));
		}
		else if (cstrUnitType == _T("A")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)11));
		}
		rsElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)nUnitID));
        rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_ELEMENT_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_ELEMENT_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
    
	//// ׼���ɷ��ж�����
	//CL3RecordSetWrap rsJudge;
	//if(!CreateClassPropSet(QA_LAB_ELEMENT_CLASS_URI,rsJudge))
	//{
	//	if(bUseTrans)
	//		Rollback(nTrans);
	//	return -1;
	//}

	//rsElement.MoveFirst();
	//while(!rsElement.IsEOF())
	//{
 //       CString cstrSampleType = rsElement.GetFieldByName(_T("Sample_Type")).ToCString();
	//	if (cstrSampleType.Mid(0,1) == _T("G")) //�������гɷ��ж�
	//	{
	//		//����ί�е������ճɷֱ�ʶ���ø�ˮ�������ճɷֱ�ʶ����
	//		CString cstrHeatID = rsElement.GetFieldByName(_T("HeatID")).ToCString();
	//		CString cstrAppID = rsElement.GetFieldByName(_T("AppID")).ToCString();
	//		L3LONG nUnitTypeID = rsElement.GetFieldByName(_T("UnitTypeID")).ToLong();
	//		L3LONG nUnitID = rsElement.GetFieldByName(_T("UnitID")).ToLong();
	//		L3LONG nFinalChemicalFlag = (GetObjectPropValue(QA_LAB_SHEET_APP_CLASS_URI +_T("\\") + cstrAppID,_T("Fin_Prod_Flag"))).ToLong();
	//		if (nFinalChemicalFlag == 1)
	//		{
	//			if (!SetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID,
	//									_T("FinalChemiclaFlag"),CL3Variant((L3LONG)1)))
	//			{
	//				if(bUseTrans)
	//					Rollback(nTrans);
	//				return -1;
	//			}
	//		}
	//		//���óɷ��ж��㷨
	//		rsJudge.AppendRecord();
	//		rsJudge.CopyCurRowFrom(rsElement);

	//		L3STRING bstrHeatID = cstrHeatID.AllocSysString();
	//		L3LONG nProcessCount = GetReHeatCount(bstrHeatID,nUnitTypeID,nUnitID);
	//		if (nProcessCount >= 0)
	//		{
	//			CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssumeAlg_Mag\\QA_HeatGradeAssumeAlg_Mag"),
	//												   _T("EstimateHeatChemical"),
	//												   nUnitTypeID,
	//												   nUnitID,
	//												   bstrHeatID,
	//												   nProcessCount,
	//												   (L3RECORDSET)rsJudge);
	//			if(valRet.IsError())
	//			{
	//				L3SysFreeString(bstrHeatID);
	//				if(bUseTrans)
	//					Rollback(nTrans);
	//				return -1;
	//			}
	//		}
	//		L3SysFreeString(bstrHeatID);
	//	}
	//	rsElement.MoveNext();
	//}
	//if(bUseTrans)
	//	Commit(nTrans);
	return rsElement.GetRowCount();
}



/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSteelElementText" type="L3LONG">
/// ���ո����컯����(�ı�)
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabSteelElementText(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// ׼����Ч�ɷ�����
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_ELEMENT_TEXT_CLASS_URI,rsElement))
	{
		return -1;
	}

	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		//ͨ�������ص��ȡ����λ����
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		L3LONG nUnitID=0;
		try
		{
			nUnitID = _ttoi(cstrUnitID);
		}
		catch(...)
		{
		}

		if (cstrUnitType == _T("Z"))
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BOF));
		}
		else if (cstrUnitType == _T("F")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)LF));
		}
		else if (cstrUnitType == _T("R")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)RH));
		}
		else if (cstrUnitType == _T("C")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)CCM));
		}
			else if (cstrUnitType == _T("A")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)11));
		}
		rsElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)nUnitID));
        rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_ELEMENT_TEXT_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_ELEMENT_TEXT_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSPrintData" type="L3LONG">
/// ���յͱ���ʵ��
/// <Param name="rsData" type="L3RECORDSET"></Param>
///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptSPrintData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// ׼����Ч�ɷ�����
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_S_PRINT_CLASS_URI,rsElement))
		return -1;
	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_S_PRINT_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_S_PRINT_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSlagElement" type="L3LONG">
/// ���������컯����
/// <Param name="rsData" type="L3RECORDSET"></Param>
///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptSlagElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// ׼����Ч�ɷ�����
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_SLAGELE_CLASS_URI,rsElement))
		return -1;
	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_SLAGELE_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_SLAGELE_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
}


/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptErrorInfo" type="L3LONG">
/// ���ջ��鵥������Ϣ2009-01-03 tangyi
/// <Param name="rsData" type="L3RECORDSET"></Param>
///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptErrorInfo (L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csAppID =  rs.GetFieldByName(_T("AppID")).ToCString();
		CString csUri = QA_LAB_SHEET_APP_CLASS_URI+_T("\\") +csAppID;
		SetObjectPropValue(csUri,_T("Back_Flag"),L3LONG(1));
		SetObjectPropValue(csUri,_T("Back_Date"),COleDateTime::GetCurrentTime());
		rs.MoveNext();
	}

	return 0;
}


/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptReSampleInfor" type="L3LONG">
/// ��������ȡ��ָʾ2009-01-03 tangyi
/// <Param name="rsData" type="L3RECORDSET"></Param>
///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptReSampleInfor (L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csAppID =  rs.GetFieldByName(_T("AppID")).ToCString();
		CString csUri = QA_LAB_SHEET_APP_CLASS_URI+_T("\\") +csAppID;
		SetObjectPropValue(csUri,_T("ReSample_Flag"),L3LONG(1));
		SetObjectPropValue(csUri,_T("ReSample_Date"),COleDateTime::GetCurrentTime());
		rs.MoveNext();
	}

	return 0;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSlagElementText" type="L3LONG">
/// ���������컯����(�ı�)
/// <Param name="rsData" type="L3RECORDSET"></Param>
///�������ݼ����������ApplyID��Sample_Code��Arrive_Date��Report_Date�ֶ�
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptSlagElementText(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// ׼����Ч�ɷ�����
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_SLAGELE_TEXT_CLASS_URI,rsElement))
		return -1;
	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_SLAGELE_TEXT_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_SLAGELE_TEXT_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabIronElement" type="L3LONG">
/// ���������컯����
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabIronElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// ׼����Ч�ɷ�����
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element"),rsElement))
	{
		return -1;
	}

    //������׸�ˮ��
	CL3RecordSetWrap rsLabElement;
	if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element"),rsLabElement))
	{
		return -1;
	}
	rsLabElement.AppendRecord();
	rsLabElement.MoveFirst();


	rsElement.CopyFrom(rs);
	rsElement.MoveFirst();
	while(!rsElement.IsEOF())
	{
		CString cstrSampleNo = rsElement.GetFieldByName(_T("Sample_Code")).ToCString();
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		L3LONG nUnitID=0;
		try
		{
			nUnitID = _ttoi(cstrUnitID);
		}
		catch(...)
		{
		}

		if (cstrUnitType == _T("G")) //��¯������
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BF));//���ù�λ
			//�������Ρ��޺�
			rsElement.SetFieldByName(_T("TAP_No"),CL3Variant(cstrSampleNo.Mid(0,9)));
			rsElement.SetFieldByName(_T("TPC_No"),CL3Variant(cstrSampleNo.Mid(9,2)));//�޺ţ�����

		}
		else if (cstrUnitType == _T("H")) //����¯������
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)MIF));
		}


		/////���׸�ˮ�ɷ�
        if(cstrSampleAddr== _T("T2"))
		{
		 
			rsLabElement.CopyCurRowFrom(rsElement);
			rsLabElement.SetFieldByName(_T("HeatID"),CL3Variant(cstrSampleNo.Mid(0,9)));
			rsLabElement.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleNo.Mid(13,2)));
			rsLabElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
			rsLabElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)10));//���ù�λ
			rsLabElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)1));
		    rsLabElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));

				BOOL bUseTrans = !IsInTrans();

				LONG nTrans = 0;
				if(bUseTrans)
				{
					nTrans = BeginTrans();
					if(nTrans < 1)
						return -1;
				}
			   
				rsElement.MoveFirst();
				LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element"),rsLabElement);
				if(nRet < rsLabElement.GetRowCount())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -1;
				}

				if(bUseTrans)
					Commit(nTrans);
				rsLabElement.MoveFirst();

		}



		rsElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)nUnitID));

		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		rsElement.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
   
	rsElement.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element"),rsElement);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	rsElement.MoveFirst();
	while(!rsElement.IsEOF())
	{
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		if (cstrUnitType == _T("G")) //��¯������
		{
			CL3RecordSetWrap rsIron;
			if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element"),rsIron))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -1;
			}

			rsIron.AppendRecord();
			rsIron.CopyCurRowFrom(rsElement);
            AcceptBFIronElementData(rsIron);
		}
		else if (cstrUnitType == _T("H")) //����¯������
		{
			CString cstrSampleType = rsElement.GetFieldByName(_T("Sample_Type")).ToCString();
			//Modify begin by llj 2011-04-15 �޸��û���¯ȫ���������ܹ�����TI��MN�ɷ� ����ԭ���
			//if (cstrSampleType == _T("TH")) //������¯�������û���¯�ӹ��������³ɷ�ֵ
			if (cstrSampleType == _T("TH")||cstrSampleType == _T("TA")) //������¯�������û���¯�ӹ��������³ɷ�ֵ
			//Modify end
			{
				CString csMIFMagURI = _T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag\\S1")+cstrUnitID;
				//modify by hyh 2012-04-17
				CL3Variant valC = rsElement.GetFieldByName(_T("C"));
				if(!(valC.IsEmpty() || valC.IsError() || valC.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("C"),valC);
					SetObjectPropValue(csMIFMagURI,_T("C_Cal"),valC);
				}
				CL3Variant valSi = rsElement.GetFieldByName(_T("Si"));
				if(!(valSi.IsEmpty() || valSi.IsError() || valSi.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Si"),valSi);
					SetObjectPropValue(csMIFMagURI,_T("Si_Cal"),valSi);
				}
				CL3Variant valMn = rsElement.GetFieldByName(_T("Mn"));
				if(!(valMn.IsEmpty() || valMn.IsError() || valMn.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Mn"),valMn);
					SetObjectPropValue(csMIFMagURI,_T("Mn_Cal"),valMn);
				}
				CL3Variant valP = rsElement.GetFieldByName(_T("P"));
				if(!(valP.IsEmpty() || valP.IsError() || valP.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("P"),valP);
					SetObjectPropValue(csMIFMagURI,_T("P_Cal"),valP);
				}
				CL3Variant valS = rsElement.GetFieldByName(_T("S"));
				if(!(valS.IsEmpty() || valS.IsError() || valS.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("S"),valS);
					SetObjectPropValue(csMIFMagURI,_T("S_Cal"),valS);
				}
				CL3Variant valTi = rsElement.GetFieldByName(_T("Ti"));
				if(!(valTi.IsEmpty() || valTi.IsError() || valTi.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Ti"),valTi);
					SetObjectPropValue(csMIFMagURI,_T("Ti_Cal"),valTi);
				}

				//add by hyh 2012-04-02
				CL3Variant valSn = rsElement.GetFieldByName(_T("Sn"));
				if(!(valSn.IsEmpty() || valSn.IsError() || valSn.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Sn"),valSn);
					SetObjectPropValue(csMIFMagURI,_T("Sn_Cal"),valSn);
				}
				CL3Variant valSb = rsElement.GetFieldByName(_T("Sb"));
				if(!(valSb.IsEmpty() || valSb.IsError() || valSb.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Sb"),valSb);
					SetObjectPropValue(csMIFMagURI,_T("Sb_Cal"),valSb);
				}
				CL3Variant valAs = rsElement.GetFieldByName(_T("As"));
				if(!(valAs.IsEmpty() || valAs.IsError() || valAs.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("As"),valAs);
					SetObjectPropValue(csMIFMagURI,_T("As_Cal"),valAs);
				}
				CL3Variant valPb = rsElement.GetFieldByName(_T("Pb"));
				if(!(valPb.IsEmpty() || valPb.IsError() || valPb.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Pb"),valPb);
					SetObjectPropValue(csMIFMagURI,_T("Pb_Cal"),valPb);
				}
				//end

				//add by hyh 2012-08-09 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
				CL3Variant valNi = rsElement.GetFieldByName(_T("Ni"));
				if(!(valNi.IsEmpty() || valNi.IsError() || valNi.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Ni"),valNi);
					SetObjectPropValue(csMIFMagURI,_T("Ni_Cal"),valNi);
				}
				CL3Variant valMo = rsElement.GetFieldByName(_T("Mo"));
				if(!(valMo.IsEmpty() || valMo.IsError() || valMo.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Mo"),valMo);
					SetObjectPropValue(csMIFMagURI,_T("Mo_Cal"),valMo);
				}
				CL3Variant valCu = rsElement.GetFieldByName(_T("Cu"));
				if(!(valCu.IsEmpty() || valCu.IsError() || valCu.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Cu"),valCu);
					SetObjectPropValue(csMIFMagURI,_T("Cu_Cal"),valCu);
				}
				CL3Variant valCr = rsElement.GetFieldByName(_T("Cr"));
				if(!(valCr.IsEmpty() || valCr.IsError() || valCr.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Cr"),valCr);
					SetObjectPropValue(csMIFMagURI,_T("Cr_Cal"),valCr);
				}
				CL3Variant valB = rsElement.GetFieldByName(_T("B"));
				if(!(valB.IsEmpty() || valB.IsError() || valB.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("B"),valB);
					SetObjectPropValue(csMIFMagURI,_T("B_Cal"),valB);
				}
				CL3Variant valV = rsElement.GetFieldByName(_T("V"));
				if(!(valV.IsEmpty() || valV.IsError() || valV.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("V"),valV);
					SetObjectPropValue(csMIFMagURI,_T("V_Cal"),valV);
				}

				//add by hyh 2012-04-02
				CL3Variant valAl = rsElement.GetFieldByName(_T("Al"));
				if(!(valAl.IsEmpty() || valAl.IsError() || valAl.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Al"),valAl);
					SetObjectPropValue(csMIFMagURI,_T("Al_Cal"),valAl);
				}
				CL3Variant valNb = rsElement.GetFieldByName(_T("Nb"));
				if(!(valNb.IsEmpty() || valNb.IsError() || valNb.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Nb"),valNb);
					SetObjectPropValue(csMIFMagURI,_T("Nb_Cal"),valNb);
				}
				CL3Variant valZn = rsElement.GetFieldByName(_T("Zn"));
				if(!(valZn.IsEmpty() || valZn.IsError() || valZn.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Zn"),valZn);
					SetObjectPropValue(csMIFMagURI,_T("Zn_Cal"),valZn);
				}
				CL3Variant valW = rsElement.GetFieldByName(_T("W"));
				if(!(valW.IsEmpty() || valW.IsError() || valW.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("W"),valW);
					SetObjectPropValue(csMIFMagURI,_T("W_Cal"),valW);
				}
				//end ��Ԫ�غ�׺������ _ELE
			}
		}
		rsElement.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsElement.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabIronElement" type="L3LONG">
/// ���������컯����
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabIronElementText(L3RECORDSET rsData)
{
		CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// ׼����Ч�ɷ�����
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element_Text"),rsElement))
	{
		return -1;
	}


	CL3RecordSetWrap rsLabElement;
	if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element_Text"),rsLabElement))
	{
		return -1;
	}
	rsLabElement.AppendRecord();
	rsLabElement.MoveFirst();

	rsElement.CopyFrom(rs);
	rsElement.MoveFirst();
	while(!rsElement.IsEOF())
	{
		CString cstrSampleNo = rsElement.GetFieldByName(_T("Sample_Code")).ToCString();
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		L3LONG nUnitID=0;
		try
		{
			nUnitID = _ttoi(cstrUnitID);
		}
		catch(...)
		{
		}
		
		if(cstrSampleAddr== _T("T2"))
		{
		 
			rsLabElement.CopyCurRowFrom(rsElement);
			rsLabElement.SetFieldByName(_T("HeatID"),CL3Variant(cstrSampleNo.Mid(0,9)));
			rsLabElement.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleNo.Mid(13,2)));
			rsLabElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
			rsLabElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)10));//���ù�λ
			rsLabElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)1));
		    rsLabElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));

				BOOL bUseTrans = !IsInTrans();

				LONG nTrans = 0;
				if(bUseTrans)
				{
					nTrans = BeginTrans();
					if(nTrans < 1)
						return -1;
				}
			   
				rsElement.MoveFirst();
				LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element_Text"),rsLabElement);
				if(nRet < rsLabElement.GetRowCount())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -1;
				}

				if(bUseTrans)
					Commit(nTrans);
				rsLabElement.MoveFirst();

		}

		else
		{
			if ((cstrUnitType == _T("G")) || (cstrUnitType == _T("T"))) //��¯������

			   {
				rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BF));//���ù�λ
				//�������Ρ��޺�
				rsElement.SetFieldByName(_T("TAP_No"),CL3Variant(cstrSampleNo.Mid(2,7)));
				rsElement.SetFieldByName(_T("TPC_No"),CL3Variant(cstrSampleNo.Mid(8,2)));//�޺ţ�����

			   }

			else if (cstrUnitType == _T("H")) //����¯������

			  {
				rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)MIF));
			  }

		
		
		}

		//if ((cstrUnitType == _T("G")) || (cstrUnitType == _T("T"))) //��¯������
		//{
		//	rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BF));//���ù�λ
		//	//�������Ρ��޺�
		//	rsElement.SetFieldByName(_T("TAP_No"),CL3Variant(cstrSampleNo.Mid(2,7)));
		//	rsElement.SetFieldByName(_T("TPC_No"),CL3Variant(cstrSampleNo.Mid(8,2)));//�޺ţ�����

		//}
		//else if (cstrUnitType == _T("H")) //����¯������
		//{
		//	rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)MIF));
		//}
		rsElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)nUnitID));
		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		rsElement.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
   
	rsElement.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element_Text"),rsElement);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsElement.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptReSampleAdvice" type="L3LONG">
/// ���ռ컯������ȡ��֪ͨ 
/// <Param name="rsData" type="L3RECORDSET"></Param>
///�������ݼ����������AppID��ReSample_Reason�ֶ�
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptReSampleAdvice(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
    //�����¼��������ȡ������
	rs.AddField(_T("ReSample_Flag"),L3VT_LONG);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//������������й���������ع������ReSampleApplyID����ֵ
		CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Code"))).ToCString();
		CString cstrUnitMagURI = GetUnitMagURIBySampleAddr(cstrSampleAddr.Mid(9,2));
		if (cstrUnitMagURI.GetLength() > 0)
		{
			if (!(SetObjectPropValue(cstrUnitMagURI,
				                     _T("ReSampleApplyID"),
									 rs.GetFieldByName(_T("AppID")))))

			{
				if(bUseTrans)
			       Rollback(nTrans);
			}
		}
		//��������ȡ����ʶ��ֵ
		rs.SetFieldByName(_T("ReSample_Flag"),CL3Variant((L3LONG)1));
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(SetObjsPropValues(QA_LAB_SHEET_APP_CLASS_URI,rs))
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
	else
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="LabCutAdvice" type="L3LONG">
/// ��д����֪ͨ��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::LabCutAdvice(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	CString csSQL;
	CL3RecordSetWrap rsResult;
	rs.MoveFirst();
	while (!rs.IsEOF())
	{
		CString cstrHeatID = (rs.GetFieldByName(_T("HeatID"))).ToCString();
		//2009-01-03 tangyi
		csSQL.Format(_T("select a.SteelGradeIndex,b.SteelGrade,b.Protocol from CCCM_Base_Data a,CQA_SteelGradeIndex_R b where a.HeatID ='%s' and a.SteelGradeIndex = b.SteelGradeIndex"),cstrHeatID);
		if(!Query(csSQL,rsResult))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;
		}
		rsResult.MoveFirst();
		rs.CopyCurRowFrom(rsResult);
		rs.SetFieldByName(_T("Log_Time"),CL3Variant((L3DATETIME)(COleDateTime::GetCurrentTime())));
		rs.SetFieldByName(_T("Cut_Mark"),CL3Variant(_T("0")));
		rs.MoveNext();
	}

	rs.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Lab_Cut_Advice"),rs);//QA_LAB_CUT_ADVICE_CLASS_URI��Ҫ��ConstDeclare�ж���
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	/*rs.MoveFirst();*/
	
	//SetObjectPropValue(CCM1_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));
	//SetObjectPropValue(CCM2_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));
	//SetObjectPropValue(CCM3_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));
	//SetObjectPropValue(CCM4_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));
	//SetObjectPropValue(CCM5_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));

	if(bUseTrans)
		Commit(nTrans);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetHeatLabElement" type="L3RECORDSET">
/// ��ȡ¯�ι��̸���
/// <Param name="rsData" type="L3RECORDSET">ȥ��</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetHeatLabElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if (rs.GetRowCount() < 1)
		return NULL;

	rs.MoveFirst();
	CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Address"))).ToCString();
	CString cstrSampleType = (rs.GetFieldByName(_T("Sample_Type"))).ToCString();
	CString cstrSampleCount= (rs.GetFieldByName(_T("Sample_Count"))).ToCString();
	CString cstrHeatID = (rs.GetFieldByName(_T("HeatID"))).ToCString();

	CString strSQL;
	strSQL = _T("select * from CQA_Lab_Element ");
	CString strCondition = _T(" where ");
	LONG nParams = 0;
	VARIANT params[4];
	if (cstrSampleAddr.GetLength() > 0)
	{
		strCondition += _T("Sample_Address=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleAddr.AllocSysString();
		nParams ++;
	}
	if (cstrSampleType.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("Sample_Type=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleType.AllocSysString();
		nParams ++;
	}
	if (cstrSampleCount.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("Sample_Count=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleCount.AllocSysString();
		nParams ++;
	}
	if (cstrHeatID.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("HeatID=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrHeatID.AllocSysString();
		nParams ++;
	}

	if (nParams < 1) return NULL;

	strSQL = strSQL + strCondition;
	CL3RecordSetWrap rstemp;
	BOOL bRet = QueryWithParam(strSQL,params,nParams,rstemp);
	for(int i=0;i<nParams;i++)
	{
		::VariantClear(&params[i]);
	}
	if(bRet)
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LAB_ELEMENT_CLASS_URI,rsRet);
		rstemp.MoveFirst();
		rsRet.CopyFrom(rstemp);
		return rsRet.Detach();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetHeatSlagElement" type="L3RECORDSET">
/// ��ȡ¯��������Ϣ
/// <Param name="rsData" type="L3RECORDSET">ȥ��</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetHeatSlagElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if (rs.GetRowCount() < 1)
		return NULL;

	rs.MoveFirst();
	CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Address"))).ToCString();
	CString cstrSampleType = (rs.GetFieldByName(_T("Sample_Type"))).ToCString();
	CString cstrSampleCount= (rs.GetFieldByName(_T("Sample_Count"))).ToCString();
	CString cstrHeatID = (rs.GetFieldByName(_T("HeatID"))).ToCString();

	CString strSQL;
	strSQL = _T("select * from CQA_Lab_SlagEle ");
	CString strCondition = _T(" where ");
	LONG nParams = 0;
	VARIANT params[4];
	if (cstrSampleAddr.GetLength() > 0)
	{
		strCondition += _T("Sample_Address=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleAddr.AllocSysString();
		nParams ++;
	}
	if (cstrSampleType.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("Sample_Type=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleType.AllocSysString();
		nParams ++;
	}
	if (cstrSampleCount.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("Sample_Count=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleCount.AllocSysString();
		nParams ++;
	}
	if (cstrHeatID.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("HeatID=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrHeatID.AllocSysString();
		nParams ++;
	}

	if (nParams < 1) return NULL;

	strSQL = strSQL + strCondition;
	CL3RecordSetWrap rstemp;
	BOOL bRet = QueryWithParam(strSQL,params,nParams,rstemp);
	for(int i=0;i<nParams;i++)
	{
		::VariantClear(&params[i]);
	}
	if(bRet)
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LAB_SLAGELE_CLASS_URI,rsRet);
		rstemp.MoveFirst();
		rsRet.CopyFrom(rstemp);
		return rsRet.Detach();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetActualHeatChemicalData" type="L3RECORDSET">
/// ��ȡ¯�λ�ѧ�ɷ�ʵ������
/// <Param name="strHeatID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetActualHeatChemicalData(L3STRING strHeatID,
																L3LONG nUnitTypeID,
																L3LONG nUnitID)
{
	CString cstrHeatID = strHeatID;
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Lab_Element_Text where HeatID = '%s' and UnitTypeID=%d and UnitID=%d "),
		cstrHeatID,nUnitTypeID,nUnitID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element_Text"),rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetTechRequestByHeatID" type="CString">
/// ͨ��¯�Ż�ȡί�е��е�Э������
/// <Param name=strHeatID//¯��</Param>
/// </Method>
CString CQA_HeatChemicalData_Mag::GetTechRequestByHeatID(LPCTSTR strHeatID)
{
	CString crSQL,strSQL;
	crSQL = _T("select c.TECH_REQUEST ");
	crSQL +=_T("from CPlan_Tapping_Act a,CPlan_Casting b,CPlan_Order c ");
    crSQL +=_T("where a.HeatID = '%s' ");
    crSQL +=_T("and a.PREHEATID = b.PREHEATID(+) ");
    crSQL +=_T("and b.PLANID = c.PLANID(+) ");
	strSQL.Format(crSQL,strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return _T("");
	else
	{
		rs.MoveFirst();
		return (rs.GetFieldByName(_T("TECH_REQUEST"))).ToCString();
	}
}
/// <Method class="CQA_HeatChemicalData_Mag" name="GetSteelGradeByHeatID" type="CString">
/// ͨ��¯�Ż�ȡ�ĸ���
/// <Param name=strHeatID//¯��</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetSteelGradeByHeatID(LPCTSTR strHeatID)
{
	CString crSQL,strSQL;
	crSQL = _T("select b.SteelGrade,b.Protocol ");
	crSQL +=_T("from CPlan_Tapping a,CQA_SteelGradeIndex_R b ");
    crSQL +=_T("where a.HeatID = '%s' ");
    crSQL +=_T("and a.SteelGradeIndex = b.SteelGradeIndex(+) ");
	strSQL.Format(crSQL,strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	//else
	//{
	//	rs.MoveFirst();
	//	return (rs.GetFieldByName(_T("SteelGrade"))).ToCString();
	//}
	return rs.Detach();
}
/// <Method class="CQA_HeatChemicalData_Mag" name="GetLatelyNewHeatChemicalData" type="L3RECORDSET">
/// ��ȡ����˹�������¯�γɷ�����
/// <Param name=//</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetLatelyNewHeatChemicalData()
{
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Lab_Element where DataLogMode = 1 and Report_Date>? "));
	COleDateTime timeCur = COleDateTime::GetCurrentTime();
	COleDateTime timeOld = timeCur - COleDateTimeSpan(1,0,0,0);
	VARIANT params[1];
	params[0].vt = VT_DATE; params[0].date = (DATE)timeOld;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,1,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetApplyDataByApplyID" type="L3RECORDSET">
/// ����ί�е��Ż�ȡί�е�����
/// <Param name=strApplyID//</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetApplyDataByApplyID(L3STRING strApplyID)
{
	CString cstrApplyID=strApplyID;
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Lab_Sheet_App where AppID = '%s'"),cstrApplyID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetApplyDataByApplyID" type="L3RECORDSET">
/// ����ί�е��Ż�ȡί�е�����
/// <Param name=strApplyID//</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetApplyIDByHeatIDAndAddr(L3STRING strHeatID,L3STRING strAddr)
{
	CString cstrApplyID=strHeatID;
	CString cstrAddr = strAddr;
	CString strSQL;
	strSQL.Format(_T("select AppID from CQA_Lab_Sheet_App where HeatID = '%s' and Sample_Address = '%s'"),cstrApplyID,cstrAddr);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetCutAdviceData" type="L3RECORDSET">
/// ��ȡ�������֪ͨ����
/// <Param name=//</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetCutAdviceData()
{
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Lab_Cut_Advice where Log_Time >? "));
	COleDateTime timeCur = COleDateTime::GetCurrentTime();
	COleDateTime timeOld = timeCur - COleDateTimeSpan(1,0,0,0);
	VARIANT params[1];
	params[0].vt = VT_DATE; params[0].date = (DATE)timeOld;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,1,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetSteelGradeByHeatID" type="L3RECORDSET">
/// ����¯�Ż�ȡ����
/// <Param name=strHeatID//¯��</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetGradeByHeatID(L3STRING strHeatID)
{
	CString cstrHeatID = strHeatID;
	CString crSQL,strSQL;
	crSQL = _T("select b.SteelGrade ");
	crSQL +=_T("from CPlan_Tapping a,CQA_SteelGradeIndex_R b ");
    crSQL +=_T("where a.HeatID = '%s' ");
    crSQL +=_T("and a.SteelGradeIndex = b.SteelGradeIndex(+) ");
	strSQL.Format(crSQL,cstrHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="DeleteCutAdvice" type="L3LONG">
/// ɾ������֪ͨ
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::DeleteCutAdvice(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rs.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_Lab_Cut_Advice"),rs)<rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	else
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetFinalActualHeatChemicalByHeatID" type="L3LONG">
/// ����¯�Ż�ȡ����ʵ�ʳɷ�����
/// <Param name="strHeatID" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetFinalActualHeatChemicalByHeatID(L3STRING strHeatID)
{
	//��ȡ�յ��������(����ȡ�����ǻ�����)
	CString cstrHeatID = strHeatID;
	CString strSQL;
	strSQL.Format(_T("select AppID from CQA_Lab_Sheet_App where HeatID = '%s' and Fin_Prod_Flag=1 and ReSampled=0 and Back_Flag = 0 "),
		          cstrHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	L3LONG rsCount = rs.GetRowCount();
	if (rsCount < 1)
	{
		return NULL;
	}
	rs.MoveFirst();
	CString cstrAppID = (rs.GetFieldByName(_T("AppID"))).ToCString();
   //��������Ż�ȡ�ɷ�����
	strSQL.Format(_T("select * from CQA_Lab_Element where AppID = '%s'"),cstrAppID);
	CL3RecordSetWrap rstemp;
	if(!Query(strSQL,rstemp))
		return NULL;
	else
		return rstemp.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetFinalStandardHeatChemicalByHeatID" type="L3LONG">
/// ����¯�Ż�ȡ���ձ�׼�ɷ�����
/// <Param name="strHeatID" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetFinalStandardHeatChemicalByHeatID(L3STRING strHeatID)
{
	//��ȡ�յ��������(����ȡ�����ǻ�����)
	CString cstrHeatID = strHeatID;
	CString strSQL;
	strSQL.Format(_T("select Sample_Address from CQA_Lab_Sheet_App where HeatID = '%s' and Fin_Prod_Flag=1 and ReSampled=0 and Back_Flag = 0 "),
		          cstrHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	L3LONG rsCount = rs.GetRowCount();
	if (rsCount < 1)
	{
		return NULL;
	}
	rs.MoveFirst();
	CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Address"))).ToCString();
	CL3Variant valtemp = GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+cstrHeatID,_T("SteelGradeIndex"));
	CString cstrSteelGradeIndex = valtemp.ToCString();
   //����ȡ���ص��ȡ��׼�ɷ�
	CString cstrClassName;
	if (cstrSampleAddr.Left(1) == _T("Z"))
		cstrClassName = _T("CQA_BOF_Std_InCtr_Ele");
	else if (cstrSampleAddr.Left(1) == _T("F"))
		cstrClassName = _T("CQA_LF_Std_InCtr_Ele");
	else if (cstrSampleAddr.Left(1) == _T("R"))
		cstrClassName = _T("CQA_RH_Std_InCtr_Ele");
	else if (cstrSampleAddr.Left(1) == _T("L"))
		cstrClassName = _T("CQA_Caster_Std_InCtr_Ele");
	else
		return NULL;

	strSQL.Format(_T("select * from %s where SteelGradeIndex = %s"),cstrClassName,cstrSteelGradeIndex);
	CL3RecordSetWrap rstemp;
	if(!Query(strSQL,rstemp))
		return NULL;
	else
		return rstemp.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetReHeatCount" type="L3LONG">
/// ��ȡ�ش������
/// <Param name="strHeatID" type="L3STRING"></Param>
/// <Param name="nUnitType" type="L3LONG"></Param>
/// <Param name="nUnitID" type="L3LONG"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::GetReHeatCount(L3STRING strHeatID,L3LONG nUnitType,L3LONG nUnitID)
{
	if (strHeatID == NULL)
	{
		return -1;
	}
	CString cstrHeatID = strHeatID;
	CString strSQL;
	if (nUnitType = UNIT_AREA_BOF)
	{
		strSQL.Format(_T("select count(HeatID) as ProcessCount from CBOF_Base_Data where HeatID = '%s' and substr(HeatID,2,1)=%d"),
		              cstrHeatID,nUnitID);
	}
	else if (nUnitType = UNIT_AREA_LF)
	{
		strSQL.Format(_T("select count(HeatID) as ProcessCount from CLF_Base_Data where HeatID = '%s' and substr(TreatNo,2,1)=%d"),
		              cstrHeatID,nUnitID);
	}
	else if (nUnitType = UNIT_AREA_RH)
	{
		strSQL.Format(_T("select count(HeatID) as ProcessCount from CRH_Base_Data where HeatID = '%s' and substr(TreatNo,2,1)=%d"),
		              cstrHeatID,nUnitID);
	}
	else if (nUnitType = UNIT_AREA_CASTER)
	{
		strSQL.Format(_T("select count(HeatID) as ProcessCount from CCCM_Base_Data where HeatID = '%s' and substr(TreatNo,2,1)=%d"),
		              cstrHeatID,nUnitID);
	}
	else
	{
		return -2;
	}
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	L3LONG rsCount = rs.GetRowCount();
	if (rsCount < 1)
	{
		return -3;
	}
	rs.MoveFirst();
	return (rs.GetFieldByName(_T("ProcessCount"))).ToLong()-1;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="NewHeatExceptionData" type="L3LONG">
/// �����µ�¯�ι����쳣����
/// <Param name="strHeatID" type="L3STRING"></Param>
/// <Param name="nUnitType" type="L3LONG"></Param>
/// <Param name="nUnitID" type="L3LONG"></Param>
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::NewHeatExceptionData(L3STRING strHeatID,L3LONG nUnitType,L3LONG nUnitID,L3RECORDSET rsData)
{
	if ((strHeatID == NULL) || (rsData == NULL) || (rsData->GetRecordCount() < 1))
	{
		return -1;
	}

	//��ȡ�ش������
	L3SHORT nProcessCount = GetReHeatCount(strHeatID,nUnitType,nUnitID);
	  //���ü�¼¯�ι����쳣����
	//return LogHeatExceptionData(nUnitType,nUnitID,strHeatID,nProcessCount,rsData);	
	  //���ü�¼¯�ι����쳣����
	CL3Variant valReturn = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssume_Mag\\QA_HeatGradeAssume_Mag"),
											_T("LogHeatExceptionData"),
											(L3SHORT)nUnitType,
											(L3SHORT)nUnitID,
											strHeatID,
											(L3SHORT)nProcessCount,
											(L3RECORDSET)rsData);	
	if (valReturn.IsError())  
	{		
		return -2;
	}

	return 0;

}
L3LONG CQA_HeatChemicalData_Mag::LogHeatExceptionData(L3SHORT nUnitTypeID,
													 L3SHORT nUnitID, 
													 L3STRING strHeatID, 
													 L3SHORT nProcessCount, 
													 L3RECORDSET rsData)
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
	CString strPresetHeatID = (GetObjectPropValue(PLAN_TAPPING_CLASS_URI+_T("\\")+cstrHeatID,_T("PreHeatID"))).ToCString();
	CString strSteelGradeIndex = (GetObjectPropValue(PLAN_TAPPING_CLASS_URI+_T("\\")+cstrHeatID,_T("SteelGradeIndex"))).ToCString();
	CString strPreSteelGradeIndex = (GetObjectPropValue(PLAN_TAPPING_CLASS_URI+_T("\\")+cstrHeatID,_T("Pre_SteelGradeIndex"))).ToCString();

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
	return 0;	
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptBFIronElementData" type="L3LONG">
/// ���ո�¯��ˮ��ʵ��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptBFIronElementData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return -1;

	rs.MoveFirst();

	while(!rs.IsEOF())
	{
		CString cstrSample_Type = rs.GetFieldByName(_T("Sample_Type")).ToCString();
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString cstrTpcNo = rs.GetFieldByName(_T("TPC_No")).ToCString();

		if(cstrSample_Type == _T("TS")) //������
		{
			CString cstrID = cstrTapNo+cstrTpcNo;
			CString csUri = _T("MES\\MaterialData\\CBFIron\\")+cstrID;
			SetObjectPropValue(csUri,_T("Sample_Place"),_T("TS"));

			L3FLOAT fC = -1;
			CL3Variant valC = rs.GetFieldByName(_T("C"));
			if (!(valC.IsError() || valC.IsNull() || valC.IsEmpty()))
			{
				fC = valC.ToFloat();
				if (fC > 0.00001)
				{
					SetObjectPropValue(csUri,_T("C"),valC);
				}
			}
			L3FLOAT fSi = -1;
			CL3Variant valSi = rs.GetFieldByName(_T("Si"));
			if (!(valSi.IsError() || valSi.IsNull() || valSi.IsEmpty()))
			{
				fSi = valSi.ToFloat();
				if (fSi > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Si"),valSi);
				}
			}
			L3FLOAT fMn = -1;
			CL3Variant valMn = rs.GetFieldByName(_T("Mn"));
			if (!(valMn.IsError() || valMn.IsNull() || valMn.IsEmpty()))
			{
				fMn = valMn.ToFloat();
				if (fMn > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Mn"),valMn);
				}
			}
			L3FLOAT fP = -1;
			CL3Variant valP = rs.GetFieldByName(_T("P"));
			if (!(valP.IsError() || valP.IsNull() || valP.IsEmpty()))
			{
				fP = valP.ToFloat();
				if (fP > 0.00001)
				{
					SetObjectPropValue(csUri,_T("P"),valP);
				}
			}
			L3FLOAT fS = -1;
			CL3Variant valS = rs.GetFieldByName(_T("S"));
			if (!(valS.IsError() || valS.IsNull() || valS.IsEmpty()))
			{
				fS = valS.ToFloat();
				if (fS > 0.00001)
				{
					SetObjectPropValue(csUri,_T("S"),valS);
				}
			}
			L3FLOAT fTi = -1;
			CL3Variant valTi = rs.GetFieldByName(_T("Ti"));
			if (!(valTi.IsError() || valTi.IsNull() || valTi.IsEmpty()))
			{
				fTi = valTi.ToFloat();
				if (fTi > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Ti"),valTi);
				}
			}

			//add by hyh 2012-04-04
			//Sn
			L3FLOAT fSn = -1;
			CL3Variant valSn = rs.GetFieldByName(_T("Sn"));
			if (!(valSn.IsError() || valSn.IsNull() || valSn.IsEmpty()))
			{
				fSn = valSn.ToFloat();
				if (fSn > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Sn"),valSn);
				}
			}
			//Sb
			L3FLOAT fSb = -1;
			CL3Variant valSb = rs.GetFieldByName(_T("Sb"));
			if (!(valSb.IsError() || valSb.IsNull() || valSb.IsEmpty()))
			{
				fSb = valSb.ToFloat();
				if (fSb > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Sb"),valSb);
				}
			}
			//As
			L3FLOAT fAs = -1;
			CL3Variant valAs = rs.GetFieldByName(_T("As"));
			if (!(valAs.IsError() || valAs.IsNull() || valAs.IsEmpty()))
			{
				fAs = valAs.ToFloat();
				if (fAs > 0.00001)
				{
					SetObjectPropValue(csUri,_T("As"),valAs);
				}
			}
			//Pb
			L3FLOAT fPb = -1;
			CL3Variant valPb = rs.GetFieldByName(_T("Pb"));
			if (!(valPb.IsError() || valPb.IsNull() || valPb.IsEmpty()))
			{
				fPb = valPb.ToFloat();
				if (fPb > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Pb"),valPb);
				}
			}
			//end

			//add by hyh 2012-08-13 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
			L3FLOAT fNi = -1;
			CL3Variant valNi = rs.GetFieldByName(_T("Ni"));
			if (!(valNi.IsError() || valNi.IsNull() || valNi.IsEmpty()))
			{
				fNi = valNi.ToFloat();
				if (fNi > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Ni"),valNi);
				}
			}
			L3FLOAT fMo = -1;
			CL3Variant valMo = rs.GetFieldByName(_T("Mo"));
			if (!(valMo.IsError() || valMo.IsNull() || valMo.IsEmpty()))
			{
				fMo = valMo.ToFloat();
				if (fMo > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Mo"),valMo);
				}
			}
			L3FLOAT fCu = -1;
			CL3Variant valCu = rs.GetFieldByName(_T("Cu"));
			if (!(valCu.IsError() || valCu.IsNull() || valCu.IsEmpty()))
			{
				fCu = valCu.ToFloat();
				if (fCu > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Cu"),valCu);
				}
			}
			L3FLOAT fCr = -1;
			CL3Variant valCr = rs.GetFieldByName(_T("Cr"));
			if (!(valCr.IsError() || valCr.IsNull() || valCr.IsEmpty()))
			{
				fCr = valCr.ToFloat();
				if (fCr > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Cr"),valCr);
				}
			}
			L3FLOAT fB = -1;
			CL3Variant valB = rs.GetFieldByName(_T("B"));
			if (!(valB.IsError() || valB.IsNull() || valB.IsEmpty()))
			{
				fB = valB.ToFloat();
				if (fB > 0.00001)
				{
					SetObjectPropValue(csUri,_T("B"),valB);
				}
			}
			L3FLOAT fV = -1;
			CL3Variant valV = rs.GetFieldByName(_T("V"));
			if (!(valV.IsError() || valV.IsNull() || valV.IsEmpty()))
			{
				fV = valV.ToFloat();
				if (fV > 0.00001)
				{
					SetObjectPropValue(csUri,_T("V"),valV);
				}
			}

			L3FLOAT fAl = -1;
			CL3Variant valAl = rs.GetFieldByName(_T("Al"));
			if (!(valAl.IsError() || valAl.IsNull() || valAl.IsEmpty()))
			{
				fAl = valAl.ToFloat();
				if (fAl > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Al"),valAl);
				}
			}

			L3FLOAT fNb = -1;
			CL3Variant valNb = rs.GetFieldByName(_T("Nb"));
			if (!(valNb.IsError() || valNb.IsNull() || valNb.IsEmpty()))
			{
				fNb = valNb.ToFloat();
				if (fNb > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Nb"),valNb);
				}
			}

			L3FLOAT fZn = -1;
			CL3Variant valZn = rs.GetFieldByName(_T("Zn"));
			if (!(valZn.IsError() || valZn.IsNull() || valZn.IsEmpty()))
			{
				fZn = valZn.ToFloat();
				if (fZn > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Zn"),valZn);
				}
			}
			
			L3FLOAT fW = -1;
			CL3Variant valW = rs.GetFieldByName(_T("W"));
			if (!(valW.IsError() || valW.IsNull() || valW.IsEmpty()))
			{
				fW = valW.ToFloat();
				if (fW > 0.00001)
				{
					SetObjectPropValue(csUri,_T("W"),valW);
				}
			}
			//end
			

			L3STRING bstrID = cstrID.AllocSysString();
			InvokeObjectMethod(_T("XGMESLogic\\BFMag\\CBF_Iron_Mag\\BFIronMag"),_T("Complete"),bstrID);
			L3SysFreeString(bstrID);

			/***2009-10-25 Begin yao***/
			CString csSampleCode = rs.GetFieldByName(_T("Sample_Code")).ToCString();
			if(csSampleCode.GetLength() == 15)
			{
    			SetDeSAnalysisData(csSampleCode,fS,fP);
			}
			/***2009-10-25 End***/

		}
		else //������
		{
			//�������κ����ø�¯��ˮ�ɷ�����
			CString strSQL;
			strSQL.Format(_T("select * from CBFIron where TAP_No ='%s' order by TAP_No"),
						  cstrTapNo);
			CL3RecordSetWrap rsIron;
			if(!Query(strSQL,rsIron))
				return -3;
			L3LONG rsCount = rsIron.GetRowCount();
			if (rsCount > 0)
			{
				rsIron.MoveFirst();

				CString csTapNo = rsIron.GetFieldByName(_T("TAP_No")).ToCString();

				//�齨��¯��ˮ�ɷݼ�¼��
				CL3RecordSet *pRSBF = new CL3RecordSet();
				CL3RecordSetWrap rsBFChemical; pRSBF->QueryInterface(IID_IL3RecordSet,rsBFChemical); pRSBF->Release();
				rsBFChemical.AddField(_T("MaterialID"),VT_BSTR);
				rsBFChemical.AddField(_T("C"),VT_BSTR);
				rsBFChemical.AddField(_T("Si"),VT_BSTR);
				rsBFChemical.AddField(_T("Mn"),VT_BSTR);
				rsBFChemical.AddField(_T("P"),VT_BSTR);
				rsBFChemical.AddField(_T("S"),VT_BSTR);
				rsBFChemical.AddField(_T("Ti"),VT_BSTR);

				//add by hyh 2012-04-04
				rsBFChemical.AddField(_T("Sn"),VT_BSTR);
				rsBFChemical.AddField(_T("Sb"),VT_BSTR);
				rsBFChemical.AddField(_T("As"),VT_BSTR);
				rsBFChemical.AddField(_T("Pb"),VT_BSTR);
				//end

				//add by hyh 2012-08-13  Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
				rsBFChemical.AddField(_T("Ni"),VT_BSTR);
				rsBFChemical.AddField(_T("Mo"),VT_BSTR);
				rsBFChemical.AddField(_T("Cu"),VT_BSTR);
				rsBFChemical.AddField(_T("Cr"),VT_BSTR);
				rsBFChemical.AddField(_T("B"),VT_BSTR);
				rsBFChemical.AddField(_T("V"),VT_BSTR);
				rsBFChemical.AddField(_T("Al"),VT_BSTR);
				rsBFChemical.AddField(_T("Nb"),VT_BSTR);
				rsBFChemical.AddField(_T("Zn"),VT_BSTR);
				rsBFChemical.AddField(_T("W"),VT_BSTR);
				//end

				rsBFChemical.AddField(_T("C_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Si_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Mn_B"),VT_BSTR);
				rsBFChemical.AddField(_T("P_B"),VT_BSTR);
				rsBFChemical.AddField(_T("S_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Ti_B"),VT_BSTR);
				//add by hyh 2012-04-04
				rsBFChemical.AddField(_T("Sn_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Sb_B"),VT_BSTR);
				rsBFChemical.AddField(_T("As_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Pb_B"),VT_BSTR);
				//end

				//add by hyh 2012-08-13  Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
				rsBFChemical.AddField(_T("Ni_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Mo_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Cu_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Cr_B"),VT_BSTR);
				rsBFChemical.AddField(_T("B_B"),VT_BSTR);
				rsBFChemical.AddField(_T("V_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Al_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Nb_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Zn_B"),VT_BSTR);
				rsBFChemical.AddField(_T("W_B"),VT_BSTR);
				//end
				rsBFChemical.AddField(_T("AnalysisFlag"),VT_I4);
				rsBFChemical.AddField(_T("SampCode"),VT_BSTR);
				rsBFChemical.AddField(_T("Sample_Place"),VT_BSTR);
				rsBFChemical.AddField(_T("Operator_B"),VT_BSTR);//2009-04-23

				while(!rsIron.IsEOF())
				{
					rsBFChemical.AppendRecord();
					rsBFChemical.MoveLast();
					CString cstrTpcNo = rsIron.GetFieldByName(_T("TPC_No")).ToCString();
					CString cstrID = cstrTapNo+cstrTpcNo;
					rsBFChemical.SetFieldByName(_T("MaterialID"),CL3Variant(cstrID));
					rsBFChemical.SetFieldByName(_T("C"),rs.GetFieldByName(_T("C")));
					rsBFChemical.SetFieldByName(_T("Si"),rs.GetFieldByName(_T("Si")));
					rsBFChemical.SetFieldByName(_T("Mn"),rs.GetFieldByName(_T("MN")));
					rsBFChemical.SetFieldByName(_T("P"),rs.GetFieldByName(_T("P")));
					rsBFChemical.SetFieldByName(_T("S"),rs.GetFieldByName(_T("S")));
					rsBFChemical.SetFieldByName(_T("Ti"),rs.GetFieldByName(_T("TI")));

					//add by hyh 2012-04-04
					rsBFChemical.SetFieldByName(_T("Sn"),rs.GetFieldByName(_T("SN")));
					rsBFChemical.SetFieldByName(_T("Sb"),rs.GetFieldByName(_T("SB")));
					rsBFChemical.SetFieldByName(_T("As"),rs.GetFieldByName(_T("AS")));
					rsBFChemical.SetFieldByName(_T("Pb"),rs.GetFieldByName(_T("PB")));
					//end

					//add by hyh 2012-08-13  Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
					rsBFChemical.SetFieldByName(_T("Ni"),rs.GetFieldByName(_T("Ni")));
					rsBFChemical.SetFieldByName(_T("Mo"),rs.GetFieldByName(_T("Mo")));
					rsBFChemical.SetFieldByName(_T("Cu"),rs.GetFieldByName(_T("Cu")));
					rsBFChemical.SetFieldByName(_T("Cr"),rs.GetFieldByName(_T("Cr")));
					rsBFChemical.SetFieldByName(_T("B"),rs.GetFieldByName(_T("B")));
					rsBFChemical.SetFieldByName(_T("V"),rs.GetFieldByName(_T("V")));
					rsBFChemical.SetFieldByName(_T("Al"),rs.GetFieldByName(_T("Al")));
					rsBFChemical.SetFieldByName(_T("Nb"),rs.GetFieldByName(_T("Nb")));
					rsBFChemical.SetFieldByName(_T("Zn"),rs.GetFieldByName(_T("Zn")));
					rsBFChemical.SetFieldByName(_T("W"),rs.GetFieldByName(_T("W")));
					//end

					rsBFChemical.SetFieldByName(_T("C_B"),rs.GetFieldByName(_T("C")));
					rsBFChemical.SetFieldByName(_T("Si_B"),rs.GetFieldByName(_T("SI")));
					rsBFChemical.SetFieldByName(_T("Mn_B"),rs.GetFieldByName(_T("MN")));
					rsBFChemical.SetFieldByName(_T("P_B"),rs.GetFieldByName(_T("P")));
					rsBFChemical.SetFieldByName(_T("S_B"),rs.GetFieldByName(_T("S")));
					rsBFChemical.SetFieldByName(_T("Ti_B"),rs.GetFieldByName(_T("TI")));

					//add by hyh 2012-04-04
					rsBFChemical.SetFieldByName(_T("Sn_B"),rs.GetFieldByName(_T("SN")));
					rsBFChemical.SetFieldByName(_T("Sb_B"),rs.GetFieldByName(_T("SB")));
					rsBFChemical.SetFieldByName(_T("As_B"),rs.GetFieldByName(_T("AS")));
					rsBFChemical.SetFieldByName(_T("Pb_B"),rs.GetFieldByName(_T("PB")));
					//end

					//add by hyh 2012-08-13  Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
					rsBFChemical.SetFieldByName(_T("Ni_B"),rs.GetFieldByName(_T("Ni")));
					rsBFChemical.SetFieldByName(_T("Mo_B"),rs.GetFieldByName(_T("Mo")));
					rsBFChemical.SetFieldByName(_T("Cu_B"),rs.GetFieldByName(_T("Cu")));
					rsBFChemical.SetFieldByName(_T("Cr_B"),rs.GetFieldByName(_T("Cr")));
					rsBFChemical.SetFieldByName(_T("B_B"),rs.GetFieldByName(_T("B")));
					rsBFChemical.SetFieldByName(_T("V_B"),rs.GetFieldByName(_T("V")));
					rsBFChemical.SetFieldByName(_T("Al_B"),rs.GetFieldByName(_T("Al")));
					rsBFChemical.SetFieldByName(_T("Nb_B"),rs.GetFieldByName(_T("Nb")));
					rsBFChemical.SetFieldByName(_T("Zn_B"),rs.GetFieldByName(_T("Zn")));
					rsBFChemical.SetFieldByName(_T("W_B"),rs.GetFieldByName(_T("W")));
					//end

					rsBFChemical.SetFieldByName(_T("Sample_Place"),CL3Variant(_T("0")));
					rsBFChemical.SetFieldByName(_T("AnalysisFlag"),CL3Variant((L3LONG)1));
					rsBFChemical.SetFieldByName(_T("SampCode"),rs.GetFieldByName(_T("Sample_Code")));
					rsBFChemical.SetFieldByName(_T("Sample_Place"),CL3Variant(_T("BF")));
					rsBFChemical.SetFieldByName(_T("Operator_B"),rs.GetFieldByName(_T("Operator")));//2009-04-23

					L3STRING bstrID = cstrID.AllocSysString();
					InvokeObjectMethod(_T("XGMESLogic\\BFMag\\CBF_Iron_Mag\\BFIronMag"),_T("Complete"),bstrID);
					L3SysFreeString(bstrID);

					rsIron.MoveNext();
				}

				SetObjsPropValues(_T("MES\\MaterialData\\CBFIron"),rsBFChemical);
			}
		}
		rs.MoveNext();
	}

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GenLabSheet" type="L3LONG">
/// ���ɻ���ί�е���
/// <Param name="strSampleType" type="L3STRING">�������</Param>
/// <Param name="strAddr" type="L3STRING">ȡ���ص�</Param>
/// <Param name="strHeatID" type="L3STRING">¯��</Param>
/// <Param name="nFinalFlag" type="L3STRING">��Ʒ����־</Param>
/// </Method>
L3RECORDSET  CQA_HeatChemicalData_Mag::GenLabSheet(L3STRING strSampleType,L3STRING strAddr,L3STRING strHeatID,L3LONG nFinalFlag)
{
	if ((strSampleType==NULL) || (strAddr==NULL) || (strHeatID == NULL))
	{
		return NULL;
	}

	CString csSampleType = strSampleType;
	CString csAddr = strAddr;
	CString csHeatID = strHeatID;

    CString cstrAppID = CalLabSheetAppID(csAddr,strSampleType);

	//��������
	CString cstrSampleCode;
	cstrSampleCode = CalBOFSampleCode(csSampleType,csAddr,csHeatID);

	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rs))
		return NULL;

	rs.AppendRecord();

	 //�����
	rs.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
	//��������
	rs.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
	//��������
	rs.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
	//��������
	rs.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
	rs.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rs.SetFieldByName(_T("Sample_Address"),CL3Variant(csAddr));
	rs.SetFieldByName(_T("Sample_Type"),CL3Variant(csSampleType));
	rs.SetFieldByName(_T("Fin_Prod_Flag"),(L3LONG)nFinalFlag);

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return NULL;
	}

	rs.MoveFirst();
    int ntemp = rs.GetRowCount();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rs);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return NULL;
	}

	if(bUseTrans)
		Commit(nTrans);

	return rs.Detach();
}


//һ����ˮ����ί�е�
L3LONG  CQA_HeatChemicalData_Mag::GenLabSheetNew(L3STRING strSampleType,L3STRING strAddr,L3STRING strHeatID,L3STRING strSteelGradeIndex,L3LONG nFinalFlag)
{
	if ((strSampleType==NULL) || (strAddr==NULL) || (strHeatID == NULL)||(strSteelGradeIndex == NULL))
	{
		return -1;
	}

	CString csSampleType = strSampleType;
	CString csAddr = strAddr;
	CString csHeatID = strHeatID;
    //���������������һ��
   /* CString cstrAppID = CalLabSheetAppID(csAddr,strSampleType);*/
	 CString cstrAppID =CalBOFSampleCode(csSampleType,csAddr,csHeatID);
	//��������
	CString cstrSampleCode;
	cstrSampleCode = cstrAppID;

	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rs))
		return -2;

	rs.AppendRecord();

	 //�����
	rs.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
	//��������
	rs.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
	//��������
	rs.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
	//��������
	rs.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
	rs.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rs.SetFieldByName(_T("Sample_Address"),CL3Variant(csAddr));
	rs.SetFieldByName(_T("Sample_Type"),CL3Variant(csSampleType));
	rs.SetFieldByName(_T("Fin_Prod_Flag"),(L3LONG)nFinalFlag);

 

	CL3RecordSetWrap rsGrade;
    //��ȡ���� Э���
	CString csSQL;
	csSQL.Format(_T("select STEELGRADE,PROTOCOL from CQA_STEELGRADEINDEX_R where STEELGRADEINDEX = '%s' "),strSteelGradeIndex);
	if(!Query(csSQL,rsGrade))
		return -3;
	rsGrade.MoveFirst();

	rs.SetFieldByName(_T("SteelGrade"),CL3Variant(rsGrade.GetFieldByIndex(0).ToString()));
	rs.SetFieldByName(_T("Treaty"),CL3Variant(rsGrade.GetFieldByIndex(1).ToString()));




	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -4;
	}

	rs.MoveFirst();
    int ntemp = rs.GetRowCount();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rs);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -6;
	}

	if(bUseTrans)
		Commit(nTrans);

   /* rs.MoveFirst();
	SendSheetDataToAnaL2(rs);*/
	return 1;
}




/// <Method class="CQA_HeatChemicalData_Mag" name="SendSheetDataToAnaL2" type="L3BOOL">
/// ��ί�е��´��컯�� 2009-01-03 
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL  CQA_HeatChemicalData_Mag::SendSheetDataToAnaL2(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;

	if(rs.GetRowCount() < 1)
		return false;

	//�齨���ݼ�
	CL3RecordSet *pRSheet = new CL3RecordSet();
	CL3RecordSetWrap rsSheet; pRSheet->QueryInterface(IID_IL3RecordSet,rsSheet); pRSheet->Release();
	rsSheet.AddField(_T("CommissionID"),VT_BSTR);
	rsSheet.AddField(_T("SampID"),VT_BSTR);
	rsSheet.AddField(_T("SampSort"),VT_BSTR);
	rsSheet.AddField(_T("SampPlace"),VT_BSTR);
	rsSheet.AddField(_T("SteelGrade"),VT_BSTR);
	rsSheet.AddField(_T("Contract"),VT_BSTR);
	rsSheet.AddField(_T("SendDate"),VT_BSTR);
	rsSheet.AddField(_T("PERMIT_DELETE_FLAG"),VT_INT);

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsSheet.AppendRecord();
		rsSheet.SetFieldByName(_T("CommissionID"),rs.GetFieldByName(_T("AppID")));
		rsSheet.SetFieldByName(_T("SampID"),rs.GetFieldByName(_T("Sample_Code")));
		rsSheet.SetFieldByName(_T("SampSort"),rs.GetFieldByName(_T("Sample_Type")));
		rsSheet.SetFieldByName(_T("SampPlace"),rs.GetFieldByName(_T("Sample_Address")));
		rsSheet.SetFieldByName(_T("SteelGrade"),rs.GetFieldByName(_T("SteelGrade")));
		rsSheet.SetFieldByName(_T("Contract"),rs.GetFieldByName(_T("Treaty")));
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		rsSheet.SetFieldByName(_T("SendDate"),CL3Variant(curTime.Format(_T("%Y-%m-%d %H:%M:%S"))));
		rsSheet.SetFieldByName(_T("PERMIT_DELETE_FLAG"),L3LONG(1));
		rs.MoveNext();
	}

	//L3LONG nPosID = 2;
	//CString csTableName = _T("TB_L3_ANACOMMISSION");
	//L3STRING strTableName = csTableName.AllocSysString();
	//InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
	//				    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
	//					strTableName,(L3RECORDSET)rsSheet);
	//L3SysFreeString(strTableName);

	//csTableName = _T("TB_L3_ANACOMMISSIONHIS");
	//strTableName = csTableName.AllocSysString();
	//InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
	//				    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
	//					strTableName,(L3RECORDSET)rsSheet);
	//L3SysFreeString(strTableName);

	//2009-04-07 Begin

	rsSheet.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\TB_L3_ANACOMMISSION"),rsSheet) < rsSheet.GetRowCount())
		return false;

	//2009-04-07 End

	return true;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="SendAnalysisDataToPLC" type="L3BOOL">
/// ������̼¯�����´�PLC 2009-03-21
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL  CQA_HeatChemicalData_Mag::SendAnalysisDataToPLC(L3FLOAT C_Ana,L3FLOAT S_Ana,L3FLOAT P_Ana)
{
	//�齨���ݼ�
	CL3RecordSet *pRSheet = new CL3RecordSet();
	CL3RecordSetWrap rsAna; pRSheet->QueryInterface(IID_IL3RecordSet,rsAna); rsAna->Release();
	rsAna.AddField(_T("C_Ana"),VT_R8);
	rsAna.AddField(_T("P_Ana"),VT_R8);
	rsAna.AddField(_T("S_Ana"),VT_R8);
	rsAna.AddField(_T("Permit_Delete_Flag"),VT_INT);

	rsAna.AppendRecord();
	rsAna.SetFieldByName(_T("C_Ana"),CL3Variant(C_Ana));
	rsAna.SetFieldByName(_T("P_Ana"),CL3Variant(P_Ana));
	rsAna.SetFieldByName(_T("S_Ana"),CL3Variant(S_Ana));
	rsAna.SetFieldByName(_T("Permit_Delete_Flag"),L3LONG(1));

	L3LONG nPosID = 4;
	CString csTableName = _T("BOF4_PLCAnalysis");
	L3STRING strTableName = csTableName.AllocSysString();
	InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
					    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
						strTableName,(L3RECORDSET)rsAna);
	L3SysFreeString(strTableName);

	return true;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="NewBFIronSheet" type="L3LONG">
/// ��������������ί�е���
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::NewBFIronSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	CL3RecordSetWrap rsApp;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rsApp))
	{
		return -1;
	}

	// �����ֶ���Ϣ
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//ȡ���κ�
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString cstrBFID = cstrTapNo.Mid(1,1);
        CString cstrAppID = CalLabSheetAppID(_T("G")+cstrBFID,_T("TG"));
		//��������
		CString cstrSampleCode = CalIronSampleCode(_T("G")+cstrBFID,_T("TG"),cstrTapNo);

		rsApp.AppendRecord();
		rsApp.MoveLast();
		 //�����
		rsApp.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
		//��������
		rsApp.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
		//��������
		rsApp.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
		//��������
		rsApp.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
		//�����ص�
		rsApp.SetFieldByName(_T("Sample_Address"),CL3Variant(_T("G")+cstrBFID));    
		//�������
		rsApp.SetFieldByName(_T("Sample_Type"),CL3Variant(_T("TG")));    

		rs.MoveNext();
	}

	int rscount = rsApp.GetRowCount();
	if (rscount < 1)
	{
		return -2;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsApp.MoveFirst();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rsApp);
	if(nRet < rsApp.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}

	//2009-04-07 Begin
	if (!SendSheetDataToAnaL2(rsApp))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}
	//2009-04-07 End

	if(bUseTrans)
		Commit(nTrans);

	//if (!SendSheetDataToAnaL2(rsApp))
	//{
	//	return -5;
	//}
	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="NewBFSlagSheet" type="L3LONG">
/// ������������ί�е���2009-04-14 �ƶ�������ͬʱ�ƶ�������
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::NewBFSlagSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	CL3RecordSetWrap rsApp;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rsApp))
	{
		return -1;
	}

	// �����ֶ���Ϣ
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//ȡ���κ�
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString cstrBFID = cstrTapNo.Mid(1,1);
        CString cstrAppID = CalLabSheetAppID(_T("G")+cstrBFID,QA_Sample_Type_ZG);
		//��������
		CString cstrSampleCode = CalIronSampleCode(_T("G")+cstrBFID,QA_Sample_Type_ZG,cstrTapNo);

		rsApp.AppendRecord();
		rsApp.MoveLast();
		 //�����
		rsApp.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
		//��������
		rsApp.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
		//��������
		rsApp.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
		//��������
		rsApp.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
		//�����ص�
		rsApp.SetFieldByName(_T("Sample_Address"),CL3Variant(_T("G")+cstrBFID));    
		//�������
		rsApp.SetFieldByName(_T("Sample_Type"),CL3Variant(QA_Sample_Type_ZG));    

		rs.MoveNext();
	}

	int rscount = rsApp.GetRowCount();
	if (rscount < 1)
	{
		return -2;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsApp.MoveFirst();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rsApp);
	if(nRet < rsApp.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}

	if (!SendSheetDataToAnaL2(rsApp))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	if(bUseTrans)
		Commit(nTrans);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="NewDeSIronSheet" type="L3LONG">
/// ��������Ԥ����������ί�е���
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::NewDeSIronSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	CL3RecordSetWrap rsApp;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rsApp))
	{
		return -1;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// �����ֶ���Ϣ
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//ȡ���κ�
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString cstrTPCNo = rs.GetFieldByName(_T("TPC_No")).ToCString();
		L3SHORT iMode = rs.GetFieldByName(_T("Mode")).ToShort();

		if (cstrTapNo.GetLength() < 2)//2009-04-16
		{
			rs.MoveNext();
			continue;
		}
		CString cstrBFID = cstrTapNo.Mid(1,1);//2009-04-16
        CString cstrAppID = CalLabSheetAppID(_T("G")+cstrBFID,_T("TS"));
		//��������
		CString cstrSampleCode = CalDesIronSampleCode(cstrTapNo,cstrTPCNo,iMode);

		rsApp.AppendRecord();
		rsApp.MoveLast();
		 //�����
		rsApp.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
		//��������
		rsApp.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
		//��������
		rsApp.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(1)));  
		//��������
		rsApp.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
		//�����ص�
		rsApp.SetFieldByName(_T("Sample_Address"),CL3Variant(_T("G")+cstrBFID));    
		//�������
		rsApp.SetFieldByName(_T("Sample_Type"),CL3Variant(_T("TS")));    

		/***********2009-10-27 begin yao**************/
		L3SHORT nSampleCount = 0;
		try
		{
			nSampleCount = _ttoi(cstrSampleCode.Right(1));
		}
		catch(...)
		{}
		CString csMaterialID = cstrTapNo.Trim() + cstrTPCNo.Trim();
		CString strDeSURI = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,csMaterialID);
		if (iMode == 1)
		{
			if (!SetObjectPropValue(strDeSURI,_T("SampleApplyCount_B"),CL3Variant((L3SHORT)nSampleCount)))
			{
				if(nTrans > 0)
					Rollback(nTrans);
				return FALSE;
			}
		}
		else if(iMode == 2)
		{
			if (!SetObjectPropValue(strDeSURI,_T("SampleApplyCount_A"),CL3Variant((L3SHORT)nSampleCount)))
			{
				if(nTrans > 0)
					Rollback(nTrans);
				return FALSE;
			}
		}
		/************2009-10-27 end **************/

		rs.MoveNext();
	}

	int rscount = rsApp.GetRowCount();
	if (rscount < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	rsApp.MoveFirst();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rsApp);
	if(nRet < rsApp.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}

	//2009-04-07 Begin
	if (!SendSheetDataToAnaL2(rsApp))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}
	//2009-04-07 End

	if(bUseTrans)
		Commit(nTrans);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronSampleCode" type="CString">
/// ����������ˮ��������
/// <Param name="csTAPNo" type="LPCTSTR"> ���κ�
/// <Param name="iMode" type="LPCTSTR"> ����ǰ���ʶ
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalDesIronSampleCode(LPCTSTR csTAPNo,LPCTSTR csTPCNo,L3SHORT iMode)
{
    CString cstrTPCNo = csTPCNo;
    CString cstrTAPNo = csTAPNo;
	int iTpcNo = _ttoi(cstrTPCNo);   
	cstrTPCNo.Format(_T("%02d"),iTpcNo);

	CString cstrPos;
	if (iMode == 1)
		cstrPos = _T("Q");
	else
		cstrPos = _T("H");

	CString cstrSampleNo=cstrTAPNo + cstrTPCNo + _T("TS")+cstrPos;

	CL3RecordSetWrap rs;
    //��CQA_Lab_Sheet_App��ȡ��¯����������(ȥ��ȡ������)���ȡ�����������Ϊ��ȡ������Ϊ0
	CString csSQL;
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where substr(Sample_Code,1,14) = '%s'"),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleNo);
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = 0;
		if ((rs.GetFieldByIndex(0)).ToCString().GetLength() > 0)
			nSampleCount = rs.GetFieldByIndex(0).ToLong();
		cstrSampleCount.Format(_T("%01d"),++nSampleCount);
	}
	else
	{
		cstrSampleCount = _T("1");
	}

	return cstrSampleNo + cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="SetDeSAnalysisData" type="L3BOOL">
/// ��������������� 009-10-25 yao
/// <Param name="SampleCode" type="LPCTSTR"> ���������
/// <Param name="S" type="L3FLOAT"> ��
/// <Param name="P" type="L3FLOAT"> ��
/// </Method>
L3BOOL  CQA_HeatChemicalData_Mag::SetDeSAnalysisData(LPCTSTR SampleCode,L3FLOAT S,L3FLOAT P)
{
	CString csSampleCode = SampleCode; 
	if(csSampleCode.GetLength() != 15)
	{
		return FALSE;
	}

	CString csMode = csSampleCode.Mid(13,1);
	CString csMaterialID = csSampleCode.Left(11);

	CString csIronUri = _T("MES\\MaterialData\\CBFIron\\")+csMaterialID;
    L3LONG nDeSFlag = GetObjectPropValue(csIronUri,_T("DeSFlag")).ToLong();
	if(nDeSFlag != 1)
	{
		return FALSE;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	if (csMode == _T("Q")) //ǰS
	{
		CL3RecordSetWrap rsDeS;
		CString csSQL;
		csSQL.Format(_T("select TreatNo,S_B,P_B from %s where MaterialID = '%s'"),CDES_PROCESS_URI,csMaterialID);
		if(!Query(csSQL,rsDeS))
		{
			if(bUseTrans) 
				Rollback(nTrans);
			return FALSE;
		}

		if (rsDeS.GetRowCount() > 0)
		{
			rsDeS.MoveFirst();
			while(!rsDeS.IsEOF())
			{
				rsDeS.SetFieldByName(_T("S_B"),(L3FLOAT)S);
				rsDeS.SetFieldByName(_T("P_B"),(L3FLOAT)P);
				rsDeS.MoveNext();
			}
			rsDeS.MoveFirst();
			CString csTreatNo = rsDeS.GetFieldByName(_T("TreatNo")).ToCString();

			if (!SetObjsPropValues(CDES_PROCESS_URI,rsDeS))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return FALSE;
			}
			if(csTreatNo.Left(1) == _T("1"))
			{
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Prod_Area\\S02A"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Prod_Area\\S02B"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
			}
			else if(csTreatNo.Left(1) == _T("2"))
			{
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Prod_Area\\S03A"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Prod_Area\\S03B"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
			}
		}
	}
    else if(csMode == _T("H")) //��S
	{
		CL3RecordSetWrap rsDeS;
		CString csSQL;
		csSQL.Format(_T("select TreatNo,S_A,P_A from %s where MaterialID = '%s'order by BlowBeginTime desc"),CDES_PROCESS_URI,csMaterialID);
		if(!Query(csSQL,rsDeS))
		{
			if(bUseTrans) 
				Rollback(nTrans);
			return FALSE;
		}

		if (rsDeS.GetRowCount() > 0)
		{
			rsDeS.MoveFirst();
 			CString csTreatNo = rsDeS.GetFieldByName(_T("TreatNo")).ToCString();
     		CString strDeSURI = CL3NameParser::MergeClassDomainName(CDES_PROCESS_URI,csTreatNo);

			if (!SetObjectPropValue(strDeSURI,_T("S_A"),(L3FLOAT)S))
			{
				if(bUseTrans) 
					Rollback(nTrans);
				return FALSE;
			}

			if (!SetObjectPropValue(strDeSURI,_T("P_A"),(L3FLOAT)P))
			{
				if(bUseTrans) 
					Rollback(nTrans);
				return FALSE;
			}

			if(csTreatNo.Left(1) == _T("1"))
			{
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag\\S02"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
			}
			else if(csTreatNo.Left(1) == _T("2"))
			{
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag\\S03"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
			}
		}
    }

	if(bUseTrans)
		Commit(nTrans);

	return TRUE;
}
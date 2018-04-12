// �߼���CQA_HeatSufaceAssume_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CQA_HeatSufaceAssume_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CQA_HeatSufaceAssume_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CQA_HeatSufaceAssume_Mag.h"
#include "L3NameParser.h"

//������װ�ص�ϵͳ��ʱ��������
void CQA_HeatSufaceAssume_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CQA_HeatSufaceAssume_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomHotJudge" type="L3LONG">
/// �����ȼ������ж�
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// ������HeatID��Bloom_Count��Cal_Weight��Wrong_Total_Count��Wrong_Total_Weight��
/// Wrong_Reason��Cut_SteelGradeIndex ��SteelGradeIndex��Produce_Date��Length��Width��
/// Thickness�ֶ�
/// </Method>
L3LONG CQA_HeatSufaceAssume_Mag::BloomHotJudge(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return -1;

	//��ȡ�������Ϣ
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	CString csShiftID = rpSysInfo.GetFieldByName(_T("ShiftID")).ToCString();
	CString csTeamID = rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();

	//��ȡ��ǰ�û�
	CString cstrOperator = GetCurrentUser();
    //������������CBloom_Data�������ݣ�������״̬����¼��
	CStringArray FieldNames; FieldNames.SetSize(16);
	CUIntArray FieldTypes; FieldTypes.SetSize(16);
	FieldNames[0] = _T("MaterialID");
	FieldNames[1] = _T("Status");
	FieldNames[2] = _T("Right_Count");
	FieldNames[3] = _T("Right_Weight");
	FieldNames[4] = _T("Wrong_Count");
	FieldNames[5] = _T("Wrong_Weight");
	FieldNames[6] = _T("Wrong_Count1");
	FieldNames[7] = _T("Wrong_Weight1");
	FieldNames[8] = _T("Wrong_Reason1");
	FieldNames[9] = _T("Wrong_Count2");
	FieldNames[10] = _T("Wrong_Weight2");
	FieldNames[11] = _T("Wrong_Reason2");
	FieldNames[12] = _T("Wrong_Count3");
	FieldNames[13] = _T("Wrong_Weight3");
	FieldNames[14] = _T("Wrong_Reason3");
	FieldNames[15] = _T("SufaceDefactDes");


	FieldTypes[0] = L3VT_STRING;
	FieldTypes[1] = L3VT_LONG;
	FieldTypes[2] = L3VT_LONG;
	FieldTypes[3] = L3VT_DOUBLE;
	FieldTypes[4] = L3VT_LONG;
	FieldTypes[5] = L3VT_DOUBLE;
	FieldTypes[6] = L3VT_LONG;
	FieldTypes[7] = L3VT_DOUBLE;
	FieldTypes[8] = L3VT_STRING;
	FieldTypes[9] = L3VT_LONG;
	FieldTypes[10] = L3VT_DOUBLE;
	FieldTypes[11] = L3VT_STRING;
	FieldTypes[12] = L3VT_LONG;
	FieldTypes[13] = L3VT_DOUBLE;
	FieldTypes[14] = L3VT_STRING;
	FieldTypes[15] = L3VT_STRING;

	CL3RecordSetWrap rsBloom;
	if (!CreateRecordSet(FieldNames,FieldTypes,rsBloom)|| rsBloom.IsNull())
		return -1;
    //����rs�а�����û���������������¼CQA_Bloom_HotJudge_Data����
	rs.AddField(_T("Team"),VT_BSTR);
	rs.AddField(_T("Shift"),VT_BSTR);
	rs.AddField(_T("Operator"),VT_BSTR);
	rs.AddField(_T("HeatID"),VT_BSTR);
	rs.AddField(_T("HotJudge_Time"),VT_DATE);
	rs.AddField(_T("CasterID"),VT_BSTR);
	rs.DelField(_T("GUID"));
	//
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("Team"),CL3Variant(csTeamID));
		rs.SetFieldByName(_T("Shift"),CL3Variant(csShiftID));
		rs.SetFieldByName(_T("Operator"),CL3Variant(cstrOperator));
		rs.SetFieldByName(_T("HeatID"),rs.GetFieldByName(_T("MaterialID")));
		rs.SetFieldByName(_T("HotJudge_Time"),COleDateTime::GetCurrentTime());
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		rs.SetFieldByName(_T("CasterID"),GetObjectPropValue(BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID,_T("CasterID")));
		//��rsBloom�������
		rsBloom.AppendRecord();
		rsBloom.CopyCurRowFrom(rs);
		if(rs.GetFieldByName(_T("WaitCheckFlag")).ToBOOL())//20081218 tangyi 
			rsBloom.SetFieldByName(_T("Status"),CL3Variant(BLOOM_STATUS_HOT_WAIT));//�ȼ첻������
		else
			rsBloom.SetFieldByName(_T("Status"),CL3Variant(BLOOM_STATUS_HOT_JUDGE));//�ȼ�Ǵ���
		rs.MoveNext();
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
    //�����ȼ�����
	rs.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Bloom_HotJudge_Data"),rs);
	if (nRet < rs.GetRowCount())
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -2;
	}
    //����¯������״̬Ϊ�ȼ����
	rsBloom.MoveFirst();
	if(!SetObjsPropValues(_T("MES\\MaterialData\\CBloom_Data"),rsBloom))
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	if (bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ��֪ͨ��������
	CL3Variant varEvent = GetPropValue(_T("HotJudgeEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("HotJudgeEvent"),nEvent);

	return rs.GetRowCount();
}
/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomColdJudge" type="L3LONG">
/// ������������ж�
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatSufaceAssume_Mag::BloomColdJudge(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return -1;

	//��ȡ�������Ϣ
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	CString csShiftID = rpSysInfo.GetFieldByName(_T("ShiftID")).ToCString();
	CString csTeamID = rpSysInfo.GetFieldByName(_T("TeamID")).ToCString();
	//��ȡ��ǰ�û�
	CString cstrOperator = GetCurrentUser();
    //������������CBloom_Data�������ݣ�������״̬����¼��
	CStringArray FieldNames; FieldNames.SetSize(17);
	CUIntArray FieldTypes; FieldTypes.SetSize(17);
	FieldNames[0] = _T("MaterialID");
	FieldNames[1] = _T("Status");
	FieldNames[2] = _T("Right_Count");
	FieldNames[3] = _T("Right_Weight");
	FieldNames[4] = _T("Wrong_Count");
	FieldNames[5] = _T("Wrong_Weight");
	FieldNames[6] = _T("Wrong_Count1");
	FieldNames[7] = _T("Wrong_Weight1");
	FieldNames[8] = _T("Wrong_Reason1");
	FieldNames[9] = _T("Wrong_Count2");
	FieldNames[10] = _T("Wrong_Weight2");
	FieldNames[11] = _T("Wrong_Reason2");
	FieldNames[12] = _T("Wrong_Count3");
	FieldNames[13] = _T("Wrong_Weight3");
	FieldNames[14] = _T("Wrong_Reason3");
	FieldNames[15] = _T("Process_Type");
	FieldNames[16] = _T("SufaceDefactDes");

	FieldTypes[0] = L3VT_STRING;
	FieldTypes[1] = L3VT_LONG;
	FieldTypes[2] = L3VT_LONG;
	FieldTypes[3] = L3VT_DOUBLE;
	FieldTypes[4] = L3VT_LONG;
	FieldTypes[5] = L3VT_DOUBLE;
	FieldTypes[6] = L3VT_LONG;
	FieldTypes[7] = L3VT_DOUBLE;
	FieldTypes[8] = L3VT_STRING;
	FieldTypes[9] = L3VT_LONG;
	FieldTypes[10] = L3VT_DOUBLE;
	FieldTypes[11] = L3VT_STRING;
	FieldTypes[12] = L3VT_LONG;
	FieldTypes[13] = L3VT_DOUBLE;
	FieldTypes[14] = L3VT_STRING;
	FieldTypes[15] = L3VT_LONG;
	FieldTypes[16] = L3VT_STRING;

	CL3RecordSetWrap rsBloom;
	if (!CreateRecordSet(FieldNames,FieldTypes,rsBloom)|| rsBloom.IsNull())
		return -1;
    //����rs�а�����û���������������¼CQA_Bloom_HotJudge_Data����
	rs.AddField(_T("Team"),L3VT_STRING);
	rs.AddField(_T("Shift"),L3VT_STRING);
	rs.AddField(_T("Operator"),L3VT_STRING);
	rs.AddField(_T("HeatID"),L3VT_STRING);
	rs.AddField(_T("CoolJudge_Time"),VT_DATE);
	rs.DelField(_T("GUID"));
	//
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("Team"),CL3Variant(csTeamID));
		rs.SetFieldByName(_T("Shift"),CL3Variant(csShiftID));
		rs.SetFieldByName(_T("Operator"),CL3Variant(cstrOperator));
		rs.SetFieldByName(_T("HeatID"),rs.GetFieldByName(_T("MaterialID")));
		rs.SetFieldByName(_T("CoolJudge_Time"),COleDateTime::GetCurrentTime());
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		rs.SetFieldByName(_T("CasterID"),GetObjectPropValue(BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID,_T("CasterID")));
		//��rsBloom�������
		CString cstrHeatID = (rs.GetFieldByName(_T("MaterialID"))).ToCString();
		rsBloom.AppendRecord();
		rsBloom.CopyCurRowFrom(rs);
		rsBloom.SetFieldByName(_T("Status"),CL3Variant(BLOOM_STATUS_COOL_JUDGE));//������
		rs.MoveNext();
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
    //�����������
	rs.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Bloom_CoolJudge_Data"),rs);
	if (nRet < rs.GetRowCount())
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -2;
	}
    //����¯������״̬Ϊ������
	rsBloom.MoveFirst();
	if(!SetObjsPropValues(_T("MES\\MaterialData\\CBloom_Data"),rsBloom))
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	if (bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ
	CL3Variant varEvent = GetPropValue(_T("CoolJudgeEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("CoolJudgeEvent"),nEvent);

	return rs.GetRowCount();
}

/// <Method class="CQuality_Mag" name="GetHeatCoolJudgeData" type="L3RECORDSET">
/// ��ȡ��������ж���Ϣ
/// <Param name="strCasterID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatSufaceAssume_Mag::GetHeatCoolJudgeData(L3STRING strCasterID)
{
	CString cstrCasterID = strCasterID;
	CString strSQL;
	strSQL.Format(_T("select * from CBloom_Data where CasterID= '%s' and Status = 10 or BloomCuttingTime > ?"),cstrCasterID);
	COleDateTime timeCur = COleDateTime::GetCurrentTime();
	//modify by hyh 2012-05-24
	//COleDateTime timeOld = timeCur - COleDateTimeSpan(1/3,0,0,0);
	COleDateTime timeOld=timeCur-COleDateTimeSpan(0.3333333);
	//end
	VARIANT params[1];
	params[0].vt = VT_DATE; params[0].date = (DATE)timeOld;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,1,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQuality_Mag" name="GetHeatCoolJudgeData" type="L3RECORDSET">
/// ��ȡ�ȼ������ж���Ϣ
/// <Param name="strCasterID" type="L3STRING">������</Param>
/// </Method>
L3RECORDSET CQA_HeatSufaceAssume_Mag::GetHeatHotJudgeData(L3STRING strCasterID)
{
	CString cstrCasterID = strCasterID;
	CString strSQL;
	strSQL.Format(_T("select * from CBloom_Data where CasterID= '%s' and Status = 6 or BloomCuttingTime > ?"),cstrCasterID);
	COleDateTime timeCur = COleDateTime::GetCurrentTime();
	//modify by hyh 2012-05-24
	//COleDateTime timeOld = timeCur - COleDateTimeSpan(1/3,0,0,0);
	COleDateTime timeOld = timeCur - COleDateTimeSpan(0.3333333);
	//end
	VARIANT params[1];
	params[0].vt = VT_DATE; params[0].date = (DATE)timeOld;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,1,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatSufaceAssume_Mag" name="GetBloomWaitingSendInfor" type="">
/// ��ȡ������������Ϣ
/// </Method>
L3RECORDSET CQA_HeatSufaceAssume_Mag::GetBloomWaitingSendInfor()
{

	CString csTemp =_T(" select a.MaterialType,a.Amount,b.* from %s a,%s b where a.Position ='%s'       ");
			csTemp+=_T(" and a.MaterialType = '%s' and a.MaterialID(+) = b.MaterialID  and b.Status =%s ");
	CString csSQL;
	//csSQL.Format(csTemp,MES_MATERIAL_POSITION,BLOOM_DATA_CLASS_URI,UNIT_ID_BLOOM_PCACHE,MATERIAL_TYPE_BLOOM,BLOOM_STATUS_HOT_JUDGE);
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,BLOOM_DATA_CLASS_URI,UNIT_ID_BLOOM_PCACHE,MATERIAL_TYPE_BLOOM,BLOOM_STATUS_FIN_JUDGE);
	CL3RecordSetWrap rsHeat;
	if(!Query(csSQL,rsHeat) || rsHeat.IsNull())
		return NULL;
	return rsHeat.Detach();
}


/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomOffLine" type="L3BOOL">
/// ��������
/// </Method>
L3LONG CQA_HeatSufaceAssume_Mag::BloomOffLine(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return -1;
	if(rs.GetFieldIndex(_T("Reason")) < 0 || rs.GetFieldIndex(_T("MaterialID")) < 0 )
		return -2;
	rs.MoveFirst();
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
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csUri = CL3NameParser::MergeClassDomainName(BLOOM_DATA_CLASS_URI,csMaterialID);
		if(!SetObjectPropValue(csUri,_T("Reason"),rs.GetFieldByName(_T("Reason"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -8;
		}
		if(!SetObjectPropValue(csUri,_T("Status"),CL3Variant(BLOOM_STATUS_DOWN)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -9;
		}
		rs.MoveNext();
	
	}

	if(bUseTrans)
		Commit(nTrans);	

	//�ı�����ֵ��֪ͨ���������
	CL3Variant varEvent = GetObjectPropValue(BLOOM_STORE_OBJ_URI,_T("BloomOffLineEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(BLOOM_STORE_OBJ_URI,_T("BloomOffLineEvent"),nEvent);

	return 0;

}

/// <Method class="CQA_HeatSufaceAssume_Mag" name="BloomOffLine" type="L3BOOL">
/// ��������
/// </Method>
L3LONG CQA_HeatSufaceAssume_Mag::BloomHotSend(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return -1;
	if(rs.GetFieldIndex(_T("Destination")) < 0 || rs.GetFieldIndex(_T("MaterialID")) < 0 )
		return -2;
	//����׼��
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialType"),VT_BSTR);
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rsBloom.AddField(_T("Amount"),VT_INT);
	rsBloom.AddField(_T("StoreAreaID"),VT_BSTR);
	rsBloom.AddField(_T("Target"),VT_BSTR);
	rsBloom.AddField(_T("SteelGradeIndex"),VT_BSTR);
	rsBloom.AddField(_T("Cur_Pile_ID"),VT_BSTR);
	rsBloom.AddField(_T("Cur_Layer_ID"),VT_BSTR);
	rsBloom.AddField(_T("Type"),VT_INT);
	///2009-02-23���������ֶ�
	rsBloom.AddField(_T("Bloom_Count"),VT_INT);
	rsBloom.AddField(_T("Waster_Count"),VT_R8);
	rsBloom.AddField(_T("Wrong_Count"),VT_INT);
	rsBloom.AddField(_T("Right_Count"),VT_INT);
	rsBloom.AddField(_T("Length"),VT_INT);
	rsBloom.AddField(_T("Width"),VT_INT);
	rsBloom.AddField(_T("Thickness"),VT_INT);
	rsBloom.AddField(_T("Cal_Weight"),VT_R8);
	rsBloom.AddField(_T("Right_Weight"),VT_R8);
	rsBloom.AddField(_T("Waster_Weight"),VT_R8);
	rsBloom.AddField(_T("Wrong_Weight"),VT_R8);
	rsBloom.AddField(_T("CasterID"),VT_BSTR);


	rs.MoveFirst();
	while(!rs.IsEOF())
	{	
		//û���иֲ���������
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();		
		//20081213 tangyi û�����в���������
		CString csBloomUri = BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID;
		CString csFinSteelGradeIndex = GetObjectPropValue(csBloomUri,_T("Final_SteelGradeIndex")).ToCString();
		L3LONG  nBloomCount = GetObjectPropValue(csBloomUri,_T("Right_Count")).ToLong();//�ж��Ƿ�ȫ¯���ϸ�
		L3LONG	nProcessType = GetObjectPropValue(csBloomUri,_T("Process_Type")).ToLong();//�ж��Ƿ�����
		csFinSteelGradeIndex.Trim();
		if(csFinSteelGradeIndex.IsEmpty())
			return -3;
		if(csFinSteelGradeIndex == WAITING_FIN_JUDGE && nProcessType != 1)
			return -4;
		if( nBloomCount == 0)
			return -5;
		rsBloom.AppendRecord();
		rsBloom.CopyCurRowFrom(rs);	
		//2009-02-23��Ӹ���������Ϣ
		CString csTemp = _T("select * from CBloom_Data where MaterialID = '%s'");
		CString csSQL;
		csSQL.Format(csTemp,csMaterialID);
		CL3RecordSetWrap rsBloomInfor;
		if(!Query(csSQL,rsBloomInfor)||rsBloomInfor.IsNull() ||rsBloomInfor.GetRowCount() < 1)
			return -6;
		rsBloomInfor.MoveFirst();
		rsBloom.CopyCurRowFrom(rsBloomInfor);
		rsBloom.SetFieldByName(_T("Target"),rs.GetFieldByName(_T("Destination")));
		rsBloom.SetFieldByName(_T("StoreAreaID"),CL3Variant(STORE_ID_BLOOM_STOCK));
		rsBloom.SetFieldByName(_T("Type"),CL3Variant(L3LONG(9)));
		rs.MoveNext();
	}

	CL3Variant valRtn =  InvokeObjectMethod(BLOOM_STORE_OBJ_URI,_T("BloomHotSend"),L3RECORDSET(rsBloom));
	if(!valRtn.IsValid() || valRtn.ToLong() < 0)
		return valRtn.ToLong();

	return 0;

}

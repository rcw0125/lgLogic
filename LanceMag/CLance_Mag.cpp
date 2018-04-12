// �߼���CLance_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CLance_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CLance_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CLance_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CLance_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CLance_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


L3BOOL CLance_Mag::UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = rsInfos;
	if(rs.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	CString csUri = lpcsClass;
	rs.MoveFirst();
	if(!SetObjsPropValues(csUri,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

L3BOOL CLance_Mag::DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = rsInfos;
	if(rs.GetRowCount() < 1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	CString csUri = lpcsClass;
	rs.MoveFirst();
	if(!DeleteOldObjects(csUri,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}


L3RECORDSET CLance_Mag::GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition)
{
	// TODO : ���ڴ�����߼�����
	CString csCondition =lpcsCondition;

	if(csCondition == _T(""))//2009-04-06
		return NULL;

	CString csTemp = _T(" SELECT * FROM %s where %s ");

	CString csUri = lpcsClass;
	CString csSQL;
	csSQL.Format(csTemp,csUri,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;

	return rsResult.Detach();
}





/// <Method class="CLance_Mag" name="SetLanceStatus" type="L3BOOL">
/// 
/// ������ǹ��״̬
/// ARG &gt;&gt; rsLances: Ҫ����״̬����ǹ�ļ�¼��
///     &gt;&gt; strStatus: ���ó�Ϊ��״̬��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsLances" type="L3RECORDSET"></Param>
/// <Param name="strStatus" type="L3STRING"></Param>
/// </Method>
L3BOOL CLance_Mag::SetLanceStatus(L3RECORDSET rsLances, L3STRING strStatus)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLances;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rsData.SetFieldByName(_T("Status"),CL3Variant(strStatus));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!SetObjsPropValues(CLANCE_BASE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;	
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceDefendStrat" type="L3BOOL">
/// 
/// ��ǹά�޿�ʼ
/// ARG &gt;&gt; rsLances: Ҫ��ʼά�޵���ǹ�ļ�¼�����������LanceID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsLance" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceDefendStrat(L3RECORDSET rsLance)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLance;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	
	int iYear = dtCurrentTime.GetYear();
	int iMonth = dtCurrentTime.GetMonth();

	CString csYear;
	csYear.Format(_T("%d"),iYear);
	csYear = csYear.Right(2);

	CString csMonth;
	csMonth.Format(_T("%02d"),iMonth);

	CString csYearMonth = csYear + csMonth;
	
	CStringArray FieldNames;FieldNames.SetSize(7);
	CUIntArray FieldTypes;FieldTypes.SetSize(7);

	FieldNames[0]=_T("LanceID");
	FieldNames[1]=_T("BOFID");
	FieldNames[2]=_T("Status");
	FieldNames[3]=_T("Lance_Age");
	FieldNames[4]=_T("MakeID");
	FieldNames[5]=_T("Make_Start_Time");
	FieldNames[6]=_T("Make_End_Time");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_STRING;
	FieldTypes[3]=L3VT_LONG;
	FieldTypes[4]=L3VT_STRING;
	FieldTypes[5]=L3VT_DATETIME;
	FieldTypes[6]=L3VT_DATETIME;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		CString csMakeID;

		CString csTemp = _T(" SELECT MakeID FROM %s WHERE LanceID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CLANCE_BASE_URI,csLanceID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull()||rsResult.GetRowCount() != 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;
		}
		rsResult.MoveFirst();
		CString csOldMakeID = rsResult.GetFieldByName(_T("MakeID")).ToCString();
		
		if(csOldMakeID == _T(""))
		{
			csMakeID = csYearMonth + csLanceID + _T("01");
		}
		else
		{
			CString csOldYearMonth = csOldMakeID.Left(4);
			//����ͬ��ͬ��
			if(csOldYearMonth == csYearMonth)
			{
				CString csOldNO = csOldMakeID.Right(2);
				CString csNO;
				int iNO = _ttoi(csOldNO) + 1;
				csNO.Format(_T("%02d"),iNO);
				csMakeID = csYearMonth + csLanceID + csNO;
			}
			else
			{
				csMakeID = csYearMonth + csLanceID + _T("01");
			}
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("LanceID"),CL3Variant(csLanceID));
		rsBase.SetFieldByName(_T("BOFID"),CL3Variant(_T("")));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CLANCE_STATUS_REPAIR));
		rsBase.SetFieldByName(_T("Lance_Age"),CL3Variant(L3LONG(0)));
		rsBase.SetFieldByName(_T("MakeID"),CL3Variant(csMakeID));
		rsBase.SetFieldByName(_T("Make_Start_Time"),CL3Variant(dtCurrentTime));
		rsBase.SetFieldByName(_T("Make_End_Time"),CL3Variant(_T("")));

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CLANCE_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;			
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceDefendEnd" type="L3BOOL">
/// 
/// ��ǹά�޽���
/// ARG &gt;&gt; rsLances: Ҫ����ά�޵���ǹ�ļ�¼�����������LanceID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsLance" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceDefendEnd(L3RECORDSET rsLance)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLance;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	CStringArray FieldNames;FieldNames.SetSize(3);
	CUIntArray FieldTypes;FieldTypes.SetSize(3);

	FieldNames[0]=_T("LanceID");
	FieldNames[1]=_T("Status");
	FieldNames[2]=_T("Make_End_Time");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_STRING;
	FieldTypes[2]=L3VT_DATETIME;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(FieldNames,FieldTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
	
		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("LanceID"),CL3Variant(csLanceID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CLANCE_STATUS_FREE));
		rsBase.SetFieldByName(_T("Make_End_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CLANCE_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;			
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceChangeOn" type="L3BOOL">
/// 
/// �˹�������ǹ
/// ARG &gt;&gt; rsLances: Ҫ���ϵ���ǹ�ļ�¼�����������LanceID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsLance" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceChangeOn(L3RECORDSET rsLance)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLance;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if(!SetObjectPropValue(CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Status"),CL3Variant(CLANCE_STATUS_USE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;				
		}
		rsData.MoveNext();
		
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceOffLineCheck" type="L3BOOL">
/// ��ǹ���߼��
/// <Param name="rsLances" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceOffLineCheck(L3RECORDSET rsLances)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLances;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if(!SetObjectPropValue(CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Status"),CL3Variant(CLANCE_STATUS_CHECK)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;				
		}
		rsData.MoveNext();
		
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceFree" type="L3BOOL">
/// ��ǹ���߼�����
/// ��Ϊ���ٴ�����ʹ��
/// <Param name="rsLances" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceFree(L3RECORDSET rsLances)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLances;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if(!SetObjectPropValue(CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Status"),CL3Variant(CLANCE_STATUS_FREE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;				
		}
		rsData.MoveNext();
		
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="LanceChangeOff" type="L3BOOL">
/// ��ǹ���ߴ���
/// ARG &gt;&gt; rsLances: Ҫ���µ���ǹ�ļ�¼�����������LanceID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsLance" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::LanceChangeOff(L3RECORDSET rsLance)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLance;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return FALSE;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if(!SetObjectPropValue(CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Status"),CL3Variant(CLANCE_STATUS_OFFLINE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;				
		}
		rsData.MoveNext();
		
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="InsertLanceDefendInfo" type="L3BOOL">
/// 
/// �����ǹά����Ϣ
/// ARG &gt;&gt; rsLanceDefends: Ҫ��ӵ���ǹ��ά���ļ�¼�����������LanceID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsLanceDefend" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceDefendInfo(L3RECORDSET rsLanceDefend)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLanceDefend;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		CString csMakeID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		
		if (csLanceID == _T("") || csMakeID== _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_DEFEND_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceDefendInfo" type="L3BOOL">
/// 
/// �޸���ǹά��ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceDefendInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_DEFEND_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceDefendInfo" type="L3BOOL">
/// 
/// ɾ����ǹά��ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceDefendInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_DEFEND_URI);
}

/// <Method class="CLance_Mag" name="GetLanceDefendInfo" type="L3RECORDSET">
/// 
/// ��ȡ��ǹά����Ϣ
/// ARG &gt;&gt; strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceDefendInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CLANCE_DEFEND_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceUseInfo" type="L3BOOL">
/// 
/// �����ǹʹ����Ϣ
/// ARG &gt;&gt; rsLanceUse: Ҫ��ӵ���ǹ��ʹ�õļ�¼�����������LanceID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsLanceUse" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceUseInfo(L3RECORDSET rsLanceUse)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLanceUse;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	//COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		if (csLanceID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CL3Variant clMakeID = GetObjectPropValue (CLANCE_BASE_URI + _T("\\") + csLanceID,_T("MakeID"));
		if( clMakeID.ToCString() == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CL3Variant clHeadType= GetObjectPropValue (CLANCE_BASE_URI + _T("\\") + csLanceID,_T("Lance_Head_Type"));
		rsData.SetFieldByName(_T("Lance_Head_Type"),CL3Variant(clHeadType));
		rsData.SetFieldByName(_T("MakeID"),CL3Variant(clMakeID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_USE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceUseInfo" type="L3BOOL">
/// 
/// �޸���ǹʹ��ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceUseInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_USE_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceUseInfo" type="L3BOOL">
/// 
/// ɾ����ǹʹ��ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceUseInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_USE_URI);
}

/// <Method class="CLance_Mag" name="GetLanceDefendInfo" type="L3RECORDSET">
/// <Method class="CLance_Mag" name="GetLanceUseInfo" type="L3RECORDSET">
/// 
/// ��ȡ��ǹʹ����Ϣ
/// ARG &gt;&gt; strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceUseInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CLANCE_USE_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceCheckInfo" type="L3BOOL">
/// 
/// �����ǹ�����Ϣ
/// ARG &gt;&gt; rsLanceCheck: Ҫ��ӵ���ǹ�ļ��ļ�¼�����������LanceID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsLanceCheck" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceCheckInfo(L3RECORDSET rsLanceCheck)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLanceCheck;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		if (csLanceID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CL3Variant clMakeID = GetObjectPropValue (CLANCE_BASE_URI + _T("\\") + csLanceID,_T("MakeID"));
		if( clMakeID.ToCString() == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		rsData.SetFieldByName(_T("MakeID"),CL3Variant(clMakeID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_CHECK_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceCheckInfo" type="L3BOOL">
/// 
/// �޸���ǹ���ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceCheckInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_CHECK_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceCheckInfo" type="L3BOOL">
/// 
/// ɾ����ǹ���ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceCheckInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_CHECK_URI);
}
/// <Method class="CLance_Mag" name="GetLanceCheckInfo" type="L3RECORDSET">
/// 
/// ��ȡ��ǹ�����Ϣ
/// ARG &gt;&gt; strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceCheckInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CLANCE_CHECK_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceHeadInInfo" type="L3BOOL">
/// 
/// �����ǹǹͷ�����Ϣ
/// ARG &gt;&gt; rsLanceHeadIn: Ҫ��ӵ���ǹ��ǹͷ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceHeadInInfo(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_IN_YARD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}
/// <Method class="CLance_Mag" name="UpdateLanceHeadInInfo" type="L3BOOL">
/// 
/// �޸�ǹͷ���ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceHeadInInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_IN_YARD_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceHeadInInfo" type="L3BOOL">
/// 
/// ɾ��ǹͷ���ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceHeadInInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_IN_YARD_URI);
}
/// <Method class="CLance_Mag" name="GetLanceLanceHeadInInfo" type="L3RECORDSET">
/// 
/// ��ȡ��ǹǹͷ�����Ϣ
/// ARG &gt;&gt; strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceLanceHeadInInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CLANCE_IN_YARD_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceHeadOutInfo" type="L3BOOL">
/// 
/// �����ǹǹͷ������Ϣ
/// ARG &gt;&gt; rsInfos: Ҫ��ӵ���ǹ��ǹͷ����ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceHeadOutInfo(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rsData.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_OUT_YARD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceHeadOutInfo" type="L3BOOL">
/// 
/// �޸�ǹͷ����ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: UpdateLanceHeadOutInfo(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLANCE_OUT_YARD_URI);
}
/// <Method class="CLance_Mag" name="DeleteLanceHeadOutInfo" type="L3BOOL">
/// 
/// ɾ��ǹͷ����ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3BOOL CLance_Mag:: DeleteLanceHeadOutInfo(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLANCE_OUT_YARD_URI);
}

/// <Method class="CLance_Mag" name="GetLanceLanceHeadOutInfo" type="L3RECORDSET">
/// 
/// ��ȡ��ǹǹͷ������Ϣ
/// ARG &gt;&gt; strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceLanceHeadOutInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CLANCE_OUT_YARD_URI,strCondition);
}

/// <Method class="CLance_Mag" name="InsertLanceMakeInfo" type="L3BOOL">
/// ������ǹ������Ϣ
/// <Param name="rsInfos" type="L3RECORDSET">��ǹ������Ϣ</Param>
/// </Method>
L3BOOL CLance_Mag::InsertLanceMakeInfo(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		if (csLanceID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		CL3Variant clMakeID = GetObjectPropValue (CLANCE_BASE_URI + _T("\\") + csLanceID,_T("MakeID"));
		if( clMakeID.ToCString() == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		rsData.SetFieldByName(_T("MakeID"),CL3Variant(clMakeID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLANCE_MAKE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="UpdateLanceMakeInfo" type="L3BOOL">
/// �޸���ǹ������Ϣ
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::UpdateLanceMakeInfo(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	return UpdateInfos(rsInfos,CLANCE_MAKE_URI);
}

/// <Method class="CLance_Mag" name="DeleteLanceMakeInfo" type="L3BOOL">
/// ɾ����ǹ������Ϣ
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CLance_Mag::DeleteLanceMakeInfo(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
		return FALSE;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMakeID = rsData.GetFieldByName(_T("MakeID")).ToCString();
		CString csLanceID = rsData.GetFieldByName(_T("LanceID")).ToCString();
		CString csTemp;
		CString csSQL;
		if (csMakeID == _T(""))
		{
			csTemp = _T("SELECT * FROM %s WHERE LanceID = '%s' and MakeID is null");
			csSQL.Format (csTemp,CLANCE_DEFEND_URI,csLanceID);
		}
		else
		{
			csTemp = _T("SELECT * FROM %s WHERE LanceID = '%s' and MakeID = '%s'");
			csSQL.Format (csTemp,CLANCE_DEFEND_URI,csLanceID,csMakeID);
		}
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return FALSE;	
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(!DeleteOldObjects(CLANCE_DEFEND_URI,rsResult))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return FALSE;	
			}
		}

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!DeleteOldObjects(CLANCE_MAKE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLance_Mag" name="GetLanceMakeInfo" type="L3RECORDSET">
/// ��ȡ��ǹ������Ϣ
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLance_Mag::GetLanceMakeInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CLANCE_MAKE_URI,strCondition);
}




// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CIronLadle_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CIronLadle_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CIronLadle_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CIronLadle_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CIronLadle_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <Method class="CIronLadle_Mag" name="GetInfos" type="L3BOOL">
/// 
/// ��ȡʵ����Ϣ
/// ARG &gt;&gt;strClassName:����
///     &gt;&gt;strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// <Param name="strClassName" type="L3STRING">����</Param>
/// </Method>
L3RECORDSET CIronLadle_Mag::GetInfos(L3STRING strCondition, L3STRING strClassName)
{
	CString  csClassUri = _T("XGMESLogic\\IronLadleMag\\");
	csClassUri += strClassName;
	CString csCondition =strCondition;
	if(csCondition == _T(""))
		return NULL;

	// TODO : ���ڴ�����߼�����
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	
	CString csSQL;
	csSQL.Format(csTemp,csClassUri,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CIronLadle_Mag" name="InsertInfos" type="L3LONG">
/// 
/// ���ʵ����Ϣ
/// ARG &gt;&gt;strClassName:����
///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// <Param name="strClassName" type="L3STRING">����</Param>
/// </Method>
L3LONG CIronLadle_Mag::InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName)
{
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;
	
	CString  csClassUri = _T("XGMESLogic\\IronLadleMag\\");
	csClassUri += strClassName;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	if(CreateNewObjects(csClassUri,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}

	if(bUseTrans)
		Commit(nTrans);

	// TODO : ���ڴ�����߼�����
	return 1;
}

/// <Method class="CIronLadle_Mag" name="UpdateInfos" type="L3LONG">
/// 
/// �޸�ʵ����Ϣ
/// ARG &gt;&gt;strClassName:����
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// <Param name="strClassName" type="L3STRING">����</Param>
/// </Method>
L3LONG CIronLadle_Mag::UpdateInfos(L3RECORDSET rsInfos, L3STRING strClassName)
{
	// TODO : ���ڴ�����߼�����

	return 0;
}

/// <Method class="CIronLadle_Mag" name="DeleteInfos" type="L3LONG">
/// 
/// ɾ��ʵ����Ϣ
/// ARG &gt;&gt;strClassName:����
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// <Param name="strClassName" type="L3STRING">����</Param>
/// </Method>
L3LONG CIronLadle_Mag::DeleteInfos(L3RECORDSET rsInfos, L3STRING strClassName)
{
	// TODO : ���ڴ�����߼�����
	return 0;
}


/// <Method class="CIronLadle_Mag" name="IronLadleTieStart" type="L3LONG">
/// 
/// ������Ὺʼ
/// ARG &gt;&gt;rsIronLadles: Ҫ��Ὺʼ�������ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleTieStart(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
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

	//���������޸�CIronLadle_Base����[2009-03-17]
	/*CL3RecordSetWrap rsBase;
	if(!CreateClassPropSet(CIRONLADLE_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}*/
	
	//������������CIRONLADLE_TIE_URI��������
	CL3RecordSetWrap rsTie;
	if(!CreateClassPropSet(CIRONLADLE_TIE_URI,rsTie))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csOldTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csTieID;

		if(csOldTieID == _T(""))
		{
			csTieID = csYearMonth + csIronLadleID + _T("01");
		}
		else
		{
			CString csOldYearMonth = csOldTieID.Left(4);
			//����ͬ��ͬ��
			if(csOldYearMonth == csYearMonth)
			{
				CString csOldNO = csOldTieID.Right(2);
				CString csNO;
				int iNO = _ttoi(csOldNO) + 1;
				csNO.Format(_T("%02d"),iNO);
				csTieID = csYearMonth + csIronLadleID + csNO;
			}
			else
			{
				csTieID = csYearMonth + csIronLadleID + _T("01");
			}
		}
		SetObjectPropValue(csBaseUri,_T("TieID"),CL3Variant(csTieID));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_TIE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("IronLadle_Age"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Refra_Produce"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Refra_ID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Small_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Middle_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Big_FireID"),CL3Variant((L3LONG)0));
	/*	rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsBase.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CIRONLADLE_STATUS_TIE));
		rsBase.SetFieldByName(_T("ComFlag"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("IronLadle_Age"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("Refra_Produce"),CL3Variant(_T("")));
		rsBase.SetFieldByName(_T("Refra_ID"),CL3Variant(_T("")));

		rsBase.SetFieldByName(_T("Small_FireID"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("Middle_FireID"),CL3Variant((L3LONG)0));
		rsBase.SetFieldByName(_T("Big_FireID"),CL3Variant((L3LONG)0));*/

		//��Ӵ��ʵ��
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		rsTie.AppendRecord();
		rsTie.SetFieldByName(_T("InPut_Time"),CL3Variant(dtCurrentTime));
		rsTie.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsTie.SetFieldByName(_T("TieID"),CL3Variant(csTieID));

		rsTie.SetFieldByName(_T("Tie_Start_Time"),CL3Variant(dtCurrentTime));
		rsTie.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsTie.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsTie.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		rsTie.SetFieldByName(_T("Doff_Mod_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}
	/*if(!SetObjsPropValues(CIRONLADLE_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}*/
	if(CreateNewObjects(CIRONLADLE_TIE_URI,rsTie) < rsTie.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//����Υ��ΨһԼ������
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleTieEnd" type="L3LONG">
/// 
/// ����������
/// ARG &gt;&gt;rsIronLadles: Ҫ�������������ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleTieEnd(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();

		if(csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�д����
		}

		CString csTieUri = CIRONLADLE_TIE_URI + _T("\\") + csTieID;//
		SetObjectPropValue(csTieUri,_T("Tie_End_Time"),CL3Variant(COleDateTime::GetCurrentTime()));

		CString csFac = GetObjectPropValue(csTieUri,_T("Refra_Produce")).ToCString();
		CString csName = GetObjectPropValue(csTieUri,_T("Refra_ID")).ToCString();
	
		SetObjectPropValue(csBaseUri,_T("Refra_Produce"),CL3Variant(csFac));
		SetObjectPropValue(csBaseUri,_T("Refra_ID"),CL3Variant(csName));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_COLD));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleSmallFireStart" type="L3LONG">
/// 
/// ����С��ʼ
/// ARG &gt;&gt;rsIronLadles: ҪС��ʼ�������ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleSmallFireStart(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	//������������CIRONLADLE_FIRE_URI��������
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�д����
		}
		long iSmallID =  GetObjectPropValue(csBaseUri,_T("Small_FireID")).ToLong();

		iSmallID = iSmallID + 1;
		SetObjectPropValue(csBaseUri,_T("Small_FireID"),CL3Variant(iSmallID));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_SMALL_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));

		//���С��濾ʵ��
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csObjectID ;
		csObjectID.Format(_T("%d"),iSmallID);
		csObjectID = csTieID + _T("1") + csObjectID;
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsFire.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("1")));
		rsFire.SetFieldByName(_T("Fire_Start_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(iSmallID));
		rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csObjectID));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//����Υ��ΨһԼ������
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CIronLadle_Mag" name="IronLadleSmallFireEnd" type="L3LONG">
/// 
/// ����С�����
/// ARG &gt;&gt;rsIronLadles: ҪС������������ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleSmallFireEnd(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csSmallID =  GetObjectPropValue(csBaseUri,_T("Small_FireID")).ToCString();

		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_SMALL_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		if(csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�д����
		}

		CString csObjectID = csTieID + _T("1") + csSmallID;
		CString csFireUri = CIRONLADLE_FIRE_URI + _T("\\") + csObjectID;
		COleDateTime dtStartTime = GetObjectPropValue(csFireUri,_T("Fire_Start_Time")).ToDateTime();
		//�濾ʱ��
		COleDateTimeSpan span = dtCurrentTime - dtStartTime;
		L3LONG nTime =(LONG)span.GetTotalMinutes();;

		SetObjectPropValue(csFireUri,_T("Fire_End_Time"),CL3Variant(dtCurrentTime));
		SetObjectPropValue(csFireUri,_T("Fire_Length"),CL3Variant(nTime));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleMiddleFireStart" type="L3LONG">
/// 
/// �����л�ʼ
/// ARG &gt;&gt;rsIronLadles: Ҫ�л�ʼ�������ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleMiddleFireStart(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	//������������CIRONLADLE_FIRE_URI��������
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�д����
		}
		long iMidID =  GetObjectPropValue(csBaseUri,_T("Middle_FireID")).ToLong();

		iMidID = iMidID + 1;
		SetObjectPropValue(csBaseUri,_T("Middle_FireID"),CL3Variant(iMidID));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_MIDDLE_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));

		//����л�濾ʵ��
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csObjectID ;
		csObjectID.Format(_T("%d"),iMidID);
		csObjectID = csTieID + _T("2") + csObjectID;
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsFire.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("2")));
		rsFire.SetFieldByName(_T("Fire_Start_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(iMidID));
		rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csObjectID));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//����Υ��ΨһԼ������
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleMiddleFireEnd" type="L3LONG">
/// 
/// �����л����
/// ARG &gt;&gt;rsIronLadles: Ҫ�л�����������ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleMiddleFireEnd(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csMidID =  GetObjectPropValue(csBaseUri,_T("Middle_FireID")).ToCString();

		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_MIDDLE_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		if(csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�д����
		}

		CString csObjectID = csTieID + _T("2") + csMidID;
		CString csFireUri = CIRONLADLE_FIRE_URI + _T("\\") + csObjectID;
		COleDateTime dtStartTime = GetObjectPropValue(csFireUri,_T("Fire_Start_Time")).ToDateTime();
		//�濾ʱ��
		COleDateTimeSpan span = dtCurrentTime - dtStartTime;
		L3LONG nTime =(LONG)span.GetTotalMinutes();;

		SetObjectPropValue(csFireUri,_T("Fire_End_Time"),CL3Variant(dtCurrentTime));
		SetObjectPropValue(csFireUri,_T("Fire_Length"),CL3Variant(nTime));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleBigFireStart" type="L3LONG">
/// 
/// �������ʼ
/// ARG &gt;&gt;rsIronLadles: Ҫ���ʼ�������ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleBigFireStart(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	//������������CIRONLADLE_FIRE_URI��������
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�д����
		}
		long iBigID =  GetObjectPropValue(csBaseUri,_T("Big_FireID")).ToLong();

		iBigID = iBigID + 1;
		SetObjectPropValue(csBaseUri,_T("Big_FireID"),CL3Variant(iBigID));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_BIG_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));

		//��Ӵ��濾ʵ��
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csObjectID ;
		csObjectID.Format(_T("%d"),iBigID);
		csObjectID = csTieID + _T("3") + csObjectID;
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("IronLadleID"),CL3Variant(csIronLadleID));
		rsFire.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("3")));
		rsFire.SetFieldByName(_T("Fire_Start_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(iBigID));
		rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csObjectID));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;	//����Υ��ΨһԼ������
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleBigFireEnd" type="L3LONG">
/// 
/// ����������
/// ARG &gt;&gt;rsIronLadles: Ҫ�������������ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleBigFireEnd(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csBigID =  GetObjectPropValue(csBaseUri,_T("Big_FireID")).ToCString();

		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		if(csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�д����
		}

		CString csObjectID = csTieID + _T("3") + csBigID;
		CString csFireUri = CIRONLADLE_FIRE_URI + _T("\\") + csObjectID;
		COleDateTime dtStartTime = GetObjectPropValue(csFireUri,_T("Fire_Start_Time")).ToDateTime();
		//�濾ʱ��
		COleDateTimeSpan span = dtCurrentTime - dtStartTime;
		L3LONG nTime =(LONG)span.GetTotalMinutes();;	

		SetObjectPropValue(csFireUri,_T("Fire_End_Time"),CL3Variant(dtCurrentTime));
		SetObjectPropValue(csFireUri,_T("Fire_Length"),CL3Variant(nTime));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLaldeStopUse" type="L3LONG">
/// ����ͣ��(תΪ�䱸)
/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLaldeStopUse(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_COLD));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleWaitRepair" type="L3LONG">
/// �������ߴ���
/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleWaitRepair(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;//
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_OFFLINE));
		SetObjectPropValue(csBaseUri,_T("Refra_Produce"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Refra_ID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Small_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Middle_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("Big_FireID"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="InsertTieInfos" type="L3LONG">
/// 
/// ��Ӵ��ʵ����Ϣ
/// ARG  &gt;&gt;rsTieInfos: Ҫ��ӵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsTieInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CIronLadle_Mag::InsertTieInfos(L3RECORDSET rsTieInfos)
{
	// TODO : ���ڴ�����߼�����
    CL3RecordSetWrap rsData = rsTieInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//��ȡ������
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if (csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��������
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();

		CString csTemp = _T(" select * from %s where TieID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CIRONLADLE_TIE_URI,csTieID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//��ѯ����¼ʧ��
		}
		if(rsResult.GetRowCount() > 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//��ǰ���ڴ���¼������������
		}

		rsData.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		
		//�Ͳĳ���
		CString csRefraPro = rsData.GetFieldByName(_T("Refra_Produce")).ToCString();
		//�Ͳ�����
		CString csRefraID = rsData.GetFieldByName(_T("Refra_ID")).ToCString();
 
		SetObjectPropValue(csBaseUri,_T("Refra_Produce"),CL3Variant(csRefraPro));
		SetObjectPropValue(csBaseUri,_T("Refra_ID"),CL3Variant(csRefraID));
		
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CIRONLADLE_TIE_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="UpdateTieInfos" type="L3LONG">
/// 
/// �޸Ĵ��ʵ����Ϣ
/// ARG &gt;&gt;rsTieInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsTieInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CIronLadle_Mag::UpdateTieInfos(L3RECORDSET rsTieInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = rsTieInfos;
	if(rs.IsNull() || rs.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//��ȡ������
		CString csTieID = rs.GetFieldByName(_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�д����
		}
		rs.MoveNext();
	}
	rs.MoveFirst();
	if(!SetObjsPropValues(CIRONLADLE_TIE_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="DeleteTieInfos" type="L3LONG">
/// 
/// ɾ�����ʵ����Ϣ
/// ARG &gt;&gt;rsTieInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsTieInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CIronLadle_Mag::DeleteTieInfos(L3RECORDSET rsTieInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = rsTieInfos;
	if(rs.GetRowCount() < 1)
		return 0;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//��ȡ�����
		CString csTieID = rs.GetFieldByName(_T("TieID")).ToCString();
		if (csTieID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�д����
		}
		rs.MoveNext();
	}
	rs.MoveFirst();
	if(DeleteOldObjects(CIRONLADLE_TIE_URI,rs) < rs.GetRowCount ())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


L3RECORDSET CIronLadle_Mag::GetTieInfos(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	CString csCondition =strCondition;
	if(csCondition == _T(""))
		return NULL;
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	
	CString csSQL;
	csSQL.Format(csTemp,CIRONLADLE_TIE_URI,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CIronLadle_Mag" name="InsertFireInfos" type="L3LONG">
/// ��Ӻ濾��Ϣ
/// <Param name="FireInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::InsertFireInfos(L3RECORDSET FireInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = FireInfos;
	if(rsData.GetRowCount() < 1||rsData.IsNull())
		return 0;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		long lFireType = rsData.GetFieldByName(_T("Fire_Type")).ToLong();
		CString csFireID =  rsData.GetFieldByName(_T("FireID")).ToString();//�޸ļ�¼���к濾���
		int iFireID = _ttoi(csFireID);
		if (csIronLadleID == _T("") ||lFireType == 0 ||iFireID < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�������Ż�濾���ͻ�濾����
		}
		
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToCString();
		CString csObjectID;
		CString csBaseFireID;
		int iBaseFireID = -1;
		switch(lFireType)
		{
			case 1:
				csBaseFireID =  GetObjectPropValue(csBaseUri,_T("Small_FireID")).ToCString();
				iBaseFireID = _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -2;//�濾�����Ȼ�����Ϣ�к濾�����ߣ�����������
				}
				csObjectID = csTieID + _T("1") + csFireID;
				break;
				
			case 2:
				csBaseFireID =  GetObjectPropValue(csBaseUri,_T("Middle_FireID")).ToCString();
				iBaseFireID = _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -2;//�濾�����Ȼ�����Ϣ�к濾�����ߣ�����������
				}
				csObjectID = csTieID + _T("2") +csFireID;
				break;
				
			case 3:
				csBaseFireID =  GetObjectPropValue(csBaseUri,_T("Big_FireID")).ToCString();
				iBaseFireID = _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -2;//�濾�����Ȼ�����Ϣ�к濾�����ߣ�����������
				}
				csObjectID = csTieID + _T("3") + csFireID;
				break;
		}
		CString csTemp = _T(" select * from %s where Object_ID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CIRONLADLE_FIRE_URI,csObjectID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;//��ѯ�濾��¼ʧ��
		}
		if(rsResult.GetRowCount() > 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//��ǰ���ں濾��¼������������
		}

		rsData.SetFieldByName(_T("Object_ID"),CL3Variant(csObjectID));
		rsData.SetFieldByName(_T("TieID"),CL3Variant(csTieID));
		rsData.SetFieldByName(_T("FireID"),CL3Variant(csFireID));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="UpdateFireInfos" type="L3LONG">
/// �޸ĺ濾��Ϣ
/// <Param name="dsFireInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CIronLadle_Mag::UpdateFireInfos(L3RECORDSET dsFireInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = dsFireInfos;
	if(rs.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	//������������CIRONLADLE_FIRE_URI��������
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csObjectID = rs.GetFieldByName(_T("Object_ID")).ToString();
		if (csObjectID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//��ǰ�޸ļ�¼û�йؼ���(����û��ˢ��)
		}
		
		CString csIronLadleID = rs.GetFieldByName(_T("IronLadleID")).ToString();//�޸ļ�¼����������
		CString csFireID =  rs.GetFieldByName(_T("FireID")).ToString();//�޸ļ�¼���к濾���
		int iFireID = _ttoi(csFireID);
		long lFireType = rs.GetFieldByName(_T("Fire_Type")).ToLong();//�޸ļ�¼���к濾����
		if (csIronLadleID == _T("")||csFireID ==_T("") ||lFireType ==0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//��ǰ�޸ļ�¼û�������Ż�濾��Ż�濾����
		}
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		CString csTieID = GetObjectPropValue(csBaseUri,_T("TieID")).ToString();
		CString csBaseFireID;
		int iBaseFireID = -1;
		CString csBaseObjectID;
		switch(lFireType)
		{
			case 1:
				csBaseFireID = GetObjectPropValue(csBaseUri,_T("Small_FireID")).ToString();
				iBaseFireID =  _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -3;//�濾�����Ȼ�����Ϣ�к濾�����ߣ�����������
				}
				csBaseObjectID = csTieID + _T("1") + csFireID;
				break;
				
			case 2:
				csBaseFireID = GetObjectPropValue(csBaseUri,_T("Middle_FireID")).ToString();
				iBaseFireID =  _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -3;//�濾�����Ȼ�����Ϣ�к濾�����ߣ�����������
				}
				csBaseObjectID = csTieID + _T("2") +csFireID;
				break;
				
			case 3:
				csBaseFireID = GetObjectPropValue(csBaseUri,_T("Big_FireID")).ToString();
				iBaseFireID =  _ttoi(csBaseFireID);
				if(iFireID > iBaseFireID)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -3;//�濾�����Ȼ�����Ϣ�к濾�����ߣ�����������
				}
				csBaseObjectID = csTieID + _T("3") + csFireID;
				break;
		}
		if(csObjectID != csBaseObjectID)//�޸��������Ȳ鿴�ɷ���������
		{

			CString csTemp = _T(" select * from %s where Object_ID = '%s' ");
			CString csSQL;
			csSQL.Format(csTemp,CIRONLADLE_FIRE_URI,csBaseObjectID);
			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;//��ѯ�濾��¼ʧ��
			}
			if(rsResult.GetRowCount() > 0 )
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;//��ǰ���ں濾��¼���������������������޸ģ�
			}

			//ɾ����ǰ��¼
			CL3RecordSetWrap rsDelete;
			if(!CreateClassPropSet(CIRONLADLE_FIRE_URI,rsDelete))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			rsDelete.AppendRecord();
			rsDelete.CopyCurRowFrom(rs);
			rsDelete.MoveFirst();
			if(DeleteOldObjects(CIRONLADLE_FIRE_URI,rsDelete) < rsDelete.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;//ɾ��ԭ�м�¼ʧ��		
			}
			//�����޸ĺ�ļ�¼
			rsFire.AppendRecord();
			rsFire.CopyCurRowFrom(rs);
			rsFire.SetFieldByName(_T("Object_ID"),CL3Variant(csBaseObjectID));
			rs.DeleteRecord(-1);
		}
		rs.MoveNext();
	}

	rs.MoveFirst();
	if (rs.GetRowCount()>0)
	{
		if(!SetObjsPropValues(CIRONLADLE_FIRE_URI,rs))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}
	}
	if (rsFire.GetRowCount()>0)
	{
		if(CreateNewObjects(CIRONLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="DeleteFireInfos" type="L3LONG">
/// ɾ���濾��Ϣ
/// <Param name="dsFireInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CIronLadle_Mag::DeleteFireInfos(L3RECORDSET dsFireInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = dsFireInfos;
	if(rs.GetRowCount() < 1)
		return 0;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csObjectID = rs.GetFieldByName(_T("Object_ID")).ToString();
		if (csObjectID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//��ǰ�޸ļ�¼û�йؼ���(����û��ˢ��)
		}
		rs.MoveNext();
	}
	rs.MoveFirst();
	if(DeleteOldObjects(CIRONLADLE_FIRE_URI,rs) < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="GetFireInfos" type="L3RECORDSET">
/// ��ȡ�濾��Ϣ
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CIronLadle_Mag::GetFireInfos(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	CString csCondition =strCondition;
	if(csCondition == _T(""))
		return NULL;
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	
	CString csSQL;
	csSQL.Format(csTemp,CIRONLADLE_FIRE_URI,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}



/// <Method class="CIronLadle_Mag" name="InsertUseInfos" type="L3LONG">
/// ���ʹ����Ϣ
/// <Param name="UseInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::InsertUseInfos(L3RECORDSET UseInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = UseInfos;
	if(rs.GetRowCount() < 1)
		return 0;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csIronLadleID = rs.GetFieldByName(_T("IronLadleID")).ToCString();
		if(csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	
		}
		
		CString csTieID = GetObjectPropValue(CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID,_T("TieID")).ToCString();
		rs.SetFieldByName(_T("TieID"),CL3Variant(csTieID));

	
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!CreateNewObjects(CIRONLADLE_USE_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="UpdateUseInfos" type="L3LONG">
/// �޸�ʹ����Ϣ
/// <Param name="dsUseInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CIronLadle_Mag::UpdateUseInfos(L3RECORDSET dsUseInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = dsUseInfos;
	if(rs.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	if(!SetObjsPropValues(CIRONLADLE_USE_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="DeleteUseInfos" type="L3LONG">
/// ɾ��ʹ����Ϣ
/// <Param name="dsUseInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CIronLadle_Mag::DeleteUseInfos(L3RECORDSET dsUseInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = dsUseInfos;
	if(rs.GetRowCount() < 1)
		return 0;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	if(DeleteOldObjects(CIRONLADLE_USE_URI,rs)< rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CIronLadle_Mag" name="GetUseInfos" type="L3RECORDSET">
/// ��ȡʹ����Ϣ
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CIronLadle_Mag::GetUseInfos(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	CString csCondition =strCondition;
	if(csCondition == _T(""))
		return NULL;
	CString csTemp = _T(" SELECT * FROM %s where %s ");
	
	CString csSQL;
	csSQL.Format(csTemp,CIRONLADLE_USE_URI,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CIronLadle_Mag" name="GetIronLadle_Age" type="L3LONG">
/// ����
/// <Param name="strIronladleId" type="L3STRING">��ѯ����</Param>
/// </Method>
L3LONG CIronLadle_Mag::GetIronLadle_Age(L3STRING strIronladleId)
{
	// TODO : ���ڴ�����߼�����
	CString csIronladleId =strIronladleId;
	CString csTemp = _T(" SELECT IRONLADLE_AGE FROM %s where INPUT_TIME = (select max(INPUT_TIME) from %s where IronLadleID = '%s')");
	CString csSQL;
	csSQL.Format(csTemp,CIRONLADLE_USE_URI,CIRONLADLE_USE_URI,csIronladleId);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return 0;

	if (rsResult.GetRowCount() < 1)
	{
		return 0;
	}

	rsResult.MoveFirst();
	L3LONG RelAge= rsResult.GetFieldByName(_T("IRONLADLE_AGE")).ToLong();
	return RelAge;

}

/// <Method class="CIronLadle_Mag" name="IronLadleUse" type="L3LONG">
/// ����תΪʹ��
/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleUse(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if(csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	
		}
		
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		long lIronLadleAge =GetObjectPropValue(csBaseUri,_T("IronLadle_Age")).ToLong();
		lIronLadleAge += 1;
	
		SetObjectPropValue(csBaseUri,_T("IronLadle_Age"),CL3Variant(lIronLadleAge));
		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleHot" type="L3LONG">
/// ת¯ָ��סԭ��������Ϊ�ȱ�
/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleHot(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		if(csIronLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	
		}
		
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT));
	
		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CIronLadle_Mag" name="IronLadleOffLineException" type="L3LONG">
/// �����쳣����
/// <Param name="rsIronLadles" type="L3RECORDSET">���ߵļ�¼</Param>
/// </Method>
L3LONG CIronLadle_Mag::IronLadleOffLineException(L3RECORDSET rsIronLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsIronLadles;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;
	if(rsData.GetFieldIndex(_T("IronLadleID")) < 0 || rsData.GetFieldIndex(_T("Status")) < 0 )
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans <1)
			return 0;
	}
	
	// �����߼�����ֻ���������� 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csIronLadleID = rsData.GetFieldByName(_T("IronLadleID")).ToCString();
		CString csStatus = rsData.GetFieldByName(_T("Status")).ToCString();
		CString csBaseUri = CIRONLADLE_BASE_URI + _T("\\") + csIronLadleID;

		if(csIronLadleID == _T("") || csStatus == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//û�������Ż�״̬
		}
	
		if(csStatus == CIRONLADLE_STATUS_USE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//�������������쳣����
		}
		if(!SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CIRONLADLE_STATUS_OFFLINE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//�޸�����״̬ʧ��
		}

		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

ULONG CLadle_Mag::MeasureDesignate(L3STRING strLadleID)// �߼���CLadle_Mag���û��߼�����Դ�ļ�
/// <Method class="CLadle_Mag" name="MeasureDesignate" type="ULONG">
/// �ְ�����ָ��
/// <Param name="strLadleID" type="L3STRING">�ְ���</Param>
/// </Method>
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CLadle_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CLadle_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CLadle_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CLadle_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CLadle_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


/// <Method class="CLadle_Mag" name="SetLadleStatus" type="L3LONG">
/// 
/// ���øְ�״̬
/// ARG &gt;&gt; rsLadles: Ҫ����״̬�ĸְ��ļ�¼��
///     &gt;&gt; strStatus: ���ó�Ϊ��״̬��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// <Param name="strStatus" type="L3STRING"></Param>
/// </Method>
L3LONG CLadle_Mag::SetLadleStatus(L3RECORDSET rsLadles, L3STRING strStatus)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		rsData.SetFieldByName(_T("Status"),CL3Variant(strStatus));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!SetObjsPropValues(CLADLE_BASE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="InsertInfos" type="L3LONG">
/// 
/// ���ʵ����Ϣ
/// ARG &gt;&gt;strClassName:����
///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// <Param name="strClassName" type="L3STRING">����</Param>
/// </Method>
L3LONG CLadle_Mag::InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName)
{
	// TODO : ���ڴ�����߼�����
	return 0;
}

/// <Method class="CLadle_Mag" name="UpdateInfos" type="L3LONG">
/// 
/// �޸�ʵ����Ϣ
/// ARG &gt;&gt;lpcsClass:����
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// <Param name="lpcsClass" type="LPCTSTR">����</Param>
/// </Method>
L3LONG CLadle_Mag::UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = rsInfos;
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
	
	CString csUri = lpcsClass;
	rs.MoveFirst();
	if(!SetObjsPropValues(csUri,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="DeleteInfos" type="L3LONG">
/// 
/// ɾ��ʵ����Ϣ
/// ARG &gt;&gt;lpcsClass:����
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// <Param name="lpcsClass" type="LPCTSTR">����</Param>
/// </Method>
L3LONG CLadle_Mag::DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs = rsInfos;
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

	CString csUri = lpcsClass;
	rs.MoveFirst();
	if(DeleteOldObjects(csUri,rs) < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="GetInfos" type="L3RECORDSET">
/// 
/// ��ȡʵ����Ϣ
/// ARG &gt;&gt;strClassName:����
///     &gt;&gt;strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
/// <Param name="lpcsClass" type="LPCTSTR">��ѯ����</Param>
/// <Param name="lpcsCondition" type="LPCTSTR">����</Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition)
{
	// TODO : ���ڴ�����߼�����
	CString csCondition =lpcsCondition;
	if(csCondition==_T(""))
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

/// <Method class="CLadle_Mag" name="SpecifyLadle" type="L3LONG">
/// 
/// ָ���ְ�
/// ARG &gt;&gt; rsLadlePlans: Ҫָ���ְ��ĸְ��ƻ��ļ�¼����
/// RET &lt;&lt; �ɹ�����true��ʧ�ܷ���false��
/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::SpecifyLadle(L3RECORDSET rsLadlePlans)
{
	CL3RecordSetWrap rs =rsLadlePlans;
    if( rs.IsNull() || rs.GetRowCount() < 1 )
		return 0;
	rs.MoveFirst();

	LONG lExcuteResult = 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	while(!rs.IsEOF())
	{
		CString csPlanID = rs.GetFieldByName(_T("PlanID")).ToCString();
		CString csUri = CLADLE_PLAN_URI + _T("\\") + csPlanID;
		CString csStatus = GetObjectPropValue(csUri,_T("Status")).ToCString();
		CString csLadleID =  rs.GetFieldByName(_T("LadleID")).ToCString();
		if(csStatus!=CLADLE_PLAN_STATUS_UNDESIGN || csLadleID.IsEmpty())
		{
			rs.MoveNext();
			continue;
		}
		CString csUriLadle = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString ssss =  GetObjectPropValue(csUriLadle,_T("Ladle_Age"));
		if (!SetObjectPropValue(csUri, _T("Ladle_Age"),GetObjectPropValue(csUriLadle,_T("Ladle_Age"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("New_BOF_Flag"),GetObjectPropValue(csUriLadle,_T("New_BOF_Flag"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("LadleID"),CL3Variant(csLadleID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("Status"),CL3Variant(CLADLE_PLAN_STATUS_DESIGN)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUriLadle, _T("Status"),CL3Variant(CLADLE_STATUS_DESIGN)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		lExcuteResult += 1;
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ
	CL3Variant varEvent = GetPropValue(_T("LadlePlanEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("LadlePlanEvent"),nEvent);

	return lExcuteResult;
}

/// <Method class="CLadle_Mag" name="LadlePour" type="L3LONG">
/// 
/// �ְ�����
/// ARG &gt;&gt; rsLadles: Ҫ�����ĸְ��ļ�¼����
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadlePour(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsInfos;
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//��ȡ�ְ���
		CString csOutLadleID = rsData.GetFieldByName(_T("Out_LadleID")).ToCString();
		CString csInLadleID = rsData.GetFieldByName(_T("In_LadleID")).ToCString();
		//��ȡ�����ְ���������
		CL3Variant clWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("WorkID"));

		CString csOutStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("Status")).ToCString();
		CString csInStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csInLadleID,_T("Status")).ToCString();

		if( csOutLadleID == _T("") || csInLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��ѡ��ְ���
		}
		
		//��������ְ�״̬Ϊʹ�ò��ҵ���ְ�Ϊ�ȱ�����ʱ�޸ĸְ�״̬
		if (csOutStatus == CLADLE_STATUS_USE && csInStatus == CLADLE_STATUS_HOT)
		{
			if(!SetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("Status"),CL3Variant(CLADLE_STATUS_HOT)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//����״̬���ɹ�
			}
			if(!SetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csInLadleID,_T("Status"),CL3Variant(CLADLE_STATUS_USE)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//����״̬���ɹ�
			}
		}
		rsData.SetFieldByName(_T("WorkID"),CL3Variant(clWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_POUR_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CLadle_Mag" name="UpdateLadlePourInfos" type="L3LONG">
/// �޸ĸְ�����ʵ��
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::UpdateLadlePourInfos(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	return UpdateInfos(rsInfos,CLADLE_POUR_URI);
}

/// <Method class="CLadle_Mag" name="DeleteLadlePourInfos" type="L3LONG">
/// ɾ���ְ�����ʵ��
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::DeleteLadlePourInfos(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	return DeleteInfos(rsInfos,CLADLE_POUR_URI);
}

/// <Method class="CLadle_Mag" name="GetLadlePourInfos" type="L3RECORDSET">
/// ��ȡ�ְ�����ʵ��
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetLadlePourInfos(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CLADLE_POUR_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="LadleFold" type="L3LONG">
/// 
/// �ְ��۹�
/// ARG &gt;&gt; rsLadles: Ҫ�۹޵ĸְ��ļ�¼����
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleFold(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsInfos;
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//��ȡ�ְ���
		CString csOutLadleID = rsData.GetFieldByName(_T("Out_LadleID")).ToCString();
		CString csInLadleID = rsData.GetFieldByName(_T("In_LadleID")).ToCString();
		//��ȡ�����ְ���������
		CL3Variant clWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("WorkID"));

		CString csOutStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("Status")).ToCString();
		CString csInStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csInLadleID,_T("Status")).ToCString();

		if( csOutLadleID == _T("") || csInLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û��ѡ��ְ���
		}
		
		//��������ְ�״̬Ϊʹ�ò��ҵ���ְ�Ϊ�ȱ�����ʱ�޸ĸְ�״̬
		if (csOutStatus == CLADLE_STATUS_USE && csInStatus == CLADLE_STATUS_HOT)
		{
			if(!SetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csOutLadleID,_T("Status"),CL3Variant(CLADLE_STATUS_HOT)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//����״̬���ɹ�
			}
			if(!SetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csInLadleID,_T("Status"),CL3Variant(CLADLE_STATUS_USE)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;	//����״̬���ɹ�
			}
		}
		rsData.SetFieldByName(_T("WorkID"),CL3Variant(clWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_FOLD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="UpdateLadleFoldInfos" type="L3LONG">
/// �޸ĸְ��۹�ʵ��
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::UpdateLadleFoldInfos(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	return UpdateInfos(rsInfos,CLADLE_FOLD_URI);
}

/// <Method class="CLadle_Mag" name="DeleteLadleFoldInfos" type="L3LONG">
/// ɾ���ְ��۹�ʵ��
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::DeleteLadleFoldInfos(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	return DeleteInfos(rsInfos,CLADLE_FOLD_URI);
}

/// <Method class="CLadle_Mag" name="GetLadleFoldInfos" type="L3RECORDSET">
/// ��ȡ�ְ��۹�ʵ��
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetLadleFoldInfos(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CLADLE_FOLD_URI,strCondition);
}
/// <Method class="CLadle_Mag" name="CancelSpecifyLadle" type="L3LONG">
/// 
/// ȡ��ָ��
/// ARG &gt;&gt; rsLadlePlans: Ҫȡ��ָ���ĸְ��ƻ��ļ�¼����
/// RET &lt;&lt; �ɹ�����true��ʧ�ܷ���false��
/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::CancelSpecifyLadle(L3RECORDSET rsLadlePlans)
{
	CL3RecordSetWrap rs =rsLadlePlans;
    if( rs.IsNull() || rs.GetRowCount() < 1 )
		return 0;
	rs.MoveFirst();

	LONG lExcuteResult = 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	while(!rs.IsEOF())
	{
		CString csPlanID = rs.GetFieldByName(_T("PlanID")).ToCString();
		CString csUri = CLADLE_PLAN_URI + _T("\\") + csPlanID;
		CString csStatus = GetObjectPropValue(csUri,_T("Status")).ToCString();
		CString csLadleID =  rs.GetFieldByName(_T("LadleID")).ToCString();
		if(csStatus!=CLADLE_PLAN_STATUS_DESIGN || csLadleID.IsEmpty())
		{
			rs.MoveNext();
			continue;
		}
		CString csUriLadle = CLADLE_BASE_URI + _T("\\") + csLadleID;
		if (!SetObjectPropValue(csUri, _T("Ladle_Age"),L3LONG(0)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}

		if (!SetObjectPropValue(csUri, _T("New_BOF_Flag"),L3LONG(0)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("LadleID"),CL3Variant(_T(""))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUri, _T("Status"),CL3Variant(CLADLE_PLAN_STATUS_UNDESIGN)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if (!SetObjectPropValue(csUriLadle, _T("Status"),CL3Variant(CLADLE_STATUS_HOT)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		lExcuteResult += 1;
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ
	CL3Variant varEvent = GetPropValue(_T("LadlePlanEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("LadlePlanEvent"),nEvent);

	return lExcuteResult;
}

/// <Method class="CLadle_Mag" name="ReSpecifyLadle" type="L3LONG">
/// 
/// ����ָ���ְ�
/// ARG &gt;&gt; strReLadleID:ָ���ְ��ţ�
///          &gt;&gt; rsLadlePlans: Ҫָ���ְ��ĸְ��ƻ��ļ�¼����
/// RET &lt;&lt; �ɹ�����true��ʧ�ܷ���false��
/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
/// <Param name="strReLadleID" type="L3STRING"></Param>
/// </Method>
L3LONG CLadle_Mag::ReSpecifyLadle(L3RECORDSET rsLadlePlans, L3STRING strReLadleID)
{
	// TODO : ���ڴ�����߼�����
	return 0;
}

/// <Method class="CLadle_Mag" name="QueryUnProcessLadlePlan" type="L3RECORDSET">
/// 
/// ��ȡ����ƻ���Ϣ�Լ��ϰ�δִ����ɼƻ�
/// ARG &gt;&gt; strBofID: ת¯�š�
///         &gt;&gt;strCasterID:������
/// RET &gt;&gt; �ҵ��ļƻ���¼����
/// <Param name="strBofID" type="L3STRING"></Param>
/// <Param name="strCasterID" type="L3STRING"></Param>
/// </Method>

L3RECORDSET CLadle_Mag::QueryUnProcessLadlePlan(L3STRING strBOFID, L3STRING strCasterID)
{

	CString csCasterID = strCasterID;
	CString csTempBOFID = strBOFID;
	CString csBOFID =csTempBOFID.Mid(2,1); 

	CL3RecordSetWrap rsReturnVal;

	CString cstrSQL = _T("  Select *  from %s                                                 ");
			cstrSQL+= _T("  where (CreateDate >= (select TRUNC(SYSDATE) from dual) -0.3333        ");
			cstrSQL+= _T("  or ( CreateDate < (select TRUNC(SYSDATE) from dual) -0.3333          ");
			cstrSQL+= _T(" and Status < '%s' ))                                                 ");


	if ((csBOFID == _T("")) && (csCasterID ==_T("")))
	{
		cstrSQL += _T("order by CasterID,CreateDate ");
		CString csSQL;
		csSQL.Format(cstrSQL,CLADLE_PLAN_URI,CLADLE_STATUS_WORK_EXCUTED);
		if (!Query(csSQL, rsReturnVal) || rsReturnVal.IsNull())
			return NULL;
		else
			return rsReturnVal.Detach();
	}
	else
	{
			if(csBOFID == _T("") && csCasterID !=_T(""))
			{
				cstrSQL += _T("and  CasterID = '%s' order by  CreateDate ");
				CString csSQL;
				csSQL.Format(cstrSQL,CLADLE_PLAN_URI,CLADLE_STATUS_WORK_EXCUTED,csCasterID);
				if (!Query(csSQL,rsReturnVal) || rsReturnVal.IsNull())
					return NULL;
				else
					return rsReturnVal.Detach();
			}
			else
			{
				if(csBOFID != _T("") && csCasterID ==_T(""))
				{
					cstrSQL += _T("and SubStr(HeatID,2,1) = '%s' order by HeatID ");	
					CString csSQL;
					csSQL.Format(cstrSQL,CLADLE_PLAN_URI,CLADLE_STATUS_WORK_EXCUTED,csBOFID);
					if (!Query(csSQL,rsReturnVal) || rsReturnVal.IsNull())
						return NULL;
					else
						return rsReturnVal.Detach();

				}
				else
				{
					cstrSQL += _T("and   SubStr(HeatID,2,1) = '%s' and  CasterID = '%s' order by HeatID ");	
					CString csSQL;
					csSQL.Format(cstrSQL,CLADLE_PLAN_URI,CLADLE_STATUS_WORK_EXCUTED,csBOFID,csCasterID);
					if (!Query(csSQL,rsReturnVal) || rsReturnVal.IsNull())
						return NULL;
					else
						return rsReturnVal.Detach();

				}
			}

	}

	return NULL;

}

//��ѯ���øְ�
/// <Method class="CLadle_Mag" name="GetAvailableLadle" type="L3RECORDSET">
/// </Method>
L3RECORDSET CLadle_Mag::GetAvailableLadle(void)
{
	CL3RecordSetWrap rsReturn;
	CString cstrSQL;
	cstrSQL.Format(_T("Select a.Code,a.Code_Des from %s a,%s b where a.code = b.LadleID and Status = '%s' order by LadleID "),_T("XGMESLogic\\BaseDataMag\\CBase_All_Code"),CLADLE_BASE_URI,CLADLE_STATUS_HOT);
	if (!Query(cstrSQL,rsReturn) || rsReturn.IsNull())
		return NULL;
	else
		return rsReturn.Detach();
}

//��ѯ�ְ����ò���
/// <Method class="CLadle_Mag" name="GetLadleInnerID" type="L3RECORDSET">
/// <Param name="strDateLadleID" type="L3STRING">�ְ���</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetLadleInnerID(L3STRING strDateLadleID)
{
	CL3RecordSetWrap rs;
	CString cstrSQL;
	CString csDateLadleID = strDateLadleID;
	csDateLadleID += _T("%");
	CString csTemp = _T("Select max(InnerID) InnerID from %s where InnerID like ? ");
	cstrSQL.Format(csTemp,CLADLE_IN_BUILD_URI);
	VARIANT valParams[1];
	valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csDateLadleID.AllocSysString();

	if (!QueryWithParam(cstrSQL,valParams,1,rs) || rs.IsNull())	  
	{
		::VariantClear(&valParams[0]);
		return NULL;
	}
	else
	{
		::VariantClear(&valParams[0]);
		return rs.Detach();
	}
}


/// <Method class="CLadle_Mag" name="InsertInnerBuildInfos" type="L3LONG">
/// 
/// ������ò���ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertInnerBuildInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//��ȡ�ְ���
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�иְ���
		}
		
		CString csInnerID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("InnerID"));
		
		CString csTemp = _T(" SELECT * FROM %s where InnerID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CLADLE_IN_BUILD_URI,csInnerID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount()>0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//�Ѿ��������ò�������Ϣ
		}
		rsData.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_IN_BUILD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateInnerBuildInfos" type="L3LONG">
/// 
/// �޸����ò���ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateInnerBuildInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_IN_BUILD_URI);
}
/// <Method class="CLadle_Mag" name="DeleteInnerBuildInfos" type="L3LONG">
/// 
/// ɾ�����ò���ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteInnerBuildInfos(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLADLE_IN_BUILD_URI);
}

/// <Method class="CLadle_Mag" name="GetInnerBuildInfos" type="L3RECORDSET">
/// 
/// ��ȡ���ò���ʵ����Ϣ
///     &gt;&gt;strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetInnerBuildInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_IN_BUILD_URI,strCondition);
}


/// <Method class="CLadle_Mag" name="InsertComTieInfos" type="L3LONG">
/// 
/// ��ӹ�������ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertComTieInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//��ȡ�ְ���
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�иְ���
		}
		
		CString csWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkID"));
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�й�������
		}
		
		CString csTemp = _T(" SELECT * FROM %s where WorkID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CLADLE_COM_TIE_URI,csWorkID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount()>0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//�Ѿ�������ͨ�ְ������Ϣ
		}

		rsData.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_COM_TIE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateComTieInfos" type="L3LONG">
/// 
/// �޸Ĺ�������ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateComTieInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_COM_TIE_URI);
}
/// <Method class="CLadle_Mag" name="DeleteComTieInfos" type="L3LONG">
/// 
/// ɾ����������ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteComTieInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
	if (rsData.IsNull()||rsData.GetRowCount()<1)
	return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if (bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
		{
			return 0;
		}
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//��ȡ����Ϣ�е�WorkID
		CString csWorkID = rsData.GetFieldByName(_T("WorkID")).ToCString();
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();

		//������GUID��ѯ����Ϣ
		CString csTemp;
		CString csSQL;

		if (csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//û�й�������
		}
		csTemp =_T(" SELECT * FROM %s WHERE WorkID = '%s' ");
		csSQL.Format(csTemp,CLADLE_COM_LAD_REP_URI,csWorkID);
		
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
			{
				Rollback(nTrans);
				return 0;
			}
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(DeleteOldObjects(CLADLE_COM_LAD_REP_URI,rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
				{
					Rollback(nTrans);
					return -2;//ɾ���޲�ʵ��ʧ��
				}
			}
		}
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(DeleteOldObjects(CLADLE_COM_TIE_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
		{
			Rollback(nTrans);
			return 0;
		}
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CLadle_Mag" name="GetComTieInfos" type="L3RECORDSET">
/// 
/// ��ȡ��������ʵ����Ϣ
///     &gt;&gt;strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetComTieInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_COM_TIE_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="InsertComRepInfos" type="L3LONG">
/// 
/// ��ӹ������޲�ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertComRepInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_COM_LAD_REP_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateComRepInfos" type="L3LONG">
/// 
/// �޸Ĺ������޲�ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateComRepInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_COM_LAD_REP_URI);
}
/// <Method class="CLadle_Mag" name="DeleteComRepInfos" type="L3LONG">
/// 
/// ɾ���������޲�ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteComRepInfos(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLADLE_COM_LAD_REP_URI);
}

/// <Method class="CLadle_Mag" name="GetComRepInfos" type="L3RECORDSET">
/// 
/// ��ȡ�������޲�ʵ����Ϣ
///     &gt;&gt;strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetComRepInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_COM_LAD_REP_URI,strCondition);
}


/// <Method class="CLadle_Mag" name="InsertFinBuildInfos" type="L3LONG">
/// 
/// ��ӹ���������ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertFinBuildInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//��ȡ�ְ���
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�иְ���
		}
		
		CString csWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkID"));
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�й�������
		}
		CString csTemp = _T(" SELECT * FROM %s where WorkID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CLADLE_FIN_BUILD_URI,csWorkID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;	
		}
		if(rsResult.GetRowCount()>0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//�Ѿ�������ͨ�ְ������Ϣ
		}
		
		rsData.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_FIN_BUILD_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateFinBuildInfos" type="L3LONG">
/// 
/// �޸Ĺ���������ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateFinBuildInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_FIN_BUILD_URI);
}
/// <Method class="CLadle_Mag" name="DeleteFinBuildInfos" type="L3LONG">
/// 
/// ɾ������������ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteFinBuildInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
	if (rsData.IsNull()||rsData.GetRowCount()<1)
	{
		return 0;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if (nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csWorkID = rsData.GetFieldByName (_T("WorkID")).ToCString();
		CString csLadleID = rsData.GetFieldByName (_T("LadleID")).ToCString();
		CString csTemp;
		CString csSQL;
		
		if (csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//û�й�������
		}
		csTemp =_T(" SELECT * FROM %s WHERE WorkID = '%s' ");
		csSQL.Format(csTemp,CLADLE_CHA_DRE_LIN_URI,csWorkID);
		
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
			{
				Rollback(nTrans);
				return 0;
			}
		}
		if(rsResult.GetRowCount() > 0)
		{
			rsResult.MoveFirst();
			if(DeleteOldObjects(CLADLE_CHA_DRE_LIN_URI,rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
				{
					Rollback(nTrans);
					return -2;//ɾ������ʵ��ʧ��
				}
			}
		}
		rsData.MoveNext();
	}

	if(DeleteOldObjects(CLADLE_FIN_BUILD_URI,rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CLadle_Mag" name="GetFinBuildInfos" type="L3RECORDSET">
/// 
/// ��ȡ����������ʵ����Ϣ
///     &gt;&gt;strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetFinBuildInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_FIN_BUILD_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="InsertChaDreLinInfos" type="L3LONG">
/// 
/// ��ӹ����㻻����ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertChaDreLinInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_CHA_DRE_LIN_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateChaDreLinInfos" type="L3LONG">
/// 
/// �޸Ĺ����㻻����ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateChaDreLinInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_CHA_DRE_LIN_URI);
}
/// <Method class="CLadle_Mag" name="DeleteChaDreLinInfos" type="L3LONG">
/// 
/// ɾ�������㻻����ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteChaDreLinInfos(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLADLE_CHA_DRE_LIN_URI);
}

/// <Method class="CLadle_Mag" name="GetChaDreLinInfos" type="L3RECORDSET">
/// 
/// ��ȡ�����㻻����ʵ����Ϣ
///     &gt;&gt;strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetChaDreLinInfos(L3STRING strCondition)
{
	return  GetInfos(CLADLE_CHA_DRE_LIN_URI,strCondition);
}


/// <Method class="CLadle_Mag" name="InsertFireInfos" type="L3LONG">
/// 
/// ��Ӻ濾ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: InsertFireInfos(L3RECORDSET rsInfos)
{
	CL3RecordSetWrap rsData = rsInfos;
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
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		//��ȡ�ְ���
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�иְ���
		}
		CString csFireType = rsData.GetFieldByName(_T("Fire_Type")).ToCString();
		if( csFireType == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�к濾����
		}
		CString csWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkID"));
		if( csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;	//û�й�������
		}

		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;
		CString csFireID;

		#pragma region "������濾"
		//������濾
		if(csFireType == _T("1"))
		{
			bool bExist = true;
			CString csWorkFireID;
			long lWorkFireID = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkFireID")).ToLong();
			while(lWorkFireID > 0 && bExist)
			{
				csWorkFireID.Format(_T("%d"),lWorkFireID);
				csFireID = csWorkID + _T("1") + csWorkFireID;
				csTemp = _T(" SELECT * FROM %s where FireID = '%s' ");
				csSQL.Format(csTemp,CLADLE_FIRE_URI,csFireID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult) || rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;	
				}
				if(rsResult.GetRowCount()>0)
				{
					bExist = true;
					lWorkFireID--;
				}
				else
				{
					bExist = false;
					rsData.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
					rsData.SetFieldByName(_T("FireID"),CL3Variant(csFireID));
				}
				//û�п��������ļ�¼
				if(bExist)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -5;//�Ѿ����ڸְ����ߺ濾��Ϣ
				}
			}

		}
		#pragma endregion
		#pragma region "���ߺ濾"
		//���ߺ濾
		else if (csFireType == _T("2"))
		{
			bool bExist = true;
			CString csHotFireID;
			long lHotFireID = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("OnFireID")).ToLong();
			while(lHotFireID > 0 && bExist)
			{
				csHotFireID.Format(_T("%d"),lHotFireID);
				csFireID = csWorkID + _T("2") + csHotFireID;
				csTemp = _T(" SELECT * FROM %s where FireID = '%s' ");
				csSQL.Format(csTemp,CLADLE_FIRE_URI,csFireID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult) || rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;	
				}
				if(rsResult.GetRowCount()>0)
				{
					bExist = true;
					lHotFireID--;
				}
				else
				{
					bExist = false;
					rsData.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
					rsData.SetFieldByName(_T("FireID"),CL3Variant(csFireID));
				}
				//û�п��������ļ�¼
				if(bExist)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -5;//�Ѿ����ڸְ����ߺ濾��Ϣ
				}
			}
		}
		#pragma endregion
		//Modify begin by llj 2011-04-10 �������ò�濾
		#pragma region "���ò�濾"
		//���ò�濾
		else if(csFireType == _T("3"))
		{
			bool bExist = true;
			CString csInnerFireID;
			long lInnerFireID = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("InnerFireID")).ToLong();
			CString csInnerID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("InnerID"));
			if( csInnerID == _T(""))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;	//û�����ò���
			}
			while(lInnerFireID > 0 && bExist)
			{
				csInnerFireID.Format(_T("%d"),lInnerFireID);
				csFireID = csInnerID + _T("3") + csInnerFireID;
				csTemp = _T(" SELECT * FROM %s where FireID = '%s' ");
				csSQL.Format(csTemp,CLADLE_FIRE_URI,csFireID);
				rsResult.DeleteAll();
				if(!Query(csSQL,rsResult) || rsResult.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;	
				}
				if(rsResult.GetRowCount()>0)
				{
					bExist = true;
					lInnerFireID--;
				}
				else
				{
					bExist = false;
					rsData.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
					rsData.SetFieldByName(_T("FireID"),CL3Variant(csFireID));
				}
				//û�п��������ļ�¼
				if(bExist)
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -7;//�Ѿ����ڸְ����ߺ濾��Ϣ
				}
			}

		}
		#pragma endregion
		//Modify end
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_FIRE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
/// <Method class="CLadle_Mag" name="UpdateFireInfos" type="L3LONG">
/// 
/// �޸ĺ濾ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: UpdateFireInfos(L3RECORDSET rsInfos)
{
	return UpdateInfos(rsInfos,CLADLE_FIRE_URI);
}
/// <Method class="CLadle_Mag" name="DeleteFireInfos" type="L3LONG">
/// 
/// ɾ���濾ʵ����Ϣ
///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ���0��
/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
/// </Method>
L3LONG CLadle_Mag:: DeleteFireInfos(L3RECORDSET rsInfos)
{
	return DeleteInfos(rsInfos,CLADLE_FIRE_URI);
}

/// <Method class="CLadle_Mag" name="GetFireInfos" type="L3RECORDSET">
/// 
/// ��ȡ�濾ʵ����Ϣ
///     &gt;&gt;strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CLadle_Mag:: GetFireInfos(L3STRING strCondition)
{
	return GetInfos(CLADLE_FIRE_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="InsertLadleUseInfos" type="L3LONG">
/// ���ʹ����Ϣ
/// <Param name="rsInfos" type="L3RECORDSET">��ӵļ�¼��</Param>
/// </Method>
L3LONG CLadle_Mag::InsertLadleUseInfos(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;//����С��0

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
		//��ȡ�ְ���
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csBOFID = rsData.GetFieldByName(_T("BOFID")).ToCString();//[2009-03-03]

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�л�ȡ���ְ���
		}
		
		CL3Variant clWorkID =	GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("WorkID"));
		CString csStatus = GetObjectPropValue(CLADLE_BASE_URI + _T("\\") + csLadleID,_T("Status")).ToCString();

		if(csStatus != CLADLE_STATUS_HOT)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//�˸ְ������ȱ��ְ�
		}

		//���ת¯��Ϊ�գ��жϵ�ǰת¯�Ƿ����û��ʹ�õĸְ�[ComFlag=0]
		if (csBOFID != _T(""))
		{	
			CString csTemp = _T("select * from %s where LadleID = '%s' and BOFID = '%s' and ComFlag = '0' ");
			CString csSQL;
			csSQL.Format(csTemp,CLADLE_USE_URI,csLadleID,csBOFID);

			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	//��ѯʧ��
			}
			if(rsResult.GetRowCount() > 0)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -3;	//��鵽��ǰת¯�ϴ���ָ���ְ�����ȡ��ָ��
			}
			
		}
		rsData.SetFieldByName(_T("WorkID"),CL3Variant(clWorkID));
	
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CLADLE_USE_URI,rsData) <  rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;//rsData.GetRowCount();
}

/// <Method class="CLadle_Mag" name="UpdateLadleUseInfos" type="L3LONG">
/// �޸�ʹ����Ϣ
/// <Param name="rsInfos" type="L3RECORDSET">�޸ĵļ�¼��</Param>
/// </Method>
L3LONG CLadle_Mag::UpdateLadleUseInfos(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	//return UpdateInfos(rsInfos,CLADLE_USE_URI);

	CL3RecordSetWrap rsData = rsInfos;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;//����С��0

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
		//��ȡ�ְ���
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csBOFID = rsData.GetFieldByName(_T("BOFID")).ToCString();//[2009-03-03]

		if( csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�л�ȡ���ְ���
		}
		
		//���ת¯��Ϊ�գ��жϵ�ǰת¯�Ƿ����û��ʹ�õĸְ�[ComFlag=0]
		if (csBOFID != _T(""))
		{	
			CString csTemp = _T("select * from %s where LadleID = '%s' and BOFID = '%s' and ComFlag = '0' ");
			CString csSQL;
			csSQL.Format(csTemp,CLADLE_USE_URI,csLadleID,csBOFID);

			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	//��ѯʧ��
			}
			if(rsResult.GetRowCount() > 0)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -3;	//��鵽��ǰת¯�ϴ���ָ���ְ�����ȡ��ָ��
			}
			
		}
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(!SetObjsPropValues(CLADLE_USE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="DeleteLadleUseInfos" type="L3LONG">
/// ɾ��ʹ����Ϣ
/// <Param name="rsInfos" type="L3RECORDSET">ɾ���ļ�¼��</Param>
/// </Method>
L3LONG CLadle_Mag::DeleteLadleUseInfos(L3RECORDSET rsInfos)
{
	// TODO : ���ڴ�����߼�����
	return DeleteInfos(rsInfos,CLADLE_USE_URI);
}

/// <Method class="CLadle_Mag" name="GetLadleUseInfos" type="L3RECORDSET">
/// ��ѯʹ����Ϣ
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetLadleUseInfos(L3STRING strCondition)
{
	return GetInfos(CLADLE_USE_URI,strCondition);
}

/// <Method class="CLadle_Mag" name="GetUseByLadleID" type="L3RECORDSET">
/// ���ݸְ��Ż�ȡ�ְ��ϴ���תʹ����Ϣ
/// <Param name="strLadleID" type="L3STRING">�ְ���</Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetUseByLadleID(L3STRING strLadleID)
{
	// TODO : ���ڴ�����߼�����
	CString csLadleID = strLadleID;
	if (csLadleID == _T("")||csLadleID.GetLength()<1)
	{
		return NULL ;
	}

	CStringArray FieldNames;FieldNames.SetSize(7);
	CUIntArray FieldTypes;FieldTypes.SetSize(7);

	FieldNames[0]=_T("LadleID");
	FieldNames[1]=_T("Ladle_Age");
	FieldNames[2]=_T("Steel_Grade");
	FieldNames[3]=_T("Tap_Time");
	FieldNames[4]=_T("Irr_Time");
	FieldNames[5]=_T("Off_Ladle_Time");//
	FieldNames[6]=_T("HeatID");

	FieldTypes[0]=L3VT_STRING;
	FieldTypes[1]=L3VT_LONG;
	FieldTypes[2]=L3VT_STRING;
	FieldTypes[3]=L3VT_DATETIME;
	FieldTypes[4]=L3VT_DATETIME;
	FieldTypes[5]=L3VT_DATETIME;
	FieldTypes[6]=L3VT_STRING;

	CL3RecordSetWrap rsInfo;
	if(!CreateRecordSet(FieldNames,FieldTypes,rsInfo)||rsInfo.IsNull())
		return NULL;

	rsInfo.AppendRecord();
	
	//����ʵ��
	CString csTemp = _T("select * from (SELECT * FROM %s WHERE LadleID = '%s' order by Casting_Start_Time desc) where rownum < 2");
	CString csSQL;
	csSQL.Format(csTemp,_T("XGMESLogic\\CCMMag\\CCCM_Heat_Ladle"),csLadleID);
	CL3RecordSetWrap rsResult;
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;
	
	rsResult.MoveFirst();
	CString csIrrTime = rsResult.GetFieldByName(_T("Casting_Start_Time")).ToCString();
	CString csOffLadleTime = rsResult.GetFieldByName(_T("Departure_Time")).ToCString();
	CString csHeatID = rsResult.GetFieldByName(_T("HeatID")).ToCString();

	rsInfo.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
	rsInfo.SetFieldByName(_T("Irr_Time"),CL3Variant(csIrrTime));
	rsInfo.SetFieldByName(_T("Off_Ladle_Time"),CL3Variant(csOffLadleTime));
	rsInfo.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));

	//����ʱ��
	csTemp = _T("select Tapping_Strat_Time  from %s where HeatID = '%s'");//SteelGrade
	csSQL.Format(csTemp,_T("XGMESLogic\\BOFMag\\CBOF_Process_Data"),csHeatID);
	rsResult.DeleteAll();
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;

	rsResult.MoveFirst();
	CString csTapTime = rsResult.GetFieldByName(_T("Tapping_Strat_Time")).ToCString();
	rsInfo.SetFieldByName(_T("Tap_Time"),CL3Variant(csTapTime));

	//����
	csTemp = _T("select SteelGrade  from %s where HeatID = '%s'");
	csSQL.Format(csTemp,_T("XGMESLogic\\BOFMag\\CBOF_Base_Data"),csHeatID);
	rsResult.DeleteAll();
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;

	rsResult.MoveFirst();
	CString csSteelGrade = rsResult.GetFieldByName(_T("SteelGrade")).ToCString();
	rsInfo.SetFieldByName(_T("Steel_Grade"),CL3Variant(csSteelGrade));

	//����
	csTemp = _T("select * from (select *  from %s where LadleID = '%s' order by Input_Time desc) where rownum < 2");
	csSQL.Format(csTemp,CLADLE_USE_URI,csLadleID);
	rsResult.DeleteAll();
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;

	rsResult.MoveFirst();
	CString csLadleAge = rsResult.GetFieldByName(_T("Ladle_Age")).ToCString();
	int  iAge=_ttoi(csLadleAge) + 1;
	rsInfo.SetFieldByName(_T("Steel_Grade"),CL3Variant(iAge));

	return rsInfo.Detach();
}

/// <Method class="CLadle_Mag" name="SetLadleInfoTaping" type="L3LONG">
/// ת¯����ʱ���øְ��ϼ���Ϣ�Լ��ְ�������Ϣ
/// <Param name="dsInfo" type="L3RECORDSET">�ְ���</Param>
/// </Method>
L3LONG CLadle_Mag::SetLadleInfoTaping(L3RECORDSET dsInfo)
{
	return 0;
}

/// <Method class="CLadle_Mag" name="GetIrrEndTime" type="L3RECORDSET">
/// ͨ���ְ��Ų�ѯ�˸ְ��ϴ�ͣ��ʱ��
/// <Param name="strLadleID" type="L3STRING">�ְ���</Param>
/// </Method>
L3RECORDSET CLadle_Mag::GetIrrEndTime(L3STRING strLadleID)
{
	// TODO : ���ڴ�����߼�����
	CString csLadleID = strLadleID;
	if (csLadleID == _T("")||csLadleID.GetLength()<1)
	{
		return NULL ;
	}

	CString csTemp = _T("select * from (select * from %s where LadleID = '%s' order by Input_time desc) where rownum <2 ");
	CString csSQL;
	csSQL.Format(csTemp,CLADLE_USE_URI,csLadleID);
	CL3RecordSetWrap rsResult;
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;
	
	rsResult.MoveFirst();
	CString csHeatID = rsResult.GetFieldByName(_T("HeatID")).ToCString();

	csTemp = _T("select * from (SELECT * FROM %s WHERE LadleID = '%s' and HeatID = '%s' order by Casting_Start_Time desc) where rownum < 2");
	csSQL.Format(csTemp,_T("XGMESLogic\\CCMMag\\CCCM_Heat_Ladle"),csLadleID,csHeatID);
	rsResult.DeleteAll();
	if (!Query(csSQL,rsResult)||rsResult.IsNull())
		return NULL;

	return rsResult.Detach();
}

/// <Method class="CLadle_Mag" name="LadleInnerBuildStart" type="L3LONG">
/// �ְ����ò�������ʼ
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleInnerBuildStart(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
	int iYear = dtCurrentTime.GetYear();
	int iMonth = dtCurrentTime.GetMonth();

	CString csYear;
	csYear.Format(_T("%d"),iYear);
	csYear = csYear.Right(2);

	CString csMonth;
	csMonth.Format(_T("%02d"),iMonth);

	CString csYearMonth = csYear + csMonth;
	
	//�������������ְ����ò�ʵ��
	CL3RecordSetWrap rsInner;
	if(!CreateClassPropSet(CLADLE_IN_BUILD_URI,rsInner))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csInnerID ;
		if(csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//û�иְ���
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		//��ѯԭ���ò���
		CString csOldInnerID = GetObjectPropValue(csBaseUri,_T("InnerID")).ToCString();
		
		if(csOldInnerID == _T(""))
			csInnerID = csYearMonth + csLadleID + _T("01");
		else
		{
			CString csOldYearMonth = csOldInnerID.Left(4);
			//����ͬ��ͬ��
			if(csOldYearMonth == csYearMonth)
			{
				CString csOldNO = csOldInnerID.Right(2);
				CString csNO;
				int iNO = _ttoi(csOldNO) + 1;
				csNO.Format(_T("%02d"),iNO);
				csInnerID = csYearMonth + csLadleID + csNO;
			}
			else
				csInnerID = csYearMonth + csLadleID + _T("01");
		}

		SetObjectPropValue(csBaseUri,_T("HeatID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_INNER_BUILD));
		SetObjectPropValue(csBaseUri,_T("Ladle_Age"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("InnerID"),CL3Variant(csInnerID));
		SetObjectPropValue(csBaseUri,_T("WorkID"),CL3Variant(_T("")));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("WorkFireID"),CL3Variant((L3LONG)0));//2009-04-17
		//Modify begin by llj 2011-04-10 �������ò�濾ʵ��
		SetObjectPropValue(csBaseUri,_T("InnerFireID"),CL3Variant((L3LONG)0));//2009-04-17
		//Modify end
		SetObjectPropValue(csBaseUri,_T("OnFireID"),CL3Variant((L3LONG)0));

		//������ò�����ʵ��
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		rsInner.AppendRecord();//
		rsInner.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsInner.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
		rsInner.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
		rsInner.SetFieldByName(_T("Build_Start_Time"),CL3Variant(dtCurrentTime));
		rsInner.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsInner.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsInner.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	
	rsInner.MoveFirst();
	if(CreateNewObjects(CLADLE_IN_BUILD_URI,rsInner) <  rsInner.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//������ò�������Ϣʧ��		
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleInnerBuildEnd" type="L3LONG">
/// �ְ����ò���������
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleInnerBuildEnd(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csInnerID =	rsData.GetFieldByName(_T("InnerID")).ToCString();
		if(csLadleID == _T("") || csInnerID ==_T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//�ְ��Ż����ò���Ϊ��
		}
		//�޸���ɱ�־
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));
		//�޸���������ʱ��
		CString csInnerUri = CLADLE_IN_BUILD_URI +_T("\\") + csInnerID;
		
		CL3RecordSetWrap rsResult;
		CString csTemp = _T(" SELECT * FROM %s WHERE InnerID = '%s'");
		CString csSQL;
		csSQL.Format(csTemp,CLADLE_IN_BUILD_URI,csInnerID);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if (rsResult.GetRowCount()> 0 )
			SetObjectPropValue(csInnerUri,_T("Build_End_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleWorkBuildStart" type="L3LONG">
/// �ְ���������/������ʼ
/// <Param name="rsLadles" type="L3LONG"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleWorkBuildStart(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
	//��������������ͨ�ְ�������ʵ��
	CL3RecordSetWrap rsComTie;
	if(!CreateClassPropSet(CLADLE_COM_TIE_URI,rsComTie))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	//�����������������ְ�������ʵ��
	CL3RecordSetWrap rsFinBuild;
	if(!CreateClassPropSet(CLADLE_FIN_BUILD_URI,rsFinBuild))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//�ְ���Ϊ��
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;

		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();
		CString csInnerID = GetObjectPropValue(csBaseUri,_T("InnerID")).ToCString(); 
		CString csOldWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		long lLadleType = GetObjectPropValue(csBaseUri,_T("LadleType")).ToLong();
		if (csInnerID == _T("")|| lLadleType == 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//û�����ò��Ż�ְ�����
		}

		int iID;
		CString csOldID;
		CString csID;
		CString csWorkID;
		CString csTemp;
		CString csSQL;
		CL3RecordSetWrap rsResult;
	
		if(csStatus == CLADLE_STATUS_INNER_FIRE)//���ò�濾
		{
			iID = 1;
			csID.Format(_T("%02d"),iID);
			csWorkID = csInnerID + csID;
		}
		else 
		{
			if(csStatus == CLADLE_STATUS_OFFLINE)
			{
		
				if(csOldWorkID == _T(""))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				csOldID = csOldWorkID.Right(2);
				iID = _ttoi(csOldID) + 1;
				csID.Format(_T("%02d"),iID);
				csWorkID = csInnerID + csID;
			}
			else
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
		}
		
		//�޸Ļ������ݼ�
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_WORK_DAUB));
		SetObjectPropValue(csBaseUri,_T("WorkID"),CL3Variant(csWorkID));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("WorkFireID"),CL3Variant((L3LONG)0));//2009-04-17
		SetObjectPropValue(csBaseUri,_T("OnFireID"),CL3Variant((L3LONG)0));

		//�޸����ò�ʹ�ô���
		CString csInnerUri = CLADLE_IN_BUILD_URI + _T("\\") + csInnerID;
		csTemp = _T(" SELECT * FROM %s WHERE InnerID = '%s'");
		csSQL.Format(csTemp,CLADLE_IN_BUILD_URI,csInnerID);
		rsResult.DeleteAll();
		if(!Query(csSQL,rsResult)||rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		long lLadle_Inner_Use_Count = 0;
		if(rsResult.GetRowCount()>0)
		{
			long lLadle_Inner_Use_Count = GetObjectPropValue(csInnerUri,_T("Ladle_Inner_Use_Count")).ToLong();
			lLadle_Inner_Use_Count++;
			SetObjectPropValue(csInnerUri,_T("Ladle_Inner_Use_Count"),CL3Variant(lLadle_Inner_Use_Count));
		}
		if(lLadle_Inner_Use_Count==0)
			lLadle_Inner_Use_Count++;
		//��������ݼ�
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
		if(lLadleType == 1)
		{
			rsComTie.AppendRecord();
			rsComTie.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsComTie.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsComTie.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
			rsComTie.SetFieldByName(_T("Tie_Start_Time"),CL3Variant(dtCurrentTime));
			rsComTie.SetFieldByName(_T("Ladle_Inner_Use_Count"),CL3Variant(lLadle_Inner_Use_Count));
			rsComTie.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsComTie.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsComTie.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		
		else if(lLadleType == 2|| lLadleType == 3)//Ϊ���߸ְ���δ�����´�����ò�
		{
			rsFinBuild.AppendRecord();
			rsFinBuild.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsFinBuild.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
			rsFinBuild.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
			rsFinBuild.SetFieldByName(_T("Build_Start_Time"),CL3Variant(dtCurrentTime));
			rsFinBuild.SetFieldByName(_T("Ladle_Inner_Use_Count"),CL3Variant(lLadle_Inner_Use_Count));
			rsFinBuild.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsFinBuild.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsFinBuild.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		rsData.MoveNext();
	}
	if(rsComTie.GetRowCount() > 0)
	{
		rsComTie.MoveFirst();
		if(CreateNewObjects(CLADLE_COM_TIE_URI,rsComTie) < rsComTie.GetRowCount())
		{
			if(bUseTrans)
					Rollback(nTrans);
			return -3;//��ӳ���ְ����ʵ��ʧ��
		}
	}
	if(rsFinBuild.GetRowCount() > 0)
	{
		rsFinBuild.MoveFirst();
		if(CreateNewObjects(CLADLE_FIN_BUILD_URI,rsFinBuild) < rsFinBuild.GetRowCount())
		{
			if(bUseTrans)
					Rollback(nTrans);
			return -4;//��Ӿ����ְ�������Ϣʧ��
		}
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleWorkBuildEnd" type="L3LONG">
/// �ְ���������/��������
/// <Param name="rsLadles" type="L3LONG"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleWorkBuildEnd(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//�ְ���Ϊ��
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		long lLadleType = GetObjectPropValue(csBaseUri,_T("LadleType")).ToLong();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;
		}
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));
		if(lLadleType == 1)
			SetObjectPropValue(CLADLE_COM_TIE_URI + _T("\\") + csWorkID,_T("Tie_End_Time"),CL3Variant(dtCurrentTime));
		
		else if(lLadleType == 2 || lLadleType == 3)
			SetObjectPropValue(CLADLE_FIN_BUILD_URI + _T("\\") + csWorkID,_T("Build_End_Time"),CL3Variant(dtCurrentTime));

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CLadle_Mag" name="LadleWorkFireStart" type="L3LONG">
/// �ְ�������濾��ʼ
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleWorkFireStart(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
	//�������������ְ�������濾ʵ��
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//�ְ���Ϊ��
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		long lWorkFireID = GetObjectPropValue(csBaseUri,_T("WorkFireID")).ToLong();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//û�й�������
		}
		lWorkFireID++;
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_WORK_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("WorkFireID"),CL3Variant(lWorkFireID));
		
		CString csFireID;
		csFireID.Format(_T("%d"),lWorkFireID);
		csFireID = csWorkID + _T("1") + csFireID;

		//��������ݼ�
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
		
		//CString csFireID = csWorkID + _T("11");//�濾��� = WorkID + 1 +1
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(csFireID));//
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
		rsFire.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
		rsFire.SetFieldByName(_T("Start_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("1")));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}

	rsFire.MoveFirst();
	if(CreateNewObjects(CLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
				Rollback(nTrans);
		return -3;//��Ӹְ�������濾��Ϣʧ��
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleWorkFireEnd" type="L3LONG">
/// �ְ�������濾����
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleWorkFireEnd(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//�ְ���Ϊ��
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		CString csWorkFireID = GetObjectPropValue(csBaseUri,_T("WorkFireID")).ToCString();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//û�й�������
		}
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_COLD));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		//�޸ĸְ�������濾����ʱ��
		if(csWorkFireID != _T("") && csWorkFireID != _T("0") )
		{
			CString csFireUri = CLADLE_FIRE_URI + _T("\\") + csWorkID + _T("1") + csWorkFireID;
			SetObjectPropValue(csFireUri,_T("End_Time"),CL3Variant(dtCurrentTime));
		}

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleHotFireStart" type="L3LONG">
/// �ְ��ȱ��濾��ʼ
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleHotFireStart(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
	
	//�������������ְ�������濾ʵ��
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//�ְ���Ϊ��
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		long lHotFireID = GetObjectPropValue(csBaseUri,_T("OnFireID")).ToLong();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//û�й�������
		}
		lHotFireID++;
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_HOT_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("OnFireID"),CL3Variant(lHotFireID));
		
		//��������ݼ�
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csFireID;
		csFireID.Format(_T("%d"),lHotFireID);
		csFireID = csWorkID + _T("2") + csFireID;
		//��Ӻ濾��¼
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(csFireID));//
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("WorkID"),CL3Variant(csWorkID));
		rsFire.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
		rsFire.SetFieldByName(_T("Start_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("2")));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}
	rsFire.MoveFirst();
	if(CreateNewObjects(CLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
				Rollback(nTrans);
		return -3;//��Ӹְ�������濾��Ϣʧ��
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleHotFireEnd" type="L3LONG">
/// �ְ��ȱ��濾����
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleHotFireEnd(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//�ְ���Ϊ��
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csBaseUri,_T("WorkID")).ToCString();
		CString csOnFireID = GetObjectPropValue(csBaseUri,_T("OnFireID")).ToCString();
		if(csWorkID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//û�й�������
		}
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_HOT));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));
		
		//�޸ĸְ�������濾����ʱ��
		if(csOnFireID != _T("") && csOnFireID != _T("0") )
		{
			CString csFireUri = CLADLE_FIRE_URI + _T("\\") + csWorkID + _T("2") + csOnFireID;
			SetObjectPropValue(csFireUri,_T("End_Time"),CL3Variant(dtCurrentTime));
		}
		
		rsData.MoveNext();
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="BOFTapingStart" type="L3BOOL">
/// ��¼ת¯���ֿ�ʼ//20081229Liao
/// <Param name="strUnitID" type="L3STRING">¯��</Param>
/// <Param name="dtTapTime" type="L3DATETIME">���ֿ�ʼʱ��</Param>
/// <Param name="strHeatID" type="L3STRING">¯��</Param>
/// </Method>
L3BOOL CLadle_Mag::BOFTapingStart(L3STRING strUnitID, L3DATETIME dtTapTime, L3STRING strHeatID)
{
	// TODO : ���ڴ�����߼�����
	CString csUnitID = strUnitID;
	CString csUnitUri = BOF_CLASS_URI + _T("\\") + csUnitID;
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return FALSE;
	}
	// �����߼�����ֻ���������� 2009-04-18
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	CL3Variant valRet =  InvokeObjectMethod(csUnitUri,_T("CaculateLadleGrade"),dtTapTime,strHeatID);
	//L3SysFreeString(strHeatID);

	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return FALSE;
	}
	if(bUseTrans)
		Commit(nTrans);
	return TRUE;
}

/// <Method class="CLadle_Mag" name="LadleThrow" type="L3LONG">
/// �ְ�˦��
/// <Param name="rsInfos" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleThrow(L3RECORDSET rsLadles)
{
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;	//�ְ���Ϊ��
		}
		CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csWorkID = GetObjectPropValue(csLadleUri,_T("WorkID")).ToCString();

		SetObjectPropValue(csLadleUri,_T("Status"),CL3Variant(CLADLE_STATUS_OFFLINE));
		
		//2009-08-22 liao
		if(csWorkID != _T(""))
		{
			CString csLadleProcessUri = CLADLE_PROCESS_URI + _T("\\") + csWorkID;
			SetObjectPropValue(csLadleProcessUri,_T("Throw_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
			SetObjectPropValue(csLadleProcessUri,_T("Comfirm_Flag"),CL3Variant(L3LONG(1)));
		}

		rsData.MoveNext();
	}
	/*rsData.MoveFirst();
	if(!SetObjsPropValues(CLADLE_BASE_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}*/
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CLadle_Mag" name="MeasureDesignate" type="L3LONG">
/// �ְ�����ָ�� 2009-04-13 liao
/// <Param name="strLadleID" type="L3STRING">�ְ���</Param>
/// </Method>
L3LONG CLadle_Mag::MeasureDesignate(L3STRING strLadleID)
{
	// TODO : ���ڴ�����߼�����
	CString csLadleID = strLadleID;
	if(csLadleID == _T(""))
		return 0;//û�иְ���
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
		
	CString csTemp = _T("SELECT LadleID,Measure_Flag from %s order by LadleID");
	CString csSQL;
	csSQL.Format(csTemp,CLADLE_BASE_URI);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	
	rsResult.MoveFirst();
	while(!rsResult.IsEOF())
	{
		CString csCurLadleID = rsResult.GetFieldByName(_T("LadleID")).ToCString();
		long lMeasureFlag = rsResult.GetFieldByName(_T("Measure_Flag")).ToLong();
		if(lMeasureFlag == 1)
		{
			CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csCurLadleID;
			if(!SetObjectPropValue(csBaseUri,_T("Measure_Flag"),L3LONG(0)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;	
			}
		}

		rsResult.MoveNext();
	}
	CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
	if(!SetObjectPropValue(csBaseUri,_T("Measure_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;	
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CLadle_Mag" name="LadleOffLineException" type="L3LONG">
/// �ְ��쳣����
/// <Param name="rsLadles" type="L3RECORDSET">���߼�¼</Param>
/// </Method>
L3LONG CLadle_Mag::LadleOffLineException(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
	if(rsData.IsNull() || rsData.GetRowCount() < 1)
		return 0;
	if(rsData.GetFieldIndex(_T("LadleID")) < 0 || rsData.GetFieldIndex(_T("Status")) < 0)
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		CString csStatus = rsData.GetFieldByName(_T("Status")).ToCString();
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;

		if(csLadleID == _T("") || csStatus == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//û�иְ��Ż�״̬
		}
	
		if(csStatus == CLADLE_STATUS_USE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//���øְ������쳣����
		}
		
		if(!SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_OFFLINE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//�޸��а�״̬ʧ��
		}

		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}


//Modify begin by llj 2011-04-09 �������ò�濾(�������ò�濾��ʼ�����ò�濾����)
/// <Method class="CLadle_Mag" name="LadleInnerFireStart" type="L3LONG">
/// �ְ����ò�濾��ʼ
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleInnerFireStart(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
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
	//�������������ְ����ò�濾ʵ��
	CL3RecordSetWrap rsFire;
	if(!CreateClassPropSet(CLADLE_FIRE_URI,rsFire))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}
	
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//�ְ���Ϊ��
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csInnerID = GetObjectPropValue(csBaseUri,_T("InnerID")).ToCString();
		long lInnerFireID = GetObjectPropValue(csBaseUri,_T("InnerFireID")).ToLong();
		if(csInnerID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//û�����ò���
		}
		lInnerFireID++;
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_INNER_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)0));
		SetObjectPropValue(csBaseUri,_T("InnerFireID"),CL3Variant(lInnerFireID));
		
		CString csFireID;
		csFireID.Format(_T("%d"),lInnerFireID);
		csFireID = csInnerID + _T("3") + csFireID;

		//��������ݼ�
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
		
		//CString csFireID = csInnerID + _T("11");//�濾��� = InnerID + �濾���� +1
		rsFire.AppendRecord();
		rsFire.SetFieldByName(_T("FireID"),CL3Variant(csFireID));//
		rsFire.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("InnerID"),CL3Variant(csInnerID));
		rsFire.SetFieldByName(_T("LadleID"),CL3Variant(csLadleID));
		rsFire.SetFieldByName(_T("Start_Time"),CL3Variant(dtCurrentTime));
		rsFire.SetFieldByName(_T("Fire_Type"),CL3Variant(_T("3")));
		rsFire.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsFire.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsFire.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));

		rsData.MoveNext();
	}

	rsFire.MoveFirst();
	if(CreateNewObjects(CLADLE_FIRE_URI,rsFire) < rsFire.GetRowCount())
	{
		if(bUseTrans)
				Rollback(nTrans);
		return -1;//��Ӹְ�������濾��Ϣʧ��
	}
	if(bUseTrans)
		Commit(nTrans);
	return 0;
}

/// <Method class="CLadle_Mag" name="LadleInnerFireEnd" type="L3LONG">
/// �ְ����ò�濾����
/// <Param name="rsLadles" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CLadle_Mag::LadleInnerFireEnd(L3RECORDSET rsLadles)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsLadles;
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
		CString csLadleID = rsData.GetFieldByName(_T("LadleID")).ToCString();
		if (csLadleID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;	//�ְ���Ϊ��
		}
		CString csBaseUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
		CString csInnerID = GetObjectPropValue(csBaseUri,_T("InnerID")).ToCString();
		CString csInnerFireID = GetObjectPropValue(csBaseUri,_T("InnerFireID")).ToCString();
		if(csInnerID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//û�����ò���
		}
		SetObjectPropValue(csBaseUri,_T("Status"),CL3Variant(CLADLE_STATUS_INNER_FIRE));
		SetObjectPropValue(csBaseUri,_T("ComFlag"),CL3Variant((L3LONG)1));

		//�޸ĸְ����ò�濾����ʱ��
		if(csInnerFireID != _T("") && csInnerFireID != _T("0") )
		{
			CString csFireUri = CLADLE_FIRE_URI + _T("\\") + csInnerID + _T("3") + csInnerFireID;
			SetObjectPropValue(csFireUri,_T("End_Time"),CL3Variant(dtCurrentTime));
		}

		rsData.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 0;
}


//Modify end
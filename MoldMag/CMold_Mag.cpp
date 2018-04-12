// �߼���CMold_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CMold_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CMold_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CMold_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CMold_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CMold_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


L3LONG CMold_Mag::UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
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
		return -1;	
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

L3LONG CMold_Mag::DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass)
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


L3RECORDSET CMold_Mag::GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition)
{
	// TODO : ���ڴ�����߼�����
	CString csCondition =lpcsCondition;
	if(csCondition == _T(""))
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


/// <Method class="CMold_Mag" name="MoldInstallStart" type="L3LONG">
/// 
/// �ᾧ��װ�俪ʼ
/// ARG &gt;&gt; rsMolds: Ҫװ�俪ʼ�Ľᾧ���ļ�¼�����������MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldInstallStart(L3RECORDSET rsMolds)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
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

	//�����޸Ľᾧ��������Ϣ�ļ�¼��[20081230]
	CStringArray BaseNames;BaseNames.SetSize(3);
	CUIntArray BaseTypes;BaseTypes.SetSize(3);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("InStallID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	
	CL3RecordSetWrap rsPipeInstall;
	if(!CreateClassPropSet(CMOLD_PIPE_INSTALL_URI,rsPipeInstall))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;//�齨ͭ��װ���¼ʧ��
	}
	
	CL3RecordSetWrap rsBoardInstall;
	if(!CreateClassPropSet(CMOLD_BOARD_INSTALL_URI,rsBoardInstall))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;//�齨ͭ��װ���¼ʧ��
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		//����ߴ�
		long lFaceMea = rsData.GetFieldByName(_T("Break_Face_Mea")).ToLong();
		//ԭװ����
		CString csOldInStallID = rsData.GetFieldByName(_T("InStallID")).ToCString();
		CString csInStallID;
		if(csMoldID == _T("")|| lFaceMea <= 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//�����ڽᾧ���Ż�û�ж���ߴ�
		}

		//����װ����
		if(csOldInStallID == _T(""))
		{
			csInStallID = csYearMonth + csMoldID + _T("01");
		}
		else
		{
			CString csOldYearMonth = csOldInStallID.Left(4);
			//����ͬ��ͬ��
			if(csOldYearMonth == csYearMonth)
			{
				CString csOldNO = csOldInStallID.Right(2);
				CString csNO;
				int iNO = _ttoi(csOldNO) + 1;
				csNO.Format(_T("%02d"),iNO);
				csInStallID = csYearMonth + csMoldID + csNO;
			}
			else
			{
				csInStallID = csYearMonth + csMoldID + _T("01");
			}
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CMOLD_STATUS_REPAIR));
		rsBase.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));

		//����װ���¼
		if (lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
		{
			CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
			CL3RecordSetWrap rpSysInfo;
			SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

			rsPipeInstall.AppendRecord();
			rsPipeInstall.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
			rsPipeInstall.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsPipeInstall.SetFieldByName(_T("Install_Date"),CL3Variant(dtCurrentTime));
			rsPipeInstall.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
			rsPipeInstall.SetFieldByName(_T("Repair_Start_Time"),CL3Variant(dtCurrentTime));
			rsPipeInstall.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsPipeInstall.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsPipeInstall.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		else if (lFaceMea == 12)
		{
			CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
			CL3RecordSetWrap rpSysInfo;
			SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

			rsBoardInstall.AppendRecord();
			rsBoardInstall.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
			rsBoardInstall.SetFieldByName(_T("Input_Time"),CL3Variant(dtCurrentTime));
			rsBoardInstall.SetFieldByName(_T("Install_Date"),CL3Variant(dtCurrentTime));
			rsBoardInstall.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
			rsBoardInstall.SetFieldByName(_T("Repair_Start_Time"),CL3Variant(dtCurrentTime));
			rsBoardInstall.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
			rsBoardInstall.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
			rsBoardInstall.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		}
		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}
	//����ͭ��װ���¼
	if (rsPipeInstall.GetRowCount() > 0)
	{
		rsPipeInstall.MoveFirst();
		CreateNewObjects(CMOLD_PIPE_INSTALL_URI,rsPipeInstall);
		/*if(CreateNewObjects(CMOLD_PIPE_INSTALL_URI,rsPipeInstall) <  1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}*/
	}
	//����ͭ��װ���¼
	if (rsBoardInstall.GetRowCount() > 0)
	{
		rsBoardInstall.MoveFirst();
		CreateNewObjects(CMOLD_BOARD_INSTALL_URI,rsBoardInstall);
		/*if(CreateNewObjects(CMOLD_BOARD_INSTALL_URI,rsBoardInstall) <  1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}*/
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="MoldInstallEnd" type="L3LONG">
/// 
/// �ᾧ��װ�����
/// ARG &gt;&gt; rsMolds: Ҫװ������Ľᾧ���ļ�¼�����������MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldInstallEnd(L3RECORDSET rsMolds)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	////�����޸Ľᾧ��������Ϣ�ļ�¼��
	//CStringArray BaseNames;BaseNames.SetSize(3);
	//CUIntArray BaseTypes;BaseTypes.SetSize(3);
	//BaseNames[0] = _T("MoldID");
	//BaseNames[1] = _T("Status");
	//BaseNames[2] = _T("InStallID");

	//BaseTypes[0] = L3VT_STRING;
	//BaseTypes[1] = L3VT_STRING;
	//BaseTypes[2] = L3VT_STRING;

	//CL3RecordSetWrap rsBase;
	//if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	//{
	//	if(bUseTrans)
	//		Rollback(nTrans);
	//	return 0;
	//}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		//����ߴ�
		long lFaceMea = rsData.GetFieldByName(_T("Break_Face_Mea")).ToLong();
		//װ����
		CString csInStallID = rsData.GetFieldByName(_T("InStallID")).ToCString();

		if(csMoldID == _T("") || lFaceMea <= 0)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//�����ڽᾧ���Ż�û�ж���ߴ�
		}
		
		SetObjectPropValue(CMOLD_BASE_URI + _T("\\") + csMoldID,_T("Status"),CL3Variant(CMOLD_STATUS_FREE));
		/*rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CMOLD_STATUS_FREE));
		rsBase.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));*/
		//�޸�װ�����ʱ��
		if (lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
		{
			CString csUri = CMOLD_PIPE_INSTALL_URI + _T("\\") + csInStallID ;
			SetObjectPropValue(csUri,_T("Repair_End_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
			//if(!SetObjectPropValue(csUri,_T("Repair_End_Time"),CL3Variant(COleDateTime::GetCurrentTime())))
			//{
			//	if(bUseTrans)
			//		Rollback(nTrans);
			//	return -2;//�޸Ĳ��ɹ�
			//}
		}
		else if (lFaceMea == 12)
		{
			CString csUri = CMOLD_BOARD_INSTALL_URI + _T("\\") + csInStallID ;
			SetObjectPropValue(csUri,_T("Repair_End_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
			//if(!SetObjectPropValue(csUri,_T("Repair_End_Time"),CL3Variant(COleDateTime::GetCurrentTime())))
			//{
			//	if(bUseTrans)
			//		Rollback(nTrans);
			//	return -2;//�޸Ĳ��ɹ�
			//}
		}
		rsData.MoveNext();
	}
	/*rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}*/
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="MoldOnLine" type="L3LONG">
/// 
/// �ᾧ�����ϲ���
/// ARG &gt;&gt; rsMolds: Ҫ���ϵĽᾧ���ļ�¼�����������MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldOnLine(L3RECORDSET rsMolds)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	//�����޸Ľᾧ��������Ϣ�ļ�¼��
	CStringArray BaseNames;BaseNames.SetSize(6);
	CUIntArray BaseTypes;BaseTypes.SetSize(6);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("Cast_ID");
	BaseNames[3] = _T("FlowID");
	BaseNames[4] = _T("Copper_Fac");
	BaseNames[5] = _T("Copper_ID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;
	BaseTypes[3] = L3VT_STRING;
	BaseTypes[4] = L3VT_STRING;
	BaseTypes[5] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	
	CL3RecordSetWrap rsPipeUse;
	if(!CreateClassPropSet(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;//�齨ͭ��ʹ�ü�¼ʧ��
	}
	
	CL3RecordSetWrap rsBoardUse;
	if(!CreateClassPropSet(CMOLD_BOARD_PAR_USE_URI,rsBoardUse))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;//�齨ͭ��ʹ�ü�¼ʧ��
	}
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csCastID = rsData.GetFieldByName(_T("Cast_ID")).ToCString();
		CString csFlowID = rsData.GetFieldByName(_T("FlowID")).ToCString();
		
		CString csBaseUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		
		long lFaceMea = GetObjectPropValue(csBaseUri,_T("Break_Face_Mea")).ToLong();//����ߴ�
		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();//�ᾧ��״̬
		CString csInStallID = GetObjectPropValue(csBaseUri,_T("InStallID")).ToCString();
		CString csCopperFac;// = rsData.GetFieldByName(_T("Copper_Fac")).ToCString();
		CString csCopperID;// = rsData.GetFieldByName(_T("Copper_ID")).ToCString();
	
		if(csMoldID == _T("") || csCastID == _T("") || csFlowID == _T("")|| csInStallID == _T("")||lFaceMea <= 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//�ᾧ���������š����š�װ����������һ��Ϊ��//����ߴ粻��ȷ
		}

		if(csStatus != CMOLD_STATUS_FREE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//�ᾧ��״̬��Ϊ�䱸
		}

		CString csTemp = _T("Select * From %s where Cast_ID = '%s' and FlowID = '%s' and Status = '%s' ");
		CString csSQL;	
		csSQL.Format(csTemp,CMOLD_BASE_URI,csCastID,csFlowID,CMOLD_STATUS_USE);
		
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if(rsResult.GetRowCount() > 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//��ǰ������ǰ�����Ѿ��нᾧ��
		}
		//����װ��ʹ�ü�¼
		if (lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
		{
			CString csTempExist =  _T("Select * From %s where InStallID = '%s' ");
			CString csSQLExist;	
			csSQLExist.Format(csTempExist,CMOLD_PIPE_PAR_USEI_URI,csInStallID);
			CL3RecordSetWrap rsResultExist;
			if(!Query(csSQLExist,rsResultExist) || rsResultExist.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}

			if (rsResultExist.GetRowCount() < 1)//�жϵ�ǰ�Ƿ����ʹ�ü�¼�������ھ������������޸�
			{
				#pragma region "����װ���¼"
				CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
				CL3RecordSetWrap rpSysInfo;
				SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
				
				CString csTempPipe = _T("Select * From %s where InStallID = '%s' ");
				CString csSQLPipe;	
				csSQLPipe.Format(csTempPipe,CMOLD_PIPE_INSTALL_URI,csInStallID);
				CL3RecordSetWrap rsResultPipe;
				if(!Query(csSQLPipe,rsResultPipe) || rsResultPipe.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				if (rsResultPipe.GetRowCount()>0)
				{
					rsResultPipe.MoveFirst();
				
					csCopperFac = rsResultPipe.GetFieldByName(_T("Copper_Fac")).ToCString();
					csCopperID = rsResultPipe.GetFieldByName(_T("Copper_ID")).ToCString();

					rsPipeUse.AppendRecord();
					rsPipeUse.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));//װ����
					rsPipeUse.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//¼������
					rsPipeUse.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));//������
					rsPipeUse.SetFieldByName(_T("FlowID"),CL3Variant(csFlowID));//����
					rsPipeUse.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));//�ᾧ����
					rsPipeUse.SetFieldByName(_T("Copper_Fac"),CL3Variant(csCopperFac));//ͭ�ܳ���
					rsPipeUse.SetFieldByName(_T("Copper_ID"),CL3Variant(csCopperID));//ͭ�ܱ��
					rsPipeUse.SetFieldByName(_T("OnLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//����ʱ��
					rsPipeUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));//���
					rsPipeUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));//���
					rsPipeUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//������Ա
				}
				#pragma endregion
			}
			else
			{
				#pragma region "�޸�װ���¼"
				CString csTempPipe = _T("Select * From %s where InStallID = '%s' ");
				CString csSQLPipe;	
				csSQLPipe.Format(csTempPipe,CMOLD_PIPE_INSTALL_URI,csInStallID);
				CL3RecordSetWrap rsResultPipe;
				if(!Query(csSQLPipe,rsResultPipe) || rsResultPipe.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				if (rsResultPipe.GetRowCount()>0)
				{
					rsResultPipe.MoveFirst();
				
					csCopperFac = rsResultPipe.GetFieldByName(_T("Copper_Fac")).ToCString();
					csCopperID = rsResultPipe.GetFieldByName(_T("Copper_ID")).ToCString();
					
					CString csPipeUri = CMOLD_PIPE_PAR_USEI_URI + _T("\\") + csInStallID;
					SetObjectPropValue(csPipeUri,_T("Cast_ID"),CL3Variant(csCastID));//������
					SetObjectPropValue(csPipeUri,_T("FlowID"),CL3Variant(csFlowID));//����
					SetObjectPropValue(csPipeUri,_T("MoldID"),CL3Variant(csMoldID));//�ᾧ����
					SetObjectPropValue(csPipeUri,_T("Copper_Fac"),CL3Variant(csCopperFac));//ͭ�ܳ���
					SetObjectPropValue(csPipeUri,_T("Copper_ID"),CL3Variant(csCopperID));//ͭ�ܱ��
				}
			}
			#pragma endregion

		}
		else if (lFaceMea == 12)//��Ż�
		{
			CString csTempExist =  _T("Select * From %s where InStallID = '%s' ");
			CString csSQLExist;	
			csSQLExist.Format(csTempExist,CMOLD_BOARD_PAR_USE_URI,csInStallID);
			CL3RecordSetWrap rsResultExist;
			if(!Query(csSQLExist,rsResultExist) || rsResultExist.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			if (rsResultExist.GetRowCount() < 1)//�жϵ�ǰ�Ƿ����ʹ�ü�¼�������ھ������������޸�
			{
				#pragma region
				CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
				CL3RecordSetWrap rpSysInfo;
				SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

				CString csTempBoard = _T("Select * From %s where InStallID = '%s' ");
				CString csSQLBoard;	
				csSQLBoard.Format(csTempBoard,CMOLD_BOARD_INSTALL_URI,csInStallID);
				CL3RecordSetWrap rsResultBoard;
				if(!Query(csSQLBoard,rsResultBoard) || rsResultBoard.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				if (rsResultBoard.GetRowCount()>0)
				{
					rsResultBoard.MoveFirst();
					
					csCopperFac = rsResultBoard.GetFieldByName(_T("Copper_Fac")).ToCString();
					csCopperID = rsResultBoard.GetFieldByName(_T("Inner_ID")).ToCString() + _T("*") + rsResultBoard.GetFieldByName(_T("Outer_ID")).ToCString() + _T("*")
						+ rsResultBoard.GetFieldByName(_T("South_ID")).ToCString() + _T("*") + rsResultBoard.GetFieldByName(_T("North_ID")).ToCString() ;

					rsBoardUse.AppendRecord();
					rsBoardUse.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));//װ����
					rsBoardUse.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//¼������
					rsBoardUse.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));//������
					rsBoardUse.SetFieldByName(_T("FlowID"),CL3Variant(csFlowID));//����
					rsBoardUse.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));//�ᾧ����
					
					rsBoardUse.SetFieldByName(_T("Inner_ID"),rsResultBoard.GetFieldByName(_T("Inner_ID")));//ͭ���ڻ����
					rsBoardUse.SetFieldByName(_T("Outer_ID"),rsResultBoard.GetFieldByName(_T("Outer_ID")));//ͭ���⻡���
					rsBoardUse.SetFieldByName(_T("South_ID"),rsResultBoard.GetFieldByName(_T("South_ID")));//ͭ���ϲ���
					rsBoardUse.SetFieldByName(_T("North_ID"),rsResultBoard.GetFieldByName(_T("North_ID")));//ͭ�山����
					rsBoardUse.SetFieldByName(_T("Copper_Fac"),rsResultBoard.GetFieldByName(_T("Copper_Fac")));//ͭ�ܳ���
					rsBoardUse.SetFieldByName(_T("Lug_Steel_Mea"),rsResultBoard.GetFieldByName(_T("Lug_Steel_Mea")));//ͨ����
					rsBoardUse.SetFieldByName(_T("Total_Pull_Mea"),rsResultBoard.GetFieldByName(_T("Lug_Steel_Mea")));//ͨ����

					rsBoardUse.SetFieldByName(_T("OnLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//����ʱ��
					rsBoardUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));//���
					rsBoardUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));//���
					rsBoardUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//������Ա

					
				}

				#pragma endregion
			}
			else
			{
				CString csTempBoard = _T("Select * From %s where InStallID = '%s' ");
				CString csSQLBoard;	
				csSQLBoard.Format(csTempBoard,CMOLD_BOARD_INSTALL_URI,csInStallID);
				CL3RecordSetWrap rsResultBoard;
				if(!Query(csSQLBoard,rsResultBoard) || rsResultBoard.IsNull())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				if (rsResultBoard.GetRowCount()>0)
				{
					rsResultBoard.MoveFirst();
					
					csCopperFac = rsResultBoard.GetFieldByName(_T("Copper_Fac")).ToCString();
					csCopperID = rsResultBoard.GetFieldByName(_T("Inner_ID")).ToCString() + _T("*") + rsResultBoard.GetFieldByName(_T("Outer_ID")).ToCString() + _T("*")
						+ rsResultBoard.GetFieldByName(_T("South_ID")).ToCString() + _T("*") + rsResultBoard.GetFieldByName(_T("North_ID")).ToCString() ;

					CString csBoardUri = CMOLD_BOARD_PAR_USE_URI + _T("\\") + csInStallID;

					SetObjectPropValue(csBoardUri,_T("Cast_ID"),CL3Variant(csCastID));//������
					SetObjectPropValue(csBoardUri,_T("FlowID"),CL3Variant(csFlowID));//����
					//SetObjectPropValue(csBoardUri,_T("MoldID"),CL3Variant(csMoldID));//�ᾧ����
					//SetObjectPropValue(csBoardUri,_T("Inner_ID"),rsResultBoard.GetFieldByName(_T("Inner_ID")));//ͭ���ڻ����
					//SetObjectPropValue(csBoardUri,_T("Outer_ID"),rsResultBoard.GetFieldByName(_T("Outer_ID")));//ͭ���⻡���
					//SetObjectPropValue(csBoardUri,_T("South_ID"),rsResultBoard.GetFieldByName(_T("South_ID")));//ͭ���ϲ���
					//SetObjectPropValue(csBoardUri,_T("North_ID"),rsResultBoard.GetFieldByName(_T("North_ID")));//ͭ�山����
					//SetObjectPropValue(csBoardUri,_T("Copper_Fac"),rsResultBoard.GetFieldByName(_T("Copper_Fac")));//ͭ�ܳ���
					//SetObjectPropValue(csBoardUri,_T("Lug_Steel_Mea"),rsResultBoard.GetFieldByName(_T("Lug_Steel_Mea")));//ͭ��������
				}
			}

			//Modify begin by llj 2011-04-114 �޸Ľᾧ��ͭ���ͨ����
			CString csSql;
			csSql.Format(_T("select Total_Weight from %s where Copper_ID='%s' ordery by Stop_Time desc " ),CCM_HEAT_STRANDINFO_CLASS_URI,csCopperID);
			CL3RecordSetWrap rsHeatStandInfo;
			if(Query(csSql,rsHeatStandInfo)&&!rsHeatStandInfo.IsNull()&&rsHeatStandInfo.GetRowCount()>0)
			{
				rsHeatStandInfo.MoveFirst();
				CString csCCMMagUri =  CCM_CLASS_URI+_T("\\")+csCastID;
				CString csSunCastWeightNo=_T("SumCastWeight")+csFlowID+_T("st");
				SetObjectPropValue(csCCMMagUri,csSunCastWeightNo,rsHeatStandInfo.GetFieldByName(_T("Total_Weight")));
			}
			//Modify end


		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CMOLD_STATUS_USE));
		rsBase.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));
		rsBase.SetFieldByName(_T("FlowID"),CL3Variant(csFlowID));
		rsBase.SetFieldByName(_T("Copper_Fac"),CL3Variant(csCopperFac));
		rsBase.SetFieldByName(_T("Copper_ID"),CL3Variant(csCopperID));

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}
	//����ͭ��ʹ�ü�¼
	if (rsPipeUse.GetRowCount() > 0)
	{
		rsPipeUse.MoveFirst();
		CreateNewObjects(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse);

		/*if(CreateNewObjects(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse) <  1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}*/
	}
	//����ͭ��ʹ�ü�¼
	if (rsBoardUse.GetRowCount() > 0)
	{
		rsBoardUse.MoveFirst();
		CreateNewObjects(CMOLD_BOARD_PAR_USE_URI,rsBoardUse);
		/*if(CreateNewObjects(CMOLD_BOARD_PAR_USE_URI,rsBoardUse) <  1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;				
		}*/
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="MoldOffLine" type="L3LONG">
/// 
/// �ᾧ�����²������
/// ARG &gt;&gt; rsMolds: Ҫ���µĽᾧ���ļ�¼�����������MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldOffLine(L3RECORDSET rsMolds)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
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
		//2009-06-04
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		
		CString csBaseUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		
		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();//�ᾧ��״̬
		CString csInStallID = GetObjectPropValue(csBaseUri,_T("InStallID")).ToCString();
		
		CString csCastID = GetObjectPropValue(csBaseUri,_T("Cast_ID")).ToCString();
		CString csFlowID = GetObjectPropValue(csBaseUri,_T("FlowID")).ToCString();

		if(csMoldID == _T("") || csCastID == _T("") || csFlowID == _T("")|| csInStallID == _T("") )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//�ᾧ���������š����š�װ����������һ��Ϊ��//����ߴ粻��ȷ
		}
		if(csStatus != CMOLD_STATUS_USE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//״̬��Ϊʹ��
		}
		//�޸Ľᾧ��������Ϣ
		CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID ;

		if(!SetObjectPropValue(csUri,_T("Status"),CL3Variant(CMOLD_STATUS_OFFLINE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//�޸�״̬ʧ��
		}

		//�����������Uri
		CString csCCMUnitUri = CCM_CLASS_URI + _T("\\") + csCastID ;
		double dHeatWeight = 0;
		int iFlowID = _ttoi(csFlowID);
		switch (iFlowID)
		{
			case 1:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight1st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight1st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -4;//�޸������ۼ�ͨ����ʧ��
				}
				break;
			case 2:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight2st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight2st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				}
				break;
			case 3:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight3st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight3st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				}
				break;
			case 4:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight4st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight4st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -4;
				}
				break;
		}
		
		try
		{
			if(dHeatWeight > 0.0)
			{
				CString csBoardUri = CMOLD_BOARD_PAR_USE_URI + _T("\\") + csInStallID ;

				double dLug_Steel_Mea = GetObjectPropValue(csBoardUri,_T("Total_Pull_Mea")).ToDouble();
				dHeatWeight = dHeatWeight + dLug_Steel_Mea;
				
				SetObjectPropValue(csBoardUri,_T("Total_Pull_Mea"),CL3Variant(dHeatWeight));
			}
		}
		catch(...)
		{}
		
		/************************************************************************************************/
		//�����ᾧ������¼ 2009-08-20 liao
		CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
		CL3RecordSetWrap rpSysInfo;
		SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

		CString csSQL;
		csSQL.Format(_T("select * from %s where InstallID = '%s'"),CMOLD_BOARD_INSTALL_URI,csInStallID);
		
		CL3RecordSetWrap rsMoldInstall;
		Query(csSQL,rsMoldInstall);

		CL3RecordSetWrap rsMoldCheck;
		if(!CreateClassPropSet(_T("XGMESLogic\\MoldMag\\CMold_Board_Check"),rsMoldCheck))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
	
		if(rsMoldInstall.GetRowCount() > 0)
		{
			rsMoldCheck.CopyFrom(rsMoldInstall);
		}
		else
		{
			rsMoldCheck.AppendRecord();
			rsMoldCheck.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
			rsMoldCheck.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
		}
		rsMoldCheck.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsMoldCheck.SetFieldByName(_T("Check_Date"),CL3Variant(COleDateTime::GetCurrentTime()));
		rsMoldCheck.SetFieldByName(_T("Lug_Steel_Mea"),CL3Variant(dHeatWeight));
		rsMoldCheck.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsMoldCheck.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsMoldCheck.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		rsMoldCheck.SetFieldByName(_T("Note"),CL3Variant(_T("")));

		rsMoldCheck.MoveFirst();
		CreateNewObjects(_T("XGMESLogic\\MoldMag\\CMold_Board_Check"),rsMoldCheck);
		/************************************************************************************************/
	
		rsData.MoveNext();
	}
	
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CMold_Mag" name="MoldCheckCold" type="L3LONG">
/// �ᾧ����������Ϊ����
/// <Param name="dsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldCheckCold(L3RECORDSET dsMolds)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = dsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	//�����޸Ľᾧ��������Ϣ�ļ�¼��
	CStringArray BaseNames;BaseNames.SetSize(2);
	CUIntArray BaseTypes;BaseTypes.SetSize(2);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	/*BaseNames[2] = _T("Cast_ID");
	BaseNames[3] = _T("FlowID");
	BaseNames[4] = _T("Copper_Fac");
	BaseNames[5] = _T("Copper_ID");*/

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	/*BaseTypes[2] = L3VT_STRING;
	BaseTypes[3] = L3VT_STRING;
	BaseTypes[4] = L3VT_STRING;
	BaseTypes[5] = L3VT_STRING;*/

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID"));
		if(csMoldID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Status"),CL3Variant(CMOLD_STATUS_FREE));
		rsBase.SetFieldByName(_T("Cast_ID"),CL3Variant(CMOLD_STATUS_FREE));
		rsBase.SetFieldByName(_T("FlowID"),CL3Variant(CMOLD_STATUS_FREE));

		rsData.MoveNext();
	}
	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;

}

/// <Method class="CMold_Mag" name="MoldCheckBuild" type="L3LONG">
/// �ᾧ����������Ϊ��װ
/// <Param name="dsMolds" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::MoldCheckBuild(L3RECORDSET dsMolds)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = dsMolds;
	if(rsData.IsNull()||rsData.GetRowCount() < 1)
	{
		return 0;
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	//�����޸Ľᾧ��������Ϣ�ļ�¼��
	CStringArray BaseNames;BaseNames.SetSize(6);
	CUIntArray BaseTypes;BaseTypes.SetSize(6);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("Cast_ID");
	BaseNames[3] = _T("FlowID");
	BaseNames[4] = _T("Copper_Fac");
	BaseNames[5] = _T("Copper_ID"); 

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;
	BaseTypes[3] = L3VT_STRING;
	BaseTypes[4] = L3VT_STRING;
	BaseTypes[5] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		
		CString csBaseUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		
		long lFaceMea = GetObjectPropValue(csBaseUri,_T("Break_Face_Mea")).ToLong();//����ߴ�
		CString csStatus = GetObjectPropValue(csBaseUri,_T("Status")).ToCString();//�ᾧ��״̬
		CString csInStallID = GetObjectPropValue(csBaseUri,_T("InStallID")).ToCString();
		
		CString csCastID = GetObjectPropValue(csBaseUri,_T("Cast_ID")).ToCString();
		CString csFlowID = GetObjectPropValue(csBaseUri,_T("FlowID")).ToCString();
		CString csCopperFac = GetObjectPropValue(csBaseUri,_T("Copper_Fac")).ToCString();
		CString csCopperID = GetObjectPropValue(csBaseUri,_T("Copper_ID")).ToCString();

		if(csMoldID == _T("") || csCastID == _T("") || csFlowID == _T("")|| csInStallID == _T("")|| lFaceMea <= 0 )
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//�ᾧ���������š����š�װ����������һ��Ϊ��//����ߴ粻��ȷ
		}
		if(csStatus != CMOLD_STATUS_USE && csStatus != CMOLD_STATUS_OFFLINE)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//״̬��Ϊʹ��
		}
		//�޸Ľᾧ��������Ϣ
		CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID ;
		SetObjectPropValue(csUri,_T("Status"),CL3Variant(CMOLD_STATUS_WAIT));
		SetObjectPropValue(csUri,_T("Cast_ID"),CL3Variant(_T("")));
		SetObjectPropValue(csUri,_T("FlowID"),CL3Variant(_T("")));
		SetObjectPropValue(csUri,_T("Copper_Fac"),CL3Variant(_T("")));
		SetObjectPropValue(csUri,_T("Copper_ID"),CL3Variant(_T("")));

		//�����������Uri
		CString csCCMUnitUri = CCM_CLASS_URI + _T("\\") + csCastID ;
		double dHeatWeight = 0;
		int iFlowID = _ttoi(csFlowID);
		switch (iFlowID)
		{
			case 1:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight1st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight1st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				break;
			case 2:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight2st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight2st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				break;
			case 3:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight3st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight3st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				break;
			case 4:
				dHeatWeight = GetObjectPropValue(csCCMUnitUri,_T("SumCastWeight4st")).ToDouble();
				if(!SetObjectPropValue(csCCMUnitUri,_T("SumCastWeight4st"),CL3Variant(0)))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;
				}
				break;
		}
		
		//����ʹ����Ϣ
		if (lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
		{
			CString csPipeUri = CMOLD_PIPE_PAR_USEI_URI + _T("\\") + csInStallID ;
		
			//2009-04-13
			SetObjectPropValue(csPipeUri,_T("Total_Pull_Mea"),CL3Variant(dHeatWeight));
			SetObjectPropValue(csPipeUri,_T("OffLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		
		}
		else if (lFaceMea == 12)//��Ż�
		{
			//ֻ�޸�����ʱ�䣬ͨ���������߼���ʱ����� 2009-06-04
			CString csBoardUri = CMOLD_BOARD_PAR_USE_URI + _T("\\") + csInStallID ;
			
			//double dLug_Steel_Mea = GetObjectPropValue(csBoardUri,_T("Lug_Steel_Mea")).ToDouble();

			//dHeatWeight = dHeatWeight + dLug_Steel_Mea;//=
			////2009-04-13
			//SetObjectPropValue(csBoardUri,_T("Total_Pull_Mea"),CL3Variant(dHeatWeight));
			SetObjectPropValue(csBoardUri,_T("OffLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));
		}
		
		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}


/// <Method class="CMold_Mag" name="InsertPipeInstallInfo" type="L3LONG">
/// 
/// ���ͭ��װ��ʵ��
/// ARG &gt;&gt; rsPipeInstalls: Ҫ��ӵ�ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::InsertPipeInstallInfo(L3RECORDSET rsPipeInstalls)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsPipeInstalls;
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

	//�����޸Ľᾧ��������Ϣ�ļ�¼��[20081230]
	CStringArray BaseNames;BaseNames.SetSize(3);
	CUIntArray BaseTypes;BaseTypes.SetSize(3);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Copper_Fac");
	BaseNames[2] = _T("Copper_ID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csCopperFac = rsData.GetFieldByName(_T("Copper_Fac")).ToCString();
		CString csCopperID = rsData.GetFieldByName(_T("Copper_ID")).ToCString();
		CString csInStallID = GetObjectPropValue(CMOLD_BASE_URI + _T("\\") + csMoldID,_T("InStallID")).ToCString();
		
		if(csMoldID == _T("")||csInStallID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//�ᾧ���Ż�װ����Ϊ��
		}

		CString csTemp = _T(" select * from %s where InStallID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CMOLD_PIPE_INSTALL_URI,csInStallID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//��ѯװ���¼ʧ��
		}
		if(rsResult.GetRowCount() > 0 )//��ǰ����װ���¼
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//��ǰ����װ���¼������������
		}
		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Copper_Fac"),CL3Variant(csCopperFac));
		rsBase.SetFieldByName(_T("Copper_ID"),CL3Variant(csCopperID));

		rsData.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CMOLD_PIPE_INSTALL_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}

	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="UpdatePipeInstallInfo" type="L3LONG">
/// 
/// �޸�ͭ��װ��ʵ��
/// ARG &gt;&gt; rsPipeInstalls: Ҫ�޸ĵ�ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::UpdatePipeInstallInfo(L3RECORDSET rsPipeInstalls)
{
	// TODO : ���ڴ�����߼�����
	return UpdateInfos(rsPipeInstalls,CMOLD_PIPE_INSTALL_URI);
}

/// <Method class="CMold_Mag" name="DeletePipeInstallInfo" type="L3LONG">
/// 
/// ɾ��ͭ��װ��ʵ��
/// ARG &gt;&gt; rsPipeInstalls: Ҫɾ����ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::DeletePipeInstallInfo(L3RECORDSET rsPipeInstalls)
{
	// TODO : ���ڴ�����߼�����
	return DeleteInfos(rsPipeInstalls,CMOLD_PIPE_INSTALL_URI);
}

/// <Method class="CMold_Mag" name="GetPipeInstallInfo" type="L3RECORDSET">
/// 
/// ��ȡͭ��װ��ʵ��
/// ARG &gt;&gt; strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����rsPipeInstalls��ʧ�ܷ���null��
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CMold_Mag::GetPipeInstallInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CMOLD_PIPE_INSTALL_URI,strCondition);
}

/// <Method class="CMold_Mag" name="InsertBoardInstallInfo" type="L3LONG">
/// 
/// ���ͭ��װ��ʵ��
/// ARG &gt;&gt; rsBoardInstalls: Ҫ��ӵ�ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::InsertBoardInstallInfo(L3RECORDSET rsBoardInstalls)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsBoardInstalls;
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

	//�����޸Ľᾧ��������Ϣ�ļ�¼��
	CStringArray BaseNames;BaseNames.SetSize(3);
	CUIntArray BaseTypes;BaseTypes.SetSize(3);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Copper_Fac");
	BaseNames[2] = _T("Copper_ID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csCopperFac = rsData.GetFieldByName(_T("Copper_Fac")).ToCString();
		
		CString csInnerID = rsData.GetFieldByName(_T("Inner_ID")).ToCString();
		CString csOuterID = rsData.GetFieldByName(_T("Outer_ID")).ToCString();
		CString csSouthID = rsData.GetFieldByName(_T("South_ID")).ToCString();
		CString csNorthID = rsData.GetFieldByName(_T("North_ID")).ToCString();
		
		CString csInStallID = GetObjectPropValue(CMOLD_BASE_URI + _T("\\") + csMoldID,_T("InStallID")).ToCString();

		CString csCopperID = csInnerID + _T("*") + csOuterID + _T("*") + csSouthID  + _T("*") + csNorthID;

		if(csMoldID == _T("") || csInStallID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//�ᾧ���Ż�װ����Ϊ��
		}
		
		CString csTemp = _T(" select * from %s where InStallID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CMOLD_BOARD_INSTALL_URI,csInStallID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//��ѯװ���¼ʧ��
		}
		if(rsResult.GetRowCount() > 0 )//��ǰ����װ���¼
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//��ǰ����װ���¼������������
		}
		rsData.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));

		rsBase.AppendRecord();
		rsBase.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));
		rsBase.SetFieldByName(_T("Copper_Fac"),CL3Variant(csCopperFac));
		rsBase.SetFieldByName(_T("Copper_ID"),CL3Variant(csCopperID));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CMOLD_BOARD_INSTALL_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}

	rsBase.MoveFirst();
	if(!SetObjsPropValues(CMOLD_BASE_URI,rsBase))
	{
		if(bUseTrans)
				Rollback(nTrans);
			return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="UpdateBoardInstallInfo" type="L3LONG">
/// 
/// �޸�ͭ��װ��ʵ��
/// ARG &gt;&gt; rsBoardInstalls: Ҫ�޸ĵ�ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::UpdateBoardInstallInfo(L3RECORDSET rsBoardInstalls)
{
	// TODO : ���ڴ�����߼�����
	return UpdateInfos(rsBoardInstalls,CMOLD_BOARD_INSTALL_URI);
}

/// <Method class="CMold_Mag" name="DeleteBoardInstallInfo" type="L3LONG">
/// 
/// ɾ��ͭ��װ��ʵ��
/// ARG &gt;&gt; rsBoardInstalls: Ҫɾ����ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::DeleteBoardInstallInfo(L3RECORDSET rsBoardInstalls)
{
	// TODO : ���ڴ�����߼�����
	return DeleteInfos(rsBoardInstalls,CMOLD_BOARD_INSTALL_URI);
}

/// <Method class="CMold_Mag" name="GetBoardInstallInfo" type="L3RECORDSET">
/// 
/// ��ȡͭ��װ��ʵ��
/// ARG &gt;&gt; strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����rsBoardInstalls:��ʧ�ܷ���null��
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CMold_Mag::GetBoardInstallInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CMOLD_BOARD_INSTALL_URI,strCondition);
}

/// <Method class="CMold_Mag" name="InsertPipeUseInfo" type="L3LONG">
/// 
/// ���ͭ��ʹ��ʵ��
/// ARG &gt;&gt; rsPipeUses: Ҫ��ӵ�ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::InsertPipeUseInfo(L3RECORDSET rsPipeUses)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsPipeUses;
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
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		
		CString csFac = GetObjectPropValue(csUri ,_T("Copper_Fac")).ToCString();
		CString csID = GetObjectPropValue(csUri ,_T("Copper_ID")).ToCString();
		CString csInStallID = GetObjectPropValue(csUri,_T("InStallID")).ToCString();

		if(csMoldID == _T("")||csInStallID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//�ᾧ���Ż�װ����Ϊ��
		}

		CString csTemp = _T(" select * from %s where InStallID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CMOLD_PIPE_PAR_USEI_URI,csInStallID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//��ѯװ���¼ʧ��
		}
		if(rsResult.GetRowCount() > 0 )//��ǰ����װ���¼
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//��ǰ����װ���¼������������
		}

		rsData.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
		rsData.SetFieldByName(_T("Copper_Fac"),CL3Variant(csFac));
		rsData.SetFieldByName(_T("Copper_ID"),CL3Variant(csID));

		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CMOLD_PIPE_PAR_USEI_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="UpdatePipeUseInfo" type="L3LONG">
/// 
/// �޸�ͭ��ʹ��ʵ��
/// ARG &gt;&gt; rsPipeUses: Ҫ�޸ĵ�ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::UpdatePipeUseInfo(L3RECORDSET rsPipeUses)
{
	// TODO : ���ڴ�����߼�����
	return UpdateInfos(rsPipeUses,CMOLD_PIPE_PAR_USEI_URI);
}

/// <Method class="CMold_Mag" name="DeletePipeUseInfo" type="L3LONG">
/// 
/// ɾ��ͭ��ʹ��ʵ��
/// ARG &gt;&gt; rsPipeUses: Ҫɾ����ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::DeletePipeUseInfo(L3RECORDSET rsPipeUses)
{
	// TODO : ���ڴ�����߼�����
	return DeleteInfos(rsPipeUses,CMOLD_PIPE_PAR_USEI_URI);
}

/// <Method class="CMold_Mag" name="GetPipeUseInfo" type="L3RECORDSET">
/// 
/// ��ȡͭ��װ��ʵ��
/// ARG &gt;&gt; strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����rsPipeUses��ʧ�ܷ���null��
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CMold_Mag::GetPipeUseInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CMOLD_PIPE_PAR_USEI_URI,strCondition);
}

/// <Method class="CMold_Mag" name="InsertBoardUseInfo" type="L3LONG">
/// 
/// ���ͭ��ʹ��ʵ��
/// ARG &gt;&gt; rsBoardUses: Ҫ��ӵ�ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���0��
/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::InsertBoardUseInfo(L3RECORDSET rsBoardUses)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = rsBoardUses;
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
		CString csMoldID = rsData.GetFieldByName(_T("MoldID")).ToCString();
		CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
		CString csFac = GetObjectPropValue(csUri ,_T("Copper_Fac")).ToCString();
		CString csID = GetObjectPropValue(csUri ,_T("Copper_ID")).ToCString();//0000*11111*2222*33333
		
		CString csInStallID = GetObjectPropValue(csUri,_T("InStallID")).ToCString();

		if(csMoldID == _T("")||csInStallID == _T(""))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -1;//�ᾧ���Ż�װ����Ϊ��
		}

		CString csTemp = _T(" select * from %s where InStallID = '%s' ");
		CString csSQL;
		csSQL.Format(csTemp,CMOLD_BOARD_PAR_USE_URI,csInStallID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;//��ѯװ���¼ʧ��
		}
		if(rsResult.GetRowCount() > 0 )//��ǰ����װ���¼
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;//��ǰ����װ���¼������������
		}

		int iPosition = csID.FindOneOf(_T("*"));
		CString csInnerID = csID.Left(iPosition);
		csID = csID.Right(csID.GetLength() - iPosition - 1);
		
		iPosition = csID.FindOneOf(_T("*"));
		CString csOuterID = csID.Left(iPosition);
		csID = csID.Right(csID.GetLength() - iPosition - 1);

		iPosition = csID.FindOneOf(_T("*"));
		CString csSouthID = csID.Left(iPosition);
		csID = csID.Right(csID.GetLength() - iPosition - 1);

		CString csNorthID = csID;

		rsData.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));
		rsData.SetFieldByName(_T("Copper_Fac"),CL3Variant(csFac));
		rsData.SetFieldByName(_T("Inner_ID"),CL3Variant(csInnerID));
		rsData.SetFieldByName(_T("Outer_ID"),CL3Variant(csOuterID));
		rsData.SetFieldByName(_T("South_ID"),CL3Variant(csSouthID));
		rsData.SetFieldByName(_T("North_ID"),CL3Variant(csNorthID));
		rsData.MoveNext();
	}

	rsData.MoveFirst();
	if(CreateNewObjects(CMOLD_BOARD_PAR_USE_URI,rsData) <  1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;				
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}

/// <Method class="CMold_Mag" name="UpdateBoardUseInfo" type="L3LONG">
/// 
/// �޸�ͭ��ʹ��ʵ��
/// ARG &gt;&gt; rsBoardUses: Ҫ�޸ĵ�ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::UpdateBoardUseInfo(L3RECORDSET rsBoardUses)
{
	// TODO : ���ڴ�����߼�����
	return UpdateInfos(rsBoardUses,CMOLD_BOARD_PAR_USE_URI);
}

/// <Method class="CMold_Mag" name="DeleteBoardUseInfo" type="L3LONG">
/// 
/// ɾ��ͭ��ʹ��ʵ��
/// ARG &gt;&gt; rsBoardUses: Ҫɾ����ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CMold_Mag::DeleteBoardUseInfo(L3RECORDSET rsBoardUses)
{
	// TODO : ���ڴ�����߼�����
	return DeleteInfos(rsBoardUses,CMOLD_BOARD_PAR_USE_URI);
}

/// <Method class="CMold_Mag" name="GetBoardUseInfo" type="L3RECORDSET">
/// 
/// ��ȡͭ��װ��ʵ��
/// ARG &gt;&gt; strCondition: ��ѯ����
/// RET &lt;&lt; �ɹ�����rsBoardUses��ʧ�ܷ���null��
/// <Param name="strCondition" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CMold_Mag::GetBoardUseInfo(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	return GetInfos(CMOLD_BOARD_PAR_USE_URI,strCondition);
}


/// <Method class="CMold_Mag" name="MoldChangeFlowID" type="L3LONG">
/// 
/// ������
/// ARG &gt;&gt; dsMolds: Ҫ�޸ĵ�ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="strMoldID" type="L3STRING"></Param>
/// <Param name="strNewFlowID" type="L3STRING"></Param>
/// </Method>
L3LONG CMold_Mag::MoldChangeFlowID(L3STRING strMoldID,L3STRING strNewFlowID)
{
	// TODO : ���ڴ�����߼�����
	CString csMoldID = strMoldID;
	CString csNewFlowID  = strNewFlowID;
	if(csMoldID == _T("")|| csNewFlowID == _T(""))
		return 0;//�����ڽᾧ���ţ�����û��ѡ��������
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}
	COleDateTime dtCurrentTime = COleDateTime::GetCurrentTime();

	//CL3RecordSetWrap rsBase;
	//if(!CreateClassPropSet(CMOLD_BASE_URI,rsBase))
	//{
	//	if(bUseTrans)
	//		Rollback(nTrans);
	//	return 0;//�齨ͭ��װ���¼ʧ��
	//}

	//�����޸Ľᾧ��������Ϣ�ļ�¼��
	CStringArray BaseNames;BaseNames.SetSize(6);
	CUIntArray BaseTypes;BaseTypes.SetSize(6);
	BaseNames[0] = _T("MoldID");
	BaseNames[1] = _T("Status");
	BaseNames[2] = _T("Cast_ID");
	BaseNames[3] = _T("FlowID");
	BaseNames[4] = _T("Copper_Fac");
	BaseNames[5] = _T("Copper_ID");

	BaseTypes[0] = L3VT_STRING;
	BaseTypes[1] = L3VT_STRING;
	BaseTypes[2] = L3VT_STRING;
	BaseTypes[3] = L3VT_STRING;
	BaseTypes[4] = L3VT_STRING;
	BaseTypes[5] = L3VT_STRING;

	CL3RecordSetWrap rsBase;
	if(!CreateRecordSet(BaseNames,BaseTypes,rsBase)||rsBase.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	CString csUri = CMOLD_BASE_URI + _T("\\") + csMoldID;
	//����ߴ�
	long lFaceMea = GetObjectPropValue(csUri,_T("Break_Face_Mea")).ToLong();
	//װ����
	CString csInStallID = GetObjectPropValue(csUri,_T("InStallID")).ToCString();
	//�ᾧ��״̬
	CString csStatus = GetObjectPropValue(csUri,_T("Status")).ToCString();
	CString csCastID =GetObjectPropValue(csUri,_T("Cast_ID")).ToCString(); 
	CString csOldFlowID =GetObjectPropValue(csUri,_T("FlowID")).ToCString(); 
	
	if( lFaceMea <= 0 || csInStallID == _T("") || csOldFlowID == csNewFlowID)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;//û�ж���ߴ��û��װ���Ż����������ԭ������ͬ
	}
	//�жϵ�ǰ�����Ƿ���Ч
	CString csTemp = _T("Select Count(*) as Mold_Count from %s where Cast_ID = '%s' and FlowID = '%s' and Status = '%s'");
	CString csSQL;	
	csSQL.Format(csTemp,CMOLD_BASE_URI,csCastID,csNewFlowID,CMOLD_STATUS_USE);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	rsResult.MoveFirst();
	long lCount = rsResult.GetFieldByName(_T("Mold_Count")).ToLong();
	if (lCount > 0 )
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//��ǰ����������ԭ������ѡ�����ϴ��ڽᾧ��
	}
	//�޸Ļ�����Ϣ������
	SetObjectPropValue(csUri,_T("FlowID"),CL3Variant(csNewFlowID));
	//�޸�ʹ�ü�¼������ͱ�ע
	if(lFaceMea == 8 ||lFaceMea == 9||lFaceMea == 16 ||lFaceMea == 18)//modify by hyh 2012-06-15
	{
		CString csTempExist =  _T("Select * From %s where InStallID = '%s' ");
		CString csSQLExist;	
		csSQLExist.Format(csTempExist,CMOLD_PIPE_PAR_USEI_URI,csInStallID);
		CL3RecordSetWrap rsResultExist;
		if(!Query(csSQLExist,rsResultExist) || rsResultExist.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if (rsResultExist.GetRowCount() < 1 )//������ʹ�ü�¼,������û�в������˹�ɾ��
		{
			CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
			CL3RecordSetWrap rpSysInfo;
			SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
			
			CString csTempPipe = _T("Select * From %s where InStallID = '%s' ");
			CString csSQLPipe;	
			csSQLPipe.Format(csTempPipe,CMOLD_PIPE_INSTALL_URI,csInStallID);
			CL3RecordSetWrap rsResultPipe;
			if(!Query(csSQLPipe,rsResultPipe) || rsResultPipe.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			if (rsResultPipe.GetRowCount()>0)
			{
				rsResultPipe.MoveFirst();
			
				CL3RecordSetWrap rsPipeUse;
				if(!CreateClassPropSet(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse))
				{
					if(bUseTrans)
						Rollback(nTrans);
					return 0;//�齨ͭ��ʹ�ü�¼ʧ��
				}

				rsPipeUse.AppendRecord();
				rsPipeUse.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));//װ����
				rsPipeUse.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//¼������
				rsPipeUse.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));//������
				rsPipeUse.SetFieldByName(_T("FlowID"),CL3Variant(csNewFlowID));//����
				rsPipeUse.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));//�ᾧ����
				rsPipeUse.SetFieldByName(_T("Copper_Fac"),rsResultPipe.GetFieldByName(_T("Copper_Fac")));//ͭ�ܳ���
				rsPipeUse.SetFieldByName(_T("Copper_ID"),rsResultPipe.GetFieldByName(_T("Copper_ID")));//ͭ�ܱ��
				rsPipeUse.SetFieldByName(_T("OnLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//����ʱ��
				rsPipeUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));//���
				rsPipeUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));//���
				rsPipeUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//������Ա
				//rsPipeUse.SetFieldByName(_T("Note"),CL3Variant(_T("������")));//������Ա
				rsPipeUse.MoveFirst();
				CreateNewObjects(CMOLD_PIPE_PAR_USEI_URI,rsPipeUse);
			}
		}
		else
		{
			CString csPipeUri = CMOLD_PIPE_PAR_USEI_URI + _T("\\") + csInStallID;
			SetObjectPropValue(csPipeUri,_T("FlowID"),CL3Variant(csNewFlowID));//����
		}
	}
	//Modify begin by llj 2011-1-27 Add CMM7
	//else ���Σ����Ӷ���Ϊ12���ж�
	else if(lFaceMea == 12)
	//Modify end
	{
		CString csTempExist =  _T("Select * From %s where InStallID = '%s' ");
		CString csSQLExist;	
		csSQLExist.Format(csTempExist,CMOLD_BOARD_PAR_USE_URI,csInStallID);
		CL3RecordSetWrap rsResultExist;
		if(!Query(csSQLExist,rsResultExist) || rsResultExist.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return 0;
		}
		if (rsResultExist.GetRowCount() < 1 )//������ʹ�ü�¼,������û�в������˹�ɾ��
		{
			CL3RecordSetWrap rsBoardUse;
			if(!CreateClassPropSet(CMOLD_BOARD_PAR_USE_URI,rsBoardUse))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;//�齨ͭ��ʹ�ü�¼ʧ��
			}

			CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
			CL3RecordSetWrap rpSysInfo;
			SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));

			CString csTempBoard = _T("Select * From %s where InStallID = '%s' ");
			CString csSQLBoard;	
			csSQLBoard.Format(csTempBoard,CMOLD_BOARD_INSTALL_URI,csInStallID);
			CL3RecordSetWrap rsResultBoard;
			if(!Query(csSQLBoard,rsResultBoard) || rsResultBoard.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return 0;
			}
			if (rsResultBoard.GetRowCount()>0)
			{
				rsResultBoard.MoveFirst();
			
				rsBoardUse.AppendRecord();
				rsBoardUse.SetFieldByName(_T("InStallID"),CL3Variant(csInStallID));//װ����
				rsBoardUse.SetFieldByName(_T("Input_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//¼������
				rsBoardUse.SetFieldByName(_T("Cast_ID"),CL3Variant(csCastID));//������
				rsBoardUse.SetFieldByName(_T("FlowID"),CL3Variant(csNewFlowID));//����
				rsBoardUse.SetFieldByName(_T("MoldID"),CL3Variant(csMoldID));//�ᾧ����
				
				rsBoardUse.SetFieldByName(_T("Inner_ID"),rsResultBoard.GetFieldByName(_T("Inner_ID")));//ͭ���ڻ����
				rsBoardUse.SetFieldByName(_T("Outer_ID"),rsResultBoard.GetFieldByName(_T("Outer_ID")));//ͭ���⻡���
				rsBoardUse.SetFieldByName(_T("South_ID"),rsResultBoard.GetFieldByName(_T("South_ID")));//ͭ���ϲ���
				rsBoardUse.SetFieldByName(_T("North_ID"),rsResultBoard.GetFieldByName(_T("North_ID")));//ͭ�山����
				rsBoardUse.SetFieldByName(_T("Copper_Fac"),rsResultBoard.GetFieldByName(_T("Copper_Fac")));//ͭ�ܳ���
				rsBoardUse.SetFieldByName(_T("Lug_Steel_Mea"),rsResultBoard.GetFieldByName(_T("Lug_Steel_Mea")));//ͭ�ܳ���

				rsBoardUse.SetFieldByName(_T("OnLine_Time"),CL3Variant(COleDateTime::GetCurrentTime()));//����ʱ��
				rsBoardUse.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));//���
				rsBoardUse.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));//���
				rsBoardUse.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));//������Ա
				rsBoardUse.MoveFirst();
				CreateNewObjects(CMOLD_BOARD_PAR_USE_URI,rsBoardUse);
			}
		}
		else
		{
			CString csBoardUri = CMOLD_BOARD_PAR_USE_URI + _T("\\") + csInStallID;
			SetObjectPropValue(csBoardUri,_T("FlowID"),CL3Variant(csNewFlowID));//����
		}
	}
	if(bUseTrans)
		Commit(nTrans);
	return 1;
}
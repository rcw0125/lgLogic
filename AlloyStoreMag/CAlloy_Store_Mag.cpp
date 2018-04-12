// �߼���CAlloy_Store_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CAlloy_Store_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CAlloy_Store_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CAlloy_Store_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CAlloy_Store_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CAlloy_Store_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ������⻺������URI
/// </summary>
CString CAlloy_Store_Mag::GetInputCache()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������
	return ALLOY_STORE_INCACHE_OBJ_URI;
}

/// <summary>
/// ���س��⻺������URI
/// </summary>
CString CAlloy_Store_Mag::GetOutputCache()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return ALLOY_STORE_OUTCACHE_OBJ_URI;
}

/// <summary>
/// ��������¼��������
/// </summary>
CString CAlloy_Store_Mag::GetInputLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return ALLOY_IN_CLASS_URI;
}

/// <summary>
/// ���س����¼��������
/// </summary>
CString CAlloy_Store_Mag::GetOutputLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return ALLOY_OUT_CLASS_URI;
}

/// <summary>
/// ���ؿ�λ��������
/// </summary>
CString CAlloy_Store_Mag::GetStoreAreaType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return _T("");
}

/// <summary>
///	��ʼ���ⷿ������
/// </summary>
BOOL CAlloy_Store_Mag::InitializeStoreProperties()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::InitializeStoreProperties();
}

/// <summary>
/// ����λ�ĳ�ʼ������
/// </summary>
BOOL CAlloy_Store_Mag::GetInitialAreaData(CL3RecordSetWrap& rs)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetInitialAreaData(rs);
}

/// <summary>
/// �ڿⷿ��ʼ��ɺ���á��̳������ش˺������ж���ĳ�ʼ��������
/// </summary>
void CAlloy_Store_Mag::OnAfterStoreInitialized()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::OnAfterStoreInitialized();
}

/// <summary>
/// ���ǰԤ������������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsInputInfo : �����Ϣ��¼��
/// RET << TRUE ������⣻FALSE �ж����
/// </summary>
BOOL CAlloy_Store_Mag::OnBeforeInputMaterials(L3RECORDSET rsInputInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeInputMaterials(rsInputInfo);
}

/// <summary>
/// �������������������ɹ�����á��̳�������ش˷������ж���Ĵ���
/// ARG >> rsInputInfo : �����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CAlloy_Store_Mag::OnAfterMaterialsInputted(L3RECORDSET rsInputInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������
	//���Ĳ��ϻ�����Ϣ�е�Position
	
	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//�ı�����ֵ2009-01-05 tangyi
	varStoreEvent = GetPropValue(_T("Alloy_Add_Material"));
	nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Alloy_Add_Material"),nStoreEvent);

	return TRUE;
}

/// <summary>
/// ����ǰԤ�����ڳ������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsOutputInfo : ������Ϣ��¼��
/// RET << TRUE �������⣻FALSE �жϳ���
/// </summary>
BOOL CAlloy_Store_Mag::OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeOutputMaterials(rsOutputInfo);
}

/// <summary>
/// ������������ڳ�������ɹ�����á��̳�������ش˷������ж���Ĵ���
/// ARG >> rsOutputInfo : ������Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CAlloy_Store_Mag::OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo)
{
	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//2009-04-08 tangyi���Ͻ�ӳ��⻺������ȥ,ɾ����������
	//CString csOutObj = GetOutputCache();
	//InvokeObjectMethod(csOutObj,_T("RemoveMaterials"),rsOutputInfo);

	return TRUE;
}

/// <summary>
/// �˹����ӿ��ǰԤ�����ڽ����˹����ӿ��ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG	>> rsMaterialInfo : ����������Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CAlloy_Store_Mag::OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeAddMaterials(rsMaterialInfo);
}

/// <summary>
/// �˹����ӿ����������ڽ����˹����ӿ�����á��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : �����Ĳ�����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CAlloy_Store_Mag::OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsAdded(rsMaterialInfo);
}

/// <summary>
/// �˹�ɾ�����ǰԤ�����ڽ����˹�ɾ�����ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG	>> rsMaterialInfo : ɾ��������Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CAlloy_Store_Mag::OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeDeleteMaterials(rsMaterialInfo);
}

/// <summary>
/// �˹�ɾ�������������ڽ����˹�ɾ��������á��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CAlloy_Store_Mag::OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsDeleted(rsMaterialInfo);
}


//tangyi 2007-12-09
/// <summary>
/// �ƿ�ǰ������
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CAlloy_Store_Mag::OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// �ƿ��������
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CAlloy_Store_Mag::OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	CL3RecordSetWrap rs = rsMaterialInfo;
	CL3RecordSetWrap rsTrans;
	if(!CreateClassPropSet(ALLOY_TRANS_CLASS_URI,rsTrans))
		return false;
	rsTrans.DelField(_T("GUID"));
	rsTrans.DelField(_T("Name"));
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsTrans.AppendRecord();
		rsTrans.CopyCurRowFrom(rs);
		rsTrans.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsTrans.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));	
		rsTrans.SetFieldByName(_T("Trans_Date"),COleDateTime::GetCurrentTime());	
		rsTrans.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));	
		rs.MoveNext();
	}
	if(CreateNewObjects(ALLOY_TRANS_CLASS_URI,L3RECORDSET(rsTrans)) < rsTrans.GetRowCount())
		return false;

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return true;

}

/// <summary>
/// ����¼Ԥ�����̳�������ش˷��������ǰ����������¼
/// </summary>
void CAlloy_Store_Mag::PrepareInputLog(L3RECORDSET rsInputLog)
{
	CL3RecordSetWrap rs = rsInputLog;
	//��ȡ�������Ϣ
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//��𡢰��
		rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));		
		rs.MoveNext();
	}
	return;
}

/// <summary>
/// �����¼Ԥ�����̳�������ش˷����ڳ���ǰ����������¼
/// </summary>
void CAlloy_Store_Mag::PrepareOutputLog(L3RECORDSET rsOutputLog)
{
	CL3RecordSetWrap rs = rsOutputLog;
	//��ȡ�������Ϣ
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//��𡢰��
		rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));		
		rs.MoveNext();
	}
}

/// <summary>
/// ����ָ����ŵĿ�λ�����URI
/// </summary>
CString CAlloy_Store_Mag::GetAreaURI(LPCTSTR lpcszAreaID)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������
	CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\");
	csAreaUri+=lpcszAreaID;

	return  csAreaUri;
}

/// <Method class="CAlloy_Store_Mag" name="AlloyDataAccept" type="L3BOOL">
/// 
/// ����NC�Ͻ�����,����input����,����ϱ�,���յ��ı�
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CAlloy_Store_Mag::AlloyDataAccept(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsAlloyData =rsData;
	if( rsAlloyData.IsNull() || rsAlloyData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//���ϼ���Ͻ���⻺��
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.AddField(_T("Batch_ID"),VT_BSTR);
	rs.AddField(_T("Alloy_Code"),VT_BSTR);
	rsAlloyData.MoveFirst();
	while(!rsAlloyData.IsEOF())
	{
		//2009-06-19 �������ϱ����ж�Ϊ�ղ�����
		CString csAlloyCode = rsAlloyData.GetFieldByName(_T("Invcode")).ToCString();
		csAlloyCode.Trim();
		if(csAlloyCode.IsEmpty())
		{
			rsAlloyData.MoveNext();
		    continue;
		}
		rs.AppendRecord();
		CString csBatchID = rsAlloyData.GetFieldByName(_T("vproductbatchcode")).ToCString();
		CString csMaterialID = csAlloyCode + csBatchID;
		L3DOUBLE nAmount = rsAlloyData.GetFieldByName(_T("nnum")).ToDouble();
		rs.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
		rs.SetFieldByName(_T("Amount"),CL3Variant(nAmount*1000));
		rs.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
		rs.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
		rsAlloyData.MoveNext();
	}

	//2009-06-19 �������ϱ����ж�Ϊ�ղ�����
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("AddMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	//����ϼƻ������ݱ�
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();	
		CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString();	
		CString csAlloyCode = rs.GetFieldByName(_T("Alloy_Code")).ToCString();	
		CString csUri = ALLOY_DATA_CLASS_URI + _T("\\") + csMaterialID;
		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();
		if(!csObject.IsEmpty())
		{
			CL3Variant valTemp = rs.GetFieldByName(_T("Amount"));
			if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			L3DOUBLE nAddAMount = valTemp.ToDouble();
			valTemp = GetObjectPropValue(csUri,_T("Amount"));
			if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			L3DOUBLE nAmount = valTemp.ToDouble();
			nAmount += nAddAMount;
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAmount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			if(!SetObjectPropValue(csUri,_T("Alloy_Code"),CL3Variant(csAlloyCode)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			if(!SetObjectPropValue(csUri,_T("Batch_ID"),CL3Variant(csBatchID)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
		}
		else
		{
			CreateNewObject(ALLOY_DATA_CLASS_URI,CL3Variant(csMaterialID));

			if(!SetObjectPropValue(csUri,_T("Amount"),rs.GetFieldByName(_T("Amount"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
			if(!SetObjectPropValue(csUri,_T("Alloy_Code"),CL3Variant(csAlloyCode)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}

			if(!SetObjectPropValue(csUri,_T("Batch_ID"),CL3Variant(csBatchID)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}
		
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	// TODO : ���ڴ�����߼�����
	return 0;
}


// <Method class="CAlloy_Store_Mag" name="AlloyDataAccept" type="L3BOOL">
/// 
/// ����NC�Ͻ�����,����input����,����ϱ�,���յ��ı�
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CAlloy_Store_Mag::AlloyDataAcceptFromNC (L3RECORDSET rsData)
{
	CL3RecordSetWrap rsAlloyData =rsData;
	if( rsAlloyData.IsNull() || rsAlloyData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//���ϼ���Ͻ���⻺��
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.AddField(_T("Batch_ID"),VT_BSTR);
	rs.AddField(_T("Alloy_Code"),VT_BSTR);
	rsAlloyData.MoveFirst();
	while(!rsAlloyData.IsEOF())
	{
		//2009-04-07���ϱ���ֱ�Ӵӵ������ȡ
		//2009-06-19 �������ϱ����ж�Ϊ�ղ�����
		CString csAlloyCode = rsAlloyData.GetFieldByName(_T("Invcode")).ToCString();
		csAlloyCode.Trim();
		if(csAlloyCode.IsEmpty())
		{
			rsAlloyData.MoveNext();
		    continue;
		}
		rs.AppendRecord();
		CString csBatchID = rsAlloyData.GetFieldByName(_T("vbatchcode")).ToCString();
		L3DOUBLE nAmount = rsAlloyData.GetFieldByName(_T("ninnum")).ToDouble();

		CString csHouseid=rsAlloyData.GetFieldByName(_T("cwarehouseid")).ToCString();
		if(csHouseid==_T("1006AA100000000E8U7E")||csHouseid==_T("CKDA0000000000000010"))
		{
		rs.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
		}
		else
		{
		rs.SetFieldByName(_T("MaterialID"),CL3Variant(_T("2")+csAlloyCode + csBatchID));
		}


		//rs.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
		rs.SetFieldByName(_T("Amount"),CL3Variant(nAmount*1000));
		rs.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
		rs.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
		rsAlloyData.MoveNext();
	}

	//2009-06-19 �������ϱ����ж�Ϊ�ղ�����
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("AddMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	//����ϼƻ������ݱ�
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();	
		CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString();	
		CString csAlloyCode = rs.GetFieldByName(_T("Alloy_Code")).ToCString();	
		CString csUri = ALLOY_DATA_CLASS_URI + _T("\\") + csMaterialID;
		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();
		if(!csObject.IsEmpty())
		{
			CL3Variant valTemp = rs.GetFieldByName(_T("Amount"));
			if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			L3DOUBLE nAddAMount = valTemp.ToDouble();
			valTemp = GetObjectPropValue(csUri,_T("Amount"));
			if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			L3DOUBLE nAmount = valTemp.ToDouble();
			nAmount += nAddAMount;
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAmount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			// 2016-03-01 rcw
			/*if(!SetObjectPropValue(csUri,_T("Alloy_Code"),CL3Variant(csAlloyCode)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			if(!SetObjectPropValue(csUri,_T("Batch_ID"),CL3Variant(csBatchID)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}*/ 
			//2016-03-01 rcw end
		}
		else
		{
			CreateNewObject(ALLOY_DATA_CLASS_URI,CL3Variant(csMaterialID));

			if(!SetObjectPropValue(csUri,_T("Amount"),rs.GetFieldByName(_T("Amount"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
			if(!SetObjectPropValue(csUri,_T("Alloy_Code"),CL3Variant(csAlloyCode)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}

			if(!SetObjectPropValue(csUri,_T("Batch_ID"),CL3Variant(csBatchID)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}
		
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("Alloy_Add_Material"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Alloy_Add_Material"),nStoreEvent);

	// TODO : ���ڴ�����߼�����
	return 0;
	
}


/// <Method class="CAlloy_Store_Mag" name="AlloyDataAccept" type="L3BOOL">
/// 
/// ����NC�Ͻ�ɷ���������ϱ�,���յ��ı�
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CAlloy_Store_Mag::AlloyElementDataAccept(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsAlloyElementData =rsData;
	if( rsAlloyElementData.IsNull() || rsAlloyElementData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	//����ϼƻ������ݱ�
	rsAlloyElementData.MoveFirst();
	while(!rsAlloyElementData.IsEOF())
	{
		CString csAlloyCode = rsAlloyElementData.GetFieldByName(_T("Invcode")).ToCString();	
		CL3Variant valTemp = rsAlloyElementData.GetFieldByName(_T("vproductbatchcode"));
		CString csBatchID = valTemp.ToCString();
		CString csMaterialID = csAlloyCode + csBatchID;
		CString csUri = ALLOY_DATA_CLASS_URI + _T("\\") + csMaterialID;
		CreateNewObject(ALLOY_DATA_CLASS_URI,CL3Variant(csMaterialID));			
		if(!SetObjPropValues(csUri,rsAlloyElementData))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		if(!SetObjectPropValue(csUri,_T("Batch_ID"),CL3Variant(csBatchID)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		rsAlloyElementData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	// TODO : ���ڴ�����߼�����
	return 0;
}


/// <Method class="CAlloy_Store_Mag" name="AlloyDataAccept" type="L3BOOL">
/// 
/// ����NC�Ͻ�ɷ���������ϱ�,���յ��ı�
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CAlloy_Store_Mag::AlloyElementDataAcceptFormNC(L3RECORDSET rsData)
{
 	CL3RecordSetWrap rsAlloyElementData =rsData;
	if( rsAlloyElementData.IsNull() || rsAlloyElementData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//��¼������Ϣ
	CL3RecordSetWrap rsTelData;
	if(!CreateClassPropSet(ALLOY_ELEMENT_TEL_CLASS_URI,rsTelData))
		return -1;
	rsTelData.DelField(_T("GUID"));
	rsTelData.CopyFrom(rsAlloyElementData);
	rsTelData.MoveFirst();
	while(!rsTelData.IsEOF())
	{
		rsTelData.SetFieldByName(_T("Rec_Time"),timeNow);
		rsTelData.MoveNext();
	}
	
	if(CreateNewObjects(ALLOY_ELEMENT_TEL_CLASS_URI,rsTelData) < rsTelData.GetRowCount())
		return -7;

	CL3RecordSetWrap rsAlloyData;
	if(!CreateClassPropSet(ALLOY_DATA_CLASS_URI,rsAlloyData))
		return -1;
	rsAlloyData.DelField(_T("GUID"));
	rsAlloyData.DelField(_T("NAME"));
	rsAlloyData.DelField(_T("Status"));
	rsAlloyData.DelField(_T("Postion"));
	rsAlloyData.DelField(_T("Batch_ID"));
	rsAlloyData.DelField(_T("Alloy_Code"));
	rsAlloyData.DelField(_T("UnitID"));
	rsAlloyData.DelField(_T("Amount"));


	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CString CheckItemID[55] = {_T("1001NC10000000004KXY")/*C*/,_T("1001NC10000000004KXU")/*Si*/,_T("1001NC10000000004KXW")/*Mn*/,_T("1001NC10000000004KX3")/*P*/,_T("1001NC10000000004KX2")/*S*/,
							   _T("1001NC10000000004KYZ")/*Cu*/,_T("1001NC10000000004L1A")/*Ni*/,_T("1001NC10000000004KYE")/*Cr*/,_T("1001NC10000000004KY9")/*Mo*/,_T("1001NC10000000004KYB")/*V*/,
							   _T("1001NC10000000004L2Z")/*Nb*/,_T("1001NC10000000004L18")/*Al*/,_T("1001NC10000000004L30")/*ALS*/,_T("1001NC10000000004KYF")/*Ti*/,_T("1001NC10000000004KYH")/*B*/,
							   _T("1001NC10000000004L2W")/*Sb*/,_T("1001NC10000000004L29")/*AS*/,_T("1001NC10000000004L2A")/*Sn*/,_T("1001NC10000000004KYX")/*Zn*/,_T("1001NC10000000004KY2")/*Ca*/,
							   _T("1001NC10000000004L2B")/*W*/,_T("1001NC10000000004KYV")/*Pb*/,_T("")/*Re*/,_T("1001NC10000000004L14")/*Ceq*/,_T("1001NC10000000004L25")/*N*/,
							   _T("1001NC10000000004L26")/*H*/,_T("1001NC10000000004L24")/*O*/,_T("1001NC10000000005EQY")/*CrNi*/,_T("")/*CrCu*(��)*/,_T("1001NC10000000005L7I")/*CrNiCu*/,
							   _T("1001NC10000000004KXD")/*TFe*/,_T("1001NC10000000004L19")/*FeO*/,_T("1001NC10000000004KX9")/*SiO2*/,_T("")/*TCa*/,_T("1001NC10000000004KXA")/*CaO*/,
							   _T("1001NC10000000004KX4")/*MgO*/,_T("1001NC10000000004KXB")/*Al2O3*/,_T("1001NC10000000004L0P")/*MnO*/,_T("1001NC10000000004KXH")/*TiO2*/,_T("1001NC10000000004L17")/*P2O5*/,_T("1001NC10000000004KXF")/*(R)*/,
							//1009-06-02 liuzhiqiang
							   _T("1001NC1000000003J6KZ")/*AD*/,_T("1001NC100000000564TE")/*Ni_Co*/,_T("1001NC100000000564TE")/*H2O*/,_T("1001NC1000000003J6L4")/*SSL*/,_T("1001NC10000000004L2C")/*FE2O3*/,
							   _T("1001NC10000000004KXS")/*G_C*/,_T("")/*RD(�۵�)*/,_T("1001NC10000000004KY7")/*Ba*/,_T("1001NC10000000004KXK")/*HFF*/,_T("1001NC10000000004KYJ")/*Sic*/,
							   _T("1001NC10000000004KYK")/*Si_SiO2*/,_T("")/*Y_C(����C)*/,_T("1001NC10000000004KYM")/*Ca_MgO*/,_T("1001NC10000000004KYU")/*K2O_Na2O*/};

	//����ϼƻ������ݱ�
	rsAlloyData.MoveFirst();
	rsAlloyData.AppendRecord();
	rsAlloyElementData.MoveFirst();
	//2009-03-24
	CString csAlloyCode;
	CString csInvcodeID = rsAlloyElementData.GetFieldByName(_T("cbaseid")).ToCString();
	//2009-06-19 �������ϱ����ж�Ϊ�ղ�����
	csInvcodeID.Trim();
	if(csInvcodeID.IsEmpty())
		return -1;
	CString csTempSql = _T("select code from CBase_All_Code where Code_Group ='ALLOY_CODE' and NC_Code ='%s'");
	CString csSQL;
	csSQL.Format(csTempSql,csInvcodeID);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		csAlloyCode = csInvcodeID;
	else
	{
		rsResult.MoveFirst();
		csAlloyCode = rsResult.GetFieldByIndex(0).ToCString();
	}
	//2009-04-07���ϱ���ֱ�Ӵӵ������ȡ	
	//CString csAlloyCode = rsAlloyElementData.GetFieldByName(_T("Invcode")).ToCString();
	CString csBatchCode = rsAlloyElementData.GetFieldByName(_T("vstobatchcode")).ToCString();
	rsAlloyData.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchCode));

	while(!rsAlloyElementData.IsEOF())
	{		
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[0])		
			rsAlloyData.SetFieldByName(_T("C"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[1])		
			rsAlloyData.SetFieldByName(_T("Si"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[2])		
			rsAlloyData.SetFieldByName(_T("Mn"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[3])		
			rsAlloyData.SetFieldByName(_T("P"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[4])	
			rsAlloyData.SetFieldByName(_T("S"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[5])		
			rsAlloyData.SetFieldByName(_T("Cu"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[6])		
			rsAlloyData.SetFieldByName(_T("Ni"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[7])		
			rsAlloyData.SetFieldByName(_T("Cr"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[8])		
			rsAlloyData.SetFieldByName(_T("Mo"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[9])		
			rsAlloyData.SetFieldByName(_T("V"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[10])		
			rsAlloyData.SetFieldByName(_T("Nb"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[11])		
			rsAlloyData.SetFieldByName(_T("Al"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[12])		
			rsAlloyData.SetFieldByName(_T("AlS"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[13])		
			rsAlloyData.SetFieldByName(_T("Ti"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[14])		
			rsAlloyData.SetFieldByName(_T("B"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[15])		
			rsAlloyData.SetFieldByName(_T("Sb"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[16])		
			rsAlloyData.SetFieldByName(_T("As"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[17])		
			rsAlloyData.SetFieldByName(_T("Sn"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[18])		
			rsAlloyData.SetFieldByName(_T("Zn"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[19])		
			rsAlloyData.SetFieldByName(_T("Ca"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[20])		
			rsAlloyData.SetFieldByName(_T("W"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[21])		
			rsAlloyData.SetFieldByName(_T("Pb"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[22])		
			rsAlloyData.SetFieldByName(_T("Re"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[23])		
			rsAlloyData.SetFieldByName(_T("Ceq"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[24])		
			rsAlloyData.SetFieldByName(_T("N"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[25])		
			rsAlloyData.SetFieldByName(_T("H"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[26])		
			rsAlloyData.SetFieldByName(_T("O"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[27])		
			rsAlloyData.SetFieldByName(_T("CrNi"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[28])		
			rsAlloyData.SetFieldByName(_T("CrCu"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[29])		
			rsAlloyData.SetFieldByName(_T("CrNiCu"),rsAlloyElementData.GetFieldByName(_T("cresult")));

		//2009-05-27 liuzhiqiang
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[30])		
			rsAlloyData.SetFieldByName(_T("TFe"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[31])		
			rsAlloyData.SetFieldByName(_T("FeO"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[32])		
			rsAlloyData.SetFieldByName(_T("SiO2"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[33])		
			rsAlloyData.SetFieldByName(_T("TCa"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[34])		
			rsAlloyData.SetFieldByName(_T("CaO"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[35])		
			rsAlloyData.SetFieldByName(_T("MgO"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[36])		
			rsAlloyData.SetFieldByName(_T("Al2O3"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[37])		
			rsAlloyData.SetFieldByName(_T("MnO"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[38])		
			rsAlloyData.SetFieldByName(_T("TiO2"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[39])		
			rsAlloyData.SetFieldByName(_T("P2O5"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[40])		
			rsAlloyData.SetFieldByName(_T("R"),rsAlloyElementData.GetFieldByName(_T("cresult")));

		//2009-06-02 liuzhiqiang
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[41])		
			rsAlloyData.SetFieldByName(_T("AD"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[42])		
			rsAlloyData.SetFieldByName(_T("Ni_Co"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[43])		
			rsAlloyData.SetFieldByName(_T("H2O"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[44])		
			rsAlloyData.SetFieldByName(_T("SSL"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[45])		
			rsAlloyData.SetFieldByName(_T("FE2O3"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[46])		
			rsAlloyData.SetFieldByName(_T("G_C"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[47])		
			rsAlloyData.SetFieldByName(_T("RD"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[48])		
			rsAlloyData.SetFieldByName(_T("Ba"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[49])		
			rsAlloyData.SetFieldByName(_T("HFF"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[50])		
			rsAlloyData.SetFieldByName(_T("Sic"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[51])		
			rsAlloyData.SetFieldByName(_T("Si_SiO2"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[52])		
			rsAlloyData.SetFieldByName(_T("Y_C"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[53])		
			rsAlloyData.SetFieldByName(_T("Ca_MgO"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		if(rsAlloyElementData.GetFieldByName(_T("ccheckitemid")).ToCString() == CheckItemID[54])		
			rsAlloyData.SetFieldByName(_T("K2O_Na2O"),rsAlloyElementData.GetFieldByName(_T("cresult")));
		rsAlloyElementData.MoveNext();

	}
	rsAlloyData.MoveFirst();
	CreateNewObjects(ALLOY_DATA_CLASS_URI,rsAlloyData);
	rsAlloyData.MoveFirst();
	if(!SetObjsPropValues(ALLOY_DATA_CLASS_URI,rsAlloyData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}
	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("Alloy_Add_Material"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Alloy_Add_Material"),nStoreEvent);

	// TODO : ���ڴ�����߼�����
	return 1;
}



/// <Method class="CAlloy_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// ��ȡ��⻺�����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CAlloy_Store_Mag::GetMaterialOnInputCache()
{
	CString csInputCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
		return NULL;
	CString csPos = valRet.ToCString();
	CString csTemp = _T(" select a.*,b.Batch_ID,b.Alloy_Code,                                                              ");
			csTemp+= _T(" b.C,b.Si,b.Mn,b.P,b.S,b.Cu,b.Ni,b.Cr,b.Mo,b.V,b.Nb,b.Al,b.AlS,b.Ti,b.B,b.Sb,b.\"AS\",            ");
			csTemp+= _T(" b.Sn,b.Zn,b.Ca,b.W,b.Pb,b.Re,b.Ceq,b.N,b.H,b.O,b.Other1,b.Other2,                                ");
			csTemp+= _T(" b.CrNi,b.CrCu,b.CrNiCu,b.TFe,b.FeO,b.SiO2,b.TCa,b.CaO,b.MgO,b.Al2O3,b.MnO,b.TiO2,b.P2O5,b.R,     ");
			csTemp+= _T(" b.AD,b.Ni_Co,b.H2O,b.SSL,b.FE2O3,b.G_C,b.RD,b.Ba,b.HFF,b.Sic,b.Si_SiO2,b.Y_C,b.Ca_MgO,b.K2O_Na2O ");
			csTemp+= _T(" from %s a,%s b where a.MaterialID = b.MaterialID and a.Position = '%s'                           ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,ALLOY_DATA_CLASS_URI,csPos);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


//L3RECORDSET CAlloy_Store_Mag::GetMaterialOnInputCachePosition()
//{
//	CString csInputCacheUri = GetInputCache();
//	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
//	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
//		return NULL;
//	CString csPos = valRet.ToCString();
//	CString csTemp = _T(" select a.*,b.Batch_ID,b.Alloy_Code                                                            ");
//			csTemp+= _T(" from %s a,%s b where a.MaterialID = b.MaterialID and a.Position = '%s'                           ");
//	CString csSQL;
//	csSQL.Format(csTemp,MES_MATERIAL_POSITION,ALLOY_DATA_CLASS_URI,csPos);
//	CL3RecordSetWrap rsResult;
//	if(!Query(csSQL,rsResult) || rsResult.IsNull())
//		return NULL;
//	else
//		return rsResult.Detach();
//}


/// <Method class="CAlloy_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// ��ȡ����������Ϣ
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CAlloy_Store_Mag::GetMaterialOnStore(L3STRING strStoreID)
{
	CString csPos = strStoreID;
	CString csTemp = _T(" select a.*,b.Batch_ID,b.Alloy_Code,                                                              ");
			csTemp+= _T(" b.C,b.Si,b.Mn,b.P,b.S,b.Cu,b.Ni,b.Cr,b.Mo,b.V,b.Nb,b.Al,b.AlS,b.Ti,b.B,b.Sb,b.\"AS\",            ");
			csTemp+= _T(" b.Sn,b.Zn,b.Ca,b.W,b.Pb,b.Re,b.Ceq,b.N,b.H,b.O,b.Other1,b.Other2,                                ");
			csTemp+= _T(" b.CrNi,b.CrCu,b.CrNiCu,b.TFe,b.FeO,b.SiO2,b.TCa,b.CaO,b.MgO,b.Al2O3,b.MnO,b.TiO2,b.P2O5,b.R,     ");
			csTemp+= _T(" b.AD,b.Ni_Co,b.H2O,b.SSL,b.FE2O3,b.G_C,b.RD,b.Ba,b.HFF,b.Sic,b.Si_SiO2,b.Y_C,b.Ca_MgO,b.K2O_Na2O ");
			csTemp+= _T(" from %s a,%b b where a.MaterialID = b.MaterialID and a.Position = '%s'                           ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,ALLOY_DATA_CLASS_URI,csPos);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CAlloy_Store_Mag" name="GetAllMaterialOnStore" type="L3RECORDSET">
/// 
/// ��ȡ���кϽ����������Ϣ
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CAlloy_Store_Mag::GetAllMaterialOnStore(void)
{

	//20081212tangyi
	//select d.code as Position,substr(d.Code,4,1) as PosDiff,
	//c.Amount,c.Alloy_C,c.Alloy_Si,c.Alloy_Mn,c.Alloy_P,
	//c.Alloy_S,c.Batch_ID,c.Alloy_Code  from 
	//(select a.Amount,a.Position as Pos,
	//b.Alloy_C,b.Alloy_Si,b.Alloy_Mn,b.Alloy_P,b.Alloy_S,b.Batch_ID,b.Alloy_Code 
	//from MATERIALPOSITION a,CALLOY_DATA b
	//where  a.MaterialID = b.MaterialID  and substr(a.Position,1,3) = 'S81'    
	//and  substr(a.Position,4,1) <> 'P' and  substr(a.Position,4,1) <> 'N' ) c ,
	//(select * from XGSTOREAREA where substr(Code,1,3) = 'S81') d
	//where   c.Pos(+)  = d.Code                              
	//order by Position


	CString csTemp = _T(" select c.MaterialID,c.MaterialType,d.Code as Position,                                                      ");
			csTemp+= _T(" substr(d.Code,4,1) as PosDiff,c.Amount,c.C,c.Si,c.Mn,c.P,c.S,c.Cu,c.Ni,c.Cr,c.Mo,                           ");
			csTemp+= _T(" c.V,c.Nb,c.Al,c.AlS,c.Ti,c.B,c.Sb,c.\"AS\",c.Sn,c.Zn,c.Ca,c.W,c.Pb,c.Re,c.Ceq,c.N,c.H,c.O,c.Other1,c.Other2,");
			csTemp+= _T(" c.CrNi,c.CrCu,c.CrNiCu,c.TFe,c.FeO,c.SiO2,c.TCa,c.CaO,c.MgO,c.Al2O3,c.MnO,c.TiO2,c.P2O5,c.R,                ");
			csTemp+= _T(" c.AD,c.Ni_Co,c.H2O,c.SSL,c.FE2O3,c.G_C,c.RD,c.Ba,c.HFF,c.Sic,c.Si_SiO2,c.Y_C,c.Ca_MgO,c.K2O_Na2O,           ");
			csTemp+= _T(" c.Batch_ID,c.Alloy_Code,d.CONTAINERID  from                                                                 ");
			csTemp+= _T(" (select a.MaterialID,a.MaterialType,a.Amount,a.Position as Pos,                                             ");
			csTemp+= _T(" b.C,b.Si,b.Mn,b.P,b.S,b.Cu,b.Ni,b.Cr,b.Mo,b.V,b.Nb,b.Al,b.AlS,b.Ti,b.B,b.Sb,b.\"AS\",                       ");
			csTemp+= _T(" b.Sn,b.Zn,b.Ca,b.W,b.Pb,b.Re,b.Ceq,b.N,b.H,b.O,b.Other1,b.Other2,                                           ");
			csTemp+= _T(" b.CrNi,b.CrCu,b.CrNiCu,b.TFe,b.FeO,b.SiO2,b.TCa,b.CaO,b.MgO,b.Al2O3,b.MnO,b.TiO2,b.P2O5,b.R,                ");
			csTemp+= _T(" b.AD,b.Ni_Co,b.H2O,b.SSL,b.FE2O3,b.G_C,b.RD,b.Ba,b.HFF,b.Sic,b.Si_SiO2,b.Y_C,b.Ca_MgO,b.K2O_Na2O,           ");
			csTemp+= _T(" b.Batch_ID,b.Alloy_Code                                                                                     ");
			csTemp+= _T(" from %s a,%s b                                                                                              ");
			csTemp+= _T(" where  a.MaterialID = b.MaterialID  and substr(a.Position,1,3) = '%s'                                       ");
			csTemp+= _T(" and  substr(a.Position,4,1) <> 'P' and  substr(a.Position,4,1) <> 'N' ) c ,                                 ");
			csTemp+= _T(" (select * from XGSTOREAREA where substr(Code,1,3) = '%s') d                                                 ");		
			csTemp+= _T(" where   c.Pos(+)  = d.Code        order by Position                                                         ");
			
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,ALLOY_DATA_CLASS_URI,STORE_ID_ALLOY,STORE_ID_ALLOY);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CAlloy_Store_Mag" name="GetAreaIDByUnitID" type="L3STRING">
/// 
/// ͨ����λ��ȡ�ϲֱ���
/// ARG&gt;&gt; strUnitID����λ
/// RET &lt;&lt;�����ϲֱ���
/// <Param name="strUnitID" type="L3STRING"></Param>
/// </Method>
L3STRING CAlloy_Store_Mag::GetAreaIDByUnitID(L3STRING strUnitID)
{
	// TODO : ���ڴ�����߼�����
	return NULL;
}

/// <Method class="CAlloy_Store_Mag" name="AlloyApp" type="L3BOOL">
/// 
/// �Ͻ�Ҫ������
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CAlloy_Store_Mag::AlloyApp(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsAlloyAppData =rsData;
	if( rsAlloyAppData.IsNull() || rsAlloyAppData.GetRowCount() < 1)
		return false;
	if(rsAlloyAppData.GetFieldIndex(_T("Alloy_Code")) < 0 ||
		rsAlloyAppData.GetFieldIndex(_T("Amount")) < 0 ||
		rsAlloyAppData.GetFieldIndex(_T("App_Time")) < 0 ||
		rsAlloyAppData.GetFieldIndex(_T("App_Operator")) < 0 ||
		rsAlloyAppData.GetFieldIndex(_T("App_UnitID")) < 0)
			return FALSE;

	rsAlloyAppData.MoveFirst();
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	//��������
	while(!rsAlloyAppData.IsEOF())
	{
		rsAlloyAppData.SetFieldByName(_T("App_Operator"),CL3Variant(csUser));
		rsAlloyAppData.SetFieldByName(_T("App_Time"),timeNow);
		rsAlloyAppData.MoveNext();
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(CreateNewObjects(ALLOY_APP_CLASS_URI,L3RECORDSET(rsAlloyAppData)) < rsAlloyAppData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	if(bUseTrans)
		Commit(nTrans);
	return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CAlloy_Store_Mag" name="AlloyAppConfirm" type="L3BOOL">
/// 
/// �Ͻ�Ҫ������
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CAlloy_Store_Mag::AlloyAppConfirm(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsAlloyAppData =rsData;
	if( rsAlloyAppData.IsNull() || rsAlloyAppData.GetRowCount() < 1)
		return false;
	rsAlloyAppData.MoveFirst();
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	//��������
	while(!rsAlloyAppData.IsEOF())
	{
		rsAlloyAppData.SetFieldByName(_T("Confirm_Flag"),LONG(1));
		rsAlloyAppData.SetFieldByName(_T("Confirm_Operator"),CL3Variant(csUser));
		rsAlloyAppData.SetFieldByName(_T("Confirm_Time"),timeNow);
		rsAlloyAppData.MoveNext();
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(!SetObjsPropValues(ALLOY_APP_CLASS_URI,L3RECORDSET(rsAlloyAppData)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	if(bUseTrans)
		Commit(nTrans);
	return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CAlloy_Store_Mag" name="AlloyInStore" type="L3LONG">
/// 
/// �Ͻ����
/// ARG&gt;&gt; rsInputInfo�Ͻ���Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID,Alloy_Code,Batch_ID�⼸���ֶΡ�
/// &gt;&gt;strUnitID:����
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
/// <Param name="strUnitID" type="L3STRING"></Param>
/// </Method>
L3LONG CAlloy_Store_Mag::AlloyInStore(L3RECORDSET rsInputInfo)
{
	//ͬһ���ϲ�ֻ�ܼ���ͬһ���ε�ͬ�ֺϽ�
	//2009-03-26 ��,һ���ϲֿ��Զ�ͬһ���Ͻ��л�װ,����ʱ��,��ȡ�Ƚ��ȳ���ԭ��tangyi
	CL3RecordSetWrap rs =rsInputInfo;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if(rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("StoreAreaID")) < 0 ||
		rs.GetFieldIndex(_T("Batch_ID")) < 0 ||
		rs.GetFieldIndex(_T("Alloy_Code")) < 0)
			return -1;
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csArea = rs.GetFieldByName(_T("StoreAreaID")).ToCString();
		csArea.Trim();
		CString csMaterialType = rs.GetFieldByName(_T("MaterialType")).ToCString();
		CString csAlloyCode =  rs.GetFieldByName(_T("Alloy_Code")).ToCString();
		CString strSQL;
		strSQL.Format(_T("SELECT * FROM %s WHERE Position = '%s' order by Idx "),MES_MATERIAL_POSITION,csArea);
		CL3RecordSetWrap rsResult;
		if(!Query(strSQL,rsResult))
            return -2;
		rsResult.MoveFirst();
		while(!rsResult.IsEOF())
		{
			CString csCurMaterialID = rsResult.GetFieldByName(_T("MaterialID")).ToCString();
			//2009-03-26 tangyi�õ��Ͻ����
			CString csAlloyUri = ALLOY_DATA_CLASS_URI + _T("\\") + csCurMaterialID;
			CString csCurAlloyCode = GetObjectPropValue(csAlloyUri,_T("Alloy_Code")).ToCString();
			CString csCurMaterialType = rsResult.GetFieldByName(_T("MaterialType")).ToCString();
			if(csAlloyCode != csCurAlloyCode || csCurMaterialType!= csMaterialType)
				return -3;
			rsResult.MoveNext();
		}
		rs.MoveNext();
	}

	if(!InputMaterials(rsInputInfo))
		return -4;
	return 0;
	// TODO : ���ڴ�����߼�����
}

//// <Method class="CAlloy_Store_Mag" name="AlloyInStore" type="L3LONG">
//// 
//// �Ͻ�ת��
//// ARG&gt;&gt; rsInputInfo�Ͻ���Ϣ.������� MaterialType,MaterialID,Amount,Position,TargetID�⼸���ֶΡ�
//// &gt;&gt;strUnitID:����
//// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
//// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
//// <Param name="strUnitID" type="L3STRING"></Param>
/////</Method>
L3LONG CAlloy_Store_Mag::AlloyChangeStore(L3RECORDSET rsInputInfo)
{
	//ͬһ���ϲ�ֻ�ܼ���ͬһ���ε�ͬ�ֺϽ�
	//2009-03-26 ��,һ���ϲֿ��Զ�ͬһ���Ͻ��л�װ,����ʱ��,��ȡ�Ƚ��ȳ���ԭ��tangyi
	CL3RecordSetWrap rs =rsInputInfo;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if (rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Position")) < 0 ||
		rs.GetFieldIndex(_T("Alloy_Code")) < 0 ||
		rs.GetFieldIndex(_T("Batch_ID")) < 0 ||
		rs.GetFieldIndex(_T("TargetID")) < 0 )
			return -1;
	rs.MoveFirst();
	//���ݼ��
	while(!rs.IsEOF())
	{
		CString csTargetArea = rs.GetFieldByName(_T("TargetID")).ToCString();
		csTargetArea.Trim();
		CString csMaterialType=rs.GetFieldByName(_T("MaterialType")).ToCString();
		CString csAlloyCode =  rs.GetFieldByName(_T("Alloy_Code")).ToCString();
		CString strSQL;
		strSQL.Format(_T("SELECT * FROM %s WHERE Position = '%s'"),MES_MATERIAL_POSITION,csTargetArea);
		CL3RecordSetWrap rsResult;
		if(!Query(strSQL,rsResult))
            return -2;
		rsResult.MoveFirst();
		while(!rsResult.IsEOF())
		{
			CString csTargetMaterialID = rsResult.GetFieldByName(_T("MaterialID")).ToCString();
			//2009-03-26 tangyi�õ��Ͻ����
			CString csAlloyUri = ALLOY_DATA_CLASS_URI + _T("\\") + csTargetMaterialID;
			CString csTargetAlloyCode = GetObjectPropValue(csAlloyUri,_T("Alloy_Code")).ToCString();
			CString csTargetMaterialType = rsResult.GetFieldByName(_T("MaterialType")).ToCString();
			if(csAlloyCode != csTargetAlloyCode || csTargetMaterialType!= csMaterialType)
				return -3;
			rsResult.MoveNext();
		}

		rs.MoveNext();
	}
	//����׼��
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsAlloy; pRS->QueryInterface(IID_IL3RecordSet,rsAlloy); pRS->Release();
	rsAlloy.AddField(_T("MaterialType"),VT_BSTR);
	rsAlloy.AddField(_T("MaterialID"),VT_BSTR);
	rsAlloy.AddField(_T("Amount"),VT_R8);
	rsAlloy.AddField(_T("TargetID"),VT_BSTR);
	rsAlloy.AddField(_T("SourceID"),VT_BSTR);
	rsAlloy.AddField(_T("Batch_ID"),VT_BSTR);
	rsAlloy.AddField(_T("Alloy_Code"),VT_BSTR);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsAlloy.AppendRecord();
		rsAlloy.SetFieldByName(_T("MaterialType"),rs.GetFieldByName(_T("MaterialType")));
		rsAlloy.SetFieldByName(_T("MaterialID"),rs.GetFieldByName(_T("MaterialID")));
		rsAlloy.SetFieldByName(_T("Amount"),rs.GetFieldByName(_T("Amount")));
		rsAlloy.SetFieldByName(_T("TargetID"),rs.GetFieldByName(_T("TargetID")));
		rsAlloy.SetFieldByName(_T("SourceID"),rs.GetFieldByName(_T("Position")));
		rsAlloy.SetFieldByName(_T("Batch_ID"),rs.GetFieldByName(_T("Batch_ID")));
		rsAlloy.SetFieldByName(_T("Alloy_Code"),rs.GetFieldByName(_T("Alloy_Code")));
		rs.MoveNext();
	}	
	//rsAlloy.MoveFirst();
	if(!MoveMaterials(L3RECORDSET(rsAlloy)))
		return -4;
	return 0;
	// TODO : ���ڴ�����߼�����
}


/// <Method class="CAlloy_Store_Mag" name="GetAlloyArea" type="L3RECORDSET">
/// 
/// ���ݺϽ�����ȡ�ϲ�
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CAlloy_Store_Mag::GetAlloyArea(L3STRING strAlloyCode)
{
	CString csTemp = _T(" select a.Alloy_Area,b.Code_Des from (select  Alloy_Area  from %s  where Alloy_Code ='%s' and Name <> '0') a, CBase_All_Code b where a.Alloy_Area = b.Code  order by b.Code_Des");
	CString csSQL;
	csSQL.Format(csTemp,ALLOY_REL_CLASS_URI,strAlloyCode);
	CL3RecordSetWrap rsAlloyData;
	if(!Query(csSQL,rsAlloyData)||rsAlloyData.IsNull())
		return NULL;
	else
		return rsAlloyData.Detach();
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CAlloy_Store_Mag" name="GetAlloyAppInfor" type="L3RECORDSET">
/// 
/// ��ȡδȷ�ϺϽ�������Ϣ
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CAlloy_Store_Mag::GetAlloyAppInfor(L3STRING strDate)
{
	CString csTemp = _T(" select * from %s where Confirm_Flag = 0 and to_char(App_Time,'yyyy-mm-dd') = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,ALLOY_APP_CLASS_URI,strDate);
	CL3RecordSetWrap rsAlloyData;
	if(!Query(csSQL,rsAlloyData)||rsAlloyData.IsNull())
		return NULL;
	else
		return rsAlloyData.Detach();
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CAlloy_Store_Mag" name="AlloyAndAreaMap" type="L3BOOL">
/// 
/// �ϲ�����ά��
/// ARG&gt;&gt; rsData:�ϲ�������Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CAlloy_Store_Mag::AlloyAndAreaMap(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsAlloyData =rsData;
	if( rsAlloyData.IsNull() || rsAlloyData.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(!SetObjsPropValues(ALLOY_REL_CLASS_URI,rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}

	if(bUseTrans)
		Commit(nTrans);
	return true;
	// TODO : ���ڴ�����߼�����
}


/// <Method class="CAlloy_Store_Mag" name="AlloyModifyAmount" type="L3BOOL">
/// 
/// ��������������
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.�������MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag �⼸���ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CAlloy_Store_Mag::ModifyMaterialAmount(L3RECORDSET rsData)
{
	L3LONG nRet = ModifyMaterialAmountFuction(rsData);

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return nRet;
}

/// <Method class="CAlloy_Store_Mag" name="AlloyModifyAmount" type="L3BOOL">
/// 
/// ��������������
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.�������MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag �⼸���ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CAlloy_Store_Mag::ModifyMaterialAmountFuction(L3RECORDSET rsData)

{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if(rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("OldAmount")) < 0 ||
		rs.GetFieldIndex(_T("BalanceFlag")) < 0 ||
		rs.GetFieldIndex(_T("StoreAreaID")) < 0 )
			return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsAlloy; pRS->QueryInterface(IID_IL3RecordSet,rsAlloy); pRS->Release();
	rsAlloy.AddField(_T("MaterialType"),VT_BSTR);
	rsAlloy.AddField(_T("MaterialID"),VT_BSTR);
	rsAlloy.AddField(_T("Amount"),VT_R8);
	rsAlloy.AppendRecord();

	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}
	rs.MoveFirst();
	while(!rs.IsEOF())
	{	
		rsAlloy.CopyCurRowFrom(rs);
		CString csArea = rs.GetFieldByName(_T("StoreAreaID")).ToCString();
		CString csAreaObj = GetAreaURI(csArea);
		L3DOUBLE fAmount = rs.GetFieldByName(_T("Amount")).ToDouble();
		L3LONG nBalanceFalg = rs.GetFieldByName(_T("BalanceFlag")).ToLong();
		L3DOUBLE fOldAmount = rs.GetFieldByName(_T("OldAmount")).ToDouble();
		L3DOUBLE fNewAmount =0;
		if(nBalanceFalg > 0)
		{
			CL3Variant valRet =InvokeObjectMethod(csAreaObj,_T("AddMaterials"),L3RECORDSET(rsAlloy));
			if(!valRet.IsValid()||valRet.IsError()||!valRet.ToBOOL())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -3;
			}
			fNewAmount = fOldAmount + fAmount;
		}
		else
		{
			CL3Variant valRet = InvokeObjectMethod(csAreaObj,_T("RemoveMaterials"),L3RECORDSET(rsAlloy));
			if(!valRet.IsValid()||valRet.IsError()||!valRet.ToBOOL())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
			fNewAmount = fOldAmount - fAmount;
		}
		//��¼��־
		CString csMatType = rs.GetFieldByName(_T("MaterialType")).ToCString();
		CString csTypeInfo = GetMaterialTypeInfoURI(csMatType);
		CString csPropLogType = GetObjectPropValue(csTypeInfo,_T("PropLogType")).ToCString();
		if(!csPropLogType.IsEmpty())
		{
			CL3RecordSetWrap rsPropLog;
			if(!CreateClassPropSet(csPropLogType,rsPropLog) && !rsPropLog.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			rsPropLog.DelField(_T("GUID"));
			rsPropLog.DelField(_T("Name"));
			rsPropLog.AppendRecord();
			rsPropLog.SetFieldByName(_T("ID"),rs.GetFieldByName(_T("MaterialID")));
			rsPropLog.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
			rsPropLog.SetFieldByName(_T("Position"),CL3Variant(csArea));
			rsPropLog.SetFieldByName(_T("NewOldFlag"),CL3Variant((LONG)0));
			rsPropLog.SetFieldByName(_T("Operator"),CL3Variant(csUser));
			rsPropLog.SetFieldByName(_T("Amount"),CL3Variant(fOldAmount));
			rsPropLog.AppendRecord();
			rsPropLog.SetFieldByName(_T("ID"),rs.GetFieldByName(_T("MaterialID")));
			rsPropLog.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
			rsPropLog.SetFieldByName(_T("Position"),CL3Variant(csArea));
			rsPropLog.SetFieldByName(_T("NewOldFlag"),CL3Variant((LONG)1));
			rsPropLog.SetFieldByName(_T("Operator"),CL3Variant(csUser));
			rsPropLog.SetFieldByName(_T("Amount"),CL3Variant(fNewAmount));
			LONG nRet = CreateNewObjects(csPropLogType,rsPropLog);
			if(nRet < rsPropLog.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}

		rs.MoveNext();
		rsAlloy.MoveFirst();
	}


	if(bUseTrans)
		Commit(nTrans);

	return 0;
	// TODO : ���ڴ�����߼�����
}


/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3RECORDSET CAlloy_Store_Mag::GetUnitClosedHeatID(L3STRING strUnitID)
{
	if(strUnitID == NULL) return NULL;
	CString csUnitID = strUnitID;
	csUnitID.Trim();
	L3LONG nUnitType = _ttol(csUnitID.Mid(1,1));
	CString csUnit =csUnitID.Mid(2,1);
	CString csSQL;
	switch(nUnitType)
	{
		case UNIT_AREA_BOF: csSQL.Format(_T("select * from (select HeatID from %s where substr(HeatID,2,1) = %s order by HeatID desc) where rownum < 5"),BOF_BASE_DATA_CLASS_URI,csUnit); break;
		case UNIT_AREA_LF:  csSQL.Format(_T("select * from (select HeatID from %s where substr(TreatNo,1,1) = %s order by HeatID desc) where rownum < 5"),LF_BASE_DATA_CLASS_URI,csUnit);  break;
		case UNIT_AREA_RH:  csSQL.Format(_T("select * from (select HeatID from %s where substr(TreatNo,1,1) = %s order by HeatID desc) where rownum < 5"),RH_BASE_DATA_CLASS_URI,csUnit);  break;
		default : return NULL;
	}
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		return NULL;
	return rsResult.Detach();

}


/// <Param name="rsData" type="L3RECORDSET"></Param>
///�ϲ�����2009-03-27
/// </Method>
L3LONG CAlloy_Store_Mag::ResetWeight (L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if(rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Position")) < 0 )
			return -1;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csPosition = rs.GetFieldByName(_T("Position")).ToCString();
		CString csTemp = _T(" select GUID from MaterialPosition where Position ='%s' and MaterialID = '%s'");
		CString csSQL;
		csSQL.Format(csTemp,csPosition,csMaterialID);
		CL3RecordSetWrap rsGuid;
		if(!Query(csSQL,rsGuid) || rsGuid.IsNull() || rsGuid.GetRowCount()< 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
		rsGuid.MoveFirst();
		CString csGuid = rsGuid.GetFieldByIndex(0).ToCString();
		if(!DeleteOldObject(_T("MES\\MaterialData\\MaterialPosition\\")+csGuid))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}

		//��¼��־
		CString csMatType = rs.GetFieldByName(_T("MaterialType")).ToCString();
		CString csTypeInfo = GetMaterialTypeInfoURI(csMatType);
		CString csPropLogType = GetObjectPropValue(csTypeInfo,_T("PropLogType")).ToCString();
		if(!csPropLogType.IsEmpty())
		{
			CL3RecordSetWrap rsPropLog;
			if(!CreateClassPropSet(csPropLogType,rsPropLog) && !rsPropLog.IsNull())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;
			}
			rsPropLog.DelField(_T("GUID"));
			rsPropLog.DelField(_T("Name"));
			rsPropLog.AppendRecord();
			rsPropLog.SetFieldByName(_T("ID"),rs.GetFieldByName(_T("MaterialID")));
			rsPropLog.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
			rsPropLog.SetFieldByName(_T("Position"),CL3Variant(csPosition));
			rsPropLog.SetFieldByName(_T("NewOldFlag"),CL3Variant((LONG)2));
			rsPropLog.SetFieldByName(_T("Operator"),CL3Variant(csUser));
			rsPropLog.SetFieldByName(_T("Amount"),rs.GetFieldByName(_T("Amount")));
			LONG nRet = CreateNewObjects(csPropLogType,rsPropLog);
			if(nRet < rsPropLog.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}

		rs.MoveNext();
	}
	if(bUseTrans)
		Commit(nTrans);
	return 0;
}


// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
/// 
/// ����NC�Ͻ���������,����input����,����ϱ�,���յ��ı�2009-04-05
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CAlloy_Store_Mag::AlloyBackAcceptFromNC (L3RECORDSET rsData)
{
	CL3RecordSetWrap rsAlloyData =rsData;
	if( rsAlloyData.IsNull() || rsAlloyData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//��ΰ��
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	//�Ͻ��Ƴ�
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(ALLOY_OUT_CLASS_URI,rs))
		return -1;

	rsAlloyData.MoveFirst();

	//�õ����ϺϽ����͡�����
	while(!rsAlloyData.IsEOF())
	{
		//2009-03-24 tangyi �޸�
		//CString csAlloyCode;
		//CString csInvcodeID = rsAlloyData.GetFieldByName(_T("cbaseid")).ToCString();
		//CString csTempSql = _T("select code from CBase_All_Code where Code_Group ='ALLOY_CODE' and NC_Code ='%s'");
		//CString csSQL;
		//csSQL.Format(csTempSql,csInvcodeID);
		//CL3RecordSetWrap rsResult;
		//if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		//	csAlloyCode = csInvcodeID;
		//else
		//{
		//	rsResult.MoveFirst();
		//	csAlloyCode = rsResult.GetFieldByIndex(0).ToCString();
		//}
		//2009-04-07���ϱ���ֱ�Ӵӵ������ȡ	
		rs.AppendRecord();
		CString csAlloyCode =  rsAlloyData.GetFieldByName(_T("Invcode")).ToCString();
		CString csBatchID = rsAlloyData.GetFieldByName(_T("vbatchcode")).ToCString();
		L3DOUBLE nAmount = rsAlloyData.GetFieldByName(_T("ninnum")).ToDouble();
		rs.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
		rs.SetFieldByName(_T("Amount"),CL3Variant(nAmount*1000));
		rs.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
		rs.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
		rs.SetFieldByName(_T("Type"),L3LONG(2));
		rs.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
		rs.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
		rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
		rs.SetFieldByName(_T("StoreAreaID"),CL3Variant(_T("S81P01")));
		rsAlloyData.MoveNext();
	}

	CString csInputCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("RemoveMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
		return -3;

	rs.MoveFirst();
	if(CreateNewObjects(ALLOY_OUT_CLASS_URI,rs) < rs.GetRowCount())
		return -4;

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("Alloy_Add_Material"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Alloy_Add_Material"),nStoreEvent);

	// TODO : ���ڴ�����߼�����
	return 0;
}


// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
/// 
/// �Ͻ�����ȡ��2009-04-05
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CAlloy_Store_Mag::AlloyInStoreCancel (L3RECORDSET rsData)
{
	CL3RecordSetWrap rsAlloyData =rsData;
	if( rsAlloyData.IsNull() || rsAlloyData.GetRowCount() < 1)
		return -1;

	if (rsAlloyData.GetFieldIndex(_T("Amount")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("MaterialType")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("MaterialID")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("Position")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("Alloy_Code")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("Batch_ID")) < 0 )
			return -1;

	rsAlloyData.MoveFirst();

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//��ΰ��
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	//�Ͻ������־
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(ALLOY_OUT_CLASS_URI,rs))
		return -1;

	//�õ����ϺϽ����͡�����

	//2009-03-24 tangyi �޸�
	rs.AppendRecord();
	rs.CopyCurRowFrom(rsAlloyData);
	rs.SetFieldByName(_T("Type"),L3LONG(1));
	rs.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rs.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
	rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
	CString csArea = rsAlloyData.GetFieldByName(_T("Position")).ToCString();
	rs.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));

	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CString csAreaObj = GetAreaURI(csArea);
	CL3Variant valRet = InvokeObjectMethod(csAreaObj,_T("RemoveMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	CString csCacheUri = GetInputCache();
	valRet = InvokeObjectMethod(csCacheUri,_T("AddMaterials"),L3RECORDSET(rs));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}

	
	rs.MoveFirst();
	if(CreateNewObjects(ALLOY_OUT_CLASS_URI,rs) < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//�ı�����ֵ2009-01-05 tangyi
	varStoreEvent = GetPropValue(_T("Alloy_Add_Material"));
	nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Alloy_Add_Material"),nStoreEvent);

	

	// TODO : ���ڴ�����߼�����
	return 0;
}


// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
/// 
/// �Ͻ�תɢװ��2009-04-08
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CAlloy_Store_Mag::AlloyTransToBulk (L3RECORDSET rsData)
{
	CL3RecordSetWrap rsAlloyData =rsData;
	if( rsAlloyData.IsNull() || rsAlloyData.GetRowCount() < 1)
		return -1;

	if (rsAlloyData.GetFieldIndex(_T("Amount")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("MaterialType")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("MaterialID")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("Position")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("Alloy_Code")) < 0 ||
		rsAlloyData.GetFieldIndex(_T("Batch_ID")) < 0 )
			return -1;

	rsAlloyData.MoveFirst();

	CString csBulkCode = rsAlloyData.GetFieldByName(_T("Alloy_Code")).ToCString();
	CString csBatchID	= rsAlloyData.GetFieldByName(_T("Batch_ID")).ToCString();


	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//��ΰ��
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	//ɢװ���뻺�����־
	CL3RecordSetWrap rsIn;
	if(!CreateClassPropSet(BULK_IN_CLASS_URI,rsIn))
		return -1;

	//�Ͻ���������־
	CL3RecordSetWrap rsOut;
	if(!CreateClassPropSet(ALLOY_OUT_CLASS_URI,rsOut))
		return -2;

	//�ж��Ƿ���תɢװ��
	CString csTemp = _T("select Code from CBase_All_Code where code ='%s' and Code_Group='BULK_CODE' ");
	CString csSQL;
	csSQL.Format(csTemp,csBulkCode);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		return -3;

	//�Ͻ��ϳ���
	rsOut.AppendRecord();
	rsOut.CopyCurRowFrom(rsAlloyData);
	rsOut.SetFieldByName(_T("Type"),L3LONG(4));
	rsOut.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rsOut.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
	rsOut.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsOut.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
	CString csArea = rsAlloyData.GetFieldByName(_T("Position")).ToCString();
	rsOut.SetFieldByName(_T("StoreAreaID"),CL3Variant(csArea));	

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	CString csCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csCacheUri,_T("RemoveMaterials"),L3RECORDSET(rsOut));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rsOut.MoveFirst();
	if(CreateNewObjects(ALLOY_OUT_CLASS_URI,rsOut) < rsOut.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}


	//ɢװ������⻺���
	rsIn.AppendRecord();
	rsIn.SetFieldByName(_T("MaterialID"),CL3Variant(csBulkCode + csBatchID));
	rsIn.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BULK));
	rsIn.SetFieldByName(_T("Amount"),rsAlloyData.GetFieldByName(_T("Amount")));
	rsIn.SetFieldByName(_T("Type"),L3LONG(4));
	rsIn.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rsIn.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
	rsIn.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsIn.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
	rsIn.SetFieldByName(_T("StoreAreaID"),CL3Variant(_T("S83P01")));	
	rsIn.SetFieldByName(_T("Bulk_Code"),CL3Variant(csBulkCode));
	rsIn.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
	csCacheUri = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S83P01");

	valRet = InvokeObjectMethod(csCacheUri,_T("AddMaterials"),L3RECORDSET(rsIn));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}
	
	rsIn.MoveFirst();
	if(CreateNewObjects(BULK_IN_CLASS_URI,rsIn) < rsIn.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	//����ɢװ�ϻ�������
	CL3RecordSetWrap rsBulk;
	if(!CreateClassPropSet(BULK_DATA_CLASS_URI,rsBulk))
		return -1;

	rsBulk.AppendRecord();
	rsBulk.SetFieldByName(_T("Status"),L3LONG(0));
	rsBulk.SetFieldByName(_T("Amount"),rsAlloyData.GetFieldByName(_T("Amount")));
	rsBulk.SetFieldByName(_T("MaterialID"),CL3Variant(csBulkCode + csBatchID));
	rsBulk.SetFieldByName(_T("Bulk_Code"),CL3Variant(csBulkCode));
	rsBulk.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
	
	CreateNewObjects(BULK_DATA_CLASS_URI,rsBulk);

	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("Alloy_Add_Material"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Alloy_Add_Material"),nStoreEvent);

	// TODO : ���ڴ�����߼�����
	return 0;
}

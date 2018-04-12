// �߼���CBulk_Store_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CBulk_Store_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CBulk_Store_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CBulk_Store_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CBulk_Store_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CBulk_Store_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ������⻺������URI
/// </summary>
CString CBulk_Store_Mag::GetInputCache()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return BULK_STORE_INCACHE_OBJ_URI;
}

/// <summary>
/// ���س��⻺������URI
/// </summary>
CString CBulk_Store_Mag::GetOutputCache()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return BULK_STORE_OUTCACHE_OBJ_URI;
}

/// <summary>
/// ��������¼��������
/// </summary>
CString CBulk_Store_Mag::GetInputLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return BULK_IN_CLASS_URI;
}

/// <summary>
/// ���س����¼��������
/// </summary>
CString CBulk_Store_Mag::GetOutputLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return BULK_OUT_CLASS_URI;
}

/// <summary>
/// ���ؿ�λ��������
/// </summary>
CString CBulk_Store_Mag::GetStoreAreaType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return _T("");
}

/// <summary>
///	��ʼ���ⷿ������
/// </summary>
BOOL CBulk_Store_Mag::InitializeStoreProperties()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::InitializeStoreProperties();
}

/// <summary>
/// ����λ�ĳ�ʼ������
/// </summary>
BOOL CBulk_Store_Mag::GetInitialAreaData(CL3RecordSetWrap& rs)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetInitialAreaData(rs);
}

/// <summary>
/// �ڿⷿ��ʼ��ɺ���á��̳������ش˺������ж���ĳ�ʼ��������
/// </summary>
void CBulk_Store_Mag::OnAfterStoreInitialized()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::OnAfterStoreInitialized();
}

/// <summary>
/// ���ǰԤ������������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsInputInfo : �����Ϣ��¼��
/// RET << TRUE ������⣻FALSE �ж����
/// </summary>
BOOL CBulk_Store_Mag::OnBeforeInputMaterials(L3RECORDSET rsInputInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeInputMaterials(rsInputInfo);
}

/// <summary>
/// �������������������ɹ�����á��̳�������ش˷������ж���Ĵ���
/// ARG >> rsInputInfo : �����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMaterialsInputted(L3RECORDSET rsInputInfo)
{
	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3LONG nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),L3LONG(nStoreEvent));
	
	//�ı�����ֵ2009-01-05 tangyi
	varStoreEvent = GetPropValue(_T("Bulk_Add_Material"));
	nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Bulk_Add_Material"),nStoreEvent);

	return TRUE;
}

/// <summary>
/// ����ǰԤ�����ڳ������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsOutputInfo : ������Ϣ��¼��
/// RET << TRUE �������⣻FALSE �жϳ���
/// </summary>
BOOL CBulk_Store_Mag::OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeOutputMaterials(rsOutputInfo);
}

/// <summary>
/// ������������ڳ�������ɹ�����á��̳�������ش˷������ж���Ĵ���
/// ARG >> rsOutputInfo : ������Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo)
{
	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//2009-04-08 tangyi��ɢװ�ϴӳ��⻺������ȥ,ɾ����������
	//CString csOutObj = GetOutputCache();
	//InvokeObjectMethod(csOutObj,_T("RemoveMaterials"),rsOutputInfo);

	return TRUE;
}

/// <summary>
/// �˹����ӿ��ǰԤ�����ڽ����˹����ӿ��ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG	>> rsMaterialInfo : ����������Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CBulk_Store_Mag::OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeAddMaterials(rsMaterialInfo);
}

/// <summary>
/// �˹����ӿ����������ڽ����˹����ӿ�����á��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : �����Ĳ�����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsAdded(rsMaterialInfo);
}

/// <summary>
/// �˹�ɾ�����ǰԤ�����ڽ����˹�ɾ�����ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG	>> rsMaterialInfo : ɾ��������Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CBulk_Store_Mag::OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeDeleteMaterials(rsMaterialInfo);
}

/// <summary>
/// �˹�ɾ�������������ڽ����˹�ɾ��������á��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo)
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
BOOL CBulk_Store_Mag::OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// �ƿ��������
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBulk_Store_Mag::OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	CL3RecordSetWrap rs = rsMaterialInfo;
	CL3RecordSetWrap rsTrans;
	if(!CreateClassPropSet(BULK_TRANS_CLASS_URI,rsTrans))
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
	if(CreateNewObjects(BULK_TRANS_CLASS_URI,L3RECORDSET(rsTrans)) < rsTrans.GetRowCount())
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
void CBulk_Store_Mag::PrepareInputLog(L3RECORDSET rsInputLog)
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
}

/// <summary>
/// �����¼Ԥ�����̳�������ش˷����ڳ���ǰ����������¼
/// </summary>
void CBulk_Store_Mag::PrepareOutputLog(L3RECORDSET rsOutputLog)
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
CString CBulk_Store_Mag::GetAreaURI(LPCTSTR lpcszAreaID)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������
	CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\");
	csAreaUri+=lpcszAreaID;

	return  csAreaUri;
}

/// <Method class="CBulk_Store_Mag" name="BulkDataAccept" type="L3BOOL">
/// 
/// ����NCɢ״���������,����input����,����ϱ�,���յ��ı�
/// ARG&gt;&gt; rsData:ɢ״����Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBulk_Store_Mag::BulkDataAccept(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsBulkData =rsData;
	if( rsBulkData.IsNull() || rsBulkData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//���ϼ�����⻺��
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.AddField(_T("Batch_ID"),VT_BSTR);
	rs.AddField(_T("Bulk_Code"),VT_BSTR);
	rsBulkData.MoveFirst();
	while(!rsBulkData.IsEOF())
	{
	
		//2009-06-19 �������ϱ����ж�Ϊ�ղ�����
		CString csBulkCode = rsBulkData.GetFieldByName(_T("Invcode")).ToCString();
		csBulkCode.Trim();
		if(csBulkCode.IsEmpty())
		{
			rsBulkData.MoveNext();
			continue;
		}
		rs.AppendRecord();
		CString csBatchID = rsBulkData.GetFieldByName(_T("vproductbatchcode")).ToCString();
		CString csMaterialID = csBulkCode + csBatchID;
		rs.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BULK));
		L3DOUBLE nWeight =0;
		if(rsBulkData.GetFieldIndex(_T("vbillcode")) < 0)
			nWeight = rsBulkData.GetFieldByName(_T("nnum")).ToDouble();
		else
			nWeight = rsBulkData.GetFieldByName(_T("ninnum")).ToDouble();
		rs.SetFieldByName(_T("Amount"),CL3Variant(nWeight*1000));
		rs.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
		rs.SetFieldByName(_T("Bulk_Code"),CL3Variant(csBulkCode));
		rsBulkData.MoveNext();
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

	//����������ݱ�
	CL3RecordSetWrap rsBulkBaseData;
	//modify by hyh 2012-04-11
	if(!CreateClassPropSet(BULK_DATA_CLASS_URI,rsBulkBaseData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	//end


	rsBulkBaseData.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CL3Variant valTemp = rs.GetFieldByName(_T("MaterialID"));
		if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		CString csMaterialID = valTemp.ToCString();	

		valTemp = rs.GetFieldByName(_T("Amount"));

		if(!valTemp.IsValid()||valTemp.IsError()||valTemp.IsNull())
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;
		}
		L3DOUBLE nAddAMount = valTemp.ToDouble();
		CString csBulkCode = rs.GetFieldByName(_T("Bulk_Code")).ToCString();
		CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString();
		rsBulkBaseData.SetFieldByName(_T("MaterialID"),  CL3Variant(csMaterialID));
		rsBulkBaseData.SetFieldByName(_T("Bulk_Code"),  CL3Variant(csBulkCode));
		rsBulkBaseData.SetFieldByName(_T("Amount"),  CL3Variant(nAddAMount));
		rsBulkBaseData.SetFieldByName(_T("Batch_ID"),  CL3Variant(csBatchID));

		CString csUri = BULK_DATA_CLASS_URI + _T("\\") + csMaterialID;

		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();

		if(!csObject.IsEmpty())
		{
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

		}
		else
		{
			CreateNewObject(BULK_DATA_CLASS_URI,CL3Variant(csMaterialID));
			if(!SetObjPropValues(csUri,rsBulkBaseData))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
		}
		rsBulkBaseData.MoveFirst();
		rs.MoveNext();
	}


	if(bUseTrans)
		Commit(nTrans);

	// TODO : ���ڴ�����߼�����
	return 0;
}


/// <Method class="CBulk_Store_Mag" name="BulkDataAcceptFromNC" type="L3BOOL">
/// 
/// ����NC����,����input����,����ϱ�,���յ��ı�
/// ARG&gt;&gt; rsScrapData:�ϸ�������Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBulk_Store_Mag::BulkDataAcceptFromNC(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsBulkData =rsData;
	if( rsBulkData.IsNull() || rsBulkData.GetRowCount() < 1)
		return -1;

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//���ϼ�����⻺��
	CString csInputCacheUri = GetInputCache();
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MES_MATERIAL_POSITION,rs))
		return -1;
	rs.DelField(_T("GUID"));
	rs.AddField(_T("Batch_ID"),VT_BSTR);
	rs.AddField(_T("Bulk_Code"),VT_BSTR);

	rsBulkData.MoveFirst();
	while(!rsBulkData.IsEOF())
	{
		//2009-04-07���ϱ���ֱ�Ӵӵ������ȡ	
		//2009-06-19 �������ϱ����ж�Ϊ�ղ�����
		CString csBulkCode = rsBulkData.GetFieldByName(_T("Invcode")).ToCString();
		csBulkCode.Trim();
		if(csBulkCode.IsEmpty())
		{
			rsBulkData.MoveNext();
			continue;
		}
		rs.AppendRecord();	
		CString csBatchID = rsBulkData.GetFieldByName(_T("vbatchcode")).ToCString();
		L3DOUBLE nAmount = rsBulkData.GetFieldByName(_T("ninnum")).ToDouble();
		rs.SetFieldByName(_T("MaterialID"),CL3Variant(csBulkCode + csBatchID));
		rs.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BULK));
		rs.SetFieldByName(_T("Amount"),CL3Variant(nAmount*1000));
		rs.SetFieldByName(_T("Bulk_Code"),CL3Variant(csBulkCode));
		rsBulkData.MoveNext();
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

	//����������ݱ�
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csMaterialID =rs.GetFieldByName(_T("MaterialID")).ToCString(); 
		CString csBatchID = rs.GetFieldByName(_T("Batch_ID")).ToCString(); 
		CString csBulkCode = rs.GetFieldByName(_T("Bulk_Code")).ToCString(); 
		CString csUri = BULK_DATA_CLASS_URI + _T("\\") + csMaterialID;	
		CL3Variant valTemp = rs.GetFieldByName(_T("Amount"));
		L3DOUBLE nAddAMount = valTemp.ToDouble();
		CString csObject = GetObjectPropValue(csUri,_T("MaterialID")).ToCString();
		csObject.Trim();
		if(!csObject.IsEmpty())
		{
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

		}
		else
		{
			CreateNewObject(BULK_DATA_CLASS_URI,CL3Variant(csMaterialID));
			if(!SetObjectPropValue(csUri,_T("Amount"),CL3Variant(nAddAMount)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}
			if(!SetObjectPropValue(csUri,_T("Bulk_Code"),CL3Variant(csBulkCode)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -6;
			}	
			//2009-03-20 liuzhiqiang
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
	CL3Variant varStoreEvent = GetPropValue(_T("Bulk_Add_Material"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Bulk_Add_Material"),nStoreEvent);

	// TODO : ���ڴ�����߼�����
	return 0;
}


/// <Method class="CBulk_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// ��ȡ��⻺�����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CBulk_Store_Mag::GetMaterialOnInputCache()
{
	CString csInputCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
		return NULL;
	CString csPos = valRet.ToCString();
	CString csTemp = _T(" select a.*,b.Batch_ID,b.Bulk_Code ");
			csTemp+= _T(" from %s a,%s b where a.MaterialID = b.MaterialID and a.Position = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,BULK_DATA_CLASS_URI,csPos);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CAlloy_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// ��ȡ����������Ϣ
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CBulk_Store_Mag::GetMaterialOnStore(L3STRING strStoreID)
{
	CString csPos = strStoreID;
	CString csTemp = _T(" select a.*,b.Batch_ID,b.Bulk_Code ");
			csTemp+= _T(" from %s a,%b b where a.MaterialID = b.MaterialID and a.Position = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,BULK_DATA_CLASS_URI,csPos);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CBulk_Store_Mag" name="GetBulkArea" type="L3RECORDSET">
/// 
/// ����ɢ״�ϱ����ȡ�ϲ�
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CBulk_Store_Mag::GetBulkArea(L3STRING strBulkCode)
{
	CString csTemp = _T(" select a.Bulk_Area,b.Code_Des from (select  Bulk_Area  from %s  where Bulk_Code ='%s') a, CBase_All_Code b where a.Bulk_Area = b.Code  order by b.Code_Des");
	CString csSQL;
	csSQL.Format(csTemp,BULK_REL_CLASS_URI,strBulkCode);
	CL3RecordSetWrap rsAlloyData;
	if(!Query(csSQL,rsAlloyData))
		return NULL;
	else
		return rsAlloyData.Detach();
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CAlloy_Store_Mag" name="GetAllMaterialOnStore" type="L3RECORDSET">
/// 
/// ��ȡ���п���������Ϣ
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CBulk_Store_Mag::GetAllMaterialOnStore(void)
{

	CString csTemp = _T(" select c.MaterialID,c.MaterialType,d.Code as Position,                         ");
			csTemp+= _T(" substr(d.Code,4,1) as PosDiff,c.Amount, c.Batch_ID,c.Bulk_Code  from           ");
			csTemp+= _T(" (select a.MaterialID,a.MaterialType,a.Amount,a.Position as Pos,                ");
			csTemp+= _T(" b.Batch_ID,b.Bulk_Code                                                         ");
			csTemp+= _T(" from %s a,%s b                                                                  ");
			csTemp+= _T(" where  a.MaterialID = b.MaterialID  and substr(a.Position,1,3) = '%s'           ");
			csTemp+= _T(" and  substr(a.Position,4,1) <> 'P' and  substr(a.Position,4,1) <> 'N' ) c ,     ");
			csTemp+= _T(" (select * from XGSTOREAREA where substr(Code,1,3) = '%s') d                     ");		
			csTemp+= _T(" where   c.Pos(+)  = d.Code        order by Position                             ");
			
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,BULK_DATA_CLASS_URI,STORE_ID_BULK,STORE_ID_BULK);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}


/// <Method class="CBulk_Store_Mag" name="GetAreaIDByUnitID" type="L3STRING">
/// 
/// ͨ����λ��ȡ�ϲֱ���
/// ARG&gt;&gt; strUnitID����λ
/// RET &lt;&lt;�����ϲֱ���
/// <Param name="strUnitID" type="L3STRING"></Param>
/// </Method>
L3STRING CBulk_Store_Mag::GetAreaIDByUnitID(L3STRING strUnitID)
{
	// TODO : ���ڴ�����߼�����
	return NULL;
}

/// <Method class="CBulk_Store_Mag" name="BulkApp" type="L3BOOL">
/// 
/// ɢ״��Ҫ������
/// ARG&gt;&gt; rsData:ɢ״����Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBulk_Store_Mag::BulkApp(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	if(rs.GetFieldIndex(_T("Bulk_Code")) < 0 ||
		rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("App_Time")) < 0 ||
		rs.GetFieldIndex(_T("App_Operator")) < 0 ||
		rs.GetFieldIndex(_T("App_UnitID")) < 0)
			return FALSE;

	rs.MoveFirst();
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	//��������
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("App_Operator"),CL3Variant(csUser));
		rs.SetFieldByName(_T("App_Time"),timeNow);
		rs.MoveNext();
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(CreateNewObjects(BULK_APP_CLASS_URI,L3RECORDSET(rs)) < rs.GetRowCount())
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

/// <Method class="CBulk_Store_Mag" name="BulkAppConfirm" type="L3BOOL">
/// 
/// ɢ״��Ҫ������ȷ��
/// ARG&gt;&gt; rsData:ɢ״����Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBulk_Store_Mag::BulkAppConfirm(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	rs.MoveFirst();
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	//��������
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("Confirm_Flag"),LONG(1));
		rs.SetFieldByName(_T("Confirm_Operator"),CL3Variant(csUser));
		rs.SetFieldByName(_T("Confirm_Time"),timeNow);
		rs.MoveNext();
	}
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(!SetObjsPropValues(BULK_APP_CLASS_URI,L3RECORDSET(rs)))
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

/// <Method class="CBulk_Store_Mag" name="BulkInStore" type="L3BOOL">
/// 
/// ɢ״�����
/// ARG&gt;&gt; rsInputInfoɢ״����Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBulk_Store_Mag::BulkInStore(L3RECORDSET rsInputInfo)
{
	//2009-03-26 ��,һ���ϲֿ��Զ�ͬһ���Ͻ��л�װ,����ʱ��,��ȡ�Ƚ��ȳ���ԭ��tangyi

	CL3RecordSetWrap rs =rsInputInfo;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if(rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("StoreAreaID")) < 0 ||
		rs.GetFieldIndex(_T("Batch_ID")) < 0 ||
		rs.GetFieldIndex(_T("Bulk_Code")) < 0)
			return -1;
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csArea = rs.GetFieldByName(_T("StoreAreaID")).ToCString();
		csArea.Trim();
		CString csMaterialType = rs.GetFieldByName(_T("MaterialType")).ToCString();
		//2009-03-26 tangyi�õ�����
		CString csBulkCode = rs.GetFieldByName(_T("Bulk_Code")).ToCString();
		CString strSQL;
		strSQL.Format(_T("SELECT * FROM %s WHERE Position = '%s'"),MES_MATERIAL_POSITION,csArea);
		CL3RecordSetWrap rsResult;
		if(!Query(strSQL,rsResult))
            return -2;
		rsResult.MoveFirst();
		while(!rsResult.IsEOF())
		{
			CString csCurMaterialID = rsResult.GetFieldByName(_T("MaterialID")).ToCString();
			//2009-03-26 tangyi�õ�����
			CString cBulkUri = BULK_DATA_CLASS_URI + _T("\\") + csCurMaterialID;
			CString csCurBulkCode = GetObjectPropValue(cBulkUri,_T("Bulk_Code")).ToCString();
			CString csCurMaterialType = rsResult.GetFieldByName(_T("MaterialType")).ToCString();
			if(csBulkCode != csCurBulkCode || csCurMaterialType!= csMaterialType)
				return -3;
			rsResult.MoveNext();
		}
		rs.MoveNext();
	}
	if(!InputMaterials(rsInputInfo))
		return -4;
	return 0;
}

//// <Method class="CAlloy_Store_Mag" name="AlloyInStore" type="L3LONG">
//// 
//// ת��
//// ARG&gt;&gt; rsInputInfo��Ϣ.������� MaterialType,MaterialID,Amount,Position,TargetID�⼸���ֶΡ�
//// &gt;&gt;strUnitID:����
//// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
//// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
//// <Param name="strUnitID" type="L3STRING"></Param>
/////</Method>
L3LONG CBulk_Store_Mag::BulkChangeStore(L3RECORDSET rsInputInfo)
{
	//ͬһ���ϲ�ֻ�ܼ���ͬһ���ε�ͬ�ֺϽ�
	CL3RecordSetWrap rs =rsInputInfo;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if (rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Position")) < 0 ||
		rs.GetFieldIndex(_T("Bulk_Code")) < 0 ||
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
		CString csBulkCode = rs.GetFieldByName(_T("Bulk_Code")).ToCString();
		CString strSQL;
		strSQL.Format(_T("SELECT * FROM %s WHERE Position = '%s'"),MES_MATERIAL_POSITION,csTargetArea);
		CL3RecordSetWrap rsResult;
		if(!Query(strSQL,rsResult))
            return -2;
		rsResult.MoveFirst();
		while(!rsResult.IsEOF())
		{
			CString csTargetMaterialID = rsResult.GetFieldByName(_T("MaterialID")).ToCString();
			//2009-03-26 tangyi�õ�����
			CString cBulkUri = BULK_DATA_CLASS_URI + _T("\\") + csTargetMaterialID;
			CString csTargetBulkCode = GetObjectPropValue(cBulkUri,_T("Bulk_Code")).ToCString();
			CString csCurMaterialType = rsResult.GetFieldByName(_T("MaterialType")).ToCString();
			if(csBulkCode != csTargetBulkCode || csCurMaterialType!= csMaterialType)
				return -3;
			rsResult.MoveNext();
		}
		rs.MoveNext();
	}
	//����׼��
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBulk; pRS->QueryInterface(IID_IL3RecordSet,rsBulk); pRS->Release();
	rsBulk.AddField(_T("MaterialType"),VT_BSTR);
	rsBulk.AddField(_T("MaterialID"),VT_BSTR);
	rsBulk.AddField(_T("Amount"),VT_R8);
	rsBulk.AddField(_T("TargetID"),VT_BSTR);
	rsBulk.AddField(_T("SourceID"),VT_BSTR);
	rsBulk.AddField(_T("Bulk_Code"),VT_BSTR);
	rsBulk.AddField(_T("Batch_ID"),VT_BSTR);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBulk.AppendRecord();
		rsBulk.SetFieldByName(_T("MaterialType"),rs.GetFieldByName(_T("MaterialType")));
		rsBulk.SetFieldByName(_T("MaterialID"),rs.GetFieldByName(_T("MaterialID")));
		rsBulk.SetFieldByName(_T("Amount"),rs.GetFieldByName(_T("Amount")));
		rsBulk.SetFieldByName(_T("TargetID"),rs.GetFieldByName(_T("TargetID")));
		rsBulk.SetFieldByName(_T("SourceID"),rs.GetFieldByName(_T("Position")));
		rsBulk.SetFieldByName(_T("Bulk_Code"),rs.GetFieldByName(_T("Bulk_Code")));
		rsBulk.SetFieldByName(_T("Batch_ID"),rs.GetFieldByName(_T("Batch_ID")));
		rs.MoveNext();
	}	
	//rsAlloy.MoveFirst();
	if(!MoveMaterials(L3RECORDSET(rsBulk)))
		return -4;
	return 0;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBulk_Store_Mag" name="GetBulkAppInfor" type="L3RECORDSET">
/// 
/// ��ȡδȷ��ɢ״��������Ϣ
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CBulk_Store_Mag::GetBulkAppInfor(L3STRING strDate)
{
	CString csTemp = _T(" select * from %s where Confirm_Flag = 0 and to_char(App_Time,'yyyy-mm-dd') = '%s' ");
	CString csSQL;
	csSQL.Format(csTemp,BULK_APP_CLASS_URI,strDate);
	CL3RecordSetWrap rsAlloyData;
	if(!Query(csSQL,rsAlloyData)||rsAlloyData.IsNull())
		return NULL;
	else
		return rsAlloyData.Detach();
	// TODO : ���ڴ�����߼�����
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBulk_Store_Mag" name="BulkAndAreaMap" type="L3BOOL">
/// 
/// �ϲ�����ά��
/// ARG&gt;&gt; rsData:�ϲ�������Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBulk_Store_Mag::BulkAndAreaMap(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	if(!SetObjsPropValues(BULK_REL_CLASS_URI,rsData))
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


/// <Method class="CAlloy_Store_Mag" name="AlloyModifyAmount" type="L3LONG">
/// 
/// ��������������
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.�������MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag �⼸���ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBulk_Store_Mag::ModifyMaterialAmount(L3RECORDSET rsData)
{
	CL3Variant valRet =InvokeObjectMethod(ALLOY_STORE_OBJ_URI,_T("ModifyMaterialAmountFuction"),rsData);
	if(!valRet.IsValid()||valRet.IsError())
		return -1;

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return valRet.ToLong();

}


// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
/// 
/// ɢװ������ȡ��2009-04-05
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CBulk_Store_Mag::BulkInStoreCancel (L3RECORDSET rsData)
{
	CL3RecordSetWrap rsBulkData =rsData;
	if( rsBulkData.IsNull() || rsBulkData.GetRowCount() < 1)
		return -1;

	if (rsBulkData.GetFieldIndex(_T("Amount")) < 0 ||
		rsBulkData.GetFieldIndex(_T("MaterialType")) < 0 ||
		rsBulkData.GetFieldIndex(_T("MaterialID")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Position")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Bulk_Code")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Batch_ID")) < 0 )
			return -1;

	rsBulkData.MoveFirst();

	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//��ΰ��
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	//ɢװ�ϳ�����־
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(BULK_OUT_CLASS_URI,rs))
		return -1;

	//�õ����ϺϽ����͡�����

	//2009-03-24 tangyi �޸�
	rs.AppendRecord();
	rs.CopyCurRowFrom(rsBulkData);
	rs.SetFieldByName(_T("Type"),L3LONG(1));
	rs.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rs.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
	rs.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rs.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
	CString csArea = rsBulkData.GetFieldByName(_T("Position")).ToCString();
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
	if(CreateNewObjects(BULK_OUT_CLASS_URI,rs) < rs.GetRowCount())
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
	varStoreEvent = GetPropValue(_T("Bulk_Add_Material"));
	nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Bulk_Add_Material"),nStoreEvent);

	// TODO : ���ڴ�����߼�����
	return 0;
}


// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
/// 
/// ɢװ��ת�Ͻ�2009-04-08
/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param> 
/// </Method>
L3LONG CBulk_Store_Mag::BulkTransToAlloy (L3RECORDSET rsData)
{
	CL3RecordSetWrap rsBulkData =rsData;
	if( rsBulkData.IsNull() || rsBulkData.GetRowCount() < 1)
		return -1;

	if (rsBulkData.GetFieldIndex(_T("Amount")) < 0 ||
		rsBulkData.GetFieldIndex(_T("MaterialType")) < 0 ||
		rsBulkData.GetFieldIndex(_T("MaterialID")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Position")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Bulk_Code")) < 0 ||
		rsBulkData.GetFieldIndex(_T("Batch_ID")) < 0 )
			return -1;

	rsBulkData.MoveFirst();

	CString csAlloyCode = rsBulkData.GetFieldByName(_T("Bulk_Code")).ToCString();
	CString csBatchID	= rsBulkData.GetFieldByName(_T("Batch_ID")).ToCString();


	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	//��ΰ��
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();

	//ɢװ�ϳ�����־
	CL3RecordSetWrap rsOut;
	if(!CreateClassPropSet(BULK_OUT_CLASS_URI,rsOut))
		return -1;

	//�Ͻ������־
	CL3RecordSetWrap rsIn;
	if(!CreateClassPropSet(ALLOY_IN_CLASS_URI,rsIn))
		return -2;

	//�ж��Ƿ���ת�Ͻ�
	CString csTemp = _T("select Code from CBase_All_Code where code ='%s' and Code_Group='ALLOY_CODE' ");
	CString csSQL;
	csSQL.Format(csTemp,csAlloyCode);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
		return -3;

	//ɢװ�ϳ���
	rsOut.AppendRecord();
	rsOut.CopyCurRowFrom(rsBulkData);
	rsOut.SetFieldByName(_T("Type"),L3LONG(3));
	rsOut.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rsOut.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
	rsOut.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsOut.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
	CString csArea = rsBulkData.GetFieldByName(_T("Position")).ToCString();
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
	if(CreateNewObjects(BULK_OUT_CLASS_URI,rsOut) < rsOut.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}


	//�Ͻ�����⻺���
	rsIn.AppendRecord();
	rsIn.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
	rsIn.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_ALLOY));
	rsIn.SetFieldByName(_T("Amount"),rsBulkData.GetFieldByName(_T("Amount")));
	rsIn.SetFieldByName(_T("Type"),L3LONG(3));
	rsIn.SetFieldByName(_T("Operator"),CL3Variant(GetCurrentUser()));
	rsIn.SetFieldByName(_T("LogDate"),CL3Variant(timeNow));
	rsIn.SetFieldByName(_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID")));
	rsIn.SetFieldByName(_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID")));	
	rsIn.SetFieldByName(_T("StoreAreaID"),CL3Variant(_T("S81P01")));	
	rsIn.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
	rsIn.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
	csCacheUri = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S81P01");

	valRet = InvokeObjectMethod(csCacheUri,_T("AddMaterials"),L3RECORDSET(rsIn));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}
	
	rsIn.MoveFirst();
	if(CreateNewObjects(ALLOY_IN_CLASS_URI,rsIn) < rsIn.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	//���ɺϽ��������
	CL3RecordSetWrap rsAlloy;
	if(!CreateClassPropSet(ALLOY_DATA_CLASS_URI,rsAlloy))
		return -1;

	rsAlloy.AppendRecord();
	rsAlloy.SetFieldByName(_T("Status"),L3LONG(0));
	rsAlloy.SetFieldByName(_T("Amount"),rsBulkData.GetFieldByName(_T("Amount")));
	rsAlloy.SetFieldByName(_T("MaterialID"),CL3Variant(csAlloyCode + csBatchID));
	rsAlloy.SetFieldByName(_T("Alloy_Code"),CL3Variant(csAlloyCode));
	rsAlloy.SetFieldByName(_T("Batch_ID"),CL3Variant(csBatchID));
	
	CreateNewObjects(ALLOY_DATA_CLASS_URI,rsAlloy);

	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("Bulk_Add_Material"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("Bulk_Add_Material"),nStoreEvent);

	// TODO : ���ڴ�����߼�����
	return 0;
}


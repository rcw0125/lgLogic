// �߼���CBloom_Store_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CBloom_Store_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CBloom_Store_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CBloom_Store_Mag.h"
#include "L3NameParser.h"

//������װ�ص�ϵͳ��ʱ��������
void CBloom_Store_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CBloom_Store_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// ������⻺������URI
/// </summary>
CString CBloom_Store_Mag::GetInputCache()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return _T("XGMESLogic\\BaseDataMag\\XGInterCache\\S71P01");	
}

/// <summary>
/// ���س��⻺������URI
/// </summary>
CString CBloom_Store_Mag::GetOutputCache()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return  BLOOM_STORE_OUTCACHE_OBJ_URI;	
}

/// <summary>
/// ��������¼��������
/// </summary>
CString CBloom_Store_Mag::GetInputLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return BLOOM_IN_CLASS_URI;
}

/// <summary>
/// ���س����¼��������
/// </summary>
CString CBloom_Store_Mag::GetOutputLogType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return BLOOM_OUT_CLASS_URI;
}

/// <summary>
/// ���ؿ�λ��������
/// </summary>
CString CBloom_Store_Mag::GetStoreAreaType()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return _T("");
}

/// <summary>
///	��ʼ���ⷿ������
/// </summary>
BOOL CBloom_Store_Mag::InitializeStoreProperties()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::InitializeStoreProperties();
}

/// <summary>
/// ����λ�ĳ�ʼ������
/// </summary>
BOOL CBloom_Store_Mag::GetInitialAreaData(CL3RecordSetWrap& rs)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::GetInitialAreaData(rs);
}

/// <summary>
/// �ڿⷿ��ʼ��ɺ���á��̳������ش˺������ж���ĳ�ʼ��������
/// </summary>
void CBloom_Store_Mag::OnAfterStoreInitialized()
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	__super::OnAfterStoreInitialized();
}

/// <summary>
/// ���ǰԤ������������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsInputInfo : �����Ϣ��¼��
/// RET << TRUE ������⣻FALSE �ж����
/// </summary>
BOOL CBloom_Store_Mag::OnBeforeInputMaterials(L3RECORDSET rsInputInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeInputMaterials(rsInputInfo);
}

/// <summary>
/// �������������������ɹ�����á��̳�������ش˷������ж���Ĵ���
/// ARG >> rsInputInfo : �����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMaterialsInputted(L3RECORDSET rsInputInfo)
{
	//���ø�������״̬Ϊ���,���¸�������λ��
	CL3RecordSetWrap rs = rsInputInfo;
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csPos = rs.GetFieldByName(_T("StoreAreaID")).ToCString();
		CString csPile = rs.GetFieldByName(_T("Cur_Pile_ID")).ToCString();
		CString csLayer = rs.GetFieldByName(_T("Cur_Layer_ID")).ToCString();
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csUir = BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID;
		if(!SetObjectPropValue(csUir,_T("Status"),CL3Variant(BLOOM_STATUS_INSTORE)))
			return false;
		if(!SetObjectPropValue(csUir,_T("Position"),CL3Variant(csPos)))
			return false;
		if(!SetObjectPropValue(csUir,_T("Cur_Pile_ID"),CL3Variant(csPile)))
			return false;
		if(!SetObjectPropValue(csUir,_T("Cur_Layer_ID"),CL3Variant(csLayer)))
			return false;
		rs.MoveNext();
	}
	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	//�ı�����ֵ2009-02-17 tangyi
	//varStoreEvent = GetPropValue(_T("BloomInStore"));
	//nStoreEvent = varStoreEvent.ToShort();
	//nStoreEvent = (nStoreEvent+1) % 9999;
	//SetPropValue(_T("BloomInStore"),nStoreEvent);
	
	return TRUE;
}

/// <summary>
/// ����ǰԤ�����ڳ������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
/// ARG >> rsOutputInfo : ������Ϣ��¼��
/// RET << TRUE �������⣻FALSE �жϳ���
/// </summary>
BOOL CBloom_Store_Mag::OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeOutputMaterials(rsOutputInfo);
}

/// <summary>
/// ������������ڳ�������ɹ�����á��̳�������ش˷������ж���Ĵ���
/// ARG >> rsOutputInfo : ������Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo)
{
	//���ø�������״̬Ϊ����
	CL3RecordSetWrap rs = rsOutputInfo;
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csUir = BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID;
		if(!SetObjectPropValue(csUir,_T("Status"),CL3Variant(BLOOM_STATUS_OUTSTORE)))
			return false;
		if(!SetObjectPropValue(csUir,_T("Position"),CL3Variant(STORE_ID_BLOOM_CACHE)))
			return false;
		rs.MoveNext();
	}
	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);
	//2009-03-06 tangyi�������ӳ��⻺������ȥ,ɾ����������
	CString csOutObj = GetOutputCache();
	rs.MoveFirst();
	InvokeObjectMethod(csOutObj,_T("RemoveMaterials"),(L3RECORDSET)rs);

	return TRUE;
}

/// <summary>
/// �˹����ӿ��ǰԤ�����ڽ����˹����ӿ��ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG	>> rsMaterialInfo : ����������Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CBloom_Store_Mag::OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeAddMaterials(rsMaterialInfo);
}

/// <summary>
/// �˹����ӿ����������ڽ����˹����ӿ�����á��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : �����Ĳ�����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterMaterialsAdded(rsMaterialInfo);
}

/// <summary>
/// �˹�ɾ�����ǰԤ�����ڽ����˹�ɾ�����ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
/// ARG	>> rsMaterialInfo : ɾ��������Ϣ��¼��
/// RET << ����TRUE������������FALSE�жϡ�
/// </summary>
BOOL CBloom_Store_Mag::OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeDeleteMaterials(rsMaterialInfo);
}

/// <summary>
/// �˹�ɾ�������������ڽ����˹�ɾ��������á��̳�������ش˷������ж��⴦��
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo)
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
BOOL CBloom_Store_Mag::OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeMoveMaterials(rsMaterialInfo);
}

/// <summary>
/// �ƿ��������
/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
/// RET << << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CBloom_Store_Mag::OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo)
{
	CL3RecordSetWrap rs = rsMaterialInfo;
	CL3RecordSetWrap rsTrans;
	if(!CreateClassPropSet(_T("XGMESLogic\\BloomStoreMag\\CBloom_Trans_Log"),rsTrans))
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
	if(CreateNewObjects(_T("XGMESLogic\\BloomStoreMag\\CBloom_Trans_Log"),L3RECORDSET(rsTrans)) < rsTrans.GetRowCount())
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
void CBloom_Store_Mag::PrepareInputLog(L3RECORDSET rsInputLog)
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
void CBloom_Store_Mag::PrepareOutputLog(L3RECORDSET rsOutputLog)
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
CString CBloom_Store_Mag::GetAreaURI(LPCTSTR lpcszAreaID)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������
	CString csAreaUri = _T("XGMESLogic\\BaseDataMag\\XGStoreArea\\");
	csAreaUri+=lpcszAreaID;

	return  csAreaUri;
}

/// <Method class="CBloom_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
/// 
/// ��ȡ��⻺�����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CBloom_Store_Mag::GetMaterialOnInputCache()
{
	CString csInputCacheUri = GetInputCache();
	CL3Variant valRet = InvokeObjectMethod(csInputCacheUri,_T("GetLocation"));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull())
		return NULL;
	CString csPos = valRet.ToCString();
	CString csTemp = _T(" select a.MaterialType,a.Amount,b.MaterialID,b.Cur_Pile_ID,b.Cur_Layer_ID,b.CasterID,NULL as StoreAreaID,                ");
			csTemp+= _T(" b.Thickness || '*' || b.Width || '*' || b.Length as Std,b.SteelGradeIndex,b.Waster_Count,b.Wrong_Count,                 ");
			csTemp+= _T(" b.Right_Count,b.Pre_SteelGradeIndex,b.Casting_No,b.Casting_Heat_Cnt,b.Process_Type,b.Plan_Ord_ID,b.Bloom_Count,         ");
			csTemp+= _T(" b.Cal_Weight,b.Right_Weight,b.Waster_Weight,b.Waster_Count1,b.Waster_Weight1,b.Waster_Reason1,b.Waster_Count2,b.Waster_Weight2,b.Waster_Reason2,");
			csTemp+= _T(" b.Waster_Count3,b.Waster_Weight3,b.Waster_Reason3,b.Wrong_Weight,b.Wrong_Count1,b.Wrong_Weight1,b.Wrong_Reason1,");
			csTemp+= _T(" b.Wrong_Count2,b.Wrong_Weight2,b.Wrong_Reason2,b.Wrong_Count3,b.Wrong_Weight3,b.Wrong_Reason3,b.SufaceDefactDes, ");
			csTemp+= _T(" b.Reason from %s a,%s b where a.MaterialID = b.MaterialID and a.Position = '%s' and Status =%s	              ");
	CString csSQL;
	csSQL.Format(csTemp,MES_MATERIAL_POSITION,BLOOM_DATA_CLASS_URI,csPos,BLOOM_STATUS_DOWN);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	else
		return rsResult.Detach();
}

/// <Method class="CBloom_Store_Mag" name="ChangeBloomPosition" type="L3BOOL">
/// 
/// ��λ���
/// ARG&gt;&gt; rsBloom���������ݣ������µĶ�λ��Ϣ
/// RET &lt;&lt;�ɹ�����True��ʧ�ܷ���False
/// <Param name="rsBloom" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CBloom_Store_Mag::ChangeBloomPosition(L3RECORDSET rsBloom)
{
	CL3RecordSetWrap rs =rsBloom;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if (rs.GetFieldIndex(_T("Amount")) < 0 ||
		rs.GetFieldIndex(_T("MaterialType")) < 0 ||
		rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Position")) < 0 ||
		rs.GetFieldIndex(_T("Cur_Pile_ID")) < 0 ||
		rs.GetFieldIndex(_T("Cur_Layer_ID")) < 0 ||
		rs.GetFieldIndex(_T("TargetID")) < 0 ||
		rs.GetFieldIndex(_T("Target_Pile_ID")) < 0 ||
		rs.GetFieldIndex(_T("Target_Layer_ID")) < 0 
		)
		return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloomChange; pRS->QueryInterface(IID_IL3RecordSet,rsBloomChange); pRS->Release();
	rsBloomChange.AddField(_T("MaterialType"),VT_BSTR);
	rsBloomChange.AddField(_T("MaterialID"),VT_BSTR);
	rsBloomChange.AddField(_T("Amount"),VT_INT);
	rsBloomChange.AddField(_T("TargetID"),VT_BSTR);
	rsBloomChange.AddField(_T("Target_Pile_ID"),VT_BSTR);
	rsBloomChange.AddField(_T("Target_Layer_ID"),VT_BSTR);
	rsBloomChange.AddField(_T("SourceID"),VT_BSTR);
	rsBloomChange.AddField(_T("Cur_Pile_ID"),VT_BSTR);
	rsBloomChange.AddField(_T("Cur_Layer_ID"),VT_BSTR);
	rsBloomChange.AppendRecord();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}
	rs.MoveFirst();
	//�ж��Ƿ�������
	while(!rs.IsEOF())
	{
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csOldPos = rs.GetFieldByName(_T("Position")).ToCString();
		CString csNewPos = rs.GetFieldByName(_T("TargetID")).ToCString();
		CString csUri = BLOOM_DATA_CLASS_URI + _T("\\") + csMaterialID;

		if(csOldPos!=csNewPos)//ת����
		{
			rsBloomChange.CopyCurRowFrom(rs);
			rsBloomChange.SetFieldByName(_T("SourceID"),rs.GetFieldByName(_T("Position")));
			if(!MoveMaterials(L3RECORDSET(rsBloomChange)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -3;
			}
			if(!SetObjectPropValue(csUri,_T("Position"),rs.GetFieldByName(_T("TargetID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
			if(!SetObjectPropValue(csUri,_T("Cur_Pile_ID"),rs.GetFieldByName(_T("Target_Pile_ID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
			if(!SetObjectPropValue(csUri,_T("Cur_Layer_ID"),rs.GetFieldByName(_T("Target_Layer_ID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
		}
		else//��λ���
		{
			if(!SetObjectPropValue(csUri,_T("Cur_Pile_ID"),rs.GetFieldByName(_T("Target_Pile_ID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}
			if(!SetObjectPropValue(csUri,_T("Cur_Layer_ID"),rs.GetFieldByName(_T("Target_Layer_ID"))))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -4;
			}

		}
		rsBloomChange.MoveFirst();
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return 0;
	// TODO : ���ڴ�����߼�����
}



/// <Method class="CBloom_Store_Mag" name="BloomColdSendInStore" type="L3BOOL">
/// 
/// ��һ��������⡣
/// ARG &gt;&gt; rsInputInfo : ���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID,Cur_Pile_ID,Cur_Layer_ID�⼸���ֶΡ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsInputInfo" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
/// </Method>
L3LONG CBloom_Store_Mag::BloomColdSendInStore(L3RECORDSET rsInputInfo)
{
	CL3RecordSetWrap rsData =rsInputInfo;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return -1;
	if(rsData.GetFieldIndex(_T("MaterialType")) < 0 ||
		rsData.GetFieldIndex(_T("MaterialID")) < 0 ||
		rsData.GetFieldIndex(_T("Amount")) < 0 ||
		rsData.GetFieldIndex(_T("StoreAreaID")) < 0 ||
		rsData.GetFieldIndex(_T("Cur_Layer_ID")) < 0 ||
		rsData.GetFieldIndex(_T("Cur_Pile_ID")) < 0)
			return -1;

	///2009-02-23���������ֶ�
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialType"),VT_BSTR);
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rsBloom.AddField(_T("Amount"),VT_INT);
	rsBloom.AddField(_T("StoreAreaID"),VT_BSTR);
	rsBloom.AddField(_T("SteelGradeIndex"),VT_BSTR);
	rsBloom.AddField(_T("Cur_Pile_ID"),VT_BSTR);
	rsBloom.AddField(_T("Cur_Layer_ID"),VT_BSTR);
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

	//�ж��Ƿ������������,����������ʵ����������ȷ�ϣ��������У������������¯��ȷ����־2009-03-16
	L3LONG nRtn = CCMConfirmHeat(rsInputInfo);
	if( nRtn < 0)
		return nRtn;

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		rsBloom.AppendRecord();
		rsBloom.CopyCurRowFrom(rsData);
		CString csMaterialID = rsData.GetFieldByName(_T("MaterialID")).ToCString();				
		CString csTemp = _T("select * from CBloom_Data where MaterialID = '%s'");
		CString csSQL;
		csSQL.Format(csTemp,csMaterialID);
		CL3RecordSetWrap rsBloomInfor;
		if(!Query(csSQL,rsBloomInfor)||rsBloomInfor.IsNull() ||rsBloomInfor.GetRowCount() < 1)
			return -3;

		rsBloomInfor.MoveFirst();
		rsBloomInfor.DelField(_T("Cur_Pile_ID"));
		rsBloomInfor.DelField(_T("Cur_Layer_ID"));
		rsBloom.CopyCurRowFrom(rsBloomInfor);
		rsData.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	if (!InputMaterials(rsBloom))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}

	//�޸�¯��ȷ����־2009-04-30 ��¯��ȷ���������Ƴ�tangyi
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMaterialID = rsData.GetFieldByName(_T("MaterialID")).ToCString();
		CString csTempSQL =_T("select TreatNo from CCCM_Base_Data where HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csMaterialID);
		CL3RecordSetWrap rsCCMHeat;
		if(!Query(csSQL,rsCCMHeat) || rsCCMHeat.IsNull() || rsCCMHeat.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -86;
		}
		rsCCMHeat.MoveFirst();

		while(!rsCCMHeat.IsEOF())
		{
			CString csTreatNo = rsCCMHeat.GetFieldByName(_T("TreatNo")).ToCString();
			CString csSteelUri = CL3NameParser::MergeClassDomainName(CCM_BASE_DATA_CLASS_URI,csTreatNo);
			if(!SetObjectPropValue(csSteelUri,_T("HeatConfirm"),L3SHORT(1)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -88;
			}
			rsCCMHeat.MoveNext();
		}
		rsData.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ��֪ͨͨѶ��NC��������Ͷ�ϡ������깤�������������Ϣ2009-03-16
	CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
	CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"),nEvent);

	return 0;
}

//2009-03-16 tangyi
L3LONG CBloom_Store_Mag::CCMConfirmHeat(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csHeatID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		csHeatID.Trim();
		//�鿴ת¯ʵ���Ƿ��Ѿ�ȷ��
		if(csHeatID.Left(1)=="2")
		{
		CString csBOFUri = CL3NameParser::MergeClassDomainName(BOF_BASE_DATA_CLASS_URI,csHeatID);
		CL3Variant vaBOFLocked = GetObjectPropValue(csBOFUri,_T("Locked"));
		if(!vaBOFLocked.ToShort()) 
			return -81;
		}
		else
		{
		
		}
		//CString csBOFUri = CL3NameParser::MergeClassDomainName(BOF_BASE_DATA_CLASS_URI,csHeatID);
		//CL3Variant vaBOFLocked = GetObjectPropValue(csBOFUri,_T("Locked"));
		//if(!vaBOFLocked.ToShort()) 
		//	return -81;
		//�õ�����·��
		CString csSteelUri = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,csHeatID);
		CString csPreHeatID = GetObjectPropValue(csSteelUri,_T("PreHeatID")).ToCString();
		csPreHeatID.Trim();
		CString csPlanUri = CL3NameParser::MergeClassDomainName(PLAN_TAPPING_CLASS_URI,csPreHeatID);
		CString csLFID = GetObjectPropValue(csPlanUri,_T("LFID")).ToCString();
		CString csRHID = GetObjectPropValue(csPlanUri,_T("RHID")).ToCString();
		//�鿴LF¯ʵ���Ƿ��Ѿ�ȷ��
		if(csLFID != _T("0"))
		{
			CString csTempSQL =_T("select TreatNo,Locked from CLF_Base_Data where HeatID ='%s' ");
			CString csSQL;
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsLFHeat;
			if(!Query(csSQL,rsLFHeat) || rsLFHeat.IsNull() || rsLFHeat.GetRowCount() < 1)
				return  -82;
			rsLFHeat.MoveFirst();
			while(!rsLFHeat.IsEOF())
			{
				CL3Variant vaLFLocked = rsLFHeat.GetFieldByName(_T("Locked"));
				if(!vaLFLocked.ToShort()) 
					return -83;
				rsLFHeat.MoveNext();
			}
		}
		//�鿴RH¯ʵ���Ƿ��Ѿ�ȷ��
		if(csRHID != _T("0"))
		{
			CString csTempSQL =_T("select TreatNo,Locked from CRH_Base_Data where HeatID ='%s' ");
			CString csSQL;
			csSQL.Format(csTempSQL,csHeatID);
			CL3RecordSetWrap rsRHHeat;
			if(!Query(csSQL,rsRHHeat) || rsRHHeat.IsNull() || rsRHHeat.GetRowCount() < 1)
				return -84;

			rsRHHeat.MoveFirst();
			while(!rsRHHeat.IsEOF())
			{
				CL3Variant vaRHLocked = rsRHHeat.GetFieldByName(_T("Locked"));
				if(!vaRHLocked.ToShort()) 
					return -85;
				rsRHHeat.MoveNext();
			}
		}	
		//�鿴����ʵ���Ƿ��Ѿ�ȷ��

		CString csTempSQL =_T("select TreatNo,Locked from CCCM_Base_Data where HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csHeatID);
		CL3RecordSetWrap rsCCMHeat;
		if(!Query(csSQL,rsCCMHeat) || rsCCMHeat.IsNull() || rsCCMHeat.GetRowCount() < 1)
			return -86;
		rsCCMHeat.MoveFirst();

		while(!rsCCMHeat.IsEOF())
		{
			CL3Variant vaCCMLocked = rsCCMHeat.GetFieldByName(_T("Locked"));
			if(!vaCCMLocked.ToShort()) 
				return -87;
			rsCCMHeat.MoveNext();
		}
		//�жϸ����Ƿ�����
		CString csBloomUri = CL3NameParser::MergeClassDomainName(BLOOM_DATA_CLASS_URI,csHeatID);
		CString csFinSteelGradeIndex = GetObjectPropValue(csBloomUri,_T("Final_SteelGradeIndex")).ToCString();
		csFinSteelGradeIndex.Trim();
		L3LONG nProcessType = GetObjectPropValue(csBloomUri,_T("Process_Type")).ToLong();
		csFinSteelGradeIndex.Trim();
		if(csFinSteelGradeIndex.IsEmpty())
			return -89;
		rs.MoveNext();
	}
	return 0;
}
/// <Method class="CBloom_Store_Mag" name="BloomHotSend" type="L3LONG">
/// 
/// ��������
/// ARG&gt;&gt; rsInputInfo : ���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID,Target,SteelGradeIndex�⼸���ֶΡ�
/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ��س������
/// <Param name="rsInputInfo" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
/// </Method>
L3LONG CBloom_Store_Mag::BloomHotSend(L3RECORDSET rsInputInfo)
{
	CL3RecordSetWrap rsData =rsInputInfo;
	if( rsData.IsNull() || rsData.GetRowCount() < 1)
		return -1;

	//�ж��Ƿ�������������,���͸�������ʵ����������ȷ�ϣ��������У������������¯��ȷ����־,�Ƴ�����2009-04-30
	L3LONG nRtn = CCMConfirmHeat(rsInputInfo);
	if( nRtn < 0)
		return nRtn;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	if(!InputMaterials(rsInputInfo))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -21;
	}
	if(!OutputMaterials(rsInputInfo))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -22;
	}

	//�޸�¯��ȷ����־2009-04-30 ��¯��ȷ���������Ƴ�tangyi
	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csMaterialID = rsData.GetFieldByName(_T("MaterialID")).ToCString();
		CString csTempSQL =_T("select TreatNo from CCCM_Base_Data where HeatID ='%s' ");
		CString csSQL;
		csSQL.Format(csTempSQL,csMaterialID);
		CL3RecordSetWrap rsCCMHeat;
		if(!Query(csSQL,rsCCMHeat) || rsCCMHeat.IsNull() || rsCCMHeat.GetRowCount() < 1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -86;
		}
		rsCCMHeat.MoveFirst();

		while(!rsCCMHeat.IsEOF())
		{
			CString csTreatNo = rsCCMHeat.GetFieldByName(_T("TreatNo")).ToCString();
			CString csSteelUri = CL3NameParser::MergeClassDomainName(CCM_BASE_DATA_CLASS_URI,csTreatNo);
			if(!SetObjectPropValue(csSteelUri,_T("HeatConfirm"),L3SHORT(1)))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -88;
			}
			rsCCMHeat.MoveNext();
		}
		rsData.MoveNext();
	}


	if(bUseTrans)
		Commit(nTrans);
	// TODO : ���ڴ�����߼�����

	//�ı�����ֵ��֪ͨͨѶ��NC��������Ͷ�ϡ������깤�������������Ϣ2009-03-16
	CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
	CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csBaseUri,_T("NC_Heat_Confirm_Event"),nEvent);

	return 0;
}


/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
/// 
/// ���ո������ͳ�����Ϣ2009-03-08
/// ARG&gt;&gt; rsData : ���ϳ�����Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID,Target�⼸���ֶΡ�
/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ��س������
/// <Param name="rsData" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
/// </Method>
L3LONG CBloom_Store_Mag::AcceptBloomOutStoreInforFromNC (L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rsBloom.AddField(_T("Target"),VT_BSTR);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBloom.AppendRecord();
		//2009-03-20 liuzhiqiang
		CString csMaterialID = rs.GetFieldByName(_T("vbatchcode")).ToString();
		if(csMaterialID.GetLength() > 9)
			csMaterialID = csMaterialID.Mid(0,9);
		rsBloom.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		//ת������ȥ�����
		CString csTarget;
		//CString csInvcodeID = rs.GetFieldByName(_T("cotherwhid")).ToCString();
		CString csInvcodeID = rs.GetFieldByName(_T("cwarehouseid")).ToCString();
		CString csTempSql = _T("select code from CBase_All_Code where Code_Group ='DESTINATION' and NC_Code ='%s'");
		CString csSQL;
		csSQL.Format(csTempSql,csInvcodeID);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull() || rsResult.GetRowCount() < 1)
			csTarget = csInvcodeID;
		else
		{
			rsResult.MoveFirst();
			csTarget = rsResult.GetFieldByIndex(0).ToCString();
		}	
		rsBloom.SetFieldByName(_T("Target"),CL3Variant(csTarget));
		rs.MoveNext();
	}

	return AcceptBloomOutStoreInfor((L3RECORDSET)rsBloom);
}
/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
/// 
/// ���ո������ͳ�����Ϣ
/// ARG&gt;&gt; rsData : ���ϳ�����Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID,Target�⼸���ֶΡ�
/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ��س������
/// <Param name="rsData" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
/// </Method>
L3LONG CBloom_Store_Mag::AcceptBloomOutStoreInfor(L3RECORDSET rsData)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if( rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Target")) < 0)
			return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialType"),VT_BSTR);
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rsBloom.AddField(_T("Amount"),VT_INT);
	rsBloom.AddField(_T("Target"),VT_BSTR);
	rsBloom.AddField(_T("SteelGradeIndex"),VT_BSTR);
	rsBloom.AddField(_T("StoreAreaID"),VT_BSTR);
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

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBloom.AppendRecord();
		rsBloom.CopyCurRowFrom(rs);
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();		
		//20081213tangyi ����û�����л��ߴ��в��������
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
		//2009-02-23
		CString csTemp = _T("select * from CBloom_Data where MaterialID = '%s'");
		CString csSQL;
		csSQL.Format(csTemp,csMaterialID);
		CL3RecordSetWrap rsBloomInfor;
		if(!Query(csSQL,rsBloomInfor)||rsBloomInfor.IsNull() ||rsBloomInfor.GetRowCount() < 1)
			return -6;
		rsBloomInfor.MoveFirst();
		rsBloom.CopyCurRowFrom(rsBloomInfor);

		rsBloom.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BLOOM));
		rsBloom.SetFieldByName(_T("StoreAreaID"),GetObjectPropValue(csBloomUri,_T("Position")));
		rsBloom.SetFieldByName(_T("Amount"),CL3Variant(L3LONG(1)));
	
		rs.MoveNext();
	}

	if(!OutputMaterials(L3RECORDSET(rsBloom)))
		return -3;
	return 0;
}

/// <Method class="CBloom_Store_Mag" name="GetBloomOnStoreArea" type="L3RECORDSET">
/// 
/// ��ȡ��������
/// ARG&gt;&gt; strArea:������
/// RET &lt;&lt;�������ݼ�
/// <Param name="strArea" type="L3STRING">��������</Param>
/// </Method>
L3RECORDSET CBloom_Store_Mag::GetBloomOnStoreArea(L3STRING strArea,L3STRING strHeatID)
{
	CString csPos = strArea;
	CString csHeatID = strHeatID;
	CString csTemp;
	CString csSQL;
	if(csPos.IsEmpty() && csHeatID.IsEmpty())
	{
		csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.Status > %s and  a.Status < %s and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID ");
		csSQL.Format(csTemp,BLOOM_STATUS_DOWN,BLOOM_STATUS_OUTSTORE);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
			return NULL;
		else
			return rsResult.Detach();
	}
	else
	{
		if(!csPos.IsEmpty() && csHeatID.IsEmpty())
		{
			csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.Position = '%s' and (a.Status > %s and  a.Status < %s )  and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
			csSQL.Format(csTemp,csPos,BLOOM_STATUS_DOWN,BLOOM_STATUS_OUTSTORE);
			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
				return NULL;
			else
				return rsResult.Detach();
		}
		else
		{
			if(csPos.IsEmpty() && !csHeatID.IsEmpty())
			{
				csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.MaterialID like ? and (a.Status > %s and  a.Status < %s ) and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
				csSQL.Format(csTemp,BLOOM_STATUS_DOWN,BLOOM_STATUS_OUTSTORE);
				CString csLikeMaterialID = _T("%") + csHeatID + _T("%");

				VARIANT valParams[1];
				valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csLikeMaterialID.AllocSysString();
				CL3RecordSetWrap rsResult;

				if (!QueryWithParam(csSQL,valParams,1,rsResult) || rsResult.IsNull())	  
				{
					::VariantClear(&valParams[0]);
					return NULL;
				}
				else
				{
					::VariantClear(&valParams[0]);
					return rsResult.Detach();
				}
			}
			else
			{
				if(!csPos.IsEmpty() && !csHeatID.IsEmpty())
				{
					csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.Position = '%s' and a.MaterialID like ? and (a.Status > %s and  a.Status < %s )  and a.SteelGradeIndex = b.SteelGradeIndex(+)  order by a.MaterialID");
					csSQL.Format(csTemp,csPos,BLOOM_STATUS_DOWN,BLOOM_STATUS_OUTSTORE);
					CString csLikeMaterialID = _T("%") + csHeatID + _T("%");
					VARIANT valParams[1];
					valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csLikeMaterialID.AllocSysString();
					CL3RecordSetWrap rsResult;

					if (!QueryWithParam(csSQL,valParams,1,rsResult) || rsResult.IsNull())	  
					{
						::VariantClear(&valParams[0]);
						return NULL;
					}
					else
					{
						::VariantClear(&valParams[0]);
						return rsResult.Detach();
					}
				}

			}
		}
	}

	return NULL;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBloom_Store_Mag" name="BloomFinish" type="L3BOOL">
/// 
/// ���������������
/// ARG &gt;&gt; rsHeatID: ����¯�š�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsHeat" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBloom_Store_Mag::BloomFinish(L3RECORDSET rsHeat)
{
	CL3RecordSetWrap rs = rsHeat;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return false;

	rs.MoveFirst();
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}
	while(!rs.IsEOF())
	{
		CString csHeatID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csUri = BLOOM_DATA_CLASS_URI  + _T("\\") + csHeatID;
		if(!SetObjectPropValue(csUri,_T("Status"),CL3Variant(BLOOM_STATUS_CHECK)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		if(!SetObjectPropValue(csUri,_T("FinishedTime"),CL3Variant(COleDateTime::GetCurrentTime())))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return false;
		}
		rs.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ��֪ͨ��������2009-01-02
	CString csUri = _T("XGMESLogic\\QualityMag\\CQA_HeatSufaceAssume_Mag\\QA_HeatSufaceAssume_Mag");
	CL3Variant varEvent = GetObjectPropValue(csUri,_T("HotJudgeEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csUri,_T("HotJudgeEvent"),nEvent);
	// TODO : ���ڴ�����߼�����

	//�ı�����ֵ2009-01-05 tangyi
	CL3Variant varStoreEvent = GetPropValue(_T("MaterialInputted"));
	L3SHORT nStoreEvent = varStoreEvent.ToShort();
	nStoreEvent = (nStoreEvent+1) % 9999;
	SetPropValue(_T("MaterialInputted"),nStoreEvent);

	return true;
}

/// <Method class="CBloom_Store_Mag" name="GetWillFinishBloom" type="L3VOID">
/// 
/// ��ȡ��������������
/// ARG&gt;&gt; strArea:������
/// RET &lt;&lt;�������ݼ�
/// <Param name="strArea" type="L3STRING">��������</Param>
/// </Method>
L3RECORDSET CBloom_Store_Mag::GetWillFinishBloom(L3STRING strArea,L3STRING strHeatID)
{
	//2009-01-07 tangyi�����϶��־
	CString csPos = strArea;
	CString csHeatID = strHeatID;
	CString csTemp;
	CString csSQL;
	if(csPos.IsEmpty() && csHeatID.IsEmpty())
	{
		csTemp = _T(" select a.*,b.SpileFlagDes  from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where (a.Status = %s or a.Status = %s) and  (a.SteelGradeIndex <> '%s' or (a.SteelGradeIndex  = '%s' and Process_Type = 1))  and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID ");
		csSQL.Format(csTemp,BLOOM_STATUS_INSTORE,BLOOM_STATUS_COOL_JUDGE,WAITING_FIN_JUDGE,WAITING_FIN_JUDGE);
		CL3RecordSetWrap rsResult;
		if(!Query(csSQL,rsResult) || rsResult.IsNull())
			return NULL;
		else
			return rsResult.Detach();
	}
	else
	{
		if(!csPos.IsEmpty() && csHeatID.IsEmpty())
		{
			csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.Position = '%s' and (a.Status = %s or a.Status = %s) and  (a.SteelGradeIndex <> '%s' or (a.SteelGradeIndex  = '%s' and a.Process_Type = 1)) and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
			csSQL.Format(csTemp,csPos,BLOOM_STATUS_INSTORE,BLOOM_STATUS_COOL_JUDGE,WAITING_FIN_JUDGE,WAITING_FIN_JUDGE);
			CL3RecordSetWrap rsResult;
			if(!Query(csSQL,rsResult) || rsResult.IsNull())
				return NULL;
			else
				return rsResult.Detach();
		}
		else
		{
			if(csPos.IsEmpty() && !csHeatID.IsEmpty())
			{
				csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b where a.MaterialID like ? and (a.Status = %s or a.Status = %s) and (a.SteelGradeIndex <> '%s' or (a.SteelGradeIndex  = '%s' and a.Process_Type = 1)) and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
				csSQL.Format(csTemp,BLOOM_STATUS_INSTORE,BLOOM_STATUS_COOL_JUDGE,WAITING_FIN_JUDGE,WAITING_FIN_JUDGE);
				CString csLikeMaterialID = _T("%") + csHeatID + _T("%");

				VARIANT valParams[1];
				valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csLikeMaterialID.AllocSysString();
				CL3RecordSetWrap rsResult;

				if (!QueryWithParam(csSQL,valParams,1,rsResult) || rsResult.IsNull())	  
				{
					::VariantClear(&valParams[0]);
					return NULL;
				}
				else
				{
					::VariantClear(&valParams[0]);
					return rsResult.Detach();
				}
			}
			else
			{
				if(!csPos.IsEmpty() && !csHeatID.IsEmpty())
				{
					csTemp = _T(" select a.*,b.SpileFlagDes   from VIEW_BLOOM_DATA a,CQA_Bloom_Std_Spile b  where a.Position = '%s' and a.MaterialID like ? and (a.Status = %s or a.Status = %s) and (a.SteelGradeIndex <> '%s' or (a.SteelGradeIndex  = '%s' and a.Process_Type = 1))  and a.SteelGradeIndex = b.SteelGradeIndex(+) order by a.MaterialID");
					csSQL.Format(csTemp,csPos,BLOOM_STATUS_INSTORE,BLOOM_STATUS_COOL_JUDGE,WAITING_FIN_JUDGE,WAITING_FIN_JUDGE);
					CString csLikeMaterialID = _T("%") + csHeatID + _T("%");
					VARIANT valParams[1];
					valParams[0].vt = VT_BSTR; valParams[0].bstrVal = csLikeMaterialID.AllocSysString();
					CL3RecordSetWrap rsResult;

					if (!QueryWithParam(csSQL,valParams,1,rsResult) || rsResult.IsNull())	  
					{
						::VariantClear(&valParams[0]);
						return NULL;
					}
					else
					{
						::VariantClear(&valParams[0]);
						return rsResult.Detach();
					}
				}

			}
		}
	}

	return NULL;

	// TODO : ���ڴ�����߼�����
}



/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
/// 
/// ���ո��߲ĸ���������Ϣ2009-04-02
/// <Param name="rsData" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
/// </Method>
L3LONG CBloom_Store_Mag::AcceptBloomBackInforFromNC (L3RECORDSET rsData)
{
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBloom.AppendRecord();
		//2009-03-20 liuzhiqiang
		CString csMaterialID = rs.GetFieldByName(_T("vbatchcode")).ToString();
		if(csMaterialID.GetLength() > 9)
			csMaterialID = csMaterialID.Mid(0,9);
		rsBloom.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rs.MoveNext();
	}

	return BloomBack((L3RECORDSET)rsBloom);
}


/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
/// 
/// ��������2009-04-02
/// <Param name="rsData" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
/// </Method>
L3LONG CBloom_Store_Mag::BloomBack (L3RECORDSET rsData)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rs =rsData;
	if( rs.IsNull() || rs.GetRowCount() < 1)
		return -1;
	if( rs.GetFieldIndex(_T("MaterialID")) < 0 )
			return -1;

	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsBloom; pRS->QueryInterface(IID_IL3RecordSet,rsBloom); pRS->Release();
	rsBloom.AddField(_T("MaterialType"),VT_BSTR);
	rsBloom.AddField(_T("MaterialID"),VT_BSTR);
	rsBloom.AddField(_T("Amount"),VT_INT);


	COleDateTime timeNow = COleDateTime::GetCurrentTime();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsBloom.AppendRecord();
		rsBloom.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_BLOOM));
		rsBloom.SetFieldByName(_T("MaterialID"),rs.GetFieldByName(_T("MaterialID")));
		rsBloom.SetFieldByName(_T("Amount"),L3LONG(1));
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

	//���뻺��
	CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\BaseDataMag\\XGStoreArea\\S71A01"),_T("AddMaterials"),L3RECORDSET(rsBloom));
	if(!valRet.IsValid()||valRet.IsError()||valRet.IsNull()|| !valRet.ToBOOL())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	//���ĸ���״̬
	rsBloom.MoveFirst();
	while(!rsBloom.IsEOF())
	{
		CString csMaterialID = rsBloom.GetFieldByName(_T("MaterialID")).ToCString();
		CString csBloomUri = BLOOM_DATA_CLASS_URI +_T("\\") + csMaterialID;
		if(!SetObjectPropValue(csBloomUri,_T("Position"),CL3Variant(_T("S71A01"))))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		if(!SetObjectPropValue(csBloomUri,_T("Status"),CL3Variant(BLOOM_STATUS_INSTORE)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		if(!SetObjectPropValue(csBloomUri,_T("Back_Flag"),L3LONG(1)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}
		if(!SetObjectPropValue(csBloomUri,_T("Back_Date"),CL3Variant(timeNow)))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -4;
		}		
		rsBloom.MoveNext();
	}
	if(bUseTrans)
			Commit(nTrans);
	return 0;
}
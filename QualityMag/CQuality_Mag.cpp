// �߼���CQuality_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CQuality_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CQuality_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CQuality_Mag.h"

//������װ�ص�ϵͳ��ʱ��������
void CQuality_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CQuality_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


/// <Method class="CQuality_Mag" name="BloomWaster" type="L3BOOL">
/// 
/// ����˦��
/// ARG&gt;&gt; rsData:˦�����ݣ�������HeatID��Bloom_Count��Cal_Weight��Waster_Total_Count��Waster_Total_Weight��Waster_Reason��Cut_SteelGradeIndex ��SteelGradeIndex��Produce_Date��Length��Width��Thickness�ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET">����ί�е���Ϣ</Param>
/// </Method>
L3BOOL CQuality_Mag::BloomWaster(L3RECORDSET rsData)
{
	return 0; // TODO : ���ڴ�����߼�����
}

/// <Method class="CQuality_Mag" name="GetUnspecifyDutyWasterData" type="L3RECORDSET">
/// 
/// ��ȡδָ�����ε�λ��˦��ʵ������
/// ARG&gt;&gt;strCasterID��������
/// RET &lt;&lt; �ɹ����ز�ѯ���ݼ���ʧ�ܷ���NULL��
/// <Param name="strCasterID" type=""></Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetUnspecifyDutyWasterData(L3STRING strCasterID)
{
	return 0;// TODO : ���ڴ�����߼�����
}

/// <Method class="CQuality_Mag" name="AddQAStdData" type="L3BOOL">
/// 
/// ������ҵ��׼����
/// ARG&gt;&gt; rsData:��׼����
///        &gt;&gt; strDataType:��������URI
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// <Param name="strDataType" type="L3STRING"></Param>
/// </Method>
L3LONG CQuality_Mag::AddBOFQAStdData(L3RECORDSET rsBase,
									  L3RECORDSET rsAr,
									  L3RECORDSET rsBlow,
									  L3RECORDSET rsBlowO2,
									  L3RECORDSET rsBulk,
									  L3RECORDSET rsFeed,
									  L3RECORDSET rsInFurnace,
									  L3RECORDSET rsLadle,
									  L3RECORDSET rsSlag,
									  L3RECORDSET rsTap)
{
	CL3RecordSetWrap rswBase = rsBase;
	if(rswBase.GetRowCount() < 1 || rswBase.IsNull())
		return -1;

	CL3RecordSetWrap rswAr = rsAr;
	if(rswAr.GetRowCount() < 1 || rswAr.IsNull())
		return -1;

	CL3RecordSetWrap rswBlow = rsBlow;
	if(rswBlow.GetRowCount() < 1 || rswBlow.IsNull())
		return -1;

	CL3RecordSetWrap rswBlowO2 = rsBlowO2;
	if(rswBlowO2.GetRowCount() < 1 || rswBlowO2.IsNull())
		return -1;

	CL3RecordSetWrap rswBulk = rsBulk;
	if(rswBulk.GetRowCount() < 1 || rswBulk.IsNull())
		return -1;

	CL3RecordSetWrap rswFeed = rsFeed;
	if(rswFeed.GetRowCount() < 1 || rswFeed.IsNull())
		return -1;

	CL3RecordSetWrap rswInFurnace = rsInFurnace;
	if(rswInFurnace.GetRowCount() < 1 || rswInFurnace.IsNull())
		return -1;

	CL3RecordSetWrap rswLadle = rsLadle;
	if(rswLadle.GetRowCount() < 1 || rswLadle.IsNull())
		return -1;

	CL3RecordSetWrap rswSlag = rsSlag;
	if(rswSlag.GetRowCount() < 1 || rswSlag.IsNull())
		return -1;

	CL3RecordSetWrap rswTap = rsTap;
	if(rswTap.GetRowCount() < 1 || rswTap.IsNull())
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// ���������׼����
	rswBase.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Base"),rswBase) < rswBase.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	
	rswAr.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ar"),rswAr) < rswAr.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswBlow.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Blow"),rswBlow) < rswBlow.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswBlowO2.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_BlowO2"),rswBlowO2) < rswBlowO2.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswBulk.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Bulk"),rswBulk) < rswBulk.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswFeed.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Feed"),rswFeed) < rswFeed.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswInFurnace.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_InToConver"),rswInFurnace) < rswInFurnace.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswLadle.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ladle"),rswLadle) < rswLadle.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSlag.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Slag_Ele"),rswSlag) < rswSlag.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswTap.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Tapping"),rswTap) < rswTap.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;

}

/// <Method class="CQuality_Mag" name="DelQAStdData" type="L3BOOL">
/// 
/// ɾ����ҵ��׼����
/// ARG&gt;&gt; rsData:��׼����
///        &gt;&gt; DataType:��������URI
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// <Param name="strDataType" type="L3STRING"></Param>
/// </Method>
L3LONG CQuality_Mag::DelBOFQAStdData(L3RECORDSET rsBase,
									  L3RECORDSET rsAr,
									  L3RECORDSET rsBlow,
									  L3RECORDSET rsBlowO2,
									  L3RECORDSET rsBulk,
									  L3RECORDSET rsFeed,
									  L3RECORDSET rsInFurnace,
									  L3RECORDSET rsLadle,
									  L3RECORDSET rsSlag,
									  L3RECORDSET rsTap)
{
	CL3RecordSetWrap rswBase = rsBase;
	if(rswBase.GetRowCount() < 1 || rswBase.IsNull())
		return -1;

	CL3RecordSetWrap rswAr = rsAr;
	if(rswAr.GetRowCount() < 1 || rswAr.IsNull())
		return -1;

	CL3RecordSetWrap rswBlow = rsBlow;
	if(rswBlow.GetRowCount() < 1 || rswBlow.IsNull())
		return -1;

	CL3RecordSetWrap rswBlowO2 = rsBlowO2;
	if(rswBlowO2.GetRowCount() < 1 || rswBlowO2.IsNull())
		return -1;

	CL3RecordSetWrap rswBulk = rsBulk;
	if(rswBulk.GetRowCount() < 1 || rswBulk.IsNull())
		return -1;

	CL3RecordSetWrap rswFeed = rsFeed;
	if(rswFeed.GetRowCount() < 1 || rswFeed.IsNull())
		return -1;

	CL3RecordSetWrap rswInFurnace = rsInFurnace;
	if(rswInFurnace.GetRowCount() < 1 || rswInFurnace.IsNull())
		return -1;

	CL3RecordSetWrap rswLadle = rsLadle;
	if(rswLadle.GetRowCount() < 1 || rswLadle.IsNull())
		return -1;

	CL3RecordSetWrap rswSlag = rsSlag;
	if(rswSlag.GetRowCount() < 1 || rswSlag.IsNull())
		return -1;

	CL3RecordSetWrap rswTap = rsTap;
	if(rswTap.GetRowCount() < 1 || rswTap.IsNull())
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// ���������׼����
	rswBase.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Base"),rswBase) < rswBase.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	
	rswAr.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ar"),rswAr) < rswAr.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswBlow.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Blow"),rswBlow) < rswBlow.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswBlowO2.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_BlowO2"),rswBlowO2) < rswBlowO2.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswBulk.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Bulk"),rswBulk) < rswBulk.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswFeed.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Feed"),rswFeed) < rswFeed.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswInFurnace.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_InToConver"),rswInFurnace) < rswInFurnace.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswLadle.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ladle"),rswLadle) < rswLadle.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSlag.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Slag_Ele"),rswSlag) < rswSlag.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswTap.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Tapping"),rswTap) < rswTap.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;

}

/// <Method class="CQuality_Mag" name="ModQAStdData" type="L3BOOL">
/// 
/// �޸���ҵ��׼����
/// ARG&gt;&gt; rsData:��׼����
///        &gt;&gt; DataType:��������URI
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// <Param name="strDataType" type="L3STRING"></Param>
/// </Method>
L3LONG CQuality_Mag::ModBOFQAStdData(L3RECORDSET rsBase,
									  L3RECORDSET rsAr,
									  L3RECORDSET rsBlow,
									  L3RECORDSET rsBlowO2,
									  L3RECORDSET rsBulk,
									  L3RECORDSET rsFeed,
									  L3RECORDSET rsInFurnace,
									  L3RECORDSET rsLadle,
									  L3RECORDSET rsSlag,
									  L3RECORDSET rsTap)
{
	CL3RecordSetWrap rswBase = rsBase;
	CL3RecordSetWrap rswAr = rsAr;
	CL3RecordSetWrap rswBlow = rsBlow;
	CL3RecordSetWrap rswBlowO2 = rsBlowO2;
	CL3RecordSetWrap rswBulk = rsBulk;
	CL3RecordSetWrap rswFeed = rsFeed;
	CL3RecordSetWrap rswInFurnace = rsInFurnace;
	CL3RecordSetWrap rswLadle = rsLadle;
	CL3RecordSetWrap rswSlag = rsSlag;
	CL3RecordSetWrap rswTap = rsTap;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	if(rswBase.GetRowCount() > 0) 
	{
		rswBase.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Base"),rswBase))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}
	
	if(rswAr.GetRowCount() > 0) 
	{
		rswAr.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ar"),rswAr))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswBlow.GetRowCount() > 0) 
	{
		rswBlow.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Blow"),rswBlow))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswBlowO2.GetRowCount() > 0) 
	{
		rswBlowO2.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_BlowO2"),rswBlowO2))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswBlowO2.GetRowCount() > 0) 
	{
		rswBulk.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Bulk"),rswBulk))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswFeed.GetRowCount() > 0) 
	{
		rswFeed.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Feed"),rswFeed))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswInFurnace.GetRowCount() > 0) 
	{
		rswInFurnace.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_InToConver"),rswInFurnace))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswLadle.GetRowCount() > 0) 
	{
		rswLadle.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Ladle"),rswLadle))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswSlag.GetRowCount() > 0) 
	{
		rswSlag.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Slag_Ele"),rswSlag))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswSlag.GetRowCount() > 0) 
	{
		rswTap.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_BOF_Std_Tapping"),rswTap))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;

}

/// <Method class="CQuality_Mag" name="GetQAStdData" type="L3RECORDSET">
/// 
/// ��ȡ������׼���ݼ�
/// ARG&gt;&gt; rsCondition ������StdDataType
/// RET &lt;&lt; �ɹ��������ݼ���ʧ�ܷ���NULL��
/// <Param name="rsCondition" type="L3RECORDSET"></Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdData(L3RECORDSET rsCondition)
{
	return 0;// TODO : ���ڴ�����߼�����
}

L3LONG CQuality_Mag::AddLFQAStdData(L3RECORDSET rsBase,
									L3RECORDSET rsAlloy,
									L3RECORDSET rsFeed,
									L3RECORDSET rsLadle,
									L3RECORDSET rsProc,
									L3RECORDSET rsSlag,
									L3RECORDSET rsSlagEle)
{
	CL3RecordSetWrap rswBase = rsBase;
	if(rswBase.GetRowCount() < 1 || rswBase.IsNull())
		return -1;

	CL3RecordSetWrap rswAlloy = rsAlloy;
	if(rswAlloy.GetRowCount() < 1 || rswAlloy.IsNull())
		return -1;

	CL3RecordSetWrap rswFeed = rsFeed;
	if(rswFeed.GetRowCount() < 1 || rswFeed.IsNull())
		return -1;

	CL3RecordSetWrap rswLadle = rsLadle;
	if(rswLadle.GetRowCount() < 1 || rswLadle.IsNull())
		return -1;

	CL3RecordSetWrap rswProc = rsProc;
	if(rswProc.GetRowCount() < 1 || rswProc.IsNull())
		return -1;

	CL3RecordSetWrap rswSlag = rsSlag;
	if(rswSlag.GetRowCount() < 1 || rswSlag.IsNull())
		return -1;

	CL3RecordSetWrap rswSlagEle = rsSlagEle;
	if(rswSlagEle.GetRowCount() < 1 || rswSlagEle.IsNull())
		return -1;


	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// ���������׼����
	rswBase.MoveFirst();
	if (CreateNewObjects(QA_LF_STD_BASE_CLASS_URI,rswBase) < rswBase.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	
	rswAlloy.MoveFirst();
	if (CreateNewObjects(QA_LF_STD_ALLOY_CLASS_URI,rswAlloy) < rswAlloy.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswFeed.MoveFirst();
	if (CreateNewObjects(QA_LF_STD_FEED_CLASS_URI,rswFeed) < rswFeed.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswLadle.MoveFirst();
	if (CreateNewObjects(QA_LF_STD_LADLE_CLASS_URI,rswLadle) < rswLadle.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswProc.MoveFirst();
	if (CreateNewObjects(QA_LF_STD_PROC_CLASS_URI,rswProc) < rswProc.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSlag.MoveFirst();
	if (CreateNewObjects(QA_LF_STD_SLAG_CLASS_URI,rswSlag) < rswSlag.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSlagEle.MoveFirst();
	if (CreateNewObjects(QA_LF_STD_SLAG_ELE_CLASS_URI,rswSlagEle) < rswSlagEle.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;
}

// �޸�LF�����׼
L3LONG CQuality_Mag::ModLFQAStdData(L3RECORDSET rsBase,
									L3RECORDSET rsAlloy,
									L3RECORDSET rsFeed,
									L3RECORDSET rsLadle,
									L3RECORDSET rsProc,
									L3RECORDSET rsSlag,
									L3RECORDSET rsSlagEle)
{
	CL3RecordSetWrap rswBase = rsBase;
	CL3RecordSetWrap rswAlloy = rsAlloy;
	CL3RecordSetWrap rswFeed = rsFeed;
	CL3RecordSetWrap rswLadle = rsLadle;
	CL3RecordSetWrap rswProc = rsProc;
	CL3RecordSetWrap rswSlag = rsSlag;
	CL3RecordSetWrap rswSlagEle = rsSlagEle;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	if(rswBase.GetRowCount() > 0) 
	{
		rswBase.MoveFirst();
		if (!SetObjsPropValues(QA_LF_STD_BASE_CLASS_URI,rswBase))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}
	
	if(rswAlloy.GetRowCount() > 0) 
	{
		rswAlloy.MoveFirst();
		if (!SetObjsPropValues(QA_LF_STD_ALLOY_CLASS_URI,rswAlloy))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswFeed.GetRowCount() > 0) 
	{
		rswFeed.MoveFirst();
		if (!SetObjsPropValues(QA_LF_STD_FEED_CLASS_URI,rswFeed))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswLadle.GetRowCount() > 0) 
	{
		rswLadle.MoveFirst();
		if (!SetObjsPropValues(QA_LF_STD_LADLE_CLASS_URI,rswLadle))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswProc.GetRowCount() > 0) 
	{
		rswProc.MoveFirst();
		if (!SetObjsPropValues(QA_LF_STD_PROC_CLASS_URI,rswProc))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswSlag.GetRowCount() > 0) 
	{
		rswSlag.MoveFirst();
		if (!SetObjsPropValues(QA_LF_STD_SLAG_CLASS_URI,rswSlag))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswSlagEle.GetRowCount() > 0) 
	{
		rswSlagEle.MoveFirst();
		if (!SetObjsPropValues(QA_LF_STD_SLAG_ELE_CLASS_URI,rswSlagEle))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;

}

L3LONG CQuality_Mag::DelLFQAStdData(L3RECORDSET rsBase,
									L3RECORDSET rsAlloy,
									L3RECORDSET rsFeed,
									L3RECORDSET rsLadle,
									L3RECORDSET rsProc,
									L3RECORDSET rsSlag,
									L3RECORDSET rsSlagEle)
{
	CL3RecordSetWrap rswBase = rsBase;
	if(rswBase.GetRowCount() < 1 || rswBase.IsNull())
		return -1;

	CL3RecordSetWrap rswAlloy = rsAlloy;
	if(rswAlloy.GetRowCount() < 1 || rswAlloy.IsNull())
		return -1;

	CL3RecordSetWrap rswFeed = rsFeed;
	if(rswFeed.GetRowCount() < 1 || rswFeed.IsNull())
		return -1;

	CL3RecordSetWrap rswLadle = rsLadle;
	if(rswLadle.GetRowCount() < 1 || rswLadle.IsNull())
		return -1;

	CL3RecordSetWrap rswProc = rsProc;
	if(rswProc.GetRowCount() < 1 || rswProc.IsNull())
		return -1;

	CL3RecordSetWrap rswSlag = rsSlag;
	if(rswSlag.GetRowCount() < 1 || rswSlag.IsNull())
		return -1;

	CL3RecordSetWrap rswSlagEle = rsSlagEle;
	if(rswSlagEle.GetRowCount() < 1 || rswSlagEle.IsNull())
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// ���������׼����
	rswBase.MoveFirst();
	if (DeleteOldObjects(QA_LF_STD_BASE_CLASS_URI,rswBase) < rswBase.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	
	rswAlloy.MoveFirst();
	if (DeleteOldObjects(QA_LF_STD_ALLOY_CLASS_URI,rswAlloy) < rswAlloy.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswFeed.MoveFirst();
	if (DeleteOldObjects(QA_LF_STD_FEED_CLASS_URI,rswFeed) < rswFeed.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswLadle.MoveFirst();
	if (DeleteOldObjects(QA_LF_STD_LADLE_CLASS_URI,rswLadle) < rswLadle.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswProc.MoveFirst();
	if (DeleteOldObjects(QA_LF_STD_PROC_CLASS_URI,rswProc) < rswProc.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSlag.MoveFirst();
	if (DeleteOldObjects(QA_LF_STD_SLAG_CLASS_URI,rswSlag) < rswSlag.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSlagEle.MoveFirst();
	if (CreateNewObjects(QA_LF_STD_SLAG_ELE_CLASS_URI,rswSlagEle) < rswSlagEle.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;

}
L3LONG CQuality_Mag::AddRHQAStdData(L3RECORDSET rsBase,
									L3RECORDSET rsAlloy,
									L3RECORDSET rsFeed,
									L3RECORDSET rsProc)
{
	CL3RecordSetWrap rswBase = rsBase;
	if(rswBase.GetRowCount() < 1 || rswBase.IsNull())
		return -1;

	CL3RecordSetWrap rswAlloy = rsAlloy;
	if(rswAlloy.GetRowCount() < 1 || rswAlloy.IsNull())
		return -1;

	CL3RecordSetWrap rswFeed = rsFeed;
	if(rswFeed.GetRowCount() < 1 || rswFeed.IsNull())
		return -1;

	CL3RecordSetWrap rswProc = rsProc;
	if(rswProc.GetRowCount() < 1 || rswProc.IsNull())
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// ���������׼����
	rswBase.MoveFirst();
	if (CreateNewObjects(QA_RH_STD_BASE_CLASS_URI,rswBase) < rswBase.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	
	rswAlloy.MoveFirst();
	if (CreateNewObjects(QA_RH_STD_ALLOY_CLASS_URI,rswAlloy) < rswAlloy.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswFeed.MoveFirst();
	if (CreateNewObjects(QA_RH_STD_FEED_CLASS_URI,rswFeed) < rswFeed.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswProc.MoveFirst();
	if (CreateNewObjects(QA_RH_STD_PROC_CLASS_URI,rswProc) < rswProc.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}


	if(bUseTrans)
		Commit(nTrans);

	return 0;
}

// �޸�RH�����׼
L3LONG CQuality_Mag::ModRHQAStdData(L3RECORDSET rsBase,
									L3RECORDSET rsAlloy,
									L3RECORDSET rsFeed,
									L3RECORDSET rsProc)
{
	CL3RecordSetWrap rswBase = rsBase;
	CL3RecordSetWrap rswAlloy = rsAlloy;
	CL3RecordSetWrap rswFeed = rsFeed;
	CL3RecordSetWrap rswProc = rsProc;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	if(rswBase.GetRowCount() > 0) 
	{
		rswBase.MoveFirst();
		if (!SetObjsPropValues(QA_RH_STD_BASE_CLASS_URI,rswBase))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}
	
	if(rswAlloy.GetRowCount() > 0) 
	{
		rswAlloy.MoveFirst();
		if (!SetObjsPropValues(QA_RH_STD_ALLOY_CLASS_URI,rswAlloy))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswFeed.GetRowCount() > 0) 
	{
		rswFeed.MoveFirst();
		if (!SetObjsPropValues(QA_RH_STD_FEED_CLASS_URI,rswFeed))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswProc.GetRowCount() > 0) 
	{
		rswProc.MoveFirst();
		if (!SetObjsPropValues(QA_RH_STD_PROC_CLASS_URI,rswProc))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;

}

// ɾ��RH�����׼
L3LONG CQuality_Mag::DelRHQAStdData(L3RECORDSET rsBase,
									L3RECORDSET rsAlloy,
									L3RECORDSET rsFeed,
									L3RECORDSET rsProc)
{
	CL3RecordSetWrap rswBase = rsBase;
	if(rswBase.GetRowCount() < 1 || rswBase.IsNull())
		return -1;

	CL3RecordSetWrap rswAlloy = rsAlloy;
	if(rswAlloy.GetRowCount() < 1 || rswAlloy.IsNull())
		return -1;

	CL3RecordSetWrap rswFeed = rsFeed;
	if(rswFeed.GetRowCount() < 1 || rswFeed.IsNull())
		return -1;

	CL3RecordSetWrap rswProc = rsProc;
	if(rswProc.GetRowCount() < 1 || rswProc.IsNull())
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// ���������׼����
	rswBase.MoveFirst();
	if (DeleteOldObjects(QA_RH_STD_BASE_CLASS_URI,rswBase) < rswBase.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	
	rswAlloy.MoveFirst();
	if (DeleteOldObjects(QA_RH_STD_ALLOY_CLASS_URI,rswAlloy) < rswAlloy.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswFeed.MoveFirst();
	if (DeleteOldObjects(QA_RH_STD_FEED_CLASS_URI,rswFeed) < rswFeed.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswProc.MoveFirst();
	if (DeleteOldObjects(QA_RH_STD_PROC_CLASS_URI,rswProc) < rswProc.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;

}

// ����CCM�����׼
L3LONG CQuality_Mag::AddCCMQAStdData(L3RECORDSET rsBase,
									L3RECORDSET rsFlux,
									L3RECORDSET rsProc,
									L3RECORDSET rsProdProc,
									L3RECORDSET rsSpec,
									L3RECORDSET rsSpeed,
									L3RECORDSET rsTundish)
{
	CL3RecordSetWrap rswBase = rsBase;
	if(rswBase.GetRowCount() < 1 || rswBase.IsNull())
		return -1;

	CL3RecordSetWrap rswFlux = rsFlux;
	if(rswFlux.GetRowCount() < 1 || rswFlux.IsNull())
		return -1;

	CL3RecordSetWrap rswProc = rsProc;
	if(rswProc.GetRowCount() < 1 || rswProc.IsNull())
		return -1;

	CL3RecordSetWrap rswProdProc = rsProdProc;
	if(rswProdProc.GetRowCount() < 1 || rswProdProc.IsNull())
		return -1;

	CL3RecordSetWrap rswSpec = rsSpec;
	if(rswSpec.GetRowCount() < 1 || rswSpec.IsNull())
		return -1;

	CL3RecordSetWrap rswSpeed = rsSpeed;
	if(rswSpeed.GetRowCount() < 1 || rswSpeed.IsNull())
		return -1;

	CL3RecordSetWrap rswTundish = rsTundish;
	if(rswTundish.GetRowCount() < 1 || rswTundish.IsNull())
		return -1;


	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// ���������׼����
	rswBase.MoveFirst();
	if (CreateNewObjects(QA_CCM_STD_BASE_CLASS_URI,rswBase) < rswBase.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	
	rswFlux.MoveFirst();
	if (CreateNewObjects(QA_CCM_STD_FLUX_CLASS_URI,rswFlux) < rswFlux.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswProc.MoveFirst();
	if (CreateNewObjects(QA_CCM_STD_PROC_CLASS_URI,rswProc) < rswProc.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswProdProc.MoveFirst();
	if (CreateNewObjects(QA_CCM_STD_PRODPROC_CLASS_URI,rswProdProc) < rswProdProc.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSpec.MoveFirst();
	if (CreateNewObjects(QA_CCM_STD_SPEC_CLASS_URI,rswSpec) < rswSpec.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSpeed.MoveFirst();
	if (CreateNewObjects(QA_CCM_STD_SPEED_CLASS_URI,rswSpeed) < rswSpeed.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswTundish.MoveFirst();
	if (CreateNewObjects(QA_CCM_STD_TUNDISH_CLASS_URI,rswTundish) < rswTundish.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;
}

// �޸�CCM�����׼
L3LONG CQuality_Mag::ModCCMQAStdData(L3RECORDSET rsBase,
									L3RECORDSET rsFlux,
									L3RECORDSET rsProc,
									L3RECORDSET rsProdProc,
									L3RECORDSET rsSpec,
									L3RECORDSET rsSpeed,
									L3RECORDSET rsTundish)
{
	CL3RecordSetWrap rswBase = rsBase;
	CL3RecordSetWrap rswFlux = rsFlux;
	CL3RecordSetWrap rswProc = rsProc;
	CL3RecordSetWrap rswProdProc = rsProdProc;
	CL3RecordSetWrap rswSpec = rsSpec;
	CL3RecordSetWrap rswSpeed = rsSpeed;
	CL3RecordSetWrap rswTundish = rsTundish;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	if(rswBase.GetRowCount() > 0) 
	{
		rswBase.MoveFirst();
		if (!SetObjsPropValues(QA_CCM_STD_BASE_CLASS_URI,rswBase))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}
	
	if(rswFlux.GetRowCount() > 0) 
	{
		rswFlux.MoveFirst();
		if (!SetObjsPropValues(QA_CCM_STD_FLUX_CLASS_URI,rswFlux))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswProc.GetRowCount() > 0) 
	{
		rswProc.MoveFirst();
		if (!SetObjsPropValues(QA_CCM_STD_PROC_CLASS_URI,rswProc))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswProdProc.GetRowCount() > 0) 
	{
		rswProdProc.MoveFirst();
		if (!SetObjsPropValues(QA_CCM_STD_PRODPROC_CLASS_URI,rswProdProc))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswSpec.GetRowCount() > 0) 
	{
		rswSpec.MoveFirst();
		if (!SetObjsPropValues(QA_CCM_STD_SPEC_CLASS_URI,rswSpec))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswSpeed.GetRowCount() > 0) 
	{
		rswSpeed.MoveFirst();
		if (!SetObjsPropValues(QA_CCM_STD_SPEED_CLASS_URI,rswSpeed))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(rswTundish.GetRowCount() > 0) 
	{
		rswTundish.MoveFirst();
		if (!SetObjsPropValues(QA_CCM_STD_TUNDISH_CLASS_URI,rswTundish))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;

}

L3LONG CQuality_Mag::DelCCMQAStdData(L3RECORDSET rsBase,
									L3RECORDSET rsFlux,
									L3RECORDSET rsProc,
									L3RECORDSET rsProdProc,
									L3RECORDSET rsSpec,
									L3RECORDSET rsSpeed,
									L3RECORDSET rsTundish)
{
	CL3RecordSetWrap rswBase = rsBase;
	if(rswBase.GetRowCount() < 1 || rswBase.IsNull())
		return -1;

	CL3RecordSetWrap rswFlux = rsFlux;
	if(rswFlux.GetRowCount() < 1 || rswFlux.IsNull())
		return -1;

	CL3RecordSetWrap rswProc = rsProc;
	if(rswProc.GetRowCount() < 1 || rswProc.IsNull())
		return -1;

	CL3RecordSetWrap rswProdProc = rsProdProc;
	if(rswProdProc.GetRowCount() < 1 || rswProdProc.IsNull())
		return -1;

	CL3RecordSetWrap rswSpec = rsSpec;
	if(rswSpec.GetRowCount() < 1 || rswSpec.IsNull())
		return -1;

	CL3RecordSetWrap rswSpeed = rsSpeed;
	if(rswSpeed.GetRowCount() < 1 || rswSpeed.IsNull())
		return -1;

	CL3RecordSetWrap rswTundish = rsTundish;
	if(rswTundish.GetRowCount() < 1 || rswTundish.IsNull())
		return -1;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// ���������׼����
	rswBase.MoveFirst();
	if (DeleteOldObjects(QA_CCM_STD_BASE_CLASS_URI,rswBase) < rswBase.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	
	rswFlux.MoveFirst();
	if (DeleteOldObjects(QA_CCM_STD_FLUX_CLASS_URI,rswFlux) < rswFlux.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswProc.MoveFirst();
	if (DeleteOldObjects(QA_CCM_STD_PROC_CLASS_URI,rswProc) < rswProc.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswProdProc.MoveFirst();
	if (DeleteOldObjects(QA_CCM_STD_PRODPROC_CLASS_URI,rswProdProc) < rswProdProc.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSpec.MoveFirst();
	if (DeleteOldObjects(QA_CCM_STD_SPEC_CLASS_URI,rswSpec) < rswSpec.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswSpeed.MoveFirst();
	if (DeleteOldObjects(QA_CCM_STD_SPEED_CLASS_URI,rswSpeed) < rswSpeed.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	rswTundish.MoveFirst();
	if (CreateNewObjects(QA_CCM_STD_TUNDISH_CLASS_URI,rswTundish) < rswTundish.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	if(bUseTrans)
		Commit(nTrans);

	return 0;

}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFBase" type="L3RECORDSET">
/// ��ȡBOF�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFBase(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_BASE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_BASE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFAr" type="L3RECORDSET">
/// ��ȡBOF�����׼(�������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFAr(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_AR_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_AR_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFBlow" type="L3RECORDSET">
/// ��ȡBOF�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFBlow(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_BLOW_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_BLOW_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFBlowOxygen" type="L3RECORDSET">
/// ��ȡBOF�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFBlowOxygen(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_BLOWO2_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_BLOWO2_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFBulk" type="L3RECORDSET">
/// ��ȡBOF�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFBulk(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_BULK_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_BULK_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFFeed" type="L3RECORDSET">
/// ��ȡBOF�����׼(ι˿����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFFeed(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_FEED_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_FEED_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFInCtrlElement" type="L3RECORDSET">
/// ��ȡBOF�����׼(�ڿسɷ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFInCtrlElement(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_INCTR_ELE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_INCTR_ELE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFMaterial" type="L3RECORDSET">
/// ��ȡBOF�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFMaterial(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_INTOCONVER_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_INTOCONVER_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFLadle" type="L3RECORDSET">
/// ��ȡBOF�����׼(�ְ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFLadle(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_LADLE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_LADLE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFSlagElement" type="L3RECORDSET">
/// ��ȡBOF�����׼(���ɷ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFSlagElement(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_SLAG_ELE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_SLAG_ELE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForBOFTapping" type="L3RECORDSET">
/// ��ȡBOF�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForBOFTapping(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_BOF_STD_TAPPING_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_BOF_STD_TAPPING_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForLFBase" type="L3RECORDSET">
/// ��ȡLF�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForLFBase(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_LF_STD_BASE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LF_STD_BASE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="GetQAStdForLFAlloy" type="L3RECORDSET">
/// ��ȡLF�����׼(�Ͻ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForLFAlloy(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_LF_STD_ALLOY_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LF_STD_ALLOY_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForLFFeed" type="L3RECORDSET">
/// ��ȡLF�����׼(ι˿����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForLFFeed(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_LF_STD_FEED_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LF_STD_FEED_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForLFInCtrlElement" type="L3RECORDSET">
/// ��ȡLF�����׼(�ڿسɷ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForLFInCtrlElement(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_LF_STD_INCTR_ELE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LF_STD_INCTR_ELE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForLFLadle" type="L3RECORDSET">
/// ��ȡLF�����׼(�ְ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForLFLadle(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_LF_STD_LADLE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LF_STD_LADLE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForLFProc" type="L3RECORDSET">
/// ��ȡLF�����׼(��ҵ����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForLFProc(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_LF_STD_PROC_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LF_STD_PROC_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForLFSlag" type="L3RECORDSET">
/// ��ȡLF�����׼(������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForLFSlag(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_LF_STD_SLAG_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LF_STD_SLAG_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForLFSlagElement" type="L3RECORDSET">
/// ��ȡLF�����׼(���ɷ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForLFSlagElement(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_LF_STD_SLAG_ELE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LF_STD_SLAG_ELE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForRHBase" type="L3RECORDSET">
/// ��ȡRH�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForRHBase(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_RH_STD_BASE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_RH_STD_BASE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForRHAlloy" type="L3RECORDSET">
/// ��ȡRH�����׼(�Ͻ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForRHAlloy(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_RH_STD_ALLOY_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_RH_STD_ALLOY_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForRHFeed" type="L3RECORDSET">
/// ��ȡRH�����׼(ι˿����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForRHFeed(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_RH_STD_FEED_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_RH_STD_FEED_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForRHInCtrlElement" type="L3RECORDSET">
/// ��ȡRH�����׼(�ڿ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForRHInCtrlElement(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_RH_STD_INCTR_ELE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_RH_STD_INCTR_ELE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForRHProc" type="L3RECORDSET">
/// ��ȡRH�����׼(��ҵ����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForRHProc(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_RH_STD_PROC_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_RH_STD_PROC_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForCCMFlux" type="L3RECORDSET">
/// ��ȡCCM�����׼(�а����Ǽ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForCCMFlux(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_CCM_STD_FLUX_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_CCM_STD_FLUX_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForCCMProc" type="L3RECORDSET">
/// ��ȡCCM�����׼(��ҵ����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForCCMProc(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_CCM_STD_PROC_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_CCM_STD_PROC_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForCCMProd" type="L3RECORDSET">
/// ��ȡCCM�����׼(�Ƴ�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForCCMProd(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_CCM_STD_PRODPROC_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_CCM_STD_PRODPROC_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForCCMSpec" type="L3RECORDSET">
/// ��ȡCCM�����׼(�������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForCCMSpec(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_CCM_STD_SPEC_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_CCM_STD_SPEC_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForCCMSpeed" type="L3RECORDSET">
/// ��ȡCCM�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForCCMSpeed(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_CCM_STD_SPEED_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_CCM_STD_SPEED_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForCCMTundish" type="L3RECORDSET">
/// ��ȡCCM�����׼(�а�����)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForCCMTundish(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_CCM_STD_TUNDISH_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_CCM_STD_TUNDISH_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}
/// <Method class="CQuality_Mag" name="GetQAStdForCCMBase" type="L3RECORDSET">
/// ��ȡCCM�����׼(��������)��
/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdForCCMBase(L3STRING strSteelGradeIndex)
{
	CString cstrSteelGradeIndex = strSteelGradeIndex;
	CString strSQL;
	strSQL.Format(_T("select * from %s where SteelGradeIndex = '%s'")
		,QA_CCM_STD_BASE_CLASS_URI,cstrSteelGradeIndex);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_CCM_STD_BASE_CLASS_URI,rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQuality_Mag" name="BloomWasterDutySpecify" type="L3RECORDSET">
/// ��ȡCCM�����׼(��������)��
/// <Param name="rsData" type="L3RECORDSET">CQA_Bloom_Waster_Data���������ε�λ�����α�־=1</Param>
/// </Method>
L3LONG CQuality_Mag::BloomWasterDutySpecify(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if (rs.GetRowCount() < 1)
		return -1;

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
    //�������ε�λ�����α�־=1
	rs.MoveFirst();
	if(!SetObjsPropValues(_T("XGMESLogic\\BloomStoreMag\\CQA_Bloom_Waster_Data"),rs))
	{
		if (bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	if (bUseTrans) 
		Commit(nTrans);

	return rs.GetRowCount();
}

/// <Method class="CQuality_Mag" name="GetSampleApplyData" type="L3RECORDSET">
/// ��ȡ���ص�(��λ)��ȡ����ί�е�����
/// <Param name="strSampleAddr" type="L3STRING">ȡ���ص�(��λ)</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetSampleApplyData(L3STRING strSampleAddr)
{
	CString cstrSampleAddr = strSampleAddr;	
	CString csSQL;
	CString cstrSQL  = _T("  Select *  from %s                                             ");
			cstrSQL += _T("  where Sample_Date >= (select TRUNC(SYSDATE) from dual) - 5   ");
	if (cstrSampleAddr.Left(1) == MIF_SAMPLE_TYPE) 
	{
		cstrSQL += _T("  and (Sample_Address = '%s' or Sample_Address = '%s' or Sample_Address = '%s')");
		cstrSQL += _T("  and ((Back_Flag = 1) or (SendFlag = 0) or (ReSample_Flag = 1)) order by Sample_Date desc ");

		csSQL.Format(cstrSQL,QA_LAB_SHEET_APP_CLASS_URI,cstrSampleAddr,QA_Sample_Addr_TB,QA_Sample_Addr_TC); 
	}
	else if (cstrSampleAddr.Left(1) == _T("G"))
	{
		cstrSQL += _T("  and substr(Sample_Address,1,1) = 'G' and Sample_Type = 'ZG'");
		cstrSQL += _T("  and ((Back_Flag = 1) or (SendFlag = 0) or (ReSample_Flag = 1)) order by Sample_Date desc ");
	
		csSQL.Format(cstrSQL,QA_LAB_SHEET_APP_CLASS_URI); 
	}
	//������P
		else if (cstrSampleAddr.Left(1) == _T("T"))
	{
		cstrSQL += _T("  and Sample_Address = '%s' ");
		cstrSQL += _T("  and ((Back_Flag = 1) or (SendFlag = 0) or (ReSample_Flag = 1)) order by Sample_Date desc ");
	
		csSQL.Format(cstrSQL,QA_LAB_SHEET_APP_CLASS_URI,cstrSampleAddr); 
	}
	else
	{
		cstrSQL += _T("  and Sample_Address = '%s'");
		cstrSQL += _T("  and ((Back_Flag = 1) or (SendFlag = 0) or (ReSample_Flag = 1)) order by Sample_Date desc ");
	
		csSQL.Format(cstrSQL,QA_LAB_SHEET_APP_CLASS_URI,cstrSampleAddr); 
	}

	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQuality_Mag" name="GetHeatIDByAddr" type="L3RECORDSET">
/// ͨ��ȡ���ص��ȡ��λ�����¯¯��
/// <Param name="strSampleAddr" type="L3STRING">ȡ���ص�(��λ)</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetHeatIDByAddr(L3STRING strSampleAddr)
{
	CString cstrSampleAddr = strSampleAddr;
	CString strSQL;
    if (cstrSampleAddr.GetLength() != 2)
		return NULL;

	if (cstrSampleAddr.Left(1) == _T("Z"))
	{
		strSQL.Format(_T("select HeatID from (select * from CBOF_Base_Data where SubStr(HeatID,2,1) = '%s' order by HeatID desc) where rownum < 4")
			,cstrSampleAddr.Right(1));
	}
	else if (cstrSampleAddr.Left(1) == _T("F"))
	{
		strSQL.Format(_T("select HeatID from (select * from CLF_Base_Data where SubStr(TreatNo,1,1) = '%s' order by TreatNo desc) where rownum < 4")
			,cstrSampleAddr.Right(1));
	}
	else if (cstrSampleAddr.Left(1) == _T("R"))
	{
		strSQL.Format(_T("select HeatID from (select * from CRH_Base_Data where SubStr(TreatNo,1,1) = '%s' order by TreatNo desc) where rownum < 4")
			,cstrSampleAddr.Right(1));
	}
	else if (cstrSampleAddr.Left(1) == _T("T"))
	{
		strSQL.Format(_T("select HeatID from (select * from Cdep_Base_Data  order by HeatID desc) where rownum < 4"));
	}
		else if (cstrSampleAddr.Left(1) == _T("A"))
	{
		strSQL.Format(_T("select HeatID from (select * from CAOD_Base_Data  order by HeatID desc) where rownum < 4"));
	}
	else if (cstrSampleAddr.Left(1) == _T("C"))
	{
		strSQL.Format(_T("select HeatID from (select * from CCCM_Base_Data where SubStr(TreatNo,1,1) = '%s' order by TreatNo desc) where rownum < 4")
			,cstrSampleAddr.Right(1));
	}
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQuality_Mag" name="CreateHeatGradeQAData" type="L3RECORDSET">
/// �����ʼ¯�εȼ�����
/// <Param name="strUnitID" type="L3STRING">����</Param>
/// <Param name="rsData" type="L3RECORDSET">���ٰ���¯�š�Ԥ��¯�š����ּǺš�Ԥ�����ּǺŵļ�¼��</Param>
/// </Method>
L3SHORT CQuality_Mag::CreateHeatGradeQAData(L3STRING strUnitID ,L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if ((rs.GetRowCount() < 1) || (strUnitID == NULL))
	{
		return -1;
	}
	CString cstrUnitID = strUnitID;

	if(rs.GetFieldIndex(_T("HeatID")) < 0 ||
		rs.GetFieldIndex(_T("PreHeatID")) < 0 ||
		rs.GetFieldIndex(_T("Pre_SteelGradeIndex")) < 0 ||
		rs.GetFieldIndex(_T("SteelGradeIndex")) < 0)
	{
		return -1;
	}

	rs.MoveFirst();
	CString strHeatID = (rs.GetFieldByName(_T("HeatID"))).ToCString();
	CL3RecordSetWrap rsQA;
	if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeData"),rsQA))
	{
		return -2;
	}

    CString csHeatGrade;
	if (cstrUnitID.Mid(1,1) == UNIT_TYPE_BOF)
	{
		csHeatGrade = BOF_INIT_HEATGRADE;
	}
	else if (cstrUnitID.Mid(1,1) == UNIT_TYPE_LF)
	{
		csHeatGrade = LF_INIT_HEATGRADE;
	}
	else if (cstrUnitID.Mid(1,1) == UNIT_TYPE_RH)
	{
		csHeatGrade = RH_INIT_HEATGRADE;
	}
	else if (cstrUnitID.Mid(1,1) == UNIT_TYPE_CASTER)
	{
		csHeatGrade = CCM_INIT_HEATGRADE;
	}

	L3LONG nProcessCount = 0;
	CString strSQL;
	strSQL.Format(_T("select count(ID_Object) as ProcessCount from %s where HeatID = '%s' and UnitTypeID=%s and UnitID = %s ")
		         ,_T("XGMESLogic\\QualityMag\\CQA_HeatGradeData"),strHeatID,cstrUnitID.Mid(1,1),cstrUnitID.Right(1));
	CL3RecordSetWrap rsCount;
	if(!Query(strSQL,rsCount))
		return -3;
	else
	{
		if (rsCount.GetRowCount() > 0)
		{
			nProcessCount = (rsCount.GetFieldByName(_T("ProcessCount"))).ToLong();
		}
	}

	CString csProcessCount;
	csProcessCount.Format(_T("%d"),nProcessCount);

	rs.MoveFirst();
	rsQA.AppendRecord();
	rsQA.CopyCurRowFrom(rs);
	rsQA.SetFieldByName(_T("ID_Object"),CL3Variant((rs.GetFieldByName(_T("HeatID"))).ToCString() + cstrUnitID + csProcessCount));
	rsQA.SetFieldByName(_T("UnitTypeID"),CL3Variant(cstrUnitID.Mid(1,1)));
	rsQA.SetFieldByName(_T("UnitID"),CL3Variant(cstrUnitID.Right(1)));
	rsQA.SetFieldByName(_T("HeatGrade"),CL3Variant(csHeatGrade));
	rsQA.SetFieldByName(_T("ProcessCount"),CL3Variant(csProcessCount));

 	rsQA.MoveFirst();
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeData"),rsQA) < rsQA.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}

	if(bUseTrans)
		Commit(nTrans);
   return 1;
}

/// <Method class="CQuality_Mag" name="GetCurrentHeatGradeQAData" type="L3RECORDSET">
/// ��ȡ����ǰ¯��¯�εȼ�
/// <Param name="strUnitID" type="L3STRING">��λ</Param>
/// <Param name="strHeatID" type="L3STRING">¯��</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetCurrentHeatGradeQAData(L3STRING strUnitID ,L3STRING strHeatID)
{
	if ((strUnitID == NULL) || (strHeatID == NULL))
	{
		return NULL;
	}
	CString cstrHeatID = strHeatID;
	CString cstrUnitID = strUnitID;
	LONG nUnitTypeID,nUnitID;
	try
	{
		nUnitTypeID = _ttoi(cstrUnitID.Mid(1,1));
		nUnitID = _ttoi(cstrUnitID.Mid(2,1));
	}
	catch (...)
	{}

	//CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatChemicalData_Mag\\QA_HeatChemicalData_Mag"),
	//	                                   _T("GetReHeatCount"),
	//									   strHeatID,
	//									   nUnitTypeID,
	//									   nUnitID);
	//if(valRet.IsError())
	//{
	//	return NULL;
	//}
	//L3LONG processCount = valRet.ToLong();
	//if (processCount < 0)
	//{
	//	return NULL;
	//}

	CString strSQL;
	strSQL.Format(_T("select * from (select ID_Object,HeatID,Exceptional_Code,Decide_Code,HeatGrade from %s where HeatID = '%s' and UnitTypeID=%d and UnitID = %d order by ProcessCount desc) where rownum < 2 ")
		         ,_T("XGMESLogic\\QualityMag\\CQA_HeatGradeData"),cstrHeatID,nUnitTypeID,nUnitID);
	CL3RecordSetWrap rstemp;
	if(!Query(strSQL,rstemp))
		return NULL;
	else 
		return rstemp.Detach();
}

/// <Method class="CQuality_Mag" name="UpdateCurrentHeatGradeData" type="L3LONG">
/// 
/// �޸ĵ�ǰ¯�εȼ���Ϣ
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQuality_Mag::UpdateCurrentHeatGradeData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rstemp = rsData;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	if(rstemp.GetRowCount() > 0) 
	{
		rstemp.MoveFirst();
		if (!SetObjsPropValues(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeData"),rstemp))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -3;
		}
	}
	
	if(bUseTrans)
		Commit(nTrans);

	return 0;

}

/// <Method class="CQuality_Mag" name="GetQACalWeightData" type="L3RECORDSET">
/// ͨ�����߳��Ȼ�ȡ���߱�׼���ݡ�
/// <Param name="Length" type="LONG">����</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQACalWeightData(LONG Length)
{
	CString strSQL;
	strSQL.Format(_T("select * from XGMESLogic\\Quality\\CQA_Cal_Weight_Std where Length = %d"),Length);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

///2008-12-29 tangyiͨ�����ֻ�ȡ�ø��ֿ��Ը��е����ּǺ�
/// <Method class="CQuality_Mag" name="GetQACalWeightData" type="L3RECORDSET">
/// ͨ�����߳��Ȼ�ȡ���߱�׼���ݡ�
/// <Param name="Length" type="LONG">����</Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetJudgedSteelGrade(L3STRING strSteelGrade,L3STRING strSteelGradeIndex)
{
	if(strSteelGrade == NULL || strSteelGradeIndex ==NULL) return NULL;
	CString csSteelGrade =strSteelGrade;
	CString csSteelGradeIndex =strSteelGradeIndex;
	CString csBigBloomFlag = csSteelGradeIndex.Mid(0,1);//2009-01-15 tangyi
	CString csSQL;
	csSQL.Format(_T("select Judged_SteelGrade from CQA_ChangeSteel_Std where SteelGrade ='%s' "),csSteelGrade);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs))
		return NULL;

	//�齨�������ݼ�
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsSteelGradeIndex; pRSRtn->QueryInterface(IID_IL3RecordSet,rsSteelGradeIndex); pRSRtn->Release();
	rsSteelGradeIndex.AddField(_T("Final_SteelGradeIndex"),VT_BSTR);
	rsSteelGradeIndex.AddField(_T("SteelGrade"),VT_BSTR);
	rsSteelGradeIndex.AddField(_T("Protocol"),VT_BSTR);

	//�����Լ�,ǰ̨ĬȻΪ��ǰ���ּǺţ����뱾�����������ּƻ��ֿ�д
	CString csSQLSelf;
	csSQLSelf.Format(_T("select SteelGradeIndex as Final_SteelGradeIndex,SteelGrade,Protocol from CQA_SteelGradeIndex_R where SteelGradeIndex ='%s'"),csSteelGradeIndex);
	CL3RecordSetWrap rsDataSelf;
	if(!Query(csSQLSelf,rsDataSelf))
		return NULL;
	if(rsDataSelf.GetRowCount() > 0)
			rsSteelGradeIndex.CopyFrom(rsDataSelf);

	//�����Լ����ֶ�Ӧ���������ּǺ�2009-03-13 tangyi 
	//CString csSQLSelf;
	if(csBigBloomFlag == _T("J"))
	{
		csSQLSelf.Format(_T("select SteelGradeIndex as Final_SteelGradeIndex,SteelGrade,Protocol from CQA_SteelGradeIndex_R where SteelGrade ='%s' and substr(SteelGradeIndex,1,1) = 'J' and SteelGradeIndex <> '%s'"),csSteelGrade,csSteelGradeIndex);
	}
	else
	{
		csSQLSelf.Format(_T("select SteelGradeIndex as Final_SteelGradeIndex,SteelGrade,Protocol from CQA_SteelGradeIndex_R where SteelGrade ='%s' and substr(SteelGradeIndex,1,1) <> 'J' and SteelGradeIndex <> '%s'"),csSteelGrade,csSteelGradeIndex);

	}
	CL3RecordSetWrap rsDataOrtherSelf;
	if(!Query(csSQLSelf,rsDataOrtherSelf))
		return NULL;
	if(rsDataOrtherSelf.GetRowCount() > 0)
			rsSteelGradeIndex.CopyFrom(rsDataOrtherSelf);

	//�������п������ּǺ�
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csJudgedSteelGrade = rs.GetFieldByIndex(0).ToCString();
		CString csSQLTemp;
		if(csBigBloomFlag == _T("J"))//2009-01-15 tangyi
		{
			csSQLTemp.Format(_T("select SteelGradeIndex as Final_SteelGradeIndex,SteelGrade,Protocol from CQA_SteelGradeIndex_R where SteelGrade ='%s' and substr(SteelGradeIndex,1,1) = 'J' "),csJudgedSteelGrade);
		}
		else
		{
			csSQLTemp.Format(_T("select SteelGradeIndex as Final_SteelGradeIndex,SteelGrade,Protocol from CQA_SteelGradeIndex_R where SteelGrade ='%s' and substr(SteelGradeIndex,1,1) <> 'J' "),csJudgedSteelGrade);

		}
		CL3RecordSetWrap rsData;
		if(!Query(csSQLTemp,rsData))
			return NULL;
		if(rsData.GetRowCount() > 0)
			rsSteelGradeIndex.CopyFrom(rsData);
		rs.MoveNext();
	}


	//���ϴ���
	rsSteelGradeIndex.AppendRecord();
	rsSteelGradeIndex.SetFieldByName(_T("Final_SteelGradeIndex"),CL3Variant(WAITING_FIN_JUDGE));

	return rsSteelGradeIndex.Detach();
}


///// <Method class="CQuality_Mag" name="GetDeSSampleApplyData" type="L3RECORDSET">
///// ��ȡ����ί�е�(����)����
///// </Method>
//L3RECORDSET CQuality_Mag::GetDeSSampleApplyData()
//{
//	CString csSQL;
//	CString cstrSQL  = _T("  Select *  from %s                                             ");
//			cstrSQL += _T("  where Sample_Type='%s' and (SendFlag = 0) and Sample_Date >= (select TRUNC(SYSDATE) from dual) - 5  order by Sample_Date desc ");
//	csSQL.Format(cstrSQL,QA_LAB_SHEET_APP_CLASS_URI,_T("TS")); 
//
//	CL3RecordSetWrap rs;
//	if(!Query(csSQL,rs))
//		return NULL;
//	else
//		return rs.Detach();
//}

/// <Method class="CQuality_Mag" name="SteelGradeIndexCopy" type="L3LONG">
/// <Param name="strNewSteelGradeIndex" type="L3STRING"></Param>
/// <Param name="strOldSteelGradeIndex" type="L3STRING"></Param>
/// </Method>
L3LONG CQuality_Mag::SteelGradeIndexCopy(L3STRING strNewSteelGradeIndex, L3STRING strOldSteelGradeIndex)
{
	// TODO : ���ڴ�����߼�����
	CString csNewSteelGradeIndex=strNewSteelGradeIndex;
	CString csOldSteelGradeIndex=strOldSteelGradeIndex;

	csNewSteelGradeIndex=csNewSteelGradeIndex.Trim();
	csOldSteelGradeIndex=csOldSteelGradeIndex.Trim();

	//���ɵ����ּǺź��µ����ּǺ��Ƿ�Ϊ��
	if(csNewSteelGradeIndex==_T("")||csOldSteelGradeIndex==_T(""))
		return -1;

	CL3RecordSetWrap rs;

	//����µ����ּǺ��Ƿ��Ѿ�����
	CString csSql;
	csSql.Format(_T(" select STEELGRADEINDEX from %s where STEELGRADEINDEX='%s' "),QA_STG_RELATION_CLASS_URI,csNewSteelGradeIndex);

	if(Query(csSql,rs)&&rs.GetRowCount()>0)
		return -2;

	csSql.Format(_T(" select STEELGRADEINDEX from %s where STEELGRADEINDEX='%s' "),QA_PROD_SHEET_CLASS_URI,csNewSteelGradeIndex);

	if(Query(csSql,rs)&&rs.GetRowCount()>0)
		return -2;

	CL3RecordSetWrap rsGradeRelation;
	CL3RecordSetWrap rsProdSheet;

	//���ɵ����ּǺ��Ƿ����
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_STG_RELATION_CLASS_URI,csOldSteelGradeIndex);

	if(!Query(csSql,rsGradeRelation)||rsGradeRelation.IsNull()||rsGradeRelation.GetRowCount()<1)
		return -3;

	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_PROD_SHEET_CLASS_URI,csOldSteelGradeIndex);

	if(!Query(csSql,rsProdSheet)||rsProdSheet.IsNull()||rsProdSheet.GetRowCount()<1)
		return -3;

	

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -4;
	}

	//���Ƹ��ֶ��չ�ϵ��
	rsGradeRelation.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
	if(CreateNewObjects(QA_STG_RELATION_CLASS_URI,rsGradeRelation)<1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	//���ƹ���·��
	rsProdSheet.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
	if(CreateNewObjects(QA_PROD_SHEET_CLASS_URI,rsProdSheet)<1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	//����ת¯��׼ CQA_BOF_STD_AR
	CL3RecordSetWrap rsBofStdAr;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_AR_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdAr)&&rsBofStdAr.GetRowCount()>0)
	{
		rsBofStdAr.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_BOF_STD_AR_CLASS_URI,rsBofStdAr)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����ת¯��׼ QA_BOF_STD_BASE
	CL3RecordSetWrap rsBofStdBase;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_BASE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdBase)&&rsBofStdBase.GetRowCount()>0)
	{
		rsBofStdBase.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_BOF_STD_BASE_CLASS_URI,rsBofStdBase)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����ת¯��׼ QA_BOF_STD_BLOW_CLASS_URI
	CL3RecordSetWrap rsBofStdBlow;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_BLOW_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdBlow)&&rsBofStdBlow.GetRowCount()>0)
	{
		rsBofStdBlow.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_BOF_STD_BLOW_CLASS_URI,rsBofStdBlow)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����ת¯��׼ QA_BOF_STD_BLOWO2_CLASS_URI
	CL3RecordSetWrap rsBofStdBlow2;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_BLOWO2_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdBlow2)&&rsBofStdBlow2.GetRowCount()>0)
	{
		rsBofStdBlow2.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_BOF_STD_BLOWO2_CLASS_URI,rsBofStdBlow2)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����ת¯��׼ QA_BOF_STD_BULK_CLASS_URI
	CL3RecordSetWrap rsBofStdBulk;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_BULK_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdBulk)&&rsBofStdBulk.GetRowCount()>0)
	{
		rsBofStdBulk.MoveFirst();
		while(!rsBofStdBulk.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsBofStdBulk.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsBofStdBulk.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_BOF_STD_BULK_CLASS_URI,rsBofStdBulk)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsBofStdBulk.MoveNext();
		}
	}

	//����ת¯��׼ QA_BOF_STD_FEED_CLASS_URI
	CL3RecordSetWrap rsBofStdFeed;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_FEED_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdFeed)&&rsBofStdFeed.GetRowCount()>0)
	{
		rsBofStdFeed.MoveFirst();
		while(!rsBofStdFeed.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsBofStdFeed.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsBofStdFeed.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_BOF_STD_FEED_CLASS_URI,rsBofStdFeed)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsBofStdFeed.MoveNext();
		}
	}

	//����ת¯��׼ QA_BOF_STD_INCTR_ELE_CLASS_URI
	CL3RecordSetWrap rsBofStdInctrEle;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_INCTR_ELE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdInctrEle)&&rsBofStdInctrEle.GetRowCount()>0)
	{
		rsBofStdInctrEle.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_BOF_STD_INCTR_ELE_CLASS_URI,rsBofStdInctrEle)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����ת¯��׼ QA_BOF_STD_INTOCONVER_CLASS_URI
	CL3RecordSetWrap rsBofStdIntoconver;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_INTOCONVER_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdIntoconver)&&rsBofStdIntoconver.GetRowCount()>0)
	{
		rsBofStdIntoconver.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_BOF_STD_INTOCONVER_CLASS_URI,rsBofStdIntoconver)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����ת¯��׼ QA_BOF_STD_LADLE_CLASS_URI
	//��׼��Ψһ
	CL3RecordSetWrap rsBofStdLadle;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_LADLE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdLadle)&&rsBofStdLadle.GetRowCount()>0)
	{
		rsBofStdLadle.MoveFirst();
		while(!rsBofStdLadle.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsBofStdLadle.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsBofStdLadle.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_BOF_STD_LADLE_CLASS_URI,rsBofStdLadle)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsBofStdLadle.MoveNext();
		}
	}

	//����ת¯��׼ QA_BOF_STD_SLAG_ELE_CLASS_URI
	CL3RecordSetWrap rsBofStdSlagEle;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_SLAG_ELE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdSlagEle)&&rsBofStdSlagEle.GetRowCount()>0)
	{
		rsBofStdSlagEle.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_BOF_STD_SLAG_ELE_CLASS_URI,rsBofStdSlagEle)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}


	//����ת¯��׼ QA_BOF_STD_TAPPING_CLASS_URI
	CL3RecordSetWrap rsBofStdStapping;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_BOF_STD_TAPPING_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsBofStdStapping)&&rsBofStdStapping.GetRowCount()>0)
	{
		rsBofStdStapping.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_BOF_STD_TAPPING_CLASS_URI,rsBofStdStapping)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����LF��׼ QA_LF_STD_ALLOY_CLASS_URI
	CL3RecordSetWrap rsLfStdAlloy;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_LF_STD_ALLOY_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsLfStdAlloy)&&rsLfStdAlloy.GetRowCount()>0)
	{
		rsLfStdAlloy.MoveFirst();
		while(!rsLfStdAlloy.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsLfStdAlloy.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsLfStdAlloy.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_LF_STD_ALLOY_CLASS_URI,rsLfStdAlloy)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsLfStdAlloy.MoveNext();
		}
	}

	//����LF��׼ QA_LF_STD_BASE_CLASS_URI
	CL3RecordSetWrap rsLfStdBase;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_LF_STD_BASE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsLfStdBase)&&rsLfStdBase.GetRowCount()>0)
	{
		rsLfStdBase.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_LF_STD_BASE_CLASS_URI,rsLfStdBase)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����LF��׼ QA_LF_STD_FEED_CLASS_URI
	CL3RecordSetWrap rsLfStdFeed;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_LF_STD_FEED_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsLfStdFeed)&&rsLfStdFeed.GetRowCount()>0)
	{
		rsLfStdFeed.MoveFirst();
		while(rsLfStdFeed.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsLfStdFeed.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsLfStdFeed.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_LF_STD_FEED_CLASS_URI,rsLfStdFeed)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsLfStdFeed.MoveNext();
		}
	}

	//����LF��׼ QA_LF_STD_INCTR_ELE_CLASS_URI
	CL3RecordSetWrap rsLfStdInctrEle;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_LF_STD_INCTR_ELE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsLfStdInctrEle)&&rsLfStdInctrEle.GetRowCount()>0)
	{
		rsLfStdInctrEle.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_LF_STD_INCTR_ELE_CLASS_URI,rsLfStdInctrEle)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����LF��׼ QA_LF_STD_LADLE_CLASS_URI
	CL3RecordSetWrap rsLfStdLadle;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_LF_STD_LADLE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsLfStdLadle)&&rsLfStdLadle.GetRowCount()>0)
	{
		rsLfStdLadle.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_LF_STD_LADLE_CLASS_URI,rsLfStdLadle)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����LF��׼ QA_LF_STD_PROC_CLASS_URI
	CL3RecordSetWrap rsLfStdProc;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_LF_STD_PROC_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsLfStdProc)&&rsLfStdProc.GetRowCount()>0)
	{
		rsLfStdProc.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_LF_STD_PROC_CLASS_URI,rsLfStdProc)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����LF��׼ QA_LF_STD_SLAG_CLASS_URI
	CL3RecordSetWrap rsLfStdSlag;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_LF_STD_SLAG_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsLfStdSlag)&&rsLfStdSlag.GetRowCount()>0)
	{
		rsLfStdSlag.MoveFirst();
		while(!rsLfStdSlag.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsLfStdSlag.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsLfStdSlag.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_LF_STD_SLAG_CLASS_URI,rsLfStdSlag)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsLfStdSlag.MoveNext();
		}
	}

	//����LF��׼ QA_LF_STD_SLAG_ELE_CLASS_URI
	CL3RecordSetWrap rsLfStdSlagEle;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_LF_STD_SLAG_ELE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsLfStdSlagEle)&&rsLfStdSlagEle.GetRowCount()>0)
	{
		rsLfStdSlagEle.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_LF_STD_SLAG_ELE_CLASS_URI,rsLfStdSlagEle)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����RH��׼ QA_RH_STD_ALLOY_CLASS_URI
	CL3RecordSetWrap rsRhStdAlloy;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_RH_STD_ALLOY_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsRhStdAlloy)&&rsRhStdAlloy.GetRowCount()>0)
	{
		rsRhStdAlloy.MoveFirst();
		while(!rsRhStdAlloy.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsRhStdAlloy.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsRhStdAlloy.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_RH_STD_ALLOY_CLASS_URI,rsRhStdAlloy)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsRhStdAlloy.MoveNext();
		}
	}

	//����RH��׼ QA_RH_STD_BASE_CLASS_URI
	CL3RecordSetWrap rsRhStdBase;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_RH_STD_BASE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsRhStdBase)&&rsRhStdBase.GetRowCount()>0)
	{
		rsRhStdBase.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_RH_STD_BASE_CLASS_URI,rsRhStdBase)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����RH��׼ QA_RH_STD_FEED_CLASS_URI
	CL3RecordSetWrap rsRhStdFeed;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_RH_STD_FEED_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsRhStdFeed)&&rsRhStdFeed.GetRowCount()>0)
	{
		rsRhStdFeed.MoveFirst();
		while(!rsRhStdFeed.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsRhStdFeed.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsRhStdFeed.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_RH_STD_FEED_CLASS_URI,rsRhStdFeed)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsRhStdFeed.MoveNext();
		}
	}

	//����RH��׼ QA_RH_STD_INCTR_ELE_CLASS_URI
	CL3RecordSetWrap rsRhStdInctrEle;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_RH_STD_INCTR_ELE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsRhStdInctrEle)&&rsRhStdInctrEle.GetRowCount()>0)
	{
		rsRhStdInctrEle.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_RH_STD_INCTR_ELE_CLASS_URI,rsRhStdInctrEle)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����RH��׼ QA_RH_STD_PROC_CLASS_URI
	CL3RecordSetWrap rsRhStdProc;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_RH_STD_PROC_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsRhStdProc)&&rsRhStdProc.GetRowCount()>0)
	{
		rsRhStdProc.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_RH_STD_PROC_CLASS_URI,rsRhStdProc)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����CCM��׼ QA_CCM_STD_FLUX_CLASS_URI
	CL3RecordSetWrap rsCCMStdFlux;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_CCM_STD_FLUX_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsCCMStdFlux)&&rsCCMStdFlux.GetRowCount()>0)
	{
		rsCCMStdFlux.MoveFirst();
		while(!rsCCMStdFlux.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsCCMStdFlux.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsCCMStdFlux.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_CCM_STD_FLUX_CLASS_URI,rsCCMStdFlux)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsCCMStdFlux.MoveNext();
		}
	}

	//����CCM��׼ QA_CCM_STD_PROC_CLASS_URI
	CL3RecordSetWrap rsCCMStdProc;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_CCM_STD_PROC_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsCCMStdProc)&&rsCCMStdProc.GetRowCount()>0)
	{
		rsCCMStdProc.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_CCM_STD_PROC_CLASS_URI,rsCCMStdProc)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����CCM��׼ QA_CCM_STD_PRODPROC_CLASS_URI
	CL3RecordSetWrap rsCCMStdProdproc;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_CCM_STD_PRODPROC_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsCCMStdProdproc)&&rsCCMStdProdproc.GetRowCount()>0)
	{
		rsCCMStdProdproc.MoveFirst();
		while(!rsCCMStdProdproc.IsEOF())
		{
			GUID uid;
			if(FAILED(::CoCreateGuid(&uid)))
				return -1;
			rsCCMStdProdproc.SetFieldByName(_T("GUID"), CL3Variant(uid));
			rsCCMStdProdproc.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
			if(CreateNewObjects(QA_CCM_STD_PRODPROC_CLASS_URI,rsCCMStdProdproc)<1)
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -5;		
			}
			rsCCMStdProdproc.MoveNext();
		}
	}

	////����CCM��׼ QA_CCM_STD_SPEC_CLASS_URI
	//CL3RecordSetWrap rsCCMStdSpec;
	//csSql.Format(csSql,QA_CCM_STD_SPEC_CLASS_URI,csOldSteelGradeIndex);

	//if(Query(_T("select * from %s where STEELGRADEINDEX='%s'"),rsCCMStdSpec)&&rsCCMStdSpec.GetRowCount()>0)
	//{
	//	rsCCMStdSpec.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
	//	if(CreateNewObjects(QA_CCM_STD_SPEC_CLASS_URI,rsCCMStdSpec)<1)
	//	{
	//		if(bUseTrans)
	//			Rollback(nTrans);
	//		return -5;		
	//	}
	//}

	//����CCM��׼ QA_CCM_STD_SPEED_CLASS_URI
	CL3RecordSetWrap rsCCMStdSpeed;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_CCM_STD_SPEED_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsCCMStdSpeed)&&rsCCMStdSpeed.GetRowCount()>0)
	{
		rsCCMStdSpeed.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_CCM_STD_SPEED_CLASS_URI,rsCCMStdSpeed)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����CCM��׼ QA_CCM_STD_TUNDISH_CLASS_URI
	CL3RecordSetWrap rsCCMStdTundish;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_CCM_STD_TUNDISH_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsCCMStdTundish)&&rsCCMStdTundish.GetRowCount()>0)
	{
		rsCCMStdTundish.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_CCM_STD_TUNDISH_CLASS_URI,rsCCMStdTundish)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//����CCM��׼ QA_CCM_STD_BASE_CLASS_URI
	CL3RecordSetWrap rsCCMStdBase;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_CCM_STD_BASE_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsCCMStdBase)&&rsCCMStdBase.GetRowCount()>0)
	{
		rsCCMStdBase.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_CCM_STD_BASE_CLASS_URI,rsCCMStdBase)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	//���ƹ�����ʱ���׼ QA_UNIT_PROC_TIME_CLASS_URI
	CL3RecordSetWrap rsUnitProcTime;
	csSql.Format(_T("select * from %s where STEELGRADEINDEX='%s'"),QA_UNIT_PROC_TIME_CLASS_URI,csOldSteelGradeIndex);

	if(Query(csSql,rsUnitProcTime)&&rsUnitProcTime.GetRowCount()>0)
	{
		rsUnitProcTime.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
		if(CreateNewObjects(QA_UNIT_PROC_TIME_CLASS_URI,rsUnitProcTime)<1)
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -5;		
		}
	}

	if(bUseTrans)
		Commit(nTrans);



	return 0;
}



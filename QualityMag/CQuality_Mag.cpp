// 逻辑类CQuality_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CQuality_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CQuality_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CQuality_Mag.h"

//当对象被装载到系统中时，被调用
void CQuality_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CQuality_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <Method class="CQuality_Mag" name="BloomWaster" type="L3BOOL">
/// 
/// 钢坯甩废
/// ARG&gt;&gt; rsData:甩废数据，包括：HeatID、Bloom_Count、Cal_Weight、Waster_Total_Count、Waster_Total_Weight、Waster_Reason、Cut_SteelGradeIndex 、SteelGradeIndex、Produce_Date、Length、Width、Thickness字段
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
/// <Param name="rsData" type="L3RECORDSET">检验委托单信息</Param>
/// </Method>
L3BOOL CQuality_Mag::BloomWaster(L3RECORDSET rsData)
{
	return 0; // TODO : 请在此添加逻辑代码
}

/// <Method class="CQuality_Mag" name="GetUnspecifyDutyWasterData" type="L3RECORDSET">
/// 
/// 获取未指定责任单位的甩废实绩数据
/// ARG&gt;&gt;strCasterID：铸机号
/// RET &lt;&lt; 成功返回查询数据集；失败返回NULL。
/// <Param name="strCasterID" type=""></Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetUnspecifyDutyWasterData(L3STRING strCasterID)
{
	return 0;// TODO : 请在此添加逻辑代码
}

/// <Method class="CQuality_Mag" name="AddQAStdData" type="L3BOOL">
/// 
/// 增加作业标准数据
/// ARG&gt;&gt; rsData:标准数据
///        &gt;&gt; strDataType:数据类型URI
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
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

	// 创建制造标准对象
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
/// 删除作业标准数据
/// ARG&gt;&gt; rsData:标准数据
///        &gt;&gt; DataType:数据类型URI
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
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

	// 创建制造标准对象
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
/// 修改作业标准数据
/// ARG&gt;&gt; rsData:标准数据
///        &gt;&gt; DataType:数据类型URI
/// RET &lt;&lt; 成功返回TRUE；失败返回FALSE。
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
/// 获取质量标准数据集
/// ARG&gt;&gt; rsCondition 包括：StdDataType
/// RET &lt;&lt; 成功返回数据集；失败返回NULL。
/// <Param name="rsCondition" type="L3RECORDSET"></Param>
/// </Method>
L3RECORDSET CQuality_Mag::GetQAStdData(L3RECORDSET rsCondition)
{
	return 0;// TODO : 请在此添加逻辑代码
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

	// 创建制造标准对象
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

// 修改LF制造标准
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

	// 创建制造标准对象
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

	// 创建制造标准对象
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

// 修改RH制造标准
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

// 删除RH制造标准
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

	// 创建制造标准对象
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

// 新增CCM制造标准
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

	// 创建制造标准对象
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

// 修改CCM制造标准
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

	// 创建制造标准对象
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
/// 获取BOF制造标准(基本数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(吹氩数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(吹炼数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(吹氧数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(加料数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(喂丝数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(内控成分数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(来料数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(钢包数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(渣成分数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取BOF制造标准(出钢数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取LF制造标准(基本数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取LF制造标准(合金数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取LF制造标准(喂丝数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取LF制造标准(内控成分数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取LF制造标准(钢包数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取LF制造标准(作业数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取LF制造标准(渣数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取LF制造标准(渣成分数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取RH制造标准(基本数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取RH制造标准(合金数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取RH制造标准(喂丝数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取RH制造标准(内控数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取RH制造标准(作业数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取CCM制造标准(中包覆盖剂数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取CCM制造标准(作业数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取CCM制造标准(制成数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取CCM制造标准(规格数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取CCM制造标准(拉速数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取CCM制造标准(中包数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取CCM制造标准(基本数据)。
/// <Param name="strSteelGradeIndex" type="L3STRING">炼钢记号</Param>
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
/// 获取CCM制造标准(基本数据)。
/// <Param name="rsData" type="L3RECORDSET">CQA_Bloom_Waster_Data主键、责任单位、责任标志=1</Param>
/// </Method>
L3LONG CQuality_Mag::BloomWasterDutySpecify(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if (rs.GetRowCount() < 1)
		return -1;

    //开始事务
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
    //设置责任单位、责任标志=1
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
/// 按取样地点(工位)获取化验委托单数据
/// <Param name="strSampleAddr" type="L3STRING">取样地点(工位)</Param>
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
	//增加脱P
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
/// 通过取样地点获取工位最近三炉炉号
/// <Param name="strSampleAddr" type="L3STRING">取样地点(工位)</Param>
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
/// 工序初始炉次等级创建
/// <Param name="strUnitID" type="L3STRING">工序</Param>
/// <Param name="rsData" type="L3RECORDSET">至少包含炉号、预定炉号、炼钢记号、预定炼钢记号的记录集</Param>
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
/// 获取工序当前炉次炉次等级
/// <Param name="strUnitID" type="L3STRING">工位</Param>
/// <Param name="strHeatID" type="L3STRING">炉号</Param>
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
/// 修改当前炉次等级信息
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
/// 通过定尺长度获取定尺标准数据。
/// <Param name="Length" type="LONG">长度</Param>
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

///2008-12-29 tangyi通过钢种获取该钢种可以改判的炼钢记号
/// <Method class="CQuality_Mag" name="GetQACalWeightData" type="L3RECORDSET">
/// 通过定尺长度获取定尺标准数据。
/// <Param name="Length" type="LONG">长度</Param>
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

	//组建返回数据集
	CL3RecordSet *pRSRtn = new CL3RecordSet();
	CL3RecordSetWrap rsSteelGradeIndex; pRSRtn->QueryInterface(IID_IL3RecordSet,rsSteelGradeIndex); pRSRtn->Release();
	rsSteelGradeIndex.AddField(_T("Final_SteelGradeIndex"),VT_BSTR);
	rsSteelGradeIndex.AddField(_T("SteelGrade"),VT_BSTR);
	rsSteelGradeIndex.AddField(_T("Protocol"),VT_BSTR);

	//加上自己,前台默然为当前炼钢记号，故与本钢种其他炼钢计划分开写
	CString csSQLSelf;
	csSQLSelf.Format(_T("select SteelGradeIndex as Final_SteelGradeIndex,SteelGrade,Protocol from CQA_SteelGradeIndex_R where SteelGradeIndex ='%s'"),csSteelGradeIndex);
	CL3RecordSetWrap rsDataSelf;
	if(!Query(csSQLSelf,rsDataSelf))
		return NULL;
	if(rsDataSelf.GetRowCount() > 0)
			rsSteelGradeIndex.CopyFrom(rsDataSelf);

	//加上自己钢种对应的其他炼钢记号2009-03-13 tangyi 
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

	//加上所有可判炼钢记号
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


	//加上待判
	rsSteelGradeIndex.AppendRecord();
	rsSteelGradeIndex.SetFieldByName(_T("Final_SteelGradeIndex"),CL3Variant(WAITING_FIN_JUDGE));

	return rsSteelGradeIndex.Detach();
}


///// <Method class="CQuality_Mag" name="GetDeSSampleApplyData" type="L3RECORDSET">
///// 获取化验委托单(脱硫)数据
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
	// TODO : 请在此添加逻辑代码
	CString csNewSteelGradeIndex=strNewSteelGradeIndex;
	CString csOldSteelGradeIndex=strOldSteelGradeIndex;

	csNewSteelGradeIndex=csNewSteelGradeIndex.Trim();
	csOldSteelGradeIndex=csOldSteelGradeIndex.Trim();

	//检查旧的炼钢记号和新的炼钢记号是否为空
	if(csNewSteelGradeIndex==_T("")||csOldSteelGradeIndex==_T(""))
		return -1;

	CL3RecordSetWrap rs;

	//检查新的炼钢记号是否已经存在
	CString csSql;
	csSql.Format(_T(" select STEELGRADEINDEX from %s where STEELGRADEINDEX='%s' "),QA_STG_RELATION_CLASS_URI,csNewSteelGradeIndex);

	if(Query(csSql,rs)&&rs.GetRowCount()>0)
		return -2;

	csSql.Format(_T(" select STEELGRADEINDEX from %s where STEELGRADEINDEX='%s' "),QA_PROD_SHEET_CLASS_URI,csNewSteelGradeIndex);

	if(Query(csSql,rs)&&rs.GetRowCount()>0)
		return -2;

	CL3RecordSetWrap rsGradeRelation;
	CL3RecordSetWrap rsProdSheet;

	//检查旧的炼钢记号是否存在
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

	//复制钢种对照关系表
	rsGradeRelation.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
	if(CreateNewObjects(QA_STG_RELATION_CLASS_URI,rsGradeRelation)<1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	//复制工艺路径
	rsProdSheet.SetFieldByName(_T("SteelGradeIndex"),(CL3Variant)csNewSteelGradeIndex);
	if(CreateNewObjects(QA_PROD_SHEET_CLASS_URI,rsProdSheet)<1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	//复制转炉标准 CQA_BOF_STD_AR
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

	//复制转炉标准 QA_BOF_STD_BASE
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

	//复制转炉标准 QA_BOF_STD_BLOW_CLASS_URI
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

	//复制转炉标准 QA_BOF_STD_BLOWO2_CLASS_URI
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

	//复制转炉标准 QA_BOF_STD_BULK_CLASS_URI
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

	//复制转炉标准 QA_BOF_STD_FEED_CLASS_URI
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

	//复制转炉标准 QA_BOF_STD_INCTR_ELE_CLASS_URI
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

	//复制转炉标准 QA_BOF_STD_INTOCONVER_CLASS_URI
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

	//复制转炉标准 QA_BOF_STD_LADLE_CLASS_URI
	//标准不唯一
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

	//复制转炉标准 QA_BOF_STD_SLAG_ELE_CLASS_URI
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


	//复制转炉标准 QA_BOF_STD_TAPPING_CLASS_URI
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

	//复制LF标准 QA_LF_STD_ALLOY_CLASS_URI
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

	//复制LF标准 QA_LF_STD_BASE_CLASS_URI
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

	//复制LF标准 QA_LF_STD_FEED_CLASS_URI
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

	//复制LF标准 QA_LF_STD_INCTR_ELE_CLASS_URI
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

	//复制LF标准 QA_LF_STD_LADLE_CLASS_URI
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

	//复制LF标准 QA_LF_STD_PROC_CLASS_URI
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

	//复制LF标准 QA_LF_STD_SLAG_CLASS_URI
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

	//复制LF标准 QA_LF_STD_SLAG_ELE_CLASS_URI
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

	//复制RH标准 QA_RH_STD_ALLOY_CLASS_URI
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

	//复制RH标准 QA_RH_STD_BASE_CLASS_URI
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

	//复制RH标准 QA_RH_STD_FEED_CLASS_URI
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

	//复制RH标准 QA_RH_STD_INCTR_ELE_CLASS_URI
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

	//复制RH标准 QA_RH_STD_PROC_CLASS_URI
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

	//复制CCM标准 QA_CCM_STD_FLUX_CLASS_URI
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

	//复制CCM标准 QA_CCM_STD_PROC_CLASS_URI
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

	//复制CCM标准 QA_CCM_STD_PRODPROC_CLASS_URI
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

	////复制CCM标准 QA_CCM_STD_SPEC_CLASS_URI
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

	//复制CCM标准 QA_CCM_STD_SPEED_CLASS_URI
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

	//复制CCM标准 QA_CCM_STD_TUNDISH_CLASS_URI
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

	//复制CCM标准 QA_CCM_STD_BASE_CLASS_URI
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

	//复制工序处理时间标准 QA_UNIT_PROC_TIME_CLASS_URI
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



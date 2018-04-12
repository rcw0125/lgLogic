// 逻辑类CQA_HeatChemicalData_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CQA_HeatChemicalData_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CQA_HeatChemicalData_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CQA_HeatChemicalData_Mag.h"
#include "_CQA_Lab_Sheet_App.h"
#include "_CSteel_Data.h"

//当对象被装载到系统中时，被调用
void CQA_HeatChemicalData_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CQA_HeatChemicalData_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetUnitMagURIBySampleAddr" type="CString">
/// 通过取样地点获取工序静态对象（用于设置工序对象相关属性）
/// <Param name=strSampleAddr//取样地点</Param>
/// </Method>
CString CQA_HeatChemicalData_Mag::GetUnitMagURIBySampleAddr(LPCTSTR strSampleAddr)
{
	L3LONG nIndex=-1;
	for (int i=0;i<SAMPLE_ADDR_COUNT;i++)
	{
		if (strSampleAddr == SAMPLE_ADDR[i])
		{
			nIndex = i;
			break;
		}
	}

	if (nIndex != -1)
	{
		return UNIT_MAG_OBJECT[nIndex];
	}
	else
	{
		return _T("");
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetSysYear" type="CString">
/// 计算委托单申请号
/// <Param name=无</Param>
/// </Method>
CString CQA_HeatChemicalData_Mag::GetSysCurYear()
{
	COleDateTime dtCurrentTime;
	dtCurrentTime = COleDateTime::GetCurrentTime();
	CString cstrCurTime = dtCurrentTime.Format(_T("%Y"));
    CString cstrYear = cstrCurTime.Mid(2,2);
    return cstrYear;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalLabSheetAppID" type="CString">
/// 计算委托单申请号
/// <Param name="crSampleAddr" type="LPCTSTR">采样地点</Param>
/// <Param name="csSampleType" type="LPCTSTR">试样类别</Param>
/// </Method>
CString CQA_HeatChemicalData_Mag::CalLabSheetAppID(LPCTSTR csSampleAddr,LPCTSTR csSampleType)
{
    CString cstrSampleAddr=csSampleAddr;
	CL3RecordSetWrap rs;
    //按采样地点获取委托单申请号中最大顺序号
	CString csSQL;
	csSQL.Format(_T("select Max(AppID) AS AppID from %s where Sample_Address = '%s'"),QA_LAB_SHEET_APPID_CLASS_URI,cstrSampleAddr);
	if(!Query(csSQL,rs) ||  rs.GetRowCount() < 1)
		return _T("");
	rs.MoveFirst();
	CString cstempAppid;
	cstempAppid = rs.GetFieldByIndex(0).ToCString();
    //产生委托单申请号中最大顺序号
	CString csNextAppid;
	if (cstempAppid.GetLength() < 1)
		cstempAppid = _T("0");
	csNextAppid.Format(_T("%06d"),_ttoi(cstempAppid)+1);
    //设置委托单申请号中最大顺序号
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return _T("");
	}

	CL3Variant valRet = GetObjectPropValue(QA_LAB_SHEET_APPID_CLASS_URI+_T("\\")+cstrSampleAddr,_T("AppID"));
	if ((valRet.IsError()) && (GetL3LastError() == L3ERR_OBJECT_NOTEXIST))
	{
		if (!CreateNewObject(QA_LAB_SHEET_APPID_CLASS_URI,CL3Variant(cstrSampleAddr)))
		{
			if (bUseTrans)
				Rollback(nTrans);
			return _T(""); 
		}
	}
    if (!SetObjectPropValue(QA_LAB_SHEET_APPID_CLASS_URI+_T("\\")+cstrSampleAddr,
		                    _T("AppID"),CL3Variant(csNextAppid)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return _T("");
	}

	if(bUseTrans)
		Commit(nTrans);

	return cstrSampleAddr+GetSysCurYear()+csNextAppid;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronSampleCode" type="CString">
/// 计算铁水试样编码
/// <Param name="csSampleAddr" type="LPCTSTR"> 取样地点
/// <Param name="csSampleType" type="LPCTSTR"> 试样类别
/// <Param name="csTAPNo" type="LPCTSTR"> 铁次号
/// 必需包括BFID，TAP_No，Sample_Type，Sample_Address</Param>
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalIronSampleCode(LPCTSTR csSampleAddr,
													 LPCTSTR csSampleType,
													 LPCTSTR csTAPNo)
{
    CString cstrSampleAddr = csSampleAddr;
    CString cstrSampleType = csSampleType;
    CString cstrTAPNo = csTAPNo;
	CString cstrBFID = cstrTAPNo.Left(1);

	CString cstrSampleNo= cstrTAPNo + cstrSampleAddr + cstrSampleType;
   /* if (cstrSampleNo.GetLength()!=13)
	{
       return _T("");
	}*/

	CL3RecordSetWrap rs;
    //从CQA_Lab_Sheet_App获取高炉样试样代码(去除取样次数)最大取样次数，如果为空取样次数为0
	CString csSQL;
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where substr(Sample_Code,1,13) = '%s'"),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleNo);
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = 0;
		if ((rs.GetFieldByIndex(0)).ToCString().GetLength() > 0)
			nSampleCount = rs.GetFieldByIndex(0).ToLong();
		cstrSampleCount.Format(_T("%02d"),++nSampleCount);
	}
	else
	{
		cstrSampleCount = _T("01");
	}

	return cstrSampleNo + cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalMixFurnaceSampleCode" type="CString">
/// 计算混铁炉试样编码
/// <Param name="csSampleAddr" type="LPCTSTR">取样地点(混铁炉)</Param>
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalMixFurnaceSampleCode(LPCTSTR csSampleAddr,LPCTSTR csSampleType)
{
    CString cstrSampleAddr = csSampleAddr;
    if (cstrSampleAddr.GetLength()!=2)
	{
       return _T("");
	}
    //获取系统年号(两位)
    CString cstrYear = GetSysCurYear();

	//当天
	COleDateTime dtcurDay =  COleDateTime::GetCurrentTime();
	CString cstrcurDay = dtcurDay.Format(_T("%Y%m%d"));

	CL3RecordSetWrap rs;
    //从CQA_Lab_Sheet_App获取混铁炉当天最大取样次数，如果为空当天取样次数为0
	CString csSQL;
	//csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where Sample_Address = '%s' and Sample_Type= '%s' and to_char(Sample_Date,'yyyyMMdd')='%s' "),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleAddr,csSampleType,cstrcurDay);
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where Sample_Address = '%s' and to_char(Sample_Date,'yyyyMMdd')='%s' "),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleAddr,cstrcurDay);
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = rs.GetFieldByIndex(0).ToLong();
		cstrSampleCount.Format(_T("%02d"),++nSampleCount);
	}
	else
	{
		cstrSampleCount = _T("00");
	}

	return _T("H") + cstrcurDay.Right(6) + cstrSampleAddr.Mid(1,1)+cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronLadleSampleCode" type="CString">
/// 计算混铁炉铁包样编码
/// <Param name="csSampleAddr" type="LPCTSTR">取样地点(混铁炉)</Param>
/// <Param name="csSampleType" type="LPCTSTR">试样类别</Param>
/// <Param name="csIronLadleNo" type="LPCTSTR">铁包</Param>
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalIronLadleSampleCode(LPCTSTR csSampleAddr,LPCTSTR csSampleType,LPCTSTR csIronLadleNo)
{
	//[20090106Liao]
    CString cstrSampleAddr = csSampleAddr;
	CString cstrIronLadleID = csIronLadleNo;
	cstrIronLadleID = cstrIronLadleID.Right(2);

    if (cstrSampleAddr.GetLength()!=2)
	{
       return _T("");
	}
    //获取系统年号(两位)
    CString cstrYear = GetSysCurYear();

	//当天
	COleDateTime dtcurDay =  COleDateTime::GetCurrentTime();
	CString cstrcurDay = dtcurDay.Format(_T("%m%d%H%M"));
	cstrcurDay = cstrYear + cstrcurDay;

	CString cstrSampleNo=_T("B") + cstrcurDay + cstrIronLadleID ;

	CL3RecordSetWrap rs;
    //从CQA_Lab_Sheet_App获取混铁炉当天最大取样次数，如果为空当天取样次数为0
	CString csSQL;
	
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where substr(Sample_Code,1,13) = '%s'"),
		QA_LAB_SHEET_APP_CLASS_URI,cstrSampleNo);
	
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = rs.GetFieldByIndex(0).ToLong();
		cstrSampleCount.Format(_T("%02d"),++nSampleCount);
	}
	else
	{
		cstrSampleCount = _T("01");
	}

    return _T("B")+ cstrcurDay + cstrIronLadleID +cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalBOFSampleCode" type="CString">
/// 计算炼钢试样编码
/// <Param name="csSampleType" type="LPCTSTR">试样类别</Param>
/// <Param name="csSampleAddr" type="LPCTSTR">取样地点</Param>
/// <Param name="csHeatID" type="LPCTSTR">炉号</Param>
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalBOFSampleCode(LPCTSTR csSampleType,
                                                    LPCTSTR csSampleAddr,
													LPCTSTR csHeatID)
{
    CString cstrSample_Type = csSampleType;
    CString cstrSample_Address = csSampleAddr;
    CString cstrHeatID = csHeatID;
    if ((cstrSample_Type.GetLength()!=2)||(cstrSample_Address.GetLength()<1)||(cstrHeatID.GetLength()!=9))
	{
       return _T("");
	}
    //获取系统年号(两位)
    CString cstrYear = GetSysCurYear();
	//获取炉座--根据炉号第2位获取转炉炉座
    CString cstrBOFID = cstrHeatID.Mid(1,1);
	//根据炉号后5位获取熔炼号
	CString cstrPartHeatID = cstrHeatID.Mid(4,5);
	
	//根据试样类别第二位判断是成品样还是过程样
    bool IsFinalSample = false;
	if ((cstrSample_Type.Right(1) == _T("P")) || (cstrSample_Type.Right(1) == _T("L"))) //增加(cstrSample_Type.Right(1) == _T("L")连铸中包样算成品样 2009-01-17
	{
		IsFinalSample = true;
	}

    CString cstrSampleCode;
    //炼钢试样编码=2+炉座号+年号+熔炼号+取样地点+试样类别+取样次数
	//cstrSampleCode = _T("2")+cstrBOFID+GetSysCurYear()+cstrHeatID.Mid(4,5)+cstrSample_Address+cstrSample_Type;
	cstrSampleCode = csHeatID+cstrSample_Address+cstrSample_Type;//2009-01-07 yao

	CL3RecordSetWrap rs;
    //按采样地点获取委托单申请号中最大顺序号
	CString csSQL;
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where substr(Sample_Code,1,13) = '%s' "),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleCode);
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = rs.GetFieldByIndex(0).ToLong();
		if (IsFinalSample)
		{
			if (nSampleCount == 99) //2009-03-21 若存在正样则产生负样
			{
				cstrSampleCount = _T("00");
			}
			else
			{
				cstrSampleCount = _T("99");
			}
		}
		else
		{
			cstrSampleCount.Format(_T("%02d"),++nSampleCount);
		}
	}
	else
	{
		cstrSampleCount = _T("00");
	}

    return cstrSampleCode + cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="LogLabSheet" type="L3LONG">
/// 生成化验委托单据
/// <Param name="rsData" type="L3RECORDSET"></Param>
///试样数据集必需包括：Sample_Type，Sample_Address，HeatID字段
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::NewLabSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// 化验委托单, 补齐化验委托单数据所需字段
	//rs.AddField(_T("AppID"),L3VT_STRING);
	//rs.AddField(_T("Sample_Code"),L3VT_STRING);
	//rs.AddField(_T("Sample_Count"),L3VT_STRING);
	//rs.AddField(_T("Sample_Date"),L3VT_DATETIME);
	// 补齐字段信息
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//取样类型
		CString cstrSample_Type = rs.GetFieldByName(_T("Sample_Type")).ToCString();
		//取样地点
		CString cstrSample_Address = rs.GetFieldByName(_T("Sample_Address")).ToCString();
		//炉号
		CString cstrHeatID = rs.GetFieldByName(_T("HeatID")).ToCString();
        //委托单编号
        CString cstrAppID = CalLabSheetAppID(cstrSample_Address,cstrSample_Type);
		//试样编码
		CString cstrSampleCode;
	
		//[20090106Liao]
		if ((cstrSample_Type == QA_Sample_Type_TH) || (cstrSample_Type == QA_Sample_Type_TA)) // 混铁炉样 (添加铁罐混铁炉全分析2009-04-11)
		{
			cstrSampleCode = CalMixFurnaceSampleCode(cstrSample_Address,cstrSample_Type);
		}
		else if ((cstrSample_Type == QA_Sample_Type_TC) && (cstrSample_Address == QA_Sample_Addr_TC)) //铁水抽查样
		{
			cstrSampleCode = CalIronSampleCode(cstrSample_Address,cstrSample_Type,cstrHeatID);//cstrHeatID为铁次号
		}
			else if ((cstrSample_Type == _T("TP")) || (cstrSample_Type == _T("TI"))) //脱磷铁水抽查样 20160316
		{
			cstrSampleCode = CalIronSampleCode(cstrSample_Address,cstrSample_Type,cstrHeatID);//cstrHeatID为铁次号
		}
		else if((cstrSample_Type == QA_Sample_Type_TC) && (cstrSample_Address == QA_Sample_Addr_TB))
		{
			cstrSampleCode = CalIronLadleSampleCode(cstrSample_Address,cstrSample_Type,cstrHeatID);//cstrHeatID为铁包
		}
		else if(cstrSample_Type == QA_Sample_Type_ZG) //铁渣样 2009-04-11
		{
			cstrSampleCode = CalIronSampleCode(cstrSample_Address,cstrSample_Type,cstrHeatID);//cstrHeatID为铁包
		}
		else 
		{
			cstrSampleCode = CalBOFSampleCode(cstrSample_Type,cstrSample_Address,cstrHeatID);
			//钢种2009-01-09tangyi GetSteelGradeByHeatID改为返回数据集
			CL3RecordSetWrap rsSteelGrade;
			rsSteelGrade = GetSteelGradeByHeatID(cstrHeatID);
			rsSteelGrade.MoveFirst();
			rs.SetFieldByName(_T("SteelGrade"),rsSteelGrade.GetFieldByName(_T("SteelGrade")));  
			//协议
			rs.SetFieldByName(_T("Treaty"),rsSteelGrade.GetFieldByName(_T("Protocol")));       
		}

		 //申请号
		rs.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
		//试样编码
		rs.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
		//试样次数
		rs.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
		//试样日期
		rs.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));

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

	rs.MoveFirst();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rs);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	if(bUseTrans)
		Commit(nTrans);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="ModifyLabSheet" type="L3LONG">
/// 修改委托单数据
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::ModifyLabSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// 检查下传检化验状态，已经下传的（SendFlag不为1）不能修改
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		// 下传检化验标识
		L3LONG nStatus = rs.GetFieldByName(_T("SendFlag")).ToLong();
		if(nStatus != CQA_Lab_Sheet_App::NotSendLab)
		{	//委托单已传送
			SetL3LastError(XGMES_ERR_SHEETSEND);
			return -1;
		}
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

	rs.MoveFirst();
	if(SetObjsPropValues(QA_LAB_SHEET_APP_CLASS_URI,rs))
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
	else
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="DeleteLabSheet" type="L3LONG">
/// 删除委托单数据
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::DeleteLabSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// 检查下传检化验状态，已经下传的（SendFlag不为1）不能修改
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		// 下传检化验标识
		L3LONG nStatus = rs.GetFieldByName(_T("SendFlag")).ToLong();
		if(nStatus == CQA_Lab_Sheet_App::SendLab)
		{	//委托单已传送
			SetL3LastError(XGMES_ERR_SHEETSEND);
			return -1;
		}
		L3LONG nBackFlag = rs.GetFieldByName(_T("Back_Flag")).ToLong();
		if ((nBackFlag != CQA_Lab_Sheet_App::IsBack) && (nStatus == CQA_Lab_Sheet_App::SendLab))
		{	//委托单未回退
			SetL3LastError(XGMES_ERR_SHEETUNBACK);
			return -1;
		}
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

	rs.MoveFirst();
	if (DeleteOldObjects(QA_LAB_SHEET_APP_CLASS_URI,rs)<rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	else
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
}



/// <Method class="CQA_HeatChemicalData_Mag" name="SendSheetDataToLab" type="L3LONG">
/// 委托单数据下传化验室
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::SendSheetDataToLab(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("SendFlag")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("SendFlag"),CL3Variant((LONG)CQA_Lab_Sheet_App::SendLab));
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!SetObjsPropValues(QA_LAB_SHEET_APP_CLASS_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	//2009-04-07 Begin
	rs.MoveFirst();
	if (!SendSheetDataToAnaL2(rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	//2009-04-07 Begin

	if(bUseTrans)
		Commit(nTrans);

	// 向检化验发送数据,必需放在事务外2009-01-03 tangyi
	//rs.MoveFirst();
	//SendSheetDataToAnaL2(rs);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSheetBack" type="L3LONG">
/// 接收检化验委托单回退
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabSheetBack(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// 检查数据有效性
	if(rs.GetFieldIndex(_T("AppID")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return -1;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//根据试样编号中取样地点设置工序管理对象UndoApplyID值
		CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Code"))).ToCString();
		CString cstrUnitMagURI = GetUnitMagURIBySampleAddr(cstrSampleAddr.Mid(9,2));
		if (cstrUnitMagURI.GetLength() > 0)
		{
			if (!(SetObjectPropValue(cstrUnitMagURI,
				                     _T("UndoApplyID"),rs.GetFieldByName(_T("AppID")))))
			{
				if(bUseTrans)
			       Rollback(nTrans);
			}
		}

		rs.SetFieldByName(_T("Back_Flag"),CL3Variant((LONG)1));
		COleDateTime dtCurrentTime;
	    dtCurrentTime = COleDateTime::GetCurrentTime();
		rs.SetFieldByName(_T("Back_Date"),CL3Variant((L3DATETIME)dtCurrentTime));
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(!SetObjsPropValues(QA_LAB_SHEET_APP_CLASS_URI,rs))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	else
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSteelElement" type="L3LONG">
/// 接收钢样检化验结果(包括割样)
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabSteelElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// 准备有效成分数据
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_ELEMENT_CLASS_URI,rsElement))
	{
		return -1;
	}

	rsElement.DelField(_T("FinalJudgeFlag")); //2009-04-28 tangyi防止样重传时改变FinalJudgeFlag标志

	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		//通过来样地点获取工序工位数据
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrSampleType = rsElement.GetFieldByName(_T("Sample_Type")).ToCString();//2009-03-21 获取试样类别用于高拉碳炉终样传送PLC
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		L3LONG nUnitID=0;
		try
		{
			nUnitID = _ttoi(cstrUnitID);
		}
		catch(...)
		{
		}

		if (cstrUnitType == _T("Z"))
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BOF));
			if ((cstrSampleType == _T("GT")) && (nUnitID == 4)) //2009-03-21 4#炉高拉碳炉终样传送PLC
			{
				L3FLOAT fC = rsElement.GetFieldByName(_T("C")).ToFloat();
				L3FLOAT fS = rsElement.GetFieldByName(_T("S")).ToFloat();
				L3FLOAT fP = rsElement.GetFieldByName(_T("P")).ToFloat();
				SendAnalysisDataToPLC(fC,fS,fP);
			}
		}
		else if (cstrUnitType == _T("F")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)LF));
		}
		else if (cstrUnitType == _T("R")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)RH));
		}
		else if (cstrUnitType == _T("C")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)CCM));
		}
		else if (cstrUnitType == _T("A")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)11));
		}
		rsElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)nUnitID));
        rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_ELEMENT_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_ELEMENT_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
    
	//// 准备成分判定数据
	//CL3RecordSetWrap rsJudge;
	//if(!CreateClassPropSet(QA_LAB_ELEMENT_CLASS_URI,rsJudge))
	//{
	//	if(bUseTrans)
	//		Rollback(nTrans);
	//	return -1;
	//}

	//rsElement.MoveFirst();
	//while(!rsElement.IsEOF())
	//{
 //       CString cstrSampleType = rsElement.GetFieldByName(_T("Sample_Type")).ToCString();
	//	if (cstrSampleType.Mid(0,1) == _T("G")) //钢样进行成分判定
	//	{
	//		//根据委托单中最终成分标识设置钢水材料最终成分标识属性
	//		CString cstrHeatID = rsElement.GetFieldByName(_T("HeatID")).ToCString();
	//		CString cstrAppID = rsElement.GetFieldByName(_T("AppID")).ToCString();
	//		L3LONG nUnitTypeID = rsElement.GetFieldByName(_T("UnitTypeID")).ToLong();
	//		L3LONG nUnitID = rsElement.GetFieldByName(_T("UnitID")).ToLong();
	//		L3LONG nFinalChemicalFlag = (GetObjectPropValue(QA_LAB_SHEET_APP_CLASS_URI +_T("\\") + cstrAppID,_T("Fin_Prod_Flag"))).ToLong();
	//		if (nFinalChemicalFlag == 1)
	//		{
	//			if (!SetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID,
	//									_T("FinalChemiclaFlag"),CL3Variant((L3LONG)1)))
	//			{
	//				if(bUseTrans)
	//					Rollback(nTrans);
	//				return -1;
	//			}
	//		}
	//		//调用成份判定算法
	//		rsJudge.AppendRecord();
	//		rsJudge.CopyCurRowFrom(rsElement);

	//		L3STRING bstrHeatID = cstrHeatID.AllocSysString();
	//		L3LONG nProcessCount = GetReHeatCount(bstrHeatID,nUnitTypeID,nUnitID);
	//		if (nProcessCount >= 0)
	//		{
	//			CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssumeAlg_Mag\\QA_HeatGradeAssumeAlg_Mag"),
	//												   _T("EstimateHeatChemical"),
	//												   nUnitTypeID,
	//												   nUnitID,
	//												   bstrHeatID,
	//												   nProcessCount,
	//												   (L3RECORDSET)rsJudge);
	//			if(valRet.IsError())
	//			{
	//				L3SysFreeString(bstrHeatID);
	//				if(bUseTrans)
	//					Rollback(nTrans);
	//				return -1;
	//			}
	//		}
	//		L3SysFreeString(bstrHeatID);
	//	}
	//	rsElement.MoveNext();
	//}
	//if(bUseTrans)
	//	Commit(nTrans);
	return rsElement.GetRowCount();
}



/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabSteelElementText" type="L3LONG">
/// 接收钢样检化验结果(文本)
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabSteelElementText(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// 准备有效成分数据
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_ELEMENT_TEXT_CLASS_URI,rsElement))
	{
		return -1;
	}

	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		//通过来样地点获取工序工位数据
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		L3LONG nUnitID=0;
		try
		{
			nUnitID = _ttoi(cstrUnitID);
		}
		catch(...)
		{
		}

		if (cstrUnitType == _T("Z"))
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BOF));
		}
		else if (cstrUnitType == _T("F")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)LF));
		}
		else if (cstrUnitType == _T("R")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)RH));
		}
		else if (cstrUnitType == _T("C")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)CCM));
		}
			else if (cstrUnitType == _T("A")) 
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)11));
		}
		rsElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)nUnitID));
        rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_ELEMENT_TEXT_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_ELEMENT_TEXT_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSPrintData" type="L3LONG">
/// 接收低倍样实绩
/// <Param name="rsData" type="L3RECORDSET"></Param>
///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptSPrintData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// 准备有效成分数据
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_S_PRINT_CLASS_URI,rsElement))
		return -1;
	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_S_PRINT_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_S_PRINT_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSlagElement" type="L3LONG">
/// 接收渣样检化验结果
/// <Param name="rsData" type="L3RECORDSET"></Param>
///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptSlagElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// 准备有效成分数据
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_SLAGELE_CLASS_URI,rsElement))
		return -1;
	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_SLAGELE_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_SLAGELE_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
}


/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptErrorInfo" type="L3LONG">
/// 接收化验单回退信息2009-01-03 tangyi
/// <Param name="rsData" type="L3RECORDSET"></Param>
///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptErrorInfo (L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csAppID =  rs.GetFieldByName(_T("AppID")).ToCString();
		CString csUri = QA_LAB_SHEET_APP_CLASS_URI+_T("\\") +csAppID;
		SetObjectPropValue(csUri,_T("Back_Flag"),L3LONG(1));
		SetObjectPropValue(csUri,_T("Back_Date"),COleDateTime::GetCurrentTime());
		rs.MoveNext();
	}

	return 0;
}


/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptReSampleInfor" type="L3LONG">
/// 接收重新取样指示2009-01-03 tangyi
/// <Param name="rsData" type="L3RECORDSET"></Param>
///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptReSampleInfor (L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csAppID =  rs.GetFieldByName(_T("AppID")).ToCString();
		CString csUri = QA_LAB_SHEET_APP_CLASS_URI+_T("\\") +csAppID;
		SetObjectPropValue(csUri,_T("ReSample_Flag"),L3LONG(1));
		SetObjectPropValue(csUri,_T("ReSample_Date"),COleDateTime::GetCurrentTime());
		rs.MoveNext();
	}

	return 0;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptSlagElementText" type="L3LONG">
/// 接收渣样检化验结果(文本)
/// <Param name="rsData" type="L3RECORDSET"></Param>
///试样数据集必需包括：ApplyID、Sample_Code、Arrive_Date、Report_Date字段
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptSlagElementText(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	// 准备有效成分数据
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(QA_LAB_SLAGELE_TEXT_CLASS_URI,rsElement))
		return -1;
	rsElement.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsElement.CopyCurRowFrom(rs);
		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		CString csAppID =  rsElement.GetFieldByName(_T("AppID")).ToCString();
		CreateNewObject(QA_LAB_SLAGELE_TEXT_CLASS_URI,CL3Variant(csAppID));
		SetObjPropValues(QA_LAB_SLAGELE_TEXT_CLASS_URI+_T("\\") +csAppID,rsElement);
		rsElement.MoveFirst();
		rs.MoveNext();
	}

	return 0;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabIronElement" type="L3LONG">
/// 接收铁样检化验结果
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabIronElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// 准备有效成分数据
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element"),rsElement))
	{
		return -1;
	}

    //添加脱磷钢水样
	CL3RecordSetWrap rsLabElement;
	if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element"),rsLabElement))
	{
		return -1;
	}
	rsLabElement.AppendRecord();
	rsLabElement.MoveFirst();


	rsElement.CopyFrom(rs);
	rsElement.MoveFirst();
	while(!rsElement.IsEOF())
	{
		CString cstrSampleNo = rsElement.GetFieldByName(_T("Sample_Code")).ToCString();
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		L3LONG nUnitID=0;
		try
		{
			nUnitID = _ttoi(cstrUnitID);
		}
		catch(...)
		{
		}

		if (cstrUnitType == _T("G")) //高炉铁沟样
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BF));//设置工位
			//设置铁次、罐号
			rsElement.SetFieldByName(_T("TAP_No"),CL3Variant(cstrSampleNo.Mid(0,9)));
			rsElement.SetFieldByName(_T("TPC_No"),CL3Variant(cstrSampleNo.Mid(9,2)));//罐号？待定

		}
		else if (cstrUnitType == _T("H")) //混铁炉区域样
		{
			rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)MIF));
		}


		/////脱磷钢水成分
        if(cstrSampleAddr== _T("T2"))
		{
		 
			rsLabElement.CopyCurRowFrom(rsElement);
			rsLabElement.SetFieldByName(_T("HeatID"),CL3Variant(cstrSampleNo.Mid(0,9)));
			rsLabElement.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleNo.Mid(13,2)));
			rsLabElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
			rsLabElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)10));//设置工位
			rsLabElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)1));
		    rsLabElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));

				BOOL bUseTrans = !IsInTrans();

				LONG nTrans = 0;
				if(bUseTrans)
				{
					nTrans = BeginTrans();
					if(nTrans < 1)
						return -1;
				}
			   
				rsElement.MoveFirst();
				LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element"),rsLabElement);
				if(nRet < rsLabElement.GetRowCount())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -1;
				}

				if(bUseTrans)
					Commit(nTrans);
				rsLabElement.MoveFirst();

		}



		rsElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)nUnitID));

		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		rsElement.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
   
	rsElement.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element"),rsElement);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	rsElement.MoveFirst();
	while(!rsElement.IsEOF())
	{
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		if (cstrUnitType == _T("G")) //高炉铁沟样
		{
			CL3RecordSetWrap rsIron;
			if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element"),rsIron))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -1;
			}

			rsIron.AppendRecord();
			rsIron.CopyCurRowFrom(rsElement);
            AcceptBFIronElementData(rsIron);
		}
		else if (cstrUnitType == _T("H")) //混铁炉区域样
		{
			CString cstrSampleType = rsElement.GetFieldByName(_T("Sample_Type")).ToCString();
			//Modify begin by llj 2011-04-15 修改让混铁炉全分析样已能够更新TI、MN成分 屏蔽原语句
			//if (cstrSampleType == _T("TH")) //若混铁炉样则设置混铁炉加工区域最新成份值
			if (cstrSampleType == _T("TH")||cstrSampleType == _T("TA")) //若混铁炉样则设置混铁炉加工区域最新成份值
			//Modify end
			{
				CString csMIFMagURI = _T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag\\S1")+cstrUnitID;
				//modify by hyh 2012-04-17
				CL3Variant valC = rsElement.GetFieldByName(_T("C"));
				if(!(valC.IsEmpty() || valC.IsError() || valC.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("C"),valC);
					SetObjectPropValue(csMIFMagURI,_T("C_Cal"),valC);
				}
				CL3Variant valSi = rsElement.GetFieldByName(_T("Si"));
				if(!(valSi.IsEmpty() || valSi.IsError() || valSi.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Si"),valSi);
					SetObjectPropValue(csMIFMagURI,_T("Si_Cal"),valSi);
				}
				CL3Variant valMn = rsElement.GetFieldByName(_T("Mn"));
				if(!(valMn.IsEmpty() || valMn.IsError() || valMn.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Mn"),valMn);
					SetObjectPropValue(csMIFMagURI,_T("Mn_Cal"),valMn);
				}
				CL3Variant valP = rsElement.GetFieldByName(_T("P"));
				if(!(valP.IsEmpty() || valP.IsError() || valP.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("P"),valP);
					SetObjectPropValue(csMIFMagURI,_T("P_Cal"),valP);
				}
				CL3Variant valS = rsElement.GetFieldByName(_T("S"));
				if(!(valS.IsEmpty() || valS.IsError() || valS.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("S"),valS);
					SetObjectPropValue(csMIFMagURI,_T("S_Cal"),valS);
				}
				CL3Variant valTi = rsElement.GetFieldByName(_T("Ti"));
				if(!(valTi.IsEmpty() || valTi.IsError() || valTi.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Ti"),valTi);
					SetObjectPropValue(csMIFMagURI,_T("Ti_Cal"),valTi);
				}

				//add by hyh 2012-04-02
				CL3Variant valSn = rsElement.GetFieldByName(_T("Sn"));
				if(!(valSn.IsEmpty() || valSn.IsError() || valSn.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Sn"),valSn);
					SetObjectPropValue(csMIFMagURI,_T("Sn_Cal"),valSn);
				}
				CL3Variant valSb = rsElement.GetFieldByName(_T("Sb"));
				if(!(valSb.IsEmpty() || valSb.IsError() || valSb.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Sb"),valSb);
					SetObjectPropValue(csMIFMagURI,_T("Sb_Cal"),valSb);
				}
				CL3Variant valAs = rsElement.GetFieldByName(_T("As"));
				if(!(valAs.IsEmpty() || valAs.IsError() || valAs.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("As"),valAs);
					SetObjectPropValue(csMIFMagURI,_T("As_Cal"),valAs);
				}
				CL3Variant valPb = rsElement.GetFieldByName(_T("Pb"));
				if(!(valPb.IsEmpty() || valPb.IsError() || valPb.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Pb"),valPb);
					SetObjectPropValue(csMIFMagURI,_T("Pb_Cal"),valPb);
				}
				//end

				//add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
				CL3Variant valNi = rsElement.GetFieldByName(_T("Ni"));
				if(!(valNi.IsEmpty() || valNi.IsError() || valNi.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Ni"),valNi);
					SetObjectPropValue(csMIFMagURI,_T("Ni_Cal"),valNi);
				}
				CL3Variant valMo = rsElement.GetFieldByName(_T("Mo"));
				if(!(valMo.IsEmpty() || valMo.IsError() || valMo.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Mo"),valMo);
					SetObjectPropValue(csMIFMagURI,_T("Mo_Cal"),valMo);
				}
				CL3Variant valCu = rsElement.GetFieldByName(_T("Cu"));
				if(!(valCu.IsEmpty() || valCu.IsError() || valCu.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Cu"),valCu);
					SetObjectPropValue(csMIFMagURI,_T("Cu_Cal"),valCu);
				}
				CL3Variant valCr = rsElement.GetFieldByName(_T("Cr"));
				if(!(valCr.IsEmpty() || valCr.IsError() || valCr.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Cr"),valCr);
					SetObjectPropValue(csMIFMagURI,_T("Cr_Cal"),valCr);
				}
				CL3Variant valB = rsElement.GetFieldByName(_T("B"));
				if(!(valB.IsEmpty() || valB.IsError() || valB.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("B"),valB);
					SetObjectPropValue(csMIFMagURI,_T("B_Cal"),valB);
				}
				CL3Variant valV = rsElement.GetFieldByName(_T("V"));
				if(!(valV.IsEmpty() || valV.IsError() || valV.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("V"),valV);
					SetObjectPropValue(csMIFMagURI,_T("V_Cal"),valV);
				}

				//add by hyh 2012-04-02
				CL3Variant valAl = rsElement.GetFieldByName(_T("Al"));
				if(!(valAl.IsEmpty() || valAl.IsError() || valAl.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Al"),valAl);
					SetObjectPropValue(csMIFMagURI,_T("Al_Cal"),valAl);
				}
				CL3Variant valNb = rsElement.GetFieldByName(_T("Nb"));
				if(!(valNb.IsEmpty() || valNb.IsError() || valNb.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Nb"),valNb);
					SetObjectPropValue(csMIFMagURI,_T("Nb_Cal"),valNb);
				}
				CL3Variant valZn = rsElement.GetFieldByName(_T("Zn"));
				if(!(valZn.IsEmpty() || valZn.IsError() || valZn.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("Zn"),valZn);
					SetObjectPropValue(csMIFMagURI,_T("Zn_Cal"),valZn);
				}
				CL3Variant valW = rsElement.GetFieldByName(_T("W"));
				if(!(valW.IsEmpty() || valW.IsError() || valW.IsNull()))
				{
					SetObjectPropValue(csMIFMagURI,_T("W"),valW);
					SetObjectPropValue(csMIFMagURI,_T("W_Cal"),valW);
				}
				//end 将元素后缀名加上 _ELE
			}
		}
		rsElement.MoveNext();
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsElement.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptLabIronElement" type="L3LONG">
/// 接收铁样检化验结果
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptLabIronElementText(L3RECORDSET rsData)
{
		CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	// 准备有效成分数据
	CL3RecordSetWrap rsElement;
	if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element_Text"),rsElement))
	{
		return -1;
	}


	CL3RecordSetWrap rsLabElement;
	if(!CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element_Text"),rsLabElement))
	{
		return -1;
	}
	rsLabElement.AppendRecord();
	rsLabElement.MoveFirst();

	rsElement.CopyFrom(rs);
	rsElement.MoveFirst();
	while(!rsElement.IsEOF())
	{
		CString cstrSampleNo = rsElement.GetFieldByName(_T("Sample_Code")).ToCString();
		CString cstrSampleAddr = rsElement.GetFieldByName(_T("Sample_Address")).ToCString();
		CString cstrUnitType = cstrSampleAddr.Mid(0,1);
		CString cstrUnitID = cstrSampleAddr.Mid(1,1);
		L3LONG nUnitID=0;
		try
		{
			nUnitID = _ttoi(cstrUnitID);
		}
		catch(...)
		{
		}
		
		if(cstrSampleAddr== _T("T2"))
		{
		 
			rsLabElement.CopyCurRowFrom(rsElement);
			rsLabElement.SetFieldByName(_T("HeatID"),CL3Variant(cstrSampleNo.Mid(0,9)));
			rsLabElement.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleNo.Mid(13,2)));
			rsLabElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
			rsLabElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)10));//设置工位
			rsLabElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)1));
		    rsLabElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));

				BOOL bUseTrans = !IsInTrans();

				LONG nTrans = 0;
				if(bUseTrans)
				{
					nTrans = BeginTrans();
					if(nTrans < 1)
						return -1;
				}
			   
				rsElement.MoveFirst();
				LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element_Text"),rsLabElement);
				if(nRet < rsLabElement.GetRowCount())
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -1;
				}

				if(bUseTrans)
					Commit(nTrans);
				rsLabElement.MoveFirst();

		}

		else
		{
			if ((cstrUnitType == _T("G")) || (cstrUnitType == _T("T"))) //高炉区域样

			   {
				rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BF));//设置工位
				//设置铁次、罐号
				rsElement.SetFieldByName(_T("TAP_No"),CL3Variant(cstrSampleNo.Mid(2,7)));
				rsElement.SetFieldByName(_T("TPC_No"),CL3Variant(cstrSampleNo.Mid(8,2)));//罐号？待定

			   }

			else if (cstrUnitType == _T("H")) //混铁炉区域样

			  {
				rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)MIF));
			  }

		
		
		}

		//if ((cstrUnitType == _T("G")) || (cstrUnitType == _T("T"))) //高炉区域样
		//{
		//	rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)BF));//设置工位
		//	//设置铁次、罐号
		//	rsElement.SetFieldByName(_T("TAP_No"),CL3Variant(cstrSampleNo.Mid(2,7)));
		//	rsElement.SetFieldByName(_T("TPC_No"),CL3Variant(cstrSampleNo.Mid(8,2)));//罐号？待定

		//}
		//else if (cstrUnitType == _T("H")) //混铁炉区域样
		//{
		//	rsElement.SetFieldByName(_T("UnitTypeID"),CL3Variant((L3LONG)MIF));
		//}
		rsElement.SetFieldByName(_T("UnitID"),CL3Variant((L3LONG)nUnitID));
		rsElement.SetFieldByName(_T("DataLogMode"),L3LONG(0));
		rsElement.SetFieldByName(_T("LogTime"),COleDateTime::GetCurrentTime());
		rsElement.MoveNext();
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
   
	rsElement.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Iron_Element_Text"),rsElement);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsElement.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptReSampleAdvice" type="L3LONG">
/// 接收检化验重新取样通知 
/// <Param name="rsData" type="L3RECORDSET"></Param>
///试样数据集必需包括：AppID，ReSample_Reason字段
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::AcceptReSampleAdvice(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;
	

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}
    //补齐记录集中重新取样数据
	rs.AddField(_T("ReSample_Flag"),L3VT_LONG);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//根据试样编号中工序设置相关工序对象ReSampleApplyID属性值
		CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Code"))).ToCString();
		CString cstrUnitMagURI = GetUnitMagURIBySampleAddr(cstrSampleAddr.Mid(9,2));
		if (cstrUnitMagURI.GetLength() > 0)
		{
			if (!(SetObjectPropValue(cstrUnitMagURI,
				                     _T("ReSampleApplyID"),
									 rs.GetFieldByName(_T("AppID")))))

			{
				if(bUseTrans)
			       Rollback(nTrans);
			}
		}
		//设置重新取样标识数值
		rs.SetFieldByName(_T("ReSample_Flag"),CL3Variant((L3LONG)1));
		rs.MoveNext();
	}

	rs.MoveFirst();
	if(SetObjsPropValues(QA_LAB_SHEET_APP_CLASS_URI,rs))
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
	else
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="LabCutAdvice" type="L3LONG">
/// 填写割样通知单
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::LabCutAdvice(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	CString csSQL;
	CL3RecordSetWrap rsResult;
	rs.MoveFirst();
	while (!rs.IsEOF())
	{
		CString cstrHeatID = (rs.GetFieldByName(_T("HeatID"))).ToCString();
		//2009-01-03 tangyi
		csSQL.Format(_T("select a.SteelGradeIndex,b.SteelGrade,b.Protocol from CCCM_Base_Data a,CQA_SteelGradeIndex_R b where a.HeatID ='%s' and a.SteelGradeIndex = b.SteelGradeIndex"),cstrHeatID);
		if(!Query(csSQL,rsResult))
		{
			if(bUseTrans)
				Rollback(nTrans);
			return -2;
		}
		rsResult.MoveFirst();
		rs.CopyCurRowFrom(rsResult);
		rs.SetFieldByName(_T("Log_Time"),CL3Variant((L3DATETIME)(COleDateTime::GetCurrentTime())));
		rs.SetFieldByName(_T("Cut_Mark"),CL3Variant(_T("0")));
		rs.MoveNext();
	}

	rs.MoveFirst();
	LONG nRet = CreateNewObjects(_T("XGMESLogic\\QualityMag\\CQA_Lab_Cut_Advice"),rs);//QA_LAB_CUT_ADVICE_CLASS_URI需要在ConstDeclare中定义
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	/*rs.MoveFirst();*/
	
	//SetObjectPropValue(CCM1_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));
	//SetObjectPropValue(CCM2_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));
	//SetObjectPropValue(CCM3_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));
	//SetObjectPropValue(CCM4_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));
	//SetObjectPropValue(CCM5_UNIT_URI,_T("CutSampleHeatID"), CL3Variant(cstrHeatID));

	if(bUseTrans)
		Commit(nTrans);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetHeatLabElement" type="L3RECORDSET">
/// 获取炉次过程钢样
/// <Param name="rsData" type="L3RECORDSET">去向</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetHeatLabElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if (rs.GetRowCount() < 1)
		return NULL;

	rs.MoveFirst();
	CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Address"))).ToCString();
	CString cstrSampleType = (rs.GetFieldByName(_T("Sample_Type"))).ToCString();
	CString cstrSampleCount= (rs.GetFieldByName(_T("Sample_Count"))).ToCString();
	CString cstrHeatID = (rs.GetFieldByName(_T("HeatID"))).ToCString();

	CString strSQL;
	strSQL = _T("select * from CQA_Lab_Element ");
	CString strCondition = _T(" where ");
	LONG nParams = 0;
	VARIANT params[4];
	if (cstrSampleAddr.GetLength() > 0)
	{
		strCondition += _T("Sample_Address=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleAddr.AllocSysString();
		nParams ++;
	}
	if (cstrSampleType.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("Sample_Type=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleType.AllocSysString();
		nParams ++;
	}
	if (cstrSampleCount.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("Sample_Count=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleCount.AllocSysString();
		nParams ++;
	}
	if (cstrHeatID.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("HeatID=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrHeatID.AllocSysString();
		nParams ++;
	}

	if (nParams < 1) return NULL;

	strSQL = strSQL + strCondition;
	CL3RecordSetWrap rstemp;
	BOOL bRet = QueryWithParam(strSQL,params,nParams,rstemp);
	for(int i=0;i<nParams;i++)
	{
		::VariantClear(&params[i]);
	}
	if(bRet)
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LAB_ELEMENT_CLASS_URI,rsRet);
		rstemp.MoveFirst();
		rsRet.CopyFrom(rstemp);
		return rsRet.Detach();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetHeatSlagElement" type="L3RECORDSET">
/// 获取炉次渣样信息
/// <Param name="rsData" type="L3RECORDSET">去向</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetHeatSlagElement(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if (rs.GetRowCount() < 1)
		return NULL;

	rs.MoveFirst();
	CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Address"))).ToCString();
	CString cstrSampleType = (rs.GetFieldByName(_T("Sample_Type"))).ToCString();
	CString cstrSampleCount= (rs.GetFieldByName(_T("Sample_Count"))).ToCString();
	CString cstrHeatID = (rs.GetFieldByName(_T("HeatID"))).ToCString();

	CString strSQL;
	strSQL = _T("select * from CQA_Lab_SlagEle ");
	CString strCondition = _T(" where ");
	LONG nParams = 0;
	VARIANT params[4];
	if (cstrSampleAddr.GetLength() > 0)
	{
		strCondition += _T("Sample_Address=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleAddr.AllocSysString();
		nParams ++;
	}
	if (cstrSampleType.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("Sample_Type=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleType.AllocSysString();
		nParams ++;
	}
	if (cstrSampleCount.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("Sample_Count=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrSampleCount.AllocSysString();
		nParams ++;
	}
	if (cstrHeatID.GetLength() > 0)
	{
		if(nParams > 0)
			strCondition += _T("and ");
		strCondition += _T("HeatID=? ");
		params[nParams].vt = VT_BSTR; params[nParams].bstrVal = cstrHeatID.AllocSysString();
		nParams ++;
	}

	if (nParams < 1) return NULL;

	strSQL = strSQL + strCondition;
	CL3RecordSetWrap rstemp;
	BOOL bRet = QueryWithParam(strSQL,params,nParams,rstemp);
	for(int i=0;i<nParams;i++)
	{
		::VariantClear(&params[i]);
	}
	if(bRet)
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(QA_LAB_SLAGELE_CLASS_URI,rsRet);
		rstemp.MoveFirst();
		rsRet.CopyFrom(rstemp);
		return rsRet.Detach();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetActualHeatChemicalData" type="L3RECORDSET">
/// 获取炉次化学成分实绩数据
/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetActualHeatChemicalData(L3STRING strHeatID,
																L3LONG nUnitTypeID,
																L3LONG nUnitID)
{
	CString cstrHeatID = strHeatID;
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Lab_Element_Text where HeatID = '%s' and UnitTypeID=%d and UnitID=%d "),
		cstrHeatID,nUnitTypeID,nUnitID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
	{
		CL3RecordSetWrap rsRet;
		CreateClassPropSet(_T("XGMESLogic\\QualityMag\\CQA_Lab_Element_Text"),rsRet);
		rs.MoveFirst();
		rsRet.CopyFrom(rs);
		return rsRet.Detach();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetTechRequestByHeatID" type="CString">
/// 通过炉号获取委托单中的协议数据
/// <Param name=strHeatID//炉号</Param>
/// </Method>
CString CQA_HeatChemicalData_Mag::GetTechRequestByHeatID(LPCTSTR strHeatID)
{
	CString crSQL,strSQL;
	crSQL = _T("select c.TECH_REQUEST ");
	crSQL +=_T("from CPlan_Tapping_Act a,CPlan_Casting b,CPlan_Order c ");
    crSQL +=_T("where a.HeatID = '%s' ");
    crSQL +=_T("and a.PREHEATID = b.PREHEATID(+) ");
    crSQL +=_T("and b.PLANID = c.PLANID(+) ");
	strSQL.Format(crSQL,strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return _T("");
	else
	{
		rs.MoveFirst();
		return (rs.GetFieldByName(_T("TECH_REQUEST"))).ToCString();
	}
}
/// <Method class="CQA_HeatChemicalData_Mag" name="GetSteelGradeByHeatID" type="CString">
/// 通过炉号获取的钢种
/// <Param name=strHeatID//炉号</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetSteelGradeByHeatID(LPCTSTR strHeatID)
{
	CString crSQL,strSQL;
	crSQL = _T("select b.SteelGrade,b.Protocol ");
	crSQL +=_T("from CPlan_Tapping a,CQA_SteelGradeIndex_R b ");
    crSQL +=_T("where a.HeatID = '%s' ");
    crSQL +=_T("and a.SteelGradeIndex = b.SteelGradeIndex(+) ");
	strSQL.Format(crSQL,strHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	//else
	//{
	//	rs.MoveFirst();
	//	return (rs.GetFieldByName(_T("SteelGrade"))).ToCString();
	//}
	return rs.Detach();
}
/// <Method class="CQA_HeatChemicalData_Mag" name="GetLatelyNewHeatChemicalData" type="L3RECORDSET">
/// 获取最进人工新增的炉次成分数据
/// <Param name=//</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetLatelyNewHeatChemicalData()
{
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Lab_Element where DataLogMode = 1 and Report_Date>? "));
	COleDateTime timeCur = COleDateTime::GetCurrentTime();
	COleDateTime timeOld = timeCur - COleDateTimeSpan(1,0,0,0);
	VARIANT params[1];
	params[0].vt = VT_DATE; params[0].date = (DATE)timeOld;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,1,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetApplyDataByApplyID" type="L3RECORDSET">
/// 根据委托单号获取委托单数据
/// <Param name=strApplyID//</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetApplyDataByApplyID(L3STRING strApplyID)
{
	CString cstrApplyID=strApplyID;
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Lab_Sheet_App where AppID = '%s'"),cstrApplyID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetApplyDataByApplyID" type="L3RECORDSET">
/// 根据委托单号获取委托单数据
/// <Param name=strApplyID//</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetApplyIDByHeatIDAndAddr(L3STRING strHeatID,L3STRING strAddr)
{
	CString cstrApplyID=strHeatID;
	CString cstrAddr = strAddr;
	CString strSQL;
	strSQL.Format(_T("select AppID from CQA_Lab_Sheet_App where HeatID = '%s' and Sample_Address = '%s'"),cstrApplyID,cstrAddr);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetCutAdviceData" type="L3RECORDSET">
/// 获取最进割样通知数据
/// <Param name=//</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetCutAdviceData()
{
	CString strSQL;
	strSQL.Format(_T("select * from CQA_Lab_Cut_Advice where Log_Time >? "));
	COleDateTime timeCur = COleDateTime::GetCurrentTime();
	COleDateTime timeOld = timeCur - COleDateTimeSpan(1,0,0,0);
	VARIANT params[1];
	params[0].vt = VT_DATE; params[0].date = (DATE)timeOld;
	CL3RecordSetWrap rs;
	if(!QueryWithParam(strSQL,params,1,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetSteelGradeByHeatID" type="L3RECORDSET">
/// 根据炉号获取钢种
/// <Param name=strHeatID//炉号</Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetGradeByHeatID(L3STRING strHeatID)
{
	CString cstrHeatID = strHeatID;
	CString crSQL,strSQL;
	crSQL = _T("select b.SteelGrade ");
	crSQL +=_T("from CPlan_Tapping a,CQA_SteelGradeIndex_R b ");
    crSQL +=_T("where a.HeatID = '%s' ");
    crSQL +=_T("and a.SteelGradeIndex = b.SteelGradeIndex(+) ");
	strSQL.Format(crSQL,cstrHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="DeleteCutAdvice" type="L3LONG">
/// 删除割样通知
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::DeleteCutAdvice(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rs.MoveFirst();
	if (DeleteOldObjects(_T("XGMESLogic\\QualityMag\\CQA_Lab_Cut_Advice"),rs)<rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}
	else
	{
		if(bUseTrans)
			Commit(nTrans);
		return rs.GetRowCount();
	}
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetFinalActualHeatChemicalByHeatID" type="L3LONG">
/// 根据炉号获取最终实际成份数据
/// <Param name="strHeatID" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetFinalActualHeatChemicalByHeatID(L3STRING strHeatID)
{
	//获取终点样申请号(非重取样、非回退样)
	CString cstrHeatID = strHeatID;
	CString strSQL;
	strSQL.Format(_T("select AppID from CQA_Lab_Sheet_App where HeatID = '%s' and Fin_Prod_Flag=1 and ReSampled=0 and Back_Flag = 0 "),
		          cstrHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	L3LONG rsCount = rs.GetRowCount();
	if (rsCount < 1)
	{
		return NULL;
	}
	rs.MoveFirst();
	CString cstrAppID = (rs.GetFieldByName(_T("AppID"))).ToCString();
   //根据申请号获取成份数据
	strSQL.Format(_T("select * from CQA_Lab_Element where AppID = '%s'"),cstrAppID);
	CL3RecordSetWrap rstemp;
	if(!Query(strSQL,rstemp))
		return NULL;
	else
		return rstemp.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetFinalStandardHeatChemicalByHeatID" type="L3LONG">
/// 根据炉号获取最终标准成份数据
/// <Param name="strHeatID" type="L3STRING"></Param>
/// </Method>
L3RECORDSET CQA_HeatChemicalData_Mag::GetFinalStandardHeatChemicalByHeatID(L3STRING strHeatID)
{
	//获取终点样申请号(非重取样、非回退样)
	CString cstrHeatID = strHeatID;
	CString strSQL;
	strSQL.Format(_T("select Sample_Address from CQA_Lab_Sheet_App where HeatID = '%s' and Fin_Prod_Flag=1 and ReSampled=0 and Back_Flag = 0 "),
		          cstrHeatID);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	L3LONG rsCount = rs.GetRowCount();
	if (rsCount < 1)
	{
		return NULL;
	}
	rs.MoveFirst();
	CString cstrSampleAddr = (rs.GetFieldByName(_T("Sample_Address"))).ToCString();
	CL3Variant valtemp = GetObjectPropValue(_T("MES\\MaterialData\\CSteel_Data\\")+cstrHeatID,_T("SteelGradeIndex"));
	CString cstrSteelGradeIndex = valtemp.ToCString();
   //根据取样地点获取标准成份
	CString cstrClassName;
	if (cstrSampleAddr.Left(1) == _T("Z"))
		cstrClassName = _T("CQA_BOF_Std_InCtr_Ele");
	else if (cstrSampleAddr.Left(1) == _T("F"))
		cstrClassName = _T("CQA_LF_Std_InCtr_Ele");
	else if (cstrSampleAddr.Left(1) == _T("R"))
		cstrClassName = _T("CQA_RH_Std_InCtr_Ele");
	else if (cstrSampleAddr.Left(1) == _T("L"))
		cstrClassName = _T("CQA_Caster_Std_InCtr_Ele");
	else
		return NULL;

	strSQL.Format(_T("select * from %s where SteelGradeIndex = %s"),cstrClassName,cstrSteelGradeIndex);
	CL3RecordSetWrap rstemp;
	if(!Query(strSQL,rstemp))
		return NULL;
	else
		return rstemp.Detach();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GetReHeatCount" type="L3LONG">
/// 获取重处理次数
/// <Param name="strHeatID" type="L3STRING"></Param>
/// <Param name="nUnitType" type="L3LONG"></Param>
/// <Param name="nUnitID" type="L3LONG"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::GetReHeatCount(L3STRING strHeatID,L3LONG nUnitType,L3LONG nUnitID)
{
	if (strHeatID == NULL)
	{
		return -1;
	}
	CString cstrHeatID = strHeatID;
	CString strSQL;
	if (nUnitType = UNIT_AREA_BOF)
	{
		strSQL.Format(_T("select count(HeatID) as ProcessCount from CBOF_Base_Data where HeatID = '%s' and substr(HeatID,2,1)=%d"),
		              cstrHeatID,nUnitID);
	}
	else if (nUnitType = UNIT_AREA_LF)
	{
		strSQL.Format(_T("select count(HeatID) as ProcessCount from CLF_Base_Data where HeatID = '%s' and substr(TreatNo,2,1)=%d"),
		              cstrHeatID,nUnitID);
	}
	else if (nUnitType = UNIT_AREA_RH)
	{
		strSQL.Format(_T("select count(HeatID) as ProcessCount from CRH_Base_Data where HeatID = '%s' and substr(TreatNo,2,1)=%d"),
		              cstrHeatID,nUnitID);
	}
	else if (nUnitType = UNIT_AREA_CASTER)
	{
		strSQL.Format(_T("select count(HeatID) as ProcessCount from CCCM_Base_Data where HeatID = '%s' and substr(TreatNo,2,1)=%d"),
		              cstrHeatID,nUnitID);
	}
	else
	{
		return -2;
	}
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	L3LONG rsCount = rs.GetRowCount();
	if (rsCount < 1)
	{
		return -3;
	}
	rs.MoveFirst();
	return (rs.GetFieldByName(_T("ProcessCount"))).ToLong()-1;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="NewHeatExceptionData" type="L3LONG">
/// 生产新的炉次工艺异常数据
/// <Param name="strHeatID" type="L3STRING"></Param>
/// <Param name="nUnitType" type="L3LONG"></Param>
/// <Param name="nUnitID" type="L3LONG"></Param>
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG CQA_HeatChemicalData_Mag::NewHeatExceptionData(L3STRING strHeatID,L3LONG nUnitType,L3LONG nUnitID,L3RECORDSET rsData)
{
	if ((strHeatID == NULL) || (rsData == NULL) || (rsData->GetRecordCount() < 1))
	{
		return -1;
	}

	//获取重处理次数
	L3SHORT nProcessCount = GetReHeatCount(strHeatID,nUnitType,nUnitID);
	  //调用记录炉次工艺异常方法
	//return LogHeatExceptionData(nUnitType,nUnitID,strHeatID,nProcessCount,rsData);	
	  //调用记录炉次工艺异常方法
	CL3Variant valReturn = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssume_Mag\\QA_HeatGradeAssume_Mag"),
											_T("LogHeatExceptionData"),
											(L3SHORT)nUnitType,
											(L3SHORT)nUnitID,
											strHeatID,
											(L3SHORT)nProcessCount,
											(L3RECORDSET)rsData);	
	if (valReturn.IsError())  
	{		
		return -2;
	}

	return 0;

}
L3LONG CQA_HeatChemicalData_Mag::LogHeatExceptionData(L3SHORT nUnitTypeID,
													 L3SHORT nUnitID, 
													 L3STRING strHeatID, 
													 L3SHORT nProcessCount, 
													 L3RECORDSET rsData)
{
	if (strHeatID == NULL) 
		return -1;

	//***********************//			
	CL3RecordSetWrap rs=rsData;
	if(rs.GetRowCount()<1)
	{
		return -1;
	}

	CString cstrHeatID = strHeatID;

	rs.MoveFirst();
	CString strExceptionalCode = (rs.GetFieldByName(_T("Exceptional_Code"))).ToCString();

	//查询炉次当前预定炉号、炼钢记号
	CString strPresetHeatID = (GetObjectPropValue(PLAN_TAPPING_CLASS_URI+_T("\\")+cstrHeatID,_T("PreHeatID"))).ToCString();
	CString strSteelGradeIndex = (GetObjectPropValue(PLAN_TAPPING_CLASS_URI+_T("\\")+cstrHeatID,_T("SteelGradeIndex"))).ToCString();
	CString strPreSteelGradeIndex = (GetObjectPropValue(PLAN_TAPPING_CLASS_URI+_T("\\")+cstrHeatID,_T("Pre_SteelGradeIndex"))).ToCString();

    CString cstrUnitTypeID,cstrUnitID,strProcessCount; 
    strProcessCount.Format(_T("%d"),nProcessCount);
	cstrUnitTypeID.Format(_T("%d"),nUnitTypeID);
	cstrUnitID.Format(_T("%d"),nUnitID);
	cstrUnitTypeID = _T("S")+cstrUnitTypeID;

	CString strPky = cstrHeatID + cstrUnitTypeID + cstrUnitID + strProcessCount + strExceptionalCode;

	CString strURI = _T("XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except");//获取类URI
 	CL3RecordSetWrap RS;
	if(this ->CreateClassPropSet(strURI,RS))
	{
		RS.DeleteRecord();
		RS->CopyFrom(rsData);
		RS.MoveFirst();
		RS.SetFieldByName(_T("ID_Object"),CL3Variant(strPky));
		RS.SetFieldByName(_T("UnitTypeID"),(L3SHORT)nUnitTypeID);
		RS.SetFieldByName(_T("UnitID"),(L3SHORT)nUnitID);
		RS.SetFieldByName(_T("HeatID"),strHeatID);
		RS.SetFieldByName(_T("PreHeatID"),CL3Variant(strPresetHeatID));
		RS.SetFieldByName(_T("SteelGradeIndex"),CL3Variant(strSteelGradeIndex));
		RS.SetFieldByName(_T("Pre_SteelGradeIndex"),CL3Variant(strPreSteelGradeIndex));
        RS.SetFieldByName(_T("ProcessCount"),(L3SHORT)nProcessCount);
	}
	if (CreateNewObjects(strURI, RS) < 1)
		return -2;//新增工艺异常失败
	return 0;	
}

/// <Method class="CQA_HeatChemicalData_Mag" name="AcceptBFIronElementData" type="L3LONG">
/// 接收高炉铁水样实绩
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::AcceptBFIronElementData(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return -1;

	rs.MoveFirst();

	while(!rs.IsEOF())
	{
		CString cstrSample_Type = rs.GetFieldByName(_T("Sample_Type")).ToCString();
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString cstrTpcNo = rs.GetFieldByName(_T("TPC_No")).ToCString();

		if(cstrSample_Type == _T("TS")) //脱硫样
		{
			CString cstrID = cstrTapNo+cstrTpcNo;
			CString csUri = _T("MES\\MaterialData\\CBFIron\\")+cstrID;
			SetObjectPropValue(csUri,_T("Sample_Place"),_T("TS"));

			L3FLOAT fC = -1;
			CL3Variant valC = rs.GetFieldByName(_T("C"));
			if (!(valC.IsError() || valC.IsNull() || valC.IsEmpty()))
			{
				fC = valC.ToFloat();
				if (fC > 0.00001)
				{
					SetObjectPropValue(csUri,_T("C"),valC);
				}
			}
			L3FLOAT fSi = -1;
			CL3Variant valSi = rs.GetFieldByName(_T("Si"));
			if (!(valSi.IsError() || valSi.IsNull() || valSi.IsEmpty()))
			{
				fSi = valSi.ToFloat();
				if (fSi > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Si"),valSi);
				}
			}
			L3FLOAT fMn = -1;
			CL3Variant valMn = rs.GetFieldByName(_T("Mn"));
			if (!(valMn.IsError() || valMn.IsNull() || valMn.IsEmpty()))
			{
				fMn = valMn.ToFloat();
				if (fMn > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Mn"),valMn);
				}
			}
			L3FLOAT fP = -1;
			CL3Variant valP = rs.GetFieldByName(_T("P"));
			if (!(valP.IsError() || valP.IsNull() || valP.IsEmpty()))
			{
				fP = valP.ToFloat();
				if (fP > 0.00001)
				{
					SetObjectPropValue(csUri,_T("P"),valP);
				}
			}
			L3FLOAT fS = -1;
			CL3Variant valS = rs.GetFieldByName(_T("S"));
			if (!(valS.IsError() || valS.IsNull() || valS.IsEmpty()))
			{
				fS = valS.ToFloat();
				if (fS > 0.00001)
				{
					SetObjectPropValue(csUri,_T("S"),valS);
				}
			}
			L3FLOAT fTi = -1;
			CL3Variant valTi = rs.GetFieldByName(_T("Ti"));
			if (!(valTi.IsError() || valTi.IsNull() || valTi.IsEmpty()))
			{
				fTi = valTi.ToFloat();
				if (fTi > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Ti"),valTi);
				}
			}

			//add by hyh 2012-04-04
			//Sn
			L3FLOAT fSn = -1;
			CL3Variant valSn = rs.GetFieldByName(_T("Sn"));
			if (!(valSn.IsError() || valSn.IsNull() || valSn.IsEmpty()))
			{
				fSn = valSn.ToFloat();
				if (fSn > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Sn"),valSn);
				}
			}
			//Sb
			L3FLOAT fSb = -1;
			CL3Variant valSb = rs.GetFieldByName(_T("Sb"));
			if (!(valSb.IsError() || valSb.IsNull() || valSb.IsEmpty()))
			{
				fSb = valSb.ToFloat();
				if (fSb > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Sb"),valSb);
				}
			}
			//As
			L3FLOAT fAs = -1;
			CL3Variant valAs = rs.GetFieldByName(_T("As"));
			if (!(valAs.IsError() || valAs.IsNull() || valAs.IsEmpty()))
			{
				fAs = valAs.ToFloat();
				if (fAs > 0.00001)
				{
					SetObjectPropValue(csUri,_T("As"),valAs);
				}
			}
			//Pb
			L3FLOAT fPb = -1;
			CL3Variant valPb = rs.GetFieldByName(_T("Pb"));
			if (!(valPb.IsError() || valPb.IsNull() || valPb.IsEmpty()))
			{
				fPb = valPb.ToFloat();
				if (fPb > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Pb"),valPb);
				}
			}
			//end

			//add by hyh 2012-08-13 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
			L3FLOAT fNi = -1;
			CL3Variant valNi = rs.GetFieldByName(_T("Ni"));
			if (!(valNi.IsError() || valNi.IsNull() || valNi.IsEmpty()))
			{
				fNi = valNi.ToFloat();
				if (fNi > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Ni"),valNi);
				}
			}
			L3FLOAT fMo = -1;
			CL3Variant valMo = rs.GetFieldByName(_T("Mo"));
			if (!(valMo.IsError() || valMo.IsNull() || valMo.IsEmpty()))
			{
				fMo = valMo.ToFloat();
				if (fMo > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Mo"),valMo);
				}
			}
			L3FLOAT fCu = -1;
			CL3Variant valCu = rs.GetFieldByName(_T("Cu"));
			if (!(valCu.IsError() || valCu.IsNull() || valCu.IsEmpty()))
			{
				fCu = valCu.ToFloat();
				if (fCu > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Cu"),valCu);
				}
			}
			L3FLOAT fCr = -1;
			CL3Variant valCr = rs.GetFieldByName(_T("Cr"));
			if (!(valCr.IsError() || valCr.IsNull() || valCr.IsEmpty()))
			{
				fCr = valCr.ToFloat();
				if (fCr > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Cr"),valCr);
				}
			}
			L3FLOAT fB = -1;
			CL3Variant valB = rs.GetFieldByName(_T("B"));
			if (!(valB.IsError() || valB.IsNull() || valB.IsEmpty()))
			{
				fB = valB.ToFloat();
				if (fB > 0.00001)
				{
					SetObjectPropValue(csUri,_T("B"),valB);
				}
			}
			L3FLOAT fV = -1;
			CL3Variant valV = rs.GetFieldByName(_T("V"));
			if (!(valV.IsError() || valV.IsNull() || valV.IsEmpty()))
			{
				fV = valV.ToFloat();
				if (fV > 0.00001)
				{
					SetObjectPropValue(csUri,_T("V"),valV);
				}
			}

			L3FLOAT fAl = -1;
			CL3Variant valAl = rs.GetFieldByName(_T("Al"));
			if (!(valAl.IsError() || valAl.IsNull() || valAl.IsEmpty()))
			{
				fAl = valAl.ToFloat();
				if (fAl > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Al"),valAl);
				}
			}

			L3FLOAT fNb = -1;
			CL3Variant valNb = rs.GetFieldByName(_T("Nb"));
			if (!(valNb.IsError() || valNb.IsNull() || valNb.IsEmpty()))
			{
				fNb = valNb.ToFloat();
				if (fNb > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Nb"),valNb);
				}
			}

			L3FLOAT fZn = -1;
			CL3Variant valZn = rs.GetFieldByName(_T("Zn"));
			if (!(valZn.IsError() || valZn.IsNull() || valZn.IsEmpty()))
			{
				fZn = valZn.ToFloat();
				if (fZn > 0.00001)
				{
					SetObjectPropValue(csUri,_T("Zn"),valZn);
				}
			}
			
			L3FLOAT fW = -1;
			CL3Variant valW = rs.GetFieldByName(_T("W"));
			if (!(valW.IsError() || valW.IsNull() || valW.IsEmpty()))
			{
				fW = valW.ToFloat();
				if (fW > 0.00001)
				{
					SetObjectPropValue(csUri,_T("W"),valW);
				}
			}
			//end
			

			L3STRING bstrID = cstrID.AllocSysString();
			InvokeObjectMethod(_T("XGMESLogic\\BFMag\\CBF_Iron_Mag\\BFIronMag"),_T("Complete"),bstrID);
			L3SysFreeString(bstrID);

			/***2009-10-25 Begin yao***/
			CString csSampleCode = rs.GetFieldByName(_T("Sample_Code")).ToCString();
			if(csSampleCode.GetLength() == 15)
			{
    			SetDeSAnalysisData(csSampleCode,fS,fP);
			}
			/***2009-10-25 End***/

		}
		else //铁沟样
		{
			//根据铁次号设置高炉铁水成份数据
			CString strSQL;
			strSQL.Format(_T("select * from CBFIron where TAP_No ='%s' order by TAP_No"),
						  cstrTapNo);
			CL3RecordSetWrap rsIron;
			if(!Query(strSQL,rsIron))
				return -3;
			L3LONG rsCount = rsIron.GetRowCount();
			if (rsCount > 0)
			{
				rsIron.MoveFirst();

				CString csTapNo = rsIron.GetFieldByName(_T("TAP_No")).ToCString();

				//组建高炉铁水成份记录集
				CL3RecordSet *pRSBF = new CL3RecordSet();
				CL3RecordSetWrap rsBFChemical; pRSBF->QueryInterface(IID_IL3RecordSet,rsBFChemical); pRSBF->Release();
				rsBFChemical.AddField(_T("MaterialID"),VT_BSTR);
				rsBFChemical.AddField(_T("C"),VT_BSTR);
				rsBFChemical.AddField(_T("Si"),VT_BSTR);
				rsBFChemical.AddField(_T("Mn"),VT_BSTR);
				rsBFChemical.AddField(_T("P"),VT_BSTR);
				rsBFChemical.AddField(_T("S"),VT_BSTR);
				rsBFChemical.AddField(_T("Ti"),VT_BSTR);

				//add by hyh 2012-04-04
				rsBFChemical.AddField(_T("Sn"),VT_BSTR);
				rsBFChemical.AddField(_T("Sb"),VT_BSTR);
				rsBFChemical.AddField(_T("As"),VT_BSTR);
				rsBFChemical.AddField(_T("Pb"),VT_BSTR);
				//end

				//add by hyh 2012-08-13  应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
				rsBFChemical.AddField(_T("Ni"),VT_BSTR);
				rsBFChemical.AddField(_T("Mo"),VT_BSTR);
				rsBFChemical.AddField(_T("Cu"),VT_BSTR);
				rsBFChemical.AddField(_T("Cr"),VT_BSTR);
				rsBFChemical.AddField(_T("B"),VT_BSTR);
				rsBFChemical.AddField(_T("V"),VT_BSTR);
				rsBFChemical.AddField(_T("Al"),VT_BSTR);
				rsBFChemical.AddField(_T("Nb"),VT_BSTR);
				rsBFChemical.AddField(_T("Zn"),VT_BSTR);
				rsBFChemical.AddField(_T("W"),VT_BSTR);
				//end

				rsBFChemical.AddField(_T("C_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Si_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Mn_B"),VT_BSTR);
				rsBFChemical.AddField(_T("P_B"),VT_BSTR);
				rsBFChemical.AddField(_T("S_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Ti_B"),VT_BSTR);
				//add by hyh 2012-04-04
				rsBFChemical.AddField(_T("Sn_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Sb_B"),VT_BSTR);
				rsBFChemical.AddField(_T("As_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Pb_B"),VT_BSTR);
				//end

				//add by hyh 2012-08-13  应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
				rsBFChemical.AddField(_T("Ni_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Mo_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Cu_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Cr_B"),VT_BSTR);
				rsBFChemical.AddField(_T("B_B"),VT_BSTR);
				rsBFChemical.AddField(_T("V_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Al_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Nb_B"),VT_BSTR);
				rsBFChemical.AddField(_T("Zn_B"),VT_BSTR);
				rsBFChemical.AddField(_T("W_B"),VT_BSTR);
				//end
				rsBFChemical.AddField(_T("AnalysisFlag"),VT_I4);
				rsBFChemical.AddField(_T("SampCode"),VT_BSTR);
				rsBFChemical.AddField(_T("Sample_Place"),VT_BSTR);
				rsBFChemical.AddField(_T("Operator_B"),VT_BSTR);//2009-04-23

				while(!rsIron.IsEOF())
				{
					rsBFChemical.AppendRecord();
					rsBFChemical.MoveLast();
					CString cstrTpcNo = rsIron.GetFieldByName(_T("TPC_No")).ToCString();
					CString cstrID = cstrTapNo+cstrTpcNo;
					rsBFChemical.SetFieldByName(_T("MaterialID"),CL3Variant(cstrID));
					rsBFChemical.SetFieldByName(_T("C"),rs.GetFieldByName(_T("C")));
					rsBFChemical.SetFieldByName(_T("Si"),rs.GetFieldByName(_T("Si")));
					rsBFChemical.SetFieldByName(_T("Mn"),rs.GetFieldByName(_T("MN")));
					rsBFChemical.SetFieldByName(_T("P"),rs.GetFieldByName(_T("P")));
					rsBFChemical.SetFieldByName(_T("S"),rs.GetFieldByName(_T("S")));
					rsBFChemical.SetFieldByName(_T("Ti"),rs.GetFieldByName(_T("TI")));

					//add by hyh 2012-04-04
					rsBFChemical.SetFieldByName(_T("Sn"),rs.GetFieldByName(_T("SN")));
					rsBFChemical.SetFieldByName(_T("Sb"),rs.GetFieldByName(_T("SB")));
					rsBFChemical.SetFieldByName(_T("As"),rs.GetFieldByName(_T("AS")));
					rsBFChemical.SetFieldByName(_T("Pb"),rs.GetFieldByName(_T("PB")));
					//end

					//add by hyh 2012-08-13  应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
					rsBFChemical.SetFieldByName(_T("Ni"),rs.GetFieldByName(_T("Ni")));
					rsBFChemical.SetFieldByName(_T("Mo"),rs.GetFieldByName(_T("Mo")));
					rsBFChemical.SetFieldByName(_T("Cu"),rs.GetFieldByName(_T("Cu")));
					rsBFChemical.SetFieldByName(_T("Cr"),rs.GetFieldByName(_T("Cr")));
					rsBFChemical.SetFieldByName(_T("B"),rs.GetFieldByName(_T("B")));
					rsBFChemical.SetFieldByName(_T("V"),rs.GetFieldByName(_T("V")));
					rsBFChemical.SetFieldByName(_T("Al"),rs.GetFieldByName(_T("Al")));
					rsBFChemical.SetFieldByName(_T("Nb"),rs.GetFieldByName(_T("Nb")));
					rsBFChemical.SetFieldByName(_T("Zn"),rs.GetFieldByName(_T("Zn")));
					rsBFChemical.SetFieldByName(_T("W"),rs.GetFieldByName(_T("W")));
					//end

					rsBFChemical.SetFieldByName(_T("C_B"),rs.GetFieldByName(_T("C")));
					rsBFChemical.SetFieldByName(_T("Si_B"),rs.GetFieldByName(_T("SI")));
					rsBFChemical.SetFieldByName(_T("Mn_B"),rs.GetFieldByName(_T("MN")));
					rsBFChemical.SetFieldByName(_T("P_B"),rs.GetFieldByName(_T("P")));
					rsBFChemical.SetFieldByName(_T("S_B"),rs.GetFieldByName(_T("S")));
					rsBFChemical.SetFieldByName(_T("Ti_B"),rs.GetFieldByName(_T("TI")));

					//add by hyh 2012-04-04
					rsBFChemical.SetFieldByName(_T("Sn_B"),rs.GetFieldByName(_T("SN")));
					rsBFChemical.SetFieldByName(_T("Sb_B"),rs.GetFieldByName(_T("SB")));
					rsBFChemical.SetFieldByName(_T("As_B"),rs.GetFieldByName(_T("AS")));
					rsBFChemical.SetFieldByName(_T("Pb_B"),rs.GetFieldByName(_T("PB")));
					//end

					//add by hyh 2012-08-13  应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
					rsBFChemical.SetFieldByName(_T("Ni_B"),rs.GetFieldByName(_T("Ni")));
					rsBFChemical.SetFieldByName(_T("Mo_B"),rs.GetFieldByName(_T("Mo")));
					rsBFChemical.SetFieldByName(_T("Cu_B"),rs.GetFieldByName(_T("Cu")));
					rsBFChemical.SetFieldByName(_T("Cr_B"),rs.GetFieldByName(_T("Cr")));
					rsBFChemical.SetFieldByName(_T("B_B"),rs.GetFieldByName(_T("B")));
					rsBFChemical.SetFieldByName(_T("V_B"),rs.GetFieldByName(_T("V")));
					rsBFChemical.SetFieldByName(_T("Al_B"),rs.GetFieldByName(_T("Al")));
					rsBFChemical.SetFieldByName(_T("Nb_B"),rs.GetFieldByName(_T("Nb")));
					rsBFChemical.SetFieldByName(_T("Zn_B"),rs.GetFieldByName(_T("Zn")));
					rsBFChemical.SetFieldByName(_T("W_B"),rs.GetFieldByName(_T("W")));
					//end

					rsBFChemical.SetFieldByName(_T("Sample_Place"),CL3Variant(_T("0")));
					rsBFChemical.SetFieldByName(_T("AnalysisFlag"),CL3Variant((L3LONG)1));
					rsBFChemical.SetFieldByName(_T("SampCode"),rs.GetFieldByName(_T("Sample_Code")));
					rsBFChemical.SetFieldByName(_T("Sample_Place"),CL3Variant(_T("BF")));
					rsBFChemical.SetFieldByName(_T("Operator_B"),rs.GetFieldByName(_T("Operator")));//2009-04-23

					L3STRING bstrID = cstrID.AllocSysString();
					InvokeObjectMethod(_T("XGMESLogic\\BFMag\\CBF_Iron_Mag\\BFIronMag"),_T("Complete"),bstrID);
					L3SysFreeString(bstrID);

					rsIron.MoveNext();
				}

				SetObjsPropValues(_T("MES\\MaterialData\\CBFIron"),rsBFChemical);
			}
		}
		rs.MoveNext();
	}

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="GenLabSheet" type="L3LONG">
/// 生成化验委托单据
/// <Param name="strSampleType" type="L3STRING">试样类别</Param>
/// <Param name="strAddr" type="L3STRING">取样地点</Param>
/// <Param name="strHeatID" type="L3STRING">炉号</Param>
/// <Param name="nFinalFlag" type="L3STRING">成品样标志</Param>
/// </Method>
L3RECORDSET  CQA_HeatChemicalData_Mag::GenLabSheet(L3STRING strSampleType,L3STRING strAddr,L3STRING strHeatID,L3LONG nFinalFlag)
{
	if ((strSampleType==NULL) || (strAddr==NULL) || (strHeatID == NULL))
	{
		return NULL;
	}

	CString csSampleType = strSampleType;
	CString csAddr = strAddr;
	CString csHeatID = strHeatID;

    CString cstrAppID = CalLabSheetAppID(csAddr,strSampleType);

	//试样编码
	CString cstrSampleCode;
	cstrSampleCode = CalBOFSampleCode(csSampleType,csAddr,csHeatID);

	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rs))
		return NULL;

	rs.AppendRecord();

	 //申请号
	rs.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
	//试样编码
	rs.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
	//试样次数
	rs.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
	//试样日期
	rs.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
	rs.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rs.SetFieldByName(_T("Sample_Address"),CL3Variant(csAddr));
	rs.SetFieldByName(_T("Sample_Type"),CL3Variant(csSampleType));
	rs.SetFieldByName(_T("Fin_Prod_Flag"),(L3LONG)nFinalFlag);

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return NULL;
	}

	rs.MoveFirst();
    int ntemp = rs.GetRowCount();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rs);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return NULL;
	}

	if(bUseTrans)
		Commit(nTrans);

	return rs.Detach();
}


//一键钢水发送委托单
L3LONG  CQA_HeatChemicalData_Mag::GenLabSheetNew(L3STRING strSampleType,L3STRING strAddr,L3STRING strHeatID,L3STRING strSteelGradeIndex,L3LONG nFinalFlag)
{
	if ((strSampleType==NULL) || (strAddr==NULL) || (strHeatID == NULL)||(strSteelGradeIndex == NULL))
	{
		return -1;
	}

	CString csSampleType = strSampleType;
	CString csAddr = strAddr;
	CString csHeatID = strHeatID;
    //试样编码与申请号一样
   /* CString cstrAppID = CalLabSheetAppID(csAddr,strSampleType);*/
	 CString cstrAppID =CalBOFSampleCode(csSampleType,csAddr,csHeatID);
	//试样编码
	CString cstrSampleCode;
	cstrSampleCode = cstrAppID;

	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rs))
		return -2;

	rs.AppendRecord();

	 //申请号
	rs.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
	//试样编码
	rs.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
	//试样次数
	rs.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
	//试样日期
	rs.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
	rs.SetFieldByName(_T("HeatID"),CL3Variant(csHeatID));
	rs.SetFieldByName(_T("Sample_Address"),CL3Variant(csAddr));
	rs.SetFieldByName(_T("Sample_Type"),CL3Variant(csSampleType));
	rs.SetFieldByName(_T("Fin_Prod_Flag"),(L3LONG)nFinalFlag);

 

	CL3RecordSetWrap rsGrade;
    //获取钢种 协议号
	CString csSQL;
	csSQL.Format(_T("select STEELGRADE,PROTOCOL from CQA_STEELGRADEINDEX_R where STEELGRADEINDEX = '%s' "),strSteelGradeIndex);
	if(!Query(csSQL,rsGrade))
		return -3;
	rsGrade.MoveFirst();

	rs.SetFieldByName(_T("SteelGrade"),CL3Variant(rsGrade.GetFieldByIndex(0).ToString()));
	rs.SetFieldByName(_T("Treaty"),CL3Variant(rsGrade.GetFieldByIndex(1).ToString()));




	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -4;
	}

	rs.MoveFirst();
    int ntemp = rs.GetRowCount();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rs);
	if(nRet < rs.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -6;
	}

	if(bUseTrans)
		Commit(nTrans);

   /* rs.MoveFirst();
	SendSheetDataToAnaL2(rs);*/
	return 1;
}




/// <Method class="CQA_HeatChemicalData_Mag" name="SendSheetDataToAnaL2" type="L3BOOL">
/// 将委托单下传检化验 2009-01-03 
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL  CQA_HeatChemicalData_Mag::SendSheetDataToAnaL2(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;

	if(rs.GetRowCount() < 1)
		return false;

	//组建数据集
	CL3RecordSet *pRSheet = new CL3RecordSet();
	CL3RecordSetWrap rsSheet; pRSheet->QueryInterface(IID_IL3RecordSet,rsSheet); pRSheet->Release();
	rsSheet.AddField(_T("CommissionID"),VT_BSTR);
	rsSheet.AddField(_T("SampID"),VT_BSTR);
	rsSheet.AddField(_T("SampSort"),VT_BSTR);
	rsSheet.AddField(_T("SampPlace"),VT_BSTR);
	rsSheet.AddField(_T("SteelGrade"),VT_BSTR);
	rsSheet.AddField(_T("Contract"),VT_BSTR);
	rsSheet.AddField(_T("SendDate"),VT_BSTR);
	rsSheet.AddField(_T("PERMIT_DELETE_FLAG"),VT_INT);

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsSheet.AppendRecord();
		rsSheet.SetFieldByName(_T("CommissionID"),rs.GetFieldByName(_T("AppID")));
		rsSheet.SetFieldByName(_T("SampID"),rs.GetFieldByName(_T("Sample_Code")));
		rsSheet.SetFieldByName(_T("SampSort"),rs.GetFieldByName(_T("Sample_Type")));
		rsSheet.SetFieldByName(_T("SampPlace"),rs.GetFieldByName(_T("Sample_Address")));
		rsSheet.SetFieldByName(_T("SteelGrade"),rs.GetFieldByName(_T("SteelGrade")));
		rsSheet.SetFieldByName(_T("Contract"),rs.GetFieldByName(_T("Treaty")));
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		rsSheet.SetFieldByName(_T("SendDate"),CL3Variant(curTime.Format(_T("%Y-%m-%d %H:%M:%S"))));
		rsSheet.SetFieldByName(_T("PERMIT_DELETE_FLAG"),L3LONG(1));
		rs.MoveNext();
	}

	//L3LONG nPosID = 2;
	//CString csTableName = _T("TB_L3_ANACOMMISSION");
	//L3STRING strTableName = csTableName.AllocSysString();
	//InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
	//				    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
	//					strTableName,(L3RECORDSET)rsSheet);
	//L3SysFreeString(strTableName);

	//csTableName = _T("TB_L3_ANACOMMISSIONHIS");
	//strTableName = csTableName.AllocSysString();
	//InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
	//				    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
	//					strTableName,(L3RECORDSET)rsSheet);
	//L3SysFreeString(strTableName);

	//2009-04-07 Begin

	rsSheet.MoveFirst();
	if (CreateNewObjects(_T("XGMESLogic\\QualityMag\\TB_L3_ANACOMMISSION"),rsSheet) < rsSheet.GetRowCount())
		return false;

	//2009-04-07 End

	return true;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="SendAnalysisDataToPLC" type="L3BOOL">
/// 将高拉碳炉终样下传PLC 2009-03-21
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL  CQA_HeatChemicalData_Mag::SendAnalysisDataToPLC(L3FLOAT C_Ana,L3FLOAT S_Ana,L3FLOAT P_Ana)
{
	//组建数据集
	CL3RecordSet *pRSheet = new CL3RecordSet();
	CL3RecordSetWrap rsAna; pRSheet->QueryInterface(IID_IL3RecordSet,rsAna); rsAna->Release();
	rsAna.AddField(_T("C_Ana"),VT_R8);
	rsAna.AddField(_T("P_Ana"),VT_R8);
	rsAna.AddField(_T("S_Ana"),VT_R8);
	rsAna.AddField(_T("Permit_Delete_Flag"),VT_INT);

	rsAna.AppendRecord();
	rsAna.SetFieldByName(_T("C_Ana"),CL3Variant(C_Ana));
	rsAna.SetFieldByName(_T("P_Ana"),CL3Variant(P_Ana));
	rsAna.SetFieldByName(_T("S_Ana"),CL3Variant(S_Ana));
	rsAna.SetFieldByName(_T("Permit_Delete_Flag"),L3LONG(1));

	L3LONG nPosID = 4;
	CString csTableName = _T("BOF4_PLCAnalysis");
	L3STRING strTableName = csTableName.AllocSysString();
	InvokeObjectMethod(_T("\\L3\\AppLogic\\CL2CommLogic\\L2CommLogic"),
					    _T("ReqSendL3DataToL2"),(L3LONG)nPosID,
						strTableName,(L3RECORDSET)rsAna);
	L3SysFreeString(strTableName);

	return true;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="NewBFIronSheet" type="L3LONG">
/// 生成铁沟样化验委托单据
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::NewBFIronSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	CL3RecordSetWrap rsApp;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rsApp))
	{
		return -1;
	}

	// 补齐字段信息
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//取铁次号
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString cstrBFID = cstrTapNo.Mid(1,1);
        CString cstrAppID = CalLabSheetAppID(_T("G")+cstrBFID,_T("TG"));
		//试样编码
		CString cstrSampleCode = CalIronSampleCode(_T("G")+cstrBFID,_T("TG"),cstrTapNo);

		rsApp.AppendRecord();
		rsApp.MoveLast();
		 //申请号
		rsApp.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
		//试样编码
		rsApp.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
		//试样次数
		rsApp.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
		//试样日期
		rsApp.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
		//试样地点
		rsApp.SetFieldByName(_T("Sample_Address"),CL3Variant(_T("G")+cstrBFID));    
		//试样类别
		rsApp.SetFieldByName(_T("Sample_Type"),CL3Variant(_T("TG")));    

		rs.MoveNext();
	}

	int rscount = rsApp.GetRowCount();
	if (rscount < 1)
	{
		return -2;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsApp.MoveFirst();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rsApp);
	if(nRet < rsApp.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}

	//2009-04-07 Begin
	if (!SendSheetDataToAnaL2(rsApp))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}
	//2009-04-07 End

	if(bUseTrans)
		Commit(nTrans);

	//if (!SendSheetDataToAnaL2(rsApp))
	//{
	//	return -5;
	//}
	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="NewBFSlagSheet" type="L3LONG">
/// 生成铁样化验委托单据2009-04-14 制定铁沟样同时制定铁渣样
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::NewBFSlagSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	CL3RecordSetWrap rsApp;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rsApp))
	{
		return -1;
	}

	// 补齐字段信息
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//取铁次号
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString cstrBFID = cstrTapNo.Mid(1,1);
        CString cstrAppID = CalLabSheetAppID(_T("G")+cstrBFID,QA_Sample_Type_ZG);
		//试样编码
		CString cstrSampleCode = CalIronSampleCode(_T("G")+cstrBFID,QA_Sample_Type_ZG,cstrTapNo);

		rsApp.AppendRecord();
		rsApp.MoveLast();
		 //申请号
		rsApp.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
		//试样编码
		rsApp.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
		//试样次数
		rsApp.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(2)));  
		//试样日期
		rsApp.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
		//试样地点
		rsApp.SetFieldByName(_T("Sample_Address"),CL3Variant(_T("G")+cstrBFID));    
		//试样类别
		rsApp.SetFieldByName(_T("Sample_Type"),CL3Variant(QA_Sample_Type_ZG));    

		rs.MoveNext();
	}

	int rscount = rsApp.GetRowCount();
	if (rscount < 1)
	{
		return -2;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	rsApp.MoveFirst();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rsApp);
	if(nRet < rsApp.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}

	if (!SendSheetDataToAnaL2(rsApp))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}

	if(bUseTrans)
		Commit(nTrans);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="NewDeSIronSheet" type="L3LONG">
/// 生成脱硫预处理样化验委托单据
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3LONG  CQA_HeatChemicalData_Mag::NewDeSIronSheet(L3RECORDSET rsData)
{
	CL3RecordSetWrap rs = rsData;
	if(rs.GetRowCount() < 1)
		return 0;

	CL3RecordSetWrap rsApp;
	if(!CreateClassPropSet(QA_LAB_SHEET_APP_CLASS_URI,rsApp))
	{
		return -1;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// 补齐字段信息
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//取铁次号
		CString cstrTapNo = rs.GetFieldByName(_T("TAP_No")).ToCString();
		CString cstrTPCNo = rs.GetFieldByName(_T("TPC_No")).ToCString();
		L3SHORT iMode = rs.GetFieldByName(_T("Mode")).ToShort();

		if (cstrTapNo.GetLength() < 2)//2009-04-16
		{
			rs.MoveNext();
			continue;
		}
		CString cstrBFID = cstrTapNo.Mid(1,1);//2009-04-16
        CString cstrAppID = CalLabSheetAppID(_T("G")+cstrBFID,_T("TS"));
		//试样编码
		CString cstrSampleCode = CalDesIronSampleCode(cstrTapNo,cstrTPCNo,iMode);

		rsApp.AppendRecord();
		rsApp.MoveLast();
		 //申请号
		rsApp.SetFieldByName(_T("AppID"),CL3Variant(cstrAppID));
		//试样编码
		rsApp.SetFieldByName(_T("Sample_Code"),CL3Variant(cstrSampleCode));    
		//试样次数
		rsApp.SetFieldByName(_T("Sample_Count"),CL3Variant(cstrSampleCode.Right(1)));  
		//试样日期
		rsApp.SetFieldByName(_T("Sample_Date"),CL3Variant((L3DATETIME)COleDateTime::GetCurrentTime()));
		//试样地点
		rsApp.SetFieldByName(_T("Sample_Address"),CL3Variant(_T("G")+cstrBFID));    
		//试样类别
		rsApp.SetFieldByName(_T("Sample_Type"),CL3Variant(_T("TS")));    

		/***********2009-10-27 begin yao**************/
		L3SHORT nSampleCount = 0;
		try
		{
			nSampleCount = _ttoi(cstrSampleCode.Right(1));
		}
		catch(...)
		{}
		CString csMaterialID = cstrTapNo.Trim() + cstrTPCNo.Trim();
		CString strDeSURI = CL3NameParser::MergeClassDomainName(CDES_BASE_URI,csMaterialID);
		if (iMode == 1)
		{
			if (!SetObjectPropValue(strDeSURI,_T("SampleApplyCount_B"),CL3Variant((L3SHORT)nSampleCount)))
			{
				if(nTrans > 0)
					Rollback(nTrans);
				return FALSE;
			}
		}
		else if(iMode == 2)
		{
			if (!SetObjectPropValue(strDeSURI,_T("SampleApplyCount_A"),CL3Variant((L3SHORT)nSampleCount)))
			{
				if(nTrans > 0)
					Rollback(nTrans);
				return FALSE;
			}
		}
		/************2009-10-27 end **************/

		rs.MoveNext();
	}

	int rscount = rsApp.GetRowCount();
	if (rscount < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	rsApp.MoveFirst();
	LONG nRet = CreateNewObjects(QA_LAB_SHEET_APP_CLASS_URI,rsApp);
	if(nRet < rsApp.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}

	//2009-04-07 Begin
	if (!SendSheetDataToAnaL2(rsApp))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -5;
	}
	//2009-04-07 End

	if(bUseTrans)
		Commit(nTrans);

	return rs.GetRowCount();
}

/// <Method class="CQA_HeatChemicalData_Mag" name="CalIronSampleCode" type="CString">
/// 计算脱硫铁水试样编码
/// <Param name="csTAPNo" type="LPCTSTR"> 铁次号
/// <Param name="iMode" type="LPCTSTR"> 脱硫前后标识
/// </Method>
CString  CQA_HeatChemicalData_Mag::CalDesIronSampleCode(LPCTSTR csTAPNo,LPCTSTR csTPCNo,L3SHORT iMode)
{
    CString cstrTPCNo = csTPCNo;
    CString cstrTAPNo = csTAPNo;
	int iTpcNo = _ttoi(cstrTPCNo);   
	cstrTPCNo.Format(_T("%02d"),iTpcNo);

	CString cstrPos;
	if (iMode == 1)
		cstrPos = _T("Q");
	else
		cstrPos = _T("H");

	CString cstrSampleNo=cstrTAPNo + cstrTPCNo + _T("TS")+cstrPos;

	CL3RecordSetWrap rs;
    //从CQA_Lab_Sheet_App获取高炉样试样代码(去除取样次数)最大取样次数，如果为空取样次数为0
	CString csSQL;
	csSQL.Format(_T("select Max(Sample_Count) AS Sample_Count from %s where substr(Sample_Code,1,14) = '%s'"),QA_LAB_SHEET_APP_CLASS_URI,cstrSampleNo);
	if(!Query(csSQL,rs))
		return _T("");

	CString cstrSampleCount;
	if (rs.GetRowCount() > 0)
	{
		rs.MoveFirst();
		L3LONG nSampleCount = 0;
		if ((rs.GetFieldByIndex(0)).ToCString().GetLength() > 0)
			nSampleCount = rs.GetFieldByIndex(0).ToLong();
		cstrSampleCount.Format(_T("%01d"),++nSampleCount);
	}
	else
	{
		cstrSampleCount = _T("1");
	}

	return cstrSampleNo + cstrSampleCount;
}

/// <Method class="CQA_HeatChemicalData_Mag" name="SetDeSAnalysisData" type="L3BOOL">
/// 设置脱硫分析数据 009-10-25 yao
/// <Param name="SampleCode" type="LPCTSTR"> 试样编码号
/// <Param name="S" type="L3FLOAT"> 硫
/// <Param name="P" type="L3FLOAT"> 磷
/// </Method>
L3BOOL  CQA_HeatChemicalData_Mag::SetDeSAnalysisData(LPCTSTR SampleCode,L3FLOAT S,L3FLOAT P)
{
	CString csSampleCode = SampleCode; 
	if(csSampleCode.GetLength() != 15)
	{
		return FALSE;
	}

	CString csMode = csSampleCode.Mid(13,1);
	CString csMaterialID = csSampleCode.Left(11);

	CString csIronUri = _T("MES\\MaterialData\\CBFIron\\")+csMaterialID;
    L3LONG nDeSFlag = GetObjectPropValue(csIronUri,_T("DeSFlag")).ToLong();
	if(nDeSFlag != 1)
	{
		return FALSE;
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	if (csMode == _T("Q")) //前S
	{
		CL3RecordSetWrap rsDeS;
		CString csSQL;
		csSQL.Format(_T("select TreatNo,S_B,P_B from %s where MaterialID = '%s'"),CDES_PROCESS_URI,csMaterialID);
		if(!Query(csSQL,rsDeS))
		{
			if(bUseTrans) 
				Rollback(nTrans);
			return FALSE;
		}

		if (rsDeS.GetRowCount() > 0)
		{
			rsDeS.MoveFirst();
			while(!rsDeS.IsEOF())
			{
				rsDeS.SetFieldByName(_T("S_B"),(L3FLOAT)S);
				rsDeS.SetFieldByName(_T("P_B"),(L3FLOAT)P);
				rsDeS.MoveNext();
			}
			rsDeS.MoveFirst();
			CString csTreatNo = rsDeS.GetFieldByName(_T("TreatNo")).ToCString();

			if (!SetObjsPropValues(CDES_PROCESS_URI,rsDeS))
			{
				if(bUseTrans)
					Rollback(nTrans);
				return FALSE;
			}
			if(csTreatNo.Left(1) == _T("1"))
			{
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Prod_Area\\S02A"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Prod_Area\\S02B"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
			}
			else if(csTreatNo.Left(1) == _T("2"))
			{
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Prod_Area\\S03A"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Prod_Area\\S03B"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
			}
		}
	}
    else if(csMode == _T("H")) //后S
	{
		CL3RecordSetWrap rsDeS;
		CString csSQL;
		csSQL.Format(_T("select TreatNo,S_A,P_A from %s where MaterialID = '%s'order by BlowBeginTime desc"),CDES_PROCESS_URI,csMaterialID);
		if(!Query(csSQL,rsDeS))
		{
			if(bUseTrans) 
				Rollback(nTrans);
			return FALSE;
		}

		if (rsDeS.GetRowCount() > 0)
		{
			rsDeS.MoveFirst();
 			CString csTreatNo = rsDeS.GetFieldByName(_T("TreatNo")).ToCString();
     		CString strDeSURI = CL3NameParser::MergeClassDomainName(CDES_PROCESS_URI,csTreatNo);

			if (!SetObjectPropValue(strDeSURI,_T("S_A"),(L3FLOAT)S))
			{
				if(bUseTrans) 
					Rollback(nTrans);
				return FALSE;
			}

			if (!SetObjectPropValue(strDeSURI,_T("P_A"),(L3FLOAT)P))
			{
				if(bUseTrans) 
					Rollback(nTrans);
				return FALSE;
			}

			if(csTreatNo.Left(1) == _T("1"))
			{
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag\\S02"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
			}
			else if(csTreatNo.Left(1) == _T("2"))
			{
				if (!SetObjectPropValue(_T("XGMESLogic\\DeSMag\\CDeS_Unit_Mag\\S03"),_T("S"),(L3FLOAT)S))
				{
					if(bUseTrans) 
						Rollback(nTrans);
					return FALSE;
				}
			}
		}
    }

	if(bUseTrans)
		Commit(nTrans);

	return TRUE;
}
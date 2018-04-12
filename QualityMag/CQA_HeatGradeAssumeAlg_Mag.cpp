// 逻辑类CQA_HeatGradeAssumeAlg_Mag的用户逻辑程序源文件
// 用户系统的逻辑程序应放在本文件中实现，逻辑函数的定义应放在_CQA_HeatGradeAssumeAlg_Mag.h中。
// 由于本文件中定义的函数均为L3集成开发环境自动生成，且在_CQA_HeatGradeAssumeAlg_Mag.h和
// 中插入了相关的代码，因此请不要删除或修改本文件中的函数定义。用户系统程序员应当只修改函数的具体
// 实现代码。如要添加、删除或修改逻辑函数的定义，请使用集成开发环境完成。

#include "StdAfx.h"
#include "_CQA_HeatGradeAssumeAlg_Mag.h"

//当对象被装载到系统中时，被调用
void CQA_HeatGradeAssumeAlg_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: 在此处添加对象装载时的处理代码
}

//当对象被卸载时，被调用
void CQA_HeatGradeAssumeAlg_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: 在此处添加对象卸载时的处理代码
}


/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="EstimateHeatGrade" type="">
/// 炉次品质判定
/// <Param name="nUnitTypeID" type="L3SHORT">工序标识</Param>
/// <Param name="nUnitID" type="L3SHORT">工位</Param>
/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
/// <Param name="nProcessCount" type="L3SHORT">工序位处理次数</Param>
/// </Method>
L3LONG CQA_HeatGradeAssumeAlg_Mag::EstimateHeatGrade(L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strHeatID, L3SHORT nProcessCount)
{
	CString cstrHeatID = strHeatID;
    // 获取炉次当前预定炉号、炼钢记号
	CString cstrPresetHeatID = (GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID,_T("PreHeatID"))).ToCString();
	CString cstrSteelGradeIndex = (GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID,_T("Pre_SteelGradeIndex"))).ToCString();
	//查询炉次当前炼钢记号对应的异常处理钢组
	CString cstrGradeGroupCode = (GetObjectPropValue(_T("XGMESLogic\\QualityMag\\CQA_SteelGradeIndex_R\\")+cstrSteelGradeIndex, _T("Grade_Group_Code"))).ToCString();
	L3STRING strGradeGroupCode = cstrGradeGroupCode.AllocSysString();
  //查询炉次工艺异常代码对应的处置代码和优先级
	VARIANT valParams[4];
	valParams[0].vt = VT_I2; valParams[0].iVal = nUnitTypeID;
	valParams[1].vt = VT_BSTR; valParams[1].bstrVal = strHeatID;
	valParams[2].vt = VT_I2; valParams[2].iVal = nProcessCount;
	valParams[3].vt = VT_BSTR; valParams[3].bstrVal = strGradeGroupCode;
	CL3RecordSetWrap rsHeatAbnormal;
	CString cstrSQL;
	cstrSQL = _T("Select A.ID_Object,A.Exceptional_Code,B.Classify,C.Decide_Code ");
	cstrSQL+= _T("From XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except A,");
	cstrSQL+= _T("     XGMESLogic\\QualityMag\\CQA_Decide_Code B,");
	cstrSQL+= _T("     XGMESLogic\\QualityMag\\CQA_Heat_Except_Code_R C ");
	cstrSQL+= _T("Where A.UnitTypeID = ? ");
	cstrSQL+= _T("And A.HeatID = ? ");
	cstrSQL+= _T("And A.Process_Count = ? ");
	cstrSQL+= _T("And C.Exceptional_Group_Code = ? ");
	cstrSQL+= _T("And B.Decide_Code=C.Decide_Code ");
	cstrSQL+= _T("And A.Exceptional_Code=C.Exceptional_Code ");
	if (QueryWithParam(cstrSQL,valParams, 4, rsHeatAbnormal))
	{
		//修改CQA_HeatGradeData（炉次工艺异常实体类）中工序炉次异常对应的处置代码和优先级
		int iRowCount = rsHeatAbnormal.GetRowCount();
		if (iRowCount == 0 )	
		{			
		  //修改计划时，无工艺异常的情况下触发，确保连铸判钢时计划信息刷新
			//CString strUnitTypeID;
			//strUnitTypeID.Format(_T("%d"),nUnitTypeID);
			//CString strProcessCount; 
			//strProcessCount.Format(_T("%d"),nProcessCount);
			//CString cstrUnitID;
			//cstrUnitID.Format(_T("%d"),nUnitID);
			//CString strID_Object1 = CString(strHeatID)+_T("S")+strUnitTypeID+cstrUnitID+strProcessCount;//生成对象标识
			//CString URIHeatGradeQAData = _T("XGMESLogic\\QualityMag\\CQA_HeatGradeData\\") + strID_Object1;//获取CHeatGradeQAData对象URI
			////修改CQA_HeatGradeData(炉次品质信息实体类）中预定炉号、炼钢记号
			//SetObjectPropValue(URIHeatGradeQAData,_T("PreHeatID"),CL3Variant(cstrPresetHeatID));
			//SetObjectPropValue(URIHeatGradeQAData,_T("SteelGradeIndex"),CL3Variant(cstrSteelGradeIndex));
    		L3SysFreeString(strGradeGroupCode);	//释放	
			return 9;
		}
		//设置炉次异常中的处置代码、优先级
		rsHeatAbnormal.MoveFirst();
		for (int i=0; i<iRowCount; i++)
		{
			CL3Variant valID_Object = rsHeatAbnormal.GetFieldByName(_T("ID_Object"));//获取对象标识
			CString strID_Object = valID_Object.ToCString();
			CL3Variant valDecideCodeTemp = rsHeatAbnormal.GetFieldByName(_T("Decide_Code"));//获取处置代码
			CString strDecideCodeTemp = valDecideCodeTemp.ToCString();
			CL3Variant valExceptionalClassifyTemp = rsHeatAbnormal.GetFieldByName(_T("Classify"));//获取优先级
			L3SHORT nExceptionalClassifyTemp = valExceptionalClassifyTemp.ToShort();			
			CString URIHeatProcessAbnormalData = _T("XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except\\") + strID_Object;//获取对象URI
			//修改对象属性
			SetObjectPropValue(URIHeatProcessAbnormalData,_T("Classify"),(L3SHORT)nExceptionalClassifyTemp);
			SetObjectPropValue(URIHeatProcessAbnormalData,_T("Decide_Code"),CL3Variant(strDecideCodeTemp));
			rsHeatAbnormal.MoveNext();
		}
	}	
	
	L3SysFreeString(strGradeGroupCode);	//释放	
	
	//查询炉次工艺异常记录集，取第一条记录与HeatID中该熔炼号对象比较，取优先级高的生成炉次等级
	VARIANT valParams1[3];
	valParams1[0].vt = VT_I2; valParams1[0].iVal = nUnitTypeID;
	valParams1[1].vt = VT_BSTR; valParams1[1].bstrVal = strHeatID;
	valParams1[2].vt = VT_I2; valParams1[2].iVal = nProcessCount;
	CL3RecordSetWrap rsHeatAbnormal1;
	cstrSQL = _T("Select ID_Object,Exceptional_Code,Classify,Decide_Code ");
	cstrSQL+= _T("From XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except ");
	cstrSQL+= _T("Where UnitTypeID = ? ");
	cstrSQL+= _T("And HeatID = ? ");
	cstrSQL+= _T("And Process_Count = ? ");
	cstrSQL+= _T("Order by Classify ");
	if (QueryWithParam(cstrSQL,valParams1, 3, rsHeatAbnormal1))
	{
        int iRowCount1 = rsHeatAbnormal1.GetRowCount();
		if (iRowCount1 == 0 )		return 9;
		rsHeatAbnormal1.MoveFirst();
		CL3Variant valExceptionalCode = rsHeatAbnormal1.GetFieldByName(_T("Exceptional_Code"));//获取异常代码
		CString strExceptionalCode = valExceptionalCode.ToCString();
		CL3Variant valExceptionalClassify = rsHeatAbnormal1.GetFieldByName(_T("Classify"));//获取优先级
		L3LONG nExceptionalClassify = valExceptionalClassify.ToLong();
		CL3Variant valDecideCode = rsHeatAbnormal1.GetFieldByName(_T("Decide_Code"));//获取处置代码
		CString strDecideCode = valDecideCode.ToCString();
  
		//查询炉次当前异常代码、处置代码、优先级	
		CL3Variant valExceptionalCode1 = GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID, _T("Exceptional_Code"));
		CString strExceptionalCode1 = valExceptionalCode1.ToCString();
		CL3Variant valExceptionalClassify1 = GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID, _T("Classify"));
		L3LONG nExceptionalClassify1 = valExceptionalClassify1.ToLong();
		CL3Variant valDecideCode1 = GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID, _T("Decide_Code"));
		CString strDecideCode1 = valDecideCode1.ToCString();
		CString strExceptionalCodeNew,strDecideCodeNew;
        L3LONG nExceptionalClassifyNew; 		
		if ((nExceptionalClassify <= nExceptionalClassify1)||(nExceptionalClassify1==0))
		{
			strExceptionalCodeNew = strExceptionalCode;
			strDecideCodeNew = strDecideCode;
			nExceptionalClassifyNew = nExceptionalClassify;
		}
		else
		{
			strExceptionalCodeNew = strExceptionalCode1;
			strDecideCodeNew = strDecideCode1;
			nExceptionalClassifyNew = nExceptionalClassify1;
		}
		CString strHeatGrade = strDecideCodeNew + strExceptionalCodeNew;//生成炉次等级
		CString strUnitTypeID;
		strUnitTypeID.Format(_T("%d"),nUnitTypeID);
        CString strProcessCount; 
	    strProcessCount.Format(_T("%d"),nProcessCount);
		CString cstrUnitID; 
    	cstrUnitID.Format(_T("%d"),nUnitID);
	    strUnitTypeID = _T("S")+strUnitTypeID;

		CString strID_Object1 = cstrHeatID + strUnitTypeID + cstrUnitID + strProcessCount;//生成对象标识

		CString URIHeatGradeQAData = _T("XGMESLogic\\QualityMag\\CQA_HeatGradeData");//获取CQA_HeatGradeData
		CString URIHeatGradeQAData1 = _T("XGMESLogic\\QualityMag\\CQA_HeatGradeData\\") + strID_Object1;//获取CQA_HeatGradeData对象URI

		//定义一个记录集变量
		CStringArray FieldNames; FieldNames.SetSize(11);
		CUIntArray FieldTypes; FieldTypes.SetSize(11);
		FieldNames[0] = _T("ID_Object");
		FieldNames[1] = _T("UnitTypeID");
		FieldNames[2] = _T("UnitID");
		FieldNames[3] = _T("HeatID");
		FieldNames[4] = _T("PreHeatID");
		FieldNames[5] = _T("SteelGradeIndex");
		FieldNames[6] = _T("ProcessCount");
		FieldNames[7] = _T("Exceptional_Code");
		FieldNames[8] = _T("Decide_Code");
		FieldNames[9] = _T("HeatGrade");
		FieldNames[10] = _T("DataLogMode");
		FieldTypes[0] = L3VT_STRING;
		FieldTypes[1] = L3VT_LONG;
		FieldTypes[2] = L3VT_LONG;
		FieldTypes[3] = L3VT_STRING;
		FieldTypes[4] = L3VT_STRING;
		FieldTypes[5] = L3VT_STRING;
		FieldTypes[6] = L3VT_LONG;
		FieldTypes[7] = L3VT_STRING;
		FieldTypes[8] = L3VT_STRING;
		FieldTypes[9] = L3VT_STRING;
		FieldTypes[10] = L3VT_LONG;
		CL3RecordSetWrap pRs;
 		if(!CreateRecordSet(FieldNames,FieldTypes,pRs) || pRs.IsNull())
			return -9;
		pRs.AppendRecord();
		pRs.SetFieldByName(_T("ID_Object"),       CL3Variant(strID_Object1));
		pRs.SetFieldByName(_T("UnitTypeID"),     (L3SHORT)nUnitTypeID);
		pRs.SetFieldByName(_T("UnitID"),         (L3SHORT)nUnitID);
		pRs.SetFieldByName(_T("HeatID"),         strHeatID);
		pRs.SetFieldByName(_T("PreHeatID"),   CL3Variant(cstrPresetHeatID));
		pRs.SetFieldByName(_T("SteelGradeIndex"),CL3Variant(cstrSteelGradeIndex));
		pRs.SetFieldByName(_T("ProcessCount"),   (L3SHORT)nProcessCount);
		pRs.SetFieldByName(_T("Exceptional_Code"),CL3Variant(strExceptionalCodeNew));
		pRs.SetFieldByName(_T("Decide_Code"),     CL3Variant(strDecideCodeNew));
		pRs.SetFieldByName(_T("HeatGrade"),      CL3Variant(strHeatGrade));
		pRs.SetFieldByName(_T("DataLogMode"),    (L3SHORT)0);//设置对象CHeatGradeQAData 属性DataLogMode=0
		//修改CQA_HeatGradeData(炉次品质信息实体类）中工序炉次等级
		if (CreateNewObjects(URIHeatGradeQAData, pRs) < 1)
  	    {
	    	SetObjPropValues(URIHeatGradeQAData1,pRs);//修改指定对象的属性值
	    }

		//定义一个记录集变量
		CStringArray FieldNames1; FieldNames1.SetSize(4);
		CUIntArray FieldTypes1; FieldTypes1.SetSize(4);
		FieldNames1[0] = _T("Classify");
		FieldNames1[1] = _T("Exceptional_Code");
		FieldNames1[2] = _T("Decide_Code");
		FieldNames1[3] = _T("HeatGrade");
		FieldTypes1[0] = L3VT_STRING;
		FieldTypes1[1] = L3VT_STRING;
		FieldTypes1[2] = L3VT_STRING;
		FieldTypes1[3] = L3VT_STRING;
		CL3RecordSetWrap pRs1;
 		if(!CreateRecordSet(FieldNames1,FieldTypes1,pRs1) || pRs.IsNull())
			return -9;
		pRs1.AppendRecord();
		CString cstrClassify;
		cstrClassify.Format(_T("%d"),nExceptionalClassifyNew);
		pRs1.SetFieldByName(_T("Classify"),CL3Variant(cstrClassify));
		pRs1.SetFieldByName(_T("Exceptional_Code"),CL3Variant(strExceptionalCodeNew));
		pRs1.SetFieldByName(_T("Decide_Code"),     CL3Variant(strDecideCodeNew));
		pRs1.SetFieldByName(_T("HeatGrade"),      CL3Variant(strHeatGrade));
  	    //修改CHeatID(炉次信息实体类）中工序炉次等级
        CString URIHeatID = MATERIAL_STEEL_URI+_T("\\")+cstrHeatID;//获取CHeatID对象URI
		SetObjPropValues(URIHeatID,pRs1);//修改指定对象的属性值

		//修改对象CHeatGradeAssumeMag属性NewHeatAbnormalEvent=NewHeatAbnormalEvent +1
		CString strURI = _T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssume_Mag\\QA_HeatGradeAssume_Mag");//获取对象URI
		CL3Variant val = GetObjectPropValue(strURI, _T("NewHeatAbnormalEvent"));		
		int NewHeatAbnormalEvent = val.ToShort();
		int NewHeatAbnormalEvent1 = (NewHeatAbnormalEvent % 9999) + 1;
		if (!SetObjectPropValue(strURI,_T("NewHeatAbnormalEvent"),(L3SHORT)NewHeatAbnormalEvent1)) return 9;//修改指定对象的属性值	
	}

	//调用炉次等级判定算法类方法
	if (nUnitTypeID == 4) 
    {
		CL3Variant valReturn = InvokeObjectMethod(_T("\\L3\\AppLogic\\CHeatGradeAssumeAlg\\HeatGradeAssumeAlg"), _T("EstimateDecideHeatGrade"), (L3SHORT)nUnitTypeID,(L3SHORT)nUnitID,strHeatID,(L3SHORT)nProcessCount);	
		if (valReturn.IsError())  return 9;
	}
	return 1;
}


/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="EstimateHeatChemical" type="L3SHORT">
/// 比对炉次成份
/// <Param name="nUnitTypeID" type="L3SHORT">工序</Param>
/// <Param name="nUnitID" type="L3SHORT">工位</Param>
/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
/// <Param name="nProcessCount" type="L3SHORT">重处理次数</Param>
/// <Param name="rsChemicalData" type="L3RECORDSET">成份数据</Param>
/// </Method>
L3LONG CQA_HeatGradeAssumeAlg_Mag::EstimateHeatChemical(L3SHORT nUnitTypeID,
														 L3SHORT nUnitID,
														 L3STRING strHeatID,
														 L3SHORT nProcessCount,
														 L3RECORDSET rsChemicalData)
{
	CString cstrHeatID = strHeatID;
	CL3RecordSetWrap pRs = rsChemicalData;
	if(pRs.GetRowCount() < 1)
		return 0;
  //查询炉次最新预定炼钢记号
	CL3RecordSetWrap rstemp;
	CString csSQL;
	csSQL.Format(_T("select Pre_SteelGradeIndex from %s where HeatID = '%s' "),MATERIAL_STEEL_URI,cstrHeatID);
	if(!Query(csSQL,rstemp))
    	return -1; 

	if (rstemp.GetRowCount()<1)
		return -1;

	rstemp.MoveFirst();
	CString csPresetSteelGradeIndex = (rstemp.GetFieldByName(_T("Pre_SteelGradeIndex"))).ToCString();
	if (csPresetSteelGradeIndex == _T("")) return -2;
	//判断该炼钢记号是否在标准中存在
	CString csSteelGradeIndex = (GetObjectPropValue(_T("XGMESLogic\\QualityMag\\CQA_Product_Sheet\\")+csPresetSteelGradeIndex,_T("SteelGradeIndex"))).ToCString();
	if (csSteelGradeIndex == _T("")) return -3;

	L3STRING strPresetSteelGradeIndex = csPresetSteelGradeIndex.AllocSysString();
  //获取接收记录集属性值
	pRs.MoveFirst();
	CL3Variant valC = pRs.GetFieldByName(_T("C"));			
	L3DOUBLE fC;
	if (valC.IsNull())
		fC  = -1; 
	else
		fC  = valC.ToFloat();
	CL3Variant valSi = pRs.GetFieldByName(_T("Si"));			
	L3DOUBLE fSi;
	if (valSi.IsNull())
		fSi  = -1; 
	else
		fSi  = valSi.ToFloat();
	CL3Variant valMn = pRs.GetFieldByName(_T("Mn"));			
	L3DOUBLE fMn;
	if (valMn.IsNull())
		fMn  = -1; 
	else
		fMn  = valMn.ToFloat();
	CL3Variant valP = pRs.GetFieldByName(_T("P"));			
	L3DOUBLE fP;
	if (valP.IsNull())
		fP  = -1; 
	else
		fP  = valP.ToFloat();
	CL3Variant valS = pRs.GetFieldByName(_T("S"));			
	L3DOUBLE fS;
	if (valS.IsNull())
		fS  = -1; 
	else
		fS  = valS.ToFloat();
	CL3Variant valCu = pRs.GetFieldByName(_T("Cu"));			
	L3DOUBLE fCu;
	if (valCu.IsNull())
		fCu  = -1; 
	else
		fCu  = valCu.ToFloat();
	CL3Variant valNi = pRs.GetFieldByName(_T("Ni"));			
	L3DOUBLE fNi;
	if (valNi.IsNull())
		fNi  = -1; 
	else
		fNi  = valNi.ToFloat();
	CL3Variant valCr = pRs.GetFieldByName(_T("Cr"));			
	L3DOUBLE fCr;
	if (valCr.IsNull())
		fCr  = -1; 
	else
		fCr  = valCr.ToFloat();
	CL3Variant valMo = pRs.GetFieldByName(_T("Mo"));			
	L3DOUBLE fMo;
	if (valMo.IsNull())
		fMo  = -1; 
	else
		fMo  = valMo.ToFloat();
	CL3Variant valV = pRs.GetFieldByName(_T("V"));			
	L3DOUBLE fV;
	if (valV.IsNull())
		fV  = -1; 
	else
		fV  = valV.ToFloat();
	CL3Variant valNb = pRs.GetFieldByName(_T("Nb"));			
	L3DOUBLE fNb;
	if (valNb.IsNull())
		fNb  = -1; 
	else
		fNb  = valNb.ToFloat();
	CL3Variant valAl = pRs.GetFieldByName(_T("Al"));			
	L3DOUBLE fAl;
	if (valAl.IsNull())
		fAl  = -1; 
	else
		fAl  = valAl.ToFloat();
	CL3Variant valAls = pRs.GetFieldByName(_T("Als"));			
	L3DOUBLE fAls;
	if (valAls.IsNull())
		fAls  = -1; 
	else
		fAls  = valAls.ToFloat();
  CL3Variant valTi = pRs.GetFieldByName(_T("Ti"));			
	L3DOUBLE fTi;
	if (valTi.IsNull())
		fTi  = -1; 
	else
		fTi  = valTi.ToFloat();
  CL3Variant valB = pRs.GetFieldByName(_T("B"));			
	L3DOUBLE fB;
	if (valB.IsNull())
		fB  = -1; 
	else
		fB  = valB.ToFloat();
  CL3Variant valSb = pRs.GetFieldByName(_T("Sb"));			
	L3DOUBLE fSb;
	if (valSb.IsNull())
		fSb  = -1; 
	else
		fSb  = valSb.ToFloat();
  CL3Variant valSn = pRs.GetFieldByName(_T("Sn"));			
	L3DOUBLE fSn;
	if (valSn.IsNull())
		fSn  = -1; 
	else
		fSn  = valSn.ToFloat();
  CL3Variant valAs = pRs.GetFieldByName(_T("As"));			
	L3DOUBLE fAs;
	if (valAs.IsNull())
		fAs  = -1; 
	else
		fAs  = valAs.ToFloat();
  CL3Variant valZn = pRs.GetFieldByName(_T("Zn"));			
	L3DOUBLE fZn;
	if (valZn.IsNull())
		fZn  = -1; 
	else
		fZn  = valZn.ToFloat();
  CL3Variant valZr = pRs.GetFieldByName(_T("Zr"));			
	L3DOUBLE fZr;
	if (valZr.IsNull())
		fZr  = -1; 
	else
		fZr  = valZr.ToFloat();
  CL3Variant valCa = pRs.GetFieldByName(_T("Ca"));			
	L3DOUBLE fCa;
	if (valCa.IsNull())
		fCa  = -1; 
	else
		fCa  = valCa.ToFloat();
  CL3Variant valW = pRs.GetFieldByName(_T("W"));			
	L3DOUBLE fW;
	if (valW.IsNull())
		fW  = -1; 
	else
		fW  = valW.ToFloat();
  CL3Variant valPb = pRs.GetFieldByName(_T("Pb"));			
	L3DOUBLE fPb;
	if (valPb.IsNull())
		fPb  = -1; 
	else
		fPb  = valPb.ToFloat();
  CL3Variant valRe = pRs.GetFieldByName(_T("Re"));			
	L3DOUBLE fRe;
	if (valRe.IsNull())
		fRe  = -1; 
	else
		fRe  = valRe.ToFloat();
  CL3Variant valCeq = pRs.GetFieldByName(_T("Ceq"));
	L3DOUBLE fCeq;
	if (valCeq.IsNull())
		fCeq = -1; 
	else
		fCeq = valCeq.ToFloat();
	CL3Variant valO = pRs.GetFieldByName(_T("O"));			
	L3DOUBLE fO;
	if (valO.IsNull())
		fO  = -1; 
	else
		fO  = valO.ToFloat();
  CL3Variant valN = pRs.GetFieldByName(_T("N"));			
	L3DOUBLE fN  ;
	if (valN.IsNull())
		fN  = -1; 
	else
		fN  = valN.ToFloat();
  CL3Variant valH = pRs.GetFieldByName(_T("H"));			
	L3DOUBLE fH;
	if (valH.IsNull())
		fH  = -1; 
	else
		fH  = valH.ToFloat();
  CL3Variant valOther1 = pRs.GetFieldByName(_T("Other1"));			
	L3DOUBLE fOther1;
	if (valOther1.IsNull())
		fOther1  = -1; 
	else
		fOther1  = valOther1.ToFloat();
  CL3Variant valOther2 = pRs.GetFieldByName(_T("Other2"));			
	L3DOUBLE fOther2;
	if (valOther2.IsNull())
		fOther2  = -1; 
	else
		fOther2  = valOther2.ToFloat();
  //设置参数
  //*************2005-11-16********增加浮点数精度控制*********//
	VARIANT valParams[91];
	valParams[0].vt = VT_R8; valParams[0].dblVal = fC+0.00001;
	valParams[1].vt = VT_R8; valParams[1].dblVal = fC-0.00001;
	valParams[2].vt = VT_R8; valParams[2].dblVal = fC;
	valParams[3].vt = VT_R8; valParams[3].dblVal = fSi+0.00001;
	valParams[4].vt = VT_R8; valParams[4].dblVal = fSi-0.00001;
	valParams[5].vt = VT_R8; valParams[5].dblVal = fSi;
	valParams[6].vt = VT_R8; valParams[6].dblVal = fMn+0.00001;
	valParams[7].vt = VT_R8; valParams[7].dblVal = fMn-0.00001;
	valParams[8].vt = VT_R8; valParams[8].dblVal = fMn;
	valParams[9].vt = VT_R8; valParams[9].dblVal = fP+0.00001;
	valParams[10].vt = VT_R8; valParams[10].dblVal = fP-0.00001;
	valParams[11].vt = VT_R8; valParams[11].dblVal = fP;
	valParams[12].vt = VT_R8; valParams[12].dblVal = fS+0.00001;
	valParams[13].vt = VT_R8; valParams[13].dblVal = fS-0.00001;
	valParams[14].vt = VT_R8; valParams[14].dblVal = fS;
	valParams[15].vt = VT_R8; valParams[15].dblVal = fCu+0.00001;
	valParams[16].vt = VT_R8; valParams[16].dblVal = fCu-0.00001;
	valParams[17].vt = VT_R8; valParams[17].dblVal = fCu;
	valParams[18].vt = VT_R8; valParams[18].dblVal = fNi+0.00001;
	valParams[19].vt = VT_R8; valParams[19].dblVal = fNi-0.00001;
	valParams[20].vt = VT_R8; valParams[20].dblVal = fNi;
	valParams[21].vt = VT_R8; valParams[21].dblVal = fCr+0.00001;
	valParams[22].vt = VT_R8; valParams[22].dblVal = fCr-0.00001;
	valParams[23].vt = VT_R8; valParams[23].dblVal = fCr;
	valParams[24].vt = VT_R8; valParams[24].dblVal = fMo+0.00001;
	valParams[25].vt = VT_R8; valParams[25].dblVal = fMo-0.00001;
	valParams[26].vt = VT_R8; valParams[26].dblVal = fMo;
	valParams[27].vt = VT_R8; valParams[27].dblVal = fV+0.00001;
	valParams[28].vt = VT_R8; valParams[28].dblVal = fV-0.00001;
	valParams[29].vt = VT_R8; valParams[29].dblVal = fV;
	valParams[30].vt = VT_R8; valParams[30].dblVal = fNb+0.00001;
	valParams[31].vt = VT_R8; valParams[31].dblVal = fNb-0.00001;
	valParams[32].vt = VT_R8; valParams[32].dblVal = fNb;
	valParams[33].vt = VT_R8; valParams[33].dblVal = fAl+0.00001;
	valParams[34].vt = VT_R8; valParams[34].dblVal = fAl-0.00001;
	valParams[35].vt = VT_R8; valParams[35].dblVal = fAl;
	valParams[36].vt = VT_R8; valParams[36].dblVal = fAls+0.00001;
	valParams[37].vt = VT_R8; valParams[37].dblVal = fAls-0.00001;
	valParams[38].vt = VT_R8; valParams[38].dblVal = fAls;
	valParams[39].vt = VT_R8; valParams[39].dblVal = fTi+0.00001;
	valParams[40].vt = VT_R8; valParams[40].dblVal = fTi-0.00001;
	valParams[41].vt = VT_R8; valParams[41].dblVal = fTi;
	valParams[42].vt = VT_R8; valParams[42].dblVal = fB+0.00001;
	valParams[43].vt = VT_R8; valParams[43].dblVal = fB-0.00001;
	valParams[44].vt = VT_R8; valParams[44].dblVal = fB;
	valParams[45].vt = VT_R8; valParams[45].dblVal = fSb+0.00001;
	valParams[46].vt = VT_R8; valParams[46].dblVal = fSb-0.00001;
	valParams[47].vt = VT_R8; valParams[47].dblVal = fSb;
	valParams[48].vt = VT_R8; valParams[48].dblVal = fSn+0.00001;
	valParams[49].vt = VT_R8; valParams[49].dblVal = fSn-0.00001;
	valParams[50].vt = VT_R8; valParams[50].dblVal = fSn;
	valParams[51].vt = VT_R8; valParams[51].dblVal = fAs+0.00001;
	valParams[52].vt = VT_R8; valParams[52].dblVal = fAs-0.00001;
	valParams[53].vt = VT_R8; valParams[53].dblVal = fAs;
	valParams[54].vt = VT_R8; valParams[54].dblVal = fZn+0.00001;
	valParams[55].vt = VT_R8; valParams[55].dblVal = fZn-0.00001;
	valParams[56].vt = VT_R8; valParams[56].dblVal = fZn;
	valParams[57].vt = VT_R8; valParams[57].dblVal = fZr+0.00001;
	valParams[58].vt = VT_R8; valParams[58].dblVal = fZr-0.00001;
	valParams[59].vt = VT_R8; valParams[59].dblVal = fZr;
	valParams[60].vt = VT_R8; valParams[60].dblVal = fCa+0.00001;
	valParams[61].vt = VT_R8; valParams[61].dblVal = fCa-0.00001;
	valParams[62].vt = VT_R8; valParams[62].dblVal = fCa;
	valParams[63].vt = VT_R8; valParams[63].dblVal = fW+0.00001;
	valParams[64].vt = VT_R8; valParams[64].dblVal = fW-0.00001;
	valParams[65].vt = VT_R8; valParams[65].dblVal = fW;
	valParams[66].vt = VT_R8; valParams[66].dblVal = fPb+0.00001;
	valParams[67].vt = VT_R8; valParams[67].dblVal = fPb-0.00001;
	valParams[68].vt = VT_R8; valParams[68].dblVal = fPb;
	valParams[69].vt = VT_R8; valParams[69].dblVal = fRe+0.00001;
	valParams[70].vt = VT_R8; valParams[70].dblVal = fRe-0.00001;
	valParams[71].vt = VT_R8; valParams[71].dblVal = fRe;
	valParams[72].vt = VT_R8; valParams[72].dblVal = fCeq+0.00001;
	valParams[73].vt = VT_R8; valParams[73].dblVal = fCeq-0.00001;
	valParams[74].vt = VT_R8; valParams[74].dblVal = fCeq;
	valParams[75].vt = VT_R8; valParams[75].dblVal = fO+0.00001;
	valParams[76].vt = VT_R8; valParams[76].dblVal = fO-0.00001;
	valParams[77].vt = VT_R8; valParams[77].dblVal = fO;
	valParams[78].vt = VT_R8; valParams[78].dblVal = fN+0.00001;
	valParams[79].vt = VT_R8; valParams[79].dblVal = fN-0.00001;
	valParams[80].vt = VT_R8; valParams[80].dblVal = fN;
	valParams[81].vt = VT_R8; valParams[81].dblVal = fH+0.00001;
	valParams[82].vt = VT_R8; valParams[82].dblVal = fH-0.00001;
	valParams[83].vt = VT_R8; valParams[83].dblVal = fH;
	valParams[84].vt = VT_R8; valParams[84].dblVal = fOther1+0.00001;
	valParams[85].vt = VT_R8; valParams[85].dblVal = fOther1-0.00001;
	valParams[86].vt = VT_R8; valParams[86].dblVal = fOther1;
	valParams[87].vt = VT_R8; valParams[87].dblVal = fOther2+0.00001;
	valParams[88].vt = VT_R8; valParams[88].dblVal = fOther2-0.00001;
	valParams[89].vt = VT_R8; valParams[89].dblVal = fOther2;
	valParams[90].vt = VT_BSTR; valParams[90].bstrVal = strPresetSteelGradeIndex;
  //***************************************************//

	//获取成份合格的记录
	CL3RecordSetWrap pRs1;
	CString csSeqStr = _T("Select A.SteelGradeIndex From XGMESLogic\\QualityMag\\CQA_Product_Sheet A Where ");
	CString csConditionSqlstr ;
    csConditionSqlstr = csConditionSqlstr +  
		                    _T("(A.C_Min <= ? and A.C_Max >= ? or A.C_Min = -1 and A.C_Max = -1 or ? = -1) and ") + _T("(A.Si_Min <= ? and A.Si_Max >= ?  or A.Si_Min = -1 and A.Si_Max = -1 or ?=-1) and ") +
	                        _T("(A.Mn_Min <= ? and A.Mn_Max >= ?  or A.Mn_Min = -1 and A.Mn_Max = -1 or ? = -1) and ") + _T("(A.P_Min <= ? and A.P_Max >= ?  or A.P_Min = -1 and A.P_Max = -1 or ? = -1) and ") +
                            _T("(A.S_Min <= ? and A.S_Max >= ?  or A.S_Min = -1 and A.S_Max = -1 or ? = -1) and ") + _T("(A.Cu_Min <= ? and A.Cu_Max >= ?  or A.Cu_Min = -1 and A.Cu_Max = -1 or ? = -1) and ") +
							_T("(A.Ni_Min <= ? and A.Ni_Max >= ?  or A.Ni_Min = -1 and A.Ni_Max = -1 or ? = -1) and ") + _T("(A.Cr_Min <= ? and A.Cr_Max >= ?  or A.Cr_Min = -1 and A.Cr_Max = -1 or ? = -1) and ") +
							_T("(A.Mo_Min <= ? and A.Mo_Max >= ?  or A.Mo_Min = -1 and A.Mo_Max = -1 or ? = -1) and ") + _T("(A.V_Min <= ? and A.V_Max >= ?  or A.V_Min = -1 and A.V_Max = -1 or ? = -1) and ") +
							_T("(A.Nb_Min <= ? and A.Nb_Max >= ?  or A.Nb_Min = -1 and A.Nb_Max = -1 or ? = -1) and ") + _T("(A.Al_Min <= ? and A.Al_Max >= ?  or A.Al_Min = -1 and A.Al_Max = -1 or ? = -1) and ") +
							_T("(A.Als_Min <= ? and A.Als_Max >= ?  or A.Als_Min = -1 and A.Als_Max = -1 or ? = -1) and ") + _T("(A.Ti_Min <= ? and A.Ti_Max >= ?  or A.Ti_Min = -1 and A.Ti_Max = -1 or ? = -1) and ") +
							_T("(A.B_Min <= ? and A.B_Max >= ?  or A.B_Min = -1 and A.B_Max = -1 or ? = -1) and ") + _T("(A.Sb_Min <= ? and A.Sb_Max >= ?  or A.Sb_Min = -1 and A.Sb_Max = -1 or ? = -1) and ") +
							_T("(A.Sn_Min <= ? and A.Sn_Max >= ?  or A.Sn_Min = -1 and A.Sn_Max = -1 or ? = -1) and ") + _T("(A.As_Min <= ? and A.As_Max >= ?  or A.As_Min = -1 and A.As_Max = -1 or ? = -1) and ") +
							_T("(A.Zn_Min <= ? and A.Zn_Max >= ?  or A.Zn_Min = -1 and A.Zn_Max = -1 or ? = -1) and ") + _T("(A.Zr_Min <= ? and A.Zr_Max >= ?  or A.Zr_Min = -1 and A.Zr_Max = -1 or ? = -1) and ") +															
							_T("(A.Ca_Min <= ? and A.Ca_Max >= ?  or A.Ca_Min = -1 and A.Ca_Max = -1 or ? = -1) and ") + _T("(A.W_Min <= ? and A.W_Max >= ?  or A.W_Min = -1 and A.W_Max = -1 or ? = -1) and ") +
							_T("(A.Pb_Min <= ? and A.Pb_Max >= ?  or A.Pb_Min = -1 and A.Pb_Max = -1 or ? = -1) and ") + _T("(A.Re_Min <= ? and A.Re_Max >= ?  or A.Re_Min = -1 and A.Re_Max = -1 or ? = -1) and ") +
							_T("(A.Ceq_Min <= ? and A.Ceq_Max >= ?  or A.Ceq_Min = -1 and A.Ceq_Max = -1 or ? = -1) and ") + _T("(A.O_Min <= ? and A.O_Max >= ?  or A.O_Min = -1 and A.O_Max = -1 or ? = -1) and ") +
							_T("(A.N_Min <= ? and A.N_Max >= ?  or A.N_Min = -1 and A.N_Max = -1 or ? = -1) and ") + _T("(A.H_Min <= ? and A.H_Max >= ?  or A.H_Min = -1 and A.H_Max = -1 or ? = -1) and ") +
							_T("(A.Other1_Min <= ? and A.Other1_Max >= ?  or A.Other1_Min = -1 and A.Other1_Max = -1 or ? = -1) and ") + _T("(A.Other2_Min <= ? and A.Other2_Max >= ?  or A.Other2_Min = -1 and A.Other2_Max = -1 or ? = -1) and ") +
							_T("A.SteelGradeIndex = ?");

    csSeqStr = csSeqStr + csConditionSqlstr;
	if (!QueryWithParam(csSeqStr, valParams, 91, pRs1))	
	{	
        L3SysFreeString(strPresetSteelGradeIndex);	
		return -4; 
	}
	int i = pRs1.GetRowCount();
	if (i == 0)//成份判定不合格
	{	
		COleDateTime dtTemp;
		dtTemp = COleDateTime::GetCurrentTime();
		L3DATETIME dt = dtTemp;
		//构造炉次成份异常记录集
		CString strURI = _T("XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except");//获取类URI
 		CL3RecordSetWrap RS;
		if(this ->CreateClassPropSet(strURI,RS))
		{
			RS.DeleteRecord();
			RS.AppendRecord();
			RS.MoveFirst();
			RS.SetFieldByName(_T("Exceptional_Code"),CL3Variant(CHEMICAL_EXCEPTIONAL_CODE));//设置异常代码 yaodingyin
			RS.SetFieldByName(_T("Exceptional_Time"),(L3DATETIME)dt);//设置异常时间
		}
	  //调用记录炉次工艺异常方法
	  CL3Variant valReturn = InvokeObjectMethod(_T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssume_Mag\\QA_HeatGradeAssume_Mag"),
		                                        _T("LogHeatExceptionData"),
												(L3SHORT)nUnitTypeID,
												(L3SHORT)nUnitID,
												strHeatID,
												(L3SHORT)nProcessCount,
												(L3RECORDSET)RS);	
		if (valReturn.IsError())  
		{		
			L3SysFreeString(strPresetSteelGradeIndex);	
			return -5;
		}
	}
	L3SysFreeString(strPresetSteelGradeIndex);	
	return 1;
}

/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="EstimateDecideHeatGrade" type="L3SHORT">
/// 综合各工序炉次等级，生成决定等级
/// <Param name="nUnitTypeID" type="L3SHORT">工序</Param>
/// <Param name="nUnitID" type="L3SHORT">工位</Param>
/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
/// <Param name="nProcessCount" type="L3SHORT">重处理次数</Param>
/// </Method>
L3LONG CQA_HeatGradeAssumeAlg_Mag::EstimateDecideHeatGrade(L3SHORT nUnitTypeID,L3SHORT nUnitID,L3STRING strHeatID,L3SHORT nProcessCount)
{ 
	CString cstrHeatID = strHeatID;
    // 获取炉次当前预定炉号、炼钢记号
	CString cstrPresetHeatID = (GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID,_T("PreHeatID"))).ToCString();
	CString cstrSteelGradeIndex = (GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID,_T("Pre_SteelGradeIndex"))).ToCString();
	//查询炉次当前炼钢记号对应的异常处理钢组
	CString cstrGradeGroupCode = (GetObjectPropValue(_T("XGMESLogic\\QualityMag\\CQA_SteelGradeIndex_R\\")+cstrSteelGradeIndex, _T("Grade_Group_Code"))).ToCString();
	L3STRING strGradeGroupCode = cstrGradeGroupCode.AllocSysString();

  //查询炉次工艺异常代码对应的处置代码和优先级
	VARIANT valParams[4];
	valParams[0].vt = VT_I2; valParams[0].iVal = nUnitTypeID;
	valParams[1].vt = VT_BSTR; valParams[1].bstrVal = strHeatID;
	valParams[2].vt = VT_I2; valParams[2].iVal = nProcessCount;
	valParams[3].vt = VT_BSTR; valParams[3].bstrVal = strGradeGroupCode;
	CL3RecordSetWrap rsHeatAbnormal;
	CString cstrSQL;
	cstrSQL = _T("Select A.ID_Object,A.Exceptional_Code,B.Classify,C.Decide_Code ");
	cstrSQL+= _T("From XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except A,");
	cstrSQL+= _T("     XGMESLogic\\QualityMag\\CQA_Decide_Code B,");
	cstrSQL+= _T("     XGMESLogic\\QualityMag\\CQA_Heat_Except_Code_R C ");
	cstrSQL+= _T("Where A.UnitTypeID = ? ");
	cstrSQL+= _T("And A.HeatID = ? ");
	cstrSQL+= _T("And A.Process_Count = ? ");
	cstrSQL+= _T("And C.Except_Group_Code = ? ");
	cstrSQL+= _T("And B.Decide_Code=C.Decide_Code ");
	cstrSQL+= _T("And A.Exceptional_Code=C.Exceptional_Code ");
	if (QueryWithParam(cstrSQL,valParams, 4, rsHeatAbnormal))
	{
		//修改CHeatProcessAbnormalData（炉次工艺异常实体类）中工序炉次异常对应的处置代码和优先级
		int iRowCount = rsHeatAbnormal.GetRowCount();
		if (iRowCount == 0 )	
		{
			L3SysFreeString(strGradeGroupCode);	//释放	
			return 9;
		}
		rsHeatAbnormal.MoveFirst();
		for (int i=0; i<iRowCount; i++)
		{
			CL3Variant valID_Object = rsHeatAbnormal.GetFieldByName(_T("ID_Object"));//获取对象标识
			CString strID_Object = valID_Object.ToCString();
			CL3Variant valDecideCodeTemp = rsHeatAbnormal.GetFieldByName(_T("Decide_Code"));//获取处置代码
			CString strDecideCodeTemp = valDecideCodeTemp.ToCString();
			CL3Variant valExceptionalClassifyTemp = rsHeatAbnormal.GetFieldByName(_T("Classify"));//获取优先级
			L3SHORT nExceptionalClassifyTemp = valExceptionalClassifyTemp.ToShort();			
			CString URIHeatProcessAbnormalData = _T("XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except\\") + strID_Object;//获取对象URI
			//修改对象属性
			SetObjectPropValue(URIHeatProcessAbnormalData,_T("Classify"),(L3SHORT)nExceptionalClassifyTemp);
			SetObjectPropValue(URIHeatProcessAbnormalData,_T("Decide_Code"),CL3Variant(strDecideCodeTemp));
			rsHeatAbnormal.MoveNext();
		}
	}	
	
	L3SysFreeString(strGradeGroupCode);	//释放	
	
	//查询炉次工艺异常记录集，取第一条记录与HeatID中该熔炼号对象比较，取优先级高的生成炉次等级
	VARIANT valParams1[3];
	valParams1[0].vt = VT_I2; valParams1[0].iVal = nUnitTypeID;
	valParams1[1].vt = VT_BSTR; valParams1[1].bstrVal = strHeatID;
	valParams1[2].vt = VT_I2; valParams1[2].iVal = nProcessCount;
	CL3RecordSetWrap rsHeatAbnormal1;

	cstrSQL = _T("Select ID_Object,Exceptional_Code,Classify,Decide_Code ");
	cstrSQL+= _T("From XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except ");
	cstrSQL+= _T("Where A.UnitTypeID = ? ");
	cstrSQL+= _T("And A.HeatID = ? ");
	cstrSQL+= _T("And A.Process_Count = ? ");
	cstrSQL+= _T("Order by Classify ");
	if (QueryWithParam(cstrSQL,valParams1, 3, rsHeatAbnormal1))
	{
    int iRowCount1 = rsHeatAbnormal1.GetRowCount();
		if (iRowCount1 == 0 )		return 9;
		rsHeatAbnormal1.MoveFirst();
		CL3Variant valExceptionalCode = rsHeatAbnormal1.GetFieldByName(_T("Exceptional_Code"));//获取异常代码
		CString strExceptionalCode = valExceptionalCode.ToCString();
		CL3Variant valExceptionalClassify = rsHeatAbnormal1.GetFieldByName(_T("Classify"));//获取优先级
		L3SHORT nExceptionalClassify = valExceptionalClassify.ToShort();
		CL3Variant valDecideCode = rsHeatAbnormal1.GetFieldByName(_T("Decide_Code"));//获取处置代码
		CString strDecideCode = valDecideCode.ToCString();
  
		//查询炉次当前异常代码、处置代码、优先级	
		CL3Variant valExceptionalCode1 = GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID, _T("Exceptional_Code"));
		CString strExceptionalCode1 = valExceptionalCode1.ToCString();
		CL3Variant valExceptionalClassify1 = GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID, _T("Classify"));
		L3SHORT nExceptionalClassify1 = valExceptionalClassify1.ToShort();
		CL3Variant valDecideCode1 = GetObjectPropValue(MATERIAL_STEEL_URI+_T("\\")+cstrHeatID, _T("Decide_Code"));
		CString strDecideCode1 = valDecideCode1.ToCString();
		CString strExceptionalCodeNew,strDecideCodeNew;
        L3SHORT nExceptionalClassifyNew; 		
		if (nExceptionalClassify <= nExceptionalClassify1)
		{
			strExceptionalCodeNew = strExceptionalCode;
			strDecideCodeNew = strDecideCode;
			nExceptionalClassifyNew = nExceptionalClassify;
		}
		else
		{
			strExceptionalCodeNew = strExceptionalCode1;
			strDecideCodeNew = strDecideCode1;
			nExceptionalClassifyNew = nExceptionalClassify1;
		}
		CString strHeatGrade = strDecideCodeNew + strExceptionalCodeNew;//生成炉次等级
		CString strUnitTypeID;
		strUnitTypeID.Format(_T("%d"),nUnitTypeID);
        CString strProcessCount; 
	    strProcessCount.Format(_T("%d"),nProcessCount);
		CString strID_Object1 = cstrHeatID+strProcessCount+strUnitTypeID;//生成对象标识
		CString URIHeatGradeQAData = _T("XGMESLogic\\QualityMag\\CQA_HeatGradeData");//获取CQA_HeatGradeData
		CString URIHeatGradeQAData1 = _T("XGMESLogic\\QualityMag\\CQA_HeatGradeData\\") + strID_Object1;//获取CQA_HeatGradeData对象URI

		//定义一个记录集变量
		CStringArray FieldNames; FieldNames.SetSize(11);
		CUIntArray FieldTypes; FieldTypes.SetSize(11);
		FieldNames[0] = _T("ID_Object");
		FieldNames[1] = _T("UnitTypeID");
		FieldNames[2] = _T("UnitID");
		FieldNames[3] = _T("HeatID");
		FieldNames[4] = _T("PreHeatID");
		FieldNames[5] = _T("SteelGradeIndex");
		FieldNames[6] = _T("ProcessCount");
		FieldNames[7] = _T("Exceptional_Code");
		FieldNames[8] = _T("Decide_Code");
		FieldNames[9] = _T("HeatGrade");
		FieldNames[10] = _T("DataLogMode");
		FieldTypes[0] = L3VT_STRING;
		FieldTypes[1] = L3VT_SHORT;
		FieldTypes[2] = L3VT_SHORT;
		FieldTypes[3] = L3VT_STRING;
		FieldTypes[4] = L3VT_STRING;
		FieldTypes[5] = L3VT_STRING;
		FieldTypes[6] = L3VT_SHORT;
		FieldTypes[7] = L3VT_STRING;
		FieldTypes[8] = L3VT_STRING;
		FieldTypes[9] = L3VT_STRING;
		FieldTypes[10] = L3VT_SHORT;
		CL3RecordSetWrap pRs;
 		if(!CreateRecordSet(FieldNames,FieldTypes,pRs) || pRs.IsNull())
			return -9;
		pRs.AppendRecord();
		pRs.SetFieldByName(_T("ID_Object"),       CL3Variant(strID_Object1));
		pRs.SetFieldByName(_T("UnitTypeID"),     (L3SHORT)nUnitTypeID);
		pRs.SetFieldByName(_T("UnitID"),         (L3SHORT)nUnitID);
		pRs.SetFieldByName(_T("HeatID"),         strHeatID);
		pRs.SetFieldByName(_T("PreHeatID"),   CL3Variant(cstrPresetHeatID));
		pRs.SetFieldByName(_T("SteelGradeIndex"),CL3Variant(cstrSteelGradeIndex));
		pRs.SetFieldByName(_T("ProcessCount"),   (L3SHORT)nProcessCount);
		pRs.SetFieldByName(_T("Exceptional_Code"),CL3Variant(strExceptionalCodeNew));
		pRs.SetFieldByName(_T("Decide_Code"),     CL3Variant(strDecideCodeNew));
		pRs.SetFieldByName(_T("HeatGrade"),      CL3Variant(strHeatGrade));
		pRs.SetFieldByName(_T("DataLogMode"),    (L3SHORT)0);//设置对象CHeatGradeQAData 属性DataLogMode=0
		//修改CHeatGradeQAData(炉次品质信息实体类）中工序炉次等级
		if (CreateNewObjects(URIHeatGradeQAData, pRs) < 1)
  	    {
	    	SetObjPropValues(URIHeatGradeQAData1,pRs);//修改指定对象的属性值
	    }

		//定义一个记录集变量
		CStringArray FieldNames1; FieldNames1.SetSize(4);
		CUIntArray FieldTypes1; FieldTypes1.SetSize(4);
		FieldNames1[0] = _T("Classify");
		FieldNames1[1] = _T("Exceptional_Code");
		FieldNames1[2] = _T("Decide_Code");
		FieldNames1[3] = _T("HeatGrade");
		FieldTypes1[0] = L3VT_STRING;
		FieldTypes1[1] = L3VT_SHORT;
		FieldTypes1[2] = L3VT_SHORT;
		FieldTypes1[3] = L3VT_STRING;
		CL3RecordSetWrap pRs1;
 		if(!CreateRecordSet(FieldNames1,FieldTypes1,pRs1) || pRs.IsNull())
			return -9;
		pRs1.AppendRecord();
		pRs1.SetFieldByName(_T("Classify"),(L3SHORT)nExceptionalClassifyNew);
		pRs1.SetFieldByName(_T("Exceptional_Code"),CL3Variant(strExceptionalCodeNew));
		pRs1.SetFieldByName(_T("Decide_Code"),     CL3Variant(strDecideCodeNew));
		pRs1.SetFieldByName(_T("HeatGrade"),      CL3Variant(strHeatGrade));
  	    //修改CHeatID(炉次信息实体类）中工序炉次等级
        CString URIHeatID = MATERIAL_STEEL_URI+_T("\\")+cstrHeatID;//获取CHeatID对象URI
		SetObjPropValues(URIHeatID,pRs1);//修改指定对象的属性值

		//修改对象CHeatGradeAssumeMag属性NewHeatAbnormalEvent=NewHeatAbnormalEvent +1
		CString strURI = _T("XGMESLogic\\QualityMag\\CQA_HeatGradeAssume_Mag\\QA_HeatGradeAssume_Mag");//获取对象URI
		CL3Variant val = GetObjectPropValue(strURI, _T("NewHeatAbnormalEvent"));		
		int NewHeatAbnormalEvent = val.ToShort();
		int NewHeatAbnormalEvent1 = (NewHeatAbnormalEvent % 9999) + 1;
		if (!SetObjectPropValue(strURI,_T("NewHeatAbnormalEvent"),(L3SHORT)NewHeatAbnormalEvent1)) return -9;//修改指定对象的属性值	
	}
	return 0;
}

/// <Method class="CQA_HeatGradeAssumeAlg_Mag" name="RecommendSteelGradeIndex" type="L3SHORT">
/// 推荐炼钢记号
/// <Param name="strHeatID" type="L3STRING">熔炼号</Param>
/// <Param name="*rsSteelGradeIndexData" type="L3RECORDSET">重处理次数</Param>
/// </Method>
L3LONG CQA_HeatGradeAssumeAlg_Mag::RecommendSteelGradeIndex(L3STRING strHeatID,L3RECORDSET *rsSteelGradeIndexData)
{ 
	CL3RecordSetWrap pRs;
	VARIANT valParams0[2];
	valParams0[0].vt = VT_BSTR; valParams0[0].bstrVal = strHeatID;
	valParams0[1].vt = VT_I2; valParams0[1].intVal = 4;
	if (!QueryWithParam(_T("Select * From XGMESLogic\\QualityMag\\CQA_Lab_Element Where HeatID = ? and UnitTypeID = ? order by LogTime desc"),valParams0, 2, pRs))	
		return -1; 

	/*****************************/
	//获取pRs中属性值
	if (pRs.IsNull()) return -1;
	int iElementCount = pRs.GetFieldCount();
	pRs.MoveFirst();
	CL3Variant valC = pRs.GetFieldByName(_T("C"));			
	L3DOUBLE fC;
	if (valC.IsNull())
		fC  = -1; 
	else
		fC  = valC.ToFloat();
	CL3Variant valSi = pRs.GetFieldByName(_T("Si"));			
	L3DOUBLE fSi;
	if (valSi.IsNull())
		fSi  = -1; 
	else
		fSi  = valSi.ToFloat();
	CL3Variant valMn = pRs.GetFieldByName(_T("Mn"));			
	L3DOUBLE fMn;
	if (valMn.IsNull())
		fMn  = -1; 
	else
		fMn  = valMn.ToFloat();
	CL3Variant valP = pRs.GetFieldByName(_T("P"));			
	L3DOUBLE fP;
	if (valP.IsNull())
		fP  = -1; 
	else
		fP  = valP.ToFloat();
	CL3Variant valS = pRs.GetFieldByName(_T("S"));			
	L3DOUBLE fS;
	if (valS.IsNull())
		fS  = -1; 
	else
		fS  = valS.ToFloat();
	CL3Variant valCu = pRs.GetFieldByName(_T("Cu"));			
	L3DOUBLE fCu;
	if (valCu.IsNull())
		fCu  = -1; 
	else
		fCu  = valCu.ToFloat();
	CL3Variant valNi = pRs.GetFieldByName(_T("Ni"));			
	L3DOUBLE fNi;
	if (valNi.IsNull())
		fNi  = -1; 
	else
		fNi  = valNi.ToFloat();
	CL3Variant valCr = pRs.GetFieldByName(_T("Cr"));			
	L3DOUBLE fCr;
	if (valCr.IsNull())
		fCr  = -1; 
	else
		fCr  = valCr.ToFloat();
	CL3Variant valMo = pRs.GetFieldByName(_T("Mo"));			
	L3DOUBLE fMo;
	if (valMo.IsNull())
		fMo  = -1; 
	else
		fMo  = valMo.ToFloat();
	CL3Variant valV = pRs.GetFieldByName(_T("V"));			
	L3DOUBLE fV;
	if (valV.IsNull())
		fV  = -1; 
	else
		fV  = valV.ToFloat();
	CL3Variant valNb = pRs.GetFieldByName(_T("Nb"));			
	L3DOUBLE fNb;
	if (valNb.IsNull())
		fNb  = -1; 
	else
		fNb  = valNb.ToFloat();
	CL3Variant valAl = pRs.GetFieldByName(_T("Al"));			
	L3DOUBLE fAl;
	if (valAl.IsNull())
		fAl  = -1; 
	else
		fAl  = valAl.ToFloat();
	CL3Variant valAls = pRs.GetFieldByName(_T("Als"));			
	L3DOUBLE fAls;
	if (valAls.IsNull())
		fAls  = -1; 
	else
		fAls  = valAls.ToFloat();
  CL3Variant valTi = pRs.GetFieldByName(_T("Ti"));			
	L3DOUBLE fTi;
	if (valTi.IsNull())
		fTi  = -1; 
	else
		fTi  = valTi.ToFloat();
  CL3Variant valB = pRs.GetFieldByName(_T("B"));			
	L3DOUBLE fB;
	if (valB.IsNull())
		fB  = -1; 
	else
		fB  = valB.ToFloat();
  CL3Variant valSb = pRs.GetFieldByName(_T("Sb"));			
	L3DOUBLE fSb;
	if (valSb.IsNull())
		fSb  = -1; 
	else
		fSb  = valSb.ToFloat();
  CL3Variant valSn = pRs.GetFieldByName(_T("Sn"));			
	L3DOUBLE fSn;
	if (valSn.IsNull())
		fSn  = -1; 
	else
		fSn  = valSn.ToFloat();
  CL3Variant valAs = pRs.GetFieldByName(_T("As"));			
	L3DOUBLE fAs;
	if (valAs.IsNull())
		fAs  = -1; 
	else
		fAs  = valAs.ToFloat();
  CL3Variant valZn = pRs.GetFieldByName(_T("Zn"));			
	L3DOUBLE fZn;
	if (valZn.IsNull())
		fZn  = -1; 
	else
		fZn  = valZn.ToFloat();
  CL3Variant valZr = pRs.GetFieldByName(_T("Zr"));			
	L3DOUBLE fZr;
	if (valZr.IsNull())
		fZr  = -1; 
	else
		fZr  = valZr.ToFloat();
  CL3Variant valCa = pRs.GetFieldByName(_T("Ca"));			
	L3DOUBLE fCa;
	if (valCa.IsNull())
		fCa  = -1; 
	else
		fCa  = valCa.ToFloat();
  CL3Variant valW = pRs.GetFieldByName(_T("W"));			
	L3DOUBLE fW;
	if (valW.IsNull())
		fW  = -1; 
	else
		fW  = valW.ToFloat();
  CL3Variant valPb = pRs.GetFieldByName(_T("Pb"));			
	L3DOUBLE fPb;
	if (valPb.IsNull())
		fPb  = -1; 
	else
		fPb  = valPb.ToFloat();
  CL3Variant valRe = pRs.GetFieldByName(_T("Re"));			
	L3DOUBLE fRe;
	if (valRe.IsNull())
		fRe  = -1; 
	else
		fRe  = valRe.ToFloat();
  CL3Variant valCeq = pRs.GetFieldByName(_T("Ceq"));
	L3DOUBLE fCeq;
	if (valCeq.IsNull())
		fCeq = -1; 
	else
		fCeq = valCeq.ToFloat();
	CL3Variant valO = pRs.GetFieldByName(_T("O"));			
	L3DOUBLE fO;
	if (valO.IsNull())
		fO  = -1; 
	else
		fO  = valO.ToFloat();
  CL3Variant valN = pRs.GetFieldByName(_T("N"));			
	L3DOUBLE fN  ;
	if (valN.IsNull())
		fN  = -1; 
	else
		fN  = valN.ToFloat();
  CL3Variant valH = pRs.GetFieldByName(_T("H"));			
	L3DOUBLE fH;
	if (valH.IsNull())
		fH  = -1; 
	else
		fH  = valH.ToFloat();
  CL3Variant valOther1 = pRs.GetFieldByName(_T("Other1"));			
	L3DOUBLE fOther1;
	if (valOther1.IsNull())
		fOther1  = -1; 
	else
		fOther1  = valOther1.ToFloat();
  CL3Variant valOther2 = pRs.GetFieldByName(_T("Other2"));			
	L3DOUBLE fOther2;
	if (valOther2.IsNull())
		fOther2  = -1; 
	else
		fOther2  = valOther2.ToFloat();
  //设置参数
  //*************2005-11-16********增加浮点数精度控制*********//
	VARIANT valParams[90];
	valParams[0].vt = VT_R8; valParams[0].dblVal = fC+0.00001;
	valParams[1].vt = VT_R8; valParams[1].dblVal = fC-0.00001;
	valParams[2].vt = VT_R8; valParams[2].dblVal = fC;
	valParams[3].vt = VT_R8; valParams[3].dblVal = fSi+0.00001;
	valParams[4].vt = VT_R8; valParams[4].dblVal = fSi-0.00001;
	valParams[5].vt = VT_R8; valParams[5].dblVal = fSi;
	valParams[6].vt = VT_R8; valParams[6].dblVal = fMn+0.00001;
	valParams[7].vt = VT_R8; valParams[7].dblVal = fMn-0.00001;
	valParams[8].vt = VT_R8; valParams[8].dblVal = fMn;
	valParams[9].vt = VT_R8; valParams[9].dblVal = fP+0.00001;
	valParams[10].vt = VT_R8; valParams[10].dblVal = fP-0.00001;
	valParams[11].vt = VT_R8; valParams[11].dblVal = fP;
	valParams[12].vt = VT_R8; valParams[12].dblVal = fS+0.00001;
	valParams[13].vt = VT_R8; valParams[13].dblVal = fS-0.00001;
	valParams[14].vt = VT_R8; valParams[14].dblVal = fS;
	valParams[15].vt = VT_R8; valParams[15].dblVal = fCu+0.00001;
	valParams[16].vt = VT_R8; valParams[16].dblVal = fCu-0.00001;
	valParams[17].vt = VT_R8; valParams[17].dblVal = fCu;
	valParams[18].vt = VT_R8; valParams[18].dblVal = fNi+0.00001;
	valParams[19].vt = VT_R8; valParams[19].dblVal = fNi-0.00001;
	valParams[20].vt = VT_R8; valParams[20].dblVal = fNi;
	valParams[21].vt = VT_R8; valParams[21].dblVal = fCr+0.00001;
	valParams[22].vt = VT_R8; valParams[22].dblVal = fCr-0.00001;
	valParams[23].vt = VT_R8; valParams[23].dblVal = fCr;
	valParams[24].vt = VT_R8; valParams[24].dblVal = fMo+0.00001;
	valParams[25].vt = VT_R8; valParams[25].dblVal = fMo-0.00001;
	valParams[26].vt = VT_R8; valParams[26].dblVal = fMo;
	valParams[27].vt = VT_R8; valParams[27].dblVal = fV+0.00001;
	valParams[28].vt = VT_R8; valParams[28].dblVal = fV-0.00001;
	valParams[29].vt = VT_R8; valParams[29].dblVal = fV;
	valParams[30].vt = VT_R8; valParams[30].dblVal = fNb+0.00001;
	valParams[31].vt = VT_R8; valParams[31].dblVal = fNb-0.00001;
	valParams[32].vt = VT_R8; valParams[32].dblVal = fNb;
	valParams[33].vt = VT_R8; valParams[33].dblVal = fAl+0.00001;
	valParams[34].vt = VT_R8; valParams[34].dblVal = fAl-0.00001;
	valParams[35].vt = VT_R8; valParams[35].dblVal = fAl;
	valParams[36].vt = VT_R8; valParams[36].dblVal = fAls+0.00001;
	valParams[37].vt = VT_R8; valParams[37].dblVal = fAls-0.00001;
	valParams[38].vt = VT_R8; valParams[38].dblVal = fAls;
	valParams[39].vt = VT_R8; valParams[39].dblVal = fTi+0.00001;
	valParams[40].vt = VT_R8; valParams[40].dblVal = fTi-0.00001;
	valParams[41].vt = VT_R8; valParams[41].dblVal = fTi;
	valParams[42].vt = VT_R8; valParams[42].dblVal = fB+0.00001;
	valParams[43].vt = VT_R8; valParams[43].dblVal = fB-0.00001;
	valParams[44].vt = VT_R8; valParams[44].dblVal = fB;
	valParams[45].vt = VT_R8; valParams[45].dblVal = fSb+0.00001;
	valParams[46].vt = VT_R8; valParams[46].dblVal = fSb-0.00001;
	valParams[47].vt = VT_R8; valParams[47].dblVal = fSb;
	valParams[48].vt = VT_R8; valParams[48].dblVal = fSn+0.00001;
	valParams[49].vt = VT_R8; valParams[49].dblVal = fSn-0.00001;
	valParams[50].vt = VT_R8; valParams[50].dblVal = fSn;
	valParams[51].vt = VT_R8; valParams[51].dblVal = fAs+0.00001;
	valParams[52].vt = VT_R8; valParams[52].dblVal = fAs-0.00001;
	valParams[53].vt = VT_R8; valParams[53].dblVal = fAs;
	valParams[54].vt = VT_R8; valParams[54].dblVal = fZn+0.00001;
	valParams[55].vt = VT_R8; valParams[55].dblVal = fZn-0.00001;
	valParams[56].vt = VT_R8; valParams[56].dblVal = fZn;
	valParams[57].vt = VT_R8; valParams[57].dblVal = fZr+0.00001;
	valParams[58].vt = VT_R8; valParams[58].dblVal = fZr-0.00001;
	valParams[59].vt = VT_R8; valParams[59].dblVal = fZr;
	valParams[60].vt = VT_R8; valParams[60].dblVal = fCa+0.00001;
	valParams[61].vt = VT_R8; valParams[61].dblVal = fCa-0.00001;
	valParams[62].vt = VT_R8; valParams[62].dblVal = fCa;
	valParams[63].vt = VT_R8; valParams[63].dblVal = fW+0.00001;
	valParams[64].vt = VT_R8; valParams[64].dblVal = fW-0.00001;
	valParams[65].vt = VT_R8; valParams[65].dblVal = fW;
	valParams[66].vt = VT_R8; valParams[66].dblVal = fPb+0.00001;
	valParams[67].vt = VT_R8; valParams[67].dblVal = fPb-0.00001;
	valParams[68].vt = VT_R8; valParams[68].dblVal = fPb;
	valParams[69].vt = VT_R8; valParams[69].dblVal = fRe+0.00001;
	valParams[70].vt = VT_R8; valParams[70].dblVal = fRe-0.00001;
	valParams[71].vt = VT_R8; valParams[71].dblVal = fRe;
	valParams[72].vt = VT_R8; valParams[72].dblVal = fCeq+0.00001;
	valParams[73].vt = VT_R8; valParams[73].dblVal = fCeq-0.00001;
	valParams[74].vt = VT_R8; valParams[74].dblVal = fCeq;
	valParams[75].vt = VT_R8; valParams[75].dblVal = fO+0.00001;
	valParams[76].vt = VT_R8; valParams[76].dblVal = fO-0.00001;
	valParams[77].vt = VT_R8; valParams[77].dblVal = fO;
	valParams[78].vt = VT_R8; valParams[78].dblVal = fN+0.00001;
	valParams[79].vt = VT_R8; valParams[79].dblVal = fN-0.00001;
	valParams[80].vt = VT_R8; valParams[80].dblVal = fN;
	valParams[81].vt = VT_R8; valParams[81].dblVal = fH+0.00001;
	valParams[82].vt = VT_R8; valParams[82].dblVal = fH-0.00001;
	valParams[83].vt = VT_R8; valParams[83].dblVal = fH;
	valParams[84].vt = VT_R8; valParams[84].dblVal = fOther1+0.00001;
	valParams[85].vt = VT_R8; valParams[85].dblVal = fOther1-0.00001;
	valParams[86].vt = VT_R8; valParams[86].dblVal = fOther1;
	valParams[87].vt = VT_R8; valParams[87].dblVal = fOther2+0.00001;
	valParams[88].vt = VT_R8; valParams[88].dblVal = fOther2-0.00001;
	valParams[89].vt = VT_R8; valParams[89].dblVal = fOther2;
	//******************************************************//

  //获取推荐的炼钢记号
	CL3RecordSetWrap pRs1;
	CString csSeqStr = _T("Select A.SteelGradeIndex,B.SteelGrade From XGMESLogic\\QualityMag\\CQA_Product_Sheet A,XGMESLogic\\QualityMag\\CQA_SteelGradeIndex_R B Where ");
	CString csConditionSqlstr ;
  csConditionSqlstr = csConditionSqlstr + _T("A.SteelGradeIndex = B.SteelGradeIndex and ") +  
		                    _T("(A.C_Min <= ? and A.C_Max >= ? or A.C_Min = -1 and A.C_Max = -1 or ? = -1) and ") + _T("(A.Si_Min <= ? and A.Si_Max >= ?  or A.Si_Min = -1 and A.Si_Max = -1 or ?=-1) and ") +
	                        _T("(A.Mn_Min <= ? and A.Mn_Max >= ?  or A.Mn_Min = -1 and A.Mn_Max = -1 or ? = -1) and ") + _T("(A.P_Min <= ? and A.P_Max >= ?  or A.P_Min = -1 and A.P_Max = -1 or ? = -1) and ") +
                            _T("(A.S_Min <= ? and A.S_Max >= ?  or A.S_Min = -1 and A.S_Max = -1 or ? = -1) and ") + _T("(A.Cu_Min <= ? and A.Cu_Max >= ?  or A.Cu_Min = -1 and A.Cu_Max = -1 or ? = -1) and ") +
							_T("(A.Ni_Min <= ? and A.Ni_Max >= ?  or A.Ni_Min = -1 and A.Ni_Max = -1 or ? = -1) and ") + _T("(A.Cr_Min <= ? and A.Cr_Max >= ?  or A.Cr_Min = -1 and A.Cr_Max = -1 or ? = -1) and ") +
							_T("(A.Mo_Min <= ? and A.Mo_Max >= ?  or A.Mo_Min = -1 and A.Mo_Max = -1 or ? = -1) and ") + _T("(A.V_Min <= ? and A.V_Max >= ?  or A.V_Min = -1 and A.V_Max = -1 or ? = -1) and ") +
							_T("(A.Nb_Min <= ? and A.Nb_Max >= ?  or A.Nb_Min = -1 and A.Nb_Max = -1 or ? = -1) and ") + _T("(A.Al_Min <= ? and A.Al_Max >= ?  or A.Al_Min = -1 and A.Al_Max = -1 or ? = -1) and ") +
							_T("(A.Als_Min <= ? and A.Als_Max >= ?  or A.Als_Min = -1 and A.Als_Max = -1 or ? = -1) and ") + _T("(A.Ti_Min <= ? and A.Ti_Max >= ?  or A.Ti_Min = -1 and A.Ti_Max = -1 or ? = -1) and ") +
							_T("(A.B_Min <= ? and A.B_Max >= ?  or A.B_Min = -1 and A.B_Max = -1 or ? = -1) and ") + _T("(A.Sb_Min <= ? and A.Sb_Max >= ?  or A.Sb_Min = -1 and A.Sb_Max = -1 or ? = -1) and ") +
							_T("(A.Sn_Min <= ? and A.Sn_Max >= ?  or A.Sn_Min = -1 and A.Sn_Max = -1 or ? = -1) and ") + _T("(A.As_Min <= ? and A.As_Max >= ?  or A.As_Min = -1 and A.As_Max = -1 or ? = -1) and ") +
							_T("(A.Zn_Min <= ? and A.Zn_Max >= ?  or A.Zn_Min = -1 and A.Zn_Max = -1 or ? = -1) and ") + _T("(A.Zr_Min <= ? and A.Zr_Max >= ?  or A.Zr_Min = -1 and A.Zr_Max = -1 or ? = -1) and ") +															
							_T("(A.Ca_Min <= ? and A.Ca_Max >= ?  or A.Ca_Min = -1 and A.Ca_Max = -1 or ? = -1) and ") + _T("(A.W_Min <= ? and A.W_Max >= ?  or A.W_Min = -1 and A.W_Max = -1 or ? = -1) and ") +
							_T("(A.Pb_Min <= ? and A.Pb_Max >= ?  or A.Pb_Min = -1 and A.Pb_Max = -1 or ? = -1) and ") + _T("(A.Re_Min <= ? and A.Re_Max >= ?  or A.Re_Min = -1 and A.Re_Max = -1 or ? = -1) and ") +
							_T("(A.Ceq_Min <= ? and A.Ceq_Max >= ?  or A.Ceq_Min = -1 and A.Ceq_Max = -1 or ? = -1) and ") + _T("(A.O_Min <= ? and A.O_Max >= ?  or A.O_Min = -1 and A.O_Max = -1 or ? = -1) and ") +
							_T("(A.N_Min <= ? and A.N_Max >= ?  or A.N_Min = -1 and A.N_Max = -1 or ? = -1) and ") + _T("(A.H_Min <= ? and A.H_Max >= ?  or A.H_Min = -1 and A.H_Max = -1 or ? = -1) and ") +
							_T("(A.Other1_Min <= ? and A.Other1_Max >= ?  or A.Other1_Min = -1 and A.Other1_Max = -1 or ? = -1) and ") + _T("(A.Other2_Min <= ? and A.Other2_Max >= ?  or A.Other2_Min = -1 and A.Other2_Max = -1 or ? = -1)"); 

  csSeqStr = csSeqStr + csConditionSqlstr;
	if (!QueryWithParam(csSeqStr, valParams, 90, pRs1))	return 0; 
	if(*rsSteelGradeIndexData != NULL)
		(*rsSteelGradeIndexData)->Release();
	int j = pRs1.GetRowCount();
	pRs1.MoveFirst();
	CString cstrtemp = (pRs1.GetFieldByName(_T("SteelGradeIndex"))).ToCString();
    *rsSteelGradeIndexData = pRs1.Detach();
  
  return 1;
}

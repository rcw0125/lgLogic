// �߼���CMIF_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CMIF_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CMIF_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CMIF_Mag.h"
#include "L3NameParser.h"
#include "Material.h"
#include "MaterialMap.h"
#include "_CIron_Data.h"
#include "_CBFIron.h"

//������װ�ص�ϵͳ��ʱ��������
void CMIF_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CMIF_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

// �����㷨���ߺ��������ڽ�������ˮ��Ϣ����һ���µ���ˮ��Ϣ
BOOL CMIF_Mag::MixIrons(L3RECORDSET rsIrons,L3RECORDSET rsTarget)
{
	CL3RecordSetWrap rs = rsIrons;
	CL3RecordSetWrap rsNew = rsTarget;
	if(rs.GetRowCount() < 1 || rsNew.GetRowCount() < 1 || rsNew.IsBOF() || rsNew.IsEOF())
		return FALSE;
	
	L3DOUBLE C=0;
	L3DOUBLE Si=0;
	L3DOUBLE Mn=0;
	L3DOUBLE S=0;
	L3DOUBLE P=0;
	L3DOUBLE Ti=0;
	L3DOUBLE Weight=0;

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		L3DOUBLE fC = rs.GetFieldByName(_T("C")).ToDouble();
		L3DOUBLE fSi = rs.GetFieldByName(_T("Si")).ToDouble();
		L3DOUBLE fMn = rs.GetFieldByName(_T("Mn")).ToDouble();
		L3DOUBLE fS = rs.GetFieldByName(_T("S")).ToDouble();
		L3DOUBLE fP = rs.GetFieldByName(_T("P")).ToDouble();
		L3DOUBLE fTi = rs.GetFieldByName(_T("Ti")).ToDouble();
		L3DOUBLE fW = 0;
		if(rs.GetFieldIndex(_T("Weight")) >= 0)
			fW = rs.GetFieldByName(_T("Weight")).ToDouble();
		else if(rs.GetFieldIndex(_T("Net_Weight")) >= 0)
			fW = rs.GetFieldByName(_T("Net_Weight")).ToDouble();
		else
			return FALSE;
		Weight += fW;
		C += fW * fC;
		Si += fW * fSi;
		Mn += fW * fMn;
		S += fW * fS;
		P += fW * fP;
		Ti += fW * fTi;
		rs.MoveNext();
	}

	rsNew.SetFieldByName(_T("Net_Weight"),CL3Variant(Weight));
	rsNew.SetFieldByName(_T("Weight"),CL3Variant(Weight));
	rsNew.SetFieldByName(_T("C"),CL3Variant((L3DOUBLE)(C / Weight)));
	rsNew.SetFieldByName(_T("Si"),CL3Variant((L3DOUBLE)(Si / Weight)));
	rsNew.SetFieldByName(_T("Mn"),CL3Variant((L3DOUBLE)(Mn / Weight)));
	rsNew.SetFieldByName(_T("S"),CL3Variant((L3DOUBLE)(S / Weight)));
	rsNew.SetFieldByName(_T("P"),CL3Variant((L3DOUBLE)(P / Weight)));
	rsNew.SetFieldByName(_T("Ti"),CL3Variant((L3DOUBLE)(Ti / Weight)));

	return TRUE;
}

/// <Method class="CMIF_Mag" name="DirectFeedIron" type="L3STRING">
/// �����ԭ��������ˮ����Ŀ�������������µ���ˮ���ϡ���������ˮ���ϵ�MaterialID��
/// <Param name="TargetLadle" type="L3STRING">Ŀ��������</Param>
/// <Param name="rsIron" type="L3RECORDSET">������������ԭ��ˮ��Ϣ</Param>
/// </Method>
L3STRING CMIF_Mag::DirectFeedIron(L3STRING TargetLadle, L3RECORDSET rsIron)
{
	CString strTgtLadle = String_BSTR2TChar(TargetLadle);
	strTgtLadle.Trim();
	if(strTgtLadle.IsEmpty()) return NULL; //2009-01-07 tangyi
	CL3RecordSetWrap rs = rsIron;
	if(rs.GetRowCount() < 1)
		return NULL;

	// ��鼰׼������
	if(rs.GetFieldIndex(_T("MaterialID")) < 0 ||
		rs.GetFieldIndex(_T("Spare_Weight")) < 0 ||
		rs.GetFieldIndex(_T("Net_Weight")) < 0)
	{
		SetL3LastError(L3ERR_WRONG_PARAMETER);
		return NULL;
	}
	rs.AddField(_T("MaterialType"),VT_BSTR);
	rs.AddField(_T("Amount"),VT_R8);
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rs.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CBFIron")));
		rs.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		rs.MoveNext();
	}
	
	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return NULL;
	// ��ס��ˮ�����Cache
	if(!PutObjectIntoTrans(BFIronStoreOutCache_URI))
	{
		Rollback(nTrans);
		return NULL;
	}

	// ׼����ˮ����������¼��
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsUpdate; pRS->QueryInterface(IID_IL3RecordSet,rsUpdate); pRS->Release();
	rsUpdate.AddField(_T("MaterialType"),VT_BSTR);
	rsUpdate.AddField(_T("MaterialID"),VT_BSTR);
	//CL3RecordSetWrap rsDel = rs.CloneStruct();
	rsUpdate.AddField(_T("Spare_Weight"),VT_R8);

	//rsDel.AddField(_T("Status"),VT_I4);
	//rsDel.AddField(_T("Amount"),VT_R8);
	//rsDel.AddField(_T("Spare_Weight"),VT_R8);

	//2009-05-17 tangyiy �޸�Ϊ����
	CL3RecordSet *pRSdel = new CL3RecordSet();
	CL3RecordSetWrap rsDel; pRSdel->QueryInterface(IID_IL3RecordSet,rsDel); pRSdel->Release();
	rsDel.AddField(_T("MaterialType"),VT_BSTR);
	rsDel.AddField(_T("MaterialID"),VT_BSTR);
	rsDel.AddField(_T("Amount"),VT_R8);
	rsDel.AddField(_T("Status"),VT_I4);
	rsDel.AddField(_T("Spare_Weight"),VT_R8);



	// ׼����ˮ���ռ�¼
	CL3RecordSetWrap rsMap;
	if(!CreateClassPropSet(_T("MES\\MaterialData\\MaterialMap"),rsMap))
	{
		Rollback(nTrans);
		return NULL;
	}

	COleDateTime curDate = COleDateTime::GetCurrentTime();
	CString strNewIronID; strNewIronID.Format(_T("%s_%04d%02d%02d%02d%02d%02d"),TargetLadle,curDate.GetYear(),curDate.GetMonth(),curDate.GetDay(),curDate.GetHour(),curDate.GetMinute(),curDate.GetSecond());

	CString csBFIron1,csBFIron2,csBFIron3;//2009-04-19
	L3DOUBLE fWeightBFIron1=0,fWeightBFIron2=0,fWeightBFIron3=0;//2009-04-19
	int iCount = 0;
	// ������ˮ��Ϣ
	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString IronID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString IronURI = CL3NameParser::MergeClassDomainName(MATERIAL_BFIRON_URI,IronID);
		// ������ˮ������
		CL3Variant valOrgWeight = GetObjectPropValue(IronURI,_T("Spare_Weight"));
		L3DOUBLE fOrgWeight = valOrgWeight.ToDouble();
		L3DOUBLE fMixWeight = rs.GetFieldByName(_T("Net_Weight")).ToDouble();
		L3DOUBLE fOff = fOrgWeight - fMixWeight;
		//if(fOff < -0.00000001)
		if(fOff < -0.005)//2009-06-11 tangyi
		{	// ��ˮ��������
			Rollback(nTrans);
			SetL3LastError(MESERR_MATERIAL_NOTENOUGH);
			return NULL;
		}
		else if(fOff < 0.00000001)
		{	// ����ȫ����ˮ
			rsDel.AppendRecord();
			//rsDel.CopyCurRowFrom(rs);//2009-04-14
			rsDel.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
			rsDel.SetFieldByName(_T("MaterialID"),CL3Variant(IronID));
			rsDel.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
			rsDel.SetFieldByName(_T("Status"),CL3Variant((LONG)Material::Deleted));
			rsDel.SetFieldByName(_T("Spare_Weight"),CL3Variant((LONG)0));
		}
		else
		{	// ���벿����ˮ
			rsUpdate.AppendRecord();
			rsUpdate.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
			rsUpdate.SetFieldByName(_T("MaterialID"),CL3Variant(IronID));
			rsUpdate.SetFieldByName(_T("Spare_Weight"),CL3Variant(fOff));
		}
		// д���ռ�¼
		rsMap.AppendRecord();
		rsMap.SetFieldByName(_T("FromType"),CL3Variant(_T("CBFIron")));
		rsMap.SetFieldByName(_T("FromID"),CL3Variant(IronID));
		rsMap.SetFieldByName(_T("ToType"),CL3Variant(_T("CIron_Data")));
		rsMap.SetFieldByName(_T("ToID"),CL3Variant(strNewIronID));
		rsMap.SetFieldByName(_T("Mode"),CL3Variant((LONG)MaterialMap::Merge));
		rsMap.SetFieldByName(_T("Mapper"),CL3Variant(GetURI()));
		rsMap.SetFieldByName(_T("SrcAmount"),CL3Variant(fMixWeight));
		rsMap.SetFieldByName(_T("TgtAmount"),CL3Variant(fMixWeight));

        //2009-04-19 Begin
		++iCount;
		if(iCount == 1)
		{
			csBFIron1 = IronID;
            fWeightBFIron1 = fMixWeight;
		}
		else if(iCount == 2)
		{
			csBFIron2 = IronID;
            fWeightBFIron2 = fMixWeight;
		}
		else if(iCount == 3)
		{
			csBFIron3 = IronID;
            fWeightBFIron3 = fMixWeight;
		}
		else
		{
			Rollback(nTrans);
			return NULL;
		}
		//2009-04-19 End

		rs.MoveNext();
	}
	// �����µ���ˮ
	CL3RecordSetWrap rsNewIron;
	if(!CreateClassPropSet(MATERIAL_IRON_URI,rsNewIron))
	{
		Rollback(nTrans);
		return NULL;
	}
	//2009-01-07 tangyi
	rsNewIron.AddField(_T("MaterialType"),VT_BSTR);
	rsNewIron.AddField(_T("Amount"),VT_R8);
	rsNewIron.AppendRecord();
	rs.MoveFirst();
	if(!MixIrons(rs,rsNewIron))
	{
		Rollback(nTrans);
		return NULL;
	}	
	rsNewIron.SetFieldByName(_T("MaterialType"),CL3Variant(_T("CIron_Data")));
	rsNewIron.SetFieldByName(_T("Amount"),CL3Variant((L3DOUBLE)1));
	rsNewIron.SetFieldByName(_T("MaterialID"),CL3Variant(strNewIronID));
	rsNewIron.SetFieldByName(_T("IronLadleNo"),CL3Variant(TargetLadle));
	rsNewIron.SetFieldByName(_T("Tap_Time"),CL3Variant(curDate));
	rsNewIron.SetFieldByName(_T("Source"),CL3Variant((LONG)CIron_Data::DirectMixed));
	rsNewIron.SetFieldByName(_T("Object1"),CL3Variant(csBFIron1));               //2009-04-19
	rsNewIron.SetFieldByName(_T("Weight1"),CL3Variant((L3DOUBLE)fWeightBFIron1));//2009-04-19
	rsNewIron.SetFieldByName(_T("Object2"),CL3Variant(csBFIron2));               //2009-04-19
	rsNewIron.SetFieldByName(_T("Weight2"),CL3Variant((L3DOUBLE)fWeightBFIron2));//2009-04-19
	rsNewIron.SetFieldByName(_T("Object3"),CL3Variant(csBFIron3));               //2009-04-19
	rsNewIron.SetFieldByName(_T("Weight3"),CL3Variant((L3DOUBLE)fWeightBFIron3));//2009-04-19

	//��ȡ�����߳�������2009-01-04 begin
	COleDateTime dtWeightTime = GetObjectPropValue(_T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag\\S11"),_T("Tare_Weight_Time")).ToDateTime();
	COleDateTime curTime = COleDateTime::GetCurrentTime();
	COleDateTimeSpan span = curTime - dtWeightTime;
	if (span.GetTotalMinutes() < 60) //һСʱ����Ч
	{
		L3DOUBLE fWeight = GetObjectPropValue(_T("XGMESLogic\\MIXFMag\\CMIF_Unit_Mag\\S11"),_T("Tare_Weight")).ToDouble();
		rsNewIron.SetFieldByName(_T("Net_Weight"),CL3Variant(fWeight));
		rsNewIron.SetFieldByName(_T("Weight"),CL3Variant(fWeight));
	}
	//��ȡ�����߳�������2009-01-04 end

	if(CreateNewObjects(MATERIAL_IRON_URI,rsNewIron) < 1)
	{
		Rollback(nTrans);
		return NULL;
	}
	// ��ȫ���������ˮ����������Ƴ�����ɾ����־��
	CL3Variant valRet;
	if(rsDel.GetRowCount() > 0)
	{
		rsDel.MoveFirst();
		valRet = InvokeObjectMethod(BFIronStoreOutCache_URI,_T("RemoveMaterials"),(L3RECORDSET)rsDel);
		if(valRet.ToBOOL() == FALSE)
		{
			Rollback(nTrans);
			return NULL;
		}
		rsDel.MoveFirst();
		if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rsDel))
		{
			Rollback(nTrans);
			return NULL;
		}
	}
	// ��δȫ���������ˮ���޸���ʣ����
	if(rsUpdate.GetRowCount() > 0)
	{
		rsUpdate.MoveFirst();
		if(!SetObjsPropValues(MATERIAL_BFIRON_URI,rsUpdate))
		{
			Rollback(nTrans);
			return NULL;
		}
	}
	// ������ˮ�������¯�󻺴�
	rsNewIron.MoveFirst();
	valRet = InvokeObjectMethod(MIXFProduceCache_URI,_T("AddMaterials"),(L3RECORDSET)rsNewIron);
	if(valRet.ToBOOL() == FALSE)
	{
		Rollback(nTrans);
		return NULL;
	}
	// ��¼���϶���
	rsMap.MoveFirst();
	if(CreateNewObjects(_T("MES\\MaterialData\\MaterialMap"),rsMap) < 1)
	{
		Rollback(nTrans);
		return NULL;
	}

	// �޸�����״̬Ϊ����
	CString strLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,strTgtLadle);
	SetObjectPropValue(strLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_USE));
	//2009-03-17
	long iIronLadleAge = GetObjectPropValue(strLadleURI,_T("IronLadle_Age")).ToLong();
	iIronLadleAge += 1;
	SetObjectPropValue(strLadleURI,_T("IronLadle_Age"),CL3Variant(L3LONG(iIronLadleAge)));

	Commit(nTrans);

	return strNewIronID.AllocSysString();
}

/// <Method class="CMIF_Mag" name="GetUnArrivedIrons" type="L3RECORDSET">
/// ����ȥ��Ϊ���ֵ�δ�������ˮ��Ϣ
/// </Method>
L3RECORDSET CMIF_Mag::GetUnArrivedIrons()
{
	CL3Variant val = InvokeObjectMethod(BFIronStore_URI,_T("GetUnArrivedIrons"),(LONG)CBFIron::ironToBOF);
	CL3RecordSetWrap rs;
	if(FAILED(val.QueryInterface(IID_IL3RecordSet,rs)))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CMIF_Mag" name="GetIncomingIrons" type="L3RECORDSET">
/// ���ص������¯����ǰ����ˮ��Ϣ
/// </Method>
L3RECORDSET CMIF_Mag::GetIncomingIrons()
{
	CL3Variant valRet = InvokeObjectMethod(BFIronStoreOutCache_URI,_T("GetMaterialDetails"),_T("CBFIron"),_T(""));
	CL3RecordSetWrap rsRet;
	if(FAILED(valRet.QueryInterface(IID_IL3RecordSet,rsRet)))
		return NULL;
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MATERIAL_BFIRON_URI,rs))
		return NULL;
	rsRet.MoveFirst();
	rs.CopyFrom(rsRet);
	return rs.Detach();
}

/// <Method class="CMIF_Mag" name="GetOutgoingIrons" type="L3RECORDSET">
/// ����ֱ�Һͻ���¯��������ˮ��Ϣ��
/// </Method>
L3RECORDSET CMIF_Mag::GetOutgoingIrons()
{
	CL3Variant valRet = InvokeObjectMethod(MIXFProduceCache_URI,_T("GetMaterialDetails"),_T("CIron_Data"),_T(""));
	CL3RecordSetWrap rsRet;
	if(FAILED(valRet.QueryInterface(IID_IL3RecordSet,rsRet)))
		return NULL;
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MATERIAL_IRON_URI,rs))
		return NULL;
	rsRet.MoveFirst();
	rs.CopyFrom(rsRet);
	return rs.Detach();
}

L3RECORDSET CMIF_Mag::GetOutgoingIrons2()
{
	CL3Variant valRet = InvokeObjectMethod(_T("XGMESLogic\\BaseDataMag\\XGInterCache\\S91P01"),_T("GetMaterialDetails"),_T("CIron_Data"),_T(""));
	CL3RecordSetWrap rsRet;
	if(FAILED(valRet.QueryInterface(IID_IL3RecordSet,rsRet)))
		return NULL;
	CL3RecordSetWrap rs;
	if(!CreateClassPropSet(MATERIAL_IRON_URI,rs))
		return NULL;
	rsRet.MoveFirst();
	rs.CopyFrom(rsRet);
	return rs.Detach();
}

/// <Method class="CMIF_Unit_Mag" name="GetHotIronLadles" type="L3RECORDSET">
/// ��ȡ��ǰ�ȱ�����
/// </Method>
L3RECORDSET CMIF_Mag::GetHotIronLadles()
{
	CString strSQL;
	strSQL.Format(_T("select IronLadleID from %s where Status = '%s'"),CIRONLADLE_BASE_URI,CIRONLADLE_STATUS_HOT);
	CL3RecordSetWrap rs;
	if(!Query(strSQL,rs))
		return NULL;
	else
		return rs.Detach();
}

/// <Method class="CMIF_Mag" name="BackBFIron" type="L3LONG">
/// ���˸�¯��ˮ
/// <Param name="dsIron" type="L3RECORDSET">������ˮ��Ϣ</Param>
/// </Method>
L3LONG CMIF_Mag::BackBFIron(L3RECORDSET dsIron)
{
	// TODO : ���ڴ�����߼�����
	return 0;
}

/// <Method class="CMIF_Mag" name="OutputIronCancel" type="L3LONG">
/// ȡ��ֱ����ˮ2009-04-19
/// </Method>
L3LONG CMIF_Mag::OutputIronCancel(L3RECORDSET rsLadleID)
{
	CL3RecordSetWrap rs = rsLadleID;
	if(rs.GetRowCount() < 1 || rs.IsNull())
		return -1;

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	// ����������¯
	if(!PutObjectIntoTrans(GetURI()))
	{
		Rollback(nTrans);
		return -2;
	}

	//�齨���ݼ�
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("Amount"),VT_INT);
	rsMaterial.AppendRecord();

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		//�޸�ʣ������
		CString csMaterialID = rs.GetFieldByName(_T("MaterialID")).ToCString();
		CString csIronUri = CL3NameParser::MergeClassDomainName(MATERIAL_IRON_URI,csMaterialID);
		CString csHeatID = GetObjectPropValue(csIronUri,_T("HeatID")).ToCString();
		csHeatID.Trim();
		//�Ѿ�ָ����ԭ�ϲ�����ȡ��
		if(!csHeatID.IsEmpty())
		{
			Rollback(nTrans);
			return -3;
		}
		L3LONG nSource = GetObjectPropValue(csIronUri,_T("Source")).ToLong();
		//����¯��ˮ������ȡ��
		if(nSource > 0)
		{
			Rollback(nTrans);
			return -4;
		}
		CString csBFIron1 = GetObjectPropValue(csIronUri,_T("Object1")).ToCString();
		L3DOUBLE fWeightBFIron1 = GetObjectPropValue(csIronUri,_T("Weight1")).ToDouble();
		CString csBFIron2 = GetObjectPropValue(csIronUri,_T("Object2")).ToCString();
		L3DOUBLE fWeightBFIron2 = GetObjectPropValue(csIronUri,_T("Weight2")).ToDouble();
		CString csBFIron3 = GetObjectPropValue(csIronUri,_T("Object3")).ToCString();
		L3DOUBLE fWeightBFIron3 = GetObjectPropValue(csIronUri,_T("Weight3")).ToDouble();

		if(csBFIron1.GetLength() > 0)
		{
			L3DOUBLE fSpareWBFIron = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csBFIron1,_T("Spare_Weight")).ToDouble();
			if(!SetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csBFIron1,_T("Spare_Weight"),CL3Variant((L3DOUBLE)fSpareWBFIron+fWeightBFIron1)))
			{
				Rollback(nTrans);
				return -8;
			}
			if(!OnDoFeedIron(csBFIron1))
			{
				Rollback(nTrans);
				return -8;
			}
		}
		if(csBFIron2.GetLength() > 0)
		{
			L3DOUBLE fSpareWBFIron = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csBFIron2,_T("Spare_Weight")).ToDouble();
			if(!SetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csBFIron2,_T("Spare_Weight"),CL3Variant((L3DOUBLE)fSpareWBFIron+fWeightBFIron2)))
			{
				Rollback(nTrans);
				return -8;
			}
			if(!OnDoFeedIron(csBFIron1))
			{
				Rollback(nTrans);
				return -8;
			}
		}
		if(csBFIron3.GetLength() > 0)
		{
			L3DOUBLE fSpareWBFIron = GetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csBFIron3,_T("Spare_Weight")).ToDouble();
			if(!SetObjectPropValue(_T("MES\\MaterialData\\CBFIron\\")+csBFIron3,_T("Spare_Weight"),CL3Variant((L3DOUBLE)fSpareWBFIron+fWeightBFIron3)))
			{
				Rollback(nTrans);
				return -8;
			}
			if(!OnDoFeedIron(csBFIron1))
			{
				Rollback(nTrans);
				return -8;
			}
		}

		//����������״̬Ϊ�ȱ�
		CString csIronLadle = GetObjectPropValue(csIronUri,_T("IronLadleNo")).ToCString();
		CString csLadleURI = CL3NameParser::MergeClassDomainName(CIRONLADLE_BASE_URI,csIronLadle);
		if(!SetObjectPropValue(csLadleURI,_T("Status"),CL3Variant(CIRONLADLE_STATUS_HOT)))
		{
			Rollback(nTrans);
			return -7;
		}

		//ɾ����ˮ����
		if(!DeleteOldObject(csIronUri))
		{
			Rollback(nTrans);
			return -5;
		}
		// ������ˮ�Ƴ���������
		rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_IRON));
		rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csMaterialID));
		rsMaterial.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
		CL3Variant valRet = InvokeObjectMethod(MIXFProduceCache_URI,_T("RemoveMaterials"),(L3RECORDSET)rsMaterial);
		if(valRet.ToBOOL() == FALSE)
		{
			Rollback(nTrans);
			return -6;
		}

		rsMaterial.MoveFirst();
		rs.MoveNext();
	}

	Commit(nTrans);

	return 1;
}

/// <Method class="CMIF_Mag" name="OnDoFeedIron" type="L3BOOL">
/// ����ֱ����ˮ2009-04-19
/// </Method>
L3BOOL CMIF_Mag::OnDoFeedIron(CString strMaterialID)
{
	CString csTemp = _T(" select GUID from MaterialPosition where Position ='%s' and MaterialID='%s'");
	CString csSQL;
	csSQL.Format(csTemp,UNIT_ID_IRON_CACHE,strMaterialID);
	CL3RecordSetWrap rs;
	if(!Query(csSQL,rs) || rs.IsNull())
	{
		return FALSE;
	}
	if (rs.GetRowCount()> 0)
	{
		return TRUE;
	}

	csTemp = _T("select * from CBFIron where MaterialID = '%s'");
	csSQL.Format(csTemp,strMaterialID);
	CL3RecordSetWrap rstemp;
	if(!Query(csSQL,rstemp) || rstemp.IsNull())
	{
		return FALSE;
	}
	if(rstemp.GetRowCount() < 1)
	{
		return FALSE;
	}
	rstemp.MoveFirst();

	CL3RecordSetWrap rsIron;
	if(!CreateClassPropSet(MATERIAL_BFIRON_URI,rsIron))
	{
		return FALSE;
	}

	rsIron.AddField(_T("MaterialType"),VT_BSTR);
	rsIron.AddField(_T("Amount"),VT_R8);
	rsIron.AddField(_T("StoreAreaID"),VT_BSTR);

	rsIron.AppendRecord();
	rsIron.CopyCurRowFrom(rstemp);
	rsIron.SetFieldByName(_T("MaterialType"),_T("CBFIron"));
	rsIron.SetFieldByName(_T("Amount"),CL3Variant((LONG)1));
	rsIron.SetFieldByName(_T("StoreAreaID"),CL3Variant(UNIT_ID_IRON_CACHE));

	CBSTR bstrCache = ::String_TChar2CBSTR(BFIronStoreOutCache_URI);
	CL3Variant valRet = InvokeObjectMethod(bstrCache,_T("AddMaterials"),L3RECORDSET(rsIron));
	if(!valRet.ToBOOL())
	{	
		return FALSE;
	}

    return TRUE;
}

/// <Method class="CMIF_Mag" name="SetIsDes" type="L3LONG">
/// �˹������Ƿ�����
/// </Method>
L3LONG CMIF_Mag::SetIsDes(L3RECORDSET rsIsDes)
{
	//modify by hyh 2012-04-12
	/*CL3RecordSetWrap rs = rsIsDes;
	if(rs.IsNull()||rs.GetRowCount()<1)
		return -1;

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		CString csMaterialID=rs.GetFieldByName(_T("MaterialID")).ToString();
		L3FLOAT fIsDes=rs.GetFieldByName(_T("IsDes")).ToFloat();

		if(csMaterialID==_T("")||(fIsDes!=0&&fIsDes!=-1))
		{
			Rollback(nTrans);
			return -1;
		}

		CString csIronUri = CL3NameParser::MergeClassDomainName(MATERIAL_IRON_URI,csMaterialID);
		if(!SetObjectPropValue(csIronUri,_T("IsDes"),(CL3Variant)fIsDes))
		{
			Rollback(nTrans);
			return -1;
		}

		rs.MoveNext();

	}
	Commit(nTrans);
	return 0;*/

	CL3RecordSetWrap rs = rsIsDes;
	if(rs.GetRowCount() < 1 || rs.IsNull())
		return -1;

	LONG nTrans = BeginTrans();
	if(nTrans < 1)
		return -1;

	//�齨���ݼ�
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsDes; pRS->QueryInterface(IID_IL3RecordSet,rsDes); pRS->Release();
	rsDes.AddField(_T("MaterialID"),VT_BSTR);
	rsDes.AddField(_T("ISDES"),VT_INT);
	

	rs.MoveFirst();
	while(!rs.IsEOF())
	{
		rsDes.AppendRecord();rsDes.MoveLast();
		rsDes.SetFieldByName(_T("MaterialID"),CL3Variant(rs.GetFieldByName(_T("MaterialID")).ToCString()));
		rsDes.SetFieldByName(_T("ISDES"),CL3Variant(rs.GetFieldByName(_T("ISDES")).ToCString()));
		rs.MoveNext();
	}
	rsDes.MoveFirst();
	if(!SetObjsPropValues(MATERIAL_IRON_URI,rsDes))
	{
		Rollback(nTrans);
			return -2;
	}

	Commit(nTrans);

	return 0;
	//end
}

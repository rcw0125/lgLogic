// �߼���CDispatch_Mag���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CDispatch_Mag.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CDispatch_Mag.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CDispatch_Mag.h"
#include "Material.h"
#include "MaterialMap.h"


//������װ�ص�ϵͳ��ʱ��������
void CDispatch_Mag::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CDispatch_Mag::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


/// <Method class="CDispatch_Mag" name="SteelTurnApp" type="L3BOOL">
/// 
/// ��ˮ��¯����
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID�ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
/// </Method>
L3BOOL CDispatch_Mag::SteelTurnApp(L3RECORDSET rsSteelTurnAppData)
{
	//���ݼ��
	CL3RecordSetWrap rsSteelData =rsSteelTurnAppData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return false;
	if(rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("SteelGradeIndex")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Time")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Steel_Weight")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Operator")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_UnitID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Reason")) < 0)
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	if(CreateNewObjects(DISPATCH_STEEL_TURN_CLASS_URI,rsSteelTurnAppData) < rsSteelData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	
	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ
	CL3Variant varEvent = GetPropValue(_T("SteelReturnAppEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("SteelReturnAppEvent"),nEvent);

	return true;

}
/// <Method class="CDispatch_Mag" name="SteelTurn" type="L3BOOL">
/// 
/// ��ˮ��¯
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������GUID\PreHeatID\All_Turn_Flag�����ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
/// </Method>
L3LONG CDispatch_Mag::SteelTurn(L3RECORDSET rsSteelTurnData)
{
	//���ݼ��
	CL3RecordSetWrap rsSteelData =rsSteelTurnData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return -1;
	if(rsSteelData.GetFieldIndex(_T("GUID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("All_Turn_Flag")) < 0)
		return -1;
	//���ݽ���
	rsSteelData.MoveFirst();
	CL3Variant valTemp = rsSteelData.GetFieldByName(_T("GUID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csObjectID = valTemp.ToCString();

	CString csURi= DISPATCH_STEEL_TURN_CLASS_URI + _T("\\") + csObjectID;
	L3LONG nTurnFlag =  GetObjectPropValue(csURi,_T("Turn_Flag")).ToLong();
	if(nTurnFlag) return -4;

	valTemp = rsSteelData.GetFieldByName(_T("PreHeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csPreHeatID = valTemp.ToCString();

	valTemp = rsSteelData.GetFieldByName(_T("All_Turn_Flag"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3LONG nAllTurnFlag = valTemp.ToLong();

	valTemp = rsSteelData.GetFieldByName(_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csHeatID = valTemp.ToCString();
	
	valTemp =  rsSteelData.GetFieldByName(_T("App_UnitID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString  csAppUnit = valTemp.ToCString();

	valTemp =  rsSteelData.GetFieldByName(_T("App_Steel_Weight"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3DOUBLE  fWeight = valTemp.ToDouble();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -1;
	}

	// �����߼�����ֻ���������� 2009-04-27
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -1;
	}

	//�������뵥��Ӧ��Ϣ
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	
	if(!SetObjectPropValue(csURi,_T("Turn_Time"),CL3Variant(timeNow)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}
	if(!SetObjectPropValue(csURi,_T("Turn_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}
	if(!SetObjectPropValue(csURi,_T("Turn_Operator"),CL3Variant(csUser)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}
	//��ΰ��
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rpSysInfo.MoveFirst();
	if(!SetObjectPropValue(csURi,_T("Shift"),rpSysInfo.GetFieldByName(_T("ShiftID"))))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}
	if(!SetObjectPropValue(csURi,_T("Team"),rpSysInfo.GetFieldByName(_T("TeamID"))))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	//���ļƻ���Ϣ
	CString csPlanURi = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	if(!SetObjectPropValue(csPlanURi,_T("Steel_Return_Flag"),L3LONG(1))) 
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	//�ж��Ƿ�ȫ��¯
	//if(nAllTurnFlag)
	//{
	if(!SetObjectPropValue(csPlanURi,_T("Status"),CL3Variant(TAPPING_PLAN_STATUS_EXCUTED)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	if(!SetObjectPropValue(csURi,_T("All_Turn_Flag"),CL3Variant(nAllTurnFlag)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	L3LONG nRet = SteelAllReturn(csPlanURi,csAppUnit,csHeatID,fWeight);
	if(nRet < 0)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return nRet;
	}
	//}

	if(bUseTrans)
		Commit(nTrans);

	//�޸ĸְ�״̬2009-03-03 tangyi
	CString csSteelUri = MATERIAL_STEEL_URI + _T("\\") + csHeatID;
	CString csLadleID = GetObjectPropValue(csSteelUri,_T("LadleID")).ToCString();
	CString csLadleUri = CLADLE_BASE_URI + _T("\\") + csLadleID;
	SetObjectPropValue(csLadleUri,_T("Status"),CL3Variant(CLADLE_STATUS_HOT));

	//֪ͨͨѶ��NC����ȫ��¯����2009-03-22
	CString csBaseUri = _T("XGMESLogic\\BaseDataMag\\CBaseData_Mag\\BaseData_Mag");
	CL3Variant varEvent = GetObjectPropValue(csBaseUri,_T("NC_Steel_Back_Event"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetObjectPropValue(csBaseUri,_T("NC_Steel_Back_Event"),nEvent);

	InvokeObjectMethod(PLAN_OBJ_URI,_T("ChangeRsTappingPlanValue"));

	return 0;// TODO : ���ڴ�����߼�����
}

/// <Method class="CDispatch_Mag" name="SteelBackApp" type="L3BOOL">
/// 
/// ��ˮ��������
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID�ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
/// </Method>
L3BOOL CDispatch_Mag::SteelBackApp(L3RECORDSET rsSteelBackAppData)
{
	//���ݼ��
	CL3RecordSetWrap rsSteelData =rsSteelBackAppData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return false;
	if(rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("SteelGradeIndex")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Time")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Steel_Weight")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Operator")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_UnitID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Reason")) < 0)
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	if(CreateNewObjects(DISPATCH_STEEL_BACK_CLASS_URI,rsSteelBackAppData) < rsSteelData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	
	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ
	CL3Variant varEvent = GetPropValue(_T("SteelBackAppEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("SteelBackAppEvent"),nEvent);

	return true;

}

/// <Method class="CDispatch_Mag" name="SteelBack" type="L3BOOL">
/// 
/// ��ˮ����
/// ARG&gt;&gt; rsSteelBackData :��ˮ������Ϣ,�������GUID\PreHeatID\BackUnitIDType\HeatID �����ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsSteelBackData" type="L3RECORDSET">��ˮ������Ϣ</Param>
/// </Method>
L3LONG CDispatch_Mag::SteelBack(L3RECORDSET rsSteelBackData)
{
	//���ݼ��
	CL3RecordSetWrap rsSteelData =rsSteelBackData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return -1;
	if(rsSteelData.GetFieldIndex(_T("GUID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("Back_UnitID_Type")) < 0)
		return -1;
	//���ݽ���
	rsSteelData.MoveFirst();
	CL3Variant valTemp = rsSteelData.GetFieldByName(_T("GUID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csObjectID = valTemp.ToCString();

	CString csObjURi= DISPATCH_STEEL_BACK_CLASS_URI + _T("\\") + csObjectID;
	L3LONG nBackFlag =  GetObjectPropValue(csObjURi,_T("Back_Flag")).ToLong();
	if(nBackFlag) return -10;

	valTemp = rsSteelData.GetFieldByName(_T("PreHeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csPreHeatID = valTemp.ToCString();

	valTemp = rsSteelData.GetFieldByName(_T("Back_UnitID_Type"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3LONG nBackUnit = valTemp.ToLong();

	valTemp = rsSteelData.GetFieldByName(_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csHeatID = valTemp.ToCString();
	
	valTemp =  rsSteelData.GetFieldByName(_T("App_UnitID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString  csAppUnit = valTemp.ToCString();

	//���ݷ��͹����ж����빤���Ƿ���
	L3LONG nAppUnit = _ttol(csAppUnit.Mid(1,1));
	CString csTappingPlanURi = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	L3SHORT nStatus =0;
	switch (nAppUnit)
	{
		case UNIT_AREA_CASTER://����ֻ�е���������
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("Caster_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus != 2)
                    return -2;
			break;
		case UNIT_AREA_RH://RH����δ��վ��������
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("RH_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				//if(nStatus < 3)
				if(nStatus < 5) //2009-02-16 tangyi
					return -3;
			break;
		case UNIT_AREA_LF://LF����δ��վ��������
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("LF_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 5) //2009-02-16 tangyi
					return -4;
			break;
		default:
			 return -5;//�������빤�򲻺Ϸ�
	}

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -6;
	}

	// �����߼�����ֻ���������� 2009-04-27
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -6;
	}

	//L3LONG nBackUnit = _ttol(csBackUnit.Mid(1,1));
	L3LONG nRet =0;
	CString csUnitID;
	switch(nBackUnit)
	{
		case UNIT_AREA_RH:
				nRet = SteelMoveInCache(csTappingPlanURi,UNIT_AREA_RH,csHeatID,csUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_LF:
				nRet = SteelMoveInCache(csTappingPlanURi,UNIT_AREA_LF,csHeatID,csUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_TAPSIDE:
				nRet = SteelMoveInCache(csTappingPlanURi,UNIT_AREA_TAPSIDE,csHeatID,csUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		default:
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -7;//����Ŀ�깤�򲻺Ϸ�
				}
	}
	//�������뵥��Ӧ��Ϣ
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	
	if(!SetObjectPropValue(csObjURi,_T("Back_Time"),CL3Variant(timeNow)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	if(!SetObjectPropValue(csObjURi,_T("Back_UnitID"),CL3Variant(csUnitID)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	if(!SetObjectPropValue(csObjURi,_T("Back_Operator"),CL3Variant(csUser)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	if(!SetObjectPropValue(csObjURi,_T("Back_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	//���ļƻ���Ϣ
	if(!SetObjectPropValue(csTappingPlanURi,_T("Steel_Back_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -9;
	}

	if(bUseTrans)
		Commit(nTrans);

	InvokeObjectMethod(PLAN_OBJ_URI,_T("ChangeRsTappingPlanValue"));

	return 0;// TODO : ���ڴ�����߼�����
}

/// <Method class="CDispatch_Mag" name="SteelDivApp" type="L3BOOL">
/// 
/// ��ˮ¯�ηָ�����
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID�ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
/// </Method>
L3BOOL CDispatch_Mag::SteelDivApp(L3RECORDSET rsSteelDivAppData)
{
	//���ݼ��
	CL3RecordSetWrap rsSteelData =rsSteelDivAppData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return false;
	if(rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("SteelGradeIndex")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Time")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Steel_Weight")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Operator")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_UnitID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Reason")) < 0)
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	if(CreateNewObjects(DISPATCH_STEEL_DIV_CLASS_URI,rsSteelDivAppData) < rsSteelData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	
	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ
	CL3Variant varEvent = GetPropValue(_T("SteelDivAppEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("SteelDivAppEvent"),nEvent);

	return true;

}

/// <Method class="CDispatch_Mag" name="SteelDiv" type="L3BOOL">
/// 
/// ��ˮ�ָ�
/// ARG&gt;&gt; strPreHeatID :Ԥ��¯��
///        &gt;&gt; strBackUnit:   ���͹�λ
///        &gt;&gt;strObjName:������
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="strPreHeatID" type="L3STRING">Ԥ��¯��</Param>
/// <Param name="strBackUnit" type="L3STRING">���͹�λ</Param>
/// <Param name="strObjName" type="L3STRING">Ԥ��¯��</Param>
/// </Method>
L3LONG CDispatch_Mag::SteelDiv(L3RECORDSET rsSteelDiv)
{
	//���ݼ��
	CL3RecordSetWrap rsSteelData =rsSteelDiv;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return -1;
	if(rsSteelData.GetFieldIndex(_T("GUID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("Back_UnitID_Type")) < 0)
		return -1;
	//���ݽ���
	rsSteelData.MoveFirst();
	CL3Variant valTemp = rsSteelData.GetFieldByName(_T("GUID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csObjectID = valTemp.ToCString();

	CString csObjURi= DISPATCH_STEEL_DIV_CLASS_URI + _T("\\") + csObjectID;
	L3LONG nDivFlag =  GetObjectPropValue(csObjURi,_T("Div_Flag")).ToLong();
	if(nDivFlag) return -14;

	valTemp = rsSteelData.GetFieldByName(_T("PreHeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csPreHeatID = valTemp.ToCString();

	valTemp = rsSteelData.GetFieldByName(_T("Back_UnitID_Type"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3LONG nBackUnit = valTemp.ToLong();

	valTemp = rsSteelData.GetFieldByName(_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csHeatID = valTemp.ToCString();
	
	valTemp =  rsSteelData.GetFieldByName(_T("App_UnitID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString  csAppUnit = valTemp.ToCString();

	valTemp =  rsSteelData.GetFieldByName(_T("App_Steel_Weight"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	L3DOUBLE  fWeight = valTemp.ToDouble();

	//���ݷ��͹����ж����빤���Ƿ�Ϸ�
	L3LONG nAppUnit = _ttol(csAppUnit.Mid(1,1));
	CString csTappingPlanURi = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	L3SHORT nStatus =0;
	switch (nAppUnit)
	{
		case UNIT_AREA_CASTER://����ֻ�п�������ָ�
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("Caster_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 3)
                    return -2;
			break;
		default:
			 return -3;//�ָ����빤�򲻺Ϸ�
	}
	
	//�°�¯������
	CString csHeatTreat = csHeatID.Mid(4,5);
	CString csYear = csHeatID.Mid(0,4);
	L3LONG nHeatTreat = _ttol(csHeatTreat);
	nHeatTreat = nHeatTreat + 90000;
	CString csDivHeatID;
	csDivHeatID.Format(_T("%05d"),nHeatTreat);
	csDivHeatID = csYear + csDivHeatID;
	//���������°�¯��Ϣ
	CL3RecordSetWrap rsDivSteelData;
	if(!CreateClassPropSet(MATERIAL_STEEL_URI,rsDivSteelData))
		return -4;
	//ɾ�������ֶ�
	rsDivSteelData.DelField(_T("GUID"));
	rsDivSteelData.DelField(_T("Name"));
	//��ȡĸ¯��Ϣ
	CL3RecordSetWrap rsData;
	CString csSQL;
	csSQL.Format(_T("select * from %s where MaterialID ='%s'"),MATERIAL_STEEL_URI,csHeatID);
	if(!Query(csSQL,rsData)||rsData.IsNull()||rsData.GetRowCount() <1)
		return -5;
	rsData.MoveFirst();
	rsDivSteelData.AppendRecord();
	rsDivSteelData.CopyCurRowFrom(rsData);
	//�޸�������¯��
	rsDivSteelData.SetFieldByName(_T("Weight"),CL3Variant(fWeight));
	rsDivSteelData.SetFieldByName(_T("MaterialID"),CL3Variant(csDivHeatID));
	rsDivSteelData.SetFieldByName(_T("HeatID"),CL3Variant(csDivHeatID));
	//�����ϰ�¯����
	L3DOUBLE fOldWeight = rsData.GetFieldByName(_T("Weight")).ToDouble();
	fOldWeight -= fWeight;
	//�������϶��ձ�
	CL3RecordSetWrap rsMaterialMap;
	if(!CreateClassPropSet(_T("MES\\MaterialData\\MaterialMap"),rsMaterialMap))
		return -6;
	rsMaterialMap.AppendRecord();//�ϰ�¯
	rsMaterialMap.SetFieldByName(_T("FromType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("FromID"),CL3Variant(csHeatID));
	rsMaterialMap.SetFieldByName(_T("ToType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("ToID"),CL3Variant(csHeatID));
	rsMaterialMap.SetFieldByName(_T("Mode"),CL3Variant(L3LONG(MaterialMap::Split)));
	rsMaterialMap.SetFieldByName(_T("Mapper"),CL3Variant(csAppUnit));
	rsMaterialMap.SetFieldByName(_T("SrcAmount"),rsData.GetFieldByName(_T("Weight")));
	rsMaterialMap.SetFieldByName(_T("TgtAmount"),CL3Variant(fOldWeight));
	rsMaterialMap.AppendRecord();//�°�¯
	rsMaterialMap.SetFieldByName(_T("FromType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("FromID"),CL3Variant(csHeatID));
	rsMaterialMap.SetFieldByName(_T("ToType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("ToID"),CL3Variant(csDivHeatID));
	rsMaterialMap.SetFieldByName(_T("Mode"),CL3Variant(L3LONG(MaterialMap::Split)));
	rsMaterialMap.SetFieldByName(_T("Mapper"),CL3Variant(csAppUnit));
	rsMaterialMap.SetFieldByName(_T("SrcAmount"),rsData.GetFieldByName(_T("Weight")));
	rsMaterialMap.SetFieldByName(_T("TgtAmount"),CL3Variant(fWeight));

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -7;
	}

	// �����߼�����ֻ���������� 2009-04-27
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -7;
	}

	rsMaterialMap.MoveFirst();

	if(CreateNewObjects(_T("MES\\MaterialData\\MaterialMap"),(L3RECORDSET)rsMaterialMap) < 2)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -8;
	}
	if(CreateNewObjects(MATERIAL_STEEL_URI,(L3RECORDSET)rsDivSteelData) < 1)
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -9;
	}
	CString csSteelUri = MATERIAL_STEEL_URI + _T("\\") + csHeatID;
	if(!SetObjectPropValue(csSteelUri,_T("Weight"),CL3Variant(fOldWeight)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -10;
	}
	//����°�¯����Ϣ����Ӧ�Ļ���
	L3LONG nRet =0;
	CString csDivUnitID;
	switch(nBackUnit)
	{
		case UNIT_AREA_CASTER:
				nRet = AddSteelToSpeciCache(csTappingPlanURi,UNIT_AREA_CASTER,csDivHeatID,csDivUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_RH:
				nRet = AddSteelToSpeciCache(csTappingPlanURi,UNIT_AREA_RH,csDivHeatID,csDivUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_LF:
				nRet = AddSteelToSpeciCache(csTappingPlanURi,UNIT_AREA_LF,csDivHeatID,csDivUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		case UNIT_AREA_TAPSIDE:
				nRet = AddSteelToSpeciCache(csTappingPlanURi,UNIT_AREA_TAPSIDE,csDivHeatID,csDivUnitID);
				if(nRet<0) 
				{
					if(bUseTrans)
						Rollback(nTrans);
					return nRet;
				}
				break;
		default:
				{
					if(bUseTrans)
						Rollback(nTrans);
					return -13;//����Ŀ�깤�򲻺Ϸ�
				}
	}
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	if(!SetObjectPropValue(csObjURi,_T("Div_Time"),CL3Variant(timeNow)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -11;
	}
	if(!SetObjectPropValue(csObjURi,_T("Div_UnitID"),CL3Variant(csDivUnitID)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -11;
	}
	if(!SetObjectPropValue(csObjURi,_T("Div_Operator"),CL3Variant(csUser)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -11;
	}
	if(!SetObjectPropValue(csObjURi,_T("Div_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -11;
	}
	//���ļƻ���Ϣ
	if(!SetObjectPropValue(csTappingPlanURi,_T("Div_HeatID"),CL3Variant(csDivHeatID)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -12;
	}

	if(bUseTrans)
		Commit(nTrans);

	InvokeObjectMethod(PLAN_OBJ_URI,_T("ChangeRsTappingPlanValue"));

	return 0;// TODO : ���ڴ�����߼�����
}

/// <Method class="CDispatch_Mag" name="SteelExchangeApp" type="L3BOOL">
/// 
/// ��ˮ�ĸ�����
/// ARG&gt;&gt; 
/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID�ֶ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
/// </Method>
L3BOOL CDispatch_Mag::SteelExchangeApp(L3RECORDSET rsSteelExchangeAppData)
{
	//���ݼ��
	CL3RecordSetWrap rsSteelData =rsSteelExchangeAppData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return false;
	if(rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("SteelGradeIndex")) < 0 ||
	rsSteelData.GetFieldIndex(_T("HeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Time")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Steel_Weight")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Operator")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_UnitID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("App_Reason")) < 0)
		return false;

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return false;
	}

	if(CreateNewObjects(DISPATCH_STEEL_EXE_CLASS_URI,rsSteelExchangeAppData) < rsSteelData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return false;
	}
	
	if(bUseTrans)
		Commit(nTrans);

	//�ı�����ֵ
	CL3Variant varEvent = GetPropValue(_T("SteelExchangeAppEvent"));
	L3LONG nEvent = varEvent.ToLong();
	nEvent = (nEvent+1) % 9999;
	SetPropValue(_T("SteelExchangeAppEvent"),nEvent);

	return true;

}

/// <Method class="CDispatch_Mag" name="SteelExchange" type="L3BOOL">
/// 
/// ��ˮ�ĸ�
/// ARG &gt;&gt; 
///     &gt;&gt;rsExchangeData���ĸ����ݼ��������GUID\PreHeatID\Ex_SteelGradeIndex�����ֶ�
/// RET &lt;&lt; �ɹ�����0��ʧ�ܷ���code��
/// <Param name="rsExchangeData" type="L3RECORDSET">���ݼ�</Param>
/// </Method>
L3LONG CDispatch_Mag::SteelExchange(L3RECORDSET rsExchangeData)
{
	//���ݼ��
	CL3RecordSetWrap rsSteelData =rsExchangeData;
	if( rsSteelData.IsNull() || rsSteelData.GetRowCount() < 1)
		return -1;
	if(rsSteelData.GetFieldIndex(_T("GUID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("PreHeatID")) < 0 ||
	rsSteelData.GetFieldIndex(_T("Ex_SteelGradeIndex")) < 0)
		return -1;
	//���ݽ���
	rsSteelData.MoveFirst();
	CL3Variant valTemp = rsSteelData.GetFieldByName(_T("GUID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csObjectID = valTemp.ToCString();

	
	CString csObjURi= DISPATCH_STEEL_EXE_CLASS_URI + _T("\\") + csObjectID;
	L3LONG nExFlag =  GetObjectPropValue(csObjURi,_T("Ex_Flag")).ToLong();
	if(nExFlag) return -5;

	valTemp = rsSteelData.GetFieldByName(_T("PreHeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csPreHeatID = valTemp.ToCString();

	valTemp = rsSteelData.GetFieldByName(_T("Ex_SteelGradeIndex"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return -1;
	CString csSteelGrade = valTemp.ToCString();

	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return -2;
	}

	// �����߼�����ֻ���������� 2009-04-27
	if(!PutObjectIntoTrans(GetURI()))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;
	}

	//�������뵥��Ӧ��Ϣ
	COleDateTime timeNow = COleDateTime::GetCurrentTime();
	CString csUser = GetCurrentUser();
	
	if(!SetObjectPropValue(csObjURi,_T("Ex_Time"),CL3Variant(timeNow)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	if(!SetObjectPropValue(csObjURi,_T("Ex_SteelGradeIndex"),CL3Variant(csSteelGrade)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	if(!SetObjectPropValue(csObjURi,_T("Ex_Operator"),CL3Variant(csUser)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	if(!SetObjectPropValue(csObjURi,_T("Ex_Flag"),L3LONG(1)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;
	}
	//���ļƻ���Ϣ
	CString csUri = PLAN_TAPPING_CLASS_URI + _T("\\") + csPreHeatID;
	if(!SetObjectPropValue(csUri,_T("SteelGradeIndex"),CL3Variant(csSteelGrade)))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}
	//��ȡ¯��
	valTemp = GetObjectPropValue(csUri,_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -4;
	}
	CString csHeatID = valTemp.ToCString();
	L3STRING strHeatID = csHeatID.AllocSysString();
	//���ĸ�ˮ��Ϣ�������Ϣ
	valTemp = InvokeObjectMethod(PLAN_OBJ_URI,_T("ModifyUnitSteelGradeIndex"),strHeatID);
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull() || valTemp.ToLong() < 0)
	{
		L3SysFreeString(strHeatID);
		if(bUseTrans)
			Rollback(nTrans);
		return valTemp.ToLong();
	}
	L3SysFreeString(strHeatID);

	if(bUseTrans)
		Commit(nTrans);

	InvokeObjectMethod(PLAN_OBJ_URI,_T("ChangeRsTappingPlanValue"));

	return 0;// TODO : ���ڴ�����߼�����
}

/// <Method class="CDispatch_Mag" name="DispatchLog" type="L3BOOL">
/// 
/// ���ȼ���
/// ARG&gt;&gt; rsData:���ݼ�
/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// <Param name="rsData" type="L3RECORDSET">����</Param>
/// </Method>
L3BOOL CDispatch_Mag::DispatchLog(L3RECORDSET rsData)
{
	CL3RecordSetWrap rsLogData =rsData;
	if( rsLogData.IsNull() || rsLogData.GetRowCount() < 1)
		return false;
	CL3Variant valR = InvokeObjectMethod(SHIFT_MAG_URI,_T("GetSessionShiftTeam"));
	CL3RecordSetWrap rpSysInfo;
	SUCCEEDED(valR.QueryInterface(IID_IL3RecordSet,rpSysInfo));
	rsLogData.MoveFirst();
	while(!rsLogData.IsEOF())
	{
		rsLogData.SetFieldByName(_T("ShiftID"),rpSysInfo.GetFieldByName(_T("ShiftID")));
		rsLogData.SetFieldByName(_T("TeamID"),rpSysInfo.GetFieldByName(_T("TeamID")));
		rsLogData.SetFieldByName(_T("CreateDate"),COleDateTime::GetCurrentTime());
		rsLogData.MoveNext();
	}

	if(CreateNewObjects(DISPATCH_LOG_CLASS_URI,rsData) <  rsLogData.GetRowCount())
		return false;

	return true;// TODO : ���ڴ�����߼�����
}

/// <Method class="CDispatch_Mag" name="GetBOFRealData" type="L3RECORDSET">
/// 
/// ��ȡת¯ʵʱ����
/// ARG&gt;&gt;strBOFID:ת¯����
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CDispatch_Mag::GetBOFRealData(L3STRING strBOFID)
{
	//��ȡת¯��ǰ¯��
	//CString csBOFID = strBOFID;
	//CString csObjUri = BOF_CLASS_URI + _T("\\") + csBOFID;
	//CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("HeatID"));
	//if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
	//	return NULL;
	//CString csHeatID = valTemp.ToCString();
	//CString csTemp = _T(" select a.HeatID,a.SteelGradeIndex,a.PreHeatID,a.ProductionDate   ");
	//		csTemp+= _T(" b.IronWeight,b.ScrapWeight,b.PigIronWeight,b.ReHeatAmount        ");
	//		csTemp+= _T(" c.Status,c.LanceAge,c.FurnaceAge,c.Campaign                      ");
	//		csTemp+= _T(" from %s a,%s b,% c where a.HeatID ='%s' and a.HeatID =b.HeatID   ");
	//		csTemp+= _T(" and a.HeatID = c.HeatID ");
	//CString csSQL;
	//csSQL.Format(csTemp,BOF_BASE_DATA_CLASS_URI,BOF_FEED_CLASS_URI,BOF_CLASS_URI,csHeatID);
	//CL3RecordSetWrap rsSteelData;
	//if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	//else
	//	return rsSteelData.Detach();
}


/// <Method class="CDispatch_Mag" name="GetBOFSideRealData" type="L3RECORDSET">
/// 
/// ��ȡ¯��ʵʱ����
/// ARG&gt;&gt;strBOFID:ת¯����
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CDispatch_Mag::GetBOFSideRealData(L3STRING strBOFID)
{
	//��ȡת¯��ǰ¯��
	CString csBOFID = strBOFID;
	CString csObjUri = BOF_SIDE_CLASS_URI + _T("\\") + csBOFID;
	CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return NULL;
	CString csHeatID = valTemp.ToCString();

	CString csTemp = _T(" select a.HeatID,a.SteelGradeIndex,a.PreHeatID,a.LadleNo,a.ProductionDate ");
			csTemp+= _T(" b.Status,                                                        ");
			csTemp+= _T(" from %s a,%s b where a.HeatID ='%s' and a.HeatID =b.HeatID   ");

	CString csSQL;
	csSQL.Format(csTemp,TAP_BASE_DATA_CLASS_URI,BOF_SIDE_CLASS_URI,csHeatID);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	else
		return rsSteelData.Detach();
}


/// <Method class="CDispatch_Mag" name="GetFactoryEnergyData" type="">
/// </Method>
L3RECORDSET CDispatch_Mag::GetFactoryEnergyData()
{
	return NULL;// TODO : ���ڴ�����߼�����
}


/// <Method class="CDispatch_Mag" name="Get1LFRealData" type="">
/// 
/// ��ȡ1#LF¯ʵʱ����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CDispatch_Mag::GetLFRealData(L3STRING strLFID)
{
	//��ȡת¯��ǰ¯��
	CString csLFID = strLFID;
	CString csObjUri = LF_CLASS_URI + _T("\\") + csLFID;
	CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("TreatNo"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return NULL;
	CString csTreatNo = valTemp.ToCString();

	CString csTemp = _T(" select a.TreatNo, a.HeatID,a.PreHeatID,a.SteelGradeIndex,a.LadleNo,a.ProductionDate ");
			csTemp+= _T(" b.Status,                                                          ");
			csTemp+= _T(" from %s a,% b where a.TreatNo ='%s' and a.TreatNo =b.TreatNo       ");

	CString csSQL;
	csSQL.Format(csTemp,LF_BASE_DATA_CLASS_URI,LF_CLASS_URI,csTreatNo);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	else
		return rsSteelData.Detach();
}


/// <Method class="CDispatch_Mag" name="Get1RHRealData" type="">
/// 
/// ��ȡ1#RH¯ʵʱ����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CDispatch_Mag::GetRHRealData(L3STRING strRHID)
{
	//��ȡת¯��ǰ¯��
	CString csRHID = strRHID;
	CString csObjUri = RH_CLASS_URI + _T("\\") + csRHID;
	CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("TreatNo"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return NULL;
	CString csTreatNo = valTemp.ToCString();

	CString csTemp = _T(" select a.TreatNo, a.HeatID,a.PreHeatID,a.SteelGradeIndex,a.LadleNo,a.ProductionDate ");
			csTemp+= _T(" b.Status,                                                          ");
			csTemp+= _T(" from %s a,% b where a.TreatNo ='%s' and a.TreatNo =b.TreatNo       ");

	CString csSQL;
	csSQL.Format(csTemp,RH_BASE_DATA_CLASS_URI,RH_CLASS_URI,csTreatNo);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	else
		return rsSteelData.Detach();
}

/// <Method class="CDispatch_Mag" name="Get1CasterRealData" type="">
/// 
/// ��ȡ����ʵʱ����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CDispatch_Mag::GetCasterRealData(L3STRING strCasterID)
{
	//��ȡת¯��ǰ¯��
	CString csCasterID = strCasterID;
	CString csObjUri = CCM_CLASS_URI + _T("\\") + csCasterID;
	CL3Variant valTemp = GetObjectPropValue(csObjUri,_T("HeatID"));
	if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
		return NULL;
	CString csHeatID = valTemp.ToCString();

	CString csTemp = _T(" select a.TreatNo, a.HeatID,a.PreHeatID,a.SteelGradeIndex,a.LadleNo,a.ProductionDate         ");
			csTemp+= _T(" b.Status,b.Ladle_Weight,b.Tundish_Weight,b.Tundish_SeqNo,b.Casting_HeatNum,b.Tundish_HeatNum ");
			csTemp+= _T(" from %s a,% b where a.HeatID ='%s' and a.HeatID =b.HeatID                                    ");

	CString csSQL;
	csSQL.Format(csTemp,CCM_BASE_DATA_CLASS_URI,CCM_CLASS_URI,csHeatID);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull()||rsSteelData.GetRowCount() < 1)
		return NULL;
	else
		return rsSteelData.Detach();
}



/// <Method class="CDispatch_Mag" name="GetAlloyStoreData" type="">
/// 
/// ��ȡ�Ͻ�ԭ�Ͽ�����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CDispatch_Mag::GetAlloyStoreData()
{
	return NULL;// TODO : ���ڴ�����߼�����
}

/// <Method class="CDispatch_Mag" name="GetScrapStoreData" type="">
/// 
/// ��ȡ2#¯ʵʱ����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CDispatch_Mag::GetScrapStoreData()
{
	return NULL;// TODO : ���ڴ�����߼�����
}

/// <Method class="CDispatch_Mag" name="GetBloomStoreData" type="">
/// 
/// ��ȡ2#¯ʵʱ����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CDispatch_Mag::GetBloomStoreData()
{
	return NULL;// TODO : ���ڴ�����߼�����
}

/// <Method class="CDispatch_Mag" name="GetBulkStoreData" type="">
/// 
/// ��ȡ2#¯ʵʱ����
/// ARG&gt;&gt; 
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3RECORDSET CDispatch_Mag::GetBulkStoreData()
{
	return NULL;// TODO : ���ڴ�����߼�����
}

/// <Method class="CDispatch_Mag" name="GetCurSteelBackInfor" type="DATASET">
/// 
/// ��ȡδ����ְ�����������Ϣ
/// ARG 
/// RET &gt;&gt; �ҵ��ĸְ�����������Ϣ��¼����
/// </Method>
L3RECORDSET CDispatch_Mag::GetCurSteelBackInfor()
{
	//CString csTemp = _T(" select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) or (App_Time < (select TRUNC(SYSDATE) from dual) and Back_Flag = 0)  ");

	CString csTemp = _T(" select * from (select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
			csTemp +=_T(" union                                                                               ");
			csTemp +=_T(" select * from                                                                       ");
			csTemp +=_T(" (select * from %s where App_Time <  (select TRUNC(SYSDATE) from dual)               ");
			csTemp +=_T("  and Back_Flag = 0 order by App_Time desc)  where rownum < 5 )                       ");
			csTemp +=_T(" order by Back_Flag asc ,App_Time desc                                                ");

	CString csSQL;
	csSQL.Format(csTemp,DISPATCH_STEEL_BACK_CLASS_URI,DISPATCH_STEEL_BACK_CLASS_URI);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull())
		return NULL;
	else
		return rsSteelData.Detach();

}

/// <Method class="CDispatch_Mag" name="GetCurSteelTurnInfor" type="DATASET">
/// 
/// ��ȡδ����ְ���¯������Ϣ
/// ARG 
/// RET &gt;&gt; �ҵ��ĸְ���¯������Ϣ��¼����
/// </Method>
L3RECORDSET CDispatch_Mag::GetCurSteelTurnInfor()
{
	//CString csTemp = _T(" select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
	//		csTemp +=_T(" or (App_Time < (select TRUNC(SYSDATE) from dual) and Turn_Flag = 0)  ");
	//		csTemp +=_T(" order by Turn_Flag asc ,App_Time desc                                ");

	CString csTemp = _T(" select * from (select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
			csTemp +=_T(" union                                                                               ");
			csTemp +=_T(" select * from                                                                       ");
			csTemp +=_T(" (select * from %s where App_Time <  (select TRUNC(SYSDATE) from dual)               ");
			csTemp +=_T("  and Turn_Flag = 0 order by App_Time desc)  where rownum < 5 )                      ");
			csTemp +=_T(" order by Turn_Flag asc ,App_Time desc                                               ");

	CString csSQL;
	csSQL.Format(csTemp,DISPATCH_STEEL_TURN_CLASS_URI,DISPATCH_STEEL_TURN_CLASS_URI);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull())
		return NULL;
	else
		return rsSteelData.Detach();

}

/// <Method class="CDispatch_Mag" name="GetCurSteelDivInfor" type="DATASET">
/// 
/// ��ȡδ����ְ�¯�ηָ�������Ϣ
/// ARG 
/// RET &gt;&gt; �ҵ��ĸְ���¯¯�ηָ���Ϣ��¼����
/// </Method>
L3RECORDSET CDispatch_Mag::GetCurSteelDivInfor()
{
	//CString csTemp = _T(" select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) or (App_Time < (select TRUNC(SYSDATE) from dual) and Div_Flag = 0)  ");

	CString csTemp = _T(" select * from (select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
			csTemp +=_T(" union                                                                               ");
			csTemp +=_T(" select * from                                                                       ");
			csTemp +=_T(" (select * from %s where App_Time <  (select TRUNC(SYSDATE) from dual)               ");
			csTemp +=_T("  and Div_Flag = 0 order by App_Time desc)  where rownum < 5 )                       ");
			csTemp +=_T(" order by Div_Flag asc ,App_Time desc                                                ");

	CString csSQL;
	csSQL.Format(csTemp,DISPATCH_STEEL_DIV_CLASS_URI,DISPATCH_STEEL_DIV_CLASS_URI);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull())
		return NULL;
	else
		return rsSteelData.Detach();
}

/// <Method class="CDispatch_Mag" name="GetCurSteelExInfor" type="DATASET">
/// 
/// ��ȡδ����ĸ�������Ϣ
/// ARG 
/// RET &gt;&gt; �ҵ��ĸĸ������¼����
/// </Method>
L3RECORDSET CDispatch_Mag::GetCurSteelExInfor()
{
	//CString csTemp = _T(" select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) or (App_Time < (select TRUNC(SYSDATE) from dual) and Ex_Flag = 0)  ");
	CString csTemp = _T(" select * from (select * from %s where App_Time >= (select TRUNC(SYSDATE) from dual) ");
			csTemp +=_T(" union                                                                               ");
			csTemp +=_T(" select * from                                                                       ");
			csTemp +=_T(" (select * from %s where App_Time <  (select TRUNC(SYSDATE) from dual)               ");
			csTemp +=_T("  and Ex_Flag = 0 order by App_Time desc)  where rownum < 5 )                       ");
			csTemp +=_T(" order by Ex_Flag asc ,App_Time desc                                                ");
	CString csSQL;
	csSQL.Format(csTemp,DISPATCH_STEEL_EXE_CLASS_URI,DISPATCH_STEEL_EXE_CLASS_URI);
	CL3RecordSetWrap rsSteelData;
	if(!Query(csSQL,rsSteelData)||rsSteelData.IsNull())
		return NULL;
	else
		return rsSteelData.Detach();
}

/// <Method class="CDispatch_Mag" name="GetCurSteelCache" type="DATASET">
/// 
/// ��ȡ��ˮ��ǰ���ڻ���URi
/// ARG csHeatID��¯��
/// RET &gt;&gt; �ҵ���URi
/// </Method>
CString CDispatch_Mag::GetCurSteelCache(CString csHeatID)
{
	//��ȡ���ϵ�ǰ��ˮcache
	CString csTemp;
	csTemp.Format(_T("select Position from %s where MaterialID = '%s' and MaterialType = '%s'"),MES_MATERIAL_POSITION,csHeatID,MATERIAL_TYPE_STEEL);
	CL3RecordSetWrap rsPosition;
	if(!Query(csTemp,rsPosition) || rsPosition.IsNull())
		return _T("");
	rsPosition.MoveFirst();
	CString csCache = rsPosition.GetFieldByName(_T("Position")).ToCString();
	CString csIsOk = csCache.Mid(3,1);
	CString csIsCaster = csCache.Mid(3,3);
	if(csIsOk != _T("P") && csIsCaster != _T("A01"))
		return _T("");
	CString csCacheUri;
	if(csIsOk == _T("P"))
		csCacheUri = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\") + csCache;
	else
		csCacheUri = _T("XGMESLogic\\CCMMag\\CCCM_Prod_Area\\") + csCache;
	return csCacheUri;

}


/// <Method class="CDispatch_Mag" name="SteelMoveInCache" type="L3LONG">
/// 
/// �ڹ��򻺴����ƶ���ˮ
/// ARG&gt;&gt; csTappingPlanURi�����ּƻ�URI
///  &gt;&gt; nUnitType��Ŀ�깤��
///  &gt;&gt; csHeatID��¯��
///  &gt;&gt; &csUnitID��Ŀ�����
/// RET &lt;&lt;����0
/// </Method>
L3LONG CDispatch_Mag::SteelMoveInCache(CString csTappingPlanURi,L3LONG nUnitType,CString csHeatID,CString &csUnitID)
{

	L3LONG nRet = MoveSteelFromCurCache(csHeatID);
	if(nRet < 0)
		return nRet;

	nRet = AddSteelToSpeciCache(csTappingPlanURi,nUnitType,csHeatID,csUnitID);
	if(nRet < 0)
		return nRet;
	


	return 0;
}

/// <Method class="CDispatch_Mag" name="MoveSteelFromCurCache" type="L3LONG">
/// 
/// ����ˮ�ӵ�ǰ��������ȥ
/// ARG&gt;&gt; 
///  &gt;&gt; csHeatID��¯��
/// RET &lt;&lt;����0
/// </Method>

L3LONG CDispatch_Mag::MoveSteelFromCurCache(CString csHeatID)
{
	//�齨���ݼ�
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("Amount"),VT_INT);
	rsMaterial.AppendRecord();
	rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csHeatID));
	rsMaterial.SetFieldByName(_T("Amount"),CL3Variant(L3LONG(1)));
	
	CString csSteelCurCache = GetCurSteelCache(csHeatID);
	if(csSteelCurCache.IsEmpty())
		return -90;//��ˮ��ǰû������Ӧ�Ļ�����

	CL3Variant valResult = InvokeObjectMethod(csSteelCurCache,_T("RemoveMaterials"),(L3RECORDSET)rsMaterial);
	if(!valResult.IsValid()||!valResult.ToBOOL())
		return -91;//��ˮ�ӷ������빤���Ƴ�ʧ��

	return 0;

}

/// <Method class="CDispatch_Mag" name="SteelMoveInCache" type="L3LONG">
/// 
/// ����ˮ�ƶ���ָ���Ļ���ͬʱ���ļƻ���Ϣ
/// ARG&gt;&gt; csTappingPlanURi�����ּƻ�URI
///  &gt;&gt; nUnitType��Ŀ�깤��
///  &gt;&gt; &csUnitID��Ŀ�����
/// RET &lt;&lt;����0
/// </Method>

L3LONG CDispatch_Mag::AddSteelToSpeciCache(CString csTappingPlanURi,L3LONG nUnitType,CString csHeatID,CString &csUnitID)
{
	CString csUnitIDType;

	switch(nUnitType)
	{
		case UNIT_AREA_CASTER:
			csUnitIDType = _T("Caster_ID");
		case UNIT_AREA_RH:
			csUnitIDType = _T("RHID");
			if(!SetObjectPropValue(csTappingPlanURi,_T("Caster_Status"),CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING)))
				return -92; 
			if(!SetObjectPropValue(csTappingPlanURi,_T("RH_Status"),CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING)))
				return -93;
			break;
		case UNIT_AREA_LF:
			csUnitIDType = _T("LFID");
			if(!SetObjectPropValue(csTappingPlanURi,_T("Caster_Status"),CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING)))
				return -92; 
			if(!SetObjectPropValue(csTappingPlanURi,_T("RH_Status"),CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING)))
				return -93;
			if(!SetObjectPropValue(csTappingPlanURi,_T("LF_Status"),CL3Variant(TAPPING_PLAN_LF_STATUS_UNEXCUTING)))
				return -94;
			break;
		//case UNIT_AREA_TAPSIDE:
		//	csUnitIDType = _T("BOFID");
		//	if(!SetObjectPropValue(csTappingPlanURi,_T("Caster_Status"),CL3Variant(TAPPING_PLAN_CCM_STATUS_UNEXCUTING)))
		//		return -92; 
		//	if(!SetObjectPropValue(csTappingPlanURi,_T("RH_Status"),CL3Variant(TAPPING_PLAN_RH_STATUS_UNEXCUTING)))
		//		return -93;
		//	if(!SetObjectPropValue(csTappingPlanURi,_T("LF_Status"),CL3Variant(TAPPING_PLAN_LF_STATUS_UNEXCUTING)))
		//		return -94;
		//	if(!SetObjectPropValue(csTappingPlanURi,_T("Side_Status"),CL3Variant(TAPPING_PLAN_SIDE_STATUS_UNEXCUTING)))
		//		return -95;
		//	break;
		default:
			return -96;
	}
	//�齨���ݼ�
	CL3RecordSet *pRS = new CL3RecordSet();
	CL3RecordSetWrap rsMaterial; pRS->QueryInterface(IID_IL3RecordSet,rsMaterial); pRS->Release();
	rsMaterial.AddField(_T("MaterialType"),VT_BSTR);
	rsMaterial.AddField(_T("MaterialID"),VT_BSTR);
	rsMaterial.AddField(_T("Amount"),VT_INT);
	rsMaterial.AppendRecord();
	rsMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csHeatID));
	rsMaterial.SetFieldByName(_T("Amount"),CL3Variant(L3LONG(1)));
	
	csUnitID = GetObjectPropValue(csTappingPlanURi,csUnitIDType).ToCString();
	if(csUnitID == _T("0")) return -97;//����Ŀ�깤�򣬹���·��������
	//if(csUnitID ==UNIT_ID_1BOF) csUnitID = UNIT_ID_1TAPSIDE;
	//if(csUnitID ==UNIT_ID_2BOF) csUnitID = UNIT_ID_2TAPSIDE;
	//if(csUnitID ==UNIT_ID_3BOF) csUnitID = UNIT_ID_3TAPSIDE;
	//if(csUnitID ==UNIT_ID_4BOF) csUnitID = UNIT_ID_4TAPSIDE;

	CString csSteelNextCache = _T("XGMESLogic\\BaseDataMag\\XGInterCache\\") + csUnitID +_T("P01");

	CL3Variant valResult = InvokeObjectMethod(csSteelNextCache,_T("AddMaterials"),(L3RECORDSET)rsMaterial);					
	if(!valResult.IsValid()||!valResult.ToBOOL())
		return -98;//��ˮ�Ƶ�����Ŀ�깤��ʧ��

	return 0;

}

/// <Method class="CDispatch_Mag" name="SteelAllReturn" type="L3LONG">
/// 
/// ��ˮȫ��¯
/// ARG&gt;&gt; csTappingPlanURi�����ּƻ�URI
///  &gt;&gt; csUnitID��ȫ��¯�������
///  &gt;&gt; csHeatID��¯��
/// RET &lt;&lt;����0�������
/// </Method>
L3LONG CDispatch_Mag::SteelAllReturn(CString csTappingPlanURi,CString csUnitID,CString csHeatID,L3DOUBLE fWeight)
{
	//�ж�״̬
	L3LONG nAppUnit = _ttol(csUnitID.Mid(1,1));
	L3SHORT nStatus =0;
	CL3Variant valTemp;
	switch (nAppUnit)
	{
		case UNIT_AREA_CASTER://����ֻ�е�������ȫ��¯
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("Caster_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus != 2)
                    return -21;
			break;
		case UNIT_AREA_RH://RH����δ��վ������ȫ��¯
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("RH_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 5)//2009-02-16 tangyi
					return -22;
			break;
		case UNIT_AREA_LF://LF����δ��վ������ȫ��¯
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("LF_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 5)//2009-02-16 tangyi
					return -23;
			break;
		case UNIT_AREA_TAPSIDE://¯����δ����������ȫ��¯
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("Side_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 3)
					return -24;
		case UNIT_AREA_BOF://ת¯����δ����������ȫ��¯
				valTemp = GetObjectPropValue(csTappingPlanURi,_T("BOF_Status"));
				if(!valTemp.IsValid() || valTemp.IsError() || valTemp.IsNull())
					return -1;
				nStatus = valTemp.ToShort();
				if(nStatus < 5)
					return -25;
			break;
		default:
			 return -26;//��¯���빤�򲻺Ϸ�
	}
	//ɾ����ˮ���ϱ���Ϣ
	CString csSteelUri = MATERIAL_STEEL_URI + _T("\\") + csHeatID;
	if(!SetObjectPropValue(csSteelUri,_T("Status"),CL3Variant(L3LONG(Material::Deleted))))
		return -27;

	//����ˮ�ӻ�����ȥ
	L3LONG nRet = MoveSteelFromCurCache(csHeatID);	
	if(nRet < 0)
		return nRet;

	COleDateTime curTime= COleDateTime::GetCurrentTime();
	CString csIronMaterialID = csHeatID + _T("_") + curTime.Format(_T("%Y%m%d%H%M%S"));

	//���ɲ��϶��ձ�
	CL3RecordSetWrap rsMaterialMap;
	if(!CreateClassPropSet(_T("MES\\MaterialData\\MaterialMap"),rsMaterialMap))
		return -28;
	rsMaterialMap.AppendRecord();
	rsMaterialMap.SetFieldByName(_T("FromType"),CL3Variant(MATERIAL_TYPE_STEEL));
	rsMaterialMap.SetFieldByName(_T("FromID"),CL3Variant(csHeatID));
	rsMaterialMap.SetFieldByName(_T("ToType"),CL3Variant(MATERIAL_TYPE_IRON));
	rsMaterialMap.SetFieldByName(_T("ToID"),CL3Variant(csIronMaterialID));
	rsMaterialMap.SetFieldByName(_T("Mode"),CL3Variant(L3LONG(MaterialMap::Produce)));
	rsMaterialMap.SetFieldByName(_T("Mapper"),CL3Variant(csUnitID));
	rsMaterialMap.SetFieldByName(_T("SrcAmount"),CL3Variant(fWeight));
	rsMaterialMap.SetFieldByName(_T("TgtAmount"),CL3Variant(fWeight));

	if(CreateNewObjects(_T("MES\\MaterialData\\MaterialMap"),L3RECORDSET(rsMaterialMap)) < rsMaterialMap.GetRowCount())
		return -29;

	//2009-01-02 tangyi ����������Ϣ����¯����ת¯����ʱ�˹�¼��
	//���ɻ�¯��ˮ��Ϣ����ˮ��
	//CL3RecordSetWrap rsIronData;
	//if(!CreateClassPropSet(MATERIAL_BFIRON_URI,rsIronData))
	//	return -30;
	//rsIronData.AppendRecord();
	//rsIronData.SetFieldByName(_T("MaterialID"),CL3Variant(csIronMaterialID));
	//rsIronData.SetFieldByName(_T("Tare"),CL3Variant(fWeight));
	//rsIronData.SetFieldByName(_T("Source"),CL3Variant(L3LONG(3)));

	//if(CreateNewObjects(MATERIAL_IRON_URI,L3RECORDSET(rsIronData)) < rsIronData.GetRowCount())
	//	return -31;

	//
	////�齨���͸�ˮ���ݼ�
	//CL3RecordSet *pRSIron = new CL3RecordSet();
	//CL3RecordSetWrap rsIronMaterial; pRSIron->QueryInterface(IID_IL3RecordSet,rsIronMaterial); pRSIron->Release();
	//rsIronMaterial.AddField(_T("MaterialType"),VT_BSTR);
	//rsIronMaterial.AddField(_T("MaterialID"),VT_BSTR);
	//rsIronMaterial.AddField(_T("Amount"),VT_INT);
	//rsIronMaterial.AppendRecord();
	//rsIronMaterial.SetFieldByName(_T("MaterialType"),CL3Variant(MATERIAL_TYPE_IRON));
	//rsIronMaterial.SetFieldByName(_T("MaterialID"),CL3Variant(csIronMaterialID));
	//rsIronMaterial.SetFieldByName(_T("Amount"),CL3Variant(L3LONG(1)));
	//CL3Variant valResult = InvokeObjectMethod(MIXFProduceCache_URI,_T("AddMaterials"),(L3RECORDSET)rsIronMaterial);					
	//if(!valResult.IsValid()||!valResult.ToBOOL())
	//	return -32;//��¯��ˮ�Ƶ�����Ŀ�깤��ʧ��

	return 0;
}




/// <Method class="CDispatch_Mag" name="GetDestination" type="L3RECORDSET">
/// 
/// ��ȡ������ȥ��
/// ARG&gt;&gt;strBOFID:ת¯����
/// RET &lt;&lt;�������ݼ�
/// </Method>
L3STRING CDispatch_Mag::GetDestination(L3STRING strUnitID,L3STRING strHeatID)
{
	CString csRtn =_T("");
	CString csUnitID =strUnitID;
	csUnitID.Trim();
	if(csUnitID.IsEmpty()) return csRtn.AllocSysString();
	
	CString csSQL;
	CL3RecordSetWrap rsResult;
	csSQL.Format(_T("select * from CPlan_Tapping where HeatID = '%s'"),strHeatID);
	if (!Query(csSQL,rsResult))
		return NULL;
	rsResult.MoveFirst();
	CString csRefineType = rsResult.GetFieldByName(_T("Refine_Type")).ToCString();

	L3LONG nUnitID = _ttol(csUnitID.Mid(1,1));
	switch(nUnitID)
	{
		case UNIT_AREA_BOF:
			if(csRefineType == _T("0"))
				return rsResult.GetFieldByName(_T("CasterID")).ToBSTR();
			else
				if(csRefineType == _T("L") || csRefineType == _T("LR"))
					return rsResult.GetFieldByName(_T("LFID")).ToBSTR();
				else
					if(csRefineType == _T("R") || csRefineType == _T("RL"))
						return rsResult.GetFieldByName(_T("RHID")).ToBSTR();
			break;
		case UNIT_AREA_LF:
				if(csRefineType == _T("L") || csRefineType == _T("RL"))
					return rsResult.GetFieldByName(_T("CasterID")).ToBSTR();
				else
					if(csRefineType == _T("LR"))
						return rsResult.GetFieldByName(_T("RHID")).ToBSTR();
			break;
		case UNIT_AREA_RH:
				if(csRefineType == _T("R") || csRefineType == _T("LR"))
					return rsResult.GetFieldByName(_T("CasterID")).ToBSTR();
				else
					if(csRefineType == _T("RL"))
						return rsResult.GetFieldByName(_T("LFID")).ToBSTR();
			break;
		default:
			return csRtn.AllocSysString();
	}	

	return csRtn.AllocSysString(); 
	
}

/// <Method class="CDispatch_Mag" name="AddDisExceptional" type="L3LONG">
/// �����豸�쳣����Ϣ
/// <Param name="dsInfo" type="L3RECORDSET">��������Ϣ</Param>
/// </Method>
L3LONG CDispatch_Mag::AddDisExceptional(L3RECORDSET dsInfo)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csDate = rsData.GetFieldByName(_T("CreateDate")).ToCString();//����yyyyMmdd
		CString csUnitID = rsData.GetFieldByName(_T("UnitID")).ToCString();//��������
		CString csShift = rsData.GetFieldByName(_T("Shift")).ToCString();//���

		if(csDate == _T("") || csUnitID == _T("") || csShift == _T(""))
			return 0;
		CString csObjectID = csDate + csUnitID + csShift;
		rsData.SetFieldByName(_T("IDObject"),CL3Variant(csObjectID));
		
		rsData.MoveNext();
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
	if(CreateNewObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional"),rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="ModifyDisExceptional" type="L3LONG">
/// �޸��豸�쳣����Ϣ
/// <Param name="dsInfo" type="L3RECORDSET">�޸ĵ�����Ϣ</Param>
/// </Method>
L3LONG CDispatch_Mag::ModifyDisExceptional(L3RECORDSET dsInfo)
{
	// TODO : ���ڴ�����߼�����
	return 0;
}

/// <Method class="CDispatch_Mag" name="DeleteDisExceptional" type="L3LONG">
/// ɾ���豸�쳣����Ϣ
/// <Param name="dsInfo" type="L3RECORDSET">ɾ��������Ϣ</Param>
/// </Method>
L3LONG CDispatch_Mag::DeleteDisExceptional(L3RECORDSET dsInfo)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;
	
	if(rsData.GetFieldIndex(_T("IDObject")) < 0)
		return -1;//û�йؼ���

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
		CString csObjectID = rsData.GetFieldByName(_T("IDObject")).ToCString();
		if(csObjectID == _T(""))
		{
			if(bUseTrans)		
				Rollback(nTrans);
			return -1;//û�йؼ���
		}
		CString csTemp;
		CString csSQL;

		csTemp =_T(" SELECT * FROM %s WHERE IDObject = '%s'");
		csSQL.Format(csTemp,_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),csObjectID);
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
			if(DeleteOldObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),rsResult) < rsResult.GetRowCount())
			{
				if(bUseTrans)
					Rollback(nTrans);
				return -2;//ɾ����ϸ��Ϣʧ��
			}
		}
		
		rsData.MoveNext();
	}
	
	rsData.MoveFirst();
	if(DeleteOldObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional"),rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;//ɾ������Ϣʧ��
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="AddDisExceptionalItems" type="L3LONG">
/// �����豸�쳣��ϸ��Ϣ
/// <Param name="dsInfo" type="L3RECORDSET">��������ϸ��Ϣ</Param>
/// </Method>
L3LONG CDispatch_Mag::AddDisExceptionalItems(L3RECORDSET dsInfo)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;

	rsData.MoveFirst();
	while(!rsData.IsEOF())
	{
		CString csObjectID = rsData.GetFieldByName(_T("IDObject")).ToCString();
		CString csItems = rsData.GetFieldByName(_T("Items")).ToCString();

		if(csObjectID == _T("") || csItems == _T(""))
			return -1;//û������Ϣ�ؼ��ֻ�û��ѡ���쳣��Ŀ

		COleDateTime dtBeginTime = rsData.GetFieldByName(_T("BeginTime")).ToDateTime();//COleDateTime::GetCurrentTime();
		COleDateTime dtEndTime = rsData.GetFieldByName(_T("EndTime")).ToDateTime();

		long lTimeSpan = 0;
		COleDateTimeSpan span = dtEndTime - dtBeginTime;
		lTimeSpan = (LONG)span.GetTotalMinutes();
		//�����쳣ʱ�䳤��
		rsData.SetFieldByName(_T("TimeSpan"),CL3Variant(lTimeSpan));
		
		rsData.MoveNext();
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
	if(CreateNewObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
				Rollback(nTrans);
		return 0;
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="ModifyDisExceptionalItems" type="L3LONG">
/// �޸��豸�쳣��ϸ��Ϣ
/// <Param name="dsInfo" type="L3RECORDSET">�޸ĵ���ϸ��Ϣ</Param>
/// </Method>
L3LONG CDispatch_Mag::ModifyDisExceptionalItems(L3RECORDSET dsInfo)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;

	if(rsData.GetFieldIndex(_T("GUID")) < 0)
		return -1;//û�йؼ���
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	if(!SetObjsPropValues(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),rsData))
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -2;//�޸���ϸ��Ϣʧ��
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="DelDisExceptionalItems" type="L3LONG">
/// ɾ���豸�쳣��ϸ��Ϣ
/// <Param name="dsInfo" type="L3RECORDSET">ɾ������ϸ��Ϣ</Param>
/// </Method>
L3LONG CDispatch_Mag::DelDisExceptionalItems(L3RECORDSET dsInfo)
{
	// TODO : ���ڴ�����߼�����
	CL3RecordSetWrap rsData = dsInfo ;
	if(rsData.IsNull()||rsData.GetRowCount()<1)
		return 0;

	if(rsData.GetFieldIndex(_T("GUID")) < 0)
		return -1;//û�йؼ���
	
	BOOL bUseTrans = !IsInTrans();
	LONG nTrans = 0;
	if(bUseTrans)
	{
		nTrans = BeginTrans();
		if(nTrans < 1)
			return 0;
	}

	rsData.MoveFirst();
	if(DeleteOldObjects(_T("XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items"),rsData) < rsData.GetRowCount())
	{
		if(bUseTrans)
			Rollback(nTrans);
		return -3;//ɾ����ϸ��Ϣʧ��
	}

	if(bUseTrans)
		Commit(nTrans);
	return rsData.GetRowCount();
}

/// <Method class="CDispatch_Mag" name="GetDispExceData" type="L3RECORDSET">
/// �豸�쳣ͨ�ò�ѯ����
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CDispatch_Mag::GetDispExceData(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	CString csCondition = strCondition;
	if(csCondition == _T(""))
		return NULL;
	
	CString csSQL;
	CString csTemp = _T("Select * from XGMESLogic\\DispatchMag\\CDisp_Exceptional where %s");
	csSQL.Format(csTemp,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	
	return rsResult.Detach();
}

/// <Method class="CDispatch_Mag" name="GetDispExceItemData" type="L3RECORDSET">
/// ͨ�û�ȡ�豸�쳣��ϸ
/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
/// </Method>
L3RECORDSET CDispatch_Mag::GetDispExceItemData(L3STRING strCondition)
{
	// TODO : ���ڴ�����߼�����
	CString csCondition = strCondition;
	if(csCondition == _T(""))
		return NULL;

	CString csSQL;
	CString csTemp = _T("Select * from XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items where %s");
	csSQL.Format(csTemp,csCondition);
	CL3RecordSetWrap rsResult;
	if(!Query(csSQL,rsResult) || rsResult.IsNull())
		return NULL;
	
	return rsResult.Detach();
}

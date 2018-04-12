// �߼���CRHL_Prod_Area���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CRHL_Prod_Area.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CRHL_Prod_Area.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CRHL_Prod_Area.h"
#include "L3NameParser.h"

#define SOFTBLOWTIMER_PERIOD 5
#define PROCTIME_PERIOD		5000


//������װ�ص�ϵͳ��ʱ��������
void CRHL_Prod_Area::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CRHL_Prod_Area::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}

/// <summary>
/// �ӹ�ǰԤ�����ڽ��мӹ��߼�����ǰ���ã��̳�������ش˺�����������Ԥ����
/// ARG >> rsParameter : �ӹ�������¼����
/// RET << ����TRUE�����ӹ�������FALSE�жϼӹ���
/// </summary>
BOOL CRHL_Prod_Area::OnBeforeProcess(L3RECORDSET rsParameter)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnBeforeProcess( rsParameter);
}

/// <summary>
/// ���ϼӹ��߼������̳�����Ҫ���ش˺����������ض��Ĳ��ϼӹ�����
/// ע�⣺�ڴ˷����в�Ҫ�Լӹ���ص����ݽ���ֱ���޸ģ�����������������������
/// ARG >> rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
///		>> rsParameter : �ӹ�ʹ�õĲ�����¼����
///		<< pnProcessType : �ɹ��󷵻ؼӹ����͡�
///		<< prsProducts : �ɹ��󷵻ز�Ʒ���ݼ�¼��
///		<< prsMaterialMap : ����ӹ�������CreateNew���ɹ��󷵻�ԭ�ϳ�Ʒ���ձ��������á�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CRHL_Prod_Area::ProcessMaterials(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG* pnProcessType,L3RECORDSET *prsProducts,L3RECORDSET *prsMaterialMap)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::ProcessMaterials( rsMaterials, rsParameter, pnProcessType, prsProducts, prsMaterialMap);
}

/// <summary>
/// �ӹ����������ڼӹ��߼�������ɺ���ã��̳�������ش˺������ж��⴦��
/// ARG >> rsMaterials : �ӹ�ʹ�õ�ԭ����Ϣ������MaterialType,MaterialID,Amount�ֶΡ�
///		>> rsParameter : �ӹ�ʹ�õĲ�����¼����
///		>> pnProcessType : �ӹ����͡�
///		>> rsProducts : ��Ʒ���ݼ�¼��
///		>> rsMaterialMap : ����ӹ�������CreateNew��Ϊԭ�ϳ�Ʒ���ձ��������á�
/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
/// </summary>
BOOL CRHL_Prod_Area::OnAfterProcessed(L3RECORDSET rsMaterials,L3RECORDSET rsParameter,L3LONG nProcessType,L3RECORDSET rsProducts,L3RECORDSET rsMaterialMap)
{
	// TODO: �ڴ˴��༭��ع��ܵĴ������

	return __super::OnAfterProcessed( rsMaterials, rsParameter, nProcessType, rsProducts, rsMaterialMap);
}

/// <summary>
/// �������ǰ������
/// </summary>
BOOL CRHL_Prod_Area::OnBeforeAddMaterials(L3RECORDSET rsMaterials)
{
	//if(HeatID != _T("") || GetMaterialCount(_T("")) > 0)

	//2009-03-28 tangyi
	if(GetMaterialCount(_T("")) > 0)
	{
		SetL3LastError(XGMES_ERR_LF_AREANOTEMPTY);
		return FALSE;
	}

	return TRUE;
}

/// <summary>
/// ������Ӻ�������
/// </summary>
BOOL CRHL_Prod_Area::OnAfterMaterialsAdded(L3RECORDSET rsMaterials)
{
	CL3RecordSetWrap rs = rsMaterials;
	if(rs.GetRowCount() < 1)
	{
		SetL3LastError(XGMES_ERR_LF_NEEDSTEEL);
		return FALSE;
	}

	rs.MoveFirst();
	CString strHeatID = rs.GetFieldByName(_T("MaterialID")).ToCString();
	CString strSteel = CL3NameParser::MergeClassDomainName(MATERIAL_STEEL_URI,strHeatID);

	HeatID = strHeatID;
	LadleID = GetObjectPropValue(strSteel,_T("LadleID")).ToCString();
	SteelGradeIndex = GetObjectPropValue(strSteel,_T("SteelGradeIndex")).ToCString();
	Weight = GetObjectPropValue(strSteel,_T("Weight")).ToDouble();
	Arrive_Time = COleDateTime::GetCurrentTime();

	return TRUE;
}

/// <summary>
/// �����Ƴ���������
/// </summary>
BOOL CRHL_Prod_Area::OnAfterMaterialsRemoved(L3RECORDSET rsMaterials)
{
	CL3RecordSetWrap rs = rsMaterials;
	if(rs.GetRowCount() < 1)
	{
		return TRUE;
	}

	HeatID = _T("");
	LadleID = _T("");
	SteelGradeIndex = _T("");
	Weight = 0.0;
	TreatNo = _T(""); //2009-03-26 
	SoftBlowTime =0;//2009-02-28

	return TRUE;
}


/// <summary>
/// ����λ�ñ�����麯�����̳���������ش˺��������Լ���λ�ñ��붨�塣
/// ARG >> void
/// RET << λ�ñ���
/// </summary>
CString CRHL_Prod_Area::GetPositionCode()
{
	return GetPropValue(_T("Code")).ToCString();
}

/// <Method class="CRHL_Prod_Area" name="OnTimer" type="L3BOOL">
/// ����ʱ���¼�
/// <Param name="nEventID" type="L3ULONG">��ʱ���¼�ID</Param>
/// </Method>
L3BOOL CRHL_Prod_Area::OnTimer(L3ULONG nEventID)
{
	if(nEventID == m_iTimer)
	{	// ������ʱ��
		 //Modify begin by llj 2011-04-10 �޸�LF������ʱ����
		//SoftBlowTime += SOFTBLOWTIMER_PERIOD;
		CString csHeatID=GetObjectPropValue(GetURI(),_T("HeatID")).ToCString();
		CString csSql;
		csSql.Format(_T("select SoftBlow_StartTime from CRHL_Process_Data where HeatID='%s'"),csHeatID);
		CL3RecordSetWrap rs;
		if(!Query(csSql,rs)||rs.IsNull()||rs.GetRowCount()<1)
			return SoftBlowTime + SOFTBLOWTIMER_PERIOD;
		rs.MoveFirst();
		L3DATETIME dSoftStart=rs.GetFieldByName(_T("SoftBlow_StartTime")).ToDateTime();
		COleDateTime curTime = COleDateTime::GetCurrentTime();
		COleDateTimeSpan span =(L3DATETIME) curTime - dSoftStart;
		SoftBlowTime=span.GetTotalSeconds();
		//Modify end
	}

	return TRUE;
}

/// <Method class="CRHL_Prod_Area" name="SetLFAreaTimer" type="L3BOOL">
/// ������ʱ���¼�
/// </Method>
L3BOOL CRHL_Prod_Area::SetLFAreaTimer()
{
	SoftBlowTime = 0;
	m_iTimer = SetTimer(GetURI(),PROCTIME_PERIOD);//2009-05-24 ����

	return TRUE;
}

/// <Method class="CRHL_Prod_Area" name="KillLFAreaTimer" type="L3BOOL">
/// ֹͣ��ʱ���¼�
/// </Method>
L3BOOL CRHL_Prod_Area::KillLFAreaTimer()
{
	if(m_iTimer != 0)
		KillTimer(GetURI(),m_iTimer);
	m_iTimer = 0;

	return TRUE;
}

// �߼���CBOF_Communicator���û��߼�����Դ�ļ�
// �û�ϵͳ���߼�����Ӧ���ڱ��ļ���ʵ�֣��߼������Ķ���Ӧ����_CBOF_Communicator.h�С�
// ���ڱ��ļ��ж���ĺ�����ΪL3���ɿ��������Զ����ɣ�����_CBOF_Communicator.h��
// �в�������صĴ��룬����벻Ҫɾ�����޸ı��ļ��еĺ������塣�û�ϵͳ����ԱӦ��ֻ�޸ĺ����ľ���
// ʵ�ִ��롣��Ҫ��ӡ�ɾ�����޸��߼������Ķ��壬��ʹ�ü��ɿ���������ɡ�

#include "StdAfx.h"
#include "_CBOF_Communicator.h"

//������װ�ص�ϵͳ��ʱ��������
void CBOF_Communicator::OnLoaded()
{
	__super::OnLoaded();

	// TODO: �ڴ˴���Ӷ���װ��ʱ�Ĵ������
}

//������ж��ʱ��������
void CBOF_Communicator::OnUnloaded()
{
	__super::OnUnloaded();

	// TODO: �ڴ˴���Ӷ���ж��ʱ�Ĵ������
}


/// <Method class="CBOF_Communicator" name="OnFeedIron" type="L3BOOL">
/// ��Ӧ�����ӷϸ��¼�����
/// <Param name="rsData" type="L3RECORDSET">��������</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnFeedIron(L3RECORDSET rsData)
{
    return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBOF_Communicator" name="OnChangeStatus" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// ״̬����
/// (BOFID,Status,Change_Time)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnChangeStatus(L3RECORDSET rsData)
{
    return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBOF_Communicator" name="OnDischarge" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// ���ϼ�¼��
/// (Element,Weight,Discharge_Time,Type)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnDischarge(L3RECORDSET rsData)
{
    return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBOF_Communicator" name="OnMeasureTemp" type="L3BOOL">
/// �����¼���Ӧ����
/// <Param name="rsData" type="L3RECORDSET">
/// ��������
/// (Temp,Temp_Time,Mode)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnMeasureTemp(L3RECORDSET rsData)
{
    return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBOF_Communicator" name="OnMeasureO2" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// ��������
/// (O2,Measure_Time)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnMeasureO2(L3RECORDSET rsData)
{
    return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBOF_Communicator" name="OnTapped" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBOF_Communicator::OnTapped(L3RECORDSET rsData)
{
    return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBOF_Communicator" name="OnBottomBlow" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// �״�����
/// (BOFID,Flow1...Flow6,Pressure1...Pressure6,Gas_Type)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnBottomBlow(L3RECORDSET rsData)
{
	CString strID = GetIdentity().ToCString();
	CString strBOFURI = _T("XGMESLogic\\BOFMag\\CBOF_Unit_Mag\\") + strID;

	CL3Variant valRet = InvokeObjectMethod(strBOFURI,_T("BottomBlowing"),(L3RECORDSET)rsData);
	if(valRet.IsError())
		return false;
	else
		return valRet.ToBOOL();

// TODO : ���ڴ�����߼�����
}

/// <Method class="CBOF_Communicator" name="OnTopBlow" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET">
/// ��������
/// (BFID,Flow,Pressure,Catch_Time)</Param>
/// </Method>
L3BOOL CBOF_Communicator::OnTopBlow(L3RECORDSET rsData)
{
    return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBOF_Communicator" name="OnSauceEvent" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBOF_Communicator::OnSauceEvent(L3RECORDSET rsData)
{
    return true;
	// TODO : ���ڴ�����߼�����
}

/// <Method class="CBOF_Communicator" name="OnTapStart" type="L3BOOL">
/// <Param name="rsData" type="L3RECORDSET"></Param>
/// </Method>
L3BOOL CBOF_Communicator::OnTapStart(L3RECORDSET rsData)
{
    return true;
	// TODO : ���ڴ�����߼�����
}

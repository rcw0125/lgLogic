// �߼���CEnergy_Unit_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

struct BOFStatus
{
	TCHAR BOFID[4];
	L3DATETIME dtBOF0ProcessEndTime;
};


const L3LONG nNewBOF =1;
const L3LONG nOldBOF =0;


/// <summary>
/// RH����
/// </summary>
enum BOFType
{
	BOF50t = 1,		// ������RH
	BOF80t = 2,			 // 1#RH
};


/// <summary>
/// ��������
/// </summary>
enum CasterType
{
	NoLFCaster = 1,		// 1#2#����
	OldLFCaster = 2,    // 3#4#����
	NewLFCaster = 3,	// 5#����
	//Modify by llj 2011-1-18 ������޸�
	NewLFCaster6 = 4,	// 6#����(������ֻ�����Ų�����¯�������ʱ���Զ�����������Բ���)
	NewLFCaster7 = 5,	// 7#���� 

};

/// <summary>
/// LF����
/// </summary>
enum LFType
{
	NoPassLF = 1,		// ������LF
	OldLF = 2,			 // 1#2#LF
	NewLF = 3,			// 3#LF
};

/// <summary>
/// RH����
/// </summary>
enum RHType
{
	NoPassRH = 1,		// ������RH
	PassRH = 2,			 // 1#RH
};


//����
const CString csCasterType1 =_T("01");//1#2#����
const CString csCasterType2 =_T("02");//3#4#����
const CString csCasterType3 =_T("03");//5#����
//Modify by llj 2011-1-18 ������޸�
const CString csCasterType7 =_T("07");//7#����

//LF
const CString csLFType1 =_T("01");//������LF
const CString csLFType2 =_T("02");//1#2#LF
const CString csLFType3 =_T("03");//3#LF
//Modify by llj 2011-02-11 ����5#LF�޸�
const CString csLFType5 =_T("05");//5#LF
//Add by hyh 2012-05-14  ������޸�
const CString csLFType4 =_T("04");//4#LF

//RH
const CString csRHType1 =_T("01");//������RH
const CString csRHType2 =_T("02");//1#RH


/// <summary>
/// ת¯
/// </summary>
enum HeatType
{
	CurrentHeat = 0,		// ��ǰ¯
	LastHeat = 1,		    // ��һ¯��
	NextHeat = 2,			// ��һ¯��
};

class CEnergy_Unit_Mag :
	public CL3Object
{
public:
	CEnergy_Unit_Mag(void);
	virtual ~CEnergy_Unit_Mag(void);

	DECLARE_L3CLASS(CEnergy_Unit_Mag,XGMESLogic\\EnergyMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergy_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CEnergy_Unit_Mag" name="AcceptEnergyFlowData" type="L3BOOL">
	/// ����һ����Դ����������ݡ�
	/// <Param name="rsData" type="L3RECORDSET">��Դ��������</Param>
	/// </Method>
	L3BOOL AcceptEnergyFlowData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptEnergyPressureData" type="L3BOOL">
	/// ����һ����Դѹ��������ݡ�
	/// <Param name="rsData" type="L3RECORDSET">��Դ��������</Param>
	/// </Method>
	L3BOOL AcceptEnergyPressureData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptEnergyConsumeData" type="L3BOOL">
	/// ����һ����Դ���ļ�����ݡ�
	/// <Param name="rsData" type="L3RECORDSET">��Դ��������</Param>
	/// </Method>
	L3BOOL AcceptEnergyConsumeData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptTrendGasFlowData" type="L3BOOL">
	/// ����һ���濾����ú������������ݡ�
	/// <Param name="rsData" type="L3RECORDSET">��Դ��������</Param>
	/// </Method>
	L3BOOL AcceptTrendGasFlowData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptTrendAirFlowData" type="L3BOOL">
	/// ����һ���濾���ƿ�������������ݡ�
	/// <Param name="rsData" type="L3RECORDSET">��Դ��������</Param>
	/// </Method>
	L3BOOL AcceptTrendAirFlowData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="GetDayValue" type="L3BOOL">
	///  ��ȡ�����ܺ�
	/// <Param name="cscurday" type="CString">����</Param>
	/// <Param name="csTagName" type="CString">��ǩ��</Param>
	/// <Param name="fieldValue" type="L3FLOAT">�ֳ�����</Param>
	/// <Param name="dayValue" type="L3FLOAT">��������</Param>
	/// <Param name="monthValue" type="L3FLOAT">��������</Param>
	/// </Method>
	L3BOOL CalculateValue(  CString cscurday,
							CString csTagName,
							L3FLOAT fieldValue,
							L3FLOAT & dayValue,
							L3FLOAT & monthValue);
	/// <Method class="CEnergy_Unit_Mag" name="NewConsumption" type="L3BOOL">
	/// �ֹ�������������
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL NewConsumption(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="UpdateConsumption" type="L3BOOL">
	/// �ֹ��޸���������
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateConsumption(L3RECORDSET rsData);
	L3BOOL UpdateAODHeatid();

	/// <Method class="CBF_Iron_Mag" name="QueryConsumptionInfo" type="L3RECORDSET">
	/// ����ʱ��κ�ȥ���Ѯ��Դ������Ϣ
	/// <Param name="timeFrom" type="L3DATETIME">��ʼʱ��</Param>
	/// <Param name="timeTo" type="L3DATETIME">����ʱ��</Param>
	/// </Method>
	L3RECORDSET QueryConsumptionInfo(L3DATETIME timeFrom, L3DATETIME timeTo);
	L3LONG TappingPlanGen(L3RECORDSET rsCastingPlan);
	L3LONG NewCastingPlanGen(L3RECORDSET rsPlan,L3STRING strSteelGradeIndex);
	private:
	L3LONG GenCastingPlanOfSpecifyCasterID(CString csCasterID,L3RECORDSET rsPlanOrder,L3LONG nHeatCount,CString csSteelGradeIndex,L3DOUBLE fWeight,L3SHORT nBOFFlag);
	L3LONG CalculateCastingTime(CString csCasterID,CString csSteelGradeIndex,L3DATETIME &dtCastingTime);
	L3LONG CalculateHeatCount(L3SHORT nBOFFlag,L3DOUBLE dWeight);
};

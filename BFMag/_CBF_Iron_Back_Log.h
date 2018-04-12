// �߼���CBF_Iron_Back_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBF_Iron_Back_Log :
	public CL3Object
{
public:
	CBF_Iron_Back_Log(void);
	virtual ~CBF_Iron_Back_Log(void);

	DECLARE_L3CLASS(CBF_Iron_Back_Log,XGMESLogic\\BFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBF_Iron_Back_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBFIron" name="BFID" type="L3STRING">
	/// ��¯¯��
	/// </Property>
	DECLARE_L3PROP_STRING(BFID)

	/// <Property class="CBFIron" name="TAP_No" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TAP_No)

	/// <Property class="CBFIron" name="TPC_No" type="L3STRING">
	/// �޺�
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

	
	/// <Property class="CBFIron" name="Source" type="L3LONG">
	/// ��ˮ��Դ
	/// (0:��¯
	/// 1:����վ)
	/// </Property>
	DECLARE_L3PROP_LONG(Source)

	
	/// <Property class="CBFIron" name="Destination" type="L3LONG">
	/// ȥ��
	// 0:δָ��ȥ��
	// 1:����
	// 2:����
	/// </Property>
	DECLARE_L3PROP_LONG(Destination)

	/// <Property class="CBFIron" name="Production_Date" type="L3DATETIME">
	/// ��������(����ʱ��)
	/// </Property>
	DECLARE_L3PROP_DATETIME(Production_Date)

	
	/// <Property class="CBFIron" name="Shift" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Shift)

	/// <Property class="CBFIron" name="Operator" type="L3STRING">
	/// ����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CBFIron" name="NC_Confirm_Flag" type="L3LONG">
	/// �ѷ����ı�־
	/// (1:�ѷ���
	///  0:δ����)
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Confirm_Flag)

	
	/// <Property class="CBFIron" name="Team" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Team)

	/// <Property class="CBFIron" name="Result" type="L3LONG">
	/// �ɷ��ж����
	/// (1:�ϸ�
	///  2:���ϸ�
	/// 0: δ�ж�)
	/// </Property>
	DECLARE_L3PROP_LONG(Result)

	/// <Property class="CBFIron" name="Sample_Place" type="L3STRING">
	/// �����ص�
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Place)

	/// <Property class="CBFIron" name="C" type="L3STRING">
	/// C�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(C)

	/// <Property class="CBFIron" name="Si" type="L3STRING">
	/// Si�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Si)

	/// <Property class="CBFIron" name="Mn" type="L3STRING">
	/// Mn�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Mn)

	/// <Property class="CBFIron" name="S" type="L3STRING">
	/// S�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(S)

	/// <Property class="CBFIron" name="P" type="L3STRING">
	/// P�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(P)

	/// <Property class="CBFIron" name="Ti" type="L3STRING">
	/// Ti�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Ti)

	/// <Property class="CBFIron" name="Gross_Weight" type="L3FLOAT">
	/// ë��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Gross_Weight)

	/// <Property class="CBFIron" name="Last_Tare" type="L3FLOAT">
	/// �ϴ�Ƥ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Last_Tare)

	/// <Property class="CBFIron" name="Curr_Tare" type="L3FLOAT">
	/// ����Ƥ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(Curr_Tare)

	/// <Property class="CBFIron" name="Net_Weight" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Net_Weight)

	/// <Property class="CBFIron" name="Spare_Weight" type="L3DOUBLE">
	/// ʣ������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spare_Weight)

	
	/// <Property class="CBFIron" name="IronStatus" type="L3LONG">
	/// ״̬
	/// (0:δ����;
	/// 1:ȥ��ȷ��
	/// 2:����ȷ��;
	/// 3:��ʹ��;
	/// 4:����)
	/// </Property>
	DECLARE_L3PROP_LONG(IronStatus)

	/// <Property class="CBFIron" name="Arrival_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrival_Time)

	/// <Property class="CBFIron" name="Feed_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Feed_Time)

	/// <Property class="CBFIron" name="Send_Time" type="L3DATETIME">
	/// ��NCʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Send_Time)

	/// <Property class="CBFIron" name="SampCode" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(SampCode)

	/// <Property class="CBFIron" name="IronConfirm" type="L3LONG">
	/// �ѷ����ı�־
	/// (1:��ȷ��
	///  0:δȷ��)
	/// </Property>
	DECLARE_L3PROP_LONG(IronConfirm)

	/// <Property class="CBFIron" name="C_B" type="L3STRING">
	/// ǰC�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(C_B)

	/// <Property class="CBFIron" name="Si_B" type="L3STRING">
	/// ǰSi�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Si_B)

	/// <Property class="CBFIron" name="Mn_B" type="L3STRING">
	/// ǰMn�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_B)

	/// <Property class="CBFIron" name="S_B" type="L3STRING">
	/// ǰS�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(S_B)

	/// <Property class="CBFIron" name="P_B" type="L3STRING">
	/// ǰP�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(P_B)

	/// <Property class="CBFIron" name="Ti_B" type="L3STRING">
	/// ǰTi�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_B)

	/// <Property class="CBFIron" name="GrossFlag" type="L3LONG">
	/// ë�ر�־
	/// </Property>
	DECLARE_L3PROP_LONG(GrossFlag)

	/// <Property class="CBFIron" name="TareFlag" type="L3LONG">
	/// Ƥ�ر�־
	/// </Property>
	DECLARE_L3PROP_LONG(TareFlag)

	/// <Property class="CBFIron" name="AnalysisFlag" type="L3LONG">
	/// ������־
	/// </Property>
	DECLARE_L3PROP_LONG(AnalysisFlag)

	/// <Property class="CBFIron" name="Operator_B" type="L3STRING">
	/// ����Ա
	/// </Property>2009-04-23
	DECLARE_L3PROP_STRING(Operator_B)

	/// <Property class="CBFIron" name="Back_Operator" type="L3STRING">
	/// ���˲�����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Back_Operator)

	/// <Property class="CBFIron" name="Back_Team" type="L3STRING">
	/// ���˰��
	/// </Property>
	DECLARE_L3PROP_STRING(Back_Team)

	/// <Property class="CBFIron" name="Back_Shift" type="L3STRING">
	/// ���˰��
	/// </Property>
	DECLARE_L3PROP_STRING(Back_Shift)

	/// <Property class="CBFIron" name="Back_Shift" type="L3STRING">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Back_Time)

};

// �߼���CBFIronͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "Material.h"

class CBFIron :
	public Material
{
public:
	CBFIron(void);
	virtual ~CBFIron(void);

	DECLARE_L3CLASS(CBFIron, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBFIron)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

public:
	// ��ˮ״̬ö��
	enum _IronStatusEnum
	{
		ironNotProcessed = 0,			// ��ˮδ����
		ironDestDefined = 1,			// ��ˮ��ָ��ȥ��
		ironArrived = 2,				// ��ˮ�ѵ���Ŀ�ĵ�
		ironProcessingAtDeS = 5,		// ��ˮ���������� 2009-10-21 yao
	};
	
	/// ��ˮȥ��ö��
	enum _IronDestEnum
	{
		ironToNoWhere = 0,				// δָ��ȥ��
		ironToBOF = 1,					// ȥ����
		ironToCast = 2,					// ȥ����
	};

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

	//��Ը�¯��ˮ��CBFIron���ں�̨BFMag��������ʵ��������Ԫ��Sn��Sb��As��Pb��
	//Modify by hyh 2012-03-28
	/// <Property class="CBFIron" name="C" type="L3STRING">
	/// Sn�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Sn)

	/// <Property class="CBFIron" name="Si" type="L3STRING">
	/// Sb�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Sb)

	/// <Property class="CBFIron" name="Mn" type="L3STRING">
	/// As�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(As)

	/// <Property class="CBFIron" name="S" type="L3STRING">
	/// Pb�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pb)
	//End

	//add by hyh 2012-08-13 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	/// <Property class="CQA_Iron_Element" name="Ni" type="L3STRING">
	/// Ni
	/// </Property>
	DECLARE_L3PROP_STRING(Ni)

	/// <Property class="CQA_Iron_Element" name="Mo" type="L3STRING">
	/// Mo
	/// </Property>
	DECLARE_L3PROP_STRING(Mo)

	/// <Property class="CQA_Iron_Element" name="Cu" type="L3STRING">
	/// Cu
	/// </Property>
	DECLARE_L3PROP_STRING(Cu)

	/// <Property class="CQA_Iron_Element" name="Cr" type="L3STRING">
	/// Cr
	/// </Property>
	DECLARE_L3PROP_STRING(Cr)

	/// <Property class="CQA_Iron_Element" name="B" type="L3STRING">
	/// B
	/// </Property>
	DECLARE_L3PROP_STRING(B)

	/// <Property class="CQA_Iron_Element" name="V" type="L3STRING">
	/// V
	/// </Property>
	DECLARE_L3PROP_STRING(V)

	/// <Property class="CQA_Iron_Element" name="Al" type="L3STRING">
	/// Al
	/// </Property>
	DECLARE_L3PROP_STRING(Al)

	/// <Property class="CQA_Iron_Element" name="Nb" type="L3STRING">
	///Nb
	/// </Property>
	DECLARE_L3PROP_STRING(Nb)

	/// <Property class="CQA_Iron_Element" name="Zn" type="L3STRING">
	/// Zn
	/// </Property>
	DECLARE_L3PROP_STRING(Zn)

	/// <Property class="CQA_Iron_Element" name="W" type="L3STRING">
	/// W
	/// </Property>
	DECLARE_L3PROP_STRING(W)
	//end

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
	/// 4:����;
	/// 5:������ 2009-10-21)
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

	//Modify by hyh 2012-03-28
	/// <Property class="CBFIron" name="Sn_B" type="L3STRING">
	/// ǰSn�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_B)

	/// <Property class="CBFIron" name="Sb_B" type="L3STRING">
	/// ǰSb�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_B)

	/// <Property class="CBFIron" name="As_B" type="L3STRING">
	/// ǰAs�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(As_B)

	/// <Property class="CBFIron" name="Pb_B" type="L3STRING">
	/// ǰPb�ɷ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_B)
	//End

	//add by hyh 2012-08-13 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	/// <Property class="CQA_Iron_Element" name="Ni" type="L3STRING">
	/// Ni
	/// </Property>
	DECLARE_L3PROP_STRING(Ni_B)

	/// <Property class="CQA_Iron_Element" name="Mo" type="L3STRING">
	/// Mo
	/// </Property>
	DECLARE_L3PROP_STRING(Mo_B)

	/// <Property class="CQA_Iron_Element" name="Cu" type="L3STRING">
	/// Cu
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_B)

	/// <Property class="CQA_Iron_Element" name="Cr" type="L3STRING">
	/// Cr
	/// </Property>
	DECLARE_L3PROP_STRING(Cr_B)

	/// <Property class="CQA_Iron_Element" name="B" type="L3STRING">
	/// B
	/// </Property>
	DECLARE_L3PROP_STRING(B_B)

	/// <Property class="CQA_Iron_Element" name="V" type="L3STRING">
	/// V
	/// </Property>
	DECLARE_L3PROP_STRING(V_B)

	/// <Property class="CQA_Iron_Element" name="Al" type="L3STRING">
	/// Al
	/// </Property>
	DECLARE_L3PROP_STRING(Al_B)

	/// <Property class="CQA_Iron_Element" name="Nb" type="L3STRING">
	///Nb
	/// </Property>
	DECLARE_L3PROP_STRING(Nb_B)

	/// <Property class="CQA_Iron_Element" name="Zn" type="L3STRING">
	/// Zn
	/// </Property>
	DECLARE_L3PROP_STRING(Zn_B)

	/// <Property class="CQA_Iron_Element" name="W" type="L3STRING">
	/// W
	/// </Property>
	DECLARE_L3PROP_STRING(W_B)
	//end

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

	/// <Property class="CBFIron" name="DeSFlag" type="L3LONG">
	/// �����־
	/// </Property>
	DECLARE_L3PROP_LONG(DeSFlag)

	/// <Property class="CDeS_Base_Data" name="DeSType" type="L3LONG">
	/// ��������
	/// (1:ǳ����
	///  2:��׼����
	///  3:������
	///  4:��������
	///  5:����)
	/// </Property>
	DECLARE_L3PROP_LONG(DeSType)
};
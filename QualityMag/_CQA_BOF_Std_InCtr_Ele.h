// �߼���CQA_BOF_Std_InCtr_Eleͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_InCtr_Ele :
	public CL3Object
{
public:
	CQA_BOF_Std_InCtr_Ele(void);
	virtual ~CQA_BOF_Std_InCtr_Ele(void);

	DECLARE_L3CLASS(CQA_BOF_Std_InCtr_Ele,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_InCtr_Ele)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="C_Min" type="L3STRING">
	/// C��С
	/// </Property>
	DECLARE_L3PROP_STRING(C_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="C_Aim" type="L3STRING">
	/// CĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(C_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="C_Max" type="L3STRING">
	/// C���
	/// </Property>
	DECLARE_L3PROP_STRING(C_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Si_Min" type="L3STRING">
	/// Si��С
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Si_Aim" type="L3STRING">
	/// SiĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Si_Max" type="L3STRING">
	/// Si���
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Mn_Min" type="L3STRING">
	/// Mn��С
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Mn_Aim" type="L3STRING">
	/// MnĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Mn_Max" type="L3STRING">
	/// Mn���
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="P_Min" type="L3STRING">
	/// P��С
	/// </Property>
	DECLARE_L3PROP_STRING(P_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="P_Aim" type="L3STRING">
	/// PĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(P_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="P_Max" type="L3STRING">
	/// P���
	/// </Property>
	DECLARE_L3PROP_STRING(P_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="S_Min" type="L3STRING">
	/// S��С
	/// </Property>
	DECLARE_L3PROP_STRING(S_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="S_Aim" type="L3STRING">
	/// SĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(S_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="S_Max" type="L3STRING">
	/// S���
	/// </Property>
	DECLARE_L3PROP_STRING(S_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Cu_Min" type="L3STRING">
	/// Cu��С
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Cu_Aim" type="L3STRING">
	/// CuĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Cu_Max" type="L3STRING">
	/// Cu���
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ni_Min" type="L3STRING">
	/// Ni��С
	/// </Property>
	DECLARE_L3PROP_STRING(Ni_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ni_Aim" type="L3STRING">
	/// NiĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Ni_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ni_Max" type="L3STRING">
	/// Ni���
	/// </Property>
	DECLARE_L3PROP_STRING(Ni_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Cr_Min" type="L3STRING">
	/// Cr��С
	/// </Property>
	DECLARE_L3PROP_STRING(Cr_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Cr_Aim" type="L3STRING">
	/// CrĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cr_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Cr_Max" type="L3STRING">
	/// Cr���
	/// </Property>
	DECLARE_L3PROP_STRING(Cr_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Mo_Min" type="L3STRING">
	/// Mo��С
	/// </Property>
	DECLARE_L3PROP_STRING(Mo_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Mo_Aim" type="L3STRING">
	/// MoĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Mo_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Mo_Max" type="L3STRING">
	/// Mo���
	/// </Property>
	DECLARE_L3PROP_STRING(Mo_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="V_Min" type="L3STRING">
	/// V��С
	/// </Property>
	DECLARE_L3PROP_STRING(V_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="V_Aim" type="L3STRING">
	/// VĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(V_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="V_Max" type="L3STRING">
	/// V���
	/// </Property>
	DECLARE_L3PROP_STRING(V_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Nb_Min" type="L3STRING">
	/// Nb��С
	/// </Property>
	DECLARE_L3PROP_STRING(Nb_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Nb_Aim" type="L3STRING">
	/// NbĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Nb_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Nb_Max" type="L3STRING">
	/// Nb���
	/// </Property>
	DECLARE_L3PROP_STRING(Nb_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Al_Min" type="L3STRING">
	/// Al��С
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Al_Aim" type="L3STRING">
	/// AlĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Al_Max" type="L3STRING">
	/// Al���
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="AlS_Min" type="L3STRING">
	/// AlS��С
	/// </Property>
	DECLARE_L3PROP_STRING(AlS_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="AlS_Aim" type="L3STRING">
	/// AlSĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(AlS_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="AlS_Max" type="L3STRING">
	/// AlS���
	/// </Property>
	DECLARE_L3PROP_STRING(AlS_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ti_Min" type="L3STRING">
	/// Ti��С
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ti_Aim" type="L3STRING">
	/// TiĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ti_Max" type="L3STRING">
	/// Ti���
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="B_Min" type="L3STRING">
	/// B��С
	/// </Property>
	DECLARE_L3PROP_STRING(B_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="B_Aim" type="L3STRING">
	/// BĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(B_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="B_Max" type="L3STRING">
	/// B���
	/// </Property>
	DECLARE_L3PROP_STRING(B_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Sb_Min" type="L3STRING">
	/// Sb��С
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Sb_Aim" type="L3STRING">
	/// SbĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Sb_Max" type="L3STRING">
	/// Sb���
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Sn_Min" type="L3STRING">
	/// Sn��С
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Sn_Aim" type="L3STRING">
	/// SnĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Sn_Max" type="L3STRING">
	/// Sn���
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="As_Min" type="L3STRING">
	/// As��С
	/// </Property>
	DECLARE_L3PROP_STRING(As_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="As_Aim" type="L3STRING">
	/// AsĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(As_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="As_Max" type="L3STRING">
	/// As���
	/// </Property>
	DECLARE_L3PROP_STRING(As_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Zn_Min" type="L3STRING">
	/// Zn��С
	/// </Property>
	DECLARE_L3PROP_STRING(Zn_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Zn_Aim" type="L3STRING">
	/// ZnĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Zn_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Zn_Max" type="L3STRING">
	/// Zn���
	/// </Property>
	DECLARE_L3PROP_STRING(Zn_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Zr_Min" type="L3STRING">
	/// Zr��С
	/// </Property>
	DECLARE_L3PROP_STRING(Zr_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Zr_Aim" type="L3STRING">
	/// ZrĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Zr_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Zr_Max" type="L3STRING">
	/// Zr���
	/// </Property>
	DECLARE_L3PROP_STRING(Zr_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ca_Min" type="L3STRING">
	/// Ca��С
	/// </Property>
	DECLARE_L3PROP_STRING(Ca_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ca_Aim" type="L3STRING">
	/// CaĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Ca_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ca_Max" type="L3STRING">
	/// Ca���
	/// </Property>
	DECLARE_L3PROP_STRING(Ca_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="W_Min" type="L3STRING">
	/// W��С
	/// </Property>
	DECLARE_L3PROP_STRING(W_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="W_Aim" type="L3STRING">
	/// WĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(W_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="W_Max" type="L3STRING">
	/// W���
	/// </Property>
	DECLARE_L3PROP_STRING(W_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Pb_Min" type="L3STRING">
	/// Pb��С
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Pb_Aim" type="L3STRING">
	/// PbĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Pb_Max" type="L3STRING">
	/// Pb���
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Re_Min" type="L3STRING">
	/// Re��С
	/// </Property>
	DECLARE_L3PROP_STRING(Re_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Re_Aim" type="L3STRING">
	/// ReĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Re_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Re_Max" type="L3STRING">
	/// Re���
	/// </Property>
	DECLARE_L3PROP_STRING(Re_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ceq_Min" type="L3STRING">
	/// Ceq��С
	/// </Property>
	DECLARE_L3PROP_STRING(Ceq_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ceq_Aim" type="L3STRING">
	/// CeqĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(Ceq_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Ceq_Max" type="L3STRING">
	/// Ceq���
	/// </Property>
	DECLARE_L3PROP_STRING(Ceq_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="N_Min" type="L3STRING">
	/// N��С
	/// </Property>
	DECLARE_L3PROP_STRING(N_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="N_Aim" type="L3STRING">
	/// NĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(N_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="N_Max" type="L3STRING">
	/// N���
	/// </Property>
	DECLARE_L3PROP_STRING(N_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="H_Min" type="L3STRING">
	/// H��С
	/// </Property>
	DECLARE_L3PROP_STRING(H_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="H_Aim" type="L3STRING">
	/// HĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(H_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="H_Max" type="L3STRING">
	/// H���
	/// </Property>
	DECLARE_L3PROP_STRING(H_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="O_Min" type="L3STRING">
	/// O��С
	/// </Property>
	DECLARE_L3PROP_STRING(O_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="O_Aim" type="L3STRING">
	/// OĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(O_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="O_Max" type="L3STRING">
	/// O���
	/// </Property>
	DECLARE_L3PROP_STRING(O_Max)


	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="CrNi_Min" type="L3STRING">
	/// CrNi_Min��С
	/// </Property>
	DECLARE_L3PROP_STRING(CrNi_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="CrNi_Aim" type="L3STRING">
	/// CrNi_AimĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(CrNi_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="CrNi_Max" type="L3STRING">
	/// CrNi_Max���
	/// </Property>
	DECLARE_L3PROP_STRING(CrNi_Max)


	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="CrCu_Min" type="L3STRING">
	/// CrCu_Min��С
	/// </Property>
	DECLARE_L3PROP_STRING(CrCu_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="CrCu_Aim" type="L3STRING">
	/// CrCu_AimĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(CrCu_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="CrCu_Max" type="L3STRING">
	/// CrCu_Max���
	/// </Property>
	DECLARE_L3PROP_STRING(CrCu_Max)


	
	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="CrNiCu_Min" type="L3STRING">
	/// CrNiCu_Min��С
	/// </Property>
	DECLARE_L3PROP_STRING(CrNiCu_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="CrNiCu_Aim" type="L3STRING">
	/// CrNiCu_AimĿ��
	/// </Property>
	DECLARE_L3PROP_STRING(CrNiCu_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="CrNiCu_Max" type="L3STRING">
	/// CrNiCu_Max���
	/// </Property>
	DECLARE_L3PROP_STRING(CrNiCu_Max)


	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Other1_Min" type="L3STRING">
	/// Other1��С
	/// </Property>
	DECLARE_L3PROP_STRING(Other1_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Other1_Aim" type="L3STRING">
	/// Other1Ŀ��
	/// </Property>
	DECLARE_L3PROP_STRING(Other1_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Other1_Max" type="L3STRING">
	/// Other1���
	/// </Property>
	DECLARE_L3PROP_STRING(Other1_Max)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Other2_Min" type="L3STRING">
	/// Other2��С
	/// </Property>
	DECLARE_L3PROP_STRING(Other2_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Other2_Aim" type="L3STRING">
	/// Other2Ŀ��
	/// </Property>
	DECLARE_L3PROP_STRING(Other2_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Other2_Max" type="L3STRING">
	/// Other2���
	/// </Property>
	DECLARE_L3PROP_STRING(Other2_Max)


	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Other3_Min" type="L3STRING">
	/// Other3��С
	/// </Property>
	DECLARE_L3PROP_STRING(Other3_Min)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Other3_Aim" type="L3STRING">
	/// Other3Ŀ��
	/// </Property>
	DECLARE_L3PROP_STRING(Other3_Aim)

	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="Other3_Max" type="L3STRING">
	/// Other3���
	/// </Property>
	DECLARE_L3PROP_STRING(Other3_Max)


	/// <Property class="CQA_BOF_Std_InCtr_Ele" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

};

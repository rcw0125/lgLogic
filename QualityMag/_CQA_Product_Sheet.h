// 逻辑类CQA_Product_Sheet头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Product_Sheet :
	public CL3Object
{
public:
	CQA_Product_Sheet(void);
	virtual ~CQA_Product_Sheet(void);

	DECLARE_L3CLASS(CQA_Product_Sheet,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Product_Sheet)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Product_Sheet" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)


	/// <Property class="CQA_Product_Sheet" name="Ladle_Brick" type="L3STRING">
	/// 钢包使用基准-衬砖材质
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Brick)

	/// <Property class="CQA_Product_Sheet" name="Ladle_Use" type="L3STRING">
	/// 钢包使用基准-使用状况
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Use)

	/// <Property class="CQA_Product_Sheet" name="Ladle_Pre_SteelGrade" type="L3STRING">
	/// 钢包使用基准-上炉钢种限制
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Pre_SteelGrade)

	/// <Property class="CQA_Product_Sheet" name="Ladle_Stay" type="L3STRING">
	/// 钢包使用基准-停留时间
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Stay)

	/// <Property class="CQA_Product_Sheet" name="BOF_Type" type="L3STRING">
	/// 转炉区分
	/// </Property>
	DECLARE_L3PROP_STRING(BOF_Type)

	/// <Property class="CQA_Product_Sheet" name="Ladle_Tapped_Proc" type="L3STRING">
	/// 钢包炉后处理基准
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Tapped_Proc)

	/// <Property class="CQA_Product_Sheet" name="LF_Type" type="L3STRING">
	/// LF精炼炉区分
	/// </Property>
	DECLARE_L3PROP_STRING(LF_Type)

	/// <Property class="CQA_Product_Sheet" name="RH_Type" type="L3STRING">
	/// RH精炼炉区分
	/// </Property>
	DECLARE_L3PROP_STRING(RH_Type)

	/// <Property class="CQA_Product_Sheet" name="Caster_Type" type="L3STRING">
	/// 连铸机区分
	/// </Property>
	DECLARE_L3PROP_STRING(Caster_Type)

	/// <Property class="CQA_Product_Sheet" name="Hot_Send_Flag" type="L3LONG">
	/// 送坯方式
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Send_Flag)

	/// <Property class="CQA_Product_Sheet" name="C_Min" type="L3STRING">
	/// C最小
	/// </Property>
	DECLARE_L3PROP_STRING(C_Min)

	/// <Property class="CQA_Product_Sheet" name="C_Aim" type="L3STRING">
	/// C目标
	/// </Property>
	DECLARE_L3PROP_STRING(C_Aim)

	/// <Property class="CQA_Product_Sheet" name="C_Max" type="L3STRING">
	/// C最大
	/// </Property>
	DECLARE_L3PROP_STRING(C_Max)

	/// <Property class="CQA_Product_Sheet" name="Si_Min" type="L3STRING">
	/// Si最小
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Min)

	/// <Property class="CQA_Product_Sheet" name="Si_Aim" type="L3STRING">
	/// Si目标
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Aim)

	/// <Property class="CQA_Product_Sheet" name="Si_Max" type="L3STRING">
	/// Si最大
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Max)

	/// <Property class="CQA_Product_Sheet" name="Mn_Min" type="L3STRING">
	/// Mn最小
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Min)

	/// <Property class="CQA_Product_Sheet" name="Mn_Aim" type="L3STRING">
	/// Mn目标
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Aim)

	/// <Property class="CQA_Product_Sheet" name="Mn_Max" type="L3STRING">
	/// Mn最大
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Max)

	/// <Property class="CQA_Product_Sheet" name="P_Min" type="L3STRING">
	/// P最小
	/// </Property>
	DECLARE_L3PROP_STRING(P_Min)

	/// <Property class="CQA_Product_Sheet" name="P_Aim" type="L3STRING">
	/// P目标
	/// </Property>
	DECLARE_L3PROP_STRING(P_Aim)

	/// <Property class="CQA_Product_Sheet" name="P_Max" type="L3STRING">
	/// P最大
	/// </Property>
	DECLARE_L3PROP_STRING(P_Max)

	/// <Property class="CQA_Product_Sheet" name="S_Min" type="L3STRING">
	/// S最小
	/// </Property>
	DECLARE_L3PROP_STRING(S_Min)

	/// <Property class="CQA_Product_Sheet" name="S_Aim" type="L3STRING">
	/// S目标
	/// </Property>
	DECLARE_L3PROP_STRING(S_Aim)

	/// <Property class="CQA_Product_Sheet" name="S_Max" type="L3STRING">
	/// S最大
	/// </Property>
	DECLARE_L3PROP_STRING(S_Max)

	/// <Property class="CQA_Product_Sheet" name="Cu_Min" type="L3STRING">
	/// Cu最小
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_Min)

	/// <Property class="CQA_Product_Sheet" name="Cu_Aim" type="L3STRING">
	/// Cu目标
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_Aim)

	/// <Property class="CQA_Product_Sheet" name="Cu_Max" type="L3STRING">
	/// Cu最大
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_Max)

	/// <Property class="CQA_Product_Sheet" name="Ni_Min" type="L3STRING">
	/// Ni最小
	/// </Property>
	DECLARE_L3PROP_STRING(Ni_Min)

	/// <Property class="CQA_Product_Sheet" name="Ni_Aim" type="L3STRING">
	/// Ni目标
	/// </Property>
	DECLARE_L3PROP_STRING(Ni_Aim)

	/// <Property class="CQA_Product_Sheet" name="Ni_Max" type="L3STRING">
	/// Ni最大
	/// </Property>
	DECLARE_L3PROP_STRING(Ni_Max)

	/// <Property class="CQA_Product_Sheet" name="Cr_Min" type="L3STRING">
	/// Cr最小
	/// </Property>
	DECLARE_L3PROP_STRING(Cr_Min)

	/// <Property class="CQA_Product_Sheet" name="Cr_Aim" type="L3STRING">
	/// Cr目标
	/// </Property>
	DECLARE_L3PROP_STRING(Cr_Aim)

	/// <Property class="CQA_Product_Sheet" name="Cr_Max" type="L3STRING">
	/// Cr最大
	/// </Property>
	DECLARE_L3PROP_STRING(Cr_Max)

	/// <Property class="CQA_Product_Sheet" name="Mo_Min" type="L3STRING">
	/// Mo最小
	/// </Property>
	DECLARE_L3PROP_STRING(Mo_Min)

	/// <Property class="CQA_Product_Sheet" name="Mo_Aim" type="L3STRING">
	/// Mo目标
	/// </Property>
	DECLARE_L3PROP_STRING(Mo_Aim)

	/// <Property class="CQA_Product_Sheet" name="Mo_Max" type="L3STRING">
	/// Mo最大
	/// </Property>
	DECLARE_L3PROP_STRING(Mo_Max)

	/// <Property class="CQA_Product_Sheet" name="V_Min" type="L3STRING">
	/// V最小
	/// </Property>
	DECLARE_L3PROP_STRING(V_Min)

	/// <Property class="CQA_Product_Sheet" name="V_Aim" type="L3STRING">
	/// V目标
	/// </Property>
	DECLARE_L3PROP_STRING(V_Aim)

	/// <Property class="CQA_Product_Sheet" name="V_Max" type="L3STRING">
	/// V最大
	/// </Property>
	DECLARE_L3PROP_STRING(V_Max)

	/// <Property class="CQA_Product_Sheet" name="Nb_Min" type="L3STRING">
	/// Nb最小
	/// </Property>
	DECLARE_L3PROP_STRING(Nb_Min)

	/// <Property class="CQA_Product_Sheet" name="Nb_Aim" type="L3STRING">
	/// Nb目标
	/// </Property>
	DECLARE_L3PROP_STRING(Nb_Aim)

	/// <Property class="CQA_Product_Sheet" name="Nb_Max" type="L3STRING">
	/// Nb最大
	/// </Property>
	DECLARE_L3PROP_STRING(Nb_Max)

	/// <Property class="CQA_Product_Sheet" name="Al_Min" type="L3STRING">
	/// Al最小
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Min)

	/// <Property class="CQA_Product_Sheet" name="Al_Aim" type="L3STRING">
	/// Al目标
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Aim)

	/// <Property class="CQA_Product_Sheet" name="Al_Max" type="L3STRING">
	/// Al最大
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Max)

	/// <Property class="CQA_Product_Sheet" name="AlS_Min" type="L3STRING">
	/// AlS最小
	/// </Property>
	DECLARE_L3PROP_STRING(AlS_Min)

	/// <Property class="CQA_Product_Sheet" name="AlS_Aim" type="L3STRING">
	/// AlS目标
	/// </Property>
	DECLARE_L3PROP_STRING(AlS_Aim)

	/// <Property class="CQA_Product_Sheet" name="AlS_Max" type="L3STRING">
	/// AlS最大
	/// </Property>
	DECLARE_L3PROP_STRING(AlS_Max)

	/// <Property class="CQA_Product_Sheet" name="Ti_Min" type="L3STRING">
	/// Ti最小
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Min)

	/// <Property class="CQA_Product_Sheet" name="Ti_Aim" type="L3STRING">
	/// Ti目标
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Aim)

	/// <Property class="CQA_Product_Sheet" name="Ti_Max" type="L3STRING">
	/// Ti最大
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Max)

	/// <Property class="CQA_Product_Sheet" name="B_Min" type="L3STRING">
	/// B最小
	/// </Property>
	DECLARE_L3PROP_STRING(B_Min)

	/// <Property class="CQA_Product_Sheet" name="B_Aim" type="L3STRING">
	/// B目标
	/// </Property>
	DECLARE_L3PROP_STRING(B_Aim)

	/// <Property class="CQA_Product_Sheet" name="B_Max" type="L3STRING">
	/// B最大
	/// </Property>
	DECLARE_L3PROP_STRING(B_Max)

	/// <Property class="CQA_Product_Sheet" name="Sb_Min" type="L3STRING">
	/// Sb最小
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Min)

	/// <Property class="CQA_Product_Sheet" name="Sb_Aim" type="L3STRING">
	/// Sb目标
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Aim)

	/// <Property class="CQA_Product_Sheet" name="Sb_Max" type="L3STRING">
	/// Sb最大
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Max)

	/// <Property class="CQA_Product_Sheet" name="Sn_Min" type="L3STRING">
	/// Sn最小
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Min)

	/// <Property class="CQA_Product_Sheet" name="Sn_Aim" type="L3STRING">
	/// Sn目标
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Aim)

	/// <Property class="CQA_Product_Sheet" name="Sn_Max" type="L3STRING">
	/// Sn最大
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Max)

	/// <Property class="CQA_Product_Sheet" name="As_Min" type="L3STRING">
	/// As最小
	/// </Property>
	DECLARE_L3PROP_STRING(As_Min)

	/// <Property class="CQA_Product_Sheet" name="As_Aim" type="L3STRING">
	/// As目标
	/// </Property>
	DECLARE_L3PROP_STRING(As_Aim)

	/// <Property class="CQA_Product_Sheet" name="As_Max" type="L3STRING">
	/// As最大
	/// </Property>
	DECLARE_L3PROP_STRING(As_Max)

	/// <Property class="CQA_Product_Sheet" name="Zn_Min" type="L3STRING">
	/// Zn最小
	/// </Property>
	DECLARE_L3PROP_STRING(Zn_Min)

	/// <Property class="CQA_Product_Sheet" name="Zn_Aim" type="L3STRING">
	/// Zn目标
	/// </Property>
	DECLARE_L3PROP_STRING(Zn_Aim)

	/// <Property class="CQA_Product_Sheet" name="Zn_Max" type="L3STRING">
	/// Zn最大
	/// </Property>
	DECLARE_L3PROP_STRING(Zn_Max)

	/// <Property class="CQA_Product_Sheet" name="Zr_Min" type="L3STRING">
	/// Zr最小
	/// </Property>
	DECLARE_L3PROP_STRING(Zr_Min)

	/// <Property class="CQA_Product_Sheet" name="Zr_Aim" type="L3STRING">
	/// Zr目标
	/// </Property>
	DECLARE_L3PROP_STRING(Zr_Aim)

	/// <Property class="CQA_Product_Sheet" name="Zr_Max" type="L3STRING">
	/// Zr最大
	/// </Property>
	DECLARE_L3PROP_STRING(Zr_Max)

	/// <Property class="CQA_Product_Sheet" name="Ca_Min" type="L3STRING">
	/// Ca最小
	/// </Property>
	DECLARE_L3PROP_STRING(Ca_Min)

	/// <Property class="CQA_Product_Sheet" name="Ca_Aim" type="L3STRING">
	/// Ca目标
	/// </Property>
	DECLARE_L3PROP_STRING(Ca_Aim)

	/// <Property class="CQA_Product_Sheet" name="Ca_Max" type="L3STRING">
	/// Ca最大
	/// </Property>
	DECLARE_L3PROP_STRING(Ca_Max)

	/// <Property class="CQA_Product_Sheet" name="W_Min" type="L3STRING">
	/// W最小
	/// </Property>
	DECLARE_L3PROP_STRING(W_Min)

	/// <Property class="CQA_Product_Sheet" name="W_Aim" type="L3STRING">
	/// W目标
	/// </Property>
	DECLARE_L3PROP_STRING(W_Aim)

	/// <Property class="CQA_Product_Sheet" name="W_Max" type="L3STRING">
	/// W最大
	/// </Property>
	DECLARE_L3PROP_STRING(W_Max)

	/// <Property class="CQA_Product_Sheet" name="Pb_Min" type="L3STRING">
	/// Pb最小
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Min)

	/// <Property class="CQA_Product_Sheet" name="Pb_Aim" type="L3STRING">
	/// Pb目标
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Aim)

	/// <Property class="CQA_Product_Sheet" name="Pb_Max" type="L3STRING">
	/// Pb最大
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Max)

	/// <Property class="CQA_Product_Sheet" name="Re_Min" type="L3STRING">
	/// Re最小
	/// </Property>
	DECLARE_L3PROP_STRING(Re_Min)

	/// <Property class="CQA_Product_Sheet" name="Re_Aim" type="L3STRING">
	/// Re目标
	/// </Property>
	DECLARE_L3PROP_STRING(Re_Aim)

	/// <Property class="CQA_Product_Sheet" name="Re_Max" type="L3STRING">
	/// Re最大
	/// </Property>
	DECLARE_L3PROP_STRING(Re_Max)

	/// <Property class="CQA_Product_Sheet" name="Ceq_Min" type="L3STRING">
	/// Ceq最小
	/// </Property>
	DECLARE_L3PROP_STRING(Ceq_Min)

	/// <Property class="CQA_Product_Sheet" name="Ceq_Aim" type="L3STRING">
	/// Ceq目标
	/// </Property>
	DECLARE_L3PROP_STRING(Ceq_Aim)

	/// <Property class="CQA_Product_Sheet" name="Ceq_Max" type="L3STRING">
	/// Ceq最大
	/// </Property>
	DECLARE_L3PROP_STRING(Ceq_Max)

	/// <Property class="CQA_Product_Sheet" name="N_Min" type="L3STRING">
	/// N最小
	/// </Property>
	DECLARE_L3PROP_STRING(N_Min)

	/// <Property class="CQA_Product_Sheet" name="N_Aim" type="L3STRING">
	/// N目标
	/// </Property>
	DECLARE_L3PROP_STRING(N_Aim)

	/// <Property class="CQA_Product_Sheet" name="N_Max" type="L3STRING">
	/// N最大
	/// </Property>
	DECLARE_L3PROP_STRING(N_Max)

	/// <Property class="CQA_Product_Sheet" name="H_Min" type="L3STRING">
	/// H最小
	/// </Property>
	DECLARE_L3PROP_STRING(H_Min)

	/// <Property class="CQA_Product_Sheet" name="H_Aim" type="L3STRING">
	/// H目标
	/// </Property>
	DECLARE_L3PROP_STRING(H_Aim)

	/// <Property class="CQA_Product_Sheet" name="H_Max" type="L3STRING">
	/// H最大
	/// </Property>
	DECLARE_L3PROP_STRING(H_Max)

	/// <Property class="CQA_Product_Sheet" name="O_Min" type="L3STRING">
	/// O最小
	/// </Property>
	DECLARE_L3PROP_STRING(O_Min)

	/// <Property class="CQA_Product_Sheet" name="O_Aim" type="L3STRING">
	/// O目标
	/// </Property>
	DECLARE_L3PROP_STRING(O_Aim)

	/// <Property class="CQA_Product_Sheet" name="O_Max" type="L3STRING">
	/// O最大
	/// </Property>
	DECLARE_L3PROP_STRING(O_Max)

	/// <Property class="CQA_Product_Sheet" name="CrNi_Min" type="L3STRING">
	/// CrNi_Min最小
	/// </Property>
	DECLARE_L3PROP_STRING(CrNi_Min)

	/// <Property class="CQA_Product_Sheet" name="CrNi_Aim" type="L3STRING">
	/// CrNi_Aim目标
	/// </Property>
	DECLARE_L3PROP_STRING(CrNi_Aim)

	/// <Property class="CQA_Product_Sheet" name="CrNi_Max" type="L3STRING">
	/// CrNi_Max最大
	/// </Property>
	DECLARE_L3PROP_STRING(CrNi_Max)


	/// <Property class="CQA_Product_Sheet" name="CrCu_Min" type="L3STRING">
	/// CrCu_Min最小
	/// </Property>
	DECLARE_L3PROP_STRING(CrCu_Min)

	/// <Property class="CQA_Product_Sheet" name="CrCu_Aim" type="L3STRING">
	/// CrCu_Aim目标
	/// </Property>
	DECLARE_L3PROP_STRING(CrCu_Aim)

	/// <Property class="CQA_Product_Sheet" name="CrCu_Max" type="L3STRING">
	/// CrCu_Max最大
	/// </Property>
	DECLARE_L3PROP_STRING(CrCu_Max)


	
	/// <Property class="CQA_Product_Sheet" name="CrNiCu_Min" type="L3STRING">
	/// CrNiCu_Min最小
	/// </Property>
	DECLARE_L3PROP_STRING(CrNiCu_Min)

	/// <Property class="CQA_Product_Sheet" name="CrNiCu_Aim" type="L3STRING">
	/// CrNiCu_Aim目标
	/// </Property>
	DECLARE_L3PROP_STRING(CrNiCu_Aim)

	/// <Property class="CQA_Product_Sheet" name="CrNiCu_Max" type="L3STRING">
	/// CrNiCu_Max最大
	/// </Property>
	DECLARE_L3PROP_STRING(CrNiCu_Max)


	/// <Property class="CQA_Product_Sheet" name="Other1_Min" type="L3STRING">
	/// Other1最小
	/// </Property>
	DECLARE_L3PROP_STRING(Other1_Min)

	/// <Property class="CQA_Product_Sheet" name="Other1_Aim" type="L3STRING">
	/// Other1目标
	/// </Property>
	DECLARE_L3PROP_STRING(Other1_Aim)

	/// <Property class="CQA_Product_Sheet" name="Other1_Max" type="L3STRING">
	/// Other1最大
	/// </Property>
	DECLARE_L3PROP_STRING(Other1_Max)

	/// <Property class="CQA_Product_Sheet" name="Other2_Min" type="L3STRING">
	/// Other2最小
	/// </Property>
	DECLARE_L3PROP_STRING(Other2_Min)

	/// <Property class="CQA_Product_Sheet" name="Other2_Aim" type="L3STRING">
	/// Other2目标
	/// </Property>
	DECLARE_L3PROP_STRING(Other2_Aim)

	/// <Property class="CQA_Product_Sheet" name="Other2_Max" type="L3STRING">
	/// Other2最大
	/// </Property>
	DECLARE_L3PROP_STRING(Other2_Max)


	/// <Property class="CQA_Product_Sheet" name="Other3_Min" type="L3STRING">
	/// Other3最小
	/// </Property>
	DECLARE_L3PROP_STRING(Other3_Min)

	/// <Property class="CQA_Product_Sheet" name="Other3_Aim" type="L3STRING">
	/// Other3目标
	/// </Property>
	DECLARE_L3PROP_STRING(Other3_Aim)

	/// <Property class="CQA_Product_Sheet" name="Other3_Max" type="L3STRING">
	/// Other3最大
	/// </Property>
	DECLARE_L3PROP_STRING(Other3_Max)
};

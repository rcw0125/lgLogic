// �߼���CEnergy_Manual_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEnergy_Manual_Data :
	public CL3Object
{
public:
	CEnergy_Manual_Data(void);
	virtual ~CEnergy_Manual_Data(void);

	DECLARE_L3CLASS(CEnergy_Manual_Data,XGMESLogic\\EnergyMag, ProductionDate)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergy_Manual_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEnergy_Manual_Data" name="ProductionDate" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(ProductionDate)

	/// <Property class="CEnergy_Manual_Data" name="Flow_CFCO" type="L3FLOAT">
	/// ��¯ú��˲ʱ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_CFCO)

	/// <Property class="CEnergy_Manual_Data" name="Flow_BOFCO" type="L3FLOAT">
	/// ת¯ú��˲ʱ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_BOFCO)

	/// <Property class="CEnergy_Manual_Data" name="Flow_BOFCO_CallBack" type="L3FLOAT">
	/// ת¯ú������˲ʱ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_BOFCO_CallBack)

	/// <Property class="CEnergy_Manual_Data" name="Flow_N2" type="L3FLOAT">
	/// ����˲ʱ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_N2)

	/// <Property class="CEnergy_Manual_Data" name="Flow_N2_SpecialSteel" type="L3FLOAT">
	/// ��Ʒ�ֵ���˲ʱ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_N2_SpecialSteel)

	/// <Property class="CEnergy_Manual_Data" name="Flow_O2" type="L3FLOAT">
	/// ����˲ʱ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_O2)

	/// <Property class="CEnergy_Manual_Data" name="CFCO_D" type="L3FLOAT">
	/// ��¯ú����������
	/// </Property>
	DECLARE_L3PROP_FLOAT(CFCO_D)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_D" type="L3FLOAT">
	/// ת¯ú����������
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_D)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_CallBack_D" type="L3FLOAT">
	/// ת¯ú��������������
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_CallBack_D)

	/// <Property class="CEnergy_Manual_Data" name="N2_D" type="L3FLOAT">
	/// ����˲ʱ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_D)

	/// <Property class="CEnergy_Manual_Data" name="N2_SpecialSteel_D" type="L3FLOAT">
	/// ��Ʒ�ֵ�����������
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_SpecialSteel_D)

	/// <Property class="CEnergy_Manual_Data" name="O2_D" type="L3FLOAT">
	/// ������������
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_D)

	/// <Property class="CEnergy_Manual_Data" name="CFCO_D_Avg" type="L3FLOAT">
	/// ��¯ú���յ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(CFCO_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_D_Avg" type="L3FLOAT">
	/// ת¯ú���յ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_CallBack_D_Avg" type="L3FLOAT">
	/// ת¯ú�������յ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_CallBack_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="N2_D_Avg" type="L3FLOAT">
	/// �����յ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="N2_SpecialSteel_D_Avg" type="L3FLOAT">
	/// ��Ʒ�ֵ����յ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_SpecialSteel_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="O2_D_Avg" type="L3FLOAT">
	/// �����յ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="CFCO_M" type="L3FLOAT">
	/// ��¯ú���ۼ�����
	/// </Property>
	DECLARE_L3PROP_FLOAT(CFCO_M)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_M" type="L3FLOAT">
	/// ת¯ú���ۼ�����
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_M)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_CallBack_M" type="L3FLOAT">
	/// ת¯ú�������ۼ�����
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_CallBack_M)

	/// <Property class="CEnergy_Manual_Data" name="N2_M" type="L3FLOAT">
	/// �����ۼ�����
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_M)

	/// <Property class="CEnergy_Manual_Data" name="N2_SpecialSteel_M" type="L3FLOAT">
	/// ��Ʒ�ֵ����ۼ�����
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_SpecialSteel_M)

	/// <Property class="CEnergy_Manual_Data" name="O2_M" type="L3FLOAT">
	/// �����ۼ�����
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_M)

	/// <Property class="CEnergy_Manual_Data" name="CFCO_M_Avg" type="L3FLOAT">
	/// ��¯ú���ۼƵ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(CFCO_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_M_Avg" type="L3FLOAT">
	/// ת¯ú���ۼƵ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_CallBack_M_Avg" type="L3FLOAT">
	/// ת¯ú�������ۼƵ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_CallBack_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="N2_M_Avg" type="L3FLOAT">
	/// �����ۼƵ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="N2_SpecialSteel_M_Avg" type="L3FLOAT">
	/// ��Ʒ�ֵ����ۼƵ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_SpecialSteel_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="O2_M_Avg" type="L3FLOAT">
	/// �����ۼƵ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="Production_D" type="L3FLOAT">
	/// �ղ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(Production_D)

	/// <Property class="CEnergy_Manual_Data" name="Production_M" type="L3FLOAT">
	/// �ۼƲ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(Production_M)

	/// <Property class="CEnergy_Manual_Data" name="CreateTime" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

	/// <Property class="CEnergy_Manual_Data" name="Operator" type="L3STRING">
	/// ����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEnergy_Manual_Data" name="Status" type="L3LONG">
	/// ״̬ 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CEnergy_Manual_Data" name="Production_Special_D" type="L3FLOAT">
	/// ��Ʒ���ղ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(Production_Special_D)

	/// <Property class="CEnergy_Manual_Data" name="Production_Special_M" type="L3FLOAT">
	/// ��Ʒ���ۼƲ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(Production_Special_M)
};

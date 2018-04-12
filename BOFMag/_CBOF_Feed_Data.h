// �߼���CBOF_Feed_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_Feed_Data :
	public CL3Object
{
public:
	CBOF_Feed_Data(void);
	virtual ~CBOF_Feed_Data(void);

	DECLARE_L3CLASS(CBOF_Feed_Data,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Feed_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_Feed_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_Feed_Data" name="IronWeight" type="L3FLOAT">
	/// ��ˮ��
	/// </Property>
	DECLARE_L3PROP_FLOAT(IronWeight)

	/// <Property class="CBOF_Feed_Data" name="ScrapWeight" type="L3FLOAT">
	/// �ϸ���
	/// </Property>
	DECLARE_L3PROP_FLOAT(ScrapWeight)

	/// <Property class="CBOF_Feed_Data" name="PigIronWeight" type="L3FLOAT">
	/// 
	/// ��������
	/// 
	/// </Property>
	DECLARE_L3PROP_FLOAT(PigIronWeight)

	/// <Property class="CBOF_Feed_Data" name="Return_Steel_Weight" type="L3FLOAT">
	/// 
	/// ��¯����
	/// 
	/// </Property>
	DECLARE_L3PROP_FLOAT(Return_Steel_Weight)

	/// <Property class="CBOF_Feed_Data" name="C" type="L3FLOAT">
	/// ̼�ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(C)

	/// <Property class="CBOF_Feed_Data" name="Si" type="L3FLOAT">
	/// ��ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Si)

	/// <Property class="CBOF_Feed_Data" name="Mn" type="L3FLOAT">
	/// �̳ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Mn)

	/// <Property class="CBOF_Feed_Data" name="P" type="L3FLOAT">
	/// �׳ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(P)

	/// <Property class="CBOF_Feed_Data" name="S" type="L3FLOAT">
	/// ��ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(S)

	/// <Property class="CBOF_Feed_Data" name="Ti" type="L3FLOAT">
	/// �ѳɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Ti)

	//add by hyh 2012-04-05
	/// <Property class="CBOF_Feed_Data" name="Sn" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(Sn)

	/// <Property class="CBOF_Feed_Data" name="Sb" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(Sb)

	/// <Property class="CBOF_Feed_Data" name="As" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(As)

	/// <Property class="CBOF_Feed_Data" name="Pb" type="L3FLOAT">
	/// </Property>
	DECLARE_L3PROP_FLOAT(Pb)

	//add by hyh 2012-08-09 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
	/// <Property class="CIron_Data" name="Ni" type="L3FLOAT">
	/// ���ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Ni)

	/// <Property class="CIron_Data" name="Mo" type="L3FLOAT">
	/// ��ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Mo)

	/// <Property class="CIron_Data" name="Cu" type="L3FLOAT">
	/// ͭ�ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Cu)

	/// <Property class="CIron_Data" name="Cr" type="L3FLOAT">
	/// ���ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Cr)

	/// <Property class="CIron_Data" name="B" type="L3FLOAT">
	/// ��ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(B)

	/// <Property class="CIron_Data" name="V" type="L3FLOAT">
	/// ���ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(V)

	/// <Property class="CIron_Data" name="Al" type="L3FLOAT">
	/// ���ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Al)

	/// <Property class="CIron_Data" name="Nb" type="L3FLOAT">
	/// ��ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Nb)

	/// <Property class="CIron_Data" name="Zn" type="L3FLOAT">
	/// п�ɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(Zn)

	/// <Property class="CIron_Data" name="W type="L3FLOAT">
	/// �ٳɷ�ֵ
	/// </Property>
	DECLARE_L3PROP_FLOAT(W)
	//end

	/// <Property class="CBOF_Feed_Data" name="IronTemp" type="L3LONG">
	/// ��ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_LONG(IronTemp)

	/// <Property class="CBOF_Feed_Data" name="LogTime" type="L3DATETIME">
	/// ָ����ԭ��ʱ��2009-03-03
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CBOF_Feed_Data" name="Return_SteelGrade" type="L3STRING">
	/// ��¯�ָ���2009-03-03
	/// </Property>
	DECLARE_L3PROP_STRING(Return_SteelGrade)


};

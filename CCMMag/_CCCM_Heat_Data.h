// �߼���CCCM_Heat_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_Data :
	public CL3Object
{
public:
	CCCM_Heat_Data(void);
	virtual ~CCCM_Heat_Data(void);

	DECLARE_L3CLASS(CCCM_Heat_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Data" name="CastingID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingID)

	/// <Property class="CCCM_Heat_Data" name="CCMID" type="L3SHORT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_SHORT(CCMID)

	/// <Property class="CCCM_Heat_Data" name="Tundish_SeqNo" type="L3STRING">
	/// �а����
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_SeqNo)

	/// <Property class="CCCM_Heat_Data" name="TreatNo" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Heat_Data" name="Casting_HeatNum" type="L3LONG">
	/// ������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Casting_HeatNum)

	/// <Property class="CCCM_Heat_Data" name="Tundish_HeatNum" type="L3LONG">
	/// �������������
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_HeatNum)

	/// <Property class="CCCM_Heat_Data" name="Pre_HeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_HeatID)

	/// <Property class="CCCM_Heat_Data" name="Pre_LotNo" type="L3STRING">
	/// Ԥ�����κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_LotNo)

	/// <Property class="CCCM_Heat_Data" name="ShopSign" type="L3STRING">
	/// ��Ʒ�ƺ�
	/// </Property>
	DECLARE_L3PROP_STRING(ShopSign)

	/// <Property class="CCCM_Heat_Data" name="Casting_Width" type="L3FLOAT">
	/// �����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Casting_Width)

	/// <Property class="CCCM_Heat_Data" name="Casting_Thickness" type="L3FLOAT">
	/// �����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Casting_Thickness)

	/// <Property class="CCCM_Heat_Data" name="Introduced_Count" type="L3LONG">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_LONG(Introduced_Count)

	/// <Property class="CCCM_Heat_Data" name="Protect_Casting" type="L3LONG">
	/// 
	/// ������ע
	/// (1-��
	///  0-����)
	/// </Property>
	DECLARE_L3PROP_LONG(Protect_Casting)

	/// <Property class="CCCM_Heat_Data" name="Blooms_Num" type="L3LONG">
	/// ����֧��
	/// </Property>
	DECLARE_L3PROP_LONG(Blooms_Num)

	/// <Property class="CCCM_Heat_Data" name="Primary_Weight" type="L3LONG">
	/// ������
	/// </Property>
	DECLARE_L3PROP_LONG(Primary_Weight)

	/// <Property class="CCCM_Heat_Data" name="StdBlooms_Num" type="L3LONG">
	/// �ϸ�֧��
	/// </Property>
	DECLARE_L3PROP_LONG(StdBlooms_Num)

	/// <Property class="CCCM_Heat_Data" name="StdBlooms_Weight" type="L3LONG">
	/// �ϸ�����
	/// </Property>
	DECLARE_L3PROP_LONG(StdBlooms_Weight)

	/// <Property class="CCCM_Heat_Data" name="SubStd_Blooms_Num" type="L3LONG">
	/// ���ϸ�֧��
	/// </Property>
	DECLARE_L3PROP_LONG(SubStd_Blooms_Num)

	/// <Property class="CCCM_Heat_Data" name="SubStd_Blooms_Weight" type="L3LONG">
	/// ���ϸ�����
	/// </Property>
	DECLARE_L3PROP_LONG(SubStd_Blooms_Weight)

	/// <Property class="CCCM_Heat_Data" name="Waster_Num" type="L3LONG">
	/// ˦��֧��
	/// </Property>
	DECLARE_L3PROP_LONG(Waster_Num)

	/// <Property class="CCCM_Heat_Data" name="FinalCut_Time" type="L3DATETIME">
	/// �����ж�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(FinalCut_Time)

	/// <Property class="CCCM_Heat_Data" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CCCM_Heat_Data" name="Waster_Weight" type="L3LONG">
	/// ˦������
	/// </Property>
	DECLARE_L3PROP_LONG(Waster_Weight)

	/// <Property class="CCCM_Heat_Data" name="Goods_Num" type="L3LONG">
	/// �ϸ�֧��
	/// </Property>
	DECLARE_L3PROP_LONG(Goods_Num)

	/// <Property class="CCCM_Heat_Data" name="InjectionBar_BlowAr" type="L3SHORT">
	/// 
	/// �Ƿ��������
	/// (1-��
	///  0-����)
	/// </Property>
	DECLARE_L3PROP_SHORT(InjectionBar_BlowAr)

	/// <Property class="CCCM_Heat_Data" name="Thickness" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CCCM_Heat_Data" name="Width" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CCCM_Heat_Data" name="Length" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CCCM_Heat_Data" name="Steel_Return_Div" type="L3SHORT">
	/// 
	/// ��ˮ��������
	/// (
	/// 0|����
	/// 1|CC��ȫ���ƶ�
	/// 2|CC�䲿���ƶ�
	/// 3|ȫ�����;���
	/// 4|���ݷ��;���
	/// 7|ȫ����¯
	/// 8|���ݻ�¯
	/// 9|����)
	/// 
	/// </Property>
	DECLARE_L3PROP_SHORT(Steel_Return_Div)

	/// <Property class="CCCM_Heat_Data" name="Weight_Return" type="L3DOUBLE">
	/// ���ظ�ˮ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Return)

	/// <Property class="CCCM_Heat_Data" name="Second_Cooling_Mode" type="L3SHORT">
	/// 
	/// ����ˮģʽ
	/// (1-L1��2-L2��0-�ֶ�)
	/// </Property>
	DECLARE_L3PROP_SHORT(Second_Cooling_Mode)

	/// <Property class="CCCM_Heat_Data" name="Second_Cooling_CurveNo" type="L3SHORT">
	/// ����ˮˮ���
	/// </Property>
	DECLARE_L3PROP_SHORT(Second_Cooling_CurveNo)

	/// <Property class="CCCM_Heat_Data" name="Weight_Cut_Head" type="L3DOUBLE">
	/// ��ͷ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Cut_Head)

	/// <Property class="CCCM_Heat_Data" name="Weight_Cut_Trail" type="L3DOUBLE">
	/// ��β��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Cut_Trail)

	/// <Property class="CCCM_Heat_Data" name="Leak_Steel_Num" type="L3LONG">
	/// ©�ִ���
	/// </Property>
	DECLARE_L3PROP_LONG(Leak_Steel_Num)

};

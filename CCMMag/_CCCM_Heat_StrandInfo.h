// �߼���CCCM_Heat_StrandInfoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_StrandInfo :
	public CL3Object
{
public:
	CCCM_Heat_StrandInfo(void);
	virtual ~CCCM_Heat_StrandInfo(void);

	DECLARE_L3CLASS(CCCM_Heat_StrandInfo,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_StrandInfo)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	///2009-02-13 ɾ���а���,���ӻ�����š�Һ�沨�����Ƿ����������ԭ��©�ִ������ᾧ����š�ͭ�ܱ�ţ�5#��ͭ�壩��ͭ�ܣ�ͭ�壩���ҡ�¯��ͨ�������ۼ�ͨ����(��ͭ�ܱ���ۼ�)

	/// <Property class="CCCM_Heat_StrandInfo" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_StrandInfo" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_StrandInfo" name="StrandID" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(StrandID)

	/// <Property class="CCCM_Heat_StrandInfo" name="Soft_Press_Flag" type="L3LONG">
	/// 
	/// ��ѹ��
	/// (1-��ѹ��
	///  0-����ѹ��)
	/// </Property>
	DECLARE_L3PROP_LONG(Soft_Press_Flag)

	/// <Property class="CCCM_Heat_StrandInfo" name="Auto_Control" type="L3LONG">
	/// 
	/// Һ���Զ�����
	/// (1-�Զ�����
	///  0-���Զ�����)
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Control)

	/// <Property class="CCCM_Heat_StrandInfo" name="Start_Time" type="L3DATETIME">
	/// ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CCCM_Heat_StrandInfo" name="Stop_Time" type="L3DATETIME">
	/// ��ͣ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Stop_Time)

	/// <Property class="CCCM_Heat_StrandInfo" name="Cast_Num" type="L3LONG">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_LONG(Cast_Num)


	/// <Property class="CCCM_Heat_StrandInfo" name="WaterGap_Center" type="L3LONG">
	/// 
	/// ˮ���Ƿ����(0-����;1-ƫ��;2-ƫ��)
	/// </Property>
	DECLARE_L3PROP_LONG(WaterGap_Center)

	/// <Property class="CCCM_Heat_StrandInfo" name="WaterGap_Deepness" type="L3LONG">
	/// 
	/// ˮ�����
	/// 
	/// </Property>
	DECLARE_L3PROP_LONG(WaterGap_Deepness)

	/// <Property class="CCCM_Heat_StrandInfo" name="CastingStatus" type="L3LONG">
	/// ��ͣ��״̬
	/// </Property>
	DECLARE_L3PROP_LONG(CastingStatus)

	/// <Property class="CCCM_Heat_StrandInfo" name="Code" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Code)

	/// <Property class="CCCM_Heat_StrandInfo" name="liquid_level" type="L3STRING">
	/// Һ�沨��
	/// </Property>
	DECLARE_L3PROP_STRING(liquid_level)

	/// <Property class="CCCM_Heat_StrandInfo" name="Block_Up" type="L3LONG">
	/// �Ƿ����
	/// </Property>
	DECLARE_L3PROP_LONG(Block_Up)


	/// <Property class="CCCM_Heat_StrandInfo" name="Block_Up_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Block_Up_Reason)

	/// <Property class="CCCM_Heat_StrandInfo" name="BreakOut_Num" type="L3LONG">
	/// ©�ִ���
	/// </Property>
	DECLARE_L3PROP_LONG(BreakOut_Num)


	/// <Property class="CCCM_Heat_StrandInfo" name="MoldID" type="L3STRING">
	/// �ᾧ�����
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CCCM_Heat_StrandInfo" name="Copper_Fac" type="L3STRING">
	/// ͭ��(��)����
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CCCM_Heat_StrandInfo" name="Copper_ID" type="L3STRING">
	/// ͭ��(��)���
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_ID)

	/// <Property class="CCCM_Heat_StrandInfo" name="Heat_Weight" type="L3DOUBLE">
	/// ¯��ͨ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Heat_Weight)

	/// <Property class="CCCM_Heat_StrandInfo" name="Total_Weight" type="L3DOUBLE">
	/// �ۼ�ͨ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Total_Weight)

};

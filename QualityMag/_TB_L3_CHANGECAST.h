// �߼���TB_L3_CHANGECASTͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class TB_L3_CHANGECAST :
	public CL3Object
{
public:
	TB_L3_CHANGECAST(void);
	virtual ~TB_L3_CHANGECAST(void);

	DECLARE_L3CLASS(TB_L3_CHANGECAST,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(TB_L3_CHANGECAST)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="TB_L3_CHANGECAST" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="TB_L3_CHANGECAST" name="CastingNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="TB_L3_CHANGECAST" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="TB_L3_CHANGECAST" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="TB_L3_CHANGECAST" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="TB_L3_CHANGECAST" name="ProductionDate" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(ProductionDate)

	/// <Property class="TB_L3_CHANGECAST" name="Permit_Delete_Flag" type="L3LONG">
	/// ����ɾ����־
	/// </Property>
	DECLARE_L3PROP_LONG(Permit_Delete_Flag)


};

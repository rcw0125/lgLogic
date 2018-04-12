// �߼���CCCM_Casting_StrandInfoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Casting_StrandInfo :
	public CL3Object
{
public:
	CCCM_Casting_StrandInfo(void);
	virtual ~CCCM_Casting_StrandInfo(void);

	DECLARE_L3CLASS(CCCM_Casting_StrandInfo,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Casting_StrandInfo)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Casting_StrandInfo" name="CastingNo" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Casting_StrandInfo" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Casting_StrandInfo" name="StrandNo" type="L3SHORT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandNo)

	/// <Property class="CCCM_Casting_StrandInfo" name="LEAD_TIME" type="L3DATETIME">
	/// ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(LEAD_TIME)

	/// <Property class="CCCM_Casting_StrandInfo" name="Mold" type="L3STRING">
	/// �ᾧ����
	/// </Property>
	DECLARE_L3PROP_STRING(Mold)

	/// <Property class="CCCM_Casting_StrandInfo" name="Cu_Factory" type="L3STRING">
	/// ͭ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_Factory)

	/// <Property class="CCCM_Casting_StrandInfo" name="Pass_Steel_Weight" type="L3DOUBLE">
	/// ͨ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pass_Steel_Weight)

};

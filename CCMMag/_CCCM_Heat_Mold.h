// �߼���CCCM_Heat_Moldͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Heat_Mold :
	public CL3Object
{
public:
	CCCM_Heat_Mold(void);
	virtual ~CCCM_Heat_Mold(void);

	DECLARE_L3CLASS(CCCM_Heat_Mold,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Mold)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_Mold" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Mold" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Mold" name="StrandID" type="L3SHORT">
	/// �ᾧ������
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandID)

	/// <Property class="CCCM_Heat_Mold" name="Flow" type="L3FLOAT">
	/// �ᾧ��ˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow)

	/// <Property class="CCCM_Heat_Mold" name="Wide_Flow" type="L3FLOAT">
	/// �ᾧ������ˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Wide_Flow)

	/// <Property class="CCCM_Heat_Mold" name="Narrow_Flow" type="L3FLOAT">
	/// �ᾧ��խ��ˮ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Narrow_Flow)

	/// <Property class="CCCM_Heat_Mold" name="In_Temp" type="L3SHORT">
	/// �ᾧ����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_SHORT(In_Temp)

	/// <Property class="CCCM_Heat_Mold" name="Out_Temp" type="L3SHORT">
	/// �ᾧ����ˮ�¶�
	/// </Property>
	DECLARE_L3PROP_SHORT(Out_Temp)

	/// <Property class="CCCM_Heat_Mold" name="Diff_Temp" type="L3SHORT">
	/// �ᾧ��ˮ�²�
	/// </Property>
	DECLARE_L3PROP_SHORT(Diff_Temp)

};

// �߼���CMIF_Chemicalͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMIF_Chemical :
	public CL3Object
{
public:
	CMIF_Chemical(void);
	virtual ~CMIF_Chemical(void);

	DECLARE_L3CLASS(CMIF_Chemical,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Chemical)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CMIF_Chemical" name="Sample_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Sample_Time)

	/// <Property class="CMIF_Chemical" name="C" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(C)

	/// <Property class="CMIF_Chemical" name="Si" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si)

	/// <Property class="CMIF_Chemical" name="Mn" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mn)

	/// <Property class="CMIF_Chemical" name="S" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CMIF_Chemical" name="P" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P)

	/// <Property class="CMIF_Chemical" name="Ti" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ti)

	/// <Property class="CMIF_Chemical" name="Mode" type="L3SHORT">
	/// 
	/// ����ʶ
	/// (0:������
	///  1:1#����¯
	///  2:2#����¯)
	/// </Property>
	DECLARE_L3PROP_SHORT(Mode)

	/// <Property class="CMIF_Chemical" name="Used_Flag" type="L3SHORT">
	/// 
	/// ʹ�ñ�־
	/// (0:δʹ��
	///  1:��ʹ��)
	/// </Property>
	DECLARE_L3PROP_SHORT(Used_Flag)

	/// <Property class="CMIF_Chemical" name="Shift" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_SHORT(Shift)

	/// <Property class="CMIF_Chemical" name="Team" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_SHORT(Team)

};

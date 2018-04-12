// �߼���CMIF_Weightͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMIF_Weight :
	public CL3Object
{
public:
	CMIF_Weight(void);
	virtual ~CMIF_Weight(void);

	DECLARE_L3CLASS(CMIF_Weight,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Weight)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CMIF_Weight" name="Weight" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CMIF_Weight" name="Weight_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Weight_Time)

	/// <Property class="CMIF_Weight" name="Source" type="L3STRING">
	/// 
	/// ��Դ
	/// (1:1#MIF
	///  2:2#MIF
	///  0:ֱ�ҵذ�)
	/// </Property>
	DECLARE_L3PROP_STRING(Source)

	/// <Property class="CMIF_Weight" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CMIF_Weight" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

};

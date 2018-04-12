// �߼���CCCM_Temp_Curveͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Temp_Curve :
	public CL3Object
{
public:
	CCCM_Temp_Curve(void);
	virtual ~CCCM_Temp_Curve(void);

	DECLARE_L3CLASS(CCCM_Temp_Curve,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Temp_Curve)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Temp_Curve" name="ObjectID" type="L3STRING">
	/// ʵʱ���ݱ�ʶ
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CCCM_Temp_Curve" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Temp_Curve" name="ValueID" type="L3LONG">
	/// 
	/// ʵʱ���ݴ���
	/// (�������¼���
	/// </Property>
	DECLARE_L3PROP_LONG(ValueID)

	/// <Property class="CCCM_Temp_Curve" name="Clock" type="L3DATETIME">
	/// ʵʱ���ݼ�¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Clock)

	/// <Property class="CCCM_Temp_Curve" name="Val" type="L3DOUBLE">
	/// ʵʱ������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Val)

};

// �߼���CCCM_Speed_Curveͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_Speed_Curve :
	public CL3Object
{
public:
	CCCM_Speed_Curve(void);
	virtual ~CCCM_Speed_Curve(void);

	DECLARE_L3CLASS(CCCM_Speed_Curve,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Speed_Curve)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_Speed_Curve" name="ObjectID" type="L3STRING">
	/// ʵʱ���ݱ�ʶ
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CCCM_Speed_Curve" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Speed_Curve" name="ValueID" type="L3LONG">
	/// 
	/// ʵʱ���ݴ���
	/// (1-4 ��������
	/// </Property>
	DECLARE_L3PROP_LONG(ValueID)

	/// <Property class="CCCM_Speed_Curve" name="Clock" type="L3DATETIME">
	/// ʵʱ���ݼ�¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Clock)

	/// <Property class="CCCM_Speed_Curve" name="Val" type="L3DOUBLE">
	/// ʵʱ������ֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Val)

};

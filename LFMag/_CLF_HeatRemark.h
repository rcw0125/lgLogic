// �߼���CLF_HeatRemarkͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_HeatRemark :
	public CL3Object
{
public:
	CLF_HeatRemark(void);
	virtual ~CLF_HeatRemark(void);

	DECLARE_L3CLASS(CLF_HeatRemark,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_HeatRemark)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_HeatRemark" name="TreatNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_HeatRemark" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_HeatRemark" name="Type" type="L3SHORT">
	/// 
	/// ����
	/// (1:��ȫ
	///  2:�豸
	///  3:����
	///  4:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(Type)

	/// <Property class="CLF_HeatRemark" name="Remark" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Remark)

	/// <Property class="CLF_HeatRemark" name="LogTime" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

};

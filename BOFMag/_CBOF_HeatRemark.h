// �߼���CBOF_HeatRemarkͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_HeatRemark :
	public CL3Object
{
public:
	CBOF_HeatRemark(void);
	virtual ~CBOF_HeatRemark(void);

	DECLARE_L3CLASS(CBOF_HeatRemark,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_HeatRemark)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_HeatRemark" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_HeatRemark" name="TypeID" type="L3SHORT">
	/// 
	/// ����
	/// (1:��ȫ
	///  2:�豸
	///  3:����
	///  4:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(TypeID)

	/// <Property class="CBOF_HeatRemark" name="Remark" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Remark)

	/// <Property class="CBOF_HeatRemark" name="Log_Time" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

};

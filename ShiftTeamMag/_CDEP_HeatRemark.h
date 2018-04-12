// �߼���CDEP_HeatRemarkͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDEP_HeatRemark :
	public CL3Object
{
public:
	CDEP_HeatRemark(void);
	virtual ~CDEP_HeatRemark(void);

	DECLARE_L3CLASS(CDEP_HeatRemark,XGMESLogic\\DePMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDEP_HeatRemark)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

		/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(IronLadle)
	/// <Property class="CDEP_HeatRemark" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CDEP_HeatRemark" name="TypeID" type="L3SHORT">
	/// 
	/// ����
	/// (1:��ȫ
	///  2:�豸
	///  3:����
	///  4:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(TypeID)

	/// <Property class="CDEP_HeatRemark" name="Remark" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Remark)

	/// <Property class="CDEP_HeatRemark" name="Log_Time" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

};

// �߼���CBOF_FenderSlagConsumeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_FenderSlagConsume :
	public CL3Object
{
public:
	CBOF_FenderSlagConsume(void);
	virtual ~CBOF_FenderSlagConsume(void);

	DECLARE_L3CLASS(CBOF_FenderSlagConsume,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_FenderSlagConsume)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_FenderSlagConsume" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_FenderSlagConsume" name="FenderSlag" type="L3SHORT">
	/// 
	/// ��������
	/// (1:������
	///  2:����׶
	///  3:������)
	/// </Property>
	DECLARE_L3PROP_SHORT(FenderSlag)

	/// <Property class="CBOF_FenderSlagConsume" name="Consume" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Consume)

};

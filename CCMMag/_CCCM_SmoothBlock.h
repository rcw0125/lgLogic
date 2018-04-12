// �߼���CCCM_SmoothBlockͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CCCM_SmoothBlock :
	public CL3Object
{
public:
	CCCM_SmoothBlock(void);
	virtual ~CCCM_SmoothBlock(void);

	DECLARE_L3CLASS(CCCM_SmoothBlock,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_SmoothBlock)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CCCM_SmoothBlock" name="CCMID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	
	/// <Property class="CCCM_SmoothBlock" name="StrandNo" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(StrandNo)

	/// <Property class="CCCM_SmoothBlock" name="BlockID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(BlockID)

	/// <Property class="CCCM_SmoothBlock" name="Block_Life" type="L3LONG">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_LONG(Block_Life)

	/// <Property class="CCCM_SmoothBlock" name="Factory" type="L3STRING">
	/// ���鳧��
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCCM_SmoothBlock" name="Start_Time" type="L3DATETIME">
	/// ���������ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CCCM_SmoothBlock" name="End_Time" type="L3DATETIME">
	/// �����������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	
	/// <Property class="CCCM_SmoothBlock" name="Block_Size" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Block_Size)

	
	/// <Property class="CCCM_SmoothBlock" name="Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

	/// <Property class="CCCM_SmoothBlock" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

};

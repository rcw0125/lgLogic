// �߼���CLance_Baseͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLance_Base :
	public CL3Object
{
public:
	CLance_Base(void);
	virtual ~CLance_Base(void);

	DECLARE_L3CLASS(CLance_Base,XGMESLogic\\LanceMag, LanceID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Base)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLance_Base" name="LanceID" type="L3STRING">
	/// ��ǹ���
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Base" name="Lance_Head_Type" type="L3STRING">
	/// 
	/// ǹͷ�ͺ�
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Base" name="BOFID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CLance_Base" name="Status" type="L3STRING">
	/// ״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CLance_Base" name="Nozzle_Factury" type="L3STRING">
	/// ��ͷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Nozzle_Factury)

	/// <Property class="CLance_Base" name="Lance_Age" type="L3LONG">
	/// ǹ��
	/// </Property>
	DECLARE_L3PROP_LONG(Lance_Age)

	/// <Property class="CLance_Base" name="MakeID" type="L3STRING">
	/// ��ǹ�������
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Base" name="Make_Start_Time" type="L3DATETIME">
	/// ��ǹ������ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Make_Start_Time)

	/// <Property class="CLance_Base" name="Make_End_Time" type="L3DATETIME">
	/// ��ǹ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Make_End_Time)

};

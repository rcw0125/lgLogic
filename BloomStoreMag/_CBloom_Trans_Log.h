// �߼���CBloom_Trans_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBloom_Trans_Log :
	public CL3Object
{
public:
	CBloom_Trans_Log(void);
	virtual ~CBloom_Trans_Log(void);

	DECLARE_L3CLASS(CBloom_Trans_Log,XGMESLogic\\BloomStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Trans_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBloom_Trans_Log" name="MaterialType" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialType)

	/// <Property class="CBloom_Trans_Log" name="MaterialID" type="L3STRING">
	/// ���Ϻ�
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID)

	/// <Property class="CBloom_Trans_Log" name="Amount" type="L3STRING">
	/// ����֧��
	/// </Property>
	DECLARE_L3PROP_STRING(Amount)

	/// <Property class="CBloom_Trans_Log" name="SourceID" type="L3STRING">
	/// ԭ����
	/// </Property>
	DECLARE_L3PROP_STRING(SourceID)

	/// <Property class="CBloom_Trans_Log" name="Cur_Pile_ID" type="L3STRING">
	/// ԭ��λ
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Pile_ID)

	/// <Property class="CBloom_Trans_Log" name="Cur_Layer_ID" type="L3STRING">
	/// ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Layer_ID)

	/// <Property class="CBloom_Trans_Log" name="TargetID" type="L3STRING">
	/// Ŀ�����
	/// </Property>
	DECLARE_L3PROP_STRING(TargetID)

	/// <Property class="CBloom_Trans_Log" name="Target_Pile_ID" type="L3STRING">
	/// Ŀ���λ
	/// </Property>
	DECLARE_L3PROP_STRING(Target_Pile_ID)

	/// <Property class="CBloom_Trans_Log" name="Target_Layer_ID" type="L3STRING">
	/// Ŀ���
	/// </Property>
	DECLARE_L3PROP_STRING(Target_Layer_ID)

	/// <Property class="CBloom_Trans_Log" name="Operator" type="L3STRING">
	/// ������Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CBloom_Trans_Log" name="Trans_Date" type="L3STRING">
	/// ת������
	/// </Property>
	DECLARE_L3PROP_STRING(Trans_Date)

	/// <Property class="CBloom_Trans_Log" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CBloom_Trans_Log" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

};

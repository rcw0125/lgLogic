// �߼���CBulk_Trans_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBulk_Trans_Log :
	public CL3Object
{
public:
	CBulk_Trans_Log(void);
	virtual ~CBulk_Trans_Log(void);

	DECLARE_L3CLASS(CBulk_Trans_Log,XGMESLogic\\BulkStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Trans_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBulk_Trans_Log" name="SourceID" type="L3STRING">
	/// ԭ�ϲ�
	/// </Property>
	DECLARE_L3PROP_STRING(SourceID)

	/// <Property class="CBulk_Trans_Log" name="TargetID" type="L3STRING">
	/// ���ϲ�
	/// </Property>
	DECLARE_L3PROP_STRING(TargetID)

	/// <Property class="CBulk_Trans_Log" name="MaterialID" type="L3STRING">
	/// ���Ϻ�
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID)

	/// <Property class="CBulk_Trans_Log" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CBulk_Trans_Log" name="Bulk_Code" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_Trans_Log" name="Amount" type="L3DOUBLE">
	/// ת����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	/// <Property class="CBulk_Trans_Log" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CBulk_Trans_Log" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CBulk_Trans_Log" name="Trans_Date" type="L3DATETIME">
	/// ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Trans_Date)

	/// <Property class="CBulk_Trans_Log" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)
};

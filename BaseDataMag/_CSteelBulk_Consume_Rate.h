// �߼���CSteelBulk_Consume_Rateͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CSteelBulk_Consume_Rate :
	public CL3Object
{
public:
	CSteelBulk_Consume_Rate(void);
	virtual ~CSteelBulk_Consume_Rate(void);

	DECLARE_L3CLASS(CSteelBulk_Consume_Rate,XGMESLogic\\BaseDataMag, MatCode)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CSteelBulk_Consume_Rate)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CSteelBulk_Consume_Rate" name="MatCode" type="L3STRING">
	/// ���ϴ��� 2009-09-07
	/// </Property>
	DECLARE_L3PROP_STRING(MatCode)

	/// <Property class="CSteelBulk_Consume_Rate" name="Unit_Consume" type="L3FLOAT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_FLOAT(Unit_Consume)

};

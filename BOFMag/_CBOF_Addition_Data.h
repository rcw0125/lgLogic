// �߼���CBOF_Addition_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_Addition_Data :
	public CL3Object
{
public:
	CBOF_Addition_Data(void);
	virtual ~CBOF_Addition_Data(void);

	DECLARE_L3CLASS(CBOF_Addition_Data,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Addition_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_Addition_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_Addition_Data" name="Element" type="L3STRING">
	/// ���ϴ���
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CBOF_Addition_Data" name="Batch_ID" type="L3STRING">
	/// ���κ�
	/// </Property>20081213 tangyi
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CBOF_Addition_Data" name="Weight" type="L3FLOAT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CBOF_Addition_Data" name="Discharge_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Discharge_Time)

	/// <Property class="CBOF_Addition_Data" name="Type" type="L3SHORT">
	/// 
	/// ��������(1-ɢ״��;
	///                  2-��̼����;
	///                  3:����;
	///                  4:������;
	///                  5:�Ͻ�)
	/// </Property>
	DECLARE_L3PROP_SHORT(Type)

	/// <Property class="CBOF_Addition_Data" name="Area" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(Area)

};

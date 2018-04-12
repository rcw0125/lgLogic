// �߼���CEnergyHistoryDataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEnergyHistoryData :
	public CL3Object
{
public:
	CEnergyHistoryData(void);
	virtual ~CEnergyHistoryData(void);

	DECLARE_L3CLASS(CEnergyHistoryData,XGMESLogic\\EnergyMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergyHistoryData)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CEnergyHistoryData" name="TagName" type="L3STRING">
	/// ��ǩ��
	/// </Property>
	DECLARE_L3PROP_STRING(TagName)

	/// <Property class="CEnergyHistoryData" name="TagType" type="L3LONG">
	/// ��ǩ����:1-ѹ��;2:����;3:����
	/// </Property>
	DECLARE_L3PROP_LONG(TagType)

	/// <Property class="CEnergyHistoryData" name="Consume" type="L3DOUBLE">
	/// ��ǩֵ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TagValue)

	/// <Property class="CEnergyHistoryData" name="Catch_Time" type="L3DATETIME">
	/// �ɼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Catch_Time)

};

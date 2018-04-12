// �߼���CLF_Ladle_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLF_Ladle_Data :
	public CL3Object
{
public:
	CLF_Ladle_Data(void);
	virtual ~CLF_Ladle_Data(void);

	DECLARE_L3CLASS(CLF_Ladle_Data,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Ladle_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLF_Ladle_Data" name="LFID" type="L3SHORT">
	/// LF¯����
	/// </Property>
	DECLARE_L3PROP_SHORT(LFID)

	/// <Property class="CLF_Ladle_Data" name="LadleNo" type="L3STRING">
	/// �ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

	/// <Property class="CLF_Ladle_Data" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Ladle_Data" name="Status" type="L3SHORT">
	/// 
	/// ״̬
	/// (0:δʹ��
	///  1:��ʹ��)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CLF_Ladle_Data" name="Weight" type="L3DOUBLE">
	/// ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

};

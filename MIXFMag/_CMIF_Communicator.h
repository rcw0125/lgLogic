// �߼���CMIF_Communicatorͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMIF_Communicator :
	public CL3Object
{
public:
	CMIF_Communicator(void);
	virtual ~CMIF_Communicator(void);

	DECLARE_L3CLASS(CMIF_Communicator,XGMESLogic\\MIXFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Communicator)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CMIF_Communicator" name="OnMIFTemperature" type="L3BOOL">
	/// ����¯�¶����ݵ����¼���Ӧ����
	/// <Param name="rsTemp" type="L3RECORDSET">�¶�����(¯����,�¶�ֵ,����ʱ��)</Param>
	/// </Method>
	L3BOOL OnMIFTemperature(L3RECORDSET rsTemp);
	/// <Method class="CMIF_Communicator" name="OnWeight" type="L3BOOL">
	/// �����¼����ﴦ����
	/// <Param name="rsWeight" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL OnWeight(L3RECORDSET rsWeight);
};

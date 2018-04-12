// �߼���CNCCommunicatorͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CNCCommunicator :
	public CL3Object
{
public:
	CNCCommunicator(void);
	virtual ~CNCCommunicator(void);

	DECLARE_L3CLASS(CNCCommunicator,XGMESLogic\\BaseDataMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CNCCommunicator)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	
	/// <Method class="CNCCommunicator" name="SendCastIronDataToNC" type="LONG">
	/// ����ˮ��Ϣ���͵�NCϵͳ��
	/// <Param name="rsIron" type="L3RECORDSET">������ˮ��Ϣ�ļ�¼��</Param>
	/// </Method>
	LONG SendCastIronDataToNC(L3RECORDSET rsIron);
};

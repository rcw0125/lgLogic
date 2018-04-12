// �߼���CMIF_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMIF_Mag :
	public CL3Object
{
public:
	CMIF_Mag(void);
	virtual ~CMIF_Mag(void);

	DECLARE_L3CLASS(CMIF_Mag,XGMESLogic\\MIXFMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Mag)
	DECLARE_L3EVENTSINK_MAP()
 
	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

public:
	// �����㷨���ߺ��������ڽ�������ˮ��Ϣ����һ���µ���ˮ��Ϣ
	static BOOL MixIrons(L3RECORDSET rsIrons,L3RECORDSET rsTarget);

	/// <Method class="CMIF_Mag" name="DirectFeedIron" type="L3STRING">
	/// �����ԭ��������ˮ����Ŀ�������������µ���ˮ���ϡ���������ˮ���ϵ�MaterialID��
	/// <Param name="TargetLadle" type="L3STRING">Ŀ��������</Param>
	/// <Param name="rsIron" type="L3RECORDSET">������������ԭ��ˮ��Ϣ</Param>
	/// </Method>
	L3STRING DirectFeedIron(L3STRING TargetLadle, L3RECORDSET rsIron);
	/// <Method class="CMIF_Mag" name="GetUnArrivedIrons" type="L3RECORDSET">
	/// ����ȥ��Ϊ���ֵ�δ�������ˮ��Ϣ
	/// </Method>
	L3RECORDSET GetUnArrivedIrons();
	/// <Method class="CMIF_Mag" name="GetIncomingIrons" type="L3RECORDSET">
	/// ���ص������¯����ǰ����ˮ��Ϣ
	/// </Method>
	L3RECORDSET GetIncomingIrons();
	/// <Method class="CMIF_Mag" name="GetOutgoingIrons" type="L3RECORDSET">
	/// ����ֱ�Һͻ���¯��������ˮ��Ϣ��
	/// </Method>
	L3RECORDSET GetOutgoingIrons();
	L3RECORDSET GetOutgoingIrons2();
	/// <Method class="CMIF_Unit_Mag" name="GetHotIronLadles" type="L3RECORDSET">
	/// ��ȡ��ǰ�ȱ�����
	/// </Method>
	L3RECORDSET GetHotIronLadles();
	/// <Method class="CMIF_Mag" name="BackBFIron" type="L3LONG">
	/// ���˸�¯��ˮ
	/// <Param name="dsIron" type="L3RECORDSET">������ˮ��Ϣ</Param>
	/// </Method>
	L3LONG BackBFIron(L3RECORDSET dsIron);

	/// <Method class="CMIF_Mag" name="OutputIronCancel" type="L3LONG">
	/// ȡ��ֱ����ˮ2009-04-19
	/// </Method>
	L3LONG OutputIronCancel(L3RECORDSET rsLadleID);

	/// <Method class="CMIF_Mag" name="OnDoFeedIron" type="L3BOOL">
	/// ����ֱ����ˮ2009-04-19
	/// </Method>
	L3BOOL OnDoFeedIron(CString strMaterialID);

	/// <Method class="CMIF_Mag" name="SetIsDes" type="L3BOOL">
	/// �˹������Ƿ�����
	/// </Method>
	L3LONG SetIsDes(L3RECORDSET rsIsDes);
};

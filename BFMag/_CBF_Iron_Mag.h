// �߼���CBF_Iron_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialStore.h"

class CBF_Iron_Mag :
	public MaterialStore
{
public:
	CBF_Iron_Mag(void);
	virtual ~CBF_Iron_Mag(void);

	DECLARE_L3CLASS(CBF_Iron_Mag,XGMESLogic\\BFMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBF_Iron_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:

	/// <summary>
	/// ������⻺������URI
	/// </summary>
	virtual CString GetInputCache();
	/// <summary>
	/// ���س��⻺������URI
	/// </summary>
	virtual CString GetOutputCache();
	/// <summary>
	/// ��������¼��������
	/// </summary>
	virtual CString GetInputLogType();
	/// <summary>
	/// ���س����¼��������
	/// </summary>
	virtual CString GetOutputLogType();
	/// <summary>
	/// ���ؿ�λ��������
	/// </summary>
	virtual CString GetStoreAreaType();

	/// <summary>
	///	��ʼ���ⷿ������
	/// </summary>
	virtual BOOL InitializeStoreProperties();
	/// <summary>
	/// ����λ�ĳ�ʼ������
	/// </summary>
	virtual BOOL GetInitialAreaData(CL3RecordSetWrap& rs);
	/// <summary>
	/// �ڿⷿ��ʼ��ɺ���á��̳������ش˺������ж���ĳ�ʼ��������
	/// </summary>
	virtual void OnAfterStoreInitialized();

	/// <summary>
	/// ���ǰԤ������������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
	/// ARG >> rsInputInfo : �����Ϣ��¼��
	/// RET << TRUE ������⣻FALSE �ж����
	/// </summary>
	virtual BOOL OnBeforeInputMaterials(L3RECORDSET rsInputInfo);
	/// <summary>
	/// �������������������ɹ�����á��̳�������ش˷������ж���Ĵ���
	/// ARG >> rsInputInfo : �����Ϣ��¼��
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterMaterialsInputted(L3RECORDSET rsInputInfo);
	/// <summary>
	/// ����ǰԤ�����ڳ������ǰ���á��̳�������ش˷�������Ԥ�ȵ�����׼���ʹ���
	/// ARG >> rsOutputInfo : ������Ϣ��¼��
	/// RET << TRUE �������⣻FALSE �жϳ���
	/// </summary>
	virtual BOOL OnBeforeOutputMaterials(L3RECORDSET rsOutputInfo);
	/// <summary>
	/// ������������ڳ�������ɹ�����á��̳�������ش˷������ж���Ĵ���
	/// ARG >> rsOutputInfo : ������Ϣ��¼��
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterMaterialsOutputted(L3RECORDSET rsOutputInfo);
	/// <summary>
	/// �˹����ӿ��ǰԤ�����ڽ����˹����ӿ��ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
	/// ARG	>> rsMaterialInfo : ����������Ϣ��¼��
	/// RET << ����TRUE������������FALSE�жϡ�
	/// </summary>
	virtual BOOL OnBeforeAddMaterials(L3RECORDSET rsMaterialInfo);
	/// <summary>
	/// �˹����ӿ����������ڽ����˹����ӿ�����á��̳�������ش˷������ж��⴦��
	/// ARG >> rsMaterialInfo : �����Ĳ�����Ϣ��¼��
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterMaterialsAdded(L3RECORDSET rsMaterialInfo);
	/// <summary>
	/// �˹�ɾ�����ǰԤ�����ڽ����˹�ɾ�����ǰ���á��̳�������ش˷�������Ԥ������׼���ʹ���
	/// ARG	>> rsMaterialInfo : ɾ��������Ϣ��¼��
	/// RET << ����TRUE������������FALSE�жϡ�
	/// </summary>
	virtual BOOL OnBeforeDeleteMaterials(L3RECORDSET rsMaterialInfo);
	/// <summary>
	/// �˹�ɾ�������������ڽ����˹�ɾ��������á��̳�������ش˷������ж��⴦��
	/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
	/// RET << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterMaterialsDeleted(L3RECORDSET rsMaterialInfo);

	//tangyi 2007-12-09
	/// <summary>
	/// �ƿ�ǰ������
	/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
	/// RET << ����TRUE������������FALSE�жϡ�
	/// </summary>
	virtual BOOL OnBeforeMoveMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// �ƿ��������
	/// ARG >> rsMaterialInfo : ɾ���Ĳ�����Ϣ��¼��
	/// RET << << �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </summary>
	virtual BOOL OnAfterMoveMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// ����¼Ԥ�����̳�������ش˷��������ǰ����������¼
	/// </summary>
	virtual void PrepareInputLog(L3RECORDSET rsInputLog);
	/// <summary>
	/// �����¼Ԥ�����̳�������ش˷����ڳ���ǰ����������¼
	/// </summary>
	virtual void PrepareOutputLog(L3RECORDSET rsOutputLog);

	/// <summary>
	/// ����ָ����ŵĿ�λ�����URI
	/// </summary>
	virtual CString GetAreaURI(LPCTSTR lpcszAreaID);

	/// <Method class="CBF_Iron_Mag" name="NewIronData" type="L3LONG">
	/// 
	/// ������ˮ����
	/// ARG&gt;&gt; rsIron : ��ˮ���ݡ��������BFID,TAP_No,TPC_No,Source�ֶΡ�
	/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ��س�����롣
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewIronData(L3RECORDSET rsIron);
	/// <Method class="CBF_Iron_Mag" name="ModifyIronData" type="L3LONG">
	/// �޸���ˮ����
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyIronData(L3RECORDSET rsIron);
	/// <Method class="CBF_Iron_Mag" name="DeleteIronData" type="L3LONG">
	/// ɾ����ˮ����
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteIronData(L3RECORDSET rsIron);
	/// <Method class="CBF_Iron_Mag" name="DesignatePath" type="L3LONG">
	/// ��ˮȥ��ָ��
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DesignatePath(L3RECORDSET rsIron);
	/// <Method class="CBF_Iron_Mag" name="SendIronDataToNC" type="L3LONG">
	/// ��ˮ�ϴ�NC
	/// <Param name="strTapNo" type="L3STRING"></Param>
	/// </Method>
    L3LONG SendIronDataToNC(L3STRING strTapNo);
	
	/// <Method class="CBF_Iron_Mag" name="GetUnprocessedIrons" type="L3RECORDSET">
	/// ����δ�������ˮ����
	/// </Method>
	L3RECORDSET GetUnprocessedIrons();
	/// <Method class="CBF_Iron_Mag" name="GetIronsForDefineDest" type="L3RECORDSET">
	/// ����δ�������ˮ
	/// </Method>
	L3RECORDSET GetIronsForDefineDest();
	/// <Method class="CBF_Iron_Mag" name="SendIronInfoToNC" type="L3LONG">
	/// ������ˮ��¼��NC
	/// <Param name="rsIrons" type="L3RECORDSET">Ҫ���͵���ˮ����</Param>
	/// </Method>
	//L3LONG SendIronInfoToNC(L3RECORDSET rsIrons);

	/// <Method class="CBF_Iron_Mag" name="QueryIronInfo" type="L3RECORDSET">
	/// ����ʱ��κ�ȥ�����ˮ��Ϣ
	/// <Param name="timeFrom" type="L3DATETIME">��ʼʱ��</Param>
	/// <Param name="timeTo" type="L3DATETIME">����ʱ��</Param>
	/// <Param name="Destination" type="L3LONG">ȥ��</Param>
	/// </Method>
	L3RECORDSET QueryIronInfo(L3DATETIME timeFrom, L3DATETIME timeTo, L3LONG Destination);
	/// <Method class="CBF_Iron_Mag" name="GetMaxTAPNoByBFID" type="L3RECORDSET">
	/// ����¯�����ȡ������κš����ؼ�¼�������ֶ�BFID��TAP_No��
	/// </Method>
	L3RECORDSET GetMaxTAPNoByBFID();
	/// <Method class="CBF_Iron_Mag" name="GetLastTareWeightByTPCNo" type="L3DOUBLE">
	/// ���ݹ޺Ų�ѯ���һ�ε�Ƥ�ء�
	/// <Param name="nTPCNo" type="L3STRING">�޺�</Param>
	/// </Method>
	L3DOUBLE GetLastTareWeightByTPCNo(L3STRING nTPCNo);
	/// <Method class="CBF_Iron_Mag" name="GetUnArrivedIrons" type="L3RECORDSET">
	/// ������ָ��ȥ�򣬵�δ����ȷ�ϵ���ˮ���ݡ�
	/// <Param name="Destination" type="L3LONG">ȥ��</Param>
	/// </Method>
	L3RECORDSET GetUnArrivedIrons(L3LONG Destination);
	/// <Method class="CBF_Iron_Mag" name="ConfirmIronArrive" type="L3BOOL">
	/// ȷ����ˮ�������ȥ����в�ͬ�Ĵ���
	/// <Param name="rsIron" type="L3RECORDSET">ȷ���Ѿ��������ˮ��¼</Param>
	/// </Method>
	L3BOOL ConfirmIronArrive(L3RECORDSET rsIron);

	/// <Method class="CBF_Iron_Mag" name="SetIrongTare" type="L3LONG">
	/// �������ι޺�Ƥ��
	/// <Param name="strTapNo" type="L3STRING"></Param>
	/// <Param name="strTpcNo" type="L3STRING"></Param>
	/// <Param name="fTare" type="L3FLOAT"></Param>
	/// </Method>
	L3LONG SetIronTare(L3STRING strTapNo,L3STRING strTpcNo,L3FLOAT fTare);

	/// <Method class="CBF_Iron_Mag" name="GetBFChemicalData" type="L3RECORDSET">
	/// ͨ�����ι޺Ż�ȡ��ˮ�ɷ����ݡ�
	/// <Param name="strTapNo" type="L3STRING">���κ�</Param>
	/// <Param name="strTpcNo" type="L3STRING">�޺�</Param>
	/// </Method>
	L3RECORDSET GetBFChemicalData(L3STRING strTapNo,L3STRING strTpcNo);


	/// <Property class="CBF_Iron_Mag" name="EventIronChanged" type="L3LONG">
	/// ��ˮ���ݱ���¼�
	/// </Property>
	DECLARE_L3PROP_LONG(EventIronChanged)

	/// <Method class="CBF_Iron_Mag" name="NewIronInfo" type="L3LONG">
	/// ������ˮ��Ϣ
	/// ARG&gt;&gt; rsIron : ��ˮ��Ϣ���������TAP_No,TPC_No�ֶΡ�
	/// RET &lt;&lt; �ɹ�����1��ʧ�ܷ��س�����롣
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewIronInfo(L3RECORDSET rsData);

	//L3LONG RetoLab(L3RECORDSET rsData);

	/// <Method class="CBF_Iron_Mag" name="AcceptWeightData" type="L3BOOL">
	/// ������ˮ���������� 2009-03-30
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptWeightData(L3RECORDSET rsData);

/// <Method class="CBF_Iron_Mag" name="Complete" type="L3BOOL">
	/// ��ˮ�깤 2009-03-30
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL Complete(L3STRING strID);

	/// <Method class="CBF_Iron_Mag" name="SendIronDataToWeight" type="L3BOOL">
	/// ������̼¯�����´�PLC 2009-03-21
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL  SendIronDataToWeight(LPCTSTR strTapNo,LPCTSTR strTpcNo);

	/// <Method class="CBF_Iron_Mag" name="SendBackIrons" type="L3LONG">
	/// δ������ˮ����
	/// <Param name="rsIrons" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SendBackIrons(L3RECORDSET rsIrons);

	/// <Method class="CBF_Iron_Mag" name="SendBackArrivedIrons" type="L3LONG">
	/// �ѵ�����ˮ����
	/// <Param name="rsIrons" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SendBackArrivedIrons(L3RECORDSET rsIrons);

	/// <Method class="CBF_Iron_Mag" name="SendIronToCast" type="L3BOOL">
	/// ������ˮȥ����
	/// <Param name="rsIron" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL SendIronToCast(L3RECORDSET rsIron);

	/// <Method class="CBF_Iron_Mag" name="MarkIronSource" type="L3LONG">
	/// ��ʶ��ˮ��Դ
	/// <Param name="rsIrons" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MarkIronSource(L3RECORDSET rsIrons);

	/// <Method class="CBF_Iron_Mag" name="GetUnprocessSampIrons" type="L3RECORDSET">
	/// add by hyh 2012-04-12
	/// ����ǰ̨���ֳɷֱ�����ʾ��ˮ�ɷ�
	/// </Method>
	L3RECORDSET GetUnprocessSampIrons();
};

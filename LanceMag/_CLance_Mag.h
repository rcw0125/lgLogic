// �߼���CLance_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLance_Mag :
	public CL3Object
{
public:
	CLance_Mag(void);
	virtual ~CLance_Mag(void);

	DECLARE_L3CLASS(CLance_Mag,XGMESLogic\\LanceMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();


	L3BOOL UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3BOOL DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);

	/// <Method class="CLance_Mag" name="SetLanceStatus" type="L3BOOL">
	/// 
	/// ������ǹ��״̬
	/// ARG &gt;&gt; rsLances: Ҫ����״̬����ǹ�ļ�¼��
	///     &gt;&gt; strStatus: ���ó�Ϊ��״̬��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLances" type="L3RECORDSET"></Param>
	/// <Param name="strStatus" type="L3STRING"></Param>
	/// </Method>
	L3BOOL SetLanceStatus(L3RECORDSET rsLances, L3STRING strStatus);

	/// <Method class="CLance_Mag" name="LanceDefendStrat" type="L3BOOL">
	/// 
	/// ��ǹ������ʼ
	/// ARG &gt;&gt; rsLances: Ҫ��ʼά�޵���ǹ�ļ�¼�����������LanceID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLance" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceDefendStrat(L3RECORDSET rsLance);
	/// <Method class="CLance_Mag" name="LanceDefendEnd" type="L3BOOL">
	/// 
	/// ��ǹ��������
	/// ARG &gt;&gt; rsLances: Ҫ����ά�޵���ǹ�ļ�¼�����������LanceID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLance" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceDefendEnd(L3RECORDSET rsLance);
	/// <Method class="CLance_Mag" name="LanceChangeOn" type="L3BOOL">
	/// 
	/// �˹�������ǹ
	/// ARG &gt;&gt; rsLances: Ҫ���ϵ���ǹ�ļ�¼�����������LanceID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLance" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceChangeOn(L3RECORDSET rsLance);
	/// <Method class="CLance_Mag" name="LanceOffLineCheck" type="L3BOOL">
	/// ��ǹ���߼��
	/// <Param name="rsLances" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceOffLineCheck(L3RECORDSET rsLances);
	/// <Method class="CLance_Mag" name="LanceFree" type="L3BOOL">
	/// ��ǹ���߼�����
	/// ��Ϊ���ٴ�����ʹ��
	/// <Param name="rsLances" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceFree(L3RECORDSET rsLances);
	/// <Method class="CLance_Mag" name="LanceChangeOff" type="L3BOOL">
	/// ��ǹ���ߴ���
	/// ARG &gt;&gt; rsLances: Ҫ���µ���ǹ�ļ�¼�����������LanceID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLance" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL LanceChangeOff(L3RECORDSET rsLance);
	/// <Method class="CLance_Mag" name="InsertLanceDefendInfo" type="L3BOOL">
	/// 
	/// �����ǹά����Ϣ
	/// ARG &gt;&gt; rsLanceDefends: Ҫ��ӵ���ǹ��ά���ļ�¼�����������LanceID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLanceDefend" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceDefendInfo(L3RECORDSET rsLanceDefend);
	/// <Method class="CLance_Mag" name="UpdateLanceDefendInfo" type="L3BOOL">
	/// 
	/// �޸���ǹά��ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL  UpdateLanceDefendInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceDefendInfo" type="L3BOOL">
	/// 
	/// ɾ����ǹά��ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL DeleteLanceDefendInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceDefendInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ��ǹά����Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceDefendInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceUseInfo" type="L3BOOL">
	/// 
	/// �����ǹʹ����Ϣ
	/// ARG &gt;&gt; rsLanceUse: Ҫ��ӵ���ǹ��ʹ�õļ�¼�����������LanceID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLanceUse" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceUseInfo(L3RECORDSET rsLanceUse);
	/// <Method class="CLance_Mag" name="UpdateLanceUseInfo" type="L3BOOL">
	/// 
	/// �޸���ǹʹ��ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL UpdateLanceUseInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceUseInfo" type="L3BOOL">
	/// 
	/// ɾ����ǹʹ��ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL DeleteLanceUseInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceUseInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ��ǹʹ����Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceUseInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceCheckInfo" type="L3BOOL">
	/// 
	/// �����ǹ�����Ϣ
	/// ARG &gt;&gt; rsLanceCheck: Ҫ��ӵ���ǹ�ļ��ļ�¼�����������LanceID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLanceCheck" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceCheckInfo(L3RECORDSET rsLanceCheck);
	/// <Method class="CLance_Mag" name="UpdateLanceCheckInfo" type="L3BOOL">
	/// 
	/// �޸���ǹ���ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL UpdateLanceCheckInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceCheckInfo" type="L3BOOL">
	/// 
	/// ɾ����ǹ���ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL  DeleteLanceCheckInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceCheckInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ��ǹ�����Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceCheckInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceHeadInInfo" type="L3BOOL">
	/// 
	/// �����ǹǹͷ�����Ϣ
	/// ARG &gt;&gt; rsInfos: Ҫ��ӵ���ǹ��ǹͷ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceHeadInInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="UpdateLanceHeadInInfo" type="L3BOOL">
	/// 
	/// �޸�ǹͷ���ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL UpdateLanceHeadInInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceHeadInInfo" type="L3BOOL">
	/// 
	/// ɾ��ǹͷ���ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL DeleteLanceHeadInInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceLanceHeadInInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ��ǹǹͷ�����Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceLanceHeadInInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceHeadOutInfo" type="L3BOOL">
	/// 
	/// �����ǹǹͷ������Ϣ
	/// ARG &gt;&gt; rsLanceHeadOut: Ҫ��ӵ���ǹ��ǹͷ����ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL InsertLanceHeadOutInfo(L3RECORDSET rsInfos);

	/// <Method class="CLance_Mag" name="UpdateLanceHeadOutInfo" type="L3BOOL">
	/// 
	/// �޸�ǹͷ����ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL UpdateLanceHeadOutInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceHeadOutInfo" type="L3BOOL">
	/// 
	/// ɾ��ǹͷ����ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3BOOL DeleteLanceHeadOutInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceLanceHeadOutInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ��ǹǹͷ������Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ����ؼ�¼����ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceLanceHeadOutInfo(L3STRING strCondition);
	/// <Method class="CLance_Mag" name="InsertLanceMakeInfo" type="L3BOOL">
	/// ������ǹ������Ϣ
	/// <Param name="rsInfos" type="L3RECORDSET">��ǹ������Ϣ</Param>
	/// </Method>
	L3BOOL InsertLanceMakeInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="UpdateLanceMakeInfo" type="L3BOOL">
	/// �޸���ǹ������Ϣ
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateLanceMakeInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="DeleteLanceMakeInfo" type="L3BOOL">
	/// ɾ����ǹ������Ϣ
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteLanceMakeInfo(L3RECORDSET rsInfos);
	/// <Method class="CLance_Mag" name="GetLanceMakeInfo" type="L3RECORDSET">
	/// ��ȡ��ǹ������Ϣ
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLanceMakeInfo(L3STRING strCondition);

};

// �߼���CTundish_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CTundish_Mag :
	public CL3Object
{
public:
	CTundish_Mag(void);
	virtual ~CTundish_Mag(void);

	DECLARE_L3CLASS(CTundish_Mag,XGMESLogic\\TundishMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CTundish_Mag" name="InsertInfos" type="L3LONG">
	/// 
	/// ���ʵ����Ϣ
	/// ARG &gt;&gt;strClassName:����
	///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// <Param name="strClassName" type="L3STRING">����</Param>
	/// </Method>
	L3LONG InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	/// <Method class="CTundish_Mag" name="UpdateInfos" type="L3LONG">
	/// 
	/// �޸�ʵ����Ϣ
	/// ARG &gt;&gt;lpcsClass:����
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// <Param name="lpcsClass" type="LPCTSTR">����</Param>
	/// </Method>
	L3LONG UpdateInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass); 
	/// <Method class="CTundish_Mag" name="DeleteInfos" type="L3LONG">
	/// 
	/// ɾ��ʵ����Ϣ
	/// ARG &gt;&gt;lpcsClass:����
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// <Param name="lpcsClass" type="LPCTSTR">����</Param>
	/// </Method>
	L3LONG DeleteInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass);
	/// <Method class="CTundish_Mag" name="GetInfos" type="L3RECORDSET">
	/// 
	/// ��ȡʵ����Ϣ
	/// ARG &gt;&gt;lpcsClass:����
	///     &gt;&gt;lpcsCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
	/// <Param name="lpcsClass" type="LPCTSTR">��ѯ����</Param>
	/// <Param name="lpcsCondition" type="LPCTSTR">����</Param>
	/// </Method>
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);
	/// <Method class="CTundish_Mag" name="TundishInnerBuildStart" type="L3LONG">
	/// 
	/// �а����ò��Ὺʼ
	/// ARG &gt;&gt; rsTundishs: Ҫ��Ὺʼ���а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInnerBuildStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishInnerBuildEnd" type="L3LONG">
	/// 
	/// �а����ò������
	/// ARG &gt;&gt; rsTundishs: Ҫ���������а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInnerBuildEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishInnerFireStart" type="L3LONG">
	/// 
	/// �а����ò�濾��ʼ
	/// ARG &gt;&gt; rsTundishs: Ҫ�濾��ʼ���а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInnerFireStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishInnerFireEnd" type="L3LONG">
	/// 
	/// �а����ò�濾����
	/// ARG &gt;&gt; rsTundishs: Ҫ�濾�������а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInnerFireEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishWorkBuildStart" type="L3LONG">
	/// 
	/// �а�������ͿĨ/����ʼ
	/// ARG &gt;&gt; rsTundishs: ҪͿĨ/����ʼ���а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishWorkBuildStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishWorkBuildEnd" type="L3LONG">
	/// 
	/// �а�������ͿĨ/�������
	/// ARG &gt;&gt; rsTundishs: Ҫ�а�������ͿĨ/������а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishWorkBuildEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishWorkFireStart" type="L3LONG">
	/// 
	/// �а�������濾��ʼ
	/// ARG &gt;&gt; rsTundishs: Ҫ������濾��ʼ���а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishWorkFireStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishWorkFireEnd" type="L3LONG">
	/// 
	/// �а�������濾����
	/// ARG &gt;&gt; rsTundishs: Ҫ������濾�������а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishWorkFireEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishConfirmCold" type="L3LONG">
	/// ȷ���а��䱸
	/// <Param name="dsTundish" type="L3RECORDSET">�а���¼��</Param>
	/// </Method>
	L3LONG TundishConfirmCold(L3RECORDSET dsTundish);
	/// <Method class="CTundish_Mag" name="TundishInstallStart" type="L3LONG">
	/// �а���ʼ�ϼ�
	/// <Param name="dsTundish" type="L3RECORDSET">�а���¼��</Param>
	/// </Method>
	L3LONG TundishInstallStart(L3RECORDSET dsTundish);
	/// <Method class="CTundish_Mag" name="TundishInstallEnd" type="L3LONG">
	/// �а��ϼ�����
	/// <Param name="dsTundish" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishInstallEnd(L3RECORDSET dsTundish);
	/// <Method class="CTundish_Mag" name="TundishOnFireStart" type="L3LONG">
	/// 
	/// �а����ߺ濾��ʼ
	/// ARG &gt;&gt; rsTundishs: Ҫ���ߺ濾��ʼ���а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishOnFireStart(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="TundishOnFireEnd" type="L3LONG">
	/// 
	/// �а����ߺ濾����
	/// ARG &gt;&gt; rsTundishs: Ҫ���ߺ濾�������а��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishOnFireEnd(L3RECORDSET rsTundishs);
	/// <Method class="CTundish_Mag" name="InsertTundishInnerBuildInfo" type="L3LONG">
	/// 
	/// ����а����ò�������Ϣ
	/// ARG &gt;&gt; rsTundishInnerBuilds: Ҫ��ӵ��а����ò���ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInnerBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishInnerBuildInfo(L3RECORDSET rsTundishInnerBuilds);
	/// <Method class="CTundish_Mag" name="UpdateTundishInnerBuildInfo" type="L3LONG">
	/// 
	/// �޸��а����ò�������Ϣ
	/// ARG &gt;&gt; rsTundishInnerBuilds: Ҫ�޸ĵ��а����ò���ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInnerBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishInnerBuildInfo(L3RECORDSET rsTundishInnerBuilds);
	/// <Method class="CTundish_Mag" name="DeleteTundishInnerBuildInfo" type="L3LONG">
	/// 
	/// ɾ���а����ò�������Ϣ
	/// ARG &gt;&gt; rsTundishInnerBuilds: Ҫɾ�����а����ò���ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInnerBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishInnerBuildInfo(L3RECORDSET rsTundishInnerBuilds);
	/// <Method class="CTundish_Mag" name="GetTundishInnerBuildInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ�а����ò�������Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reTundishInnerBuildInfos��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishInnerBuildInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishInnerFireInfo" type="L3LONG">
	/// 
	/// ����а����ò�濾��Ϣ
	/// ARG &gt;&gt; rsTundishInnerFires: Ҫ��ӵ��а����ò�濾�ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInnerFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishInnerFireInfo(L3RECORDSET rsTundishInnerFires);
	/// <Method class="CTundish_Mag" name="UpdateTundishInnerFireInfo" type="L3LONG">
	/// 
	/// �޸��а����ò�濾��Ϣ
	/// ARG &gt;&gt; rsTundishInnerFires: Ҫ�޸ĵ��а����ò�濾�ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInnerFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishInnerFireInfo(L3RECORDSET rsTundishInnerFires);
	/// <Method class="CTundish_Mag" name="DeleteTundishInnerFireInfo" type="L3LONG">
	/// 
	/// ɾ���а����ò�濾��Ϣ
	/// ARG &gt;&gt; rsTundishInnerFires: Ҫɾ�����а����ò�濾�ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInnerFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishInnerFireInfo(L3RECORDSET rsTundishInnerFires);
	/// <Method class="CTundish_Mag" name="GetTundishInnerFireInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ�а����ò�濾��Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reTundishInnerFireInfos��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishInnerFireInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishWorkBuildInfo" type="L3LONG">
	/// 
	/// ����а�������������Ϣ
	/// ARG &gt;&gt; rsTundishWorkBuilds: Ҫ��ӵ��а���������ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishWorkBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishWorkBuildInfo(L3RECORDSET rsTundishWorkBuilds);
	/// <Method class="CTundish_Mag" name="UpdateTundishWorkBuildInfo" type="L3LONG">
	/// 
	/// �޸��а�������������Ϣ
	/// ARG &gt;&gt; rsTundishWorkBuilds: Ҫ�޸ĵ��а���������ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishWorkBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishWorkBuildInfo(L3RECORDSET rsTundishWorkBuilds);
	/// <Method class="CTundish_Mag" name="DeleteTundishWorkBuildInfo" type="L3LONG">
	/// 
	/// ɾ���а�������������Ϣ
	/// ARG &gt;&gt; rsTundishWorkBuilds: Ҫɾ�����а���������ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishWorkBuilds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishWorkBuildInfo(L3RECORDSET rsTundishWorkBuilds);
	/// <Method class="CTundish_Mag" name="GetTundishWorkBuildInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ�а�������������Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsTundishWorkBuilds��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishWorkBuildInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishOTHotFireInfo" type="L3LONG">
	/// 
	/// ���1��2#�����а��������ȱ��濾��Ϣ
	/// ARG &gt;&gt; rsTundishHotFires: Ҫ��ӵ��а��濾�ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishOTHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="UpdateTundishOTHotFireInfo" type="L3LONG">
	/// 
	/// �޸�1��2#�����а��������ȱ��濾��Ϣ
	/// ARG &gt;&gt; rsTundishHotFires: Ҫ�޸ĵ��а��濾�ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishOTHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="DeleteTundishOTHotFireInfo" type="L3LONG">
	/// 
	/// ɾ��1��2#�����а��������ȱ��濾��Ϣ
	/// ARG &gt;&gt; rsTundishHotFires: Ҫɾ�����а��濾�ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishOTHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="GetTundishOTHotFireInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ1��2#�����а��������ȱ��濾��Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsTundishOTHotFires��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishOTHotFireInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishTFFHotFireInfo" type="L3LONG">
	/// 
	/// ���3��4��5#�����а��ȱ��濾��Ϣ
	/// ARG &gt;&gt; rsTundishHotFires: Ҫ��ӵ��а��濾�ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishTFFHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="UpdateTundishTFFHotFireInfo" type="L3LONG">
	/// 
	/// �޸�3��4��5#�����а��ȱ��濾��Ϣ
	/// ARG &gt;&gt; rsTundishHotFires: Ҫ�޸ĵ��а��濾�ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishTFFHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="DeleteTundishTFFHotFireInfo" type="L3LONG">
	/// 
	/// ɾ��3��4��5#�����а��ȱ��濾��Ϣ
	/// ARG &gt;&gt; rsTundishHotFires: Ҫɾ�����а��濾�ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishHotFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishTFFHotFireInfo(L3RECORDSET rsTundishHotFires);
	/// <Method class="CTundish_Mag" name="GetTundishTFFHotFireInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ3��4��5#�����а��濾��Ϣ
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsTundishTFFHotFires��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishTFFHotFireInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishOTInstallInfo" type="L3LONG">
	/// 
	/// ���1��2#�����а��ϼ�ʵ��
	/// ARG &gt;&gt; rsTundishInstalls: Ҫ��ӵ��а��ϼ��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishOTInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="UpdateTundishOTInstallInfo" type="L3LONG">
	/// 
	/// �޸�1��2#�����а��ϼ�ʵ��
	/// ARG &gt;&gt; rsTundishInstalls: Ҫ�޸ĵ��а��ϼ��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishOTInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="DeleteTundishOTInstallInfo" type="L3LONG">
	/// 
	/// ɾ��1��2#�����а��ϼ�ʵ��
	/// ARG &gt;&gt; rsTundishInstalls: Ҫɾ�����а��ϼ��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishOTInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="GetTundishOTInstallInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ1��2#�����а��ϼ�ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsTundishOTInstalls��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishOTInstallInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishTFFInstallInfo" type="L3LONG">
	/// 
	/// ���3��4��5#�����а��ϼ�ʵ��
	/// ARG &gt;&gt; rsTundishInstalls: Ҫ��ӵ��а��ϼ��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishTFFInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="UpdateTundishTFFInstallInfo" type="L3LONG">
	/// 
	/// �޸�3��4��5#�����а��ϼ�ʵ��
	/// ARG &gt;&gt; rsTundishInstalls: Ҫ�޸ĵ��а��ϼ��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishTFFInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="DeleteTundishTFFInstallInfo" type="L3LONG">
	/// 
	/// ɾ��3��4��5#�����а��ϼ�ʵ��
	/// ARG &gt;&gt; rsTundishInstalls: Ҫɾ�����а��ϼ��ļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishTFFInstallInfo(L3RECORDSET rsTundishInstalls);
	/// <Method class="CTundish_Mag" name="GetTundishTFFInstallInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ3��4��5#�����а��ϼ�ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsTundishOTInstalls��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishTFFInstallInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishOTRefraUseInfo" type="L3LONG">
	/// 
	/// ���1��2#�����а��Ͳ�ʹ��ʵ��
	/// ARG &gt;&gt; rsTundishRefraUses: Ҫ��ӵ��а��Ͳ�ʹ�õļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishOTRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="UpdateTundishOTRefraUseInfo" type="L3LONG">
	/// 
	/// �޸�1��2#�����а��Ͳ�ʹ��ʵ��
	/// ARG &gt;&gt; rsTundishRefraUses: Ҫ�޸ĵ��а��Ͳ�ʹ�õļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishOTRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="DeleteTundishOTRefraUseInfo" type="L3LONG">
	/// 
	/// ɾ��1��2#�����а��Ͳ�ʹ��ʵ��
	/// ARG &gt;&gt; rsTundishRefraUses: Ҫɾ�����а��Ͳ�ʹ�õļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishOTRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="GetTundishOTRefraUseInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ1��2#�����а��Ͳ�ʹ��ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsTundishRefraUses��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishOTRefraUseInfo(L3STRING strCondition);
	/// <Method class="CTundish_Mag" name="InsertTundishTTFRefraUseInfo" type="L3LONG">
	/// 
	/// ���3��4��5#�����а��Ͳ�ʹ��ʵ��
	/// ARG &gt;&gt; rsTundishRefraUses: Ҫ��ӵ��а��Ͳ�ʹ�õļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertTundishTTFRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="UpdateTundishTTFRefraUseInfo" type="L3LONG">
	/// 
	/// �޸�3��4��5#�����а��Ͳ�ʹ��ʵ��
	/// ARG &gt;&gt; rsTundishRefraUses: Ҫ�޸ĵ��а��Ͳ�ʹ�õļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateTundishTTFRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="DeleteTundishTTFRefraUseInfo" type="L3LONG">
	/// 
	/// ɾ��3��4��5#�����а��Ͳ�ʹ��ʵ��
	/// ARG &gt;&gt; rsTundishRefraUses: Ҫɾ�����а��Ͳ�ʹ�õļ�¼�����������TundishID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTundishRefraUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteTundishTTFRefraUseInfo(L3RECORDSET rsTundishRefraUses);
	/// <Method class="CTundish_Mag" name="GetTundishTTFRefraUseInfo" type="L3RECORDSET">
	/// 
	/// ��ȡ3��4��5#�����а��Ͳ�ʹ��ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsTundishRefraUses��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetTundishTTFRefraUseInfo(L3STRING strCondition);
	/// <Property class="CTundish_Mag" name="Tundish_SeqNo" type="L3STRING">
	/// �а����
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_SeqNo)

	/// <Method class="CTundish_Mag" name="GetAllHotTundish" type="L3RECORDSET">
	/// ��ȡ�а�״̬Ϊ�ȱ��а�(�����а�)
	/// </Method>
	L3RECORDSET GetAllHotTundish();
	/// <Method class="CTundish_Mag" name="SetTundishNO" type="L3LONG">
	/// �����а����κ�
	/// <Param name="TundishID" type="L3STRING">�а���</Param>
	/// <Param name="TundishNO" type="L3STRING">���κ�</Param>
	/// </Method>
	L3LONG SetTundishNO(L3STRING TundishID, L3STRING TundishNO);
	/// <Method class="CTundish_Mag" name="TundishOnLine" type="L3LONG">
	/// �а�����
	/// <Param name="TundishID" type="L3STRING">�а���</Param>
	/// <Param name="TundishNO" type="L3STRING">���κ�</Param>
	/// <Param name="dtOnLine" type="L3DATETIME">�а�����ʱ��</Param>
	/// </Method>
	L3LONG TundishOnLine(L3STRING TundishID, L3STRING TundishNO,L3DATETIME dtOnLine);
	
	/// <Method class="CTundish_Mag" name="TundishOffLine" type="L3LONG">
	/// �а�����
	/// <Param name="TundishID" type="L3STRING">�а���</Param>
	/// <Param name="TundishNO" type="L3STRING">���κ�</Param>
	/// <Param name="dtOffLine" type="L3DATETIME">�а�����ʱ��</Param>
	/// </Method>
	L3LONG TundishOffLine(L3STRING TundishID, L3STRING TundishNO,L3DATETIME dtOffLine);
	/// <Method class="CTundish_Mag" name="GetEnableInnerIDorWorkID" type="L3RECORDSET">
	/// �����а��źͻ�ȡ���ͻ�ȡ���а�������û��ʵ�������ò��Ż���������
	/// <Param name="strTundishID" type="L3STRING">�а���</Param>
	/// <Param name="strType" type="L3STRING">��ȡ����</Param>
	/// </Method>
	L3RECORDSET GetEnableInnerIDorWorkID(L3STRING strTundishID, L3STRING strType);
	/// <Method class="CTundish_Mag" name="TundishDirectCold" type="L3LONG">
	/// �а�ֱ���䱸
	/// <Param name="dsTundishs" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG TundishDirectCold(L3RECORDSET dsTundishs);
	/// <Method class="CTundish_Mag" name="TundishDireCCMID" type="L3LONG">
	/// ��״̬Ϊ�ȱ��濾���ȱ����а�ָ��ȥ��
	/// <Param name="strTundishID" type="L3STRING">�а���</Param>
	/// <Param name="strCCMID" type="L3STRING"></Param>
	/// </Method>
	L3LONG TundishDireCCMID(L3STRING strTundishID, L3STRING strCCMID);
	/// <Method class="CTundish_Mag" name="TundishOffLineException" type="L3LONG">
	/// �а��쳣����[ֻ��״̬Ϊ"ʹ��"��ǰ���а�]
	/// <Param name="rsTundish" type="L3RECORDSET">�쳣���ߵļ�¼</Param>
	/// </Method>
	L3LONG TundishOffLineException(L3RECORDSET rsTundish);
};

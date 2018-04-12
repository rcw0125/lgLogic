// �߼���CLadle_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Mag :
	public CL3Object
{
public:
	CLadle_Mag(void);
	virtual ~CLadle_Mag(void);

	DECLARE_L3CLASS(CLadle_Mag,XGMESLogic\\LadleMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Mag)
	DECLARE_L3EVENTSINK_MAP()

	DECLARE_L3PROP_LONG(LadlePlanEvent)               //�ְ��ƻ�״̬�仯�¼�

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CLadle_Mag" name="SetLadleStatus" type="L3LONG">
	/// 
	/// ���øְ�״̬
	/// ARG &gt;&gt; rsLadles: Ҫ����״̬�ĸְ��ļ�¼��
	///     &gt;&gt; strStatus: ���ó�Ϊ��״̬��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// <Param name="strStatus" type="L3STRING"></Param>
	/// </Method>
	L3LONG SetLadleStatus(L3RECORDSET rsLadles, L3STRING strStatus);
	/// <Method class="CLadle_Mag" name="InsertInfos" type="L3LONG">
	/// 
	/// ���ʵ����Ϣ
	/// ARG &gt;&gt;strClassName:����
	///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// <Param name="strClassName" type="L3STRING">����</Param>
	/// </Method>
	L3LONG InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	/// <Method class="CLadle_Mag" name="UpdateInfos" type="L3LONG">
	/// 
	/// �޸�ʵ����Ϣ
	/// ARG &gt;&gt;lpcsClass:����
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// <Param name="lpcsClass" type="LPCTSTR">����</Param>
	/// </Method>
	L3LONG UpdateInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass);//LPCTSTR lpcsClass
	/// <Method class="CLadle_Mag" name="DeleteInfos" type="L3LONG">
	/// 
	/// ɾ��ʵ����Ϣ
	/// ARG &gt;&gt;lpcsClass:����
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// <Param name="lpcsClass" type="LPCTSTR">����</Param>
	/// </Method>
	L3LONG DeleteInfos(L3RECORDSET rsInfos, LPCTSTR lpcsClass);
	/// <Method class="CLadle_Mag" name="GetInfos" type="L3RECORDSET">
	/// 
	/// ��ȡʵ����Ϣ
	/// ARG &gt;&gt;strClassName:����
	///     &gt;&gt;strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
	/// <Param name="lpcsClass" type="LPCTSTR">��ѯ����</Param>
	/// <Param name="lpcsCondition" type="LPCTSTR">����</Param>
	/// </Method>
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);
	/// <Method class="CLadle_Mag" name="SpecifyLadle" type="L3LONG">
	/// 
	/// ָ���ְ�
	/// ARG &gt;&gt; rsLadlePlans: Ҫָ���ְ��ĸְ��ƻ��ļ�¼����
	/// RET &lt;&lt; �ɹ�����true��ʧ�ܷ���false��
	/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SpecifyLadle(L3RECORDSET rsLadlePlans);
	/// <Method class="CLadle_Mag" name="LadlePour" type="L3LONG">
	/// 
	/// �ְ�����
	/// ARG &gt;&gt; rsLadles: Ҫ�����ĸְ��ļ�¼����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadlePour(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleFold" type="L3LONG">
	/// 
	/// �ְ��۹�
	/// ARG &gt;&gt; rsLadles: Ҫ�۹޵ĸְ��ļ�¼����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleFold(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="CancelSpecifyLadle" type="L3LONG">
	/// 
	/// ȡ��ָ��
	/// ARG &gt;&gt; rsLadlePlans: Ҫȡ��ָ���ĸְ��ƻ��ļ�¼����
	/// RET &lt;&lt; �ɹ�����true��ʧ�ܷ���false��
	/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG CancelSpecifyLadle(L3RECORDSET rsLadlePlans);
	/// <Method class="CLadle_Mag" name="ReSpecifyLadle" type="L3LONG">
	/// 
	/// ����ָ���ְ�
	/// ARG &gt;&gt; strReLadleID:ָ���ְ��ţ�
	///          &gt;&gt; rsLadlePlans: Ҫָ���ְ��ĸְ��ƻ��ļ�¼����
	/// RET &lt;&lt; �ɹ�����true��ʧ�ܷ���false��
	/// <Param name="rsLadlePlans" type="L3RECORDSET"></Param>
	/// <Param name="strReLadleID" type="L3STRING"></Param>
	/// </Method>
	L3LONG ReSpecifyLadle(L3RECORDSET rsLadlePlans, L3STRING strReLadleID);



	/// <Method class="CLadle_Mag" name="QueryUnProcessLadlePlan" type="L3RECORDSET">
	/// 
	/// ��ȡ����ƻ���Ϣ�Լ��ϰ�δִ����ɼƻ�
	/// ARG &gt;&gt; strBofID: ת¯�š�
	///         &gt;&gt;strCasterID:������
	/// RET &gt;&gt; �ҵ��ļƻ���¼����
	/// <Param name="strBofID" type="L3STRING"></Param>
	/// <Param name="strCasterID" type="L3STRING"></Param>
	/// </Method>

	L3RECORDSET QueryUnProcessLadlePlan(L3STRING strBOFID, L3STRING strCasterID);


	//��ѯ���øְ�
	/// <Method class="CLadle_Mag" name="GetAvailableLadle" type="L3RECORDSET">
	/// </Method>
	L3RECORDSET GetAvailableLadle(void);

	//��ѯ�ְ����ò���
	/// <Method class="CLadle_Mag" name="GetLadleInnerID" type="L3RECORDSET">
	/// <Param name="strDateLadleID" type="L3STRING">�ְ���</Param>
	/// </Method>
	L3RECORDSET GetLadleInnerID(L3STRING strDateLadleID);

	/// <Method class="CLadle_Mag" name="InsertInnerBuildInfos" type="L3LONG">
	/// 
	/// ������ò���ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG InsertInnerBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateInnerBuildInfos" type="L3LONG">
	/// 
	/// �޸����ò���ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG UpdateInnerBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteInnerBuildInfos" type="L3LONG">
	/// 
	/// ɾ�����ò���ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG DeleteInnerBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetInnerBuildInfos" type="L3RECORDSET">
	/// 
	/// ��ȡ���ò���ʵ����Ϣ
	///     &gt;&gt;strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET GetInnerBuildInfos(L3STRING strCondition);
		
	/// <Method class="CLadle_Mag" name="InsertComTieInfos" type="L3LONG">
	/// 
	/// ��ӹ�������ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  InsertComTieInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateComTieInfos" type="L3LONG">
	/// 
	/// �޸Ĺ�������ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  UpdateComTieInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteComTieInfos" type="L3LONG">
	/// 
	/// ɾ����������ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG DeleteComTieInfos(L3RECORDSET rsInfos);

	/// <Method class="CLadle_Mag" name="GetComTieInfos" type="L3RECORDSET">
	/// 
	/// ��ȡ��������ʵ����Ϣ
	///     &gt;&gt;strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET  GetComTieInfos(L3STRING strCondition);

	/// <Method class="CLadle_Mag" name="InsertComRepInfos" type="L3LONG">
	/// 
	/// ��ӹ������޲�ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  InsertComRepInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateComRepInfos" type="L3LONG">
	/// 
	/// �޸Ĺ������޲�ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  UpdateComRepInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteComRepInfos" type="L3LONG">
	/// 
	/// ɾ���������޲�ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  DeleteComRepInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetComRepInfos" type="L3RECORDSET">
	/// 
	/// ��ȡ�������޲�ʵ����Ϣ
	///     &gt;&gt;strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET  GetComRepInfos(L3STRING strCondition);

	/// <Method class="CLadle_Mag" name="InsertFinBuildInfos" type="L3LONG">
	/// 
	/// ��ӹ���������ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  InsertFinBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateFinBuildInfos" type="L3LONG">
	/// 
	/// �޸Ĺ���������ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  UpdateFinBuildInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteFinBuildInfos" type="L3LONG">
	/// 
	/// ɾ������������ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  DeleteFinBuildInfos(L3RECORDSET rsInfos);

	/// <Method class="CLadle_Mag" name="GetFinBuildInfos" type="L3RECORDSET">
	/// 
	/// ��ȡ����������ʵ����Ϣ
	///     &gt;&gt;strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET  GetFinBuildInfos(L3STRING strCondition);


	/// <Method class="CLadle_Mag" name="InsertChaDreLinInfos" type="L3LONG">
	/// 
	/// ��ӹ����㻻����ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  InsertChaDreLinInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateChaDreLinInfos" type="L3LONG">
	/// 
	/// �޸Ĺ����㻻����ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  UpdateChaDreLinInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteChaDreLinInfos" type="L3LONG">
	/// 
	/// ɾ�������㻻����ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  DeleteChaDreLinInfos(L3RECORDSET rsInfos);

	/// <Method class="CLadle_Mag" name="GetChaDreLinInfos" type="L3RECORDSET">
	/// 
	/// ��ȡ�����㻻����ʵ����Ϣ
	///     &gt;&gt;strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET  GetChaDreLinInfos(L3STRING strCondition);


	/// <Method class="CLadle_Mag" name="InsertFireInfos" type="L3LONG">
	/// 
	/// ��Ӻ濾ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  InsertFireInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateFireInfos" type="L3LONG">
	/// 
	/// �޸ĺ濾ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  UpdateFireInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteFireInfos" type="L3LONG">
	/// 
	/// ɾ���濾ʵ����Ϣ
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG  DeleteFireInfos(L3RECORDSET rsInfos);

	/// <Method class="CLadle_Mag" name="GetFireInfos" type="L3RECORDSET">
	/// 
	/// ��ȡ�濾ʵ����Ϣ
	///     &gt;&gt;strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET  GetFireInfos(L3STRING strCondition);


	/// <Method class="CLadle_Mag" name="InsertLadleUseInfos" type="L3LONG">
	/// ���ʹ����Ϣ
	/// <Param name="rsInfos" type="L3RECORDSET">��ӵļ�¼��</Param>
	/// </Method>
	L3LONG InsertLadleUseInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="UpdateLadleUseInfos" type="L3LONG">
	/// �޸�ʹ����Ϣ
	/// <Param name="rsInfos" type="L3RECORDSET">�޸ĵļ�¼��</Param>
	/// </Method>
	L3LONG UpdateLadleUseInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteLadleUseInfos" type="L3LONG">
	/// ɾ��ʹ����Ϣ
	/// <Param name="rsInfos" type="L3RECORDSET">ɾ���ļ�¼��</Param>
	/// </Method>
	L3LONG DeleteLadleUseInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetLadleUseInfos" type="L3RECORDSET">
	/// ��ѯʹ����Ϣ
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET GetLadleUseInfos(L3STRING strCondition);
	/// <Method class="CLadle_Mag" name="GetUseByLadleID" type="L3RECORDSET">
	/// ���ݸְ��Ż�ȡ�ְ��ϴ���תʹ����Ϣ
	/// <Param name="strLadleID" type="L3STRING">�ְ���</Param>
	/// </Method>
	L3RECORDSET GetUseByLadleID(L3STRING strLadleID);
	/// <Method class="CLadle_Mag" name="SetLadleInfoTaping" type="L3LONG">
	/// ת¯����ʱ���øְ��ϼ���Ϣ�Լ��ְ�������Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SetLadleInfoTaping(L3RECORDSET dsInfo);

	/// <Method class="CLadle_Mag" name="GetIrrEndTime" type="L3RECORDSET">
	/// ͨ���ְ��Ų�ѯ�˸ְ��ϴ�ͣ��ʱ��
	/// <Param name="strLadleID" type="L3STRING">�ְ���</Param>
	/// </Method>
	L3RECORDSET GetIrrEndTime(L3STRING strLadleID);
	/// <Method class="CLadle_Mag" name="LadleInnerBuildStart" type="L3LONG">
	/// �ְ����ò�������ʼ
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleInnerBuildStart(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleInnerBuildEnd" type="L3LONG">
	/// �ְ����ò���������
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleInnerBuildEnd(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleWorkBuildStart" type="L3LONG">
	/// �ְ���������/������ʼ
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleWorkBuildStart(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleWorkBuildEnd" type="L3LONG">
	/// �ְ���������/��������
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleWorkBuildEnd(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Fin_Build" name="LadleWorkFireStart" type="L3LONG">
	/// �ְ�������濾��ʼ
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleWorkFireStart(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleWorkFireEnd" type="L3LONG">
	/// �ְ�������濾����
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleWorkFireEnd(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleHotFireStart" type="L3LONG">
	/// �ְ��ȱ��濾��ʼ
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleHotFireStart(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="LadleHotFireEnd" type="L3LONG">
	/// �ְ��ȱ��濾����
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleHotFireEnd(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="BOFTapingStart" type="L3BOOL">
	/// ��¼ת¯���ֿ�ʼ//20081229Liao
	/// <Param name="strUnitID" type="L3STRING">¯��</Param>
	/// <Param name="dtTapTime" type="L3DATETIME">���ֿ�ʼʱ��</Param>
	/// <Param name="strHeatID" type="L3STRING">¯��</Param>
	/// </Method>
	L3BOOL BOFTapingStart(L3STRING strUnitID, L3DATETIME dtTapTime, L3STRING strHeatID);
	/// <Method class="CLadle_Mag" name="UpdateLadlePourInfos" type="L3LONG">
	/// �޸ĸְ�����ʵ��
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateLadlePourInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteLadlePourInfos" type="L3LONG">
	/// ɾ���ְ�����ʵ��
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteLadlePourInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetLadlePourInfos" type="L3RECORDSET">
	/// ��ȡ�ְ�����ʵ��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLadlePourInfos(L3STRING strCondition);
	/// <Method class="CLadle_Mag" name="UpdateLadleFoldInfos" type="L3LONG">
	/// �޸ĸְ��۹�ʵ��
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateLadleFoldInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="DeleteLadleFoldInfos" type="L3LONG">
	/// ɾ���ְ��۹�ʵ��
	/// <Param name="rsInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteLadleFoldInfos(L3RECORDSET rsInfos);
	/// <Method class="CLadle_Mag" name="GetLadleFoldInfos" type="L3RECORDSET">
	/// ��ȡ�ְ��۹�ʵ��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetLadleFoldInfos(L3STRING strCondition);
	/// <Method class="CLadle_Mag" name="LadleThrow" type="L3LONG">
	/// �ְ�˦��
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleThrow(L3RECORDSET rsLadles);
	/// <Method class="CLadle_Mag" name="MeasureDesignate" type="L3LONG">
	/// �ְ�����ָ��
	/// <Param name="strLadleID" type="L3STRING">�ְ���</Param>
	/// </Method>
	L3LONG MeasureDesignate(L3STRING strLadleID);
	/// <Method class="CLadle_Mag" name="LadleOffLineException" type="L3LONG">
	/// �ְ��쳣����
	/// <Param name="rsLadles" type="L3RECORDSET">���߼�¼</Param>
	/// </Method>
	L3LONG LadleOffLineException(L3RECORDSET rsLadles);

	/// <Method class="CLadle_Mag" name="LadleInnerFireStart" type="L3LONG">
	/// �ְ����ò�濾��ʼ
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG	LadleInnerFireStart(L3RECORDSET rsLadles);

	/// <Method class="CLadle_Mag" name="LadleInnerFireEnd" type="L3LONG">
	/// �ְ����ò�濾����
	/// <Param name="rsLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG LadleInnerFireEnd(L3RECORDSET rsLadles);
	};

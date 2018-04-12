// �߼���CIronLadle_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CIronLadle_Mag :
	public CL3Object
{
public:
	CIronLadle_Mag(void);
	virtual ~CIronLadle_Mag(void);

	DECLARE_L3CLASS(CIronLadle_Mag,XGMESLogic\\IronLadleMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CIronLadle_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CIronLadle_Mag" name="GetInfos" type="L3RECORDSET">
	/// 
	/// ��ȡʵ����Ϣ
	/// ARG &gt;&gt;strClassName:����
	///     &gt;&gt;strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����reInfos��ʧ�ܷ���Null
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// <Param name="strClassName" type="L3STRING">����</Param>
	/// </Method>
	L3RECORDSET GetInfos(L3STRING strCondition, L3STRING strClassName);
	/// <Method class="CIronLadle_Mag" name="InsertInfos" type="L3LONG">
	/// 
	/// ���ʵ����Ϣ
	/// ARG &gt;&gt;strClassName:����
	///     &gt;&gt;rsInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// <Param name="strClassName" type="L3STRING">����</Param>
	/// </Method>
	L3LONG InsertInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	/// <Method class="CIronLadle_Mag" name="UpdateInfos" type="L3LONG">
	/// 
	/// �޸�ʵ����Ϣ
	/// ARG &gt;&gt;strClassName:����
	///     &gt;&gt;rsInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// <Param name="strClassName" type="L3STRING">����</Param>
	/// </Method>
	L3LONG UpdateInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	/// <Method class="CIronLadle_Mag" name="DeleteInfos" type="L3LONG">
	/// 
	/// ɾ��ʵ����Ϣ
	/// ARG &gt;&gt;strClassName:����
	///     &gt;&gt;rsInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// <Param name="strClassName" type="L3STRING">����</Param>
	/// </Method>
	L3LONG DeleteInfos(L3RECORDSET rsInfos, L3STRING strClassName);
	
	
	/// <Method class="CIronLadle_Mag" name="IronLadleTieStart" type="L3LONG">
	/// 
	/// ������Ὺʼ
	/// ARG &gt;&gt;rsIronLadles: Ҫ��Ὺʼ�������ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
	/// </Method>
	L3LONG IronLadleTieStart(L3RECORDSET rsIronLadles);
	
	/// <Method class="CIronLadle_Mag" name="IronLadleTieEnd" type="L3LONG">
	/// 
	/// ����������
	/// ARG &gt;&gt;rsIronLadles: Ҫ�������������ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
	/// </Method>
	L3LONG IronLadleTieEnd(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleSmallFireStart" type="L3LONG">
	/// 
	/// ����С��ʼ
	/// ARG &gt;&gt;rsIronLadles: ҪС��ʼ�������ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
	/// </Method>
	L3LONG IronLadleSmallFireStart(L3RECORDSET rsIronLadles);
	
	/// <Method class="CIronLadle_Mag" name="IronLadleSmallFireEnd" type="L3LONG">
	/// 
	/// ����С�����
	/// ARG &gt;&gt;rsIronLadles: ҪС������������ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
	/// </Method>
	L3LONG IronLadleSmallFireEnd(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleMiddleFireStart" type="L3LONG">
	/// 
	/// �����л�ʼ
	/// ARG &gt;&gt;rsIronLadles: Ҫ�л�ʼ�������ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
	/// </Method>
	L3LONG IronLadleMiddleFireStart(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleMiddleFireEnd" type="L3LONG">
	/// 
	/// �����л����
	/// ARG &gt;&gt;rsIronLadles: Ҫ�л�����������ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
	/// </Method>
	L3LONG IronLadleMiddleFireEnd(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleBigFireStart" type="L3LONG">
	/// 
	/// �������ʼ
	/// ARG &gt;&gt;rsIronLadles: Ҫ���ʼ�������ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
	/// </Method>
	L3LONG IronLadleBigFireStart(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleBigFireEnd" type="L3LONG">
	/// 
	/// ����������
	/// ARG &gt;&gt;rsIronLadles: Ҫ�������������ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE
	/// <Param name="rsIronLadles" type="L3RECORDSET">�����ļ�¼��</Param>
	/// </Method>
	L3LONG IronLadleBigFireEnd(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLaldeStopUse" type="L3LONG">
	/// ��������ͣ��(תΪ�䱸)
	/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG IronLaldeStopUse(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleWaitRepair" type="L3LONG">
	/// �������ߴ���
	/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG IronLadleWaitRepair(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="InsertTieInfos" type="L3LONG">
	/// 
	/// ��Ӵ��ʵ����Ϣ
	/// ARG  &gt;&gt;rsTieInfos: Ҫ��ӵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTieInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG InsertTieInfos(L3RECORDSET rsTieInfos);
	/// <Method class="CIronLadle_Mag" name="UpdateTieInfos" type="L3LONG">
	/// 
	/// �޸Ĵ��ʵ����Ϣ
	/// ARG &gt;&gt;rsTieInfos: Ҫ�޸ĵ�ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTieInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG UpdateTieInfos(L3RECORDSET rsTieInfos);
	/// <Method class="CIronLadle_Mag" name="DeleteTieInfos" type="L3LONG">
	/// 
	/// ɾ�����ʵ����Ϣ
	/// ARG &gt;&gt;rsTieInfos: Ҫɾ����ʵ���ļ�¼��
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsTieInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG DeleteTieInfos(L3RECORDSET rsTieInfos);
	/// <Method class="CIronLadle_Mag" name="GetTieInfos" type="L3RECORDSET">
	/// ��ȡ���ʵ����Ϣ
	/// ARG &gt;&gt;strCondition
	/// RET &lt;&lt;�ɹ����ؼ�¼��rsTieInfos,ʧ�ܷ���NULL
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET GetTieInfos(L3STRING strCondition);
	
	/// <Method class="CIronLadle_Mag" name="InsertFireInfos" type="L3LONG">
	/// ��Ӻ濾��Ϣ
	/// <Param name="dsFireInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertFireInfos(L3RECORDSET dsFireInfos);
	/// <Method class="CIronLadle_Mag" name="UpdateFireInfos" type="L3LONG">
	/// �޸ĺ濾��Ϣ
	/// <Param name="dsFireInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG UpdateFireInfos(L3RECORDSET dsFireInfos);
	/// <Method class="CIronLadle_Mag" name="DeleteFireInfos" type="L3LONG">
	/// ɾ���濾��Ϣ
	/// <Param name="dsFireInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG DeleteFireInfos(L3RECORDSET dsFireInfos);
	/// <Method class="CIronLadle_Mag" name="GetFireInfos" type="L3RECORDSET">
	/// ��ȡ�濾��Ϣ
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET GetFireInfos(L3STRING strCondition);

	/// <Method class="CIronLadle_Mag" name="InsertUseInfos" type="L3LONG">
	/// ���ʹ����Ϣ
	/// <Param name="dsUseInfos" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertUseInfos(L3RECORDSET dsUseInfos);
	/// <Method class="CIronLadle_Mag" name="UpdateUseInfos" type="L3LONG">
	/// �޸�ʹ����Ϣ
	/// <Param name="dsUseInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG UpdateUseInfos(L3RECORDSET dsUseInfos);
	/// <Method class="CIronLadle_Mag" name="DeleteUseInfos" type="L3LONG">
	/// ɾ��ʹ����Ϣ
	/// <Param name="dsUseInfos" type="L3RECORDSET">ʵ�����ݼ�</Param>
	/// </Method>
	L3LONG DeleteUseInfos(L3RECORDSET dsUseInfos);
	/// <Method class="CIronLadle_Mag" name="GetUseInfos" type="L3RECORDSET">
	/// ��ȡʹ����Ϣ
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET GetUseInfos(L3STRING strCondition);

	/// <Method class="CIronLadle_Mag" name="GetIronLadle_Age" type="L3LONG">
	/// ��ȡ��������
	/// <Param name="strIronladleId" type="L3STRING">������</Param>
	/// </Method>
	L3LONG GetIronLadle_Age(L3STRING strIronladleId);
	/// <Method class="CIronLadle_Mag" name="IronLadleUse" type="L3LONG">
	/// ����תΪʹ��
	/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG IronLadleUse(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleHot" type="L3LONG">
	/// ת¯����������Ϊ�ȱ�
	/// <Param name="rsIronLadles" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG IronLadleHot(L3RECORDSET rsIronLadles);
	/// <Method class="CIronLadle_Mag" name="IronLadleOffLineException" type="L3LONG">
	/// �����쳣����
	/// <Param name="rsIronLadles" type="L3RECORDSET">���ߵļ�¼</Param>
	/// </Method>
	L3LONG IronLadleOffLineException(L3RECORDSET rsIronLadles);
};

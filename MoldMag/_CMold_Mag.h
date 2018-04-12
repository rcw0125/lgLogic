// �߼���CMold_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMold_Mag :
	public CL3Object
{
public:
	CMold_Mag(void);
	virtual ~CMold_Mag(void);

	DECLARE_L3CLASS(CMold_Mag,XGMESLogic\\MoldMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	L3LONG UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3LONG DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);


	/// <Method class="CMold_Mag" name="MoldInstallStart" type="L3LONG">
	/// 
	/// �ᾧ��װ�俪ʼ
	/// ARG &gt;&gt; rsMolds: Ҫװ�俪ʼ�Ľᾧ���ļ�¼�����������MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldInstallStart(L3RECORDSET rsMolds);
	/// <Method class="CMold_Mag" name="MoldInstallEnd" type="L3LONG">
	/// 
	/// �ᾧ��װ�����
	/// ARG &gt;&gt; rsMolds: Ҫװ������Ľᾧ���ļ�¼�����������MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldInstallEnd(L3RECORDSET rsMolds);
	/// <Method class="CMold_Mag" name="MoldOnLine" type="L3LONG">
	/// 
	/// �ᾧ�����ϲ���
	/// ARG &gt;&gt; rsMolds: Ҫ���ϵĽᾧ���ļ�¼�����������MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldOnLine(L3RECORDSET rsMolds);
	/// <Method class="CMold_Mag" name="MoldOffLine" type="L3LONG">
	/// 
	/// �ᾧ�����²���
	/// ARG &gt;&gt; rsMolds: Ҫ���µĽᾧ���ļ�¼�����������MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldOffLine(L3RECORDSET rsMolds);
	/// <Method class="CMold_Mag" name="InsertPipeInstallInfo" type="L3LONG">
	/// 
	/// ���ͭ��װ��ʵ��
	/// ARG &gt;&gt; rsPipeInstalls: Ҫ��ӵ�ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertPipeInstallInfo(L3RECORDSET rsPipeInstalls);
	/// <Method class="CMold_Mag" name="UpdatePipeInstallInfo" type="L3LONG">
	/// 
	/// �޸�ͭ��װ��ʵ��
	/// ARG &gt;&gt; rsPipeInstalls: Ҫ�޸ĵ�ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdatePipeInstallInfo(L3RECORDSET rsPipeInstalls);
	/// <Method class="CMold_Mag" name="DeletePipeInstallInfo" type="L3LONG">
	/// 
	/// ɾ��ͭ��װ��ʵ��
	/// ARG &gt;&gt; rsPipeInstalls: Ҫɾ����ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPipeInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeletePipeInstallInfo(L3RECORDSET rsPipeInstalls);
	/// <Method class="CMold_Mag" name="GetPipeInstallInfo" type="L3RECORDSET">
	/// 
	/// ��ȡͭ��װ��ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsPipeInstalls��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetPipeInstallInfo(L3STRING strCondition);
	/// <Method class="CMold_Mag" name="InsertBoardInstallInfo" type="L3LONG">
	/// 
	/// ���ͭ��װ��ʵ��
	/// ARG &gt;&gt; rsBoardInstalls: Ҫ��ӵ�ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertBoardInstallInfo(L3RECORDSET rsBoardInstalls);
	/// <Method class="CMold_Mag" name="UpdateBoardInstallInfo" type="L3LONG">
	/// 
	/// �޸�ͭ��װ��ʵ��
	/// ARG &gt;&gt; rsBoardInstalls: Ҫ�޸ĵ�ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateBoardInstallInfo(L3RECORDSET rsBoardInstalls);
	/// <Method class="CMold_Mag" name="DeleteBoardInstallInfo" type="L3LONG">
	/// 
	/// ɾ��ͭ��װ��ʵ��
	/// ARG &gt;&gt; rsBoardInstalls: Ҫɾ����ͭ��װ��ļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsBoardInstalls" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteBoardInstallInfo(L3RECORDSET rsBoardInstalls);
	/// <Method class="CMold_Mag" name="GetBoardInstallInfo" type="L3RECORDSET">
	/// 
	/// ��ȡͭ��װ��ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsBoardInstalls:��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetBoardInstallInfo(L3STRING strCondition);
	/// <Method class="CMold_Mag" name="InsertPipeUseInfo" type="L3LONG">
	/// 
	/// ���ͭ��ʹ��ʵ��
	/// ARG &gt;&gt; rsPipeUses: Ҫ��ӵ�ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertPipeUseInfo(L3RECORDSET rsPipeUses);
	/// <Method class="CMold_Mag" name="UpdatePipeUseInfo" type="L3LONG">
	/// 
	/// �޸�ͭ��ʹ��ʵ��
	/// ARG &gt;&gt; rsPipeUses: Ҫ�޸ĵ�ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdatePipeUseInfo(L3RECORDSET rsPipeUses);
	/// <Method class="CMold_Mag" name="DeletePipeUseInfo" type="L3LONG">
	/// 
	/// ɾ��ͭ��ʹ��ʵ��
	/// ARG &gt;&gt; rsPipeUses: Ҫɾ����ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsPipeUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeletePipeUseInfo(L3RECORDSET rsPipeUses);
	/// <Method class="CMold_Mag" name="GetPipeUseInfo" type="L3RECORDSET">
	/// 
	/// ��ȡͭ��װ��ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsPipeUses��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetPipeUseInfo(L3STRING strCondition);
	/// <Method class="CMold_Mag" name="InsertBoardUseInfo" type="L3LONG">
	/// 
	/// ���ͭ��ʹ��ʵ��
	/// ARG &gt;&gt; rsBoardUses: Ҫ��ӵ�ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertBoardUseInfo(L3RECORDSET rsBoardUses);
	/// <Method class="CMold_Mag" name="UpdateBoardUseInfo" type="L3LONG">
	/// 
	/// �޸�ͭ��ʹ��ʵ��
	/// ARG &gt;&gt; rsBoardUses: Ҫ�޸ĵ�ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG UpdateBoardUseInfo(L3RECORDSET rsBoardUses);
	/// <Method class="CMold_Mag" name="DeleteBoardUseInfo" type="L3LONG">
	/// 
	/// ɾ��ͭ��ʹ��ʵ��
	/// ARG &gt;&gt; rsBoardUses: Ҫɾ����ͭ��ʹ�õļ�¼����������� MoldID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsBoardUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteBoardUseInfo(L3RECORDSET rsBoardUses);
	/// <Method class="CMold_Mag" name="GetBoardUseInfo" type="L3RECORDSET">
	/// 
	/// ��ȡͭ��װ��ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsBoardUses��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetBoardUseInfo(L3STRING strCondition);
	/// <Method class="CMold_Mag" name="MoldCheckCold" type="L3LONG">
	/// �ᾧ����������Ϊ����
	/// <Param name="dsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldCheckCold(L3RECORDSET dsMolds);
	/// <Method class="CMold_Mag" name="MoldCheckBuild" type="L3LONG">
	/// �ᾧ����������Ϊ��װ
	/// <Param name="dsMolds" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG MoldCheckBuild(L3RECORDSET dsMolds);//
	/// <Method class="CMold_Mag" name="MoldChangeFlowID" type="L3LONG">
	/// �ᾧ����������Ϊ��װ
	/// <Param name="strMoldID" type="L3STRING"></Param>
	/// <Param name="strNewFlowID" type="L3STRING"></Param>
	/// </Method>
	L3LONG MoldChangeFlowID(L3STRING strMoldID,L3STRING strNewFlowID);
};

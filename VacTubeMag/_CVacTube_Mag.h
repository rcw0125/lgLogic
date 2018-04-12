// �߼���CVacTube_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CVacTube_Mag :
	public CL3Object
{
public:
	CVacTube_Mag(void);
	virtual ~CVacTube_Mag(void);

	DECLARE_L3CLASS(CVacTube_Mag,XGMESLogic\\VacTubeMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	L3BOOL UpdateInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3BOOL DeleteInfos(L3RECORDSET rsInfos,LPCTSTR lpcsClass);
	L3RECORDSET GetInfos(LPCTSTR lpcsClass, LPCTSTR lpcsCondition);

	/// <Method class="CVacTube_Mag" name="VacTubeOnPosition" type="L3BOOL">
	/// 
	/// ��չ���λ
	/// ARG &gt;&gt; rsVacTubes: ҪҪ��λ����չܵļ�¼�����������VacTube_ID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL VacTubeOnPosition(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="VacTubeBuildStart" type="L3BOOL">
	/// 
	/// ��ղ۲۹�������ʼ
	/// ARG &gt;&gt; rsVacTubes: ҪҪ������ʼ����չܵļ�¼�����������VacTube_ID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL VacTubeBuildStart(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="VacTubeBuildEnd" type="L3BOOL">
	/// 
	/// ��ղ۲۹���������
	/// ARG &gt;&gt; rsVacTubes: ҪҪ������������չܵļ�¼�����������VacTube_ID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL VacTubeBuildEnd(L3RECORDSET rsVacTubes);
	
	/// <Method class="CVacTube_Mag" name="InsertVacTubeBuild" type="L3LONG">
	/// 
	/// �����ղ�����ʵ��
	/// ARG &gt;&gt; rsVacTubes: Ҫ��ӵ���ղ������ļ�¼����������� VacTube_ID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeBuild(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeBuild" type="L3BOOL">
	/// 
	/// �޸���ղ�����ʵ��
	/// ARG &gt;&gt; rsVacTubes: Ҫ�޸ĵ���ղ������ļ�¼����������� VacTube_ID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeBuild(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeBuild" type="L3LONG">
	/// 
	/// ɾ����ղ�����ʵ��
	/// ARG &gt;&gt; rsVacTubes: Ҫɾ������ղ������ļ�¼����������� VacTube_ID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteVacTubeBuild(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="GetVacTubeBuild" type="L3RECORDSET">
	/// 
	/// ��ȡ��ղ�����ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsVacTubes��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeBuild(L3STRING strCondition);
	
	/// <Method class="CVacTube_Mag" name="InsertHotSypBuild" type="L3LONG">
	/// 
	/// ������������ʵ��
	/// ARG &gt;&gt; rsHotSyps: Ҫ��ӵ�����������ļ�¼����������� Hot_Syp_ID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsHotSyps" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertHotSypBuild(L3RECORDSET rsHotSyps);
	/// <Method class="CVacTube_Mag" name="UpdateHotSypBuild" type="L3BOOL">
	/// 
	/// �޸����������ʵ��
	/// ARG &gt;&gt; rsHotSyps: Ҫ�޸ĵ�����������ļ�¼����������� Hot_Syp_ID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsHotSyps" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateHotSypBuild(L3RECORDSET rsHotSyps);
	/// <Method class="CVacTube_Mag" name="DeleteHotSypBuild" type="L3LONG">
	/// 
	/// ɾ�����������ʵ��
	/// ARG &gt;&gt; rsHotSyps: Ҫɾ��������������ļ�¼����������� Hot_Syp_ID�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsHotSyps" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteHotSypBuild(L3RECORDSET rsHotSyps);
	/// <Method class="CVacTube_Mag" name="GetHotSypBuild" type="L3RECORDSET">
	/// 
	/// ��ȡ��ղ�����ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsHotSyps��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetHotSypBuild(L3STRING strCondition);
	/// <Method class="CVacTube_Mag" name="InsertVacTubeFire" type="L3LONG">
	/// 
	/// �����ղۺ濾ʵ��
	/// ARG &gt;&gt; rsFires: Ҫ��ӵ���ղۺ濾�ļ�¼����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeFire(L3RECORDSET rsFires);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeFire" type="L3BOOL">
	/// 
	/// �޸���ղۺ濾ʵ��
	/// ARG &gt;&gt; rsFires: Ҫ�޸ĵ���ղۺ濾�ļ�¼����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeFire(L3RECORDSET rsFires);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeFire" type="L3LONG">
	/// 
	/// ɾ����ղۺ濾ʵ��
	/// ARG &gt;&gt; rsFires: Ҫɾ������ղۺ濾�ļ�¼����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsFires" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteVacTubeFire(L3RECORDSET rsFires);
	/// <Method class="CVacTube_Mag" name="GetVacTubeFire" type="L3RECORDSET">
	/// 
	/// ��ȡ��ղۺ濾ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsFires��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeFire(L3STRING strCondition);
	/// <Method class="CVacTube_Mag" name="InsertVacTubeUse" type="L3LONG">
	/// 
	/// �����ղ�ʹ��ʵ��
	/// ARG &gt;&gt; rsUses: Ҫ��ӵ���ղ�ʹ�õļ�¼����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeUse(L3RECORDSET rsUses);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeUse" type="L3BOOL">
	/// 
	/// �޸���ղ�ʹ��ʵ��
	/// ARG &gt;&gt; rsUses: Ҫ�޸ĵ���ղ�ʹ�õļ�¼����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeUse(L3RECORDSET rsUses);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeUse" type="L3LONG">
	/// 
	/// ɾ����ղ�ʹ��ʵ��
	/// ARG &gt;&gt; rsUses: Ҫɾ������ղ�ʹ�õļ�¼����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsUses" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteVacTubeUse(L3RECORDSET rsUses);
	/// <Method class="CVacTube_Mag" name="GetVacTubeUse" type="L3RECORDSET">
	/// 
	/// ��ȡ��ղ�ʹ��ʵ��
	/// ARG &gt;&gt; strCondition: ��ѯ����
	/// RET &lt;&lt; �ɹ�����rsUses��ʧ�ܷ���null��
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeUse(L3STRING strCondition);
	
	/// <Method class="CVacTube_Mag" name="HotOn" type="L3LONG">
	/// ���������
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG HotOn(L3RECORDSET rsVacTubes);
	/// <Method class="CVacTube_Mag" name="HotOff" type="L3LONG">
	/// ���������
	/// <Param name="rsVacTubes" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG HotOff(L3RECORDSET rsVacTubes);
	
	/// <Method class="CVacTube_Mag" name="VactubeOnLine" type="L3LONG">
	/// RH����ʼ,��ղ�����ʹ��
	/// <Param name="strPosition" type="L3STRING">����λ</Param>
	/// </Method>
	L3LONG VactubeOnLine(L3STRING strPosition);
	/// <Method class="CVacTube_Mag" name="VactubeOffLine" type="L3LONG">
	/// RH�������,��ղ��ȱ�
	/// <Param name="strPosition" type="L3STRING">����λ</Param>
	/// </Method>
	L3LONG VactubeOffLine(L3STRING strPosition);
	
	/// <Method class="CVacTube_Mag" name="AccepteFireData" type="L3BOOL">
	/// ���պ濾����
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AccepteFireData(L3RECORDSET rsData);
	/// <Method class="CVacTube_Mag" name="Vactube_Install" type="L3LONG">
	/// ��ղ���װ
	/// <Param name="strUpID" type="L3STRING">�ϲ��ۺ�</Param>
	/// <Param name="strDownID" type="L3STRING">�²��ۺ�</Param>
	/// </Method>
	L3LONG Vactube_Install(L3STRING strUpID, L3STRING strDownID);
	/// <Method class="CVacTube_Mag" name="VacTubeFire" type="L3LONG">
	/// �濾λ�ã�2(AԤ��λ)��3(BԤ��λ)��A(A����λ)��B(B����λ)
	/// �濾���1(�濾��ʼ)��0(�濾����)
	/// <Param name="strPositon" type="L3STRING">�濾λ��</Param>
	/// <Param name="strType" type="L3STRING">�濾���</Param>
	/// </Method>
	L3LONG VacTubeFire(L3STRING strPositon, L3STRING strType);
	/// <Method class="CVacTube_Mag" name="VacTubeCheck" type="L3LONG">
	/// ��ղ����߼��
	/// <Param name="strPosition" type="L3STRING"></Param>
	/// </Method>
	L3LONG VacTubeCheck(L3STRING strPosition);
	/// <Method class="CVacTube_Mag" name="VacTubeCheckOver" type="L3LONG">
	/// ��ղ����߼�����
	/// 1:����
	/// 2:С��
	/// 3:��������
	/// <Param name="strVacTubeCode" type="L3STRING">��ղ۱��</Param>
	/// <Param name="strType" type="L3STRING">��������</Param>
	/// </Method>
	L3LONG VacTubeCheckOver(L3STRING strVacTubeCode, L3STRING strType);
	/// <Method class="CVacTube_Mag" name="InsertVacTubeRepair" type="L3LONG">
	/// �����ղ��޲���Ϣ
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeRepair" type="L3BOOL">
	/// �޸���ղ��޲���Ϣ
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeRepair" type="L3BOOL">
	/// ɾ����ղ��޲���Ϣ
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteVacTubeRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="GetVacTubeRepair" type="L3RECORDSET">
	/// ��ȡ��ղ��޲���Ϣ
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeRepair(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="InsertHotSypRepair" type="L3LONG">
	/// ���������޲���Ϣ
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertHotSypRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="UpdateHotSypRepair" type="L3BOOL">
	/// �޸�������޲���Ϣ
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateHotSypRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="DeleteHotSypRepair" type="L3BOOL">
	/// ɾ��������޲���Ϣ
	/// <Param name="rsRepair" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteHotSypRepair(L3RECORDSET rsRepair);
	/// <Method class="CVacTube_Mag" name="GetHotSypRepair" type="L3RECORDSET">
	/// ��ȡ������޲���Ϣ
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetHotSypRepair(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="InsertVacTubeFireInfo" type="L3LONG">
	/// ��Ӻ濾��ϸ��Ϣ
	/// <Param name="rsFireInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeFireInfo(L3RECORDSET rsFireInfo);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeFireInfo" type="L3BOOL">
	/// �޸ĺ濾��ϸ��Ϣ
	/// <Param name="rsFireInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeFireInfo(L3RECORDSET rsFireInfo);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeFireInfo" type="L3BOOL">
	/// ɾ���濾��ϸ��Ϣ
	/// <Param name="rsFireInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteVacTubeFireInfo(L3RECORDSET rsFireInfo);
	/// <Method class="CVacTube_Mag" name="GetVacTubeFireInfo" type="L3RECORDSET">
	/// ��ȡ�濾��ϸ��Ϣ
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeFireInfo(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="InsertVacTubeUseInfo" type="L3LONG">
	/// �����ղ�ʹ����ϸ��Ϣ
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertVacTubeUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="UpdateVacTubeUseInfo" type="L3BOOL">
	/// �޸���ղ�ʹ����ϸ��Ϣ
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateVacTubeUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="DeleteVacTubeUseInfo" type="L3BOOL">
	/// ɾ����ղ�ʹ����ϸ��Ϣ
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteVacTubeUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="GetVacTubeUseInfo" type="L3RECORDSET">
	/// ��ȡ��ղ�ʹ����ϸ��Ϣ
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetVacTubeUseInfo(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="InsertHotSypUseInfo" type="L3LONG">
	/// ��������ʹ����Ϣ
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertHotSypUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="UpdateHotSypUseInfo" type="L3BOOL">
	/// �޸������ʹ����Ϣ
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL UpdateHotSypUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="DeleteHotSypUseInfo" type="L3BOOL">
	/// ɾ�������ʹ����Ϣ
	/// <Param name="rsUseInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL DeleteHotSypUseInfo(L3RECORDSET rsUseInfo);
	/// <Method class="CVacTube_Mag" name="GetHotSypUseInfo" type="L3RECORDSET">
	/// ��ȡ�����ʹ����Ϣ
	/// <Param name="strCondition" type="L3STRING"></Param>
	/// </Method>
	L3RECORDSET GetHotSypUseInfo(L3STRING strCondition);

	/// <Method class="CVacTube_Mag" name="LastVacTubeAesSoaTotalLenOfHeatID" type="L3LONG">
	/// ��ȡ��¯�ε�����������ۼ�ʱ��
	/// <Param name="strHeatID" type="L3STRING"></Param>
	/// </Method>
	L3LONG LastVacTubeAesSoaTotalLenOfHeatID(L3STRING strHeatID);
};

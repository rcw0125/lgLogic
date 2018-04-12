// �߼���CDispatch_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once




class CDispatch_Mag :
	public CL3Object
{
public:
	CDispatch_Mag(void);
	virtual ~CDispatch_Mag(void);

	DECLARE_L3CLASS(CDispatch_Mag,XGMESLogic\\DispatchMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDispatch_Mag)
	DECLARE_L3EVENTSINK_MAP()

	DECLARE_L3PROP_LONG(SteelBackAppEvent)      //��ˮ���������¼�
	DECLARE_L3PROP_LONG(SteelReturnAppEvent)     //��ˮ��¯�����¼�
	DECLARE_L3PROP_LONG(SteelDivAppEvent)		//��ˮ¯�ηָ������¼�
	DECLARE_L3PROP_LONG(SteelExchangeAppEvent)	//��ˮ�ĸ������¼�

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CDispatch_Mag" name="SteelTurnApp" type="L3BOOL">
	/// 
	/// ��ˮ��¯����
	/// ARG&gt;&gt; 
	/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID�ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
	/// </Method>
	L3BOOL SteelTurnApp(L3RECORDSET rsSteelTurnAppData);

	/// <Method class="CDispatch_Mag" name="SteelTurn" type="L3BOOL">
	/// 
	/// ��ˮ��¯
	/// ARG&gt;&gt; strPreHeatID :Ԥ��¯��
	/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������GUID\PreHeatID\All_Turn_Flag�����ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
	/// </Method>
	L3LONG SteelTurn(L3RECORDSET rsSteelTurnData);

	/// <Method class="CDispatch_Mag" name="SteelBackApp" type="L3BOOL">
	/// 
	/// ��ˮ��������
	/// ARG&gt;&gt; 
	/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID�ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
	/// </Method>
	L3BOOL SteelBackApp(L3RECORDSET rsSteelBackAppData);

	/// <Method class="CDispatch_Mag" name="SteelBack" type="L3BOOL">
	/// 
	/// ��ˮ����
	/// ARG&gt;&gt; rsSteelBackData :��ˮ������Ϣ,�������GUID\PreHeatID\Back_UnitID�����ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsSteelBackData" type="L3RECORDSET">��ˮ������Ϣ</Param>
	/// </Method>
	L3LONG SteelBack(L3RECORDSET rsSteelBackData);

	/// <Method class="CDispatch_Mag" name="SteelDivApp" type="L3BOOL">
	/// 
	/// ��ˮ¯�ηָ�����
	/// ARG&gt;&gt; 
	/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID�ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
	/// </Method>
	L3BOOL SteelDivApp(L3RECORDSET rsSteelDivAppData);

	/// <Method class="CDispatch_Mag" name="SteelDiv" type="L3BOOL">
	/// 
	/// ��ˮ�ָ�
	/// ARG&gt;&gt; strPreHeatID :Ԥ��¯��
	///        &gt;&gt; strBackUnit:   ���͹�λ
	///        &gt;&gt;strObjName:������
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="strPreHeatID" type="L3STRING">Ԥ��¯��</Param>
	/// <Param name="strBackUnit" type="L3STRING">���͹�λ</Param>
	/// <Param name="strObjName" type="L3STRING">Ԥ��¯��</Param>
	/// </Method>
	L3LONG SteelDiv(L3RECORDSET rsSteelDiv);

	/// <Method class="CDispatch_Mag" name="SteelExchangeApp" type="L3BOOL">
	/// 
	/// ��ˮ�ĸ�����
	/// ARG&gt;&gt; 
	/// &gt;&gt;rsSteelTurnData:��ˮ��¯��Ϣ,�������PreHeatID\SteelGradeIndex\HeatID\App_Time\App_Steel_Weight\App_Operator\App_Reason\App_UnitID�ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsSteelTurnData" type="L3RECORDSET">��ˮ��¯��Ϣ</Param>
	/// </Method>
	L3BOOL SteelExchangeApp(L3RECORDSET rsSteelExchangeAppData);

	/// <Method class="CDispatch_Mag" name="SteelExchange" type="L3BOOL">
	/// 
	/// ��ˮ�ĸ�
	/// ARG &gt;&gt; 
	///     &gt;&gt;rsExchangeData���ĸ����ݼ��������GUID\PreHeatID\Ex_SteelGradeIndex�����ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsExchangeData" type="L3RECORDSET">���ݼ�</Param>
	/// </Method>
	L3LONG SteelExchange(L3RECORDSET rsExchangeData);
	/// <Method class="CDispatch_Mag" name="DispatchLog" type="L3BOOL">
	/// 
	/// ���ȼ���
	/// ARG&gt;&gt; rsData:���ݼ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET">����</Param>
	/// </Method>
	L3BOOL DispatchLog(L3RECORDSET rsData);
	/// <Method class="CDispatch_Mag" name="GetBOFRealData" type="L3RECORDSET">
	/// 
	/// ��ȡת¯ʵʱ����
	/// ARG&gt;&gt;strBOFID:ת¯����
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetBOFRealData(L3STRING strBOFID);

	/// <Method class="CDispatch_Mag" name="GetBOFSideRealData" type="L3RECORDSET">
	/// 
	/// ��ȡ¯��ʵʱ����
	/// ARG&gt;&gt;strBOFID:ת¯����
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetBOFSideRealData(L3STRING strBOFID);


	/// <Method class="CDispatch_Mag" name="GetFactoryEnergyData" type="">
	/// </Method>
	L3RECORDSET GetFactoryEnergyData();
	
	/// <Method class="CDispatch_Mag" name="Get1LFRealData" type="">
	/// 
	/// ��ȡLF¯ʵʱ����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetLFRealData(L3STRING strLFID);
	
	/// <Method class="CDispatch_Mag" name="Get1RHRealData" type="">
	/// 
	/// ��ȡ1#RH¯ʵʱ����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetRHRealData(L3STRING strRHID);
	/// <Method class="CDispatch_Mag" name="Get1CasterRealData" type="">
	/// 
	/// ��ȡ1#����ʵʱ����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetCasterRealData(L3STRING strCasterID);

	/// <Method class="CDispatch_Mag" name="GetAlloyStoreData" type="">
	/// 
	/// ��ȡ�Ͻ�ԭ�Ͽ�����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetAlloyStoreData();
	/// <Method class="CDispatch_Mag" name="GetScrapStoreData" type="">
	/// 
	/// ��ȡ2#¯ʵʱ����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetScrapStoreData();
	/// <Method class="CDispatch_Mag" name="GetBloomStoreData" type="">
	/// 
	/// ��ȡ2#¯ʵʱ����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetBloomStoreData();
	/// <Method class="CDispatch_Mag" name="GetBulkStoreData" type="">
	/// 
	/// ��ȡ2#¯ʵʱ����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetBulkStoreData();
	/// <Method class="CDispatch_Mag" name="GetCurSteelBackInfor" type="DATASET">
	/// 
	/// ��ȡδ����ְ�����������Ϣ
	/// ARG 
	/// RET &gt;&gt; �ҵ��ĸְ�����������Ϣ��¼����
	/// </Method>
	L3RECORDSET GetCurSteelBackInfor();
	/// <Method class="CDispatch_Mag" name="GetCurSteelTurnInfor" type="DATASET">
	/// 
	/// ��ȡδ����ְ���¯������Ϣ
	/// ARG 
	/// RET &gt;&gt; �ҵ��ĸְ���¯������Ϣ��¼����
	/// </Method>
	L3RECORDSET GetCurSteelTurnInfor();
	/// <Method class="CDispatch_Mag" name="GetCurSteelDivInfor" type="DATASET">
	/// 
	/// ��ȡδ����ְ�¯�ηָ�������Ϣ
	/// ARG 
	/// RET &gt;&gt; �ҵ��ĸְ���¯¯�ηָ���Ϣ��¼����
	/// </Method>
	L3RECORDSET GetCurSteelDivInfor();
	/// <Method class="CDispatch_Mag" name="GetCurSteelExInfor" type="DATASET">
	/// 
	/// ��ȡδ����ĸ�������Ϣ
	/// ARG 
	/// RET &gt;&gt; �ҵ��ĸĸ������¼����
	/// </Method>
	L3RECORDSET GetCurSteelExInfor();

	/// <Method class="CDispatch_Mag" name="GetCurSteelCache" type="DATASET">
	/// 
	/// ��ȡ��ˮ��ǰ���ڻ���URi
	/// ARG csHeatID��¯��
	/// RET &gt;&gt; �ҵ���URi
	/// </Method>
	CString GetCurSteelCache(CString csHeatID);

	/// <Method class="CDispatch_Mag" name="SteelMoveInCache" type="L3LONG">
	/// 
	/// �ڹ��򻺴����ƶ���ˮ
	/// ARG&gt;&gt; csTappingPlanURi�����ּƻ�URI
	///  &gt;&gt; nUnitType��Ŀ�깤��
	///  &gt;&gt; csHeatID��¯��
	///  &gt;&gt; &csUnitID��Ŀ�����
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3LONG  SteelMoveInCache(CString csTappingPlanURi,L3LONG nUnitType,CString csHeatID,CString &csUnitID);


	/// <Method class="CDispatch_Mag" name="SteelAllReturn" type="L3LONG">
	/// 
	/// ��ˮȫ��¯
	/// ARG&gt;&gt; csTappingPlanURi�����ּƻ�URI
	///  &gt;&gt; csUnitID��ȫ��¯�������
	///  &gt;&gt; csHeatID��¯��
	/// RET &lt;&lt;����0�������
	/// </Method>
	L3LONG SteelAllReturn(CString csTappingPlanURi,CString csUnitID,CString csHeatID,L3DOUBLE fWeight);


	/// <Method class="CDispatch_Mag" name="MoveSteelFromCurCache" type="L3LONG">
	/// 
	/// ����ˮ�ӵ�ǰ��������ȥ
	/// ARG&gt;&gt; 
	///  &gt;&gt; csHeatID��¯��
	/// RET &lt;&lt;����0
	/// </Method>

	L3LONG MoveSteelFromCurCache(CString csHeatID);


	/// <Method class="CDispatch_Mag" name="SteelMoveInCache" type="L3LONG">
	/// 
	/// ����ˮ�ƶ���ָ���Ļ���ͬʱ���ļƻ���Ϣ
	/// ARG&gt;&gt; csTappingPlanURi�����ּƻ�URI
	///  &gt;&gt; nUnitType��Ŀ�깤��
	///  &gt;&gt; &csUnitID��Ŀ�����
	/// RET &lt;&lt;����0
	/// </Method>

	L3LONG AddSteelToSpeciCache(CString csTappingPlanURi,L3LONG nUnitType,CString csHeatID,CString &csUnitID);


	/// <Method class="CDispatch_Mag" name="GetDestination" type="L3RECORDSET">
	/// 
	/// ��ȡ������ȥ��
	/// ARG&gt;&gt;strBOFID:ת¯����
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3STRING GetDestination(L3STRING strUnitID,L3STRING strHeatID);

	//2009-04-09 Liao
	/// <Method class="CDispatch_Mag" name="AddDisExceptional" type="L3LONG">
	/// �����豸�쳣����Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET">��������Ϣ</Param>
	/// </Method>
	L3LONG AddDisExceptional(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="ModifyDisExceptional" type="L3LONG">
	/// �޸��豸�쳣����Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET">�޸ĵ�����Ϣ</Param>
	/// </Method>
	L3LONG ModifyDisExceptional(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="DeleteDisExceptional" type="L3LONG">
	/// ɾ���豸�쳣����Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET">ɾ��������Ϣ</Param>
	/// </Method>
	L3LONG DeleteDisExceptional(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="AddDisExceptionalItems" type="L3LONG">
	/// �����豸�쳣��ϸ��Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET">��������ϸ��Ϣ</Param>
	/// </Method>
	L3LONG AddDisExceptionalItems(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="ModifyDisExceptionalItems" type="L3LONG">
	/// �޸��豸�쳣��ϸ��Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET">�޸ĵ���ϸ��Ϣ</Param>
	/// </Method>
	L3LONG ModifyDisExceptionalItems(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="DelDisExceptionalItems" type="L3LONG">
	/// ɾ���豸�쳣��ϸ��Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET">ɾ������ϸ��Ϣ</Param>
	/// </Method>
	L3LONG DelDisExceptionalItems(L3RECORDSET dsInfo);
	/// <Method class="CDispatch_Mag" name="GetDispExceData" type="L3RECORDSET">
	/// ͨ�û�ȡ�豸�쳣����Ϣ
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET GetDispExceData(L3STRING strCondition);
	/// <Method class="CDispatch_Mag" name="GetDispExceItemData" type="L3RECORDSET">
	/// ͨ�û�ȡ�豸�쳣��ϸ��Ϣ
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET GetDispExceItemData(L3STRING strCondition);
};

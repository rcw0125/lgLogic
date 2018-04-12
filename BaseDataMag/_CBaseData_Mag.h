// �߼���BaseData_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBaseData_Mag :
	public CL3Object
{
public:
	CBaseData_Mag(void);
	virtual ~CBaseData_Mag(void);

	DECLARE_L3CLASS(CBaseData_Mag,XGMESLogic\\BaseDataMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBaseData_Mag)
	DECLARE_L3EVENTSINK_MAP()
	DECLARE_L3ACCESSCONTROL_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="BaseData_Mag" name="NC_Plan_Event" type="L3LONG">
	///NC�ƻ�ԤԼ����
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Plan_Event)////2009-02-21 tangyi


	/// <Property class="BaseData_Mag" name="NC_Plan_Event" type="L3LONG">
	///NC¯��ȷ��ԤԼ����
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Heat_Confirm_Event)////2009-02-22 tangyi

	/// <Property class="BaseData_Mag" name="NC_Plan_Event" type="L3LONG">
	///NC��ˮ����ԤԼ����
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Iron_Event)////2009-03-15 liuzhiqiang


	/// <Property class="BaseData_Mag" name="Steel_Back_Event" type="L3LONG">
	///��ˮ��¯ԤԼ����
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Steel_Back_Event)////2009-03-22 tangyi


	/// <Property class="BaseData_Mag" name="NC_Store_ChangeJudge_Event" type="L3LONG">
	///���ڸ���ԤԼ����
	/// </Property>
	DECLARE_L3PROP_LONG(NC_Store_Change_Event)////2009-03-22 tangyi


	/// <Method class="BaseData_Mag" name="ReceiveBaseData" type="">
	/// 
	/// ����NC����������Ϣ
	/// ARG&gt;&gt; rsData : �������ݣ��������DataType�ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// </Method>
	L3BOOL ReceiveBaseData();


	L3RECORDSET GetCodeAndDes(L3STRING csCodeGroup);

	L3STRING GetSysCurDate();


	
	/*/// <Method class="CBaseData_Mag" name="GetPlanInfor" type="L3LONG">
	/// 2009-02-21
	/// ��NC���������ƻ�����
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetPlanInfor();
	/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
	/// 2009-02-21
	/// NCȷ����������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmPlan(L3RECORDSET rsData);


	/// <Method class="CBaseData_Mag" name="GetQualityJudgeInfor" type="L3LONG">
	/// 2009-02-22
	/// ��NC����������������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetQualityJudgeInfor(L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2);


	/// <Method class="CBaseData_Mag" name="ConfirmQuality" type="L3LONG">
	/// 
	/// NCȷ����������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmQuality(L3RECORDSET rsData);

	
	/// <Method class="CBaseData_Mag" name="GetBloomInfor" type="L3LONG">
	/// 2009-02-22
	/// ��NC����������ɵ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetBloomInfor(L3RECORDSET *rsMainData);


	/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
	/// 
	/// NCȷ���������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmBloomInfor(L3RECORDSET rsData);


	/// <Method class="CBaseData_Mag" name="GetBOFAddMaterialsInfor" type="L3LONG">
	/// 2009-02-22
	/// ��NC�����������ϵ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetAddMaterialsInfor(L3RECORDSET *rsMainData);


	/// <Method class="CBloom_Store_Mag" name="BloomHotSend" type="L3LONG">
	/// 
	/// ��NC���͸���������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetBloomInStoreInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="ConfirmRHAddMaterials" type="L3LONG">
	/// 
	/// NCȷ�ϸ������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmBloomInStoreInfor(L3RECORDSET rsData);*/	

	/*/// NCȷ�Ϸ��ϳɹ����
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmAddMaterialInfor(L3RECORDSET rsData);*/	

	/*/// <Method class="CBaseData_Mag" name="GetIronQualityJudgeInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng
	/// ��NC������ˮ������������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetIronQualityJudgeInfor(L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2);

	/// <Method class="CBaseData_Mag" name="ConfirmIronQuality" type="L3LONG">
	/// 
	/// NCȷ����ˮ��������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmIronQuality(L3RECORDSET rsData);

	/// <Method class="CBaseData_Mag" name="GetIronBloomInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng
	/// ��NC������ˮ������ɵ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetIronBloomInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="ConfirmIronBloomInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng
	/// NCȷ����ˮ�������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmIronBloomInfor(L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="GetIronBloomInStoreInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng
	/// ��NC������ˮ������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetIronBloomInStoreInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="ConfirmIronBloomInStoreInfor" type="L3LONG">
	/// 2009-03-15 liuzhiqng 
	/// NCȷ����ˮ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmIronBloomInStoreInfor(L3RECORDSET rsData);*/


	/*/// <Method class="CBaseData_Mag" name="GetAllReturnMaterialsInfor" type="L3LONG">
	/// 2009-03-23 liuzhiqiang
	/// ��NC����ȫ��¯�������ϵ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetAllReturnMaterialsInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="GetAllReturnBloomInfor" type="L3LONG">
	/// 2009-03-23
	/// ��NC����ȫ��¯������ɵ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetAllReturnBloomInfor(L3RECORDSET *rsMainData);

	/// <Method class="CBloom_Store_Mag" name="GetAllBloomInStoreInfor" type="L3LONG">
	/// 
	/// ��NC����ȫ��¯������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetAllBloomInStoreInfor(L3RECORDSET *rsMainData);*/

	/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
	/// 
	/// �������ݵ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL BaseAllCodeInput();

	/// <Method class="CBaseData_Mag" name="ConfirmPlan" type="L3LONG">
	/// 
	/// ������������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3RECORDSET ModifySteelGrade(CString HeatID,CString CurSteelGradeIndex);
	
	/// <Method class="CBaseData_Mag" name="ConfirmIronBloomInStoreInfor" type="L3LONG">
	/// 
	///��NC���ո�������Ϣ
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0 2009-03-18
	/// </Method>
	L3BOOL ReceiveSteelmaterialInforFromNC(L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="WriteLogFromNC" type="L3LONG">
	/// 
	/// ���ݷ��͵ĵ��ļ�¼��־
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3BOOL WriteLogFromNC(L3RECORDSET rsData);


	/// <Method class="CBaseData_Mag" name="SendPlanInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// ��NC���������ƻ�����
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET SendPlanInfor(L3STRING strHeatID);

	/// <Method class="CBaseData_Mag" name="SendAddMaterialsInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// ��NC�����������ϵ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET SendAddMaterialsInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="GetBloomInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// ��NC����������ɵ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET SendBloomInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="SendQualityJudgeInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// ��NC����������������(strType:0��������;1:���ڸ���)
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET SendQualityJudgeInfor(L3STRING strHeatID,L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2,L3STRING strType);

	/// <Method class="CBloom_Store_Mag" name="SendBloomInStoreInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// ��NC��������������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET SendBloomInStoreInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="SendIronBloomInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// ��NC������ˮ������ɵ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET SendIronBloomInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);

	/// <Method class="CBaseData_Mag" name="SendIronQualityJudgeInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// ��NC������ˮ������������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET SendIronQualityJudgeInfor(L3STRING strHeatID,L3RECORDSET *rsMaterialsData1,L3RECORDSET *rsMaterialsData2);

	/// <Method class="CBloom_Store_Mag" name="SendIronBloomInStoreInfor" type="L3LONG">
	/// 2009-03-26 liuzhiqiang
	/// ��NC������ˮ������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET SendIronBloomInStoreInfor(L3STRING strHeatID,L3RECORDSET *rsMainData);


	//��ȡ���κ�2009-03-28
	L3RECORDSET GetMaterialBatchID(L3STRING strMaterialCode);

	/// <Method class="CBaseData_Mag" name="GetPlanOrder" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// ��NC���������ƻ�����
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetPlanOrder();

	/// <Method class="CBaseData_Mag" name="ConfirmPlanOrder" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// NCȷ����������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmPlanOrder(L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="GetInStore" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// ��NC���͸���������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetInStore();

	/// <Method class="CBaseData_Mag" name="ConfirmInStore" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// NCȷ�ϸ������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmInStore(L3RECORDSET rsData);

	/// <Method class="CBaseData_Mag" name="GetIron" type="L3LONG">
	/// 2009-03-30 liuzhiqiang
	/// ��NC������ˮ������������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetIron();

	/// <Method class="CBaseData_Mag" name="ConfirmIron" type="L3LONG">
	/// 
	/// NCȷ����ˮ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmIron(L3RECORDSET rsData);

	/// <Method class="CBaseData_Mag" name="GetIron" type="L3LONG">
	/// 2009-02-22
	/// ��NC���Ϳ���������������
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetInStoreQuality();


	/// <Method class="CBaseData_Mag" name="ConfirmIron" type="L3LONG">
	/// 
	/// NCȷ�Ͽ��ڸ���
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmInStoreQuality(L3RECORDSET rsData);

	/// <Method class="CBaseData_Mag" name="ConfirmIron" type="L3LONG">
	/// 
	/// ���Դ洢����
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL TestOracleProcess(L3STRING strHeatID);

	/// <Method class="CBloom_Store_Mag" name="GetInStore" type="L3LONG">
	/// 2009-04-04 liuzhiqiang
	/// ��NC����ȫ��¯����
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���NULL
	/// </Method>
	L3RECORDSET GetAllReturn();

	/// <Method class="CBaseData_Mag" name="ConfirmInStore" type="L3LONG">
	/// 2009-04-04 liuzhiqiang
	/// NCȷ��ȫ��¯
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ���0
	/// </Method>
	L3BOOL ConfirmAllReturn(L3RECORDSET rsData);

	//2009-04-17 Liao
	/// <Method class="CBaseData_Mag" name="Add_Mat_Price" type="L3LONG">
	/// ������ϼ۸����Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET">������Ϣ</Param>
	/// </Method>
	L3LONG Add_Mat_Price(L3RECORDSET dsInfo);
	/// <Method class="CBaseData_Mag" name="Modify_Mat_Price" type="L3LONG">
	/// �޸����ϼ۸����Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET">�޸���Ϣ</Param>
	/// </Method>
	L3LONG Modify_Mat_Price(L3RECORDSET dsInfo);
	/// <Method class="CBaseData_Mag" name="Delete_Mat_Price" type="L3LONG">
	/// ɾ�����ϼ۸����Ϣ
	/// <Param name="dsInfo" type="L3RECORDSET">ɾ����Ϣ</Param>
	/// </Method>
	L3LONG Delete_Mat_Price(L3RECORDSET dsInfo);
	/// <Method class="CBaseData_Mag" name="Get_Materia_Price" type="L3RECORDSET">
	/// ��ȡ���ϼ۸���Ϣ
	/// <Param name="strCondition" type="L3STRING">��ѯ����</Param>
	/// </Method>
	L3RECORDSET Get_Materia_Price(L3STRING strCondition);
	/// <Method class="CBaseData_Mag" name="InsertBaseParameter" type="L3LONG">
	/// �������ݵ�ָ���Ļ�����
	/// ARG >> strClassNameURI: ������
	///		   rsParam�� ���ݼ�
	/// RET << �ɹ�����1�����򷵻ط�1
	/// <Param name="strClassNam" type="L3STRING"></Param>
	/// <Param name="rsParam" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG InsertBaseParameter(L3STRING strClassNameURI, L3RECORDSET rsParam);
};

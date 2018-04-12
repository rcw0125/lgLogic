// �߼���CScrap_Store_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialStore.h"

class CScrap_Store_Mag :
	public MaterialStore
{
public:
	CScrap_Store_Mag(void);
	virtual ~CScrap_Store_Mag(void);

	DECLARE_L3CLASS(CScrap_Store_Mag,XGMESLogic\\ScrapStoreMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CScrap_Store_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:

	virtual double GetAmountTolerance() { return 0.02; };//2009-03-27

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

	/// <Method class="CScrap_Store_Mag" name="ScrapDataAccept" type="L3BOOL">
	/// 
	/// ����NC�ϸ�����,����input����,����ϱ�,���յ��ı�
	/// ARG&gt;&gt; rsScrapData:�ϸ�������Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ScrapDataAccept(L3RECORDSET rsScrapData);
	/// <Method class="CScrap_Store_Mag" name="ScrapInStore" type="L3VOID">
	/// 
	/// �ϸ����
	/// ARG&gt;&gt; rsInputInfo�ϸ�������Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL ScrapInStore(L3RECORDSET rsInputInfo);
	/// <Method class="CScrap_Store_Mag" name="ScrapOutStore" type="L3VOID">
	/// 
	/// �ϸֳ���
	/// ARG&gt;&gt; rsOutputInfo�ϸ�������Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID,Scrap_Slot_ID,Car_ID,Car_Type,Net_Weight,Gross_Weight,Tare_Weight�⼸���ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsOutputInfo" type="L3RECORDSET">������Ϣ��¼������MaterialType,MaterialID,Amount,AreaID���ֶΡ�</Param>
	/// </Method>
	L3BOOL ScrapOutStore(L3RECORDSET rsOutputInfo);
	/// <Method class="CScrap_Store_Mag" name="GetMaterialOnInputCache" type="L3CORDSET">
	/// 
	/// ��ȡ��⻺�����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetMaterialOnInputCache();

	/// <Method class="CAlloy_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
	/// 
	/// ��ȡ����������Ϣ
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetMaterialOnStore(L3STRING strStoreID);


	/// <Method class="CAlloy_Store_Mag" name="AlloyModifyAmount" type="L3BOOL">
	/// 
	/// ��������������
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.�������MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag �⼸���ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyMaterialAmount(L3RECORDSET rsData);

	/// <Method class="CScrap_Store_Mag" name="ScrapCancelOutStore" type="L3VOID">
	/// 
	/// �ϸֳ�������2009-02-26
	/// ARG&gt;&gt; rsOutputInfo�ϸ�������Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL ScrapCancelOutStore(L3RECORDSET rsOutputInfo);

	/// <Method class="CBOF_Unit_Mag" name="GetScrapesForDesignate" type="L3RECORDSET">
	/// ��ȡ��ѡ�ϸ���Ϣ��¼�����ش��зϸֲۺźͷϸ����ļ�¼����
	/// </Method>
	L3RECORDSET GetScrapes();

	/// <Method class="CScrap_Store_Mag" name="ScrapDataAccept" type="L3BOOL">
	/// 
	/// ����NC�ϸ�����,����input����,����ϱ�,���յ��ı�
	/// ARG&gt;&gt; rsScrapData:�ϸ�������Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ScrapDataAcceptFromNC(L3RECORDSET rsScrapData);

	/// <Method class="CScrap_Store_Mag" name="SaveScrapOutDetail" type="L3LONG">
	/// <Param name="rsScrap" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG SaveScrapOutDetail(L3RECORDSET rsScrap);
};

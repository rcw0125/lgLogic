// �߼���CBulk_Store_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialStore.h"

class CBulk_Store_Mag :
	public MaterialStore
{
public:
	CBulk_Store_Mag(void);
	virtual ~CBulk_Store_Mag(void);

	DECLARE_L3CLASS(CBulk_Store_Mag,XGMESLogic\\BulkStoreMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_Store_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:

	DECLARE_L3PROP_LONG(Bulk_Add_Material);

	virtual double GetAmountTolerance() { return 20; };

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

	/// <Method class="CBulk_Store_Mag" name="BulkDataAccept" type="L3BOOL">
	/// 
	/// ����NCɢ״������,����input����,����ϱ�,���յ��ı�
	/// ARG&gt;&gt; rsData:ɢ״����Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG BulkDataAccept(L3RECORDSET rsData);
	/// <Method class="CBulk_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
	/// 
	/// ��ȡ��⻺�����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetMaterialOnInputCache();
	/// <Method class="CBulk_Store_Mag" name="GetAreaIDByUnitID" type="L3STRING">
	/// 
	/// ͨ����λ��ȡ�ϲֱ���
	/// ARG&gt;&gt; strUnitID����λ
	/// RET &lt;&lt;�����ϲֱ���
	/// <Param name="strUnitID" type="L3STRING"></Param>
	/// </Method>
	L3STRING GetAreaIDByUnitID(L3STRING strUnitID);
	/// <Method class="CBulk_Store_Mag" name="BulkApp" type="L3BOOL">
	/// 
	/// ɢ״��Ҫ������
	/// ARG&gt;&gt; rsData:ɢ״����Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL BulkApp(L3RECORDSET rsData);
	/// <Method class="CBulk_Store_Mag" name="BulkAppConfirm" type="L3BOOL">
	/// 
	/// ɢ״��Ҫ������ȷ��
	/// ARG&gt;&gt; rsData:ɢ״����Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL BulkAppConfirm(L3RECORDSET rsData);
	/// <Method class="CBulk_Store_Mag" name="BulkInStore" type="L3BOOL">
	/// 
	/// ɢ״�����
	/// ARG&gt;&gt; rsInputInfoɢ״����Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
	/// &gt;&gt;strUnitID:����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
	/// <Param name="strUnitID" type="L3STRING"></Param>
	/// </Method>
	L3LONG BulkInStore(L3RECORDSET rsInputInfo);
	/// <Method class="CBulk_Store_Mag" name="GetBulkAppInfor" type="L3BOOL">
	/// 
	/// ��ȡδȷ��ɢ״��������Ϣ
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetBulkAppInfor(L3STRING strDate);
	/// <Method class="CBulk_Store_Mag" name="BulkAndAreaMap" type="L3BOOL">
	/// 
	/// �ϲ�����ά��
	/// ARG&gt;&gt; rsData:�ϲ�������Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL BulkAndAreaMap(L3RECORDSET rsData);


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

	//// <Method class="CAlloy_Store_Mag" name="AlloyInStore" type="L3LONG">
	//// 
	//// ת��
	//// ARG&gt;&gt; rsInputInfo��Ϣ.������� MaterialType,MaterialID,Amount,Position,TargetID�⼸���ֶΡ�
	//// &gt;&gt;strUnitID:����
	//// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	//// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
	//// <Param name="strUnitID" type="L3STRING"></Param>
	/////</Method>
	L3LONG BulkChangeStore(L3RECORDSET rsInputInfo);


	/// <Method class="CAlloy_Store_Mag" name="GetAllMaterialOnStore" type="L3RECORDSET">
	/// 
	/// ��ȡ���п���������Ϣ
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetAllMaterialOnStore(void);


	/// <Method class="CBulk_Store_Mag" name="GetBulkArea" type="L3RECORDSET">
	/// 
	/// ����ɢ״�ϱ����ȡ�ϲ�
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetBulkArea(L3STRING strBulkCode);

	/// <Method class="CBulk_Store_Mag" name="BulkDataAcceptFromNC" type="L3BOOL">
	/// 
	/// ����NC����,����input����,����ϱ�,���յ��ı�
	/// ARG&gt;&gt; rsScrapData:�ϸ�������Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsScrapData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG BulkDataAcceptFromNC(L3RECORDSET rsData);


	// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
	/// 
	/// ɢװ������ȡ��2009-04-05
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param> 
	/// </Method>
	L3LONG BulkInStoreCancel (L3RECORDSET rsData);

	// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
	/// 
	/// ɢװ��ת�Ͻ�2009-04-08
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param> 
	/// </Method>
	L3LONG BulkTransToAlloy (L3RECORDSET rsData);


};

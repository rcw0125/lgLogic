// �߼���CAlloy_Store_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialStore.h"
#include "MaterialType.h"



class CAlloy_Store_Mag :
	public MaterialStore
{
public:
	CAlloy_Store_Mag(void);
	virtual ~CAlloy_Store_Mag(void);

	DECLARE_L3CLASS(CAlloy_Store_Mag,XGMESLogic\\AlloyStoreMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_Store_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

protected:

	virtual double GetAmountTolerance() { return 20; };

	DECLARE_L3PROP_LONG(Alloy_Add_Material);

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

	/// <Method class="CAlloy_Store_Mag" name="AlloyDataAccept" type="L3BOOL">
	/// 
	/// ����NC�Ͻ�����,����input����,����ϱ�,���յ��ı�
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG AlloyDataAccept(L3RECORDSET rsData);
	/// <Method class="CAlloy_Store_Mag" name="GetMaterialOnInputCache" type="L3VOID">
	/// 
	/// ��ȡ��⻺�����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetMaterialOnInputCache();
	/// <Method class="CAlloy_Store_Mag" name="GetAreaIDByUnitID" type="L3STRING">
	/// 
	/// ͨ����λ��ȡ�ϲֱ���
	/// ARG&gt;&gt; strUnitID����λ
	/// RET &lt;&lt;�����ϲֱ���
	/// <Param name="strUnitID" type="L3STRING"></Param>
	/// </Method>
	L3STRING GetAreaIDByUnitID(L3STRING strUnitID);
	/// <Method class="CAlloy_Store_Mag" name="AlloyApp" type="L3BOOL">
	/// 
	/// �Ͻ�Ҫ������
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AlloyApp(L3RECORDSET rsData);
	/// <Method class="CAlloy_Store_Mag" name="AlloyAppConfirm" type="L3BOOL">
	/// 
	/// �Ͻ�Ҫ������
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AlloyAppConfirm(L3RECORDSET rsData);
	/// <Method class="CAlloy_Store_Mag" name="AlloyInStore" type="L3VOID">
	/// 
	/// �Ͻ����
	/// ARG&gt;&gt; rsInputInfo�Ͻ���Ϣ.�������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
	/// &gt;&gt;strUnitID:����
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
	/// <Param name="strUnitID" type="L3STRING"></Param>
	/// </Method>
	L3LONG AlloyInStore(L3RECORDSET rsInputInfo);
	/// <Method class="CAlloy_Store_Mag" name="GetAlloyAppInfor" type="L3RECORDSET">
	/// 
	/// ��ȡδȷ�ϺϽ�������Ϣ
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetAlloyAppInfor(L3STRING strDate);
	/// <Method class="CAlloy_Store_Mag" name="AlloyAndAreaMap" type="L3VOID">
	/// 
	/// �ϲ�����ά��
	/// ARG&gt;&gt; rsData:�ϲ�������Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AlloyAndAreaMap(L3RECORDSET rsData);


	/// <Method class="CAlloy_Store_Mag" name="ModifyMaterialAmountFuction" type="L3BOOL">
	/// 
	/// ��������������,�����������
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.�������MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag �⼸���ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyMaterialAmountFuction(L3RECORDSET rsData);


	/// <Method class="CAlloy_Store_Mag" name="ModifyMaterialAmount" type="L3BOOL">
	/// 
	/// ��������������
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.�������MaterialType, MaterialID, OldAmount, Amount,StoreAreaID,BalanceFlag �⼸���ֶ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyMaterialAmount(L3RECORDSET rsData);


	/// <Method class="CAlloy_Store_Mag" name="GetMaterialOnStore" type="L3RECORDSET">
	/// 
	/// ��ȡ����������Ϣ
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET  GetMaterialOnStore(L3STRING strStoreID);


	/// <Method class="CAlloy_Store_Mag" name="GetAllMaterialOnStore" type="L3RECORDSET">
	/// 
	/// ��ȡ���кϽ����������Ϣ
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetAllMaterialOnStore(void);

	//// <Method class="CAlloy_Store_Mag" name="AlloyInStore" type="L3LONG">
	//// 
	//// �Ͻ�ת��
	//// ARG&gt;&gt; rsInputInfo�Ͻ���Ϣ.������� Amount,Position,TargetID,Alloy_Code,Batch_ID�⼸���ֶΡ�
	//// &gt;&gt;strUnitID:����
	//// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	//// <Param name="rsInputInfo" type="L3RECORDSET"></Param>
	//// <Param name="strUnitID" type="L3STRING"></Param>
	/////</Method>
	L3LONG AlloyChangeStore(L3RECORDSET rsInputInfo);



	/// <Method class="CAlloy_Store_Mag" name="GetAlloyArea" type="L3RECORDSET">
	/// 
	/// ���ݺϽ�����ȡ�ϲ�
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetAlloyArea(L3STRING strAlloyCode);


	/// <Method class="CAlloy_Store_Mag" name="AlloyDataAccept" type="L3BOOL">
	/// 
	/// ����NC�Ͻ�ɷ���������ϱ�,���յ��ı�
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param> 
	/// </Method>
	L3LONG AlloyElementDataAccept(L3RECORDSET rsData);


	/// <Method class="CAlloy_Store_Mag" name="AlloyAndAreaMap" type="L3BOOL">
	/// 
	/// ��װɢ״�ϳ����ȡ��������ĸ�¯��
	/// ARG&gt;&gt; rsData:�ϲ�������Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3RECORDSET GetUnitClosedHeatID(L3STRING strUnitID);

	/// <Method class="CAlloy_Store_Mag" name="AlloyDataAccept" type="L3BOOL">
	/// 
	/// ����NC�Ͻ�ɷ���������ϱ�,���յ��ı�
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param> 
	/// </Method>
	L3LONG AlloyElementDataAcceptFormNC(L3RECORDSET rsData);

	// <Method class="CAlloy_Store_Mag" name="AlloyDataAccept" type="L3BOOL">
	/// 
	/// ����NC�Ͻ�����,����input����,����ϱ�,���յ��ı�
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param> 
	/// </Method>
	L3LONG AlloyDataAcceptFromNC (L3RECORDSET rsData);

	/// <Param name="rsData" type="L3RECORDSET"></Param>
	///�ϲ�����2009-03-27
	/// </Method>
	L3LONG ResetWeight (L3RECORDSET rsData);


	// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
	/// 
	/// ����NC�Ͻ���������,����input����,����ϱ�,���յ��ı�2009-04-05
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param> 
	/// </Method>
	L3LONG AlloyBackAcceptFromNC (L3RECORDSET rsData);


	// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
	/// 
	/// �Ͻ�����ȡ��2009-04-05
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param> 
	/// </Method>
	L3LONG AlloyInStoreCancel (L3RECORDSET rsData);

	// <Method class="CAlloy_Store_Mag" name="AlloyBackAcceptFromNC" type="L3BOOL">
	/// 
	/// �Ͻ�תɢװ��2009-04-08
	/// ARG&gt;&gt; rsData:�Ͻ���Ϣ.
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsData" type="L3RECORDSET"></Param> 
	/// </Method>
	L3LONG AlloyTransToBulk (L3RECORDSET rsData);

};

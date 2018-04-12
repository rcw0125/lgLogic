// �߼���CBloom_Store_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialStore.h"


class CBloom_Store_Mag :
	public MaterialStore
{
public:
	CBloom_Store_Mag(void);
	virtual ~CBloom_Store_Mag(void);

	DECLARE_L3CLASS(CBloom_Store_Mag,XGMESLogic\\BloomStoreMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Store_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();


	/// <Property class="CBloom_Store_Mag" name="BloomOffLineEvent" type="L3LONG">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_LONG(BloomOffLineEvent);

	/// <Property class="CBloom_Store_Mag" name="BloomInStore" type="L3LONG">
	/// �������NC�ӿ�ԤԼ����
	/// </Property>
	DECLARE_L3PROP_LONG(BloomInStore);

protected:

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

	/// <Method class="CBloom_Store_Mag" name="GetMaterialOnInputCache" type="L3RECORDSET">
	/// 
	/// ��ȡ��⻺�����
	/// ARG&gt;&gt; 
	/// RET &lt;&lt;�������ݼ�
	/// </Method>
	L3RECORDSET GetMaterialOnInputCache();
	/// <Method class="CBloom_Store_Mag" name="ChangeBloomPosition" type="L3BOOL">
	/// 
	/// ��λ���
	/// ARG&gt;&gt; rsBloom���������ݣ������µĶ�λ��Ϣ
	/// RET &lt;&lt;�ɹ�����True��ʧ�ܷ���False
	/// <Param name="rsBloom" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ChangeBloomPosition(L3RECORDSET rsBloom);
	/// <Method class="CBloom_Store_Mag" name="BloomColdSendInStore" type="L3BOOL">
	/// 
	/// ��һ��������⡣
	/// ARG &gt;&gt; rsInputInfo : ���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsInputInfo" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
	/// </Method>
	L3LONG BloomColdSendInStore(L3RECORDSET rsInputInfo);
	/// <Method class="CBloom_Store_Mag" name="BloomHotSend" type="L3LONG">
	/// 
	/// ��������
	/// ARG&gt;&gt; rsInputInfo : ���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ��س������
	/// <Param name="rsInputInfo" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
	/// </Method>
	L3LONG BloomHotSend(L3RECORDSET rsInputInfo);
	/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
	/// 
	/// ���ո������ͳ�����Ϣ
	/// ARG&gt;&gt; rsData : ���ϳ�����Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ��س������
	/// <Param name="rsData" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
	/// </Method>
	L3LONG AcceptBloomOutStoreInfor(L3RECORDSET rsData);
	/// <Method class="CBloom_Store_Mag" name="GetBloomOnStoreArea" type="L3RECORDSET">
	/// 
	/// ��ȡ��������
	/// ARG&gt;&gt; strArea:������
	/// RET &lt;&lt;�������ݼ�
	/// <Param name="strArea" type="L3STRING">��������</Param>
	/// </Method>
	L3RECORDSET GetBloomOnStoreArea(L3STRING strArea,L3STRING strHeatID);
	/// <Method class="CBloom_Store_Mag" name="BloomFinish" type="L3BOOL">
	/// 
	/// ���������������
	/// ARG &gt;&gt; rsHeatID: ����¯�š�
	/// RET &lt;&lt; �ɹ�����TRUE��ʧ�ܷ���FALSE��
	/// <Param name="rsHeat" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL BloomFinish(L3RECORDSET rsHeat);
	/// <Method class="CBloom_Store_Mag" name="GetWillFinishBloom" type="L3VOID">
	/// 
	/// ��ȡ��������������
	/// ARG&gt;&gt; strArea:������
	/// RET &lt;&lt;�������ݼ�
	/// <Param name="strArea" type="L3STRING">��������</Param>
	/// </Method>
	L3RECORDSET GetWillFinishBloom(L3STRING strArea,L3STRING strHeatID);


	/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
	/// 
	/// ���ո������ͳ�����Ϣ2009-03-08
	/// ARG&gt;&gt; rsData : ���ϳ�����Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID,Target�⼸���ֶΡ�
	/// RET &lt;&lt;�ɹ�����1��ʧ�ܷ��س������
	/// <Param name="rsData" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
	/// </Method>
	L3LONG AcceptBloomOutStoreInforFromNC (L3RECORDSET rsData);

	
	L3LONG CCMConfirmHeat(L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
	/// 
	/// ��������2009-04-02
	/// <Param name="rsData" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
	/// </Method>
	L3LONG BloomBack (L3RECORDSET rsData);

	/// <Method class="CBloom_Store_Mag" name="AcceptBloomOutStoreInfor" type="L3LONG">
	/// 
	/// ���ո��߲ĸ���������Ϣ2009-04-02
	/// <Param name="rsData" type="L3RECORDSET">���������Ϣ��¼�����������MaterialType, MaterialID, Amount, StoreAreaID�⼸���ֶΡ�</Param>
	/// </Method>
	L3LONG AcceptBloomBackInforFromNC (L3RECORDSET rsData);

};

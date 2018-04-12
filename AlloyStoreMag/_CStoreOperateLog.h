// �߼���CStoreOperateLogͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CStoreOperateLog :
	public CL3Object
{
public:
	CStoreOperateLog(void);
	virtual ~CStoreOperateLog(void);

	DECLARE_L3CLASS(CStoreOperateLog,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CStoreOperateLog)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CStoreOperateLog" name="StoreID" type="L3STRING">
	///�ϲ�ID
	/// </Property>
	DECLARE_L3PROP_STRING(StoreID)

	/// <Property class="CStoreOperateLog" name="BeforeMaterialID" type="L3STRING">
	///����ǰ���ϱ���
	/// </Property>
	DECLARE_L3PROP_STRING(BeforeMaterialID)

	/// <Property class="CStoreOperateLog" name="BeforMaterialName" type="L3STRING">
	///����ǰ��������
	/// </Property>
	DECLARE_L3PROP_STRING(BeforMaterialName)

	/// <Property class="CStoreOperateLog" name="OperateMode" type="L3STRING">
	///����ģʽ 0����� 1������ 2���̿� 3���ϲ����� 4������ά��
	/// </Property>
	DECLARE_L3PROP_STRING(OperateMode)

	/// <Property class="CStoreOperateLog" name="Operater" type="L3STRING">
	///����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operater)

	/// <Property class="CStoreOperateLog" name="OperatorTime" type="L3STRING">
	///����ʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(OperatorTime)

	/// <Property class="CStoreOperateLog" name="AfterMaterialID" type="L3STRING">
	///���������ϱ���
	/// </Property>
	DECLARE_L3PROP_STRING(AfterMaterialID)

	/// <Property class="CStoreOperateLog" name="AfterMaterialName" type="L3STRING">
	///��������������
	/// </Property>
	DECLARE_L3PROP_STRING(AfterMaterialName)

	/// <Property class="CStoreOperateLog" name="BeforeWeight" type="L3STRING">
	///����ǰ����
	/// </Property>
	DECLARE_L3PROP_STRING(BeforeWeight)

	/// <Property class="CStoreOperateLog" name="AfterWeight" type="L3STRING">
	///����������
	/// </Property>
	DECLARE_L3PROP_STRING(AfterWeight)

};

// �߼���Stock_Base_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Stock_Infor :
	public CL3Object
{
public:
	CBase_Stock_Infor(void);
	virtual ~CBase_Stock_Infor(void);

	DECLARE_L3CLASS(CBase_Stock_Infor,XGMESLogic\\BaseDataMag, Pk_Stock)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Stock_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="Stock_Base_Infor" name="Pk_Stock" type="L3STRING">
	/// �ֿ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Stock)

	/// <Property class="Stock_Base_Infor" name="Stock_Code" type="L3STRING">
	/// �ֿ����
	/// </Property>
	DECLARE_L3PROP_STRING(Stock_Code)

	/// <Property class="Stock_Base_Infor" name="Stock_Name" type="L3STRING">
	/// �ֿ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Stock_Name)


};

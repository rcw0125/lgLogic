// �߼���CBase_Cargo_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Cargo_Infor :
	public CL3Object
{
public:
	CBase_Cargo_Infor(void);
	virtual ~CBase_Cargo_Infor(void);

	DECLARE_L3CLASS(CBase_Cargo_Infor,XGMESLogic\\BaseDataMag, Pk_Cargo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Cargo_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Cargo_Infor" name="Pk_Cargo" type="L3STRING">
	/// ��λ����
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Cargo)

	/// <Property class="CBase_Cargo_Infor" name="Cargo_Code" type="L3STRING">
	/// ��λ����
	/// </Property>
	DECLARE_L3PROP_STRING(Cargo_Code)

	/// <Property class="CBase_Cargo_Infor" name="Carge_name" type="L3STRING">
	/// ��λ����
	/// </Property>
	DECLARE_L3PROP_STRING(Carge_name)

	/// <Property class="CBase_Cargo_Infor" name="Pk_Stock" type="L3STRING">
	/// �����ֿ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Stock)

};

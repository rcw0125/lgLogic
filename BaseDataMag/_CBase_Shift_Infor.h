// �߼���CBase_Shift_Inforͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBase_Shift_Infor :
	public CL3Object
{
public:
	CBase_Shift_Infor(void);
	virtual ~CBase_Shift_Infor(void);

	DECLARE_L3CLASS(CBase_Shift_Infor,XGMESLogic\\BaseDataMag, Pk_Shift)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBase_Shift_Infor)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBase_Shift_Infor" name="Pk_Shift" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Pk_Shift)

	/// <Property class="CBase_Shift_Infor" name="Shift_Code" type="L3STRING">
	/// ��α���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift_Code)

	/// <Property class="CBase_Shift_Infor" name="Shift_Name" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Shift_Name)

};

// �߼���CBOF_Remark_Typeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_Remark_Type :
	public CL3Object
{
public:
	CBOF_Remark_Type(void);
	virtual ~CBOF_Remark_Type(void);

	DECLARE_L3CLASS(CBOF_Remark_Type,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Remark_Type)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_Remark_Type" name="TypeID" type="L3SHORT">
	/// 
	/// ����
	/// (1:��ȫ
	///  2:�豸
	///  3:����
	///  4:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(TypeID)

	/// <Property class="CBOF_Remark_Type" name="TypeDes" type="L3STRING">
	/// 
	/// ����
	/// (1:��ȫ
	///  2:�豸
	///  3:����
	///  4:����)
	/// </Property>
	DECLARE_L3PROP_STRING(TypeDes)

};

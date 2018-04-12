// �߼���CVacTube_Baseͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CVacTube_Base :
	public CL3Object
{
public:
	CVacTube_Base(void);
	virtual ~CVacTube_Base(void);

	DECLARE_L3CLASS(CVacTube_Base,XGMESLogic\\VacTubeMag, VacTube_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Base)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Base" name="VacTube_Name" type="L3STRING">
	/// �۹�����
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Name)

	/// <Property class="CVacTube_Base" name="VacTube_ID" type="L3STRING">
	/// �۹ܱ��
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_ID)

	/// <Property class="CVacTube_Base" name="Status" type="L3STRING">
	/// ״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CVacTube_Base" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CVacTube_Base" name="Position" type="L3STRING">
	/// λ��
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CVacTube_Base" name="Build_ID" type="L3STRING">
	/// �������
	/// yymm+VacTube_ID+��λ����
	/// </Property>
	DECLARE_L3PROP_STRING(Build_ID)

	/// <Property class="CVacTube_Base" name="VacTube_Code" type="L3STRING">
	/// ��ղ۱��
	/// �ϲ��ۺ�+�²��ۺ�(11)
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Code)

	/// <Property class="CVacTube_Base" name="VacTube_Age" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(VacTube_Age)

	/// <Property class="CVacTube_Base" name="Install_ID" type="L3STRING">
	/// ��װ���
	/// yymm+VacTube_Code+��λ����
	/// </Property>
	DECLARE_L3PROP_STRING(Install_ID)

	/// <Property class="CVacTube_Base" name="Flag" type="L3LONG">
	/// ��ɱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Flag)

	/// <Property class="CVacTube_Base" name="Fire_Count" type="L3LONG">
	/// �濾����
	/// </Property>
	DECLARE_L3PROP_LONG(Fire_Count)

};

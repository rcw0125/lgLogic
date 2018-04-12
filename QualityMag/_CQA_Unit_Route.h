// �߼���CQA_Unit_Routeͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Unit_Route :
	public CL3Object
{
public:
	CQA_Unit_Route(void);
	virtual ~CQA_Unit_Route(void);

	DECLARE_L3CLASS(CQA_Unit_Route,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Unit_Route)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Unit_Route" name="Lev_Type" type="L3LONG">
	/// ���ȼ���
	/// </Property>
	DECLARE_L3PROP_LONG(Lev_Type)

	/// <Property class="CQA_Unit_Route" name="BOFID" type="L3STRING">
	/// ת¯��λ��
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CQA_Unit_Route" name="LFID" type="L3STRING">
	/// LF��λ��
	/// </Property>
	DECLARE_L3PROP_STRING(LFID)

	/// <Property class="CQA_Unit_Route" name="RHID" type="L3STRING">
	/// RH��λ��
	/// </Property>
	DECLARE_L3PROP_STRING(RHID)

	/// <Property class="CQA_Unit_Route" name="CasterID" type="L3STRING">
	/// ������λ
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

};

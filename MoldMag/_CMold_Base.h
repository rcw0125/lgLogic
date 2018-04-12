// �߼���CMold_Baseͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CMold_Base :
	public CL3Object
{
public:
	CMold_Base(void);
	virtual ~CMold_Base(void);

	DECLARE_L3CLASS(CMold_Base,XGMESLogic\\MoldMag, MoldID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Base)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CMold_Base" name="MoldID" type="L3STRING">
	/// �ᾧ�����
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CMold_Base" name="Break_Face_Mea" type="L3DOUBLE">
	/// ����ߴ�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Break_Face_Mea)

	/// <Property class="CMold_Base" name="Status" type="L3STRING">
	/// ״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CMold_Base" name="Cast_ID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CMold_Base" name="FlowID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(FlowID)

	/// <Property class="CMold_Base" name="Copper_Fac" type="L3STRING">
	/// ͭ��(��)����
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CMold_Base" name="Copper_ID" type="L3STRING">
	/// ͭ��(��)���
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_ID)

	/// <Property class="CMold_Base" name="InStallID" type="L3STRING">
	/// װ����
	/// </Property>
	DECLARE_L3PROP_STRING(InStallID)

	/// <Property class="CMold_Base" name="UnitID" type="L3STRING">
	/// �ᾧ��������λ
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

};

// �߼���CQA_Des_Stdͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Des_Std :
	public CL3Object
{
public:
	CQA_Des_Std(void);
	virtual ~CQA_Des_Std(void);

	DECLARE_L3CLASS(CQA_Des_Std,XGMESLogic\\QualityMag, Des_Proc_Mod)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Des_Std)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Des_Std" name="Des_Proc_Mod" type="L3SHORT">
	/// ������ģʽ��
	/// </Property>
	DECLARE_L3PROP_LONG(Des_Proc_Mod)

	/// <Property class="CQA_Des_Std" name="Valid_Date" type="L3DATETIME">
	/// ��Ч����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Valid_Date)

	/// <Property class="CQA_Des_Std" name="S" type="L3DOUBLE">
	/// ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CQA_Des_Std" name="Weight" type="L3DOUBLE">
	/// ��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

};

// �߼���CBOF_Proc_Stat_Defͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBOF_Proc_Stat_Def :
	public CL3Object
{
public:
	CBOF_Proc_Stat_Def(void);
	virtual ~CBOF_Proc_Stat_Def(void);

	DECLARE_L3CLASS(CBOF_Proc_Stat_Def,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Proc_Stat_Def)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBOF_Proc_Stat_Def" name="Status" type="L3SHORT">
	/// ״̬
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CBOF_Proc_Stat_Def" name="Descr" type="L3STRING">
	/// 
	/// ״̬(1:�ӷϸֶ���;
	///          2:����;
	///          3:����;
	///          4:���ֿ�ʼ;
	///          5:���ֽ���;
	///          6:������ʼ;
	///          7:��������;
	///          8:������ʼ;
	///          9:��������[�ȴ�])
	/// </Property>
	DECLARE_L3PROP_STRING(Descr)

};

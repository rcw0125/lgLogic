// �߼���CPlan_Cur_PreLotNoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CPlan_Cur_PreLotNo :
	public CL3Object
{
public:
	CPlan_Cur_PreLotNo(void);
	virtual ~CPlan_Cur_PreLotNo(void);

	DECLARE_L3CLASS(CPlan_Cur_PreLotNo,XGMESLogic\\PlanMag, CasterID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Cur_PreLotNo)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_Cur_PreLotNo" name="Cur_PreLotNo" type="L3STRING">
	/// ��ǰԤ�����κ�
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_PreLotNo)

	/// <Property class="CPlan_Cur_PreLotNo" name="CasterID" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

};

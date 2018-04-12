// �߼���CEquip_Unit_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CEquip_Unit_Mag :
	public CL3Object
{
public:
	CEquip_Unit_Mag(void);
	virtual ~CEquip_Unit_Mag(void);

	DECLARE_L3CLASS(CEquip_Unit_Mag,XGMESLogic\\EquipMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEquip_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Method class="CEquip_Unit_Mag" name="NewCalibration" type="L3LONG">
	/// ����У׼������Ϣ 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewCalibration(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="ModifyCalibration" type="L3LONG">
	/// �޸�У׼������Ϣ 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyCalibration(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="DeleteCalibration" type="L3LONG">
	/// ɾ��У׼������Ϣ 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteCalibration(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="NewCalibrationDetail" type="L3LONG">
	/// ����У׼��ϸ��Ϣ 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG NewCalibrationDetail(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="ModifyCalibrationDetail" type="L3LONG">
	/// �޸�У׼��ϸ��Ϣ 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG ModifyCalibrationDetail(L3RECORDSET rsData);

	/// <Method class="CEquip_Unit_Mag" name="DeleteCalibrationDetail" type="L3LONG">
	/// ɾ��У׼��ϸ��Ϣ 2009-04-06
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3LONG DeleteCalibrationDetail(L3RECORDSET rsData);

	/// <Method class="CBF_Iron_Mag" name="QueryCalibration" type="L3RECORDSET">
	/// ����ʱ��β�У׼��Ϣ
	/// <Param name="timeFrom" type="L3DATETIME">��ʼʱ��</Param>
	/// <Param name="timeTo" type="L3DATETIME">����ʱ��</Param>
	/// </Method>
	L3RECORDSET QueryCalibration(L3DATETIME timeFrom, L3DATETIME timeTo);

	/// <Method class="CBF_Iron_Mag" name="QueryCalibrationDetail" type="L3RECORDSET">
	/// ����LogID��У׼��ϸ��Ϣ
	/// <Param name="strLogID" type="L3STRING">��ʼʱ��</Param>
	/// </Method>
	L3RECORDSET QueryCalibrationDetail(L3STRING strLogID);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptCleaningData" type="L3BOOL">
	/// ����һ��������ȴ�������ݡ�
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptCleaningData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptRuntimeData" type="L3BOOL">
	/// ����һ�����������������ݡ�
	/// <Param name="rsData" type="L3RECORDSET">��������</Param>
	/// </Method>
	L3BOOL AcceptRuntimeData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptSupplyWaterData" type="L3BOOL">
	/// ����һ���������ղ�ˮ���ݡ�
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptSupplyWaterData(L3RECORDSET rsData);

	/// <Method class="CEnergy_Unit_Mag" name="AcceptSupplyWaterEndData" type="L3BOOL">
	/// ����һ���������ղ�ˮ�������ݡ�
	/// <Param name="rsData" type="L3RECORDSET"></Param>
	/// </Method>
	L3BOOL AcceptSupplyWaterEndData(L3RECORDSET rsData);
};

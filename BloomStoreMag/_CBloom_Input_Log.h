// �߼���CBloom_Input_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once
#include "MaterialInputLog.h"

class CBloom_Input_Log :
	public MaterialInputLog
{
public:
	CBloom_Input_Log(void);
	virtual ~CBloom_Input_Log(void);

	DECLARE_L3CLASS(CBloom_Input_Log,XGMESLogic\\BloomStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Input_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBloom_Input_Log" name="Bloom_Count" type="L3LONG">
	/// ����֦��
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CBloom_Input_Log" name="Waster_Count" type="L3DOUBLE">
	/// ˦�ϸ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count)

	/// <Property class="CBloom_Input_Log" name="Wrong_Count" type="L3LONG">
	/// ���ϸ����֦��
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count)

	/// <Property class="CBloom_Input_Log" name="Right_Count" type="L3LONG">
	/// �ϸ����֦��
	/// </Property>
	DECLARE_L3PROP_LONG(Right_Count)

	/// <Property class="CBloom_Input_Log" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CBloom_Input_Log" name="Cur_Section_ID" type="L3STRING">
	/// ��ǰ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Section_ID)

	/// <Property class="CBloom_Input_Log" name="Cur_Bay_ID" type="L3STRING">
	/// ��ǰ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Bay_ID)

	/// <Property class="CBloom_Input_Log" name="Cur_Pile_ID" type="L3STRING">
	/// ��ǰ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Pile_ID)

	/// <Property class="CBloom_Input_Log" name="Cur_Layer_ID" type="L3STRING">
	/// ��ǰ��
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Layer_ID)

	/// <Property class="CBloom_Input_Log" name="Cur_Seq_ID" type="L3LONG">
	/// ��ǰ˳��
	/// </Property>
	DECLARE_L3PROP_LONG(Cur_Seq_ID)

	///2009-02-23���������ֶ�
	/// <Property class="CBloom_Input_Log" name="Length" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CBloom_Input_Log" name="Width" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CBloom_Input_Log" name="Thickness" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CBloom_Input_Log" name="Cal_Weight" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cal_Weight)

	/// <Property class="CBloom_Input_Log" name="Right_Weight" type="L3DOUBLE">
	/// �ϸ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Right_Weight)

	/// <Property class="CBloom_Input_Log" name="Waster_Weight" type="L3DOUBLE">
	/// ˦��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight)

	/// <Property class="CBloom_Input_Log" name="Wrong_Weight" type="L3DOUBLE">
	/// ���ϸ�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight)

};

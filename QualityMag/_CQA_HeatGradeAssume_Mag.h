// �߼���CQA_HeatGradeAssume_Magͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

const int nDecideSteelGradeIndexFlag1 = 1;//�������ּǺŲ�����־(1���Ѿ�����ж�)
const int nUnitTypeID = 9;//�����ʶ(9�����վ���)
const int nProcessCount =0;//����λ�������
const int nDataLogMode = 1;//���ݲ�����ʽ(0���Զ����㣻1���ֹ�¼�룻)
const int DecideFinalFlag0 = 0;//��Ҫ���б�־(0������Ҫ��1����Ҫ��)
const int DecideFinalFlag1 = 1;//��Ҫ���б�־(0������Ҫ��1����Ҫ��)
const int RecommendFlag[2] = {0,1};//�Ƽ����ּǺű�־(0:��Heat�����Ƽ���1:��Slab�����Ƽ���)
const int SlabIDModificationFlag = 1;//�����ű����־��0��δ�����1���ѱ��
const int DecideSteelGradeIndexFlag = 0;//�������ּǺŲ�����־��0��δ�У�1���Ѿ�����ж�


/// <summary>
/// �������и�������
/// </summary>
enum FinalJudgeBloom
{
	HotChecked = 0,	// �Ѿ��ȼ�
	WaitJudge  = 2, // ����
	ColdCheck  = 3,	// ���
};


class CQA_HeatGradeAssume_Mag :
	public CL3Object
{
public:
	CQA_HeatGradeAssume_Mag(void);
	virtual ~CQA_HeatGradeAssume_Mag(void);

	DECLARE_L3CLASS(CQA_HeatGradeAssume_Mag,XGMESLogic\\QualityMag, Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_HeatGradeAssume_Mag)
	DECLARE_L3EVENTSINK_MAP()


	DECLARE_L3PROP_LONG (FinalJudgeEvent); //���������¼�2009-01-02

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_HeatGradeAssume_Mag" name="NewHeatAbnormalEvent" type="L3STRING">
	/// �µ�¯���쳣�����¼�
	/// </Property>
	DECLARE_L3PROP_STRING(NewHeatAbnormalEvent)

	/// <Method class="CQA_HeatGradeAssume_Mag" name="LogHeatExceptionData" type="L3SHORT">
	/// ��¼¯�ι����쳣
	/// <Param name="nUnitTypeID" type="L3SHORT">����</Param>
	/// <Param name="nUnitID" type="L3SHORT">��λID</Param>
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// <Param name="nProcessCount" type="L3SHORT">����λ�������</Param>
	/// <Param name="rsData" type="L3RECORDSET">
	/// �쳣���ݣ����������
	/// nUnitTypeID(�����ʶ)��nUnitID(��λID)��strHeatID�������ţ���nProcessCount������λ�����������ExceptCode���쳣���룩</Param>
	/// </Method>
	L3LONG LogHeatExceptionData(L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strHeatID, L3SHORT nProcessCount, L3RECORDSET rsData);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="HeatJudge" type="L3SHORT">
	/// �ж��������ּǺ�
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// <Param name="strSteelGradeIndex" type="L3STRING">���ּǺ�</Param>
	/// <Param name="rsData" type="L3RECORDSET">
	/// �����иּ�¼��,������
	/// HeatID��DecideSteelGradeIndex�ֶ�
	/// </Param>
	/// </Method>
	L3LONG HeatJudge(L3STRING strHeatID, L3STRING strSteelGradeIndex, L3RECORDSET rsData);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="LogQAOperateInfo" type="L3SHORT">
	/// 
	/// ��¼����������Ϣ
	/// 
    /// <Param name="rsData" type="L3RECORDSET">����¯�š���������ļ�¼��</Param>
	/// </Method>
	L3LONG LogQAOperateInfo( L3RECORDSET rsData);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="HeatFinalJudge" type="L3SHORT">
	/// 
	/// ¯������
	/// 
	/// 
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// <Param name="rsData" type="L3RECORDSET">¯�����м�¼��</Param>
	/// </Method>
	L3LONG HeatFinalJudge(L3STRING strHeatID, L3RECORDSET rsData,L3STRING strAppID);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetHeatGradeData" type="L3RECORDSET">
	/// ��ȡ¯��Ʒ���ж�����
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetHeatGradeData(L3STRING strHeatID);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetHeatProcessExceptData" type="L3RECORDSET">
	/// ��ȡ¯�ι����쳣����
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetHeatProcessExceptData(L3STRING strHeatID);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetHeatJudgeUnitInfo" type="">
	/// </Method>
	L3RECORDSET GetHeatJudgeUnitInfo();
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetUnJudgeHeatID" type="L3RECORDSET">
	/// 
	/// ��ȡ��Ҫ�иֵ�¯��
	/// ARG&gt;&gt; CCMID��������
	/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
	/// <Param name="CCMID" type="L3LONG">������</Param>
	/// </Method>
	L3RECORDSET GetUnJudgeHeatID(L3LONG CCMID);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetFinJudgeHeat" type="L3RECORDSET">
	/// 
	/// ��ȡ��Ҫ����¯��
	/// ARG&gt;&gt; strCasterID��������
	/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
	/// <Param name="strCasterID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetFinJudgeHeat(L3STRING strCasterID,L3STRING strCondition);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetSurfaceJudgeInfor" type="L3RECORDSET">
	/// 
	/// ����¯�Ż�ȡ�����ȼ���Ϣ
	/// ARG&gt;&gt; strHeatID��������
	/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
	/// <Param name="strCasterID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetSurfaceJudgeInfor(L3STRING strHeatID);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetSurfaceJudgeInfor" type="L3RECORDSET">
	/// 
	/// ����¯�Ż�ȡ�����ɷֱ�׼
	/// ARG&gt;&gt; strHeatID��������
	/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
	/// <Param name="strCasterID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetBloomStdEle(L3STRING strHeatID);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetBloomTerminalEle" type="L3RECORDSET">
	/// 
	/// ����¯�Ż�ȡ�����յ���
	/// ARG&gt;&gt; strHeatID��������
	/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
	/// <Param name="strCasterID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetBloomTerminalEle(L3STRING strHeatID);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetFinJudgeInfor" type="L3RECORDSET">
	/// 
	/// ����¯�Ż�ȡ����������Ϣ
	/// ARG&gt;&gt; strHeatID��������
	/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
	/// <Param name="strCasterID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetFinJudgeInfor(L3STRING strHeatID);

	/// <Method class="CQA_HeatGradeAssume_Mag" name="ModHeatGrade" type="L3SHORT">
	/// ������ǰ¯�εȼ�
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// <Param name="nProcessCount" type="L3SHORT">�ش������</Param>
	/// <Param name="nUnitTypeID" type="L3SHORT">����</Param>
	/// <Param name="rsData" type="L3RECORDSET">����¯�εȼ����쳣���롢���ô��롢���ȼ�</Param>
	/// </Method>
	L3LONG ModHeatGrade(L3STRING strHeatID, L3SHORT nProcessCount, L3SHORT nUnitTypeID, L3RECORDSET rsData);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="CreateQAHeatGradeData" type="L3SHORT">
	/// ������ʼ¯�εȼ�
	/// <Param name="strHeatID" type="L3STRING">������</Param>
	/// <Param name="strPresetHeatID" type="L3STRING">Ԥ��¯��</Param>
	/// <Param name="nUnitTypeID" type="L3SHORT">����</Param>
	/// <Param name="nUnitID" type="L3SHORT">��λ</Param>
	/// <Param name="strSteelGradeIndex" type="L3STRING">��ǰ��ҵ���ּǺ�</Param>
	/// </Method>
	L3LONG CreateQAHeatGradeData(L3STRING strHeatID, L3STRING strPresetHeatID, L3SHORT nUnitTypeID, L3SHORT nUnitID, L3STRING strSteelGradeIndex);


	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetRefineThirdEle" type="L3RECORDSET">
	/// 
	/// ����¯�Ż�ȡ���������γɷ�����
	/// ARG&gt;&gt; strHeatID��������
	/// RET &lt;&lt; �ɹ����ع��������ݼ���ʧ�ܷ���NULL��
	/// <Param name="strCasterID" type="L3STRING">������</Param>
	/// </Method>
	L3RECORDSET GetRefineThirdEle(L3STRING strHeatID);

	//Modify begin by llj 2011-03-26 ����ת¯��ˮֱ�Ͳ���ֲ��ߵĹ���·�������и�ˮ�����ж����ϴ�NC
	//��ˮ�����ж����ʱ�Զ���ɸ�ˮ������ϴ�NC
	/// <Method class="CQuality_Mag" name="BofSteelQualityJudge" type="L3LONG">
	/// ת¯��ˮֱ�Ͳ���������ж�
	/// <Param name="rsBofSteelInfo" type="L3RECORDSET">��ˮ��Ϣ</Param>
	/// </Method>
	L3LONG BofSteelQualityJudge(L3RECORDSET rsBofSteelInfo);
	/// <Method class="CQA_HeatGradeAssume_Mag" name="GetBofSteelJudgeHeat" type="L3RECORDSET">
	/// </Method>
	L3RECORDSET GetBofSteelJudgeHeat();
};

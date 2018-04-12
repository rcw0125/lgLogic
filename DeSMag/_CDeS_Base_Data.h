// �߼���CDeS_Base_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDeS_Base_Data :
	public CL3Object
{
public:
	CDeS_Base_Data(void);
	virtual ~CDeS_Base_Data(void);

	// ��ˮ״̬ö��
	enum _IronStatusEnum
	{
		ironPrepare = 1,			// ׼������
		ironArrived = 2,			// ���޽�վ
		ironBeginPreRemoveSlag = 3,	// Ԥ������ʼ
		ironEndPreRemoveSlag = 4,	// Ԥ��������
		ironBeginSpray = 5,			// �紵��ʼ
		ironEndSpray = 6,			// �紵����
		ironBeginRemoveSlag = 7,	// ������ʼ
		ironEndRemoveSlag = 8,	    // ��������
		ironDepart = 9,			    // ���޳�վ
		ironUsed = 10,			    // ��ˮ��ʹ��
		ironUndo = 11,			    // ��ˮ����
	};


	DECLARE_L3CLASS(CDeS_Base_Data,XGMESLogic\\DeSMag, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Base_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDeS_Base_Data" name="MaterialID" type="L3STRING">
	/// ���ϱ�ʶ
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID)

	/// <Property class="CDeS_Base_Data" name="TAP_No" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TAP_No)

	/// <Property class="CDeS_Base_Data" name="TPC_No" type="L3STRING">
	/// �޺�
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

	/// <Property class="CDeS_Base_Data" name="DeS_UnitID" type="L3STRING">
	/// ����λ
	/// </Property>
	DECLARE_L3PROP_STRING(DeS_UnitID)

	/// <Property class="CDeS_Base_Data" name="RemoveSlag_UnitID" type="L3STRING">
	/// ������λ
	/// </Property>
	DECLARE_L3PROP_STRING(RemoveSlag_UnitID)

	/// <Property class="CDeS_Base_Data" name="DeS_Operator" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(DeS_Operator)

	/// <Property class="CDeS_Base_Data" name="RemoveSlag_Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(RemoveSlag_Operator)

	/// <Property class="CDeS_Base_Data" name="DeS_Flag" type="L3LONG">
	/// �����־
	/// </Property>
	DECLARE_L3PROP_LONG(DeS_Flag)

	/// <Property class="CDeS_Base_Data" name="ProductionDate" type="L3DATETIME">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DATETIME(ProductionDate)

	/// <Property class="CDeS_Base_Data" name="PreRemoveSlagTime" type="L3LONG">
	/// Ԥ������ʱ
	/// </Property>
	DECLARE_L3PROP_LONG(PreRemoveSlagTime)

	/// <Property class="CDeS_Base_Data" name="RemoveSlagTime" type="L3LONG">
	/// ������ʱ
	/// </Property>
	DECLARE_L3PROP_LONG(RemoveSlagTime)

	/// <Property class="CDeS_Process_Data" name="BlowTimeTotal" type="L3LONG">
	/// �紵��ʱ
	/// </Property>
	DECLARE_L3PROP_LONG(BlowTimeTotal)

	/// <Property class="CDeS_Process_Data" name="ProcessTime" type="L3LONG">
	/// ��ҵʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessTime)

	/// <Property class="CDeS_Base_Data" name="RemoveSlagCount" type="L3LONG">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_LONG(RemoveSlagCount)

	/// <Property class="CDeS_Process_Data" name="Gross_Weight" type="L3DOUBLE">
	/// ë��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gross_Weight)

	/// <Property class="CDeS_Process_Data" name="Estimate_Weight" type="L3DOUBLE">
	/// ��ˮԤ������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Estimate_Weight)

	/// <Property class="CDeS_Process_Data" name="Net_Weight" type="L3DOUBLE">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Net_Weight)

	/// <Property class="CDeS_Base_Data" name="DeSType" type="L3SHORT">
	/// ��������
	/// (1:ǳ����
	///  2:��׼����
	///  3:������
	///  4:��������
	///  5:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(DeSType)

	/// <Property class="CDeS_Process_Data" name="Mat_Consume" type="L3DOUBLE">
	/// ����þ����
	/// (����紵֮��)
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mat_Consume)

	/// <Property class="CDeS_Process_Data" name="Weight_MatTank" type="L3DOUBLE">
	/// ���Ϲ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_MatTank)

	/// <Property class="CDeS_Process_Data" name="Weight_SprayTank" type="L3DOUBLE">
	/// �紵������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_SprayTank)

	/// <Property class="CDeS_Base_Data" name="Status" type="L3SHORT">
	/// ״̬
	/// (1:׼������;
	///  2:���޽�վ;
	///  3:Ԥ������ʼ;
	///  4:Ԥ��������;
	///  5:�紵��ʼ;
	///  6:�紵����;
	///  7:������ʼ;
	///  8:��������;
	///  9:���޳�վ;
	///  10:��ˮ��ʹ��
	///  11:��ˮ����)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CDeS_Process_Data" name="Destination" type="L3LONG">
	/// ȥ��
	/// (0:δָ��;
	///  1:����¯;
	///  2:����)
	/// </Property>
	DECLARE_L3PROP_LONG(Destination)

	/// <Property class="CDeS_Base_Data" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDeS_Base_Data" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDeS_Base_Data" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CDeS_Base_Data" name="Locked" type="L3SHORT">
	/// 
	/// ����־(0:δ����
	///                  1:����[���������ݱ��])
	/// </Property>
	DECLARE_L3PROP_SHORT(Locked)

	/// <Property class="CDeS_Base_Data" name="SampleApplyCout_B" type="L3SHORT">
	/// ����ǰ���������
	/// </Property>
	DECLARE_L3PROP_SHORT(SampleApplyCount_B)

	/// <Property class="CDeS_Base_Data" name="SampleApplyCout_A" type="L3SHORT">
	/// ��������������
	/// </Property>
	DECLARE_L3PROP_SHORT(SampleApplyCount_A)

	/// <Property class="CDeS_Base_Data" name="Mediator" type="L3STRING">
	/// Э����
	/// </Property>
	DECLARE_L3PROP_STRING(Mediator)

	/// <Property class="CDeS_Process_Data" name="TotalTime" type="L3LONG">
	/// ȫ����ʱ
	/// </Property>
	DECLARE_L3PROP_LONG(TotalTime)
};

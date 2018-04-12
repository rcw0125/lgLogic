// 逻辑类CMIF_Unit_Mag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProduceUnit.h"

class CMIF_Unit_Mag :
	public ProduceUnit
{
public:
	CMIF_Unit_Mag(void);
	virtual ~CMIF_Unit_Mag(void);

	DECLARE_L3CLASS(CMIF_Unit_Mag,XGMESLogic\\MIXFMag, MIFID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMIF_Unit_Mag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

protected:
	/// <summary>
	/// 返回机组的加工区域
	/// ARG << lstURIs : 接收所有加工区对象的URI
	/// </summary>
	virtual BOOL GetProduceAreas(CStringList& lstURIs);

	/// <summary>
	/// 得到机组前序材料缓冲区的URI
	/// </summary>
	virtual CString GetInputCache();

	/// <summary>
	/// 得到机组后继材料缓冲区的URI
	/// </summary>
	virtual CString GetOutputCache();

	/// <summary>
	/// 机组上料前预处理。在机组上料前调用，继承类可重载此方法进行预先数据准备和处理。
	/// ARG >> rsMaterialInfo : 材料信息记录集。
	/// RET << 返回TRUE继续上料；返回FALSE中断上料。
	/// </summary>
	virtual BOOL OnBeforeFeedMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 机组上料后续处理。在机组上料后调用，继承类可重载此方法进行额外处理。
	/// ARG >> rsMaterialInfo : 材料信息记录集。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMaterialsFeeded(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 返回机组上料记录的类型URI
	/// </summary>
	virtual CString GetFeedingLogType();

	/// <summary>
	/// 准备上料记录数据。继承类可重载此函数进行额外的数据处理。
	/// ARG >> rsFeedingLogs : 上料记录信息。
	/// RET << void
	/// </summary>
	virtual void PrepareFeedingLogs(L3RECORDSET rsFeedingLogs);

	/// <summary>
	/// 加工参数预处理。在调用加工区域的加工方法前调用，继承类可重载此函数对加工参数进行修改和配置。
	/// ARG >> lpcszArea : 加工区域的URI
	///		>> rsParameters : 加工参数记录集。
	/// RET << 返回TRUE继续加工；返回FALSE中断加工。
	/// </summary>
	virtual BOOL PrepareProcessParameters(LPCTSTR lpcszArea,L3RECORDSET rsParameters);

	/// <summary>
	/// 加工完成后续处理。在加工完成后调用，继承类可重载此函数进行额外逻辑处理
	/// ARG >> lpcszArea : 加工区域的URI
	///		>> nProcessType : 加工的类型。
	///		>> rsProducts : 加工产生的产品的信息记录。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterProcessCompleted(LPCTSTR lpcszArea,LONG nProcessType,L3RECORDSET rsProducts);

	/// <summary>
	/// 下线前预处理。在执行下线操作前调用，继承类可重载此函数进行预先的数据准备和处理。
	/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
	/// RET << 返回TRUE继续下线；返回FALSE中断下线。
	/// </summary>
	virtual BOOL OnBeforeDeliverMaterials(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 下线后续处理。在执行下线操作后调用，继承类可重载此函数进行额外处理。
	/// ARG >> rsMaterialInfo : 下线材料信息。包含MaterialType,MaterialID,Amount,Area字段。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterMaterialsDelivered(L3RECORDSET rsMaterialInfo);

	/// <summary>
	/// 返回机组产出记录的类型URI
	/// </summary>
	virtual CString GetDeliveryLogType();

	/// <summary>
	/// 准备下料记录数据。
	/// ARG >> rsDeliveryLog : 下料记录数据。
	/// RET <<void
	/// </summary>
	virtual void PrepareDeliveryLogs(L3RECORDSET rsDeliveryLog);

	/// <summary>
	/// 返回本机组的通讯器对象的URI
	/// </summary>
	virtual CString GetCommunicator();

	/// <summary>
	/// 准备计划数据，以便向机组下位系统发送。
	/// ARG >> lpcszPlanType : 计划类型。
	///		>> rsPlan : 计划数据。包括PlanID字段。
	///		<< rsSend : 接收准备好的计划发送数据。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL PreparePlanForSending(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsSend);

	/// <summary>
	/// 计划下达后续处理。在向下位系统发送计划后调用，继承类可重载此函数进行后续处理。
	/// ARG >> rsSend : 下发下位系统的计划数据。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterPlansSent(L3RECORDSET rsSend);

	/// <summary>
	/// 准备计划数据，以便通知机组下位系统取消计划。
	/// ARG >> lpcszPlanType : 计划类型。
	///		>> rsPlan : 计划数据。包括PlanID字段。
	///		<< rsSend : 接收准备好的计划取消数据。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL PreparePlanForCancel(LPCTSTR lpcszPlanType,L3RECORDSET rsPlan,L3RECORDSET* pprsCancel);

	/// <summary>
	/// 计划取消后续处理。在向下位系统发送取消计划后调用，继承类可重载此函数进行后续处理。
	/// ARG >> rsCancel : 下发下位系统的计划取消数据。
	/// RET << 成功返回TRUE；失败返回FALSE。
	/// </summary>
	virtual BOOL OnAfterPlansCanceled(L3RECORDSET rsCancel);

	/// <summary>
	/// 处理材料上线的事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleMaterialFeedingEvent(MatEnterArea *pEvt);
	/// <summary>
	/// 处理材料进入加工区域的事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleMaterialEnterAreaEvent(MatEnterArea *pEvt);
	/// <summary>
	/// 处理材料离开加工区域事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleMaterialLeaveAreaEvent(MatLeaveArea *pEvt);
	/// <summary>
	/// 处理材料生产完毕事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleMaterialProducedEvent(MatProduced *pEvt);
	/// <summary>
	/// 处理机组测量数据变更事件
	/// ARG >> pEvt : 事件对象
	/// RET << 返回TRUE表示已经成功处理。返回FALSE表示使用系统缺省处理方式。
	/// </summary>
	virtual BOOL HandleUnitMeasureChangedEvent(UnitMeasure *pEvt);

	/// <Property class="CMIF_Unit_Mag" name="MIFID" type="L3STRING">
	/// 混铁炉炉座号
	/// </Property>
	DECLARE_L3PROP_STRING(MIFID)

	/// <Property class="CMIF_Unit_Mag" name="Temp" type="L3LONG">
	/// 当前温度
	/// </Property>
	DECLARE_L3PROP_LONG(Temp)

	/// <Property class="CMIF_Unit_Mag" name="C" type="L3DOUBLE">
	/// C成份化验值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(C)

	/// <Property class="CMIF_Unit_Mag" name="Si" type="L3DOUBLE">
	/// Si成份化验值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si)

	/// <Property class="CMIF_Unit_Mag" name="Mn" type="L3DOUBLE">
	/// Mn成份化验值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mn)

	/// <Property class="CMIF_Unit_Mag" name="P" type="L3DOUBLE">
	/// P成份化验值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P)

	/// <Property class="CMIF_Unit_Mag" name="S" type="L3DOUBLE">
	/// S成份化验值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S)

	/// <Property class="CMIF_Unit_Mag" name="Ti" type="L3DOUBLE">
	/// Ti成份化验值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ti)

	//add by hyh 2012-04-10
	/// <Property class="CMIF_Unit_Mag" name="Sn" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sn)

	/// <Property class="CMIF_Unit_Mag" name="Sb" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sb)

	/// <Property class="CMIF_Unit_Mag" name="As" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(As)

	/// <Property class="CMIF_Unit_Mag" name="Pb" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pb)
	//end

	//////add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	/// <Property class="CMIF_Unit_Mag" name="Ni" type="L3DOUBLE">
	/// Ni
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ni)

	/// <Property class="CMIF_Unit_Mag" name="Mo" type="L3DOUBLE">
	/// Mo
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mo)

	/// <Property class="CMIF_Unit_Mag" name="Cu" type="L3DOUBLE">
	/// Cu
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cu)

	/// <Property class="CMIF_Unit_Mag" name="Cr" type="L3DOUBLE">
	/// Cr
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cr)

	/// <Property class="CMIF_Unit_Mag" name="B" type="L3DOUBLE">
	/// B
	/// </Property>
	DECLARE_L3PROP_DOUBLE(B)

	/// <Property class="CMIF_Unit_Mag" name="V" type="L3DOUBLE">
	/// V
	/// </Property>
	DECLARE_L3PROP_DOUBLE(V)

	/// <Property class="CMIF_Unit_Mag" name="Al" type="L3DOUBLE">
	/// Al
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al)

	/// <Property class="CMIF_Unit_Mag" name="Nb" type="L3DOUBLE">
	///Nb
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nb)

	/// <Property class="CMIF_Unit_Mag" name="Zn" type="L3DOUBLE">
	/// Zn
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Zn)

	/// <Property class="CMIF_Unit_Mag" name="W" type="L3DOUBLE">
	/// W
	/// </Property>
	DECLARE_L3PROP_DOUBLE(W)
	//////////////////end///////////////////

	
	/// <Property class="CMIF_Unit_Mag" name="C_Cal" type="L3DOUBLE">
	/// C成份计算值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(C_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Si_Cal" type="L3DOUBLE">
	/// Si成份计算值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Mn_Cal" type="L3DOUBLE">
	/// Mn成份计算值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mn_Cal)

	/// <Property class="CMIF_Unit_Mag" name="P_Cal" type="L3DOUBLE">
	/// P成份计算值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Cal)

	/// <Property class="CMIF_Unit_Mag" name="S_Cal" type="L3DOUBLE">
	/// S成份计算值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Ti_Cal" type="L3DOUBLE">
	/// Ti成份计算值
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ti_Cal)

	//add by hyh 2012-04-10
	/// <Property class="CMIF_Unit_Mag" name="Sn_Cal" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sn_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Sb_Cal" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sb_Cal)

	/// <Property class="CMIF_Unit_Mag" name="As_Cal" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(As_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Pb_Cal" type="L3DOUBLE">
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pb_Cal)

	//end


	//////add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	/// <Property class="CMIF_Unit_Mag" name="Ni_Cal" type="L3DOUBLE">
	/// Ni_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ni_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Mo_Cal" type="L3DOUBLE">
	/// Mo_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mo_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Cu_Cal" type="L3DOUBLE">
	/// Cu_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cu_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Cr_Cal" type="L3DOUBLE">
	/// Cr_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cr_Cal)

	/// <Property class="CMIF_Unit_Mag" name="B_Cal" type="L3DOUBLE">
	/// B_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(B_Cal)

	/// <Property class="CMIF_Unit_Mag" name="V_Cal" type="L3DOUBLE">
	/// V_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(V_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Al_Cal" type="L3DOUBLE">
	/// Al_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Nb_Cal" type="L3DOUBLE">
	///Nb_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nb_Cal)

	/// <Property class="CMIF_Unit_Mag" name="Zn_Cal" type="L3DOUBLE">
	/// Zn_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Zn_Cal)

	/// <Property class="CMIF_Unit_Mag" name="W_Cal" type="L3DOUBLE">
	/// W_Cal
	/// </Property>
	DECLARE_L3PROP_DOUBLE(W_Cal)
	//////////////////end///////////////////

	/// <Property class="CMIF_Unit_Mag" name="Weight" type="L3DOUBLE">
	/// 混铁炉存铁量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight)

	/// <Property class="CMIF_Unit_Mag" name="subCount" type="L3LONG">
	/// 预约计数
	/// </Property>
	DECLARE_L3PROP_LONG(subCount)

	/// <Property class="CMIF_Unit_Mag" name="Temp_Time" type="L3DATETIME">
	/// 测温时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Temp_Time)

	/// <Property class="CMIF_Unit_Mag" name="Tare_Weight" type="L3DOUBLE">
	/// 地磅过跨线称重重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tare_Weight)

	/// <Property class="CMIF_Unit_Mag" name="Tare_Weight_Time" type="L3DATETIME">
	///地磅过跨线称重时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tare_Weight_Time)

	/// <Property class="CMIF_Unit_Mag" name="Gross_Weight" type="L3DOUBLE">
	/// 地磅铁水重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gross_Weight)

	/// <Property class="CMIF_Unit_Mag" name="Gross_Weight_Time" type="L3DATETIME">
	/// 地磅铁水称重时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Gross_Weight_Time)

	/// <Method class="CMIF_Unit_Mag" name="CalculateChemicalData" type="L3VOID">
	/// <Param name="rsIron" type="L3RECORDSET">铁水罐数据</Param>
	/// </Method>
	L3VOID CalculateChemicalData(L3RECORDSET rsIron);
	/// <Method class="CMIF_Unit_Mag" name="SampleChemcialData" type="L3LONG">
	/// 混铁炉来样处理函数
	/// <Param name="rsChemical" type="L3RECORDSET">成份数据</Param>
	/// </Method>
	L3LONG SampleChemcialData(L3RECORDSET rsChemical);
	/// <Method class="CMIF_Unit_Mag" name="MixIrons" type="L3LONG">
	/// 将某些铁水混入混铁炉
	/// <Param name="rsIrons" type="L3RECORDSET">混入混铁炉的铁水记录</Param>
	/// </Method>
	L3LONG MixIrons(L3RECORDSET rsIrons);
	/// <Method class="CMIF_Unit_Mag" name="OutputIron" type="L3BOOL">
	/// 向目标铁包出铁
	/// <Param name="LadleID" type="L3STRING">目标铁包号</Param>
	/// <Param name="fWeight" type="L3DOUBLE">出铁重量</Param>
	/// <Param name="fReHeatWeight" type="L3DOUBLE">回炉钢重量</Param>
	/// </Method>
	L3BOOL OutputIron(L3STRING LadleID, L3DOUBLE fWeight,L3DOUBLE fReHeatWeight,L3STRING Destination);

	/// <Method class="CMIF_Unit_Mag" name="AcceptIronLadleWeightData" type="L3BOOL">
	/// 接收混铁炉称重数据 2009-01-04
	/// <Param name="rsData" type="L3RECORDSET">混铁炉重量数据</Param>
	/// </Method>
	L3BOOL AcceptIronLadleWeightData(L3RECORDSET rsData);

	/// <Method class="CMIF_Unit_Mag" name="AcceptTemperatureData" type="L3BOOL">
	/// 接收混铁炉测温数据 2009-01-04
	/// <Param name="rsData" type="L3RECORDSET">混铁炉测温数据</Param>
	/// </Method>
	L3BOOL AcceptTemperatureData(L3RECORDSET rsData);

	/// <Method class="CMIF_Unit_Mag" name="AcceptDirectIronWeightData" type="L3BOOL">
	/// 接收混铁炉过跨线铁包称重数据 2009-01-04
	/// <Param name="rsData" type="L3RECORDSET">过跨线铁包重量数据</Param>
	/// </Method>
	L3BOOL AcceptDirectIronWeightData(L3RECORDSET rsData);



	/// <Method class="CMIF_Unit_Mag" name="OutputIronCancel" type="L3BOOL">
	/// 取消混铁炉出铁2009-03-11
	/// </Method>
	L3LONG OutputIronCancel(L3RECORDSET rsLadleID);

	L3LONG OutputIronCancelToDEP(L3RECORDSET rsLadleID);



};

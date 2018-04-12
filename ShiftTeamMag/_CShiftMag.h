// 逻辑类ShiftMag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CShiftMag :
	public CL3Object
{
public:
	CShiftMag(void);
	virtual ~CShiftMag(void);

	DECLARE_L3CLASS(CShiftMag,XGMESLogic\\ShiftTeamMag, L3Name)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(ShiftMag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	DECLARE_L3PROP_STRING(L3Name)				//主键
	////自动换班
	//L3BOOL AutoModifyProcessShift(L3STRING str);
	L3BOOL AutoModifyProcessShift();
	////得到班次班组顺序
	L3RECORDSET GetShiftTeamOrder();
	//提交班次班组顺序
	L3BOOL CommitShiftTeamOrder(L3RECORDSET rs);
	//删除班次班组顺序
	L3BOOL DeleteShiftTeamOrder();
	////得到工序时间
	L3RECORDSET GetUnitTime();
	//提交工序时间
	L3BOOL CommitUnitTime(L3RECORDSET rs);
	//删除最后一条工序时间
	L3BOOL DeleteUnitTime();
	////得到工序操作工
	L3RECORDSET GetUnitOperator();
	//提交工序操作工
	L3BOOL CommitUnitOperator(L3RECORDSET rs);
	//删除最后一条工序操作工
	L3BOOL DeleteUnitOperator();
	//得到班次班别
	L3RECORDSET GetShiftTeamID(L3STRING str);
	//得到当前班次班别，自己维护前台调用
	L3RECORDSET GetCurrentShiftTeamID(L3SHORT shortTemp);
	//后台得到当前班次班别
	L3RECORDSET GetSessionShiftTeam();
	//设置警告值
	L3BOOL AutoWarning();


};

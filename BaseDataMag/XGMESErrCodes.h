#pragma once

// 邢钢MES错误代码定义

// 工序错误代码
#define XGMES_ERR_IRONINUSE				0xF0001001		// 铁水在使用，不能修改或删除
#define XGMES_ERR_IRONWRONGDEST			0xF0001002		// 铁水去向错误。

#define XGMES_ERR_BOFREFUSED			0xF0002001		// 转炉操作被拒绝。通常是由于状态不符。
#define XGMES_ERR_BOFNEEDIRONS			0xF0002002		// 转炉需要指定铁水
#define XGMES_ERR_BOFNEEDSCRAPES		0xF0002003		// 转炉需要指定废钢生铁斗

#define XGMES_ERR_TAPREFUSED			0xF0003001		// 炉后操作被拒绝。通常是由于状态不符。

#define XGMES_ERR_LF_NEEDWEIGHTSTEEL	0xF0004001		// 需要为LF炉指定称重的钢包
#define XGMES_ERR_LF_NEEDSTEEL			0xF0004002		// 需要为LF炉指定到站钢包
#define XGMES_ERR_LF_AREANOTEMPTY		0xF0004003		// LF炉加工位置不空，已经被占用
#define XGMES_ERR_LF_WRONGSTATUS		0xF0004004		// LF炉状态不正确，无法进行当前操作

#define XGMES_ERR_RH_WRONGSTATUS		0xF0005001		// RH炉状态不正确，无法进行当前操作
#define XGMES_ERR_RH_NEEDSTEEL			0xF0005002		// 需要为RH炉指定到站钢包
#define XGMES_ERR_RH_AREANOTEMPTY		0xF0005003		// RH炉加工位置不空，已经被占用

#define XGMES_ERR_CCM_WRONGSTATUS		0xF0006001		// 铸机状态不正确，无法进行当前操作
#define XGMES_ERR_CCM_NEEDSTEEL			0xF0006002		// 未指定上线的钢水或钢水不在入口区
#define XGMES_ERR_CCM_TOOMUCHSTEELS		0xF0006003		// 工位上已经存在钢水，不能移入其他钢水
#define XGMES_ERR_CCM_NEEDTUNDISH		0xF0006004		// 没有可用的中包

// 计划错误代码
#define XGMES_ERR_PLANNOTEXIST			0xF0011001		// 计划不存在
#define XGMES_ERR_PLANWRONGREFINETYPE	0xF0011002		// 计划的精炼类型错误

// 质量错误代码
#define XGMES_ERR_SHEETSEND				0xF0009001		// 委托单已传送，不能修改或删除
#define XGMES_ERR_SHEETUNBACK			0xF0009002	// 委托单未回退，不能修改或删除

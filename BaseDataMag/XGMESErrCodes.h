#pragma once

// �ϸ�MES������붨��

// ����������
#define XGMES_ERR_IRONINUSE				0xF0001001		// ��ˮ��ʹ�ã������޸Ļ�ɾ��
#define XGMES_ERR_IRONWRONGDEST			0xF0001002		// ��ˮȥ�����

#define XGMES_ERR_BOFREFUSED			0xF0002001		// ת¯�������ܾ���ͨ��������״̬������
#define XGMES_ERR_BOFNEEDIRONS			0xF0002002		// ת¯��Ҫָ����ˮ
#define XGMES_ERR_BOFNEEDSCRAPES		0xF0002003		// ת¯��Ҫָ���ϸ�������

#define XGMES_ERR_TAPREFUSED			0xF0003001		// ¯��������ܾ���ͨ��������״̬������

#define XGMES_ERR_LF_NEEDWEIGHTSTEEL	0xF0004001		// ��ҪΪLF¯ָ�����صĸְ�
#define XGMES_ERR_LF_NEEDSTEEL			0xF0004002		// ��ҪΪLF¯ָ����վ�ְ�
#define XGMES_ERR_LF_AREANOTEMPTY		0xF0004003		// LF¯�ӹ�λ�ò��գ��Ѿ���ռ��
#define XGMES_ERR_LF_WRONGSTATUS		0xF0004004		// LF¯״̬����ȷ���޷����е�ǰ����

#define XGMES_ERR_RH_WRONGSTATUS		0xF0005001		// RH¯״̬����ȷ���޷����е�ǰ����
#define XGMES_ERR_RH_NEEDSTEEL			0xF0005002		// ��ҪΪRH¯ָ����վ�ְ�
#define XGMES_ERR_RH_AREANOTEMPTY		0xF0005003		// RH¯�ӹ�λ�ò��գ��Ѿ���ռ��

#define XGMES_ERR_CCM_WRONGSTATUS		0xF0006001		// ����״̬����ȷ���޷����е�ǰ����
#define XGMES_ERR_CCM_NEEDSTEEL			0xF0006002		// δָ�����ߵĸ�ˮ���ˮ���������
#define XGMES_ERR_CCM_TOOMUCHSTEELS		0xF0006003		// ��λ���Ѿ����ڸ�ˮ����������������ˮ
#define XGMES_ERR_CCM_NEEDTUNDISH		0xF0006004		// û�п��õ��а�

// �ƻ��������
#define XGMES_ERR_PLANNOTEXIST			0xF0011001		// �ƻ�������
#define XGMES_ERR_PLANWRONGREFINETYPE	0xF0011002		// �ƻ��ľ������ʹ���

// �����������
#define XGMES_ERR_SHEETSEND				0xF0009001		// ί�е��Ѵ��ͣ������޸Ļ�ɾ��
#define XGMES_ERR_SHEETUNBACK			0xF0009002	// ί�е�δ���ˣ������޸Ļ�ɾ��

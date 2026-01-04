#ifndef _APCFG_H_
#define _APCFG_H_
#include "wifi_manager.h"

/** wifi功能和ap配网功能初始化
 * @param wifi_state_callback wifi连接状态回调函数
 * @param wifi_no_info_callback wifi无保存信息回调函数
 * @return 无 
*/
void ap_wifi_init(p_wifi_state_callback wifi_state_callback, p_wifi_no_info_callback wifi_no_info_callback);

/** 连接某个热点
 * @param ssid
 * @param password
 * @return 无 
*/
void ap_wifi_set(const char* ssid,const char* password);

/** 启动配网模式
 * @param enable 暂无用，强制true
 * @return 无 
*/
void ap_wifi_apcfg(bool enable);

#endif

#ifndef WULIANSDK_H
#define WULIANSDK_H
#ifdef __cplusplus
extern "C" {
#endif

typedef void (*SDKOnline)();
typedef void (*SDKOffline)();
typedef void (*ZigbeeSetupData)(const char *chData);
typedef void (*DeviceOnline)(const char *chDeviceID, const char *chDeviceType, const char *chData);
typedef void (*DeviceOffline)(const char *chDeviceID);
typedef void (*DeviceLeft)(const char *chDeviceID);
typedef void (*DeviceData)(const char *chDeviceID, const char *chData);
typedef void (*DeviceSetupData)(const char *chDeviceID, const char *chData);
typedef void (*DeviceAlarmData)(const char *chDeviceID, const char *chData);
typedef void (*LogMessage)(const char *chMsg);

extern void RegisterCallBack(SDKOnline pfungatewayonline,
        SDKOffline pfungatewayoffline,
        ZigbeeSetupData pfunzigbeedata,
        DeviceOnline pfundeviceonline,
        DeviceOffline pfundeviceoffline,
        DeviceLeft pfundeviceleft,
        DeviceData pfundevicedata,
        DeviceSetupData pfundevicesetupdata,
        DeviceAlarmData pfundevicealarmdata,
        LogMessage pfunlogmessage);
extern void UnRegisterCallBack();
extern int BuildNetwork();
extern int EnableJoinGateway();
extern int DisableJoinGateway();
extern int ControlDevice(const char *chDeviceID, const char *chCmd);
extern int FindDevice(const char *chDeviceID, int itimes);
extern int GetDeviceSignal(const char *chDeviceID);
extern int DeleteDevice(const char *chDeviceID);
extern int ResetZigbee();
extern const char *GetSdkVersion();

//返回-1 表示sdk未准备好
extern int SyncAllDevOnlineStatus();
extern int SyncOneDevOnlineStatus(const char *chDeviceID);

extern void WulianSDK_Start();

#ifdef __cplusplus
}
#endif
#endif // WULIANSDK_H

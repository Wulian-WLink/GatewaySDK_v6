#include "../include/WulianSDK.h"

#include <iostream>
#include <unistd.h>

void MySDKOnline()
{
    std::cout << __FUNCTION__ << std::endl;
}

void MySDKOffline()
{
    std::cout << __FUNCTION__ << std::endl;
}

void MyZigbeeSetupData(const char *chData)
{
    std::cout << __FUNCTION__ << "::" << chData << std::endl;
}

void MyDeviceOnline(const char *chDeviceID, const char *chDeviceType, const char *chData)
{
    std::cout << __FUNCTION__ << "::" << chDeviceID << "::";
    std::cout << chDeviceType << "::" << chData << std::endl;
}

void MyDeviceOffline(const char *chDeviceID)
{
    std::cout << __FUNCTION__ << "::" << chDeviceID << std::endl;
}

void MyDeviceLeft(const char *chDeviceID)
{
    std::cout << __FUNCTION__ << "::" << chDeviceID << std::endl;
}

void MyDeviceData(const char *chDeviceID, const char *chData)
{
    std::cout << __FUNCTION__ << "::" << chDeviceID;
    std::cout << "::" << chData << std::endl;
}

void MyDeviceSetupData(const char *chDeviceID, const char *chData)
{
    std::cout << __FUNCTION__ << "::" << chDeviceID;
    std::cout << "::" << chData << std::endl;
}

void MyDeviceAlarmData(const char *chDeviceID, const char *chData)
{
    std::cout << __FUNCTION__ << "::" << chDeviceID;
    std::cout << "::" << chData << std::endl;
}

void MyLogMessage(const char *chMsg)
{
    std::cout << __FUNCTION__ << "::" << chMsg << std::endl;
}

int main(int argc, char *argv[])
{
    RegisterCallBack(MySDKOnline, MySDKOffline,
                      MyZigbeeSetupData, MyDeviceOnline,
                      MyDeviceOffline, MyDeviceLeft,
                      MyDeviceData,
                      MyDeviceSetupData, MyDeviceAlarmData,
                      MyLogMessage);
    WulianSDK_Start();
    while (SyncAllDevOnlineStatus() == -1) {
        std::cout << "test sync" << std::endl;
        sleep(1);
    }
    while (true) {
        sleep(1);
    }
}

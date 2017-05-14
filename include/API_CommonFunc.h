#ifndef _API_COMMONFUNC_H
#define _API_COMMONFUNC_H
#include <string>
#ifdef __cplusplus
extern "C" {
#endif
extern int API_GenerateRandom(int seed);
extern std::string API_GetGwid();
extern std::string API_GwIpAddrInit();
extern std::string API_GetFileContent(std::string filename, int line);
extern std::string API_GenerateRandStr(int numbers);
extern std::string API_GetBoardName();
extern std::string API_HexToAscii(const std::string &str, char *outstr);
extern std::string API_ExecSystemCmd(const std::string &cmd);
extern void API_SignalInit();
extern int API_ZigbeeCmd_CUU(char *pRetCmd, char pSign, char *pShordAddr,char *pData);
extern std::string API_GetDevType(const std::string &pData);
extern std::string API_ReadStrByOpt(std::string filename, std::string config, std::string option);
#ifdef __cplusplus
}
#endif

#endif

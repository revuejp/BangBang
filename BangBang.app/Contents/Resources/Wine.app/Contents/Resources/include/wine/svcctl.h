/*** Autogenerated by WIDL 1.4.1 from wine/svcctl.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __svcctl_h__
#define __svcctl_h__

/* Forward declarations */

/* Headers for imported files */

#include <wtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#include "winsvc.h"
#define SVCCTL_TRANSPORT {'n','c','a','c','n','_','n','p',0}
#define SVCCTL_ENDPOINT {'\\','p','i','p','e','\\','s','v','c','c','t','l',0}
#define SVCCTL_STARTED_EVENT {'_','_','w','i','n','e','_','S','v','c','c','t','l','S','t','a','r','t','e','d',0}
enum service_pipe_command {
    WINESERV_STARTINFO = 1,
    WINESERV_SENDCONTROL = 2
};

typedef struct service_start_info_t {
    enum service_pipe_command cmd;
    DWORD total_size;
    DWORD name_size;
    DWORD control;
    WCHAR data[1];
} service_start_info;
/*****************************************************************************
 * svcctl interface (v2.0)
 */
#ifndef __svcctl_INTERFACE_DEFINED__
#define __svcctl_INTERFACE_DEFINED__

extern RPC_IF_HANDLE svcctl_v2_0_c_ifspec;
extern RPC_IF_HANDLE svcctl_v2_0_s_ifspec;
typedef LPCWSTR MACHINE_HANDLEW;
typedef void *SC_RPC_HANDLE;
typedef void *SC_RPC_LOCK;
#define SERVICE_SET_STATUS   0x8000
#if 0 /* already defined in winsvc.h */
typedef struct _QUERY_SERVICE_CONFIGW {
    DWORD dwServiceType;
    DWORD dwStartType;
    DWORD dwErrorControl;
    LPWSTR lpBinaryPathName;
    LPWSTR lpLoadOrderGroup;
    DWORD dwTagId;
    LPWSTR lpDependencies;
    LPWSTR lpServiceStartName;
    LPWSTR lpDisplayName;
} QUERY_SERVICE_CONFIGW;
typedef struct _QUERY_SERVICE_CONFIGW *LPQUERY_SERVICE_CONFIGW;
typedef struct _SERVICE_STATUS {
    DWORD dwServiceType;
    DWORD dwCurrentState;
    DWORD dwControlsAccepted;
    DWORD dwWin32ExitCode;
    DWORD dwServiceSpecificExitCode;
    DWORD dwCheckPoint;
    DWORD dwWaitHint;
} SERVICE_STATUS;
typedef struct _SERVICE_STATUS *LPSERVICE_STATUS;
typedef enum _SC_STATUS_TYPE {
    SC_STATUS_PROCESS_INFO = 0
} SC_STATUS_TYPE;
typedef struct _SERVICE_DESCRIPTIONW {
    LPWSTR lpDescription;
} SERVICE_DESCRIPTIONW;
typedef struct _SERVICE_DESCRIPTIONW *LPSERVICE_DESCRIPTIONW;
typedef enum _SC_ACTION_TYPE {
    SC_ACTION_NONE = 0,
    SC_ACTION_RESTART = 1,
    SC_ACTION_REBOOT = 2,
    SC_ACTION_RUN_COMMAND = 3
} SC_ACTION_TYPE;
typedef struct _SC_ACTION {
    SC_ACTION_TYPE Type;
    DWORD Delay;
} SC_ACTION;
typedef struct _SC_ACTION *LPSC_ACTION;
typedef struct _SERVICE_FAILURE_ACTIONSW {
    DWORD dwResetPeriod;
    LPWSTR lpRebootMsg;
    LPWSTR lpCommand;
    DWORD cActions;
    SC_ACTION *lpsaActions;
} SERVICE_FAILURE_ACTIONSW;
typedef struct _SERVICE_FAILURE_ACTIONSW *LPSERVICE_FAILURE_ACTIONSW;
typedef struct _SERVICE_PRESHUTDOWN_INFO {
    DWORD dwPreshutdownTimeout;
} SERVICE_PRESHUTDOWN_INFO;
typedef struct _SERVICE_PRESHUTDOWN_INFO *LPSERVICE_PRESHUTDOWN_INFO;
typedef struct _ENUM_SERVICE_STATUSW {
    LPWSTR lpServiceName;
    LPWSTR lpDisplayName;
    SERVICE_STATUS ServiceStatus;
} ENUM_SERVICE_STATUSW;
typedef struct _ENUM_SERVICE_STATUSW *LPENUM_SERVICE_STATUSW;
#endif
typedef union __WIDL_svcctl_generated_name_00000000 {
    SERVICE_DESCRIPTIONW descr;
    SERVICE_FAILURE_ACTIONSW actions;
    SERVICE_PRESHUTDOWN_INFO preshutdown;
} SERVICE_CONFIG2W;
DWORD __cdecl svcctl_CloseServiceHandle(
    SC_RPC_HANDLE *handle);

DWORD __cdecl svcctl_ControlService(
    SC_RPC_HANDLE hService,
    DWORD dwControl,
    SERVICE_STATUS *lpServiceStatus);

DWORD __cdecl svcctl_DeleteService(
    SC_RPC_HANDLE hService);

DWORD __cdecl svcctl_LockServiceDatabase(
    SC_RPC_HANDLE hSCManager,
    SC_RPC_LOCK *phLock);

DWORD __cdecl svcctl_QueryServiceObjectSecurity(
    void);

DWORD __cdecl svcctl_SetServiceObjectSecurity(
    void);

DWORD __cdecl svcctl_QueryServiceStatus(
    void);

DWORD __cdecl svcctl_SetServiceStatus(
    SC_RPC_HANDLE hServiceStatus,
    LPSERVICE_STATUS lpServiceStatus);

DWORD __cdecl svcctl_UnlockServiceDatabase(
    SC_RPC_LOCK *phLock);

DWORD __cdecl svcctl_NotifyBootConfigStatus(
    void);

DWORD __cdecl svcctl_SCSetServiceBitsW(
    void);

DWORD __cdecl svcctl_ChangeServiceConfigW(
    SC_RPC_HANDLE hService,
    DWORD dwServiceType,
    DWORD dwStartType,
    DWORD dwErrorControl,
    LPCWSTR lpBinaryPathName,
    LPCWSTR lpLoadOrderGroupKey,
    DWORD *lpdwTagId,
    const BYTE *lpDependencies,
    DWORD dwDependenciesSize,
    LPCWSTR lpServiceStartName,
    const BYTE *lpPassword,
    DWORD dwPasswordSize,
    LPCWSTR lpDisplayName);

DWORD __cdecl svcctl_CreateServiceW(
    SC_RPC_HANDLE hSCManager,
    LPCWSTR lpServiceName,
    LPCWSTR lpDisplayName,
    DWORD dwDesiredAccess,
    DWORD dwServiceType,
    DWORD dwStartType,
    DWORD dwErrorControl,
    LPCWSTR lpBinaryPathName,
    LPCWSTR lpLoadOrderGroup,
    DWORD *lpdwTagId,
    const BYTE *lpDependencies,
    DWORD dwDependenciesSize,
    LPCWSTR lpServiceStartName,
    const BYTE *lpPassword,
    DWORD dwPasswordSize,
    SC_RPC_HANDLE *phService);

DWORD __cdecl svcctl_EnumDependentServicesW(
    void);

DWORD __cdecl svcctl_EnumServicesStatusW(
    SC_RPC_HANDLE hmngr,
    DWORD type,
    DWORD state,
    BYTE *buffer,
    DWORD size,
    LPDWORD needed,
    LPDWORD returned);

DWORD __cdecl svcctl_OpenSCManagerW(
    MACHINE_HANDLEW MachineName,
    LPCWSTR DatabaseName,
    DWORD dwAccessMask,
    SC_RPC_HANDLE *handle);

DWORD __cdecl svcctl_OpenServiceW(
    SC_RPC_HANDLE hSCManager,
    LPCWSTR lpServiceName,
    DWORD dwDesiredAccess,
    SC_RPC_HANDLE *phService);

DWORD __cdecl svcctl_QueryServiceConfigW(
    SC_RPC_HANDLE hService,
    QUERY_SERVICE_CONFIGW *config);

DWORD __cdecl svcctl_QueryServiceLockStatusW(
    void);

DWORD __cdecl svcctl_StartServiceW(
    SC_RPC_HANDLE hService,
    DWORD dwNumServiceArgs,
    LPCWSTR *lpServiceArgVectors);

DWORD __cdecl svcctl_GetServiceDisplayNameW(
    SC_RPC_HANDLE hSCManager,
    LPCWSTR lpServiceName,
    WCHAR lpBuffer[],
    DWORD *cchBufSize);

DWORD __cdecl svcctl_GetServiceKeyNameW(
    SC_RPC_HANDLE hSCManager,
    LPCWSTR lpServiceDisplayName,
    WCHAR lpBuffer[],
    DWORD *cchBufSize);

DWORD __cdecl svcctl_SCSetServiceBitsA(
    void);

DWORD __cdecl svcctl_ChangeServiceConfigA(
    void);

DWORD __cdecl svcctl_CreateServiceA(
    void);

DWORD __cdecl svcctl_EnumDependentServicesA(
    void);

DWORD __cdecl svcctl_EnumServicesStatusA(
    void);

DWORD __cdecl svcctl_OpenSCManagerA(
    void);

DWORD __cdecl svcctl_OpenServiceA(
    void);

DWORD __cdecl svcctl_QueryServiceConfigA(
    void);

DWORD __cdecl svcctl_QueryServiceLockStatusA(
    void);

DWORD __cdecl svcctl_StartServiceA(
    void);

DWORD __cdecl svcctl_GetServiceDisplayNameA(
    void);

DWORD __cdecl svcctl_GetServiceKeyNameA(
    void);

DWORD __cdecl svcctl_GetCurrentGroupStateW(
    void);

DWORD __cdecl svcctl_EnumServiceGroupW(
    void);

DWORD __cdecl svcctl_ChangeServiceConfig2A(
    void);

DWORD __cdecl svcctl_ChangeServiceConfig2W(
    SC_RPC_HANDLE hService,
    DWORD InfoLevel,
    SERVICE_CONFIG2W *config);

DWORD __cdecl svcctl_QueryServiceConfig2A(
    void);

DWORD __cdecl svcctl_QueryServiceConfig2W(
    SC_RPC_HANDLE hService,
    DWORD InfoLevel,
    BYTE lpBuffer[],
    DWORD cbBufSize,
    LPDWORD pcbBytesNeeded);

DWORD __cdecl svcctl_QueryServiceStatusEx(
    SC_RPC_HANDLE hService,
    SC_STATUS_TYPE InfoLevel,
    BYTE *lpBuffer,
    DWORD cbBufSize,
    LPDWORD pcbBytesNeeded);

DWORD __cdecl svcctl_EnumServicesStatusExW(
    SC_RPC_HANDLE hmngr,
    DWORD type,
    DWORD state,
    BYTE *buffer,
    DWORD size,
    LPDWORD needed,
    LPDWORD returned,
    LPCWSTR group);


#endif  /* __svcctl_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */

handle_t __RPC_USER MACHINE_HANDLEW_bind(MACHINE_HANDLEW);
void __RPC_USER MACHINE_HANDLEW_unbind(MACHINE_HANDLEW, handle_t);
void __RPC_USER SC_RPC_HANDLE_rundown(SC_RPC_HANDLE);
void __RPC_USER SC_RPC_LOCK_rundown(SC_RPC_LOCK);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __svcctl_h__ */

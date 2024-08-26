#ifndef OIDC_SETTINGS_H
#define OIDC_SETTINGS_H

#include "msys.h"
#include "oidc_values.h"

#ifndef BIN_PATH
#define BIN_PATH "/usr/bin"
#endif
#define AGENT_PATH BIN_PATH "/oidc-agent"

// env var names
/**
 * the name of the environment variable used to locate the IPC socket
 */
#define OIDC_SOCK_ENV_NAME "OIDC_SOCK"
/**
 * the name of the environment variable used to locate the remote TCP socket
 */
#define OIDC_REMOTE_SOCK_ENV_NAME "OIDC_REMOTE_SOCK"
/**
 * the name of the environment variable that holds the agent pid
 */
#define OIDC_PID_ENV_NAME "OIDCD_PID"
/**
 * the name of the environment variable that might hold the oidcagentdir
 * location
 */
#define OIDC_CONFIG_DIR_ENV_NAME "OIDC_CONFIG_DIR"
/**
 * the name of the environment variable that might hold the path to the user's
 * config file
 */
#define OIDC_USER_CONFIG_PATH_ENV_NAME "OIDC_USER_CONFIG"
/**
 * the scope used as default value
 */
#define DEFAULT_SCOPE OIDC_SCOPE_OPENID " profile " OIDC_SCOPE_OFFLINE_ACCESS

// Default env var names for arguments
#define OIDC_REFRESHTOKEN_ENV_NAME "OIDC_REFRESH_TOKEN"
#define OIDC_PASSWORD_ENV_NAME "OIDC_ENCRYPTION_PW"

// file names
#define ISSUER_CONFIG_FILENAME "issuer.config"
#define ISSUER_CONFIG_DIRNAME ISSUER_CONFIG_FILENAME ".d"
#define CUSTOM_PARAMETERS_FILENAME "custom_parameters.config"

#ifdef ANY_MSYS
const char* CERT_FILE();
const char* ETC_ISSUER_CONFIG_FILE();
const char* ETC_ISSUER_CONFIG_DIR();
const char* ETC_CUSTOM_PARAMETERS_FILE();
const char* _MYTOKEN_GLOBAL_BASE();
const char* ETC_CONFIG_FILE();

#define OIDC_AGENT_REGISTRY "SOFTWARE\\oidc-agent"
#define SOCKET_LOOPBACK_ADDRESS "127.0.0.1"
#else
#ifndef CONFIG_PATH
#define CONFIG_PATH "/etc"
#endif

#define ETC_ISSUER_CONFIG_FILE CONFIG_PATH "/oidc-agent/" ISSUER_CONFIG_FILENAME
#define ETC_ISSUER_CONFIG_DIR CONFIG_PATH "/oidc-agent/" ISSUER_CONFIG_DIRNAME
#define ETC_CUSTOM_PARAMETERS_FILE \
  CONFIG_PATH "/oidc-agent/" CUSTOM_PARAMETERS_FILENAME
#define ETC_CONFIG_FILE CONFIG_PATH "/oidc-agent/config"
#endif

#define MAX_PASS_TRIES 3
/**
 * maximum number of polling tries
 */
#define MAX_POLL 20
/**
 * the delta between two pollings in seconds
 */
#define DELTA_POLL 2  // seconds

#define HTTP_DEFAULT_PORT 4242
#define HTTP_FALLBACK_PORT 8080

#define CONF_ENDPOINT_SUFFIX ".well-known/openid-configuration"
#define OAUTH_CONF_ENDPOINT_SUFFIX ".well-known/oauth-authorization-server"

#ifdef NO_MSYS
extern char* possibleCertFiles[6];
#endif

/**
 * prefix for tmp-files generated during account generation;
 * if dynamic client registration is used, the client config is temporarily
 * saved in a file prefixed with that string
 */

#define CLIENT_TMP_PREFIX \
  "/tmp/oidc-gen:"  // This is not a filesystem path, this is only an oidc-agent
                    // internal 'file'
#ifdef ANY_MSYS
#define AGENTDIR_LOCATION_CONFIG "$LOCALAPPDATA/oidc-agent/oidc-agent/"
#define AGENTDIR_LOCATION_DOT "$USERPROFILE/Documents/oidc-agent/"
#else
#define AGENTDIR_LOCATION_CONFIG "~/.config/oidc-agent/"
#define AGENTDIR_LOCATION_DOT "~/.oidc-agent/"
#endif

#ifdef __linux__
#define URL_OPENER "xdg-open"
#else
#define URL_OPENER "open"
#endif

#ifdef ANY_MSYS
#define HOME_ENV "USERPROFILE"
#else
#define HOME_ENV "HOME"
#endif

#ifndef ANY_MSYS
#define TMPDIR_ENVVAR "TMPDIR"
#endif

#endif  // OIDC_SETTINGS_H

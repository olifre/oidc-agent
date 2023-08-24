// This file is automatically generated. If any of the .mustache files is changed, rerun the generation.
#ifndef PROMPTTEXT_TEMPLATES_H
#define PROMPTTEXT_TEMPLATES_H

#include "wrapper/cjson.h"

#define PROMPTTEMPLATE_AUTHENTICATE_CLI "{{intro}}\nTo continue please open the following URL in {{#code}}a browser on any device {{#qr}}(or use the QR code) {{/qr}}and enter the following code{{/code}}{{^code}}your browser{{/code}}:\n{{code}}"
#define PROMPTTEMPLATE_AUTHENTICATE_GUI "<h2>Authenticate</h2>\n<p/>\n{{intro}}\nTo continue please open the following URL in {{#code}}a browser on any device {{#qr}}(or use the QR code) {{/qr}}and enter the following code{{/code}}{{^code}}your browser{{/code}}:\n{{#code}}<p><b>{{.}}</b></p>{{/code}}\n<p class=\"tiny\">You need to close this window manually</p>"
#define PROMPTTEMPLATE_CONFIRM_CLI "{{#application-hint}}{{.}}{{/application-hint}}{{^application-hint}}An application{{/application-hint}} requests an {{token-type}} token for {{#issuer}}{{.}}{{/issuer}}{{^issuer}}{{shortname}}{{/issuer}}.\n{{#id}}ID tokens should not be passed to other applications as authorization.{{/id}}\nDo you want to allow the usage of {shortname}}?"
#define PROMPTTEMPLATE_CONFIRM_GUI "<h2>Confirm</h2>\n<p/>\n{{#application-hint}}<b>{{.}}</b>{{/application-hint}}{{^application-hint}}An application{{/application-hint}} requests an {{token-type}} token for <b>{{#issuer}}{{.}}{{/issuer}}{{^issuer}}{{shortname}}{{/issuer}}</b>.\n{{#id}}ID tokens should not be passed to other applications as authorization.{{/id}}\nDo you want to allow the usage of <b>{{shortname}}</b>?"
#define PROMPTTEMPLATE_CONFIRM_PASSWORD_CLI "Confirm encryption password"
#define PROMPTTEMPLATE_CONFIRM_PASSWORD_GUI "<h2>Confirm Password</h2>\n<p/>\nConfirm encryption password:"
#define PROMPTTEMPLATE_LINK_IDENTITY_CLI "{{#application-hint}}{{.}}{{/application-hint}}{{^application-hint}}An application{{/application-hint}} requests an access token for {{issuer}}.\nThere currently is no identity configured for this issuer. Do you want to configure one now?"
#define PROMPTTEMPLATE_LINK_IDENTITY_GUI "<h2>Link Identity</h2>\n<p/>\n{{#application-hint}}<b>{{.}}</b>{{/application-hint}}{{^application-hint}}An application{{/application-hint}} requests an access token for <b>{{issuer}}</b>.\n<p/>\nThere currently is no identity configured for this issuer. Do you want to configure one now?"
#define PROMPTTEMPLATE_PASSWORD_CLI "Enter encryption password for {{shortname}}"
#define PROMPTTEMPLATE_PASSWORD_GUI "<h2>Enter Password</h2>\n<p/>\nEnter encryption password for {{shortname}}:"
#define PROMPTTEMPLATE_SHORTNAME_CLI "{{#exists}}An account with that shortname is already configured.\nPlease choose another shortname.\n\n{{/exists}}\nEnter short name for the account to configure"
#define PROMPTTEMPLATE_SHORTNAME_GUI "<h2>Configure account</h2>\n<p/>\n{{#exists}}An account with that shortname is already configured.\nPlease choose another shortname.\n<p/>{{/exists}}\nEnter short name for the account to configure:"
#define PROMPTTEMPLATE_UNLOCK_ACCOUNT_CLI "{{#application-hint}}{{.}}{{/application-hint}}{{^application-hint}}An application{{/application-hint}} requests an access token for {{shortname}}, which is currently not loaded.\nEnter the encryption password to unlock account {{shortname}}"
#define PROMPTTEMPLATE_UNLOCK_ACCOUNT_GUI "<h2>Unlock Identity</h2>\n<p/>\n{{#application-hint}}<b>{{.}}</b>{{/application-hint}}{{^application-hint}}An application{{/application-hint}} requests an access token for <b>{{shortname}}</b>, which is currently not loaded.\nEnter the encryption password to unlock account <b>{{shortname}}</b>."
#define PROMPTTEMPLATE_UNLOCK_ACCOUNT_ISSUER_CLI "{{#application-hint}}{{.}}{{/application-hint}}{{^application-hint}}An application{{/application-hint}} requests an access token for {{issuer}}, but this provider is currently not loaded.\nEnter the encryption password to unlock account {{shortname}}"
#define PROMPTTEMPLATE_UNLOCK_ACCOUNT_ISSUER_GUI "<h2>Unlock Identity</h2>\n<p/>\n{{#application-hint}}<b>{{.}}</b>{{/application-hint}}{{^application-hint}}An application{{/application-hint}} requests an access token for <b>{{issuer}}</b>, but this provider is currently not loaded.\nEnter the encryption password to unlock account <b>{{shortname}}</b>."
#define PROMPTTEMPLATE_UPDATE_ACCOUNT_CLI "oidc-agent needs to update the account config for {{shortname}}.\nPlease enter the encryption password for {{shortname}}"
#define PROMPTTEMPLATE_UPDATE_ACCOUNT_GUI "<h2>Update Account Config</h2>\n<p/>\noidc-agent needs to update the account config for <b>{{shortname}}</b>.<br/>\nPlease enter the encryption password for <b>{{shortname}}</b>."

#endif // PROMPTTEXT_TEMPLATES_H

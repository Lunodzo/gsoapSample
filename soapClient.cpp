/* soapClient.cpp
   Generated by gSOAP 2.8.117 for hello.h

gSOAP XML Web services tools
Copyright (C) 2000-2021, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"

SOAP_SOURCE_STAMP("@(#) soapClient.cpp ver 2.8.117 2024-02-09 15:15:27 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__hello(struct soap *soap, const char *soap_endpoint, const char *soap_action, const std::string& name, std::string &greeting)
{	if (soap_send_ns__hello(soap, soap_endpoint, soap_action, name) || soap_recv_ns__hello(soap, greeting))
		return soap->error;
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_send_ns__hello(struct soap *soap, const char *soap_endpoint, const char *soap_action, const std::string& name)
{	struct ns__hello soap_tmp_ns__hello;
	soap_tmp_ns__hello.name = name;
	soap_begin(soap);
	soap->encodingStyle = NULL; /* use SOAP literal style */
	soap_serializeheader(soap);
	soap_serialize_ns__hello(soap, &soap_tmp_ns__hello);
	if (soap_begin_count(soap))
		return soap->error;
	if ((soap->mode & SOAP_IO_LENGTH))
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__hello(soap, &soap_tmp_ns__hello, "ns:hello", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__hello(soap, &soap_tmp_ns__hello, "ns:hello", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	return SOAP_OK;
}

SOAP_FMAC5 int SOAP_FMAC6 soap_recv_ns__hello(struct soap *soap, std::string &greeting)
{
	struct ns__helloResponse *soap_tmp_ns__helloResponse;
	soap_default_std__string(soap, &greeting);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_tmp_ns__helloResponse = soap_get_ns__helloResponse(soap, NULL, "ns:helloResponse", NULL);
	if (!soap_tmp_ns__helloResponse || soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	greeting = soap_tmp_ns__helloResponse->greeting;
	return soap_closesock(soap);
}

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.cpp */

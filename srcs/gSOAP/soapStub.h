/* soapStub.h
   Generated by gSOAP 2.7.8c from calc.h
   Copyright (C) 2000-2006, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/

#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#ifndef SOAP_TYPE_ns__addResponse
#define SOAP_TYPE_ns__addResponse (9)
/* ns:addResponse */
struct ns__addResponse
{
public:
	double *result;	/* RPC return element */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_ns__add
#define SOAP_TYPE_ns__add (10)
/* ns:add */
struct ns__add
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_ns__subResponse
#define SOAP_TYPE_ns__subResponse (12)
/* ns:subResponse */
struct ns__subResponse
{
public:
	double *result;	/* RPC return element */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_ns__sub
#define SOAP_TYPE_ns__sub (13)
/* ns:sub */
struct ns__sub
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_ns__mulResponse
#define SOAP_TYPE_ns__mulResponse (15)
/* ns:mulResponse */
struct ns__mulResponse
{
public:
	double *result;	/* RPC return element */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_ns__mul
#define SOAP_TYPE_ns__mul (16)
/* ns:mul */
struct ns__mul
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_ns__divResponse
#define SOAP_TYPE_ns__divResponse (18)
/* ns:divResponse */
struct ns__divResponse
{
public:
	double *result;	/* RPC return element */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_ns__div
#define SOAP_TYPE_ns__div (19)
/* ns:div */
struct ns__div
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_ns__powResponse
#define SOAP_TYPE_ns__powResponse (21)
/* ns:powResponse */
struct ns__powResponse
{
public:
	double *result;	/* RPC return element */	/* optional element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_ns__pow
#define SOAP_TYPE_ns__pow (22)
/* ns:pow */
struct ns__pow
{
public:
	double a;	/* required element of type xsd:double */
	double b;	/* required element of type xsd:double */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (25)
/* SOAP Header: */
struct SOAP_ENV__Header
{
public:
	void *dummy;	/* transient */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (26)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (28)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
	char *__any;
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (29)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (30)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (4)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif


/******************************************************************************\
 *                                                                            *
 * Typedef Synonyms                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Service Operations                                                         *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 ns__add(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 ns__sub(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 ns__mul(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 ns__div(struct soap*, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 ns__pow(struct soap*, double a, double b, double *result);

/******************************************************************************\
 *                                                                            *
 * Stubs                                                                      *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__add(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__sub(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__mul(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__div(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__pow(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result);

/******************************************************************************\
 *                                                                            *
 * Skeletons                                                                  *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__add(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__sub(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__mul(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__div(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_ns__pow(struct soap*);

#endif

/* End of soapStub.h */

/****************************************************************************
**
** Author: Miroslav Safr <miroslav.safr@gmail.com>
** Web: https://github.com/safrm/soap_calc
**
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
****************************************************************************/
#include "soapH.h"
#include "calc.nsmap"

int main(int argc, char **argv)
{ int m, s; /* master and slave sockets */
  struct soap soap;
  soap_init(&soap);
  if (argc < 2)
    soap_serve(&soap);	/* serve as CGI application */
  else
  { m = soap_bind(&soap, NULL, atoi(argv[1]), 100);
    if (m < 0)
    { soap_print_fault(&soap, stderr);
      exit(-1);
    }
    fprintf(stderr, "Socket connection successful: master socket = %d\n", m);
    for ( ; ; )
    { s = soap_accept(&soap);
      fprintf(stderr, "Socket connection successful: slave socket = %d\n", s);
      if (s < 0)
      { soap_print_fault(&soap, stderr);
        exit(-1);
      } 
      soap_serve(&soap);
      soap_end(&soap);
    }
  }
  return 0;
} 

int ns__add(struct soap *soap, double a, double b, double *result)
{ *result = a + b;
  return SOAP_OK;
} 

int ns__sub(struct soap *soap, double a, double b, double *result)
{ *result = a - b;
  return SOAP_OK;
} 

int ns__mul(struct soap *soap, double a, double b, double *result)
{ *result = a * b;
  return SOAP_OK;
} 

int ns__div(struct soap *soap, double a, double b, double *result)
{ if (b)
    *result = a / b;
  else
  { char *s = (char*)soap_malloc(soap, 1024);
    sprintf(s, "<error xmlns=\"http://tempuri.org/\">Can't divide %f by %f</error>", a, b);
    return soap_sender_fault(soap, "Division by zero", s);
  }
  return SOAP_OK;
} 

int ns__pow(struct soap *soap, double a, double b, double *result)
{ *result = pow(a, b);
  if (soap_errno == EDOM)	/* soap_errno is like errno, but compatible with Win32 */
  { char *s = (char*)soap_malloc(soap, 1024);
    sprintf(s, "Can't take the power of %f to %f", a, b);
    sprintf(s, "<error xmlns=\"http://tempuri.org/\">Can't take power of %f to %f</error>", a, b);
    return soap_sender_fault(soap, "Power function domain error", s);
  }
  return SOAP_OK;
} 

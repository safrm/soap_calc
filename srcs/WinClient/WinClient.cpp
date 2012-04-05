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
#include <windows.h>
#include <tchar.h>
#include <wininet.h>
#include <stdio.h>
#include "resource.h"
#include "soapH.h"
#include "calc.nsmap"

const char server[] = " http://127.0.0.1/"; 

enum SignalType
{
  PLUS,
  MINUS,
  MUL,
  DIV,
  POW
} type;

void UseSOAP(SignalType signal,HWND hDlg)
{
  struct soap soap;
  double a, b, result= 0;
  soap_init(&soap);
  TCHAR szA[20];
  TCHAR szB[20];
  TCHAR szServer[60];
  GetDlgItemText(hDlg,IDC_EDIT1,szA,20);
  GetDlgItemText(hDlg,IDC_EDIT2,szB,20);
  GetDlgItemText(hDlg,IDC_IP_ADRRESS,szServer,60);
  a = atof (szA);
  b = atof (szB);
    

  switch (signal)
  { case PLUS:
      soap_call_ns__add(&soap, szServer, "", a, b, &result);
      break;
    case MINUS:
      soap_call_ns__sub(&soap, szServer, "", a, b, &result);
      break;
    case MUL:
      soap_call_ns__mul(&soap, szServer, "", a, b, &result);
      break;
    case DIV:
      soap_call_ns__div(&soap, szServer, "", a, b, &result);
      break;
    case POW:
      soap_call_ns__pow(&soap, szServer, "", a, b, &result);
      break;
    default:
      MessageBox(hDlg,"Unknown command","Error",MB_OK);
  }
  if (soap.error)
  { 
    soap_print_fault(&soap, stderr);
    MessageBox(hDlg,"SOAP error","Error",MB_OK);
  }
  else
  {
    printf("result = %g\n", result);
    TCHAR szR[20];
     sprintf(szR, "=%g",result);
    SetDlgItemText(hDlg,IDC_RESULT,szR); 
  }

  soap_destroy(&soap);
  soap_end(&soap);
  soap_done(&soap); 

}

INT_PTR CALLBACK DialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch ( uMsg )
	{
		case WM_COMMAND:
			switch ( LOWORD(wParam) )
			{
				case IDOK:
				case IDCANCEL:
					EndDialog(hWnd, LOWORD(wParam));
					break;
        case IDPLUS:
          UseSOAP(PLUS,hWnd);
          break;
        case IDMINUS:
          UseSOAP(MINUS,hWnd);
          break;
        case IDMUL:
          UseSOAP(MUL,hWnd);
          break;
        case IDDIV:
          UseSOAP(DIV,hWnd);
          break;
        case IDPOW:
          UseSOAP(POW,hWnd);
          break;
			}
			break;
		case WM_INITDIALOG:
      SetDlgItemText(hWnd,IDC_IP_ADRRESS,server);
      SetDlgItemText(hWnd,IDC_EDIT1,"0");
      SetDlgItemText(hWnd,IDC_EDIT2,"0");
			break;
	}
	return FALSE;
}

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)
{
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_WinClient), NULL, DialogProc);
	return 0;
}



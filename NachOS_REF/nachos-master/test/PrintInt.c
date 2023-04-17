/*
 * =====================================================================================
 *
 *       Filename:  PrintInt.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2013 06:32:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "syscall.h"
#include "copyright.h"
int main()
{
	int n;
	PrintString("Nhap 1 so:");
	n = ReadInt();
	PrintString("So vua nhap:");
	PrintInt(n); // Test the PrintInt function: print 100 to console.
	return 0;
}


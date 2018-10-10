#include "stdafx.h"		// ����������� ������������ ����
#include "Task3.h"		// ���� � ����������� ������� function_3

#define MAX_SIZE 100	// ������ ���������� ��������� MAX_SIZE ��������� 100. ������ MAX_SIZE ����������� ������ 100

void function_3()	// ����������� ������� function_3
{	// ������ �������
	char str[MAX_SIZE];		// ������� ������ (������ ��������) ������� 100 �� ����� str
	cout << "������� ����� ������:" << endl << "� �������� ��������������� ���������: " << endl;	// �����
	cin >> str;			// ���� ������ � ���������� str
	int num, buf;		// ��������� ���������� num � buf. � num ����� ��������� ����������� ����� ��������� ������, � buf ����� ��������������
						// ��� ���������� ����������������� ������� ��� ������ 
	for (int i = 0; i < MAX_SIZE; i++)	// ����. ������� ����������-������� i, ���������� ������� ����. ����� ������ �������� ����� �����������
								// i �� �������, �� ��� ���, ���� i �� ��������� �������� ������������ ����� ������ MAX_SIZE (100)
	{	// ������ �����
		if (str[i] == '\0')	// ��������� i-��� ������ ������. ���� ������� ����.������ ����� ������ '\0', ��������� ���� if-a
		{	// ������ if-a
			num = i - 1;	// ����������� � ���������� num ����� ���������� ��������� ������� � ������ str
			break;	// ��������� ����, �������� �� ���������� ���������� ����.
		}	// ����� if-a
	}	// ����� �����
	// �.�. ����� break-a �� �������� ����
	for (int i = 0, j = num; i < j; i++, j--)	// ���������� �� ������ str � ���� ������. ���������� i ������ ��� �������� �������� �������
				// � ����� ����� ������ (������� � 0 � �.�., ������������ �� �������), ���������� j ��� �������� �������� � ������ ������� 
				// (������� � num � ���������� � ������ ��������� �� �������)
	{	// ������ ����� �������� ������
		buf = str[i];	// ���������� � ���������� buf i-�� ������ ������ (��� ������ �������� - ����� 0-�� ������(������))
		str[i] = str[j];	// ���������� � i-�� ������ ������ j-�� ������ (��� ������ �������� - � ������ ������ ������ ���������� ���������)
		str[j] = buf;	// ���������� � j-�� ������ �������� buf (������ i-�� ������) (��� ������ �������� - � ��������� ������ ���������� ���������� ������)
	}	// ����� �����
	cout << str << endl;	// ������� ��� ������������ ������
}	// ����� �������
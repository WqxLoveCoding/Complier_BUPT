//
// Created by 18233 on 2020/8/25/025.
//
#include <fstream>
#include <conio.h>
#include "compile.h"


int main()
{
    string temp;
    int line_no = 1;
    const char* file_path = "test_code_1.txt";
    cout << "------------------------------------------------------" << endl;
    cout << "Raw code\n" << endl;
    // ԭʼ�������
    ifstream infile(file_path);
    while (!infile.eof())
    {
        getline(infile, temp);
        printf("%-4d", line_no);
        line_no++;
        cout << temp << endl;
    }
    infile.close();
    cout << "------------------------------------------------------" << endl;
    // �ʷ����� + �﷨����
    syntax_process(file_path);
    cout << "------------------------------------------------------" << endl;
    // �������
    semantic(root_node);
    print_stable();
    // ��������
    generate_code(&root_node);
    //getch();
    return 0;
}


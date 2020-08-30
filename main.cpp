//
// Created by 18233 on 2020/8/25/025.
//
#include <fstream>
#include <conio.h>
#include "compile.h"


int main(int argc, char ** argv)
{
    string temp;
    int line_no = 1;
    const char* file_path;
    if(argc == 1) file_path = "file.txt";
    else file_path = argv[1];
    cout << "------------------------------------------------------" << endl;
    cout << "Raw code\n" << endl;
    // ԭʼ�������
    ifstream infile(file_path);
    while (getline(infile, temp))
    {
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
    cout << "Symbol Table" << endl;
    output_table(curTable, 0);
    cout << "------------------------------------------------------" << endl;
    // ��������
    generate_code(&root_node, file_path);
    // getch();
    return 0;
}


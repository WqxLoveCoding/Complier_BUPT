#include "Compiler.h"

// ��������
void postorder_traversal(const ATRNode& Node);
T_item search_table(const string & name, bool only_cur_table);
void insert_symbol_table(const T_item & item);

void generate_1(const ATRNode & node);
void generate_2(const ATRNode & node);
void generate_3(const ATRNode & node);
void generate_4(const ATRNode & node);
int generate_5(const ATRNode & node, const TYPE_info & type_info);
int generate_6(const ATRNode & node, const TYPE_info & type_info);
void generate_7(const ATRNode & node);
void generate_8(const ATRNode & node);
void generate_9(const ATRNode & node);
void generate_10(const ATRNode & node);
void generate_15(const ATRNode & node);
void generate_16(const ATRNode & node);
void generate_17(const ATRNode & node);
void generate_18(const ATRNode & node);
TYPE_info generate_19(const ATRNode & node);
TYPE_info generate_20(const ATRNode & node);
TYPE_info generate_21(const ATRNode & node);
void generate_25(const ATRNode & node, TYPE_info & type_info);
void generate_26(const ATRNode & node, TYPE_info & type_info);
void generate_27(const ATRNode & node);
void generate_28(const ATRNode & node);
void generate_29(const ATRNode & node);
void generate_30(const ATRNode & node);
void generate_31(const ATRNode & node);
int generate_32(const ATRNode & node);
int generate_33(const ATRNode & node);
int generate_34(const ATRNode & node);
int generate_35(const ATRNode & node);
int generate_36(const ATRNode & node);
int generate_38(const ATRNode & node);
int generate_39(const ATRNode & node);
void generate_40(const ATRNode & node);
void generate_41(const ATRNode & node);
void generate_42(const ATRNode & node);
void generate_43(const ATRNode & node);
void generate_44(const ATRNode & node);
void generate_45(const ATRNode & node);
void generate_46(const ATRNode & node);
void generate_47(const ATRNode & node);
void generate_48(const ATRNode & node);
void generate_49(const ATRNode & node);
void generate_50(const ATRNode & node);
void generate_51(const ATRNode & node);
void generate_52(const ATRNode & node);
void generate_53(const ATRNode & node);
void generate_54(const ATRNode & node);
int generate_55(const ATRNode & node);
vector<T_item> generate_56(const ATRNode & node);
void generate_58(const ATRNode & node);
void generate_59(const ATRNode & node);
vector<T_item> generate_62(const ATRNode & node);
T_item generate_63(const ATRNode & node);
T_item generate_64(const ATRNode & node);
T_item generate_65(const ATRNode & node);
T_item generate_66(const ATRNode & node);
T_item generate_67(const ATRNode & node);
T_item generate_68(const ATRNode & node);
T_item generate_69(const ATRNode & node);
T_item generate_70(const ATRNode & node);
int generate_72(const ATRNode & node);
int generate_73(const ATRNode & node);
int generate_74(const ATRNode & node);
int generate_75(const ATRNode & node);

vector<T_item> * curTable = & SymbolTable;

/*
 * program sample (input, output);
 *      var x, y: integer;
 *      begin
 *          x:=y+1
 *      end.
 *
 * */

//����һ����
ATRNode sampleCreate()
{
    //Ҷ�ӽڵ�,������Դ��
    ATRNode program(PROGRAM, "program");
    ATRNode id1(IDENTIFIER, "example");
    ATRNode leftBracket(LPAREN, "(");
    ATRNode id2(IDENTIFIER, "input");
    ATRNode comma1(COMMA, ",");
    ATRNode id3(IDENTIFIER, "output");
    ATRNode rightBracket(RPAREN, ")");
    ATRNode scolon1(SEMICOLON, ";");

    ATRNode empty1(EMPTY,"");
    ATRNode var(VAR, "var");
    ATRNode id4(IDENTIFIER, "x");
    ATRNode comma2(COMMA, ",");
    ATRNode id5(IDENTIFIER, "y");
    ATRNode colon(COLON, ":");
    ATRNode integer(TYPE, "integer");
    ATRNode scolon2(SEMICOLON, ";");
    ATRNode empty2(EMPTY,"");

    ATRNode begin(PBEGIN, "begin");
    ATRNode id6(IDENTIFIER, "x");
    ATRNode empty3(EMPTY, "");
    ATRNode assignment(ASSIGNMENT, ":=");
    ATRNode id7(IDENTIFIER, "y");
    ATRNode empty4(EMPTY, "");
    ATRNode add(PLUS, "+");
    ATRNode digits(DIGSEQ, "1");

    ATRNode end(END, "end");
    ATRNode dot(DOT, ".");

    //���ɷ�Ҷ�ӽڵ�
    ATRNode const_declarations(-1, "const_declarations");   //const_declarations->NULL
    // const_declarations.children.push_back(empty1);

    ATRNode subprogram_declarations(-1, "subprogram_declarations"); //subprogram_declarations->NULL
    // subprogram_declarations.children.push_back(empty2);

    //program example(input,output)
    ATRNode idlist1(-1,"idlist");   //idlist->id
    idlist1.children.push_back(id2);

    ATRNode idlist2(-1,"idlist");   //idlist->idlist , id
    idlist2.children.push_back(idlist1);
    idlist2.children.push_back(comma1);
    idlist2.children.push_back(id3);

    ATRNode program_head(-1, "program_head");   //program_head->program id ( idlist )
    program_head.children.push_back(program);
    program_head.children.push_back(id1);
    program_head.children.push_back(leftBracket);
    program_head.children.push_back(idlist2);
    program_head.children.push_back(rightBracket);

    //var  x,y:integer;
    ATRNode idlist3(-1,"idlist");   //idlist->id
    idlist3.children.push_back(id4);

    ATRNode idlist4(-1,"idlist");   //idlist->idlist , id
    idlist4.children.push_back(idlist3);
    idlist4.children.push_back(comma2);
    idlist4.children.push_back(id5);

    ATRNode basic_type1(-1, "basic_type");  //basic_type -> integer
    basic_type1.children.push_back(integer);

    ATRNode type1(-1, "type");  //type -> basic_type
    type1.children.push_back(basic_type1);

    ATRNode var_declaration(-1, "var_declaration"); //var_declaration->idlist  :  type
    var_declaration.children.push_back(idlist4);
    var_declaration.children.push_back(colon);
    var_declaration.children.push_back(type1);

    ATRNode var_declarations(-1, "var_declarations"); //var_declarations->var  var_declaration ;
    var_declarations.children.push_back(var);
    var_declarations.children.push_back(var_declaration);
    var_declarations.children.push_back(scolon2);

    //begin
    //     x:=y+1
    //end
    ATRNode id_varpart1(-1, "id_varpart"); //id_varpart->NULL
    // id_varpart1.children.push_back(empty3);

    ATRNode variable1(-1, "variable"); //variable->id id_varpart
    variable1.children.push_back(id6);
    variable1.children.push_back(id_varpart1);


    ATRNode id_varpart2(-1, "id_varpart"); //id_varpart->NULL
    // id_varpart2.children.push_back(empty4);

    ATRNode variable2(-1, "variable"); //variable->id id_varpart
    variable2.children.push_back(id7);
    variable2.children.push_back(id_varpart2);

    ATRNode factor1(-1,"factor"); //factor->variable
    factor1.children.push_back(variable2);

    ATRNode term1(-1,"term"); //term->factor
    term1.children.push_back(factor1);

    ATRNode simple_expression1(-1, "simple_expression"); //simple_expression->term
    simple_expression1.children.push_back(term1);

    ATRNode num(-1,"num"); // num -> digits
    num.children.push_back(digits);

    ATRNode factor2(-1,"factor"); //factor->variable
    factor2.children.push_back(num);

    ATRNode term2(-1,"term"); //term->factor
    term2.children.push_back(factor2);

    ATRNode simple_expression2(-1, "simple_expression"); //simple_expression->simple_expression addop term
    simple_expression2.children.push_back(simple_expression1);
    simple_expression2.children.push_back(add);
    simple_expression2.children.push_back(term2);

    ATRNode expression(-1, "expression");   //expression->simple_expression
    expression.children.push_back(simple_expression2);

    ATRNode statement(-1, "statement"); //statement->variable assignment expression
    statement.children.push_back(variable1);
    statement.children.push_back(assignment);
    statement.children.push_back(expression);

    ATRNode statement_list(-1, "statement_list"); //statement_list->statement
    statement_list.children.push_back(statement);

    ATRNode compound_statement(-1, "compound_statement");
    compound_statement.children.push_back(begin);
    compound_statement.children.push_back(statement_list);
    compound_statement.children.push_back(end);


    ATRNode program_body(-1, "program_body");
    program_body.children.push_back(const_declarations);
    program_body.children.push_back(var_declarations);
    program_body.children.push_back(subprogram_declarations);
    program_body.children.push_back(compound_statement);

    ATRNode programstruct(-1, "programstruct");
    programstruct.children.push_back(program_head);
    programstruct.children.push_back(scolon1);
    programstruct.children.push_back(program_body);
    programstruct.children.push_back(dot);


    return programstruct;
}

string show_type(int type)
{
    string str;
    switch(type)
    {
        case INTEGER:
            str = "integer";
            break;
        case REAL:
            str = "real";
            break;
        case CHAR:
            str = "char";
            break;
        case BOOLEAN:
            str = "boolean";
            break;
        case PROGRAM:
            str = "program";
            break;
        case FUNCTION:
            str = "function";
            break;
        case PROCEDURE:
            str = "procedure";
            break;
        default:
            str = "none";
            break;
    }
    return str;
}

void print_stable()
{
    for(auto &i : SymbolTable)
    {
        cout << i.name << " " << show_type(i.type) << " " << i.dimension << endl;
    }
}

//���������
void postorder_traversal(const ATRNode& Node)
{
    if(Node.children.empty() and Node.id != -1)
    {
        cout << Node.attr << " ";
    }
    else{
        for(auto & i : Node.children)
        {
            postorder_traversal(i);
        }
    }
}
 // ���ҷ��ű����Ƿ����Ϊ name ����
T_item search_table(const string & name, bool only_cur_table)
{
    T_item result("false", 0, 0, 0, nullptr);
    for(auto & i : (*curTable))
    {
        if (name==i.name)
        {
            result = i;
            break;
        }
    }
    if(only_cur_table)
    {
        return result;
    }
    else
    {
        vector<T_item> * temp = curTable;
        bool find = false;
        while((*temp)[0].p != nullptr)
        {
            result = search_table(name, true);
            if(result.name == "false")
            {
                temp = (*temp)[0].p;
            }
            else
            {
                find = true;
                break;
            }
        }
        if(!find)
        {
            result = search_table(name, true);
        }
        return result;
    }
}

// �ڷ��ű��в���item����
void insert_symbol_table(const T_item & item)
{
    T_item search_result = search_table(item.name, true);
    if(search_result.name == "false")
    {
        // cout << "������ű� " << item.name << endl;
        (*curTable).push_back(item);
    } else{
        cout << item.name <<"�ظ�����" <<endl;
    }
}

// programstruct -> program_head  ��program_body .
void generate_1(const ATRNode & node)
{
    if(node.children[0].children.size()==2)
    {
        generate_3(node.children[0]);
    }
    else{
        generate_2(node.children[0]);
    }
    generate_4(node.children[2]);
}

// program_head -> program id �������ӱ�( idlist ����������Ϊ�ա������ã����ʹ��ݡ�)
void generate_2(const ATRNode & node)
{
    ATRNode id = node.children[1];
    T_item item(id.attr, PROGRAM, 0, 0, nullptr);
    insert_symbol_table(item);
    TYPE_info type_info(NONE, 0, nullptr);
    int id_count;
    if(node.children[3].children.size()==1)
    {
        id_count = generate_6(node.children[3], type_info);
    }
    else{
        id_count = generate_5(node.children[3], type_info);
    }
    (*curTable)[0].dimension = id_count;
}

// program_head -> program id
void generate_3(const ATRNode & node)
{
    ATRNode id = node.children[1];
    T_item item(id.attr, PROGRAM, 0, 0, nullptr);
    insert_symbol_table(item);
}

/*
 * program_body ->  const_declarations
 *                  var_declarations
 *                  subprogram_declarations
 *                  compound_statement
 * */

void generate_4(const ATRNode & node)
{
    if(node.children[0].children.empty())
    {
        generate_8(node.children[0]);
    }
    else{
        generate_7(node.children[0]);
    }
    if(node.children[1].children.empty())
    {
        generate_16(node.children[1]);
    }
    else{
        generate_15(node.children[1]);
    }
    if(node.children[2].children.empty())
    {
        generate_28(node.children[2]);
    }
    else{
        generate_27(node.children[2]);
    }
    generate_41(node.children[3]);
}

// idlist -> idlist , id  �����ʹ��ݡ���д����ű������ã����ʹ��ݡ�
int generate_5(const ATRNode & node, const TYPE_info & type_info)
{
    int id_count = 1;
    if(node.children[0].children.size()==1)
    {
        id_count += generate_6(node.children[0], type_info);
    }
    else{
        id_count += generate_5(node.children[0], type_info);
    }
    ATRNode id = node.children[2];
    T_item item(id.attr, type_info.type, type_info.dim, 0, type_info.p);
    insert_symbol_table(item);
    return id_count;
}

// idlist -> id  �����ʹ��ݡ���д����ű�
int generate_6(const ATRNode & node, const TYPE_info & type_info)
{
    ATRNode id = node.children[0];
    T_item item(id.attr, type_info.type, type_info.dim, 0, type_info.p);
    insert_symbol_table(item);
    return 1;
}

// const_declarations -> const  const_declaration  ;
void generate_7(const ATRNode & node)
{
    if(node.children[1].children.size()==3)
    {
        generate_10(node.children[1]);
    }
    else{
        generate_9(node.children[1]);
    }
}

// const_declarations ->
void generate_8(const ATRNode & node)
{}

// const_declaration -> const_declaration ;  id = const_value  �����ʹ��ݡ���д����ű�
void generate_9(const ATRNode & node)
{
    if(node.children[0].children.size()==3)
    {
        generate_10(node.children[1]);
    }
    else{
        generate_9(node.children[1]);
    }
    ATRNode id = node.children[2];
    ATRNode value = node.children[4];
    int type;
    if(value.children.size()==3)
    {
        type = CHAR;
    }
    else if(value.children.size()==1)
    {
        ATRNode num = value.children[0];
        if(num.children[0].attr == "digits")
        {
            type = INTEGER;
        }
        else
        {
            type = REAL;
        }
    }
    else
    {
        ATRNode num = value.children[1];
        if(num.children[0].attr == "digits")
        {
            type = INTEGER;
        }
        else
        {
            type = REAL;
        }
    }
    T_item item(id.attr, type, 0, 0, nullptr);
    insert_symbol_table(item);
}

// const_declaration -> id = const_value  �����ʹ��ݡ���д����ű�
void generate_10(const ATRNode & node)
{
    ATRNode id = node.children[0];
    ATRNode value = node.children[2];
    int type;
    if(value.children.size()==3)
    {
        type = CHAR;
    }
    else if(value.children.size()==1)
    {
        ATRNode num = value.children[0];
        if(num.children[0].id == DIGSEQ)
        {
            type = INTEGER;
        }
        else
        {
            type = REAL;
        }
    }
    else
    {
        ATRNode num = value.children[1];
        if(num.children[0].id == DIGSEQ)
        {
            type = INTEGER;
        }
        else
        {
            type = REAL;
        }
    }
    T_item item(id.attr, type, 0, 0, nullptr);
    insert_symbol_table(item);
}

// var_declarations -> var  var_declaration ;
void generate_15(const ATRNode & node)
{
    if(node.children[1].children.size()==3)
    {
        generate_18(node.children[1]);
    } else{
        generate_17(node.children[1]);
    }
}

// var_declarations ->
void generate_16(const ATRNode & node)
{}

// var_declaration -> var_declaration  ;  idlist  :  type  �����ʹ��ݡ������ã����ʹ��ݡ�
void generate_17(const ATRNode & node)
{
    if(node.children[0].children.size()==3)
    {
        generate_18(node.children[1]);
    }
    else{
        generate_17(node.children[1]);
    }
    TYPE_info type_info(NONE, 0, nullptr);
    if(node.children[4].children.size()==1)
    {
        type_info = generate_19(node.children[4]);
    } else{
        type_info = generate_20(node.children[4]);
    }
    if(node.children[2].children.size()==1)
    {
        generate_6(node.children[2], type_info);
    }
    else{
        generate_5(node.children[2], type_info);
    }
}

// var_declaration -> idlist  :  type  �����ʹ��ݡ������ã����ʹ��ݡ�
void generate_18(const ATRNode & node)
{
    TYPE_info type_info(NONE, 0, nullptr);
    if(node.children[2].children.size()==1)
    {
        type_info = generate_19(node.children[2]);
    }
    else{
        type_info = generate_20(node.children[2]);
    }
    if(node.children[0].children.size()==1)
    {
        generate_6(node.children[0], type_info);
    }
    else{
        generate_5(node.children[0], type_info);
    }
}

// type -> basic_type  �����ʹ��ݡ�
TYPE_info generate_19(const ATRNode & node)
{
    return generate_21(node.children[0]);
}

// type -> array  �����������ӱ�[  period  ] ���˳������ӱ� of  basic_type  �����ʹ��ݡ�
TYPE_info generate_20(const ATRNode & node)
{
    vector<T_item> array_table;
    TYPE_info type_info = generate_21(node.children[5]);
    vector<T_item> para_table;  // ����������Ϣ�ӱ�
    type_info.p = &para_table;
    if(node.children[2].children.size()==3)
    {
        generate_26(node.children[2], type_info);
    }
    else
    {
        generate_25(node.children[2], type_info);
    }
    return type_info;
}

// basic_type -> integer | real | boolean | char �����ʹ��ݡ�
TYPE_info generate_21(const ATRNode & node)
{
    ATRNode type = node.children[0];
    if(type.attr=="integer")
    {
        TYPE_info type_info(INTEGER, 0, nullptr);
        return type_info;
    }
    else if(type.attr=="real")
    {
        TYPE_info type_info(REAL, 0, nullptr);
        return type_info;
    }
    else if(type.attr=="boolean")
    {
        TYPE_info type_info(BOOLEAN, 0, nullptr);
        return type_info;
    }
    else if(type.attr=="char")
    {
        TYPE_info type_info(CHAR, 0, nullptr);
        return type_info;
    }
    else{
        TYPE_info type_info(NONE, 0, nullptr);
        cout << "basic_type ������Ϣ����!" <<endl;
        return type_info;
    }
}

// period -> period �� digits .. digits  ��ά��+1������Χ���桿
void generate_25(const ATRNode & node, TYPE_info & type_info)
{
    if(node.children[0].children.size()==3)
    {
        generate_26(node.children[0], type_info);
    }
    else
    {
        generate_25(node.children[0], type_info);
    }
    int start_index = stoi(node.children[2].attr);
    int end_index = stoi(node.children[4].attr);
    T_item item("", start_index, end_index, 0, nullptr);
    type_info.dim += 1;
    type_info.p->push_back(item);
}

// period -> digits .. digits  ���������� ��ά����Ϊ1������Χ���桿
void generate_26(const ATRNode & node, TYPE_info & type_info)
{
    int start_index = stoi(node.children[0].attr);
    int end_index = stoi(node.children[2].attr);
    T_item item("", start_index, end_index, 0, nullptr);
    type_info.dim = 1;
    type_info.p->push_back(item);
}

/*
 * subprogram_declarations -> subprogram_declarations
 *                            subprogram  ;
 */
void generate_27(const ATRNode & node)
{
    if(node.children[0].children.empty())
    {
        generate_28(node.children[0]);
    }
    else{
        generate_27(node.children[0]);
    }
    generate_29(node.children[1]);
}

// subprogram_declarations ->
void generate_28(const ATRNode & node)
{}

// subprogram -> subprogram_head   ;  subprogram_body ���˳��ӱ�
void generate_29(const ATRNode & node)
{
    if(node.children[0].children.size()==3)
    {
        generate_30(node.children[0]);
    }
    else
    {
        generate_31(node.children[0]);
    }
    generate_40(node.children[2]);
    // �˳��ӱ�
    curTable = (*curTable)[0].p;
}

// subprogram_head -> procedure  id �������ӱ���дid�� formal_parameter
void generate_30(const ATRNode & node)
{
    ATRNode id = node.children[1];
    vector<T_item> prod_table;
    T_item item(id.attr, PROCEDURE, 0, 0, &prod_table);
    insert_symbol_table(item);
    T_item item1(id.attr, NONE, 0, 0, curTable);
    curTable = item.p;
    insert_symbol_table(item1);
    int param_count;
    if(node.children[2].children.empty())
    {
        param_count = generate_33(node.children[2]);
    }
    else
    {
        param_count = generate_32(node.children[2]);
    }
    vector<T_item> * temp = (*curTable)[0].p;
    (*temp)[(*temp).size() - 1].dimension = param_count;
}

// subprogram_head -> function  id  �������ӱ���дid��formal_parameter  :  basic_type
void generate_31(const ATRNode & node)
{
    ATRNode id = node.children[1];
    vector<T_item> prod_table;
    T_item item(id.attr, FUNCTION, 0, 0, &prod_table);
    insert_symbol_table(item);
    TYPE_info type_info = generate_21(node.children[4]);
    T_item item1(id.attr, type_info.type, 0, 0, curTable);
    curTable = item.p;
    insert_symbol_table(item1);
    int param_count;
    if(node.children[2].children.empty())
    {
        param_count = generate_33(node.children[2]);
    }
    else
    {
        param_count = generate_32(node.children[2]);
    }
    vector<T_item> * temp = (*curTable)[0].p;
    (*temp)[(*temp).size() - 1].dimension = param_count;
}

// formal_parameter -> (  parameter_list  )
int generate_32(const ATRNode & node)
{
    int param_count;
    if(node.children[1].children.size()==1)
    {
        param_count = generate_35(node.children[1]);
    }
    else
    {
        param_count = generate_34(node.children[1]);
    }
    return param_count;
}

// formal_parameter ->   ����������Ϊ0����������]
int generate_33(const ATRNode & node)
{
    return 0;
}

// parameter_list -> parameter_list  ;  parameter  ��ά��+1��
int generate_34(const ATRNode & node)
{
    int param_count;
    if(node.children[0].children.size()==1)
    {
        param_count = generate_35(node.children[0]);
    }
    else
    {
        param_count = generate_34(node.children[0]);
    }
    param_count += generate_36(node.children[2]);
    return param_count;
}

// parameter_list -> parameter  ��ά����Ϊ1��
int generate_35(const ATRNode & node)
{
    return generate_36(node.children[0]);
}

// parameter -> var_parameter  |  value_parameter
int generate_36(const ATRNode & node)
{
    int param_count;
    if(node.children[0].children.size()==2)
    {
        param_count = generate_38(node.children[0]);
    }
    else
    {
        param_count = generate_39(node.children[0]);
    }
    return param_count;
}

// var_parameter -> var  value_parameter
int generate_38(const ATRNode & node)
{
    return generate_39(node.children[1]);
}

// value_parameter -> idlist  :  basic_type  �����ʹ��ݡ������ã����ʹ��ݡ�
int generate_39(const ATRNode & node)
{
    TYPE_info type_info = generate_21(node.children[2]);
    int param_count;
    if(node.children[0].children.size()==1)
    {
        param_count = generate_6(node.children[0], type_info);
    } else{
        param_count = generate_5(node.children[0], type_info);
    }
    return param_count;
}

/*
 * subprogram_body ->   const_declarations
 *                      var_declarations
 *                      compound_statement
 */
void generate_40(const ATRNode & node)
{
    if(node.children[0].children.empty())
    {
        generate_8(node.children[0]);
    }
    else{
        generate_7(node.children[0]);
    }
    if(node.children[1].children.empty())
    {
        generate_16(node.children[1]);
    }
    else{
        generate_15(node.children[1]);
    }
    generate_41(node.children[2]);
}

// compound_statement -> begin statement_list  end
void generate_41(const ATRNode & node)
{
    if(node.children[1].children.size()==1)
    {
        generate_43(node.children[1]);
    }
    else
    {
        generate_42(node.children[1]);
    }
}

// statement_list -> statement_list  ;  statement
void generate_42(const ATRNode & node)
{
    if(node.children[0].children.size()==1)
    {
        generate_43(node.children[0]);
    }
    else
    {
        generate_42(node.children[0]);
    }

    ATRNode first_node = node.children[2];
    if(first_node.children.empty())
    {
        generate_52(first_node);
    }
    else if(first_node.children[0].attr=="variable")
    {
        generate_44(first_node);
    }
    else if(first_node.children[0].attr=="procedure_call")
    {
        generate_45(first_node);
    }
    else if(first_node.children[0].attr=="compound_statement")
    {
        generate_46(first_node);
    }
    else if(first_node.children[0].attr=="if")
    {
        generate_47(first_node);
    }
    else if(first_node.children[0].attr=="for")
    {
        generate_48(first_node);
    }
    else if(first_node.children[0].attr=="while")
    {
        generate_49(first_node);
    }
    else if(first_node.children[0].attr=="read")
    {
        generate_50(first_node);
    }
    else if(first_node.children[0].attr=="write")
    {
        generate_51(first_node);
    }
}

// statement_list -> statement
void generate_43(const ATRNode & node)
{
    ATRNode first_node = node.children[0];
    if(first_node.children.empty())
    {
        generate_52(first_node);
    }
    else if(first_node.children[0].attr=="variable")
    {
        generate_44(first_node);
    }
    else if(first_node.children[0].attr=="procedure_call")
    {
        generate_45(first_node);
    }
    else if(first_node.children[0].attr=="compound_statement")
    {
        generate_46(first_node);
    }
    else if(first_node.children[0].attr=="if")
    {
        generate_47(first_node);
    }
    else if(first_node.children[0].attr=="for")
    {
        generate_48(first_node);
    }
    else if(first_node.children[0].attr=="while")
    {
        generate_49(first_node);
    }
    else if(first_node.children[0].attr=="read")
    {
        generate_50(first_node);
    }
    else if(first_node.children[0].attr=="write")
    {
        generate_51(first_node);
    }
}

// statement -> variable  assignop  expression  �����ͼ�顿
void generate_44(const ATRNode & node)
{
    int type1 = generate_55(node.children[0]);
    int type2;
    if(node.children[2].children.size()==1)
    {
        type2 = generate_65(node.children[2]).type;
    }
    else{
        type2 = generate_64(node.children[2]).type;
    }
    if(type1 != type2)
    {
        cout << "��ֵ������Ͳ�ƥ��" << endl;
    }
}

// statement -> procedure_call
void generate_45(const ATRNode & node)
{
    if(node.children[0].children.size() == 1)
    {
        generate_58(node.children[0]);
    }
    else
    {
        generate_59(node.children[0]);
    }
}

// statement -> �������ӱ�compound_statement ���˳��ӱ�
void generate_46(const ATRNode & node)
{
    vector<T_item> block_table;
    T_item item("_", NONE, 0, 0, &block_table);
    insert_symbol_table(item);
    T_item item1("_", NONE, 0, 0, curTable);
    curTable = item.p;
    insert_symbol_table(item1);
    generate_41(node.children[0]);
    curTable = (*curTable)[0].p;
}

// statement -> if  expression  then statement  else_part
void generate_47(const ATRNode & node)
{
    int type;
    if(node.children[1].children.size()==1)
    {
        type = generate_65(node.children[1]).type;
    }
    else
    {
        type = generate_64(node.children[1]).type;
    }
    if(type != BOOLEAN)
    {
        cout << "if�������bool���ͱ��ʽ" << endl;
    }
    else
    {
        ATRNode first_node = node.children[3];
        if(first_node.children.empty())
        {
            generate_52(first_node);
        }
        else if(first_node.children[0].attr=="variable")
        {
            generate_44(first_node);
        }
        else if(first_node.children[0].attr=="procedure_call")
        {
            generate_45(first_node);
        }
        else if(first_node.children[0].attr=="compound_statement")
        {
            generate_46(first_node);
        }
        else if(first_node.children[0].attr=="if")
        {
            generate_47(first_node);
        }
        else if(first_node.children[0].attr=="for")
        {
            generate_48(first_node);
        }
        else if(first_node.children[0].attr=="while")
        {
            generate_49(first_node);
        }
        else if(first_node.children[0].attr=="read")
        {
            generate_50(first_node);
        }
        else if(first_node.children[0].attr=="write")
        {
            generate_51(first_node);
        }
        if(!node.children[4].children.empty())
        {
            ATRNode second_node = node.children[4].children[1];
            if(second_node.children.empty())
            {
                generate_52(second_node);
            }
            else if(second_node.children[0].attr=="variable")
            {
                generate_44(second_node);
            }
            else if(second_node.children[0].attr=="procedure_call")
            {
                generate_45(second_node);
            }
            else if(second_node.children[0].attr=="compound_statement")
            {
                generate_46(second_node);
            }
            else if(second_node.children[0].attr=="if")
            {
                generate_47(second_node);
            }
            else if(second_node.children[0].attr=="for")
            {
                generate_48(second_node);
            }
            else if(second_node.children[0].attr=="while")
            {
                generate_49(second_node);
            }
            else if(second_node.children[0].attr=="read")
            {
                generate_50(second_node);
            }
            else if(second_node.children[0].attr=="write")
            {
                generate_51(second_node);
            }
        }
    }
}

// statement -> for  id���������ű�  assignop  expression �����ͼ�顿  to  expression �����ͼ�顿  do  statement
void generate_48(const ATRNode & node)
{
    ATRNode id = node.children[1];
    T_item item1 = search_table(id.attr, false);
    if(item1.name == "false")
    {
        cout << "δ��������ã�" << id.attr << endl;
    }
    else
    {
        T_item item2("", NONE, 0, 0, nullptr);
        if(node.children[3].children.size()==1)
        {
            item2 = generate_65(node.children[3]);
        }
        else
        {
            item2 = generate_64(node.children[3]);
        }
        T_item item3("", NONE, 0, 0, nullptr);
        if(node.children[5].children.size()==1)
        {
            item3 = generate_65(node.children[5]);
        }
        else
        {
            item3 = generate_64(node.children[5]);
        }
        if(item1.type != item2.type or item1.type != item3.type)
        {
            cout << item1.name << "ѭ��������ֵ���ʹ���"<< endl;
        }
        else
        {
            ATRNode first_node = node.children[7];
            if(first_node.children.empty())
            {
                generate_52(first_node);
            }
            else if(first_node.children[0].attr=="variable")
            {
                generate_44(first_node);
            }
            else if(first_node.children[0].attr=="procedure_call")
            {
                generate_45(first_node);
            }
            else if(first_node.children[0].attr=="compound_statement")
            {
                generate_46(first_node);
            }
            else if(first_node.children[0].attr=="if")
            {
                generate_47(first_node);
            }
            else if(first_node.children[0].attr=="for")
            {
                generate_48(first_node);
            }
            else if(first_node.children[0].attr=="while")
            {
                generate_49(first_node);
            }
            else if(first_node.children[0].attr=="read")
            {
                generate_50(first_node);
            }
            else if(first_node.children[0].attr=="write")
            {
                generate_51(first_node);
            }
        }
    }
}

// statement -> while expression do statement
void generate_49(const ATRNode & node)
{
    T_item item("", NONE, 0, 0, nullptr);
    if(node.children[1].children.size()==1)
    {
        item = generate_65(node.children[1]);
    }
    else
    {
        item = generate_64(node.children[1]);
    }
    if(item.type != BOOLEAN)
    {
        cout << "while�������Ϊbool����" << endl;
    }
    else
    {
        ATRNode first_node = node.children[3];
        if(first_node.children.empty())
        {
            generate_52(first_node);
        }
        else if(first_node.children[0].attr=="variable")
        {
            generate_44(first_node);
        }
        else if(first_node.children[0].attr=="procedure_call")
        {
            generate_45(first_node);
        }
        else if(first_node.children[0].attr=="compound_statement")
        {
            generate_46(first_node);
        }
        else if(first_node.children[0].attr=="if")
        {
            generate_47(first_node);
        }
        else if(first_node.children[0].attr=="for")
        {
            generate_48(first_node);
        }
        else if(first_node.children[0].attr=="while")
        {
            generate_49(first_node);
        }
        else if(first_node.children[0].attr=="read")
        {
            generate_50(first_node);
        }
        else if(first_node.children[0].attr=="write")
        {
            generate_51(first_node);
        }
    }
}

// statement -> read ( variable_list  )
void generate_50(const ATRNode & node)
{
    if(node.children[2].children.size()==1)
    {
        generate_54(node.children[2]);
    }
    else
    {
        generate_53(node.children[2]);
    }
}

// statement -> write ( expression_list )
void generate_51(const ATRNode & node)
{
    if(node.children[2].children.size()==1)
    {
        generate_63(node.children[2]);
    }
    else
    {
        generate_62(node.children[2]);
    }
}

//
void generate_52(const ATRNode & node)
{}

// variable_list -> variable_list , variable
void generate_53(const ATRNode & node)
{
    if(node.children[0].children.size() == 1)
    {
        generate_54(node.children[0]);
    }
    else
    {
        generate_53(node.children[0]);
    }
    generate_55(node.children[2]);
}

// variable_list -> variable
void generate_54(const ATRNode & node)
{
    generate_55(node.children[0]);
}

// variable -> id���������ű� id_varpart ���������㣬����ƥ�䡿
int generate_55(const ATRNode & node)
{
    ATRNode id = node.children[0];
    T_item item = search_table(id.attr, false);
    if(item.name == "false")
    {
        cout << "δ��������ã�" << id.attr << endl;
    }
    else{
        if(node.children[1].children.empty())
        {
            if(item.dimension!=0)
            {
                cout << "�������ά��Ϊ0" << endl;
            }
        }
        else if(item.dimension==0)
        {
            cout << item.name << "��������, ��������" << endl;
        }
        else
        {
            vector<T_item> param_list = generate_56(node.children[1]);
            vector<T_item> index_list = *(item.p);
            if(param_list.size() != index_list.size())
            {
                cout << item.name << "���������Ŀ��ƥ�䣡" << endl;
            }
            else
            {
                for(auto & i : param_list)
                {
                    if(i.type != INTEGER)
                    {
                        cout << item.name << "���ڷ���������" << endl;
                    }
                    // ���鷶Χ���
                }
            }
        }
    }
    return item.type;
}

// id_varpart -> [ expression_list ]
vector<T_item> generate_56(const ATRNode & node)
{

    if(node.children[1].children.size()==1)
    {
        vector<T_item> item;
        item.push_back(generate_63(node.children[1]));
        return item;
    }
    else
    {
        return generate_62(node.children[1]);
    }
}

// procedure_call -> id ���������ű�
void generate_58(const ATRNode & node)
{
    ATRNode id = node.children[0];
    T_item item = search_table(id.attr, false);
    if(item.name == "false")
    {
        cout << "δ��������ã�" << id.attr << endl;
    }
    else if(item.type != PROCEDURE)
    {
        cout << "�ǹ������ͣ����ɵ��ã�" << id.attr << endl;
    }
}

// procedure_call -> id ���������ű�( expression_list�����ã�����ƥ�䡿 )
void generate_59(const ATRNode & node)
{
    ATRNode id = node.children[0];
    T_item item = search_table(id.attr, false);
    if(item.name == "false")
    {
        cout << "δ��������ã�" << id.attr << endl;
    }
    else if(item.type != PROCEDURE)
    {
        cout << "�ǹ������ͣ����ɵ��ã�" << id.attr << endl;
    }
    else
    {
        vector<T_item> param_table = *(item.p);
        vector<T_item> param_list;
        if(node.children[2].children.size() == 1)
        {
            param_list.push_back(generate_63(node.children[2]));
        }
        else
        {
            param_list = generate_62(node.children[2]);
        }
        if(param_list.size() != item.dimension)
        {
            cout << item.name << "����������Ŀ��ƥ�䣡" << endl;
        }
        else{
            for(int i=0; i<item.dimension; i++)
            {
                if(param_list[i].type != param_table[i+1].type)
                {
                    cout << item.name << "�������ʹ���λ��" << i+1 << endl;
                }
            }
        }
    }
}

// expression_list -> expression_list  ,  expression  ������ƥ�䡿�����ã�����ƥ�䡿
vector<T_item> generate_62(const ATRNode & node)
{
    vector<T_item> item;
    if(node.children[0].children.size()==1)
    {
        item.push_back(generate_63(node.children[0]));
    }
    else
    {
        item = generate_62(node.children[0]);
    }
    if(node.children[2].children.size()==1)
    {
        item.push_back(generate_65(node.children[2]));
    }
    else
    {
        item.push_back(generate_64(node.children[2]));
    }
    return item;
}

// expression_list -> expression  ������ƥ�䡿
T_item generate_63(const ATRNode & node)
{
    if(node.children[0].children.size()==1)
    {
        return generate_65(node.children[0]);
    }
    else
    {
        return generate_64(node.children[0]);
    }
}

// expression -> simple_expression  relop  simple_expression �����ͼ�顿���������ʹ��ݡ�
T_item generate_64(const ATRNode & node)
{
    T_item item1("", NONE, 0, 0, nullptr);
    T_item item2("", NONE, 0, 0, nullptr);
    if(node.children[0].children.size()==1)
    {
        item1 = generate_67(node.children[0]);
    }
    else
    {
        item1 = generate_66(node.children[0]);
    }
    if(node.children[2].children.size()==1)
    {
        item2 = generate_67(node.children[2]);
    }
    else
    {
        item2 = generate_66(node.children[2]);
    }
    if(item1.type == item2.type and (item1.type == INTEGER or item1.type == REAL))
    {
        T_item item("", BOOLEAN, 0, 0, nullptr);
        return item;
    }
    else
    {
        cout << "��ϵ���������Ͳ�ƥ��!" << endl;
        T_item item("", NONE, 0, 0, nullptr);
        return item;
    }
}

// expression -> simple_expression  �����ʹ��ݡ�
T_item generate_65(const ATRNode & node)
{
    if(node.children[0].children.size()==1)
    {
        return generate_67(node.children[0]);
    }
    else
    {
        return generate_66(node.children[0]);
    }
}

// simple_expression -> simple_expression  addop term  �����ͼ�顿�����ʹ��ݡ�
T_item generate_66(const ATRNode & node)
{
    T_item item1("", NONE, 0, 0, nullptr);
    T_item item2("", NONE, 0, 0, nullptr);
    if(node.children[0].children.size()==1)
    {
        item1 = generate_67(node.children[0]);
    }
    else
    {
        item1 = generate_66(node.children[0]);
    }
    if(node.children[2].children.size()==1)
    {
        item2 = generate_69(node.children[2]);
    }
    else
    {
        item2 = generate_68(node.children[2]);
    }
    if(item1.type == item2.type and (item1.type == INTEGER or item1.type == REAL))
    {
        T_item item("", item1.type, 0, 0, nullptr);
        return item;
    }
    else
    {
        cout << "��ϵ���������Ͳ�ƥ��!" << endl;
        T_item item("", NONE, 0, 0, nullptr);
        return item;
    }
}

// simple_expression -> term  �����ʹ��ݡ�
T_item generate_67(const ATRNode & node)
{
    if(node.children[0].children.size()==1)
    {
        return generate_69(node.children[0]);
    }
    else
    {
        return generate_68(node.children[0]);
    }
}

// term -> term  mulop  factor  �����ͼ�顿�����ʹ��ݡ�
T_item generate_68(const ATRNode & node)
{
    int type1, type2, type;
    if(node.children[0].children.size()==1)
    {
        type1 = generate_69(node.children[0]).type;
    }
    else
    {
        type1 = generate_68(node.children[0]).type;
    }
    ATRNode factor = node.children[2];
    if(factor.children[0].attr == "num")
    {
        type2 = generate_70(factor).type;
    }
    else if(factor.children[0].attr == "variable")
    {
        type2 = generate_55(factor.children[0]);
    }
    else if(factor.children[0].id == IDENTIFIER)
    {
        type2 = generate_72(factor);
    }
    else if(factor.children[0].id == NOT)
    {
        type2 = generate_74(factor);
    }
    else if(factor.children[0].id == UMINUS)
    {
        type2 = generate_75(factor);
    }
    else
    {
        type2 = generate_73(factor);
    }
    if(type1 == type2 and (type1 == REAL or type1 == INTEGER))
    {
        type = type1;
    }
    else
    {
        cout << "mulop������������Ͳ�ƥ��" << endl;
        type = NONE;
    }
    T_item item("", type, 0, 0, nullptr);
    return item;
}

// term -> factor  �����ʹ��ݡ�
T_item generate_69(const ATRNode & node)
{
    ATRNode factor = node.children[0];
    if(factor.children[0].attr == "num")
    {
        return generate_70(factor);
    }
    else if(factor.children[0].attr == "variable")
    {
        int type = generate_55(factor.children[0]);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
    else if(factor.children[0].id == IDENTIFIER)
    {
        int type = generate_72(factor);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
    else if(factor.children[0].id == NOT)
    {
        int type = generate_74(factor);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
    else if(factor.children[0].id == UMINUS)
    {
        int type = generate_75(factor);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
    else
    {
        int type = generate_73(factor);
        T_item item("", type, 0, 0, nullptr);
        return item;
    }
}

// factor -> num  (����)  �����ʹ��ݡ�
T_item generate_70(const ATRNode & node)
{
    ATRNode first_node = node.children[0];
    if(first_node.children[0].id==DIGSEQ)
    {
        T_item item("", INTEGER, 0, 0, nullptr);
        return item;
    }
    else
    {
        T_item item("", REAL, 0, 0, nullptr);
        return item;
    }
}

// factor -> id  ���������ű�( expression_list �����ã�����ƥ�䡿 )�����ʹ��ݡ�
int generate_72(const ATRNode & node)
{
    ATRNode id = node.children[0];
    T_item item = search_table(id.attr, false);
    if(item.name == "false")
    {
        cout << "δ��������ã�" << id.attr << endl;
    }
    else if(item.type != FUNCTION)
    {
        cout << "�Ǻ������ͣ����ɵ��ã�" << id.attr << endl;
    }
    else
    {
        vector<T_item> param_table = *(item.p);
        vector<T_item> param_list;
        if(node.children[2].children.size() == 1)
        {
            param_list.push_back(generate_63(node.children[2]));
        }
        else
        {
            param_list = generate_62(node.children[2]);
        }
        if(param_list.size() != item.dimension)
        {
            cout << item.name << "����������Ŀ��ƥ�䣡" << endl;
        }
        else{
            for(int i=0; i<item.dimension; i++)
            {
                if(param_list[i].type != param_table[i+1].type)
                {
                    cout << item.name << "�������ʹ���λ��" << i+1 << endl;
                }
            }
        }
        return param_table[0].type;
    }
    return NONE;
}

// factor -> ( expression �����ʹ��ݡ�)
int generate_73(const ATRNode & node)
{
    if(node.children[1].children.size()==1)
    {
        return generate_65(node.children[1]).type;
    }
    else
    {
        return generate_64(node.children[1]).type;
    }
}

// factor -> not  factor  �����ʹ��ݡ�
int generate_74(const ATRNode & node)
{
    int type;
    ATRNode factor = node.children[1];
    if(factor.children[0].attr == "num")
    {
        type = generate_70(factor).type;
    }
    else if(factor.children[0].attr == "variable")
    {
        type = generate_55(factor.children[0]);
    }
    else if(factor.children[0].id == IDENTIFIER)
    {
        type = generate_72(factor);
    }
    else if(factor.children[0].id == NOT)
    {
        type = generate_74(factor);
    }
    else if(factor.children[0].id == UMINUS)
    {
        type = generate_75(factor);
    }
    else
    {
        type = generate_73(factor);
    }
    return type;
}

// factor -> uminus  factor  �����ʹ��ݡ�
int generate_75(const ATRNode & node)
{
    int type;
    ATRNode factor = node.children[1];
    if(factor.children[0].attr == "num")
    {
        type = generate_70(factor).type;
    }
    else if(factor.children[0].attr == "variable")
    {
        type = generate_55(factor.children[0]);
    }
    else if(factor.children[0].id == IDENTIFIER)
    {
        type = generate_72(factor);
    }
    else if(factor.children[0].id == NOT)
    {
        type = generate_74(factor);
    }
    else if(factor.children[0].id == UMINUS)
    {
        type = generate_75(factor);
    }
    else
    {
        type = generate_73(factor);
    }
    return type;
}

// ������
void Senmantic(const ATRNode & node)
{
    generate_1(node);
}

int main()
{
    ATRNode root = sampleCreate();
    postorder_traversal(root);
    cout << endl;
    Senmantic(root);
    print_stable();
    return 0;
}
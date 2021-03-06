#pragma once

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// AnalyzeProgram
//C++的关键字
const CString keyword[] = {
		L"include",L"using",L"namespace",L"std",L"main",L"endl",L"iostream",
		L"char",L"double",L"enum",L"float",L"int",L"long",L"short",L"signed",L"struct",L"union",
		L"unsigned",L"void",
		L"for",L"do",L"while",L"break",L"continue",
		L"if",L"else",L"goto",
		L"switch",L"case",L"default",
		L"return",
		L"auto",L"extern",L"register",L"static",
		L"const",L"sizeof",L"typedof",L"volatile",
		L"bool",L"true",L"false",
		L"class",L"public",L"private",L"protected",L"friend",L"mutable",L"explicit",L"this",L"virtual",
		L"new",L"delete",L"try",L"catch",L"throw"
};

//枚举类型，用于输出词法分析结果的标识
enum TYPE { KEYW, ID, NUM, STR, OPER, NOTE, SPEC };

class AnalyzeProgram : public CWnd
{
	DECLARE_DYNAMIC(AnalyzeProgram)

public:
	AnalyzeProgram(CString path);  //构造函数，打开待分析的文件
	//判断是否为数字
	bool isDigit(char ch);

	//判断是否为字母
	bool isLetter(char ch);

	//判断是否为关键字
	bool isKeyWord(CString s);

	void print(CString s, TYPE type);

	//分析主过程
	void analyse();
	//获取分析结果
	CString getResult();
	
	virtual ~AnalyzeProgram();

protected:
	DECLARE_MESSAGE_MAP()
	
	string buf;		//缓冲区
	int num;   //缓冲区长度
	CString result;  //存储分析结果
	
};



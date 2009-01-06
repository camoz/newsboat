

#if !defined(COCO_PARSER_H__)
#define COCO_PARSER_H__

#include "FilterParser.h"


#include "Scanner.h"



class Errors {
public:
	int count;			// number of errors detected

	Errors();
	void SynErr(int n);
	void Error();
	void Warning();
	void Exception();

}; // Errors

class Parser {
private:
	int _EOF;
	int _openblock;
	int _closeblock;
	int _ident;
	int _stringliteral;
	int _numliteral;
	int maxT;

	Token *dummyToken;
	int errDist;
	int minErrDist;

	void SynErr(int n);
	void Get();
	void Expect(int n);
	bool StartOf(int s);
	void ExpectWeak(int n, int follow);
	bool WeakSeparator(int n, int syFol, int repFol);

public:
	Scanner *scanner;
	Errors  *errors;

	Token *t;			// last recognized token
	Token *la;			// lookahead token

FilterParser * gen;



	Parser(Scanner *scanner);
	~Parser();
	void SemErr(wchar_t* msg);

	void stringlit(char* &lit);
	void matchattrib(char* &name);
	void matchop(int &op);
	void logop(int &lop);
	void matchexpr();
	void blockexpr();
	void expr();
	void Filter();

	void Parse();

}; // end Parser



#endif // !defined(COCO_PARSER_H__)

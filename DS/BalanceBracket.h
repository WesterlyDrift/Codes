#include<iostream>
#include<fstream>
#include"seqStack.h"
class balance
{
    private:
        std::ifstream fin;//file stream to be checked
        int currentLine;//number of line in process
        int Errors;//errors already found out

        struct Symbol
        {
            char Token;
            int TheLine;
        };
        enum CommentType
        {
            SlashSlash,
            SlashStar
        };
        //Tool functions used in CheckBalance
        bool CheckMatch(char Symb1,char Symb2,int Line1,int Line2);
        char GetNextSymbol();
        void PutBackChar(char ch);
        void SkipComment (CommentType type);
        void SkipQuote(char type);
        char NextChar();

    public:
        balance(const char* s);
        int CheckBalance();

};

class NoFile{};

balance::balance(const char* s)
{
    fin.open(s);
    if(!fin) throw NoFile();

    currentLine=1;
    Errors=0;
}

int balance::CheckBalance()
{
    struct Symbol node;
    seqStack<Symbol> st;
    char LastChar,Match;//Last char is the read-in symbol,
    //Match is the stack top symbol
    while(LastChar=GetNextSymbol())
    {
        switch(LastChar)
        {
            case '(':
            case '[':
            case '{':
                node.Token=LastChar;
                node.TheLine=currentLine;
                st.push(node);
                break;
            case ')':
            case ']':
            case '}':
                if(st.isEmpty())
                {
                    Errors++;
                    std::cout<<"There is a redundant char "<<LastChar<<
                    " in line "<<currentLine<<'.'<<std::endl;

                }
                else 
                {
                    node=st.pop();
                    Match=node.Token;
                    if(!CheckMatch(Match,LastChar,node.TheLine,currentLine))
                    ++Errors;
                }
                break;

        }
        while(!st.isEmpty())
        {//in-stack opening brackets dont meet closing brackets
            Errors++;
            node=st.pop();
            std::cout<<"In line "<<node.TheLine<<" the "<<node.Token<<"doesn't match\n";
        }
    }
    return Errors;
}

bool balance::CheckMatch(char Symb1,char Symb2,int Line1,int Line2)
{
    if(Symb1=='('&&Symb2!=')'||Symb1=='['&&Symb2!=']'
    ||Symb1=='{'&&Symb2!='}')
    {
        std::cout<<"There is an unmatch between "<<Symb2<<" in line "<<Line2
        <<" and "<<Symb1<<" in line "<<Line1<<std::endl;
        return false;
    }
    else return true;
}

char balance::GetNextSymbol()
{
    char ch;
    while(ch=NextChar())
    {
        if(ch=='/')
        {
            ch=NextChar();
            if(ch=='*') SkipComment(SlashStar);
            else if(ch=='/') SkipComment(SlashSlash);
            else PutBackChar(ch);
        }
        else if (ch=='\''||ch=='"') SkipQuote(ch);
        else if (ch=='{'||ch=='['||ch=='('||ch==')'||ch==']'||ch=='}')
        return ch;
    }
    return NULL; //file ends
}

char balance::NextChar()
{
    char ch;
    if((ch=fin.get())==EOF) return NULL;
    if(ch=='\n') currentLine++;
    return ch;
}

void balance::PutBackChar(char ch)
{
    fin.putback(ch);
    if(ch=='\n') currentLine--;
}

void balance::SkipQuote(char type)
{
    char ch;
    while((ch=NextChar()))
    {
        if(ch==type) return;
        else if(ch=='\n')
        {
            Errors++;
            std::cout<<"Missing closing quote at line "<<currentLine<<std::endl;
            return;
        }
        else if(ch=='\\') ch=NextChar();//skip ESC
    }
}

void balance::SkipComment(CommentType type)
{
    char ch,flag;

    if(type==SlashSlash)
    {
        while((ch=NextChar())&&(ch!='\n'));
        return ;
    }

    flag=' ';
    while((ch=NextChar())!=NULL)
    {
        if(flag=='*'&&ch=='/') return;
        flag=ch;
    }
    Errors++;
    std::cout<<"Comment is not terminated!\n";
}

/* example of using this class balance

#include<iostream>
using namespace std;

#include"balance.h"

int main(int argc,const char** argv)
{
    char filename[80];
    balance* p;
    int result;

    try
    {
        if(argc==1)
        {
            cout<<"please input the filename:"
            cin>>filename;
            p=new balance(filename);
            result=p->CheckBalance();
            delete p;
            cout<<result<<" errors in total.\n";
            return 0;
        }
        while (--argc)
        {
            cout<<"Check file "<<* ++argv<<endl;
            p=new balance(*argv);
            result=p->CheckBalance();
            delete p;
            cout<<result<<" errors in total.\n";
        }

    }
    catch(NoFile){ cout<<"No such file.\n";}
    return 0;
}

*/ 
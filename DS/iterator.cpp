#include<iostream>
#include<string>
#include<vector>

using namespace std;
int main()
{
    vector<string> text;
    string word;
    while(getline(cin,word))
    {
        text.push_back(word);//read input circularly
    }

    //suffix increment
    cout<<"suffix increment"<<endl;
    for(vector<string>::size_type ix=0;ix!=text.size();++ix)
        cout<<text[ix]<<endl;
    //iterator
    cout<<"Output by iterator"<<endl;
    for(vector<string>::iterator it=text.begin();it!=text.end();++it)
        cout<<*it<<endl;
    //int result = unique Morse Representations(text);

    //Reduced increment
    cout<<"Reduced increment"<<endl;
    for(const string& words:text)
        cout<<words<<endl;

    getchar();
    return 0;
}
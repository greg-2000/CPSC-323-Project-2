// Author: Gregory Martinez
// Email: greg_2000@csu.fullerton.edu
// Date: 2022-12-04
// Files: Prog1.cpp, r.sh

#include<iostream>
#include<string>
#include<deque>
using namespace std;
int n,n1,n2;
int getPosition(string arr[], string q, int size)
{
    for(int i=0;i<size;i++)
    {
        if(q == arr[i])
            return i;
    }
    return -1;
}
int main()
{
    //For the sake of time, the production rules in the given project are coded in instead of asking to focus on parsing table.
    string prods[10],first[10],follow[10],nonterms[10],terms[10];
    string pp_table[20][20] = {};
    // //Enter producation rules after left recursion elimination into prods[]
    prods[0] = "E->TQ";
    prods[1] = "Q->+TQ";
    prods[2] = "Q->-TQ";
    prods[3] = "Q->#";
    prods[4] = "T->FR";
    prods[5] = "R->*FR";
    prods[6] = "R->/FR";
    prods[7] = "R->#";
    prods[8] = "F->(E)";
    prods[9] = "F->a";
    n = 10;

    //Enter the first of each production
    first[0] = "(a";
    first[1] = "+";
    first[2] = "-";
    first[3] = "#";
    first[4] = "(a";
    first[5] = "*";
    first[6] = "/";
    first[7] = "#";
    first[8] = "(";
    first[9] = "a";

    //Enter Terminal (small letters)
    terms[0] = "a";
    terms[1] = "+";
    terms[2] = "-";
    terms[3] = "*";
    terms[4] = "/";
    terms[5] = "(";
    terms[6] = ")";
    terms[7] = "$";
    n2 = 8;

    //Enter Non-Terminals(Big Letters)
    nonterms[0] = "E";
    nonterms[1] = "Q";
    nonterms[2] = "T";
    nonterms[3] = "R";
    nonterms[4] = "F";

    //Follow of Non-Terms
    follow[0] = "$)";
    follow[1] = "$)";
    follow[2] = "+-)$";
    follow[3] = "+-)$";
    follow[4] = "+-*/)$";
    n1 = 5;

    //Can uncomment but following chunk of code is to ask user for
    //Production Rules, Terminals, NonTerminals, Follows and Firsts
    //To set Rules and create Predictive Parsing Table
    // cout<<"Enter the number of productions : ";
    // cin>>n;
    // cin.ignore();
    // cout<<"Enter the productions"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     //add production rule into prods[]
    //     getline(cin,prods[i]);
    //     //correlate first of each production into first[]
    //     cout<<"Enter first for "<<prods[i].substr(3)<<" : ";
    //     getline(cin,first[i]);
    // }
    // //Enter Terminals (small letters)
    // cout<<"Enter the number of Terminals : ";
    // cin>>n2;
    // cin.ignore();
    // cout<<"Enter the Terminals"<<endl;
    // for(int i=0;i<n2;i++)
    // {
    //     //adds terminals into term[]
    //     cin>>terms[i];
    // }
    // //lists last terminal as $
    // terms[n2] = "$";
    // n2++;
    // //Enter Non-Terminals
    // cout<<"Enter the number of Non-Terminals : ";
    // cin>>n1;
    // cin.ignore();
    // for(int i=0;i<n1;i++)
    // {
    //     //Enters Non-Terminals into nonterms[] 
    //     cout<<"Enter Non-Terminal : ";
    //     getline(cin,nonterms[i]);
    //     //Correlates the follow of nonterms into follow[]
    //     cout<<"Enter follow of "<<nonterms[i]<<" : ";
    //     getline(cin,follow[i]);
    // }


    cout<<endl;
    //Display Production Rules
    cout<<"Grammar"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<prods[i]<<endl;
    }

    
    //Matches up production rules with afters and follows if not null '#'
    //To create predictive parsing table
    for(int j=0;j<n;j++)
    {
        int row = getPosition(nonterms,prods[j].substr(0,1),n1);
        if(prods[j].at(3)!='#')
        {
            for(long unsigned int i=0;i<first[j].length();i++)
            {
                int col = getPosition(terms,first[j].substr(i,1),n2);
                pp_table[row][col] = prods[j];
            }
        }
        else
        {
            for(long unsigned int i=0;i<follow[row].length();i++)
            {
                int col = getPosition(terms,follow[row].substr(i,1),n2);
                pp_table[row][col] = prods[j];
            }
        }
    }
    //Display Predictive Parsing Table
    for(int j=0;j<n2;j++)
        //Dipslay terminals spaced out
        cout<<"\t"<<terms[j];
    cout<<endl;
    //Display Non-Terminals spaced out in column
    for(int i=0;i<n1;i++)
    {
            cout<<nonterms[i]<<"\t";
            //Display Predictive Parsing Table (Inner Matching from Before)
            for(int j=0;j<n2;j++)
            {
                cout<<pp_table[i][j]<<"\t";
            }
            cout<<endl;
    }
    //Parsing String
    char c;
    do{
    string ip;
    //Create a stack to push and pop accordingly in states
    deque<string> pp_stack;
    //Push in $ first
    pp_stack.push_front("$");
    //Push in Starting Production Rule Non-Terminal [E]
    pp_stack.push_front(prods[0].substr(0,1));
    //Enter string to be parsed as ip
    cout<<"Enter the string to be parsed : ";
    getline(cin,ip);
    //Place $ at the end of string to use for Stack Implementation
    ip.push_back('$');

    //Display of Stack Implementation Table
    cout<<"Stack\tInput\tAction"<<endl;
    while(true)
    {
        //Display Stack each turn/state
        for(long unsigned int i=0;i<pp_stack.size();i++)
            cout<<pp_stack[i];
        //Display current input state
        cout<<"\t"<<ip<<"\t";
        
        //getPosition that matches current Non-Terminal to PPT
        int row1 = getPosition(nonterms,pp_stack.front(),n1);
        
        //getPosition that matches terminal and current Input to match
        int column = getPosition(terms,ip.substr(0,1),n2);

        //If a Nonterminal and a Terminal both return false, then String cannot be parsed
        if(row1 != -1 && column != -1)
        {
            //Else match the outcome to PPT zone
            string p = pp_table[row1][column];
            //If empty the cannot be Parsed
            if(p.empty())
            {
                cout<<endl<<"String is no accepted/ In valid."<<endl;
                break;
            }
            pp_stack.pop_front();
            if(p[3] != '#')
            {
                for(int x=p.size()-1;x>2;x--)
                {
                    pp_stack.push_front(p.substr(x,1));
                }
            }
            cout<<p;
        }
        else
        {
            //If input matches stack
            if(ip.substr(0,1) == pp_stack.front())
            {
                //If $ = $ then string fully parsed
                if(pp_stack.front() == "$")
                {
                    cout<<endl<<"String is accepted/ valid."<<endl;
                    break;
                }
                cout<<"Match "<<ip[0];
                pp_stack.pop_front();
                ip = ip.substr(1);
            }
            else
            {
                //By last resort it cannot be parsed
                cout<<endl<<"String cannot be Parsed."<<endl;
                break;
            }
        }
        cout<<endl;
    }
    cout<<"Continue?(Y/N) ";
    cin>>c;
    cin.ignore();
    }while(c=='y' || c=='Y');
    return 0;
}
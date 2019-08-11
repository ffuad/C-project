#include<bits/stdc++.h>
#include<fstream>
using namespace std;
vector<pair<string,int>> lendvec;
vector<pair<string,int>> readvec;

class member_data
{
protected:
    const int cnt=0;
    string pass,last_name,address,first_name,email;
public:
    bool chk = false;
    void sign_up()
    {
        ofstream outfile;
        outfile.open("customer data.txt",ios::out | ios::app);
        cout << "Enter your first name: ";
        cin>> first_name;
        outfile<< "First name: "<<first_name<<"\n";
        cout << "\nEnter your last name: ";
        cin >> last_name;
        outfile<< "last name: "<<last_name<<"\n";
        cout << "\nEnter your email: ";
        cin >> email;
        outfile<< "email: "<<email<<"\n";
        cout << "\nEnter your password: ";
        cin >> pass;
        outfile<< "Password: "<<pass<<"\n";

        //getchar();
    }
    void sign_in()
    {
        cout << "Enter your email: ";
        cin >> email;
        cout<< "\nEnter your password: ";
        cin>>pass;
        check();
    }
    void check()
    {
        fstream fin;
        fin.open("customer data.txt",ios::in);
        string line;
        string chek1 = "email: "+email;
        string chek2 = "Password: "+pass;
        bool c1 = false,c2 = false;
        while(fin)
        {
            getline(fin,line);

            if(c1 == false and line == chek1)
            {
                c1 = true;
            }
            if(c2 == false and chek2 == line)
            {
                c2 = true;
            }
            if(c1 and c2) {
                chk = true;
                break;
            }
        }
        int choose;
        if(!chk){
            cout<<"your password or email is wrong or you haven't registered.\n please re-enter or register::\n";
            cout<< "for register press 1\nfor resubmission press 2\n";
            cin>>choose;
            if(choose == 1) sign_up();
            else sign_in();
        }
        else return;
    }
    friend istream &operator >> (istream &input,member_data &m)
    {
        int chc;
        input>>chc;
        if(chc == 2)
        {
            m.sign_up();
            //cout<<"\n\n\nCongratulations! Your registration is completed\n"<<endl;
            //sign_in();
        }
        else
        {
            m.sign_in();
        }
        return (input);
    }
};

class books
{
public:
    map<string,string> bookss;
    void Books()
    {
        //cout<<"in our library the available books are:: "<<endl;
        fstream fin;
        fin.open("book.txt",ios::in);

        string line;
        string str;

        int i;
        while(getline(fin,line),getline(fin,str))
        {
            bookss[line] = str;
        }
        cout<<"\n";
    }
    void show_books()
    {
        cout<<"All books in library are: "<<endl<<endl<<endl;
        int cnt=0;
        for (map<string,string>::iterator it=bookss.begin(); it!=bookss.end(); ++it)
        {
            cout <<++cnt<<". "<< it->first <<endl;
        }
        cout<<"\n\n\n";
    }

};
class lend: virtual  public books
{
    string line,str;
    int i;
public:
    void show();
    void Lend()
    {
        i=0;
        cout<<"available books for lending"<<endl;
        fstream fin;
        fin.open("Lend.txt",ios::in);
        while(fin)
        {
            i++;int cnt,sr=0;
            getline(fin,line);
            if(i%2==1)
            {
                str = line;
                if(str[0] == '0') break;

                //cout<<++sr<<". "<<line;
            }
            else if(i%2==0) {
                cnt++;
                int n = stoi(line);
                lendvec.push_back(make_pair(str,n));

                //cout << lendvec[cnt].first << " "<< lendvec[cnt].second << endl;
                //cout<<str<<" "<<n<<endl;
            }
        }
        cout<<"\n\n\n";
    }
};

void lend :: show()
{
    //cout<<"mango"<<endl;
    for(int i=0;i<lendvec.size();i++)
        cout<<i+1<<". "<<lendvec[i].first<<"\t\t\t:: availability: "<<lendvec[i].second<<endl;
}
void rewrite(string str)
{
    if(str == "Lend")
    {
        ofstream fout;
        fout.open("Lend.txt",ios::out);
        for(int i=0;i<lendvec.size();i++)
        {
            fout<<lendvec[i].first<<"\n";
            fout<<lendvec[i].second<<"\n";
        }
        fout<<'0';
        return;
    }
    else if(str == "Read")
    {
        ofstream fout;
        fout.open("Read.txt",ios::out);
        for(int i=0;i<readvec.size();i++)
        {
            fout<<readvec[i].first<<"\n";
            fout<<readvec[i].second<<"\n";
        }
        fout<<'0';
        return;
    }

}
class read : virtual public books
{
    string line,str;
    int i;
public:
    void Read()
    {
        i=0;
        cout<<"available books for reading"<<endl;
        fstream fin;
        fin.open("Lend.txt",ios::in);
        while(fin)
        {
            i++;int cnt;
            getline(fin,line);
            ///map e save korbo
            if(i%2==1)
            {
                str = line;
                if(str[0] == '0') break;

                cout<<"Book name: "<<line;
            }
            else if(i%2==0) {
                cnt++;
                int n = stoi(line);
                readvec.push_back(make_pair(str,n));
                // cout << vec[cnt].first << " "<< vec[cnt].second << endl;
                cout<<"\t\t:: No of available book: "<<n<<endl;
            }
        }
        cout<<"\n\n\n";
    }
    virtual void Show();

};

void read :: Show()
{
    for(int i=0;i<readvec.size();i++)
        cout<<i+1<<". "<<readvec[i].first<<"\t\t:: availability: "<<readvec[i].second<<endl;
}



class admin : virtual public read, virtual public lend
{
public:
    void Return();

    admin()
    {
        cout<<"\t\t\t******WELCOME TO LIBRARY MANAGEMENT SYSTEM******\n\n\n\n\n\n";

        cout<<"If you have account please sign in or if you haven't register please register first "<<endl;
        cout<<"Press 1 for sign in. \nPress 2 for sign up;\n\n";

        member_data m;
        cin>>m;


        Books();
        //cout<<"malango"<<endl;
        show_books();
        cout<<"What do you love to do? \nPress 1 for Lend book\nPress 2 for Read book\nPress 3 for return book\n"<<endl;
        int chc;
        cin>>chc;
        string str;
        if(chc == 1)
        {
            Lend();
            show();
            bool mylove = true;
            while(mylove){
                cout<<"\n\nWhich you want to lend? Enter the name of book:  ";
                cin>>str;
                bool chk = true;
                for(int i=0;i<lendvec.size();i++)
                {
                    //cout<<lendvec[i].first<<endl;;
                    if(str == lendvec[i].first)
                    {
                        //cout<<str<<" "<<lendvec[i].first<<endl;
                        chk = false;mylove = false;
                        lendvec[i].second--;
                        rewrite("Lend");
                        //cout<<lendvec[i].second<<endl;
                        cout<<bookss[str]<<endl<<"\n\n";
                        cout<<"\n\n you successfully lend this book :)\n\n";
                    }
                }
                if(chk)
                {
                    cout<<"You input wrong name or the book is not for lending\n\n"<<endl;
                }
            }
        }
        else if(chc ==  2)
        {
            Read();
            bool mylove = true;
            while(mylove){
                cout<<"Which you want to read? Enter the name of book:  ";
                cin>>str;
                bool chk = true;
                for(int i=0;i<readvec.size();i++)
                {
                    if(str == readvec[i].first)
                    {
                        chk = false;mylove = false;
                        readvec[i].second--;
                        rewrite("Read");
                        cout<<bookss[str]<<endl<<"\n\n";
                        break;
                    }
                }
                //if(chk) break;
                 if(chk)
                {
                    cout<<"You input wrong name"<<endl;
                }
            }
        }
        else
        {
            Return();
        }
    }
};

int main()
{
    admin a;


}

void admin :: Return()
{
    cout<<"\n\n\nWhich book do you want to return?\n";
    string str;
    bool mylove = true;
    Lend();

    while(mylove)
    {
        cin>>str;
        bool chk = true;

        for (int i=0;i<lendvec.size();i++)
        {
            cout<<lendvec[i].first<<endl;
            if(str == lendvec[i].first)
            {
                //cout<<"mango"<<endl;
                lendvec[i].second++;
                rewrite("Lend");
                chk = false;mylove=false;
                break;
            }
        }
        if(chk)
        {
            cout<<"Your input is wrong. Please re-enter the name of book:: ";
            continue;
        }

    }
    cout<<"Your book is successfully returned"<<endl;
    return;
}

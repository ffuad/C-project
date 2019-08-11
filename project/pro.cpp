#include<bits/stdc++.h>
#include<fstream>
using namespace std;

class customer_data
{
    ///data of customer and create id or sign in id
protected:
    const int cnt=0;
    //int x;
    string pass,last_name,address,first_name,email;
public:
    bool chk = false;
    virtual void sign_up()
    {
        //jekhane call korbo seikhane cnt++ baraye dekha lagbe
        ofstream outfile;
        outfile.open("customer data.txt",ios::out | ios::app);
      //  outfile<<x<<".\n";
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
        cout << "\nEnter your address: ";
        cin >> address;
        cout<<endl;
        outfile<< "Address: "<<address<<"\n\n\n";
        ///will be store in file
        getchar();
    }
    virtual void sign_in()
    {
        cout << "Enter your email: ";
        cin >> email;
        cout<< "\nEnter your password: ";
        cin>>pass;
        check();
        ///will search from file
    }
    virtual void check()
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
        }///do it until the password or email is correct;
        else return;
    }
};

class travel_place
{
protected:
    string place;
public:
    virtual void getplace()
    {
        system("cls");

        cout << "Currently you can go 3 area with our agency. those are:\n1.Dhaka\n2.Rajshahi\n3.Khulna\n";
        cout << "In which place do you want to go? Enter the name of city: ";
        cin >> place;
    }
    virtual void get_description()
    {
        if(place == "Dhaka")
        {
            cout<<"\nyour required information about Dhaka ::\n\n";
            fstream fin;
            fin.open("Dhaka.txt",ios::in);
            string line;
            while(fin)
            {
                getline(fin,line);
                cout<<line<<endl;
            }
            cout<<"\n";
        }
        else if(place == "Rajshahi")
        {
            cout<<"\nyour required information about Rajshahi ::\n\n";
            fstream fin;
            fin.open("Rajshahi.txt",ios::in);
            string line;
            while(fin)
            {
                getline(fin,line);
                cout<<line<<endl;
            }
            cout<<"\n";
        }
        else if(place == "Khulna")
        {
            cout<<"\nyour required information about Khulna ::\n\n";
            fstream fin;
            fin.open("Khulna.txt",ios::in);
            string line;
            while(fin)
            {
                getline(fin,line);
                cout<<line<<endl;
            }
            cout<<"\n";
        }
        else
        {
            int x;
            cout<<"invalid input"<<endl;
            cout<<"do you want to enter again?\n1 for Yes\n2 for No";
            cin>>x;
            if(x==1) get_description();
            else return ;
        }

    }
};

class take_benifit : virtual public customer_data,virtual public travel_place
{
protected:
    string from;

    ///if customer takes benefit from us, then the procedures are described and this based work
public:
    int s_num;
    virtual void getinfo()
    {
        cout<<"From where you want to go: ";

        cin>>from;

        system("cls");

        cout<<"\n\nFrom "<<from<<" to "<<place<<" you have 3 option to go:\n\n";
        cout<<"1. By Bus."<<endl;
        cout<<"2. By Train."<<endl;
        cout<<"3. By Plane."<<endl;
        cout<<"please press the serial number from which you want to go: ";

        cin>>s_num;
        //getchar();
    }
    virtual void gethotel()
    {
        //system("cls";
        string str;
        cout<<"What type of hotel do you want? "<<endl;

        cout<<"put your option and name of hotel: ";
        cin>>s_num;

        int num;
        cout<<"choose the serial number by which you want to stay: ";
        cin>>num;
        cout<<"your room is booked.\n";
        cout<<"your number number is "<<rand()%50<<endl;
        cout<<"Thank You\n\n";
    }
};

class travel_bus :virtual public take_benifit
{
public:
    void get_bus()
    {
        //cost taken from file and store in cost
        //time
        //availability
        system("cls");


        cout<<"You have chosen bus for transportation. :)\nyour inquiries are\n\n";

        if ((place == "Khulna" and from == "Dhaka")or(from == "Khulna" and place == "Dhaka"))
        {
            //cout<<"habijabi"<<endl;
            fstream fin;
            fin.open("DK.txt",ios::in);
            string line;
            int cnt=0;

            while(fin)
            {
                cnt++;
                getline(fin,line);

                if(cnt<=4 and cnt>=0)
                {
                    cout<<line<<endl;
                }

                else if(cnt>3)
                    break;

                else
                    continue;
            }
        }

        else if ((place == "Khulna" and from == "Rajshahi")or(from == "Khulna" and place == "Rajshahi"))
        {
            fstream fin;
            fin.open("RK.txt",ios::in);
            string line;
            int cnt=0;
            while(fin)
            {
                cnt++;
                getline(fin,line);

                if(cnt<=4 and cnt>=0)
                {
                    cout<<line<<endl;
                }

                else if(cnt>6)
                    break;

                else
                    continue;
            }
        }

        else if ((place == "Khulna" and from == "Dhaka")or(from == "Khulna" and place == "Dhaka"))
        {
            fstream fin;
            fin.open("RD.txt",ios::in);
            string line;
            int cnt=0;
            while(fin)
            {
                cnt++;
                getline(fin,line);

                if(cnt<=4 and cnt>=0)
                {
                    cout<<line<<endl;
                }

                else if(cnt>9)
                    break;

                else
                    continue;
            }
        }

    }

    virtual void buy_bticket()
    {
        int num;
        cout<<"choose the serial number by which you want to go: ";
        cin>>num;
        cout<<"your ticket is purchased.\n";
        cout<<"your ticket number is "<<rand()%50<<endl;
        cout<<"enjoy your journey\n\n";
    }
};

class travel_aeroplane :virtual public take_benifit
{
public:
     void get_aeroplane()
    {
        system("cls");


        cout<<"You have chosen plane for transportation. :)\nyour inquiries are\n\n";

        if ((place == "Khulna" and from == "Dhaka")or(from == "Khulna" and place == "Dhaka"))
            {
            fstream fin;
            fin.open("DK.txt",ios::in);
            string line;
            int cnt=0;
            while(fin)
            {
                cnt++;
                getline(fin,line);

                if(cnt<15 and cnt>9)
                {
                    cout<<line<<endl;
                }

                else if(cnt>15)
                    break;

                else
                    continue;
            }
        }

        else if ((place == "Khulna" and from == "Rajshahi")or(from == "Khulna" and place == "Rajshahi"))
            {
            fstream fin;
            fin.open("RK.txt",ios::in);
            string line;
            int cnt=0;
            while(fin)
            {
                cnt++;
                getline(fin,line);

                if(cnt<15 and cnt>9)
                {
                    cout<<line<<endl;
                }

                else if(cnt>15)
                    break;

                else
                    continue;
            }
        }

        else if ((place == "Khulna" and from == "Dhaka")or(from == "Khulna" and place == "Dhaka"))
        {
            fstream fin;
            fin.open("RD.txt",ios::in);
            string line;
            int cnt=0;
            while(fin)
            {
                cnt++;
                getline(fin,line);

                if(cnt<15 and cnt>9)
                {
                    cout<<line<<endl;
                }

                else if(cnt>15)
                    break;

                else
                    continue;
            }
        }

    }

    virtual void buy_pticket()
    {
        int num;
        cout<<"choose the serial number by which you want to go: ";
        cin>>num;
        cout<<"your ticket is purchased.\n";
        cout<<"your ticket number is "<<rand()%50<<endl;
        cout<<"enjoy your journey\n\n";
    }
};

class travel_train :virtual public take_benifit
{
public:
    void get_train()
    {
        system("cls");

        cout<<"You have chosen train for transportation. :)\nyour inquiries are\n\n\n\n";

        if ((place == "Khulna" and from == "Dhaka")or(from == "Khulna" and place == "Dhaka"))
        {
            fstream fin;
            fin.open("DK.txt",ios::in);
            string line;
            int cnt = 0;
            while(fin)
            {
                cnt++;
                getline(fin,line);

                if(cnt<10 and cnt>4)
                {
                    cout<<line<<endl;
                }

                else if(cnt>10)
                    break;

                else
                    continue;
            }
        }

        else if ((place == "Khulna" and from == "Rajshahi")or(from == "Khulna" and place == "Rajshahi"))
        {
            fstream fin;
            fin.open("RK.txt",ios::in);
            string line;
            int cnt=0;
            ///somthing line theke something line porjnto print korbo
            while(fin)
            {
                cnt++;
                getline(fin,line);

                if(cnt<10 and cnt>4 )
                {
                    cout<<line<<endl;
                }

                else if(cnt>10)
                    break;

                else
                    continue;
            }
        }

        else if ((place == "Khulna" and from == "Dhaka")or(from == "Khulna" and place == "Dhaka"))
        {
            fstream fin;
            fin.open("RD.txt",ios::in);
            string line;
            int cnt=0;
            while(fin)
            {
                cnt++;
                getline(fin,line);

                if(cnt<10 and cnt>4)
                {
                    cout<<line<<endl;
                }

                else if(cnt>10)
                    break;

                else
                    continue;
            }
        }

    }

    virtual void buy_tticket()
    {
        int num;
        cout<<"choose the serial number by which you want to go: ";
        cin>>num;
        cout<<"your ticket is purchased.\n";
        cout<<"your ticket number is "<<rand()%50<<endl;
        cout<<"enjoy your journey\n\n";
    }
};

class hotel_selection :virtual public take_benifit
{
    ///ratings for hotels and motels and also qualities
public:
    void hoteldescription()
    {
        //getchar();
        system("cls");

        cout<<"You have chosen bus for transportation. :)\nyour inquiries are\n\n";
        if ((place == "Dhaka"))
        {
            fstream fin;
            fin.open("DH.txt",ios::in);
            string line;
            while(fin)
            {
                getline(fin,line);
                cout<<line<<endl;
            }
        }

        else if ((place == "Rajshahi"))
        {
            fstream fin;
            fin.open("RH.txt",ios::in);
            string line;
            while(fin)
            {
                getline(fin,line);
                cout<<line<<endl;
            }
        }

        else if (place == "Khulna" )
        {
            fstream fin;
            fin.open("KH.txt",ios::in);
            string line;
            while(fin)
            {
                getline(fin,line);
                cout<<line<<endl;
            }
        }
        cout<<"\n\n\n";

        gethotel();
    }
};

class Final : virtual public hotel_selection,virtual public travel_aeroplane ,virtual public travel_bus,virtual public travel_train
{
public:

    Final()
    {
        cout<<"\t\t\tWelcome to the page: \n\n\n"<<endl;
        cout<<"do you have an id?\nPress 1 for Yes\nPress 2 for No\n";
        int chc;
        cin>>chc;
        //customer_data c;

        if(chc == 2)
        {
            sign_up();
        }

        else
        {
            sign_in();
        }

        getplace();
        get_description();

        while(true)
            {
            getinfo();

            if(s_num == 1)
            {
               get_bus();
               buy_bticket();
               break;
            }

            else if(s_num == 2)
            {
                get_train();
                buy_tticket();
                break;
            }

            else if(s_num == 3)
            {
                get_aeroplane();
                buy_pticket();
                break;
            }

            else
            {
                cout<<"input is invalid\n";
                Final();
            }
        }

        hoteldescription();

    }
};

///MAIN FUNCTION///

int main()
{
    //system("color 1A");
    Final F;

    //F.customer();
}

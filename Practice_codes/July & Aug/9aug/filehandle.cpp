#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    char name[30];
    char age[30];
    fstream file;
 
    file.open("aaa.txt",ios::out);
    if(!file)
    {
      cout<<"Error in creating file.."<<endl;
      return 0;
    }
    cout<<"\nFile created successfully."<<endl;
 
    //read values from kb
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"Enter age: ";
    cin>>age;
    //write into file
    file.write(name,sizeof(name));
    file.write(age,sizeof(age));

    file.close();
    cout<<"\nFile saved and closed succesfully."<<endl;
 
    //re open file in input mode and read data
    //open file
    file.open("aaa.txt",ios::in);
    if(!file){
        cout<<"Error in opening file..";
        return 0;
    }
    //cin>>name;
    file.read(name,sizeof(name)-1);
    file.read(age,sizeof(age));

    cout<<"Name: "<<name<<",Age:"<<age<<endl;
    return 0;
}
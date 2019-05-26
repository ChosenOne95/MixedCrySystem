#include <iostream>
#include <string>

using namespace std;

int main()
{
    string fileName;
    string password;
    string targetIP;
    string targetPort;
    cout<<"input the file you want to encrypt:"<<endl;
    cin>>fileName;

    string enc_cmd;
    enc_cmd = "gmssl sms4 -e -in "+fileName+" -out "+ "./send/send.sms4";
    system(enc_cmd.c_str());
    cout<<"input your psaaword for me once more:"<<endl;
    cin>>password;
    
    string pac_cmd;
    pac_cmd = "tar -cvf package.tar send";
    system(pac_cmd.c_str());

    cout<<"input the target ip you want to send:"<<endl;
    cin>>targetIP;
    cout<<"input the port of target:"<<endl;
    cin>>targetPort;
    string nc_cmd;
    nc_cmd = "nc " + targetIP + " " + targetPort+" " +"< package.tar";
    system(nc_cmd.c_str());

    return 0;
}

#include <iostream>
#include <string.h>
#include <string>

using namespace std;

int main(int num, char* arg[])
{
    string url;
    // prompt to request input from the user
    cout << "Please enter the url you want to parse" << endl;
    cin >> url;
// This is comment
    
    string acceptedProtocol[] = { "http","https","ftp","ftps" };
    int i = 0;
    // use index of substring to find the protocol from 0- until (://)
    string protocol = url.substr(0, url.find("://"));
    // Check if protocol name is present in validProtocols
    for (int i = 0; i <= sizeof(acceptedProtocol); i++)
    {
        if (protocol == acceptedProtocol[i])
        {
            cout << "protocol:   " << protocol << endl;
            break;
        }
        if (i == sizeof(acceptedProtocol))
            cout << protocol << " is not accepted Protocol" << endl;

    }

    //cout << url<< endl;
    // after protocol and 3 chars begin domain  
    string domainBegin = url.substr(url.find("://")+3 );
    // until domain begin finds (:)
    string domain = domainBegin.substr(0, domainBegin.find(":"));
    cout << "Domain: " << domain << endl;
    // after domain begin port after find(:)
    string portBegin = domain.substr(domain.find(":") + 1);
    // until it finds
    //size_t domainEnd = domain.find("/");
    string PortBegin = domainBegin.substr(domainBegin.find_first_of(":")+1);
    string portstr = PortBegin.substr(0, PortBegin.find_first_of("/"));
   
    int port = 0;
    try {
        // Block of code to try
        port = stoi(portstr);

        if (port < 1 || port > 65535)
        {
            cout << "Port number must be between 1 and 65535" << endl;
        }


        cout << "Port: " << port << endl;
        // Throw an exception when a problem arise
    }
    catch (std::invalid_argument const& ex) {
        // Block of code to handle errors
        cout << "The port is invalid.\n";
    }


    string beginPath = domainBegin.substr(domainBegin.find_first_of("/"));
   
    string filePath = beginPath.substr(0, beginPath.find("?"));
    cout << "File Path: " << filePath << endl;


    string parameters = domainBegin.substr(domainBegin.find_first_of("?")+1);
    cout << "Parameters: " << parameters << endl;
}

  

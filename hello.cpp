#include "soapH.h"  // include the generated source code headers
#include "ns.nsmap" // include XML namespaces
int main()
{
  return soap_serve(soap_new());
}
int ns__hello(struct soap *soap, std::string name, std::string& greeting)
{
  greeting = "Hello " + name;
  return SOAP_OK;
}
 
//  The server is now ready to be compiled and run. 
//  Compile the server 
//  The server can be compiled using the following command: 
//  g++ -o hello hello.cpp soapC.cpp soapServer.cpp -lgsoap++
 
//  Run the server 
//  The server can be run using the following command: 
//  ./hello
 
//  The server is now running and waiting for requests. 
//  Create a client 
//  The client is a simple program that sends a request to the server and prints the response. 
//  Create a file named  hello_client.cpp  with the following content: 
 // Path: hello_client.cpp
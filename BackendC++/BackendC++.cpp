#include<iostream>
#include<crow.h>
#include<unordered_map>

using namespace std;
using namespace crow;

struct ServerData {
	int ip;
	int requests = 0;
	int servedPages = 0;
	//initialzing server
	ServerData() {
		requests++;
		servedPages++;
	}
};

int main() {
	const int PORT = 3000;
	unordered_map<int, bool> found_ip;

	//server part
	SimpleApp app;
	

	CROW_ROUTE(app, "/")([&]() {
		ostringstream port;
		port << PORT;
		string responseMessage = "The Server is up and running on port : ";
		responseMessage += port.str();
		return responseMessage;
	});

	//adding validation part to the server 
	CROW_ROUTE(app, "/validateData/<int>/<int>")([](const request& req, response& res,int a , int b) {
		cout << "values recieved on the server are : " << a << " " << b << endl;
		ostringstream validatedData;
		validatedData << a + b;
		string resString = "The validation index is : ";
		resString += validatedData.str();
		res.write(resString);
		res.end();
	});

}
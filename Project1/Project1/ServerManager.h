#ifndef SERVERMANAGER_H
#define SERVERMANAGER_H

#include <mutex>
#include <thread>
#ifdef __linux__
#include <sys/time.h>
#endif

#include "Client.h"
#include "PracticalSocket.h"

class Client;

class ServerManager {
private :
	static ServerManager* _instance;

	TCPServerSocket servSock;
	int defaultPort = 9999;

	const int maxClients = 100;

	bool serverStatus = true;


#ifdef __linux__
	fd_set descSet;
#endif

public:
	static ServerManager* get();
	ServerManager() : servSock(defaultPort), serverStatus(false) {};
	ServerManager(int port) : servSock(port) {};
	~ServerManager();
	void acquireClient(Client & inClient);
	//Client* getLastClient();
	bool isRunning();
	void abort();
	void checkSockets();
	string getMsgFromSocket(TCPSocket & inSock);
	//void checkNewConnection();

};


#endif
